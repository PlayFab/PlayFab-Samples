// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Threading.Tasks;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.Extensions.Logging;
using System.Net.Http;
using PlayFab.TicTacToeDemo.Util;
using PlayFab.Plugins.CloudScript;
using PlayFab.TicTacToeDemo.Models;

namespace TicTacToeFunctions.Functions
{
    public static class ResetGameState
    {
        [FunctionName("ResetGameState")]
        public static async Task Run(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req,
            ILogger log)
        {
            var context = await FunctionContext<PlayFabIdRequest>.Create(req);
            var playFabId = context.FunctionArgument.PlayFabId;

            Settings.TrySetSecretKey(context.ApiSettings);
            Settings.TrySetCloudName(context.ApiSettings);

            var newCurrentGameState = new TicTacToeState()
            {
                Data = new int[9]
            };

            await GameStateUtil.UpdateCurrentGameState(
                newCurrentGameState,
                playFabId,
                context.ApiSettings,
                context.AuthenticationContext);

        }
    }
}
