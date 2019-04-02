using PlayFab;
using PlayFab.ClientModels;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class InventoryViewManager : MonoBehaviour
{
    public GameObject uiParent;
    public GameObject sampleCanvas;

    public Text balanceValue;

    private Vector3 RowStart = new Vector3(0, 15);
    private Vector3 ItemOffset = new Vector3(0, 175);

    // Use this for initialization
    void Start()
    {
    }

    public void ViewInit()
    {
        sampleCanvas.SetActive(true);
    }

    public void UpdatePlayerInventory(GetUserInventoryResult result)
    {
        var pos = new Vector3(RowStart.x, RowStart.y);
        var parentOffset = uiParent.transform.position;

        foreach(var item in result.Inventory)
        {
            var itemView = uiParent.transform.Find(CatalogViewItem.getIconFromItemId(item.ItemId));

            itemView.GetComponentInChildren<Text>().text = item.RemainingUses.ToString();
            var button = itemView.GetComponentInChildren<Button>();
            button.onClick.RemoveAllListeners();
            button.onClick.AddListener(() =>
            {
                PlayFabCommerceManager.Instance.ConsumeSingleItem(item);
            });
        }

        balanceValue.text = result.VirtualCurrency["TC"].ToString() + " TC";
    }
}
