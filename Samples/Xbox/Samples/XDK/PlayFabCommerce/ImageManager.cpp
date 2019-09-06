//--------------------------------------------------------------------------------------
// File: ImageManager.cpp
//
// Class to handle the downloading, lifetime, and storage of images
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//-------------------------------------------------------------------------------------
#include "pch.h"
#include "ImageManager.h"

#include "HttpCall.h"
#include "SampleGUI.h"
#include "WICTextureLoader.h"

using Microsoft::WRL::ComPtr;

ImageManager *ImageManager::s_inst = nullptr;

ImageManager::ImageManager(std::shared_ptr<ATG::HttpCallManager> &callManager) : m_callManager(callManager)
{
    if (s_inst != nullptr)
    {
        throw std::exception("Image Manager is a singleton");
    }

    s_inst = this;
}

void ImageManager::RestoreDevice(ID3D11DeviceX *device)
{
    m_device = device;
}

ID3D11ShaderResourceView *ImageManager::GetImage(const std::wstring &imageName)
{
    std::lock_guard<std::mutex> lock_guard(s_inst->m_imageLock);
    auto image = m_images.find(imageName);
    if (image != m_images.end())
    {
        return image->second.Get();
    }
    return nullptr;
}

void ImageManager::RemoveImage(const std::wstring &imageName)
{
    m_images.erase(imageName);
}

void ImageManager::LoadImageFromFile(const wchar_t *imageName, const wchar_t *fileName)
{
    ComPtr<ID3D11ShaderResourceView> image;

    DirectX::CreateWICTextureFromFile(s_inst->m_device.Get(), fileName, nullptr, image.GetAddressOf());

    std::lock_guard<std::mutex> lock_guard(s_inst->m_imageLock);
    s_inst->m_images[imageName] = image;
}

void ImageManager::DownloadImage(const wchar_t *url, const wchar_t *imageName)
{
    if (m_callManager.expired())
    {
        return;
    }

    auto callManager = m_callManager.lock();
    std::wstring imageNameString = imageName;
    callManager->MakeHttpCall(L"GET", url, std::vector<ATG::HttpHeader>(), [imageNameString](ATG::HttpResponse *response)
    {
        DownloadImageHandler(response, imageNameString);
    });
}

void ImageManager::DownloadImageHandler(ATG::HttpResponse *response, const std::wstring &imageName)
{
    if (response->IsError())
    {
        return;
    }

    if (s_inst == nullptr)
    {
        throw std::exception("Image Manager has not been initialized.");
    }

    ComPtr<ID3D11ShaderResourceView> image;

    DirectX::CreateWICTextureFromMemory(s_inst->m_device.Get(), response->ResponseBody().get(), response->ResponseBodySize(), nullptr, image.GetAddressOf());

    std::lock_guard<std::mutex> lock_guard(s_inst->m_imageLock);
    s_inst->m_images[imageName] = image;
    auto imagenametemp = imageName + L"\n";
}
