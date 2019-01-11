using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_PingDevelopmentServer : BaseHandler
{
    public Handler_PingDevelopmentServer() : base(EndpointSecurityType.None) { }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        DevelopmentServer deserializedBody = JsonConvert.DeserializeObject<DevelopmentServer>(requestBody);

        DevelopmentServer serverToUse = null;
        await Program.g_DevelopmentServersMutex.WaitAsync();
        foreach (DevelopmentServer devServer in Program.g_lstDevelopmentServers)
        {
            if (devServer == deserializedBody)
            {
                serverToUse = devServer;
                devServer.lastUpdate = Environment.TickCount;
            }
        }
        Program.g_DevelopmentServersMutex.Release();
        return JsonConvert.SerializeObject(serverToUse);
    }

    public override int NumExpectedParameters() { return 0; }
}