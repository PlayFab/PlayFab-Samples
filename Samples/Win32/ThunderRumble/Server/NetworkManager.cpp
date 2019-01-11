//--------------------------------------------------------------------------------------
// NetworkManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Managers.h"
#include "GameServer.h"

using namespace ThunderRumble;

NetworkManager::NetworkManager()
{
    _peerId = GameServer::c_ServerPeerId;
}

NetworkManager::~NetworkManager()
{
}

void NetworkManager::SendGameMessage(const GameNetworkMessage& message)
{
    Managers::Get<GameStateManager>()->GetPendingSends().push_back(std::make_pair(_peerId, message.Serialize()));
}
