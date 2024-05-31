// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.ServerModels;

namespace PlayFab.TicTacToeDemo.Util
{
    public static class GameDataUtil
    {
        public static async Task<int> GetGamesPlayed(string playFabId, PlayFabApiSettings apiSettings)
        {
            GetUserDataRequest request = new() {
                                                   PlayFabId = playFabId,
                                                   Keys = new List<string> { Constants.GAMES_PLAYED_KEY }
                                               };

            PlayFabServerInstanceAPI serverApi = new(apiSettings);

            PlayFabResult<GetUserDataResult>? result = await serverApi.GetUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while fetching the number of games played: Error: {result.Error.GenerateErrorReport()}");
            }

            Dictionary<string, UserDataRecord>? resultData = result.Result.Data;

            if (resultData.Count > 0 && resultData.TryGetValue(Constants.GAMES_PLAYED_KEY, out UserDataRecord? gamesPlayedRecord))
            {
                return int.Parse(gamesPlayedRecord.Value);
            }

            // Set the number of games played to be 0 since the record doesn't exist
            await SetGamesPlayed(0, playFabId, apiSettings);
            return 0;
        }

        public static async Task SetGamesPlayed(int gamesPlayed, string playFabId, PlayFabApiSettings apiSettings)
        {
            UpdateUserDataRequest request = new() {
                                                      PlayFabId = playFabId,
                                                      Data = new Dictionary<string, string> { { Constants.GAMES_PLAYED_KEY, gamesPlayed.ToString() } }
                                                  };

            PlayFabServerInstanceAPI serverApi = new(apiSettings);

            PlayFabResult<UpdateUserDataResult>? result = await serverApi.UpdateUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while updating the number of games played: Error: {result.Error.GenerateErrorReport()}");
            }
        }
    }
}
