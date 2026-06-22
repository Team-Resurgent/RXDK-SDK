#pragma once
/* Route STL debug heap calls to Xbox CRT malloc/free; block legacy crtdbg.h macro expansion. */
#include <stdlib.h>
#include <malloc.h>
#ifndef _CRT_BLOCK
#define _CRT_BLOCK 0
#endif
#ifndef _CRT_WARN
#define _CRT_WARN 0
#endif
#ifndef _CRT_ERROR
#define _CRT_ERROR 1
#endif
#ifndef _CRT_ASSERT
#define _CRT_ASSERT 2
#endif
#ifndef _NORMAL_BLOCK
#define _NORMAL_BLOCK 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

static inline void* _malloc_dbg(size_t size, int block, const char* file, int line) {
    (void)block;
    (void)file;
    (void)line;
    return malloc(size > 0 ? size : 1);
}

static inline void* _calloc_dbg(size_t count, size_t size, int block, const char* file, int line) {
    (void)block;
    (void)file;
    (void)line;
    return calloc(count, size);
}

static inline void* _realloc_dbg(void* ptr, size_t size, int block, const char* file, int line) {
    (void)block;
    (void)file;
    (void)line;
    return realloc(ptr, size);
}

static inline void _free_dbg(void* ptr, int block) {
    (void)block;
    free(ptr);
}

static inline size_t _msize_dbg(void* ptr, int block) {
    (void)block;
    return _msize(ptr);
}

#ifdef __cplusplus
}
#endif

#ifndef _CrtDbgReportW
#define _CrtDbgReportW(...) 0
#endif
#ifndef _CrtDbgBreak
#define _CrtDbgBreak() ((void)0)
#endif
#ifndef _CrtDbgReport
#define _CrtDbgReport(...) 0
#endif
#ifndef _ASSERT_BASE
#define _ASSERT_BASE(expr, msg) ((void)0)
#endif
#ifndef _ASSERT
#define _ASSERT(expr) _ASSERT_BASE((expr), NULL)
#endif
#ifndef _ASSERTE
#define _ASSERTE(expr) _ASSERT_BASE((expr), #expr)
#endif

#ifndef _RPT_BASE
#define _RPT_BASE(args) ((void)0)
#endif
#ifndef _RPT0
#define _RPT0(rptno, msg) _RPT_BASE((rptno, NULL, 0, NULL, "%s", msg))
#endif
#ifndef _RPTF0
#define _RPTF0(rptno, msg) _RPT_BASE((rptno, __FILE__, __LINE__, NULL, "%s", msg))
#endif
#ifndef _RPT1
#define _RPT1(rptno, msg, arg1) _RPT_BASE((rptno, NULL, 0, NULL, msg, arg1))
#endif
#ifndef _RPTF1
#define _RPTF1(rptno, msg, arg1) _RPT_BASE((rptno, __FILE__, __LINE__, NULL, msg, arg1))
#endif

#undef _CRTDBG_MAP_ALLOC

#ifndef _INC_CRTDBG
#define _INC_CRTDBG
#endif
