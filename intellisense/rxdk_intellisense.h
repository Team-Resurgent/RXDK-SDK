#pragma once
/*
  RXDK IntelliSense prelude (force-included for IntelliSense only; the real clang/zig
  build never sees this file). The RXDK SDK headers are written for clang and use
  clang/GCC builtin type macros (__SIZE_TYPE__ etc.) and GCC attribute syntax that the
  MSVC IntelliSense front-end doesn't provide — which makes it fail to parse the headers
  and report "symbol not found". Define those builtins (for the 32-bit Xbox ABI: ILP32,
  16-bit wchar_t) and neutralise GCC-only syntax so the MSVC front-end can parse them.

  Guarded on !__GNUC__ so it is inert under the real clang build (which defines __GNUC__)
  even if ever force-included there; MSVC IntelliSense does not define __GNUC__.
*/
#ifndef __GNUC__

/* clang/GCC fixed-width base type builtins the SDK's picolibc headers rely on. */
#define __INT8_TYPE__          signed char
#define __UINT8_TYPE__         unsigned char
#define __INT16_TYPE__         short
#define __UINT16_TYPE__        unsigned short
#define __INT32_TYPE__         int
#define __UINT32_TYPE__        unsigned int
#define __INT64_TYPE__         long long
#define __UINT64_TYPE__        unsigned long long
#define __INTMAX_TYPE__        long long
#define __UINTMAX_TYPE__       unsigned long long
#define __INTPTR_TYPE__        int
#define __UINTPTR_TYPE__       unsigned int
#define __PTRDIFF_TYPE__       int
#define __SIZE_TYPE__          unsigned int
#define __WCHAR_TYPE__         unsigned short
#define __WINT_TYPE__          unsigned int
#define __INT_LEAST8_TYPE__    signed char
#define __UINT_LEAST8_TYPE__   unsigned char
#define __INT_LEAST16_TYPE__   short
#define __UINT_LEAST16_TYPE__  unsigned short
#define __INT_LEAST32_TYPE__   int
#define __UINT_LEAST32_TYPE__  unsigned int
#define __INT_LEAST64_TYPE__   long long
#define __UINT_LEAST64_TYPE__  unsigned long long
#define __INT_FAST8_TYPE__     signed char
#define __UINT_FAST8_TYPE__    unsigned char
#define __INT_FAST16_TYPE__    int
#define __UINT_FAST16_TYPE__   unsigned int
#define __INT_FAST32_TYPE__    int
#define __UINT_FAST32_TYPE__   unsigned int
#define __INT_FAST64_TYPE__    long long
#define __UINT_FAST64_TYPE__   unsigned long long

/* GCC-ism syntax the MSVC IntelliSense front-end doesn't accept. */
#define __attribute__(x)
#define __extension__
#define __restrict__
#define __inline__ __inline

#endif /* !__GNUC__ */
