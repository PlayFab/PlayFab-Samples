// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.TicTacToeDemo.Models;
using System;
using System.Collections;
using UnityEngine;

namespace PlayFab.TicTacToeDemo.Handlers
{
    public class RequestHandler
    {
        protected PlayerInfo Player { get; set; }
        protected bool ExecutionCompleted { get; set; }

        public RequestHandler(PlayerInfo Player)
        {
            this.Player = Player;
        }

        public virtual IEnumerator ExecuteRequest() 
        {
            throw new NotImplementedException();
        }

        protected IEnumerator WaitForExecution()
        {
            yield return new WaitUntil(() => { return ExecutionCompleted; });
        }
    }
}
