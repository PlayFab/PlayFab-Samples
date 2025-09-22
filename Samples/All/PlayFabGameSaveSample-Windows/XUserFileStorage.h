#pragma once

/// <summary>
/// Helper providing a simple file based implementation of the XUser storage event
/// handlers.
/// </summary>
class XUserFileStorage
{
public:
    /// <summary>
    /// Registers the storage callbacks with XUser.
    /// </summary>
    /// <param name="queue">The async queue to run the event handlers on.
    /// </param>
    /// <param name="pathPrefix">Optional path prefix, see remarks</param>
    /// <remarks>
    /// This function should be called once before XUserInit is called.
    ///
    /// The handlers will create one file per key in the following form:
    /// {pathPrefix}{key}.json
    /// </remarks>
    static HRESULT Init(XTaskQueueHandle queue, _In_opt_z_ char const* pathPrefix);

private:
    static void OnWrite(
        _In_opt_ void* context,
        _In_ uint32_t userIdentifier,
        _In_ XUserPlatformOperation operation,
        _In_z_ char const* key,
        _In_ size_t dataSize,
        _In_reads_bytes_(dataSize) void const* data
    );

    static void OnRead(
        _In_opt_ void* context,
        _In_ uint32_t userIdentifier,
        _In_ XUserPlatformOperation operation,
        _In_z_ char const* key
    );

    static void OnClear(
        _In_opt_ void* context,
        _In_ uint32_t userIdentifier,
        _In_ XUserPlatformOperation operation,
        _In_z_ char const* key
    );
};
