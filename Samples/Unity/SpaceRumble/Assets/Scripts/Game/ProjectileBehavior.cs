//--------------------------------------------------------------------------------------
// ProjectileBehavior.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using UnityEngine;

public class ProjectileBehavior : MonoBehaviour
{
    public int DamageAmount = 10;
    public GameObject ExplosionPrefab;

    private GameManager Manager;

    private void Start()
    {
        Manager = GameObject.Find("GameManager").GetComponent<GameManager>();
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.transform.tag == "Satellite")
        {
            collision.transform.GetComponent<TurretBehavior>().TakeDamage(DamageAmount);
            Manager.TallyStat("satellite_hit");
        }

        // Spawn a small explosion where the laser hits an object
        var prefab = Instantiate(ExplosionPrefab, gameObject.transform.position, Quaternion.identity);
        var explosion = prefab.GetComponent<ParticleSystem>();

        explosion.Play();

        // After colliding, destroy the projectile
        Destroy(explosion, explosion.main.duration);
        Destroy(gameObject);
    }
}
