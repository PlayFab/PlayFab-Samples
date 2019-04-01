//--------------------------------------------------------------------------------------
// MineProjectile.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Projectile.h"

namespace BumbleRumble
{

class MineProjectile : public Projectile
{
public:
    MineProjectile(std::shared_ptr<Ship> owner, DirectX::SimpleMath::Vector2 direction);
    virtual ~MineProjectile();

    virtual void Update(float elapsedTime) override;
    virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext) override;
    virtual bool TakeDamage(std::shared_ptr<GameplayObject> source, float damageAmount) override;
    virtual void Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly) override;

private:
    bool m_anchored;
    std::shared_ptr<DX::Texture> m_texture;
};

}
