//#define FORCE_LOCALHOST

using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_PulseMatchmaking : BaseHandler
{
    public Handler_PulseMatchmaking() : base(EndpointSecurityType.RequiresUserSession) { }
    class PulseMatchmakingBody
    {

    }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

    struct PulseMatchmakingResult
    {
        public int LocalPlayerIndex;
        public Lobby LobbyInstance;
    }

#pragma warning disable 1998 // function doesnt have any async calls, but the base definition requires it
    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        PulseMatchmakingBody deserializedBody = JsonConvert.DeserializeObject<PulseMatchmakingBody>(requestBody);

        if (requestingPlayer != null)
        {
            if (requestingPlayer.IsInLobby())
            {
                PulseMatchmakingResult result;
                result.LocalPlayerIndex = -1;

                int index = 1;
                foreach (var lobbyPlayer in requestingPlayer.CurrentLobby.Members)
                {
                    if (lobbyPlayer == requestingPlayer)
                    {
                        result.LocalPlayerIndex = index;
                        break;
                    }

                    ++index;
                }

                result.LobbyInstance = requestingPlayer.CurrentLobby;
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

