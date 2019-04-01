//--------------------------------------------------------------------------------------
// DebugOverlayScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Managers.h"
#include "ScreenManager.h"
#include "DebugOverlayScreen.h"
#include "Game.h"
#include "PlayerState.h"

using namespace BumbleRumble;
using namespace DirectX;

DebugOverlayScreen::DebugOverlayScreen() : GameScreen()
{
    m_exitWhenHidden = false;
}

DebugOverlayScreen::~DebugOverlayScreen()
{
}

void DebugOverlayScreen::Draw(float totalTime, float elapsedTime)
{
    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext(BlendMode::NonPremultiplied);
    auto spriteFont = Managers::Get<ContentManager>()->LoadFont("Assets\\Fonts\\SegoeUI_64.spritefont");
    float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);
    float scale = 0.25f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    renderContext->Begin();

    if (Managers::Get<GameStateManager>()->GetGodMode())
    {
        renderContext->DrawString(
            spriteFont,
            "God Mode Enabled",
            XMFLOAT2(c_UserInfoLeft, c_UserInfoTop - 30.0f),
            Colors::Red,
            0,
            XMFLOAT2(0.0f, spriteFont->GetLineSpacing() / 2.0f),
            scale
            );
    }

    // Draw a status line for each player
    auto playerStates = Managers::Get<GameStateManager>()->GetAllPlayerStates();
    if (playerStates.size() > 0)
    {
        auto count = 0;

        for (const auto& playerState : playerStates)
        {
            if (playerState != nullptr)
            {
                std::string textLine = playerState->DisplayName.empty() ? "[NONAMEYET]" : playerState->DisplayName;
                textLine += "(";
                textLine += playerState->PeerId;
                textLine += "): ";
                textLine += playerState->InGame ? "InGame " : "";
                textLine += playerState->IsLocalPlayer ? "Local " : "";
                textLine += playerState->LobbyReady ? "LR " : "";
                textLine += playerState->IsInactive() ? "Inactive " : "Active ";

                auto ship = playerState->GetShip();
                if (ship)
                {
                    std::string shipLine = "Pos: ";
                    shipLine += std::to_string(ship->Position.x);
                    shipLine += ", ";
                    shipLine += std::to_string(ship->Position.y);
                    shipLine += "  Vel: ";
                    shipLine += std::to_string(ship->Velocity.x);
                    shipLine += ", ";
                    shipLine += std::to_string(ship->Velocity.y);
                    shipLine += " LS: ";
                    shipLine += std::to_string(ship->Input.LeftStick.x);
                    shipLine += ", ";
                    shipLine += std::to_string(ship->Input.LeftStick.y);
                    shipLine += " RS: ";
                    shipLine += std::to_string(ship->Input.RightStick.x);
                    shipLine += ", ";
                    shipLine += std::to_string(ship->Input.RightStick.y);
                    textLine += "    " + shipLine;
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