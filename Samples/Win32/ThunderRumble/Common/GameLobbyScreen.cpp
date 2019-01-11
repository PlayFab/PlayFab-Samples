//--------------------------------------------------------------------------------------
// GameLobbyScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "GameLobbyScreen.h"
#include "GamePlayScreen.h"
#include "Managers.h"
#include "PlayerState.h"
#include "Game.h"

using namespace ThunderRumble;
using namespace DirectX;

const wchar_t* lobbySessionInstructions = L"";
#ifdef _XBOX_ONE
const wchar_t* gameSessionInstructions = L"Press X to toggle ready, Y to open party app, LB/RB to change ship color/style, Menu for game options, Left Thumbstick for user list";
#else
const wchar_t* gameSessionInstructions = L"Gamepad: LB/RB to change ship color/style, Menu for game options, Left Thumbstick for user list";
const wchar_t* gameSessionInstructions2 = L"Keyboard: Left/Right to change ship color/style, Tab for game options, Shift+Tab for user list";
#endif

GameLobbyScreen::GameLobbyScreen() :
    MenuScreen(),
    _ready(false),
    _lastState(GameState::Initialize)
{
    m_transitionOnTime = 1.0;
    m_transitionOffTime = 1.0;

    Managers::Get<AudioManager>()->PlaySoundTrack(false);

    m_menuEntries.clear();
    m_menuEntries.push_back(MenuEntry(L"Matchmaking: Requesting Start"));
    m_TimeSinceLastMatchmakingPulse = 0.f;
    Managers::Get<GameStateManager>()->GotoMatchmaking();


    m_inGameTexture = Managers::Get<ContentManager>()->LoadTexture(L"Assets\\Textures\\Xbox_One_Controller_Front.png");
    m_readyTexture = Managers::Get<ContentManager>()->LoadTexture(L"Assets\\Textures\\ready.png");

    Managers::Get<PlayFabManager>()->UpdateStatistic(L"games_joined", 1);

    Managers::Get<ScreenManager>()->SetBackgroundsVisible(true);
}

GameLobbyScreen::~GameLobbyScreen()
{
}

void GameLobbyScreen::HandleInput()
{
    MenuScreen::HandleInput();

    auto inputManager = Managers::Get<InputManager>();
    auto localPlayerState = Managers::Get<GameStateManager>()->GetLocalPlayerState();

    if (inputManager->IsNewButtonPress(InputManager::GamepadButtons::LeftShoulder) || inputManager->IsNewKeyPress(Keyboard::Keys::Left))
    {
        // change ship color
        byte newColor = (localPlayerState->ShipColor() + 1) % Ship::Colors.size();
        //localPlayerState->ShipColor(newColor);

        // sync to service
        Managers::Get<GameServiceManager>()->SetShipColor(newColor);
    }
    else if (inputManager->IsNewButtonPress(InputManager::GamepadButtons::RightShoulder) || inputManager->IsNewKeyPress(Keyboard::Keys::Right))
    {
        // change ship design
        byte newShip = (localPlayerState->ShipVariation() + 1) % Ship::MaxVariations;
        // localPlayerState->ShipVariation(newShip);

         // sync to service
        Managers::Get<GameServiceManager>()->SetShipVariant(newShip);
    }
}

void GameLobbyScreen::Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen)
{
    auto state = Managers::Get<GameStateManager>()->GetState();

    m_menuEntries.clear();

    switch (state)
    {
    case GameState::Matchmaking:
    case GameState::Countdown:
        m_TimeSinceLastMatchmakingPulse += elapsedTime;

        if (state == GameState::Matchmaking)
        {
            m_menuEntries.push_back(MenuEntry(L"Matchmaking: Waiting for players..."));
        }
        else if (state == GameState::Countdown)
        {
            int countdown = Managers::Get<GameStateManager>()->GetTimeUntilMatchStart();
            std::wstring countdownMsg = L"Matchmaking: Proceeding to server allocation in ";
            countdownMsg += std::to_wstring(countdown);
            countdownMsg += L"  seconds (Lobby is still joinable)";
            m_menuEntries.push_back(MenuEntry(countdownMsg));

            // ready check
            if (_ready)
            {
                m_menuEntries.push_back(MenuEntry(L"Waiting for others to ready up..."));
            }
            else
            {
                m_menuEntries.push_back(MenuEntry(L"Ready up to proceed faster (Press A)",
                    [this]()
                {
                    _ready = true;
                    Managers::Get<GameServiceManager>()->SetReadyState(true);
                }));
            }
        }

        if (m_TimeSinceLastMatchmakingPulse >= timeBetweenMatchmakingPulses)
        {
            m_TimeSinceLastMatchmakingPulse = 0.f;
            Managers::Get<GameServiceManager>()->PulseMatchmaking();
        }
        break;

    case GameState::AllocatingServer:
    {
        m_menuEntries.push_back(MenuEntry(L"Allocating Server..."));
        break;
    }

    case GameState::ConnectingToServer:
        m_menuEntries.push_back(MenuEntry(L"Connecting to server..."));
        break;

    case GameState::WaitingToStart:
        m_TimeSinceLastMatchmakingPulse += elapsedTime;
        if (m_TimeSinceLastMatchmakingPulse >= timeBetweenMatchmakingPulses)
        {
            m_TimeSinceLastMatchmakingPulse = 0.f;
            Managers::Get<GameServiceManager>()->PulseMatchmaking();
        }

        m_menuEntries.push_back(MenuEntry(L"Waiting for more players..."));
        break;

    case GameState::Playing:
        if (_lastState != state)
        {
            Managers::Get<GameServiceManager>()->PulseMatchmaking();

            Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<NetworkManager>()->LocalPeerId())->InGame = true;

            // send our state
            Managers::Get<NetworkManager>()->SendGameMessage(
                GameNetworkMessage(
                    GameMessageType::PlayerInfo,
                    Managers::Get<NetworkManager>()->LocalPeerId(),
                    Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<NetworkManager>()->LocalPeerId())->DisplayName
                )
            );

            Managers::Get<NetworkManager>()->SendGameMessage(
                GameNetworkMessage(
                    GameMessageType::PlayerState,
                    Managers::Get<NetworkManager>()->LocalPeerId(),
                    Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<NetworkManager>()->LocalPeerId())->SerializePlayerStateData()
                )
            );

            Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<GamePlayScreen>());
            Managers::Get<ScreenManager>()->SetBackgroundsVisible(false);
        }
        break;
    }

    _lastState = state;

    MenuScreen::Update(totalTime, elapsedTime, otherScreenHasFocus, coveredByOtherScreen);
}

void GameLobbyScreen::Draw(float totalTime, float elapsedTime)
{
    if (!IsActive())
    {
        return;
    }

    if (State() == ScreenStateType::Active)
    {
        auto renderManager = Managers::Get<RenderManager>();
        auto renderContext = renderManager->GetRenderContext(BlendMode::NonPremultiplied);
        auto spriteFont = Managers::Get<ContentManager>()->LoadFont(L"Assets\\Fonts\\SegoeUI_64.spritefont");
        auto viewportWidth = static_cast<float>(TheGame->GetWindowWidth());
        float viewportHeight = static_cast<float>(TheGame->GetWindowHeight());
        float scale = 0.35f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

        renderContext->Begin();

        auto playerStates = Managers::Get<GameStateManager>()->GetAllPlayerStates();
        if (playerStates.size() > 0)
        {
            // draw session members centered
            XMFLOAT2 memberPositions[] =
            {
                XMFLOAT2(viewportWidth * 0.15f, viewportHeight * 0.7f),
                XMFLOAT2(viewportWidth * 0.38f, viewportHeight * 0.7f),
                XMFLOAT2(viewportWidth * 0.61f, viewportHeight * 0.7f),
                XMFLOAT2(viewportWidth * 0.84f, viewportHeight * 0.7f)
            };

            float inGameTextureScale = 0.9f * scale * spriteFont->GetLineSpacing() / m_inGameTexture.Texture->Height();
            XMFLOAT2 inGameTextureOrigin = XMFLOAT2((float)m_inGameTexture.Texture->Width(), (float)m_inGameTexture.Texture->Height() / 2.0f);

            float readyTextureScale = 0.9f * scale * spriteFont->GetLineSpacing() / m_readyTexture.Texture->Height();
            XMFLOAT2 readyTextureOrigin = XMFLOAT2((float)m_readyTexture.Texture->Width(), (float)m_readyTexture.Texture->Height() / 2.0f);

            UINT memberNumber = 0;
            for (const auto& playerState : playerStates)
            {
                if (!playerState)
                {
                    continue;
                }

                // get member display name
                std::wstring memberName = L"(Reserved)";
                if (!playerState->DisplayName.empty())
                {
                    memberName = playerState->DisplayName;

                    if (playerState->IsLocalPlayer)
                    {
                        memberName.append(L" (You)");
                    }
                }

                auto memberNameLen = spriteFont->MeasureString(memberName.c_str());
                XMFLOAT2 memberOrigin = XMFLOAT2(XMVectorGetX(memberNameLen) / 2.0f, spriteFont->GetLineSpacing() / 2.0f);

                // draw member display name
                if (playerState != nullptr && !playerState->IsInactive())
                {
                    renderContext->DrawString(spriteFont, memberName.c_str(), memberPositions[memberNumber % 4], Ship::Colors[playerState->ShipColor()], 0, memberOrigin, scale);
                }
                else
                {
                    renderContext->DrawString(spriteFont, memberName.c_str(), memberPositions[memberNumber % 4], Colors::LightGray, 0, memberOrigin, scale);
                }

                if (playerState != nullptr)
                {
                    // draw member status icons and ship
                    XMFLOAT2 glyphCenterPosition = XMFLOAT2(memberPositions[memberNumber % 4].x, memberPositions[memberNumber % 4].y + spriteFont->GetLineSpacing() * 1.7f * scale);

                    if (playerState->InGame)
                    {
                        // draw inGame texture
                        renderContext->Draw(m_inGameTexture, glyphCenterPosition, 0.0f, inGameTextureScale, Colors::White, TexturePosition::Centered);
                    }
                    else if (playerState->LobbyReady)
                    {
                        // draw ready texture if player is ready
                        renderContext->Draw(m_readyTexture, glyphCenterPosition, 0.0f, readyTextureScale, Colors::White, TexturePosition::Centered);
                    }

                    // draw ship
                    auto ship = playerState->GetShip();
                    if (ship)
                    {
                        XMFLOAT2 oldShipPosition = ship->Position;
                        float oldShipRotation = ship->Rotation;

                        ship->Position = glyphCenterPosition;
                        ship->Position.x += ship->Radius + 10.0f;
                        ship->Rotation = 0.0f;

                        ship->Draw(0.0f, renderContext, true, GetScaleMultiplierForViewport(viewportWidth, viewportHeight));

                        ship->Rotation = oldShipRotation;
                        ship->Position = oldShipPosition;
                    }
                }

                // adjust the column for the next row
                memberPositions[memberNumber % 4].y += spriteFont->GetLineSpacing() * scale * 3.7f;
                memberNumber++;
            }

            if (IsActive())
            {
                // draw instructions centered at bottom of screen
#ifdef _XBOX_ONE
                XMFLOAT2 position = XMFLOAT2(viewportWidth / 2.0f, viewportHeight * 0.95f);
#else
                XMFLOAT2 position = XMFLOAT2(viewportWidth / 2.0f, viewportHeight * 0.9f);
#endif

                if (Managers::Get<GameStateManager>()->GetState() == GameState::WaitingToStart)
                {
                    XMVECTOR size = spriteFont->MeasureString(gameSessionInstructions);
                    XMFLOAT2 origin = XMFLOAT2(XMVectorGetX(size) / 2.0f, spriteFont->GetLineSpacing() / 2.0f);
                    renderContext->DrawString(spriteFont, gameSessionInstructions, position, Colors::White, 0, origin, scale);
#ifndef _XBOX_ONE
                    position.y += spriteFont->GetLineSpacing() * scale;
                    size = spriteFont->MeasureString(gameSessionInstructions2);
                    origin = XMFLOAT2(XMVectorGetX(size) / 2.0f, spriteFont->GetLineSpacing() / 2.0f);
                    renderContext->DrawString(spriteFont, gameSessionInstructions2, position, Colors::White, 0, origin, scale);
#endif
                }
                else
                {
                    XMVECTOR size = spriteFont->MeasureString(lobbySessionInstructions);
                    XMFLOAT2 origin = XMFLOAT2(XMVectorGetX(size) / 2.0f, spriteFont->GetLineSpacing() / 2.0f);
                    renderContext->DrawString(spriteFont, lobbySessionInstructions, position, Colors::White, 0, origin, scale);
                }
            }
        }

        renderContext->End();
    }

    MenuScreen::Draw(totalTime, elapsedTime);
}

void GameLobbyScreen::OnCancel()
{
    ExitScreen();
}
