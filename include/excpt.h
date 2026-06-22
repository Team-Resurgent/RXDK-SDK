#pragma once
/* Minimal SEH types for MSVC <ehdata.h> (no UCRT vcruntime chain). */
#ifndef _INC_EXCPT
#define _INC_EXCPT

typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;

#endif
