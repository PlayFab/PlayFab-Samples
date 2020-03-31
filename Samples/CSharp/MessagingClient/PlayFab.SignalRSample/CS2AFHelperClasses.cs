// Copyright (C) Microsoft Corporation. All rights reserved.

namespace PlayFab.Samples
{
    using System;
    using System.Collections.Generic;

    // Shared models
    public class TitleAuthenticationContext
    {
        public string Id { get; set; }
        public string EntityToken { get; set; }
    }

    // Models  via ExecuteFunction API
    public class FunctionExecutionContext<T>
    {
        public PlayFab.ProfilesModels.EntityProfileBody CallerEntityProfile { get; set; }
        public TitleAuthenticationContext TitleAuthenticationContext { get; set; }
        public bool? GeneratePlayStreamEvent { get; set; }
        public T FunctionArgument { get; set; }
    }

    public class FunctionExecutionContext : FunctionExecutionContext<object>
    {
    }

    // Models via Player PlayStream event, entering or leaving a 
    // player segment or as part of a player segment based scheduled task.
    public class PlayerPlayStreamFunctionExecutionContext<T>
    {
        public PlayFab.CloudScriptModels.PlayerProfileModel PlayerProfile { get; set; }
        public bool PlayerProfileTruncated { get; set; }
        public PlayFab.CloudScriptModels.PlayStreamEventEnvelopeModel PlayStreamEventEnvelope { get; set; }
        public TitleAuthenticationContext TitleAuthenticationContext { get; set; }
        public bool? GeneratePlayStreamEvent { get; set; }
        public T FunctionArgument { get; set; }
    }

    public class PlayerPlayStreamFunctionExecutionContext : PlayerPlayStreamFunctionExecutionContext<object>
    {
    }

    // Models via Scheduled task
    public class PlayStreamEventHistory
    {
        public string ParentTriggerId { get; set; }
        public string ParentEventId { get; set; }
        public bool TriggeredEvents { get; set; }
    }

    public class ScheduledTaskFunctionExecutionContext<T>
    {
        public PlayFab.CloudScriptModels.NameIdentifier ScheduledTaskNameId { get; set; }
        public Stack<PlayStreamEventHistory> EventHistory { get; set; }
        public TitleAuthenticationContext TitleAuthenticationContext { get; set; }
        public bool? GeneratePlayStreamEvent { get; set; }
        public T FunctionArgument { get; set; }
    }

    public class ScheduledTaskFunctionExecutionContext : ScheduledTaskFunctionExecutionContext<object>
    {
    }

    // Models via entity PlayStream event, entering or leaving an 
    // entity segment or as part of an entity segment based scheduled task.
    public class EventFullName
    {
        public string Name { get; set; }
        public string Namespace { get; set; }
    }

    public class OriginInfo
    {
        public string Id { get; set; }
        public DateTime? Timestamp { get; set; }
    }

    public class EntityPlayStreamEvent<T>
    {
        public string SchemaVersion { get; set; }
        public EventFullName FullName { get; set; }
        public string Id { get; set; }
        public DateTime Timestamp { get; set; }
        public PlayFab.CloudScriptModels.EntityKey Entity { get; set; }
        public PlayFab.CloudScriptModels.EntityKey Originator { get; set; }
        public OriginInfo OriginInfo { get; set; }
        public T Payload { get; set; }
        public PlayFab.ProfilesModels.EntityLineage EntityLineage { get; set; }
    }

    public class EntityPlayStreamEvent : EntityPlayStreamEvent<object>
    {
    }

    public class EntityPlayStreamFunctionExecutionContext<TPayload, TArg>
    {
        public PlayFab.ProfilesModels.EntityProfileBody CallerEntityProfile { get; set; }
        public EntityPlayStreamEvent<TPayload> PlayStreamEvent { get; set; }
        public TitleAuthenticationContext TitleAuthenticationContext { get; set; }
        public bool? GeneratePlayStreamEvent { get; set; }
        public TArg FunctionArgument { get; set; }
    }

    public class EntityPlayStreamFunctionExecutionContext : EntityPlayStreamFunctionExecutionContext<object, object>
    {
    }
}