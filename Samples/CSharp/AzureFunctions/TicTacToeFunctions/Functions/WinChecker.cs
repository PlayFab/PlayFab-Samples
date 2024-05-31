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

namespace TicTacToeFunctions.Functions
{
    public class WinChecker
    {
        private readonly ILogger _logger;

        public WinChecker(ILoggerFactory loggerFactory) {
            _logger = loggerFactory.CreateLogger<WinChecker>();
        }

        [Function("WinCheck")]
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

            PlayFabIdRequest playFabIdRequest = context.FunctionArgument.ToObject<PlayFabIdRequest>();

            // Grab the current player's game state
            TicTacToeState state = await GameStateUtil.GetCurrentGameState(playFabIdRequest.PlayFabId, settings);
            
            WinCheckResult winCheckResult = WinCheckUtil.Check(state);

            if (winCheckResult.Winner == GameWinnerType.NONE) {
                return new OkObjectResult(winCheckResult);
            }
            
            // Update the leaderboard accordingly
            await LeaderboardUtils.UpdateLeaderboard(playFabIdRequest.PlayFabId, winCheckResult.Winner);

            // Store the game history
            await GameStateUtil.AddGameStateHistory(state, playFabIdRequest.PlayFabId, settings);

            // Clear the current game state
            await GameStateUtil.UpdateCurrentGameState(new TicTacToeState(), playFabIdRequest.PlayFabId, settings);

            return new OkObjectResult(winCheckResult);
        }
    }
}
