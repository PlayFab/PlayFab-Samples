//--------------------------------------------------------------------------------------
// File: LiveResourcesUWP.h
//
// Handles Users signing in and out and the related Xbox Live Contexts
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright(c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#pragma once

#if !defined(WINAPI_FAMILY) || (WINAPI_FAMILY != WINAPI_FAMILY_APP)
#error This file only supports UWP apps
#endif

// ***USAGE NOTE: when using this tool kit with a multi-user UWP app (MUA) on Xbox, add this to your pch.h: #define LIVETK_MULTI_USER_APP

namespace ATG
{
    using XboxLiveUser = std::shared_ptr<xbox::services::system::xbox_live_user>;

    class LiveResources : public std::enable_shared_from_this<LiveResources>
    {
    public:
        // Constructor Paramters:
        //   autoManageUser: auto user management sets current user to the first user it finds upon calling Initialize()
        //   isGuestUserAllowed: provided for compatibility with XDK version; not currently used by UWP
        LiveResources(bool autoManageUser = true, bool isGuestUserAllowed = false);

        // Callback for UWP signin methods
        using UserSignInCallback = std::function<void(xbox::services::xbox_live_result<xbox::services::system::sign_in_result>&)>;

        void Initialize(UserSignInCallback userSignInCallback = nullptr, Platform::Object^ dispatcher = nullptr); // you can provide a sign in callback when using auto user management
        void Refresh(UserSignInCallback userSignInCallback = nullptr, Platform::Object^ dispatcher = nullptr); // call when resuming from suspend, optionally providing a callback if you want the sign in results
        void SignIn(UserSignInCallback userSignInCallback, Platform::Object^ dispatcher = nullptr);
        void SignInSilently(UserSignInCallback userSignInCallback, Platform::Object^ dispatcher = nullptr);

        const std::wstring&                                 GetGamertag()           const { return m_gamertag; }
        std::shared_ptr<xbox::services::xbox_live_context>  GetLiveContext()        const { return m_xboxLiveContext; }
        const std::wstring&                                 GetSandbox()            const { return m_sandbox; }
        const std::wstring&                                 GetServiceConfigId()    const { return m_scid; }
        uint32_t                                            GetTitleId()            const { return m_titleId; }
        const std::wstring&                                 GetTitleIdHex()         const { return m_titleIdHex; }
        ATG::XboxLiveUser                                   GetUser()               const { return m_xboxLiveUser; }
        Windows::System::User^                              GetWindowsUser()        const { return m_windowsUser; }
        const std::wstring&                                 GetXuid()               const { return m_xuid; }
        bool                                                IsUserSignedIn()        const { return m_xboxLiveUser && m_xboxLiveUser->is_signed_in(); }

        void SetUserSignOutCompletedCallback(std::function<void(ATG::XboxLiveUser)> callback) { m_onUserSignOutCompletedCallback = callback; }
        void SetWindowsUser(Windows::System::User^ windowsUser);

    private:
        void HandleSignInResult(xbox::services::xbox_live_result<xbox::services::system::sign_in_result>& signInResult, UserSignInCallback userSignInCallback, Platform::Object^ dispatcher);
        void OnSignOutCompleted(const xbox::services::system::sign_out_completed_event_args& args);
        void UpdateUserInfo();

        bool                                                m_autoManageUser;
        bool                                                m_isGuestUserAllowed;

        // User Info
        std::wstring                                        m_gamertag;
        Windows::System::User^                              m_windowsUser;
        std::shared_ptr<xbox::services::xbox_live_context>  m_xboxLiveContext;
        ATG::XboxLiveUser                                   m_xboxLiveUser;
        std::wstring                                        m_xuid;

        // Title Info
        std::wstring                                        m_sandbox;
        std::wstring                                        m_scid;
        uint32_t                                            m_titleId;
        std::wstring                                        m_titleIdHex;

        // Callbacks
        std::function<void(ATG::XboxLiveUser)>              m_onUserSignOutCompletedCallback;
    };
}