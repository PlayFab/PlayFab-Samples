//--------------------------------------------------------------------------------------
// ErrorScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "ErrorScreen.h"
#include "MainMenuScreen.h"
#include "Managers.h"
#include "Game.h"
#include "ErrorScreen.h"

using namespace BumbleRumble;
using namespace DirectX;

ErrorScreen::ErrorScreen(const std::string& message, std::function<void(void)> callback) :
    GameScreen(),
    m_message(message),
    m_callback(callback)
{
    m_isPopup = true;
}

ErrorScreen::~ErrorScreen()
{
}

void ErrorScreen::HandleInput()
{
    if (Managers::Get<InputManager>()->IsMenuSelect())
    {
        ExitScreen(true);
    }
}

void ErrorScreen::Draw(float totalTime, float elapsedTime)
{
    UNREFERENCED_PARAMETER(totalTime);
    UNREFERENCED_PARAMETER(elapsedTime);

    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext();
    auto contentManager = Managers::Get<ContentManager>();
    auto spriteFont = contentManager->LoadFont("Assets\\Fonts\\SegoeUI_64.spritefont");
    float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);

    // calculate position and size of error message
    SimpleMath::Vector2 errorMsgPosition = SimpleMath::Vector2(0, viewportHeight / 2.0f);
    XMVECTORF32 errorMsgColor = Colors::Yellow;
    float scale = 0.5f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);
    SimpleMath::Vector2 origin = SimpleMath::Vector2(0, spriteFont->GetLineSpacing() / 2.0f);
    XMVECTOR size = spriteFont->MeasureString(m_message.c_str());
    errorMsgPosition.x = viewportWidth / 2.0f - XMVectorGetX(size) / 2.0f * scale;

    // create a rectangle representing the screen dimensions of the error message background rectangle
    long rectangleWidth = long(std::min(std::max((XMVectorGetX(size) * scale) + 100.0f, 600.0f), viewportWidth));
    long rectangleHeight = long(spriteFont->GetLineSpacing() * scale * 6.0f);
    long rectangleLeft = long(viewportWidth / 2.0f) - (rectangleWidth / 2);
    long rectangleTop = long(errorMsgPosition.y + spriteFont->GetLineSpacing() * scale) - (rectangleHeight / 2);
    RECT backgroundRectangle = { rectangleLeft, rectangleTop, rectangleLeft + rectangleWidth, rectangleTop + rectangleHeight };

    renderContext->Begin();

    // draw a background color for the rectangle
    renderContext->Draw(contentManager->LoadTexture("Assets\\Textures\\blank.png"), backgroundRectangle, Colors::DarkSlateGray);

    // draw error message in the middle of the screen
    renderContext->DrawString(spriteFont, m_message.c_str(), errorMsgPosition, errorMsgColor, 0, origin, scale);

    // draw continuation prompt
    errorMsgPosition.y += spriteFont->GetLineSpacing() * scale;
    size = spriteFont->MeasureString("Press (A) to Continue");
    errorMsgPosition.x = viewportWidth / 2.0f - XMVectorGetX(size) / 2.0f * scale;
    renderContext->DrawString(spriteFont, "Press (A) to Continue", errorMsgPosition, Colors::Yellow, 0, origin, scale);

    renderContext->End();
}

void ErrorScreen::ExitScreen(bool immediate)
{
    GameScreen::ExitScreen(immediate);

    if (m_callback)
    {
        m_callback();
    }
}
