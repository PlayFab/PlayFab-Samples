// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Net.Http;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.Extensions.Logging;
using PlayFab.Plugins.CloudScript;
using PlayFab.TicTacToeDemo.Models;
using PlayFab.TicTacToeDemo.Util;

namespace PlayFab.TicTacToeDemo.Functions
{
    public static class MakeMove
    {
        [FunctionName("MakeRandomAIMove")]
        public static async Task<TicTacToeMove> MakeRandomAIMove(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, HttpRequest httpRequest,
            ILogger log)
        {
            // Extract the context from the incoming request
            var context = await FunctionContext<TicTacToeState>.Create(req);

            // Determine the next AI move
            return TicTacToeAI.GetNextRandomMove(context.FunctionArgument);
        }

        [FunctionName("MakeMinimaxAIMove")]
        public static async Task<TicTacToeMove> MakeMinimaxAIMove(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, HttpRequest httpRequest,
            ILogger log)
        {
            // Extract the context from the incoming request
            var context = await FunctionContext<TicTacToeState>.Create(req);

            // Determine the next AI Minimax move
            return TicTacToeAI.GetNextMinimaxMove(context.FunctionArgument);
        }
    }
}
