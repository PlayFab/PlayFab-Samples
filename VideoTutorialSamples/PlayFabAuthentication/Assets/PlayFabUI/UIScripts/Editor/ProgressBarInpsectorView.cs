namespace PlayFab.UI.Editor
{
    using UnityEngine;
    using UnityEngine.UI;
    using UnityEditor;

    [CustomEditor(typeof(ProgressBarView))]
    public class ProgressBarInspectorView : Editor
    {
        public override void OnInspectorGUI()
        {
            ProgressBarView _target = (ProgressBarView)target;
            _target.Slider = (Slider)EditorGUILayout.ObjectField("Slider", _target.Slider, typeof(Slider), true);
            _target.Label = (Text)EditorGUILayout.ObjectField("Label", _target.Label, typeof(Text), true);
            _target.TweenType = (TweenTypes)EditorGUILayout.EnumPopup("Tween Type", _target.TweenType);
            if (_target.TweenType == TweenTypes.Curve)
            {
                _target.Curve = EditorGUILayout.CurveField("Curve", _target.Curve);
            }

            //_target.Slider = EditorGUILayout.Slider()
            //_target.Label;
            //_target.TweenType;
            //_target.Curve;
        }
    }
}