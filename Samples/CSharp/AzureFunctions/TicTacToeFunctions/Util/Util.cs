// Copyright (C) Microsoft Corporation. All rights reserved.

using Microsoft.Azure.Functions.Worker.Http;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using PlayFab.Samples;

namespace PlayFab.TicTacToeDemo.Util
{
    public static class PlayFabFunctionHelper
    {
        internal static async Task<FunctionExecutionContext<dynamic>?> GetContext(ILogger logger, HttpRequestData req)
        {
            string zRequest = await req.ReadAsStringAsync() ?? string.Empty;
            var context = JsonConvert.DeserializeObject<FunctionExecutionContext<dynamic>>(zRequest);
            if (context is null) return null;

            // Pretty print requestData
            string prettyRequestBody = JObject.Parse(zRequest).ToString(Formatting.Indented);
            logger.LogInformation("Request Data: {prettyRequestBody}\n", prettyRequestBody);

            // Pretty print FunctionContext
            string zContext = JsonConvert.SerializeObject(context);
            string prettyExecutionContext = JObject.Parse(zContext).ToString(Formatting.Indented);
            logger.LogInformation("Execution Context: {prettyExecutionContext}\n", prettyExecutionContext);

            return context;
        }
    }
    
    public class ArrayUtil
    {
        public static T[,] Make2DArray<T>(T[] input, int height, int width)
        {
            T[,] output = new T[height, width];
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    output[i, j] = input[i * width + j];
                }
            }
            return output;
        }
    }
}
