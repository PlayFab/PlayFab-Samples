using UnityEditor;
using UnityEngine;
using System;
using System.Collections.Generic;
using System.IO;
using PlayFab.PfEditor.Json;

namespace PlayFab.PfEditor
{
    [InitializeOnLoad]
    public class PlayFabEditorHelper : UnityEditor.Editor
    {
        #region EDITOR_STRINGS
        public static string EDEX_NAME = "PlayFab_EditorExtensions";
        public static string EDEX_VERSION = "0.0.994";
        public static string EDEX_ROOT = Application.dataPath + "/PlayFabEditorExtensions/Editor";
        public static string DEV_API_ENDPOINT = "https://editor.playfabapi.com";
        public static string TITLE_ENDPOINT = ".playfabapi.com";
        public static string GAMEMANAGER_URL = "https://developer.playfab.com";
        public static string PLAYFAB_SETTINGS_TYPENAME = "PlayFabSettings";
        public static string PLAYFAB_EDEX_MAINFILE = "PlayFabEditor.cs";
        public static string SDK_DOWNLOAD_PATH = "/Resources/PlayFabUnitySdk.unitypackage";
        public static string EDEX_UPGRADE_PATH = "/Resources/PlayFabUnityEditorExtensions.unitypackage";
        public static string EDEX_PACKAGES_PATH = "/Resources/MostRecentPackage.unitypackage";

        public static string CLOUDSCRIPT_FILENAME = ".CloudScript.js";  //prefixed with a '.' to exclude this code from Unity's compiler
        public static string CLOUDSCRIPT_PATH = EDEX_ROOT + "/Resources/" + CLOUDSCRIPT_FILENAME;

        public static string ADMIN_API = "ENABLE_PLAYFABADMIN_API";
        public static string SERVER_API = "ENABLE_PLAYFABSERVER_API";
        public static string CLIENT_API = "DISABLE_PLAYFABCLIENT_API";
        public static string DEBUG_REQUEST_TIMING = "PLAYFAB_REQUEST_TIMING";
        public static string DISABLE_IDFA = "DISABLE_IDFA";
        public static Dictionary<string, string> FLAG_LABELS = new Dictionary<string, string> {
            { ADMIN_API, "ENABLE CLIENT API" },
            { SERVER_API, "ENABLE ADMIN API" },
            { CLIENT_API, "ENABLE SERVER API" },
            { DEBUG_REQUEST_TIMING, "ENABLE REQUEST TIMES" },
            { DISABLE_IDFA, "ENABLE IDFA" },
        };
        public static Dictionary<string, bool> FLAG_INVERSION = new Dictionary<string, bool> {
            { ADMIN_API, true },
            { SERVER_API, false },
            { CLIENT_API, false },
            { DEBUG_REQUEST_TIMING, false },
            { DISABLE_IDFA, false },
        };

        public static string DEFAULT_SDK_LOCATION = "Assets/PlayFabSdk";
        public static string STUDIO_OVERRIDE = "_OVERRIDE_";

        public static string MSG_SPIN_BLOCK = "{\"useSpinner\":true, \"blockUi\":true }";
        #endregion

        private static GUISkin _uiStyle;
        public static GUISkin uiStyle
        {
            get
            {
                if (_uiStyle != null)
                    return _uiStyle;
                _uiStyle = GetUiStyle();
                return _uiStyle;
            }
        }

        static PlayFabEditorHelper()
        {
            // scan for changes to the editor folder / structure.
            if (uiStyle == null)
            {
                string[] rootFiles = new string[0];
                bool relocatedEdEx = false;
                _uiStyle = null;

                try
                {
                    if (PlayFabEditorDataService.EnvDetails != null && !string.IsNullOrEmpty(PlayFabEditorDataService.EnvDetails.edexPath))
                        EDEX_ROOT = PlayFabEditorDataService.EnvDetails.edexPath;
                    rootFiles = Directory.GetDirectories(EDEX_ROOT);
                }
                catch
                {

                    if (rootFiles.Length == 0)
                    {
                        // this probably means the editor folder was moved.
                        // see if we can locate the moved root and reload the assets

                        var movedRootFiles = Directory.GetFiles(Application.dataPath, PLAYFAB_EDEX_MAINFILE, SearchOption.AllDirectories);
                        if (movedRootFiles.Length > 0)
                        {
                            relocatedEdEx = true;
                            EDEX_ROOT = movedRootFiles[0].Substring(0, movedRootFiles[0].IndexOf(PLAYFAB_EDEX_MAINFILE) - 1);
                            PlayFabEditorDataService.EnvDetails.edexPath = EDEX_ROOT;
                            PlayFabEditorDataService.SaveEnvDetails();
                        }
                    }
                }
                finally
                {
                    if (relocatedEdEx && rootFiles.Length == 0)
                    {
                        Debug.Log("Found new EdEx root: " + EDEX_ROOT);
                    }
                    else if (rootFiles.Length == 0)
                    {
                        Debug.Log("Could not relocate the PlayFab Editor Extension");
                        EDEX_ROOT = string.Empty;
                    }
                }
            }
        }

        private static GUISkin GetUiStyle()
        {
            var searchRoot = string.IsNullOrEmpty(EDEX_ROOT) ? Application.dataPath : EDEX_ROOT;
            var pfGuiPaths = Directory.GetFiles(searchRoot, "PlayFabStyles.guiskin", SearchOption.AllDirectories);
            foreach (var eachPath in pfGuiPaths)
            {
                var loadPath = eachPath.Substring(eachPath.IndexOf("Assets/"));
                return (GUISkin)AssetDatabase.LoadAssetAtPath(loadPath, typeof(GUISkin));
            }
            return null;
        }

        public static void SharedErrorCallback(EditorModels.PlayFabError error)
        {
            PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnError, error.ErrorMessage);
        }

        public static void SharedErrorCallback(string error)
        {
            PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnError, error);
        }

        protected internal static EditorModels.PlayFabError GeneratePlayFabError(string json, object customData = null)
        {
            JsonObject errorDict = null;
            Dictionary<string, List<string>> errorDetails = null;
            try
            {
                //deserialize the error
                errorDict = JsonWrapper.DeserializeObject<JsonObject>(json, PlayFabEditorUtil.ApiSerializerStrategy);


                if (errorDict.ContainsKey("errorDetails"))
                {
                    var ed = JsonWrapper.DeserializeObject<Dictionary<string, List<string>>>(errorDict["errorDetails"].ToString());
                    errorDetails = ed;
                }
            }
            catch (Exception e)
            {
                return new EditorModels.PlayFabError()
                {
                    ErrorMessage = e.Message
                };
            }

            //create new error object
            return new EditorModels.PlayFabError
            {
                HttpCode = errorDict.ContainsKey("code") ? Convert.ToInt32(errorDict["code"]) : 400,
                HttpStatus = errorDict.ContainsKey("status")
                    ? (string)errorDict["status"]
                    : "BadRequest",
                Error = errorDict.ContainsKey("errorCode")
                    ? (EditorModels.PlayFabErrorCode)Convert.ToInt32(errorDict["errorCode"])
                    : EditorModels.PlayFabErrorCode.ServiceUnavailable,
                ErrorMessage = errorDict.ContainsKey("errorMessage")
                    ? (string)errorDict["errorMessage"]
                    : string.Empty,
                ErrorDetails = errorDetails,
                CustomData = customData ?? new object()
            };
        }

        #region unused, but could be useful

        /// <summary>
        /// Tool to create a color background texture
        /// </summary>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="col"></param>
        /// <returns>Texture2D</returns>
        public static Texture2D MakeTex(int width, int height, Color col)
        {
            var pix = new Color[width * height];

            for (var i = 0; i < pix.Length; i++)
                pix[i] = col;

            var result = new Texture2D(width, height);
            result.SetPixels(pix);
            result.Apply();

            return result;
        }

        public static Vector3 GetColorVector(int colorValue)
        {
            return new Vector3((colorValue / 255f), (colorValue / 255f), (colorValue / 255f));
        }
        #endregion
    }
}
