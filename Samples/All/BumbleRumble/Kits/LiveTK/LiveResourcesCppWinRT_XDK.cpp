//--------------------------------------------------------------------------------------
// File: LiveResourcesCppWinRT_XDK.cpp
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright(c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "LiveResourcesCppWinRT_XDK.h"

using namespace winrt::Windows::Xbox::ApplicationModel::Core;
using namespace winrt::Windows::Xbox::System;
using namespace winrt::Microsoft::Xbox::Services;
using namespace winrt::Microsoft::Xbox::Services::System;

ATG::LiveResources::LiveResources(bool autoManageUser, bool isGuestUserAllowed) :
    m_autoManageUser(autoManageUser),
    m_isGuestUserAllowed(isGuestUserAllowed),
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

void ATG::LiveResources::Initialize()
{
    std::weak_ptr<LiveResources> thisWeakPtr = shared_from_this();

    if (m_autoManageUser)
    {
        CoreApplicationContext::CurrentUserChanged([thisWeakPtr] (const winrt::Windows::Foundation::IInspectable&, const winrt::Windows::Foundation::IInspectable&)
        {
            std::shared_ptr<LiveResources> thisSharedPtr(thisWeakPtr.lock());
            if (thisSharedPtr)
            {
                thisSharedPtr->OnCurrentUserChanged();
            }
        });

        User::SignInCompleted([thisWeakPtr] (const winrt::Windows::Foundation::IInspectable&, const SignInCompletedEventArgs& args)
        {
            std::shared_ptr<LiveResources> thisSharedPtr(thisWeakPtr.lock());
            if (thisSharedPtr)
            {
                thisSharedPtr->SetCurrentUser(args.User(), true);
            }
        });
    }

    User::SignOutCompleted([thisWeakPtr] (const winrt::Windows::Foundation::IInspectable&, const SignOutCompletedEventArgs& args)
    {
        std::shared_ptr<LiveResources> thisSharedPtr(thisWeakPtr.lock());
        if (thisSharedPtr)
        {
            thisSharedPtr->OnSignOutCompleted(args);
        }
    });

    User::SignOutStarted([thisWeakPtr] (const winrt::Windows::Foundation::IInspectable&, const SignOutStartedEventArgs& args)
    {
        std::shared_ptr<LiveResources> thisSharedPtr(thisWeakPtr.lock());
        if (thisSharedPtr)
        {
            thisSharedPtr->OnSignOutStarted(args);
        }
    });

    if (m_autoManageUser)
    {
        Refresh();
        UpdateFirstSignedInUser();
    }
    else
    {
        UpdateUserInfo();
    }
}

void ATG::LiveResources::Refresh()
{
    auto currentUser = CoreApplicationContext::CurrentUser();

    if (currentUser && currentUser.IsSignedIn() && (!currentUser.IsGuest() || m_isGuestUserAllowed))
    {
        SetCurrentUser(currentUser, true);
    }
    else
    {
        SetCurrentUser(nullptr, true);

        if (m_autoManageUser)
        {
            UpdateFirstSignedInUser();
        }
    }
}

void ATG::LiveResources::SetCurrentUser(const XboxLiveUser& user, bool callUserChangedCallback)
{
    const wchar_t* newXuid = user ? user.XboxUserId().c_str() : L"";
    bool userChanged = _wcsicmp(newXuid, m_xuid.c_str()) != 0;

    m_xboxLiveUser = user;
    UpdateUserInfo();

    if (userChanged && callUserChangedCallback && m_onUserChangedCallback)
    {
        m_onUserChangedCallback(m_xboxLiveUser);
    }
}

void ATG::LiveResources::OnCurrentUserChanged()
{
    const auto& user = winrt::Windows::Xbox::ApplicationModel::Core::CoreApplicationContext::CurrentUser();
    if (user && user.XboxUserId() != m_xboxLiveUser.XboxUserId() && user.IsSignedIn() && (!user.IsGuest() || m_isGuestUserAllowed))
    {
        SetCurrentUser(user, true);
    }
}

void ATG::LiveResources::OnSignOutCompleted(const winrt::Windows::Xbox::System::SignOutCompletedEventArgs& args)
{
    if (m_xboxLiveUser && (m_xboxLiveUser.XboxUserId() == args.User().XboxUserId()))
    {
        if (m_onUserSignOutCompletedCallback)
        {
            m_onUserSignOutCompletedCallback(args.User());
        }

        SetCurrentUser(nullptr, false);

        if (m_autoManageUser)
        {
            // If there is another user still signed in, set them as the current user
            UpdateFirstSignedInUser();
        }
    }
}

void ATG::LiveResources::OnSignOutStarted(const winrt::Windows::Xbox::System::SignOutStartedEventArgs& args)
{
    if (m_onUserSignOutStartedCallback)
    {
        m_onUserSignOutStartedCallback(args);
    }
}

void ATG::LiveResources::UpdateFirstSignedInUser()
{
    if (m_xboxLiveUser)
        return;

    for (auto user : winrt::Windows::Xbox::System::User::Users())
    {
        if (user.IsSignedIn() && (!user.IsGuest() || m_isGuestUserAllowed))
        {
            SetCurrentUser(user, true);
            break;
        }
    }
}

void ATG::LiveResources::UpdateUserInfo()
{
    if (m_xboxLiveUser)
    {
        m_gamertag = m_xboxLiveUser.DisplayInfo().GameDisplayName();
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
