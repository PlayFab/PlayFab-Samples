//
// pch.h
// Header for standard system include files.
//

#pragma once

#include <WinSDKVer.h>
#define _WIN32_WINNT 0x0601
#include <SDKDDKVer.h>

#define _ENABLE_EXTENDED_ALIGNED_STORAGE

// Use the C++ standard templated min/max
#define NOMINMAX

// DirectX apps don't need GDI
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP

// Include <mcx.h> if you need this
#define NOMCX

// Include <winsvc.h> if you need this
#define NOSERVICE

// WinHelp is deprecated
#define NOHELP

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <wrl.h>
#include <wrl/client.h>
#include <d3d11_1.h>

#if defined(NTDDI_WIN10_RS2)
#include <dxgi1_6.h>
#else
#include <dxgi1_5.h>
#endif

#include <WinSock2.h>
#include <DirectXMath.h>
#include <SimpleMath.h>
#include <DirectXColors.h>
#include <SpriteFont.h>
#include <GamePad.h>
#include <Keyboard.h>
#include <Audio.h>

#include <stdint.h>
#include <concurrent_queue.h>

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

#include "StepTimer.h"
#include "Texture.h"

#include "Debug.h"

#define TheGame g_game

namespace DX
{
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            // Set a breakpoint on this line to catch DirectX API errors
            throw std::exception();
        }
    }
}