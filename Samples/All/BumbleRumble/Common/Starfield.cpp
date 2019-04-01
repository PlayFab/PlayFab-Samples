//--------------------------------------------------------------------------------------
// Starfield.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "Managers.h"
#include "Starfield.h"
#include "Game.h"

using namespace BumbleRumble;
using namespace DirectX;

Starfield::Starfield(DirectX::SimpleMath::Vector2 position) :
    m_lastPosition(position),
    m_position(position)
{
    for (size_t i = 0; i < m_stars.size(); i++)
    {
        m_stars[i] = SimpleMath::Vector2(0, 0);
    }

    for (int i = 0; i < 8; i++)
    {
        SetLayerSize(i, 0);
    }

    SetLayerColor(0, 255.0f);
    SetLayerColor(1, 216.0f);
    SetLayerColor(2, 192.0f);
    SetLayerColor(3, 160.0f);
    SetLayerColor(4, 128.0f);
    SetLayerColor(5, 96.0f);
    SetLayerColor(6, 64.0f);
    SetLayerColor(7, 32.0f);

    // load the star texture
    m_starTexture = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\Blank.png");
}

Starfield::~Starfield()
{
}

void Starfield::Reset(DirectX::SimpleMath::Vector2 position)
{
    // recreate the stars
    auto renderManager = Managers::Get<RenderManager>();
    int viewportWidth = static_cast<int>(renderManager->GetOutputSize().right);
    int viewportHeight = static_cast<int>(renderManager->GetOutputSize().bottom);

    for (size_t i = 0; i < m_stars.size(); i++)
    {
        m_stars[i] = SimpleMath::Vector2(static_cast<float>(rand() % viewportWidth), static_cast<float>(rand() % viewportHeight));
    }

    // reset the position
    m_lastPosition = m_position = position;
}

void Starfield::Draw(DirectX::SimpleMath::Vector2 position)
{
    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext(BlendMode::NonPremultiplied);

    // update the current position
    m_lastPosition = m_position;
    m_position = position;

    // determine the movement vector of the stars
    // -- for the purposes of the parallax effect, 
    //    this is the opposite direction as the position movement.
    SimpleMath::Vector2 movement = m_lastPosition - position;

    // create a rectangle representing the screen dimensions of the starfield
    int viewportWidth = static_cast<int>(renderManager->GetOutputSize().right);
    int viewportHeight = static_cast<int>(renderManager->GetOutputSize().bottom);
    RECT starfieldRectangle = { 0, 0, viewportWidth, viewportHeight };

    //// draw a background color for the starfield
    renderContext->Begin();
    renderContext->Draw(m_starTexture, starfieldRectangle, c_backgroundColor);
    renderContext->End();

    // if we've moved too far, then reset, as the stars will be moving too fast
    if (movement.LengthSquared() > c_maximumMovementPerUpdate * c_maximumMovementPerUpdate)
    {
        Reset(position);
        return;
    }

    // draw all of the stars
    renderContext->Begin();

    for (auto n = c_numberOfLayers - 1; n >= 0; n--)
    {
        for (size_t i = 0; i < m_stars.size(); i++)
        {
            // move the star based on the depth
            size_t depth = i % c_movementFactors.size();

            if (depth != n)
            {
                continue;
            }

            SimpleMath::Vector2 p = m_stars[i];
            p += movement * c_movementFactors[depth];

            // wrap the stars around
            if (p.x < 0 - m_layerSizes[depth])
            {
                p.x = static_cast<float>(viewportWidth);
                p.y = static_cast<float>(rand() % viewportHeight);
            }
            if (p.x > viewportWidth)
            {
                p.x = static_cast<float>(0 - m_layerSizes[depth]);
                p.y = static_cast<float>(rand() % viewportHeight);
            }
            if (p.y < 0 - m_layerSizes[depth])
            {
                p.x = static_cast<float>(rand() % viewportWidth);
                p.y = static_cast<float>(viewportHeight);
            }
            if (p.y > viewportHeight)
            {
                p.x = static_cast<float>(rand() % viewportWidth);
                p.y = static_cast<float>(0 - m_layerSizes[depth]);
            }

            m_stars[i] = p;

            // draw the star
            RECT b = { (int)p.x, (int)p.y, (int)p.x + c_starSize, (int)p.y + c_starSize };
            renderContext->Draw(m_starTexture, b, m_layerColors[depth]);
        }
    }

    renderContext->End();
}