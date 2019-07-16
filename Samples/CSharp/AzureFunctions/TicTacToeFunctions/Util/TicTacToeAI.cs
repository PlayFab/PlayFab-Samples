// Copyright (C) Microsoft Corporation. All rights reserved.

using System;
using System.Collections.Generic;
using PlayFab.TicTacToeDemo.Models;

namespace PlayFab.TicTacToeDemo.Util
{
    public class TicTacToeAI
    {
        public static TicTacToeMove GetNextRandomMove(TicTacToeState state)
        {
            // Find all empty indices
            var emptyIndices = EmptyIndices(state);

            // Pick a random index among the empty indices
            if (emptyIndices.Count > 0)
            {
                Random rnd = new Random();
                int randomIndex = emptyIndices[rnd.Next(emptyIndices.Count)];
                // Turn the index into 2D board coordinates and return as a move
                return new TicTacToeMove
                {
                    row = randomIndex / 3,
                    col = randomIndex % 3
                };
            }

            // Return sentinel (-1, -1) move coordinates to indicate no more moves are possible
            return new TicTacToeMove
            {
                row = -1,
                col = -1
            };
        }

        public static TicTacToeMove GetNextMinimaxMove(TicTacToeState state)
        {
            var move = Minimax(state, OccupantType.AI);
            return new TicTacToeMove
            {
                row = move.Index != null ? move.Index.Value / 3 : -1,
                col = move.Index != null ? move.Index.Value % 3 : -1
            };
        }

        private class MinimaxMove
        {
            public int? Index { get; set; }
            public int Score { get; set; }
        }

        private static MinimaxMove Minimax(TicTacToeState state, OccupantType player)
        {
            var emptyIndices = EmptyIndices(state);

            var winningResult = WinCheckUtil.Check(state);

            if (winningResult.Winner.Equals(GameWinnerType.PLAYER))
            {
                return new MinimaxMove { Score = -10 };
            }
            else if (winningResult.Winner.Equals(GameWinnerType.AI))
            {
                return new MinimaxMove { Score = 10 };
            }
            else if (emptyIndices.Count == 0)
            {
                return new MinimaxMove { Score = 0 };
            }

            var moves = new List<MinimaxMove>();

            for (int i = 0; i < emptyIndices.Count; i++)
            {
                var move = new MinimaxMove
                {
                    Index = emptyIndices[i]
                };

                state.Data[emptyIndices[i]] = (int)player;

                var result = player.Equals(OccupantType.AI) ?
                    Minimax(state, OccupantType.PLAYER) :
                    Minimax(state, OccupantType.AI);
                move.Score = result.Score;

                state.Data[emptyIndices[i]] = (int) OccupantType.NONE;

                moves.Add(move);
            }

            int bestMove = -1;
            if (player.Equals(OccupantType.AI))
            {
                var bestScore = -10000;
                for (int i = 0; i < moves.Count; i++)
                {
                    if (moves[i].Score > bestScore)
                    {
                        bestScore = moves[i].Score;
                        bestMove = i;
                    }
                }
            }
            else
            {
                var bestScore = 10000;
                for (int i = 0; i < moves.Count; i++)
                {
                    if (moves[i].Score < bestScore)
                    {
                        bestScore = moves[i].Score;
                        bestMove = i;
                    }
                }
            }

            return moves[bestMove];
        }

        private static List<int> EmptyIndices(TicTacToeState state)
        {
            var emptyIndices = new List<int>();
            for (int i = 0; i < 9; i++)
            {
                if (state.Get(i).Equals((int) OccupantType.NONE))
                {
                    emptyIndices.Add(i);
                }
            }

            return emptyIndices;
        }
    }
}
