//--------------------------------------------------------------------------------------
// GameScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "Managers.h"
#include "GameScreen.h"

using namespace ThunderRumble;
using namespace DirectX;

GameScreen::GameScreen() :
    m_exitWhenHidden(true),
    m_isPopup(false),
    m_transitionOnTime(0.0f),
    m_transitionOffTime(0.0f),
    m_transitionPosition(1.0f),
    m_state(ScreenStateType::TransitionOn),
    m_isExiting(false),
    m_otherScreenHasFocus(false),
    m_controllingPlayer(-1)
{
}

GameScreen::~GameScreen()
{
}

void GameScreen::LoadContent()
{
    // Nothing for the base class to load
}

void GameScreen::UnloadContent()
{
    // Nothing for the base class to unload
}

void GameScreen::Reset()
{
    // Nothing for the base class to reset
}

void GameScreen::Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen)
{
    UNREFERENCED_PARAMETER(totalTime);

    m_otherScreenHasFocus = otherScreenHasFocus;

    if (m_isExiting)
    {
        m_state = ScreenStateType::TransitionOff;
        if (!UpdateTransition(elapsedTime, m_transitionOffTime, 1))
        {
            // When the transition finishes, remove the screen.
            Managers::Get<ScreenManager>()->RemoveScreen(this);
        }
    }
    else if (coveredByOtherScreen)
    {
        // If the screen is covered by another, it should transition off.
        if (UpdateTransition(elapsedTime, m_transitionOffTime, 1))
        {
            // Still busy transitioning.
            m_state = ScreenStateType::TransitionOff;
        }
        else
        {
            // Transition finished!
            m_state = ScreenStateType::Hidden;
            if (m_exitWhenHidden)
            {
                Managers::Get<ScreenManager>()->RemoveScreen(this);
            }
        }
    }
    else
    {
        // Otherwise the screen should transition on and become active.
        if (UpdateTransition(elapsedTime, m_transitionOnTime, -1))
        {
            // Still busy transitioning.
            m_state = ScreenStateType::TransitionOn;
        }
        else
        {
            // Transition finished!
            m_state = ScreenStateType::Active;
        }
    }
}

void GameScreen::HandleInput()
{
    // Nothing for the base class to handle
    auto inputManager = Managers::Get<InputManager>();

    if (inputManager->IsNewKeyPress(DirectX::Keyboard::OemTilde))
    {
        Managers::Get<ScreenManager>()->SetForegroundsVisible(!Managers::Get<ScreenManager>()->GetForegroundsVisible());
    }
}

void GameScreen::Draw(float, float)
{
    // Nothing for the base class to draw
}

void GameScreen::ExitScreen(bool immediate)
{
    if (immediate || m_transitionOffTime == 0.0f)
    {
        // If the screen has a zero transition time, remove it immediately.
        Managers::Get<ScreenManager>()->RemoveScreen(this);
    }
    else
    {
        // Otherwise flag that it should transition off and then exit.
        m_isExiting = true;
    }
}

bool GameScreen::UpdateTransition(float elapsedTime, float time, int direction)
{
    // How much should we move by?
    float transitionDelta = 0.0f;

    if (time == 0.0f)
    {
        transitionDelta = 1;
    }
    else
    {
        transitionDelta = elapsedTime / time;
    }

    // Update the transition position.
    m_transitionPosition += transitionDelta * direction;

    // Did we reach the end of the transition?
    if (((direction < 0) && (m_transitionPosition <= 0)) ||
        ((direction > 0) && (m_transitionPosition >= 1)))
    {
        m_transitionPosition = std::min(std::max(m_transitionPosition, 0.0f), 1.0f);
        return false;
    }

    // Otherwise we are still busy transitioning.
    return true;
}