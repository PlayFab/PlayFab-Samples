// Copyright (C) Microsoft Corporation. All rights reserved.

using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.Functions.Worker;
using Microsoft.Azure.Functions.Worker.Http;
using Microsoft.Extensions.Logging;
using PlayFab.TicTacToeDemo.Models;
using PlayFab.TicTacToeDemo.Util;
using PlayFab;

namespace TicTacToeFunctions.Functions
{
    public class MakeAIMove(ILoggerFactory loggerFactory)
    {
        [Function("MakeAIMove")]
        public async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)]
            HttpRequestData req,
            FunctionContext executionContext)
        {
            return await MakeMinMaxAIMove(req, executionContext);
        }
        
        [Function("MakeRandomAIMove")]
        public async Task<IActionResult> MakeRandomAIMove(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestData req,
            FunctionContext executionContext)
        {
            var context = await PlayFabFunctionHelper.GetContext(_logger, req);
            if (context is null) return new BadRequestObjectResult("Invalid context"); 

            var settings = new PlayFabApiSettings { TitleId = context.TitleAuthenticationContext.Id, };
            Settings.TrySetSecretKey(settings);
            Settings.TrySetCloudName(settings);

            var playFabId = context.FunctionArgument.ToObject<PlayFabIdRequest>().PlayFabId;

            // Attempt to load the player's game state
            var state = await GameStateUtil.GetCurrentGameState(playFabId, settings);

            // Look for a random AI move to make
            var aiMove = TicTacToeAI.GetNextRandomMove(state);

            // Store the AI move on the current game state
            var oneDimMoveIndex = aiMove.row * 3 + aiMove.col;
            state.Data[oneDimMoveIndex] = (int) OccupantType.AI;
            await GameStateUtil.UpdateCurrentGameState(state, playFabId, settings);

            // Respond with the AI move
            return new OkObjectResult(aiMove);
        }


        [Function("MakeMinMaxAIMove")]
        public async Task<IActionResult> MakeMinMaxAIMove(
            [HttpTrigger(AuthorizationLevel.Function, "post")] HttpRequestData req,
            FunctionContext executionContext)
        {
            var context = await PlayFabFunctionHelper.GetContext(_logger, req);
            if (context is null) return new BadRequestObjectResult("Invalid context"); 

            PlayFabApiSettings settings = new() { TitleId = context.TitleAuthenticationContext.Id, };
            Settings.TrySetSecretKey(settings);
            Settings.TrySetCloudName(settings);

            var playFabId = context.FunctionArgument.ToObject<PlayFabIdRequest>().PlayFabId;

            // Attempt to load the Player's game state
            var state = await GameStateUtil.GetCurrentGameState(playFabId, settings);

            // Look for a minimax AI move to make
            var aiMove = TicTacToeAI.GetNextMinimaxMove(state);

            // Store the AI move on the current game state
            var oneDimMoveIndex = aiMove.row * 3 + aiMove.col;
            state.Data[oneDimMoveIndex] = (int) OccupantType.AI;
            await GameStateUtil.UpdateCurrentGameState(state, playFabId, settings);

            // Respond with the AI move
            return new OkObjectResult(aiMove);
        }
        
        private readonly ILogger _logger = loggerFactory.CreateLogger<MakeAIMove>();
    }
}
