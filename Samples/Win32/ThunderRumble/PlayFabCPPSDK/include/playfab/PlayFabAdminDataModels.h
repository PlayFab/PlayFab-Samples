#pragma once

#ifdef ENABLE_PLAYFABADMIN_API

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
    namespace AdminModels
    {
        // Admin Enums
        enum AuthTokenType
        {
            AuthTokenTypeEmail
        };

        inline void ToJsonEnum(const AuthTokenType input, Json::Value& output)
        {
            if (input == AuthTokenTypeEmail) output = Json::Value("Email");
        }
        inline void FromJsonEnum(const Json::Value& input, AuthTokenType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Email") output = AuthTokenTypeEmail;
        }

        enum Conditionals
        {
            ConditionalsAny,
            ConditionalsTrue,
            ConditionalsFalse
        };

        inline void ToJsonEnum(const Conditionals input, Json::Value& output)
        {
            if (input == ConditionalsAny) output = Json::Value("Any");
            if (input == ConditionalsTrue) output = Json::Value("True");
            if (input == ConditionalsFalse) output = Json::Value("False");
        }
        inline void FromJsonEnum(const Json::Value& input, Conditionals& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Any") output = ConditionalsAny;
            if (inputStr == "True") output = ConditionalsTrue;
            if (inputStr == "False") output = ConditionalsFalse;
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

        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        inline void ToJsonEnum(const EffectType input, Json::Value& output)
        {
            if (input == EffectTypeAllow) output = Json::Value("Allow");
            if (input == EffectTypeDeny) output = Json::Value("Deny");
        }
        inline void FromJsonEnum(const Json::Value& input, EffectType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Allow") output = EffectTypeAllow;
            if (inputStr == "Deny") output = EffectTypeDeny;
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

        enum GameBuildStatus
        {
            GameBuildStatusAvailable,
            GameBuildStatusValidating,
            GameBuildStatusInvalidBuildPackage,
            GameBuildStatusProcessing,
            GameBuildStatusFailedToProcess
        };

        inline void ToJsonEnum(const GameBuildStatus input, Json::Value& output)
        {
            if (input == GameBuildStatusAvailable) output = Json::Value("Available");
            if (input == GameBuildStatusValidating) output = Json::Value("Validating");
            if (input == GameBuildStatusInvalidBuildPackage) output = Json::Value("InvalidBuildPackage");
            if (input == GameBuildStatusProcessing) output = Json::Value("Processing");
            if (input == GameBuildStatusFailedToProcess) output = Json::Value("FailedToProcess");
        }
        inline void FromJsonEnum(const Json::Value& input, GameBuildStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Available") output = GameBuildStatusAvailable;
            if (inputStr == "Validating") output = GameBuildStatusValidating;
            if (inputStr == "InvalidBuildPackage") output = GameBuildStatusInvalidBuildPackage;
            if (inputStr == "Processing") output = GameBuildStatusProcessing;
            if (inputStr == "FailedToProcess") output = GameBuildStatusFailedToProcess;
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
            GenericErrorCodesMultiplayerServerError,
            GenericErrorCodesMultiplayerServerTooManyRequests,
            GenericErrorCodesMultiplayerServerNoContent,
            GenericErrorCodesMultiplayerServerBadRequest,
            GenericErrorCodesMultiplayerServerUnauthorized,
            GenericErrorCodesMultiplayerServerForbidden,
            GenericErrorCodesMultiplayerServerNotFound,
            GenericErrorCodesMultiplayerServerConflict,
            GenericErrorCodesMultiplayerServerInternalServerError,
            GenericErrorCodesMultiplayerServerUnavailable,
            GenericErrorCodesExplicitContentDetected,
            GenericErrorCodesPIIContentDetected,
            GenericErrorCodesInvalidScheduledTaskParameter,
            GenericErrorCodesPerEntityEventRateLimitExceeded,
            GenericErrorCodesTitleDefaultLanguageNotSet,
            GenericErrorCodesEmailTemplateMissingDefaultVersion,
            GenericErrorCodesFacebookInstantGamesIdNotLinked,
            GenericErrorCodesInvalidFacebookInstantGamesSignature,
            GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle,
            GenericErrorCodesEntityProfileConstraintValidationFailed,
            GenericErrorCodesPlayInsightsIngestionKeyPending,
            GenericErrorCodesPlayInsightsIngestionKeyNotFound,
            GenericErrorCodesStatisticTagRequired,
            GenericErrorCodesStatisticTagInvalid,
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
            GenericErrorCodesMatchmakingNotEnabled,
            GenericErrorCodesMatchmakingGetStatisticsIdentityInvalid,
            GenericErrorCodesMatchmakingStatisticsIdMissing
        };

        inline void ToJsonEnum(const GenericErrorCodes input, Json::Value& output)
        {
            if (input == GenericErrorCodesSuccess) output = Json::Value("Success");
            if (input == GenericErrorCodesUnkownError) output = Json::Value("UnkownError");
            if (input == GenericErrorCodesInvalidParams) output = Json::Value("InvalidParams");
            if (input == GenericErrorCodesAccountNotFound) output = Json::Value("AccountNotFound");
            if (input == GenericErrorCodesAccountBanned) output = Json::Value("AccountBanned");
            if (input == GenericErrorCodesInvalidUsernameOrPassword) output = Json::Value("InvalidUsernameOrPassword");
            if (input == GenericErrorCodesInvalidTitleId) output = Json::Value("InvalidTitleId");
            if (input == GenericErrorCodesInvalidEmailAddress) output = Json::Value("InvalidEmailAddress");
            if (input == GenericErrorCodesEmailAddressNotAvailable) output = Json::Value("EmailAddressNotAvailable");
            if (input == GenericErrorCodesInvalidUsername) output = Json::Value("InvalidUsername");
            if (input == GenericErrorCodesInvalidPassword) output = Json::Value("InvalidPassword");
            if (input == GenericErrorCodesUsernameNotAvailable) output = Json::Value("UsernameNotAvailable");
            if (input == GenericErrorCodesInvalidSteamTicket) output = Json::Value("InvalidSteamTicket");
            if (input == GenericErrorCodesAccountAlreadyLinked) output = Json::Value("AccountAlreadyLinked");
            if (input == GenericErrorCodesLinkedAccountAlreadyClaimed) output = Json::Value("LinkedAccountAlreadyClaimed");
            if (input == GenericErrorCodesInvalidFacebookToken) output = Json::Value("InvalidFacebookToken");
            if (input == GenericErrorCodesAccountNotLinked) output = Json::Value("AccountNotLinked");
            if (input == GenericErrorCodesFailedByPaymentProvider) output = Json::Value("FailedByPaymentProvider");
            if (input == GenericErrorCodesCouponCodeNotFound) output = Json::Value("CouponCodeNotFound");
            if (input == GenericErrorCodesInvalidContainerItem) output = Json::Value("InvalidContainerItem");
            if (input == GenericErrorCodesContainerNotOwned) output = Json::Value("ContainerNotOwned");
            if (input == GenericErrorCodesKeyNotOwned) output = Json::Value("KeyNotOwned");
            if (input == GenericErrorCodesInvalidItemIdInTable) output = Json::Value("InvalidItemIdInTable");
            if (input == GenericErrorCodesInvalidReceipt) output = Json::Value("InvalidReceipt");
            if (input == GenericErrorCodesReceiptAlreadyUsed) output = Json::Value("ReceiptAlreadyUsed");
            if (input == GenericErrorCodesReceiptCancelled) output = Json::Value("ReceiptCancelled");
            if (input == GenericErrorCodesGameNotFound) output = Json::Value("GameNotFound");
            if (input == GenericErrorCodesGameModeNotFound) output = Json::Value("GameModeNotFound");
            if (input == GenericErrorCodesInvalidGoogleToken) output = Json::Value("InvalidGoogleToken");
            if (input == GenericErrorCodesUserIsNotPartOfDeveloper) output = Json::Value("UserIsNotPartOfDeveloper");
            if (input == GenericErrorCodesInvalidTitleForDeveloper) output = Json::Value("InvalidTitleForDeveloper");
            if (input == GenericErrorCodesTitleNameConflicts) output = Json::Value("TitleNameConflicts");
            if (input == GenericErrorCodesUserisNotValid) output = Json::Value("UserisNotValid");
            if (input == GenericErrorCodesValueAlreadyExists) output = Json::Value("ValueAlreadyExists");
            if (input == GenericErrorCodesBuildNotFound) output = Json::Value("BuildNotFound");
            if (input == GenericErrorCodesPlayerNotInGame) output = Json::Value("PlayerNotInGame");
            if (input == GenericErrorCodesInvalidTicket) output = Json::Value("InvalidTicket");
            if (input == GenericErrorCodesInvalidDeveloper) output = Json::Value("InvalidDeveloper");
            if (input == GenericErrorCodesInvalidOrderInfo) output = Json::Value("InvalidOrderInfo");
            if (input == GenericErrorCodesRegistrationIncomplete) output = Json::Value("RegistrationIncomplete");
            if (input == GenericErrorCodesInvalidPlatform) output = Json::Value("InvalidPlatform");
            if (input == GenericErrorCodesUnknownError) output = Json::Value("UnknownError");
            if (input == GenericErrorCodesSteamApplicationNotOwned) output = Json::Value("SteamApplicationNotOwned");
            if (input == GenericErrorCodesWrongSteamAccount) output = Json::Value("WrongSteamAccount");
            if (input == GenericErrorCodesTitleNotActivated) output = Json::Value("TitleNotActivated");
            if (input == GenericErrorCodesRegistrationSessionNotFound) output = Json::Value("RegistrationSessionNotFound");
            if (input == GenericErrorCodesNoSuchMod) output = Json::Value("NoSuchMod");
            if (input == GenericErrorCodesFileNotFound) output = Json::Value("FileNotFound");
            if (input == GenericErrorCodesDuplicateEmail) output = Json::Value("DuplicateEmail");
            if (input == GenericErrorCodesItemNotFound) output = Json::Value("ItemNotFound");
            if (input == GenericErrorCodesItemNotOwned) output = Json::Value("ItemNotOwned");
            if (input == GenericErrorCodesItemNotRecycleable) output = Json::Value("ItemNotRecycleable");
            if (input == GenericErrorCodesItemNotAffordable) output = Json::Value("ItemNotAffordable");
            if (input == GenericErrorCodesInvalidVirtualCurrency) output = Json::Value("InvalidVirtualCurrency");
            if (input == GenericErrorCodesWrongVirtualCurrency) output = Json::Value("WrongVirtualCurrency");
            if (input == GenericErrorCodesWrongPrice) output = Json::Value("WrongPrice");
            if (input == GenericErrorCodesNonPositiveValue) output = Json::Value("NonPositiveValue");
            if (input == GenericErrorCodesInvalidRegion) output = Json::Value("InvalidRegion");
            if (input == GenericErrorCodesRegionAtCapacity) output = Json::Value("RegionAtCapacity");
            if (input == GenericErrorCodesServerFailedToStart) output = Json::Value("ServerFailedToStart");
            if (input == GenericErrorCodesNameNotAvailable) output = Json::Value("NameNotAvailable");
            if (input == GenericErrorCodesInsufficientFunds) output = Json::Value("InsufficientFunds");
            if (input == GenericErrorCodesInvalidDeviceID) output = Json::Value("InvalidDeviceID");
            if (input == GenericErrorCodesInvalidPushNotificationToken) output = Json::Value("InvalidPushNotificationToken");
            if (input == GenericErrorCodesNoRemainingUses) output = Json::Value("NoRemainingUses");
            if (input == GenericErrorCodesInvalidPaymentProvider) output = Json::Value("InvalidPaymentProvider");
            if (input == GenericErrorCodesPurchaseInitializationFailure) output = Json::Value("PurchaseInitializationFailure");
            if (input == GenericErrorCodesDuplicateUsername) output = Json::Value("DuplicateUsername");
            if (input == GenericErrorCodesInvalidBuyerInfo) output = Json::Value("InvalidBuyerInfo");
            if (input == GenericErrorCodesNoGameModeParamsSet) output = Json::Value("NoGameModeParamsSet");
            if (input == GenericErrorCodesBodyTooLarge) output = Json::Value("BodyTooLarge");
            if (input == GenericErrorCodesReservedWordInBody) output = Json::Value("ReservedWordInBody");
            if (input == GenericErrorCodesInvalidTypeInBody) output = Json::Value("InvalidTypeInBody");
            if (input == GenericErrorCodesInvalidRequest) output = Json::Value("InvalidRequest");
            if (input == GenericErrorCodesReservedEventName) output = Json::Value("ReservedEventName");
            if (input == GenericErrorCodesInvalidUserStatistics) output = Json::Value("InvalidUserStatistics");
            if (input == GenericErrorCodesNotAuthenticated) output = Json::Value("NotAuthenticated");
            if (input == GenericErrorCodesStreamAlreadyExists) output = Json::Value("StreamAlreadyExists");
            if (input == GenericErrorCodesErrorCreatingStream) output = Json::Value("ErrorCreatingStream");
            if (input == GenericErrorCodesStreamNotFound) output = Json::Value("StreamNotFound");
            if (input == GenericErrorCodesInvalidAccount) output = Json::Value("InvalidAccount");
            if (input == GenericErrorCodesPurchaseDoesNotExist) output = Json::Value("PurchaseDoesNotExist");
            if (input == GenericErrorCodesInvalidPurchaseTransactionStatus) output = Json::Value("InvalidPurchaseTransactionStatus");
            if (input == GenericErrorCodesAPINotEnabledForGameClientAccess) output = Json::Value("APINotEnabledForGameClientAccess");
            if (input == GenericErrorCodesNoPushNotificationARNForTitle) output = Json::Value("NoPushNotificationARNForTitle");
            if (input == GenericErrorCodesBuildAlreadyExists) output = Json::Value("BuildAlreadyExists");
            if (input == GenericErrorCodesBuildPackageDoesNotExist) output = Json::Value("BuildPackageDoesNotExist");
            if (input == GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle) output = Json::Value("CustomAnalyticsEventsNotEnabledForTitle");
            if (input == GenericErrorCodesInvalidSharedGroupId) output = Json::Value("InvalidSharedGroupId");
            if (input == GenericErrorCodesNotAuthorized) output = Json::Value("NotAuthorized");
            if (input == GenericErrorCodesMissingTitleGoogleProperties) output = Json::Value("MissingTitleGoogleProperties");
            if (input == GenericErrorCodesInvalidItemProperties) output = Json::Value("InvalidItemProperties");
            if (input == GenericErrorCodesInvalidPSNAuthCode) output = Json::Value("InvalidPSNAuthCode");
            if (input == GenericErrorCodesInvalidItemId) output = Json::Value("InvalidItemId");
            if (input == GenericErrorCodesPushNotEnabledForAccount) output = Json::Value("PushNotEnabledForAccount");
            if (input == GenericErrorCodesPushServiceError) output = Json::Value("PushServiceError");
            if (input == GenericErrorCodesReceiptDoesNotContainInAppItems) output = Json::Value("ReceiptDoesNotContainInAppItems");
            if (input == GenericErrorCodesReceiptContainsMultipleInAppItems) output = Json::Value("ReceiptContainsMultipleInAppItems");
            if (input == GenericErrorCodesInvalidBundleID) output = Json::Value("InvalidBundleID");
            if (input == GenericErrorCodesJavascriptException) output = Json::Value("JavascriptException");
            if (input == GenericErrorCodesInvalidSessionTicket) output = Json::Value("InvalidSessionTicket");
            if (input == GenericErrorCodesUnableToConnectToDatabase) output = Json::Value("UnableToConnectToDatabase");
            if (input == GenericErrorCodesInternalServerError) output = Json::Value("InternalServerError");
            if (input == GenericErrorCodesInvalidReportDate) output = Json::Value("InvalidReportDate");
            if (input == GenericErrorCodesReportNotAvailable) output = Json::Value("ReportNotAvailable");
            if (input == GenericErrorCodesDatabaseThroughputExceeded) output = Json::Value("DatabaseThroughputExceeded");
            if (input == GenericErrorCodesInvalidGameTicket) output = Json::Value("InvalidGameTicket");
            if (input == GenericErrorCodesExpiredGameTicket) output = Json::Value("ExpiredGameTicket");
            if (input == GenericErrorCodesGameTicketDoesNotMatchLobby) output = Json::Value("GameTicketDoesNotMatchLobby");
            if (input == GenericErrorCodesLinkedDeviceAlreadyClaimed) output = Json::Value("LinkedDeviceAlreadyClaimed");
            if (input == GenericErrorCodesDeviceAlreadyLinked) output = Json::Value("DeviceAlreadyLinked");
            if (input == GenericErrorCodesDeviceNotLinked) output = Json::Value("DeviceNotLinked");
            if (input == GenericErrorCodesPartialFailure) output = Json::Value("PartialFailure");
            if (input == GenericErrorCodesPublisherNotSet) output = Json::Value("PublisherNotSet");
            if (input == GenericErrorCodesServiceUnavailable) output = Json::Value("ServiceUnavailable");
            if (input == GenericErrorCodesVersionNotFound) output = Json::Value("VersionNotFound");
            if (input == GenericErrorCodesRevisionNotFound) output = Json::Value("RevisionNotFound");
            if (input == GenericErrorCodesInvalidPublisherId) output = Json::Value("InvalidPublisherId");
            if (input == GenericErrorCodesDownstreamServiceUnavailable) output = Json::Value("DownstreamServiceUnavailable");
            if (input == GenericErrorCodesAPINotIncludedInTitleUsageTier) output = Json::Value("APINotIncludedInTitleUsageTier");
            if (input == GenericErrorCodesDAULimitExceeded) output = Json::Value("DAULimitExceeded");
            if (input == GenericErrorCodesAPIRequestLimitExceeded) output = Json::Value("APIRequestLimitExceeded");
            if (input == GenericErrorCodesInvalidAPIEndpoint) output = Json::Value("InvalidAPIEndpoint");
            if (input == GenericErrorCodesBuildNotAvailable) output = Json::Value("BuildNotAvailable");
            if (input == GenericErrorCodesConcurrentEditError) output = Json::Value("ConcurrentEditError");
            if (input == GenericErrorCodesContentNotFound) output = Json::Value("ContentNotFound");
            if (input == GenericErrorCodesCharacterNotFound) output = Json::Value("CharacterNotFound");
            if (input == GenericErrorCodesCloudScriptNotFound) output = Json::Value("CloudScriptNotFound");
            if (input == GenericErrorCodesContentQuotaExceeded) output = Json::Value("ContentQuotaExceeded");
            if (input == GenericErrorCodesInvalidCharacterStatistics) output = Json::Value("InvalidCharacterStatistics");
            if (input == GenericErrorCodesPhotonNotEnabledForTitle) output = Json::Value("PhotonNotEnabledForTitle");
            if (input == GenericErrorCodesPhotonApplicationNotFound) output = Json::Value("PhotonApplicationNotFound");
            if (input == GenericErrorCodesPhotonApplicationNotAssociatedWithTitle) output = Json::Value("PhotonApplicationNotAssociatedWithTitle");
            if (input == GenericErrorCodesInvalidEmailOrPassword) output = Json::Value("InvalidEmailOrPassword");
            if (input == GenericErrorCodesFacebookAPIError) output = Json::Value("FacebookAPIError");
            if (input == GenericErrorCodesInvalidContentType) output = Json::Value("InvalidContentType");
            if (input == GenericErrorCodesKeyLengthExceeded) output = Json::Value("KeyLengthExceeded");
            if (input == GenericErrorCodesDataLengthExceeded) output = Json::Value("DataLengthExceeded");
            if (input == GenericErrorCodesTooManyKeys) output = Json::Value("TooManyKeys");
            if (input == GenericErrorCodesFreeTierCannotHaveVirtualCurrency) output = Json::Value("FreeTierCannotHaveVirtualCurrency");
            if (input == GenericErrorCodesMissingAmazonSharedKey) output = Json::Value("MissingAmazonSharedKey");
            if (input == GenericErrorCodesAmazonValidationError) output = Json::Value("AmazonValidationError");
            if (input == GenericErrorCodesInvalidPSNIssuerId) output = Json::Value("InvalidPSNIssuerId");
            if (input == GenericErrorCodesPSNInaccessible) output = Json::Value("PSNInaccessible");
            if (input == GenericErrorCodesExpiredAuthToken) output = Json::Value("ExpiredAuthToken");
            if (input == GenericErrorCodesFailedToGetEntitlements) output = Json::Value("FailedToGetEntitlements");
            if (input == GenericErrorCodesFailedToConsumeEntitlement) output = Json::Value("FailedToConsumeEntitlement");
            if (input == GenericErrorCodesTradeAcceptingUserNotAllowed) output = Json::Value("TradeAcceptingUserNotAllowed");
            if (input == GenericErrorCodesTradeInventoryItemIsAssignedToCharacter) output = Json::Value("TradeInventoryItemIsAssignedToCharacter");
            if (input == GenericErrorCodesTradeInventoryItemIsBundle) output = Json::Value("TradeInventoryItemIsBundle");
            if (input == GenericErrorCodesTradeStatusNotValidForCancelling) output = Json::Value("TradeStatusNotValidForCancelling");
            if (input == GenericErrorCodesTradeStatusNotValidForAccepting) output = Json::Value("TradeStatusNotValidForAccepting");
            if (input == GenericErrorCodesTradeDoesNotExist) output = Json::Value("TradeDoesNotExist");
            if (input == GenericErrorCodesTradeCancelled) output = Json::Value("TradeCancelled");
            if (input == GenericErrorCodesTradeAlreadyFilled) output = Json::Value("TradeAlreadyFilled");
            if (input == GenericErrorCodesTradeWaitForStatusTimeout) output = Json::Value("TradeWaitForStatusTimeout");
            if (input == GenericErrorCodesTradeInventoryItemExpired) output = Json::Value("TradeInventoryItemExpired");
            if (input == GenericErrorCodesTradeMissingOfferedAndAcceptedItems) output = Json::Value("TradeMissingOfferedAndAcceptedItems");
            if (input == GenericErrorCodesTradeAcceptedItemIsBundle) output = Json::Value("TradeAcceptedItemIsBundle");
            if (input == GenericErrorCodesTradeAcceptedItemIsStackable) output = Json::Value("TradeAcceptedItemIsStackable");
            if (input == GenericErrorCodesTradeInventoryItemInvalidStatus) output = Json::Value("TradeInventoryItemInvalidStatus");
            if (input == GenericErrorCodesTradeAcceptedCatalogItemInvalid) output = Json::Value("TradeAcceptedCatalogItemInvalid");
            if (input == GenericErrorCodesTradeAllowedUsersInvalid) output = Json::Value("TradeAllowedUsersInvalid");
            if (input == GenericErrorCodesTradeInventoryItemDoesNotExist) output = Json::Value("TradeInventoryItemDoesNotExist");
            if (input == GenericErrorCodesTradeInventoryItemIsConsumed) output = Json::Value("TradeInventoryItemIsConsumed");
            if (input == GenericErrorCodesTradeInventoryItemIsStackable) output = Json::Value("TradeInventoryItemIsStackable");
            if (input == GenericErrorCodesTradeAcceptedItemsMismatch) output = Json::Value("TradeAcceptedItemsMismatch");
            if (input == GenericErrorCodesInvalidKongregateToken) output = Json::Value("InvalidKongregateToken");
            if (input == GenericErrorCodesFeatureNotConfiguredForTitle) output = Json::Value("FeatureNotConfiguredForTitle");
            if (input == GenericErrorCodesNoMatchingCatalogItemForReceipt) output = Json::Value("NoMatchingCatalogItemForReceipt");
            if (input == GenericErrorCodesInvalidCurrencyCode) output = Json::Value("InvalidCurrencyCode");
            if (input == GenericErrorCodesNoRealMoneyPriceForCatalogItem) output = Json::Value("NoRealMoneyPriceForCatalogItem");
            if (input == GenericErrorCodesTradeInventoryItemIsNotTradable) output = Json::Value("TradeInventoryItemIsNotTradable");
            if (input == GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable) output = Json::Value("TradeAcceptedCatalogItemIsNotTradable");
            if (input == GenericErrorCodesUsersAlreadyFriends) output = Json::Value("UsersAlreadyFriends");
            if (input == GenericErrorCodesLinkedIdentifierAlreadyClaimed) output = Json::Value("LinkedIdentifierAlreadyClaimed");
            if (input == GenericErrorCodesCustomIdNotLinked) output = Json::Value("CustomIdNotLinked");
            if (input == GenericErrorCodesTotalDataSizeExceeded) output = Json::Value("TotalDataSizeExceeded");
            if (input == GenericErrorCodesDeleteKeyConflict) output = Json::Value("DeleteKeyConflict");
            if (input == GenericErrorCodesInvalidXboxLiveToken) output = Json::Value("InvalidXboxLiveToken");
            if (input == GenericErrorCodesExpiredXboxLiveToken) output = Json::Value("ExpiredXboxLiveToken");
            if (input == GenericErrorCodesResettableStatisticVersionRequired) output = Json::Value("ResettableStatisticVersionRequired");
            if (input == GenericErrorCodesNotAuthorizedByTitle) output = Json::Value("NotAuthorizedByTitle");
            if (input == GenericErrorCodesNoPartnerEnabled) output = Json::Value("NoPartnerEnabled");
            if (input == GenericErrorCodesInvalidPartnerResponse) output = Json::Value("InvalidPartnerResponse");
            if (input == GenericErrorCodesAPINotEnabledForGameServerAccess) output = Json::Value("APINotEnabledForGameServerAccess");
            if (input == GenericErrorCodesStatisticNotFound) output = Json::Value("StatisticNotFound");
            if (input == GenericErrorCodesStatisticNameConflict) output = Json::Value("StatisticNameConflict");
            if (input == GenericErrorCodesStatisticVersionClosedForWrites) output = Json::Value("StatisticVersionClosedForWrites");
            if (input == GenericErrorCodesStatisticVersionInvalid) output = Json::Value("StatisticVersionInvalid");
            if (input == GenericErrorCodesAPIClientRequestRateLimitExceeded) output = Json::Value("APIClientRequestRateLimitExceeded");
            if (input == GenericErrorCodesInvalidJSONContent) output = Json::Value("InvalidJSONContent");
            if (input == GenericErrorCodesInvalidDropTable) output = Json::Value("InvalidDropTable");
            if (input == GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval) output = Json::Value("StatisticVersionAlreadyIncrementedForScheduledInterval");
            if (input == GenericErrorCodesStatisticCountLimitExceeded) output = Json::Value("StatisticCountLimitExceeded");
            if (input == GenericErrorCodesStatisticVersionIncrementRateExceeded) output = Json::Value("StatisticVersionIncrementRateExceeded");
            if (input == GenericErrorCodesContainerKeyInvalid) output = Json::Value("ContainerKeyInvalid");
            if (input == GenericErrorCodesCloudScriptExecutionTimeLimitExceeded) output = Json::Value("CloudScriptExecutionTimeLimitExceeded");
            if (input == GenericErrorCodesNoWritePermissionsForEvent) output = Json::Value("NoWritePermissionsForEvent");
            if (input == GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded) output = Json::Value("CloudScriptFunctionArgumentSizeExceeded");
            if (input == GenericErrorCodesCloudScriptAPIRequestCountExceeded) output = Json::Value("CloudScriptAPIRequestCountExceeded");
            if (input == GenericErrorCodesCloudScriptAPIRequestError) output = Json::Value("CloudScriptAPIRequestError");
            if (input == GenericErrorCodesCloudScriptHTTPRequestError) output = Json::Value("CloudScriptHTTPRequestError");
            if (input == GenericErrorCodesInsufficientGuildRole) output = Json::Value("InsufficientGuildRole");
            if (input == GenericErrorCodesGuildNotFound) output = Json::Value("GuildNotFound");
            if (input == GenericErrorCodesOverLimit) output = Json::Value("OverLimit");
            if (input == GenericErrorCodesEventNotFound) output = Json::Value("EventNotFound");
            if (input == GenericErrorCodesInvalidEventField) output = Json::Value("InvalidEventField");
            if (input == GenericErrorCodesInvalidEventName) output = Json::Value("InvalidEventName");
            if (input == GenericErrorCodesCatalogNotConfigured) output = Json::Value("CatalogNotConfigured");
            if (input == GenericErrorCodesOperationNotSupportedForPlatform) output = Json::Value("OperationNotSupportedForPlatform");
            if (input == GenericErrorCodesSegmentNotFound) output = Json::Value("SegmentNotFound");
            if (input == GenericErrorCodesStoreNotFound) output = Json::Value("StoreNotFound");
            if (input == GenericErrorCodesInvalidStatisticName) output = Json::Value("InvalidStatisticName");
            if (input == GenericErrorCodesTitleNotQualifiedForLimit) output = Json::Value("TitleNotQualifiedForLimit");
            if (input == GenericErrorCodesInvalidServiceLimitLevel) output = Json::Value("InvalidServiceLimitLevel");
            if (input == GenericErrorCodesServiceLimitLevelInTransition) output = Json::Value("ServiceLimitLevelInTransition");
            if (input == GenericErrorCodesCouponAlreadyRedeemed) output = Json::Value("CouponAlreadyRedeemed");
            if (input == GenericErrorCodesGameServerBuildSizeLimitExceeded) output = Json::Value("GameServerBuildSizeLimitExceeded");
            if (input == GenericErrorCodesGameServerBuildCountLimitExceeded) output = Json::Value("GameServerBuildCountLimitExceeded");
            if (input == GenericErrorCodesVirtualCurrencyCountLimitExceeded) output = Json::Value("VirtualCurrencyCountLimitExceeded");
            if (input == GenericErrorCodesVirtualCurrencyCodeExists) output = Json::Value("VirtualCurrencyCodeExists");
            if (input == GenericErrorCodesTitleNewsItemCountLimitExceeded) output = Json::Value("TitleNewsItemCountLimitExceeded");
            if (input == GenericErrorCodesInvalidTwitchToken) output = Json::Value("InvalidTwitchToken");
            if (input == GenericErrorCodesTwitchResponseError) output = Json::Value("TwitchResponseError");
            if (input == GenericErrorCodesProfaneDisplayName) output = Json::Value("ProfaneDisplayName");
            if (input == GenericErrorCodesUserAlreadyAdded) output = Json::Value("UserAlreadyAdded");
            if (input == GenericErrorCodesInvalidVirtualCurrencyCode) output = Json::Value("InvalidVirtualCurrencyCode");
            if (input == GenericErrorCodesVirtualCurrencyCannotBeDeleted) output = Json::Value("VirtualCurrencyCannotBeDeleted");
            if (input == GenericErrorCodesIdentifierAlreadyClaimed) output = Json::Value("IdentifierAlreadyClaimed");
            if (input == GenericErrorCodesIdentifierNotLinked) output = Json::Value("IdentifierNotLinked");
            if (input == GenericErrorCodesInvalidContinuationToken) output = Json::Value("InvalidContinuationToken");
            if (input == GenericErrorCodesExpiredContinuationToken) output = Json::Value("ExpiredContinuationToken");
            if (input == GenericErrorCodesInvalidSegment) output = Json::Value("InvalidSegment");
            if (input == GenericErrorCodesInvalidSessionId) output = Json::Value("InvalidSessionId");
            if (input == GenericErrorCodesSessionLogNotFound) output = Json::Value("SessionLogNotFound");
            if (input == GenericErrorCodesInvalidSearchTerm) output = Json::Value("InvalidSearchTerm");
            if (input == GenericErrorCodesTwoFactorAuthenticationTokenRequired) output = Json::Value("TwoFactorAuthenticationTokenRequired");
            if (input == GenericErrorCodesGameServerHostCountLimitExceeded) output = Json::Value("GameServerHostCountLimitExceeded");
            if (input == GenericErrorCodesPlayerTagCountLimitExceeded) output = Json::Value("PlayerTagCountLimitExceeded");
            if (input == GenericErrorCodesRequestAlreadyRunning) output = Json::Value("RequestAlreadyRunning");
            if (input == GenericErrorCodesActionGroupNotFound) output = Json::Value("ActionGroupNotFound");
            if (input == GenericErrorCodesMaximumSegmentBulkActionJobsRunning) output = Json::Value("MaximumSegmentBulkActionJobsRunning");
            if (input == GenericErrorCodesNoActionsOnPlayersInSegmentJob) output = Json::Value("NoActionsOnPlayersInSegmentJob");
            if (input == GenericErrorCodesDuplicateStatisticName) output = Json::Value("DuplicateStatisticName");
            if (input == GenericErrorCodesScheduledTaskNameConflict) output = Json::Value("ScheduledTaskNameConflict");
            if (input == GenericErrorCodesScheduledTaskCreateConflict) output = Json::Value("ScheduledTaskCreateConflict");
            if (input == GenericErrorCodesInvalidScheduledTaskName) output = Json::Value("InvalidScheduledTaskName");
            if (input == GenericErrorCodesInvalidTaskSchedule) output = Json::Value("InvalidTaskSchedule");
            if (input == GenericErrorCodesSteamNotEnabledForTitle) output = Json::Value("SteamNotEnabledForTitle");
            if (input == GenericErrorCodesLimitNotAnUpgradeOption) output = Json::Value("LimitNotAnUpgradeOption");
            if (input == GenericErrorCodesNoSecretKeyEnabledForCloudScript) output = Json::Value("NoSecretKeyEnabledForCloudScript");
            if (input == GenericErrorCodesTaskNotFound) output = Json::Value("TaskNotFound");
            if (input == GenericErrorCodesTaskInstanceNotFound) output = Json::Value("TaskInstanceNotFound");
            if (input == GenericErrorCodesInvalidIdentityProviderId) output = Json::Value("InvalidIdentityProviderId");
            if (input == GenericErrorCodesMisconfiguredIdentityProvider) output = Json::Value("MisconfiguredIdentityProvider");
            if (input == GenericErrorCodesInvalidScheduledTaskType) output = Json::Value("InvalidScheduledTaskType");
            if (input == GenericErrorCodesBillingInformationRequired) output = Json::Value("BillingInformationRequired");
            if (input == GenericErrorCodesLimitedEditionItemUnavailable) output = Json::Value("LimitedEditionItemUnavailable");
            if (input == GenericErrorCodesInvalidAdPlacementAndReward) output = Json::Value("InvalidAdPlacementAndReward");
            if (input == GenericErrorCodesAllAdPlacementViewsAlreadyConsumed) output = Json::Value("AllAdPlacementViewsAlreadyConsumed");
            if (input == GenericErrorCodesGoogleOAuthNotConfiguredForTitle) output = Json::Value("GoogleOAuthNotConfiguredForTitle");
            if (input == GenericErrorCodesGoogleOAuthError) output = Json::Value("GoogleOAuthError");
            if (input == GenericErrorCodesUserNotFriend) output = Json::Value("UserNotFriend");
            if (input == GenericErrorCodesInvalidSignature) output = Json::Value("InvalidSignature");
            if (input == GenericErrorCodesInvalidPublicKey) output = Json::Value("InvalidPublicKey");
            if (input == GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse) output = Json::Value("GoogleOAuthNoIdTokenIncludedInResponse");
            if (input == GenericErrorCodesStatisticUpdateInProgress) output = Json::Value("StatisticUpdateInProgress");
            if (input == GenericErrorCodesLeaderboardVersionNotAvailable) output = Json::Value("LeaderboardVersionNotAvailable");
            if (input == GenericErrorCodesStatisticAlreadyHasPrizeTable) output = Json::Value("StatisticAlreadyHasPrizeTable");
            if (input == GenericErrorCodesPrizeTableHasOverlappingRanks) output = Json::Value("PrizeTableHasOverlappingRanks");
            if (input == GenericErrorCodesPrizeTableHasMissingRanks) output = Json::Value("PrizeTableHasMissingRanks");
            if (input == GenericErrorCodesPrizeTableRankStartsAtZero) output = Json::Value("PrizeTableRankStartsAtZero");
            if (input == GenericErrorCodesInvalidStatistic) output = Json::Value("InvalidStatistic");
            if (input == GenericErrorCodesExpressionParseFailure) output = Json::Value("ExpressionParseFailure");
            if (input == GenericErrorCodesExpressionInvokeFailure) output = Json::Value("ExpressionInvokeFailure");
            if (input == GenericErrorCodesExpressionTooLong) output = Json::Value("ExpressionTooLong");
            if (input == GenericErrorCodesDataUpdateRateExceeded) output = Json::Value("DataUpdateRateExceeded");
            if (input == GenericErrorCodesRestrictedEmailDomain) output = Json::Value("RestrictedEmailDomain");
            if (input == GenericErrorCodesEncryptionKeyDisabled) output = Json::Value("EncryptionKeyDisabled");
            if (input == GenericErrorCodesEncryptionKeyMissing) output = Json::Value("EncryptionKeyMissing");
            if (input == GenericErrorCodesEncryptionKeyBroken) output = Json::Value("EncryptionKeyBroken");
            if (input == GenericErrorCodesNoSharedSecretKeyConfigured) output = Json::Value("NoSharedSecretKeyConfigured");
            if (input == GenericErrorCodesSecretKeyNotFound) output = Json::Value("SecretKeyNotFound");
            if (input == GenericErrorCodesPlayerSecretAlreadyConfigured) output = Json::Value("PlayerSecretAlreadyConfigured");
            if (input == GenericErrorCodesAPIRequestsDisabledForTitle) output = Json::Value("APIRequestsDisabledForTitle");
            if (input == GenericErrorCodesInvalidSharedSecretKey) output = Json::Value("InvalidSharedSecretKey");
            if (input == GenericErrorCodesPrizeTableHasNoRanks) output = Json::Value("PrizeTableHasNoRanks");
            if (input == GenericErrorCodesProfileDoesNotExist) output = Json::Value("ProfileDoesNotExist");
            if (input == GenericErrorCodesContentS3OriginBucketNotConfigured) output = Json::Value("ContentS3OriginBucketNotConfigured");
            if (input == GenericErrorCodesInvalidEnvironmentForReceipt) output = Json::Value("InvalidEnvironmentForReceipt");
            if (input == GenericErrorCodesEncryptedRequestNotAllowed) output = Json::Value("EncryptedRequestNotAllowed");
            if (input == GenericErrorCodesSignedRequestNotAllowed) output = Json::Value("SignedRequestNotAllowed");
            if (input == GenericErrorCodesRequestViewConstraintParamsNotAllowed) output = Json::Value("RequestViewConstraintParamsNotAllowed");
            if (input == GenericErrorCodesBadPartnerConfiguration) output = Json::Value("BadPartnerConfiguration");
            if (input == GenericErrorCodesXboxBPCertificateFailure) output = Json::Value("XboxBPCertificateFailure");
            if (input == GenericErrorCodesXboxXASSExchangeFailure) output = Json::Value("XboxXASSExchangeFailure");
            if (input == GenericErrorCodesInvalidEntityId) output = Json::Value("InvalidEntityId");
            if (input == GenericErrorCodesStatisticValueAggregationOverflow) output = Json::Value("StatisticValueAggregationOverflow");
            if (input == GenericErrorCodesEmailMessageFromAddressIsMissing) output = Json::Value("EmailMessageFromAddressIsMissing");
            if (input == GenericErrorCodesEmailMessageToAddressIsMissing) output = Json::Value("EmailMessageToAddressIsMissing");
            if (input == GenericErrorCodesSmtpServerAuthenticationError) output = Json::Value("SmtpServerAuthenticationError");
            if (input == GenericErrorCodesSmtpServerLimitExceeded) output = Json::Value("SmtpServerLimitExceeded");
            if (input == GenericErrorCodesSmtpServerInsufficientStorage) output = Json::Value("SmtpServerInsufficientStorage");
            if (input == GenericErrorCodesSmtpServerCommunicationError) output = Json::Value("SmtpServerCommunicationError");
            if (input == GenericErrorCodesSmtpServerGeneralFailure) output = Json::Value("SmtpServerGeneralFailure");
            if (input == GenericErrorCodesEmailClientTimeout) output = Json::Value("EmailClientTimeout");
            if (input == GenericErrorCodesEmailClientCanceledTask) output = Json::Value("EmailClientCanceledTask");
            if (input == GenericErrorCodesEmailTemplateMissing) output = Json::Value("EmailTemplateMissing");
            if (input == GenericErrorCodesInvalidHostForTitleId) output = Json::Value("InvalidHostForTitleId");
            if (input == GenericErrorCodesEmailConfirmationTokenDoesNotExist) output = Json::Value("EmailConfirmationTokenDoesNotExist");
            if (input == GenericErrorCodesEmailConfirmationTokenExpired) output = Json::Value("EmailConfirmationTokenExpired");
            if (input == GenericErrorCodesAccountDeleted) output = Json::Value("AccountDeleted");
            if (input == GenericErrorCodesPlayerSecretNotConfigured) output = Json::Value("PlayerSecretNotConfigured");
            if (input == GenericErrorCodesInvalidSignatureTime) output = Json::Value("InvalidSignatureTime");
            if (input == GenericErrorCodesNoContactEmailAddressFound) output = Json::Value("NoContactEmailAddressFound");
            if (input == GenericErrorCodesInvalidAuthToken) output = Json::Value("InvalidAuthToken");
            if (input == GenericErrorCodesAuthTokenDoesNotExist) output = Json::Value("AuthTokenDoesNotExist");
            if (input == GenericErrorCodesAuthTokenExpired) output = Json::Value("AuthTokenExpired");
            if (input == GenericErrorCodesAuthTokenAlreadyUsedToResetPassword) output = Json::Value("AuthTokenAlreadyUsedToResetPassword");
            if (input == GenericErrorCodesMembershipNameTooLong) output = Json::Value("MembershipNameTooLong");
            if (input == GenericErrorCodesMembershipNotFound) output = Json::Value("MembershipNotFound");
            if (input == GenericErrorCodesGoogleServiceAccountInvalid) output = Json::Value("GoogleServiceAccountInvalid");
            if (input == GenericErrorCodesGoogleServiceAccountParseFailure) output = Json::Value("GoogleServiceAccountParseFailure");
            if (input == GenericErrorCodesEntityTokenMissing) output = Json::Value("EntityTokenMissing");
            if (input == GenericErrorCodesEntityTokenInvalid) output = Json::Value("EntityTokenInvalid");
            if (input == GenericErrorCodesEntityTokenExpired) output = Json::Value("EntityTokenExpired");
            if (input == GenericErrorCodesEntityTokenRevoked) output = Json::Value("EntityTokenRevoked");
            if (input == GenericErrorCodesInvalidProductForSubscription) output = Json::Value("InvalidProductForSubscription");
            if (input == GenericErrorCodesXboxInaccessible) output = Json::Value("XboxInaccessible");
            if (input == GenericErrorCodesSubscriptionAlreadyTaken) output = Json::Value("SubscriptionAlreadyTaken");
            if (input == GenericErrorCodesSmtpAddonNotEnabled) output = Json::Value("SmtpAddonNotEnabled");
            if (input == GenericErrorCodesAPIConcurrentRequestLimitExceeded) output = Json::Value("APIConcurrentRequestLimitExceeded");
            if (input == GenericErrorCodesXboxRejectedXSTSExchangeRequest) output = Json::Value("XboxRejectedXSTSExchangeRequest");
            if (input == GenericErrorCodesVariableNotDefined) output = Json::Value("VariableNotDefined");
            if (input == GenericErrorCodesTemplateVersionNotDefined) output = Json::Value("TemplateVersionNotDefined");
            if (input == GenericErrorCodesFileTooLarge) output = Json::Value("FileTooLarge");
            if (input == GenericErrorCodesTitleDeleted) output = Json::Value("TitleDeleted");
            if (input == GenericErrorCodesTitleContainsUserAccounts) output = Json::Value("TitleContainsUserAccounts");
            if (input == GenericErrorCodesTitleDeletionPlayerCleanupFailure) output = Json::Value("TitleDeletionPlayerCleanupFailure");
            if (input == GenericErrorCodesEntityFileOperationPending) output = Json::Value("EntityFileOperationPending");
            if (input == GenericErrorCodesNoEntityFileOperationPending) output = Json::Value("NoEntityFileOperationPending");
            if (input == GenericErrorCodesEntityProfileVersionMismatch) output = Json::Value("EntityProfileVersionMismatch");
            if (input == GenericErrorCodesTemplateVersionTooOld) output = Json::Value("TemplateVersionTooOld");
            if (input == GenericErrorCodesMembershipDefinitionInUse) output = Json::Value("MembershipDefinitionInUse");
            if (input == GenericErrorCodesPaymentPageNotConfigured) output = Json::Value("PaymentPageNotConfigured");
            if (input == GenericErrorCodesFailedLoginAttemptRateLimitExceeded) output = Json::Value("FailedLoginAttemptRateLimitExceeded");
            if (input == GenericErrorCodesEntityBlockedByGroup) output = Json::Value("EntityBlockedByGroup");
            if (input == GenericErrorCodesRoleDoesNotExist) output = Json::Value("RoleDoesNotExist");
            if (input == GenericErrorCodesEntityIsAlreadyMember) output = Json::Value("EntityIsAlreadyMember");
            if (input == GenericErrorCodesDuplicateRoleId) output = Json::Value("DuplicateRoleId");
            if (input == GenericErrorCodesGroupInvitationNotFound) output = Json::Value("GroupInvitationNotFound");
            if (input == GenericErrorCodesGroupApplicationNotFound) output = Json::Value("GroupApplicationNotFound");
            if (input == GenericErrorCodesOutstandingInvitationAcceptedInstead) output = Json::Value("OutstandingInvitationAcceptedInstead");
            if (input == GenericErrorCodesOutstandingApplicationAcceptedInstead) output = Json::Value("OutstandingApplicationAcceptedInstead");
            if (input == GenericErrorCodesRoleIsGroupDefaultMember) output = Json::Value("RoleIsGroupDefaultMember");
            if (input == GenericErrorCodesRoleIsGroupAdmin) output = Json::Value("RoleIsGroupAdmin");
            if (input == GenericErrorCodesRoleNameNotAvailable) output = Json::Value("RoleNameNotAvailable");
            if (input == GenericErrorCodesGroupNameNotAvailable) output = Json::Value("GroupNameNotAvailable");
            if (input == GenericErrorCodesEmailReportAlreadySent) output = Json::Value("EmailReportAlreadySent");
            if (input == GenericErrorCodesEmailReportRecipientBlacklisted) output = Json::Value("EmailReportRecipientBlacklisted");
            if (input == GenericErrorCodesEventNamespaceNotAllowed) output = Json::Value("EventNamespaceNotAllowed");
            if (input == GenericErrorCodesEventEntityNotAllowed) output = Json::Value("EventEntityNotAllowed");
            if (input == GenericErrorCodesInvalidEntityType) output = Json::Value("InvalidEntityType");
            if (input == GenericErrorCodesNullTokenResultFromAad) output = Json::Value("NullTokenResultFromAad");
            if (input == GenericErrorCodesInvalidTokenResultFromAad) output = Json::Value("InvalidTokenResultFromAad");
            if (input == GenericErrorCodesNoValidCertificateForAad) output = Json::Value("NoValidCertificateForAad");
            if (input == GenericErrorCodesInvalidCertificateForAad) output = Json::Value("InvalidCertificateForAad");
            if (input == GenericErrorCodesDuplicateDropTableId) output = Json::Value("DuplicateDropTableId");
            if (input == GenericErrorCodesMultiplayerServerError) output = Json::Value("MultiplayerServerError");
            if (input == GenericErrorCodesMultiplayerServerTooManyRequests) output = Json::Value("MultiplayerServerTooManyRequests");
            if (input == GenericErrorCodesMultiplayerServerNoContent) output = Json::Value("MultiplayerServerNoContent");
            if (input == GenericErrorCodesMultiplayerServerBadRequest) output = Json::Value("MultiplayerServerBadRequest");
            if (input == GenericErrorCodesMultiplayerServerUnauthorized) output = Json::Value("MultiplayerServerUnauthorized");
            if (input == GenericErrorCodesMultiplayerServerForbidden) output = Json::Value("MultiplayerServerForbidden");
            if (input == GenericErrorCodesMultiplayerServerNotFound) output = Json::Value("MultiplayerServerNotFound");
            if (input == GenericErrorCodesMultiplayerServerConflict) output = Json::Value("MultiplayerServerConflict");
            if (input == GenericErrorCodesMultiplayerServerInternalServerError) output = Json::Value("MultiplayerServerInternalServerError");
            if (input == GenericErrorCodesMultiplayerServerUnavailable) output = Json::Value("MultiplayerServerUnavailable");
            if (input == GenericErrorCodesExplicitContentDetected) output = Json::Value("ExplicitContentDetected");
            if (input == GenericErrorCodesPIIContentDetected) output = Json::Value("PIIContentDetected");
            if (input == GenericErrorCodesInvalidScheduledTaskParameter) output = Json::Value("InvalidScheduledTaskParameter");
            if (input == GenericErrorCodesPerEntityEventRateLimitExceeded) output = Json::Value("PerEntityEventRateLimitExceeded");
            if (input == GenericErrorCodesTitleDefaultLanguageNotSet) output = Json::Value("TitleDefaultLanguageNotSet");
            if (input == GenericErrorCodesEmailTemplateMissingDefaultVersion) output = Json::Value("EmailTemplateMissingDefaultVersion");
            if (input == GenericErrorCodesFacebookInstantGamesIdNotLinked) output = Json::Value("FacebookInstantGamesIdNotLinked");
            if (input == GenericErrorCodesInvalidFacebookInstantGamesSignature) output = Json::Value("InvalidFacebookInstantGamesSignature");
            if (input == GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle) output = Json::Value("FacebookInstantGamesAuthNotConfiguredForTitle");
            if (input == GenericErrorCodesEntityProfileConstraintValidationFailed) output = Json::Value("EntityProfileConstraintValidationFailed");
            if (input == GenericErrorCodesPlayInsightsIngestionKeyPending) output = Json::Value("PlayInsightsIngestionKeyPending");
            if (input == GenericErrorCodesPlayInsightsIngestionKeyNotFound) output = Json::Value("PlayInsightsIngestionKeyNotFound");
            if (input == GenericErrorCodesStatisticTagRequired) output = Json::Value("StatisticTagRequired");
            if (input == GenericErrorCodesStatisticTagInvalid) output = Json::Value("StatisticTagInvalid");
            if (input == GenericErrorCodesMatchmakingEntityInvalid) output = Json::Value("MatchmakingEntityInvalid");
            if (input == GenericErrorCodesMatchmakingPlayerAttributesInvalid) output = Json::Value("MatchmakingPlayerAttributesInvalid");
            if (input == GenericErrorCodesMatchmakingCreateRequestMissing) output = Json::Value("MatchmakingCreateRequestMissing");
            if (input == GenericErrorCodesMatchmakingCreateRequestCreatorMissing) output = Json::Value("MatchmakingCreateRequestCreatorMissing");
            if (input == GenericErrorCodesMatchmakingCreateRequestCreatorIdMissing) output = Json::Value("MatchmakingCreateRequestCreatorIdMissing");
            if (input == GenericErrorCodesMatchmakingCreateRequestUserListMissing) output = Json::Value("MatchmakingCreateRequestUserListMissing");
            if (input == GenericErrorCodesMatchmakingCreateRequestGiveUpAfterInvalid) output = Json::Value("MatchmakingCreateRequestGiveUpAfterInvalid");
            if (input == GenericErrorCodesMatchmakingTicketIdMissing) output = Json::Value("MatchmakingTicketIdMissing");
            if (input == GenericErrorCodesMatchmakingMatchIdMissing) output = Json::Value("MatchmakingMatchIdMissing");
            if (input == GenericErrorCodesMatchmakingMatchIdIdMissing) output = Json::Value("MatchmakingMatchIdIdMissing");
            if (input == GenericErrorCodesMatchmakingQueueNameMissing) output = Json::Value("MatchmakingQueueNameMissing");
            if (input == GenericErrorCodesMatchmakingTitleIdMissing) output = Json::Value("MatchmakingTitleIdMissing");
            if (input == GenericErrorCodesMatchmakingTicketIdIdMissing) output = Json::Value("MatchmakingTicketIdIdMissing");
            if (input == GenericErrorCodesMatchmakingPlayerIdMissing) output = Json::Value("MatchmakingPlayerIdMissing");
            if (input == GenericErrorCodesMatchmakingJoinRequestUserMissing) output = Json::Value("MatchmakingJoinRequestUserMissing");
            if (input == GenericErrorCodesMatchmakingQueueConfigNotFound) output = Json::Value("MatchmakingQueueConfigNotFound");
            if (input == GenericErrorCodesMatchmakingMatchNotFound) output = Json::Value("MatchmakingMatchNotFound");
            if (input == GenericErrorCodesMatchmakingTicketNotFound) output = Json::Value("MatchmakingTicketNotFound");
            if (input == GenericErrorCodesMatchmakingCreateTicketServerIdentityInvalid) output = Json::Value("MatchmakingCreateTicketServerIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingCreateTicketClientIdentityInvalid) output = Json::Value("MatchmakingCreateTicketClientIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingGetTicketUserMismatch) output = Json::Value("MatchmakingGetTicketUserMismatch");
            if (input == GenericErrorCodesMatchmakingJoinTicketServerIdentityInvalid) output = Json::Value("MatchmakingJoinTicketServerIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingJoinTicketUserIdentityMismatch) output = Json::Value("MatchmakingJoinTicketUserIdentityMismatch");
            if (input == GenericErrorCodesMatchmakingCancelTicketServerIdentityInvalid) output = Json::Value("MatchmakingCancelTicketServerIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingCancelTicketUserIdentityMismatch) output = Json::Value("MatchmakingCancelTicketUserIdentityMismatch");
            if (input == GenericErrorCodesMatchmakingGetMatchIdentityMismatch) output = Json::Value("MatchmakingGetMatchIdentityMismatch");
            if (input == GenericErrorCodesMatchmakingPlayerIdentityMismatch) output = Json::Value("MatchmakingPlayerIdentityMismatch");
            if (input == GenericErrorCodesMatchmakingAlreadyJoinedTicket) output = Json::Value("MatchmakingAlreadyJoinedTicket");
            if (input == GenericErrorCodesMatchmakingTicketAlreadyCompleted) output = Json::Value("MatchmakingTicketAlreadyCompleted");
            if (input == GenericErrorCodesMatchmakingQueueNameInvalid) output = Json::Value("MatchmakingQueueNameInvalid");
            if (input == GenericErrorCodesMatchmakingQueueConfigInvalid) output = Json::Value("MatchmakingQueueConfigInvalid");
            if (input == GenericErrorCodesMatchmakingMemberProfileInvalid) output = Json::Value("MatchmakingMemberProfileInvalid");
            if (input == GenericErrorCodesWriteAttemptedDuringExport) output = Json::Value("WriteAttemptedDuringExport");
            if (input == GenericErrorCodesNintendoSwitchDeviceIdNotLinked) output = Json::Value("NintendoSwitchDeviceIdNotLinked");
            if (input == GenericErrorCodesMatchmakingNotEnabled) output = Json::Value("MatchmakingNotEnabled");
            if (input == GenericErrorCodesMatchmakingGetStatisticsIdentityInvalid) output = Json::Value("MatchmakingGetStatisticsIdentityInvalid");
            if (input == GenericErrorCodesMatchmakingStatisticsIdMissing) output = Json::Value("MatchmakingStatisticsIdMissing");
        }
        inline void FromJsonEnum(const Json::Value& input, GenericErrorCodes& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Success") output = GenericErrorCodesSuccess;
            if (inputStr == "UnkownError") output = GenericErrorCodesUnkownError;
            if (inputStr == "InvalidParams") output = GenericErrorCodesInvalidParams;
            if (inputStr == "AccountNotFound") output = GenericErrorCodesAccountNotFound;
            if (inputStr == "AccountBanned") output = GenericErrorCodesAccountBanned;
            if (inputStr == "InvalidUsernameOrPassword") output = GenericErrorCodesInvalidUsernameOrPassword;
            if (inputStr == "InvalidTitleId") output = GenericErrorCodesInvalidTitleId;
            if (inputStr == "InvalidEmailAddress") output = GenericErrorCodesInvalidEmailAddress;
            if (inputStr == "EmailAddressNotAvailable") output = GenericErrorCodesEmailAddressNotAvailable;
            if (inputStr == "InvalidUsername") output = GenericErrorCodesInvalidUsername;
            if (inputStr == "InvalidPassword") output = GenericErrorCodesInvalidPassword;
            if (inputStr == "UsernameNotAvailable") output = GenericErrorCodesUsernameNotAvailable;
            if (inputStr == "InvalidSteamTicket") output = GenericErrorCodesInvalidSteamTicket;
            if (inputStr == "AccountAlreadyLinked") output = GenericErrorCodesAccountAlreadyLinked;
            if (inputStr == "LinkedAccountAlreadyClaimed") output = GenericErrorCodesLinkedAccountAlreadyClaimed;
            if (inputStr == "InvalidFacebookToken") output = GenericErrorCodesInvalidFacebookToken;
            if (inputStr == "AccountNotLinked") output = GenericErrorCodesAccountNotLinked;
            if (inputStr == "FailedByPaymentProvider") output = GenericErrorCodesFailedByPaymentProvider;
            if (inputStr == "CouponCodeNotFound") output = GenericErrorCodesCouponCodeNotFound;
            if (inputStr == "InvalidContainerItem") output = GenericErrorCodesInvalidContainerItem;
            if (inputStr == "ContainerNotOwned") output = GenericErrorCodesContainerNotOwned;
            if (inputStr == "KeyNotOwned") output = GenericErrorCodesKeyNotOwned;
            if (inputStr == "InvalidItemIdInTable") output = GenericErrorCodesInvalidItemIdInTable;
            if (inputStr == "InvalidReceipt") output = GenericErrorCodesInvalidReceipt;
            if (inputStr == "ReceiptAlreadyUsed") output = GenericErrorCodesReceiptAlreadyUsed;
            if (inputStr == "ReceiptCancelled") output = GenericErrorCodesReceiptCancelled;
            if (inputStr == "GameNotFound") output = GenericErrorCodesGameNotFound;
            if (inputStr == "GameModeNotFound") output = GenericErrorCodesGameModeNotFound;
            if (inputStr == "InvalidGoogleToken") output = GenericErrorCodesInvalidGoogleToken;
            if (inputStr == "UserIsNotPartOfDeveloper") output = GenericErrorCodesUserIsNotPartOfDeveloper;
            if (inputStr == "InvalidTitleForDeveloper") output = GenericErrorCodesInvalidTitleForDeveloper;
            if (inputStr == "TitleNameConflicts") output = GenericErrorCodesTitleNameConflicts;
            if (inputStr == "UserisNotValid") output = GenericErrorCodesUserisNotValid;
            if (inputStr == "ValueAlreadyExists") output = GenericErrorCodesValueAlreadyExists;
            if (inputStr == "BuildNotFound") output = GenericErrorCodesBuildNotFound;
            if (inputStr == "PlayerNotInGame") output = GenericErrorCodesPlayerNotInGame;
            if (inputStr == "InvalidTicket") output = GenericErrorCodesInvalidTicket;
            if (inputStr == "InvalidDeveloper") output = GenericErrorCodesInvalidDeveloper;
            if (inputStr == "InvalidOrderInfo") output = GenericErrorCodesInvalidOrderInfo;
            if (inputStr == "RegistrationIncomplete") output = GenericErrorCodesRegistrationIncomplete;
            if (inputStr == "InvalidPlatform") output = GenericErrorCodesInvalidPlatform;
            if (inputStr == "UnknownError") output = GenericErrorCodesUnknownError;
            if (inputStr == "SteamApplicationNotOwned") output = GenericErrorCodesSteamApplicationNotOwned;
            if (inputStr == "WrongSteamAccount") output = GenericErrorCodesWrongSteamAccount;
            if (inputStr == "TitleNotActivated") output = GenericErrorCodesTitleNotActivated;
            if (inputStr == "RegistrationSessionNotFound") output = GenericErrorCodesRegistrationSessionNotFound;
            if (inputStr == "NoSuchMod") output = GenericErrorCodesNoSuchMod;
            if (inputStr == "FileNotFound") output = GenericErrorCodesFileNotFound;
            if (inputStr == "DuplicateEmail") output = GenericErrorCodesDuplicateEmail;
            if (inputStr == "ItemNotFound") output = GenericErrorCodesItemNotFound;
            if (inputStr == "ItemNotOwned") output = GenericErrorCodesItemNotOwned;
            if (inputStr == "ItemNotRecycleable") output = GenericErrorCodesItemNotRecycleable;
            if (inputStr == "ItemNotAffordable") output = GenericErrorCodesItemNotAffordable;
            if (inputStr == "InvalidVirtualCurrency") output = GenericErrorCodesInvalidVirtualCurrency;
            if (inputStr == "WrongVirtualCurrency") output = GenericErrorCodesWrongVirtualCurrency;
            if (inputStr == "WrongPrice") output = GenericErrorCodesWrongPrice;
            if (inputStr == "NonPositiveValue") output = GenericErrorCodesNonPositiveValue;
            if (inputStr == "InvalidRegion") output = GenericErrorCodesInvalidRegion;
            if (inputStr == "RegionAtCapacity") output = GenericErrorCodesRegionAtCapacity;
            if (inputStr == "ServerFailedToStart") output = GenericErrorCodesServerFailedToStart;
            if (inputStr == "NameNotAvailable") output = GenericErrorCodesNameNotAvailable;
            if (inputStr == "InsufficientFunds") output = GenericErrorCodesInsufficientFunds;
            if (inputStr == "InvalidDeviceID") output = GenericErrorCodesInvalidDeviceID;
            if (inputStr == "InvalidPushNotificationToken") output = GenericErrorCodesInvalidPushNotificationToken;
            if (inputStr == "NoRemainingUses") output = GenericErrorCodesNoRemainingUses;
            if (inputStr == "InvalidPaymentProvider") output = GenericErrorCodesInvalidPaymentProvider;
            if (inputStr == "PurchaseInitializationFailure") output = GenericErrorCodesPurchaseInitializationFailure;
            if (inputStr == "DuplicateUsername") output = GenericErrorCodesDuplicateUsername;
            if (inputStr == "InvalidBuyerInfo") output = GenericErrorCodesInvalidBuyerInfo;
            if (inputStr == "NoGameModeParamsSet") output = GenericErrorCodesNoGameModeParamsSet;
            if (inputStr == "BodyTooLarge") output = GenericErrorCodesBodyTooLarge;
            if (inputStr == "ReservedWordInBody") output = GenericErrorCodesReservedWordInBody;
            if (inputStr == "InvalidTypeInBody") output = GenericErrorCodesInvalidTypeInBody;
            if (inputStr == "InvalidRequest") output = GenericErrorCodesInvalidRequest;
            if (inputStr == "ReservedEventName") output = GenericErrorCodesReservedEventName;
            if (inputStr == "InvalidUserStatistics") output = GenericErrorCodesInvalidUserStatistics;
            if (inputStr == "NotAuthenticated") output = GenericErrorCodesNotAuthenticated;
            if (inputStr == "StreamAlreadyExists") output = GenericErrorCodesStreamAlreadyExists;
            if (inputStr == "ErrorCreatingStream") output = GenericErrorCodesErrorCreatingStream;
            if (inputStr == "StreamNotFound") output = GenericErrorCodesStreamNotFound;
            if (inputStr == "InvalidAccount") output = GenericErrorCodesInvalidAccount;
            if (inputStr == "PurchaseDoesNotExist") output = GenericErrorCodesPurchaseDoesNotExist;
            if (inputStr == "InvalidPurchaseTransactionStatus") output = GenericErrorCodesInvalidPurchaseTransactionStatus;
            if (inputStr == "APINotEnabledForGameClientAccess") output = GenericErrorCodesAPINotEnabledForGameClientAccess;
            if (inputStr == "NoPushNotificationARNForTitle") output = GenericErrorCodesNoPushNotificationARNForTitle;
            if (inputStr == "BuildAlreadyExists") output = GenericErrorCodesBuildAlreadyExists;
            if (inputStr == "BuildPackageDoesNotExist") output = GenericErrorCodesBuildPackageDoesNotExist;
            if (inputStr == "CustomAnalyticsEventsNotEnabledForTitle") output = GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle;
            if (inputStr == "InvalidSharedGroupId") output = GenericErrorCodesInvalidSharedGroupId;
            if (inputStr == "NotAuthorized") output = GenericErrorCodesNotAuthorized;
            if (inputStr == "MissingTitleGoogleProperties") output = GenericErrorCodesMissingTitleGoogleProperties;
            if (inputStr == "InvalidItemProperties") output = GenericErrorCodesInvalidItemProperties;
            if (inputStr == "InvalidPSNAuthCode") output = GenericErrorCodesInvalidPSNAuthCode;
            if (inputStr == "InvalidItemId") output = GenericErrorCodesInvalidItemId;
            if (inputStr == "PushNotEnabledForAccount") output = GenericErrorCodesPushNotEnabledForAccount;
            if (inputStr == "PushServiceError") output = GenericErrorCodesPushServiceError;
            if (inputStr == "ReceiptDoesNotContainInAppItems") output = GenericErrorCodesReceiptDoesNotContainInAppItems;
            if (inputStr == "ReceiptContainsMultipleInAppItems") output = GenericErrorCodesReceiptContainsMultipleInAppItems;
            if (inputStr == "InvalidBundleID") output = GenericErrorCodesInvalidBundleID;
            if (inputStr == "JavascriptException") output = GenericErrorCodesJavascriptException;
            if (inputStr == "InvalidSessionTicket") output = GenericErrorCodesInvalidSessionTicket;
            if (inputStr == "UnableToConnectToDatabase") output = GenericErrorCodesUnableToConnectToDatabase;
            if (inputStr == "InternalServerError") output = GenericErrorCodesInternalServerError;
            if (inputStr == "InvalidReportDate") output = GenericErrorCodesInvalidReportDate;
            if (inputStr == "ReportNotAvailable") output = GenericErrorCodesReportNotAvailable;
            if (inputStr == "DatabaseThroughputExceeded") output = GenericErrorCodesDatabaseThroughputExceeded;
            if (inputStr == "InvalidGameTicket") output = GenericErrorCodesInvalidGameTicket;
            if (inputStr == "ExpiredGameTicket") output = GenericErrorCodesExpiredGameTicket;
            if (inputStr == "GameTicketDoesNotMatchLobby") output = GenericErrorCodesGameTicketDoesNotMatchLobby;
            if (inputStr == "LinkedDeviceAlreadyClaimed") output = GenericErrorCodesLinkedDeviceAlreadyClaimed;
            if (inputStr == "DeviceAlreadyLinked") output = GenericErrorCodesDeviceAlreadyLinked;
            if (inputStr == "DeviceNotLinked") output = GenericErrorCodesDeviceNotLinked;
            if (inputStr == "PartialFailure") output = GenericErrorCodesPartialFailure;
            if (inputStr == "PublisherNotSet") output = GenericErrorCodesPublisherNotSet;
            if (inputStr == "ServiceUnavailable") output = GenericErrorCodesServiceUnavailable;
            if (inputStr == "VersionNotFound") output = GenericErrorCodesVersionNotFound;
            if (inputStr == "RevisionNotFound") output = GenericErrorCodesRevisionNotFound;
            if (inputStr == "InvalidPublisherId") output = GenericErrorCodesInvalidPublisherId;
            if (inputStr == "DownstreamServiceUnavailable") output = GenericErrorCodesDownstreamServiceUnavailable;
            if (inputStr == "APINotIncludedInTitleUsageTier") output = GenericErrorCodesAPINotIncludedInTitleUsageTier;
            if (inputStr == "DAULimitExceeded") output = GenericErrorCodesDAULimitExceeded;
            if (inputStr == "APIRequestLimitExceeded") output = GenericErrorCodesAPIRequestLimitExceeded;
            if (inputStr == "InvalidAPIEndpoint") output = GenericErrorCodesInvalidAPIEndpoint;
            if (inputStr == "BuildNotAvailable") output = GenericErrorCodesBuildNotAvailable;
            if (inputStr == "ConcurrentEditError") output = GenericErrorCodesConcurrentEditError;
            if (inputStr == "ContentNotFound") output = GenericErrorCodesContentNotFound;
            if (inputStr == "CharacterNotFound") output = GenericErrorCodesCharacterNotFound;
            if (inputStr == "CloudScriptNotFound") output = GenericErrorCodesCloudScriptNotFound;
            if (inputStr == "ContentQuotaExceeded") output = GenericErrorCodesContentQuotaExceeded;
            if (inputStr == "InvalidCharacterStatistics") output = GenericErrorCodesInvalidCharacterStatistics;
            if (inputStr == "PhotonNotEnabledForTitle") output = GenericErrorCodesPhotonNotEnabledForTitle;
            if (inputStr == "PhotonApplicationNotFound") output = GenericErrorCodesPhotonApplicationNotFound;
            if (inputStr == "PhotonApplicationNotAssociatedWithTitle") output = GenericErrorCodesPhotonApplicationNotAssociatedWithTitle;
            if (inputStr == "InvalidEmailOrPassword") output = GenericErrorCodesInvalidEmailOrPassword;
            if (inputStr == "FacebookAPIError") output = GenericErrorCodesFacebookAPIError;
            if (inputStr == "InvalidContentType") output = GenericErrorCodesInvalidContentType;
            if (inputStr == "KeyLengthExceeded") output = GenericErrorCodesKeyLengthExceeded;
            if (inputStr == "DataLengthExceeded") output = GenericErrorCodesDataLengthExceeded;
            if (inputStr == "TooManyKeys") output = GenericErrorCodesTooManyKeys;
            if (inputStr == "FreeTierCannotHaveVirtualCurrency") output = GenericErrorCodesFreeTierCannotHaveVirtualCurrency;
            if (inputStr == "MissingAmazonSharedKey") output = GenericErrorCodesMissingAmazonSharedKey;
            if (inputStr == "AmazonValidationError") output = GenericErrorCodesAmazonValidationError;
            if (inputStr == "InvalidPSNIssuerId") output = GenericErrorCodesInvalidPSNIssuerId;
            if (inputStr == "PSNInaccessible") output = GenericErrorCodesPSNInaccessible;
            if (inputStr == "ExpiredAuthToken") output = GenericErrorCodesExpiredAuthToken;
            if (inputStr == "FailedToGetEntitlements") output = GenericErrorCodesFailedToGetEntitlements;
            if (inputStr == "FailedToConsumeEntitlement") output = GenericErrorCodesFailedToConsumeEntitlement;
            if (inputStr == "TradeAcceptingUserNotAllowed") output = GenericErrorCodesTradeAcceptingUserNotAllowed;
            if (inputStr == "TradeInventoryItemIsAssignedToCharacter") output = GenericErrorCodesTradeInventoryItemIsAssignedToCharacter;
            if (inputStr == "TradeInventoryItemIsBundle") output = GenericErrorCodesTradeInventoryItemIsBundle;
            if (inputStr == "TradeStatusNotValidForCancelling") output = GenericErrorCodesTradeStatusNotValidForCancelling;
            if (inputStr == "TradeStatusNotValidForAccepting") output = GenericErrorCodesTradeStatusNotValidForAccepting;
            if (inputStr == "TradeDoesNotExist") output = GenericErrorCodesTradeDoesNotExist;
            if (inputStr == "TradeCancelled") output = GenericErrorCodesTradeCancelled;
            if (inputStr == "TradeAlreadyFilled") output = GenericErrorCodesTradeAlreadyFilled;
            if (inputStr == "TradeWaitForStatusTimeout") output = GenericErrorCodesTradeWaitForStatusTimeout;
            if (inputStr == "TradeInventoryItemExpired") output = GenericErrorCodesTradeInventoryItemExpired;
            if (inputStr == "TradeMissingOfferedAndAcceptedItems") output = GenericErrorCodesTradeMissingOfferedAndAcceptedItems;
            if (inputStr == "TradeAcceptedItemIsBundle") output = GenericErrorCodesTradeAcceptedItemIsBundle;
            if (inputStr == "TradeAcceptedItemIsStackable") output = GenericErrorCodesTradeAcceptedItemIsStackable;
            if (inputStr == "TradeInventoryItemInvalidStatus") output = GenericErrorCodesTradeInventoryItemInvalidStatus;
            if (inputStr == "TradeAcceptedCatalogItemInvalid") output = GenericErrorCodesTradeAcceptedCatalogItemInvalid;
            if (inputStr == "TradeAllowedUsersInvalid") output = GenericErrorCodesTradeAllowedUsersInvalid;
            if (inputStr == "TradeInventoryItemDoesNotExist") output = GenericErrorCodesTradeInventoryItemDoesNotExist;
            if (inputStr == "TradeInventoryItemIsConsumed") output = GenericErrorCodesTradeInventoryItemIsConsumed;
            if (inputStr == "TradeInventoryItemIsStackable") output = GenericErrorCodesTradeInventoryItemIsStackable;
            if (inputStr == "TradeAcceptedItemsMismatch") output = GenericErrorCodesTradeAcceptedItemsMismatch;
            if (inputStr == "InvalidKongregateToken") output = GenericErrorCodesInvalidKongregateToken;
            if (inputStr == "FeatureNotConfiguredForTitle") output = GenericErrorCodesFeatureNotConfiguredForTitle;
            if (inputStr == "NoMatchingCatalogItemForReceipt") output = GenericErrorCodesNoMatchingCatalogItemForReceipt;
            if (inputStr == "InvalidCurrencyCode") output = GenericErrorCodesInvalidCurrencyCode;
            if (inputStr == "NoRealMoneyPriceForCatalogItem") output = GenericErrorCodesNoRealMoneyPriceForCatalogItem;
            if (inputStr == "TradeInventoryItemIsNotTradable") output = GenericErrorCodesTradeInventoryItemIsNotTradable;
            if (inputStr == "TradeAcceptedCatalogItemIsNotTradable") output = GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable;
            if (inputStr == "UsersAlreadyFriends") output = GenericErrorCodesUsersAlreadyFriends;
            if (inputStr == "LinkedIdentifierAlreadyClaimed") output = GenericErrorCodesLinkedIdentifierAlreadyClaimed;
            if (inputStr == "CustomIdNotLinked") output = GenericErrorCodesCustomIdNotLinked;
            if (inputStr == "TotalDataSizeExceeded") output = GenericErrorCodesTotalDataSizeExceeded;
            if (inputStr == "DeleteKeyConflict") output = GenericErrorCodesDeleteKeyConflict;
            if (inputStr == "InvalidXboxLiveToken") output = GenericErrorCodesInvalidXboxLiveToken;
            if (inputStr == "ExpiredXboxLiveToken") output = GenericErrorCodesExpiredXboxLiveToken;
            if (inputStr == "ResettableStatisticVersionRequired") output = GenericErrorCodesResettableStatisticVersionRequired;
            if (inputStr == "NotAuthorizedByTitle") output = GenericErrorCodesNotAuthorizedByTitle;
            if (inputStr == "NoPartnerEnabled") output = GenericErrorCodesNoPartnerEnabled;
            if (inputStr == "InvalidPartnerResponse") output = GenericErrorCodesInvalidPartnerResponse;
            if (inputStr == "APINotEnabledForGameServerAccess") output = GenericErrorCodesAPINotEnabledForGameServerAccess;
            if (inputStr == "StatisticNotFound") output = GenericErrorCodesStatisticNotFound;
            if (inputStr == "StatisticNameConflict") output = GenericErrorCodesStatisticNameConflict;
            if (inputStr == "StatisticVersionClosedForWrites") output = GenericErrorCodesStatisticVersionClosedForWrites;
            if (inputStr == "StatisticVersionInvalid") output = GenericErrorCodesStatisticVersionInvalid;
            if (inputStr == "APIClientRequestRateLimitExceeded") output = GenericErrorCodesAPIClientRequestRateLimitExceeded;
            if (inputStr == "InvalidJSONContent") output = GenericErrorCodesInvalidJSONContent;
            if (inputStr == "InvalidDropTable") output = GenericErrorCodesInvalidDropTable;
            if (inputStr == "StatisticVersionAlreadyIncrementedForScheduledInterval") output = GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval;
            if (inputStr == "StatisticCountLimitExceeded") output = GenericErrorCodesStatisticCountLimitExceeded;
            if (inputStr == "StatisticVersionIncrementRateExceeded") output = GenericErrorCodesStatisticVersionIncrementRateExceeded;
            if (inputStr == "ContainerKeyInvalid") output = GenericErrorCodesContainerKeyInvalid;
            if (inputStr == "CloudScriptExecutionTimeLimitExceeded") output = GenericErrorCodesCloudScriptExecutionTimeLimitExceeded;
            if (inputStr == "NoWritePermissionsForEvent") output = GenericErrorCodesNoWritePermissionsForEvent;
            if (inputStr == "CloudScriptFunctionArgumentSizeExceeded") output = GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded;
            if (inputStr == "CloudScriptAPIRequestCountExceeded") output = GenericErrorCodesCloudScriptAPIRequestCountExceeded;
            if (inputStr == "CloudScriptAPIRequestError") output = GenericErrorCodesCloudScriptAPIRequestError;
            if (inputStr == "CloudScriptHTTPRequestError") output = GenericErrorCodesCloudScriptHTTPRequestError;
            if (inputStr == "InsufficientGuildRole") output = GenericErrorCodesInsufficientGuildRole;
            if (inputStr == "GuildNotFound") output = GenericErrorCodesGuildNotFound;
            if (inputStr == "OverLimit") output = GenericErrorCodesOverLimit;
            if (inputStr == "EventNotFound") output = GenericErrorCodesEventNotFound;
            if (inputStr == "InvalidEventField") output = GenericErrorCodesInvalidEventField;
            if (inputStr == "InvalidEventName") output = GenericErrorCodesInvalidEventName;
            if (inputStr == "CatalogNotConfigured") output = GenericErrorCodesCatalogNotConfigured;
            if (inputStr == "OperationNotSupportedForPlatform") output = GenericErrorCodesOperationNotSupportedForPlatform;
            if (inputStr == "SegmentNotFound") output = GenericErrorCodesSegmentNotFound;
            if (inputStr == "StoreNotFound") output = GenericErrorCodesStoreNotFound;
            if (inputStr == "InvalidStatisticName") output = GenericErrorCodesInvalidStatisticName;
            if (inputStr == "TitleNotQualifiedForLimit") output = GenericErrorCodesTitleNotQualifiedForLimit;
            if (inputStr == "InvalidServiceLimitLevel") output = GenericErrorCodesInvalidServiceLimitLevel;
            if (inputStr == "ServiceLimitLevelInTransition") output = GenericErrorCodesServiceLimitLevelInTransition;
            if (inputStr == "CouponAlreadyRedeemed") output = GenericErrorCodesCouponAlreadyRedeemed;
            if (inputStr == "GameServerBuildSizeLimitExceeded") output = GenericErrorCodesGameServerBuildSizeLimitExceeded;
            if (inputStr == "GameServerBuildCountLimitExceeded") output = GenericErrorCodesGameServerBuildCountLimitExceeded;
            if (inputStr == "VirtualCurrencyCountLimitExceeded") output = GenericErrorCodesVirtualCurrencyCountLimitExceeded;
            if (inputStr == "VirtualCurrencyCodeExists") output = GenericErrorCodesVirtualCurrencyCodeExists;
            if (inputStr == "TitleNewsItemCountLimitExceeded") output = GenericErrorCodesTitleNewsItemCountLimitExceeded;
            if (inputStr == "InvalidTwitchToken") output = GenericErrorCodesInvalidTwitchToken;
            if (inputStr == "TwitchResponseError") output = GenericErrorCodesTwitchResponseError;
            if (inputStr == "ProfaneDisplayName") output = GenericErrorCodesProfaneDisplayName;
            if (inputStr == "UserAlreadyAdded") output = GenericErrorCodesUserAlreadyAdded;
            if (inputStr == "InvalidVirtualCurrencyCode") output = GenericErrorCodesInvalidVirtualCurrencyCode;
            if (inputStr == "VirtualCurrencyCannotBeDeleted") output = GenericErrorCodesVirtualCurrencyCannotBeDeleted;
            if (inputStr == "IdentifierAlreadyClaimed") output = GenericErrorCodesIdentifierAlreadyClaimed;
            if (inputStr == "IdentifierNotLinked") output = GenericErrorCodesIdentifierNotLinked;
            if (inputStr == "InvalidContinuationToken") output = GenericErrorCodesInvalidContinuationToken;
            if (inputStr == "ExpiredContinuationToken") output = GenericErrorCodesExpiredContinuationToken;
            if (inputStr == "InvalidSegment") output = GenericErrorCodesInvalidSegment;
            if (inputStr == "InvalidSessionId") output = GenericErrorCodesInvalidSessionId;
            if (inputStr == "SessionLogNotFound") output = GenericErrorCodesSessionLogNotFound;
            if (inputStr == "InvalidSearchTerm") output = GenericErrorCodesInvalidSearchTerm;
            if (inputStr == "TwoFactorAuthenticationTokenRequired") output = GenericErrorCodesTwoFactorAuthenticationTokenRequired;
            if (inputStr == "GameServerHostCountLimitExceeded") output = GenericErrorCodesGameServerHostCountLimitExceeded;
            if (inputStr == "PlayerTagCountLimitExceeded") output = GenericErrorCodesPlayerTagCountLimitExceeded;
            if (inputStr == "RequestAlreadyRunning") output = GenericErrorCodesRequestAlreadyRunning;
            if (inputStr == "ActionGroupNotFound") output = GenericErrorCodesActionGroupNotFound;
            if (inputStr == "MaximumSegmentBulkActionJobsRunning") output = GenericErrorCodesMaximumSegmentBulkActionJobsRunning;
            if (inputStr == "NoActionsOnPlayersInSegmentJob") output = GenericErrorCodesNoActionsOnPlayersInSegmentJob;
            if (inputStr == "DuplicateStatisticName") output = GenericErrorCodesDuplicateStatisticName;
            if (inputStr == "ScheduledTaskNameConflict") output = GenericErrorCodesScheduledTaskNameConflict;
            if (inputStr == "ScheduledTaskCreateConflict") output = GenericErrorCodesScheduledTaskCreateConflict;
            if (inputStr == "InvalidScheduledTaskName") output = GenericErrorCodesInvalidScheduledTaskName;
            if (inputStr == "InvalidTaskSchedule") output = GenericErrorCodesInvalidTaskSchedule;
            if (inputStr == "SteamNotEnabledForTitle") output = GenericErrorCodesSteamNotEnabledForTitle;
            if (inputStr == "LimitNotAnUpgradeOption") output = GenericErrorCodesLimitNotAnUpgradeOption;
            if (inputStr == "NoSecretKeyEnabledForCloudScript") output = GenericErrorCodesNoSecretKeyEnabledForCloudScript;
            if (inputStr == "TaskNotFound") output = GenericErrorCodesTaskNotFound;
            if (inputStr == "TaskInstanceNotFound") output = GenericErrorCodesTaskInstanceNotFound;
            if (inputStr == "InvalidIdentityProviderId") output = GenericErrorCodesInvalidIdentityProviderId;
            if (inputStr == "MisconfiguredIdentityProvider") output = GenericErrorCodesMisconfiguredIdentityProvider;
            if (inputStr == "InvalidScheduledTaskType") output = GenericErrorCodesInvalidScheduledTaskType;
            if (inputStr == "BillingInformationRequired") output = GenericErrorCodesBillingInformationRequired;
            if (inputStr == "LimitedEditionItemUnavailable") output = GenericErrorCodesLimitedEditionItemUnavailable;
            if (inputStr == "InvalidAdPlacementAndReward") output = GenericErrorCodesInvalidAdPlacementAndReward;
            if (inputStr == "AllAdPlacementViewsAlreadyConsumed") output = GenericErrorCodesAllAdPlacementViewsAlreadyConsumed;
            if (inputStr == "GoogleOAuthNotConfiguredForTitle") output = GenericErrorCodesGoogleOAuthNotConfiguredForTitle;
            if (inputStr == "GoogleOAuthError") output = GenericErrorCodesGoogleOAuthError;
            if (inputStr == "UserNotFriend") output = GenericErrorCodesUserNotFriend;
            if (inputStr == "InvalidSignature") output = GenericErrorCodesInvalidSignature;
            if (inputStr == "InvalidPublicKey") output = GenericErrorCodesInvalidPublicKey;
            if (inputStr == "GoogleOAuthNoIdTokenIncludedInResponse") output = GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse;
            if (inputStr == "StatisticUpdateInProgress") output = GenericErrorCodesStatisticUpdateInProgress;
            if (inputStr == "LeaderboardVersionNotAvailable") output = GenericErrorCodesLeaderboardVersionNotAvailable;
            if (inputStr == "StatisticAlreadyHasPrizeTable") output = GenericErrorCodesStatisticAlreadyHasPrizeTable;
            if (inputStr == "PrizeTableHasOverlappingRanks") output = GenericErrorCodesPrizeTableHasOverlappingRanks;
            if (inputStr == "PrizeTableHasMissingRanks") output = GenericErrorCodesPrizeTableHasMissingRanks;
            if (inputStr == "PrizeTableRankStartsAtZero") output = GenericErrorCodesPrizeTableRankStartsAtZero;
            if (inputStr == "InvalidStatistic") output = GenericErrorCodesInvalidStatistic;
            if (inputStr == "ExpressionParseFailure") output = GenericErrorCodesExpressionParseFailure;
            if (inputStr == "ExpressionInvokeFailure") output = GenericErrorCodesExpressionInvokeFailure;
            if (inputStr == "ExpressionTooLong") output = GenericErrorCodesExpressionTooLong;
            if (inputStr == "DataUpdateRateExceeded") output = GenericErrorCodesDataUpdateRateExceeded;
            if (inputStr == "RestrictedEmailDomain") output = GenericErrorCodesRestrictedEmailDomain;
            if (inputStr == "EncryptionKeyDisabled") output = GenericErrorCodesEncryptionKeyDisabled;
            if (inputStr == "EncryptionKeyMissing") output = GenericErrorCodesEncryptionKeyMissing;
            if (inputStr == "EncryptionKeyBroken") output = GenericErrorCodesEncryptionKeyBroken;
            if (inputStr == "NoSharedSecretKeyConfigured") output = GenericErrorCodesNoSharedSecretKeyConfigured;
            if (inputStr == "SecretKeyNotFound") output = GenericErrorCodesSecretKeyNotFound;
            if (inputStr == "PlayerSecretAlreadyConfigured") output = GenericErrorCodesPlayerSecretAlreadyConfigured;
            if (inputStr == "APIRequestsDisabledForTitle") output = GenericErrorCodesAPIRequestsDisabledForTitle;
            if (inputStr == "InvalidSharedSecretKey") output = GenericErrorCodesInvalidSharedSecretKey;
            if (inputStr == "PrizeTableHasNoRanks") output = GenericErrorCodesPrizeTableHasNoRanks;
            if (inputStr == "ProfileDoesNotExist") output = GenericErrorCodesProfileDoesNotExist;
            if (inputStr == "ContentS3OriginBucketNotConfigured") output = GenericErrorCodesContentS3OriginBucketNotConfigured;
            if (inputStr == "InvalidEnvironmentForReceipt") output = GenericErrorCodesInvalidEnvironmentForReceipt;
            if (inputStr == "EncryptedRequestNotAllowed") output = GenericErrorCodesEncryptedRequestNotAllowed;
            if (inputStr == "SignedRequestNotAllowed") output = GenericErrorCodesSignedRequestNotAllowed;
            if (inputStr == "RequestViewConstraintParamsNotAllowed") output = GenericErrorCodesRequestViewConstraintParamsNotAllowed;
            if (inputStr == "BadPartnerConfiguration") output = GenericErrorCodesBadPartnerConfiguration;
            if (inputStr == "XboxBPCertificateFailure") output = GenericErrorCodesXboxBPCertificateFailure;
            if (inputStr == "XboxXASSExchangeFailure") output = GenericErrorCodesXboxXASSExchangeFailure;
            if (inputStr == "InvalidEntityId") output = GenericErrorCodesInvalidEntityId;
            if (inputStr == "StatisticValueAggregationOverflow") output = GenericErrorCodesStatisticValueAggregationOverflow;
            if (inputStr == "EmailMessageFromAddressIsMissing") output = GenericErrorCodesEmailMessageFromAddressIsMissing;
            if (inputStr == "EmailMessageToAddressIsMissing") output = GenericErrorCodesEmailMessageToAddressIsMissing;
            if (inputStr == "SmtpServerAuthenticationError") output = GenericErrorCodesSmtpServerAuthenticationError;
            if (inputStr == "SmtpServerLimitExceeded") output = GenericErrorCodesSmtpServerLimitExceeded;
            if (inputStr == "SmtpServerInsufficientStorage") output = GenericErrorCodesSmtpServerInsufficientStorage;
            if (inputStr == "SmtpServerCommunicationError") output = GenericErrorCodesSmtpServerCommunicationError;
            if (inputStr == "SmtpServerGeneralFailure") output = GenericErrorCodesSmtpServerGeneralFailure;
            if (inputStr == "EmailClientTimeout") output = GenericErrorCodesEmailClientTimeout;
            if (inputStr == "EmailClientCanceledTask") output = GenericErrorCodesEmailClientCanceledTask;
            if (inputStr == "EmailTemplateMissing") output = GenericErrorCodesEmailTemplateMissing;
            if (inputStr == "InvalidHostForTitleId") output = GenericErrorCodesInvalidHostForTitleId;
            if (inputStr == "EmailConfirmationTokenDoesNotExist") output = GenericErrorCodesEmailConfirmationTokenDoesNotExist;
            if (inputStr == "EmailConfirmationTokenExpired") output = GenericErrorCodesEmailConfirmationTokenExpired;
            if (inputStr == "AccountDeleted") output = GenericErrorCodesAccountDeleted;
            if (inputStr == "PlayerSecretNotConfigured") output = GenericErrorCodesPlayerSecretNotConfigured;
            if (inputStr == "InvalidSignatureTime") output = GenericErrorCodesInvalidSignatureTime;
            if (inputStr == "NoContactEmailAddressFound") output = GenericErrorCodesNoContactEmailAddressFound;
            if (inputStr == "InvalidAuthToken") output = GenericErrorCodesInvalidAuthToken;
            if (inputStr == "AuthTokenDoesNotExist") output = GenericErrorCodesAuthTokenDoesNotExist;
            if (inputStr == "AuthTokenExpired") output = GenericErrorCodesAuthTokenExpired;
            if (inputStr == "AuthTokenAlreadyUsedToResetPassword") output = GenericErrorCodesAuthTokenAlreadyUsedToResetPassword;
            if (inputStr == "MembershipNameTooLong") output = GenericErrorCodesMembershipNameTooLong;
            if (inputStr == "MembershipNotFound") output = GenericErrorCodesMembershipNotFound;
            if (inputStr == "GoogleServiceAccountInvalid") output = GenericErrorCodesGoogleServiceAccountInvalid;
            if (inputStr == "GoogleServiceAccountParseFailure") output = GenericErrorCodesGoogleServiceAccountParseFailure;
            if (inputStr == "EntityTokenMissing") output = GenericErrorCodesEntityTokenMissing;
            if (inputStr == "EntityTokenInvalid") output = GenericErrorCodesEntityTokenInvalid;
            if (inputStr == "EntityTokenExpired") output = GenericErrorCodesEntityTokenExpired;
            if (inputStr == "EntityTokenRevoked") output = GenericErrorCodesEntityTokenRevoked;
            if (inputStr == "InvalidProductForSubscription") output = GenericErrorCodesInvalidProductForSubscription;
            if (inputStr == "XboxInaccessible") output = GenericErrorCodesXboxInaccessible;
            if (inputStr == "SubscriptionAlreadyTaken") output = GenericErrorCodesSubscriptionAlreadyTaken;
            if (inputStr == "SmtpAddonNotEnabled") output = GenericErrorCodesSmtpAddonNotEnabled;
            if (inputStr == "APIConcurrentRequestLimitExceeded") output = GenericErrorCodesAPIConcurrentRequestLimitExceeded;
            if (inputStr == "XboxRejectedXSTSExchangeRequest") output = GenericErrorCodesXboxRejectedXSTSExchangeRequest;
            if (inputStr == "VariableNotDefined") output = GenericErrorCodesVariableNotDefined;
            if (inputStr == "TemplateVersionNotDefined") output = GenericErrorCodesTemplateVersionNotDefined;
            if (inputStr == "FileTooLarge") output = GenericErrorCodesFileTooLarge;
            if (inputStr == "TitleDeleted") output = GenericErrorCodesTitleDeleted;
            if (inputStr == "TitleContainsUserAccounts") output = GenericErrorCodesTitleContainsUserAccounts;
            if (inputStr == "TitleDeletionPlayerCleanupFailure") output = GenericErrorCodesTitleDeletionPlayerCleanupFailure;
            if (inputStr == "EntityFileOperationPending") output = GenericErrorCodesEntityFileOperationPending;
            if (inputStr == "NoEntityFileOperationPending") output = GenericErrorCodesNoEntityFileOperationPending;
            if (inputStr == "EntityProfileVersionMismatch") output = GenericErrorCodesEntityProfileVersionMismatch;
            if (inputStr == "TemplateVersionTooOld") output = GenericErrorCodesTemplateVersionTooOld;
            if (inputStr == "MembershipDefinitionInUse") output = GenericErrorCodesMembershipDefinitionInUse;
            if (inputStr == "PaymentPageNotConfigured") output = GenericErrorCodesPaymentPageNotConfigured;
            if (inputStr == "FailedLoginAttemptRateLimitExceeded") output = GenericErrorCodesFailedLoginAttemptRateLimitExceeded;
            if (inputStr == "EntityBlockedByGroup") output = GenericErrorCodesEntityBlockedByGroup;
            if (inputStr == "RoleDoesNotExist") output = GenericErrorCodesRoleDoesNotExist;
            if (inputStr == "EntityIsAlreadyMember") output = GenericErrorCodesEntityIsAlreadyMember;
            if (inputStr == "DuplicateRoleId") output = GenericErrorCodesDuplicateRoleId;
            if (inputStr == "GroupInvitationNotFound") output = GenericErrorCodesGroupInvitationNotFound;
            if (inputStr == "GroupApplicationNotFound") output = GenericErrorCodesGroupApplicationNotFound;
            if (inputStr == "OutstandingInvitationAcceptedInstead") output = GenericErrorCodesOutstandingInvitationAcceptedInstead;
            if (inputStr == "OutstandingApplicationAcceptedInstead") output = GenericErrorCodesOutstandingApplicationAcceptedInstead;
            if (inputStr == "RoleIsGroupDefaultMember") output = GenericErrorCodesRoleIsGroupDefaultMember;
            if (inputStr == "RoleIsGroupAdmin") output = GenericErrorCodesRoleIsGroupAdmin;
            if (inputStr == "RoleNameNotAvailable") output = GenericErrorCodesRoleNameNotAvailable;
            if (inputStr == "GroupNameNotAvailable") output = GenericErrorCodesGroupNameNotAvailable;
            if (inputStr == "EmailReportAlreadySent") output = GenericErrorCodesEmailReportAlreadySent;
            if (inputStr == "EmailReportRecipientBlacklisted") output = GenericErrorCodesEmailReportRecipientBlacklisted;
            if (inputStr == "EventNamespaceNotAllowed") output = GenericErrorCodesEventNamespaceNotAllowed;
            if (inputStr == "EventEntityNotAllowed") output = GenericErrorCodesEventEntityNotAllowed;
            if (inputStr == "InvalidEntityType") output = GenericErrorCodesInvalidEntityType;
            if (inputStr == "NullTokenResultFromAad") output = GenericErrorCodesNullTokenResultFromAad;
            if (inputStr == "InvalidTokenResultFromAad") output = GenericErrorCodesInvalidTokenResultFromAad;
            if (inputStr == "NoValidCertificateForAad") output = GenericErrorCodesNoValidCertificateForAad;
            if (inputStr == "InvalidCertificateForAad") output = GenericErrorCodesInvalidCertificateForAad;
            if (inputStr == "DuplicateDropTableId") output = GenericErrorCodesDuplicateDropTableId;
            if (inputStr == "MultiplayerServerError") output = GenericErrorCodesMultiplayerServerError;
            if (inputStr == "MultiplayerServerTooManyRequests") output = GenericErrorCodesMultiplayerServerTooManyRequests;
            if (inputStr == "MultiplayerServerNoContent") output = GenericErrorCodesMultiplayerServerNoContent;
            if (inputStr == "MultiplayerServerBadRequest") output = GenericErrorCodesMultiplayerServerBadRequest;
            if (inputStr == "MultiplayerServerUnauthorized") output = GenericErrorCodesMultiplayerServerUnauthorized;
            if (inputStr == "MultiplayerServerForbidden") output = GenericErrorCodesMultiplayerServerForbidden;
            if (inputStr == "MultiplayerServerNotFound") output = GenericErrorCodesMultiplayerServerNotFound;
            if (inputStr == "MultiplayerServerConflict") output = GenericErrorCodesMultiplayerServerConflict;
            if (inputStr == "MultiplayerServerInternalServerError") output = GenericErrorCodesMultiplayerServerInternalServerError;
            if (inputStr == "MultiplayerServerUnavailable") output = GenericErrorCodesMultiplayerServerUnavailable;
            if (inputStr == "ExplicitContentDetected") output = GenericErrorCodesExplicitContentDetected;
            if (inputStr == "PIIContentDetected") output = GenericErrorCodesPIIContentDetected;
            if (inputStr == "InvalidScheduledTaskParameter") output = GenericErrorCodesInvalidScheduledTaskParameter;
            if (inputStr == "PerEntityEventRateLimitExceeded") output = GenericErrorCodesPerEntityEventRateLimitExceeded;
            if (inputStr == "TitleDefaultLanguageNotSet") output = GenericErrorCodesTitleDefaultLanguageNotSet;
            if (inputStr == "EmailTemplateMissingDefaultVersion") output = GenericErrorCodesEmailTemplateMissingDefaultVersion;
            if (inputStr == "FacebookInstantGamesIdNotLinked") output = GenericErrorCodesFacebookInstantGamesIdNotLinked;
            if (inputStr == "InvalidFacebookInstantGamesSignature") output = GenericErrorCodesInvalidFacebookInstantGamesSignature;
            if (inputStr == "FacebookInstantGamesAuthNotConfiguredForTitle") output = GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle;
            if (inputStr == "EntityProfileConstraintValidationFailed") output = GenericErrorCodesEntityProfileConstraintValidationFailed;
            if (inputStr == "PlayInsightsIngestionKeyPending") output = GenericErrorCodesPlayInsightsIngestionKeyPending;
            if (inputStr == "PlayInsightsIngestionKeyNotFound") output = GenericErrorCodesPlayInsightsIngestionKeyNotFound;
            if (inputStr == "StatisticTagRequired") output = GenericErrorCodesStatisticTagRequired;
            if (inputStr == "StatisticTagInvalid") output = GenericErrorCodesStatisticTagInvalid;
            if (inputStr == "MatchmakingEntityInvalid") output = GenericErrorCodesMatchmakingEntityInvalid;
            if (inputStr == "MatchmakingPlayerAttributesInvalid") output = GenericErrorCodesMatchmakingPlayerAttributesInvalid;
            if (inputStr == "MatchmakingCreateRequestMissing") output = GenericErrorCodesMatchmakingCreateRequestMissing;
            if (inputStr == "MatchmakingCreateRequestCreatorMissing") output = GenericErrorCodesMatchmakingCreateRequestCreatorMissing;
            if (inputStr == "MatchmakingCreateRequestCreatorIdMissing") output = GenericErrorCodesMatchmakingCreateRequestCreatorIdMissing;
            if (inputStr == "MatchmakingCreateRequestUserListMissing") output = GenericErrorCodesMatchmakingCreateRequestUserListMissing;
            if (inputStr == "MatchmakingCreateRequestGiveUpAfterInvalid") output = GenericErrorCodesMatchmakingCreateRequestGiveUpAfterInvalid;
            if (inputStr == "MatchmakingTicketIdMissing") output = GenericErrorCodesMatchmakingTicketIdMissing;
            if (inputStr == "MatchmakingMatchIdMissing") output = GenericErrorCodesMatchmakingMatchIdMissing;
            if (inputStr == "MatchmakingMatchIdIdMissing") output = GenericErrorCodesMatchmakingMatchIdIdMissing;
            if (inputStr == "MatchmakingQueueNameMissing") output = GenericErrorCodesMatchmakingQueueNameMissing;
            if (inputStr == "MatchmakingTitleIdMissing") output = GenericErrorCodesMatchmakingTitleIdMissing;
            if (inputStr == "MatchmakingTicketIdIdMissing") output = GenericErrorCodesMatchmakingTicketIdIdMissing;
            if (inputStr == "MatchmakingPlayerIdMissing") output = GenericErrorCodesMatchmakingPlayerIdMissing;
            if (inputStr == "MatchmakingJoinRequestUserMissing") output = GenericErrorCodesMatchmakingJoinRequestUserMissing;
            if (inputStr == "MatchmakingQueueConfigNotFound") output = GenericErrorCodesMatchmakingQueueConfigNotFound;
            if (inputStr == "MatchmakingMatchNotFound") output = GenericErrorCodesMatchmakingMatchNotFound;
            if (inputStr == "MatchmakingTicketNotFound") output = GenericErrorCodesMatchmakingTicketNotFound;
            if (inputStr == "MatchmakingCreateTicketServerIdentityInvalid") output = GenericErrorCodesMatchmakingCreateTicketServerIdentityInvalid;
            if (inputStr == "MatchmakingCreateTicketClientIdentityInvalid") output = GenericErrorCodesMatchmakingCreateTicketClientIdentityInvalid;
            if (inputStr == "MatchmakingGetTicketUserMismatch") output = GenericErrorCodesMatchmakingGetTicketUserMismatch;
            if (inputStr == "MatchmakingJoinTicketServerIdentityInvalid") output = GenericErrorCodesMatchmakingJoinTicketServerIdentityInvalid;
            if (inputStr == "MatchmakingJoinTicketUserIdentityMismatch") output = GenericErrorCodesMatchmakingJoinTicketUserIdentityMismatch;
            if (inputStr == "MatchmakingCancelTicketServerIdentityInvalid") output = GenericErrorCodesMatchmakingCancelTicketServerIdentityInvalid;
            if (inputStr == "MatchmakingCancelTicketUserIdentityMismatch") output = GenericErrorCodesMatchmakingCancelTicketUserIdentityMismatch;
            if (inputStr == "MatchmakingGetMatchIdentityMismatch") output = GenericErrorCodesMatchmakingGetMatchIdentityMismatch;
            if (inputStr == "MatchmakingPlayerIdentityMismatch") output = GenericErrorCodesMatchmakingPlayerIdentityMismatch;
            if (inputStr == "MatchmakingAlreadyJoinedTicket") output = GenericErrorCodesMatchmakingAlreadyJoinedTicket;
            if (inputStr == "MatchmakingTicketAlreadyCompleted") output = GenericErrorCodesMatchmakingTicketAlreadyCompleted;
            if (inputStr == "MatchmakingQueueNameInvalid") output = GenericErrorCodesMatchmakingQueueNameInvalid;
            if (inputStr == "MatchmakingQueueConfigInvalid") output = GenericErrorCodesMatchmakingQueueConfigInvalid;
            if (inputStr == "MatchmakingMemberProfileInvalid") output = GenericErrorCodesMatchmakingMemberProfileInvalid;
            if (inputStr == "WriteAttemptedDuringExport") output = GenericErrorCodesWriteAttemptedDuringExport;
            if (inputStr == "NintendoSwitchDeviceIdNotLinked") output = GenericErrorCodesNintendoSwitchDeviceIdNotLinked;
            if (inputStr == "MatchmakingNotEnabled") output = GenericErrorCodesMatchmakingNotEnabled;
            if (inputStr == "MatchmakingGetStatisticsIdentityInvalid") output = GenericErrorCodesMatchmakingGetStatisticsIdentityInvalid;
            if (inputStr == "MatchmakingStatisticsIdMissing") output = GenericErrorCodesMatchmakingStatisticsIdMissing;
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

        enum PushSetupPlatform
        {
            PushSetupPlatformGCM,
            PushSetupPlatformAPNS,
            PushSetupPlatformAPNS_SANDBOX
        };

        inline void ToJsonEnum(const PushSetupPlatform input, Json::Value& output)
        {
            if (input == PushSetupPlatformGCM) output = Json::Value("GCM");
            if (input == PushSetupPlatformAPNS) output = Json::Value("APNS");
            if (input == PushSetupPlatformAPNS_SANDBOX) output = Json::Value("APNS_SANDBOX");
        }
        inline void FromJsonEnum(const Json::Value& input, PushSetupPlatform& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "GCM") output = PushSetupPlatformGCM;
            if (inputStr == "APNS") output = PushSetupPlatformAPNS;
            if (inputStr == "APNS_SANDBOX") output = PushSetupPlatformAPNS_SANDBOX;
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

        enum ResolutionOutcome
        {
            ResolutionOutcomeRevoke,
            ResolutionOutcomeReinstate,
            ResolutionOutcomeManual
        };

        inline void ToJsonEnum(const ResolutionOutcome input, Json::Value& output)
        {
            if (input == ResolutionOutcomeRevoke) output = Json::Value("Revoke");
            if (input == ResolutionOutcomeReinstate) output = Json::Value("Reinstate");
            if (input == ResolutionOutcomeManual) output = Json::Value("Manual");
        }
        inline void FromJsonEnum(const Json::Value& input, ResolutionOutcome& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Revoke") output = ResolutionOutcomeRevoke;
            if (inputStr == "Reinstate") output = ResolutionOutcomeReinstate;
            if (inputStr == "Manual") output = ResolutionOutcomeManual;
        }

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        inline void ToJsonEnum(const ResultTableNodeType input, Json::Value& output)
        {
            if (input == ResultTableNodeTypeItemId) output = Json::Value("ItemId");
            if (input == ResultTableNodeTypeTableId) output = Json::Value("TableId");
        }
        inline void FromJsonEnum(const Json::Value& input, ResultTableNodeType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "ItemId") output = ResultTableNodeTypeItemId;
            if (inputStr == "TableId") output = ResultTableNodeTypeTableId;
        }

        enum ScheduledTaskType
        {
            ScheduledTaskTypeCloudScript,
            ScheduledTaskTypeActionsOnPlayerSegment
        };

        inline void ToJsonEnum(const ScheduledTaskType input, Json::Value& output)
        {
            if (input == ScheduledTaskTypeCloudScript) output = Json::Value("CloudScript");
            if (input == ScheduledTaskTypeActionsOnPlayerSegment) output = Json::Value("ActionsOnPlayerSegment");
        }
        inline void FromJsonEnum(const Json::Value& input, ScheduledTaskType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "CloudScript") output = ScheduledTaskTypeCloudScript;
            if (inputStr == "ActionsOnPlayerSegment") output = ScheduledTaskTypeActionsOnPlayerSegment;
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

        enum StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        inline void ToJsonEnum(const StatisticAggregationMethod input, Json::Value& output)
        {
            if (input == StatisticAggregationMethodLast) output = Json::Value("Last");
            if (input == StatisticAggregationMethodMin) output = Json::Value("Min");
            if (input == StatisticAggregationMethodMax) output = Json::Value("Max");
            if (input == StatisticAggregationMethodSum) output = Json::Value("Sum");
        }
        inline void FromJsonEnum(const Json::Value& input, StatisticAggregationMethod& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Last") output = StatisticAggregationMethodLast;
            if (inputStr == "Min") output = StatisticAggregationMethodMin;
            if (inputStr == "Max") output = StatisticAggregationMethodMax;
            if (inputStr == "Sum") output = StatisticAggregationMethodSum;
        }

        enum StatisticResetIntervalOption
        {
            StatisticResetIntervalOptionNever,
            StatisticResetIntervalOptionHour,
            StatisticResetIntervalOptionDay,
            StatisticResetIntervalOptionWeek,
            StatisticResetIntervalOptionMonth
        };

        inline void ToJsonEnum(const StatisticResetIntervalOption input, Json::Value& output)
        {
            if (input == StatisticResetIntervalOptionNever) output = Json::Value("Never");
            if (input == StatisticResetIntervalOptionHour) output = Json::Value("Hour");
            if (input == StatisticResetIntervalOptionDay) output = Json::Value("Day");
            if (input == StatisticResetIntervalOptionWeek) output = Json::Value("Week");
            if (input == StatisticResetIntervalOptionMonth) output = Json::Value("Month");
        }
        inline void FromJsonEnum(const Json::Value& input, StatisticResetIntervalOption& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Never") output = StatisticResetIntervalOptionNever;
            if (inputStr == "Hour") output = StatisticResetIntervalOptionHour;
            if (inputStr == "Day") output = StatisticResetIntervalOptionDay;
            if (inputStr == "Week") output = StatisticResetIntervalOptionWeek;
            if (inputStr == "Month") output = StatisticResetIntervalOptionMonth;
        }

        enum StatisticVersionArchivalStatus
        {
            StatisticVersionArchivalStatusNotScheduled,
            StatisticVersionArchivalStatusScheduled,
            StatisticVersionArchivalStatusQueued,
            StatisticVersionArchivalStatusInProgress,
            StatisticVersionArchivalStatusComplete
        };

        inline void ToJsonEnum(const StatisticVersionArchivalStatus input, Json::Value& output)
        {
            if (input == StatisticVersionArchivalStatusNotScheduled) output = Json::Value("NotScheduled");
            if (input == StatisticVersionArchivalStatusScheduled) output = Json::Value("Scheduled");
            if (input == StatisticVersionArchivalStatusQueued) output = Json::Value("Queued");
            if (input == StatisticVersionArchivalStatusInProgress) output = Json::Value("InProgress");
            if (input == StatisticVersionArchivalStatusComplete) output = Json::Value("Complete");
        }
        inline void FromJsonEnum(const Json::Value& input, StatisticVersionArchivalStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "NotScheduled") output = StatisticVersionArchivalStatusNotScheduled;
            if (inputStr == "Scheduled") output = StatisticVersionArchivalStatusScheduled;
            if (inputStr == "Queued") output = StatisticVersionArchivalStatusQueued;
            if (inputStr == "InProgress") output = StatisticVersionArchivalStatusInProgress;
            if (inputStr == "Complete") output = StatisticVersionArchivalStatusComplete;
        }

        enum StatisticVersionStatus
        {
            StatisticVersionStatusActive,
            StatisticVersionStatusSnapshotPending,
            StatisticVersionStatusSnapshot,
            StatisticVersionStatusArchivalPending,
            StatisticVersionStatusArchived
        };

        inline void ToJsonEnum(const StatisticVersionStatus input, Json::Value& output)
        {
            if (input == StatisticVersionStatusActive) output = Json::Value("Active");
            if (input == StatisticVersionStatusSnapshotPending) output = Json::Value("SnapshotPending");
            if (input == StatisticVersionStatusSnapshot) output = Json::Value("Snapshot");
            if (input == StatisticVersionStatusArchivalPending) output = Json::Value("ArchivalPending");
            if (input == StatisticVersionStatusArchived) output = Json::Value("Archived");
        }
        inline void FromJsonEnum(const Json::Value& input, StatisticVersionStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Active") output = StatisticVersionStatusActive;
            if (inputStr == "SnapshotPending") output = StatisticVersionStatusSnapshotPending;
            if (inputStr == "Snapshot") output = StatisticVersionStatusSnapshot;
            if (inputStr == "ArchivalPending") output = StatisticVersionStatusArchivalPending;
            if (inputStr == "Archived") output = StatisticVersionStatusArchived;
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

        enum TaskInstanceStatus
        {
            TaskInstanceStatusSucceeded,
            TaskInstanceStatusStarting,
            TaskInstanceStatusInProgress,
            TaskInstanceStatusFailed,
            TaskInstanceStatusAborted,
            TaskInstanceStatusStalled
        };

        inline void ToJsonEnum(const TaskInstanceStatus input, Json::Value& output)
        {
            if (input == TaskInstanceStatusSucceeded) output = Json::Value("Succeeded");
            if (input == TaskInstanceStatusStarting) output = Json::Value("Starting");
            if (input == TaskInstanceStatusInProgress) output = Json::Value("InProgress");
            if (input == TaskInstanceStatusFailed) output = Json::Value("Failed");
            if (input == TaskInstanceStatusAborted) output = Json::Value("Aborted");
            if (input == TaskInstanceStatusStalled) output = Json::Value("Stalled");
        }
        inline void FromJsonEnum(const Json::Value& input, TaskInstanceStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Succeeded") output = TaskInstanceStatusSucceeded;
            if (inputStr == "Starting") output = TaskInstanceStatusStarting;
            if (inputStr == "InProgress") output = TaskInstanceStatusInProgress;
            if (inputStr == "Failed") output = TaskInstanceStatusFailed;
            if (inputStr == "Aborted") output = TaskInstanceStatusAborted;
            if (inputStr == "Stalled") output = TaskInstanceStatusStalled;
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

            ~AbortTaskInstanceRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TaskInstanceId"], TaskInstanceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output["TaskInstanceId"] = each_TaskInstanceId;
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

            ~ActionsOnPlayersInSegmentTaskParameter() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ActionId"], ActionId);
                FromJsonUtilS(input["SegmentId"], SegmentId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ActionId; ToJsonUtilS(ActionId, each_ActionId); output["ActionId"] = each_ActionId;
                Json::Value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output["SegmentId"] = each_SegmentId;
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

            ~NameIdentifier() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
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

            ~ActionsOnPlayersInSegmentTaskSummary() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["CompletedAt"], CompletedAt);
                FromJsonUtilS(input["ErrorMessage"], ErrorMessage);
                FromJsonUtilP(input["ErrorWasFatal"], ErrorWasFatal);
                FromJsonUtilP(input["EstimatedSecondsRemaining"], EstimatedSecondsRemaining);
                FromJsonUtilP(input["PercentComplete"], PercentComplete);
                FromJsonUtilS(input["ScheduledByUserId"], ScheduledByUserId);
                FromJsonUtilT(input["StartedAt"], StartedAt);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilO(input["TaskIdentifier"], TaskIdentifier);
                FromJsonUtilS(input["TaskInstanceId"], TaskInstanceId);
                FromJsonUtilP(input["TotalPlayersInSegment"], TotalPlayersInSegment);
                FromJsonUtilP(input["TotalPlayersProcessed"], TotalPlayersProcessed);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output["CompletedAt"] = each_CompletedAt;
                Json::Value each_ErrorMessage; ToJsonUtilS(ErrorMessage, each_ErrorMessage); output["ErrorMessage"] = each_ErrorMessage;
                Json::Value each_ErrorWasFatal; ToJsonUtilP(ErrorWasFatal, each_ErrorWasFatal); output["ErrorWasFatal"] = each_ErrorWasFatal;
                Json::Value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output["EstimatedSecondsRemaining"] = each_EstimatedSecondsRemaining;
                Json::Value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output["PercentComplete"] = each_PercentComplete;
                Json::Value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output["ScheduledByUserId"] = each_ScheduledByUserId;
                Json::Value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output["StartedAt"] = each_StartedAt;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output["TaskIdentifier"] = each_TaskIdentifier;
                Json::Value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output["TaskInstanceId"] = each_TaskInstanceId;
                Json::Value each_TotalPlayersInSegment; ToJsonUtilP(TotalPlayersInSegment, each_TotalPlayersInSegment); output["TotalPlayersInSegment"] = each_TotalPlayersInSegment;
                Json::Value each_TotalPlayersProcessed; ToJsonUtilP(TotalPlayersProcessed, each_TotalPlayersProcessed); output["TotalPlayersProcessed"] = each_TotalPlayersProcessed;
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

            ~AdCampaignAttribution() = default;

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

            ~AddNewsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Body"], Body);
                FromJsonUtilT(input["Timestamp"], Timestamp);
                FromJsonUtilS(input["Title"], Title);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Body; ToJsonUtilS(Body, each_Body); output["Body"] = each_Body;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
                Json::Value each_Title; ToJsonUtilS(Title, each_Title); output["Title"] = each_Title;
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

            ~AddNewsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["NewsId"], NewsId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NewsId; ToJsonUtilS(NewsId, each_NewsId); output["NewsId"] = each_NewsId;
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

            ~AddPlayerTagRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["TagName"], TagName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_TagName; ToJsonUtilS(TagName, each_TagName); output["TagName"] = each_TagName;
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

            ~AddPlayerTagResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~AddServerBuildRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CommandLineTemplate"], CommandLineTemplate);
                FromJsonUtilS(input["Comment"], Comment);
                FromJsonUtilS(input["ExecutablePath"], ExecutablePath);
                FromJsonUtilP(input["MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input["MinFreeGameSlots"], MinFreeGameSlots);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output["ActiveRegions"] = each_ActiveRegions;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output["CommandLineTemplate"] = each_CommandLineTemplate;
                Json::Value each_Comment; ToJsonUtilS(Comment, each_Comment); output["Comment"] = each_Comment;
                Json::Value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output["ExecutablePath"] = each_ExecutablePath;
                Json::Value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output["MaxGamesPerHost"] = each_MaxGamesPerHost;
                Json::Value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output["MinFreeGameSlots"] = each_MinFreeGameSlots;
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

            ~AddServerBuildResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CommandLineTemplate"], CommandLineTemplate);
                FromJsonUtilS(input["Comment"], Comment);
                FromJsonUtilS(input["ExecutablePath"], ExecutablePath);
                FromJsonUtilP(input["MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input["MinFreeGameSlots"], MinFreeGameSlots);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilT(input["Timestamp"], Timestamp);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output["ActiveRegions"] = each_ActiveRegions;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output["CommandLineTemplate"] = each_CommandLineTemplate;
                Json::Value each_Comment; ToJsonUtilS(Comment, each_Comment); output["Comment"] = each_Comment;
                Json::Value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output["ExecutablePath"] = each_ExecutablePath;
                Json::Value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output["MaxGamesPerHost"] = each_MaxGamesPerHost;
                Json::Value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output["MinFreeGameSlots"] = each_MinFreeGameSlots;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~AddUserVirtualCurrencyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["VirtualCurrency"], VirtualCurrency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
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

            ~VirtualCurrencyData() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CurrencyCode"], CurrencyCode);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilP(input["InitialDeposit"], InitialDeposit);
                FromJsonUtilP(input["RechargeMax"], RechargeMax);
                FromJsonUtilP(input["RechargeRate"], RechargeRate);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output["CurrencyCode"] = each_CurrencyCode;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_InitialDeposit; ToJsonUtilP(InitialDeposit, each_InitialDeposit); output["InitialDeposit"] = each_InitialDeposit;
                Json::Value each_RechargeMax; ToJsonUtilP(RechargeMax, each_RechargeMax); output["RechargeMax"] = each_RechargeMax;
                Json::Value each_RechargeRate; ToJsonUtilP(RechargeRate, each_RechargeRate); output["RechargeRate"] = each_RechargeRate;
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

            ~AddVirtualCurrencyTypesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["VirtualCurrencies"], VirtualCurrencies);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output["VirtualCurrencies"] = each_VirtualCurrencies;
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

            ~ApiCondition() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["HasSignatureOrEncryption"], HasSignatureOrEncryption);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_HasSignatureOrEncryption; ToJsonUtilE(HasSignatureOrEncryption, each_HasSignatureOrEncryption); output["HasSignatureOrEncryption"] = each_HasSignatureOrEncryption;
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

            ~BanInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilS(input["BanId"], BanId);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilT(input["Expires"], Expires);
                FromJsonUtilS(input["IPAddress"], IPAddress);
                FromJsonUtilS(input["MACAddress"], MACAddress);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["Reason"], Reason);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_BanId; ToJsonUtilS(BanId, each_BanId); output["BanId"] = each_BanId;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_Expires; ToJsonUtilT(Expires, each_Expires); output["Expires"] = each_Expires;
                Json::Value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output["IPAddress"] = each_IPAddress;
                Json::Value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output["MACAddress"] = each_MACAddress;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
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

            ~BanRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["DurationInHours"], DurationInHours);
                FromJsonUtilS(input["IPAddress"], IPAddress);
                FromJsonUtilS(input["MACAddress"], MACAddress);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["Reason"], Reason);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DurationInHours; ToJsonUtilP(DurationInHours, each_DurationInHours); output["DurationInHours"] = each_DurationInHours;
                Json::Value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output["IPAddress"] = each_IPAddress;
                Json::Value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output["MACAddress"] = each_MACAddress;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
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

            ~BanUsersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bans"], Bans);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bans; ToJsonUtilO(Bans, each_Bans); output["Bans"] = each_Bans;
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

            ~BanUsersResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["BanData"], BanData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BanData; ToJsonUtilO(BanData, each_BanData); output["BanData"] = each_BanData;
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

            ~BlankResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~CheckLimitedEditionItemAvailabilityRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
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

            ~CheckLimitedEditionItemAvailabilityResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
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

            ~CloudScriptFile() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileContents"], FileContents);
                FromJsonUtilS(input["Filename"], Filename);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileContents; ToJsonUtilS(FileContents, each_FileContents); output["FileContents"] = each_FileContents;
                Json::Value each_Filename; ToJsonUtilS(Filename, each_Filename); output["Filename"] = each_Filename;
                return output;
            }
        };

        struct CloudScriptTaskParameter : public PlayFabBaseModel
        {
            Json::Value Argument;
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

            ~CloudScriptTaskParameter() = default;

            void FromJson(Json::Value& input) override
            {
                Argument = input["Argument"];
                FromJsonUtilS(input["FunctionName"], FunctionName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["Argument"] = Argument;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
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

            ~CloudScriptTaskSummary() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["CompletedAt"], CompletedAt);
                FromJsonUtilP(input["EstimatedSecondsRemaining"], EstimatedSecondsRemaining);
                FromJsonUtilP(input["PercentComplete"], PercentComplete);
                FromJsonUtilO(input["Result"], Result);
                FromJsonUtilS(input["ScheduledByUserId"], ScheduledByUserId);
                FromJsonUtilT(input["StartedAt"], StartedAt);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilO(input["TaskIdentifier"], TaskIdentifier);
                FromJsonUtilS(input["TaskInstanceId"], TaskInstanceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output["CompletedAt"] = each_CompletedAt;
                Json::Value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output["EstimatedSecondsRemaining"] = each_EstimatedSecondsRemaining;
                Json::Value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output["PercentComplete"] = each_PercentComplete;
                Json::Value each_Result; ToJsonUtilO(Result, each_Result); output["Result"] = each_Result;
                Json::Value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output["ScheduledByUserId"] = each_ScheduledByUserId;
                Json::Value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output["StartedAt"] = each_StartedAt;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output["TaskIdentifier"] = each_TaskIdentifier;
                Json::Value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output["TaskInstanceId"] = each_TaskInstanceId;
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

            ~CloudScriptVersionStatus() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["LatestRevision"], LatestRevision);
                FromJsonUtilP(input["PublishedRevision"], PublishedRevision);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LatestRevision; ToJsonUtilP(LatestRevision, each_LatestRevision); output["LatestRevision"] = each_LatestRevision;
                Json::Value each_PublishedRevision; ToJsonUtilP(PublishedRevision, each_PublishedRevision); output["PublishedRevision"] = each_PublishedRevision;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~ContactEmailInfo() = default;

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

            ~ContentInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Key"], Key);
                FromJsonUtilT(input["LastModified"], LastModified);
                FromJsonUtilP(input["Size"], Size);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Key; ToJsonUtilS(Key, each_Key); output["Key"] = each_Key;
                Json::Value each_LastModified; ToJsonUtilT(LastModified, each_LastModified); output["LastModified"] = each_LastModified;
                Json::Value each_Size; ToJsonUtilP(Size, each_Size); output["Size"] = each_Size;
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

            ~CreateActionsOnPlayerSegmentTaskRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilO(input["Parameter"], Parameter);
                FromJsonUtilS(input["Schedule"], Schedule);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output["Parameter"] = each_Parameter;
                Json::Value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output["Schedule"] = each_Schedule;
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

            ~CreateCloudScriptTaskRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilO(input["Parameter"], Parameter);
                FromJsonUtilS(input["Schedule"], Schedule);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output["Parameter"] = each_Parameter;
                Json::Value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output["Schedule"] = each_Schedule;
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

            ~CreatePlayerSharedSecretRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FriendlyName"], FriendlyName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output["FriendlyName"] = each_FriendlyName;
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

            ~CreatePlayerSharedSecretResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["SecretKey"], SecretKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output["SecretKey"] = each_SecretKey;
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

            ~CreatePlayerStatisticDefinitionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["AggregationMethod"], AggregationMethod);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilE(input["VersionChangeInterval"], VersionChangeInterval);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output["AggregationMethod"] = each_AggregationMethod;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output["VersionChangeInterval"] = each_VersionChangeInterval;
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

            ~PlayerStatisticDefinition() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["AggregationMethod"], AggregationMethod);
                FromJsonUtilP(input["CurrentVersion"], CurrentVersion);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilE(input["VersionChangeInterval"], VersionChangeInterval);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output["AggregationMethod"] = each_AggregationMethod;
                Json::Value each_CurrentVersion; ToJsonUtilP(CurrentVersion, each_CurrentVersion); output["CurrentVersion"] = each_CurrentVersion;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output["VersionChangeInterval"] = each_VersionChangeInterval;
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

            ~CreatePlayerStatisticDefinitionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Statistic"], Statistic);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Statistic; ToJsonUtilO(Statistic, each_Statistic); output["Statistic"] = each_Statistic;
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

            ~CreateTaskResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TaskId"], TaskId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TaskId; ToJsonUtilS(TaskId, each_TaskId); output["TaskId"] = each_TaskId;
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

            ~DeleteContentRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Key"], Key);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Key; ToJsonUtilS(Key, each_Key); output["Key"] = each_Key;
                return output;
            }
        };

        struct DeleteMasterPlayerAccountRequest : public PlayFabRequestCommon
        {
            std::string MetaData;
            std::string PlayFabId;

            DeleteMasterPlayerAccountRequest() :
                PlayFabRequestCommon(),
                MetaData(),
                PlayFabId()
            {}

            DeleteMasterPlayerAccountRequest(const DeleteMasterPlayerAccountRequest& src) :
                PlayFabRequestCommon(),
                MetaData(src.MetaData),
                PlayFabId(src.PlayFabId)
            {}

            ~DeleteMasterPlayerAccountRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["MetaData"], MetaData);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MetaData; ToJsonUtilS(MetaData, each_MetaData); output["MetaData"] = each_MetaData;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~DeleteMasterPlayerAccountResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["JobReceiptId"], JobReceiptId);
                FromJsonUtilS(input["TitleIds"], TitleIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_JobReceiptId; ToJsonUtilS(JobReceiptId, each_JobReceiptId); output["JobReceiptId"] = each_JobReceiptId;
                Json::Value each_TitleIds; ToJsonUtilS(TitleIds, each_TitleIds); output["TitleIds"] = each_TitleIds;
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

            ~DeletePlayerRequest() = default;

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

        struct DeletePlayerResult : public PlayFabResultCommon
        {

            DeletePlayerResult() :
                PlayFabResultCommon()
            {}

            DeletePlayerResult(const DeletePlayerResult&) :
                PlayFabResultCommon()
            {}

            ~DeletePlayerResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~DeletePlayerSharedSecretRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["SecretKey"], SecretKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output["SecretKey"] = each_SecretKey;
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

            ~DeletePlayerSharedSecretResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~DeleteStoreRequest() = default;

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

        struct DeleteStoreResult : public PlayFabResultCommon
        {

            DeleteStoreResult() :
                PlayFabResultCommon()
            {}

            DeleteStoreResult(const DeleteStoreResult&) :
                PlayFabResultCommon()
            {}

            ~DeleteStoreResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~DeleteTaskRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Identifier"], Identifier);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output["Identifier"] = each_Identifier;
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

            ~DeleteTitleRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~DeleteTitleResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ExportMasterPlayerDataRequest() = default;

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

            ~ExportMasterPlayerDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["JobReceiptId"], JobReceiptId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_JobReceiptId; ToJsonUtilS(JobReceiptId, each_JobReceiptId); output["JobReceiptId"] = each_JobReceiptId;
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

            ~GameModeInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Gamemode"], Gamemode);
                FromJsonUtilP(input["MaxPlayerCount"], MaxPlayerCount);
                FromJsonUtilP(input["MinPlayerCount"], MinPlayerCount);
                FromJsonUtilP(input["StartOpen"], StartOpen);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Gamemode; ToJsonUtilS(Gamemode, each_Gamemode); output["Gamemode"] = each_Gamemode;
                Json::Value each_MaxPlayerCount; ToJsonUtilP(MaxPlayerCount, each_MaxPlayerCount); output["MaxPlayerCount"] = each_MaxPlayerCount;
                Json::Value each_MinPlayerCount; ToJsonUtilP(MinPlayerCount, each_MinPlayerCount); output["MinPlayerCount"] = each_MinPlayerCount;
                Json::Value each_StartOpen; ToJsonUtilP(StartOpen, each_StartOpen); output["StartOpen"] = each_StartOpen;
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

            ~GetActionsOnPlayersInSegmentTaskInstanceResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Parameter"], Parameter);
                FromJsonUtilO(input["Summary"], Summary);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output["Parameter"] = each_Parameter;
                Json::Value each_Summary; ToJsonUtilO(Summary, each_Summary); output["Summary"] = each_Summary;
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

            ~GetAllSegmentsRequest() = default;

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

            ~GetAllSegmentsResult() = default;

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

            ~GetCloudScriptRevisionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Revision"], Revision);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Revision; ToJsonUtilP(Revision, each_Revision); output["Revision"] = each_Revision;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetCloudScriptRevisionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["CreatedAt"], CreatedAt);
                FromJsonUtilO(input["Files"], Files);
                FromJsonUtilP(input["IsPublished"], IsPublished);
                FromJsonUtilP(input["Revision"], Revision);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreatedAt; ToJsonUtilT(CreatedAt, each_CreatedAt); output["CreatedAt"] = each_CreatedAt;
                Json::Value each_Files; ToJsonUtilO(Files, each_Files); output["Files"] = each_Files;
                Json::Value each_IsPublished; ToJsonUtilP(IsPublished, each_IsPublished); output["IsPublished"] = each_IsPublished;
                Json::Value each_Revision; ToJsonUtilP(Revision, each_Revision); output["Revision"] = each_Revision;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~GetCloudScriptTaskInstanceResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Parameter"], Parameter);
                FromJsonUtilO(input["Summary"], Summary);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output["Parameter"] = each_Parameter;
                Json::Value each_Summary; ToJsonUtilO(Summary, each_Summary); output["Summary"] = each_Summary;
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

            ~GetCloudScriptVersionsRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~GetCloudScriptVersionsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Versions"], Versions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Versions; ToJsonUtilO(Versions, each_Versions); output["Versions"] = each_Versions;
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

            ~GetContentListRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Prefix"], Prefix);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Prefix; ToJsonUtilS(Prefix, each_Prefix); output["Prefix"] = each_Prefix;
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

            ~GetContentListResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Contents"], Contents);
                FromJsonUtilP(input["ItemCount"], ItemCount);
                FromJsonUtilP(input["TotalSize"], TotalSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Contents; ToJsonUtilO(Contents, each_Contents); output["Contents"] = each_Contents;
                Json::Value each_ItemCount; ToJsonUtilP(ItemCount, each_ItemCount); output["ItemCount"] = each_ItemCount;
                Json::Value each_TotalSize; ToJsonUtilP(TotalSize, each_TotalSize); output["TotalSize"] = each_TotalSize;
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

            ~GetContentUploadUrlRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ContentType"], ContentType);
                FromJsonUtilS(input["Key"], Key);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContentType; ToJsonUtilS(ContentType, each_ContentType); output["ContentType"] = each_ContentType;
                Json::Value each_Key; ToJsonUtilS(Key, each_Key); output["Key"] = each_Key;
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

            ~GetContentUploadUrlResult() = default;

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

            ~GetDataReportRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Day"], Day);
                FromJsonUtilP(input["Month"], Month);
                FromJsonUtilS(input["ReportName"], ReportName);
                FromJsonUtilP(input["Year"], Year);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Day; ToJsonUtilP(Day, each_Day); output["Day"] = each_Day;
                Json::Value each_Month; ToJsonUtilP(Month, each_Month); output["Month"] = each_Month;
                Json::Value each_ReportName; ToJsonUtilS(ReportName, each_ReportName); output["ReportName"] = each_ReportName;
                Json::Value each_Year; ToJsonUtilP(Year, each_Year); output["Year"] = each_Year;
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

            ~GetDataReportResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DownloadUrl"], DownloadUrl);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DownloadUrl; ToJsonUtilS(DownloadUrl, each_DownloadUrl); output["DownloadUrl"] = each_DownloadUrl;
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

            ~GetMatchmakerGameInfoRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["LobbyId"], LobbyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
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
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                StartTime(src.StartTime),
                TitleId(src.TitleId)
            {}

            ~GetMatchmakerGameInfoResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildVersion"], BuildVersion);
                FromJsonUtilT(input["EndTime"], EndTime);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilS(input["Mode"], Mode);
                FromJsonUtilS(input["Players"], Players);
                FromJsonUtilE(input["pfRegion"], pfRegion);
                FromJsonUtilS(input["ServerIPV4Address"], ServerIPV4Address);
                FromJsonUtilS(input["ServerIPV6Address"], ServerIPV6Address);
                FromJsonUtilP(input["ServerPort"], ServerPort);
                FromJsonUtilS(input["ServerPublicDNSName"], ServerPublicDNSName);
                FromJsonUtilT(input["StartTime"], StartTime);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output["BuildVersion"] = each_BuildVersion;
                Json::Value each_EndTime; ToJsonUtilT(EndTime, each_EndTime); output["EndTime"] = each_EndTime;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_Mode; ToJsonUtilS(Mode, each_Mode); output["Mode"] = each_Mode;
                Json::Value each_Players; ToJsonUtilS(Players, each_Players); output["Players"] = each_Players;
                Json::Value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output["Region"] = each_pfRegion;
                Json::Value each_ServerIPV4Address; ToJsonUtilS(ServerIPV4Address, each_ServerIPV4Address); output["ServerIPV4Address"] = each_ServerIPV4Address;
                Json::Value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output["ServerIPV6Address"] = each_ServerIPV6Address;
                Json::Value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output["ServerPort"] = each_ServerPort;
                Json::Value each_ServerPublicDNSName; ToJsonUtilS(ServerPublicDNSName, each_ServerPublicDNSName); output["ServerPublicDNSName"] = each_ServerPublicDNSName;
                Json::Value each_StartTime; ToJsonUtilT(StartTime, each_StartTime); output["StartTime"] = each_StartTime;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~GetMatchmakerGameModesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildVersion"], BuildVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output["BuildVersion"] = each_BuildVersion;
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

            ~GetMatchmakerGameModesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["GameModes"], GameModes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GameModes; ToJsonUtilO(GameModes, each_GameModes); output["GameModes"] = each_GameModes;
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

            ~GetPlayedTitleListRequest() = default;

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

            ~GetPlayedTitleListResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TitleIds"], TitleIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TitleIds; ToJsonUtilS(TitleIds, each_TitleIds); output["TitleIds"] = each_TitleIds;
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

            ~GetPlayerIdFromAuthTokenRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Token"], Token);
                FromJsonEnum(input["TokenType"], TokenType);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Token; ToJsonUtilS(Token, each_Token); output["Token"] = each_Token;
                Json::Value each_TokenType; ToJsonEnum(TokenType, each_TokenType); output["TokenType"] = each_TokenType;
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

            ~GetPlayerIdFromAuthTokenResult() = default;

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

        struct GetPlayerSharedSecretsRequest : public PlayFabRequestCommon
        {

            GetPlayerSharedSecretsRequest() :
                PlayFabRequestCommon()
            {}

            GetPlayerSharedSecretsRequest(const GetPlayerSharedSecretsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetPlayerSharedSecretsRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~SharedSecret() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Disabled"], Disabled);
                FromJsonUtilS(input["FriendlyName"], FriendlyName);
                FromJsonUtilS(input["SecretKey"], SecretKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Disabled; ToJsonUtilP(Disabled, each_Disabled); output["Disabled"] = each_Disabled;
                Json::Value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output["FriendlyName"] = each_FriendlyName;
                Json::Value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output["SecretKey"] = each_SecretKey;
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

            ~GetPlayerSharedSecretsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["SharedSecrets"], SharedSecrets);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_SharedSecrets; ToJsonUtilO(SharedSecrets, each_SharedSecrets); output["SharedSecrets"] = each_SharedSecrets;
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

            ~GetPlayersInSegmentRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["MaxBatchSize"], MaxBatchSize);
                FromJsonUtilP(input["SecondsToLive"], SecondsToLive);
                FromJsonUtilS(input["SegmentId"], SegmentId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_MaxBatchSize; ToJsonUtilP(MaxBatchSize, each_MaxBatchSize); output["MaxBatchSize"] = each_MaxBatchSize;
                Json::Value each_SecondsToLive; ToJsonUtilP(SecondsToLive, each_SecondsToLive); output["SecondsToLive"] = each_SecondsToLive;
                Json::Value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output["SegmentId"] = each_SegmentId;
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

            ~PlayerLinkedAccount() = default;

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

            ~PlayerLocation() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["City"], City);
                FromJsonEnum(input["pfContinentCode"], pfContinentCode);
                FromJsonEnum(input["pfCountryCode"], pfCountryCode);
                FromJsonUtilP(input["Latitude"], Latitude);
                FromJsonUtilP(input["Longitude"], Longitude);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_City; ToJsonUtilS(City, each_City); output["City"] = each_City;
                Json::Value each_pfContinentCode; ToJsonEnum(pfContinentCode, each_pfContinentCode); output["ContinentCode"] = each_pfContinentCode;
                Json::Value each_pfCountryCode; ToJsonEnum(pfCountryCode, each_pfCountryCode); output["CountryCode"] = each_pfCountryCode;
                Json::Value each_Latitude; ToJsonUtilP(Latitude, each_Latitude); output["Latitude"] = each_Latitude;
                Json::Value each_Longitude; ToJsonUtilP(Longitude, each_Longitude); output["Longitude"] = each_Longitude;
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

            ~PlayerStatistic() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["StatisticValue"], StatisticValue);
                FromJsonUtilP(input["StatisticVersion"], StatisticVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_StatisticValue; ToJsonUtilP(StatisticValue, each_StatisticValue); output["StatisticValue"] = each_StatisticValue;
                Json::Value each_StatisticVersion; ToJsonUtilP(StatisticVersion, each_StatisticVersion); output["StatisticVersion"] = each_StatisticVersion;
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

            ~PushNotificationRegistration() = default;

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

            ~PlayerProfile() = default;

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
                FromJsonUtilE(input["Origination"], Origination);
                FromJsonUtilS(input["PlayerId"], PlayerId);
                FromJsonUtilO(input["PlayerStatistics"], PlayerStatistics);
                FromJsonUtilS(input["PublisherId"], PublisherId);
                FromJsonUtilO(input["PushNotificationRegistrations"], PushNotificationRegistrations);
                FromJsonUtilP(input["Statistics"], Statistics);
                FromJsonUtilS(input["Tags"], Tags);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilP(input["TotalValueToDateInUSD"], TotalValueToDateInUSD);
                FromJsonUtilP(input["ValuesToDate"], ValuesToDate);
                FromJsonUtilP(input["VirtualCurrencyBalances"], VirtualCurrencyBalances);
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
                Json::Value each_Origination; ToJsonUtilE(Origination, each_Origination); output["Origination"] = each_Origination;
                Json::Value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output["PlayerId"] = each_PlayerId;
                Json::Value each_PlayerStatistics; ToJsonUtilO(PlayerStatistics, each_PlayerStatistics); output["PlayerStatistics"] = each_PlayerStatistics;
                Json::Value each_PublisherId; ToJsonUtilS(PublisherId, each_PublisherId); output["PublisherId"] = each_PublisherId;
                Json::Value each_PushNotificationRegistrations; ToJsonUtilO(PushNotificationRegistrations, each_PushNotificationRegistrations); output["PushNotificationRegistrations"] = each_PushNotificationRegistrations;
                Json::Value each_Statistics; ToJsonUtilP(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_TotalValueToDateInUSD; ToJsonUtilP(TotalValueToDateInUSD, each_TotalValueToDateInUSD); output["TotalValueToDateInUSD"] = each_TotalValueToDateInUSD;
                Json::Value each_ValuesToDate; ToJsonUtilP(ValuesToDate, each_ValuesToDate); output["ValuesToDate"] = each_ValuesToDate;
                Json::Value each_VirtualCurrencyBalances; ToJsonUtilP(VirtualCurrencyBalances, each_VirtualCurrencyBalances); output["VirtualCurrencyBalances"] = each_VirtualCurrencyBalances;
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

            ~GetPlayersInSegmentResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilO(input["PlayerProfiles"], PlayerProfiles);
                FromJsonUtilP(input["ProfilesInSegment"], ProfilesInSegment);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_PlayerProfiles; ToJsonUtilO(PlayerProfiles, each_PlayerProfiles); output["PlayerProfiles"] = each_PlayerProfiles;
                Json::Value each_ProfilesInSegment; ToJsonUtilP(ProfilesInSegment, each_ProfilesInSegment); output["ProfilesInSegment"] = each_ProfilesInSegment;
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

            ~GetPlayersSegmentsRequest() = default;

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

        struct GetPlayerStatisticDefinitionsRequest : public PlayFabRequestCommon
        {

            GetPlayerStatisticDefinitionsRequest() :
                PlayFabRequestCommon()
            {}

            GetPlayerStatisticDefinitionsRequest(const GetPlayerStatisticDefinitionsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetPlayerStatisticDefinitionsRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~GetPlayerStatisticDefinitionsResult() = default;

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

            ~PlayerStatisticVersion() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["ActivationTime"], ActivationTime);
                FromJsonUtilS(input["ArchiveDownloadUrl"], ArchiveDownloadUrl);
                FromJsonUtilT(input["DeactivationTime"], DeactivationTime);
                FromJsonUtilT(input["ScheduledActivationTime"], ScheduledActivationTime);
                FromJsonUtilT(input["ScheduledDeactivationTime"], ScheduledDeactivationTime);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ActivationTime; ToJsonUtilT(ActivationTime, each_ActivationTime); output["ActivationTime"] = each_ActivationTime;
                Json::Value each_ArchiveDownloadUrl; ToJsonUtilS(ArchiveDownloadUrl, each_ArchiveDownloadUrl); output["ArchiveDownloadUrl"] = each_ArchiveDownloadUrl;
                Json::Value each_DeactivationTime; ToJsonUtilT(DeactivationTime, each_DeactivationTime); output["DeactivationTime"] = each_DeactivationTime;
                Json::Value each_ScheduledActivationTime; ToJsonUtilT(ScheduledActivationTime, each_ScheduledActivationTime); output["ScheduledActivationTime"] = each_ScheduledActivationTime;
                Json::Value each_ScheduledDeactivationTime; ToJsonUtilT(ScheduledDeactivationTime, each_ScheduledDeactivationTime); output["ScheduledDeactivationTime"] = each_ScheduledDeactivationTime;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
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

            ~GetPolicyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PolicyName"], PolicyName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output["PolicyName"] = each_PolicyName;
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

            ~PermissionStatement() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Action"], Action);
                FromJsonUtilO(input["ApiConditions"], ApiConditions);
                FromJsonUtilS(input["Comment"], Comment);
                FromJsonEnum(input["Effect"], Effect);
                FromJsonUtilS(input["Principal"], Principal);
                FromJsonUtilS(input["Resource"], Resource);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Action; ToJsonUtilS(Action, each_Action); output["Action"] = each_Action;
                Json::Value each_ApiConditions; ToJsonUtilO(ApiConditions, each_ApiConditions); output["ApiConditions"] = each_ApiConditions;
                Json::Value each_Comment; ToJsonUtilS(Comment, each_Comment); output["Comment"] = each_Comment;
                Json::Value each_Effect; ToJsonEnum(Effect, each_Effect); output["Effect"] = each_Effect;
                Json::Value each_Principal; ToJsonUtilS(Principal, each_Principal); output["Principal"] = each_Principal;
                Json::Value each_Resource; ToJsonUtilS(Resource, each_Resource); output["Resource"] = each_Resource;
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

            ~GetPolicyResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PolicyName"], PolicyName);
                FromJsonUtilO(input["Statements"], Statements);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output["PolicyName"] = each_PolicyName;
                Json::Value each_Statements; ToJsonUtilO(Statements, each_Statements); output["Statements"] = each_Statements;
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

            ~GetRandomResultTablesRequest() = default;

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

            ~ResultTableNode() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ResultItem"], ResultItem);
                FromJsonEnum(input["ResultItemType"], ResultItemType);
                FromJsonUtilP(input["Weight"], Weight);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ResultItem; ToJsonUtilS(ResultItem, each_ResultItem); output["ResultItem"] = each_ResultItem;
                Json::Value each_ResultItemType; ToJsonEnum(ResultItemType, each_ResultItemType); output["ResultItemType"] = each_ResultItemType;
                Json::Value each_Weight; ToJsonUtilP(Weight, each_Weight); output["Weight"] = each_Weight;
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

            ~RandomResultTableListing() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input["Nodes"], Nodes);
                FromJsonUtilS(input["TableId"], TableId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_Nodes; ToJsonUtilO(Nodes, each_Nodes); output["Nodes"] = each_Nodes;
                Json::Value each_TableId; ToJsonUtilS(TableId, each_TableId); output["TableId"] = each_TableId;
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

            ~GetRandomResultTablesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Tables"], Tables);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Tables; ToJsonUtilO(Tables, each_Tables); output["Tables"] = each_Tables;
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

            ~GetServerBuildInfoRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
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

            ~GetServerBuildInfoResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["Comment"], Comment);
                FromJsonUtilS(input["ErrorMessage"], ErrorMessage);
                FromJsonUtilP(input["MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input["MinFreeGameSlots"], MinFreeGameSlots);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilT(input["Timestamp"], Timestamp);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output["ActiveRegions"] = each_ActiveRegions;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Comment; ToJsonUtilS(Comment, each_Comment); output["Comment"] = each_Comment;
                Json::Value each_ErrorMessage; ToJsonUtilS(ErrorMessage, each_ErrorMessage); output["ErrorMessage"] = each_ErrorMessage;
                Json::Value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output["MaxGamesPerHost"] = each_MaxGamesPerHost;
                Json::Value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output["MinFreeGameSlots"] = each_MinFreeGameSlots;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~GetServerBuildUploadURLRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
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

            ~GetServerBuildUploadURLResult() = default;

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

            ~GetTaskInstanceRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TaskInstanceId"], TaskInstanceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output["TaskInstanceId"] = each_TaskInstanceId;
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

            ~GetTaskInstancesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["StartedAtRangeFrom"], StartedAtRangeFrom);
                FromJsonUtilT(input["StartedAtRangeTo"], StartedAtRangeTo);
                FromJsonUtilE(input["StatusFilter"], StatusFilter);
                FromJsonUtilO(input["TaskIdentifier"], TaskIdentifier);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StartedAtRangeFrom; ToJsonUtilT(StartedAtRangeFrom, each_StartedAtRangeFrom); output["StartedAtRangeFrom"] = each_StartedAtRangeFrom;
                Json::Value each_StartedAtRangeTo; ToJsonUtilT(StartedAtRangeTo, each_StartedAtRangeTo); output["StartedAtRangeTo"] = each_StartedAtRangeTo;
                Json::Value each_StatusFilter; ToJsonUtilE(StatusFilter, each_StatusFilter); output["StatusFilter"] = each_StatusFilter;
                Json::Value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output["TaskIdentifier"] = each_TaskIdentifier;
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

            ~TaskInstanceBasicSummary() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["CompletedAt"], CompletedAt);
                FromJsonUtilP(input["EstimatedSecondsRemaining"], EstimatedSecondsRemaining);
                FromJsonUtilP(input["PercentComplete"], PercentComplete);
                FromJsonUtilS(input["ScheduledByUserId"], ScheduledByUserId);
                FromJsonUtilT(input["StartedAt"], StartedAt);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilO(input["TaskIdentifier"], TaskIdentifier);
                FromJsonUtilS(input["TaskInstanceId"], TaskInstanceId);
                FromJsonUtilE(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output["CompletedAt"] = each_CompletedAt;
                Json::Value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output["EstimatedSecondsRemaining"] = each_EstimatedSecondsRemaining;
                Json::Value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output["PercentComplete"] = each_PercentComplete;
                Json::Value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output["ScheduledByUserId"] = each_ScheduledByUserId;
                Json::Value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output["StartedAt"] = each_StartedAt;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output["TaskIdentifier"] = each_TaskIdentifier;
                Json::Value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output["TaskInstanceId"] = each_TaskInstanceId;
                Json::Value each_Type; ToJsonUtilE(Type, each_Type); output["Type"] = each_Type;
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

            ~GetTaskInstancesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Summaries"], Summaries);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Summaries; ToJsonUtilO(Summaries, each_Summaries); output["Summaries"] = each_Summaries;
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

            ~GetTasksRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Identifier"], Identifier);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output["Identifier"] = each_Identifier;
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
            Json::Value Parameter;
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

            ~ScheduledTask() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilT(input["LastRunTime"], LastRunTime);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilT(input["NextRunTime"], NextRunTime);
                Parameter = input["Parameter"];
                FromJsonUtilS(input["Schedule"], Schedule);
                FromJsonUtilS(input["TaskId"], TaskId);
                FromJsonUtilE(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_LastRunTime; ToJsonUtilT(LastRunTime, each_LastRunTime); output["LastRunTime"] = each_LastRunTime;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_NextRunTime; ToJsonUtilT(NextRunTime, each_NextRunTime); output["NextRunTime"] = each_NextRunTime;
                output["Parameter"] = Parameter;
                Json::Value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output["Schedule"] = each_Schedule;
                Json::Value each_TaskId; ToJsonUtilS(TaskId, each_TaskId); output["TaskId"] = each_TaskId;
                Json::Value each_Type; ToJsonUtilE(Type, each_Type); output["Type"] = each_Type;
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

            ~GetTasksResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Tasks"], Tasks);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Tasks; ToJsonUtilO(Tasks, each_Tasks); output["Tasks"] = each_Tasks;
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

            ~GetUserBansRequest() = default;

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

            ~GetUserBansResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["BanData"], BanData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BanData; ToJsonUtilO(BanData, each_BanData); output["BanData"] = each_BanData;
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

            ~GetUserDataResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Data"], Data);
                FromJsonUtilP(input["DataVersion"], DataVersion);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilO(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output["DataVersion"] = each_DataVersion;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GetUserInventoryRequest() = default;

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

            ~GetUserInventoryResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Inventory"], Inventory);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilP(input["VirtualCurrency"], VirtualCurrency);
                FromJsonUtilO(input["VirtualCurrencyRechargeTimes"], VirtualCurrencyRechargeTimes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output["Inventory"] = each_Inventory;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
                Json::Value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output["VirtualCurrencyRechargeTimes"] = each_VirtualCurrencyRechargeTimes;
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

            ~GrantedItemInstance() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Annotation"], Annotation);
                FromJsonUtilS(input["BundleContents"], BundleContents);
                FromJsonUtilS(input["BundleParent"], BundleParent);
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["CustomData"], CustomData);
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilT(input["Expiration"], Expiration);
                FromJsonUtilS(input["ItemClass"], ItemClass);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ItemInstanceId"], ItemInstanceId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilT(input["PurchaseDate"], PurchaseDate);
                FromJsonUtilP(input["RemainingUses"], RemainingUses);
                FromJsonUtilP(input["Result"], Result);
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
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output["CustomData"] = each_CustomData;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output["Expiration"] = each_Expiration;
                Json::Value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output["ItemClass"] = each_ItemClass;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output["ItemInstanceId"] = each_ItemInstanceId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output["PurchaseDate"] = each_PurchaseDate;
                Json::Value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output["RemainingUses"] = each_RemainingUses;
                Json::Value each_Result; ToJsonUtilP(Result, each_Result); output["Result"] = each_Result;
                Json::Value each_UnitCurrency; ToJsonUtilS(UnitCurrency, each_UnitCurrency); output["UnitCurrency"] = each_UnitCurrency;
                Json::Value each_UnitPrice; ToJsonUtilP(UnitPrice, each_UnitPrice); output["UnitPrice"] = each_UnitPrice;
                Json::Value each_UsesIncrementedBy; ToJsonUtilP(UsesIncrementedBy, each_UsesIncrementedBy); output["UsesIncrementedBy"] = each_UsesIncrementedBy;
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

            ~ItemGrant() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Annotation"], Annotation);
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["Data"], Data);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["KeysToRemove"], KeysToRemove);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output["Annotation"] = each_Annotation;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output["KeysToRemove"] = each_KeysToRemove;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~GrantItemsToUsersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input["ItemGrants"], ItemGrants);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_ItemGrants; ToJsonUtilO(ItemGrants, each_ItemGrants); output["ItemGrants"] = each_ItemGrants;
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

            ~GrantItemsToUsersResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["ItemGrantResults"], ItemGrantResults);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ItemGrantResults; ToJsonUtilO(ItemGrantResults, each_ItemGrantResults); output["ItemGrantResults"] = each_ItemGrantResults;
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

            ~IncrementLimitedEditionItemAvailabilityRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
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

            ~IncrementLimitedEditionItemAvailabilityResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~IncrementPlayerStatisticVersionRequest() = default;

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

            ~IncrementPlayerStatisticVersionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["StatisticVersion"], StatisticVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatisticVersion; ToJsonUtilO(StatisticVersion, each_StatisticVersion); output["StatisticVersion"] = each_StatisticVersion;
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

            ~ListBuildsRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ListBuildsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Builds"], Builds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Builds; ToJsonUtilO(Builds, each_Builds); output["Builds"] = each_Builds;
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

            ~ListVirtualCurrencyTypesRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ListVirtualCurrencyTypesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["VirtualCurrencies"], VirtualCurrencies);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output["VirtualCurrencies"] = each_VirtualCurrencies;
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

            ~LookupUserAccountInfoRequest() = default;

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

            ~LookupUserAccountInfoResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["UserInfo"], UserInfo);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_UserInfo; ToJsonUtilO(UserInfo, each_UserInfo); output["UserInfo"] = each_UserInfo;
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

            ~ModifyMatchmakerGameModesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildVersion"], BuildVersion);
                FromJsonUtilO(input["GameModes"], GameModes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output["BuildVersion"] = each_BuildVersion;
                Json::Value each_GameModes; ToJsonUtilO(GameModes, each_GameModes); output["GameModes"] = each_GameModes;
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

            ~ModifyMatchmakerGameModesResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ModifyServerBuildRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CommandLineTemplate"], CommandLineTemplate);
                FromJsonUtilS(input["Comment"], Comment);
                FromJsonUtilS(input["ExecutablePath"], ExecutablePath);
                FromJsonUtilP(input["MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input["MinFreeGameSlots"], MinFreeGameSlots);
                FromJsonUtilT(input["Timestamp"], Timestamp);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output["ActiveRegions"] = each_ActiveRegions;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output["CommandLineTemplate"] = each_CommandLineTemplate;
                Json::Value each_Comment; ToJsonUtilS(Comment, each_Comment); output["Comment"] = each_Comment;
                Json::Value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output["ExecutablePath"] = each_ExecutablePath;
                Json::Value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output["MaxGamesPerHost"] = each_MaxGamesPerHost;
                Json::Value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output["MinFreeGameSlots"] = each_MinFreeGameSlots;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
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

            ~ModifyServerBuildResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["ActiveRegions"], ActiveRegions);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CommandLineTemplate"], CommandLineTemplate);
                FromJsonUtilS(input["Comment"], Comment);
                FromJsonUtilS(input["ExecutablePath"], ExecutablePath);
                FromJsonUtilP(input["MaxGamesPerHost"], MaxGamesPerHost);
                FromJsonUtilP(input["MinFreeGameSlots"], MinFreeGameSlots);
                FromJsonUtilE(input["Status"], Status);
                FromJsonUtilT(input["Timestamp"], Timestamp);
                FromJsonUtilS(input["TitleId"], TitleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output["ActiveRegions"] = each_ActiveRegions;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output["CommandLineTemplate"] = each_CommandLineTemplate;
                Json::Value each_Comment; ToJsonUtilS(Comment, each_Comment); output["Comment"] = each_Comment;
                Json::Value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output["ExecutablePath"] = each_ExecutablePath;
                Json::Value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output["MaxGamesPerHost"] = each_MaxGamesPerHost;
                Json::Value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output["MinFreeGameSlots"] = each_MinFreeGameSlots;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output["Timestamp"] = each_Timestamp;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
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

            ~RandomResultTable() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Nodes"], Nodes);
                FromJsonUtilS(input["TableId"], TableId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Nodes; ToJsonUtilO(Nodes, each_Nodes); output["Nodes"] = each_Nodes;
                Json::Value each_TableId; ToJsonUtilS(TableId, each_TableId); output["TableId"] = each_TableId;
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

            ~RefundPurchaseRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OrderId"], OrderId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["Reason"], Reason);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
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

            ~RefundPurchaseResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PurchaseStatus"], PurchaseStatus);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PurchaseStatus; ToJsonUtilS(PurchaseStatus, each_PurchaseStatus); output["PurchaseStatus"] = each_PurchaseStatus;
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

            ~RemovePlayerTagRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["TagName"], TagName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_TagName; ToJsonUtilS(TagName, each_TagName); output["TagName"] = each_TagName;
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

            ~RemovePlayerTagResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~RemoveServerBuildRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
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

            ~RemoveServerBuildResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~RemoveVirtualCurrencyTypesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["VirtualCurrencies"], VirtualCurrencies);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output["VirtualCurrencies"] = each_VirtualCurrencies;
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

            ~ResetCharacterStatisticsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~ResetCharacterStatisticsResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ResetPasswordRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["Token"], Token);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_Token; ToJsonUtilS(Token, each_Token); output["Token"] = each_Token;
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

            ~ResetPasswordResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ResetUserStatisticsRequest() = default;

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

        struct ResetUserStatisticsResult : public PlayFabResultCommon
        {

            ResetUserStatisticsResult() :
                PlayFabResultCommon()
            {}

            ResetUserStatisticsResult(const ResetUserStatisticsResult&) :
                PlayFabResultCommon()
            {}

            ~ResetUserStatisticsResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~ResolvePurchaseDisputeRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OrderId"], OrderId);
                FromJsonEnum(input["Outcome"], Outcome);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["Reason"], Reason);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output["OrderId"] = each_OrderId;
                Json::Value each_Outcome; ToJsonEnum(Outcome, each_Outcome); output["Outcome"] = each_Outcome;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
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

            ~ResolvePurchaseDisputeResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PurchaseStatus"], PurchaseStatus);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PurchaseStatus; ToJsonUtilS(PurchaseStatus, each_PurchaseStatus); output["PurchaseStatus"] = each_PurchaseStatus;
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

            ~RevokeAllBansForUserRequest() = default;

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

            ~RevokeAllBansForUserResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["BanData"], BanData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BanData; ToJsonUtilO(BanData, each_BanData); output["BanData"] = each_BanData;
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

            ~RevokeBansRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BanIds"], BanIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BanIds; ToJsonUtilS(BanIds, each_BanIds); output["BanIds"] = each_BanIds;
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

            ~RevokeBansResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["BanData"], BanData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BanData; ToJsonUtilO(BanData, each_BanData); output["BanData"] = each_BanData;
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

            ~RevokeInventoryItem() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["ItemInstanceId"], ItemInstanceId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output["ItemInstanceId"] = each_ItemInstanceId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~RevokeInventoryItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["ItemInstanceId"], ItemInstanceId);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output["ItemInstanceId"] = each_ItemInstanceId;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~RevokeInventoryItemsRequest() = default;

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

            ~RevokeItemError() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["Error"], Error);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Error; ToJsonUtilE(Error, each_Error); output["Error"] = each_Error;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
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

            ~RevokeInventoryItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Errors"], Errors);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Errors; ToJsonUtilO(Errors, each_Errors); output["Errors"] = each_Errors;
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

            ~RevokeInventoryResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~RunTaskRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Identifier"], Identifier);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output["Identifier"] = each_Identifier;
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

            ~RunTaskResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TaskInstanceId"], TaskInstanceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output["TaskInstanceId"] = each_TaskInstanceId;
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

            ~SendAccountRecoveryEmailRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Email"], Email);
                FromJsonUtilS(input["EmailTemplateId"], EmailTemplateId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Email; ToJsonUtilS(Email, each_Email); output["Email"] = each_Email;
                Json::Value each_EmailTemplateId; ToJsonUtilS(EmailTemplateId, each_EmailTemplateId); output["EmailTemplateId"] = each_EmailTemplateId;
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

            ~SetPlayerSecretRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayerSecret"], PlayerSecret);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output["PlayerSecret"] = each_PlayerSecret;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~SetPublishedRevisionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Revision"], Revision);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Revision; ToJsonUtilP(Revision, each_Revision); output["Revision"] = each_Revision;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~SetPublishedRevisionResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~SetPublisherDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Key"], Key);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Key; ToJsonUtilS(Key, each_Key); output["Key"] = each_Key;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
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

            ~SetPublisherDataResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~SetTitleDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Key"], Key);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Key; ToJsonUtilS(Key, each_Key); output["Key"] = each_Key;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
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

            ~SetTitleDataResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~SetupPushNotificationRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Credential"], Credential);
                FromJsonUtilS(input["Key"], Key);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["OverwriteOldARN"], OverwriteOldARN);
                FromJsonEnum(input["Platform"], Platform);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Credential; ToJsonUtilS(Credential, each_Credential); output["Credential"] = each_Credential;
                Json::Value each_Key; ToJsonUtilS(Key, each_Key); output["Key"] = each_Key;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_OverwriteOldARN; ToJsonUtilP(OverwriteOldARN, each_OverwriteOldARN); output["OverwriteOldARN"] = each_OverwriteOldARN;
                Json::Value each_Platform; ToJsonEnum(Platform, each_Platform); output["Platform"] = each_Platform;
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

            ~SetupPushNotificationResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ARN"], ARN);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ARN; ToJsonUtilS(ARN, each_ARN); output["ARN"] = each_ARN;
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

            ~SubtractUserVirtualCurrencyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
                FromJsonUtilS(input["VirtualCurrency"], VirtualCurrency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
                Json::Value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output["VirtualCurrency"] = each_VirtualCurrency;
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

            ~UpdateBanRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilS(input["BanId"], BanId);
                FromJsonUtilT(input["Expires"], Expires);
                FromJsonUtilS(input["IPAddress"], IPAddress);
                FromJsonUtilS(input["MACAddress"], MACAddress);
                FromJsonUtilP(input["Permanent"], Permanent);
                FromJsonUtilS(input["Reason"], Reason);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_BanId; ToJsonUtilS(BanId, each_BanId); output["BanId"] = each_BanId;
                Json::Value each_Expires; ToJsonUtilT(Expires, each_Expires); output["Expires"] = each_Expires;
                Json::Value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output["IPAddress"] = each_IPAddress;
                Json::Value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output["MACAddress"] = each_MACAddress;
                Json::Value each_Permanent; ToJsonUtilP(Permanent, each_Permanent); output["Permanent"] = each_Permanent;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
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

            ~UpdateBansRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bans"], Bans);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bans; ToJsonUtilO(Bans, each_Bans); output["Bans"] = each_Bans;
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

            ~UpdateBansResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["BanData"], BanData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BanData; ToJsonUtilO(BanData, each_BanData); output["BanData"] = each_BanData;
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

            ~UpdateCatalogItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Catalog"], Catalog);
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilP(input["SetAsDefaultCatalog"], SetAsDefaultCatalog);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Catalog; ToJsonUtilO(Catalog, each_Catalog); output["Catalog"] = each_Catalog;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_SetAsDefaultCatalog; ToJsonUtilP(SetAsDefaultCatalog, each_SetAsDefaultCatalog); output["SetAsDefaultCatalog"] = each_SetAsDefaultCatalog;
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

            ~UpdateCatalogItemsResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UpdateCloudScriptRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DeveloperPlayFabId"], DeveloperPlayFabId);
                FromJsonUtilO(input["Files"], Files);
                FromJsonUtilP(input["Publish"], Publish);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DeveloperPlayFabId; ToJsonUtilS(DeveloperPlayFabId, each_DeveloperPlayFabId); output["DeveloperPlayFabId"] = each_DeveloperPlayFabId;
                Json::Value each_Files; ToJsonUtilO(Files, each_Files); output["Files"] = each_Files;
                Json::Value each_Publish; ToJsonUtilP(Publish, each_Publish); output["Publish"] = each_Publish;
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

            ~UpdateCloudScriptResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Revision"], Revision);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Revision; ToJsonUtilP(Revision, each_Revision); output["Revision"] = each_Revision;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
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

            ~UpdatePlayerSharedSecretRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Disabled"], Disabled);
                FromJsonUtilS(input["FriendlyName"], FriendlyName);
                FromJsonUtilS(input["SecretKey"], SecretKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Disabled; ToJsonUtilP(Disabled, each_Disabled); output["Disabled"] = each_Disabled;
                Json::Value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output["FriendlyName"] = each_FriendlyName;
                Json::Value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output["SecretKey"] = each_SecretKey;
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

            ~UpdatePlayerSharedSecretResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UpdatePlayerStatisticDefinitionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["AggregationMethod"], AggregationMethod);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilE(input["VersionChangeInterval"], VersionChangeInterval);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output["AggregationMethod"] = each_AggregationMethod;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output["VersionChangeInterval"] = each_VersionChangeInterval;
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

            ~UpdatePlayerStatisticDefinitionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Statistic"], Statistic);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Statistic; ToJsonUtilO(Statistic, each_Statistic); output["Statistic"] = each_Statistic;
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

            ~UpdatePolicyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["OverwritePolicy"], OverwritePolicy);
                FromJsonUtilS(input["PolicyName"], PolicyName);
                FromJsonUtilO(input["Statements"], Statements);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OverwritePolicy; ToJsonUtilP(OverwritePolicy, each_OverwritePolicy); output["OverwritePolicy"] = each_OverwritePolicy;
                Json::Value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output["PolicyName"] = each_PolicyName;
                Json::Value each_Statements; ToJsonUtilO(Statements, each_Statements); output["Statements"] = each_Statements;
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

            ~UpdatePolicyResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PolicyName"], PolicyName);
                FromJsonUtilO(input["Statements"], Statements);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output["PolicyName"] = each_PolicyName;
                Json::Value each_Statements; ToJsonUtilO(Statements, each_Statements); output["Statements"] = each_Statements;
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

            ~UpdateRandomResultTablesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input["Tables"], Tables);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_Tables; ToJsonUtilO(Tables, each_Tables); output["Tables"] = each_Tables;
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

            ~UpdateRandomResultTablesResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~UpdateStoreItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CatalogVersion"], CatalogVersion);
                FromJsonUtilO(input["MarketingData"], MarketingData);
                FromJsonUtilO(input["Store"], Store);
                FromJsonUtilS(input["StoreId"], StoreId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output["CatalogVersion"] = each_CatalogVersion;
                Json::Value each_MarketingData; ToJsonUtilO(MarketingData, each_MarketingData); output["MarketingData"] = each_MarketingData;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                Json::Value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output["StoreId"] = each_StoreId;
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

            ~UpdateStoreItemsResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct UpdateTaskRequest : public PlayFabRequestCommon
        {
            std::string Description;
            Boxed<NameIdentifier> Identifier;
            bool IsActive;
            std::string Name;
            Json::Value Parameter;
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

            ~UpdateTaskRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilO(input["Identifier"], Identifier);
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilS(input["Name"], Name);
                Parameter = input["Parameter"];
                FromJsonUtilS(input["Schedule"], Schedule);
                FromJsonEnum(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output["Identifier"] = each_Identifier;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                output["Parameter"] = Parameter;
                Json::Value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output["Schedule"] = each_Schedule;
                Json::Value each_Type; ToJsonEnum(Type, each_Type); output["Type"] = each_Type;
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

            ~UpdateUserDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Data"], Data);
                FromJsonUtilS(input["KeysToRemove"], KeysToRemove);
                FromJsonUtilE(input["Permission"], Permission);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output["KeysToRemove"] = each_KeysToRemove;
                Json::Value each_Permission; ToJsonUtilE(Permission, each_Permission); output["Permission"] = each_Permission;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~UpdateUserInternalDataRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Data"], Data);
                FromJsonUtilS(input["KeysToRemove"], KeysToRemove);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Data; ToJsonUtilS(Data, each_Data); output["Data"] = each_Data;
                Json::Value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output["KeysToRemove"] = each_KeysToRemove;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

            ~UpdateUserTitleDisplayNameRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilS(input["PlayFabId"], PlayFabId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output["PlayFabId"] = each_PlayFabId;
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

    }
}

#endif
