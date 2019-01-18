using System.Collections.Generic;
using PlayFab;
using PlayFab.ClientModels;
using UnityEngine;
using UnityEngine.UI;

public static class PlayfabManager
{
    public static void Login(System.Action<LoginResult> onSuccess, System.Action<PlayFabError> onFailed)

	{
#if UNITY_ANDROID
        PlayFabClientAPI.LoginWithAndroidDeviceID(
            // Request
            new LoginWithAndroidDeviceIDRequest
            {
                CreateAccount = true,
                AndroidDevice = SystemInfo.deviceModel,
                OS = SystemInfo.operatingSystem,
                AndroidDeviceId = SystemInfo.deviceUniqueIdentifier
            },
            // Success
            (LoginResult result) => 
            {
                Debug.Log("Login completed.");
                LoadLeaderboards();
                IsLoggedIn = true;
            },
            // Failure
            (PlayFabError error) => 
            {
                Debug.LogError("Login failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
#elif UNITY_IOS
        PlayFabClientAPI.LoginWithIOSDeviceID(
            // Request
            new LoginWithIOSDeviceIDRequest
            {
                CreateAccount = true,
                DeviceId = SystemInfo.deviceUniqueIdentifier,
                DeviceModel = SystemInfo.deviceModel,
                OS = SystemInfo.operatingSystem
            },
            // Success
            (LoginResult result) => 
            {
                Debug.Log("Login completed.");
                LoadLeaderboards();
                IsLoggedIn = true;
            },
            // Failure
            (PlayFabError error) => 
            {
                Debug.LogError("Login failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
#else
        PlayFabClientAPI.LoginWithCustomID(
            // Request
            new LoginWithCustomIDRequest
            {
                CustomId = System.Guid.NewGuid().ToString(),
                CreateAccount = true
            },
            // Success
            (LoginResult result) => 
            {
                Debug.Log("Login completed.");
                IsLoggedIn = true;
				onSuccess(result);
            },
            // Failure
            (PlayFabError error) => 
            {
                Debug.LogError("Login failed.");
                Debug.LogError(error.GenerateErrorReport());
				onFailed(error);
			}
            );
#endif
    }

    // Flag set after successfull Playfab Login
    public static bool IsLoggedIn = false;
	
    ////////////////////////////////////////////////////////////////
    /// Update the user's game stats in bulk
    /// 
    /// This uses a custom even to trigger cloudscript which
    /// performs the stat updates
    /// 
    public static void UpdateStatistics(Dictionary<string, object> values)
    {
        PlayFabClientAPI.WritePlayerEvent(
            // Request
            new WriteClientPlayerEventRequest
            {
                EventName = "update_statistics",
                Body = new Dictionary<string, object>
                {
                    { "stats", values }
                }
            },
            // Success
            (WriteEventResponse response) =>
            {
                Debug.Log("WritePlayerEvent (UpdateStatistics) completed.");
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("WritePlayerEvent failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    ////////////////////////////////////////////////////////////////
    /// Update a user's individual game stat
    /// 
    /// This uses a custom even to trigger cloudscript which
    /// performs the stat updates
    /// 
    public static void UpdateStatistic(string stat, int value)
    {
		PlayFabClientAPI.WritePlayerEvent(
            // Request
            new WriteClientPlayerEventRequest
            {
                EventName = "update_statistic",
                Body = new Dictionary<string, object>
                {
                    { "stat_name", stat },
                    { "value", value }
                }
            },
            // Success
            (WriteEventResponse response) =>
            {
                Debug.Log("WritePlayerEvent (UpdateStatistic) completed.");
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("WritePlayerEvent failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    // List of server configured leaderboards
    public static string[] LeaderboardList = 
    { 
        "best_time",
        "high_score",
        "total_score"
    };

	private static int m_NumLeaderboardSuccess = 0;
	private static  int m_NumLeaderboardError = 0;
	private static void OnLeaderboardResult(bool bSuccess, System.Action onSuccess, System.Action onFailed)
	{
		if (bSuccess)
		{
			++m_NumLeaderboardSuccess;
		}
		else
		{
			++m_NumLeaderboardError;
		}

		// Are we done?
		if (m_NumLeaderboardSuccess + m_NumLeaderboardError == LeaderboardList.Length)
		{
			if (m_NumLeaderboardError == 0)
			{
				onSuccess();
			}
			else
			{
				onFailed();
			}
		}
	}

    ////////////////////////////////////////////////////////////////
    /// Load the leaderboard data
    /// 
    public static void LoadLeaderboards(System.Action onSuccess, System.Action onFailed)
    {
		m_NumLeaderboardSuccess = 0;
		m_NumLeaderboardError = 0;

		LeaderboardData = new Dictionary<string, List<PlayerLeaderboardEntry>>();

        foreach (string board in LeaderboardList)
        {
            PlayFabClientAPI.GetLeaderboard(
                // Request
                new GetLeaderboardRequest
                {
                    StatisticName = board,
                    StartPosition = 0,
                    MaxResultsCount = MaxLeaderboardEntries
                },
                // Success
                (GetLeaderboardResult result) =>
                {
                    var boardName = (result.Request as GetLeaderboardRequest).StatisticName;
                    LeaderboardData[boardName] = result.Leaderboard;
                    AreLeaderboardsLoaded = true;
                    Debug.Log(string.Format("GetLeaderboard completed: {0}", boardName));
					OnLeaderboardResult(true, onSuccess, onFailed);
				},
                // Failure
                (PlayFabError error) =>
                {
                    Debug.LogError("GetLeaderboard failed.");
                    Debug.LogError(error.GenerateErrorReport());
					OnLeaderboardResult(false, onSuccess, onFailed);
				}
                );
        }
	}

    // Max entries to retrieve; based on UI space
    public static int MaxLeaderboardEntries = 7;

    // Flag set when leaderboards have been loaded
    public static bool AreLeaderboardsLoaded = false;

    // Cache for leaderboard data
    private static Dictionary<string, List<PlayerLeaderboardEntry>> LeaderboardData;

    // Access for leaderboards
    public static List<PlayerLeaderboardEntry> GetLeaderboard(string board)
    {
        return LeaderboardData[board];
    }
}
