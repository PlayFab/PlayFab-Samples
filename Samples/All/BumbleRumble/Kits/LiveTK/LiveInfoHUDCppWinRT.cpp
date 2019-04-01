//--------------------------------------------------------------------------------------
// File: LiveInfoHUDCppWinRT.cpp
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
#include "pch.h"
#include "LiveInfoHUDCppWinRT.h"

#include "ATGColors.h"
#include "WICTextureLoader.h"

#ifndef _XBOX_ONE
#include "cpprest/uri.h"
#include "winrt/Microsoft.Xbox.Services.Social.h"
#endif

using namespace winrt::Microsoft::Xbox::Services;

#if defined(_XBOX_ONE) && defined(_TITLE)
using namespace winrt::Windows::Xbox::System;
#endif

namespace ATG
{
    LiveInfoHUD::LiveInfoHUD(_In_z_ wchar_t const* sampleTitle) :
        m_sampleTitle(sampleTitle),
        m_gamerTag(L"No User Signed in"),
        m_width(0),
        m_height(0)
    {

    }

    void LiveInfoHUD::Initialize(const XboxLiveContext& context, int windowWidth, int windowHeight)
    {
        const auto& config = XboxLiveAppConfiguration::SingletonInstance();

        m_serviceConfigId = config.ServiceConfigurationId();

        wchar_t buffer[16] = {};
        swprintf_s(buffer,L"0x%08X",config.TitleId());
        m_titleId = buffer;

        m_sandboxId = config.Sandbox();

        if (context)
        {
            SetUser(context);
        }

        SetWindowSize(windowWidth, windowHeight);
    }

    void LiveInfoHUD::ReleaseDevice()
    {
        m_batch.reset();
        m_smallFont.reset();
        m_boldFont.reset();
        m_titleFont.reset();
        m_gamerPic.Reset();
        m_context.Reset();
    }

    void LiveInfoHUD::RestoreDevice(_In_ ID3D11DeviceContext* context)
    {
        m_context = context;
        m_batch = std::make_unique<DirectX::SpriteBatch>(context);

        Microsoft::WRL::ComPtr<ID3D11Device> device;
        context->GetDevice(device.GetAddressOf());

        m_smallFont = std::make_unique<DirectX::SpriteFont>(device.Get(), L"SegoeUI_18.spritefont");
        m_boldFont = std::make_unique<DirectX::SpriteFont>(device.Get(), L"SegoeUI_18_Bold.spritefont");
        m_titleFont = std::make_unique<DirectX::SpriteFont>(device.Get(), L"SegoeUI_36.spritefont");

        SetGamerPic();
    }

    void LiveInfoHUD::SetUser(const XboxLiveContext& context)
    {
        if (!context || !context.User() || !context.User().IsSignedIn())
        {
            m_gamerTag = L"No User Signed in";
            SetGamerPic();
        }
        else
        {
#if defined(_XBOX_ONE) && defined(_TITLE)
            m_gamerTag = context.User().DisplayInfo().Gamertag();
#else
            m_gamerTag = context.User().Gamertag();

            // sandbox is not available in UWP apps until a user has signed in
            const auto& config = XboxLiveAppConfiguration::SingletonInstance();
            m_sandboxId = config.Sandbox();
#endif

            GetGamerPic(context);
        }
    }

    void LiveInfoHUD::Render()
    {
#if defined(_XBOX_ONE) && defined(_TITLE)
        static const DirectX::XMMATRIX scale = DirectX::XMMatrixIdentity();
#else
        DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(m_width / 1920.f, m_height / 1080.f, 1.f);
#endif
        m_batch->Begin(DirectX::SpriteSortMode_Deferred, nullptr, nullptr, nullptr, nullptr, nullptr, scale);

        m_titleFont->DrawString(m_batch.get(), m_sampleTitle.c_str(), DirectX::XMFLOAT2(78.f, 44.f), ATG::Colors::OffWhite, 0.0f);

        m_boldFont->DrawString(m_batch.get(), L"Sandbox Id:", DirectX::XMFLOAT2(270.f, 1019.f), ATG::Colors::OffWhite, 0.0f);
        m_boldFont->DrawString(m_batch.get(), L"Title Id:", DirectX::XMFLOAT2(590.f, 1019.f), ATG::Colors::OffWhite, 0.0f);
        m_boldFont->DrawString(m_batch.get(), L"Service Config Id:", DirectX::XMFLOAT2(950.f, 1019.f), ATG::Colors::OffWhite, 0.0f);

        m_smallFont->DrawString(m_batch.get(), m_sandboxId.c_str(), DirectX::XMFLOAT2(410.f, 1019.f), ATG::Colors::OffWhite, 0.0f);
        m_smallFont->DrawString(m_batch.get(), m_titleId.c_str(), DirectX::XMFLOAT2(680.f, 1019.f), ATG::Colors::OffWhite, 0.0f);
        m_smallFont->DrawString(m_batch.get(), m_serviceConfigId.c_str(), DirectX::XMFLOAT2(1155.f, 1019.f), ATG::Colors::OffWhite, 0.0f);

        m_smallFont->DrawString(m_batch.get(), m_serviceConfigId.c_str(), DirectX::XMFLOAT2(1155.f, 1019.f), ATG::Colors::OffWhite, 0.0f);

        auto pos = DirectX::XMFLOAT2(1770.f, 70.f);
        pos.x -= DirectX::XMVectorGetX(m_smallFont->MeasureString(m_gamerTag.c_str()));

        m_smallFont->DrawString(m_batch.get(), m_gamerTag.c_str(), pos, ATG::Colors::OffWhite, 0.0f);

        static const RECT gamerPicRect = { 1780, 55, 1780 + 64, 55 + 64 };

        m_batch->Draw(m_gamerPic.Get(), gamerPicRect);

        m_batch->End();
    }

    void LiveInfoHUD::GetGamerPic(const winrt::Microsoft::Xbox::Services::XboxLiveContext& context)
    {
        auto user = context.User();
        if (user)
        {
#if defined(_XBOX_ONE) && defined(_TITLE)
            GetGamerPicAsync(user);
#else
            GetGamerPicAsync(context);
#endif
        }
    }

#if defined(_XBOX_ONE) && defined(_TITLE)
    winrt::Windows::Foundation::IAsyncAction LiveInfoHUD::GetGamerPicAsync(winrt::Windows::Xbox::System::User user)
    {
        auto buffer = winrt::Windows::Storage::Streams::Buffer(1024 * 8);

        auto result = co_await user.DisplayInfo().GetGamerPictureAsync(
            winrt::Windows::Xbox::System::UserPictureSize::Small,
            buffer);

        if (result.Result() == E_BOUNDS)
        {
            buffer = winrt::Windows::Storage::Streams::Buffer(result.RequiredBufferSize());

            result = co_await user.DisplayInfo().GetGamerPictureAsync(
                winrt::Windows::Xbox::System::UserPictureSize::Small,
                buffer);
        }

        if (SUCCEEDED(result.Result()))
        {
            auto reader = winrt::Windows::Storage::Streams::DataReader::FromBuffer(buffer);
            auto length = reader.UnconsumedBufferLength();
            std::vector<uint8_t> data(length);

            if (!data.empty())
            {
                reader.ReadBytes(data);
                SetGamerPic(data.data(), data.size());
            }
        }
    }
#else
    winrt::Windows::Foundation::IAsyncAction LiveInfoHUD::GetGamerPicAsync(const winrt::Microsoft::Xbox::Services::XboxLiveContext& context)
    {
        // UWP requires use of the profile service to get the gamer pic for a user
        auto userProfile = co_await context.ProfileService().GetUserProfileAsync(context.User().XboxUserId());

        if (!userProfile)
            return;

        auto uri = web::uri(userProfile.GameDisplayPictureResizeUri().AbsoluteUri().c_str());

        try
        {
            web::uri_builder pathQueryFragment;
            pathQueryFragment.append_path(uri.path());
            auto split = web::uri::split_query(uri.query());
            pathQueryFragment.append_query(L"url", split[L"url"]);
            pathQueryFragment.append_query(L"format", split[L"format"]);

            auto liveHttpCall = XboxLiveHttpCall::CreateXboxLiveHttpCall(context.Settings(), L"GET", uri.scheme() + L"://" + uri.host(), pathQueryFragment.to_string());
            auto response = co_await liveHttpCall.GetResponseWithoutAuth(HttpCallResponseBodyType::VectorBody);
            
            if (response.ErrorCode())
                return;

            auto image = response.ResponseBodyVector();
            SetGamerPic(image.data(), image.size());
        }
        catch (...)
        {
            OutputDebugString(L"Creating an HTTP call to get a gamerpic or getting its response threw an exception\n");
        }
    }
#endif

    void LiveInfoHUD::SetGamerPic(_In_ uint8_t const* data, size_t size)
    {
        if (!m_context)
            return;

        HRESULT hr = E_FAIL;
        Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> tex;
        Microsoft::WRL::ComPtr<ID3D11Device> device;

        m_context->GetDevice(device.GetAddressOf());

        if (data && size > 0)
        {
            hr = DirectX::CreateWICTextureFromMemory(
                device.Get(),
                data,
                size,
                nullptr,
                tex.GetAddressOf()
            );
        }
        else
        {
            hr = DirectX::CreateWICTextureFromFile(
                device.Get(),
                L".\\Assets\\GamerPic.png",
                nullptr,
                tex.GetAddressOf());
        }

        if (SUCCEEDED(hr))
        {
            m_gamerPic.Swap(tex); // take ownership of resource
        }
    }
}