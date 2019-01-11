//--------------------------------------------------------------------------------------
// LaserProjectile.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Projectile.h"

namespace ThunderRumble
{

    class LaserProjectile : public Projectile
    {
    public:
        LaserProjectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction);

        virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext) override;
        virtual void Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly) override;

        // speed of the laser-bolt projectiles
        const float initialSpeed = 640.0f;
    private:
        TextureHandle m_texture;
    };

}
