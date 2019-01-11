//--------------------------------------------------------------------------------------
// DoubleLaserPowerUp.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "PowerUp.h"

namespace ThunderRumble
{

    class DoubleLaserPowerUp : public PowerUp
    {
    public:
        DoubleLaserPowerUp();
        virtual ~DoubleLaserPowerUp();

        virtual bool OnTouch(std::shared_ptr<GameplayObject> target) override;
        virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext) override;
        virtual PowerUpType GetPowerUpType() const override { return PowerUpType::DoubleLaser; }

    private:
        TextureHandle _powerUpTexture;
    };

}
