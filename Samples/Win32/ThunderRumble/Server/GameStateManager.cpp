//--------------------------------------------------------------------------------------
// GameStateManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayerState.h"
#include "World.h"
#include "Managers.h"
#include "GameServer.h"

using namespace ThunderRumble;

int GameServer::m_numExpectedPlayersFromLobby = 0;

GameStateManager::GameStateManager() :
    _state(GameState::Initialize)
{
}

void GameStateManager::Initialize()
{
    _world = std::make_unique<World>();
}

void GameStateManager::ShutDown()
{
}

void GameStateManager::Update(float totalTime, float elapsedTime)
{
    if (_world && _world->IsInitialized())
    {
        _world->Update(totalTime, elapsedTime);
    }
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

bool GameStateManager::CheckForReadyPlayers()
{
    bool ready = true;

    if (_peers.size() == 0 || GameServer::m_numExpectedPlayersFromLobby == 0)
    {
        ready = false;
        return ready;
    }
    else
    {
        for (auto item : _peers)
        {
            if (!item.second || !item.second->LobbyReady)
            {
                ready = false;
                break;
            }
        }
    }

    std::wcout << L"Expected players is " << GameServer::m_numExpectedPlayersFromLobby << L". We currently have " << _peers.size() << std::endl;
    ready = (_peers.size() == GameServer::GameServer::m_numExpectedPlayersFromLobby);
    if (ready)
    {
        std::wcout << L"We are ready!" << std::endl;
        _world->GenerateWorld();
        _world->SetGameInProgress(true);

        std::map<uint16_t, std::shared_ptr<Ship>> ships;

        for (auto item : _peers)
        {
            if (item.second && !item.second->IsInactive())
            {
                ships[item.first] = item.second->GetShip();
            }
        }

        auto message = GameNetworkMessage(GameMessageType::WorldSetup, GameServer::c_ServerPeerId, _world->SerializeWorldSetup(ships));
        auto payload = message.Serialize();

        _pendingSends.push_back(std::make_pair(GameServer::c_ServerPeerId, payload));

        message = GameNetworkMessage(GameMessageType::GameStart, GameServer::c_ServerPeerId, 0);
        payload = message.Serialize();

        _pendingSends.push_back(std::make_pair(GameServer::c_ServerPeerId, payload));
    }

    return ready;
}

void GameStateManager::ProcessGameNetworkMessage(std::shared_ptr<GameNetworkMessage> &message)
{
    switch (message->MessageType())
    {
    case GameMessageType::PlayerState:
    {
        auto player = GetPlayerState(message->Peer());
        if (player != nullptr)
        {
            std::wcout << L"Received PlayerState from " << player->DisplayName << std::endl;

            auto packet = message->RawData();

            // Deserialize info for local copy of playerstate
            player->DeserializePlayerStateData(packet);

            // then send the info to all other connected users
            for (auto& peer : _peers)
            {
                if (peer.first != message->Peer())
                {
                    auto msg = GameNetworkMessage(
                        GameMessageType::PlayerState,
                        player->PeerId,
                        player->SerializePlayerStateData()
                    );

                    _pendingSends.push_back(std::make_pair(peer.first, msg.Serialize()));

                    msg = GameNetworkMessage(
                        GameMessageType::PlayerState,
                        peer.first,
                        peer.second->SerializePlayerStateData()
                    );

                    _pendingSends.push_back(std::make_pair(player->PeerId, msg.Serialize()));
                }
            }
        }
        break;
    }
    case GameMessageType::PlayerInfo:
    {
        std::wcout << L"Received PlayerInfo from peer " << message->Peer() << std::endl;

        auto player = GetPlayerState(message->Peer());
        if (player != nullptr)
        {
            player->DisplayName = message->StringValue();
            std::wcout << "Peer " << message->Peer() << " is " << player->DisplayName << std::endl;

            Managers::Get<IPC>()->AddPlayer(player->PeerId, player->DisplayName);

            for (auto& peer : _peers)
            {
                if (peer.first != message->Peer())
                {
                    std::wcout << "Sending PlayerInfo (T) (" << std::to_wstring(player->PeerId) << ", " << player->DisplayName << ") to " << std::to_wstring(peer.first) << std::endl;
                    auto msg = GameNetworkMessage(
                        GameMessageType::PlayerInfo,
                        player->PeerId,
                        player->DisplayName
                    );

                    _pendingSends.push_back(std::make_pair(peer.first, msg.Serialize()));

                    if (peer.second->DisplayName != L"Player")
                    {
                        std::wcout << "Sending PlayerInfo (B) (" << std::to_wstring(peer.first) << ", " << peer.second->DisplayName << ") to " << std::to_wstring(player->PeerId) << std::endl;
                        msg = GameNetworkMessage(
                            GameMessageType::PlayerInfo,
                            peer.first,
                            peer.second->DisplayName
                        );

                        _pendingSends.push_back(std::make_pair(player->PeerId, msg.Serialize()));
                    }
                }
            }
        }
        break;
    }
    case GameMessageType::ShipInput:
    {
        auto player = GetPlayerState(message->Peer());
        if (player != nullptr)
        {
            player->GetShip()->Input.Deserialize(message->RawData());

            for (const auto& player : _peers)
            {
                if (player.first != message->Peer())
                {
                    _pendingSends.push_back(std::make_pair(player.first, message->Serialize()));
                }
            }
        }
        break;
    }
    default:
        std::wcout << "Unhandled GameMessageType: " << (int)message->MessageType() << std::endl;
        break;
    }
}

void GameStateManager::SetPlayerState(uint16_t id, std::shared_ptr<PlayerState> state)
{
    auto peer = GetPlayerState(id);

    if (peer != nullptr && state == nullptr)
    {
        peer->DeactivatePlayer();

        auto message = GameNetworkMessage(GameMessageType::PlayerState, id, peer->SerializePlayerStateData());
        auto payload = message.Serialize();

        for (auto& usernode : _peers)
        {
            if (usernode.first != id)
            {
                _pendingSends.push_back(std::make_pair(usernode.first, payload));
            }
        }

        _peers.erase(id);
    }
    else
    {
        _peers[id] = state;
    }
}

std::vector<std::shared_ptr<PlayerState>> GameStateManager::GetAllPlayerStates()
{
    std::vector<std::shared_ptr<PlayerState>> players;

    if (_peers.size() > 0)
    {
        for (auto& item : _peers)
        {
            players.push_back(item.second);
        }
    }

    return players;
}

void GameStateManager::ClearPlayerScores()
{
    if (_peers.size() == 0)
    {
        return;
    }

    for (auto& pair : _peers)
    {
        pair.second->GetShip()->Score = 0;
    }
}

void GameStateManager::ClearPendingSends()
{
    _pendingSends.clear();
}

void GameStateManager::ResetGameplayData()
{
    // Reset any existing game world to its defaults
    if (_world != nullptr)
    {
        _world->ResetDefaults();
        _world->SetGameInProgress(false);
    }
}

void GameStateManager::SendShipUpdates()
{
    for (auto& peer : _peers)
    {
        auto msg = GameNetworkMessage(
            GameMessageType::ShipData,
            peer.first,
            peer.second->GetShip()->Serialize()
        );

        _pendingSends.push_back(
            std::make_pair(
                GameServer::c_ServerPeerId,
                msg.Serialize()
            )
        );
    }
}
