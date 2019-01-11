#include "pch.h"
#include "PlayerState.h"
#include "GameServer.h"
#include "Managers.h"
#include "Compute/IPC.h"

using namespace ThunderRumble;
using namespace PeerMeshForSamples;

GameServer::GameServer(std::wstring& hostName, uint16_t portNumber) :
    _hostName(hostName),
    _portNumber(portNumber),
    _running(false),
    _state(GameServerState::Initialize)
{
}

GameServer::~GameServer()
{
}

void GameServer::IPCCallback_OnAllocated(const IPCBuffer& packetData)
{
    const char* szSessionCookie = packetData.ReadString();

    m_allocationTimer.ResetElapsedTime();
    m_bAllocated = true;
    m_bIsAwaitingPlayers = true;
    std::wcout << L"Server was allocated... cookie is " << szSessionCookie << std::endl;
    std::wcout << L"Waiting for players to connect" << std::endl;

    // parse json
    Json::Value responseJson = Json::Value::null;
    Json::CharReaderBuilder jsonReaderFactory;
    std::unique_ptr<Json::CharReader> jsonReader(jsonReaderFactory.newCharReader());
    JSONCPP_STRING jsonParseErrors;
    const bool parsedSuccessfully = jsonReader->parse(szSessionCookie, szSessionCookie + strlen(szSessionCookie), &responseJson, &jsonParseErrors);

    if (parsedSuccessfully)
    {
        const Json::Value jsonSessionID = responseJson["lobbyID"];
        const std::string& lobbyID = jsonSessionID.asString();

        std::wcout << L"Lobby ID is " << lobbyID.c_str() << std::endl;

        Managers::Get<GameServiceManager>()->GetLobbyInformation(lobbyID).then([=](Concurrency::task<GetLobbyInformationResponse> task)
        {
            const GetLobbyInformationResponse& resp = task.get();
            GameServer::m_numExpectedPlayersFromLobby = resp.m_numMembers;
        });
    }
    else
    {
        // TODO: error
    }
}

int GameServer::Run()
{
    // Run the game server at 30 FPS
    _timer.SetFixedTimeStep(true);
    _timer.SetTargetElapsedSeconds(1.0 / 30);

    Managers::PreInitialize();

    _running = true;

    while (_running)
    {
        Tick();
        Sleep(1);
    }

    return 0;
}

// Executes the basic game loop.
void GameServer::Tick()
{
    // Were we allocated, but no one connected and we've reached our timeout? Shutdown
    if (m_bAllocated && m_bIsAwaitingPlayers)
    {
        m_allocationTimer.Tick([&]()
        {
            if (m_allocationTimer.GetTotalSeconds() >= m_TimeBeforeExitWhenNoPlayersJoined)
            {
                Exit(L"We were allocated, but no players ever connected\n");
                return;
            }
        });
    }

    _timer.Tick([&]()
    {
        if (_running)
        {
            Update(_timer);
        }
    });

    // Update Compute IPC
    Managers::Get<IPC>()->Update();
}

void GameServer::CheckForAllPlayersQuit()
{
    auto players = Managers::Get<GameStateManager>()->GetAllPlayerStates();
    auto found = false;

    for (const auto& player : players)
    {
        if (player)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        Exit(L"All players have left the server\n");
        return;
    }
}

// Updates the world.
void GameServer::Update(DX::StepTimer const& timer)
{
    auto elapsedTime = static_cast<float>(timer.GetElapsedSeconds());
    auto totalTime = static_cast<float>(timer.GetTotalSeconds());

    if (!_running)
    {
        return;
    }

    switch (_state)
    {
    case GameServerState::Initialize:
        Initialize();
        break;

    case GameServerState::WaitingForPlayers:
        if (Managers::Get<GameStateManager>()->CheckForReadyPlayers())
        {
            std::wcout << L"All players ready, moving to Playing state" << std::endl;
            _state = GameServerState::Playing;
        }

        // If we are in waiting for players, and we did have players, check if anyone is still connected, if not exit
        if (!m_bIsAwaitingPlayers)
        {
            CheckForAllPlayersQuit();
        }
        break;

    case GameServerState::Playing:
    {
        CheckForAllPlayersQuit();

        if (Managers::Get<GameStateManager>()->IsGameWon())
        {
            Exit(L"The game is over\n");

            // Flush the network so clients get the game over message
            if (_networkManager)
            {
                _networkManager->DoWork(elapsedTime);
            }

            return;
        }
        break;
    }
    }

    if (_state == GameServerState::Failed)
    {
        return;
    }

    Managers::Get<GameStateManager>()->Update(totalTime, elapsedTime);

    if (_networkManager)
    {
        _networkManager->DoWork(elapsedTime);
    }

    ProcessUserQueues();
    ProcessGameMessages();
}

void GameServer::Exit(const wchar_t* msg)
{
    if (_networkManager)
    {
        _networkManager->SetPeerAddedHandler(nullptr);
        _networkManager->SetPeerRemovedHandler(nullptr);
        _networkManager->SetDataReceivedHandler(nullptr);
    }

    if (msg)
    {
        std::wcout << msg;
    }
    std::wcout << "Exitting Server" << std::endl;
    _running = false;
}

void GameServer::Initialize()
{
    std::wcout << L"GameServer::Initialize()" << std::endl;

    Managers::Initialize();

    // Register our packet callbacks
    Managers::Get<IPC>()->RegisterCallback(IPCPacketIdentifier_ALLOCATED, [this](const IPCBuffer& packetData) { IPCCallback_OnAllocated(packetData); });

    Managers::Get<GameStateManager>()->Initialize();

    _networkManager = std::make_unique<PeerToPeerNetworkManager>();

    _networkManager->SetPeerAddedHandler([this](TPeerId peer)
    {
        std::wcout << L"PeedAddedHandler: " << std::to_wstring(peer) << std::endl;
        std::lock_guard<std::mutex> lock(_dataLock);
        _addedUsers.push_back(peer);
    });

    _networkManager->SetPeerRemovedHandler([this](TPeerId peer, bool lastPeer)
    {
        std::lock_guard<std::mutex> lock(_dataLock);
        _removedUsers.push_back(peer);
    });

    _networkManager->SetDataReceivedHandler([this](TPeerId peer, TByteArray data, uint32_t size)
    {
        std::lock_guard<std::mutex> lock(_dataLock);
        _receivedMessages.push_back(std::make_shared<GameNetworkMessage>(std::vector<uint8_t>(data, data + size)));
    });

    try
    {
        _networkManager->CreateNetwork(
            c_ServerPeerId,
            _hostName,
            _portNumber
        );

        _state = GameServerState::WaitingForPlayers;

        std::wcout << L"GameServer waiting to be allocated" << std::endl;
    }
    catch (...)
    {
        _state = GameServerState::Failed;

        Exit(L"Failed to create network.");
    }
}

void GameServer::ProcessUserQueues()
{
    std::lock_guard<std::mutex> lock(_dataLock);

    for (const auto &userid : _addedUsers)
    {
        m_bIsAwaitingPlayers = false;
        auto newState = std::make_shared<PlayerState>();
        newState->PeerId = userid;
        newState->IsLocalPlayer = false;
        newState->LobbyReady = true; // Everyone is ready at this point, readying up was done on the previous stage before the server was allocated
        Managers::Get<GameStateManager>()->SetPlayerState(userid, newState);

        std::wcout << "User added: " << std::to_wstring(userid) << std::endl;
    }

    _addedUsers.clear();

    for (const auto &userid : _removedUsers)
    {
        Managers::Get<GameStateManager>()->SetPlayerState(userid, nullptr);

        std::wcout << "User removed: " << std::to_wstring(userid) << std::endl;

        Managers::Get<IPC>()->RemovePlayer(userid);
    }

    _removedUsers.clear();
}

void GameServer::ProcessGameMessages()
{
    std::lock_guard<std::mutex> lock(_dataLock);

    for (auto msg : _receivedMessages)
    {
        Managers::Get<GameStateManager>()->ProcessGameNetworkMessage(msg);
    }

    _receivedMessages.clear();

    auto pendingSends = Managers::Get<GameStateManager>()->GetPendingSends();
    for (auto item : pendingSends)
    {
        if (item.first == c_ServerPeerId)
        {
            _networkManager->SendDataToNetwork(
                item.second.data(),
                static_cast<uint32_t>(item.second.size())
            );
        }
        else
        {
            _networkManager->SendDataToPeer(
                item.first,
                item.second.data(),
                static_cast<uint32_t>(item.second.size())
            );
        }
    }

    Managers::Get<GameStateManager>()->ClearPendingSends();
}
