#include <stdafx.h>

#include <playfab/PlayFabCallRequestContainer.h>

namespace PlayFab
{
    CallRequestContainerBase::CallRequestContainerBase(
        std::string url,
        const std::unordered_map<std::string, std::string>& headers,
        std::string requestBody,
        CallRequestContainerCallback callback,
        void* customData) :
        url(url),
        headers(headers),
        requestBody(requestBody),
        callback(callback),
        customData(customData)
    {
    }

    CallRequestContainerBase::CallRequestContainerBase(const CallRequestContainerBase& otherContainer)
    {
        *this = otherContainer;
    }

    const CallRequestContainerBase& CallRequestContainerBase::operator=(const CallRequestContainerBase& otherContainer)
    {
        if (this != &otherContainer)
        {
            this->url = otherContainer.url;
            this->headers = otherContainer.headers;
            this->requestBody = otherContainer.requestBody;
            this->callback = otherContainer.callback;
            this->customData = otherContainer.customData;
        }

        return *this;
    }

    CallRequestContainerBase::~CallRequestContainerBase()
    {
    }

    std::string CallRequestContainerBase::GetUrl() const
    {
        return url;
    }

    std::unordered_map<std::string, std::string> CallRequestContainerBase::GetHeaders() const
    {
        return headers;
    }

    std::string CallRequestContainerBase::GetRequestBody() const
    {
        return requestBody;
    }

    CallRequestContainerCallback CallRequestContainerBase::GetCallback() const
    {
        return callback;
    }

    void* CallRequestContainerBase::GetCustomData() const
    {
        return customData;
    }
}
