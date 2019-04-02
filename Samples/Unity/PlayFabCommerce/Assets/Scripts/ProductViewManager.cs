using PlayFab;
using PlayFab.ClientModels;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ProductViewManager : MonoBehaviour {

    public GameObject catalogItemView;
    public GameObject uiParent;

    public GameObject sampleCanvas;

    private Vector3 RowStart = new Vector3(-400, 175);
    private Vector3 RowOffset = new Vector3(0,-350);
    private Vector3 ColumnOffset = new Vector3(200, 0);
    private int ItemsPerRow = 4;

    private List<CatalogViewItem> catalogItemViews = new List<CatalogViewItem>();
    
	// Use this for initialization
	void Start () {

        //if(isMobilePLatform) // Editor can't spoof this...
        {
            float widthInches = (Screen.width * .9f) / Screen.dpi; // screen width in inches
            float heightInches = Screen.height / Screen.dpi; // screen height in inches

            ItemsPerRow = (int)(widthInches / (ColumnOffset.x / Screen.dpi));

            float columnWidth = Screen.width * .9f / ItemsPerRow;
            ColumnOffset.x = columnWidth;


            RowStart = new Vector3(Screen.width * .05f + ColumnOffset.x / 2, -100);
        }
    }

    public void ViewInit()
    {
        

        sampleCanvas.SetActive(true);
    }

    public void AquiredCatalogItems(List<ICatalogItem> catalog)
    {
        var pos = new Vector3(RowStart.x, RowStart.y);
        int colCount = 0;
        int rowCount = 0;

        var parentOffset = uiParent.transform.position;

        catalogItemViews.Clear();

        foreach (var item in catalog)
        {
            var itemView = Instantiate(catalogItemView, uiParent.transform);

            var view = itemView.GetComponent<CatalogViewItem>();

            catalogItemViews.Add(view);

            view.Initialize(item, pos + parentOffset);

            if (++colCount >= ItemsPerRow)
            {
                ++rowCount;
                pos = new Vector3(RowStart.x, RowStart.y);
                pos += (rowCount * RowOffset);
                colCount = 0;
            }
            else
            {
                pos += ColumnOffset;
            }
        }

        var rect = uiParent.GetComponent<RectTransform>();
        rect.sizeDelta = new Vector2(rect.sizeDelta.x, 350 * (rowCount + 1));
        Debug.Log(rowCount);
    }

    void OnError(PlayFabError error)
    {

    }

    internal void RefreshStorePrices()
    {
        foreach(var view in catalogItemViews)
        {
            view.RefreshPrice();
        }
    }
}
