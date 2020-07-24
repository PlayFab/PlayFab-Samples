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

public class WishList : MonoBehaviour
{

    /* The following variables are to identify the group entity which holds the wish list. */
    /* They are first set in the WishList.FindOrCreateWishList function */

    public static string group_entityKeyId;
    public static string group_entityKeyType;

    /* 
        Find the entity group for the player's wish list, or create one if does not exist

        @param player_entityKeyId: the entity ID of the player; for a title entity the ID should be;
            in most cases, this can be found in LoginResult.EntityToken.Entity.Id 
        @param player_entityKeyType: the entity type of the player whose wish list we are searching
            for; should be title_player_account entity in most cases
        
    */

    public static void FindOrCreateWishList(string player_entityKeyId, string player_entityKeyType) {

        PlayFab.DataModels.EntityKey ent = new PlayFab.DataModels.EntityKey { Id = player_entityKeyId, Type = player_entityKeyType };

        var req = new PlayFab.DataModels.GetObjectsRequest { Entity = ent };

        PlayFabDataAPI.GetObjects( req, result => {

            if( !result.Objects.ContainsKey("wishlist") ) {

                // Empty so need to create
                CreateEntityWishList();

            } else {

                string wl = (string) result.Objects["wishlist"].DataObject;

                // Exists so can set up store
                StoreSetup.SetUpStore(wl, false);

            }

        }, error => { Debug.LogError(error.GenerateErrorReport()); });

    }

    /* 

        If the item is on the wish list, remove it. If the item is not on the wish list, add it.

        @param item_id: ItemID of the item to be added to or remove from the wishlist
        
        This function gets the "wishlist" object from the entity group data. If the item is on the wish list,
        this function updates the CSV by removing it. If the item is not on the wish list, this function
        updates the CSV by adding it. It then calls UpdateObject, which updates the actual entity group data.

    */

    public void UpdateWishlist(string item_id) {

        PlayFab.DataModels.EntityKey ek = new PlayFab.DataModels.EntityKey { Id = LoginClass.getPlayerEntityKeyId(), Type = LoginClass.getPlayerEntityKeyType() };

        var getObjectRequest = new PlayFab.DataModels.GetObjectsRequest { Entity = ek };

        /* GetObjects to get the wish list in CSV form. */
        PlayFabDataAPI.GetObjects(getObjectRequest, objectResult => {

            string wl;
            bool adding_item; // This tells us whether we are adding or removing an item from the wish list


            if( !string.IsNullOrEmpty( (string) objectResult.Objects["wishlist"].DataObject ) ) {
                                    
                wl = (string) objectResult.Objects["wishlist"].DataObject; // string of the CSV of items on the wish list
                
                if( !WishlistContainsItem(wl, item_id) ) {
                    
                    /* Wish list does not contain the item, so we must add it. */
                    wl = AddItemToCSV(wl, item_id);
                    adding_item = true;

                } else {
                    /* Wish list contains item, so we must remove it. */
                    wl = RemoveItemFromCSV(wl, item_id);
                    adding_item = false;

                }
            } else {

                wl = item_id;
                adding_item = true;
            }

            /* UpdateObject is where the entity group data is actually updated */
            UpdateObject(wl, adding_item, item_id);
            
        }, error => {
            Debug.LogError(error.GenerateErrorReport());
        });               

    }

    /* 

        Remove an ItemID from the CSV.

        @param csv: the CSV list of ItemID's on the wish list
        @param item_id: ItemID of the item to be added to be removed from the wishlist

        @return the updated CSV

    */

    private static string RemoveItemFromCSV(string csv, string item_id) {
        /* Split CSV into an array of ItemIDs  */
        string[] items = csv.Split(',');
        int ind = Array.IndexOf(items, item_id); // item at which ItemID exists
        List<string> items_list = new List<string>(items); // Convert array to list for easy removal

        /* Only try to remove if the ItemID shows up in the CSV */
        if( ind != -1 ) {
            items_list.RemoveAt(ind);
        }

        string updated_csv = string.Join(",", items_list);
        return updated_csv;
    }

    /* 

        Add an ItemID to the CSV.

        @param csv: the CSV list of ItemID's on the wish list
        @param item_id: ItemID of the item to be added to the wishlist

        @return the updated CSV

    */

    private static string AddItemToCSV(string csv, string item_id) {
        return csv + "," + item_id;
    }

    /* 

        See if a wish list CSV contains a specific ItemID.

        @param csv: the CSV list of ItemID's on the wish list
        @param item_id: ItemID of the item

        @return true if the wish list contains the item, false otherwise

    */

    private static bool WishlistContainsItem(string csv, string item_id) {
        /* Split CSV into an array of ItemIDs  */
        string[] items = csv.Split(',');
        int ind = Array.IndexOf(items, item_id); // item at which ItemID exists
        List<string> items_list = new List<string>(items); // Convert array to list for easy removal

        if( ind != -1 ) {
            return true;
        } else {
            return false;
        }

    }

    /* 

        Execute a PlayFab Cloud Script function to update the group entity object data to the
        updated CSV. Title-level data should not be changed directly from the client.

        @param dataobj: the updated CSV; the Cloud Script function sets the entity group object data to
            this value.
        @param item_id: ItemID of the item that was either added or removed

    */

    private void UpdateObject(string dataobj, bool adding_item, string item_id) {

        PlayFab.DataModels.EntityKey entity = new PlayFab.DataModels.EntityKey { Id = LoginClass.getPlayerEntityKeyId(), Type = LoginClass.getPlayerEntityKeyType() };

        List<PlayFab.DataModels.SetObject> ObjList = new List<PlayFab.DataModels.SetObject>();

        ObjList.Add( 

            new PlayFab.DataModels.SetObject {
                ObjectName = "wishlist",
                DataObject = dataobj
            }

        );

        var request = new PlayFab.DataModels.SetObjectsRequest { 

            Entity = entity,
            Objects = ObjList
            
        };

        PlayFabDataAPI.SetObjects(request, result => {

            if( adding_item ) {
                StoreSetup.SetUpStore(item_id, false);
            } else {
                StoreSetup.SetUpStore(item_id, true);
            }

        }, error => { Debug.LogError(error.GenerateErrorReport()); });

    }


    /*

        If the wish list does not exist, we create an entity object for the player.

    */

    private static void CreateEntityWishList() {

        PlayFab.DataModels.EntityKey entity = new PlayFab.DataModels.EntityKey { Id = LoginClass.getPlayerEntityKeyId(), Type = LoginClass.getPlayerEntityKeyType() };

        /* SetObjects takes in a list of type SetObject. These will contain the objects that we want to set. */

        List<PlayFab.DataModels.SetObject> ObjList = new List<PlayFab.DataModels.SetObject>();

        /*  
            We will add an object of type wishlist. The DataObject is empty because we are initializing the entity object,
            as it does not exist. We do not have any ItemId's to add to the wish list yet. 
        */

        ObjList.Add(

            new PlayFab.DataModels.SetObject {
                ObjectName = "wishlist",
                DataObject = ""
            }

        );

        var request = new PlayFab.DataModels.SetObjectsRequest { 

            Entity = entity,
            Objects = ObjList
            
        };

        /* Call PlayFab SetObjects to set the object data for the player entity. */

        PlayFabDataAPI.SetObjects(request, result => {

            /* The title player now has a wishlist object. */

            Debug.Log("Set object successful");

        }, error => { Debug.LogError(error.GenerateErrorReport()); });

    }

    /* 

        This function gets a player's wish list.

        @param PlayFabID: the PlayFabId of the user whose wish list we want to see

    */

    public static void ViewPlayerWishList(string PlayFabID) {

        /* We have their PlayFabID, but we need their title player ID in order to make an entity key. */

        PlayFabClientAPI.GetAccountInfo(new PlayFab.ClientModels.GetAccountInfoRequest {

            PlayFabId = PlayFabID

        }, AccountInfoResult => {

            /* The below contains the title player Id */

            var id = AccountInfoResult.AccountInfo.TitleInfo.TitlePlayerAccount.Id;

            /* Now that we have their title player ID, we can use GetObjects to get their wish list */

            PlayFabDataAPI.GetObjects(new PlayFab.DataModels.GetObjectsRequest {

                /* GetObjects has an entity key parameter */

                Entity = new PlayFab.DataModels.EntityKey { Id = id, Type = "title_player_account" }

            }, GetObjectsResult => {

                /*  
                    GetObjects returns a dictionary of objects. We are interested in the "wishlist"
                    key-value pair.
                */

                if( GetObjectsResult.Objects.ContainsKey("wishlist") ) {

                    Debug.Log(GetObjectsResult.Objects["wishlist"].DataObject);

                } else {

                    Debug.Log("Player has no wish list");

                }

            }, error => { Debug.LogError(error.GenerateErrorReport()); }); 

        }, error => {

            Debug.LogError(error.GenerateErrorReport());

        });

    }


}
