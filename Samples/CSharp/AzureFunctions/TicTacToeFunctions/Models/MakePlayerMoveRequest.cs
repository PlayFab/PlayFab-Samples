// Copyright (C) Microsoft Corporation. All rights reserved.

namespace PlayFab.TicTacToeDemo.Models
{
    public class MakePlayerMoveRequest : PlayFabIdRequest
    {
        public TicTacToeMove Move { get; set; }
    }
}
