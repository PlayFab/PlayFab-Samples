//--------------------------------------------------------------------------------------
// MainMenuScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "MainMenuScreen.h"
#include "GameLobbyScreen.h"
#include "Managers.h"
#include "Game.h"

using namespace ThunderRumble;
using namespace DirectX;

MainMenuScreen::MainMenuScreen() : MenuScreen()
{
    m_transitionOnTime = 1.0;
    m_transitionOffTime = 1.0;

    m_menuEntries.clear();

    m_menuEntries.push_back(MenuEntry(L"Join a game",
        []()
    {
        Managers::Get<PlayFabManager>()->BeginMultiplayer(
            [](bool success, std::wstring& message)
        {
            if (success)
            {
                Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<GameLobbyScreen>());
            }
            else
            {
                message;
            }
        });
    }));

    m_menuEntries.push_back(MenuEntry(L"Options",
        []()
    {
    }));
    m_menuEntries[1].m_active = false;

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
    ExitScreen();
}
