//--------------------------------------------------------------------------------------
// Starfield.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using UnityEngine;

public class Starfield : MonoBehaviour
{
    public int NumberOfStars = 256;
    public int NumberOfLayers = 8;
    public Vector2 ColorRange = new Vector2(32f, 255f);
    public Vector2 SpeedRange = new Vector2(.1f, .9f);

    private ParticleSystem Particles;
    private ParticleSystem.Particle[] Stars;
    private float[] LayerColors;
    private float[] LayerSpeeds;
    private float ColorStep;
    private float SpeedStep;
    private Vector3 LastPosition;
    private Vector3 CurrentPosition;

    public void Reset()
    {
        // Create a new star field
        for (int i = 0; i < NumberOfStars; i++)
        {
            Stars[i].position = Camera.main.ScreenToWorldPoint(
                new Vector3(
                    Random.Range(0, 32767) % Screen.width,
                    Random.Range(0, 32767) % Screen.height,
                    1.0f
                )
            );

            Stars[i].startSize = 0.05f;
            Stars[i].startColor = new Color(1f, 1f, 1f, LayerColors[i % NumberOfLayers] / 255f);
        }

        Particles.SetParticles(Stars, Stars.Length);
    }

    void Start()
    {
        ColorStep = (ColorRange.y - ColorRange.x) / NumberOfLayers;
        SpeedStep = (SpeedRange.y - SpeedRange.x) / NumberOfLayers;

        LayerColors = new float[NumberOfLayers];
        LayerSpeeds = new float[NumberOfLayers];

        for (int i = 0; i < NumberOfLayers; i++)
        {
            LayerColors[i] = ColorRange.x + (ColorStep * (float)i);
            LayerSpeeds[i] = SpeedRange.y - (SpeedStep * (float)i);
        }

        Stars = new ParticleSystem.Particle[NumberOfStars];
        Particles = GetComponent<ParticleSystem>();

        Reset();

        LastPosition = CurrentPosition = Camera.main.transform.position;
    }

    void Update()
    {
        // Calculate how far the camera has moved
        LastPosition = CurrentPosition;
        CurrentPosition = Camera.main.transform.position;

        // If the camera has moved too far, reset the whole field
        Vector2 cameraMovement = new Vector2((CurrentPosition.x - LastPosition.x), (CurrentPosition.y - LastPosition.y));
        float maximumMovementPerUpdate = 10f;

        if (cameraMovement.x * cameraMovement.x + cameraMovement.y * cameraMovement.y > maximumMovementPerUpdate * maximumMovementPerUpdate)
        {
            Reset();
            return;
        }

        // Move all stars based on their parallax layer in relation to the camera movement
        Vector2 screenBounds = Camera.main.ScreenToWorldPoint(new Vector2(Screen.width, Screen.height));
        Vector2 screenOrigin = Camera.main.ScreenToWorldPoint(Vector2.zero);

        for (int i = 0; i < NumberOfStars; i++)
        {
            Vector3 starPosition = Stars[i].position;

            starPosition.x += cameraMovement.x * LayerSpeeds[i % NumberOfLayers];
            starPosition.y += cameraMovement.y * LayerSpeeds[i % NumberOfLayers];

            // wrap the stars around
            if (starPosition.x < screenOrigin.x)
            {
                starPosition.x = screenBounds.x;
                starPosition.y = Camera.main.ScreenToWorldPoint(new Vector3(0, Random.Range(0, 32767) % Screen.height, 0)).y;
            }
            if (starPosition.x > screenBounds.x)
            {
                starPosition.x = screenOrigin.x;
                starPosition.y = Camera.main.ScreenToWorldPoint(new Vector3(0, Random.Range(0, 32767) % Screen.height, 0)).y;
            }
            if (starPosition.y < screenOrigin.y)
            {
                starPosition.x = Camera.main.ScreenToWorldPoint(new Vector3(Random.Range(0, 32767) % Screen.width, 0, 0)).x;
                starPosition.y = screenBounds.y;
            }
            if (starPosition.y > screenBounds.y)
            {
                starPosition.x = Camera.main.ScreenToWorldPoint(new Vector3(Random.Range(0, 32767) % Screen.width, 0, 0)).x;
                starPosition.y = screenOrigin.y;
            }

            Stars[i].position = starPosition;
        }

        Particles.SetParticles(Stars, Stars.Length);
    }
}
