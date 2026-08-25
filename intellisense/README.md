# IntelliSense shim headers

These headers exist **only for IDE IntelliSense** (Visual Studio's native C++ IntelliSense and
VS Code's C/C++ extension, both running the **MSVC front-end**). They are **never** used by the real
build — the RXDK toolchain compiles with clang/zig, which provides all of this natively.

## Why they're needed

The RXDK SDK headers (`include/`) are written for clang and pull in clang/GCC constructs the MSVC
IntelliSense front-end doesn't provide:

- clang builtin type macros (`__SIZE_TYPE__`, `__WINT_TYPE__`, …) that picolibc's headers use,
- freestanding/compiler headers the clang toolchain supplies from its own resource dir
  (`stddef.h`, `stdarg.h`, `float.h`, `stdbool.h`, `stdalign.h`),
- the Windows structure-packing headers (`pshpack1/2/4/8/16.h`, `poppack.h`) and a couple of
  Windows-compat stubs (`cguid.h`, `ioccom.h`) that the build gets from the Zig mingw headers.

Without them the MSVC front-end hits a fatal "cannot open include file" and aborts parsing the whole
translation unit, so every symbol — even a macro defined in the same file — reads as
**"symbol not found"** on hover (while Go To Declaration still works via the tag database).

## How they're wired

The IDEs add this directory to the IntelliSense include path (after `include/`) and force-include
[`rxdk_intellisense.h`](rxdk_intellisense.h) — the prelude that defines the clang builtin type macros
(for the 32-bit Xbox ABI: ILP32, 16-bit `wchar_t`) and neutralises GCC attribute syntax — ahead of the
SDK headers. `rxdk_intellisense.h` is guarded on `!__GNUC__`, so it is inert under the real clang build.

- Visual Studio: `Rxdk.Xbox.IntelliSense.props` (`NMakeIncludeSearchPath` + `NMakeForcedIncludes`).
- VS Code: generated `c_cpp_properties.json` / settings (`includePath` + `forcedInclude`).
