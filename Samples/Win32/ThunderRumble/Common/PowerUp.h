//--------------------------------------------------------------------------------------
// PowerUp.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameplayObject.h"

namespace ThunderRumble
{

    enum class PowerUpType
    {
        Unknown,
        DoubleLaser,
        TripleLaser,
        Rocket
    };

    class PowerUp abstract : public GameplayObject
    {
    public:
        PowerUp();
        virtual ~PowerUp();

        virtual void Initialize() override;
        virtual bool OnTouch(std::shared_ptr<GameplayObject> target) override;
        virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext, const TextureHandle &sprite, DirectX::XMVECTOR color) override;
        virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext) = 0;

        virtual GameplayObjectType GetType() const override { return GameplayObjectType::PowerUp; }
        virtual PowerUpType GetPowerUpType() const { return PowerUpType::Unknown; }

        static PowerUpType ChooseNextPowerUpType();

    protected:
        // speed of the rotation of the power-up, in radians/sec
        float rotationSpeed;

        // amplitude of the power-up pulsation
        float pulseAmplitude;

        // rate of pulsation
        float pulseRate;

    private:
        float pulseTimer;
    };

}
