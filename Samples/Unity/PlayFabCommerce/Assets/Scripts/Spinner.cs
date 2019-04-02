using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spinner : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        Quaternion rotationStep = Quaternion.Euler(0, 0, -60 * Time.deltaTime);
        transform.rotation *= rotationStep;
    }
}
