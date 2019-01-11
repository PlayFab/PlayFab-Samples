//--------------------------------------------------------------------------------------
// World.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "World.h"
#include "Managers.h"
#include "DataBuffer.h"
#include "PlayerState.h"
#include "Weapon.h"
#include "LaserWeapon.h"
#include "MineWeapon.h"
#include "DoubleLaserWeapon.h"
#include "TripleLaserWeapon.h"
#include "RocketWeapon.h"
#include "DoubleLaserPowerUp.h"
#include "TripleLaserPowerUp.h"
#include "RocketPowerUp.h"
#include "RandomMath.h"
#include "PlayFabManager.h"

#ifndef THUNDERRUMBLE_SERVER
#include "Game.h"
#else
#include "GameServer.h"
#endif

using namespace ThunderRumble;
using namespace DirectX;

World::World()
{
    m_isGameInProgress = false;
    WinningScore = 5;

    ResetDefaults();

    m_starfield = std::make_unique<Starfield>(SimpleMath::Vector2());

    // Set outer barrier and world dimensions
    outerBarrierCounts = XMINT2(Game_BarrierCount, Game_BarrierCount);
    worldDimensions.left = Game_BarrierSize;
    worldDimensions.right = outerBarrierCounts.x * Game_BarrierSize;
    worldDimensions.top = Game_BarrierSize;
    worldDimensions.bottom = outerBarrierCounts.y * Game_BarrierSize;

    // Load world barrier textures
    auto contentManager = Managers::Get<ContentManager>();
    cornerBarrierTexture = contentManager->LoadTexture(L"Assets\\Textures\\barrierEnd.png");
    horizontalBarrierTexture = contentManager->LoadTexture(L"Assets\\Textures\\barrierRed.png");
    verticalBarrierTexture = contentManager->LoadTexture(L"Assets\\Textures\\barrierPurple.png");

    // Initialize the CollisionManager
    auto collisionManager = Managers::Get<CollisionManager>();
    collisionManager->SetDimensions(worldDimensions);
    worldDimensions.top = worldDimensions.left = 0;

    // Setup the collision version of the world barriers
    auto MakeRect = [](int x, int y, int w, int h)
    {
        RECT r = { x, y, x + w, y + h };
        return r;
    };

    collisionManager->Barriers().clear();
    collisionManager->Barriers().push_back(MakeRect(worldDimensions.left, worldDimensions.top, worldDimensions.right - worldDimensions.left, Game_BarrierSize)); // top edge
    collisionManager->Barriers().push_back(MakeRect(worldDimensions.left, worldDimensions.bottom, worldDimensions.right - worldDimensions.left, Game_BarrierSize)); // bottom edge
    collisionManager->Barriers().push_back(MakeRect(worldDimensions.left, worldDimensions.top, Game_BarrierSize, worldDimensions.bottom - worldDimensions.top)); // left edge
    collisionManager->Barriers().push_back(MakeRect(worldDimensions.right, worldDimensions.top, Game_BarrierSize, worldDimensions.bottom - worldDimensions.top)); // right edge

    // Setup the rendering version of the world barriers
    cornerBarriers.clear();
    cornerBarriers.push_back(MakeRect(worldDimensions.left, worldDimensions.top, Game_BarrierSize, Game_BarrierSize)); // top-left corner
    cornerBarriers.push_back(MakeRect(worldDimensions.right, worldDimensions.top, Game_BarrierSize, Game_BarrierSize)); // top-right corner
    cornerBarriers.push_back(MakeRect(worldDimensions.left, worldDimensions.bottom, Game_BarrierSize, Game_BarrierSize)); // bottom-left corner
    cornerBarriers.push_back(MakeRect(worldDimensions.right, worldDimensions.bottom, Game_BarrierSize, Game_BarrierSize)); // bottom-right corner

    horizontalBarriers.clear();
    for (int i = 1; i < outerBarrierCounts.x; i++)
    {
        horizontalBarriers.push_back(MakeRect(worldDimensions.left + Game_BarrierSize * i, worldDimensions.top, Game_BarrierSize, Game_BarrierSize)); // top edge
        horizontalBarriers.push_back(MakeRect(worldDimensions.left + Game_BarrierSize * i, worldDimensions.top + worldDimensions.right - worldDimensions.left, Game_BarrierSize, Game_BarrierSize)); // bottom edge
    }

    verticalBarriers.clear();
    for (int i = 1; i < outerBarrierCounts.y; i++)
    {
        verticalBarriers.push_back(MakeRect(worldDimensions.left, worldDimensions.top + Game_BarrierSize * i, Game_BarrierSize, Game_BarrierSize)); // left edge
        verticalBarriers.push_back(MakeRect(worldDimensions.right, worldDimensions.top + Game_BarrierSize * i, Game_BarrierSize, Game_BarrierSize)); // right edge
    }
}

World::~World()
{
}

// Clear the world of objects and reset default values
void World::ResetDefaults()
{
    m_asteroids.clear();

    m_isInitialized = false;
    m_updatesSinceWorldDataSent = 0;
    m_powerUp = nullptr;
    m_powerUpTimer = MaximumPowerUpTimer;

    IsGameWon = false;
    WinnerName = L"";
    WinningColor = Colors::White;

    Managers::Get<GameStateManager>()->ClearPlayerScores();

    Managers::Get<CollisionManager>()->Collection()->ApplyPendingRemovals();
    Managers::Get<CollisionManager>()->Collection()->clear();
}

// Generate the world, placing asteroids and all ships
void World::GenerateWorld()
{
    // first reset world defaults from any prior game
    ResetDefaults();

    // initialize the ships, finding spawn points and resetting score
    for (const auto& playerState : Managers::Get<GameStateManager>()->GetAllPlayerStates())
    {
        if (playerState && playerState->LobbyReady)
        {
            auto ship = playerState->GetShip();
            ship->Initialize(Game_Asteroids);
            ship->Position = Managers::Get<CollisionManager>()->FindSpawnPoint(ship, ship->Radius);
        }
    }

    // place the asteroids
    for (int i = 0; i < Game_Asteroids; ++i)
    {
        // choose one of three radii and texture variations
        float radius = 32.0f;
        switch (RandomMath::RandomBetween(0, 2))
        {
        case 0:
            radius = 32.0f;
            break;
        case 1:
            radius = 60.0f;
            break;
        case 2:
            radius = 96.0f;
            break;
        }
        int variation = RandomMath::RandomBetween(0, Asteroid::Variations - 1);

        // create the asteroid
        m_asteroids.push_back(std::make_shared<Asteroid>(radius, variation));
        m_asteroids[i]->Initialize();
        m_asteroids[i]->Position = Managers::Get<CollisionManager>()->FindSpawnPoint(m_asteroids[i], radius);
    }

    auto localState = Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<NetworkManager>()->LocalPeerId());
    if (localState)
    {
        m_starfield->Reset(localState->GetShip()->Position);
    }

    m_isInitialized = true;
}

std::vector<uint8_t> World::SerializeShipSpawn(uint16_t peerid)
{
    auto playerState = Managers::Get<GameStateManager>()->GetPlayerState(peerid);
    if (playerState != nullptr)
    {
        auto ship = playerState->GetShip();
        if (ship != nullptr)
        {
            SimpleMath::Vector2 spawnPt = Managers::Get<CollisionManager>()->FindSpawnPoint(ship, ship->Radius);
            DataBufferWriter dataWriter;

            dataWriter.WriteUInt32(static_cast<uint32_t>(peerid));
            dataWriter.WriteStruct(spawnPt);

            return dataWriter.GetBuffer();
        }
    }

    return std::vector<uint8_t>();
}

void World::DeserializeShipSpawn(const std::vector<uint8_t>& data)
{
    DataBufferReader dataReader(data);

    auto peerid = static_cast<uint16_t>(dataReader.ReadUInt32());
    auto x = dataReader.ReadSingle();
    auto y = dataReader.ReadSingle();
    SimpleMath::Vector2 position = SimpleMath::Vector2(x, y);

    DEBUGLOG(L"DeserializeShipSpawn() received Peerid %u at (%f, %f)\n", peerid, position.x, position.y);

    auto playerState = Managers::Get<GameStateManager>()->GetPlayerState(peerid);
    if (playerState != nullptr)
    {
        auto ship = playerState->GetShip();
        if (ship != nullptr)
        {
            ship->Position = position;
            ship->Initialize(playerState->IsLocalPlayer);
        }
    }
}

std::vector<unsigned char> World::SerializePowerUpSpawn()
{
    DataBufferWriter dataWriter;

    dataWriter.WriteByte(static_cast<byte>(PowerUp::ChooseNextPowerUpType()));

    XMFLOAT2 spawnPt = Managers::Get<CollisionManager>()->FindSpawnPoint(nullptr, 50.0f);
    dataWriter.WriteStruct(spawnPt);

    return dataWriter.GetBuffer();
}

void World::DeserializePowerUpSpawn(const std::vector<uint8_t> &data)
{
    DataBufferReader dataReader(data);

    PowerUpType powerUpType = static_cast<PowerUpType>(dataReader.ReadByte());
    SimpleMath::Vector2 position;
    dataReader.ReadStruct(position);

    DEBUGLOG(L"DeserializePowerUpSpawn() received powerUp type %u at (%f, %f)\n", powerUpType, position.x, position.y);

    SpawnPowerUp(powerUpType, position);
}

// Prepare the world data for the WorldData packet
std::vector<unsigned char> World::SerializeWorldData()
{
    DataBufferWriter dataWriter;

    // write the asteroid data
    for (int i = 0; i < Game_Asteroids; ++i)
    {
        dataWriter.WriteStruct(m_asteroids[i]->Position);
        dataWriter.WriteStruct(m_asteroids[i]->Velocity);
    }

    return dataWriter.GetBuffer();
}

void World::DeserializeWorldData(const std::vector<uint8_t> &data)
{
    DataBufferReader dataReader(data);

    // update the asteroid data
    for (int i = 0; i < Game_Asteroids; ++i)
    {
        dataReader.ReadStruct(m_asteroids[i]->Position);
        dataReader.ReadStruct(m_asteroids[i]->Velocity);
    }
}

void World::DeserializeGameSettings(const std::vector<uint8_t> &data)
{
    DataBufferReader dataReader(data);
    WinningScore = dataReader.ReadInt32();
}

// Prepare the member ships and world data for the WorldSetup packet
std::vector<uint8_t> World::SerializeWorldSetup(std::map<uint16_t, std::shared_ptr<Ship>>& ships)
{
    DataBufferWriter dataWriter;

    dataWriter.WriteUInt32(static_cast<uint32_t>(ships.size()));

    // write active ship data
    for (auto& activeShipPair : ships)
    {
        auto peerid = activeShipPair.first;
        auto ship = activeShipPair.second;

        dataWriter.WriteUInt32(static_cast<uint32_t>(peerid));
        dataWriter.WriteStruct(ship->Position);

        WeaponType currentWeaponType = WeaponType::Unknown;
        if (ship->PrimaryWeapon != nullptr)
        {
            currentWeaponType = ship->PrimaryWeapon->GetWeaponType();
        }
        dataWriter.WriteByte(static_cast<uint8_t>(currentWeaponType));

        DEBUGLOG(L"SerializeWorldSetup() received Peer %u at (%f, %f) with weapon %u\n", peerid, ship->Position.x, ship->Position.y, currentWeaponType);
    }

    // write the asteroid data
    for (int i = 0; i < Game_Asteroids; ++i)
    {
        dataWriter.WriteSingle(m_asteroids[i]->Radius);
        dataWriter.WriteByte(static_cast<uint8_t>(m_asteroids[i]->Variation));
        dataWriter.WriteStruct(m_asteroids[i]->Position);
        dataWriter.WriteStruct(m_asteroids[i]->Velocity);
    }

    // write the powerUp data
    if (m_powerUp != nullptr)
    {
        dataWriter.WriteByte(static_cast<uint8_t>(m_powerUp->GetPowerUpType()));
        dataWriter.WriteStruct(m_powerUp->Position);
    }
    else
    {
        dataWriter.WriteByte(static_cast<uint8_t>(PowerUpType::Unknown));
        dataWriter.WriteSingle(0.0f);
        dataWriter.WriteSingle(0.0f);
    }

    // write the game mode and winning score (redundant with the GameSettings packet, but that packet isn't sent to those who join in progress)
    dataWriter.WriteInt32(WinningScore);

    return dataWriter.GetBuffer();
}

void World::DeserializeWorldSetup(const std::vector<uint8_t> &data)
{
#ifndef THUNDERRUMBLE_SERVER
    Managers::Get<PlayFabManager>()->UpdateStatistic(L"games_started", 1);
#endif

    DataBufferReader dataReader(data);

    // first reset world defaults from any prior game
    ResetDefaults();

    // read the members' ship data
    auto memberSize = dataReader.ReadUInt32();
    for (uint32_t i = 0; i < memberSize; ++i)
    {
        auto peerid = static_cast<uint16_t>(dataReader.ReadUInt32());

        SimpleMath::Vector2 position;
        dataReader.ReadStruct(position);

        WeaponType currentWeaponType = static_cast<WeaponType>(dataReader.ReadByte());

        DEBUGLOG(L"DeserializeWorldSetup() received Peerid %u at (%f, %f) with weapon %u\n", peerid, position.x, position.y, currentWeaponType);

        auto playerState = Managers::Get<GameStateManager>()->GetPlayerState(peerid);
        if (playerState != nullptr)
        {
            auto ship = playerState->GetShip();

            ship->Initialize(playerState->IsLocalPlayer);
            ship->Position = position;

            switch (currentWeaponType)
            {
            case WeaponType::Unknown:
                break;
            case WeaponType::Laser:
                ship->PrimaryWeapon = std::make_shared<LaserWeapon>(ship);
                break;
            case WeaponType::DoubleLaser:
                ship->PrimaryWeapon = std::make_shared<DoubleLaserWeapon>(ship);
                break;
            case WeaponType::TripleLaser:
                ship->PrimaryWeapon = std::make_shared<TripleLaserWeapon>(ship);
                break;
            case WeaponType::Rocket:
                ship->PrimaryWeapon = std::make_shared<RocketWeapon>(ship);
                break;
            case WeaponType::Mine:
                ship->PrimaryWeapon = std::make_shared<MineWeapon>(ship);
                break;
            default:
                break;
            }
        }
    }

    // read the asteroid data
    for (int i = 0; i < Game_Asteroids; ++i)
    {
        float radius = dataReader.ReadSingle();
        m_asteroids.push_back(std::make_shared<Asteroid>(radius, dataReader.ReadByte()));
        m_asteroids[i]->Initialize();
        dataReader.ReadStruct(m_asteroids[i]->Position);
        dataReader.ReadStruct(m_asteroids[i]->Velocity);
    }

    // read the powerUp data
    PowerUpType powerUpType = static_cast<PowerUpType>(dataReader.ReadByte());
    SimpleMath::Vector2 position;
    dataReader.ReadStruct(position);
    SpawnPowerUp(powerUpType, position);

    // read the game mode and winning score
    WinningScore = dataReader.ReadInt32();

    auto localstate = Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<NetworkManager>()->LocalPeerId());
    if (localstate && localstate->GetShip())
    {
        m_starfield->Reset(localstate->GetShip()->Position);
    }

    m_isInitialized = true;
}

std::vector<uint8_t> World::SerializeShipDeath(std::shared_ptr<Ship> localShip)
{
    if (localShip)
    {
        DataBufferWriter dataWriter;

        auto lastDamagedBy = localShip->LastDamagedBy;
        if (lastDamagedBy != nullptr &&
            lastDamagedBy->GetType() == GameplayObjectType::Ship &&
            lastDamagedBy != localShip)
        {
            uint16_t killer = 0;

            for (const auto& playerState : Managers::Get<GameStateManager>()->GetAllPlayerStates())
            {
                if (playerState && playerState->InGame)
                {
                    auto ship = playerState->GetShip();
                    if (ship && ship == lastDamagedBy)
                    {
                        killer = playerState->PeerId;
                        break;
                    }
                }
            }

            dataWriter.WriteUInt32(killer);
        }
        else
        {
            dataWriter.WriteUInt32(0);
        }

        return dataWriter.GetBuffer();
    }

    return std::move(std::vector<unsigned char>());
}

void World::DeserializeShipDeath(uint16_t peerid, const std::vector<uint8_t> &data)
{
    DEBUGLOG(L"DeserializeShipDeath() received for peer %u\n", peerid);

    auto playerState = Managers::Get<GameStateManager>()->GetPlayerState(peerid);
    if (playerState == nullptr)
    {
        return;
    }

    auto shipKilled = playerState->GetShip();
    if (shipKilled == nullptr)
    {
        return;
    }

    DataBufferReader dataReader(data);

    std::shared_ptr<Ship> killerShip = nullptr;
    auto killerid = static_cast<uint16_t>(dataReader.ReadUInt32());
    if (killerid != 0)
    {
        auto killerState = Managers::Get<GameStateManager>()->GetPlayerState(killerid);
        if (killerState)
        {
            killerShip = killerState->GetShip();

#ifndef THUNDERRUMBLE_SERVER
            if (killerState->IsLocalPlayer)
            {
                Json::Value metadata;
                metadata["Location"]["X"] = killerShip->Position.x;
                metadata["Location"]["Y"] = killerShip->Position.y;
                metadata["Target"]["Location"]["X"] = shipKilled->Position.x;
                metadata["Target"]["Location"]["Y"] = shipKilled->Position.y;

                Managers::Get<PlayFabManager>()->UpdateStatistic(L"enemies_defeated", 1, metadata);
            }
#endif
        }
    }

    shipKilled->Die(killerShip, false);
}

std::vector<unsigned char> World::SerializeGameOver()
{
    DataBufferWriter dataWriter;

    dataWriter.WriteStruct(WinningColor);
    dataWriter.WriteString(WinnerName);

    return dataWriter.GetBuffer();
}

void World::DeserializeGameOver(const std::vector<uint8_t> &data)
{
    DataBufferReader dataReader(data);

    dataReader.ReadStruct(WinningColor);

    WinnerName = dataReader.ReadString();

#ifndef THUNDERRUMBLE_SERVER
    auto online = Managers::Get<PlayFabManager>();

    online->UpdateStatistic(L"games_completed", 1);

    if (WinnerName == Managers::Get<GameStateManager>()->GetLocalPlayerName())
    {
        Json::Value metadata(Json::arrayValue);

        auto state = Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<NetworkManager>()->LocalPeerId());
        if (state)
        {
            metadata["Score"] = state->GetShip()->Score;
            online->UpdateStatistic(L"total_wins", 1, metadata);
        }
    }
#endif

    DEBUGLOG(L"DeserializeGameOver() received with winner %ws and color (%f, %f, %f, %f)\n", WinnerName.c_str(), WinningColor.f[0], WinningColor.f[1], WinningColor.f[2], WinningColor.f[3]);
}

void World::Update(float totalTime, float elapsedTime)
{
    UNREFERENCED_PARAMETER(totalTime);

#ifdef THUNDERRUMBLE_SERVER
    if (!IsGameWon)
    {
        int highScore = MININT;
        std::wstring highScoreName = L"";
        DirectX::XMVECTORF32 highScoreColor = Colors::White;

        for (const auto& playerState : Managers::Get<GameStateManager>()->GetAllPlayerStates())
        {
            if (playerState && playerState->InGame)
            {
                auto ship = playerState->GetShip();

                // get current high score (and scorer)
                if (ship->Score > highScore)
                {
                    highScore = ship->Score;
                    highScoreName = playerState->DisplayName;
                    highScoreColor = ship->Color;
                }

                // respawn players
                if (ship && !ship->Active() && ship->RespawnTimer <= 0.0f)
                {
                    // send ship spawn message and immediately process locally
                    auto messageData = SerializeShipSpawn(playerState->PeerId);
                    Managers::Get<NetworkManager>()->SendGameMessage(GameNetworkMessage(GameMessageType::ShipSpawn, playerState->PeerId, messageData));
                    DeserializeShipSpawn(messageData);
                }
            }
        }

        // respawn the power-up
        if (m_powerUp == nullptr)
        {
            m_powerUpTimer -= elapsedTime;
            if (m_powerUpTimer <= 0.0f)
            {
                // send the power-up-spawn packet and immediately process locally
                auto messageData = SerializePowerUpSpawn();
                Managers::Get<NetworkManager>()->SendGameMessage(GameNetworkMessage(GameMessageType::PowerUpSpawn, GameServer::c_ServerPeerId, messageData));
                DeserializePowerUpSpawn(messageData);
            }
        }
        else
        {
            m_powerUpTimer = MaximumPowerUpTimer;
        }

        // check if game has been won
        if (highScore >= WinningScore)
        {
            DEBUGLOG(L"GAME OVER\n");

            WinnerName = highScoreName;
            WinningColor = highScoreColor;

            Managers::Get<NetworkManager>()->SendGameMessage(
                GameNetworkMessage(
                    GameMessageType::GameOver,
                    GameServer::c_ServerPeerId,
                    SerializeGameOver()
                )
            );

            SetGameInProgress(false);
            IsGameWon = true;
        }
    }
#endif

    // update all player ships based on last input
    for (const auto& playerState : Managers::Get<GameStateManager>()->GetAllPlayerStates())
    {
        if (playerState && playerState->InGame)
        {
            auto ship = playerState->GetShip();
            if (ship)
            {
                if (ship->Active())
                {
                    ship->Update(elapsedTime);

#ifdef THUNDERRUMBLE_SERVER
                    // check for ship death
                    //   -- server is authority on death of own ship
                    if (ship->Life < 0 && !IsGameWon)
                    {
                        // send local ship death message and immediately process locally
                        auto messageData = SerializeShipDeath(ship);
                        Managers::Get<NetworkManager>()->SendGameMessage(
                            GameNetworkMessage(
                                GameMessageType::ShipDeath,
                                playerState->PeerId,
                                messageData
                            )
                        );
                        DeserializeShipDeath(playerState->PeerId, messageData);
                    }
#endif
                }
                else if (ship->RespawnTimer > 0.0f)
                {
                    // everyone (not just the host) updates all respawn timers so we can display respawn countdown in HUD
                    ship->RespawnTimer -= elapsedTime;
                }
            }
        }
    }

#ifdef THUNDERRUMBLE_SERVER
    // update all asteroids
    for (size_t i = 0; i < m_asteroids.size(); ++i)
    {
        if (m_asteroids[i]->Active())
        {
            m_asteroids[i]->Update(elapsedTime);
        }
    }
#endif
    // update the power-up
    if (m_powerUp != nullptr)
    {
        if (m_powerUp->Active())
        {
            m_powerUp->Update(elapsedTime);
        }
        else
        {
            m_powerUp = nullptr;
        }
    }

    // update collision manager to apply all physics
    Managers::Get<CollisionManager>()->Update(elapsedTime);

    // update the particle-effect manager
    Managers::Get<ParticleEffectManager>()->Update(elapsedTime);

    // final host duties
    // send everyone an update on the latest state of the world
#ifdef THUNDERRUMBLE_SERVER
    if (m_updatesSinceWorldDataSent >= c_UpdatesBetweenWorldDataPackets)
    {
        Managers::Get<NetworkManager>()->SendGameMessage(
            GameNetworkMessage(
                GameMessageType::WorldData,
                GameServer::c_ServerPeerId,
                SerializeWorldData()
            )
        );

        Managers::Get<GameStateManager>()->SendShipUpdates();

        m_updatesSinceWorldDataSent = 0;
    }
    else
    {
        m_updatesSinceWorldDataSent++;
    }
#endif
}

void World::Draw(float elapsedTime)
{
    UNREFERENCED_PARAMETER(elapsedTime);
#ifndef THUNDERRUMBLE_SERVER
    float viewportWidth = static_cast<float>(TheGame->GetWindowWidth());
    float viewportHeight = static_cast<float>(TheGame->GetWindowHeight());
    auto localShip = Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<NetworkManager>()->LocalPeerId())->GetShip();

    XMFLOAT2 center = XMFLOAT2(localShip->Position.x - viewportWidth / 2.0f, localShip->Position.y - viewportHeight / 2.0f);

    // pull the center inwards so that it doesn't show a ton of the space outside the game
    center.x = std::min(std::max(center.x, worldDimensions.left - Game_VisualPadding), worldDimensions.right - viewportWidth + Game_VisualPadding);
    center.y = std::min(std::max(center.y, worldDimensions.top - Game_VisualPadding), worldDimensions.bottom - viewportHeight + Game_VisualPadding);

    // draw the starfield
    m_starfield->Draw(center);

    if (m_isInitialized)
    {
        auto renderContext = Managers::Get<RenderManager>()->GetRenderContext(BlendMode::NonPremultiplied);
        XMMATRIX transform = XMMatrixTranslation(-center.x, -center.y, 0);

        renderContext->Begin(transform);

        // draw the barriers
        std::for_each(cornerBarriers.begin(), cornerBarriers.end(), [&](RECT r) { renderContext->Draw(cornerBarrierTexture, r); });
        std::for_each(horizontalBarriers.begin(), horizontalBarriers.end(), [&](RECT r) { renderContext->Draw(horizontalBarrierTexture, r); });
        std::for_each(verticalBarriers.begin(), verticalBarriers.end(), [&](RECT r) { renderContext->Draw(verticalBarrierTexture, r); });

        // draw the powerup
        if (m_powerUp != nullptr && m_powerUp->Active())
        {
            m_powerUp->Draw(elapsedTime, renderContext);
        }

        // draw the asteroids
        for (int i = 0; i < Game_Asteroids; ++i)
        {
            if (m_asteroids[i]->Active())
            {
                m_asteroids[i]->Draw(elapsedTime, renderContext);
            }
        }

        // draw each ship
        for (const auto& playerState : Managers::Get<GameStateManager>()->GetAllPlayerStates())
        {
            if (playerState && playerState->InGame)
            {
                auto ship = playerState->GetShip();
                if (ship && ship->Active())
                {
                    ship->Draw(elapsedTime, renderContext, false);
                }
            }
        }

        // draw the alpha-blended particles
        Managers::Get<ParticleEffectManager>()->Draw(renderContext, SpriteBlendMode::Alpha);

        renderContext->End();

        renderContext = Managers::Get<RenderManager>()->GetRenderContext(BlendMode::Additive);

        // draw the additive particles
        renderContext->Begin(transform, SpriteSortMode::SpriteSortMode_Texture);

        Managers::Get<ParticleEffectManager>()->Draw(renderContext, SpriteBlendMode::Additive);

        renderContext->End();
    }
#endif
}

void World::SpawnPowerUp(PowerUpType type, const DirectX::SimpleMath::Vector2 & position)
{
    switch (type)
    {
    case PowerUpType::DoubleLaser:
        m_powerUp = std::make_shared<DoubleLaserPowerUp>();
        break;
    case PowerUpType::TripleLaser:
        m_powerUp = std::make_shared <TripleLaserPowerUp>();
        break;
    case PowerUpType::Rocket:
        m_powerUp = std::make_shared <RocketPowerUp>();
        break;
    default:
        m_powerUp = nullptr;
        break;
    }

    if (m_powerUp != nullptr)
    {
        m_powerUp->Position = position;
        m_powerUp->Initialize();
    }
}
