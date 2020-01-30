//--------------------------------------------------------------------------------------
// GameStateManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Game.h"
#include "GameScreen.h"
#include "WelcomeScreen.h"
#include "StarfieldScreen.h"
#include "DebugOverlayScreen.h"
#include "PlayerState.h"
#include "World.h"
#include "Managers.h"

using namespace BumbleRumble;

namespace
{
    std::string NewGuid()
    {
        GUID id = {};
        char buf[64] = {};

        CoCreateGuid(&id);

        sprintf_s(buf, "%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX",
            id.Data1, id.Data2, id.Data3,
            id.Data4[0], id.Data4[1], id.Data4[2], id.Data4[3],
            id.Data4[4], id.Data4[5], id.Data4[6], id.Data4[7]);

        return std::string(buf);
    }
}

GameStateManager::GameStateManager() :
    m_state(GameState::Initialize),
    m_godMode(false),
    m_gettingHost(false)
{
}

void GameStateManager::Initialize()
{
    DEBUGLOG("GameStateManager::Initialize()\n");

    m_world = std::make_unique<World>();
}

void GameStateManager::SetLocalPlayerName(std::string name)
{
    m_localPlayerName = name;
}

void GameStateManager::SetLocalPeerId(std::string peerId)
{
    auto localPlayer = std::make_shared<PlayerState>(m_localPlayerName.c_str());
    localPlayer->IsLocalPlayer = true;
    localPlayer->ShipColor(0);
    localPlayer->ShipVariation(0);
    localPlayer->PeerId = peerId;

    m_peers[localPlayer->PeerId] = localPlayer;
}
std::shared_ptr<PlayerState> GameStateManager::GetPlayerState(std::string& peer)
{
    auto itr = m_peers.find(peer);
    if (itr != m_peers.end())
    {
        return (*itr).second;
    }
    return nullptr;
}

void GameStateManager::DeactivatePlayer(std::string& peer)
{
    auto player = GetPlayerState(peer);

    if (player != nullptr)
    {
        player->DeactivatePlayer();
    }
}

void GameStateManager::Suspend()
{
}

void GameStateManager::Resume()
{
}

void GameStateManager::Shutdown()
{
    DEBUGLOG("GameStateManager::Shutdown()\n");
    m_world = nullptr;
    m_peers.clear();
    m_localPlayerName.clear();
    m_state = GameState::Initialize;
}

void GameStateManager::Update()
{
    if (m_state == GameState::Matchmaking)
    {
        auto playfab = Managers::Get<PlayFabManager>();

        if (playfab->MatchStatus() == MatchmakingStatus::MatchingComplete)
        {
            if (playfab->IsGameHost())
            {
                GotoAllocatingServer();
            }
            else
            {
                GotoWaitingForServer();
            }
        }
        else if (playfab->MatchStatus() == MatchmakingStatus::MatchingFailed)
        {
            ResetGame(playfab->MatchError());
        }
    }
    else if (m_state == GameState::WaitingForServer)
    {
        if (m_gettingHost)
        {
            return;
        }

        m_timer.Tick([this]()
        {
            m_gettingHost = true;

            Managers::Get<PlayFabManager>()->GetHostNetwork([this](std::string invite, std::string network)
            {
                if (!network.empty())
                {
                    DEBUGLOG("Connecting to Host's network (%hs)\n", network.c_str());

                    GotoConnectingToServer();

                    Managers::Get<NetworkManager>()->ConnectToNetwork(
                        invite.c_str(),
                        network.c_str(),
                        [this]()
                        {
                            GotoWaitingToStart();
                        }
                        );
                }
                else
                {
                    m_gettingHost = false;
                }
            });
        });
    }
}

void GameStateManager::ProcessGameNetworkMessage(std::string& sender, std::shared_ptr<GameNetworkMessage> &message)
{
    auto localPeerId = Managers::Get<PlayFabManager>()->EntityId();

    switch (message->MessageType())
    {
        case GameMessageType::GameOver:
            if (m_world->IsInitialized())
            {
                DEBUGLOG("Received a GameOver message\n");

                auto localPlayer = GetPlayerState(localPeerId);
                if (localPlayer->InGame)
                {
                    m_world->IsGameWon = true;
                    m_world->SetGameInProgress(false);
                    m_world->DeserializeGameOver(message->RawData());
                }
                else
                {
                    ResetGameplayData();
                }

                m_state = GameState::GameOver;
            }
            break;

        case GameMessageType::GameSettings:
            DEBUGLOG("Received a GameSettings message\n");
            m_world->DeserializeGameSettings(message->RawData());
            break;

        case GameMessageType::GameStart:
        {
            DEBUGLOG("Received a GameStart message\n");

            auto localPlayer = GetPlayerState(localPeerId);
            if (!localPlayer->InGame)
            {
                m_world->SetGameInProgress(true);

                if (localPlayer->LobbyReady)
                {
                    m_state = GameState::Playing;
                }
            }
            break;
        }
        case GameMessageType::PlayerInfo:
        {
            auto itr = m_peers.find(sender);
            if (itr == m_peers.end() && sender != localPeerId)
            {
                auto playerState = std::make_shared<PlayerState>(message->StringValue().c_str());
                playerState->IsLocalPlayer = false;
                playerState->ShipColor(0);
                playerState->ShipVariation(0);
                playerState->PeerId = sender;

                m_peers[sender] = playerState;

                DEBUGLOG("Received PlayerInfo for: %hs\n", playerState->DisplayName.c_str());
            }
            else
            {
                DEBUGLOG("Received PlayerInfo from known peer %hs\n", sender.c_str());
            }
            break;
        }
        case GameMessageType::PlayerState:
        {
            DEBUGLOG("Received a PlayerState message from %hs\n", sender.c_str());
            auto playerState = GetPlayerState(sender);
            if (playerState != nullptr && sender != localPeerId)
            {
                playerState->DeserializePlayerStateData(message->RawData());
            }
            else
            {
                DEBUGLOG("No PlayerState exists for peer %hs!\n", sender.c_str());
            }
            break;
        }
        case GameMessageType::PowerUpSpawn:
            DEBUGLOG("Received a PowerUpSpawn message\n");
            if (m_world->IsInitialized())
            {
                m_world->DeserializePowerUpSpawn(message->RawData());
            }
            else
            {
                DEBUGLOG("...World not initialized!\n");
            }
            break;

        case GameMessageType::ShipData:
            if (m_world->IsInitialized())
            {
                auto peerState = GetPlayerState(sender);
                if (peerState != nullptr)
                {
                    peerState->GetShip()->Deserialize(message->RawData());
                }
            }
            else
            {
                DEBUGLOG("Received a ShipData message\n");
                DEBUGLOG("...World not initialized!\n");
            }
            break;

        case GameMessageType::ShipDeath:
            DEBUGLOG("Received a ShipDeath message from %hs\n", sender.c_str());
            if (m_world->IsInitialized())
            {
                auto peerState = GetPlayerState(sender);
                if (peerState != nullptr)
                {
                    m_world->DeserializeShipDeath(sender, message->RawData());
                }
                else
                {
                    DEBUGLOG("PlayerState not found for %hs\n", sender.c_str());
                }
            }
            else
            {
                DEBUGLOG("...World not initialized!\n");
            }
            break;

        case GameMessageType::ShipInput:
            if (m_world->IsInitialized())
            {
                auto peerState = GetPlayerState(sender);
                if (peerState != nullptr)
                {
                    peerState->GetShip()->Input.Deserialize(message->RawData());
                }
            }
            else
            {
                DEBUGLOG("...World not initialized!\n");
            }
            break;

        case GameMessageType::ShipSpawn:
            DEBUGLOG("Received a ShipSpawn message\n");
            if (m_world->IsInitialized())
            {
                m_world->DeserializeShipSpawn(message->RawData());
            }
            else
            {
                DEBUGLOG("...World not initialized!\n");
            }
            break;

        case GameMessageType::WorldData:
            if (m_world->IsInitialized())
            {
                m_world->DeserializeWorldData(message->RawData());
            }
            else
            {
                DEBUGLOG("...World not initialized!\n");
            }
            break;

        case GameMessageType::WorldSetup:
            DEBUGLOG("Received a WorldSetup message\n");
            if (!m_world->IsInitialized())
            {
                m_world->DeserializeWorldSetup(message->RawData());
            }
            else
            {
                DEBUGLOG("...World is already initialized!\n");
            }
            break;
    }
}

void GameStateManager::GotoMatchmaking()
{
    DEBUGLOG("GameStateManager::GotoMatchmaking()\n");
    Managers::Get<PlayFabManager>()->BeginMultiplayer("nr_simple", 120);
    m_state = GameState::Matchmaking;
}

void GameStateManager::GotoConnectingToServer()
{
    DEBUGLOG("GameStateManager::GotoConnectingToServer()\n");
    m_state = GameState::ConnectingToServer;
}

void GameStateManager::GotoAllocatingServer()
{
    DEBUGLOG("GameStateManager::GotoAllocatingServer()\n");
    m_TimeUntilMatchStart = -1;
    m_state = GameState::AllocatingServer;

    auto inviteId = NewGuid();

    Managers::Get<NetworkManager>()->CreateAndConnectToNetwork(
        inviteId.c_str(),
        [this, inviteId](std::string descriptor)
        {
            DEBUGLOG("Network Created, send Descriptor to lobby service\n");
            Managers::Get<PlayFabManager>()->WriteHostNetwork(inviteId, descriptor);
            GotoWaitingToStart();
        }
        );
}

void GameStateManager::GotoWaitingForServer()
{
    DEBUGLOG("GameStateManager::GotoWaitingForServer()\n");
    m_TimeUntilMatchStart = -1;
    m_state = GameState::WaitingForServer;

    m_timer.SetTargetElapsedSeconds(1.0f);
    m_timer.SetFixedTimeStep(true);
    m_timer.ResetElapsedTime();
}

void GameStateManager::GotoWaitingToStart()
{
    DEBUGLOG("GameStateManager::GotoWaitingToStart()\n");
    m_state = GameState::WaitingToStart;
}

void GameStateManager::GotoPlaying()
{
    DEBUGLOG("GameStateManager::GotoPlaying()\n");

    m_state = GameState::Playing;

    m_world->GenerateWorld();
    m_world->SetGameInProgress(true);

    Managers::Get<NetworkManager>()->SendGameMessage(
        GameNetworkMessage(
            GameMessageType::GameStart,
            0
            )
        );

    std::map<std::string, std::shared_ptr<Ship>> ships;

    for (auto item : m_peers)
    {
        if (item.second && !item.second->IsInactive())
        {
            ships[item.first] = item.second->GetShip();
        }
    }

    Managers::Get<NetworkManager>()->SendGameMessage(
        GameNetworkMessage(
            GameMessageType::WorldSetup,
            m_world->SerializeWorldSetup(ships)
            )
        );

    Managers::Get<PlayFabManager>()->ClearHostNetwork();
}

void GameStateManager::ResetGame(std::string error)
{
    DEBUGLOG("GameStateManager::ResetGame(%hs)\n", error.c_str());

    m_state = GameState::Resetting;
    m_gettingHost = false;

    auto andthen = []()
    {
        Managers::Get<NetworkManager>()->LeaveNetwork([]()
        {
            Managers::Get<GameStateManager>()->Shutdown();

            Managers::Get<ScreenManager>()->ExitAllScreens();
            Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<WelcomeScreen>());
            Managers::Get<ScreenManager>()->AddBackgroundScreen(std::make_shared<StarfieldScreen>());
            Managers::Get<ScreenManager>()->AddForegroundScreen(std::make_shared<DebugOverlayScreen>());
            Managers::Get<ScreenManager>()->SetBackgroundsVisible(true);

            Managers::Get<GameStateManager>()->Initialize();
        });
    };

    if (error.empty())
    {
        andthen();
    }
    else
    {
        Managers::Get<ScreenManager>()->ShowError(error, andthen);
    }
}

void GameStateManager::ClearPlayerScores()
{
    for (auto& pair : m_peers)
    {
        pair.second->GetShip()->Score = 0;
    }
}

void GameStateManager::DrawWorld(float elapsedTime)
{
    if (m_world->IsInitialized())
    {
        m_world->Draw(elapsedTime);
    }
}

void GameStateManager::UpdateWorld(float totalTime, float elapsedTime)
{
    if (m_world->IsInitialized())
    {
        m_world->Update(totalTime, elapsedTime);
    }
}

std::vector<std::shared_ptr<PlayerState>> GameStateManager::GetAllPlayerStates()
{
    std::vector<std::shared_ptr<PlayerState>> players;

    for (auto& item : m_peers)
    {
        players.push_back(item.second);
    }

    return players;
}

void GameStateManager::ResetGameplayData()
{
    // Reset any existing game world to its defaults
    if (m_world != nullptr)
    {
        m_world->ResetDefaults();
        m_world->SetGameInProgress(false);
    }
}

