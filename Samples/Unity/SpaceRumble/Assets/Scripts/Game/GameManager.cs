//--------------------------------------------------------------------------------------
// GameManager.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public GameObject[] ShipPrefabs = new GameObject[4];
    public Color[] ShipColors = new Color[4];
    public GameObject PlayerShip;
    public GameObject Satellite;
    public Text UserName;
    public Text MOTD;
    public Text RemainingUI;
    public Text TimerUI;
    public Text TotalTimeUI;
    public GameObject WelcomePanel;
    public GameObject MainMenuPanel;
    public GameObject GameOverPanel;
    public GameObject ControlsPanel;
    public GameObject AsteroidField;
    public GameObject WorldMap;
    public GameObject FixedScroll;
    public Joystick FireStick;
    public Joystick ThrustStick;

    private int SatellitesRemaining;
    public bool HaveSetMOTD = false;
    public bool HaveSetUserName = false;
    private Dictionary<string, int> GameStats = new Dictionary<string, int>();
    private float RoundTimer = 0;
    private bool GamePlaying = false;

    void Update () 
    {
        if (!HaveSetMOTD)
        {
            if (PlayFabManager.IsLoggedIn && PlayFabManager.IsTitleDataLoaded)
            {
                MOTD.text = PlayFabManager.GetTitleDataValue("MOTD");
                HaveSetMOTD = true;
            }
        }

        if (!HaveSetUserName)
        {
            if (PlayFabManager.IsLoggedIn && PlayFabManager.IsAccountInfoLoaded)
            {
                if (!string.IsNullOrEmpty(PlayFabManager.UserDisplayName))
                {
                    UserName.text = PlayFabManager.UserDisplayName;
                }
                else
                {
                    UserName.text = "Visit Options to set your user name!";
                }

                HaveSetUserName = true;
            }
        }

        if (GamePlaying)
        {
            RoundTimer += Time.deltaTime;
            TimerUI.text = FormatTimer(RoundTimer);
        }
    }

    public void StartGame()
    {
        // Hard-coded locations for enemy satellites
        // These should be randomly generated
        Vector3[] SatelliteSpawns =
        {
            new Vector3(-7.49f, 3.45f),
            new Vector3(-15.52f, 23.42f),
            new Vector3(-16.46f, -25.27f),
            new Vector3(17.21f, 13.4f),
            new Vector3(25.61f, -23.13f)
        };

        SatellitesRemaining = SatelliteSpawns.Length;
        RoundTimer = 0;

        // Tell each satellite to kill the player
        foreach(Vector3 loc in SatelliteSpawns)
        {
            var enemy = Instantiate(Satellite, loc, Quaternion.identity);
            enemy.GetComponent<TurretBehavior>().Target = PlayerShip;
        }

        // Set the initial UX
        RemainingUI.text = SatellitesRemaining.ToString();
        TimerUI.text = FormatTimer(RoundTimer);

        GamePlaying = true;
    }

    public void ClearUserSignin()
    {
        PlayFabAuthService.Instance.ClearRememberMe();
    }

    private string FormatTimer(float time)
    {
        // Take number of seconds and produce a string with the format
        //     "999m 99s"
        int seconds = (int)time;
        string output = "";

        if (seconds >= 60)
        {
            output += (seconds / 60).ToString();
            output += "m ";
            seconds %= 60;
        }

        output += seconds.ToString();
        output += "s";

        return output;
    }

    public void EnemyKilled()
    {
        // Called when a satellite is destroyed
        SatellitesRemaining -= 1;

        RemainingUI.text = SatellitesRemaining.ToString();

        if (SatellitesRemaining == 0)
        {
            GameOver();
        }
    }

    public void GameOver()
    {
        GamePlaying = false;

        // Setup the post-game UX
        TotalTimeUI.text = FormatTimer(RoundTimer);

        // Set the UX state
        GameOverPanel.SetActive(true);
        ControlsPanel.SetActive(false);
        PlayerShip.SetActive(false);
        FixedScroll.SetActive(true);

        // Update the final game stat
        SetStat("total_round_time", (int)RoundTimer);

        // Write all of the game stats to the service
        WriteGameplayStats();
    }

    public void GoToMainMenu()
    {
        MainMenuPanel.SetActive(true);

        // Update the UX state
        WorldMap.SetActive(false);
        AsteroidField.SetActive(false);
    }

    public void GoToGamePlay()
    {
        PlayFabManager.UpdateStatistic("games_played", 1);

        if (PlayerShip == null)
        {
            var style = PlayFabManager.GetUserDataValue("ShipStyle");
            var color = PlayFabManager.GetUserDataValue("ShipColor");

            if (string.IsNullOrEmpty(style))
            {
                style = Random.Range(0, 4).ToString();
            }

            if (string.IsNullOrEmpty(color))
            {
                color = Random.Range(0, 4).ToString();
            }

            PlayerShip = Instantiate(ShipPrefabs[int.Parse(style)], new Vector3(0, 0, 1f), Quaternion.identity);
            PlayerShip.GetComponent<ShipBehavior>().ShipColor = ShipColors[int.Parse(color)];
            PlayerShip.GetComponent<FireJoystickBehavior>().Joystick = FireStick;
            PlayerShip.GetComponent<MovementJoystickBehavior>().Joystick = ThrustStick;
        }

        // Reset positions to the origin
        Camera.main.transform.position = new Vector3(0, 0, Camera.main.transform.position.z);
        PlayerShip.transform.position = new Vector3(0, 0, 1f);

        // Stop scrolling the starfield
        FixedScroll.SetActive(false);

        // Turn on world map, asteroids and satellites
        WorldMap.SetActive(true);
        AsteroidField.SetActive(true);

        // Show the player
        PlayerShip.SetActive(true);

        // Start the game
        StartGame();
    }

    public void ClearStats()
    {
        GameStats.Clear();
    }

    public void TallyStat(string stat)
    {
        AddToStat(stat, 1);
    }

    public void AddToStat(string stat, int value)
    {
        if (!GameStats.ContainsKey(stat))
        {
            GameStats[stat] = 0;
        }

        GameStats[stat] += value;
    }

    public int GetStat(string stat)
    {
        if (GameStats.ContainsKey(stat))
        {
            return GameStats[stat];
        }

        return -1;
    }

    public void SetStat(string stat, int value)
    {
        GameStats[stat] = value;
    }

    private void WriteGameplayStats()
    {
        var updateStats = new Dictionary<string, object>();

        foreach(var stat in GameStats.Keys)
        {
            updateStats[stat] = GameStats[stat];
        }

        PlayFabManager.UpdateStatistics(updateStats);
    }
}
