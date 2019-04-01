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
    std::shared_ptr<DX::Texture> m_title;
    std::shared_ptr<DX::Texture> m_background;
    DirectX::SimpleMath::Vector2 m_centerpoint;
    int m_xdir;
    int m_ydir;
};

}
