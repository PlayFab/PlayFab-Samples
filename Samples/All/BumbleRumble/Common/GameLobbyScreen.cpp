//--------------------------------------------------------------------------------------
// GameLobbyScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "GameLobbyScreen.h"
#include "GamePlayScreen.h"
#include "MainMenuScreen.h"
#include "Managers.h"
#include "PlayerState.h"
#include "Game.h"

using namespace BumbleRumble;
using namespace DirectX;

const char* c_lobbySessionInstructions = "";
const char* c_gameSessionInstructions = "Gamepad: LB/RB to change ship color/style, Menu for game options, Left Thumbstick for user list";
const char* c_gameSessionInstructions2 = "Keyboard: Left/Right to change ship color/style, Tab for game options, Shift+Tab for user list";

GameLobbyScreen::GameLobbyScreen() : 
    MenuScreen(),
    m_ready(false),
    m_lastState(GameState::Initialize)
{
    m_transitionOnTime = 1.0;
    m_transitionOffTime = 1.0;

    Managers::Get<AudioManager>()->PlaySoundTrack(false);

    m_menuEntries.clear();
    m_menuEntries.push_back(MenuEntry("Matchmaking: Requesting Start"));
    m_TimeSinceLastMatchmakingPulse = 0.f;
    Managers::Get<GameStateManager>()->GotoMatchmaking();


    m_inGameTexture = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\Xbox_One_Controller_Front.png");
    m_readyTexture = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\ready.png");
    m_chatAble = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\chatAble.png");
    m_chatMute = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\chatMute.png");
    m_chatTalk = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\chatTalking.png");

    Managers::Get<PlayFabManager>()->UpdateStatistic("games_joined", 1);
    Managers::Get<ScreenManager>()->SetBackgroundsVisible(true);
}

GameLobbyScreen::~GameLobbyScreen()
{
}

void GameLobbyScreen::HandleInput()
{
    MenuScreen::HandleInput();

    auto inputManager = Managers::Get<InputManager>();
    auto localPlayerState = Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId());

    if (inputManager->IsNewButtonPress(InputManager::GamepadButtons::LeftShoulder) || inputManager->IsNewKeyPress(Keyboard::Keys::Left))
    {
        // change ship color
        localPlayerState->ShipColor((localPlayerState->ShipColor() + 1) % Ship::Colors.size());

        Managers::Get<NetworkManager>()->SendGameMessage(
            GameNetworkMessage(
                GameMessageType::PlayerState,
                localPlayerState->SerializePlayerStateData()
                )
            );
    }
    else if (inputManager->IsNewButtonPress(InputManager::GamepadButtons::RightShoulder) || inputManager->IsNewKeyPress(Keyboard::Keys::Right))
    {
        // change ship design
        localPlayerState->ShipVariation((localPlayerState->ShipVariation() + 1) % Ship::MaxVariations);

        Managers::Get<NetworkManager>()->SendGameMessage(
            GameNetworkMessage(
                GameMessageType::PlayerState,
                localPlayerState->SerializePlayerStateData()
                )
            );
    }
}

void GameLobbyScreen::Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen)
{
    auto state = Managers::Get<GameStateManager>()->GetState();

    m_menuEntries.clear();

    switch(state)
    {
        case GameState::Matchmaking:
            if (Managers::Get<PlayFabManager>()->MatchStatus() == MatchmakingStatus::CancellingMatch)
            {
                m_menuEntries.push_back(MenuEntry("Matchmaking: Cancelling..."));
            }
            else
            {
                m_menuEntries.push_back(MenuEntry("Matchmaking: Waiting for players..."));
            }
            break;

        case GameState::AllocatingServer:
        {
            if (Managers::Get<PlayFabManager>()->IsGameHost())
            {
                m_menuEntries.push_back(MenuEntry("Creating Network..."));
            }
            else
            {
                m_menuEntries.push_back(MenuEntry("Waiting for Host..."));
            }
            break;
        }

        case GameState::WaitingForServer:
        case GameState::ConnectingToServer:
            m_menuEntries.push_back(MenuEntry("Connecting to Host..."));
            break;

        case GameState::WaitingToStart:
            if (m_lastState != state)
            {
                DEBUGLOG("WaitingToStart: Sending PlayerInfo\n");
                auto playerState = Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId());
                auto displayName = playerState->DisplayName;

                Managers::Get<NetworkManager>()->SendGameMessage(
                    GameNetworkMessage(
                        GameMessageType::PlayerInfo,
                        displayName
                        )
                    );

                Managers::Get<NetworkManager>()->SendGameMessage(
                    GameNetworkMessage(
                        GameMessageType::PlayerState,
                        playerState->SerializePlayerStateData()
                        )
                    );
            }

            if (m_ready)
            {
                m_menuEntries.push_back(MenuEntry("Waiting for game to start"));
            }
            else
            {
                m_menuEntries.push_back(MenuEntry("Press (A) to ready",
                    [this]()
                    {
                        m_ready = true;
                        Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId())->LobbyReady = true;

                        Managers::Get<NetworkManager>()->SendGameMessage(
                            GameNetworkMessage(
                                GameMessageType::PlayerState,
                                Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId())->SerializePlayerStateData()
                                )
                            );
                    }));
            }


            if (Managers::Get<PlayFabManager>()->IsGameHost())
            {
                auto allReady = true;
                auto players = Managers::Get<GameStateManager>()->GetAllPlayerStates();

                for (auto player : players)
                {
                    if (!player->LobbyReady)
                    {
                        allReady = false;
                        break;
                    }
                }

                if (allReady)
                {
                    Managers::Get<GameStateManager>()->GotoPlaying();
                }
            }

            break;

        case GameState::Playing:
            if (m_lastState != state)
            {
                Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId())->InGame = true;
                Managers::Get<NetworkManager>()->SendGameMessage(
                    GameNetworkMessage(
                        GameMessageType::PlayerState,
                        Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId())->SerializePlayerStateData()
                        )
                    );
                Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<GamePlayScreen>());
                Managers::Get<ScreenManager>()->SetBackgroundsVisible(false);
            }
            break;
    }

    if (state != GameState::Playing)
    {
        m_TimeSinceLastMatchmakingPulse += elapsedTime;

        if (m_TimeSinceLastMatchmakingPulse >= c_timeBetweenMatchmakingPulses)
        {
            m_TimeSinceLastMatchmakingPulse = 0.f;
        }
    }

    m_lastState = state;

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
        auto spriteFont = Managers::Get<ContentManager>()->LoadFont("Assets\\Fonts\\SegoeUI_64.spritefont");
        float viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
        float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);
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

            float inGameTextureScale = 0.9f * scale * spriteFont->GetLineSpacing() / m_inGameTexture->Height();
            XMFLOAT2 inGameTextureOrigin = XMFLOAT2((float)m_inGameTexture->Width(), (float)m_inGameTexture->Height() / 2.0f);

            float readyTextureScale = 0.9f * scale * spriteFont->GetLineSpacing() / m_readyTexture->Height();
            XMFLOAT2 readyTextureOrigin = XMFLOAT2((float)m_readyTexture->Width(), (float)m_readyTexture->Height() / 2.0f);

            float chatTextureScale = 0.9f * scale * spriteFont->GetLineSpacing() / m_chatAble->Height();
            XMFLOAT2 chatTextureOrigin = XMFLOAT2((float)m_chatAble->Width(), (float)m_chatAble->Height() / 2.0f);

            UINT memberNumber = 0;
            for (const auto& playerState : playerStates)
            {
                if (!playerState)
                {
                    continue;
                }

                // get member display name
                std::string memberName = "(Reserved)";
                if (!playerState->DisplayName.empty())
                {
                    memberName = playerState->DisplayName;
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
                    XMFLOAT2 chatCenterPosition = XMFLOAT2(memberPositions[memberNumber % 4].x - m_chatAble->Width() * 1.8f * scale, memberPositions[memberNumber % 4].y + spriteFont->GetLineSpacing() * 1.7f * scale);

                    if (playerState->InGame)
                    {
                        // draw InGame texture
                        renderContext->Draw(m_inGameTexture, glyphCenterPosition, 0.0f, inGameTextureScale, Colors::White, TexturePosition::Centered);
                    }
                    else if (playerState->LobbyReady)
                    {
                        // draw ready mtexture if player is ready
                        renderContext->Draw(m_readyTexture, glyphCenterPosition, 0.0f, readyTextureScale, Colors::White, TexturePosition::Centered);
                    }

                    if (playerState->IsLocalPlayer)
                    {
                        Party::PartyLocalChatControlChatIndicator indicator;

                        Managers::Get<NetworkManager>()->GetLocalChatControl()->GetLocalChatIndicator(&indicator);

                        switch (indicator)
                        {
                        case Party::PartyLocalChatControlChatIndicator::AudioInputMuted:
                        case Party::PartyLocalChatControlChatIndicator::NoAudioInput:
                            renderContext->Draw(m_chatMute, chatCenterPosition, 0.0f, chatTextureScale, Colors::White, TexturePosition::Centered);
                            break;
                        case Party::PartyLocalChatControlChatIndicator::Silent:
                            renderContext->Draw(m_chatAble, chatCenterPosition, 0.0f, chatTextureScale, Colors::White, TexturePosition::Centered);
                            break;
                        case Party::PartyLocalChatControlChatIndicator::Talking:
                            renderContext->Draw(m_chatTalk, chatCenterPosition, 0.0f, chatTextureScale, Colors::White, TexturePosition::Centered);
                            break;
                        }
                    }
                    else
                    {
                        auto chatControl = Managers::Get<NetworkManager>()->GetChatControl(playerState->PeerId);

                        if (chatControl != nullptr)
                        {
                            Party::PartyChatControlChatIndicator indicator;

                            Managers::Get<NetworkManager>()->GetLocalChatControl()->GetChatIndicator(chatControl, &indicator);

                            switch (indicator)
                            {
                            case Party::PartyChatControlChatIndicator::IncomingCommunicationsMuted:
                            case Party::PartyChatControlChatIndicator::IncomingVoiceDisabled:
                                renderContext->Draw(m_chatMute, chatCenterPosition, 0.0f, chatTextureScale, Colors::White, TexturePosition::Centered);
                                break;
                            case Party::PartyChatControlChatIndicator::Silent:
                                renderContext->Draw(m_chatAble, chatCenterPosition, 0.0f, chatTextureScale, Colors::White, TexturePosition::Centered);
                                break;
                            case Party::PartyChatControlChatIndicator::Talking:
                                renderContext->Draw(m_chatTalk, chatCenterPosition, 0.0f, chatTextureScale, Colors::White, TexturePosition::Centered);
                                break;
                            }

                        }
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
                XMFLOAT2 position = XMFLOAT2(viewportWidth / 2.0f, viewportHeight * 0.9f);

                if (Managers::Get<GameStateManager>()->GetState() == GameState::WaitingToStart)
                {
                    XMVECTOR size = spriteFont->MeasureString(c_gameSessionInstructions);
                    XMFLOAT2 origin = XMFLOAT2(XMVectorGetX(size) / 2.0f, spriteFont->GetLineSpacing() / 2.0f);
                    renderContext->DrawString(spriteFont, c_gameSessionInstructions, position, Colors::White, 0, origin, scale);

                    position.y += spriteFont->GetLineSpacing() * scale;
                    size = spriteFont->MeasureString(c_gameSessionInstructions2);
                    origin = XMFLOAT2(XMVectorGetX(size) / 2.0f, spriteFont->GetLineSpacing() / 2.0f);
                    renderContext->DrawString(spriteFont, c_gameSessionInstructions2, position, Colors::White, 0, origin, scale);
                }
                else
                {
                    XMVECTOR size = spriteFont->MeasureString(c_lobbySessionInstructions);
                    XMFLOAT2 origin = XMFLOAT2(XMVectorGetX(size) / 2.0f, spriteFont->GetLineSpacing() / 2.0f);
                    renderContext->DrawString(spriteFont, c_lobbySessionInstructions, position, Colors::White, 0, origin, scale);
                }
            }
        }

        renderContext->End();
    }

    MenuScreen::Draw(totalTime, elapsedTime);
}

void GameLobbyScreen::OnCancel()
{
    if (Managers::Get<GameStateManager>()->GetState() == GameState::Matchmaking)
    {
        Managers::Get<PlayFabManager>()->CancelMatchmaking();
    }
    else
    {
        Managers::Get<GameStateManager>()->ResetGame("");
    }
}
