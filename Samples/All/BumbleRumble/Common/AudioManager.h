//--------------------------------------------------------------------------------------
// AudioManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once


#include "Manager.h"

namespace BumbleRumble
{

class AudioManager : public Manager
{
public:
    AudioManager();

    void Initialize();
    void Suspend();
    void Resume();
    void ShutDown();
    void Tick();
    void PlaySoundTrack(bool play);
    void PlaySound(const std::string& soundName, bool loop = false);
    void SetMasterVolume(float volume);

    bool SoundTrackOn;
    bool PlaySoundEffects;

    void LoadSound(const std::string &name, const std::string &path);

private:
    std::unique_ptr<DirectX::AudioEngine>                         m_audEngine;
    std::unique_ptr<DirectX::SoundEffect>                         m_backgroundSound;
    std::unique_ptr<DirectX::SoundEffectInstance>                 m_backgroundSoundInstance;
    std::map<std::string, std::shared_ptr<DirectX::SoundEffect>> m_soundEffects;
};

}

