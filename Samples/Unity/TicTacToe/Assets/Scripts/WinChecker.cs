// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab;
using PlayFab.ClientModels;
using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public static class WinChecker
{
    public static WinCheckResult Check(TicTacToeState state)
    {
        int[,] state2D = Util.Make2DArray(state.Data, 3, 3);
        // For all but NONE occupant types, check to see if there is a winner in the game at the moment
        foreach (var occupantType in (OccupantType[]) Enum.GetValues(typeof(OccupantType)))
        {
            if (occupantType == OccupantType.NONE)
                continue;

            if(CheckRowWin(occupantType, state2D) 
                || CheckColWin(occupantType, state2D) 
                || CheckDiagWin(occupantType, state2D))
            {
                return new WinCheckResult(){ winner = occupantType };
            }
        }
        return new WinCheckResult(){ winner = (int) OccupantType.NONE };
    }

    private static bool CheckRowWin(OccupantType occupantType, int[,] state)
    {
        // Given an occupant type, check all rows to see if that occupant type has won any row
        for (int i = 0; i < 3; i++)
        {
            if (state[i, 0] == (int) occupantType 
                && state[i, 1] == (int) occupantType
                && state[i, 2] == (int) occupantType)
                return true;
        }
        return false;
    }

    private static bool CheckColWin(OccupantType occupantType, int[,] state)
    {
        // Given an occupant type, check all column to see if that occupant type has won any column
        for (int i = 0; i < 3; i++)
        {
            if (state[0, i] == (int) occupantType
                && state[1, i] == (int) occupantType
                && state[2, i] == (int) occupantType)
                return true;
        }
        return false;
    }

    private static bool CheckDiagWin(OccupantType occupantType, int[,] state)
    {
        // Given an occupant type, check both diagonals  to see if that occupant type has won any diagonal
        if (state[0, 0] == (int) occupantType
            && state[1, 1] == (int) occupantType
            && state[2, 2] == (int) occupantType)
            return true;
        if (state[2, 0] == (int) occupantType
            && state[1, 1] == (int) occupantType
            && state[0, 2] ==  (int) occupantType)
            return true;
        return false;
    }

    public static void UpdateStatValue(string sessionTicket, string statName, int deltaValue)
    {
        // Grab the previous value of the player's stat
        PlayFabClientAPI.GetPlayerStatistics(
            new GetPlayerStatisticsRequest
            {
                StatisticNames = new List<string> {statName}
            },
            (statFetchResult) => {

                var oldValue = 0;
                uint version = 0;

                // Find the matching stat
                try 
                {
                    var statistic = statFetchResult.Statistics.First(stat => stat.StatisticName.Equals(statName));
                    oldValue = statistic.Value;
                    version = statistic.Version;
                } 
                catch (InvalidOperationException) { }

                // Apply the delta on the stat
                var newValue = oldValue + deltaValue;

                // Update the stat with the new value
                PlayFabClientAPI.UpdatePlayerStatistics(
                    new UpdatePlayerStatisticsRequest
                    {
                        Statistics = new List<StatisticUpdate>
                        {
                            new StatisticUpdate
                            {
                                StatisticName = statName,
                                Value = newValue,
                                Version = version
                            }
                        }
                    },
                    (statUpdateResult) => 
                    {
                        Debug.Log($"Stat {statName} old value: {oldValue}");
                        Debug.Log($"Stat {statName} new value: {newValue}");
                    },
                    (statUpdateError) => 
                    {
                        Util.DisplayHttpError(statUpdateError);
                    });
            }, 
            (statFetchError) => {
                Util.DisplayHttpError(statFetchError);
            });
    }
}
