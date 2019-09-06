//--------------------------------------------------------------------------------------
// PlayFabCloudScripts.h
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
#include "TextConsole.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
#include "ControllerFont.h"
#include "Effects.h"
#include "VertexTypes.h"
#include "DebugDraw.h"
#include "CommonStates.h"
#include "SimpleMath.h"

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

    static void OnPlayFabError(const PlayFab::PlayFabError& error, void* data);
    static void OnCloudScriptExecuted(const PlayFab::ClientModels::ExecuteCloudScriptResult& result, void* data);

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    void TryAddFunds();
    void CheckFunds();
    void RunHelloWorldScript();

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

    // UI objects
    std::unique_ptr<DX::TextConsole>            m_console;
    std::unique_ptr<DirectX::SpriteBatch>       m_batch;
    std::unique_ptr<DirectX::SpriteFont>        m_font;
    std::unique_ptr<DirectX::SpriteFont>        m_largeFont;
    std::unique_ptr<DirectX::SpriteFont>        m_ctrlFont;

    uint32_t                                    m_lastRequestTickCount;
    uint32_t                                    m_showRecieptTickCount;
    uint32_t                                    m_fundsAdded;
    uint32_t                                    m_balance;
    std::wstring                                m_messageToDisplay;

    std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>  m_drawBatch;
    std::unique_ptr<DirectX::BasicEffect>                                   m_drawEffect;
    Microsoft::WRL::ComPtr<ID3D11InputLayout>                               m_drawInputLayout;
    std::unique_ptr<DirectX::CommonStates>                                  m_states;
};
