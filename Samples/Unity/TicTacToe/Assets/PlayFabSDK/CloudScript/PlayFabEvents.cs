#if !DISABLE_PLAYFABENTITY_API
using PlayFab.CloudScriptModels;

namespace PlayFab.Events
{
    public partial class PlayFabEvents
    {
        public event PlayFabRequestEvent<ExecuteEntityCloudScriptRequest> OnCloudScriptExecuteEntityCloudScriptRequestEvent;
        public event PlayFabResultEvent<ExecuteCloudScriptResult> OnCloudScriptExecuteEntityCloudScriptResultEvent;
        public event PlayFabRequestEvent<ExecuteFunctionRequest> OnCloudScriptExecuteFunctionRequestEvent;
        public event PlayFabResultEvent<ExecuteFunctionResult> OnCloudScriptExecuteFunctionResultEvent;
        public event PlayFabRequestEvent<ListFunctionsRequest> OnCloudScriptListFunctionsRequestEvent;
        public event PlayFabResultEvent<ListFunctionsResult> OnCloudScriptListFunctionsResultEvent;
        public event PlayFabRequestEvent<RegisterHttpFunctionRequest> OnCloudScriptRegisterHttpFunctionRequestEvent;
        public event PlayFabResultEvent<EmptyResult> OnCloudScriptRegisterHttpFunctionResultEvent;
        public event PlayFabRequestEvent<UnregisterFunctionRequest> OnCloudScriptUnregisterFunctionRequestEvent;
        public event PlayFabResultEvent<EmptyResult> OnCloudScriptUnregisterFunctionResultEvent;
    }
}
#endif
