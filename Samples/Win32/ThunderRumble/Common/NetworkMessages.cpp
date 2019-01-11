//--------------------------------------------------------------------------------------
// NetworkMessages.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "NetworkMessages.h"

using namespace ThunderRumble;

GameNetworkMessage::GameNetworkMessage()
{
    _type = GameMessageType::Unknown;
    _peer = 0;
}

GameNetworkMessage::~GameNetworkMessage()
{
}

GameNetworkMessage::GameNetworkMessage(GameMessageType type, uint16_t peerid, unsigned data)
{
    _peer = peerid;
    _type = type;
    _data.resize(sizeof(unsigned));
    CopyMemory(_data.data(), &data, sizeof(data));
}

GameNetworkMessage::GameNetworkMessage(GameMessageType type, uint16_t peerid, const std::wstring &data)
{
    _peer = peerid;
    _type = type;
    _data.resize(data.length() * sizeof(wchar_t));
    CopyMemory(_data.data(), reinterpret_cast<const uint8_t*>(data.c_str()), _data.size());
}

GameNetworkMessage::GameNetworkMessage(GameMessageType type, uint16_t peerid, const std::vector<uint8_t> &data)
{
    _peer = peerid;
    _type = type;
    _data = data;
}

GameNetworkMessage::GameNetworkMessage(const std::vector<uint8_t> &data)
{
    if (data.size() < (sizeof(GameMessageType) + sizeof(uint8_t)))
    {
        // Invalid message
        return;
    }

    CopyMemory(&_type, data.data(), sizeof(GameMessageType));
    CopyMemory(&_peer, data.data() + sizeof(GameMessageType), sizeof(_peer));

    _data.resize(data.size() - sizeof(_peer) - sizeof(GameMessageType));
    CopyMemory(_data.data(), data.data() + sizeof(GameMessageType) + sizeof(_peer), _data.size());
}

std::vector<uint8_t>
GameNetworkMessage::Serialize() const
{
    if (_type == GameMessageType::Unknown || _data.empty())
    {
        return std::vector<uint8_t>();
    }

    size_t length = sizeof(GameMessageType) + sizeof(_peer) + _data.size();
    uint8_t *buffer = new uint8_t[length];

    CopyMemory(buffer, &_type, sizeof(GameMessageType));
    CopyMemory(buffer + sizeof(GameMessageType), &_peer, sizeof(_peer));
    CopyMemory(buffer + sizeof(GameMessageType) + sizeof(_peer), _data.data(), _data.size());

    auto packet = std::vector<uint8_t>(buffer, buffer + length);

    delete[] buffer;

    return packet;
}

std::wstring GameNetworkMessage::StringValue()
{
    if (!_data.empty())
    {
        auto stringData = reinterpret_cast<wchar_t *>(_data.data());
        return std::wstring(stringData, stringData + (_data.size() / sizeof(wchar_t)));
    }

    return L"";
}

unsigned
GameNetworkMessage::UnsignedValue()
{
    if (!_data.empty())
    {
        return *(reinterpret_cast<unsigned *>(_data.data()));
    }

    return 0;
}

