using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Net;
using System.Threading.Tasks;

class Handler_Timestamp : BaseHandler
{
    public Handler_Timestamp() : base(EndpointSecurityType.None) { }

    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        JObject retVal = new JObject();
        retVal["timestamp"] = (Int32)(DateTime.UtcNow.Subtract(new DateTime(1970, 1, 1))).TotalSeconds;
        return Task.FromResult(JsonConvert.SerializeObject(retVal));
    }

    public override Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        return Task.FromResult(String.Empty);
    }

    public override int NumExpectedParameters() { return 0; }
}