//--------------------------------------------------------------------------------------
// File: LiveResourcesCppWinRT_XDK.h
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

#if !defined(_XBOX_ONE) || !defined(_TITLE)
#error This file only supports Xbox One XDK apps
#endif

namespace ATG
{
    using XboxLiveUser = winrt::Windows::Xbox::System::User;

    class LiveResources : public std::enable_shared_from_this<LiveResources>
    {
    public:
        // Constructor Paramters:
        //   autoManageUser:
        //     1) sets current user to the first user it finds upon calling Initialize()
        //     2) switches to new users as they sign in
        //     3) attempts to find another signed in user when current user signs out
        //   isGuestUserAllowed: when true, guest users are valid users to use in auto user management or when resuming from suspend
        LiveResources(bool autoManageUser = true, bool isGuestUserAllowed = false);

        void Initialize();
        void Refresh(); // call when resuming from suspend

        const winrt::hstring&                                       GetGamertag()           const { return m_gamertag; }
        const winrt::Microsoft::Xbox::Services::XboxLiveContext&    GetLiveContext()        const { return m_xboxLiveContext; }
        const winrt::hstring&                                       GetSandbox()            const { return m_sandbox; }
        const winrt::hstring&                                       GetServiceConfigId()    const { return m_scid; }
        uint32_t                                                    GetTitleId()            const { return m_titleId; }
        const winrt::hstring&                                       GetTitleIdHex()         const { return m_titleIdHex; }
        const ATG::XboxLiveUser&                                    GetUser()               const { return m_xboxLiveUser; }
        const winrt::hstring&                                       GetXuid()               const { return m_xuid; }
        bool                                                        IsUserSignedIn()        const { return m_xboxLiveUser && m_xboxLiveUser.IsSignedIn(); }

        void SetCurrentUser(const ATG::XboxLiveUser& user, bool callUserChangedCallback); // typically not needed when using auto user management
        void SetUserChangedCallback(std::function<void(const ATG::XboxLiveUser&)> callback) { m_onUserChangedCallback = callback; }
        void SetUserSignOutStartedCallback(std::function<void(const winrt::Windows::Xbox::System::SignOutStartedEventArgs&)> callback) { m_onUserSignOutStartedCallback = callback; }
        void SetUserSignOutCompletedCallback(std::function<void(const ATG::XboxLiveUser&)> callback) { m_onUserSignOutCompletedCallback = callback; }

    private:
        // Event Handlers
        void OnCurrentUserChanged();
        void OnSignOutCompleted(const winrt::Windows::Xbox::System::SignOutCompletedEventArgs& args);
        void OnSignOutStarted(const winrt::Windows::Xbox::System::SignOutStartedEventArgs& args);

        void UpdateFirstSignedInUser();
        void UpdateUserInfo();

        bool                                                        m_autoManageUser;
        bool                                                        m_isGuestUserAllowed;

        // User Info
        winrt::hstring                                              m_gamertag;
        winrt::Microsoft::Xbox::Services::XboxLiveContext           m_xboxLiveContext;
        ATG::XboxLiveUser                                           m_xboxLiveUser;
        winrt::hstring                                              m_xuid;

        // Title Info
        winrt::hstring                                              m_sandbox;
        winrt::hstring                                              m_scid;
        uint32_t                                                    m_titleId;
        winrt::hstring                                              m_titleIdHex;

        // Callbacks
        std::function<void(const ATG::XboxLiveUser&)>                                       m_onUserChangedCallback;
        std::function<void(const winrt::Windows::Xbox::System::SignOutStartedEventArgs&)>   m_onUserSignOutStartedCallback;
        std::function<void(const ATG::XboxLiveUser&)>                                       m_onUserSignOutCompletedCallback;
    };
}