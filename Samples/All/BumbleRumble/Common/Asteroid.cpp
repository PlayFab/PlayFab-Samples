//--------------------------------------------------------------------------------------
// Asteroid.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Asteroid.h"

#include "Managers.h"
#include "RandomMath.h"

using namespace BumbleRumble;
using namespace DirectX;

Asteroid::Asteroid(float radius, int variation)
{
    Radius = radius;
    Mass = radius * c_massRadiusRatio;
    Life = radius * c_lifeRadiusRatio;
    Velocity = RandomMath::RandomDirection();
    float l = RandomMath::RandomBetween(c_initialSpeedMinimum, c_initialSpeedMaximum);
    Velocity.x *= l;
    Velocity.y *= l;
    Variation = variation;
    char buffer[64] = {};
    sprintf_s(buffer, "Assets\\Textures\\asteroid%d.png", variation);
    m_texture = Managers::Get<ContentManager>()->LoadTexture(buffer);
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(float elapsedTime)
{
    // spin the asteroid based on the radius and velocity
    float velocityMassRatio = (Velocity.LengthSquared() / Mass);
    Rotation += velocityMassRatio * c_velocityMassRatioToRotationScalar * elapsedTime;

    float speed = Velocity.Length();
    if (speed > c_minSpeedFromDrag)
    {
        // apply some drag so the asteroids settle down
        Velocity -= Velocity * (elapsedTime * c_dragPerSecond);
    }

    GameplayObject::Update(elapsedTime);
}

void Asteroid::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext)
{
    GameplayObject::Draw(elapsedTime, renderContext, m_texture, Colors::White);
}

bool Asteroid::OnTouch(std::shared_ptr<GameplayObject> target)
{
    // if the asteroid has touched a player, then damage it
    if (target->GetType() == GameplayObjectType::Ship)
    {
        // calculate damage as a function of how much the two GameplayObject's
        // velocities were going towards one another
        XMFLOAT2 playerAsteroidVector = XMFLOAT2(Position.x - target->Position.x, Position.y - target->Position.y);
        if (playerAsteroidVector.x * playerAsteroidVector.x + playerAsteroidVector.y * playerAsteroidVector.y > 0)
        {
            float d = 1.0f / std::sqrt(playerAsteroidVector.x * playerAsteroidVector.x + playerAsteroidVector.y * playerAsteroidVector.y);
            playerAsteroidVector.x *= d;
            playerAsteroidVector.y *= d;

            float rammingSpeed =
                (playerAsteroidVector.x * target->Velocity.x + playerAsteroidVector.y * target->Velocity.y) -
                (playerAsteroidVector.x * Velocity.x + playerAsteroidVector.y * Velocity.y);
            float momentum = Mass * rammingSpeed;
            target->TakeDamage(shared_from_this(), momentum * c_momentumToDamageScalar);
        }
    }
    // if the asteroid didn't hit a projectile, play the asteroid-touch sound effect
    if (target->GetType() != GameplayObjectType::Projectile)
    {
        Managers::Get<AudioManager>()->PlaySound("asteroid_touch");
    }
    return true;
}
