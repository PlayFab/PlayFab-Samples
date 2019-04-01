//--------------------------------------------------------------------------------------
// OptionsPopUpScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "MenuScreen.h"
#include "GameStateManager.h"

namespace BumbleRumble
{
    class OptionsPopUpScreen : public MenuScreen
    {
    public:
        OptionsPopUpScreen();
        virtual ~OptionsPopUpScreen();

        virtual void HandleInput() override;
        virtual void Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen) override;
        virtual void Draw(float totalTime, float elapsedTime) override;
        virtual void LoadContent() override;

    protected:
        virtual void OnCancel() override;
        virtual void ComputeMenuBounds(float viewportWidth, float viewportHeight) override;

    private:
        std::shared_ptr<DX::Texture> m_backgroundTexture;
        int m_currentIndex;
    };
}
