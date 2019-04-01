//--------------------------------------------------------------------------------------
// ContentManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

namespace BumbleRumble
{

class Manager;

class ContentManager : public Manager
{
public:
    ContentManager();
    ~ContentManager();

    std::shared_ptr<DX::Texture> LoadTexture(const std::string &path);
    std::shared_ptr<DirectX::SpriteFont> LoadFont(const std::string &path);

private:
    std::map<std::string, std::shared_ptr<DX::Texture>> m_textures;
    std::map<std::string, std::shared_ptr<DirectX::SpriteFont>> m_fonts;
};

}
