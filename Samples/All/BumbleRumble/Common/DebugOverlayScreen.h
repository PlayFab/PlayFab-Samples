//--------------------------------------------------------------------------------------
// DebugOverlayScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameScreen.h"

namespace BumbleRumble
{

class DebugOverlayScreen : public GameScreen
{
public:
    DebugOverlayScreen();
    virtual ~DebugOverlayScreen();

    virtual void Draw(float totalTime, float elapsedTime) override;

    const float c_UserInfoLeft = 50.0f;
    const float c_UserInfoTop = 50.0f;
    const float c_UserInfoHeight = 25.0f;
};

}
