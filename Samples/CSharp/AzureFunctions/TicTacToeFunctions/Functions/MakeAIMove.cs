// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Threading.Tasks;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.Extensions.Logging;
using PlayFab.TicTacToeDemo.Models;
using System.Net.Http;
using PlayFab.Plugins.CloudScript;
using PlayFab.TicTacToeDemo.Util;

namespace TicTacToeFunctions.Functions
{
    public static class MakeAIMove
    {
        [FunctionName("MakeRandomAIMove")]
        public static async Task<TicTacToeMove> MakeRandomAIMove(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req,
            ILogger log)
        {
            var context = await FunctionContext<PlayFabIdRequest>.Create(req);

            Settings.TrySetSecretKey(context.ApiSettings);
            Settings.TrySetCloudName(context.ApiSettings);

            var playFabId = context.FunctionArgument.PlayFabId;

            // Attempt to load the player's game state
            var state = await GameStateUtil.GetCurrentGameState(playFabId, context.ApiSettings, context.AuthenticationContext);

            // Look for a random AI move to make
            var aiMove = TicTacToeAI.GetNextRandomMove(state);

            // Store the AI move on the current game state
            var oneDimMoveIndex = aiMove.row * 3 + aiMove.col;
            state.Data[oneDimMoveIndex] = (int) OccupantType.AI;
            await GameStateUtil.UpdateCurrentGameState(state, playFabId, context.ApiSettings, context.AuthenticationContext);
            
            // Respond with the AI move
            return aiMove;
        }

        [FunctionName("MakeMinimaxAIMove")]
        public static async Task<TicTacToeMove> MakeMinimaxAIMove(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req,
            ILogger log)
        {
            var context = await FunctionContext<PlayFabIdRequest>.Create(req);

            Settings.TrySetSecretKey(context.ApiSettings);
            Settings.TrySetCloudName(context.ApiSettings);

            var playFabId = context.FunctionArgument.PlayFabId;

            // Attempt to load the Player's game state
            var state = await GameStateUtil.GetCurrentGameState(playFabId, context.ApiSettings, context.AuthenticationContext);

            // Look for a minimax AI move to make
            var aiMove = TicTacToeAI.GetNextMinimaxMove(state);

            // Store the AI move on the current game state
            var oneDimMoveIndex = aiMove.row * 3 + aiMove.col;
            state.Data[oneDimMoveIndex] = (int) OccupantType.AI;
            await GameStateUtil.UpdateCurrentGameState(state, playFabId, context.ApiSettings, context.AuthenticationContext);

            // Respond with the AI move
            return aiMove;
        }
    }
}
