#if !DISABLE_PLAYFABENTITY_API
using System;
using System.Collections.Generic;
using PlayFab.SharedModels;

namespace PlayFab.LeaderboardsModels
{
    [Serializable]
    public class CreateStatisticDefinitionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Aggregation method for this statistic. Default is Last.
        /// </summary>
        public StatisticAggregationMethod? AggregationMethod;
        /// <summary>
        /// Additional configuration options for statistics to be used for leaderboards.
        /// </summary>
        public LeaderboardDefinition LeaderboardDefinition;
        /// <summary>
        /// Immutable name of the statistic. Must be less than 50 characters.
        /// </summary>
        public string Name;
    }

    [Serializable]
    public class DeleteStatisticDefinitionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Name of the statistic to delete.
        /// </summary>
        public string Name;
    }

    [Serializable]
    public class DeleteStatisticsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// Optional field used for concurrency control. By specifying the previously returned value of ProfileVersion from
        /// GetProfile API, you can ensure that the object set will only be performed if the profile has not been updated by any
        /// other clients since the version you last loaded.
        /// </summary>
        public int? ExpectedProfileVersion;
        /// <summary>
        /// Collection of statistics to remove from this entity.
        /// </summary>
        public List<StatisticDelete> Statistics;
    }

    [Serializable]
    public class DeleteStatisticsResponse : PlayFabResultCommon
    {
        /// <summary>
        /// The entity id and type.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The current version of the profile, can be used for concurrency control during updates.
        /// </summary>
        public int ProfileVersion;
        /// <summary>
        /// Updated entity profile statistics.
        /// </summary>
        public Dictionary<string,EntityStatisticValue> Statistics;
    }

    [Serializable]
    public class EmptyResponse : PlayFabResultCommon
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

    /// <summary>
    /// Individual rank of an entity in a leaderboard
    /// </summary>
    [Serializable]
    public class EntityLeaderboardEntry : PlayFabBaseModel
    {
        /// <summary>
        /// Entity's display name.
        /// </summary>
        public string DisplayName;
        /// <summary>
        /// Entity identifier.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// Custom entity metadata as set during the last UpdateStatistic API call.
        /// </summary>
        public string EntityLeaderboardMetadata;
        /// <summary>
        /// Lineage for this entity.
        /// </summary>
        public EntityLineage EntityLineage;
        /// <summary>
        /// Statistic or statistic child metadata as set during the UpdateStatistic API call.
        /// </summary>
        public string Metadata;
        /// <summary>
        /// Position on the leaderboard.
        /// </summary>
        public int Rank;
        /// <summary>
        /// Statistic value.
        /// </summary>
        public int Score;
    }

    [Serializable]
    public class EntityLineage : PlayFabBaseModel
    {
        /// <summary>
        /// The Character Id of the associated entity.
        /// </summary>
        public string CharacterId;
        /// <summary>
        /// The Group Id of the associated entity.
        /// </summary>
        public string GroupId;
        /// <summary>
        /// The Master Player Account Id of the associated entity.
        /// </summary>
        public string MasterPlayerAccountId;
        /// <summary>
        /// The Namespace Id of the associated entity.
        /// </summary>
        public string NamespaceId;
        /// <summary>
        /// The Title Id of the associated entity.
        /// </summary>
        public string TitleId;
        /// <summary>
        /// The Title Player Account Id of the associated entity.
        /// </summary>
        public string TitlePlayerAccountId;
    }

    [Serializable]
    public class EntityStatisticChildValue : PlayFabBaseModel
    {
        /// <summary>
        /// Child name value, if child statistic
        /// </summary>
        public string ChildName;
        /// <summary>
        /// Child statistic metadata
        /// </summary>
        public string Metadata;
        /// <summary>
        /// Child statistic value
        /// </summary>
        public int Value;
    }

    [Serializable]
    public class EntityStatisticValue : PlayFabBaseModel
    {
        /// <summary>
        /// Child statistic values
        /// </summary>
        public Dictionary<string,EntityStatisticChildValue> ChildStatistics;
        /// <summary>
        /// Statistic metadata
        /// </summary>
        public string Metadata;
        /// <summary>
        /// Statistic name
        /// </summary>
        public string Name;
        /// <summary>
        /// Statistic value
        /// </summary>
        public int? Value;
        /// <summary>
        /// Statistic version
        /// </summary>
        public int Version;
    }

    /// <summary>
    /// Request to load a leaderboard.
    /// </summary>
    [Serializable]
    public class GetEntityLeaderboardRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Optional child statistic name to filter the leaderboard to.
        /// </summary>
        public string ChildName;
        /// <summary>
        /// Type of entity to get a leaderboard for.
        /// </summary>
        public string EntityType;
        /// <summary>
        /// maximum number of results to return from the leaderboard. Minimum 1, maximum 1,000.
        /// </summary>
        public uint MaxResults;
        /// <summary>
        /// Index position to start from. 0 is beginning of leaderboard.
        /// </summary>
        public uint? StartingPosition;
        /// <summary>
        /// Name of the leaderboard statistic.
        /// </summary>
        public string StatisticName;
        /// <summary>
        /// Optional version of the leaderboard statistic, defaults to current version.
        /// </summary>
        public uint? StatisticVersion;
    }

    /// <summary>
    /// Leaderboard response
    /// </summary>
    [Serializable]
    public class GetEntityLeaderboardResponse : PlayFabResultCommon
    {
        /// <summary>
        /// Individual entity rankings in the leaderboard, in sorted order by rank.
        /// </summary>
        public List<EntityLeaderboardEntry> Rankings;
        /// <summary>
        /// Version of the leaderboard being returned.
        /// </summary>
        public uint StatisticVersion;
    }

    /// <summary>
    /// Request to load a section of a leaderboard centered on a specific entity.
    /// </summary>
    [Serializable]
    public class GetLeaderboardAroundEntityRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Optional statistic child to filter the leaderboard by.
        /// </summary>
        public string ChildName;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// Number of ranks above and below the entity to return. If 5 then at most 11 results will be returned, 5 above, the
        /// entity, then 5 below. If the entity is at the top then only 6 will be returned, the entity and 5 below.
        /// </summary>
        public uint Offset;
        /// <summary>
        /// Name of the statistic.
        /// </summary>
        public string StatisticName;
        /// <summary>
        /// Optional version of the statistic, defaults to current.
        /// </summary>
        public uint? StatisticVersion;
    }

    /// <summary>
    /// Request a leaderboard limited to a collection of entities.
    /// </summary>
    [Serializable]
    public class GetLeaderboardForEntitiesRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Optional statistic child name to filter the leaderboard by.
        /// </summary>
        public string ChildName;
        /// <summary>
        /// Collection of Entity IDs to include in the leaderboard.
        /// </summary>
        public List<string> Entities;
        /// <summary>
        /// Entity type of all Entity IDs.
        /// </summary>
        public string EntityType;
        /// <summary>
        /// Name of the statistic.
        /// </summary>
        public string StatisticName;
        /// <summary>
        /// Optional version of the statistic, defaults to current.
        /// </summary>
        public uint? StatisticVersion;
    }

    [Serializable]
    public class GetStatisticDefinitionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Immutable name of the statistic. Must be less than 50 characters.
        /// </summary>
        public string Name;
    }

    [Serializable]
    public class GetStatisticDefinitionResponse : PlayFabResultCommon
    {
        /// <summary>
        /// Last time, in UTC, statistic version was incremented.
        /// </summary>
        public DateTime? LastResetTime;
        /// <summary>
        /// Statistic leaderboard definition.
        /// </summary>
        public LeaderboardDefinition LeaderboardDefinition;
        /// <summary>
        /// Name of the statistic.
        /// </summary>
        public string Name;
        /// <summary>
        /// Statistic version.
        /// </summary>
        public uint Version;
    }

    [Serializable]
    public class GetStatisticDefinitionsRequest : PlayFabRequestCommon
    {
    }

    [Serializable]
    public class GetStatisticDefinitionsResponse : PlayFabResultCommon
    {
        /// <summary>
        /// List of statistic definitions for the title.
        /// </summary>
        public IEnumerable_GetStatisticDefinitionResponse StatisticDefinitions;
    }

    [Serializable]
    public class IEnumerable_GetStatisticDefinitionResponse : PlayFabBaseModel
    {
    }

    [Serializable]
    public class IncrementStatisticVersionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Name of the statistic to increment the version of.
        /// </summary>
        public string Name;
    }

    [Serializable]
    public class IncrementStatisticVersionResponse : PlayFabResultCommon
    {
        /// <summary>
        /// New statistic version.
        /// </summary>
        public uint Version;
        /// <summary>
        /// Statistic versions and leaderboards to be removed.
        /// </summary>
        public uint VersionToBeDeleted;
    }

    [Serializable]
    public class LeaderboardDefinition : PlayFabBaseModel
    {
        /// <summary>
        /// For non-dynamic child leaderboards the statistic child name must be defined to prevent leaderboard length restrictions.
        /// </summary>
        public List<string> ChildLeaderboardNames;
        /// <summary>
        /// Number of entities to rank in a leaderboard when the child is dynamically defined, new entities will not be ranked
        /// unless that beat an existing score on a leaderboard. Default 0, Maximum 100.
        /// </summary>
        public uint? DynamicChildLeaderboardMaxSize;
        /// <summary>
        /// Flag to indicate that leaderboards should be created/updated when this statistic is updated on an entity. Default is
        /// false.
        /// </summary>
        public bool ProvisionLeaderboard;
        /// <summary>
        /// Sort direction of the leaderboard, cannot be changed after creation. Default is Descending
        /// </summary>
        public LeaderboardSortDirection? SortDirection;
    }

    public enum LeaderboardSortDirection
    {
        Descending,
        Ascending
    }

    public enum StatisticAggregationMethod
    {
        Last,
        Min,
        Max,
        Sum
    }

    [Serializable]
    public class StatisticDelete : PlayFabBaseModel
    {
        /// <summary>
        /// Optionally delete only the child statistic from this entity.
        /// </summary>
        public string ChildName;
        /// <summary>
        /// Name of the statistic, as originally configured.
        /// </summary>
        public string Name;
        /// <summary>
        /// Optional field to indicate the version of the statistic to set. When empty defaults to the statistic's current version.
        /// </summary>
        public uint? Version;
    }

    [Serializable]
    public class StatisticUpdate : PlayFabBaseModel
    {
        /// <summary>
        /// Arbitrary statistic child name, using child statistics will cause entity to be ranked on only the child leaderboard. See
        /// documentation for full details. Must be less than 50 UTF8 encoded characters.
        /// </summary>
        public string ChildName;
        /// <summary>
        /// Arbitrary metadata to store along side the statistic or child statistic, will be returned by all Leaderboard APIs. Must
        /// be less than 50 UTF8 encoded characters.
        /// </summary>
        public string Metadata;
        /// <summary>
        /// Name of the statistic, as originally configured.
        /// </summary>
        public string Name;
        /// <summary>
        /// Statistic value for the entity. This will be used in accordance with the aggregation method configured for the
        /// statistics.
        /// </summary>
        public int Value;
        /// <summary>
        /// Optional field to indicate the version of the statistic to set. When empty defaults to the statistic's current version.
        /// </summary>
        public uint? Version;
    }

    [Serializable]
    public class UpdateStatisticsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// Arbitrary metadata to store on the entity that will be returned on all leaderboard APIs. Max length 50 characters.
        /// </summary>
        public string EntityLeaderboardMetadata;
        /// <summary>
        /// Optional field used for concurrency control. By specifying the previously returned value of ProfileVersion from
        /// GetProfile API, you can ensure that the statistic updates will only be performed if the profile has not been updated by
        /// any other clients since the version you last loaded.
        /// </summary>
        public int? ExpectedProfileVersion;
        /// <summary>
        /// Flag to force the values in the request to bypass the aggregation method and be the new value for the statistic. When
        /// empty defaults to false.
        /// </summary>
        public bool? ForceUpdate;
        /// <summary>
        /// Collection of statistics to update, maximum 50.
        /// </summary>
        public List<StatisticUpdate> Statistics;
    }

    [Serializable]
    public class UpdateStatisticsResponse : PlayFabResultCommon
    {
        /// <summary>
        /// The entity id and type.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The current version of the profile, can be used for concurrency control during updates.
        /// </summary>
        public int ProfileVersion;
        /// <summary>
        /// Updated entity profile statistics.
        /// </summary>
        public Dictionary<string,EntityStatisticValue> Statistics;
    }
}
#endif
