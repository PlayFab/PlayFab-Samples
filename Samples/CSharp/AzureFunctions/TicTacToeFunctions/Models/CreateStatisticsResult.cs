// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Collections.Generic;
using PlayFab.Internal;

namespace PlayFab.TicTacToeDemo.Models
{
    public class CreateStatisticsResult
    {
        public List<PlayFabResultCommon> results { get; set; }
        public List<PlayFabError> errors { get; set; }
    }
}
