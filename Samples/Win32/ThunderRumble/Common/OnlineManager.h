#pragma once

#include "Manager.h"

#include <json/value.h>

namespace ThunderRumble
{

    class OnlineManager : public Manager
    {
    public:
        virtual void Initialize() = 0;

        // Sign in ?
        virtual void SignIn(std::function<void(bool, std::wstring&)> callback) = 0;

        // Enter Multiplayer
        virtual void BeginMultiplayer(std::function<void(bool, std::wstring&)> callback) = 0;

        // Leave Multiplayer
        // Matchmake

        virtual void Tick() = 0;

        inline bool IsTaskInProgress() { return m_taskInProgress; }

        virtual void UpdateStatistic(const std::wstring &name, int value, const Json::Value &metadata = Json::Value()) = 0;
        virtual void SendTelemetry(const std::wstring &eventName, const Json::Value &payload) = 0;

    protected:
        bool m_taskInProgress;
    };

}