/// <summary>
/// Global definitions for PlayFab QoS.
/// </summary>

#pragma once
#include <iostream>

// define body for logging or debug output
#define LOG_QOS(S) /*std::cout << S;*/

namespace PlayFab
{
    namespace QoS
    {
        // the error code that is returned if a QoS exception was thrown
        constexpr int EXCEPTION_ERROR_CODE = -777;

        // Wait time before looping back on a thread
        constexpr int THREAD_WAIT_MS = 10;

        // Default timeout for the api if the user does not supply a timeout
        constexpr int DEFAULT_TIMEOUT_MS = 250;

        // Number of times a server is pinged
        constexpr int NUM_OF_PING_ITERATIONS = 3;
    }
}