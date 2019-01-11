//--------------------------------------------------------------------------------------
// WelcomeScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "WelcomeScreen.h"
#include "MainMenuScreen.h"
#include "Managers.h"
#include "Game.h"
#include "GameServiceManagerTypes.h"


#include <playfab/PlayFabClientApi.h>
#include <playfab/PlayFabClientDataModels.h>
#include <playfab/PlayFabSettings.h>

#include <playfab\QoS\PlayFabQoSApi.h>

using namespace ThunderRumble;
using namespace DirectX;

WelcomeScreen::WelcomeScreen() : MenuScreen()
{
    m_exitWhenHidden = false;
    m_transitionOnTime = 1.0;
    m_transitionOffTime = 1.0;

    m_menuEntries.clear();

    m_menuEntries.push_back(MenuEntry(L"Play Now",
        [this]()
    {
        m_menuEntries.clear();
        m_menuEntries.push_back(MenuEntry(L"Signing Into PlayFab"));

        Managers::Get<PlayFabManager>()->SignIn(
            [this](bool success, std::wstring& message)
        {
            if (success)
            {
                m_menuEntries.clear();
                m_menuEntries.push_back(MenuEntry(L"Logging into Services..."));
                std::shared_ptr<PlayFabManager> playfabMgr = Managers::Get<PlayFabManager>();

                Managers::Get<GameServiceManager>()->RegisterPlayer(playfabMgr->GetLoginResult().SessionTicket).then([=](Concurrency::task<bool> task)
                {
                    if (task.get())
                    {
                        Managers::Get<GameServiceManager>()->GetAvailableRegions().then([=](Concurrency::task<GetAvailableRegionsResponse> task)
                        {
                            const GetAvailableRegionsResponse& resp = task.get();

                            if (resp.m_vecRegions.size() > 0)
                            {
                                m_menuEntries.clear();
                                m_menuEntries.push_back(MenuEntry(L"Performing QoS"));

                                PlayFab::QoS::PlayFabQoSApi qosAPI;

                                auto result = qosAPI.GetQoSResult(5, 200);
                                if (result.lastErrorCode == 0)
                                {
                                    std::vector<PlayFab::QoS::DataCenterResult> r(move(result.dataCenterResults));

                                    // determine smallest
                                    bool bFoundRegion = false;
                                    PlayFab::MultiplayerModels::AzureRegion regionToUse = PlayFab::MultiplayerModels::AzureRegionAustraliaEast;
                                    int smallestLatency = INT_MAX;
                                    for (int i = 0; i < r.size(); ++i)
                                    {
                                        int thisLatency = r[i].latencyMs;
                                        if (thisLatency <= smallestLatency)
                                        {
                                            regionToUse = r[i].region;
                                            smallestLatency = thisLatency;
                                            bFoundRegion = true;
                                        }
                                    }

                                    if (bFoundRegion)
                                    {
                                        Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<MainMenuScreen>());
                                        Managers::Get<GameServiceManager>()->SetPreferredRegion(regionToUse);
                                    }
                                    else
                                    {
                                        m_menuEntries.clear();
                                        m_menuEntries.push_back(MenuEntry(L"Nearby data centers are offline"));
                                    }
                                }
                                else
                                {
                                    m_menuEntries.clear();
                                    m_menuEntries.push_back(MenuEntry(L"Nearby data centers are offline"));
                                }
                            }
                            else
                            {
                                m_menuEntries.clear();
                                m_menuEntries.push_back(MenuEntry(L"Failed to get regions"));
                            }
                        });
                    }
                    else
                    {
                        m_menuEntries.clear();
                        m_menuEntries.push_back(MenuEntry(L"Game Services are Offline"));
                    }
                });
            }
            else
            {
                m_menuEntries.push_back(MenuEntry(message));
            }
        });
    }));

    //m_menuEntries.push_back(MenuEntry(L"Sign in with PlayFab",
    //    []()
    //    {
    //    }));

    Managers::Get<AudioManager>()->PlaySoundTrack(true);
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

    auto viewportWidth = static_cast<float>(TheGame->GetWindowWidth());
    auto viewportHeight = static_cast<float>(TheGame->GetWindowHeight());
    auto scale = GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    auto renderContext = Managers::Get<RenderManager>()->GetRenderContext(BlendMode::NonPremultiplied);
    auto font = Managers::Get<ContentManager>()->LoadFont(L"Assets\\Fonts\\SegoeUI_64.spritefont");

    renderContext->Begin();

    auto displayName = Managers::Get<GameStateManager>()->GetLocalPlayerName();
    auto userNameWidth = XMVectorGetX(font->MeasureString(displayName.c_str()));
    auto position = SimpleMath::Vector2(viewportWidth - 100 * scale, viewportHeight - 100 * scale);
    auto origin = SimpleMath::Vector2(userNameWidth, font->GetLineSpacing() / 2.0f);

    renderContext->DrawString(
        font,
        displayName.c_str(),
        position,
        Colors::White,
        0,
        origin,
        scale * 0.35f
    );

    renderContext->End();
}

void WelcomeScreen::OnCancel()
{
    ExitScreen();
}
