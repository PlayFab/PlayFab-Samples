// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Threading.Tasks;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.Extensions.Logging;
using PlayFab.TicTacToeDemo.Models;
using System.Net.Http;
using PlayFab.Plugins.CloudScript;
using PlayFab.TicTacToeDemo.Util;

namespace PlayFab.TicTacToeDemo.Functions
{
    public static class MakePlayerMove
    {
        [FunctionName("MakePlayerMove")]
        public static async Task<MakePlayerMoveResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req,
            ILogger log)
        {
            var context = await FunctionContext<MakePlayerMoveRequest>.Create(req);
            var move = context.FunctionArgument.Move;

            Settings.TrySetSecretKey(context.ApiSettings);
            Settings.TrySetCloudName(context.ApiSettings);

            var playFabId = context.FunctionArgument.PlayFabId;

            // Attempt to load the player's game state
            var state = await GameStateUtil.GetCurrentGameState(playFabId, context.ApiSettings, context.AuthenticationContext);

            var oneDimMoveIndex = move.row * 3 + move.col;

            // Move can only be made if spot was empty
            if (state.Data[oneDimMoveIndex] == (int) OccupantType.NONE)
            {
                state.Data[oneDimMoveIndex] = (int) OccupantType.PLAYER;
                await GameStateUtil.UpdateCurrentGameState(state, playFabId, context.ApiSettings, context.AuthenticationContext);
                return new MakePlayerMoveResult()
                {
                    Valid = true
                };
            }
            // Move attempt was invalid
            else
            {
                return new MakePlayerMoveResult()
                {
                    Valid = false
                };
            }
        }

        

    }
}
