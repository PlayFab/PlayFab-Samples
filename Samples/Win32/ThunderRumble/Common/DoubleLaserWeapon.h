//--------------------------------------------------------------------------------------
// DoubleLaserWeapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "LaserWeapon.h"

namespace ThunderRumble
{

    class DoubleLaserWeapon : public LaserWeapon
    {
    public:
        DoubleLaserWeapon(std::shared_ptr<Ship> owner);
        virtual ~DoubleLaserWeapon();

        virtual void CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction) override;
        virtual WeaponType GetWeaponType() const override { return WeaponType::DoubleLaser; }

        // The distance that the laser bolts are moved off of the owner's position.
        const float laserSpread = 8.0f;
    };

}
