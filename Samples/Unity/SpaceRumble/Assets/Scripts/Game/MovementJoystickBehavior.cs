//--------------------------------------------------------------------------------------
// MovementJoystickBehavior.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using UnityEngine;

public class MovementJoystickBehavior : MonoBehaviour 
{
    public float Thrust = 50f;
    public Joystick Joystick;

    private void Update()
    {
        // Find out which way the joystick is pointing
        Vector2 moveVector = (Vector3.right * Joystick.Horizontal + Vector3.up * Joystick.Vertical);

        if (moveVector != Vector2.zero)
        {
            // Face the direction of the joystick
            transform.rotation = Quaternion.LookRotation(Vector3.forward, moveVector);

            // Move in the direction of the joystick
            gameObject.GetComponent<Rigidbody2D>().AddForce(moveVector * Thrust);
        }

        // Show the engine flare if there is controller input
        gameObject.GetComponent<ShipBehavior>().FlareEngine(System.Math.Abs(Joystick.Horizontal) > 0 && System.Math.Abs(Joystick.Vertical) > 0);
    }
}
