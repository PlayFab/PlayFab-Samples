//--------------------------------------------------------------------------------------
// DoubleLaserPowerUp.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "DoubleLaserPowerUp.h"

#include "Managers.h"
#include "DoubleLaserWeapon.h"
#include "Ship.h"

using namespace BumbleRumble;
using namespace DirectX;

DoubleLaserPowerUp::DoubleLaserPowerUp()
{
    m_powerUpTexture = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\powerupDoubleLaser.png");
}

DoubleLaserPowerUp::~DoubleLaserPowerUp()
{
}

bool DoubleLaserPowerUp::OnTouch(std::shared_ptr<GameplayObject> target)
{
    // check the target, if we have one
    if (target != nullptr)
    {
        if (target->GetType() == GameplayObjectType::Ship)
        {
            auto ship = std::dynamic_pointer_cast<Ship>(target);
            ship->PrimaryWeapon = std::make_shared<DoubleLaserWeapon>(ship);
        }
    }

    return PowerUp::OnTouch(target);
}

void DoubleLaserPowerUp::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext)
{
    PowerUp::Draw(elapsedTime, renderContext, m_powerUpTexture, Colors::White);
}
