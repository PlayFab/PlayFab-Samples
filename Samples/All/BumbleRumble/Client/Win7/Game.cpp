//--------------------------------------------------------------------------------------
// Game.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Game.h"
#include "Managers.h"
#include "WelcomeScreen.h"
#include "StarfieldScreen.h"
#include "DebugOverlayScreen.h"

extern void ExitGame();

using namespace BumbleRumble;
using namespace DirectX;

using Microsoft::WRL::ComPtr;

Game::Game() noexcept :
    m_window(nullptr),
    m_outputWidth(1280),
    m_outputHeight(720)
{
}

// Initialize the Direct3D resources required to run.
void Game::Initialize(HWND window, int width, int height)
{
    m_window = window;
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);


#ifdef _DEBUG
    DebugInit();
#endif

    Managers::Initialize();

    Managers::Get<RenderManager>()->Initialize(window, width, height);

    Managers::Get<AudioManager>()->Initialize();
    Managers::Get<PlayFabManager>()->Initialize();
    Managers::Get<GameStateManager>()->Initialize();
    Managers::Get<ParticleEffectManager>()->Initialize();

    Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<WelcomeScreen>());
    Managers::Get<ScreenManager>()->AddBackgroundScreen(std::make_shared<StarfieldScreen>());
    Managers::Get<ScreenManager>()->AddForegroundScreen(std::make_shared<DebugOverlayScreen>());

    PrefetchContent();
}

// Executes the basic game loop.
void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}

// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    Managers::Get<NetworkManager>()->DoWork();
    Managers::Get<InputManager>()->Update();
    Managers::Get<AudioManager>()->Tick();
    Managers::Get<PlayFabManager>()->Tick();
    Managers::Get<GameStateManager>()->Update();
    Managers::Get<ParticleEffectManager>()->Update(static_cast<float_t>(timer.GetElapsedSeconds()));
    Managers::Get<ScreenManager>()->Update(timer);
}

// Draws the scene.
void Game::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    auto renderManager = Managers::Get<RenderManager>();

    renderManager->Clear();

    Managers::Get<ScreenManager>()->Render(m_timer);

    renderManager->Present();
}

// Message handlers
void Game::OnActivated()
{
}

void Game::OnDeactivated()
{
}

void Game::OnSuspending()
{
    Managers::Get<GameStateManager>()->Suspend();
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    Managers::Get<GameStateManager>()->Resume();
}

void Game::OnWindowSizeChanged(int width, int height)
{
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);

    Managers::Get<RenderManager>()->OnWindowSizeChanged(width, height);
    Managers::Get<ScreenManager>()->CreateWindowSizeDependentResources();
}

// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    width = 1280;
    height = 720;
}

void Game::PrefetchContent()
{
    auto contentManager = Managers::Get<ContentManager>();
    std::string texturePath = "Assets\\Textures\\";

    // Ship
    contentManager->LoadTexture(texturePath + "ship0.png");
    contentManager->LoadTexture(texturePath + "ship1.png");
    contentManager->LoadTexture(texturePath + "ship2.png");
    contentManager->LoadTexture(texturePath + "ship3.png");
    contentManager->LoadTexture(texturePath + "ship0Overlay.png");
    contentManager->LoadTexture(texturePath + "ship1Overlay.png");
    contentManager->LoadTexture(texturePath + "ship2Overlay.png");
    contentManager->LoadTexture(texturePath + "ship3Overlay.png");
    contentManager->LoadTexture(texturePath + "shipShields.png");

    // Asteroids
    contentManager->LoadTexture(texturePath + "asteroid0.png");
    contentManager->LoadTexture(texturePath + "asteroid1.png");
    contentManager->LoadTexture(texturePath + "asteroid2.png");

    // Laser
    contentManager->LoadTexture(texturePath + "laser.png");
    contentManager->LoadTexture(texturePath + "powerupDoubleLaser.png");
    contentManager->LoadTexture(texturePath + "powerupTripleLaser.png");

    // Mine
    contentManager->LoadTexture(texturePath + "mine.png");

    // Rocket
    contentManager->LoadTexture(texturePath + "rocket.png");
    contentManager->LoadTexture(texturePath + "powerupRocket.png");


    auto audioManager = Managers::Get<AudioManager>();
    std::string audioPath = "Assets\\Audio\\";

    audioManager->LoadSound("asteroid_touch", audioPath + "asteroid_touch.wav");
    audioManager->LoadSound("explosion_large", audioPath + "explosion_large.wav");
    audioManager->LoadSound("explosion_medium", audioPath + "explosion_medium.wav");
    audioManager->LoadSound("explosion_shockwave", audioPath + "explosion_shockwave.wav");
    audioManager->LoadSound("fire_laser1", audioPath + "fire_laser1.wav");
    audioManager->LoadSound("fire_laser2", audioPath + "fire_laser2.wav");
    audioManager->LoadSound("fire_laser3", audioPath + "fire_laser3.wav");
    audioManager->LoadSound("fire_rocket1", audioPath + "fire_rocket1.wav");
    audioManager->LoadSound("fire_rocket2", audioPath + "fire_rocket2.wav");
    audioManager->LoadSound("menu_scroll", audioPath + "menu_scroll.wav");
    audioManager->LoadSound("menu_select", audioPath + "menu_select.wav");
    audioManager->LoadSound("player_spawn", audioPath + "player_spawn.wav");
    audioManager->LoadSound("powerup_spawn", audioPath + "powerup_spawn.wav");
    audioManager->LoadSound("powerup_touch", audioPath + "powerup_touch.wav");
    audioManager->LoadSound("rocket", audioPath + "rocket.wav");
}