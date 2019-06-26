// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.TicTacToeDemo.Models;
using System;

namespace PlayFab.TicTacToeDemo.Util
{
    public static class WinCheckUtil
    {
        public static WinCheckResult Check(TicTacToeState state)
        {
            int[,] state2D = Util.Make2DArray(state.Data, 3, 3);
            // For all but NONE occupant types, check to see if there is a winner in the game at the moment
            foreach (var occupantType in (OccupantType[])Enum.GetValues(typeof(OccupantType)))
            {
                if (occupantType == OccupantType.NONE)
                    continue;

                if (CheckRowWin(occupantType, state2D)
                    || CheckColWin(occupantType, state2D)
                    || CheckDiagWin(occupantType, state2D))
                {
                    return new WinCheckResult() { Winner = occupantType };
                }
            }
            return new WinCheckResult() { Winner = OccupantType.NONE };
        }

        private static bool CheckRowWin(OccupantType occupantType, int[,] state)
        {
            // Given an occupant type, check all rows to see if that occupant type has won any row
            for (int i = 0; i < 3; i++)
            {
                if (state[i, 0] == (int)occupantType
                    && state[i, 1] == (int)occupantType
                    && state[i, 2] == (int)occupantType)
                    return true;
            }
            return false;
        }

        private static bool CheckColWin(OccupantType occupantType, int[,] state)
        {
            // Given an occupant type, check all column to see if that occupant type has won any column
            for (int i = 0; i < 3; i++)
            {
                if (state[0, i] == (int)occupantType
                    && state[1, i] == (int)occupantType
                    && state[2, i] == (int)occupantType)
                    return true;
            }
            return false;
        }

        private static bool CheckDiagWin(OccupantType occupantType, int[,] state)
        {
            // Given an occupant type, check both diagonals  to see if that occupant type has won any diagonal
            if (state[0, 0] == (int)occupantType
                && state[1, 1] == (int)occupantType
                && state[2, 2] == (int)occupantType)
                return true;
            if (state[2, 0] == (int)occupantType
                && state[1, 1] == (int)occupantType
                && state[0, 2] == (int)occupantType)
                return true;
            return false;
        }
    }
}
