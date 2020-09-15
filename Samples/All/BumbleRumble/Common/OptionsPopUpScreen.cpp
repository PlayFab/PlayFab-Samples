//--------------------------------------------------------------------------------------
// OptionsPopUpScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "OptionsPopUpScreen.h"
#include "Managers.h"
#include "Game.h"

using namespace BumbleRumble;
using namespace DirectX;

static XMVECTORF32 s_backgroundColor = { 0.4f, 0.5f, 0.5f, 0.2f };

// Supported languages:
// https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/language-support

static const char* s_languageCodes[] = 
{
    "ar-EG", "ca-ES", "da-DK", "de-DE", "en-AU", "en-CA", "en-GB",
    "en-IN", "en-NZ", "en-US", "es-ES", "es-MX", "fi-FI", "fr-CA",
    "fr-FR", "hi-IN", "it-IT", "ja-JP", "ko-KR", "nb-NO", "nl-NL",
    "pl-PL", "pt-BR", "pt-PT", "ru-RU", "sv-SE", "zh-CN", "zh-HK",
    "zh-TW", "th-TH"
};

static const int s_numberOfLanguages = ARRAYSIZE(s_languageCodes);

static const char* s_languageNames[s_numberOfLanguages] =
{
    "Arabic (Egypt)", "Catalan (Spain)", "Danish (Denmark)", "German (Germany)",
    "English (Australia)", "English (Canada)", "English (United Kingdom)",
    "English (India)", "English (New Zealand)", "English (United States)",
    "Spanish (Spain)", "Spanish (Mexico)", "Finnish (Finland)", "French (Canada)",
    "French (France)", "Hindi (India)", "Italian (Italy)", "Japanese (Japan)",
    "Korean (Korea)", "Norwegian (Norway)", "Dutch (Netherlands)",
    "Polish (Poland)", "Portuguese (Brazil)", "Portuguese (Portugal)",
    "Russian (Russia)", "Swedish (Sweden)", "Chinese (Mandarin, simplified)",
    "Chinese (Mandarin, Traditional)", "Chinese (Taiwanese Mandarin)", "Thai (Thailand)"
};

enum MenuIndex
{
    LANGUAGE_CODE,
	COGNITIVE_SERVICES
};

OptionsPopUpScreen::OptionsPopUpScreen() : MenuScreen()
{
    m_transitionOnTime = 1.0f;
    m_transitionOffTime = 1.0f;
    m_currentIndex = 9;

    m_menuEntries.clear();

    std::string value;

    value = s_languageCodes[m_currentIndex];
    value += " - ";
    value += s_languageNames[m_currentIndex];

    m_menuEntries.push_back(MenuEntry("User language code:", nullptr,
        [this](bool adjustLeft)
        {
            if (adjustLeft)
            {
                m_currentIndex--;

                if (m_currentIndex < 0)
                {
                    m_currentIndex = s_numberOfLanguages - 1;
                }
            }
            else
            {
                m_currentIndex++;

                if (m_currentIndex >= s_numberOfLanguages)
                {
                    m_currentIndex = 0;
                }
            }

            std::string value;

            value = s_languageCodes[m_currentIndex];
            value += " - ";
            value += s_languageNames[m_currentIndex];

            m_menuEntries[MenuIndex::LANGUAGE_CODE].m_value = value;

            Managers::Get<NetworkManager>()->SetLanguageCode(
                s_languageCodes[m_currentIndex],
                s_languageNames[m_currentIndex]
                );
        },
        value));

    if (Managers::Get<NetworkManager>()->State() == NetworkManagerState::NetworkConnected)
    {
        value = Managers::Get<NetworkManager>()->IsCognitiveServicesEnabled() ? "Enabled" : "Disabled";
        m_menuEntries.push_back(MenuEntry("Cognitive Services:", nullptr,
            [this](bool adjustLeft)
            {
                adjustLeft;
                bool bNewValue = !Managers::Get<NetworkManager>()->IsCognitiveServicesEnabled();

                m_menuEntries[MenuIndex::COGNITIVE_SERVICES].m_value = bNewValue ? "Enabled" : "Disabled";

                Managers::Get<NetworkManager>()->SetCognitiveServicesEnabled(bNewValue);
            },
            value));
    }

    m_menuTextScale = 0.35f;
    SetTransitionDirections(false, false);
    ConfigureAsPopUpMenu();
    SetCenterJustified(true);
}

OptionsPopUpScreen::~OptionsPopUpScreen()
{
}

void OptionsPopUpScreen::HandleInput()
{
    MenuScreen::HandleInput();
}

void OptionsPopUpScreen::LoadContent()
{
    MenuScreen::LoadContent();

    auto screenManager = Manager();
    m_backgroundTexture = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\blank.png");
}

void OptionsPopUpScreen::Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen)
{
    GameScreen::Update(totalTime, elapsedTime, otherScreenHasFocus, coveredByOtherScreen);
}

void OptionsPopUpScreen::Draw(float totalTime, float elapsedTime)
{
    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext(BlendMode::NonPremultiplied);

    renderContext->Begin();

    // draw a background color for the rectangle
    RECT backgroundRectangle = { LONG(m_menuBounds.x), LONG(m_menuBounds.y), LONG(m_menuBounds.z), LONG(m_menuBounds.w) };
    auto backgroundColor = s_backgroundColor;
    backgroundColor.f[3] = s_backgroundColor.f[3] * TransitionAlpha();

    renderContext->Draw(m_backgroundTexture, backgroundRectangle, backgroundColor);

    float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);
    auto spriteFont = Managers::Get<ContentManager>()->LoadFont("Assets\\Fonts\\SegoeUI_64.spritefont");
    const char* message = "Select with arrow keys; Backspace to confirm";
    XMFLOAT2 position = XMFLOAT2(viewportWidth / 2.0f, viewportHeight * 0.9f);
    XMVECTOR size = spriteFont->MeasureString(message);
    XMFLOAT2 origin = XMFLOAT2(XMVectorGetX(size) / 2.0f, spriteFont->GetLineSpacing() / 2.0f);

    renderContext->DrawString(
        spriteFont,
        message,
        position,
        Colors::White,
        0,
        origin,
        0.5f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight)
        );

    renderContext->End();

    MenuScreen::Draw(totalTime, elapsedTime);
}

void OptionsPopUpScreen::OnCancel()
{
    ExitScreen();
}

void OptionsPopUpScreen::ComputeMenuBounds(float viewportWidth, float viewportHeight)
{
    float scale = GetScaleMultiplierForViewport(viewportWidth, viewportHeight);
    SetMenuOffset(250.0f * scale, 70.0f * scale);
    auto left = viewportWidth / 2 - (500.0f * scale);
    auto top = viewportHeight * 0.6f;
    m_menuBounds = XMFLOAT4(left, top, left + 1000.0f * scale, top + 200.0f * scale);
}
