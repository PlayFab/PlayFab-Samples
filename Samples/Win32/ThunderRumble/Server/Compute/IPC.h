#pragma once
#include "Manager.h"

enum IPCPacketIdentifier
{
	IPCPacketIdentifier_ALLOCATED,
	IPCPacketIdentifier_ADDPLAYER,
	IPCPacketIdentifier_REMOVEPLAYER,
};

class IPCBuffer
{
public:
	IPCBuffer()
	{
		m_Buffer.resize(ms_DefaultBufferLength);
	}

	const char* ReadString() const
	{
		return &m_Buffer[m_BytesRead];
	}

	template<typename T>
	T Read()
	{
		T val = (T)m_Buffer[m_BytesRead];
		m_BytesRead += sizeof(T);
		return val;
	}

	void AppendString(const char* szBuffer)
	{
		size_t len = strlen(szBuffer);
		WriteBytes((BYTE*)len, sizeof(len));
		WriteBytes((BYTE*)szBuffer, len * sizeof(char));
	}

	void AppendString(const wchar_t* szBuffer)
	{
		char szString[64] = { 0 };
		size_t len = wcslen(szBuffer);
		WideCharToMultiByte(CP_ACP, 0, szBuffer, static_cast<int>(len), szString, static_cast<int>(len), nullptr, nullptr);
		WriteBytes((BYTE*)&len, sizeof(len));
		WriteBytes((BYTE*)szString, len);

	}

	void WriteIdentifier(IPCPacketIdentifier identifier)
	{
		WriteBytes((BYTE*)&identifier, sizeof(BYTE));
	}

	void WriteBytes(BYTE* pBytes, size_t numBytes)
	{
		memcpy(&m_Buffer[0] + m_BytesWritten, pBytes, numBytes);
		m_BytesWritten += numBytes;
	}

	char* GetBuffer()
	{
		return &m_Buffer[0];
	}

	size_t GetLength() const
	{
		return m_BytesWritten;
	}

	int ReceiveFrom(SOCKET socket)
	{
		int recvLen = 0;
		recvLen = recv(socket, &m_Buffer[m_BytesWritten], (int)m_Buffer.size(), 0);
		m_BytesWritten += recvLen;

		return recvLen;
	}

	void SendTo(SOCKET socket)
	{
		if (m_BytesWritten > 0)
		{
			send(socket, (char*)&m_Buffer[0], (int)m_BytesWritten, 0);
		}
		
	}

private:
	std::vector<char> m_Buffer;

	size_t m_BytesWritten = 0;
	size_t m_BytesRead = 0;
	const unsigned int ms_DefaultBufferLength = 512;
};

typedef std::function<void(const IPCBuffer&)> IPCCallbackFunc;

class IPC : public ThunderRumble::Manager
{
public:
	IPC();
	~IPC();

	void Update();

    void AddPlayer(unsigned int userID, const std::wstring& strPlayerName);
    void RemovePlayer(unsigned int userID);

	void RegisterCallback(IPCPacketIdentifier packetIdentifier, IPCCallbackFunc callbackFunc);

private:
	SOCKET ClientSocket = INVALID_SOCKET;
	SOCKET ListenSocket = INVALID_SOCKET;

	std::map<IPCPacketIdentifier, IPCCallbackFunc> m_mapCallbackFuncs;
};