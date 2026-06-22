/* Force-include for modern MSVC STL (C++17) built against Xbox CRT. */
#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
/* Before xtl.h/winbase.h: skip Interlocked decls that clash with MSVC intrin.h. */
#ifndef _NTOS_
#define _NTOS_
#endif
#include "internal_shared_patch.h"
#include "xdk_modern_eh.h"
#include "xdk_modern_ctype.h"
#ifndef _LEADBYTE
#define _LEADBYTE 0x8000
#endif
#ifndef _cpp_isleadbyte
#define _cpp_isleadbyte(c) (__pctype_func()[(unsigned char)(c)] & _LEADBYTE)
#endif
#include "xdk_modern_stdio.h"
#include "xdk_modern_time.h"
#include "xdk_modern_wchar.h"
#include "xdk_modern_math.h"
#include "xdk_modern_math_ld.h"
#include "xdk_modern_stdlib.h"
#include "xdk_modern_crtdbg.h"
#ifndef _STL_ASSERT
#define _STL_ASSERT(cond, msg) ((void)((cond) || (_RPTF0(_CRT_ASSERT, msg), 0)))
#endif
#ifndef _STL_VERIFY
#define _STL_VERIFY(cond, msg) _STL_ASSERT(cond, msg)
#endif
#ifndef _STL_REPORT_ERROR
#define _STL_REPORT_ERROR(msg) _RPTF0(_CRT_ERROR, msg)
#endif
#include "xdk_modern_locale.h"
#ifndef _INC_WCHAR
#include <wchar.h>
#endif

#ifdef __cplusplus

#ifndef _CRTIMP2_PURE_IMPORT
#define _CRTIMP2_PURE_IMPORT
#endif
#ifndef _CRTIMP2_PURE
#define _CRTIMP2_PURE
#endif
#ifndef _MRTIMP2_PURE
#define _MRTIMP2_PURE
#endif
#ifndef _MRTIMP2
#define _MRTIMP2
#endif
#ifndef _ACRTIMP
#define _ACRTIMP
#endif
#ifndef _CRTIMP
#define _CRTIMP
#endif
#ifndef _CRTIMP2_PURE_IMPORT
#define _CRTIMP2_PURE_IMPORT
#endif
#ifndef _PGLOBAL
#define _PGLOBAL
#endif
#ifndef _CRTDATA2_IMPORT
#define _CRTDATA2_IMPORT
#endif
#ifndef _CRTDATA2
#define _CRTDATA2
#endif

#ifndef _NATIVE_WCHAR_T_DEFINED
#define _NATIVE_WCHAR_T_DEFINED
#endif
#define _CRTBLD_NATIVE_WCHAR_T

/* Xbox / static libcp: C++ exceptions (CRT eh_mt + /EHsc). Set XDK_LIBCP_EXCEPTIONS=0 to disable. */
#ifndef XDK_LIBCP_EXCEPTIONS
#define XDK_LIBCP_EXCEPTIONS 1
#endif
#undef _HAS_EXCEPTIONS
#if XDK_LIBCP_EXCEPTIONS
#define _HAS_EXCEPTIONS 1
#else
#define _HAS_EXCEPTIONS 0
#endif
#define _STATIC_CPPLIB 1
#define _CRTBLD 1
/* MSVC pre-injects ThrowInfo/PMD (normally via /FI ehdata_forceinclude.h). */
#if XDK_LIBCP_EXCEPTIONS
#include <ehdata_forceinclude.h>
#endif
#ifndef _HAS_CXX20
#define _HAS_CXX20 1
#endif
#ifndef _CRT_GUARDOVERFLOW
#define _CRT_GUARDOVERFLOW
#endif
#ifndef _CRT_SATURATE
#define _CRT_SATURATE
#endif
#ifndef _CRT_SATURATE_HIGH
#define _CRT_SATURATE_HIGH
#endif

struct _timespec64 {
    long long tv_sec;
    long tv_nsec;
};

/* Iterator debugging off for release-sized Xbox libs. */
#ifndef _ITERATOR_DEBUG_LEVEL
#define _ITERATOR_DEBUG_LEVEL 0
#endif

/* Block vcruntime headers that pull UCRT startup before Xbox shims apply. */
#define _VCRUNTIME_H_
#define _VCRUNTIME_NEW_H_
#define _VCRUNTIME_STRING_H_

struct threadlocaleinfostruct;
typedef struct threadlocaleinfostruct* pthreadlocinfo;
#define _TICORE

#include <cmath>
#include "xdk_cmath_float_patch.h"

#endif /* __cplusplus */
