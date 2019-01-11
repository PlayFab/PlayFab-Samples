//--------------------------------------------------------------------------------------
// ShipInput.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include <GamePad.h>
#include <Keyboard.h>
#include <DirectXMath.h>

namespace ThunderRumble
{

    class ShipInput
    {
    public:
        ShipInput(const DirectX::GamePad::State& gamePadState = DirectX::GamePad::State());
        ShipInput(const DirectX::Keyboard::State& keyboardState);
        ~ShipInput();

        void Add(const ShipInput& moreInput);

        // Prepare the ship input data for the ShipInput packet
        std::vector<unsigned char> Serialize();

        // Get the latest ship input from the ShipInput packet
        void Deserialize(const std::vector<unsigned char> &data);

        DirectX::SimpleMath::Vector2 LeftStick;
        DirectX::SimpleMath::Vector2 RightStick;
        bool MineFired;
    };

}
