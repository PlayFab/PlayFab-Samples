//--------------------------------------------------------------------------------------
// Asteroid.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameplayObject.h"

namespace BumbleRumble
{

class Asteroid : public GameplayObject
{
public:
    Asteroid(float radius, int variation);
    ~Asteroid();

    virtual void Update(float elapsedTime) override;
    void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext);
    virtual bool OnTouch(std::shared_ptr<GameplayObject> target) override;

    virtual GameplayObjectType GetType() const override { return GameplayObjectType::Asteroid; }

    int Variation;

    static const int Variations = 3;

    // The ratio of the mass of an asteroid to its radius.
    const float c_massRadiusRatio = 0.5f;

    // The ratio of the mass of an asteroid to its radius.
    const float c_lifeRadiusRatio = 10.0f;

    // The amount of drag applied to velocity per second, 
    // as a percentage of velocity.
    const float c_dragPerSecond = 0.15f;

    // Scalar to convert the velocity / mass ratio into a "nice" rotational value.
    const float c_velocityMassRatioToRotationScalar = 0.0017f;

    // Scalar for calculated damage values that asteroids apply to players.
    const float c_momentumToDamageScalar = 0.007f;

    // The minimum possible initial speed for asteroids.
    const float c_initialSpeedMinimum = 32.0f;

    // The minimum possible initial speed for asteroids.
    const float c_initialSpeedMaximum = 96.0f;

    // The minimum speed for drag to have any effect.
    const float c_minSpeedFromDrag = 25.0f;

private:
    std::shared_ptr<DX::Texture> m_texture;
};

}
