// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.Json;
using PlayFab.ServerModels;
using PlayFab.TicTacToeDemo.Models;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace PlayFab.TicTacToeDemo.Util
{
    public static class GameStateUtil
    {
        public static async Task<TicTacToeState> GetCurrentGameState(string playFabId, PlayFabApiSettings apiSettings, PlayFabAuthenticationContext authenticationContext)
        {
            var request = new GetUserDataRequest()
            {
                PlayFabId = playFabId,
                Keys = new List<string>() { Constants.GAME_CURRENT_STATE_KEY }
            };

            var serverApi = new PlayFabServerInstanceAPI(apiSettings, authenticationContext);

            var result = await serverApi.GetUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occurred while fetching the current game state: Error: {result.Error.GenerateErrorReport()}");
            }

            var resultData = result.Result.Data;

            // Current state found
            if (resultData.Count > 0 && resultData.TryGetValue(Constants.GAME_CURRENT_STATE_KEY, out var currentGameStateRecord))
            {
                return PlayFabSimpleJson.DeserializeObject<TicTacToeState>(currentGameStateRecord.Value);
            }
            // Current game record does not exist and so must be created
            else
            {
                var newState = new TicTacToeState() { Data = new int[9] };
                await UpdateCurrentGameState(newState, playFabId, apiSettings, authenticationContext);
                return newState;
            }
        }

        public static async Task UpdateCurrentGameState(TicTacToeState state, string playFabId, PlayFabApiSettings apiSettings, PlayFabAuthenticationContext authenticationContext)
        {
            var serializedNewGameState = PlayFabSimpleJson.SerializeObject(state);

            var request = new UpdateUserDataRequest()
            {
                PlayFabId = playFabId,
                Data = new Dictionary<string, string>() { { Constants.GAME_CURRENT_STATE_KEY,  serializedNewGameState} }
            };

            var serverApi = new PlayFabServerInstanceAPI(apiSettings, authenticationContext);

            var result = await serverApi.UpdateUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while creating a new game state: {result.Error.GenerateErrorReport()}");
            }
        }

        public static async Task AddGameStateHistory(TicTacToeState gameState, string playFabId, PlayFabApiSettings apiSettings, PlayFabAuthenticationContext authenticationContext)
        {
            var gamesPlayed = await GameDataUtil.GetGamesPlayed(playFabId, apiSettings, authenticationContext);

            var key = $"{Constants.GAME_STATE_KEY}_{gamesPlayed + 1}";

            var serializedGameState = PlayFabSimpleJson.SerializeObject(gameState);

            var request = new UpdateUserDataRequest()
            {
                PlayFabId = playFabId,
                Data = new Dictionary<string, string>() { { key, serializedGameState } }
            };

            var serverApi = new PlayFabServerInstanceAPI(apiSettings, authenticationContext);

            var result = await serverApi.UpdateUserDataAsync(request);

            if (result.Error != null)
            {
                throw new Exception($"An error occured while updating the game state: Error: {result.Error.GenerateErrorReport()}");
            }

            await GameDataUtil.SetGamesPlayed(gamesPlayed + 1, playFabId, apiSettings, authenticationContext);
        }
    }
}
