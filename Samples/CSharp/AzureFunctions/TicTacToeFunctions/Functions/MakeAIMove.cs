// Copyright (C) Microsoft Corporation. All rights reserved.

using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.Functions.Worker;
using Microsoft.Azure.Functions.Worker.Http;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using PlayFab;
using PlayFab.Samples;
using PlayFab.TicTacToeDemo.Models;
using PlayFab.TicTacToeDemo.Util;
using FunctionContext = PlayFab.Plugins.CloudScript.FunctionContext;

namespace Shuffle.TicTacToe.Functions {
    public class MakeAiMove {
        private readonly ILogger _logger;

        public MakeAiMove(ILoggerFactory loggerFactory) {
            _logger = loggerFactory.CreateLogger<MakeAiMove>();
        }
        
        [Function("MakeRandomAiMove")]
        public async Task<IActionResult> MakeRandomAiMove(
            [HttpTrigger(AuthorizationLevel.Function, "post")]
            HttpRequestData requestData,
            FunctionContext executionContext) {
            
            string zRequest = await requestData.ReadAsStringAsync() ?? string.Empty;
            PlayerPlayStreamFunctionExecutionContext<dynamic>? context =
                JsonConvert.DeserializeObject<PlayerPlayStreamFunctionExecutionContext<dynamic>>(zRequest);

            // Pretty print requestData
            string prettyRequestBody = JObject.Parse(zRequest).ToString(Formatting.Indented);
            _logger.LogInformation("Request Data: {prettyRequestBody}\n", prettyRequestBody);

            // Pretty print executionContext
            string executionContextString = JsonConvert.SerializeObject(context);
            string prettyExecutionContext = JObject.Parse(executionContextString).ToString(Formatting.Indented);
            _logger.LogInformation("Execution Context: {prettyExecutionContext}\n", prettyExecutionContext);
            
            if (context == null) {
                return new BadRequestObjectResult("Invalid context");
            }

            PlayFabApiSettings settings = new() { TitleId = context.TitleAuthenticationContext.Id, };
            Settings.TrySetSecretKey(ref settings);
            Settings.TrySetCloudName(ref settings);

            PlayFabIdRequest playFabIdRequest = context.FunctionArgument.ToObject<PlayFabIdRequest>();

            // Attempt to load the player's game state
            TicTacToeState state = await GameStateUtil.GetCurrentGameState(playFabIdRequest.PlayFabId, settings);

            // Look for a random AI move to make
            TicTacToeMove aiMove = TicTacToeAI.GetNextRandomMove(state);

            // Store the AI move on the current game state
            int oneDimMoveIndex = aiMove.row * 3 + aiMove.col;
            state.Data[oneDimMoveIndex] = (int)OccupantType.AI;
            await GameStateUtil.UpdateCurrentGameState(state, playFabIdRequest.PlayFabId, settings);

            // Respond with the AI move
            return new OkObjectResult(aiMove);
        }


        //[Function("MakeAiMove")]
        [Function("MakeMinMaxAiMove")]
        public async Task<IActionResult> MakeMinMaxAiMove(
            [HttpTrigger(AuthorizationLevel.Function, "post")]
            HttpRequestData requestData,
            FunctionContext executionContext) {
            
            string zRequest = await requestData.ReadAsStringAsync() ?? string.Empty;
            PlayerPlayStreamFunctionExecutionContext<dynamic>? context =
                JsonConvert.DeserializeObject<PlayerPlayStreamFunctionExecutionContext<dynamic>>(zRequest);

            // Pretty print requestData
            string prettyRequestBody = JObject.Parse(zRequest).ToString(Formatting.Indented);
            _logger.LogInformation("Request Data: \n" + prettyRequestBody);

            // Pretty print executionContext
            string executionContextString = JsonConvert.SerializeObject(context);
            string prettyExecutionContext = JObject.Parse(executionContextString).ToString(Formatting.Indented);
            _logger.LogInformation("Execution Context: \n" + prettyExecutionContext);
            
            if (context == null) {
                return new BadRequestObjectResult("Invalid context");
            }

            PlayFabApiSettings settings = new() { TitleId = context.TitleAuthenticationContext.Id, };
            Settings.TrySetSecretKey(ref settings);
            Settings.TrySetCloudName(ref settings);

            PlayFabIdRequest playFabIdRequest = context.FunctionArgument.ToObject<PlayFabIdRequest>();

            // Attempt to load the Player's game state
            TicTacToeState state = await GameStateUtil.GetCurrentGameState(playFabIdRequest.PlayFabId, settings);

            // Look for a minimax AI move to make
            TicTacToeMove aiMove = TicTacToeAI.GetNextMinimaxMove(state);

            // Store the AI move on the current game state
            int oneDimMoveIndex = aiMove.row * 3 + aiMove.col;
            state.Data[oneDimMoveIndex] = (int)OccupantType.AI;
            await GameStateUtil.UpdateCurrentGameState(state, playFabIdRequest.PlayFabId, settings);

            // Respond with the AI move
            return new OkObjectResult(aiMove);
        }
    }
}
