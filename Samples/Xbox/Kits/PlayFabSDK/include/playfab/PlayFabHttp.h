#pragma once

#include "cpprest/http_client.h"
#include "PlayFabError.h"
#include <functional>

namespace PlayFab
{
    struct CallRequestContainer;
    typedef void(*RequestCompleteCallback)(CallRequestContainer& reqContainer);
    typedef std::shared_ptr<void> SharedVoidPointer;

    /// <summary>
    /// Internal PlayFabHttp container for each api call
    /// </summary>
    struct CallRequestContainer
    {
        bool finished = false;
        web::http::client::http_client* httpClient;
        web::http::http_request* httpRequest;

        web::json::value request;
        PlayFabError errorWrapper;
        RequestCompleteCallback internalCallback;
        SharedVoidPointer successCallback;
        ErrorCallback errorCallback;
        void* customData;

        ~CallRequestContainer();
    };

    /// <summary>
    /// Provides an interface and a static instance for https implementations
    /// </summary>
    class IPlayFabHttp
    {
    public:
        static IPlayFabHttp& Get();

        virtual ~IPlayFabHttp();

        virtual void AddRequest(const utility::string_t& urlPath, const utility::string_t& authKey, const utility::string_t& authValue, const web::json::value& requestBody, RequestCompleteCallback internalCallback, SharedVoidPointer successCallback, ErrorCallback errorCallback, void* customData) = 0;
        virtual size_t Update() = 0;
    protected:
        static IPlayFabHttp* httpInstance;
    };

    /// <summary>
    /// PlayFabHttp is the default https implementation for Win/C++, using cpprestsdk
    /// </summary>
    class PlayFabHttp : public IPlayFabHttp
    {
    public:
        static void MakeInstance();

        ~PlayFabHttp() override;

        void AddRequest(const utility::string_t& urlPath, const utility::string_t& authKey, const utility::string_t& authValue, const web::json::value& requestBody, RequestCompleteCallback internalCallback, SharedVoidPointer successCallback, ErrorCallback errorCallback, void* customData) override;
        size_t Update() override;
    private:
        PlayFabHttp(); // Private constructor, to enforce singleton instance
        PlayFabHttp(const PlayFabHttp& other); // Private copy-constructor, to enforce singleton instance

        std::vector<CallRequestContainer*> pendingRequests;
        void HandleResults(CallRequestContainer& reqContainer);
    };
}
