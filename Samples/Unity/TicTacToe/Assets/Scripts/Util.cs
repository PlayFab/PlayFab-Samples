// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab;
using UnityEngine;

public class Util
{
    public static T[,] Make2DArray<T>(T[] input, int height, int width)
    {
        T[,] output = new T[height, width];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                output[i, j] = input[i * width + j];
            }
        }
        return output;
    }

    public static void DisplayHttpError(PlayFabError error)
    {
        Debug.LogError($"Request failed with status code {error.HttpCode}");
        Debug.LogError($"Error details: {error.ErrorDetails}");
        Debug.LogError($"Error message: {error.ErrorMessage}");
    }
}
