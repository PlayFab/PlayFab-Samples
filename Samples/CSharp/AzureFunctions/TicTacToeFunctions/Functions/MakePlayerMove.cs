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

namespace TicTacToeDemo.Functions {
    public class MakePlayerMove {
        private readonly ILogger _logger;

        public MakePlayerMove(ILoggerFactory loggerFactory) {
            _logger = loggerFactory.CreateLogger<MakePlayerMove>();
        }

        [Function("MakePlayerMove")]
        public async Task<IActionResult> Run(
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

            MakePlayerMoveRequest moveRequest = context.FunctionArgument.ToObject<MakePlayerMoveRequest>();

            // Attempt to load the player's game state
            TicTacToeState state = await GameStateUtil.GetCurrentGameState(moveRequest.PlayFabId, settings);
            TicTacToeMove move = moveRequest.Move;

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
    }
}
