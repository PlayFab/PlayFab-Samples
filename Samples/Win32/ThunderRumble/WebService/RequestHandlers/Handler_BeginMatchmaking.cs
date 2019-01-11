using Newtonsoft.Json;
using PlayFab.MultiplayerModels;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_BeginMatchmaking : BaseHandler
{
    public Handler_BeginMatchmaking() : base(EndpointSecurityType.RequiresUserSession) { }

    class BeginMatchmakingBody : BaseRequestBody
    {
        public AzureRegion preferred_region = AzureRegion.WestUs;
    }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

#pragma warning disable 1998 // function doesnt have any async calls, but the base definition requires it
    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        BeginMatchmakingBody deserializedBody = JsonConvert.DeserializeObject<BeginMatchmakingBody>(requestBody);

        if (requestingPlayer != null)
        {
            if (!requestingPlayer.IsInLobby())
            {
                requestingPlayer.StartMatchmaking(deserializedBody.preferred_region);
                return JsonConvert.SerializeObject(requestingPlayer);
            }
            else
            {
                return JsonConvert.SerializeObject("ERROR_ALREADY_IN_LOBBY");
            }
        }

        return JsonConvert.SerializeObject("UNEXPECTED_ERROR");
    }
#pragma warning restore 1998

    public override int NumExpectedParameters() { return 0; }
}