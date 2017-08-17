using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using PlayFab.PfEditor.Json;
using PlayFab.PfEditor.EditorModels;

#if UNITY_5_4_OR_NEWER
using UnityEngine.Networking;
#else
using UnityEngine.Experimental.Networking;
#endif

namespace PlayFab.PfEditor
{
    public class PlayFabEditorHttp : UnityEditor.Editor
    {
        internal static void MakeDownloadCall(string url, Action<string> resultCallback)
        {
            var www = new WWW(url);
            PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnHttpReq, url, PlayFabEditorHelper.MSG_SPIN_BLOCK);
            EditorCoroutine.Start(PostDownload(www, (response) => { WriteResultFile(url, resultCallback, response); }, PlayFabEditorHelper.SharedErrorCallback), www);
        }

        private static void WriteResultFile(string url, Action<string> resultCallback, byte[] response)
        {
            PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnHttpRes, url);

            string fileName;
            if (url.IndexOf("unity-edex") > -1)
                fileName = PlayFabEditorHelper.EDEX_UPGRADE_PATH;
            else if (url.IndexOf("unity-via-edex") > -1)
                fileName = PlayFabEditorHelper.SDK_DOWNLOAD_PATH;
            else
                fileName = PlayFabEditorHelper.EDEX_PACKAGES_PATH;

            var fileSaveLocation = PlayFabEditorHelper.EDEX_ROOT + fileName;
            var fileSaveDirectory = Path.GetDirectoryName(fileSaveLocation);
            Debug.Log("Saving " + response.Length + " bytes to: " + fileSaveLocation);
            if (!Directory.Exists(fileSaveDirectory))
                Directory.CreateDirectory(fileSaveDirectory);
            File.WriteAllBytes(fileSaveLocation, response);
            resultCallback(fileSaveLocation);
        }

        internal static void MakeApiCall<TRequestType, TResultType>(string api, string apiEndpoint, TRequestType request, Action<TResultType> resultCallback, Action<EditorModels.PlayFabError> errorCallback) where TResultType : class
        {
            var url = apiEndpoint + api;
            var req = JsonWrapper.SerializeObject(request, PlayFabEditorUtil.ApiSerializerStrategy);
            //Set headers
            var headers = new Dictionary<string, string>
            {
                {"Content-Type", "application/json"},
                {"X-ReportErrorAsSuccess", "true"},
                {"X-PlayFabSDK", string.Format("{0}_{1}", PlayFabEditorHelper.EDEX_NAME, PlayFabEditorHelper.EDEX_VERSION)}
            };

            if (api.Contains("/Server/") || api.Contains("/Admin/"))
            {
                if (PlayFabEditorDataService.ActiveTitle == null || string.IsNullOrEmpty(PlayFabEditorDataService.ActiveTitle.SecretKey))
                {
                    PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnError, "Must have PlayFabSettings.DeveloperSecretKey set to call this method");
                    return;
                }

                headers.Add("X-SecretKey", PlayFabEditorDataService.ActiveTitle.SecretKey);
            }

            //Encode Payload
            var payload = System.Text.Encoding.UTF8.GetBytes(req.Trim());
            var www = new WWW(url, payload, headers);
            PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnHttpReq, api, PlayFabEditorHelper.MSG_SPIN_BLOCK);

            EditorCoroutine.Start(Post(www, (response) => { OnWwwSuccess(api, resultCallback, errorCallback, response); }, (error) => { OnWwwError(errorCallback, error); }), www);
        }

        private static void OnWwwSuccess<TResultType>(string api, Action<TResultType> resultCallback, Action<PlayFab.PfEditor.EditorModels.PlayFabError> errorCallback, string response) where TResultType : class
        {
            var httpResult = JsonWrapper.DeserializeObject<HttpResponseObject>(response, PlayFabEditorUtil.ApiSerializerStrategy);
            if (httpResult.code != 200)
            {
                OnWwwError(errorCallback, response);
                return;
            }

            PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnHttpRes, api);
            if (resultCallback == null)
                return;

            TResultType result = null;
            var resultAssigned = false;
            try
            {
                var dataJson = JsonWrapper.SerializeObject(httpResult.data, PlayFabEditorUtil.ApiSerializerStrategy);
                result = JsonWrapper.DeserializeObject<TResultType>(dataJson, PlayFabEditorUtil.ApiSerializerStrategy);
                resultAssigned = true;
            }
            catch (Exception e)
            {
                PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnError, e.Message);
            }
            if (resultAssigned)
                resultCallback(result);
        }

        private static void OnWwwError(Action<PlayFab.PfEditor.EditorModels.PlayFabError> errorCallback, string error)
        {
            if (errorCallback != null)
                errorCallback(PlayFabEditorHelper.GeneratePlayFabError(error));
            else
                PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnError, error);
        }

        internal static void MakeGitHubApiCall(string url, Action<string> resultCallback)
        {
            var www = new WWW(url);
            EditorCoroutine.Start(Post(www, (response) => { OnGitHubSuccess(resultCallback, response); }, PlayFabEditorHelper.SharedErrorCallback), www);
        }

        private static void OnGitHubSuccess(Action<string> resultCallback, string response)
        {
            if (resultCallback == null)
                return;

            var jsonResponse = JsonWrapper.DeserializeObject<List<object>>(response);
            if (jsonResponse == null || jsonResponse.Count == 0)
                return;

            // list seems to come back in ascending order (oldest -> newest)
            var latestSdkTag = (JsonObject)jsonResponse[jsonResponse.Count - 1];
            object tag;
            if (latestSdkTag.TryGetValue("ref", out tag))
            {
                var startIndex = tag.ToString().LastIndexOf('/') + 1;
                var length = tag.ToString().Length - startIndex;
                resultCallback(tag.ToString().Substring(startIndex, length));
            }
            else
            {
                resultCallback(null);
            }
        }

        private static IEnumerator Post(WWW www, Action<string> callBack, Action<string> errorCallback)
        {
            yield return www;

            if (!string.IsNullOrEmpty(www.error))
                errorCallback(www.error);
            else
                callBack(www.text);
        }

        private static IEnumerator PostDownload(WWW www, Action<byte[]> callBack, Action<string> errorCallback)
        {
            yield return www;

            if (!string.IsNullOrEmpty(www.error))
                errorCallback(www.error);
            else
                callBack(www.bytes);
        }
    }
}
