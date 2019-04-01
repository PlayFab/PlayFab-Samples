//--------------------------------------------------------------------------------------
// RocketProjectile.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Projectile.h"

namespace BumbleRumble
{

class ParticleEffect;

class RocketProjectile : public Projectile
{
public:
    RocketProjectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction);
    virtual ~RocketProjectile();

    virtual void Initialize() override;
    virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext) override;
    virtual void Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly) override;

    // speed of the laser-bolt projectiles
    const float c_initialSpeed = 650.0f;

protected:
    std::shared_ptr<DX::Texture> m_rocketTexture;
    std::shared_ptr<ParticleEffect> m_rocketTrailEffect;
};

}
