//--------------------------------------------------------------------------------------
// NetworkMessages.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "NetworkMessages.h"

using namespace BumbleRumble;

GameNetworkMessage::GameNetworkMessage() :
    m_type(GameMessageType::Unknown)
{
}

GameNetworkMessage::~GameNetworkMessage()
{
}

GameNetworkMessage::GameNetworkMessage(GameMessageType type, unsigned data)
{
    m_type = type;
    m_data.resize(sizeof(unsigned));
    CopyMemory(m_data.data(), &data, sizeof(data));
}

GameNetworkMessage::GameNetworkMessage(GameMessageType type, const std::string &data)
{
    m_type = type;
    m_data.resize(data.length() * sizeof(char));
    CopyMemory(m_data.data(), reinterpret_cast<const uint8_t*>(data.c_str()), m_data.size());
}

GameNetworkMessage::GameNetworkMessage(GameMessageType type, const std::vector<uint8_t> &data)
{
    m_type = type;
    m_data = data;
}

GameNetworkMessage::GameNetworkMessage(const std::vector<uint8_t> &data)
{
    if (data.size() < (sizeof(GameMessageType) + sizeof(uint8_t)))
    {
        // Invalid message
        return;
    }

    CopyMemory(&m_type, data.data(), sizeof(GameMessageType));
    m_data.resize(data.size() - sizeof(GameMessageType));
    CopyMemory(m_data.data(), data.data() + sizeof(GameMessageType), m_data.size());
}

std::vector<uint8_t>
GameNetworkMessage::Serialize() const
{
    if (m_type == GameMessageType::Unknown || m_data.empty())
    {
        return std::vector<uint8_t>();
    }

    size_t length = sizeof(GameMessageType) + m_data.size();
    uint8_t *buffer = new uint8_t[length];

    CopyMemory(buffer, &m_type, sizeof(GameMessageType));
    CopyMemory(buffer + sizeof(GameMessageType), m_data.data(), m_data.size());

    auto packet = std::vector<uint8_t>(buffer, buffer + length);

    delete [] buffer;

    return packet;
}

std::string GameNetworkMessage::StringValue()
{
    if (!m_data.empty())
    {
        auto stringData = reinterpret_cast<char *>(m_data.data());
        return std::string(stringData, stringData + (m_data.size() / sizeof(char)));
    }

    return "";
}

unsigned
GameNetworkMessage::UnsignedValue()
{
    if (!m_data.empty())
    {
        return *(reinterpret_cast<unsigned *>(m_data.data()));
    }

    return 0;
}

