//--------------------------------------------------------------------------------------
// ErrorScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "GameScreen.h"

namespace ThunderRumble
{

    class ErrorScreen : public GameScreen
    {
    public:
        ErrorScreen(const std::wstring& message, std::function<void(void)> callback = nullptr);
        virtual ~ErrorScreen();

        virtual void HandleInput() override;
        virtual void Draw(float totalTime, float elapsedTime) override;
        virtual void ExitScreen(bool immediate = false) override;

    private:
        std::wstring _message;
        std::function<void(void)> _callback;
    };

}
