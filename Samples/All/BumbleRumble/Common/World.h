//--------------------------------------------------------------------------------------
// World.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "PowerUp.h"
#include "Asteroid.h"
#include "Starfield.h"
#include "Ship.h"

namespace BumbleRumble
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
    std::vector<uint8_t> SerializeWorldSetup(std::map<std::string, std::shared_ptr<Ship>>& ships);

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
    std::vector<uint8_t> SerializeShipSpawn(std::string& peerid);

    // Spawn ship for indicated player
    void DeserializeShipSpawn(const std::vector<uint8_t> &data);

    // Prepare local ship death packet
    std::vector<uint8_t> SerializeShipDeath(std::shared_ptr<Ship> localShip);

    // Handle ship death packet
    void DeserializeShipDeath(std::string& senderId, const std::vector<uint8_t> &data);

    // Serialize game over packet
    std::vector<uint8_t> SerializeGameOver();

    // Handle game over packet
    void DeserializeGameOver(const std::vector<uint8_t> &data);

    inline bool IsGameInProgress() { return m_isGameInProgress; }
    inline bool IsInitialized(){ return m_isInitialized; }
    inline void SetGameInProgress(bool isGameInProgress) { m_isGameInProgress = isGameInProgress; }
    inline void SetInitialized(bool isInitialized) { m_isInitialized = isInitialized; }

    virtual void Update(float totalTime, float elapsedTime);
    virtual void Draw(float elapsedTime);

    bool IsGameWon;
    std::string WinnerName;
    DirectX::XMVECTORF32 WinningColor;
    int WinningScore;

    const int c_gameBarrierCount = 50;           // default number of edge barriers per side
    const int c_gameBarrierSize = 48;            // default size of each edge barrier
    const float c_gameVisualPadding = 150.0f;    // distance to pull the center inwards so we don't see a large amount of outside space when local ship is near an edge
    const int c_gameAsteroids = 15;              // default number of asteroids

    // The length of time it takes for another power-up to spawn.
    const float c_maximumPowerUpTimer = 10.0f;

    const int c_updatesBetweenWorldDataPackets = 30;

private:
    void SpawnPowerUp(PowerUpType type, const DirectX::SimpleMath::Vector2& position);

    bool m_isGameInProgress;
    bool m_isInitialized;
    float m_powerUpTimer;
    int m_updatesSinceWorldDataSent;

    // World contents
    RECT m_worldDimensions;
    DirectX::XMINT2 m_outerBarrierCounts;
    std::vector<RECT> m_cornerBarriers;
    std::vector<RECT> m_horizontalBarriers;
    std::vector<RECT> m_verticalBarriers;
    std::unique_ptr<Starfield> m_starfield;
    std::vector<std::shared_ptr<Asteroid>> m_asteroids;
    std::shared_ptr<PowerUp> m_powerUp;

    // World textures
    std::shared_ptr<DX::Texture> m_cornerBarrierTexture;
    std::shared_ptr<DX::Texture> m_horizontalBarrierTexture;
    std::shared_ptr<DX::Texture> m_verticalBarrierTexture;
};

}