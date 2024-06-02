// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.CloudScriptModels;
using PlayFab.Json;
using PlayFab.TicTacToeDemo.Models;
using System;
using System.Collections;

namespace PlayFab.TicTacToeDemo.Handlers
{
    public class PlayerMoveHandler : RequestHandler
    {
        private TicTacToeMove MoveToExecute { get; set; }
        public MakePlayerMoveResult MoveResult { get; private set; }

        public PlayerMoveHandler(PlayerInfo player, TicTacToeMove NextMove) : base(player)
        {
            MoveToExecute = NextMove;
        }
        
        public override IEnumerator ExecuteRequest()
        {
            // Create the move request
            var request = new ExecuteFunctionRequest
            {
                Entity = new EntityKey
                {
                    Id = PlayFabSettings.staticPlayer.EntityId,
                    Type = PlayFabSettings.staticPlayer.EntityType,
                },
                FunctionName = Constants.PLAYER_MOVE_FUNCTION_NAME,
                FunctionParameter = new MakePlayerMoveRequest
                {
                    PlayFabId = Player.PlayFabId,
                    Move = MoveToExecute
                },
                GeneratePlayStreamEvent = true
            };

            // Execute the move request
            PlayFabCloudScriptAPI.ExecuteFunction(request,
                (result) =>
                {
                    ExecutionCompleted = true;
                    MoveResult = PlayFabSimpleJson.DeserializeObject<MakePlayerMoveResult>(result.FunctionResult.ToString());
                },
                (error) =>
                {
                    throw new Exception($"MakePlayerMove request failed. Message: {error.ErrorMessage}, Code: {error.HttpCode}");
                });

            yield return WaitForExecution();
        }
    }
}
