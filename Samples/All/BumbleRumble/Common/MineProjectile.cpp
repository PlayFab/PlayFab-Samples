//--------------------------------------------------------------------------------------
// MineProjectile.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "MineProjectile.h"

#include "Managers.h"
#include "Ship.h"

using namespace BumbleRumble;
using namespace DirectX;

namespace
{
    /// The initial life of this projectile.
    constexpr float c_initialLife = 150.0f;

    /// The initial speed of this projectile.
    constexpr float c_initialSpeed = 80.0f;

    /// The amount of drag applied to velocity per second, 
    /// as a percentage of velocity.
    constexpr float c_dragPerSecond = 0.9f;

    /// The radians-per-second that this object rotates at.
    constexpr float c_rotationRadiansPerSecond = 1.0f;
}

MineProjectile::MineProjectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction) : 
    Projectile(owner, direction),
    m_anchored(false)
{
    // set the gameplay data
    Velocity.x = c_initialSpeed * direction.x;
    Velocity.y = c_initialSpeed * direction.y;

    // set the collision data
    Radius = 10.0f;
    Mass = 5.0f;

    // set the projectile data
    m_duration = 20.0f;
    m_damageAmount = 200.0f;
    m_damageRadius = 300.0f;
    m_damageOwner = false;
    Life = c_initialLife;

    m_texture = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\mine.png");
}

MineProjectile::~MineProjectile()
{
}

void MineProjectile::Update(float elapsedTime)
{
    Projectile::Update(elapsedTime);

    Velocity.x -= Velocity.x * elapsedTime * c_dragPerSecond;
    Velocity.y -= Velocity.y * elapsedTime * c_dragPerSecond;

    // once mines near stop after their initial release, they become anchored and unmovable
    if (!m_anchored)
    {
        float speedSquared = 0.0f;
        XMStoreFloat(&speedSquared, XMVector2LengthSq(XMLoadFloat2(&Velocity)));

        if (speedSquared < 100.0f)
        {
            m_anchored = true;
        }
    }

    if (m_anchored)
    {
        Velocity.x = 0.0f;
        Velocity.y = 0.0f;
    }

    Rotation += elapsedTime * c_rotationRadiansPerSecond;
}

void MineProjectile::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext)
{
    // ignore the parameter color if we have an owner
    GameplayObject::Draw(elapsedTime, renderContext, m_texture, (m_anchored && m_owner != nullptr) ? m_owner->Color : Colors::White);
}

bool MineProjectile::TakeDamage(std::shared_ptr<GameplayObject> source, float damageAmount)
{
    if (source->GetType() == GameplayObjectType::Projectile)
    {
        Life -= damageAmount;
    }
    else
    {
        Life = 0.0f;
    }

    if (Life <= 0.0f)
    {
        Die(source, false);
    }

    return true;
}

void MineProjectile::Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly)
{
    if (m_active)
    {
        if (!cleanupOnly)
        {
            // play the mine explosion sound
            Managers::Get<AudioManager>()->PlaySound("explosion_large");

            // display the mine explosion
            Managers::Get<ParticleEffectManager>()->SpawnEffect(ParticleEffectType::MineExplosion, Position);
        }
    }

    Projectile::Die(source, cleanupOnly);
}
