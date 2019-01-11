//--------------------------------------------------------------------------------------
// DebugOverlayScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameScreen.h"

namespace ThunderRumble
{

    class DebugOverlayScreen : public GameScreen
    {
    public:
        DebugOverlayScreen();
        virtual ~DebugOverlayScreen();

        virtual void Draw(float totalTime, float elapsedTime) override;

    private:
    };

}
