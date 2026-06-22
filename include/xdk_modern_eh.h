#pragma once
/* terminate / set_terminate from Xbox CRT eh_mt (libcmt). */
#ifdef __cplusplus

#ifndef _CRTBLD
#define _CRTBLD 1
#define _XDK_EH_UNSET_CRTBLD 1
#endif

#include <eh.h>

// Installed automatically via xdk_xbox_crt_startup() before main().
extern "C" void __cdecl xdk_install_crt_eh_handlers(void);

inline int __uncaught_exceptions(void) {
    return __uncaught_exception() ? 1 : 0;
}

#ifdef _XDK_EH_UNSET_CRTBLD
#undef _CRTBLD
#undef _XDK_EH_UNSET_CRTBLD
#endif

#endif /* __cplusplus */
