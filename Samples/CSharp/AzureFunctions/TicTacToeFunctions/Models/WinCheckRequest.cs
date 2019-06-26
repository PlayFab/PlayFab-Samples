// Copyright (C) Microsoft Corporation. All rights reserved.

namespace PlayFab.TicTacToeDemo.Models
{
    public class WinCheckRequest
    {
        public TicTacToeState State { get; set; }
        public string PlayFabId { get; set; }
    }
}
