// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.ServerModels;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace PlayFab.TicTacToeDemo.Util
{
    public static class GameDataUtil
    {
        public static async Task<int> GetGamesPlayed(string playFabId, PlayFabApiSettings apiSettings, PlayFabAuthenticationContext authenticationContext)
        {
            var request = new GetUserDataRequest
            {
                PlayFabId = playFabId,
                Keys = new List<string> { Constants.GAMES_PLAYED_KEY }
            };

            var serverApi = new PlayFabServerInstanceAPI(apiSettings, authenticationContext);

            var result = await serverApi.GetUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while fetching the number of games played: Error: {result.Error.GenerateErrorReport()}");
            }

            var resultData = result.Result.Data;

            if (resultData.Count > 0 && resultData.TryGetValue(Constants.GAMES_PLAYED_KEY, out var gamesPlayedRecord))
            {
                return int.Parse(gamesPlayedRecord.Value);
            }

            // Set the number of games played to be 0 since the record doesn't exist
            await SetGamesPlayed(0, playFabId, apiSettings, authenticationContext);
            return 0;
        }

        public static async Task SetGamesPlayed(int gamesPlayed, string playFabId, PlayFabApiSettings apiSettings, PlayFabAuthenticationContext authenticationContext)
        {
            var request = new UpdateUserDataRequest
            {
                PlayFabId = playFabId,
                Data = new Dictionary<string, string> { { Constants.GAMES_PLAYED_KEY.ToString(), gamesPlayed.ToString() } }
            };

            var serverApi = new PlayFabServerInstanceAPI(apiSettings, authenticationContext);

            var result = await serverApi.UpdateUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while updating the number of games played: Error: {result.Error.GenerateErrorReport()}");
            }
        }
    }
}
