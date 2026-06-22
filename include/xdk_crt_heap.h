/* heap module shim: use CRT new/delete declarations before vcruntime headers */
#if defined(_CRTBLD) && defined(_XBOX)
#include <cruntime.h>
#ifndef _INC_NEW
#include <new.h>
#endif
#define _VCRUNTIME_NEW_H_
#define _VCRUNTIME_H_
#endif
