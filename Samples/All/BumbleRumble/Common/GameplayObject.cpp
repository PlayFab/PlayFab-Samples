//--------------------------------------------------------------------------------------
// GameplayObject.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "GameplayObject.h"

#include "Managers.h"
#include "Texture.h"

#include "RenderManager.h"

using namespace BumbleRumble;
using namespace DirectX;

std::atomic_uint32_t GameplayObject::s_nextUniqueID = 1;

GameplayObject::GameplayObject() :
    Position(SimpleMath::Vector2(0, 0)),
    Velocity(SimpleMath::Vector2(0, 0)),
    Rotation(0.0f),
    Radius(1.0f),
    Mass(1.0f),
    Life(0.0f),
    CollidedThisFrame(false),
    m_active(false),
    m_uniqueID(s_nextUniqueID)
{
    ++s_nextUniqueID;
}

void GameplayObject::Initialize()
{
    if (!m_active)
    {
        m_active = true;
        Managers::Get<CollisionManager>()->Collection()->push_back(shared_from_this());
    }
}

void GameplayObject::Update(float elapsedTime)
{
    UNREFERENCED_PARAMETER(elapsedTime);
    CollidedThisFrame = false;
}

void GameplayObject::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext, std::shared_ptr<DX::Texture> texture, XMVECTOR color)
{
    UNREFERENCED_PARAMETER(elapsedTime);
    if (renderContext && texture)
    {
        renderContext->Draw(
            texture,
            Position,
            Rotation,
            2.0f * Radius / static_cast<float>(std::min<int>(texture->Width(), texture->Height())),
            color,
            TexturePosition::Centered);
    }
}

/// <summary>
/// Defines the interaction between this GameplayObject and 
/// a target GameplayObject when they touch.
/// </summary>
/// <param name="target">The GameplayObject that is touching this one.</param>
/// <returns>True if the objects meaningfully interacted.</returns>
bool GameplayObject::OnTouch(std::shared_ptr<GameplayObject> target)
{
    UNREFERENCED_PARAMETER(target);
    return true;
}

/// <summary>
/// Damage this object by the amount provided.
/// </summary>
/// <remarks>
/// This function is provided in lieu of a Life mutation property to allow 
/// classes of objects to restrict which kinds of objects may damage them,
/// and under what circumstances they may be damaged.
/// </remarks>
/// <param name="source">The GameplayObject responsible for the damage.</param>
/// <param name="damageAmount">The amount of damage.</param>
/// <returns>If true, this object was damaged.</returns>
bool GameplayObject::TakeDamage(std::shared_ptr<GameplayObject> source, float damageAmount)
{
    UNREFERENCED_PARAMETER(source);
    UNREFERENCED_PARAMETER(damageAmount);
    return false;
}

/// <summary>
/// Kills this object, in response to the given GameplayObject.
/// </summary>
/// <param name="source">The GameplayObject responsible for the kill.</param>
/// <param name="cleanupOnly">
/// If true, the object dies without any further effects.
/// </param>
void GameplayObject::Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly)
{
    UNREFERENCED_PARAMETER(source);
    UNREFERENCED_PARAMETER(cleanupOnly);
    if (m_active)
    {
        m_active = false;
        Managers::Get<CollisionManager>()->Collection()->QueuePendingRemoval(shared_from_this());
    }
}