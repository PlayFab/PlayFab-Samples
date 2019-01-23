//--------------------------------------------------------------------------------------
// FixedScroll.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using UnityEngine;

public class FixedScroll : MonoBehaviour
{
    public float YScrollSpeed = 0.025f;
    public float XScrollSpeed = 0.025f;

    public Vector2 CameraXBounds = new Vector2(-30f, 30f);
    public Vector2 CameraYBounds = new Vector2(-30f, 30f);

    Transform theCamera;

    void Start()
    {
        theCamera = Camera.main.transform;
    }

    void Update()
    {
        float newX = theCamera.position.x + XScrollSpeed;
        float newY = theCamera.position.y + YScrollSpeed;

        if (newX < CameraXBounds.x || newX > CameraXBounds.y)
        {
            XScrollSpeed *= -1;
        }

        if (newY < CameraYBounds.x || newY > CameraYBounds.y)
        {
            YScrollSpeed *= -1;
        }

        theCamera.position = new Vector3(newX, newY, theCamera.position.z);
    }
}
