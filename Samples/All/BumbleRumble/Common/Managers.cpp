//--------------------------------------------------------------------------------------
// Managers.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Manager.h"
#include "Managers.h"

using namespace BumbleRumble;

std::map<const char *, std::shared_ptr<Manager>> Managers::m_managersByType;
