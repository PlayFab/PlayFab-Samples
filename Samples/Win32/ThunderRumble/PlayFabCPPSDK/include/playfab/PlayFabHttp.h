#pragma once

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabError.h>
#include <functional>
#include <memory>
#include <thread>
#include <mutex>

#ifndef _WIN32
#include <jsoncpp/json/value.h>
#endif
#ifdef _WIN32
#include <json/value.h>
#endif

namespace PlayFab
{
    /// <summary>
    /// Provides an interface and a static instance for https implementations
    /// </summary>
    class IPlayFabHttp : public IPlayFabHttpPlugin
    {
    public:
        static IPlayFabHttp& Get();
        static std::shared_ptr<IPlayFabHttp> GetPtr();

        virtual ~IPlayFabHttp() = 0;

        virtual size_t Update() = 0;

        virtual void MakePostRequest(const CallRequestContainerBase&) = 0;

    protected:
        static std::shared_ptr<IPlayFabHttp> httpInstance;
    };

    /// <summary>
    /// PlayFabHttp is the default https implementation for Win/C++, using cpprestsdk
    /// </summary>
    class PlayFabHttp : public IPlayFabHttp
    {
    public:
        static void MakeInstance();
        ~PlayFabHttp() override;

        virtual void MakePostRequest(const CallRequestContainerBase&) override;

        size_t Update() override;

    private:
        PlayFabHttp(); // Private constructor, to enforce singleton instance
        PlayFabHttp(const PlayFabHttp& other); // Private copy-constructor, to enforce singleton instance

        PlayFabHttp(PlayFabHttp&& other) = delete;
        PlayFabHttp& operator=(PlayFabHttp&& other) = delete;

        static size_t CurlReceiveData(char* buffer, size_t blockSize, size_t blockCount, void* userData);
        static void ExecuteRequest(CallRequestContainer& reqContainer);
        void WorkerThread();
        static void HandleCallback(CallRequestContainer& reqContainer);
        static void HandleResults(CallRequestContainer& reqContainer);

        std::thread pfHttpWorkerThread;
        std::mutex httpRequestMutex;
        bool threadRunning;
        int activeRequestCount;
        std::vector<CallRequestContainerBase*> pendingRequests;
        std::vector<CallRequestContainerBase*> pendingResults;
    };
}

