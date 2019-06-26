// Copyright (C) Microsoft Corporation. All rights reserved.

public class TicTacToeMove
{
    public int row { get ;set; }
    public int col { get; set; }

    public bool Invalid
    {
        get
        {
            return row == -1 && col == -1;
        }
    }
}
