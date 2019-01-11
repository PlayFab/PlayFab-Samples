//--------------------------------------------------------------------------------------
// DebugOverlayScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Managers.h"
#include "ScreenManager.h"
#include "DebugOverlayScreen.h"
#include "Game.h"
#include "PlayerState.h"

using namespace ThunderRumble;
using namespace DirectX;

DebugOverlayScreen::DebugOverlayScreen() : GameScreen()
{
    m_exitWhenHidden = false;
}

DebugOverlayScreen::~DebugOverlayScreen()
{
}

const float c_UserInfoLeft = 50.0f;
const float c_UserInfoTop = 50.0f;
const float c_UserInfoHeight = 25.0f;

void DebugOverlayScreen::Draw(float totalTime, float elapsedTime)
{
    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext(BlendMode::NonPremultiplied);
    auto spriteFont = Managers::Get<ContentManager>()->LoadFont(L"Assets\\Fonts\\SegoeUI_64.spritefont");
    auto viewportWidth = static_cast<float>(TheGame->GetWindowWidth());
    float viewportHeight = static_cast<float>(TheGame->GetWindowHeight());
    float scale = 0.25f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    renderContext->Begin();

    // Draw a status line for each player
    auto playerStates = Managers::Get<GameStateManager>()->GetAllPlayerStates();
    if (playerStates.size() > 0)
    {
        auto count = 0;

        for (const auto& playerState : playerStates)
        {
            if (playerState != nullptr)
            {
                std::wstring textLine = playerState->DisplayName.empty() ? L"[NONAMEYET]" : playerState->DisplayName;
                textLine += L"(";
                textLine += std::to_wstring(playerState->PeerId);
                textLine += L"): ";
                textLine += playerState->InGame ? L"InGame " : L"";
                textLine += playerState->IsLocalPlayer ? L"Local " : L"";
                textLine += playerState->LobbyReady ? L"LR " : L"";
                textLine += playerState->IsInactive() ? L"Inactive " : L"Active ";

                auto ship = playerState->GetShip();
                if (ship)
                {
                    std::wstring shipLine = L"Pos: ";
                    shipLine += std::to_wstring(ship->Position.x);
                    shipLine += L", ";
                    shipLine += std::to_wstring(ship->Position.y);
                    shipLine += L"  Vel: ";
                    shipLine += std::to_wstring(ship->Velocity.x);
                    shipLine += L", ";
                    shipLine += std::to_wstring(ship->Velocity.y);
                    shipLine += L" LS: ";
                    shipLine += std::to_wstring(ship->Input.LeftStick.x);
                    shipLine += L", ";
                    shipLine += std::to_wstring(ship->Input.LeftStick.y);
                    shipLine += L" RS: ";
                    shipLine += std::to_wstring(ship->Input.RightStick.x);
                    shipLine += L", ";
                    shipLine += std::to_wstring(ship->Input.RightStick.y);
                    textLine += L"    " + shipLine;
                }

                auto lineWidth = spriteFont->MeasureString(textLine.c_str());

                renderContext->DrawString(
                    spriteFont,
                    textLine.c_str(),
                    XMFLOAT2(c_UserInfoLeft, c_UserInfoTop + (count * (XMVectorGetY(lineWidth) * scale))),
                    Colors::Yellow,
                    0,
                    XMFLOAT2(0.0f, spriteFont->GetLineSpacing() / 2.0f),
                    scale
                );

                count++;
            }
        }
    }

    renderContext->End();

    GameScreen::Draw(totalTime, elapsedTime);
}