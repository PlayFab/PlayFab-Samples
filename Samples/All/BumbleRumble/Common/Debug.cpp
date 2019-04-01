//--------------------------------------------------------------------------------------
// Debug.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Debug.h"

std::string g_logFilePath(DEBUG_LOG_FILENAME);

void SetLogPath()
{
    char path[MAX_PATH + 1];

#if defined(_XBOX_ONE) && defined(_TITLE)
    path[0] = 'D';
    path[1] = ':';
    path[2] = '\\';
    path[3] = 0;
#else
    GetTempPathA(MAX_PATH, path);
#endif

    g_logFilePath = path;
    g_logFilePath += DEBUG_LOG_FILENAME;

    SYSTEMTIME localTime;
    GetLocalTime(&localTime);

    char timeStr[100];
    sprintf_s(timeStr, 100, "%02u-%02u-%02u",
        localTime.wHour,
        localTime.wMinute,
        localTime.wSecond
        );

    g_logFilePath += timeStr;
    g_logFilePath += ".txt";

    OutputDebugStringA("Log file path: ");
    OutputDebugStringA(g_logFilePath.c_str());
    OutputDebugStringA("\n");
}


///////////////////////////////////////////////////////////////////////////////
//  Debug Helpers
//
#define DEBUG_BUFFER_SIZE 8192

std::mutex __debug_mutex;

void DebugInit()
{
#ifdef DEBUG_LOGGING
    SetLogPath();

#if DEBUG_LOG_CREATE_NEW_ON_LAUNCH == 1
    // delete logfile, ignoring failures
    remove(g_logFilePath.c_str());
#endif
#endif
}

std::string DebugWrite(const char* format, ...)
{
    std::lock_guard<std::mutex> lock(__debug_mutex);
    static char msgbuffer[DEBUG_BUFFER_SIZE];
    std::string returnLine("");

    va_list args;
    va_start(args, format);
    vsprintf_s(msgbuffer, DEBUG_BUFFER_SIZE, format, args);
    va_end(args);

    std::string buffer(DEBUG_LOG_ENTRY_PREFIX);
    buffer += msgbuffer;
    OutputDebugStringA(buffer.c_str());

    // note the log time
    SYSTEMTIME localTime;
    GetLocalTime(&localTime);

    char timeStr[100];
    sprintf_s(timeStr, 100, "%02u:%02u:%02u.%03u ",
        localTime.wHour,
        localTime.wMinute,
        localTime.wSecond,
        localTime.wMilliseconds); // format: "hh:mm:ss.ms"

#ifdef DEBUG_LOGGING
    // log the string to a file
    FILE *file  = nullptr;

    errno_t err = fopen_s(
        &file,
        g_logFilePath.c_str(),
        "ab+, ccs=UTF-8"
        );

    if (err != 0)
    {
        std::string err_msg("Unable to open log file: ");
        err_msg += std::to_string(err);
        err_msg += "\n";
        OutputDebugStringA(err_msg.c_str());
    }
    else
    {
        std::string fileStr("");
        fileStr += std::to_string(GetCurrentThreadId());
        fileStr += " \t";
        fileStr += timeStr;
        fileStr += msgbuffer;

        fwrite(
            (void*)fileStr.c_str(),
            sizeof(char),
            fileStr.length(),
            file
            );

        fflush(file);
        fclose(file);
    }
#endif

    // assemble return line
    returnLine += timeStr;
    returnLine += msgbuffer;

    return returnLine;
}
