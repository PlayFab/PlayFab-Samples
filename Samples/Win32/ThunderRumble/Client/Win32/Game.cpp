//--------------------------------------------------------------------------------------
// Game.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Game.h"
#include "Managers.h"
#include "WelcomeScreen.h"
#include "StarfieldScreen.h"
#include "DebugOverlayScreen.h"

extern void ExitGame();

using namespace ThunderRumble;
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

    //CreateDevice();
    //CreateResources();

    // Lock the game to 60FPS
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 30);

    Managers::Initialize();

    Managers::Get<RenderManager>()->Initialize(window, width, height);

    Managers::Get<AudioManager>()->Initialize();
    Managers::Get<PlayFabManager>()->Initialize();
    Managers::Get<NetworkManager>()->Initialize();
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
    Managers::Get<ScreenManager>()->Update(timer);
    Managers::Get<InputManager>()->Update();
    Managers::Get<AudioManager>()->Tick();
    Managers::Get<PlayFabManager>()->Tick();
    Managers::Get<ParticleEffectManager>()->Update(static_cast<float_t>(timer.GetElapsedSeconds()));
    Managers::Get<NetworkManager>()->DoWork(static_cast<float_t>(timer.GetElapsedSeconds()));
    Managers::Get<GameStateManager>()->Update();
    Managers::Get<GameServiceManager>()->Tick();
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
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
    Managers::Get<GameStateManager>()->Suspend();
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
    Managers::Get<GameStateManager>()->Resume();
}

void Game::OnWindowSizeChanged(int width, int height)
{
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);

    Managers::Get<RenderManager>()->OnWindowSizeChanged(width, height);

    // TODO: Game window is being resized.
    Managers::Get<ScreenManager>()->CreateWindowSizeDependentResources();
}

// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width = 1280;
    height = 720;
}

void Game::PrefetchContent()
{
    auto contentManager = Managers::Get<ContentManager>();
    std::wstring texturePath = L"Assets\\Textures\\";

    // Ship
    contentManager->LoadTexture(texturePath + L"ship0.png");
    contentManager->LoadTexture(texturePath + L"ship1.png");
    contentManager->LoadTexture(texturePath + L"ship2.png");
    contentManager->LoadTexture(texturePath + L"ship3.png");
    contentManager->LoadTexture(texturePath + L"ship0Overlay.png");
    contentManager->LoadTexture(texturePath + L"ship1Overlay.png");
    contentManager->LoadTexture(texturePath + L"ship2Overlay.png");
    contentManager->LoadTexture(texturePath + L"ship3Overlay.png");
    contentManager->LoadTexture(texturePath + L"shipShields.png");

    // Asteroids
    contentManager->LoadTexture(texturePath + L"asteroid0.png");
    contentManager->LoadTexture(texturePath + L"asteroid1.png");
    contentManager->LoadTexture(texturePath + L"asteroid2.png");

    // Laser
    contentManager->LoadTexture(texturePath + L"laser.png");
    contentManager->LoadTexture(texturePath + L"powerupDoubleLaser.png");
    contentManager->LoadTexture(texturePath + L"powerupTripleLaser.png");

    // Mine
    contentManager->LoadTexture(texturePath + L"mine.png");

    // Rocket
    contentManager->LoadTexture(texturePath + L"rocket.png");
    contentManager->LoadTexture(texturePath + L"powerupRocket.png");


    auto audioManager = Managers::Get<AudioManager>();
    std::wstring audioPath = L"Assets\\Audio\\";

    audioManager->LoadSound(L"asteroid_touch", audioPath + L"asteroid_touch.wav");
    audioManager->LoadSound(L"explosion_large", audioPath + L"explosion_large.wav");
    audioManager->LoadSound(L"explosion_medium", audioPath + L"explosion_medium.wav");
    audioManager->LoadSound(L"explosion_shockwave", audioPath + L"explosion_shockwave.wav");
    audioManager->LoadSound(L"fire_laser1", audioPath + L"fire_laser1.wav");
    audioManager->LoadSound(L"fire_laser2", audioPath + L"fire_laser2.wav");
    audioManager->LoadSound(L"fire_laser3", audioPath + L"fire_laser3.wav");
    audioManager->LoadSound(L"fire_rocket1", audioPath + L"fire_rocket1.wav");
    audioManager->LoadSound(L"fire_rocket2", audioPath + L"fire_rocket2.wav");
    audioManager->LoadSound(L"menu_scroll", audioPath + L"menu_scroll.wav");
    audioManager->LoadSound(L"menu_select", audioPath + L"menu_select.wav");
    audioManager->LoadSound(L"player_spawn", audioPath + L"player_spawn.wav");
    audioManager->LoadSound(L"powerup_spawn", audioPath + L"powerup_spawn.wav");
    audioManager->LoadSound(L"powerup_touch", audioPath + L"powerup_touch.wav");
    audioManager->LoadSound(L"rocket", audioPath + L"rocket.wav");
}