// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.Json;

namespace PlayFab.TicTacToeDemo.Models
{
    public class TicTacToeState
    {
        [JsonProperty]
        public int[] Data { get; set; }

        public int Get(int index)
        {
            return Data[index];
        }

        public void Set(int index, int value)
        {
            Data[index] = value;
        }
    }
}
