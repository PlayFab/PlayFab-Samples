//--------------------------------------------------------------------------------------
// Managers.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Manager.h"
#include "Managers.h"

using namespace ThunderRumble;

std::map<const char *, std::shared_ptr<Manager>> Managers::m_managersByType;
