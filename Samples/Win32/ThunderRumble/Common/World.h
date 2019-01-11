//--------------------------------------------------------------------------------------
// World.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "PowerUp.h"
#include "Asteroid.h"
#include "Starfield.h"
#include "Ship.h"

namespace ThunderRumble
{

    struct ShipSerialization
    {
        float xPos;
        float yPos;
        uint8_t weapon;
    };

    struct AsteroidSerialization
    {
        float radius;
        byte variation;
        float xPos;
        float yPos;
        float xVel;
        float yVel;
    };

    struct PowerUpSerialization
    {
        byte type;
        float xPos;
        float yPos;
    };

    class World
    {
    public:
        World();
        virtual ~World();

        // Clear the world of objects and reset default values
        void ResetDefaults();

        // Generate the world, placing asteroids and all ships
        void GenerateWorld();

        // Serialize the GameSettings packet (also included in the WorldSetup packet)
        std::vector<uint8_t> SerializeGameSettings();

        // Update the settings from the GameSettings packet
        void DeserializeGameSettings(const std::vector<uint8_t> &data);

        // Prepare the member ships and world data for the WorldSetup packet
        std::vector<uint8_t> SerializeWorldSetup(std::map<uint16_t, std::shared_ptr<Ship>>& ships);

        // Initialize the member ships and world with the data from the WorldSetup packet
        void DeserializeWorldSetup(const std::vector<uint8_t> &data);

        // Prepare the world data for the WorldData packet
        std::vector<uint8_t> SerializeWorldData();

        // Update the world with the data from the WorldData packet
        void DeserializeWorldData(const std::vector<uint8_t> &data);

        // Serialize powerUp spawn packet
        std::vector<uint8_t> SerializePowerUpSpawn();

        // Handle powerUp spawn packet
        void DeserializePowerUpSpawn(const std::vector<uint8_t> &data);

        // Serialize a suitable ship spawn point for the indicated player
        std::vector<uint8_t> SerializeShipSpawn(uint16_t peerid);

        // Spawn ship for indicated player
        void DeserializeShipSpawn(const std::vector<uint8_t> &data);

        // Prepare local ship death packet
        std::vector<uint8_t> SerializeShipDeath(std::shared_ptr<Ship> localShip);

        // Handle ship death packet
        void DeserializeShipDeath(uint16_t senderId, const std::vector<uint8_t> &data);

        // Serialize game over packet
        std::vector<uint8_t> SerializeGameOver();

        // Handle game over packet
        void DeserializeGameOver(const std::vector<uint8_t> &data);

        inline bool IsGameInProgress() { return m_isGameInProgress; }
        inline bool IsInitialized() { return m_isInitialized; }
        inline void SetGameInProgress(bool isGameInProgress) { m_isGameInProgress = isGameInProgress; }
        inline void SetInitialized(bool isInitialized) { m_isInitialized = isInitialized; }

        virtual void Update(float totalTime, float elapsedTime);
        virtual void Draw(float elapsedTime);

        bool IsGameWon;
        std::wstring WinnerName;
        DirectX::XMVECTORF32 WinningColor;
        int WinningScore;

        const int Game_BarrierCount = 50;           // default number of edge barriers per side
        const int Game_BarrierSize = 48;            // default size of each edge barrier
        const float Game_VisualPadding = 150.0f;    // distance to pull the center inwards so we don't see a large amount of outside space when local ship is near an edge
        const int Game_Asteroids = 15;              // default number of asteroids

        // The length of time it takes for another power-up to spawn.
        const float MaximumPowerUpTimer = 10.0f;

        const int c_UpdatesBetweenWorldDataPackets = 5;

    private:
        void SpawnPowerUp(PowerUpType type, const DirectX::SimpleMath::Vector2& position);

        bool m_isGameInProgress;
        bool m_isInitialized;
        float m_powerUpTimer;
        int m_updatesSinceWorldDataSent;

        // World contents
        RECT worldDimensions;
        DirectX::XMINT2 outerBarrierCounts;
        std::vector<RECT> cornerBarriers;
        std::vector<RECT> horizontalBarriers;
        std::vector<RECT> verticalBarriers;
        std::unique_ptr<Starfield> m_starfield;
        std::vector<std::shared_ptr<Asteroid>> m_asteroids;
        std::shared_ptr<PowerUp> m_powerUp;

        // World textures
        TextureHandle cornerBarrierTexture;
        TextureHandle horizontalBarrierTexture;
        TextureHandle verticalBarrierTexture;
    };

}