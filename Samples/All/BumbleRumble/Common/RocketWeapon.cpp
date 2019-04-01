//--------------------------------------------------------------------------------------
// RocketWeapon.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "RocketWeapon.h"

#include "RandomMath.h"
#include "RocketProjectile.h"
#include "Ship.h"

using namespace BumbleRumble;

RocketWeapon::RocketWeapon(std::shared_ptr<Ship> owner) : Weapon(owner)
{
    m_fireDelay = 0.5f;

    if (RandomMath::RandomBetween(0, 1) == 0)
    {
        m_fireSoundEffect = "fire_rocket1";
    }
    else
    {
        m_fireSoundEffect = "fire_rocket2";
    }
}

RocketWeapon::~RocketWeapon()
{
}

void RocketWeapon::CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction)
{
    // create the new projectile
    auto projectile = std::make_shared<RocketProjectile>(m_owner, direction);
    projectile->Initialize();

    m_owner->Projectiles.push_back(projectile);
}
