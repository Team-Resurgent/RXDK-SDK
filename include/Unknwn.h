#pragma once
/* COM stub for MSVC excptptr.cpp (no desktop ole32). */
#ifndef _UNKWN_H_
#define _UNKWN_H_

typedef long HRESULT;

struct IUnknown {
    virtual HRESULT __stdcall QueryInterface(void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef(void) = 0;
    virtual unsigned long __stdcall Release(void) = 0;
};

#endif
