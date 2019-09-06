//--------------------------------------------------------------------------------------
// PlayFabCloudScripts.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayFabCloudScripts.h"

#include "ATGColors.h"


extern void ExitSample();

using namespace DirectX;

using Microsoft::WRL::ComPtr; 

using namespace PlayFab;
using namespace PlayFab::ClientModels;
using namespace Windows::Xbox::System;

namespace
{
    const std::string c_ducketsCode = "DU";
    const uint32_t c_ticksToShowReceipt = 600;
    const RECT c_consoleDisplay = { 960, 250, 1838, 690 };

    const DirectX::XMFLOAT2 c_consoleTagPos(960, 210);
    const DirectX::XMFLOAT2 c_userIdTagPos(100, 210);
    const DirectX::XMFLOAT2 c_fundsTagPos(650, 610);
    const DirectX::XMFLOAT2 c_balanceTagPos(650, 210);

    const DirectX::XMFLOAT2 c_userIdPos(105, 240);
    const DirectX::XMFLOAT2 c_fundsPos(655, 640);
    const DirectX::XMFLOAT2 c_balancePos(655, 240);
    const DirectX::XMFLOAT2 c_leftLegendPos(100, 635);
    const DirectX::XMFLOAT2 c_rightLegendPos(400, 635);
    const DirectX::XMFLOAT2 c_messagePos(150, 390);

    const DirectX::XMFLOAT4A c_quadColor = { .235f, .235f, .235f, 0.f };
    const DirectX::VertexPositionColor c_userIdVerts[] =
    {
        { { 100.f, 250.f, -.1f }, c_quadColor },
        { { 625.f, 250.f, -.1f }, c_quadColor },
        { { 625.f, 300.f, -.1f }, c_quadColor },
        { { 100.f, 300.f, -.1f }, c_quadColor },
    };

    const DirectX::VertexPositionColor c_balanceVerts[] =
    {
        { { 650.f, 250.f, -.1f }, c_quadColor },
        { { 900.f, 250.f, -.1f }, c_quadColor },
        { { 900.f, 300.f, -.1f }, c_quadColor },
        { { 650.f, 300.f, -.1f }, c_quadColor },
    };

    const DirectX::VertexPositionColor c_scriptOutputVerts[] =
    {
        { { 100.f, 310.f, -.1f }, c_quadColor },
        { { 900.f, 310.f, -.1f }, c_quadColor },
        { { 900.f, 600.f, -.1f }, c_quadColor },
        { { 100.f, 600.f, -.1f }, c_quadColor },
    };

    const DirectX::VertexPositionColor c_fundsVerts[] =
    {
        { { 650.f, 650.f, -.1f }, c_quadColor },
        { { 900.f, 650.f, -.1f }, c_quadColor },
        { { 900.f, 700.f, -.1f }, c_quadColor },
        { { 650.f, 700.f, -.1f }, c_quadColor },
    };

    const DirectX::VertexPositionColor c_consoleVerts[] =
    {
        { { 955.f, 250.f, -.1f }, c_quadColor },
        { { 1843.f, 250.f, -.1f }, c_quadColor },
        { { 1843.f, 700.f, -.1f }, c_quadColor },
        { { 955.f, 700.f, -.1f }, c_quadColor },
    };
}

Sample::Sample() noexcept(false) :
    m_frame(0)
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();

    m_liveResources = std::make_shared<ATG::LiveResources>();
    m_liveInfoHUD = std::make_unique<ATG::LiveInfoHUD>(L"PlayFabCloudScripts Sample");
    m_playFabResources = std::make_shared<ATG::PlayFabResources>(L"DC0");
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

    m_liveResources->SetUserChangedCallback([this](ATG::XboxLiveUser user)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
    });

    m_liveResources->SetUserSignOutCompletedCallback([this](ATG::XboxLiveUser user)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
    });

    m_playFabResources->SetPlayFabUserChangedCallback([this](LoginResult result)
    {
        // A script has been set up in the PlayFab dashboard to run every time an auth token is requested by a
        //  player. This functionality can be found in the Automation tab of your PlayFab dashboard. The script
        //  that runs simply changes a statistic for the user to track the number of times they have retrieved
        //  a token for this title.
        m_console->Write(L"Current PlayFab user: ");
        m_console->WriteLine(WidenString(result.PlayFabId).c_str());
        
        GetPlayerStatisticsRequest request;
        request.StatisticNames.push_back("loginCount");

        PlayFabClientAPI::GetPlayerStatistics(request, [this](const GetPlayerStatisticsResult& result, void*)
        {
            for each(auto stat in result.Statistics)
            {
                if(strcmp(stat.StatisticName.c_str(), "loginCount") == 0)
                {
                    wchar_t buffer[200] = {};
                    swprintf_s(buffer, L"How many times have you logged in? %i", stat.Value);
                    m_console->WriteLine(buffer);
                    break;
                }
            }
        }, OnPlayFabError, m_console.get());
    });

    m_liveResources->Initialize();
    m_liveInfoHUD->Initialize(m_liveResources->GetLiveContext());
    m_playFabResources->Initialize(); 

    if (!m_liveResources->IsUserSignedIn())
        m_console->WriteLine(L"This sample requires someone to be logged in. Hit the menu button to open the account picker.");

    m_lastRequestTickCount = 0;
    m_balance = 0;
    m_showRecieptTickCount = 0;
    m_fundsAdded = 0;
}

// Run a cloud script to attempt to add funds to the player
void Sample::TryAddFunds()
{
    // Don't send requests too frequently
    if (m_lastRequestTickCount < 30)
    {
        OutputDebugString(L"Prevent requests that are too frequent to save bandwidth\n");
        return;
    }
    m_lastRequestTickCount = 0;

    // The script to run is defined in the PlayFab dashboard as handlers.addCurrencyToPlayer
    ExecuteCloudScriptRequest request;
    request.FunctionName = "addCurrencyToPlayer";

    PlayFabClientAPI::ExecuteCloudScript(request, [=](const ExecuteCloudScriptResult& result, void* custom)
    {
        try
        {
            m_fundsAdded = result.FunctionResult.as_integer();
            m_showRecieptTickCount = c_ticksToShowReceipt;
        }
        catch (std::exception& ex)
        {
            m_console->WriteLine(L"An error occurred. Check the debug output for more info.");
            OutputDebugStringA(ex.what());
            OutputDebugString(L"\n");
        }
        OnCloudScriptExecuted(result, custom);
    }, OnPlayFabError, m_console.get());
}

// Check the user's inventory to see how much virtual currency they have
void Sample::CheckFunds()
{
    // Don't send requests too frequently
    if (m_lastRequestTickCount < 30)
    {
        OutputDebugString(L"Prevent requests that are too frequent to save bandwidth\n");
        return;
    }
    m_lastRequestTickCount = 0;

    GetUserInventoryRequest request;
    
    PlayFabClientAPI::GetUserInventory(request, [=](const GetUserInventoryResult& result, void*)
    {
        // Virtual currencies are identified by the two-letter codes they are given when they are created.
        //  The currency for this game are "Duckets" denoted by the string "DU". Currencies can be created
        //  or edited in the Economy tab in your PlayFab dashboard.
        auto duckets = result.VirtualCurrency.at(c_ducketsCode);

        wchar_t buffer[100] = {};
        swprintf_s(buffer, L"Current balance: %i", duckets);
        m_console->WriteLine(buffer);

        m_balance = duckets;
    }, OnPlayFabError, m_console.get());
}

// Run the "helloWorld" script that is provided by PlayFab to use as a reference for your own custom scripting
void Sample::RunHelloWorldScript()
{
    // Don't send requests too frequently
    if (m_lastRequestTickCount < 30)
    {
        OutputDebugString(L"Prevent requests that are too frequent to save bandwidth\n");
        return;
    }
    m_lastRequestTickCount = 0;

    ExecuteCloudScriptRequest request;
    request.FunctionName = "helloWorld";

    // This script uses parameters. They are passed to the script as a list of key/value pairs. In this case the
    //  script uses a parameter called "inputValue". Parameters can be given any name and any value.
    request.FunctionParameter = web::json::value::parse(L"{\"inputValue\": \"This string has been to|the cloud and back\"}");

    PlayFabClientAPI::ExecuteCloudScript(request, [=](const ExecuteCloudScriptResult& result, void* custom)
    {
        try
        {
            auto beginIter = result.Logs.begin();
            beginIter++;
            auto obj = beginIter->Data.as_object();
            m_messageToDisplay = obj[L"input"].as_string().c_str();

            auto replace = m_messageToDisplay.find_first_of(L'|');
            m_messageToDisplay[replace] = L'\n';
        }
        catch (std::exception& ex)
        {
            m_console->WriteLine(L"An error occurred. Check debug output for more info.");
            OutputDebugStringA(ex.what());
            OutputDebugString(L"\n");
        }
        OnCloudScriptExecuted(result, custom);
    }, OnPlayFabError, m_console.get());
}

// Check the results returned from a cloud script and render it to the screen
void Sample::OnCloudScriptExecuted(const PlayFab::ClientModels::ExecuteCloudScriptResult& result, void* data)
{
    auto console = reinterpret_cast<DX::TextConsole*>(data);
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
        wcscat_s(buffer, L"No function result was returned");
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

    console->WriteLine(buffer);
}

void Sample::OnPlayFabError(const PlayFabError& error, void* data)
{
    auto console = reinterpret_cast<DX::TextConsole*>(data);
    wchar_t buffer[2000];
    swprintf_s(buffer, L"%hs\n%hs\nError: %i\nURL Path: %hs\nHTTP code: %i\nHTTP status: %hs\nError details: %ls\n",
        error.ErrorName.c_str(),
        error.ErrorMessage.c_str(),
        error.ErrorCode,
        error.UrlPath.c_str(),
        error.HttpCode,
        error.HttpStatus.c_str(),
        error.ErrorDetails.serialize().c_str());

    console->WriteLine(buffer);
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
    m_lastRequestTickCount++;

    auto pad = m_gamePad->GetState(0);
    if (pad.IsConnected())
    {
        m_gamePadButtons.Update(pad);

        if (pad.IsViewPressed())
        {
            ExitSample();
        }

        if (m_gamePadButtons.a == GamePad::ButtonStateTracker::PRESSED)
        {
            m_playFabResources->RefreshPlayFabToken();
        }

        if (m_gamePadButtons.b == GamePad::ButtonStateTracker::PRESSED)
        {
            RunHelloWorldScript();
        }

        if (m_gamePadButtons.x == GamePad::ButtonStateTracker::PRESSED)
        {
            TryAddFunds();
        }

        if (m_gamePadButtons.y == GamePad::ButtonStateTracker::PRESSED)
        {
            CheckFunds();
        }

        if (m_gamePadButtons.menu == GamePad::ButtonStateTracker::PRESSED)
        {
            Windows::Xbox::UI::SystemUI::ShowAccountPickerAsync(nullptr, Windows::Xbox::UI::AccountPickerOptions::None);
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

    // Draw screen partitions to make text more readable
    context->OMSetBlendState(m_states->Opaque(), nullptr, 0xFFFFFFFF);
    context->OMSetDepthStencilState(m_states->DepthNone(), 0);
    context->RSSetState(m_states->CullNone());

    m_drawEffect->Apply(context);
    context->IASetInputLayout(m_drawInputLayout.Get());
    m_drawBatch->Begin();

    m_drawBatch->DrawQuad(c_userIdVerts[0], c_userIdVerts[1], c_userIdVerts[2], c_userIdVerts[3]);
    m_drawBatch->DrawQuad(c_fundsVerts[0], c_fundsVerts[1], c_fundsVerts[2], c_fundsVerts[3]);
    m_drawBatch->DrawQuad(c_balanceVerts[0], c_balanceVerts[1], c_balanceVerts[2], c_balanceVerts[3]);
    m_drawBatch->DrawQuad(c_consoleVerts[0], c_consoleVerts[1], c_consoleVerts[2], c_consoleVerts[3]);
    m_drawBatch->DrawQuad(c_scriptOutputVerts[0], c_scriptOutputVerts[1], c_scriptOutputVerts[2], c_scriptOutputVerts[3]);

    m_drawBatch->End();
    
    // Draw screen elements
    m_liveInfoHUD->Render();
    m_console->Render();

    m_batch->Begin();

    DX::DrawControllerString(m_batch.get(), m_font.get(), m_ctrlFont.get(), L"[A] Refresh PlayFab login\n[X] Withdraw money", c_leftLegendPos);
    DX::DrawControllerString(m_batch.get(), m_font.get(), m_ctrlFont.get(), L"[B] \"Hello, World!\"\n[Y] Check funds", c_rightLegendPos);

    m_font->DrawString(m_batch.get(), L"Raw output", c_consoleTagPos, DirectX::Colors::LightGray);
    m_font->DrawString(m_batch.get(), L"PLayFab User ID", c_userIdTagPos, DirectX::Colors::LightGray);
    m_font->DrawString(m_batch.get(), L"Balance", c_balanceTagPos, DirectX::Colors::LightGray);
    m_font->DrawString(m_batch.get(), L"Add Funds", c_fundsTagPos, DirectX::Colors::LightGray);

    // Display the message from the Hello, World script if it has been run
    if (!m_messageToDisplay.empty())
        m_largeFont->DrawString(m_batch.get(), m_messageToDisplay.c_str(), c_messagePos, DirectX::Colors::White);

    // Display the latest balance queried
    wchar_t balanceBuffer[10] = {};
    _itow_s(m_balance, balanceBuffer, 10);
    m_largeFont->DrawString(m_batch.get(), balanceBuffer, c_balancePos, DirectX::Colors::Yellow);

    // Display the last amount of funds withdrawn, if appropriate
    if (m_showRecieptTickCount > 0)
    {
        --m_showRecieptTickCount;
        wchar_t fundsBuffer[10] = {};
        _itow_s(m_fundsAdded, fundsBuffer, 10);
        m_largeFont->DrawString(m_batch.get(), fundsBuffer, c_fundsPos, DirectX::Colors::SkyBlue);
    }

    // Display the player's ID
    m_largeFont->DrawString(m_batch.get(), WidenString(m_playFabResources->GetPlayFabLogin().PlayFabId.c_str()).c_str(), c_userIdPos, DirectX::Colors::Green);

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
    m_batch = std::make_unique<SpriteBatch>(context);

    m_font = std::make_unique<SpriteFont>(device, L"SegoeUI_18.spritefont");
    m_largeFont = std::make_unique<SpriteFont>(device, L"SegoeUI_36.spritefont");
    m_ctrlFont = std::make_unique<SpriteFont>(device, L"XboxOneController.spritefont");

    m_liveInfoHUD->RestoreDevice(context);

    m_console = std::make_unique<DX::TextConsole>(context, L"Courier_16.spritefont");

    // Setup for drawing screen parititions
    m_states = std::make_unique<CommonStates>(device);
    m_drawEffect = std::make_unique<BasicEffect>(device);
    m_drawEffect->SetVertexColorEnabled(true);

    void const* byteCode;
    size_t byteCodeLength;

    m_drawEffect->GetVertexShaderBytecode(&byteCode, &byteCodeLength);

    DX::ThrowIfFailed(
        device->CreateInputLayout(VertexPositionColor::InputElements,
            VertexPositionColor::InputElementCount,
            byteCode, byteCodeLength,
            m_drawInputLayout.ReleaseAndGetAddressOf()));

    m_drawBatch = std::make_unique<PrimitiveBatch<VertexPositionColor>>(context);
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
    m_console->SetWindow(c_consoleDisplay);

    auto size = m_deviceResources->GetOutputSize();
    auto vp = m_deviceResources->GetScreenViewport();
    SimpleMath::Matrix proj = SimpleMath::Matrix::CreateOrthographicOffCenter(0.f, float(vp.Width), float(vp.Height), 0.f, 0.f, 1.f);
    m_drawEffect->SetProjection(proj);
}
#pragma endregion
