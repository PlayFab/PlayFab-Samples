//--------------------------------------------------------------------------------------
// SimplePlayFabAuth.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "SimplePlayFabAuth.h"

#include "ATGColors.h"

extern void ExitSample();

using namespace DirectX;
using namespace PlayFab;
using namespace PlayFab::ClientModels;
using namespace Windows::Xbox::System;

using Microsoft::WRL::ComPtr;

Sample::Sample() :
    m_frame(0)
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();

    m_liveResources = std::make_shared<ATG::LiveResources>();
    m_liveInfoHUD = std::make_unique<ATG::LiveInfoHUD>(L"Simple PlayFab Auth Sample");
}

// Initialize the Direct3D resources required to run.
void Sample::Initialize(IUnknown* window)
{
    m_gamePad = std::make_unique<GamePad>();

    m_deviceResources->SetWindow(window);

    m_deviceResources->CreateDeviceResources();  
    CreateDeviceDependentResources();

    m_deviceResources->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();

    m_liveResources->SetUserChangedCallback([this](ATG::XboxLiveUser)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
    });

    m_liveResources->SetUserSignOutCompletedCallback([this](ATG::XboxLiveUser)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
    });

    m_liveResources->Initialize();
    m_liveInfoHUD->Initialize(m_liveResources->GetLiveContext());

    User::UserAdded +=
        ref new Windows::Foundation::EventHandler<UserAddedEventArgs^>([this](Platform::Object^ sender, UserAddedEventArgs^ args)
    {
        m_console->Write(L"UserAdded event fired\n");
        m_users = User::Users;
    });

    User::UserRemoved +=
        ref new Windows::Foundation::EventHandler<UserRemovedEventArgs^>([this](Platform::Object^ sender, UserRemovedEventArgs^ args)
    {
        m_console->Write(L"UserRemoved event fired\n");
        if (m_currentUser == nullptr || m_currentUser->Id == args->User->Id)
        {
            SetCurrentUser(nullptr);
        }

        m_users = User::Users;
    });

    m_playFabLoggedIn = false;
    m_playFabDisplayName[0] = '\0';

    // This must be set for PlayFab APIs to work. It can be found in your PlayFab developer dashboard.
    PlayFabSettings::titleId = L"DC0";

    auto user = Windows::Xbox::ApplicationModel::Core::CoreApplicationContext::CurrentUser;
    m_users = User::Users;

    if (user == nullptr &&m_users->Size > 0)
        user = m_users->GetAt(0);

    SetCurrentUser(user);
}

void Sample::OnPlayFabError(const PlayFab::PlayFabError& error, void* custom)
{
    DX::TextConsole* console = reinterpret_cast<DX::TextConsole*>(custom);
    console->Write(L"An error occurred with a PlayFab API\n");
    wchar_t buffer[2000] = {};
    swprintf_s(buffer, L"PlayFab error code: %i\n%S\n%S\n%S\nHTTP error: %i\n%S\n",
        error.ErrorCode,
        error.ErrorName.c_str(),
        error.ErrorMessage.c_str(),
        error.UrlPath.c_str(),
        error.HttpCode,
        error.HttpStatus.c_str());

    console->Write(buffer);
}

// Link an Xbox account to a signed in PlayFab account. If a new PlayFab account is created it is not associated
//  with an Xbox account until this is called.
void Sample::LinkWithExistingPlayFabAccount(IUser^ xboxUser)
{
    auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(L"PlayFab ID", L"Login name", L"Provide a login ID for PlayFab. Must be 3-20 characters long", Windows::Xbox::UI::VirtualKeyboardInputScope::Alphanumeric);
    concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
    {
        try
        {
            Platform::String^ userName = task.get();
            auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(L"", L"Password", L"Provide a password for PlayFab. Must be 6-100 characters long", Windows::Xbox::UI::VirtualKeyboardInputScope::Password);
            concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
            {
                try
                {
                    Platform::String^ password = task.get();

                    // Now that we have the user's login name and password, login with the PlayFab API, then link
                    //  that to the logged in Xbox account. Once the account is linked, then the LoginWithXbox
                    //  API can be used with the Xbox token and manual input will no longer be needed.
                    ClientModels::LoginWithPlayFabRequest loginRequest;
                    loginRequest.Password = ShortenString(password->Data());
                    loginRequest.Username = ShortenString(userName->Data());

                    PlayFabClientAPI::LoginWithPlayFab(loginRequest, [=](const LoginResult&, void*)
                    {
                        auto async = xboxUser->GetTokenAndSignatureAsync("POST", "https://playfabapi.com", "");
                        m_playFabLoggedIn = true;

                        concurrency::create_task(async).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> task)
                        {
                            try
                            {
                                auto xboxTokenResult = task.get();

                                LinkXboxAccountRequest linkRequest;
                                linkRequest.XboxToken = ShortenString(xboxTokenResult->Token->Data());

                                PlayFabClientAPI::LinkXboxAccount(linkRequest, [this](const LinkXboxAccountResult&, void*)
                                {
                                    m_console->Write(L"Account link successful\n");
                                }, OnPlayFabError, m_console.get());
                            }
                            catch (Platform::Exception^ Ex)
                            {
                                Sample::HandleException(Ex, __FUNCTIONW__);
                            }
                        }); // create_task for GetTokenAndSignatureAsync

                    }, Sample::OnPlayFabError, m_console.get()); // LoginWithPlayFab

                }
                catch (Platform::Exception^ Ex)
                {
                    Sample::HandleException(Ex, __FUNCTIONW__);
                }

            }); // create_task for ShowVirtualKeyboardAsync

        }
        catch (Platform::Exception^ Ex)
        {
            Sample::HandleException(Ex, __FUNCTIONW__);
        }

    });// create_task for ShowVirtualKeyboardAsync
}

// Register a new PlayFab user. PlayFab enforces length requirements for all input strings. The flow for this
//  function is to show the virtual keyboard three times to get a display name, a login username, and a login
//  password, then use that information to create the PlayFab account. Once the account is created, then get
//  the Xbox token for the player with GetTokenAndSignatureAsync and use that to link the new account to their
//  Xbox profile. This is useful because it allows the player to choose a display name for their account at
//  the time it is created.
void Sample::RegisterForPlayFab(IUser^ xboxUser)
{
    auto gamerTag = xboxUser->DisplayInfo->Gamertag;
    auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(gamerTag, L"Display Name", L"Provide a display name for your PlayFab account. Must be 3-25 characters long", Windows::Xbox::UI::VirtualKeyboardInputScope::Alphanumeric);
    concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
    {
        try
        {
            Platform::String^ displayName = task.get();
            auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(gamerTag, L"Login name", L"Provide a login ID for PlayFab. Must be 3-20 characters long", Windows::Xbox::UI::VirtualKeyboardInputScope::Alphanumeric);
            concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
            {
                try
                {
                    Platform::String^ signinName = task.get();
                    auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(L"", L"Password", L"Provide a password for PlayFab. Must be 6-100 characters long", Windows::Xbox::UI::VirtualKeyboardInputScope::Password);
                    concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
                    {
                        try
                        {
                            Platform::String^ password = task.get();

                            RegisterPlayFabUserRequest regRequest;
                            regRequest.DisplayName = ShortenString(displayName->Data());    // Must be 3-25 characters
                            regRequest.Username = ShortenString(signinName->Data());        // Must be 3-20 characters
                            regRequest.Password = ShortenString(password->Data());          // Must be 6-100 characters
                            regRequest.RequireBothUsernameAndEmail = false;

                            if (displayName->Length() < 3 || displayName->Length() > 25)
                            {
                                m_console->Write(L"User Name must be 3-25 characters long\n");
                                return;
                            }

                            if (signinName->Length() < 3 || signinName->Length() > 20)
                            {
                                m_console->Write(L"Login ID must be 3-20 characters long\n");
                                return;
                            }

                            if (password->Length() < 6 || password->Length() > 100)
                            {
                                m_console->Write(L"Password must be 6-100 characters long\n");
                                return;
                            }

                            PlayFabClientAPI::RegisterPlayFabUser(regRequest, [=](const RegisterPlayFabUserResult&, void*)
                            {
                                m_console->Write(L"PlayFabClientAPI::RegisterPlayFabUser completed successfully\n");

                                // Now that a new PlayFab account has been registered, link to with with the logged in Xbox user
                                auto async = xboxUser->GetTokenAndSignatureAsync("POST", "https://playfabapi.com", "");

                                concurrency::create_task(async).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> task)
                                {
                                    try
                                    {
                                        auto result = task.get();

                                        LinkXboxAccountRequest linkRequest;
                                        linkRequest.XboxToken = ShortenString(result->Token->Data());

                                        PlayFabClientAPI::LinkXboxAccount(linkRequest, [this,displayName](const LinkXboxAccountResult&, void*)
                                        {
                                            m_console->Write(L"Account link successful\n");
                                            wcscpy_s(m_playFabDisplayName, displayName->Data());

                                        }, OnPlayFabError, m_console.get()); // LinkXboxAccount

                                    }
                                    catch (Platform::Exception^ Ex)
                                    {
                                        Sample::HandleException(Ex, __FUNCTIONW__);
                                    }
                                }); // create_task for GetTokenAndSignatureAsync


                            }, Sample::OnPlayFabError, m_console.get()); // RegisterPlayFabUser
                        }
                        catch (Platform::Exception^ Ex)
                        {
                            Sample::HandleException(Ex, __FUNCTIONW__);
                        }
                    }); // create_task for ShowVirtualKeyboardAsync

                }
                catch (Platform::Exception^ Ex)
                {
                    Sample::HandleException(Ex, __FUNCTIONW__);
                }
            }); // create_task for ShowVirtualKeyboardAsync

        }
        catch (Platform::Exception^ Ex)
        {
            Sample::HandleException(Ex, __FUNCTIONW__);
        }
    }); // create_task for ShowVirtualKeyboardAsync
}

// This logs a player in to PlayFab. Once LoginWithXbox is executed, a PlayFab token will be stored in
//  the PlayFab settings until another user is logged in. Tokens for multiple players can be managed by
//  client code to allow multiple PlayFab logins at once by setting PlayFabSettings::clientSessionTicket
//  with the token associated with the correct user before making PlayFab API calls. These tokens
//  must expire after 4 hours and must be refreshed by client code. There is no need to log a PlayFab
//  user out once a play session is over.
void Sample::RefreshPlayFabToken(IUser^ xboxUser)
{
    auto async = xboxUser->GetTokenAndSignatureAsync("POST", "https://playfabapi.com", "");

    concurrency::create_task(async).then([this](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> task)
    {
        try
        {
            auto result = task.get();
            
            LoginWithXboxRequest request;
            auto token = result->Token;
            request.XboxToken = ShortenString(token->Data());

            // This sample will only log someone in to PlayFab if they already have an account
            //  associated with their Xbox account. Setting this to 'true' will automaticalle 
            //  create a new PlayFab account if one does not already exist for your Xbox account.
            request.CreateAccount = false;
            
            PlayFabClientAPI::LoginWithXbox(request, [this](const LoginResult& result, void*)
            {
                m_console->Write(L"PlayFab signin successful\n");
                m_playFabLoggedIn = true;

                GetPlayerProfileRequest request;
                request.PlayFabId = result.PlayFabId;

                PlayFabClientAPI::GetPlayerProfile(request, [this](const GetPlayerProfileResult& result, void*)
                {
                    m_console->Write(L"PlayFabClientAPI::GetPlayerProfile successful\n");
                    swprintf_s(m_playFabDisplayName, L"%S", result.PlayerProfile->DisplayName.c_str());
                }, Sample::OnPlayFabError, m_console.get());
            }, OnPlayFabError, m_console.get()); // LoginWithXbox

        }
        catch (Platform::Exception^ Ex)
        {
            Sample::HandleException(Ex, __FUNCTIONW__);
        }
    }); // create_task for GetTokenAndSignatureAsync
}

// PlayFab allows a title to save a unique display name for every game a user plays. Each display name is distinct in
//  each title. This can later be queried from the user's info with GetAccountInfo or GetPlayerProfile.
void Sample::UpdatePlayFabDisplayName()
{
    auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(m_currentUser->DisplayInfo->Gamertag, L"Display Name", L"Choose the name you would like to use for this game", Windows::Xbox::UI::VirtualKeyboardInputScope::Alphanumeric);
    concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
    {
        try
        {
            Platform::String^ displayName = task.get();
            UpdateUserTitleDisplayNameRequest request;
            request.DisplayName = ShortenString(displayName->Data());

            PlayFabClientAPI::UpdateUserTitleDisplayName(request, [=](const UpdateUserTitleDisplayNameResult&, void*)
            {
                m_console->Write(L"Display name successfully updated: ");
                m_console->WriteLine(displayName->Data());
                wcscpy_s(m_playFabDisplayName, displayName->Data());
            }, OnPlayFabError, m_console.get());
        }
        catch (Platform::Exception^ Ex)
        {
            Sample::HandleException(Ex, __FUNCTIONW__);
        }
    });
}

void Sample::SetCurrentUser(IUser^ xboxUser)
{
    // If the current user has changed, mark this user as signed out of PlayFab until a new token has been retrieved
    if (m_currentUser != nullptr && xboxUser != nullptr &&
        m_currentUser->Id != xboxUser->Id)
    {
        m_playFabLoggedIn = false;
    }

    m_currentUser = xboxUser;
    if (m_currentUser == nullptr)
    {
        m_playFabDisplayName[0] = '\0';
        m_playFabLoggedIn = false;
    }
    else
    {
        RefreshPlayFabToken(m_currentUser);
    }
}

void Sample::ChangeAccount()
{
    auto async = Windows::Xbox::UI::SystemUI::ShowAccountPickerAsync(nullptr, Windows::Xbox::UI::AccountPickerOptions::None);

    concurrency::create_task(async).then([this](concurrency::task<Windows::Xbox::UI::AccountPickerResult^> task)
    {
        try
        {
            auto result = task.get();
            SetCurrentUser(result->User);
        }
        catch (Platform::Exception^ Ex)
        {
            Sample::HandleException(Ex, __FUNCTIONW__);
        }
    });
}

void Sample::HandleException(Platform::Exception^ Ex, Platform::String^ sender)
{
    wchar_t buffer[1000] = {};
    swprintf_s(buffer, L"There was a problem with %s\nError: 0x%X\n%s\n", sender->Data(), Ex->HResult, Ex->Message->Data());
    OutputDebugString(buffer);
}

#pragma region Frame Update
// Executes basic render loop.
void Sample::Tick()
{
    PIXBeginEvent(PIX_COLOR_DEFAULT, L"Frame %I64u", m_frame);

    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();

    PIXEndEvent();
    m_frame++;
}

// Updates the world.
void Sample::Update(DX::StepTimer const&)
{
    PIXBeginEvent(PIX_COLOR_DEFAULT, L"Update");

    PlayFabClientAPI::Update();

    auto pad = m_gamePad->GetState(0);
    if (pad.IsConnected())
    {
        m_gamePadButtons.Update(pad);
        
        if (pad.IsViewPressed())
        {
            ExitSample();
        }

        {
            if (pad.IsAPressed())
            {
                if (m_currentUser != nullptr)
                    UpdatePlayFabDisplayName();
                else
                    ChangeAccount();
            }

            // If there is no one signed in on the console, open the account picker instead. An Xbox account should be linked
            //  with the new PlayFab account upon creation.
            else if (pad.IsBPressed())
            {
                if (m_currentUser != nullptr)
                    RegisterForPlayFab(m_currentUser);
                else
                    ChangeAccount();
                //framesSinceLastInput = 0;
            }

            // A signed in Xbox account is required for getting a PlayFab token so open the
            //  account picker if no user is logged in.
            // Note: Using ButtonState::PRESSED to prevent this from firing on back to back frames
            else if (m_gamePadButtons.x == DirectX::GamePad::ButtonStateTracker::ButtonState::PRESSED)
            {
                if (m_currentUser != nullptr)
                    RefreshPlayFabToken(m_currentUser);
                else
                    ChangeAccount();
            }

            // If a new PlayFab user was created, you can link it to the signed in Xbox account
            //  with the LinkXboxAccount API.
            else if (pad.IsYPressed())
            {
                if (m_currentUser != nullptr)
                    LinkWithExistingPlayFabAccount(m_currentUser);
                else
                    ChangeAccount();
            }

            else if (pad.IsMenuPressed())
            {
                ChangeAccount();
            }
        }
    }
    else
    {
        m_gamePadButtons.Reset();
    }

    PIXEndEvent();
}
#pragma endregion

#pragma region Frame Render
// Draws the scene.
void Sample::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    // Prepare the render target to render a new frame.
    m_deviceResources->Prepare();
    Clear();

    auto context = m_deviceResources->GetD3DDeviceContext();
    PIXBeginEvent(context, PIX_COLOR_DEFAULT, L"Render");

    m_liveInfoHUD->Render();

    m_batch->Begin();

    if (m_currentUser != nullptr)
    {
        if (!m_playFabLoggedIn)
        {
            m_font->DrawString(m_batch.get(), L"No PlayFab account available...", DirectX::XMFLOAT2(100, 100), DirectX::Colors::Red);
        }
        else
        {
            m_font->DrawString(m_batch.get(), L"PlayFab Display Name:", DirectX::XMFLOAT2(100, 100), DirectX::Colors::Green);
            if(wcslen(m_playFabDisplayName) == 0)
                m_font->DrawString(m_batch.get(), L"[Anonymous account]", DirectX::XMFLOAT2(480, 100), DirectX::Colors::Green);
            else
                m_font->DrawString(m_batch.get(), m_playFabDisplayName, DirectX::XMFLOAT2(480, 100), DirectX::Colors::Green);
        }
    }

    DX::DrawControllerString(m_batch.get(), m_font.get(), m_ctrlFont.get(), L"[Menu] Open account picker\n[A] Update display name\n[B] Create new PlayFab account\n[X] Login to existing PlayFab account\n[Y] Link Xbox and PlayFab accounts", DirectX::XMFLOAT2(100, 200));

    m_console->Render();

    m_batch->End();

    PIXEndEvent(context);

    // Show the new frame.
    PIXBeginEvent(context, PIX_COLOR_DEFAULT, L"Present");
    m_deviceResources->Present();
    m_graphicsMemory->Commit();
    PIXEndEvent(context);
}

// Helper method to clear the back buffers.
void Sample::Clear()
{
    auto context = m_deviceResources->GetD3DDeviceContext();
    PIXBeginEvent(context, PIX_COLOR_DEFAULT, L"Clear");

    // Clear the views.
    auto renderTarget = m_deviceResources->GetRenderTargetView();
    auto depthStencil = m_deviceResources->GetDepthStencilView();

    context->ClearRenderTargetView(renderTarget, ATG::Colors::Background);
    context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    context->OMSetRenderTargets(1, &renderTarget, depthStencil);

    // Set the viewport.
    auto viewport = m_deviceResources->GetScreenViewport();
    context->RSSetViewports(1, &viewport);

    PIXEndEvent(context);
}
#pragma endregion

#pragma region Message Handlers
// Message handlers
void Sample::OnSuspending()
{
    auto context = m_deviceResources->GetD3DDeviceContext();
    context->Suspend(0);
}

void Sample::OnResuming()
{
    auto context = m_deviceResources->GetD3DDeviceContext();
    context->Resume();
    m_timer.ResetElapsedTime();
    m_gamePadButtons.Reset();
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Sample::CreateDeviceDependentResources()
{
    auto device = m_deviceResources->GetD3DDevice();
    auto context = m_deviceResources->GetD3DDeviceContext();

    m_liveInfoHUD->RestoreDevice(context);

    m_graphicsMemory = std::make_unique<GraphicsMemory>(device, m_deviceResources->GetBackBufferCount());
    m_batch = std::make_unique<SpriteBatch>(context);
    m_font = std::make_unique<SpriteFont>(device, L"SegoeUI_24.spritefont");

    m_console = std::make_unique<DX::TextConsole>(context, L"Courier_16.spritefont");
    m_ctrlFont = std::make_unique<SpriteFont>(device, L"XboxOneController.spritefont");
    m_console->SetDebugOutput(true);
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
    auto vp = m_deviceResources->GetScreenViewport();
    m_batch->SetViewport(vp);

    RECT console = {};

    console.top = 547;
    console.left = 795;
    console.bottom = console.top + 341;
    console.right = console.left + 626;

    m_console->SetWindow(console);
}
#pragma endregion
