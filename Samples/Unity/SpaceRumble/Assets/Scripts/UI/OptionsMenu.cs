//--------------------------------------------------------------------------------------
// OptionsMenu.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using UnityEngine;
using UnityEngine.UI;

public class OptionsMenu : MonoBehaviour{

    public Color NormalColor;
    public Color SelectedColor;

    private int CurrentColor;
    private int CurrentStyle;
    private InputField CurrentInput;

    private int PreviousColor;
    private int PreviousStyle;
    private string PreviousName;

    void Start ()
    {
        // Keep track of the User Name input
        CurrentInput = transform.Find("InputField").GetComponent<InputField>();

        // Set the UI with the current settings
        CurrentInput.text = PlayFabManager.UserDisplayName;

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

        CurrentStyle = int.Parse(style);
        CurrentColor = int.Parse(color);

        SelectShip(CurrentStyle);
        SelectColor(CurrentColor);

        PreviousColor = CurrentColor;
        PreviousStyle = CurrentStyle;
        PreviousName = CurrentInput.text;
    }

    public void SelectShip(int ship)
    {
        // Update slected ship style
        CurrentStyle = ship;

        // Change the background of the selected button to a highlited color
        // This requires the first four children of the panel to be the ship
        // style buttons (indexes 0 - 3)
        for (int x = 0; x < 4; x++)
        {
            if (x == ship)
            {
                transform.GetChild(x).GetComponent<Image>().color = SelectedColor;
            }
            else
            {
                transform.GetChild(x).GetComponent<Image>().color = NormalColor;
            }
        }
    }

    public void SelectColor(int color)
    {
        // Update selecte ship color
        CurrentColor = color;

        // Change the background of the selected button to a highlited color
        // This requires the second four children of the panel to be the ship
        // color buttons (indexes 4 - 7)
        for (int x = 0; x < 4; x++)
        {
            if (x == color)
            {
                transform.GetChild(x + 4).GetComponent<Image>().color = SelectedColor;
            }
            else
            {
                transform.GetChild(x + 4).GetComponent<Image>().color = NormalColor;
            }
        }
    }

    public void SaveOptions()
    {
        // Write the current values to the service
        if (CurrentStyle != PreviousStyle || CurrentColor != PreviousColor)
        {
            PlayFabManager.StoreUserData(CurrentStyle, CurrentColor);
            PreviousColor = CurrentColor;
            PreviousStyle = CurrentStyle;
        }

        if (PreviousName != CurrentInput.text)
        {
            PlayFabManager.SetUserDisplayName(CurrentInput.text);
            PreviousName = CurrentInput.text;
        }

        GameObject.Find("GameManager").GetComponent<GameManager>().HaveSetUserName = false;
    }
}
