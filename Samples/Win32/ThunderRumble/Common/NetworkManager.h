//--------------------------------------------------------------------------------------
// NetworkManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include "PeerToPeerNetworkManager.h"
#include "NetworkMessages.h"

namespace ThunderRumble
{

    class NetworkManager : public Manager
    {
    public:
        NetworkManager();
        ~NetworkManager();

        static const uint16_t c_ServerPeerId = 0;
        static const uint16_t c_ClientPortNumber = 0;

        void Initialize();
        bool CreateNetwork();
        void ConnectToServer(const std::wstring &hostAddress, uint16_t port, std::function<void(void)> connectedCallback = nullptr);
        void SendGameMessage(const GameNetworkMessage& message);
        void Shutdown();

        void DoWork(float_t delta);

        inline bool IsConnected() { return _connected; }

        inline uint16_t LocalPeerId() { return _peerId; }
        inline void SetLocalPeerId(uint16_t newLocalPeerID) { _peerId = newLocalPeerID; }

        inline uint16_t ServerPeerId() { return _ServerPeerId; }
        inline void SetServerPeerId(uint16_t newServerPeerID) { _ServerPeerId = newServerPeerID; }

    private:
        std::unique_ptr<PeerMeshForSamples::PeerToPeerNetworkManager> _network;
        std::vector<PeerMeshForSamples::TPeerId> _addedUsers;
        std::vector<PeerMeshForSamples::TPeerId> _removedUsers;
        concurrency::concurrent_queue<std::shared_ptr<ThunderRumble::GameNetworkMessage>> _receivedMessages;
        std::mutex _dataLock;
        uint16_t _peerId;
        uint16_t _ServerPeerId;
        bool _connected;
        std::function<void(void)> _onconnected;
    };

}
