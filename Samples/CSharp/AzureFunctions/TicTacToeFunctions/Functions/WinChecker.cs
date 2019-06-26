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
            var context = await FunctionContext<WinCheckRequest>.Create(entityRequest);

            // TODO: check if can be done with currentplayerid directly from context
            // Extract the Player's PlayFabId from the request
            string playFabId = context.FunctionArgument.PlayFabId;

            // Determine the winner (if any)
            var winResult = WinCheckUtil.Check(context.FunctionArgument.State);

            // Update the leaderboard accordingly
            await LeaderboardUtils.UpdateLeaderboard(playFabId, winResult.Winner);

            return winResult;

        }
    }
}
