//--------------------------------------------------------------------------------------
// RocketPowerUp.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "RocketPowerUp.h"

#include "Managers.h"
#include "RocketWeapon.h"
#include "Ship.h"

using namespace ThunderRumble;
using namespace DirectX;

RocketPowerUp::RocketPowerUp()
{
    _powerUpTexture = Managers::Get<ContentManager>()->LoadTexture(L"Assets\\Textures\\powerupRocket.png");
}

RocketPowerUp::~RocketPowerUp()
{
}

bool RocketPowerUp::OnTouch(std::shared_ptr<GameplayObject> target)
{
    // check the target, if we have one
    if (target != nullptr)
    {
        if (target->GetType() == GameplayObjectType::Ship)
        {
            auto ship = std::dynamic_pointer_cast<Ship>(target);
            ship->PrimaryWeapon = std::make_shared<RocketWeapon>(ship);
        }
    }

    return PowerUp::OnTouch(target);
}

void RocketPowerUp::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext)
{
    PowerUp::Draw(elapsedTime, renderContext, _powerUpTexture, Colors::White);
}
