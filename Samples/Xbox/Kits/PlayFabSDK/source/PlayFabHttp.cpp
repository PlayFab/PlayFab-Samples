#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabSettings.h"

namespace PlayFab
{
    CallRequestContainer::~CallRequestContainer()
    {
        delete httpClient;
        delete httpRequest;
    }

    IPlayFabHttp* IPlayFabHttp::httpInstance = nullptr;
    IPlayFabHttp::~IPlayFabHttp() {}
    IPlayFabHttp& IPlayFabHttp::Get()
    {
        // In the future we could make it easier to override this instance with a sub-type, for now it defaults to the only one we have
        if (httpInstance == nullptr)
            PlayFabHttp::MakeInstance();
        return *httpInstance;
    }

    PlayFabHttp::PlayFabHttp()
    {
    }

    PlayFabHttp::~PlayFabHttp()
    {
        for (size_t i = 0; i < pendingRequests.size(); ++i)
            delete pendingRequests[i];
        pendingRequests.clear();
    }

    void PlayFabHttp::MakeInstance()
    {
        if (httpInstance == nullptr)
            httpInstance = new PlayFabHttp;
    }

    void PlayFabHttp::AddRequest(const utility::string_t& urlPath, const utility::string_t& authKey, const utility::string_t& authValue, const web::json::value& requestBody, RequestCompleteCallback internalCallback, SharedVoidPointer successCallback, ErrorCallback errorCallback, void* customData)
    {
        CallRequestContainer* reqContainer = new CallRequestContainer();
        reqContainer->request = requestBody;
        reqContainer->internalCallback = internalCallback;
        reqContainer->successCallback = successCallback;
        reqContainer->errorCallback = errorCallback;
        reqContainer->customData = customData;

        // Create http_client to send the request.
        reqContainer->httpClient = new web::http::client::http_client(PlayFabSettings::GetUrl(urlPath));
        reqContainer->httpRequest = new web::http::http_request(web::http::methods::POST);
        web::http::http_headers& headers = reqContainer->httpRequest->headers();
        headers.add(L"Content-Type", L"application/json");
        headers.add(L"X-PlayFabSDK", PlayFabSettings::versionString);
        headers.add(L"X-ReportErrorAsSuccess", L"true");
        if (authKey.length() != 0 && authValue.length() != 0)
            headers.add(authKey, authValue);
        reqContainer->httpRequest->set_body(reqContainer->request);

        auto requestTask = reqContainer->httpClient->request(*reqContainer->httpRequest);
        requestTask.then([=](Concurrency::task<web::http::http_response> responseTask)
        {
            web::http::http_response response;
            try
            {
                response = responseTask.get();
            }
            catch (const std::exception&)
            {
                // Handle Failures at this layer
                reqContainer->errorWrapper.UrlPath = ShortenString(PlayFabSettings::GetUrl(urlPath));
                reqContainer->errorWrapper.Request = requestBody;
                reqContainer->errorWrapper.HttpCode = 408;
                reqContainer->errorWrapper.ErrorCode = PlayFabErrorServiceUnavailable;
                reqContainer->errorWrapper.HttpStatus = "RequestTimeout";
                reqContainer->errorWrapper.ErrorMessage = "Failed to connect to PlayFab server";
                throw;
            }

            auto responseHeaders = response.headers();
            int httpCode = response.status_code();
            if (httpCode != 200)
            {
                // Handle Failures at this layer
                reqContainer->errorWrapper.UrlPath = ShortenString(PlayFabSettings::GetUrl(urlPath));
                reqContainer->errorWrapper.Request = requestBody;
                reqContainer->errorWrapper.HttpCode = httpCode;
                reqContainer->errorWrapper.ErrorCode = PlayFabErrorServiceUnavailable;
                reqContainer->errorWrapper.HttpStatus = "Failed";
                reqContainer->errorWrapper.ErrorMessage = "Failed to connect to PlayFab server";
                throw std::exception("Failed to connect to PlayFab server");
            }
            return response.extract_json();
        }).then([=](Concurrency::task<web::json::value> responseTask)
        {
            try
            {
                auto response = responseTask.get();
                if (response.is_object())
                    reqContainer->errorWrapper.FromJson(response);
                reqContainer->errorWrapper.UrlPath = ShortenString(PlayFabSettings::GetUrl(urlPath));
                reqContainer->errorWrapper.Request = requestBody;
            }
            catch (const std::exception&)
            {
            }

            reqContainer->finished = true;
            if (PlayFabSettings::threadedCallbacks)
                HandleResults(*reqContainer);
        });

        if (!PlayFabSettings::threadedCallbacks)
            pendingRequests.push_back(reqContainer);
    }

    void PlayFabHttp::HandleResults(CallRequestContainer& reqContainer)
    {
        // The success case must be handled by a function which is aware of the ResultType
        if (reqContainer.errorWrapper.HttpCode == 200)
        {
            reqContainer.internalCallback(reqContainer); // Unpacks the result as ResultType and invokes successCallback according to that type
        }
        else // Process the error case
        {
            if (PlayFabSettings::globalErrorHandler != nullptr)
                PlayFabSettings::globalErrorHandler(reqContainer.errorWrapper, reqContainer.customData);
            if (reqContainer.errorCallback != nullptr)
                reqContainer.errorCallback(reqContainer.errorWrapper, reqContainer.customData);
        }
    }

    size_t PlayFabHttp::Update()
    {
        if (PlayFabSettings::threadedCallbacks)
            throw std::runtime_error("You should not call Update() when PlayFabSettings::threadedCallbacks == true");

        if (pendingRequests.size() == 0)
            return 0;

        for (size_t i = 0; i < pendingRequests.size(); ++i)
        {
            size_t index = pendingRequests.size() - i - 1; // Go through the list in reverse
            CallRequestContainer* reqContainer = pendingRequests[index];
            if (!reqContainer->finished)
                continue;

            HandleResults(*reqContainer);

            // This is why we have to count backwards
            pendingRequests.erase(pendingRequests.begin() + index);
            delete reqContainer;
        }

        return pendingRequests.size(); // mHandles can change during FinalizeRequests
    }
}
