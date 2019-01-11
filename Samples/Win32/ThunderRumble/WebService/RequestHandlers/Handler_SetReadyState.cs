using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_SetReadyState : BaseHandler
{
    public Handler_SetReadyState() : base(EndpointSecurityType.RequiresUserSession) { }
    class SetReadyStateBody
    {
        public bool is_ready = false;
    }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

    struct SetReadyStateBodyResult
    {

    }

#pragma warning disable 1998 // function doesnt have any async calls, but the base definition requires it
    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        SetReadyStateBody deserializedBody = JsonConvert.DeserializeObject<SetReadyStateBody>(requestBody);

        if (requestingPlayer != null)
        {
            if (requestingPlayer.IsInLobby())
            {
                requestingPlayer.IsReady = deserializedBody.is_ready;

                SetReadyStateBodyResult result;
                return JsonConvert.SerializeObject(result);
            }
            else
            {
                return JsonConvert.SerializeObject("NOT_IN_LOBBY");
            }
        }

        return JsonConvert.SerializeObject("UNEXPECTED_ERROR");
    }
#pragma warning restore 1998

    public override int NumExpectedParameters() { return 0; }
}

