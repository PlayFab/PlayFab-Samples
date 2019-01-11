//#define FORCE_LOCALHOST

using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_GetLobbyInformation : BaseHandler
{
    public Handler_GetLobbyInformation() : base(EndpointSecurityType.None) { }
    class GetLobbyInformationBody
    {
        public string lobby_id = String.Empty;
    }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

#pragma warning disable 1998 // function doesnt have any async calls, but the base definition requires it
    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        GetLobbyInformationBody deserializedBody = JsonConvert.DeserializeObject<GetLobbyInformationBody>(requestBody);

        Lobby lobby = Program.g_LobbyManager.RetrieveLobby(deserializedBody.lobby_id);

        if (lobby != null)
        {
            return JsonConvert.SerializeObject(lobby);
        }

        return JsonConvert.SerializeObject("INVALID_LOBBY");
    }
#pragma warning restore 1998

    public override int NumExpectedParameters() { return 0; }
}

