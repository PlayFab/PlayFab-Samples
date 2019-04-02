using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CatalogViewItem : MonoBehaviour {

    private ICatalogItem item;

    public void Initialize(ICatalogItem catalogItem, Vector3 position)
    {
        item = catalogItem;

        var image = GetComponentInChildren<Image>();

        var texture = Resources.Load<Texture2D>("icon_" + getIconFromItemId(catalogItem.Id));

        image.sprite = Sprite.Create(texture, image.sprite.rect, image.sprite.pivot);

        var itemName = GetComponentInChildren<Text>();
        itemName.text = catalogItem.DisplayName;

        RefreshPrice();

        var purchaseButton = GetComponentInChildren<Button>();
        purchaseButton.onClick.AddListener(() =>
        {
            PlayFabCommerceManager.Instance.PurchaseItem(item);
        });

        (transform as RectTransform).position = position;
    }

    public void RefreshPrice()
    {
        var purchaseButton = GetComponentInChildren<Button>();
        var buttonText = purchaseButton.GetComponentInChildren<Text>();
        buttonText.text = item.CostString;
    }

    public static string getIconFromItemId(string itemId)
    {
        itemId = itemId.ToLower();
        if (itemId.Contains("arrow"))
        {
            return "arrow";
        }
        else if (itemId.Contains("potion"))
        {
            return "potion";
        }
        else if (itemId.Contains("mystery"))
        {
            return "crate";
        }
        else if (itemId.Contains("100tc"))
        {
            return "coins_small";
        }
        else if (itemId.Contains("1000tc"))
        {
            return "coins_large";
        }
        else
        {
            return itemId;
        }
    }
}
