//--------------------------------------------------------------------------------------
// STTOverlayScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//�Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Managers.h"
#include "ScreenManager.h"
#include "STTOverlayScreen.h"
#include "Game.h"
#include "PlayerState.h"

using namespace BumbleRumble;
using namespace DirectX;

STTOverlayScreen::STTOverlayScreen() : GameScreen()
{
    m_exitWhenHidden = false;
}

STTOverlayScreen::~STTOverlayScreen()
{
}

void STTOverlayScreen::Draw(float totalTime, float elapsedTime)
{
    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext(BlendMode::NonPremultiplied);
    auto spriteFont = Managers::Get<ContentManager>()->LoadFont("Assets\\Fonts\\SegoeUI_64.spritefont");
    float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);
    float scale = 0.45f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    renderContext->Begin();

    if (m_currentLines.size() > 0)
    {
        auto count = 0;

        for (const auto& lineItem : m_currentLines)
        {
            auto line = lineItem.sender + ": " + lineItem.message;

            if (lineItem.fragment)
            {
                line += " ...";
            }

            auto lineWidth = spriteFont->MeasureString(line.c_str());
            auto lineTop = (viewportHeight * c_STTBoxTop) + (count * (XMVectorGetY(lineWidth) * scale));
            auto chatTextureScale = scale * spriteFont->GetLineSpacing() / m_textIcon->Height();
            auto chatTextureOrigin = XMFLOAT2((float)m_textIcon->Width(), (float)m_textIcon->Height() / 2.0f);
            auto chatTexturePosition = XMFLOAT2((c_STTBoxLeft * viewportWidth) - ((m_textIcon->Width() / 2) * scale), lineTop);

            renderContext->Draw(
                lineItem.transcribed ? m_voiceIcon : m_textIcon,
                chatTexturePosition,
                0.0f,
                chatTextureScale,
                Colors::White,
                TexturePosition::Centered
                );

            renderContext->DrawString(
                spriteFont,
                line.c_str(),
                XMFLOAT2(c_STTBoxLeft * viewportWidth, lineTop),
                Colors::Yellow,
                0,
                XMFLOAT2(0.0f, spriteFont->GetLineSpacing() / 2.0f),
                scale
                );

            count++;

            if (count >= c_MaxLinesToShow)
            {
                break;
            }
        }
    }

    renderContext->End();

    GameScreen::Draw(totalTime, elapsedTime);
}

void STTOverlayScreen::Update(float, float elapsedTime, bool, bool)
{
    std::vector<STTLineItem> ttsLines;
    auto count = 0;

    // Process current lines
    for (auto line : m_currentLines)
    {
        count++;

        // Update the timers of visible lines
        if (count < c_MaxLinesToShow)
        {
            line.timeout += elapsedTime;
        }

        // Only keep items that haven't timed out
        if (line.timeout < c_TextDisplayTimeout)
        {
            ttsLines.push_back(line);
        }
    }

    // Get any new lines or updates
    for (auto& pline : m_pendingLines)
    {
        bool modified = false;

        for (auto& cline : ttsLines)
        {
            if (pline.sender == cline.sender && cline.fragment)
            {
                cline.message = pline.message;
                cline.fragment = pline.fragment;
                cline.timeout = 0;

                modified = true;
            }
        }

        if (!modified)
        {
            ttsLines.push_back(pline);
        }
    }

    m_pendingLines.clear();
    m_currentLines = ttsLines;
}

void STTOverlayScreen::AddSTTString(std::string sender, std::string message, bool transcribed, bool fragment)
{
    if (m_textIcon == nullptr)
    {
        m_textIcon = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\Text.png");
        m_voiceIcon = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\Mic.png");
    }

    m_pendingLines.push_back(STTLineItem(sender, message, transcribed, fragment));
}
