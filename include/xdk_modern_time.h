#pragma once
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TIME_UTC
#define TIME_UTC 1
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
struct timespec {
    long tv_sec;
    long tv_nsec;
};
#endif

int timespec_get(struct timespec* ts, int base);

#ifdef __cplusplus
}
#endif
