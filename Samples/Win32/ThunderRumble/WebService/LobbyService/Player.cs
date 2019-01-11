using Newtonsoft.Json;
using PlayFab.MultiplayerModels;
using System;

enum EPlayerState
{
    Idle,
    Matchmaking,
    InLobby,
    InGame
}
class Player
{
    [JsonProperty]
    public string UserName { get; set; } = String.Empty;

    [JsonProperty]
    public string DisplayName { get; set; } = String.Empty;

    [JsonIgnore]
    public string SessionTicket { get; set; } = String.Empty;

    [JsonProperty]
    public int VersionNum { get; set; } = -1;

    [JsonProperty]
    public int ShipColor { get; set; } = 0;

    [JsonProperty]
    public int ShipVariant { get; set; } = 0;

    [JsonProperty]
    public bool IsReady { get; set; } = false;

    public void ResetPerMatchSettings()
    {
        ShipColor = 0;
        ShipVariant = 0;
        IsReady = false;
    }

    [JsonProperty]
    public EPlayerState PlayerState { get; set; } = EPlayerState.Idle;

    [JsonProperty]
    public string SessionID { get; set; } = String.Empty; // NOTE: In the real world, you should expire sessions

    [JsonIgnore]
    public Lobby CurrentLobby { get; set; } = null;

    public bool IsInLobby() { return CurrentLobby != null; }

    [JsonIgnore]
    public AzureRegion MatchmakingRegion { get; set; } = AzureRegion.EastUs;

    public Player(string sessionticket, string username, string displayname, int version)
    {
        SessionTicket = sessionticket;
        SessionID = Guid.NewGuid().ToString();
        UserName = username;
        DisplayName = displayname;
        VersionNum = version;
    }

    public void StartMatchmaking(AzureRegion region)
    {
        PlayerState = EPlayerState.Matchmaking;
        MatchmakingRegion = region;
    }
}