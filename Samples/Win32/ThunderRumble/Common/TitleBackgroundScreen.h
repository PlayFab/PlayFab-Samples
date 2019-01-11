//--------------------------------------------------------------------------------------
// StarfieldScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameScreen.h"

namespace ThunderRumble
{

    class TitleBackgroundScreen : public GameScreen
    {
    public:
        TitleBackgroundScreen();
        virtual ~TitleBackgroundScreen();

        virtual void LoadContent() override;
        virtual void UnloadContent() override;
        virtual void Reset() override;
        virtual void Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen) override;
        virtual void Draw(float totalTime, float elapsedTime) override;

    private:
        TextureHandle m_title;
        TextureHandle m_background;
        DirectX::SimpleMath::Vector2 m_centerpoint;
        int m_xdir;
        int m_ydir;
    };

}
