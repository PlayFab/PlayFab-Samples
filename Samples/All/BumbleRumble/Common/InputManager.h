//--------------------------------------------------------------------------------------
// InputManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"

namespace BumbleRumble
{

enum class GameAction
{
    GA_BACK,
    GA_PAUSE
};

// Contains all game input in one central location and exposes helper functions for working with the input
class InputManager : public Manager
{
public:
    static const int MaxInputs = DirectX::GamePad::MAX_PLAYER_COUNT;

    InputManager();

    // Handle PLM and window events
    void Suspend();
    void Resume();

    // Updates the current state of the input
    void Update();

    // Define the Gamepad enum for Win32
    enum GamepadButtons : unsigned int
    {
        None = 0,
        Menu = 0x4,
        View = 0x8,
        A = 0x10,
        B = 0x20,
        X = 0x40,
        Y = 0x80,
        DPadUp = 0x100,
        DPadDown = 0x200,
        DPadLeft = 0x400,
        DPadRight = 0x800,
        LeftShoulder = 0x1000,
        RightShoulder = 0x2000,
        LeftThumbstick = 0x4000,
        RightThumbstick = 0x8000,
        Paddle1 = 0x10000,
        Paddle2 = 0x20000,
        Paddle3 = 0x40000,
        Paddle4 = 0x80000,
    };

    bool IsNewButtonPress(GamepadButtons button);
    DirectX::GamePad::ButtonStateTracker::ButtonState GetButtonState(GamepadButtons button);
    bool IsNewKeyPress(DirectX::Keyboard::Keys key);

#if !defined(_XBOX_ONE)
    void ProcessMessage(UINT message, WPARAM wParam, LPARAM lParam);
#endif

    // Helper functions for standard game functions that call into IsNewButtonPress with various standard inputs
    bool IsMenuSelect();
    bool IsMenuCancel();
    bool IsMenuUp();
    bool IsMenuDown();
    bool IsMenuLeft();
    bool IsMenuRight();
    bool IsMenuToggle();

    // The current state of all the game pads
    DirectX::GamePad::State CurrentGamePadState;

    // The previous state of all the game pads
    DirectX::GamePad::State LastGamePadState;

    DirectX::Keyboard::State CurrentKeyboardState() { return m_keyboard->GetState(); }

private:
    std::unique_ptr<DirectX::GamePad> m_gamePad;
    std::unique_ptr<DirectX::Keyboard> m_keyboard;
    DirectX::GamePad::ButtonStateTracker m_buttonStateTracker;
    std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> m_keyboardStateTracker;
};

}
