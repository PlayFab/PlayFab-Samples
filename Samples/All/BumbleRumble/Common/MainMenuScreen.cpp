//--------------------------------------------------------------------------------------
// MainMenuScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "MainMenuScreen.h"
#include "GameLobbyScreen.h"
#include "OptionsPopUpScreen.h"
#include "Managers.h"
#include "WelcomeScreen.h"
#include "Game.h"

using namespace BumbleRumble;
using namespace DirectX;

MainMenuScreen::MainMenuScreen() : MenuScreen()
{
    m_transitionOnTime = 1.0;
    m_transitionOffTime = 1.0;

    m_menuEntries.clear();

    m_menuEntries.push_back(MenuEntry("Join a game",
        []()
        {
            Managers::Get<NetworkManager>()->Initialize();
            Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<GameLobbyScreen>());
        }));

    m_menuEntries.push_back(MenuEntry("Options",
        []()
        {
            Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<OptionsPopUpScreen>());
        }));

    Managers::Get<AudioManager>()->PlaySoundTrack(false);
}

MainMenuScreen::~MainMenuScreen()
{
}

void MainMenuScreen::HandleInput()
{
    MenuScreen::HandleInput();
}

void MainMenuScreen::Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen)
{
    MenuScreen::Update(totalTime, elapsedTime, otherScreenHasFocus, coveredByOtherScreen);
}

void MainMenuScreen::Draw(float totalTime, float elapsedTime)
{
    if (IsActive())
    {
        MenuScreen::Draw(totalTime, elapsedTime);
    }
}

void MainMenuScreen::OnCancel()
{
    Managers::Get<ScreenManager>()->ExitAllScreens();
    Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<WelcomeScreen>());
}
