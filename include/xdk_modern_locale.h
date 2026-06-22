#pragma once
#ifdef __cplusplus
extern "C" {
#endif
void __cdecl _lock_locales(void);
void __cdecl _unlock_locales(void);
void __cdecl _Atexit(void(__cdecl*)(void));
#ifdef __cplusplus
}
#endif
