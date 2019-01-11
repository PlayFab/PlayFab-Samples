//--------------------------------------------------------------------------------------
// GameStateManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include "NetworkMessages.h"
#include "World.h"
#include "LobbyPlayer.h"
#include "PlayerState.h"

namespace ThunderRumble
{

    class PlayerState;
    class World;


    enum class GameState
    {
        Initialize,
        InMenus,
        Matchmaking,
        Countdown,
        AllocatingServer,
        ConnectingToServer,
        WaitingToStart,
        Playing
    };

    class GameStateManager : public Manager
    {
    public:
        GameStateManager();

        void Initialize();
        void Suspend();
        void Resume();
        void ShutDown();
        void Update();

        void ProcessGameNetworkMessage(std::shared_ptr<GameNetworkMessage> &message);
        void GotoMatchmaking();
        void GotoLobby();
        void GotoAllocatingServer();
        void GotoCountdownStage(int timeUntilStart);
        void ConnectToServer(const std::wstring& ipAddr, uint16_t portNum);
        void ClearPlayerScores();
        void DrawWorld(float elapsedTime);
        void UpdateWorld(float totalTime, float elapsedTime);
        std::shared_ptr<PlayerState> GetPlayerState(uint16_t peer);
        std::shared_ptr<PlayerState> GetLocalPlayerState();
        void SetPlayerState(uint16_t id, std::shared_ptr<PlayerState> state);

        inline GameState GetState() { return _state; }
        inline std::wstring& GetLocalPlayerName() { return _localPlayerName; }
        inline bool IsGameWon() { return _world->IsGameWon; }
        inline std::wstring GetWinnerName() { return _world->WinnerName; }
        inline DirectX::XMVECTORF32 GetWinningColor() { return _world->WinningColor; }
        inline int GetTimeUntilMatchStart() { return m_TimeUntilMatchStart; }

        std::vector<std::shared_ptr<PlayerState>> GetAllPlayerStates();

        // Lobby
        void SetLobbyPlayers(uint16_t localPlayerIndex, const std::vector<CLobbyPlayer>& lobbyMembers);
        const std::vector<CLobbyPlayer>& GetLobbyPlayers() const { return m_vecLobbyPlayers; }

    private:
        void ResetGameplayData();

        int m_TimeUntilMatchStart = -1;
        GameState _state;
        std::wstring _localPlayerName;
        std::map<uint16_t, std::shared_ptr<PlayerState>> _peers;
        std::unique_ptr<World> _world;

        std::vector<CLobbyPlayer> m_vecLobbyPlayers;
    };

}