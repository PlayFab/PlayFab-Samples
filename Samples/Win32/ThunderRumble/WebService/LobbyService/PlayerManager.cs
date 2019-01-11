using System.Collections.Generic;

class PlayerManager
{
    private Dictionary<string, Player> m_Players = new Dictionary<string, Player>();

    public Dictionary<string, Player>.ValueCollection GetAllPlayers()
    {
        return m_Players.Values;
    }

    public Player RegisterPlayer(string sessionTicket, string username, string displayname, int version)
    {
        Player newPlayer = new Player(sessionTicket, username, displayname, version);
        m_Players[newPlayer.SessionID] = newPlayer;
        return newPlayer;
    }

    public Player GetPlayerFromSession(string sessionID)
    {
        if (m_Players.ContainsKey(sessionID))
        {
            return m_Players[sessionID];
        }

        return null;
    }

    public bool DestroyPlayerFromSession(string sessionID)
    {
        Player targetPlayer = GetPlayerFromSession(sessionID);
        if (targetPlayer != null)
        {
            targetPlayer.CurrentLobby.RemovePlayer(targetPlayer);
            m_Players.Remove(sessionID);
            return true;
        }

        return false;
    }
}