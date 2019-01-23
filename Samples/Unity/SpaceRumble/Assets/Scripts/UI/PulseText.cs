//--------------------------------------------------------------------------------------
// PulseText.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using UnityEngine;

public class PulseText : MonoBehaviour
{
    public float MinSize = 0.5F;
    public float MaxSize = 1.5F;
    public float Speed = 0.5f;

    private static float Timer = 0.0f;

    void Update()
    {
        Vector3 newScale = transform.localScale;

        newScale.x = Mathf.Lerp(MinSize, MaxSize, Timer);
        newScale.z = newScale.y = newScale.x;

        transform.localScale = newScale;

        Timer += Speed * Time.deltaTime;

        if (Timer > 1.0f)
        {
            float temp = MaxSize;
            MaxSize = MinSize;
            MinSize = temp;
            Timer = 0.0f;
        }
    }
}
