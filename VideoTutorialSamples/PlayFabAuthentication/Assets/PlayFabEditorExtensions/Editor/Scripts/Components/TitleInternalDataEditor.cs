using UnityEditor;
using UnityEngine;

namespace PlayFab.PfEditor
{
    public class TitleInternalDataEditor : UnityEditor.EditorWindow
    {
        public string key = string.Empty;
        public string Value = string.Empty;

        public Vector2 scrollPos = Vector2.zero;

        void OnGUI()
        {
            // The actual window code goes here
            using (new UnityHorizontal(PlayFabEditorHelper.uiStyle.GetStyle("gpStyleGray1")))
                GUILayout.Label(string.Format("Editing: {0}", key), PlayFabEditorHelper.uiStyle.GetStyle("orTitle"), GUILayout.MinWidth(EditorGUIUtility.currentViewWidth));

            scrollPos = GUILayout.BeginScrollView(scrollPos, PlayFabEditorHelper.uiStyle.GetStyle("gpStyleGray1"));
            Value = GUILayout.TextArea(Value, PlayFabEditorHelper.uiStyle.GetStyle("editTxt"));
            GUILayout.EndScrollView();


            using (new UnityHorizontal(PlayFabEditorHelper.uiStyle.GetStyle("gpStyleClear")))
            {
                GUILayout.FlexibleSpace();
                if (GUILayout.Button("Save", PlayFabEditorHelper.uiStyle.GetStyle("Button"), GUILayout.MaxWidth(200)))
                {
                    for (int z = 0; z < PlayFabEditorDataMenu.tdInternalViewer.items.Count; z++)
                    {
                        if (PlayFabEditorDataMenu.tdInternalViewer.items[z].Key == key)
                        {
                            PlayFabEditorDataMenu.tdInternalViewer.items[z].Value = Value;
                            PlayFabEditorDataMenu.tdInternalViewer.items[z].isDirty = true;
                        }
                    }
                    Close();

                }
                GUILayout.FlexibleSpace();
            }

            Repaint();
        }

        public void LoadData(string k, string v)
        {
            key = k;
            Value = v;
        }
    }
}
