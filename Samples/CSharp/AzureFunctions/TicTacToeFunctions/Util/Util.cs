// Copyright (C) Microsoft Corporation. All rights reserved.

namespace PlayFab.TicTacToeDemo.Util
{
    public class ArrayUtil
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
    }
}
