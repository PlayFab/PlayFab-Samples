using PlayFab.MultiplayerModels;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

class LobbyManager
{
    public Dictionary<string, Lobby> Lobbies { get; } = new Dictionary<string, Lobby>();

    public Lobby RequestLobby(string sessionID, int version, AzureRegion region)
    {
        return InternalCreateLobbyFromSessionID(sessionID, version, region);
    }

    public Lobby CreateLobby(int version, AzureRegion region)
    {
        string sessionID = Guid.NewGuid().ToString();
        Lobby newLobby = InternalCreateLobbyFromSessionID(sessionID, version, region);
        return newLobby;
    }

    private Lobby InternalCreateLobbyFromSessionID(string sessionID, int version, AzureRegion region)
    {
        if (!Lobbies.ContainsKey(sessionID))
        {
            Lobbies[sessionID] = new Lobby(sessionID, version, region);
        }

        return Lobbies[sessionID];
    }
    public Lobby RetrieveLobby(string sessionID)
    {
        if (Lobbies.ContainsKey(sessionID))
        {
            return Lobbies[sessionID];
        }

        return null;
    }

    public async Task<bool> DestroyLobby(string sessionID)
    {
        Lobby targetLobby = RetrieveLobby(sessionID);
        if (targetLobby != null)
        {
            // Kill server, if present
            if (targetLobby.ServerInstance != null)
            {
                await targetLobby.KillServerInstance();
            }

            Lobbies.Remove(sessionID);
            return true;
        }

        return false;
    }
}