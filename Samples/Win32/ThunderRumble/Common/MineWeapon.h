//--------------------------------------------------------------------------------------
// MineWeapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Weapon.h"

namespace ThunderRumble
{

    class MineWeapon : public Weapon
    {
    public:
        MineWeapon(std::shared_ptr<Ship> owner);
        virtual ~MineWeapon();

        // The distance that the mine spawns behind the ship.
        const float mineSpawnDistance = 8.0f;

        virtual void CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction) override;
        virtual WeaponType GetWeaponType() const override { return WeaponType::Mine; }
    };

}
