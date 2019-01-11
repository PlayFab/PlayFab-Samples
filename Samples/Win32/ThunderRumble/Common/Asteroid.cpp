//--------------------------------------------------------------------------------------
// Asteroid.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Asteroid.h"

#include "Managers.h"
#include "RandomMath.h"

using namespace ThunderRumble;
using namespace DirectX;


Asteroid::Asteroid(float radius, int variation)
{
    Radius = radius;
    Mass = radius * massRadiusRatio;
    Life = radius * lifeRadiusRatio;
    Velocity = RandomMath::RandomDirection();
    float l = RandomMath::RandomBetween(initialSpeedMinimum, initialSpeedMaximum);
    Velocity.x *= l;
    Velocity.y *= l;
    Variation = variation;
    wchar_t buffer[64] = {};
    swprintf_s(buffer, L"Assets\\Textures\\asteroid%d.png", variation);
    m_texture = Managers::Get<ContentManager>()->LoadTexture(buffer);
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(float elapsedTime)
{
    // spin the asteroid based on the radius and velocity
    float velocityMassRatio = (Velocity.LengthSquared() / Mass);
    Rotation += velocityMassRatio * velocityMassRatioToRotationScalar * elapsedTime;

    float speed = Velocity.Length();
    if (speed > minSpeedFromDrag)
    {
        // apply some drag so the asteroids settle down
        Velocity -= Velocity * (elapsedTime * dragPerSecond);
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
            target->TakeDamage(shared_from_this(), momentum * momentumToDamageScalar);
        }

        // jameslen: I believe this works, but I don't have a game to test it.  The old code is commented out below.

        // calculate damage as a function of how much the two GameplayObject's
        // velocities were going towards one another
        //auto playerAsteroidVector = Position - target->Position;

        //auto lengthSq = playerAsteroidVector.LengthSquared();

        //if (lengthSq > 0)
        //{
        //    playerAsteroidVector /= sqrt(lengthSq);

        //    float rammingSpeed = playerAsteroidVector.Dot(target->Velocity) - playerAsteroidVector.Dot(Velocity);

        //    float momentum = Mass * rammingSpeed;
        //    target->TakeDamage(shared_from_this(), momentum * momentumToDamageScalar);
        //}
    }
    // if the asteroid didn't hit a projectile, play the asteroid-touch sound effect
    if (target->GetType() != GameplayObjectType::Projectile)
    {
        Managers::Get<AudioManager>()->PlaySound(L"asteroid_touch");
    }
    return true;
}
