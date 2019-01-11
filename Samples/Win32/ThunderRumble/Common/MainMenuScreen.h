//--------------------------------------------------------------------------------------
// MainMenuScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "MenuScreen.h"

namespace ThunderRumble
{

    class MainMenuScreen : public MenuScreen
    {
    public:
        MainMenuScreen();
        virtual ~MainMenuScreen();

        virtual void Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen) override;
        virtual void HandleInput() override;
        virtual void Draw(float totalTime, float elapsedTime) override;

    protected:
        virtual void OnCancel() override;
    };

}
