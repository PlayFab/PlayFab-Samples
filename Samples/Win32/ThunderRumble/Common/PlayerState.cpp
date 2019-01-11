//--------------------------------------------------------------------------------------
// PlayerState.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "CollisionManager.h"
#include "PlayerState.h"
#include "Ship.h"

using namespace ThunderRumble;
using namespace DirectX;

PlayerState::PlayerState(const wchar_t *displayName) :
    m_shipColor(0),
    m_shipVariation(0),
    m_isInactive(true)
{
    m_playerShip = std::make_shared<Ship>();

    if (std::wstring(displayName).empty())
    {
        DisplayName = L"Player";
    }
    else
    {
        DisplayName = displayName;
    }
    IsLocalPlayer = false;
    EnterLobby();
    m_isInactive = false;
}

void PlayerState::DeactivatePlayer()
{
    m_isInactive = true;
    m_playerShip->Score = 0;
    EnterLobby();
}

void PlayerState::EnterLobby()
{
    if (InGame)
    {
        //std::lock_guard<std::mutex> lock(CollisionManager::g_lock);
        m_playerShip->Die(nullptr, true);
        m_playerShip->RespawnTimer = 0.0f;
        //CollisionManager::Collection()->ApplyPendingRemovals(); // this should be redundant since Ship::Die() does this
        //Game->World->RemoveShip(m_playerShip.get());
        InGame = false;
    }

    LobbyReady = false;
}

void PlayerState::ReactivatePlayer()
{
    m_isInactive = false;
}

void PlayerState::DeserializePlayerStateData(const std::vector<uint8_t> &data)
{
    PlayerStateData rcvdPlayerStateData = PlayerStateData();
    CopyMemory(&rcvdPlayerStateData, data.data(), sizeof(PlayerStateData));

    DEBUGLOG(L"Received player state data: InGame = %u; LobbyReady = %u; ColorIndex = %u; ColorVariation = %u\n",
        rcvdPlayerStateData.inGame,
        rcvdPlayerStateData.lobbyReady,
        rcvdPlayerStateData.shipColorIndex,
        rcvdPlayerStateData.shipVariation);

    InGame = rcvdPlayerStateData.inGame;
    LobbyReady = rcvdPlayerStateData.lobbyReady;
    ShipColor(rcvdPlayerStateData.shipColorIndex);
    ShipVariation(rcvdPlayerStateData.shipVariation);
}

std::vector<uint8_t> PlayerState::SerializePlayerStateData()
{
    PlayerStateData playerStateData = { InGame, LobbyReady, m_shipColor, m_shipVariation };

    DEBUGLOG(L"Serializing player state data: InGame = %u; LobbyReady = %u; ColorIndex = %u; ColorVariation = %u\n",
        InGame,
        LobbyReady,
        m_shipColor,
        m_shipVariation);

    std::vector<uint8_t> data(sizeof(PlayerStateData));
    CopyMemory(data.data(), &playerStateData, sizeof(PlayerStateData));

    return data;
}
