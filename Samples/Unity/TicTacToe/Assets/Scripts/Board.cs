// Copyright (C) Microsoft Corporation. All rights reserved.

using System.Collections;
using UnityEngine;

namespace PlayFab.TicTacToeDemo
{
    public class Board : MonoBehaviour
    {
        private bool _canPlay { get; set; }

        public TokenRow[] Rows = new TokenRow[3];
        public GameObject XPrefab;
        public GameObject OPrefab;

        public TicTacToeMove LatestPlayerMove { get; private set; }

        private void Start()
        {
            SetEnabled(false);
        }

        public IEnumerator WaitForNextMove()
        {
            // Enable the board
            SetEnabled(true);
            while (true)
            {
                for (int i = 0; i < Rows.Length; i++)
                {
                    // Query the row for the next move on it
                    StartCoroutine(Rows[i].GetNextMove());

                    // On the first row that gets clicked
                    if (Rows[i].ColumnClicked != -1)
                    {
                        // Get the move that was requested
                        LatestPlayerMove = new TicTacToeMove
                        {
                            row = i,
                            col = Rows[i].ColumnClicked
                        };

                        // Reset the row
                        Rows[i].ColumnClicked = -1;

                        // Disable the board
                        SetEnabled(false);
                        yield break;
                    }
                }
                yield return null;
            }
        }

        public TicTacToeMove GetAndResetMove()
        {
            var move = LatestPlayerMove;
            LatestPlayerMove = null;
            return move;
        }

        public void PlacePlayerToken(int row, int col)
        {
            Rows[row].Columns[col].PlaceToken(XPrefab);
        }

        public void PlaceAIToken(int row, int col)
        {
            Rows[row].Columns[col].PlaceToken(OPrefab);
        }

        private void SetEnabled(bool enabled)
        {
            foreach (var row in Rows)
            {
                foreach (var token in row.Columns)
                {
                    token.IsEnabled = enabled;
                }
            }
        }

        public void Reset()
        {
            SetEnabled(true);

            foreach (var row in Rows)
            {
                foreach (var token in row.Columns)
                {
                    token.Reset();
                }
            }
        }
    }
}
