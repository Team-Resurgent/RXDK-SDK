#pragma once
/* IntelliSense-only stdarg.h: the MSVC front-end understands these builtins. */
typedef char *va_list;
#define va_start(ap, v) ((void)(ap = (va_list)&(v) + sizeof(v)))
#define va_arg(ap, t)   (*(t *)((ap += sizeof(t)) - sizeof(t)))
#define va_end(ap)      ((void)(ap = (va_list)0))
#define va_copy(d, s)   ((void)((d) = (s)))
