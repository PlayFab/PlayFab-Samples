//--------------------------------------------------------------------------------------
// Managers.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include "ScreenManager.h"
#include "PlayfabManager.h"
#include "GameStateManager.h"
#include "RenderManager.h"
#include "ContentManager.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "OnlineManager.h"
#include "NetworkManager.h"
#include "ParticleManager.h"
#include "CollisionManager.h"

#include <vcruntime_typeinfo.h>

namespace BumbleRumble
{

class Manager;

class Managers
{
public:
    Managers()
    {
    }

    static void Initialize()
    {
        m_managersByType[typeid(NetworkManager).name()] = CreateManager<NetworkManager>();
        m_managersByType[typeid(InputManager).name()] = CreateManager<InputManager>();
        m_managersByType[typeid(AudioManager).name()] = CreateManager<AudioManager>();
        m_managersByType[typeid(RenderManager).name()] = CreateManager<RenderManager>();
        m_managersByType[typeid(ContentManager).name()] = CreateManager<ContentManager>();
        m_managersByType[typeid(ParticleEffectManager).name()] = CreateManager<ParticleEffectManager>();
        m_managersByType[typeid(GameStateManager).name()] = CreateManager<GameStateManager>();
        m_managersByType[typeid(CollisionManager).name()] = CreateManager<CollisionManager>();
        m_managersByType[typeid(ScreenManager).name()] = CreateManager<ScreenManager>();
        m_managersByType[typeid(PlayFabManager).name()] = CreateManager<PlayFabManager>();
    }

    template<class T>
    static std::shared_ptr<T> Get()
    {
        return std::static_pointer_cast<T>(m_managersByType[typeid(T).name()]);
    }

private:

    template<typename ManagerType>
    static std::shared_ptr<Manager> CreateManager()
    {
        return std::static_pointer_cast<Manager>(std::make_shared<ManagerType>());
    }

    static std::map<const char *, std::shared_ptr<Manager>> m_managersByType;
};

}

