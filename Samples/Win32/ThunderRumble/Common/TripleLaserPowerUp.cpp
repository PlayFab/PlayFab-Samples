//--------------------------------------------------------------------------------------
// TripleLaserPowerUp.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "TripleLaserPowerUp.h"

#include "Managers.h"
#include "TripleLaserWeapon.h"
#include "Ship.h"

using namespace ThunderRumble;
using namespace DirectX;

TripleLaserPowerUp::TripleLaserPowerUp()
{
    _powerUpTexture = Managers::Get<ContentManager>()->LoadTexture(L"Assets\\Textures\\powerupTripleLaser.png");
}

TripleLaserPowerUp::~TripleLaserPowerUp()
{
}

bool TripleLaserPowerUp::OnTouch(std::shared_ptr<GameplayObject> target)
{
    // check the target, if we have one
    if (target != nullptr)
    {
        if (target->GetType() == GameplayObjectType::Ship)
        {
            auto ship = std::dynamic_pointer_cast<Ship>(target);
            ship->PrimaryWeapon = std::make_shared<TripleLaserWeapon>(ship);
        }
    }

    return PowerUp::OnTouch(target);
}

void TripleLaserPowerUp::Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext)
{
    PowerUp::Draw(elapsedTime, renderContext, _powerUpTexture, Colors::White);
}
