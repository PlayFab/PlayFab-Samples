#if !DISABLE_PLAYFABENTITY_API

using System;
using System.Collections.Generic;
using PlayFab.LeaderboardsModels;
using PlayFab.Internal;
using PlayFab.SharedModels;

namespace PlayFab
{
    /// <summary>
    /// Manage entity statistics Manage entity statistics
    /// </summary>
    public class PlayFabLeaderboardsInstanceAPI : IPlayFabInstanceApi
    {
        public readonly PlayFabApiSettings apiSettings = null;
        private readonly PlayFabAuthenticationContext authenticationContext = null;

        public PlayFabLeaderboardsInstanceAPI(PlayFabAuthenticationContext context)
        {
            if (context == null)
                throw new PlayFabException(PlayFabExceptionCode.AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or call <PlayFabClientInstanceAPI>.GetAuthenticationContext()");
            authenticationContext = context;
        }

        public PlayFabLeaderboardsInstanceAPI(PlayFabApiSettings settings, PlayFabAuthenticationContext context)
        {
            if (context == null)
                throw new PlayFabException(PlayFabExceptionCode.AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or call <PlayFabClientInstanceAPI>.GetAuthenticationContext()");
            apiSettings = settings;
            authenticationContext = context;
        }

        public PlayFabAuthenticationContext GetAuthenticationContext()
        {
            return authenticationContext;
        }

        /// <summary>
        /// Verify entity login.
        /// </summary>
        public bool IsEntityLoggedIn()
        {
            return authenticationContext == null ? false : authenticationContext.IsEntityLoggedIn();
        }

        /// <summary>
        /// Clear the Client SessionToken which allows this Client to call API calls requiring login.
        /// A new/fresh login will be required after calling this.
        /// </summary>
        public void ForgetAllCredentials()
        {
            if (authenticationContext != null)
            {
                authenticationContext.ForgetAllCredentials();
            }
        }

        /// <summary>
        /// Create a new entity statistic definition.
        /// </summary>
        public void CreateStatisticDefinition(CreateStatisticDefinitionRequest request, Action<EmptyResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Statistic/CreateStatisticDefinition", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Delete an entity statistic definition. Will delete all statistics on entity profiles and leaderboards.
        /// </summary>
        public void DeleteStatisticDefinition(DeleteStatisticDefinitionRequest request, Action<EmptyResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Statistic/DeleteStatisticDefinition", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Delete statistics on an entity profile, will remove all rankings from associated leaderboards.
        /// </summary>
        public void DeleteStatistics(DeleteStatisticsRequest request, Action<DeleteStatisticsResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Statistic/DeleteStatistics", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Get the leaderboard for a specific entity type and statistic.
        /// </summary>
        public void GetLeaderboard(GetEntityLeaderboardRequest request, Action<GetEntityLeaderboardResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Leaderboard/GetLeaderboard", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Get the leaderboard around a specific entity.
        /// </summary>
        public void GetLeaderboardAroundEntity(GetLeaderboardAroundEntityRequest request, Action<GetEntityLeaderboardResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Leaderboard/GetLeaderboardAroundEntity", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Get the leaderboard limited to a set of entities.
        /// </summary>
        public void GetLeaderboardForEntities(GetLeaderboardForEntitiesRequest request, Action<GetEntityLeaderboardResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Leaderboard/GetLeaderboardForEntities", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Get current statistic definition information
        /// </summary>
        public void GetStatisticDefinition(GetStatisticDefinitionRequest request, Action<GetStatisticDefinitionResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Statistic/GetStatisticDefinition", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Get all current statistic definitions information
        /// </summary>
        public void GetStatisticDefinitions(GetStatisticDefinitionsRequest request, Action<GetStatisticDefinitionsResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Statistic/GetStatisticDefinitions", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Increment an entity statistic definition version.
        /// </summary>
        public void IncrementStatisticVersion(IncrementStatisticVersionRequest request, Action<IncrementStatisticVersionResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Statistic/IncrementStatisticVersion", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

        /// <summary>
        /// Update statistics on an entity profile, depending on the statistic definition may cause entity to be ranked on various
        /// leaderboards.
        /// </summary>
        public void UpdateStatistics(UpdateStatisticsRequest request, Action<UpdateStatisticsResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? authenticationContext;
            var callSettings = apiSettings ?? PlayFabSettings.staticSettings;
            PlayFabHttp.MakeApiCall("/Statistic/UpdateStatistics", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context, callSettings, this);
        }

    }
}

#endif
