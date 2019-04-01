//--------------------------------------------------------------------------------------
// GamePlayScreen.h
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

class GamePlayScreen : public GameScreen
{
public:
    GamePlayScreen();
    virtual ~GamePlayScreen();

    virtual void Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen) override;
    virtual void HandleInput() override;
    virtual void Draw(float totalTime, float elapsedTime) override;

private:
    void DrawHud();

    std::shared_ptr<DirectX::SpriteFont> m_playerFont;
    DirectX::Keyboard::State m_lastKeyboardState;
    int m_updatesSinceShipDataSent;
};

}
