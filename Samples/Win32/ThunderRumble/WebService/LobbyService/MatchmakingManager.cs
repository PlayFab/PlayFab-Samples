using Newtonsoft.Json;
using PlayFab.MultiplayerModels;
using System.Collections.Generic;
using System.Threading.Tasks;

static class MatchmakingSettings
{
    public const int numPlayersRequiredToStart = 2;
    public const int numPlayersRequiredToFormLobby = 2;
    public const int maxPlayers = 4;
    public const int timeWhenThresholdMetUntilStartsSeconds = 30;
}

struct SessionCookie
{
    public string lobbyID;
}

class MatchmakingManager
{
    public static async Task Update()
    {
        Dictionary<AzureRegion, List<List<Player>>> buckets = new Dictionary<AzureRegion, List<List<Player>>>();

        // are any players waiting for a lobby?
        foreach (var plr in Program.g_PlayerManager.GetAllPlayers())
        {
            if (plr.PlayerState == EPlayerState.Matchmaking)
            {
                // Do we have a suitable existing lobby for this person?
                bool bFoundSuitableLobby = false;
                foreach (var kvPair in Program.g_LobbyManager.Lobbies)
                {
                    Lobby existingLobby = kvPair.Value;
                    if (existingLobby.IsJoinable())
                    {
                        // does the region and version match?
                        if (existingLobby.VersionNum == plr.VersionNum && existingLobby.Region == plr.MatchmakingRegion)
                        {
                            var members = existingLobby.Members;
                            if (members.Count < MatchmakingSettings.maxPlayers)
                            {
                                plr.CurrentLobby = existingLobby;
                                existingLobby.AddPlayer(plr);
                                plr.PlayerState = EPlayerState.InLobby;
                                bFoundSuitableLobby = true;

                            }
                        }
                    }
                }

                if (!bFoundSuitableLobby)
                {
                    // if no lobby, find a suitable bucket
                    if (!buckets.ContainsKey(plr.MatchmakingRegion)) // no buckets for this region
                    {
                        List<Player> lstNewBucket = new List<Player>() { plr };
                        buckets[plr.MatchmakingRegion] = new List<List<Player>>() { lstNewBucket };
                    }
                    else
                    {
                        // find a suitable bucket within this region
                        bool bFoundValidBucket = false;
                        foreach (List<Player> matchmakingBucket in buckets[plr.MatchmakingRegion])
                        {
                            // found a non-full bucket, put player in here
                            if (matchmakingBucket.Count < MatchmakingSettings.maxPlayers)
                            {
                                matchmakingBucket.Add(plr);
                                bFoundValidBucket = true;
                                break;
                            }
                        }

                        if (!bFoundValidBucket)
                        {
                            List<Player> lstNewBucket = new List<Player>() { plr };
                            buckets[plr.MatchmakingRegion] = new List<List<Player>>() { lstNewBucket };
                        }
                    }
                }
            }
        }

        // Form lobbies from matchmaking buckets
        foreach (var kvPair in buckets)
        {
            foreach (List<Player> matchmakingBucket in kvPair.Value)
            {
                if (matchmakingBucket.Count >= MatchmakingSettings.numPlayersRequiredToFormLobby)
                {
                    // Make a new lobby and put all the players in it
                    Lobby newLobby = Program.g_LobbyManager.CreateLobby(matchmakingBucket[0].VersionNum, kvPair.Key);

                    foreach (Player bucketPlayer in matchmakingBucket)
                    {
                        bucketPlayer.CurrentLobby = newLobby;
                        newLobby.AddPlayer(bucketPlayer);
                        bucketPlayer.PlayerState = EPlayerState.InLobby;
                    }
                }
            }
        }

        // process existing lobby states (e.g. allocate server)
        foreach (var kvPair in Program.g_LobbyManager.Lobbies)
        {
            Lobby currentLobby = kvPair.Value;
            if (currentLobby.LobbyState == Lobby.ELobbyState.WaitingForPlayers)
            {
                var members = currentLobby.Members;

                if (members.Count >= MatchmakingSettings.numPlayersRequiredToStart && currentLobby.ServerInstance == null)
                {
                    currentLobby.LobbyState = Lobby.ELobbyState.Countdown;
                }
            }
            else if (currentLobby.LobbyState == Lobby.ELobbyState.AllocatingServer)
            {
                // We roll this back later on if something goes sideways
                currentLobby.LobbyState = Lobby.ELobbyState.WaitingForServer;

                try
                {
                    bool bHasAllocatedDevServer = false;
                    // Only request a server if the development server list is empty
                    await Program.g_DevelopmentServersMutex.WaitAsync().ConfigureAwait(false);
                    if (Program.g_lstDevelopmentServers.Count > 0)
                    {
                        // Try to pull a dev server
                        DevelopmentServer serverToUse = null;
                        foreach (DevelopmentServer devServer in Program.g_lstDevelopmentServers)
                        {
                            if (!devServer.IsAllocated)
                            {
                                devServer.IsAllocated = true;

                                SessionCookie cookie;
                                cookie.lobbyID = currentLobby.SessionID;
                                devServer.SessionCookie = JsonConvert.SerializeObject(cookie);

                                serverToUse = devServer;
                                bHasAllocatedDevServer = true;
                                break;
                            }
                        }

                        if (bHasAllocatedDevServer)
                        {
                            RequestMultiplayerServerResponse dummyResp = new RequestMultiplayerServerResponse
                            {
                                ConnectedPlayers = new List<ConnectedPlayer>(),
                                IPV4Address = serverToUse.ipAddr,
                                Ports = new List<Port>() { new Port { Name = "Game", Num = serverToUse.port, Protocol = ProtocolType.UDP } },
                                Region = currentLobby.Region,
                                ServerId = "Localhost Development Server",
                                SessionId = currentLobby.SessionID,
                                VmId = "Development Server"
                            };
                            currentLobby.ServerInstance = new ServerInstance(dummyResp, "Local Build");

                            // Normally we would set this in the async callback saying we got a server successfully, but for dev servers that won't happen so set here
                            currentLobby.LobbyState = Lobby.ELobbyState.InGame;
                        }
                    }

                    if (!bHasAllocatedDevServer) // Allocate a real server
                    {
                        await PlayFabMultiplayerServerHelper.Singleton.GetTitleEntityToken().ConfigureAwait(false);
                        var buildTask = await PlayFab.PlayFabMultiplayerAPI.ListBuildSummariesAsync(null).ConfigureAwait(false);

                        // Find a suitable build
                        PlayFab.MultiplayerModels.BuildSummary buildToUse = null;
                        foreach (var buildSummary in buildTask.Result.BuildSummaries)
                        {
                            // Does this build have the required metadata to determine suitability?
                            if (buildSummary.Metadata.ContainsKey("MajorVersion") && buildSummary.Metadata.ContainsKey("MinorVersion"))
                            {
                                // Does major version match lobby?
                                int majorVersion = int.Parse(buildSummary.Metadata["MajorVersion"]);
                                if (majorVersion == currentLobby.VersionNum)
                                {
                                    // Is this our first server of this version or a higher minor version?
                                    int minorVersion = int.Parse(buildSummary.Metadata["MinorVersion"]);
                                    if (buildToUse == null || (minorVersion > int.Parse(buildToUse.Metadata["MinorVersion"])))
                                    {
                                        buildToUse = buildSummary;
                                    }
                                }
                            }
                        }

                        // Did we find a server to use?
                        if (buildToUse != null)
                        {
                            // Actually request a server
                            // NOTE: This call can be made multiple times by multiple users. Since the lobby ID is consistent, the same server instance will be returned each time
                            try
                            {
                                var allocResp = await PlayFabMultiplayerServerHelper.Singleton.RequestMultiplayerServer(buildToUse.BuildId, new List<PlayFab.MultiplayerModels.AzureRegion> { currentLobby.Region }, "", currentLobby.SessionID).ConfigureAwait(false);
                                if (allocResp != null)
                                {
                                    currentLobby.ServerInstance = new ServerInstance(allocResp, buildToUse.BuildId);
                                    currentLobby.LobbyState = Lobby.ELobbyState.InGame;
                                }
                                else
                                {
                                    // Go back to the previous stage and keep trying
                                    currentLobby.LobbyState = Lobby.ELobbyState.WaitingForPlayers;
                                }
                            }
                            catch
                            {
                                // Go back to the previous stage and keep trying
                                currentLobby.LobbyState = Lobby.ELobbyState.WaitingForPlayers;
                            }
                        }
                        else
                        {
                            // Go back to the previous stage and keep trying
                            currentLobby.LobbyState = Lobby.ELobbyState.WaitingForPlayers;
                        }
                    }
                }
                finally
                {
                    Program.g_DevelopmentServersMutex.Release();
                }
            }
            else if (currentLobby.LobbyState == Lobby.ELobbyState.WaitingForServer)
            {

            }
            else if (currentLobby.LobbyState == Lobby.ELobbyState.Countdown)
            {
                var members = currentLobby.Members;

                // Do we no longer meet the requirements? roll back state if we are more than 5 seconds out from starting
                // (5 seconds to avoid any potential desync with clients who already started transitioning)
                if (members.Count < MatchmakingSettings.numPlayersRequiredToStart && currentLobby.TimeUntilMatchStartSeconds > 5)
                {
                    currentLobby.LobbyState = Lobby.ELobbyState.WaitingForPlayers;
                }

                bool bIsEveryoneReady = (members.Count >= MatchmakingSettings.numPlayersRequiredToStart);
                foreach (var member in members)
                {
                    bIsEveryoneReady &= member.IsReady;
                }

                // have we reached the time limit? or obtained a full lobby? or we have enough players and everyone is ready?
                if (currentLobby.TimeUntilMatchStartSeconds == 0 || members.Count == MatchmakingSettings.maxPlayers + 1 || bIsEveryoneReady)
                {
                    // set everyone to ready, client picks this up automatically
                    foreach (var member in members)
                    {
                        member.IsReady = true;
                    }

                    // Allocate server
                    currentLobby.LobbyState = Lobby.ELobbyState.AllocatingServer;
                }
            }
        }
    }
}