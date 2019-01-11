//--------------------------------------------------------------------------------------
// ScreenManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "Game.h"
#include "Manager.h"
#include "Managers.h"
#include "GameScreen.h"
#include "ErrorScreen.h"

using namespace ThunderRumble;
using namespace DirectX;

ScreenManager::ScreenManager() :
    m_screenStackCleared(false),
    m_backgroundsVisible(true),
    m_foregroundsVisible(false)
{
}


ScreenManager::~ScreenManager()
{
}

void ScreenManager::CreateWindowSizeDependentResources()
{
    for (auto& screen : m_backgroundScreens)
    {
        screen->Reset();
    }

    for (auto& screen : m_gameScreens)
    {
        screen->Reset();
    }

    for (auto& screen : m_foregroundScreens)
    {
        screen->Reset();
    }

#ifndef _XBOX_ONE
    //    m_spriteBatch->SetRotation(m_deviceResources->ComputeDisplayRotation());
#endif
}

void ScreenManager::ExitAllScreens()
{
    while (!m_gameScreens.empty())
    {
        auto screen = m_gameScreens.back();
        screen->ExitScreen(true);
    }
    m_screenStackCleared = true;
}

void ScreenManager::AddGameScreen(const std::shared_ptr<GameScreen>& screen)
{
    std::lock_guard<std::mutex> lock(m_screenLock);

    screen->m_isExiting = false;

    if (!screen->IsPopup() && m_gameScreens.size() > 0)
    {
        // insert the new screen underneath any existing popup screens
        ScreensIterator it = m_gameScreens.begin();
        for (; it != m_gameScreens.end(); ++it)
        {
            if ((*it)->IsPopup())
                break;
        }
        m_gameScreens.insert(it, screen);
    }
    else
    {
        // otherwise just tack on the new screen at the end (top) of the list
        m_gameScreens.push_back(screen);
    }

    // Allow the screen to load content now that it's being added to the screen manager
    screen->LoadContent();
}

void ScreenManager::RemoveScreen(const std::shared_ptr<GameScreen>& screen)
{
    // Shell out to our private helper since it's going to do the same thing
    RemoveScreen(screen.get());
}

std::shared_ptr<GameScreen> ThunderRumble::ScreenManager::GetCurrentGameScreen()
{
    if (!m_gameScreens.empty())
    {
        return m_gameScreens[0];
    }

    return nullptr;
}

void ThunderRumble::ScreenManager::ShowError(const std::wstring & message, std::function<void(void)> andthen)
{
    AddGameScreen(std::static_pointer_cast<GameScreen>(std::make_shared<ErrorScreen>(message, andthen)));
}

void ScreenManager::AddBackgroundScreen(const std::shared_ptr<GameScreen>& screen)
{
    std::lock_guard<std::mutex> lock(m_screenLock);

    screen->m_isExiting = false;
    screen->m_state = ScreenStateType::Active;

    m_backgroundScreens.push_back(screen);

    // Allow the screen to load content now that it's being added to the screen manager
    screen->LoadContent();
}

void ScreenManager::AddForegroundScreen(const std::shared_ptr<GameScreen>& screen)
{
    std::lock_guard<std::mutex> lock(m_screenLock);

    screen->m_isExiting = false;
    screen->m_state = ScreenStateType::Active;

    m_foregroundScreens.push_back(screen);

    // Allow the screen to load content now that it's being added to the screen manager
    screen->LoadContent();
}

void ScreenManager::Update(DX::StepTimer const& timer)
{
    float totalTime = float(timer.GetTotalSeconds());
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: review
    //if (Game->InputManager->IsNewButtonPress(GamepadButtons::View, -1) || Game->InputManager->IsNewKeyPress(Keyboard::Keys::OemTilde))
    //{
    //    isDebugOverlayOn = !isDebugOverlayOn;
    //}

    // Make a copy of the master screen list, to avoid confusion if the process of updating one screen adds or removes others
    std::vector<std::shared_ptr<GameScreen>> gameScreensToUpdate;
    std::vector<std::shared_ptr<GameScreen>> backgroundsToUpdate;
    std::vector<std::shared_ptr<GameScreen>> foregroundsToUpdate;
    {
        std::lock_guard<std::mutex> lock(m_screenLock);
        gameScreensToUpdate = m_gameScreens;
        backgroundsToUpdate = m_backgroundScreens;
        foregroundsToUpdate = m_foregroundScreens;
    }

    bool otherScreenHasFocus = false;
    bool coveredByOtherScreen = false;

    m_screenStackCleared = false;

    // Draw backgrounds first
    if (m_backgroundsVisible)
    {
        for (ReverseScreensIterator itr = backgroundsToUpdate.rbegin(); itr != backgroundsToUpdate.rend(); itr++)
        {
            (*itr)->Update(totalTime, elapsedTime, otherScreenHasFocus, coveredByOtherScreen);
        }
    }

    // Iterate the screens in reverse order so the last screen added is considered the top of the "stack"
    for (ReverseScreensIterator itr = gameScreensToUpdate.rbegin(); itr != gameScreensToUpdate.rend(); itr++)
    {
        std::shared_ptr<GameScreen> screen = (*itr);

        // Update the screen
        screen->Update(totalTime, elapsedTime, otherScreenHasFocus, coveredByOtherScreen);

        if (screen->m_state == ScreenStateType::TransitionOn || screen->m_state == ScreenStateType::Active)
        {
            // If this is the first active screen we came across, give it a chance to handle input
            if (!otherScreenHasFocus)
            {
                screen->HandleInput();
                otherScreenHasFocus = true;
            }

            // If this is an active non-popup, inform any subsequent screens that they are covered by it
            if (!screen->m_isPopup)
            {
                coveredByOtherScreen = true;
            }
        }

        if (m_screenStackCleared)
        {
            // ExitAllScreens() was called by the current screen so don't process any more screens
            break;
        }
    }

    // Draw foregrounds last
    if (m_foregroundsVisible)
    {
        for (ReverseScreensIterator itr = foregroundsToUpdate.rbegin(); itr != foregroundsToUpdate.rend(); itr++)
        {
            (*itr)->Update(totalTime, elapsedTime, otherScreenHasFocus, coveredByOtherScreen);
        }
    }
}

void ScreenManager::Suspend()
{
    ExitAllScreens();
}

void ScreenManager::Resume()
{
}

void ScreenManager::Render(DX::StepTimer const& timer)
{
    float totalTime = float(timer.GetTotalSeconds());
    float elapsedTime = float(timer.GetElapsedSeconds());

    // Make a copy of the master screen list so we can loop through and draw the screens even if another thread alters the collection during the draw
    std::vector<std::shared_ptr<GameScreen>> gameScreensToRender;
    std::vector<std::shared_ptr<GameScreen>> backgroundsToRender;
    std::vector<std::shared_ptr<GameScreen>> foregroundsToRender;
    {
        std::lock_guard<std::mutex> lock(m_screenLock);
        gameScreensToRender = m_gameScreens;
        backgroundsToRender = m_backgroundScreens;
        foregroundsToRender = m_foregroundScreens;
    }

    if (m_backgroundsVisible)
    {
        for (auto& screen : backgroundsToRender)
        {
            screen->Draw(totalTime, elapsedTime);
        }
    }

    for (auto& screen : gameScreensToRender)
    {
        if (screen->m_state != ScreenStateType::Hidden)
        {
            screen->Draw(totalTime, elapsedTime);
        }
    }

    if (m_foregroundsVisible)
    {
        for (auto& screen : foregroundsToRender)
        {
            screen->Draw(totalTime, elapsedTime);
        }
    }
}

void ScreenManager::RemoveScreen(GameScreen* screen)
{
    std::lock_guard<std::mutex> lock(m_screenLock);

    for (ScreensIterator itr = m_gameScreens.begin(); itr != m_gameScreens.end(); ++itr)
    {
        if ((*itr).get() == screen)
        {
            screen->UnloadContent();
            m_gameScreens.erase(itr);
            return;
        }
    }

    for (ScreensIterator itr = m_backgroundScreens.begin(); itr != m_backgroundScreens.end(); ++itr)
    {
        if ((*itr).get() == screen)
        {
            screen->UnloadContent();
            m_backgroundScreens.erase(itr);
            return;
        }
    }

    for (ScreensIterator itr = m_foregroundScreens.begin(); itr != m_foregroundScreens.end(); ++itr)
    {
        if ((*itr).get() == screen)
        {
            screen->UnloadContent();
            m_foregroundScreens.erase(itr);
            return;
        }
    }
}
