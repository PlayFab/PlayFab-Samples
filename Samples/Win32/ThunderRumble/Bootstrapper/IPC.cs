using System;
using System.IO;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace ATGBootstrapper
{
    enum IPCPacketIdentifier : byte
    {
        ALLOCATED,
        ADDPLAYER,
        REMOVEPLAYER
    }

    class IPC : IDisposable
    {
        public IPC()
        {
            m_IPCClient = new TcpClient();
        }

        ~IPC()
        {
            if (m_IPCClient != null)
            {
                m_IPCClient.Close();
                m_IPCClient = null;
            }
        }

        public async Task<bool> Connect()
        {
            await m_IPCClient.ConnectAsync(System.Net.IPAddress.Loopback, 5001);
            return false;
        }
        public void SendAllocatedPacket(string sessionCookie)
        {
            IPCBuffer ipcBuffer = new IPCBuffer(m_IPCClient);
            ipcBuffer.WriteIdentifier(IPCPacketIdentifier.ALLOCATED);
            ipcBuffer.WriteString(sessionCookie);
            ipcBuffer.Flush();
        }

        public async void Update()
        {
            if (m_IPCClient.Connected)
            {
                IPCBuffer ipcBuffer = new IPCBuffer(m_IPCClient);
                if (ipcBuffer.HasPendingData())
                {
                    IPCPacketIdentifier packetIdentifer = (IPCPacketIdentifier)await ipcBuffer.Read<byte>();

                    switch (packetIdentifer)
                    {
                        case IPCPacketIdentifier.ADDPLAYER:
                            {
                                UInt32 userID = await ipcBuffer.Read<UInt32>();
                                string strDisplayName = await ipcBuffer.ReadString();

                                Console.WriteLine("Added Player: {0} ({1})", strDisplayName, userID);
                                PlayerManager.AddPlayer(userID, strDisplayName);
                                break;
                            }
                        case IPCPacketIdentifier.REMOVEPLAYER:
                            {
                                UInt32 userID = await ipcBuffer.Read<UInt32>();

                                Console.WriteLine("Removed Player: {0}", userID);
                                PlayerManager.RemovePlayer(userID);
                                break;
                            }
                        default:
                            {
                                Console.WriteLine("Got unhandled packet type with identifier {0}", (int)packetIdentifer);
                                break;
                            }
                    }
                }
            }
        }

        public void Dispose()
        {
            ((IDisposable)m_IPCClient).Dispose();
        }

        private TcpClient m_IPCClient = null;
    }

    class IPCBuffer : IDisposable
    {
        public IPCBuffer(TcpClient ipcClient)
        {
            m_ipcClient = ipcClient;
            m_StreamWriter = new StreamWriter(m_ipcClient.GetStream());
            m_StreamReader = new StreamReader(m_StreamWriter.BaseStream);
        }

        ~IPCBuffer()
        {

        }

        public async Task<IPCPacketIdentifier> ReadIdentifier()
        {
            return (IPCPacketIdentifier)await ReadByte();
        }

        public async Task<byte> ReadByte()
        {
            return await Read<byte>();
        }

        public async Task<string> ReadString()
        {
            int len = await Read<int>();

            char[] charStr = new char[len];
            m_StreamReader.ReadBlock(charStr, 0, len);
            return new string(charStr);
        }

        public void WriteIdentifier(IPCPacketIdentifier identifier)
        {
            m_StreamWriter.Write((char)identifier);
        }

        public void WriteByte(byte b)
        {
            m_StreamWriter.Write((char)b);
        }

        public void WriteString(string str)
        {
            m_StreamWriter.Write(str);
        }

        public void Flush()
        {
            m_StreamWriter.Flush();
        }

        public bool HasPendingData()
        {
            return m_ipcClient.Available > 0;
        }

        public async Task<T> Read<T>()
        {
            try
            {
                if (!m_StreamReader.EndOfStream)
                {
                    int sizeOfType = System.Runtime.InteropServices.Marshal.SizeOf(typeof(T));
                    char[] readBuffer = new char[sizeOfType];
                    await m_StreamReader.ReadBlockAsync(readBuffer, 0, sizeOfType);

                    unsafe
                    {
                        fixed (char* ptr = readBuffer)
                        {
                            return (T)Marshal.PtrToStructure((IntPtr)ptr, typeof(T));
                        }
                    }
                }
            }
            catch
            {

            }
            return default(T);
        }

        public void Dispose()
        {
            ((IDisposable)m_ipcClient).Dispose();
            ((IDisposable)m_StreamWriter).Dispose();
            ((IDisposable)m_StreamReader).Dispose();
        }

        private TcpClient m_ipcClient = null;
        private StreamWriter m_StreamWriter = null;
        private StreamReader m_StreamReader = null;
    }
}