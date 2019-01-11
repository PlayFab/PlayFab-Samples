using Microsoft.WindowsAzure.Storage;
using Microsoft.WindowsAzure.Storage.Auth;
using Microsoft.WindowsAzure.Storage.Blob;
using PlayFab;
using PlayFab.AuthenticationModels;
using PlayFab.MultiplayerModels;
using System;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;

/////////////////////////////////////////
// NOTE: Before using this class you MUST set PlayFab.PlayFabSettings.TitleId and PlayFab.PlayFabSettings.DeveloperSecretKey
/////////////////////////////////////////

class PlayFabMultiplayerServerHelper
{
    public static PlayFabMultiplayerServerHelper Singleton = null;

    public PlayFabMultiplayerServerHelper()
    {
        Singleton = this;
    }

    /// <summary>
    /// Authenticates with the PlayFab backend & obtains an entity token for the title.
    /// </summary>
    /// <returns>
    /// Boolean representing whether the call was successful or not
    /// </returns>
    public async Task<bool> GetTitleEntityToken()
    {
        // Reset our entity token
        m_EntityToken = String.Empty;

        var key = new PlayFab.AuthenticationModels.EntityKey();
        key.Id = PlayFab.PlayFabSettings.TitleId;

        var tokenRequest = new GetEntityTokenRequest();
        tokenRequest.Entity = key;

        // Get an entity token from the PF backend using our title ID
        PlayFabResult<GetEntityTokenResponse> taskResult = await PlayFab.PlayFabAuthenticationAPI.GetEntityTokenAsync(tokenRequest);

        // Check the response for an error
        bool hasError = CheckForError(taskResult);
        if (!hasError)
        {
            m_EntityToken = taskResult.Result.EntityToken;
        }
        else
        {
            m_EntityToken = String.Empty;
        }

        return !hasError;
    }

    /// <summary>
    /// Checks that the title is enabled (provisioned) for PlayFab Multiplayer Servers
    /// </summary>
    /// <returns>
    /// Boolean representing whether the call was successful or not
    /// </returns>
    public async Task<bool> IsTitleProvisioned()
    {
        PlayFabResult<GetTitleEnabledForMultiplayerServersStatusResponse> taskResult = await PlayFab.PlayFabMultiplayerAPI.GetTitleEnabledForMultiplayerServersStatusAsync(null);

        bool hasError = CheckForError(taskResult);
        if (!hasError)
        {
            return taskResult.Result.Status == TitleMultiplayerServerEnabledStatus.Enabled;
        }
        return !hasError;
    }

    /// <summary>
    /// Enables PlayFab Multiplayer for the title
    /// </summary>
    /// <returns>
    /// Boolean representing whether the call was successful or not
    /// </returns>
    public async Task<bool> ProvisionTitle()
    {
        var taskResult = await PlayFab.PlayFabMultiplayerAPI.EnableMultiplayerServersForTitleAsync(null);

        bool hasError = CheckForError(taskResult);
        return !hasError;
    }

    /// <summary>
    /// Helper function which checks fora PlayFabBaseResult for an error
    /// </summary>
    /// <returns>
    /// Boolean representing whether an error was present or not
    /// </returns>
    private bool CheckForError(PlayFabBaseResult result)
    {
        if (result.Error != null)
        {
            return true;
        }
        return false;
    }

    /// <summary>
    /// Retrieves a list of builds
    /// </summary>
    /// <returns>
    /// A list container of build information
    /// </returns>
    public async Task<List<BuildSummary>> QueryBuilds()
    {
        if (IsAuthenticated())
        {
            var task = PlayFab.PlayFabMultiplayerAPI.ListBuildSummariesAsync(null);
            var resp = await task;
            return resp.Result.BuildSummaries;
        }

        return null;
    }

    /// <summary>
    /// Retrieves a list of multiplayer servers
    /// </summary>
    /// <returns>
    /// A list container of running multiplayer server information
    /// </returns>
    public async Task<List<MultiplayerServerSummary>> QueryMultiplayerServers(string buildID, AzureRegion region)
    {
        // We must be authenticated to make this call
        if (IsAuthenticated())
        {
            ListMultiplayerServersRequest request = new ListMultiplayerServersRequest();
            request.BuildId = buildID;
            request.Region = region;

            var task = PlayFab.PlayFabMultiplayerAPI.ListMultiplayerServersAsync(request);
            var resp = await task;

            return resp.Result.MultiplayerServerSummaries;
        }

        return null;
    }

    /// <summary>
    /// Retrieves a list of virtual machines
    /// </summary>
    /// <returns>
    /// A list container of running VMs
    /// </returns>
    public async Task<List<VirtualMachineSummary>> QueryVMs(string buildID, AzureRegion region)
    {
        // We must be authenticated to make this call
        if (IsAuthenticated())
        {
            ListVirtualMachineSummariesRequest request = new ListVirtualMachineSummariesRequest();
            request.BuildId = buildID;
            request.Region = region;

            var task = PlayFab.PlayFabMultiplayerAPI.ListVirtualMachineSummariesAsync(request);
            var resp = await task;

            return resp.Result.VirtualMachines;
        }

        return null;
    }

    /// <summary>
    /// Requests a multiplayer server from the backend.
    /// This will return an existing allocated server with the same session ID if one exists. Otherwise, a new server is allocated.
    /// </summary>
    /// <returns>
    /// Details of the server
    /// </returns>
    public async Task<RequestMultiplayerServerResponse> RequestMultiplayerServer(string buildID, List<AzureRegion> regions, string sessionCookie, string sessionID)
    {
        // We must be authenticated to make this call
        if (IsAuthenticated())
        {
            RequestMultiplayerServerRequest request = new RequestMultiplayerServerRequest();
            request.BuildId = buildID;
            request.PreferredRegions = regions;
            request.SessionCookie = sessionCookie;
            request.SessionId = sessionID;

            var task = PlayFab.PlayFabMultiplayerAPI.RequestMultiplayerServerAsync(request);
            var resp = await task;

            bool hasError = CheckForError(resp);
            if (!hasError)
            {
                return resp.Result;
            }
            else
            {
                throw new Exception(String.Format("Allocate failed with error: {0}", resp.Error.ErrorMessage));
            }
        }

        return null;
    }

    /// <summary>
    /// Requests the shutdown of a multiplayer server
    /// </summary>
    /// <returns>
    /// Boolean representing whether the call was successful or not
    /// </returns>
    public async Task<bool> ShutdownMultiplayerServer(string buildID, AzureRegion region, string sessionID)
    {
        if (IsAuthenticated())
        {
            ShutdownMultiplayerServerRequest request = new ShutdownMultiplayerServerRequest();
            request.BuildId = buildID;
            request.Region = region;
            request.SessionId = sessionID;

            var task = PlayFab.PlayFabMultiplayerAPI.ShutdownMultiplayerServerAsync(request);
            var resp = await task;

            bool hasError = CheckForError(resp);
            if (!hasError)
            {
                return true;
            }
            else
            {
                throw new Exception(String.Format("Deallocate failed with error: {0}", resp.Error.ErrorMessage));
            }
        }

        return false;
    }

    /// <summary>
    /// Retrieves the status of a multiplay server by session ID
    /// </summary>
    /// <returns>
    /// Status of the server
    /// </returns>
    public async Task<GetMultiplayerServerDetailsResponse> GetMultiplayerServerStatus(string buildID, string sessionId)
    {
        if (IsAuthenticated())
        {
            GetMultiplayerServerDetailsRequest request = new GetMultiplayerServerDetailsRequest
            {
                BuildId = buildID,
                SessionId = sessionId
            };

            var task = PlayFab.PlayFabMultiplayerAPI.GetMultiplayerServerDetailsAsync(request);
            var resp = await task;

            bool hasError = CheckForError(resp);
            if (!hasError)
            {
                return resp.Result;
            }
            else
            {
                throw new Exception(String.Format("GetMultiplayerServerStatus failed with error: {0}", resp.Error.ErrorMessage));
            }
        }

        return null;
    }

    // This class represents the information required to connect to a server via remote desktop
    public class RDPInformation
    {
        public string Username;
        public string Password;
        public string Address;
        public int Port;
    }

    /// <summary>
    /// Creates a build
    /// </summary>
    /// <returns>
    /// Boolean representing whether the call was successful or not
    /// </returns>
    public async Task<bool> CreateBuild(
        string strName,
        ContainerFlavor containerFlavor,
        List<AssetReferenceParams> lstGameAssets,
        List<GameCertificateReferenceParams> lstCertificates,
        List<Port> lstPorts,
        Dictionary<string, string> metaData,
        List<BuildRegionParams> lstRegions,
        int multiplayerServerCountPerVm,
        string strStartGameCommand,
        AzureVmSize VMSize
        )
    {
        // Create a build with the requested specificaitons
        CreateBuildWithManagedContainerRequest createRequest = new CreateBuildWithManagedContainerRequest()
        {
            BuildName = strName,
            ContainerFlavor = containerFlavor,
            GameAssetReferences = lstGameAssets,
            GameCertificateReferences = lstCertificates,
            Ports = lstPorts,
            Metadata = metaData,
            RegionConfigurations = lstRegions,
            MultiplayerServerCountPerVm = multiplayerServerCountPerVm,
            StartMultiplayerServerCommand = strStartGameCommand,
            VmSize = VMSize
        };

        var createResp = await PlayFabMultiplayerAPI.CreateBuildWithManagedContainerAsync(createRequest);

        bool hasError = CheckForError(createResp);
        if (hasError)
        {
            throw new Exception(String.Format("Create Build failed with error: {0}", createResp.Error.ErrorMessage));
        }

        return !hasError;
    }

    /// <summary>
    /// Uploads a certificate to be used with build creation
    /// </summary>
    /// <returns>
    /// Awaitable void Task
    /// </returns>
    public async Task UploadCertificate(string certificateLocalPath, string certificateName, string certificatePassword)
    {
        string base64Certificate = Convert.ToBase64String(File.ReadAllBytes(certificateLocalPath));
        Certificate newCert = new Certificate() { Base64EncodedValue = base64Certificate, Name = certificateName, Password = certificatePassword };

        UploadCertificateRequest uploadCertRequest = new UploadCertificateRequest() { GameCertificate = newCert };

        var uploadCertResponse = await PlayFab.PlayFabMultiplayerAPI.UploadCertificateAsync(uploadCertRequest);
        bool hasError = CheckForError(uploadCertResponse);
        if (hasError)
        {
            throw new Exception(String.Format("Upload Certificate failed with error: {0}", uploadCertResponse.Error.ErrorMessage));
        }
    }

    /// <summary>
    /// Uploads an asset (e.g. a server build, or art assets/other files to be deployed onto the docker container
    /// </summary>
    /// <returns>
    /// String representing the deployed file name
    /// </returns>
    public async Task<string> UploadAsset(string assetLocalPath, Dictionary<string, string> metaData)
    {
        metaData.Add("OriginalFilePath", assetLocalPath);


        // NOTE: We append a timestamp here to provide uniqueness. Duplicate asset keys are not allowed.
        Int32 unixTimestamp = (Int32)(DateTime.UtcNow.Subtract(new DateTime(1970, 1, 1))).TotalSeconds;
        string assetRemoteName = String.Format("0_{0}_{1}", unixTimestamp, System.IO.Path.GetFileName(assetLocalPath));

        GetAssetUploadUrlRequest assetURLRequest = new GetAssetUploadUrlRequest
        {
            FileName = assetRemoteName,
        };

        var assetURLResponse = await PlayFab.PlayFabMultiplayerAPI.GetAssetUploadUrlAsync(assetURLRequest);
        bool hasError = CheckForError(assetURLResponse);
        if (!hasError)
        {
            // parse SAS token
            string sasToken = assetURLResponse.Result.AssetUploadUrl;
            sasToken = sasToken.Remove(sasToken.LastIndexOf("&api"));
            string storageAccountName = sasToken.Substring(8, sasToken.IndexOf("blob") - 9);
            sasToken = sasToken.Substring(sasToken.IndexOf("sv"));

            // Azure storage auth using SAS token
            StorageCredentials accountSAS = new StorageCredentials(sasToken);

            // Use these credentials and the account name to create a Blob service client.
            CloudStorageAccount accountWithSAS = new CloudStorageAccount(accountSAS, storageAccountName, endpointSuffix: null, useHttps: true);

            // create and upload blob
            CloudBlobClient blobClient = accountWithSAS.CreateCloudBlobClient();
            CloudBlobContainer container = blobClient.GetContainerReference("gameassets");
            var blob = container.GetBlockBlobReference(assetRemoteName);
            blob.Properties.ContentType = "application/zip";
            await blob.UploadFromFileAsync(assetLocalPath);

            return assetURLResponse.Result.FileName;
        }
        else
        {
            throw new Exception(String.Format("Upload Asset failed with error: {0}", assetURLResponse.Error.ErrorMessage));
        }
    }

    /// <summary>
    /// Retrieves a list of all available assets
    /// </summary>
    /// <returns>
    /// List of assets and their details
    /// </returns>
    public async Task<List<AssetSummary>> GetAllAssets()
    {
        var task = await PlayFabMultiplayerAPI.ListAssetSummariesAsync(null);
        return task.Result.AssetSummaries;
    }

    /// <summary>
    /// Creates an account on a VM for RDP use
    /// </summary>
    /// <returns>
    /// RDP connection information including ip, port and credentials
    /// </returns>
    public async Task<RDPInformation> CreateRDPCredentials(string buildID, AzureRegion region, string VMID)
    {
        // Create a random username, usernames must be unique
        Random rng = new Random(Environment.TickCount);
        string strUsername = "RDPUser_" + rng.Next().ToString();
        DateTime expirationTime = DateTime.UtcNow.AddMinutes(60);

        CreateRemoteUserRequest request = new CreateRemoteUserRequest()
        {
            BuildId = buildID,
            Region = region,
            ExpirationTime = expirationTime,
            VmId = VMID,
            Username = strUsername,
        };

        // Create the user on the VM and retrieve the password generated by the backend service
        var resp = await PlayFab.PlayFabMultiplayerAPI.CreateRemoteUserAsync(request);
        string strPassword = resp.Result.Password;

        if (!CheckForError(resp))
        {
            GetRemoteLoginEndpointRequest endpointRequest = new GetRemoteLoginEndpointRequest()
            {
                BuildId = buildID,
                Region = region,
                VmId = VMID,
            };

            // Retrieve the RDP connection details for the VM
            var endpointResp = await PlayFab.PlayFabMultiplayerAPI.GetRemoteLoginEndpointAsync(endpointRequest);
            RDPInformation rdpInfo = new RDPInformation
            {
                Username = strUsername,
                Password = strPassword,
                Address = endpointResp.Result.IPV4Address,
                Port = endpointResp.Result.Port,
            };

            return rdpInfo;
        }

        return null;
    }

    /// <summary>
    /// Helper function to determine if the local device is authenticated
    /// </summary>
    /// <returns>
    /// Boolean representing whether the local device is authenticated or not
    /// </returns>
    public bool IsAuthenticated()
    {
        return m_EntityToken != String.Empty;
    }

    // MEMBERS
    private string m_EntityToken = String.Empty;
}

