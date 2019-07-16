// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.CloudScriptModels;
using PlayFab.TicTacToeDemo.Models;
using System;
using System.Collections;

namespace PlayFab.TicTacToeDemo.Handlers
{
    public class ResetGameStateHandler : RequestHandler
    {
        public ResetGameStateHandler(PlayerInfo Player) : base(Player) { }

        public override IEnumerator ExecuteRequest()
        {
            // Create the reset request
            var request = new ExecuteFunctionRequest
            {
                FunctionName = Constants.RESET_GAME_STATE_FUNCTION_NAME,
                FunctionParameter = new PlayFabIdRequest
                {
                    PlayFabId = Player.PlayFabId
                },
                AuthenticationContext = new PlayFabAuthenticationContext
                {
                    EntityToken = Player.EntityToken
                }
            };

            // Execute the reset request
            PlayFabCloudScriptAPI.ExecuteFunction(request,
                (result) =>
                {
                    ExecutionCompleted = true;
                },
                (error) =>
                {
                    throw new Exception($"ResetGameState request failed. Message: {error.ErrorMessage}, Code: {error.HttpCode}");
                });

            yield return WaitForExecution();
        }
    }
}
