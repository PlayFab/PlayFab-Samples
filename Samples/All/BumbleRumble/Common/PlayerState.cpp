//--------------------------------------------------------------------------------------
// PlayerState.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "CollisionManager.h"
#include "PlayerState.h"
#include "Ship.h"

using namespace BumbleRumble;
using namespace DirectX;

PlayerState::PlayerState(const char *displayName) :
    m_shipColor(0),
    m_shipVariation(0),
    m_isInactive(true)
{
    m_playerShip = std::make_shared<Ship>();

    if (std::string(displayName).empty())
    {
        DisplayName = "Player";
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
        m_playerShip->Die(nullptr, true);
        m_playerShip->RespawnTimer = 0.0f;
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

    DEBUGLOG("Received player state data: InGame = %u; LobbyReady = %u; ColorIndex = %u; ColorVariation = %u\n", 
        rcvdPlayerStateData.InGame, 
        rcvdPlayerStateData.LobbyReady, 
        rcvdPlayerStateData.ShipColorIndex, 
        rcvdPlayerStateData.ShipVariation);

    InGame = rcvdPlayerStateData.InGame;
    LobbyReady = rcvdPlayerStateData.LobbyReady;
    ShipColor(rcvdPlayerStateData.ShipColorIndex);
    ShipVariation(rcvdPlayerStateData.ShipVariation);
}

std::vector<uint8_t> PlayerState::SerializePlayerStateData()
{
    PlayerStateData playerStateData = { InGame, LobbyReady, m_shipColor, m_shipVariation };

    DEBUGLOG("Serializing player state data: InGame = %u; LobbyReady = %u; ColorIndex = %u; ColorVariation = %u\n", 
        InGame, 
        LobbyReady, 
        m_shipColor, 
        m_shipVariation);

    std::vector<uint8_t> data(sizeof(PlayerStateData));
    CopyMemory(data.data(), &playerStateData, sizeof(PlayerStateData));

    return data;
}
