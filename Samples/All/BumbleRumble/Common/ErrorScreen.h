//--------------------------------------------------------------------------------------
// ErrorScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameScreen.h"

namespace BumbleRumble
{

class ErrorScreen : public GameScreen
{
public:
    ErrorScreen(const std::string& message, std::function<void(void)> callback = nullptr);
    virtual ~ErrorScreen();

    virtual void HandleInput() override;
    virtual void Draw(float totalTime, float elapsedTime) override;
    virtual void ExitScreen(bool immediate = false) override;

private:
    std::string m_message;
    std::function<void(void)> m_callback;
};

}
