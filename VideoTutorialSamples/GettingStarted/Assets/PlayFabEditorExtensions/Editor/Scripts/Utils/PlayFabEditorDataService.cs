using PlayFab.PfEditor.EditorModels;
using PlayFab.PfEditor.Json;
using System;
using System.Collections.Generic;
using System.Reflection;
using UnityEditor;
using UnityEngine;

namespace PlayFab.PfEditor
{
    [InitializeOnLoad]
    public class PlayFabEditorDataService : UnityEditor.Editor
    {
        #region EditorPref data classes
        public class PlayFab_DeveloperAccountDetails
        {
            public static string Name = "PlayFab_DeveloperAccountDetails";

            public string email;
            public string devToken;
            public List<Studio> studios;

            public PlayFab_DeveloperAccountDetails()
            {
                studios = null; // Null means not fetched, empty is a possible return result from GetStudios
            }
        }

        public class PlayFab_DeveloperEnvironmentDetails
        {
            public static string Name = "PlayFab_DeveloperEnvironmentDetails";

            public string selectedStudio;
            public Dictionary<string, string> titleData;
            public Dictionary<string, string> titleInternalData;
            public string sdkPath;
            public string edexPath;
            public string localCloudScriptPath;

            public PlayFab_DeveloperEnvironmentDetails()
            {
                titleData = new Dictionary<string, string>();
                titleInternalData = new Dictionary<string, string>();
            }
        }

        public class PlayFab_SharedSettingsProxy
        {
            private readonly PropertyInfo _titleId;
            private readonly PropertyInfo _developerSecretKey;
            private readonly PropertyInfo _webRequestType;
            private readonly PropertyInfo _compressApiData;
            private readonly PropertyInfo _keepAlive;
            private readonly PropertyInfo _timeOut;

            public string TitleId { get { return (string)_titleId.GetValue(null, null); } set { _titleId.SetValue(null, value, null); } }
            public string DeveloperSecretKey { get { return (string)_developerSecretKey.GetValue(null, null); } set { _developerSecretKey.SetValue(null, value, null); } }
            public PlayFabEditorSettings.WebRequestType WebRequestType { get { return (PlayFabEditorSettings.WebRequestType)_webRequestType.GetValue(null, null); } set { _webRequestType.SetValue(null, (int)value, null); } }
            public bool CompressApiData { get { return (bool)_compressApiData.GetValue(null, null); } set { _compressApiData.SetValue(null, value, null); } }
            public bool KeepAlive { get { return (bool)_keepAlive.GetValue(null, null); } set { _keepAlive.SetValue(null, value, null); } }
            public int TimeOut
            {
                get
                {
                    return (int)_timeOut.GetValue(null, null);
                }
                set
                {
                    _timeOut.SetValue(null, value, null);
                }
            }

            public PlayFab_SharedSettingsProxy()
            {
                var playFabSettingsType = PlayFabEditorSDKTools.GetPlayFabSettings();
                if (playFabSettingsType == null)
                    return;

                var settingProperties = playFabSettingsType.GetProperties();
                foreach (var eachProperty in settingProperties)
                {
                    var lcName = eachProperty.Name.ToLowerInvariant();
                    switch (lcName)
                    {
                        case "titleid":
                            _titleId = eachProperty; break;
                        case "developersecretkey":
                            _developerSecretKey = eachProperty; break;
                        case "requesttype":
                            _webRequestType = eachProperty; break;
                        case "compressapidata":
                            _compressApiData = eachProperty; break;
                        case "requestkeepalive":
                            _keepAlive = eachProperty; break;
                        case "requesttimeout":
                            _timeOut = eachProperty; break;
                    }
                }
            }
        }

        public class PlayFab_EditorSettings
        {
            public static string Name = "PlayFab_EditorSettings";

            private bool _isEdExShown;
            private string _latestSdkVersion;
            private string _latestEdExVersion;
            private DateTime _lastSdkVersionCheck;
            private DateTime _lastEdExVersionCheck;
            public bool isEdExShown { get { return _isEdExShown; } set { _isEdExShown = value; Save(); } }
            public string latestSdkVersion { get { return _latestSdkVersion; } set { _latestSdkVersion = value; _lastSdkVersionCheck = DateTime.UtcNow; Save(); } }
            public string latestEdExVersion { get { return _latestEdExVersion; } set { _latestEdExVersion = value; _lastEdExVersionCheck = DateTime.UtcNow; Save(); } }
            public DateTime lastSdkVersionCheck { get { return _lastSdkVersionCheck; } }
            public DateTime lastEdExVersionCheck { get { return _lastEdExVersionCheck; } }

            public static void Save()
            {
                SaveToEditorPrefs(EditorSettings, Name);
            }
        }

        public class PlayFab_EditorView
        {
            public static string Name = "PlayFab_EditorView";

            private int _currentMainMenu;
            private int _currentSubMenu;
            public int currentMainMenu { get { return _currentMainMenu; } set { _currentMainMenu = value; Save(); } }
            public int currentSubMenu { get { return _currentSubMenu; } set { _currentSubMenu = value; Save(); } }

            private static void Save()
            {
                SaveToEditorPrefs(EditorView, Name);
            }

        }
        #endregion EditorPref data classes

        public static PlayFab_DeveloperAccountDetails AccountDetails;
        public static PlayFab_DeveloperEnvironmentDetails EnvDetails;
        public static PlayFab_SharedSettingsProxy SharedSettings = new PlayFab_SharedSettingsProxy();
        public static PlayFab_EditorSettings EditorSettings;
        public static PlayFab_EditorView EditorView;

        private static string KeyPrefix
        {
            get
            {
                var dataPath = Application.dataPath;
                var lastIndex = dataPath.LastIndexOf('/');
                var secondToLastIndex = dataPath.LastIndexOf('/', lastIndex - 1);
                return dataPath.Substring(secondToLastIndex, lastIndex - secondToLastIndex);
            }
        }

        private static bool _IsDataLoaded = false;
        public static bool IsDataLoaded { get { return _IsDataLoaded && AccountDetails != null && EnvDetails != null && EditorSettings != null && EditorView != null; } }

        public static Title ActiveTitle
        {
            get
            {
                if (AccountDetails != null && AccountDetails.studios != null && AccountDetails.studios.Count > 0 && EnvDetails != null)
                {
                    if (string.IsNullOrEmpty(EnvDetails.selectedStudio) || EnvDetails.selectedStudio == PlayFabEditorHelper.STUDIO_OVERRIDE)
                        return new Title { Id = SharedSettings.TitleId, SecretKey = SharedSettings.DeveloperSecretKey, GameManagerUrl = PlayFabEditorHelper.GAMEMANAGER_URL };

                    if (string.IsNullOrEmpty(EnvDetails.selectedStudio) || string.IsNullOrEmpty(SharedSettings.TitleId))
                        return null;

                    int studioIndex; int titleIndex;
                    if (DoesTitleExistInStudios(SharedSettings.TitleId, out studioIndex, out titleIndex))
                        return AccountDetails.studios[studioIndex].Titles[titleIndex];
                }
                return null;
            }
        }

        private static void SaveToEditorPrefs(object obj, string key)
        {
            var json = JsonWrapper.SerializeObject(obj);
            EditorPrefs.SetString(KeyPrefix + key, json);
        }

        public static void SaveAccountDetails()
        {
            SaveToEditorPrefs(AccountDetails, PlayFab_DeveloperAccountDetails.Name);
        }

        public static void SaveEnvDetails(bool updateToScriptableObj = true)
        {
            SaveToEditorPrefs(EnvDetails, PlayFab_DeveloperEnvironmentDetails.Name);
            if (updateToScriptableObj)
                UpdateScriptableObject();
        }

        private static TResult LoadFromEditorPrefs<TResult>(string key) where TResult : class, new()
        {
            if (!EditorPrefs.HasKey(KeyPrefix + key))
                return new TResult();

            var serialized = EditorPrefs.GetString(KeyPrefix + key);
            var result = JsonWrapper.DeserializeObject<TResult>(serialized);
            if (result != null)
                return JsonWrapper.DeserializeObject<TResult>(serialized);
            return new TResult();
        }

        public static void LoadAllData()
        {
            if (IsDataLoaded)
                return;

            AccountDetails = LoadFromEditorPrefs<PlayFab_DeveloperAccountDetails>(PlayFab_DeveloperAccountDetails.Name);
            EnvDetails = LoadFromEditorPrefs<PlayFab_DeveloperEnvironmentDetails>(PlayFab_DeveloperEnvironmentDetails.Name);
            EditorSettings = LoadFromEditorPrefs<PlayFab_EditorSettings>(PlayFab_EditorSettings.Name);
            EditorView = LoadFromEditorPrefs<PlayFab_EditorView>(PlayFab_EditorView.Name);

            _IsDataLoaded = true;
            PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnDataLoaded, "Complete");
        }

        private static void UpdateScriptableObject()
        {
            var playfabSettingsType = PlayFabEditorSDKTools.GetPlayFabSettings();
            if (playfabSettingsType == null || !PlayFabEditorSDKTools.IsInstalled || !PlayFabEditorSDKTools.isSdkSupported)
                return;

            var props = playfabSettingsType.GetProperties();
            foreach (var property in props)
            {
                switch (property.Name.ToLowerInvariant())
                {
                    case "productionenvironmenturl":
                        property.SetValue(null, PlayFabEditorHelper.TITLE_ENDPOINT, null); break;
                }
            }

            var getSoMethod = playfabSettingsType.GetMethod("GetSharedSettingsObjectPrivate", BindingFlags.NonPublic | BindingFlags.Static);
            if (getSoMethod != null)
            {
                var so = getSoMethod.Invoke(null, new object[0]) as ScriptableObject;
                if (so != null)
                    EditorUtility.SetDirty(so);
            }
            AssetDatabase.SaveAssets();
        }

        public static void RemoveEditorPrefs()
        {
            EditorPrefs.DeleteKey(KeyPrefix + PlayFab_EditorSettings.Name);
            EditorPrefs.DeleteKey(KeyPrefix + PlayFab_DeveloperEnvironmentDetails.Name);
            EditorPrefs.DeleteKey(KeyPrefix + PlayFab_DeveloperAccountDetails.Name);
            EditorPrefs.DeleteKey(KeyPrefix + PlayFab_EditorView.Name);
        }

        public static bool DoesTitleExistInStudios(string searchFor) //out Studio studio
        {
            if (AccountDetails.studios == null)
                return false;
            searchFor = searchFor.ToLower();
            foreach (var studio in AccountDetails.studios)
                if (studio.Titles != null)
                    foreach (var title in studio.Titles)
                        if (title.Id.ToLower() == searchFor)
                            return true;
            return false;
        }

        private static bool DoesTitleExistInStudios(string searchFor, out int studioIndex, out int titleIndex) //out Studio studio
        {
            studioIndex = 0; // corresponds to our _OVERRIDE_
            titleIndex = -1;

            if (AccountDetails.studios == null)
                return false;

            for (var studioIdx = 0; studioIdx < AccountDetails.studios.Count; studioIdx++)
            {
                for (var titleIdx = 0; titleIdx < AccountDetails.studios[studioIdx].Titles.Length; titleIdx++)
                {
                    if (AccountDetails.studios[studioIdx].Titles[titleIdx].Id.ToLower() == searchFor.ToLower())
                    {
                        studioIndex = studioIdx;
                        titleIndex = titleIdx;
                        return true;
                    }
                }
            }

            return false;
        }

        public static void RefreshStudiosList()
        {
            if (AccountDetails.studios != null)
                AccountDetails.studios.Clear();
            PlayFabEditorApi.GetStudios(new GetStudiosRequest(), (getStudioResult) =>
            {
                if (AccountDetails.studios == null)
                    AccountDetails.studios = new List<Studio>();
                foreach (var eachStudio in getStudioResult.Studios)
                    AccountDetails.studios.Add(eachStudio);
                AccountDetails.studios.Add(Studio.OVERRIDE);
                SaveAccountDetails();
            }, PlayFabEditorHelper.SharedErrorCallback);
        }
    }
}
