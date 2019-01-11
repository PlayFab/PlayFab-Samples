using System.Net;
using System.Threading.Tasks;

public enum EndpointSecurityType
{
    None,
    RequiresUserSession
}

abstract class BaseHandler
{
    public BaseHandler(EndpointSecurityType endpointSecurity)
    {
        EndpointSecurity = endpointSecurity;
    }

    public EndpointSecurityType EndpointSecurity { get; private set; }

    public abstract Task<string> ProcessRequest_Get(Player requestingPlayer, HttpListenerRequest request, string[] parameters);
    public abstract Task<string> ProcessRequest_Put(Player requestingPlayer, HttpListenerRequest request, string[] parameters, string requestBody);
    public abstract int NumExpectedParameters();
}

class BaseRequestBody
{
    public int version = -1;
}