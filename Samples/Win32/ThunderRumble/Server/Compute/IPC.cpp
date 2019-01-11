#include "pch.h"
#include "IPC.h"

#define IPC_PORT "5001"

IPC::IPC()
{
	WSADATA wsaData;
	int iResult;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		std::wcout << L"[COMPUTE IPC] WSAStartup failed with error: " << iResult << std::endl;
		return;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(NULL, IPC_PORT, &hints, &result);
	if (iResult != 0) {
		std::wcout << L"[COMPUTE IPC] getaddrinfo failed with error: " << iResult << std::endl;
		WSACleanup();
		return;
	}

	char ipAddr[INET_ADDRSTRLEN];
	inet_ntop(result->ai_family, (void*)&((sockaddr_in const *)result->ai_addr)->sin_addr, ipAddr, INET_ADDRSTRLEN);
	std::wcout << L"[COMPUTE IPC] Binding to " << ipAddr << L":" << IPC_PORT << std::endl;

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		std::wcout << L"[COMPUTE IPC] socket failed with error: " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		WSACleanup();
		return;
	}

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		std::wcout << L"[COMPUTE IPC] bind failed with error:" << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		std::wcout << L"[COMPUTE IPC] listen failed with error: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return;
	}

    std::wcout << L"IPC Manager created" << std::endl;
}

IPC::~IPC()
{
	if (ListenSocket != INVALID_SOCKET)
	{
		shutdown(ListenSocket, SD_SEND);
		closesocket(ListenSocket);
	}

	if (ClientSocket != INVALID_SOCKET)
	{
		shutdown(ClientSocket, SD_SEND);
		closesocket(ClientSocket);
	}

	WSACleanup();
}

void IPC::RegisterCallback(IPCPacketIdentifier packetIdentifier, IPCCallbackFunc callbackFunc)
{
	m_mapCallbackFuncs.insert(std::pair<IPCPacketIdentifier, IPCCallbackFunc>(packetIdentifier, callbackFunc));
}

void IPC::AddPlayer(unsigned int userID, const std::wstring& strPlayerName)
{
	IPCBuffer sendBuffer;
	sendBuffer.WriteIdentifier(IPCPacketIdentifier_ADDPLAYER);
	sendBuffer.WriteBytes((BYTE*)&userID, sizeof(userID));
	sendBuffer.AppendString(strPlayerName.c_str());
	sendBuffer.SendTo(ClientSocket);
}

void IPC::RemovePlayer(unsigned int userID)
{
	IPCBuffer sendBuffer;
	sendBuffer.WriteIdentifier(IPCPacketIdentifier_REMOVEPLAYER);
	sendBuffer.WriteBytes((BYTE*)&userID, sizeof(userID));
	sendBuffer.SendTo(ClientSocket);
}

void IPC::Update()
{
	IPCBuffer recvBuffer;

	// Accept a client socket
	fd_set readSetListen;
	FD_ZERO(&readSetListen);
	FD_SET(ListenSocket, &readSetListen);
	timeval timeout;
	timeout.tv_sec = 0;  // Zero timeout (poll)
	timeout.tv_usec = 0;
	if (select((int)ListenSocket, &readSetListen, NULL, NULL, &timeout) == 1)
	{
		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			std::wcout << L"[COMPUTE IPC] accept failed with error: " << WSAGetLastError() << std::endl;
			closesocket(ListenSocket);
			WSACleanup();
			return;
		}

		// No longer need listen socket
		closesocket(ListenSocket);
	}

	fd_set readSet;
	FD_ZERO(&readSet);
	FD_SET(ClientSocket, &readSet);
	if (select((int)ClientSocket, &readSet, NULL, NULL, &timeout) == 1)
	{
		int iResult = recvBuffer.ReceiveFrom(ClientSocket);
		if (iResult > 0)
		{
			BYTE bytePacketIdentifier = recvBuffer.Read<BYTE>();
			bool bHadBuiltInHandler = true;

			// Incase we have any built in handling, do that first
			switch ((int)bytePacketIdentifier)
			{
				case IPCPacketIdentifier::IPCPacketIdentifier_ADDPLAYER:
				{
					break;
				}

				case IPCPacketIdentifier::IPCPacketIdentifier_REMOVEPLAYER:
				{
					break;
				}

				case IPCPacketIdentifier::IPCPacketIdentifier_ALLOCATED:
				{
					break;
				}


			default:
				bHadBuiltInHandler = false;
				break;
			}

			// Now call the callback func (if registered)
            auto callback = m_mapCallbackFuncs.find((IPCPacketIdentifier)bytePacketIdentifier);
			if (callback != m_mapCallbackFuncs.end())
			{
				callback->second(recvBuffer);
			}
			else if (!bHadBuiltInHandler)
			{
				std::wcout << L"[COMPUTE IPC] Received unhandled packet with identifier: " << bytePacketIdentifier << std::endl;
			}
		}
		else if (iResult == 0)
		{
			std::wcout << L"[COMPUTE IPC] Socket Closed" << std::endl;
		}
	}
}

