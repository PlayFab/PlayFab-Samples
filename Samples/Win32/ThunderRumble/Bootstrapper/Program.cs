//#define LOCAL_BUILD

using Microsoft.Playfab.Gaming.GSDK.CSharp;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Sockets;
using System.Text;

namespace ATGBootstrapper
{
    static class PlayerManager
    {
        private static Dictionary<UInt32, string> Players = new Dictionary<UInt32, string>();
        private static bool PlayersIsDirty = false;

        public static void AddPlayer(UInt32 userID, string strDisplayName)
        {
            Players[userID] = strDisplayName;
            PlayersIsDirty = true;
        }

        public static void RemovePlayer(UInt32 userID)
        {
            Players.Remove(userID);
            PlayersIsDirty = true;
        }

        public static void ProcessPlayerList()
        {
            // Update player list if dirty
            if (PlayersIsDirty)
            {
                PlayersIsDirty = false;

                List<ConnectedPlayer> lstPlayers = new List<ConnectedPlayer>();
                foreach (var keyValuePair in Players)
                {
                    lstPlayers.Add(new ConnectedPlayer(keyValuePair.Value));
                }

                GameserverSDK.UpdateConnectedPlayers(lstPlayers);
            }
        }
    }

    class Program
    {
        static private Process g_ServerProcess = null;
        static private Process remoteDebuggerProc = null;
        static private bool g_bServerAllocated = false;
        static private bool g_bPendingServerAllocationIPCMsg = false;
        static private SessionCookie g_SessionCookie;

        class Config
        {
            public bool enable_remote_debug = false;
        }

        static private void StartRemoteDebugging()
        {
            // unzip remote debugger
            try
            {
                Directory.Delete(Path.Combine("external_tools", "remotedebugger"));
            }
            catch
            {

            }

            try
            {
                ZipFile.ExtractToDirectory(Path.Combine("external_tools", "remotedebugger.zip"), Path.Combine("external_tools", "remotedebugger"));
            }
            catch
            {

            }

            // NOTE: local debugger runs an msvsmon instance
            var targetNumProcesses = System.Diagnostics.Debugger.IsAttached ? 1 : 0;

            if (Process.GetProcessesByName("msvsmon").Length == targetNumProcesses)
            {
                string msvsmonPath = Path.Combine(Directory.GetCurrentDirectory(), "external_tools", "remotedebugger", "Common7", "IDE", "Remote Debugger", "x64", "msvsmon.exe");

                // run config
                LogMessage("Configuring system for remote debugging");
                remoteDebuggerProc = new Process();
                remoteDebuggerProc.StartInfo.FileName = msvsmonPath;
                remoteDebuggerProc.StartInfo.Arguments = "/prepcomputer /quiet";
                remoteDebuggerProc.Start();
                remoteDebuggerProc.WaitForExit();

                // run msvsmon
                LogMessage("Starting remote debugger");
                remoteDebuggerProc = new Process();
                remoteDebuggerProc.StartInfo.FileName = msvsmonPath;
                remoteDebuggerProc.StartInfo.Arguments = "/nostatus /nosecuritywarn /nofirewallwarn /nodiscovery /port 4022 /noauth /anyuser";
                remoteDebuggerProc.Start();
            }
        }

        static private void LoadConfig()
        {
            string strConfigPath = Path.Combine(Directory.GetCurrentDirectory(), "config.json");

            Config conf = JsonConvert.DeserializeObject<Config>(File.ReadAllText(strConfigPath));

            if (conf.enable_remote_debug)
            {
                StartRemoteDebugging();
            }
        }

        static void LogMessage(string strMessage)
        {
            File.AppendAllLines(g_bIsRunningInComputeEnvironment ? Path.Combine(GameserverSDK.GetLogsDirectory(), "log.txt") : "log.txt", new string[] { strMessage });
            Console.WriteLine(strMessage);
        }

        const string strAuthHeader = "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiIsIng1dCI6IkZTaW11RnJGTm9DMHNKWEdtdjEzbk5aY2VEYyIsImtpZCI6IkZTaW11RnJGTm9DMHNKWEdtdjEzbk5aY2VEYyJ9.eyJhdWQiOiJodHRwczovL21pY3Jvc29mdC5vbm1pY3Jvc29mdC5jb20vYjdhMDQwNTgtNzU3NS00N2I3LWE1Y2EtOWU2MDk4NTRjNDE3IiwiaXNzIjoiaHR0cHM6Ly9zdHMud2luZG93cy5uZXQvNzJmOTg4YmYtODZmMS00MWFmLTkxYWItMmQ3Y2QwMTFkYjQ3LyIsImlhdCI6MTUyNDg3NDc0MCwibmJm";
        struct DevelopmentServerRequest
        {
            public string ipAddr;
            public uint port;
        }
        static HttpClient g_HttpClient = null;

        static async void RegisterAsDevelopmentServer()
        {
            IPAddress primaryNetworkAdapterAddr = Dns.GetHostEntry(Dns.GetHostName()).AddressList.Where(ip => ip.AddressFamily == AddressFamily.InterNetwork).ElementAt(0);
            DevelopmentServerRequest devServerRequest = new DevelopmentServerRequest { ipAddr = primaryNetworkAdapterAddr.ToString(), port = 5000 };
            await g_HttpClient.PutAsync(String.Format("http://{0}/adddevelopmentserver", primaryNetworkAdapterAddr.ToString()), new StringContent(JsonConvert.SerializeObject(devServerRequest), Encoding.UTF8, "application/json"));
        }

        class PingServerResponse
        {
            public string ipAddr = String.Empty;
            public UInt16 port = 0;
            public bool IsAllocated = false;
            public string SessionCookie = String.Empty;
        }

        static async void PingDevelopmentServer()
        {
            IPAddress primaryNetworkAdapterAddr = Dns.GetHostEntry(Dns.GetHostName()).AddressList.Where(ip => ip.AddressFamily == AddressFamily.InterNetwork).ElementAt(0);
            DevelopmentServerRequest devServerRequest = new DevelopmentServerRequest { ipAddr = primaryNetworkAdapterAddr.ToString(), port = 5000 };
            var resp = await g_HttpClient.PutAsync(String.Format("http://{0}/pingdevelopmentserver", primaryNetworkAdapterAddr.ToString()), new StringContent(JsonConvert.SerializeObject(devServerRequest), Encoding.UTF8, "application/json"));
            var jsonResp = await resp.Content.ReadAsStringAsync();

            try
            {
                PingServerResponse respDeserialized = JsonConvert.DeserializeObject<PingServerResponse>(jsonResp);
                bool bAllocated = respDeserialized.IsAllocated;

                // Did we just get allocated?
                if (!g_bServerAllocated && bAllocated)
                {
                    g_bServerAllocated = bAllocated;
                    string SessCookie = respDeserialized.SessionCookie;
                    g_SessionCookie = JsonConvert.DeserializeObject<SessionCookie>(SessCookie);
                    g_bPendingServerAllocationIPCMsg = true;
                }
            }
            catch
            {

            }
        }

        static bool g_bIsRunningInComputeEnvironment = true;
        static int g_LastPingDevelopmentServer = Environment.TickCount;
        static IPC g_IPC = new IPC();

        class SessionCookie
        {
            public string lobbyID = String.Empty;
        }

        static async void Initialize()
        {
            try
            {
                GameserverSDK.Start();
                LoadConfig();

                GameserverSDK.RegisterShutdownCallback(() =>
                {
                    g_ServerProcess.Kill();
                });
            }
            catch
            {
                g_bIsRunningInComputeEnvironment = false;

                g_HttpClient = new HttpClient();
                g_HttpClient.DefaultRequestHeaders.Add("Authorization", strAuthHeader);

                // We're running in a dev environment, so lets dummy add our server
                RegisterAsDevelopmentServer();
            }

            LaunchServer();

            await g_IPC.Connect();

            if (g_bIsRunningInComputeEnvironment)
            {
                GameserverSDK.ReadyForPlayers();
                g_bServerAllocated = true;
                g_bPendingServerAllocationIPCMsg = true;
            }
        }

        static void Main(string[] args)
        {
            Initialize();

            while (!g_ServerProcess.HasExited)
            {
                g_IPC.Update();

                if (g_bIsRunningInComputeEnvironment)
                {
                    PlayerManager.ProcessPlayerList();
                }

                if (!g_bIsRunningInComputeEnvironment)
                {
                    if (!g_bServerAllocated && Environment.TickCount - g_LastPingDevelopmentServer >= 250)
                    {
                        g_LastPingDevelopmentServer = Environment.TickCount;
                        PingDevelopmentServer();
                    }
                }

                if (g_bPendingServerAllocationIPCMsg)
                {
                    g_bPendingServerAllocationIPCMsg = false;
                    g_IPC.SendAllocatedPacket(JsonConvert.SerializeObject(g_SessionCookie));
                }

                System.Threading.Thread.Sleep(1);
            }

            if (remoteDebuggerProc != null)
            {
                remoteDebuggerProc.Kill();
            }
        }

        static void LaunchServer()
        {
            // Bind gameserver to primary ipv4 network adapter
            IPAddress ipAddr = Dns.GetHostEntry(Dns.GetHostName()).AddressList.Where(ip => ip.AddressFamily == AddressFamily.InterNetwork).ElementAt(0);

            g_ServerProcess = new Process();
            g_ServerProcess.StartInfo.FileName = "ThunderRumbleServer.exe";
            g_ServerProcess.StartInfo.Arguments = String.Format("-host {0} -port {1}", g_bIsRunningInComputeEnvironment ? "0.0.0.0" : ipAddr.ToString(), 5000) + (g_bIsRunningInComputeEnvironment ? String.Format(" -logpath {0}", GameserverSDK.GetLogsDirectory()) : "");
            g_ServerProcess.StartInfo.UseShellExecute = false;
            g_ServerProcess.StartInfo.RedirectStandardOutput = true;
            g_ServerProcess.OutputDataReceived += OnOutputDataReceived;
            g_ServerProcess.Start();
            g_ServerProcess.BeginOutputReadLine();
        }

        private static void OnOutputDataReceived(object sender, DataReceivedEventArgs e)
        {
            Console.WriteLine(e.Data);
        }
    }
}
