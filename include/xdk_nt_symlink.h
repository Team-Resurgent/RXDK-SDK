#pragma once
/* Kernel object-manager symlink APIs not declared in consumer winbase.h (Xbox mount tests). */

#ifndef _XDK_NT_SYMLINK_H_
#define _XDK_NT_SYMLINK_H_

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) (((long)(Status)) >= 0)
#endif

#ifndef STATUS_OBJECT_NAME_COLLISION
#define STATUS_OBJECT_NAME_COLLISION ((long)0xC0000035L)
#endif

typedef long NTSTATUS;

typedef struct _OBJECT_STRING {
    unsigned short Length;
    unsigned short MaximumLength;
    char* Buffer;
} OBJECT_STRING, *POBJECT_STRING;

#ifdef __cplusplus
extern "C" {
#endif

NTSTATUS __stdcall IoCreateSymbolicLink(POBJECT_STRING SymbolicLinkName, POBJECT_STRING DeviceName);

#ifdef __cplusplus
}
#endif

#endif /* _XDK_NT_SYMLINK_H_ */
