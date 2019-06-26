///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Cloud Script runs in the PlayFab cloud and has full access to the PlayFab Game Server API 
// (https://api.playfab.com/Documentation/Server), and it runs in the context of a securely
// authenticated player, so you can use it to implement logic for your game that is safe from
// client-side exploits. 
//
// Cloud Script functions can also make web requests to external HTTP
// endpoints, such as a database or private API for your title, which makes them a flexible
// way to integrate with your existing backend systems.
//
// There are several different options for calling Cloud Script functions:
//
// 1) Your game client calls them directly using the "ExecuteFunction" API,
// passing in the function name and arguments in the request and receiving the 
// function return result in the response.
// (https://api.playfab.com/Documentation/Client/method/ExecuteFunction)
// 
// 2) You create PlayStream event actions that call them when a particular 
// event occurs, passing in the event and associated player profile data.
// (https://api.playfab.com/playstream/docs)
//
//
// The following examples demonstrate all three options.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Important notes on Azure Functions:
//
// There are a few requirements needed to make your first Azure Functions App work with PlayFab.
//
// To start, you need to add a reference to the PlayFabAllSDK NuGet package (Version x.xx.xxxx and 
// above) which contains the C# types and methods necessary to make calls onto the PlayFab Main Server.
//
// Furthermore, you will need to have several environment values set in your Functions App. In the
// local case, these values will have to be inserted in the local.settings.json file located at
// the root of your Azure Functions App. If this file is not created by default in your App, feel
// free to create one from scratch and add the following in it:
//
// {
//     "Values":
//         {
//             "FUNCTIONS_WORKER_RUNTIME": "dotnet",
//             "PLAYFAB_DEV_SECRET_KEY":  "[INSERT PLAYFAB TITLE DEV SECRET KEY HERE]",
//             "PLAYFAB_TITLE_ID": "[INSERT PLAYFAB TITLE ID HERE]"
//         }
// }
//
// This will provide your Azure Functions App and the PlayFab SDK with the necessary credentials that
// they will look for to be able to make certain API calls.
// In the remote version of your app, these values can either be uploaded on the App through the 
// portal by uploading the same local.settings.json file, or through manually creating them in the
// Application Settings window of your App. For more information on this please visit the following link:
// (https://docs.microsoft.com/en-us/azure/azure-functions/functions-run-local#local-settings-file)
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


using System;
using System.Threading.Tasks;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.Extensions.Logging;
using PlayFab.ServerModels;
using PlayFab.Json;
using System.Collections.Generic;
using PlayFab.DataModels;
using System.Net.Http;
using System.Net.Http.Headers;
using PlayFab.Plugins.CloudScript;

namespace PlayFab.AzureFunctions
{
    public static class Handlers
    {
        [FunctionName("HelloWorld")]
        public static async Task<dynamic> HelloWorld(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, ILogger log)
        {
            /* Create the function execution's context through the request */
            var context = await FunctionContext<dynamic>.Create(req);
            var args = context.FunctionArgument;

            var message = $"Hello {context.CurrentPlayerId}!";
            log.LogInformation(message);

            dynamic inputValue = null;
            if (args != null && args["inputValue"] != null)
            {
                inputValue = args["inputValue"];
            }

            log.LogDebug($"HelloWorld: {new { input = inputValue} }");

            return new { messageValue = message };
        }

        /// <summary>
        /// This is a simple example of making a PlayFab server API call through an Azure Function
        /// </summary>
        /// <param name="req">The request object deserialized through the Azure Functions runtime from the body of the original request</param>
        /// <param name="log">The log object passed through the Azure Functions runtime for logging to the console</param>
        /// <returns>The result of the simple PlayFab server API call</returns>
        [FunctionName("MakeAPICall")]
        public static async Task<dynamic> MakeApiCall(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, ILogger log)
        {
            /* Create the function execution's context through the request */
            var context = await FunctionContext<dynamic>.Create(req);
            var args = context.FunctionArgument;

            /* Create the request object through the SDK models */
            var request = new UpdatePlayerStatisticsRequest
            {
                PlayFabId = context.CurrentPlayerId,
                Statistics = new List<StatisticUpdate>
                {
                    new StatisticUpdate
                    {
                        StatisticName = "Level",
                        Value = 2
                    }
                }
            };
            /* Use the ApiSettings and AuthenticationContext provided to the function as context for making API calls. */
            var serverApi = new PlayFabServerInstanceAPI(context.ApiSettings, context.AuthenticationContext);
            
            /* The PlayFabServerAPI SDK methods provide means of making HTTP request to the PlayFab Main Server without any 
             * extra code needed to issue the HTTP requests. */
            return await serverApi.UpdatePlayerStatisticsAsync(request);
        }

        /// <summary>
        /// A simple entity API call example that demonstrates as Azure Function using the PlayFab Data API to make a SetObject 
        /// request on an Entity.
        /// </summary>
        /// <param name="req">The request object deserialized through the Azure Functions runtime from the body of the original request</param>
        /// <param name="log">The log object passed through the Azure Functions runtime for logging to the console</param>
        /// <returns>The profile and set result of the entity set object request made in this function</returns>
        [FunctionName("MakeEntityAPICall")]
        public static async Task<dynamic> MakeEntityApiCall(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, ILogger log)
        {
            /* Create the function execution's context through the request */
            var context = await FunctionContext<dynamic>.Create(req);
            var args = context.FunctionArgument;
            
            var entityProfile = context.CallerEntityProfile;

            var setObjectRequest = new SetObjectsRequest
            {
                Entity = ClassConverter<ProfilesModels.EntityKey, DataModels.EntityKey>.Convert(entityProfile.Entity),
                Objects = new List<SetObject>
                {
                    new SetObject
                    {
                        ObjectName = "obj1",
                        DataObject = new
                        {
                            foo = "some server computed value",
                            prop1 = args["prop1"]
                        }
                    }
                }
            };

            /* Use the ApiSettings and AuthenticationContext provided to the function as context for making API calls. */
            var dataApi = new PlayFabDataInstanceAPI(context.ApiSettings, context.AuthenticationContext);
            /* Execute the entity API request */
            var setObjectsResponse = await dataApi.SetObjectsAsync(setObjectRequest);
            var setObjectsResult = setObjectsResponse.Result.SetResults[0].SetResult;

            return new
            {
                profile = entityProfile,
                setResult = setObjectsResult
            };
        }

        /// <summary>
        /// A simple example function that makes an external HTTP call.
        /// </summary>
        /// <param name="req">The request object deserialized through the Azure Functions runtime from the body of the original request</param>
        /// <param name="log">The log object passed through the Azure Functions runtime for logging to the console</param>
        /// <returns>The response of the external HTTP call</returns>
        [FunctionName("MakeHTTPRequest")]
        public static async Task<dynamic> MakeHTTPRequest(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, ILogger log)
        {
            /* Create the function execution's context through the request */
            var context = await FunctionContext<dynamic>.Create(req);
            var args = context.FunctionArgument;

            /* Prepare the body, headers, and url of the external HTTP request */
            dynamic body = new
            {
                input = args, 
                userId = context.CurrentPlayerId,
                mode = "foobar"
            };
            var requestContent = new StringContent(PlayFabSimpleJson.SerializeObject(body));
            requestContent.Headers.Add("X-MyCustomHeader", "Some Value");
            requestContent.Headers.ContentType = new MediaTypeHeaderValue("application/json");
            var url = "http://httpbin.org/status/200";

            /* Execute the HTTP request using a simple HttpClient */
            using (var client = new HttpClient())
            {
                using (var httpResponseMessage = 
                    await client.PostAsync(url, requestContent))
                {
                    using (var responseContent = httpResponseMessage.Content)
                    {
                        return await responseContent.ReadAsAsync<dynamic>();
                    }
                }
            }
        }

        [FunctionName("CompletedLevel")]
        public static async Task<dynamic> LevelCompleted(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, ILogger log)
        {
            /* Create the function execution's context through the request */
            var context = await FunctionContext<dynamic>.Create(req);
            var args = context.FunctionArgument;
            
            var level = args["levelName"];
            var monstersKilled = (int) args["monstersKilled"];

            var updateUserInternalDataRequest = new UpdateUserInternalDataRequest
            {
                PlayFabId = context.CurrentPlayerId,
                Data = new Dictionary<string, string>
                {
                     { "lastLevelCompleted", level }
                }
            };

            /* Use the ApiSettings and AuthenticationContext provided to the function as context for making API calls. */
            var serverApi = new PlayFabServerInstanceAPI(context.ApiSettings, context.AuthenticationContext);
            /* Execute the Server API request */
            var updateUserDataResult = await serverApi.UpdateUserInternalDataAsync(updateUserInternalDataRequest);
            log.LogDebug($"Set lastLevelCompleted for player {context.CurrentPlayerId} to {level}");

            var updateStatRequest = new UpdatePlayerStatisticsRequest
            {
                PlayFabId = context.CurrentPlayerId,
                Statistics = new List<StatisticUpdate>
                {
                    new StatisticUpdate
                    {
                        StatisticName = "level_monster_kills",
                        Value = monstersKilled
                    }
                }
            };

            /* Execute the server API request */
            var updateStatResult = await serverApi.UpdatePlayerStatisticsAsync(updateStatRequest);
            log.LogDebug($"Updated level_monster_kills stat for player {context.CurrentPlayerId} to {monstersKilled}");

            return new
            {
                updateStatResult.Result
            };
        }


        /// <summary>
        /// In addition to the Azure Function handlers, you can define your own functions and call them from your handlers.
        /// This makes it possible to share code between multiple handlers and to improve code organization.
        /// </summary>
        /// <param name="req">The request object deserialized through the Azure Functions runtime from the body of the original request</param>
        /// <param name="log">The log object passed through the Azure Functions runtime for logging to the console</param>
        /// <returns>Your custom output</returns>
        [FunctionName("UpdatePlayerMove")]
        public static async Task<dynamic> UpdatePlayerMove(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, ILogger log)
        {
            /* Create the function execution's context through the request */
            var context = await FunctionContext<dynamic>.Create(req);
            var args = context.FunctionArgument;

            /* Use the ApiSettings and AuthenticationContext provided to the function as context for making API calls. */
            var serverApi = new PlayFabServerInstanceAPI(context.ApiSettings, context.AuthenticationContext);

            bool validMove = await ProcessPlayerMove(serverApi, args["playerMove"], context.CurrentPlayerId, log);
            return new
            {
                ValidMove = validMove
            };
        }

        /// <summary>
        /// This is an example of using PlayStream real-time segmentation to trigger game logic based on player behavior.
        /// (https://playfab.com/introducing-playstream/) The function is called when a player_statistic_changed PlayStream
        /// event causes a player to enter a segment defined for high skill players. It sets a key value in the player's
        /// internal data which unlocks some new content for the player.
        /// </summary>
        /// <param name="req">The request object deserialized through the Azure Functions runtime from the body of the original request</param>
        /// <param name="log">The log object passed through the Azure Functions runtime for logging to the console</param>
        /// <returns>The player's entity profile</returns>
        [FunctionName("UnlockHighSkillContent")]
        public static async Task<dynamic> UnlockHighSkillContent(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = null)] HttpRequestMessage req, ILogger log)
        {
            /* Create the function execution's context through the request */
            var context = await FunctionPlayerPlayStreamContext<dynamic>.Create(req);
            var args = context.FunctionArgument;

            var playerStatUpdatedEvent = PlayFabSimpleJson.DeserializeObject<dynamic>(context.PlayStreamEventEnvelope.EventData);

            var request = new UpdateUserInternalDataRequest
            {
                PlayFabId = context.CurrentPlayerId,
                Data = new Dictionary<string, string>
                {
                    { "HighSkillContent", "true" },
                    { "XPAtHighSkillUnlock", playerStatUpdatedEvent["StatisticValue"].ToString() }
                }
            };

            /* Use the ApiSettings and AuthenticationContext provided to the function as context for making API calls. */
            var serverApi = new PlayFabServerInstanceAPI(context.ApiSettings, context.AuthenticationContext);

            /* Execute the Server API request */
            var updateUserDataResponse = await serverApi.UpdateUserInternalDataAsync(request);

            log.LogInformation($"Unlocked HighSkillContent for {context.PlayerProfile.DisplayName}");

            return new
            {
                profile = context.PlayerProfile
            };
        }

        /// <summary>
        /// This is a helper function that verifies that the player's move wasn't made
        /// too quickly following their previous move, according to the rules of the game.
        /// If the move is valid, then it updates the player's statistics and profile data.
        /// This function is called from the "UpdatePlayerMove" handler above and also is 
        /// triggered by the "RoomEventRaised" Photon room event in the Webhook handler
        /// below. 
        /// 
        /// For this example, the script defines the cooldown period (playerMoveCooldownInSeconds)
        /// as 15 seconds.A recommended approach for values like this would be to create them in Title
        /// Data, so that they can be queries in the script with a call to GetTitleData
        /// (https://api.playfab.com/Documentation/Server/method/GetTitleData). This would allow you to
        /// make adjustments to these values over time, without having to edit, test, and roll out an
        /// updated script.
        /// </summary>
        /// <param name="playerMove">The player's move object</param>
        /// <param name="currentPlayerId">The player's PlayFab ID</param>
        /// <param name="log">The logger object to log to</param>
        /// <returns>True if the player's move was valid, false otherwise</returns>
        private static async Task<bool> ProcessPlayerMove(PlayFabServerInstanceAPI serverApi, dynamic playerMove, string currentPlayerId, ILogger log)
        {
            var now = DateTime.Now;
            var playerMoveCooldownInSeconds = -15;

            var userInternalDataRequest = new GetUserDataRequest
            {
                PlayFabId = currentPlayerId,
                Keys = new List<string>
                {
                    "last_move_timestamp"
                }
            };

            var playerDataResponse = await serverApi.GetUserInternalDataAsync(userInternalDataRequest);
            var playerData = playerDataResponse.Result.Data;
            var lastMoveTimeStampSetting = playerData["last_move_timestamp"];

            if (lastMoveTimeStampSetting != null)
            {
                var lastMoveTime = DateTime.Parse(lastMoveTimeStampSetting.Value);
                var timeSinceLastMoveInSeconds = (now - lastMoveTime) / 1000;
                log.LogDebug($"lastMoveTime: {lastMoveTime} now: {now} timeSinceLastMoveInSeconds: {timeSinceLastMoveInSeconds}");

                if (timeSinceLastMoveInSeconds.TotalSeconds < playerMoveCooldownInSeconds)
                {
                    log.LogError($"Invalid move - time since last move: {timeSinceLastMoveInSeconds}s less than minimum of {playerMoveCooldownInSeconds}s.");
                    return false;
                }
            }

            var getStatsRequest = new GetPlayerStatisticsRequest
            {
                PlayFabId = currentPlayerId
            };

            var playerStats = (await serverApi.GetPlayerStatisticsAsync(getStatsRequest)).Result.Statistics;
            var movesMade = 0;

            for (var i = 0; i < playerStats.Count; i++)
            {
                if (string.IsNullOrEmpty(playerStats[i].StatisticName))
                {
                    movesMade = playerStats[i].Value;
                }
            }
            movesMade += 1;
            var updateStatsRequest = new UpdatePlayerStatisticsRequest
            {
                PlayFabId = currentPlayerId,
                Statistics = new List<StatisticUpdate>
                {
                    new StatisticUpdate
                    {
                        StatisticName = "movesMade",
                        Value = movesMade
                    }
                }
            };

            await serverApi.UpdatePlayerStatisticsAsync(updateStatsRequest);
            await serverApi.UpdateUserInternalDataAsync(new UpdateUserInternalDataRequest
            {
                PlayFabId = currentPlayerId,
                Data = new Dictionary<string, string>
                {
                    { "last_move_timestamp", DateTime.Now.ToUniversalTime().ToString() },
                    { "last_move", PlayFabSimpleJson.SerializeObject(playerMove) }
                }
            });

            return true;
        }

        private class ClassConverter<SourceClass, TargetClass>
        {
            public static TargetClass Convert(SourceClass input)
            {
                var json = PlayFabSimpleJson.SerializeObject(input);
                return PlayFabSimpleJson.DeserializeObject<TargetClass>(json);
            }
        }
    }
}