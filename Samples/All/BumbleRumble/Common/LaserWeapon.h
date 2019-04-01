//--------------------------------------------------------------------------------------
// LaserWeapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Weapon.h"

namespace BumbleRumble
{

class LaserWeapon : public Weapon
{
public:
    LaserWeapon(std::shared_ptr<Ship> owner);
    virtual ~LaserWeapon();

    virtual void CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction) override;
    virtual WeaponType GetWeaponType() const override { return WeaponType::Laser; }
};

}
