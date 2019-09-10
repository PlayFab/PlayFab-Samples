//--------------------------------------------------------------------------------------
// File: ImageManager.h
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
#pragma once

#include <map>
#include <memory>
#include <string>

struct ID3D11DeviceX;
struct ID3D11ShaderResourceView;

namespace ATG
{
    class HttpCallManager;
    class HttpResponse;

}

class ImageManager
{
public:
    ImageManager(std::shared_ptr<ATG::HttpCallManager> &callManager);

    ImageManager(ImageManager&& moveFrom) = default;
    ImageManager& operator=(ImageManager&& moveFrom) = default;

    ImageManager(ImageManager const&) = delete;
    ImageManager& operator=(ImageManager const&) = delete;

    void RestoreDevice(ID3D11DeviceX *device);

    void LoadImageFromFile(const wchar_t *imageName, const wchar_t *fileName);
    void DownloadImage(const wchar_t *url, const wchar_t *imageName);

    ID3D11ShaderResourceView *GetImage(const std::wstring &imageName);
    void RemoveImage(const std::wstring &imageName);

    static void DownloadImageHandler(ATG::HttpResponse *response, const std::wstring &imageName);
private:
    static ImageManager *s_inst;

    std::weak_ptr<ATG::HttpCallManager> m_callManager;

    Microsoft::WRL::ComPtr<ID3D11DeviceX> m_device;
    std::mutex                                    m_imageLock;
    std::map<std::wstring, Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>> m_images;
};
