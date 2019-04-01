//--------------------------------------------------------------------------------------
// BumbleRumbleXDK.cpp
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

extern void ExitSample();

using namespace DirectX;
using namespace BumbleRumble;

using Microsoft::WRL::ComPtr; 

std::unique_ptr<Sample> g_game;

Sample::Sample() noexcept(false) :
    m_frame(0)
{
    m_liveResources = std::make_shared<ATG::LiveResources>();
}

// Initialize the Direct3D resources required to run.
void Sample::Initialize(IUnknown* window)
{
    Managers::Initialize();

    Managers::Get<RenderManager>()->Initialize(window);

    Managers::Get<AudioManager>()->Initialize();
    Managers::Get<PlayFabManager>()->Initialize();
    Managers::Get<GameStateManager>()->Initialize();
    Managers::Get<ParticleEffectManager>()->Initialize();

    Managers::Get<ScreenManager>()->AddGameScreen(std::make_shared<WelcomeScreen>());
    Managers::Get<ScreenManager>()->AddBackgroundScreen(std::make_shared<StarfieldScreen>());
    Managers::Get<ScreenManager>()->AddForegroundScreen(std::make_shared<DebugOverlayScreen>());

    PrefetchContent();

    CreateDeviceDependentResources();
    CreateWindowSizeDependentResources();

    m_liveResources->SetUserChangedCallback([this](ATG::XboxLiveUser user)
    {
        user;
    });

    m_liveResources->SetUserSignOutCompletedCallback([this](ATG::XboxLiveUser user)
    {
        user;
    });

    m_liveResources->Initialize();
}

#pragma region Frame Update
// Executes basic render loop.
void Sample::Tick()
{
    PIXBeginEvent(PIX_COLOR_DEFAULT, L"Frame %I64u", m_frame);

    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();

    PIXEndEvent();
    m_frame++;
}

// Updates the world.
void Sample::Update(DX::StepTimer const& timer)
{
    PIXBeginEvent(PIX_COLOR_DEFAULT, L"Update");

    Managers::Get<NetworkManager>()->DoWork();
    Managers::Get<InputManager>()->Update();
    Managers::Get<AudioManager>()->Tick();
    Managers::Get<PlayFabManager>()->Tick();
    Managers::Get<GameStateManager>()->Update();
    Managers::Get<ParticleEffectManager>()->Update(static_cast<float_t>(timer.GetElapsedSeconds()));
    Managers::Get<ScreenManager>()->Update(timer);

    PIXEndEvent();
}
#pragma endregion

#pragma region Frame Render
// Draws the scene.
void Sample::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    auto renderManager = Managers::Get<RenderManager>();

    renderManager->Prepare();
    renderManager->Clear();

    Managers::Get<ScreenManager>()->Render(m_timer);

    renderManager->Present();
}

// Helper method to clear the back buffers.
void Sample::Clear()
{
    Managers::Get<RenderManager>()->Clear();
}
#pragma endregion

#pragma region Message Handlers
// Message handlers
void Sample::OnSuspending()
{
    Managers::Get<RenderManager>()->Suspend();
}

void Sample::OnResuming()
{
    Managers::Get<RenderManager>()->Resume();
    m_timer.ResetElapsedTime();
    m_liveResources->Refresh();
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Sample::CreateDeviceDependentResources()
{
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
}
#pragma endregion

void Sample::PrefetchContent()
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