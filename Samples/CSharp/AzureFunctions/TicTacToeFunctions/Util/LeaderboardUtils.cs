// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.ServerModels;
using PlayFab.TicTacToeDemo.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PlayFab.TicTacToeDemo.Util
{
    public class LeaderboardUtils
    {
        public static async Task UpdateLeaderboard(string playFabId, OccupantType winner)
        {
            switch (winner)
            {
                case OccupantType.HUMAN:
                    {
                        // Add a win to player's record
                        await UpdateStatValue(playFabId, "wins", 1);
                        break;
                    }
                case OccupantType.AI:
                    {
                        // Add a loss to player's record
                        await UpdateStatValue(playFabId, "losses", 1);
                        break;
                    }
                default:
                    {
                        break;
                    }
            }
        }

        /// <summary>
        /// This method acts as an example on how to make an API call from an Azure Function back to PlayFab.
        /// While it is okay to use non-instance API in a game environment, it is critical to use the InstanceAPIs when
        /// making PlayFab API calls from an Azure Function as runtime may be shared among several of your functions, if not all,
        /// and using the static API methods can result in various static fields overriding each other when functions are
        /// called concurrently.
        /// </summary>
        /// <param name="playFabId"></param>
        /// <param name="statName"></param>
        /// <param name="deltaValue"></param>
        /// <returns></returns>
        public static async Task UpdateStatValue(string playFabId, string statName, int deltaValue)
        {
            // Create an API settings object with the authentication credentials
            var apiSettings = new PlayFabApiSettings
            {
                TitleId = Environment.GetEnvironmentVariable(Constants.PLAYFAB_TITLE_ID, EnvironmentVariableTarget.Process),
                VerticalName = Environment.GetEnvironmentVariable(Constants.PLAYFAB_CLOUD_NAME, EnvironmentVariableTarget.Process),
                DeveloperSecretKey = Environment.GetEnvironmentVariable(Constants.PLAYFAB_DEV_SECRET_KEY, EnvironmentVariableTarget.Process)
            };

            // Instantiate a server api client using the settings
            var serverApi = new PlayFabServerInstanceAPI(apiSettings);

            // Grab the previous value of the player's stat
            var currentStatResult = await serverApi.GetPlayerStatisticsAsync(
                new GetPlayerStatisticsRequest
                {
                    PlayFabId = playFabId
                });

            // Apply the delta on the stat
            int oldValue = 0;
            // Try catch in case the stat was not found then assign it to the player
            try
            {
                oldValue = currentStatResult.Result.Statistics.First(stat => stat.StatisticName.Equals(statName)).Value;
            }
            catch (InvalidOperationException) {} // Do not handle stat not found for player, simply create it with update.

            var newValue = oldValue + deltaValue;

            // Update the player's stat with the new value
            var updateStatResult = await serverApi.UpdatePlayerStatisticsAsync(
            new UpdatePlayerStatisticsRequest
            {
                Statistics = new List<StatisticUpdate>
                {
                    new StatisticUpdate
                    {
                        StatisticName = statName,
                        Value = newValue
                    }
                },
                PlayFabId = playFabId
            });
        }
    }
}
