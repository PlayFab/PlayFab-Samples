#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace DataModels
    {
        // Data Enums
        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup,
            EntityTypesservice
        };

        inline void ToJsonEnum(const EntityTypes input, web::json::value& output)
        {
            if (input == EntityTypestitle) output = web::json::value(L"title");
            if (input == EntityTypesmaster_player_account) output = web::json::value(L"master_player_account");
            if (input == EntityTypestitle_player_account) output = web::json::value(L"title_player_account");
            if (input == EntityTypescharacter) output = web::json::value(L"character");
            if (input == EntityTypesgroup) output = web::json::value(L"group");
            if (input == EntityTypesservice) output = web::json::value(L"service");
        }
        inline void FromJsonEnum(const web::json::value& input, EntityTypes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"title") output = EntityTypestitle;
            if (inputStr == L"master_player_account") output = EntityTypesmaster_player_account;
            if (inputStr == L"title_player_account") output = EntityTypestitle_player_account;
            if (inputStr == L"character") output = EntityTypescharacter;
            if (inputStr == L"group") output = EntityTypesgroup;
            if (inputStr == L"service") output = EntityTypesservice;
        }

        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        inline void ToJsonEnum(const OperationTypes input, web::json::value& output)
        {
            if (input == OperationTypesCreated) output = web::json::value(L"Created");
            if (input == OperationTypesUpdated) output = web::json::value(L"Updated");
            if (input == OperationTypesDeleted) output = web::json::value(L"Deleted");
            if (input == OperationTypesNone) output = web::json::value(L"None");
        }
        inline void FromJsonEnum(const web::json::value& input, OperationTypes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Created") output = OperationTypesCreated;
            if (inputStr == L"Updated") output = OperationTypesUpdated;
            if (inputStr == L"Deleted") output = OperationTypesDeleted;
            if (inputStr == L"None") output = OperationTypesNone;
        }

        // Data Classes
        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            Boxed<EntityTypes> Type;
            std::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
            {}

            ~EntityKey() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Id"], Id);
                FromJsonUtilE(input[L"Type"], Type);
                FromJsonUtilS(input[L"TypeString"], TypeString);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[L"Id"] = each_Id;
                web::json::value each_Type; ToJsonUtilE(Type, each_Type); output[L"Type"] = each_Type;
                web::json::value each_TypeString; ToJsonUtilS(TypeString, each_TypeString); output[L"TypeString"] = each_TypeString;
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

            ~AbortFileUploadsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"FileNames"], FileNames);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output[L"FileNames"] = each_FileNames;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
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

            ~AbortFileUploadsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
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

            ~DeleteFilesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"FileNames"], FileNames);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output[L"FileNames"] = each_FileNames;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
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

            ~DeleteFilesResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
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

            ~FinalizeFileUploadsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"FileNames"], FileNames);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output[L"FileNames"] = each_FileNames;
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

            ~GetFileMetadata() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Checksum"], Checksum);
                FromJsonUtilS(input[L"DownloadUrl"], DownloadUrl);
                FromJsonUtilS(input[L"FileName"], FileName);
                FromJsonUtilT(input[L"LastModified"], LastModified);
                FromJsonUtilP(input[L"Size"], Size);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Checksum; ToJsonUtilS(Checksum, each_Checksum); output[L"Checksum"] = each_Checksum;
                web::json::value each_DownloadUrl; ToJsonUtilS(DownloadUrl, each_DownloadUrl); output[L"DownloadUrl"] = each_DownloadUrl;
                web::json::value each_FileName; ToJsonUtilS(FileName, each_FileName); output[L"FileName"] = each_FileName;
                web::json::value each_LastModified; ToJsonUtilT(LastModified, each_LastModified); output[L"LastModified"] = each_LastModified;
                web::json::value each_Size; ToJsonUtilP(Size, each_Size); output[L"Size"] = each_Size;
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

            ~FinalizeFileUploadsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Metadata"], Metadata);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Metadata; ToJsonUtilO(Metadata, each_Metadata); output[L"Metadata"] = each_Metadata;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
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

            ~GetFilesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
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

            ~GetFilesResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Metadata"], Metadata);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Metadata; ToJsonUtilO(Metadata, each_Metadata); output[L"Metadata"] = each_Metadata;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
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

            ~GetObjectsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilP(input[L"EscapeObject"], EscapeObject);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_EscapeObject; ToJsonUtilP(EscapeObject, each_EscapeObject); output[L"EscapeObject"] = each_EscapeObject;
                return output;
            }
        };

        struct ObjectResult : public PlayFabResultCommon
        {
            web::json::value DataObject;
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

            ~ObjectResult() { }

            void FromJson(web::json::value& input) override
            {
                DataObject = input[L"DataObject"];
                FromJsonUtilS(input[L"EscapedDataObject"], EscapedDataObject);
                FromJsonUtilS(input[L"ObjectName"], ObjectName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"DataObject"] = DataObject;
                web::json::value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output[L"EscapedDataObject"] = each_EscapedDataObject;
                web::json::value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output[L"ObjectName"] = each_ObjectName;
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

            ~GetObjectsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Objects"], Objects);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Objects; ToJsonUtilO(Objects, each_Objects); output[L"Objects"] = each_Objects;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
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

            ~InitiateFileUploadMetadata() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FileName"], FileName);
                FromJsonUtilS(input[L"UploadUrl"], UploadUrl);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FileName; ToJsonUtilS(FileName, each_FileName); output[L"FileName"] = each_FileName;
                web::json::value each_UploadUrl; ToJsonUtilS(UploadUrl, each_UploadUrl); output[L"UploadUrl"] = each_UploadUrl;
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

            ~InitiateFileUploadsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"FileNames"], FileNames);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output[L"FileNames"] = each_FileNames;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
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

            ~InitiateFileUploadsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
                FromJsonUtilO(input[L"UploadDetails"], UploadDetails);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
                web::json::value each_UploadDetails; ToJsonUtilO(UploadDetails, each_UploadDetails); output[L"UploadDetails"] = each_UploadDetails;
                return output;
            }
        };

        struct SetObject : public PlayFabBaseModel
        {
            web::json::value DataObject;
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

            ~SetObject() { }

            void FromJson(web::json::value& input) override
            {
                DataObject = input[L"DataObject"];
                FromJsonUtilP(input[L"DeleteObject"], DeleteObject);
                FromJsonUtilS(input[L"EscapedDataObject"], EscapedDataObject);
                FromJsonUtilS(input[L"ObjectName"], ObjectName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"DataObject"] = DataObject;
                web::json::value each_DeleteObject; ToJsonUtilP(DeleteObject, each_DeleteObject); output[L"DeleteObject"] = each_DeleteObject;
                web::json::value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output[L"EscapedDataObject"] = each_EscapedDataObject;
                web::json::value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output[L"ObjectName"] = each_ObjectName;
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

            ~SetObjectInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ObjectName"], ObjectName);
                FromJsonUtilS(input[L"OperationReason"], OperationReason);
                FromJsonUtilE(input[L"SetResult"], SetResult);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output[L"ObjectName"] = each_ObjectName;
                web::json::value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output[L"OperationReason"] = each_OperationReason;
                web::json::value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output[L"SetResult"] = each_SetResult;
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

            ~SetObjectsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilP(input[L"ExpectedProfileVersion"], ExpectedProfileVersion);
                FromJsonUtilO(input[L"Objects"], Objects);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output[L"ExpectedProfileVersion"] = each_ExpectedProfileVersion;
                web::json::value each_Objects; ToJsonUtilO(Objects, each_Objects); output[L"Objects"] = each_Objects;
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

            ~SetObjectsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
                FromJsonUtilO(input[L"SetResults"], SetResults);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
                web::json::value each_SetResults; ToJsonUtilO(SetResults, each_SetResults); output[L"SetResults"] = each_SetResults;
                return output;
            }
        };

    }
}

#endif
