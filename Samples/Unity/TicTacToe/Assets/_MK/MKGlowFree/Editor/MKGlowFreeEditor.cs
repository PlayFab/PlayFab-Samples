//////////////////////////////////////////////////////
// MK Glow Free	    			                    //
//					                                //
// Created by Michael Kremmel                       //
// www.michaelkremmel.de | www.michaelkremmel.store //
// Copyright © 2017 All rights reserved.            //
//////////////////////////////////////////////////////
#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using System;
using System.Reflection;

namespace MK.Glow
{
    [CustomEditor(typeof(MKGlowFree))]
    public class MKGlowEditor : Editor
    {
        public static class GuiStyles
        {
            public static GUIStyle header = new GUIStyle("ShurikenModuleTitle")
            {
                font = (new GUIStyle("Label")).font,
                border = new RectOffset(15, 7, 4, 4),
                fixedHeight = 22,
                contentOffset = new Vector2(20f, -2f),
            };

            public static GUIStyle headerCheckbox = new GUIStyle("ShurikenCheckMark");
            public static GUIStyle headerCheckboxMixed = new GUIStyle("ShurikenCheckMarkMixed");
        }

        private const string m_Style = "box";
#pragma warning disable CS0612 // Type or member is obsolete
        private ColorPickerHDRConfig colorPickerHDRConfig = new ColorPickerHDRConfig(0f, 99f, 1 / 99f, 3f);
#pragma warning restore CS0612 // Type or member is obsolete
        private static GUIContent glowTintLabel = new GUIContent("Glow Tint", "The glows coloration in full screen mode(only FullscreenGlowType)");

        private SerializedProperty glowType;
        private SerializedProperty samples;
        private SerializedProperty blurSpreadInner;
        private SerializedProperty blurIterations;
        private SerializedProperty glowIntensityInner;
        private SerializedProperty glowTint;
        private SerializedProperty glowLayer;
        private SerializedProperty threshold;

        private SerializedProperty showMainBehavior;
        private SerializedProperty showInnerGlowBehavior;

        //private SerializedProperty debugMode;
        //private SerializedProperty rtFormat;

        [MenuItem("Window/MK/Glow/Add MK Glow Free To Selection")]
        private static void AddMKGlowToObject()
        {
            foreach (GameObject obj in Selection.gameObjects)
            {
                if (obj.GetComponent<MKGlowFree>() == null)
                    obj.AddComponent<MKGlowFree>();
            }
        }

        private void OnEnable()
        {
            samples = serializedObject.FindProperty("samples");
            blurSpreadInner = serializedObject.FindProperty("blurSpreadInner");
            blurIterations = serializedObject.FindProperty("blurIterations");
            glowIntensityInner = serializedObject.FindProperty("glowIntensityInner");
            glowTint = serializedObject.FindProperty("glowTint");
            glowType = serializedObject.FindProperty("glowType");
            glowLayer = serializedObject.FindProperty("glowLayer");
            threshold = serializedObject.FindProperty("threshold");

            showInnerGlowBehavior = serializedObject.FindProperty("showInnerGlowBehavior");
            showMainBehavior = serializedObject.FindProperty("showMainBehavior");

            //debugMode = serializedObject.FindProperty("debugMode");
            //rtFormat = serializedObject.FindProperty("rtFormat");
        }

        public override void OnInspectorGUI()
        {
            MKGlowFree mkGlow = (MKGlowFree)target;

            EditorGUI.BeginChangeCheck();

            serializedObject.Update();

            //EditorGUILayout.LabelField("_Debug_", GuiStyles.header);
            //EditorGUILayout.PropertyField(debugMode);
            //EditorGUILayout.PropertyField(rtFormat);

            if (HandleBehavior("Main", ref showMainBehavior))
            {
                EditorGUILayout.PropertyField(glowType);
                if (glowType.enumValueIndex == 0)
                {
                    EditorGUILayout.PropertyField(glowLayer);
                }
                EditorGUILayout.IntSlider(samples, 2, 4, "Samples");
                EditorGUILayout.IntSlider(blurIterations, 1, 10, "Iterations");
                if (glowType.enumValueIndex == 2)
                {
                    threshold.floatValue = EditorGUILayout.FloatField("Threshold", threshold.floatValue);
                }
#pragma warning disable CS0618 // Type or member is obsolete
                glowTint.colorValue = EditorGUILayout.ColorField(glowTintLabel, glowTint.colorValue, false, false, false, colorPickerHDRConfig);
#pragma warning restore CS0618 // Type or member is obsolete
            }
            if (HandleBehavior("Glow Inner", ref showInnerGlowBehavior))
            {
                EditorGUILayout.Slider(blurSpreadInner, 0.0f, 2.0f, "Spread Inner");
                EditorGUILayout.Slider(glowIntensityInner, 0.0f, 1.0f, "Intensity");
            }

            serializedObject.ApplyModifiedProperties();

            EditorGUI.EndChangeCheck();
        }

        private bool HandleBehavior(string title, ref SerializedProperty behavior)
        {
            EditorGUI.showMixedValue = behavior.hasMultipleDifferentValues;
            var rect = GUILayoutUtility.GetRect(16f, 22f, GuiStyles.header);
            rect.x -= 10;
            rect.width += 10;
            var e = Event.current;

            GUI.Box(rect, title, GuiStyles.header);

            var foldoutRect = new Rect(EditorGUIUtility.currentViewWidth * 0.5f, rect.y + 2, 13f, 13f);
            if (behavior.hasMultipleDifferentValues)
            {
                foldoutRect.x -= 13;
                foldoutRect.y -= 2;
            }

            EditorGUI.BeginChangeCheck();
            if (e.type == EventType.MouseDown)
            {
                if (rect.Contains(e.mousePosition))
                {
                    if (behavior.hasMultipleDifferentValues)
                        behavior.boolValue = false;
                    else
                        behavior.boolValue = !behavior.boolValue;
                    e.Use();
                }
            }
            if (EditorGUI.EndChangeCheck())
            {
                if (behavior.boolValue)
                    Undo.RegisterCompleteObjectUndo(this, behavior.displayName + " Show");
                else
                    Undo.RegisterCompleteObjectUndo(this, behavior.displayName + " Hide");
            }

            EditorGUI.showMixedValue = false;

            if (e.type == EventType.Repaint && behavior.hasMultipleDifferentValues)
                EditorStyles.radioButton.Draw(foldoutRect, "", false, false, true, false);
            else
                EditorGUI.Foldout(foldoutRect, behavior.boolValue, "");

            if (behavior.hasMultipleDifferentValues)
                return true;
            else
                return behavior.boolValue;
        }
    }
}
#endif