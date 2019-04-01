//--------------------------------------------------------------------------------------
// RenderManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------
#pragma once

#include "Manager.h"
#include "DeviceResources.h"

#include "RenderContext.h"

#include "SpriteBatch.h"

namespace DirectX
{
    class SpriteBatch;
    class CommonStates;
}

namespace BumbleRumble
{
    enum class BlendMode
    {
        Default,
        NonPremultiplied,
        Additive
    };

    class RenderManager : public Manager
    {
    public:
        RenderManager();
        ~RenderManager();

        void Initialize(IUnknown* window);

        void Prepare();
        void Clear();
        void Present();

        void Suspend();
        void Resume();

        std::shared_ptr<RenderContext> GetRenderContext(BlendMode mode = BlendMode::Default);

        ID3D11Device1* GetD3DDevice() const { return m_deviceResources->GetD3DDevice(); }
        RECT GetOutputSize() const { return m_deviceResources->GetOutputSize(); }

    private:
        std::unique_ptr<DX::DeviceResources>        m_deviceResources;
        std::unique_ptr<DirectX::GraphicsMemory>    m_graphicsMemory;
        std::shared_ptr<DirectX::SpriteBatch>       m_spriteBatch;
        std::shared_ptr<DirectX::CommonStates>      m_commonStates;
    };
}