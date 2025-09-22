#include "pch.h"
#include "XUserFileStorage.h"

struct FileHandleCloser
{
    void operator()(HANDLE f)
    {
        CloseHandle(f);
    }
};

using FileHandle = std::unique_ptr<std::remove_pointer<HANDLE>::type, FileHandleCloser>;

std::string& PathPrefix()
{
    static std::string s_pathPrefix;
    return s_pathPrefix;
}

std::string MakeName(char const* key)
{
    return PathPrefix() + key + ".json";
}

HRESULT XUserFileStorage::Init(XTaskQueueHandle queue, _In_opt_z_ char const* pathPrefix)
{
    if (pathPrefix)
    {
        PathPrefix() = pathPrefix;
    }

    XUserPlatformStorageEventHandlers handlers = {};
    handlers.write = &OnWrite;
    handlers.read = &OnRead;
    handlers.clear = &OnClear;
    handlers.context = nullptr;

    HRESULT hr = XUserPlatformStorageSetEventHandlers(queue, &handlers);
    assert(SUCCEEDED(hr));
    UNREFERENCED_PARAMETER(hr);
    return hr;
}

void XUserFileStorage::OnWrite(
    _In_opt_ void* /*context*/,
    _In_ uint32_t /*userIdentifier*/,
    _In_ XUserPlatformOperation operation,
    _In_z_ char const* key,
    _In_ size_t dataSize,
    _In_reads_bytes_(dataSize) void const* data
)
{
    std::string name = MakeName(key);

    FileHandle f{ CreateFileA(
        name.c_str(),
        GENERIC_WRITE,
        FILE_SHARE_READ,
        nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    ) };

    if (f.get() == INVALID_HANDLE_VALUE)
    {
        XUserPlatformStorageWriteComplete(operation, XUserPlatformOperationResult::Failure);
        return;
    }

    DWORD written = 0;
    if (!WriteFile(f.get(), data, static_cast<DWORD>(dataSize), &written, nullptr) || written != dataSize)
    {
        XUserPlatformStorageWriteComplete(operation, XUserPlatformOperationResult::Failure);
        return;
    }

    XUserPlatformStorageWriteComplete(operation, XUserPlatformOperationResult::Success);
}

void XUserFileStorage::OnRead(
    _In_opt_ void* /*context*/,
    _In_ uint32_t /*userIdentifier*/,
    _In_ XUserPlatformOperation operation,
    _In_z_ char const* key
)
{
    std::string name = MakeName(key);

    FileHandle f{ CreateFileA(
        name.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    ) };

    if (f.get() == INVALID_HANDLE_VALUE)
    {
        DWORD error = GetLastError();

        if (error == ERROR_FILE_NOT_FOUND)
        {
            XUserPlatformStorageReadComplete(operation, XUserPlatformOperationResult::Success, 0, nullptr);
            return;
        }
        else
        {
            XUserPlatformStorageReadComplete(operation, XUserPlatformOperationResult::Failure, 0, nullptr);
            return;
        }
    }

    LARGE_INTEGER fileSize = { 0 };
    if (!GetFileSizeEx(f.get(), &fileSize))
    {
        XUserPlatformStorageReadComplete(operation, XUserPlatformOperationResult::Failure, 0, nullptr);
        return;
    }

    DWORD read = 0;
    std::vector<uint8_t> data(fileSize.LowPart);
    if (!ReadFile(f.get(), data.data(), static_cast<DWORD>(data.size()), &read, nullptr) || read != data.size())
    {
        XUserPlatformStorageReadComplete(operation, XUserPlatformOperationResult::Failure, 0, nullptr);
        return;
    }

    XUserPlatformStorageReadComplete(operation, XUserPlatformOperationResult::Success, data.size(), data.data());
}

void XUserFileStorage::OnClear(
    _In_opt_ void* /*context*/,
    _In_ uint32_t /*userIdentifier*/,
    _In_ XUserPlatformOperation operation,
    _In_z_ char const* key
)
{
    std::string name = MakeName(key);

    if (!DeleteFileA(name.c_str()))
    {
        DWORD error = GetLastError();

        if (error == ERROR_FILE_NOT_FOUND)
        {
            XUserPlatformStorageClearComplete(operation, XUserPlatformOperationResult::Success);
            return;
        }
        else
        {
            //std::cout << "    Failed to delete file with error " << GetLastError() << std::endl;
            XUserPlatformStorageClearComplete(operation, XUserPlatformOperationResult::Failure);
            return;
        }
    }

    XUserPlatformStorageClearComplete(operation, XUserPlatformOperationResult::Success);
}

