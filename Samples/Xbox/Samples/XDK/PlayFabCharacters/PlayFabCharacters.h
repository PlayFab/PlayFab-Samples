//--------------------------------------------------------------------------------------
// PlayFabCharacters.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"
#include "LiveResourcesXDK.h"
#include "LiveInfoHUD.h"
#include "PlayFabResourcesXDK.h"

#include "SampleGUI.h"


// A basic sample implementation that creates a D3D11 device and
// provides a render loop.
class Sample
{
public:

    Sample() noexcept(false);

    // Initialization and management
    void Initialize(IUnknown* window);

    // Basic game loop
    void Tick();

    // Messages
    void OnSuspending();
    void OnResuming();

    // Properties
    bool RequestHDRMode() const { return m_deviceResources ? (m_deviceResources->GetDeviceOptions() & DX::DeviceResources::c_EnableHDR) != 0 : false; }

    static void OnCloudScriptExecuted(const PlayFab::ClientModels::ExecuteCloudScriptResult& result);
    static void OnPlayFabError(const PlayFab::PlayFabError& error, void*);

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    void SetupUI();
    void UpdateCharacterList();
    void GetPlayFabCharacters();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>        m_deviceResources;

    // Rendering loop timer.
    uint64_t                                    m_frame;
    DX::StepTimer                               m_timer;

    // Input devices.
    std::unique_ptr<DirectX::GamePad>           m_gamePad;

    DirectX::GamePad::ButtonStateTracker        m_gamePadButtons;

    // DirectXTK objects.
    std::unique_ptr<DirectX::GraphicsMemory>    m_graphicsMemory;
	
	// Xbox Live objects.
	std::shared_ptr<ATG::LiveResources>         m_liveResources;
    std::unique_ptr<ATG::LiveInfoHUD>           m_liveInfoHUD; 

    // PlayFab objects.
    std::shared_ptr<ATG::PlayFabResources>      m_playFabResources;

    // UI elements
    std::unique_ptr<ATG::UIManager>             m_ui;
    std::unique_ptr<DirectX::SpriteBatch>       m_batch;
    std::unique_ptr<DirectX::SpriteFont>        m_font;

    std::vector<PlayFab::ClientModels::CharacterResult> m_characters;
    wchar_t                                     m_characterDescBuffers[3][1000];
};
