#pragma once
/* Route MSVC <trnsctrl.h> to Xbox CRT EH + current-exception bridge (skip vcruntime_internal.h). */
#ifndef _XDK_TRNSCTRL_SHIM_
#define _XDK_TRNSCTRL_SHIM_

#include "../../private/sdktools/crt/crtw32/h/trnsctrl.h"

struct _CONTEXT;
struct EHExceptionRecord;

#ifdef __cplusplus
extern "C" {
#endif

struct _tiddata;
typedef struct _tiddata* _ptiddata;
_ptiddata __cdecl _getptd(void);

void** __cdecl __current_exception(void);
void** __cdecl __current_exception_context(void);
int* __cdecl __processing_throw(void);

#ifdef __cplusplus
}
#endif

#define _pCurrentException (*reinterpret_cast<EHExceptionRecord**>(__current_exception()))
#define _pCurrentExContext (*reinterpret_cast<struct _CONTEXT**>(__current_exception_context()))
#define __ProcessingThrow (*__processing_throw())

#include "winrt_eh.h"

#endif /* _XDK_TRNSCTRL_SHIM_ */
