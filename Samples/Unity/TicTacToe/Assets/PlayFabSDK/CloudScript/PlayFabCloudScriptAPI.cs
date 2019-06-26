#if !DISABLE_PLAYFABENTITY_API

using System;
using System.Collections.Generic;
using PlayFab.CloudScriptModels;
using PlayFab.Internal;

namespace PlayFab
{
    /// <summary>
    /// API methods for executing CloudScript using an Entity Profile
    /// </summary>
    public static class PlayFabCloudScriptAPI
    {
        static PlayFabCloudScriptAPI() {}


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
        /// Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution of any kind of
        /// custom server-side functionality you can implement, and it can be used in conjunction with virtually anything.
        /// </summary>
        public static void ExecuteEntityCloudScript(ExecuteEntityCloudScriptRequest request, Action<ExecuteCloudScriptResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/CloudScript/ExecuteEntityCloudScript", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution of any kind of
        /// custom server-side functionality you can implement, and it can be used in conjunction with virtually anything.
        /// </summary>
        public static void ExecuteFunction(ExecuteFunctionRequest request, Action<ExecuteFunctionResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;

            var localApiServerString = PlayFabSettings.LocalApiServer;
            if (!string.IsNullOrEmpty(localApiServerString))
            {
                var baseUri = new Uri(localApiServerString);
                var fullUri = new Uri(baseUri, "/CloudScript/ExecuteFunction".TrimStart('/'));
                PlayFabHttp.MakeApiCallWithFullUri(fullUri.AbsoluteUri, request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
                return;
            }

            PlayFabHttp.MakeApiCall("/CloudScript/ExecuteFunction", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Lists all currently registered Azure Functions for a given title.
        /// </summary>
        public static void ListFunctions(ListFunctionsRequest request, Action<ListFunctionsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/CloudScript/ListFunctions", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Registers an Azure function with a title.
        /// </summary>
        public static void RegisterHttpFunction(RegisterHttpFunctionRequest request, Action<EmptyResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/CloudScript/RegisterHttpFunction", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Unregisters an Azure function with a title.
        /// </summary>
        public static void UnregisterFunction(UnregisterFunctionRequest request, Action<EmptyResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/CloudScript/UnregisterFunction", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }


    }
}

#endif
