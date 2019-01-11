using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class DevelopmentServer
{
    public string ipAddr;
    public UInt16 port;
    public bool IsAllocated = false;
    public string SessionCookie = String.Empty;

    [JsonIgnore]
    public int lastUpdate = Environment.TickCount;

    public static bool operator ==(DevelopmentServer p1, DevelopmentServer p2)
    {
        if (object.ReferenceEquals(p1, null))
        {
            return object.ReferenceEquals(p2, null);
        }
        else if (object.ReferenceEquals(p2, null))
        {
            return false;
        }

        return p1.ipAddr == p2.ipAddr && p1.port == p2.port;
    }

    public static bool operator !=(DevelopmentServer p1, DevelopmentServer p2)
    {
        return !(p1 == p2);
    }

    public override bool Equals(object o)
    {
        DevelopmentServer rhs = o as DevelopmentServer;

        if (rhs == null)
        {
            return false;
        }

        return this.ipAddr.Equals(rhs.ipAddr) && this.port.Equals(rhs.port);
    }

    public override int GetHashCode()
    {
        return this.ipAddr.GetHashCode() + this.port.GetHashCode();
    }
}

class Handler_AddDevelopmentServer : BaseHandler
{
    public Handler_AddDevelopmentServer() : base(EndpointSecurityType.None) { }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        DevelopmentServer deserializedBody = JsonConvert.DeserializeObject<DevelopmentServer>(requestBody);
        await Program.g_DevelopmentServersMutex.WaitAsync();
        Program.g_lstDevelopmentServers.Add(new DevelopmentServer { ipAddr = deserializedBody.ipAddr, port = deserializedBody.port });
        Program.g_DevelopmentServersMutex.Release();
        return JsonConvert.SerializeObject("RegisteredServer");
    }

    public override int NumExpectedParameters() { return 0; }
}