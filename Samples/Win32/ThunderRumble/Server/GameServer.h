#pragma once

#include "StepTimer.h"
#include "PeerToPeerNetworkManager.h"
#include "NetworkMessages.h"
#include "ServerGameStateManager.h"
#include "Compute\IPC.h"

class GameServer
{
public:
    GameServer(std::wstring& hostName, uint16_t portNumber);
    ~GameServer();

    enum class GameServerState
    {
        Initialize,
        WaitingForPlayers,
        Playing,
        GameOver,
        Failed
    };

    static const uint32_t c_ServerPeerId = 0;
	static int m_numExpectedPlayersFromLobby;

    int Run();
    void Tick();
    void Update(DX::StepTimer const& timer);

	void CheckForAllPlayersQuit();

    void Exit(const wchar_t* msg = nullptr);

    void Initialize();

private:
    void ProcessUserQueues();
    void ProcessGameMessages();

	void IPCCallback_OnAllocated(const IPCBuffer& packetData);

private:
    std::wstring _hostName;
    uint16_t _portNumber;
    DX::StepTimer _timer;
    bool _running;
    GameServerState _state;
    std::mutex _dataLock;
    std::unique_ptr<PeerMeshForSamples::PeerToPeerNetworkManager> _networkManager;
    std::vector<PeerMeshForSamples::TPeerId> _addedUsers;
    std::vector<PeerMeshForSamples::TPeerId> _removedUsers;
    std::vector<std::shared_ptr<ThunderRumble::GameNetworkMessage>> _receivedMessages;

	// Shutdown logic if no one connected
	bool m_bAllocated = false;
	DX::StepTimer m_allocationTimer;
	bool m_bIsAwaitingPlayers = true;
	const double m_TimeBeforeExitWhenNoPlayersJoined = 3000.0f;
};

