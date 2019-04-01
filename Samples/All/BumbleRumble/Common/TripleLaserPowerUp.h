//--------------------------------------------------------------------------------------
// TripleLaserPowerUp.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "PowerUp.h"

namespace BumbleRumble
{

class TripleLaserPowerUp : public PowerUp
{
public:
    TripleLaserPowerUp();
    virtual ~TripleLaserPowerUp();

    virtual bool OnTouch(std::shared_ptr<GameplayObject> target) override;
    virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext) override;
    virtual PowerUpType GetPowerUpType() const override { return PowerUpType::TripleLaser; }

private:
    std::shared_ptr<DX::Texture> m_powerUpTexture;
};

}
