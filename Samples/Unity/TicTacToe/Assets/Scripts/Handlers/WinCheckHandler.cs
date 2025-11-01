// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.CloudScriptModels;
using PlayFab.Json;
using PlayFab.TicTacToeDemo.Models;
using System;
using System.Collections;

namespace PlayFab.TicTacToeDemo.Handlers
{
    public class WinCheckHandler: RequestHandler
    {
        public WinCheckResult WinCheckResult { get; private set; }

        public WinCheckHandler(PlayerInfo Player) : base(Player) { }

        public override IEnumerator ExecuteRequest()
        {
            var request = new ExecuteFunctionRequest
            {
                Entity = new EntityKey
                {
                    Id = PlayFabSettings.staticPlayer.EntityId,
                    Type = PlayFabSettings.staticPlayer.EntityType,
                },
                FunctionName = Constants.WIN_CHECK_FUNCTION_NAME,
                FunctionParameter = new PlayFabIdRequest
                {
                    PlayFabId = Player.PlayFabId
                },
                GeneratePlayStreamEvent = true
            };

            PlayFabCloudScriptAPI.ExecuteFunction(request,
                (result) =>
                {
                    ExecutionCompleted = true;
                    WinCheckResult = PlayFabSimpleJson.DeserializeObject<WinCheckResult>(result.FunctionResult.ToString());
                },
                (error) =>
                {
                    throw new Exception($"WinCheck request failed. Message: ${error.ErrorMessage}, Code: ${error.HttpCode}");
                });

            yield return WaitForExecution();
        }
    }
}
