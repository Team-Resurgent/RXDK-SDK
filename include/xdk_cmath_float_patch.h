#pragma once
/* Floating signbit/isnan for MSVC <format> when _CSTD lacks them (Xbox CRT + integral <cmath> overloads). */
#ifndef _XDK_CMATH_FLOAT_PATCH_H
#define _XDK_CMATH_FLOAT_PATCH_H

#ifdef __cplusplus

#include <math.h>

namespace std {
inline bool signbit(float x) noexcept {
    return x < 0.0f;
}
inline bool signbit(double x) noexcept {
    return x < 0.0;
}
inline bool signbit(long double x) noexcept {
    return x < 0.0L;
}
inline bool isnan(float x) noexcept {
    return ::_isnan(static_cast<double>(x)) != 0;
}
inline bool isnan(double x) noexcept {
    return ::_isnan(x) != 0;
}
inline bool isnan(long double x) noexcept {
    return ::_isnan(static_cast<double>(x)) != 0;
}
} // namespace std

#endif /* __cplusplus */

#endif /* _XDK_CMATH_FLOAT_PATCH_H */
