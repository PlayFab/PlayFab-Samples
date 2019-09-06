//--------------------------------------------------------------------------------------
// PlayFabAccountManagement.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayFabAccountManagement.h"

#include "ATGColors.h"

#define CHECK_EMPTY(string) (string.empty() ? L"[No value]" : string.c_str())

extern void ExitSample();

using namespace DirectX;

using Microsoft::WRL::ComPtr;

using namespace PlayFab;
using namespace PlayFab::ClientModels;
using namespace Windows::Xbox::UI;
using namespace Windows::Xbox::System;

namespace
{
    const int c_sampleUIPanel = 2000;
    const int c_changeProfileBtn = 2101;
    const int c_newAccountBtn = 2102;
    const int c_linkAccountBtn = 2103;
    const int c_unlinkAccountBtn = 2104;
    const int c_setDisplayNameBtn = 2105;
    const int c_updateEmailBtn = 2106;
    const int c_removeEmailBtn = 2107;
    const int c_loginWithXboxBtn = 2110;
    const int c_loginWithUsernameBtn = 2111;


    std::wstring FormatTimeValue(const time_t &timeValue)
    {
        struct tm time;
        localtime_s(&time, &timeValue);
        char buffer[26];
        asctime_s(buffer, &time);
        buffer[strlen(buffer) - 1] = '\0'; // Trim the trailing newline character
        return WidenString(buffer);
    }
}

Sample::Sample() noexcept(false) :
    m_frame(0)
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();

    m_liveResources = std::make_shared<ATG::LiveResources>();
    m_liveInfoHUD = std::make_unique<ATG::LiveInfoHUD>(L"PlayFabAccountManagement Sample");
    m_playFabResources = std::make_shared<ATG::PlayFabResources>(L"DC0");

    ATG::UIConfig uiconfig;
    wcscpy_s(uiconfig.largeLegendName, L"XboxOneController.spritefont");
    wcscpy_s(uiconfig.smallLegendName, L"XboxOneController.spritefont");
    uiconfig.colorNormal = XMFLOAT4(.86f, .86f, .86f, 1.f);
    m_ui = std::make_unique<ATG::UIManager>(uiconfig);
}

// Initialize the Direct3D resources required to run.
void Sample::Initialize(IUnknown* window)
{
    m_gamePad = std::make_unique<GamePad>();
    m_ui->LoadLayout(L".\\Assets\\SampleUI.csv", L".\\Assets");

    m_deviceResources->SetWindow(window);

    m_deviceResources->CreateDeviceResources();  
    CreateDeviceDependentResources();

    m_deviceResources->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();

    m_liveResources->SetUserChangedCallback([this](ATG::XboxLiveUser user)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
        m_ui->FindPanel<ATG::IPanel>(c_sampleUIPanel)->Show();
    });

    m_liveResources->SetUserSignOutCompletedCallback([this](ATG::XboxLiveUser user)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
        m_ui->FindPanel<ATG::IPanel>(c_sampleUIPanel)->Close();
    });

    m_playFabResources->SetPlayFabUserChangedCallback([this](LoginResult result)
    {
        RefreshAccountInfo(result.PlayFabId);
    });

    m_playFabResources->SetPlayFabLoginErrorCallback([this](PlayFabError error)
    {
        SetErrorText(L"Unable to login with PlayFab\nMore information in debug output", 600);
    });

    m_banned = false;
    m_frameCountToDisplayError = 0;

    m_liveResources->Initialize();
    m_liveInfoHUD->Initialize(m_liveResources->GetLiveContext());
    m_playFabResources->Initialize(); 
    SetupUI();
}

void Sample::SetErrorText(const std::wstring& message, int frameCountToDisplayError)
{
    m_errorMessage = message;
    m_frameCountToDisplayError = frameCountToDisplayError;
}

void Sample::RefreshAccountInfo(const std::string& playFabId)
{
    ClearAccountInfo();
    GetAccountInfo();
    GetProfileInfo(playFabId);
}

void Sample::ClearAccountInfo()
{
    m_banned = false;
    m_bannedUntil.clear();
    m_contactEmail.clear();
    m_creationTime.clear();
    m_displayName.clear();
    m_firstLogin.clear();
    m_lastLogin.clear();
    m_playFabId.clear();
    m_publisherId.clear();
    m_titleId.clear();
    m_userName.clear();
    m_xboxUserId.clear();
    m_avatarUrl.clear();
}

void Sample::ChangeXboxProfile()
{
    m_console->WriteLine(L"In " __FUNCTION__);
    SystemUI::ShowAccountPickerAsync(nullptr, AccountPickerOptions::None);
}

void Sample::CreateNewPlayFabAccountAndLink()
{
    m_console->WriteLine(L"In " __FUNCTION__);
    auto xboxUser = m_liveResources->GetUser();
    if (xboxUser == nullptr)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
    }
    auto gamertag = xboxUser->DisplayInfo->Gamertag;

    auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(gamertag, L"Display Name", L"Provide a display name for your PlayFab account. Must be 3-25 characters long", Windows::Xbox::UI::VirtualKeyboardInputScope::Alphanumeric);
    concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
    {
        try
        {
            Platform::String^ displayName = task.get();
            auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(gamertag, L"Login name", L"Provide a login ID for PlayFab. Must be 3-20 characters long", Windows::Xbox::UI::VirtualKeyboardInputScope::Alphanumeric);
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
                                m_console->Write(L"Display Name must be 3-25 characters long\n");
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

                                        PlayFabClientAPI::LinkXboxAccount(linkRequest, [this](const LinkXboxAccountResult&, void*)
                                        {
                                            auto id = m_playFabResources->GetPlayFabLogin().PlayFabId;
                                            RefreshAccountInfo(id);
                                            m_console->Write(L"Account link successful\n");
                                        }, OnPlayFabError, m_console.get());
                                    }
                                    catch (Platform::Exception^ Ex)
                                    {
                                        Sample::HandleException(Ex, __FUNCTIONW__);
                                    }
                                });
                            }, Sample::OnPlayFabError, m_console.get());
                        }
                        catch (Platform::Exception^ Ex)
                        {
                            Sample::HandleException(Ex, __FUNCTIONW__);
                        }
                    });
                }
                catch (Platform::Exception^ Ex)
                {
                    Sample::HandleException(Ex, __FUNCTIONW__);
                }
            });
        }
        catch (Platform::Exception^ Ex)
        {
            Sample::HandleException(Ex, __FUNCTIONW__);
        }
    });
}

void Sample::LinkExistingPlayFabAccount()
{
    m_console->WriteLine(L"In " __FUNCTION__);
    if (m_liveResources->IsUserSignedIn() == false)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
        return;
    }

    auto user = m_liveResources->GetUser();
    auto async = user->GetTokenAndSignatureAsync("POST", "https://playfabapi.com", "");
    concurrency::create_task(async).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> task)
    {
        try
        {
            LinkXboxAccountRequest request;
            request.XboxToken = ShortenString(task.get()->Token->Data());

            // If this is set to true and the Xbox profile is already linked to another account, then it will be automatically
            //  unlinked from that other account and relinked to the logged in PlayFab account (e.g. the account associated with
            //  the token stored in PlayFabSettings at the time this call is made)
            request.ForceLink = false;

            PlayFabClientAPI::LinkXboxAccount(request, [=](const LinkXboxAccountResult&, void*)
            {
                auto id = m_playFabResources->GetPlayFabLogin().PlayFabId;
                RefreshAccountInfo(id);
                m_console->WriteLine(L"Xbox profile successfully linked to PlayFab account");
            }, OnPlayFabError, m_console.get());
        }
        catch (Platform::Exception^ ex)
        {
            Sample::HandleException(ex, __FUNCTION__);
        }
    });
}

void Sample::UnlinkPlayFabAccount()
{
    m_console->WriteLine(L"In " __FUNCTION__);
    if (m_liveResources->IsUserSignedIn() == false)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
        return;
    }

    auto user = m_liveResources->GetUser();
    auto async = user->GetTokenAndSignatureAsync("POST", "https://.playfabapi.com", "");
    concurrency::create_task(async).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> task)
    {
        try
        {
            UnlinkXboxAccountRequest request;
            request.XboxToken = ShortenString(task.get()->Token->Data());

            PlayFabClientAPI::UnlinkXboxAccount(request, [=](const UnlinkXboxAccountResult&, void*)
            {
                ClearAccountInfo();
                m_console->WriteLine(L"Xbox profile successfully unlkinked from PlayFab account");
            }, OnPlayFabError, m_console.get());
        }
        catch (Platform::Exception^ Ex)
        {
            HandleException(Ex, __FUNCTION__);
        }
    });
}

void Sample::SetTitleDisplayName()
{
    // NOTE: The PlayFab title display name (or display name) may be used in conjunction with a player's
    //  gamertag, but it cannot be used as a replacement. XR-046 still requires a gamertag be displayed
    //  when identifying a player.
    m_console->WriteLine(L"In " __FUNCTION__);
    if (m_liveResources->IsUserSignedIn() == false)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
        return;
    }

    auto user = m_liveResources->GetUser();
    auto async = SystemUI::ShowVirtualKeyboardAsync(user->DisplayInfo->Gamertag, "Display Name", "What name do you want others to see?", VirtualKeyboardInputScope::Alphanumeric);

    concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
    {
        try
        {
            UpdateUserTitleDisplayNameRequest request;
            request.DisplayName = ShortenString(task.get()->Data());

            PlayFabClientAPI::UpdateUserTitleDisplayName(request, [=](const UpdateUserTitleDisplayNameResult& result, void*)
            {
                m_displayName = WidenString(result.DisplayName);
                m_console->Write(L"Display name set to ");
                m_console->WriteLine(m_displayName.c_str());
            }, OnPlayFabError, m_console.get());
        }
        catch (Platform::Exception^ Ex)
        {
            HandleException(Ex, __FUNCTION__);
        }
    });
}

void Sample::UpdateEmailAddress()
{
    m_console->WriteLine(L"In " __FUNCTION__);
    if (m_liveResources->IsUserSignedIn() == false)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
        return;
    }

    auto async = SystemUI::ShowVirtualKeyboardAsync("", "Email address", "Please provide your preferred contact email address", VirtualKeyboardInputScope::EmailSmtpAddress);

    concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
    {
        try
        {
            auto email = task.get();
            AddOrUpdateContactEmailRequest request;
            request.EmailAddress = ShortenString(email->Data());

            PlayFabClientAPI::AddOrUpdateContactEmail(request, [=](const AddOrUpdateContactEmailResult&, void*)
            {
                m_contactEmail = email->Data();
                m_console->Write(L"Contact email set to ");
                m_console->WriteLine(email->Data());
            }, OnPlayFabError, m_console.get());
        }
        catch (Platform::Exception^ Ex)
        {
            HandleException(Ex, __FUNCTION__);
        }
    });
}

void Sample::RemoveEmailAddress()
{
    m_console->WriteLine(L"In " __FUNCTION__);
    if (m_liveResources->IsUserSignedIn() == false)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
        return;
    }

    RemoveContactEmailRequest request;
    PlayFabClientAPI::RemoveContactEmail(request, [=](const RemoveContactEmailResult&, void*)
    {
        m_contactEmail.clear();
        m_console->WriteLine(L"Contact email address has been removed");
    }, OnPlayFabError, m_console.get());
}

void Sample::GetAccountInfo()
{
    m_console->WriteLine(L"In " __FUNCTION__);
    if (m_liveResources->IsUserSignedIn() == false)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
        return;
    }

    GetAccountInfoRequest request;
    // Leaving the request with default values looks up the account info for the currently logged in PlayFab
    //  account (e.g. the account associated with the token stored in PlayFabSettings).
    PlayFabClientAPI::GetAccountInfo(request, [=](const GetAccountInfoResult& result, void*)
    {
        if (result.AccountInfo.notNull())
        {
            // NOTE: Some of these properties require explicitly allowing access in the Settings section of the
            //  developer dashboard at http://playfab.com
            m_playFabId = WidenString(result.AccountInfo->PlayFabId.c_str());

            if (result.AccountInfo->TitleInfo.notNull())
            {
                auto& titleInfo = result.AccountInfo->TitleInfo;
                m_displayName = WidenString(titleInfo->DisplayName.c_str());
                m_creationTime = FormatTimeValue(titleInfo->Created);
                if (titleInfo->FirstLogin.notNull())
                {
                    m_firstLogin = FormatTimeValue(titleInfo->FirstLogin);
                }
                if (titleInfo->LastLogin.notNull())
                {
                    m_lastLogin = FormatTimeValue(titleInfo->LastLogin);
                }
                m_banned = titleInfo->isBanned.notNull() ? titleInfo->isBanned : false;
                m_avatarUrl = WidenString(result.AccountInfo->TitleInfo->AvatarUrl.c_str());
            }

            m_userName = WidenString(result.AccountInfo->Username.c_str());
            
            if (result.AccountInfo->XboxInfo.notNull())
            {
                m_xboxUserId = WidenString(result.AccountInfo->XboxInfo->XboxUserId.c_str());
            }

            m_console->WriteLine(L"Successfully executed PlayFabClientAPI::GetAccountInfo");
        }
    }, OnPlayFabError, m_console.get());
}

void Sample::GetProfileInfo(std::string playFabId)
{
    m_console->WriteLine(L"In " __FUNCTION__);
    if (m_liveResources->IsUserSignedIn() == false)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
        return;
    }

    GetPlayerProfileRequest request;
    request.PlayFabId = playFabId;
    {
        PlayerProfileViewConstraints constraints;
        constraints.ShowContactEmailAddresses = true;
        constraints.ShowTotalValueToDateInUsd = true;
        constraints.ShowLocations = true;
        constraints.ShowBannedUntil = true;
        request.ProfileConstraints = constraints;
    }
    
    PlayFabClientAPI::GetPlayerProfile(request, [=](const GetPlayerProfileResult& result, void*)
    {
        m_console->WriteLine(L"Successfully completed PlayFabClientAPI::GetPlayerProfile");

        if (result.PlayerProfile.notNull())
        {
            const PlayerProfileModel& playerProfile = result.PlayerProfile;
            m_titleId = WidenString(playerProfile.TitleId.c_str());
            m_publisherId = WidenString(playerProfile.PublisherId.c_str());
            if (playerProfile.BannedUntil.notNull())
            {
                m_bannedUntil = FormatTimeValue(playerProfile.BannedUntil);
            }
            m_playerValue = playerProfile.TotalValueToDateInUSD.notNull() ? playerProfile.TotalValueToDateInUSD : 0;

            // There will either be one or zero contact email addresses
            auto emails = result.PlayerProfile->ContactEmailAddresses;
            if (emails.size() > 0)
                m_contactEmail = WidenString(emails.front().EmailAddress);
            else
                m_contactEmail.clear();
        }
    }, OnPlayFabError, m_console.get());
}

void Sample::LoginWithXbox()
{
    m_console->WriteLine(L"In " __FUNCTION__);
    if (m_liveResources->IsUserSignedIn() == false)
    {
        m_console->WriteLine(L"Sign in to your Xbox profile first");
        return;
    }

    auto async = m_liveResources->GetUser()->GetTokenAndSignatureAsync("POST", "https://playfabapi.com", "");
    concurrency::create_task(async).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> task)
    {
        try
        {
            auto tokenResult = task.get();

            LoginWithXboxRequest request;
            request.XboxToken = ShortenString(tokenResult->Token->Data());

            PlayFabClientAPI::LoginWithXbox(request, [=](const LoginResult& result, void*)
            {
                RefreshAccountInfo(result.PlayFabId);
                m_console->WriteLine(L"Successfully logged in using Xbox token");
            }, OnPlayFabError, m_console.get());
        }
        catch (Platform::Exception^ Ex)
        {
            HandleException(Ex, __FUNCTION__);
        }
    });
    LoginWithXboxRequest request;
    
}

void Sample::LoginWithUsername()
{
    m_console->WriteLine(L"In " __FUNCTION__);

    auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(L"", L"Username", L"Provide your login username for PlayFab.", Windows::Xbox::UI::VirtualKeyboardInputScope::Alphanumeric);
    concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
    {
        try
        {
            Platform::String^ signinName = task.get();
            auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(L"", L"Password", L"Provide your password for PlayFab.", Windows::Xbox::UI::VirtualKeyboardInputScope::Password);
            concurrency::create_task(async).then([=](concurrency::task<Platform::String^> task)
            {
                try
                {
                    LoginWithPlayFabRequest request;
                    request.Username = ShortenString(signinName->Data());
                    request.Password = ShortenString(task.get()->Data());

                    PlayFabClientAPI::LoginWithPlayFab(request, [=](const LoginResult& result, void*)
                    {
                        RefreshAccountInfo(result.PlayFabId);
                        m_console->WriteLine(L"Login with PlayFab credentials successful");
                        m_console->WriteLine(L"Make sure to link to your Xbox profile for easier login next time!");
                    }, OnPlayFabError, m_console.get());
                }
                catch (Platform::Exception^ Ex)
                {
                    HandleException(Ex, __FUNCTION__);
                }
            });
        }
        catch (Platform::Exception^ Ex)
        {
            HandleException(Ex, __FUNCTION__);
        }
    });
}

void Sample::OnPlayFabError(const PlayFab::PlayFabError& error, void* custom)
{
    DX::TextConsole* console = (DX::TextConsole*)custom;
    console->Write(L"An error occurred with a PlayFab API\n");
    wchar_t buffer[2000] = {};
    swprintf_s(buffer, L"%hs\n%hs\nError: %i\nURL Path: %hs\nHTTP code: %i\nHTTP status: %hs\nError details: %ls\n",
        error.ErrorName.c_str(),
        error.ErrorMessage.c_str(),
        error.ErrorCode,
        error.UrlPath.c_str(),
        error.HttpCode,
        error.HttpStatus.c_str(),
        error.ErrorDetails.serialize().c_str());

    console->Write(buffer);
}

void Sample::HandleException(Platform::Exception^ Ex, Platform::String^ sender)
{
    wchar_t buffer[1000] = {};
    swprintf_s(buffer, L"There was a problem with %s\nError: 0x%X\n%ls\n", sender->Data(), Ex->HResult, Ex->Message->Data());
    OutputDebugString(buffer);
}

void Sample::SetupUI()
{
    using namespace ATG;
    
    m_ui->FindControl<Button>(c_sampleUIPanel, c_changeProfileBtn)->SetCallback([this](IPanel*, IControl*)
    {
        ChangeXboxProfile();
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_newAccountBtn)->SetCallback([this](IPanel*, IControl*)
    {
        CreateNewPlayFabAccountAndLink();
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_linkAccountBtn)->SetCallback([this](IPanel*, IControl*)
    {
        LinkExistingPlayFabAccount();
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_unlinkAccountBtn)->SetCallback([this](IPanel*, IControl*)
    {
        UnlinkPlayFabAccount();
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_setDisplayNameBtn)->SetCallback([this](IPanel*, IControl*)
    {
        SetTitleDisplayName();
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_updateEmailBtn)->SetCallback([this](IPanel*, IControl*)
    {
        UpdateEmailAddress();
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_removeEmailBtn)->SetCallback([this](IPanel*, IControl*)
    {
        RemoveEmailAddress();
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_loginWithXboxBtn)->SetCallback([this](IPanel*, IControl*)
    {
        LoginWithXbox();
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_loginWithUsernameBtn)->SetCallback([this](IPanel*, IControl*)
    {
        LoginWithUsername();
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

    PlayFabClientAPI::Update();

    auto pad = m_gamePad->GetState(0);
    if (pad.IsConnected())
    {
        m_gamePadButtons.Update(pad);

        if (!m_ui->Update(elapsedTime, pad))
        {
            if (pad.IsViewPressed())
            {
                ExitSample();
            }

            if (m_gamePadButtons.menu == GamePad::ButtonStateTracker::PRESSED)
            {
                Windows::Xbox::UI::SystemUI::ShowAccountPickerAsync(nullptr, Windows::Xbox::UI::AccountPickerOptions::None);
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

    // Draw quads to break up the UI elements
    context->OMSetBlendState(m_states->Opaque(), nullptr, 0xFFFFFFFF);
    context->OMSetDepthStencilState(m_states->DepthNone(), 0);
    context->RSSetState(m_states->CullNone());

    m_drawEffect->Apply(context);
    context->IASetInputLayout(m_drawInputLayout.Get());
    m_drawBatch->Begin();

    static DirectX::XMFLOAT4A color = { .1f, .1f, .1f, 0.f };
    static DirectX::VertexPositionColor vpc[] =
    {
        { {790.f, 690.f, -.1f}, color },
        { {1848.f, 690.f, -.1f}, color },
        { {1848.f, 990.f, -.1f}, color },
        { {790.f, 990.f, -.1f}, color },
    };

    m_drawBatch->DrawQuad(vpc[0], vpc[1], vpc[2], vpc[3]);

    m_drawBatch->End();
        
    m_liveInfoHUD->Render();
    m_ui->Render();
    m_console->Render();

    wchar_t buffer[4000] = {};
    swprintf_s(buffer, L"PlayFab Id: %ls\nPlayFab display name: %ls\nPlayFab user name: %ls\nPlayFab email: %ls\nAvatar URL: %ls\nCreated on: %ls\nFirst login: %ls\nLast login: %ls\nPlayer value: %i\nUser banned: %ls\nBanned until: %ls\nTitle ID: %ls\nPublisher ID: %ls\nXbox user ID: %ls\n",
        CHECK_EMPTY(m_playFabId),
        CHECK_EMPTY(m_displayName),
        CHECK_EMPTY(m_userName),
        CHECK_EMPTY(m_contactEmail),
        CHECK_EMPTY(m_avatarUrl),
        CHECK_EMPTY(m_creationTime),
        CHECK_EMPTY(m_firstLogin),
        CHECK_EMPTY(m_lastLogin),
        m_playerValue,
        (m_banned ? L"TRUE" : L"FALSE"),
        CHECK_EMPTY(m_bannedUntil),
        CHECK_EMPTY(m_titleId),
        CHECK_EMPTY(m_publisherId),
        CHECK_EMPTY(m_xboxUserId));

    m_batch->Begin();

    m_font->DrawString(m_batch.get(), buffer, DirectX::XMFLOAT2(800, 150), DirectX::Colors::White);
    
    if (m_frameCountToDisplayError > 0)
    {
        m_frameCountToDisplayError--;
        m_font->DrawString(m_batch.get(), m_errorMessage.c_str(), DirectX::XMFLOAT2(800, 600), DirectX::Colors::Pink);
    }

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
    m_liveResources->Refresh();
    m_playFabResources->Refresh();
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Sample::CreateDeviceDependentResources()
{
    auto device = m_deviceResources->GetD3DDevice();
    auto context = m_deviceResources->GetD3DDeviceContext();

    m_graphicsMemory = std::make_unique<GraphicsMemory>(device, m_deviceResources->GetBackBufferCount());

    m_liveInfoHUD->RestoreDevice(context);

    m_console = std::make_unique<DX::TextConsole>(context, L"Courier_16.spritefont");
    m_ui->RestoreDevice(context);

    m_batch = std::make_unique<SpriteBatch>(context);
    m_font = std::make_unique<SpriteFont>(device, L"SegoeUI_18.spritefont");

    // Set up drawing effect and batch
    m_states = std::make_unique<CommonStates>(device);
    m_drawEffect = std::make_unique<BasicEffect>(device);
    m_drawEffect->SetVertexColorEnabled(true);

    void const* shaderByteCode;
    size_t byteCodeLength;

    m_drawEffect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);

    DX::ThrowIfFailed(
        device->CreateInputLayout(VertexPositionColor::InputElements,
            VertexPositionColor::InputElementCount,
            shaderByteCode, byteCodeLength,
            m_drawInputLayout.ReleaseAndGetAddressOf()));

    m_drawBatch = std::make_unique<PrimitiveBatch<VertexPositionColor>>(context);
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
    auto vp = m_deviceResources->GetScreenViewport();
    m_batch->SetViewport(vp);

    RECT fullscreen = m_deviceResources->GetOutputSize();
    m_ui->SetWindow(fullscreen);

    static const RECT consoleDisplay = { 800, 700, 1838, 1000 };
    m_console->SetWindow(consoleDisplay);

    // Scaled input coordinates for effect
    auto size = m_deviceResources->GetOutputSize();
    SimpleMath::Matrix proj = SimpleMath::Matrix::CreateOrthographicOffCenter(0.f, float(vp.Width), float(vp.Height), 0.f, 0.f, 1.f);

    m_drawEffect->SetProjection(proj);
}
#pragma endregion
