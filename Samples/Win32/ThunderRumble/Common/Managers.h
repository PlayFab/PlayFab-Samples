//--------------------------------------------------------------------------------------
// Managers.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include "ScreenManager.h"
#ifdef THUNDERRUMBLE_SERVER
//#include "ServerContentManager.h"
#include "ServerGameStateManager.h"
#include "Compute\IPC.h"
#else
#include "PlayfabManager.h"
#include "GameStateManager.h"
#include "RenderManager.h"
#endif
#include "ContentManager.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "OnlineManager.h"
#include "NetworkManager.h"
#include "ParticleManager.h"
#include "CollisionManager.h"
#include "GameServiceManager.h"

#include <vcruntime_typeinfo.h>

namespace ThunderRumble
{

    class Manager;

    class Managers
    {
    public:
        Managers()
        {
        }

        static void PreInitialize()
        {
#ifdef THUNDERRUMBLE_SERVER
            m_managersByType[typeid(IPC).name()] = CreateManager<IPC>();
#endif
        }

        static void Initialize()
        {
            m_managersByType[typeid(NetworkManager).name()] = CreateManager<NetworkManager>();
            m_managersByType[typeid(AudioManager).name()] = CreateManager<AudioManager>();
            m_managersByType[typeid(ParticleEffectManager).name()] = CreateManager<ParticleEffectManager>();
            m_managersByType[typeid(GameStateManager).name()] = CreateManager<GameStateManager>();
            m_managersByType[typeid(CollisionManager).name()] = CreateManager<CollisionManager>();



            // Change this to use a different OnlineManager
#ifndef THUNDERRUMBLE_SERVER
            m_managersByType[typeid(InputManager).name()] = CreateManager<InputManager>();
            m_managersByType[typeid(RenderManager).name()] = CreateManager<RenderManager>();
            m_managersByType[typeid(ContentManager).name()] = CreateManager<ContentManager>();
            m_managersByType[typeid(ParticleEffectManager).name()] = CreateManager<ParticleEffectManager>();
            m_managersByType[typeid(GameStateManager).name()] = CreateManager<GameStateManager>();
            m_managersByType[typeid(CollisionManager).name()] = CreateManager<CollisionManager>();
            m_managersByType[typeid(ScreenManager).name()] = CreateManager<ScreenManager>();
            m_managersByType[typeid(PlayFabManager).name()] = CreateManager<PlayFabManager>();
            m_managersByType[typeid(GameServiceManager).name()] = CreateManager<GameServiceManager>();
#endif
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

