//--------------------------------------------------------------------------------------
// File: LiveInfoHUDCppWinRT.h
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

#if defined(_XBOX_ONE) && defined(_TITLE)
#include <d3d11_x.h>
#else
#include <d3d11_1.h>
#endif

#include "SpriteBatch.h"
#include "SpriteFont.h"

struct ID3D11DeviceContext;
struct ID3D11ShaderResourceView;

namespace ATG
{
    class LiveInfoHUD
    {
    public:
        LiveInfoHUD(_In_z_ wchar_t const* sampleTitle);

        void Initialize(const winrt::Microsoft::Xbox::Services::XboxLiveContext& context, int windowWidth = 0, int windowHeight = 0);

        void ReleaseDevice();
        void RestoreDevice(_In_ ID3D11DeviceContext *context);
        
        void SetUser(const winrt::Microsoft::Xbox::Services::XboxLiveContext& context);

        void Render();

        void SetWindowSize(int width, int height) { m_width = width; m_height = height; }

    private:
        void GetGamerPic(const winrt::Microsoft::Xbox::Services::XboxLiveContext& context);
#if defined(_XBOX_ONE) && defined(_TITLE)
        winrt::Windows::Foundation::IAsyncAction GetGamerPicAsync(winrt::Windows::Xbox::System::User user);
#else
        winrt::Windows::Foundation::IAsyncAction GetGamerPicAsync(const winrt::Microsoft::Xbox::Services::XboxLiveContext& context);
#endif
        void SetGamerPic(_In_ uint8_t const* data = nullptr, size_t size = 0);

        winrt::hstring                                   m_sampleTitle;
        winrt::hstring                                   m_serviceConfigId;
        winrt::hstring                                   m_titleId;
        winrt::hstring                                   m_sandboxId;
        winrt::hstring                                   m_gamerTag;
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