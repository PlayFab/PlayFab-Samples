using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using PlayFab.ClientModels;
using System;

public class ScoreList : MonoBehaviour
{
    public GameObject EntryPrefab;

    // Use this for initialization
    public void ShowLeaderboard (string boardName, string boardTitle, string valueName)
    {
        // Remove any existing entries
        foreach (Transform child in transform)
        {
            Destroy(child.gameObject);
        }

        // Get the leaderboard data
        var leaderboards = PlayfabManager.GetLeaderboard(boardName);

		if (leaderboards.Count > 0)
		{
			// Create UI entries for each
			foreach (var leaderboard in leaderboards)
			{
				var entry = Instantiate(EntryPrefab);

				entry.transform.SetParent(this.transform, false);
				entry.transform.Find("Player").GetComponent<Text>().text = leaderboard.DisplayName ?? leaderboard.PlayFabId;
				entry.transform.Find("Rank").GetComponent<Text>().text = (leaderboard.Position + 1).ToString();
				entry.transform.Find("Value").GetComponent<Text>().text = leaderboard.StatValue.ToString();
			}
		}
		else
		{
			var entry = Instantiate(EntryPrefab);
			entry.transform.SetParent(this.transform, false);
			entry.transform.Find("Player").GetComponent<Text>().text = "Leaderboard is empty";
			entry.transform.Find("Rank").GetComponent<Text>().text = String.Empty;
			entry.transform.Find("Value").GetComponent<Text>().text = String.Empty;
		}

        // Set the label text
        GameObject.Find("Title Panel").transform.Find("Title").GetComponent<Text>().text = boardTitle;
        GameObject.Find("Header Panel").transform.Find("Header: Value").GetComponent<Text>().text = valueName;
    }
}
