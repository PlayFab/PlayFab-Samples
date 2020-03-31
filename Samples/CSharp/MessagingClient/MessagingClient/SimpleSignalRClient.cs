// Copyright (C) Microsoft Corporation. All rights reserved.

namespace MessagingClient
{
    using System;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.SignalR.Client;
    using Newtonsoft.Json;
    using PlayFab;
    using PlayFab.CloudScriptModels;

    public class SimpleSignalRClient
    {
        // The PlayFab Azure Function name that will be used to retrieve SignalR connection information specific to this client.
        private const string GetConnectionFunctionName = "GetSignalRConnection";

        private readonly PlayFabCloudScriptInstanceAPI cloudScriptAPI;
        private HubConnection signalRHubConnection;

        /// <summary>
        /// Instantiates a new instance of the SimpleSignalRClient class.
        /// </summary>
        /// <param name="settings">PlayFab API Settings to be used by this client when calling PlayFab APIs.</param>
        /// <param name="authContext">The auth context to be used by this client when calling PlayFab APIs.</param>
        public SimpleSignalRClient(PlayFabApiSettings settings, PlayFabAuthenticationContext authContext)
        {
            cloudScriptAPI = new PlayFabCloudScriptInstanceAPI(settings, authContext);
        }

        /// <summary>
        /// Subscribes this client to a specific type of message sent through the SignalR server.
        /// </summary>
        /// <param name="subscriptionName">The subscription name must align with a Target for messages sent from the server.</param>
        /// <param name="messageCallback">Action that is invoked whenever this subscription receives a message.</param>
        public void Subscribe(string subscriptionName, Action<object> messageCallback)
        {
            signalRHubConnection.On(subscriptionName,
                (object message) =>
                {
                    messageCallback(message);
                });
        }

        /// <summary>
        /// Starts the SignalR client. This includes a call to PlayFab to retrieve the cinnection info.
        /// </summary>
        /// <returns>Whether the SignalR client was successfully started.</returns>
        public async Task<bool> StartAsync()
        {
            // We only want to do this once, so bypass on repeat calls.
            if (signalRHubConnection == null)
            {
                // Get the conneciton info from PlayFab.
                var connectionInfo = await GetConnectionInfo();

                if (connectionInfo == null)
                {
                    return false;
                }

                // Configures a connection to the hub using the url and access token we just retrieved.
                signalRHubConnection = new HubConnectionBuilder()
                   .WithUrl(connectionInfo.url, option =>
                   {
                       option.AccessTokenProvider = () =>
                       {
                           return Task.FromResult(connectionInfo.accessToken);
                       };
                   }).Build();

                // After being configured, establish the connection so that we can start receiving messages.
                await signalRHubConnection.StartAsync();
                
                return true;
            }

            return true;
        }

        /// <summary>
        /// Disposes the SignalR Hub Connection.
        /// </summary>
        /// <returns>A Task to await.</returns>
        public async Task DisposeAsync()
        {
            if (signalRHubConnection != null)
            {
                await signalRHubConnection.DisposeAsync();
            }
        }

        /// <summary>
        /// Calls an Azure Function via PlayFab to retrieve SignalR connection info specific to this client.
        /// </summary>
        /// <returns>The SignalR connection info to be used by this client.</returns>
        private async Task<SignalRConnectionInfo> GetConnectionInfo()
        {
            // We're getting the conneciton info from PlayFab. This will utilize the player's id to generate a unique access token.
            var getConnectionRequest = new ExecuteFunctionRequest()
            {
                FunctionName = GetConnectionFunctionName,
                GeneratePlayStreamEvent = true
            };

            var getConnectionResult = await cloudScriptAPI.ExecuteFunctionAsync(getConnectionRequest);
            if (getConnectionResult.Error != null || getConnectionResult.Result.Error != null)
            {
                return null;
            }

            return JsonConvert.DeserializeObject<SignalRConnectionInfo>(getConnectionResult.Result.FunctionResult.ToString());
        }
    }

    /// <summary>
    /// Class meant to store connection info for a SignalR client.
    /// </summary>
    public class SignalRConnectionInfo
    {
        public string url { get; set; }
        public string accessToken { get; set; }
    }
}
