#pragma once

#ifdef ENABLE_PLAYFABADMIN_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace AdminModels
    {
        // Admin Enums
        enum AuthTokenType
        {
            AuthTokenTypeEmail
        };

        inline void ToJsonEnum(const AuthTokenType input, web::json::value& output)
        {
            if (input == AuthTokenTypeEmail) output = web::json::value(L"Email");
        }
        inline void FromJsonEnum(const web::json::value& input, AuthTokenType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Email") output = AuthTokenTypeEmail;
        }

        enum Conditionals
        {
            ConditionalsAny,
            ConditionalsTrue,
            ConditionalsFalse
        };

        inline void ToJsonEnum(const Conditionals input, web::json::value& output)
        {
            if (input == ConditionalsAny) output = web::json::value(L"Any");
            if (input == ConditionalsTrue) output = web::json::value(L"True");
            if (input == ConditionalsFalse) output = web::json::value(L"False");
        }
        inline void FromJsonEnum(const web::json::value& input, Conditionals& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Any") output = ConditionalsAny;
            if (inputStr == L"True") output = ConditionalsTrue;
            if (inputStr == L"False") output = ConditionalsFalse;
        }

        enum ContinentCode
        {
            ContinentCodeAF,
            ContinentCodeAN,
            ContinentCodeAS,
            ContinentCodeEU,
            ContinentCodeNA,
            ContinentCodeOC,
            ContinentCodeSA
        };

        inline void ToJsonEnum(const ContinentCode input, web::json::value& output)
        {
            if (input == ContinentCodeAF) output = web::json::value(L"AF");
            if (input == ContinentCodeAN) output = web::json::value(L"AN");
            if (input == ContinentCodeAS) output = web::json::value(L"AS");
            if (input == ContinentCodeEU) output = web::json::value(L"EU");
            if (input == ContinentCodeNA) output = web::json::value(L"NA");
            if (input == ContinentCodeOC) output = web::json::value(L"OC");
            if (input == ContinentCodeSA) output = web::json::value(L"SA");
        }
        inline void FromJsonEnum(const web::json::value& input, ContinentCode& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"AF") output = ContinentCodeAF;
            if (inputStr == L"AN") output = ContinentCodeAN;
            if (inputStr == L"AS") output = ContinentCodeAS;
            if (inputStr == L"EU") output = ContinentCodeEU;
            if (inputStr == L"NA") output = ContinentCodeNA;
            if (inputStr == L"OC") output = ContinentCodeOC;
            if (inputStr == L"SA") output = ContinentCodeSA;
        }

        enum CountryCode
        {
            CountryCodeAF,
            CountryCodeAX,
            CountryCodeAL,
            CountryCodeDZ,
            CountryCodeAS,
            CountryCodeAD,
            CountryCodeAO,
            CountryCodeAI,
            CountryCodeAQ,
            CountryCodeAG,
            CountryCodeAR,
            CountryCodeAM,
            CountryCodeAW,
            CountryCodeAU,
            CountryCodeAT,
            CountryCodeAZ,
            CountryCodeBS,
            CountryCodeBH,
            CountryCodeBD,
            CountryCodeBB,
            CountryCodeBY,
            CountryCodeBE,
            CountryCodeBZ,
            CountryCodeBJ,
            CountryCodeBM,
            CountryCodeBT,
            CountryCodeBO,
            CountryCodeBQ,
            CountryCodeBA,
            CountryCodeBW,
            CountryCodeBV,
            CountryCodeBR,
            CountryCodeIO,
            CountryCodeBN,
            CountryCodeBG,
            CountryCodeBF,
            CountryCodeBI,
            CountryCodeKH,
            CountryCodeCM,
            CountryCodeCA,
            CountryCodeCV,
            CountryCodeKY,
            CountryCodeCF,
            CountryCodeTD,
            CountryCodeCL,
            CountryCodeCN,
            CountryCodeCX,
            CountryCodeCC,
            CountryCodeCO,
            CountryCodeKM,
            CountryCodeCG,
            CountryCodeCD,
            CountryCodeCK,
            CountryCodeCR,
            CountryCodeCI,
            CountryCodeHR,
            CountryCodeCU,
            CountryCodeCW,
            CountryCodeCY,
            CountryCodeCZ,
            CountryCodeDK,
            CountryCodeDJ,
            CountryCodeDM,
            CountryCodeDO,
            CountryCodeEC,
            CountryCodeEG,
            CountryCodeSV,
            CountryCodeGQ,
            CountryCodeER,
            CountryCodeEE,
            CountryCodeET,
            CountryCodeFK,
            CountryCodeFO,
            CountryCodeFJ,
            CountryCodeFI,
            CountryCodeFR,
            CountryCodeGF,
            CountryCodePF,
            CountryCodeTF,
            CountryCodeGA,
            CountryCodeGM,
            CountryCodeGE,
            CountryCodeDE,
            CountryCodeGH,
            CountryCodeGI,
            CountryCodeGR,
            CountryCodeGL,
            CountryCodeGD,
            CountryCodeGP,
            CountryCodeGU,
            CountryCodeGT,
            CountryCodeGG,
            CountryCodeGN,
            CountryCodeGW,
            CountryCodeGY,
            CountryCodeHT,
            CountryCodeHM,
            CountryCodeVA,
            CountryCodeHN,
            CountryCodeHK,
            CountryCodeHU,
            CountryCodeIS,
            CountryCodeIN,
            CountryCodeID,
            CountryCodeIR,
            CountryCodeIQ,
            CountryCodeIE,
            CountryCodeIM,
            CountryCodeIL,
            CountryCodeIT,
            CountryCodeJM,
            CountryCodeJP,
            CountryCodeJE,
            CountryCodeJO,
            CountryCodeKZ,
            CountryCodeKE,
            CountryCodeKI,
            CountryCodeKP,
            CountryCodeKR,
            CountryCodeKW,
            CountryCodeKG,
            CountryCodeLA,
            CountryCodeLV,
            CountryCodeLB,
            CountryCodeLS,
            CountryCodeLR,
            CountryCodeLY,
            CountryCodeLI,
            CountryCodeLT,
            CountryCodeLU,
            CountryCodeMO,
            CountryCodeMK,
            CountryCodeMG,
            CountryCodeMW,
            CountryCodeMY,
            CountryCodeMV,
            CountryCodeML,
            CountryCodeMT,
            CountryCodeMH,
            CountryCodeMQ,
            CountryCodeMR,
            CountryCodeMU,
            CountryCodeYT,
            CountryCodeMX,
            CountryCodeFM,
            CountryCodeMD,
            CountryCodeMC,
            CountryCodeMN,
            CountryCodeME,
            CountryCodeMS,
            CountryCodeMA,
            CountryCodeMZ,
            CountryCodeMM,
            CountryCodeNA,
            CountryCodeNR,
            CountryCodeNP,
            CountryCodeNL,
            CountryCodeNC,
            CountryCodeNZ,
            CountryCodeNI,
            CountryCodeNE,
            CountryCodeNG,
            CountryCodeNU,
            CountryCodeNF,
            CountryCodeMP,
            CountryCodeNO,
            CountryCodeOM,
            CountryCodePK,
            CountryCodePW,
            CountryCodePS,
            CountryCodePA,
            CountryCodePG,
            CountryCodePY,
            CountryCodePE,
            CountryCodePH,
            CountryCodePN,
            CountryCodePL,
            CountryCodePT,
            CountryCodePR,
            CountryCodeQA,
            CountryCodeRE,
            CountryCodeRO,
            CountryCodeRU,
            CountryCodeRW,
            CountryCodeBL,
            CountryCodeSH,
            CountryCodeKN,
            CountryCodeLC,
            CountryCodeMF,
            CountryCodePM,
            CountryCodeVC,
            CountryCodeWS,
            CountryCodeSM,
            CountryCodeST,
            CountryCodeSA,
            CountryCodeSN,
            CountryCodeRS,
            CountryCodeSC,
            CountryCodeSL,
            CountryCodeSG,
            CountryCodeSX,
            CountryCodeSK,
            CountryCodeSI,
            CountryCodeSB,
            CountryCodeSO,
            CountryCodeZA,
            CountryCodeGS,
            CountryCodeSS,
            CountryCodeES,
            CountryCodeLK,
            CountryCodeSD,
            CountryCodeSR,
            CountryCodeSJ,
            CountryCodeSZ,
            CountryCodeSE,
            CountryCodeCH,
            CountryCodeSY,
            CountryCodeTW,
            CountryCodeTJ,
            CountryCodeTZ,
            CountryCodeTH,
            CountryCodeTL,
            CountryCodeTG,
            CountryCodeTK,
            CountryCodeTO,
            CountryCodeTT,
            CountryCodeTN,
            CountryCodeTR,
            CountryCodeTM,
            CountryCodeTC,
            CountryCodeTV,
            CountryCodeUG,
            CountryCodeUA,
            CountryCodeAE,
            CountryCodeGB,
            CountryCodeUS,
            CountryCodeUM,
            CountryCodeUY,
            CountryCodeUZ,
            CountryCodeVU,
            CountryCodeVE,
            CountryCodeVN,
            CountryCodeVG,
            CountryCodeVI,
            CountryCodeWF,
            CountryCodeEH,
            CountryCodeYE,
            CountryCodeZM,
            CountryCodeZW
        };

        inline void ToJsonEnum(const CountryCode input, web::json::value& output)
        {
            if (input == CountryCodeAF) output = web::json::value(L"AF");
            if (input == CountryCodeAX) output = web::json::value(L"AX");
            if (input == CountryCodeAL) output = web::json::value(L"AL");
            if (input == CountryCodeDZ) output = web::json::value(L"DZ");
            if (input == CountryCodeAS) output = web::json::value(L"AS");
            if (input == CountryCodeAD) output = web::json::value(L"AD");
            if (input == CountryCodeAO) output = web::json::value(L"AO");
            if (input == CountryCodeAI) output = web::json::value(L"AI");
            if (input == CountryCodeAQ) output = web::json::value(L"AQ");
            if (input == CountryCodeAG) output = web::json::value(L"AG");
            if (input == CountryCodeAR) output = web::json::value(L"AR");
            if (input == CountryCodeAM) output = web::json::value(L"AM");
            if (input == CountryCodeAW) output = web::json::value(L"AW");
            if (input == CountryCodeAU) output = web::json::value(L"AU");
            if (input == CountryCodeAT) output = web::json::value(L"AT");
            if (input == CountryCodeAZ) output = web::json::value(L"AZ");
            if (input == CountryCodeBS) output = web::json::value(L"BS");
            if (input == CountryCodeBH) output = web::json::value(L"BH");
            if (input == CountryCodeBD) output = web::json::value(L"BD");
            if (input == CountryCodeBB) output = web::json::value(L"BB");
            if (input == CountryCodeBY) output = web::json::value(L"BY");
            if (input == CountryCodeBE) output = web::json::value(L"BE");
            if (input == CountryCodeBZ) output = web::json::value(L"BZ");
            if (input == CountryCodeBJ) output = web::json::value(L"BJ");
            if (input == CountryCodeBM) output = web::json::value(L"BM");
            if (input == CountryCodeBT) output = web::json::value(L"BT");
            if (input == CountryCodeBO) output = web::json::value(L"BO");
            if (input == CountryCodeBQ) output = web::json::value(L"BQ");
            if (input == CountryCodeBA) output = web::json::value(L"BA");
            if (input == CountryCodeBW) output = web::json::value(L"BW");
            if (input == CountryCodeBV) output = web::json::value(L"BV");
            if (input == CountryCodeBR) output = web::json::value(L"BR");
            if (input == CountryCodeIO) output = web::json::value(L"IO");
            if (input == CountryCodeBN) output = web::json::value(L"BN");
            if (input == CountryCodeBG) output = web::json::value(L"BG");
            if (input == CountryCodeBF) output = web::json::value(L"BF");
            if (input == CountryCodeBI) output = web::json::value(L"BI");
            if (input == CountryCodeKH) output = web::json::value(L"KH");
            if (input == CountryCodeCM) output = web::json::value(L"CM");
            if (input == CountryCodeCA) output = web::json::value(L"CA");
            if (input == CountryCodeCV) output = web::json::value(L"CV");
            if (input == CountryCodeKY) output = web::json::value(L"KY");
            if (input == CountryCodeCF) output = web::json::value(L"CF");
            if (input == CountryCodeTD) output = web::json::value(L"TD");
            if (input == CountryCodeCL) output = web::json::value(L"CL");
            if (input == CountryCodeCN) output = web::json::value(L"CN");
            if (input == CountryCodeCX) output = web::json::value(L"CX");
            if (input == CountryCodeCC) output = web::json::value(L"CC");
            if (input == CountryCodeCO) output = web::json::value(L"CO");
            if (input == CountryCodeKM) output = web::json::value(L"KM");
            if (input == CountryCodeCG) output = web::json::value(L"CG");
            if (input == CountryCodeCD) output = web::json::value(L"CD");
            if (input == CountryCodeCK) output = web::json::value(L"CK");
            if (input == CountryCodeCR) output = web::json::value(L"CR");
            if (input == CountryCodeCI) output = web::json::value(L"CI");
            if (input == CountryCodeHR) output = web::json::value(L"HR");
            if (input == CountryCodeCU) output = web::json::value(L"CU");
            if (input == CountryCodeCW) output = web::json::value(L"CW");
            if (input == CountryCodeCY) output = web::json::value(L"CY");
            if (input == CountryCodeCZ) output = web::json::value(L"CZ");
            if (input == CountryCodeDK) output = web::json::value(L"DK");
            if (input == CountryCodeDJ) output = web::json::value(L"DJ");
            if (input == CountryCodeDM) output = web::json::value(L"DM");
            if (input == CountryCodeDO) output = web::json::value(L"DO");
            if (input == CountryCodeEC) output = web::json::value(L"EC");
            if (input == CountryCodeEG) output = web::json::value(L"EG");
            if (input == CountryCodeSV) output = web::json::value(L"SV");
            if (input == CountryCodeGQ) output = web::json::value(L"GQ");
            if (input == CountryCodeER) output = web::json::value(L"ER");
            if (input == CountryCodeEE) output = web::json::value(L"EE");
            if (input == CountryCodeET) output = web::json::value(L"ET");
            if (input == CountryCodeFK) output = web::json::value(L"FK");
            if (input == CountryCodeFO) output = web::json::value(L"FO");
            if (input == CountryCodeFJ) output = web::json::value(L"FJ");
            if (input == CountryCodeFI) output = web::json::value(L"FI");
            if (input == CountryCodeFR) output = web::json::value(L"FR");
            if (input == CountryCodeGF) output = web::json::value(L"GF");
            if (input == CountryCodePF) output = web::json::value(L"PF");
            if (input == CountryCodeTF) output = web::json::value(L"TF");
            if (input == CountryCodeGA) output = web::json::value(L"GA");
            if (input == CountryCodeGM) output = web::json::value(L"GM");
            if (input == CountryCodeGE) output = web::json::value(L"GE");
            if (input == CountryCodeDE) output = web::json::value(L"DE");
            if (input == CountryCodeGH) output = web::json::value(L"GH");
            if (input == CountryCodeGI) output = web::json::value(L"GI");
            if (input == CountryCodeGR) output = web::json::value(L"GR");
            if (input == CountryCodeGL) output = web::json::value(L"GL");
            if (input == CountryCodeGD) output = web::json::value(L"GD");
            if (input == CountryCodeGP) output = web::json::value(L"GP");
            if (input == CountryCodeGU) output = web::json::value(L"GU");
            if (input == CountryCodeGT) output = web::json::value(L"GT");
            if (input == CountryCodeGG) output = web::json::value(L"GG");
            if (input == CountryCodeGN) output = web::json::value(L"GN");
            if (input == CountryCodeGW) output = web::json::value(L"GW");
            if (input == CountryCodeGY) output = web::json::value(L"GY");
            if (input == CountryCodeHT) output = web::json::value(L"HT");
            if (input == CountryCodeHM) output = web::json::value(L"HM");
            if (input == CountryCodeVA) output = web::json::value(L"VA");
            if (input == CountryCodeHN) output = web::json::value(L"HN");
            if (input == CountryCodeHK) output = web::json::value(L"HK");
            if (input == CountryCodeHU) output = web::json::value(L"HU");
            if (input == CountryCodeIS) output = web::json::value(L"IS");
            if (input == CountryCodeIN) output = web::json::value(L"IN");
            if (input == CountryCodeID) output = web::json::value(L"ID");
            if (input == CountryCodeIR) output = web::json::value(L"IR");
            if (input == CountryCodeIQ) output = web::json::value(L"IQ");
            if (input == CountryCodeIE) output = web::json::value(L"IE");
            if (input == CountryCodeIM) output = web::json::value(L"IM");
            if (input == CountryCodeIL) output = web::json::value(L"IL");
            if (input == CountryCodeIT) output = web::json::value(L"IT");
            if (input == CountryCodeJM) output = web::json::value(L"JM");
            if (input == CountryCodeJP) output = web::json::value(L"JP");
            if (input == CountryCodeJE) output = web::json::value(L"JE");
            if (input == CountryCodeJO) output = web::json::value(L"JO");
            if (input == CountryCodeKZ) output = web::json::value(L"KZ");
            if (input == CountryCodeKE) output = web::json::value(L"KE");
            if (input == CountryCodeKI) output = web::json::value(L"KI");
            if (input == CountryCodeKP) output = web::json::value(L"KP");
            if (input == CountryCodeKR) output = web::json::value(L"KR");
            if (input == CountryCodeKW) output = web::json::value(L"KW");
            if (input == CountryCodeKG) output = web::json::value(L"KG");
            if (input == CountryCodeLA) output = web::json::value(L"LA");
            if (input == CountryCodeLV) output = web::json::value(L"LV");
            if (input == CountryCodeLB) output = web::json::value(L"LB");
            if (input == CountryCodeLS) output = web::json::value(L"LS");
            if (input == CountryCodeLR) output = web::json::value(L"LR");
            if (input == CountryCodeLY) output = web::json::value(L"LY");
            if (input == CountryCodeLI) output = web::json::value(L"LI");
            if (input == CountryCodeLT) output = web::json::value(L"LT");
            if (input == CountryCodeLU) output = web::json::value(L"LU");
            if (input == CountryCodeMO) output = web::json::value(L"MO");
            if (input == CountryCodeMK) output = web::json::value(L"MK");
            if (input == CountryCodeMG) output = web::json::value(L"MG");
            if (input == CountryCodeMW) output = web::json::value(L"MW");
            if (input == CountryCodeMY) output = web::json::value(L"MY");
            if (input == CountryCodeMV) output = web::json::value(L"MV");
            if (input == CountryCodeML) output = web::json::value(L"ML");
            if (input == CountryCodeMT) output = web::json::value(L"MT");
            if (input == CountryCodeMH) output = web::json::value(L"MH");
            if (input == CountryCodeMQ) output = web::json::value(L"MQ");
            if (input == CountryCodeMR) output = web::json::value(L"MR");
            if (input == CountryCodeMU) output = web::json::value(L"MU");
            if (input == CountryCodeYT) output = web::json::value(L"YT");
            if (input == CountryCodeMX) output = web::json::value(L"MX");
            if (input == CountryCodeFM) output = web::json::value(L"FM");
            if (input == CountryCodeMD) output = web::json::value(L"MD");
            if (input == CountryCodeMC) output = web::json::value(L"MC");
            if (input == CountryCodeMN) output = web::json::value(L"MN");
            if (input == CountryCodeME) output = web::json::value(L"ME");
            if (input == CountryCodeMS) output = web::json::value(L"MS");
            if (input == CountryCodeMA) output = web::json::value(L"MA");
            if (input == CountryCodeMZ) output = web::json::value(L"MZ");
            if (input == CountryCodeMM) output = web::json::value(L"MM");
            if (input == CountryCodeNA) output = web::json::value(L"NA");
            if (input == CountryCodeNR) output = web::json::value(L"NR");
            if (input == CountryCodeNP) output = web::json::value(L"NP");
            if (input == CountryCodeNL) output = web::json::value(L"NL");
            if (input == CountryCodeNC) output = web::json::value(L"NC");
            if (input == CountryCodeNZ) output = web::json::value(L"NZ");
            if (input == CountryCodeNI) output = web::json::value(L"NI");
            if (input == CountryCodeNE) output = web::json::value(L"NE");
            if (input == CountryCodeNG) output = web::json::value(L"NG");
            if (input == CountryCodeNU) output = web::json::value(L"NU");
            if (input == CountryCodeNF) output = web::json::value(L"NF");
            if (input == CountryCodeMP) output = web::json::value(L"MP");
            if (input == CountryCodeNO) output = web::json::value(L"NO");
            if (input == CountryCodeOM) output = web::json::value(L"OM");
            if (input == CountryCodePK) output = web::json::value(L"PK");
            if (input == CountryCodePW) output = web::json::value(L"PW");
            if (input == CountryCodePS) output = web::json::value(L"PS");
            if (input == CountryCodePA) output = web::json::value(L"PA");
            if (input == CountryCodePG) output = web::json::value(L"PG");
            if (input == CountryCodePY) output = web::json::value(L"PY");
            if (input == CountryCodePE) output = web::json::value(L"PE");
            if (input == CountryCodePH) output = web::json::value(L"PH");
            if (input == CountryCodePN) output = web::json::value(L"PN");
            if (input == CountryCodePL) output = web::json::value(L"PL");
            if (input == CountryCodePT) output = web::json::value(L"PT");
            if (input == CountryCodePR) output = web::json::value(L"PR");
            if (input == CountryCodeQA) output = web::json::value(L"QA");
            if (input == CountryCodeRE) output = web::json::value(L"RE");
            if (input == CountryCodeRO) output = web::json::value(L"RO");
            if (input == CountryCodeRU) output = web::json::value(L"RU");
            if (input == CountryCodeRW) output = web::json::value(L"RW");
            if (input == CountryCodeBL) output = web::json::value(L"BL");
            if (input == CountryCodeSH) output = web::json::value(L"SH");
            if (input == CountryCodeKN) output = web::json::value(L"KN");
            if (input == CountryCodeLC) output = web::json::value(L"LC");
            if (input == CountryCodeMF) output = web::json::value(L"MF");
            if (input == CountryCodePM) output = web::json::value(L"PM");
            if (input == CountryCodeVC) output = web::json::value(L"VC");
            if (input == CountryCodeWS) output = web::json::value(L"WS");
            if (input == CountryCodeSM) output = web::json::value(L"SM");
            if (input == CountryCodeST) output = web::json::value(L"ST");
            if (input == CountryCodeSA) output = web::json::value(L"SA");
            if (input == CountryCodeSN) output = web::json::value(L"SN");
            if (input == CountryCodeRS) output = web::json::value(L"RS");
            if (input == CountryCodeSC) output = web::json::value(L"SC");
            if (input == CountryCodeSL) output = web::json::value(L"SL");
            if (input == CountryCodeSG) output = web::json::value(L"SG");
            if (input == CountryCodeSX) output = web::json::value(L"SX");
            if (input == CountryCodeSK) output = web::json::value(L"SK");
            if (input == CountryCodeSI) output = web::json::value(L"SI");
            if (input == CountryCodeSB) output = web::json::value(L"SB");
            if (input == CountryCodeSO) output = web::json::value(L"SO");
            if (input == CountryCodeZA) output = web::json::value(L"ZA");
            if (input == CountryCodeGS) output = web::json::value(L"GS");
            if (input == CountryCodeSS) output = web::json::value(L"SS");
            if (input == CountryCodeES) output = web::json::value(L"ES");
            if (input == CountryCodeLK) output = web::json::value(L"LK");
            if (input == CountryCodeSD) output = web::json::value(L"SD");
            if (input == CountryCodeSR) output = web::json::value(L"SR");
            if (input == CountryCodeSJ) output = web::json::value(L"SJ");
            if (input == CountryCodeSZ) output = web::json::value(L"SZ");
            if (input == CountryCodeSE) output = web::json::value(L"SE");
            if (input == CountryCodeCH) output = web::json::value(L"CH");
            if (input == CountryCodeSY) output = web::json::value(L"SY");
            if (input == CountryCodeTW) output = web::json::value(L"TW");
            if (input == CountryCodeTJ) output = web::json::value(L"TJ");
            if (input == CountryCodeTZ) output = web::json::value(L"TZ");
            if (input == CountryCodeTH) output = web::json::value(L"TH");
            if (input == CountryCodeTL) output = web::json::value(L"TL");
            if (input == CountryCodeTG) output = web::json::value(L"TG");
            if (input == CountryCodeTK) output = web::json::value(L"TK");
            if (input == CountryCodeTO) output = web::json::value(L"TO");
            if (input == CountryCodeTT) output = web::json::value(L"TT");
            if (input == CountryCodeTN) output = web::json::value(L"TN");
            if (input == CountryCodeTR) output = web::json::value(L"TR");
            if (input == CountryCodeTM) output = web::json::value(L"TM");
            if (input == CountryCodeTC) output = web::json::value(L"TC");
            if (input == CountryCodeTV) output = web::json::value(L"TV");
            if (input == CountryCodeUG) output = web::json::value(L"UG");
            if (input == CountryCodeUA) output = web::json::value(L"UA");
            if (input == CountryCodeAE) output = web::json::value(L"AE");
            if (input == CountryCodeGB) output = web::json::value(L"GB");
            if (input == CountryCodeUS) output = web::json::value(L"US");
            if (input == CountryCodeUM) output = web::json::value(L"UM");
            if (input == CountryCodeUY) output = web::json::value(L"UY");
            if (input == CountryCodeUZ) output = web::json::value(L"UZ");
            if (input == CountryCodeVU) output = web::json::value(L"VU");
            if (input == CountryCodeVE) output = web::json::value(L"VE");
            if (input == CountryCodeVN) output = web::json::value(L"VN");
            if (input == CountryCodeVG) output = web::json::value(L"VG");
            if (input == CountryCodeVI) output = web::json::value(L"VI");
            if (input == CountryCodeWF) output = web::json::value(L"WF");
            if (input == CountryCodeEH) output = web::json::value(L"EH");
            if (input == CountryCodeYE) output = web::json::value(L"YE");
            if (input == CountryCodeZM) output = web::json::value(L"ZM");
            if (input == CountryCodeZW) output = web::json::value(L"ZW");
        }
        inline void FromJsonEnum(const web::json::value& input, CountryCode& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"AF") output = CountryCodeAF;
            if (inputStr == L"AX") output = CountryCodeAX;
            if (inputStr == L"AL") output = CountryCodeAL;
            if (inputStr == L"DZ") output = CountryCodeDZ;
            if (inputStr == L"AS") output = CountryCodeAS;
            if (inputStr == L"AD") output = CountryCodeAD;
            if (inputStr == L"AO") output = CountryCodeAO;
            if (inputStr == L"AI") output = CountryCodeAI;
            if (inputStr == L"AQ") output = CountryCodeAQ;
            if (inputStr == L"AG") output = CountryCodeAG;
            if (inputStr == L"AR") output = CountryCodeAR;
            if (inputStr == L"AM") output = CountryCodeAM;
            if (inputStr == L"AW") output = CountryCodeAW;
            if (inputStr == L"AU") output = CountryCodeAU;
            if (inputStr == L"AT") output = CountryCodeAT;
            if (inputStr == L"AZ") output = CountryCodeAZ;
            if (inputStr == L"BS") output = CountryCodeBS;
            if (inputStr == L"BH") output = CountryCodeBH;
            if (inputStr == L"BD") output = CountryCodeBD;
            if (inputStr == L"BB") output = CountryCodeBB;
            if (inputStr == L"BY") output = CountryCodeBY;
            if (inputStr == L"BE") output = CountryCodeBE;
            if (inputStr == L"BZ") output = CountryCodeBZ;
            if (inputStr == L"BJ") output = CountryCodeBJ;
            if (inputStr == L"BM") output = CountryCodeBM;
            if (inputStr == L"BT") output = CountryCodeBT;
            if (inputStr == L"BO") output = CountryCodeBO;
            if (inputStr == L"BQ") output = CountryCodeBQ;
            if (inputStr == L"BA") output = CountryCodeBA;
            if (inputStr == L"BW") output = CountryCodeBW;
            if (inputStr == L"BV") output = CountryCodeBV;
            if (inputStr == L"BR") output = CountryCodeBR;
            if (inputStr == L"IO") output = CountryCodeIO;
            if (inputStr == L"BN") output = CountryCodeBN;
            if (inputStr == L"BG") output = CountryCodeBG;
            if (inputStr == L"BF") output = CountryCodeBF;
            if (inputStr == L"BI") output = CountryCodeBI;
            if (inputStr == L"KH") output = CountryCodeKH;
            if (inputStr == L"CM") output = CountryCodeCM;
            if (inputStr == L"CA") output = CountryCodeCA;
            if (inputStr == L"CV") output = CountryCodeCV;
            if (inputStr == L"KY") output = CountryCodeKY;
            if (inputStr == L"CF") output = CountryCodeCF;
            if (inputStr == L"TD") output = CountryCodeTD;
            if (inputStr == L"CL") output = CountryCodeCL;
            if (inputStr == L"CN") output = CountryCodeCN;
            if (inputStr == L"CX") output = CountryCodeCX;
            if (inputStr == L"CC") output = CountryCodeCC;
            if (inputStr == L"CO") output = CountryCodeCO;
            if (inputStr == L"KM") output = CountryCodeKM;
            if (inputStr == L"CG") output = CountryCodeCG;
            if (inputStr == L"CD") output = CountryCodeCD;
            if (inputStr == L"CK") output = CountryCodeCK;
            if (inputStr == L"CR") output = CountryCodeCR;
            if (inputStr == L"CI") output = CountryCodeCI;
            if (inputStr == L"HR") output = CountryCodeHR;
            if (inputStr == L"CU") output = CountryCodeCU;
            if (inputStr == L"CW") output = CountryCodeCW;
            if (inputStr == L"CY") output = CountryCodeCY;
            if (inputStr == L"CZ") output = CountryCodeCZ;
            if (inputStr == L"DK") output = CountryCodeDK;
            if (inputStr == L"DJ") output = CountryCodeDJ;
            if (inputStr == L"DM") output = CountryCodeDM;
            if (inputStr == L"DO") output = CountryCodeDO;
            if (inputStr == L"EC") output = CountryCodeEC;
            if (inputStr == L"EG") output = CountryCodeEG;
            if (inputStr == L"SV") output = CountryCodeSV;
            if (inputStr == L"GQ") output = CountryCodeGQ;
            if (inputStr == L"ER") output = CountryCodeER;
            if (inputStr == L"EE") output = CountryCodeEE;
            if (inputStr == L"ET") output = CountryCodeET;
            if (inputStr == L"FK") output = CountryCodeFK;
            if (inputStr == L"FO") output = CountryCodeFO;
            if (inputStr == L"FJ") output = CountryCodeFJ;
            if (inputStr == L"FI") output = CountryCodeFI;
            if (inputStr == L"FR") output = CountryCodeFR;
            if (inputStr == L"GF") output = CountryCodeGF;
            if (inputStr == L"PF") output = CountryCodePF;
            if (inputStr == L"TF") output = CountryCodeTF;
            if (inputStr == L"GA") output = CountryCodeGA;
            if (inputStr == L"GM") output = CountryCodeGM;
            if (inputStr == L"GE") output = CountryCodeGE;
            if (inputStr == L"DE") output = CountryCodeDE;
            if (inputStr == L"GH") output = CountryCodeGH;
            if (inputStr == L"GI") output = CountryCodeGI;
            if (inputStr == L"GR") output = CountryCodeGR;
            if (inputStr == L"GL") output = CountryCodeGL;
            if (inputStr == L"GD") output = CountryCodeGD;
            if (inputStr == L"GP") output = CountryCodeGP;
            if (inputStr == L"GU") output = CountryCodeGU;
            if (inputStr == L"GT") output = CountryCodeGT;
            if (inputStr == L"GG") output = CountryCodeGG;
            if (inputStr == L"GN") output = CountryCodeGN;
            if (inputStr == L"GW") output = CountryCodeGW;
            if (inputStr == L"GY") output = CountryCodeGY;
            if (inputStr == L"HT") output = CountryCodeHT;
            if (inputStr == L"HM") output = CountryCodeHM;
            if (inputStr == L"VA") output = CountryCodeVA;
            if (inputStr == L"HN") output = CountryCodeHN;
            if (inputStr == L"HK") output = CountryCodeHK;
            if (inputStr == L"HU") output = CountryCodeHU;
            if (inputStr == L"IS") output = CountryCodeIS;
            if (inputStr == L"IN") output = CountryCodeIN;
            if (inputStr == L"ID") output = CountryCodeID;
            if (inputStr == L"IR") output = CountryCodeIR;
            if (inputStr == L"IQ") output = CountryCodeIQ;
            if (inputStr == L"IE") output = CountryCodeIE;
            if (inputStr == L"IM") output = CountryCodeIM;
            if (inputStr == L"IL") output = CountryCodeIL;
            if (inputStr == L"IT") output = CountryCodeIT;
            if (inputStr == L"JM") output = CountryCodeJM;
            if (inputStr == L"JP") output = CountryCodeJP;
            if (inputStr == L"JE") output = CountryCodeJE;
            if (inputStr == L"JO") output = CountryCodeJO;
            if (inputStr == L"KZ") output = CountryCodeKZ;
            if (inputStr == L"KE") output = CountryCodeKE;
            if (inputStr == L"KI") output = CountryCodeKI;
            if (inputStr == L"KP") output = CountryCodeKP;
            if (inputStr == L"KR") output = CountryCodeKR;
            if (inputStr == L"KW") output = CountryCodeKW;
            if (inputStr == L"KG") output = CountryCodeKG;
            if (inputStr == L"LA") output = CountryCodeLA;
            if (inputStr == L"LV") output = CountryCodeLV;
            if (inputStr == L"LB") output = CountryCodeLB;
            if (inputStr == L"LS") output = CountryCodeLS;
            if (inputStr == L"LR") output = CountryCodeLR;
            if (inputStr == L"LY") output = CountryCodeLY;
            if (inputStr == L"LI") output = CountryCodeLI;
            if (inputStr == L"LT") output = CountryCodeLT;
            if (inputStr == L"LU") output = CountryCodeLU;
            if (inputStr == L"MO") output = CountryCodeMO;
            if (inputStr == L"MK") output = CountryCodeMK;
            if (inputStr == L"MG") output = CountryCodeMG;
            if (inputStr == L"MW") output = CountryCodeMW;
            if (inputStr == L"MY") output = CountryCodeMY;
            if (inputStr == L"MV") output = CountryCodeMV;
            if (inputStr == L"ML") output = CountryCodeML;
            if (inputStr == L"MT") output = CountryCodeMT;
            if (inputStr == L"MH") output = CountryCodeMH;
            if (inputStr == L"MQ") output = CountryCodeMQ;
            if (inputStr == L"MR") output = CountryCodeMR;
            if (inputStr == L"MU") output = CountryCodeMU;
            if (inputStr == L"YT") output = CountryCodeYT;
            if (inputStr == L"MX") output = CountryCodeMX;
            if (inputStr == L"FM") output = CountryCodeFM;
            if (inputStr == L"MD") output = CountryCodeMD;
            if (inputStr == L"MC") output = CountryCodeMC;
            if (inputStr == L"MN") output = CountryCodeMN;
            if (inputStr == L"ME") output = CountryCodeME;
            if (inputStr == L"MS") output = CountryCodeMS;
            if (inputStr == L"MA") output = CountryCodeMA;
            if (inputStr == L"MZ") output = CountryCodeMZ;
            if (inputStr == L"MM") output = CountryCodeMM;
            if (inputStr == L"NA") output = CountryCodeNA;
            if (inputStr == L"NR") output = CountryCodeNR;
            if (inputStr == L"NP") output = CountryCodeNP;
            if (inputStr == L"NL") output = CountryCodeNL;
            if (inputStr == L"NC") output = CountryCodeNC;
            if (inputStr == L"NZ") output = CountryCodeNZ;
            if (inputStr == L"NI") output = CountryCodeNI;
            if (inputStr == L"NE") output = CountryCodeNE;
            if (inputStr == L"NG") output = CountryCodeNG;
            if (inputStr == L"NU") output = CountryCodeNU;
            if (inputStr == L"NF") output = CountryCodeNF;
            if (inputStr == L"MP") output = CountryCodeMP;
            if (inputStr == L"NO") output = CountryCodeNO;
            if (inputStr == L"OM") output = CountryCodeOM;
            if (inputStr == L"PK") output = CountryCodePK;
            if (inputStr == L"PW") output = CountryCodePW;
            if (inputStr == L"PS") output = CountryCodePS;
            if (inputStr == L"PA") output = CountryCodePA;
            if (inputStr == L"PG") output = CountryCodePG;
            if (inputStr == L"PY") output = CountryCodePY;
            if (inputStr == L"PE") output = CountryCodePE;
            if (inputStr == L"PH") output = CountryCodePH;
            if (inputStr == L"PN") output = CountryCodePN;
            if (inputStr == L"PL") output = CountryCodePL;
            if (inputStr == L"PT") output = CountryCodePT;
            if (inputStr == L"PR") output = CountryCodePR;
            if (inputStr == L"QA") output = CountryCodeQA;
            if (inputStr == L"RE") output = CountryCodeRE;
            if (inputStr == L"RO") output = CountryCodeRO;
            if (inputStr == L"RU") output = CountryCodeRU;
            if (inputStr == L"RW") output = CountryCodeRW;
            if (inputStr == L"BL") output = CountryCodeBL;
            if (inputStr == L"SH") output = CountryCodeSH;
            if (inputStr == L"KN") output = CountryCodeKN;
            if (inputStr == L"LC") output = CountryCodeLC;
            if (inputStr == L"MF") output = CountryCodeMF;
            if (inputStr == L"PM") output = CountryCodePM;
            if (inputStr == L"VC") output = CountryCodeVC;
            if (inputStr == L"WS") output = CountryCodeWS;
            if (inputStr == L"SM") output = CountryCodeSM;
            if (inputStr == L"ST") output = CountryCodeST;
            if (inputStr == L"SA") output = CountryCodeSA;
            if (inputStr == L"SN") output = CountryCodeSN;
            if (inputStr == L"RS") output = CountryCodeRS;
            if (inputStr == L"SC") output = CountryCodeSC;
            if (inputStr == L"SL") output = CountryCodeSL;
            if (inputStr == L"SG") output = CountryCodeSG;
            if (inputStr == L"SX") output = CountryCodeSX;
            if (inputStr == L"SK") output = CountryCodeSK;
            if (inputStr == L"SI") output = CountryCodeSI;
            if (inputStr == L"SB") output = CountryCodeSB;
            if (inputStr == L"SO") output = CountryCodeSO;
            if (inputStr == L"ZA") output = CountryCodeZA;
            if (inputStr == L"GS") output = CountryCodeGS;
            if (inputStr == L"SS") output = CountryCodeSS;
            if (inputStr == L"ES") output = CountryCodeES;
            if (inputStr == L"LK") output = CountryCodeLK;
            if (inputStr == L"SD") output = CountryCodeSD;
            if (inputStr == L"SR") output = CountryCodeSR;
            if (inputStr == L"SJ") output = CountryCodeSJ;
            if (inputStr == L"SZ") output = CountryCodeSZ;
            if (inputStr == L"SE") output = CountryCodeSE;
            if (inputStr == L"CH") output = CountryCodeCH;
            if (inputStr == L"SY") output = CountryCodeSY;
            if (inputStr == L"TW") output = CountryCodeTW;
            if (inputStr == L"TJ") output = CountryCodeTJ;
            if (inputStr == L"TZ") output = CountryCodeTZ;
            if (inputStr == L"TH") output = CountryCodeTH;
            if (inputStr == L"TL") output = CountryCodeTL;
            if (inputStr == L"TG") output = CountryCodeTG;
            if (inputStr == L"TK") output = CountryCodeTK;
            if (inputStr == L"TO") output = CountryCodeTO;
            if (inputStr == L"TT") output = CountryCodeTT;
            if (inputStr == L"TN") output = CountryCodeTN;
            if (inputStr == L"TR") output = CountryCodeTR;
            if (inputStr == L"TM") output = CountryCodeTM;
            if (inputStr == L"TC") output = CountryCodeTC;
            if (inputStr == L"TV") output = CountryCodeTV;
            if (inputStr == L"UG") output = CountryCodeUG;
            if (inputStr == L"UA") output = CountryCodeUA;
            if (inputStr == L"AE") output = CountryCodeAE;
            if (inputStr == L"GB") output = CountryCodeGB;
            if (inputStr == L"US") output = CountryCodeUS;
            if (inputStr == L"UM") output = CountryCodeUM;
            if (inputStr == L"UY") output = CountryCodeUY;
            if (inputStr == L"UZ") output = CountryCodeUZ;
            if (inputStr == L"VU") output = CountryCodeVU;
            if (inputStr == L"VE") output = CountryCodeVE;
            if (inputStr == L"VN") output = CountryCodeVN;
            if (inputStr == L"VG") output = CountryCodeVG;
            if (inputStr == L"VI") output = CountryCodeVI;
            if (inputStr == L"WF") output = CountryCodeWF;
            if (inputStr == L"EH") output = CountryCodeEH;
            if (inputStr == L"YE") output = CountryCodeYE;
            if (inputStr == L"ZM") output = CountryCodeZM;
            if (inputStr == L"ZW") output = CountryCodeZW;
        }

        enum Currency
        {
            CurrencyAED,
            CurrencyAFN,
            CurrencyALL,
            CurrencyAMD,
            CurrencyANG,
            CurrencyAOA,
            CurrencyARS,
            CurrencyAUD,
            CurrencyAWG,
            CurrencyAZN,
            CurrencyBAM,
            CurrencyBBD,
            CurrencyBDT,
            CurrencyBGN,
            CurrencyBHD,
            CurrencyBIF,
            CurrencyBMD,
            CurrencyBND,
            CurrencyBOB,
            CurrencyBRL,
            CurrencyBSD,
            CurrencyBTN,
            CurrencyBWP,
            CurrencyBYR,
            CurrencyBZD,
            CurrencyCAD,
            CurrencyCDF,
            CurrencyCHF,
            CurrencyCLP,
            CurrencyCNY,
            CurrencyCOP,
            CurrencyCRC,
            CurrencyCUC,
            CurrencyCUP,
            CurrencyCVE,
            CurrencyCZK,
            CurrencyDJF,
            CurrencyDKK,
            CurrencyDOP,
            CurrencyDZD,
            CurrencyEGP,
            CurrencyERN,
            CurrencyETB,
            CurrencyEUR,
            CurrencyFJD,
            CurrencyFKP,
            CurrencyGBP,
            CurrencyGEL,
            CurrencyGGP,
            CurrencyGHS,
            CurrencyGIP,
            CurrencyGMD,
            CurrencyGNF,
            CurrencyGTQ,
            CurrencyGYD,
            CurrencyHKD,
            CurrencyHNL,
            CurrencyHRK,
            CurrencyHTG,
            CurrencyHUF,
            CurrencyIDR,
            CurrencyILS,
            CurrencyIMP,
            CurrencyINR,
            CurrencyIQD,
            CurrencyIRR,
            CurrencyISK,
            CurrencyJEP,
            CurrencyJMD,
            CurrencyJOD,
            CurrencyJPY,
            CurrencyKES,
            CurrencyKGS,
            CurrencyKHR,
            CurrencyKMF,
            CurrencyKPW,
            CurrencyKRW,
            CurrencyKWD,
            CurrencyKYD,
            CurrencyKZT,
            CurrencyLAK,
            CurrencyLBP,
            CurrencyLKR,
            CurrencyLRD,
            CurrencyLSL,
            CurrencyLYD,
            CurrencyMAD,
            CurrencyMDL,
            CurrencyMGA,
            CurrencyMKD,
            CurrencyMMK,
            CurrencyMNT,
            CurrencyMOP,
            CurrencyMRO,
            CurrencyMUR,
            CurrencyMVR,
            CurrencyMWK,
            CurrencyMXN,
            CurrencyMYR,
            CurrencyMZN,
            CurrencyNAD,
            CurrencyNGN,
            CurrencyNIO,
            CurrencyNOK,
            CurrencyNPR,
            CurrencyNZD,
            CurrencyOMR,
            CurrencyPAB,
            CurrencyPEN,
            CurrencyPGK,
            CurrencyPHP,
            CurrencyPKR,
            CurrencyPLN,
            CurrencyPYG,
            CurrencyQAR,
            CurrencyRON,
            CurrencyRSD,
            CurrencyRUB,
            CurrencyRWF,
            CurrencySAR,
            CurrencySBD,
            CurrencySCR,
            CurrencySDG,
            CurrencySEK,
            CurrencySGD,
            CurrencySHP,
            CurrencySLL,
            CurrencySOS,
            CurrencySPL,
            CurrencySRD,
            CurrencySTD,
            CurrencySVC,
            CurrencySYP,
            CurrencySZL,
            CurrencyTHB,
            CurrencyTJS,
            CurrencyTMT,
            CurrencyTND,
            CurrencyTOP,
            CurrencyTRY,
            CurrencyTTD,
            CurrencyTVD,
            CurrencyTWD,
            CurrencyTZS,
            CurrencyUAH,
            CurrencyUGX,
            CurrencyUSD,
            CurrencyUYU,
            CurrencyUZS,
            CurrencyVEF,
            CurrencyVND,
            CurrencyVUV,
            CurrencyWST,
            CurrencyXAF,
            CurrencyXCD,
            CurrencyXDR,
            CurrencyXOF,
            CurrencyXPF,
            CurrencyYER,
            CurrencyZAR,
            CurrencyZMW,
            CurrencyZWD
        };

        inline void ToJsonEnum(const Currency input, web::json::value& output)
        {
            if (input == CurrencyAED) output = web::json::value(L"AED");
            if (input == CurrencyAFN) output = web::json::value(L"AFN");
            if (input == CurrencyALL) output = web::json::value(L"ALL");
            if (input == CurrencyAMD) output = web::json::value(L"AMD");
            if (input == CurrencyANG) output = web::json::value(L"ANG");
            if (input == CurrencyAOA) output = web::json::value(L"AOA");
            if (input == CurrencyARS) output = web::json::value(L"ARS");
            if (input == CurrencyAUD) output = web::json::value(L"AUD");
            if (input == CurrencyAWG) output = web::json::value(L"AWG");
            if (input == CurrencyAZN) output = web::json::value(L"AZN");
            if (input == CurrencyBAM) output = web::json::value(L"BAM");
            if (input == CurrencyBBD) output = web::json::value(L"BBD");
            if (input == CurrencyBDT) output = web::json::value(L"BDT");
            if (input == CurrencyBGN) output = web::json::value(L"BGN");
            if (input == CurrencyBHD) output = web::json::value(L"BHD");
            if (input == CurrencyBIF) output = web::json::value(L"BIF");
            if (input == CurrencyBMD) output = web::json::value(L"BMD");
            if (input == CurrencyBND) output = web::json::value(L"BND");
            if (input == CurrencyBOB) output = web::json::value(L"BOB");
            if (input == CurrencyBRL) output = web::json::value(L"BRL");
            if (input == CurrencyBSD) output = web::json::value(L"BSD");
            if (input == CurrencyBTN) output = web::json::value(L"BTN");
            if (input == CurrencyBWP) output = web::json::value(L"BWP");
            if (input == CurrencyBYR) output = web::json::value(L"BYR");
            if (input == CurrencyBZD) output = web::json::value(L"BZD");
            if (input == CurrencyCAD) output = web::json::value(L"CAD");
            if (input == CurrencyCDF) output = web::json::value(L"CDF");
            if (input == CurrencyCHF) output = web::json::value(L"CHF");
            if (input == CurrencyCLP) output = web::json::value(L"CLP");
            if (input == CurrencyCNY) output = web::json::value(L"CNY");
            if (input == CurrencyCOP) output = web::json::value(L"COP");
            if (input == CurrencyCRC) output = web::json::value(L"CRC");
            if (input == CurrencyCUC) output = web::json::value(L"CUC");
            if (input == CurrencyCUP) output = web::json::value(L"CUP");
            if (input == CurrencyCVE) output = web::json::value(L"CVE");
            if (input == CurrencyCZK) output = web::json::value(L"CZK");
            if (input == CurrencyDJF) output = web::json::value(L"DJF");
            if (input == CurrencyDKK) output = web::json::value(L"DKK");
            if (input == CurrencyDOP) output = web::json::value(L"DOP");
            if (input == CurrencyDZD) output = web::json::value(L"DZD");
            if (input == CurrencyEGP) output = web::json::value(L"EGP");
            if (input == CurrencyERN) output = web::json::value(L"ERN");
            if (input == CurrencyETB) output = web::json::value(L"ETB");
            if (input == CurrencyEUR) output = web::json::value(L"EUR");
            if (input == CurrencyFJD) output = web::json::value(L"FJD");
            if (input == CurrencyFKP) output = web::json::value(L"FKP");
            if (input == CurrencyGBP) output = web::json::value(L"GBP");
            if (input == CurrencyGEL) output = web::json::value(L"GEL");
            if (input == CurrencyGGP) output = web::json::value(L"GGP");
            if (input == CurrencyGHS) output = web::json::value(L"GHS");
            if (input == CurrencyGIP) output = web::json::value(L"GIP");
            if (input == CurrencyGMD) output = web::json::value(L"GMD");
            if (input == CurrencyGNF) output = web::json::value(L"GNF");
            if (input == CurrencyGTQ) output = web::json::value(L"GTQ");
            if (input == CurrencyGYD) output = web::json::value(L"GYD");
            if (input == CurrencyHKD) output = web::json::value(L"HKD");
            if (input == CurrencyHNL) output = web::json::value(L"HNL");
            if (input == CurrencyHRK) output = web::json::value(L"HRK");
            if (input == CurrencyHTG) output = web::json::value(L"HTG");
            if (input == CurrencyHUF) output = web::json::value(L"HUF");
            if (input == CurrencyIDR) output = web::json::value(L"IDR");
            if (input == CurrencyILS) output = web::json::value(L"ILS");
            if (input == CurrencyIMP) output = web::json::value(L"IMP");
            if (input == CurrencyINR) output = web::json::value(L"INR");
            if (input == CurrencyIQD) output = web::json::value(L"IQD");
            if (input == CurrencyIRR) output = web::json::value(L"IRR");
            if (input == CurrencyISK) output = web::json::value(L"ISK");
            if (input == CurrencyJEP) output = web::json::value(L"JEP");
            if (input == CurrencyJMD) output = web::json::value(L"JMD");
            if (input == CurrencyJOD) output = web::json::value(L"JOD");
            if (input == CurrencyJPY) output = web::json::value(L"JPY");
            if (input == CurrencyKES) output = web::json::value(L"KES");
            if (input == CurrencyKGS) output = web::json::value(L"KGS");
            if (input == CurrencyKHR) output = web::json::value(L"KHR");
            if (input == CurrencyKMF) output = web::json::value(L"KMF");
            if (input == CurrencyKPW) output = web::json::value(L"KPW");
            if (input == CurrencyKRW) output = web::json::value(L"KRW");
            if (input == CurrencyKWD) output = web::json::value(L"KWD");
            if (input == CurrencyKYD) output = web::json::value(L"KYD");
            if (input == CurrencyKZT) output = web::json::value(L"KZT");
            if (input == CurrencyLAK) output = web::json::value(L"LAK");
            if (input == CurrencyLBP) output = web::json::value(L"LBP");
            if (input == CurrencyLKR) output = web::json::value(L"LKR");
            if (input == CurrencyLRD) output = web::json::value(L"LRD");
            if (input == CurrencyLSL) output = web::json::value(L"LSL");
            if (input == CurrencyLYD) output = web::json::value(L"LYD");
            if (input == CurrencyMAD) output = web::json::value(L"MAD");
            if (input == CurrencyMDL) output = web::json::value(L"MDL");
            if (input == CurrencyMGA) output = web::json::value(L"MGA");
            if (input == CurrencyMKD) output = web::json::value(L"MKD");
            if (input == CurrencyMMK) output = web::json::value(L"MMK");
            if (input == CurrencyMNT) output = web::json::value(L"MNT");
            if (input == CurrencyMOP) output = web::json::value(L"MOP");
            if (input == CurrencyMRO) output = web::json::value(L"MRO");
            if (input == CurrencyMUR) output = web::json::value(L"MUR");
            if (input == CurrencyMVR) output = web::json::value(L"MVR");
            if (input == CurrencyMWK) output = web::json::value(L"MWK");
            if (input == CurrencyMXN) output = web::json::value(L"MXN");
            if (input == CurrencyMYR) output = web::json::value(L"MYR");
            if (input == CurrencyMZN) output = web::json::value(L"MZN");
            if (input == CurrencyNAD) output = web::json::value(L"NAD");
            if (input == CurrencyNGN) output = web::json::value(L"NGN");
            if (input == CurrencyNIO) output = web::json::value(L"NIO");
            if (input == CurrencyNOK) output = web::json::value(L"NOK");
            if (input == CurrencyNPR) output = web::json::value(L"NPR");
            if (input == CurrencyNZD) output = web::json::value(L"NZD");
            if (input == CurrencyOMR) output = web::json::value(L"OMR");
            if (input == CurrencyPAB) output = web::json::value(L"PAB");
            if (input == CurrencyPEN) output = web::json::value(L"PEN");
            if (input == CurrencyPGK) output = web::json::value(L"PGK");
            if (input == CurrencyPHP) output = web::json::value(L"PHP");
            if (input == CurrencyPKR) output = web::json::value(L"PKR");
            if (input == CurrencyPLN) output = web::json::value(L"PLN");
            if (input == CurrencyPYG) output = web::json::value(L"PYG");
            if (input == CurrencyQAR) output = web::json::value(L"QAR");
            if (input == CurrencyRON) output = web::json::value(L"RON");
            if (input == CurrencyRSD) output = web::json::value(L"RSD");
            if (input == CurrencyRUB) output = web::json::value(L"RUB");
            if (input == CurrencyRWF) output = web::json::value(L"RWF");
            if (input == CurrencySAR) output = web::json::value(L"SAR");
            if (input == CurrencySBD) output = web::json::value(L"SBD");
            if (input == CurrencySCR) output = web::json::value(L"SCR");
            if (input == CurrencySDG) output = web::json::value(L"SDG");
            if (input == CurrencySEK) output = web::json::value(L"SEK");
            if (input == CurrencySGD) output = web::json::value(L"SGD");
            if (input == CurrencySHP) output = web::json::value(L"SHP");
            if (input == CurrencySLL) output = web::json::value(L"SLL");
            if (input == CurrencySOS) output = web::json::value(L"SOS");
            if (input == CurrencySPL) output = web::json::value(L"SPL");
            if (input == CurrencySRD) output = web::json::value(L"SRD");
            if (input == CurrencySTD) output = web::json::value(L"STD");
            if (input == CurrencySVC) output = web::json::value(L"SVC");
            if (input == CurrencySYP) output = web::json::value(L"SYP");
            if (input == CurrencySZL) output = web::json::value(L"SZL");
            if (input == CurrencyTHB) output = web::json::value(L"THB");
            if (input == CurrencyTJS) output = web::json::value(L"TJS");
            if (input == CurrencyTMT) output = web::json::value(L"TMT");
            if (input == CurrencyTND) output = web::json::value(L"TND");
            if (input == CurrencyTOP) output = web::json::value(L"TOP");
            if (input == CurrencyTRY) output = web::json::value(L"TRY");
            if (input == CurrencyTTD) output = web::json::value(L"TTD");
            if (input == CurrencyTVD) output = web::json::value(L"TVD");
            if (input == CurrencyTWD) output = web::json::value(L"TWD");
            if (input == CurrencyTZS) output = web::json::value(L"TZS");
            if (input == CurrencyUAH) output = web::json::value(L"UAH");
            if (input == CurrencyUGX) output = web::json::value(L"UGX");
            if (input == CurrencyUSD) output = web::json::value(L"USD");
            if (input == CurrencyUYU) output = web::json::value(L"UYU");
            if (input == CurrencyUZS) output = web::json::value(L"UZS");
            if (input == CurrencyVEF) output = web::json::value(L"VEF");
            if (input == CurrencyVND) output = web::json::value(L"VND");
            if (input == CurrencyVUV) output = web::json::value(L"VUV");
            if (input == CurrencyWST) output = web::json::value(L"WST");
            if (input == CurrencyXAF) output = web::json::value(L"XAF");
            if (input == CurrencyXCD) output = web::json::value(L"XCD");
            if (input == CurrencyXDR) output = web::json::value(L"XDR");
            if (input == CurrencyXOF) output = web::json::value(L"XOF");
            if (input == CurrencyXPF) output = web::json::value(L"XPF");
            if (input == CurrencyYER) output = web::json::value(L"YER");
            if (input == CurrencyZAR) output = web::json::value(L"ZAR");
            if (input == CurrencyZMW) output = web::json::value(L"ZMW");
            if (input == CurrencyZWD) output = web::json::value(L"ZWD");
        }
        inline void FromJsonEnum(const web::json::value& input, Currency& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"AED") output = CurrencyAED;
            if (inputStr == L"AFN") output = CurrencyAFN;
            if (inputStr == L"ALL") output = CurrencyALL;
            if (inputStr == L"AMD") output = CurrencyAMD;
            if (inputStr == L"ANG") output = CurrencyANG;
            if (inputStr == L"AOA") output = CurrencyAOA;
            if (inputStr == L"ARS") output = CurrencyARS;
            if (inputStr == L"AUD") output = CurrencyAUD;
            if (inputStr == L"AWG") output = CurrencyAWG;
            if (inputStr == L"AZN") output = CurrencyAZN;
            if (inputStr == L"BAM") output = CurrencyBAM;
            if (inputStr == L"BBD") output = CurrencyBBD;
            if (inputStr == L"BDT") output = CurrencyBDT;
            if (inputStr == L"BGN") output = CurrencyBGN;
            if (inputStr == L"BHD") output = CurrencyBHD;
            if (inputStr == L"BIF") output = CurrencyBIF;
            if (inputStr == L"BMD") output = CurrencyBMD;
            if (inputStr == L"BND") output = CurrencyBND;
            if (inputStr == L"BOB") output = CurrencyBOB;
            if (inputStr == L"BRL") output = CurrencyBRL;
            if (inputStr == L"BSD") output = CurrencyBSD;
            if (inputStr == L"BTN") output = CurrencyBTN;
            if (inputStr == L"BWP") output = CurrencyBWP;
            if (inputStr == L"BYR") output = CurrencyBYR;
            if (inputStr == L"BZD") output = CurrencyBZD;
            if (inputStr == L"CAD") output = CurrencyCAD;
            if (inputStr == L"CDF") output = CurrencyCDF;
            if (inputStr == L"CHF") output = CurrencyCHF;
            if (inputStr == L"CLP") output = CurrencyCLP;
            if (inputStr == L"CNY") output = CurrencyCNY;
            if (inputStr == L"COP") output = CurrencyCOP;
            if (inputStr == L"CRC") output = CurrencyCRC;
            if (inputStr == L"CUC") output = CurrencyCUC;
            if (inputStr == L"CUP") output = CurrencyCUP;
            if (inputStr == L"CVE") output = CurrencyCVE;
            if (inputStr == L"CZK") output = CurrencyCZK;
            if (inputStr == L"DJF") output = CurrencyDJF;
            if (inputStr == L"DKK") output = CurrencyDKK;
            if (inputStr == L"DOP") output = CurrencyDOP;
            if (inputStr == L"DZD") output = CurrencyDZD;
            if (inputStr == L"EGP") output = CurrencyEGP;
            if (inputStr == L"ERN") output = CurrencyERN;
            if (inputStr == L"ETB") output = CurrencyETB;
            if (inputStr == L"EUR") output = CurrencyEUR;
            if (inputStr == L"FJD") output = CurrencyFJD;
            if (inputStr == L"FKP") output = CurrencyFKP;
            if (inputStr == L"GBP") output = CurrencyGBP;
            if (inputStr == L"GEL") output = CurrencyGEL;
            if (inputStr == L"GGP") output = CurrencyGGP;
            if (inputStr == L"GHS") output = CurrencyGHS;
            if (inputStr == L"GIP") output = CurrencyGIP;
            if (inputStr == L"GMD") output = CurrencyGMD;
            if (inputStr == L"GNF") output = CurrencyGNF;
            if (inputStr == L"GTQ") output = CurrencyGTQ;
            if (inputStr == L"GYD") output = CurrencyGYD;
            if (inputStr == L"HKD") output = CurrencyHKD;
            if (inputStr == L"HNL") output = CurrencyHNL;
            if (inputStr == L"HRK") output = CurrencyHRK;
            if (inputStr == L"HTG") output = CurrencyHTG;
            if (inputStr == L"HUF") output = CurrencyHUF;
            if (inputStr == L"IDR") output = CurrencyIDR;
            if (inputStr == L"ILS") output = CurrencyILS;
            if (inputStr == L"IMP") output = CurrencyIMP;
            if (inputStr == L"INR") output = CurrencyINR;
            if (inputStr == L"IQD") output = CurrencyIQD;
            if (inputStr == L"IRR") output = CurrencyIRR;
            if (inputStr == L"ISK") output = CurrencyISK;
            if (inputStr == L"JEP") output = CurrencyJEP;
            if (inputStr == L"JMD") output = CurrencyJMD;
            if (inputStr == L"JOD") output = CurrencyJOD;
            if (inputStr == L"JPY") output = CurrencyJPY;
            if (inputStr == L"KES") output = CurrencyKES;
            if (inputStr == L"KGS") output = CurrencyKGS;
            if (inputStr == L"KHR") output = CurrencyKHR;
            if (inputStr == L"KMF") output = CurrencyKMF;
            if (inputStr == L"KPW") output = CurrencyKPW;
            if (inputStr == L"KRW") output = CurrencyKRW;
            if (inputStr == L"KWD") output = CurrencyKWD;
            if (inputStr == L"KYD") output = CurrencyKYD;
            if (inputStr == L"KZT") output = CurrencyKZT;
            if (inputStr == L"LAK") output = CurrencyLAK;
            if (inputStr == L"LBP") output = CurrencyLBP;
            if (inputStr == L"LKR") output = CurrencyLKR;
            if (inputStr == L"LRD") output = CurrencyLRD;
            if (inputStr == L"LSL") output = CurrencyLSL;
            if (inputStr == L"LYD") output = CurrencyLYD;
            if (inputStr == L"MAD") output = CurrencyMAD;
            if (inputStr == L"MDL") output = CurrencyMDL;
            if (inputStr == L"MGA") output = CurrencyMGA;
            if (inputStr == L"MKD") output = CurrencyMKD;
            if (inputStr == L"MMK") output = CurrencyMMK;
            if (inputStr == L"MNT") output = CurrencyMNT;
            if (inputStr == L"MOP") output = CurrencyMOP;
            if (inputStr == L"MRO") output = CurrencyMRO;
            if (inputStr == L"MUR") output = CurrencyMUR;
            if (inputStr == L"MVR") output = CurrencyMVR;
            if (inputStr == L"MWK") output = CurrencyMWK;
            if (inputStr == L"MXN") output = CurrencyMXN;
            if (inputStr == L"MYR") output = CurrencyMYR;
            if (inputStr == L"MZN") output = CurrencyMZN;
            if (inputStr == L"NAD") output = CurrencyNAD;
            if (inputStr == L"NGN") output = CurrencyNGN;
            if (inputStr == L"NIO") output = CurrencyNIO;
            if (inputStr == L"NOK") output = CurrencyNOK;
            if (inputStr == L"NPR") output = CurrencyNPR;
            if (inputStr == L"NZD") output = CurrencyNZD;
            if (inputStr == L"OMR") output = CurrencyOMR;
            if (inputStr == L"PAB") output = CurrencyPAB;
            if (inputStr == L"PEN") output = CurrencyPEN;
            if (inputStr == L"PGK") output = CurrencyPGK;
            if (inputStr == L"PHP") output = CurrencyPHP;
            if (inputStr == L"PKR") output = CurrencyPKR;
            if (inputStr == L"PLN") output = CurrencyPLN;
            if (inputStr == L"PYG") output = CurrencyPYG;
            if (inputStr == L"QAR") output = CurrencyQAR;
            if (inputStr == L"RON") output = CurrencyRON;
            if (inputStr == L"RSD") output = CurrencyRSD;
            if (inputStr == L"RUB") output = CurrencyRUB;
            if (inputStr == L"RWF") output = CurrencyRWF;
            if (inputStr == L"SAR") output = CurrencySAR;
            if (inputStr == L"SBD") output = CurrencySBD;
            if (inputStr == L"SCR") output = CurrencySCR;
            if (inputStr == L"SDG") output = CurrencySDG;
            if (inputStr == L"SEK") output = CurrencySEK;
            if (inputStr == L"SGD") output = CurrencySGD;
            if (inputStr == L"SHP") output = CurrencySHP;
            if (inputStr == L"SLL") output = CurrencySLL;
            if (inputStr == L"SOS") output = CurrencySOS;
            if (inputStr == L"SPL") output = CurrencySPL;
            if (inputStr == L"SRD") output = CurrencySRD;
            if (inputStr == L"STD") output = CurrencySTD;
            if (inputStr == L"SVC") output = CurrencySVC;
            if (inputStr == L"SYP") output = CurrencySYP;
            if (inputStr == L"SZL") output = CurrencySZL;
            if (inputStr == L"THB") output = CurrencyTHB;
            if (inputStr == L"TJS") output = CurrencyTJS;
            if (inputStr == L"TMT") output = CurrencyTMT;
            if (inputStr == L"TND") output = CurrencyTND;
            if (inputStr == L"TOP") output = CurrencyTOP;
            if (inputStr == L"TRY") output = CurrencyTRY;
            if (inputStr == L"TTD") output = CurrencyTTD;
            if (inputStr == L"TVD") output = CurrencyTVD;
            if (inputStr == L"TWD") output = CurrencyTWD;
            if (inputStr == L"TZS") output = CurrencyTZS;
            if (inputStr == L"UAH") output = CurrencyUAH;
            if (inputStr == L"UGX") output = CurrencyUGX;
            if (inputStr == L"USD") output = CurrencyUSD;
            if (inputStr == L"UYU") output = CurrencyUYU;
            if (inputStr == L"UZS") output = CurrencyUZS;
            if (inputStr == L"VEF") output = CurrencyVEF;
            if (inputStr == L"VND") output = CurrencyVND;
            if (inputStr == L"VUV") output = CurrencyVUV;
            if (inputStr == L"WST") output = CurrencyWST;
            if (inputStr == L"XAF") output = CurrencyXAF;
            if (inputStr == L"XCD") output = CurrencyXCD;
            if (inputStr == L"XDR") output = CurrencyXDR;
            if (inputStr == L"XOF") output = CurrencyXOF;
            if (inputStr == L"XPF") output = CurrencyXPF;
            if (inputStr == L"YER") output = CurrencyYER;
            if (inputStr == L"ZAR") output = CurrencyZAR;
            if (inputStr == L"ZMW") output = CurrencyZMW;
            if (inputStr == L"ZWD") output = CurrencyZWD;
        }

        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        inline void ToJsonEnum(const EffectType input, web::json::value& output)
        {
            if (input == EffectTypeAllow) output = web::json::value(L"Allow");
            if (input == EffectTypeDeny) output = web::json::value(L"Deny");
        }
        inline void FromJsonEnum(const web::json::value& input, EffectType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Allow") output = EffectTypeAllow;
            if (inputStr == L"Deny") output = EffectTypeDeny;
        }

        enum EmailVerificationStatus
        {
            EmailVerificationStatusUnverified,
            EmailVerificationStatusPending,
            EmailVerificationStatusConfirmed
        };

        inline void ToJsonEnum(const EmailVerificationStatus input, web::json::value& output)
        {
            if (input == EmailVerificationStatusUnverified) output = web::json::value(L"Unverified");
            if (input == EmailVerificationStatusPending) output = web::json::value(L"Pending");
            if (input == EmailVerificationStatusConfirmed) output = web::json::value(L"Confirmed");
        }
        inline void FromJsonEnum(const web::json::value& input, EmailVerificationStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Unverified") output = EmailVerificationStatusUnverified;
            if (inputStr == L"Pending") output = EmailVerificationStatusPending;
            if (inputStr == L"Confirmed") output = EmailVerificationStatusConfirmed;
        }

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

        enum GameBuildStatus
        {
            GameBuildStatusAvailable,
            GameBuildStatusValidating,
            GameBuildStatusInvalidBuildPackage,
            GameBuildStatusProcessing,
            GameBuildStatusFailedToProcess
        };

        inline void ToJsonEnum(const GameBuildStatus input, web::json::value& output)
        {
            if (input == GameBuildStatusAvailable) output = web::json::value(L"Available");
            if (input == GameBuildStatusValidating) output = web::json::value(L"Validating");
            if (input == GameBuildStatusInvalidBuildPackage) output = web::json::value(L"InvalidBuildPackage");
            if (input == GameBuildStatusProcessing) output = web::json::value(L"Processing");
            if (input == GameBuildStatusFailedToProcess) output = web::json::value(L"FailedToProcess");
        }
        inline void FromJsonEnum(const web::json::value& input, GameBuildStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Available") output = GameBuildStatusAvailable;
            if (inputStr == L"Validating") output = GameBuildStatusValidating;
            if (inputStr == L"InvalidBuildPackage") output = GameBuildStatusInvalidBuildPackage;
            if (inputStr == L"Processing") output = GameBuildStatusProcessing;
            if (inputStr == L"FailedToProcess") output = GameBuildStatusFailedToProcess;
        }

        enum GenericErrorCodes
        {
            GenericErrorCodesSuccess,
            GenericErrorCodesUnkownError,
            GenericErrorCodesInvalidParams,
            GenericErrorCodesAccountNotFound,
            GenericErrorCodesAccountBanned,
            GenericErrorCodesInvalidUsernameOrPassword,
            GenericErrorCodesInvalidTitleId,
            GenericErrorCodesInvalidEmailAddress,
            GenericErrorCodesEmailAddressNotAvailable,
            GenericErrorCodesInvalidUsername,
            GenericErrorCodesInvalidPassword,
            GenericErrorCodesUsernameNotAvailable,
            GenericErrorCodesInvalidSteamTicket,
            GenericErrorCodesAccountAlreadyLinked,
            GenericErrorCodesLinkedAccountAlreadyClaimed,
            GenericErrorCodesInvalidFacebookToken,
            GenericErrorCodesAccountNotLinked,
            GenericErrorCodesFailedByPaymentProvider,
            GenericErrorCodesCouponCodeNotFound,
            GenericErrorCodesInvalidContainerItem,
            GenericErrorCodesContainerNotOwned,
            GenericErrorCodesKeyNotOwned,
            GenericErrorCodesInvalidItemIdInTable,
            GenericErrorCodesInvalidReceipt,
            GenericErrorCodesReceiptAlreadyUsed,
            GenericErrorCodesReceiptCancelled,
            GenericErrorCodesGameNotFound,
            GenericErrorCodesGameModeNotFound,
            GenericErrorCodesInvalidGoogleToken,
            GenericErrorCodesUserIsNotPartOfDeveloper,
            GenericErrorCodesInvalidTitleForDeveloper,
            GenericErrorCodesTitleNameConflicts,
            GenericErrorCodesUserisNotValid,
            GenericErrorCodesValueAlreadyExists,
            GenericErrorCodesBuildNotFound,
            GenericErrorCodesPlayerNotInGame,
            GenericErrorCodesInvalidTicket,
            GenericErrorCodesInvalidDeveloper,
            GenericErrorCodesInvalidOrderInfo,
            GenericErrorCodesRegistrationIncomplete,
            GenericErrorCodesInvalidPlatform,
            GenericErrorCodesUnknownError,
            GenericErrorCodesSteamApplicationNotOwned,
            GenericErrorCodesWrongSteamAccount,
            GenericErrorCodesTitleNotActivated,
            GenericErrorCodesRegistrationSessionNotFound,
            GenericErrorCodesNoSuchMod,
            GenericErrorCodesFileNotFound,
            GenericErrorCodesDuplicateEmail,
            GenericErrorCodesItemNotFound,
            GenericErrorCodesItemNotOwned,
            GenericErrorCodesItemNotRecycleable,
            GenericErrorCodesItemNotAffordable,
            GenericErrorCodesInvalidVirtualCurrency,
            GenericErrorCodesWrongVirtualCurrency,
            GenericErrorCodesWrongPrice,
            GenericErrorCodesNonPositiveValue,
            GenericErrorCodesInvalidRegion,
            GenericErrorCodesRegionAtCapacity,
            GenericErrorCodesServerFailedToStart,
            GenericErrorCodesNameNotAvailable,
            GenericErrorCodesInsufficientFunds,
            GenericErrorCodesInvalidDeviceID,
            GenericErrorCodesInvalidPushNotificationToken,
            GenericErrorCodesNoRemainingUses,
            GenericErrorCodesInvalidPaymentProvider,
            GenericErrorCodesPurchaseInitializationFailure,
            GenericErrorCodesDuplicateUsername,
            GenericErrorCodesInvalidBuyerInfo,
            GenericErrorCodesNoGameModeParamsSet,
            GenericErrorCodesBodyTooLarge,
            GenericErrorCodesReservedWordInBody,
            GenericErrorCodesInvalidTypeInBody,
            GenericErrorCodesInvalidRequest,
            GenericErrorCodesReservedEventName,
            GenericErrorCodesInvalidUserStatistics,
            GenericErrorCodesNotAuthenticated,
            GenericErrorCodesStreamAlreadyExists,
            GenericErrorCodesErrorCreatingStream,
            GenericErrorCodesStreamNotFound,
            GenericErrorCodesInvalidAccount,
            GenericErrorCodesPurchaseDoesNotExist,
            GenericErrorCodesInvalidPurchaseTransactionStatus,
            GenericErrorCodesAPINotEnabledForGameClientAccess,
            GenericErrorCodesNoPushNotificationARNForTitle,
            GenericErrorCodesBuildAlreadyExists,
            GenericErrorCodesBuildPackageDoesNotExist,
            GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle,
            GenericErrorCodesInvalidSharedGroupId,
            GenericErrorCodesNotAuthorized,
            GenericErrorCodesMissingTitleGoogleProperties,
            GenericErrorCodesInvalidItemProperties,
            GenericErrorCodesInvalidPSNAuthCode,
            GenericErrorCodesInvalidItemId,
            GenericErrorCodesPushNotEnabledForAccount,
            GenericErrorCodesPushServiceError,
            GenericErrorCodesReceiptDoesNotContainInAppItems,
            GenericErrorCodesReceiptContainsMultipleInAppItems,
            GenericErrorCodesInvalidBundleID,
            GenericErrorCodesJavascriptException,
            GenericErrorCodesInvalidSessionTicket,
            GenericErrorCodesUnableToConnectToDatabase,
            GenericErrorCodesInternalServerError,
            GenericErrorCodesInvalidReportDate,
            GenericErrorCodesReportNotAvailable,
            GenericErrorCodesDatabaseThroughputExceeded,
            GenericErrorCodesInvalidGameTicket,
            GenericErrorCodesExpiredGameTicket,
            GenericErrorCodesGameTicketDoesNotMatchLobby,
            GenericErrorCodesLinkedDeviceAlreadyClaimed,
            GenericErrorCodesDeviceAlreadyLinked,
            GenericErrorCodesDeviceNotLinked,
            GenericErrorCodesPartialFailure,
            GenericErrorCodesPublisherNotSet,
            GenericErrorCodesServiceUnavailable,
            GenericErrorCodesVersionNotFound,
            GenericErrorCodesRevisionNotFound,
            GenericErrorCodesInvalidPublisherId,
            GenericErrorCodesDownstreamServiceUnavailable,
            GenericErrorCodesAPINotIncludedInTitleUsageTier,
            GenericErrorCodesDAULimitExceeded,
            GenericErrorCodesAPIRequestLimitExceeded,
            GenericErrorCodesInvalidAPIEndpoint,
            GenericErrorCodesBuildNotAvailable,
            GenericErrorCodesConcurrentEditError,
            GenericErrorCodesContentNotFound,
            GenericErrorCodesCharacterNotFound,
            GenericErrorCodesCloudScriptNotFound,
            GenericErrorCodesContentQuotaExceeded,
            GenericErrorCodesInvalidCharacterStatistics,
            GenericErrorCodesPhotonNotEnabledForTitle,
            GenericErrorCodesPhotonApplicationNotFound,
            GenericErrorCodesPhotonApplicationNotAssociatedWithTitle,
            GenericErrorCodesInvalidEmailOrPassword,
            GenericErrorCodesFacebookAPIError,
            GenericErrorCodesInvalidContentType,
            GenericErrorCodesKeyLengthExceeded,
            GenericErrorCodesDataLengthExceeded,
            GenericErrorCodesTooManyKeys,
            GenericErrorCodesFreeTierCannotHaveVirtualCurrency,
            GenericErrorCodesMissingAmazonSharedKey,
            GenericErrorCodesAmazonValidationError,
            GenericErrorCodesInvalidPSNIssuerId,
            GenericErrorCodesPSNInaccessible,
            GenericErrorCodesExpiredAuthToken,
            GenericErrorCodesFailedToGetEntitlements,
            GenericErrorCodesFailedToConsumeEntitlement,
            GenericErrorCodesTradeAcceptingUserNotAllowed,
            GenericErrorCodesTradeInventoryItemIsAssignedToCharacter,
            GenericErrorCodesTradeInventoryItemIsBundle,
            GenericErrorCodesTradeStatusNotValidForCancelling,
            GenericErrorCodesTradeStatusNotValidForAccepting,
            GenericErrorCodesTradeDoesNotExist,
            GenericErrorCodesTradeCancelled,
            GenericErrorCodesTradeAlreadyFilled,
            GenericErrorCodesTradeWaitForStatusTimeout,
            GenericErrorCodesTradeInventoryItemExpired,
            GenericErrorCodesTradeMissingOfferedAndAcceptedItems,
            GenericErrorCodesTradeAcceptedItemIsBundle,
            GenericErrorCodesTradeAcceptedItemIsStackable,
            GenericErrorCodesTradeInventoryItemInvalidStatus,
            GenericErrorCodesTradeAcceptedCatalogItemInvalid,
            GenericErrorCodesTradeAllowedUsersInvalid,
            GenericErrorCodesTradeInventoryItemDoesNotExist,
            GenericErrorCodesTradeInventoryItemIsConsumed,
            GenericErrorCodesTradeInventoryItemIsStackable,
            GenericErrorCodesTradeAcceptedItemsMismatch,
            GenericErrorCodesInvalidKongregateToken,
            GenericErrorCodesFeatureNotConfiguredForTitle,
            GenericErrorCodesNoMatchingCatalogItemForReceipt,
            GenericErrorCodesInvalidCurrencyCode,
            GenericErrorCodesNoRealMoneyPriceForCatalogItem,
            GenericErrorCodesTradeInventoryItemIsNotTradable,
            GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable,
            GenericErrorCodesUsersAlreadyFriends,
            GenericErrorCodesLinkedIdentifierAlreadyClaimed,
            GenericErrorCodesCustomIdNotLinked,
            GenericErrorCodesTotalDataSizeExceeded,
            GenericErrorCodesDeleteKeyConflict,
            GenericErrorCodesInvalidXboxLiveToken,
            GenericErrorCodesExpiredXboxLiveToken,
            GenericErrorCodesResettableStatisticVersionRequired,
            GenericErrorCodesNotAuthorizedByTitle,
            GenericErrorCodesNoPartnerEnabled,
            GenericErrorCodesInvalidPartnerResponse,
            GenericErrorCodesAPINotEnabledForGameServerAccess,
            GenericErrorCodesStatisticNotFound,
            GenericErrorCodesStatisticNameConflict,
            GenericErrorCodesStatisticVersionClosedForWrites,
            GenericErrorCodesStatisticVersionInvalid,
            GenericErrorCodesAPIClientRequestRateLimitExceeded,
            GenericErrorCodesInvalidJSONContent,
            GenericErrorCodesInvalidDropTable,
            GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval,
            GenericErrorCodesStatisticCountLimitExceeded,
            GenericErrorCodesStatisticVersionIncrementRateExceeded,
            GenericErrorCodesContainerKeyInvalid,
            GenericErrorCodesCloudScriptExecutionTimeLimitExceeded,
            GenericErrorCodesNoWritePermissionsForEvent,
            GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded,
            GenericErrorCodesCloudScriptAPIRequestCountExceeded,
            GenericErrorCodesCloudScriptAPIRequestError,
            GenericErrorCodesCloudScriptHTTPRequestError,
            GenericErrorCodesInsufficientGuildRole,
            GenericErrorCodesGuildNotFound,
            GenericErrorCodesOverLimit,
            GenericErrorCodesEventNotFound,
            GenericErrorCodesInvalidEventField,
            GenericErrorCodesInvalidEventName,
            GenericErrorCodesCatalogNotConfigured,
            GenericErrorCodesOperationNotSupportedForPlatform,
            GenericErrorCodesSegmentNotFound,
            GenericErrorCodesStoreNotFound,
            GenericErrorCodesInvalidStatisticName,
            GenericErrorCodesTitleNotQualifiedForLimit,
            GenericErrorCodesInvalidServiceLimitLevel,
            GenericErrorCodesServiceLimitLevelInTransition,
            GenericErrorCodesCouponAlreadyRedeemed,
            GenericErrorCodesGameServerBuildSizeLimitExceeded,
            GenericErrorCodesGameServerBuildCountLimitExceeded,
            GenericErrorCodesVirtualCurrencyCountLimitExceeded,
            GenericErrorCodesVirtualCurrencyCodeExists,
            GenericErrorCodesTitleNewsItemCountLimitExceeded,
            GenericErrorCodesInvalidTwitchToken,
            GenericErrorCodesTwitchResponseError,
            GenericErrorCodesProfaneDisplayName,
            GenericErrorCodesUserAlreadyAdded,
            GenericErrorCodesInvalidVirtualCurrencyCode,
            GenericErrorCodesVirtualCurrencyCannotBeDeleted,
            GenericErrorCodesIdentifierAlreadyClaimed,
            GenericErrorCodesIdentifierNotLinked,
            GenericErrorCodesInvalidContinuationToken,
            GenericErrorCodesExpiredContinuationToken,
            GenericErrorCodesInvalidSegment,
            GenericErrorCodesInvalidSessionId,
            GenericErrorCodesSessionLogNotFound,
            GenericErrorCodesInvalidSearchTerm,
            GenericErrorCodesTwoFactorAuthenticationTokenRequired,
            GenericErrorCodesGameServerHostCountLimitExceeded,
            GenericErrorCodesPlayerTagCountLimitExceeded,
            GenericErrorCodesRequestAlreadyRunning,
            GenericErrorCodesActionGroupNotFound,
            GenericErrorCodesMaximumSegmentBulkActionJobsRunning,
            GenericErrorCodesNoActionsOnPlayersInSegmentJob,
            GenericErrorCodesDuplicateStatisticName,
            GenericErrorCodesScheduledTaskNameConflict,
            GenericErrorCodesScheduledTaskCreateConflict,
            GenericErrorCodesInvalidScheduledTaskName,
            GenericErrorCodesInvalidTaskSchedule,
            GenericErrorCodesSteamNotEnabledForTitle,
            GenericErrorCodesLimitNotAnUpgradeOption,
            GenericErrorCodesNoSecretKeyEnabledForCloudScript,
            GenericErrorCodesTaskNotFound,
            GenericErrorCodesTaskInstanceNotFound,
            GenericErrorCodesInvalidIdentityProviderId,
            GenericErrorCodesMisconfiguredIdentityProvider,
            GenericErrorCodesInvalidScheduledTaskType,
            GenericErrorCodesBillingInformationRequired,
            GenericErrorCodesLimitedEditionItemUnavailable,
            GenericErrorCodesInvalidAdPlacementAndReward,
            GenericErrorCodesAllAdPlacementViewsAlreadyConsumed,
            GenericErrorCodesGoogleOAuthNotConfiguredForTitle,
            GenericErrorCodesGoogleOAuthError,
            GenericErrorCodesUserNotFriend,
            GenericErrorCodesInvalidSignature,
            GenericErrorCodesInvalidPublicKey,
            GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse,
            GenericErrorCodesStatisticUpdateInProgress,
            GenericErrorCodesLeaderboardVersionNotAvailable,
            GenericErrorCodesStatisticAlreadyHasPrizeTable,
            GenericErrorCodesPrizeTableHasOverlappingRanks,
            GenericErrorCodesPrizeTableHasMissingRanks,
            GenericErrorCodesPrizeTableRankStartsAtZero,
            GenericErrorCodesInvalidStatistic,
            GenericErrorCodesExpressionParseFailure,
            GenericErrorCodesExpressionInvokeFailure,
            GenericErrorCodesExpressionTooLong,
            GenericErrorCodesDataUpdateRateExceeded,
            GenericErrorCodesRestrictedEmailDomain,
            GenericErrorCodesEncryptionKeyDisabled,
            GenericErrorCodesEncryptionKeyMissing,
            GenericErrorCodesEncryptionKeyBroken,
            GenericErrorCodesNoSharedSecretKeyConfigured,
            GenericErrorCodesSecretKeyNotFound,
            GenericErrorCodesPlayerSecretAlreadyConfigured,
            GenericErrorCodesAPIRequestsDisabledForTitle,
            GenericErrorCodesInvalidSharedSecretKey,
            GenericErrorCodesPrizeTableHasNoRanks,
            GenericErrorCodesProfileDoesNotExist,
            GenericErrorCodesContentS3OriginBucketNotConfigured,
            GenericErrorCodesInvalidEnvironmentForReceipt,
            GenericErrorCodesEncryptedRequestNotAllowed,
            GenericErrorCodesSignedRequestNotAllowed,
            GenericErrorCodesRequestViewConstraintParamsNotAllowed,
            GenericErrorCodesBadPartnerConfiguration,
            GenericErrorCodesXboxBPCertificateFailure,
            GenericErrorCodesXboxXASSExchangeFailure,
            GenericErrorCodesInvalidEntityId,
            GenericErrorCodesStatisticValueAggregationOverflow,
            GenericErrorCodesEmailMessageFromAddressIsMissing,
            GenericErrorCodesEmailMessageToAddressIsMissing,
            GenericErrorCodesSmtpServerAuthenticationError,
            GenericErrorCodesSmtpServerLimitExceeded,
            GenericErrorCodesSmtpServerInsufficientStorage,
            GenericErrorCodesSmtpServerCommunicationError,
            GenericErrorCodesSmtpServerGeneralFailure,
            GenericErrorCodesEmailClientTimeout,
            GenericErrorCodesEmailClientCanceledTask,
            GenericErrorCodesEmailTemplateMissing,
            GenericErrorCodesInvalidHostForTitleId,
            GenericErrorCodesEmailConfirmationTokenDoesNotExist,
            GenericErrorCodesEmailConfirmationTokenExpired,
            GenericErrorCodesAccountDeleted,
            GenericErrorCodesPlayerSecretNotConfigured,
            GenericErrorCodesInvalidSignatureTime,
            GenericErrorCodesNoContactEmailAddressFound,
            GenericErrorCodesInvalidAuthToken,
            GenericErrorCodesAuthTokenDoesNotExist,
            GenericErrorCodesAuthTokenExpired,
            GenericErrorCodesAuthTokenAlreadyUsedToResetPassword,
            GenericErrorCodesMembershipNameTooLong,
            GenericErrorCodesMembershipNotFound,
            GenericErrorCodesGoogleServiceAccountInvalid,
            GenericErrorCodesGoogleServiceAccountParseFailure,
            GenericErrorCodesEntityTokenMissing,
            GenericErrorCodesEntityTokenInvalid,
            GenericErrorCodesEntityTokenExpired,
            GenericErrorCodesEntityTokenRevoked,
            GenericErrorCodesInvalidProductForSubscription,
            GenericErrorCodesXboxInaccessible,
            GenericErrorCodesSubscriptionAlreadyTaken,
            GenericErrorCodesSmtpAddonNotEnabled,
            GenericErrorCodesAPIConcurrentRequestLimitExceeded,
            GenericErrorCodesXboxRejectedXSTSExchangeRequest,
            GenericErrorCodesVariableNotDefined,
            GenericErrorCodesTemplateVersionNotDefined,
            GenericErrorCodesFileTooLarge,
            GenericErrorCodesTitleDeleted,
            GenericErrorCodesTitleContainsUserAccounts,
            GenericErrorCodesTitleDeletionPlayerCleanupFailure,
            GenericErrorCodesEntityFileOperationPending,
            GenericErrorCodesNoEntityFileOperationPending,
            GenericErrorCodesEntityProfileVersionMismatch,
            GenericErrorCodesTemplateVersionTooOld,
            GenericErrorCodesMembershipDefinitionInUse,
            GenericErrorCodesPaymentPageNotConfigured,
            GenericErrorCodesFailedLoginAttemptRateLimitExceeded,
            GenericErrorCodesEntityBlockedByGroup,
            GenericErrorCodesRoleDoesNotExist,
            GenericErrorCodesEntityIsAlreadyMember,
            GenericErrorCodesDuplicateRoleId,
            GenericErrorCodesGroupInvitationNotFound,
            GenericErrorCodesGroupApplicationNotFound,
            GenericErrorCodesOutstandingInvitationAcceptedInstead,
            GenericErrorCodesOutstandingApplicationAcceptedInstead,
            GenericErrorCodesRoleIsGroupDefaultMember,
            GenericErrorCodesRoleIsGroupAdmin,
            GenericErrorCodesRoleNameNotAvailable,
            GenericErrorCodesGroupNameNotAvailable,
            GenericErrorCodesEmailReportAlreadySent,
            GenericErrorCodesEmailReportRecipientBlacklisted,
            GenericErrorCodesEventNamespaceNotAllowed,
            GenericErrorCodesEventEntityNotAllowed,
            GenericErrorCodesInvalidEntityType,
            GenericErrorCodesNullTokenResultFromAad,
            GenericErrorCodesInvalidTokenResultFromAad,
            GenericErrorCodesNoValidCertificateForAad,
            GenericErrorCodesInvalidCertificateForAad,
            GenericErrorCodesDuplicateDropTableId,
            GenericErrorCodesGameServerOk,
            GenericErrorCodesGameServerAccepted,
            GenericErrorCodesGameServerNoContent,
            GenericErrorCodesGameServerBadRequest,
            GenericErrorCodesGameServerUnauthorized,
            GenericErrorCodesGameServerForbidden,
            GenericErrorCodesGameServerNotFound,
            GenericErrorCodesGameServerConflict,
            GenericErrorCodesGameServerInternalServerError,
            GenericErrorCodesGameServerServiceUnavailable,
            GenericErrorCodesExplicitContentDetected,
            GenericErrorCodesPIIContentDetected,
            GenericErrorCodesInvalidScheduledTaskParameter,
            GenericErrorCodesPerEntityEventRateLimitExceeded,
            GenericErrorCodesTitleDefaultLanguageNotSet,
            GenericErrorCodesEmailTemplateMissingDefaultVersion,
            GenericErrorCodesFacebookInstantGamesIdNotLinked,
            GenericErrorCodesInvalidFacebookInstantGamesSignature,
            GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle,
            GenericErrorCodesMatchmakingEntityInvalid,
            GenericErrorCodesMatchmakingPlayerAttributesInvalid,
            GenericErrorCodesMatchmakingCreateRequestMissing,
            GenericErrorCodesMatchmakingCreateRequestCreatorMissing,
            GenericErrorCodesMatchmakingCreateRequestCreatorIdMissing,
            GenericErrorCodesMatchmakingCreateRequestUserListMissing,
            GenericErrorCodesMatchmakingCreateRequestGiveUpAfterInvalid,
            GenericErrorCodesMatchmakingTicketIdMissing,
            GenericErrorCodesMatchmakingMatchIdMissing,
            GenericErrorCodesMatchmakingMatchIdIdMissing,
            GenericErrorCodesMatchmakingQueueNameMissing,
            GenericErrorCodesMatchmakingTitleIdMissing,
            GenericErrorCodesMatchmakingTicketIdIdMissing,
            GenericErrorCodesMatchmakingPlayerIdMissing,
            GenericErrorCodesMatchmakingJoinRequestUserMissing,
            GenericErrorCodesMatchmakingQueueConfigNotFound,
            GenericErrorCodesMatchmakingMatchNotFound,
            GenericErrorCodesMatchmakingTicketNotFound,
            GenericErrorCodesMatchmakingCreateTicketServerIdentityInvalid,
            GenericErrorCodesMatchmakingCreateTicketClientIdentityInvalid,
            GenericErrorCodesMatchmakingGetTicketUserMismatch,
            GenericErrorCodesMatchmakingJoinTicketServerIdentityInvalid,
            GenericErrorCodesMatchmakingJoinTicketUserIdentityMismatch,
            GenericErrorCodesMatchmakingCancelTicketServerIdentityInvalid,
            GenericErrorCodesMatchmakingCancelTicketUserIdentityMismatch,
            GenericErrorCodesMatchmakingGetMatchIdentityMismatch,
            GenericErrorCodesMatchmakingPlayerIdentityMismatch,
            GenericErrorCodesMatchmakingAlreadyJoinedTicket,
            GenericErrorCodesMatchmakingTicketAlreadyCompleted,
            GenericErrorCodesMatchmakingQueueNameInvalid,
            GenericErrorCodesMatchmakingQueueConfigInvalid,
            GenericErrorCodesMatchmakingMemberProfileInvalid,
            GenericErrorCodesWriteAttemptedDuringExport,
            GenericErrorCodesNintendoSwitchDeviceIdNotLinked,
            GenericErrorCodesMatchmakingNotEnabled
        };

        inline void ToJsonEnum(const GenericErrorCodes input, web::json::value& output)
        {
            if (input == GenericErrorCodesSuccess) output = web::json::value(L"Success");
            if (input == GenericErrorCodesUnkownError) output = web::json::value(L"UnkownError");
            if (input == GenericErrorCodesInvalidParams) output = web::json::value(L"InvalidParams");
            if (input == GenericErrorCodesAccountNotFound) output = web::json::value(L"AccountNotFound");
            if (input == GenericErrorCodesAccountBanned) output = web::json::value(L"AccountBanned");
            if (input == GenericErrorCodesInvalidUsernameOrPassword) output = web::json::value(L"InvalidUsernameOrPassword");
            if (input == GenericErrorCodesInvalidTitleId) output = web::json::value(L"InvalidTitleId");
            if (input == GenericErrorCodesInvalidEmailAddress) output = web::json::value(L"InvalidEmailAddress");
            if (input == GenericErrorCodesEmailAddressNotAvailable) output = web::json::value(L"EmailAddressNotAvailable");
            if (input == GenericErrorCodesInvalidUsername) output = web::json::value(L"InvalidUsername");
            if (input == GenericErrorCodesInvalidPassword) output = web::json::value(L"InvalidPassword");
            if (input == GenericErrorCodesUsernameNotAvailable) output = web::json::value(L"UsernameNotAvailable");
            if (input == GenericErrorCodesInvalidSteamTicket) output = web::json::value(L"InvalidSteamTicket");
            if (input == GenericErrorCodesAccountAlreadyLinked) output = web::json::value(L"AccountAlreadyLinked");
            if (input == GenericErrorCodesLinkedAccountAlreadyClaimed) output = web::json::value(L"LinkedAccountAlreadyClaimed");
            if (input == GenericErrorCodesInvalidFacebookToken) output = web::json::value(L"InvalidFacebookToken");
            if (input == GenericErrorCodesAccountNotLinked) output = web::json::value(L"AccountNotLinked");
            if (input == GenericErrorCodesFailedByPaymentProvider) output = web::json::value(L"FailedByPaymentProvider");
            if (input == GenericErrorCodesCouponCodeNotFound) output = web::json::value(L"CouponCodeNotFound");
            if (input == GenericErrorCodesInvalidContainerItem) output = web::json::value(L"InvalidContainerItem");
            if (input == GenericErrorCodesContainerNotOwned) output = web::json::value(L"ContainerNotOwned");
            if (input == GenericErrorCodesKeyNotOwned) output = web::json::value(L"KeyNotOwned");
            if (input == GenericErrorCodesInvalidItemIdInTable) output = web::json::value(L"InvalidItemIdInTable");
            if (input == GenericErrorCodesInvalidReceipt) output = web::json::value(L"InvalidReceipt");
            if (input == GenericErrorCodesReceiptAlreadyUsed) output = web::json::value(L"ReceiptAlreadyUsed");
            if (input == GenericErrorCodesReceiptCancelled) output = web::json::value(L"ReceiptCancelled");
            if (input == GenericErrorCodesGameNotFound) output = web::json::value(L"GameNotFound");
            if (input == GenericErrorCodesGameModeNotFound) output = web::json::value(L"GameModeNotFound");
            if (input == GenericErrorCodesInvalidGoogleToken) output = web::json::value(L"InvalidGoogleToken");
            if (input == GenericErrorCodesUserIsNotPartOfDeveloper) output = web::json::value(L"UserIsNotPartOfDeveloper");
            if (input == GenericErrorCodesInvalidTitleForDeveloper) output = web::json::value(L"InvalidTitleForDeveloper");
            if (input == GenericErrorCodesTitleNameConflicts) output = web::json::value(L"TitleNameConflicts");
            if (input == GenericErrorCodesUserisNotValid) output = web::json::value(L"UserisNotValid");
            if (input == GenericErrorCodesValueAlreadyExists) output = web::json::value(L"ValueAlreadyExists");
            if (input == GenericErrorCodesBuildNotFound) output = web::json::value(L"BuildNotFound");
            if (input == GenericErrorCodesPlayerNotInGame) output = web::json::value(L"PlayerNotInGame");
            if (input == GenericErrorCodesInvalidTicket) output = web::json::value(L"InvalidTicket");
            if (input == GenericErrorCodesInvalidDeveloper) output = web::json::value(L"InvalidDeveloper");
            if (input == GenericErrorCodesInvalidOrderInfo) output = web::json::value(L"InvalidOrderInfo");
            if (input == GenericErrorCodesRegistrationIncomplete) output = web::json::value(L"RegistrationIncomplete");
            if (input == GenericErrorCodesInvalidPlatform) output = web::json::value(L"InvalidPlatform");
            if (input == GenericErrorCodesUnknownError) output = web::json::value(L"UnknownError");
            if (input == GenericErrorCodesSteamApplicationNotOwned) output = web::json::value(L"SteamApplicationNotOwned");
            if (input == GenericErrorCodesWrongSteamAccount) output = web::json::value(L"WrongSteamAccount");
            if (input == GenericErrorCodesTitleNotActivated) output = web::json::value(L"TitleNotActivated");
            if (input == GenericErrorCodesRegistrationSessionNotFound) output = web::json::value(L"RegistrationSessionNotFound");
            if (input == GenericErrorCodesNoSuchMod) output = web::json::value(L"NoSuchMod");
            if (input == GenericErrorCodesFileNotFound) output = web::json::value(L"FileNotFound");
            if (input == GenericErrorCodesDuplicateEmail) output = web::json::value(L"DuplicateEmail");
            if (input == GenericErrorCodesItemNotFound) output = web::json::value(L"ItemNotFound");
            if (input == GenericErrorCodesItemNotOwned) output = web::json::value(L"ItemNotOwned");
            if (input == GenericErrorCodesItemNotRecycleable) output = web::json::value(L"ItemNotRecycleable");
            if (input == GenericErrorCodesItemNotAffordable) output = web::json::value(L"ItemNotAffordable");
            if (input == GenericErrorCodesInvalidVirtualCurrency) output = web::json::value(L"InvalidVirtualCurrency");
            if (input == GenericErrorCodesWrongVirtualCurrency) output = web::json::value(L"WrongVirtualCurrency");
            if (input == GenericErrorCodesWrongPrice) output = web::json::value(L"WrongPrice");
            if (input == GenericErrorCodesNonPositiveValue) output = web::json::value(L"NonPositiveValue");
            if (input == GenericErrorCodesInvalidRegion) output = web::json::value(L"InvalidRegion");
            if (input == GenericErrorCodesRegionAtCapacity) output = web::json::value(L"RegionAtCapacity");
            if (input == GenericErrorCodesServerFailedToStart) output = web::json::value(L"ServerFailedToStart");
            if (input == GenericErrorCodesNameNotAvailable) output = web::json::value(L"NameNotAvailable");
            if (input == GenericErrorCodesInsufficientFunds) output = web::json::value(L"InsufficientFunds");
            if (input == GenericErrorCodesInvalidDeviceID) output = web::json::value(L"InvalidDeviceID");
            if (input == GenericErrorCodesInvalidPushNotificationToken) output = web::json::value(L"InvalidPushNotificationToken");
            if (input == GenericErrorCodesNoRemainingUses) output = web::json::value(L"NoRemainingUses");
            if (input == GenericErrorCodesInvalidPaymentProvider) output = web::json::value(L"InvalidPaymentProvider");
            if (input == GenericErrorCodesPurchaseInitializationFailure) output = web::json::value(L"PurchaseInitializationFailure");
            if (input == GenericErrorCodesDuplicateUsername) output = web::json::value(L"DuplicateUsername");
            if (input == GenericErrorCodesInvalidBuyerInfo) output = web::json::value(L"InvalidBuyerInfo");
            if (input == GenericErrorCodesNoGameModeParamsSet) output = web::json::value(L"NoGameModeParamsSet");
            if (input == GenericErrorCodesBodyTooLarge) output = web::json::value(L"BodyTooLarge");
            if (input == GenericErrorCodesReservedWordInBody) output = web::json::value(L"ReservedWordInBody");
            if (input == GenericErrorCodesInvalidTypeInBody) output = web::json::value(L"InvalidTypeInBody");
            if (input == GenericErrorCodesInvalidRequest) output = web::json::value(L"InvalidRequest");
            if (input == GenericErrorCodesReservedEventName) output = web::json::value(L"ReservedEventName");
            if (input == GenericErrorCodesInvalidUserStatistics) output = web::json::value(L"InvalidUserStatistics");
            if (input == GenericErrorCodesNotAuthenticated) output = web::json::value(L"NotAuthenticated");
            if (input == GenericErrorCodesStreamAlreadyExists) output = web::json::value(L"StreamAlreadyExists");
            if (input == GenericErrorCodesErrorCreatingStream) output = web::json::value(L"ErrorCreatingStream");
            if (input == GenericErrorCodesStreamNotFound) output = web::json::value(L"StreamNotFound");
            if (input == GenericErrorCodesInvalidAccount) output = web::json::value(L"InvalidAccount");
            if (input == GenericErrorCodesPurchaseDoesNotExist) output = web::json::value(L"PurchaseDoesNotExist");
            if (input == GenericErrorCodesInvalidPurchaseTransactionStatus) output = web::json::value(L"InvalidPurchaseTransactionStatus");
            if (input == GenericErrorCodesAPINotEnabledForGameClientAccess) output = web::json::value(L"APINotEnabledForGameClientAccess");
            if (input == GenericErrorCodesNoPushNotificationARNForTitle) output = web::json::value(L"NoPushNotificationARNForTitle");
            if (input == GenericErrorCodesBuildAlreadyExists) output = web::json::value(L"BuildAlreadyExists");
            if (input == GenericErrorCodesBuildPackageDoesNotExist) output = web::json::value(L"BuildPackageDoesNotExist");
            if (input == GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle) output = web::json::value(L"CustomAnalyticsEventsNotEnabledForTitle");
            if (input == GenericErrorCodesInvalidSharedGroupId) output = web::json::value(L"InvalidSharedGroupId");
            if (input == GenericErrorCodesNotAuthorized) output = web::json::value(L"NotAuthorized");
            if (input == GenericErrorCodesMissingTitleGoogleProperties) output = web::json::value(L"MissingTitleGoogleProperties");
            if (input == GenericErrorCodesInvalidItemProperties) output = web::json::value(L"InvalidItemProperties");
            if (input == GenericErrorCodesInvalidPSNAuthCode) output = web::json::value(L"InvalidPSNAuthCode");
            if (input == GenericErrorCodesInvalidItemId) output = web::json::value(L"InvalidItemId");
            if (input == GenericErrorCodesPushNotEnabledForAccount) output = web::json::value(L"PushNotEnabledForAccount");
            if (input == GenericErrorCodesPushServiceError) output = web::json::value(L"PushServiceError");
            if (input == GenericErrorCodesReceiptDoesNotContainInAppItems) output = web::json::value(L"ReceiptDoesNotContainInAppItems");
            if (input == GenericErrorCodesReceiptContainsMultipleInAppItems) output = web::json::value(L"ReceiptContainsMultipleInAppItems");
            if (input == GenericErrorCodesInvalidBundleID) output = web::json::value(L"InvalidBundleID");
            if (input == GenericErrorCodesJavascriptException) output = web::json::value(L"JavascriptException");
            if (input == GenericErrorCodesInvalidSessionTicket) output = web::json::value(L"InvalidSessionTicket");
            if (input == GenericErrorCodesUnableToConnectToDatabase) output = web::json::value(L"UnableToConnectToDatabase");
            if (input == GenericErrorCodesInternalServerError) output = web::json::value(L"InternalServerError");
            if (input == GenericErrorCodesInvalidReportDate) output = web::json::value(L"InvalidReportDate");
            if (input == GenericErrorCodesReportNotAvailable) output = web::json::value(L"ReportNotAvailable");
            if (input == GenericErrorCodesDatabaseThroughputExceeded) output = web::json::value(L"DatabaseThroughputExceeded");
            if (input == GenericErrorCodesInvalidGameTicket) output = web::json::value(L"InvalidGameTicket");
            if (input == GenericErrorCodesExpiredGameTicket) output = web::json::value(L"ExpiredGameTicket");
            if (input == GenericErrorCodesGameTicketDoesNotMatchLobby) output = web::json::value(L"GameTicketDoesNotMatchLobby");
            if (input == GenericErrorCodesLinkedDeviceAlreadyClaimed) output = web::json::value(L"LinkedDeviceAlreadyClaimed");
            if (input == GenericErrorCodesDeviceAlreadyLinked) output = web::json::value(L"DeviceAlreadyLinked");
            if (input == GenericErrorCodesDeviceNotLinked) output = web::json::value(L"DeviceNotLinked");
            if (input == GenericErrorCodesPartialFailure) output = web::json::value(L"PartialFailure");
            if (input == GenericErrorCodesPublisherNotSet) output = web::json::value(L"PublisherNotSet");
            if (input == GenericErrorCodesServiceUnavailable) output = web::json::value(L"ServiceUnavailable");
            if (input == GenericErrorCodesVersionNotFound) output = web::json::value(L"VersionNotFound");
            if (input == GenericErrorCodesRevisionNotFound) output = web::json::value(L"RevisionNotFound");
            if (input == GenericErrorCodesInvalidPublisherId) output = web::json::value(L"InvalidPublisherId");
            if (input == GenericErrorCodesDownstreamServiceUnavailable) output = web::json::value(L"DownstreamServiceUnavailable");
            if (input == GenericErrorCodesAPINotIncludedInTitleUsageTier) output = web::json::value(L"APINotIncludedInTitleUsageTier");
            if (input == GenericErrorCodesDAULimitExceeded) output = web::json::value(L"DAULimitExceeded");
            if (input == GenericErrorCodesAPIRequestLimitExceeded) output = web::json::value(L"APIRequestLimitExceeded");
            if (input == GenericErrorCodesInvalidAPIEndpoint) output = web::json::value(L"InvalidAPIEndpoint");
            if (input == GenericErrorCodesBuildNotAvailable) output = web::json::value(L"BuildNotAvailable");
            if (input == GenericErrorCodesConcurrentEditError) output = web::json::value(L"ConcurrentEditError");
            if (input == GenericErrorCodesContentNotFound) output = web::json::value(L"ContentNotFound");
            if (input == GenericErrorCodesCharacterNotFound) output = web::json::value(L"CharacterNotFound");
            if (input == GenericErrorCodesCloudScriptNotFound) output = web::json::value(L"CloudScriptNotFound");
            if (input == GenericErrorCodesContentQuotaExceeded) output = web::json::value(L"ContentQuotaExceeded");
            if (input == GenericErrorCodesInvalidCharacterStatistics) output = web::json::value(L"InvalidCharacterStatistics");
            if (input == GenericErrorCodesPhotonNotEnabledForTitle) output = web::json::value(L"PhotonNotEnabledForTitle");
            if (input == GenericErrorCodesPhotonApplicationNotFound) output = web::json::value(L"PhotonApplicationNotFound");
            if (input == GenericErrorCodesPhotonApplicationNotAssociatedWithTitle) output = web::json::value(L"PhotonApplicationNotAssociatedWithTitle");
            if (input == GenericErrorCodesInvalidEmailOrPassword) output = web::json::value(L"InvalidEmailOrPassword");
            if (input == GenericErrorCodesFacebookAPIError) output = web::json::value(L"FacebookAPIError");
            if (input == GenericErrorCodesInvalidContentType) output = web::json::value(L"InvalidContentType");
            if (input == GenericErrorCodesKeyLengthExceeded) output = web::json::value(L"KeyLengthExceeded");
            if (input == GenericErrorCodesDataLengthExceeded) output = web::json::value(L"DataLengthExceeded");
            if (input == GenericErrorCodesTooManyKeys) output = web::json::value(L"TooManyKeys");
            if (input == GenericErrorCodesFreeTierCannotHaveVirtualCurrency) output = web::json::value(L"FreeTierCannotHaveVirtualCurrency");
            if (input == GenericErrorCodesMissingAmazonSharedKey) output = web::json::value(L"MissingAmazonSharedKey");
            if (input == GenericErrorCodesAmazonValidationError) output = web::json::value(L"AmazonValidationError");
            if (input == GenericErrorCodesInvalidPSNIssuerId) output = web::json::value(L"InvalidPSNIssuerId");
            if (input == GenericErrorCodesPSNInaccessible) output = web::json::value(L"PSNInaccessible");
            if (input == GenericErrorCodesExpiredAuthToken) output = web::json::value(L"ExpiredAuthToken");
            if (input == GenericErrorCodesFailedToGetEntitlements) output = web::json::value(L"FailedToGetEntitlements");
            if (input == GenericErrorCodesFailedToConsumeEntitlement) output = web::json::value(L"FailedToConsumeEntitlement");
            if (input == GenericErrorCodesTradeAcceptingUserNotAllowed) output = web::json::value(L"TradeAcceptingUserNotAllowed");
            if (input == GenericErrorCodesTradeInventoryItemIsAssignedToCharacter) output = web::json::value(L"TradeInventoryItemIsAssignedToCharacter");
            if (input == GenericErrorCodesTradeInventoryItemIsBundle) output = web::json::value(L"TradeInventoryItemIsBundle");
            if (input == GenericErrorCodesTradeStatusNotValidForCancelling) output = web::json::value(L"TradeStatusNotValidForCancelling");
            if (input == GenericErrorCodesTradeStatusNotValidForAccepting) output = web::json::value(L"TradeStatusNotValidForAccepting");
            if (input == GenericErrorCodesTradeDoesNotExist) output = web::json::value(L"TradeDoesNotExist");
            if (input == GenericErrorCodesTradeCancelled) output = web::json::value(L"TradeCancelled");
            if (input == GenericErrorCodesTradeAlreadyFilled) output = web::json::value(L"TradeAlreadyFilled");
            if (input == GenericErrorCodesTradeWaitForStatusTimeout) output = web::json::value(L"TradeWaitForStatusTimeout");
            if (input == GenericErrorCodesTradeInventoryItemExpired) output = web::json::value(L"TradeInventoryItemExpired");
            if (input == GenericErrorCodesTradeMissingOfferedAndAcceptedItems) output = web::json::value(L"TradeMissingOfferedAndAcceptedItems");
            if (input == GenericErrorCodesTradeAcceptedItemIsBundle) output = web::json::value(L"TradeAcceptedItemIsBundle");
            if (input == GenericErrorCodesTradeAcceptedItemIsStackable) output = web::json::value(L"TradeAcceptedItemIsStackable");
            if (input == GenericErrorCodesTradeInventoryItemInvalidStatus) output = web::json::value(L"TradeInventoryItemInvalidStatus");
            if (input == GenericErrorCodesTradeAcceptedCatalogItemInvalid) output = web::json::value(L"TradeAcceptedCatalogItemInvalid");
            if (input == GenericErrorCodesTradeAllowedUsersInvalid) output = web::json::value(L"TradeAllowedUsersInvalid");
            if (input == GenericErrorCodesTradeInventoryItemDoesNotExist) output = web::json::value(L"TradeInventoryItemDoesNotExist");
            if (input == GenericErrorCodesTradeInventoryItemIsConsumed) output = web::json::value(L"TradeInventoryItemIsConsumed");
            if (input == GenericErrorCodesTradeInventoryItemIsStackable) output = web::json::value(L"TradeInventoryItemIsStackable");
            if (input == GenericErrorCodesTradeAcceptedItemsMismatch) output = web::json::value(L"TradeAcceptedItemsMismatch");
            if (input == GenericErrorCodesInvalidKongregateToken) output = web::json::value(L"InvalidKongregateToken");
            if (input == GenericErrorCodesFeatureNotConfiguredForTitle) output = web::json::value(L"FeatureNotConfiguredForTitle");
            if (input == GenericErrorCodesNoMatchingCatalogItemForReceipt) output = web::json::value(L"NoMatchingCatalogItemForReceipt");
            if (input == GenericErrorCodesInvalidCurrencyCode) output = web::json::value(L"InvalidCurrencyCode");
            if (input == GenericErrorCodesNoRealMoneyPriceForCatalogItem) output = web::json::value(L"NoRealMoneyPriceForCatalogItem");
            if (input == GenericErrorCodesTradeInventoryItemIsNotTradable) output = web::json::value(L"TradeInventoryItemIsNotTradable");
            if (input == GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable) output = web::json::value(L"TradeAcceptedCatalogItemIsNotTradable");
            if (input == GenericErrorCodesUsersAlreadyFriends) output = web::json::value(L"UsersAlreadyFriends");
            if (input == GenericErrorCodesLinkedIdentifierAlreadyClaimed) output = web::json::value(L"LinkedIdentifierAlreadyClaimed");
            if (input == GenericErrorCodesCustomIdNotLinked) output = web::json::value(L"CustomIdNotLinked");
            if (input == GenericErrorCodesTotalDataSizeExceeded) output = web::json::value(L"TotalDataSizeExceeded");
            if (input == GenericErrorCodesDeleteKeyConflict) output = web::json::value(L"DeleteKeyConflict");
            if (input == GenericErrorCodesInvalidXboxLiveToken) output = web::json::value(L"InvalidXboxLiveToken");
            if (input == GenericErrorCodesExpiredXboxLiveToken) output = web::json::value(L"ExpiredXboxLiveToken");
            if (input == GenericErrorCodesResettableStatisticVersionRequired) output = web::json::value(L"ResettableStatisticVersionRequired");
            if (input == GenericErrorCodesNotAuthorizedByTitle) output = web::json::value(L"NotAuthorizedByTitle");
            if (input == GenericErrorCodesNoPartnerEnabled) output = web::json::value(L"NoPartnerEnabled");
            if (input == GenericErrorCodesInvalidPartnerResponse) output = web::json::value(L"InvalidPartnerResponse");
            if (input == GenericErrorCodesAPINotEnabledForGameServerAccess) output = web::json::value(L"APINotEnabledForGameServerAccess");
            if (input == GenericErrorCodesStatisticNotFound) output = web::json::value(L"StatisticNotFound");
            if (input == GenericErrorCodesStatisticNameConflict) output = web::json::value(L"StatisticNameConflict");
            if (input == GenericErrorCodesStatisticVersionClosedForWrites) output = web::json::value(L"StatisticVersionClosedForWrites");
            if (input == GenericErrorCodesStatisticVersionInvalid) output = web::json::value(L"StatisticVersionInvalid");
            if (input == GenericErrorCodesAPIClientRequestRateLimitExceeded) output = web::json::value(L"APIClientRequestRateLimitExceeded");
            if (input == GenericErrorCodesInvalidJSONContent) output = web::json::value(L"InvalidJSONContent");
            if (input == GenericErrorCodesInvalidDropTable) output = web::json::value(L"InvalidDropTable");
            if (input == GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval) output = web::json::value(L"StatisticVersionAlreadyIncrementedForScheduledInterval");
            if (input == GenericErrorCodesStatisticCountLimitExceeded) output = web::json::value(L"StatisticCountLimitExceeded");
            if (input == GenericErrorCodesStatisticVersionIncrementRateExceeded) output = web::json::value(L"StatisticVersionIncrementRateExceeded");
            if (input == GenericErrorCodesContainerKeyInvalid) output = web::json::value(L"ContainerKeyInvalid");
            if (input == GenericErrorCodesCloudScriptExecutionTimeLimitExceeded) output = web::json::value(L"CloudScriptExecutionTimeLimitExceeded");
            if (input == GenericErrorCodesNoWritePermissionsForEvent) output = web::json::value(L"NoWritePermissionsForEvent");
            if (input == GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded) output = web::json::value(L"CloudScriptFunctionArgumentSizeExceeded");
            if (input == GenericErrorCodesCloudScriptAPIRequestCountExceeded) output = web::json::value(L"CloudScriptAPIRequestCountExceeded");
            if (input == GenericErrorCodesCloudScriptAPIRequestError) output = web::json::value(L"CloudScriptAPIRequestError");
            if (input == GenericErrorCodesCloudScriptHTTPRequestError) output = web::json::value(L"CloudScriptHTTPRequestError");
            if (input == GenericErrorCodesInsufficientGuildRole) output = web::json::value(L"InsufficientGuildRole");
            if (input == GenericErrorCodesGuildNotFound) output = web::json::value(L"GuildNotFound");
            if (input == GenericErrorCodesOverLimit) output = web::json::value(L"OverLimit");
            if (input == GenericErrorCodesEventNotFound) output = web::json::value(L"EventNotFound");
            if (input == GenericErrorCodesInvalidEventField) output = web::json::value(L"InvalidEventField");
            if (input == GenericErrorCodesInvalidEventName) output = web::json::value(L"InvalidEventName");
            if (input == GenericErrorCodesCatalogNotConfigured) output = web::json::value(L"CatalogNotConfigured");
            if (input == GenericErrorCodesOperationNotSupportedForPlatform) output = web::json::value(L"OperationNotSupportedForPlatform");
            if (input == GenericErrorCodesSegmentNotFound) output = web::json::value(L"SegmentNotFound");
            if (input == GenericErrorCodesStoreNotFound) output = web::json::value(L"StoreNotFound");
            if (input == GenericErrorCodesInvalidStatisticName) output = web::json::value(L"InvalidStatisticName");
            if (input == GenericErrorCodesTitleNotQualifiedForLimit) output = web::json::value(L"TitleNotQualifiedForLimit");
            if (input == GenericErrorCodesInvalidServiceLimitLevel) output = web::json::value(L"InvalidServiceLimitLevel");
            if (input == GenericErrorCodesServiceLimitLevelInTransition) output = web::json::value(L"ServiceLimitLevelInTransition");
            if (input == GenericErrorCodesCouponAlreadyRedeemed) output = web::json::value(L"CouponAlreadyRedeemed");
            if (input == GenericErrorCodesGameServerBuildSizeLimitExceeded) output = web::json::value(L"GameServerBuildSizeLimitExceeded");
            if (input == GenericErrorCodesGameServerBuildCountLimitExceeded) output = web::json::value(L"GameServerBuildCountLimitExceeded");
            if (input == GenericErrorCodesVirtualCurrencyCountLimitExceeded) output = web::json::value(L"VirtualCurrencyCountLimitExceeded");
            if (input == GenericErrorCodesVirtualCurrencyCodeExists) output = web::json::value(L"VirtualCurrencyCodeExists");
            if (input == GenericErrorCodesTitleNewsItemCountLimitExceeded) output = web::json::value(L"TitleNewsItemCountLimitExceeded");
            if (input == GenericErrorCodesInvalidTwitchToken) output = web::json::value(L"InvalidTwitchToken");
            if (input == GenericErrorCodesTwitchResponseError) output = web::json::value(L"TwitchResponseError");
            if (input == GenericErrorCodesProfaneDisplayName) output = web::json::value(L"ProfaneDisplayName");
            if (input == GenericErrorCodesUserAlreadyAdded) output = web::json::value(L"UserAlreadyAdded");
            if (input == GenericErrorCodesInvalidVirtualCurrencyCode) output = web::json::value(L"InvalidVirtualCurrencyCode");
            if (input == GenericErrorCodesVirtualCurrencyCannotBeDeleted) output = web::json::value(L"VirtualCurrencyCannotBeDeleted");
            if (input == GenericErrorCodesIdentifierAlreadyClaimed) output = web::json::value(L"IdentifierAlreadyClaimed");
            if (input == GenericErrorCodesIdentifierNotLinked) output = web::json::value(L"IdentifierNotLinked");
            if (input == GenericErrorCodesInvalidContinuationToken) output = web::json::value(L"InvalidContinuationToken");
            if (input == GenericErrorCodesExpiredContinuationToken) output = web::json::value(L"ExpiredContinuationToken");
            if (input == GenericErrorCodesInvalidSegment) output = web::json::value(L"InvalidSegment");
            if (input == GenericErrorCodesInvalidSessionId) output = web::json::value(L"InvalidSessionId");
            if (input == GenericErrorCodesSessionLogNotFound) output = web::json::value(L"SessionLogNotFound");
            if (input == GenericErrorCodesInvalidSearchTerm) output = web::json::value(L"InvalidSearchTerm");
            if (input == GenericErrorCodesTwoFactorAuthenticationTokenRequired) output = web::json::value(L"TwoFactorAuthenticationTokenRequired");
            if (input == GenericErrorCodesGameServerHostCountLimitExceeded) output = web::json::value(L"GameServerHostCountLimitExceeded");
            if (input == GenericErrorCodesPlayerTagCountLimitExceeded) output = web::json::value(L"PlayerTagCountLimitExceeded");
            if (input == GenericErrorCodesRequestAlreadyRunning) output = web::json::value(L"RequestAlreadyRunning");
            if (input == GenericErrorCodesActionGroupNotFound) output = web::json::value(L"ActionGroupNotFound");
            if (input == GenericErrorCodesMaximumSegmentBulkActionJobsRunning) output = web::json::value(L"MaximumSegmentBulkActionJobsRunning");
            if (input == GenericErrorCodesNoActionsOnPlayersInSegmentJob) output = web::json::value(L"NoActionsOnPlayersInSegmentJob");
            if (input == GenericErrorCodesDuplicateStatisticName) output = web::json::value(L"DuplicateStatisticName");
            if (input == GenericErrorCodesScheduledTaskNameConflict) output = web::json::value(L"ScheduledTaskNameConflict");
            if (input == GenericErrorCodesScheduledTaskCreateConflict) output = web::json::value(L"ScheduledTaskCreateConflict");
            if (input == GenericErrorCodesInvalidScheduledTaskName) output = web::json::value(L"InvalidScheduledTaskName");
            if (input == GenericErrorCodesInvalidTaskSchedule) output = web::json::value(L"InvalidTaskSchedule");
            if (input == GenericErrorCodesSteamNotEnabledForTitle) output = web::json::value(L"SteamNotEnabledForTitle");
            if (input == GenericErrorCodesLimitNotAnUpgradeOption) output = web::json::value(L"LimitNotAnUpgradeOption");
            if (input == GenericErrorCodesNoSecretKeyEnabledForCloudScript) output = web::json::value(L"NoSecretKeyEnabledForCloudScript");
            if (input == GenericErrorCodesTaskNotFound) output = web::json::value(L"TaskNotFound");
            if (input == GenericErrorCodesTaskInstanceNotFound) output = web::json::value(L"TaskInstanceNotFound");
            if (input == GenericErrorCodesInvalidIdentityProviderId) output = web::json::value(L"InvalidIdentityProviderId");
            if (input == GenericErrorCodesMisconfiguredIdentityProvider) output = web::json::value(L"MisconfiguredIdentityProvider");
            if (input == GenericErrorCodesInvalidScheduledTaskType) output = web::json::value(L"InvalidScheduledTaskType");
            if (input == GenericErrorCodesBillingInformationRequired) output = web::json::value(L"BillingInformationRequired");
            if (input == GenericErrorCodesLimitedEditionItemUnavailable) output = web::json::value(L"LimitedEditionItemUnavailable");
            if (input == GenericErrorCodesInvalidAdPlacementAndReward) output = web::json::value(L"InvalidAdPlacementAndReward");
            if (input == GenericErrorCodesAllAdPlacementViewsAlreadyConsumed) output = web::json::value(L"AllAdPlacementViewsAlreadyConsumed");
            if (input == GenericErrorCodesGoogleOAuthNotConfiguredForTitle) output = web::json::value(L"GoogleOAuthNotConfiguredForTitle");
            if (input == GenericErrorCodesGoogleOAuthError) output = web::json::value(L"GoogleOAuthError");
            if (input == GenericErrorCodesUserNotFriend) output = web::json::value(L"UserNotFriend");
            if (input == GenericErrorCodesInvalidSignature) output = web::json::value(L"InvalidSignature");
            if (input == GenericErrorCodesInvalidPublicKey) output = web::json::value(L"InvalidPublicKey");
            if (input == GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse) output = web::json::value(L"GoogleOAuthNoIdTokenIncludedInResponse");
            if (input == GenericErrorCodesStatisticUpdateInProgress) output = web::json::value(L"StatisticUpdateInProgress");
            if (input == GenericErrorCodesLeaderboardVersionNotAvailable) output = web::json::value(L"LeaderboardVersionNotAvailable");
            if (input == GenericErrorCodesStatisticAlreadyHasPrizeTable) output = web::json::value(L"StatisticAlreadyHasPrizeTable");
            if (input == GenericErrorCodesPrizeTableHasOverlappingRanks) output = web::json::value(L"PrizeTableHasOverlappingRanks");
            if (input == GenericErrorCodesPrizeTableHasMissingRanks) output = web::json::value(L"PrizeTableHasMissingRanks");
            if (input == GenericErrorCodesPrizeTableRankStartsAtZero) output = web::json::value(L"PrizeTableRankStartsAtZero");
            if (input == GenericErrorCodesInvalidStatistic) output = web::json::value(L"InvalidStatistic");
            if (input == GenericErrorCodesExpressionParseFailure) output = web::json::value(L"ExpressionParseFailure");
            if (input == GenericErrorCodesExpressionInvokeFailure) output = web::json::value(L"ExpressionInvokeFailure");
            if (input == GenericErrorCodesExpressionTooLong) output = web::json::value(L"ExpressionTooLong");
            if (input == GenericErrorCodesDataUpdateRateExceeded) output = web::json::value(L"DataUpdateRateExceeded");
            if (input == GenericErrorCodesRestrictedEmailDomain) output = web::json::value(L"RestrictedEmailDomain");
            if (input == GenericErrorCodesEncryptionKeyDisabled) output = web::json::value(L"EncryptionKeyDisabled");
            if (input == GenericErrorCodesEncryptionKeyMissing) output = web::json::value(L"EncryptionKeyMissing");
            if (input == GenericErrorCodesEncryptionKeyBroken) output = web::json::value(L"EncryptionKeyBroken");
            if (input == GenericErrorCodesNoSharedSecretKeyConfigured) output = web::json::value(L"NoSharedSecretKeyConfigured");
            if (input == GenericErrorCodesSecretKeyNotFound) output = web::json::value(L"SecretKeyNotFound");
            if (input == GenericErrorCodesPlayerSecretAlreadyConfigured) output = web::json::value(L"PlayerSecretAlreadyConfigured");
            if (input == GenericErrorCodesAPIRequestsDisabledForTitle) output = web::json::value(L"APIRequestsDisabledForTitle");
            if (input == GenericErrorCodesInvalidSharedSecretKey) output = web::json::value(L"InvalidSharedSecretKey");
            if (input == GenericErrorCodesPrizeTableHasNoRanks) output = web::json::value(L"PrizeTableHasNoRanks");
            if (input == GenericErrorCodesProfileDoesNotExist) output = web::json::value(L"ProfileDoesNotExist");
            if (input == GenericErrorCodesContentS3OriginBucketNotConfigured) output = web::json::value(L"ContentS3OriginBucketNotConfigured");
            if (input == GenericErrorCodesInvalidEnvironmentForReceipt) output = web::json::value(L"InvalidEnvironmentForReceipt");
            if (input == GenericErrorCodesEncryptedRequestNotAllowed) output = web::json::value(L"EncryptedRequestNotAllowed");
            if (input == GenericErrorCodesSignedRequestNotAllowed) output = web::json::value(L"SignedRequestNotAllowed");
            if (input == GenericErrorCodesRequestViewConstraintParamsNotAllowed) output = web::json::value(L"RequestViewConstraintParamsNotAllowed");
            if (input == GenericErrorCodesBadPartnerConfiguration) output = web::json::value(L"BadPartnerConfiguration");
            if (input == GenericErrorCodesXboxBPCertificateFailure) output = web::json::value(L"XboxBPCertificateFailure");
            if (input == GenericErrorCodesXboxXASSExchangeFailure) output = web::json::value(L"XboxXASSExchangeFailure");
            if (input == GenericErrorCodesInvalidEntityId) output = web::json::value(L"InvalidEntityId");
            if (input == GenericErrorCodesStatisticValueAggregationOverflow) output = web::json::value(L"StatisticValueAggregationOverflow");
            if (input == GenericErrorCodesEmailMessageFromAddressIsMissing) output = web::json::value(L"EmailMessageFromAddressIsMissing");
            if (input == GenericErrorCodesEmailMessageToAddressIsMissing) output = web::json::value(L"EmailMessageToAddressIsMissing");
            if (input == GenericErrorCodesSmtpServerAuthenticationError) output = web::json::value(L"SmtpServerAuthenticationError");
            if (input == GenericErrorCodesSmtpServerLimitExceeded) output = web::json::value(L"SmtpServerLimitExceeded");
            if (input == GenericErrorCodesSmtpServerInsufficientStorage) output = web::json::value(L"SmtpServerInsufficientStorage");
            if (input == GenericErrorCodesSmtpServerCommunicationError) output = web::json::value(L"SmtpServerCommunicationError");
            if (input == GenericErrorCodesSmtpServerGeneralFailure) output = web::json::value(L"SmtpServerGeneralFailure");
            if (input == GenericErrorCodesEmailClientTimeout) output = web::json::value(L"EmailClientTimeout");
            if (input == GenericErrorCodesEmailClientCanceledTask) output = web::json::value(L"EmailClientCanceledTask");
            if (input == GenericErrorCodesEmailTemplateMissing) output = web::json::value(L"EmailTemplateMissing");
            if (input == GenericErrorCodesInvalidHostForTitleId) output = web::json::value(L"InvalidHostForTitleId");
            if (input == GenericErrorCodesEmailConfirmationTokenDoesNotExist) output = web::json::value(L"EmailConfirmationTokenDoesNotExist");
            if (input == GenericErrorCodesEmailConfirmationTokenExpired) output = web::json::value(L"EmailConfirmationTokenExpired");
            if (input == GenericErrorCodesAccountDeleted) output = web::json::value(L"AccountDeleted");
            if (input == GenericErrorCodesPlayerSecretNotConfigured) output = web::json::value(L"PlayerSecretNotConfigured");
            if (input == GenericErrorCodesInvalidSignatureTime) output = web::json::value(L"InvalidSignatureTime");
            if (input == GenericErrorCodesNoContactEmailAddressFound) output = web::json::value(L"NoContactEmailAddressFound");
            if (input == GenericErrorCodesInvalidAuthToken) output = web::json::value(L"InvalidAuthToken");
            if (input == GenericErrorCodesAuthTokenDoesNotExist) output = web::json::value(L"AuthTokenDoesNotExist");
            if (input == GenericErrorCodesAuthTokenExpired) output = web::json::value(L"AuthTokenExpired");
            if (input == GenericErrorCodesAuthTokenAlreadyUsedToResetPassword) output = web::json::value(L"AuthTokenAlreadyUsedToResetPassword");
            if (input == GenericErrorCodesMembershipNameTooLong) output = web::json::value(L"MembershipNameTooLong");
            if (input == GenericErrorCodesMembershipNotFound) output = web::json::value(L"MembershipNotFound");
            if (input == GenericErrorCodesGoogleServiceAccountInvalid) output = web::json::value(L"GoogleServiceAccountInvalid");
            if (input == GenericErrorCodesGoogleServiceAccountParseFailure) output = web::json::value(L"GoogleServiceAccountParseFailure");
            if (input == GenericErrorCodesEntityTokenMissing) output = web::json::value(L"EntityTokenMissing");
            if (input == GenericErrorCodesEntityTokenInvalid) output = web::json::value(L"EntityTokenInvalid");
            if (input == GenericErrorCodesEntityTokenExpired) output = web::json::value(L"EntityTokenExpired");
            if (input == GenericErrorCodesEntityTokenRevoked) output = web::json::value(L"EntityTokenRevoked");
            if (input == GenericErrorCodesInvalidProductForSubscription) output = web::json::value(L"InvalidProductForSubscription");
            if (input == GenericErrorCodesXboxInaccessible) output = web::json::value(L"XboxInaccessible");
            if (input == GenericErrorCodesSubscriptionAlreadyTaken) output = web::json::value(L"SubscriptionAlreadyTaken");
            if (input == GenericErrorCodesSmtpAddonNotEnabled) output = web::json::value(L"SmtpAddonNotEnabled");
            if (input == GenericErrorCodesAPIConcurrentRequestLimitExceeded) output = web::json::value(L"APIConcurrentRequestLimitExceeded");
            if (input == GenericErrorCodesXboxRejectedXSTSExchangeRequest) output = web::json::value(L"XboxRejectedXSTSExchangeRequest");
            if (input == GenericErrorCodesVariableNotDefined) output = web::json::value(L"VariableNotDefined");
            if (input == GenericErrorCodesTemplateVersionNotDefined) output = web::json::value(L"TemplateVersionNotDefined");
            if (input == GenericErrorCodesFileTooLarge) output = web::json::value(L"FileTooLarge");
            if (input == GenericErrorCodesTitleDeleted) output = web::json::value(L"TitleDeleted");
            if (input == GenericErrorCodesTitleContainsUserAccounts) output = web::json::value(L"TitleContainsUserAccounts");
            if (input == GenericErrorCodesTitleDeletionPlayerCleanupFailure) output = web::json::value(L"TitleDeletionPlayerCleanupFailure");
            if (input == GenericErrorCodesEntityFileOperationPending) output = web::json::value(L"EntityFileOperationPending");
            if (input == GenericErrorCodesNoEntityFileOperationPending) output = web::json::value(L"NoEntityFileOperationPending");
            if (input == GenericErrorCodesEntityProfileVersionMismatch) output = web::json::value(L"EntityProfileVersionMismatch");
            if (input == GenericErrorCodesTemplateVersionTooOld) output = web::json::value(L"TemplateVersionTooOld");
            if (input == GenericErrorCodesMembershipDefinitionInUse) output = web::json::value(L"MembershipDefinitionInUse");
            if (input == GenericErrorCodesPaymentPageNotConfigured) output = web::json::value(L"PaymentPageNotConfigured");
            if (input == GenericErrorCodesFailedLoginAttemptRateLimitExceeded) output = web::json::value(L"FailedLoginAttemptRateLimitExceeded");
            if (input == GenericErrorCodesEntityBlockedByGroup) output = web::json::value(L"EntityBlockedByGroup");
            if (input == GenericErrorCodesRoleDoesNotExist) output = web::json::value(L"RoleDoesNotExist");
            if (input == GenericErrorCodesEntityIsAlreadyMember) output = web::json::value(L"EntityIsAlreadyMember");
            if (input == GenericErrorCodesDuplicateRoleId) output = web::json::value(L"DuplicateRoleId");
            if (input == GenericErrorCodesGroupInvitationNotFound) output = web::json::value(L"GroupInvitationNotFound");
            if (input == GenericErrorCodesGroupApplicationNotFound) output = web::json::value(L"GroupApplicationNotFound");
            if (input == GenericErrorCodesOutstandingInvitationAcceptedInstead) output = web::json::value(L"OutstandingInvitationAcceptedInstead");
            if (input == GenericErrorCodesOutstandingApplicationAcceptedInstead) output = web::json::value(L"OutstandingApplicationAcceptedInstead");
            if (input == GenericErrorCodesRoleIsGroupDefaultMember) output = web::json::value(L"RoleIsGroupDefaultMember");
            if (input == GenericErrorCodesRoleIsGroupAdmin) output = web::json::value(L"RoleIsGroupAdmin");
            if (input == GenericErrorCodesRoleNameNotAvailable) output = web::json::value(L"RoleNameNotAvailable");
            if (input == GenericErrorCodesGroupNameNotAvailable) output = web::json::value(L"GroupNameNotAvailable");
            if (input == GenericErrorCodesEmailReportAlreadySent) output = web::json::value(L"EmailReportAlreadySent");
            if (input == GenericErrorCodesEmailReportRecipientBlacklisted) output = web::json::value(L"EmailReportRecipientBlacklisted");
            if (input == GenericErrorCodesEventNamespaceNotAllowed) output = web::json::value(L"EventNamespaceNotAllowed");
            if (input == GenericErrorCodesEventEntityNotAllowed) output = web::json::value(L"EventEntityNotAllowed");
            if (input == GenericErrorCodesInvalidEntityType) output = web::json::value(L"InvalidEntityType");
            if (input == GenericErrorCodesNullTokenResultFromAad) output = web::json::value(L"NullTokenResultFromAad");
            if (input == GenericErrorCodesInvalidTokenResultFromAad) output = web::json::value(L"InvalidTokenResultFromAad");
            if (input == GenericErrorCodesNoValidCertificateForAad) output = web::json::value(L"NoValidCertificateForAad");
            if (input == GenericErrorCodesInvalidCertificateForAad) output = web::json::value(L"InvalidCertificateForAad");
            if (input == GenericErrorCodesDuplicateDropTableId) output = web::json::value(L"DuplicateDropTableId");
            if (input == GenericErrorCodesGameServerOk) output = web::json::value(L"GameServerOk");
            if (input == GenericErrorCodesGameServerAccepted) output = web::json::value(L"GameServerAccepted");
            if (input == GenericErrorCodesGameServerNoContent) output = web::json::value(L"GameServerNoContent");
            if (input == GenericErrorCodesGameServerBadRequest) output = web::json::value(L"GameServerBadRequest");
            if (input == GenericErrorCodesGameServerUnauthorized) output = web::json::value(L"GameServerUnauthorized");
            if (input == GenericErrorCodesGameServerForbidden) output = web::json::value(L"GameServerForbidden");
            if (input == GenericErrorCodesGameServerNotFound) output = web::json::value(L"GameServerNotFound");
            if (input == GenericErrorCodesGameServerConflict) output = web::json::value(L"GameServerConflict");
            if (input == GenericErrorCodesGameServerInternalServerError) output = web::json::value(L"GameServerInternalServerError");
            if (input == GenericErrorCodesGameServerServiceUnavailable) output = web::json::value(L"GameServerServiceUnavailable");
            if (input == GenericErrorCodesExplicitContentDetected) output = web::json::value(L"ExplicitContentDetected");
            if (input == GenericErrorCodesPIIContentDetected) output = web::json::value(L"PIIContentDetected");
            if (input == GenericErrorCodesInvalidScheduledTaskParameter) output = web::json::value(L"InvalidScheduledTaskParameter");
            if (input == GenericErrorCodesPerEntityEventRateLimitExceeded) output = web::json::value(L"PerEntityEventRateLimitExceeded");
            if (input == GenericErrorCodesTitleDefaultLanguageNotSet) output = web::json::value(L"TitleDefaultLanguageNotSet");
            if (input == GenericErrorCodesEmailTemplateMissingDefaultVersion) output = web::json::value(L"EmailTemplateMissingDefaultVersion");
            if (input == GenericErrorCodesFacebookInstantGamesIdNotLinked) output = web::json::value(L"FacebookInstantGamesIdNotLinked");
            if (input == GenericErrorCodesInvalidFacebookInstantGamesSignature) output = web::json::value(L"InvalidFacebookInstantGamesSignature");
            if (input == GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle) output = web::json::value(L"FacebookInstantGamesAuthNotConfiguredForTitle");
            if (input == GenericErrorCodesMatchmakingEntityInvalid) output = web::json::value(L"MatchmakingEntityInvalid");
            if (input == GenericErrorCodesMatchmakingPlayerAttributesInvalid) output = web::json::value(L"MatchmakingPlayerAttributesInvalid");
            if (input == GenericErrorCodesMatchmakingCreateRequestMissing) output = web::json::value(L"MatchmakingCreateRequestMissing");
            if (input == GenericErrorCodesMatchmakingCreateRequestCreatorMissing) output = web::json::value(L"MatchmakingCreateRequestCreatorMissing");
            if (input == GenericErrorCodesMatchmakingCreateRequestCreatorIdMissing) output = web::json::value(L"MatchmakingCreateRequestCreatorIdMissing");
            if (input == GenericErrorCodesMatchmakingCreateRequestUserListMissing) output = web::json::value(L"MatchmakingCreateRequestUserListMissing");
            if (input == GenericErrorCodesMatchmakingCreateRequestGiveUpAfterInvalid) output = web::json::value(L"MatchmakingCreateRequestGiveUpAfterInvalid");
            if (input == GenericErrorCodesMatchmakingTicketIdMissing) output = web::json::value(L"MatchmakingTicketIdMissing");
            if (input == GenericErrorCodesMatchmakingMatchIdMissing) output = web::json::value(L"MatchmakingMatchIdMissing");
            if (input == GenericErrorCodesMatchmakingMatchIdIdMissing) output = web::json::value(L"MatchmakingMatchIdIdMissing");
            if (input == GenericErrorCodesMatchmakingQueueNameMissing) output = web::json::value(L"MatchmakingQueueNameMissing");
            if (input == GenericErrorCodesMatchmakingTitleIdMissing) output = web::json::value(L"MatchmakingTitleIdMissing");
            if (input == GenericErrorCodesMatchmakingTicketIdIdMissing) output = web::json::value(L"MatchmakingTicketIdIdMissing");
            if (input == GenericErrorCodesMatchmakingPlayerIdMissing) output = web::json::value(L"MatchmakingPlayerIdMissing");
            if (input == GenericErrorCodesMatchmakingJoinRequestUserMissing) output = web::json::value(L"MatchmakingJoinRequestUserMissing");
            if (input == GenericErrorCodesMatchmakingQueueConfigNotFound) output = web::json::value(L"MatchmakingQueueConfigNotFound");
            if (input == GenericErrorCodesMatchmakingMatchNotFound) output = web::json::value(L"MatchmakingMatchNotFound");
            if (input == GenericErrorCodesMatchmakingTicketNotFound) output = web::json::value(L"MatchmakingTicketNotFound");
            if (input == GenericErrorCodesMatchmakingCreateTicketServerIdentityInvalid) output = web::json::value(L"MatchmakingCreateTicketServerIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingCreateTicketClientIdentityInvalid) output = web::json::value(L"MatchmakingCreateTicketClientIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingGetTicketUserMismatch) output = web::json::value(L"MatchmakingGetTicketUserMismatch");
            if (input == GenericErrorCodesMatchmakingJoinTicketServerIdentityInvalid) output = web::json::value(L"MatchmakingJoinTicketServerIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingJoinTicketUserIdentityMismatch) output = web::json::value(L"MatchmakingJoinTicketUserIdentityMismatch");
            if (input == GenericErrorCodesMatchmakingCancelTicketServerIdentityInvalid) output = web::json::value(L"MatchmakingCancelTicketServerIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingCancelTicketUserIdentityMismatch) output = web::json::value(L"MatchmakingCancelTicketUserIdentityMismatch");
            if (input == GenericErrorCodesMatchmakingGetMatchIdentityMismatch) output = web::json::value(L"MatchmakingGetMatchIdentityMismatch");
            if (input == GenericErrorCodesMatchmakingPlayerIdentityMismatch) output = web::json::value(L"MatchmakingPlayerIdentityMismatch");
            if (input == GenericErrorCodesMatchmakingAlreadyJoinedTicket) output = web::json::value(L"MatchmakingAlreadyJoinedTicket");
            if (input == GenericErrorCodesMatchmakingTicketAlreadyCompleted) output = web::json::value(L"MatchmakingTicketAlreadyCompleted");
            if (input == GenericErrorCodesMatchmakingQueueNameInvalid) output = web::json::value(L"MatchmakingQueueNameInvalid");
            if (input == GenericErrorCodesMatchmakingQueueConfigInvalid) output = web::json::value(L"MatchmakingQueueConfigInvalid");
            if (input == GenericErrorCodesMatchmakingMemberProfileInvalid) output = web::json::value(L"MatchmakingMemberProfileInvalid");
            if (input == GenericErrorCodesWriteAttemptedDuringExport) output = web::json::value(L"WriteAttemptedDuringExport");
            if (input == GenericErrorCodesNintendoSwitchDeviceIdNotLinked) output = web::json::value(L"NintendoSwitchDeviceIdNotLinked");
            if (input == GenericErrorCodesMatchmakingNotEnabled) output = web::json::value(L"MatchmakingNotEnabled");
        }
        inline void FromJsonEnum(const web::json::value& input, GenericErrorCodes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Success") output = GenericErrorCodesSuccess;
            if (inputStr == L"UnkownError") output = GenericErrorCodesUnkownError;
            if (inputStr == L"InvalidParams") output = GenericErrorCodesInvalidParams;
            if (inputStr == L"AccountNotFound") output = GenericErrorCodesAccountNotFound;
            if (inputStr == L"AccountBanned") output = GenericErrorCodesAccountBanned;
            if (inputStr == L"InvalidUsernameOrPassword") output = GenericErrorCodesInvalidUsernameOrPassword;
            if (inputStr == L"InvalidTitleId") output = GenericErrorCodesInvalidTitleId;
            if (inputStr == L"InvalidEmailAddress") output = GenericErrorCodesInvalidEmailAddress;
            if (inputStr == L"EmailAddressNotAvailable") output = GenericErrorCodesEmailAddressNotAvailable;
            if (inputStr == L"InvalidUsername") output = GenericErrorCodesInvalidUsername;
            if (inputStr == L"InvalidPassword") output = GenericErrorCodesInvalidPassword;
            if (inputStr == L"UsernameNotAvailable") output = GenericErrorCodesUsernameNotAvailable;
            if (inputStr == L"InvalidSteamTicket") output = GenericErrorCodesInvalidSteamTicket;
            if (inputStr == L"AccountAlreadyLinked") output = GenericErrorCodesAccountAlreadyLinked;
            if (inputStr == L"LinkedAccountAlreadyClaimed") output = GenericErrorCodesLinkedAccountAlreadyClaimed;
            if (inputStr == L"InvalidFacebookToken") output = GenericErrorCodesInvalidFacebookToken;
            if (inputStr == L"AccountNotLinked") output = GenericErrorCodesAccountNotLinked;
            if (inputStr == L"FailedByPaymentProvider") output = GenericErrorCodesFailedByPaymentProvider;
            if (inputStr == L"CouponCodeNotFound") output = GenericErrorCodesCouponCodeNotFound;
            if (inputStr == L"InvalidContainerItem") output = GenericErrorCodesInvalidContainerItem;
            if (inputStr == L"ContainerNotOwned") output = GenericErrorCodesContainerNotOwned;
            if (inputStr == L"KeyNotOwned") output = GenericErrorCodesKeyNotOwned;
            if (inputStr == L"InvalidItemIdInTable") output = GenericErrorCodesInvalidItemIdInTable;
            if (inputStr == L"InvalidReceipt") output = GenericErrorCodesInvalidReceipt;
            if (inputStr == L"ReceiptAlreadyUsed") output = GenericErrorCodesReceiptAlreadyUsed;
            if (inputStr == L"ReceiptCancelled") output = GenericErrorCodesReceiptCancelled;
            if (inputStr == L"GameNotFound") output = GenericErrorCodesGameNotFound;
            if (inputStr == L"GameModeNotFound") output = GenericErrorCodesGameModeNotFound;
            if (inputStr == L"InvalidGoogleToken") output = GenericErrorCodesInvalidGoogleToken;
            if (inputStr == L"UserIsNotPartOfDeveloper") output = GenericErrorCodesUserIsNotPartOfDeveloper;
            if (inputStr == L"InvalidTitleForDeveloper") output = GenericErrorCodesInvalidTitleForDeveloper;
            if (inputStr == L"TitleNameConflicts") output = GenericErrorCodesTitleNameConflicts;
            if (inputStr == L"UserisNotValid") output = GenericErrorCodesUserisNotValid;
            if (inputStr == L"ValueAlreadyExists") output = GenericErrorCodesValueAlreadyExists;
            if (inputStr == L"BuildNotFound") output = GenericErrorCodesBuildNotFound;
            if (inputStr == L"PlayerNotInGame") output = GenericErrorCodesPlayerNotInGame;
            if (inputStr == L"InvalidTicket") output = GenericErrorCodesInvalidTicket;
            if (inputStr == L"InvalidDeveloper") output = GenericErrorCodesInvalidDeveloper;
            if (inputStr == L"InvalidOrderInfo") output = GenericErrorCodesInvalidOrderInfo;
            if (inputStr == L"RegistrationIncomplete") output = GenericErrorCodesRegistrationIncomplete;
            if (inputStr == L"InvalidPlatform") output = GenericErrorCodesInvalidPlatform;
            if (inputStr == L"UnknownError") output = GenericErrorCodesUnknownError;
            if (inputStr == L"SteamApplicationNotOwned") output = GenericErrorCodesSteamApplicationNotOwned;
            if (inputStr == L"WrongSteamAccount") output = GenericErrorCodesWrongSteamAccount;
            if (inputStr == L"TitleNotActivated") output = GenericErrorCodesTitleNotActivated;
            if (inputStr == L"RegistrationSessionNotFound") output = GenericErrorCodesRegistrationSessionNotFound;
            if (inputStr == L"NoSuchMod") output = GenericErrorCodesNoSuchMod;
            if (inputStr == L"FileNotFound") output = GenericErrorCodesFileNotFound;
            if (inputStr == L"DuplicateEmail") output = GenericErrorCodesDuplicateEmail;
            if (inputStr == L"ItemNotFound") output = GenericErrorCodesItemNotFound;
            if (inputStr == L"ItemNotOwned") output = GenericErrorCodesItemNotOwned;
            if (inputStr == L"ItemNotRecycleable") output = GenericErrorCodesItemNotRecycleable;
            if (inputStr == L"ItemNotAffordable") output = GenericErrorCodesItemNotAffordable;
            if (inputStr == L"InvalidVirtualCurrency") output = GenericErrorCodesInvalidVirtualCurrency;
            if (inputStr == L"WrongVirtualCurrency") output = GenericErrorCodesWrongVirtualCurrency;
            if (inputStr == L"WrongPrice") output = GenericErrorCodesWrongPrice;
            if (inputStr == L"NonPositiveValue") output = GenericErrorCodesNonPositiveValue;
            if (inputStr == L"InvalidRegion") output = GenericErrorCodesInvalidRegion;
            if (inputStr == L"RegionAtCapacity") output = GenericErrorCodesRegionAtCapacity;
            if (inputStr == L"ServerFailedToStart") output = GenericErrorCodesServerFailedToStart;
            if (inputStr == L"NameNotAvailable") output = GenericErrorCodesNameNotAvailable;
            if (inputStr == L"InsufficientFunds") output = GenericErrorCodesInsufficientFunds;
            if (inputStr == L"InvalidDeviceID") output = GenericErrorCodesInvalidDeviceID;
            if (inputStr == L"InvalidPushNotificationToken") output = GenericErrorCodesInvalidPushNotificationToken;
            if (inputStr == L"NoRemainingUses") output = GenericErrorCodesNoRemainingUses;
            if (inputStr == L"InvalidPaymentProvider") output = GenericErrorCodesInvalidPaymentProvider;
            if (inputStr == L"PurchaseInitializationFailure") output = GenericErrorCodesPurchaseInitializationFailure;
            if (inputStr == L"DuplicateUsername") output = GenericErrorCodesDuplicateUsername;
            if (inputStr == L"InvalidBuyerInfo") output = GenericErrorCodesInvalidBuyerInfo;
            if (inputStr == L"NoGameModeParamsSet") output = GenericErrorCodesNoGameModeParamsSet;
            if (inputStr == L"BodyTooLarge") output = GenericErrorCodesBodyTooLarge;
            if (inputStr == L"ReservedWordInBody") output = GenericErrorCodesReservedWordInBody;
            if (inputStr == L"InvalidTypeInBody") output = GenericErrorCodesInvalidTypeInBody;
            if (inputStr == L"InvalidRequest") output = GenericErrorCodesInvalidRequest;
            if (inputStr == L"ReservedEventName") output = GenericErrorCodesReservedEventName;
            if (inputStr == L"InvalidUserStatistics") output = GenericErrorCodesInvalidUserStatistics;
            if (inputStr == L"NotAuthenticated") output = GenericErrorCodesNotAuthenticated;
            if (inputStr == L"StreamAlreadyExists") output = GenericErrorCodesStreamAlreadyExists;
            if (inputStr == L"ErrorCreatingStream") output = GenericErrorCodesErrorCreatingStream;
            if (inputStr == L"StreamNotFound") output = GenericErrorCodesStreamNotFound;
            if (inputStr == L"InvalidAccount") output = GenericErrorCodesInvalidAccount;
            if (inputStr == L"PurchaseDoesNotExist") output = GenericErrorCodesPurchaseDoesNotExist;
            if (inputStr == L"InvalidPurchaseTransactionStatus") output = GenericErrorCodesInvalidPurchaseTransactionStatus;
            if (inputStr == L"APINotEnabledForGameClientAccess") output = GenericErrorCodesAPINotEnabledForGameClientAccess;
            if (inputStr == L"NoPushNotificationARNForTitle") output = GenericErrorCodesNoPushNotificationARNForTitle;
            if (inputStr == L"BuildAlreadyExists") output = GenericErrorCodesBuildAlreadyExists;
            if (inputStr == L"BuildPackageDoesNotExist") output = GenericErrorCodesBuildPackageDoesNotExist;
            if (inputStr == L"CustomAnalyticsEventsNotEnabledForTitle") output = GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle;
            if (inputStr == L"InvalidSharedGroupId") output = GenericErrorCodesInvalidSharedGroupId;
            if (inputStr == L"NotAuthorized") output = GenericErrorCodesNotAuthorized;
            if (inputStr == L"MissingTitleGoogleProperties") output = GenericErrorCodesMissingTitleGoogleProperties;
            if (inputStr == L"InvalidItemProperties") output = GenericErrorCodesInvalidItemProperties;
            if (inputStr == L"InvalidPSNAuthCode") output = GenericErrorCodesInvalidPSNAuthCode;
            if (inputStr == L"InvalidItemId") output = GenericErrorCodesInvalidItemId;
            if (inputStr == L"PushNotEnabledForAccount") output = GenericErrorCodesPushNotEnabledForAccount;
            if (inputStr == L"PushServiceError") output = GenericErrorCodesPushServiceError;
            if (inputStr == L"ReceiptDoesNotContainInAppItems") output = GenericErrorCodesReceiptDoesNotContainInAppItems;
            if (inputStr == L"ReceiptContainsMultipleInAppItems") output = GenericErrorCodesReceiptContainsMultipleInAppItems;
            if (inputStr == L"InvalidBundleID") output = GenericErrorCodesInvalidBundleID;
            if (inputStr == L"JavascriptException") output = GenericErrorCodesJavascriptException;
            if (inputStr == L"InvalidSessionTicket") output = GenericErrorCodesInvalidSessionTicket;
            if (inputStr == L"UnableToConnectToDatabase") output = GenericErrorCodesUnableToConnectToDatabase;
            if (inputStr == L"InternalServerError") output = GenericErrorCodesInternalServerError;
            if (inputStr == L"InvalidReportDate") output = GenericErrorCodesInvalidReportDate;
            if (inputStr == L"ReportNotAvailable") output = GenericErrorCodesReportNotAvailable;
            if (inputStr == L"DatabaseThroughputExceeded") output = GenericErrorCodesDatabaseThroughputExceeded;
            if (inputStr == L"InvalidGameTicket") output = GenericErrorCodesInvalidGameTicket;
            if (inputStr == L"ExpiredGameTicket") output = GenericErrorCodesExpiredGameTicket;
            if (inputStr == L"GameTicketDoesNotMatchLobby") output = GenericErrorCodesGameTicketDoesNotMatchLobby;
            if (inputStr == L"LinkedDeviceAlreadyClaimed") output = GenericErrorCodesLinkedDeviceAlreadyClaimed;
            if (inputStr == L"DeviceAlreadyLinked") output = GenericErrorCodesDeviceAlreadyLinked;
            if (inputStr == L"DeviceNotLinked") output = GenericErrorCodesDeviceNotLinked;
            if (inputStr == L"PartialFailure") output = GenericErrorCodesPartialFailure;
            if (inputStr == L"PublisherNotSet") output = GenericErrorCodesPublisherNotSet;
            if (inputStr == L"ServiceUnavailable") output = GenericErrorCodesServiceUnavailable;
            if (inputStr == L"VersionNotFound") output = GenericErrorCodesVersionNotFound;
            if (inputStr == L"RevisionNotFound") output = GenericErrorCodesRevisionNotFound;
            if (inputStr == L"InvalidPublisherId") output = GenericErrorCodesInvalidPublisherId;
            if (inputStr == L"DownstreamServiceUnavailable") output = GenericErrorCodesDownstreamServiceUnavailable;
            if (inputStr == L"APINotIncludedInTitleUsageTier") output = GenericErrorCodesAPINotIncludedInTitleUsageTier;
            if (inputStr == L"DAULimitExceeded") output = GenericErrorCodesDAULimitExceeded;
            if (inputStr == L"APIRequestLimitExceeded") output = GenericErrorCodesAPIRequestLimitExceeded;
            if (inputStr == L"InvalidAPIEndpoint") output = GenericErrorCodesInvalidAPIEndpoint;
            if (inputStr == L"BuildNotAvailable") output = GenericErrorCodesBuildNotAvailable;
            if (inputStr == L"ConcurrentEditError") output = GenericErrorCodesConcurrentEditError;
            if (inputStr == L"ContentNotFound") output = GenericErrorCodesContentNotFound;
            if (inputStr == L"CharacterNotFound") output = GenericErrorCodesCharacterNotFound;
            if (inputStr == L"CloudScriptNotFound") output = GenericErrorCodesCloudScriptNotFound;
            if (inputStr == L"ContentQuotaExceeded") output = GenericErrorCodesContentQuotaExceeded;
            if (inputStr == L"InvalidCharacterStatistics") output = GenericErrorCodesInvalidCharacterStatistics;
            if (inputStr == L"PhotonNotEnabledForTitle") output = GenericErrorCodesPhotonNotEnabledForTitle;
            if (inputStr == L"PhotonApplicationNotFound") output = GenericErrorCodesPhotonApplicationNotFound;
            if (inputStr == L"PhotonApplicationNotAssociatedWithTitle") output = GenericErrorCodesPhotonApplicationNotAssociatedWithTitle;
            if (inputStr == L"InvalidEmailOrPassword") output = GenericErrorCodesInvalidEmailOrPassword;
            if (inputStr == L"FacebookAPIError") output = GenericErrorCodesFacebookAPIError;
            if (inputStr == L"InvalidContentType") output = GenericErrorCodesInvalidContentType;
            if (inputStr == L"KeyLengthExceeded") output = GenericErrorCodesKeyLengthExceeded;
            if (inputStr == L"DataLengthExceeded") output = GenericErrorCodesDataLengthExceeded;
            if (inputStr == L"TooManyKeys") output = GenericErrorCodesTooManyKeys;
            if (inputStr == L"FreeTierCannotHaveVirtualCurrency") output = GenericErrorCodesFreeTierCannotHaveVirtualCurrency;
            if (inputStr == L"MissingAmazonSharedKey") output = GenericErrorCodesMissingAmazonSharedKey;
            if (inputStr == L"AmazonValidationError") output = GenericErrorCodesAmazonValidationError;
            if (inputStr == L"InvalidPSNIssuerId") output = GenericErrorCodesInvalidPSNIssuerId;
            if (inputStr == L"PSNInaccessible") output = GenericErrorCodesPSNInaccessible;
            if (inputStr == L"ExpiredAuthToken") output = GenericErrorCodesExpiredAuthToken;
            if (inputStr == L"FailedToGetEntitlements") output = GenericErrorCodesFailedToGetEntitlements;
            if (inputStr == L"FailedToConsumeEntitlement") output = GenericErrorCodesFailedToConsumeEntitlement;
            if (inputStr == L"TradeAcceptingUserNotAllowed") output = GenericErrorCodesTradeAcceptingUserNotAllowed;
            if (inputStr == L"TradeInventoryItemIsAssignedToCharacter") output = GenericErrorCodesTradeInventoryItemIsAssignedToCharacter;
            if (inputStr == L"TradeInventoryItemIsBundle") output = GenericErrorCodesTradeInventoryItemIsBundle;
            if (inputStr == L"TradeStatusNotValidForCancelling") output = GenericErrorCodesTradeStatusNotValidForCancelling;
            if (inputStr == L"TradeStatusNotValidForAccepting") output = GenericErrorCodesTradeStatusNotValidForAccepting;
            if (inputStr == L"TradeDoesNotExist") output = GenericErrorCodesTradeDoesNotExist;
            if (inputStr == L"TradeCancelled") output = GenericErrorCodesTradeCancelled;
            if (inputStr == L"TradeAlreadyFilled") output = GenericErrorCodesTradeAlreadyFilled;
            if (inputStr == L"TradeWaitForStatusTimeout") output = GenericErrorCodesTradeWaitForStatusTimeout;
            if (inputStr == L"TradeInventoryItemExpired") output = GenericErrorCodesTradeInventoryItemExpired;
            if (inputStr == L"TradeMissingOfferedAndAcceptedItems") output = GenericErrorCodesTradeMissingOfferedAndAcceptedItems;
            if (inputStr == L"TradeAcceptedItemIsBundle") output = GenericErrorCodesTradeAcceptedItemIsBundle;
            if (inputStr == L"TradeAcceptedItemIsStackable") output = GenericErrorCodesTradeAcceptedItemIsStackable;
            if (inputStr == L"TradeInventoryItemInvalidStatus") output = GenericErrorCodesTradeInventoryItemInvalidStatus;
            if (inputStr == L"TradeAcceptedCatalogItemInvalid") output = GenericErrorCodesTradeAcceptedCatalogItemInvalid;
            if (inputStr == L"TradeAllowedUsersInvalid") output = GenericErrorCodesTradeAllowedUsersInvalid;
            if (inputStr == L"TradeInventoryItemDoesNotExist") output = GenericErrorCodesTradeInventoryItemDoesNotExist;
            if (inputStr == L"TradeInventoryItemIsConsumed") output = GenericErrorCodesTradeInventoryItemIsConsumed;
            if (inputStr == L"TradeInventoryItemIsStackable") output = GenericErrorCodesTradeInventoryItemIsStackable;
            if (inputStr == L"TradeAcceptedItemsMismatch") output = GenericErrorCodesTradeAcceptedItemsMismatch;
            if (inputStr == L"InvalidKongregateToken") output = GenericErrorCodesInvalidKongregateToken;
            if (inputStr == L"FeatureNotConfiguredForTitle") output = GenericErrorCodesFeatureNotConfiguredForTitle;
            if (inputStr == L"NoMatchingCatalogItemForReceipt") output = GenericErrorCodesNoMatchingCatalogItemForReceipt;
            if (inputStr == L"InvalidCurrencyCode") output = GenericErrorCodesInvalidCurrencyCode;
            if (inputStr == L"NoRealMoneyPriceForCatalogItem") output = GenericErrorCodesNoRealMoneyPriceForCatalogItem;
            if (inputStr == L"TradeInventoryItemIsNotTradable") output = GenericErrorCodesTradeInventoryItemIsNotTradable;
            if (inputStr == L"TradeAcceptedCatalogItemIsNotTradable") output = GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable;
            if (inputStr == L"UsersAlreadyFriends") output = GenericErrorCodesUsersAlreadyFriends;
            if (inputStr == L"LinkedIdentifierAlreadyClaimed") output = GenericErrorCodesLinkedIdentifierAlreadyClaimed;
            if (inputStr == L"CustomIdNotLinked") output = GenericErrorCodesCustomIdNotLinked;
            if (inputStr == L"TotalDataSizeExceeded") output = GenericErrorCodesTotalDataSizeExceeded;
            if (inputStr == L"DeleteKeyConflict") output = GenericErrorCodesDeleteKeyConflict;
            if (inputStr == L"InvalidXboxLiveToken") output = GenericErrorCodesInvalidXboxLiveToken;
            if (inputStr == L"ExpiredXboxLiveToken") output = GenericErrorCodesExpiredXboxLiveToken;
            if (inputStr == L"ResettableStatisticVersionRequired") output = GenericErrorCodesResettableStatisticVersionRequired;
            if (inputStr == L"NotAuthorizedByTitle") output = GenericErrorCodesNotAuthorizedByTitle;
            if (inputStr == L"NoPartnerEnabled") output = GenericErrorCodesNoPartnerEnabled;
            if (inputStr == L"InvalidPartnerResponse") output = GenericErrorCodesInvalidPartnerResponse;
            if (inputStr == L"APINotEnabledForGameServerAccess") output = GenericErrorCodesAPINotEnabledForGameServerAccess;
            if (inputStr == L"StatisticNotFound") output = GenericErrorCodesStatisticNotFound;
            if (inputStr == L"StatisticNameConflict") output = GenericErrorCodesStatisticNameConflict;
            if (inputStr == L"StatisticVersionClosedForWrites") output = GenericErrorCodesStatisticVersionClosedForWrites;
            if (inputStr == L"StatisticVersionInvalid") output = GenericErrorCodesStatisticVersionInvalid;
            if (inputStr == L"APIClientRequestRateLimitExceeded") output = GenericErrorCodesAPIClientRequestRateLimitExceeded;
            if (inputStr == L"InvalidJSONContent") output = GenericErrorCodesInvalidJSONContent;
            if (inputStr == L"InvalidDropTable") output = GenericErrorCodesInvalidDropTable;
            if (inputStr == L"StatisticVersionAlreadyIncrementedForScheduledInterval") output = GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval;
            if (inputStr == L"StatisticCountLimitExceeded") output = GenericErrorCodesStatisticCountLimitExceeded;
            if (inputStr == L"StatisticVersionIncrementRateExceeded") output = GenericErrorCodesStatisticVersionIncrementRateExceeded;
            if (inputStr == L"ContainerKeyInvalid") output = GenericErrorCodesContainerKeyInvalid;
            if (inputStr == L"CloudScriptExecutionTimeLimitExceeded") output = GenericErrorCodesCloudScriptExecutionTimeLimitExceeded;
            if (inputStr == L"NoWritePermissionsForEvent") output = GenericErrorCodesNoWritePermissionsForEvent;
            if (inputStr == L"CloudScriptFunctionArgumentSizeExceeded") output = GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded;
            if (inputStr == L"CloudScriptAPIRequestCountExceeded") output = GenericErrorCodesCloudScriptAPIRequestCountExceeded;
            if (inputStr == L"CloudScriptAPIRequestError") output = GenericErrorCodesCloudScriptAPIRequestError;
            if (inputStr == L"CloudScriptHTTPRequestError") output = GenericErrorCodesCloudScriptHTTPRequestError;
            if (inputStr == L"InsufficientGuildRole") output = GenericErrorCodesInsufficientGuildRole;
            if (inputStr == L"GuildNotFound") output = GenericErrorCodesGuildNotFound;
            if (inputStr == L"OverLimit") output = GenericErrorCodesOverLimit;
            if (inputStr == L"EventNotFound") output = GenericErrorCodesEventNotFound;
            if (inputStr == L"InvalidEventField") output = GenericErrorCodesInvalidEventField;
            if (inputStr == L"InvalidEventName") output = GenericErrorCodesInvalidEventName;
            if (inputStr == L"CatalogNotConfigured") output = GenericErrorCodesCatalogNotConfigured;
            if (inputStr == L"OperationNotSupportedForPlatform") output = GenericErrorCodesOperationNotSupportedForPlatform;
            if (inputStr == L"SegmentNotFound") output = GenericErrorCodesSegmentNotFound;
            if (inputStr == L"StoreNotFound") output = GenericErrorCodesStoreNotFound;
            if (inputStr == L"InvalidStatisticName") output = GenericErrorCodesInvalidStatisticName;
            if (inputStr == L"TitleNotQualifiedForLimit") output = GenericErrorCodesTitleNotQualifiedForLimit;
            if (inputStr == L"InvalidServiceLimitLevel") output = GenericErrorCodesInvalidServiceLimitLevel;
            if (inputStr == L"ServiceLimitLevelInTransition") output = GenericErrorCodesServiceLimitLevelInTransition;
            if (inputStr == L"CouponAlreadyRedeemed") output = GenericErrorCodesCouponAlreadyRedeemed;
            if (inputStr == L"GameServerBuildSizeLimitExceeded") output = GenericErrorCodesGameServerBuildSizeLimitExceeded;
            if (inputStr == L"GameServerBuildCountLimitExceeded") output = GenericErrorCodesGameServerBuildCountLimitExceeded;
            if (inputStr == L"VirtualCurrencyCountLimitExceeded") output = GenericErrorCodesVirtualCurrencyCountLimitExceeded;
            if (inputStr == L"VirtualCurrencyCodeExists") output = GenericErrorCodesVirtualCurrencyCodeExists;
            if (inputStr == L"TitleNewsItemCountLimitExceeded") output = GenericErrorCodesTitleNewsItemCountLimitExceeded;
            if (inputStr == L"InvalidTwitchToken") output = GenericErrorCodesInvalidTwitchToken;
            if (inputStr == L"TwitchResponseError") output = GenericErrorCodesTwitchResponseError;
            if (inputStr == L"ProfaneDisplayName") output = GenericErrorCodesProfaneDisplayName;
            if (inputStr == L"UserAlreadyAdded") output = GenericErrorCodesUserAlreadyAdded;
            if (inputStr == L"InvalidVirtualCurrencyCode") output = GenericErrorCodesInvalidVirtualCurrencyCode;
            if (inputStr == L"VirtualCurrencyCannotBeDeleted") output = GenericErrorCodesVirtualCurrencyCannotBeDeleted;
            if (inputStr == L"IdentifierAlreadyClaimed") output = GenericErrorCodesIdentifierAlreadyClaimed;
            if (inputStr == L"IdentifierNotLinked") output = GenericErrorCodesIdentifierNotLinked;
            if (inputStr == L"InvalidContinuationToken") output = GenericErrorCodesInvalidContinuationToken;
            if (inputStr == L"ExpiredContinuationToken") output = GenericErrorCodesExpiredContinuationToken;
            if (inputStr == L"InvalidSegment") output = GenericErrorCodesInvalidSegment;
            if (inputStr == L"InvalidSessionId") output = GenericErrorCodesInvalidSessionId;
            if (inputStr == L"SessionLogNotFound") output = GenericErrorCodesSessionLogNotFound;
            if (inputStr == L"InvalidSearchTerm") output = GenericErrorCodesInvalidSearchTerm;
            if (inputStr == L"TwoFactorAuthenticationTokenRequired") output = GenericErrorCodesTwoFactorAuthenticationTokenRequired;
            if (inputStr == L"GameServerHostCountLimitExceeded") output = GenericErrorCodesGameServerHostCountLimitExceeded;
            if (inputStr == L"PlayerTagCountLimitExceeded") output = GenericErrorCodesPlayerTagCountLimitExceeded;
            if (inputStr == L"RequestAlreadyRunning") output = GenericErrorCodesRequestAlreadyRunning;
            if (inputStr == L"ActionGroupNotFound") output = GenericErrorCodesActionGroupNotFound;
            if (inputStr == L"MaximumSegmentBulkActionJobsRunning") output = GenericErrorCodesMaximumSegmentBulkActionJobsRunning;
            if (inputStr == L"NoActionsOnPlayersInSegmentJob") output = GenericErrorCodesNoActionsOnPlayersInSegmentJob;
            if (inputStr == L"DuplicateStatisticName") output = GenericErrorCodesDuplicateStatisticName;
            if (inputStr == L"ScheduledTaskNameConflict") output = GenericErrorCodesScheduledTaskNameConflict;
            if (inputStr == L"ScheduledTaskCreateConflict") output = GenericErrorCodesScheduledTaskCreateConflict;
            if (inputStr == L"InvalidScheduledTaskName") output = GenericErrorCodesInvalidScheduledTaskName;
            if (inputStr == L"InvalidTaskSchedule") output = GenericErrorCodesInvalidTaskSchedule;
            if (inputStr == L"SteamNotEnabledForTitle") output = GenericErrorCodesSteamNotEnabledForTitle;
            if (inputStr == L"LimitNotAnUpgradeOption") output = GenericErrorCodesLimitNotAnUpgradeOption;
            if (inputStr == L"NoSecretKeyEnabledForCloudScript") output = GenericErrorCodesNoSecretKeyEnabledForCloudScript;
            if (inputStr == L"TaskNotFound") output = GenericErrorCodesTaskNotFound;
            if (inputStr == L"TaskInstanceNotFound") output = GenericErrorCodesTaskInstanceNotFound;
            if (inputStr == L"InvalidIdentityProviderId") output = GenericErrorCodesInvalidIdentityProviderId;
            if (inputStr == L"MisconfiguredIdentityProvider") output = GenericErrorCodesMisconfiguredIdentityProvider;
            if (inputStr == L"InvalidScheduledTaskType") output = GenericErrorCodesInvalidScheduledTaskType;
            if (inputStr == L"BillingInformationRequired") output = GenericErrorCodesBillingInformationRequired;
            if (inputStr == L"LimitedEditionItemUnavailable") output = GenericErrorCodesLimitedEditionItemUnavailable;
            if (inputStr == L"InvalidAdPlacementAndReward") output = GenericErrorCodesInvalidAdPlacementAndReward;
            if (inputStr == L"AllAdPlacementViewsAlreadyConsumed") output = GenericErrorCodesAllAdPlacementViewsAlreadyConsumed;
            if (inputStr == L"GoogleOAuthNotConfiguredForTitle") output = GenericErrorCodesGoogleOAuthNotConfiguredForTitle;
            if (inputStr == L"GoogleOAuthError") output = GenericErrorCodesGoogleOAuthError;
            if (inputStr == L"UserNotFriend") output = GenericErrorCodesUserNotFriend;
            if (inputStr == L"InvalidSignature") output = GenericErrorCodesInvalidSignature;
            if (inputStr == L"InvalidPublicKey") output = GenericErrorCodesInvalidPublicKey;
            if (inputStr == L"GoogleOAuthNoIdTokenIncludedInResponse") output = GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse;
            if (inputStr == L"StatisticUpdateInProgress") output = GenericErrorCodesStatisticUpdateInProgress;
            if (inputStr == L"LeaderboardVersionNotAvailable") output = GenericErrorCodesLeaderboardVersionNotAvailable;
            if (inputStr == L"StatisticAlreadyHasPrizeTable") output = GenericErrorCodesStatisticAlreadyHasPrizeTable;
            if (inputStr == L"PrizeTableHasOverlappingRanks") output = GenericErrorCodesPrizeTableHasOverlappingRanks;
            if (inputStr == L"PrizeTableHasMissingRanks") output = GenericErrorCodesPrizeTableHasMissingRanks;
            if (inputStr == L"PrizeTableRankStartsAtZero") output = GenericErrorCodesPrizeTableRankStartsAtZero;
            if (inputStr == L"InvalidStatistic") output = GenericErrorCodesInvalidStatistic;
            if (inputStr == L"ExpressionParseFailure") output = GenericErrorCodesExpressionParseFailure;
            if (inputStr == L"ExpressionInvokeFailure") output = GenericErrorCodesExpressionInvokeFailure;
            if (inputStr == L"ExpressionTooLong") output = GenericErrorCodesExpressionTooLong;
            if (inputStr == L"DataUpdateRateExceeded") output = GenericErrorCodesDataUpdateRateExceeded;
            if (inputStr == L"RestrictedEmailDomain") output = GenericErrorCodesRestrictedEmailDomain;
            if (inputStr == L"EncryptionKeyDisabled") output = GenericErrorCodesEncryptionKeyDisabled;
            if (inputStr == L"EncryptionKeyMissing") output = GenericErrorCodesEncryptionKeyMissing;
            if (inputStr == L"EncryptionKeyBroken") output = GenericErrorCodesEncryptionKeyBroken;
            if (inputStr == L"NoSharedSecretKeyConfigured") output = GenericErrorCodesNoSharedSecretKeyConfigured;
            if (inputStr == L"SecretKeyNotFound") output = GenericErrorCodesSecretKeyNotFound;
            if (inputStr == L"PlayerSecretAlreadyConfigured") output = GenericErrorCodesPlayerSecretAlreadyConfigured;
            if (inputStr == L"APIRequestsDisabledForTitle") output = GenericErrorCodesAPIRequestsDisabledForTitle;
            if (inputStr == L"InvalidSharedSecretKey") output = GenericErrorCodesInvalidSharedSecretKey;
            if (inputStr == L"PrizeTableHasNoRanks") output = GenericErrorCodesPrizeTableHasNoRanks;
            if (inputStr == L"ProfileDoesNotExist") output = GenericErrorCodesProfileDoesNotExist;
            if (inputStr == L"ContentS3OriginBucketNotConfigured") output = GenericErrorCodesContentS3OriginBucketNotConfigured;
            if (inputStr == L"InvalidEnvironmentForReceipt") output = GenericErrorCodesInvalidEnvironmentForReceipt;
            if (inputStr == L"EncryptedRequestNotAllowed") output = GenericErrorCodesEncryptedRequestNotAllowed;
            if (inputStr == L"SignedRequestNotAllowed") output = GenericErrorCodesSignedRequestNotAllowed;
            if (inputStr == L"RequestViewConstraintParamsNotAllowed") output = GenericErrorCodesRequestViewConstraintParamsNotAllowed;
            if (inputStr == L"BadPartnerConfiguration") output = GenericErrorCodesBadPartnerConfiguration;
            if (inputStr == L"XboxBPCertificateFailure") output = GenericErrorCodesXboxBPCertificateFailure;
            if (inputStr == L"XboxXASSExchangeFailure") output = GenericErrorCodesXboxXASSExchangeFailure;
            if (inputStr == L"InvalidEntityId") output = GenericErrorCodesInvalidEntityId;
            if (inputStr == L"StatisticValueAggregationOverflow") output = GenericErrorCodesStatisticValueAggregationOverflow;
            if (inputStr == L"EmailMessageFromAddressIsMissing") output = GenericErrorCodesEmailMessageFromAddressIsMissing;
            if (inputStr == L"EmailMessageToAddressIsMissing") output = GenericErrorCodesEmailMessageToAddressIsMissing;
            if (inputStr == L"SmtpServerAuthenticationError") output = GenericErrorCodesSmtpServerAuthenticationError;
            if (inputStr == L"SmtpServerLimitExceeded") output = GenericErrorCodesSmtpServerLimitExceeded;
            if (inputStr == L"SmtpServerInsufficientStorage") output = GenericErrorCodesSmtpServerInsufficientStorage;
            if (inputStr == L"SmtpServerCommunicationError") output = GenericErrorCodesSmtpServerCommunicationError;
            if (inputStr == L"SmtpServerGeneralFailure") output = GenericErrorCodesSmtpServerGeneralFailure;
            if (inputStr == L"EmailClientTimeout") output = GenericErrorCodesEmailClientTimeout;
            if (inputStr == L"EmailClientCanceledTask") output = GenericErrorCodesEmailClientCanceledTask;
            if (inputStr == L"EmailTemplateMissing") output = GenericErrorCodesEmailTemplateMissing;
            if (inputStr == L"InvalidHostForTitleId") output = GenericErrorCodesInvalidHostForTitleId;
            if (inputStr == L"EmailConfirmationTokenDoesNotExist") output = GenericErrorCodesEmailConfirmationTokenDoesNotExist;
            if (inputStr == L"EmailConfirmationTokenExpired") output = GenericErrorCodesEmailConfirmationTokenExpired;
            if (inputStr == L"AccountDeleted") output = GenericErrorCodesAccountDeleted;
            if (inputStr == L"PlayerSecretNotConfigured") output = GenericErrorCodesPlayerSecretNotConfigured;
            if (inputStr == L"InvalidSignatureTime") output = GenericErrorCodesInvalidSignatureTime;
            if (inputStr == L"NoContactEmailAddressFound") output = GenericErrorCodesNoContactEmailAddressFound;
            if (inputStr == L"InvalidAuthToken") output = GenericErrorCodesInvalidAuthToken;
            if (inputStr == L"AuthTokenDoesNotExist") output = GenericErrorCodesAuthTokenDoesNotExist;
            if (inputStr == L"AuthTokenExpired") output = GenericErrorCodesAuthTokenExpired;
            if (inputStr == L"AuthTokenAlreadyUsedToResetPassword") output = GenericErrorCodesAuthTokenAlreadyUsedToResetPassword;
            if (inputStr == L"MembershipNameTooLong") output = GenericErrorCodesMembershipNameTooLong;
            if (inputStr == L"MembershipNotFound") output = GenericErrorCodesMembershipNotFound;
            if (inputStr == L"GoogleServiceAccountInvalid") output = GenericErrorCodesGoogleServiceAccountInvalid;
            if (inputStr == L"GoogleServiceAccountParseFailure") output = GenericErrorCodesGoogleServiceAccountParseFailure;
            if (inputStr == L"EntityTokenMissing") output = GenericErrorCodesEntityTokenMissing;
            if (inputStr == L"EntityTokenInvalid") output = GenericErrorCodesEntityTokenInvalid;
            if (inputStr == L"EntityTokenExpired") output = GenericErrorCodesEntityTokenExpired;
            if (inputStr == L"EntityTokenRevoked") output = GenericErrorCodesEntityTokenRevoked;
            if (inputStr == L"InvalidProductForSubscription") output = GenericErrorCodesInvalidProductForSubscription;
            if (inputStr == L"XboxInaccessible") output = GenericErrorCodesXboxInaccessible;
            if (inputStr == L"SubscriptionAlreadyTaken") output = GenericErrorCodesSubscriptionAlreadyTaken;
            if (inputStr == L"SmtpAddonNotEnabled") output = GenericErrorCodesSmtpAddonNotEnabled;
            if (inputStr == L"APIConcurrentRequestLimitExceeded") output = GenericErrorCodesAPIConcurrentRequestLimitExceeded;
            if (inputStr == L"XboxRejectedXSTSExchangeRequest") output = GenericErrorCodesXboxRejectedXSTSExchangeRequest;
            if (inputStr == L"VariableNotDefined") output = GenericErrorCodesVariableNotDefined;
            if (inputStr == L"TemplateVersionNotDefined") output = GenericErrorCodesTemplateVersionNotDefined;
            if (inputStr == L"FileTooLarge") output = GenericErrorCodesFileTooLarge;
            if (inputStr == L"TitleDeleted") output = GenericErrorCodesTitleDeleted;
            if (inputStr == L"TitleContainsUserAccounts") output = GenericErrorCodesTitleContainsUserAccounts;
            if (inputStr == L"TitleDeletionPlayerCleanupFailure") output = GenericErrorCodesTitleDeletionPlayerCleanupFailure;
            if (inputStr == L"EntityFileOperationPending") output = GenericErrorCodesEntityFileOperationPending;
            if (inputStr == L"NoEntityFileOperationPending") output = GenericErrorCodesNoEntityFileOperationPending;
            if (inputStr == L"EntityProfileVersionMismatch") output = GenericErrorCodesEntityProfileVersionMismatch;
            if (inputStr == L"TemplateVersionTooOld") output = GenericErrorCodesTemplateVersionTooOld;
            if (inputStr == L"MembershipDefinitionInUse") output = GenericErrorCodesMembershipDefinitionInUse;
            if (inputStr == L"PaymentPageNotConfigured") output = GenericErrorCodesPaymentPageNotConfigured;
            if (inputStr == L"FailedLoginAttemptRateLimitExceeded") output = GenericErrorCodesFailedLoginAttemptRateLimitExceeded;
            if (inputStr == L"EntityBlockedByGroup") output = GenericErrorCodesEntityBlockedByGroup;
            if (inputStr == L"RoleDoesNotExist") output = GenericErrorCodesRoleDoesNotExist;
            if (inputStr == L"EntityIsAlreadyMember") output = GenericErrorCodesEntityIsAlreadyMember;
            if (inputStr == L"DuplicateRoleId") output = GenericErrorCodesDuplicateRoleId;
            if (inputStr == L"GroupInvitationNotFound") output = GenericErrorCodesGroupInvitationNotFound;
            if (inputStr == L"GroupApplicationNotFound") output = GenericErrorCodesGroupApplicationNotFound;
            if (inputStr == L"OutstandingInvitationAcceptedInstead") output = GenericErrorCodesOutstandingInvitationAcceptedInstead;
            if (inputStr == L"OutstandingApplicationAcceptedInstead") output = GenericErrorCodesOutstandingApplicationAcceptedInstead;
            if (inputStr == L"RoleIsGroupDefaultMember") output = GenericErrorCodesRoleIsGroupDefaultMember;
            if (inputStr == L"RoleIsGroupAdmin") output = GenericErrorCodesRoleIsGroupAdmin;
            if (inputStr == L"RoleNameNotAvailable") output = GenericErrorCodesRoleNameNotAvailable;
            if (inputStr == L"GroupNameNotAvailable") output = GenericErrorCodesGroupNameNotAvailable;
            if (inputStr == L"EmailReportAlreadySent") output = GenericErrorCodesEmailReportAlreadySent;
            if (inputStr == L"EmailReportRecipientBlacklisted") output = GenericErrorCodesEmailReportRecipientBlacklisted;
            if (inputStr == L"EventNamespaceNotAllowed") output = GenericErrorCodesEventNamespaceNotAllowed;
            if (inputStr == L"EventEntityNotAllowed") output = GenericErrorCodesEventEntityNotAllowed;
            if (inputStr == L"InvalidEntityType") output = GenericErrorCodesInvalidEntityType;
            if (inputStr == L"NullTokenResultFromAad") output = GenericErrorCodesNullTokenResultFromAad;
            if (inputStr == L"InvalidTokenResultFromAad") output = GenericErrorCodesInvalidTokenResultFromAad;
            if (inputStr == L"NoValidCertificateForAad") output = GenericErrorCodesNoValidCertificateForAad;
            if (inputStr == L"InvalidCertificateForAad") output = GenericErrorCodesInvalidCertificateForAad;
            if (inputStr == L"DuplicateDropTableId") output = GenericErrorCodesDuplicateDropTableId;
            if (inputStr == L"GameServerOk") output = GenericErrorCodesGameServerOk;
            if (inputStr == L"GameServerAccepted") output = GenericErrorCodesGameServerAccepted;
            if (inputStr == L"GameServerNoContent") output = GenericErrorCodesGameServerNoContent;
            if (inputStr == L"GameServerBadRequest") output = GenericErrorCodesGameServerBadRequest;
            if (inputStr == L"GameServerUnauthorized") output = GenericErrorCodesGameServerUnauthorized;
            if (inputStr == L"GameServerForbidden") output = GenericErrorCodesGameServerForbidden;
            if (inputStr == L"GameServerNotFound") output = GenericErrorCodesGameServerNotFound;
            if (inputStr == L"GameServerConflict") output = GenericErrorCodesGameServerConflict;
            if (inputStr == L"GameServerInternalServerError") output = GenericErrorCodesGameServerInternalServerError;
            if (inputStr == L"GameServerServiceUnavailable") output = GenericErrorCodesGameServerServiceUnavailable;
            if (inputStr == L"ExplicitContentDetected") output = GenericErrorCodesExplicitContentDetected;
            if (inputStr == L"PIIContentDetected") output = GenericErrorCodesPIIContentDetected;
            if (inputStr == L"InvalidScheduledTaskParameter") output = GenericErrorCodesInvalidScheduledTaskParameter;
            if (inputStr == L"PerEntityEventRateLimitExceeded") output = GenericErrorCodesPerEntityEventRateLimitExceeded;
            if (inputStr == L"TitleDefaultLanguageNotSet") output = GenericErrorCodesTitleDefaultLanguageNotSet;
            if (inputStr == L"EmailTemplateMissingDefaultVersion") output = GenericErrorCodesEmailTemplateMissingDefaultVersion;
            if (inputStr == L"FacebookInstantGamesIdNotLinked") output = GenericErrorCodesFacebookInstantGamesIdNotLinked;
            if (inputStr == L"InvalidFacebookInstantGamesSignature") output = GenericErrorCodesInvalidFacebookInstantGamesSignature;
            if (inputStr == L"FacebookInstantGamesAuthNotConfiguredForTitle") output = GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle;
            if (inputStr == L"MatchmakingEntityInvalid") output = GenericErrorCodesMatchmakingEntityInvalid;
            if (inputStr == L"MatchmakingPlayerAttributesInvalid") output = GenericErrorCodesMatchmakingPlayerAttributesInvalid;
            if (inputStr == L"MatchmakingCreateRequestMissing") output = GenericErrorCodesMatchmakingCreateRequestMissing;
            if (inputStr == L"MatchmakingCreateRequestCreatorMissing") output = GenericErrorCodesMatchmakingCreateRequestCreatorMissing;
            if (inputStr == L"MatchmakingCreateRequestCreatorIdMissing") output = GenericErrorCodesMatchmakingCreateRequestCreatorIdMissing;
            if (inputStr == L"MatchmakingCreateRequestUserListMissing") output = GenericErrorCodesMatchmakingCreateRequestUserListMissing;
            if (inputStr == L"MatchmakingCreateRequestGiveUpAfterInvalid") output = GenericErrorCodesMatchmakingCreateRequestGiveUpAfterInvalid;
            if (inputStr == L"MatchmakingTicketIdMissing") output = GenericErrorCodesMatchmakingTicketIdMissing;
            if (inputStr == L"MatchmakingMatchIdMissing") output = GenericErrorCodesMatchmakingMatchIdMissing;
            if (inputStr == L"MatchmakingMatchIdIdMissing") output = GenericErrorCodesMatchmakingMatchIdIdMissing;
            if (inputStr == L"MatchmakingQueueNameMissing") output = GenericErrorCodesMatchmakingQueueNameMissing;
            if (inputStr == L"MatchmakingTitleIdMissing") output = GenericErrorCodesMatchmakingTitleIdMissing;
            if (inputStr == L"MatchmakingTicketIdIdMissing") output = GenericErrorCodesMatchmakingTicketIdIdMissing;
            if (inputStr == L"MatchmakingPlayerIdMissing") output = GenericErrorCodesMatchmakingPlayerIdMissing;
            if (inputStr == L"MatchmakingJoinRequestUserMissing") output = GenericErrorCodesMatchmakingJoinRequestUserMissing;
            if (inputStr == L"MatchmakingQueueConfigNotFound") output = GenericErrorCodesMatchmakingQueueConfigNotFound;
            if (inputStr == L"MatchmakingMatchNotFound") output = GenericErrorCodesMatchmakingMatchNotFound;
            if (inputStr == L"MatchmakingTicketNotFound") output = GenericErrorCodesMatchmakingTicketNotFound;
            if (inputStr == L"MatchmakingCreateTicketServerIdentityInvalid") output = GenericErrorCodesMatchmakingCreateTicketServerIdentityInvalid;
            if (inputStr == L"MatchmakingCreateTicketClientIdentityInvalid") output = GenericErrorCodesMatchmakingCreateTicketClientIdentityInvalid;
            if (inputStr == L"MatchmakingGetTicketUserMismatch") output = GenericErrorCodesMatchmakingGetTicketUserMismatch;
            if (inputStr == L"MatchmakingJoinTicketServerIdentityInvalid") output = GenericErrorCodesMatchmakingJoinTicketServerIdentityInvalid;
            if (inputStr == L"MatchmakingJoinTicketUserIdentityMismatch") output = GenericErrorCodesMatchmakingJoinTicketUserIdentityMismatch;
            if (inputStr == L"MatchmakingCancelTicketServerIdentityInvalid") output = GenericErrorCodesMatchmakingCancelTicketServerIdentityInvalid;
            if (inputStr == L"MatchmakingCancelTicketUserIdentityMismatch") output = GenericErrorCodesMatchmakingCancelTicketUserIdentityMismatch;
            if (inputStr == L"MatchmakingGetMatchIdentityMismatch") output = GenericErrorCodesMatchmakingGetMatchIdentityMismatch;
            if (inputStr == L"MatchmakingPlayerIdentityMismatch") output = GenericErrorCodesMatchmakingPlayerIdentityMismatch;
            if (inputStr == L"MatchmakingAlreadyJoinedTicket") output = GenericErrorCodesMatchmakingAlreadyJoinedTicket;
            if (inputStr == L"MatchmakingTicketAlreadyCompleted") output = GenericErrorCodesMatchmakingTicketAlreadyCompleted;
            if (inputStr == L"MatchmakingQueueNameInvalid") output = GenericErrorCodesMatchmakingQueueNameInvalid;
            if (inputStr == L"MatchmakingQueueConfigInvalid") output = GenericErrorCodesMatchmakingQueueConfigInvalid;
            if (inputStr == L"MatchmakingMemberProfileInvalid") output = GenericErrorCodesMatchmakingMemberProfileInvalid;
            if (inputStr == L"WriteAttemptedDuringExport") output = GenericErrorCodesWriteAttemptedDuringExport;
            if (inputStr == L"NintendoSwitchDeviceIdNotLinked") output = GenericErrorCodesNintendoSwitchDeviceIdNotLinked;
            if (inputStr == L"MatchmakingNotEnabled") output = GenericErrorCodesMatchmakingNotEnabled;
        }

        enum LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello,
            LoginIdentityProviderGameServer,
            LoginIdentityProviderCustomServer,
            LoginIdentityProviderNintendoSwitch,
            LoginIdentityProviderFacebookInstantGames
        };

        inline void ToJsonEnum(const LoginIdentityProvider input, web::json::value& output)
        {
            if (input == LoginIdentityProviderUnknown) output = web::json::value(L"Unknown");
            if (input == LoginIdentityProviderPlayFab) output = web::json::value(L"PlayFab");
            if (input == LoginIdentityProviderCustom) output = web::json::value(L"Custom");
            if (input == LoginIdentityProviderGameCenter) output = web::json::value(L"GameCenter");
            if (input == LoginIdentityProviderGooglePlay) output = web::json::value(L"GooglePlay");
            if (input == LoginIdentityProviderSteam) output = web::json::value(L"Steam");
            if (input == LoginIdentityProviderXBoxLive) output = web::json::value(L"XBoxLive");
            if (input == LoginIdentityProviderPSN) output = web::json::value(L"PSN");
            if (input == LoginIdentityProviderKongregate) output = web::json::value(L"Kongregate");
            if (input == LoginIdentityProviderFacebook) output = web::json::value(L"Facebook");
            if (input == LoginIdentityProviderIOSDevice) output = web::json::value(L"IOSDevice");
            if (input == LoginIdentityProviderAndroidDevice) output = web::json::value(L"AndroidDevice");
            if (input == LoginIdentityProviderTwitch) output = web::json::value(L"Twitch");
            if (input == LoginIdentityProviderWindowsHello) output = web::json::value(L"WindowsHello");
            if (input == LoginIdentityProviderGameServer) output = web::json::value(L"GameServer");
            if (input == LoginIdentityProviderCustomServer) output = web::json::value(L"CustomServer");
            if (input == LoginIdentityProviderNintendoSwitch) output = web::json::value(L"NintendoSwitch");
            if (input == LoginIdentityProviderFacebookInstantGames) output = web::json::value(L"FacebookInstantGames");
        }
        inline void FromJsonEnum(const web::json::value& input, LoginIdentityProvider& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Unknown") output = LoginIdentityProviderUnknown;
            if (inputStr == L"PlayFab") output = LoginIdentityProviderPlayFab;
            if (inputStr == L"Custom") output = LoginIdentityProviderCustom;
            if (inputStr == L"GameCenter") output = LoginIdentityProviderGameCenter;
            if (inputStr == L"GooglePlay") output = LoginIdentityProviderGooglePlay;
            if (inputStr == L"Steam") output = LoginIdentityProviderSteam;
            if (inputStr == L"XBoxLive") output = LoginIdentityProviderXBoxLive;
            if (inputStr == L"PSN") output = LoginIdentityProviderPSN;
            if (inputStr == L"Kongregate") output = LoginIdentityProviderKongregate;
            if (inputStr == L"Facebook") output = LoginIdentityProviderFacebook;
            if (inputStr == L"IOSDevice") output = LoginIdentityProviderIOSDevice;
            if (inputStr == L"AndroidDevice") output = LoginIdentityProviderAndroidDevice;
            if (inputStr == L"Twitch") output = LoginIdentityProviderTwitch;
            if (inputStr == L"WindowsHello") output = LoginIdentityProviderWindowsHello;
            if (inputStr == L"GameServer") output = LoginIdentityProviderGameServer;
            if (inputStr == L"CustomServer") output = LoginIdentityProviderCustomServer;
            if (inputStr == L"NintendoSwitch") output = LoginIdentityProviderNintendoSwitch;
            if (inputStr == L"FacebookInstantGames") output = LoginIdentityProviderFacebookInstantGames;
        }

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        inline void ToJsonEnum(const PushNotificationPlatform input, web::json::value& output)
        {
            if (input == PushNotificationPlatformApplePushNotificationService) output = web::json::value(L"ApplePushNotificationService");
            if (input == PushNotificationPlatformGoogleCloudMessaging) output = web::json::value(L"GoogleCloudMessaging");
        }
        inline void FromJsonEnum(const web::json::value& input, PushNotificationPlatform& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"ApplePushNotificationService") output = PushNotificationPlatformApplePushNotificationService;
            if (inputStr == L"GoogleCloudMessaging") output = PushNotificationPlatformGoogleCloudMessaging;
        }

        enum PushSetupPlatform
        {
            PushSetupPlatformGCM,
            PushSetupPlatformAPNS,
            PushSetupPlatformAPNS_SANDBOX
        };

        inline void ToJsonEnum(const PushSetupPlatform input, web::json::value& output)
        {
            if (input == PushSetupPlatformGCM) output = web::json::value(L"GCM");
            if (input == PushSetupPlatformAPNS) output = web::json::value(L"APNS");
            if (input == PushSetupPlatformAPNS_SANDBOX) output = web::json::value(L"APNS_SANDBOX");
        }
        inline void FromJsonEnum(const web::json::value& input, PushSetupPlatform& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"GCM") output = PushSetupPlatformGCM;
            if (inputStr == L"APNS") output = PushSetupPlatformAPNS;
            if (inputStr == L"APNS_SANDBOX") output = PushSetupPlatformAPNS_SANDBOX;
        }

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

        enum ResolutionOutcome
        {
            ResolutionOutcomeRevoke,
            ResolutionOutcomeReinstate,
            ResolutionOutcomeManual
        };

        inline void ToJsonEnum(const ResolutionOutcome input, web::json::value& output)
        {
            if (input == ResolutionOutcomeRevoke) output = web::json::value(L"Revoke");
            if (input == ResolutionOutcomeReinstate) output = web::json::value(L"Reinstate");
            if (input == ResolutionOutcomeManual) output = web::json::value(L"Manual");
        }
        inline void FromJsonEnum(const web::json::value& input, ResolutionOutcome& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Revoke") output = ResolutionOutcomeRevoke;
            if (inputStr == L"Reinstate") output = ResolutionOutcomeReinstate;
            if (inputStr == L"Manual") output = ResolutionOutcomeManual;
        }

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        inline void ToJsonEnum(const ResultTableNodeType input, web::json::value& output)
        {
            if (input == ResultTableNodeTypeItemId) output = web::json::value(L"ItemId");
            if (input == ResultTableNodeTypeTableId) output = web::json::value(L"TableId");
        }
        inline void FromJsonEnum(const web::json::value& input, ResultTableNodeType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"ItemId") output = ResultTableNodeTypeItemId;
            if (inputStr == L"TableId") output = ResultTableNodeTypeTableId;
        }

        enum ScheduledTaskType
        {
            ScheduledTaskTypeCloudScript,
            ScheduledTaskTypeActionsOnPlayerSegment
        };

        inline void ToJsonEnum(const ScheduledTaskType input, web::json::value& output)
        {
            if (input == ScheduledTaskTypeCloudScript) output = web::json::value(L"CloudScript");
            if (input == ScheduledTaskTypeActionsOnPlayerSegment) output = web::json::value(L"ActionsOnPlayerSegment");
        }
        inline void FromJsonEnum(const web::json::value& input, ScheduledTaskType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"CloudScript") output = ScheduledTaskTypeCloudScript;
            if (inputStr == L"ActionsOnPlayerSegment") output = ScheduledTaskTypeActionsOnPlayerSegment;
        }

        enum SourceType
        {
            SourceTypeAdmin,
            SourceTypeBackEnd,
            SourceTypeGameClient,
            SourceTypeGameServer,
            SourceTypePartner,
            SourceTypeCustom,
            SourceTypeAPI
        };

        inline void ToJsonEnum(const SourceType input, web::json::value& output)
        {
            if (input == SourceTypeAdmin) output = web::json::value(L"Admin");
            if (input == SourceTypeBackEnd) output = web::json::value(L"BackEnd");
            if (input == SourceTypeGameClient) output = web::json::value(L"GameClient");
            if (input == SourceTypeGameServer) output = web::json::value(L"GameServer");
            if (input == SourceTypePartner) output = web::json::value(L"Partner");
            if (input == SourceTypeCustom) output = web::json::value(L"Custom");
            if (input == SourceTypeAPI) output = web::json::value(L"API");
        }
        inline void FromJsonEnum(const web::json::value& input, SourceType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Admin") output = SourceTypeAdmin;
            if (inputStr == L"BackEnd") output = SourceTypeBackEnd;
            if (inputStr == L"GameClient") output = SourceTypeGameClient;
            if (inputStr == L"GameServer") output = SourceTypeGameServer;
            if (inputStr == L"Partner") output = SourceTypePartner;
            if (inputStr == L"Custom") output = SourceTypeCustom;
            if (inputStr == L"API") output = SourceTypeAPI;
        }

        enum StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        inline void ToJsonEnum(const StatisticAggregationMethod input, web::json::value& output)
        {
            if (input == StatisticAggregationMethodLast) output = web::json::value(L"Last");
            if (input == StatisticAggregationMethodMin) output = web::json::value(L"Min");
            if (input == StatisticAggregationMethodMax) output = web::json::value(L"Max");
            if (input == StatisticAggregationMethodSum) output = web::json::value(L"Sum");
        }
        inline void FromJsonEnum(const web::json::value& input, StatisticAggregationMethod& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Last") output = StatisticAggregationMethodLast;
            if (inputStr == L"Min") output = StatisticAggregationMethodMin;
            if (inputStr == L"Max") output = StatisticAggregationMethodMax;
            if (inputStr == L"Sum") output = StatisticAggregationMethodSum;
        }

        enum StatisticResetIntervalOption
        {
            StatisticResetIntervalOptionNever,
            StatisticResetIntervalOptionHour,
            StatisticResetIntervalOptionDay,
            StatisticResetIntervalOptionWeek,
            StatisticResetIntervalOptionMonth
        };

        inline void ToJsonEnum(const StatisticResetIntervalOption input, web::json::value& output)
        {
            if (input == StatisticResetIntervalOptionNever) output = web::json::value(L"Never");
            if (input == StatisticResetIntervalOptionHour) output = web::json::value(L"Hour");
            if (input == StatisticResetIntervalOptionDay) output = web::json::value(L"Day");
            if (input == StatisticResetIntervalOptionWeek) output = web::json::value(L"Week");
            if (input == StatisticResetIntervalOptionMonth) output = web::json::value(L"Month");
        }
        inline void FromJsonEnum(const web::json::value& input, StatisticResetIntervalOption& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Never") output = StatisticResetIntervalOptionNever;
            if (inputStr == L"Hour") output = StatisticResetIntervalOptionHour;
            if (inputStr == L"Day") output = StatisticResetIntervalOptionDay;
            if (inputStr == L"Week") output = StatisticResetIntervalOptionWeek;
            if (inputStr == L"Month") output = StatisticResetIntervalOptionMonth;
        }

        enum StatisticVersionArchivalStatus
        {
            StatisticVersionArchivalStatusNotScheduled,
            StatisticVersionArchivalStatusScheduled,
            StatisticVersionArchivalStatusQueued,
            StatisticVersionArchivalStatusInProgress,
            StatisticVersionArchivalStatusComplete
        };

        inline void ToJsonEnum(const StatisticVersionArchivalStatus input, web::json::value& output)
        {
            if (input == StatisticVersionArchivalStatusNotScheduled) output = web::json::value(L"NotScheduled");
            if (input == StatisticVersionArchivalStatusScheduled) output = web::json::value(L"Scheduled");
            if (input == StatisticVersionArchivalStatusQueued) output = web::json::value(L"Queued");
            if (input == StatisticVersionArchivalStatusInProgress) output = web::json::value(L"InProgress");
            if (input == StatisticVersionArchivalStatusComplete) output = web::json::value(L"Complete");
        }
        inline void FromJsonEnum(const web::json::value& input, StatisticVersionArchivalStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"NotScheduled") output = StatisticVersionArchivalStatusNotScheduled;
            if (inputStr == L"Scheduled") output = StatisticVersionArchivalStatusScheduled;
            if (inputStr == L"Queued") output = StatisticVersionArchivalStatusQueued;
            if (inputStr == L"InProgress") output = StatisticVersionArchivalStatusInProgress;
            if (inputStr == L"Complete") output = StatisticVersionArchivalStatusComplete;
        }

        enum StatisticVersionStatus
        {
            StatisticVersionStatusActive,
            StatisticVersionStatusSnapshotPending,
            StatisticVersionStatusSnapshot,
            StatisticVersionStatusArchivalPending,
            StatisticVersionStatusArchived
        };

        inline void ToJsonEnum(const StatisticVersionStatus input, web::json::value& output)
        {
            if (input == StatisticVersionStatusActive) output = web::json::value(L"Active");
            if (input == StatisticVersionStatusSnapshotPending) output = web::json::value(L"SnapshotPending");
            if (input == StatisticVersionStatusSnapshot) output = web::json::value(L"Snapshot");
            if (input == StatisticVersionStatusArchivalPending) output = web::json::value(L"ArchivalPending");
            if (input == StatisticVersionStatusArchived) output = web::json::value(L"Archived");
        }
        inline void FromJsonEnum(const web::json::value& input, StatisticVersionStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Active") output = StatisticVersionStatusActive;
            if (inputStr == L"SnapshotPending") output = StatisticVersionStatusSnapshotPending;
            if (inputStr == L"Snapshot") output = StatisticVersionStatusSnapshot;
            if (inputStr == L"ArchivalPending") output = StatisticVersionStatusArchivalPending;
            if (inputStr == L"Archived") output = StatisticVersionStatusArchived;
        }

        enum SubscriptionProviderStatus
        {
            SubscriptionProviderStatusNoError,
            SubscriptionProviderStatusCancelled,
            SubscriptionProviderStatusUnknownError,
            SubscriptionProviderStatusBillingError,
            SubscriptionProviderStatusProductUnavailable,
            SubscriptionProviderStatusCustomerDidNotAcceptPriceChange,
            SubscriptionProviderStatusFreeTrial,
            SubscriptionProviderStatusPaymentPending
        };

        inline void ToJsonEnum(const SubscriptionProviderStatus input, web::json::value& output)
        {
            if (input == SubscriptionProviderStatusNoError) output = web::json::value(L"NoError");
            if (input == SubscriptionProviderStatusCancelled) output = web::json::value(L"Cancelled");
            if (input == SubscriptionProviderStatusUnknownError) output = web::json::value(L"UnknownError");
            if (input == SubscriptionProviderStatusBillingError) output = web::json::value(L"BillingError");
            if (input == SubscriptionProviderStatusProductUnavailable) output = web::json::value(L"ProductUnavailable");
            if (input == SubscriptionProviderStatusCustomerDidNotAcceptPriceChange) output = web::json::value(L"CustomerDidNotAcceptPriceChange");
            if (input == SubscriptionProviderStatusFreeTrial) output = web::json::value(L"FreeTrial");
            if (input == SubscriptionProviderStatusPaymentPending) output = web::json::value(L"PaymentPending");
        }
        inline void FromJsonEnum(const web::json::value& input, SubscriptionProviderStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"NoError") output = SubscriptionProviderStatusNoError;
            if (inputStr == L"Cancelled") output = SubscriptionProviderStatusCancelled;
            if (inputStr == L"UnknownError") output = SubscriptionProviderStatusUnknownError;
            if (inputStr == L"BillingError") output = SubscriptionProviderStatusBillingError;
            if (inputStr == L"ProductUnavailable") output = SubscriptionProviderStatusProductUnavailable;
            if (inputStr == L"CustomerDidNotAcceptPriceChange") output = SubscriptionProviderStatusCustomerDidNotAcceptPriceChange;
            if (inputStr == L"FreeTrial") output = SubscriptionProviderStatusFreeTrial;
            if (inputStr == L"PaymentPending") output = SubscriptionProviderStatusPaymentPending;
        }

        enum TaskInstanceStatus
        {
            TaskInstanceStatusSucceeded,
            TaskInstanceStatusStarting,
            TaskInstanceStatusInProgress,
            TaskInstanceStatusFailed,
            TaskInstanceStatusAborted,
            TaskInstanceStatusPending
        };

        inline void ToJsonEnum(const TaskInstanceStatus input, web::json::value& output)
        {
            if (input == TaskInstanceStatusSucceeded) output = web::json::value(L"Succeeded");
            if (input == TaskInstanceStatusStarting) output = web::json::value(L"Starting");
            if (input == TaskInstanceStatusInProgress) output = web::json::value(L"InProgress");
            if (input == TaskInstanceStatusFailed) output = web::json::value(L"Failed");
            if (input == TaskInstanceStatusAborted) output = web::json::value(L"Aborted");
            if (input == TaskInstanceStatusPending) output = web::json::value(L"Pending");
        }
        inline void FromJsonEnum(const web::json::value& input, TaskInstanceStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Succeeded") output = TaskInstanceStatusSucceeded;
            if (inputStr == L"Starting") output = TaskInstanceStatusStarting;
            if (inputStr == L"InProgress") output = TaskInstanceStatusInProgress;
            if (inputStr == L"Failed") output = TaskInstanceStatusFailed;
            if (inputStr == L"Aborted") output = TaskInstanceStatusAborted;
            if (inputStr == L"Pending") output = TaskInstanceStatusPending;
        }

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        inline void ToJsonEnum(const TitleActivationStatus input, web::json::value& output)
        {
            if (input == TitleActivationStatusNone) output = web::json::value(L"None");
            if (input == TitleActivationStatusActivatedTitleKey) output = web::json::value(L"ActivatedTitleKey");
            if (input == TitleActivationStatusPendingSteam) output = web::json::value(L"PendingSteam");
            if (input == TitleActivationStatusActivatedSteam) output = web::json::value(L"ActivatedSteam");
            if (input == TitleActivationStatusRevokedSteam) output = web::json::value(L"RevokedSteam");
        }
        inline void FromJsonEnum(const web::json::value& input, TitleActivationStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"None") output = TitleActivationStatusNone;
            if (inputStr == L"ActivatedTitleKey") output = TitleActivationStatusActivatedTitleKey;
            if (inputStr == L"PendingSteam") output = TitleActivationStatusPendingSteam;
            if (inputStr == L"ActivatedSteam") output = TitleActivationStatusActivatedSteam;
            if (inputStr == L"RevokedSteam") output = TitleActivationStatusRevokedSteam;
        }

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        inline void ToJsonEnum(const UserDataPermission input, web::json::value& output)
        {
            if (input == UserDataPermissionPrivate) output = web::json::value(L"Private");
            if (input == UserDataPermissionPublic) output = web::json::value(L"Public");
        }
        inline void FromJsonEnum(const web::json::value& input, UserDataPermission& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Private") output = UserDataPermissionPrivate;
            if (inputStr == L"Public") output = UserDataPermissionPublic;
        }

        enum UserOrigination
        {
            UserOriginationOrganic,
            UserOriginationSteam,
            UserOriginationGoogle,
            UserOriginationAmazon,
            UserOriginationFacebook,
            UserOriginationKongregate,
            UserOriginationGamersFirst,
            UserOriginationUnknown,
            UserOriginationIOS,
            UserOriginationLoadTest,
            UserOriginationAndroid,
            UserOriginationPSN,
            UserOriginationGameCenter,
            UserOriginationCustomId,
            UserOriginationXboxLive,
            UserOriginationParse,
            UserOriginationTwitch,
            UserOriginationWindowsHello,
            UserOriginationServerCustomId,
            UserOriginationNintendoSwitchDeviceId,
            UserOriginationFacebookInstantGamesId
        };

        inline void ToJsonEnum(const UserOrigination input, web::json::value& output)
        {
            if (input == UserOriginationOrganic) output = web::json::value(L"Organic");
            if (input == UserOriginationSteam) output = web::json::value(L"Steam");
            if (input == UserOriginationGoogle) output = web::json::value(L"Google");
            if (input == UserOriginationAmazon) output = web::json::value(L"Amazon");
            if (input == UserOriginationFacebook) output = web::json::value(L"Facebook");
            if (input == UserOriginationKongregate) output = web::json::value(L"Kongregate");
            if (input == UserOriginationGamersFirst) output = web::json::value(L"GamersFirst");
            if (input == UserOriginationUnknown) output = web::json::value(L"Unknown");
            if (input == UserOriginationIOS) output = web::json::value(L"IOS");
            if (input == UserOriginationLoadTest) output = web::json::value(L"LoadTest");
            if (input == UserOriginationAndroid) output = web::json::value(L"Android");
            if (input == UserOriginationPSN) output = web::json::value(L"PSN");
            if (input == UserOriginationGameCenter) output = web::json::value(L"GameCenter");
            if (input == UserOriginationCustomId) output = web::json::value(L"CustomId");
            if (input == UserOriginationXboxLive) output = web::json::value(L"XboxLive");
            if (input == UserOriginationParse) output = web::json::value(L"Parse");
            if (input == UserOriginationTwitch) output = web::json::value(L"Twitch");
            if (input == UserOriginationWindowsHello) output = web::json::value(L"WindowsHello");
            if (input == UserOriginationServerCustomId) output = web::json::value(L"ServerCustomId");
            if (input == UserOriginationNintendoSwitchDeviceId) output = web::json::value(L"NintendoSwitchDeviceId");
            if (input == UserOriginationFacebookInstantGamesId) output = web::json::value(L"FacebookInstantGamesId");
        }
        inline void FromJsonEnum(const web::json::value& input, UserOrigination& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Organic") output = UserOriginationOrganic;
            if (inputStr == L"Steam") output = UserOriginationSteam;
            if (inputStr == L"Google") output = UserOriginationGoogle;
            if (inputStr == L"Amazon") output = UserOriginationAmazon;
            if (inputStr == L"Facebook") output = UserOriginationFacebook;
            if (inputStr == L"Kongregate") output = UserOriginationKongregate;
            if (inputStr == L"GamersFirst") output = UserOriginationGamersFirst;
            if (inputStr == L"Unknown") output = UserOriginationUnknown;
            if (inputStr == L"IOS") output = UserOriginationIOS;
            if (inputStr == L"LoadTest") output = UserOriginationLoadTest;
            if (inputStr == L"Android") output = UserOriginationAndroid;
            if (inputStr == L"PSN") output = UserOriginationPSN;
            if (inputStr == L"GameCenter") output = UserOriginationGameCenter;
            if (inputStr == L"CustomId") output = UserOriginationCustomId;
            if (inputStr == L"XboxLive") output = UserOriginationXboxLive;
            if (inputStr == L"Parse") output = UserOriginationParse;
            if (inputStr == L"Twitch") output = UserOriginationTwitch;
            if (inputStr == L"WindowsHello") output = UserOriginationWindowsHello;
            if (inputStr == L"ServerCustomId") output = UserOriginationServerCustomId;
            if (inputStr == L"NintendoSwitchDeviceId") output = UserOriginationNintendoSwitchDeviceId;
            if (inputStr == L"FacebookInstantGamesId") output = UserOriginationFacebookInstantGamesId;
        }

        // Admin Classes
        struct AbortTaskInstanceRequest : public PlayFabRequestCommon
        {
            std::string TaskInstanceId;

            AbortTaskInstanceRequest() :
                PlayFabRequestCommon(),
                TaskInstanceId()
            {}

            AbortTaskInstanceRequest(const AbortTaskInstanceRequest& src) :
                PlayFabRequestCommon(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            ~AbortTaskInstanceRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TaskInstanceId"], TaskInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[L"TaskInstanceId"] = each_TaskInstanceId;
                return output;
            }
        };

        struct ActionsOnPlayersInSegmentTaskParameter : public PlayFabBaseModel
        {
            std::string ActionId;
            std::string SegmentId;

            ActionsOnPlayersInSegmentTaskParameter() :
                PlayFabBaseModel(),
                ActionId(),
                SegmentId()
            {}

            ActionsOnPlayersInSegmentTaskParameter(const ActionsOnPlayersInSegmentTaskParameter& src) :
                PlayFabBaseModel(),
                ActionId(src.ActionId),
                SegmentId(src.SegmentId)
            {}

            ~ActionsOnPlayersInSegmentTaskParameter() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ActionId"], ActionId);
                FromJsonUtilS(input[L"SegmentId"], SegmentId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActionId; ToJsonUtilS(ActionId, each_ActionId); output[L"ActionId"] = each_ActionId;
                web::json::value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output[L"SegmentId"] = each_SegmentId;
                return output;
            }
        };

        struct NameIdentifier : public PlayFabBaseModel
        {
            std::string Id;
            std::string Name;

            NameIdentifier() :
                PlayFabBaseModel(),
                Id(),
                Name()
            {}

            NameIdentifier(const NameIdentifier& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name)
            {}

            ~NameIdentifier() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Id"], Id);
                FromJsonUtilS(input[L"Name"], Name);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[L"Id"] = each_Id;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                return output;
            }
        };

        struct ActionsOnPlayersInSegmentTaskSummary : public PlayFabBaseModel
        {
            Boxed<time_t> CompletedAt;
            std::string ErrorMessage;
            Boxed<bool> ErrorWasFatal;
            Boxed<double> EstimatedSecondsRemaining;
            Boxed<double> PercentComplete;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            Boxed<NameIdentifier> TaskIdentifier;
            std::string TaskInstanceId;
            Boxed<Int32> TotalPlayersInSegment;
            Boxed<Int32> TotalPlayersProcessed;

            ActionsOnPlayersInSegmentTaskSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                ErrorMessage(),
                ErrorWasFatal(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                ScheduledByUserId(),
                StartedAt(),
                Status(),
                TaskIdentifier(),
                TaskInstanceId(),
                TotalPlayersInSegment(),
                TotalPlayersProcessed()
            {}

            ActionsOnPlayersInSegmentTaskSummary(const ActionsOnPlayersInSegmentTaskSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                ErrorMessage(src.ErrorMessage),
                ErrorWasFatal(src.ErrorWasFatal),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier),
                TaskInstanceId(src.TaskInstanceId),
                TotalPlayersInSegment(src.TotalPlayersInSegment),
                TotalPlayersProcessed(src.TotalPlayersProcessed)
            {}

            ~ActionsOnPlayersInSegmentTaskSummary() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"CompletedAt"], CompletedAt);
                FromJsonUtilS(input[L"ErrorMessage"], ErrorMessage);
                FromJsonUtilP(input[L"ErrorWasFatal"], ErrorWasFatal);
                FromJsonUtilP(input[L"EstimatedSecondsRemaining"], EstimatedSecondsRemaining);
                FromJsonUtilP(input[L"PercentComplete"], PercentComplete);
                FromJsonUtilS(input[L"ScheduledByUserId"], ScheduledByUserId);
                FromJsonUtilT(input[L"StartedAt"], StartedAt);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilO(input[L"TaskIdentifier"], TaskIdentifier);
                FromJsonUtilS(input[L"TaskInstanceId"], TaskInstanceId);
                FromJsonUtilP(input[L"TotalPlayersInSegment"], TotalPlayersInSegment);
                FromJsonUtilP(input[L"TotalPlayersProcessed"], TotalPlayersProcessed);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output[L"CompletedAt"] = each_CompletedAt;
                web::json::value each_ErrorMessage; ToJsonUtilS(ErrorMessage, each_ErrorMessage); output[L"ErrorMessage"] = each_ErrorMessage;
                web::json::value each_ErrorWasFatal; ToJsonUtilP(ErrorWasFatal, each_ErrorWasFatal); output[L"ErrorWasFatal"] = each_ErrorWasFatal;
                web::json::value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output[L"EstimatedSecondsRemaining"] = each_EstimatedSecondsRemaining;
                web::json::value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output[L"PercentComplete"] = each_PercentComplete;
                web::json::value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output[L"ScheduledByUserId"] = each_ScheduledByUserId;
                web::json::value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output[L"StartedAt"] = each_StartedAt;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output[L"TaskIdentifier"] = each_TaskIdentifier;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[L"TaskInstanceId"] = each_TaskInstanceId;
                web::json::value each_TotalPlayersInSegment; ToJsonUtilP(TotalPlayersInSegment, each_TotalPlayersInSegment); output[L"TotalPlayersInSegment"] = each_TotalPlayersInSegment;
                web::json::value each_TotalPlayersProcessed; ToJsonUtilP(TotalPlayersProcessed, each_TotalPlayersProcessed); output[L"TotalPlayersProcessed"] = each_TotalPlayersProcessed;
                return output;
            }
        };

        struct AdCampaignAttribution : public PlayFabBaseModel
        {
            time_t AttributedAt;
            std::string CampaignId;
            std::string Platform;

            AdCampaignAttribution() :
                PlayFabBaseModel(),
                AttributedAt(),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttribution(const AdCampaignAttribution& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            ~AdCampaignAttribution() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"AttributedAt"], AttributedAt);
                FromJsonUtilS(input[L"CampaignId"], CampaignId);
                FromJsonUtilS(input[L"Platform"], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AttributedAt; ToJsonUtilT(AttributedAt, each_AttributedAt); output[L"AttributedAt"] = each_AttributedAt;
                web::json::value each_CampaignId; ToJsonUtilS(CampaignId, each_CampaignId); output[L"CampaignId"] = each_CampaignId;
                web::json::value each_Platform; ToJsonUtilS(Platform, each_Platform); output[L"Platform"] = each_Platform;
                return output;
            }
        };

        struct AdCampaignAttributionModel : public PlayFabBaseModel
        {
            time_t AttributedAt;
            std::string CampaignId;
            std::string Platform;

            AdCampaignAttributionModel() :
                PlayFabBaseModel(),
                AttributedAt(),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttributionModel(const AdCampaignAttributionModel& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            ~AdCampaignAttributionModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"AttributedAt"], AttributedAt);
                FromJsonUtilS(input[L"CampaignId"], CampaignId);
                FromJsonUtilS(input[L"Platform"], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AttributedAt; ToJsonUtilT(AttributedAt, each_AttributedAt); output[L"AttributedAt"] = each_AttributedAt;
                web::json::value each_CampaignId; ToJsonUtilS(CampaignId, each_CampaignId); output[L"CampaignId"] = each_CampaignId;
                web::json::value each_Platform; ToJsonUtilS(Platform, each_Platform); output[L"Platform"] = each_Platform;
                return output;
            }
        };

        struct AddNewsRequest : public PlayFabRequestCommon
        {
            std::string Body;
            Boxed<time_t> Timestamp;
            std::string Title;

            AddNewsRequest() :
                PlayFabRequestCommon(),
                Body(),
                Timestamp(),
                Title()
            {}

            AddNewsRequest(const AddNewsRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                Timestamp(src.Timestamp),
                Title(src.Title)
            {}

            ~AddNewsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Body"], Body);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
                FromJsonUtilS(input[L"Title"], Title);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Body; ToJsonUtilS(Body, each_Body); output[L"Body"] = each_Body;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                web::json::value each_Title; ToJsonUtilS(Title, each_Title); output[L"Title"] = each_Title;
                return output;
            }
        };

        struct AddNewsResult : public PlayFabResultCommon
        {
            std::string NewsId;

            AddNewsResult() :
                PlayFabResultCommon(),
                NewsId()
            {}

            AddNewsResult(const AddNewsResult& src) :
                PlayFabResultCommon(),
                NewsId(src.NewsId)
            {}

            ~AddNewsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"NewsId"], NewsId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_NewsId; ToJsonUtilS(NewsId, each_NewsId); output[L"NewsId"] = each_NewsId;
                return output;
            }
        };

        struct AddPlayerTagRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;
            std::string TagName;

            AddPlayerTagRequest() :
                PlayFabRequestCommon(),
                PlayFabId(),
                TagName()
            {}

            AddPlayerTagRequest(const AddPlayerTagRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            ~AddPlayerTagRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"TagName"], TagName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_TagName; ToJsonUtilS(TagName, each_TagName); output[L"TagName"] = each_TagName;
                return output;
            }
        };

        struct AddPlayerTagResult : public PlayFabResultCommon
        {

            AddPlayerTagResult() :
                PlayFabResultCommon()
            {}

            AddPlayerTagResult(const AddPlayerTagResult&) :
                PlayFabResultCommon()
            {}

            ~AddPlayerTagResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AddServerBuildRequest : public PlayFabRequestCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;

            AddServerBuildRequest() :
                PlayFabRequestCommon(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(),
                MinFreeGameSlots()
            {}

            AddServerBuildRequest(const AddServerBuildRequest& src) :
                PlayFabRequestCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots)
            {}

            ~AddServerBuildRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input[L"BuildId"], BuildId);
                FromJsonUtilS(input[L"CommandLineTemplate"], CommandLineTemplate);
                FromJsonUtilS(input[L"Comment"], Comment);
                FromJsonUtilS(input[L"ExecutablePath"], ExecutablePath);
                FromJsonUtilP(input[L"MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input[L"MinFreeGameSlots"], MinFreeGameSlots);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[L"ActiveRegions"] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[L"BuildId"] = each_BuildId;
                web::json::value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output[L"CommandLineTemplate"] = each_CommandLineTemplate;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[L"Comment"] = each_Comment;
                web::json::value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output[L"ExecutablePath"] = each_ExecutablePath;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[L"MaxGamesPerHost"] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[L"MinFreeGameSlots"] = each_MinFreeGameSlots;
                return output;
            }
        };

        struct AddServerBuildResult : public PlayFabResultCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            AddServerBuildResult() :
                PlayFabResultCommon(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(),
                MinFreeGameSlots(),
                Status(),
                Timestamp(),
                TitleId()
            {}

            AddServerBuildResult(const AddServerBuildResult& src) :
                PlayFabResultCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            ~AddServerBuildResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input[L"BuildId"], BuildId);
                FromJsonUtilS(input[L"CommandLineTemplate"], CommandLineTemplate);
                FromJsonUtilS(input[L"Comment"], Comment);
                FromJsonUtilS(input[L"ExecutablePath"], ExecutablePath);
                FromJsonUtilP(input[L"MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input[L"MinFreeGameSlots"], MinFreeGameSlots);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[L"ActiveRegions"] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[L"BuildId"] = each_BuildId;
                web::json::value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output[L"CommandLineTemplate"] = each_CommandLineTemplate;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[L"Comment"] = each_Comment;
                web::json::value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output[L"ExecutablePath"] = each_ExecutablePath;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[L"MaxGamesPerHost"] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[L"MinFreeGameSlots"] = each_MinFreeGameSlots;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string PlayFabId;
            std::string VirtualCurrency;

            AddUserVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                PlayFabId(),
                VirtualCurrency()
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~AddUserVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Amount"], Amount);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"VirtualCurrency"], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[L"Amount"] = each_Amount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct VirtualCurrencyData : public PlayFabBaseModel
        {
            std::string CurrencyCode;
            std::string DisplayName;
            Boxed<Int32> InitialDeposit;
            Boxed<Int32> RechargeMax;
            Boxed<Int32> RechargeRate;

            VirtualCurrencyData() :
                PlayFabBaseModel(),
                CurrencyCode(),
                DisplayName(),
                InitialDeposit(),
                RechargeMax(),
                RechargeRate()
            {}

            VirtualCurrencyData(const VirtualCurrencyData& src) :
                PlayFabBaseModel(),
                CurrencyCode(src.CurrencyCode),
                DisplayName(src.DisplayName),
                InitialDeposit(src.InitialDeposit),
                RechargeMax(src.RechargeMax),
                RechargeRate(src.RechargeRate)
            {}

            ~VirtualCurrencyData() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CurrencyCode"], CurrencyCode);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilP(input[L"InitialDeposit"], InitialDeposit);
                FromJsonUtilP(input[L"RechargeMax"], RechargeMax);
                FromJsonUtilP(input[L"RechargeRate"], RechargeRate);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[L"CurrencyCode"] = each_CurrencyCode;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_InitialDeposit; ToJsonUtilP(InitialDeposit, each_InitialDeposit); output[L"InitialDeposit"] = each_InitialDeposit;
                web::json::value each_RechargeMax; ToJsonUtilP(RechargeMax, each_RechargeMax); output[L"RechargeMax"] = each_RechargeMax;
                web::json::value each_RechargeRate; ToJsonUtilP(RechargeRate, each_RechargeRate); output[L"RechargeRate"] = each_RechargeRate;
                return output;
            }
        };

        struct AddVirtualCurrencyTypesRequest : public PlayFabRequestCommon
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            AddVirtualCurrencyTypesRequest() :
                PlayFabRequestCommon(),
                VirtualCurrencies()
            {}

            AddVirtualCurrencyTypesRequest(const AddVirtualCurrencyTypesRequest& src) :
                PlayFabRequestCommon(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ~AddVirtualCurrencyTypesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"VirtualCurrencies"], VirtualCurrencies);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output[L"VirtualCurrencies"] = each_VirtualCurrencies;
                return output;
            }
        };

        struct ApiCondition : public PlayFabBaseModel
        {
            Boxed<Conditionals> HasSignatureOrEncryption;

            ApiCondition() :
                PlayFabBaseModel(),
                HasSignatureOrEncryption()
            {}

            ApiCondition(const ApiCondition& src) :
                PlayFabBaseModel(),
                HasSignatureOrEncryption(src.HasSignatureOrEncryption)
            {}

            ~ApiCondition() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"HasSignatureOrEncryption"], HasSignatureOrEncryption);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_HasSignatureOrEncryption; ToJsonUtilE(HasSignatureOrEncryption, each_HasSignatureOrEncryption); output[L"HasSignatureOrEncryption"] = each_HasSignatureOrEncryption;
                return output;
            }
        };

        struct BanInfo : public PlayFabBaseModel
        {
            bool Active;
            std::string BanId;
            Boxed<time_t> Created;
            Boxed<time_t> Expires;
            std::string IPAddress;
            std::string MACAddress;
            std::string PlayFabId;
            std::string Reason;

            BanInfo() :
                PlayFabBaseModel(),
                Active(),
                BanId(),
                Created(),
                Expires(),
                IPAddress(),
                MACAddress(),
                PlayFabId(),
                Reason()
            {}

            BanInfo(const BanInfo& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                BanId(src.BanId),
                Created(src.Created),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ~BanInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Active"], Active);
                FromJsonUtilS(input[L"BanId"], BanId);
                FromJsonUtilT(input[L"Created"], Created);
                FromJsonUtilT(input[L"Expires"], Expires);
                FromJsonUtilS(input[L"IPAddress"], IPAddress);
                FromJsonUtilS(input[L"MACAddress"], MACAddress);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"Reason"], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Active; ToJsonUtilP(Active, each_Active); output[L"Active"] = each_Active;
                web::json::value each_BanId; ToJsonUtilS(BanId, each_BanId); output[L"BanId"] = each_BanId;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[L"Created"] = each_Created;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[L"Expires"] = each_Expires;
                web::json::value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output[L"IPAddress"] = each_IPAddress;
                web::json::value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output[L"MACAddress"] = each_MACAddress;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[L"Reason"] = each_Reason;
                return output;
            }
        };

        struct BanRequest : public PlayFabRequestCommon
        {
            Boxed<Uint32> DurationInHours;
            std::string IPAddress;
            std::string MACAddress;
            std::string PlayFabId;
            std::string Reason;

            BanRequest() :
                PlayFabRequestCommon(),
                DurationInHours(),
                IPAddress(),
                MACAddress(),
                PlayFabId(),
                Reason()
            {}

            BanRequest(const BanRequest& src) :
                PlayFabRequestCommon(),
                DurationInHours(src.DurationInHours),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ~BanRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"DurationInHours"], DurationInHours);
                FromJsonUtilS(input[L"IPAddress"], IPAddress);
                FromJsonUtilS(input[L"MACAddress"], MACAddress);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"Reason"], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DurationInHours; ToJsonUtilP(DurationInHours, each_DurationInHours); output[L"DurationInHours"] = each_DurationInHours;
                web::json::value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output[L"IPAddress"] = each_IPAddress;
                web::json::value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output[L"MACAddress"] = each_MACAddress;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[L"Reason"] = each_Reason;
                return output;
            }
        };

        struct BanUsersRequest : public PlayFabRequestCommon
        {
            std::list<BanRequest> Bans;

            BanUsersRequest() :
                PlayFabRequestCommon(),
                Bans()
            {}

            BanUsersRequest(const BanUsersRequest& src) :
                PlayFabRequestCommon(),
                Bans(src.Bans)
            {}

            ~BanUsersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Bans"], Bans);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Bans; ToJsonUtilO(Bans, each_Bans); output[L"Bans"] = each_Bans;
                return output;
            }
        };

        struct BanUsersResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            BanUsersResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            BanUsersResult(const BanUsersResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~BanUsersResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"BanData"], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[L"BanData"] = each_BanData;
                return output;
            }
        };

        struct BlankResult : public PlayFabResultCommon
        {

            BlankResult() :
                PlayFabResultCommon()
            {}

            BlankResult(const BlankResult&) :
                PlayFabResultCommon()
            {}

            ~BlankResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct CatalogItemBundleInfo : public PlayFabBaseModel
        {
            std::list<std::string> BundledItems;
            std::list<std::string> BundledResultTables;
            std::map<std::string, Uint32> BundledVirtualCurrencies;

            CatalogItemBundleInfo() :
                PlayFabBaseModel(),
                BundledItems(),
                BundledResultTables(),
                BundledVirtualCurrencies()
            {}

            CatalogItemBundleInfo(const CatalogItemBundleInfo& src) :
                PlayFabBaseModel(),
                BundledItems(src.BundledItems),
                BundledResultTables(src.BundledResultTables),
                BundledVirtualCurrencies(src.BundledVirtualCurrencies)
            {}

            ~CatalogItemBundleInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BundledItems"], BundledItems);
                FromJsonUtilS(input[L"BundledResultTables"], BundledResultTables);
                FromJsonUtilP(input[L"BundledVirtualCurrencies"], BundledVirtualCurrencies);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BundledItems; ToJsonUtilS(BundledItems, each_BundledItems); output[L"BundledItems"] = each_BundledItems;
                web::json::value each_BundledResultTables; ToJsonUtilS(BundledResultTables, each_BundledResultTables); output[L"BundledResultTables"] = each_BundledResultTables;
                web::json::value each_BundledVirtualCurrencies; ToJsonUtilP(BundledVirtualCurrencies, each_BundledVirtualCurrencies); output[L"BundledVirtualCurrencies"] = each_BundledVirtualCurrencies;
                return output;
            }
        };

        struct CatalogItemConsumableInfo : public PlayFabBaseModel
        {
            Boxed<Uint32> UsageCount;
            Boxed<Uint32> UsagePeriod;
            std::string UsagePeriodGroup;

            CatalogItemConsumableInfo() :
                PlayFabBaseModel(),
                UsageCount(),
                UsagePeriod(),
                UsagePeriodGroup()
            {}

            CatalogItemConsumableInfo(const CatalogItemConsumableInfo& src) :
                PlayFabBaseModel(),
                UsageCount(src.UsageCount),
                UsagePeriod(src.UsagePeriod),
                UsagePeriodGroup(src.UsagePeriodGroup)
            {}

            ~CatalogItemConsumableInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"UsageCount"], UsageCount);
                FromJsonUtilP(input[L"UsagePeriod"], UsagePeriod);
                FromJsonUtilS(input[L"UsagePeriodGroup"], UsagePeriodGroup);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_UsageCount; ToJsonUtilP(UsageCount, each_UsageCount); output[L"UsageCount"] = each_UsageCount;
                web::json::value each_UsagePeriod; ToJsonUtilP(UsagePeriod, each_UsagePeriod); output[L"UsagePeriod"] = each_UsagePeriod;
                web::json::value each_UsagePeriodGroup; ToJsonUtilS(UsagePeriodGroup, each_UsagePeriodGroup); output[L"UsagePeriodGroup"] = each_UsagePeriodGroup;
                return output;
            }
        };

        struct CatalogItemContainerInfo : public PlayFabBaseModel
        {
            std::list<std::string> ItemContents;
            std::string KeyItemId;
            std::list<std::string> ResultTableContents;
            std::map<std::string, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                ItemContents(),
                KeyItemId(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                ItemContents(src.ItemContents),
                KeyItemId(src.KeyItemId),
                ResultTableContents(src.ResultTableContents),
                VirtualCurrencyContents(src.VirtualCurrencyContents)
            {}

            ~CatalogItemContainerInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ItemContents"], ItemContents);
                FromJsonUtilS(input[L"KeyItemId"], KeyItemId);
                FromJsonUtilS(input[L"ResultTableContents"], ResultTableContents);
                FromJsonUtilP(input[L"VirtualCurrencyContents"], VirtualCurrencyContents);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemContents; ToJsonUtilS(ItemContents, each_ItemContents); output[L"ItemContents"] = each_ItemContents;
                web::json::value each_KeyItemId; ToJsonUtilS(KeyItemId, each_KeyItemId); output[L"KeyItemId"] = each_KeyItemId;
                web::json::value each_ResultTableContents; ToJsonUtilS(ResultTableContents, each_ResultTableContents); output[L"ResultTableContents"] = each_ResultTableContents;
                web::json::value each_VirtualCurrencyContents; ToJsonUtilP(VirtualCurrencyContents, each_VirtualCurrencyContents); output[L"VirtualCurrencyContents"] = each_VirtualCurrencyContents;
                return output;
            }
        };

        struct CatalogItem : public PlayFabBaseModel
        {
            Boxed<CatalogItemBundleInfo> Bundle;
            bool CanBecomeCharacter;
            std::string CatalogVersion;
            Boxed<CatalogItemConsumableInfo> Consumable;
            Boxed<CatalogItemContainerInfo> Container;
            std::string CustomData;
            std::string Description;
            std::string DisplayName;
            Int32 InitialLimitedEditionCount;
            bool IsLimitedEdition;
            bool IsStackable;
            bool IsTradable;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemImageUrl;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::list<std::string> Tags;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            CatalogItem() :
                PlayFabBaseModel(),
                Bundle(),
                CanBecomeCharacter(),
                CatalogVersion(),
                Consumable(),
                Container(),
                CustomData(),
                Description(),
                DisplayName(),
                InitialLimitedEditionCount(),
                IsLimitedEdition(),
                IsStackable(),
                IsTradable(),
                ItemClass(),
                ItemId(),
                ItemImageUrl(),
                RealCurrencyPrices(),
                Tags(),
                VirtualCurrencyPrices()
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                Bundle(src.Bundle),
                CanBecomeCharacter(src.CanBecomeCharacter),
                CatalogVersion(src.CatalogVersion),
                Consumable(src.Consumable),
                Container(src.Container),
                CustomData(src.CustomData),
                Description(src.Description),
                DisplayName(src.DisplayName),
                InitialLimitedEditionCount(src.InitialLimitedEditionCount),
                IsLimitedEdition(src.IsLimitedEdition),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemImageUrl(src.ItemImageUrl),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            ~CatalogItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Bundle"], Bundle);
                FromJsonUtilP(input[L"CanBecomeCharacter"], CanBecomeCharacter);
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input[L"Consumable"], Consumable);
                FromJsonUtilO(input[L"Container"], Container);
                FromJsonUtilS(input[L"CustomData"], CustomData);
                FromJsonUtilS(input[L"Description"], Description);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilP(input[L"InitialLimitedEditionCount"], InitialLimitedEditionCount);
                FromJsonUtilP(input[L"IsLimitedEdition"], IsLimitedEdition);
                FromJsonUtilP(input[L"IsStackable"], IsStackable);
                FromJsonUtilP(input[L"IsTradable"], IsTradable);
                FromJsonUtilS(input[L"ItemClass"], ItemClass);
                FromJsonUtilS(input[L"ItemId"], ItemId);
                FromJsonUtilS(input[L"ItemImageUrl"], ItemImageUrl);
                FromJsonUtilP(input[L"RealCurrencyPrices"], RealCurrencyPrices);
                FromJsonUtilS(input[L"Tags"], Tags);
                FromJsonUtilP(input[L"VirtualCurrencyPrices"], VirtualCurrencyPrices);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Bundle; ToJsonUtilO(Bundle, each_Bundle); output[L"Bundle"] = each_Bundle;
                web::json::value each_CanBecomeCharacter; ToJsonUtilP(CanBecomeCharacter, each_CanBecomeCharacter); output[L"CanBecomeCharacter"] = each_CanBecomeCharacter;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_Consumable; ToJsonUtilO(Consumable, each_Consumable); output[L"Consumable"] = each_Consumable;
                web::json::value each_Container; ToJsonUtilO(Container, each_Container); output[L"Container"] = each_Container;
                web::json::value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output[L"CustomData"] = each_CustomData;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[L"Description"] = each_Description;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_InitialLimitedEditionCount; ToJsonUtilP(InitialLimitedEditionCount, each_InitialLimitedEditionCount); output[L"InitialLimitedEditionCount"] = each_InitialLimitedEditionCount;
                web::json::value each_IsLimitedEdition; ToJsonUtilP(IsLimitedEdition, each_IsLimitedEdition); output[L"IsLimitedEdition"] = each_IsLimitedEdition;
                web::json::value each_IsStackable; ToJsonUtilP(IsStackable, each_IsStackable); output[L"IsStackable"] = each_IsStackable;
                web::json::value each_IsTradable; ToJsonUtilP(IsTradable, each_IsTradable); output[L"IsTradable"] = each_IsTradable;
                web::json::value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output[L"ItemClass"] = each_ItemClass;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                web::json::value each_ItemImageUrl; ToJsonUtilS(ItemImageUrl, each_ItemImageUrl); output[L"ItemImageUrl"] = each_ItemImageUrl;
                web::json::value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output[L"RealCurrencyPrices"] = each_RealCurrencyPrices;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[L"Tags"] = each_Tags;
                web::json::value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output[L"VirtualCurrencyPrices"] = each_VirtualCurrencyPrices;
                return output;
            }
        };

        struct CheckLimitedEditionItemAvailabilityRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string ItemId;

            CheckLimitedEditionItemAvailabilityRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                ItemId()
            {}

            CheckLimitedEditionItemAvailabilityRequest(const CheckLimitedEditionItemAvailabilityRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                ItemId(src.ItemId)
            {}

            ~CheckLimitedEditionItemAvailabilityRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"ItemId"], ItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                return output;
            }
        };

        struct CheckLimitedEditionItemAvailabilityResult : public PlayFabResultCommon
        {
            Int32 Amount;

            CheckLimitedEditionItemAvailabilityResult() :
                PlayFabResultCommon(),
                Amount()
            {}

            CheckLimitedEditionItemAvailabilityResult(const CheckLimitedEditionItemAvailabilityResult& src) :
                PlayFabResultCommon(),
                Amount(src.Amount)
            {}

            ~CheckLimitedEditionItemAvailabilityResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Amount"], Amount);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[L"Amount"] = each_Amount;
                return output;
            }
        };

        struct CloudScriptFile : public PlayFabBaseModel
        {
            std::string FileContents;
            std::string Filename;

            CloudScriptFile() :
                PlayFabBaseModel(),
                FileContents(),
                Filename()
            {}

            CloudScriptFile(const CloudScriptFile& src) :
                PlayFabBaseModel(),
                FileContents(src.FileContents),
                Filename(src.Filename)
            {}

            ~CloudScriptFile() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FileContents"], FileContents);
                FromJsonUtilS(input[L"Filename"], Filename);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FileContents; ToJsonUtilS(FileContents, each_FileContents); output[L"FileContents"] = each_FileContents;
                web::json::value each_Filename; ToJsonUtilS(Filename, each_Filename); output[L"Filename"] = each_Filename;
                return output;
            }
        };

        struct CloudScriptTaskParameter : public PlayFabBaseModel
        {
            web::json::value Argument;
            std::string FunctionName;

            CloudScriptTaskParameter() :
                PlayFabBaseModel(),
                Argument(),
                FunctionName()
            {}

            CloudScriptTaskParameter(const CloudScriptTaskParameter& src) :
                PlayFabBaseModel(),
                Argument(src.Argument),
                FunctionName(src.FunctionName)
            {}

            ~CloudScriptTaskParameter() { }

            void FromJson(web::json::value& input) override
            {
                Argument = input[L"Argument"];
                FromJsonUtilS(input[L"FunctionName"], FunctionName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"Argument"] = Argument;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[L"FunctionName"] = each_FunctionName;
                return output;
            }
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
            std::string Error;
            std::string Message;
            std::string StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ~ScriptExecutionError() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Error"], Error);
                FromJsonUtilS(input[L"Message"], Message);
                FromJsonUtilS(input[L"StackTrace"], StackTrace);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Error; ToJsonUtilS(Error, each_Error); output[L"Error"] = each_Error;
                web::json::value each_Message; ToJsonUtilS(Message, each_Message); output[L"Message"] = each_Message;
                web::json::value each_StackTrace; ToJsonUtilS(StackTrace, each_StackTrace); output[L"StackTrace"] = each_StackTrace;
                return output;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
            web::json::value Data;
            std::string Level;
            std::string Message;

            LogStatement() :
                PlayFabBaseModel(),
                Data(),
                Level(),
                Message()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Level(src.Level),
                Message(src.Message)
            {}

            ~LogStatement() { }

            void FromJson(web::json::value& input) override
            {
                Data = input[L"Data"];
                FromJsonUtilS(input[L"Level"], Level);
                FromJsonUtilS(input[L"Message"], Message);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"Data"] = Data;
                web::json::value each_Level; ToJsonUtilS(Level, each_Level); output[L"Level"] = each_Level;
                web::json::value each_Message; ToJsonUtilS(Message, each_Message); output[L"Message"] = each_Message;
                return output;
            }
        };

        struct ExecuteCloudScriptResult : public PlayFabResultCommon
        {
            Int32 APIRequestsIssued;
            Boxed<ScriptExecutionError> Error;
            double ExecutionTimeSeconds;
            std::string FunctionName;
            web::json::value FunctionResult;
            Boxed<bool> FunctionResultTooLarge;
            Int32 HttpRequestsIssued;
            std::list<LogStatement> Logs;
            Boxed<bool> LogsTooLarge;
            Uint32 MemoryConsumedBytes;
            double ProcessorTimeSeconds;
            Int32 Revision;

            ExecuteCloudScriptResult() :
                PlayFabResultCommon(),
                APIRequestsIssued(),
                Error(),
                ExecutionTimeSeconds(),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge(),
                HttpRequestsIssued(),
                Logs(),
                LogsTooLarge(),
                MemoryConsumedBytes(),
                ProcessorTimeSeconds(),
                Revision()
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabResultCommon(),
                APIRequestsIssued(src.APIRequestsIssued),
                Error(src.Error),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                Revision(src.Revision)
            {}

            ~ExecuteCloudScriptResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"APIRequestsIssued"], APIRequestsIssued);
                FromJsonUtilO(input[L"Error"], Error);
                FromJsonUtilP(input[L"ExecutionTimeSeconds"], ExecutionTimeSeconds);
                FromJsonUtilS(input[L"FunctionName"], FunctionName);
                FunctionResult = input[L"FunctionResult"];
                FromJsonUtilP(input[L"FunctionResultTooLarge"], FunctionResultTooLarge);
                FromJsonUtilP(input[L"HttpRequestsIssued"], HttpRequestsIssued);
                FromJsonUtilO(input[L"Logs"], Logs);
                FromJsonUtilP(input[L"LogsTooLarge"], LogsTooLarge);
                FromJsonUtilP(input[L"MemoryConsumedBytes"], MemoryConsumedBytes);
                FromJsonUtilP(input[L"ProcessorTimeSeconds"], ProcessorTimeSeconds);
                FromJsonUtilP(input[L"Revision"], Revision);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_APIRequestsIssued; ToJsonUtilP(APIRequestsIssued, each_APIRequestsIssued); output[L"APIRequestsIssued"] = each_APIRequestsIssued;
                web::json::value each_Error; ToJsonUtilO(Error, each_Error); output[L"Error"] = each_Error;
                web::json::value each_ExecutionTimeSeconds; ToJsonUtilP(ExecutionTimeSeconds, each_ExecutionTimeSeconds); output[L"ExecutionTimeSeconds"] = each_ExecutionTimeSeconds;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[L"FunctionName"] = each_FunctionName;
                output[L"FunctionResult"] = FunctionResult;
                web::json::value each_FunctionResultTooLarge; ToJsonUtilP(FunctionResultTooLarge, each_FunctionResultTooLarge); output[L"FunctionResultTooLarge"] = each_FunctionResultTooLarge;
                web::json::value each_HttpRequestsIssued; ToJsonUtilP(HttpRequestsIssued, each_HttpRequestsIssued); output[L"HttpRequestsIssued"] = each_HttpRequestsIssued;
                web::json::value each_Logs; ToJsonUtilO(Logs, each_Logs); output[L"Logs"] = each_Logs;
                web::json::value each_LogsTooLarge; ToJsonUtilP(LogsTooLarge, each_LogsTooLarge); output[L"LogsTooLarge"] = each_LogsTooLarge;
                web::json::value each_MemoryConsumedBytes; ToJsonUtilP(MemoryConsumedBytes, each_MemoryConsumedBytes); output[L"MemoryConsumedBytes"] = each_MemoryConsumedBytes;
                web::json::value each_ProcessorTimeSeconds; ToJsonUtilP(ProcessorTimeSeconds, each_ProcessorTimeSeconds); output[L"ProcessorTimeSeconds"] = each_ProcessorTimeSeconds;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[L"Revision"] = each_Revision;
                return output;
            }
        };

        struct CloudScriptTaskSummary : public PlayFabBaseModel
        {
            Boxed<time_t> CompletedAt;
            Boxed<double> EstimatedSecondsRemaining;
            Boxed<double> PercentComplete;
            Boxed<ExecuteCloudScriptResult> Result;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            Boxed<NameIdentifier> TaskIdentifier;
            std::string TaskInstanceId;

            CloudScriptTaskSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                Result(),
                ScheduledByUserId(),
                StartedAt(),
                Status(),
                TaskIdentifier(),
                TaskInstanceId()
            {}

            CloudScriptTaskSummary(const CloudScriptTaskSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                Result(src.Result),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier),
                TaskInstanceId(src.TaskInstanceId)
            {}

            ~CloudScriptTaskSummary() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"CompletedAt"], CompletedAt);
                FromJsonUtilP(input[L"EstimatedSecondsRemaining"], EstimatedSecondsRemaining);
                FromJsonUtilP(input[L"PercentComplete"], PercentComplete);
                FromJsonUtilO(input[L"Result"], Result);
                FromJsonUtilS(input[L"ScheduledByUserId"], ScheduledByUserId);
                FromJsonUtilT(input[L"StartedAt"], StartedAt);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilO(input[L"TaskIdentifier"], TaskIdentifier);
                FromJsonUtilS(input[L"TaskInstanceId"], TaskInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output[L"CompletedAt"] = each_CompletedAt;
                web::json::value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output[L"EstimatedSecondsRemaining"] = each_EstimatedSecondsRemaining;
                web::json::value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output[L"PercentComplete"] = each_PercentComplete;
                web::json::value each_Result; ToJsonUtilO(Result, each_Result); output[L"Result"] = each_Result;
                web::json::value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output[L"ScheduledByUserId"] = each_ScheduledByUserId;
                web::json::value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output[L"StartedAt"] = each_StartedAt;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output[L"TaskIdentifier"] = each_TaskIdentifier;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[L"TaskInstanceId"] = each_TaskInstanceId;
                return output;
            }
        };

        struct CloudScriptVersionStatus : public PlayFabBaseModel
        {
            Int32 LatestRevision;
            Int32 PublishedRevision;
            Int32 Version;

            CloudScriptVersionStatus() :
                PlayFabBaseModel(),
                LatestRevision(),
                PublishedRevision(),
                Version()
            {}

            CloudScriptVersionStatus(const CloudScriptVersionStatus& src) :
                PlayFabBaseModel(),
                LatestRevision(src.LatestRevision),
                PublishedRevision(src.PublishedRevision),
                Version(src.Version)
            {}

            ~CloudScriptVersionStatus() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"LatestRevision"], LatestRevision);
                FromJsonUtilP(input[L"PublishedRevision"], PublishedRevision);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LatestRevision; ToJsonUtilP(LatestRevision, each_LatestRevision); output[L"LatestRevision"] = each_LatestRevision;
                web::json::value each_PublishedRevision; ToJsonUtilP(PublishedRevision, each_PublishedRevision); output[L"PublishedRevision"] = each_PublishedRevision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct ContactEmailInfo : public PlayFabBaseModel
        {
            std::string EmailAddress;
            std::string Name;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfo() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name(),
                VerificationStatus()
            {}

            ContactEmailInfo(const ContactEmailInfo& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name),
                VerificationStatus(src.VerificationStatus)
            {}

            ~ContactEmailInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"EmailAddress"], EmailAddress);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilE(input[L"VerificationStatus"], VerificationStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EmailAddress; ToJsonUtilS(EmailAddress, each_EmailAddress); output[L"EmailAddress"] = each_EmailAddress;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_VerificationStatus; ToJsonUtilE(VerificationStatus, each_VerificationStatus); output[L"VerificationStatus"] = each_VerificationStatus;
                return output;
            }
        };

        struct ContactEmailInfoModel : public PlayFabBaseModel
        {
            std::string EmailAddress;
            std::string Name;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfoModel() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name(),
                VerificationStatus()
            {}

            ContactEmailInfoModel(const ContactEmailInfoModel& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name),
                VerificationStatus(src.VerificationStatus)
            {}

            ~ContactEmailInfoModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"EmailAddress"], EmailAddress);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilE(input[L"VerificationStatus"], VerificationStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EmailAddress; ToJsonUtilS(EmailAddress, each_EmailAddress); output[L"EmailAddress"] = each_EmailAddress;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_VerificationStatus; ToJsonUtilE(VerificationStatus, each_VerificationStatus); output[L"VerificationStatus"] = each_VerificationStatus;
                return output;
            }
        };

        struct ContentInfo : public PlayFabBaseModel
        {
            std::string Key;
            time_t LastModified;
            Uint32 Size;

            ContentInfo() :
                PlayFabBaseModel(),
                Key(),
                LastModified(),
                Size()
            {}

            ContentInfo(const ContentInfo& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            ~ContentInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Key"], Key);
                FromJsonUtilT(input[L"LastModified"], LastModified);
                FromJsonUtilP(input[L"Size"], Size);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[L"Key"] = each_Key;
                web::json::value each_LastModified; ToJsonUtilT(LastModified, each_LastModified); output[L"LastModified"] = each_LastModified;
                web::json::value each_Size; ToJsonUtilP(Size, each_Size); output[L"Size"] = each_Size;
                return output;
            }
        };

        struct CreateActionsOnPlayerSegmentTaskRequest : public PlayFabRequestCommon
        {
            std::string Description;
            bool IsActive;
            std::string Name;
            ActionsOnPlayersInSegmentTaskParameter Parameter;
            std::string Schedule;

            CreateActionsOnPlayerSegmentTaskRequest() :
                PlayFabRequestCommon(),
                Description(),
                IsActive(),
                Name(),
                Parameter(),
                Schedule()
            {}

            CreateActionsOnPlayerSegmentTaskRequest(const CreateActionsOnPlayerSegmentTaskRequest& src) :
                PlayFabRequestCommon(),
                Description(src.Description),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule)
            {}

            ~CreateActionsOnPlayerSegmentTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Description"], Description);
                FromJsonUtilP(input[L"IsActive"], IsActive);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilO(input[L"Parameter"], Parameter);
                FromJsonUtilS(input[L"Schedule"], Schedule);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[L"Description"] = each_Description;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[L"IsActive"] = each_IsActive;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output[L"Parameter"] = each_Parameter;
                web::json::value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output[L"Schedule"] = each_Schedule;
                return output;
            }
        };

        struct CreateCloudScriptTaskRequest : public PlayFabRequestCommon
        {
            std::string Description;
            bool IsActive;
            std::string Name;
            CloudScriptTaskParameter Parameter;
            std::string Schedule;

            CreateCloudScriptTaskRequest() :
                PlayFabRequestCommon(),
                Description(),
                IsActive(),
                Name(),
                Parameter(),
                Schedule()
            {}

            CreateCloudScriptTaskRequest(const CreateCloudScriptTaskRequest& src) :
                PlayFabRequestCommon(),
                Description(src.Description),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule)
            {}

            ~CreateCloudScriptTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Description"], Description);
                FromJsonUtilP(input[L"IsActive"], IsActive);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilO(input[L"Parameter"], Parameter);
                FromJsonUtilS(input[L"Schedule"], Schedule);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[L"Description"] = each_Description;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[L"IsActive"] = each_IsActive;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output[L"Parameter"] = each_Parameter;
                web::json::value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output[L"Schedule"] = each_Schedule;
                return output;
            }
        };

        struct CreatePlayerSharedSecretRequest : public PlayFabRequestCommon
        {
            std::string FriendlyName;

            CreatePlayerSharedSecretRequest() :
                PlayFabRequestCommon(),
                FriendlyName()
            {}

            CreatePlayerSharedSecretRequest(const CreatePlayerSharedSecretRequest& src) :
                PlayFabRequestCommon(),
                FriendlyName(src.FriendlyName)
            {}

            ~CreatePlayerSharedSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FriendlyName"], FriendlyName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output[L"FriendlyName"] = each_FriendlyName;
                return output;
            }
        };

        struct CreatePlayerSharedSecretResult : public PlayFabResultCommon
        {
            std::string SecretKey;

            CreatePlayerSharedSecretResult() :
                PlayFabResultCommon(),
                SecretKey()
            {}

            CreatePlayerSharedSecretResult(const CreatePlayerSharedSecretResult& src) :
                PlayFabResultCommon(),
                SecretKey(src.SecretKey)
            {}

            ~CreatePlayerSharedSecretResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"SecretKey"], SecretKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output[L"SecretKey"] = each_SecretKey;
                return output;
            }
        };

        struct CreatePlayerStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            CreatePlayerStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                AggregationMethod(),
                StatisticName(),
                VersionChangeInterval()
            {}

            CreatePlayerStatisticDefinitionRequest(const CreatePlayerStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                AggregationMethod(src.AggregationMethod),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            ~CreatePlayerStatisticDefinitionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"AggregationMethod"], AggregationMethod);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilE(input[L"VersionChangeInterval"], VersionChangeInterval);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output[L"AggregationMethod"] = each_AggregationMethod;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output[L"VersionChangeInterval"] = each_VersionChangeInterval;
                return output;
            }
        };

        struct PlayerStatisticDefinition : public PlayFabBaseModel
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            Uint32 CurrentVersion;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            PlayerStatisticDefinition() :
                PlayFabBaseModel(),
                AggregationMethod(),
                CurrentVersion(),
                StatisticName(),
                VersionChangeInterval()
            {}

            PlayerStatisticDefinition(const PlayerStatisticDefinition& src) :
                PlayFabBaseModel(),
                AggregationMethod(src.AggregationMethod),
                CurrentVersion(src.CurrentVersion),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            ~PlayerStatisticDefinition() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"AggregationMethod"], AggregationMethod);
                FromJsonUtilP(input[L"CurrentVersion"], CurrentVersion);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilE(input[L"VersionChangeInterval"], VersionChangeInterval);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output[L"AggregationMethod"] = each_AggregationMethod;
                web::json::value each_CurrentVersion; ToJsonUtilP(CurrentVersion, each_CurrentVersion); output[L"CurrentVersion"] = each_CurrentVersion;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output[L"VersionChangeInterval"] = each_VersionChangeInterval;
                return output;
            }
        };

        struct CreatePlayerStatisticDefinitionResult : public PlayFabResultCommon
        {
            Boxed<PlayerStatisticDefinition> Statistic;

            CreatePlayerStatisticDefinitionResult() :
                PlayFabResultCommon(),
                Statistic()
            {}

            CreatePlayerStatisticDefinitionResult(const CreatePlayerStatisticDefinitionResult& src) :
                PlayFabResultCommon(),
                Statistic(src.Statistic)
            {}

            ~CreatePlayerStatisticDefinitionResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Statistic"], Statistic);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Statistic; ToJsonUtilO(Statistic, each_Statistic); output[L"Statistic"] = each_Statistic;
                return output;
            }
        };

        struct CreateTaskResult : public PlayFabResultCommon
        {
            std::string TaskId;

            CreateTaskResult() :
                PlayFabResultCommon(),
                TaskId()
            {}

            CreateTaskResult(const CreateTaskResult& src) :
                PlayFabResultCommon(),
                TaskId(src.TaskId)
            {}

            ~CreateTaskResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TaskId"], TaskId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TaskId; ToJsonUtilS(TaskId, each_TaskId); output[L"TaskId"] = each_TaskId;
                return output;
            }
        };

        struct DeleteContentRequest : public PlayFabRequestCommon
        {
            std::string Key;

            DeleteContentRequest() :
                PlayFabRequestCommon(),
                Key()
            {}

            DeleteContentRequest(const DeleteContentRequest& src) :
                PlayFabRequestCommon(),
                Key(src.Key)
            {}

            ~DeleteContentRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Key"], Key);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[L"Key"] = each_Key;
                return output;
            }
        };

        struct DeleteMasterPlayerAccountRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            DeleteMasterPlayerAccountRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            DeleteMasterPlayerAccountRequest(const DeleteMasterPlayerAccountRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~DeleteMasterPlayerAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct DeleteMasterPlayerAccountResult : public PlayFabResultCommon
        {
            std::string JobReceiptId;
            std::list<std::string> TitleIds;

            DeleteMasterPlayerAccountResult() :
                PlayFabResultCommon(),
                JobReceiptId(),
                TitleIds()
            {}

            DeleteMasterPlayerAccountResult(const DeleteMasterPlayerAccountResult& src) :
                PlayFabResultCommon(),
                JobReceiptId(src.JobReceiptId),
                TitleIds(src.TitleIds)
            {}

            ~DeleteMasterPlayerAccountResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"JobReceiptId"], JobReceiptId);
                FromJsonUtilS(input[L"TitleIds"], TitleIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_JobReceiptId; ToJsonUtilS(JobReceiptId, each_JobReceiptId); output[L"JobReceiptId"] = each_JobReceiptId;
                web::json::value each_TitleIds; ToJsonUtilS(TitleIds, each_TitleIds); output[L"TitleIds"] = each_TitleIds;
                return output;
            }
        };

        struct DeletePlayerRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            DeletePlayerRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            DeletePlayerRequest(const DeletePlayerRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~DeletePlayerRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct DeletePlayerResult : public PlayFabResultCommon
        {

            DeletePlayerResult() :
                PlayFabResultCommon()
            {}

            DeletePlayerResult(const DeletePlayerResult&) :
                PlayFabResultCommon()
            {}

            ~DeletePlayerResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeletePlayerSharedSecretRequest : public PlayFabRequestCommon
        {
            std::string SecretKey;

            DeletePlayerSharedSecretRequest() :
                PlayFabRequestCommon(),
                SecretKey()
            {}

            DeletePlayerSharedSecretRequest(const DeletePlayerSharedSecretRequest& src) :
                PlayFabRequestCommon(),
                SecretKey(src.SecretKey)
            {}

            ~DeletePlayerSharedSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"SecretKey"], SecretKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output[L"SecretKey"] = each_SecretKey;
                return output;
            }
        };

        struct DeletePlayerSharedSecretResult : public PlayFabResultCommon
        {

            DeletePlayerSharedSecretResult() :
                PlayFabResultCommon()
            {}

            DeletePlayerSharedSecretResult(const DeletePlayerSharedSecretResult&) :
                PlayFabResultCommon()
            {}

            ~DeletePlayerSharedSecretResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeleteStoreRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string StoreId;

            DeleteStoreRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                StoreId()
            {}

            DeleteStoreRequest(const DeleteStoreRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            ~DeleteStoreRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"StoreId"], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[L"StoreId"] = each_StoreId;
                return output;
            }
        };

        struct DeleteStoreResult : public PlayFabResultCommon
        {

            DeleteStoreResult() :
                PlayFabResultCommon()
            {}

            DeleteStoreResult(const DeleteStoreResult&) :
                PlayFabResultCommon()
            {}

            ~DeleteStoreResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeleteTaskRequest : public PlayFabRequestCommon
        {
            Boxed<NameIdentifier> Identifier;

            DeleteTaskRequest() :
                PlayFabRequestCommon(),
                Identifier()
            {}

            DeleteTaskRequest(const DeleteTaskRequest& src) :
                PlayFabRequestCommon(),
                Identifier(src.Identifier)
            {}

            ~DeleteTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Identifier"], Identifier);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output[L"Identifier"] = each_Identifier;
                return output;
            }
        };

        struct DeleteTitleRequest : public PlayFabRequestCommon
        {

            DeleteTitleRequest() :
                PlayFabRequestCommon()
            {}

            DeleteTitleRequest(const DeleteTitleRequest&) :
                PlayFabRequestCommon()
            {}

            ~DeleteTitleRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeleteTitleResult : public PlayFabResultCommon
        {

            DeleteTitleResult() :
                PlayFabResultCommon()
            {}

            DeleteTitleResult(const DeleteTitleResult&) :
                PlayFabResultCommon()
            {}

            ~DeleteTitleResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct EmptyResult : public PlayFabResultCommon
        {

            EmptyResult() :
                PlayFabResultCommon()
            {}

            EmptyResult(const EmptyResult&) :
                PlayFabResultCommon()
            {}

            ~EmptyResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

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

        struct ExportMasterPlayerDataRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            ExportMasterPlayerDataRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            ExportMasterPlayerDataRequest(const ExportMasterPlayerDataRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~ExportMasterPlayerDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct ExportMasterPlayerDataResult : public PlayFabResultCommon
        {
            std::string JobReceiptId;

            ExportMasterPlayerDataResult() :
                PlayFabResultCommon(),
                JobReceiptId()
            {}

            ExportMasterPlayerDataResult(const ExportMasterPlayerDataResult& src) :
                PlayFabResultCommon(),
                JobReceiptId(src.JobReceiptId)
            {}

            ~ExportMasterPlayerDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"JobReceiptId"], JobReceiptId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_JobReceiptId; ToJsonUtilS(JobReceiptId, each_JobReceiptId); output[L"JobReceiptId"] = each_JobReceiptId;
                return output;
            }
        };

        struct GameModeInfo : public PlayFabBaseModel
        {
            std::string Gamemode;
            Uint32 MaxPlayerCount;
            Uint32 MinPlayerCount;
            Boxed<bool> StartOpen;

            GameModeInfo() :
                PlayFabBaseModel(),
                Gamemode(),
                MaxPlayerCount(),
                MinPlayerCount(),
                StartOpen()
            {}

            GameModeInfo(const GameModeInfo& src) :
                PlayFabBaseModel(),
                Gamemode(src.Gamemode),
                MaxPlayerCount(src.MaxPlayerCount),
                MinPlayerCount(src.MinPlayerCount),
                StartOpen(src.StartOpen)
            {}

            ~GameModeInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Gamemode"], Gamemode);
                FromJsonUtilP(input[L"MaxPlayerCount"], MaxPlayerCount);
                FromJsonUtilP(input[L"MinPlayerCount"], MinPlayerCount);
                FromJsonUtilP(input[L"StartOpen"], StartOpen);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Gamemode; ToJsonUtilS(Gamemode, each_Gamemode); output[L"Gamemode"] = each_Gamemode;
                web::json::value each_MaxPlayerCount; ToJsonUtilP(MaxPlayerCount, each_MaxPlayerCount); output[L"MaxPlayerCount"] = each_MaxPlayerCount;
                web::json::value each_MinPlayerCount; ToJsonUtilP(MinPlayerCount, each_MinPlayerCount); output[L"MinPlayerCount"] = each_MinPlayerCount;
                web::json::value each_StartOpen; ToJsonUtilP(StartOpen, each_StartOpen); output[L"StartOpen"] = each_StartOpen;
                return output;
            }
        };

        struct GetActionsOnPlayersInSegmentTaskInstanceResult : public PlayFabResultCommon
        {
            Boxed<ActionsOnPlayersInSegmentTaskParameter> Parameter;
            Boxed<ActionsOnPlayersInSegmentTaskSummary> Summary;

            GetActionsOnPlayersInSegmentTaskInstanceResult() :
                PlayFabResultCommon(),
                Parameter(),
                Summary()
            {}

            GetActionsOnPlayersInSegmentTaskInstanceResult(const GetActionsOnPlayersInSegmentTaskInstanceResult& src) :
                PlayFabResultCommon(),
                Parameter(src.Parameter),
                Summary(src.Summary)
            {}

            ~GetActionsOnPlayersInSegmentTaskInstanceResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Parameter"], Parameter);
                FromJsonUtilO(input[L"Summary"], Summary);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output[L"Parameter"] = each_Parameter;
                web::json::value each_Summary; ToJsonUtilO(Summary, each_Summary); output[L"Summary"] = each_Summary;
                return output;
            }
        };

        struct GetAllSegmentsRequest : public PlayFabRequestCommon
        {

            GetAllSegmentsRequest() :
                PlayFabRequestCommon()
            {}

            GetAllSegmentsRequest(const GetAllSegmentsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetAllSegmentsRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetSegmentResult : public PlayFabResultCommon
        {
            std::string ABTestParent;
            std::string Id;
            std::string Name;

            GetSegmentResult() :
                PlayFabResultCommon(),
                ABTestParent(),
                Id(),
                Name()
            {}

            GetSegmentResult(const GetSegmentResult& src) :
                PlayFabResultCommon(),
                ABTestParent(src.ABTestParent),
                Id(src.Id),
                Name(src.Name)
            {}

            ~GetSegmentResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ABTestParent"], ABTestParent);
                FromJsonUtilS(input[L"Id"], Id);
                FromJsonUtilS(input[L"Name"], Name);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ABTestParent; ToJsonUtilS(ABTestParent, each_ABTestParent); output[L"ABTestParent"] = each_ABTestParent;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[L"Id"] = each_Id;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                return output;
            }
        };

        struct GetAllSegmentsResult : public PlayFabResultCommon
        {
            std::list<GetSegmentResult> Segments;

            GetAllSegmentsResult() :
                PlayFabResultCommon(),
                Segments()
            {}

            GetAllSegmentsResult(const GetAllSegmentsResult& src) :
                PlayFabResultCommon(),
                Segments(src.Segments)
            {}

            ~GetAllSegmentsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Segments"], Segments);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Segments; ToJsonUtilO(Segments, each_Segments); output[L"Segments"] = each_Segments;
                return output;
            }
        };

        struct GetCatalogItemsRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;

            GetCatalogItemsRequest() :
                PlayFabRequestCommon(),
                CatalogVersion()
            {}

            GetCatalogItemsRequest(const GetCatalogItemsRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion)
            {}

            ~GetCatalogItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                return output;
            }
        };

        struct GetCatalogItemsResult : public PlayFabResultCommon
        {
            std::list<CatalogItem> Catalog;

            GetCatalogItemsResult() :
                PlayFabResultCommon(),
                Catalog()
            {}

            GetCatalogItemsResult(const GetCatalogItemsResult& src) :
                PlayFabResultCommon(),
                Catalog(src.Catalog)
            {}

            ~GetCatalogItemsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Catalog"], Catalog);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Catalog; ToJsonUtilO(Catalog, each_Catalog); output[L"Catalog"] = each_Catalog;
                return output;
            }
        };

        struct GetCloudScriptRevisionRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> Revision;
            Boxed<Int32> Version;

            GetCloudScriptRevisionRequest() :
                PlayFabRequestCommon(),
                Revision(),
                Version()
            {}

            GetCloudScriptRevisionRequest(const GetCloudScriptRevisionRequest& src) :
                PlayFabRequestCommon(),
                Revision(src.Revision),
                Version(src.Version)
            {}

            ~GetCloudScriptRevisionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Revision"], Revision);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[L"Revision"] = each_Revision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetCloudScriptRevisionResult : public PlayFabResultCommon
        {
            time_t CreatedAt;
            std::list<CloudScriptFile> Files;
            bool IsPublished;
            Int32 Revision;
            Int32 Version;

            GetCloudScriptRevisionResult() :
                PlayFabResultCommon(),
                CreatedAt(),
                Files(),
                IsPublished(),
                Revision(),
                Version()
            {}

            GetCloudScriptRevisionResult(const GetCloudScriptRevisionResult& src) :
                PlayFabResultCommon(),
                CreatedAt(src.CreatedAt),
                Files(src.Files),
                IsPublished(src.IsPublished),
                Revision(src.Revision),
                Version(src.Version)
            {}

            ~GetCloudScriptRevisionResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"CreatedAt"], CreatedAt);
                FromJsonUtilO(input[L"Files"], Files);
                FromJsonUtilP(input[L"IsPublished"], IsPublished);
                FromJsonUtilP(input[L"Revision"], Revision);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreatedAt; ToJsonUtilT(CreatedAt, each_CreatedAt); output[L"CreatedAt"] = each_CreatedAt;
                web::json::value each_Files; ToJsonUtilO(Files, each_Files); output[L"Files"] = each_Files;
                web::json::value each_IsPublished; ToJsonUtilP(IsPublished, each_IsPublished); output[L"IsPublished"] = each_IsPublished;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[L"Revision"] = each_Revision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetCloudScriptTaskInstanceResult : public PlayFabResultCommon
        {
            Boxed<CloudScriptTaskParameter> Parameter;
            Boxed<CloudScriptTaskSummary> Summary;

            GetCloudScriptTaskInstanceResult() :
                PlayFabResultCommon(),
                Parameter(),
                Summary()
            {}

            GetCloudScriptTaskInstanceResult(const GetCloudScriptTaskInstanceResult& src) :
                PlayFabResultCommon(),
                Parameter(src.Parameter),
                Summary(src.Summary)
            {}

            ~GetCloudScriptTaskInstanceResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Parameter"], Parameter);
                FromJsonUtilO(input[L"Summary"], Summary);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output[L"Parameter"] = each_Parameter;
                web::json::value each_Summary; ToJsonUtilO(Summary, each_Summary); output[L"Summary"] = each_Summary;
                return output;
            }
        };

        struct GetCloudScriptVersionsRequest : public PlayFabRequestCommon
        {

            GetCloudScriptVersionsRequest() :
                PlayFabRequestCommon()
            {}

            GetCloudScriptVersionsRequest(const GetCloudScriptVersionsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetCloudScriptVersionsRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetCloudScriptVersionsResult : public PlayFabResultCommon
        {
            std::list<CloudScriptVersionStatus> Versions;

            GetCloudScriptVersionsResult() :
                PlayFabResultCommon(),
                Versions()
            {}

            GetCloudScriptVersionsResult(const GetCloudScriptVersionsResult& src) :
                PlayFabResultCommon(),
                Versions(src.Versions)
            {}

            ~GetCloudScriptVersionsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Versions"], Versions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Versions; ToJsonUtilO(Versions, each_Versions); output[L"Versions"] = each_Versions;
                return output;
            }
        };

        struct GetContentListRequest : public PlayFabRequestCommon
        {
            std::string Prefix;

            GetContentListRequest() :
                PlayFabRequestCommon(),
                Prefix()
            {}

            GetContentListRequest(const GetContentListRequest& src) :
                PlayFabRequestCommon(),
                Prefix(src.Prefix)
            {}

            ~GetContentListRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Prefix"], Prefix);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Prefix; ToJsonUtilS(Prefix, each_Prefix); output[L"Prefix"] = each_Prefix;
                return output;
            }
        };

        struct GetContentListResult : public PlayFabResultCommon
        {
            std::list<ContentInfo> Contents;
            Int32 ItemCount;
            Uint32 TotalSize;

            GetContentListResult() :
                PlayFabResultCommon(),
                Contents(),
                ItemCount(),
                TotalSize()
            {}

            GetContentListResult(const GetContentListResult& src) :
                PlayFabResultCommon(),
                Contents(src.Contents),
                ItemCount(src.ItemCount),
                TotalSize(src.TotalSize)
            {}

            ~GetContentListResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Contents"], Contents);
                FromJsonUtilP(input[L"ItemCount"], ItemCount);
                FromJsonUtilP(input[L"TotalSize"], TotalSize);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Contents; ToJsonUtilO(Contents, each_Contents); output[L"Contents"] = each_Contents;
                web::json::value each_ItemCount; ToJsonUtilP(ItemCount, each_ItemCount); output[L"ItemCount"] = each_ItemCount;
                web::json::value each_TotalSize; ToJsonUtilP(TotalSize, each_TotalSize); output[L"TotalSize"] = each_TotalSize;
                return output;
            }
        };

        struct GetContentUploadUrlRequest : public PlayFabRequestCommon
        {
            std::string ContentType;
            std::string Key;

            GetContentUploadUrlRequest() :
                PlayFabRequestCommon(),
                ContentType(),
                Key()
            {}

            GetContentUploadUrlRequest(const GetContentUploadUrlRequest& src) :
                PlayFabRequestCommon(),
                ContentType(src.ContentType),
                Key(src.Key)
            {}

            ~GetContentUploadUrlRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ContentType"], ContentType);
                FromJsonUtilS(input[L"Key"], Key);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ContentType; ToJsonUtilS(ContentType, each_ContentType); output[L"ContentType"] = each_ContentType;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[L"Key"] = each_Key;
                return output;
            }
        };

        struct GetContentUploadUrlResult : public PlayFabResultCommon
        {
            std::string URL;

            GetContentUploadUrlResult() :
                PlayFabResultCommon(),
                URL()
            {}

            GetContentUploadUrlResult(const GetContentUploadUrlResult& src) :
                PlayFabResultCommon(),
                URL(src.URL)
            {}

            ~GetContentUploadUrlResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"URL"], URL);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_URL; ToJsonUtilS(URL, each_URL); output[L"URL"] = each_URL;
                return output;
            }
        };

        struct GetDataReportRequest : public PlayFabRequestCommon
        {
            Int32 Day;
            Int32 Month;
            std::string ReportName;
            Int32 Year;

            GetDataReportRequest() :
                PlayFabRequestCommon(),
                Day(),
                Month(),
                ReportName(),
                Year()
            {}

            GetDataReportRequest(const GetDataReportRequest& src) :
                PlayFabRequestCommon(),
                Day(src.Day),
                Month(src.Month),
                ReportName(src.ReportName),
                Year(src.Year)
            {}

            ~GetDataReportRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Day"], Day);
                FromJsonUtilP(input[L"Month"], Month);
                FromJsonUtilS(input[L"ReportName"], ReportName);
                FromJsonUtilP(input[L"Year"], Year);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Day; ToJsonUtilP(Day, each_Day); output[L"Day"] = each_Day;
                web::json::value each_Month; ToJsonUtilP(Month, each_Month); output[L"Month"] = each_Month;
                web::json::value each_ReportName; ToJsonUtilS(ReportName, each_ReportName); output[L"ReportName"] = each_ReportName;
                web::json::value each_Year; ToJsonUtilP(Year, each_Year); output[L"Year"] = each_Year;
                return output;
            }
        };

        struct GetDataReportResult : public PlayFabResultCommon
        {
            std::string DownloadUrl;

            GetDataReportResult() :
                PlayFabResultCommon(),
                DownloadUrl()
            {}

            GetDataReportResult(const GetDataReportResult& src) :
                PlayFabResultCommon(),
                DownloadUrl(src.DownloadUrl)
            {}

            ~GetDataReportResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DownloadUrl"], DownloadUrl);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DownloadUrl; ToJsonUtilS(DownloadUrl, each_DownloadUrl); output[L"DownloadUrl"] = each_DownloadUrl;
                return output;
            }
        };

        struct GetMatchmakerGameInfoRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;

            GetMatchmakerGameInfoRequest() :
                PlayFabRequestCommon(),
                LobbyId()
            {}

            GetMatchmakerGameInfoRequest(const GetMatchmakerGameInfoRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId)
            {}

            ~GetMatchmakerGameInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"LobbyId"], LobbyId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[L"LobbyId"] = each_LobbyId;
                return output;
            }
        };

        struct GetMatchmakerGameInfoResult : public PlayFabResultCommon
        {
            std::string BuildVersion;
            Boxed<time_t> EndTime;
            std::string LobbyId;
            std::string Mode;
            std::list<std::string> Players;
            Boxed<Region> pfRegion;
            std::string ServerAddress;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            Uint32 ServerPort;
            std::string ServerPublicDNSName;
            time_t StartTime;
            std::string TitleId;

            GetMatchmakerGameInfoResult() :
                PlayFabResultCommon(),
                BuildVersion(),
                EndTime(),
                LobbyId(),
                Mode(),
                Players(),
                pfRegion(),
                ServerAddress(),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(),
                ServerPublicDNSName(),
                StartTime(),
                TitleId()
            {}

            GetMatchmakerGameInfoResult(const GetMatchmakerGameInfoResult& src) :
                PlayFabResultCommon(),
                BuildVersion(src.BuildVersion),
                EndTime(src.EndTime),
                LobbyId(src.LobbyId),
                Mode(src.Mode),
                Players(src.Players),
                pfRegion(src.pfRegion),
                ServerAddress(src.ServerAddress),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                StartTime(src.StartTime),
                TitleId(src.TitleId)
            {}

            ~GetMatchmakerGameInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildVersion"], BuildVersion);
                FromJsonUtilT(input[L"EndTime"], EndTime);
                FromJsonUtilS(input[L"LobbyId"], LobbyId);
                FromJsonUtilS(input[L"Mode"], Mode);
                FromJsonUtilS(input[L"Players"], Players);
                FromJsonUtilE(input[L"pfRegion"], pfRegion);
                FromJsonUtilS(input[L"ServerAddress"], ServerAddress);
                FromJsonUtilS(input[L"ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input[L"ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input[L"ServerPort"], ServerPort);
                FromJsonUtilS(input[L"ServerPublicDNSName"], ServerPublicDNSName);
                FromJsonUtilT(input[L"StartTime"], StartTime);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[L"BuildVersion"] = each_BuildVersion;
                web::json::value each_EndTime; ToJsonUtilT(EndTime, each_EndTime); output[L"EndTime"] = each_EndTime;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[L"LobbyId"] = each_LobbyId;
                web::json::value each_Mode; ToJsonUtilS(Mode, each_Mode); output[L"Mode"] = each_Mode;
                web::json::value each_Players; ToJsonUtilS(Players, each_Players); output[L"Players"] = each_Players;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[L"Region"] = each_pfRegion;
                web::json::value each_ServerAddress; ToJsonUtilS(ServerAddress, each_ServerAddress); output[L"ServerAddress"] = each_ServerAddress;
                web::json::value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output[L"ServerIPV4Address"] = each_ServerIPV4Address;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[L"ServerIPV6Address"] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[L"ServerPort"] = each_ServerPort;
                web::json::value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output[L"ServerPublicDNSName"] = each_ServerPublicDNSName;
                web::json::value each_StartTime; ToJsonUtilT(StartTime, each_StartTime); output[L"StartTime"] = each_StartTime;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct GetMatchmakerGameModesRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;

            GetMatchmakerGameModesRequest() :
                PlayFabRequestCommon(),
                BuildVersion()
            {}

            GetMatchmakerGameModesRequest(const GetMatchmakerGameModesRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion)
            {}

            ~GetMatchmakerGameModesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildVersion"], BuildVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[L"BuildVersion"] = each_BuildVersion;
                return output;
            }
        };

        struct GetMatchmakerGameModesResult : public PlayFabResultCommon
        {
            std::list<GameModeInfo> GameModes;

            GetMatchmakerGameModesResult() :
                PlayFabResultCommon(),
                GameModes()
            {}

            GetMatchmakerGameModesResult(const GetMatchmakerGameModesResult& src) :
                PlayFabResultCommon(),
                GameModes(src.GameModes)
            {}

            ~GetMatchmakerGameModesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"GameModes"], GameModes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameModes; ToJsonUtilO(GameModes, each_GameModes); output[L"GameModes"] = each_GameModes;
                return output;
            }
        };

        struct GetPlayedTitleListRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            GetPlayedTitleListRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            GetPlayedTitleListRequest(const GetPlayedTitleListRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayedTitleListRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayedTitleListResult : public PlayFabResultCommon
        {
            std::list<std::string> TitleIds;

            GetPlayedTitleListResult() :
                PlayFabResultCommon(),
                TitleIds()
            {}

            GetPlayedTitleListResult(const GetPlayedTitleListResult& src) :
                PlayFabResultCommon(),
                TitleIds(src.TitleIds)
            {}

            ~GetPlayedTitleListResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TitleIds"], TitleIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TitleIds; ToJsonUtilS(TitleIds, each_TitleIds); output[L"TitleIds"] = each_TitleIds;
                return output;
            }
        };

        struct GetPlayerIdFromAuthTokenRequest : public PlayFabRequestCommon
        {
            std::string Token;
            AuthTokenType TokenType;

            GetPlayerIdFromAuthTokenRequest() :
                PlayFabRequestCommon(),
                Token(),
                TokenType()
            {}

            GetPlayerIdFromAuthTokenRequest(const GetPlayerIdFromAuthTokenRequest& src) :
                PlayFabRequestCommon(),
                Token(src.Token),
                TokenType(src.TokenType)
            {}

            ~GetPlayerIdFromAuthTokenRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Token"], Token);
                FromJsonEnum(input[L"TokenType"], TokenType);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Token; ToJsonUtilS(Token, each_Token); output[L"Token"] = each_Token;
                web::json::value each_TokenType; ToJsonEnum(TokenType, each_TokenType); output[L"TokenType"] = each_TokenType;
                return output;
            }
        };

        struct GetPlayerIdFromAuthTokenResult : public PlayFabResultCommon
        {
            std::string PlayFabId;

            GetPlayerIdFromAuthTokenResult() :
                PlayFabResultCommon(),
                PlayFabId()
            {}

            GetPlayerIdFromAuthTokenResult(const GetPlayerIdFromAuthTokenResult& src) :
                PlayFabResultCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayerIdFromAuthTokenResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct PlayerProfileViewConstraints : public PlayFabBaseModel
        {
            bool ShowAvatarUrl;
            bool ShowBannedUntil;
            bool ShowCampaignAttributions;
            bool ShowContactEmailAddresses;
            bool ShowCreated;
            bool ShowDisplayName;
            bool ShowLastLogin;
            bool ShowLinkedAccounts;
            bool ShowLocations;
            bool ShowMemberships;
            bool ShowOrigination;
            bool ShowPushNotificationRegistrations;
            bool ShowStatistics;
            bool ShowTags;
            bool ShowTotalValueToDateInUsd;
            bool ShowValuesToDate;

            PlayerProfileViewConstraints() :
                PlayFabBaseModel(),
                ShowAvatarUrl(),
                ShowBannedUntil(),
                ShowCampaignAttributions(),
                ShowContactEmailAddresses(),
                ShowCreated(),
                ShowDisplayName(),
                ShowLastLogin(),
                ShowLinkedAccounts(),
                ShowLocations(),
                ShowMemberships(),
                ShowOrigination(),
                ShowPushNotificationRegistrations(),
                ShowStatistics(),
                ShowTags(),
                ShowTotalValueToDateInUsd(),
                ShowValuesToDate()
            {}

            PlayerProfileViewConstraints(const PlayerProfileViewConstraints& src) :
                PlayFabBaseModel(),
                ShowAvatarUrl(src.ShowAvatarUrl),
                ShowBannedUntil(src.ShowBannedUntil),
                ShowCampaignAttributions(src.ShowCampaignAttributions),
                ShowContactEmailAddresses(src.ShowContactEmailAddresses),
                ShowCreated(src.ShowCreated),
                ShowDisplayName(src.ShowDisplayName),
                ShowLastLogin(src.ShowLastLogin),
                ShowLinkedAccounts(src.ShowLinkedAccounts),
                ShowLocations(src.ShowLocations),
                ShowMemberships(src.ShowMemberships),
                ShowOrigination(src.ShowOrigination),
                ShowPushNotificationRegistrations(src.ShowPushNotificationRegistrations),
                ShowStatistics(src.ShowStatistics),
                ShowTags(src.ShowTags),
                ShowTotalValueToDateInUsd(src.ShowTotalValueToDateInUsd),
                ShowValuesToDate(src.ShowValuesToDate)
            {}

            ~PlayerProfileViewConstraints() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"ShowAvatarUrl"], ShowAvatarUrl);
                FromJsonUtilP(input[L"ShowBannedUntil"], ShowBannedUntil);
                FromJsonUtilP(input[L"ShowCampaignAttributions"], ShowCampaignAttributions);
                FromJsonUtilP(input[L"ShowContactEmailAddresses"], ShowContactEmailAddresses);
                FromJsonUtilP(input[L"ShowCreated"], ShowCreated);
                FromJsonUtilP(input[L"ShowDisplayName"], ShowDisplayName);
                FromJsonUtilP(input[L"ShowLastLogin"], ShowLastLogin);
                FromJsonUtilP(input[L"ShowLinkedAccounts"], ShowLinkedAccounts);
                FromJsonUtilP(input[L"ShowLocations"], ShowLocations);
                FromJsonUtilP(input[L"ShowMemberships"], ShowMemberships);
                FromJsonUtilP(input[L"ShowOrigination"], ShowOrigination);
                FromJsonUtilP(input[L"ShowPushNotificationRegistrations"], ShowPushNotificationRegistrations);
                FromJsonUtilP(input[L"ShowStatistics"], ShowStatistics);
                FromJsonUtilP(input[L"ShowTags"], ShowTags);
                FromJsonUtilP(input[L"ShowTotalValueToDateInUsd"], ShowTotalValueToDateInUsd);
                FromJsonUtilP(input[L"ShowValuesToDate"], ShowValuesToDate);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ShowAvatarUrl; ToJsonUtilP(ShowAvatarUrl, each_ShowAvatarUrl); output[L"ShowAvatarUrl"] = each_ShowAvatarUrl;
                web::json::value each_ShowBannedUntil; ToJsonUtilP(ShowBannedUntil, each_ShowBannedUntil); output[L"ShowBannedUntil"] = each_ShowBannedUntil;
                web::json::value each_ShowCampaignAttributions; ToJsonUtilP(ShowCampaignAttributions, each_ShowCampaignAttributions); output[L"ShowCampaignAttributions"] = each_ShowCampaignAttributions;
                web::json::value each_ShowContactEmailAddresses; ToJsonUtilP(ShowContactEmailAddresses, each_ShowContactEmailAddresses); output[L"ShowContactEmailAddresses"] = each_ShowContactEmailAddresses;
                web::json::value each_ShowCreated; ToJsonUtilP(ShowCreated, each_ShowCreated); output[L"ShowCreated"] = each_ShowCreated;
                web::json::value each_ShowDisplayName; ToJsonUtilP(ShowDisplayName, each_ShowDisplayName); output[L"ShowDisplayName"] = each_ShowDisplayName;
                web::json::value each_ShowLastLogin; ToJsonUtilP(ShowLastLogin, each_ShowLastLogin); output[L"ShowLastLogin"] = each_ShowLastLogin;
                web::json::value each_ShowLinkedAccounts; ToJsonUtilP(ShowLinkedAccounts, each_ShowLinkedAccounts); output[L"ShowLinkedAccounts"] = each_ShowLinkedAccounts;
                web::json::value each_ShowLocations; ToJsonUtilP(ShowLocations, each_ShowLocations); output[L"ShowLocations"] = each_ShowLocations;
                web::json::value each_ShowMemberships; ToJsonUtilP(ShowMemberships, each_ShowMemberships); output[L"ShowMemberships"] = each_ShowMemberships;
                web::json::value each_ShowOrigination; ToJsonUtilP(ShowOrigination, each_ShowOrigination); output[L"ShowOrigination"] = each_ShowOrigination;
                web::json::value each_ShowPushNotificationRegistrations; ToJsonUtilP(ShowPushNotificationRegistrations, each_ShowPushNotificationRegistrations); output[L"ShowPushNotificationRegistrations"] = each_ShowPushNotificationRegistrations;
                web::json::value each_ShowStatistics; ToJsonUtilP(ShowStatistics, each_ShowStatistics); output[L"ShowStatistics"] = each_ShowStatistics;
                web::json::value each_ShowTags; ToJsonUtilP(ShowTags, each_ShowTags); output[L"ShowTags"] = each_ShowTags;
                web::json::value each_ShowTotalValueToDateInUsd; ToJsonUtilP(ShowTotalValueToDateInUsd, each_ShowTotalValueToDateInUsd); output[L"ShowTotalValueToDateInUsd"] = each_ShowTotalValueToDateInUsd;
                web::json::value each_ShowValuesToDate; ToJsonUtilP(ShowValuesToDate, each_ShowValuesToDate); output[L"ShowValuesToDate"] = each_ShowValuesToDate;
                return output;
            }
        };

        struct GetPlayerProfileRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;

            GetPlayerProfileRequest() :
                PlayFabRequestCommon(),
                PlayFabId(),
                ProfileConstraints()
            {}

            GetPlayerProfileRequest(const GetPlayerProfileRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints)
            {}

            ~GetPlayerProfileRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilO(input[L"ProfileConstraints"], ProfileConstraints);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[L"ProfileConstraints"] = each_ProfileConstraints;
                return output;
            }
        };

        struct LinkedPlatformAccountModel : public PlayFabBaseModel
        {
            std::string Email;
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;

            LinkedPlatformAccountModel() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            LinkedPlatformAccountModel(const LinkedPlatformAccountModel& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            ~LinkedPlatformAccountModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Email"], Email);
                FromJsonUtilE(input[L"Platform"], Platform);
                FromJsonUtilS(input[L"PlatformUserId"], PlatformUserId);
                FromJsonUtilS(input[L"Username"], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                web::json::value each_Platform; ToJsonUtilE(Platform, each_Platform); output[L"Platform"] = each_Platform;
                web::json::value each_PlatformUserId; ToJsonUtilS(PlatformUserId, each_PlatformUserId); output[L"PlatformUserId"] = each_PlatformUserId;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                return output;
            }
        };

        struct LocationModel : public PlayFabBaseModel
        {
            std::string City;
            Boxed<ContinentCode> pfContinentCode;
            Boxed<CountryCode> pfCountryCode;
            Boxed<double> Latitude;
            Boxed<double> Longitude;

            LocationModel() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            LocationModel(const LocationModel& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            ~LocationModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"City"], City);
                FromJsonUtilE(input[L"pfContinentCode"], pfContinentCode);
                FromJsonUtilE(input[L"pfCountryCode"], pfCountryCode);
                FromJsonUtilP(input[L"Latitude"], Latitude);
                FromJsonUtilP(input[L"Longitude"], Longitude);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_City; ToJsonUtilS(City, each_City); output[L"City"] = each_City;
                web::json::value each_pfContinentCode; ToJsonUtilE(pfContinentCode, each_pfContinentCode); output[L"ContinentCode"] = each_pfContinentCode;
                web::json::value each_pfCountryCode; ToJsonUtilE(pfCountryCode, each_pfCountryCode); output[L"CountryCode"] = each_pfCountryCode;
                web::json::value each_Latitude; ToJsonUtilP(Latitude, each_Latitude); output[L"Latitude"] = each_Latitude;
                web::json::value each_Longitude; ToJsonUtilP(Longitude, each_Longitude); output[L"Longitude"] = each_Longitude;
                return output;
            }
        };

        struct SubscriptionModel : public PlayFabBaseModel
        {
            time_t Expiration;
            time_t InitialSubscriptionTime;
            bool IsActive;
            Boxed<SubscriptionProviderStatus> Status;
            std::string SubscriptionId;
            std::string SubscriptionItemId;
            std::string SubscriptionProvider;

            SubscriptionModel() :
                PlayFabBaseModel(),
                Expiration(),
                InitialSubscriptionTime(),
                IsActive(),
                Status(),
                SubscriptionId(),
                SubscriptionItemId(),
                SubscriptionProvider()
            {}

            SubscriptionModel(const SubscriptionModel& src) :
                PlayFabBaseModel(),
                Expiration(src.Expiration),
                InitialSubscriptionTime(src.InitialSubscriptionTime),
                IsActive(src.IsActive),
                Status(src.Status),
                SubscriptionId(src.SubscriptionId),
                SubscriptionItemId(src.SubscriptionItemId),
                SubscriptionProvider(src.SubscriptionProvider)
            {}

            ~SubscriptionModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"Expiration"], Expiration);
                FromJsonUtilT(input[L"InitialSubscriptionTime"], InitialSubscriptionTime);
                FromJsonUtilP(input[L"IsActive"], IsActive);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilS(input[L"SubscriptionId"], SubscriptionId);
                FromJsonUtilS(input[L"SubscriptionItemId"], SubscriptionItemId);
                FromJsonUtilS(input[L"SubscriptionProvider"], SubscriptionProvider);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output[L"Expiration"] = each_Expiration;
                web::json::value each_InitialSubscriptionTime; ToJsonUtilT(InitialSubscriptionTime, each_InitialSubscriptionTime); output[L"InitialSubscriptionTime"] = each_InitialSubscriptionTime;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[L"IsActive"] = each_IsActive;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_SubscriptionId; ToJsonUtilS(SubscriptionId, each_SubscriptionId); output[L"SubscriptionId"] = each_SubscriptionId;
                web::json::value each_SubscriptionItemId; ToJsonUtilS(SubscriptionItemId, each_SubscriptionItemId); output[L"SubscriptionItemId"] = each_SubscriptionItemId;
                web::json::value each_SubscriptionProvider; ToJsonUtilS(SubscriptionProvider, each_SubscriptionProvider); output[L"SubscriptionProvider"] = each_SubscriptionProvider;
                return output;
            }
        };

        struct MembershipModel : public PlayFabBaseModel
        {
            bool IsActive;
            time_t MembershipExpiration;
            std::string MembershipId;
            Boxed<time_t> OverrideExpiration;
            std::list<SubscriptionModel> Subscriptions;

            MembershipModel() :
                PlayFabBaseModel(),
                IsActive(),
                MembershipExpiration(),
                MembershipId(),
                OverrideExpiration(),
                Subscriptions()
            {}

            MembershipModel(const MembershipModel& src) :
                PlayFabBaseModel(),
                IsActive(src.IsActive),
                MembershipExpiration(src.MembershipExpiration),
                MembershipId(src.MembershipId),
                OverrideExpiration(src.OverrideExpiration),
                Subscriptions(src.Subscriptions)
            {}

            ~MembershipModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"IsActive"], IsActive);
                FromJsonUtilT(input[L"MembershipExpiration"], MembershipExpiration);
                FromJsonUtilS(input[L"MembershipId"], MembershipId);
                FromJsonUtilT(input[L"OverrideExpiration"], OverrideExpiration);
                FromJsonUtilO(input[L"Subscriptions"], Subscriptions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[L"IsActive"] = each_IsActive;
                web::json::value each_MembershipExpiration; ToJsonUtilT(MembershipExpiration, each_MembershipExpiration); output[L"MembershipExpiration"] = each_MembershipExpiration;
                web::json::value each_MembershipId; ToJsonUtilS(MembershipId, each_MembershipId); output[L"MembershipId"] = each_MembershipId;
                web::json::value each_OverrideExpiration; ToJsonUtilT(OverrideExpiration, each_OverrideExpiration); output[L"OverrideExpiration"] = each_OverrideExpiration;
                web::json::value each_Subscriptions; ToJsonUtilO(Subscriptions, each_Subscriptions); output[L"Subscriptions"] = each_Subscriptions;
                return output;
            }
        };

        struct PushNotificationRegistrationModel : public PlayFabBaseModel
        {
            std::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistrationModel() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistrationModel(const PushNotificationRegistrationModel& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            ~PushNotificationRegistrationModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"NotificationEndpointARN"], NotificationEndpointARN);
                FromJsonUtilE(input[L"Platform"], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_NotificationEndpointARN; ToJsonUtilS(NotificationEndpointARN, each_NotificationEndpointARN); output[L"NotificationEndpointARN"] = each_NotificationEndpointARN;
                web::json::value each_Platform; ToJsonUtilE(Platform, each_Platform); output[L"Platform"] = each_Platform;
                return output;
            }
        };

        struct StatisticModel : public PlayFabBaseModel
        {
            std::string Name;
            Int32 Value;
            Int32 Version;

            StatisticModel() :
                PlayFabBaseModel(),
                Name(),
                Value(),
                Version()
            {}

            StatisticModel(const StatisticModel& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Value(src.Value),
                Version(src.Version)
            {}

            ~StatisticModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilP(input[L"Value"], Value);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_Value; ToJsonUtilP(Value, each_Value); output[L"Value"] = each_Value;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct TagModel : public PlayFabBaseModel
        {
            std::string TagValue;

            TagModel() :
                PlayFabBaseModel(),
                TagValue()
            {}

            TagModel(const TagModel& src) :
                PlayFabBaseModel(),
                TagValue(src.TagValue)
            {}

            ~TagModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TagValue"], TagValue);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TagValue; ToJsonUtilS(TagValue, each_TagValue); output[L"TagValue"] = each_TagValue;
                return output;
            }
        };

        struct ValueToDateModel : public PlayFabBaseModel
        {
            std::string Currency;
            Uint32 TotalValue;
            std::string TotalValueAsDecimal;

            ValueToDateModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(),
                TotalValueAsDecimal()
            {}

            ValueToDateModel(const ValueToDateModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue),
                TotalValueAsDecimal(src.TotalValueAsDecimal)
            {}

            ~ValueToDateModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Currency"], Currency);
                FromJsonUtilP(input[L"TotalValue"], TotalValue);
                FromJsonUtilS(input[L"TotalValueAsDecimal"], TotalValueAsDecimal);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Currency; ToJsonUtilS(Currency, each_Currency); output[L"Currency"] = each_Currency;
                web::json::value each_TotalValue; ToJsonUtilP(TotalValue, each_TotalValue); output[L"TotalValue"] = each_TotalValue;
                web::json::value each_TotalValueAsDecimal; ToJsonUtilS(TotalValueAsDecimal, each_TotalValueAsDecimal); output[L"TotalValueAsDecimal"] = each_TotalValueAsDecimal;
                return output;
            }
        };

        struct PlayerProfileModel : public PlayFabBaseModel
        {
            std::list<AdCampaignAttributionModel> AdCampaignAttributions;
            std::string AvatarUrl;
            Boxed<time_t> BannedUntil;
            std::list<ContactEmailInfoModel> ContactEmailAddresses;
            Boxed<time_t> Created;
            std::string DisplayName;
            Boxed<time_t> LastLogin;
            std::list<LinkedPlatformAccountModel> LinkedAccounts;
            std::list<LocationModel> Locations;
            std::list<MembershipModel> Memberships;
            Boxed<LoginIdentityProvider> Origination;
            std::string PlayerId;
            std::string PublisherId;
            std::list<PushNotificationRegistrationModel> PushNotificationRegistrations;
            std::list<StatisticModel> Statistics;
            std::list<TagModel> Tags;
            std::string TitleId;
            Boxed<Uint32> TotalValueToDateInUSD;
            std::list<ValueToDateModel> ValuesToDate;

            PlayerProfileModel() :
                PlayFabBaseModel(),
                AdCampaignAttributions(),
                AvatarUrl(),
                BannedUntil(),
                ContactEmailAddresses(),
                Created(),
                DisplayName(),
                LastLogin(),
                LinkedAccounts(),
                Locations(),
                Memberships(),
                Origination(),
                PlayerId(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate()
            {}

            PlayerProfileModel(const PlayerProfileModel& src) :
                PlayFabBaseModel(),
                AdCampaignAttributions(src.AdCampaignAttributions),
                AvatarUrl(src.AvatarUrl),
                BannedUntil(src.BannedUntil),
                ContactEmailAddresses(src.ContactEmailAddresses),
                Created(src.Created),
                DisplayName(src.DisplayName),
                LastLogin(src.LastLogin),
                LinkedAccounts(src.LinkedAccounts),
                Locations(src.Locations),
                Memberships(src.Memberships),
                Origination(src.Origination),
                PlayerId(src.PlayerId),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate)
            {}

            ~PlayerProfileModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"AdCampaignAttributions"], AdCampaignAttributions);
                FromJsonUtilS(input[L"AvatarUrl"], AvatarUrl);
                FromJsonUtilT(input[L"BannedUntil"], BannedUntil);
                FromJsonUtilO(input[L"ContactEmailAddresses"], ContactEmailAddresses);
                FromJsonUtilT(input[L"Created"], Created);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilT(input[L"LastLogin"], LastLogin);
                FromJsonUtilO(input[L"LinkedAccounts"], LinkedAccounts);
                FromJsonUtilO(input[L"Locations"], Locations);
                FromJsonUtilO(input[L"Memberships"], Memberships);
                FromJsonUtilE(input[L"Origination"], Origination);
                FromJsonUtilS(input[L"PlayerId"], PlayerId);
                FromJsonUtilS(input[L"PublisherId"], PublisherId);
                FromJsonUtilO(input[L"PushNotificationRegistrations"], PushNotificationRegistrations);
                FromJsonUtilO(input[L"Statistics"], Statistics);
                FromJsonUtilO(input[L"Tags"], Tags);
                FromJsonUtilS(input[L"TitleId"], TitleId);
                FromJsonUtilP(input[L"TotalValueToDateInUSD"], TotalValueToDateInUSD);
                FromJsonUtilO(input[L"ValuesToDate"], ValuesToDate);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdCampaignAttributions; ToJsonUtilO(AdCampaignAttributions, each_AdCampaignAttributions); output[L"AdCampaignAttributions"] = each_AdCampaignAttributions;
                web::json::value each_AvatarUrl; ToJsonUtilS(AvatarUrl, each_AvatarUrl); output[L"AvatarUrl"] = each_AvatarUrl;
                web::json::value each_BannedUntil; ToJsonUtilT(BannedUntil, each_BannedUntil); output[L"BannedUntil"] = each_BannedUntil;
                web::json::value each_ContactEmailAddresses; ToJsonUtilO(ContactEmailAddresses, each_ContactEmailAddresses); output[L"ContactEmailAddresses"] = each_ContactEmailAddresses;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[L"Created"] = each_Created;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_LastLogin; ToJsonUtilT(LastLogin, each_LastLogin); output[L"LastLogin"] = each_LastLogin;
                web::json::value each_LinkedAccounts; ToJsonUtilO(LinkedAccounts, each_LinkedAccounts); output[L"LinkedAccounts"] = each_LinkedAccounts;
                web::json::value each_Locations; ToJsonUtilO(Locations, each_Locations); output[L"Locations"] = each_Locations;
                web::json::value each_Memberships; ToJsonUtilO(Memberships, each_Memberships); output[L"Memberships"] = each_Memberships;
                web::json::value each_Origination; ToJsonUtilE(Origination, each_Origination); output[L"Origination"] = each_Origination;
                web::json::value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output[L"PlayerId"] = each_PlayerId;
                web::json::value each_PublisherId; ToJsonUtilS(PublisherId, each_PublisherId); output[L"PublisherId"] = each_PublisherId;
                web::json::value each_PushNotificationRegistrations; ToJsonUtilO(PushNotificationRegistrations, each_PushNotificationRegistrations); output[L"PushNotificationRegistrations"] = each_PushNotificationRegistrations;
                web::json::value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output[L"Statistics"] = each_Statistics;
                web::json::value each_Tags; ToJsonUtilO(Tags, each_Tags); output[L"Tags"] = each_Tags;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                web::json::value each_TotalValueToDateInUSD; ToJsonUtilP(TotalValueToDateInUSD, each_TotalValueToDateInUSD); output[L"TotalValueToDateInUSD"] = each_TotalValueToDateInUSD;
                web::json::value each_ValuesToDate; ToJsonUtilO(ValuesToDate, each_ValuesToDate); output[L"ValuesToDate"] = each_ValuesToDate;
                return output;
            }
        };

        struct GetPlayerProfileResult : public PlayFabResultCommon
        {
            Boxed<PlayerProfileModel> PlayerProfile;

            GetPlayerProfileResult() :
                PlayFabResultCommon(),
                PlayerProfile()
            {}

            GetPlayerProfileResult(const GetPlayerProfileResult& src) :
                PlayFabResultCommon(),
                PlayerProfile(src.PlayerProfile)
            {}

            ~GetPlayerProfileResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"PlayerProfile"], PlayerProfile);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayerProfile; ToJsonUtilO(PlayerProfile, each_PlayerProfile); output[L"PlayerProfile"] = each_PlayerProfile;
                return output;
            }
        };

        struct GetPlayerSegmentsResult : public PlayFabResultCommon
        {
            std::list<GetSegmentResult> Segments;

            GetPlayerSegmentsResult() :
                PlayFabResultCommon(),
                Segments()
            {}

            GetPlayerSegmentsResult(const GetPlayerSegmentsResult& src) :
                PlayFabResultCommon(),
                Segments(src.Segments)
            {}

            ~GetPlayerSegmentsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Segments"], Segments);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Segments; ToJsonUtilO(Segments, each_Segments); output[L"Segments"] = each_Segments;
                return output;
            }
        };

        struct GetPlayerSharedSecretsRequest : public PlayFabRequestCommon
        {

            GetPlayerSharedSecretsRequest() :
                PlayFabRequestCommon()
            {}

            GetPlayerSharedSecretsRequest(const GetPlayerSharedSecretsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetPlayerSharedSecretsRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SharedSecret : public PlayFabBaseModel
        {
            bool Disabled;
            std::string FriendlyName;
            std::string SecretKey;

            SharedSecret() :
                PlayFabBaseModel(),
                Disabled(),
                FriendlyName(),
                SecretKey()
            {}

            SharedSecret(const SharedSecret& src) :
                PlayFabBaseModel(),
                Disabled(src.Disabled),
                FriendlyName(src.FriendlyName),
                SecretKey(src.SecretKey)
            {}

            ~SharedSecret() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Disabled"], Disabled);
                FromJsonUtilS(input[L"FriendlyName"], FriendlyName);
                FromJsonUtilS(input[L"SecretKey"], SecretKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Disabled; ToJsonUtilP(Disabled, each_Disabled); output[L"Disabled"] = each_Disabled;
                web::json::value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output[L"FriendlyName"] = each_FriendlyName;
                web::json::value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output[L"SecretKey"] = each_SecretKey;
                return output;
            }
        };

        struct GetPlayerSharedSecretsResult : public PlayFabResultCommon
        {
            std::list<SharedSecret> SharedSecrets;

            GetPlayerSharedSecretsResult() :
                PlayFabResultCommon(),
                SharedSecrets()
            {}

            GetPlayerSharedSecretsResult(const GetPlayerSharedSecretsResult& src) :
                PlayFabResultCommon(),
                SharedSecrets(src.SharedSecrets)
            {}

            ~GetPlayerSharedSecretsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"SharedSecrets"], SharedSecrets);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SharedSecrets; ToJsonUtilO(SharedSecrets, each_SharedSecrets); output[L"SharedSecrets"] = each_SharedSecrets;
                return output;
            }
        };

        struct GetPlayersInSegmentRequest : public PlayFabRequestCommon
        {
            std::string ContinuationToken;
            Boxed<Uint32> MaxBatchSize;
            Boxed<Uint32> SecondsToLive;
            std::string SegmentId;

            GetPlayersInSegmentRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                MaxBatchSize(),
                SecondsToLive(),
                SegmentId()
            {}

            GetPlayersInSegmentRequest(const GetPlayersInSegmentRequest& src) :
                PlayFabRequestCommon(),
                ContinuationToken(src.ContinuationToken),
                MaxBatchSize(src.MaxBatchSize),
                SecondsToLive(src.SecondsToLive),
                SegmentId(src.SegmentId)
            {}

            ~GetPlayersInSegmentRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input[L"MaxBatchSize"], MaxBatchSize);
                FromJsonUtilP(input[L"SecondsToLive"], SecondsToLive);
                FromJsonUtilS(input[L"SegmentId"], SegmentId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output[L"ContinuationToken"] = each_ContinuationToken;
                web::json::value each_MaxBatchSize; ToJsonUtilP(MaxBatchSize, each_MaxBatchSize); output[L"MaxBatchSize"] = each_MaxBatchSize;
                web::json::value each_SecondsToLive; ToJsonUtilP(SecondsToLive, each_SecondsToLive); output[L"SecondsToLive"] = each_SecondsToLive;
                web::json::value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output[L"SegmentId"] = each_SegmentId;
                return output;
            }
        };

        struct PlayerLinkedAccount : public PlayFabBaseModel
        {
            std::string Email;
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;

            PlayerLinkedAccount() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            PlayerLinkedAccount(const PlayerLinkedAccount& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            ~PlayerLinkedAccount() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Email"], Email);
                FromJsonUtilE(input[L"Platform"], Platform);
                FromJsonUtilS(input[L"PlatformUserId"], PlatformUserId);
                FromJsonUtilS(input[L"Username"], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                web::json::value each_Platform; ToJsonUtilE(Platform, each_Platform); output[L"Platform"] = each_Platform;
                web::json::value each_PlatformUserId; ToJsonUtilS(PlatformUserId, each_PlatformUserId); output[L"PlatformUserId"] = each_PlatformUserId;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                return output;
            }
        };

        struct PlayerLocation : public PlayFabBaseModel
        {
            std::string City;
            ContinentCode pfContinentCode;
            CountryCode pfCountryCode;
            Boxed<double> Latitude;
            Boxed<double> Longitude;

            PlayerLocation() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            PlayerLocation(const PlayerLocation& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            ~PlayerLocation() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"City"], City);
                FromJsonEnum(input[L"pfContinentCode"], pfContinentCode);
                FromJsonEnum(input[L"pfCountryCode"], pfCountryCode);
                FromJsonUtilP(input[L"Latitude"], Latitude);
                FromJsonUtilP(input[L"Longitude"], Longitude);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_City; ToJsonUtilS(City, each_City); output[L"City"] = each_City;
                web::json::value each_pfContinentCode; ToJsonEnum(pfContinentCode, each_pfContinentCode); output[L"ContinentCode"] = each_pfContinentCode;
                web::json::value each_pfCountryCode; ToJsonEnum(pfCountryCode, each_pfCountryCode); output[L"CountryCode"] = each_pfCountryCode;
                web::json::value each_Latitude; ToJsonUtilP(Latitude, each_Latitude); output[L"Latitude"] = each_Latitude;
                web::json::value each_Longitude; ToJsonUtilP(Longitude, each_Longitude); output[L"Longitude"] = each_Longitude;
                return output;
            }
        };

        struct PlayerStatistic : public PlayFabBaseModel
        {
            std::string Id;
            std::string Name;
            Int32 StatisticValue;
            Int32 StatisticVersion;

            PlayerStatistic() :
                PlayFabBaseModel(),
                Id(),
                Name(),
                StatisticValue(),
                StatisticVersion()
            {}

            PlayerStatistic(const PlayerStatistic& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name),
                StatisticValue(src.StatisticValue),
                StatisticVersion(src.StatisticVersion)
            {}

            ~PlayerStatistic() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Id"], Id);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilP(input[L"StatisticValue"], StatisticValue);
                FromJsonUtilP(input[L"StatisticVersion"], StatisticVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[L"Id"] = each_Id;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_StatisticValue; ToJsonUtilP(StatisticValue, each_StatisticValue); output[L"StatisticValue"] = each_StatisticValue;
                web::json::value each_StatisticVersion; ToJsonUtilP(StatisticVersion, each_StatisticVersion); output[L"StatisticVersion"] = each_StatisticVersion;
                return output;
            }
        };

        struct PushNotificationRegistration : public PlayFabBaseModel
        {
            std::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistration() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistration(const PushNotificationRegistration& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            ~PushNotificationRegistration() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"NotificationEndpointARN"], NotificationEndpointARN);
                FromJsonUtilE(input[L"Platform"], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_NotificationEndpointARN; ToJsonUtilS(NotificationEndpointARN, each_NotificationEndpointARN); output[L"NotificationEndpointARN"] = each_NotificationEndpointARN;
                web::json::value each_Platform; ToJsonUtilE(Platform, each_Platform); output[L"Platform"] = each_Platform;
                return output;
            }
        };

        struct PlayerProfile : public PlayFabBaseModel
        {
            std::list<AdCampaignAttribution> AdCampaignAttributions;
            std::string AvatarUrl;
            Boxed<time_t> BannedUntil;
            std::list<ContactEmailInfo> ContactEmailAddresses;
            Boxed<time_t> Created;
            std::string DisplayName;
            Boxed<time_t> LastLogin;
            std::list<PlayerLinkedAccount> LinkedAccounts;
            std::map<std::string, PlayerLocation> Locations;
            Boxed<LoginIdentityProvider> Origination;
            std::string PlayerId;
            std::list<PlayerStatistic> PlayerStatistics;
            std::string PublisherId;
            std::list<PushNotificationRegistration> PushNotificationRegistrations;
            std::map<std::string, Int32> Statistics;
            std::list<std::string> Tags;
            std::string TitleId;
            Boxed<Uint32> TotalValueToDateInUSD;
            std::map<std::string, Uint32> ValuesToDate;
            std::map<std::string, Int32> VirtualCurrencyBalances;

            PlayerProfile() :
                PlayFabBaseModel(),
                AdCampaignAttributions(),
                AvatarUrl(),
                BannedUntil(),
                ContactEmailAddresses(),
                Created(),
                DisplayName(),
                LastLogin(),
                LinkedAccounts(),
                Locations(),
                Origination(),
                PlayerId(),
                PlayerStatistics(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                VirtualCurrencyBalances()
            {}

            PlayerProfile(const PlayerProfile& src) :
                PlayFabBaseModel(),
                AdCampaignAttributions(src.AdCampaignAttributions),
                AvatarUrl(src.AvatarUrl),
                BannedUntil(src.BannedUntil),
                ContactEmailAddresses(src.ContactEmailAddresses),
                Created(src.Created),
                DisplayName(src.DisplayName),
                LastLogin(src.LastLogin),
                LinkedAccounts(src.LinkedAccounts),
                Locations(src.Locations),
                Origination(src.Origination),
                PlayerId(src.PlayerId),
                PlayerStatistics(src.PlayerStatistics),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            ~PlayerProfile() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"AdCampaignAttributions"], AdCampaignAttributions);
                FromJsonUtilS(input[L"AvatarUrl"], AvatarUrl);
                FromJsonUtilT(input[L"BannedUntil"], BannedUntil);
                FromJsonUtilO(input[L"ContactEmailAddresses"], ContactEmailAddresses);
                FromJsonUtilT(input[L"Created"], Created);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilT(input[L"LastLogin"], LastLogin);
                FromJsonUtilO(input[L"LinkedAccounts"], LinkedAccounts);
                FromJsonUtilO(input[L"Locations"], Locations);
                FromJsonUtilE(input[L"Origination"], Origination);
                FromJsonUtilS(input[L"PlayerId"], PlayerId);
                FromJsonUtilO(input[L"PlayerStatistics"], PlayerStatistics);
                FromJsonUtilS(input[L"PublisherId"], PublisherId);
                FromJsonUtilO(input[L"PushNotificationRegistrations"], PushNotificationRegistrations);
                FromJsonUtilP(input[L"Statistics"], Statistics);
                FromJsonUtilS(input[L"Tags"], Tags);
                FromJsonUtilS(input[L"TitleId"], TitleId);
                FromJsonUtilP(input[L"TotalValueToDateInUSD"], TotalValueToDateInUSD);
                FromJsonUtilP(input[L"ValuesToDate"], ValuesToDate);
                FromJsonUtilP(input[L"VirtualCurrencyBalances"], VirtualCurrencyBalances);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdCampaignAttributions; ToJsonUtilO(AdCampaignAttributions, each_AdCampaignAttributions); output[L"AdCampaignAttributions"] = each_AdCampaignAttributions;
                web::json::value each_AvatarUrl; ToJsonUtilS(AvatarUrl, each_AvatarUrl); output[L"AvatarUrl"] = each_AvatarUrl;
                web::json::value each_BannedUntil; ToJsonUtilT(BannedUntil, each_BannedUntil); output[L"BannedUntil"] = each_BannedUntil;
                web::json::value each_ContactEmailAddresses; ToJsonUtilO(ContactEmailAddresses, each_ContactEmailAddresses); output[L"ContactEmailAddresses"] = each_ContactEmailAddresses;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[L"Created"] = each_Created;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_LastLogin; ToJsonUtilT(LastLogin, each_LastLogin); output[L"LastLogin"] = each_LastLogin;
                web::json::value each_LinkedAccounts; ToJsonUtilO(LinkedAccounts, each_LinkedAccounts); output[L"LinkedAccounts"] = each_LinkedAccounts;
                web::json::value each_Locations; ToJsonUtilO(Locations, each_Locations); output[L"Locations"] = each_Locations;
                web::json::value each_Origination; ToJsonUtilE(Origination, each_Origination); output[L"Origination"] = each_Origination;
                web::json::value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output[L"PlayerId"] = each_PlayerId;
                web::json::value each_PlayerStatistics; ToJsonUtilO(PlayerStatistics, each_PlayerStatistics); output[L"PlayerStatistics"] = each_PlayerStatistics;
                web::json::value each_PublisherId; ToJsonUtilS(PublisherId, each_PublisherId); output[L"PublisherId"] = each_PublisherId;
                web::json::value each_PushNotificationRegistrations; ToJsonUtilO(PushNotificationRegistrations, each_PushNotificationRegistrations); output[L"PushNotificationRegistrations"] = each_PushNotificationRegistrations;
                web::json::value each_Statistics; ToJsonUtilP(Statistics, each_Statistics); output[L"Statistics"] = each_Statistics;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[L"Tags"] = each_Tags;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                web::json::value each_TotalValueToDateInUSD; ToJsonUtilP(TotalValueToDateInUSD, each_TotalValueToDateInUSD); output[L"TotalValueToDateInUSD"] = each_TotalValueToDateInUSD;
                web::json::value each_ValuesToDate; ToJsonUtilP(ValuesToDate, each_ValuesToDate); output[L"ValuesToDate"] = each_ValuesToDate;
                web::json::value each_VirtualCurrencyBalances; ToJsonUtilP(VirtualCurrencyBalances, each_VirtualCurrencyBalances); output[L"VirtualCurrencyBalances"] = each_VirtualCurrencyBalances;
                return output;
            }
        };

        struct GetPlayersInSegmentResult : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            std::list<PlayerProfile> PlayerProfiles;
            Int32 ProfilesInSegment;

            GetPlayersInSegmentResult() :
                PlayFabResultCommon(),
                ContinuationToken(),
                PlayerProfiles(),
                ProfilesInSegment()
            {}

            GetPlayersInSegmentResult(const GetPlayersInSegmentResult& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                PlayerProfiles(src.PlayerProfiles),
                ProfilesInSegment(src.ProfilesInSegment)
            {}

            ~GetPlayersInSegmentResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ContinuationToken"], ContinuationToken);
                FromJsonUtilO(input[L"PlayerProfiles"], PlayerProfiles);
                FromJsonUtilP(input[L"ProfilesInSegment"], ProfilesInSegment);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output[L"ContinuationToken"] = each_ContinuationToken;
                web::json::value each_PlayerProfiles; ToJsonUtilO(PlayerProfiles, each_PlayerProfiles); output[L"PlayerProfiles"] = each_PlayerProfiles;
                web::json::value each_ProfilesInSegment; ToJsonUtilP(ProfilesInSegment, each_ProfilesInSegment); output[L"ProfilesInSegment"] = each_ProfilesInSegment;
                return output;
            }
        };

        struct GetPlayersSegmentsRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            GetPlayersSegmentsRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            GetPlayersSegmentsRequest(const GetPlayersSegmentsRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayersSegmentsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayerStatisticDefinitionsRequest : public PlayFabRequestCommon
        {

            GetPlayerStatisticDefinitionsRequest() :
                PlayFabRequestCommon()
            {}

            GetPlayerStatisticDefinitionsRequest(const GetPlayerStatisticDefinitionsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetPlayerStatisticDefinitionsRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetPlayerStatisticDefinitionsResult : public PlayFabResultCommon
        {
            std::list<PlayerStatisticDefinition> Statistics;

            GetPlayerStatisticDefinitionsResult() :
                PlayFabResultCommon(),
                Statistics()
            {}

            GetPlayerStatisticDefinitionsResult(const GetPlayerStatisticDefinitionsResult& src) :
                PlayFabResultCommon(),
                Statistics(src.Statistics)
            {}

            ~GetPlayerStatisticDefinitionsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Statistics"], Statistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output[L"Statistics"] = each_Statistics;
                return output;
            }
        };

        struct GetPlayerStatisticVersionsRequest : public PlayFabRequestCommon
        {
            std::string StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabRequestCommon(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabRequestCommon(),
                StatisticName(src.StatisticName)
            {}

            ~GetPlayerStatisticVersionsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                return output;
            }
        };

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            time_t ActivationTime;
            std::string ArchiveDownloadUrl;
            Boxed<time_t> DeactivationTime;
            Boxed<time_t> ScheduledActivationTime;
            Boxed<time_t> ScheduledDeactivationTime;
            std::string StatisticName;
            Boxed<StatisticVersionStatus> Status;
            Uint32 Version;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                ActivationTime(),
                ArchiveDownloadUrl(),
                DeactivationTime(),
                ScheduledActivationTime(),
                ScheduledDeactivationTime(),
                StatisticName(),
                Status(),
                Version()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                ActivationTime(src.ActivationTime),
                ArchiveDownloadUrl(src.ArchiveDownloadUrl),
                DeactivationTime(src.DeactivationTime),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                StatisticName(src.StatisticName),
                Status(src.Status),
                Version(src.Version)
            {}

            ~PlayerStatisticVersion() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"ActivationTime"], ActivationTime);
                FromJsonUtilS(input[L"ArchiveDownloadUrl"], ArchiveDownloadUrl);
                FromJsonUtilT(input[L"DeactivationTime"], DeactivationTime);
                FromJsonUtilT(input[L"ScheduledActivationTime"], ScheduledActivationTime);
                FromJsonUtilT(input[L"ScheduledDeactivationTime"], ScheduledDeactivationTime);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActivationTime; ToJsonUtilT(ActivationTime, each_ActivationTime); output[L"ActivationTime"] = each_ActivationTime;
                web::json::value each_ArchiveDownloadUrl; ToJsonUtilS(ArchiveDownloadUrl, each_ArchiveDownloadUrl); output[L"ArchiveDownloadUrl"] = each_ArchiveDownloadUrl;
                web::json::value each_DeactivationTime; ToJsonUtilT(DeactivationTime, each_DeactivationTime); output[L"DeactivationTime"] = each_DeactivationTime;
                web::json::value each_ScheduledActivationTime; ToJsonUtilT(ScheduledActivationTime, each_ScheduledActivationTime); output[L"ScheduledActivationTime"] = each_ScheduledActivationTime;
                web::json::value each_ScheduledDeactivationTime; ToJsonUtilT(ScheduledDeactivationTime, each_ScheduledDeactivationTime); output[L"ScheduledDeactivationTime"] = each_ScheduledDeactivationTime;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabResultCommon
        {
            std::list<PlayerStatisticVersion> StatisticVersions;

            GetPlayerStatisticVersionsResult() :
                PlayFabResultCommon(),
                StatisticVersions()
            {}

            GetPlayerStatisticVersionsResult(const GetPlayerStatisticVersionsResult& src) :
                PlayFabResultCommon(),
                StatisticVersions(src.StatisticVersions)
            {}

            ~GetPlayerStatisticVersionsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"StatisticVersions"], StatisticVersions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticVersions; ToJsonUtilO(StatisticVersions, each_StatisticVersions); output[L"StatisticVersions"] = each_StatisticVersions;
                return output;
            }
        };

        struct GetPlayerTagsRequest : public PlayFabRequestCommon
        {
            std::string Namespace;
            std::string PlayFabId;

            GetPlayerTagsRequest() :
                PlayFabRequestCommon(),
                Namespace(),
                PlayFabId()
            {}

            GetPlayerTagsRequest(const GetPlayerTagsRequest& src) :
                PlayFabRequestCommon(),
                Namespace(src.Namespace),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayerTagsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Namespace"], Namespace);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Namespace; ToJsonUtilS(Namespace, each_Namespace); output[L"Namespace"] = each_Namespace;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayerTagsResult : public PlayFabResultCommon
        {
            std::string PlayFabId;
            std::list<std::string> Tags;

            GetPlayerTagsResult() :
                PlayFabResultCommon(),
                PlayFabId(),
                Tags()
            {}

            GetPlayerTagsResult(const GetPlayerTagsResult& src) :
                PlayFabResultCommon(),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            ~GetPlayerTagsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"Tags"], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[L"Tags"] = each_Tags;
                return output;
            }
        };

        struct GetPolicyRequest : public PlayFabRequestCommon
        {
            std::string PolicyName;

            GetPolicyRequest() :
                PlayFabRequestCommon(),
                PolicyName()
            {}

            GetPolicyRequest(const GetPolicyRequest& src) :
                PlayFabRequestCommon(),
                PolicyName(src.PolicyName)
            {}

            ~GetPolicyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PolicyName"], PolicyName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output[L"PolicyName"] = each_PolicyName;
                return output;
            }
        };

        struct PermissionStatement : public PlayFabBaseModel
        {
            std::string Action;
            Boxed<ApiCondition> ApiConditions;
            std::string Comment;
            EffectType Effect;
            std::string Principal;
            std::string Resource;

            PermissionStatement() :
                PlayFabBaseModel(),
                Action(),
                ApiConditions(),
                Comment(),
                Effect(),
                Principal(),
                Resource()
            {}

            PermissionStatement(const PermissionStatement& src) :
                PlayFabBaseModel(),
                Action(src.Action),
                ApiConditions(src.ApiConditions),
                Comment(src.Comment),
                Effect(src.Effect),
                Principal(src.Principal),
                Resource(src.Resource)
            {}

            ~PermissionStatement() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Action"], Action);
                FromJsonUtilO(input[L"ApiConditions"], ApiConditions);
                FromJsonUtilS(input[L"Comment"], Comment);
                FromJsonEnum(input[L"Effect"], Effect);
                FromJsonUtilS(input[L"Principal"], Principal);
                FromJsonUtilS(input[L"Resource"], Resource);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Action; ToJsonUtilS(Action, each_Action); output[L"Action"] = each_Action;
                web::json::value each_ApiConditions; ToJsonUtilO(ApiConditions, each_ApiConditions); output[L"ApiConditions"] = each_ApiConditions;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[L"Comment"] = each_Comment;
                web::json::value each_Effect; ToJsonEnum(Effect, each_Effect); output[L"Effect"] = each_Effect;
                web::json::value each_Principal; ToJsonUtilS(Principal, each_Principal); output[L"Principal"] = each_Principal;
                web::json::value each_Resource; ToJsonUtilS(Resource, each_Resource); output[L"Resource"] = each_Resource;
                return output;
            }
        };

        struct GetPolicyResponse : public PlayFabResultCommon
        {
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            GetPolicyResponse() :
                PlayFabResultCommon(),
                PolicyName(),
                Statements()
            {}

            GetPolicyResponse(const GetPolicyResponse& src) :
                PlayFabResultCommon(),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            ~GetPolicyResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PolicyName"], PolicyName);
                FromJsonUtilO(input[L"Statements"], Statements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output[L"PolicyName"] = each_PolicyName;
                web::json::value each_Statements; ToJsonUtilO(Statements, each_Statements); output[L"Statements"] = each_Statements;
                return output;
            }
        };

        struct GetPublisherDataRequest : public PlayFabRequestCommon
        {
            std::list<std::string> Keys;

            GetPublisherDataRequest() :
                PlayFabRequestCommon(),
                Keys()
            {}

            GetPublisherDataRequest(const GetPublisherDataRequest& src) :
                PlayFabRequestCommon(),
                Keys(src.Keys)
            {}

            ~GetPublisherDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Keys"], Keys);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[L"Keys"] = each_Keys;
                return output;
            }
        };

        struct GetPublisherDataResult : public PlayFabResultCommon
        {
            std::map<std::string, std::string> Data;

            GetPublisherDataResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPublisherDataResult(const GetPublisherDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPublisherDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetRandomResultTablesRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;

            GetRandomResultTablesRequest() :
                PlayFabRequestCommon(),
                CatalogVersion()
            {}

            GetRandomResultTablesRequest(const GetRandomResultTablesRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion)
            {}

            ~GetRandomResultTablesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                return output;
            }
        };

        struct ResultTableNode : public PlayFabBaseModel
        {
            std::string ResultItem;
            ResultTableNodeType ResultItemType;
            Int32 Weight;

            ResultTableNode() :
                PlayFabBaseModel(),
                ResultItem(),
                ResultItemType(),
                Weight()
            {}

            ResultTableNode(const ResultTableNode& src) :
                PlayFabBaseModel(),
                ResultItem(src.ResultItem),
                ResultItemType(src.ResultItemType),
                Weight(src.Weight)
            {}

            ~ResultTableNode() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ResultItem"], ResultItem);
                FromJsonEnum(input[L"ResultItemType"], ResultItemType);
                FromJsonUtilP(input[L"Weight"], Weight);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ResultItem; ToJsonUtilS(ResultItem, each_ResultItem); output[L"ResultItem"] = each_ResultItem;
                web::json::value each_ResultItemType; ToJsonEnum(ResultItemType, each_ResultItemType); output[L"ResultItemType"] = each_ResultItemType;
                web::json::value each_Weight; ToJsonUtilP(Weight, each_Weight); output[L"Weight"] = each_Weight;
                return output;
            }
        };

        struct RandomResultTableListing : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::list<ResultTableNode> Nodes;
            std::string TableId;

            RandomResultTableListing() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Nodes(),
                TableId()
            {}

            RandomResultTableListing(const RandomResultTableListing& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                Nodes(src.Nodes),
                TableId(src.TableId)
            {}

            ~RandomResultTableListing() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input[L"Nodes"], Nodes);
                FromJsonUtilS(input[L"TableId"], TableId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_Nodes; ToJsonUtilO(Nodes, each_Nodes); output[L"Nodes"] = each_Nodes;
                web::json::value each_TableId; ToJsonUtilS(TableId, each_TableId); output[L"TableId"] = each_TableId;
                return output;
            }
        };

        struct GetRandomResultTablesResult : public PlayFabResultCommon
        {
            std::map<std::string, RandomResultTableListing> Tables;

            GetRandomResultTablesResult() :
                PlayFabResultCommon(),
                Tables()
            {}

            GetRandomResultTablesResult(const GetRandomResultTablesResult& src) :
                PlayFabResultCommon(),
                Tables(src.Tables)
            {}

            ~GetRandomResultTablesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Tables"], Tables);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Tables; ToJsonUtilO(Tables, each_Tables); output[L"Tables"] = each_Tables;
                return output;
            }
        };

        struct GetServerBuildInfoRequest : public PlayFabRequestCommon
        {
            std::string BuildId;

            GetServerBuildInfoRequest() :
                PlayFabRequestCommon(),
                BuildId()
            {}

            GetServerBuildInfoRequest(const GetServerBuildInfoRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId)
            {}

            ~GetServerBuildInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildId"], BuildId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[L"BuildId"] = each_BuildId;
                return output;
            }
        };

        struct GetServerBuildInfoResult : public PlayFabResultCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string Comment;
            std::string ErrorMessage;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            GetServerBuildInfoResult() :
                PlayFabResultCommon(),
                ActiveRegions(),
                BuildId(),
                Comment(),
                ErrorMessage(),
                MaxGamesPerHost(),
                MinFreeGameSlots(),
                Status(),
                Timestamp(),
                TitleId()
            {}

            GetServerBuildInfoResult(const GetServerBuildInfoResult& src) :
                PlayFabResultCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                Comment(src.Comment),
                ErrorMessage(src.ErrorMessage),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            ~GetServerBuildInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input[L"BuildId"], BuildId);
                FromJsonUtilS(input[L"Comment"], Comment);
                FromJsonUtilS(input[L"ErrorMessage"], ErrorMessage);
                FromJsonUtilP(input[L"MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input[L"MinFreeGameSlots"], MinFreeGameSlots);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[L"ActiveRegions"] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[L"BuildId"] = each_BuildId;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[L"Comment"] = each_Comment;
                web::json::value each_ErrorMessage; ToJsonUtilS(ErrorMessage, each_ErrorMessage); output[L"ErrorMessage"] = each_ErrorMessage;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[L"MaxGamesPerHost"] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[L"MinFreeGameSlots"] = each_MinFreeGameSlots;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct GetServerBuildUploadURLRequest : public PlayFabRequestCommon
        {
            std::string BuildId;

            GetServerBuildUploadURLRequest() :
                PlayFabRequestCommon(),
                BuildId()
            {}

            GetServerBuildUploadURLRequest(const GetServerBuildUploadURLRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId)
            {}

            ~GetServerBuildUploadURLRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildId"], BuildId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[L"BuildId"] = each_BuildId;
                return output;
            }
        };

        struct GetServerBuildUploadURLResult : public PlayFabResultCommon
        {
            std::string URL;

            GetServerBuildUploadURLResult() :
                PlayFabResultCommon(),
                URL()
            {}

            GetServerBuildUploadURLResult(const GetServerBuildUploadURLResult& src) :
                PlayFabResultCommon(),
                URL(src.URL)
            {}

            ~GetServerBuildUploadURLResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"URL"], URL);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_URL; ToJsonUtilS(URL, each_URL); output[L"URL"] = each_URL;
                return output;
            }
        };

        struct GetStoreItemsRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string StoreId;

            GetStoreItemsRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                StoreId()
            {}

            GetStoreItemsRequest(const GetStoreItemsRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            ~GetStoreItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"StoreId"], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[L"StoreId"] = each_StoreId;
                return output;
            }
        };

        struct StoreMarketingModel : public PlayFabBaseModel
        {
            std::string Description;
            std::string DisplayName;
            web::json::value Metadata;

            StoreMarketingModel() :
                PlayFabBaseModel(),
                Description(),
                DisplayName(),
                Metadata()
            {}

            StoreMarketingModel(const StoreMarketingModel& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                DisplayName(src.DisplayName),
                Metadata(src.Metadata)
            {}

            ~StoreMarketingModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Description"], Description);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                Metadata = input[L"Metadata"];
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[L"Description"] = each_Description;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                output[L"Metadata"] = Metadata;
                return output;
            }
        };

        struct StoreItem : public PlayFabBaseModel
        {
            web::json::value CustomData;
            Boxed<Uint32> DisplayPosition;
            std::string ItemId;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            StoreItem() :
                PlayFabBaseModel(),
                CustomData(),
                DisplayPosition(),
                ItemId(),
                RealCurrencyPrices(),
                VirtualCurrencyPrices()
            {}

            StoreItem(const StoreItem& src) :
                PlayFabBaseModel(),
                CustomData(src.CustomData),
                DisplayPosition(src.DisplayPosition),
                ItemId(src.ItemId),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            ~StoreItem() { }

            void FromJson(web::json::value& input) override
            {
                CustomData = input[L"CustomData"];
                FromJsonUtilP(input[L"DisplayPosition"], DisplayPosition);
                FromJsonUtilS(input[L"ItemId"], ItemId);
                FromJsonUtilP(input[L"RealCurrencyPrices"], RealCurrencyPrices);
                FromJsonUtilP(input[L"VirtualCurrencyPrices"], VirtualCurrencyPrices);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"CustomData"] = CustomData;
                web::json::value each_DisplayPosition; ToJsonUtilP(DisplayPosition, each_DisplayPosition); output[L"DisplayPosition"] = each_DisplayPosition;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                web::json::value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output[L"RealCurrencyPrices"] = each_RealCurrencyPrices;
                web::json::value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output[L"VirtualCurrencyPrices"] = each_VirtualCurrencyPrices;
                return output;
            }
        };

        struct GetStoreItemsResult : public PlayFabResultCommon
        {
            std::string CatalogVersion;
            Boxed<StoreMarketingModel> MarketingData;
            Boxed<SourceType> Source;
            std::list<StoreItem> Store;
            std::string StoreId;

            GetStoreItemsResult() :
                PlayFabResultCommon(),
                CatalogVersion(),
                MarketingData(),
                Source(),
                Store(),
                StoreId()
            {}

            GetStoreItemsResult(const GetStoreItemsResult& src) :
                PlayFabResultCommon(),
                CatalogVersion(src.CatalogVersion),
                MarketingData(src.MarketingData),
                Source(src.Source),
                Store(src.Store),
                StoreId(src.StoreId)
            {}

            ~GetStoreItemsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input[L"MarketingData"], MarketingData);
                FromJsonUtilE(input[L"Source"], Source);
                FromJsonUtilO(input[L"Store"], Store);
                FromJsonUtilS(input[L"StoreId"], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_MarketingData; ToJsonUtilO(MarketingData, each_MarketingData); output[L"MarketingData"] = each_MarketingData;
                web::json::value each_Source; ToJsonUtilE(Source, each_Source); output[L"Source"] = each_Source;
                web::json::value each_Store; ToJsonUtilO(Store, each_Store); output[L"Store"] = each_Store;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[L"StoreId"] = each_StoreId;
                return output;
            }
        };

        struct GetTaskInstanceRequest : public PlayFabRequestCommon
        {
            std::string TaskInstanceId;

            GetTaskInstanceRequest() :
                PlayFabRequestCommon(),
                TaskInstanceId()
            {}

            GetTaskInstanceRequest(const GetTaskInstanceRequest& src) :
                PlayFabRequestCommon(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            ~GetTaskInstanceRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TaskInstanceId"], TaskInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[L"TaskInstanceId"] = each_TaskInstanceId;
                return output;
            }
        };

        struct GetTaskInstancesRequest : public PlayFabRequestCommon
        {
            Boxed<time_t> StartedAtRangeFrom;
            Boxed<time_t> StartedAtRangeTo;
            Boxed<TaskInstanceStatus> StatusFilter;
            Boxed<NameIdentifier> TaskIdentifier;

            GetTaskInstancesRequest() :
                PlayFabRequestCommon(),
                StartedAtRangeFrom(),
                StartedAtRangeTo(),
                StatusFilter(),
                TaskIdentifier()
            {}

            GetTaskInstancesRequest(const GetTaskInstancesRequest& src) :
                PlayFabRequestCommon(),
                StartedAtRangeFrom(src.StartedAtRangeFrom),
                StartedAtRangeTo(src.StartedAtRangeTo),
                StatusFilter(src.StatusFilter),
                TaskIdentifier(src.TaskIdentifier)
            {}

            ~GetTaskInstancesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"StartedAtRangeFrom"], StartedAtRangeFrom);
                FromJsonUtilT(input[L"StartedAtRangeTo"], StartedAtRangeTo);
                FromJsonUtilE(input[L"StatusFilter"], StatusFilter);
                FromJsonUtilO(input[L"TaskIdentifier"], TaskIdentifier);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StartedAtRangeFrom; ToJsonUtilT(StartedAtRangeFrom, each_StartedAtRangeFrom); output[L"StartedAtRangeFrom"] = each_StartedAtRangeFrom;
                web::json::value each_StartedAtRangeTo; ToJsonUtilT(StartedAtRangeTo, each_StartedAtRangeTo); output[L"StartedAtRangeTo"] = each_StartedAtRangeTo;
                web::json::value each_StatusFilter; ToJsonUtilE(StatusFilter, each_StatusFilter); output[L"StatusFilter"] = each_StatusFilter;
                web::json::value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output[L"TaskIdentifier"] = each_TaskIdentifier;
                return output;
            }
        };

        struct TaskInstanceBasicSummary : public PlayFabBaseModel
        {
            Boxed<time_t> CompletedAt;
            Boxed<double> EstimatedSecondsRemaining;
            Boxed<double> PercentComplete;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            Boxed<NameIdentifier> TaskIdentifier;
            std::string TaskInstanceId;
            Boxed<ScheduledTaskType> Type;

            TaskInstanceBasicSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                ScheduledByUserId(),
                StartedAt(),
                Status(),
                TaskIdentifier(),
                TaskInstanceId(),
                Type()
            {}

            TaskInstanceBasicSummary(const TaskInstanceBasicSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier),
                TaskInstanceId(src.TaskInstanceId),
                Type(src.Type)
            {}

            ~TaskInstanceBasicSummary() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"CompletedAt"], CompletedAt);
                FromJsonUtilP(input[L"EstimatedSecondsRemaining"], EstimatedSecondsRemaining);
                FromJsonUtilP(input[L"PercentComplete"], PercentComplete);
                FromJsonUtilS(input[L"ScheduledByUserId"], ScheduledByUserId);
                FromJsonUtilT(input[L"StartedAt"], StartedAt);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilO(input[L"TaskIdentifier"], TaskIdentifier);
                FromJsonUtilS(input[L"TaskInstanceId"], TaskInstanceId);
                FromJsonUtilE(input[L"Type"], Type);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output[L"CompletedAt"] = each_CompletedAt;
                web::json::value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output[L"EstimatedSecondsRemaining"] = each_EstimatedSecondsRemaining;
                web::json::value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output[L"PercentComplete"] = each_PercentComplete;
                web::json::value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output[L"ScheduledByUserId"] = each_ScheduledByUserId;
                web::json::value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output[L"StartedAt"] = each_StartedAt;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output[L"TaskIdentifier"] = each_TaskIdentifier;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[L"TaskInstanceId"] = each_TaskInstanceId;
                web::json::value each_Type; ToJsonUtilE(Type, each_Type); output[L"Type"] = each_Type;
                return output;
            }
        };

        struct GetTaskInstancesResult : public PlayFabResultCommon
        {
            std::list<TaskInstanceBasicSummary> Summaries;

            GetTaskInstancesResult() :
                PlayFabResultCommon(),
                Summaries()
            {}

            GetTaskInstancesResult(const GetTaskInstancesResult& src) :
                PlayFabResultCommon(),
                Summaries(src.Summaries)
            {}

            ~GetTaskInstancesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Summaries"], Summaries);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Summaries; ToJsonUtilO(Summaries, each_Summaries); output[L"Summaries"] = each_Summaries;
                return output;
            }
        };

        struct GetTasksRequest : public PlayFabRequestCommon
        {
            Boxed<NameIdentifier> Identifier;

            GetTasksRequest() :
                PlayFabRequestCommon(),
                Identifier()
            {}

            GetTasksRequest(const GetTasksRequest& src) :
                PlayFabRequestCommon(),
                Identifier(src.Identifier)
            {}

            ~GetTasksRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Identifier"], Identifier);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output[L"Identifier"] = each_Identifier;
                return output;
            }
        };

        struct ScheduledTask : public PlayFabBaseModel
        {
            std::string Description;
            bool IsActive;
            Boxed<time_t> LastRunTime;
            std::string Name;
            Boxed<time_t> NextRunTime;
            web::json::value Parameter;
            std::string Schedule;
            std::string TaskId;
            Boxed<ScheduledTaskType> Type;

            ScheduledTask() :
                PlayFabBaseModel(),
                Description(),
                IsActive(),
                LastRunTime(),
                Name(),
                NextRunTime(),
                Parameter(),
                Schedule(),
                TaskId(),
                Type()
            {}

            ScheduledTask(const ScheduledTask& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                IsActive(src.IsActive),
                LastRunTime(src.LastRunTime),
                Name(src.Name),
                NextRunTime(src.NextRunTime),
                Parameter(src.Parameter),
                Schedule(src.Schedule),
                TaskId(src.TaskId),
                Type(src.Type)
            {}

            ~ScheduledTask() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Description"], Description);
                FromJsonUtilP(input[L"IsActive"], IsActive);
                FromJsonUtilT(input[L"LastRunTime"], LastRunTime);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilT(input[L"NextRunTime"], NextRunTime);
                Parameter = input[L"Parameter"];
                FromJsonUtilS(input[L"Schedule"], Schedule);
                FromJsonUtilS(input[L"TaskId"], TaskId);
                FromJsonUtilE(input[L"Type"], Type);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[L"Description"] = each_Description;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[L"IsActive"] = each_IsActive;
                web::json::value each_LastRunTime; ToJsonUtilT(LastRunTime, each_LastRunTime); output[L"LastRunTime"] = each_LastRunTime;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_NextRunTime; ToJsonUtilT(NextRunTime, each_NextRunTime); output[L"NextRunTime"] = each_NextRunTime;
                output[L"Parameter"] = Parameter;
                web::json::value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output[L"Schedule"] = each_Schedule;
                web::json::value each_TaskId; ToJsonUtilS(TaskId, each_TaskId); output[L"TaskId"] = each_TaskId;
                web::json::value each_Type; ToJsonUtilE(Type, each_Type); output[L"Type"] = each_Type;
                return output;
            }
        };

        struct GetTasksResult : public PlayFabResultCommon
        {
            std::list<ScheduledTask> Tasks;

            GetTasksResult() :
                PlayFabResultCommon(),
                Tasks()
            {}

            GetTasksResult(const GetTasksResult& src) :
                PlayFabResultCommon(),
                Tasks(src.Tasks)
            {}

            ~GetTasksResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Tasks"], Tasks);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Tasks; ToJsonUtilO(Tasks, each_Tasks); output[L"Tasks"] = each_Tasks;
                return output;
            }
        };

        struct GetTitleDataRequest : public PlayFabRequestCommon
        {
            std::list<std::string> Keys;

            GetTitleDataRequest() :
                PlayFabRequestCommon(),
                Keys()
            {}

            GetTitleDataRequest(const GetTitleDataRequest& src) :
                PlayFabRequestCommon(),
                Keys(src.Keys)
            {}

            ~GetTitleDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Keys"], Keys);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[L"Keys"] = each_Keys;
                return output;
            }
        };

        struct GetTitleDataResult : public PlayFabResultCommon
        {
            std::map<std::string, std::string> Data;

            GetTitleDataResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetTitleDataResult(const GetTitleDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetTitleDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetUserBansRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            GetUserBansRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            GetUserBansRequest(const GetUserBansRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserBansRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetUserBansResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            GetUserBansResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            GetUserBansResult(const GetUserBansResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~GetUserBansResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"BanData"], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[L"BanData"] = each_BanData;
                return output;
            }
        };

        struct GetUserDataRequest : public PlayFabRequestCommon
        {
            Boxed<Uint32> IfChangedFromDataVersion;
            std::list<std::string> Keys;
            std::string PlayFabId;

            GetUserDataRequest() :
                PlayFabRequestCommon(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabRequestCommon(),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"IfChangedFromDataVersion"], IfChangedFromDataVersion);
                FromJsonUtilS(input[L"Keys"], Keys);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IfChangedFromDataVersion; ToJsonUtilP(IfChangedFromDataVersion, each_IfChangedFromDataVersion); output[L"IfChangedFromDataVersion"] = each_IfChangedFromDataVersion;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[L"Keys"] = each_Keys;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct UserDataRecord : public PlayFabBaseModel
        {
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;
            std::string Value;

            UserDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(),
                Permission(),
                Value()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission),
                Value(src.Value)
            {}

            ~UserDataRecord() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"LastUpdated"], LastUpdated);
                FromJsonUtilE(input[L"Permission"], Permission);
                FromJsonUtilS(input[L"Value"], Value);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LastUpdated; ToJsonUtilT(LastUpdated, each_LastUpdated); output[L"LastUpdated"] = each_LastUpdated;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[L"Permission"] = each_Permission;
                web::json::value each_Value; ToJsonUtilS(Value, each_Value); output[L"Value"] = each_Value;
                return output;
            }
        };

        struct GetUserDataResult : public PlayFabResultCommon
        {
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;
            std::string PlayFabId;

            GetUserDataResult() :
                PlayFabResultCommon(),
                Data(),
                DataVersion(),
                PlayFabId()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data),
                DataVersion(src.DataVersion),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
                FromJsonUtilP(input[L"DataVersion"], DataVersion);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[L"DataVersion"] = each_DataVersion;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetUserInventoryRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            GetUserInventoryRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserInventoryRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
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

        struct GetUserInventoryResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Inventory;
            std::string PlayFabId;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabResultCommon(),
                Inventory(),
                PlayFabId(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabResultCommon(),
                Inventory(src.Inventory),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~GetUserInventoryResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Inventory"], Inventory);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilP(input[L"VirtualCurrency"], VirtualCurrency);
                FromJsonUtilO(input[L"VirtualCurrencyRechargeTimes"], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[L"Inventory"] = each_Inventory;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[L"VirtualCurrencyRechargeTimes"] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GrantedItemInstance : public PlayFabBaseModel
        {
            std::string Annotation;
            std::list<std::string> BundleContents;
            std::string BundleParent;
            std::string CatalogVersion;
            std::string CharacterId;
            std::map<std::string, std::string> CustomData;
            std::string DisplayName;
            Boxed<time_t> Expiration;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            std::string PlayFabId;
            Boxed<time_t> PurchaseDate;
            Boxed<Int32> RemainingUses;
            bool Result;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            Boxed<Int32> UsesIncrementedBy;

            GrantedItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CharacterId(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PlayFabId(),
                PurchaseDate(),
                RemainingUses(),
                Result(),
                UnitCurrency(),
                UnitPrice(),
                UsesIncrementedBy()
            {}

            GrantedItemInstance(const GrantedItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                Result(src.Result),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
            {}

            ~GrantedItemInstance() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Annotation"], Annotation);
                FromJsonUtilS(input[L"BundleContents"], BundleContents);
                FromJsonUtilS(input[L"BundleParent"], BundleParent);
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"CustomData"], CustomData);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilT(input[L"Expiration"], Expiration);
                FromJsonUtilS(input[L"ItemClass"], ItemClass);
                FromJsonUtilS(input[L"ItemId"], ItemId);
                FromJsonUtilS(input[L"ItemInstanceId"], ItemInstanceId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilT(input[L"PurchaseDate"], PurchaseDate);
                FromJsonUtilP(input[L"RemainingUses"], RemainingUses);
                FromJsonUtilP(input[L"Result"], Result);
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
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output[L"CustomData"] = each_CustomData;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output[L"Expiration"] = each_Expiration;
                web::json::value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output[L"ItemClass"] = each_ItemClass;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[L"ItemInstanceId"] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output[L"PurchaseDate"] = each_PurchaseDate;
                web::json::value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output[L"RemainingUses"] = each_RemainingUses;
                web::json::value each_Result; ToJsonUtilP(Result, each_Result); output[L"Result"] = each_Result;
                web::json::value each_UnitCurrency; ToJsonUtilS(UnitCurrency, each_UnitCurrency); output[L"UnitCurrency"] = each_UnitCurrency;
                web::json::value each_UnitPrice; ToJsonUtilP(UnitPrice, each_UnitPrice); output[L"UnitPrice"] = each_UnitPrice;
                web::json::value each_UsesIncrementedBy; ToJsonUtilP(UsesIncrementedBy, each_UsesIncrementedBy); output[L"UsesIncrementedBy"] = each_UsesIncrementedBy;
                return output;
            }
        };

        struct ItemGrant : public PlayFabBaseModel
        {
            std::string Annotation;
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::string ItemId;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            ItemGrant() :
                PlayFabBaseModel(),
                Annotation(),
                CharacterId(),
                Data(),
                ItemId(),
                KeysToRemove(),
                PlayFabId()
            {}

            ItemGrant(const ItemGrant& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                CharacterId(src.CharacterId),
                Data(src.Data),
                ItemId(src.ItemId),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            ~ItemGrant() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Annotation"], Annotation);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"Data"], Data);
                FromJsonUtilS(input[L"ItemId"], ItemId);
                FromJsonUtilS(input[L"KeysToRemove"], KeysToRemove);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output[L"Annotation"] = each_Annotation;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[L"KeysToRemove"] = each_KeysToRemove;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GrantItemsToUsersRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::list<ItemGrant> ItemGrants;

            GrantItemsToUsersRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                ItemGrants()
            {}

            GrantItemsToUsersRequest(const GrantItemsToUsersRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                ItemGrants(src.ItemGrants)
            {}

            ~GrantItemsToUsersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input[L"ItemGrants"], ItemGrants);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_ItemGrants; ToJsonUtilO(ItemGrants, each_ItemGrants); output[L"ItemGrants"] = each_ItemGrants;
                return output;
            }
        };

        struct GrantItemsToUsersResult : public PlayFabResultCommon
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToUsersResult() :
                PlayFabResultCommon(),
                ItemGrantResults()
            {}

            GrantItemsToUsersResult(const GrantItemsToUsersResult& src) :
                PlayFabResultCommon(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            ~GrantItemsToUsersResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"ItemGrantResults"], ItemGrantResults);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemGrantResults; ToJsonUtilO(ItemGrantResults, each_ItemGrantResults); output[L"ItemGrantResults"] = each_ItemGrantResults;
                return output;
            }
        };

        struct IncrementLimitedEditionItemAvailabilityRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string CatalogVersion;
            std::string ItemId;

            IncrementLimitedEditionItemAvailabilityRequest() :
                PlayFabRequestCommon(),
                Amount(),
                CatalogVersion(),
                ItemId()
            {}

            IncrementLimitedEditionItemAvailabilityRequest(const IncrementLimitedEditionItemAvailabilityRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                CatalogVersion(src.CatalogVersion),
                ItemId(src.ItemId)
            {}

            ~IncrementLimitedEditionItemAvailabilityRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Amount"], Amount);
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"ItemId"], ItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[L"Amount"] = each_Amount;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                return output;
            }
        };

        struct IncrementLimitedEditionItemAvailabilityResult : public PlayFabResultCommon
        {

            IncrementLimitedEditionItemAvailabilityResult() :
                PlayFabResultCommon()
            {}

            IncrementLimitedEditionItemAvailabilityResult(const IncrementLimitedEditionItemAvailabilityResult&) :
                PlayFabResultCommon()
            {}

            ~IncrementLimitedEditionItemAvailabilityResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct IncrementPlayerStatisticVersionRequest : public PlayFabRequestCommon
        {
            std::string StatisticName;

            IncrementPlayerStatisticVersionRequest() :
                PlayFabRequestCommon(),
                StatisticName()
            {}

            IncrementPlayerStatisticVersionRequest(const IncrementPlayerStatisticVersionRequest& src) :
                PlayFabRequestCommon(),
                StatisticName(src.StatisticName)
            {}

            ~IncrementPlayerStatisticVersionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                return output;
            }
        };

        struct IncrementPlayerStatisticVersionResult : public PlayFabResultCommon
        {
            Boxed<PlayerStatisticVersion> StatisticVersion;

            IncrementPlayerStatisticVersionResult() :
                PlayFabResultCommon(),
                StatisticVersion()
            {}

            IncrementPlayerStatisticVersionResult(const IncrementPlayerStatisticVersionResult& src) :
                PlayFabResultCommon(),
                StatisticVersion(src.StatisticVersion)
            {}

            ~IncrementPlayerStatisticVersionResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"StatisticVersion"], StatisticVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticVersion; ToJsonUtilO(StatisticVersion, each_StatisticVersion); output[L"StatisticVersion"] = each_StatisticVersion;
                return output;
            }
        };

        struct ListBuildsRequest : public PlayFabRequestCommon
        {

            ListBuildsRequest() :
                PlayFabRequestCommon()
            {}

            ListBuildsRequest(const ListBuildsRequest&) :
                PlayFabRequestCommon()
            {}

            ~ListBuildsRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ListBuildsResult : public PlayFabResultCommon
        {
            std::list<GetServerBuildInfoResult> Builds;

            ListBuildsResult() :
                PlayFabResultCommon(),
                Builds()
            {}

            ListBuildsResult(const ListBuildsResult& src) :
                PlayFabResultCommon(),
                Builds(src.Builds)
            {}

            ~ListBuildsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Builds"], Builds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Builds; ToJsonUtilO(Builds, each_Builds); output[L"Builds"] = each_Builds;
                return output;
            }
        };

        struct ListVirtualCurrencyTypesRequest : public PlayFabRequestCommon
        {

            ListVirtualCurrencyTypesRequest() :
                PlayFabRequestCommon()
            {}

            ListVirtualCurrencyTypesRequest(const ListVirtualCurrencyTypesRequest&) :
                PlayFabRequestCommon()
            {}

            ~ListVirtualCurrencyTypesRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ListVirtualCurrencyTypesResult : public PlayFabResultCommon
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            ListVirtualCurrencyTypesResult() :
                PlayFabResultCommon(),
                VirtualCurrencies()
            {}

            ListVirtualCurrencyTypesResult(const ListVirtualCurrencyTypesResult& src) :
                PlayFabResultCommon(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ~ListVirtualCurrencyTypesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"VirtualCurrencies"], VirtualCurrencies);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output[L"VirtualCurrencies"] = each_VirtualCurrencies;
                return output;
            }
        };

        struct LookupUserAccountInfoRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string PlayFabId;
            std::string TitleDisplayName;
            std::string Username;

            LookupUserAccountInfoRequest() :
                PlayFabRequestCommon(),
                Email(),
                PlayFabId(),
                TitleDisplayName(),
                Username()
            {}

            LookupUserAccountInfoRequest(const LookupUserAccountInfoRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                PlayFabId(src.PlayFabId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            ~LookupUserAccountInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Email"], Email);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"TitleDisplayName"], TitleDisplayName);
                FromJsonUtilS(input[L"Username"], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_TitleDisplayName; ToJsonUtilS(TitleDisplayName, each_TitleDisplayName); output[L"TitleDisplayName"] = each_TitleDisplayName;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                return output;
            }
        };

        struct UserAndroidDeviceInfo : public PlayFabBaseModel
        {
            std::string AndroidDeviceId;

            UserAndroidDeviceInfo() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UserAndroidDeviceInfo(const UserAndroidDeviceInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            ~UserAndroidDeviceInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AndroidDeviceId"], AndroidDeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output[L"AndroidDeviceId"] = each_AndroidDeviceId;
                return output;
            }
        };

        struct UserCustomIdInfo : public PlayFabBaseModel
        {
            std::string CustomId;

            UserCustomIdInfo() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UserCustomIdInfo(const UserCustomIdInfo& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            ~UserCustomIdInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CustomId"], CustomId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output[L"CustomId"] = each_CustomId;
                return output;
            }
        };

        struct UserFacebookInfo : public PlayFabBaseModel
        {
            std::string FacebookId;
            std::string FullName;

            UserFacebookInfo() :
                PlayFabBaseModel(),
                FacebookId(),
                FullName()
            {}

            UserFacebookInfo(const UserFacebookInfo& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                FullName(src.FullName)
            {}

            ~UserFacebookInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FacebookId"], FacebookId);
                FromJsonUtilS(input[L"FullName"], FullName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookId; ToJsonUtilS(FacebookId, each_FacebookId); output[L"FacebookId"] = each_FacebookId;
                web::json::value each_FullName; ToJsonUtilS(FullName, each_FullName); output[L"FullName"] = each_FullName;
                return output;
            }
        };

        struct UserGameCenterInfo : public PlayFabBaseModel
        {
            std::string GameCenterId;

            UserGameCenterInfo() :
                PlayFabBaseModel(),
                GameCenterId()
            {}

            UserGameCenterInfo(const UserGameCenterInfo& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId)
            {}

            ~UserGameCenterInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"GameCenterId"], GameCenterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output[L"GameCenterId"] = each_GameCenterId;
                return output;
            }
        };

        struct UserGoogleInfo : public PlayFabBaseModel
        {
            std::string GoogleEmail;
            std::string GoogleGender;
            std::string GoogleId;
            std::string GoogleLocale;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleEmail(),
                GoogleGender(),
                GoogleId(),
                GoogleLocale()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleEmail(src.GoogleEmail),
                GoogleGender(src.GoogleGender),
                GoogleId(src.GoogleId),
                GoogleLocale(src.GoogleLocale)
            {}

            ~UserGoogleInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"GoogleEmail"], GoogleEmail);
                FromJsonUtilS(input[L"GoogleGender"], GoogleGender);
                FromJsonUtilS(input[L"GoogleId"], GoogleId);
                FromJsonUtilS(input[L"GoogleLocale"], GoogleLocale);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GoogleEmail; ToJsonUtilS(GoogleEmail, each_GoogleEmail); output[L"GoogleEmail"] = each_GoogleEmail;
                web::json::value each_GoogleGender; ToJsonUtilS(GoogleGender, each_GoogleGender); output[L"GoogleGender"] = each_GoogleGender;
                web::json::value each_GoogleId; ToJsonUtilS(GoogleId, each_GoogleId); output[L"GoogleId"] = each_GoogleId;
                web::json::value each_GoogleLocale; ToJsonUtilS(GoogleLocale, each_GoogleLocale); output[L"GoogleLocale"] = each_GoogleLocale;
                return output;
            }
        };

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
            std::string IosDeviceId;

            UserIosDeviceInfo() :
                PlayFabBaseModel(),
                IosDeviceId()
            {}

            UserIosDeviceInfo(const UserIosDeviceInfo& src) :
                PlayFabBaseModel(),
                IosDeviceId(src.IosDeviceId)
            {}

            ~UserIosDeviceInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"IosDeviceId"], IosDeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IosDeviceId; ToJsonUtilS(IosDeviceId, each_IosDeviceId); output[L"IosDeviceId"] = each_IosDeviceId;
                return output;
            }
        };

        struct UserKongregateInfo : public PlayFabBaseModel
        {
            std::string KongregateId;
            std::string KongregateName;

            UserKongregateInfo() :
                PlayFabBaseModel(),
                KongregateId(),
                KongregateName()
            {}

            UserKongregateInfo(const UserKongregateInfo& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                KongregateName(src.KongregateName)
            {}

            ~UserKongregateInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"KongregateId"], KongregateId);
                FromJsonUtilS(input[L"KongregateName"], KongregateName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output[L"KongregateId"] = each_KongregateId;
                web::json::value each_KongregateName; ToJsonUtilS(KongregateName, each_KongregateName); output[L"KongregateName"] = each_KongregateName;
                return output;
            }
        };

        struct UserPrivateAccountInfo : public PlayFabBaseModel
        {
            std::string Email;

            UserPrivateAccountInfo() :
                PlayFabBaseModel(),
                Email()
            {}

            UserPrivateAccountInfo(const UserPrivateAccountInfo& src) :
                PlayFabBaseModel(),
                Email(src.Email)
            {}

            ~UserPrivateAccountInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Email"], Email);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                return output;
            }
        };

        struct UserPsnInfo : public PlayFabBaseModel
        {
            std::string PsnAccountId;
            std::string PsnOnlineId;

            UserPsnInfo() :
                PlayFabBaseModel(),
                PsnAccountId(),
                PsnOnlineId()
            {}

            UserPsnInfo(const UserPsnInfo& src) :
                PlayFabBaseModel(),
                PsnAccountId(src.PsnAccountId),
                PsnOnlineId(src.PsnOnlineId)
            {}

            ~UserPsnInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PsnAccountId"], PsnAccountId);
                FromJsonUtilS(input[L"PsnOnlineId"], PsnOnlineId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PsnAccountId; ToJsonUtilS(PsnAccountId, each_PsnAccountId); output[L"PsnAccountId"] = each_PsnAccountId;
                web::json::value each_PsnOnlineId; ToJsonUtilS(PsnOnlineId, each_PsnOnlineId); output[L"PsnOnlineId"] = each_PsnOnlineId;
                return output;
            }
        };

        struct UserSteamInfo : public PlayFabBaseModel
        {
            Boxed<TitleActivationStatus> SteamActivationStatus;
            std::string SteamCountry;
            Boxed<Currency> SteamCurrency;
            std::string SteamId;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamActivationStatus(),
                SteamCountry(),
                SteamCurrency(),
                SteamId()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamActivationStatus(src.SteamActivationStatus),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamId(src.SteamId)
            {}

            ~UserSteamInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"SteamActivationStatus"], SteamActivationStatus);
                FromJsonUtilS(input[L"SteamCountry"], SteamCountry);
                FromJsonUtilE(input[L"SteamCurrency"], SteamCurrency);
                FromJsonUtilS(input[L"SteamId"], SteamId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SteamActivationStatus; ToJsonUtilE(SteamActivationStatus, each_SteamActivationStatus); output[L"SteamActivationStatus"] = each_SteamActivationStatus;
                web::json::value each_SteamCountry; ToJsonUtilS(SteamCountry, each_SteamCountry); output[L"SteamCountry"] = each_SteamCountry;
                web::json::value each_SteamCurrency; ToJsonUtilE(SteamCurrency, each_SteamCurrency); output[L"SteamCurrency"] = each_SteamCurrency;
                web::json::value each_SteamId; ToJsonUtilS(SteamId, each_SteamId); output[L"SteamId"] = each_SteamId;
                return output;
            }
        };

        struct UserTitleInfo : public PlayFabBaseModel
        {
            std::string AvatarUrl;
            time_t Created;
            std::string DisplayName;
            Boxed<time_t> FirstLogin;
            Boxed<bool> isBanned;
            Boxed<time_t> LastLogin;
            Boxed<UserOrigination> Origination;
            Boxed<EntityKey> TitlePlayerAccount;

            UserTitleInfo() :
                PlayFabBaseModel(),
                AvatarUrl(),
                Created(),
                DisplayName(),
                FirstLogin(),
                isBanned(),
                LastLogin(),
                Origination(),
                TitlePlayerAccount()
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                AvatarUrl(src.AvatarUrl),
                Created(src.Created),
                DisplayName(src.DisplayName),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned),
                LastLogin(src.LastLogin),
                Origination(src.Origination),
                TitlePlayerAccount(src.TitlePlayerAccount)
            {}

            ~UserTitleInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AvatarUrl"], AvatarUrl);
                FromJsonUtilT(input[L"Created"], Created);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilT(input[L"FirstLogin"], FirstLogin);
                FromJsonUtilP(input[L"isBanned"], isBanned);
                FromJsonUtilT(input[L"LastLogin"], LastLogin);
                FromJsonUtilE(input[L"Origination"], Origination);
                FromJsonUtilO(input[L"TitlePlayerAccount"], TitlePlayerAccount);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AvatarUrl; ToJsonUtilS(AvatarUrl, each_AvatarUrl); output[L"AvatarUrl"] = each_AvatarUrl;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[L"Created"] = each_Created;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_FirstLogin; ToJsonUtilT(FirstLogin, each_FirstLogin); output[L"FirstLogin"] = each_FirstLogin;
                web::json::value each_isBanned; ToJsonUtilP(isBanned, each_isBanned); output[L"isBanned"] = each_isBanned;
                web::json::value each_LastLogin; ToJsonUtilT(LastLogin, each_LastLogin); output[L"LastLogin"] = each_LastLogin;
                web::json::value each_Origination; ToJsonUtilE(Origination, each_Origination); output[L"Origination"] = each_Origination;
                web::json::value each_TitlePlayerAccount; ToJsonUtilO(TitlePlayerAccount, each_TitlePlayerAccount); output[L"TitlePlayerAccount"] = each_TitlePlayerAccount;
                return output;
            }
        };

        struct UserTwitchInfo : public PlayFabBaseModel
        {
            std::string TwitchId;
            std::string TwitchUserName;

            UserTwitchInfo() :
                PlayFabBaseModel(),
                TwitchId(),
                TwitchUserName()
            {}

            UserTwitchInfo(const UserTwitchInfo& src) :
                PlayFabBaseModel(),
                TwitchId(src.TwitchId),
                TwitchUserName(src.TwitchUserName)
            {}

            ~UserTwitchInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TwitchId"], TwitchId);
                FromJsonUtilS(input[L"TwitchUserName"], TwitchUserName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TwitchId; ToJsonUtilS(TwitchId, each_TwitchId); output[L"TwitchId"] = each_TwitchId;
                web::json::value each_TwitchUserName; ToJsonUtilS(TwitchUserName, each_TwitchUserName); output[L"TwitchUserName"] = each_TwitchUserName;
                return output;
            }
        };

        struct UserXboxInfo : public PlayFabBaseModel
        {
            std::string XboxUserId;

            UserXboxInfo() :
                PlayFabBaseModel(),
                XboxUserId()
            {}

            UserXboxInfo(const UserXboxInfo& src) :
                PlayFabBaseModel(),
                XboxUserId(src.XboxUserId)
            {}

            ~UserXboxInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"XboxUserId"], XboxUserId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_XboxUserId; ToJsonUtilS(XboxUserId, each_XboxUserId); output[L"XboxUserId"] = each_XboxUserId;
                return output;
            }
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            Boxed<UserAndroidDeviceInfo> AndroidDeviceInfo;
            time_t Created;
            Boxed<UserCustomIdInfo> CustomIdInfo;
            Boxed<UserFacebookInfo> FacebookInfo;
            Boxed<UserGameCenterInfo> GameCenterInfo;
            Boxed<UserGoogleInfo> GoogleInfo;
            Boxed<UserIosDeviceInfo> IosDeviceInfo;
            Boxed<UserKongregateInfo> KongregateInfo;
            std::string PlayFabId;
            Boxed<UserPrivateAccountInfo> PrivateInfo;
            Boxed<UserPsnInfo> PsnInfo;
            Boxed<UserSteamInfo> SteamInfo;
            Boxed<UserTitleInfo> TitleInfo;
            Boxed<UserTwitchInfo> TwitchInfo;
            std::string Username;
            Boxed<UserXboxInfo> XboxInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                AndroidDeviceInfo(),
                Created(),
                CustomIdInfo(),
                FacebookInfo(),
                GameCenterInfo(),
                GoogleInfo(),
                IosDeviceInfo(),
                KongregateInfo(),
                PlayFabId(),
                PrivateInfo(),
                PsnInfo(),
                SteamInfo(),
                TitleInfo(),
                TwitchInfo(),
                Username(),
                XboxInfo()
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceInfo(src.AndroidDeviceInfo),
                Created(src.Created),
                CustomIdInfo(src.CustomIdInfo),
                FacebookInfo(src.FacebookInfo),
                GameCenterInfo(src.GameCenterInfo),
                GoogleInfo(src.GoogleInfo),
                IosDeviceInfo(src.IosDeviceInfo),
                KongregateInfo(src.KongregateInfo),
                PlayFabId(src.PlayFabId),
                PrivateInfo(src.PrivateInfo),
                PsnInfo(src.PsnInfo),
                SteamInfo(src.SteamInfo),
                TitleInfo(src.TitleInfo),
                TwitchInfo(src.TwitchInfo),
                Username(src.Username),
                XboxInfo(src.XboxInfo)
            {}

            ~UserAccountInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"AndroidDeviceInfo"], AndroidDeviceInfo);
                FromJsonUtilT(input[L"Created"], Created);
                FromJsonUtilO(input[L"CustomIdInfo"], CustomIdInfo);
                FromJsonUtilO(input[L"FacebookInfo"], FacebookInfo);
                FromJsonUtilO(input[L"GameCenterInfo"], GameCenterInfo);
                FromJsonUtilO(input[L"GoogleInfo"], GoogleInfo);
                FromJsonUtilO(input[L"IosDeviceInfo"], IosDeviceInfo);
                FromJsonUtilO(input[L"KongregateInfo"], KongregateInfo);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilO(input[L"PrivateInfo"], PrivateInfo);
                FromJsonUtilO(input[L"PsnInfo"], PsnInfo);
                FromJsonUtilO(input[L"SteamInfo"], SteamInfo);
                FromJsonUtilO(input[L"TitleInfo"], TitleInfo);
                FromJsonUtilO(input[L"TwitchInfo"], TwitchInfo);
                FromJsonUtilS(input[L"Username"], Username);
                FromJsonUtilO(input[L"XboxInfo"], XboxInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDeviceInfo; ToJsonUtilO(AndroidDeviceInfo, each_AndroidDeviceInfo); output[L"AndroidDeviceInfo"] = each_AndroidDeviceInfo;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[L"Created"] = each_Created;
                web::json::value each_CustomIdInfo; ToJsonUtilO(CustomIdInfo, each_CustomIdInfo); output[L"CustomIdInfo"] = each_CustomIdInfo;
                web::json::value each_FacebookInfo; ToJsonUtilO(FacebookInfo, each_FacebookInfo); output[L"FacebookInfo"] = each_FacebookInfo;
                web::json::value each_GameCenterInfo; ToJsonUtilO(GameCenterInfo, each_GameCenterInfo); output[L"GameCenterInfo"] = each_GameCenterInfo;
                web::json::value each_GoogleInfo; ToJsonUtilO(GoogleInfo, each_GoogleInfo); output[L"GoogleInfo"] = each_GoogleInfo;
                web::json::value each_IosDeviceInfo; ToJsonUtilO(IosDeviceInfo, each_IosDeviceInfo); output[L"IosDeviceInfo"] = each_IosDeviceInfo;
                web::json::value each_KongregateInfo; ToJsonUtilO(KongregateInfo, each_KongregateInfo); output[L"KongregateInfo"] = each_KongregateInfo;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_PrivateInfo; ToJsonUtilO(PrivateInfo, each_PrivateInfo); output[L"PrivateInfo"] = each_PrivateInfo;
                web::json::value each_PsnInfo; ToJsonUtilO(PsnInfo, each_PsnInfo); output[L"PsnInfo"] = each_PsnInfo;
                web::json::value each_SteamInfo; ToJsonUtilO(SteamInfo, each_SteamInfo); output[L"SteamInfo"] = each_SteamInfo;
                web::json::value each_TitleInfo; ToJsonUtilO(TitleInfo, each_TitleInfo); output[L"TitleInfo"] = each_TitleInfo;
                web::json::value each_TwitchInfo; ToJsonUtilO(TwitchInfo, each_TwitchInfo); output[L"TwitchInfo"] = each_TwitchInfo;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                web::json::value each_XboxInfo; ToJsonUtilO(XboxInfo, each_XboxInfo); output[L"XboxInfo"] = each_XboxInfo;
                return output;
            }
        };

        struct LookupUserAccountInfoResult : public PlayFabResultCommon
        {
            Boxed<UserAccountInfo> UserInfo;

            LookupUserAccountInfoResult() :
                PlayFabResultCommon(),
                UserInfo()
            {}

            LookupUserAccountInfoResult(const LookupUserAccountInfoResult& src) :
                PlayFabResultCommon(),
                UserInfo(src.UserInfo)
            {}

            ~LookupUserAccountInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"UserInfo"], UserInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_UserInfo; ToJsonUtilO(UserInfo, each_UserInfo); output[L"UserInfo"] = each_UserInfo;
                return output;
            }
        };

        struct ModifyMatchmakerGameModesRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::list<GameModeInfo> GameModes;

            ModifyMatchmakerGameModesRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                GameModes()
            {}

            ModifyMatchmakerGameModesRequest(const ModifyMatchmakerGameModesRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                GameModes(src.GameModes)
            {}

            ~ModifyMatchmakerGameModesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildVersion"], BuildVersion);
                FromJsonUtilO(input[L"GameModes"], GameModes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[L"BuildVersion"] = each_BuildVersion;
                web::json::value each_GameModes; ToJsonUtilO(GameModes, each_GameModes); output[L"GameModes"] = each_GameModes;
                return output;
            }
        };

        struct ModifyMatchmakerGameModesResult : public PlayFabResultCommon
        {

            ModifyMatchmakerGameModesResult() :
                PlayFabResultCommon()
            {}

            ModifyMatchmakerGameModesResult(const ModifyMatchmakerGameModesResult&) :
                PlayFabResultCommon()
            {}

            ~ModifyMatchmakerGameModesResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ModifyServerBuildRequest : public PlayFabRequestCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<time_t> Timestamp;

            ModifyServerBuildRequest() :
                PlayFabRequestCommon(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(),
                MinFreeGameSlots(),
                Timestamp()
            {}

            ModifyServerBuildRequest(const ModifyServerBuildRequest& src) :
                PlayFabRequestCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Timestamp(src.Timestamp)
            {}

            ~ModifyServerBuildRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input[L"BuildId"], BuildId);
                FromJsonUtilS(input[L"CommandLineTemplate"], CommandLineTemplate);
                FromJsonUtilS(input[L"Comment"], Comment);
                FromJsonUtilS(input[L"ExecutablePath"], ExecutablePath);
                FromJsonUtilP(input[L"MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input[L"MinFreeGameSlots"], MinFreeGameSlots);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[L"ActiveRegions"] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[L"BuildId"] = each_BuildId;
                web::json::value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output[L"CommandLineTemplate"] = each_CommandLineTemplate;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[L"Comment"] = each_Comment;
                web::json::value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output[L"ExecutablePath"] = each_ExecutablePath;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[L"MaxGamesPerHost"] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[L"MinFreeGameSlots"] = each_MinFreeGameSlots;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                return output;
            }
        };

        struct ModifyServerBuildResult : public PlayFabResultCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            ModifyServerBuildResult() :
                PlayFabResultCommon(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(),
                MinFreeGameSlots(),
                Status(),
                Timestamp(),
                TitleId()
            {}

            ModifyServerBuildResult(const ModifyServerBuildResult& src) :
                PlayFabResultCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            ~ModifyServerBuildResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input[L"BuildId"], BuildId);
                FromJsonUtilS(input[L"CommandLineTemplate"], CommandLineTemplate);
                FromJsonUtilS(input[L"Comment"], Comment);
                FromJsonUtilS(input[L"ExecutablePath"], ExecutablePath);
                FromJsonUtilP(input[L"MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input[L"MinFreeGameSlots"], MinFreeGameSlots);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[L"ActiveRegions"] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[L"BuildId"] = each_BuildId;
                web::json::value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output[L"CommandLineTemplate"] = each_CommandLineTemplate;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[L"Comment"] = each_Comment;
                web::json::value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output[L"ExecutablePath"] = each_ExecutablePath;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[L"MaxGamesPerHost"] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[L"MinFreeGameSlots"] = each_MinFreeGameSlots;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct ModifyUserVirtualCurrencyResult : public PlayFabResultCommon
        {
            Int32 Balance;
            Int32 BalanceChange;
            std::string PlayFabId;
            std::string VirtualCurrency;

            ModifyUserVirtualCurrencyResult() :
                PlayFabResultCommon(),
                Balance(),
                BalanceChange(),
                PlayFabId(),
                VirtualCurrency()
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabResultCommon(),
                Balance(src.Balance),
                BalanceChange(src.BalanceChange),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~ModifyUserVirtualCurrencyResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Balance"], Balance);
                FromJsonUtilP(input[L"BalanceChange"], BalanceChange);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"VirtualCurrency"], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Balance; ToJsonUtilP(Balance, each_Balance); output[L"Balance"] = each_Balance;
                web::json::value each_BalanceChange; ToJsonUtilP(BalanceChange, each_BalanceChange); output[L"BalanceChange"] = each_BalanceChange;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct RandomResultTable : public PlayFabBaseModel
        {
            std::list<ResultTableNode> Nodes;
            std::string TableId;

            RandomResultTable() :
                PlayFabBaseModel(),
                Nodes(),
                TableId()
            {}

            RandomResultTable(const RandomResultTable& src) :
                PlayFabBaseModel(),
                Nodes(src.Nodes),
                TableId(src.TableId)
            {}

            ~RandomResultTable() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Nodes"], Nodes);
                FromJsonUtilS(input[L"TableId"], TableId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Nodes; ToJsonUtilO(Nodes, each_Nodes); output[L"Nodes"] = each_Nodes;
                web::json::value each_TableId; ToJsonUtilS(TableId, each_TableId); output[L"TableId"] = each_TableId;
                return output;
            }
        };

        struct RefundPurchaseRequest : public PlayFabRequestCommon
        {
            std::string OrderId;
            std::string PlayFabId;
            std::string Reason;

            RefundPurchaseRequest() :
                PlayFabRequestCommon(),
                OrderId(),
                PlayFabId(),
                Reason()
            {}

            RefundPurchaseRequest(const RefundPurchaseRequest& src) :
                PlayFabRequestCommon(),
                OrderId(src.OrderId),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ~RefundPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"OrderId"], OrderId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"Reason"], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[L"Reason"] = each_Reason;
                return output;
            }
        };

        struct RefundPurchaseResponse : public PlayFabResultCommon
        {
            std::string PurchaseStatus;

            RefundPurchaseResponse() :
                PlayFabResultCommon(),
                PurchaseStatus()
            {}

            RefundPurchaseResponse(const RefundPurchaseResponse& src) :
                PlayFabResultCommon(),
                PurchaseStatus(src.PurchaseStatus)
            {}

            ~RefundPurchaseResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PurchaseStatus"], PurchaseStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PurchaseStatus; ToJsonUtilS(PurchaseStatus, each_PurchaseStatus); output[L"PurchaseStatus"] = each_PurchaseStatus;
                return output;
            }
        };

        struct RemovePlayerTagRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;
            std::string TagName;

            RemovePlayerTagRequest() :
                PlayFabRequestCommon(),
                PlayFabId(),
                TagName()
            {}

            RemovePlayerTagRequest(const RemovePlayerTagRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            ~RemovePlayerTagRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"TagName"], TagName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_TagName; ToJsonUtilS(TagName, each_TagName); output[L"TagName"] = each_TagName;
                return output;
            }
        };

        struct RemovePlayerTagResult : public PlayFabResultCommon
        {

            RemovePlayerTagResult() :
                PlayFabResultCommon()
            {}

            RemovePlayerTagResult(const RemovePlayerTagResult&) :
                PlayFabResultCommon()
            {}

            ~RemovePlayerTagResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveServerBuildRequest : public PlayFabRequestCommon
        {
            std::string BuildId;

            RemoveServerBuildRequest() :
                PlayFabRequestCommon(),
                BuildId()
            {}

            RemoveServerBuildRequest(const RemoveServerBuildRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId)
            {}

            ~RemoveServerBuildRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildId"], BuildId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[L"BuildId"] = each_BuildId;
                return output;
            }
        };

        struct RemoveServerBuildResult : public PlayFabResultCommon
        {

            RemoveServerBuildResult() :
                PlayFabResultCommon()
            {}

            RemoveServerBuildResult(const RemoveServerBuildResult&) :
                PlayFabResultCommon()
            {}

            ~RemoveServerBuildResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveVirtualCurrencyTypesRequest : public PlayFabRequestCommon
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            RemoveVirtualCurrencyTypesRequest() :
                PlayFabRequestCommon(),
                VirtualCurrencies()
            {}

            RemoveVirtualCurrencyTypesRequest(const RemoveVirtualCurrencyTypesRequest& src) :
                PlayFabRequestCommon(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ~RemoveVirtualCurrencyTypesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"VirtualCurrencies"], VirtualCurrencies);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output[L"VirtualCurrencies"] = each_VirtualCurrencies;
                return output;
            }
        };

        struct ResetCharacterStatisticsRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string PlayFabId;

            ResetCharacterStatisticsRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                PlayFabId()
            {}

            ResetCharacterStatisticsRequest(const ResetCharacterStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId)
            {}

            ~ResetCharacterStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct ResetCharacterStatisticsResult : public PlayFabResultCommon
        {

            ResetCharacterStatisticsResult() :
                PlayFabResultCommon()
            {}

            ResetCharacterStatisticsResult(const ResetCharacterStatisticsResult&) :
                PlayFabResultCommon()
            {}

            ~ResetCharacterStatisticsResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ResetPasswordRequest : public PlayFabRequestCommon
        {
            std::string Password;
            std::string Token;

            ResetPasswordRequest() :
                PlayFabRequestCommon(),
                Password(),
                Token()
            {}

            ResetPasswordRequest(const ResetPasswordRequest& src) :
                PlayFabRequestCommon(),
                Password(src.Password),
                Token(src.Token)
            {}

            ~ResetPasswordRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Password"], Password);
                FromJsonUtilS(input[L"Token"], Token);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[L"Password"] = each_Password;
                web::json::value each_Token; ToJsonUtilS(Token, each_Token); output[L"Token"] = each_Token;
                return output;
            }
        };

        struct ResetPasswordResult : public PlayFabResultCommon
        {

            ResetPasswordResult() :
                PlayFabResultCommon()
            {}

            ResetPasswordResult(const ResetPasswordResult&) :
                PlayFabResultCommon()
            {}

            ~ResetPasswordResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ResetUserStatisticsRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            ResetUserStatisticsRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            ResetUserStatisticsRequest(const ResetUserStatisticsRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~ResetUserStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct ResetUserStatisticsResult : public PlayFabResultCommon
        {

            ResetUserStatisticsResult() :
                PlayFabResultCommon()
            {}

            ResetUserStatisticsResult(const ResetUserStatisticsResult&) :
                PlayFabResultCommon()
            {}

            ~ResetUserStatisticsResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ResolvePurchaseDisputeRequest : public PlayFabRequestCommon
        {
            std::string OrderId;
            ResolutionOutcome Outcome;
            std::string PlayFabId;
            std::string Reason;

            ResolvePurchaseDisputeRequest() :
                PlayFabRequestCommon(),
                OrderId(),
                Outcome(),
                PlayFabId(),
                Reason()
            {}

            ResolvePurchaseDisputeRequest(const ResolvePurchaseDisputeRequest& src) :
                PlayFabRequestCommon(),
                OrderId(src.OrderId),
                Outcome(src.Outcome),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ~ResolvePurchaseDisputeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"OrderId"], OrderId);
                FromJsonEnum(input[L"Outcome"], Outcome);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"Reason"], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                web::json::value each_Outcome; ToJsonEnum(Outcome, each_Outcome); output[L"Outcome"] = each_Outcome;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[L"Reason"] = each_Reason;
                return output;
            }
        };

        struct ResolvePurchaseDisputeResponse : public PlayFabResultCommon
        {
            std::string PurchaseStatus;

            ResolvePurchaseDisputeResponse() :
                PlayFabResultCommon(),
                PurchaseStatus()
            {}

            ResolvePurchaseDisputeResponse(const ResolvePurchaseDisputeResponse& src) :
                PlayFabResultCommon(),
                PurchaseStatus(src.PurchaseStatus)
            {}

            ~ResolvePurchaseDisputeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PurchaseStatus"], PurchaseStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PurchaseStatus; ToJsonUtilS(PurchaseStatus, each_PurchaseStatus); output[L"PurchaseStatus"] = each_PurchaseStatus;
                return output;
            }
        };

        struct RevokeAllBansForUserRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            RevokeAllBansForUserRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            RevokeAllBansForUserRequest(const RevokeAllBansForUserRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~RevokeAllBansForUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct RevokeAllBansForUserResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            RevokeAllBansForUserResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            RevokeAllBansForUserResult(const RevokeAllBansForUserResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~RevokeAllBansForUserResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"BanData"], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[L"BanData"] = each_BanData;
                return output;
            }
        };

        struct RevokeBansRequest : public PlayFabRequestCommon
        {
            std::list<std::string> BanIds;

            RevokeBansRequest() :
                PlayFabRequestCommon(),
                BanIds()
            {}

            RevokeBansRequest(const RevokeBansRequest& src) :
                PlayFabRequestCommon(),
                BanIds(src.BanIds)
            {}

            ~RevokeBansRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BanIds"], BanIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanIds; ToJsonUtilS(BanIds, each_BanIds); output[L"BanIds"] = each_BanIds;
                return output;
            }
        };

        struct RevokeBansResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            RevokeBansResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            RevokeBansResult(const RevokeBansResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~RevokeBansResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"BanData"], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[L"BanData"] = each_BanData;
                return output;
            }
        };

        struct RevokeInventoryItem : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            RevokeInventoryItem() :
                PlayFabBaseModel(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            RevokeInventoryItem(const RevokeInventoryItem& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ~RevokeInventoryItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"ItemInstanceId"], ItemInstanceId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[L"ItemInstanceId"] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct RevokeInventoryItemRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            RevokeInventoryItemRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            RevokeInventoryItemRequest(const RevokeInventoryItemRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ~RevokeInventoryItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"ItemInstanceId"], ItemInstanceId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[L"ItemInstanceId"] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct RevokeInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::list<RevokeInventoryItem> Items;

            RevokeInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Items()
            {}

            RevokeInventoryItemsRequest(const RevokeInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Items(src.Items)
            {}

            ~RevokeInventoryItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Items"], Items);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Items; ToJsonUtilO(Items, each_Items); output[L"Items"] = each_Items;
                return output;
            }
        };

        struct RevokeItemError : public PlayFabBaseModel
        {
            Boxed<GenericErrorCodes> Error;
            Boxed<RevokeInventoryItem> Item;

            RevokeItemError() :
                PlayFabBaseModel(),
                Error(),
                Item()
            {}

            RevokeItemError(const RevokeItemError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Item(src.Item)
            {}

            ~RevokeItemError() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"Error"], Error);
                FromJsonUtilO(input[L"Item"], Item);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Error; ToJsonUtilE(Error, each_Error); output[L"Error"] = each_Error;
                web::json::value each_Item; ToJsonUtilO(Item, each_Item); output[L"Item"] = each_Item;
                return output;
            }
        };

        struct RevokeInventoryItemsResult : public PlayFabResultCommon
        {
            std::list<RevokeItemError> Errors;

            RevokeInventoryItemsResult() :
                PlayFabResultCommon(),
                Errors()
            {}

            RevokeInventoryItemsResult(const RevokeInventoryItemsResult& src) :
                PlayFabResultCommon(),
                Errors(src.Errors)
            {}

            ~RevokeInventoryItemsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Errors"], Errors);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Errors; ToJsonUtilO(Errors, each_Errors); output[L"Errors"] = each_Errors;
                return output;
            }
        };

        struct RevokeInventoryResult : public PlayFabResultCommon
        {

            RevokeInventoryResult() :
                PlayFabResultCommon()
            {}

            RevokeInventoryResult(const RevokeInventoryResult&) :
                PlayFabResultCommon()
            {}

            ~RevokeInventoryResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RunTaskRequest : public PlayFabRequestCommon
        {
            Boxed<NameIdentifier> Identifier;

            RunTaskRequest() :
                PlayFabRequestCommon(),
                Identifier()
            {}

            RunTaskRequest(const RunTaskRequest& src) :
                PlayFabRequestCommon(),
                Identifier(src.Identifier)
            {}

            ~RunTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Identifier"], Identifier);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output[L"Identifier"] = each_Identifier;
                return output;
            }
        };

        struct RunTaskResult : public PlayFabResultCommon
        {
            std::string TaskInstanceId;

            RunTaskResult() :
                PlayFabResultCommon(),
                TaskInstanceId()
            {}

            RunTaskResult(const RunTaskResult& src) :
                PlayFabResultCommon(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            ~RunTaskResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TaskInstanceId"], TaskInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[L"TaskInstanceId"] = each_TaskInstanceId;
                return output;
            }
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string EmailTemplateId;

            SendAccountRecoveryEmailRequest() :
                PlayFabRequestCommon(),
                Email(),
                EmailTemplateId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                EmailTemplateId(src.EmailTemplateId)
            {}

            ~SendAccountRecoveryEmailRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Email"], Email);
                FromJsonUtilS(input[L"EmailTemplateId"], EmailTemplateId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                web::json::value each_EmailTemplateId; ToJsonUtilS(EmailTemplateId, each_EmailTemplateId); output[L"EmailTemplateId"] = each_EmailTemplateId;
                return output;
            }
        };

        struct SendAccountRecoveryEmailResult : public PlayFabResultCommon
        {

            SendAccountRecoveryEmailResult() :
                PlayFabResultCommon()
            {}

            SendAccountRecoveryEmailResult(const SendAccountRecoveryEmailResult&) :
                PlayFabResultCommon()
            {}

            ~SendAccountRecoveryEmailResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetPlayerSecretRequest : public PlayFabRequestCommon
        {
            std::string PlayerSecret;
            std::string PlayFabId;

            SetPlayerSecretRequest() :
                PlayFabRequestCommon(),
                PlayerSecret(),
                PlayFabId()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabRequestCommon(),
                PlayerSecret(src.PlayerSecret),
                PlayFabId(src.PlayFabId)
            {}

            ~SetPlayerSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct SetPlayerSecretResult : public PlayFabResultCommon
        {

            SetPlayerSecretResult() :
                PlayFabResultCommon()
            {}

            SetPlayerSecretResult(const SetPlayerSecretResult&) :
                PlayFabResultCommon()
            {}

            ~SetPlayerSecretResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetPublishedRevisionRequest : public PlayFabRequestCommon
        {
            Int32 Revision;
            Int32 Version;

            SetPublishedRevisionRequest() :
                PlayFabRequestCommon(),
                Revision(),
                Version()
            {}

            SetPublishedRevisionRequest(const SetPublishedRevisionRequest& src) :
                PlayFabRequestCommon(),
                Revision(src.Revision),
                Version(src.Version)
            {}

            ~SetPublishedRevisionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Revision"], Revision);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[L"Revision"] = each_Revision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct SetPublishedRevisionResult : public PlayFabResultCommon
        {

            SetPublishedRevisionResult() :
                PlayFabResultCommon()
            {}

            SetPublishedRevisionResult(const SetPublishedRevisionResult&) :
                PlayFabResultCommon()
            {}

            ~SetPublishedRevisionResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetPublisherDataRequest : public PlayFabRequestCommon
        {
            std::string Key;
            std::string Value;

            SetPublisherDataRequest() :
                PlayFabRequestCommon(),
                Key(),
                Value()
            {}

            SetPublisherDataRequest(const SetPublisherDataRequest& src) :
                PlayFabRequestCommon(),
                Key(src.Key),
                Value(src.Value)
            {}

            ~SetPublisherDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Key"], Key);
                FromJsonUtilS(input[L"Value"], Value);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[L"Key"] = each_Key;
                web::json::value each_Value; ToJsonUtilS(Value, each_Value); output[L"Value"] = each_Value;
                return output;
            }
        };

        struct SetPublisherDataResult : public PlayFabResultCommon
        {

            SetPublisherDataResult() :
                PlayFabResultCommon()
            {}

            SetPublisherDataResult(const SetPublisherDataResult&) :
                PlayFabResultCommon()
            {}

            ~SetPublisherDataResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetTitleDataRequest : public PlayFabRequestCommon
        {
            std::string Key;
            std::string Value;

            SetTitleDataRequest() :
                PlayFabRequestCommon(),
                Key(),
                Value()
            {}

            SetTitleDataRequest(const SetTitleDataRequest& src) :
                PlayFabRequestCommon(),
                Key(src.Key),
                Value(src.Value)
            {}

            ~SetTitleDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Key"], Key);
                FromJsonUtilS(input[L"Value"], Value);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[L"Key"] = each_Key;
                web::json::value each_Value; ToJsonUtilS(Value, each_Value); output[L"Value"] = each_Value;
                return output;
            }
        };

        struct SetTitleDataResult : public PlayFabResultCommon
        {

            SetTitleDataResult() :
                PlayFabResultCommon()
            {}

            SetTitleDataResult(const SetTitleDataResult&) :
                PlayFabResultCommon()
            {}

            ~SetTitleDataResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetupPushNotificationRequest : public PlayFabRequestCommon
        {
            std::string Credential;
            std::string Key;
            std::string Name;
            bool OverwriteOldARN;
            PushSetupPlatform Platform;

            SetupPushNotificationRequest() :
                PlayFabRequestCommon(),
                Credential(),
                Key(),
                Name(),
                OverwriteOldARN(),
                Platform()
            {}

            SetupPushNotificationRequest(const SetupPushNotificationRequest& src) :
                PlayFabRequestCommon(),
                Credential(src.Credential),
                Key(src.Key),
                Name(src.Name),
                OverwriteOldARN(src.OverwriteOldARN),
                Platform(src.Platform)
            {}

            ~SetupPushNotificationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Credential"], Credential);
                FromJsonUtilS(input[L"Key"], Key);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilP(input[L"OverwriteOldARN"], OverwriteOldARN);
                FromJsonEnum(input[L"Platform"], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Credential; ToJsonUtilS(Credential, each_Credential); output[L"Credential"] = each_Credential;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[L"Key"] = each_Key;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_OverwriteOldARN; ToJsonUtilP(OverwriteOldARN, each_OverwriteOldARN); output[L"OverwriteOldARN"] = each_OverwriteOldARN;
                web::json::value each_Platform; ToJsonEnum(Platform, each_Platform); output[L"Platform"] = each_Platform;
                return output;
            }
        };

        struct SetupPushNotificationResult : public PlayFabResultCommon
        {
            std::string ARN;

            SetupPushNotificationResult() :
                PlayFabResultCommon(),
                ARN()
            {}

            SetupPushNotificationResult(const SetupPushNotificationResult& src) :
                PlayFabResultCommon(),
                ARN(src.ARN)
            {}

            ~SetupPushNotificationResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ARN"], ARN);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ARN; ToJsonUtilS(ARN, each_ARN); output[L"ARN"] = each_ARN;
                return output;
            }
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string PlayFabId;
            std::string VirtualCurrency;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                PlayFabId(),
                VirtualCurrency()
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~SubtractUserVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Amount"], Amount);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"VirtualCurrency"], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[L"Amount"] = each_Amount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct UpdateBanRequest : public PlayFabRequestCommon
        {
            Boxed<bool> Active;
            std::string BanId;
            Boxed<time_t> Expires;
            std::string IPAddress;
            std::string MACAddress;
            Boxed<bool> Permanent;
            std::string Reason;

            UpdateBanRequest() :
                PlayFabRequestCommon(),
                Active(),
                BanId(),
                Expires(),
                IPAddress(),
                MACAddress(),
                Permanent(),
                Reason()
            {}

            UpdateBanRequest(const UpdateBanRequest& src) :
                PlayFabRequestCommon(),
                Active(src.Active),
                BanId(src.BanId),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Permanent(src.Permanent),
                Reason(src.Reason)
            {}

            ~UpdateBanRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Active"], Active);
                FromJsonUtilS(input[L"BanId"], BanId);
                FromJsonUtilT(input[L"Expires"], Expires);
                FromJsonUtilS(input[L"IPAddress"], IPAddress);
                FromJsonUtilS(input[L"MACAddress"], MACAddress);
                FromJsonUtilP(input[L"Permanent"], Permanent);
                FromJsonUtilS(input[L"Reason"], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Active; ToJsonUtilP(Active, each_Active); output[L"Active"] = each_Active;
                web::json::value each_BanId; ToJsonUtilS(BanId, each_BanId); output[L"BanId"] = each_BanId;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[L"Expires"] = each_Expires;
                web::json::value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output[L"IPAddress"] = each_IPAddress;
                web::json::value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output[L"MACAddress"] = each_MACAddress;
                web::json::value each_Permanent; ToJsonUtilP(Permanent, each_Permanent); output[L"Permanent"] = each_Permanent;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[L"Reason"] = each_Reason;
                return output;
            }
        };

        struct UpdateBansRequest : public PlayFabRequestCommon
        {
            std::list<UpdateBanRequest> Bans;

            UpdateBansRequest() :
                PlayFabRequestCommon(),
                Bans()
            {}

            UpdateBansRequest(const UpdateBansRequest& src) :
                PlayFabRequestCommon(),
                Bans(src.Bans)
            {}

            ~UpdateBansRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Bans"], Bans);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Bans; ToJsonUtilO(Bans, each_Bans); output[L"Bans"] = each_Bans;
                return output;
            }
        };

        struct UpdateBansResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            UpdateBansResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            UpdateBansResult(const UpdateBansResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~UpdateBansResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"BanData"], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[L"BanData"] = each_BanData;
                return output;
            }
        };

        struct UpdateCatalogItemsRequest : public PlayFabRequestCommon
        {
            std::list<CatalogItem> Catalog;
            std::string CatalogVersion;
            Boxed<bool> SetAsDefaultCatalog;

            UpdateCatalogItemsRequest() :
                PlayFabRequestCommon(),
                Catalog(),
                CatalogVersion(),
                SetAsDefaultCatalog()
            {}

            UpdateCatalogItemsRequest(const UpdateCatalogItemsRequest& src) :
                PlayFabRequestCommon(),
                Catalog(src.Catalog),
                CatalogVersion(src.CatalogVersion),
                SetAsDefaultCatalog(src.SetAsDefaultCatalog)
            {}

            ~UpdateCatalogItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Catalog"], Catalog);
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilP(input[L"SetAsDefaultCatalog"], SetAsDefaultCatalog);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Catalog; ToJsonUtilO(Catalog, each_Catalog); output[L"Catalog"] = each_Catalog;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_SetAsDefaultCatalog; ToJsonUtilP(SetAsDefaultCatalog, each_SetAsDefaultCatalog); output[L"SetAsDefaultCatalog"] = each_SetAsDefaultCatalog;
                return output;
            }
        };

        struct UpdateCatalogItemsResult : public PlayFabResultCommon
        {

            UpdateCatalogItemsResult() :
                PlayFabResultCommon()
            {}

            UpdateCatalogItemsResult(const UpdateCatalogItemsResult&) :
                PlayFabResultCommon()
            {}

            ~UpdateCatalogItemsResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateCloudScriptRequest : public PlayFabRequestCommon
        {
            std::string DeveloperPlayFabId;
            std::list<CloudScriptFile> Files;
            bool Publish;

            UpdateCloudScriptRequest() :
                PlayFabRequestCommon(),
                DeveloperPlayFabId(),
                Files(),
                Publish()
            {}

            UpdateCloudScriptRequest(const UpdateCloudScriptRequest& src) :
                PlayFabRequestCommon(),
                DeveloperPlayFabId(src.DeveloperPlayFabId),
                Files(src.Files),
                Publish(src.Publish)
            {}

            ~UpdateCloudScriptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DeveloperPlayFabId"], DeveloperPlayFabId);
                FromJsonUtilO(input[L"Files"], Files);
                FromJsonUtilP(input[L"Publish"], Publish);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeveloperPlayFabId; ToJsonUtilS(DeveloperPlayFabId, each_DeveloperPlayFabId); output[L"DeveloperPlayFabId"] = each_DeveloperPlayFabId;
                web::json::value each_Files; ToJsonUtilO(Files, each_Files); output[L"Files"] = each_Files;
                web::json::value each_Publish; ToJsonUtilP(Publish, each_Publish); output[L"Publish"] = each_Publish;
                return output;
            }
        };

        struct UpdateCloudScriptResult : public PlayFabResultCommon
        {
            Int32 Revision;
            Int32 Version;

            UpdateCloudScriptResult() :
                PlayFabResultCommon(),
                Revision(),
                Version()
            {}

            UpdateCloudScriptResult(const UpdateCloudScriptResult& src) :
                PlayFabResultCommon(),
                Revision(src.Revision),
                Version(src.Version)
            {}

            ~UpdateCloudScriptResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Revision"], Revision);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[L"Revision"] = each_Revision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct UpdatePlayerSharedSecretRequest : public PlayFabRequestCommon
        {
            bool Disabled;
            std::string FriendlyName;
            std::string SecretKey;

            UpdatePlayerSharedSecretRequest() :
                PlayFabRequestCommon(),
                Disabled(),
                FriendlyName(),
                SecretKey()
            {}

            UpdatePlayerSharedSecretRequest(const UpdatePlayerSharedSecretRequest& src) :
                PlayFabRequestCommon(),
                Disabled(src.Disabled),
                FriendlyName(src.FriendlyName),
                SecretKey(src.SecretKey)
            {}

            ~UpdatePlayerSharedSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Disabled"], Disabled);
                FromJsonUtilS(input[L"FriendlyName"], FriendlyName);
                FromJsonUtilS(input[L"SecretKey"], SecretKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Disabled; ToJsonUtilP(Disabled, each_Disabled); output[L"Disabled"] = each_Disabled;
                web::json::value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output[L"FriendlyName"] = each_FriendlyName;
                web::json::value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output[L"SecretKey"] = each_SecretKey;
                return output;
            }
        };

        struct UpdatePlayerSharedSecretResult : public PlayFabResultCommon
        {

            UpdatePlayerSharedSecretResult() :
                PlayFabResultCommon()
            {}

            UpdatePlayerSharedSecretResult(const UpdatePlayerSharedSecretResult&) :
                PlayFabResultCommon()
            {}

            ~UpdatePlayerSharedSecretResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdatePlayerStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            UpdatePlayerStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                AggregationMethod(),
                StatisticName(),
                VersionChangeInterval()
            {}

            UpdatePlayerStatisticDefinitionRequest(const UpdatePlayerStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                AggregationMethod(src.AggregationMethod),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            ~UpdatePlayerStatisticDefinitionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"AggregationMethod"], AggregationMethod);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilE(input[L"VersionChangeInterval"], VersionChangeInterval);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output[L"AggregationMethod"] = each_AggregationMethod;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output[L"VersionChangeInterval"] = each_VersionChangeInterval;
                return output;
            }
        };

        struct UpdatePlayerStatisticDefinitionResult : public PlayFabResultCommon
        {
            Boxed<PlayerStatisticDefinition> Statistic;

            UpdatePlayerStatisticDefinitionResult() :
                PlayFabResultCommon(),
                Statistic()
            {}

            UpdatePlayerStatisticDefinitionResult(const UpdatePlayerStatisticDefinitionResult& src) :
                PlayFabResultCommon(),
                Statistic(src.Statistic)
            {}

            ~UpdatePlayerStatisticDefinitionResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Statistic"], Statistic);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Statistic; ToJsonUtilO(Statistic, each_Statistic); output[L"Statistic"] = each_Statistic;
                return output;
            }
        };

        struct UpdatePolicyRequest : public PlayFabRequestCommon
        {
            bool OverwritePolicy;
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            UpdatePolicyRequest() :
                PlayFabRequestCommon(),
                OverwritePolicy(),
                PolicyName(),
                Statements()
            {}

            UpdatePolicyRequest(const UpdatePolicyRequest& src) :
                PlayFabRequestCommon(),
                OverwritePolicy(src.OverwritePolicy),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            ~UpdatePolicyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"OverwritePolicy"], OverwritePolicy);
                FromJsonUtilS(input[L"PolicyName"], PolicyName);
                FromJsonUtilO(input[L"Statements"], Statements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OverwritePolicy; ToJsonUtilP(OverwritePolicy, each_OverwritePolicy); output[L"OverwritePolicy"] = each_OverwritePolicy;
                web::json::value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output[L"PolicyName"] = each_PolicyName;
                web::json::value each_Statements; ToJsonUtilO(Statements, each_Statements); output[L"Statements"] = each_Statements;
                return output;
            }
        };

        struct UpdatePolicyResponse : public PlayFabResultCommon
        {
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            UpdatePolicyResponse() :
                PlayFabResultCommon(),
                PolicyName(),
                Statements()
            {}

            UpdatePolicyResponse(const UpdatePolicyResponse& src) :
                PlayFabResultCommon(),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            ~UpdatePolicyResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PolicyName"], PolicyName);
                FromJsonUtilO(input[L"Statements"], Statements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output[L"PolicyName"] = each_PolicyName;
                web::json::value each_Statements; ToJsonUtilO(Statements, each_Statements); output[L"Statements"] = each_Statements;
                return output;
            }
        };

        struct UpdateRandomResultTablesRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::list<RandomResultTable> Tables;

            UpdateRandomResultTablesRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                Tables()
            {}

            UpdateRandomResultTablesRequest(const UpdateRandomResultTablesRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                Tables(src.Tables)
            {}

            ~UpdateRandomResultTablesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input[L"Tables"], Tables);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_Tables; ToJsonUtilO(Tables, each_Tables); output[L"Tables"] = each_Tables;
                return output;
            }
        };

        struct UpdateRandomResultTablesResult : public PlayFabResultCommon
        {

            UpdateRandomResultTablesResult() :
                PlayFabResultCommon()
            {}

            UpdateRandomResultTablesResult(const UpdateRandomResultTablesResult&) :
                PlayFabResultCommon()
            {}

            ~UpdateRandomResultTablesResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateStoreItemsRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            Boxed<StoreMarketingModel> MarketingData;
            std::list<StoreItem> Store;
            std::string StoreId;

            UpdateStoreItemsRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                MarketingData(),
                Store(),
                StoreId()
            {}

            UpdateStoreItemsRequest(const UpdateStoreItemsRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                MarketingData(src.MarketingData),
                Store(src.Store),
                StoreId(src.StoreId)
            {}

            ~UpdateStoreItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input[L"MarketingData"], MarketingData);
                FromJsonUtilO(input[L"Store"], Store);
                FromJsonUtilS(input[L"StoreId"], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_MarketingData; ToJsonUtilO(MarketingData, each_MarketingData); output[L"MarketingData"] = each_MarketingData;
                web::json::value each_Store; ToJsonUtilO(Store, each_Store); output[L"Store"] = each_Store;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[L"StoreId"] = each_StoreId;
                return output;
            }
        };

        struct UpdateStoreItemsResult : public PlayFabResultCommon
        {

            UpdateStoreItemsResult() :
                PlayFabResultCommon()
            {}

            UpdateStoreItemsResult(const UpdateStoreItemsResult&) :
                PlayFabResultCommon()
            {}

            ~UpdateStoreItemsResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateTaskRequest : public PlayFabRequestCommon
        {
            std::string Description;
            Boxed<NameIdentifier> Identifier;
            bool IsActive;
            std::string Name;
            web::json::value Parameter;
            std::string Schedule;
            ScheduledTaskType Type;

            UpdateTaskRequest() :
                PlayFabRequestCommon(),
                Description(),
                Identifier(),
                IsActive(),
                Name(),
                Parameter(),
                Schedule(),
                Type()
            {}

            UpdateTaskRequest(const UpdateTaskRequest& src) :
                PlayFabRequestCommon(),
                Description(src.Description),
                Identifier(src.Identifier),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule),
                Type(src.Type)
            {}

            ~UpdateTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Description"], Description);
                FromJsonUtilO(input[L"Identifier"], Identifier);
                FromJsonUtilP(input[L"IsActive"], IsActive);
                FromJsonUtilS(input[L"Name"], Name);
                Parameter = input[L"Parameter"];
                FromJsonUtilS(input[L"Schedule"], Schedule);
                FromJsonEnum(input[L"Type"], Type);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[L"Description"] = each_Description;
                web::json::value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output[L"Identifier"] = each_Identifier;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[L"IsActive"] = each_IsActive;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                output[L"Parameter"] = Parameter;
                web::json::value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output[L"Schedule"] = each_Schedule;
                web::json::value each_Type; ToJsonEnum(Type, each_Type); output[L"Type"] = each_Type;
                return output;
            }
        };

        struct UpdateUserDataRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string PlayFabId;

            UpdateUserDataRequest() :
                PlayFabRequestCommon(),
                Data(),
                KeysToRemove(),
                Permission(),
                PlayFabId()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabRequestCommon(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateUserDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Data"], Data);
                FromJsonUtilS(input[L"KeysToRemove"], KeysToRemove);
                FromJsonUtilE(input[L"Permission"], Permission);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[L"KeysToRemove"] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[L"Permission"] = each_Permission;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct UpdateUserDataResult : public PlayFabResultCommon
        {
            Uint32 DataVersion;

            UpdateUserDataResult() :
                PlayFabResultCommon(),
                DataVersion()
            {}

            UpdateUserDataResult(const UpdateUserDataResult& src) :
                PlayFabResultCommon(),
                DataVersion(src.DataVersion)
            {}

            ~UpdateUserDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"DataVersion"], DataVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[L"DataVersion"] = each_DataVersion;
                return output;
            }
        };

        struct UpdateUserInternalDataRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            UpdateUserInternalDataRequest() :
                PlayFabRequestCommon(),
                Data(),
                KeysToRemove(),
                PlayFabId()
            {}

            UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
                PlayFabRequestCommon(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateUserInternalDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Data"], Data);
                FromJsonUtilS(input[L"KeysToRemove"], KeysToRemove);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[L"KeysToRemove"] = each_KeysToRemove;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct UpdateUserTitleDisplayNameRequest : public PlayFabRequestCommon
        {
            std::string DisplayName;
            std::string PlayFabId;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabRequestCommon(),
                DisplayName(),
                PlayFabId()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabRequestCommon(),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateUserTitleDisplayNameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct UpdateUserTitleDisplayNameResult : public PlayFabResultCommon
        {
            std::string DisplayName;

            UpdateUserTitleDisplayNameResult() :
                PlayFabResultCommon(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameResult(const UpdateUserTitleDisplayNameResult& src) :
                PlayFabResultCommon(),
                DisplayName(src.DisplayName)
            {}

            ~UpdateUserTitleDisplayNameResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                return output;
            }
        };

    }
}

#endif
