//--------------------------------------------------------------------------------------
// ShipBehavior.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using UnityEngine;

public class ShipBehavior : MonoBehaviour
{
    public Color ShipColor;
    public ParticleSystem EngineFlare;
    public float MaxVelocity = 20f;

    void Start()
    {
        // Don't let physics 'spin' the ship
        GetComponent<Rigidbody2D>().freezeRotation = true;

        // Set the color of the overlay
        // Overlay is the 2nd child
        transform.GetChild(1).GetComponent<SpriteRenderer>().color = ShipColor;
    }

    void Update()
    {
        // Keep the camera directly over the ship
        Camera.main.transform.position = new Vector3(
            transform.position.x,
            transform.position.y,
            Camera.main.transform.position.z
            );

        // Clamp the velocity of the ship
        Rigidbody2D rigidBody = GetComponent<Rigidbody2D>();

        if (rigidBody.velocity.sqrMagnitude > MaxVelocity)
        {
            // Smoothness of the slowdown is controlled by the 0.99f, 
            // 0.5f is less smooth, 0.9999f is more smooth
            rigidBody.velocity *= 0.99f;
        }
    }

    public void FlareEngine(bool on)
    {
        // Controller calls this to tell us if the engine should be on
        if (on && !EngineFlare.isPlaying)
        {
            EngineFlare.Play();
        }

        if (!on && EngineFlare.isPlaying)
        {
            EngineFlare.Stop();
        }
    }
}
