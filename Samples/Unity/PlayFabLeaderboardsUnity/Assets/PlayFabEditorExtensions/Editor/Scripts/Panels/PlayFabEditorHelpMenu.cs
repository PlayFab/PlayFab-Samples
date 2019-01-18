using UnityEditor;
using UnityEngine;

namespace PlayFab.PfEditor
{
    public class PlayFabEditorHelpMenu : UnityEditor.Editor
    {
        public static float buttonWidth = 200;
        public static Vector2 scrollPos = Vector2.zero;

        public static void DrawHelpPanel()
        {
            scrollPos = GUILayout.BeginScrollView(scrollPos, PlayFabEditorHelper.uiStyle.GetStyle("gpStyleGray1"));
            buttonWidth = EditorGUIUtility.currentViewWidth > 400 ? EditorGUIUtility.currentViewWidth / 2 : 200;

            using (new UnityVertical())
            {
                EditorGUILayout.LabelField("LEARN PLAYFAB:", PlayFabEditorHelper.uiStyle.GetStyle("labelStyle"));

                using (new UnityHorizontal(PlayFabEditorHelper.uiStyle.GetStyle("gpStyleClear")))
                {
                    GUILayout.FlexibleSpace();

                    if (GUILayout.Button("BEGINNERS GUIDE", PlayFabEditorHelper.uiStyle.GetStyle("Button"), GUILayout.MinHeight(32), GUILayout.Width(buttonWidth)))
                    {
                        Application.OpenURL("https://api.playfab.com/docs/beginners-guide");
                    }

                    GUILayout.FlexibleSpace();
                }

                using (new UnityHorizontal(PlayFabEditorHelper.uiStyle.GetStyle("gpStyleClear")))
                {
                    GUILayout.FlexibleSpace();

                    if (GUILayout.Button("RECIPES", PlayFabEditorHelper.uiStyle.GetStyle("Button"), GUILayout.MinHeight(32), GUILayout.Width(buttonWidth)))
                    {
                        Application.OpenURL("https://api.playfab.com/docs/recipe-index");
                    }

                    GUILayout.FlexibleSpace();
                }

                using (new UnityHorizontal(PlayFabEditorHelper.uiStyle.GetStyle("gpStyleClear")))
                {
                    GUILayout.FlexibleSpace();

                    if (GUILayout.Button("TUTORIALS", PlayFabEditorHelper.uiStyle.GetStyle("Button"), GUILayout.MinHeight(32), GUILayout.Width(buttonWidth)))
                    {
                        Application.OpenURL("https://api.playfab.com/docs/tutorials");
                    }

                    GUILayout.FlexibleSpace();
                }

                using (new UnityHorizontal(PlayFabEditorHelper.uiStyle.GetStyle("gpStyleClear")))
                {
                    GUILayout.FlexibleSpace();

                    if (GUILayout.Button("API REFERENCE", PlayFabEditorHelper.uiStyle.GetStyle("Button"), GUILayout.MinHeight(32), GUILayout.Width(buttonWidth)))
                    {
                        Application.OpenURL("https://api.playfab.com/documentation");
                    }

                    GUILayout.FlexibleSpace();
                }
            }

            using (new UnityVertical())
            {
                EditorGUILayout.LabelField("TROUBLESHOOTING:", PlayFabEditorHelper.uiStyle.GetStyle("labelStyle"));

                using (new UnityHorizontal(PlayFabEditorHelper.uiStyle.GetStyle("gpStyleClear")))
                {
                    GUILayout.FlexibleSpace();

                    if (GUILayout.Button("ASK QUESTIONS", PlayFabEditorHelper.uiStyle.GetStyle("Button"), GUILayout.MinHeight(32), GUILayout.Width(buttonWidth)))
                    {
                        Application.OpenURL("https://community.playfab.com/index.html");
                    }

                    GUILayout.FlexibleSpace();
                }

                using (new UnityHorizontal(PlayFabEditorHelper.uiStyle.GetStyle("gpStyleClear")))
                {
                    GUILayout.FlexibleSpace();

                    if (GUILayout.Button("VIEW SERVICE AVAILABILITY", PlayFabEditorHelper.uiStyle.GetStyle("Button"), GUILayout.MinHeight(32), GUILayout.Width(buttonWidth)))
                    {
                        Application.OpenURL("http://status.playfab.com/");
                    }

                    GUILayout.FlexibleSpace();
                }
            }
            GUILayout.EndScrollView();
        }
    }
}
