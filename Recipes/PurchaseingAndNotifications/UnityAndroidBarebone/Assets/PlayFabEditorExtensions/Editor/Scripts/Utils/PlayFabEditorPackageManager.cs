using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;

namespace PlayFab.PfEditor
{
    [InitializeOnLoad]
    public class PlayFabEditorPackageManager : UnityEditor.Editor {
        //TODO change these vars after we disucss how to organize these moving forward.
        public static bool AndroidPushPlugin = false;

        static bool _androidPushPluginPreviousState = false;


//        public void FetchPackageDetails()
//        {
//        }
//
//            


#region ctor
        static PlayFabEditorPackageManager()
        {
            ScanForInstalledPackages();
        }

#endregion




        public static void Update()
        {
            if(AndroidPushPlugin != _androidPushPluginPreviousState)
            {
                if(!AndroidPushPlugin)
                {
                    //uninstall
                    _androidPushPluginPreviousState = AndroidPushPlugin;
                    RemoveEdExPackage("AndroidPushPlugin");
                }
                else
                {
                    //install
                    _androidPushPluginPreviousState = AndroidPushPlugin;
                    InstallEdExPackage("AndroidPushPlugin");
                }
            }
        }

        public static void InstallEdExPackage(string key)
        {
            //TODO update this to work with a standardized key nomenclature

            if( EditorUtility.DisplayDialog("Confirm Package Installation", "This will install the " + key + " package.", "Confirm", "Cancel"))
            {
                PlayFabEditorHttp.MakeDownloadCall("https://api.playfab.com/sdks/download/android-push50-via-edex", (fileName) => 
                {
                    AssetDatabase.ImportPackage(fileName, true); 
                    Debug.Log(string.Format("EdEx: {0} Installation Complete", key));
                });
            }
            else
            {
                //TODO this will need to be updated when we have several plugins.
                AndroidPushPlugin = false;
                _androidPushPluginPreviousState = false;
            }
        }

        public static void RemoveEdExPackage(string key)
        {
            switch(key)
            {
                default:
                    if( EditorUtility.DisplayDialog("Confirm Pacakge Removal", "This will remove the " + key + " package.", "Confirm", "Cancel"))
                    {
                        RemoveAndroidPushPlugin();
                        //Debug.Log(string.Format("EdEx: Removed {0} Package", key));
                    }
                    else
                    {
                        //TODO this will need to be updated when we have several plugins.
                        AndroidPushPlugin = true;
                        _androidPushPluginPreviousState = true;
                    }
                break;
            }
        }



        #region Helpers
            static void RemoveAndroidPushPlugin()
            {
                try
                {
                    var androidPluginPath = Application.dataPath + "/Plugins/Android/";
                    List<string> filesToRemove = new List<string>(){
                        "PlayFab",
                        "PlayFabAdInfo.aar",
                        "PlayFabUnityAndroid.aar"    
                    };

                    foreach(var file in filesToRemove)
                    {
                        if(FileUtil.DeleteFileOrDirectory(androidPluginPath + file))
                        {
                            Debug.Log(androidPluginPath + file + " -- Removed.");
                        }
                        else
                        {
                            Debug.LogWarning(androidPluginPath + file + " -- Could not be found.");
                        }
                    }

                if( EditorUtility.DisplayDialog("Confirm Removal of Android Libraries", "Do you also want to remove the Android .aar libraries are used by the PlayFab Plugin? Discretion is advised, these files may also be shared among other unrelated plugins. ", "Yes", "No"))
                    {
                        List<string> optionalFilesToRemove = new List<string>(){
                            "appcompat-v7*.aar",
                            "play-services-base*.aar",
                            "play-services-basement*.aar",
                            "play-services-gcm*.aar",
                            "play-services-iid*.aar",
                            "support-v4*.aar"
                        };

                        //using wild card here to get variations on versions if they exist.
                        DirectoryInfo pluginDir = new DirectoryInfo(androidPluginPath);
                        if(pluginDir != null)
                        {
                            foreach(var opt in optionalFilesToRemove)
                            {
                                //TODO ensure that we only want to search the top of the dir
                                var files = pluginDir.GetFiles(opt, SearchOption.TopDirectoryOnly);
                                foreach(var file in files)
                                {
                                    if(FileUtil.DeleteFileOrDirectory(androidPluginPath + file.Name))
                                    {
                                        Debug.Log(androidPluginPath + file + " -- Removed.");
                                    }
                                    else
                                    {
                                        Debug.LogWarning(androidPluginPath + file + " -- Could not be found.");
                                    }
                                }
                            }
                        }
                    }

                    if( EditorUtility.DisplayDialog("Confirm Removal of AndroidManifest.xml", "Do you want to also remove AndroidManifest.xml? Discretion is advised, as this may impact the performance of your Android builds.", "Yes", "No"))
                    {
                        FileUtil.DeleteFileOrDirectory(Application.dataPath + "/Plugins/Android/AndroidManifest.xml");
                    }    

                    PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnSuccess, "Android Push Plugin Removed");
                    AssetDatabase.Refresh();

                }
                catch(Exception ex)
                {
                    PlayFabEditor.RaiseStateUpdate(PlayFabEditor.EdExStates.OnError, ex.Message); 
                }
            }

            //only scans for >5.0 plugins
            static void ScanForInstalledPackages()
            {
                //TODO will need to update once whe have more than 1 package.
                try
                {
                    DirectoryInfo pluginDir = new DirectoryInfo(Application.dataPath + "/Plugins/Android/");
                    var files = pluginDir.GetFiles("PlayFabUnityAndroid.aar", SearchOption.TopDirectoryOnly);
                    if(files.Length > 0)
                    {
                        AndroidPushPlugin = true;
                        _androidPushPluginPreviousState = true;
                    }
               }
               catch
               {
                    AndroidPushPlugin = false;
                    _androidPushPluginPreviousState = false;
               }
            }
        #endregion

       
    }
}
