//--------------------------------------------------------------------------------------
// LaserWeapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Weapon.h"

namespace ThunderRumble
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
