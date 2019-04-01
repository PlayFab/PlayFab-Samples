//--------------------------------------------------------------------------------------
// pch.h
//
// Header for standard system include files.
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

// Use the C++ standard templated min/max
#define NOMINMAX

#define _ENABLE_EXTENDED_ALIGNED_STORAGE

#include <xdk.h>

#if _XDK_VER < 0x3AD703ED /* XDK Edition 170300 */
#error This sample requires the March 2017 XDK or later
#endif

#include <wrl.h>

#include <d3d11_x.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <SimpleMath.h>
#include <SpriteFont.h>
#include <Audio.h>
#include <Keyboard.h>

#include <cmath>
#include <algorithm>
#include <exception>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <mutex>
#include <cctype>
#include <map>
#include <queue>
#include <list>
#include <array>
#include <mutex>
#include <random>

#include <stdio.h>
#include <pix.h>

#include "GamePad.h"
#include "GraphicsMemory.h"

#include <xsapi/services.h>

#include "Party.h"

#include "StepTimer.h"
#include "Texture.h"
#include "StringConv.h"
#include "Debug.h"

#define TheGame g_game

namespace DX
{
    // Helper class for COM exceptions
    class com_exception : public std::exception
    {
    public:
        com_exception(HRESULT hr) : result(hr) {}

        virtual const char* what() const override
        {
            static char s_str[64] = {};
            sprintf_s(s_str, "Failure with HRESULT of %08X", static_cast<unsigned int>(result));
            return s_str;
        }

    private:
        HRESULT result;
    };

    // Helper utility converts D3D API failures into exceptions.
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            throw com_exception(hr);
        }
    }
}