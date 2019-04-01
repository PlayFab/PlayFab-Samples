//--------------------------------------------------------------------------------------
// ContentManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Manager.h"
#include "ContentManager.h"
#include "Managers.h"

using namespace BumbleRumble;
using namespace DirectX;

ContentManager::ContentManager()
{
}

ContentManager::~ContentManager()
{
    m_textures.clear();
}

std::shared_ptr<DX::Texture> ContentManager::LoadTexture(const std::string &path)
{
    std::string lowerPath = path;
    // Lower case the path for our map
    std::transform(lowerPath.begin(), lowerPath.end(), lowerPath.begin(), [](char wc) { return static_cast<char>(std::tolower(wc)); });

    // Look in our cache first
    auto itr = m_textures.find(lowerPath);
    if (itr != m_textures.end())
    {
        return itr->second;
    }

    return std::make_shared<DX::Texture>(Managers::Get<RenderManager>()->GetD3DDevice(), lowerPath.c_str());
}

std::shared_ptr<SpriteFont> ContentManager::LoadFont(const std::string &path)
{
    std::string lowerPath = path;
    // Lower case the path for our map
    std::transform(lowerPath.begin(), lowerPath.end(), lowerPath.begin(), [](char wc) { return static_cast<char>(std::tolower(wc)); });

    // Look in our cache first
    auto itr = m_fonts.find(lowerPath);
    if (itr != m_fonts.end())
    {
        return itr->second;
    }

    // Otherwise use the WICTextureLoader APIs to load the texture into our cache
    auto font = std::make_shared<SpriteFont>(Managers::Get<RenderManager>()->GetD3DDevice(), StrToWStr(lowerPath).c_str());
    font->SetDefaultCharacter(L'?');
    m_fonts[lowerPath] = font;

    return font;
}