using Newtonsoft.Json;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_KillLobby : BaseHandler
{
    public Handler_KillLobby() : base(EndpointSecurityType.RequiresUserSession) { }
    class KillLobbyBody
    {
        public string lobby_id = String.Empty;
    }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

    public override async Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        KillLobbyBody deserializedBody = JsonConvert.DeserializeObject<KillLobbyBody>(requestBody);

        if (await Program.g_LobbyManager.DestroyLobby(deserializedBody.lobby_id))
        {
            return JsonConvert.SerializeObject("LobbyDestroyed");
        }

        return JsonConvert.SerializeObject("InvalidLobby");
    }

    public override int NumExpectedParameters() { return 0; }
}