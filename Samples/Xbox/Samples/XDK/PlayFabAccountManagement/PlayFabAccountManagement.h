//--------------------------------------------------------------------------------------
// PlayFabAccountManagement.h
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
#include "TextConsole.h"
#include "SpriteFont.h"
#include "DebugDraw.h"
#include "Effects.h"
#include "SimpleMath.h"
#include "CommonStates.h"

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

    void ChangeXboxProfile();
    void CreateNewPlayFabAccountAndLink();
    void LinkExistingPlayFabAccount();
    void UnlinkPlayFabAccount();
    void SetTitleDisplayName();
    void UpdateEmailAddress();
    void RemoveEmailAddress();
    void GetAccountInfo();
    void GetProfileInfo(std::string playFabId);
    void LoginWithXbox();
    void LoginWithUsername();

    void SetErrorText(const std::wstring& message, int frameCountToDisplayError);

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    void RefreshAccountInfo(const std::string& playFabId);
    void ClearAccountInfo();
    void SetupUI();
    static void OnPlayFabError(const PlayFab::PlayFabError& error, void* custom);
    static void HandleException(Platform::Exception^ Ex, Platform::String^ sender);

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
    std::unique_ptr<DX::TextConsole>            m_console;
    std::unique_ptr<DirectX::SpriteBatch>       m_batch;
    std::unique_ptr<DirectX::SpriteFont>        m_font;

    std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>  m_drawBatch;
    std::unique_ptr<DirectX::BasicEffect>                                   m_drawEffect;
    Microsoft::WRL::ComPtr<ID3D11InputLayout>                               m_drawInputLayout;
    std::unique_ptr<DirectX::CommonStates>                                  m_states;

    // Contact email address for a PlayFab account
    std::wstring                                m_contactEmail;
    // Title display name stored in PlayFab account
    std::wstring                                m_displayName;
    // PlayFab account ID (not generally displayed to the user)
    std::wstring                                m_playFabId;
    // Username a player may use to sign in to their account
    std::wstring                                m_userName;
    // Xbox user ID (XUID)
    std::wstring                                m_xboxUserId;
    // Time of PlayFab account creation
    std::wstring                                m_creationTime;
    // Time of first login for this account
    std::wstring                                m_firstLogin;
    // Time of most recent login for this account
    std::wstring                                m_lastLogin;
    // Title ID that this information was requested for (not generally displayed to the user)
    std::wstring                                m_titleId;
    // Publisher ID of the title (not generally displayed to the user)
    std::wstring                                m_publisherId;
    // Time that this account is banned until
    std::wstring                                m_bannedUntil;
    // URL for the avatar for this account
    std::wstring                                m_avatarUrl;
    // Indicated whether this account is banned
    bool                                        m_banned;
    // Amount of money this player has spent during the lifetime of this account (i.e. 999 = $9.99)
    PlayFab::Uint32                             m_playerValue;

    int                                         m_frameCountToDisplayError;
    std::wstring                                m_errorMessage;
};
