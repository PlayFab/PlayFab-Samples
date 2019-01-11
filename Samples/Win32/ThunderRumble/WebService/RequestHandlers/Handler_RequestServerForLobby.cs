using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_RequestServerForLobby : BaseHandler
{
    public Handler_RequestServerForLobby() : base(EndpointSecurityType.RequiresUserSession) { }
    class RequestServerForLobbyBody
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
        RequestServerForLobbyBody deserializedBody = JsonConvert.DeserializeObject<RequestServerForLobbyBody>(requestBody);
        Lobby lobby = Program.g_LobbyManager.RetrieveLobby(deserializedBody.lobby_id);

        if (lobby != null)
        {

        }

        return JsonConvert.SerializeObject("InvalidLobby");
    }
#pragma warning restore 1998

    public override int NumExpectedParameters() { return 0; }
}