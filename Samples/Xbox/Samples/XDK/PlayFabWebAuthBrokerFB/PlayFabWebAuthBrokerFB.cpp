//--------------------------------------------------------------------------------------
// PlayFabWebAuthBrokerFB.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayFabWebAuthBrokerFB.h"

#include "ATGColors.h"
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabSettings.h"

extern void ExitSample();

using namespace DirectX;

using Microsoft::WRL::ComPtr; 

using namespace PlayFab;
using namespace ClientModels;

Sample::Sample() noexcept(false)
    : m_frame(0)
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();

    m_liveResources = std::make_shared<ATG::LiveResources>();
    m_liveInfoHUD = std::make_unique<ATG::LiveInfoHUD>(L"PlayFabWebAuthBrokerFB Sample");

    m_fbAuthHelper = std::make_unique<FacebookAuthHelper>();

    m_sampleUI = std::make_unique<SampleUI>();
}

// Initialize the Direct3D resources required to run.
void Sample::Initialize(IUnknown* window)
{
    m_gamePad = std::make_unique<GamePad>();

    m_deviceResources->SetWindow(window);

    m_sampleUI->Initialize();

    m_deviceResources->CreateDeviceResources();  
    CreateDeviceDependentResources();

    m_deviceResources->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();

    // This must be set for PlayFab APIs to work. It can be found in your PlayFab developer dashboard.
    PlayFabSettings::titleId = L"DC0";

    m_liveResources->SetUserChangedCallback([this](ATG::XboxLiveUser user)
    {
        concurrency::critical_section::scoped_lock lock(m_critSec);
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
        m_sampleUI->OnUserChanged();
        m_facebookAuthCancelationTokenSource = concurrency::cancellation_token_source();

        CacheXboxLiveTokenResult(user).then(
            [this, user]()
        {
            LoginToPlayFabWithXbox(user, false);
        });
    });

    m_liveResources->SetUserSignOutCompletedCallback([this](ATG::XboxLiveUser user)
    {
        concurrency::critical_section::scoped_lock lock(m_critSec);
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
        m_xboxLiveToken.clear();
        m_facebookAuthCancelationTokenSource.cancel();
        PlayFabSettings::ForgetAllCredentials();
        m_playFabId.clear();
        m_playerProfileSummary = PlayFabPlayerProfileSummary();
        m_sampleUI->OnUserSignedOut();
    });

    m_liveResources->Initialize();
    m_liveInfoHUD->Initialize(m_liveResources->GetLiveContext());

    //If no Xbox Live user signed in then prompt for Live sign-in
    if (!m_liveResources->IsUserSignedIn())
    {
        m_sampleUI->PromptForXboxLiveSignIn();
    }

    m_sampleUI->SetCreateDefaultPlayFabAccountCommand(
        [this]()
    {
        LoginToPlayFabWithXbox(m_liveResources->GetUser(), true);
    });
    
    m_sampleUI->SetFacebookLoginCommand(
        [this]()
    {
        try
        {
            m_facebookAuthTask = m_fbAuthHelper->Authenticate(m_liveResources->GetUser());
        }
        catch (...)
        {
            m_sampleUI->ShowFacebookAuthFailureUI();
        }
    });

    m_sampleUI->SetUnlinkPlayFabAccountCommand(
        [this]()
    {
        UnlinkPlayFabAccount();
    });

    m_sampleUI->SetRetryLoginToPlayFabWithXboxCommand(
        [this]()
    {
        LoginToPlayFabWithXbox(m_liveResources->GetUser(), false);
    });
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
void Sample::Update(DX::StepTimer const& timer)
{
    PIXBeginEvent(PIX_COLOR_DEFAULT, L"Update");

    float elapsedTime = float(timer.GetElapsedSeconds());

    // Must update PlayFabClientAPI
    {
        PlayFabClientAPI::Update();
    }

    auto pad = m_gamePad->GetState(0);
    if (pad.IsConnected())
    {
        m_gamePadButtons.Update(pad);

        m_sampleUI->Update(elapsedTime, pad);

        if (m_sampleUI->GetShowUnlinkOption())
        {
            if (m_gamePadButtons.x == GamePad::ButtonStateTracker::PRESSED)
            {
                m_sampleUI->ShowUnlinkPlayFabUI();
            }

            if (m_gamePadButtons.y == GamePad::ButtonStateTracker::PRESSED)
            {
                DisplayPlayerProfileSummary(m_playFabId);
            }
        }

        if (pad.IsViewPressed())
        {
            ExitSample();
        }
    }
    else
    {
        m_gamePadButtons.Reset();
    }

    if (m_facebookAuthTask != concurrency::task<FacebookAuthHelper::FacebookAuthResult>() // This checks the validity of the task
        && m_facebookAuthTask.is_done())
    {
        try
        {
            auto res = m_facebookAuthTask.get(); // If the task has been canceled this will throw
            OnFacebookAuthComplete(res);
        }
        catch (...)
        {
            // Deliberately throwing away the exception (most likely the task was cancelled)
        }

        m_facebookAuthTask = concurrency::task<FacebookAuthHelper::FacebookAuthResult>(); // Default constructs an invalid task
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

    // Print the PlayFab account summary if available
    m_batch->Begin();
    {
        static DirectX::XMFLOAT2 accountSummaryOrigin(95, 190);
        auto& profileSummary = m_playerProfileSummary.GetFormatted();
        if (profileSummary.empty())
        {
            if (m_playFabId.empty())
            {
                m_font->DrawString(m_batch.get(), L"No PlayFab account acquired", accountSummaryOrigin, DirectX::Colors::Red);
            }
            else
            {
                m_font->DrawString(m_batch.get(), L"Press 'Y' to display account summary", accountSummaryOrigin, DirectX::Colors::Green);
            }
        }
        else
        {
            m_font->DrawString(m_batch.get(), profileSummary.c_str(), accountSummaryOrigin, DirectX::Colors::LightBlue);
        }
    }
    m_batch->End();

    m_sampleUI->Render(context);

    m_console->Render();

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
    m_facebookAuthCancelationTokenSource.cancel();
    m_sampleUI->OnSuspending();
}

void Sample::OnResuming()
{
    auto context = m_deviceResources->GetD3DDeviceContext();
    context->Resume();
    m_timer.ResetElapsedTime();
    m_gamePadButtons.Reset();
    m_liveResources->Refresh();
    m_sampleUI->OnResuming();
    m_facebookAuthCancelationTokenSource = concurrency::cancellation_token_source();
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Sample::CreateDeviceDependentResources()
{
    auto device = m_deviceResources->GetD3DDevice();
    auto context = m_deviceResources->GetD3DDeviceContext();

    m_batch = std::make_unique<SpriteBatch>(context);
    m_font = std::make_unique<SpriteFont>(device, L"SegoeUI_24.spritefont");

    m_graphicsMemory = std::make_unique<GraphicsMemory>(device, m_deviceResources->GetBackBufferCount());

    m_liveInfoHUD->RestoreDevice(context);

    m_console = std::make_unique<DX::TextConsole>(context, L"Courier_16.spritefont");
    m_console->SetDebugOutput(true);

    m_sampleUI->CreateDeviceDependentResources(context, device);
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
    RECT fullscreen = m_deviceResources->GetOutputSize();

    {
        RECT console = {};

        console.top = 225;
        console.left = 1300;
        console.bottom = console.top + 650;
        console.right = console.left + 525;

        m_console->SetWindow(console);
    }

    auto vp = m_deviceResources->GetScreenViewport();
    m_sampleUI->CreateWindowSizeDependentResources(fullscreen, vp);
}

void Sample::LoginToPlayFabWithXbox(Windows::Xbox::System::IUser^ xboxUser, bool createAccount)
{

    LoginWithXboxRequest request;
    {
        concurrency::critical_section::scoped_lock lock(m_critSec);
        request.XboxToken = m_xboxLiveToken;
    }

    request.CreateAccount = createAccount;

    PlayFabClientAPI::LoginWithXbox(request, [this, createAccount](const LoginResult& result, void*)
    {
        m_console->Write(L"PlayFab signin successful\n");

        m_playFabId = result.PlayFabId;

        if (createAccount)
        {
            // Success here means that a new PlayFab account was created and linked with
            // the Xbox Live user. At this point we are done with the login flow and we
            // don't need to try any other PlayFab login methods
            m_sampleUI->ShowNewPlayFabAccountUI();
            m_sampleUI->ShowUnlinkOption(true);
        }
        else
        {
            // Success here means that the Xbox Live user is already linked to a PlayFab account
            // At this point we're done with the login flow and we don't need to try any other
            // PlayFab login methods
            m_sampleUI->ShowAccountAlreadyLinkedUI();
            m_sampleUI->ShowUnlinkOption(true);
        }

    }, [this, createAccount](const PlayFab::PlayFabError& error, void*) { LoginToPlayFabWithXboxErrorHandler(error, createAccount); }, nullptr);
}

void Sample::LoginToPlayFabWithXboxErrorHandler(const PlayFab::PlayFabError & error, bool createAccount)
{
    if (error.ErrorCode == PlayFabErrorCode::PlayFabErrorAccountNotFound)
    {
        assert(!createAccount);

        // The Xbox Live account is not linked to the PlayFab account so present
        // the player with alternative PlayFab Client login choices
        m_sampleUI->ShowPlayFabAccountChoices();
    }
    else
    {
        if (createAccount)
        {
            m_sampleUI->ShowCreatePlayFabAccountFailureUI();
        }
        else
        {
            m_sampleUI->ShowAcquirePlayFabXboxLinkedAccountFailureUI();
        }

        ReportPlayFabError(error);
    }
}

void Sample::DisplayPlayerProfileSummary(const std::string &playFabId)
{
    GetPlayerProfileRequest request;
    request.PlayFabId = playFabId;

    PlayerProfileViewConstraints constraints;
    constraints.ShowDisplayName = true;
    constraints.ShowLinkedAccounts = true;
    constraints.ShowCreated = true;
    request.ProfileConstraints = constraints;
    
    PlayFabClientAPI::GetPlayerProfile(request, 
        [=](const GetPlayerProfileResult& result, void*)
    {
        m_console->WriteLine(L"PlayFabClientAPI::GetPlayerProfile successful.");

        m_playerProfileSummary = PlayFabPlayerProfileSummary(constraints, result.PlayerProfile);

    }, [this](const PlayFab::PlayFabError& error, void*) { ReportPlayFabError(error); });
}

void Sample::LoginToPlayFabWithFacebook(const std::string &fbAccessToken)
{
    LoginWithFacebookRequest request;
    request.AccessToken = fbAccessToken;
    request.CreateAccount = true; // To simplify the sample we will just force account creation on this call

    PlayFabClientAPI::LoginWithFacebook(request, [this](const LoginResult& result, void*)
    {
        m_console->WriteLine(L"PlayFab sign in successfull");

        // Link the play fab account with the Xbox user
        auto xboxUser = m_liveResources->GetUser();

        LinkXboxAccountRequest request;
        {
            concurrency::critical_section::scoped_lock lock(m_critSec);
            request.XboxToken = m_xboxLiveToken;
        }

        if (result.NewlyCreated)
        {
            m_console->WriteLine(L"PlayFab account was newly created.");
        }

        m_playFabId = result.PlayFabId;
        PlayFabClientAPI::LinkXboxAccount(request, [this](const LinkXboxAccountResult&, void*)
        {
            m_console->WriteLine(L"LinkXboxAccount was successfull.");
            m_sampleUI->ShowSignInFlowCompleteUI();
            m_sampleUI->ShowUnlinkOption(true);

        }, [this](const PlayFab::PlayFabError& error, void*) { LinkPlayFabWithXboxErrorHandler(error); }, nullptr);

    }, [this](const PlayFab::PlayFabError& error, void*) { LoginToPlayFabWithFacebookErrorHandler(error); }, nullptr);
}

void Sample::LoginToPlayFabWithFacebookErrorHandler(const PlayFab::PlayFabError& error)
{
    m_sampleUI->ShowAcquirePlayFabFacebookLinkedAccountFailureUI();
    ReportPlayFabError(error);
}

void Sample::OnFacebookAuthComplete(FacebookAuthHelper::FacebookAuthResult& facebookAuthResult)
{
    if (facebookAuthResult.accessToken.empty())
    {
        // No access token returned so figure out what went wrong and recover
        if (facebookAuthResult.webAuthStatus == Windows::Xbox::UI::WebAuthenticationStatus::UserCancel)
        {
            m_console->WriteLine(L"Facebook authentication was cancelled by the user.");
            m_sampleUI->ShowPlayFabAccountChoices();
        }
        else
        {
            m_console->WriteLine(L"An error occurred when trying to authenticate with Facebook:");
            m_console->Format(L"errorCode: %ls\n", facebookAuthResult.errorCode.c_str());
            m_console->Format(L"errorDescription: %ls\n", facebookAuthResult.errorDescription.c_str());
            m_console->Format(L"errorDetail: 0x%08x\n", facebookAuthResult.errorDetail);
            m_sampleUI->ShowFacebookAuthFailureUI();
        }
    }
    else
    {
        LoginToPlayFabWithFacebook(ShortenString(facebookAuthResult.accessToken));
    }
}

void Sample::LinkPlayFabWithXboxErrorHandler(const PlayFab::PlayFabError & error)
{
    m_sampleUI->ShowLinkPlayFabWithXboxFailureUI();
    ReportPlayFabError(error);
}

void Sample::UnlinkPlayFabAccount()
{
    UnlinkXboxAccountRequest unlinkRequest;
    {
        concurrency::critical_section::scoped_lock lock(m_critSec);
        unlinkRequest.XboxToken = m_xboxLiveToken;
    }

    PlayFabClientAPI::UnlinkXboxAccount(unlinkRequest, [this](const UnlinkXboxAccountResult&, void*)
    {
        m_console->WriteLine(L"Unlink Xbox Account successful\n");
        m_playFabId.clear();
        m_playerProfileSummary = PlayFabPlayerProfileSummary();
        m_sampleUI->ShowPlayFabAccountChoices();
        m_sampleUI->ShowUnlinkOption(false);
    }, [this](const PlayFab::PlayFabError& error, void*) { ReportPlayFabError(error); }, nullptr);
}

void Sample::ReportPlayFabError(const PlayFab::PlayFabError & error)
{
    m_console->Write(L"An error occurred with a PlayFab API\n");
    wchar_t buffer[2000] = {};
    swprintf_s(buffer, L"PlayFab error code: %i\n%S\n%S\n%S\nHTTP error: %i\n%S\n",
        error.ErrorCode,
        error.ErrorName.c_str(),
        error.ErrorMessage.c_str(),
        error.UrlPath.c_str(),
        error.HttpCode,
        error.HttpStatus.c_str());

    m_console->Write(buffer);
}

void Sample::ReportException(Platform::Exception ^Ex, Platform::String ^sender)
{
    wchar_t buffer[1000] = {};
    swprintf_s(buffer, L"There was a problem with %ls\nError: 0x%X\n%ls\n", sender->Data(), Ex->HResult, Ex->Message->Data());
    OutputDebugString(buffer);

    m_console->Write(buffer);
}

void Sample::ReportException(Platform::Exception ^ Ex)
{
    wchar_t buffer[1000] = {};
    swprintf_s(buffer, L"Unexpected exception:\nError: 0x%X\n%ls\n", Ex->HResult, Ex->Message->Data());
    OutputDebugString(buffer);

    m_console->Write(buffer);
}

concurrency::task<void> Sample::CacheXboxLiveTokenResult(Windows::Xbox::System::IUser ^ xboxUser)
{
    try
    {
        auto async = xboxUser->GetTokenAndSignatureAsync("POST", "https://playfabapi.com", "");
        return concurrency::create_task(async).then([this](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> task)
        {
            try
            {
                auto token = task.get()->Token;
                {
                    concurrency::critical_section::scoped_lock lock(m_critSec);
                    m_xboxLiveToken = ShortenString(token->Data());
                }
            }
            catch (Platform::Exception^ Ex)
            {
                ReportException(Ex);
            }

            return concurrency::task_from_result();
        });
    }
    catch (Platform::Exception^ Ex)
    {
        ReportException(Ex);
    }
    return concurrency::task_from_result();
}

#pragma endregion
