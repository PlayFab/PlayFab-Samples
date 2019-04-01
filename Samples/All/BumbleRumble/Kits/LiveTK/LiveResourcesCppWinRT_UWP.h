//--------------------------------------------------------------------------------------
// File: LiveResourcesCppWinRT_UWP.h
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
    using XboxLiveUser = winrt::Microsoft::Xbox::Services::System::XboxLiveUser;

    class LiveResources : public std::enable_shared_from_this<LiveResources>
    {
    public:
        // Constructor Paramters:
        //   autoManageUser: auto user management sets current user to the first user it finds upon calling Initialize()
        //   isGuestUserAllowed: provided for compatibility with XDK version; not currently used by UWP
        LiveResources(bool autoManageUser = true, bool isGuestUserAllowed = false);

        // Callback for UWP signin methods
        using UserSignInCallback = std::function<void(const winrt::Microsoft::Xbox::Services::System::SignInResult&)>;

        void Initialize(UserSignInCallback userSignInCallback = nullptr, const winrt::Windows::IInspectable& dispatcher = nullptr); // you can provide a sign in callback when using auto user management
        void Refresh(UserSignInCallback userSignInCallback = nullptr, const winrt::Windows::IInspectable& dispatcher = nullptr); // call when resuming from suspend, optionally providing a callback if you want the sign in results
        winrt::Windows::Foundation::IAsyncAction SignInAsync(UserSignInCallback userSignInCallback, const winrt::Windows::IInspectable& dispatcher = nullptr);
        winrt::Windows::Foundation::IAsyncAction SignInSilentlyAsync(UserSignInCallback userSignInCallback, const winrt::Windows::IInspectable& dispatcher = nullptr);

        const winrt::hstring&                                       GetGamertag()           const { return m_gamertag; }
        const winrt::Microsoft::Xbox::Services::XboxLiveContext&    GetLiveContext()        const { return m_xboxLiveContext; }
        const winrt::hstring&                                       GetSandbox()            const { return m_sandbox; }
        const winrt::hstring&                                       GetServiceConfigId()    const { return m_scid; }
        uint32_t                                                    GetTitleId()            const { return m_titleId; }
        const winrt::hstring&                                       GetTitleIdHex()         const { return m_titleIdHex; }
        const ATG::XboxLiveUser&                                    GetUser()               const { return m_xboxLiveUser; }
        const winrt::Windows::System::User&                         GetWindowsUser()        const { return m_windowsUser; }
        const winrt::hstring&                                       GetXuid()               const { return m_xuid; }
        bool                                                        IsUserSignedIn()        const { return m_xboxLiveUser && m_xboxLiveUser.IsSignedIn(); }

        void SetUserSignOutCompletedCallback(std::function<void(const ATG::XboxLiveUser&)> callback) { m_onUserSignOutCompletedCallback = callback; }
        void SetWindowsUser(const winrt::Windows::System::User& windowsUser);

    private:
        void HandleSignInResult(const winrt::Microsoft::Xbox::Services::System::SignInResult& signInResult, UserSignInCallback userSignInCallback, const winrt::Windows::IInspectable& dispatcher);
        void OnSignOutCompleted(const winrt::Microsoft::Xbox::Services::System::SignOutCompletedEventArgs& args);
        void UpdateUserInfo();

        bool                                                m_autoManageUser;
        bool                                                m_isGuestUserAllowed;

        // User Info
        winrt::hstring                                      m_gamertag;
        winrt::Windows::System::User                        m_windowsUser;
        winrt::Microsoft::Xbox::Services::XboxLiveContext   m_xboxLiveContext;
        ATG::XboxLiveUser                                   m_xboxLiveUser;
        winrt::hstring                                      m_xuid;

        // Title Info
        winrt::hstring                                      m_sandbox;
        winrt::hstring                                      m_scid;
        uint32_t                                            m_titleId;
        winrt::hstring                                      m_titleIdHex;

        // Callbacks
        std::function<void(const ATG::XboxLiveUser&)>       m_onUserSignOutCompletedCallback;
    };
}