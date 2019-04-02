using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PopupError : MonoBehaviour
{
    public Text titleText;
    public Text messageText;

    static PopupError errorPanel;

    // Start is called before the first frame update
    void Start()
    {
        errorPanel = this;
        GetComponentInChildren<Button>().onClick.AddListener(OkButton);
    }

    private void DisplayError(string title, string message)
    {
        titleText.text = title;
        messageText.text = message;
    }

    void OkButton()
    {
        gameObject.SetActive(false);
    }

    public static void ShowErrorMessage(string title, string message)
    {
        errorPanel.gameObject.SetActive(true);
        errorPanel.DisplayError(title, message);
    }
}
