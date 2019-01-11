//--------------------------------------------------------------------------------------
// GameStateManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "GameScreen.h"
#include "WelcomeScreen.h"
#include "PlayerState.h"
#include "World.h"
#include "Managers.h"

using namespace ThunderRumble;

GameStateManager::GameStateManager() :
    _state(GameState::Initialize)
{
}

void GameStateManager::Initialize()
{
    wchar_t machineName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(machineName) / sizeof(machineName[0]);
    GetComputerNameW(machineName, &size);

    // Used for UI, not lobby name since those are de-duped
    _localPlayerName = machineName;
    _world = std::make_unique<World>();
}

std::shared_ptr<PlayerState> GameStateManager::GetPlayerState(uint16_t peer)
{
    auto itr = _peers.find(peer);
    if (itr != _peers.end())
    {
        return (*itr).second;
    }
    return nullptr;
}

std::shared_ptr<PlayerState> GameStateManager::GetLocalPlayerState()
{
    for (const auto& peer : _peers)
    {
        if (peer.second->IsLocalPlayer)
        {
            return peer.second;
        }
    }

    return nullptr;
}

void GameStateManager::SetPlayerState(uint16_t id, std::shared_ptr<PlayerState> state)
{
    auto peer = GetPlayerState(id);

    if (peer != nullptr && state == nullptr)
    {
        peer->DeactivatePlayer();
        _peers.erase(id);
    }
    else
    {
        _peers[id] = state;
    }
}

void GameStateManager::Suspend()
{
}

void GameStateManager::Resume()
{
}

void GameStateManager::ShutDown()
{
}

void GameStateManager::Update()
{
}

void GameStateManager::SetLobbyPlayers(uint16_t localPlayerIndex, const std::vector<CLobbyPlayer>& lobbyMembers)
{
    m_vecLobbyPlayers = lobbyMembers;

    Managers::Get<NetworkManager>()->SetLocalPeerId(localPlayerIndex);
    Managers::Get<NetworkManager>()->SetServerPeerId(0); // server peer ID is zero

    uint16_t lobbyIndex = 1;
    for (auto iter = m_vecLobbyPlayers.begin(); iter != m_vecLobbyPlayers.end(); iter++)
    {
        uint16_t userID = lobbyIndex++;

        auto existingPeer = GetPlayerState(userID);
        if (existingPeer != nullptr)
        {
            existingPeer->ShipColor(iter->ShipColor());
            existingPeer->ShipVariation(iter->ShipVariant());
            existingPeer->LobbyReady = iter->IsReady();
        }
        else
        {
            auto newState = std::make_shared<PlayerState>();
            newState->DisplayName = iter->GetDisplayName();
            newState->PeerId = userID;
            newState->IsLocalPlayer = (userID == localPlayerIndex);

            newState->ShipColor(iter->ShipColor());
            newState->ShipVariation(iter->ShipVariant());
            newState->LobbyReady = iter->IsReady();

            SetPlayerState(userID, newState);
        }

    }
}

void GameStateManager::ProcessGameNetworkMessage(std::shared_ptr<GameNetworkMessage> &message)
{
    auto localPeerId = Managers::Get<NetworkManager>()->LocalPeerId();

    switch (message->MessageType())
    {
    case GameMessageType::GameOver:
        if (_world->IsInitialized())
        {
            DEBUGLOG(L"Received a GameOver message\n");

            auto localPlayer = GetPlayerState(localPeerId);
            if (localPlayer->InGame)
            {
                _world->IsGameWon = true;
                _world->SetGameInProgress(false);
                _world->DeserializeGameOver(message->RawData());
            }
            else
            {
                ResetGameplayData();
            }

        }
        break;

    case GameMessageType::GameSettings:
        DEBUGLOG(L"Received a GameSettings message\n");
        _world->DeserializeGameSettings(message->RawData());
        break;

    case GameMessageType::GameStart:
    {
        DEBUGLOG(L"Received a GameStart message\n");

        auto localPlayer = GetPlayerState(localPeerId);
        if (!localPlayer->InGame)
        {
            _world->SetGameInProgress(true);

            if (localPlayer->LobbyReady)
            {
                _state = GameState::Playing;
            }
        }
        break;
    }
    case GameMessageType::PlayerInfo:
    {
        auto itr = _peers.find(message->Peer());
        if (itr == _peers.end() && message->Peer() != localPeerId)
        {
            auto playerState = std::make_shared<PlayerState>(message->StringValue().c_str());
            playerState->IsLocalPlayer = false;
            playerState->ShipColor(0);
            playerState->ShipVariation(0);
            playerState->PeerId = message->Peer();

            _peers[message->Peer()] = playerState;

            DEBUGLOG(L"Received PlayerInfo for: %ws\n", playerState->DisplayName.c_str());
        }
        else
        {
            DEBUGLOG(L"Received PlayerInfo for known peer %u\n", message->Peer());
        }
        break;
    }
    case GameMessageType::PlayerState:
    {
        DEBUGLOG(L"Received a PlayerState message from %u\n", message->Peer());
        auto playerState = GetPlayerState(message->Peer());
        if (playerState != nullptr && message->Peer() != localPeerId)
        {
            playerState->DeserializePlayerStateData(message->RawData());
        }
        else
        {
            DEBUGLOG(L"No PlayerState exists for peer %u!\n", message->Peer());
        }
        break;
    }
    case GameMessageType::PowerUpSpawn:
        DEBUGLOG(L"Received a PowerUpSpawn message\n");
        if (_world->IsInitialized())
        {
            _world->DeserializePowerUpSpawn(message->RawData());
        }
        else
        {
            DEBUGLOG(L"...World not initialized!\n");
        }
        break;

    case GameMessageType::ShipData:
        if (_world->IsInitialized())
        {
            auto peerState = GetPlayerState(message->Peer());
            if (peerState != nullptr)
            {
                peerState->GetShip()->Deserialize(message->RawData());
            }
        }
        else
        {
            DEBUGLOG(L"Received a ShipData message\n");
            DEBUGLOG(L"...World not initialized!\n");
        }
        break;

    case GameMessageType::ShipDeath:
        DEBUGLOG(L"Received a ShipDeath message from %u\n", message->Peer());
        if (_world->IsInitialized())
        {
            auto peerState = GetPlayerState(message->Peer());
            if (peerState != nullptr)
            {
                _world->DeserializeShipDeath(message->Peer(), message->RawData());
            }
            else
            {
                DEBUGLOG(L"PlayerState not found for %u\n", message->Peer());
            }
        }
        else
        {
            DEBUGLOG(L"...World not initialized!\n");
        }
        break;

    case GameMessageType::ShipInput:
        if (_world->IsInitialized())
        {
            auto peerState = GetPlayerState(message->Peer());
            if (peerState != nullptr)
            {
                peerState->GetShip()->Input.Deserialize(message->RawData());
            }
        }
        else
        {
            DEBUGLOG(L"...World not initialized!\n");
        }
        break;

    case GameMessageType::ShipSpawn:
        DEBUGLOG(L"Received a ShipSpawn message\n");
        if (_world->IsInitialized())
        {
            _world->DeserializeShipSpawn(message->RawData());
        }
        else
        {
            DEBUGLOG(L"...World not initialized!\n");
        }
        break;

    case GameMessageType::WorldData:
        if (_world->IsInitialized())
        {
            _world->DeserializeWorldData(message->RawData());
        }
        else
        {
            DEBUGLOG(L"...World not initialized!\n");
        }
        break;

    case GameMessageType::WorldSetup:
        DEBUGLOG(L"Received a WorldSetup message\n");
        if (!_world->IsInitialized())
        {
            _world->DeserializeWorldSetup(message->RawData());
        }
        else
        {
            DEBUGLOG(L"...World is already initialized!\n");
        }
        break;
    }
}

void ThunderRumble::GameStateManager::GotoMatchmaking()
{
    Managers::Get<GameServiceManager>()->BeginMatchmaking();
    _state = GameState::Matchmaking;
}

void ThunderRumble::GameStateManager::GotoLobby()
{
    m_TimeUntilMatchStart = -1;
    _state = GameState::WaitingToStart;
}

void ThunderRumble::GameStateManager::GotoAllocatingServer()
{
    m_TimeUntilMatchStart = -1;
    _state = GameState::AllocatingServer;
}

void ThunderRumble::GameStateManager::GotoCountdownStage(int timeUntilStart)
{
    m_TimeUntilMatchStart = timeUntilStart;
    _state = GameState::Countdown;
}

void ThunderRumble::GameStateManager::ConnectToServer(const std::wstring& ipAddr, uint16_t portNum)
{
    _state = GameState::ConnectingToServer;

    if (Managers::Get<NetworkManager>()->CreateNetwork())
    {
        Managers::Get<NetworkManager>()->ConnectToServer(
            ipAddr,
            portNum,
            [this]()
        {
        }
        );
    }
    else
    {
        Managers::Get<ScreenManager>()->ShowError(
            L"Unable to create network",
            [this]()
        {
            _state = GameState::InMenus;

            Managers::Get<ScreenManager>()->ExitAllScreens();
            Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<WelcomeScreen>());
        }
        );
    }
}

void GameStateManager::ClearPlayerScores()
{
    for (auto& pair : _peers)
    {
        pair.second->GetShip()->Score = 0;
    }
}

void GameStateManager::DrawWorld(float elapsedTime)
{
    if (_world->IsInitialized())
    {
        _world->Draw(elapsedTime);
    }
}

void ThunderRumble::GameStateManager::UpdateWorld(float totalTime, float elapsedTime)
{
    if (_world->IsInitialized())
    {
        _world->Update(totalTime, elapsedTime);
    }
}

std::vector<std::shared_ptr<PlayerState>> GameStateManager::GetAllPlayerStates()
{
    std::vector<std::shared_ptr<PlayerState>> players;

    for (auto& item : _peers)
    {
        players.push_back(item.second);
    }

    return players;
}

void ThunderRumble::GameStateManager::ResetGameplayData()
{
    // Reset any existing game world to its defaults
    if (_world != nullptr)
    {
        _world->ResetDefaults();
        _world->SetGameInProgress(false);
    }
}

