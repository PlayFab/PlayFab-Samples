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


