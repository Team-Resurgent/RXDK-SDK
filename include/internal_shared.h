#pragma once
/* Shadow MSVC vcruntime/internal_shared.h for Xbox libcp (no UCRT/vcruntime.h). */
#ifndef _VCRUNTIME_INTERNAL_SHARED_H
#define _VCRUNTIME_INTERNAL_SHARED_H

#include "internal_shared_patch.h"
#include <crtdbg.h>
#include <intrin.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "Windows.h"

#ifndef _CRT_BEGIN_C_HEADER
#define _CRT_BEGIN_C_HEADER
#define _CRT_END_C_HEADER
#endif

_CRT_BEGIN_C_HEADER

typedef struct _IMAGE_DOS_HEADER {
    unsigned short e_magic;
} IMAGE_DOS_HEADER;

_CRT_END_C_HEADER

#ifndef _calloc_crt
#define _calloc_crt(c, s) calloc((c), (s))
#endif
#ifndef _free_crt
#define _free_crt(p) free(p)
#endif
#ifndef _malloc_crt
#define _malloc_crt(s) malloc(s)
#endif
#ifndef _realloc_crt
#define _realloc_crt(p, s) realloc((p), (s))
#endif
#ifndef _recalloc_crt
#define _recalloc_crt(p, c, s) calloc((c), (s))
#endif

#define _malloca_crt(size) malloc(size)

#ifdef __cplusplus
extern "C++" {
struct __crt_internal_free_policy {
    template <typename T>
    void operator()(T const* const p) const noexcept {
        free(const_cast<T*>(p));
    }
};

template <typename T, typename Free = __crt_internal_free_policy>
class __crt_unique_heap_ptr {
public:
    explicit __crt_unique_heap_ptr(T* const p = nullptr) noexcept : _p(p) {}
    __crt_unique_heap_ptr(const __crt_unique_heap_ptr&) = delete;
    __crt_unique_heap_ptr& operator=(const __crt_unique_heap_ptr&) = delete;
    __crt_unique_heap_ptr(__crt_unique_heap_ptr&& other) noexcept : _p(other._p) {
        other._p = nullptr;
    }
    ~__crt_unique_heap_ptr() noexcept { release(); }
    __crt_unique_heap_ptr& operator=(__crt_unique_heap_ptr&& other) noexcept {
        release();
        _p = other._p;
        other._p = nullptr;
        return *this;
    }
    T* get() const noexcept { return _p; }
    explicit operator bool() const noexcept { return _p != nullptr; }
    void release() noexcept {
        Free()(_p);
        _p = nullptr;
    }

private:
    T* _p;
};

#define _malloc_crt_t(t, n) (__crt_unique_heap_ptr<t>(static_cast<t*>(_malloc_crt((n) * sizeof(t)))))

template <typename T, typename V>
T* __crt_interlocked_exchange_pointer(T* const volatile* target, V const value) noexcept {
    return reinterpret_cast<T*>(_InterlockedExchangePointer((void**)target, (void*)value));
}

template <typename T>
T* __crt_interlocked_read_pointer(T* const volatile* target) noexcept {
    T* const result = *target;
    _ReadWriteBarrier();
    return const_cast<T*>(result);
}

} /* extern "C++" */
#endif /* __cplusplus */

#endif /* _VCRUNTIME_INTERNAL_SHARED_H */
