//--------------------------------------------------------------------------------------
// SimplePlayFabAuth.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"
#include "LiveResourcesXDK.h"
#include "LiveInfoHUD.h"
#include "ControllerFont.h"


// A basic sample implementation that creates a D3D11 device and
// provides a render loop.
class Sample
{
public:

    Sample();

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

    void ChangeAccount();
    void SetCurrentUser(Windows::Xbox::System::IUser^ xboxUser);

    void RefreshPlayFabToken(Windows::Xbox::System::IUser^ xboxUser);
    void LinkWithExistingPlayFabAccount(Windows::Xbox::System::IUser^ xboxUser);
    void RegisterForPlayFab(Windows::Xbox::System::IUser^ xboxUser);
    void UpdatePlayFabDisplayName();

    // These are static so they can be used from within lambdas that don't otherwise need access to "this"
    static void HandleException(Platform::Exception^ Ex, Platform::String^ sender);
    static void OnPlayFabError(const PlayFab::PlayFabError& error, void* custom);

    // Device resources.
    std::unique_ptr<DX::DeviceResources>        m_deviceResources;

    std::unique_ptr<DirectX::SpriteBatch>       m_batch;
    std::unique_ptr<DirectX::SpriteFont>        m_font;
    std::unique_ptr<DirectX::SpriteFont>        m_ctrlFont;
    std::unique_ptr<DX::TextConsole>            m_console;

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

    Windows::Xbox::System::IUser^ m_currentUser;
    Windows::Foundation::Collections::IVectorView<Windows::Xbox::System::User^>^ m_users;

    // PlayFab limits display names to a max of 25 characters plus one for null terminator
    wchar_t m_playFabDisplayName[26];
    bool m_playFabLoggedIn;
};
