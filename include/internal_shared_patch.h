#pragma once
#ifndef _XDK_INTERNAL_SHARED_PATCH_H
#define _XDK_INTERNAL_SHARED_PATCH_H
/* Prepended before MSVC internal_shared.h for libcp (no PE module / alloca markers). */
#ifndef _ALLOCA_S_MARKER_SIZE
#define _ALLOCA_S_MARKER_SIZE 8
#endif
#ifndef _ALLOCA_S_HEAP_MARKER
#define _ALLOCA_S_HEAP_MARKER 0x5678
#endif
#ifndef _ALLOCA_S_STACK_MARKER
#define _ALLOCA_S_STACK_MARKER 0xCCCC
#endif
#ifndef _CRT_UNUSED
#define _CRT_UNUSED(x) (void)(x)
#endif
inline unsigned long RotateRight32(unsigned long Value, int Shift) {
    return (Value >> Shift) | (Value << (32 - Shift));
}
inline unsigned long long RotateRight64(unsigned long long Value, int Shift) {
    return (Value >> Shift) | (Value << (64 - Shift));
}

#endif /* _XDK_INTERNAL_SHARED_PATCH_H */
