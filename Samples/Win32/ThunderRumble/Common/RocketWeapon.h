//--------------------------------------------------------------------------------------
// RocketWeapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Weapon.h"

namespace ThunderRumble
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
