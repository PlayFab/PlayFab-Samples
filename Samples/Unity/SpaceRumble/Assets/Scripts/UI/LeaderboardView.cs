//--------------------------------------------------------------------------------------
// LeaderboardView.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using PlayFab;
using PlayFab.ClientModels;

[Serializable]
public class LeaderBoardInfo
{
    public string Name = string.Empty;
    public string Title = string.Empty;
    public string ColumnName = string.Empty;
}

public class LeaderboardView : MonoBehaviour
{
    public Text ColumnHeaderText;
    public Text TitleText;
    public GameObject EntryPrefab;
    public GameObject EntryList;
    public List<LeaderBoardInfo> LeaderBoards = new List<LeaderBoardInfo>();
    public int MaxLeaderboardEntries = 7;

    private int CurrentLeaderboard = 0;
    private Dictionary<string, List<PlayerLeaderboardEntry>> DataCache = new Dictionary<string, List<PlayerLeaderboardEntry>>();

    void Start ()
    {
        Debug.Log("LeaderboardView Start");
        ShowLeaderboard(CurrentLeaderboard);
    }

    public void ClearLeaderboards()
    {
        DataCache.Clear();
    }

    public void NextLeaderboard()
    {
        CurrentLeaderboard++;

        if (CurrentLeaderboard == LeaderBoards.Count)
        {
            CurrentLeaderboard = 0;
        }

        ShowLeaderboard(CurrentLeaderboard);
    }

    public void PrevLeaderboard()
    {
        CurrentLeaderboard--;

        if (CurrentLeaderboard < 0)
        {
            CurrentLeaderboard = LeaderBoards.Count - 1;
        }

        ShowLeaderboard(CurrentLeaderboard);
    }

    private bool _loading = false;

    private void ShowLeaderboard(int boardIndex)
    {
        if (_loading)
        {
            Debug.Log(string.Format("ShowLeaderboard({0}) called while already loading.", boardIndex));
            return;
        }

        // Remove any existing entries
        foreach (Transform child in EntryList.transform)
        {
            Destroy(child.gameObject);
        }

        // See if we've loaded it already
        if (DataCache.ContainsKey(LeaderBoards[boardIndex].Name))
        {
            PopulateLeaderboard(LeaderBoards[boardIndex]);
            return;
        }

        TitleText.text = "Loading...";
        _loading = true;

        PlayFabClientAPI.GetLeaderboard(
            // Request
            new GetLeaderboardRequest
            {
                StatisticName = LeaderBoards[boardIndex].Name,
                StartPosition = 0,
                MaxResultsCount = MaxLeaderboardEntries
            },
            // Success
            (GetLeaderboardResult result) =>
            {
                _loading = false;
                DataCache[LeaderBoards[boardIndex].Name] = result.Leaderboard;
                PopulateLeaderboard(LeaderBoards[boardIndex]);
                Debug.Log("GetLeaderboard completed.");
            },
            // Failure
            (PlayFabError error) =>
            {

                _loading = false;
                TitleText.text = "Failed to load";

                Debug.LogError("GetLeaderboard failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    private void PopulateLeaderboard(LeaderBoardInfo leaderboardInfo)
    {
        // Set the label text
        TitleText.text = leaderboardInfo.Title;
        ColumnHeaderText.text = leaderboardInfo.ColumnName;

        // Create UI entries for each
        foreach (var leaderboard in DataCache[leaderboardInfo.Name])
        {
            var entry = Instantiate(EntryPrefab);

            entry.transform.SetParent(EntryList.transform, false);
            entry.transform.Find("Player").GetComponent<Text>().text = leaderboard.DisplayName ?? leaderboard.PlayFabId;
            entry.transform.Find("Rank").GetComponent<Text>().text = (leaderboard.Position + 1).ToString();
            entry.transform.Find("Value").GetComponent<Text>().text = leaderboard.StatValue.ToString();
        }
    }
}
