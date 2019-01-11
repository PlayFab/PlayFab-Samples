//--------------------------------------------------------------------------------------
// Projectile.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Projectile.h"

#include "Managers.h"
#include "Ship.h"

using namespace ThunderRumble;

Projectile::Projectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction) :
    m_owner(owner),
    m_damageAmount(0.0f),
    m_damageRadius(0.0f),
    m_damageOwner(true),
    m_duration(0.0f)
{
    Velocity = direction;
    Position = owner->Position;
    Rotation = std::acos(direction.y); // safe for all angles, but assumes direction is a unit vector
    if (direction.x > 0.0f)
    {
        Rotation *= -1.0f;
    }
}

Projectile::~Projectile()
{
}

void Projectile::Update(float elapsedTime)
{
    // projectiles can "time out"
    if (m_duration > 0.0f)
    {
        m_duration -= elapsedTime;
        if (m_duration < 0.0f)
        {
            Die(nullptr, false);
        }
    }

    GameplayObject::Update(elapsedTime);
}

/// <summary>
/// Defines the interaction between this projectile and a target GameplayObject
/// when they touch.
/// </summary>
/// <param name="target">The GameplayObject that is touching this one.</param>
/// <returns>True if the objects meaningfully interacted.</returns>
bool Projectile::OnTouch(std::shared_ptr<GameplayObject> target)
{
    // check the target, if we have one
    if (target != nullptr)
    {
        // don't bother hitting any power-ups
        if (target->GetType() == GameplayObjectType::PowerUp)
        {
            return false;
        }

        // don't hit the owner if the damageOwner flag isn't set
        if ((m_damageOwner == false) && (target == m_owner))
        {
            return false;
        }

        // don't hit other projectiles from the same ship
        if (target->GetType() == GameplayObjectType::Projectile)
        {
            auto projectile = std::dynamic_pointer_cast<Projectile>(target);
            if (projectile->GetOwner() == m_owner)
            {
                return false;
            }
        }

        // asteroids and enemy ships kill all projectiles
        if (target->GetType() == GameplayObjectType::Asteroid || target->GetType() == GameplayObjectType::Ship)
        {
            Life = 0.0f;
        }

        // damage the target
        target->TakeDamage(shared_from_this(), m_damageAmount);
    }

    // either we hit something or the target is null - in either case, check if we die
    if (Life <= 0.0f)
    {
        Die(target, false);
    }

    return GameplayObject::OnTouch(target);
}

void Projectile::Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly)
{
    if (m_active)
    {
        if (!cleanupOnly)
        {
            Managers::Get<CollisionManager>()->Explode(
                shared_from_this(),
                source,
                m_damageAmount,
                Position,
                m_damageRadius,
                m_damageOwner
            );
        }
    }

    GameplayObject::Die(source, cleanupOnly);
}