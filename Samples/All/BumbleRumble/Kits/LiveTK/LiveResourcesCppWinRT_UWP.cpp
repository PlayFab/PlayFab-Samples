//--------------------------------------------------------------------------------------
// File: LiveResourcesCppWinRT_UWP.cpp
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright(c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "LiveResourcesCppWinRT_UWP.h"

#include "winrt/Windows.UI.Core.h"

using namespace winrt::Microsoft::Xbox::Services;
using namespace winrt::Microsoft::Xbox::Services::System;

ATG::LiveResources::LiveResources(bool autoManageUser, bool isGuestUserAllowed) :
    m_autoManageUser(autoManageUser),
    m_isGuestUserAllowed(isGuestUserAllowed),
    m_windowsUser(nullptr),
    m_xboxLiveContext(nullptr),
    m_xboxLiveUser(nullptr)
{
    auto appConfig = XboxLiveAppConfiguration::SingletonInstance();

    m_sandbox = appConfig.Sandbox();
    m_scid = appConfig.ServiceConfigurationId();
    m_titleId = appConfig.TitleId();

    wchar_t hexTitleId[16] = {};
    swprintf_s(hexTitleId, L"0x%08X", m_titleId);
    m_titleIdHex = hexTitleId;
}

void ATG::LiveResources::Initialize(UserSignInCallback userSignInCallback, const winrt::Windows::IInspectable& dispatcher)
{
    m_xboxLiveUser = XboxLiveUser();

    std::weak_ptr<LiveResources> thisWeakPtr = shared_from_this();
    XboxLiveUser::SignOutCompleted([thisWeakPtr](const winrt::Windows::IInspectable&, const SignOutCompletedEventArgs& args)
    {
        std::shared_ptr<LiveResources> thisSharedPtr(thisWeakPtr.lock());
        if (thisSharedPtr)
        {
            thisSharedPtr->OnSignOutCompleted(args);
        }
    });

    if (m_autoManageUser)
    {
        SignInSilentlyAsync(userSignInCallback, dispatcher); // exceptions are swallowed by co-routine handler
    }
    else
    {
        UpdateUserInfo();
    }
}

void ATG::LiveResources::Refresh(UserSignInCallback userSignInCallback, const winrt::Windows::IInspectable& dispatcher)
{
    SignInSilentlyAsync(userSignInCallback, dispatcher); // exceptions are swallowed by co-routine handler
}

winrt::Windows::Foundation::IAsyncAction ATG::LiveResources::SignInAsync(UserSignInCallback userSignInCallback, const winrt::Windows::IInspectable& dispatcher)
{
    auto result = co_await m_xboxLiveUser.SignInAsync(dispatcher ? dispatcher : winrt::Windows::UI::Core::CoreWindow::GetForCurrentThread().Dispatcher());

    HandleSignInResult(result, userSignInCallback, dispatcher);
}

winrt::Windows::Foundation::IAsyncAction ATG::LiveResources::SignInSilentlyAsync(UserSignInCallback userSignInCallback, const winrt::Windows::IInspectable& dispatcher)
{
    auto result = co_await m_xboxLiveUser.SignInSilentlyAsync(dispatcher ? dispatcher : winrt::Windows::UI::Core::CoreWindow::GetForCurrentThread().Dispatcher());

    HandleSignInResult(result, userSignInCallback, dispatcher);
}

void ATG::LiveResources::SetWindowsUser(const winrt::Windows::System::User& windowsUser)
{
    m_windowsUser = windowsUser;

#ifdef LIVETK_MULTI_USER_APP
    {
        m_xboxLiveUser = XboxLiveUser(windowsUser);
        UpdateUserInfo();
    }
#endif
}

void ATG::LiveResources::HandleSignInResult(const SignInResult& signInResult, UserSignInCallback userSignInCallback, const winrt::Windows::IInspectable& dispatcher)
{
    UpdateUserInfo();

    if (signInResult.Status() == SignInStatus::Success)
    {
        auto appConfig = XboxLiveAppConfiguration::SingletonInstance();
        m_sandbox = appConfig.Sandbox(); // available in UWP once user has signed in
    }
	else if (signInResult.Status() == SignInStatus::UserInteractionRequired && m_autoManageUser)
	{
		SignIn(userSignInCallback, dispatcher);
	}

    if (userSignInCallback)
    {
        userSignInCallback(signInResult);
    }
}

void ATG::LiveResources::OnSignOutCompleted(const SignOutCompletedEventArgs& args)
{
    UpdateUserInfo();

    if (m_onUserSignOutCompletedCallback)
    {
        m_onUserSignOutCompletedCallback(args.User());
    }
}

void ATG::LiveResources::UpdateUserInfo()
{
    if (m_xboxLiveUser)
    {
        m_gamertag = m_xboxLiveUser.Gamertag();
        m_xuid = m_xboxLiveUser.XboxUserId();

        if (m_xboxLiveUser.IsSignedIn())
        {
            m_xboxLiveContext = XboxLiveContext(m_xboxLiveUser);
        }
        else
        {
            m_xboxLiveContext = nullptr;
        }
    }
    else
    {
        m_gamertag.clear();
        m_xuid.clear();
        m_xboxLiveContext = nullptr;
    }
}
