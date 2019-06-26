// Copyright (C) Microsoft Corporation. All rights reserved.

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.Extensions.Logging;
using PlayFab.Internal;
using PlayFab.Json;
using PlayFab.ProfilesModels;

namespace PlayFab.AzureFunctions
{
    public static class LocalExecuteFunction
    {
        private const string DEV_SECRET_KEY = "PLAYFAB_DEV_SECRET_KEY";
        private const string TITLE_ID = "PLAYFAB_TITLE_ID";
        private const string CLOUD_NAME = "PLAYFAB_CLOUD_NAME";
        private static readonly HttpClient httpClient = new HttpClient();
        /// <summary>
        /// A local implementation of the ExecuteFunction feature. Provides the ability to execute an Azure Function with a local URL with respect to the host
        /// of the application this function is running in.
        /// </summary>
        /// <param name="functionRequest">The execution request</param>
        /// <param name="httpRequest">The HTTP request</param>
        /// <param name="log">A logger object</param>
        /// <returns>The function execution result(s)</returns>
        [FunctionName("ExecuteFunction")]
        public static async Task<HttpResponseMessage> ExecuteFunction(
            [HttpTrigger(AuthorizationLevel.Function, "post", Route = "CloudScript/ExecuteFunction")] HttpRequest request, ILogger log)
        {
            // Extract the caller's entity token
            string callerEntityToken = request.Headers["X-EntityToken"];

            // Extract the request body and deserialize
            string body = await DecompressHttpBody(request);
            var execRequest = PlayFabSimpleJson.DeserializeObject<ExecuteFunctionRequest>(body);

            // Create a FunctionContextInternal as the payload to send to the target function
            var functionContext = new FunctionContextInternal
            {
                CallerEntityProfile = await GetEntityProfile(callerEntityToken),
                TitleAuthenticationContext = new TitleAuthenticationContext
                {
                    Id = Environment.GetEnvironmentVariable(TITLE_ID, EnvironmentVariableTarget.Process),
                    EntityToken = await GetTitleEntityToken()
                },
                FunctionArgument = execRequest.FunctionParameter
            };

            // Serialize the request to the azure function and add headers
            var functionRequestContent = new StringContent(PlayFabSimpleJson.SerializeObject(functionContext));
            functionRequestContent.Headers.ContentType = new MediaTypeHeaderValue("application/json");

            var azureFunctionUri = ConstructLocalAzureFunctionUri(execRequest.FunctionName, request.Host);

            var sw = new Stopwatch();
            sw.Start();

            // Execute the local azure function
            using (var functionResponseMessage =
                await httpClient.PostAsync(azureFunctionUri, functionRequestContent))
            {
                sw.Stop();
                long executionTime = sw.ElapsedMilliseconds;

                if (!functionResponseMessage.IsSuccessStatusCode)
                {
                    throw new Exception($"An error occured while executing the target function locally: FunctionName: {execRequest.FunctionName}, HTTP Status Code: {functionResponseMessage.StatusCode}.");
                }

                // Extract the response content
                using (var functionResponseContent = functionResponseMessage.Content)
                {
                    // Prepare a response to reply back to client with and include function execution results
                    var functionResult = new ExecuteFunctionResult
                    {
                        FunctionName = execRequest.FunctionName,
                        FunctionResult = await ExtractFunctionResult(functionResponseContent),
                        ExecutionTimeMilliseconds = (int) executionTime,
                        FunctionResultTooLarge = false
                    };

                    // Reply back to client with final results
                    var output = new PlayFabJsonSuccess<ExecuteFunctionResult>
                    {
                        code = 200,
                        status = "OK",
                        data = functionResult
                    };
                    // Serialize the output and return it
                    var outputStr = PlayFabSimpleJson.SerializeObject(output);

                    return new HttpResponseMessage
                    {
                        Content = new ByteArrayContent(CompressResponseBody(output, request)),
                        StatusCode = HttpStatusCode.OK
                    };
                }
            }
        }

        /// <summary>
        /// Fetch's an entity's profile from the PlayFab server
        /// </summary>
        /// <param name="callerEntityToken">The entity token of the entity profile being fetched</param>
        /// <returns>The entity's profile</returns>
        private static async Task<EntityProfileBody> GetEntityProfile(string callerEntityToken) {
            // Construct the PlayFabAPI URL for GetEntityProfile
            var getProfileUrl = GetServerApiUri("/Profile/GetProfile");

            // Create the get entity profile request
            var profileRequest = new GetEntityProfileRequest { };

            // Prepare the request headers
            var profileRequestContent = new StringContent(PlayFabSimpleJson.SerializeObject(profileRequest));
            profileRequestContent.Headers.Add("X-EntityToken", callerEntityToken);
            profileRequestContent.Headers.ContentType = new MediaTypeHeaderValue("application/json");

            PlayFabJsonSuccess<GetEntityProfileResponse> getProfileResponseSuccess = null;
            GetEntityProfileResponse getProfileResponse = null;

            // Execute the get entity profile request
            using (var profileResponseMessage =
                    await httpClient.PostAsync(getProfileUrl, profileRequestContent))
            {
                using (var profileResponseContent = profileResponseMessage.Content)
                {
                    string profileResponseString = await profileResponseContent.ReadAsStringAsync();

                    // Deserialize the http response
                    getProfileResponseSuccess =
                        PlayFabSimpleJson.DeserializeObject<PlayFabJsonSuccess<GetEntityProfileResponse>>(profileResponseString);

                    // Extract the actual get profile response from the deserialized http response
                    getProfileResponse = getProfileResponseSuccess?.data;
                }
            }

            // If response object was not filled it means there was an error
            if (getProfileResponseSuccess?.data == null || getProfileResponseSuccess?.code != 200)
            {
                throw new Exception($"Failed to get Entity Profile: code: {getProfileResponseSuccess?.code}");
            }

            return getProfileResponse.Profile;
        }

        /// <summary>
        /// Grabs the developer secret key from the environment variable (expected to be set) and uses it to
        /// ask the PlayFab server for a title entity token.
        /// </summary>
        /// <returns>The title's entity token</returns>
        private static async Task<string> GetTitleEntityToken()
        {
            var titleEntityTokenRequest = new AuthenticationModels.GetEntityTokenRequest();

            var getEntityTokenUrl = GetServerApiUri("/Authentication/GetEntityToken");

            // Grab the developer secret key from the environment variables (app settings) to use as header for GetEntityToken
            var secretKey = Environment.GetEnvironmentVariable(DEV_SECRET_KEY, EnvironmentVariableTarget.Process);

            if (string.IsNullOrEmpty(secretKey))
            {
                // Environment variable was not set on the app
                throw new Exception("Could not fetch the developer secret key from the environment. Please set \"PLAYFAB_DEV_SECRET_KEY\" in your app's local.settings.json file.");
            }

            var titleEntityTokenRequestContent = new StringContent(PlayFabSimpleJson.SerializeObject(titleEntityTokenRequest));
            titleEntityTokenRequestContent.Headers.ContentType = new MediaTypeHeaderValue("application/json");
            titleEntityTokenRequestContent.Headers.Add("X-SecretKey", secretKey);

            using (var titleEntityTokenResponseMessage =
                await httpClient.PostAsync(getEntityTokenUrl, titleEntityTokenRequestContent))
            {
                using (var titleEntityTokenResponseContent = titleEntityTokenResponseMessage.Content)
                {
                    string titleEntityTokenResponseString = await titleEntityTokenResponseContent.ReadAsStringAsync();

                    // Deserialize the http response
                    var titleEntityTokenResponseSuccess =
                        PlayFabSimpleJson.DeserializeObject<PlayFabJsonSuccess<AuthenticationModels.GetEntityTokenResponse>>(titleEntityTokenResponseString);

                    // Extract the actual get title entity token header
                    var titleEntityTokenResponse = titleEntityTokenResponseSuccess.data;

                    return titleEntityTokenResponse.EntityToken;
                }
            }
        }

        /// <summary>
        /// Constructs a function's local url given its name and the current function app's host. Assumes that the
        /// function is located in the same function app as the application host provided.
        /// </summary>
        /// <param name="functionName">The name of the function to construct a URL for</param>
        /// <param name="appHost">The function's application host</param>
        /// <returns>The function's URI</returns>
        private static string ConstructLocalAzureFunctionUri(string functionName, HostString appHost)
        {
            // Assemble the target function's path in the current App
            string routePrefix = GetHostRoutePrefix();
            string functionPath = routePrefix != null ? routePrefix + "/" + functionName
                : functionName;

            // Build URI of Azure Function based on current host
            var uriBuilder = new UriBuilder
            {
                Host = appHost.Host,
                Port = appHost.Port ?? 80,
                Path = functionPath
            };

            return uriBuilder.Uri.AbsoluteUri;
        }

        private static async Task<object> ExtractFunctionResult(HttpContent content)
        {
            string responseContent = await content.ReadAsStringAsync();

            if (!string.IsNullOrWhiteSpace(responseContent))
            {
                // JSON object or array
                if (responseContent.StartsWith("{") || responseContent.StartsWith("["))
                {
                    return PlayFabSimpleJson.DeserializeObject(responseContent);
                }
                // JSON number
                else if (float.TryParse(responseContent, out float f))
                {
                    return f;
                }
                // JSON true or false
                else if (bool.TryParse(responseContent, out bool b))
                {
                    return b;
                }
                else // JSON string
                {
                    return responseContent;
                }
            }

            return null;
        }


        private static string GetServerApiUri(string endpoint)
        {
            var sb = new StringBuilder();

            // Append the title name if applicable
            string title = Environment.GetEnvironmentVariable(TITLE_ID, EnvironmentVariableTarget.Process);
            if (!string.IsNullOrEmpty(title))
            {
                sb.Append(title).Append(".");
            }
            // Append the cloud name if applicable
            string cloud = Environment.GetEnvironmentVariable(CLOUD_NAME, EnvironmentVariableTarget.Process);
            if (!string.IsNullOrEmpty(cloud))
            {
                sb.Append(cloud).Append(".");
            }
            // Append base PF API address
            sb.Append("playfabapi.com");

            var uriBuilder = new UriBuilder
            {
                Scheme = "https",
                Host = sb.ToString(),
                Path = endpoint
            };

            return uriBuilder.Uri.AbsoluteUri;
        }

        #region Utility Functions
        private static string ReadAllFileText(string filename)
        {
            var sb = new StringBuilder();

            if (!File.Exists(filename))
            {
                return string.Empty;
            }

            if (sb == null)
            {
                sb = new StringBuilder();
            }
            sb.Length = 0;

            using (var fs = new FileStream(filename, FileMode.Open))
            {
                using (var br = new BinaryReader(fs))
                {
                    while (br.BaseStream.Position != br.BaseStream.Length)
                    {
                        sb.Append(br.ReadChar());
                    }
                }
            }

            return sb.ToString();
        }

        private static string GetHostRoutePrefix()
        {
            string hostFileContent = null;
            string currDir = Directory.GetCurrentDirectory();
            string currDirHostFile = Path.Combine(currDir, "host.json");

            if (File.Exists(currDirHostFile))
            {
                hostFileContent = ReadAllFileText(currDirHostFile);
            }

            var hostModel = PlayFabSimpleJson.DeserializeObject<HostJsonModel>(hostFileContent);

            return hostModel?.extensions?.http?.routePrefix;
        }

        private static async Task<string> DecompressHttpBody(HttpRequest request)
        {
            string encoding = request.Headers["Content-Encoding"];

            // Compression was not present and hence attempt to simply read out the body provided
            if (string.IsNullOrWhiteSpace(encoding))
            {
                using (var reader = new StreamReader(request.Body))
                {
                    return await reader.ReadToEndAsync();
                }
            }
            else if (!encoding.ToLower().Equals("gzip"))
            {
                // Only GZIP decompression supported
                throw new Exception($"Unkown compression used on body. Content-Encoding header value: {encoding}. Expecting none or GZIP");
            }

            var responseBytes = StreamToBytes(request.Body);
            // Attempt to decompress the GZIP compressed request body
            using (Stream responseStream = new MemoryStream(responseBytes))
            {
                using (var gZipStream = new GZipStream(responseStream, CompressionMode.Decompress, false))
                {
                    byte[] buffer = new byte[4*1024];
                    using (var output = new MemoryStream())
                    {
                        int read;
                        while ((read = gZipStream.Read(buffer, 0, buffer.Length)) > 0)
                        {
                            output.Write(buffer, 0, read);
                        }
                        output.Seek(0, SeekOrigin.Begin);
                        return await new StreamReader(output).ReadToEndAsync();
                    }
                }
            }
        }

        private static byte[] CompressResponseBody(object responseObject, HttpRequest request)
        {
            string responseJson = PlayFabSimpleJson.SerializeObject(responseObject);
            var responseBytes = Encoding.UTF8.GetBytes(responseJson);

            // Get all accepted encodings,
            string encodingsString = request.Headers["Accept-Encoding"];

            // If client doesn't specify accepted encodings, assume identity and respond decompressed
            if (string.IsNullOrEmpty(encodingsString))
            {
                return responseBytes;
            }

            List<string> encodings = encodingsString.Replace(" ", String.Empty).Split(',').ToList();
            encodings.ForEach(encoding => encoding.ToLower());

            // If client accepts identity explicitly, respond decompressed
            if (encodings.Contains("identity", StringComparer.OrdinalIgnoreCase))
            {
                return responseBytes;
            }

            // If client accepts gzip, compress
            if (encodings.Contains("gzip", StringComparer.OrdinalIgnoreCase))
            {
                using (var stream = new MemoryStream())
                {
                    using (var gZipStream = new GZipStream(stream, CompressionLevel.Fastest, false))
                    {
                        gZipStream.Write(responseBytes, 0, responseBytes.Length);
                    }
                    responseBytes = stream.ToArray();
                }
                return responseBytes;
            }

            // If neither identity or gzip, throw error: we support gzip only right now
            throw new Exception($"Unknown compression requested for response. The \"Accept-Encoding\" haeder values was: ${encodingsString}. Only \"Identity\" and \"GZip\" are supported right now.");
        }

        private static byte[] StreamToBytes(Stream input)
        {
            input.Seek(0, SeekOrigin.Begin);
            byte[] buffer = new byte[4*1024];
            using (var output = new MemoryStream())
            {
                int read;
                while ((read = input.Read(buffer, 0, buffer.Length)) > 0)
                {
                    output.Write(buffer, 0, read);
                }
                return output.ToArray();
            }
        }
        #endregion
    }

    #region Models
    public class TitleAuthenticationContext
    {
        public string Id;
        public string EntityToken;
    }

    public class FunctionContextInternal : FunctionContextInternal<object>
    {
    }

    public class FunctionContextInternal<TFunctionArgument>
    {
        public TitleAuthenticationContext TitleAuthenticationContext { get; set; }
        public EntityProfileBody CallerEntityProfile { get; set; }
        public TFunctionArgument FunctionArgument { get; set; }
    }

    public class ExecuteFunctionRequest : PlayFabRequestCommon
    {
        public ClientModels.EntityKey Entity { get; set; }

        public string FunctionName { get; set; }

        public object FunctionParameter { get; set; }

        public bool? GeneratePlayStreamEvent { get; set; }
    }

    public class ExecuteFunctionResult : PlayFabResultCommon
    {
        public int ExecutionTimeMilliseconds;
        public string FunctionName;
        public object FunctionResult;
        public bool? FunctionResultTooLarge;
    }

    public class HostJsonModel
    {
        public string version { get; set; }
        public HostJsonExtensionsModel extensions { get; set; }

        public class HostJsonExtensionsModel
        {
            public HostJsonHttpModel http { get; set; }
        }

        public class HostJsonHttpModel
        {
            public string routePrefix { get; set; }
        }
    }
    #endregion
}
