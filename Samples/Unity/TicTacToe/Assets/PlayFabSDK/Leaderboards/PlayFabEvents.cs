#if !DISABLE_PLAYFABENTITY_API
using PlayFab.LeaderboardsModels;

namespace PlayFab.Events
{
    public partial class PlayFabEvents
    {
        public event PlayFabRequestEvent<CreateStatisticDefinitionRequest> OnLeaderboardsCreateStatisticDefinitionRequestEvent;
        public event PlayFabResultEvent<EmptyResponse> OnLeaderboardsCreateStatisticDefinitionResultEvent;
        public event PlayFabRequestEvent<DeleteStatisticDefinitionRequest> OnLeaderboardsDeleteStatisticDefinitionRequestEvent;
        public event PlayFabResultEvent<EmptyResponse> OnLeaderboardsDeleteStatisticDefinitionResultEvent;
        public event PlayFabRequestEvent<DeleteStatisticsRequest> OnLeaderboardsDeleteStatisticsRequestEvent;
        public event PlayFabResultEvent<DeleteStatisticsResponse> OnLeaderboardsDeleteStatisticsResultEvent;
        public event PlayFabRequestEvent<GetEntityLeaderboardRequest> OnLeaderboardsGetLeaderboardRequestEvent;
        public event PlayFabResultEvent<GetEntityLeaderboardResponse> OnLeaderboardsGetLeaderboardResultEvent;
        public event PlayFabRequestEvent<GetLeaderboardAroundEntityRequest> OnLeaderboardsGetLeaderboardAroundEntityRequestEvent;
        public event PlayFabResultEvent<GetEntityLeaderboardResponse> OnLeaderboardsGetLeaderboardAroundEntityResultEvent;
        public event PlayFabRequestEvent<GetLeaderboardForEntitiesRequest> OnLeaderboardsGetLeaderboardForEntitiesRequestEvent;
        public event PlayFabResultEvent<GetEntityLeaderboardResponse> OnLeaderboardsGetLeaderboardForEntitiesResultEvent;
        public event PlayFabRequestEvent<GetStatisticDefinitionRequest> OnLeaderboardsGetStatisticDefinitionRequestEvent;
        public event PlayFabResultEvent<GetStatisticDefinitionResponse> OnLeaderboardsGetStatisticDefinitionResultEvent;
        public event PlayFabRequestEvent<GetStatisticDefinitionsRequest> OnLeaderboardsGetStatisticDefinitionsRequestEvent;
        public event PlayFabResultEvent<GetStatisticDefinitionsResponse> OnLeaderboardsGetStatisticDefinitionsResultEvent;
        public event PlayFabRequestEvent<IncrementStatisticVersionRequest> OnLeaderboardsIncrementStatisticVersionRequestEvent;
        public event PlayFabResultEvent<IncrementStatisticVersionResponse> OnLeaderboardsIncrementStatisticVersionResultEvent;
        public event PlayFabRequestEvent<UpdateStatisticsRequest> OnLeaderboardsUpdateStatisticsRequestEvent;
        public event PlayFabResultEvent<UpdateStatisticsResponse> OnLeaderboardsUpdateStatisticsResultEvent;
    }
}
#endif
