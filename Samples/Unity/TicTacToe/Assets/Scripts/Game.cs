// Copyright (C) Microsoft Corporation. All rights reserved.

using PlayFab.TicTacToeDemo.Handlers;
using PlayFab.TicTacToeDemo.Models;
using System;
using System.Collections;
using UnityEngine;
using UnityEngine.UI;

namespace PlayFab.TicTacToeDemo
{
    public class Game : MonoBehaviour
    {
        #region UI Objects
        public Button RestartButton;
        public Text WinnerStatusText;
        public Text GameStatusText;
        #endregion

        #region Game Objects
        public Board Board;
        #endregion

        #region Game State Properties
        public bool GameOver { get; private set; }
        public PlayerInfo CurrentPlayer { get; private set; }
        #endregion

        void Start()
        {
            RestartButton.onClick.AddListener(RestartGame);

            UpdateGameStatus(Constants.PLAYER_LOGIN_STARTED);

            var loginHandler = new LoginHandler();
            loginHandler.Login(OnPlayerLogin, OnLoginFail);
        }

        private void OnPlayerLogin(PlayerInfo playerInfo)
        {
            UpdateGameStatus(Constants.PLAYER_LOGIN_COMPLETED);

            // Store the player info
            CurrentPlayer = playerInfo;

            // Start the game loop
            StartCoroutine(StartGameLoop());
        }

        private IEnumerator StartGameLoop()
        {
            // Reset any previously stored current game state
            yield return StartCoroutine(ResetCurrentGameState());

            while (true)
            {
                // Let the player make a move
                yield return StartCoroutine(MakePlayerMove());

                // Check if the player won
                yield return StartCoroutine(CheckForWinner());
                if (GameOver)
                {
                    UpdateGameStatus(Constants.GAME_OVER);

                    yield break;
                }

                // Ask for AI move
                yield return StartCoroutine(MakeAIMove());

                // Check if the AI won
                yield return StartCoroutine(CheckForWinner());
                if (GameOver)
                {
                    UpdateGameStatus(Constants.GAME_OVER);

                    yield break;
                }
            }
        }

        private IEnumerator MakePlayerMove()
        {
            while(true)
            {
                UpdateGameStatus(Constants.PLAYER_MOVE_WAIT);

                // Let the player make a move
                yield return StartCoroutine(Board.WaitForNextMove());

                UpdateGameStatus(Constants.PLAYER_MOVE_PROCESSING);

                // Get and execute the player move
                var move = Board.GetAndResetMove();
                var playerMoveHandler = new PlayerMoveHandler(CurrentPlayer, move);
                yield return StartCoroutine(playerMoveHandler.ExecuteRequest());

                var makeMoveResult = playerMoveHandler.MoveResult;

                // If valid move place token and end player move
                if (makeMoveResult.valid)
                {
                    UpdateGameStatus(Constants.PLAYER_MOVE_COMPLETED);

                    WinnerStatusText.GetComponent<Text>().enabled = false;
                    Board.PlacePlayerToken(move.row, move.col);
                    yield break;
                }
                // Otherwise ask for another move
                else
                {
                    UpdateGameStatus(Constants.PLAYER_MOVE_INVALID);
                }

                yield return null;
            }
        }

        private IEnumerator MakeAIMove()
        {
            UpdateGameStatus(Constants.AI_MOVE_STARTED);

            var aiMoveHandler = new AIMoveHandler(CurrentPlayer);
            yield return StartCoroutine(aiMoveHandler.ExecuteRequest());

            var aiMove = aiMoveHandler.AIMoveResult;

            if (aiMove.Valid)
            {
                UpdateGameStatus(Constants.AI_MOVE_COMPLETED);

                Board.PlaceAIToken(aiMove.row, aiMove.col);
            } else
            {
                UpdateGameStatus(Constants.AI_MOVE_FAILED);
            }
        }

        private IEnumerator CheckForWinner()
        {
            UpdateGameStatus(Constants.GAME_WIN_CHECK_STARTED);

            var winCheckHandler = new WinCheckHandler(CurrentPlayer);
            yield return StartCoroutine(winCheckHandler.ExecuteRequest());

            var winCheckResult = winCheckHandler.WinCheckResult;

            ProcessWinCheckResult(winCheckResult);

            UpdateGameStatus(Constants.GAME_WIN_CHECK_COMPLETED);
        }

        private IEnumerator ResetCurrentGameState()
        {
            UpdateGameStatus(Constants.GAME_RESET_STARTED);

            var resetGameHandler = new ResetGameStateHandler(CurrentPlayer);
            yield return StartCoroutine(resetGameHandler.ExecuteRequest());

            UpdateGameStatus(Constants.GAME_RESET_COMPLETED);
        }

        private void RestartGame()
        {
            // Reset state
            GameOver = false;

            // Clear the board tokens
            Board.Reset();

            // Hide restart button
            RestartButton.gameObject.SetActive(false);

            // Hide status message
            WinnerStatusText.GetComponent<Text>().enabled = false;

            // Restart game loop
            StartCoroutine(StartGameLoop());
        }

        private void ProcessWinCheckResult(WinCheckResult result)
        {
            switch (result.winner)
            {
                case GameWinnerType.NONE:
                    break;
                case GameWinnerType.DRAW:
                    WinnerStatusText.text = "DRAW!";
                    break;
                case GameWinnerType.PLAYER:
                    WinnerStatusText.text = "YOU WIN";
                    break;
                case GameWinnerType.AI:
                    WinnerStatusText.text = "YOU LOSE";
                    break;
            }

            if (result.winner != GameWinnerType.NONE)
            {
                WinnerStatusText.GetComponent<Text>().enabled = true;
                RestartButton.gameObject.SetActive(true);
                GameOver = true;
            }
        }

        private void UpdateGameStatus(string statusText)
        {
            GameStatusText.GetComponent<Text>().enabled = true;
            GameStatusText.text = statusText;
        }

        private void OnLoginFail()
        {
            UpdateGameStatus(Constants.PLAYER_LOGIN_FAILED);
            throw new Exception("Failed to login.");
        }
    }
}
