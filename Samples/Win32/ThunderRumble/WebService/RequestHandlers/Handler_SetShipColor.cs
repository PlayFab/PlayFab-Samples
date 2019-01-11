using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_SetShipColor : BaseHandler
{
    public Handler_SetShipColor() : base(EndpointSecurityType.RequiresUserSession) { }

    class SetShipColorBody
    {
        public int ship_color = 0;
    }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

    struct SetShipColorBodyResult
    {

    }

#pragma warning disable 1998 // function doesnt have any async calls, but the base definition requires it
    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        SetShipColorBody deserializedBody = JsonConvert.DeserializeObject<SetShipColorBody>(requestBody);

        if (requestingPlayer != null)
        {
            if (requestingPlayer.IsInLobby())
            {
                requestingPlayer.ShipColor = deserializedBody.ship_color;

                SetShipColorBodyResult result;
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

