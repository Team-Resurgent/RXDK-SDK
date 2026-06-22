#pragma once
#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _XDK_MODERN_CTYPE
#define _XDK_MODERN_CTYPE
inline int isblank(int c) { return c == ' ' || c == '\t'; }
#endif

#ifdef __cplusplus
}
#endif
