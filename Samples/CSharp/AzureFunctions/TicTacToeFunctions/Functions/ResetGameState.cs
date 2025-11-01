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
    public class ResetGameState
    {
        [Function("ResetGameState")]
        public async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestData req,
            FunctionContext executionContext)
        {
            var context = await PlayFabFunctionHelper.GetContext(_logger, req);
            if (context is null) return new BadRequestObjectResult("Invalid context");

            var settings = new PlayFabApiSettings { TitleId = context.TitleAuthenticationContext.Id, };
            Settings.TrySetSecretKey(settings);
            Settings.TrySetCloudName(settings);

            string playFabId = context.CallerEntityProfile.Lineage.MasterPlayerAccountId;

            var newCurrentGameState = new TicTacToeState
            {
                Data = new int[9]
            };

            await GameStateUtil.UpdateCurrentGameState(
                newCurrentGameState,
                playFabId,
                settings);

            return new OkResult();
        }

        private readonly ILogger _logger;

        public ResetGameState(ILoggerFactory loggerFactory)
        {
            _logger = loggerFactory.CreateLogger<ResetGameState>();
        }
    }
}
