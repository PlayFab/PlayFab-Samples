//--------------------------------------------------------------------------------------
// AudioManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "AudioManager.h"

using namespace ThunderRumble;
using namespace DirectX;

AudioManager::AudioManager() :
    SoundTrackOn(true),
    PlaySoundEffects(true)
{
#ifdef THUNDERRUMBLE_SERVER
    SoundTrackOn = false;
    PlaySoundEffects = false;
#endif
}

void AudioManager::LoadSound(const std::wstring &name, const std::wstring &path)
{
    // Stuff the data into our map
    _soundEffects[name] = std::make_shared<SoundEffect>(_audEngine.get(), path.c_str());
}

void AudioManager::Initialize()
{
#ifndef THUNDERRUMBLE_SERVER
    AUDIO_ENGINE_FLAGS eflags = AudioEngine_UseMasteringLimiter;
#ifdef _DEBUG
    eflags = eflags | AudioEngine_Debug;
#endif

    _audEngine.reset(new AudioEngine(eflags));

    // The sound assets in NR are all too loud at default volume
    // One simple option to correct this is to adjust the master volume
    SetMasterVolume(0.04f);

    try
    {
        _backgroundSound.reset(new SoundEffect(_audEngine.get(), L"Assets\\Audio\\OneStepBeyond.xwma"));
    }
    catch (std::exception)
    {
        _backgroundSound.reset();
    }

    if (_backgroundSound != nullptr)
    {
        _backgroundSoundInstance = _backgroundSound->CreateInstance();
    }
#endif
}

void AudioManager::Suspend()
{
    if (_audEngine)
    {
        _audEngine->Suspend();
    }
}

void AudioManager::Resume()
{
    if (_audEngine)
    {
        _audEngine->Resume();
    }
}

void AudioManager::ShutDown()
{
}

void AudioManager::Tick()
{
    if (!_audEngine)
    {
        return;
    }

    if (!_audEngine->Update())
    {
        if (_audEngine->IsCriticalError())
        {
            // This would only happen if we were rendering to a headset that was disconnected
            // The sample always renders to the 'default' system audio device, not to headsets
            assert(false);
        }
    }
}

void AudioManager::PlaySoundTrack(bool play)
{
    if (!(_audEngine && _backgroundSoundInstance))
    {
        return;
    }

#ifdef THUNDERRUMBLE_SERVER
    SoundTrackOn = false;
#else
    if (play)
    {
        _backgroundSoundInstance->Play(true);
    }
    else
    {
        _backgroundSoundInstance->Stop();
    }

    SoundTrackOn = play;
#endif
}

void AudioManager::PlaySound(const std::wstring& soundName, bool loop)
{
    if (!PlaySoundEffects)
    {
        return;
    }

    UNREFERENCED_PARAMETER(loop);

    // Try to find the sound data for the sound
    auto itr = _soundEffects.find(soundName);
    if (itr == _soundEffects.end())
    {
        return;
    }

    itr->second->Play();
}

void AudioManager::SetMasterVolume(float volume)
{
    if (!_audEngine)
    {
        return;
    }

    auto masterVoice = _audEngine->GetMasterVoice();
    if (masterVoice)
    {
        masterVoice->SetVolume(volume);
    }
}
