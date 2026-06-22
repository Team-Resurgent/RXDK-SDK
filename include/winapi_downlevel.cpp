//
// winapi_downlevel.cpp
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// Definitions of wrappers for Windows API functions that previously could not be called
// directly, but are now available on all supported operating systems.
//
#include <vcruntime_internal.h>

#if _VCRT_WIN32_WINNT < _WIN32_WINNT_VISTA
    // TRANSITION, ABI: __vcrt_FlsAlloc() is preserved for binary compatibility, parentheses avoid macroization
    extern "C" DWORD (__cdecl __vcrt_FlsAlloc)(_In_opt_ PFLS_CALLBACK_FUNCTION const callback)
    {
        return FlsAlloc(callback);
    }

    // TRANSITION, ABI: __vcrt_FlsFree() is preserved for binary compatibility, parentheses avoid macroization
    extern "C" BOOL (__cdecl __vcrt_FlsFree)(_In_ DWORD const fls_index)
    {
        return FlsFree(fls_index);
    }

    // TRANSITION, ABI: __vcrt_FlsGetValue() is preserved for binary compatibility, parentheses avoid macroization
    extern "C" PVOID (__cdecl __vcrt_FlsGetValue)(_In_ DWORD const fls_index)
    {
        return FlsGetValue(fls_index);
    }

    // TRANSITION, ABI: __vcrt_FlsSetValue() is preserved for binary compatibility, parentheses avoid macroization
    extern "C" BOOL (__cdecl __vcrt_FlsSetValue)(_In_ DWORD const fls_index, _In_opt_ PVOID const fls_data)
    {
        return FlsSetValue(fls_index, fls_data);
    }
#endif // _VCRT_WIN32_WINNT < _WIN32_WINNT_VISTA

// TRANSITION, ABI: __vcrt_InitializeCriticalSectionEx() is preserved for binary compatibility
extern "C" BOOL __cdecl __vcrt_InitializeCriticalSectionEx(
    _Out_ LPCRITICAL_SECTION const critical_section,
    _In_  DWORD              const spin_count,
    _In_  DWORD              const flags
    )
{
    return InitializeCriticalSectionEx(critical_section, spin_count, flags);
}
