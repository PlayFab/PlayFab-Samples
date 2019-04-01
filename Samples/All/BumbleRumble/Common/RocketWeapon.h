//--------------------------------------------------------------------------------------
// RocketWeapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Weapon.h"

namespace BumbleRumble
{
class RocketWeapon : public Weapon
{

public:
    RocketWeapon(std::shared_ptr<Ship> owner);
    virtual ~RocketWeapon();

    virtual void CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction) override;
    virtual WeaponType GetWeaponType() const override { return WeaponType::Rocket; }
};

}
