#if !DISABLE_PLAYFABENTITY_API
using System;
using System.Collections.Generic;
using PlayFab.SharedModels;

namespace PlayFab.CloudScriptModels
{
    public enum CloudScriptRevisionOption
    {
        Live,
        Latest,
        Specific
    }

    [Serializable]
    public class EmptyResult : PlayFabResultCommon
    {
    }

    /// <summary>
    /// Combined entity type and ID structure which uniquely identifies a single entity.
    /// </summary>
    [Serializable]
    public class EntityKey : PlayFabBaseModel
    {
        /// <summary>
        /// Unique ID of the entity.
        /// </summary>
        public string Id;
        /// <summary>
        /// Entity type. See https://api.playfab.com/docs/tutorials/entities/entitytypes
        /// </summary>
        public string Type;
    }

    [Serializable]
    public class ExecuteCloudScriptResult : PlayFabResultCommon
    {
        /// <summary>
        /// Number of PlayFab API requests issued by the CloudScript function
        /// </summary>
        public int APIRequestsIssued;
        /// <summary>
        /// Information about the error, if any, that occurred during execution
        /// </summary>
        public ScriptExecutionError Error;
        public double ExecutionTimeSeconds;
        /// <summary>
        /// The name of the function that executed
        /// </summary>
        public string FunctionName;
        /// <summary>
        /// The object returned from the CloudScript function, if any
        /// </summary>
        public object FunctionResult;
        /// <summary>
        /// Flag indicating if the FunctionResult was too large and was subsequently dropped from this event. This only occurs if
        /// the total event size is larger than 350KB.
        /// </summary>
        public bool? FunctionResultTooLarge;
        /// <summary>
        /// Number of external HTTP requests issued by the CloudScript function
        /// </summary>
        public int HttpRequestsIssued;
        /// <summary>
        /// Entries logged during the function execution. These include both entries logged in the function code using log.info()
        /// and log.error() and error entries for API and HTTP request failures.
        /// </summary>
        public List<LogStatement> Logs;
        /// <summary>
        /// Flag indicating if the logs were too large and were subsequently dropped from this event. This only occurs if the total
        /// event size is larger than 350KB after the FunctionResult was removed.
        /// </summary>
        public bool? LogsTooLarge;
        public uint MemoryConsumedBytes;
        /// <summary>
        /// Processor time consumed while executing the function. This does not include time spent waiting on API calls or HTTP
        /// requests.
        /// </summary>
        public double ProcessorTimeSeconds;
        /// <summary>
        /// The revision of the CloudScript that executed
        /// </summary>
        public int Revision;
    }

    /// <summary>
    /// Executes CloudScript with the entity profile that is defined in the request.
    /// </summary>
    [Serializable]
    public class ExecuteEntityCloudScriptRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The name of the CloudScript function to execute
        /// </summary>
        public string FunctionName;
        /// <summary>
        /// Object that is passed in to the function as the first argument
        /// </summary>
        public object FunctionParameter;
        /// <summary>
        /// Generate a 'entity_executed_cloudscript' PlayStream event containing the results of the function execution and other
        /// contextual information. This event will show up in the PlayStream debugger console for the player in Game Manager.
        /// </summary>
        public bool? GeneratePlayStreamEvent;
        /// <summary>
        /// Option for which revision of the CloudScript to execute. 'Latest' executes the most recently created revision, 'Live'
        /// executes the current live, published revision, and 'Specific' executes the specified revision. The default value is
        /// 'Specific', if the SpecificRevision parameter is specified, otherwise it is 'Live'.
        /// </summary>
        public CloudScriptRevisionOption? RevisionSelection;
        /// <summary>
        /// The specific revision to execute, when RevisionSelection is set to 'Specific'
        /// </summary>
        public int? SpecificRevision;
    }

    /// <summary>
    /// Executes an Azure Function with the profile of the entity that is defined in the request.
    /// </summary>
    [Serializable]
    public class ExecuteFunctionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The name of the CloudScript function to execute
        /// </summary>
        public string FunctionName;
        /// <summary>
        /// Object that is passed in to the function as the FunctionArgument field of the FunctionExecutionContext data structure
        /// </summary>
        public object FunctionParameter;
        /// <summary>
        /// Generate a 'entity_executed_cloudscript_function' PlayStream event containing the results of the function execution and
        /// other contextual information. This event will show up in the PlayStream debugger console for the player in Game Manager.
        /// </summary>
        public bool? GeneratePlayStreamEvent;
    }

    [Serializable]
    public class ExecuteFunctionResult : PlayFabResultCommon
    {
        /// <summary>
        /// The amount of time the function took to execute
        /// </summary>
        public int ExecutionTimeMilliseconds;
        /// <summary>
        /// The name of the function that executed
        /// </summary>
        public string FunctionName;
        /// <summary>
        /// The object returned from the function, if any
        /// </summary>
        public object FunctionResult;
        /// <summary>
        /// Flag indicating if the FunctionResult was too large and was subsequently dropped from this event.
        /// </summary>
        public bool? FunctionResultTooLarge;
    }

    [Serializable]
    public class FunctionModel : PlayFabBaseModel
    {
        public string FunctionName;
        public string FunctionUrl;
    }

    /// <summary>
    /// A title can have many functions, ListFunctions will return a list of all the currently registered functions for a given
    /// title.
    /// </summary>
    [Serializable]
    public class ListFunctionsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
    }

    [Serializable]
    public class ListFunctionsResult : PlayFabResultCommon
    {
        public List<FunctionModel> Functions;
    }

    [Serializable]
    public class LogStatement : PlayFabBaseModel
    {
        /// <summary>
        /// Optional object accompanying the message as contextual information
        /// </summary>
        public object Data;
        /// <summary>
        /// 'Debug', 'Info', or 'Error'
        /// </summary>
        public string Level;
        public string Message;
    }

    /// <summary>
    /// A title can have many functions, RegisterFunction associates a function name to a URL that can be invoked by
    /// CloudScript.ExecuteFunction or in response to a PlayStream event or as part of a Task.
    /// </summary>
    [Serializable]
    public class RegisterHttpFunctionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The name of the function to register
        /// </summary>
        public string FunctionName;
        /// <summary>
        /// Full URL for Azure Function that implements the function.
        /// </summary>
        public string FunctionUrl;
    }

    [Serializable]
    public class ScriptExecutionError : PlayFabBaseModel
    {
        /// <summary>
        /// Error code, such as CloudScriptNotFound, JavascriptException, CloudScriptFunctionArgumentSizeExceeded,
        /// CloudScriptAPIRequestCountExceeded, CloudScriptAPIRequestError, or CloudScriptHTTPRequestError
        /// </summary>
        public string Error;
        /// <summary>
        /// Details about the error
        /// </summary>
        public string Message;
        /// <summary>
        /// Point during the execution of the script at which the error occurred, if any
        /// </summary>
        public string StackTrace;
    }

    /// <summary>
    /// A title can have many functions, UnregisterFunction disassociates a previously registered function from the title.
    /// </summary>
    [Serializable]
    public class UnregisterFunctionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The name of the function to unregister
        /// </summary>
        public string FunctionName;
    }
}
#endif
