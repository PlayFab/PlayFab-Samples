#include "pch.h"
#include "PlayerProfileSummary.h"
#include "playfab/PlayFabClientDataModels.h"
#include <sstream>

using namespace PlayFab;
using namespace ClientModels;

namespace
{
    std::wstring FormatTimeValue(const time_t &timeVal)
    {
        struct tm t;
        localtime_s(&t, &timeVal);
        char timeBuffer[26] = {};
        asctime_s(timeBuffer, &t);
        return WidenString(timeBuffer);
    }

    void FormatAdCampaignAttributionModel(const AdCampaignAttributionModel &adModel, std::wstringstream &stream, int indentAmount = 0)
    {
        std::wstring indent(indentAmount, L' ');
        stream << indent << L"CampaignID: " << WidenString(adModel.CampaignId) << L"\n";
        stream << indent << L"PlatForm: " << WidenString(adModel.Platform) << L"\n";
        stream << indent << L"AttributedAt: " << FormatTimeValue(adModel.AttributedAt);
    }

    void FormatContactEmailInfoModel(const ContactEmailInfoModel &infoModel, std::wstringstream &stream, int indentAmount = 0)
    {
        std::wstring indent(indentAmount, L' ');
        stream << indent << L"Name: " << WidenString(infoModel.Name) << L"\n";
        stream << indent << L"Email Address: " << WidenString(infoModel.EmailAddress) << L"\n";

        if (infoModel.VerificationStatus.notNull())
        {
            stream << indent << L"Verification Status: ";
            EmailVerificationStatus status = infoModel.VerificationStatus;
            switch (status)
            {
            case EmailVerificationStatus::EmailVerificationStatusConfirmed:
                stream << L"Confirmed";
                break;
            case EmailVerificationStatus::EmailVerificationStatusPending:
                stream << L"Pending";
                break;
            case EmailVerificationStatus::EmailVerificationStatusUnverified:
                stream << L"Not Verified";
                break;
            }

            stream << L"\n";
        }
    }
    
    std::wstring FormatLoginIdentityProvider(LoginIdentityProvider provider)
    {
        switch (provider)
        {
        case LoginIdentityProvider::LoginIdentityProviderPlayFab:
            return L"PlayFab";
        case LoginIdentityProvider::LoginIdentityProviderCustom:
            return L"Custom";
        case LoginIdentityProvider::LoginIdentityProviderGameCenter:
            return L"Game Center";
        case LoginIdentityProvider::LoginIdentityProviderGooglePlay:
            return L"Google Play";
        case LoginIdentityProvider::LoginIdentityProviderSteam:
            return L"Steam";
        case LoginIdentityProvider::LoginIdentityProviderXBoxLive:
            return L"Xbox Live";
        case LoginIdentityProvider::LoginIdentityProviderPSN:
            return L"Play Station Network";
        case LoginIdentityProvider::LoginIdentityProviderKongregate:
            return L"Kongregate";
        case LoginIdentityProvider::LoginIdentityProviderFacebook:
            return L"Facebook";
        case LoginIdentityProvider::LoginIdentityProviderIOSDevice:
            return L"IOS Device";
        case LoginIdentityProvider::LoginIdentityProviderAndroidDevice:
            return L"Android Device";
        case LoginIdentityProvider::LoginIdentityProviderTwitch:
            return L"Twitch";
        case LoginIdentityProvider::LoginIdentityProviderWindowsHello:
            return L"Windows Hello";
        case LoginIdentityProvider::LoginIdentityProviderUnknown:
        default:
            return L"Unknown";
        }
    }

    void FormatLinkedPlatformAccountModel(const LinkedPlatformAccountModel &linkedAccount, std::wstringstream &stream, int indentAmount = 0)
    {
        std::wstring indent(indentAmount, L' ');
        stream << indent << L"User Name: " << WidenString(linkedAccount.Username) << L"\n";
        stream << indent << L"Platform User ID: " << WidenString(linkedAccount.PlatformUserId) << L"\n";
        stream << indent << L"Email: " << WidenString(linkedAccount.Email) << L"\n";
        if (linkedAccount.Platform.notNull())
        {
            stream << indent << L"Platform: " << FormatLoginIdentityProvider(linkedAccount.Platform) << L"\n";
        }
    }

    void FormatLocationModel(const LocationModel &locationModel, std::wstringstream &stream, int indentAmount = 0)
    {
        std::wstring indent(indentAmount, L' ');
        stream << indent << L"City: " << WidenString(locationModel.City) << L"\n";
        if (locationModel.pfContinentCode.notNull())
        {
            stream << indent << L"Continent: ";
            const ContinentCode continentCode = locationModel.pfContinentCode;
            switch (continentCode)
            {
            case ContinentCode::ContinentCodeAF:
                stream << L"Africa";
                break;
            case ContinentCode::ContinentCodeAN:
                stream << L"Antarctica";
                break;
            case ContinentCode::ContinentCodeAS:
                stream << L"Asia";
                break;
            case ContinentCode::ContinentCodeEU:
                stream << L"Europe";
                break;
            case ContinentCode::ContinentCodeNA:
                stream << L"North America";
                break;
            case ContinentCode::ContinentCodeOC:
                stream << L"Oceania";
                break;
            case ContinentCode::ContinentCodeSA:
                stream << L"South America";
                break;
            }
            stream << L"\n";
        }
        if (locationModel.pfCountryCode.notNull())
        {
            stream << indent << L"Country/region: ";
            const CountryCode countryCode = locationModel.pfCountryCode;
            switch (countryCode)
            {
            case CountryCodeAF:
                stream << L"AF";
                break;

            case CountryCodeAX:
                stream << L"AX";
                break;
            case CountryCodeAL:
                stream << L"AL";
                break;
            case CountryCodeDZ:
                stream << L"DZ";
                break;
            case CountryCodeAS:
                stream << L"AS";
                break;
            case CountryCodeAD:
                stream << L"AD";
                break;
            case CountryCodeAO:
                stream << L"AO";
                break;
            case CountryCodeAI:
                stream << L"AI";
                break;
            case CountryCodeAQ:
                stream << L"AQ";
                break;
            case CountryCodeAG:
                stream << L"AG";
                break;
            case CountryCodeAR:
                stream << L"AR";
                break;
            case CountryCodeAM:
                stream << L"AM";
                break;
            case CountryCodeAW:
                stream << L"AW";
                break;
            case CountryCodeAU:
                stream << L"AU";
                break;
            case CountryCodeAT:
                stream << L"AT";
                break;
            case CountryCodeAZ:
                stream << L"AZ";
                break;
            case CountryCodeBS:
                stream << L"BS";
                break;
            case CountryCodeBH:
                stream << L"BH";
                break;
            case CountryCodeBD:
                stream << L"BD";
                break;
            case CountryCodeBB:
                stream << L"BB";
                break;
            case CountryCodeBY:
                stream << L"BY";
                break;
            case CountryCodeBE:
                stream << L"BE";
                break;
            case CountryCodeBZ:
                stream << L"BZ";
                break;
            case CountryCodeBJ:
                stream << L"BJ";
                break;
            case CountryCodeBM:
                stream << L"BM";
                break;
            case CountryCodeBT:
                stream << L"BT";
                break;
            case CountryCodeBO:
                stream << L"BO";
                break;
            case CountryCodeBQ:
                stream << L"BQ";
                break;
            case CountryCodeBA:
                stream << L"BA";
                break;
            case CountryCodeBW:
                stream << L"BW";
                break;
            case CountryCodeBV:
                stream << L"BV";
                break;
            case CountryCodeBR:
                stream << L"BR";
                break;
            case CountryCodeIO:
                stream << L"IO";
                break;
            case CountryCodeBN:
                stream << L"BN";
                break;
            case CountryCodeBG:
                stream << L"BG";
                break;
            case CountryCodeBF:
                stream << L"BF";
                break;
            case CountryCodeBI:
                stream << L"BI";
                break;
            case CountryCodeKH:
                stream << L"KH";
                break;
            case CountryCodeCM:
                stream << L"CM";
                break;
            case CountryCodeCA:
                stream << L"CA";
                break;
            case CountryCodeCV:
                stream << L"CV";
                break;
            case CountryCodeKY:
                stream << L"KY";
                break;
            case CountryCodeCF:
                stream << L"CF";
                break;
            case CountryCodeTD:
                stream << L"TD";
                break;
            case CountryCodeCL:
                stream << L"CL";
                break;
            case CountryCodeCN:
                stream << L"CN";
                break;
            case CountryCodeCX:
                stream << L"CX";
                break;
            case CountryCodeCC:
                stream << L"CC";
                break;
            case CountryCodeCO:
                stream << L"CO";
                break;
            case CountryCodeKM:
                stream << L"KM";
                break;
            case CountryCodeCG:
                stream << L"CG";
                break;
            case CountryCodeCD:
                stream << L"CD";
                break;
            case CountryCodeCK:
                stream << L"CK";
                break;
            case CountryCodeCR:
                stream << L"CR";
                break;
            case CountryCodeCI:
                stream << L"CI";
                break;
            case CountryCodeHR:
                stream << L"HR";
                break;
            case CountryCodeCU:
                stream << L"CU";
                break;
            case CountryCodeCW:
                stream << L"CW";
                break;
            case CountryCodeCY:
                stream << L"CY";
                break;
            case CountryCodeCZ:
                stream << L"CZ";
                break;
            case CountryCodeDK:
                stream << L"DK";
                break;
            case CountryCodeDJ:
                stream << L"DJ";
                break;
            case CountryCodeDM:
                stream << L"DM";
                break;
            case CountryCodeDO:
                stream << L"DO";
                break;
            case CountryCodeEC:
                stream << L"EC";
                break;
            case CountryCodeEG:
                stream << L"EG";
                break;
            case CountryCodeSV:
                stream << L"SV";
                break;
            case CountryCodeGQ:
                stream << L"GQ";
                break;
            case CountryCodeER:
                stream << L"ER";
                break;
            case CountryCodeEE:
                stream << L"EE";
                break;
            case CountryCodeET:
                stream << L"ET";
                break;
            case CountryCodeFK:
                stream << L"FK";
                break;
            case CountryCodeFO:
                stream << L"FO";
                break;
            case CountryCodeFJ:
                stream << L"FJ";
                break;
            case CountryCodeFI:
                stream << L"FI";
                break;
            case CountryCodeFR:
                stream << L"FR";
                break;
            case CountryCodeGF:
                stream << L"GF";
                break;
            case CountryCodePF:
                stream << L"PF";
                break;
            case CountryCodeTF:
                stream << L"TF";
                break;
            case CountryCodeGA:
                stream << L"GA";
                break;
            case CountryCodeGM:
                stream << L"GM";
                break;
            case CountryCodeGE:
                stream << L"GE";
                break;
            case CountryCodeDE:
                stream << L"DE";
                break;
            case CountryCodeGH:
                stream << L"GH";
                break;
            case CountryCodeGI:
                stream << L"GI";
                break;
            case CountryCodeGR:
                stream << L"GR";
                break;
            case CountryCodeGL:
                stream << L"GL";
                break;
            case CountryCodeGD:
                stream << L"GD";
                break;
            case CountryCodeGP:
                stream << L"GP";
                break;
            case CountryCodeGU:
                stream << L"GU";
                break;
            case CountryCodeGT:
                stream << L"GT";
                break;
            case CountryCodeGG:
                stream << L"GG";
                break;
            case CountryCodeGN:
                stream << L"GN";
                break;
            case CountryCodeGW:
                stream << L"GW";
                break;
            case CountryCodeGY:
                stream << L"GY";
                break;
            case CountryCodeHT:
                stream << L"HT";
                break;
            case CountryCodeHM:
                stream << L"HM";
                break;
            case CountryCodeVA:
                stream << L"VA";
                break;
            case CountryCodeHN:
                stream << L"HN";
                break;
            case CountryCodeHK:
                stream << L"HK";
                break;
            case CountryCodeHU:
                stream << L"HU";
                break;
            case CountryCodeIS:
                stream << L"IS";
                break;
            case CountryCodeIN:
                stream << L"IN";
                break;
            case CountryCodeID:
                stream << L"ID";
                break;
            case CountryCodeIR:
                stream << L"IR";
                break;
            case CountryCodeIQ:
                stream << L"IQ";
                break;
            case CountryCodeIE:
                stream << L"IE";
                break;
            case CountryCodeIM:
                stream << L"IM";
                break;
            case CountryCodeIL:
                stream << L"IL";
                break;
            case CountryCodeIT:
                stream << L"IT";
                break;
            case CountryCodeJM:
                stream << L"JM";
                break;
            case CountryCodeJP:
                stream << L"JP";
                break;
            case CountryCodeJE:
                stream << L"JE";
                break;
            case CountryCodeJO:
                stream << L"JO";
                break;
            case CountryCodeKZ:
                stream << L"KZ";
                break;
            case CountryCodeKE:
                stream << L"KE";
                break;
            case CountryCodeKI:
                stream << L"KI";
                break;
            case CountryCodeKP:
                stream << L"KP";
                break;
            case CountryCodeKR:
                stream << L"KR";
                break;
            case CountryCodeKW:
                stream << L"KW";
                break;
            case CountryCodeKG:
                stream << L"KG";
                break;
            case CountryCodeLA:
                stream << L"LA";
                break;
            case CountryCodeLV:
                stream << L"LV";
                break;
            case CountryCodeLB:
                stream << L"LB";
                break;
            case CountryCodeLS:
                stream << L"LS";
                break;
            case CountryCodeLR:
                stream << L"LR";
                break;
            case CountryCodeLY:
                stream << L"LY";
                break;
            case CountryCodeLI:
                stream << L"LI";
                break;
            case CountryCodeLT:
                stream << L"LT";
                break;
            case CountryCodeLU:
                stream << L"LU";
                break;
            case CountryCodeMO:
                stream << L"MO";
                break;
            case CountryCodeMK:
                stream << L"MK";
                break;
            case CountryCodeMG:
                stream << L"MG";
                break;
            case CountryCodeMW:
                stream << L"MW";
                break;
            case CountryCodeMY:
                stream << L"MY";
                break;
            case CountryCodeMV:
                stream << L"MV";
                break;
            case CountryCodeML:
                stream << L"ML";
                break;
            case CountryCodeMT:
                stream << L"MT";
                break;
            case CountryCodeMH:
                stream << L"MH";
                break;
            case CountryCodeMQ:
                stream << L"MQ";
                break;
            case CountryCodeMR:
                stream << L"MR";
                break;
            case CountryCodeMU:
                stream << L"MU";
                break;
            case CountryCodeYT:
                stream << L"YT";
                break;
            case CountryCodeMX:
                stream << L"MX";
                break;
            case CountryCodeFM:
                stream << L"FM";
                break;
            case CountryCodeMD:
                stream << L"MD";
                break;
            case CountryCodeMC:
                stream << L"MC";
                break;
            case CountryCodeMN:
                stream << L"MN";
                break;
            case CountryCodeME:
                stream << L"ME";
                break;
            case CountryCodeMS:
                stream << L"MS";
                break;
            case CountryCodeMA:
                stream << L"MA";
                break;
            case CountryCodeMZ:
                stream << L"MZ";
                break;
            case CountryCodeMM:
                stream << L"MM";
                break;
            case CountryCodeNA:
                stream << L"NA";
                break;
            case CountryCodeNR:
                stream << L"NR";
                break;
            case CountryCodeNP:
                stream << L"NP";
                break;
            case CountryCodeNL:
                stream << L"NL";
                break;
            case CountryCodeNC:
                stream << L"NC";
                break;
            case CountryCodeNZ:
                stream << L"NZ";
                break;
            case CountryCodeNI:
                stream << L"NI";
                break;
            case CountryCodeNE:
                stream << L"NE";
                break;
            case CountryCodeNG:
                stream << L"NG";
                break;
            case CountryCodeNU:
                stream << L"NU";
                break;
            case CountryCodeNF:
                stream << L"NF";
                break;
            case CountryCodeMP:
                stream << L"MP";
                break;
            case CountryCodeNO:
                stream << L"NO";
                break;
            case CountryCodeOM:
                stream << L"OM";
                break;
            case CountryCodePK:
                stream << L"PK";
                break;
            case CountryCodePW:
                stream << L"PW";
                break;
            case CountryCodePS:
                stream << L"PS";
                break;
            case CountryCodePA:
                stream << L"PA";
                break;
            case CountryCodePG:
                stream << L"PG";
                break;
            case CountryCodePY:
                stream << L"PY";
                break;
            case CountryCodePE:
                stream << L"PE";
                break;
            case CountryCodePH:
                stream << L"PH";
                break;
            case CountryCodePN:
                stream << L"PN";
                break;
            case CountryCodePL:
                stream << L"PL";
                break;
            case CountryCodePT:
                stream << L"PT";
                break;
            case CountryCodePR:
                stream << L"PR";
                break;
            case CountryCodeQA:
                stream << L"QA";
                break;
            case CountryCodeRE:
                stream << L"RE";
                break;
            case CountryCodeRO:
                stream << L"RO";
                break;
            case CountryCodeRU:
                stream << L"RU";
                break;
            case CountryCodeRW:
                stream << L"RW";
                break;
            case CountryCodeBL:
                stream << L"BL";
                break;
            case CountryCodeSH:
                stream << L"SH";
                break;
            case CountryCodeKN:
                stream << L"KN";
                break;
            case CountryCodeLC:
                stream << L"LC";
                break;
            case CountryCodeMF:
                stream << L"MF";
                break;
            case CountryCodePM:
                stream << L"PM";
                break;
            case CountryCodeVC:
                stream << L"VC";
                break;
            case CountryCodeWS:
                stream << L"WS";
                break;
            case CountryCodeSM:
                stream << L"SM";
                break;
            case CountryCodeST:
                stream << L"ST";
                break;
            case CountryCodeSA:
                stream << L"SA";
                break;
            case CountryCodeSN:
                stream << L"SN";
                break;
            case CountryCodeRS:
                stream << L"RS";
                break;
            case CountryCodeSC:
                stream << L"SC";
                break;
            case CountryCodeSL:
                stream << L"SL";
                break;
            case CountryCodeSG:
                stream << L"SG";
                break;
            case CountryCodeSX:
                stream << L"SX";
                break;
            case CountryCodeSK:
                stream << L"SK";
                break;
            case CountryCodeSI:
                stream << L"SI";
                break;
            case CountryCodeSB:
                stream << L"SB";
                break;
            case CountryCodeSO:
                stream << L"SO";
                break;
            case CountryCodeZA:
                stream << L"ZA";
                break;
            case CountryCodeGS:
                stream << L"GS";
                break;
            case CountryCodeSS:
                stream << L"SS";
                break;
            case CountryCodeES:
                stream << L"ES";
                break;
            case CountryCodeLK:
                stream << L"LK";
                break;
            case CountryCodeSD:
                stream << L"SD";
                break;
            case CountryCodeSR:
                stream << L"SR";
                break;
            case CountryCodeSJ:
                stream << L"SJ";
                break;
            case CountryCodeSZ:
                stream << L"SZ";
                break;
            case CountryCodeSE:
                stream << L"SE";
                break;
            case CountryCodeCH:
                stream << L"CH";
                break;
            case CountryCodeSY:
                stream << L"SY";
                break;
            case CountryCodeTW:
                stream << L"TW";
                break;
            case CountryCodeTJ:
                stream << L"TJ";
                break;
            case CountryCodeTZ:
                stream << L"TZ";
                break;
            case CountryCodeTH:
                stream << L"TH";
                break;
            case CountryCodeTL:
                stream << L"TL";
                break;
            case CountryCodeTG:
                stream << L"TG";
                break;
            case CountryCodeTK:
                stream << L"TK";
                break;
            case CountryCodeTO:
                stream << L"TO";
                break;
            case CountryCodeTT:
                stream << L"TT";
                break;
            case CountryCodeTN:
                stream << L"TN";
                break;
            case CountryCodeTR:
                stream << L"TR";
                break;
            case CountryCodeTM:
                stream << L"TM";
                break;
            case CountryCodeTC:
                stream << L"TC";
                break;
            case CountryCodeTV:
                stream << L"TV";
                break;
            case CountryCodeUG:
                stream << L"UG";
                break;
            case CountryCodeUA:
                stream << L"UA";
                break;
            case CountryCodeAE:
                stream << L"AE";
                break;
            case CountryCodeGB:
                stream << L"GB";
                break;
            case CountryCodeUS:
                stream << L"US";
                break;
            case CountryCodeUM:
                stream << L"UM";
                break;
            case CountryCodeUY:
                stream << L"UY";
                break;
            case CountryCodeUZ:
                stream << L"UZ";
                break;
            case CountryCodeVU:
                stream << L"VU";
                break;
            case CountryCodeVE:
                stream << L"VE";
                break;
            case CountryCodeVN:
                stream << L"VN";
                break;
            case CountryCodeVG:
                stream << L"VG";
                break;
            case CountryCodeVI:
                stream << L"VI";
                break;
            case CountryCodeWF:
                stream << L"WF";
                break;
            case CountryCodeEH:
                stream << L"EH";
                break;
            case CountryCodeYE:
                stream << L"YE";
                break;
            case CountryCodeZM:
                stream << L"ZM";
                break;
            case CountryCodeZW:
                stream << L"ZW";
                break;
            default:
                stream << L"UNKNOWN";
                break;
            }
            stream << L"\n";
        }
        if (locationModel.Latitude.notNull())
        {
            stream << indent << L"Latitude: " << static_cast<const double&>(locationModel.Latitude) << L"\n";
        }
        if (locationModel.Longitude.notNull())
        {
            stream << indent << L"Longitude: " << static_cast<const double&>(locationModel.Longitude) << L"\n";
        }
    }

    void FormatSubscriptionModel(const SubscriptionModel &subscriptionModel, std::wstringstream &stream, int indentAmount)
    {
        std::wstring indent(indentAmount, L' ');
        stream << indent << L"Subscription Provider: " << WidenString(subscriptionModel.SubscriptionProvider) << L"\n";
        stream << indent << L"Subscription ID: " << WidenString(subscriptionModel.SubscriptionId) << L"\n";
        stream << indent << L"Subscription Item ID: " << WidenString(subscriptionModel.SubscriptionItemId) << L"\n";
        if (subscriptionModel.Status.notNull())
        {
            stream << indent << L"Status: ";
            const SubscriptionProviderStatus &status = subscriptionModel.Status;
            switch (status)
            {
            case SubscriptionProviderStatus::SubscriptionProviderStatusCancelled:
                stream << L"Cancelled";
                break;
            case SubscriptionProviderStatus::SubscriptionProviderStatusNoError:
                stream << L"No Error";
                break;
            case SubscriptionProviderStatus::SubscriptionProviderStatusUnknownError:
                stream << L"Unknown Error";
                break;
            case SubscriptionProviderStatus::SubscriptionProviderStatusBillingError:
                stream << L"Billing Error";
                break;
            case SubscriptionProviderStatus::SubscriptionProviderStatusProductUnavailable:
                stream << L"Product Unavailable";
                break;
            case SubscriptionProviderStatus::SubscriptionProviderStatusCustomerDidNotAcceptPriceChange:
                stream << L"Customer did not accept change";
                break;
            case SubscriptionProviderStatus::SubscriptionProviderStatusFreeTrial:
                stream << L"Free Trial";
                break;
            case SubscriptionProviderStatus::SubscriptionProviderStatusPaymentPending:
                stream << L"Payment Pending";
                break;
            }
            stream << L"\n";
        }
        if (subscriptionModel.IsActive)
        {
            stream << indent << L"Subscription is active\n";
        }
        else
        {
            stream << indent << L"Subscription is innactive\n";
        }
        stream << indent << L"Initial Subscription Time: " << FormatTimeValue(subscriptionModel.InitialSubscriptionTime);
        stream << indent << L"Expiration Time: " << FormatTimeValue(subscriptionModel.Expiration);
    }

    void FormatMembershipModel(const MembershipModel &membershipModel, std::wstringstream &stream, int indentAmount = 0)
    {
        std::wstring indent(indentAmount, L' ');
        if (membershipModel.IsActive)
        {
            stream << indent << L"Active Membership:\n";
        }
        else
        {
            stream << indent << L"Innactive Membership:\n";
        }
        stream << indent << L"Membership ID: " << WidenString(membershipModel.MembershipId) << L"\n";
        stream << indent << L"Membership Expiration: " << FormatTimeValue(membershipModel.MembershipExpiration);
        if (membershipModel.OverrideExpiration.notNull())
        {
            stream << indent << L"Override Expiration: " << FormatTimeValue(membershipModel.OverrideExpiration);
        }
        stream << indent << L"Subscriptions:\n";
        auto itr = membershipModel.Subscriptions.begin();
        auto itrEnd = membershipModel.Subscriptions.end();
        for (; itr != itrEnd; ++itr)
        {
            FormatSubscriptionModel(*itr, stream, 2 * indentAmount);
        }
    }

    void FormatPushNotificationRegistrationModel(const PushNotificationRegistrationModel &pushNotificationRegistrationModel, std::wstringstream &stream, int indentAmount = 0)
    {
        std::wstring indent(indentAmount, L' ');
        stream << indent<< L"Notification Endpoint ARN: " << WidenString(pushNotificationRegistrationModel.NotificationEndpointARN) << L"\n";
        if (pushNotificationRegistrationModel.Platform.notNull())
        {
            stream << indent << L"Platform: ";
            PushNotificationPlatform platform = pushNotificationRegistrationModel.Platform;
            switch (platform)
            {
            case PushNotificationPlatform::PushNotificationPlatformApplePushNotificationService:
                stream << indent << L"Apple Push Notification Service";
                break;
            case PushNotificationPlatform::PushNotificationPlatformGoogleCloudMessaging:
                stream << indent << L"Google Cloud Messaging";
                break;
            }
            stream << L"\n";
        }
    }

    void FormatStatisticModel(const StatisticModel statModel, std::wstringstream &stream, int indentAmount = 0)
    {
        std::wstring indent(indentAmount, L' ');
        stream << indent << L"Name: " << WidenString(statModel.Name) << L"\n";
        stream << indent << L"Value: " << statModel.Value << L"\n";
        stream << indent << L"Version: " << statModel.Version << L"\n";
    }


} // ANONYMOUS namespace

PlayFabPlayerProfileSummary::PlayFabPlayerProfileSummary()
{
}

PlayFabPlayerProfileSummary::PlayFabPlayerProfileSummary(
    const PlayFab::ClientModels::PlayerProfileViewConstraints &constraints,
    const PlayFab::ClientModels::PlayerProfileModel &profile)
{
    std::wstringstream stream;
    
    //PlayerProfileModel::PlayerId;
    stream << L"Player ID: " << WidenString(profile.PlayerId) << L"\n";

    //PlayerProfileModel::TitleId
    stream << L"Title ID: " << WidenString(profile.TitleId) << L"\n";

    //PlayerProfileModel::PublisherId;
    stream << L"Publisher Id: " << WidenString(profile.PublisherId) << L"\n";

    //PlayerProfileModel::AdCampaignAttributions
    if (constraints.ShowCampaignAttributions)
    {
        stream << L"Campaign Attributions:\n";
        auto itr = profile.AdCampaignAttributions.begin();
        auto itrEnd = profile.AdCampaignAttributions.end();
        for (;itr != itrEnd; ++itr)
        {
            FormatAdCampaignAttributionModel(*itr, stream, 3);
        }
    }

    //PlayerProfileModel::AvatarUrl
    if (constraints.ShowAvatarUrl)
    {
        stream << L"AvatarURL: " << WidenString(profile.AvatarUrl) << L"\n";
    }

    //PlayerProfileModel::BannedUntil
    if (constraints.ShowBannedUntil && profile.BannedUntil.notNull())
    {
        stream << L"BannedUntil: " << FormatTimeValue(profile.BannedUntil);
    }

    //PlayerProfileModel::ContactEmailAddresses
    if (constraints.ShowContactEmailAddresses)
    {
        stream << L"Contact Email Addresses:\n";
        auto itr = profile.ContactEmailAddresses.begin();
        auto itrEnd = profile.ContactEmailAddresses.end();
        for (; itr != itrEnd; ++itr)
        {
            FormatContactEmailInfoModel(*itr, stream, 3);
        }
    }

    //PlayerProfileModel::Created
    if (constraints.ShowCreated && profile.Created.notNull())
    {
        stream << L"Created: " << FormatTimeValue(profile.Created);
    }

    //PlayerProfileModel::DisplayName
    if (constraints.ShowDisplayName)
    {
        stream << L"Display Name: " << WidenString(profile.DisplayName) << L"\n";
    }

    //PlayerProfileModel::LastLogin
    if (constraints.ShowLastLogin && profile.LastLogin.notNull())
    {
        stream << L"Last Login: " << FormatTimeValue(profile.LastLogin);
    }

    //PlayerProfileModel::LinkedAccounts
    if (constraints.ShowLinkedAccounts)
    {
        stream << L"Linked Accounts:\n";
        auto itr = profile.LinkedAccounts.begin();
        auto itrEnd = profile.LinkedAccounts.end();
        for (; itr != itrEnd; ++itr)
        {
            FormatLinkedPlatformAccountModel(*itr, stream, 3);
        }
    }

    //PlayerProfileModel::Locations
    if (constraints.ShowLocations)
    {
        stream << L"Locations: \n";
        auto itr = profile.Locations.begin();
        auto itrEnd = profile.Locations.end();
        for (; itr != itrEnd; ++itr)
        {
            FormatLocationModel(*itr, stream, 3);
        }
    }

    //PlayerProfileModel::Memberships
    if (constraints.ShowMemberships)
    {
        stream << L"Memberships: \n";
        auto itr = profile.Memberships.begin();
        auto itrEnd = profile.Memberships.end();
        for (; itr != itrEnd; ++itr)
        {
            FormatMembershipModel(*itr, stream, 3);
        }
    }

    //PlayerProfileModel::Origination
    if (constraints.ShowOrigination && profile.Origination.notNull())
    {
        stream << L"Origination: " << FormatLoginIdentityProvider(profile.Origination) << L"\n";
    }

    //PlayerProfileModel::PushNotificationRegistrations
    if (constraints.ShowPushNotificationRegistrations)
    {
        stream << L"Push Notification Registrations:\n";
        auto itr = profile.PushNotificationRegistrations.begin();
        auto itrEnd = profile.PushNotificationRegistrations.end();
        for (; itr != itrEnd; ++itr)
        {
            FormatPushNotificationRegistrationModel(*itr, stream, 3);
        }
    }

    //PlayerProfileModel::Statistics
    if (constraints.ShowStatistics)
    {
        stream << L"Statistics:\n";
        auto itr = profile.Statistics.begin();
        auto itrEnd = profile.Statistics.end();
        for (; itr != itrEnd; ++itr)
        {
            FormatStatisticModel(*itr, stream, 3);
        }
    }

    //PlayerProfileModel::Tags
    if (constraints.ShowTags)
    {
        stream << L"Tags:\n";
        std::wstring indent(3, L' ');
        auto itr = profile.Tags.begin();
        auto itrEnd = profile.Tags.end();
        for (; itr != itrEnd; ++itr)
        {
            stream << indent << L"Tag Value: " << WidenString(itr->TagValue) << L"\n";
        }
    }

    //PlayerProfileModel::TotalValueToDateInUSD
    if (constraints.ShowTotalValueToDateInUsd && profile.TotalValueToDateInUSD.notNull())
    {
        stream << L"Total Value to Date (USD): " << profile.TotalValueToDateInUSD << L"\n";
    }

    //PlayerProfileModel::ValuesToDate
    if (constraints.ShowValuesToDate)
    {
        stream << L"Values to Date:\n";
        std::wstring indent(3, L' ');
        auto itr = profile.ValuesToDate.begin();
        auto itrEnd = profile.ValuesToDate.end();
        for (; itr != itrEnd; ++itr)
        {
            stream << indent << L"Total Value: " << itr->TotalValue << L"\n";
            stream << indent << L"Total Value as Decimal: " << WidenString(itr->TotalValueAsDecimal) << L"\n";
            stream << indent << L"Currency: " << WidenString(itr->Currency) << L"\n";
        }
    }

    m_formatted = stream.str();
}
