// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class TokenRow : MonoBehaviour
{
    public TokenPlaceholder[] Columns = new TokenPlaceholder[3];

    public TokenPlaceholder this[int index]
    {
        get
        {
            return Columns[index];
        }

        set
        {
            Columns[index] = value;
        }
    }
}
