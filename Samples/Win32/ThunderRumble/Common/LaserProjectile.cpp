//--------------------------------------------------------------------------------------
// LaserProjectile.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "LaserProjectile.h"
#include "Ship.h"
#include "Managers.h"

using namespace ThunderRumble;
using namespace DirectX;

LaserProjectile::LaserProjectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction) : Projectile(owner, direction)
{
    // set the gameplay data
    Velocity.x = initialSpeed * direction.x;
    Velocity.y = initialSpeed * direction.y;

    // set the collision data
    Radius = 4.0f;
    Mass = 0.5f;

    // set the projectile data
    m_duration = 5.0f;
    m_damageAmount = 20.0f;
    m_damageRadius = 0.0f;
    m_damageOwner = false;

    m_texture = Managers::Get<ContentManager>()->LoadTexture(L"Assets\\Textures\\laser.png");
}

void LaserProjectile::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext)
{
    // ignore the parameter color if we have an owner
    GameplayObject::Draw(elapsedTime, renderContext, m_texture, m_owner != nullptr ? m_owner->Color : Colors::White);
}

void LaserProjectile::Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly)
{
    if (m_active)
    {
        // display the laser explosion
        if (!cleanupOnly)
        {
            Managers::Get<ParticleEffectManager>()->SpawnEffect(ParticleEffectType::LaserExplosion, Position);
        }
    }

    Projectile::Die(source, cleanupOnly);
}
