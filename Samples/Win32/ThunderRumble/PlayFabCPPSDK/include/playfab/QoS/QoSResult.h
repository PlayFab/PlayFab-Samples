#pragma once

#include <vector>

#include <playfab/QoS/DataCenterResult.h>

namespace PlayFab
{
    namespace QoS
    {
        /// <summary>
        /// A class that holds a result of the whole QoS operation.
        /// </summary>
        class QoSResult
        {
        public:
            QoSResult() = default;
            QoSResult(QoSResult&&) = default;
            QoSResult(const QoSResult&) = delete;
            QoSResult& operator=(QoSResult&&) = default;
            QoSResult& operator=(const QoSResult&) = delete;

            // A list of datacenter results. Each element contains a ping result for a datacenter.
            std::vector<DataCenterResult> dataCenterResults;

            // An error code of the whole QoS operation.
            int lastErrorCode;
        };
    }
}