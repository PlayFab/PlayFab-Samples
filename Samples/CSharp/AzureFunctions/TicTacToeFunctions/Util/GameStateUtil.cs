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
            var request = new GetUserDataRequest()
            {
                PlayFabId = playFabId,
                Keys = new List<string>() { Constants.GAME_CURRENT_STATE_KEY }
            };

            var serverApi = new PlayFabServerInstanceAPI(apiSettings);

            var result = await serverApi.GetUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occurred while fetching the current game state: Error: {result.Error.GenerateErrorReport()}");
            }

            var resultData = result.Result.Data;

            // Current state found
            if (resultData.Count > 0 && resultData.TryGetValue(Constants.GAME_CURRENT_STATE_KEY, out UserDataRecord? currentGameStateRecord))
            {
                return PlayFabSimpleJson.DeserializeObject<TicTacToeState>(currentGameStateRecord.Value);
            }
            // Current game record does not exist and so must be created
            else
            {
                var newState = new TicTacToeState { Data = new int[9] };
                await UpdateCurrentGameState(newState, playFabId, apiSettings);
                return newState;
            }
        }

        public static async Task UpdateCurrentGameState(TicTacToeState state, string entityId, PlayFabApiSettings apiSettings)
        {
            var serializedNewGameState = PlayFabSimpleJson.SerializeObject(state);

            var request = new UpdateUserDataRequest()
            {
                PlayFabId = entityId,
                Data = new Dictionary<string, string>() { { Constants.GAME_CURRENT_STATE_KEY, serializedNewGameState } }
            };

            var serverApi = new PlayFabServerInstanceAPI(apiSettings);

            var result = await serverApi.UpdateUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while creating a new game state: {result.Error.GenerateErrorReport()}");
            }
        }

        public static async Task AddGameStateHistory(TicTacToeState gameState, string playFabId, PlayFabApiSettings apiSettings)
        {
            var gamesPlayed = await GameDataUtil.GetGamesPlayed(playFabId, apiSettings);

            var key = $"{Constants.GAME_STATE_KEY}_{gamesPlayed + 1}";

            var serializedGameState = PlayFabSimpleJson.SerializeObject(gameState);

            var request = new UpdateUserDataRequest()
            {
                PlayFabId = playFabId,
                Data = new Dictionary<string, string>() { { key, serializedGameState } }
            };

            var serverApi = new PlayFabServerInstanceAPI(apiSettings);

            var result = await serverApi.UpdateUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while updating the game state: Error: {result.Error.GenerateErrorReport()}");
            }

            await GameDataUtil.SetGamesPlayed(gamesPlayed + 1, playFabId, apiSettings);
        }
    }
}
