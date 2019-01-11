//--------------------------------------------------------------------------------------
// RocketProjectile.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "RocketProjectile.h"

#include "Managers.h"
#include "Ship.h"

using namespace ThunderRumble;
using namespace DirectX;

RocketProjectile::RocketProjectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction) :
    Projectile(owner, direction),
    m_rocketTrailEffect(nullptr)
{
    // set the gameplay data
    Velocity.x = initialSpeed * direction.x;
    Velocity.y = initialSpeed * direction.y;

    // set the collision data
    Radius = 8.0f;
    Mass = 10.0f;

    // set the projectile data
    m_duration = 4.0f;
    m_damageAmount = 150.0f;
    m_damageRadius = 128.0f;
    m_damageOwner = false;
    Rotation += DirectX::XM_PI;

    m_rocketTexture = Managers::Get<ContentManager>()->LoadTexture(L"Assets\\Textures\\rocket.png");
}

RocketProjectile::~RocketProjectile()
{
}

void RocketProjectile::Initialize()
{
    if (!Active())
    {
        m_rocketTrailEffect = Managers::Get<ParticleEffectManager>()->SpawnEffect(ParticleEffectType::RocketTrail, Position, shared_from_this());
        m_rocketTrailEffect->SetFollowOffset(SimpleMath::Vector2(-Radius * 2.5f, 0));
    }

    Projectile::Initialize();
}

void RocketProjectile::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext)
{
    GameplayObject::Draw(
        elapsedTime,
        renderContext,
        m_rocketTexture,
        m_owner != nullptr ? m_owner->Color : Colors::White
    );
}

void RocketProjectile::Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly)
{
    if (m_active)
    {
        if (!cleanupOnly)
        {
            // play the rocket explosion sound
            Managers::Get<AudioManager>()->PlaySound(L"explosion_medium");

            // display the rocket explosion
            Managers::Get<ParticleEffectManager>()->SpawnEffect(ParticleEffectType::RocketExplosion, Position);
        }

        // stop the rocket trail effect
        if (m_rocketTrailEffect != nullptr)
        {
            m_rocketTrailEffect->Stop(false);
        }
    }

    Projectile::Die(source, cleanupOnly);
}
