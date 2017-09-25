namespace PlayFab.UI
{
    using UnityEngine;
    public class Tween 
    {
        public static float Linear(float start, float end, float delta)
        {
            return Mathf.Lerp(start, end, delta);
        }

        public static float EaseIn(float start, float end, float delta)
        {
            return Mathf.Lerp(start, end, delta * delta);
        }

        public static float Curve(float start, float end, AnimationCurve curve,float delta)
        {
            return (end - start) * curve.Evaluate(delta) + start;
        }

    }

    public enum TweenTypes
    {
        Linear,
        EaseIn,
        Curve
    }
}