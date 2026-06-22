#pragma once
#include "xdk_modern_math.h"

/* Xbox CRT math.h defines many *l functions as macros; undef before real symbols. */
#ifdef acosl
#undef acosl
#undef asinl
#undef atanl
#undef atan2l
#undef ceill
#undef cosl
#undef coshl
#undef expl
#undef fabsl
#undef floorl
#undef fmodl
#undef frexpl
#undef ldexpl
#undef logl
#undef log10l
#undef modfl
#undef powl
#undef sinl
#undef sinhl
#undef sqrtl
#undef tanl
#undef tanhl
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* long double math required by MSVC STL <cmath> (no UCRT headers in Xbox build). */
long double acosl(long double);
long double asinl(long double);
long double atanl(long double);
long double atan2l(long double, long double);
long double ceill(long double);
long double cosl(long double);
long double coshl(long double);
long double expl(long double);
long double fabsl(long double);
long double floorl(long double);
long double fmodl(long double, long double);
long double frexpl(long double, int*);
long double ldexpl(long double, int);
long double logl(long double);
long double log10l(long double);
long double modfl(long double, long double*);
long double powl(long double, long double);
long double sinl(long double);
long double sinhl(long double);
long double sqrtl(long double);
long double tanl(long double);
long double tanhl(long double);
long double acoshl(long double);
long double asinhl(long double);
long double atanhl(long double);
long double cbrtl(long double);
long double erfl(long double);
long double erfcl(long double);
long double expm1l(long double);
long double exp2l(long double);
long double hypotl(long double, long double);
long double ilogbl(long double);
long double lgammal(long double);
long double log1pl(long double);
long double log2l(long double);
long double logbl(long double);
long long llrintl(long double);
long lrintl(long double);
long double nearbyintl(long double);
long double rintl(long double);
long long llroundl(long double);
long lroundl(long double);
long double fdiml(long double, long double);
long double fmal(long double, long double, long double);
long double fmaxl(long double, long double);
long double fminl(long double, long double);
long double roundl(long double);
long double truncl(long double);
long double remainderl(long double, long double);
long double remquol(long double, long double, int*);
long double copysignl(long double, long double);
long double nanl(const char*);
long double nextafterl(long double, long double);
long double scalbnl(long double, int);
long double scalblnl(long double, long int);
long double nexttowardl(long double, long double);
long double tgammal(long double);

#ifdef __cplusplus
}
#endif
