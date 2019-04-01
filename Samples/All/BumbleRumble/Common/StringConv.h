//--------------------------------------------------------------------------------------
// StringConv.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include <locale>
#include <codecvt>
#include <string>

namespace BumbleRumble
{
    std::wstring StrToWStr(const std::string& str);
    std::wstring StrToWStr(const char* str);
    std::string WStrToStr(const std::wstring& wstr);
    std::string WStrToStr(const wchar_t* wstr);
}