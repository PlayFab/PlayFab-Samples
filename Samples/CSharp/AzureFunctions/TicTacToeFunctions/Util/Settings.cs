// Copyright (C) Microsoft Corporation. All rights reserved.

namespace PlayFab.TicTacToeDemo.Util
{
    public static class Settings
    {
        public static void TrySetSecretKey(ref PlayFabApiSettings settings)
        {
            string? secretKey = Environment.GetEnvironmentVariable(Constants.PLAYFAB_DEV_SECRET_KEY, EnvironmentVariableTarget.Process);

            if (!string.IsNullOrEmpty(secretKey))
            {
                settings.DeveloperSecretKey = secretKey;
            }
        }

        public static void TrySetCloudName(ref PlayFabApiSettings settings)
        {
            string? cloud = Environment.GetEnvironmentVariable(Constants.PLAYFAB_CLOUD_NAME, EnvironmentVariableTarget.Process);

            if (!string.IsNullOrEmpty(cloud))
            {
                settings.VerticalName = cloud;
            }
        }
    }
}
