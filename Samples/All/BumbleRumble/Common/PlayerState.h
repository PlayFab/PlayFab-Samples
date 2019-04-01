//--------------------------------------------------------------------------------------
// PlayerState.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Ship.h"

namespace BumbleRumble
{

struct PlayerStateData
{
    bool InGame;
    bool LobbyReady;
    byte ShipColorIndex;
    byte ShipVariation;
};

class PlayerState
{
public:
    PlayerState(const char *displayName = "");

    // Lobby functions
    void DeactivatePlayer();
    void EnterLobby();
    void ReactivatePlayer();

    void DeserializePlayerStateData(const std::vector<uint8_t> &data);
    std::vector<uint8_t> SerializePlayerStateData();

    // State properties
    std::string DisplayName;
    bool IsLocalPlayer;
    bool InGame;
    bool LobbyReady;
    std::string PeerId;

    byte ShipColor() { return m_shipColor; }
    void ShipColor(byte colorIndex)
    {
        if (colorIndex >= Ship::Colors.size())
        {
            colorIndex = 0;
        }
        m_shipColor = colorIndex;
        if (m_playerShip)
        {
            m_playerShip->Color = Ship::Colors[colorIndex];
        }
    }

    byte ShipVariation() { return m_shipVariation; }
    void ShipVariation(byte variation)
    {
        if (variation >= Ship::MaxVariations)
        {
            variation = 0;
        }
        m_shipVariation = variation;
        if (m_playerShip)
        {
            m_playerShip->SetShipTexture(variation);
        }
    }

    bool IsInactive() { return m_isInactive; }

    std::shared_ptr<Ship> GetShip() const { return m_playerShip; }

private:
    std::shared_ptr<Ship> m_playerShip;
    byte m_shipColor;
    byte m_shipVariation;
    bool m_isInactive;
};

}
