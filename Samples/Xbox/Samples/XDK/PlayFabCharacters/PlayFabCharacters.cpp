//--------------------------------------------------------------------------------------
// PlayFabCharacters.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayFabCharacters.h"

#include "ATGColors.h"


extern void ExitSample();

using namespace DirectX;

using Microsoft::WRL::ComPtr; 

using namespace ATG;
using namespace PlayFab;
using namespace PlayFab::ClientModels;

namespace
{
    const int c_sampleUIPanel = 2000;
    const int c_sampleUIChangeAccount = 2101;
    const int c_sampleUIAdd = 2102;
    const int c_sampleUIDelete1 = 2103;
    const int c_sampleUIDelete2 = 2105;
    const int c_sampleUIDelete3 = 2107;

    const DirectX::XMFLOAT2 c_textLocations[3] = 
    {
        {800, 550},
        {800, 710},
        {800, 870}
    };
}

Sample::Sample() noexcept(false) :
    m_frame(0)
{
    m_deviceResources = std::make_unique<DX::DeviceResources>(DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_UNKNOWN);

    m_liveResources = std::make_shared<ATG::LiveResources>();
    m_liveInfoHUD = std::make_unique<ATG::LiveInfoHUD>(L"PlayFabCharacters Sample");
    m_playFabResources = std::make_shared<ATG::PlayFabResources>(L"DC0");

    ATG::UIConfig uiconfig;
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

    m_playFabResources->SetPlayFabUserChangedCallback([this](LoginResult results)
    {
        ListUsersCharactersRequest request;
        GetPlayFabCharacters();
    });

    m_liveResources->Initialize();
    m_liveInfoHUD->Initialize(m_liveResources->GetLiveContext());
    m_playFabResources->Initialize();
    SetupUI();
}

void Sample::OnPlayFabError(const PlayFabError& error, void*)
{
    OutputDebugString(L"An error occurred with a PlayFab API\n");
    wchar_t buffer[2000] = {};
    swprintf_s(buffer, L"%hs\n%hs\nError: %i\nURL Path: %hs\nHTTP code: %i\nHTTP status: %hs\nError details: %ls\n",
        error.ErrorName.c_str(),
        error.ErrorMessage.c_str(),
        error.ErrorCode,
        error.UrlPath.c_str(),
        error.HttpCode,
        error.HttpStatus.c_str(),
        error.ErrorDetails.serialize().c_str());

    OutputDebugString(buffer);
}

void Sample::OnCloudScriptExecuted(const PlayFab::ClientModels::ExecuteCloudScriptResult& result)
{
    wchar_t buffer[2000] = {};

    swprintf_s(buffer, L"Executed: %hs\nExecution time: %f\nProcessor time: %f\n",
        result.FunctionName.c_str(),
        result.ExecutionTimeSeconds,
        result.ProcessorTimeSeconds);

    if (result.Error.notNull())
    {
        wcscat_s(buffer, L"An error occurred!\n");
        wcscat_s(buffer, WidenString(result.Error->Error).c_str());
        wcscat_s(buffer, L"\n");
        wcscat_s(buffer, WidenString(result.Error->Message).c_str());
    }

    wcscat_s(buffer, L"Reporting logs\n");
    for each(auto log in result.Logs)
    {
        wcscat_s(buffer, L"-");
        wcscat_s(buffer, WidenString(log.Message).c_str());
        wcscat_s(buffer, L"\n");
        if (!log.Data.is_null())
        {
            wcscat_s(buffer, L"-");
            wcscat_s(buffer, log.Data.serialize().c_str());
            wcscat_s(buffer, L"\n");
        }
    }

    if (result.FunctionResult.is_null())
    {
        wcscat_s(buffer, L"No function result was returned\n");
    }
    else
    {
        wcscat_s(buffer, L"Result:\n");
        if (result.FunctionResult.is_string())
        {
            wcscat_s(buffer, result.FunctionResult.as_string().c_str());
        }
        else if (result.FunctionResult.is_integer())
        {
            wchar_t numBuffer[_MAX_ITOSTR_BASE10_COUNT] = {};
            _itow_s(result.FunctionResult.as_integer(), numBuffer, 10);
            wcscat_s(buffer, numBuffer);
        }
        else if (result.FunctionResult.is_double())
        {
            wchar_t numBuffer[100] = {};
            swprintf_s(numBuffer, L"%g", result.FunctionResult.as_double());
            wcscat_s(buffer, numBuffer);
        }
        else if (result.FunctionResult.is_object())
        {
            auto obj = result.FunctionResult.as_object();
            auto iter = obj.begin();
            while (iter != obj.end())
            {
                wcscat_s(buffer, iter->first.c_str());
                wcscat_s(buffer, L": ");
                wcscat_s(buffer, iter->second.serialize().c_str());
                wcscat_s(buffer, L"\n");
                ++iter;
            }
        }
    }

    OutputDebugString(buffer);
    OutputDebugString(L"\n");
}

void Sample::SetupUI()
{
    m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIChangeAccount)->SetCallback([this](IPanel*, IControl*)
    {
        Windows::Xbox::UI::SystemUI::ShowAccountPickerAsync(nullptr, Windows::Xbox::UI::AccountPickerOptions::None);
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIAdd)->SetCallback([this](IPanel*, IControl*)
    {
        if (m_characters.size() < 3)
        {
            auto async = Windows::Xbox::UI::SystemUI::ShowVirtualKeyboardAsync(L"", L"Name", L"What do you want your new character to be named?", Windows::Xbox::UI::VirtualKeyboardInputScope::Alphanumeric);
            concurrency::create_task(async).then([=](concurrency::task<Platform::String^> t)
            {
                try
                {
                    auto result = t.get();
                    wchar_t buffer[200] = {};
                    swprintf_s(buffer, L"{\"Name\":\"%ls\"}", result->Data());

                    ExecuteCloudScriptRequest request;
                    request.FunctionName = "grantCharacter";
                    request.FunctionParameter = web::json::value::parse(buffer);
                    PlayFabClientAPI::ExecuteCloudScript(request, [=](const PlayFab::ClientModels::ExecuteCloudScriptResult& result, void*)
                    {
                        GetPlayFabCharacters();
                        OnCloudScriptExecuted(result);
                    }, OnPlayFabError);
                }
                catch (Platform::Exception^ ex)
                {
                    OutputDebugString(L"There was a problem\n");
                    OutputDebugString(ex->Message->Data());
                    OutputDebugString(L"\n");
                }
            });
        }
        else
        {
            OutputDebugString(L"Three characters already created. No more allowed.\n");
        }
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete1)->SetEnabled(false);
    m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete1)->SetCallback([this](IPanel*, IControl*)
    {
        wchar_t buffer[200] = {};
        swprintf_s(buffer, L"{\"CharId\":\"%hs\"}", m_characters[0].CharacterId.c_str());

        ExecuteCloudScriptRequest request;
        request.FunctionName = "deleteCharacter";
        request.FunctionParameter = web::json::value::parse(buffer);
        PlayFabClientAPI::ExecuteCloudScript(request, [=](const PlayFab::ClientModels::ExecuteCloudScriptResult& result, void*)
        {
            GetPlayFabCharacters();
            OnCloudScriptExecuted(result);
        }, OnPlayFabError);
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete2)->SetEnabled(false);
    m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete2)->SetCallback([this](IPanel*, IControl*)
    {
        wchar_t buffer[200] = {};
        swprintf_s(buffer, L"{\"CharId\":\"%hs\"}", m_characters[1].CharacterId.c_str());

        ExecuteCloudScriptRequest request;
        request.FunctionName = "deleteCharacter";
        request.FunctionParameter = web::json::value::parse(buffer);
        PlayFabClientAPI::ExecuteCloudScript(request, [=](const PlayFab::ClientModels::ExecuteCloudScriptResult& result, void*)
        {
            GetPlayFabCharacters();
            OnCloudScriptExecuted(result);
        }, OnPlayFabError);
    });

    m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete3)->SetEnabled(false);
    m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete3)->SetCallback([this](IPanel*, IControl*)
    {
        wchar_t buffer[200] = {};
        swprintf_s(buffer, L"{\"CharId\":\"%hs\"}", m_characters[2].CharacterId.c_str());

        ExecuteCloudScriptRequest request;
        request.FunctionName = "deleteCharacter";
        request.FunctionParameter = web::json::value::parse(buffer);
        PlayFabClientAPI::ExecuteCloudScript(request, [=](const PlayFab::ClientModels::ExecuteCloudScriptResult& result, void*)
        {
            GetPlayFabCharacters();
            OnCloudScriptExecuted(result);
        }, OnPlayFabError);
    });
}

void Sample::GetPlayFabCharacters()
{
    ListUsersCharactersRequest request;
    PlayFabClientAPI::GetAllUsersCharacters(request, [=](const ListUsersCharactersResult &result, void*)
    {
        OutputDebugString(L"Successfully retrieved characters\n");
        m_characters.clear();
        m_characters.reserve(result.Characters.size());
        for (auto item : result.Characters)
            m_characters.push_back(item);
        UpdateCharacterList();
    }, OnPlayFabError);
}

void Sample::UpdateCharacterList()
{
    int idx = 0;
    for (auto item : m_characters)
    {
        ++idx;
        if (idx > 3)
        {
            OutputDebugString(L"More characters than expected. Stopping at 3.\n");
            break;
        }

        swprintf_s(m_characterDescBuffers[idx - 1], L"Character %i Name - %hs\nCharacter Type - %hs",
            idx,
            item.CharacterName.c_str(),
            item.CharacterType.c_str());
    }

    if(m_characters.size() >= 1)
        m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete1)->SetEnabled(true);
    else
        m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete1)->SetEnabled(false);

    if (m_characters.size() >= 2)
        m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete2)->SetEnabled(true);
    else
        m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete2)->SetEnabled(false);

    if (m_characters.size() == 3)
    {
        m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete3)->SetEnabled(true);
        m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIAdd)->SetEnabled(false);
    }
    else
    {
        m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIDelete3)->SetEnabled(false);
        m_ui->FindControl<Button>(c_sampleUIPanel, c_sampleUIAdd)->SetEnabled(true);
    }
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

    try
    {
        PlayFabClientAPI::Update();
    }
    catch (web::json::json_exception ex)
    {
        OutputDebugStringA(ex.what());
        OutputDebugString(L"\nAn exception was caught\n");
    }

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
        
    m_liveInfoHUD->Render();
    m_ui->Render();

    m_batch->Begin();

    for (int idx = 0; idx < m_characters.size(); ++idx)
        m_font->DrawString(m_batch.get(), m_characterDescBuffers[idx], c_textLocations[idx], DirectX::Colors::White);

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
    
    context->ClearRenderTargetView(renderTarget, ATG::Colors::Background);
    
    context->OMSetRenderTargets(1, &renderTarget, nullptr);

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

    m_batch = std::make_unique<SpriteBatch>(context);
    m_font = std::make_unique<SpriteFont>(device, L"SegoeUI_24.spritefont");

    m_ui->RestoreDevice(context);
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
    auto vp = m_deviceResources->GetScreenViewport();
    m_batch->SetViewport(vp);

    auto fullscreen = m_deviceResources->GetOutputSize();
    m_ui->SetWindow(fullscreen);
}
#pragma endregion
