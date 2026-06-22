#pragma once

#ifdef __cplusplus
extern "C" {
#endif

unsigned long __cdecl _EH_ReadFs0(void);
unsigned long __cdecl _EH_ReadEsp(void);
void __cdecl _EH_WriteFs0(unsigned long value);
void __cdecl _EH_UnlinkFsMarker(void);
void __cdecl _EH_RelinkFsMarker(unsigned long savedMarker, unsigned long currentHead);
void __cdecl _EH_PushFsNode(void* node);
void __cdecl _EH_FixTranslationMarker(void* savedMarker);

#ifdef __cplusplus
}
#endif
