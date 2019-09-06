#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace MatchmakerModels
    {
        // Matchmaker Enums
        enum Region
        {
            RegionUSCentral,
            RegionUSEast,
            RegionEUWest,
            RegionSingapore,
            RegionJapan,
            RegionBrazil,
            RegionAustralia
        };

        inline void ToJsonEnum(const Region input, web::json::value& output)
        {
            if (input == RegionUSCentral) output = web::json::value(L"USCentral");
            if (input == RegionUSEast) output = web::json::value(L"USEast");
            if (input == RegionEUWest) output = web::json::value(L"EUWest");
            if (input == RegionSingapore) output = web::json::value(L"Singapore");
            if (input == RegionJapan) output = web::json::value(L"Japan");
            if (input == RegionBrazil) output = web::json::value(L"Brazil");
            if (input == RegionAustralia) output = web::json::value(L"Australia");
        }
        inline void FromJsonEnum(const web::json::value& input, Region& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"USCentral") output = RegionUSCentral;
            if (inputStr == L"USEast") output = RegionUSEast;
            if (inputStr == L"EUWest") output = RegionEUWest;
            if (inputStr == L"Singapore") output = RegionSingapore;
            if (inputStr == L"Japan") output = RegionJapan;
            if (inputStr == L"Brazil") output = RegionBrazil;
            if (inputStr == L"Australia") output = RegionAustralia;
        }

        // Matchmaker Classes
        struct AuthUserRequest : public PlayFabRequestCommon
        {
            std::string AuthorizationTicket;

            AuthUserRequest() :
                PlayFabRequestCommon(),
                AuthorizationTicket()
            {}

            AuthUserRequest(const AuthUserRequest& src) :
                PlayFabRequestCommon(),
                AuthorizationTicket(src.AuthorizationTicket)
            {}

            ~AuthUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AuthorizationTicket"], AuthorizationTicket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AuthorizationTicket; ToJsonUtilS(AuthorizationTicket, each_AuthorizationTicket); output[L"AuthorizationTicket"] = each_AuthorizationTicket;
                return output;
            }
        };

        struct AuthUserResponse : public PlayFabResultCommon
        {
            bool Authorized;
            std::string PlayFabId;

            AuthUserResponse() :
                PlayFabResultCommon(),
                Authorized(),
                PlayFabId()
            {}

            AuthUserResponse(const AuthUserResponse& src) :
                PlayFabResultCommon(),
                Authorized(src.Authorized),
                PlayFabId(src.PlayFabId)
            {}

            ~AuthUserResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Authorized"], Authorized);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Authorized; ToJsonUtilP(Authorized, each_Authorized); output[L"Authorized"] = each_Authorized;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct ItemInstance : public PlayFabBaseModel
        {
            std::string Annotation;
            std::list<std::string> BundleContents;
            std::string BundleParent;
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomData;
            std::string DisplayName;
            Boxed<time_t> Expiration;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            Boxed<time_t> PurchaseDate;
            Boxed<Int32> RemainingUses;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            Boxed<Int32> UsesIncrementedBy;

            ItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PurchaseDate(),
                RemainingUses(),
                UnitCurrency(),
                UnitPrice(),
                UsesIncrementedBy()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
            {}

            ~ItemInstance() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Annotation"], Annotation);
                FromJsonUtilS(input[L"BundleContents"], BundleContents);
                FromJsonUtilS(input[L"BundleParent"], BundleParent);
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CustomData"], CustomData);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilT(input[L"Expiration"], Expiration);
                FromJsonUtilS(input[L"ItemClass"], ItemClass);
                FromJsonUtilS(input[L"ItemId"], ItemId);
                FromJsonUtilS(input[L"ItemInstanceId"], ItemInstanceId);
                FromJsonUtilT(input[L"PurchaseDate"], PurchaseDate);
                FromJsonUtilP(input[L"RemainingUses"], RemainingUses);
                FromJsonUtilS(input[L"UnitCurrency"], UnitCurrency);
                FromJsonUtilP(input[L"UnitPrice"], UnitPrice);
                FromJsonUtilP(input[L"UsesIncrementedBy"], UsesIncrementedBy);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output[L"Annotation"] = each_Annotation;
                web::json::value each_BundleContents; ToJsonUtilS(BundleContents, each_BundleContents); output[L"BundleContents"] = each_BundleContents;
                web::json::value each_BundleParent; ToJsonUtilS(BundleParent, each_BundleParent); output[L"BundleParent"] = each_BundleParent;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output[L"CustomData"] = each_CustomData;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output[L"Expiration"] = each_Expiration;
                web::json::value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output[L"ItemClass"] = each_ItemClass;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[L"ItemInstanceId"] = each_ItemInstanceId;
                web::json::value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output[L"PurchaseDate"] = each_PurchaseDate;
                web::json::value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output[L"RemainingUses"] = each_RemainingUses;
                web::json::value each_UnitCurrency; ToJsonUtilS(UnitCurrency, each_UnitCurrency); output[L"UnitCurrency"] = each_UnitCurrency;
                web::json::value each_UnitPrice; ToJsonUtilP(UnitPrice, each_UnitPrice); output[L"UnitPrice"] = each_UnitPrice;
                web::json::value each_UsesIncrementedBy; ToJsonUtilP(UsesIncrementedBy, each_UsesIncrementedBy); output[L"UsesIncrementedBy"] = each_UsesIncrementedBy;
                return output;
            }
        };

        struct PlayerJoinedRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;
            std::string PlayFabId;

            PlayerJoinedRequest() :
                PlayFabRequestCommon(),
                LobbyId(),
                PlayFabId()
            {}

            PlayerJoinedRequest(const PlayerJoinedRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            ~PlayerJoinedRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"LobbyId"], LobbyId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[L"LobbyId"] = each_LobbyId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct PlayerJoinedResponse : public PlayFabResultCommon
        {

            PlayerJoinedResponse() :
                PlayFabResultCommon()
            {}

            PlayerJoinedResponse(const PlayerJoinedResponse&) :
                PlayFabResultCommon()
            {}

            ~PlayerJoinedResponse() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct PlayerLeftRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;
            std::string PlayFabId;

            PlayerLeftRequest() :
                PlayFabRequestCommon(),
                LobbyId(),
                PlayFabId()
            {}

            PlayerLeftRequest(const PlayerLeftRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            ~PlayerLeftRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"LobbyId"], LobbyId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[L"LobbyId"] = each_LobbyId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct PlayerLeftResponse : public PlayFabResultCommon
        {

            PlayerLeftResponse() :
                PlayFabResultCommon()
            {}

            PlayerLeftResponse(const PlayerLeftResponse&) :
                PlayFabResultCommon()
            {}

            ~PlayerLeftResponse() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct StartGameRequest : public PlayFabRequestCommon
        {
            std::string Build;
            std::string CustomCommandLineData;
            std::string ExternalMatchmakerEventEndpoint;
            std::string GameMode;
            Region pfRegion;

            StartGameRequest() :
                PlayFabRequestCommon(),
                Build(),
                CustomCommandLineData(),
                ExternalMatchmakerEventEndpoint(),
                GameMode(),
                pfRegion()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabRequestCommon(),
                Build(src.Build),
                CustomCommandLineData(src.CustomCommandLineData),
                ExternalMatchmakerEventEndpoint(src.ExternalMatchmakerEventEndpoint),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion)
            {}

            ~StartGameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Build"], Build);
                FromJsonUtilS(input[L"CustomCommandLineData"], CustomCommandLineData);
                FromJsonUtilS(input[L"ExternalMatchmakerEventEndpoint"], ExternalMatchmakerEventEndpoint);
                FromJsonUtilS(input[L"GameMode"], GameMode);
                FromJsonEnum(input[L"pfRegion"], pfRegion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Build; ToJsonUtilS(Build, each_Build); output[L"Build"] = each_Build;
                web::json::value each_CustomCommandLineData; ToJsonUtilS(CustomCommandLineData, each_CustomCommandLineData); output[L"CustomCommandLineData"] = each_CustomCommandLineData;
                web::json::value each_ExternalMatchmakerEventEndpoint; ToJsonUtilS(ExternalMatchmakerEventEndpoint, each_ExternalMatchmakerEventEndpoint); output[L"ExternalMatchmakerEventEndpoint"] = each_ExternalMatchmakerEventEndpoint;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[L"GameMode"] = each_GameMode;
                web::json::value each_pfRegion; ToJsonEnum(pfRegion, each_pfRegion); output[L"Region"] = each_pfRegion;
                return output;
            }
        };

        struct StartGameResponse : public PlayFabResultCommon
        {
            std::string GameID;
            std::string ServerHostname;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            Uint32 ServerPort;
            std::string ServerPublicDNSName;

            StartGameResponse() :
                PlayFabResultCommon(),
                GameID(),
                ServerHostname(),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(),
                ServerPublicDNSName()
            {}

            StartGameResponse(const StartGameResponse& src) :
                PlayFabResultCommon(),
                GameID(src.GameID),
                ServerHostname(src.ServerHostname),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName)
            {}

            ~StartGameResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"GameID"], GameID);
                FromJsonUtilS(input[L"ServerHostname"], ServerHostname);
                FromJsonUtilS(input[L"ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input[L"ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input[L"ServerPort"], ServerPort);
                FromJsonUtilS(input[L"ServerPublicDNSName"], ServerPublicDNSName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameID; ToJsonUtilS(GameID, each_GameID); output[L"GameID"] = each_GameID;
                web::json::value each_ServerHostname; ToJsonUtilS(ServerHostname, each_ServerHostname); output[L"ServerHostname"] = each_ServerHostname;
                web::json::value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output[L"ServerIPV4Address"] = each_ServerIPV4Address;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[L"ServerIPV6Address"] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[L"ServerPort"] = each_ServerPort;
                web::json::value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output[L"ServerPublicDNSName"] = each_ServerPublicDNSName;
                return output;
            }
        };

        struct UserInfoRequest : public PlayFabRequestCommon
        {
            Int32 MinCatalogVersion;
            std::string PlayFabId;

            UserInfoRequest() :
                PlayFabRequestCommon(),
                MinCatalogVersion(),
                PlayFabId()
            {}

            UserInfoRequest(const UserInfoRequest& src) :
                PlayFabRequestCommon(),
                MinCatalogVersion(src.MinCatalogVersion),
                PlayFabId(src.PlayFabId)
            {}

            ~UserInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"MinCatalogVersion"], MinCatalogVersion);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MinCatalogVersion; ToJsonUtilP(MinCatalogVersion, each_MinCatalogVersion); output[L"MinCatalogVersion"] = each_MinCatalogVersion;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
            Int32 RechargeMax;
            time_t RechargeTime;
            Int32 SecondsToRecharge;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                RechargeMax(),
                RechargeTime(),
                SecondsToRecharge()
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                RechargeMax(src.RechargeMax),
                RechargeTime(src.RechargeTime),
                SecondsToRecharge(src.SecondsToRecharge)
            {}

            ~VirtualCurrencyRechargeTime() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"RechargeMax"], RechargeMax);
                FromJsonUtilT(input[L"RechargeTime"], RechargeTime);
                FromJsonUtilP(input[L"SecondsToRecharge"], SecondsToRecharge);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_RechargeMax; ToJsonUtilP(RechargeMax, each_RechargeMax); output[L"RechargeMax"] = each_RechargeMax;
                web::json::value each_RechargeTime; ToJsonUtilT(RechargeTime, each_RechargeTime); output[L"RechargeTime"] = each_RechargeTime;
                web::json::value each_SecondsToRecharge; ToJsonUtilP(SecondsToRecharge, each_SecondsToRecharge); output[L"SecondsToRecharge"] = each_SecondsToRecharge;
                return output;
            }
        };

        struct UserInfoResponse : public PlayFabResultCommon
        {
            std::list<ItemInstance> Inventory;
            bool IsDeveloper;
            std::string PlayFabId;
            std::string SteamId;
            std::string TitleDisplayName;
            std::string Username;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            UserInfoResponse() :
                PlayFabResultCommon(),
                Inventory(),
                IsDeveloper(),
                PlayFabId(),
                SteamId(),
                TitleDisplayName(),
                Username(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            UserInfoResponse(const UserInfoResponse& src) :
                PlayFabResultCommon(),
                Inventory(src.Inventory),
                IsDeveloper(src.IsDeveloper),
                PlayFabId(src.PlayFabId),
                SteamId(src.SteamId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~UserInfoResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Inventory"], Inventory);
                FromJsonUtilP(input[L"IsDeveloper"], IsDeveloper);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"SteamId"], SteamId);
                FromJsonUtilS(input[L"TitleDisplayName"], TitleDisplayName);
                FromJsonUtilS(input[L"Username"], Username);
                FromJsonUtilP(input[L"VirtualCurrency"], VirtualCurrency);
                FromJsonUtilO(input[L"VirtualCurrencyRechargeTimes"], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[L"Inventory"] = each_Inventory;
                web::json::value each_IsDeveloper; ToJsonUtilP(IsDeveloper, each_IsDeveloper); output[L"IsDeveloper"] = each_IsDeveloper;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_SteamId; ToJsonUtilS(SteamId, each_SteamId); output[L"SteamId"] = each_SteamId;
                web::json::value each_TitleDisplayName; ToJsonUtilS(TitleDisplayName, each_TitleDisplayName); output[L"TitleDisplayName"] = each_TitleDisplayName;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[L"VirtualCurrencyRechargeTimes"] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

    }
}

#endif
