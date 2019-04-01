//--------------------------------------------------------------------------------------
// InputBoxScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameScreen.h"

namespace BumbleRumble
{

class InputBoxScreen : public GameScreen
{
public:
    InputBoxScreen();
    virtual ~InputBoxScreen();

    virtual void Draw(float totalTime, float elapsedTime) override;
    virtual void HandleInput() override;

private:
    std::string CharacterFromKey(DirectX::Keyboard::Keys key, bool shifted);

    std::string m_inputString;
    std::shared_ptr<DX::Texture> m_background;
    DirectX::Keyboard::KeyboardStateTracker m_keyboardState;
};

}
