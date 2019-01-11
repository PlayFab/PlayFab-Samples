#include <stdafx.h>

#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>

// Intellisense-only includes
#include <curl/curl.h>

#include <stdexcept>

namespace PlayFab
{
    std::shared_ptr<IPlayFabHttp> IPlayFabHttp::httpInstance = nullptr;
    IPlayFabHttp::~IPlayFabHttp() = default;
    IPlayFabHttp& IPlayFabHttp::Get()
    {
        return *GetPtr().get();
    }

    std::shared_ptr<IPlayFabHttp> IPlayFabHttp::GetPtr()
    {
        // In the future we could make it easier to override this instance with a sub-type, for now it defaults to the only one we have
        if (httpInstance == nullptr)
        {
            PlayFabHttp::MakeInstance();
        }

        return httpInstance;
    }

    PlayFabHttp::PlayFabHttp()
    {
        activeRequestCount = 0;
        threadRunning = true;
        pfHttpWorkerThread = std::thread(&PlayFabHttp::WorkerThread, this);
    };

    PlayFabHttp::~PlayFabHttp()
    {
        threadRunning = false;
        pfHttpWorkerThread.join();
        for (size_t i = 0; i < pendingRequests.size(); ++i)
        {
            delete pendingRequests[i];
        }

        pendingRequests.clear();

        for (size_t i = 0; i < pendingResults.size(); ++i)
        {
            delete pendingResults[i];
        }

        pendingResults.clear();

        activeRequestCount = 0;
    }

    void PlayFabHttp::MakeInstance()
    {
        if (httpInstance == nullptr)
        {
#if __cplusplus > 201103L
            class _PlayFabHttp : public PlayFabHttp {}; // Hack to bypass private constructor on PlayFabHttp
            httpInstance = std::make_shared<_PlayFabHttp>();
#else
#pragma message("PlayFab SDK: C++11 support is not well tested. Please consider upgrading to the latest version of Visual Studio")
            httpInstance = std::shared_ptr<PlayFabHttp>(new PlayFabHttp());
#endif
        }
    }

    void PlayFabHttp::WorkerThread()
    {
        size_t queueSize;

        while (this->threadRunning)
        {
            CallRequestContainerBase* reqContainer = nullptr;

            { // LOCK httpRequestMutex
                std::unique_lock<std::mutex> lock(this->httpRequestMutex);

                queueSize = this->pendingRequests.size();
                if (queueSize != 0)
                {
                    reqContainer = this->pendingRequests[this->pendingRequests.size() - 1];
                    this->pendingRequests.pop_back();
                }
            } // UNLOCK httpRequestMutex

            if (queueSize == 0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                continue;
            }

            if (reqContainer != nullptr)
            {
                ExecuteRequest(*static_cast<CallRequestContainer*>(reqContainer));
            }
        }
    }

    void PlayFabHttp::HandleCallback(CallRequestContainer& reqContainer)
    {
        reqContainer.finished = true;
        if (PlayFabSettings::threadedCallbacks)
        {
            HandleResults(reqContainer);
        }

        if (!PlayFabSettings::threadedCallbacks)
        {
            PlayFabHttp& instance = static_cast<PlayFabHttp&>(Get());
            { // LOCK httpRequestMutex
                std::unique_lock<std::mutex> lock(instance.httpRequestMutex);
                instance.pendingResults.push_back(&reqContainer);
            } // UNLOCK httpRequestMutex
        }
    }

    size_t PlayFabHttp::CurlReceiveData(char* buffer, size_t blockSize, size_t blockCount, void* userData)
    {
        CallRequestContainer* reqContainer = reinterpret_cast<CallRequestContainer*>(userData);
        reqContainer->responseString.append(buffer, blockSize * blockCount);

        return (blockSize * blockCount);
    }

    void PlayFabHttp::MakePostRequest(const CallRequestContainerBase& reqContainer)
    {
        { // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            pendingRequests.push_back(const_cast<CallRequestContainerBase*>(&reqContainer));
            activeRequestCount++;
        } // UNLOCK httpRequestMutex
    }

    void PlayFabHttp::ExecuteRequest(CallRequestContainer& reqContainer)
    {
        // Set up curl handle
        reqContainer.curlHandle = curl_easy_init();
        curl_easy_reset(reqContainer.curlHandle);
        curl_easy_setopt(reqContainer.curlHandle, CURLOPT_URL, PlayFabSettings::GetUrl(reqContainer.GetUrl(), PlayFabSettings::requestGetParams).c_str());

        // Set up headers
        reqContainer.curlHttpHeaders = nullptr;
        reqContainer.curlHttpHeaders = curl_slist_append(reqContainer.curlHttpHeaders, "Accept: application/json");
        reqContainer.curlHttpHeaders = curl_slist_append(reqContainer.curlHttpHeaders, "Content-Type: application/json; charset=utf-8");
        reqContainer.curlHttpHeaders = curl_slist_append(reqContainer.curlHttpHeaders, ("X-PlayFabSDK: " + PlayFabSettings::versionString).c_str());
        reqContainer.curlHttpHeaders = curl_slist_append(reqContainer.curlHttpHeaders, "X-ReportErrorAsSuccess: true");

        auto headers = reqContainer.GetHeaders();

        if (headers.size() > 0)
        {
            for (auto const &obj : headers)
            {
                if (obj.first.length() != 0 && obj.second.length() != 0) // no empty keys or values in headers
                {
                    std::string header = obj.first + ": " + obj.second;
                    reqContainer.curlHttpHeaders = curl_slist_append(reqContainer.curlHttpHeaders, header.c_str());
                }
            }
        }

        curl_easy_setopt(reqContainer.curlHandle, CURLOPT_HTTPHEADER, reqContainer.curlHttpHeaders);

        // Set up post & payload
        std::string payload = reqContainer.GetRequestBody();
        curl_easy_setopt(reqContainer.curlHandle, CURLOPT_POST, nullptr);
        curl_easy_setopt(reqContainer.curlHandle, CURLOPT_POSTFIELDS, payload.c_str());

        // Process result
        // TODO: CURLOPT_ERRORBUFFER ?
        curl_easy_setopt(reqContainer.curlHandle, CURLOPT_TIMEOUT_MS, 10000L);
        curl_easy_setopt(reqContainer.curlHandle, CURLOPT_WRITEDATA, &reqContainer);
        curl_easy_setopt(reqContainer.curlHandle, CURLOPT_WRITEFUNCTION, CurlReceiveData);

        // Send
        curl_easy_setopt(reqContainer.curlHandle, CURLOPT_SSL_VERIFYPEER, false); // TODO: Replace this with a ca-bundle ref???
        const auto res = curl_easy_perform(reqContainer.curlHandle);

        if (res != CURLE_OK)
        {
            reqContainer.errorWrapper.HttpCode = 408;
            reqContainer.errorWrapper.HttpStatus = "Failed to contact server";
            reqContainer.errorWrapper.ErrorCode = PlayFabErrorConnectionTimeout;
            reqContainer.errorWrapper.ErrorName = "Failed to contact server";
            reqContainer.errorWrapper.ErrorMessage = "Failed to contact server, curl error: " + std::to_string(res);
            HandleCallback(reqContainer);
        }
        else
        {
            Json::CharReaderBuilder jsonReaderFactory;
            std::unique_ptr<Json::CharReader> jsonReader(jsonReaderFactory.newCharReader());
            JSONCPP_STRING jsonParseErrors;
            const bool parsedSuccessfully = jsonReader->parse(reqContainer.responseString.c_str(), reqContainer.responseString.c_str() + reqContainer.responseString.length(), &reqContainer.responseJson, &jsonParseErrors);

            if (parsedSuccessfully)
            {
                reqContainer.errorWrapper.HttpCode = reqContainer.responseJson.get("code", Json::Value::null).asInt();
                reqContainer.errorWrapper.HttpStatus = reqContainer.responseJson.get("status", Json::Value::null).asString();
                reqContainer.errorWrapper.Data = reqContainer.responseJson.get("data", Json::Value::null);
                reqContainer.errorWrapper.ErrorName = reqContainer.responseJson.get("error", Json::Value::null).asString();
                reqContainer.errorWrapper.ErrorMessage = reqContainer.responseJson.get("errorMessage", Json::Value::null).asString();
                reqContainer.errorWrapper.ErrorDetails = reqContainer.responseJson.get("errorDetails", Json::Value::null);
            }
            else
            {
                reqContainer.errorWrapper.HttpCode = 408;
                reqContainer.errorWrapper.HttpStatus = reqContainer.responseString;
                reqContainer.errorWrapper.ErrorCode = PlayFabErrorConnectionTimeout;
                reqContainer.errorWrapper.ErrorName = "Failed to parse PlayFab response";
                reqContainer.errorWrapper.ErrorMessage = jsonParseErrors;
            }

            HandleCallback(reqContainer);
        }
    }

    void PlayFabHttp::HandleResults(CallRequestContainer& reqContainer)
    {
        auto callback = reqContainer.GetCallback();
        if (callback != nullptr)
        {
            callback(
                reqContainer.responseJson.get("code", Json::Value::null).asInt(),
                reqContainer.responseString,
                reqContainer);
        }
    }

    size_t PlayFabHttp::Update()
    {
        if (PlayFabSettings::threadedCallbacks)
        {
            throw std::runtime_error("You should not call Update() when PlayFabSettings::threadedCallbacks == true");
        }

        CallRequestContainerBase* reqContainer;
        { // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            if (pendingResults.empty())
            {
                return activeRequestCount;
            }

            reqContainer = pendingResults[pendingResults.size() - 1];
            pendingResults.pop_back();
            activeRequestCount--;
        } // UNLOCK httpRequestMutex

        // The callback called from HandleResults may delete the object pointed by reqContainer from the heap; do not use it after this call
        HandleResults(*static_cast<CallRequestContainer*>(reqContainer));

        // activeRequestCount can be altered by HandleResults, so we have to re-lock and return an updated value
        { // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            return activeRequestCount;
        }
    }
}
