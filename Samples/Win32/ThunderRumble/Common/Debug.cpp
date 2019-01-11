//
// Debug.cpp
//

#include "pch.h"
#include "Debug.h"

std::wstring g_logFilePath(DEBUG_LOG_FILENAME);

void SetLogPath()
{
#if defined(_XBOX_ONE) && defined(_TITLE)
    g_logFilePath = L"D:";
#else
    wchar_t path[MAX_PATH + 1];

    GetTempPath(MAX_PATH, path);

    g_logFilePath = path;
#endif
    g_logFilePath += DEBUG_LOG_FILENAME;

    SYSTEMTIME localTime;
    GetLocalTime(&localTime);

    wchar_t timeStr[100];
    swprintf_s(timeStr, 100, L"%02u-%02u-%02u",
        localTime.wHour,
        localTime.wMinute,
        localTime.wSecond
    );

    g_logFilePath += timeStr;
    g_logFilePath += L".txt";

    OutputDebugString(L"Log file path: ");
    OutputDebugString(g_logFilePath.c_str());
    OutputDebugString(L"\n");
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
    _wremove(g_logFilePath.c_str());
#endif
#endif
}

std::wstring DebugWrite(const wchar_t* format, ...)
{
    std::lock_guard<std::mutex> lock(__debug_mutex);
    static wchar_t msgbuffer[DEBUG_BUFFER_SIZE];
    std::wstring returnLine(L"");

    va_list args;
    va_start(args, format);
    vswprintf(msgbuffer, DEBUG_BUFFER_SIZE, format, args);
    va_end(args);

    std::wstring buffer(DEBUG_LOG_ENTRY_PREFIX);
    buffer += msgbuffer;
    OutputDebugString(buffer.c_str());

    // note the log time
    SYSTEMTIME localTime;
    GetLocalTime(&localTime);

    wchar_t timeStr[100];
    swprintf_s(timeStr, 100, L"%02u:%02u:%02u.%03u ",
        localTime.wHour,
        localTime.wMinute,
        localTime.wSecond,
        localTime.wMilliseconds); // format: "hh:mm:ss.ms"

#ifdef DEBUG_LOGGING
    // log the string to a file
    FILE *file = nullptr;

    errno_t err = _wfopen_s(
        &file,
        g_logFilePath.c_str(),
        L"at+, ccs=UTF-8"
    );

    if (err != 0)
    {
        std::wstring err_msg(L"Unable to open log file: ");
        err_msg += std::to_wstring(err);
        err_msg += L"\n";
        OutputDebugString(err_msg.c_str());
    }
    else
    {
        std::wstring fileStr(L"");
        fileStr += std::to_wstring(GetCurrentThreadId());
        fileStr += L" \t";
        fileStr += timeStr;
        fileStr += msgbuffer;

        fwrite(
            (void*)fileStr.c_str(),
            sizeof(wchar_t),
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
