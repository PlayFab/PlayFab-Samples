//--------------------------------------------------------------------------------------
// TurretBehavior.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using UnityEngine;

public class TurretBehavior : MonoBehaviour
{
    public Color ShipColor;
    public GameObject Projectile;
    public GameObject Target;
    public GameObject ExplosionPrefab;
    public GameObject ExplosionSmokePrefab;
    public AudioSource ExplosionSoundPrefab;
    public float FireRate = 0.8f;
    public float ProjectileSpeed = 500f;
    public float ProjectileScale = 2.0f;
    public float FireRadius = 10.0f;
    public int HitPoints = 100;

    private float TimeToNextFire = 0.0f;
    private GameManager Manager;

    void Start()
    {
        // Set the color of the overlay
        // Overlay is the 2nd child
        transform.GetChild(1).GetComponent<SpriteRenderer>().color = ShipColor;

        Manager = GameObject.Find("GameManager").GetComponent<GameManager>();
    }

    public void TakeDamage(int amount)
    {
        HitPoints -= amount;

        Manager.AddToStat("total_damage", amount);

        if (HitPoints <= 0)
        {
            Manager.TallyStat("satellites_destroyed");
            Manager.EnemyKilled();

            // Create the explosion
            var prefab = Instantiate(ExplosionPrefab, gameObject.transform.position, Quaternion.identity);
            var explosion = prefab.GetComponent<ParticleSystem>();

            explosion.Play();

            var smokefab = Instantiate(ExplosionSmokePrefab, gameObject.transform.position, Quaternion.identity);
            var smoke = smokefab.GetComponent<ParticleSystem>();

            smoke.Play();

            // Play explosion sound
            var soundeffect = Instantiate(ExplosionSoundPrefab, gameObject.transform.position, Quaternion.identity);

            // Clean up
            Destroy(soundeffect, soundeffect.clip.length);
            Destroy(explosion, explosion.main.duration);
            Destroy(smoke, smoke.main.duration);
            Destroy(gameObject);
        }
    }

    void Update()
    {
        if (Target == null)
        {
            return;
        }

        // Rotate the turret to face the player
        Vector3 diff = Target.transform.position - transform.position;

        transform.rotation = Quaternion.Euler(
            0f,
            0f,
            (Mathf.Atan2(diff.y, diff.x) - 1.5f) * Mathf.Rad2Deg
            );

        // Update firing timer
        TimeToNextFire = Mathf.Max(TimeToNextFire - Time.deltaTime, 0f);

        // Check how far away the player is
        float distance = Vector3.Distance(
            transform.position,
            Target.transform.position
            );

        // If they're close enough, start firing!
        if (distance < FireRadius)
        {
            Fire(Target.transform.position);
        }
    }

    public void Fire(Vector3 target)
    {
        // Enforce the max fire rate
        if (TimeToNextFire > 0.0f)
        {
            return;
        }

        TimeToNextFire = FireRate;

        // Create a new laser bolt
        GameObject bullet = Instantiate(
            Projectile,
            transform.position + transform.up * 2f,
            transform.rotation
            );

        // Set the scale, match velocity and set the force
        bullet.transform.localScale *= ProjectileScale;
        bullet.GetComponent<Rigidbody2D>().velocity = GetComponent<Rigidbody2D>().velocity;
        bullet.GetComponent<Rigidbody2D>().AddForce(transform.up * ProjectileSpeed);

        // Don't let the laser collide with us
        Physics2D.IgnoreCollision(
            GetComponent<Collider2D>(),
            bullet.GetComponent<Collider2D>()
            );

        // Pew pew
        GetComponent<AudioSource>().Play();
    }
}
