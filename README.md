# RXDK-SDK

Consumer SDK for original Xbox development — static libraries and headers for building Xbox titles with Visual Studio 2022.

Current release: see [`VERSION`](VERSION).

## Layout

```
lib/        # ship static libraries (retail + *d debug names in one folder)
include/    # consumer headers (platform + Xbox CRT + modern MSVC STL + shims)
VERSION     # SDK tag (e.g. v0.1.0-cpp17)
```

`lib/xboxkrnl.lib` is the kernel import library. Host-side packaging and deploy tools are not included in this repo.

## Using the SDK in a project

Point your Xbox title project at this tree:

| Setting | Value |
|---------|--------|
| Include | single `/I` to `include/` |
| Library path | single `/LIBPATH` to `lib/` |
| C standard | `/std:c17` |
| C++ standard | `/std:c++17` |
| C++ force-includes | `/FI include/xdk_modern_stl.h` and `/FI include/xdk_crt_heap.h` |

**Retail vs debug:** pick libs by name — `d3d8.lib` for Release, `d3d8d.lib` for Debug. Both live in `lib/`. Config-agnostic names (`*ltcg`, `*i`, `uuid`, `xbdm`, …) have no `*d` sibling and appear once.

**Link line (typical):** `libcmt` + `libcpmt` + tier libs + `xboxkrnl.lib`. Do **not** mix in MSVC redist CRT/libs from Program Files.

For C++ exceptions, use `/EHsc`.

## Shipped libraries

52 ship libs in flat layout (Release + Debug names together, matching original XDK `lib\`):

| Tier | Libraries |
|------|-----------|
| CRT | `libcmt`, `libcmtd`, `libcpmt`, `libcpmtd`, `libc`, `libcd`, `libci`, `libcid`, `libcimt`, `libcimtd`, `libcp`, `libcpd` |
| xAPI | `xapilib`, `xapilibd`, `xbdm` |
| DirectX | `d3d8`, `d3d8d`, `d3d8i`, `d3d8ltcg`, `d3dx8`, `d3dx8d`, `dsound`, `dsoundd`, `xgraphics`, `xgraphicsd`, `xgraphicsltcg` |
| Audio / media | `dmusic`, `dmusicd`, `dmusici`, `dmusicltcg`, `xacteng`, `xactengd`, `xactengi`, `xactengltcg`, `xsndtrk`, `xsndtrkd`, `xvoice`, `xvoiced`, `wmvdec`, `wmvdecd` |
| Network / online | `xnet`, `xnetd`, `xnets`, `xnetsd`, `xkbd`, `xkbdd`, `xonline`, `xonlined`, `xonlines`, `xonlinesd` |
| System | `uuid`, `xboxkrnl` |
