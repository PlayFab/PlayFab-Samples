//--------------------------------------------------------------------------------------
// MineWeapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Weapon.h"

namespace BumbleRumble
{

class MineWeapon : public Weapon
{
public:
    MineWeapon(std::shared_ptr<Ship> owner);
    virtual ~MineWeapon();

    // The distance that the mine spawns behind the ship.
    const float c_mineSpawnDistance = 8.0f;

    virtual void CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction) override;
    virtual WeaponType GetWeaponType() const override { return WeaponType::Mine; }
};

}
