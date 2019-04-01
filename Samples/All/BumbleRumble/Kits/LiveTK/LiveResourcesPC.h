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

// TODO : Error so its only Win32
//#if !defined(WINAPI_FAMILY) || (WINAPI_FAMILY != WINAPI_FAMILY_APP)
//#error This file only supports UWP apps
//#endif

#include <xal/types.h>

// ***USAGE NOTE: when using this tool kit with a multi-user UWP app (MUA) on Xbox, add this to your pch.h: #define LIVETK_MULTI_USER_APP

namespace ATG
{
    using XboxLiveUser = XAL_USER_HANDLE;

    using XALOnAuthComplete = std::function<void(const std::string&, XAL_CLIENT_OPERATION, XAL_CLIENT_OPERATION_RESULT)>;
    using XALBrowserAuthCallback = std::function<void(const char *, const char *, XAL_CLIENT_OPERATION, XALOnAuthComplete)>;

    class LiveResources : public std::enable_shared_from_this<LiveResources>
    {
    public:
        // Constructor Paramters:
        //   autoManageUser: auto user management sets current user to the first user it finds upon calling Initialize()
        //   isGuestUserAllowed: provided for compatibility with XDK version; not currently used by UWP
        LiveResources(bool autoManageUser = true, bool isGuestUserAllowed = false);
        ~LiveResources();


        void Initialize(XALBrowserAuthCallback callback);
        void Tick();

        void SignIn();
        void SignInSilently();
        void SignOut();
        void SwitchUser();

        const std::wstring&                                 GetGamertag()           const { return m_gamertag; }
        std::shared_ptr<xbox::services::xbox_live_context>  GetLiveContext()        const { return m_xboxLiveContext; }
        const std::wstring&                                 GetSandbox()            const { return m_sandbox; }
        const std::wstring&                                 GetServiceConfigId()    const { return m_scid; }
        uint32_t                                            GetTitleId()            const { return m_titleId; }
        const std::wstring&                                 GetTitleIdHex()         const { return m_titleIdHex; }
        ATG::XboxLiveUser                                   GetUser()               const { return m_xboxLiveUser; }
        const std::wstring&                                 GetXuid()               const { return m_xuid; }
        bool                                                IsUserSignedIn()        const { return m_xboxLiveUser != nullptr; }

        void SetUserChangedCallback(std::function<void(ATG::XboxLiveUser)> callback) { m_onUserChangedCallback = callback; }
        void SetUserSignOutCallback(std::function<void(ATG::XboxLiveUser)> callback) { m_onUserSignOutCallback = callback; }

    private:
        static void XalTaskEventHandler(_In_ XAL_TASK_PENDING_TYPE eventType, _In_opt_ void* context);
        static void XALAddUserAsyncCallback(_In_ XALRESULT result, _In_opt_ XAL_USER_HANDLE newUser, _In_opt_ void* callbackContext);
        static void XALSwitchUserAsyncCallback(_In_ XALRESULT result, _In_ XAL_USER_HANDLE oldUser, _In_opt_ XAL_USER_HANDLE newUser, _In_opt_ void* callbackContext);
        static void XALRemoveUserAsyncCallback(_In_ XALRESULT result, _In_opt_ XAL_USER_HANDLE oldUser, _In_opt_ void* callbackContext);
        static void XALPlatformWebShowUrlEventHandler(_In_opt_ void* context, _In_ XAL_CLIENT_OPERATION operation, const char *startUrl, const char *finalUrl, bool supressUI);

        void SetCurrentUser(ATG::XboxLiveUser user);
        void UpdateUserInfo();

        bool                                                m_autoManageUser;
        bool                                                m_isGuestUserAllowed;

        // User Info
        std::wstring                                        m_gamertag;
        std::shared_ptr<xbox::services::xbox_live_context>  m_xboxLiveContext;
        ATG::XboxLiveUser                                   m_xboxLiveUser;
        std::wstring                                        m_xuid;

        // Title Info
        std::wstring                                        m_sandbox;
        std::wstring                                        m_scid;
        uint32_t                                            m_titleId;
        std::wstring                                        m_titleIdHex;

        // Callbacks
        std::function<void(ATG::XboxLiveUser)>              m_onUserChangedCallback;
        std::function<void(ATG::XboxLiveUser)>              m_onUserSignOutCallback;
        XALBrowserAuthCallback                              m_browserCallback;

        HANDLE                                              m_xalForegroundTask;
        HANDLE                                              m_xalBackgroundTask;
    };
}