//--------------------------------------------------------------------------------------
// PlayFabNewsFeed.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayFabNewsFeed.h"

#include "ATGColors.h"
#include <sstream>

extern void ExitSample();

using namespace DirectX;

using Microsoft::WRL::ComPtr; 

using namespace PlayFab;
using namespace PlayFab::ClientModels;

Sample::Sample() noexcept(false) :
    m_frame(0)
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();

    m_liveResources = std::make_shared<ATG::LiveResources>();
    m_liveInfoHUD = std::make_unique<ATG::LiveInfoHUD>(L"PlayFabNewsFeed Sample");
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

    m_playFabResources->SetPlayFabUserChangedCallback([this](LoginResult)
    {
        m_console->Clear();
        RefreshNewsFeed();
    });

    m_liveResources->Initialize();
    m_liveInfoHUD->Initialize(m_liveResources->GetLiveContext());
    m_playFabResources->Initialize();

    if (Windows::Xbox::System::User::Users->Size == 0)
    {
        m_console->WriteLine(L"This sample requires someone to be signed in.\nHit \'A\' to open the account picker.");
    }
}

void Sample::RefreshNewsFeed()
{
    m_console->Clear();
    GetTitleNewsRequest request;
    
    // Using the default values in the request retrieves the 10 latest pieces of news
    PlayFabClientAPI::GetTitleNews(request, [this](const GetTitleNewsResult& result, void*)
    {
        for each(auto item in result.News)
        {
            m_console->WriteLine(WidenString(item.Title).c_str());

            struct tm info;
            localtime_s(&info, &item.Timestamp);
            wchar_t buffer[20] = {};
            swprintf_s(buffer, L"%02d/%02d/%4d %02d:%02d", info.tm_mon + 1, info.tm_mday, info.tm_year + 1900, info.tm_hour, info.tm_min);
            m_console->WriteLine(buffer);

            m_console->WriteLine(WidenString(item.Body).c_str());
            m_console->WriteLine(L"");
        }
    }, [this](const PlayFabError& error, void*)
    {
        wchar_t buffer[2000];
        swprintf_s(buffer, L"%S\n%S\nError: %i\nURL Path: %S\nHTTP code: %i\nHTTP status: %S\n",
            error.ErrorName.c_str(),
            error.ErrorMessage.c_str(),
            error.ErrorCode,
            error.UrlPath.c_str(),
            error.HttpCode,
            error.HttpStatus.c_str());
        OutputDebugString(buffer);
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
    elapsedTime;

    auto pad = m_gamePad->GetState(0);
    if (pad.IsConnected())
    {
        m_gamePadButtons.Update(pad);

        if (pad.IsViewPressed())
        {
            ExitSample();
        }

        if (pad.IsAPressed())
        {
            m_playFabResources->RefreshPlayFabToken();
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
        
    m_liveInfoHUD->Render();
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
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
    static const RECT consoleDisplay = { 200, 150, 1838, 825 };
    m_console->SetWindow(consoleDisplay);
}
#pragma endregion
