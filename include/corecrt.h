/* Minimal corecrt.h for MSVC STL on Xbox CRT (blocks Windows UCRT). */
#pragma once
#ifndef _CORECRT_H
#define _CORECRT_H

typedef int mbstate_t;

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
typedef long time_t;
#endif

#endif /* _CORECRT_H */
