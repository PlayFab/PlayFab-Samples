//--------------------------------------------------------------------------------------
// File: HttpCall.cpp
//
// An example use of IXMLHTTPRequest2Callback interface presented
// as a simplified HTTP request manager.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//-------------------------------------------------------------------------------------
#include "pch.h"

#include "HttpCall.h"

#if defined(XSAPI_CPP) && defined(_XBOX_ONE)
#include <ixmlhttprequest2.h>
#else
#include <msxml6.h>
#include <deque>
#endif

#define AUTOMATIC_INSERTION

using namespace Microsoft::WRL;

namespace ATG
{
    const size_t c_maxRequestChunkSize = 128 * 1024;

    std::wstring MakeLowerWString(const wchar_t* begin, const wchar_t *end)
    {
        std::wstring result;
        result.reserve(end - begin);

        while(begin != end)
        {
            result.push_back(towlower(*begin));
            ++begin;
        }

        return result;
    }

    std::wstring ConvertHeadersToString(const std::vector<ATG::HttpHeader> &headers)
    {
        std::wstring headerString = L"";

        for(const auto &header : headers)
        {
            headerString.append(header.Header());
            headerString.append(L": ");
            headerString.append(header.Value());
            headerString.append(L"\r\n");
        }
        return headerString;
    }

    std::wstring GetHostFromUrl(const wchar_t *url)
    {
        // Find first // then go up to next / if present
        auto begin = wcschr(url, L'/') + 2;
        auto end = wcschr(begin, L'/');

        if(end != nullptr)
            return MakeLowerWString(begin, end);
        else
            return MakeLowerWString(begin, url + wcslen(url));
    }

    std::vector<std::wstring> SplitString(const std::wstring &string, const std::wstring &token)
    {
        std::vector<std::wstring> splitString;

        size_t start = 0;
        size_t end = string.find_first_of(token);

        while (end != std::wstring::npos)
        {
            splitString.push_back(string.substr(start, end - start));

            start = end + token.length();
            end = string.find_first_of(token, start);
        }

        return splitString;
    }

    // Buffer with the required IStream interface to send data with and IXHR2 request. The only method
    // required for use is Read.  IXHR2 will not write to this buffer nor will it use anything from the IDispatch
    // interface.
    class HttpRequestStream : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IStream, IDispatch>
    {
    public:
        HttpRequestStream();
        ~HttpRequestStream();

        // IStream interface
        HRESULT STDMETHODCALLTYPE Read(void *buffer, unsigned long bufferSize, unsigned long *bytesRead) override;
        HRESULT STDMETHODCALLTYPE Write(const void *, unsigned long, unsigned long *) override { return E_NOTIMPL; }

        // Added functions for the IStream instead of ISequential Stream as provided by Gaspard to avoid issues that
        // some developers have encountered with the old ISequentialStream implementation of this class.
        // From forums post: https://forums.xboxlive.com/questions/78851/index.html
        HRESULT STDMETHODCALLTYPE Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition) override {
            switch (dwOrigin) {
            case STREAM_SEEK_SET:
                m_seekLocation = static_cast<size_t>(dlibMove.QuadPart);
                break;
            case STREAM_SEEK_CUR:
                m_seekLocation += static_cast<size_t>(dlibMove.QuadPart);
                break;
            case STREAM_SEEK_END:
                m_seekLocation = m_bufferSize + static_cast<size_t>(dlibMove.QuadPart);
                break;
            }

            if (plibNewPosition != nullptr)
            {
                plibNewPosition->QuadPart = m_seekLocation;
            }

            return S_OK;
        }

        HRESULT STDMETHODCALLTYPE Stat(STATSTG *pstatstg, DWORD grfStatFlag) override
        {
            UNREFERENCED_PARAMETER(grfStatFlag);
            pstatstg->cbSize.QuadPart = m_bufferSize;
            return S_OK;
        }

        HRESULT STDMETHODCALLTYPE SetSize(ULARGE_INTEGER /*libNewSize*/) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE CopyTo(IStream * /*pstm*/, ULARGE_INTEGER /*cb*/, ULARGE_INTEGER * /*pcbRead*/, ULARGE_INTEGER * /*pcbWritten*/) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE Commit(DWORD /*grfCommitFlags*/) override { return S_OK; }
        HRESULT STDMETHODCALLTYPE Revert(void) override { return S_OK; }
        HRESULT STDMETHODCALLTYPE LockRegion(ULARGE_INTEGER /*libOffset*/, ULARGE_INTEGER /*cb*/, DWORD /*dwLockType*/) override { return STG_E_INVALIDFUNCTION; }
        HRESULT STDMETHODCALLTYPE UnlockRegion(ULARGE_INTEGER /*libOffset*/, ULARGE_INTEGER /*cb*/, DWORD /*dwLockType*/) override { return STG_E_INVALIDFUNCTION; }
        HRESULT STDMETHODCALLTYPE Clone(IStream ** /*ppstm*/) override { return E_NOTIMPL; }

        // IUnknown interface
        HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void ** ppvObject) override
        {
            if (iid == __uuidof(IUnknown)
                || iid == __uuidof(IStream)
                || iid == __uuidof(ISequentialStream))
            {
                *ppvObject = static_cast<IStream*>(this);
                AddRef();
                return S_OK;
            }
            else
                return E_NOINTERFACE;
        }

        // IDispatch interface is required but not used in this context.  The methods are empty.
        HRESULT STDMETHODCALLTYPE GetTypeInfoCount(unsigned int FAR*) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE GetTypeInfo(unsigned int, LCID, ITypeInfo FAR* FAR*) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID, OLECHAR FAR* FAR*, unsigned int, LCID, DISPID FAR*) override { return DISP_E_UNKNOWNNAME; }
        HRESULT STDMETHODCALLTYPE Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS FAR*, VARIANT FAR*, EXCEPINFO FAR*, unsigned int FAR*) override { return S_OK; }

        // Methods created for simplicity when creating and passing along the buffer
        HRESULT Open(const void *buffer, size_t bufferSize);
        size_t Size() const { return m_bufferSize; }
    private:
        void AllocateInternalBuffer(size_t size);
        void FreeInternalBuffer();

        unsigned char    *m_buffer;
        size_t            m_seekLocation;
        size_t            m_bufferSize;
    };
    
    // This handles the data coming in from the HTTP request. As the data comes in it copies it into a growable buffer.
    // Upon completion of the request the buffers get combined into a contiguous buffer to be returned to the callback.
    class HttpCallback : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IXMLHTTPRequest2Callback>
    {
    public:
        HttpCallback();
        virtual ~HttpCallback();

        HRESULT RuntimeClassInitialize(std::function<void(HttpResponse *)> callback);
    
        // IXMLHTTPRequest2Callback Methods
        HRESULT STDMETHODCALLTYPE OnRedirect(IXMLHTTPRequest2 *, const WCHAR *) override { return S_OK; }
        HRESULT STDMETHODCALLTYPE OnHeadersAvailable(IXMLHTTPRequest2 *request, DWORD responseCode, const wchar_t *) override;
        HRESULT STDMETHODCALLTYPE OnDataAvailable(IXMLHTTPRequest2 *request, ISequentialStream *responseStream) override;
        HRESULT STDMETHODCALLTYPE OnResponseReceived(IXMLHTTPRequest2 *request, ISequentialStream *responseStream) override;
        HRESULT STDMETHODCALLTYPE OnError(IXMLHTTPRequest2 *request, HRESULT error) override;

        // Methods to build and send the call
        HRESULT OpenRequest(const wchar_t *verb, const wchar_t *url);
        HRESULT SetTimeout(unsigned long timeoutMs);
        HRESULT SetHeaders(const std::vector<HttpHeader> &headers);
        void SetContent(const unsigned char *buffer, size_t bufferSize);
        HRESULT Send();

        const std::wstring &GetHost() const { return m_host; }

    private:
        // The ISepentialStream does not have a method for returning it's size, so this is a grow-able buffer
        // for reading the data.
        struct MemoryPage
        {
            MemoryPage(unsigned char *buffer, size_t used = 0) : m_usedSpace(used), m_page(buffer) {}
    
            size_t m_usedSpace;
            unsigned char *m_page;
        };
        HRESULT ReadToBuffer(ISequentialStream *stream);
        MemoryPage &AllocatePage();
        MemoryPage MakeContiguous();
        std::vector<MemoryPage> m_memoryPages;

        // Response
        HttpResponse              m_response;

        // Request Data
        ComPtr<IXMLHTTPRequest2>  m_request;
        ComPtr<HttpRequestStream> m_requestBuffer;

        std::wstring              m_host;
    };
}

class ATG::HttpCallManager::Impl
{
public:
    Impl() :
        m_timeoutMS(0)
    {
        if (s_httpCallManager)
        {
            throw std::exception("HttpCallManager is a singleton");
        }

        s_httpCallManager = this;
    }
    ~Impl()
    {
        s_httpCallManager = nullptr;
    }

    std::vector<HttpResponse> DoWork()
    {
        std::vector<HttpResponse> currentResponses; 
        
        {
            // Move the responses to the new vector and clear the buffer.
            std::lock_guard<std::mutex> lock(m_responseLock);
            currentResponses = std::move(m_responses);
        }

        {
            std::lock_guard<std::mutex> lock(m_bufferedCallLock);
            // Go through all of the calls that were buffered for each endpoint and send
            // as many as possible.
            for(auto &hostQueue : m_bufferedCalls)
            {
                auto& queue = hostQueue.second;

                while (!queue.empty() && AcquireCallSlot(hostQueue.first))
                {
                    queue.front()->Send();
                    queue.pop_front();
                }
            }
        }
        
        return currentResponses;
    }

    HRESULT MakeHttpCall(const std::wstring &verb, 
                         const std::wstring &uri,
                         const unsigned char *buffer, 
                         size_t bufferSize,
                         const std::vector<HttpHeader> &headers,
                         std::function<void(HttpResponse *)> callback)
    {
        // Create the request
        ComPtr<HttpCallback> call;
        MakeAndInitialize<HttpCallback>(&call, callback);

        auto result = call->OpenRequest(verb.c_str(), uri.c_str());
        if (FAILED(result)) return result;

        result = call->SetHeaders(headers);
        if (FAILED(result)) return result;

        if(buffer != nullptr)
        {
            call->SetContent(buffer, bufferSize);
        }
        result = call->SetTimeout(m_timeoutMS);
        if (FAILED(result)) return result;

        auto host = GetHostFromUrl(uri.c_str());

        // IXHR2 can only have 6 calls to a specific endpoint in flight at once. This
        // will place the call in a queue if there are too many in flight and on the
        // next frame send it if there is space.
        if(AcquireCallSlot(host))
        {
            result = call->Send();
            if (FAILED(result)) return result;
        }
        else
        {
            std::lock_guard<std::mutex> lock(m_bufferedCallLock);
            m_bufferedCalls[host].push_back(call);
        }

        return result;
    }

    void SetTimeout(unsigned long timeoutMS)
    {
        m_timeoutMS = timeoutMS;
    }

    void AddResponse(HttpResponse response)
    {
        std::lock_guard<std::mutex> lock(m_responseLock);
        m_responses.push_back(response);
    }

    void RegisterHost(const std::wstring &host)
    {
        // Add a new endpoint counter if it doesn't exist.
        if(m_requestsInFlight.find(host) == m_requestsInFlight.end())
        {
            std::lock_guard<std::mutex> lock(m_requestsInFlightLock);
            // Make one more check before adding just in case another thread already added it
            if (m_requestsInFlight.find(host) == m_requestsInFlight.end())
            {
                m_requestsInFlight[host] = 0;
            }
        }
    }

    bool AcquireCallSlot(const std::wstring &host)
    {
        // IXHR2 only allows 6 calls in flight to a given endpoint
        std::lock_guard<std::mutex> lock(m_requestsInFlightLock);
        auto &counter = m_requestsInFlight[host];
        if (counter < 6)
        {
            ++counter;
            return true;
        }
        return false;
    }

    void ReleaseCallToHost(const std::wstring &host)
    {
        std::lock_guard<std::mutex> lock(m_requestsInFlightLock);
        --m_requestsInFlight[host];
    }

    static HttpCallManager::Impl* s_httpCallManager;
private:
    std::mutex                   m_responseLock;
    std::vector<HttpResponse>    m_responses;

    unsigned long                m_timeoutMS;

    std::mutex                                               m_requestsInFlightLock;
    std::map<std::wstring, int>                              m_requestsInFlight;
    std::mutex                                               m_bufferedCallLock;
    std::map<std::wstring, std::deque<ComPtr<HttpCallback>>> m_bufferedCalls;
};

ATG::HttpCallManager::Impl* ATG::HttpCallManager::Impl::s_httpCallManager = nullptr;

// Public Constructor
ATG::HttpCallManager::HttpCallManager() noexcept(false) :
    pImpl(new Impl())
{

}

// Public Destructor
ATG::HttpCallManager::~HttpCallManager()
{

}

// Public Methods
std::vector<ATG::HttpResponse> ATG::HttpCallManager::DoWork()
{
    return pImpl->DoWork();
}

HRESULT ATG::HttpCallManager::MakeHttpCall(const wchar_t *verb,
                                           const wchar_t *uri,
                                           const std::vector<HttpHeader> &headers, 
                                           std::function<void(HttpResponse *)> callback)
{
    return pImpl->MakeHttpCall(verb, uri, nullptr, 0, headers, callback );
}

HRESULT ATG::HttpCallManager::MakeHttpCall(const wchar_t *verb,
                                           const wchar_t *uri,
                                           const std::vector<HttpHeader> &headers, 
                                           std::vector<unsigned char> &bodyContent,
                                           std::function<void(HttpResponse *)> callback)
{
    return pImpl->MakeHttpCall(verb, uri, &bodyContent[0], bodyContent.size(), headers, callback);
}

#if defined(XSAPI_CPP)
HRESULT ATG::HttpCallManager::MakeHttpCallWithAuth(std::shared_ptr<xbox::services::xbox_live_context> userContext,
                                                   const wchar_t *verb, 
                                                   const wchar_t *uri,
                                                   const std::vector<HttpHeader> &headers, 
                                                   std::function<void(HttpResponse *)> callback)
{
    HRESULT result = S_OK;
#if defined(_XBOX_ONE) && defined(_TITLE)
    #if defined(AUTOMATIC_INSERTION)
    // On Xbox One auth headers will be auto inserted if the xbl-authz-actor-10 header 
    // is set with the user's hash
    auto authHeaders = headers;
    authHeaders.emplace_back(L"xbl-authz-actor-10", userContext->user()->XboxUserHash->Data());
    result = pImpl->MakeHttpCall(verb, uri, nullptr, 0, authHeaders, callback);
    #else

    std::wstring verbCapture = verb;
    std::wstring uriCapture = uri;

    // Demonstration of how to manually get the Authorization and Signature headers on Xbox
    auto asyncOp = userContext->user()->GetTokenAndSignatureAsync(ref new Platform::String(verb),
                                                                  ref new Platform::String(uri),
                                                                  ref new Platform::String(ConvertHeadersToString(headers).c_str()));
    concurrency::create_task(asyncOp).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> result)
    {
        try
        {
            auto payload = result.get();

            auto authHeaders = headers;
            authHeaders.emplace_back(L"Authorization", payload->Token->Data());
            authHeaders.emplace_back(L"Signature", payload->Signature->Data());
            
            auto httpResult = pImpl->MakeHttpCall(verbCapture, uriCapture, nullptr, 0, authHeaders, callback);

            // As we are in an async call, we can't return the result immediately.  So it gets queued
            // in the response queue.
            if (FAILED(httpResult))
            {
                HttpResponse response;
                response.SetError(httpResult, L"Error attempting to make call.");
                response.SetCallback(callback);
                pImpl->AddResponse(response);
            }
        }
        catch (Platform::Exception ^e)
        {
            HttpResponse response;
            response.SetError(e->HResult, e->Message->Data());
            response.SetCallback(callback);
            pImpl->AddResponse(response);
        }
    });
    #endif
#else
    // UWP doesn't have automatic insertion, so we have to use get_token_and_signature
    userContext->user()->get_token_and_signature(verb,uri, ConvertHeadersToString(headers))
        .then([=](xbox::services::xbox_live_result<xbox::services::system::token_and_signature_result> result)
        {
            if(result.err())
                return;

            auto payload = result.payload();

            auto authHeaders = headers;
            authHeaders.emplace_back(L"Authorization", payload.token().c_str());
            authHeaders.emplace_back(L"Signature", payload.signature().c_str());
            
            std::wstring verbCapture = verb;
            std::wstring uriCapture = uri;

            auto httpResult = pImpl->MakeHttpCall(verbCapture, uriCapture, nullptr, 0, authHeaders, callback);

            // As we are in an async call, we can't return the result immediately.  So it gets queued
            // in the response queue.
            if (FAILED(httpResult))
            {
                HttpResponse response;
                response.SetError(httpResult, L"Error attempting to make call.");
                response.SetCallback(callback);
                pImpl->AddResponse(response);
            }
        });
#endif
    return result;
}

HRESULT ATG::HttpCallManager::MakeHttpCallWithAuth(std::shared_ptr<xbox::services::xbox_live_context> userContext,
                                                   const wchar_t *verb, 
                                                   const wchar_t *uri,
                                                   const std::vector<HttpHeader> &headers, 
                                                   std::vector<unsigned char> &bodyContent,
                                                   std::function<void(HttpResponse *)> callback)
{
    HRESULT result = S_OK;
#if defined(_XBOX_ONE) && defined(_TITLE)
    #ifdef AUTOMATIC_INSERTION
    // On Xbox One auth headers will be auto inserted if the xbl-authz-actor-10 header 
    // is set with the user's hash
    auto authHeaders = headers;
    authHeaders.emplace_back(L"xbl-authz-actor-10", userContext->user()->XboxUserHash->Data());
    result = pImpl->MakeHttpCall(verb, uri, &bodyContent[0], bodyContent.size(), authHeaders, callback);
    #else

    std::wstring verbCapture = verb;
    std::wstring uriCapture = uri;

    // Demonstration of how to manually get the Authorization and Signature headers on Xbox
    auto asyncOp = userContext->user()->GetTokenAndSignatureAsync(ref new Platform::String(verb),
                                                                  ref new Platform::String(uri),
                                                                  ref new Platform::String(ConvertHeadersToString(headers).c_str()),
                                                                  ref new Platform::Array<unsigned char>(&bodyContent[0], static_cast<unsigned int>(bodyContent.size())));
    concurrency::create_task(asyncOp).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> result)
    {
        try
        {
            auto payload = result.get();

            auto authHeaders = headers;
            authHeaders.emplace_back(L"Authorization", payload->Token->Data());
            authHeaders.emplace_back(L"Signature", payload->Signature->Data());
            
            auto httpResult = pImpl->MakeHttpCall(verbCapture, uriCapture, &bodyContent[0], bodyContent.size(), authHeaders, callback);

            // As we are in an async call, we can't return the result immediately.  So it gets queued
            // in the response queue.
            if(FAILED(httpResult))
            {
                HttpResponse response;
                response.SetError(httpResult, L"Error attempting to make call.");
                response.SetCallback(callback);
                pImpl->AddResponse(response);
            }
        }
        catch (Platform::Exception ^e)
        {
            HttpResponse response;
            response.SetError(e->HResult, e->Message->Data());
            response.SetCallback(callback);
            pImpl->AddResponse(response);
        }
    });
    #endif
#else
    // UWP doesn't have automatic insertion, so we have to use get_token_and_signature
    std::wstring requestBodyString(bodyContent.begin(), bodyContent.end());
    userContext->user()->get_token_and_signature(verb, uri, ConvertHeadersToString(headers), requestBodyString)
        .then([=](xbox::services::xbox_live_result<xbox::services::system::token_and_signature_result> result)
        {
            if(result.err())
                return;

            auto payload = result.payload();

            auto authHeaders = headers;
            authHeaders.emplace_back(L"Authorization", payload.token().c_str());
            authHeaders.emplace_back(L"Signature", payload.signature().c_str());

            std::wstring verbCapture = verb;
            std::wstring uriCapture = uri;

            auto httpResult = pImpl->MakeHttpCall(verbCapture, uriCapture, &bodyContent[0], bodyContent.size(), authHeaders, callback);

            // As we are in an async call, we can't return the result immediately.  So it gets queued
            // in the response queue.
            if (FAILED(httpResult))
            {
                HttpResponse response;
                response.SetError(httpResult, L"Error attempting to make call.");
                response.SetCallback(callback);
                pImpl->AddResponse(response);
            }
        });
#endif
    return result;
}
#endif

void ATG::HttpCallManager::SetTimeout(unsigned long timeoutMS)
{
    pImpl->SetTimeout(timeoutMS);
}

void ATG::HttpResponse::ParseHeaders(const std::wstring &headers)
{
    auto headersSplit = SplitString(headers, L"\r\n");

    for (auto &headerLine : headersSplit)
    {
        size_t splitLocation = headerLine.find_first_of(L':');
        m_responseHeaders.emplace_back(headerLine.substr(0, splitLocation).c_str(), headerLine.substr(splitLocation + 1).c_str());
    }
}

// Callback for handling the http response
ATG::HttpCallback::HttpCallback()
{

}

ATG::HttpCallback::~HttpCallback()
{

}

HRESULT ATG::HttpCallback::OnHeadersAvailable(IXMLHTTPRequest2 *request, DWORD responseCode, const wchar_t *)
{
    if (request == nullptr)
    {
        return E_INVALIDARG;
    }

    m_response.SetResponseCode(responseCode);

    wchar_t* headers = nullptr;
    HRESULT hr = request->GetAllResponseHeaders(&headers);
    if (SUCCEEDED(hr))
    {
        // Parse the header string and parse into a vector<HttpHeader>
        m_response.ParseHeaders(headers);
    }

    // The header string that was passed in needs to be deleted here.
    if (headers != nullptr)
    {
        ::CoTaskMemFree(headers);
        headers = nullptr;
    }

    return S_OK;
}

HRESULT ATG::HttpCallback::OnDataAvailable(IXMLHTTPRequest2 *, ISequentialStream *responseStream)
{
    // Read in the available chunk of data.
    auto result = ReadToBuffer(responseStream);

    if(result == S_FALSE)
        return S_OK;
    return result;
}

HRESULT ATG::HttpCallback::OnResponseReceived(IXMLHTTPRequest2 *, ISequentialStream *responseStream)
{
    // Final chunk of data needs to be read
    auto result = ReadToBuffer(responseStream);
    
    // Combine all of the memory pages into a single contiguous buffer
    auto memory = MakeContiguous();
    m_response.SetResponseBody(memory.m_page, memory.m_usedSpace);

    // Let the HttpCallManager know the call is completed
    auto mgr = HttpCallManager::Impl::s_httpCallManager;
    if (!mgr)
    {
        throw std::exception("HttpCallManager");
    }
    // Release the slot so another call to this host can be made
    mgr->ReleaseCallToHost(m_host);
    // Add the response to the queue to be processed later.
    mgr->AddResponse(std::move(m_response));
    m_request.Reset();

    return result;
}

HRESULT ATG::HttpCallback::OnError(IXMLHTTPRequest2 *, HRESULT error)
{
    // If there is an error during the request, report it in an HttpResponse for processing
    std::wstring errorMessage = L"[HttpCallback::OnError] ";
    errorMessage.append(std::to_wstring(error));
    m_response.SetError(error, errorMessage);
    auto mgr = HttpCallManager::Impl::s_httpCallManager;
    if (!mgr)
    {
        throw std::exception("HttpCallManager");
    }
    mgr->ReleaseCallToHost(m_host);
    mgr->AddResponse(std::move(m_response));
    m_request.Reset();

    return S_OK;
}

HRESULT ATG::HttpCallback::ReadToBuffer(ISequentialStream *stream)
{
    // Get either a new page or a current not full page.
    MemoryPage *lastPage = nullptr;

    if (m_memoryPages.empty())
    {
        lastPage = &AllocatePage();
    }
    else
    {
        lastPage = &m_memoryPages.back();
    }

    HRESULT result = S_OK;
    do
    {
        size_t freeBufferSpace = c_maxRequestChunkSize - lastPage->m_usedSpace;

        if (freeBufferSpace == 0)
        {
            lastPage = &AllocatePage();
            freeBufferSpace = c_maxRequestChunkSize;
        }

        unsigned long bytesRead = 0;
        result = stream->Read(lastPage->m_page + lastPage->m_usedSpace, static_cast<unsigned long>(freeBufferSpace), &bytesRead);

        lastPage->m_usedSpace += bytesRead;
    } while (result == S_OK);

    return result;
}

ATG::HttpCallback::MemoryPage &ATG::HttpCallback::AllocatePage()
{
    MemoryPage page(new unsigned char[c_maxRequestChunkSize]);
    m_memoryPages.push_back(page);

    return m_memoryPages.back();
}

ATG::HttpCallback::MemoryPage ATG::HttpCallback::MakeContiguous()
{
    // if there was no data read, just return an empty memory page
    if (m_memoryPages.empty())
    {
        return MemoryPage(nullptr, 0);
    }

    // Compute the total space needed and allocate the new buffer
    size_t totalBufferSize = c_maxRequestChunkSize * (m_memoryPages.size() - 1) + m_memoryPages.back().m_usedSpace;
    unsigned char *combinedBuffer = new unsigned char[totalBufferSize];

    // Copy the data one page at a time to the new buffer and release the old ones.
    size_t offset = 0;
    for (auto &memory : m_memoryPages)
    {
        memcpy(combinedBuffer + offset, memory.m_page, memory.m_usedSpace);
        offset += memory.m_usedSpace;
        delete [] memory.m_page;
    }
    return MemoryPage(combinedBuffer, totalBufferSize);
}

// Com Interface to create the HttpCallback and initialize it with the provided callback.
HRESULT ATG::HttpCallback::RuntimeClassInitialize(std::function<void(HttpResponse *)> callback)
{
    m_response.SetCallback(callback);
    auto result = ::CoCreateInstance(__uuidof(FreeThreadedXMLHTTP60),
        nullptr,
        CLSCTX_SERVER,
        __uuidof(IXMLHTTPRequest2),
        &m_request);

    if (FAILED(result))
    {
#ifdef DEBUG
        OutputDebugStringW(L"HttpCallManager: Could not create IXMLHTTPRequest.");
#endif
    }

    return result;
}


HRESULT ATG::HttpCallback::OpenRequest(const wchar_t *verb, const wchar_t *url)
{
    auto result = m_request->Open(verb,
        url,
        this,
        nullptr,
        nullptr,
        nullptr,
        nullptr);

    if (FAILED(result))
    {
#ifdef DEBUG
        OutputDebugStringW(L"HttpCallManager: Could not open request");
#endif
        return result;
    }

    m_host = GetHostFromUrl(url);
    
    result = m_request->SetProperty(XHR_PROP_ONDATA_THRESHOLD, c_maxRequestChunkSize);

    if (FAILED(result))
    {
#ifdef DEBUG
        OutputDebugStringW(L"HttpCallManager: Could not set XHR_PROP_ONDATA_THRESHOLD.");
#endif
    }

    result = m_request->SetRequestHeader(L"User-Agent", L"ATG-HttpCallManager");

    if (FAILED(result))
    {
#ifdef DEBUG
        OutputDebugStringW(L"HttpCallManager: Could not set \"User-Agent\".");
#endif
    }

    return result;
}

HRESULT ATG::HttpCallback::SetTimeout(unsigned long timeoutMs)
{
    if (timeoutMs != 0)
    {
        m_request->SetProperty(XHR_PROP_TIMEOUT, timeoutMs);
    }
    return S_OK;
}

HRESULT ATG::HttpCallback::SetHeaders(const std::vector<HttpHeader> &headers)
{
    auto result = S_OK;
    for (const auto &header : headers)
    {
        result = m_request->SetRequestHeader(header.Header().c_str(), header.Value().c_str());

        if (FAILED(result))
        {
#ifdef DEBUG
            OutputDebugStringW(L"HttpCallManager: Could not set header.");
#endif
        }
    }
    return result;
}

void ATG::HttpCallback::SetContent(const unsigned char *buffer, size_t bufferSize)
{
    m_requestBuffer = Make<HttpRequestStream>();
    m_requestBuffer->Open(buffer, bufferSize);
    m_request->SetRequestHeader(L"Content-Length", std::to_wstring(bufferSize).c_str() );
}

HRESULT ATG::HttpCallback::Send()
{
    auto result = S_OK;
    
    if(m_requestBuffer != nullptr)
        result = m_request->Send(m_requestBuffer.Get(), m_requestBuffer->Size());
    else
        result = m_request->Send(nullptr, 0);
    // We no longer need to hang onto the buffer, let the request 
    // clean it up when it is done
    m_requestBuffer.Reset();
    m_requestBuffer = nullptr;

    if (FAILED(result))
    {
#ifdef DEBUG
        OutputDebugStringW(L"HttpCallManager: Could not send Http Request.");
#endif
    }

    return result;
}


// Read Only buffer for sending data
ATG::HttpRequestStream::HttpRequestStream() :
    m_buffer(nullptr),
    m_seekLocation(0),
    m_bufferSize(0)
{

}

ATG::HttpRequestStream::~HttpRequestStream()
{
    FreeInternalBuffer();
}

HRESULT ATG::HttpRequestStream::Open(const void *buffer, size_t bufferSize)
{
    AllocateInternalBuffer(bufferSize);

    memcpy(m_buffer, buffer, bufferSize);

    return S_OK;
}

HRESULT ATG::HttpRequestStream::Read(void *buffer, unsigned long bufferSize, unsigned long *bytesRead)
{
    if (buffer == nullptr)
    {
        return E_INVALIDARG;
    }

    long result = S_OK;

    if (bufferSize + m_seekLocation > m_bufferSize)
    {
        result = S_FALSE;

        // Calculate how many bytes are remaining 
        bufferSize = static_cast<unsigned long>(m_bufferSize - m_seekLocation);
    }

    memcpy(buffer, m_buffer + m_seekLocation, bufferSize);

    *bytesRead = bufferSize;
    m_seekLocation += bufferSize;
    
    return result;
}

void ATG::HttpRequestStream::AllocateInternalBuffer(size_t size)
{
    if (m_buffer != nullptr)
    {
        FreeInternalBuffer();
    }

    m_bufferSize = size;
    m_buffer = new unsigned char[size];
}

void ATG::HttpRequestStream::FreeInternalBuffer()
{
    delete[] m_buffer;
    m_buffer = nullptr;
}
