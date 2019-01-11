using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Net;
using System.Threading.Tasks;

class Handler_ParamsTest : BaseHandler
{
    public Handler_ParamsTest() : base(EndpointSecurityType.None) { }
    public override Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters)
    {
        return Task.FromResult(JsonConvert.SerializeObject(parameters));
    }

    public override Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody)
    {
        JObject deserializedBody = JsonConvert.DeserializeObject<JObject>(requestBody);
        return Task.FromResult(JsonConvert.SerializeObject(deserializedBody));
    }

    public override int NumExpectedParameters() { return -1; } // -1 = Don't care how many params
}