//--------------------------------------------------------------------------------------
// File: LiveInfoHUD.h
//
// A Heads Up Display (HUD) for Xbox Live samples
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//-------------------------------------------------------------------------------------
#pragma once

#include <memory>
#include <string>

#if defined(_XBOX_ONE) && defined(_TITLE)
#include <d3d11_x.h>
#else
#include <d3d11_1.h>
#endif

#include "SpriteBatch.h"
#include "SpriteFont.h"

namespace xbox
{
    namespace services
    {
        class xbox_live_context;
    }
}

struct ID3D11DeviceContext;
struct ID3D11ShaderResourceView;

namespace ATG
{
    class LiveInfoHUD
    {
    public:
        explicit LiveInfoHUD(_In_z_ wchar_t const* sampleTitle);

        LiveInfoHUD(LiveInfoHUD&&) = delete;
        LiveInfoHUD& operator= (LiveInfoHUD&&) = delete;

        LiveInfoHUD(LiveInfoHUD const&) = delete;
        LiveInfoHUD& operator= (LiveInfoHUD const&) = delete;

        void Initialize(std::shared_ptr<xbox::services::xbox_live_context> context, int windowWidth = 0, int windowHeight = 0);

        void ReleaseDevice();
        void RestoreDevice(_In_ ID3D11DeviceContext* context);

        void SetUser(std::shared_ptr<xbox::services::xbox_live_context> context);

        void Render();

        void SetViewport(const D3D11_VIEWPORT &viewport);

        void SetRotation(DXGI_MODE_ROTATION rotation);

        void SetWindowSize(int width, int height) { m_width = width; m_height = height; }

    private:
        void GetGamerPic(std::shared_ptr<xbox::services::xbox_live_context> context);
        void SetGamerPic(_In_ uint8_t const* data = nullptr, size_t size = 0);

        std::wstring                                     m_sampleTitle;
        std::wstring                                     m_serviceConfigId;
        std::wstring                                     m_titleId;
        std::wstring                                     m_sandboxId;
        std::wstring                                     m_gamerTag;
        Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_gamerPic;

        Microsoft::WRL::ComPtr<ID3D11DeviceContext>      m_context;

        // Direct3D resources
        std::unique_ptr<DirectX::SpriteBatch>        m_batch;
        std::unique_ptr<DirectX::SpriteFont>         m_smallFont;
        std::unique_ptr<DirectX::SpriteFont>         m_boldFont;
        std::unique_ptr<DirectX::SpriteFont>         m_titleFont;

        int                                          m_width;
        int                                          m_height;
    };
}