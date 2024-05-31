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

namespace TicTacToeFunctions.Functions {
    public class ResetGameState {
        private readonly ILogger _logger;

        public ResetGameState(ILoggerFactory loggerFactory) {
            _logger = loggerFactory.CreateLogger<ResetGameState>();
        }

        [Function("ResetGameState")]
        public async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "post")]
            HttpRequestData requestData,
            FunctionContext executionContext) {

            string zRequest = await requestData.ReadAsStringAsync() ?? string.Empty;
            FunctionExecutionContext<dynamic>? context =
                JsonConvert.DeserializeObject<FunctionExecutionContext<dynamic>>(zRequest);

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

            string playFabId = context.CallerEntityProfile.Lineage.MasterPlayerAccountId;

            TicTacToeState newCurrentGameState = new() { Data = new int[9] };

            await GameStateUtil.UpdateCurrentGameState(newCurrentGameState, playFabId, settings);

            return new OkResult();
        }
    }
}
