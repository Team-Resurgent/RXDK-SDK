/* C99 math declarations for MSVC STL <cmath> when using Xbox CRT headers. */
#pragma once
#include <float.h>
#include <math.h>
#ifndef _DSIGN
#define _DSIGN ((unsigned short)0x8000)
#endif
#ifndef _FSIGN
#define _FSIGN ((unsigned short)0x8000)
#endif
#ifndef _LSIGN
#define _LSIGN ((unsigned short)0x8000)
#endif
#ifndef DBL_TRUE_MIN
#define DBL_TRUE_MIN DBL_MIN
#endif
#ifndef FLT_TRUE_MIN
#define FLT_TRUE_MIN FLT_MIN
#endif
#ifndef LDBL_TRUE_MIN
#define LDBL_TRUE_MIN LDBL_MIN
#endif

#ifdef __cplusplus
/* Disambiguate MSVC <cmath> integer isfinite overloads for long double (Xbox CRT). */
inline bool isfinite(float x) noexcept { return _finite((double)x) != 0; }
inline bool isfinite(double x) noexcept { return _finite(x) != 0; }
inline bool isfinite(long double x) noexcept { return _finite((double)x) != 0; }
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _XDK_MODERN_MATH_DECLARED
#define _XDK_MODERN_MATH_DECLARED

typedef float float_t;
typedef double double_t;

#ifndef FP_NORMAL
#define FP_NORMAL 0
#define FP_ZERO 1
#define FP_SUBNORMAL 2
#define FP_INFINITE 3
#define FP_NAN 4
#endif

#ifdef __cplusplus
inline int isunordered(double x, double y) { (void)x; (void)y; return 0; }
inline int islessgreater(double x, double y) { return x > y || x < y; }
inline int isless(double x, double y) { return x < y; }
inline int islessequal(double x, double y) { return x <= y; }
inline int isgreater(double x, double y) { return x > y; }
inline int isgreaterequal(double x, double y) { return x >= y; }
#endif

double cbrt(double);
float cbrtf(float x);
float llroundf(float x);
long long llrint(double);
float llrintf(float x);
long lrint(double);
float lrintf(float x);
long long llround(double);
long lround(double);
float lroundf(float x);
double nearbyint(double);
float nearbyintf(float x);
double rint(double);
float rintf(float x);
double round(double);
float roundf(float x);
double trunc(double);
float truncf(float x);
double remainder(double, double);
float remainderf(float x, float y);
double remquo(double, double, int*);
float remquof(float x, float y, int* quo);
double fdim(double, double);
float fdimf(float x, float y);
double fmax(double, double);
float fmaxf(float x, float y);
double fmin(double, double);
float fminf(float x, float y);
float hypotf(float x, float y);
double log1p(double);
float log1pf(float x);
double expm1(double);
float expm1f(float x);
double exp2(double);
float exp2f(float x);
double log2(double);
float log2f(float x);
double logb(double);
float logbf(float x);
int ilogb(double);
double lgamma(double);
double tgamma(double);
double erf(double);
double erfc(double);
double acosh(double);
double asinh(double);
double atanh(double);
double copysign(double, double);
double nan(const char*);
double nextafter(double, double);
double scalbn(double, int);
double nexttoward(double, double);
float erff(float);
float erfcf(float);
float acoshf(float);
float asinhf(float);
float atanhf(float);
float frexpf(float, int*);
float ldexpf(float, int);
float modff(float, float*);
float powf(float, float);
float fmaf(float, float, float);
float nanf(const char*);
float copysignf(float, float);
float nextafterf(float, float);
float scalbnf(float, int);
float scalblnf(float, long int);
float nexttowardf(float, float);
float tgammaf(float);
float lgammaf(float);
float ilogbf(float);

#endif /* _XDK_MODERN_MATH_DECLARED */

#ifdef __cplusplus
}
#endif
