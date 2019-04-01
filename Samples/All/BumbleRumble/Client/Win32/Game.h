//--------------------------------------------------------------------------------------
// Game.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

namespace BumbleRumble
{

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game() noexcept;

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

    int GetWindowWidth() { return m_outputWidth; }
    int GetWindowHeight() { return m_outputHeight; }

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void PrefetchContent();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;
};

}

extern std::unique_ptr<BumbleRumble::Game> g_game;
