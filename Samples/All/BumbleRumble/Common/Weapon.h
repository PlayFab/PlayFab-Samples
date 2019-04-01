//--------------------------------------------------------------------------------------
// Weapon.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

namespace BumbleRumble
{

class Ship;

enum class WeaponType
{
    Unknown,
    Laser,
    DoubleLaser,
    TripleLaser,
    Rocket,
    Mine
};

class Weapon abstract
{
public:
    Weapon(std::shared_ptr<Ship> owner);
    virtual ~Weapon();

    virtual void Update(float elapsedTime);
    virtual void Fire(const DirectX::SimpleMath::Vector2 &direction);
    virtual void CreateProjectiles(const DirectX::SimpleMath::Vector2 &direction) = 0;
    virtual WeaponType GetWeaponType() const { return WeaponType::Unknown; }

protected:
    std::shared_ptr<Ship> m_owner;
    float m_timeToNextFire;
    float m_fireDelay;

    std::string m_fireSoundEffect;
};

}
