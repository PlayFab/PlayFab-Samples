//--------------------------------------------------------------------------------------
// Ship.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameplayObject.h"
#include "ShipInput.h"
#include "Projectile.h"
#include "Weapon.h"
#include "BatchRemovalCollection.h"

namespace ThunderRumble
{

    class PlayerState;

    class Ship : public GameplayObject
    {
    public:
        Ship();

        //virtual void Initialize() override;
        void Initialize(bool isLocal, bool useSpawnEffect = true);
        virtual void Update(float elapsedTime) override;
        virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext, bool onlyDrawBody, float scale = 1.0f);
        virtual bool TakeDamage(std::shared_ptr<GameplayObject> source, float damageAmount) override;
        virtual void Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly) override;
        void SetSafe(bool isSafe);

        virtual GameplayObjectType GetType() const override { return GameplayObjectType::Ship; }

        // Prepare the ship input data for the ShipInput packet
        std::vector<unsigned char> Serialize();

        // Get the latest ship input from the ShipInput packet
        void Deserialize(const std::vector<unsigned char> &data);

        void SetShipTexture(uint32_t index);

        uint32_t Variation;
        DirectX::XMVECTORF32 Color;

        ShipInput Input;

        int Score;

        std::shared_ptr<Weapon> PrimaryWeapon;
        std::shared_ptr<Weapon> DroppedWeapon;

        float Shield;
        float RespawnTimer;

        bool IsLocal;

        std::shared_ptr<GameplayObject> LastDamagedBy;

        BatchRemovalCollection<std::shared_ptr<Projectile>> Projectiles;
    private:
        TextureHandle m_primaryTexture;
        TextureHandle m_overlayTexture;
        TextureHandle m_shieldTexture;

        float m_safeTimer;
        float m_shieldPulseTime;
        float m_shieldRechargeTimer;

    public:
        /// The colors used for each ship.
        static const std::array<DirectX::XMVECTORF32, 18> Colors;

        static constexpr uint32_t MaxVariations = 4;
    };

}
