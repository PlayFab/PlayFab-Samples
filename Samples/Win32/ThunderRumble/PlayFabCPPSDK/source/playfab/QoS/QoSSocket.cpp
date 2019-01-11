#include <stdafx.h>

#include <chrono>
#include <thread>
#include <iostream>
#include <cstdint>

#include <playfab/QoS/QoS.h>
#include <playfab/QoS/QoSSocket.h>

using namespace std;

namespace PlayFab
{
    namespace QoS
    {
        QoSSocket::QoSSocket()
        {
            xPlatSocket = make_unique<XPlatSocket>();
        }

        int QoSSocket::ConfigureSocket(int timeoutMs)
        {
            int errorCode = xPlatSocket->InitializeSocket();

            if (errorCode == 0)
            {
                // Set the port
                errorCode = xPlatSocket->SetPort(PORT);
            }

            if (errorCode == 0)
            {
                // Set the timeout
                errorCode = xPlatSocket->SetTimeout(timeoutMs);
            }

            // If the errorCode is not 0, return the last socket error.
            return (errorCode == 0) ? 0 : xPlatSocket->GetLastErrorCode();
        }

        int QoSSocket::SetAddress(const char * socketAddr)
        {
            // Set the socket to ping to the input address
            return xPlatSocket->SetAddress(socketAddr);
        }

        PingResult QoSSocket::GetQoSServerLatencyMs()
        {
            // Clear the buffer
            memset(buf, BUFFER_VALUE, BUFLEN);

            PingResult result(INT32_MAX, 0, 0);

            // Snap the start time
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

            // Send the message
            if (xPlatSocket->SendMessage(message) == SOCKET_ERROR)
            {
                result.errorCode = xPlatSocket->GetLastErrorCode();
                LOG_QOS("sendto() failed with error code : " << result.errorCode << endl);

                return std::move(result);
            }

            // Wait for the reply.
            
            if (xPlatSocket->ReceiveReply(buf, BUFLEN) == SOCKET_ERROR)
            {
                result.errorCode = xPlatSocket->GetLastErrorCode();
                LOG_QOS("recvfrom() failed with error code : " << result.errorCode << endl);

                return std::move(result);
            }

            // Snap the end time
            chrono::steady_clock::time_point end = chrono::steady_clock::now();

            // TODO : Can add error checking for the reply and return based on that
            //	The first 2 bytes should be set to 0s.

            // Calculate the total time
            chrono::milliseconds totalMilliseconds = chrono::duration_cast<chrono::milliseconds>(end - begin);

            result.latencyMs = totalMilliseconds.count();

            return std::move(result);
        }
    }
}