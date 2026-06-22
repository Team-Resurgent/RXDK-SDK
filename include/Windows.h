#pragma once
/* MSVC STL only (libcp): block desktop Windows.h. */
#include <intrin.h>
#include "winerror.h"
#include "xdk_modern_sync.h"
#include "xdk_modern_awint.h"
#include "xdk_modern_winthread.h"

#ifndef InterlockedIncrement
#define InterlockedIncrement _InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#endif

typedef int BOOL;
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef unsigned long ULONG;
typedef unsigned char BYTE;
typedef BYTE* PBYTE;
typedef unsigned short WORD;
#ifndef WINAPI
#define WINAPI __stdcall
#endif
#ifndef CALLBACK
#define CALLBACK __stdcall
#endif
#ifndef PVOID
#define PVOID void*
#endif
typedef char CHAR;
typedef wchar_t WCHAR;
typedef CHAR* LPSTR;
typedef const CHAR* LPCSTR;
typedef WCHAR* LPWSTR;
typedef const WCHAR* LPCWSTR;
typedef void* LPVOID;
typedef void* HLOCAL;
typedef WORD* LPWORD;

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif
typedef void* HMODULE;
typedef void* HANDLE;
#ifndef INVALID_HANDLE_VALUE
#define INVALID_HANDLE_VALUE ((HANDLE)(intptr_t)-1)
#endif

#ifndef MAX_LEADBYTES
#define MAX_LEADBYTES 12
#endif

typedef struct tagCREATEFILE2_EXTENDED_PARAMETERS {
    unsigned long dwSize;
    unsigned long dwFileAttributes;
    unsigned long dwFileFlags;
    unsigned long dwSecurityQosFlags;
    void* lpSecurityAttributes;
    void* hTemplateFile;
} CREATEFILE2_EXTENDED_PARAMETERS;

typedef struct _FILETIME {
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
} FILETIME;

typedef union _LARGE_INTEGER {
    struct {
        unsigned long LowPart;
        long HighPart;
    } u;
    long long QuadPart;
} LARGE_INTEGER;

#ifndef TIME_UTC
#define TIME_UTC 1
#endif

#ifndef SORT_STRINGSORT
#define SORT_STRINGSORT 0x00001000
#endif
#ifndef CT_CTYPE1
#define CT_CTYPE1 0x00000400
#endif
#ifndef LOCALE_ILDATE
#define LOCALE_ILDATE 0x0000100A
#endif
#ifndef EXCEPTION_NONCONTINUABLE
#define EXCEPTION_NONCONTINUABLE 0x00000001
#endif

typedef struct _EXCEPTION_RECORD {
    unsigned long ExceptionCode;
    unsigned long ExceptionFlags;
    struct _EXCEPTION_RECORD* ExceptionRecord;
    void* ExceptionAddress;
    unsigned long NumberParameters;
    unsigned long ExceptionInformation[15];
} EXCEPTION_RECORD, *_PEXCEPTION_RECORD;
#ifndef EXCEPTION_MAXIMUM_PARAMETERS
#define EXCEPTION_MAXIMUM_PARAMETERS 15
#endif

#ifdef __cplusplus
extern "C" {
#endif

void __stdcall GetSystemTimePreciseAsFileTime(FILETIME* ft);
int __stdcall QueryPerformanceCounter(LARGE_INTEGER* li);
int __stdcall QueryPerformanceFrequency(LARGE_INTEGER* li);
int __stdcall GetStringTypeW(unsigned long info, const wchar_t* src, int count, LPWORD chartype);
int __stdcall GetLocaleInfoEx(const wchar_t* locale, unsigned long type, wchar_t* data, int count);
int __stdcall GetCPInfoExW(unsigned int code_page, unsigned long flags, CPINFOEXW* info);

HANDLE __stdcall CreateFile2(
    const wchar_t* name, unsigned long access, unsigned long share, unsigned long disposition,
    CREATEFILE2_EXTENDED_PARAMETERS* params);
unsigned long __stdcall GetCurrentThreadId(void);
void __stdcall Sleep(unsigned long ms);
unsigned long __stdcall WaitForSingleObject(HANDLE h, unsigned long ms);
unsigned long __stdcall WaitForSingleObjectEx(HANDLE h, unsigned long ms, int alertable);
int __stdcall CloseHandle(HANDLE h);
int __stdcall GetExitCodeThread(HANDLE h, unsigned long* code);
void __stdcall SwitchToThread(void);
void __stdcall RaiseException(
    unsigned long code, unsigned long flags, unsigned long n, const unsigned long* args);

unsigned long __stdcall GetLogicalProcessorInformationEx(
    int relationship, void* buffer, unsigned long* length);
#ifndef RelationProcessorPackage
#define RelationProcessorPackage 0
#endif
#ifndef ERROR_INSUFFICIENT_BUFFER
#define ERROR_INSUFFICIENT_BUFFER 122u
#endif

typedef struct _PROCESSOR_GROUP_INFO {
    unsigned short MaximumProcessorCount;
    unsigned short ActiveProcessorCount;
    unsigned long long Mask;
} PROCESSOR_GROUP_INFO;

typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX {
    unsigned long Relationship;
    unsigned long Size;
    union {
        struct {
            unsigned char Flags;
            unsigned char EfficiencyClass;
            unsigned char Reserved[20];
            unsigned short GroupCount;
            PROCESSOR_GROUP_INFO GroupMask[1];
        } Processor;
    };
} SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX;

unsigned long __cdecl FormatMessageA(
    unsigned long flags, void* source, unsigned long message_id, unsigned long language_id,
    char* buffer, unsigned long size, void* arguments);
void* __cdecl LocalFree(void* mem);

__inline void* GetProcAddress(HMODULE module, const char* name) {
    (void)module;
    (void)name;
    return 0;
}
__inline void* EncodePointer(void* ptr) {
    return ptr;
}
__inline void* DecodePointer(void* ptr) {
    return ptr;
}

#ifndef GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT
#define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT 0x00000002u
#endif
#ifndef GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS 0x00000004u
#endif

typedef void* PTP_CALLBACK_INSTANCE;
typedef void* PTP_WORK;
typedef void* PTP_CALLBACK_ENVIRON;
typedef void(__stdcall* PTP_WORK_CALLBACK)(PTP_CALLBACK_INSTANCE instance, void* context, void* work);

struct _IMAGE_DOS_HEADER;
typedef struct _IMAGE_DOS_HEADER IMAGE_DOS_HEADER;
extern IMAGE_DOS_HEADER __ImageBase;

int __stdcall GetModuleHandleExW(unsigned long flags, const wchar_t* module_name, HMODULE* module);
void __stdcall FreeLibraryWhenCallbackReturns(PTP_CALLBACK_INSTANCE instance, HMODULE module);

#ifdef __cplusplus
void* __stdcall __std_create_threadpool_work(
    void(__stdcall* callback)(void*, void*, void*), void* context, void* environ) noexcept;
void __stdcall __std_submit_threadpool_work(void* work) noexcept;
void __stdcall __std_close_threadpool_work(void* work) noexcept;
#else
void* __stdcall __std_create_threadpool_work(
    void(__stdcall* callback)(void*, void*, void*), void* context, void* environ);
void __stdcall __std_submit_threadpool_work(void* work);
void __stdcall __std_close_threadpool_work(void* work);
#endif

PTP_WORK __stdcall CreateThreadpoolWork(
    PTP_WORK_CALLBACK callback, void* context, PTP_CALLBACK_ENVIRON environ);
void __stdcall SubmitThreadpoolWork(PTP_WORK work);
void __stdcall CloseThreadpoolWork(PTP_WORK work);

unsigned short __stdcall RtlCaptureStackBackTrace(
    unsigned long frames_to_skip, unsigned long frames_to_capture, void** back_trace, unsigned long* hash);

#ifndef FAST_FAIL_INVALID_ARG
#define FAST_FAIL_INVALID_ARG 5
#endif
#ifndef __fastfail
#define __fastfail(code) abort()
#endif

#ifdef __cplusplus
}
#endif
