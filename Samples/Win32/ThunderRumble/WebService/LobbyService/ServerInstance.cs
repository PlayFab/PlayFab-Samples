using PlayFab.MultiplayerModels;
using System.Collections.Generic;

class ServerInstance
{
    public ServerInstance(RequestMultiplayerServerResponse resp, string a_BuildID)
    {
        IPV4Address = resp.IPV4Address;
        Ports = resp.Ports;
        Region = resp.Region ?? default(AzureRegion);
        ServerId = resp.ServerId;
        VmId = resp.VmId;
        BuildId = a_BuildID;
    }

    public string IPV4Address { get; }
    public List<Port> Ports { get; }
    public AzureRegion Region { get; }
    public string ServerId { get; }
    public string VmId { get; }
    public string BuildId { get; }
}