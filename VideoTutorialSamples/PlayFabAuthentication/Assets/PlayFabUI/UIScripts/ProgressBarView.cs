namespace PlayFab.UI
{
    using System;
    using UnityEngine;
    using UnityEngine.UI;

    [RequireComponent(typeof(Slider))]
    public class ProgressBarView : MonoBehaviour
    {
        public Slider Slider;
        public Text Label;
        public TweenTypes TweenType;
        public AnimationCurve Curve;

        private float _progress = 0;
        private bool _isAnimating = false;
        private float _start;
        private float _end;
        private Action _callback;

        private float _t;

        public void Awake()
        {
            if(Slider == null)
            {
                Slider = GetComponent<Slider>();
            }
        }

        public void UpdateProgress(float progress)
        {
            Slider.value = progress;
        }

        public void AnimateProgress(float start, float end)
        {
            _t = 0f;
            _start = start;
            _end = end;
            _isAnimating = true;
        }

        public void AnimateProgress(float start, float end, Action callback)
        {
            _callback = callback;
            AnimateProgress(start, end);
        }

        public void UpdateLabel(string label)
        {
            Label.gameObject.SetActive(true);
            Label.text = label;
        }

        // Update is called once per frame
        void Update()
        {
            if (_isAnimating)
            {
                _t += Time.deltaTime;
                switch (TweenType)
                {
                    case TweenTypes.Linear:
                        if (Slider.value < 1)
                        {
                            Slider.value = Tween.Linear(_start, _end, _t);
                        }
                    break;

                    case TweenTypes.EaseIn:
                        if(Slider.value < 1)
                        {
                            Slider.value = Tween.EaseIn(_start, _end, _t);
                        }
                    break;

                    case TweenTypes.Curve:
                        if (Slider.value < 1)
                        {
                            Slider.value = Tween.Curve(_start, _end, Curve, _t);
                        }
                        break;
                }

                if(Slider.value >= 1)
                {
                    if(_callback != null)
                    {
                        _isAnimating = false;
                        _callback();
                    }
                }
            }
        }
    }

}

namespace PlayFab.UI.Editor
{
    using UnityEngine;
    using UnityEngine.UI;
    using UnityEditor;

    [CustomEditor(typeof(ProgressBarView))]
    public class LevelScriptEditor : Editor
    {
        public override void OnInspectorGUI()
        {
            ProgressBarView _target = (ProgressBarView)target;
            _target.Slider = (Slider) EditorGUILayout.ObjectField("Slider",_target.Slider, typeof(Slider), true );
            _target.Label = (Text)EditorGUILayout.ObjectField("Label", _target.Label, typeof(Text), true);
            _target.TweenType = (TweenTypes) EditorGUILayout.EnumPopup("Tween Type", _target.TweenType);
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
