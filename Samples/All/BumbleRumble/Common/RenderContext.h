//--------------------------------------------------------------------------------------
// RenderContext.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

namespace DirectX
{
    class SpriteBatch;
    class CommonStates;
    class Texture2D;
}

namespace BumbleRumble
{
    enum class TexturePosition
    {
        None,
        Centered
    };

    class RenderContext
    {
    public:
        void Begin(DirectX::FXMMATRIX transformMatrix = MatrixIdentity, DirectX::SpriteSortMode sortMode = DirectX::SpriteSortMode::SpriteSortMode_Deferred);
        void End();

        void Draw(std::shared_ptr<DX::Texture> texture, const DirectX::XMFLOAT2 &position, float rotation = 0.0f, float scale = 1.0f, DirectX::FXMVECTOR color = DirectX::Colors::White, TexturePosition texturePosition = TexturePosition::Centered);
        void Draw(std::shared_ptr<DX::Texture> texture, const RECT &destinationRect, DirectX::FXMVECTOR color = DirectX::Colors::White);

        void DrawString(std::shared_ptr<DirectX::SpriteFont> font, const std::string &message, const DirectX::XMFLOAT2 &position, DirectX::FXMVECTOR color = DirectX::Colors::White, float rotation = 0, const DirectX::XMFLOAT2 &origin = Float2Zero, float scale = 1);
    private:
        RenderContext(std::shared_ptr<DirectX::SpriteBatch> spriteBatch, ID3D11BlendState *blendstate);

        ID3D11BlendState*                     m_blendState;
        std::shared_ptr<DirectX::SpriteBatch> m_spriteBatch;

        static const DirectX::XMMATRIX MatrixIdentity;
        static const DirectX::XMFLOAT2 Float2Zero;

        friend class RenderManager;
    };
}
