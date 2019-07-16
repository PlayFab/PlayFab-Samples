// Copyright (C) Microsoft Corporation. All rights reserved.

using System;
using UnityEngine;

namespace PlayFab.TicTacToeDemo
{
    public class TokenPlaceholder : MonoBehaviour
    {
        public int row;
        public int col;

        public GameObject Token { get; set; }
        public OccupantType OccupantType { get; set; }

        public bool IsEnabled { get; set; }
        public bool IsClicked { get; set; }

        public Action<int, int> OnTokenPlaceholderClicked { get; set; }

        void Start()
        {
            var rend = GetComponent<Renderer>();
            rend.enabled = false;
        }

        private void OnMouseEnter()
        {
            if (Token == null && IsEnabled)
            {
                var rend = GetComponent<Renderer>();
                rend.enabled = true;
            }
        }

        private void OnMouseDown()
        {
            if (Token == null && IsEnabled)
            {
                IsClicked = true;
            }
        }

        private void OnMouseExit()
        {
            var rend = GetComponent<Renderer>();
            rend.enabled = false;
        }

        public void PlaceToken(GameObject tokenPrefab)
        {
            Token = Instantiate(tokenPrefab);
            Token.transform.SetParent(transform);
            Token.transform.position = transform.position;
            var renderer = GetComponent<Renderer>();
            renderer.enabled = false;
        }

        public void Reset()
        {
            IsClicked = false;
            Destroy(Token);
            Token = null;
            OccupantType = OccupantType.NONE;
        }
    }
}
