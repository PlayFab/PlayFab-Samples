//--------------------------------------------------------------------------------------
// GameLobbyScreen.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "MenuScreen.h"
#include "GameStateManager.h"

namespace BumbleRumble
{

class GameLobbyScreen : public MenuScreen
{
public:
    GameLobbyScreen();
    virtual ~GameLobbyScreen();

    virtual void Update(float totalTime, float elapsedTime, bool otherScreenHasFocus, bool coveredByOtherScreen) override;
    virtual void HandleInput() override;
    virtual void Draw(float totalTime, float elapsedTime) override;

protected:
    virtual void OnCancel() override;

private:
    bool m_ready;

    const float c_timeBetweenMatchmakingPulses = 0.5f;
    float m_TimeSinceLastMatchmakingPulse = 0.0f;
    GameState m_lastState;
    std::shared_ptr<DX::Texture> m_inGameTexture;
    std::shared_ptr<DX::Texture> m_readyTexture;
    std::shared_ptr<DX::Texture> m_chatAble;
    std::shared_ptr<DX::Texture> m_chatMute;
    std::shared_ptr<DX::Texture> m_chatTalk;
};

}
