/* IntelliSense-only <stddef.h> for the 32-bit Xbox ABI (ILP32, 16-bit wchar_t).
   No #pragma once: picolibc re-includes it with different __need_* selectors.
   Nothing else in the SDK declares these types, so per-type guards suffice. */
#ifndef _RXDK_IS_SIZE_T
#define _RXDK_IS_SIZE_T
typedef unsigned int size_t;
#endif
#ifndef _RXDK_IS_WCHAR_T
#define _RXDK_IS_WCHAR_T
#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif
#endif
#ifndef _RXDK_IS_WINT_T
#define _RXDK_IS_WINT_T
typedef unsigned int wint_t;
#endif
#ifndef _RXDK_IS_PTRDIFF_T
#define _RXDK_IS_PTRDIFF_T
typedef int ptrdiff_t;
#endif
#ifndef NULL
#define NULL 0
#endif
#ifndef offsetof
#define offsetof(s, m) ((size_t) & (((s *)0)->m))
#endif
