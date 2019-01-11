//--------------------------------------------------------------------------------------
// ServerGameStateManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include "NetworkMessages.h"
#include "World.h"
#include "PlayerState.h"

namespace ThunderRumble
{

enum class GameState
{
    Initialize,
    InMenus,
    ConnectingToServer,
    WaitingToStart
};

class GameStateManager : public Manager
{
public:
    GameStateManager();

    void Initialize();
    void ShutDown();
    void Update(float totalTime, float elapsedTime);

    void ProcessGameNetworkMessage(std::shared_ptr<GameNetworkMessage> &message);
    void ClearPlayerScores();
    void ClearPendingSends();
    bool CheckForReadyPlayers();

    std::vector<std::pair<uint16_t, std::vector<uint8_t>>>& GetPendingSends() { return _pendingSends; }
    std::vector<std::shared_ptr<PlayerState>> GetAllPlayerStates();

    inline GameState GetState() { return _state; }
    inline bool IsGameWon() { return _world->IsGameWon; }
    std::shared_ptr<PlayerState> GetPlayerState(uint16_t peer);
	void SetPlayerState(uint16_t id, std::shared_ptr<PlayerState> state);

    void ResetGameplayData();
    void SendShipUpdates();

private:
    GameState _state;
    std::map<uint16_t, std::shared_ptr<PlayerState>> _peers;
    std::unique_ptr<World> _world;
    std::vector<std::pair<uint16_t, std::vector<uint8_t>>> _pendingSends;
};

}

