#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#ifndef _Mbstatet
typedef mbstate_t _Mbstatet;
#endif
#ifdef __cplusplus
extern "C" {
#endif

int snprintf(char* buffer, size_t count, const char* format, ...);
int vsnprintf(char* buffer, size_t count, const char* format, va_list argptr);
int vfscanf(FILE* stream, const char* format, va_list argptr);
int vscanf(const char* format, va_list argptr);
int vsscanf(const char* buffer, const char* format, va_list argptr);
int _fseeki64(FILE* stream, long long offset, int origin);
/* Implemented by libcmt (_file.obj); declared here for libcpmt / STL compile. */
void __cdecl _lock_file(FILE* stream);
void __cdecl _unlock_file(FILE* stream);
void __cdecl _get_stream_buffer_pointers(FILE* stream, char*** in, char*** out, int** in_size);
int sprintf_s(char* buffer, size_t sizeOfBuffer, const char* format, ...);
int swprintf_s(wchar_t* buffer, size_t sizeOfBuffer, const wchar_t* format, ...);

#ifdef __cplusplus
}
#endif
