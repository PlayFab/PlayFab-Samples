//--------------------------------------------------------------------------------------
// File: LiveResourcesUWP.cpp
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright(c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"



#include <xal/xal.h>
#include <xal/xal_platform.h>
#define HC_API_NONE
#include <httpClient/httpClient.h>

#ifndef DEBUGLOG
#define DEBUGLOG(x)
#endif


#include "LiveResourcesPC.h"

#include <ppltasks.h>

using namespace xbox::services;
using namespace xbox::services::system;

// Fwd declares
static _Ret_maybenull_ _Post_writable_byte_size_(size) void* __cdecl XalMemAlloc(_In_ size_t size);
static void __cdecl XalMemFree(_In_ _Post_invalid_ void* pointer);
const wchar_t *ConvertXalResultToString(XALRESULT hr);

ATG::LiveResources::LiveResources(bool autoManageUser, bool isGuestUserAllowed) :
    m_autoManageUser(autoManageUser),
    m_isGuestUserAllowed(isGuestUserAllowed),
    m_xboxLiveUser(nullptr),
    m_xalForegroundTask(CreateEvent(nullptr, false, false, nullptr)),
    m_xalBackgroundTask(CreateEvent(nullptr, false, false, nullptr))
{
    auto appConfig = xbox_live_app_config::get_app_config_singleton();

    m_sandbox = appConfig->sandbox();
    m_scid = appConfig->scid();
    m_titleId = appConfig->title_id();

    wchar_t hexTitleId[16] = {};
    swprintf_s(hexTitleId, L"0x%08X", m_titleId);
    m_titleIdHex.assign(hexTitleId);
}

ATG::LiveResources::~LiveResources()
{
    if (m_xboxLiveUser != nullptr)
    {
        XalUserCloseHandle(m_xboxLiveUser);
        m_xboxLiveUser = nullptr;
    }
    XalGlobalCleanup();
}

void ATG::LiveResources::Initialize(XALBrowserAuthCallback callback)
{
    m_browserCallback = callback;

    // TODO: Make this configurable
    XAL_INIT_ARGS xalInitArgs = {};
    xalInitArgs.ClientId = "000000004414D26C";
    xalInitArgs.TitleId = m_titleId;
    xalInitArgs.Sandbox = "XDKS.1";
    xalInitArgs.TitleType = XAL_TITLE_TYPE::XAL_TITLE_TYPE_THIRD_PARTY;

    XALRESULT hr = XalGlobalInitialize(&xalInitArgs);
    DEBUGLOG(L"XalGlobalInitialize: %S\n", ConvertXalResultToString(hr));

    XalRegisterTaskEventHandler(static_cast<void*>(this), &LiveResources::XalTaskEventHandler);

    hr = XalPlatformWebSetEventHandler(
        static_cast<void*>(this),
        ATG::LiveResources::XALPlatformWebShowUrlEventHandler
    );

    DEBUGLOG(L"XalPlatformWebSetEventHandler: %S\n", ConvertXalResultToString(hr));

    if (m_autoManageUser)
    {
        SignInSilently();
    }
}

void ATG::LiveResources::Tick()
{
    HANDLE hEvents[2] =
    {
        m_xalBackgroundTask,
        m_xalForegroundTask
    };

    while(XalAnyBackgroundTaskPending())
    {
        XalProcessNextBackgroundTask();
    }

    while (XalAnyForegroundTaskPending())
    {
        XalProcessNextForegroundTask(); 
    }
}

void ATG::LiveResources::SignIn()
{
    XAL_USER_HANDLE users[10];
    uint32_t currUsers = 0;
    XalGetCurrentUsers(10, users, &currUsers);

    XALRESULT hr = XalAddUserAsync(
        static_cast<void*>(this),
        XALAddUserAsyncCallback
    );
    DEBUGLOG(L"XalAddUserAsync: %S\n", ConvertXalResultToString(hr));
}

void ATG::LiveResources::SignInSilently()
{
    XALRESULT hr = XalTryAddFirstUserSilentlyAsync(
        static_cast<void*>(this),
        XALAddUserAsyncCallback);
    DEBUGLOG(L"XalTryAddFirstUserSilentlyAsync: %S\n", ConvertXalResultToString(hr));
}

void ATG::LiveResources::SignOut()
{

    if (m_xboxLiveUser != nullptr)
    {
        if (XalRemoveUserAsyncIsPresent())
        {
            XALRESULT hr = XalRemoveUserAsync(m_xboxLiveUser, static_cast<void*>(this), XALRemoveUserAsyncCallback);
            DEBUGLOG(L"XalRemoveUser: %S\n", ConvertXalResultToString(hr));
            XalUserCloseHandle(m_xboxLiveUser);
            m_xboxLiveUser = nullptr;

            UpdateUserInfo();
        }
    }

    /*m_xboxLiveContext->settings()->add_service_call_routed_handler([](const xbox::services::xbox_service_call_routed_event_args &args) {
        args.http_status()
    }*/
}

void ATG::LiveResources::SwitchUser()
{
    if (XalSwitchUserAsyncIsPresent())
    {
        XALRESULT hr = XalSwitchUserAsync(
            m_xboxLiveUser,
            static_cast<void*>(this),
            XALSwitchUserAsyncCallback
        );
        DEBUGLOG(L"XalAddUserAsync: %S\n", ConvertXalResultToString(hr));
    }
}

void ATG::LiveResources::SetCurrentUser(XboxLiveUser user)
{
    uint64_t newXuid = 0;
    XalUserGetId(user, &newXuid);

    bool userChanged = std::to_wstring(newXuid) != m_xuid;

    m_xboxLiveUser = user;
    XalUserDuplicateHandle(m_xboxLiveUser);
    UpdateUserInfo();

    if (userChanged && m_onUserChangedCallback)
    {
        m_onUserChangedCallback(m_xboxLiveUser);
    }
}

void ATG::LiveResources::UpdateUserInfo()
{
    if (m_xboxLiveUser)
    {
        XAL_GAMERTAG gamertag;
        XalUserGetGamertag(m_xboxLiveUser, &gamertag);
        m_gamertag.assign(gamertag.Text, gamertag.Text + strlen(gamertag.Text));

        uint64_t xuid;
        XalUserGetId(m_xboxLiveUser, &xuid);

        m_xuid.assign(std::to_wstring(xuid));

        m_xboxLiveContext = std::make_shared<xbox_live_context>(m_xboxLiveUser);
    }
    else
    {
        m_gamertag.clear();
        m_xuid.clear();
        m_xboxLiveContext.reset();
    }
}

void ATG::LiveResources::XALAddUserAsyncCallback(
    _In_ XALRESULT result,
    _In_opt_ XAL_USER_HANDLE newUser,
    _In_opt_ void* callbackContext

)
{
    auto liveResourses = static_cast<ATG::LiveResources*>(callbackContext);
    if (liveResourses == nullptr) return;

    DEBUGLOG(L"XalAddUserAsyncCallback: %S\n", ConvertXalResultToString(result));
    if (result == XAL_OK)
    {
        liveResourses->SetCurrentUser(newUser);
    }
}

void ATG::LiveResources::XALSwitchUserAsyncCallback(
    _In_ XALRESULT result,
    _In_ XAL_USER_HANDLE oldUser,
    _In_opt_ XAL_USER_HANDLE newUser,
    _In_opt_ void* callbackContext
)
{
    UNREFERENCED_PARAMETER(oldUser);
    auto liveResourses = static_cast<ATG::LiveResources*>(callbackContext);
    if (liveResourses == nullptr) return;

    DEBUGLOG(L"XAL_SwitchUserAsyncCallback: %S\n", ConvertXalResultToString(result));
    if (result == XAL_OK)
    {
        liveResourses->SetCurrentUser(newUser);
    }
}

void ATG::LiveResources::XALRemoveUserAsyncCallback(
    _In_ XALRESULT result,
    _In_opt_ XAL_USER_HANDLE oldUser,
    _In_opt_ void* callbackContext
)
{
    auto liveResources = static_cast<ATG::LiveResources*>(callbackContext);
    if (liveResources == nullptr) return;

    if (liveResources->m_onUserSignOutCallback)
        liveResources->m_onUserSignOutCallback(oldUser);
}

void ATG::LiveResources::XALPlatformWebShowUrlEventHandler(
    _In_opt_ void* context,
    _In_ XAL_CLIENT_OPERATION operation,
    const char *startUrl,
    const char *finalUrl, bool
)
{
    auto liveResources = static_cast<ATG::LiveResources*>(context);
    if (liveResources == nullptr) return;

    liveResources->m_browserCallback(startUrl, finalUrl, operation,
        [](const std::string &responseUrl, XAL_CLIENT_OPERATION operation, XAL_CLIENT_OPERATION_RESULT result)
    {
        XALRESULT hr = XalPlatformWebShowUrlComplete(
            operation,
            result,
            responseUrl.c_str());
    });

    //pplx::create_task(
    //    [weakLiveResources, startUrl, finalUrl, operation]()
    //{

    //    std::string response;
    //    XAL_CLIENT_OPERATION_RESULT result;

    //    auto pThis = weakLiveResources.lock();

    //    if (!pThis)
    //    {
    //        result = XAL_CLIENT_OPERATION_RESULT::XAL_CLIENT_OPERATION_RESULT_FAILURE;
    //    }
    //    else
    //    {

    //        // Show a web browser somehow starting at the startUrl, and stopping when the finalUrl is in the path.
    //        // Have the web browser return full URL it gets which will contain the user account token 
    //        // and pass that on to XAL

    //        

    //        // This sample launches a simple external C# process to show the URL 
    //        // but preferable the web page is shown inside the game.
    //        //xal_browser_launch::OnShow(startUrl, finalUrl, &response, &result);
    //    }
    //    /*xsapiState->m_consoleLog->Format(L"Xal_PlatformWebShowUrlEventHandler:\n\n");
    //    xsapiState->m_consoleLog->Format(L"startUrl=%S\n\n", startUrl.Text);
    //    xsapiState->m_consoleLog->Format(L"finalUrl=%S\n\n", finalUrl.Text);
    //    xsapiState->m_consoleLog->Format(L"response=%S\n\n", response.c_str());*/

    //    XALRESULT hr = XalPlatformWebShowUrlComplete(
    //        operation,
    //        result,
    //        XAL_STRING{ response.size(), response.data() }
    //    );
    //    //xsapiState->m_consoleLog->Format(L"XalPlatformWebShowUrlComplete: %S\n", ConvertXalResultToString(hr).c_str());
    //});

}

void ATG::LiveResources::XalTaskEventHandler(
    _In_ XAL_TASK_PENDING_TYPE eventType,
    _In_opt_ void* context
)
{
    auto liveResources = reinterpret_cast<ATG::LiveResources*>(context);

    switch (eventType)
    {
    case XAL_TASK_PENDING_TYPE::XAL_TASK_PENDING_BACKGROUND:
        SetEvent(liveResources->m_xalForegroundTask);
        break;

    case XAL_TASK_PENDING_TYPE::XAL_TASK_PENDING_FOREGROUND:
        SetEvent(liveResources->m_xalBackgroundTask);
        break;
    }
}


static _Ret_maybenull_ _Post_writable_byte_size_(size) void* __cdecl XalMemAlloc(_In_ size_t size)
{
    return new (std::nothrow) int8_t[size];
}

static void __cdecl XalMemFree(_In_ _Post_invalid_ void* pointer)
{
    delete[] pointer;
}

const wchar_t *ConvertXalResultToString(XALRESULT hr)
{
    switch (hr)
    {
    case XAL_OK: return L"XAL_OK";
    case XAL_E_FAIL: return L"XAL_E_FAIL";
    case XAL_E_POINTER: return L"XAL_E_POINTER";
    case XAL_E_INVALIDARG: return L"XAL_E_INVALIDARG";
    case XAL_E_OUTOFMEMORY: return L"XAL_E_OUTOFMEMORY";
    case XAL_E_BUFFERTOOSMALL: return L"XAL_E_BUFFERTOOSMALL";
    case XAL_E_NOTINITIALIZED: return L"XAL_E_NOTINITIALIZED";
    case XAL_E_FEATURENOTPRESENT: return L"XAL_E_FEATURENOTPRESENT";
    case XAL_E_ALREADYINITIALIZED: return L"XAL_E_ALREADYINITIALIZED";
    case XAL_E_NOUSERFOUND: return L"XAL_E_NOUSERFOUND";
    case XAL_E_USERINVALID: return L"XAL_E_USERINVALID";
    case XAL_E_USERREMOVED: return L"XAL_E_USERREMOVED";
    case XAL_E_TOKENEXPIRED: return L"XAL_E_TOKENEXPIRED";
    //case XAL_E_TOOMANYUSERS: return L"XAL_E_TOOMANYUSERS";
    case XAL_E_NETWORK: return L"XAL_E_NETWORK";
    case XAL_E_CLIENTERROR: return L"XAL_E_CLIENTERROR";
    default: return L"unknown";
    }
}
