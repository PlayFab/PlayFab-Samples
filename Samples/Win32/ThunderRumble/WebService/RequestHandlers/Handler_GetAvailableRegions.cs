using Newtonsoft.Json;
using PlayFab.MultiplayerModels;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_GetAvailableRegions : BaseHandler
{
    AzureRegion[] g_AvailableRegions = new AzureRegion[]
    {
        AzureRegion.WestUs,
        AzureRegion.EastUs,
    };

    public Handler_GetAvailableRegions() : base(EndpointSecurityType.RequiresUserSession) { }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

#pragma warning disable 1998 // function doesnt have any async calls, but the base definition requires it
    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        return JsonConvert.SerializeObject(g_AvailableRegions);

    }
#pragma warning restore 1998

    public override int NumExpectedParameters() { return 0; }
}