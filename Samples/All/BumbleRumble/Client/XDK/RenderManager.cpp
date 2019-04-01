//--------------------------------------------------------------------------------------
// RenderManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once
#include "pch.h"
#include "RenderManager.h"
#include "RenderContext.h"
#include "DeviceResources.h"
#include "Managers.h"
#include "SpriteBatch.h"
#include "CommonStates.h"
#include "ATGColors.h"

using namespace DirectX;

namespace
{
    const float c_backgroundColor[4] = { 0, 0, 32.0f / 255.0f, 1.0f };
}

namespace BumbleRumble
{
    RenderManager::RenderManager()
    {
        m_deviceResources = std::make_unique<DX::DeviceResources>();
    }

    RenderManager::~RenderManager()
    {

    }

    std::shared_ptr<RenderContext> RenderManager::GetRenderContext(BlendMode mode)
    {
        ID3D11BlendState *blendstate = nullptr;

        switch (mode)
        {
        case BlendMode::NonPremultiplied:
            blendstate = m_commonStates->NonPremultiplied();
            break;
        case BlendMode::Additive:
            blendstate = m_commonStates->Additive();
            break;
        default:
            break;
        };

        std::shared_ptr<RenderContext> context;
        context.reset(new RenderContext(m_spriteBatch, blendstate));

        return context;

    }

    void RenderManager::Initialize(IUnknown* window)
    {
        m_deviceResources->SetWindow(window);
        m_deviceResources->CreateDeviceResources();

        m_spriteBatch = std::make_shared<DirectX::SpriteBatch>(m_deviceResources->GetD3DDeviceContext());
        m_commonStates = std::make_shared<DirectX::CommonStates>(m_deviceResources->GetD3DDevice());
        m_graphicsMemory = std::make_unique<GraphicsMemory>(m_deviceResources->GetD3DDevice(), m_deviceResources->GetBackBufferCount());

        m_deviceResources->CreateWindowSizeDependentResources();
    }

    void RenderManager::Prepare()
    {
        m_deviceResources->Prepare();
    }

    void RenderManager::Clear()
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

    void RenderManager::Present()
    {
        m_deviceResources->Present();
        m_graphicsMemory->Commit();
    }

    void RenderManager::Suspend()
    {
        m_deviceResources->GetD3DDeviceContext()->Suspend(0);
    }

    void RenderManager::Resume()
    {
        m_deviceResources->GetD3DDeviceContext()->Resume();
    }
}