//--------------------------------------------------------------------------------------
// MineWeapon.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "MineWeapon.h"

#include "MineProjectile.h"
#include "Ship.h"

using namespace ThunderRumble;

MineWeapon::MineWeapon(std::shared_ptr<Ship> owner) : Weapon(owner)
{
    m_fireDelay = 3.0f;
}

MineWeapon::~MineWeapon()
{
}

void MineWeapon::CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction)
{
    // create the new projectile
    auto projectile = std::make_shared<MineProjectile>(m_owner, direction);
    projectile->Initialize();

    m_owner->Projectiles.push_back(projectile);

    // move the mine out from the ship
    float magnitude = m_owner->Radius + projectile->Radius + mineSpawnDistance;
    projectile->Position += direction * magnitude;
}
