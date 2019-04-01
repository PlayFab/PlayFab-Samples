//--------------------------------------------------------------------------------------
// StarfieldScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameScreen.h"

namespace BumbleRumble
{

class Starfield;

class StarfieldScreen : public GameScreen
{
public:
    StarfieldScreen();
    virtual ~StarfieldScreen();

    virtual void LoadContent() override;
    virtual void UnloadContent() override;
    virtual void Reset() override;
    virtual void Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen) override;
    virtual void Draw(float totalTime, float elapsedTime) override;

    const float starsParallaxPeriod = 30.0f;
    const float starsParallaxAmplitude = 2048.0f;

private:
    std::unique_ptr<Starfield> m_starfield;
    std::shared_ptr<DX::Texture> m_title;
    float m_movement;
};

}
