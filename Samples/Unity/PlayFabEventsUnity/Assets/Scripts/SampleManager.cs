using PlayFab;
using PlayFab.ClientModels;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SampleManager : MonoBehaviour
{
	private int CurrentLevel = 1;
	private int CharacterEventCounter = 0;
	private string CharacterIdToUse = null;
	public Text ConsoleUI;
	private const uint g_NumConsoleLines = 10;
	private string[] g_strConsoleContents = new string[g_NumConsoleLines];


	private void PushConsoleMessage(string message, params object[] formatParams)
	{
		// Shift everything up
		for (int i = 0; i < g_NumConsoleLines - 1; ++i)
		{
			g_strConsoleContents[i] = g_strConsoleContents[i + 1];
		}

		string strMessage = String.Format(message, formatParams);
		g_strConsoleContents[g_NumConsoleLines - 1] = strMessage;
		Debug.Log(strMessage);

		// Update UI element
		ConsoleUI.text = "";
		foreach (string strConsoleLine in g_strConsoleContents)
		{
			if (ConsoleUI.text.Length != 0)
			{
				ConsoleUI.text += "\n";
			}

			ConsoleUI.text += strConsoleLine;
		}
	}

	void Start()
	{
		PushConsoleMessage("Sample Started");

		if (PlayFabManager.IsLoggedIn == false)
		{
			PlayFabManager.Login(OnLoginSuccess, OnLoginFailed);
		}
	}

	private void OnLoginSuccess(LoginResult result)
	{
		// This sample requires at least one character. We create one below if no characters exist
		PlayFabClientAPI.GetAllUsersCharacters(new ListUsersCharactersRequest
		{
			PlayFabId = result.PlayFabId
		},
		// Success
		(ListUsersCharactersResult listUsersResult) =>
		{
			if (listUsersResult.Characters.Count == 0)
			{
				// Purchase the character consumable (required to grant the consumable)
				PlayFabClientAPI.PurchaseItem(new PurchaseItemRequest
				{
					ItemId = "Sample Warrior Class",
					Price = 0,
					VirtualCurrency = "SC"
				},
				// Success
				(PurchaseItemResult purchaseItemResult) =>
				{
					// Grant the character, based on the consumable
					PlayFabClientAPI.GrantCharacterToUser(new GrantCharacterToUserRequest
					{
						CharacterName = "Sample Character",
						ItemId = purchaseItemResult.Items[0].ItemId
					},
					// Success
					(GrantCharacterToUserResult grantCharacterResult) =>
					{
						CharacterIdToUse = grantCharacterResult.CharacterId;
					},
					// Failure
					(PlayFabError error) =>
					{
						PushConsoleMessage("ERROR: GrantCharacterToUser failed. Please verify your title is not configured on PlayFab GameManager.");
						PushConsoleMessage(error.GenerateErrorReport());
					}
					);
				},
				// Failure
				(PlayFabError error) =>
				{
					PushConsoleMessage("ERROR: PurchaseItem failed. Please verify your title is not configured on PlayFab GameManager.");
					PushConsoleMessage(error.GenerateErrorReport());
				}
				);
			}
			else
			{
				PushConsoleMessage(string.Format("Found {0} Characters: ", listUsersResult.Characters.Count));
				foreach (var user in listUsersResult.Characters)
				{
					PushConsoleMessage(string.Format("\t{0}: {1}", user.CharacterId, user.CharacterName));
				}

				CharacterIdToUse = listUsersResult.Characters[0].CharacterId;
			}
		},
		// Failure
		(PlayFabError error) =>
		{
			PushConsoleMessage("ERROR: GetAllUsersCharacters failed. Please verify your title is not configured on PlayFab GameManager.");
			PushConsoleMessage(error.GenerateErrorReport());
		}
		);
	}

	private void OnLoginFailed(PlayFabError error)
	{
		PushConsoleMessage("ERROR: Login Failed. Verify Title ID is set correctly.");
		PushConsoleMessage(error.GenerateErrorReport());
	}

	public void SendPlayerEvent_CompleteLevel()
	{
		PushConsoleMessage("Sent player event 'player_completed_level'");
		PlayFabClientAPI.WritePlayerEvent(new WriteClientPlayerEventRequest
		{
			EventName = "player_completed_level",
			Body = new Dictionary<string, object>()
			{
				{ "level_finished", ++CurrentLevel }
			}
		}, null, null);
	}

	public void SendTitleEvent_GameClientUpdated()
	{
		PushConsoleMessage("Sent title event 'game_client_updated'");
		PlayFabClientAPI.WriteTitleEvent(new WriteTitleEventRequest
		{
			EventName = "game_client_updated",
			Body = new Dictionary<string, object>()
			{
				{ "new_version", "1.0.0"}
			}
		}, null, null);
	}

	public void SendCharacterEvent_TestEvent()
	{
		PushConsoleMessage("Sent character event 'test_event'");
		PlayFabClientAPI.WriteCharacterEvent(new WriteClientCharacterEventRequest
		{
			EventName = "test_event",
			CharacterId = CharacterIdToUse,
			Body = new Dictionary<string, object>()
			{
				{ "counter", ++CharacterEventCounter}
			}
		}, null, null);
	}
}
