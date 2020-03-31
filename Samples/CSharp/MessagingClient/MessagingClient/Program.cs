// Copyright (C) Microsoft Corporation. All rights reserved.

namespace MessagingClient
{
    using System;
    using System.Collections.Generic;
    using System.Diagnostics;
    using System.Linq;
    using System.Threading;
    using Newtonsoft.Json;
    using PlayFab;
    using PlayFab.ClientModels;
    using PlayFab.CloudScriptModels;
    using PlayFab.MultiplayerModels;

    class Program
    {
        // Title Id from PlayFab. Set this depending on the title you're integrating with.
        private const string TITLE_ID = "XXXXX";

        private static List<string> matchPlayers;
        private static ManualResetEvent matchReady = new ManualResetEvent(false);

        /// <summary>
        /// This sample application uses Azure SignalR and PlayFab Azure Functions to matchmake with other instances, 
        /// receive notifications of player login, and do basic chatting.
        /// </summary>
        /// <param name="args">No args expected.</param>
        static void Main(string[] args)
        {
            // Generating a new custom id for every instance. This can simulate lots of different players logging in.
            var customId = $"{Environment.MachineName}_{Process.GetCurrentProcess().Id}";

            // First thing to do is always login to PlayFab. We'll need to get the auth context and player entity for this sample.
            PlayFabSettings.staticSettings.TitleId = TITLE_ID;
            var loginResult = PlayFabClientAPI.LoginWithCustomIDAsync(new LoginWithCustomIDRequest() 
                { CustomId = customId, TitleId = TITLE_ID, CreateAccount = true }).Result;
            if (loginResult.Error != null)
            {
                Console.WriteLine($"!!! Failed to log in to PlayFab: {loginResult.Error.ErrorMessage}");
            }

            Console.WriteLine($"### Logged in to PlayFab as {customId}");

            // Establishing the SignalR connection
            var signalRClient = new SimpleSignalRClient(PlayFabSettings.staticSettings, loginResult.Result.AuthenticationContext);
            if (signalRClient.StartAsync().Result)
            {
                // After connecting, we need to set up some subscriptions.
                signalRClient.Subscribe("matchmakingComplete", (message) => ReceiveMatchmakingNotification(message));
                signalRClient.Subscribe("chatMessage", (message) => Console.WriteLine(message));
                signalRClient.Subscribe("friendLogin", (message) =>
                {
                    if (!string.Equals(message.ToString(), customId)) Console.WriteLine($"### {message} has logged in.");
                });
            }
            else
            {
                Console.WriteLine("!!! Failed to establish SignalR Subscription. Aborting.");
                Console.ReadLine();
                return;
            }

            // Now that SignalR is listening, we can join matchmaking and wait to be matched.
            JoinMatchmaking(new PlayFab.MultiplayerModels.EntityKey() { Id = loginResult.Result.AuthenticationContext.EntityId, Type = loginResult.Result.AuthenticationContext.EntityType });
            Console.WriteLine("### Ready to receive matchmaking notifications");

            // Waiting on the matchmaking to complete
            var matched = matchReady.WaitOne(TimeSpan.FromSeconds(30));

            if (matched)
            {
                RunMatch(loginResult.Result.AuthenticationContext.EntityId);
            }
            else
            {
                Console.WriteLine("!!! Failed to find a match in time");
            }

            signalRClient.DisposeAsync().Wait();
        }

        private static void ReceiveMatchmakingNotification(object message)
        {
            // The callback from SignalR will contain GetMatch response payload, so cast it and extract the other players in the match.
            var matchResult = JsonConvert.DeserializeObject<GetMatchResult>(message.ToString());
            matchPlayers = matchResult.Members.Select(x => x.Entity.Id).ToList();
            Console.WriteLine($"Starting Match: {matchResult.MatchId} with players ({string.Join(",", matchPlayers)}).");

            // Now that we're in a match, notify the main thread.
            matchReady.Set();
        }

        private static void JoinMatchmaking(PlayFab.MultiplayerModels.EntityKey entity)
        {
            // We're joining a simple 2-player matchmaking queue with no rules or restrictions.
            var matchMakingRequest = new CreateMatchmakingTicketRequest()
            {
                QueueName = "nr_simple",
                Creator = new MatchmakingPlayer() { Entity = entity },
                GiveUpAfterSeconds = 30
            };

            var match = PlayFabMultiplayerAPI.CreateMatchmakingTicketAsync(matchMakingRequest).Result;
            if (match.Error != null)
            {
                Console.WriteLine($"!!! Matchmaking failed: {match.Error.ErrorMessage}");
            }
        }

        private static void RunMatch(string currentPlayer)
        {
            Console.WriteLine("### Ready to chat.");

            // We're doing 2-player matchmaking, so we can examine the list of players to determine the id of th eother player.
            var otherPlayer = matchPlayers.Single(x => x != currentPlayer);

            // While we're in the chat after matchmaking, read console input and send it to PlayFab.
            for (string inputLine = Console.ReadLine(); inputLine != string.Empty;  inputLine = Console.ReadLine())
            {
                SendChatMessage(otherPlayer, inputLine);
            }
        }

        private static void SendChatMessage(string targetPlayer, string message)
        {
            // Sending a chat message is a simple Azure Function execution where we pass in the target player and message.
            var sendChatRequest = new ExecuteFunctionRequest()
            {
                FunctionName = "SendChatMessage",
                FunctionParameter = new { TargetPlayer = targetPlayer, Message = message },
                GeneratePlayStreamEvent = true
            };

            PlayFabCloudScriptAPI.ExecuteFunctionAsync(sendChatRequest);
        }
    }
}