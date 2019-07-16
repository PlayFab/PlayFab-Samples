// Copyright (C) Microsoft Corporation. All rights reserved.

namespace PlayFab.TicTacToeDemo
{
    public static class Settings
    {
        public static void UpdateSettings()
        {
            PlayFabSettings.TitleId = Constants.TITLE_ID;
            PlayFabSettings.VerticalName = Constants.CLOUD_NAME;
            PlayFabSettings.CompressApiData = Constants.COMPRESS_API_DATA;
        }
    }
}
