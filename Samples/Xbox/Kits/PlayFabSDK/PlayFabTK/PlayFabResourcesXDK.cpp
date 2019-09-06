//--------------------------------------------------------------------------------------
// File: PlayFabResourcesXDK.cpp
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright(c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "PlayFabResourcesXDK.h"
#include <collection.h>
#include <ppltasks.h>
#include <playfab/PlayFabSettings.h>

using namespace Concurrency;

ATG::PlayFabResources::PlayFabResources(const wchar_t* playFabTitleID, bool autoManageUser, bool isGuestUserAllowed) :
    m_autoManageUser(autoManageUser),
    m_isGuestUserAllowed(isGuestUserAllowed),
    m_playFabTitleID(playFabTitleID)
{
    PlayFab::PlayFabSettings::titleId = m_playFabTitleID.c_str();
}

void ATG::PlayFabResources::Initialize()
{
    std::weak_ptr<PlayFabResources> thisWeakPtr = shared_from_this();

    if (m_autoManageUser)
    {
        Windows::Xbox::ApplicationModel::Core::CoreApplicationContext::CurrentUserChanged +=
            ref new Windows::Foundation::EventHandler<Platform::Object^>(
                [thisWeakPtr](Platform::Object^ sender, Platform::Object^ args)
        {
            std::shared_ptr<PlayFabResources> thisSharedPtr(thisWeakPtr.lock());
            if (thisSharedPtr)
            {
                thisSharedPtr->OnCurrentUserChanged();
            }
        });

        Windows::Xbox::System::User::SignInCompleted +=
            ref new Windows::Foundation::EventHandler<Windows::Xbox::System::SignInCompletedEventArgs^>(
                [thisWeakPtr](Platform::Object^ sender, Windows::Xbox::System::SignInCompletedEventArgs^ args)
        {
            std::shared_ptr<PlayFabResources> thisSharedPtr(thisWeakPtr.lock());
            if (thisSharedPtr)
            {
                thisSharedPtr->SetCurrentUser(args->User, true);
            }
        });
    }

    Windows::Xbox::System::User::SignOutCompleted +=
        ref new Windows::Foundation::EventHandler<Windows::Xbox::System::SignOutCompletedEventArgs^>(
            [thisWeakPtr](Platform::Object^ sender, Windows::Xbox::System::SignOutCompletedEventArgs^ args)
    {
        std::shared_ptr<PlayFabResources> thisSharedPtr(thisWeakPtr.lock());
        if (thisSharedPtr)
        {
            thisSharedPtr->OnSignOutCompleted(args);
        }
    });

    Windows::Xbox::System::User::SignOutStarted +=
        ref new Windows::Foundation::EventHandler<Windows::Xbox::System::SignOutStartedEventArgs^>(
            [thisWeakPtr](Platform::Object^ sender, Windows::Xbox::System::SignOutStartedEventArgs^ args)
    {
        std::shared_ptr<PlayFabResources> thisSharedPtr(thisWeakPtr.lock());
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

void ATG::PlayFabResources::Refresh()
{
    auto currentUser = Windows::Xbox::ApplicationModel::Core::CoreApplicationContext::CurrentUser;

    if (currentUser && currentUser->IsSignedIn && (!currentUser->IsGuest || m_isGuestUserAllowed))
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

void ATG::PlayFabResources::RefreshPlayFabToken()
{
    // If no user has logged in yet, then this may be null
    if (m_xboxLiveUser == nullptr)
    {
        OutputDebugString(L"A user must be logged in to get a PlayFab token\n");
        return;
    }

    auto async = m_xboxLiveUser->GetTokenAndSignatureAsync("POST", "https://playfabapi.com", "");

    concurrency::create_task(async).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> result)
    {
        try
        {
            auto token = result.get();
            static char buffer[4000] = {};
            sprintf_s(buffer, "%ls", token->Token->Data());

            PlayFab::ClientModels::LoginWithXboxRequest request;

            request.XboxToken = buffer;
            request.CreateAccount = true;
            PlayFab::PlayFabClientAPI::LoginWithXbox(request,
                [this](const PlayFab::ClientModels::LoginResult& result, void*)
            {
                // a mutex is needed if PlayFabSettings::threadedCallbacks == true
                std::lock_guard<std::mutex> lock(m_playFabMutex);
                m_playFabLoginResult = result;
                OutputDebugString(L"PlayFab login successful\n");
                if (m_onPlayFabUserChangedCallback)
                {
                    m_onPlayFabUserChangedCallback(m_playFabLoginResult);
                }
            }
                , [this](const PlayFab::PlayFabError& error, void*)
            {
                OutputDebugString(L"There was a problem signing in to PlayFab\n");
                OutputDebugStringA(error.ErrorMessage.c_str());
                OutputDebugString(L"\n");
                OutputDebugStringA(error.HttpStatus.c_str());

                switch (error.ErrorCode)
                {
                case PlayFab::PlayFabErrorCode::PlayFabErrorInvalidXboxLiveToken:
                    OutputDebugString(L"LoginWithXbox returned InvalidXboxLiveToken. Make sure GetTokenAndSignatureAsync was given the correct URL.\n");
                    break;
                case PlayFab::PlayFabErrorCode::PlayFabErrorAccountNotFound:
                    OutputDebugString(L"LoginWithXbox returned AccountNotFound.\n");
                    break;
                case PlayFab::PlayFabErrorCode::PlayFabErrorAccountDeleted:
                    OutputDebugString(L"LoginWithXbox returned AccountDeleted. Please wait a few hours before attempting to reuse, or unlink Xbox account before deleting.\n");
                    break;
                case PlayFab::PlayFabErrorCode::PlayFabErrorInvalidPublisherId:
                    OutputDebugString(L"LoginWithXbox returned InvalidPublisherId.\n");
                    break;
                case PlayFab::PlayFabErrorCode::PlayFabErrorInvalidTitleId:
                    OutputDebugString(L"LoginWithXbox return InvalidTitleId. Make sure you used a valid PlayFab title ID when creating PlayFabResources\n");
                    break;
                case PlayFab::PlayFabErrorCode::PlayFabErrorRequestViewConstraintParamsNotAllowed:
                    OutputDebugString(L"LoginWithXbox return ViewConstraintParamsNotAllowed.\n");
                    break;
                case PlayFab::PlayFabErrorCode::PlayFabErrorXboxRejectedXSTSExchangeRequest:
                    OutputDebugString(L"LoginWithXbox return XboxRejectedXSTSExchangeRequest.\n");
                    break;
                case PlayFab::PlayFabErrorCode::PlayFabErrorXboxXASSExchangeFailure:
                    OutputDebugString(L"LoginWithXbox return XboxXASSExchangeFailure.\n");
                    break;
                default:
                {
                    wchar_t errorBuffer[200] = {};
                    swprintf_s(errorBuffer, L"Unknown PlayFab error return from XboxLogin. Code: %i\n", static_cast<int>(error.ErrorCode));
                    OutputDebugString(errorBuffer);
                }
                }

                if (m_onPlayFabLoginError)
                {
                    m_onPlayFabLoginError(error);
                }
            });

        }
        catch (Platform::Exception^ ex)
        {
            wchar_t buffer[1000] = {};
            swprintf_s(buffer, L"HRESULT: %x\nMessage: %ls\n", ex->HResult, ex->Message->Data());
            OutputDebugString(L"Failed to get Xbox Live token\n");
            OutputDebugString(buffer);
        }
    });
}

void ATG::PlayFabResources::SetCurrentUser(XboxLiveUser user, bool callUserChangedCallback)
{
    auto newXuid = user ? user->XboxUserId : nullptr;
    bool userChanged = user ? (_wcsicmp(newXuid->Data(), m_xuid.c_str()) != 0) : false;

    m_xboxLiveUser = user;
    UpdateUserInfo();

    if (userChanged)
    {
        RefreshPlayFabToken();

        if (callUserChangedCallback && m_onXboxUserChangedCallback)
        {
            m_onXboxUserChangedCallback(m_xboxLiveUser);
        }
    }
}

void ATG::PlayFabResources::OnCurrentUserChanged()
{
    auto user = Windows::Xbox::ApplicationModel::Core::CoreApplicationContext::CurrentUser;
    if (user && user != m_xboxLiveUser && user->IsSignedIn && (!user->IsGuest || m_isGuestUserAllowed))
    {
        SetCurrentUser(user, true);
    }
}

void ATG::PlayFabResources::OnSignOutCompleted(Windows::Xbox::System::SignOutCompletedEventArgs^ args)
{
    if (m_xboxLiveUser == args->User)
    {
        if (m_onUserSignOutCompletedCallback)
        {
            m_onUserSignOutCompletedCallback(args->User);
        }

        SetCurrentUser(nullptr, false);

        if (m_autoManageUser)
        {
            // If there is another user still signed in, set them as the current user
            UpdateFirstSignedInUser();
        }
    }
}

void ATG::PlayFabResources::OnSignOutStarted(Windows::Xbox::System::SignOutStartedEventArgs^ args)
{
    if (m_onUserSignOutStartedCallback)
    {
        m_onUserSignOutStartedCallback(args);
    }
}

void ATG::PlayFabResources::UpdateFirstSignedInUser()
{
    if (m_xboxLiveUser)
        return;

    for (auto user : Windows::Xbox::System::User::Users)
    {
        if (user && user->IsSignedIn && (!user->IsGuest || m_isGuestUserAllowed))
        {
            SetCurrentUser(user, true);
            break;
        }
    }
}

void ATG::PlayFabResources::UpdateUserInfo()
{
    if (m_xboxLiveUser)
    {
        m_gamertag.assign(m_xboxLiveUser->DisplayInfo->GameDisplayName->Data());
        m_xuid.assign(m_xboxLiveUser->XboxUserId->Data());
    }
    else
    {
        m_gamertag.clear();
        m_xuid.clear();
    }
}
