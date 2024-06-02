// Copyright (C) Microsoft Corporation. All rights reserved.

using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.Functions.Worker;
using Microsoft.Azure.Functions.Worker.Http;
using Microsoft.Extensions.Logging;
using PlayFab;
using PlayFab.TicTacToeDemo.Models;
using PlayFab.TicTacToeDemo.Util;

namespace TicTacToeFunctions.Functions
{
    public class WinChecker
    {
        [Function("WinCheck")]
        public async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)]HttpRequestData req,
            FunctionContext executionContext)
        {
            var context = await PlayFabFunctionHelper.GetContext(_logger, req);
            if (context is null) return new BadRequestObjectResult("Invalid context");

            // TODO: check if can be done with currentplayerid directly from context
            // Extract the Player's PlayFabId from the request
            string playFabId = context.FunctionArgument.ToObject<PlayFabIdRequest>().PlayFabId;
            
            // Grab the current player's game state
            PlayFabApiSettings settings = new() { TitleId = context.TitleAuthenticationContext.Id, };
            Settings.TrySetSecretKey(settings);
            Settings.TrySetCloudName(settings);
            
            var state = await GameStateUtil.GetCurrentGameState(playFabId, settings);
            
            // Determine the winner (if any)
            var winResult = WinCheckUtil.Check(state);

            // Update the leaderboard accordingly
            await LeaderboardUtils.UpdateLeaderboard(playFabId, winResult.Winner);
            
            return new OkObjectResult(winResult);
        }

        private readonly ILogger _logger;

        public WinChecker(ILoggerFactory loggerFactory)
        {
            _logger = loggerFactory.CreateLogger<WinChecker>();
        }
    }
}
