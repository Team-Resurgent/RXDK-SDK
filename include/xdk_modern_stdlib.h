#pragma once
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _XDK_MODERN_STDLIB_DECLARED
#define _XDK_MODERN_STDLIB_DECLARED

float strtof(const char* nptr, char** endptr);
long double strtold(const char* nptr, char** endptr);
long long strtoll(const char* nptr, char** endptr, int base);
unsigned long long strtoull(const char* nptr, char** endptr, int base);
void _Exit(int status);
int at_quick_exit(void (__cdecl*)(void));
void quick_exit(int status);

typedef struct { long long quot; long long rem; } lldiv_t;
lldiv_t lldiv(long long numer, long long denom);
long long atoll(const char* nptr);
long long llabs(long long x);
char* __cdecl getenv(const char* name);
int rand_s(unsigned int* random_value);

#endif

#ifdef __cplusplus
}
#endif
