//--------------------------------------------------------------------------------------
// MineProjectile.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Projectile.h"

namespace ThunderRumble
{

    class MineProjectile : public Projectile
    {
    public:
        MineProjectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction);
        virtual ~MineProjectile();

        virtual void Update(float elapsedTime) override;
        virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext) override;
        virtual bool TakeDamage(std::shared_ptr<GameplayObject> source, float damageAmount) override;
        virtual void Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly) override;

        static void LoadContent();
        static void UnloadContent();

    private:
        bool anchored;
        TextureHandle m_texture;
    };

}
