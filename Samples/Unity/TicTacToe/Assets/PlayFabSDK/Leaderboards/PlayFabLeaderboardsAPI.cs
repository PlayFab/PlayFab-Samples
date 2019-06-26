#if !DISABLE_PLAYFABENTITY_API

using System;
using System.Collections.Generic;
using PlayFab.LeaderboardsModels;
using PlayFab.Internal;

namespace PlayFab
{
    /// <summary>
    /// Manage entity statistics Manage entity statistics
    /// </summary>
    public static class PlayFabLeaderboardsAPI
    {
        static PlayFabLeaderboardsAPI() {}


        /// <summary>
        /// Verify entity login.
        /// </summary>
        public static bool IsEntityLoggedIn()
        {
            return PlayFabSettings.staticPlayer.IsEntityLoggedIn();
        }

        /// <summary>
        /// Clear the Client SessionToken which allows this Client to call API calls requiring login.
        /// A new/fresh login will be required after calling this.
        /// </summary>
        public static void ForgetAllCredentials()
        {
            PlayFabSettings.staticPlayer.ForgetAllCredentials();
        }

        /// <summary>
        /// Create a new entity statistic definition.
        /// </summary>
        public static void CreateStatisticDefinition(CreateStatisticDefinitionRequest request, Action<EmptyResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Statistic/CreateStatisticDefinition", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Delete an entity statistic definition. Will delete all statistics on entity profiles and leaderboards.
        /// </summary>
        public static void DeleteStatisticDefinition(DeleteStatisticDefinitionRequest request, Action<EmptyResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Statistic/DeleteStatisticDefinition", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Delete statistics on an entity profile, will remove all rankings from associated leaderboards.
        /// </summary>
        public static void DeleteStatistics(DeleteStatisticsRequest request, Action<DeleteStatisticsResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Statistic/DeleteStatistics", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get the leaderboard for a specific entity type and statistic.
        /// </summary>
        public static void GetLeaderboard(GetEntityLeaderboardRequest request, Action<GetEntityLeaderboardResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Leaderboard/GetLeaderboard", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get the leaderboard around a specific entity.
        /// </summary>
        public static void GetLeaderboardAroundEntity(GetLeaderboardAroundEntityRequest request, Action<GetEntityLeaderboardResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Leaderboard/GetLeaderboardAroundEntity", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get the leaderboard limited to a set of entities.
        /// </summary>
        public static void GetLeaderboardForEntities(GetLeaderboardForEntitiesRequest request, Action<GetEntityLeaderboardResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Leaderboard/GetLeaderboardForEntities", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get current statistic definition information
        /// </summary>
        public static void GetStatisticDefinition(GetStatisticDefinitionRequest request, Action<GetStatisticDefinitionResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Statistic/GetStatisticDefinition", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get all current statistic definitions information
        /// </summary>
        public static void GetStatisticDefinitions(GetStatisticDefinitionsRequest request, Action<GetStatisticDefinitionsResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Statistic/GetStatisticDefinitions", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Increment an entity statistic definition version.
        /// </summary>
        public static void IncrementStatisticVersion(IncrementStatisticVersionRequest request, Action<IncrementStatisticVersionResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Statistic/IncrementStatisticVersion", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Update statistics on an entity profile, depending on the statistic definition may cause entity to be ranked on various
        /// leaderboards.
        /// </summary>
        public static void UpdateStatistics(UpdateStatisticsRequest request, Action<UpdateStatisticsResponse> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Statistic/UpdateStatistics", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }


    }
}

#endif
