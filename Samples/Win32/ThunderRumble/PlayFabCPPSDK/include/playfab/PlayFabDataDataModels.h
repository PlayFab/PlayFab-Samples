#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>

// Intellisense-only includes
#ifndef _WIN32
#include <jsoncpp/json/value.h>
#endif
#ifdef _WIN32
#include <json/value.h>
#endif

namespace PlayFab
{
    namespace DataModels
    {
        // Data Enums
        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        inline void ToJsonEnum(const OperationTypes input, Json::Value& output)
        {
            if (input == OperationTypesCreated) output = Json::Value("Created");
            if (input == OperationTypesUpdated) output = Json::Value("Updated");
            if (input == OperationTypesDeleted) output = Json::Value("Deleted");
            if (input == OperationTypesNone) output = Json::Value("None");
        }
        inline void FromJsonEnum(const Json::Value& input, OperationTypes& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Created") output = OperationTypesCreated;
            if (inputStr == "Updated") output = OperationTypesUpdated;
            if (inputStr == "Deleted") output = OperationTypesDeleted;
            if (inputStr == "None") output = OperationTypesNone;
        }

        // Data Classes
        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            std::string Type;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type)
            {}

            ~EntityKey() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct AbortFileUploadsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            Boxed<Int32> ProfileVersion;

            AbortFileUploadsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            AbortFileUploadsRequest(const AbortFileUploadsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            ~AbortFileUploadsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FileNames"], FileNames);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output["FileNames"] = each_FileNames;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                return output;
            }
        };

        struct AbortFileUploadsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ProfileVersion;

            AbortFileUploadsResponse() :
                PlayFabResultCommon(),
                Entity(),
                ProfileVersion()
            {}

            AbortFileUploadsResponse(const AbortFileUploadsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                ProfileVersion(src.ProfileVersion)
            {}

            ~AbortFileUploadsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                return output;
            }
        };

        struct DeleteFilesRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            Boxed<Int32> ProfileVersion;

            DeleteFilesRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            DeleteFilesRequest(const DeleteFilesRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            ~DeleteFilesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FileNames"], FileNames);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output["FileNames"] = each_FileNames;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                return output;
            }
        };

        struct DeleteFilesResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ProfileVersion;

            DeleteFilesResponse() :
                PlayFabResultCommon(),
                Entity(),
                ProfileVersion()
            {}

            DeleteFilesResponse(const DeleteFilesResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                ProfileVersion(src.ProfileVersion)
            {}

            ~DeleteFilesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                return output;
            }
        };

        struct FinalizeFileUploadsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<std::string> FileNames;

            FinalizeFileUploadsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FileNames()
            {}

            FinalizeFileUploadsRequest(const FinalizeFileUploadsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FileNames(src.FileNames)
            {}

            ~FinalizeFileUploadsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FileNames"], FileNames);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output["FileNames"] = each_FileNames;
                return output;
            }
        };

        struct GetFileMetadata : public PlayFabBaseModel
        {
            std::string Checksum;
            std::string DownloadUrl;
            std::string FileName;
            time_t LastModified;
            Int32 Size;

            GetFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                DownloadUrl(),
                FileName(),
                LastModified(),
                Size()
            {}

            GetFileMetadata(const GetFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                DownloadUrl(src.DownloadUrl),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            ~GetFileMetadata() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Checksum"], Checksum);
                FromJsonUtilS(input["DownloadUrl"], DownloadUrl);
                FromJsonUtilS(input["FileName"], FileName);
                FromJsonUtilT(input["LastModified"], LastModified);
                FromJsonUtilP(input["Size"], Size);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Checksum; ToJsonUtilS(Checksum, each_Checksum); output["Checksum"] = each_Checksum;
                Json::Value each_DownloadUrl; ToJsonUtilS(DownloadUrl, each_DownloadUrl); output["DownloadUrl"] = each_DownloadUrl;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                Json::Value each_LastModified; ToJsonUtilT(LastModified, each_LastModified); output["LastModified"] = each_LastModified;
                Json::Value each_Size; ToJsonUtilP(Size, each_Size); output["Size"] = each_Size;
                return output;
            }
        };

        struct FinalizeFileUploadsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::map<std::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            FinalizeFileUploadsResponse() :
                PlayFabResultCommon(),
                Entity(),
                Metadata(),
                ProfileVersion()
            {}

            FinalizeFileUploadsResponse(const FinalizeFileUploadsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            ~FinalizeFileUploadsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Metadata"], Metadata);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Metadata; ToJsonUtilO(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                return output;
            }
        };

        struct GetFilesRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;

            GetFilesRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            GetFilesRequest(const GetFilesRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~GetFilesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetFilesResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::map<std::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            GetFilesResponse() :
                PlayFabResultCommon(),
                Entity(),
                Metadata(),
                ProfileVersion()
            {}

            GetFilesResponse(const GetFilesResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            ~GetFilesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Metadata"], Metadata);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Metadata; ToJsonUtilO(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                return output;
            }
        };

        struct GetObjectsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            Boxed<bool> EscapeObject;

            GetObjectsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                EscapeObject()
            {}

            GetObjectsRequest(const GetObjectsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                EscapeObject(src.EscapeObject)
            {}

            ~GetObjectsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["EscapeObject"], EscapeObject);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EscapeObject; ToJsonUtilP(EscapeObject, each_EscapeObject); output["EscapeObject"] = each_EscapeObject;
                return output;
            }
        };

        struct ObjectResult : public PlayFabResultCommon
        {
            Json::Value DataObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            ObjectResult() :
                PlayFabResultCommon(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            ObjectResult(const ObjectResult& src) :
                PlayFabResultCommon(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ~ObjectResult() = default;

            void FromJson(Json::Value& input) override
            {
                DataObject = input["DataObject"];
                FromJsonUtilS(input["EscapedDataObject"], EscapedDataObject);
                FromJsonUtilS(input["ObjectName"], ObjectName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["DataObject"] = DataObject;
                Json::Value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output["EscapedDataObject"] = each_EscapedDataObject;
                Json::Value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output["ObjectName"] = each_ObjectName;
                return output;
            }
        };

        struct GetObjectsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::map<std::string, ObjectResult> Objects;
            Int32 ProfileVersion;

            GetObjectsResponse() :
                PlayFabResultCommon(),
                Entity(),
                Objects(),
                ProfileVersion()
            {}

            GetObjectsResponse(const GetObjectsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Objects(src.Objects),
                ProfileVersion(src.ProfileVersion)
            {}

            ~GetObjectsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Objects"], Objects);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Objects; ToJsonUtilO(Objects, each_Objects); output["Objects"] = each_Objects;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                return output;
            }
        };

        struct InitiateFileUploadMetadata : public PlayFabBaseModel
        {
            std::string FileName;
            std::string UploadUrl;

            InitiateFileUploadMetadata() :
                PlayFabBaseModel(),
                FileName(),
                UploadUrl()
            {}

            InitiateFileUploadMetadata(const InitiateFileUploadMetadata& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                UploadUrl(src.UploadUrl)
            {}

            ~InitiateFileUploadMetadata() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
                FromJsonUtilS(input["UploadUrl"], UploadUrl);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                Json::Value each_UploadUrl; ToJsonUtilS(UploadUrl, each_UploadUrl); output["UploadUrl"] = each_UploadUrl;
                return output;
            }
        };

        struct InitiateFileUploadsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            Boxed<Int32> ProfileVersion;

            InitiateFileUploadsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            InitiateFileUploadsRequest(const InitiateFileUploadsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            ~InitiateFileUploadsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FileNames"], FileNames);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output["FileNames"] = each_FileNames;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                return output;
            }
        };

        struct InitiateFileUploadsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ProfileVersion;
            std::list<InitiateFileUploadMetadata> UploadDetails;

            InitiateFileUploadsResponse() :
                PlayFabResultCommon(),
                Entity(),
                ProfileVersion(),
                UploadDetails()
            {}

            InitiateFileUploadsResponse(const InitiateFileUploadsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                ProfileVersion(src.ProfileVersion),
                UploadDetails(src.UploadDetails)
            {}

            ~InitiateFileUploadsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilO(input["UploadDetails"], UploadDetails);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_UploadDetails; ToJsonUtilO(UploadDetails, each_UploadDetails); output["UploadDetails"] = each_UploadDetails;
                return output;
            }
        };

        struct SetObject : public PlayFabBaseModel
        {
            Json::Value DataObject;
            Boxed<bool> DeleteObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            SetObject() :
                PlayFabBaseModel(),
                DataObject(),
                DeleteObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            SetObject(const SetObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                DeleteObject(src.DeleteObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ~SetObject() = default;

            void FromJson(Json::Value& input) override
            {
                DataObject = input["DataObject"];
                FromJsonUtilP(input["DeleteObject"], DeleteObject);
                FromJsonUtilS(input["EscapedDataObject"], EscapedDataObject);
                FromJsonUtilS(input["ObjectName"], ObjectName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["DataObject"] = DataObject;
                Json::Value each_DeleteObject; ToJsonUtilP(DeleteObject, each_DeleteObject); output["DeleteObject"] = each_DeleteObject;
                Json::Value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output["EscapedDataObject"] = each_EscapedDataObject;
                Json::Value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output["ObjectName"] = each_ObjectName;
                return output;
            }
        };

        struct SetObjectInfo : public PlayFabBaseModel
        {
            std::string ObjectName;
            std::string OperationReason;
            Boxed<OperationTypes> SetResult;

            SetObjectInfo() :
                PlayFabBaseModel(),
                ObjectName(),
                OperationReason(),
                SetResult()
            {}

            SetObjectInfo(const SetObjectInfo& src) :
                PlayFabBaseModel(),
                ObjectName(src.ObjectName),
                OperationReason(src.OperationReason),
                SetResult(src.SetResult)
            {}

            ~SetObjectInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ObjectName"], ObjectName);
                FromJsonUtilS(input["OperationReason"], OperationReason);
                FromJsonUtilE(input["SetResult"], SetResult);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output["ObjectName"] = each_ObjectName;
                Json::Value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output["OperationReason"] = each_OperationReason;
                Json::Value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output["SetResult"] = each_SetResult;
                return output;
            }
        };

        struct SetObjectsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            Boxed<Int32> ExpectedProfileVersion;
            std::list<SetObject> Objects;

            SetObjectsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ExpectedProfileVersion(),
                Objects()
            {}

            SetObjectsRequest(const SetObjectsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Objects(src.Objects)
            {}

            ~SetObjectsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ExpectedProfileVersion"], ExpectedProfileVersion);
                FromJsonUtilO(input["Objects"], Objects);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output["ExpectedProfileVersion"] = each_ExpectedProfileVersion;
                Json::Value each_Objects; ToJsonUtilO(Objects, each_Objects); output["Objects"] = each_Objects;
                return output;
            }
        };

        struct SetObjectsResponse : public PlayFabResultCommon
        {
            Int32 ProfileVersion;
            std::list<SetObjectInfo> SetResults;

            SetObjectsResponse() :
                PlayFabResultCommon(),
                ProfileVersion(),
                SetResults()
            {}

            SetObjectsResponse(const SetObjectsResponse& src) :
                PlayFabResultCommon(),
                ProfileVersion(src.ProfileVersion),
                SetResults(src.SetResults)
            {}

            ~SetObjectsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilO(input["SetResults"], SetResults);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_SetResults; ToJsonUtilO(SetResults, each_SetResults); output["SetResults"] = each_SetResults;
                return output;
            }
        };

    }
}

#endif
