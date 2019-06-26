// Copyright (C) Microsoft Corporation. All rights reserved.

using UnityEngine;

public class TokenPlaceholder : MonoBehaviour
{
    public int row;
    public int col;

    public Board Board;
    public GameObject Token { get; set; }
    public OccupantType OccupantType { get; set; }
    
    void Start()
    {
        var rend = GetComponent<Renderer>();
        rend.enabled = false;
    }

    private void OnMouseEnter()
    {
        if (Token == null && Board.CanPlay) 
        {
            var rend = GetComponent<Renderer>();
            rend.enabled = true;
        }
    }

    private void OnMouseDown()
    {
        if (Token == null && Board.CanPlay)
        {
            Board.PlaceHumanToken(this);
        }
    }

    private void OnMouseExit()
    {
        var rend = GetComponent<Renderer>();
        rend.enabled = false;
    }
}
