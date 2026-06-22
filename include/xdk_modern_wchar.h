#pragma once
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _XDK_MODERN_WCHAR_DECLARED
#define _XDK_MODERN_WCHAR_DECLARED

unsigned long long wcstoull(const wchar_t* nptr, wchar_t** endptr, int base);
long long wcstoll(const wchar_t* nptr, wchar_t** endptr, int base);
int vfwscanf(FILE* stream, const wchar_t* format, va_list argptr);
int vswscanf(const wchar_t* buffer, const wchar_t* format, va_list argptr);
int vwscanf(const wchar_t* format, va_list argptr);
float wcstof(const wchar_t* nptr, wchar_t** endptr);
long double wcstold(const wchar_t* nptr, wchar_t** endptr);

#endif

#ifdef __cplusplus
}
#endif
