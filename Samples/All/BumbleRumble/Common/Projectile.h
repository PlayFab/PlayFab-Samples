//--------------------------------------------------------------------------------------
// Projectile.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameplayObject.h"

namespace BumbleRumble
{

class Ship;

class Projectile abstract : public GameplayObject
{
public:
    Projectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction);
    virtual ~Projectile();

    virtual void Update(float elapsedTime) override;
    virtual bool OnTouch(std::shared_ptr<GameplayObject> target) override;
    virtual void Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly) override;

    virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext) = 0;

    virtual GameplayObjectType GetType() const override { return GameplayObjectType::Projectile; }
    inline std::shared_ptr<Ship> GetOwner() const { return m_owner; }

protected:
    std::shared_ptr<Ship> m_owner;
    float m_damageAmount;
    float m_damageRadius;
    bool m_damageOwner;
    float m_duration;
};

}
