using Newtonsoft.Json;
using PlayFab.MultiplayerModels;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

class Lobby
{
    [JsonProperty]
    public string SessionID { get; set; } = String.Empty;

    [JsonProperty]
    public int VersionNum { get; set; } = -1;

    [JsonProperty]
    public ServerInstance ServerInstance { get; set; } = null;

    [JsonProperty]
    private ELobbyState State = ELobbyState.WaitingForPlayers;

    [JsonIgnore]
    public ELobbyState LobbyState
    {
        get
        {
            return this.State;
        }
        set
        {
            this.State = value;
            LastStateChange = Environment.TickCount;
        }
    }

    [JsonProperty]
    public int TimeSinceLastStateChange
    {
        get
        {
            return Environment.TickCount - LastStateChange;
        }
    }

    [JsonProperty]
    public int TimeUntilMatchStartSeconds
    {
        get
        {
            if (LobbyState == ELobbyState.Countdown)
            {
                return (Math.Max(0, (MatchmakingSettings.timeWhenThresholdMetUntilStartsSeconds * 1000) - (Environment.TickCount - LastStateChange))) / 1000;
            }
            else
            {
                return -1;
            }
        }
    }

    [JsonIgnore]
    public int LastStateChange = 0;

    [JsonProperty]
    public AzureRegion Region { get; set; }

    public enum ELobbyState
    {
        WaitingForPlayers,
        Countdown,
        AllocatingServer,
        WaitingForServer,
        InGame
    }

    public Lobby(string sessionID, int version, AzureRegion region)
    {
        SessionID = sessionID;
        VersionNum = version;
        Region = region;
    }

    public bool IsJoinable()
    {
        return State == ELobbyState.WaitingForPlayers || State == ELobbyState.Countdown;
    }


    public void AddPlayer(Player plr)
    {
        // dedupe name
        int playerDedupeIndex = 0;
        foreach (var member in Members)
        {
            if (member.UserName == plr.UserName)
            {
                ++playerDedupeIndex;
            }
        }

        if (playerDedupeIndex != 0)
        {
            plr.DisplayName += String.Format(" ({0})", playerDedupeIndex);
        }

        plr.ResetPerMatchSettings();


        Members.Add(plr);
    }

    public void RemovePlayer(Player plr)
    {
        plr.DisplayName = plr.UserName;
        Members.Remove(plr);
    }

    public List<Player> Members { get; } = new List<Player>();

    public async Task<string> KillServerInstance()
    {
        if (ServerInstance != null)
        {
            // authenticate
            await PlayFabMultiplayerServerHelper.Singleton.GetTitleEntityToken();
            try
            {
                bool deallocResp = await PlayFabMultiplayerServerHelper.Singleton.ShutdownMultiplayerServer(ServerInstance.BuildId, ServerInstance.Region, SessionID);

                if (deallocResp)
                {
                    ServerInstance = null;
                    return JsonConvert.SerializeObject(this);
                }
                else
                {
                    return JsonConvert.SerializeObject("FailedToDeallocate");
                }
            }
            catch (Exception ex)
            {
                return JsonConvert.SerializeObject(ex);
            }
        }

        return JsonConvert.SerializeObject("LobbyHasNoServerInstance");
    }
}