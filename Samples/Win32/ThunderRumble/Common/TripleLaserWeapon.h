//--------------------------------------------------------------------------------------
// TripleLaserWeapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "LaserWeapon.h"

namespace ThunderRumble
{

    class TripleLaserWeapon : public LaserWeapon
    {
    public:
        TripleLaserWeapon(std::shared_ptr<Ship> owner);
        virtual ~TripleLaserWeapon();

        virtual void CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction) override;
        virtual WeaponType GetWeaponType() const override { return WeaponType::TripleLaser; }

        // The spread of the second and third laser projectiles' directions, in radians
        const float laserSpreadRadians = DirectX::XMConvertToRadians(2.5f);
    };

}
