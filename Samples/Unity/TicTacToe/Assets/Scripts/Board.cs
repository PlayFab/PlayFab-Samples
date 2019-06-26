// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab;
using PlayFab.CloudScriptModels;
using PlayFab.Json;
using System.Linq;
using UnityEngine;
using UnityEngine.UI;

public class Board : MonoBehaviour
{
    
    public TokenRow[] Rows = new TokenRow[3];

    public bool CanPlay { get; private set; }
    public bool GameOver { get; private set; }
    
    private Player Player;
    
    // Prefabs
    public Player PlayerPrefab;
    public GameObject XPrefab;
    public GameObject OPrefab;

    public Text WinText;
    public Text LossText;
    public Text DrawText;

    public Button RestartButton;

    private void Start()
    {
        Player = Instantiate(PlayerPrefab);
        Player.name = Constants.PLAYER;
        Player.Board = this;
    }

    public void OnPlayerLoginCompleted()
    {
        CanPlay = true;
    }

    public void PlaceHumanToken(TokenPlaceholder placeholder)
    {
        // Safety against duplication of tokens and out of turn move(s)
        if (placeholder.Token != null)
            return;

        // Disable game actions until a move has been made or a winner announced
        CanPlay = false;

        // Instantiate the token object from the prefab, nest it in the placeholder, and position it correctly
        PlaceTokenOnPlaceholder(placeholder, XPrefab, OccupantType.HUMAN);
        
        var state = GetBoardState();

        // Check if this move was a win and end game if so, don't send a move request to server
        CheckWinRemote(state, true);
    }

    private void MakeAIMove()
    {
        var state = GetBoardState();
        
        // Create a request object to send to server that includes the board state
        var request = new ExecuteFunctionRequest
        {
            FunctionName = Constants.MOVE_FUNCTION_NAME,
            FunctionParameter = state,
            AuthenticationContext = new PlayFabAuthenticationContext
            {
                EntityToken = Player.EntityToken
            }
        };

        // Execute the request
        PlayFabCloudScriptAPI.ExecuteFunction(request,
            // Success callback: server responds with a valid/invalid move
            (result) =>
            {
                // Extract the move out of the server response
                var move = PlayFabSimpleJson.DeserializeObject<TicTacToeMove>(result.FunctionResult?.ToString());

                // Perform the steps needed to process the AI's move
                PostAIMoveActions(move);
            }, 
            // Failure callback
            (error) => 
            {
                Util.DisplayHttpError(error);
            });
    }

    private void PostAIMoveActions(TicTacToeMove move)
    {
        // Check if game ended without any winner
        if (move.Invalid)
        {
            DrawText.GetComponent<Text>().enabled = true;
            GameOver = true;
            RestartButton.gameObject.SetActive(true);
            return;
        }

        // Place the AI's token on the appropriate placeholder with necessary positioning & nesting
        PlaceTokenOnPlaceholder(this[move.row, move.col], OPrefab, OccupantType.AI);
        
        var state = GetBoardState();

        // Check for a win from the AI
        CheckWinRemote(state, false);
    }

    private TicTacToeState GetBoardState()
    {
        // Create a 2D array of ints representing the current state of the board
        int[,] state = new int[3, 3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                switch(this[i, j].OccupantType)
                {
                    case OccupantType.NONE:
                        state[i, j] = (int) OccupantType.NONE;
                        break;
                    case OccupantType.HUMAN:
                        state[i, j] = (int) OccupantType.HUMAN;
                        break;
                    case OccupantType.AI:
                        state[i, j] = (int) OccupantType.AI;
                        break;
                }
            }
        }
        int[] flatState = state.Cast<int>().ToArray();
        return new TicTacToeState() { Data = flatState };
    }


    private void CheckWin(TicTacToeState state, bool movePending)
    {
        var result = WinChecker.Check(state);
        GameOver = ProcessWinResults(result.winner);

        if (!GameOver)
        {
            // If an AI move is pending, perform it
            if (movePending)
            {
                MakeAIMove();
            }
            // Otherwise allow the player to make a move as AI move just finished
            else
            {
                CanPlay = true;
            }
        }
        else
        {
            // Game is over so update the player's stats based on whether they won or lost
            UpdateLeaderboard(Player.SessionTicket, result.winner);

            // Allow the user to restart the game if they wish to do so
            RestartButton.gameObject.SetActive(true);
        }
    }

    private void CheckWinRemote(TicTacToeState state, bool movePending)
    {
        var functionRequest = new ExecuteFunctionRequest
        {
            FunctionName = Constants.WIN_CHECK_FUNCTION_NAME,
            FunctionParameter = new WinCheckRequest 
            {
                State = state,
                PlayFabId = Player.PlayFabId
            },
            AuthenticationContext = new PlayFabAuthenticationContext
            {
                EntityToken = Player.EntityToken
            }
        };

        PlayFabCloudScriptAPI.ExecuteFunction(functionRequest,
            (functionResult) => {
                var result = PlayFabSimpleJson.DeserializeObject<WinCheckResult>(functionResult.FunctionResult?.ToString());
                GameOver = ProcessWinResults(result.winner);

                if (!GameOver)
                {
                    if (movePending)
                    {
                        MakeAIMove();
                    }
                    else
                    {
                        CanPlay = true;
                    }
                }
                else
                {
                    RestartButton.gameObject.SetActive(true); 
                }
            },
            (functionError) => {
                Util.DisplayHttpError(functionError);
            });
    }

    private bool ProcessWinResults(OccupantType winner)
    {
        bool gameOver = false;
        switch (winner)
        {
            case OccupantType.HUMAN:
                {
                    WinText.GetComponent<Text>().enabled = true;
                    gameOver = true;
                    break;
                }
            case OccupantType.AI:
                {
                    LossText.GetComponent<Text>().enabled = true;
                    gameOver = true;
                    break;
                }
            case OccupantType.NONE:
                {
                    break;
                }
        }
        return gameOver;
    }

    

    private static void UpdateLeaderboard(string sessionTicket, OccupantType winner)
    {
        switch (winner)
        {
            case OccupantType.HUMAN:
                {
                    // Add a win to player's record
                    WinChecker.UpdateStatValue(sessionTicket, "wins", 1);
                    break;
                }
            case OccupantType.AI:
                {
                    // Add a loss to player's record
                    WinChecker.UpdateStatValue(sessionTicket, "losses", 1);
                    break;
                }
            default:
                {
                    break;
                }
        }
    }

    public void Reset()
    {
        WinText.GetComponent<Text>().enabled = false;
        LossText.GetComponent<Text>().enabled = false;
        DrawText.GetComponent<Text>().enabled = false;

        foreach (var row in Rows)
        {
            foreach (var placeholder in row.Columns)
            {
                Destroy(placeholder.Token);
                placeholder.OccupantType = OccupantType.NONE;

                if (placeholder.Token != null)
                {
                    placeholder.Token = null;
                }

                CanPlay = true;
                GameOver = false;
            }
        }

        RestartButton.gameObject.SetActive(false);
    }

    private void PlaceTokenOnPlaceholder(TokenPlaceholder placeholder, GameObject prefab, OccupantType occupantType)
    {
        placeholder.Token = Instantiate(prefab);
        placeholder.Token.transform.SetParent(placeholder.transform);
        placeholder.Token.transform.position = placeholder.transform.position;
        placeholder.OccupantType = occupantType;
        var renderer = placeholder.GetComponent<Renderer>();
        renderer.enabled = false;
    }

    public TokenRow this[int index]
    {
        get
        {
            return Rows[index];
        }

        set
        {
            Rows[index] = value;
        }
    }

    public TokenPlaceholder this[int firstDim, int secondDim]
    {
        get
        {
            return Rows[firstDim][secondDim];
        }
    }
}
