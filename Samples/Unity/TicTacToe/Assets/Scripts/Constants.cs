// Copyright (C) Microsoft Corporation. All rights reserved.

public class Constants
{
    // FOR DEMO PURPOSES ONLY
    // It is strongly adviced to move this data out of the game client in a real production environment

    // API settings
    public const string TITLE_ID = "";
    public const string CLOUD_NAME = "";
    public const bool COMPRESS_API_DATA = false;
    public const string PLAYER = "Player";
    public const string PLAYFAB_PLAYER_CUSTOM_ID = "PLAYFAB_PLAYER_CUSTOM_ID";

    // Function names
    public const string MOVE_FUNCTION_NAME = "MakeRandomAIMove";
    public const string WIN_CHECK_FUNCTION_NAME = "WinCheck";
    public const string CREATE_STAT_FUNCTION_NAME = "TryCreateStatistics";
    public const string PLAYER_MOVE_FUNCTION_NAME = "MakePlayerMove";
    public const string AI_MOVE_FUNCTION_NAME = "MakeAIMove";
    public const string RESET_GAME_STATE_FUNCTION_NAME = "ResetGameState";

    // Status messages
    public const string AI_MOVE_COMPLETED = "AI move complete";
    public const string AI_MOVE_FAILED = "AI has no moves left";
    public const string AI_MOVE_STARTED = "Requesting AI move";
    public const string GAME_OVER = "Game over";
    public const string GAME_RESET_COMPLETED = "Reset complete";
    public const string GAME_RESET_STARTED = "Resetting game state";
    public const string GAME_WIN_CHECK_COMPLETED = "Win check complete";
    public const string GAME_WIN_CHECK_STARTED = "Checking for winner";
    public const string PLAYER_LOGIN_COMPLETED = "Login successful";
    public const string PLAYER_LOGIN_FAILED = "Login failed";
    public const string PLAYER_LOGIN_STARTED = "Login started";
    public const string PLAYER_MOVE_COMPLETED = "Player move complete";
    public const string PLAYER_MOVE_INVALID = "Invalid player move";
    public const string PLAYER_MOVE_PROCESSING = "Executing player move";
    public const string PLAYER_MOVE_WAIT = "Waiting for player move";
}
