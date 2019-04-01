//--------------------------------------------------------------------------------------
// TitleBackgroundScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Managers.h"
#include "ScreenManager.h"
#include "TitleBackgroundScreen.h"
#include "Game.h"

using namespace BumbleRumble;
using namespace DirectX;

TitleBackgroundScreen::TitleBackgroundScreen() : GameScreen(),
    m_centerpoint(DirectX::SimpleMath::Vector2(0.0f, 0.0f)),
    m_xdir(1),
    m_ydir(1)
{
    m_transitionPosition = 0.0f;
}

TitleBackgroundScreen::~TitleBackgroundScreen()
{
}

void TitleBackgroundScreen::LoadContent()
{
    m_title = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\titleCP.png");
    m_background = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\desertbackground.png");

    Reset();
}

void TitleBackgroundScreen::UnloadContent()
{
}

void TitleBackgroundScreen::Reset()
{
    auto renderManager = Managers::Get<RenderManager>();
    float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);

    m_centerpoint = SimpleMath::Vector2(viewportWidth / 2.0f, viewportHeight / 2.0f);
}

// Updates the background screen. Unlike most screens, this should not transition off even if it has been covered by another screen: it is
// supposed to be covered, after all! This overload forces the coveredByOtherScreen parameter to false in order to stop the base
// Update method wanting to transition off.
void TitleBackgroundScreen::Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen)
{
    UNREFERENCED_PARAMETER(coveredByOtherScreen);

    auto renderManager = Managers::Get<RenderManager>();
    float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);
    float scale = GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    if (m_xdir > 0)
    {
        m_centerpoint.x += (50 * elapsedTime);
    }
    else
    {
        m_centerpoint.x -= (50 * elapsedTime);
    }

    if (m_ydir > 0)
    {
        m_centerpoint.y += 50 * elapsedTime;
    }
    else
    {
        m_centerpoint.y -= 50 * elapsedTime;
    }

    float halfHeight = m_background->Height() * scale / 2.0f;
    float halfWidth = m_background->Width() * scale / 2.0f;

    if (m_centerpoint.x - halfWidth > 0.0f || m_centerpoint.x + halfWidth < viewportWidth)
    {
        m_xdir *= -1;
    }

    if (m_centerpoint.y - halfHeight > 0.0f || m_centerpoint.y + halfHeight < viewportHeight)
    {
        m_ydir *= -1;
    }

    GameScreen::Update(totalTime, elapsedTime, otherScreenHasFocus, false);
}

void TitleBackgroundScreen::Draw(float totalTime, float elapsedTime)
{
    UNREFERENCED_PARAMETER(totalTime);
    UNREFERENCED_PARAMETER(elapsedTime);

    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext(BlendMode::NonPremultiplied);

    float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);
    float scale = GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    SimpleMath::Vector2 titlePosition = SimpleMath::Vector2(viewportWidth / 2.0f, (viewportHeight / 2.0f) - (200.f * scale));
    titlePosition.y -= pow(TransitionPosition(), 2) * titlePosition.y;
    XMVECTORF32 color = { 1.0f, 1.0f, 1.f, TransitionAlpha() };

    renderContext->Begin();

    renderContext->Draw(
        m_background,
        m_centerpoint,
        0.0f,
        scale,
        color);
        
    renderContext->Draw(
        m_title,
        titlePosition,
        0.0f,
        scale,
        color);
        
    renderContext->End();
}