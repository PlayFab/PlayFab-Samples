#pragma once

// Windows headers
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <objbase.h>
#include <shlobj.h>
#include <wincred.h>

// Standard C++ headers
#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <sstream>
#include <fstream>
#include <cassert>
#include <memory>

// Third-party library headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>

// Steam headers
#include <steam/steam_api.h>
#include <steam/steam_api_common.h>
#include <steam/isteamutils.h>

// Xbox/GDK headers
#include <XGameRuntime.h>

// PlayFab headers
#include <playfab/core/PFCore.h>
#include <playfab/services/PFServices.h>
#include <playfab/gamesave/PFGameSaveFiles.h>

// Common macros
#define RETURN_HR(hr)                                           return(hr)
#define RETURN_LAST_ERROR()                                     return HRESULT_FROM_WIN32(GetLastError())
#define RETURN_WIN32(win32err)                                  return HRESULT_FROM_WIN32(win32err)

#define RETURN_IF_FAILED(hr)                                    do { HRESULT __hrRet = hr; if (FAILED(__hrRet)) { RETURN_HR(__hrRet); }} while (0, 0)
#define RETURN_IF_FAILED_PLAYFAB(PlayFabResult)                 do { auto __pfRet = PlayFabResult; if (FAILED(__pfRet.hr)) { return {__pfRet.hr, __pfRet.errorMessage}; }} while (0, 0)
#define RETURN_IF_WIN32_BOOL_FALSE(win32BOOL)                   do { BOOL __boolRet = win32BOOL; if (!__boolRet) { RETURN_LAST_ERROR(); }} while (0, 0)
#define RETURN_IF_NULL_ALLOC(ptr)                               do { if ((ptr) == nullptr) { RETURN_HR(E_OUTOFMEMORY); }} while (0, 0)
#define RETURN_HR_IF(hr, condition)                             do { if (condition) { RETURN_HR(hr); }} while (0, 0)
#define RETURN_HR_IF_FALSE(hr, condition)                       do { if (!(condition)) { RETURN_HR(hr); }} while (0, 0)
#define RETURN_HR_INVALIDARG_IF_NULL(arg)                       do { RETURN_HR_IF(E_INVALIDARG, arg == nullptr); } while(0, 0)
#define RETURN_LAST_ERROR_IF(condition)                         do { if (condition) { RETURN_LAST_ERROR(); }} while (0, 0)
#define RETURN_LAST_ERROR_IF_NULL(ptr)                          do { if ((ptr) == nullptr) { RETURN_LAST_ERROR(); }} while (0, 0)

// Link libraries that are commonly used
#pragma comment(lib, "advapi32.lib")
