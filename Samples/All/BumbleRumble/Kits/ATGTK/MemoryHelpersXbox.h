//--------------------------------------------------------------------------------------
// MemoryHelpersXbox.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#pragma once

#if !defined(_XBOX_ONE) || !defined(_TITLE)
#error This file only supports Xbox One XDK apps
#endif

#include <cstdint>
#include <functional>

namespace ATG
{
    namespace XMemAllocHelpers
    {
        // individual entry for each allocation in the system, also used to determine if we created the allocation when performing free
        struct MemoryDebugData
        {
            MemoryDebugData(size_t allocSize = 0, uint64_t allocAttribs = 0)
                : size(allocSize)
                , attribs(allocAttribs)
            {
            }

            size_t size;
            uint64_t attribs;
        };

        // statistics on each allocation type, split among objectType, pageSize, allocatorId, and memoryType
        struct MemoryAllocationDataBlock
        {
            uint64_t m_currentAllocationCount;          // access to these structures is protected by a mutex, no need for an atomic
            uint64_t m_highWaterAllocationCount;
            uint64_t m_lifetimeAllocationCount;
            uint64_t m_currentAllocationBytes;
            uint64_t m_highWaterMarkBytes;
            uint64_t m_lifetimeAllocationBytes;
            MemoryAllocationDataBlock() : m_currentAllocationCount(0), m_highWaterAllocationCount(0)
                , m_lifetimeAllocationCount(0), m_currentAllocationBytes(0)
                , m_highWaterMarkBytes(0), m_lifetimeAllocationBytes(0) {}

            void UpdateAllocation(uint64_t size)
            {
                m_currentAllocationCount++;
                m_lifetimeAllocationCount++;
                m_highWaterAllocationCount = m_currentAllocationCount > m_highWaterAllocationCount ? m_currentAllocationCount : m_highWaterAllocationCount;
                m_currentAllocationBytes += size;
                m_lifetimeAllocationBytes += size;
                m_highWaterMarkBytes = m_currentAllocationBytes > m_highWaterMarkBytes ? m_currentAllocationBytes : m_highWaterMarkBytes;
            }

            void UpdateFree(uint64_t size)
            {
                assert(m_currentAllocationCount > 0);
                m_currentAllocationCount--;
                assert(m_currentAllocationBytes >= size);
                m_currentAllocationBytes -= size;
            }
        };

        // routines used to override the actual allocation
        typedef std::function<void * (size_t size, uint64_t attributes)> MemoryAllocRoutine;
        typedef std::function<bool(void *address, uint64_t attributes)> MemoryFreeRoutine;

        // routines used to change the allocation parameters before performing the allocation
        typedef std::function<void(size_t& size, uint64_t& attributes)> MemoryTweakRoutine;

        MemoryAllocationDataBlock GetAllocationStatisticsForObjectType(uint64_t attributes);
        MemoryAllocationDataBlock GetAllocationStatisticsForPageSize(uint64_t attributes);
        MemoryAllocationDataBlock GetAllocationStatisticsForAllocatorId(uint64_t attributes);
        MemoryAllocationDataBlock GetAllocationStatisticsForMemoryType(uint64_t attributes);
        MemoryDebugData GetMemoryDebugData(_In_opt_ const void *address);

        // setup the initial hooks to track memory allocations, if only this function is called all allocations go to XMemAllocDefault
        void InstallMainMemoryHooks(bool enableSentinelValues = true, bool onlyTrackGameAllocations = true);

        void InstallXMemAllocTweakHooks(const MemoryTweakRoutine& memoryTweakRoutine);
        void InstallXMemAllocHooks(const MemoryAllocRoutine& memoryAllocRoutine, const MemoryFreeRoutine& memoryFreeRoutine);

        // disable hooks and route all allocations back to XMem###Default
        void ResetXMemAllocHooks();
    }
}
