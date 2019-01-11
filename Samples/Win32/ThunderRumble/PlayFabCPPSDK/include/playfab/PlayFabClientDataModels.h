#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

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
    namespace ClientModels
    {
        // Client Enums
        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        inline void ToJsonEnum(const CloudScriptRevisionOption input, Json::Value& output)
        {
            if (input == CloudScriptRevisionOptionLive) output = Json::Value("Live");
            if (input == CloudScriptRevisionOptionLatest) output = Json::Value("Latest");
            if (input == CloudScriptRevisionOptionSpecific) output = Json::Value("Specific");
        }
        inline void FromJsonEnum(const Json::Value& input, CloudScriptRevisionOption& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Live") output = CloudScriptRevisionOptionLive;
            if (inputStr == "Latest") output = CloudScriptRevisionOptionLatest;
            if (inputStr == "Specific") output = CloudScriptRevisionOptionSpecific;
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

        inline void ToJsonEnum(const ContinentCode input, Json::Value& output)
        {
            if (input == ContinentCodeAF) output = Json::Value("AF");
            if (input == ContinentCodeAN) output = Json::Value("AN");
            if (input == ContinentCodeAS) output = Json::Value("AS");
            if (input == ContinentCodeEU) output = Json::Value("EU");
            if (input == ContinentCodeNA) output = Json::Value("NA");
            if (input == ContinentCodeOC) output = Json::Value("OC");
            if (input == ContinentCodeSA) output = Json::Value("SA");
        }
        inline void FromJsonEnum(const Json::Value& input, ContinentCode& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "AF") output = ContinentCodeAF;
            if (inputStr == "AN") output = ContinentCodeAN;
            if (inputStr == "AS") output = ContinentCodeAS;
            if (inputStr == "EU") output = ContinentCodeEU;
            if (inputStr == "NA") output = ContinentCodeNA;
            if (inputStr == "OC") output = ContinentCodeOC;
            if (inputStr == "SA") output = ContinentCodeSA;
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

        inline void ToJsonEnum(const CountryCode input, Json::Value& output)
        {
            if (input == CountryCodeAF) output = Json::Value("AF");
            if (input == CountryCodeAX) output = Json::Value("AX");
            if (input == CountryCodeAL) output = Json::Value("AL");
            if (input == CountryCodeDZ) output = Json::Value("DZ");
            if (input == CountryCodeAS) output = Json::Value("AS");
            if (input == CountryCodeAD) output = Json::Value("AD");
            if (input == CountryCodeAO) output = Json::Value("AO");
            if (input == CountryCodeAI) output = Json::Value("AI");
            if (input == CountryCodeAQ) output = Json::Value("AQ");
            if (input == CountryCodeAG) output = Json::Value("AG");
            if (input == CountryCodeAR) output = Json::Value("AR");
            if (input == CountryCodeAM) output = Json::Value("AM");
            if (input == CountryCodeAW) output = Json::Value("AW");
            if (input == CountryCodeAU) output = Json::Value("AU");
            if (input == CountryCodeAT) output = Json::Value("AT");
            if (input == CountryCodeAZ) output = Json::Value("AZ");
            if (input == CountryCodeBS) output = Json::Value("BS");
            if (input == CountryCodeBH) output = Json::Value("BH");
            if (input == CountryCodeBD) output = Json::Value("BD");
            if (input == CountryCodeBB) output = Json::Value("BB");
            if (input == CountryCodeBY) output = Json::Value("BY");
            if (input == CountryCodeBE) output = Json::Value("BE");
            if (input == CountryCodeBZ) output = Json::Value("BZ");
            if (input == CountryCodeBJ) output = Json::Value("BJ");
            if (input == CountryCodeBM) output = Json::Value("BM");
            if (input == CountryCodeBT) output = Json::Value("BT");
            if (input == CountryCodeBO) output = Json::Value("BO");
            if (input == CountryCodeBQ) output = Json::Value("BQ");
            if (input == CountryCodeBA) output = Json::Value("BA");
            if (input == CountryCodeBW) output = Json::Value("BW");
            if (input == CountryCodeBV) output = Json::Value("BV");
            if (input == CountryCodeBR) output = Json::Value("BR");
            if (input == CountryCodeIO) output = Json::Value("IO");
            if (input == CountryCodeBN) output = Json::Value("BN");
            if (input == CountryCodeBG) output = Json::Value("BG");
            if (input == CountryCodeBF) output = Json::Value("BF");
            if (input == CountryCodeBI) output = Json::Value("BI");
            if (input == CountryCodeKH) output = Json::Value("KH");
            if (input == CountryCodeCM) output = Json::Value("CM");
            if (input == CountryCodeCA) output = Json::Value("CA");
            if (input == CountryCodeCV) output = Json::Value("CV");
            if (input == CountryCodeKY) output = Json::Value("KY");
            if (input == CountryCodeCF) output = Json::Value("CF");
            if (input == CountryCodeTD) output = Json::Value("TD");
            if (input == CountryCodeCL) output = Json::Value("CL");
            if (input == CountryCodeCN) output = Json::Value("CN");
            if (input == CountryCodeCX) output = Json::Value("CX");
            if (input == CountryCodeCC) output = Json::Value("CC");
            if (input == CountryCodeCO) output = Json::Value("CO");
            if (input == CountryCodeKM) output = Json::Value("KM");
            if (input == CountryCodeCG) output = Json::Value("CG");
            if (input == CountryCodeCD) output = Json::Value("CD");
            if (input == CountryCodeCK) output = Json::Value("CK");
            if (input == CountryCodeCR) output = Json::Value("CR");
            if (input == CountryCodeCI) output = Json::Value("CI");
            if (input == CountryCodeHR) output = Json::Value("HR");
            if (input == CountryCodeCU) output = Json::Value("CU");
            if (input == CountryCodeCW) output = Json::Value("CW");
            if (input == CountryCodeCY) output = Json::Value("CY");
            if (input == CountryCodeCZ) output = Json::Value("CZ");
            if (input == CountryCodeDK) output = Json::Value("DK");
            if (input == CountryCodeDJ) output = Json::Value("DJ");
            if (input == CountryCodeDM) output = Json::Value("DM");
            if (input == CountryCodeDO) output = Json::Value("DO");
            if (input == CountryCodeEC) output = Json::Value("EC");
            if (input == CountryCodeEG) output = Json::Value("EG");
            if (input == CountryCodeSV) output = Json::Value("SV");
            if (input == CountryCodeGQ) output = Json::Value("GQ");
            if (input == CountryCodeER) output = Json::Value("ER");
            if (input == CountryCodeEE) output = Json::Value("EE");
            if (input == CountryCodeET) output = Json::Value("ET");
            if (input == CountryCodeFK) output = Json::Value("FK");
            if (input == CountryCodeFO) output = Json::Value("FO");
            if (input == CountryCodeFJ) output = Json::Value("FJ");
            if (input == CountryCodeFI) output = Json::Value("FI");
            if (input == CountryCodeFR) output = Json::Value("FR");
            if (input == CountryCodeGF) output = Json::Value("GF");
            if (input == CountryCodePF) output = Json::Value("PF");
            if (input == CountryCodeTF) output = Json::Value("TF");
            if (input == CountryCodeGA) output = Json::Value("GA");
            if (input == CountryCodeGM) output = Json::Value("GM");
            if (input == CountryCodeGE) output = Json::Value("GE");
            if (input == CountryCodeDE) output = Json::Value("DE");
            if (input == CountryCodeGH) output = Json::Value("GH");
            if (input == CountryCodeGI) output = Json::Value("GI");
            if (input == CountryCodeGR) output = Json::Value("GR");
            if (input == CountryCodeGL) output = Json::Value("GL");
            if (input == CountryCodeGD) output = Json::Value("GD");
            if (input == CountryCodeGP) output = Json::Value("GP");
            if (input == CountryCodeGU) output = Json::Value("GU");
            if (input == CountryCodeGT) output = Json::Value("GT");
            if (input == CountryCodeGG) output = Json::Value("GG");
            if (input == CountryCodeGN) output = Json::Value("GN");
            if (input == CountryCodeGW) output = Json::Value("GW");
            if (input == CountryCodeGY) output = Json::Value("GY");
            if (input == CountryCodeHT) output = Json::Value("HT");
            if (input == CountryCodeHM) output = Json::Value("HM");
            if (input == CountryCodeVA) output = Json::Value("VA");
            if (input == CountryCodeHN) output = Json::Value("HN");
            if (input == CountryCodeHK) output = Json::Value("HK");
            if (input == CountryCodeHU) output = Json::Value("HU");
            if (input == CountryCodeIS) output = Json::Value("IS");
            if (input == CountryCodeIN) output = Json::Value("IN");
            if (input == CountryCodeID) output = Json::Value("ID");
            if (input == CountryCodeIR) output = Json::Value("IR");
            if (input == CountryCodeIQ) output = Json::Value("IQ");
            if (input == CountryCodeIE) output = Json::Value("IE");
            if (input == CountryCodeIM) output = Json::Value("IM");
            if (input == CountryCodeIL) output = Json::Value("IL");
            if (input == CountryCodeIT) output = Json::Value("IT");
            if (input == CountryCodeJM) output = Json::Value("JM");
            if (input == CountryCodeJP) output = Json::Value("JP");
            if (input == CountryCodeJE) output = Json::Value("JE");
            if (input == CountryCodeJO) output = Json::Value("JO");
            if (input == CountryCodeKZ) output = Json::Value("KZ");
            if (input == CountryCodeKE) output = Json::Value("KE");
            if (input == CountryCodeKI) output = Json::Value("KI");
            if (input == CountryCodeKP) output = Json::Value("KP");
            if (input == CountryCodeKR) output = Json::Value("KR");
            if (input == CountryCodeKW) output = Json::Value("KW");
            if (input == CountryCodeKG) output = Json::Value("KG");
            if (input == CountryCodeLA) output = Json::Value("LA");
            if (input == CountryCodeLV) output = Json::Value("LV");
            if (input == CountryCodeLB) output = Json::Value("LB");
            if (input == CountryCodeLS) output = Json::Value("LS");
            if (input == CountryCodeLR) output = Json::Value("LR");
            if (input == CountryCodeLY) output = Json::Value("LY");
            if (input == CountryCodeLI) output = Json::Value("LI");
            if (input == CountryCodeLT) output = Json::Value("LT");
            if (input == CountryCodeLU) output = Json::Value("LU");
            if (input == CountryCodeMO) output = Json::Value("MO");
            if (input == CountryCodeMK) output = Json::Value("MK");
            if (input == CountryCodeMG) output = Json::Value("MG");
            if (input == CountryCodeMW) output = Json::Value("MW");
            if (input == CountryCodeMY) output = Json::Value("MY");
            if (input == CountryCodeMV) output = Json::Value("MV");
            if (input == CountryCodeML) output = Json::Value("ML");
            if (input == CountryCodeMT) output = Json::Value("MT");
            if (input == CountryCodeMH) output = Json::Value("MH");
            if (input == CountryCodeMQ) output = Json::Value("MQ");
            if (input == CountryCodeMR) output = Json::Value("MR");
            if (input == CountryCodeMU) output = Json::Value("MU");
            if (input == CountryCodeYT) output = Json::Value("YT");
            if (input == CountryCodeMX) output = Json::Value("MX");
            if (input == CountryCodeFM) output = Json::Value("FM");
            if (input == CountryCodeMD) output = Json::Value("MD");
            if (input == CountryCodeMC) output = Json::Value("MC");
            if (input == CountryCodeMN) output = Json::Value("MN");
            if (input == CountryCodeME) output = Json::Value("ME");
            if (input == CountryCodeMS) output = Json::Value("MS");
            if (input == CountryCodeMA) output = Json::Value("MA");
            if (input == CountryCodeMZ) output = Json::Value("MZ");
            if (input == CountryCodeMM) output = Json::Value("MM");
            if (input == CountryCodeNA) output = Json::Value("NA");
            if (input == CountryCodeNR) output = Json::Value("NR");
            if (input == CountryCodeNP) output = Json::Value("NP");
            if (input == CountryCodeNL) output = Json::Value("NL");
            if (input == CountryCodeNC) output = Json::Value("NC");
            if (input == CountryCodeNZ) output = Json::Value("NZ");
            if (input == CountryCodeNI) output = Json::Value("NI");
            if (input == CountryCodeNE) output = Json::Value("NE");
            if (input == CountryCodeNG) output = Json::Value("NG");
            if (input == CountryCodeNU) output = Json::Value("NU");
            if (input == CountryCodeNF) output = Json::Value("NF");
            if (input == CountryCodeMP) output = Json::Value("MP");
            if (input == CountryCodeNO) output = Json::Value("NO");
            if (input == CountryCodeOM) output = Json::Value("OM");
            if (input == CountryCodePK) output = Json::Value("PK");
            if (input == CountryCodePW) output = Json::Value("PW");
            if (input == CountryCodePS) output = Json::Value("PS");
            if (input == CountryCodePA) output = Json::Value("PA");
            if (input == CountryCodePG) output = Json::Value("PG");
            if (input == CountryCodePY) output = Json::Value("PY");
            if (input == CountryCodePE) output = Json::Value("PE");
            if (input == CountryCodePH) output = Json::Value("PH");
            if (input == CountryCodePN) output = Json::Value("PN");
            if (input == CountryCodePL) output = Json::Value("PL");
            if (input == CountryCodePT) output = Json::Value("PT");
            if (input == CountryCodePR) output = Json::Value("PR");
            if (input == CountryCodeQA) output = Json::Value("QA");
            if (input == CountryCodeRE) output = Json::Value("RE");
            if (input == CountryCodeRO) output = Json::Value("RO");
            if (input == CountryCodeRU) output = Json::Value("RU");
            if (input == CountryCodeRW) output = Json::Value("RW");
            if (input == CountryCodeBL) output = Json::Value("BL");
            if (input == CountryCodeSH) output = Json::Value("SH");
            if (input == CountryCodeKN) output = Json::Value("KN");
            if (input == CountryCodeLC) output = Json::Value("LC");
            if (input == CountryCodeMF) output = Json::Value("MF");
            if (input == CountryCodePM) output = Json::Value("PM");
            if (input == CountryCodeVC) output = Json::Value("VC");
            if (input == CountryCodeWS) output = Json::Value("WS");
            if (input == CountryCodeSM) output = Json::Value("SM");
            if (input == CountryCodeST) output = Json::Value("ST");
            if (input == CountryCodeSA) output = Json::Value("SA");
            if (input == CountryCodeSN) output = Json::Value("SN");
            if (input == CountryCodeRS) output = Json::Value("RS");
            if (input == CountryCodeSC) output = Json::Value("SC");
            if (input == CountryCodeSL) output = Json::Value("SL");
            if (input == CountryCodeSG) output = Json::Value("SG");
            if (input == CountryCodeSX) output = Json::Value("SX");
            if (input == CountryCodeSK) output = Json::Value("SK");
            if (input == CountryCodeSI) output = Json::Value("SI");
            if (input == CountryCodeSB) output = Json::Value("SB");
            if (input == CountryCodeSO) output = Json::Value("SO");
            if (input == CountryCodeZA) output = Json::Value("ZA");
            if (input == CountryCodeGS) output = Json::Value("GS");
            if (input == CountryCodeSS) output = Json::Value("SS");
            if (input == CountryCodeES) output = Json::Value("ES");
            if (input == CountryCodeLK) output = Json::Value("LK");
            if (input == CountryCodeSD) output = Json::Value("SD");
            if (input == CountryCodeSR) output = Json::Value("SR");
            if (input == CountryCodeSJ) output = Json::Value("SJ");
            if (input == CountryCodeSZ) output = Json::Value("SZ");
            if (input == CountryCodeSE) output = Json::Value("SE");
            if (input == CountryCodeCH) output = Json::Value("CH");
            if (input == CountryCodeSY) output = Json::Value("SY");
            if (input == CountryCodeTW) output = Json::Value("TW");
            if (input == CountryCodeTJ) output = Json::Value("TJ");
            if (input == CountryCodeTZ) output = Json::Value("TZ");
            if (input == CountryCodeTH) output = Json::Value("TH");
            if (input == CountryCodeTL) output = Json::Value("TL");
            if (input == CountryCodeTG) output = Json::Value("TG");
            if (input == CountryCodeTK) output = Json::Value("TK");
            if (input == CountryCodeTO) output = Json::Value("TO");
            if (input == CountryCodeTT) output = Json::Value("TT");
            if (input == CountryCodeTN) output = Json::Value("TN");
            if (input == CountryCodeTR) output = Json::Value("TR");
            if (input == CountryCodeTM) output = Json::Value("TM");
            if (input == CountryCodeTC) output = Json::Value("TC");
            if (input == CountryCodeTV) output = Json::Value("TV");
            if (input == CountryCodeUG) output = Json::Value("UG");
            if (input == CountryCodeUA) output = Json::Value("UA");
            if (input == CountryCodeAE) output = Json::Value("AE");
            if (input == CountryCodeGB) output = Json::Value("GB");
            if (input == CountryCodeUS) output = Json::Value("US");
            if (input == CountryCodeUM) output = Json::Value("UM");
            if (input == CountryCodeUY) output = Json::Value("UY");
            if (input == CountryCodeUZ) output = Json::Value("UZ");
            if (input == CountryCodeVU) output = Json::Value("VU");
            if (input == CountryCodeVE) output = Json::Value("VE");
            if (input == CountryCodeVN) output = Json::Value("VN");
            if (input == CountryCodeVG) output = Json::Value("VG");
            if (input == CountryCodeVI) output = Json::Value("VI");
            if (input == CountryCodeWF) output = Json::Value("WF");
            if (input == CountryCodeEH) output = Json::Value("EH");
            if (input == CountryCodeYE) output = Json::Value("YE");
            if (input == CountryCodeZM) output = Json::Value("ZM");
            if (input == CountryCodeZW) output = Json::Value("ZW");
        }
        inline void FromJsonEnum(const Json::Value& input, CountryCode& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "AF") output = CountryCodeAF;
            if (inputStr == "AX") output = CountryCodeAX;
            if (inputStr == "AL") output = CountryCodeAL;
            if (inputStr == "DZ") output = CountryCodeDZ;
            if (inputStr == "AS") output = CountryCodeAS;
            if (inputStr == "AD") output = CountryCodeAD;
            if (inputStr == "AO") output = CountryCodeAO;
            if (inputStr == "AI") output = CountryCodeAI;
            if (inputStr == "AQ") output = CountryCodeAQ;
            if (inputStr == "AG") output = CountryCodeAG;
            if (inputStr == "AR") output = CountryCodeAR;
            if (inputStr == "AM") output = CountryCodeAM;
            if (inputStr == "AW") output = CountryCodeAW;
            if (inputStr == "AU") output = CountryCodeAU;
            if (inputStr == "AT") output = CountryCodeAT;
            if (inputStr == "AZ") output = CountryCodeAZ;
            if (inputStr == "BS") output = CountryCodeBS;
            if (inputStr == "BH") output = CountryCodeBH;
            if (inputStr == "BD") output = CountryCodeBD;
            if (inputStr == "BB") output = CountryCodeBB;
            if (inputStr == "BY") output = CountryCodeBY;
            if (inputStr == "BE") output = CountryCodeBE;
            if (inputStr == "BZ") output = CountryCodeBZ;
            if (inputStr == "BJ") output = CountryCodeBJ;
            if (inputStr == "BM") output = CountryCodeBM;
            if (inputStr == "BT") output = CountryCodeBT;
            if (inputStr == "BO") output = CountryCodeBO;
            if (inputStr == "BQ") output = CountryCodeBQ;
            if (inputStr == "BA") output = CountryCodeBA;
            if (inputStr == "BW") output = CountryCodeBW;
            if (inputStr == "BV") output = CountryCodeBV;
            if (inputStr == "BR") output = CountryCodeBR;
            if (inputStr == "IO") output = CountryCodeIO;
            if (inputStr == "BN") output = CountryCodeBN;
            if (inputStr == "BG") output = CountryCodeBG;
            if (inputStr == "BF") output = CountryCodeBF;
            if (inputStr == "BI") output = CountryCodeBI;
            if (inputStr == "KH") output = CountryCodeKH;
            if (inputStr == "CM") output = CountryCodeCM;
            if (inputStr == "CA") output = CountryCodeCA;
            if (inputStr == "CV") output = CountryCodeCV;
            if (inputStr == "KY") output = CountryCodeKY;
            if (inputStr == "CF") output = CountryCodeCF;
            if (inputStr == "TD") output = CountryCodeTD;
            if (inputStr == "CL") output = CountryCodeCL;
            if (inputStr == "CN") output = CountryCodeCN;
            if (inputStr == "CX") output = CountryCodeCX;
            if (inputStr == "CC") output = CountryCodeCC;
            if (inputStr == "CO") output = CountryCodeCO;
            if (inputStr == "KM") output = CountryCodeKM;
            if (inputStr == "CG") output = CountryCodeCG;
            if (inputStr == "CD") output = CountryCodeCD;
            if (inputStr == "CK") output = CountryCodeCK;
            if (inputStr == "CR") output = CountryCodeCR;
            if (inputStr == "CI") output = CountryCodeCI;
            if (inputStr == "HR") output = CountryCodeHR;
            if (inputStr == "CU") output = CountryCodeCU;
            if (inputStr == "CW") output = CountryCodeCW;
            if (inputStr == "CY") output = CountryCodeCY;
            if (inputStr == "CZ") output = CountryCodeCZ;
            if (inputStr == "DK") output = CountryCodeDK;
            if (inputStr == "DJ") output = CountryCodeDJ;
            if (inputStr == "DM") output = CountryCodeDM;
            if (inputStr == "DO") output = CountryCodeDO;
            if (inputStr == "EC") output = CountryCodeEC;
            if (inputStr == "EG") output = CountryCodeEG;
            if (inputStr == "SV") output = CountryCodeSV;
            if (inputStr == "GQ") output = CountryCodeGQ;
            if (inputStr == "ER") output = CountryCodeER;
            if (inputStr == "EE") output = CountryCodeEE;
            if (inputStr == "ET") output = CountryCodeET;
            if (inputStr == "FK") output = CountryCodeFK;
            if (inputStr == "FO") output = CountryCodeFO;
            if (inputStr == "FJ") output = CountryCodeFJ;
            if (inputStr == "FI") output = CountryCodeFI;
            if (inputStr == "FR") output = CountryCodeFR;
            if (inputStr == "GF") output = CountryCodeGF;
            if (inputStr == "PF") output = CountryCodePF;
            if (inputStr == "TF") output = CountryCodeTF;
            if (inputStr == "GA") output = CountryCodeGA;
            if (inputStr == "GM") output = CountryCodeGM;
            if (inputStr == "GE") output = CountryCodeGE;
            if (inputStr == "DE") output = CountryCodeDE;
            if (inputStr == "GH") output = CountryCodeGH;
            if (inputStr == "GI") output = CountryCodeGI;
            if (inputStr == "GR") output = CountryCodeGR;
            if (inputStr == "GL") output = CountryCodeGL;
            if (inputStr == "GD") output = CountryCodeGD;
            if (inputStr == "GP") output = CountryCodeGP;
            if (inputStr == "GU") output = CountryCodeGU;
            if (inputStr == "GT") output = CountryCodeGT;
            if (inputStr == "GG") output = CountryCodeGG;
            if (inputStr == "GN") output = CountryCodeGN;
            if (inputStr == "GW") output = CountryCodeGW;
            if (inputStr == "GY") output = CountryCodeGY;
            if (inputStr == "HT") output = CountryCodeHT;
            if (inputStr == "HM") output = CountryCodeHM;
            if (inputStr == "VA") output = CountryCodeVA;
            if (inputStr == "HN") output = CountryCodeHN;
            if (inputStr == "HK") output = CountryCodeHK;
            if (inputStr == "HU") output = CountryCodeHU;
            if (inputStr == "IS") output = CountryCodeIS;
            if (inputStr == "IN") output = CountryCodeIN;
            if (inputStr == "ID") output = CountryCodeID;
            if (inputStr == "IR") output = CountryCodeIR;
            if (inputStr == "IQ") output = CountryCodeIQ;
            if (inputStr == "IE") output = CountryCodeIE;
            if (inputStr == "IM") output = CountryCodeIM;
            if (inputStr == "IL") output = CountryCodeIL;
            if (inputStr == "IT") output = CountryCodeIT;
            if (inputStr == "JM") output = CountryCodeJM;
            if (inputStr == "JP") output = CountryCodeJP;
            if (inputStr == "JE") output = CountryCodeJE;
            if (inputStr == "JO") output = CountryCodeJO;
            if (inputStr == "KZ") output = CountryCodeKZ;
            if (inputStr == "KE") output = CountryCodeKE;
            if (inputStr == "KI") output = CountryCodeKI;
            if (inputStr == "KP") output = CountryCodeKP;
            if (inputStr == "KR") output = CountryCodeKR;
            if (inputStr == "KW") output = CountryCodeKW;
            if (inputStr == "KG") output = CountryCodeKG;
            if (inputStr == "LA") output = CountryCodeLA;
            if (inputStr == "LV") output = CountryCodeLV;
            if (inputStr == "LB") output = CountryCodeLB;
            if (inputStr == "LS") output = CountryCodeLS;
            if (inputStr == "LR") output = CountryCodeLR;
            if (inputStr == "LY") output = CountryCodeLY;
            if (inputStr == "LI") output = CountryCodeLI;
            if (inputStr == "LT") output = CountryCodeLT;
            if (inputStr == "LU") output = CountryCodeLU;
            if (inputStr == "MO") output = CountryCodeMO;
            if (inputStr == "MK") output = CountryCodeMK;
            if (inputStr == "MG") output = CountryCodeMG;
            if (inputStr == "MW") output = CountryCodeMW;
            if (inputStr == "MY") output = CountryCodeMY;
            if (inputStr == "MV") output = CountryCodeMV;
            if (inputStr == "ML") output = CountryCodeML;
            if (inputStr == "MT") output = CountryCodeMT;
            if (inputStr == "MH") output = CountryCodeMH;
            if (inputStr == "MQ") output = CountryCodeMQ;
            if (inputStr == "MR") output = CountryCodeMR;
            if (inputStr == "MU") output = CountryCodeMU;
            if (inputStr == "YT") output = CountryCodeYT;
            if (inputStr == "MX") output = CountryCodeMX;
            if (inputStr == "FM") output = CountryCodeFM;
            if (inputStr == "MD") output = CountryCodeMD;
            if (inputStr == "MC") output = CountryCodeMC;
            if (inputStr == "MN") output = CountryCodeMN;
            if (inputStr == "ME") output = CountryCodeME;
            if (inputStr == "MS") output = CountryCodeMS;
            if (inputStr == "MA") output = CountryCodeMA;
            if (inputStr == "MZ") output = CountryCodeMZ;
            if (inputStr == "MM") output = CountryCodeMM;
            if (inputStr == "NA") output = CountryCodeNA;
            if (inputStr == "NR") output = CountryCodeNR;
            if (inputStr == "NP") output = CountryCodeNP;
            if (inputStr == "NL") output = CountryCodeNL;
            if (inputStr == "NC") output = CountryCodeNC;
            if (inputStr == "NZ") output = CountryCodeNZ;
            if (inputStr == "NI") output = CountryCodeNI;
            if (inputStr == "NE") output = CountryCodeNE;
            if (inputStr == "NG") output = CountryCodeNG;
            if (inputStr == "NU") output = CountryCodeNU;
            if (inputStr == "NF") output = CountryCodeNF;
            if (inputStr == "MP") output = CountryCodeMP;
            if (inputStr == "NO") output = CountryCodeNO;
            if (inputStr == "OM") output = CountryCodeOM;
            if (inputStr == "PK") output = CountryCodePK;
            if (inputStr == "PW") output = CountryCodePW;
            if (inputStr == "PS") output = CountryCodePS;
            if (inputStr == "PA") output = CountryCodePA;
            if (inputStr == "PG") output = CountryCodePG;
            if (inputStr == "PY") output = CountryCodePY;
            if (inputStr == "PE") output = CountryCodePE;
            if (inputStr == "PH") output = CountryCodePH;
            if (inputStr == "PN") output = CountryCodePN;
            if (inputStr == "PL") output = CountryCodePL;
            if (inputStr == "PT") output = CountryCodePT;
            if (inputStr == "PR") output = CountryCodePR;
            if (inputStr == "QA") output = CountryCodeQA;
            if (inputStr == "RE") output = CountryCodeRE;
            if (inputStr == "RO") output = CountryCodeRO;
            if (inputStr == "RU") output = CountryCodeRU;
            if (inputStr == "RW") output = CountryCodeRW;
            if (inputStr == "BL") output = CountryCodeBL;
            if (inputStr == "SH") output = CountryCodeSH;
            if (inputStr == "KN") output = CountryCodeKN;
            if (inputStr == "LC") output = CountryCodeLC;
            if (inputStr == "MF") output = CountryCodeMF;
            if (inputStr == "PM") output = CountryCodePM;
            if (inputStr == "VC") output = CountryCodeVC;
            if (inputStr == "WS") output = CountryCodeWS;
            if (inputStr == "SM") output = CountryCodeSM;
            if (inputStr == "ST") output = CountryCodeST;
            if (inputStr == "SA") output = CountryCodeSA;
            if (inputStr == "SN") output = CountryCodeSN;
            if (inputStr == "RS") output = CountryCodeRS;
            if (inputStr == "SC") output = CountryCodeSC;
            if (inputStr == "SL") output = CountryCodeSL;
            if (inputStr == "SG") output = CountryCodeSG;
            if (inputStr == "SX") output = CountryCodeSX;
            if (inputStr == "SK") output = CountryCodeSK;
            if (inputStr == "SI") output = CountryCodeSI;
            if (inputStr == "SB") output = CountryCodeSB;
            if (inputStr == "SO") output = CountryCodeSO;
            if (inputStr == "ZA") output = CountryCodeZA;
            if (inputStr == "GS") output = CountryCodeGS;
            if (inputStr == "SS") output = CountryCodeSS;
            if (inputStr == "ES") output = CountryCodeES;
            if (inputStr == "LK") output = CountryCodeLK;
            if (inputStr == "SD") output = CountryCodeSD;
            if (inputStr == "SR") output = CountryCodeSR;
            if (inputStr == "SJ") output = CountryCodeSJ;
            if (inputStr == "SZ") output = CountryCodeSZ;
            if (inputStr == "SE") output = CountryCodeSE;
            if (inputStr == "CH") output = CountryCodeCH;
            if (inputStr == "SY") output = CountryCodeSY;
            if (inputStr == "TW") output = CountryCodeTW;
            if (inputStr == "TJ") output = CountryCodeTJ;
            if (inputStr == "TZ") output = CountryCodeTZ;
            if (inputStr == "TH") output = CountryCodeTH;
            if (inputStr == "TL") output = CountryCodeTL;
            if (inputStr == "TG") output = CountryCodeTG;
            if (inputStr == "TK") output = CountryCodeTK;
            if (inputStr == "TO") output = CountryCodeTO;
            if (inputStr == "TT") output = CountryCodeTT;
            if (inputStr == "TN") output = CountryCodeTN;
            if (inputStr == "TR") output = CountryCodeTR;
            if (inputStr == "TM") output = CountryCodeTM;
            if (inputStr == "TC") output = CountryCodeTC;
            if (inputStr == "TV") output = CountryCodeTV;
            if (inputStr == "UG") output = CountryCodeUG;
            if (inputStr == "UA") output = CountryCodeUA;
            if (inputStr == "AE") output = CountryCodeAE;
            if (inputStr == "GB") output = CountryCodeGB;
            if (inputStr == "US") output = CountryCodeUS;
            if (inputStr == "UM") output = CountryCodeUM;
            if (inputStr == "UY") output = CountryCodeUY;
            if (inputStr == "UZ") output = CountryCodeUZ;
            if (inputStr == "VU") output = CountryCodeVU;
            if (inputStr == "VE") output = CountryCodeVE;
            if (inputStr == "VN") output = CountryCodeVN;
            if (inputStr == "VG") output = CountryCodeVG;
            if (inputStr == "VI") output = CountryCodeVI;
            if (inputStr == "WF") output = CountryCodeWF;
            if (inputStr == "EH") output = CountryCodeEH;
            if (inputStr == "YE") output = CountryCodeYE;
            if (inputStr == "ZM") output = CountryCodeZM;
            if (inputStr == "ZW") output = CountryCodeZW;
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

        inline void ToJsonEnum(const Currency input, Json::Value& output)
        {
            if (input == CurrencyAED) output = Json::Value("AED");
            if (input == CurrencyAFN) output = Json::Value("AFN");
            if (input == CurrencyALL) output = Json::Value("ALL");
            if (input == CurrencyAMD) output = Json::Value("AMD");
            if (input == CurrencyANG) output = Json::Value("ANG");
            if (input == CurrencyAOA) output = Json::Value("AOA");
            if (input == CurrencyARS) output = Json::Value("ARS");
            if (input == CurrencyAUD) output = Json::Value("AUD");
            if (input == CurrencyAWG) output = Json::Value("AWG");
            if (input == CurrencyAZN) output = Json::Value("AZN");
            if (input == CurrencyBAM) output = Json::Value("BAM");
            if (input == CurrencyBBD) output = Json::Value("BBD");
            if (input == CurrencyBDT) output = Json::Value("BDT");
            if (input == CurrencyBGN) output = Json::Value("BGN");
            if (input == CurrencyBHD) output = Json::Value("BHD");
            if (input == CurrencyBIF) output = Json::Value("BIF");
            if (input == CurrencyBMD) output = Json::Value("BMD");
            if (input == CurrencyBND) output = Json::Value("BND");
            if (input == CurrencyBOB) output = Json::Value("BOB");
            if (input == CurrencyBRL) output = Json::Value("BRL");
            if (input == CurrencyBSD) output = Json::Value("BSD");
            if (input == CurrencyBTN) output = Json::Value("BTN");
            if (input == CurrencyBWP) output = Json::Value("BWP");
            if (input == CurrencyBYR) output = Json::Value("BYR");
            if (input == CurrencyBZD) output = Json::Value("BZD");
            if (input == CurrencyCAD) output = Json::Value("CAD");
            if (input == CurrencyCDF) output = Json::Value("CDF");
            if (input == CurrencyCHF) output = Json::Value("CHF");
            if (input == CurrencyCLP) output = Json::Value("CLP");
            if (input == CurrencyCNY) output = Json::Value("CNY");
            if (input == CurrencyCOP) output = Json::Value("COP");
            if (input == CurrencyCRC) output = Json::Value("CRC");
            if (input == CurrencyCUC) output = Json::Value("CUC");
            if (input == CurrencyCUP) output = Json::Value("CUP");
            if (input == CurrencyCVE) output = Json::Value("CVE");
            if (input == CurrencyCZK) output = Json::Value("CZK");
            if (input == CurrencyDJF) output = Json::Value("DJF");
            if (input == CurrencyDKK) output = Json::Value("DKK");
            if (input == CurrencyDOP) output = Json::Value("DOP");
            if (input == CurrencyDZD) output = Json::Value("DZD");
            if (input == CurrencyEGP) output = Json::Value("EGP");
            if (input == CurrencyERN) output = Json::Value("ERN");
            if (input == CurrencyETB) output = Json::Value("ETB");
            if (input == CurrencyEUR) output = Json::Value("EUR");
            if (input == CurrencyFJD) output = Json::Value("FJD");
            if (input == CurrencyFKP) output = Json::Value("FKP");
            if (input == CurrencyGBP) output = Json::Value("GBP");
            if (input == CurrencyGEL) output = Json::Value("GEL");
            if (input == CurrencyGGP) output = Json::Value("GGP");
            if (input == CurrencyGHS) output = Json::Value("GHS");
            if (input == CurrencyGIP) output = Json::Value("GIP");
            if (input == CurrencyGMD) output = Json::Value("GMD");
            if (input == CurrencyGNF) output = Json::Value("GNF");
            if (input == CurrencyGTQ) output = Json::Value("GTQ");
            if (input == CurrencyGYD) output = Json::Value("GYD");
            if (input == CurrencyHKD) output = Json::Value("HKD");
            if (input == CurrencyHNL) output = Json::Value("HNL");
            if (input == CurrencyHRK) output = Json::Value("HRK");
            if (input == CurrencyHTG) output = Json::Value("HTG");
            if (input == CurrencyHUF) output = Json::Value("HUF");
            if (input == CurrencyIDR) output = Json::Value("IDR");
            if (input == CurrencyILS) output = Json::Value("ILS");
            if (input == CurrencyIMP) output = Json::Value("IMP");
            if (input == CurrencyINR) output = Json::Value("INR");
            if (input == CurrencyIQD) output = Json::Value("IQD");
            if (input == CurrencyIRR) output = Json::Value("IRR");
            if (input == CurrencyISK) output = Json::Value("ISK");
            if (input == CurrencyJEP) output = Json::Value("JEP");
            if (input == CurrencyJMD) output = Json::Value("JMD");
            if (input == CurrencyJOD) output = Json::Value("JOD");
            if (input == CurrencyJPY) output = Json::Value("JPY");
            if (input == CurrencyKES) output = Json::Value("KES");
            if (input == CurrencyKGS) output = Json::Value("KGS");
            if (input == CurrencyKHR) output = Json::Value("KHR");
            if (input == CurrencyKMF) output = Json::Value("KMF");
            if (input == CurrencyKPW) output = Json::Value("KPW");
            if (input == CurrencyKRW) output = Json::Value("KRW");
            if (input == CurrencyKWD) output = Json::Value("KWD");
            if (input == CurrencyKYD) output = Json::Value("KYD");
            if (input == CurrencyKZT) output = Json::Value("KZT");
            if (input == CurrencyLAK) output = Json::Value("LAK");
            if (input == CurrencyLBP) output = Json::Value("LBP");
            if (input == CurrencyLKR) output = Json::Value("LKR");
            if (input == CurrencyLRD) output = Json::Value("LRD");
            if (input == CurrencyLSL) output = Json::Value("LSL");
            if (input == CurrencyLYD) output = Json::Value("LYD");
            if (input == CurrencyMAD) output = Json::Value("MAD");
            if (input == CurrencyMDL) output = Json::Value("MDL");
            if (input == CurrencyMGA) output = Json::Value("MGA");
            if (input == CurrencyMKD) output = Json::Value("MKD");
            if (input == CurrencyMMK) output = Json::Value("MMK");
            if (input == CurrencyMNT) output = Json::Value("MNT");
            if (input == CurrencyMOP) output = Json::Value("MOP");
            if (input == CurrencyMRO) output = Json::Value("MRO");
            if (input == CurrencyMUR) output = Json::Value("MUR");
            if (input == CurrencyMVR) output = Json::Value("MVR");
            if (input == CurrencyMWK) output = Json::Value("MWK");
            if (input == CurrencyMXN) output = Json::Value("MXN");
            if (input == CurrencyMYR) output = Json::Value("MYR");
            if (input == CurrencyMZN) output = Json::Value("MZN");
            if (input == CurrencyNAD) output = Json::Value("NAD");
            if (input == CurrencyNGN) output = Json::Value("NGN");
            if (input == CurrencyNIO) output = Json::Value("NIO");
            if (input == CurrencyNOK) output = Json::Value("NOK");
            if (input == CurrencyNPR) output = Json::Value("NPR");
            if (input == CurrencyNZD) output = Json::Value("NZD");
            if (input == CurrencyOMR) output = Json::Value("OMR");
            if (input == CurrencyPAB) output = Json::Value("PAB");
            if (input == CurrencyPEN) output = Json::Value("PEN");
            if (input == CurrencyPGK) output = Json::Value("PGK");
            if (input == CurrencyPHP) output = Json::Value("PHP");
            if (input == CurrencyPKR) output = Json::Value("PKR");
            if (input == CurrencyPLN) output = Json::Value("PLN");
            if (input == CurrencyPYG) output = Json::Value("PYG");
            if (input == CurrencyQAR) output = Json::Value("QAR");
            if (input == CurrencyRON) output = Json::Value("RON");
            if (input == CurrencyRSD) output = Json::Value("RSD");
            if (input == CurrencyRUB) output = Json::Value("RUB");
            if (input == CurrencyRWF) output = Json::Value("RWF");
            if (input == CurrencySAR) output = Json::Value("SAR");
            if (input == CurrencySBD) output = Json::Value("SBD");
            if (input == CurrencySCR) output = Json::Value("SCR");
            if (input == CurrencySDG) output = Json::Value("SDG");
            if (input == CurrencySEK) output = Json::Value("SEK");
            if (input == CurrencySGD) output = Json::Value("SGD");
            if (input == CurrencySHP) output = Json::Value("SHP");
            if (input == CurrencySLL) output = Json::Value("SLL");
            if (input == CurrencySOS) output = Json::Value("SOS");
            if (input == CurrencySPL) output = Json::Value("SPL");
            if (input == CurrencySRD) output = Json::Value("SRD");
            if (input == CurrencySTD) output = Json::Value("STD");
            if (input == CurrencySVC) output = Json::Value("SVC");
            if (input == CurrencySYP) output = Json::Value("SYP");
            if (input == CurrencySZL) output = Json::Value("SZL");
            if (input == CurrencyTHB) output = Json::Value("THB");
            if (input == CurrencyTJS) output = Json::Value("TJS");
            if (input == CurrencyTMT) output = Json::Value("TMT");
            if (input == CurrencyTND) output = Json::Value("TND");
            if (input == CurrencyTOP) output = Json::Value("TOP");
            if (input == CurrencyTRY) output = Json::Value("TRY");
            if (input == CurrencyTTD) output = Json::Value("TTD");
            if (input == CurrencyTVD) output = Json::Value("TVD");
            if (input == CurrencyTWD) output = Json::Value("TWD");
            if (input == CurrencyTZS) output = Json::Value("TZS");
            if (input == CurrencyUAH) output = Json::Value("UAH");
            if (input == CurrencyUGX) output = Json::Value("UGX");
            if (input == CurrencyUSD) output = Json::Value("USD");
            if (input == CurrencyUYU) output = Json::Value("UYU");
            if (input == CurrencyUZS) output = Json::Value("UZS");
            if (input == CurrencyVEF) output = Json::Value("VEF");
            if (input == CurrencyVND) output = Json::Value("VND");
            if (input == CurrencyVUV) output = Json::Value("VUV");
            if (input == CurrencyWST) output = Json::Value("WST");
            if (input == CurrencyXAF) output = Json::Value("XAF");
            if (input == CurrencyXCD) output = Json::Value("XCD");
            if (input == CurrencyXDR) output = Json::Value("XDR");
            if (input == CurrencyXOF) output = Json::Value("XOF");
            if (input == CurrencyXPF) output = Json::Value("XPF");
            if (input == CurrencyYER) output = Json::Value("YER");
            if (input == CurrencyZAR) output = Json::Value("ZAR");
            if (input == CurrencyZMW) output = Json::Value("ZMW");
            if (input == CurrencyZWD) output = Json::Value("ZWD");
        }
        inline void FromJsonEnum(const Json::Value& input, Currency& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "AED") output = CurrencyAED;
            if (inputStr == "AFN") output = CurrencyAFN;
            if (inputStr == "ALL") output = CurrencyALL;
            if (inputStr == "AMD") output = CurrencyAMD;
            if (inputStr == "ANG") output = CurrencyANG;
            if (inputStr == "AOA") output = CurrencyAOA;
            if (inputStr == "ARS") output = CurrencyARS;
            if (inputStr == "AUD") output = CurrencyAUD;
            if (inputStr == "AWG") output = CurrencyAWG;
            if (inputStr == "AZN") output = CurrencyAZN;
            if (inputStr == "BAM") output = CurrencyBAM;
            if (inputStr == "BBD") output = CurrencyBBD;
            if (inputStr == "BDT") output = CurrencyBDT;
            if (inputStr == "BGN") output = CurrencyBGN;
            if (inputStr == "BHD") output = CurrencyBHD;
            if (inputStr == "BIF") output = CurrencyBIF;
            if (inputStr == "BMD") output = CurrencyBMD;
            if (inputStr == "BND") output = CurrencyBND;
            if (inputStr == "BOB") output = CurrencyBOB;
            if (inputStr == "BRL") output = CurrencyBRL;
            if (inputStr == "BSD") output = CurrencyBSD;
            if (inputStr == "BTN") output = CurrencyBTN;
            if (inputStr == "BWP") output = CurrencyBWP;
            if (inputStr == "BYR") output = CurrencyBYR;
            if (inputStr == "BZD") output = CurrencyBZD;
            if (inputStr == "CAD") output = CurrencyCAD;
            if (inputStr == "CDF") output = CurrencyCDF;
            if (inputStr == "CHF") output = CurrencyCHF;
            if (inputStr == "CLP") output = CurrencyCLP;
            if (inputStr == "CNY") output = CurrencyCNY;
            if (inputStr == "COP") output = CurrencyCOP;
            if (inputStr == "CRC") output = CurrencyCRC;
            if (inputStr == "CUC") output = CurrencyCUC;
            if (inputStr == "CUP") output = CurrencyCUP;
            if (inputStr == "CVE") output = CurrencyCVE;
            if (inputStr == "CZK") output = CurrencyCZK;
            if (inputStr == "DJF") output = CurrencyDJF;
            if (inputStr == "DKK") output = CurrencyDKK;
            if (inputStr == "DOP") output = CurrencyDOP;
            if (inputStr == "DZD") output = CurrencyDZD;
            if (inputStr == "EGP") output = CurrencyEGP;
            if (inputStr == "ERN") output = CurrencyERN;
            if (inputStr == "ETB") output = CurrencyETB;
            if (inputStr == "EUR") output = CurrencyEUR;
            if (inputStr == "FJD") output = CurrencyFJD;
            if (inputStr == "FKP") output = CurrencyFKP;
            if (inputStr == "GBP") output = CurrencyGBP;
            if (inputStr == "GEL") output = CurrencyGEL;
            if (inputStr == "GGP") output = CurrencyGGP;
            if (inputStr == "GHS") output = CurrencyGHS;
            if (inputStr == "GIP") output = CurrencyGIP;
            if (inputStr == "GMD") output = CurrencyGMD;
            if (inputStr == "GNF") output = CurrencyGNF;
            if (inputStr == "GTQ") output = CurrencyGTQ;
            if (inputStr == "GYD") output = CurrencyGYD;
            if (inputStr == "HKD") output = CurrencyHKD;
            if (inputStr == "HNL") output = CurrencyHNL;
            if (inputStr == "HRK") output = CurrencyHRK;
            if (inputStr == "HTG") output = CurrencyHTG;
            if (inputStr == "HUF") output = CurrencyHUF;
            if (inputStr == "IDR") output = CurrencyIDR;
            if (inputStr == "ILS") output = CurrencyILS;
            if (inputStr == "IMP") output = CurrencyIMP;
            if (inputStr == "INR") output = CurrencyINR;
            if (inputStr == "IQD") output = CurrencyIQD;
            if (inputStr == "IRR") output = CurrencyIRR;
            if (inputStr == "ISK") output = CurrencyISK;
            if (inputStr == "JEP") output = CurrencyJEP;
            if (inputStr == "JMD") output = CurrencyJMD;
            if (inputStr == "JOD") output = CurrencyJOD;
            if (inputStr == "JPY") output = CurrencyJPY;
            if (inputStr == "KES") output = CurrencyKES;
            if (inputStr == "KGS") output = CurrencyKGS;
            if (inputStr == "KHR") output = CurrencyKHR;
            if (inputStr == "KMF") output = CurrencyKMF;
            if (inputStr == "KPW") output = CurrencyKPW;
            if (inputStr == "KRW") output = CurrencyKRW;
            if (inputStr == "KWD") output = CurrencyKWD;
            if (inputStr == "KYD") output = CurrencyKYD;
            if (inputStr == "KZT") output = CurrencyKZT;
            if (inputStr == "LAK") output = CurrencyLAK;
            if (inputStr == "LBP") output = CurrencyLBP;
            if (inputStr == "LKR") output = CurrencyLKR;
            if (inputStr == "LRD") output = CurrencyLRD;
            if (inputStr == "LSL") output = CurrencyLSL;
            if (inputStr == "LYD") output = CurrencyLYD;
            if (inputStr == "MAD") output = CurrencyMAD;
            if (inputStr == "MDL") output = CurrencyMDL;
            if (inputStr == "MGA") output = CurrencyMGA;
            if (inputStr == "MKD") output = CurrencyMKD;
            if (inputStr == "MMK") output = CurrencyMMK;
            if (inputStr == "MNT") output = CurrencyMNT;
            if (inputStr == "MOP") output = CurrencyMOP;
            if (inputStr == "MRO") output = CurrencyMRO;
            if (inputStr == "MUR") output = CurrencyMUR;
            if (inputStr == "MVR") output = CurrencyMVR;
            if (inputStr == "MWK") output = CurrencyMWK;
            if (inputStr == "MXN") output = CurrencyMXN;
            if (inputStr == "MYR") output = CurrencyMYR;
            if (inputStr == "MZN") output = CurrencyMZN;
            if (inputStr == "NAD") output = CurrencyNAD;
            if (inputStr == "NGN") output = CurrencyNGN;
            if (inputStr == "NIO") output = CurrencyNIO;
            if (inputStr == "NOK") output = CurrencyNOK;
            if (inputStr == "NPR") output = CurrencyNPR;
            if (inputStr == "NZD") output = CurrencyNZD;
            if (inputStr == "OMR") output = CurrencyOMR;
            if (inputStr == "PAB") output = CurrencyPAB;
            if (inputStr == "PEN") output = CurrencyPEN;
            if (inputStr == "PGK") output = CurrencyPGK;
            if (inputStr == "PHP") output = CurrencyPHP;
            if (inputStr == "PKR") output = CurrencyPKR;
            if (inputStr == "PLN") output = CurrencyPLN;
            if (inputStr == "PYG") output = CurrencyPYG;
            if (inputStr == "QAR") output = CurrencyQAR;
            if (inputStr == "RON") output = CurrencyRON;
            if (inputStr == "RSD") output = CurrencyRSD;
            if (inputStr == "RUB") output = CurrencyRUB;
            if (inputStr == "RWF") output = CurrencyRWF;
            if (inputStr == "SAR") output = CurrencySAR;
            if (inputStr == "SBD") output = CurrencySBD;
            if (inputStr == "SCR") output = CurrencySCR;
            if (inputStr == "SDG") output = CurrencySDG;
            if (inputStr == "SEK") output = CurrencySEK;
            if (inputStr == "SGD") output = CurrencySGD;
            if (inputStr == "SHP") output = CurrencySHP;
            if (inputStr == "SLL") output = CurrencySLL;
            if (inputStr == "SOS") output = CurrencySOS;
            if (inputStr == "SPL") output = CurrencySPL;
            if (inputStr == "SRD") output = CurrencySRD;
            if (inputStr == "STD") output = CurrencySTD;
            if (inputStr == "SVC") output = CurrencySVC;
            if (inputStr == "SYP") output = CurrencySYP;
            if (inputStr == "SZL") output = CurrencySZL;
            if (inputStr == "THB") output = CurrencyTHB;
            if (inputStr == "TJS") output = CurrencyTJS;
            if (inputStr == "TMT") output = CurrencyTMT;
            if (inputStr == "TND") output = CurrencyTND;
            if (inputStr == "TOP") output = CurrencyTOP;
            if (inputStr == "TRY") output = CurrencyTRY;
            if (inputStr == "TTD") output = CurrencyTTD;
            if (inputStr == "TVD") output = CurrencyTVD;
            if (inputStr == "TWD") output = CurrencyTWD;
            if (inputStr == "TZS") output = CurrencyTZS;
            if (inputStr == "UAH") output = CurrencyUAH;
            if (inputStr == "UGX") output = CurrencyUGX;
            if (inputStr == "USD") output = CurrencyUSD;
            if (inputStr == "UYU") output = CurrencyUYU;
            if (inputStr == "UZS") output = CurrencyUZS;
            if (inputStr == "VEF") output = CurrencyVEF;
            if (inputStr == "VND") output = CurrencyVND;
            if (inputStr == "VUV") output = CurrencyVUV;
            if (inputStr == "WST") output = CurrencyWST;
            if (inputStr == "XAF") output = CurrencyXAF;
            if (inputStr == "XCD") output = CurrencyXCD;
            if (inputStr == "XDR") output = CurrencyXDR;
            if (inputStr == "XOF") output = CurrencyXOF;
            if (inputStr == "XPF") output = CurrencyXPF;
            if (inputStr == "YER") output = CurrencyYER;
            if (inputStr == "ZAR") output = CurrencyZAR;
            if (inputStr == "ZMW") output = CurrencyZMW;
            if (inputStr == "ZWD") output = CurrencyZWD;
        }

        enum EmailVerificationStatus
        {
            EmailVerificationStatusUnverified,
            EmailVerificationStatusPending,
            EmailVerificationStatusConfirmed
        };

        inline void ToJsonEnum(const EmailVerificationStatus input, Json::Value& output)
        {
            if (input == EmailVerificationStatusUnverified) output = Json::Value("Unverified");
            if (input == EmailVerificationStatusPending) output = Json::Value("Pending");
            if (input == EmailVerificationStatusConfirmed) output = Json::Value("Confirmed");
        }
        inline void FromJsonEnum(const Json::Value& input, EmailVerificationStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Unverified") output = EmailVerificationStatusUnverified;
            if (inputStr == "Pending") output = EmailVerificationStatusPending;
            if (inputStr == "Confirmed") output = EmailVerificationStatusConfirmed;
        }

        enum GameInstanceState
        {
            GameInstanceStateOpen,
            GameInstanceStateClosed
        };

        inline void ToJsonEnum(const GameInstanceState input, Json::Value& output)
        {
            if (input == GameInstanceStateOpen) output = Json::Value("Open");
            if (input == GameInstanceStateClosed) output = Json::Value("Closed");
        }
        inline void FromJsonEnum(const Json::Value& input, GameInstanceState& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Open") output = GameInstanceStateOpen;
            if (inputStr == "Closed") output = GameInstanceStateClosed;
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
            LoginIdentityProviderFacebookInstantGames,
            LoginIdentityProviderOpenIdConnect
        };

        inline void ToJsonEnum(const LoginIdentityProvider input, Json::Value& output)
        {
            if (input == LoginIdentityProviderUnknown) output = Json::Value("Unknown");
            if (input == LoginIdentityProviderPlayFab) output = Json::Value("PlayFab");
            if (input == LoginIdentityProviderCustom) output = Json::Value("Custom");
            if (input == LoginIdentityProviderGameCenter) output = Json::Value("GameCenter");
            if (input == LoginIdentityProviderGooglePlay) output = Json::Value("GooglePlay");
            if (input == LoginIdentityProviderSteam) output = Json::Value("Steam");
            if (input == LoginIdentityProviderXBoxLive) output = Json::Value("XBoxLive");
            if (input == LoginIdentityProviderPSN) output = Json::Value("PSN");
            if (input == LoginIdentityProviderKongregate) output = Json::Value("Kongregate");
            if (input == LoginIdentityProviderFacebook) output = Json::Value("Facebook");
            if (input == LoginIdentityProviderIOSDevice) output = Json::Value("IOSDevice");
            if (input == LoginIdentityProviderAndroidDevice) output = Json::Value("AndroidDevice");
            if (input == LoginIdentityProviderTwitch) output = Json::Value("Twitch");
            if (input == LoginIdentityProviderWindowsHello) output = Json::Value("WindowsHello");
            if (input == LoginIdentityProviderGameServer) output = Json::Value("GameServer");
            if (input == LoginIdentityProviderCustomServer) output = Json::Value("CustomServer");
            if (input == LoginIdentityProviderNintendoSwitch) output = Json::Value("NintendoSwitch");
            if (input == LoginIdentityProviderFacebookInstantGames) output = Json::Value("FacebookInstantGames");
            if (input == LoginIdentityProviderOpenIdConnect) output = Json::Value("OpenIdConnect");
        }
        inline void FromJsonEnum(const Json::Value& input, LoginIdentityProvider& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown") output = LoginIdentityProviderUnknown;
            if (inputStr == "PlayFab") output = LoginIdentityProviderPlayFab;
            if (inputStr == "Custom") output = LoginIdentityProviderCustom;
            if (inputStr == "GameCenter") output = LoginIdentityProviderGameCenter;
            if (inputStr == "GooglePlay") output = LoginIdentityProviderGooglePlay;
            if (inputStr == "Steam") output = LoginIdentityProviderSteam;
            if (inputStr == "XBoxLive") output = LoginIdentityProviderXBoxLive;
            if (inputStr == "PSN") output = LoginIdentityProviderPSN;
            if (inputStr == "Kongregate") output = LoginIdentityProviderKongregate;
            if (inputStr == "Facebook") output = LoginIdentityProviderFacebook;
            if (inputStr == "IOSDevice") output = LoginIdentityProviderIOSDevice;
            if (inputStr == "AndroidDevice") output = LoginIdentityProviderAndroidDevice;
            if (inputStr == "Twitch") output = LoginIdentityProviderTwitch;
            if (inputStr == "WindowsHello") output = LoginIdentityProviderWindowsHello;
            if (inputStr == "GameServer") output = LoginIdentityProviderGameServer;
            if (inputStr == "CustomServer") output = LoginIdentityProviderCustomServer;
            if (inputStr == "NintendoSwitch") output = LoginIdentityProviderNintendoSwitch;
            if (inputStr == "FacebookInstantGames") output = LoginIdentityProviderFacebookInstantGames;
            if (inputStr == "OpenIdConnect") output = LoginIdentityProviderOpenIdConnect;
        }

        enum MatchmakeStatus
        {
            MatchmakeStatusComplete,
            MatchmakeStatusWaiting,
            MatchmakeStatusGameNotFound,
            MatchmakeStatusNoAvailableSlots,
            MatchmakeStatusSessionClosed
        };

        inline void ToJsonEnum(const MatchmakeStatus input, Json::Value& output)
        {
            if (input == MatchmakeStatusComplete) output = Json::Value("Complete");
            if (input == MatchmakeStatusWaiting) output = Json::Value("Waiting");
            if (input == MatchmakeStatusGameNotFound) output = Json::Value("GameNotFound");
            if (input == MatchmakeStatusNoAvailableSlots) output = Json::Value("NoAvailableSlots");
            if (input == MatchmakeStatusSessionClosed) output = Json::Value("SessionClosed");
        }
        inline void FromJsonEnum(const Json::Value& input, MatchmakeStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Complete") output = MatchmakeStatusComplete;
            if (inputStr == "Waiting") output = MatchmakeStatusWaiting;
            if (inputStr == "GameNotFound") output = MatchmakeStatusGameNotFound;
            if (inputStr == "NoAvailableSlots") output = MatchmakeStatusNoAvailableSlots;
            if (inputStr == "SessionClosed") output = MatchmakeStatusSessionClosed;
        }

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        inline void ToJsonEnum(const PushNotificationPlatform input, Json::Value& output)
        {
            if (input == PushNotificationPlatformApplePushNotificationService) output = Json::Value("ApplePushNotificationService");
            if (input == PushNotificationPlatformGoogleCloudMessaging) output = Json::Value("GoogleCloudMessaging");
        }
        inline void FromJsonEnum(const Json::Value& input, PushNotificationPlatform& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "ApplePushNotificationService") output = PushNotificationPlatformApplePushNotificationService;
            if (inputStr == "GoogleCloudMessaging") output = PushNotificationPlatformGoogleCloudMessaging;
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

        inline void ToJsonEnum(const Region input, Json::Value& output)
        {
            if (input == RegionUSCentral) output = Json::Value("USCentral");
            if (input == RegionUSEast) output = Json::Value("USEast");
            if (input == RegionEUWest) output = Json::Value("EUWest");
            if (input == RegionSingapore) output = Json::Value("Singapore");
            if (input == RegionJapan) output = Json::Value("Japan");
            if (input == RegionBrazil) output = Json::Value("Brazil");
            if (input == RegionAustralia) output = Json::Value("Australia");
        }
        inline void FromJsonEnum(const Json::Value& input, Region& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "USCentral") output = RegionUSCentral;
            if (inputStr == "USEast") output = RegionUSEast;
            if (inputStr == "EUWest") output = RegionEUWest;
            if (inputStr == "Singapore") output = RegionSingapore;
            if (inputStr == "Japan") output = RegionJapan;
            if (inputStr == "Brazil") output = RegionBrazil;
            if (inputStr == "Australia") output = RegionAustralia;
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

        inline void ToJsonEnum(const SourceType input, Json::Value& output)
        {
            if (input == SourceTypeAdmin) output = Json::Value("Admin");
            if (input == SourceTypeBackEnd) output = Json::Value("BackEnd");
            if (input == SourceTypeGameClient) output = Json::Value("GameClient");
            if (input == SourceTypeGameServer) output = Json::Value("GameServer");
            if (input == SourceTypePartner) output = Json::Value("Partner");
            if (input == SourceTypeCustom) output = Json::Value("Custom");
            if (input == SourceTypeAPI) output = Json::Value("API");
        }
        inline void FromJsonEnum(const Json::Value& input, SourceType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Admin") output = SourceTypeAdmin;
            if (inputStr == "BackEnd") output = SourceTypeBackEnd;
            if (inputStr == "GameClient") output = SourceTypeGameClient;
            if (inputStr == "GameServer") output = SourceTypeGameServer;
            if (inputStr == "Partner") output = SourceTypePartner;
            if (inputStr == "Custom") output = SourceTypeCustom;
            if (inputStr == "API") output = SourceTypeAPI;
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

        inline void ToJsonEnum(const SubscriptionProviderStatus input, Json::Value& output)
        {
            if (input == SubscriptionProviderStatusNoError) output = Json::Value("NoError");
            if (input == SubscriptionProviderStatusCancelled) output = Json::Value("Cancelled");
            if (input == SubscriptionProviderStatusUnknownError) output = Json::Value("UnknownError");
            if (input == SubscriptionProviderStatusBillingError) output = Json::Value("BillingError");
            if (input == SubscriptionProviderStatusProductUnavailable) output = Json::Value("ProductUnavailable");
            if (input == SubscriptionProviderStatusCustomerDidNotAcceptPriceChange) output = Json::Value("CustomerDidNotAcceptPriceChange");
            if (input == SubscriptionProviderStatusFreeTrial) output = Json::Value("FreeTrial");
            if (input == SubscriptionProviderStatusPaymentPending) output = Json::Value("PaymentPending");
        }
        inline void FromJsonEnum(const Json::Value& input, SubscriptionProviderStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "NoError") output = SubscriptionProviderStatusNoError;
            if (inputStr == "Cancelled") output = SubscriptionProviderStatusCancelled;
            if (inputStr == "UnknownError") output = SubscriptionProviderStatusUnknownError;
            if (inputStr == "BillingError") output = SubscriptionProviderStatusBillingError;
            if (inputStr == "ProductUnavailable") output = SubscriptionProviderStatusProductUnavailable;
            if (inputStr == "CustomerDidNotAcceptPriceChange") output = SubscriptionProviderStatusCustomerDidNotAcceptPriceChange;
            if (inputStr == "FreeTrial") output = SubscriptionProviderStatusFreeTrial;
            if (inputStr == "PaymentPending") output = SubscriptionProviderStatusPaymentPending;
        }

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        inline void ToJsonEnum(const TitleActivationStatus input, Json::Value& output)
        {
            if (input == TitleActivationStatusNone) output = Json::Value("None");
            if (input == TitleActivationStatusActivatedTitleKey) output = Json::Value("ActivatedTitleKey");
            if (input == TitleActivationStatusPendingSteam) output = Json::Value("PendingSteam");
            if (input == TitleActivationStatusActivatedSteam) output = Json::Value("ActivatedSteam");
            if (input == TitleActivationStatusRevokedSteam) output = Json::Value("RevokedSteam");
        }
        inline void FromJsonEnum(const Json::Value& input, TitleActivationStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "None") output = TitleActivationStatusNone;
            if (inputStr == "ActivatedTitleKey") output = TitleActivationStatusActivatedTitleKey;
            if (inputStr == "PendingSteam") output = TitleActivationStatusPendingSteam;
            if (inputStr == "ActivatedSteam") output = TitleActivationStatusActivatedSteam;
            if (inputStr == "RevokedSteam") output = TitleActivationStatusRevokedSteam;
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

        inline void ToJsonEnum(const TradeStatus input, Json::Value& output)
        {
            if (input == TradeStatusInvalid) output = Json::Value("Invalid");
            if (input == TradeStatusOpening) output = Json::Value("Opening");
            if (input == TradeStatusOpen) output = Json::Value("Open");
            if (input == TradeStatusAccepting) output = Json::Value("Accepting");
            if (input == TradeStatusAccepted) output = Json::Value("Accepted");
            if (input == TradeStatusFilled) output = Json::Value("Filled");
            if (input == TradeStatusCancelled) output = Json::Value("Cancelled");
        }
        inline void FromJsonEnum(const Json::Value& input, TradeStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Invalid") output = TradeStatusInvalid;
            if (inputStr == "Opening") output = TradeStatusOpening;
            if (inputStr == "Open") output = TradeStatusOpen;
            if (inputStr == "Accepting") output = TradeStatusAccepting;
            if (inputStr == "Accepted") output = TradeStatusAccepted;
            if (inputStr == "Filled") output = TradeStatusFilled;
            if (inputStr == "Cancelled") output = TradeStatusCancelled;
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

        inline void ToJsonEnum(const TransactionStatus input, Json::Value& output)
        {
            if (input == TransactionStatusCreateCart) output = Json::Value("CreateCart");
            if (input == TransactionStatusInit) output = Json::Value("Init");
            if (input == TransactionStatusApproved) output = Json::Value("Approved");
            if (input == TransactionStatusSucceeded) output = Json::Value("Succeeded");
            if (input == TransactionStatusFailedByProvider) output = Json::Value("FailedByProvider");
            if (input == TransactionStatusDisputePending) output = Json::Value("DisputePending");
            if (input == TransactionStatusRefundPending) output = Json::Value("RefundPending");
            if (input == TransactionStatusRefunded) output = Json::Value("Refunded");
            if (input == TransactionStatusRefundFailed) output = Json::Value("RefundFailed");
            if (input == TransactionStatusChargedBack) output = Json::Value("ChargedBack");
            if (input == TransactionStatusFailedByUber) output = Json::Value("FailedByUber");
            if (input == TransactionStatusFailedByPlayFab) output = Json::Value("FailedByPlayFab");
            if (input == TransactionStatusRevoked) output = Json::Value("Revoked");
            if (input == TransactionStatusTradePending) output = Json::Value("TradePending");
            if (input == TransactionStatusTraded) output = Json::Value("Traded");
            if (input == TransactionStatusUpgraded) output = Json::Value("Upgraded");
            if (input == TransactionStatusStackPending) output = Json::Value("StackPending");
            if (input == TransactionStatusStacked) output = Json::Value("Stacked");
            if (input == TransactionStatusOther) output = Json::Value("Other");
            if (input == TransactionStatusFailed) output = Json::Value("Failed");
        }
        inline void FromJsonEnum(const Json::Value& input, TransactionStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "CreateCart") output = TransactionStatusCreateCart;
            if (inputStr == "Init") output = TransactionStatusInit;
            if (inputStr == "Approved") output = TransactionStatusApproved;
            if (inputStr == "Succeeded") output = TransactionStatusSucceeded;
            if (inputStr == "FailedByProvider") output = TransactionStatusFailedByProvider;
            if (inputStr == "DisputePending") output = TransactionStatusDisputePending;
            if (inputStr == "RefundPending") output = TransactionStatusRefundPending;
            if (inputStr == "Refunded") output = TransactionStatusRefunded;
            if (inputStr == "RefundFailed") output = TransactionStatusRefundFailed;
            if (inputStr == "ChargedBack") output = TransactionStatusChargedBack;
            if (inputStr == "FailedByUber") output = TransactionStatusFailedByUber;
            if (inputStr == "FailedByPlayFab") output = TransactionStatusFailedByPlayFab;
            if (inputStr == "Revoked") output = TransactionStatusRevoked;
            if (inputStr == "TradePending") output = TransactionStatusTradePending;
            if (inputStr == "Traded") output = TransactionStatusTraded;
            if (inputStr == "Upgraded") output = TransactionStatusUpgraded;
            if (inputStr == "StackPending") output = TransactionStatusStackPending;
            if (inputStr == "Stacked") output = TransactionStatusStacked;
            if (inputStr == "Other") output = TransactionStatusOther;
            if (inputStr == "Failed") output = TransactionStatusFailed;
        }

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        inline void ToJsonEnum(const UserDataPermission input, Json::Value& output)
        {
            if (input == UserDataPermissionPrivate) output = Json::Value("Private");
            if (input == UserDataPermissionPublic) output = Json::Value("Public");
        }
        inline void FromJsonEnum(const Json::Value& input, UserDataPermission& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Private") output = UserDataPermissionPrivate;
            if (inputStr == "Public") output = UserDataPermissionPublic;
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
            UserOriginationFacebookInstantGamesId,
            UserOriginationOpenIdConnect
        };

        inline void ToJsonEnum(const UserOrigination input, Json::Value& output)
        {
            if (input == UserOriginationOrganic) output = Json::Value("Organic");
            if (input == UserOriginationSteam) output = Json::Value("Steam");
            if (input == UserOriginationGoogle) output = Json::Value("Google");
            if (input == UserOriginationAmazon) output = Json::Value("Amazon");
            if (input == UserOriginationFacebook) output = Json::Value("Facebook");
            if (input == UserOriginationKongregate) output = Json::Value("Kongregate");
            if (input == UserOriginationGamersFirst) output = Json::Value("GamersFirst");
            if (input == UserOriginationUnknown) output = Json::Value("Unknown");
            if (input == UserOriginationIOS) output = Json::Value("IOS");
            if (input == UserOriginationLoadTest) output = Json::Value("LoadTest");
            if (input == UserOriginationAndroid) output = Json::Value("Android");
            if (input == UserOriginationPSN) output = Json::Value("PSN");
            if (input == UserOriginationGameCenter) output = Json::Value("GameCenter");
            if (input == UserOriginationCustomId) output = Json::Value("CustomId");
            if (input == UserOriginationXboxLive) output = Json::Value("XboxLive");
            if (input == UserOriginationParse) output = Json::Value("Parse");
            if (input == UserOriginationTwitch) output = Json::Value("Twitch");
            if (input == UserOriginationWindowsHello) output = Json::Value("WindowsHello");
            if (input == UserOriginationServerCustomId) output = Json::Value("ServerCustomId");
            if (input == UserOriginationNintendoSwitchDeviceId) output = Json::Value("NintendoSwitchDeviceId");
            if (input == UserOriginationFacebookInstantGamesId) output = Json::Value("FacebookInstantGamesId");
            if (input == UserOriginationOpenIdConnect) output = Json::Value("OpenIdConnect");
        }
        inline void FromJsonEnum(const Json::Value& input, UserOrigination& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Organic") output = UserOriginationOrganic;
            if (inputStr == "Steam") output = UserOriginationSteam;
            if (inputStr == "Google") output = UserOriginationGoogle;
            if (inputStr == "Amazon") output = UserOriginationAmazon;
            if (inputStr == "Facebook") output = UserOriginationFacebook;
            if (inputStr == "Kongregate") output = UserOriginationKongregate;
            if (inputStr == "GamersFirst") output = UserOriginationGamersFirst;
            if (inputStr == "Unknown") output = UserOriginationUnknown;
            if (inputStr == "IOS") output = UserOriginationIOS;
            if (inputStr == "LoadTest") output = UserOriginationLoadTest;
            if (inputStr == "Android") output = UserOriginationAndroid;
            if (inputStr == "PSN") output = UserOriginationPSN;
            if (inputStr == "GameCenter") output = UserOriginationGameCenter;
            if (inputStr == "CustomId") output = UserOriginationCustomId;
            if (inputStr == "XboxLive") output = UserOriginationXboxLive;
            if (inputStr == "Parse") output = UserOriginationParse;
            if (inputStr == "Twitch") output = UserOriginationTwitch;
            if (inputStr == "WindowsHello") output = UserOriginationWindowsHello;
            if (inputStr == "ServerCustomId") output = UserOriginationServerCustomId;
            if (inputStr == "NintendoSwitchDeviceId") output = UserOriginationNintendoSwitchDeviceId;
            if (inputStr == "FacebookInstantGamesId") output = UserOriginationFacebookInstantGamesId;
            if (inputStr == "OpenIdConnect") output = UserOriginationOpenIdConnect;
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

            ~AcceptTradeRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AcceptedInventoryInstanceIds"], AcceptedInventoryInstanceIds);
                FromJsonUtilS(input["OfferingPlayerId"], OfferingPlayerId);
                FromJsonUtilS(input["TradeId"], TradeId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AcceptedInventoryInstanceIds; ToJsonUtilS(AcceptedInventoryInstanceIds, each_AcceptedInventoryInstanceIds); output["AcceptedInventoryInstanceIds"] = each_AcceptedInventoryInstanceIds;
                Json::Value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output["OfferingPlayerId"] = each_OfferingPlayerId;
                Json::Value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output["TradeId"] = each_TradeId;
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

            ~TradeInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AcceptedInventoryInstanceIds"], AcceptedInventoryInstanceIds);
                FromJsonUtilS(input["AcceptedPlayerId"], AcceptedPlayerId);
                FromJsonUtilS(input["AllowedPlayerIds"], AllowedPlayerIds);
                FromJsonUtilT(input["CancelledAt"], CancelledAt);
                FromJsonUtilT(input["FilledAt"], FilledAt);
                FromJsonUtilT(input["InvalidatedAt"], InvalidatedAt);
                FromJsonUtilS(input["OfferedCatalogItemIds"], OfferedCatalogItemIds);
                FromJsonUtilS(input["OfferedInventoryInstanceIds"], OfferedInventoryInstanceIds);
                FromJsonUtilS(input["OfferingPlayerId"], OfferingPlayerId);
                FromJsonUtilT(input["OpenedAt"], OpenedAt);
                FromJsonUtilS(input["RequestedCatalogItemIds"], RequestedCatalogItemIds);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilS(input["TradeId"], TradeId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AcceptedInventoryInstanceIds; ToJsonUtilS(AcceptedInventoryInstanceIds, each_AcceptedInventoryInstanceIds); output["AcceptedInventoryInstanceIds"] = each_AcceptedInventoryInstanceIds;
                Json::Value each_AcceptedPlayerId; ToJsonUtilS(AcceptedPlayerId, each_AcceptedPlayerId); output["AcceptedPlayerId"] = each_AcceptedPlayerId;
                Json::Value each_AllowedPlayerIds; ToJsonUtilS(AllowedPlayerIds, each_AllowedPlayerIds); output["AllowedPlayerIds"] = each_AllowedPlayerIds;
                Json::Value each_CancelledAt; ToJsonUtilT(CancelledAt, each_CancelledAt); output["CancelledAt"] = each_CancelledAt;
                Json::Value each_FilledAt; ToJsonUtilT(FilledAt, each_FilledAt); output["FilledAt"] = each_FilledAt;
                Json::Value each_InvalidatedAt; ToJsonUtilT(InvalidatedAt, each_InvalidatedAt); output["InvalidatedAt"] = each_InvalidatedAt;
                Json::Value each_OfferedCatalogItemIds; ToJsonUtilS(OfferedCatalogItemIds, each_OfferedCatalogItemIds); output["OfferedCatalogItemIds"] = each_OfferedCatalogItemIds;
                Json::Value each_OfferedInventoryInstanceIds; ToJsonUtilS(OfferedInventoryInstanceIds, each_OfferedInventoryInstanceIds); output["OfferedInventoryInstanceIds"] = each_OfferedInventoryInstanceIds;
                Json::Value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output["OfferingPlayerId"] = each_OfferingPlayerId;
                Json::Value each_OpenedAt; ToJsonUtilT(OpenedAt, each_OpenedAt); output["OpenedAt"] = each_OpenedAt;
                Json::Value each_RequestedCatalogItemIds; ToJsonUtilS(RequestedCatalogItemIds, each_RequestedCatalogItemIds); output["RequestedCatalogItemIds"] = each_RequestedCatalogItemIds;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output["TradeId"] = each_TradeId;
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

            ~AcceptTradeResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Trade"], Trade);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Trade; ToJsonUtilO(Trade, each_Trade); output["Trade"] = each_Trade;
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

            ~AdCampaignAttributionModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["AttributedAt"], AttributedAt);
                FromJsonUtilS(input["CampaignId"], CampaignId);
                FromJsonUtilS(input["Platform"], Platform);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AttributedAt; ToJsonUtilT(AttributedAt, each_AttributedAt); output["AttributedAt"] = each_AttributedAt;
                Json::Value each_CampaignId; ToJsonUtilS(CampaignId, each_CampaignId); output["CampaignId"] = each_CampaignId;
                Json::Value each_Platform; ToJsonUtilS(Platform, each_Platform); output["Platform"] = each_Platform;
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

            ~AddFriendRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FriendEmail"], FriendEmail);
                FromJsonUtilS(input["FriendPlayFabId"], FriendPlayFabId);
                FromJsonUtilS(input["FriendTitleDisplayName"], FriendTitleDisplayName);
                FromJsonUtilS(input["FriendUsername"], FriendUsername);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FriendEmail; ToJsonUtilS(FriendEmail, each_FriendEmail); output["FriendEmail"] = each_FriendEmail;
                Json::Value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output["FriendPlayFabId"] = each_FriendPlayFabId;
                Json::Value each_FriendTitleDisplayName; ToJsonUtilS(FriendTitleDisplayName, each_FriendTitleDisplayName); output["FriendTitleDisplayName"] = each_FriendTitleDisplayName;
                Json::Value each_FriendUsername; ToJsonUtilS(FriendUsername, each_FriendUsername); output["FriendUsername"] = each_FriendUsername;
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

            ~AddFriendResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Created"], Created);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
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

            ~GenericServiceId() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ServiceName"], ServiceName);
                FromJsonUtilS(input["UserId"], UserId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ServiceName; ToJsonUtilS(ServiceName, each_ServiceName); output["ServiceName"] = each_ServiceName;
                Json::Value each_UserId; ToJsonUtilS(UserId, each_UserId); output["UserId"] = each_UserId;
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

            ~AddGenericIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["GenericId"], GenericId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output["GenericId"] = each_GenericId;
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

            ~AddGenericIDResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~AddOrUpdateContactEmailRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["EmailAddress"], EmailAddress);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EmailAddress; ToJsonUtilS(EmailAddress, each_EmailAddress); output["EmailAddress"] = each_EmailAddress;
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

            ~AddOrUpdateContactEmailResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~AddSharedGroupMembersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabIds"], PlayFabIds);
                FromJsonUtilS(input["SharedGroupId"], SharedGroupId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabIds; ToJsonUtilS(PlayFabIds, each_PlayFabIds); output["PlayFabIds"] = each_PlayFabIds;
                Json::Value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output["SharedGroupId"] = each_SharedGroupId;
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

            ~AddSharedGroupMembersResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~AddUsernamePasswordRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Email"], Email);
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Email; ToJsonUtilS(Email, each_Email); output["Email"] = each_Email;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
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

            ~AddUsernamePasswordResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
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

            ~AddUserVirtualCurrencyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["VirtualCurrency"], VirtualCurrency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
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

            ~AndroidDevicePushNotificationRegistrationRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ConfirmationMessage"], ConfirmationMessage);
                FromJsonUtilS(input["DeviceToken"], DeviceToken);
                FromJsonUtilP(input["SendPushNotificationConfirmation"], SendPushNotificationConfirmation);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConfirmationMessage; ToJsonUtilS(ConfirmationMessage, each_ConfirmationMessage); output["ConfirmationMessage"] = each_ConfirmationMessage;
                Json::Value each_DeviceToken; ToJsonUtilS(DeviceToken, each_DeviceToken); output["DeviceToken"] = each_DeviceToken;
                Json::Value each_SendPushNotificationConfirmation; ToJsonUtilP(SendPushNotificationConfirmation, each_SendPushNotificationConfirmation); output["SendPushNotificationConfirmation"] = each_SendPushNotificationConfirmation;
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

            ~AndroidDevicePushNotificationRegistrationResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~AttributeInstallRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Adid"], Adid);
                FromJsonUtilS(input["Idfa"], Idfa);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Adid; ToJsonUtilS(Adid, each_Adid); output["Adid"] = each_Adid;
                Json::Value each_Idfa; ToJsonUtilS(Idfa, each_Idfa); output["Idfa"] = each_Idfa;
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

            ~AttributeInstallResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~CancelTradeRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TradeId"], TradeId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output["TradeId"] = each_TradeId;
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

            ~CancelTradeResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Trade"], Trade);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Trade; ToJsonUtilO(Trade, each_Trade); output["Trade"] = each_Trade;
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

            ~CartItem() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilS(input["ItemClass"], ItemClass);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ItemInstanceId"], ItemInstanceId);
                FromJsonUtilP(input["RealCurrencyPrices"], RealCurrencyPrices);
                FromJsonUtilP(input["VCAmount"], VCAmount);
                FromJsonUtilP(input["VirtualCurrencyPrices"], VirtualCurrencyPrices);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output["ItemClass"] = each_ItemClass;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output["ItemInstanceId"] = each_ItemInstanceId;
                Json::Value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output["RealCurrencyPrices"] = each_RealCurrencyPrices;
                Json::Value each_VCAmount; ToJsonUtilP(VCAmount, each_VCAmount); output["VCAmount"] = each_VCAmount;
                Json::Value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output["VirtualCurrencyPrices"] = each_VirtualCurrencyPrices;
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

            ~CatalogItemBundleInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BundledItems"], BundledItems);
                FromJsonUtilS(input["BundledResultTables"], BundledResultTables);
                FromJsonUtilP(input["BundledVirtualCurrencies"], BundledVirtualCurrencies);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BundledItems; ToJsonUtilS(BundledItems, each_BundledItems); output["BundledItems"] = each_BundledItems;
                Json::Value each_BundledResultTables; ToJsonUtilS(BundledResultTables, each_BundledResultTables); output["BundledResultTables"] = each_BundledResultTables;
                Json::Value each_BundledVirtualCurrencies; ToJsonUtilP(BundledVirtualCurrencies, each_BundledVirtualCurrencies); output["BundledVirtualCurrencies"] = each_BundledVirtualCurrencies;
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

            ~CatalogItemConsumableInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["UsageCount"], UsageCount);
                FromJsonUtilP(input["UsagePeriod"], UsagePeriod);
                FromJsonUtilS(input["UsagePeriodGroup"], UsagePeriodGroup);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_UsageCount; ToJsonUtilP(UsageCount, each_UsageCount); output["UsageCount"] = each_UsageCount;
                Json::Value each_UsagePeriod; ToJsonUtilP(UsagePeriod, each_UsagePeriod); output["UsagePeriod"] = each_UsagePeriod;
                Json::Value each_UsagePeriodGroup; ToJsonUtilS(UsagePeriodGroup, each_UsagePeriodGroup); output["UsagePeriodGroup"] = each_UsagePeriodGroup;
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

            ~CatalogItemContainerInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ItemContents"], ItemContents);
                FromJsonUtilS(input["KeyItemId"], KeyItemId);
                FromJsonUtilS(input["ResultTableContents"], ResultTableContents);
                FromJsonUtilP(input["VirtualCurrencyContents"], VirtualCurrencyContents);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ItemContents; ToJsonUtilS(ItemContents, each_ItemContents); output["ItemContents"] = each_ItemContents;
                Json::Value each_KeyItemId; ToJsonUtilS(KeyItemId, each_KeyItemId); output["KeyItemId"] = each_KeyItemId;
                Json::Value each_ResultTableContents; ToJsonUtilS(ResultTableContents, each_ResultTableContents); output["ResultTableContents"] = each_ResultTableContents;
                Json::Value each_VirtualCurrencyContents; ToJsonUtilP(VirtualCurrencyContents, each_VirtualCurrencyContents); output["VirtualCurrencyContents"] = each_VirtualCurrencyContents;
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

            ~CatalogItem() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bundle"], Bundle);
                FromJsonUtilP(input["CanBecomeCharacter"], CanBecomeCharacter);
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input["Consumable"], Consumable);
                FromJsonUtilO(input["Container"], Container);
                FromJsonUtilS(input["CustomData"], CustomData);
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilP(input["InitialLimitedEditionCount"], InitialLimitedEditionCount);
                FromJsonUtilP(input["IsLimitedEdition"], IsLimitedEdition);
                FromJsonUtilP(input["IsStackable"], IsStackable);
                FromJsonUtilP(input["IsTradable"], IsTradable);
                FromJsonUtilS(input["ItemClass"], ItemClass);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ItemImageUrl"], ItemImageUrl);
                FromJsonUtilP(input["RealCurrencyPrices"], RealCurrencyPrices);
                FromJsonUtilS(input["Tags"], Tags);
                FromJsonUtilP(input["VirtualCurrencyPrices"], VirtualCurrencyPrices);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bundle; ToJsonUtilO(Bundle, each_Bundle); output["Bundle"] = each_Bundle;
                Json::Value each_CanBecomeCharacter; ToJsonUtilP(CanBecomeCharacter, each_CanBecomeCharacter); output["CanBecomeCharacter"] = each_CanBecomeCharacter;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_Consumable; ToJsonUtilO(Consumable, each_Consumable); output["Consumable"] = each_Consumable;
                Json::Value each_Container; ToJsonUtilO(Container, each_Container); output["Container"] = each_Container;
                Json::Value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output["CustomData"] = each_CustomData;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_InitialLimitedEditionCount; ToJsonUtilP(InitialLimitedEditionCount, each_InitialLimitedEditionCount); output["InitialLimitedEditionCount"] = each_InitialLimitedEditionCount;
                Json::Value each_IsLimitedEdition; ToJsonUtilP(IsLimitedEdition, each_IsLimitedEdition); output["IsLimitedEdition"] = each_IsLimitedEdition;
                Json::Value each_IsStackable; ToJsonUtilP(IsStackable, each_IsStackable); output["IsStackable"] = each_IsStackable;
                Json::Value each_IsTradable; ToJsonUtilP(IsTradable, each_IsTradable); output["IsTradable"] = each_IsTradable;
                Json::Value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output["ItemClass"] = each_ItemClass;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ItemImageUrl; ToJsonUtilS(ItemImageUrl, each_ItemImageUrl); output["ItemImageUrl"] = each_ItemImageUrl;
                Json::Value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output["RealCurrencyPrices"] = each_RealCurrencyPrices;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output["VirtualCurrencyPrices"] = each_VirtualCurrencyPrices;
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

            ~ItemInstance() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Annotation"], Annotation);
                FromJsonUtilS(input["BundleContents"], BundleContents);
                FromJsonUtilS(input["BundleParent"], BundleParent);
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CustomData"], CustomData);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilT(input["Expiration"], Expiration);
                FromJsonUtilS(input["ItemClass"], ItemClass);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ItemInstanceId"], ItemInstanceId);
                FromJsonUtilT(input["PurchaseDate"], PurchaseDate);
                FromJsonUtilP(input["RemainingUses"], RemainingUses);
                FromJsonUtilS(input["UnitCurrency"], UnitCurrency);
                FromJsonUtilP(input["UnitPrice"], UnitPrice);
                FromJsonUtilP(input["UsesIncrementedBy"], UsesIncrementedBy);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output["Annotation"] = each_Annotation;
                Json::Value each_BundleContents; ToJsonUtilS(BundleContents, each_BundleContents); output["BundleContents"] = each_BundleContents;
                Json::Value each_BundleParent; ToJsonUtilS(BundleParent, each_BundleParent); output["BundleParent"] = each_BundleParent;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output["CustomData"] = each_CustomData;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output["Expiration"] = each_Expiration;
                Json::Value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output["ItemClass"] = each_ItemClass;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output["ItemInstanceId"] = each_ItemInstanceId;
                Json::Value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output["PurchaseDate"] = each_PurchaseDate;
                Json::Value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output["RemainingUses"] = each_RemainingUses;
                Json::Value each_UnitCurrency; ToJsonUtilS(UnitCurrency, each_UnitCurrency); output["UnitCurrency"] = each_UnitCurrency;
                Json::Value each_UnitPrice; ToJsonUtilP(UnitPrice, each_UnitPrice); output["UnitPrice"] = each_UnitPrice;
                Json::Value each_UsesIncrementedBy; ToJsonUtilP(UsesIncrementedBy, each_UsesIncrementedBy); output["UsesIncrementedBy"] = each_UsesIncrementedBy;
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

            ~CharacterInventory() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilO(input["Inventory"], Inventory);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output["Inventory"] = each_Inventory;
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

            ~CharacterLeaderboardEntry() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["CharacterName"], CharacterName);
                FromJsonUtilS(input["CharacterType"], CharacterType);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilP(input["Position"], Position);
                FromJsonUtilP(input["StatValue"], StatValue);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output["CharacterName"] = each_CharacterName;
                Json::Value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output["CharacterType"] = each_CharacterType;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_Position; ToJsonUtilP(Position, each_Position); output["Position"] = each_Position;
                Json::Value each_StatValue; ToJsonUtilP(StatValue, each_StatValue); output["StatValue"] = each_StatValue;
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

            ~CharacterResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["CharacterName"], CharacterName);
                FromJsonUtilS(input["CharacterType"], CharacterType);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output["CharacterName"] = each_CharacterName;
                Json::Value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output["CharacterType"] = each_CharacterType;
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

            ~Container_Dictionary_String_String() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
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

            ~CollectionFilter() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Excludes"], Excludes);
                FromJsonUtilO(input["Includes"], Includes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Excludes; ToJsonUtilO(Excludes, each_Excludes); output["Excludes"] = each_Excludes;
                Json::Value each_Includes; ToJsonUtilO(Includes, each_Includes); output["Includes"] = each_Includes;
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

            ~ConfirmPurchaseRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OrderId"], OrderId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
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

            ~ConfirmPurchaseResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Items"], Items);
                FromJsonUtilS(input["OrderId"], OrderId);
                FromJsonUtilT(input["PurchaseDate"], PurchaseDate);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
                Json::Value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output["PurchaseDate"] = each_PurchaseDate;
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

            ~ConsumeItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilP(input["ConsumeCount"], ConsumeCount);
                FromJsonUtilS(input["ItemInstanceId"], ItemInstanceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_ConsumeCount; ToJsonUtilP(ConsumeCount, each_ConsumeCount); output["ConsumeCount"] = each_ConsumeCount;
                Json::Value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output["ItemInstanceId"] = each_ItemInstanceId;
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

            ~ConsumeItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ItemInstanceId"], ItemInstanceId);
                FromJsonUtilP(input["RemainingUses"], RemainingUses);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output["ItemInstanceId"] = each_ItemInstanceId;
                Json::Value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output["RemainingUses"] = each_RemainingUses;
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

            ~ConsumeXboxEntitlementsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
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

            ~ConsumeXboxEntitlementsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
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

            ~ContactEmailInfoModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["EmailAddress"], EmailAddress);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilE(input["VerificationStatus"], VerificationStatus);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EmailAddress; ToJsonUtilS(EmailAddress, each_EmailAddress); output["EmailAddress"] = each_EmailAddress;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_VerificationStatus; ToJsonUtilE(VerificationStatus, each_VerificationStatus); output["VerificationStatus"] = each_VerificationStatus;
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

            ~CreateSharedGroupRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["SharedGroupId"], SharedGroupId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output["SharedGroupId"] = each_SharedGroupId;
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

            ~CreateSharedGroupResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["SharedGroupId"], SharedGroupId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output["SharedGroupId"] = each_SharedGroupId;
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

            ~CurrentGamesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildVersion"], BuildVersion);
                FromJsonUtilS(input["GameMode"], GameMode);
                FromJsonUtilE(input["pfRegion"], pfRegion);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilO(input["TagFilter"], TagFilter);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output["BuildVersion"] = each_BuildVersion;
                Json::Value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output["GameMode"] = each_GameMode;
                Json::Value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output["Region"] = each_pfRegion;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_TagFilter; ToJsonUtilO(TagFilter, each_TagFilter); output["TagFilter"] = each_TagFilter;
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
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                StatisticName(src.StatisticName),
                Tags(src.Tags)
            {}

            ~GameInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildVersion"], BuildVersion);
                FromJsonUtilS(input["GameMode"], GameMode);
                FromJsonUtilS(input["GameServerData"], GameServerData);
                FromJsonUtilE(input["GameServerStateEnum"], GameServerStateEnum);
                FromJsonUtilT(input["LastHeartbeat"], LastHeartbeat);
                FromJsonUtilS(input["LobbyID"], LobbyID);
                FromJsonUtilP(input["MaxPlayers"], MaxPlayers);
                FromJsonUtilS(input["PlayerUserIds"], PlayerUserIds);
                FromJsonUtilE(input["pfRegion"], pfRegion);
                FromJsonUtilP(input["RunTime"], RunTime);
                FromJsonUtilS(input["ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input["ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input["ServerPort"], ServerPort);
                FromJsonUtilS(input["ServerPublicDNSName"], ServerPublicDNSName);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output["BuildVersion"] = each_BuildVersion;
                Json::Value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output["GameMode"] = each_GameMode;
                Json::Value each_GameServerData; ToJsonUtilS(GameServerData, each_GameServerData); output["GameServerData"] = each_GameServerData;
                Json::Value each_GameServerStateEnum; ToJsonUtilE(GameServerStateEnum, each_GameServerStateEnum); output["GameServerStateEnum"] = each_GameServerStateEnum;
                Json::Value each_LastHeartbeat; ToJsonUtilT(LastHeartbeat, each_LastHeartbeat); output["LastHeartbeat"] = each_LastHeartbeat;
                Json::Value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output["LobbyID"] = each_LobbyID;
                Json::Value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output["MaxPlayers"] = each_MaxPlayers;
                Json::Value each_PlayerUserIds; ToJsonUtilS(PlayerUserIds, each_PlayerUserIds); output["PlayerUserIds"] = each_PlayerUserIds;
                Json::Value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output["Region"] = each_pfRegion;
                Json::Value each_RunTime; ToJsonUtilP(RunTime, each_RunTime); output["RunTime"] = each_RunTime;
                Json::Value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output["ServerIPV4Address"] = each_ServerIPV4Address;
                Json::Value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output["ServerIPV6Address"] = each_ServerIPV6Address;
                Json::Value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output["ServerPort"] = each_ServerPort;
                Json::Value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output["ServerPublicDNSName"] = each_ServerPublicDNSName;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
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

            ~CurrentGamesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["GameCount"], GameCount);
                FromJsonUtilO(input["Games"], Games);
                FromJsonUtilP(input["PlayerCount"], PlayerCount);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GameCount; ToJsonUtilP(GameCount, each_GameCount); output["GameCount"] = each_GameCount;
                Json::Value each_Games; ToJsonUtilO(Games, each_Games); output["Games"] = each_Games;
                Json::Value each_PlayerCount; ToJsonUtilP(PlayerCount, each_PlayerCount); output["PlayerCount"] = each_PlayerCount;
                return output;
            }
        };

        struct DeviceInfoRequest : public PlayFabRequestCommon
        {
            Json::Value Info; // Not truly arbitrary. See documentation for restrictions on format

            DeviceInfoRequest() :
                PlayFabRequestCommon(),
                Info()
            {}

            DeviceInfoRequest(const DeviceInfoRequest& src) :
                PlayFabRequestCommon(),
                Info(src.Info)
            {}

            ~DeviceInfoRequest() = default;

            void FromJson(Json::Value& input) override
            {
                Info = input["Info"];
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["Info"] = Info;
                return output;
            }
        };

        struct EmptyResponse : public PlayFabResultCommon
        {

            EmptyResponse() :
                PlayFabResultCommon()
            {}

            EmptyResponse(const EmptyResponse&) :
                PlayFabResultCommon()
            {}

            ~EmptyResponse() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~EmptyResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

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

            ~EntityTokenResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["EntityToken"], EntityToken);
                FromJsonUtilT(input["TokenExpiration"], TokenExpiration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                Json::Value each_TokenExpiration; ToJsonUtilT(TokenExpiration, each_TokenExpiration); output["TokenExpiration"] = each_TokenExpiration;
                return output;
            }
        };

        struct ExecuteCloudScriptRequest : public PlayFabRequestCommon
        {
            std::string FunctionName;
            Json::Value FunctionParameter;
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

            ~ExecuteCloudScriptRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FunctionName"], FunctionName);
                FunctionParameter = input["FunctionParameter"];
                FromJsonUtilP(input["GeneratePlayStreamEvent"], GeneratePlayStreamEvent);
                FromJsonUtilE(input["RevisionSelection"], RevisionSelection);
                FromJsonUtilP(input["SpecificRevision"], SpecificRevision);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                output["FunctionParameter"] = FunctionParameter;
                Json::Value each_GeneratePlayStreamEvent; ToJsonUtilP(GeneratePlayStreamEvent, each_GeneratePlayStreamEvent); output["GeneratePlayStreamEvent"] = each_GeneratePlayStreamEvent;
                Json::Value each_RevisionSelection; ToJsonUtilE(RevisionSelection, each_RevisionSelection); output["RevisionSelection"] = each_RevisionSelection;
                Json::Value each_SpecificRevision; ToJsonUtilP(SpecificRevision, each_SpecificRevision); output["SpecificRevision"] = each_SpecificRevision;
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

            ~ScriptExecutionError() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Error"], Error);
                FromJsonUtilS(input["Message"], Message);
                FromJsonUtilS(input["StackTrace"], StackTrace);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Error; ToJsonUtilS(Error, each_Error); output["Error"] = each_Error;
                Json::Value each_Message; ToJsonUtilS(Message, each_Message); output["Message"] = each_Message;
                Json::Value each_StackTrace; ToJsonUtilS(StackTrace, each_StackTrace); output["StackTrace"] = each_StackTrace;
                return output;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
            Json::Value Data;
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

            ~LogStatement() = default;

            void FromJson(Json::Value& input) override
            {
                Data = input["Data"];
                FromJsonUtilS(input["Level"], Level);
                FromJsonUtilS(input["Message"], Message);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["Data"] = Data;
                Json::Value each_Level; ToJsonUtilS(Level, each_Level); output["Level"] = each_Level;
                Json::Value each_Message; ToJsonUtilS(Message, each_Message); output["Message"] = each_Message;
                return output;
            }
        };

        struct ExecuteCloudScriptResult : public PlayFabResultCommon
        {
            Int32 APIRequestsIssued;
            Boxed<ScriptExecutionError> Error;
            double ExecutionTimeSeconds;
            std::string FunctionName;
            Json::Value FunctionResult;
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

            ~ExecuteCloudScriptResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["APIRequestsIssued"], APIRequestsIssued);
                FromJsonUtilO(input["Error"], Error);
                FromJsonUtilP(input["ExecutionTimeSeconds"], ExecutionTimeSeconds);
                FromJsonUtilS(input["FunctionName"], FunctionName);
                FunctionResult = input["FunctionResult"];
                FromJsonUtilP(input["FunctionResultTooLarge"], FunctionResultTooLarge);
                FromJsonUtilP(input["HttpRequestsIssued"], HttpRequestsIssued);
                FromJsonUtilO(input["Logs"], Logs);
                FromJsonUtilP(input["LogsTooLarge"], LogsTooLarge);
                FromJsonUtilP(input["MemoryConsumedBytes"], MemoryConsumedBytes);
                FromJsonUtilP(input["ProcessorTimeSeconds"], ProcessorTimeSeconds);
                FromJsonUtilP(input["Revision"], Revision);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_APIRequestsIssued; ToJsonUtilP(APIRequestsIssued, each_APIRequestsIssued); output["APIRequestsIssued"] = each_APIRequestsIssued;
                Json::Value each_Error; ToJsonUtilO(Error, each_Error); output["Error"] = each_Error;
                Json::Value each_ExecutionTimeSeconds; ToJsonUtilP(ExecutionTimeSeconds, each_ExecutionTimeSeconds); output["ExecutionTimeSeconds"] = each_ExecutionTimeSeconds;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                output["FunctionResult"] = FunctionResult;
                Json::Value each_FunctionResultTooLarge; ToJsonUtilP(FunctionResultTooLarge, each_FunctionResultTooLarge); output["FunctionResultTooLarge"] = each_FunctionResultTooLarge;
                Json::Value each_HttpRequestsIssued; ToJsonUtilP(HttpRequestsIssued, each_HttpRequestsIssued); output["HttpRequestsIssued"] = each_HttpRequestsIssued;
                Json::Value each_Logs; ToJsonUtilO(Logs, each_Logs); output["Logs"] = each_Logs;
                Json::Value each_LogsTooLarge; ToJsonUtilP(LogsTooLarge, each_LogsTooLarge); output["LogsTooLarge"] = each_LogsTooLarge;
                Json::Value each_MemoryConsumedBytes; ToJsonUtilP(MemoryConsumedBytes, each_MemoryConsumedBytes); output["MemoryConsumedBytes"] = each_MemoryConsumedBytes;
                Json::Value each_ProcessorTimeSeconds; ToJsonUtilP(ProcessorTimeSeconds, each_ProcessorTimeSeconds); output["ProcessorTimeSeconds"] = each_ProcessorTimeSeconds;
                Json::Value each_Revision; ToJsonUtilP(Revision, each_Revision); output["Revision"] = each_Revision;
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

            ~FacebookInstantGamesPlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FacebookInstantGamesId"], FacebookInstantGamesId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FacebookInstantGamesId; ToJsonUtilS(FacebookInstantGamesId, each_FacebookInstantGamesId); output["FacebookInstantGamesId"] = each_FacebookInstantGamesId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~FacebookPlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FacebookId"], FacebookId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FacebookId; ToJsonUtilS(FacebookId, each_FacebookId); output["FacebookId"] = each_FacebookId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~UserFacebookInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FacebookId"], FacebookId);
                FromJsonUtilS(input["FullName"], FullName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FacebookId; ToJsonUtilS(FacebookId, each_FacebookId); output["FacebookId"] = each_FacebookId;
                Json::Value each_FullName; ToJsonUtilS(FullName, each_FullName); output["FullName"] = each_FullName;
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

            ~UserGameCenterInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["GameCenterId"], GameCenterId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output["GameCenterId"] = each_GameCenterId;
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

            ~LinkedPlatformAccountModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Email"], Email);
                FromJsonUtilE(input["Platform"], Platform);
                FromJsonUtilS(input["PlatformUserId"], PlatformUserId);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Email; ToJsonUtilS(Email, each_Email); output["Email"] = each_Email;
                Json::Value each_Platform; ToJsonUtilE(Platform, each_Platform); output["Platform"] = each_Platform;
                Json::Value each_PlatformUserId; ToJsonUtilS(PlatformUserId, each_PlatformUserId); output["PlatformUserId"] = each_PlatformUserId;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
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

            ~LocationModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["City"], City);
                FromJsonUtilE(input["pfContinentCode"], pfContinentCode);
                FromJsonUtilE(input["pfCountryCode"], pfCountryCode);
                FromJsonUtilP(input["Latitude"], Latitude);
                FromJsonUtilP(input["Longitude"], Longitude);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_City; ToJsonUtilS(City, each_City); output["City"] = each_City;
                Json::Value each_pfContinentCode; ToJsonUtilE(pfContinentCode, each_pfContinentCode); output["ContinentCode"] = each_pfContinentCode;
                Json::Value each_pfCountryCode; ToJsonUtilE(pfCountryCode, each_pfCountryCode); output["CountryCode"] = each_pfCountryCode;
                Json::Value each_Latitude; ToJsonUtilP(Latitude, each_Latitude); output["Latitude"] = each_Latitude;
                Json::Value each_Longitude; ToJsonUtilP(Longitude, each_Longitude); output["Longitude"] = each_Longitude;
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

            ~SubscriptionModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["Expiration"], Expiration);
                FromJsonUtilT(input["InitialSubscriptionTime"], InitialSubscriptionTime);
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilS(input["SubscriptionId"], SubscriptionId);
                FromJsonUtilS(input["SubscriptionItemId"], SubscriptionItemId);
                FromJsonUtilS(input["SubscriptionProvider"], SubscriptionProvider);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output["Expiration"] = each_Expiration;
                Json::Value each_InitialSubscriptionTime; ToJsonUtilT(InitialSubscriptionTime, each_InitialSubscriptionTime); output["InitialSubscriptionTime"] = each_InitialSubscriptionTime;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_SubscriptionId; ToJsonUtilS(SubscriptionId, each_SubscriptionId); output["SubscriptionId"] = each_SubscriptionId;
                Json::Value each_SubscriptionItemId; ToJsonUtilS(SubscriptionItemId, each_SubscriptionItemId); output["SubscriptionItemId"] = each_SubscriptionItemId;
                Json::Value each_SubscriptionProvider; ToJsonUtilS(SubscriptionProvider, each_SubscriptionProvider); output["SubscriptionProvider"] = each_SubscriptionProvider;
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

            ~MembershipModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilT(input["MembershipExpiration"], MembershipExpiration);
                FromJsonUtilS(input["MembershipId"], MembershipId);
                FromJsonUtilT(input["OverrideExpiration"], OverrideExpiration);
                FromJsonUtilO(input["Subscriptions"], Subscriptions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_MembershipExpiration; ToJsonUtilT(MembershipExpiration, each_MembershipExpiration); output["MembershipExpiration"] = each_MembershipExpiration;
                Json::Value each_MembershipId; ToJsonUtilS(MembershipId, each_MembershipId); output["MembershipId"] = each_MembershipId;
                Json::Value each_OverrideExpiration; ToJsonUtilT(OverrideExpiration, each_OverrideExpiration); output["OverrideExpiration"] = each_OverrideExpiration;
                Json::Value each_Subscriptions; ToJsonUtilO(Subscriptions, each_Subscriptions); output["Subscriptions"] = each_Subscriptions;
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

            ~PushNotificationRegistrationModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["NotificationEndpointARN"], NotificationEndpointARN);
                FromJsonUtilE(input["Platform"], Platform);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NotificationEndpointARN; ToJsonUtilS(NotificationEndpointARN, each_NotificationEndpointARN); output["NotificationEndpointARN"] = each_NotificationEndpointARN;
                Json::Value each_Platform; ToJsonUtilE(Platform, each_Platform); output["Platform"] = each_Platform;
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

            ~StatisticModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Value"], Value);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Value; ToJsonUtilP(Value, each_Value); output["Value"] = each_Value;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~TagModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TagValue"], TagValue);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TagValue; ToJsonUtilS(TagValue, each_TagValue); output["TagValue"] = each_TagValue;
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

            ~ValueToDateModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Currency"], Currency);
                FromJsonUtilP(input["TotalValue"], TotalValue);
                FromJsonUtilS(input["TotalValueAsDecimal"], TotalValueAsDecimal);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currency; ToJsonUtilS(Currency, each_Currency); output["Currency"] = each_Currency;
                Json::Value each_TotalValue; ToJsonUtilP(TotalValue, each_TotalValue); output["TotalValue"] = each_TotalValue;
                Json::Value each_TotalValueAsDecimal; ToJsonUtilS(TotalValueAsDecimal, each_TotalValueAsDecimal); output["TotalValueAsDecimal"] = each_TotalValueAsDecimal;
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

            ~PlayerProfileModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["AdCampaignAttributions"], AdCampaignAttributions);
                FromJsonUtilS(input["AvatarUrl"], AvatarUrl);
                FromJsonUtilT(input["BannedUntil"], BannedUntil);
                FromJsonUtilO(input["ContactEmailAddresses"], ContactEmailAddresses);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilT(input["LastLogin"], LastLogin);
                FromJsonUtilO(input["LinkedAccounts"], LinkedAccounts);
                FromJsonUtilO(input["Locations"], Locations);
                FromJsonUtilO(input["Memberships"], Memberships);
                FromJsonUtilE(input["Origination"], Origination);
                FromJsonUtilS(input["PlayerId"], PlayerId);
                FromJsonUtilS(input["PublisherId"], PublisherId);
                FromJsonUtilO(input["PushNotificationRegistrations"], PushNotificationRegistrations);
                FromJsonUtilO(input["Statistics"], Statistics);
                FromJsonUtilO(input["Tags"], Tags);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilP(input["TotalValueToDateInUSD"], TotalValueToDateInUSD);
                FromJsonUtilO(input["ValuesToDate"], ValuesToDate);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AdCampaignAttributions; ToJsonUtilO(AdCampaignAttributions, each_AdCampaignAttributions); output["AdCampaignAttributions"] = each_AdCampaignAttributions;
                Json::Value each_AvatarUrl; ToJsonUtilS(AvatarUrl, each_AvatarUrl); output["AvatarUrl"] = each_AvatarUrl;
                Json::Value each_BannedUntil; ToJsonUtilT(BannedUntil, each_BannedUntil); output["BannedUntil"] = each_BannedUntil;
                Json::Value each_ContactEmailAddresses; ToJsonUtilO(ContactEmailAddresses, each_ContactEmailAddresses); output["ContactEmailAddresses"] = each_ContactEmailAddresses;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_LastLogin; ToJsonUtilT(LastLogin, each_LastLogin); output["LastLogin"] = each_LastLogin;
                Json::Value each_LinkedAccounts; ToJsonUtilO(LinkedAccounts, each_LinkedAccounts); output["LinkedAccounts"] = each_LinkedAccounts;
                Json::Value each_Locations; ToJsonUtilO(Locations, each_Locations); output["Locations"] = each_Locations;
                Json::Value each_Memberships; ToJsonUtilO(Memberships, each_Memberships); output["Memberships"] = each_Memberships;
                Json::Value each_Origination; ToJsonUtilE(Origination, each_Origination); output["Origination"] = each_Origination;
                Json::Value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output["PlayerId"] = each_PlayerId;
                Json::Value each_PublisherId; ToJsonUtilS(PublisherId, each_PublisherId); output["PublisherId"] = each_PublisherId;
                Json::Value each_PushNotificationRegistrations; ToJsonUtilO(PushNotificationRegistrations, each_PushNotificationRegistrations); output["PushNotificationRegistrations"] = each_PushNotificationRegistrations;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                Json::Value each_Tags; ToJsonUtilO(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_TotalValueToDateInUSD; ToJsonUtilP(TotalValueToDateInUSD, each_TotalValueToDateInUSD); output["TotalValueToDateInUSD"] = each_TotalValueToDateInUSD;
                Json::Value each_ValuesToDate; ToJsonUtilO(ValuesToDate, each_ValuesToDate); output["ValuesToDate"] = each_ValuesToDate;
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

            ~UserPsnInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PsnAccountId"], PsnAccountId);
                FromJsonUtilS(input["PsnOnlineId"], PsnOnlineId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PsnAccountId; ToJsonUtilS(PsnAccountId, each_PsnAccountId); output["PsnAccountId"] = each_PsnAccountId;
                Json::Value each_PsnOnlineId; ToJsonUtilS(PsnOnlineId, each_PsnOnlineId); output["PsnOnlineId"] = each_PsnOnlineId;
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

            ~UserSteamInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["SteamActivationStatus"], SteamActivationStatus);
                FromJsonUtilS(input["SteamCountry"], SteamCountry);
                FromJsonUtilE(input["SteamCurrency"], SteamCurrency);
                FromJsonUtilS(input["SteamId"], SteamId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_SteamActivationStatus; ToJsonUtilE(SteamActivationStatus, each_SteamActivationStatus); output["SteamActivationStatus"] = each_SteamActivationStatus;
                Json::Value each_SteamCountry; ToJsonUtilS(SteamCountry, each_SteamCountry); output["SteamCountry"] = each_SteamCountry;
                Json::Value each_SteamCurrency; ToJsonUtilE(SteamCurrency, each_SteamCurrency); output["SteamCurrency"] = each_SteamCurrency;
                Json::Value each_SteamId; ToJsonUtilS(SteamId, each_SteamId); output["SteamId"] = each_SteamId;
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

            ~UserXboxInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["XboxUserId"], XboxUserId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_XboxUserId; ToJsonUtilS(XboxUserId, each_XboxUserId); output["XboxUserId"] = each_XboxUserId;
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

            ~FriendInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CurrentMatchmakerLobbyId"], CurrentMatchmakerLobbyId);
                FromJsonUtilO(input["FacebookInfo"], FacebookInfo);
                FromJsonUtilS(input["FriendPlayFabId"], FriendPlayFabId);
                FromJsonUtilO(input["GameCenterInfo"], GameCenterInfo);
                FromJsonUtilO(input["Profile"], Profile);
                FromJsonUtilO(input["PSNInfo"], PSNInfo);
                FromJsonUtilO(input["SteamInfo"], SteamInfo);
                FromJsonUtilS(input["Tags"], Tags);
                FromJsonUtilS(input["TitleDisplayName"], TitleDisplayName);
                FromJsonUtilS(input["Username"], Username);
                FromJsonUtilO(input["XboxInfo"], XboxInfo);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CurrentMatchmakerLobbyId; ToJsonUtilS(CurrentMatchmakerLobbyId, each_CurrentMatchmakerLobbyId); output["CurrentMatchmakerLobbyId"] = each_CurrentMatchmakerLobbyId;
                Json::Value each_FacebookInfo; ToJsonUtilO(FacebookInfo, each_FacebookInfo); output["FacebookInfo"] = each_FacebookInfo;
                Json::Value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output["FriendPlayFabId"] = each_FriendPlayFabId;
                Json::Value each_GameCenterInfo; ToJsonUtilO(GameCenterInfo, each_GameCenterInfo); output["GameCenterInfo"] = each_GameCenterInfo;
                Json::Value each_Profile; ToJsonUtilO(Profile, each_Profile); output["Profile"] = each_Profile;
                Json::Value each_PSNInfo; ToJsonUtilO(PSNInfo, each_PSNInfo); output["PSNInfo"] = each_PSNInfo;
                Json::Value each_SteamInfo; ToJsonUtilO(SteamInfo, each_SteamInfo); output["SteamInfo"] = each_SteamInfo;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_TitleDisplayName; ToJsonUtilS(TitleDisplayName, each_TitleDisplayName); output["TitleDisplayName"] = each_TitleDisplayName;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
                Json::Value each_XboxInfo; ToJsonUtilO(XboxInfo, each_XboxInfo); output["XboxInfo"] = each_XboxInfo;
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

            ~GameCenterPlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["GameCenterId"], GameCenterId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output["GameCenterId"] = each_GameCenterId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GameServerRegionsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildVersion"], BuildVersion);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output["BuildVersion"] = each_BuildVersion;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~RegionInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Available"], Available);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["PingUrl"], PingUrl);
                FromJsonUtilE(input["pfRegion"], pfRegion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Available; ToJsonUtilP(Available, each_Available); output["Available"] = each_Available;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_PingUrl; ToJsonUtilS(PingUrl, each_PingUrl); output["PingUrl"] = each_PingUrl;
                Json::Value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output["Region"] = each_pfRegion;
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

            ~GameServerRegionsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Regions"], Regions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Regions; ToJsonUtilO(Regions, each_Regions); output["Regions"] = each_Regions;
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

            ~GenericPlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["GenericId"], GenericId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output["GenericId"] = each_GenericId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GetAccountInfoRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Email"], Email);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["TitleDisplayName"], TitleDisplayName);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Email; ToJsonUtilS(Email, each_Email); output["Email"] = each_Email;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_TitleDisplayName; ToJsonUtilS(TitleDisplayName, each_TitleDisplayName); output["TitleDisplayName"] = each_TitleDisplayName;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
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

            ~UserAndroidDeviceInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AndroidDeviceId"], AndroidDeviceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output["AndroidDeviceId"] = each_AndroidDeviceId;
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

            ~UserCustomIdInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CustomId"], CustomId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output["CustomId"] = each_CustomId;
                return output;
            }
        };

        struct UserFacebookInstantGamesIdInfo : public PlayFabBaseModel
        {
            std::string FacebookInstantGamesId;

            UserFacebookInstantGamesIdInfo() :
                PlayFabBaseModel(),
                FacebookInstantGamesId()
            {}

            UserFacebookInstantGamesIdInfo(const UserFacebookInstantGamesIdInfo& src) :
                PlayFabBaseModel(),
                FacebookInstantGamesId(src.FacebookInstantGamesId)
            {}

            ~UserFacebookInstantGamesIdInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FacebookInstantGamesId"], FacebookInstantGamesId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FacebookInstantGamesId; ToJsonUtilS(FacebookInstantGamesId, each_FacebookInstantGamesId); output["FacebookInstantGamesId"] = each_FacebookInstantGamesId;
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

            ~UserGoogleInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["GoogleEmail"], GoogleEmail);
                FromJsonUtilS(input["GoogleGender"], GoogleGender);
                FromJsonUtilS(input["GoogleId"], GoogleId);
                FromJsonUtilS(input["GoogleLocale"], GoogleLocale);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GoogleEmail; ToJsonUtilS(GoogleEmail, each_GoogleEmail); output["GoogleEmail"] = each_GoogleEmail;
                Json::Value each_GoogleGender; ToJsonUtilS(GoogleGender, each_GoogleGender); output["GoogleGender"] = each_GoogleGender;
                Json::Value each_GoogleId; ToJsonUtilS(GoogleId, each_GoogleId); output["GoogleId"] = each_GoogleId;
                Json::Value each_GoogleLocale; ToJsonUtilS(GoogleLocale, each_GoogleLocale); output["GoogleLocale"] = each_GoogleLocale;
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

            ~UserIosDeviceInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IosDeviceId"], IosDeviceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IosDeviceId; ToJsonUtilS(IosDeviceId, each_IosDeviceId); output["IosDeviceId"] = each_IosDeviceId;
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

            ~UserKongregateInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["KongregateId"], KongregateId);
                FromJsonUtilS(input["KongregateName"], KongregateName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output["KongregateId"] = each_KongregateId;
                Json::Value each_KongregateName; ToJsonUtilS(KongregateName, each_KongregateName); output["KongregateName"] = each_KongregateName;
                return output;
            }
        };

        struct UserNintendoSwitchDeviceIdInfo : public PlayFabBaseModel
        {
            std::string NintendoSwitchDeviceId;

            UserNintendoSwitchDeviceIdInfo() :
                PlayFabBaseModel(),
                NintendoSwitchDeviceId()
            {}

            UserNintendoSwitchDeviceIdInfo(const UserNintendoSwitchDeviceIdInfo& src) :
                PlayFabBaseModel(),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId)
            {}

            ~UserNintendoSwitchDeviceIdInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output["NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
                return output;
            }
        };

        struct UserOpenIdInfo : public PlayFabBaseModel
        {
            std::string ConnectionId;
            std::string Issuer;
            std::string Subject;

            UserOpenIdInfo() :
                PlayFabBaseModel(),
                ConnectionId(),
                Issuer(),
                Subject()
            {}

            UserOpenIdInfo(const UserOpenIdInfo& src) :
                PlayFabBaseModel(),
                ConnectionId(src.ConnectionId),
                Issuer(src.Issuer),
                Subject(src.Subject)
            {}

            ~UserOpenIdInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionId"], ConnectionId);
                FromJsonUtilS(input["Issuer"], Issuer);
                FromJsonUtilS(input["Subject"], Subject);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionId; ToJsonUtilS(ConnectionId, each_ConnectionId); output["ConnectionId"] = each_ConnectionId;
                Json::Value each_Issuer; ToJsonUtilS(Issuer, each_Issuer); output["Issuer"] = each_Issuer;
                Json::Value each_Subject; ToJsonUtilS(Subject, each_Subject); output["Subject"] = each_Subject;
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

            ~UserPrivateAccountInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Email"], Email);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Email; ToJsonUtilS(Email, each_Email); output["Email"] = each_Email;
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

            ~UserTitleInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AvatarUrl"], AvatarUrl);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilT(input["FirstLogin"], FirstLogin);
                FromJsonUtilP(input["isBanned"], isBanned);
                FromJsonUtilT(input["LastLogin"], LastLogin);
                FromJsonUtilE(input["Origination"], Origination);
                FromJsonUtilO(input["TitlePlayerAccount"], TitlePlayerAccount);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AvatarUrl; ToJsonUtilS(AvatarUrl, each_AvatarUrl); output["AvatarUrl"] = each_AvatarUrl;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_FirstLogin; ToJsonUtilT(FirstLogin, each_FirstLogin); output["FirstLogin"] = each_FirstLogin;
                Json::Value each_isBanned; ToJsonUtilP(isBanned, each_isBanned); output["isBanned"] = each_isBanned;
                Json::Value each_LastLogin; ToJsonUtilT(LastLogin, each_LastLogin); output["LastLogin"] = each_LastLogin;
                Json::Value each_Origination; ToJsonUtilE(Origination, each_Origination); output["Origination"] = each_Origination;
                Json::Value each_TitlePlayerAccount; ToJsonUtilO(TitlePlayerAccount, each_TitlePlayerAccount); output["TitlePlayerAccount"] = each_TitlePlayerAccount;
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

            ~UserTwitchInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TwitchId"], TwitchId);
                FromJsonUtilS(input["TwitchUserName"], TwitchUserName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TwitchId; ToJsonUtilS(TwitchId, each_TwitchId); output["TwitchId"] = each_TwitchId;
                Json::Value each_TwitchUserName; ToJsonUtilS(TwitchUserName, each_TwitchUserName); output["TwitchUserName"] = each_TwitchUserName;
                return output;
            }
        };

        struct UserWindowsHelloInfo : public PlayFabBaseModel
        {
            std::string WindowsHelloDeviceName;
            std::string WindowsHelloPublicKeyHash;

            UserWindowsHelloInfo() :
                PlayFabBaseModel(),
                WindowsHelloDeviceName(),
                WindowsHelloPublicKeyHash()
            {}

            UserWindowsHelloInfo(const UserWindowsHelloInfo& src) :
                PlayFabBaseModel(),
                WindowsHelloDeviceName(src.WindowsHelloDeviceName),
                WindowsHelloPublicKeyHash(src.WindowsHelloPublicKeyHash)
            {}

            ~UserWindowsHelloInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["WindowsHelloDeviceName"], WindowsHelloDeviceName);
                FromJsonUtilS(input["WindowsHelloPublicKeyHash"], WindowsHelloPublicKeyHash);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_WindowsHelloDeviceName; ToJsonUtilS(WindowsHelloDeviceName, each_WindowsHelloDeviceName); output["WindowsHelloDeviceName"] = each_WindowsHelloDeviceName;
                Json::Value each_WindowsHelloPublicKeyHash; ToJsonUtilS(WindowsHelloPublicKeyHash, each_WindowsHelloPublicKeyHash); output["WindowsHelloPublicKeyHash"] = each_WindowsHelloPublicKeyHash;
                return output;
            }
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            Boxed<UserAndroidDeviceInfo> AndroidDeviceInfo;
            time_t Created;
            Boxed<UserCustomIdInfo> CustomIdInfo;
            Boxed<UserFacebookInfo> FacebookInfo;
            Boxed<UserFacebookInstantGamesIdInfo> FacebookInstantGamesIdInfo;
            Boxed<UserGameCenterInfo> GameCenterInfo;
            Boxed<UserGoogleInfo> GoogleInfo;
            Boxed<UserIosDeviceInfo> IosDeviceInfo;
            Boxed<UserKongregateInfo> KongregateInfo;
            Boxed<UserNintendoSwitchDeviceIdInfo> NintendoSwitchDeviceIdInfo;
            std::list<UserOpenIdInfo> OpenIdInfo;
            std::string PlayFabId;
            Boxed<UserPrivateAccountInfo> PrivateInfo;
            Boxed<UserPsnInfo> PsnInfo;
            Boxed<UserSteamInfo> SteamInfo;
            Boxed<UserTitleInfo> TitleInfo;
            Boxed<UserTwitchInfo> TwitchInfo;
            std::string Username;
            Boxed<UserWindowsHelloInfo> WindowsHelloInfo;
            Boxed<UserXboxInfo> XboxInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                AndroidDeviceInfo(),
                Created(),
                CustomIdInfo(),
                FacebookInfo(),
                FacebookInstantGamesIdInfo(),
                GameCenterInfo(),
                GoogleInfo(),
                IosDeviceInfo(),
                KongregateInfo(),
                NintendoSwitchDeviceIdInfo(),
                OpenIdInfo(),
                PlayFabId(),
                PrivateInfo(),
                PsnInfo(),
                SteamInfo(),
                TitleInfo(),
                TwitchInfo(),
                Username(),
                WindowsHelloInfo(),
                XboxInfo()
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceInfo(src.AndroidDeviceInfo),
                Created(src.Created),
                CustomIdInfo(src.CustomIdInfo),
                FacebookInfo(src.FacebookInfo),
                FacebookInstantGamesIdInfo(src.FacebookInstantGamesIdInfo),
                GameCenterInfo(src.GameCenterInfo),
                GoogleInfo(src.GoogleInfo),
                IosDeviceInfo(src.IosDeviceInfo),
                KongregateInfo(src.KongregateInfo),
                NintendoSwitchDeviceIdInfo(src.NintendoSwitchDeviceIdInfo),
                OpenIdInfo(src.OpenIdInfo),
                PlayFabId(src.PlayFabId),
                PrivateInfo(src.PrivateInfo),
                PsnInfo(src.PsnInfo),
                SteamInfo(src.SteamInfo),
                TitleInfo(src.TitleInfo),
                TwitchInfo(src.TwitchInfo),
                Username(src.Username),
                WindowsHelloInfo(src.WindowsHelloInfo),
                XboxInfo(src.XboxInfo)
            {}

            ~UserAccountInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["AndroidDeviceInfo"], AndroidDeviceInfo);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilO(input["CustomIdInfo"], CustomIdInfo);
                FromJsonUtilO(input["FacebookInfo"], FacebookInfo);
                FromJsonUtilO(input["FacebookInstantGamesIdInfo"], FacebookInstantGamesIdInfo);
                FromJsonUtilO(input["GameCenterInfo"], GameCenterInfo);
                FromJsonUtilO(input["GoogleInfo"], GoogleInfo);
                FromJsonUtilO(input["IosDeviceInfo"], IosDeviceInfo);
                FromJsonUtilO(input["KongregateInfo"], KongregateInfo);
                FromJsonUtilO(input["NintendoSwitchDeviceIdInfo"], NintendoSwitchDeviceIdInfo);
                FromJsonUtilO(input["OpenIdInfo"], OpenIdInfo);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilO(input["PrivateInfo"], PrivateInfo);
                FromJsonUtilO(input["PsnInfo"], PsnInfo);
                FromJsonUtilO(input["SteamInfo"], SteamInfo);
                FromJsonUtilO(input["TitleInfo"], TitleInfo);
                FromJsonUtilO(input["TwitchInfo"], TwitchInfo);
                FromJsonUtilS(input["Username"], Username);
                FromJsonUtilO(input["WindowsHelloInfo"], WindowsHelloInfo);
                FromJsonUtilO(input["XboxInfo"], XboxInfo);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AndroidDeviceInfo; ToJsonUtilO(AndroidDeviceInfo, each_AndroidDeviceInfo); output["AndroidDeviceInfo"] = each_AndroidDeviceInfo;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_CustomIdInfo; ToJsonUtilO(CustomIdInfo, each_CustomIdInfo); output["CustomIdInfo"] = each_CustomIdInfo;
                Json::Value each_FacebookInfo; ToJsonUtilO(FacebookInfo, each_FacebookInfo); output["FacebookInfo"] = each_FacebookInfo;
                Json::Value each_FacebookInstantGamesIdInfo; ToJsonUtilO(FacebookInstantGamesIdInfo, each_FacebookInstantGamesIdInfo); output["FacebookInstantGamesIdInfo"] = each_FacebookInstantGamesIdInfo;
                Json::Value each_GameCenterInfo; ToJsonUtilO(GameCenterInfo, each_GameCenterInfo); output["GameCenterInfo"] = each_GameCenterInfo;
                Json::Value each_GoogleInfo; ToJsonUtilO(GoogleInfo, each_GoogleInfo); output["GoogleInfo"] = each_GoogleInfo;
                Json::Value each_IosDeviceInfo; ToJsonUtilO(IosDeviceInfo, each_IosDeviceInfo); output["IosDeviceInfo"] = each_IosDeviceInfo;
                Json::Value each_KongregateInfo; ToJsonUtilO(KongregateInfo, each_KongregateInfo); output["KongregateInfo"] = each_KongregateInfo;
                Json::Value each_NintendoSwitchDeviceIdInfo; ToJsonUtilO(NintendoSwitchDeviceIdInfo, each_NintendoSwitchDeviceIdInfo); output["NintendoSwitchDeviceIdInfo"] = each_NintendoSwitchDeviceIdInfo;
                Json::Value each_OpenIdInfo; ToJsonUtilO(OpenIdInfo, each_OpenIdInfo); output["OpenIdInfo"] = each_OpenIdInfo;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_PrivateInfo; ToJsonUtilO(PrivateInfo, each_PrivateInfo); output["PrivateInfo"] = each_PrivateInfo;
                Json::Value each_PsnInfo; ToJsonUtilO(PsnInfo, each_PsnInfo); output["PsnInfo"] = each_PsnInfo;
                Json::Value each_SteamInfo; ToJsonUtilO(SteamInfo, each_SteamInfo); output["SteamInfo"] = each_SteamInfo;
                Json::Value each_TitleInfo; ToJsonUtilO(TitleInfo, each_TitleInfo); output["TitleInfo"] = each_TitleInfo;
                Json::Value each_TwitchInfo; ToJsonUtilO(TwitchInfo, each_TwitchInfo); output["TwitchInfo"] = each_TwitchInfo;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
                Json::Value each_WindowsHelloInfo; ToJsonUtilO(WindowsHelloInfo, each_WindowsHelloInfo); output["WindowsHelloInfo"] = each_WindowsHelloInfo;
                Json::Value each_XboxInfo; ToJsonUtilO(XboxInfo, each_XboxInfo); output["XboxInfo"] = each_XboxInfo;
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

            ~GetAccountInfoResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["AccountInfo"], AccountInfo);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccountInfo; ToJsonUtilO(AccountInfo, each_AccountInfo); output["AccountInfo"] = each_AccountInfo;
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

            ~GetCatalogItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
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

            ~GetCatalogItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Catalog"], Catalog);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Catalog; ToJsonUtilO(Catalog, each_Catalog); output["Catalog"] = each_Catalog;
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

            ~GetCharacterDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilP(input["IfChangedFromDataVersion"], IfChangedFromDataVersion);
                FromJsonUtilS(input["Keys"], Keys);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_IfChangedFromDataVersion; ToJsonUtilP(IfChangedFromDataVersion, each_IfChangedFromDataVersion); output["IfChangedFromDataVersion"] = each_IfChangedFromDataVersion;
                Json::Value each_Keys; ToJsonUtilS(Keys, each_Keys); output["Keys"] = each_Keys;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~UserDataRecord() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["LastUpdated"], LastUpdated);
                FromJsonUtilE(input["Permission"], Permission);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LastUpdated; ToJsonUtilT(LastUpdated, each_LastUpdated); output["LastUpdated"] = each_LastUpdated;
                Json::Value each_Permission; ToJsonUtilE(Permission, each_Permission); output["Permission"] = each_Permission;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
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

            ~GetCharacterDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilO(input["Data"], Data);
                FromJsonUtilP(input["DataVersion"], DataVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output["DataVersion"] = each_DataVersion;
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

            ~GetCharacterInventoryRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CharacterId"], CharacterId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
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

            ~VirtualCurrencyRechargeTime() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["RechargeMax"], RechargeMax);
                FromJsonUtilT(input["RechargeTime"], RechargeTime);
                FromJsonUtilP(input["SecondsToRecharge"], SecondsToRecharge);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_RechargeMax; ToJsonUtilP(RechargeMax, each_RechargeMax); output["RechargeMax"] = each_RechargeMax;
                Json::Value each_RechargeTime; ToJsonUtilT(RechargeTime, each_RechargeTime); output["RechargeTime"] = each_RechargeTime;
                Json::Value each_SecondsToRecharge; ToJsonUtilP(SecondsToRecharge, each_SecondsToRecharge); output["SecondsToRecharge"] = each_SecondsToRecharge;
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

            ~GetCharacterInventoryResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilO(input["Inventory"], Inventory);
                FromJsonUtilP(input["VirtualCurrency"], VirtualCurrency);
                FromJsonUtilO(input["VirtualCurrencyRechargeTimes"], VirtualCurrencyRechargeTimes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output["Inventory"] = each_Inventory;
                Json::Value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
                Json::Value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output["VirtualCurrencyRechargeTimes"] = each_VirtualCurrencyRechargeTimes;
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

            ~GetCharacterLeaderboardRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterType"], CharacterType);
                FromJsonUtilP(input["MaxResultsCount"], MaxResultsCount);
                FromJsonUtilP(input["StartPosition"], StartPosition);
                FromJsonUtilS(input["StatisticName"], StatisticName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output["CharacterType"] = each_CharacterType;
                Json::Value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output["MaxResultsCount"] = each_MaxResultsCount;
                Json::Value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output["StartPosition"] = each_StartPosition;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
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

            ~GetCharacterLeaderboardResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Leaderboard"], Leaderboard);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output["Leaderboard"] = each_Leaderboard;
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

            ~GetCharacterStatisticsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
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

            ~GetCharacterStatisticsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CharacterStatistics"], CharacterStatistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterStatistics; ToJsonUtilP(CharacterStatistics, each_CharacterStatistics); output["CharacterStatistics"] = each_CharacterStatistics;
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

            ~GetContentDownloadUrlRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["HttpMethod"], HttpMethod);
                FromJsonUtilS(input["Key"], Key);
                FromJsonUtilP(input["ThruCDN"], ThruCDN);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_HttpMethod; ToJsonUtilS(HttpMethod, each_HttpMethod); output["HttpMethod"] = each_HttpMethod;
                Json::Value each_Key; ToJsonUtilS(Key, each_Key); output["Key"] = each_Key;
                Json::Value each_ThruCDN; ToJsonUtilP(ThruCDN, each_ThruCDN); output["ThruCDN"] = each_ThruCDN;
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

            ~GetContentDownloadUrlResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["URL"], URL);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_URL; ToJsonUtilS(URL, each_URL); output["URL"] = each_URL;
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

            ~PlayerProfileViewConstraints() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ShowAvatarUrl"], ShowAvatarUrl);
                FromJsonUtilP(input["ShowBannedUntil"], ShowBannedUntil);
                FromJsonUtilP(input["ShowCampaignAttributions"], ShowCampaignAttributions);
                FromJsonUtilP(input["ShowContactEmailAddresses"], ShowContactEmailAddresses);
                FromJsonUtilP(input["ShowCreated"], ShowCreated);
                FromJsonUtilP(input["ShowDisplayName"], ShowDisplayName);
                FromJsonUtilP(input["ShowLastLogin"], ShowLastLogin);
                FromJsonUtilP(input["ShowLinkedAccounts"], ShowLinkedAccounts);
                FromJsonUtilP(input["ShowLocations"], ShowLocations);
                FromJsonUtilP(input["ShowMemberships"], ShowMemberships);
                FromJsonUtilP(input["ShowOrigination"], ShowOrigination);
                FromJsonUtilP(input["ShowPushNotificationRegistrations"], ShowPushNotificationRegistrations);
                FromJsonUtilP(input["ShowStatistics"], ShowStatistics);
                FromJsonUtilP(input["ShowTags"], ShowTags);
                FromJsonUtilP(input["ShowTotalValueToDateInUsd"], ShowTotalValueToDateInUsd);
                FromJsonUtilP(input["ShowValuesToDate"], ShowValuesToDate);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ShowAvatarUrl; ToJsonUtilP(ShowAvatarUrl, each_ShowAvatarUrl); output["ShowAvatarUrl"] = each_ShowAvatarUrl;
                Json::Value each_ShowBannedUntil; ToJsonUtilP(ShowBannedUntil, each_ShowBannedUntil); output["ShowBannedUntil"] = each_ShowBannedUntil;
                Json::Value each_ShowCampaignAttributions; ToJsonUtilP(ShowCampaignAttributions, each_ShowCampaignAttributions); output["ShowCampaignAttributions"] = each_ShowCampaignAttributions;
                Json::Value each_ShowContactEmailAddresses; ToJsonUtilP(ShowContactEmailAddresses, each_ShowContactEmailAddresses); output["ShowContactEmailAddresses"] = each_ShowContactEmailAddresses;
                Json::Value each_ShowCreated; ToJsonUtilP(ShowCreated, each_ShowCreated); output["ShowCreated"] = each_ShowCreated;
                Json::Value each_ShowDisplayName; ToJsonUtilP(ShowDisplayName, each_ShowDisplayName); output["ShowDisplayName"] = each_ShowDisplayName;
                Json::Value each_ShowLastLogin; ToJsonUtilP(ShowLastLogin, each_ShowLastLogin); output["ShowLastLogin"] = each_ShowLastLogin;
                Json::Value each_ShowLinkedAccounts; ToJsonUtilP(ShowLinkedAccounts, each_ShowLinkedAccounts); output["ShowLinkedAccounts"] = each_ShowLinkedAccounts;
                Json::Value each_ShowLocations; ToJsonUtilP(ShowLocations, each_ShowLocations); output["ShowLocations"] = each_ShowLocations;
                Json::Value each_ShowMemberships; ToJsonUtilP(ShowMemberships, each_ShowMemberships); output["ShowMemberships"] = each_ShowMemberships;
                Json::Value each_ShowOrigination; ToJsonUtilP(ShowOrigination, each_ShowOrigination); output["ShowOrigination"] = each_ShowOrigination;
                Json::Value each_ShowPushNotificationRegistrations; ToJsonUtilP(ShowPushNotificationRegistrations, each_ShowPushNotificationRegistrations); output["ShowPushNotificationRegistrations"] = each_ShowPushNotificationRegistrations;
                Json::Value each_ShowStatistics; ToJsonUtilP(ShowStatistics, each_ShowStatistics); output["ShowStatistics"] = each_ShowStatistics;
                Json::Value each_ShowTags; ToJsonUtilP(ShowTags, each_ShowTags); output["ShowTags"] = each_ShowTags;
                Json::Value each_ShowTotalValueToDateInUsd; ToJsonUtilP(ShowTotalValueToDateInUsd, each_ShowTotalValueToDateInUsd); output["ShowTotalValueToDateInUsd"] = each_ShowTotalValueToDateInUsd;
                Json::Value each_ShowValuesToDate; ToJsonUtilP(ShowValuesToDate, each_ShowValuesToDate); output["ShowValuesToDate"] = each_ShowValuesToDate;
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

            ~GetFriendLeaderboardAroundPlayerRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["IncludeFacebookFriends"], IncludeFacebookFriends);
                FromJsonUtilP(input["IncludeSteamFriends"], IncludeSteamFriends);
                FromJsonUtilP(input["MaxResultsCount"], MaxResultsCount);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilO(input["ProfileConstraints"], ProfileConstraints);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["Version"], Version);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output["IncludeFacebookFriends"] = each_IncludeFacebookFriends;
                Json::Value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output["IncludeSteamFriends"] = each_IncludeSteamFriends;
                Json::Value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output["MaxResultsCount"] = each_MaxResultsCount;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output["ProfileConstraints"] = each_ProfileConstraints;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
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

            ~PlayerLeaderboardEntry() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilP(input["Position"], Position);
                FromJsonUtilO(input["Profile"], Profile);
                FromJsonUtilP(input["StatValue"], StatValue);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_Position; ToJsonUtilP(Position, each_Position); output["Position"] = each_Position;
                Json::Value each_Profile; ToJsonUtilO(Profile, each_Profile); output["Profile"] = each_Profile;
                Json::Value each_StatValue; ToJsonUtilP(StatValue, each_StatValue); output["StatValue"] = each_StatValue;
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

            ~GetFriendLeaderboardAroundPlayerResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Leaderboard"], Leaderboard);
                FromJsonUtilT(input["NextReset"], NextReset);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output["Leaderboard"] = each_Leaderboard;
                Json::Value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output["NextReset"] = each_NextReset;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetFriendLeaderboardRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["IncludeFacebookFriends"], IncludeFacebookFriends);
                FromJsonUtilP(input["IncludeSteamFriends"], IncludeSteamFriends);
                FromJsonUtilP(input["MaxResultsCount"], MaxResultsCount);
                FromJsonUtilO(input["ProfileConstraints"], ProfileConstraints);
                FromJsonUtilP(input["StartPosition"], StartPosition);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["Version"], Version);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output["IncludeFacebookFriends"] = each_IncludeFacebookFriends;
                Json::Value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output["IncludeSteamFriends"] = each_IncludeSteamFriends;
                Json::Value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output["MaxResultsCount"] = each_MaxResultsCount;
                Json::Value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output["ProfileConstraints"] = each_ProfileConstraints;
                Json::Value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output["StartPosition"] = each_StartPosition;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
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

            ~GetFriendsListRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["IncludeFacebookFriends"], IncludeFacebookFriends);
                FromJsonUtilP(input["IncludeSteamFriends"], IncludeSteamFriends);
                FromJsonUtilO(input["ProfileConstraints"], ProfileConstraints);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output["IncludeFacebookFriends"] = each_IncludeFacebookFriends;
                Json::Value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output["IncludeSteamFriends"] = each_IncludeSteamFriends;
                Json::Value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output["ProfileConstraints"] = each_ProfileConstraints;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
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

            ~GetFriendsListResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Friends"], Friends);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Friends; ToJsonUtilO(Friends, each_Friends); output["Friends"] = each_Friends;
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

            ~GetLeaderboardAroundCharacterRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["CharacterType"], CharacterType);
                FromJsonUtilP(input["MaxResultsCount"], MaxResultsCount);
                FromJsonUtilS(input["StatisticName"], StatisticName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output["CharacterType"] = each_CharacterType;
                Json::Value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output["MaxResultsCount"] = each_MaxResultsCount;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
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

            ~GetLeaderboardAroundCharacterResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Leaderboard"], Leaderboard);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output["Leaderboard"] = each_Leaderboard;
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

            ~GetLeaderboardAroundPlayerRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["MaxResultsCount"], MaxResultsCount);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilO(input["ProfileConstraints"], ProfileConstraints);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output["MaxResultsCount"] = each_MaxResultsCount;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output["ProfileConstraints"] = each_ProfileConstraints;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetLeaderboardAroundPlayerResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Leaderboard"], Leaderboard);
                FromJsonUtilT(input["NextReset"], NextReset);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output["Leaderboard"] = each_Leaderboard;
                Json::Value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output["NextReset"] = each_NextReset;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetLeaderboardForUsersCharactersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["MaxResultsCount"], MaxResultsCount);
                FromJsonUtilS(input["StatisticName"], StatisticName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output["MaxResultsCount"] = each_MaxResultsCount;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
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

            ~GetLeaderboardForUsersCharactersResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Leaderboard"], Leaderboard);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output["Leaderboard"] = each_Leaderboard;
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

            ~GetLeaderboardRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["MaxResultsCount"], MaxResultsCount);
                FromJsonUtilO(input["ProfileConstraints"], ProfileConstraints);
                FromJsonUtilP(input["StartPosition"], StartPosition);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output["MaxResultsCount"] = each_MaxResultsCount;
                Json::Value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output["ProfileConstraints"] = each_ProfileConstraints;
                Json::Value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output["StartPosition"] = each_StartPosition;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetLeaderboardResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Leaderboard"], Leaderboard);
                FromJsonUtilT(input["NextReset"], NextReset);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output["Leaderboard"] = each_Leaderboard;
                Json::Value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output["NextReset"] = each_NextReset;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetPaymentTokenRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TokenProvider"], TokenProvider);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TokenProvider; ToJsonUtilS(TokenProvider, each_TokenProvider); output["TokenProvider"] = each_TokenProvider;
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

            ~GetPaymentTokenResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OrderId"], OrderId);
                FromJsonUtilS(input["ProviderToken"], ProviderToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
                Json::Value each_ProviderToken; ToJsonUtilS(ProviderToken, each_ProviderToken); output["ProviderToken"] = each_ProviderToken;
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

            ~GetPhotonAuthenticationTokenRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PhotonApplicationId"], PhotonApplicationId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PhotonApplicationId; ToJsonUtilS(PhotonApplicationId, each_PhotonApplicationId); output["PhotonApplicationId"] = each_PhotonApplicationId;
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

            ~GetPhotonAuthenticationTokenResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PhotonCustomAuthenticationToken"], PhotonCustomAuthenticationToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PhotonCustomAuthenticationToken; ToJsonUtilS(PhotonCustomAuthenticationToken, each_PhotonCustomAuthenticationToken); output["PhotonCustomAuthenticationToken"] = each_PhotonCustomAuthenticationToken;
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

            ~GetPlayerCombinedInfoRequestParams() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["GetCharacterInventories"], GetCharacterInventories);
                FromJsonUtilP(input["GetCharacterList"], GetCharacterList);
                FromJsonUtilP(input["GetPlayerProfile"], GetPlayerProfile);
                FromJsonUtilP(input["GetPlayerStatistics"], GetPlayerStatistics);
                FromJsonUtilP(input["GetTitleData"], GetTitleData);
                FromJsonUtilP(input["GetUserAccountInfo"], GetUserAccountInfo);
                FromJsonUtilP(input["GetUserData"], GetUserData);
                FromJsonUtilP(input["GetUserInventory"], GetUserInventory);
                FromJsonUtilP(input["GetUserReadOnlyData"], GetUserReadOnlyData);
                FromJsonUtilP(input["GetUserVirtualCurrency"], GetUserVirtualCurrency);
                FromJsonUtilS(input["PlayerStatisticNames"], PlayerStatisticNames);
                FromJsonUtilO(input["ProfileConstraints"], ProfileConstraints);
                FromJsonUtilS(input["TitleDataKeys"], TitleDataKeys);
                FromJsonUtilS(input["UserDataKeys"], UserDataKeys);
                FromJsonUtilS(input["UserReadOnlyDataKeys"], UserReadOnlyDataKeys);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GetCharacterInventories; ToJsonUtilP(GetCharacterInventories, each_GetCharacterInventories); output["GetCharacterInventories"] = each_GetCharacterInventories;
                Json::Value each_GetCharacterList; ToJsonUtilP(GetCharacterList, each_GetCharacterList); output["GetCharacterList"] = each_GetCharacterList;
                Json::Value each_GetPlayerProfile; ToJsonUtilP(GetPlayerProfile, each_GetPlayerProfile); output["GetPlayerProfile"] = each_GetPlayerProfile;
                Json::Value each_GetPlayerStatistics; ToJsonUtilP(GetPlayerStatistics, each_GetPlayerStatistics); output["GetPlayerStatistics"] = each_GetPlayerStatistics;
                Json::Value each_GetTitleData; ToJsonUtilP(GetTitleData, each_GetTitleData); output["GetTitleData"] = each_GetTitleData;
                Json::Value each_GetUserAccountInfo; ToJsonUtilP(GetUserAccountInfo, each_GetUserAccountInfo); output["GetUserAccountInfo"] = each_GetUserAccountInfo;
                Json::Value each_GetUserData; ToJsonUtilP(GetUserData, each_GetUserData); output["GetUserData"] = each_GetUserData;
                Json::Value each_GetUserInventory; ToJsonUtilP(GetUserInventory, each_GetUserInventory); output["GetUserInventory"] = each_GetUserInventory;
                Json::Value each_GetUserReadOnlyData; ToJsonUtilP(GetUserReadOnlyData, each_GetUserReadOnlyData); output["GetUserReadOnlyData"] = each_GetUserReadOnlyData;
                Json::Value each_GetUserVirtualCurrency; ToJsonUtilP(GetUserVirtualCurrency, each_GetUserVirtualCurrency); output["GetUserVirtualCurrency"] = each_GetUserVirtualCurrency;
                Json::Value each_PlayerStatisticNames; ToJsonUtilS(PlayerStatisticNames, each_PlayerStatisticNames); output["PlayerStatisticNames"] = each_PlayerStatisticNames;
                Json::Value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output["ProfileConstraints"] = each_ProfileConstraints;
                Json::Value each_TitleDataKeys; ToJsonUtilS(TitleDataKeys, each_TitleDataKeys); output["TitleDataKeys"] = each_TitleDataKeys;
                Json::Value each_UserDataKeys; ToJsonUtilS(UserDataKeys, each_UserDataKeys); output["UserDataKeys"] = each_UserDataKeys;
                Json::Value each_UserReadOnlyDataKeys; ToJsonUtilS(UserReadOnlyDataKeys, each_UserReadOnlyDataKeys); output["UserReadOnlyDataKeys"] = each_UserReadOnlyDataKeys;
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

            ~GetPlayerCombinedInfoRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~StatisticValue() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["Value"], Value);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Value; ToJsonUtilP(Value, each_Value); output["Value"] = each_Value;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetPlayerCombinedInfoResultPayload() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["AccountInfo"], AccountInfo);
                FromJsonUtilO(input["CharacterInventories"], CharacterInventories);
                FromJsonUtilO(input["CharacterList"], CharacterList);
                FromJsonUtilO(input["PlayerProfile"], PlayerProfile);
                FromJsonUtilO(input["PlayerStatistics"], PlayerStatistics);
                FromJsonUtilS(input["TitleData"], TitleData);
                FromJsonUtilO(input["UserData"], UserData);
                FromJsonUtilP(input["UserDataVersion"], UserDataVersion);
                FromJsonUtilO(input["UserInventory"], UserInventory);
                FromJsonUtilO(input["UserReadOnlyData"], UserReadOnlyData);
                FromJsonUtilP(input["UserReadOnlyDataVersion"], UserReadOnlyDataVersion);
                FromJsonUtilP(input["UserVirtualCurrency"], UserVirtualCurrency);
                FromJsonUtilO(input["UserVirtualCurrencyRechargeTimes"], UserVirtualCurrencyRechargeTimes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccountInfo; ToJsonUtilO(AccountInfo, each_AccountInfo); output["AccountInfo"] = each_AccountInfo;
                Json::Value each_CharacterInventories; ToJsonUtilO(CharacterInventories, each_CharacterInventories); output["CharacterInventories"] = each_CharacterInventories;
                Json::Value each_CharacterList; ToJsonUtilO(CharacterList, each_CharacterList); output["CharacterList"] = each_CharacterList;
                Json::Value each_PlayerProfile; ToJsonUtilO(PlayerProfile, each_PlayerProfile); output["PlayerProfile"] = each_PlayerProfile;
                Json::Value each_PlayerStatistics; ToJsonUtilO(PlayerStatistics, each_PlayerStatistics); output["PlayerStatistics"] = each_PlayerStatistics;
                Json::Value each_TitleData; ToJsonUtilS(TitleData, each_TitleData); output["TitleData"] = each_TitleData;
                Json::Value each_UserData; ToJsonUtilO(UserData, each_UserData); output["UserData"] = each_UserData;
                Json::Value each_UserDataVersion; ToJsonUtilP(UserDataVersion, each_UserDataVersion); output["UserDataVersion"] = each_UserDataVersion;
                Json::Value each_UserInventory; ToJsonUtilO(UserInventory, each_UserInventory); output["UserInventory"] = each_UserInventory;
                Json::Value each_UserReadOnlyData; ToJsonUtilO(UserReadOnlyData, each_UserReadOnlyData); output["UserReadOnlyData"] = each_UserReadOnlyData;
                Json::Value each_UserReadOnlyDataVersion; ToJsonUtilP(UserReadOnlyDataVersion, each_UserReadOnlyDataVersion); output["UserReadOnlyDataVersion"] = each_UserReadOnlyDataVersion;
                Json::Value each_UserVirtualCurrency; ToJsonUtilP(UserVirtualCurrency, each_UserVirtualCurrency); output["UserVirtualCurrency"] = each_UserVirtualCurrency;
                Json::Value each_UserVirtualCurrencyRechargeTimes; ToJsonUtilO(UserVirtualCurrencyRechargeTimes, each_UserVirtualCurrencyRechargeTimes); output["UserVirtualCurrencyRechargeTimes"] = each_UserVirtualCurrencyRechargeTimes;
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

            ~GetPlayerCombinedInfoResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["InfoResultPayload"], InfoResultPayload);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_InfoResultPayload; ToJsonUtilO(InfoResultPayload, each_InfoResultPayload); output["InfoResultPayload"] = each_InfoResultPayload;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GetPlayerProfileRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilO(input["ProfileConstraints"], ProfileConstraints);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output["ProfileConstraints"] = each_ProfileConstraints;
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

            ~GetPlayerProfileResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["PlayerProfile"], PlayerProfile);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayerProfile; ToJsonUtilO(PlayerProfile, each_PlayerProfile); output["PlayerProfile"] = each_PlayerProfile;
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

            ~GetPlayerSegmentsRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~GetSegmentResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ABTestParent"], ABTestParent);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ABTestParent; ToJsonUtilS(ABTestParent, each_ABTestParent); output["ABTestParent"] = each_ABTestParent;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
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

            ~GetPlayerSegmentsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Segments"], Segments);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Segments; ToJsonUtilO(Segments, each_Segments); output["Segments"] = each_Segments;
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

            ~StatisticNameVersion() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetPlayerStatisticsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["StatisticNames"], StatisticNames);
                FromJsonUtilO(input["StatisticNameVersions"], StatisticNameVersions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatisticNames; ToJsonUtilS(StatisticNames, each_StatisticNames); output["StatisticNames"] = each_StatisticNames;
                Json::Value each_StatisticNameVersions; ToJsonUtilO(StatisticNameVersions, each_StatisticNameVersions); output["StatisticNameVersions"] = each_StatisticNameVersions;
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

            ~GetPlayerStatisticsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
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

            ~GetPlayerStatisticVersionsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["StatisticName"], StatisticName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
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

            ~PlayerStatisticVersion() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["ActivationTime"], ActivationTime);
                FromJsonUtilT(input["DeactivationTime"], DeactivationTime);
                FromJsonUtilT(input["ScheduledActivationTime"], ScheduledActivationTime);
                FromJsonUtilT(input["ScheduledDeactivationTime"], ScheduledDeactivationTime);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ActivationTime; ToJsonUtilT(ActivationTime, each_ActivationTime); output["ActivationTime"] = each_ActivationTime;
                Json::Value each_DeactivationTime; ToJsonUtilT(DeactivationTime, each_DeactivationTime); output["DeactivationTime"] = each_DeactivationTime;
                Json::Value each_ScheduledActivationTime; ToJsonUtilT(ScheduledActivationTime, each_ScheduledActivationTime); output["ScheduledActivationTime"] = each_ScheduledActivationTime;
                Json::Value each_ScheduledDeactivationTime; ToJsonUtilT(ScheduledDeactivationTime, each_ScheduledDeactivationTime); output["ScheduledDeactivationTime"] = each_ScheduledDeactivationTime;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetPlayerStatisticVersionsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["StatisticVersions"], StatisticVersions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatisticVersions; ToJsonUtilO(StatisticVersions, each_StatisticVersions); output["StatisticVersions"] = each_StatisticVersions;
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

            ~GetPlayerTagsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Namespace"], Namespace);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Namespace; ToJsonUtilS(Namespace, each_Namespace); output["Namespace"] = each_Namespace;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GetPlayerTagsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
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

            ~GetPlayerTradesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["StatusFilter"], StatusFilter);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatusFilter; ToJsonUtilE(StatusFilter, each_StatusFilter); output["StatusFilter"] = each_StatusFilter;
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

            ~GetPlayerTradesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["AcceptedTrades"], AcceptedTrades);
                FromJsonUtilO(input["OpenedTrades"], OpenedTrades);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AcceptedTrades; ToJsonUtilO(AcceptedTrades, each_AcceptedTrades); output["AcceptedTrades"] = each_AcceptedTrades;
                Json::Value each_OpenedTrades; ToJsonUtilO(OpenedTrades, each_OpenedTrades); output["OpenedTrades"] = each_OpenedTrades;
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

            ~GetPlayFabIDsFromFacebookIDsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FacebookIDs"], FacebookIDs);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FacebookIDs; ToJsonUtilS(FacebookIDs, each_FacebookIDs); output["FacebookIDs"] = each_FacebookIDs;
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

            ~GetPlayFabIDsFromFacebookIDsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPlayFabIDsFromFacebookInstantGamesIdsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FacebookInstantGamesIds"], FacebookInstantGamesIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FacebookInstantGamesIds; ToJsonUtilS(FacebookInstantGamesIds, each_FacebookInstantGamesIds); output["FacebookInstantGamesIds"] = each_FacebookInstantGamesIds;
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

            ~GetPlayFabIDsFromFacebookInstantGamesIdsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPlayFabIDsFromGameCenterIDsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["GameCenterIDs"], GameCenterIDs);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GameCenterIDs; ToJsonUtilS(GameCenterIDs, each_GameCenterIDs); output["GameCenterIDs"] = each_GameCenterIDs;
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

            ~GetPlayFabIDsFromGameCenterIDsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPlayFabIDsFromGenericIDsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["GenericIDs"], GenericIDs);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GenericIDs; ToJsonUtilO(GenericIDs, each_GenericIDs); output["GenericIDs"] = each_GenericIDs;
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

            ~GetPlayFabIDsFromGenericIDsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPlayFabIDsFromGoogleIDsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["GoogleIDs"], GoogleIDs);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GoogleIDs; ToJsonUtilS(GoogleIDs, each_GoogleIDs); output["GoogleIDs"] = each_GoogleIDs;
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

            ~GooglePlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["GoogleId"], GoogleId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GoogleId; ToJsonUtilS(GoogleId, each_GoogleId); output["GoogleId"] = each_GoogleId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GetPlayFabIDsFromGoogleIDsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPlayFabIDsFromKongregateIDsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["KongregateIDs"], KongregateIDs);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_KongregateIDs; ToJsonUtilS(KongregateIDs, each_KongregateIDs); output["KongregateIDs"] = each_KongregateIDs;
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

            ~KongregatePlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["KongregateId"], KongregateId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output["KongregateId"] = each_KongregateId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GetPlayFabIDsFromKongregateIDsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["NintendoSwitchDeviceIds"], NintendoSwitchDeviceIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NintendoSwitchDeviceIds; ToJsonUtilS(NintendoSwitchDeviceIds, each_NintendoSwitchDeviceIds); output["NintendoSwitchDeviceIds"] = each_NintendoSwitchDeviceIds;
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

            ~NintendoSwitchPlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output["NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GetPlayFabIDsFromNintendoSwitchDeviceIdsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPlayFabIDsFromSteamIDsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["SteamStringIDs"], SteamStringIDs);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_SteamStringIDs; ToJsonUtilS(SteamStringIDs, each_SteamStringIDs); output["SteamStringIDs"] = each_SteamStringIDs;
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

            ~SteamPlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["SteamStringId"], SteamStringId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_SteamStringId; ToJsonUtilS(SteamStringId, each_SteamStringId); output["SteamStringId"] = each_SteamStringId;
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

            ~GetPlayFabIDsFromSteamIDsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPlayFabIDsFromTwitchIDsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TwitchIds"], TwitchIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TwitchIds; ToJsonUtilS(TwitchIds, each_TwitchIds); output["TwitchIds"] = each_TwitchIds;
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

            ~TwitchPlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["TwitchId"], TwitchId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_TwitchId; ToJsonUtilS(TwitchId, each_TwitchId); output["TwitchId"] = each_TwitchId;
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

            ~GetPlayFabIDsFromTwitchIDsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromXboxLiveIDsRequest : public PlayFabRequestCommon
        {
            std::string Sandbox;
            std::list<std::string> XboxLiveAccountIDs;

            GetPlayFabIDsFromXboxLiveIDsRequest() :
                PlayFabRequestCommon(),
                Sandbox(),
                XboxLiveAccountIDs()
            {}

            GetPlayFabIDsFromXboxLiveIDsRequest(const GetPlayFabIDsFromXboxLiveIDsRequest& src) :
                PlayFabRequestCommon(),
                Sandbox(src.Sandbox),
                XboxLiveAccountIDs(src.XboxLiveAccountIDs)
            {}

            ~GetPlayFabIDsFromXboxLiveIDsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Sandbox"], Sandbox);
                FromJsonUtilS(input["XboxLiveAccountIDs"], XboxLiveAccountIDs);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Sandbox; ToJsonUtilS(Sandbox, each_Sandbox); output["Sandbox"] = each_Sandbox;
                Json::Value each_XboxLiveAccountIDs; ToJsonUtilS(XboxLiveAccountIDs, each_XboxLiveAccountIDs); output["XboxLiveAccountIDs"] = each_XboxLiveAccountIDs;
                return output;
            }
        };

        struct XboxLiveAccountPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string XboxLiveAccountId;

            XboxLiveAccountPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                XboxLiveAccountId()
            {}

            XboxLiveAccountPlayFabIdPair(const XboxLiveAccountPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                XboxLiveAccountId(src.XboxLiveAccountId)
            {}

            ~XboxLiveAccountPlayFabIdPair() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["XboxLiveAccountId"], XboxLiveAccountId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_XboxLiveAccountId; ToJsonUtilS(XboxLiveAccountId, each_XboxLiveAccountId); output["XboxLiveAccountId"] = each_XboxLiveAccountId;
                return output;
            }
        };

        struct GetPlayFabIDsFromXboxLiveIDsResult : public PlayFabResultCommon
        {
            std::list<XboxLiveAccountPlayFabIdPair> Data;

            GetPlayFabIDsFromXboxLiveIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromXboxLiveIDsResult(const GetPlayFabIDsFromXboxLiveIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromXboxLiveIDsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPublisherDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Keys"], Keys);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Keys; ToJsonUtilS(Keys, each_Keys); output["Keys"] = each_Keys;
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

            ~GetPublisherDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
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

            ~GetPurchaseRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OrderId"], OrderId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
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

            ~GetPurchaseResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OrderId"], OrderId);
                FromJsonUtilS(input["PaymentProvider"], PaymentProvider);
                FromJsonUtilT(input["PurchaseDate"], PurchaseDate);
                FromJsonUtilS(input["TransactionId"], TransactionId);
                FromJsonUtilS(input["TransactionStatus"], TransactionStatus);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
                Json::Value each_PaymentProvider; ToJsonUtilS(PaymentProvider, each_PaymentProvider); output["PaymentProvider"] = each_PaymentProvider;
                Json::Value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output["PurchaseDate"] = each_PurchaseDate;
                Json::Value each_TransactionId; ToJsonUtilS(TransactionId, each_TransactionId); output["TransactionId"] = each_TransactionId;
                Json::Value each_TransactionStatus; ToJsonUtilS(TransactionStatus, each_TransactionStatus); output["TransactionStatus"] = each_TransactionStatus;
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

            ~GetSharedGroupDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["GetMembers"], GetMembers);
                FromJsonUtilS(input["Keys"], Keys);
                FromJsonUtilS(input["SharedGroupId"], SharedGroupId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GetMembers; ToJsonUtilP(GetMembers, each_GetMembers); output["GetMembers"] = each_GetMembers;
                Json::Value each_Keys; ToJsonUtilS(Keys, each_Keys); output["Keys"] = each_Keys;
                Json::Value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output["SharedGroupId"] = each_SharedGroupId;
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

            ~SharedGroupDataRecord() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["LastUpdated"], LastUpdated);
                FromJsonUtilS(input["LastUpdatedBy"], LastUpdatedBy);
                FromJsonUtilE(input["Permission"], Permission);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LastUpdated; ToJsonUtilT(LastUpdated, each_LastUpdated); output["LastUpdated"] = each_LastUpdated;
                Json::Value each_LastUpdatedBy; ToJsonUtilS(LastUpdatedBy, each_LastUpdatedBy); output["LastUpdatedBy"] = each_LastUpdatedBy;
                Json::Value each_Permission; ToJsonUtilE(Permission, each_Permission); output["Permission"] = each_Permission;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
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

            ~GetSharedGroupDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
                FromJsonUtilS(input["Members"], Members);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_Members; ToJsonUtilS(Members, each_Members); output["Members"] = each_Members;
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

            ~GetStoreItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["StoreId"], StoreId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output["StoreId"] = each_StoreId;
                return output;
            }
        };

        struct StoreMarketingModel : public PlayFabBaseModel
        {
            std::string Description;
            std::string DisplayName;
            Json::Value Metadata;

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

            ~StoreMarketingModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                Metadata = input["Metadata"];
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                output["Metadata"] = Metadata;
                return output;
            }
        };

        struct StoreItem : public PlayFabBaseModel
        {
            Json::Value CustomData;
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

            ~StoreItem() = default;

            void FromJson(Json::Value& input) override
            {
                CustomData = input["CustomData"];
                FromJsonUtilP(input["DisplayPosition"], DisplayPosition);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilP(input["RealCurrencyPrices"], RealCurrencyPrices);
                FromJsonUtilP(input["VirtualCurrencyPrices"], VirtualCurrencyPrices);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["CustomData"] = CustomData;
                Json::Value each_DisplayPosition; ToJsonUtilP(DisplayPosition, each_DisplayPosition); output["DisplayPosition"] = each_DisplayPosition;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output["RealCurrencyPrices"] = each_RealCurrencyPrices;
                Json::Value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output["VirtualCurrencyPrices"] = each_VirtualCurrencyPrices;
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

            ~GetStoreItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input["MarketingData"], MarketingData);
                FromJsonUtilE(input["Source"], Source);
                FromJsonUtilO(input["Store"], Store);
                FromJsonUtilS(input["StoreId"], StoreId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_MarketingData; ToJsonUtilO(MarketingData, each_MarketingData); output["MarketingData"] = each_MarketingData;
                Json::Value each_Source; ToJsonUtilE(Source, each_Source); output["Source"] = each_Source;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                Json::Value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output["StoreId"] = each_StoreId;
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

            ~GetTimeRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~GetTimeResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["Time"], Time);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Time; ToJsonUtilT(Time, each_Time); output["Time"] = each_Time;
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

            ~GetTitleDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Keys"], Keys);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Keys; ToJsonUtilS(Keys, each_Keys); output["Keys"] = each_Keys;
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

            ~GetTitleDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Data"], Data);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
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

            ~GetTitleNewsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Count"], Count);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
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

            ~TitleNewsItem() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Body"], Body);
                FromJsonUtilS(input["NewsId"], NewsId);
                FromJsonUtilT(input["Timestamp"], Timestamp);
                FromJsonUtilS(input["Title"], Title);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Body; ToJsonUtilS(Body, each_Body); output["Body"] = each_Body;
                Json::Value each_NewsId; ToJsonUtilS(NewsId, each_NewsId); output["NewsId"] = each_NewsId;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
                Json::Value each_Title; ToJsonUtilS(Title, each_Title); output["Title"] = each_Title;
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

            ~GetTitleNewsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["News"], News);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_News; ToJsonUtilO(News, each_News); output["News"] = each_News;
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

            ~GetTitlePublicKeyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilS(input["TitleSharedSecret"], TitleSharedSecret);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_TitleSharedSecret; ToJsonUtilS(TitleSharedSecret, each_TitleSharedSecret); output["TitleSharedSecret"] = each_TitleSharedSecret;
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

            ~GetTitlePublicKeyResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["RSAPublicKey"], RSAPublicKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_RSAPublicKey; ToJsonUtilS(RSAPublicKey, each_RSAPublicKey); output["RSAPublicKey"] = each_RSAPublicKey;
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

            ~GetTradeStatusRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OfferingPlayerId"], OfferingPlayerId);
                FromJsonUtilS(input["TradeId"], TradeId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output["OfferingPlayerId"] = each_OfferingPlayerId;
                Json::Value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output["TradeId"] = each_TradeId;
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

            ~GetTradeStatusResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Trade"], Trade);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Trade; ToJsonUtilO(Trade, each_Trade); output["Trade"] = each_Trade;
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

            ~GetUserDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["IfChangedFromDataVersion"], IfChangedFromDataVersion);
                FromJsonUtilS(input["Keys"], Keys);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IfChangedFromDataVersion; ToJsonUtilP(IfChangedFromDataVersion, each_IfChangedFromDataVersion); output["IfChangedFromDataVersion"] = each_IfChangedFromDataVersion;
                Json::Value each_Keys; ToJsonUtilS(Keys, each_Keys); output["Keys"] = each_Keys;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GetUserDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
                FromJsonUtilP(input["DataVersion"], DataVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output["DataVersion"] = each_DataVersion;
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

            ~GetUserInventoryRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~GetUserInventoryResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Inventory"], Inventory);
                FromJsonUtilP(input["VirtualCurrency"], VirtualCurrency);
                FromJsonUtilO(input["VirtualCurrencyRechargeTimes"], VirtualCurrencyRechargeTimes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output["Inventory"] = each_Inventory;
                Json::Value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
                Json::Value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output["VirtualCurrencyRechargeTimes"] = each_VirtualCurrencyRechargeTimes;
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

            ~GetWindowsHelloChallengeRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PublicKeyHint"], PublicKeyHint);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output["PublicKeyHint"] = each_PublicKeyHint;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~GetWindowsHelloChallengeResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Challenge"], Challenge);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Challenge; ToJsonUtilS(Challenge, each_Challenge); output["Challenge"] = each_Challenge;
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

            ~GrantCharacterToUserRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CharacterName"], CharacterName);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output["CharacterName"] = each_CharacterName;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
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

            ~GrantCharacterToUserResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["CharacterType"], CharacterType);
                FromJsonUtilP(input["Result"], Result);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output["CharacterType"] = each_CharacterType;
                Json::Value each_Result; ToJsonUtilP(Result, each_Result); output["Result"] = each_Result;
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

            ~ItemPurchaseRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Annotation"], Annotation);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilP(input["Quantity"], Quantity);
                FromJsonUtilS(input["UpgradeFromItems"], UpgradeFromItems);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output["Annotation"] = each_Annotation;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Quantity; ToJsonUtilP(Quantity, each_Quantity); output["Quantity"] = each_Quantity;
                Json::Value each_UpgradeFromItems; ToJsonUtilS(UpgradeFromItems, each_UpgradeFromItems); output["UpgradeFromItems"] = each_UpgradeFromItems;
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

            ~LinkAndroidDeviceIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AndroidDevice"], AndroidDevice);
                FromJsonUtilS(input["AndroidDeviceId"], AndroidDeviceId);
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["OS"], OS);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AndroidDevice; ToJsonUtilS(AndroidDevice, each_AndroidDevice); output["AndroidDevice"] = each_AndroidDevice;
                Json::Value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output["AndroidDeviceId"] = each_AndroidDeviceId;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_OS; ToJsonUtilS(OS, each_OS); output["OS"] = each_OS;
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

            ~LinkAndroidDeviceIDResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkCustomIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CustomId"], CustomId);
                FromJsonUtilP(input["ForceLink"], ForceLink);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output["CustomId"] = each_CustomId;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
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

            ~LinkCustomIDResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkFacebookAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AccessToken"], AccessToken);
                FromJsonUtilP(input["ForceLink"], ForceLink);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output["AccessToken"] = each_AccessToken;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
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

            ~LinkFacebookAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkFacebookInstantGamesIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FacebookInstantGamesSignature"], FacebookInstantGamesSignature);
                FromJsonUtilP(input["ForceLink"], ForceLink);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FacebookInstantGamesSignature; ToJsonUtilS(FacebookInstantGamesSignature, each_FacebookInstantGamesSignature); output["FacebookInstantGamesSignature"] = each_FacebookInstantGamesSignature;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
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

            ~LinkFacebookInstantGamesIdResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkGameCenterAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["GameCenterId"], GameCenterId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output["GameCenterId"] = each_GameCenterId;
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

            ~LinkGameCenterAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkGoogleAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["ServerAuthCode"], ServerAuthCode);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_ServerAuthCode; ToJsonUtilS(ServerAuthCode, each_ServerAuthCode); output["ServerAuthCode"] = each_ServerAuthCode;
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

            ~LinkGoogleAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkIOSDeviceIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DeviceId"], DeviceId);
                FromJsonUtilS(input["DeviceModel"], DeviceModel);
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["OS"], OS);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output["DeviceId"] = each_DeviceId;
                Json::Value each_DeviceModel; ToJsonUtilS(DeviceModel, each_DeviceModel); output["DeviceModel"] = each_DeviceModel;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_OS; ToJsonUtilS(OS, each_OS); output["OS"] = each_OS;
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

            ~LinkIOSDeviceIDResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkKongregateAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AuthTicket"], AuthTicket);
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["KongregateId"], KongregateId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AuthTicket; ToJsonUtilS(AuthTicket, each_AuthTicket); output["AuthTicket"] = each_AuthTicket;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output["KongregateId"] = each_KongregateId;
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

            ~LinkKongregateAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkNintendoSwitchDeviceIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output["NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
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

            ~LinkNintendoSwitchDeviceIdResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct LinkOpenIdConnectRequest : public PlayFabRequestCommon
        {
            std::string ConnectionId;
            Boxed<bool> ForceLink;
            std::string IdToken;

            LinkOpenIdConnectRequest() :
                PlayFabRequestCommon(),
                ConnectionId(),
                ForceLink(),
                IdToken()
            {}

            LinkOpenIdConnectRequest(const LinkOpenIdConnectRequest& src) :
                PlayFabRequestCommon(),
                ConnectionId(src.ConnectionId),
                ForceLink(src.ForceLink),
                IdToken(src.IdToken)
            {}

            ~LinkOpenIdConnectRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionId"], ConnectionId);
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["IdToken"], IdToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionId; ToJsonUtilS(ConnectionId, each_ConnectionId); output["ConnectionId"] = each_ConnectionId;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_IdToken; ToJsonUtilS(IdToken, each_IdToken); output["IdToken"] = each_IdToken;
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

            ~LinkSteamAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["SteamTicket"], SteamTicket);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_SteamTicket; ToJsonUtilS(SteamTicket, each_SteamTicket); output["SteamTicket"] = each_SteamTicket;
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

            ~LinkSteamAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkTwitchAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AccessToken"], AccessToken);
                FromJsonUtilP(input["ForceLink"], ForceLink);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output["AccessToken"] = each_AccessToken;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
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

            ~LinkTwitchAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkWindowsHelloAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DeviceName"], DeviceName);
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["PublicKey"], PublicKey);
                FromJsonUtilS(input["UserName"], UserName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DeviceName; ToJsonUtilS(DeviceName, each_DeviceName); output["DeviceName"] = each_DeviceName;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_PublicKey; ToJsonUtilS(PublicKey, each_PublicKey); output["PublicKey"] = each_PublicKey;
                Json::Value each_UserName; ToJsonUtilS(UserName, each_UserName); output["UserName"] = each_UserName;
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

            ~LinkWindowsHelloAccountResponse() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~LinkXboxAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ForceLink"], ForceLink);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output["ForceLink"] = each_ForceLink;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
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

            ~LinkXboxAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ListUsersCharactersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~ListUsersCharactersResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Characters"], Characters);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Characters; ToJsonUtilO(Characters, each_Characters); output["Characters"] = each_Characters;
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

            ~UserSettings() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["GatherDeviceInfo"], GatherDeviceInfo);
                FromJsonUtilP(input["GatherFocusInfo"], GatherFocusInfo);
                FromJsonUtilP(input["NeedsAttribution"], NeedsAttribution);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GatherDeviceInfo; ToJsonUtilP(GatherDeviceInfo, each_GatherDeviceInfo); output["GatherDeviceInfo"] = each_GatherDeviceInfo;
                Json::Value each_GatherFocusInfo; ToJsonUtilP(GatherFocusInfo, each_GatherFocusInfo); output["GatherFocusInfo"] = each_GatherFocusInfo;
                Json::Value each_NeedsAttribution; ToJsonUtilP(NeedsAttribution, each_NeedsAttribution); output["NeedsAttribution"] = each_NeedsAttribution;
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

            ~LoginResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["EntityToken"], EntityToken);
                FromJsonUtilO(input["InfoResultPayload"], InfoResultPayload);
                FromJsonUtilT(input["LastLoginTime"], LastLoginTime);
                FromJsonUtilP(input["NewlyCreated"], NewlyCreated);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["SessionTicket"], SessionTicket);
                FromJsonUtilO(input["SettingsForUser"], SettingsForUser);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EntityToken; ToJsonUtilO(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                Json::Value each_InfoResultPayload; ToJsonUtilO(InfoResultPayload, each_InfoResultPayload); output["InfoResultPayload"] = each_InfoResultPayload;
                Json::Value each_LastLoginTime; ToJsonUtilT(LastLoginTime, each_LastLoginTime); output["LastLoginTime"] = each_LastLoginTime;
                Json::Value each_NewlyCreated; ToJsonUtilP(NewlyCreated, each_NewlyCreated); output["NewlyCreated"] = each_NewlyCreated;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_SessionTicket; ToJsonUtilS(SessionTicket, each_SessionTicket); output["SessionTicket"] = each_SessionTicket;
                Json::Value each_SettingsForUser; ToJsonUtilO(SettingsForUser, each_SettingsForUser); output["SettingsForUser"] = each_SettingsForUser;
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

            ~LoginWithAndroidDeviceIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AndroidDevice"], AndroidDevice);
                FromJsonUtilS(input["AndroidDeviceId"], AndroidDeviceId);
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["OS"], OS);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AndroidDevice; ToJsonUtilS(AndroidDevice, each_AndroidDevice); output["AndroidDevice"] = each_AndroidDevice;
                Json::Value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output["AndroidDeviceId"] = each_AndroidDeviceId;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_OS; ToJsonUtilS(OS, each_OS); output["OS"] = each_OS;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithCustomIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["CustomId"], CustomId);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output["CustomId"] = each_CustomId;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithEmailAddressRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Email"], Email);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Email; ToJsonUtilS(Email, each_Email); output["Email"] = each_Email;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithFacebookInstantGamesIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilS(input["FacebookInstantGamesSignature"], FacebookInstantGamesSignature);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_FacebookInstantGamesSignature; ToJsonUtilS(FacebookInstantGamesSignature, each_FacebookInstantGamesSignature); output["FacebookInstantGamesSignature"] = each_FacebookInstantGamesSignature;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithFacebookRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AccessToken"], AccessToken);
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output["AccessToken"] = each_AccessToken;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithGameCenterRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerId"], PlayerId);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output["PlayerId"] = each_PlayerId;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithGoogleAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["ServerAuthCode"], ServerAuthCode);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_ServerAuthCode; ToJsonUtilS(ServerAuthCode, each_ServerAuthCode); output["ServerAuthCode"] = each_ServerAuthCode;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithIOSDeviceIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["DeviceId"], DeviceId);
                FromJsonUtilS(input["DeviceModel"], DeviceModel);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["OS"], OS);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output["DeviceId"] = each_DeviceId;
                Json::Value each_DeviceModel; ToJsonUtilS(DeviceModel, each_DeviceModel); output["DeviceModel"] = each_DeviceModel;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_OS; ToJsonUtilS(OS, each_OS); output["OS"] = each_OS;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithKongregateRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AuthTicket"], AuthTicket);
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilS(input["KongregateId"], KongregateId);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AuthTicket; ToJsonUtilS(AuthTicket, each_AuthTicket); output["AuthTicket"] = each_AuthTicket;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output["KongregateId"] = each_KongregateId;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithNintendoSwitchDeviceIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output["NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                return output;
            }
        };

        struct LoginWithOpenIdConnectRequest : public PlayFabRequestCommon
        {
            std::string ConnectionId;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            std::string IdToken;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithOpenIdConnectRequest() :
                PlayFabRequestCommon(),
                ConnectionId(),
                CreateAccount(),
                EncryptedRequest(),
                IdToken(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithOpenIdConnectRequest(const LoginWithOpenIdConnectRequest& src) :
                PlayFabRequestCommon(),
                ConnectionId(src.ConnectionId),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                IdToken(src.IdToken),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithOpenIdConnectRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionId"], ConnectionId);
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilS(input["IdToken"], IdToken);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionId; ToJsonUtilS(ConnectionId, each_ConnectionId); output["ConnectionId"] = each_ConnectionId;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_IdToken; ToJsonUtilS(IdToken, each_IdToken); output["IdToken"] = each_IdToken;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithPlayFabRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
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

            ~LoginWithSteamRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["SteamTicket"], SteamTicket);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_SteamTicket; ToJsonUtilS(SteamTicket, each_SteamTicket); output["SteamTicket"] = each_SteamTicket;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithTwitchRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AccessToken"], AccessToken);
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output["AccessToken"] = each_AccessToken;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithWindowsHelloRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ChallengeSignature"], ChallengeSignature);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PublicKeyHint"], PublicKeyHint);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChallengeSignature; ToJsonUtilS(ChallengeSignature, each_ChallengeSignature); output["ChallengeSignature"] = each_ChallengeSignature;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output["PublicKeyHint"] = each_PublicKeyHint;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~LoginWithXboxRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreateAccount"], CreateAccount);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output["CreateAccount"] = each_CreateAccount;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
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

            ~MatchmakeRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildVersion"], BuildVersion);
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["GameMode"], GameMode);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilE(input["pfRegion"], pfRegion);
                FromJsonUtilP(input["StartNewIfNoneFound"], StartNewIfNoneFound);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilO(input["TagFilter"], TagFilter);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output["BuildVersion"] = each_BuildVersion;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output["GameMode"] = each_GameMode;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output["Region"] = each_pfRegion;
                Json::Value each_StartNewIfNoneFound; ToJsonUtilP(StartNewIfNoneFound, each_StartNewIfNoneFound); output["StartNewIfNoneFound"] = each_StartNewIfNoneFound;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_TagFilter; ToJsonUtilO(TagFilter, each_TagFilter); output["TagFilter"] = each_TagFilter;
                return output;
            }
        };

        struct MatchmakeResult : public PlayFabResultCommon
        {
            std::string Expires;
            std::string LobbyID;
            Boxed<Int32> PollWaitTimeMS;
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
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                Status(src.Status),
                Ticket(src.Ticket)
            {}

            ~MatchmakeResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Expires"], Expires);
                FromJsonUtilS(input["LobbyID"], LobbyID);
                FromJsonUtilP(input["PollWaitTimeMS"], PollWaitTimeMS);
                FromJsonUtilS(input["ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input["ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input["ServerPort"], ServerPort);
                FromJsonUtilS(input["ServerPublicDNSName"], ServerPublicDNSName);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilS(input["Ticket"], Ticket);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Expires; ToJsonUtilS(Expires, each_Expires); output["Expires"] = each_Expires;
                Json::Value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output["LobbyID"] = each_LobbyID;
                Json::Value each_PollWaitTimeMS; ToJsonUtilP(PollWaitTimeMS, each_PollWaitTimeMS); output["PollWaitTimeMS"] = each_PollWaitTimeMS;
                Json::Value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output["ServerIPV4Address"] = each_ServerIPV4Address;
                Json::Value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output["ServerIPV6Address"] = each_ServerIPV6Address;
                Json::Value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output["ServerPort"] = each_ServerPort;
                Json::Value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output["ServerPublicDNSName"] = each_ServerPublicDNSName;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_Ticket; ToJsonUtilS(Ticket, each_Ticket); output["Ticket"] = each_Ticket;
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

            ~ModifyUserVirtualCurrencyResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Balance"], Balance);
                FromJsonUtilP(input["BalanceChange"], BalanceChange);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["VirtualCurrency"], VirtualCurrency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Balance; ToJsonUtilP(Balance, each_Balance); output["Balance"] = each_Balance;
                Json::Value each_BalanceChange; ToJsonUtilP(BalanceChange, each_BalanceChange); output["BalanceChange"] = each_BalanceChange;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
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

            ~OpenTradeRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AllowedPlayerIds"], AllowedPlayerIds);
                FromJsonUtilS(input["OfferedInventoryInstanceIds"], OfferedInventoryInstanceIds);
                FromJsonUtilS(input["RequestedCatalogItemIds"], RequestedCatalogItemIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AllowedPlayerIds; ToJsonUtilS(AllowedPlayerIds, each_AllowedPlayerIds); output["AllowedPlayerIds"] = each_AllowedPlayerIds;
                Json::Value each_OfferedInventoryInstanceIds; ToJsonUtilS(OfferedInventoryInstanceIds, each_OfferedInventoryInstanceIds); output["OfferedInventoryInstanceIds"] = each_OfferedInventoryInstanceIds;
                Json::Value each_RequestedCatalogItemIds; ToJsonUtilS(RequestedCatalogItemIds, each_RequestedCatalogItemIds); output["RequestedCatalogItemIds"] = each_RequestedCatalogItemIds;
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

            ~OpenTradeResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Trade"], Trade);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Trade; ToJsonUtilO(Trade, each_Trade); output["Trade"] = each_Trade;
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

            ~PayForPurchaseRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Currency"], Currency);
                FromJsonUtilS(input["OrderId"], OrderId);
                FromJsonUtilS(input["ProviderName"], ProviderName);
                FromJsonUtilS(input["ProviderTransactionId"], ProviderTransactionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currency; ToJsonUtilS(Currency, each_Currency); output["Currency"] = each_Currency;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
                Json::Value each_ProviderName; ToJsonUtilS(ProviderName, each_ProviderName); output["ProviderName"] = each_ProviderName;
                Json::Value each_ProviderTransactionId; ToJsonUtilS(ProviderTransactionId, each_ProviderTransactionId); output["ProviderTransactionId"] = each_ProviderTransactionId;
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

            ~PayForPurchaseResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["CreditApplied"], CreditApplied);
                FromJsonUtilS(input["OrderId"], OrderId);
                FromJsonUtilS(input["ProviderData"], ProviderData);
                FromJsonUtilS(input["ProviderToken"], ProviderToken);
                FromJsonUtilS(input["PurchaseConfirmationPageURL"], PurchaseConfirmationPageURL);
                FromJsonUtilS(input["PurchaseCurrency"], PurchaseCurrency);
                FromJsonUtilP(input["PurchasePrice"], PurchasePrice);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilP(input["VCAmount"], VCAmount);
                FromJsonUtilP(input["VirtualCurrency"], VirtualCurrency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreditApplied; ToJsonUtilP(CreditApplied, each_CreditApplied); output["CreditApplied"] = each_CreditApplied;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
                Json::Value each_ProviderData; ToJsonUtilS(ProviderData, each_ProviderData); output["ProviderData"] = each_ProviderData;
                Json::Value each_ProviderToken; ToJsonUtilS(ProviderToken, each_ProviderToken); output["ProviderToken"] = each_ProviderToken;
                Json::Value each_PurchaseConfirmationPageURL; ToJsonUtilS(PurchaseConfirmationPageURL, each_PurchaseConfirmationPageURL); output["PurchaseConfirmationPageURL"] = each_PurchaseConfirmationPageURL;
                Json::Value each_PurchaseCurrency; ToJsonUtilS(PurchaseCurrency, each_PurchaseCurrency); output["PurchaseCurrency"] = each_PurchaseCurrency;
                Json::Value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output["PurchasePrice"] = each_PurchasePrice;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_VCAmount; ToJsonUtilP(VCAmount, each_VCAmount); output["VCAmount"] = each_VCAmount;
                Json::Value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
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

            ~PaymentOption() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Currency"], Currency);
                FromJsonUtilP(input["Price"], Price);
                FromJsonUtilS(input["ProviderName"], ProviderName);
                FromJsonUtilP(input["StoreCredit"], StoreCredit);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currency; ToJsonUtilS(Currency, each_Currency); output["Currency"] = each_Currency;
                Json::Value each_Price; ToJsonUtilP(Price, each_Price); output["Price"] = each_Price;
                Json::Value each_ProviderName; ToJsonUtilS(ProviderName, each_ProviderName); output["ProviderName"] = each_ProviderName;
                Json::Value each_StoreCredit; ToJsonUtilP(StoreCredit, each_StoreCredit); output["StoreCredit"] = each_StoreCredit;
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

            ~PurchaseItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilP(input["Price"], Price);
                FromJsonUtilS(input["StoreId"], StoreId);
                FromJsonUtilS(input["VirtualCurrency"], VirtualCurrency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Price; ToJsonUtilP(Price, each_Price); output["Price"] = each_Price;
                Json::Value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output["StoreId"] = each_StoreId;
                Json::Value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
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

            ~PurchaseItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
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

            ~RedeemCouponRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["CouponCode"], CouponCode);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_CouponCode; ToJsonUtilS(CouponCode, each_CouponCode); output["CouponCode"] = each_CouponCode;
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

            ~RedeemCouponResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["GrantedItems"], GrantedItems);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GrantedItems; ToJsonUtilO(GrantedItems, each_GrantedItems); output["GrantedItems"] = each_GrantedItems;
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

            ~RegisterForIOSPushNotificationRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ConfirmationMessage"], ConfirmationMessage);
                FromJsonUtilS(input["DeviceToken"], DeviceToken);
                FromJsonUtilP(input["SendPushNotificationConfirmation"], SendPushNotificationConfirmation);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConfirmationMessage; ToJsonUtilS(ConfirmationMessage, each_ConfirmationMessage); output["ConfirmationMessage"] = each_ConfirmationMessage;
                Json::Value each_DeviceToken; ToJsonUtilS(DeviceToken, each_DeviceToken); output["DeviceToken"] = each_DeviceToken;
                Json::Value each_SendPushNotificationConfirmation; ToJsonUtilP(SendPushNotificationConfirmation, each_SendPushNotificationConfirmation); output["SendPushNotificationConfirmation"] = each_SendPushNotificationConfirmation;
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

            ~RegisterForIOSPushNotificationResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~RegisterPlayFabUserRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilS(input["Email"], Email);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilP(input["RequireBothUsernameAndEmail"], RequireBothUsernameAndEmail);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_Email; ToJsonUtilS(Email, each_Email); output["Email"] = each_Email;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_RequireBothUsernameAndEmail; ToJsonUtilP(RequireBothUsernameAndEmail, each_RequireBothUsernameAndEmail); output["RequireBothUsernameAndEmail"] = each_RequireBothUsernameAndEmail;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
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

            ~RegisterPlayFabUserResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["EntityToken"], EntityToken);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["SessionTicket"], SessionTicket);
                FromJsonUtilO(input["SettingsForUser"], SettingsForUser);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EntityToken; ToJsonUtilO(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_SessionTicket; ToJsonUtilS(SessionTicket, each_SessionTicket); output["SessionTicket"] = each_SessionTicket;
                Json::Value each_SettingsForUser; ToJsonUtilO(SettingsForUser, each_SettingsForUser); output["SettingsForUser"] = each_SettingsForUser;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
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

            ~RegisterWithWindowsHelloRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DeviceName"], DeviceName);
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilO(input["InfoRequestParameters"], InfoRequestParameters);
                FromJsonUtilP(input["LoginTitlePlayerAccountEntity"], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["PublicKey"], PublicKey);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilS(input["UserName"], UserName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DeviceName; ToJsonUtilS(DeviceName, each_DeviceName); output["DeviceName"] = each_DeviceName;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output["InfoRequestParameters"] = each_InfoRequestParameters;
                Json::Value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output["LoginTitlePlayerAccountEntity"] = each_LoginTitlePlayerAccountEntity;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_PublicKey; ToJsonUtilS(PublicKey, each_PublicKey); output["PublicKey"] = each_PublicKey;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_UserName; ToJsonUtilS(UserName, each_UserName); output["UserName"] = each_UserName;
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

            ~RemoveContactEmailRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~RemoveContactEmailResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~RemoveFriendRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FriendPlayFabId"], FriendPlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output["FriendPlayFabId"] = each_FriendPlayFabId;
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

            ~RemoveFriendResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~RemoveGenericIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["GenericId"], GenericId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output["GenericId"] = each_GenericId;
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

            ~RemoveGenericIDResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~RemoveSharedGroupMembersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabIds"], PlayFabIds);
                FromJsonUtilS(input["SharedGroupId"], SharedGroupId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabIds; ToJsonUtilS(PlayFabIds, each_PlayFabIds); output["PlayFabIds"] = each_PlayFabIds;
                Json::Value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output["SharedGroupId"] = each_SharedGroupId;
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

            ~RemoveSharedGroupMembersResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ReportPlayerClientRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Comment"], Comment);
                FromJsonUtilS(input["ReporteeId"], ReporteeId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Comment; ToJsonUtilS(Comment, each_Comment); output["Comment"] = each_Comment;
                Json::Value each_ReporteeId; ToJsonUtilS(ReporteeId, each_ReporteeId); output["ReporteeId"] = each_ReporteeId;
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

            ~ReportPlayerClientResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["SubmissionsRemaining"], SubmissionsRemaining);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_SubmissionsRemaining; ToJsonUtilP(SubmissionsRemaining, each_SubmissionsRemaining); output["SubmissionsRemaining"] = each_SubmissionsRemaining;
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

            ~RestoreIOSPurchasesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ReceiptData"], ReceiptData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ReceiptData; ToJsonUtilS(ReceiptData, each_ReceiptData); output["ReceiptData"] = each_ReceiptData;
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

            ~RestoreIOSPurchasesResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~SendAccountRecoveryEmailRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Email"], Email);
                FromJsonUtilS(input["EmailTemplateId"], EmailTemplateId);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Email; ToJsonUtilS(Email, each_Email); output["Email"] = each_Email;
                Json::Value each_EmailTemplateId; ToJsonUtilS(EmailTemplateId, each_EmailTemplateId); output["EmailTemplateId"] = each_EmailTemplateId;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~SendAccountRecoveryEmailResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~SetFriendTagsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FriendPlayFabId"], FriendPlayFabId);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output["FriendPlayFabId"] = each_FriendPlayFabId;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
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

            ~SetFriendTagsResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~SetPlayerSecretRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["EncryptedRequest"], EncryptedRequest);
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output["EncryptedRequest"] = each_EncryptedRequest;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
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

            ~SetPlayerSecretResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~StartGameRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildVersion"], BuildVersion);
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["CustomCommandLineData"], CustomCommandLineData);
                FromJsonUtilS(input["GameMode"], GameMode);
                FromJsonEnum(input["pfRegion"], pfRegion);
                FromJsonUtilS(input["StatisticName"], StatisticName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output["BuildVersion"] = each_BuildVersion;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_CustomCommandLineData; ToJsonUtilS(CustomCommandLineData, each_CustomCommandLineData); output["CustomCommandLineData"] = each_CustomCommandLineData;
                Json::Value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output["GameMode"] = each_GameMode;
                Json::Value each_pfRegion; ToJsonEnum(pfRegion, each_pfRegion); output["Region"] = each_pfRegion;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                return output;
            }
        };

        struct StartGameResult : public PlayFabResultCommon
        {
            std::string Expires;
            std::string LobbyID;
            std::string Password;
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
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                Ticket(src.Ticket)
            {}

            ~StartGameResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Expires"], Expires);
                FromJsonUtilS(input["LobbyID"], LobbyID);
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input["ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input["ServerPort"], ServerPort);
                FromJsonUtilS(input["ServerPublicDNSName"], ServerPublicDNSName);
                FromJsonUtilS(input["Ticket"], Ticket);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Expires; ToJsonUtilS(Expires, each_Expires); output["Expires"] = each_Expires;
                Json::Value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output["LobbyID"] = each_LobbyID;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output["ServerIPV4Address"] = each_ServerIPV4Address;
                Json::Value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output["ServerIPV6Address"] = each_ServerIPV6Address;
                Json::Value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output["ServerPort"] = each_ServerPort;
                Json::Value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output["ServerPublicDNSName"] = each_ServerPublicDNSName;
                Json::Value each_Ticket; ToJsonUtilS(Ticket, each_Ticket); output["Ticket"] = each_Ticket;
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

            ~StartPurchaseRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input["Items"], Items);
                FromJsonUtilS(input["StoreId"], StoreId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                Json::Value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output["StoreId"] = each_StoreId;
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

            ~StartPurchaseResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Contents"], Contents);
                FromJsonUtilS(input["OrderId"], OrderId);
                FromJsonUtilO(input["PaymentOptions"], PaymentOptions);
                FromJsonUtilP(input["VirtualCurrencyBalances"], VirtualCurrencyBalances);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Contents; ToJsonUtilO(Contents, each_Contents); output["Contents"] = each_Contents;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
                Json::Value each_PaymentOptions; ToJsonUtilO(PaymentOptions, each_PaymentOptions); output["PaymentOptions"] = each_PaymentOptions;
                Json::Value each_VirtualCurrencyBalances; ToJsonUtilP(VirtualCurrencyBalances, each_VirtualCurrencyBalances); output["VirtualCurrencyBalances"] = each_VirtualCurrencyBalances;
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

            ~StatisticUpdate() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["Value"], Value);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Value; ToJsonUtilP(Value, each_Value); output["Value"] = each_Value;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~SubtractUserVirtualCurrencyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["VirtualCurrency"], VirtualCurrency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
                return output;
            }
        };

        struct UninkOpenIdConnectRequest : public PlayFabRequestCommon
        {
            std::string ConnectionId;

            UninkOpenIdConnectRequest() :
                PlayFabRequestCommon(),
                ConnectionId()
            {}

            UninkOpenIdConnectRequest(const UninkOpenIdConnectRequest& src) :
                PlayFabRequestCommon(),
                ConnectionId(src.ConnectionId)
            {}

            ~UninkOpenIdConnectRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionId"], ConnectionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionId; ToJsonUtilS(ConnectionId, each_ConnectionId); output["ConnectionId"] = each_ConnectionId;
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

            ~UnlinkAndroidDeviceIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AndroidDeviceId"], AndroidDeviceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output["AndroidDeviceId"] = each_AndroidDeviceId;
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

            ~UnlinkAndroidDeviceIDResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkCustomIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CustomId"], CustomId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output["CustomId"] = each_CustomId;
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

            ~UnlinkCustomIDResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkFacebookAccountRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkFacebookAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkFacebookInstantGamesIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FacebookInstantGamesId"], FacebookInstantGamesId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FacebookInstantGamesId; ToJsonUtilS(FacebookInstantGamesId, each_FacebookInstantGamesId); output["FacebookInstantGamesId"] = each_FacebookInstantGamesId;
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

            ~UnlinkFacebookInstantGamesIdResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkGameCenterAccountRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkGameCenterAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkGoogleAccountRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkGoogleAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkIOSDeviceIDRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DeviceId"], DeviceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output["DeviceId"] = each_DeviceId;
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

            ~UnlinkIOSDeviceIDResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkKongregateAccountRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkKongregateAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkNintendoSwitchDeviceIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["NintendoSwitchDeviceId"], NintendoSwitchDeviceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NintendoSwitchDeviceId; ToJsonUtilS(NintendoSwitchDeviceId, each_NintendoSwitchDeviceId); output["NintendoSwitchDeviceId"] = each_NintendoSwitchDeviceId;
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

            ~UnlinkNintendoSwitchDeviceIdResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkSteamAccountRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkSteamAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkTwitchAccountRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkTwitchAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkWindowsHelloAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PublicKeyHint"], PublicKeyHint);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output["PublicKeyHint"] = each_PublicKeyHint;
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

            ~UnlinkWindowsHelloAccountResponse() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlinkXboxAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
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

            ~UnlinkXboxAccountResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UnlockContainerInstanceRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["ContainerItemInstanceId"], ContainerItemInstanceId);
                FromJsonUtilS(input["KeyItemInstanceId"], KeyItemInstanceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_ContainerItemInstanceId; ToJsonUtilS(ContainerItemInstanceId, each_ContainerItemInstanceId); output["ContainerItemInstanceId"] = each_ContainerItemInstanceId;
                Json::Value each_KeyItemInstanceId; ToJsonUtilS(KeyItemInstanceId, each_KeyItemInstanceId); output["KeyItemInstanceId"] = each_KeyItemInstanceId;
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

            ~UnlockContainerItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["ContainerItemId"], ContainerItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_ContainerItemId; ToJsonUtilS(ContainerItemId, each_ContainerItemId); output["ContainerItemId"] = each_ContainerItemId;
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

            ~UnlockContainerItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["GrantedItems"], GrantedItems);
                FromJsonUtilS(input["UnlockedItemInstanceId"], UnlockedItemInstanceId);
                FromJsonUtilS(input["UnlockedWithItemInstanceId"], UnlockedWithItemInstanceId);
                FromJsonUtilP(input["VirtualCurrency"], VirtualCurrency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GrantedItems; ToJsonUtilO(GrantedItems, each_GrantedItems); output["GrantedItems"] = each_GrantedItems;
                Json::Value each_UnlockedItemInstanceId; ToJsonUtilS(UnlockedItemInstanceId, each_UnlockedItemInstanceId); output["UnlockedItemInstanceId"] = each_UnlockedItemInstanceId;
                Json::Value each_UnlockedWithItemInstanceId; ToJsonUtilS(UnlockedWithItemInstanceId, each_UnlockedWithItemInstanceId); output["UnlockedWithItemInstanceId"] = each_UnlockedWithItemInstanceId;
                Json::Value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
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

            ~UpdateAvatarUrlRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ImageUrl"], ImageUrl);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ImageUrl; ToJsonUtilS(ImageUrl, each_ImageUrl); output["ImageUrl"] = each_ImageUrl;
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

            ~UpdateCharacterDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["Data"], Data);
                FromJsonUtilS(input["KeysToRemove"], KeysToRemove);
                FromJsonUtilE(input["Permission"], Permission);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output["KeysToRemove"] = each_KeysToRemove;
                Json::Value each_Permission; ToJsonUtilE(Permission, each_Permission); output["Permission"] = each_Permission;
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

            ~UpdateCharacterDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["DataVersion"], DataVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output["DataVersion"] = each_DataVersion;
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

            ~UpdateCharacterStatisticsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilP(input["CharacterStatistics"], CharacterStatistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_CharacterStatistics; ToJsonUtilP(CharacterStatistics, each_CharacterStatistics); output["CharacterStatistics"] = each_CharacterStatistics;
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

            ~UpdateCharacterStatisticsResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UpdatePlayerStatisticsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
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

            ~UpdatePlayerStatisticsResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UpdateSharedGroupDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Data"], Data);
                FromJsonUtilS(input["KeysToRemove"], KeysToRemove);
                FromJsonUtilE(input["Permission"], Permission);
                FromJsonUtilS(input["SharedGroupId"], SharedGroupId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output["KeysToRemove"] = each_KeysToRemove;
                Json::Value each_Permission; ToJsonUtilE(Permission, each_Permission); output["Permission"] = each_Permission;
                Json::Value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output["SharedGroupId"] = each_SharedGroupId;
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

            ~UpdateSharedGroupDataResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UpdateUserDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Data"], Data);
                FromJsonUtilS(input["KeysToRemove"], KeysToRemove);
                FromJsonUtilE(input["Permission"], Permission);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output["KeysToRemove"] = each_KeysToRemove;
                Json::Value each_Permission; ToJsonUtilE(Permission, each_Permission); output["Permission"] = each_Permission;
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

            ~UpdateUserDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["DataVersion"], DataVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output["DataVersion"] = each_DataVersion;
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

            ~UpdateUserTitleDisplayNameRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DisplayName"], DisplayName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
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

            ~UpdateUserTitleDisplayNameResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DisplayName"], DisplayName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
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

            ~ValidateAmazonReceiptRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CurrencyCode"], CurrencyCode);
                FromJsonUtilP(input["PurchasePrice"], PurchasePrice);
                FromJsonUtilS(input["ReceiptId"], ReceiptId);
                FromJsonUtilS(input["UserId"], UserId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output["CurrencyCode"] = each_CurrencyCode;
                Json::Value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output["PurchasePrice"] = each_PurchasePrice;
                Json::Value each_ReceiptId; ToJsonUtilS(ReceiptId, each_ReceiptId); output["ReceiptId"] = each_ReceiptId;
                Json::Value each_UserId; ToJsonUtilS(UserId, each_UserId); output["UserId"] = each_UserId;
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

            ~ValidateAmazonReceiptResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ValidateGooglePlayPurchaseRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CurrencyCode"], CurrencyCode);
                FromJsonUtilP(input["PurchasePrice"], PurchasePrice);
                FromJsonUtilS(input["ReceiptJson"], ReceiptJson);
                FromJsonUtilS(input["Signature"], Signature);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output["CurrencyCode"] = each_CurrencyCode;
                Json::Value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output["PurchasePrice"] = each_PurchasePrice;
                Json::Value each_ReceiptJson; ToJsonUtilS(ReceiptJson, each_ReceiptJson); output["ReceiptJson"] = each_ReceiptJson;
                Json::Value each_Signature; ToJsonUtilS(Signature, each_Signature); output["Signature"] = each_Signature;
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

            ~ValidateGooglePlayPurchaseResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ValidateIOSReceiptRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CurrencyCode"], CurrencyCode);
                FromJsonUtilP(input["PurchasePrice"], PurchasePrice);
                FromJsonUtilS(input["ReceiptData"], ReceiptData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output["CurrencyCode"] = each_CurrencyCode;
                Json::Value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output["PurchasePrice"] = each_PurchasePrice;
                Json::Value each_ReceiptData; ToJsonUtilS(ReceiptData, each_ReceiptData); output["ReceiptData"] = each_ReceiptData;
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

            ~ValidateIOSReceiptResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ValidateWindowsReceiptRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CurrencyCode"], CurrencyCode);
                FromJsonUtilP(input["PurchasePrice"], PurchasePrice);
                FromJsonUtilS(input["Receipt"], Receipt);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output["CurrencyCode"] = each_CurrencyCode;
                Json::Value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output["PurchasePrice"] = each_PurchasePrice;
                Json::Value each_Receipt; ToJsonUtilS(Receipt, each_Receipt); output["Receipt"] = each_Receipt;
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

            ~ValidateWindowsReceiptResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct WriteClientCharacterEventRequest : public PlayFabRequestCommon
        {
            Json::Value Body; // Not truly arbitrary. See documentation for restrictions on format
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

            ~WriteClientCharacterEventRequest() = default;

            void FromJson(Json::Value& input) override
            {
                Body = input["Body"];
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["EventName"], EventName);
                FromJsonUtilT(input["Timestamp"], Timestamp);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["Body"] = Body;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_EventName; ToJsonUtilS(EventName, each_EventName); output["EventName"] = each_EventName;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
                return output;
            }
        };

        struct WriteClientPlayerEventRequest : public PlayFabRequestCommon
        {
            Json::Value Body; // Not truly arbitrary. See documentation for restrictions on format
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

            ~WriteClientPlayerEventRequest() = default;

            void FromJson(Json::Value& input) override
            {
                Body = input["Body"];
                FromJsonUtilS(input["EventName"], EventName);
                FromJsonUtilT(input["Timestamp"], Timestamp);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["Body"] = Body;
                Json::Value each_EventName; ToJsonUtilS(EventName, each_EventName); output["EventName"] = each_EventName;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
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

            ~WriteEventResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["EventId"], EventId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EventId; ToJsonUtilS(EventId, each_EventId); output["EventId"] = each_EventId;
                return output;
            }
        };

        struct WriteTitleEventRequest : public PlayFabRequestCommon
        {
            Json::Value Body; // Not truly arbitrary. See documentation for restrictions on format
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

            ~WriteTitleEventRequest() = default;

            void FromJson(Json::Value& input) override
            {
                Body = input["Body"];
                FromJsonUtilS(input["EventName"], EventName);
                FromJsonUtilT(input["Timestamp"], Timestamp);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["Body"] = Body;
                Json::Value each_EventName; ToJsonUtilS(EventName, each_EventName); output["EventName"] = each_EventName;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
                return output;
            }
        };

    }
}

#endif
