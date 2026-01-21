// Copyright (C) Microsoft Corporation. All rights reserved.

using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.Functions.Worker;
using Microsoft.Azure.Functions.Worker.Http;
using Microsoft.Extensions.Logging;
using PlayFab.TicTacToeDemo.Models;
using PlayFab.TicTacToeDemo.Util;

namespace PlayFab.TicTacToeDemo.Functions
{
    public class MakePlayerMove(ILoggerFactory loggerFactory)
    {
        [Function("MakePlayerMove")]
        public async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestData req,
            FunctionContext executionContext)
        {
            var context = await PlayFabFunctionHelper.GetContext(_logger, req);
            if (context is null) return new BadRequestObjectResult("Invalid context"); 

            var settings = new PlayFabApiSettings { TitleId = context.TitleAuthenticationContext.Id, };
            Settings.TrySetSecretKey(settings);
            Settings.TrySetCloudName(settings);

            var moveRequest = context.FunctionArgument.ToObject<MakePlayerMoveRequest>();

            // Attempt to load the player's game state
            var state = await GameStateUtil.GetCurrentGameState(moveRequest.PlayFabId, settings);
            var move = moveRequest.Move;

            int oneDimMoveIndex = move.row * 3 + move.col;

            // Move can only be made if spot was empty
            if (state.Data[oneDimMoveIndex] == (int) OccupantType.NONE)
            {
                state.Data[oneDimMoveIndex] = (int) OccupantType.PLAYER;
                await GameStateUtil.UpdateCurrentGameState(state, moveRequest.PlayFabId, settings);
                return new OkObjectResult(new MakePlayerMoveResult { Valid = true });
            }

            // Move attempt was invalid
            return new OkObjectResult(new MakePlayerMoveResult { Valid = false });
        }

        private readonly ILogger _logger = loggerFactory.CreateLogger<MakePlayerMove>();
    }
}
