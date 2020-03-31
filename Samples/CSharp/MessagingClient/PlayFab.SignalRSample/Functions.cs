// Copyright (C) Microsoft Corporation. All rights reserved.

namespace PlayFab.SignalRSample
{
    using System.Collections.Generic;
    using System.Threading.Tasks;
    using Microsoft.Azure.WebJobs;
    using Microsoft.Azure.WebJobs.Extensions.Http;
    using Microsoft.Azure.WebJobs.Extensions.SignalRService;
    using Microsoft.Extensions.Logging;
    using Newtonsoft.Json;
    using PlayFab;
    using PlayFab.MultiplayerModels;
    using PlayFab.Samples;

    public static class Functions
    {
        /// <summary>
        /// Http-triggered function meant to be invoked by a client ExecuteFunction call. Mints an access token and then provides SignalR conection information back to the client.
        /// </summary>
        /// <param name="request">Request containing the function context. Used to extract the caller's entity id.</param>
        /// <param name="binder">WebJobs Binder used to create a SignalR connection using the provided entity id.</param>
        /// <param name="log">Logger so that we can debug later.</param>
        /// <returns>SignalR Connection Info which consists of a conection string and an access token.</returns>
        [FunctionName("GetSignalRConnection")]
        public static async Task<SignalRConnectionInfo> GetSignalRInfo(
            [HttpTrigger(AuthorizationLevel.Function, "post")] string request,
            Binder binder,
            ILogger log)
        {
            log.LogInformation($"GetSignalRConnection: Received request: {request}.");

            // We need to extract the Entity Id from the context. The entity id is going to be used as the SignalR user id associated with the caller's connection.
            var context = JsonConvert.DeserializeObject<FunctionExecutionContext<object>>(request);

            log.LogInformation($"Creating PubSub subscription for user {context.CallerEntityProfile.Entity.Id}.");

            // In Azure Functions, the SignalR connection is normally created through an input binding attribute. Here, because we need to specify the user id dynamically,
            // we're going to manually create the attribute and then use it to mint connection info.
            // The connection string to use is pulled from the AzureSignalRConnectionString setting by default.
            var signalRConnectionAttribute = new SignalRConnectionInfoAttribute() { HubName = "PubSub", UserId = context.CallerEntityProfile.Entity.Id };
            return await binder.BindAsync<SignalRConnectionInfo>(signalRConnectionAttribute);
        }

        /// <summary>
        /// This is a queued Function that is meant to respond to the match_found PlayStream event.
        /// It gets the match id from the event, uses it to look up the match, and then sends match details to each participant.
        /// </summary>
        /// <param name="request">Request containing the function context. We need to extract the match_found event payload from here.</param>
        /// <param name="signalRMessageQueue">This is the message queue that we can use to send messages to subscribed users.</param>
        /// <param name="log">Logger so that we can debug later.</param>
        /// <returns>Sends a SignalR message to all players in the match containing the response to a GetMatch call.</returns>
        [FunctionName("MatchFound")]
        public static async Task MatchFound(
            [QueueTrigger("matchfound")] string request,
            [SignalR(HubName = "PubSub")] IAsyncCollector<SignalRMessage> signalRMessageQueue,
            ILogger log)
        {
            log.LogInformation($"MatchFound: Received match_found event: {request}.");

            // We need to extact the matchId and queueName from the context. These are contained in the PlayStream V2 event payload and will be used to query GetMatch.
            var context = JsonConvert.DeserializeObject<EntityPlayStreamFunctionExecutionContext<MatchFoundPayload, object>>(request);
            var matchmakingPayload = context.PlayStreamEvent.Payload;

            // Making a call to PlayFab to get the match information from GetMatch. This uses the title auth context, matchId, and queueName provided in the request.
            PlayFabSettings.staticSettings.TitleId = context.TitleAuthenticationContext.Id;
            var getMatchRequest = new GetMatchRequest()
            {
                AuthenticationContext = new PlayFabAuthenticationContext() { EntityToken = context.TitleAuthenticationContext.EntityToken },
                EscapeObject = false,
                MatchId = matchmakingPayload.MatchId,
                QueueName = matchmakingPayload.QueueName,
                ReturnMemberAttributes = true
            };

            var match = await PlayFabMultiplayerAPI.GetMatchAsync(getMatchRequest);

            if (match.Error != null)
            {
                log.LogError($"GetMatch returned error: {match.Error.ErrorMessage}");
                return;
            }

            log.LogInformation($"GetMatch response: {match}");

            // We extracted the list of players from the GetMatch result. Now we iterate through them and send the match details to each.
            foreach (var player in match.Result.Members)
            {
                await signalRMessageQueue.AddAsync(
                    new SignalRMessage
                    {
                        Target = "matchmakingComplete",
                        Arguments = new[] { JsonConvert.SerializeObject(match.Result) },
                        UserId = player.Entity.Id
                    });
            }
        }

        /// <summary>
        /// This is meant to be invoked by a client ExecuteFunction call and will forward a chat message to the target player.
        /// </summary>
        /// <param name="request">Request containing the function context. We expect to find Function Arguments containing a target player and a message to send.</param>
        /// <param name="signalRMessageQueue">This is the message queue that we can use to send messages to subscribed users.</param>
        /// <param name="log">Logger so that we can debug later.</param>
        /// <returns>Sends a SignalR message containing the chat message to the target user.</returns>
        [FunctionName("SendChatMessage")]
        public static async Task SendChatMessage(
            [HttpTrigger(AuthorizationLevel.Function, "post")] string request,
            [SignalR(HubName = "PubSub")] IAsyncCollector<SignalRMessage> signalRMessageQueue,
            ILogger log)
        {
            log.LogInformation($"SendChatMessage: Received login event: {request}.");

            // We need to get the target player and the message from the context. These should be contained in the FunctionArugment.
            var context = JsonConvert.DeserializeObject<FunctionExecutionContext<dynamic>>(request);
            var args = context.FunctionArgument;

            if (args.TargetPlayer == null || args.Message == null)
            {
                log.LogError($"Not all required function arguments were specificed (TargetPlayer and Message)");
            }

            log.LogInformation($"Sending chat message to player: {args.TargetPlayer}.");

            // After extracting the target player and the message, it's easy to send them via SignalR
            // Note the different Target parameter on the message, this allows clients to subscribe to the exact kind of messages they'd like to receive.
            await signalRMessageQueue.AddAsync(
                new SignalRMessage
                {
                    Target = "chatMessage",
                    Arguments = new[] { args.Message },
                    UserId = args.TargetPlayer
                });
        }

        /// <summary>
        /// Broadcasts player login to all other logged-in players. Triggered based on a player_logged_in event via direct Http call.
        /// </summary>
        /// <param name="request">Request containing the function context. This will contain the payload of the player_logged_in event, from which we can get the player's login name.</param>
        /// <param name="signalRMessageQueue">This is the message queue that we can use to send messages to subscribed users.</param>
        /// <param name="log">Logger so that we can debug later.</param>
        /// <returns></returns>
        [FunctionName("PlayerLogin")]
        public static async Task PlayerLogin(
            [HttpTrigger(AuthorizationLevel.Function, "post")] string request,
            [SignalR(HubName = "PubSub")] IAsyncCollector<SignalRMessage> signalRMessageQueue,
            ILogger log)
        {
            log.LogInformation($"PlayerLogin: Received login event: {request}.");

            // Extracting the eventData of the player_logged_in event from the function context.
            var context = JsonConvert.DeserializeObject<PlayerPlayStreamFunctionExecutionContext>(request);
            var eventData = JsonConvert.DeserializeObject<dynamic>(context.PlayStreamEventEnvelope.EventData);

            // In this example, we're just broadcasting a simple value from the player's legacy profile to all other players.
            // It would be straighforward to expand this to read the player's profile, friends, groups, etc and send the desired data to the right set of players.
            log.LogInformation($"Broadcast login for player: {eventData.PlatformUserId}.");
            await signalRMessageQueue.AddAsync(
                new SignalRMessage
                {
                    Target = "friendLogin",
                    Arguments = new[] { eventData.PlatformUserId }
                });
        }
    }

    /// <summary>
    /// Model class used to contain a match_found event payload.
    /// </summary>
    public class MatchFoundPayload
    {
        public List<string> TicketIds { get; set; }
        public string MatchId { get; set; }
        public string QueueName { get; set; }
    }
}
