//--------------------------------------------------------------------------------------
// GamePlayScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "GamePlayScreen.h"
#include "Managers.h"
#include "PlayerState.h"
#include "Game.h"
#include "WelcomeScreen.h"
#include "StarfieldScreen.h"
#include "DebugOverlayScreen.h"

using namespace BumbleRumble;
using namespace DirectX;

GamePlayScreen::GamePlayScreen() : 
    GameScreen()
{
    m_updatesSinceShipDataSent = 0;
    m_playerFont = Managers::Get<ContentManager>()->LoadFont("Assets\\Fonts\\NetRumble.spritefont");
}

GamePlayScreen::~GamePlayScreen()
{
}

void GamePlayScreen::HandleInput()
{
    auto stateManager = Managers::Get<GameStateManager>();
    auto inputManager = Managers::Get<InputManager>();

    if (Managers::Get<GameStateManager>()->IsGameWon())
    {
        if (inputManager->IsNewButtonPress(InputManager::GamepadButtons::A))
        {
            Managers::Get<GameStateManager>()->ResetGame(std::string());
            return;
        }
    }

    auto localShip = stateManager->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId())->GetShip();
    if (localShip->Active() && !stateManager->IsGameWon())
    {
        localShip->Input = ShipInput(inputManager->CurrentGamePadState);
    }
    else
    {
        localShip->Input = ShipInput();
    }

    Managers::Get<NetworkManager>()->SendGameMessage(
        GameNetworkMessage(
            GameMessageType::ShipInput,
            localShip->Input.Serialize()
            )
        );

    GameScreen::HandleInput();
}

void GamePlayScreen::Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen)
{
    Managers::Get<GameStateManager>()->UpdateWorld(totalTime, elapsedTime);

    // update other players with the local ship data, if it's time
    if (m_updatesSinceShipDataSent >= 8)
    {
        Managers::Get<NetworkManager>()->SendGameMessage(
            GameNetworkMessage(
                GameMessageType::ShipData,
                Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId())->GetShip()->Serialize()
                )
            );

        m_updatesSinceShipDataSent = 0;
    }
    else
    {
        m_updatesSinceShipDataSent++;
    }

    GameScreen::Update(totalTime, elapsedTime, otherScreenHasFocus, coveredByOtherScreen);
}

void GamePlayScreen::Draw(float totalTime, float elapsedTime)
{
    UNREFERENCED_PARAMETER(totalTime);

    Managers::Get<GameStateManager>()->DrawWorld(elapsedTime);
    DrawHud();
}

void GamePlayScreen::DrawHud()
{
    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext();
    float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);
    XMFLOAT2 fontOrigin = XMFLOAT2(0, m_playerFont->GetLineSpacing() / 2.0f);
    float playerNameScale = 1.7f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);
    float messageScale = 2.25f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    renderContext->Begin();

    auto playerStates = Managers::Get<GameStateManager>()->GetAllPlayerStates();
    auto playerIds = std::vector<uint16_t>();
    auto count = playerStates.size();

    XMFLOAT2 memberPositions[] =
    {
        XMFLOAT2(viewportWidth * 0.05f, viewportHeight * 0.06f),
        XMFLOAT2(viewportWidth * 0.28f, viewportHeight * 0.06f),
        XMFLOAT2(viewportWidth * 0.51f, viewportHeight * 0.06f),
        XMFLOAT2(viewportWidth * 0.74f, viewportHeight * 0.06f)
    };

    // draw players 0 - 3 at the top of the screen
    for (uint32_t i = 0; i < std::min<size_t>(static_cast<size_t>(4), count); ++i)
    {
        auto playerState = playerStates[i];
        if (playerState)
        {
            auto memberName = playerState->DisplayName;
            auto memberColor = (playerState->InGame) ? Ship::Colors[playerState->ShipColor()] : Colors::LightGray;

            renderContext->DrawString(m_playerFont, memberName.c_str(), memberPositions[i], memberColor, 0, fontOrigin, playerNameScale);

            // draw score and respawn counter centered underneath each name
            auto ship = playerState->GetShip();
            std::string memberData = std::to_string(ship->Score);
            if (!ship->Active() && ship->RespawnTimer > 0.0f)
            {
                memberData += "  (" + std::to_string(1 + static_cast<int>(ship->RespawnTimer)) + ")";
            }
            auto memberNameLen = playerNameScale * m_playerFont->MeasureString(memberName.c_str());
            XMFLOAT2 scorePosition = XMFLOAT2(memberPositions[i].x + (XMVectorGetX(memberNameLen) / 2.0f), memberPositions[i].y + (playerNameScale * m_playerFont->GetLineSpacing()));
            renderContext->DrawString(m_playerFont, memberData.c_str(), scorePosition, memberColor, 0, fontOrigin, playerNameScale);
        }
    }

    // draw players 4 - 7 at the bottom of the screen
    for (uint32_t i = 4; i < std::min<size_t>(static_cast<size_t>(8), count); ++i)
    {
        memberPositions[i % 4].y = viewportHeight * 0.9f;

        auto playerState = playerStates[i];
        if (playerState)
        {
            auto memberName = playerState->DisplayName;
            auto memberColor = (playerState->InGame) ? Ship::Colors[playerState->ShipColor()] : Colors::LightGray;

            renderContext->DrawString(m_playerFont, memberName.c_str(), memberPositions[i % 4], memberColor, 0, fontOrigin, playerNameScale);

            // draw score and respawn counter centered underneath each name
            auto ship = playerState->GetShip();
            std::string memberData = std::to_string(ship->Score);
            if (!ship->Active() && ship->RespawnTimer > 0.0f)
            {
                memberData += "  (" + std::to_string(1 + static_cast<int>(ship->RespawnTimer)) + ")";
            }
            auto memberNameLen = playerNameScale * m_playerFont->MeasureString(memberName.c_str());
            XMFLOAT2 scorePosition = XMFLOAT2(memberPositions[i % 4].x + (XMVectorGetX(memberNameLen) / 2.0f), memberPositions[i % 4].y + (playerNameScale * m_playerFont->GetLineSpacing()));
            renderContext->DrawString(m_playerFont, memberData.c_str(), scorePosition, memberColor, 0, fontOrigin, playerNameScale);
        }
    }

    // draw a spawn countdown text message for the local user when appropriate
    auto localShip = Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId())->GetShip();
    if (!Managers::Get<GameStateManager>()->IsGameWon() && !localShip->Active() && localShip->RespawnTimer > 0.0f)
    {
        std::string respawnMessage = "Spawning in " + std::to_string(1 + static_cast<int>(localShip->RespawnTimer));
        auto respawnMessageLen = m_playerFont->MeasureString(respawnMessage.c_str());
        XMFLOAT2 respawnMessagePosition = XMFLOAT2(viewportWidth / 2.0f, viewportHeight / 2.0f);
        XMFLOAT2 respawnMessageOrigin = XMFLOAT2(XMVectorGetX(respawnMessageLen) / 2.0f, 0.0f);
        renderContext->DrawString(m_playerFont, respawnMessage.c_str(), respawnMessagePosition, Colors::White, 0.0f, respawnMessageOrigin, messageScale);
    }

    // if round has been won, draw win message
    if (Managers::Get<GameStateManager>()->IsGameWon())
    {
        auto winMessageLine1 = Managers::Get<GameStateManager>()->GetWinnerName() + " has won the game!";
#ifdef _XBOX_ONE
        auto winMessageLine2 = "Press (A) to return to the lobby";
#else
        auto winMessageLine2 = "Press (A) or Enter to return to the lobby";
#endif
        XMFLOAT2 winMessagePosition = XMFLOAT2(viewportWidth / 2.0f, viewportHeight * 0.4f);

        auto winMessageLen = m_playerFont->MeasureString(winMessageLine1.c_str());
        auto winMessageOrigin = XMFLOAT2(XMVectorGetX(winMessageLen) / 2.0f, m_playerFont->GetLineSpacing());
        renderContext->DrawString(m_playerFont, winMessageLine1.c_str(), winMessagePosition, Managers::Get<GameStateManager>()->GetWinningColor(), 0.0f, winMessageOrigin, playerNameScale);

        winMessageLen = m_playerFont->MeasureString(winMessageLine2);
        winMessageOrigin = XMFLOAT2(XMVectorGetX(winMessageLen) / 2.0f, 0.0f);
        renderContext->DrawString(m_playerFont, winMessageLine2, winMessagePosition, Managers::Get<GameStateManager>()->GetWinningColor(), 0.0f, winMessageOrigin, playerNameScale);
    }

    renderContext->End();
}

