using Newtonsoft.Json;
using PlayFab.ServerModels;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_RegisterPlayer : BaseHandler
{
    public Handler_RegisterPlayer() : base(EndpointSecurityType.None) { }
    class RegisterPlayerBody : BaseRequestBody
    {
        public string playfab_session = String.Empty;
    }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(String.Empty);
    }

    public async override Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        RegisterPlayerBody deserializedBody = JsonConvert.DeserializeObject<RegisterPlayerBody>(requestBody);

        // Verify auth token
        AuthenticateSessionTicketRequest req = new AuthenticateSessionTicketRequest
        {
            SessionTicket = deserializedBody.playfab_session
        };

        var task = PlayFab.PlayFabServerAPI.AuthenticateSessionTicketAsync(req);
        var resp = await task;

        if (resp.Error == null)
        {
            Player newPlayer = Program.g_PlayerManager.RegisterPlayer(deserializedBody.playfab_session, resp.Result.UserInfo.PlayFabId, resp.Result.UserInfo.CustomIdInfo.CustomId, deserializedBody.version);
            return JsonConvert.SerializeObject(newPlayer);
        }

        Console.WriteLine("RegisterPlayer failed as auth token is invalid");
        return String.Empty;
    }

    public override int NumExpectedParameters() { return 0; }
}