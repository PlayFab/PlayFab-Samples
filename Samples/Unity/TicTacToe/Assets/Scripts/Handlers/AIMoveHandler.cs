// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.CloudScriptModels;
using PlayFab.Json;
using PlayFab.TicTacToeDemo.Models;
using System;
using System.Collections;

namespace PlayFab.TicTacToeDemo.Handlers
{
    public class AIMoveHandler : RequestHandler
    {
        public TicTacToeMove AIMoveResult { get; set; }

        public AIMoveHandler(PlayerInfo player) : base(player) { }

        public override IEnumerator ExecuteRequest()
        {
            var request = new ExecuteFunctionRequest
            {
                FunctionName = Constants.AI_MOVE_FUNCTION_NAME,
                FunctionParameter = new PlayFabIdRequest
                {
                    PlayFabId = Player.PlayFabId
                },
                AuthenticationContext = new PlayFabAuthenticationContext
                {
                    EntityToken = Player.EntityToken
                }
            };

            PlayFabCloudScriptAPI.ExecuteFunction(request,
                (result) =>
                {
                    ExecutionCompleted = true;
                    AIMoveResult = PlayFabSimpleJson.DeserializeObject<TicTacToeMove>(result.FunctionResult.ToString());
                },
                (error) =>
                {
                    throw new Exception($"MakeAIMove request failed. Message: {error.ErrorMessage}, Code: {error.HttpCode}");
                });

            yield return WaitForExecution();
        }
    }
}
