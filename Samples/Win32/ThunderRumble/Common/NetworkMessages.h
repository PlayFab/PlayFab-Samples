//--------------------------------------------------------------------------------------
// NetworkMessages.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

namespace ThunderRumble
{

    enum class GameMessageType
    {
        Unknown,
        GameStart,
        GameTurn,
        GameOver,
        GameLeft,
        GameSettings,
        PlayerInfo,
        PlayerState,
        PowerUpSpawn,
        WorldSetup,
        WorldData,
        ShipSpawn,
        ShipInput,
        ShipData,
        ShipDeath
    };

    class GameNetworkMessage
    {
    public:
        GameNetworkMessage();
        GameNetworkMessage(GameMessageType type, uint16_t peerid, unsigned data);
        GameNetworkMessage(GameMessageType type, uint16_t peerid, const std::wstring &data);
        GameNetworkMessage(GameMessageType type, uint16_t peerid, const std::vector<uint8_t> &data);
        GameNetworkMessage(const std::vector<uint8_t> &data);
        ~GameNetworkMessage();

        inline uint16_t Peer() { return _peer; }
        inline void Peer(uint16_t peerid) { _peer = peerid; }

        inline GameMessageType MessageType() { return _type; }
        inline void MessageType(GameMessageType type) { _type = type; }

        inline const std::vector<uint8_t> &RawData() { return _data; }
        inline void RawData(const std::vector<uint8_t> &data) { _data = data; }

        std::wstring StringValue();
        unsigned UnsignedValue();

        std::vector<uint8_t> Serialize() const;

    private:
        uint16_t _peer;
        GameMessageType _type;
        std::vector<uint8_t> _data;
    };

}
