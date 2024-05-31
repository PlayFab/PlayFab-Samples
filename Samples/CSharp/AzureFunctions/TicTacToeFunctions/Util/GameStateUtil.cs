// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.Json;
using PlayFab.ServerModels;
using PlayFab.TicTacToeDemo.Models;

namespace PlayFab.TicTacToeDemo.Util
{
    public static class GameStateUtil
    {
        public static async Task<TicTacToeState> GetCurrentGameState(string playFabId, PlayFabApiSettings apiSettings)
        {
            GetUserDataRequest request = new()
                                         {
                                             PlayFabId = playFabId,
                                             Keys = new List<string>() { Constants.GAME_CURRENT_STATE_KEY }
                                         };

            PlayFabServerInstanceAPI serverApi = new(apiSettings);

            PlayFabResult<GetUserDataResult>? result = await serverApi.GetUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occurred while fetching the current game state: Error: {result.Error.GenerateErrorReport()}");
            }

            Dictionary<string, UserDataRecord>? resultData = result.Result.Data;

            // Current state found
            if (resultData.Count > 0 && resultData.TryGetValue(Constants.GAME_CURRENT_STATE_KEY, out UserDataRecord? currentGameStateRecord))
            {
                return PlayFabSimpleJson.DeserializeObject<TicTacToeState>(currentGameStateRecord.Value);
            }
            // Current game record does not exist and so must be created
            else
            {
                TicTacToeState newState = new() { Data = new int[9] };
                await UpdateCurrentGameState(newState, playFabId, apiSettings);
                return newState;
            }
        }

        public static async Task UpdateCurrentGameState(TicTacToeState state, string entityId, PlayFabApiSettings apiSettings)
        {
            string? serializedNewGameState = PlayFabSimpleJson.SerializeObject(state);

            UpdateUserDataRequest request = new()
                                            {
                                                PlayFabId = entityId,
                                                Data = new Dictionary<string, string>() { { Constants.GAME_CURRENT_STATE_KEY,  serializedNewGameState} }
                                            };

            PlayFabServerInstanceAPI serverApi = new(apiSettings);

            PlayFabResult<UpdateUserDataResult>? result = await serverApi.UpdateUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while creating a new game state: {result.Error.GenerateErrorReport()}");
            }
        }

        public static async Task AddGameStateHistory(TicTacToeState gameState, string playFabId, PlayFabApiSettings apiSettings)
        {
            int gamesPlayed = await GameDataUtil.GetGamesPlayed(playFabId, apiSettings);

            string key = $"{Constants.GAME_STATE_KEY}_{gamesPlayed + 1}";

            string? serializedGameState = PlayFabSimpleJson.SerializeObject(gameState);

            UpdateUserDataRequest request = new()
                                            {
                                                PlayFabId = playFabId,
                                                Data = new Dictionary<string, string>() { { key, serializedGameState } }
                                            };

            PlayFabServerInstanceAPI serverApi = new(apiSettings);

            PlayFabResult<UpdateUserDataResult>? result = await serverApi.UpdateUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while updating the game state: Error: {result.Error.GenerateErrorReport()}");
            }

            await GameDataUtil.SetGamesPlayed(gamesPlayed + 1, playFabId, apiSettings);
        }
    }
}
