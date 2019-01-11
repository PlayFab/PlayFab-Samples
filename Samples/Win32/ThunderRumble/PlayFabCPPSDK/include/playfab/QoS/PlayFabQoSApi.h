#pragma once

#include <future>
#include <chrono>
#include <unordered_map>

#include <playfab/QoS/QoS.h>
#include <playfab/QoS/QoSResult.h>
#include <playfab/QoS/QoSSocket.h>
#include <playfab/PlayFabMultiplayerDataModels.h>
#include <playfab/PlayFabEventsDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    namespace QoS
    {
        class PlayFabQoSApi
        {
        public:
            // Runs a QoS operation asynchronously. The operation pings a set of datacenters and returns a result with average response times.
            std::future<QoSResult> GetQoSResultAsync(unsigned int numThreads, unsigned int timeoutMs = DEFAULT_TIMEOUT_MS);

            // Runs a QoS operation synchronously. The operation pings a set of datacenters and returns a result with average response times.
            QoSResult GetQoSResult(unsigned int numThreads, unsigned int timeoutMs = DEFAULT_TIMEOUT_MS);

        private:
            std::vector<PlayFab::MultiplayerModels::AzureRegion> GetPingList(unsigned int serverCount);
            void InitializeAccumulatedPingResults(std::unordered_map<PlayFab::MultiplayerModels::AzureRegion, PingResult>& accumulatedPingResults);
            int SetupSockets(std::vector<std::shared_ptr<QoSSocket>>& sockets, unsigned int numThreads, unsigned int timeoutMs);
            void InitializeAsyncPingResults(std::vector<std::future<PingResult>>& asyncPingResults);
            void PingServers(std::vector<PlayFab::MultiplayerModels::AzureRegion>& pings, std::vector<std::future<PingResult>>& asyncPingResults, std::vector<std::shared_ptr<QoSSocket>>& sockets, std::unordered_map<PlayFab::MultiplayerModels::AzureRegion, PingResult>& accumulatedPingResults, unsigned int timeoutMs);
            void UpdateAccumulatedPingResult(PingResult& result, PlayFab::MultiplayerModels::AzureRegion region, std::unordered_map<PlayFab::MultiplayerModels::AzureRegion, PingResult>& accumulatedPingResults, unsigned int timeoutMs);
            QoSResult GetResult(unsigned int numThreads, unsigned int timeoutMs);

            void PingThunderheadForServerList();
            static void ListQosServersSuccessCallBack(const PlayFab::MultiplayerModels::ListQosServersResponse& result, void* customData);
            static void ListQosServersFailureCallBack(const PlayFab::PlayFabError& error, void* customData);

            void SendResultsToPlayFab(QoSResult& result);
            static void WriteEventsSuccessCallBack(const PlayFab::EventsModels::WriteEventsResponse& result, void*);
            static void WriteEventsFailureCallBack(const PlayFab::PlayFabError& error, void*);

            static PingResult GetQoSResultForDatacenter(std::shared_ptr<QoSSocket> socket);

        private:
            const int numOfPingIterations = NUM_OF_PING_ITERATIONS; // Number of pings to do to each server, to calculate an average latency.
            const std::chrono::milliseconds threadWaitTimespan = std::chrono::milliseconds(THREAD_WAIT_MS);

            std::unordered_map<PlayFab::MultiplayerModels::AzureRegion, std::string> dataCenterMap;
            bool listQosServersCompleted;
        };
    }
}