# RXDK-SDK

Consumer SDK for original Xbox homebrew development — static libraries and public
headers for building Xbox titles (`.xbe`) with the LLVM/clang toolchain.

Current release: see [`VERSION`](VERSION).

Produced by the **RXDK-Libs** build — a from-source, MSVC-free port of the Xbox
runtime (kernel import library, C/C++ runtimes, xAPI, D3D8/D3DX8, DirectSound, XNet,
XMV). The `.lib` files are standard COFF archives; the headers are a clean
picolibc + libc++ + Xbox-API tree.

## Layout

```
libs/       # static import / runtime libraries (.lib)
include/    # public headers: C, C++ (c++/v1), and the Xbox APIs
VERSION     # SDK tag
```

## Libraries (`libs/`)

| Library | Role |
|---------|------|
| `libkernel.lib`    | Xbox kernel (xboxkrnl) import library — **every title links this last** |
| `libc.lib`         | C runtime (picolibc, C17/C23) + Xbox HAL |
| `libcpp.lib`       | C++ runtime (libc++ / libc++abi / DWARF unwinder) |
| `libxapi.lib`      | Xbox application API: XInput, memory units, fibers, files, TLS, … |
| `libd3d8.lib`      | Direct3D 8 — NV2A GPU driver |
| `libd3dx8.lib`     | D3DX8 helpers: math, textures, mesh, `.X` files |
| `libxgraphics.lib` | xgraphics: swizzle, S3TC, shader assembler |
| `libdsound.lib`    | DirectSound — MCPX APU driver |
| `libxnet.lib`      | XNet TCP/IP stack |
| `libxmv.lib`       | XMV (FMV) video decoder |

Release builds only — there are no separate `*d` debug variants.

## Headers (`include/`)

- **C** — standard library (picolibc-derived): `stdio.h`, `stdlib.h`, `string.h`,
  `math.h`, … plus the `bits/`, `machine/`, and `sys/` support trees.
- **C++** — `c++/v1/` (libc++), a standard libc++ install layout, so a libc++
  toolchain finds it automatically.
- **Xbox** — `xboxkrnl/` (kernel API), `xbox/`, `xt.h`, `xapi.h`, `d3d8*.h`,
  `d3dx8*.h`, `dsound*.h`, `xgraphics.h`, `xmv.h`, `conio.h`, `xkbd.h`, …

## Using the SDK

Titles are compiled with **clang/LLVM** targeting x86 (Pentium III — MMX/SSE1, no
SSE2) and linked into an `.xbe`; this is **not** an MSVC SDK, so don't mix in CRT/libs
from Visual Studio.

- Include path: `-I include/`
- Library path: `libs/`

**Link order** — specific device libs first, then xAPI, then the kernel import lib
last (it resolves the `__imp__*` kernel imports):

```
libd3dx8  libxgraphics  libd3d8  libdsound  libxmv   →   libxapi   →   libkernel
```

(plus `libc` / `libcpp`). A title only needs the device libs it actually uses; e.g. a
plain xAPI app links just `libxapi` + `libkernel`, a D3D title adds `libd3d8`
(`+ libd3dx8`/`libxgraphics` for the helpers).

For the exact compile/link recipe — target triple, `-nostdinc`, `-fms-extensions`,
the force-included `picolibc.h`, the XBE bootstrap entry point — see the sample
projects in the RXDK-Libs build that produces this SDK.
