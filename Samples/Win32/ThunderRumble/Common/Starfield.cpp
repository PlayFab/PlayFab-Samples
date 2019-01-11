//--------------------------------------------------------------------------------------
// Starfield.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "Managers.h"
#include "Starfield.h"
#include "Game.h"

using namespace ThunderRumble;
using namespace DirectX;

static const float maximumMovementPerUpdate = 128.0f;
static XMVECTOR backgroundColor = { 0, 0, 32.0f / 255.0f, 1.0f };
static const int numberOfLayers = 8;
static std::array<XMVECTOR, numberOfLayers> layerColors;

static void SetLayerColor(int i, float a)
{
    XMVECTOR v = { 1.0f, 1.0f, 1.0f, a / 255.0f };
    layerColors[i] = v;
}
static std::array<int, numberOfLayers> layerSizes;
static void SetLayerSize(int i, int s)
{
    layerSizes[i] = s;
}
static std::array<float, numberOfLayers> movementFactors = { 0.9f, 0.8f, 0.7f, 0.6f, 0.5f, 0.4f, 0.3f, 0.2f };
static const int starSize = 2;

Starfield::Starfield(DirectX::SimpleMath::Vector2 position) :
    m_lastPosition(position),
    m_position(position)
{
    for (size_t i = 0; i < m_stars.size(); i++)
    {
        m_stars[i] = SimpleMath::Vector2(0, 0);
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
    m_starTexture = Managers::Get<ContentManager>()->LoadTexture(L"Assets\\Textures\\Blank.png");
}

Starfield::~Starfield()
{
}

void Starfield::Reset(DirectX::SimpleMath::Vector2 position)
{
    // recreate the stars
    int viewportWidth = TheGame->GetWindowWidth();
    int viewportHeight = TheGame->GetWindowHeight();

    for (size_t i = 0; i < m_stars.size(); i++)
    {
        m_stars[i] = SimpleMath::Vector2(static_cast<float>(rand() % viewportWidth), static_cast<float>(rand() % viewportHeight));
    }

    // reset the position
    m_lastPosition = m_position = position;
}

void Starfield::Draw(DirectX::SimpleMath::Vector2 position)
{
    auto renderContext = Managers::Get<RenderManager>()->GetRenderContext(BlendMode::NonPremultiplied);

    // update the current position
    m_lastPosition = m_position;
    m_position = position;

    // determine the movement vector of the stars
    // -- for the purposes of the parallax effect, 
    //    this is the opposite direction as the position movement.
    SimpleMath::Vector2 movement = m_lastPosition - position;

    // create a rectangle representing the screen dimensions of the starfield
    int viewportWidth = TheGame->GetWindowWidth();
    int viewportHeight = TheGame->GetWindowHeight();
    RECT starfieldRectangle = { 0, 0, viewportWidth, viewportHeight };

    //// draw a background color for the starfield
    renderContext->Begin();
    renderContext->Draw(m_starTexture, starfieldRectangle, backgroundColor);
    renderContext->End();


    // if we've moved too far, then reset, as the stars will be moving too fast
    if (movement.LengthSquared() > maximumMovementPerUpdate * maximumMovementPerUpdate)
    {
        Reset(position);
        return;
    }

    // draw all of the stars
    renderContext->Begin();

    for (auto n = numberOfLayers - 1; n >= 0; n--)
    {
        for (size_t i = 0; i < m_stars.size(); i++)
        {
            // move the star based on the depth
            size_t depth = i % movementFactors.size();

            if (depth != n)
            {
                continue;
            }

            SimpleMath::Vector2 p = m_stars[i];
            p += movement * movementFactors[depth];

            // wrap the stars around
            if (p.x < 0 - layerSizes[depth])
            {
                p.x = static_cast<float>(viewportWidth);
                p.y = static_cast<float>(rand() % viewportHeight);
            }
            if (p.x > viewportWidth)
            {
                p.x = static_cast<float>(0 - layerSizes[depth]);
                p.y = static_cast<float>(rand() % viewportHeight);
            }
            if (p.y < 0 - layerSizes[depth])
            {
                p.x = static_cast<float>(rand() % viewportWidth);
                p.y = static_cast<float>(viewportHeight);
            }
            if (p.y > viewportHeight)
            {
                p.x = static_cast<float>(rand() % viewportWidth);
                p.y = static_cast<float>(0 - layerSizes[depth]);
            }

            m_stars[i] = p;

            // draw the star
            RECT b = { (int)p.x, (int)p.y, (int)p.x + starSize, (int)p.y + starSize };
            renderContext->Draw(m_starTexture, b, layerColors[depth]);
        }
    }

    renderContext->End();
}