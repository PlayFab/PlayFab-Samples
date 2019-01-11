//--------------------------------------------------------------------------------------
// InputManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "InputManager.h"

using namespace ThunderRumble;
using namespace DirectX;

#ifdef _XBOX_ONE
using namespace Windows::Xbox::Input;
#elseif defined(WINAPI_FAMILY) && (WINAPI_FAMILY != WINAPI_FAMILY_DESKTOP_APP)
using namespace Windows::Gaming::Input;
#endif

InputManager::InputManager()
{
    gamePad.reset(new GamePad);
    m_keyboard.reset(new Keyboard);
    m_keyboardStateTracker.reset(new Keyboard::KeyboardStateTracker);

    LastGamePadState = CurrentGamePadState = GamePad::State();
}

void InputManager::Suspend()
{
    gamePad->Suspend();
}

void InputManager::Resume()
{
    gamePad->Resume();
    m_buttonStateTracker.Reset();
    m_keyboardStateTracker->Reset();
}

#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY != WINAPI_FAMILY_DESKTOP_APP)
void InputManager::SetWindow(Windows::UI::Core::CoreWindow ^ window)
{
#ifndef _XBOX_ONE
    m_keyboard->SetWindow(window);
#endif
}
#else
void InputManager::ProcessMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_keyboard)
    {
        m_keyboard->ProcessMessage(message, wParam, lParam);
    }
}
#endif

void InputManager::Update()
{
    LastGamePadState = CurrentGamePadState;
    CurrentGamePadState = gamePad->GetState(0);

    if (CurrentGamePadState.IsConnected())
    {
        m_buttonStateTracker.Update(CurrentGamePadState);
    }

    auto keyboardState = m_keyboard->GetState();
    m_keyboardStateTracker->Update(keyboardState);
}

bool InputManager::IsNewButtonPress(GamepadButtons button)
{
    // Read input from the specified player
    if (GetButtonState(button) == GamePad::ButtonStateTracker::ButtonState::PRESSED)
    {
        return true;
    }

    return false;
}

GamePad::ButtonStateTracker::ButtonState InputManager::GetButtonState(GamepadButtons button)
{
    switch (button)
    {
    case GamepadButtons::None:
        return GamePad::ButtonStateTracker::ButtonState::UP;
    case GamepadButtons::DPadUp:
        return m_buttonStateTracker.dpadUp;
    case GamepadButtons::DPadDown:
        return m_buttonStateTracker.dpadDown;
    case GamepadButtons::DPadLeft:
        return m_buttonStateTracker.dpadLeft;
    case GamepadButtons::DPadRight:
        return m_buttonStateTracker.dpadRight;
    case GamepadButtons::View:
        return m_buttonStateTracker.back;
    case GamepadButtons::Menu:
        return m_buttonStateTracker.start;
    case GamepadButtons::LeftThumbstick:
        return m_buttonStateTracker.leftStick;
    case GamepadButtons::RightThumbstick:
        return m_buttonStateTracker.rightStick;
    case GamepadButtons::LeftShoulder:
        return m_buttonStateTracker.leftShoulder;
    case GamepadButtons::RightShoulder:
        return m_buttonStateTracker.rightShoulder;
    case GamepadButtons::A:
        return m_buttonStateTracker.a;
    case GamepadButtons::B:
        return m_buttonStateTracker.b;
    case GamepadButtons::X:
        return m_buttonStateTracker.x;
    case GamepadButtons::Y:
        return m_buttonStateTracker.y;
    default:
        return GamePad::ButtonStateTracker::ButtonState::UP;
    }
}

bool InputManager::IsNewKeyPress(DirectX::Keyboard::Keys key)
{
    return m_keyboardStateTracker->IsKeyPressed(key);
}

bool InputManager::IsMenuSelect()
{
    if (IsNewButtonPress(GamepadButtons::A))
    {
        return true;
    }

    return m_keyboardStateTracker->pressed.Enter;
}

bool InputManager::IsMenuCancel()
{
    if (IsNewButtonPress(GamepadButtons::B))
    {
        return true;
    }

    return m_keyboardStateTracker->pressed.Escape || m_keyboardStateTracker->pressed.Back;
}

bool InputManager::IsMenuUp()
{
    bool newLeftThumbstickUp = false;

    newLeftThumbstickUp = CurrentGamePadState.IsLeftThumbStickUp() && !LastGamePadState.IsLeftThumbStickUp();

    if (newLeftThumbstickUp || IsNewButtonPress(GamepadButtons::DPadUp))
    {
        return true;
    }

    return m_keyboardStateTracker->pressed.Up;
}

bool InputManager::IsMenuDown()
{
    bool newLeftThumbstickDown = false;

    newLeftThumbstickDown = CurrentGamePadState.IsLeftThumbStickDown() && !LastGamePadState.IsLeftThumbStickDown();

    if (newLeftThumbstickDown || IsNewButtonPress(GamepadButtons::DPadDown))
    {
        return true;
    }

    return m_keyboardStateTracker->pressed.Down;
}

bool InputManager::IsMenuLeft()
{
    bool newLeftThumbstickLeft = false;

    newLeftThumbstickLeft = CurrentGamePadState.IsLeftThumbStickLeft() && !LastGamePadState.IsLeftThumbStickLeft();

    if (newLeftThumbstickLeft || IsNewButtonPress(GamepadButtons::DPadLeft))
    {
        return true;
    }

    return m_keyboardStateTracker->pressed.Left;
}

bool InputManager::IsMenuRight()
{
    bool newLeftThumbstickRight = false;

    newLeftThumbstickRight = CurrentGamePadState.IsLeftThumbStickRight() && !LastGamePadState.IsLeftThumbStickRight();

    if (newLeftThumbstickRight || IsNewButtonPress(GamepadButtons::DPadRight))
    {
        return true;
    }

    return m_keyboardStateTracker->pressed.Right;
}

bool InputManager::IsMenuToggle()
{
    return IsNewButtonPress(GamepadButtons::Menu) || m_keyboardStateTracker->pressed.Tab;
}

#ifdef _XBOX_ONE
IGamepad^ InputManager::GetGamepad(int index)
{
    if (index < -1 || index >= MaxInputs)
        return nullptr;

    uint64_t gamepadId = 0;
    if (index == -1)
    {
        for (int i = 0; i < MaxInputs; ++i)
        {
            gamepadId = gamePad->GetCapabilities(i).id;
            if (gamepadId > 0)
                break;
        }
    }
    else
    {
        gamepadId = gamePad->GetCapabilities(index).id;
    }

    if (gamepadId == 0)
        return nullptr;

    for (const auto& gamepad : Gamepad::Gamepads)
    {
        if (gamepad->Id == gamepadId)
            return gamepad;
    }

    return nullptr;
}

int InputManager::GetGamepadIndex(IGamepad^ gamepad) const
{
    uint64_t controllerId = gamepad->Id;

    for (int i = 0; i < MaxInputs; ++i)
    {
        if (gamePad->GetCapabilities(i).id == controllerId)
            return i;
    }

    return -1;
}
#endif
