//--------------------------------------------------------------------------------------
// PowerUp.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PowerUp.h"
#include "RandomMath.h"
#include "Managers.h"
#include "Ship.h"

using namespace BumbleRumble;

namespace
{
    const std::map<PowerUpType, std::string> c_PowerUpStrings = {
        { PowerUpType::Unknown, "Unknown" },
        { PowerUpType::DoubleLaser, "DoubleLaser" },
        { PowerUpType::TripleLaser, "TripleLaser" },
        { PowerUpType::Rocket, "Rocket" }
    };
}

PowerUp::PowerUp() :
    rotationSpeed(2.0f),
    pulseAmplitude(0.1f),
    pulseRate(0.1f),
    pulseTimer(0.0f)
{
    Mass = static_cast<float>(INT_MAX);
    Radius = 20.0f;
}

PowerUp::~PowerUp()
{
}

void PowerUp::Initialize()
{
    if (!Active())
    {
        // play the spawn sound effect
        Managers::Get<AudioManager>()->PlaySound("powerup_spawn");
    }

    GameplayObject::Initialize();
}

bool PowerUp::OnTouch(std::shared_ptr<GameplayObject> target)
{
    // check the target, if we have one
    if (target != nullptr)
    {
        if (target->GetType() == GameplayObjectType::Ship)
        {
            // play the "power-up picked up" sound effect
            Managers::Get<AudioManager>()->PlaySound("powerup_touch");

            // kill the power-up
            Die(target, false);

            if (std::dynamic_pointer_cast<Ship>(target)->IsLocal)
            {
                auto typeName = c_PowerUpStrings.find(GetPowerUpType());

                Json::Value metadata;
                metadata["PowerUpType"] = Json::Value(typeName->second);

                Managers::Get<PlayFabManager>()->UpdateStatistic("powerups_collected", 1, metadata);
            }

            // the ship keeps going as if it didn't hit anything
            return false;
        }
    }

    return GameplayObject::OnTouch(target);
}

void PowerUp::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext, std::shared_ptr<DX::Texture> sprite, DirectX::XMVECTOR color)
{
    // update the rotation
    Rotation = rotationSpeed * elapsedTime;

    // adjust the radius to affect the scale
    float oldRadius = Radius;
    pulseTimer += elapsedTime;
    Radius *= 1.0f + pulseAmplitude * std::sin(pulseTimer / pulseRate);
    GameplayObject::Draw(elapsedTime, renderContext, sprite, color);
    Radius = oldRadius;
}

PowerUpType PowerUp::ChooseNextPowerUpType()
{
    int randValue = RandomMath::RandomBetween(1, 5);

    if (randValue == 1 || randValue == 2)
    {
        return PowerUpType::DoubleLaser;
    }
    else if (randValue == 3 || randValue == 4)
    {
        return PowerUpType::TripleLaser;
    }
    else
    {
        return PowerUpType::Rocket;
    }
}
