#pragma once

#include <curl/curl.h>
#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>
#include "GameServiceManagerTypes.h"

#define SERVICE_ADDR "127.0.0.1"

namespace ThunderRumble
{

    template<typename T>
    class ServiceHTTPRequest
    {
    public:
        std::string strEncoded;
        ServiceHTTPRequest(T request)
        {
            char buffer[64] = {};
            sprintf_s(buffer, "http://%s/%s/", SERVICE_ADDR, request.m_strEndpoint.c_str());

            curlHandle = curl_easy_init();
            curl_easy_reset(curlHandle);
            curl_easy_setopt(curlHandle, CURLOPT_URL, buffer);

            // Set up headers
            m_curlHttpHeaders = nullptr;
            m_curlHttpHeaders = curl_slist_append(m_curlHttpHeaders, "Accept: application/json");
            m_curlHttpHeaders = curl_slist_append(m_curlHttpHeaders, "Content-Type: application/json");
            m_curlHttpHeaders = curl_slist_append(m_curlHttpHeaders, "Authorization: eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiIsIng1dCI6IkZTaW11RnJGTm9DMHNKWEdtdjEzbk5aY2VEYyIsImtpZCI6IkZTaW11RnJGTm9DMHNKWEdtdjEzbk5aY2VEYyJ9.eyJhdWQiOiJodHRwczovL21pY3Jvc29mdC5vbm1pY3Jvc29mdC5jb20vYjdhMDQwNTgtNzU3NS00N2I3LWE1Y2EtOWU2MDk4NTRjNDE3IiwiaXNzIjoiaHR0cHM6Ly9zdHMud2luZG93cy5uZXQvNzJmOTg4YmYtODZmMS00MWFmLTkxYWItMmQ3Y2QwMTFkYjQ3LyIsImlhdCI6MTUyNDg3NDc0MCwibmJm");

            curl_easy_setopt(curlHandle, CURLOPT_HTTPHEADER, m_curlHttpHeaders);

            // Set up post & payload
            Json::Value requestBody = request.Serialize();
            requestBody["version"] = Json::Value(THUNDERRUMBLE_VERSION);

            Json::FastWriter writer;
            strEncoded = writer.write(requestBody);

            curl_easy_setopt(curlHandle, CURLOPT_CUSTOMREQUEST, "PUT");
            curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, strEncoded.c_str());

            // Process result
            curl_easy_setopt(curlHandle, CURLOPT_TIMEOUT_MS, 10000L);
            curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, this);
            curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, CurlReceiveData);

            curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, false);
        }

        static size_t CurlReceiveData(char* buffer, size_t blockSize, size_t blockCount, void* userData)
        {
            ServiceHTTPRequest* reqContainer = reinterpret_cast<ServiceHTTPRequest*>(userData);
            reqContainer->responseString.append(buffer, blockSize * blockCount);
            return (blockSize * blockCount);
        }

        ~ServiceHTTPRequest()
        {
            if (curlHandle != nullptr)
            {
                curl_easy_reset(curlHandle);
                curlHandle = nullptr;
            }

            if (m_curlHttpHeaders != nullptr)
            {
                m_curlHttpHeaders = nullptr;
            }
        }

        concurrency::task<Json::Value> Send()
        {
            const auto res = curl_easy_perform(curlHandle);

            if (res != CURLE_OK)
            {
                return concurrency::task_from_result(Json::Value::null);
            }
            else
            {
                Json::CharReaderBuilder jsonReaderFactory;
                std::unique_ptr<Json::CharReader> jsonReader(jsonReaderFactory.newCharReader());
                JSONCPP_STRING jsonParseErrors;
                const bool parsedSuccessfully = jsonReader->parse(responseString.c_str(), responseString.c_str() + responseString.length(), &responseJson, &jsonParseErrors);

                if (parsedSuccessfully)
                {
                    return concurrency::task_from_result(responseJson);
                }
                else
                {
                    return concurrency::task_from_result(Json::Value::null);
                }
            }
        }

    private:
        CURL* curlHandle = nullptr;
        curl_slist* m_curlHttpHeaders = nullptr;

    public:
        std::string responseString;
        Json::Value responseJson = Json::Value::null;
    };
}
