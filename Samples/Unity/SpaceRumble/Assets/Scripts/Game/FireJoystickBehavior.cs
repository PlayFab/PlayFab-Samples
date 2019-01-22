using UnityEngine;

public class FireJoystickBehavior : MonoBehaviour
{
    public Joystick Joystick;
    public GameObject Projectile;
    public float FireRate = 0.3f;
    public float ProjectileSpeed = 400f;

    private float TimeToNextFire = 0.0f;

    private void Update()
    {
        // Find direction joystick is pointing
        Vector2 fireVector = (Vector3.right * Joystick.Horizontal + Vector3.up * Joystick.Vertical);

        if (fireVector != Vector2.zero)
        {
            // Face the direction of the joystick
            transform.rotation = Quaternion.LookRotation(Vector3.forward, fireVector);

            // Shoot in the direction of the joystick
            Fire();
        }

        // Update firing timier
        TimeToNextFire = Mathf.Max(TimeToNextFire - Time.deltaTime, 0f);
    }

    public void Fire()
    {
        // Enforce firing rate
        if (TimeToNextFire > 0.0f)
        {
            return;
        }

        TimeToNextFire = FireRate;

        // Create the projectile
        GameObject bullet = Instantiate(
            Projectile,
            transform.position + transform.up * 1.2f,
            transform.rotation
            );

        // Match velocity and set firing force
        bullet.GetComponent<Rigidbody2D>().velocity = GetComponent<Rigidbody2D>().velocity;
        bullet.GetComponent<Rigidbody2D>().AddForce(transform.up * ProjectileSpeed);

        // Bullets should match the color of the shooter
        bullet.GetComponent<SpriteRenderer>().color = GetComponent<ShipBehavior>().ShipColor;

        // Don't let the projectile collide with us
        Physics2D.IgnoreCollision(
            GetComponent<Collider2D>(),
            bullet.GetComponent<Collider2D>()
            );

        // Pew pew
        GetComponent<AudioSource>().Play();
    }
}
