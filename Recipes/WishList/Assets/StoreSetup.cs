using System;

using PlayFab;
using PlayFab.GroupsModels;
using PlayFab.ClientModels;
using PlayFab.DataModels;
using PlayFab.Json;

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.UI;

public class StoreSetup : MonoBehaviour {

    /* Buttons that appear in our Unity game. */

    public static Button Login_Button, Cat_Button, Dog_Button, Mango_Button;

    public static InputField Field;

    /*
        When the player logs in, set up the store in our Unity game. Namely, set the button colors and text.
    */

    public static void StoreStart() {
        Cat_Button = GameObject.FindGameObjectWithTag("Cat_Button").GetComponent<Button>();
        Dog_Button = GameObject.FindGameObjectWithTag("Dog_Button").GetComponent<Button>();
        Mango_Button = GameObject.FindGameObjectWithTag("Mango_Button").GetComponent<Button>();

        Field = GameObject.FindGameObjectWithTag("ViewWishlistField").GetComponent<InputField>();

        Cat_Button.GetComponentInChildren<Text>().text = "Cat (Add to Wishlist)";
        Cat_Button.GetComponent<Image>().color = Color.white; 

        Dog_Button.GetComponentInChildren<Text>().text = "Dog (Add to Wishlist)";
        Dog_Button.GetComponent<Image>().color = Color.white;

        Mango_Button.GetComponentInChildren<Text>().text = "Mango (Add to Wishlist)";
        Mango_Button.GetComponent<Image>().color = Color.white;       

    }

    /*
        Set up the store buttons based on the CSV wish list OR update store after an item is removed from
        the wish list.

        @param item_ids: If initially setting up the store, CSV of ItemIDs on the wish list. If updating the store
            after an ItemID is removed from the wish list, then the ItemID of the item that was removed.
        @param remote_tem: true if an item is being removed, false otherwise.

        The second parameter allows us to call this function when the store is initially set up, and also when
        an item is removed from the wish list. 
        
        For initial setup, StoreSetup.StoreStart initializes all buttons to
        the color white and text indicating that they are not on the wishlist. For all items on the wishlist, 
        SetUpStore changes the corresponding button color to green and text to indicate that the item is on the wish list.

        If an item is removed from the wishlist and we need to update the store, then the items array will have one element. That
        one element is the ItemID for the item we removed. The function then changes the button color and text to indicate that
        the item is no longer on the wish list.
    */

    public static void SetUpStore(string item_ids, bool remove_item) {
        
        string[] items = item_ids.Split(',');

        for(int j = 0; j < items.Length; j++) {

            if( items[j].Equals("cat") ) {
                if( !remove_item ) {
                    Cat_Button.GetComponentInChildren<Text>().text = "Cat (Added!)";
                    Cat_Button.GetComponent<Image>().color = Color.green;
                } else {
                    Cat_Button.GetComponentInChildren<Text>().text = "Cat (Add to Wishlist)";
                    Cat_Button.GetComponent<Image>().color = Color.white;                   
                }
            } else if( items[j].Equals("dog") ) {
                if( !remove_item ) {
                    Dog_Button.GetComponentInChildren<Text>().text = "Dog (Added!)";
                    Dog_Button.GetComponent<Image>().color = Color.green;
                } else {
                    Dog_Button.GetComponentInChildren<Text>().text = "Dog (Add to Wishlist)";
                    Dog_Button.GetComponent<Image>().color = Color.white;
                }
            } else if( items[j].Equals("mango") ) {
                if( !remove_item ) {
                    Mango_Button.GetComponentInChildren<Text>().text = "Mango (Added!)";
                    Mango_Button.GetComponent<Image>().color = Color.green;
                } else {
                    Mango_Button.GetComponentInChildren<Text>().text = "Mango (Add to Wishlist)";
                    Mango_Button.GetComponent<Image>().color = Color.white;     
                }
            }
        }

    }

    public void GetWishList() {

        WishList.ViewPlayerWishList(Field.text);

    }

}
