//--------------------------------------------------------------------------------------
// OnlineManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include <json/json.h>

namespace BumbleRumble
{

class OnlineManager : public Manager
{
public:
    virtual void Initialize() = 0;
    virtual void SignIn(std::function<void(bool, std::string&)> callback) = 0;
    virtual void BeginMultiplayer(const std::string &queueName, int timeout) = 0;

    virtual void Tick() = 0;

    inline bool IsTaskInProgress() { return m_taskInProgress; }

    virtual void UpdateStatistic(const std::string &name, int value, const Json::Value &metadata = Json::Value()) = 0;
    virtual void SendTelemetry(const std::string &eventName, const Json::Value &payload) = 0;

protected:
    bool m_taskInProgress;
};

}