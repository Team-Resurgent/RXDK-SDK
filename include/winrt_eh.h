#pragma once
/* WinRT EH types referenced by excptptr.cpp (never executed on Xbox). */
#ifndef _XDK_WINRT_EH_H_
#define _XDK_WINRT_EH_H_

typedef struct WinRTExceptionInfo {
    void* description;
    void* restrictedErrorString;
    void* restrictedErrorReference;
    void* capabilitySid;
    long hr;
    void* restrictedInfo;
    ThrowInfo* throwInfo;
    unsigned int size;
    void (__stdcall* PrepareThrow)(void* ExceptionInfo);
} WINRTEXCEPTIONINFO;

#endif
