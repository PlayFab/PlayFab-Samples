// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Threading.Tasks;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;
using PlayFab.TicTacToeDemo.Models;
using System.Net.Http;
using PlayFab.Plugins.CloudScript;
using PlayFab.TicTacToeDemo.Util;

namespace PlayFab.TicTacToeDemo.Functions
{
    public static class WinChecker
    {
        [FunctionName("WinCheck")]
        public static async Task<WinCheckResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage entityRequest, HttpRequest httpRequest,
            ILogger log)
        {
            // Extract the context from the incoming request
            var context = await FunctionContext<PlayFabIdRequest>.Create(entityRequest);

            string playFabId = context.FunctionArgument.PlayFabId;

            Settings.TrySetSecretKey(context.ApiSettings);
            Settings.TrySetCloudName(context.ApiSettings);

            // Grab the current player's game state
            var state = await GameStateUtil.GetCurrentGameState(playFabId, context.ApiSettings, context.AuthenticationContext);
            
            var winCheckResult = WinCheckUtil.Check(state);

            if (winCheckResult.Winner != GameWinnerType.NONE)
            {
                // Update the leaderboard accordingly
                await LeaderboardUtils.UpdateLeaderboard(playFabId, winCheckResult.Winner);

                // Store the game history
                await GameStateUtil.AddGameStateHistory(state, playFabId, context.ApiSettings, context.AuthenticationContext);

                // Clear the current game state
                await GameStateUtil.UpdateCurrentGameState(new TicTacToeState(), playFabId, context.ApiSettings, context.AuthenticationContext);
            }

            

            return winCheckResult;
        }
    }
}
