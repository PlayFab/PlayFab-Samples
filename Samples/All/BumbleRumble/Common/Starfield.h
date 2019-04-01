//--------------------------------------------------------------------------------------
// Starfield.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

namespace BumbleRumble
{

class Starfield
{
public:
    Starfield(DirectX::SimpleMath::Vector2 position);
    ~Starfield();

    void Reset(DirectX::SimpleMath::Vector2 position);
    void Draw(DirectX::SimpleMath::Vector2 position);

private:
    static const int c_numberOfStars = 256;
    static const int c_numberOfLayers = 8;

    const float c_maximumMovementPerUpdate = 128.0f;
#pragma warning(push)
#pragma warning(disable: 4324)
    const DirectX::XMVECTOR c_backgroundColor = { 0, 0, 32.0f / 255.0f, 1.0f };
#pragma warning(pop)
    const std::array<float, c_numberOfLayers> c_movementFactors = { 0.9f, 0.8f, 0.7f, 0.6f, 0.5f, 0.4f, 0.3f, 0.2f };
    const int c_starSize = 2;

    std::array<DirectX::XMVECTOR, c_numberOfLayers> m_layerColors;
    std::array<int, c_numberOfLayers> m_layerSizes;

    void SetLayerColor(int i, float a)
    {
        DirectX::XMVECTOR v = { 1.0f, 1.0f, 1.0f, a / 255.0f };
        m_layerColors[i] = v;
    }

    void SetLayerSize(int i, int s)
    {
        m_layerSizes[i] = s;
    }

    DirectX::SimpleMath::Vector2 m_lastPosition;
    DirectX::SimpleMath::Vector2 m_position;
    std::array<DirectX::SimpleMath::Vector2, c_numberOfStars> m_stars;
    std::shared_ptr<DX::Texture> m_starTexture;
};

}
