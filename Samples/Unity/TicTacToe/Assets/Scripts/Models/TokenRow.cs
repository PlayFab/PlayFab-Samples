// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Collections;
using UnityEngine;

namespace PlayFab.TicTacToeDemo
{
    [System.Serializable]
    public class TokenRow : MonoBehaviour
    {
        public TokenPlaceholder[] Columns = new TokenPlaceholder[3];
        public int ColumnClicked { get; set; }

        private void Start()
        {
            ColumnClicked = -1;
        }
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

        public IEnumerator GetNextMove()
        {
            while (true)
            {
                for (int i = 0; i < Columns.Length; i++)
                {
                    if (Columns[i].IsClicked)
                    {
                        Columns[i].IsClicked = false;
                        ColumnClicked = i;
                        yield break;
                    }
                }
                yield return null;
            }
        }
    }

}
