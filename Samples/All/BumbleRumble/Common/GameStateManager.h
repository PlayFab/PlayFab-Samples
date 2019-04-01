//--------------------------------------------------------------------------------------
// GameStateManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include "NetworkMessages.h"
#include "World.h"

namespace BumbleRumble
{

class PlayerState;
class World;

enum class GameState
{
    Initialize,
    InMenus,
    Matchmaking,
    AllocatingServer,
    WaitingForServer,
    ConnectingToServer,
    WaitingToStart,
    Playing,
    Resetting,
    GameOver
};

class GameStateManager : public Manager
{
public:
    GameStateManager();

    void Initialize();
    void Suspend();
    void Resume();
    void Shutdown();
    void Update();

    void ProcessGameNetworkMessage(std::string& sender, std::shared_ptr<GameNetworkMessage> &message);
    void GotoMatchmaking();
    void GotoAllocatingServer();
    void GotoWaitingForServer();
    void GotoWaitingToStart();
    void GotoConnectingToServer();
    void GotoPlaying();
    void ClearPlayerScores();
    void DrawWorld(float elapsedTime);
    void UpdateWorld(float totalTime, float elapsedTime);
    void ResetGame(std::string error);
    std::shared_ptr<PlayerState> GetPlayerState(std::string& peer);
    void SetLocalPeerId(std::string peerId);
    void DeactivatePlayer(std::string& peer);
    void SetLocalPlayerName(std::string name);

    inline GameState GetState() { return m_state; }
    inline std::string& GetLocalPlayerName() { return m_localPlayerName; }
    inline bool IsGameWon() { return m_world->IsGameWon; }
    inline std::string GetWinnerName() { return m_world->WinnerName; }
    inline DirectX::XMVECTORF32 GetWinningColor() { return m_world->WinningColor; }
    inline int GetTimeUntilMatchStart() { return m_TimeUntilMatchStart; }
    inline bool GetGodMode() { return m_godMode; }
    inline void SetGodMode(bool value) { m_godMode = value; }

    std::vector<std::shared_ptr<PlayerState>> GetAllPlayerStates();

private:
    void ResetGameplayData();

    bool m_godMode;
    bool m_gettingHost;
    int m_TimeUntilMatchStart = -1;
    GameState m_state;
    std::string m_localPlayerName;
    std::map<std::string, std::shared_ptr<PlayerState>> m_peers;
    std::unique_ptr<World> m_world;
    DX::StepTimer m_timer;
};

}

