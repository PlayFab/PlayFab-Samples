//--------------------------------------------------------------------------------------
// StringConv.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "StringConv.h"

static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

std::wstring BumbleRumble::StrToWStr(const std::string& str)
{
    return converter.from_bytes(str);
}

std::wstring BumbleRumble::StrToWStr(const char* str)
{
    return converter.from_bytes(str);
}

std::string BumbleRumble::WStrToStr(const std::wstring& wstr)
{
    return converter.to_bytes(wstr);
}

std::string BumbleRumble::WStrToStr(const wchar_t* wstr)
{
    return converter.to_bytes(wstr);
}
