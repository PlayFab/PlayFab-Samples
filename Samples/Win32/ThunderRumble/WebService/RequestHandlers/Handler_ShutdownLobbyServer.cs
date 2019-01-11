using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_ShutdownLobbyServer : BaseHandler
{
    public Handler_ShutdownLobbyServer() : base(EndpointSecurityType.RequiresUserSession) { }

    class ShutdownLobbyServerBody
    {
        public string lobby_id = String.Empty;
    }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        ShutdownLobbyServerBody deserializedBody = JsonConvert.DeserializeObject<ShutdownLobbyServerBody>(requestBody);
        Lobby lobby = Program.g_LobbyManager.RetrieveLobby(deserializedBody.lobby_id);

        if (lobby != null)
        {
            return await lobby.KillServerInstance();
        }

        return JsonConvert.SerializeObject("InvalidLobby");
    }

    public override int NumExpectedParameters() { return 0; }
}