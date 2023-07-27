#if !DISABLE_PLAYFABCLIENT_API
using System.Collections.Generic;
using PlayFab.SharedModels;
using UnityEngine;

namespace PlayFab.Internal
{
    public static class PlayFabDeviceUtil
    {
        private static bool _needsAttribution, _gatherDeviceInfo, _gatherScreenTime;

        #region Scrape Device Info
        private static void SendDeviceInfoToPlayFab(PlayFabApiSettings settings, IPlayFabInstanceApi instanceApi)
        {
            if (settings.DisableDeviceInfo || !_gatherDeviceInfo) return;

            var serializer = PluginManager.GetPlugin<ISerializerPlugin>(PluginContract.PlayFab_Serializer);
            var request = new ClientModels.DeviceInfoRequest
            {
                Info = serializer.DeserializeObject<Dictionary<string, object>>(serializer.SerializeObject(new PlayFabDataGatherer()))
            };
            var clientInstanceApi = instanceApi as PlayFabClientInstanceAPI;
            if (clientInstanceApi != null)
                clientInstanceApi.ReportDeviceInfo(request, null, OnGatherFail, settings);
#if !DISABLE_PLAYFAB_STATIC_API
            else
                PlayFabClientAPI.ReportDeviceInfo(request, null, OnGatherFail, settings);
#endif
        }
        private static void OnGatherFail(PlayFabError error)
        {
            Debug.Log("OnGatherFail: " + error.GenerateErrorReport());
        }
        #endregion

        /// <summary>
        /// When a PlayFab login occurs, check the result information, and
        ///   relay it to _OnPlayFabLogin where the information is used
        /// </summary>
        /// <param name="result"></param>
        public static void OnPlayFabLogin(PlayFabResultCommon result, PlayFabApiSettings settings, IPlayFabInstanceApi instanceApi)
        {
            var loginResult = result as ClientModels.LoginResult;
            var registerResult = result as ClientModels.RegisterPlayFabUserResult;
            if (loginResult == null && registerResult == null)
                return;

            // Gather things common to the result types
            ClientModels.UserSettings settingsForUser = null;
            string playFabId = null;
            string entityId = null;
            string entityType = null;

            if (loginResult != null)
            {
                settingsForUser = loginResult.SettingsForUser;
                playFabId = loginResult.PlayFabId;
                if (loginResult.EntityToken != null)
                {
                    entityId = loginResult.EntityToken.Entity.Id;
                    entityType = loginResult.EntityToken.Entity.Type;
                }
            }
            else if (registerResult != null)
            {
                settingsForUser = registerResult.SettingsForUser;
                playFabId = registerResult.PlayFabId;
                if (registerResult.EntityToken != null)
                {
                    entityId = registerResult.EntityToken.Entity.Id;
                    entityType = registerResult.EntityToken.Entity.Type;
                }
            }

            _OnPlayFabLogin(settingsForUser, playFabId, entityId, entityType, settings, instanceApi);
        }

        /// <summary>
        /// Separated from OnPlayFabLogin, to explicitly lose the refs to loginResult and registerResult, because
        ///   only one will be defined, but both usually have all the information we REALLY need here.
        /// But the result signatures are different and clunky, so do the separation above, and processing here
        /// </summary>
        private static void _OnPlayFabLogin(ClientModels.UserSettings settingsForUser, string playFabId, string entityId, string entityType, PlayFabApiSettings settings, IPlayFabInstanceApi instanceApi)
        {
            _needsAttribution = _gatherDeviceInfo = _gatherScreenTime = false;
            if (settingsForUser != null)
            {
                _needsAttribution = settingsForUser.NeedsAttribution;
                _gatherDeviceInfo = settingsForUser.GatherDeviceInfo;
                _gatherScreenTime = settingsForUser.GatherFocusInfo;
            }

            // Device information gathering
            SendDeviceInfoToPlayFab(settings, instanceApi);

#if !DISABLE_PLAYFABENTITY_API
            if (!string.IsNullOrEmpty(entityId) && !string.IsNullOrEmpty(entityType) && _gatherScreenTime)
            {
                PlayFabHttp.InitializeScreenTimeTracker(entityId, entityType, playFabId);
            }
            else
            {
                settings.DisableFocusTimeCollection = true;
            }
#endif
        }
    }
}
#endif
