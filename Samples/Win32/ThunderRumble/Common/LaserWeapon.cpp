//--------------------------------------------------------------------------------------
// LaserWeapon.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "LaserWeapon.h"

#include "LaserProjectile.h"
#include "Ship.h"

using namespace ThunderRumble;

LaserWeapon::LaserWeapon(std::shared_ptr<Ship> owner) : Weapon(owner)
{
    m_fireDelay = 0.15f;

    switch (owner->Variation % 3)
    {
    case 0:
        m_fireSoundEffect = L"fire_laser1";
        break;
    case 1:
        m_fireSoundEffect = L"fire_laser2";
        break;
    case 2:
        m_fireSoundEffect = L"fire_laser3";
        break;
    default:
        break;
    }
}

LaserWeapon::~LaserWeapon()
{
}

void LaserWeapon::CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction)
{
    // create the new projectile
    auto projectile = std::make_shared<LaserProjectile>(m_owner, direction);
    projectile->Initialize();

    m_owner->Projectiles.push_back(projectile);
}
