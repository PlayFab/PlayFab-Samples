using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

class WebServer : IDisposable
{
    private HttpListener m_Listener = new HttpListener();
    private Dictionary<string, BaseHandler> m_Handlers = new Dictionary<string, BaseHandler>();
    private readonly string AuthToken = "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiIsIng1dCI6IkZTaW11RnJGTm9DMHNKWEdtdjEzbk5aY2VEYyIsImtpZCI6IkZTaW11RnJGTm9DMHNKWEdtdjEzbk5aY2VEYyJ9.eyJhdWQiOiJodHRwczovL21pY3Jvc29mdC5vbm1pY3Jvc29mdC5jb20vYjdhMDQwNTgtNzU3NS00N2I3LWE1Y2EtOWU2MDk4NTRjNDE3IiwiaXNzIjoiaHR0cHM6Ly9zdHMud2luZG93cy5uZXQvNzJmOTg4YmYtODZmMS00MWFmLTkxYWItMmQ3Y2QwMTFkYjQ3LyIsImlhdCI6MTUyNDg3NDc0MCwibmJm";

    private readonly PlayFabMultiplayerServerHelper m_PlayfabCompute = new PlayFabMultiplayerServerHelper();

    ~WebServer()
    {
        Dispose();
    }

    public void Dispose()
    {
        m_Listener.Stop();
        m_Listener.Close();
    }

    private void Print(ConsoleColor color, string strFormat, params object[] parameters)
    {
        Console.ForegroundColor = color;
        Console.WriteLine(strFormat, parameters);
        Console.ForegroundColor = ConsoleColor.Gray;
    }

    private void InitializeHandlers()
    {
        m_Handlers.Add("timestamp", new Handler_Timestamp());
        m_Handlers.Add("paramstest", new Handler_ParamsTest());
        m_Handlers.Add("requestserverforlobby", new Handler_RequestServerForLobby());
        m_Handlers.Add("killlobby", new Handler_KillLobby());
        m_Handlers.Add("shutdownlobbyserver", new Handler_ShutdownLobbyServer());
        m_Handlers.Add("registerplayer", new Handler_RegisterPlayer());
        m_Handlers.Add("beginmatchmaking", new Handler_BeginMatchmaking());
        m_Handlers.Add("pulsematchmaking", new Handler_PulseMatchmaking());
        m_Handlers.Add("adddevelopmentserver", new Handler_AddDevelopmentServer());
        m_Handlers.Add("getlobbyinformation", new Handler_GetLobbyInformation());
        m_Handlers.Add("pingdevelopmentserver", new Handler_PingDevelopmentServer());
        m_Handlers.Add("getavailableregions", new Handler_GetAvailableRegions());
        m_Handlers.Add("setshipcolor", new Handler_SetShipColor());
        m_Handlers.Add("setshipvariant", new Handler_SetShipVariant());
        m_Handlers.Add("setreadystate", new Handler_SetReadyState());

    }

    private void BindToIP(IPAddress ipAddr)
    {
        string formattedIpAddr = String.Format("http://{0}:80/", ipAddr.ToString());
        m_Listener.Prefixes.Add(formattedIpAddr);
        Print(ConsoleColor.Cyan, "\tBinding to {0}", formattedIpAddr);
    }

    public bool Init()
    {
        if (!HttpListener.IsSupported)
        {
            Print(ConsoleColor.Red, "Windows XP SP2 or Server 2003 is required to use the HttpListener class.");
            return false;
        }

        // Initialize PlayFab SDK
        PlayFab.PlayFabSettings.TitleId = "<INSERT TITLE ID HERE>";
        PlayFab.PlayFabSettings.DeveloperSecretKey = "<INSERT TITLE DEVELOPER SECRET HERE>";

        Print(ConsoleColor.Cyan, "Finding IP addresses to bind to:");

        // Bind to primary ipv4 network adapter
        foreach (IPAddress ipAddr in Dns.GetHostEntry(Dns.GetHostName()).AddressList.Where(ip => ip.AddressFamily == AddressFamily.InterNetwork))
        {
            BindToIP(ipAddr);
        }
        BindToIP(IPAddress.Loopback);

        InitializeHandlers();

        m_Listener.Start();

        return true;
    }

    public async void Update()
    {
        // Expire old dev servers
        await Program.g_DevelopmentServersMutex.WaitAsync();

        for (int i = Program.g_lstDevelopmentServers.Count - 1; i >= 0; i--)
        {
            int timeSinceLastUpdate = Environment.TickCount - Program.g_lstDevelopmentServers[i].lastUpdate;
            if (timeSinceLastUpdate > 10000)
            {
                Program.g_lstDevelopmentServers.RemoveAt(i);
            }
        }
        Program.g_DevelopmentServersMutex.Release();
    }

    public void Run()
    {
        ThreadPool.QueueUserWorkItem(o =>
        {
            Print(ConsoleColor.Green, "Webserver is now listening for connections...");

            while (m_Listener.IsListening)
            {
                ThreadPool.QueueUserWorkItem(async c =>
                {
                    var ctx = c as HttpListenerContext;
                    try
                    {
                        if (ctx == null)
                        {
                            return;
                        }

                            // Do we have auth header?
                            if (ctx.Request.Headers.Get("Authorization") == null)
                        {
                            ctx.Response.StatusCode = 401;
                            Print(ConsoleColor.Yellow, "Blocked Unauthorized request from {0} (No Auth Header)", ctx.Request.UserHostAddress);
                            return;
                        }

                        string requestAuthToken = ctx.Request.Headers["Authorization"].Replace("Bearer ", ""); ;
                        if (requestAuthToken != AuthToken)
                        {
                            ctx.Response.StatusCode = 401;
                            Print(ConsoleColor.Yellow, "Blocked Unauthorized request from {0} (Invalid Auth Token)", ctx.Request.UserHostAddress);
                            return;
                        }

                        string[] explodedUri = ctx.Request.RawUrl.Split('/');
                        string funcName = explodedUri[1];

                        long paramsLen = explodedUri.Length - 2;
                        string[] parameters = new string[paramsLen];
                        Array.Copy(explodedUri, 2, parameters, 0, paramsLen);
                        parameters = parameters.Where(x => !string.IsNullOrEmpty(x)).ToArray();

                        string reqBody = new StreamReader(ctx.Request.InputStream).ReadToEnd();
                        string respStr = String.Empty;

                            // Do we have a handler?
                            if (m_Handlers.ContainsKey(funcName))
                        {
                            BaseHandler handler = m_Handlers[funcName];

                                // Do we have the expected security authorization?
                                bool bMeetsSecurityReq = false;
                            Player associatedPlayer = null;
                            if (handler.EndpointSecurity != EndpointSecurityType.None)
                            {
                                switch (handler.EndpointSecurity)
                                {
                                    case EndpointSecurityType.RequiresUserSession:
                                        {
                                                // attempt to read the UserSession from the JSON body
                                                // any exception here will trigger the finally and catch block below, terminating the request and cleaning up nicely
                                                dynamic reqBodyDeserialized = Newtonsoft.Json.Linq.JObject.Parse(reqBody);
                                            string UserSessionID = reqBodyDeserialized.user_session;
                                            if (UserSessionID == null)
                                            {
                                                bMeetsSecurityReq = false;
                                            }
                                            else
                                            {
                                                    // Is the session valid?
                                                    associatedPlayer = Program.g_PlayerManager.GetPlayerFromSession(UserSessionID);
                                                if (associatedPlayer != null)
                                                {
                                                    bMeetsSecurityReq = true;
                                                }
                                                else
                                                {
                                                    bMeetsSecurityReq = false;
                                                }
                                            }
                                            break;
                                        }

                                    default:
                                        {
                                            bMeetsSecurityReq = false;
                                            break;
                                        }
                                }

                            }
                            else
                            {
                                bMeetsSecurityReq = true;
                            }

                            if (!bMeetsSecurityReq)
                            {
                                ctx.Response.StatusCode = 403;
                                string errorStr = String.Format("-> {0} expected auth type {1}. A valid session was not provided.", handler.GetType().Name, handler.EndpointSecurity);
                                Print(ConsoleColor.Green, errorStr);
                                respStr = errorStr;
                            }
                            else
                            {
                                if (handler.NumExpectedParameters() == parameters.Length || handler.NumExpectedParameters() == -1)
                                {
                                    Print(ConsoleColor.Green, "-> Routing {2} request {0} to {1}", funcName, handler.GetType().Name, ctx.Request.HttpMethod);

                                    if (ctx.Request.HttpMethod == "GET")
                                    {
                                        respStr = await handler.ProcessRequest_Get(associatedPlayer, ctx.Request, parameters);
                                    }
                                    else if (ctx.Request.HttpMethod == "PUT")
                                    {
                                        respStr = await handler.ProcessRequest_Put(associatedPlayer, ctx.Request, parameters, reqBody);
                                    }
                                    else
                                    {
                                        Print(ConsoleColor.Green, "-> Request {0} with method {1} was not handled.", funcName, ctx.Request.HttpMethod);
                                    }

                                }
                                else
                                {
                                    string errorStr = String.Format("-> Invalid number of parameters for {0}. Expected: {1}. Got: {2}", handler.GetType().Name, handler.NumExpectedParameters(), parameters.Length);
                                    Print(ConsoleColor.Green, errorStr);
                                    respStr = errorStr;
                                }
                            }
                        }
                        else
                        {
                            respStr = "Function not registered.";
                        }

                        ctx.Response.ContentType = "application/json";
                        var buf = Encoding.UTF8.GetBytes(respStr);
                        ctx.Response.ContentLength64 = buf.Length;
                        ctx.Response.OutputStream.Write(buf, 0, buf.Length);
                    }
                    catch (Exception ex)
                    {
                        Print(ConsoleColor.Red, "Ctx Exception: {0}", ex.Message);
                    }
                    finally
                    {
                            // always close stream
                            if (ctx != null)
                        {
                            try { ctx.Response.OutputStream.Close(); } catch { };
                        }
                    }
                }, m_Listener.GetContext());
            }
        });
    }
}