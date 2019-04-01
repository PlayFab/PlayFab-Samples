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

#include "LiveResourcesUWP.h"

#include <ppltasks.h>

using namespace xbox::services;
using namespace xbox::services::system;

ATG::LiveResources::LiveResources(bool autoManageUser, bool isGuestUserAllowed) :
    m_autoManageUser(autoManageUser),
    m_isGuestUserAllowed(isGuestUserAllowed)
{
    auto appConfig = xbox_live_app_config::get_app_config_singleton();

    m_sandbox = appConfig->sandbox();
    m_scid = appConfig->scid();
    m_titleId = appConfig->title_id();

    wchar_t hexTitleId[16] = {};
    swprintf_s(hexTitleId, L"0x%08X", m_titleId);
    m_titleIdHex.assign(hexTitleId);
}

void ATG::LiveResources::Initialize(UserSignInCallback userSignInCallback, Platform::Object^ dispatcher)
{
    m_xboxLiveUser = std::make_shared<xbox_live_user>();

    std::weak_ptr<LiveResources> thisWeakPtr = shared_from_this();
    xbox_live_user::add_sign_out_completed_handler([thisWeakPtr](const sign_out_completed_event_args& args)
    {
        std::shared_ptr<LiveResources> thisSharedPtr(thisWeakPtr.lock());
        if (thisSharedPtr)
        {
            thisSharedPtr->OnSignOutCompleted(args);
        }
    });

    if (m_autoManageUser)
    {
        SignInSilently(userSignInCallback, dispatcher);
    }
    else
    {
        UpdateUserInfo();
    }
}

void ATG::LiveResources::Refresh(UserSignInCallback userSignInCallback, Platform::Object^ dispatcher)
{
    SignInSilently(userSignInCallback, dispatcher);
}

void ATG::LiveResources::SignIn(UserSignInCallback userSignInCallback, Platform::Object^ dispatcher)
{
    std::weak_ptr<LiveResources> thisWeakPtr = shared_from_this();
    m_xboxLiveUser->signin(dispatcher ? dispatcher : Windows::UI::Core::CoreWindow::GetForCurrentThread()->Dispatcher)
        .then([thisWeakPtr, userSignInCallback, dispatcher](xbox_live_result<sign_in_result> result) // use task_continuation_context::use_current() to make the continuation task running in current apartment 
    {
        std::shared_ptr<LiveResources> thisSharedPtr(thisWeakPtr.lock());
        if (thisSharedPtr)
        {
            thisSharedPtr->HandleSignInResult(result, userSignInCallback, dispatcher);
        }
    }, concurrency::task_continuation_context::use_current());
}

void ATG::LiveResources::SignInSilently(UserSignInCallback userSignInCallback, Platform::Object^ dispatcher)
{
	std::weak_ptr<LiveResources> thisWeakPtr = shared_from_this();
	m_xboxLiveUser->signin_silently(dispatcher ? dispatcher : Windows::UI::Core::CoreWindow::GetForCurrentThread()->Dispatcher)
	    .then([thisWeakPtr, userSignInCallback, dispatcher](xbox_live_result<sign_in_result> result) // use task_continuation_context::use_current() to make the continuation task running in current apartment 
	{
	    std::shared_ptr<LiveResources> thisSharedPtr(thisWeakPtr.lock());
	    if (thisSharedPtr)
	    {
	        thisSharedPtr->HandleSignInResult(result, userSignInCallback, dispatcher);
	    }
	}, concurrency::task_continuation_context::use_current());
}

void ATG::LiveResources::SetWindowsUser(Windows::System::User^ windowsUser)
{
    m_windowsUser = windowsUser;
    
#ifdef LIVETK_MULTI_USER_APP
    {
        m_xboxLiveUser = std::make_shared<xbox_live_user>(windowsUser);
        UpdateUserInfo();
    }
#endif
}

void ATG::LiveResources::HandleSignInResult(xbox_live_result<sign_in_result>& signInResult, UserSignInCallback userSignInCallback, Platform::Object^ dispatcher)
{
    UpdateUserInfo();

    if (!signInResult.err())
    {
        auto signInStatus = signInResult.payload().status();
        if (signInStatus == sign_in_status::success)
        {
            auto appConfig = xbox_live_app_config::get_app_config_singleton();
            m_sandbox = appConfig->sandbox(); // available in UWP once user has signed in
        }
		else if (signInStatus == sign_in_status::user_interaction_required && m_autoManageUser)
		{
			SignIn(userSignInCallback, dispatcher);
		}
    }

    if (userSignInCallback)
    {
        userSignInCallback(signInResult);
    }
}

void ATG::LiveResources::OnSignOutCompleted(const xbox::services::system::sign_out_completed_event_args& args)
{
    UpdateUserInfo();

    if (m_onUserSignOutCompletedCallback)
    {
        m_onUserSignOutCompletedCallback(args.user());
    }
}

void ATG::LiveResources::UpdateUserInfo()
{
    if (m_xboxLiveUser)
    {
        m_gamertag.assign(m_xboxLiveUser->gamertag());
        m_xuid.assign(m_xboxLiveUser->xbox_user_id());

        if (m_xboxLiveUser->is_signed_in())
        {
            m_xboxLiveContext = std::make_shared<xbox_live_context>(m_xboxLiveUser);
        }
        else
        {
            m_xboxLiveContext.reset();
        }
    }
    else
    {
        m_gamertag.clear();
        m_xuid.clear();
        m_xboxLiveContext.reset();
    }
}
