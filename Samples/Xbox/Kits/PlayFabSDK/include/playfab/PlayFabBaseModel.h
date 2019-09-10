#pragma once

#include "cpprest/json.h"
#include <ctime>
#include <functional>
#include <list>
#include <map>
#include <assert.h>

namespace PlayFab
{
#ifdef WIN32
    typedef signed __int64 Int64;
    typedef signed __int32 Int32;
    typedef signed __int16 Int16;

    typedef unsigned __int64 Uint64;
    typedef unsigned __int32 Uint32;
    typedef unsigned __int16 Uint16;
#else
    typedef int64_t Int64;
    typedef int32_t Int32;
    typedef int16_t Int16;

    typedef uint64_t Uint64;
    typedef uint32_t Uint32;
    typedef uint16_t Uint16;
#endif
    /// <summary>
    /// Utility to convert from ansi-string to UTF-16 string
    /// </summary>
    inline utility::string_t WidenString(std::string input)
    {
        return utility::string_t(input.begin(), input.end());
    }
    /// <summary>
    /// Utility to convert from UTF-16 string to ansi-string
    /// </summary>
    inline std::string ShortenString(utility::string_t input)
    {
        return std::string(input.begin(), input.end());
    }

    template <typename BoxedType>
    class Boxed
    {
    public:
        Boxed() : mValue(), mIsSet(false) {}
        Boxed(BoxedType value) : mValue(value), mIsSet(true) {}

        inline Boxed& operator=(BoxedType value) { mValue = value; mIsSet = true; return *this; }
        inline operator const BoxedType& () const { assert(notNull()); return *operator->(); }
        inline BoxedType* operator->() { return mIsSet ? &mValue : nullptr; }
        inline const BoxedType* operator->() const { return mIsSet ? &mValue : nullptr; }

        inline void setNull() { mIsSet = false; }
        inline bool notNull() const { return mIsSet; }
        inline bool isNull() const { return !mIsSet; }
    private:
        BoxedType mValue;
        bool mIsSet;
    };

    template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* customData)>;

    /// <summary>
    /// Base class for all PlayFab Models
    /// Provides interface for converting to/from json
    /// </summary>
    struct PlayFabBaseModel
    {
        virtual ~PlayFabBaseModel() {}
        virtual void FromJson(web::json::value& input) = 0; // We explicitly choose not to make web::json::value const here, because it restricts available syntax
        virtual web::json::value ToJson() const = 0;
    };

    /// <summary>
    /// Base class for all PlayFab Requests
    /// Adds a parameter that controls how requests are threaded
    /// </summary>
    struct PlayFabRequestCommon : public PlayFabBaseModel { };

    /// <summary>
    /// Base class for all PlayFab Results
    /// </summary>
    struct PlayFabResultCommon : public PlayFabBaseModel {
        web::json::value Request;
    };

    // Utilities for [de]serializing time_t to/from json
    inline void ToJsonUtilT(const time_t input, web::json::value& output)
    {
        struct tm timeInfo;
        gmtime_s(&timeInfo, &input);
        char buff[40];
        strftime(buff, 40, "%Y-%m-%dT%H:%M:%S.000Z", &timeInfo);
        output = web::json::value(WidenString(buff));
    }
    inline void FromJsonUtilT(const web::json::value& input, time_t& output)
    {
        if (input.is_null()) return;
        std::string timeStr = ShortenString(input.as_string());
        tm timeStruct = {};
        unsigned int milliseconds = 0; // milliseconds are truncated in a standard time_t structure
        sscanf_s(timeStr.c_str(), "%u-%u-%uT%u:%u%u.%uZ", &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday,
            &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec, &milliseconds);
        timeStruct.tm_year -= 1900;
        timeStruct.tm_mon -= 1;
        output = mktime(&timeStruct);
    }
    inline void ToJsonUtilT(const Boxed<time_t>& input, web::json::value& output)
    {
        if (input.isNull())
        {
            output = web::json::value();
        }
        else
        {
            ToJsonUtilT(static_cast<time_t>(input), output);
        }
    }
    inline void FromJsonUtilT(const web::json::value& input, Boxed<time_t>& output)
    {
        if (input.is_null())
        {
            output.setNull();
        }
        else
        {
            time_t outputVal;
            FromJsonUtilT(input, outputVal);
            output = outputVal;
        }
    }
    inline void ToJsonUtilT(const std::list<time_t>& input, web::json::value& output)
    {
        if (input.size() == 0)
        {
            output = web::json::value::null();
        }
        else
        {
            output = web::json::value::array();
            web::json::value eachOutput;
            int index = 0;
            for (auto iter = input.begin(); iter != input.end(); ++iter)
            {
                ToJsonUtilT(*iter, eachOutput);
                output[index++] = eachOutput;
            }
        }
    }
    inline void FromJsonUtilT(web::json::value& input, std::list<time_t>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        time_t eachOutput;
        web::json::array& inputArray = input.as_array();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonUtilT(*iter, eachOutput);
            output.push_back(eachOutput);
        }
    }
    inline void ToJsonUtilT(const std::map<std::string, time_t>& input, web::json::value& output)
    {
        output = web::json::value::object();
        web::json::value eachOutput;
        for (auto iter = input.begin(); iter != input.end(); ++iter)
        {
            ToJsonUtilT(iter->second, eachOutput);
            output[WidenString(iter->first)] = eachOutput;
        }
    }
    inline void FromJsonUtilT(web::json::value& input, std::map<std::string, time_t>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        time_t eachOutput;
        web::json::object& inputArray = input.as_object();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonUtilT(iter->second, eachOutput);
            output[ShortenString(iter->first)] = eachOutput;
        }
    }

    // Utilities for [de]serializing EnumType to/from json
    template <typename EnumType> inline void ToJsonUtilE(const Boxed<EnumType>& input, web::json::value& output)
    {
        if (input.isNull())
        {
            output = web::json::value();
        }
        else
        {
            ToJsonEnum(input, output);
        }
    }
    template <typename EnumType> inline void FromJsonUtilE(const web::json::value& input, Boxed<EnumType>& output)
    {
        if (input.is_null())
        {
            output.setNull();
        }
        else
        {
            EnumType outputVal;
            FromJsonEnum(input, outputVal);
            output = outputVal;
        }
    }
    template <typename EnumType> inline void ToJsonUtilE(const std::list<EnumType>& input, web::json::value& output)
    {
        if (input.size() == 0)
        {
            output = web::json::value::null();
        }
        else
        {
            output = web::json::value::array();
            web::json::value eachOutput;
            int index = 0;
            for (auto iter = input.begin(); iter != input.end(); ++iter)
            {
                ToJsonEnum(*iter, eachOutput);
                output[index++] = eachOutput;
            }
        }
    }
    template <typename EnumType> inline void FromJsonUtilE(web::json::value& input, std::list<EnumType>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        EnumType eachOutput;
        web::json::array& inputArray = input.as_array();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonEnum(*iter, eachOutput);
            output.push_back(eachOutput);
        }
    }
    template <typename EnumType> inline void ToJsonUtilE(const std::map<std::string, EnumType>& input, web::json::value& output)
    {
        output = web::json::value::object();
        web::json::value eachOutput;
        for (auto iter = input.begin(); iter != input.end(); ++iter)
        {
            ToJsonEnum(iter->second, eachOutput);
            output[WidenString(iter->first)] = eachOutput;
        }
    }
    template <typename EnumType> inline void FromJsonUtilE(web::json::value& input, std::map<std::string, EnumType>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        EnumType eachOutput;
        web::json::object& inputArray = input.as_object();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonEnum(iter->second, eachOutput);
            output[ShortenString(iter->first)] = eachOutput;
        }
    }

    // Utilities for [de]serializing string to/from json
    inline void ToJsonUtilS(const std::string& input, web::json::value& output)
    {
        if (input.length() == 0)
            output = web::json::value::null();
        else
            output = web::json::value::string(WidenString(input));
    }
    inline void FromJsonUtilS(const web::json::value& input, std::string& output)
    {
        if (input.is_null())
            output.clear();
        else
            output = ShortenString(input.as_string());
    }
    inline void ToJsonUtilS(const std::list<std::string>& input, web::json::value& output)
    {
        if (input.size() == 0)
        {
            output = web::json::value::null();
        }
        else
        {
            output = web::json::value::array();
            web::json::value eachOutput;
            int index = 0;
            for (auto iter = input.begin(); iter != input.end(); ++iter)
            {
                ToJsonUtilS(*iter, eachOutput);
                output[index++] = eachOutput;
            }
        }
    }
    inline void FromJsonUtilS(web::json::value& input, std::list<std::string>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        std::string eachOutput;
        web::json::array& inputArray = input.as_array();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonUtilS(*iter, eachOutput);
            output.push_back(eachOutput);
        }
    }
    inline void ToJsonUtilS(const std::map<std::string, std::string>& input, web::json::value& output)
    {
        output = web::json::value::object();
        web::json::value eachOutput;
        for (auto iter = input.begin(); iter != input.end(); ++iter)
        {
            ToJsonUtilS(iter->second, eachOutput);
            output[WidenString(iter->first)] = eachOutput;
        }
    }
    inline void FromJsonUtilS(web::json::value& input, std::map<std::string, std::string>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        std::string eachOutput;
        web::json::object& inputArray = input.as_object();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonUtilS(iter->second, eachOutput);
            output[ShortenString(iter->first)] = eachOutput;
        }
    }

    // Utilities for [de]serializing PlayFabObjects to/from json
    inline void ToJsonUtilO(const PlayFabBaseModel& input, web::json::value& output)
    {
        output = input.ToJson();
    }
    inline void FromJsonUtilO(web::json::value& input, PlayFabBaseModel& output)
    {
        output.FromJson(input);
    }
    template <typename ObjectType> inline void ToJsonUtilO(const Boxed<ObjectType> input, web::json::value& output)
    {
        if (input.isNull())
            output = web::json::value();
        else
        {
            const ObjectType &obj = input;
            output = obj.ToJson();
        }
    }
    template <typename ObjectType> inline void FromJsonUtilO(web::json::value& input, Boxed<ObjectType>& output)
    {
        if (input.is_null())
            output.setNull();
        else
        {
            ObjectType outputTemp;
            outputTemp.FromJson(input);
            output = outputTemp;
        }
    }
    template <typename ObjectType> inline void ToJsonUtilO(const std::list<ObjectType>& input, web::json::value& output)
    {
        if (input.size() == 0)
        {
            output = web::json::value::null();
        }
        else
        {
            output = web::json::value::array();
            web::json::value eachOutput;
            int index = 0;
            for (auto iter = input.begin(); iter != input.end(); ++iter)
            {
                ToJsonUtilO(*iter, eachOutput);
                output[index++] = eachOutput;
            }
        }
    }
    template <typename ObjectType> inline void FromJsonUtilO(web::json::value& input, std::list<ObjectType>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        ObjectType eachOutput;
        web::json::array& inputArray = input.as_array();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonUtilO(*iter, eachOutput);
            output.push_back(eachOutput);
        }
    }
    template <typename ObjectType> inline void ToJsonUtilO(const std::map<std::string, ObjectType>& input, web::json::value& output)
    {
        output = web::json::value::object();
        web::json::value eachOutput;
        for (auto iter = input.begin(); iter != input.end(); ++iter)
        {
            ToJsonUtilO(iter->second, eachOutput);
            output[WidenString(iter->first)] = eachOutput;
        }
    }
    template <typename ObjectType> inline void FromJsonUtilO(web::json::value& input, std::map<std::string, ObjectType>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        ObjectType eachOutput;
        web::json::object& inputArray = input.as_object();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonUtilO(iter->second, eachOutput);
            output[ShortenString(iter->first)] = eachOutput;
        }
    }

    // Utilities for [de]serializing primitives to/from json
    template <typename PrimitiveType> inline void ToJsonUtilP(const PrimitiveType input, web::json::value& output)
    {
        output = web::json::value(input);
    }
    inline void FromJsonUtilP(const web::json::value& input, bool& output)
    {
        if (!input.is_null()) output = input.as_bool();
    }
    inline void FromJsonUtilP(const web::json::value& input, Int16& output)
    {
        if (!input.is_null()) output = static_cast<Int16>(input.as_integer());
    }
    inline void FromJsonUtilP(const web::json::value& input, Uint16& output)
    {
        if (!input.is_null()) output = static_cast<Uint16>(input.as_integer());
    }
    inline void FromJsonUtilP(const web::json::value& input, Int32& output)
    {
        if (!input.is_null()) output = input.as_integer();
    }
    inline void FromJsonUtilP(const web::json::value& input, Uint32& output)
    {
        if (!input.is_null()) output = input.as_number().to_uint32();
    }
    inline void FromJsonUtilP(const web::json::value& input, Int64& output)
    {
        if (!input.is_null()) output = input.as_number().to_int64();
    }
    inline void FromJsonUtilP(const web::json::value& input, Uint64& output)
    {
        if (!input.is_null()) output = input.as_number().to_uint64();
    }
    inline void FromJsonUtilP(const web::json::value& input, float& output)
    {
        if (!input.is_null()) output = static_cast<float>(input.as_double());
    }
    inline void FromJsonUtilP(const web::json::value& input, double& output)
    {
        if (!input.is_null()) output = input.as_double();
    }
    template <typename PrimitiveType> inline void ToJsonUtilP(const Boxed<PrimitiveType>& input, web::json::value& output)
    {
        if (input.isNull())
        {
            output = web::json::value();
        }
        else
        {
            ToJsonUtilP(static_cast<PrimitiveType>(input), output);
        }
    }
    template <typename PrimitiveType> inline void FromJsonUtilP(const web::json::value& input, Boxed<PrimitiveType>& output)
    {
        if (input.is_null())
        {
            output.setNull();
        }
        else
        {
            PrimitiveType outputVal;
            FromJsonUtilP(input, outputVal);
            output = outputVal;
        }
    }
    template <typename PrimitiveType> inline void ToJsonUtilP(const std::list<PrimitiveType>& input, web::json::value& output)
    {
        if (input.size() == 0)
        {
            output = web::json::value::null();
        }
        else
        {
            output = web::json::value::array();
            web::json::value eachOutput;
            int index = 0;
            for (auto iter = input.begin(); iter != input.end(); ++iter)
            {
                FromJsonUtilP(*iter, eachOutput);
                output[index++] = eachOutput;
            }
        }
    }
    template <typename PrimitiveType> inline void FromJsonUtilP(web::json::value& input, std::list<PrimitiveType>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        PrimitiveType eachOutput;
        web::json::array& inputArray = input.as_array();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonUtilP(*iter, eachOutput);
            output.push_back(eachOutput);
        }
    }
    template <typename PrimitiveType> inline void ToJsonUtilP(const std::map<std::string, PrimitiveType>& input, web::json::value& output)
    {
        output = web::json::value::object();
        web::json::value eachOutput;
        for (auto iter = input.begin(); iter != input.end(); ++iter)
        {
            ToJsonUtilP(iter->second, eachOutput);
            output[WidenString(iter->first)] = eachOutput;
        }
    }
    template <typename PrimitiveType> inline void FromJsonUtilP(web::json::value& input, std::map<std::string, PrimitiveType>& output)
    {
        output.clear();
        if (input.is_null())
            return;

        PrimitiveType eachOutput;
        web::json::object& inputArray = input.as_object();
        for (auto iter = inputArray.begin(); iter != inputArray.end(); ++iter)
        {
            FromJsonUtilP(iter->second, eachOutput);
            output[ShortenString(iter->first)] = eachOutput;
        }
    }
}

