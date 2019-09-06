//--------------------------------------------------------------------------------------
// PlayFabWebAuthBrokerFB.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"
#include "LiveResourcesXDK.h"
#include "LiveInfoHUD.h"
#include "FacebookAuthHelper.h"

#include "playfab/PlayFabError.h"
#include "playfab/PlayFabClientDataModels.h"
#include "PlayerProfileSummary.h"

#include "SampleUI.h"

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

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    // Log into PlayFab using the Xbox User
    void LoginToPlayFabWithXbox(Windows::Xbox::System::IUser ^xboxUser, bool createAccount);
    void LoginToPlayFabWithXboxErrorHandler(const PlayFab::PlayFabError& error, bool createAccount);

    // Display the PlayFab player profile summary
    void DisplayPlayerProfileSummary(const std::string &playFabId);

    // Log into PlayFab using the facebook auth token
    void LoginToPlayFabWithFacebook(const std::string &fbAccessToken);
    void LoginToPlayFabWithFacebookErrorHandler(const PlayFab::PlayFabError& error);

    // Use the authentication broker to sign into Facebook
    void OnFacebookAuthComplete(FacebookAuthHelper::FacebookAuthResult& facebookAuthResult);

    // Link the PlayFab account with the Xbox user error handler
    void LinkPlayFabWithXboxErrorHandler(const PlayFab::PlayFabError& error);

    void UnlinkPlayFabAccount();

    void ReportPlayFabError(const PlayFab::PlayFabError & error);
    void ReportException(Platform::Exception^ Ex, Platform::String^ sender);
    void ReportException(Platform::Exception^ Ex);

    concurrency::task<void> CacheXboxLiveTokenResult(Windows::Xbox::System::IUser ^ xboxUser);

    // Device resources.
    std::unique_ptr<DX::DeviceResources>                      m_deviceResources;

    std::unique_ptr<DX::TextConsole>                          m_console;

    // Rendering loop timer.
    uint64_t                                                  m_frame;
    DX::StepTimer                                             m_timer;

    // Input devices.
    std::unique_ptr<DirectX::GamePad>                         m_gamePad;

    DirectX::GamePad::ButtonStateTracker                      m_gamePadButtons;

    // UI system
    std::unique_ptr<SampleUI>                                 m_sampleUI;
    std::unique_ptr<DirectX::SpriteBatch>                     m_batch;
    std::unique_ptr<DirectX::SpriteFont>                      m_font;

    // DirectXTK objects.
    std::unique_ptr<DirectX::GraphicsMemory>                  m_graphicsMemory;
	
	// Xbox Live objects.
	std::shared_ptr<ATG::LiveResources>                       m_liveResources;
    std::unique_ptr<ATG::LiveInfoHUD>                         m_liveInfoHUD;

    // Sample objects
    std::string                                               m_xboxLiveToken;

    std::unique_ptr<FacebookAuthHelper>                       m_fbAuthHelper;
    concurrency::cancellation_token_source                    m_facebookAuthCancelationTokenSource;
    concurrency::task<FacebookAuthHelper::FacebookAuthResult> m_facebookAuthTask;

    concurrency::critical_section                             m_critSec;
    
    std::string                                               m_playFabId;
    PlayFabPlayerProfileSummary                               m_playerProfileSummary;
};
