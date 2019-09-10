#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ClientModels
    {
        // Client Enums
        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        inline void ToJsonEnum(const CloudScriptRevisionOption input, web::json::value& output)
        {
            if (input == CloudScriptRevisionOptionLive) output = web::json::value(L"Live");
            if (input == CloudScriptRevisionOptionLatest) output = web::json::value(L"Latest");
            if (input == CloudScriptRevisionOptionSpecific) output = web::json::value(L"Specific");
        }
        inline void FromJsonEnum(const web::json::value& input, CloudScriptRevisionOption& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Live") output = CloudScriptRevisionOptionLive;
            if (inputStr == L"Latest") output = CloudScriptRevisionOptionLatest;
            if (inputStr == L"Specific") output = CloudScriptRevisionOptionSpecific;
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

        enum GameInstanceState
        {
            GameInstanceStateOpen,
            GameInstanceStateClosed
        };

        inline void ToJsonEnum(const GameInstanceState input, web::json::value& output)
        {
            if (input == GameInstanceStateOpen) output = web::json::value(L"Open");
            if (input == GameInstanceStateClosed) output = web::json::value(L"Closed");
        }
        inline void FromJsonEnum(const web::json::value& input, GameInstanceState& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Open") output = GameInstanceStateOpen;
            if (inputStr == L"Closed") output = GameInstanceStateClosed;
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

        enum MatchmakeStatus
        {
            MatchmakeStatusComplete,
            MatchmakeStatusWaiting,
            MatchmakeStatusGameNotFound,
            MatchmakeStatusNoAvailableSlots,
            MatchmakeStatusSessionClosed
        };

        inline void ToJsonEnum(const MatchmakeStatus input, web::json::value& output)
        {
            if (input == MatchmakeStatusComplete) output = web::json::value(L"Complete");
            if (input == MatchmakeStatusWaiting) output = web::json::value(L"Waiting");
            if (input == MatchmakeStatusGameNotFound) output = web::json::value(L"GameNotFound");
            if (input == MatchmakeStatusNoAvailableSlots) output = web::json::value(L"NoAvailableSlots");
            if (input == MatchmakeStatusSessionClosed) output = web::json::value(L"SessionClosed");
        }
        inline void FromJsonEnum(const web::json::value& input, MatchmakeStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Complete") output = MatchmakeStatusComplete;
            if (inputStr == L"Waiting") output = MatchmakeStatusWaiting;
            if (inputStr == L"GameNotFound") output = MatchmakeStatusGameNotFound;
            if (inputStr == L"NoAvailableSlots") output = MatchmakeStatusNoAvailableSlots;
            if (inputStr == L"SessionClosed") output = MatchmakeStatusSessionClosed;
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

        enum TradeStatus
        {
            TradeStatusInvalid,
            TradeStatusOpening,
            TradeStatusOpen,
            TradeStatusAccepting,
            TradeStatusAccepted,
            TradeStatusFilled,
            TradeStatusCancelled
        };

        inline void ToJsonEnum(const TradeStatus input, web::json::value& output)
        {
            if (input == TradeStatusInvalid) output = web::json::value(L"Invalid");
            if (input == TradeStatusOpening) output = web::json::value(L"Opening");
            if (input == TradeStatusOpen) output = web::json::value(L"Open");
            if (input == TradeStatusAccepting) output = web::json::value(L"Accepting");
            if (input == TradeStatusAccepted) output = web::json::value(L"Accepted");
            if (input == TradeStatusFilled) output = web::json::value(L"Filled");
            if (input == TradeStatusCancelled) output = web::json::value(L"Cancelled");
        }
        inline void FromJsonEnum(const web::json::value& input, TradeStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Invalid") output = TradeStatusInvalid;
            if (inputStr == L"Opening") output = TradeStatusOpening;
            if (inputStr == L"Open") output = TradeStatusOpen;
            if (inputStr == L"Accepting") output = TradeStatusAccepting;
            if (inputStr == L"Accepted") output = TradeStatusAccepted;
            if (inputStr == L"Filled") output = TradeStatusFilled;
            if (inputStr == L"Cancelled") output = TradeStatusCancelled;
        }

        enum TransactionStatus
        {
            TransactionStatusCreateCart,
            TransactionStatusInit,
            TransactionStatusApproved,
            TransactionStatusSucceeded,
            TransactionStatusFailedByProvider,
            TransactionStatusDisputePending,
            TransactionStatusRefundPending,
            TransactionStatusRefunded,
            TransactionStatusRefundFailed,
            TransactionStatusChargedBack,
            TransactionStatusFailedByUber,
            TransactionStatusFailedByPlayFab,
            TransactionStatusRevoked,
            TransactionStatusTradePending,
            TransactionStatusTraded,
            TransactionStatusUpgraded,
            TransactionStatusStackPending,
            TransactionStatusStacked,
            TransactionStatusOther,
            TransactionStatusFailed
        };

        inline void ToJsonEnum(const TransactionStatus input, web::json::value& output)
        {
            if (input == TransactionStatusCreateCart) output = web::json::value(L"CreateCart");
            if (input == TransactionStatusInit) output = web::json::value(L"Init");
            if (input == TransactionStatusApproved) output = web::json::value(L"Approved");
            if (input == TransactionStatusSucceeded) output = web::json::value(L"Succeeded");
            if (input == TransactionStatusFailedByProvider) output = web::json::value(L"FailedByProvider");
            if (input == TransactionStatusDisputePending) output = web::json::value(L"DisputePending");
            if (input == TransactionStatusRefundPending) output = web::json::value(L"RefundPending");
            if (input == TransactionStatusRefunded) output = web::json::value(L"Refunded");
            if (input == TransactionStatusRefundFailed) output = web::json::value(L"RefundFailed");
            if (input == TransactionStatusChargedBack) output = web::json::value(L"ChargedBack");
            if (input == TransactionStatusFailedByUber) output = web::json::value(L"FailedByUber");
            if (input == TransactionStatusFailedByPlayFab) output = web::json::value(L"FailedByPlayFab");
            if (input == TransactionStatusRevoked) output = web::json::value(L"Revoked");
            if (input == TransactionStatusTradePending) output = web::json::value(L"TradePending");
            if (input == TransactionStatusTraded) output = web::json::value(L"Traded");
            if (input == TransactionStatusUpgraded) output = web::json::value(L"Upgraded");
            if (input == TransactionStatusStackPending) output = web::json::value(L"StackPending");
            if (input == TransactionStatusStacked) output = web::json::value(L"Stacked");
            if (input == TransactionStatusOther) output = web::json::value(L"Other");
            if (input == TransactionStatusFailed) output = web::json::value(L"Failed");
        }
        inline void FromJsonEnum(const web::json::value& input, TransactionStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"CreateCart") output = TransactionStatusCreateCart;
            if (inputStr == L"Init") output = TransactionStatusInit;
            if (inputStr == L"Approved") output = TransactionStatusApproved;
            if (inputStr == L"Succeeded") output = TransactionStatusSucceeded;
            if (inputStr == L"FailedByProvider") output = TransactionStatusFailedByProvider;
            if (inputStr == L"DisputePending") output = TransactionStatusDisputePending;
            if (inputStr == L"RefundPending") output = TransactionStatusRefundPending;
            if (inputStr == L"Refunded") output = TransactionStatusRefunded;
            if (inputStr == L"RefundFailed") output = TransactionStatusRefundFailed;
            if (inputStr == L"ChargedBack") output = TransactionStatusChargedBack;
            if (inputStr == L"FailedByUber") output = TransactionStatusFailedByUber;
            if (inputStr == L"FailedByPlayFab") output = TransactionStatusFailedByPlayFab;
            if (inputStr == L"Revoked") output = TransactionStatusRevoked;
            if (inputStr == L"TradePending") output = TransactionStatusTradePending;
            if (inputStr == L"Traded") output = TransactionStatusTraded;
            if (inputStr == L"Upgraded") output = TransactionStatusUpgraded;
            if (inputStr == L"StackPending") output = TransactionStatusStackPending;
            if (inputStr == L"Stacked") output = TransactionStatusStacked;
            if (inputStr == L"Other") output = TransactionStatusOther;
            if (inputStr == L"Failed") output = TransactionStatusFailed;
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

        // Client Classes
        struct AcceptTradeRequest : public PlayFabRequestCommon
        {
            std::list<std::string> AcceptedInventoryInstanceIds;
            std::string OfferingPlayerId;
            std::string TradeId;

            AcceptTradeRequest() :
                PlayFabRequestCommon(),
                AcceptedInventoryInstanceIds(),
                OfferingPlayerId(),
                TradeId()
            {}

            AcceptTradeRequest(const AcceptTradeRequest& src) :
                PlayFabRequestCommon(),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
            {}

            ~AcceptTradeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AcceptedInventoryInstanceIds"], AcceptedInventoryInstanceIds);
                FromJsonUtilS(input[L"OfferingPlayerId"], OfferingPlayerId);
                FromJsonUtilS(input[L"TradeId"], TradeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AcceptedInventoryInstanceIds; ToJsonUtilS(AcceptedInventoryInstanceIds, each_AcceptedInventoryInstanceIds); output[L"AcceptedInventoryInstanceIds"] = each_AcceptedInventoryInstanceIds;
                web::json::value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output[L"OfferingPlayerId"] = each_OfferingPlayerId;
                web::json::value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output[L"TradeId"] = each_TradeId;
                return output;
            }
        };

        struct TradeInfo : public PlayFabBaseModel
        {
            std::list<std::string> AcceptedInventoryInstanceIds;
            std::string AcceptedPlayerId;
            std::list<std::string> AllowedPlayerIds;
            Boxed<time_t> CancelledAt;
            Boxed<time_t> FilledAt;
            Boxed<time_t> InvalidatedAt;
            std::list<std::string> OfferedCatalogItemIds;
            std::list<std::string> OfferedInventoryInstanceIds;
            std::string OfferingPlayerId;
            Boxed<time_t> OpenedAt;
            std::list<std::string> RequestedCatalogItemIds;
            Boxed<TradeStatus> Status;
            std::string TradeId;

            TradeInfo() :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(),
                AcceptedPlayerId(),
                AllowedPlayerIds(),
                CancelledAt(),
                FilledAt(),
                InvalidatedAt(),
                OfferedCatalogItemIds(),
                OfferedInventoryInstanceIds(),
                OfferingPlayerId(),
                OpenedAt(),
                RequestedCatalogItemIds(),
                Status(),
                TradeId()
            {}

            TradeInfo(const TradeInfo& src) :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                AcceptedPlayerId(src.AcceptedPlayerId),
                AllowedPlayerIds(src.AllowedPlayerIds),
                CancelledAt(src.CancelledAt),
                FilledAt(src.FilledAt),
                InvalidatedAt(src.InvalidatedAt),
                OfferedCatalogItemIds(src.OfferedCatalogItemIds),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                OfferingPlayerId(src.OfferingPlayerId),
                OpenedAt(src.OpenedAt),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds),
                Status(src.Status),
                TradeId(src.TradeId)
            {}

            ~TradeInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AcceptedInventoryInstanceIds"], AcceptedInventoryInstanceIds);
                FromJsonUtilS(input[L"AcceptedPlayerId"], AcceptedPlayerId);
                FromJsonUtilS(input[L"AllowedPlayerIds"], AllowedPlayerIds);
                FromJsonUtilT(input[L"CancelledAt"], CancelledAt);
                FromJsonUtilT(input[L"FilledAt"], FilledAt);
                FromJsonUtilT(input[L"InvalidatedAt"], InvalidatedAt);
                FromJsonUtilS(input[L"OfferedCatalogItemIds"], OfferedCatalogItemIds);
                FromJsonUtilS(input[L"OfferedInventoryInstanceIds"], OfferedInventoryInstanceIds);
                FromJsonUtilS(input[L"OfferingPlayerId"], OfferingPlayerId);
                FromJsonUtilT(input[L"OpenedAt"], OpenedAt);
                FromJsonUtilS(input[L"RequestedCatalogItemIds"], RequestedCatalogItemIds);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilS(input[L"TradeId"], TradeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AcceptedInventoryInstanceIds; ToJsonUtilS(AcceptedInventoryInstanceIds, each_AcceptedInventoryInstanceIds); output[L"AcceptedInventoryInstanceIds"] = each_AcceptedInventoryInstanceIds;
                web::json::value each_AcceptedPlayerId; ToJsonUtilS(AcceptedPlayerId, each_AcceptedPlayerId); output[L"AcceptedPlayerId"] = each_AcceptedPlayerId;
                web::json::value each_AllowedPlayerIds; ToJsonUtilS(AllowedPlayerIds, each_AllowedPlayerIds); output[L"AllowedPlayerIds"] = each_AllowedPlayerIds;
                web::json::value each_CancelledAt; ToJsonUtilT(CancelledAt, each_CancelledAt); output[L"CancelledAt"] = each_CancelledAt;
                web::json::value each_FilledAt; ToJsonUtilT(FilledAt, each_FilledAt); output[L"FilledAt"] = each_FilledAt;
                web::json::value each_InvalidatedAt; ToJsonUtilT(InvalidatedAt, each_InvalidatedAt); output[L"InvalidatedAt"] = each_InvalidatedAt;
                web::json::value each_OfferedCatalogItemIds; ToJsonUtilS(OfferedCatalogItemIds, each_OfferedCatalogItemIds); output[L"OfferedCatalogItemIds"] = each_OfferedCatalogItemIds;
                web::json::value each_OfferedInventoryInstanceIds; ToJsonUtilS(OfferedInventoryInstanceIds, each_OfferedInventoryInstanceIds); output[L"OfferedInventoryInstanceIds"] = each_OfferedInventoryInstanceIds;
                web::json::value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output[L"OfferingPlayerId"] = each_OfferingPlayerId;
                web::json::value each_OpenedAt; ToJsonUtilT(OpenedAt, each_OpenedAt); output[L"OpenedAt"] = each_OpenedAt;
                web::json::value each_RequestedCatalogItemIds; ToJsonUtilS(RequestedCatalogItemIds, each_RequestedCatalogItemIds); output[L"RequestedCatalogItemIds"] = each_RequestedCatalogItemIds;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output[L"TradeId"] = each_TradeId;
                return output;
            }
        };

        struct AcceptTradeResponse : public PlayFabResultCommon
        {
            Boxed<TradeInfo> Trade;

            AcceptTradeResponse() :
                PlayFabResultCommon(),
                Trade()
            {}

            AcceptTradeResponse(const AcceptTradeResponse& src) :
                PlayFabResultCommon(),
                Trade(src.Trade)
            {}

            ~AcceptTradeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Trade"], Trade);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Trade; ToJsonUtilO(Trade, each_Trade); output[L"Trade"] = each_Trade;
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

        struct AddFriendRequest : public PlayFabRequestCommon
        {
            std::string FriendEmail;
            std::string FriendPlayFabId;
            std::string FriendTitleDisplayName;
            std::string FriendUsername;

            AddFriendRequest() :
                PlayFabRequestCommon(),
                FriendEmail(),
                FriendPlayFabId(),
                FriendTitleDisplayName(),
                FriendUsername()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabRequestCommon(),
                FriendEmail(src.FriendEmail),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendTitleDisplayName(src.FriendTitleDisplayName),
                FriendUsername(src.FriendUsername)
            {}

            ~AddFriendRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FriendEmail"], FriendEmail);
                FromJsonUtilS(input[L"FriendPlayFabId"], FriendPlayFabId);
                FromJsonUtilS(input[L"FriendTitleDisplayName"], FriendTitleDisplayName);
                FromJsonUtilS(input[L"FriendUsername"], FriendUsername);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendEmail; ToJsonUtilS(FriendEmail, each_FriendEmail); output[L"FriendEmail"] = each_FriendEmail;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[L"FriendPlayFabId"] = each_FriendPlayFabId;
                web::json::value each_FriendTitleDisplayName; ToJsonUtilS(FriendTitleDisplayName, each_FriendTitleDisplayName); output[L"FriendTitleDisplayName"] = each_FriendTitleDisplayName;
                web::json::value each_FriendUsername; ToJsonUtilS(FriendUsername, each_FriendUsername); output[L"FriendUsername"] = each_FriendUsername;
                return output;
            }
        };

        struct AddFriendResult : public PlayFabResultCommon
        {
            bool Created;

            AddFriendResult() :
                PlayFabResultCommon(),
                Created()
            {}

            AddFriendResult(const AddFriendResult& src) :
                PlayFabResultCommon(),
                Created(src.Created)
            {}

            ~AddFriendResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Created"], Created);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Created; ToJsonUtilP(Created, each_Created); output[L"Created"] = each_Created;
                return output;
            }
        };

        struct GenericServiceId : public PlayFabBaseModel
        {
            std::string ServiceName;
            std::string UserId;

            GenericServiceId() :
                PlayFabBaseModel(),
                ServiceName(),
                UserId()
            {}

            GenericServiceId(const GenericServiceId& src) :
                PlayFabBaseModel(),
                ServiceName(src.ServiceName),
                UserId(src.UserId)
            {}

            ~GenericServiceId() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ServiceName"], ServiceName);
                FromJsonUtilS(input[L"UserId"], UserId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ServiceName; ToJsonUtilS(ServiceName, each_ServiceName); output[L"ServiceName"] = each_ServiceName;
                web::json::value each_UserId; ToJsonUtilS(UserId, each_UserId); output[L"UserId"] = each_UserId;
                return output;
            }
        };

        struct AddGenericIDRequest : public PlayFabRequestCommon
        {
            GenericServiceId GenericId;

            AddGenericIDRequest() :
                PlayFabRequestCommon(),
                GenericId()
            {}

            AddGenericIDRequest(const AddGenericIDRequest& src) :
                PlayFabRequestCommon(),
                GenericId(src.GenericId)
            {}

            ~AddGenericIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"GenericId"], GenericId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output[L"GenericId"] = each_GenericId;
                return output;
            }
        };

        struct AddGenericIDResult : public PlayFabResultCommon
        {

            AddGenericIDResult() :
                PlayFabResultCommon()
            {}

            AddGenericIDResult(const AddGenericIDResult&) :
                PlayFabResultCommon()
            {}

            ~AddGenericIDResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AddOrUpdateContactEmailRequest : public PlayFabRequestCommon
        {
            std::string EmailAddress;

            AddOrUpdateContactEmailRequest() :
                PlayFabRequestCommon(),
                EmailAddress()
            {}

            AddOrUpdateContactEmailRequest(const AddOrUpdateContactEmailRequest& src) :
                PlayFabRequestCommon(),
                EmailAddress(src.EmailAddress)
            {}

            ~AddOrUpdateContactEmailRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"EmailAddress"], EmailAddress);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EmailAddress; ToJsonUtilS(EmailAddress, each_EmailAddress); output[L"EmailAddress"] = each_EmailAddress;
                return output;
            }
        };

        struct AddOrUpdateContactEmailResult : public PlayFabResultCommon
        {

            AddOrUpdateContactEmailResult() :
                PlayFabResultCommon()
            {}

            AddOrUpdateContactEmailResult(const AddOrUpdateContactEmailResult&) :
                PlayFabResultCommon()
            {}

            ~AddOrUpdateContactEmailResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AddSharedGroupMembersRequest : public PlayFabRequestCommon
        {
            std::list<std::string> PlayFabIds;
            std::string SharedGroupId;

            AddSharedGroupMembersRequest() :
                PlayFabRequestCommon(),
                PlayFabIds(),
                SharedGroupId()
            {}

            AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
                PlayFabRequestCommon(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
            {}

            ~AddSharedGroupMembersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabIds"], PlayFabIds);
                FromJsonUtilS(input[L"SharedGroupId"], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabIds; ToJsonUtilS(PlayFabIds, each_PlayFabIds); output[L"PlayFabIds"] = each_PlayFabIds;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[L"SharedGroupId"] = each_SharedGroupId;
                return output;
            }
        };

        struct AddSharedGroupMembersResult : public PlayFabResultCommon
        {

            AddSharedGroupMembersResult() :
                PlayFabResultCommon()
            {}

            AddSharedGroupMembersResult(const AddSharedGroupMembersResult&) :
                PlayFabResultCommon()
            {}

            ~AddSharedGroupMembersResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AddUsernamePasswordRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string Password;
            std::string Username;

            AddUsernamePasswordRequest() :
                PlayFabRequestCommon(),
                Email(),
                Password(),
                Username()
            {}

            AddUsernamePasswordRequest(const AddUsernamePasswordRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                Password(src.Password),
                Username(src.Username)
            {}

            ~AddUsernamePasswordRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Email"], Email);
                FromJsonUtilS(input[L"Password"], Password);
                FromJsonUtilS(input[L"Username"], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[L"Password"] = each_Password;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                return output;
            }
        };

        struct AddUsernamePasswordResult : public PlayFabResultCommon
        {
            std::string Username;

            AddUsernamePasswordResult() :
                PlayFabResultCommon(),
                Username()
            {}

            AddUsernamePasswordResult(const AddUsernamePasswordResult& src) :
                PlayFabResultCommon(),
                Username(src.Username)
            {}

            ~AddUsernamePasswordResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Username"], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                return output;
            }
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string VirtualCurrency;

            AddUserVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                VirtualCurrency()
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~AddUserVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Amount"], Amount);
                FromJsonUtilS(input[L"VirtualCurrency"], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[L"Amount"] = each_Amount;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct AndroidDevicePushNotificationRegistrationRequest : public PlayFabRequestCommon
        {
            std::string ConfirmationMessage;
            std::string DeviceToken;
            Boxed<bool> SendPushNotificationConfirmation;

            AndroidDevicePushNotificationRegistrationRequest() :
                PlayFabRequestCommon(),
                ConfirmationMessage(),
                DeviceToken(),
                SendPushNotificationConfirmation()
            {}

            AndroidDevicePushNotificationRegistrationRequest(const AndroidDevicePushNotificationRegistrationRequest& src) :
                PlayFabRequestCommon(),
                ConfirmationMessage(src.ConfirmationMessage),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation)
            {}

            ~AndroidDevicePushNotificationRegistrationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ConfirmationMessage"], ConfirmationMessage);
                FromJsonUtilS(input[L"DeviceToken"], DeviceToken);
                FromJsonUtilP(input[L"SendPushNotificationConfirmation"], SendPushNotificationConfirmation);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ConfirmationMessage; ToJsonUtilS(ConfirmationMessage, each_ConfirmationMessage); output[L"ConfirmationMessage"] = each_ConfirmationMessage;
                web::json::value each_DeviceToken; ToJsonUtilS(DeviceToken, each_DeviceToken); output[L"DeviceToken"] = each_DeviceToken;
                web::json::value each_SendPushNotificationConfirmation; ToJsonUtilP(SendPushNotificationConfirmation, each_SendPushNotificationConfirmation); output[L"SendPushNotificationConfirmation"] = each_SendPushNotificationConfirmation;
                return output;
            }
        };

        struct AndroidDevicePushNotificationRegistrationResult : public PlayFabResultCommon
        {

            AndroidDevicePushNotificationRegistrationResult() :
                PlayFabResultCommon()
            {}

            AndroidDevicePushNotificationRegistrationResult(const AndroidDevicePushNotificationRegistrationResult&) :
                PlayFabResultCommon()
            {}

            ~AndroidDevicePushNotificationRegistrationResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AttributeInstallRequest : public PlayFabRequestCommon
        {
            std::string Adid;
            std::string Idfa;

            AttributeInstallRequest() :
                PlayFabRequestCommon(),
                Adid(),
                Idfa()
            {}

            AttributeInstallRequest(const AttributeInstallRequest& src) :
                PlayFabRequestCommon(),
                Adid(src.Adid),
                Idfa(src.Idfa)
            {}

            ~AttributeInstallRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Adid"], Adid);
                FromJsonUtilS(input[L"Idfa"], Idfa);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Adid; ToJsonUtilS(Adid, each_Adid); output[L"Adid"] = each_Adid;
                web::json::value each_Idfa; ToJsonUtilS(Idfa, each_Idfa); output[L"Idfa"] = each_Idfa;
                return output;
            }
        };

        struct AttributeInstallResult : public PlayFabResultCommon
        {

            AttributeInstallResult() :
                PlayFabResultCommon()
            {}

            AttributeInstallResult(const AttributeInstallResult&) :
                PlayFabResultCommon()
            {}

            ~AttributeInstallResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct CancelTradeRequest : public PlayFabRequestCommon
        {
            std::string TradeId;

            CancelTradeRequest() :
                PlayFabRequestCommon(),
                TradeId()
            {}

            CancelTradeRequest(const CancelTradeRequest& src) :
                PlayFabRequestCommon(),
                TradeId(src.TradeId)
            {}

            ~CancelTradeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TradeId"], TradeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output[L"TradeId"] = each_TradeId;
                return output;
            }
        };

        struct CancelTradeResponse : public PlayFabResultCommon
        {
            Boxed<TradeInfo> Trade;

            CancelTradeResponse() :
                PlayFabResultCommon(),
                Trade()
            {}

            CancelTradeResponse(const CancelTradeResponse& src) :
                PlayFabResultCommon(),
                Trade(src.Trade)
            {}

            ~CancelTradeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Trade"], Trade);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Trade; ToJsonUtilO(Trade, each_Trade); output[L"Trade"] = each_Trade;
                return output;
            }
        };

        struct CartItem : public PlayFabBaseModel
        {
            std::string Description;
            std::string DisplayName;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::map<std::string, Uint32> VCAmount;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            CartItem() :
                PlayFabBaseModel(),
                Description(),
                DisplayName(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                RealCurrencyPrices(),
                VCAmount(),
                VirtualCurrencyPrices()
            {}

            CartItem(const CartItem& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                DisplayName(src.DisplayName),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VCAmount(src.VCAmount),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            ~CartItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Description"], Description);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilS(input[L"ItemClass"], ItemClass);
                FromJsonUtilS(input[L"ItemId"], ItemId);
                FromJsonUtilS(input[L"ItemInstanceId"], ItemInstanceId);
                FromJsonUtilP(input[L"RealCurrencyPrices"], RealCurrencyPrices);
                FromJsonUtilP(input[L"VCAmount"], VCAmount);
                FromJsonUtilP(input[L"VirtualCurrencyPrices"], VirtualCurrencyPrices);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[L"Description"] = each_Description;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output[L"ItemClass"] = each_ItemClass;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[L"ItemInstanceId"] = each_ItemInstanceId;
                web::json::value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output[L"RealCurrencyPrices"] = each_RealCurrencyPrices;
                web::json::value each_VCAmount; ToJsonUtilP(VCAmount, each_VCAmount); output[L"VCAmount"] = each_VCAmount;
                web::json::value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output[L"VirtualCurrencyPrices"] = each_VirtualCurrencyPrices;
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

        struct CharacterInventory : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::list<ItemInstance> Inventory;

            CharacterInventory() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory()
            {}

            CharacterInventory(const CharacterInventory& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory)
            {}

            ~CharacterInventory() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilO(input[L"Inventory"], Inventory);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[L"Inventory"] = each_Inventory;
                return output;
            }
        };

        struct CharacterLeaderboardEntry : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string CharacterName;
            std::string CharacterType;
            std::string DisplayName;
            std::string PlayFabId;
            Int32 Position;
            Int32 StatValue;

            CharacterLeaderboardEntry() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType(),
                DisplayName(),
                PlayFabId(),
                Position(),
                StatValue()
            {}

            CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                StatValue(src.StatValue)
            {}

            ~CharacterLeaderboardEntry() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"CharacterName"], CharacterName);
                FromJsonUtilS(input[L"CharacterType"], CharacterType);
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilP(input[L"Position"], Position);
                FromJsonUtilP(input[L"StatValue"], StatValue);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output[L"CharacterName"] = each_CharacterName;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[L"CharacterType"] = each_CharacterType;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_Position; ToJsonUtilP(Position, each_Position); output[L"Position"] = each_Position;
                web::json::value each_StatValue; ToJsonUtilP(StatValue, each_StatValue); output[L"StatValue"] = each_StatValue;
                return output;
            }
        };

        struct CharacterResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::string CharacterName;
            std::string CharacterType;

            CharacterResult() :
                PlayFabResultCommon(),
                CharacterId(),
                CharacterName(),
                CharacterType()
            {}

            CharacterResult(const CharacterResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType)
            {}

            ~CharacterResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"CharacterName"], CharacterName);
                FromJsonUtilS(input[L"CharacterType"], CharacterType);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output[L"CharacterName"] = each_CharacterName;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[L"CharacterType"] = each_CharacterType;
                return output;
            }
        };

        struct Container_Dictionary_String_String : public PlayFabBaseModel
        {
            std::map<std::string, std::string> Data;

            Container_Dictionary_String_String() :
                PlayFabBaseModel(),
                Data()
            {}

            Container_Dictionary_String_String(const Container_Dictionary_String_String& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            ~Container_Dictionary_String_String() { }

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

        struct CollectionFilter : public PlayFabBaseModel
        {
            std::list<Container_Dictionary_String_String> Excludes;
            std::list<Container_Dictionary_String_String> Includes;

            CollectionFilter() :
                PlayFabBaseModel(),
                Excludes(),
                Includes()
            {}

            CollectionFilter(const CollectionFilter& src) :
                PlayFabBaseModel(),
                Excludes(src.Excludes),
                Includes(src.Includes)
            {}

            ~CollectionFilter() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Excludes"], Excludes);
                FromJsonUtilO(input[L"Includes"], Includes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Excludes; ToJsonUtilO(Excludes, each_Excludes); output[L"Excludes"] = each_Excludes;
                web::json::value each_Includes; ToJsonUtilO(Includes, each_Includes); output[L"Includes"] = each_Includes;
                return output;
            }
        };

        struct ConfirmPurchaseRequest : public PlayFabRequestCommon
        {
            std::string OrderId;

            ConfirmPurchaseRequest() :
                PlayFabRequestCommon(),
                OrderId()
            {}

            ConfirmPurchaseRequest(const ConfirmPurchaseRequest& src) :
                PlayFabRequestCommon(),
                OrderId(src.OrderId)
            {}

            ~ConfirmPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"OrderId"], OrderId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                return output;
            }
        };

        struct ConfirmPurchaseResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Items;
            std::string OrderId;
            time_t PurchaseDate;

            ConfirmPurchaseResult() :
                PlayFabResultCommon(),
                Items(),
                OrderId(),
                PurchaseDate()
            {}

            ConfirmPurchaseResult(const ConfirmPurchaseResult& src) :
                PlayFabResultCommon(),
                Items(src.Items),
                OrderId(src.OrderId),
                PurchaseDate(src.PurchaseDate)
            {}

            ~ConfirmPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Items"], Items);
                FromJsonUtilS(input[L"OrderId"], OrderId);
                FromJsonUtilT(input[L"PurchaseDate"], PurchaseDate);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Items; ToJsonUtilO(Items, each_Items); output[L"Items"] = each_Items;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                web::json::value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output[L"PurchaseDate"] = each_PurchaseDate;
                return output;
            }
        };

        struct ConsumeItemRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            Int32 ConsumeCount;
            std::string ItemInstanceId;

            ConsumeItemRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                ConsumeCount(),
                ItemInstanceId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                ConsumeCount(src.ConsumeCount),
                ItemInstanceId(src.ItemInstanceId)
            {}

            ~ConsumeItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilP(input[L"ConsumeCount"], ConsumeCount);
                FromJsonUtilS(input[L"ItemInstanceId"], ItemInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_ConsumeCount; ToJsonUtilP(ConsumeCount, each_ConsumeCount); output[L"ConsumeCount"] = each_ConsumeCount;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[L"ItemInstanceId"] = each_ItemInstanceId;
                return output;
            }
        };

        struct ConsumeItemResult : public PlayFabResultCommon
        {
            std::string ItemInstanceId;
            Int32 RemainingUses;

            ConsumeItemResult() :
                PlayFabResultCommon(),
                ItemInstanceId(),
                RemainingUses()
            {}

            ConsumeItemResult(const ConsumeItemResult& src) :
                PlayFabResultCommon(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ~ConsumeItemResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ItemInstanceId"], ItemInstanceId);
                FromJsonUtilP(input[L"RemainingUses"], RemainingUses);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[L"ItemInstanceId"] = each_ItemInstanceId;
                web::json::value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output[L"RemainingUses"] = each_RemainingUses;
                return output;
            }
        };

        struct ConsumeXboxEntitlementsRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string XboxToken;

            ConsumeXboxEntitlementsRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                XboxToken()
            {}

            ConsumeXboxEntitlementsRequest(const ConsumeXboxEntitlementsRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                XboxToken(src.XboxToken)
            {}

            ~ConsumeXboxEntitlementsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"XboxToken"], XboxToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output[L"XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct ConsumeXboxEntitlementsResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Items;

            ConsumeXboxEntitlementsResult() :
                PlayFabResultCommon(),
                Items()
            {}

            ConsumeXboxEntitlementsResult(const ConsumeXboxEntitlementsResult& src) :
                PlayFabResultCommon(),
                Items(src.Items)
            {}

            ~ConsumeXboxEntitlementsResult() { }

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

        struct CreateSharedGroupRequest : public PlayFabRequestCommon
        {
            std::string SharedGroupId;

            CreateSharedGroupRequest() :
                PlayFabRequestCommon(),
                SharedGroupId()
            {}

            CreateSharedGroupRequest(const CreateSharedGroupRequest& src) :
                PlayFabRequestCommon(),
                SharedGroupId(src.SharedGroupId)
            {}

            ~CreateSharedGroupRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"SharedGroupId"], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[L"SharedGroupId"] = each_SharedGroupId;
                return output;
            }
        };

        struct CreateSharedGroupResult : public PlayFabResultCommon
        {
            std::string SharedGroupId;

            CreateSharedGroupResult() :
                PlayFabResultCommon(),
                SharedGroupId()
            {}

            CreateSharedGroupResult(const CreateSharedGroupResult& src) :
                PlayFabResultCommon(),
                SharedGroupId(src.SharedGroupId)
            {}

            ~CreateSharedGroupResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"SharedGroupId"], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[L"SharedGroupId"] = each_SharedGroupId;
                return output;
            }
        };

        struct CurrentGamesRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::string GameMode;
            Boxed<Region> pfRegion;
            std::string StatisticName;
            Boxed<CollectionFilter> TagFilter;

            CurrentGamesRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                GameMode(),
                pfRegion(),
                StatisticName(),
                TagFilter()
            {}

            CurrentGamesRequest(const CurrentGamesRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter)
            {}

            ~CurrentGamesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildVersion"], BuildVersion);
                FromJsonUtilS(input[L"GameMode"], GameMode);
                FromJsonUtilE(input[L"pfRegion"], pfRegion);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilO(input[L"TagFilter"], TagFilter);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[L"BuildVersion"] = each_BuildVersion;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[L"GameMode"] = each_GameMode;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[L"Region"] = each_pfRegion;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_TagFilter; ToJsonUtilO(TagFilter, each_TagFilter); output[L"TagFilter"] = each_TagFilter;
                return output;
            }
        };

        struct GameInfo : public PlayFabBaseModel
        {
            std::string BuildVersion;
            std::string GameMode;
            std::string GameServerData;
            Boxed<GameInstanceState> GameServerStateEnum;
            Boxed<time_t> LastHeartbeat;
            std::string LobbyID;
            Boxed<Int32> MaxPlayers;
            std::list<std::string> PlayerUserIds;
            Boxed<Region> pfRegion;
            Uint32 RunTime;
            std::string ServerHostname;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            Boxed<Int32> ServerPort;
            std::string ServerPublicDNSName;
            std::string StatisticName;
            std::map<std::string, std::string> Tags;

            GameInfo() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameMode(),
                GameServerData(),
                GameServerStateEnum(),
                LastHeartbeat(),
                LobbyID(),
                MaxPlayers(),
                PlayerUserIds(),
                pfRegion(),
                RunTime(),
                ServerHostname(),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(),
                ServerPublicDNSName(),
                StatisticName(),
                Tags()
            {}

            GameInfo(const GameInfo& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                GameServerData(src.GameServerData),
                GameServerStateEnum(src.GameServerStateEnum),
                LastHeartbeat(src.LastHeartbeat),
                LobbyID(src.LobbyID),
                MaxPlayers(src.MaxPlayers),
                PlayerUserIds(src.PlayerUserIds),
                pfRegion(src.pfRegion),
                RunTime(src.RunTime),
                ServerHostname(src.ServerHostname),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                StatisticName(src.StatisticName),
                Tags(src.Tags)
            {}

            ~GameInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildVersion"], BuildVersion);
                FromJsonUtilS(input[L"GameMode"], GameMode);
                FromJsonUtilS(input[L"GameServerData"], GameServerData);
                FromJsonUtilE(input[L"GameServerStateEnum"], GameServerStateEnum);
                FromJsonUtilT(input[L"LastHeartbeat"], LastHeartbeat);
                FromJsonUtilS(input[L"LobbyID"], LobbyID);
                FromJsonUtilP(input[L"MaxPlayers"], MaxPlayers);
                FromJsonUtilS(input[L"PlayerUserIds"], PlayerUserIds);
                FromJsonUtilE(input[L"pfRegion"], pfRegion);
                FromJsonUtilP(input[L"RunTime"], RunTime);
                FromJsonUtilS(input[L"ServerHostname"], ServerHostname);
                FromJsonUtilS(input[L"ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input[L"ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input[L"ServerPort"], ServerPort);
                FromJsonUtilS(input[L"ServerPublicDNSName"], ServerPublicDNSName);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilS(input[L"Tags"], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[L"BuildVersion"] = each_BuildVersion;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[L"GameMode"] = each_GameMode;
                web::json::value each_GameServerData; ToJsonUtilS(GameServerData, each_GameServerData); output[L"GameServerData"] = each_GameServerData;
                web::json::value each_GameServerStateEnum; ToJsonUtilE(GameServerStateEnum, each_GameServerStateEnum); output[L"GameServerStateEnum"] = each_GameServerStateEnum;
                web::json::value each_LastHeartbeat; ToJsonUtilT(LastHeartbeat, each_LastHeartbeat); output[L"LastHeartbeat"] = each_LastHeartbeat;
                web::json::value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output[L"LobbyID"] = each_LobbyID;
                web::json::value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output[L"MaxPlayers"] = each_MaxPlayers;
                web::json::value each_PlayerUserIds; ToJsonUtilS(PlayerUserIds, each_PlayerUserIds); output[L"PlayerUserIds"] = each_PlayerUserIds;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[L"Region"] = each_pfRegion;
                web::json::value each_RunTime; ToJsonUtilP(RunTime, each_RunTime); output[L"RunTime"] = each_RunTime;
                web::json::value each_ServerHostname; ToJsonUtilS(ServerHostname, each_ServerHostname); output[L"ServerHostname"] = each_ServerHostname;
                web::json::value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output[L"ServerIPV4Address"] = each_ServerIPV4Address;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[L"ServerIPV6Address"] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[L"ServerPort"] = each_ServerPort;
                web::json::value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output[L"ServerPublicDNSName"] = each_ServerPublicDNSName;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[L"Tags"] = each_Tags;
                return output;
            }
        };

        struct CurrentGamesResult : public PlayFabResultCommon
        {
            Int32 GameCount;
            std::list<GameInfo> Games;
            Int32 PlayerCount;

            CurrentGamesResult() :
                PlayFabResultCommon(),
                GameCount(),
                Games(),
                PlayerCount()
            {}

            CurrentGamesResult(const CurrentGamesResult& src) :
                PlayFabResultCommon(),
                GameCount(src.GameCount),
                Games(src.Games),
                PlayerCount(src.PlayerCount)
            {}

            ~CurrentGamesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"GameCount"], GameCount);
                FromJsonUtilO(input[L"Games"], Games);
                FromJsonUtilP(input[L"PlayerCount"], PlayerCount);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameCount; ToJsonUtilP(GameCount, each_GameCount); output[L"GameCount"] = each_GameCount;
                web::json::value each_Games; ToJsonUtilO(Games, each_Games); output[L"Games"] = each_Games;
                web::json::value each_PlayerCount; ToJsonUtilP(PlayerCount, each_PlayerCount); output[L"PlayerCount"] = each_PlayerCount;
                return output;
            }
        };

        struct DeviceInfoRequest : public PlayFabRequestCommon
        {
            web::json::value Info; // Not truly arbitrary. See documentation for restrictions on format

            DeviceInfoRequest() :
                PlayFabRequestCommon(),
                Info()
            {}

            DeviceInfoRequest(const DeviceInfoRequest& src) :
                PlayFabRequestCommon(),
                Info(src.Info)
            {}

            ~DeviceInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                Info = input[L"Info"];
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"Info"] = Info;
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

        struct EntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::string EntityToken;
            Boxed<time_t> TokenExpiration;

            EntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                EntityToken(),
                TokenExpiration()
            {}

            EntityTokenResponse(const EntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            ~EntityTokenResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"EntityToken"], EntityToken);
                FromJsonUtilT(input[L"TokenExpiration"], TokenExpiration);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output[L"EntityToken"] = each_EntityToken;
                web::json::value each_TokenExpiration; ToJsonUtilT(TokenExpiration, each_TokenExpiration); output[L"TokenExpiration"] = each_TokenExpiration;
                return output;
            }
        };

        struct ExecuteCloudScriptRequest : public PlayFabRequestCommon
        {
            std::string FunctionName;
            web::json::value FunctionParameter;
            Boxed<bool> GeneratePlayStreamEvent;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            Boxed<Int32> SpecificRevision;

            ExecuteCloudScriptRequest() :
                PlayFabRequestCommon(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteCloudScriptRequest(const ExecuteCloudScriptRequest& src) :
                PlayFabRequestCommon(),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ~ExecuteCloudScriptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FunctionName"], FunctionName);
                FunctionParameter = input[L"FunctionParameter"];
                FromJsonUtilP(input[L"GeneratePlayStreamEvent"], GeneratePlayStreamEvent);
                FromJsonUtilE(input[L"RevisionSelection"], RevisionSelection);
                FromJsonUtilP(input[L"SpecificRevision"], SpecificRevision);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[L"FunctionName"] = each_FunctionName;
                output[L"FunctionParameter"] = FunctionParameter;
                web::json::value each_GeneratePlayStreamEvent; ToJsonUtilP(GeneratePlayStreamEvent, each_GeneratePlayStreamEvent); output[L"GeneratePlayStreamEvent"] = each_GeneratePlayStreamEvent;
                web::json::value each_RevisionSelection; ToJsonUtilE(RevisionSelection, each_RevisionSelection); output[L"RevisionSelection"] = each_RevisionSelection;
                web::json::value each_SpecificRevision; ToJsonUtilP(SpecificRevision, each_SpecificRevision); output[L"SpecificRevision"] = each_SpecificRevision;
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

        struct FacebookInstantGamesPlayFabIdPair : public PlayFabBaseModel
        {
            std::string FacebookInstantGamesId;
            std::string PlayFabId;

            FacebookInstantGamesPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookInstantGamesId(),
                PlayFabId()
            {}

            FacebookInstantGamesPlayFabIdPair(const FacebookInstantGamesPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookInstantGamesId(src.FacebookInstantGamesId),
                PlayFabId(src.PlayFabId)
            {}

            ~FacebookInstantGamesPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FacebookInstantGamesId"], FacebookInstantGamesId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookInstantGamesId; ToJsonUtilS(FacebookInstantGamesId, each_FacebookInstantGamesId); output[L"FacebookInstantGamesId"] = each_FacebookInstantGamesId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct FacebookPlayFabIdPair : public PlayFabBaseModel
        {
            std::string FacebookId;
            std::string PlayFabId;

            FacebookPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookId(),
                PlayFabId()
            {}

            FacebookPlayFabIdPair(const FacebookPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                PlayFabId(src.PlayFabId)
            {}

            ~FacebookPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FacebookId"], FacebookId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookId; ToJsonUtilS(FacebookId, each_FacebookId); output[L"FacebookId"] = each_FacebookId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
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

        struct FriendInfo : public PlayFabBaseModel
        {
            std::string CurrentMatchmakerLobbyId;
            Boxed<UserFacebookInfo> FacebookInfo;
            std::string FriendPlayFabId;
            Boxed<UserGameCenterInfo> GameCenterInfo;
            Boxed<PlayerProfileModel> Profile;
            Boxed<UserPsnInfo> PSNInfo;
            Boxed<UserSteamInfo> SteamInfo;
            std::list<std::string> Tags;
            std::string TitleDisplayName;
            std::string Username;
            Boxed<UserXboxInfo> XboxInfo;

            FriendInfo() :
                PlayFabBaseModel(),
                CurrentMatchmakerLobbyId(),
                FacebookInfo(),
                FriendPlayFabId(),
                GameCenterInfo(),
                Profile(),
                PSNInfo(),
                SteamInfo(),
                Tags(),
                TitleDisplayName(),
                Username(),
                XboxInfo()
            {}

            FriendInfo(const FriendInfo& src) :
                PlayFabBaseModel(),
                CurrentMatchmakerLobbyId(src.CurrentMatchmakerLobbyId),
                FacebookInfo(src.FacebookInfo),
                FriendPlayFabId(src.FriendPlayFabId),
                GameCenterInfo(src.GameCenterInfo),
                Profile(src.Profile),
                PSNInfo(src.PSNInfo),
                SteamInfo(src.SteamInfo),
                Tags(src.Tags),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username),
                XboxInfo(src.XboxInfo)
            {}

            ~FriendInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CurrentMatchmakerLobbyId"], CurrentMatchmakerLobbyId);
                FromJsonUtilO(input[L"FacebookInfo"], FacebookInfo);
                FromJsonUtilS(input[L"FriendPlayFabId"], FriendPlayFabId);
                FromJsonUtilO(input[L"GameCenterInfo"], GameCenterInfo);
                FromJsonUtilO(input[L"Profile"], Profile);
                FromJsonUtilO(input[L"PSNInfo"], PSNInfo);
                FromJsonUtilO(input[L"SteamInfo"], SteamInfo);
                FromJsonUtilS(input[L"Tags"], Tags);
                FromJsonUtilS(input[L"TitleDisplayName"], TitleDisplayName);
                FromJsonUtilS(input[L"Username"], Username);
                FromJsonUtilO(input[L"XboxInfo"], XboxInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CurrentMatchmakerLobbyId; ToJsonUtilS(CurrentMatchmakerLobbyId, each_CurrentMatchmakerLobbyId); output[L"CurrentMatchmakerLobbyId"] = each_CurrentMatchmakerLobbyId;
                web::json::value each_FacebookInfo; ToJsonUtilO(FacebookInfo, each_FacebookInfo); output[L"FacebookInfo"] = each_FacebookInfo;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[L"FriendPlayFabId"] = each_FriendPlayFabId;
                web::json::value each_GameCenterInfo; ToJsonUtilO(GameCenterInfo, each_GameCenterInfo); output[L"GameCenterInfo"] = each_GameCenterInfo;
                web::json::value each_Profile; ToJsonUtilO(Profile, each_Profile); output[L"Profile"] = each_Profile;
                web::json::value each_PSNInfo; ToJsonUtilO(PSNInfo, each_PSNInfo); output[L"PSNInfo"] = each_PSNInfo;
                web::json::value each_SteamInfo; ToJsonUtilO(SteamInfo, each_SteamInfo); output[L"SteamInfo"] = each_SteamInfo;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[L"Tags"] = each_Tags;
                web::json::value each_TitleDisplayName; ToJsonUtilS(TitleDisplayName, each_TitleDisplayName); output[L"TitleDisplayName"] = each_TitleDisplayName;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                web::json::value each_XboxInfo; ToJsonUtilO(XboxInfo, each_XboxInfo); output[L"XboxInfo"] = each_XboxInfo;
                return output;
            }
        };

        struct GameCenterPlayFabIdPair : public PlayFabBaseModel
        {
            std::string GameCenterId;
            std::string PlayFabId;

            GameCenterPlayFabIdPair() :
                PlayFabBaseModel(),
                GameCenterId(),
                PlayFabId()
            {}

            GameCenterPlayFabIdPair(const GameCenterPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId),
                PlayFabId(src.PlayFabId)
            {}

            ~GameCenterPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"GameCenterId"], GameCenterId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output[L"GameCenterId"] = each_GameCenterId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GameServerRegionsRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::string TitleId;

            GameServerRegionsRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                TitleId()
            {}

            GameServerRegionsRequest(const GameServerRegionsRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                TitleId(src.TitleId)
            {}

            ~GameServerRegionsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildVersion"], BuildVersion);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[L"BuildVersion"] = each_BuildVersion;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct RegionInfo : public PlayFabBaseModel
        {
            bool Available;
            std::string Name;
            std::string PingUrl;
            Boxed<Region> pfRegion;

            RegionInfo() :
                PlayFabBaseModel(),
                Available(),
                Name(),
                PingUrl(),
                pfRegion()
            {}

            RegionInfo(const RegionInfo& src) :
                PlayFabBaseModel(),
                Available(src.Available),
                Name(src.Name),
                PingUrl(src.PingUrl),
                pfRegion(src.pfRegion)
            {}

            ~RegionInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Available"], Available);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilS(input[L"PingUrl"], PingUrl);
                FromJsonUtilE(input[L"pfRegion"], pfRegion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Available; ToJsonUtilP(Available, each_Available); output[L"Available"] = each_Available;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_PingUrl; ToJsonUtilS(PingUrl, each_PingUrl); output[L"PingUrl"] = each_PingUrl;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[L"Region"] = each_pfRegion;
                return output;
            }
        };

        struct GameServerRegionsResult : public PlayFabResultCommon
        {
            std::list<RegionInfo> Regions;

            GameServerRegionsResult() :
                PlayFabResultCommon(),
                Regions()
            {}

            GameServerRegionsResult(const GameServerRegionsResult& src) :
                PlayFabResultCommon(),
                Regions(src.Regions)
            {}

            ~GameServerRegionsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Regions"], Regions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Regions; ToJsonUtilO(Regions, each_Regions); output[L"Regions"] = each_Regions;
                return output;
            }
        };

        struct GenericPlayFabIdPair : public PlayFabBaseModel
        {
            Boxed<GenericServiceId> GenericId;
            std::string PlayFabId;

            GenericPlayFabIdPair() :
                PlayFabBaseModel(),
                GenericId(),
                PlayFabId()
            {}

            GenericPlayFabIdPair(const GenericPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId),
                PlayFabId(src.PlayFabId)
            {}

            ~GenericPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"GenericId"], GenericId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output[L"GenericId"] = each_GenericId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetAccountInfoRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string PlayFabId;
            std::string TitleDisplayName;
            std::string Username;

            GetAccountInfoRequest() :
                PlayFabRequestCommon(),
                Email(),
                PlayFabId(),
                TitleDisplayName(),
                Username()
            {}

            GetAccountInfoRequest(const GetAccountInfoRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                PlayFabId(src.PlayFabId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            ~GetAccountInfoRequest() { }

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

        struct GetAccountInfoResult : public PlayFabResultCommon
        {
            Boxed<UserAccountInfo> AccountInfo;

            GetAccountInfoResult() :
                PlayFabResultCommon(),
                AccountInfo()
            {}

            GetAccountInfoResult(const GetAccountInfoResult& src) :
                PlayFabResultCommon(),
                AccountInfo(src.AccountInfo)
            {}

            ~GetAccountInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"AccountInfo"], AccountInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccountInfo; ToJsonUtilO(AccountInfo, each_AccountInfo); output[L"AccountInfo"] = each_AccountInfo;
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

        struct GetCharacterDataRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            Boxed<Uint32> IfChangedFromDataVersion;
            std::list<std::string> Keys;
            std::string PlayFabId;

            GetCharacterDataRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetCharacterDataRequest(const GetCharacterDataRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
            {}

            ~GetCharacterDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilP(input[L"IfChangedFromDataVersion"], IfChangedFromDataVersion);
                FromJsonUtilS(input[L"Keys"], Keys);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
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

        struct GetCharacterDataResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetCharacterDataResult() :
                PlayFabResultCommon(),
                CharacterId(),
                Data(),
                DataVersion()
            {}

            GetCharacterDataResult(const GetCharacterDataResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            ~GetCharacterDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilO(input[L"Data"], Data);
                FromJsonUtilP(input[L"DataVersion"], DataVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[L"DataVersion"] = each_DataVersion;
                return output;
            }
        };

        struct GetCharacterInventoryRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;

            GetCharacterInventoryRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId)
            {}

            ~GetCharacterInventoryRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
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

        struct GetCharacterInventoryResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabResultCommon(),
                CharacterId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~GetCharacterInventoryResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilO(input[L"Inventory"], Inventory);
                FromJsonUtilP(input[L"VirtualCurrency"], VirtualCurrency);
                FromJsonUtilO(input[L"VirtualCurrencyRechargeTimes"], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[L"Inventory"] = each_Inventory;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[L"VirtualCurrencyRechargeTimes"] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GetCharacterLeaderboardRequest : public PlayFabRequestCommon
        {
            std::string CharacterType;
            Boxed<Int32> MaxResultsCount;
            Int32 StartPosition;
            std::string StatisticName;

            GetCharacterLeaderboardRequest() :
                PlayFabRequestCommon(),
                CharacterType(),
                MaxResultsCount(),
                StartPosition(),
                StatisticName()
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName)
            {}

            ~GetCharacterLeaderboardRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterType"], CharacterType);
                FromJsonUtilP(input[L"MaxResultsCount"], MaxResultsCount);
                FromJsonUtilP(input[L"StartPosition"], StartPosition);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[L"CharacterType"] = each_CharacterType;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[L"MaxResultsCount"] = each_MaxResultsCount;
                web::json::value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output[L"StartPosition"] = each_StartPosition;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                return output;
            }
        };

        struct GetCharacterLeaderboardResult : public PlayFabResultCommon
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetCharacterLeaderboardResult() :
                PlayFabResultCommon(),
                Leaderboard()
            {}

            GetCharacterLeaderboardResult(const GetCharacterLeaderboardResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard)
            {}

            ~GetCharacterLeaderboardResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Leaderboard"], Leaderboard);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[L"Leaderboard"] = each_Leaderboard;
                return output;
            }
        };

        struct GetCharacterStatisticsRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;

            GetCharacterStatisticsRequest() :
                PlayFabRequestCommon(),
                CharacterId()
            {}

            GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId)
            {}

            ~GetCharacterStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                return output;
            }
        };

        struct GetCharacterStatisticsResult : public PlayFabResultCommon
        {
            std::map<std::string, Int32> CharacterStatistics;

            GetCharacterStatisticsResult() :
                PlayFabResultCommon(),
                CharacterStatistics()
            {}

            GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
                PlayFabResultCommon(),
                CharacterStatistics(src.CharacterStatistics)
            {}

            ~GetCharacterStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CharacterStatistics"], CharacterStatistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterStatistics; ToJsonUtilP(CharacterStatistics, each_CharacterStatistics); output[L"CharacterStatistics"] = each_CharacterStatistics;
                return output;
            }
        };

        struct GetContentDownloadUrlRequest : public PlayFabRequestCommon
        {
            std::string HttpMethod;
            std::string Key;
            Boxed<bool> ThruCDN;

            GetContentDownloadUrlRequest() :
                PlayFabRequestCommon(),
                HttpMethod(),
                Key(),
                ThruCDN()
            {}

            GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
                PlayFabRequestCommon(),
                HttpMethod(src.HttpMethod),
                Key(src.Key),
                ThruCDN(src.ThruCDN)
            {}

            ~GetContentDownloadUrlRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"HttpMethod"], HttpMethod);
                FromJsonUtilS(input[L"Key"], Key);
                FromJsonUtilP(input[L"ThruCDN"], ThruCDN);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_HttpMethod; ToJsonUtilS(HttpMethod, each_HttpMethod); output[L"HttpMethod"] = each_HttpMethod;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[L"Key"] = each_Key;
                web::json::value each_ThruCDN; ToJsonUtilP(ThruCDN, each_ThruCDN); output[L"ThruCDN"] = each_ThruCDN;
                return output;
            }
        };

        struct GetContentDownloadUrlResult : public PlayFabResultCommon
        {
            std::string URL;

            GetContentDownloadUrlResult() :
                PlayFabResultCommon(),
                URL()
            {}

            GetContentDownloadUrlResult(const GetContentDownloadUrlResult& src) :
                PlayFabResultCommon(),
                URL(src.URL)
            {}

            ~GetContentDownloadUrlResult() { }

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

        struct GetFriendLeaderboardAroundPlayerRequest : public PlayFabRequestCommon
        {
            Boxed<bool> IncludeFacebookFriends;
            Boxed<bool> IncludeSteamFriends;
            Boxed<Int32> MaxResultsCount;
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            std::string StatisticName;
            Boxed<Int32> Version;
            std::string XboxToken;

            GetFriendLeaderboardAroundPlayerRequest() :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(),
                StatisticName(),
                Version(),
                XboxToken()
            {}

            GetFriendLeaderboardAroundPlayerRequest(const GetFriendLeaderboardAroundPlayerRequest& src) :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints),
                StatisticName(src.StatisticName),
                Version(src.Version),
                XboxToken(src.XboxToken)
            {}

            ~GetFriendLeaderboardAroundPlayerRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"IncludeFacebookFriends"], IncludeFacebookFriends);
                FromJsonUtilP(input[L"IncludeSteamFriends"], IncludeSteamFriends);
                FromJsonUtilP(input[L"MaxResultsCount"], MaxResultsCount);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilO(input[L"ProfileConstraints"], ProfileConstraints);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilP(input[L"Version"], Version);
                FromJsonUtilS(input[L"XboxToken"], XboxToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output[L"IncludeFacebookFriends"] = each_IncludeFacebookFriends;
                web::json::value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output[L"IncludeSteamFriends"] = each_IncludeSteamFriends;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[L"MaxResultsCount"] = each_MaxResultsCount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[L"ProfileConstraints"] = each_ProfileConstraints;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                web::json::value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output[L"XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct PlayerLeaderboardEntry : public PlayFabBaseModel
        {
            std::string DisplayName;
            std::string PlayFabId;
            Int32 Position;
            Boxed<PlayerProfileModel> Profile;
            Int32 StatValue;

            PlayerLeaderboardEntry() :
                PlayFabBaseModel(),
                DisplayName(),
                PlayFabId(),
                Position(),
                Profile(),
                StatValue()
            {}

            PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                Profile(src.Profile),
                StatValue(src.StatValue)
            {}

            ~PlayerLeaderboardEntry() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilP(input[L"Position"], Position);
                FromJsonUtilO(input[L"Profile"], Profile);
                FromJsonUtilP(input[L"StatValue"], StatValue);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_Position; ToJsonUtilP(Position, each_Position); output[L"Position"] = each_Position;
                web::json::value each_Profile; ToJsonUtilO(Profile, each_Profile); output[L"Profile"] = each_Profile;
                web::json::value each_StatValue; ToJsonUtilP(StatValue, each_StatValue); output[L"StatValue"] = each_StatValue;
                return output;
            }
        };

        struct GetFriendLeaderboardAroundPlayerResult : public PlayFabResultCommon
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Boxed<time_t> NextReset;
            Int32 Version;

            GetFriendLeaderboardAroundPlayerResult() :
                PlayFabResultCommon(),
                Leaderboard(),
                NextReset(),
                Version()
            {}

            GetFriendLeaderboardAroundPlayerResult(const GetFriendLeaderboardAroundPlayerResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            ~GetFriendLeaderboardAroundPlayerResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Leaderboard"], Leaderboard);
                FromJsonUtilT(input[L"NextReset"], NextReset);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[L"Leaderboard"] = each_Leaderboard;
                web::json::value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output[L"NextReset"] = each_NextReset;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetFriendLeaderboardRequest : public PlayFabRequestCommon
        {
            Boxed<bool> IncludeFacebookFriends;
            Boxed<bool> IncludeSteamFriends;
            Boxed<Int32> MaxResultsCount;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            Boxed<Int32> Version;
            std::string XboxToken;

            GetFriendLeaderboardRequest() :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                ProfileConstraints(),
                StartPosition(),
                StatisticName(),
                Version(),
                XboxToken()
            {}

            GetFriendLeaderboardRequest(const GetFriendLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version),
                XboxToken(src.XboxToken)
            {}

            ~GetFriendLeaderboardRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"IncludeFacebookFriends"], IncludeFacebookFriends);
                FromJsonUtilP(input[L"IncludeSteamFriends"], IncludeSteamFriends);
                FromJsonUtilP(input[L"MaxResultsCount"], MaxResultsCount);
                FromJsonUtilO(input[L"ProfileConstraints"], ProfileConstraints);
                FromJsonUtilP(input[L"StartPosition"], StartPosition);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilP(input[L"Version"], Version);
                FromJsonUtilS(input[L"XboxToken"], XboxToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output[L"IncludeFacebookFriends"] = each_IncludeFacebookFriends;
                web::json::value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output[L"IncludeSteamFriends"] = each_IncludeSteamFriends;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[L"MaxResultsCount"] = each_MaxResultsCount;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[L"ProfileConstraints"] = each_ProfileConstraints;
                web::json::value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output[L"StartPosition"] = each_StartPosition;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                web::json::value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output[L"XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct GetFriendsListRequest : public PlayFabRequestCommon
        {
            Boxed<bool> IncludeFacebookFriends;
            Boxed<bool> IncludeSteamFriends;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            std::string XboxToken;

            GetFriendsListRequest() :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                ProfileConstraints(),
                XboxToken()
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                ProfileConstraints(src.ProfileConstraints),
                XboxToken(src.XboxToken)
            {}

            ~GetFriendsListRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"IncludeFacebookFriends"], IncludeFacebookFriends);
                FromJsonUtilP(input[L"IncludeSteamFriends"], IncludeSteamFriends);
                FromJsonUtilO(input[L"ProfileConstraints"], ProfileConstraints);
                FromJsonUtilS(input[L"XboxToken"], XboxToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                
                // grpettyj: There's something wonky with "each_IncludeFacebookFriends" so I changed it to "sneach_IncludeFacebookFriends"
                web::json::value sneach_IncludeFacebookFriends;
                ToJsonUtilP(IncludeFacebookFriends, sneach_IncludeFacebookFriends);
                output[L"IncludeFacebookFriends"] = sneach_IncludeFacebookFriends;
                web::json::value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output[L"IncludeSteamFriends"] = each_IncludeSteamFriends;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[L"ProfileConstraints"] = each_ProfileConstraints;
                web::json::value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output[L"XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct GetFriendsListResult : public PlayFabResultCommon
        {
            std::list<FriendInfo> Friends;

            GetFriendsListResult() :
                PlayFabResultCommon(),
                Friends()
            {}

            GetFriendsListResult(const GetFriendsListResult& src) :
                PlayFabResultCommon(),
                Friends(src.Friends)
            {}

            ~GetFriendsListResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Friends"], Friends);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Friends; ToJsonUtilO(Friends, each_Friends); output[L"Friends"] = each_Friends;
                return output;
            }
        };

        struct GetLeaderboardAroundCharacterRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string CharacterType;
            Boxed<Int32> MaxResultsCount;
            std::string StatisticName;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(),
                StatisticName()
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StatisticName(src.StatisticName)
            {}

            ~GetLeaderboardAroundCharacterRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"CharacterType"], CharacterType);
                FromJsonUtilP(input[L"MaxResultsCount"], MaxResultsCount);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[L"CharacterType"] = each_CharacterType;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[L"MaxResultsCount"] = each_MaxResultsCount;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                return output;
            }
        };

        struct GetLeaderboardAroundCharacterResult : public PlayFabResultCommon
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetLeaderboardAroundCharacterResult() :
                PlayFabResultCommon(),
                Leaderboard()
            {}

            GetLeaderboardAroundCharacterResult(const GetLeaderboardAroundCharacterResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard)
            {}

            ~GetLeaderboardAroundCharacterResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Leaderboard"], Leaderboard);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[L"Leaderboard"] = each_Leaderboard;
                return output;
            }
        };

        struct GetLeaderboardAroundPlayerRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> MaxResultsCount;
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            std::string StatisticName;
            Boxed<Int32> Version;

            GetLeaderboardAroundPlayerRequest() :
                PlayFabRequestCommon(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(),
                StatisticName(),
                Version()
            {}

            GetLeaderboardAroundPlayerRequest(const GetLeaderboardAroundPlayerRequest& src) :
                PlayFabRequestCommon(),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~GetLeaderboardAroundPlayerRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"MaxResultsCount"], MaxResultsCount);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilO(input[L"ProfileConstraints"], ProfileConstraints);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[L"MaxResultsCount"] = each_MaxResultsCount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[L"ProfileConstraints"] = each_ProfileConstraints;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetLeaderboardAroundPlayerResult : public PlayFabResultCommon
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Boxed<time_t> NextReset;
            Int32 Version;

            GetLeaderboardAroundPlayerResult() :
                PlayFabResultCommon(),
                Leaderboard(),
                NextReset(),
                Version()
            {}

            GetLeaderboardAroundPlayerResult(const GetLeaderboardAroundPlayerResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            ~GetLeaderboardAroundPlayerResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Leaderboard"], Leaderboard);
                FromJsonUtilT(input[L"NextReset"], NextReset);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[L"Leaderboard"] = each_Leaderboard;
                web::json::value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output[L"NextReset"] = each_NextReset;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetLeaderboardForUsersCharactersRequest : public PlayFabRequestCommon
        {
            Int32 MaxResultsCount;
            std::string StatisticName;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabRequestCommon(),
                MaxResultsCount(),
                StatisticName()
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabRequestCommon(),
                MaxResultsCount(src.MaxResultsCount),
                StatisticName(src.StatisticName)
            {}

            ~GetLeaderboardForUsersCharactersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"MaxResultsCount"], MaxResultsCount);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[L"MaxResultsCount"] = each_MaxResultsCount;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                return output;
            }
        };

        struct GetLeaderboardForUsersCharactersResult : public PlayFabResultCommon
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetLeaderboardForUsersCharactersResult() :
                PlayFabResultCommon(),
                Leaderboard()
            {}

            GetLeaderboardForUsersCharactersResult(const GetLeaderboardForUsersCharactersResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard)
            {}

            ~GetLeaderboardForUsersCharactersResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Leaderboard"], Leaderboard);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[L"Leaderboard"] = each_Leaderboard;
                return output;
            }
        };

        struct GetLeaderboardRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> MaxResultsCount;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            Boxed<Int32> Version;

            GetLeaderboardRequest() :
                PlayFabRequestCommon(),
                MaxResultsCount(),
                ProfileConstraints(),
                StartPosition(),
                StatisticName(),
                Version()
            {}

            GetLeaderboardRequest(const GetLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~GetLeaderboardRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"MaxResultsCount"], MaxResultsCount);
                FromJsonUtilO(input[L"ProfileConstraints"], ProfileConstraints);
                FromJsonUtilP(input[L"StartPosition"], StartPosition);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[L"MaxResultsCount"] = each_MaxResultsCount;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[L"ProfileConstraints"] = each_ProfileConstraints;
                web::json::value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output[L"StartPosition"] = each_StartPosition;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetLeaderboardResult : public PlayFabResultCommon
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Boxed<time_t> NextReset;
            Int32 Version;

            GetLeaderboardResult() :
                PlayFabResultCommon(),
                Leaderboard(),
                NextReset(),
                Version()
            {}

            GetLeaderboardResult(const GetLeaderboardResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            ~GetLeaderboardResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Leaderboard"], Leaderboard);
                FromJsonUtilT(input[L"NextReset"], NextReset);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[L"Leaderboard"] = each_Leaderboard;
                web::json::value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output[L"NextReset"] = each_NextReset;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetPaymentTokenRequest : public PlayFabRequestCommon
        {
            std::string TokenProvider;

            GetPaymentTokenRequest() :
                PlayFabRequestCommon(),
                TokenProvider()
            {}

            GetPaymentTokenRequest(const GetPaymentTokenRequest& src) :
                PlayFabRequestCommon(),
                TokenProvider(src.TokenProvider)
            {}

            ~GetPaymentTokenRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TokenProvider"], TokenProvider);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TokenProvider; ToJsonUtilS(TokenProvider, each_TokenProvider); output[L"TokenProvider"] = each_TokenProvider;
                return output;
            }
        };

        struct GetPaymentTokenResult : public PlayFabResultCommon
        {
            std::string OrderId;
            std::string ProviderToken;

            GetPaymentTokenResult() :
                PlayFabResultCommon(),
                OrderId(),
                ProviderToken()
            {}

            GetPaymentTokenResult(const GetPaymentTokenResult& src) :
                PlayFabResultCommon(),
                OrderId(src.OrderId),
                ProviderToken(src.ProviderToken)
            {}

            ~GetPaymentTokenResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"OrderId"], OrderId);
                FromJsonUtilS(input[L"ProviderToken"], ProviderToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                web::json::value each_ProviderToken; ToJsonUtilS(ProviderToken, each_ProviderToken); output[L"ProviderToken"] = each_ProviderToken;
                return output;
            }
        };

        struct GetPhotonAuthenticationTokenRequest : public PlayFabRequestCommon
        {
            std::string PhotonApplicationId;

            GetPhotonAuthenticationTokenRequest() :
                PlayFabRequestCommon(),
                PhotonApplicationId()
            {}

            GetPhotonAuthenticationTokenRequest(const GetPhotonAuthenticationTokenRequest& src) :
                PlayFabRequestCommon(),
                PhotonApplicationId(src.PhotonApplicationId)
            {}

            ~GetPhotonAuthenticationTokenRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PhotonApplicationId"], PhotonApplicationId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PhotonApplicationId; ToJsonUtilS(PhotonApplicationId, each_PhotonApplicationId); output[L"PhotonApplicationId"] = each_PhotonApplicationId;
                return output;
            }
        };

        struct GetPhotonAuthenticationTokenResult : public PlayFabResultCommon
        {
            std::string PhotonCustomAuthenticationToken;

            GetPhotonAuthenticationTokenResult() :
                PlayFabResultCommon(),
                PhotonCustomAuthenticationToken()
            {}

            GetPhotonAuthenticationTokenResult(const GetPhotonAuthenticationTokenResult& src) :
                PlayFabResultCommon(),
                PhotonCustomAuthenticationToken(src.PhotonCustomAuthenticationToken)
            {}

            ~GetPhotonAuthenticationTokenResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PhotonCustomAuthenticationToken"], PhotonCustomAuthenticationToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PhotonCustomAuthenticationToken; ToJsonUtilS(PhotonCustomAuthenticationToken, each_PhotonCustomAuthenticationToken); output[L"PhotonCustomAuthenticationToken"] = each_PhotonCustomAuthenticationToken;
                return output;
            }
        };

        struct GetPlayerCombinedInfoRequestParams : public PlayFabBaseModel
        {
            bool GetCharacterInventories;
            bool GetCharacterList;
            bool GetPlayerProfile;
            bool GetPlayerStatistics;
            bool GetTitleData;
            bool GetUserAccountInfo;
            bool GetUserData;
            bool GetUserInventory;
            bool GetUserReadOnlyData;
            bool GetUserVirtualCurrency;
            std::list<std::string> PlayerStatisticNames;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            std::list<std::string> TitleDataKeys;
            std::list<std::string> UserDataKeys;
            std::list<std::string> UserReadOnlyDataKeys;

            GetPlayerCombinedInfoRequestParams() :
                PlayFabBaseModel(),
                GetCharacterInventories(),
                GetCharacterList(),
                GetPlayerProfile(),
                GetPlayerStatistics(),
                GetTitleData(),
                GetUserAccountInfo(),
                GetUserData(),
                GetUserInventory(),
                GetUserReadOnlyData(),
                GetUserVirtualCurrency(),
                PlayerStatisticNames(),
                ProfileConstraints(),
                TitleDataKeys(),
                UserDataKeys(),
                UserReadOnlyDataKeys()
            {}

            GetPlayerCombinedInfoRequestParams(const GetPlayerCombinedInfoRequestParams& src) :
                PlayFabBaseModel(),
                GetCharacterInventories(src.GetCharacterInventories),
                GetCharacterList(src.GetCharacterList),
                GetPlayerProfile(src.GetPlayerProfile),
                GetPlayerStatistics(src.GetPlayerStatistics),
                GetTitleData(src.GetTitleData),
                GetUserAccountInfo(src.GetUserAccountInfo),
                GetUserData(src.GetUserData),
                GetUserInventory(src.GetUserInventory),
                GetUserReadOnlyData(src.GetUserReadOnlyData),
                GetUserVirtualCurrency(src.GetUserVirtualCurrency),
                PlayerStatisticNames(src.PlayerStatisticNames),
                ProfileConstraints(src.ProfileConstraints),
                TitleDataKeys(src.TitleDataKeys),
                UserDataKeys(src.UserDataKeys),
                UserReadOnlyDataKeys(src.UserReadOnlyDataKeys)
            {}

            ~GetPlayerCombinedInfoRequestParams() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"GetCharacterInventories"], GetCharacterInventories);
                FromJsonUtilP(input[L"GetCharacterList"], GetCharacterList);
                FromJsonUtilP(input[L"GetPlayerProfile"], GetPlayerProfile);
                FromJsonUtilP(input[L"GetPlayerStatistics"], GetPlayerStatistics);
                FromJsonUtilP(input[L"GetTitleData"], GetTitleData);
                FromJsonUtilP(input[L"GetUserAccountInfo"], GetUserAccountInfo);
                FromJsonUtilP(input[L"GetUserData"], GetUserData);
                FromJsonUtilP(input[L"GetUserInventory"], GetUserInventory);
                FromJsonUtilP(input[L"GetUserReadOnlyData"], GetUserReadOnlyData);
                FromJsonUtilP(input[L"GetUserVirtualCurrency"], GetUserVirtualCurrency);
                FromJsonUtilS(input[L"PlayerStatisticNames"], PlayerStatisticNames);
                FromJsonUtilO(input[L"ProfileConstraints"], ProfileConstraints);
                FromJsonUtilS(input[L"TitleDataKeys"], TitleDataKeys);
                FromJsonUtilS(input[L"UserDataKeys"], UserDataKeys);
                FromJsonUtilS(input[L"UserReadOnlyDataKeys"], UserReadOnlyDataKeys);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GetCharacterInventories; ToJsonUtilP(GetCharacterInventories, each_GetCharacterInventories); output[L"GetCharacterInventories"] = each_GetCharacterInventories;
                web::json::value each_GetCharacterList; ToJsonUtilP(GetCharacterList, each_GetCharacterList); output[L"GetCharacterList"] = each_GetCharacterList;
                web::json::value each_GetPlayerProfile; ToJsonUtilP(GetPlayerProfile, each_GetPlayerProfile); output[L"GetPlayerProfile"] = each_GetPlayerProfile;
                web::json::value each_GetPlayerStatistics; ToJsonUtilP(GetPlayerStatistics, each_GetPlayerStatistics); output[L"GetPlayerStatistics"] = each_GetPlayerStatistics;
                web::json::value each_GetTitleData; ToJsonUtilP(GetTitleData, each_GetTitleData); output[L"GetTitleData"] = each_GetTitleData;
                web::json::value each_GetUserAccountInfo; ToJsonUtilP(GetUserAccountInfo, each_GetUserAccountInfo); output[L"GetUserAccountInfo"] = each_GetUserAccountInfo;
                web::json::value each_GetUserData; ToJsonUtilP(GetUserData, each_GetUserData); output[L"GetUserData"] = each_GetUserData;
                web::json::value each_GetUserInventory; ToJsonUtilP(GetUserInventory, each_GetUserInventory); output[L"GetUserInventory"] = each_GetUserInventory;
                web::json::value each_GetUserReadOnlyData; ToJsonUtilP(GetUserReadOnlyData, each_GetUserReadOnlyData); output[L"GetUserReadOnlyData"] = each_GetUserReadOnlyData;
                web::json::value each_GetUserVirtualCurrency; ToJsonUtilP(GetUserVirtualCurrency, each_GetUserVirtualCurrency); output[L"GetUserVirtualCurrency"] = each_GetUserVirtualCurrency;
                web::json::value each_PlayerStatisticNames; ToJsonUtilS(PlayerStatisticNames, each_PlayerStatisticNames); output[L"PlayerStatisticNames"] = each_PlayerStatisticNames;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[L"ProfileConstraints"] = each_ProfileConstraints;
                web::json::value each_TitleDataKeys; ToJsonUtilS(TitleDataKeys, each_TitleDataKeys); output[L"TitleDataKeys"] = each_TitleDataKeys;
                web::json::value each_UserDataKeys; ToJsonUtilS(UserDataKeys, each_UserDataKeys); output[L"UserDataKeys"] = each_UserDataKeys;
                web::json::value each_UserReadOnlyDataKeys; ToJsonUtilS(UserReadOnlyDataKeys, each_UserReadOnlyDataKeys); output[L"UserReadOnlyDataKeys"] = each_UserReadOnlyDataKeys;
                return output;
            }
        };

        struct GetPlayerCombinedInfoRequest : public PlayFabRequestCommon
        {
            GetPlayerCombinedInfoRequestParams InfoRequestParameters;
            std::string PlayFabId;

            GetPlayerCombinedInfoRequest() :
                PlayFabRequestCommon(),
                InfoRequestParameters(),
                PlayFabId()
            {}

            GetPlayerCombinedInfoRequest(const GetPlayerCombinedInfoRequest& src) :
                PlayFabRequestCommon(),
                InfoRequestParameters(src.InfoRequestParameters),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayerCombinedInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct StatisticValue : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 Value;
            Uint32 Version;

            StatisticValue() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(),
                Version()
            {}

            StatisticValue(const StatisticValue& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            ~StatisticValue() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilP(input[L"Value"], Value);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Value; ToJsonUtilP(Value, each_Value); output[L"Value"] = each_Value;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetPlayerCombinedInfoResultPayload : public PlayFabBaseModel
        {
            Boxed<UserAccountInfo> AccountInfo;
            std::list<CharacterInventory> CharacterInventories;
            std::list<CharacterResult> CharacterList;
            Boxed<PlayerProfileModel> PlayerProfile;
            std::list<StatisticValue> PlayerStatistics;
            std::map<std::string, std::string> TitleData;
            std::map<std::string, UserDataRecord> UserData;
            Uint32 UserDataVersion;
            std::list<ItemInstance> UserInventory;
            std::map<std::string, UserDataRecord> UserReadOnlyData;
            Uint32 UserReadOnlyDataVersion;
            std::map<std::string, Int32> UserVirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> UserVirtualCurrencyRechargeTimes;

            GetPlayerCombinedInfoResultPayload() :
                PlayFabBaseModel(),
                AccountInfo(),
                CharacterInventories(),
                CharacterList(),
                PlayerProfile(),
                PlayerStatistics(),
                TitleData(),
                UserData(),
                UserDataVersion(),
                UserInventory(),
                UserReadOnlyData(),
                UserReadOnlyDataVersion(),
                UserVirtualCurrency(),
                UserVirtualCurrencyRechargeTimes()
            {}

            GetPlayerCombinedInfoResultPayload(const GetPlayerCombinedInfoResultPayload& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo),
                CharacterInventories(src.CharacterInventories),
                CharacterList(src.CharacterList),
                PlayerProfile(src.PlayerProfile),
                PlayerStatistics(src.PlayerStatistics),
                TitleData(src.TitleData),
                UserData(src.UserData),
                UserDataVersion(src.UserDataVersion),
                UserInventory(src.UserInventory),
                UserReadOnlyData(src.UserReadOnlyData),
                UserReadOnlyDataVersion(src.UserReadOnlyDataVersion),
                UserVirtualCurrency(src.UserVirtualCurrency),
                UserVirtualCurrencyRechargeTimes(src.UserVirtualCurrencyRechargeTimes)
            {}

            ~GetPlayerCombinedInfoResultPayload() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"AccountInfo"], AccountInfo);
                FromJsonUtilO(input[L"CharacterInventories"], CharacterInventories);
                FromJsonUtilO(input[L"CharacterList"], CharacterList);
                FromJsonUtilO(input[L"PlayerProfile"], PlayerProfile);
                FromJsonUtilO(input[L"PlayerStatistics"], PlayerStatistics);
                FromJsonUtilS(input[L"TitleData"], TitleData);
                FromJsonUtilO(input[L"UserData"], UserData);
                FromJsonUtilP(input[L"UserDataVersion"], UserDataVersion);
                FromJsonUtilO(input[L"UserInventory"], UserInventory);
                FromJsonUtilO(input[L"UserReadOnlyData"], UserReadOnlyData);
                FromJsonUtilP(input[L"UserReadOnlyDataVersion"], UserReadOnlyDataVersion);
                FromJsonUtilP(input[L"UserVirtualCurrency"], UserVirtualCurrency);
                FromJsonUtilO(input[L"UserVirtualCurrencyRechargeTimes"], UserVirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccountInfo; ToJsonUtilO(AccountInfo, each_AccountInfo); output[L"AccountInfo"] = each_AccountInfo;
                web::json::value each_CharacterInventories; ToJsonUtilO(CharacterInventories, each_CharacterInventories); output[L"CharacterInventories"] = each_CharacterInventories;
                web::json::value each_CharacterList; ToJsonUtilO(CharacterList, each_CharacterList); output[L"CharacterList"] = each_CharacterList;
                web::json::value each_PlayerProfile; ToJsonUtilO(PlayerProfile, each_PlayerProfile); output[L"PlayerProfile"] = each_PlayerProfile;
                web::json::value each_PlayerStatistics; ToJsonUtilO(PlayerStatistics, each_PlayerStatistics); output[L"PlayerStatistics"] = each_PlayerStatistics;
                web::json::value each_TitleData; ToJsonUtilS(TitleData, each_TitleData); output[L"TitleData"] = each_TitleData;
                web::json::value each_UserData; ToJsonUtilO(UserData, each_UserData); output[L"UserData"] = each_UserData;
                web::json::value each_UserDataVersion; ToJsonUtilP(UserDataVersion, each_UserDataVersion); output[L"UserDataVersion"] = each_UserDataVersion;
                web::json::value each_UserInventory; ToJsonUtilO(UserInventory, each_UserInventory); output[L"UserInventory"] = each_UserInventory;
                web::json::value each_UserReadOnlyData; ToJsonUtilO(UserReadOnlyData, each_UserReadOnlyData); output[L"UserReadOnlyData"] = each_UserReadOnlyData;
                web::json::value each_UserReadOnlyDataVersion; ToJsonUtilP(UserReadOnlyDataVersion, each_UserReadOnlyDataVersion); output[L"UserReadOnlyDataVersion"] = each_UserReadOnlyDataVersion;
                web::json::value each_UserVirtualCurrency; ToJsonUtilP(UserVirtualCurrency, each_UserVirtualCurrency); output[L"UserVirtualCurrency"] = each_UserVirtualCurrency;
                web::json::value each_UserVirtualCurrencyRechargeTimes; ToJsonUtilO(UserVirtualCurrencyRechargeTimes, each_UserVirtualCurrencyRechargeTimes); output[L"UserVirtualCurrencyRechargeTimes"] = each_UserVirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GetPlayerCombinedInfoResult : public PlayFabResultCommon
        {
            Boxed<GetPlayerCombinedInfoResultPayload> InfoResultPayload;
            std::string PlayFabId;

            GetPlayerCombinedInfoResult() :
                PlayFabResultCommon(),
                InfoResultPayload(),
                PlayFabId()
            {}

            GetPlayerCombinedInfoResult(const GetPlayerCombinedInfoResult& src) :
                PlayFabResultCommon(),
                InfoResultPayload(src.InfoResultPayload),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayerCombinedInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"InfoResultPayload"], InfoResultPayload);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_InfoResultPayload; ToJsonUtilO(InfoResultPayload, each_InfoResultPayload); output[L"InfoResultPayload"] = each_InfoResultPayload;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
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

        struct GetPlayerSegmentsRequest : public PlayFabRequestCommon
        {

            GetPlayerSegmentsRequest() :
                PlayFabRequestCommon()
            {}

            GetPlayerSegmentsRequest(const GetPlayerSegmentsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetPlayerSegmentsRequest() { }

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

        struct StatisticNameVersion : public PlayFabBaseModel
        {
            std::string StatisticName;
            Uint32 Version;

            StatisticNameVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version()
            {}

            StatisticNameVersion(const StatisticNameVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~StatisticNameVersion() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct GetPlayerStatisticsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> StatisticNames;
            std::list<StatisticNameVersion> StatisticNameVersions;

            GetPlayerStatisticsRequest() :
                PlayFabRequestCommon(),
                StatisticNames(),
                StatisticNameVersions()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabRequestCommon(),
                StatisticNames(src.StatisticNames),
                StatisticNameVersions(src.StatisticNameVersions)
            {}

            ~GetPlayerStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"StatisticNames"], StatisticNames);
                FromJsonUtilO(input[L"StatisticNameVersions"], StatisticNameVersions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticNames; ToJsonUtilS(StatisticNames, each_StatisticNames); output[L"StatisticNames"] = each_StatisticNames;
                web::json::value each_StatisticNameVersions; ToJsonUtilO(StatisticNameVersions, each_StatisticNameVersions); output[L"StatisticNameVersions"] = each_StatisticNameVersions;
                return output;
            }
        };

        struct GetPlayerStatisticsResult : public PlayFabResultCommon
        {
            std::list<StatisticValue> Statistics;

            GetPlayerStatisticsResult() :
                PlayFabResultCommon(),
                Statistics()
            {}

            GetPlayerStatisticsResult(const GetPlayerStatisticsResult& src) :
                PlayFabResultCommon(),
                Statistics(src.Statistics)
            {}

            ~GetPlayerStatisticsResult() { }

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
            Boxed<time_t> DeactivationTime;
            Boxed<time_t> ScheduledActivationTime;
            Boxed<time_t> ScheduledDeactivationTime;
            std::string StatisticName;
            Uint32 Version;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                ActivationTime(),
                DeactivationTime(),
                ScheduledActivationTime(),
                ScheduledDeactivationTime(),
                StatisticName(),
                Version()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                ActivationTime(src.ActivationTime),
                DeactivationTime(src.DeactivationTime),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~PlayerStatisticVersion() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"ActivationTime"], ActivationTime);
                FromJsonUtilT(input[L"DeactivationTime"], DeactivationTime);
                FromJsonUtilT(input[L"ScheduledActivationTime"], ScheduledActivationTime);
                FromJsonUtilT(input[L"ScheduledDeactivationTime"], ScheduledDeactivationTime);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActivationTime; ToJsonUtilT(ActivationTime, each_ActivationTime); output[L"ActivationTime"] = each_ActivationTime;
                web::json::value each_DeactivationTime; ToJsonUtilT(DeactivationTime, each_DeactivationTime); output[L"DeactivationTime"] = each_DeactivationTime;
                web::json::value each_ScheduledActivationTime; ToJsonUtilT(ScheduledActivationTime, each_ScheduledActivationTime); output[L"ScheduledActivationTime"] = each_ScheduledActivationTime;
                web::json::value each_ScheduledDeactivationTime; ToJsonUtilT(ScheduledDeactivationTime, each_ScheduledDeactivationTime); output[L"ScheduledDeactivationTime"] = each_ScheduledDeactivationTime;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
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

        struct GetPlayerTradesRequest : public PlayFabRequestCommon
        {
            Boxed<TradeStatus> StatusFilter;

            GetPlayerTradesRequest() :
                PlayFabRequestCommon(),
                StatusFilter()
            {}

            GetPlayerTradesRequest(const GetPlayerTradesRequest& src) :
                PlayFabRequestCommon(),
                StatusFilter(src.StatusFilter)
            {}

            ~GetPlayerTradesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"StatusFilter"], StatusFilter);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatusFilter; ToJsonUtilE(StatusFilter, each_StatusFilter); output[L"StatusFilter"] = each_StatusFilter;
                return output;
            }
        };

        struct GetPlayerTradesResponse : public PlayFabResultCommon
        {
            std::list<TradeInfo> AcceptedTrades;
            std::list<TradeInfo> OpenedTrades;

            GetPlayerTradesResponse() :
                PlayFabResultCommon(),
                AcceptedTrades(),
                OpenedTrades()
            {}

            GetPlayerTradesResponse(const GetPlayerTradesResponse& src) :
                PlayFabResultCommon(),
                AcceptedTrades(src.AcceptedTrades),
                OpenedTrades(src.OpenedTrades)
            {}

            ~GetPlayerTradesResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"AcceptedTrades"], AcceptedTrades);
                FromJsonUtilO(input[L"OpenedTrades"], OpenedTrades);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AcceptedTrades; ToJsonUtilO(AcceptedTrades, each_AcceptedTrades); output[L"AcceptedTrades"] = each_AcceptedTrades;
                web::json::value each_OpenedTrades; ToJsonUtilO(OpenedTrades, each_OpenedTrades); output[L"OpenedTrades"] = each_OpenedTrades;
                return output;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> FacebookIDs;

            GetPlayFabIDsFromFacebookIDsRequest() :
                PlayFabRequestCommon(),
                FacebookIDs()
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const GetPlayFabIDsFromFacebookIDsRequest& src) :
                PlayFabRequestCommon(),
                FacebookIDs(src.FacebookIDs)
            {}

            ~GetPlayFabIDsFromFacebookIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FacebookIDs"], FacebookIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookIDs; ToJsonUtilS(FacebookIDs, each_FacebookIDs); output[L"FacebookIDs"] = each_FacebookIDs;
                return output;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsResult : public PlayFabResultCommon
        {
            std::list<FacebookPlayFabIdPair> Data;

            GetPlayFabIDsFromFacebookIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromFacebookIDsResult(const GetPlayFabIDsFromFacebookIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromFacebookIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromFacebookInstantGamesIdsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> FacebookInstantGamesIds;

            GetPlayFabIDsFromFacebookInstantGamesIdsRequest() :
                PlayFabRequestCommon(),
                FacebookInstantGamesIds()
            {}

            GetPlayFabIDsFromFacebookInstantGamesIdsRequest(const GetPlayFabIDsFromFacebookInstantGamesIdsRequest& src) :
                PlayFabRequestCommon(),
                FacebookInstantGamesIds(src.FacebookInstantGamesIds)
            {}

            ~GetPlayFabIDsFromFacebookInstantGamesIdsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FacebookInstantGamesIds"], FacebookInstantGamesIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookInstantGamesIds; ToJsonUtilS(FacebookInstantGamesIds, each_FacebookInstantGamesIds); output[L"FacebookInstantGamesIds"] = each_FacebookInstantGamesIds;
                return output;
            }
        };

        struct GetPlayFabIDsFromFacebookInstantGamesIdsResult : public PlayFabResultCommon
        {
            std::list<FacebookInstantGamesPlayFabIdPair> Data;

            GetPlayFabIDsFromFacebookInstantGamesIdsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromFacebookInstantGamesIdsResult(const GetPlayFabIDsFromFacebookInstantGamesIdsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromFacebookInstantGamesIdsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromGameCenterIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> GameCenterIDs;

            GetPlayFabIDsFromGameCenterIDsRequest() :
                PlayFabRequestCommon(),
                GameCenterIDs()
            {}

            GetPlayFabIDsFromGameCenterIDsRequest(const GetPlayFabIDsFromGameCenterIDsRequest& src) :
                PlayFabRequestCommon(),
                GameCenterIDs(src.GameCenterIDs)
            {}

            ~GetPlayFabIDsFromGameCenterIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"GameCenterIDs"], GameCenterIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameCenterIDs; ToJsonUtilS(GameCenterIDs, each_GameCenterIDs); output[L"GameCenterIDs"] = each_GameCenterIDs;
                return output;
            }
        };

        struct GetPlayFabIDsFromGameCenterIDsResult : public PlayFabResultCommon
        {
            std::list<GameCenterPlayFabIdPair> Data;

            GetPlayFabIDsFromGameCenterIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromGameCenterIDsResult(const GetPlayFabIDsFromGameCenterIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromGameCenterIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromGenericIDsRequest : public PlayFabRequestCommon
        {
            std::list<GenericServiceId> GenericIDs;

            GetPlayFabIDsFromGenericIDsRequest() :
                PlayFabRequestCommon(),
                GenericIDs()
            {}

            GetPlayFabIDsFromGenericIDsRequest(const GetPlayFabIDsFromGenericIDsRequest& src) :
                PlayFabRequestCommon(),
                GenericIDs(src.GenericIDs)
            {}

            ~GetPlayFabIDsFromGenericIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"GenericIDs"], GenericIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GenericIDs; ToJsonUtilO(GenericIDs, each_GenericIDs); output[L"GenericIDs"] = each_GenericIDs;
                return output;
            }
        };

        struct GetPlayFabIDsFromGenericIDsResult : public PlayFabResultCommon
        {
            std::list<GenericPlayFabIdPair> Data;

            GetPlayFabIDsFromGenericIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromGenericIDsResult(const GetPlayFabIDsFromGenericIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromGenericIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromGoogleIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> GoogleIDs;

            GetPlayFabIDsFromGoogleIDsRequest() :
                PlayFabRequestCommon(),
                GoogleIDs()
            {}

            GetPlayFabIDsFromGoogleIDsRequest(const GetPlayFabIDsFromGoogleIDsRequest& src) :
                PlayFabRequestCommon(),
                GoogleIDs(src.GoogleIDs)
            {}

            ~GetPlayFabIDsFromGoogleIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"GoogleIDs"], GoogleIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GoogleIDs; ToJsonUtilS(GoogleIDs, each_GoogleIDs); output[L"GoogleIDs"] = each_GoogleIDs;
                return output;
            }
        };

        struct GooglePlayFabIdPair : public PlayFabBaseModel
        {
            std::string GoogleId;
            std::string PlayFabId;

            GooglePlayFabIdPair() :
                PlayFabBaseModel(),
                GoogleId(),
                PlayFabId()
            {}

            GooglePlayFabIdPair(const GooglePlayFabIdPair& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                PlayFabId(src.PlayFabId)
            {}

            ~GooglePlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"GoogleId"], GoogleId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GoogleId; ToJsonUtilS(GoogleId, each_GoogleId); output[L"GoogleId"] = each_GoogleId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayFabIDsFromGoogleIDsResult : public PlayFabResultCommon
        {
            std::list<GooglePlayFabIdPair> Data;

            GetPlayFabIDsFromGoogleIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromGoogleIDsResult(const GetPlayFabIDsFromGoogleIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromGoogleIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromKongregateIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> KongregateIDs;

            GetPlayFabIDsFromKongregateIDsRequest() :
                PlayFabRequestCommon(),
                KongregateIDs()
            {}

            GetPlayFabIDsFromKongregateIDsRequest(const GetPlayFabIDsFromKongregateIDsRequest& src) :
                PlayFabRequestCommon(),
                KongregateIDs(src.KongregateIDs)
            {}

            ~GetPlayFabIDsFromKongregateIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"KongregateIDs"], KongregateIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_KongregateIDs; ToJsonUtilS(KongregateIDs, each_KongregateIDs); output[L"KongregateIDs"] = each_KongregateIDs;
                return output;
            }
        };

        struct KongregatePlayFabIdPair : public PlayFabBaseModel
        {
            std::string KongregateId;
            std::string PlayFabId;

            KongregatePlayFabIdPair() :
                PlayFabBaseModel(),
                KongregateId(),
                PlayFabId()
            {}

            KongregatePlayFabIdPair(const KongregatePlayFabIdPair& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                PlayFabId(src.PlayFabId)
            {}

            ~KongregatePlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"KongregateId"], KongregateId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output[L"KongregateId"] = each_KongregateId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayFabIDsFromKongregateIDsResult : public PlayFabResultCommon
        {
            std::list<KongregatePlayFabIdPair> Data;

            GetPlayFabIDsFromKongregateIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromKongregateIDsResult(const GetPlayFabIDsFromKongregateIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromKongregateIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> NintendoSwitchDeviceIds;

            GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest() :
                PlayFabRequestCommon(),
                NintendoSwitchDeviceIds()
            {}

            GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(const GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& src) :
                PlayFabRequestCommon(),
                NintendoSwitchDeviceIds(src.NintendoSwitchDeviceIds)
            {}

            ~GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"NintendoSwitchDeviceIds"], NintendoSwitchDeviceIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_NintendoSwitchDeviceIds; ToJsonUtilS(NintendoSwitchDeviceIds, each_NintendoSwitchDeviceIds); output[L"NintendoSwitchDeviceIds"] = each_NintendoSwitchDeviceIds;
                return output;
            }
        };

        struct NintendoSwitchPlayFabIdPair : public PlayFabBaseModel
        {
            std::string NintendoSwitchDeviceId;
            std::string PlayFabId;

            NintendoSwitchPlayFabIdPair() :
                PlayFabBaseModel(),
                NintendoSwitchDeviceId(),
                PlayFabId()
            {}

            NintendoSwitchPlayFabIdPair(const NintendoSwitchPlayFabIdPair& src) :
                PlayFabBaseModel(),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId),
                PlayFabId(src.PlayFabId)
            {}

            ~NintendoSwitchPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output[L"NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayFabIDsFromNintendoSwitchDeviceIdsResult : public PlayFabResultCommon
        {
            std::list<NintendoSwitchPlayFabIdPair> Data;

            GetPlayFabIDsFromNintendoSwitchDeviceIdsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromNintendoSwitchDeviceIdsResult(const GetPlayFabIDsFromNintendoSwitchDeviceIdsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromNintendoSwitchDeviceIdsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromSteamIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> SteamStringIDs;

            GetPlayFabIDsFromSteamIDsRequest() :
                PlayFabRequestCommon(),
                SteamStringIDs()
            {}

            GetPlayFabIDsFromSteamIDsRequest(const GetPlayFabIDsFromSteamIDsRequest& src) :
                PlayFabRequestCommon(),
                SteamStringIDs(src.SteamStringIDs)
            {}

            ~GetPlayFabIDsFromSteamIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"SteamStringIDs"], SteamStringIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SteamStringIDs; ToJsonUtilS(SteamStringIDs, each_SteamStringIDs); output[L"SteamStringIDs"] = each_SteamStringIDs;
                return output;
            }
        };

        struct SteamPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string SteamStringId;

            SteamPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                SteamStringId()
            {}

            SteamPlayFabIdPair(const SteamPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                SteamStringId(src.SteamStringId)
            {}

            ~SteamPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"SteamStringId"], SteamStringId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_SteamStringId; ToJsonUtilS(SteamStringId, each_SteamStringId); output[L"SteamStringId"] = each_SteamStringId;
                return output;
            }
        };

        struct GetPlayFabIDsFromSteamIDsResult : public PlayFabResultCommon
        {
            std::list<SteamPlayFabIdPair> Data;

            GetPlayFabIDsFromSteamIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromSteamIDsResult(const GetPlayFabIDsFromSteamIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromSteamIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromTwitchIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> TwitchIds;

            GetPlayFabIDsFromTwitchIDsRequest() :
                PlayFabRequestCommon(),
                TwitchIds()
            {}

            GetPlayFabIDsFromTwitchIDsRequest(const GetPlayFabIDsFromTwitchIDsRequest& src) :
                PlayFabRequestCommon(),
                TwitchIds(src.TwitchIds)
            {}

            ~GetPlayFabIDsFromTwitchIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TwitchIds"], TwitchIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TwitchIds; ToJsonUtilS(TwitchIds, each_TwitchIds); output[L"TwitchIds"] = each_TwitchIds;
                return output;
            }
        };

        struct TwitchPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string TwitchId;

            TwitchPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                TwitchId()
            {}

            TwitchPlayFabIdPair(const TwitchPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TwitchId(src.TwitchId)
            {}

            ~TwitchPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"TwitchId"], TwitchId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_TwitchId; ToJsonUtilS(TwitchId, each_TwitchId); output[L"TwitchId"] = each_TwitchId;
                return output;
            }
        };

        struct GetPlayFabIDsFromTwitchIDsResult : public PlayFabResultCommon
        {
            std::list<TwitchPlayFabIdPair> Data;

            GetPlayFabIDsFromTwitchIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromTwitchIDsResult(const GetPlayFabIDsFromTwitchIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromTwitchIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
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

        struct GetPurchaseRequest : public PlayFabRequestCommon
        {
            std::string OrderId;

            GetPurchaseRequest() :
                PlayFabRequestCommon(),
                OrderId()
            {}

            GetPurchaseRequest(const GetPurchaseRequest& src) :
                PlayFabRequestCommon(),
                OrderId(src.OrderId)
            {}

            ~GetPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"OrderId"], OrderId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                return output;
            }
        };

        struct GetPurchaseResult : public PlayFabResultCommon
        {
            std::string OrderId;
            std::string PaymentProvider;
            time_t PurchaseDate;
            std::string TransactionId;
            std::string TransactionStatus;

            GetPurchaseResult() :
                PlayFabResultCommon(),
                OrderId(),
                PaymentProvider(),
                PurchaseDate(),
                TransactionId(),
                TransactionStatus()
            {}

            GetPurchaseResult(const GetPurchaseResult& src) :
                PlayFabResultCommon(),
                OrderId(src.OrderId),
                PaymentProvider(src.PaymentProvider),
                PurchaseDate(src.PurchaseDate),
                TransactionId(src.TransactionId),
                TransactionStatus(src.TransactionStatus)
            {}

            ~GetPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"OrderId"], OrderId);
                FromJsonUtilS(input[L"PaymentProvider"], PaymentProvider);
                FromJsonUtilT(input[L"PurchaseDate"], PurchaseDate);
                FromJsonUtilS(input[L"TransactionId"], TransactionId);
                FromJsonUtilS(input[L"TransactionStatus"], TransactionStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                web::json::value each_PaymentProvider; ToJsonUtilS(PaymentProvider, each_PaymentProvider); output[L"PaymentProvider"] = each_PaymentProvider;
                web::json::value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output[L"PurchaseDate"] = each_PurchaseDate;
                web::json::value each_TransactionId; ToJsonUtilS(TransactionId, each_TransactionId); output[L"TransactionId"] = each_TransactionId;
                web::json::value each_TransactionStatus; ToJsonUtilS(TransactionStatus, each_TransactionStatus); output[L"TransactionStatus"] = each_TransactionStatus;
                return output;
            }
        };

        struct GetSharedGroupDataRequest : public PlayFabRequestCommon
        {
            Boxed<bool> GetMembers;
            std::list<std::string> Keys;
            std::string SharedGroupId;

            GetSharedGroupDataRequest() :
                PlayFabRequestCommon(),
                GetMembers(),
                Keys(),
                SharedGroupId()
            {}

            GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
                PlayFabRequestCommon(),
                GetMembers(src.GetMembers),
                Keys(src.Keys),
                SharedGroupId(src.SharedGroupId)
            {}

            ~GetSharedGroupDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"GetMembers"], GetMembers);
                FromJsonUtilS(input[L"Keys"], Keys);
                FromJsonUtilS(input[L"SharedGroupId"], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GetMembers; ToJsonUtilP(GetMembers, each_GetMembers); output[L"GetMembers"] = each_GetMembers;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[L"Keys"] = each_Keys;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[L"SharedGroupId"] = each_SharedGroupId;
                return output;
            }
        };

        struct SharedGroupDataRecord : public PlayFabBaseModel
        {
            time_t LastUpdated;
            std::string LastUpdatedBy;
            Boxed<UserDataPermission> Permission;
            std::string Value;

            SharedGroupDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(),
                LastUpdatedBy(),
                Permission(),
                Value()
            {}

            SharedGroupDataRecord(const SharedGroupDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                LastUpdatedBy(src.LastUpdatedBy),
                Permission(src.Permission),
                Value(src.Value)
            {}

            ~SharedGroupDataRecord() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"LastUpdated"], LastUpdated);
                FromJsonUtilS(input[L"LastUpdatedBy"], LastUpdatedBy);
                FromJsonUtilE(input[L"Permission"], Permission);
                FromJsonUtilS(input[L"Value"], Value);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LastUpdated; ToJsonUtilT(LastUpdated, each_LastUpdated); output[L"LastUpdated"] = each_LastUpdated;
                web::json::value each_LastUpdatedBy; ToJsonUtilS(LastUpdatedBy, each_LastUpdatedBy); output[L"LastUpdatedBy"] = each_LastUpdatedBy;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[L"Permission"] = each_Permission;
                web::json::value each_Value; ToJsonUtilS(Value, each_Value); output[L"Value"] = each_Value;
                return output;
            }
        };

        struct GetSharedGroupDataResult : public PlayFabResultCommon
        {
            std::map<std::string, SharedGroupDataRecord> Data;
            std::list<std::string> Members;

            GetSharedGroupDataResult() :
                PlayFabResultCommon(),
                Data(),
                Members()
            {}

            GetSharedGroupDataResult(const GetSharedGroupDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data),
                Members(src.Members)
            {}

            ~GetSharedGroupDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
                FromJsonUtilS(input[L"Members"], Members);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_Members; ToJsonUtilS(Members, each_Members); output[L"Members"] = each_Members;
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

        struct GetTimeRequest : public PlayFabRequestCommon
        {

            GetTimeRequest() :
                PlayFabRequestCommon()
            {}

            GetTimeRequest(const GetTimeRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetTimeRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetTimeResult : public PlayFabResultCommon
        {
            time_t Time;

            GetTimeResult() :
                PlayFabResultCommon(),
                Time()
            {}

            GetTimeResult(const GetTimeResult& src) :
                PlayFabResultCommon(),
                Time(src.Time)
            {}

            ~GetTimeResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[L"Time"], Time);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Time; ToJsonUtilT(Time, each_Time); output[L"Time"] = each_Time;
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

        struct GetTitleNewsRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> Count;

            GetTitleNewsRequest() :
                PlayFabRequestCommon(),
                Count()
            {}

            GetTitleNewsRequest(const GetTitleNewsRequest& src) :
                PlayFabRequestCommon(),
                Count(src.Count)
            {}

            ~GetTitleNewsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Count"], Count);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Count; ToJsonUtilP(Count, each_Count); output[L"Count"] = each_Count;
                return output;
            }
        };

        struct TitleNewsItem : public PlayFabBaseModel
        {
            std::string Body;
            std::string NewsId;
            time_t Timestamp;
            std::string Title;

            TitleNewsItem() :
                PlayFabBaseModel(),
                Body(),
                NewsId(),
                Timestamp(),
                Title()
            {}

            TitleNewsItem(const TitleNewsItem& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                NewsId(src.NewsId),
                Timestamp(src.Timestamp),
                Title(src.Title)
            {}

            ~TitleNewsItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Body"], Body);
                FromJsonUtilS(input[L"NewsId"], NewsId);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
                FromJsonUtilS(input[L"Title"], Title);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Body; ToJsonUtilS(Body, each_Body); output[L"Body"] = each_Body;
                web::json::value each_NewsId; ToJsonUtilS(NewsId, each_NewsId); output[L"NewsId"] = each_NewsId;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                web::json::value each_Title; ToJsonUtilS(Title, each_Title); output[L"Title"] = each_Title;
                return output;
            }
        };

        struct GetTitleNewsResult : public PlayFabResultCommon
        {
            std::list<TitleNewsItem> News;

            GetTitleNewsResult() :
                PlayFabResultCommon(),
                News()
            {}

            GetTitleNewsResult(const GetTitleNewsResult& src) :
                PlayFabResultCommon(),
                News(src.News)
            {}

            ~GetTitleNewsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"News"], News);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_News; ToJsonUtilO(News, each_News); output[L"News"] = each_News;
                return output;
            }
        };

        struct GetTitlePublicKeyRequest : public PlayFabRequestCommon
        {
            std::string TitleId;
            std::string TitleSharedSecret;

            GetTitlePublicKeyRequest() :
                PlayFabRequestCommon(),
                TitleId(),
                TitleSharedSecret()
            {}

            GetTitlePublicKeyRequest(const GetTitlePublicKeyRequest& src) :
                PlayFabRequestCommon(),
                TitleId(src.TitleId),
                TitleSharedSecret(src.TitleSharedSecret)
            {}

            ~GetTitlePublicKeyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"TitleId"], TitleId);
                FromJsonUtilS(input[L"TitleSharedSecret"], TitleSharedSecret);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                web::json::value each_TitleSharedSecret; ToJsonUtilS(TitleSharedSecret, each_TitleSharedSecret); output[L"TitleSharedSecret"] = each_TitleSharedSecret;
                return output;
            }
        };

        struct GetTitlePublicKeyResult : public PlayFabResultCommon
        {
            std::string RSAPublicKey;

            GetTitlePublicKeyResult() :
                PlayFabResultCommon(),
                RSAPublicKey()
            {}

            GetTitlePublicKeyResult(const GetTitlePublicKeyResult& src) :
                PlayFabResultCommon(),
                RSAPublicKey(src.RSAPublicKey)
            {}

            ~GetTitlePublicKeyResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"RSAPublicKey"], RSAPublicKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_RSAPublicKey; ToJsonUtilS(RSAPublicKey, each_RSAPublicKey); output[L"RSAPublicKey"] = each_RSAPublicKey;
                return output;
            }
        };

        struct GetTradeStatusRequest : public PlayFabRequestCommon
        {
            std::string OfferingPlayerId;
            std::string TradeId;

            GetTradeStatusRequest() :
                PlayFabRequestCommon(),
                OfferingPlayerId(),
                TradeId()
            {}

            GetTradeStatusRequest(const GetTradeStatusRequest& src) :
                PlayFabRequestCommon(),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
            {}

            ~GetTradeStatusRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"OfferingPlayerId"], OfferingPlayerId);
                FromJsonUtilS(input[L"TradeId"], TradeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output[L"OfferingPlayerId"] = each_OfferingPlayerId;
                web::json::value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output[L"TradeId"] = each_TradeId;
                return output;
            }
        };

        struct GetTradeStatusResponse : public PlayFabResultCommon
        {
            Boxed<TradeInfo> Trade;

            GetTradeStatusResponse() :
                PlayFabResultCommon(),
                Trade()
            {}

            GetTradeStatusResponse(const GetTradeStatusResponse& src) :
                PlayFabResultCommon(),
                Trade(src.Trade)
            {}

            ~GetTradeStatusResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Trade"], Trade);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Trade; ToJsonUtilO(Trade, each_Trade); output[L"Trade"] = each_Trade;
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

        struct GetUserDataResult : public PlayFabResultCommon
        {
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetUserDataResult() :
                PlayFabResultCommon(),
                Data(),
                DataVersion()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            ~GetUserDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Data"], Data);
                FromJsonUtilP(input[L"DataVersion"], DataVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[L"DataVersion"] = each_DataVersion;
                return output;
            }
        };

        struct GetUserInventoryRequest : public PlayFabRequestCommon
        {

            GetUserInventoryRequest() :
                PlayFabRequestCommon()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetUserInventoryRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetUserInventoryResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabResultCommon(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabResultCommon(),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~GetUserInventoryResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Inventory"], Inventory);
                FromJsonUtilP(input[L"VirtualCurrency"], VirtualCurrency);
                FromJsonUtilO(input[L"VirtualCurrencyRechargeTimes"], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[L"Inventory"] = each_Inventory;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[L"VirtualCurrencyRechargeTimes"] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GetWindowsHelloChallengeRequest : public PlayFabRequestCommon
        {
            std::string PublicKeyHint;
            std::string TitleId;

            GetWindowsHelloChallengeRequest() :
                PlayFabRequestCommon(),
                PublicKeyHint(),
                TitleId()
            {}

            GetWindowsHelloChallengeRequest(const GetWindowsHelloChallengeRequest& src) :
                PlayFabRequestCommon(),
                PublicKeyHint(src.PublicKeyHint),
                TitleId(src.TitleId)
            {}

            ~GetWindowsHelloChallengeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PublicKeyHint"], PublicKeyHint);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output[L"PublicKeyHint"] = each_PublicKeyHint;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct GetWindowsHelloChallengeResponse : public PlayFabResultCommon
        {
            std::string Challenge;

            GetWindowsHelloChallengeResponse() :
                PlayFabResultCommon(),
                Challenge()
            {}

            GetWindowsHelloChallengeResponse(const GetWindowsHelloChallengeResponse& src) :
                PlayFabResultCommon(),
                Challenge(src.Challenge)
            {}

            ~GetWindowsHelloChallengeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Challenge"], Challenge);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Challenge; ToJsonUtilS(Challenge, each_Challenge); output[L"Challenge"] = each_Challenge;
                return output;
            }
        };

        struct GrantCharacterToUserRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterName;
            std::string ItemId;

            GrantCharacterToUserRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterName(),
                ItemId()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterName(src.CharacterName),
                ItemId(src.ItemId)
            {}

            ~GrantCharacterToUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CharacterName"], CharacterName);
                FromJsonUtilS(input[L"ItemId"], ItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output[L"CharacterName"] = each_CharacterName;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                return output;
            }
        };

        struct GrantCharacterToUserResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::string CharacterType;
            bool Result;

            GrantCharacterToUserResult() :
                PlayFabResultCommon(),
                CharacterId(),
                CharacterType(),
                Result()
            {}

            GrantCharacterToUserResult(const GrantCharacterToUserResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                Result(src.Result)
            {}

            ~GrantCharacterToUserResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"CharacterType"], CharacterType);
                FromJsonUtilP(input[L"Result"], Result);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[L"CharacterType"] = each_CharacterType;
                web::json::value each_Result; ToJsonUtilP(Result, each_Result); output[L"Result"] = each_Result;
                return output;
            }
        };

        struct ItemPurchaseRequest : public PlayFabRequestCommon
        {
            std::string Annotation;
            std::string ItemId;
            Uint32 Quantity;
            std::list<std::string> UpgradeFromItems;

            ItemPurchaseRequest() :
                PlayFabRequestCommon(),
                Annotation(),
                ItemId(),
                Quantity(),
                UpgradeFromItems()
            {}

            ItemPurchaseRequest(const ItemPurchaseRequest& src) :
                PlayFabRequestCommon(),
                Annotation(src.Annotation),
                ItemId(src.ItemId),
                Quantity(src.Quantity),
                UpgradeFromItems(src.UpgradeFromItems)
            {}

            ~ItemPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Annotation"], Annotation);
                FromJsonUtilS(input[L"ItemId"], ItemId);
                FromJsonUtilP(input[L"Quantity"], Quantity);
                FromJsonUtilS(input[L"UpgradeFromItems"], UpgradeFromItems);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output[L"Annotation"] = each_Annotation;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                web::json::value each_Quantity; ToJsonUtilP(Quantity, each_Quantity); output[L"Quantity"] = each_Quantity;
                web::json::value each_UpgradeFromItems; ToJsonUtilS(UpgradeFromItems, each_UpgradeFromItems); output[L"UpgradeFromItems"] = each_UpgradeFromItems;
                return output;
            }
        };

        struct LinkAndroidDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string AndroidDevice;
            std::string AndroidDeviceId;
            Boxed<bool> ForceLink;
            std::string OS;

            LinkAndroidDeviceIDRequest() :
                PlayFabRequestCommon(),
                AndroidDevice(),
                AndroidDeviceId(),
                ForceLink(),
                OS()
            {}

            LinkAndroidDeviceIDRequest(const LinkAndroidDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                AndroidDevice(src.AndroidDevice),
                AndroidDeviceId(src.AndroidDeviceId),
                ForceLink(src.ForceLink),
                OS(src.OS)
            {}

            ~LinkAndroidDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AndroidDevice"], AndroidDevice);
                FromJsonUtilS(input[L"AndroidDeviceId"], AndroidDeviceId);
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"OS"], OS);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDevice; ToJsonUtilS(AndroidDevice, each_AndroidDevice); output[L"AndroidDevice"] = each_AndroidDevice;
                web::json::value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output[L"AndroidDeviceId"] = each_AndroidDeviceId;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_OS; ToJsonUtilS(OS, each_OS); output[L"OS"] = each_OS;
                return output;
            }
        };

        struct LinkAndroidDeviceIDResult : public PlayFabResultCommon
        {

            LinkAndroidDeviceIDResult() :
                PlayFabResultCommon()
            {}

            LinkAndroidDeviceIDResult(const LinkAndroidDeviceIDResult&) :
                PlayFabResultCommon()
            {}

            ~LinkAndroidDeviceIDResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkCustomIDRequest : public PlayFabRequestCommon
        {
            std::string CustomId;
            Boxed<bool> ForceLink;

            LinkCustomIDRequest() :
                PlayFabRequestCommon(),
                CustomId(),
                ForceLink()
            {}

            LinkCustomIDRequest(const LinkCustomIDRequest& src) :
                PlayFabRequestCommon(),
                CustomId(src.CustomId),
                ForceLink(src.ForceLink)
            {}

            ~LinkCustomIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CustomId"], CustomId);
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output[L"CustomId"] = each_CustomId;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                return output;
            }
        };

        struct LinkCustomIDResult : public PlayFabResultCommon
        {

            LinkCustomIDResult() :
                PlayFabResultCommon()
            {}

            LinkCustomIDResult(const LinkCustomIDResult&) :
                PlayFabResultCommon()
            {}

            ~LinkCustomIDResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkFacebookAccountRequest : public PlayFabRequestCommon
        {
            std::string AccessToken;
            Boxed<bool> ForceLink;

            LinkFacebookAccountRequest() :
                PlayFabRequestCommon(),
                AccessToken(),
                ForceLink()
            {}

            LinkFacebookAccountRequest(const LinkFacebookAccountRequest& src) :
                PlayFabRequestCommon(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            ~LinkFacebookAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AccessToken"], AccessToken);
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output[L"AccessToken"] = each_AccessToken;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                return output;
            }
        };

        struct LinkFacebookAccountResult : public PlayFabResultCommon
        {

            LinkFacebookAccountResult() :
                PlayFabResultCommon()
            {}

            LinkFacebookAccountResult(const LinkFacebookAccountResult&) :
                PlayFabResultCommon()
            {}

            ~LinkFacebookAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkFacebookInstantGamesIdRequest : public PlayFabRequestCommon
        {
            std::string FacebookInstantGamesSignature;
            Boxed<bool> ForceLink;

            LinkFacebookInstantGamesIdRequest() :
                PlayFabRequestCommon(),
                FacebookInstantGamesSignature(),
                ForceLink()
            {}

            LinkFacebookInstantGamesIdRequest(const LinkFacebookInstantGamesIdRequest& src) :
                PlayFabRequestCommon(),
                FacebookInstantGamesSignature(src.FacebookInstantGamesSignature),
                ForceLink(src.ForceLink)
            {}

            ~LinkFacebookInstantGamesIdRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FacebookInstantGamesSignature"], FacebookInstantGamesSignature);
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookInstantGamesSignature; ToJsonUtilS(FacebookInstantGamesSignature, each_FacebookInstantGamesSignature); output[L"FacebookInstantGamesSignature"] = each_FacebookInstantGamesSignature;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                return output;
            }
        };

        struct LinkFacebookInstantGamesIdResult : public PlayFabResultCommon
        {

            LinkFacebookInstantGamesIdResult() :
                PlayFabResultCommon()
            {}

            LinkFacebookInstantGamesIdResult(const LinkFacebookInstantGamesIdResult&) :
                PlayFabResultCommon()
            {}

            ~LinkFacebookInstantGamesIdResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkGameCenterAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> ForceLink;
            std::string GameCenterId;

            LinkGameCenterAccountRequest() :
                PlayFabRequestCommon(),
                ForceLink(),
                GameCenterId()
            {}

            LinkGameCenterAccountRequest(const LinkGameCenterAccountRequest& src) :
                PlayFabRequestCommon(),
                ForceLink(src.ForceLink),
                GameCenterId(src.GameCenterId)
            {}

            ~LinkGameCenterAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"GameCenterId"], GameCenterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output[L"GameCenterId"] = each_GameCenterId;
                return output;
            }
        };

        struct LinkGameCenterAccountResult : public PlayFabResultCommon
        {

            LinkGameCenterAccountResult() :
                PlayFabResultCommon()
            {}

            LinkGameCenterAccountResult(const LinkGameCenterAccountResult&) :
                PlayFabResultCommon()
            {}

            ~LinkGameCenterAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkGoogleAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> ForceLink;
            std::string ServerAuthCode;

            LinkGoogleAccountRequest() :
                PlayFabRequestCommon(),
                ForceLink(),
                ServerAuthCode()
            {}

            LinkGoogleAccountRequest(const LinkGoogleAccountRequest& src) :
                PlayFabRequestCommon(),
                ForceLink(src.ForceLink),
                ServerAuthCode(src.ServerAuthCode)
            {}

            ~LinkGoogleAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"ServerAuthCode"], ServerAuthCode);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_ServerAuthCode; ToJsonUtilS(ServerAuthCode, each_ServerAuthCode); output[L"ServerAuthCode"] = each_ServerAuthCode;
                return output;
            }
        };

        struct LinkGoogleAccountResult : public PlayFabResultCommon
        {

            LinkGoogleAccountResult() :
                PlayFabResultCommon()
            {}

            LinkGoogleAccountResult(const LinkGoogleAccountResult&) :
                PlayFabResultCommon()
            {}

            ~LinkGoogleAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkIOSDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string DeviceId;
            std::string DeviceModel;
            Boxed<bool> ForceLink;
            std::string OS;

            LinkIOSDeviceIDRequest() :
                PlayFabRequestCommon(),
                DeviceId(),
                DeviceModel(),
                ForceLink(),
                OS()
            {}

            LinkIOSDeviceIDRequest(const LinkIOSDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                DeviceId(src.DeviceId),
                DeviceModel(src.DeviceModel),
                ForceLink(src.ForceLink),
                OS(src.OS)
            {}

            ~LinkIOSDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DeviceId"], DeviceId);
                FromJsonUtilS(input[L"DeviceModel"], DeviceModel);
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"OS"], OS);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output[L"DeviceId"] = each_DeviceId;
                web::json::value each_DeviceModel; ToJsonUtilS(DeviceModel, each_DeviceModel); output[L"DeviceModel"] = each_DeviceModel;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_OS; ToJsonUtilS(OS, each_OS); output[L"OS"] = each_OS;
                return output;
            }
        };

        struct LinkIOSDeviceIDResult : public PlayFabResultCommon
        {

            LinkIOSDeviceIDResult() :
                PlayFabResultCommon()
            {}

            LinkIOSDeviceIDResult(const LinkIOSDeviceIDResult&) :
                PlayFabResultCommon()
            {}

            ~LinkIOSDeviceIDResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkKongregateAccountRequest : public PlayFabRequestCommon
        {
            std::string AuthTicket;
            Boxed<bool> ForceLink;
            std::string KongregateId;

            LinkKongregateAccountRequest() :
                PlayFabRequestCommon(),
                AuthTicket(),
                ForceLink(),
                KongregateId()
            {}

            LinkKongregateAccountRequest(const LinkKongregateAccountRequest& src) :
                PlayFabRequestCommon(),
                AuthTicket(src.AuthTicket),
                ForceLink(src.ForceLink),
                KongregateId(src.KongregateId)
            {}

            ~LinkKongregateAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AuthTicket"], AuthTicket);
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"KongregateId"], KongregateId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AuthTicket; ToJsonUtilS(AuthTicket, each_AuthTicket); output[L"AuthTicket"] = each_AuthTicket;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output[L"KongregateId"] = each_KongregateId;
                return output;
            }
        };

        struct LinkKongregateAccountResult : public PlayFabResultCommon
        {

            LinkKongregateAccountResult() :
                PlayFabResultCommon()
            {}

            LinkKongregateAccountResult(const LinkKongregateAccountResult&) :
                PlayFabResultCommon()
            {}

            ~LinkKongregateAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkNintendoSwitchDeviceIdRequest : public PlayFabRequestCommon
        {
            Boxed<bool> ForceLink;
            std::string NintendoSwitchDeviceId;

            LinkNintendoSwitchDeviceIdRequest() :
                PlayFabRequestCommon(),
                ForceLink(),
                NintendoSwitchDeviceId()
            {}

            LinkNintendoSwitchDeviceIdRequest(const LinkNintendoSwitchDeviceIdRequest& src) :
                PlayFabRequestCommon(),
                ForceLink(src.ForceLink),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId)
            {}

            ~LinkNintendoSwitchDeviceIdRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output[L"NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
                return output;
            }
        };

        struct LinkNintendoSwitchDeviceIdResult : public PlayFabResultCommon
        {

            LinkNintendoSwitchDeviceIdResult() :
                PlayFabResultCommon()
            {}

            LinkNintendoSwitchDeviceIdResult(const LinkNintendoSwitchDeviceIdResult&) :
                PlayFabResultCommon()
            {}

            ~LinkNintendoSwitchDeviceIdResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkSteamAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> ForceLink;
            std::string SteamTicket;

            LinkSteamAccountRequest() :
                PlayFabRequestCommon(),
                ForceLink(),
                SteamTicket()
            {}

            LinkSteamAccountRequest(const LinkSteamAccountRequest& src) :
                PlayFabRequestCommon(),
                ForceLink(src.ForceLink),
                SteamTicket(src.SteamTicket)
            {}

            ~LinkSteamAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"SteamTicket"], SteamTicket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_SteamTicket; ToJsonUtilS(SteamTicket, each_SteamTicket); output[L"SteamTicket"] = each_SteamTicket;
                return output;
            }
        };

        struct LinkSteamAccountResult : public PlayFabResultCommon
        {

            LinkSteamAccountResult() :
                PlayFabResultCommon()
            {}

            LinkSteamAccountResult(const LinkSteamAccountResult&) :
                PlayFabResultCommon()
            {}

            ~LinkSteamAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkTwitchAccountRequest : public PlayFabRequestCommon
        {
            std::string AccessToken;
            Boxed<bool> ForceLink;

            LinkTwitchAccountRequest() :
                PlayFabRequestCommon(),
                AccessToken(),
                ForceLink()
            {}

            LinkTwitchAccountRequest(const LinkTwitchAccountRequest& src) :
                PlayFabRequestCommon(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            ~LinkTwitchAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AccessToken"], AccessToken);
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output[L"AccessToken"] = each_AccessToken;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                return output;
            }
        };

        struct LinkTwitchAccountResult : public PlayFabResultCommon
        {

            LinkTwitchAccountResult() :
                PlayFabResultCommon()
            {}

            LinkTwitchAccountResult(const LinkTwitchAccountResult&) :
                PlayFabResultCommon()
            {}

            ~LinkTwitchAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkWindowsHelloAccountRequest : public PlayFabRequestCommon
        {
            std::string DeviceName;
            Boxed<bool> ForceLink;
            std::string PublicKey;
            std::string UserName;

            LinkWindowsHelloAccountRequest() :
                PlayFabRequestCommon(),
                DeviceName(),
                ForceLink(),
                PublicKey(),
                UserName()
            {}

            LinkWindowsHelloAccountRequest(const LinkWindowsHelloAccountRequest& src) :
                PlayFabRequestCommon(),
                DeviceName(src.DeviceName),
                ForceLink(src.ForceLink),
                PublicKey(src.PublicKey),
                UserName(src.UserName)
            {}

            ~LinkWindowsHelloAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DeviceName"], DeviceName);
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"PublicKey"], PublicKey);
                FromJsonUtilS(input[L"UserName"], UserName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeviceName; ToJsonUtilS(DeviceName, each_DeviceName); output[L"DeviceName"] = each_DeviceName;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_PublicKey; ToJsonUtilS(PublicKey, each_PublicKey); output[L"PublicKey"] = each_PublicKey;
                web::json::value each_UserName; ToJsonUtilS(UserName, each_UserName); output[L"UserName"] = each_UserName;
                return output;
            }
        };

        struct LinkWindowsHelloAccountResponse : public PlayFabResultCommon
        {

            LinkWindowsHelloAccountResponse() :
                PlayFabResultCommon()
            {}

            LinkWindowsHelloAccountResponse(const LinkWindowsHelloAccountResponse&) :
                PlayFabResultCommon()
            {}

            ~LinkWindowsHelloAccountResponse() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkXboxAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> ForceLink;
            std::string XboxToken;

            LinkXboxAccountRequest() :
                PlayFabRequestCommon(),
                ForceLink(),
                XboxToken()
            {}

            LinkXboxAccountRequest(const LinkXboxAccountRequest& src) :
                PlayFabRequestCommon(),
                ForceLink(src.ForceLink),
                XboxToken(src.XboxToken)
            {}

            ~LinkXboxAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"ForceLink"], ForceLink);
                FromJsonUtilS(input[L"XboxToken"], XboxToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[L"ForceLink"] = each_ForceLink;
                web::json::value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output[L"XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct LinkXboxAccountResult : public PlayFabResultCommon
        {

            LinkXboxAccountResult() :
                PlayFabResultCommon()
            {}

            LinkXboxAccountResult(const LinkXboxAccountResult&) :
                PlayFabResultCommon()
            {}

            ~LinkXboxAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ListUsersCharactersRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            ListUsersCharactersRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            ListUsersCharactersRequest(const ListUsersCharactersRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~ListUsersCharactersRequest() { }

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

        struct ListUsersCharactersResult : public PlayFabResultCommon
        {
            std::list<CharacterResult> Characters;

            ListUsersCharactersResult() :
                PlayFabResultCommon(),
                Characters()
            {}

            ListUsersCharactersResult(const ListUsersCharactersResult& src) :
                PlayFabResultCommon(),
                Characters(src.Characters)
            {}

            ~ListUsersCharactersResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Characters"], Characters);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Characters; ToJsonUtilO(Characters, each_Characters); output[L"Characters"] = each_Characters;
                return output;
            }
        };

        struct UserSettings : public PlayFabBaseModel
        {
            bool GatherDeviceInfo;
            bool GatherFocusInfo;
            bool NeedsAttribution;

            UserSettings() :
                PlayFabBaseModel(),
                GatherDeviceInfo(),
                GatherFocusInfo(),
                NeedsAttribution()
            {}

            UserSettings(const UserSettings& src) :
                PlayFabBaseModel(),
                GatherDeviceInfo(src.GatherDeviceInfo),
                GatherFocusInfo(src.GatherFocusInfo),
                NeedsAttribution(src.NeedsAttribution)
            {}

            ~UserSettings() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"GatherDeviceInfo"], GatherDeviceInfo);
                FromJsonUtilP(input[L"GatherFocusInfo"], GatherFocusInfo);
                FromJsonUtilP(input[L"NeedsAttribution"], NeedsAttribution);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GatherDeviceInfo; ToJsonUtilP(GatherDeviceInfo, each_GatherDeviceInfo); output[L"GatherDeviceInfo"] = each_GatherDeviceInfo;
                web::json::value each_GatherFocusInfo; ToJsonUtilP(GatherFocusInfo, each_GatherFocusInfo); output[L"GatherFocusInfo"] = each_GatherFocusInfo;
                web::json::value each_NeedsAttribution; ToJsonUtilP(NeedsAttribution, each_NeedsAttribution); output[L"NeedsAttribution"] = each_NeedsAttribution;
                return output;
            }
        };

        struct LoginResult : public PlayFabResultCommon
        {
            Boxed<EntityTokenResponse> EntityToken;
            Boxed<GetPlayerCombinedInfoResultPayload> InfoResultPayload;
            Boxed<time_t> LastLoginTime;
            bool NewlyCreated;
            std::string PlayFabId;
            std::string SessionTicket;
            Boxed<UserSettings> SettingsForUser;

            LoginResult() :
                PlayFabResultCommon(),
                EntityToken(),
                InfoResultPayload(),
                LastLoginTime(),
                NewlyCreated(),
                PlayFabId(),
                SessionTicket(),
                SettingsForUser()
            {}

            LoginResult(const LoginResult& src) :
                PlayFabResultCommon(),
                EntityToken(src.EntityToken),
                InfoResultPayload(src.InfoResultPayload),
                LastLoginTime(src.LastLoginTime),
                NewlyCreated(src.NewlyCreated),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                SettingsForUser(src.SettingsForUser)
            {}

            ~LoginResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"EntityToken"], EntityToken);
                FromJsonUtilO(input[L"InfoResultPayload"], InfoResultPayload);
                FromJsonUtilT(input[L"LastLoginTime"], LastLoginTime);
                FromJsonUtilP(input[L"NewlyCreated"], NewlyCreated);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"SessionTicket"], SessionTicket);
                FromJsonUtilO(input[L"SettingsForUser"], SettingsForUser);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EntityToken; ToJsonUtilO(EntityToken, each_EntityToken); output[L"EntityToken"] = each_EntityToken;
                web::json::value each_InfoResultPayload; ToJsonUtilO(InfoResultPayload, each_InfoResultPayload); output[L"InfoResultPayload"] = each_InfoResultPayload;
                web::json::value each_LastLoginTime; ToJsonUtilT(LastLoginTime, each_LastLoginTime); output[L"LastLoginTime"] = each_LastLoginTime;
                web::json::value each_NewlyCreated; ToJsonUtilP(NewlyCreated, each_NewlyCreated); output[L"NewlyCreated"] = each_NewlyCreated;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_SessionTicket; ToJsonUtilS(SessionTicket, each_SessionTicket); output[L"SessionTicket"] = each_SessionTicket;
                web::json::value each_SettingsForUser; ToJsonUtilO(SettingsForUser, each_SettingsForUser); output[L"SettingsForUser"] = each_SettingsForUser;
                return output;
            }
        };

        struct LoginWithAndroidDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string AndroidDevice;
            std::string AndroidDeviceId;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string OS;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithAndroidDeviceIDRequest() :
                PlayFabRequestCommon(),
                AndroidDevice(),
                AndroidDeviceId(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                OS(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithAndroidDeviceIDRequest(const LoginWithAndroidDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                AndroidDevice(src.AndroidDevice),
                AndroidDeviceId(src.AndroidDeviceId),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                OS(src.OS),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithAndroidDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AndroidDevice"], AndroidDevice);
                FromJsonUtilS(input[L"AndroidDeviceId"], AndroidDeviceId);
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"OS"], OS);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDevice; ToJsonUtilS(AndroidDevice, each_AndroidDevice); output[L"AndroidDevice"] = each_AndroidDevice;
                web::json::value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output[L"AndroidDeviceId"] = each_AndroidDeviceId;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_OS; ToJsonUtilS(OS, each_OS); output[L"OS"] = each_OS;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithCustomIDRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string CustomId;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithCustomIDRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                CustomId(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithCustomIDRequest(const LoginWithCustomIDRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                CustomId(src.CustomId),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithCustomIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"CustomId"], CustomId);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output[L"CustomId"] = each_CustomId;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithEmailAddressRequest : public PlayFabRequestCommon
        {
            std::string Email;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string Password;
            std::string TitleId;

            LoginWithEmailAddressRequest() :
                PlayFabRequestCommon(),
                Email(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                Password(),
                TitleId()
            {}

            LoginWithEmailAddressRequest(const LoginWithEmailAddressRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                TitleId(src.TitleId)
            {}

            ~LoginWithEmailAddressRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Email"], Email);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"Password"], Password);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[L"Password"] = each_Password;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithFacebookInstantGamesIdRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            std::string FacebookInstantGamesSignature;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithFacebookInstantGamesIdRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                FacebookInstantGamesSignature(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithFacebookInstantGamesIdRequest(const LoginWithFacebookInstantGamesIdRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                FacebookInstantGamesSignature(src.FacebookInstantGamesSignature),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithFacebookInstantGamesIdRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilS(input[L"FacebookInstantGamesSignature"], FacebookInstantGamesSignature);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_FacebookInstantGamesSignature; ToJsonUtilS(FacebookInstantGamesSignature, each_FacebookInstantGamesSignature); output[L"FacebookInstantGamesSignature"] = each_FacebookInstantGamesSignature;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithFacebookRequest : public PlayFabRequestCommon
        {
            std::string AccessToken;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithFacebookRequest() :
                PlayFabRequestCommon(),
                AccessToken(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithFacebookRequest(const LoginWithFacebookRequest& src) :
                PlayFabRequestCommon(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithFacebookRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AccessToken"], AccessToken);
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output[L"AccessToken"] = each_AccessToken;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithGameCenterRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerId;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithGameCenterRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerId(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithGameCenterRequest(const LoginWithGameCenterRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerId(src.PlayerId),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithGameCenterRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerId"], PlayerId);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output[L"PlayerId"] = each_PlayerId;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithGoogleAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string ServerAuthCode;
            std::string TitleId;

            LoginWithGoogleAccountRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                ServerAuthCode(),
                TitleId()
            {}

            LoginWithGoogleAccountRequest(const LoginWithGoogleAccountRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                ServerAuthCode(src.ServerAuthCode),
                TitleId(src.TitleId)
            {}

            ~LoginWithGoogleAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"ServerAuthCode"], ServerAuthCode);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_ServerAuthCode; ToJsonUtilS(ServerAuthCode, each_ServerAuthCode); output[L"ServerAuthCode"] = each_ServerAuthCode;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithIOSDeviceIDRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string DeviceId;
            std::string DeviceModel;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string OS;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithIOSDeviceIDRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                DeviceId(),
                DeviceModel(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                OS(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithIOSDeviceIDRequest(const LoginWithIOSDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                DeviceId(src.DeviceId),
                DeviceModel(src.DeviceModel),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                OS(src.OS),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithIOSDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"DeviceId"], DeviceId);
                FromJsonUtilS(input[L"DeviceModel"], DeviceModel);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"OS"], OS);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output[L"DeviceId"] = each_DeviceId;
                web::json::value each_DeviceModel; ToJsonUtilS(DeviceModel, each_DeviceModel); output[L"DeviceModel"] = each_DeviceModel;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_OS; ToJsonUtilS(OS, each_OS); output[L"OS"] = each_OS;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithKongregateRequest : public PlayFabRequestCommon
        {
            std::string AuthTicket;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            std::string KongregateId;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithKongregateRequest() :
                PlayFabRequestCommon(),
                AuthTicket(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                KongregateId(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithKongregateRequest(const LoginWithKongregateRequest& src) :
                PlayFabRequestCommon(),
                AuthTicket(src.AuthTicket),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                KongregateId(src.KongregateId),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithKongregateRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AuthTicket"], AuthTicket);
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilS(input[L"KongregateId"], KongregateId);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AuthTicket; ToJsonUtilS(AuthTicket, each_AuthTicket); output[L"AuthTicket"] = each_AuthTicket;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output[L"KongregateId"] = each_KongregateId;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithNintendoSwitchDeviceIdRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string NintendoSwitchDeviceId;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithNintendoSwitchDeviceIdRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                NintendoSwitchDeviceId(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithNintendoSwitchDeviceIdRequest(const LoginWithNintendoSwitchDeviceIdRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithNintendoSwitchDeviceIdRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output[L"NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithPlayFabRequest : public PlayFabRequestCommon
        {
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string Password;
            std::string TitleId;
            std::string Username;

            LoginWithPlayFabRequest() :
                PlayFabRequestCommon(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                Password(),
                TitleId(),
                Username()
            {}

            LoginWithPlayFabRequest(const LoginWithPlayFabRequest& src) :
                PlayFabRequestCommon(),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                TitleId(src.TitleId),
                Username(src.Username)
            {}

            ~LoginWithPlayFabRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"Password"], Password);
                FromJsonUtilS(input[L"TitleId"], TitleId);
                FromJsonUtilS(input[L"Username"], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[L"Password"] = each_Password;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                return output;
            }
        };

        struct LoginWithSteamRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string SteamTicket;
            std::string TitleId;

            LoginWithSteamRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                SteamTicket(),
                TitleId()
            {}

            LoginWithSteamRequest(const LoginWithSteamRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                SteamTicket(src.SteamTicket),
                TitleId(src.TitleId)
            {}

            ~LoginWithSteamRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"SteamTicket"], SteamTicket);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_SteamTicket; ToJsonUtilS(SteamTicket, each_SteamTicket); output[L"SteamTicket"] = each_SteamTicket;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithTwitchRequest : public PlayFabRequestCommon
        {
            std::string AccessToken;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithTwitchRequest() :
                PlayFabRequestCommon(),
                AccessToken(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithTwitchRequest(const LoginWithTwitchRequest& src) :
                PlayFabRequestCommon(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithTwitchRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AccessToken"], AccessToken);
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output[L"AccessToken"] = each_AccessToken;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithWindowsHelloRequest : public PlayFabRequestCommon
        {
            std::string ChallengeSignature;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PublicKeyHint;
            std::string TitleId;

            LoginWithWindowsHelloRequest() :
                PlayFabRequestCommon(),
                ChallengeSignature(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PublicKeyHint(),
                TitleId()
            {}

            LoginWithWindowsHelloRequest(const LoginWithWindowsHelloRequest& src) :
                PlayFabRequestCommon(),
                ChallengeSignature(src.ChallengeSignature),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PublicKeyHint(src.PublicKeyHint),
                TitleId(src.TitleId)
            {}

            ~LoginWithWindowsHelloRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ChallengeSignature"], ChallengeSignature);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PublicKeyHint"], PublicKeyHint);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ChallengeSignature; ToJsonUtilS(ChallengeSignature, each_ChallengeSignature); output[L"ChallengeSignature"] = each_ChallengeSignature;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output[L"PublicKeyHint"] = each_PublicKeyHint;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithXboxRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;
            std::string XboxToken;

            LoginWithXboxRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId(),
                XboxToken()
            {}

            LoginWithXboxRequest(const LoginWithXboxRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId),
                XboxToken(src.XboxToken)
            {}

            ~LoginWithXboxRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreateAccount"], CreateAccount);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"TitleId"], TitleId);
                FromJsonUtilS(input[L"XboxToken"], XboxToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[L"CreateAccount"] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                web::json::value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output[L"XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct MatchmakeRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::string CharacterId;
            std::string GameMode;
            std::string LobbyId;
            Boxed<Region> pfRegion;
            Boxed<bool> StartNewIfNoneFound;
            std::string StatisticName;
            Boxed<CollectionFilter> TagFilter;

            MatchmakeRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                CharacterId(),
                GameMode(),
                LobbyId(),
                pfRegion(),
                StartNewIfNoneFound(),
                StatisticName(),
                TagFilter()
            {}

            MatchmakeRequest(const MatchmakeRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                CharacterId(src.CharacterId),
                GameMode(src.GameMode),
                LobbyId(src.LobbyId),
                pfRegion(src.pfRegion),
                StartNewIfNoneFound(src.StartNewIfNoneFound),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter)
            {}

            ~MatchmakeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildVersion"], BuildVersion);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"GameMode"], GameMode);
                FromJsonUtilS(input[L"LobbyId"], LobbyId);
                FromJsonUtilE(input[L"pfRegion"], pfRegion);
                FromJsonUtilP(input[L"StartNewIfNoneFound"], StartNewIfNoneFound);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilO(input[L"TagFilter"], TagFilter);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[L"BuildVersion"] = each_BuildVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[L"GameMode"] = each_GameMode;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[L"LobbyId"] = each_LobbyId;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[L"Region"] = each_pfRegion;
                web::json::value each_StartNewIfNoneFound; ToJsonUtilP(StartNewIfNoneFound, each_StartNewIfNoneFound); output[L"StartNewIfNoneFound"] = each_StartNewIfNoneFound;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_TagFilter; ToJsonUtilO(TagFilter, each_TagFilter); output[L"TagFilter"] = each_TagFilter;
                return output;
            }
        };

        struct MatchmakeResult : public PlayFabResultCommon
        {
            std::string Expires;
            std::string LobbyID;
            Boxed<Int32> PollWaitTimeMS;
            std::string ServerHostname;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            Boxed<Int32> ServerPort;
            std::string ServerPublicDNSName;
            Boxed<MatchmakeStatus> Status;
            std::string Ticket;

            MatchmakeResult() :
                PlayFabResultCommon(),
                Expires(),
                LobbyID(),
                PollWaitTimeMS(),
                ServerHostname(),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(),
                ServerPublicDNSName(),
                Status(),
                Ticket()
            {}

            MatchmakeResult(const MatchmakeResult& src) :
                PlayFabResultCommon(),
                Expires(src.Expires),
                LobbyID(src.LobbyID),
                PollWaitTimeMS(src.PollWaitTimeMS),
                ServerHostname(src.ServerHostname),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                Status(src.Status),
                Ticket(src.Ticket)
            {}

            ~MatchmakeResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Expires"], Expires);
                FromJsonUtilS(input[L"LobbyID"], LobbyID);
                FromJsonUtilP(input[L"PollWaitTimeMS"], PollWaitTimeMS);
                FromJsonUtilS(input[L"ServerHostname"], ServerHostname);
                FromJsonUtilS(input[L"ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input[L"ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input[L"ServerPort"], ServerPort);
                FromJsonUtilS(input[L"ServerPublicDNSName"], ServerPublicDNSName);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilS(input[L"Ticket"], Ticket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expires; ToJsonUtilS(Expires, each_Expires); output[L"Expires"] = each_Expires;
                web::json::value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output[L"LobbyID"] = each_LobbyID;
                web::json::value each_PollWaitTimeMS; ToJsonUtilP(PollWaitTimeMS, each_PollWaitTimeMS); output[L"PollWaitTimeMS"] = each_PollWaitTimeMS;
                web::json::value each_ServerHostname; ToJsonUtilS(ServerHostname, each_ServerHostname); output[L"ServerHostname"] = each_ServerHostname;
                web::json::value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output[L"ServerIPV4Address"] = each_ServerIPV4Address;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[L"ServerIPV6Address"] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[L"ServerPort"] = each_ServerPort;
                web::json::value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output[L"ServerPublicDNSName"] = each_ServerPublicDNSName;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_Ticket; ToJsonUtilS(Ticket, each_Ticket); output[L"Ticket"] = each_Ticket;
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

        struct OpenTradeRequest : public PlayFabRequestCommon
        {
            std::list<std::string> AllowedPlayerIds;
            std::list<std::string> OfferedInventoryInstanceIds;
            std::list<std::string> RequestedCatalogItemIds;

            OpenTradeRequest() :
                PlayFabRequestCommon(),
                AllowedPlayerIds(),
                OfferedInventoryInstanceIds(),
                RequestedCatalogItemIds()
            {}

            OpenTradeRequest(const OpenTradeRequest& src) :
                PlayFabRequestCommon(),
                AllowedPlayerIds(src.AllowedPlayerIds),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds)
            {}

            ~OpenTradeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AllowedPlayerIds"], AllowedPlayerIds);
                FromJsonUtilS(input[L"OfferedInventoryInstanceIds"], OfferedInventoryInstanceIds);
                FromJsonUtilS(input[L"RequestedCatalogItemIds"], RequestedCatalogItemIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AllowedPlayerIds; ToJsonUtilS(AllowedPlayerIds, each_AllowedPlayerIds); output[L"AllowedPlayerIds"] = each_AllowedPlayerIds;
                web::json::value each_OfferedInventoryInstanceIds; ToJsonUtilS(OfferedInventoryInstanceIds, each_OfferedInventoryInstanceIds); output[L"OfferedInventoryInstanceIds"] = each_OfferedInventoryInstanceIds;
                web::json::value each_RequestedCatalogItemIds; ToJsonUtilS(RequestedCatalogItemIds, each_RequestedCatalogItemIds); output[L"RequestedCatalogItemIds"] = each_RequestedCatalogItemIds;
                return output;
            }
        };

        struct OpenTradeResponse : public PlayFabResultCommon
        {
            Boxed<TradeInfo> Trade;

            OpenTradeResponse() :
                PlayFabResultCommon(),
                Trade()
            {}

            OpenTradeResponse(const OpenTradeResponse& src) :
                PlayFabResultCommon(),
                Trade(src.Trade)
            {}

            ~OpenTradeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Trade"], Trade);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Trade; ToJsonUtilO(Trade, each_Trade); output[L"Trade"] = each_Trade;
                return output;
            }
        };

        struct PayForPurchaseRequest : public PlayFabRequestCommon
        {
            std::string Currency;
            std::string OrderId;
            std::string ProviderName;
            std::string ProviderTransactionId;

            PayForPurchaseRequest() :
                PlayFabRequestCommon(),
                Currency(),
                OrderId(),
                ProviderName(),
                ProviderTransactionId()
            {}

            PayForPurchaseRequest(const PayForPurchaseRequest& src) :
                PlayFabRequestCommon(),
                Currency(src.Currency),
                OrderId(src.OrderId),
                ProviderName(src.ProviderName),
                ProviderTransactionId(src.ProviderTransactionId)
            {}

            ~PayForPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Currency"], Currency);
                FromJsonUtilS(input[L"OrderId"], OrderId);
                FromJsonUtilS(input[L"ProviderName"], ProviderName);
                FromJsonUtilS(input[L"ProviderTransactionId"], ProviderTransactionId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Currency; ToJsonUtilS(Currency, each_Currency); output[L"Currency"] = each_Currency;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                web::json::value each_ProviderName; ToJsonUtilS(ProviderName, each_ProviderName); output[L"ProviderName"] = each_ProviderName;
                web::json::value each_ProviderTransactionId; ToJsonUtilS(ProviderTransactionId, each_ProviderTransactionId); output[L"ProviderTransactionId"] = each_ProviderTransactionId;
                return output;
            }
        };

        struct PayForPurchaseResult : public PlayFabResultCommon
        {
            Uint32 CreditApplied;
            std::string OrderId;
            std::string ProviderData;
            std::string ProviderToken;
            std::string PurchaseConfirmationPageURL;
            std::string PurchaseCurrency;
            Uint32 PurchasePrice;
            Boxed<TransactionStatus> Status;
            std::map<std::string, Int32> VCAmount;
            std::map<std::string, Int32> VirtualCurrency;

            PayForPurchaseResult() :
                PlayFabResultCommon(),
                CreditApplied(),
                OrderId(),
                ProviderData(),
                ProviderToken(),
                PurchaseConfirmationPageURL(),
                PurchaseCurrency(),
                PurchasePrice(),
                Status(),
                VCAmount(),
                VirtualCurrency()
            {}

            PayForPurchaseResult(const PayForPurchaseResult& src) :
                PlayFabResultCommon(),
                CreditApplied(src.CreditApplied),
                OrderId(src.OrderId),
                ProviderData(src.ProviderData),
                ProviderToken(src.ProviderToken),
                PurchaseConfirmationPageURL(src.PurchaseConfirmationPageURL),
                PurchaseCurrency(src.PurchaseCurrency),
                PurchasePrice(src.PurchasePrice),
                Status(src.Status),
                VCAmount(src.VCAmount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~PayForPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"CreditApplied"], CreditApplied);
                FromJsonUtilS(input[L"OrderId"], OrderId);
                FromJsonUtilS(input[L"ProviderData"], ProviderData);
                FromJsonUtilS(input[L"ProviderToken"], ProviderToken);
                FromJsonUtilS(input[L"PurchaseConfirmationPageURL"], PurchaseConfirmationPageURL);
                FromJsonUtilS(input[L"PurchaseCurrency"], PurchaseCurrency);
                FromJsonUtilP(input[L"PurchasePrice"], PurchasePrice);
                FromJsonUtilE(input[L"Status"], Status);
                FromJsonUtilP(input[L"VCAmount"], VCAmount);
                FromJsonUtilP(input[L"VirtualCurrency"], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreditApplied; ToJsonUtilP(CreditApplied, each_CreditApplied); output[L"CreditApplied"] = each_CreditApplied;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                web::json::value each_ProviderData; ToJsonUtilS(ProviderData, each_ProviderData); output[L"ProviderData"] = each_ProviderData;
                web::json::value each_ProviderToken; ToJsonUtilS(ProviderToken, each_ProviderToken); output[L"ProviderToken"] = each_ProviderToken;
                web::json::value each_PurchaseConfirmationPageURL; ToJsonUtilS(PurchaseConfirmationPageURL, each_PurchaseConfirmationPageURL); output[L"PurchaseConfirmationPageURL"] = each_PurchaseConfirmationPageURL;
                web::json::value each_PurchaseCurrency; ToJsonUtilS(PurchaseCurrency, each_PurchaseCurrency); output[L"PurchaseCurrency"] = each_PurchaseCurrency;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[L"PurchasePrice"] = each_PurchasePrice;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[L"Status"] = each_Status;
                web::json::value each_VCAmount; ToJsonUtilP(VCAmount, each_VCAmount); output[L"VCAmount"] = each_VCAmount;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct PaymentOption : public PlayFabBaseModel
        {
            std::string Currency;
            Uint32 Price;
            std::string ProviderName;
            Uint32 StoreCredit;

            PaymentOption() :
                PlayFabBaseModel(),
                Currency(),
                Price(),
                ProviderName(),
                StoreCredit()
            {}

            PaymentOption(const PaymentOption& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                Price(src.Price),
                ProviderName(src.ProviderName),
                StoreCredit(src.StoreCredit)
            {}

            ~PaymentOption() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Currency"], Currency);
                FromJsonUtilP(input[L"Price"], Price);
                FromJsonUtilS(input[L"ProviderName"], ProviderName);
                FromJsonUtilP(input[L"StoreCredit"], StoreCredit);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Currency; ToJsonUtilS(Currency, each_Currency); output[L"Currency"] = each_Currency;
                web::json::value each_Price; ToJsonUtilP(Price, each_Price); output[L"Price"] = each_Price;
                web::json::value each_ProviderName; ToJsonUtilS(ProviderName, each_ProviderName); output[L"ProviderName"] = each_ProviderName;
                web::json::value each_StoreCredit; ToJsonUtilP(StoreCredit, each_StoreCredit); output[L"StoreCredit"] = each_StoreCredit;
                return output;
            }
        };

        struct PurchaseItemRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ItemId;
            Int32 Price;
            std::string StoreId;
            std::string VirtualCurrency;

            PurchaseItemRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                ItemId(),
                Price(),
                StoreId(),
                VirtualCurrency()
            {}

            PurchaseItemRequest(const PurchaseItemRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ItemId(src.ItemId),
                Price(src.Price),
                StoreId(src.StoreId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~PurchaseItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"ItemId"], ItemId);
                FromJsonUtilP(input[L"Price"], Price);
                FromJsonUtilS(input[L"StoreId"], StoreId);
                FromJsonUtilS(input[L"VirtualCurrency"], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[L"ItemId"] = each_ItemId;
                web::json::value each_Price; ToJsonUtilP(Price, each_Price); output[L"Price"] = each_Price;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[L"StoreId"] = each_StoreId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct PurchaseItemResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Items;

            PurchaseItemResult() :
                PlayFabResultCommon(),
                Items()
            {}

            PurchaseItemResult(const PurchaseItemResult& src) :
                PlayFabResultCommon(),
                Items(src.Items)
            {}

            ~PurchaseItemResult() { }

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

        struct RedeemCouponRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string CouponCode;

            RedeemCouponRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                CouponCode()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CouponCode(src.CouponCode)
            {}

            ~RedeemCouponRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"CouponCode"], CouponCode);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_CouponCode; ToJsonUtilS(CouponCode, each_CouponCode); output[L"CouponCode"] = each_CouponCode;
                return output;
            }
        };

        struct RedeemCouponResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> GrantedItems;

            RedeemCouponResult() :
                PlayFabResultCommon(),
                GrantedItems()
            {}

            RedeemCouponResult(const RedeemCouponResult& src) :
                PlayFabResultCommon(),
                GrantedItems(src.GrantedItems)
            {}

            ~RedeemCouponResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"GrantedItems"], GrantedItems);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GrantedItems; ToJsonUtilO(GrantedItems, each_GrantedItems); output[L"GrantedItems"] = each_GrantedItems;
                return output;
            }
        };

        struct RegisterForIOSPushNotificationRequest : public PlayFabRequestCommon
        {
            std::string ConfirmationMessage;
            std::string DeviceToken;
            Boxed<bool> SendPushNotificationConfirmation;

            RegisterForIOSPushNotificationRequest() :
                PlayFabRequestCommon(),
                ConfirmationMessage(),
                DeviceToken(),
                SendPushNotificationConfirmation()
            {}

            RegisterForIOSPushNotificationRequest(const RegisterForIOSPushNotificationRequest& src) :
                PlayFabRequestCommon(),
                ConfirmationMessage(src.ConfirmationMessage),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation)
            {}

            ~RegisterForIOSPushNotificationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ConfirmationMessage"], ConfirmationMessage);
                FromJsonUtilS(input[L"DeviceToken"], DeviceToken);
                FromJsonUtilP(input[L"SendPushNotificationConfirmation"], SendPushNotificationConfirmation);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ConfirmationMessage; ToJsonUtilS(ConfirmationMessage, each_ConfirmationMessage); output[L"ConfirmationMessage"] = each_ConfirmationMessage;
                web::json::value each_DeviceToken; ToJsonUtilS(DeviceToken, each_DeviceToken); output[L"DeviceToken"] = each_DeviceToken;
                web::json::value each_SendPushNotificationConfirmation; ToJsonUtilP(SendPushNotificationConfirmation, each_SendPushNotificationConfirmation); output[L"SendPushNotificationConfirmation"] = each_SendPushNotificationConfirmation;
                return output;
            }
        };

        struct RegisterForIOSPushNotificationResult : public PlayFabResultCommon
        {

            RegisterForIOSPushNotificationResult() :
                PlayFabResultCommon()
            {}

            RegisterForIOSPushNotificationResult(const RegisterForIOSPushNotificationResult&) :
                PlayFabResultCommon()
            {}

            ~RegisterForIOSPushNotificationResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RegisterPlayFabUserRequest : public PlayFabRequestCommon
        {
            std::string DisplayName;
            std::string Email;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string Password;
            std::string PlayerSecret;
            Boxed<bool> RequireBothUsernameAndEmail;
            std::string TitleId;
            std::string Username;

            RegisterPlayFabUserRequest() :
                PlayFabRequestCommon(),
                DisplayName(),
                Email(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                Password(),
                PlayerSecret(),
                RequireBothUsernameAndEmail(),
                TitleId(),
                Username()
            {}

            RegisterPlayFabUserRequest(const RegisterPlayFabUserRequest& src) :
                PlayFabRequestCommon(),
                DisplayName(src.DisplayName),
                Email(src.Email),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                PlayerSecret(src.PlayerSecret),
                RequireBothUsernameAndEmail(src.RequireBothUsernameAndEmail),
                TitleId(src.TitleId),
                Username(src.Username)
            {}

            ~RegisterPlayFabUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DisplayName"], DisplayName);
                FromJsonUtilS(input[L"Email"], Email);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"Password"], Password);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilP(input[L"RequireBothUsernameAndEmail"], RequireBothUsernameAndEmail);
                FromJsonUtilS(input[L"TitleId"], TitleId);
                FromJsonUtilS(input[L"Username"], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[L"DisplayName"] = each_DisplayName;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[L"Password"] = each_Password;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_RequireBothUsernameAndEmail; ToJsonUtilP(RequireBothUsernameAndEmail, each_RequireBothUsernameAndEmail); output[L"RequireBothUsernameAndEmail"] = each_RequireBothUsernameAndEmail;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                return output;
            }
        };

        struct RegisterPlayFabUserResult : public PlayFabResultCommon
        {
            Boxed<EntityTokenResponse> EntityToken;
            std::string PlayFabId;
            std::string SessionTicket;
            Boxed<UserSettings> SettingsForUser;
            std::string Username;

            RegisterPlayFabUserResult() :
                PlayFabResultCommon(),
                EntityToken(),
                PlayFabId(),
                SessionTicket(),
                SettingsForUser(),
                Username()
            {}

            RegisterPlayFabUserResult(const RegisterPlayFabUserResult& src) :
                PlayFabResultCommon(),
                EntityToken(src.EntityToken),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                SettingsForUser(src.SettingsForUser),
                Username(src.Username)
            {}

            ~RegisterPlayFabUserResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"EntityToken"], EntityToken);
                FromJsonUtilS(input[L"PlayFabId"], PlayFabId);
                FromJsonUtilS(input[L"SessionTicket"], SessionTicket);
                FromJsonUtilO(input[L"SettingsForUser"], SettingsForUser);
                FromJsonUtilS(input[L"Username"], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EntityToken; ToJsonUtilO(EntityToken, each_EntityToken); output[L"EntityToken"] = each_EntityToken;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[L"PlayFabId"] = each_PlayFabId;
                web::json::value each_SessionTicket; ToJsonUtilS(SessionTicket, each_SessionTicket); output[L"SessionTicket"] = each_SessionTicket;
                web::json::value each_SettingsForUser; ToJsonUtilO(SettingsForUser, each_SettingsForUser); output[L"SettingsForUser"] = each_SettingsForUser;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[L"Username"] = each_Username;
                return output;
            }
        };

        struct RegisterWithWindowsHelloRequest : public PlayFabRequestCommon
        {
            std::string DeviceName;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string PublicKey;
            std::string TitleId;
            std::string UserName;

            RegisterWithWindowsHelloRequest() :
                PlayFabRequestCommon(),
                DeviceName(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                PublicKey(),
                TitleId(),
                UserName()
            {}

            RegisterWithWindowsHelloRequest(const RegisterWithWindowsHelloRequest& src) :
                PlayFabRequestCommon(),
                DeviceName(src.DeviceName),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                PublicKey(src.PublicKey),
                TitleId(src.TitleId),
                UserName(src.UserName)
            {}

            ~RegisterWithWindowsHelloRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DeviceName"], DeviceName);
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input[L"InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input[L"LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input[L"PublicKey"], PublicKey);
                FromJsonUtilS(input[L"TitleId"], TitleId);
                FromJsonUtilS(input[L"UserName"], UserName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeviceName; ToJsonUtilS(DeviceName, each_DeviceName); output[L"DeviceName"] = each_DeviceName;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[L"InfoRequestParameters"] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[L"LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
                web::json::value each_PublicKey; ToJsonUtilS(PublicKey, each_PublicKey); output[L"PublicKey"] = each_PublicKey;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
                web::json::value each_UserName; ToJsonUtilS(UserName, each_UserName); output[L"UserName"] = each_UserName;
                return output;
            }
        };

        struct RemoveContactEmailRequest : public PlayFabRequestCommon
        {

            RemoveContactEmailRequest() :
                PlayFabRequestCommon()
            {}

            RemoveContactEmailRequest(const RemoveContactEmailRequest&) :
                PlayFabRequestCommon()
            {}

            ~RemoveContactEmailRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveContactEmailResult : public PlayFabResultCommon
        {

            RemoveContactEmailResult() :
                PlayFabResultCommon()
            {}

            RemoveContactEmailResult(const RemoveContactEmailResult&) :
                PlayFabResultCommon()
            {}

            ~RemoveContactEmailResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveFriendRequest : public PlayFabRequestCommon
        {
            std::string FriendPlayFabId;

            RemoveFriendRequest() :
                PlayFabRequestCommon(),
                FriendPlayFabId()
            {}

            RemoveFriendRequest(const RemoveFriendRequest& src) :
                PlayFabRequestCommon(),
                FriendPlayFabId(src.FriendPlayFabId)
            {}

            ~RemoveFriendRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FriendPlayFabId"], FriendPlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[L"FriendPlayFabId"] = each_FriendPlayFabId;
                return output;
            }
        };

        struct RemoveFriendResult : public PlayFabResultCommon
        {

            RemoveFriendResult() :
                PlayFabResultCommon()
            {}

            RemoveFriendResult(const RemoveFriendResult&) :
                PlayFabResultCommon()
            {}

            ~RemoveFriendResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveGenericIDRequest : public PlayFabRequestCommon
        {
            GenericServiceId GenericId;

            RemoveGenericIDRequest() :
                PlayFabRequestCommon(),
                GenericId()
            {}

            RemoveGenericIDRequest(const RemoveGenericIDRequest& src) :
                PlayFabRequestCommon(),
                GenericId(src.GenericId)
            {}

            ~RemoveGenericIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"GenericId"], GenericId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output[L"GenericId"] = each_GenericId;
                return output;
            }
        };

        struct RemoveGenericIDResult : public PlayFabResultCommon
        {

            RemoveGenericIDResult() :
                PlayFabResultCommon()
            {}

            RemoveGenericIDResult(const RemoveGenericIDResult&) :
                PlayFabResultCommon()
            {}

            ~RemoveGenericIDResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveSharedGroupMembersRequest : public PlayFabRequestCommon
        {
            std::list<std::string> PlayFabIds;
            std::string SharedGroupId;

            RemoveSharedGroupMembersRequest() :
                PlayFabRequestCommon(),
                PlayFabIds(),
                SharedGroupId()
            {}

            RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
                PlayFabRequestCommon(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
            {}

            ~RemoveSharedGroupMembersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PlayFabIds"], PlayFabIds);
                FromJsonUtilS(input[L"SharedGroupId"], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabIds; ToJsonUtilS(PlayFabIds, each_PlayFabIds); output[L"PlayFabIds"] = each_PlayFabIds;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[L"SharedGroupId"] = each_SharedGroupId;
                return output;
            }
        };

        struct RemoveSharedGroupMembersResult : public PlayFabResultCommon
        {

            RemoveSharedGroupMembersResult() :
                PlayFabResultCommon()
            {}

            RemoveSharedGroupMembersResult(const RemoveSharedGroupMembersResult&) :
                PlayFabResultCommon()
            {}

            ~RemoveSharedGroupMembersResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ReportPlayerClientRequest : public PlayFabRequestCommon
        {
            std::string Comment;
            std::string ReporteeId;

            ReportPlayerClientRequest() :
                PlayFabRequestCommon(),
                Comment(),
                ReporteeId()
            {}

            ReportPlayerClientRequest(const ReportPlayerClientRequest& src) :
                PlayFabRequestCommon(),
                Comment(src.Comment),
                ReporteeId(src.ReporteeId)
            {}

            ~ReportPlayerClientRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Comment"], Comment);
                FromJsonUtilS(input[L"ReporteeId"], ReporteeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[L"Comment"] = each_Comment;
                web::json::value each_ReporteeId; ToJsonUtilS(ReporteeId, each_ReporteeId); output[L"ReporteeId"] = each_ReporteeId;
                return output;
            }
        };

        struct ReportPlayerClientResult : public PlayFabResultCommon
        {
            Int32 SubmissionsRemaining;

            ReportPlayerClientResult() :
                PlayFabResultCommon(),
                SubmissionsRemaining()
            {}

            ReportPlayerClientResult(const ReportPlayerClientResult& src) :
                PlayFabResultCommon(),
                SubmissionsRemaining(src.SubmissionsRemaining)
            {}

            ~ReportPlayerClientResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"SubmissionsRemaining"], SubmissionsRemaining);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SubmissionsRemaining; ToJsonUtilP(SubmissionsRemaining, each_SubmissionsRemaining); output[L"SubmissionsRemaining"] = each_SubmissionsRemaining;
                return output;
            }
        };

        struct RestoreIOSPurchasesRequest : public PlayFabRequestCommon
        {
            std::string ReceiptData;

            RestoreIOSPurchasesRequest() :
                PlayFabRequestCommon(),
                ReceiptData()
            {}

            RestoreIOSPurchasesRequest(const RestoreIOSPurchasesRequest& src) :
                PlayFabRequestCommon(),
                ReceiptData(src.ReceiptData)
            {}

            ~RestoreIOSPurchasesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ReceiptData"], ReceiptData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ReceiptData; ToJsonUtilS(ReceiptData, each_ReceiptData); output[L"ReceiptData"] = each_ReceiptData;
                return output;
            }
        };

        struct RestoreIOSPurchasesResult : public PlayFabResultCommon
        {

            RestoreIOSPurchasesResult() :
                PlayFabResultCommon()
            {}

            RestoreIOSPurchasesResult(const RestoreIOSPurchasesResult&) :
                PlayFabResultCommon()
            {}

            ~RestoreIOSPurchasesResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string EmailTemplateId;
            std::string TitleId;

            SendAccountRecoveryEmailRequest() :
                PlayFabRequestCommon(),
                Email(),
                EmailTemplateId(),
                TitleId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                EmailTemplateId(src.EmailTemplateId),
                TitleId(src.TitleId)
            {}

            ~SendAccountRecoveryEmailRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Email"], Email);
                FromJsonUtilS(input[L"EmailTemplateId"], EmailTemplateId);
                FromJsonUtilS(input[L"TitleId"], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[L"Email"] = each_Email;
                web::json::value each_EmailTemplateId; ToJsonUtilS(EmailTemplateId, each_EmailTemplateId); output[L"EmailTemplateId"] = each_EmailTemplateId;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[L"TitleId"] = each_TitleId;
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

        struct SetFriendTagsRequest : public PlayFabRequestCommon
        {
            std::string FriendPlayFabId;
            std::list<std::string> Tags;

            SetFriendTagsRequest() :
                PlayFabRequestCommon(),
                FriendPlayFabId(),
                Tags()
            {}

            SetFriendTagsRequest(const SetFriendTagsRequest& src) :
                PlayFabRequestCommon(),
                FriendPlayFabId(src.FriendPlayFabId),
                Tags(src.Tags)
            {}

            ~SetFriendTagsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FriendPlayFabId"], FriendPlayFabId);
                FromJsonUtilS(input[L"Tags"], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[L"FriendPlayFabId"] = each_FriendPlayFabId;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[L"Tags"] = each_Tags;
                return output;
            }
        };

        struct SetFriendTagsResult : public PlayFabResultCommon
        {

            SetFriendTagsResult() :
                PlayFabResultCommon()
            {}

            SetFriendTagsResult(const SetFriendTagsResult&) :
                PlayFabResultCommon()
            {}

            ~SetFriendTagsResult() { }

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
            std::string EncryptedRequest;
            std::string PlayerSecret;

            SetPlayerSecretRequest() :
                PlayFabRequestCommon(),
                EncryptedRequest(),
                PlayerSecret()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabRequestCommon(),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret)
            {}

            ~SetPlayerSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"EncryptedRequest"], EncryptedRequest);
                FromJsonUtilS(input[L"PlayerSecret"], PlayerSecret);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[L"EncryptedRequest"] = each_EncryptedRequest;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[L"PlayerSecret"] = each_PlayerSecret;
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

        struct StartGameRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::string CharacterId;
            std::string CustomCommandLineData;
            std::string GameMode;
            Region pfRegion;
            std::string StatisticName;

            StartGameRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                CharacterId(),
                CustomCommandLineData(),
                GameMode(),
                pfRegion(),
                StatisticName()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                CharacterId(src.CharacterId),
                CustomCommandLineData(src.CustomCommandLineData),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion),
                StatisticName(src.StatisticName)
            {}

            ~StartGameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"BuildVersion"], BuildVersion);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"CustomCommandLineData"], CustomCommandLineData);
                FromJsonUtilS(input[L"GameMode"], GameMode);
                FromJsonEnum(input[L"pfRegion"], pfRegion);
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[L"BuildVersion"] = each_BuildVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_CustomCommandLineData; ToJsonUtilS(CustomCommandLineData, each_CustomCommandLineData); output[L"CustomCommandLineData"] = each_CustomCommandLineData;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[L"GameMode"] = each_GameMode;
                web::json::value each_pfRegion; ToJsonEnum(pfRegion, each_pfRegion); output[L"Region"] = each_pfRegion;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                return output;
            }
        };

        struct StartGameResult : public PlayFabResultCommon
        {
            std::string Expires;
            std::string LobbyID;
            std::string Password;
            std::string ServerHostname;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            Boxed<Int32> ServerPort;
            std::string ServerPublicDNSName;
            std::string Ticket;

            StartGameResult() :
                PlayFabResultCommon(),
                Expires(),
                LobbyID(),
                Password(),
                ServerHostname(),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(),
                ServerPublicDNSName(),
                Ticket()
            {}

            StartGameResult(const StartGameResult& src) :
                PlayFabResultCommon(),
                Expires(src.Expires),
                LobbyID(src.LobbyID),
                Password(src.Password),
                ServerHostname(src.ServerHostname),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                Ticket(src.Ticket)
            {}

            ~StartGameResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Expires"], Expires);
                FromJsonUtilS(input[L"LobbyID"], LobbyID);
                FromJsonUtilS(input[L"Password"], Password);
                FromJsonUtilS(input[L"ServerHostname"], ServerHostname);
                FromJsonUtilS(input[L"ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input[L"ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input[L"ServerPort"], ServerPort);
                FromJsonUtilS(input[L"ServerPublicDNSName"], ServerPublicDNSName);
                FromJsonUtilS(input[L"Ticket"], Ticket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expires; ToJsonUtilS(Expires, each_Expires); output[L"Expires"] = each_Expires;
                web::json::value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output[L"LobbyID"] = each_LobbyID;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[L"Password"] = each_Password;
                web::json::value each_ServerHostname; ToJsonUtilS(ServerHostname, each_ServerHostname); output[L"ServerHostname"] = each_ServerHostname;
                web::json::value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output[L"ServerIPV4Address"] = each_ServerIPV4Address;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[L"ServerIPV6Address"] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[L"ServerPort"] = each_ServerPort;
                web::json::value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output[L"ServerPublicDNSName"] = each_ServerPublicDNSName;
                web::json::value each_Ticket; ToJsonUtilS(Ticket, each_Ticket); output[L"Ticket"] = each_Ticket;
                return output;
            }
        };

        struct StartPurchaseRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::list<ItemPurchaseRequest> Items;
            std::string StoreId;

            StartPurchaseRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                Items(),
                StoreId()
            {}

            StartPurchaseRequest(const StartPurchaseRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                Items(src.Items),
                StoreId(src.StoreId)
            {}

            ~StartPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input[L"Items"], Items);
                FromJsonUtilS(input[L"StoreId"], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_Items; ToJsonUtilO(Items, each_Items); output[L"Items"] = each_Items;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[L"StoreId"] = each_StoreId;
                return output;
            }
        };

        struct StartPurchaseResult : public PlayFabResultCommon
        {
            std::list<CartItem> Contents;
            std::string OrderId;
            std::list<PaymentOption> PaymentOptions;
            std::map<std::string, Int32> VirtualCurrencyBalances;

            StartPurchaseResult() :
                PlayFabResultCommon(),
                Contents(),
                OrderId(),
                PaymentOptions(),
                VirtualCurrencyBalances()
            {}

            StartPurchaseResult(const StartPurchaseResult& src) :
                PlayFabResultCommon(),
                Contents(src.Contents),
                OrderId(src.OrderId),
                PaymentOptions(src.PaymentOptions),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            ~StartPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Contents"], Contents);
                FromJsonUtilS(input[L"OrderId"], OrderId);
                FromJsonUtilO(input[L"PaymentOptions"], PaymentOptions);
                FromJsonUtilP(input[L"VirtualCurrencyBalances"], VirtualCurrencyBalances);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Contents; ToJsonUtilO(Contents, each_Contents); output[L"Contents"] = each_Contents;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[L"OrderId"] = each_OrderId;
                web::json::value each_PaymentOptions; ToJsonUtilO(PaymentOptions, each_PaymentOptions); output[L"PaymentOptions"] = each_PaymentOptions;
                web::json::value each_VirtualCurrencyBalances; ToJsonUtilP(VirtualCurrencyBalances, each_VirtualCurrencyBalances); output[L"VirtualCurrencyBalances"] = each_VirtualCurrencyBalances;
                return output;
            }
        };

        struct StatisticUpdate : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 Value;
            Boxed<Uint32> Version;

            StatisticUpdate() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(),
                Version()
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            ~StatisticUpdate() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"StatisticName"], StatisticName);
                FromJsonUtilP(input[L"Value"], Value);
                FromJsonUtilP(input[L"Version"], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[L"StatisticName"] = each_StatisticName;
                web::json::value each_Value; ToJsonUtilP(Value, each_Value); output[L"Value"] = each_Value;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[L"Version"] = each_Version;
                return output;
            }
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string VirtualCurrency;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                VirtualCurrency()
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~SubtractUserVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"Amount"], Amount);
                FromJsonUtilS(input[L"VirtualCurrency"], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[L"Amount"] = each_Amount;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct UnlinkAndroidDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string AndroidDeviceId;

            UnlinkAndroidDeviceIDRequest() :
                PlayFabRequestCommon(),
                AndroidDeviceId()
            {}

            UnlinkAndroidDeviceIDRequest(const UnlinkAndroidDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            ~UnlinkAndroidDeviceIDRequest() { }

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

        struct UnlinkAndroidDeviceIDResult : public PlayFabResultCommon
        {

            UnlinkAndroidDeviceIDResult() :
                PlayFabResultCommon()
            {}

            UnlinkAndroidDeviceIDResult(const UnlinkAndroidDeviceIDResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkAndroidDeviceIDResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkCustomIDRequest : public PlayFabRequestCommon
        {
            std::string CustomId;

            UnlinkCustomIDRequest() :
                PlayFabRequestCommon(),
                CustomId()
            {}

            UnlinkCustomIDRequest(const UnlinkCustomIDRequest& src) :
                PlayFabRequestCommon(),
                CustomId(src.CustomId)
            {}

            ~UnlinkCustomIDRequest() { }

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

        struct UnlinkCustomIDResult : public PlayFabResultCommon
        {

            UnlinkCustomIDResult() :
                PlayFabResultCommon()
            {}

            UnlinkCustomIDResult(const UnlinkCustomIDResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkCustomIDResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkFacebookAccountRequest : public PlayFabRequestCommon
        {

            UnlinkFacebookAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkFacebookAccountRequest(const UnlinkFacebookAccountRequest&) :
                PlayFabRequestCommon()
            {}

            ~UnlinkFacebookAccountRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkFacebookAccountResult : public PlayFabResultCommon
        {

            UnlinkFacebookAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkFacebookAccountResult(const UnlinkFacebookAccountResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkFacebookAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkFacebookInstantGamesIdRequest : public PlayFabRequestCommon
        {
            std::string FacebookInstantGamesId;

            UnlinkFacebookInstantGamesIdRequest() :
                PlayFabRequestCommon(),
                FacebookInstantGamesId()
            {}

            UnlinkFacebookInstantGamesIdRequest(const UnlinkFacebookInstantGamesIdRequest& src) :
                PlayFabRequestCommon(),
                FacebookInstantGamesId(src.FacebookInstantGamesId)
            {}

            ~UnlinkFacebookInstantGamesIdRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"FacebookInstantGamesId"], FacebookInstantGamesId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookInstantGamesId; ToJsonUtilS(FacebookInstantGamesId, each_FacebookInstantGamesId); output[L"FacebookInstantGamesId"] = each_FacebookInstantGamesId;
                return output;
            }
        };

        struct UnlinkFacebookInstantGamesIdResult : public PlayFabResultCommon
        {

            UnlinkFacebookInstantGamesIdResult() :
                PlayFabResultCommon()
            {}

            UnlinkFacebookInstantGamesIdResult(const UnlinkFacebookInstantGamesIdResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkFacebookInstantGamesIdResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkGameCenterAccountRequest : public PlayFabRequestCommon
        {

            UnlinkGameCenterAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkGameCenterAccountRequest(const UnlinkGameCenterAccountRequest&) :
                PlayFabRequestCommon()
            {}

            ~UnlinkGameCenterAccountRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkGameCenterAccountResult : public PlayFabResultCommon
        {

            UnlinkGameCenterAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkGameCenterAccountResult(const UnlinkGameCenterAccountResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkGameCenterAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkGoogleAccountRequest : public PlayFabRequestCommon
        {

            UnlinkGoogleAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkGoogleAccountRequest(const UnlinkGoogleAccountRequest&) :
                PlayFabRequestCommon()
            {}

            ~UnlinkGoogleAccountRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkGoogleAccountResult : public PlayFabResultCommon
        {

            UnlinkGoogleAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkGoogleAccountResult(const UnlinkGoogleAccountResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkGoogleAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkIOSDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string DeviceId;

            UnlinkIOSDeviceIDRequest() :
                PlayFabRequestCommon(),
                DeviceId()
            {}

            UnlinkIOSDeviceIDRequest(const UnlinkIOSDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                DeviceId(src.DeviceId)
            {}

            ~UnlinkIOSDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"DeviceId"], DeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output[L"DeviceId"] = each_DeviceId;
                return output;
            }
        };

        struct UnlinkIOSDeviceIDResult : public PlayFabResultCommon
        {

            UnlinkIOSDeviceIDResult() :
                PlayFabResultCommon()
            {}

            UnlinkIOSDeviceIDResult(const UnlinkIOSDeviceIDResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkIOSDeviceIDResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkKongregateAccountRequest : public PlayFabRequestCommon
        {

            UnlinkKongregateAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkKongregateAccountRequest(const UnlinkKongregateAccountRequest&) :
                PlayFabRequestCommon()
            {}

            ~UnlinkKongregateAccountRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkKongregateAccountResult : public PlayFabResultCommon
        {

            UnlinkKongregateAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkKongregateAccountResult(const UnlinkKongregateAccountResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkKongregateAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkNintendoSwitchDeviceIdRequest : public PlayFabRequestCommon
        {
            std::string NintendoSwitchDeviceId;

            UnlinkNintendoSwitchDeviceIdRequest() :
                PlayFabRequestCommon(),
                NintendoSwitchDeviceId()
            {}

            UnlinkNintendoSwitchDeviceIdRequest(const UnlinkNintendoSwitchDeviceIdRequest& src) :
                PlayFabRequestCommon(),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId)
            {}

            ~UnlinkNintendoSwitchDeviceIdRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output[L"NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
                return output;
            }
        };

        struct UnlinkNintendoSwitchDeviceIdResult : public PlayFabResultCommon
        {

            UnlinkNintendoSwitchDeviceIdResult() :
                PlayFabResultCommon()
            {}

            UnlinkNintendoSwitchDeviceIdResult(const UnlinkNintendoSwitchDeviceIdResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkNintendoSwitchDeviceIdResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkSteamAccountRequest : public PlayFabRequestCommon
        {

            UnlinkSteamAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkSteamAccountRequest(const UnlinkSteamAccountRequest&) :
                PlayFabRequestCommon()
            {}

            ~UnlinkSteamAccountRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkSteamAccountResult : public PlayFabResultCommon
        {

            UnlinkSteamAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkSteamAccountResult(const UnlinkSteamAccountResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkSteamAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkTwitchAccountRequest : public PlayFabRequestCommon
        {

            UnlinkTwitchAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkTwitchAccountRequest(const UnlinkTwitchAccountRequest&) :
                PlayFabRequestCommon()
            {}

            ~UnlinkTwitchAccountRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkTwitchAccountResult : public PlayFabResultCommon
        {

            UnlinkTwitchAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkTwitchAccountResult(const UnlinkTwitchAccountResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkTwitchAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkWindowsHelloAccountRequest : public PlayFabRequestCommon
        {
            std::string PublicKeyHint;

            UnlinkWindowsHelloAccountRequest() :
                PlayFabRequestCommon(),
                PublicKeyHint()
            {}

            UnlinkWindowsHelloAccountRequest(const UnlinkWindowsHelloAccountRequest& src) :
                PlayFabRequestCommon(),
                PublicKeyHint(src.PublicKeyHint)
            {}

            ~UnlinkWindowsHelloAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"PublicKeyHint"], PublicKeyHint);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output[L"PublicKeyHint"] = each_PublicKeyHint;
                return output;
            }
        };

        struct UnlinkWindowsHelloAccountResponse : public PlayFabResultCommon
        {

            UnlinkWindowsHelloAccountResponse() :
                PlayFabResultCommon()
            {}

            UnlinkWindowsHelloAccountResponse(const UnlinkWindowsHelloAccountResponse&) :
                PlayFabResultCommon()
            {}

            ~UnlinkWindowsHelloAccountResponse() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkXboxAccountRequest : public PlayFabRequestCommon
        {
            std::string XboxToken;

            UnlinkXboxAccountRequest() :
                PlayFabRequestCommon(),
                XboxToken()
            {}

            UnlinkXboxAccountRequest(const UnlinkXboxAccountRequest& src) :
                PlayFabRequestCommon(),
                XboxToken(src.XboxToken)
            {}

            ~UnlinkXboxAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"XboxToken"], XboxToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output[L"XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct UnlinkXboxAccountResult : public PlayFabResultCommon
        {

            UnlinkXboxAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkXboxAccountResult(const UnlinkXboxAccountResult&) :
                PlayFabResultCommon()
            {}

            ~UnlinkXboxAccountResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlockContainerInstanceRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemInstanceId;
            std::string KeyItemInstanceId;

            UnlockContainerInstanceRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemInstanceId(),
                KeyItemInstanceId()
            {}

            UnlockContainerInstanceRequest(const UnlockContainerInstanceRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemInstanceId(src.ContainerItemInstanceId),
                KeyItemInstanceId(src.KeyItemInstanceId)
            {}

            ~UnlockContainerInstanceRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"ContainerItemInstanceId"], ContainerItemInstanceId);
                FromJsonUtilS(input[L"KeyItemInstanceId"], KeyItemInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_ContainerItemInstanceId; ToJsonUtilS(ContainerItemInstanceId, each_ContainerItemInstanceId); output[L"ContainerItemInstanceId"] = each_ContainerItemInstanceId;
                web::json::value each_KeyItemInstanceId; ToJsonUtilS(KeyItemInstanceId, each_KeyItemInstanceId); output[L"KeyItemInstanceId"] = each_KeyItemInstanceId;
                return output;
            }
        };

        struct UnlockContainerItemRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemId;

            UnlockContainerItemRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemId()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemId(src.ContainerItemId)
            {}

            ~UnlockContainerItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"ContainerItemId"], ContainerItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_ContainerItemId; ToJsonUtilS(ContainerItemId, each_ContainerItemId); output[L"ContainerItemId"] = each_ContainerItemId;
                return output;
            }
        };

        struct UnlockContainerItemResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> GrantedItems;
            std::string UnlockedItemInstanceId;
            std::string UnlockedWithItemInstanceId;
            std::map<std::string, Uint32> VirtualCurrency;

            UnlockContainerItemResult() :
                PlayFabResultCommon(),
                GrantedItems(),
                UnlockedItemInstanceId(),
                UnlockedWithItemInstanceId(),
                VirtualCurrency()
            {}

            UnlockContainerItemResult(const UnlockContainerItemResult& src) :
                PlayFabResultCommon(),
                GrantedItems(src.GrantedItems),
                UnlockedItemInstanceId(src.UnlockedItemInstanceId),
                UnlockedWithItemInstanceId(src.UnlockedWithItemInstanceId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~UnlockContainerItemResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"GrantedItems"], GrantedItems);
                FromJsonUtilS(input[L"UnlockedItemInstanceId"], UnlockedItemInstanceId);
                FromJsonUtilS(input[L"UnlockedWithItemInstanceId"], UnlockedWithItemInstanceId);
                FromJsonUtilP(input[L"VirtualCurrency"], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GrantedItems; ToJsonUtilO(GrantedItems, each_GrantedItems); output[L"GrantedItems"] = each_GrantedItems;
                web::json::value each_UnlockedItemInstanceId; ToJsonUtilS(UnlockedItemInstanceId, each_UnlockedItemInstanceId); output[L"UnlockedItemInstanceId"] = each_UnlockedItemInstanceId;
                web::json::value each_UnlockedWithItemInstanceId; ToJsonUtilS(UnlockedWithItemInstanceId, each_UnlockedWithItemInstanceId); output[L"UnlockedWithItemInstanceId"] = each_UnlockedWithItemInstanceId;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[L"VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct UpdateAvatarUrlRequest : public PlayFabRequestCommon
        {
            std::string ImageUrl;

            UpdateAvatarUrlRequest() :
                PlayFabRequestCommon(),
                ImageUrl()
            {}

            UpdateAvatarUrlRequest(const UpdateAvatarUrlRequest& src) :
                PlayFabRequestCommon(),
                ImageUrl(src.ImageUrl)
            {}

            ~UpdateAvatarUrlRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"ImageUrl"], ImageUrl);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ImageUrl; ToJsonUtilS(ImageUrl, each_ImageUrl); output[L"ImageUrl"] = each_ImageUrl;
                return output;
            }
        };

        struct UpdateCharacterDataRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateCharacterDataRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            ~UpdateCharacterDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"Data"], Data);
                FromJsonUtilS(input[L"KeysToRemove"], KeysToRemove);
                FromJsonUtilE(input[L"Permission"], Permission);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[L"KeysToRemove"] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[L"Permission"] = each_Permission;
                return output;
            }
        };

        struct UpdateCharacterDataResult : public PlayFabResultCommon
        {
            Uint32 DataVersion;

            UpdateCharacterDataResult() :
                PlayFabResultCommon(),
                DataVersion()
            {}

            UpdateCharacterDataResult(const UpdateCharacterDataResult& src) :
                PlayFabResultCommon(),
                DataVersion(src.DataVersion)
            {}

            ~UpdateCharacterDataResult() { }

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

        struct UpdateCharacterStatisticsRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::map<std::string, Int32> CharacterStatistics;

            UpdateCharacterStatisticsRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                CharacterStatistics()
            {}

            UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics)
            {}

            ~UpdateCharacterStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilP(input[L"CharacterStatistics"], CharacterStatistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_CharacterStatistics; ToJsonUtilP(CharacterStatistics, each_CharacterStatistics); output[L"CharacterStatistics"] = each_CharacterStatistics;
                return output;
            }
        };

        struct UpdateCharacterStatisticsResult : public PlayFabResultCommon
        {

            UpdateCharacterStatisticsResult() :
                PlayFabResultCommon()
            {}

            UpdateCharacterStatisticsResult(const UpdateCharacterStatisticsResult&) :
                PlayFabResultCommon()
            {}

            ~UpdateCharacterStatisticsResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdatePlayerStatisticsRequest : public PlayFabRequestCommon
        {
            std::list<StatisticUpdate> Statistics;

            UpdatePlayerStatisticsRequest() :
                PlayFabRequestCommon(),
                Statistics()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabRequestCommon(),
                Statistics(src.Statistics)
            {}

            ~UpdatePlayerStatisticsRequest() { }

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

        struct UpdatePlayerStatisticsResult : public PlayFabResultCommon
        {

            UpdatePlayerStatisticsResult() :
                PlayFabResultCommon()
            {}

            UpdatePlayerStatisticsResult(const UpdatePlayerStatisticsResult&) :
                PlayFabResultCommon()
            {}

            ~UpdatePlayerStatisticsResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateSharedGroupDataRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string SharedGroupId;

            UpdateSharedGroupDataRequest() :
                PlayFabRequestCommon(),
                Data(),
                KeysToRemove(),
                Permission(),
                SharedGroupId()
            {}

            UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
                PlayFabRequestCommon(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                SharedGroupId(src.SharedGroupId)
            {}

            ~UpdateSharedGroupDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Data"], Data);
                FromJsonUtilS(input[L"KeysToRemove"], KeysToRemove);
                FromJsonUtilE(input[L"Permission"], Permission);
                FromJsonUtilS(input[L"SharedGroupId"], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[L"KeysToRemove"] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[L"Permission"] = each_Permission;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[L"SharedGroupId"] = each_SharedGroupId;
                return output;
            }
        };

        struct UpdateSharedGroupDataResult : public PlayFabResultCommon
        {

            UpdateSharedGroupDataResult() :
                PlayFabResultCommon()
            {}

            UpdateSharedGroupDataResult(const UpdateSharedGroupDataResult&) :
                PlayFabResultCommon()
            {}

            ~UpdateSharedGroupDataResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateUserDataRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabRequestCommon(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabRequestCommon(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            ~UpdateUserDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Data"], Data);
                FromJsonUtilS(input[L"KeysToRemove"], KeysToRemove);
                FromJsonUtilE(input[L"Permission"], Permission);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[L"Data"] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[L"KeysToRemove"] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[L"Permission"] = each_Permission;
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

        struct UpdateUserTitleDisplayNameRequest : public PlayFabRequestCommon
        {
            std::string DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabRequestCommon(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabRequestCommon(),
                DisplayName(src.DisplayName)
            {}

            ~UpdateUserTitleDisplayNameRequest() { }

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

        struct ValidateAmazonReceiptRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CurrencyCode;
            Int32 PurchasePrice;
            std::string ReceiptId;
            std::string UserId;

            ValidateAmazonReceiptRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(),
                ReceiptId(),
                UserId()
            {}

            ValidateAmazonReceiptRequest(const ValidateAmazonReceiptRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptId(src.ReceiptId),
                UserId(src.UserId)
            {}

            ~ValidateAmazonReceiptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CurrencyCode"], CurrencyCode);
                FromJsonUtilP(input[L"PurchasePrice"], PurchasePrice);
                FromJsonUtilS(input[L"ReceiptId"], ReceiptId);
                FromJsonUtilS(input[L"UserId"], UserId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[L"CurrencyCode"] = each_CurrencyCode;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[L"PurchasePrice"] = each_PurchasePrice;
                web::json::value each_ReceiptId; ToJsonUtilS(ReceiptId, each_ReceiptId); output[L"ReceiptId"] = each_ReceiptId;
                web::json::value each_UserId; ToJsonUtilS(UserId, each_UserId); output[L"UserId"] = each_UserId;
                return output;
            }
        };

        struct ValidateAmazonReceiptResult : public PlayFabResultCommon
        {

            ValidateAmazonReceiptResult() :
                PlayFabResultCommon()
            {}

            ValidateAmazonReceiptResult(const ValidateAmazonReceiptResult&) :
                PlayFabResultCommon()
            {}

            ~ValidateAmazonReceiptResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ValidateGooglePlayPurchaseRequest : public PlayFabRequestCommon
        {
            std::string CurrencyCode;
            Boxed<Uint32> PurchasePrice;
            std::string ReceiptJson;
            std::string Signature;

            ValidateGooglePlayPurchaseRequest() :
                PlayFabRequestCommon(),
                CurrencyCode(),
                PurchasePrice(),
                ReceiptJson(),
                Signature()
            {}

            ValidateGooglePlayPurchaseRequest(const ValidateGooglePlayPurchaseRequest& src) :
                PlayFabRequestCommon(),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptJson(src.ReceiptJson),
                Signature(src.Signature)
            {}

            ~ValidateGooglePlayPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CurrencyCode"], CurrencyCode);
                FromJsonUtilP(input[L"PurchasePrice"], PurchasePrice);
                FromJsonUtilS(input[L"ReceiptJson"], ReceiptJson);
                FromJsonUtilS(input[L"Signature"], Signature);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[L"CurrencyCode"] = each_CurrencyCode;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[L"PurchasePrice"] = each_PurchasePrice;
                web::json::value each_ReceiptJson; ToJsonUtilS(ReceiptJson, each_ReceiptJson); output[L"ReceiptJson"] = each_ReceiptJson;
                web::json::value each_Signature; ToJsonUtilS(Signature, each_Signature); output[L"Signature"] = each_Signature;
                return output;
            }
        };

        struct ValidateGooglePlayPurchaseResult : public PlayFabResultCommon
        {

            ValidateGooglePlayPurchaseResult() :
                PlayFabResultCommon()
            {}

            ValidateGooglePlayPurchaseResult(const ValidateGooglePlayPurchaseResult&) :
                PlayFabResultCommon()
            {}

            ~ValidateGooglePlayPurchaseResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ValidateIOSReceiptRequest : public PlayFabRequestCommon
        {
            std::string CurrencyCode;
            Int32 PurchasePrice;
            std::string ReceiptData;

            ValidateIOSReceiptRequest() :
                PlayFabRequestCommon(),
                CurrencyCode(),
                PurchasePrice(),
                ReceiptData()
            {}

            ValidateIOSReceiptRequest(const ValidateIOSReceiptRequest& src) :
                PlayFabRequestCommon(),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptData(src.ReceiptData)
            {}

            ~ValidateIOSReceiptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CurrencyCode"], CurrencyCode);
                FromJsonUtilP(input[L"PurchasePrice"], PurchasePrice);
                FromJsonUtilS(input[L"ReceiptData"], ReceiptData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[L"CurrencyCode"] = each_CurrencyCode;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[L"PurchasePrice"] = each_PurchasePrice;
                web::json::value each_ReceiptData; ToJsonUtilS(ReceiptData, each_ReceiptData); output[L"ReceiptData"] = each_ReceiptData;
                return output;
            }
        };

        struct ValidateIOSReceiptResult : public PlayFabResultCommon
        {

            ValidateIOSReceiptResult() :
                PlayFabResultCommon()
            {}

            ValidateIOSReceiptResult(const ValidateIOSReceiptResult&) :
                PlayFabResultCommon()
            {}

            ~ValidateIOSReceiptResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ValidateWindowsReceiptRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CurrencyCode;
            Uint32 PurchasePrice;
            std::string Receipt;

            ValidateWindowsReceiptRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(),
                Receipt()
            {}

            ValidateWindowsReceiptRequest(const ValidateWindowsReceiptRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                Receipt(src.Receipt)
            {}

            ~ValidateWindowsReceiptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input[L"CurrencyCode"], CurrencyCode);
                FromJsonUtilP(input[L"PurchasePrice"], PurchasePrice);
                FromJsonUtilS(input[L"Receipt"], Receipt);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[L"CatalogVersion"] = each_CatalogVersion;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[L"CurrencyCode"] = each_CurrencyCode;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[L"PurchasePrice"] = each_PurchasePrice;
                web::json::value each_Receipt; ToJsonUtilS(Receipt, each_Receipt); output[L"Receipt"] = each_Receipt;
                return output;
            }
        };

        struct ValidateWindowsReceiptResult : public PlayFabResultCommon
        {

            ValidateWindowsReceiptResult() :
                PlayFabResultCommon()
            {}

            ValidateWindowsReceiptResult(const ValidateWindowsReceiptResult&) :
                PlayFabResultCommon()
            {}

            ~ValidateWindowsReceiptResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct WriteClientCharacterEventRequest : public PlayFabRequestCommon
        {
            web::json::value Body; // Not truly arbitrary. See documentation for restrictions on format
            std::string CharacterId;
            std::string EventName;
            Boxed<time_t> Timestamp;

            WriteClientCharacterEventRequest() :
                PlayFabRequestCommon(),
                Body(),
                CharacterId(),
                EventName(),
                Timestamp()
            {}

            WriteClientCharacterEventRequest(const WriteClientCharacterEventRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                CharacterId(src.CharacterId),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            ~WriteClientCharacterEventRequest() { }

            void FromJson(web::json::value& input) override
            {
                Body = input[L"Body"];
                FromJsonUtilS(input[L"CharacterId"], CharacterId);
                FromJsonUtilS(input[L"EventName"], EventName);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"Body"] = Body;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[L"CharacterId"] = each_CharacterId;
                web::json::value each_EventName; ToJsonUtilS(EventName, each_EventName); output[L"EventName"] = each_EventName;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                return output;
            }
        };

        struct WriteClientPlayerEventRequest : public PlayFabRequestCommon
        {
            web::json::value Body; // Not truly arbitrary. See documentation for restrictions on format
            std::string EventName;
            Boxed<time_t> Timestamp;

            WriteClientPlayerEventRequest() :
                PlayFabRequestCommon(),
                Body(),
                EventName(),
                Timestamp()
            {}

            WriteClientPlayerEventRequest(const WriteClientPlayerEventRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            ~WriteClientPlayerEventRequest() { }

            void FromJson(web::json::value& input) override
            {
                Body = input[L"Body"];
                FromJsonUtilS(input[L"EventName"], EventName);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"Body"] = Body;
                web::json::value each_EventName; ToJsonUtilS(EventName, each_EventName); output[L"EventName"] = each_EventName;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                return output;
            }
        };

        struct WriteEventResponse : public PlayFabResultCommon
        {
            std::string EventId;

            WriteEventResponse() :
                PlayFabResultCommon(),
                EventId()
            {}

            WriteEventResponse(const WriteEventResponse& src) :
                PlayFabResultCommon(),
                EventId(src.EventId)
            {}

            ~WriteEventResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"EventId"], EventId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EventId; ToJsonUtilS(EventId, each_EventId); output[L"EventId"] = each_EventId;
                return output;
            }
        };

        struct WriteTitleEventRequest : public PlayFabRequestCommon
        {
            web::json::value Body; // Not truly arbitrary. See documentation for restrictions on format
            std::string EventName;
            Boxed<time_t> Timestamp;

            WriteTitleEventRequest() :
                PlayFabRequestCommon(),
                Body(),
                EventName(),
                Timestamp()
            {}

            WriteTitleEventRequest(const WriteTitleEventRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            ~WriteTitleEventRequest() { }

            void FromJson(web::json::value& input) override
            {
                Body = input[L"Body"];
                FromJsonUtilS(input[L"EventName"], EventName);
                FromJsonUtilT(input[L"Timestamp"], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"Body"] = Body;
                web::json::value each_EventName; ToJsonUtilS(EventName, each_EventName); output[L"EventName"] = each_EventName;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[L"Timestamp"] = each_Timestamp;
                return output;
            }
        };

    }
}

#endif
