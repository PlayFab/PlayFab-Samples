//--------------------------------------------------------------------------------------
// WelcomeScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "WelcomeScreen.h"
#include "MainMenuScreen.h"
#include "Managers.h"
#include "Game.h"

using namespace BumbleRumble;
using namespace DirectX;

WelcomeScreen::WelcomeScreen() : MenuScreen()
{
    m_exitWhenHidden = false;
    m_transitionOnTime = 1.0;
    m_transitionOffTime = 1.0;

    m_menuEntries.clear();
    
    m_menuEntries.push_back(MenuEntry("Play Now",
        [this]()
        {
            m_menuEntries.clear();
            m_menuEntries.push_back(MenuEntry("Signing Into PlayFab"));

            Managers::Get<PlayFabManager>()->SignIn(
                [this](bool success, std::string& message)
                {
                    if (success)
                    {
                        Managers::Get<NetworkManager>()->Initialize();
                        Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<MainMenuScreen>());
                    }
                    else
                    {
                        m_menuEntries.push_back(MenuEntry(message));
                    }
                });
        }));

    Managers::Get<AudioManager>()->PlaySoundTrack(true);

#if defined(_XBOX_ONE) && defined(_TITLE)
    if (!TheGame->LiveResources()->IsUserSignedIn())
    {
        concurrency::create_task(
            Windows::Xbox::UI::SystemUI::ShowAccountPickerAsync(
                nullptr,
                Windows::Xbox::UI::AccountPickerOptions::None
            )
        ).then([](concurrency::task<Windows::Xbox::UI::AccountPickerResult^> t)
        {
            try
            {
                Windows::Xbox::UI::AccountPickerResult^ result = t.get();

                if (result->User == nullptr)
                {
                    // User canceled the dialog
                    return;
                }

                Managers::Get<GameStateManager>()->SetLocalPlayerName(BumbleRumble::WStrToStr(result->User->DisplayInfo->GameDisplayName->Data()));
            }
            catch (Platform::Exception^ ex)
            {
                DEBUGLOG("Could not select a user. ShowAccountPickerAsync threw error: %hs\n", BumbleRumble::WStrToStr(ex->Message->Data()).c_str());
            }
            catch (concurrency::task_canceled&)
            {
                DEBUGLOG("ShowAccountPickerAsync canceled\n");
            }
        });
    }
    else
    {
        Managers::Get<GameStateManager>()->SetLocalPlayerName(BumbleRumble::WStrToStr(TheGame->LiveResources()->GetUser()->DisplayInfo->GameDisplayName->Data()));
    }
#else
    char szMachineName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(szMachineName) / sizeof(szMachineName[0]);
    GetComputerNameA(szMachineName, &size);

    Managers::Get<GameStateManager>()->SetLocalPlayerName(szMachineName);
#endif
}

WelcomeScreen::~WelcomeScreen()
{
}

void WelcomeScreen::HandleInput()
{
    MenuScreen::HandleInput();
}

void WelcomeScreen::Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen)
{
    MenuScreen::Update(totalTime, elapsedTime, otherScreenHasFocus, coveredByOtherScreen);
}

void WelcomeScreen::Draw(float totalTime, float elapsedTime)
{
    if (IsActive())
    {
        MenuScreen::Draw(totalTime, elapsedTime);
    }
}

void WelcomeScreen::OnCancel()
{
    Managers::Get<ScreenManager>()->ExitAllScreens();
    Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<WelcomeScreen>());
}
