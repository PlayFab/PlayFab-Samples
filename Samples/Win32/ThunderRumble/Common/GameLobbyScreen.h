//--------------------------------------------------------------------------------------
// GameLobbyScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "MenuScreen.h"
#include "GameStateManager.h"

namespace ThunderRumble
{

    class GameLobbyScreen : public MenuScreen
    {
    public:
        GameLobbyScreen();
        virtual ~GameLobbyScreen();

        virtual void Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen) override;
        virtual void HandleInput() override;
        virtual void Draw(float totalTime, float elapsedTime) override;

        void GotoConnectionState();

    protected:
        virtual void OnCancel() override;

    private:
        bool _ready;

        const float timeBetweenMatchmakingPulses = 0.2f;
        float m_TimeSinceLastMatchmakingPulse = 0.0f;
        GameState _lastState;
        TextureHandle m_inGameTexture;
        TextureHandle m_readyTexture;
    };

}
