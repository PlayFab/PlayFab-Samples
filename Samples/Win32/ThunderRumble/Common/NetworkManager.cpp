//--------------------------------------------------------------------------------------
// NetworkManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Managers.h"
#include "Game.h"

using namespace ThunderRumble;
using namespace PeerMeshForSamples;

NetworkManager::NetworkManager() :
    _connected(false),
    _peerId(0),
    _ServerPeerId(0)
{
    DEBUGLOG(L"Generated PeerID: %u\n", _peerId);
}

NetworkManager::~NetworkManager()
{
}

void NetworkManager::Initialize()
{
    _network = std::make_unique<PeerToPeerNetworkManager>();

    _network->SetPeerAddedHandler([this](TPeerId peer)
    {
        std::lock_guard<std::mutex> lock(_dataLock);
        DEBUGLOG(L"NetworkManager: PeerAdded: %u\n", peer);
        _addedUsers.push_back(peer);
    });

    _network->SetPeerRemovedHandler([this](TPeerId peer, bool)
    {
        std::lock_guard<std::mutex> lock(_dataLock);
        DEBUGLOG(L"NetworkManager: PeerRemoved: %u\n", peer);
        _removedUsers.push_back(peer);
    });

    _network->SetDataReceivedHandler([this](TPeerId, TByteArray data, uint32_t size)
    {
        std::lock_guard<std::mutex> lock(_dataLock);
        _receivedMessages.push(
            std::make_shared<GameNetworkMessage>(
                std::vector<unsigned char>(data, data + size)
                )
        );
    });
}

void NetworkManager::Shutdown()
{
    _connected = false;

    _network->DestroyNetwork();
    _network = nullptr;
}

bool NetworkManager::CreateNetwork()
{
    try
    {
        _network->CreateNetwork(
            _peerId,               // pseudo-random client id
            L"",                   // bind ip addr associated with the hostname
            c_ClientPortNumber     // local endpoint port number
        );
    }
    catch (...)
    {
        return false;
    }

    return true;
}

void NetworkManager::ConnectToServer(const std::wstring & hostAddress, uint16_t port, std::function<void(void)> connectedCallback)
{
    if (!_network)
    {
        return;
    }

    _onconnected = connectedCallback;
    _network->AddPeerToNetwork(
        c_ServerPeerId,
        hostAddress,
        port
    );
}

void NetworkManager::SendGameMessage(const GameNetworkMessage & message)
{
    if (!_network)
    {
        return;
    }

    auto packet = message.Serialize();

    _network->SendDataToPeer(
        c_ServerPeerId,
        packet.data(),
        static_cast<uint32_t>(packet.size())
    );
}

void NetworkManager::DoWork(float_t delta)
{
    if (_network)
    {
        _network->DoWork(delta);
    }

    // Process our queues
    {
        std::lock_guard<std::mutex> lock(_dataLock);

        for (auto peerid : _addedUsers)
        {
            if (peerid == c_ServerPeerId)
            {
                DEBUGLOG(L"NetworkManager: Server peer added\n");

                _connected = true;

                if (_onconnected)
                {
                    _onconnected();
                }
            }
            else if (peerid == _peerId)
            {
                DEBUGLOG(L"NetworkManager: Our own peer added\n");
            }
            else
            {
                DEBUGLOG(L"NetworkManager: Unknown peer added: %d\n", peerid);
            }
        }

        _addedUsers.clear();

        for (auto peerid : _removedUsers)
        {
            if (peerid == c_ServerPeerId)
            {
                DEBUGLOG(L"NetworkManager: Server peer removed\n");

                _connected = false;
            }
            else if (peerid == _peerId)
            {
                DEBUGLOG(L"NetworkManager: Our own peer removed\n");

                _connected = false;
            }
            else
            {
                DEBUGLOG(L"NetworkManager: Unknown peer removed: %d\n", peerid);
            }
        }

        _removedUsers.clear();

        std::shared_ptr<GameNetworkMessage> message;

        while (_receivedMessages.try_pop(message))
        {
            Managers::Get<GameStateManager>()->ProcessGameNetworkMessage(message);
        }
    }
}
