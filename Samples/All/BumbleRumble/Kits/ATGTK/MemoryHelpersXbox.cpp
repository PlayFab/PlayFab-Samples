//--------------------------------------------------------------------------------------
// MemoryHelpersXbox.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "MemoryHelpersXbox.h"
#include "pixMemory.h"
#include <unordered_map>
#include <mutex>

#if !defined(_XBOX_ONE) || !defined(_TITLE)
#error This file only supports Xbox One XDK apps
#endif

using namespace ATG::XMemAllocHelpers;

namespace
{
    static const uint64_t s_sentinelValue = 0xEDFDDEADBEEFFDBD;
    static const uint64_t s_sentinelSize = sizeof(s_sentinelValue);

    inline void SetSentinelValue(void *baseAddress, uint64_t size)
    {
        (*reinterpret_cast<uint64_t *> (reinterpret_cast<char *> (baseAddress) + size)) = s_sentinelValue;
    }
    inline bool CheckSentinelValue(void *baseAddress, uint64_t size)
    {
        uint64_t localValue = *reinterpret_cast<uint64_t *> (reinterpret_cast<char *> (baseAddress) + size);
        assert(localValue == s_sentinelValue);
        return localValue == s_sentinelValue;
    }

    struct DebugDataHash
    {
        size_t operator() (const void * const& value) const
        {
            uintptr_t temp = reinterpret_cast<uintptr_t> (value);
            return temp >> 8ULL;       // just remove the lower bits from the equation in the final bucket mod
        }
    };

    bool s_mainHookInstalled = false;
    bool s_enableSentinelValues = false;
    bool s_onlyTrackGameAllocations = false;
    MemoryAllocRoutine s_titleAllocHook;
    MemoryFreeRoutine s_titleFreeHook;
    MemoryTweakRoutine s_titleTweakHook;
    std::recursive_mutex s_memoryStatisticsMutex;       // need a recursive_mutex due to updating the statistics could allocate memory

                                                        // ideally these entries should be fully allocated ahead of time to avoid extra allocations during an allocations
                                                        // however this is only for samples and not a fully robust system for a game engine
                                                        // if only track game allocations is enable then any allocations related to these blocks will not be counted
    std::unordered_map <uint64_t, MemoryAllocationDataBlock> s_objectTypeStatistics;
    std::unordered_map <uint64_t, MemoryAllocationDataBlock> s_pageSizeStatistics;
    std::unordered_map <uint64_t, MemoryAllocationDataBlock> s_allocatorIdStatistics;
    std::unordered_map <uint64_t, MemoryAllocationDataBlock> s_memoryTypeStatistics;
    std::unordered_map <const void*, MemoryDebugData, DebugDataHash> s_mapAddressToDebugData;

    void *AtgTkXMemAllocHook(size_t requestedSize, uint64_t attributes)
    {
        void *toret = nullptr;
        size_t adjustedSize = requestedSize;

        if (s_titleTweakHook)
            s_titleTweakHook(adjustedSize, attributes);

        XALLOC_ATTRIBUTES bitField;
        bitField.dwAttributes = attributes;
        bool titleRequest = ((bitField.s.dwAllocatorId >= eXALLOCAllocatorId_GameMin) && (bitField.s.dwAllocatorId <= eXALLOCAllocatorId_GameMax));
        bool useSentinelValue = s_enableSentinelValues && (!s_onlyTrackGameAllocations || titleRequest);

        if (s_titleAllocHook)
            toret = s_titleAllocHook(adjustedSize + (useSentinelValue ? s_sentinelSize : 0), attributes);
        else
            toret = XMemAllocDefault(adjustedSize + (useSentinelValue ? s_sentinelSize : 0), attributes);

        if (toret)
        {
            if (!s_onlyTrackGameAllocations || titleRequest)
            {
                std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
                s_objectTypeStatistics[bitField.s.dwObjectType].UpdateAllocation(adjustedSize);
                s_pageSizeStatistics[bitField.s.dwPageSize].UpdateAllocation(adjustedSize);
                s_allocatorIdStatistics[bitField.s.dwAllocatorId].UpdateAllocation(adjustedSize);
                s_memoryTypeStatistics[bitField.s.dwMemoryType].UpdateAllocation(adjustedSize);
                s_mapAddressToDebugData[toret] = MemoryDebugData(adjustedSize, attributes);
            }
            PIXRecordMemoryAllocationEvent(0, toret, adjustedSize, attributes);
            if (useSentinelValue)
            {
                SetSentinelValue(toret, adjustedSize);
            }
        }
        return toret;
    }

    void AtgTkXMemFreeHook(void *address, uint64_t attributes)
    {
        // check if it's an allocation we know about, if not ignore and route straight to XMemFreeDefault
        {
            s_memoryStatisticsMutex.lock();                     // no lock_guard usage here due to wanting to explicitly unlock before the call to XMemFreeDefault.
            auto iter = s_mapAddressToDebugData.find(address);  // this helps performance immensely across threads.
            if (iter == s_mapAddressToDebugData.end())
            {
                s_memoryStatisticsMutex.unlock();
                XMemFreeDefault(address, attributes);
                PIXRecordMemoryFreeEvent(0, address, 0, attributes);
                return;
            }
            s_memoryStatisticsMutex.unlock();
        }

        {
            s_memoryStatisticsMutex.lock();                     // no lock_guard usage here due to wanting to explicitly unlock right after the copy of the data is made.
            auto iter = s_mapAddressToDebugData.find(address);
            if (iter == s_mapAddressToDebugData.end())
            {
                s_memoryStatisticsMutex.unlock();
                assert(false);      // if this fires it's probably a good chance of a double free from multiple threads at the same time
            }                       // we just continue and pass along to the memory free function to let the normal memory system handle
            else
            {
                MemoryDebugData debugData = iter->second;       // make a copy of the data, in theory removal from the address map
                s_mapAddressToDebugData.erase(iter);            // could end up in another call into this function
                s_memoryStatisticsMutex.unlock();

                if (s_titleTweakHook)
                    s_titleTweakHook(debugData.size, attributes);

                XALLOC_ATTRIBUTES bitField;
                bitField.dwAttributes = attributes;

                bool titleRequest = ((bitField.s.dwAllocatorId >= eXALLOCAllocatorId_GameMin) && (bitField.s.dwAllocatorId <= eXALLOCAllocatorId_GameMax));
                bool useSentinelValue = s_enableSentinelValues && (!s_onlyTrackGameAllocations || titleRequest);

                if (useSentinelValue)
                    CheckSentinelValue(address, debugData.size);

                if (!s_onlyTrackGameAllocations || titleRequest)
                {
                    std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
                    s_objectTypeStatistics[bitField.s.dwObjectType].UpdateFree(debugData.size);
                    s_pageSizeStatistics[bitField.s.dwPageSize].UpdateFree(debugData.size);
                    s_allocatorIdStatistics[bitField.s.dwAllocatorId].UpdateFree(debugData.size);
                    s_memoryTypeStatistics[bitField.s.dwMemoryType].UpdateFree(debugData.size);
                }
            }
        }

        // finally free the memory
        if (s_titleFreeHook)
            s_titleFreeHook(address, attributes);
        else
            XMemFreeDefault(address, attributes);

        PIXRecordMemoryFreeEvent(0, address, 0, attributes);
    }
}

MemoryAllocationDataBlock ATG::XMemAllocHelpers::GetAllocationStatisticsForObjectType(uint64_t objectType)
{
    std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
    auto iter = s_objectTypeStatistics.find(objectType);
    if (iter == s_objectTypeStatistics.end())
        return MemoryAllocationDataBlock();
    return iter->second;
}
MemoryAllocationDataBlock ATG::XMemAllocHelpers::GetAllocationStatisticsForPageSize(uint64_t pageSize)
{
    std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
    auto iter = s_pageSizeStatistics.find(pageSize);
    if (iter == s_pageSizeStatistics.end())
        return MemoryAllocationDataBlock();
    return iter->second;
}
MemoryAllocationDataBlock ATG::XMemAllocHelpers::GetAllocationStatisticsForAllocatorId(uint64_t allocatorId)
{
    std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
    auto iter = s_allocatorIdStatistics.find(allocatorId);
    if (iter == s_allocatorIdStatistics.end())
        return MemoryAllocationDataBlock();
    return iter->second;
}
MemoryAllocationDataBlock ATG::XMemAllocHelpers::GetAllocationStatisticsForMemoryType(uint64_t memoryType)
{
    std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
    auto iter = s_memoryTypeStatistics.find(memoryType);
    if (iter == s_memoryTypeStatistics.end())
        return MemoryAllocationDataBlock();
    return iter->second;
}

MemoryDebugData ATG::XMemAllocHelpers::GetMemoryDebugData(_In_opt_ const void *address)
{
    std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
    auto iter = s_mapAddressToDebugData.find(address);
    if (iter == s_mapAddressToDebugData.end())
        return MemoryDebugData();
    return iter->second;
}

void ATG::XMemAllocHelpers::InstallMainMemoryHooks(bool enableSentinelValues, bool onlyTrackGameAllocations)
{
    std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
    assert(!s_mainHookInstalled);
    s_enableSentinelValues = enableSentinelValues;
    s_onlyTrackGameAllocations = onlyTrackGameAllocations;

    // explicitly try and reserve some spots in the maps before memory tracking. This is debug memory and I don't really want to track it
    // since it's not direct memory used normally by the title. It's not a fully clean memory tracking system, but then a sample isn't a fully
    // clean title. This should at least reduce the chance of an expensive rehash and memory allocation during insertion
    s_pageSizeStatistics.reserve(4);        // only 2 bits needed
    s_memoryTypeStatistics.reserve(16);     // only 4 bits needed
    s_objectTypeStatistics.reserve(16);     // 14 bits needed, however probably don't need to represent the full range
    s_allocatorIdStatistics.reserve(32);    // 8 bits needed, however probably don't need to represent the full range

    s_mapAddressToDebugData.max_load_factor(100);   // allow these buckets to get fairly large, 100 elements per bucket.
    s_mapAddressToDebugData.reserve(200000);        // one entry needed per active allocation, we want at least 2000 buckets with a maximum of 100 elements per bucket

    XMemSetAllocationHooks(AtgTkXMemAllocHook, AtgTkXMemFreeHook);

    s_mainHookInstalled = true;
}

void ATG::XMemAllocHelpers::InstallXMemAllocTweakHooks(const MemoryTweakRoutine& tweakRoutine)
{
    if (!s_mainHookInstalled)
        InstallMainMemoryHooks();
    s_titleTweakHook = tweakRoutine;
}

void ATG::XMemAllocHelpers::InstallXMemAllocHooks(const MemoryAllocRoutine& allocRoutine, const MemoryFreeRoutine& freeRoutine)
{
    if (!s_mainHookInstalled)
        InstallMainMemoryHooks();
    XMemSetAllocationHooks(AtgTkXMemAllocHook, AtgTkXMemFreeHook);
    s_titleAllocHook = allocRoutine;
    s_titleFreeHook = freeRoutine;
}

void ATG::XMemAllocHelpers::ResetXMemAllocHooks()
{
    std::lock_guard<std::recursive_mutex> guard(s_memoryStatisticsMutex);
    assert(s_mainHookInstalled);
    XMemSetAllocationHooks(XMemAllocDefault, XMemFreeDefault);
    s_mainHookInstalled = false;
    s_objectTypeStatistics.clear();
    s_pageSizeStatistics.clear();
    s_allocatorIdStatistics.clear();
    s_memoryTypeStatistics.clear();
    s_mapAddressToDebugData.clear();
}
