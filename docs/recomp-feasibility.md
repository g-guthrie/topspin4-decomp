# Static recompilation as scaffolding: feasibility for Top Spin 4 (Xbox 360, 54540859)

RC1, 2026-11-14. This is a research note plus tooling. Nothing under `src/`, `config/` or
`tools/matching.py` was changed. Every generated file and download is under `work/recomp/`, which is
git-ignored. Every claim is tagged:

- **[here]**: measured in this container; the command is given.
- **[doc]**: read in a third-party repository fetched into `work/recomp/ref/`.
- **[web]**: taken from a web page, cited.
- **[inf]**: my inference.

## 0. Decisive facts

1. **The recompiler runs on this executable. [here]** XenonRecomp (hedge-dev, MIT, commit
   `ddd128b`, built with clang 18.1.3) reads `Swing_DLL.xex` directly, with no manual decrypting.
   We fed it our 46,730 function boundaries plus 552 switch tables from a new detector. It
   translated all 47,077 functions, 2,553,850 instructions, into 184 C++ files (171 MB) in **5
   seconds**. The stock XenonAnalyse finds **0** of the switch tables, because MSVC 16 schedules
   the table-load sequence differently. Our detector resolves every switch-shaped `bctr` (552
   tables, 11,334 case labels). Of its 534 absolute tables, 529 agree with Jeff's `jumptable_`
   sizes; one disagreement is a Jeff size bug (section 2.2).
2. **Only 0.15% of instructions are unhandled. [here]** 3,866 instruction sites, in 1,056
   functions (2.2%), are unhandled. All of them are reachable code. Most are plain PowerPC forms
   that XenonRecomp has not implemented: update-form loads and stores (`stfsu`, `lfsu`, `sthu`,
   `lhzu`, `*ux`: 2,235), `bdzf` (876, an MSVC switch-by-CTR idiom), and `eqv`, `subfze`, `addc`
   and `addme`. **VMX128 is nearly complete.** 75,971 VMX128 instructions of 59 kinds occur, and
   only `vsel128` (366), `vpkswss128` (60), `vcfpuxws128` (1) and 20 `vpkd3d128` float16_4 packs
   are missing. Every missing form is a few lines in `recompiler.cpp`.
3. **The generated C++ compiles. [here]**
   - **First run:** clang 18 `-O2 -march=x86-64-v3` compiled 183 of the 185 generated `.cpp` files
     cleanly. The other 2 failed on 3 `goto`s to labels in a neighbouring function: loops that
     Jeff split into two symbols.
   - **Fix:** `recomp_config.py` now merges such adjacent splits (46 merges, 38 unreferenced inner
     entries dropped). After it, a label check over all 47,039 functions finds 0 undeclared gotos,
     and the three affected files compile. Out-of-function branches fell from 71 to 28.
   - **Size:** 37.6 MB of x86-64 machine code (`size -t`: text 37,585,503) from 10.2 MB of
     PowerPC.
   - **It links and runs.** With a 150-line stub harness, the translated `_DllMainCRTStartup`
     runs the CRT start-up and every static initialiser to completion and returns TRUE, after
     255 kernel calls and with no fault (section 2.5).
4. **A complete open runtime already exists. [doc]** ReXGlue SDK (BSD-3-Clause, 2026, derived from
   Xenia) provides:
   - a codegen whose config is a superset of XenonRecomp's, including `is_dll`, switch tables and
     exception handlers;
   - Xenia's kernel and XAM HLE, which mentions **all 262** of Swing's import names (248 function
     thunks plus 14 variables; the grep counts stubs as present too);
   - Xenia's Xenos GPU command-processor emulation with D3D12 and Vulkan back ends;
   - an XMA decoder.

   About 60 Xbox 360 ports in 2026 are built on it (section 1). Unleashed Recompiled (GPL-3.0) is
   the other model. It hooks 42 D3D functions plus the render-state table, and its kernel covers
   183 of our 262 import names.
5. **Shaders translate. [here]** The disc holds **1,028 unique compiled shaders** (380 vertex, 648
   pixel; 4.2 MB, XDK container magic `102A1100`/`102A1101`) behind 15,650 archive entries.
   XenosRecomp (MIT) turns **all 1,028** into HLSL, and DXC compiles **845 (82%)** to SPIR-V
   unmodified. The 183 failures come from two documented XenosRecomp gaps: Texture1D (115 pixel
   shaders) and hard-coded Vulkan input locations (68 vertex shaders).
6. **The middleware boundary is narrow. [here]** Direct calls from game code into middleware reach:
   - D3D runtime: 76 distinct entry points;
   - D3DX: 21;
   - Havok: 174 (Animation 24, Physics 43, Base 37, mixed and utils 62, Compat 8);
   - FMOD: 31;
   - Bink: about 12.

   Virtual calls are not included (section 4).
7. **What could kill the approach. [inf]**
   - **D3D was linked as `D3D9LTCG`.** D3D state code is inlined into the game's renderer, so an
     Unleashed-style "hook the D3D API" renderer may not find a clean boundary. The fallback is
     GPU emulation, which is accurate but heavy for the browser.
   - **The browser has no memory aliasing and a 4 GiB wasm32 limit.**

   Neither is fatal for the native build.

## 1. Tools

| Tool | What it does | Licence | Status (date) | Source |
|---|---|---|---|---|
| **XenonRecomp** (hedge-dev) | XEX → C++. Per-instruction translation, one C++ function per guest function, CPU state in a struct, BE memory through byteswapping loads and stores, VMX via x86 intrinsics or SIMDe (ARM64). Function boundaries come from `.pdata`, `bl` scanning and an optional TOML list. Switch tables come from a TOML. No MMIO, no SEH. | MIT | commit `ddd128b` (2025-08-04) | [doc] `work/recomp/XenonRecomp/README.md`; [web] [repo](https://github.com/hedge-dev/XenonRecomp) |
| **XenonAnalyse** | Jump-table detector with fixed instruction patterns tuned for Sonic Unleashed | MIT | same | [here] finds 0 tables in Swing |
| **XenosRecomp** (hedge-dev) | Xenos shader microcode (XDK container) → HLSL → DXIL and SPIR-V via DXC; cache keyed by XXH3. Game-specific assumptions are marked `UNLEASHED_RECOMP`. | MIT | commit `70a084c` (2026-11-14) | [doc] README; [web] [repo](https://github.com/hedge-dev/XenosRecomp) |
| **Unleashed Recompiled** | Reference port, Sonic Unleashed. Translation-layer renderer (`gpu/video.cpp`, 7.9 k lines, D3D12 and Vulkan through plume), 42 `GUEST_FUNCTION_HOOK`s on D3D, 196 kernel and XAM hooks or stubs (`kernel/imports.cpp`), 191 mid-asm hooks, 372 switch tables, SDL2 audio | **GPL-3.0** (`COPYING`) | commit `cf829a9` (2026-06-29) | [doc] `work/recomp/ref/UnleashedRecomp` |
| **ReXGlue SDK** (rexglue) | Xenia-derived runtime plus its own codegen ("inspired by XenonRecomp and rexdex's recompiler"). Main source trees:<br>`src/codegen` (18.9 k lines; config keys include `is_dll`, `switch_tables`, `generate_exception_handlers`, `indirect_calls`, `midasm_hook`)<br>`src/kernel` (18.9 k; xboxkrnl, xam, xbdm, crt)<br>`src/graphics` (254 k; Xenia command processor, Xenos shader translator, D3D12 and Vulkan)<br>`src/audio` (XMA context emulation and decoder; FFmpeg submodule)<br>`src/filesystem`, `src/input` (SDL3), `src/ui`<br>Windows, Linux x64 and Linux arm64 CI | **BSD-3-Clause** (`LICENSE`, includes the Xenia notice) | commit `546a082` (2026-11-06), README says "early development" | [doc] `work/recomp/ref/rexglue-sdk`; [web] [repo](https://github.com/rexglue/rexglue-sdk) |
| **Xenia / Xenia Canary** | The emulator that every tool above borrows from (CPU semantics, GPU, kernel) | BSD-3-Clause | — | [web] cited by all of the above |
| rexdex's recompiler | The earliest Xbox 360 static recompiler, now superseded | — | — | [doc] ReXGlue README |

**Ports built this way. [web]** The curated list
[awesome-x360-recomps](https://github.com/abduznik/awesome-x360-recomps) records 72 projects. 60
use ReXGlue and 12 use XenonRecomp/XenosRecomp. Examples:

- ReXGlue: Skate 3, Crackdown, Fable II, Forza Horizon, Burnout Revenge (own Vulkan renderer), PGR4,
  Ninja Gaiden II, Rockstar Table Tennis.
- XenonRecomp: Sonic Unleashed, Sonic '06 (MarathonRecomp), Dead Rising 2 Case Zero and Case West,
  NFS Most Wanted ("SpeedBreaker"; experimental iOS), The Simpsons Game (Xenia-derived runtime),
  Call of Duty 3.

The list records platform claims but no licences. The pattern ([web],
[guide](https://heldgames.com/guides/xbox-360-recompilation-rexglue)): each port is hand-built.
Each one needs its own runtime fixes and game-specific hooks, and asks users for their own files.
Rockstar Table Tennis is the closest genre match: a RAGE-engine sports game of the same era. Its
existence says the approach copes with this class of game. It says nothing about effort. [inf]

**What each needed. [doc][inf]** From the two repositories read here:

- **Unleashed** needed a renderer translation layer and a hand-curated shader cache. It also
  needed kernel, XAM and filesystem HLE, an audio driver, mid-asm hooks for game-specific fixes,
  and patches for frame-rate independence.
- **ReXGlue ports** reuse Xenia's GPU emulation, so they need little renderer work. The
  per-title work is mostly hooks, fixes and the config.
- **ReXGlue's direction.** Its founder's interview says the graphics system is "an abstract
  interface injected at build time". The plan is to replace Xenia's GPU, audio and input with
  native implementations over time. Each port has to work out how its game used the Xenos GPU.
  Blue Dragon is the pilot title and already runs faster than on the console
  ([interview](https://readonlymemo.com/rexglue-xbox-360-recompilation-interview/)) [web]. That
  injection point is where our own renderer would plug in [inf].

## 2. Run it

### 2.1 Commands and versions [here]

| Item | Value |
|---|---|
| XenonRecomp | `https://github.com/hedge-dev/XenonRecomp` `ddd128bcca99fe8bfbb99bea583c972351fa6ace`, built `cmake -G Ninja -DCMAKE_BUILD_TYPE=Release` with Ubuntu clang 18.1.3, cmake 3.28.3, x86-64 |
| XenosRecomp | `70a084c2392378818a4da4086e8e3420b4c3ea8d`, DXC from its `dxc-bin` submodule (`dxc-linux`) |
| Inputs | `Swing_DLL.xex` sha256 `dfa71292…fac44`; `Swing_DLL.dll` sha256 `a7f28b29…ba9`; `config/54540859/symbols.txt` (46,736 distinct function starts) |
| Python | 3.13.18 (new tool is standard library only) |

```sh
python3 tools/recomp_config.py config --image orig/54540859/Swing_DLL.dll \
  --symbols config/54540859/symbols.txt --xex ../../../orig/54540859/Swing_DLL.xex \
  --name Swing --out-dir work/recomp/swing --setjmp 0x8856B7F0 --longjmp 0x88569D30
cd work/recomp/swing && ../XenonRecomp/build/XenonRecomp/XenonRecomp Swing.toml ../XenonRecomp/XenonUtils/ppc_context.h > recomp.log
python3 tools/recomp_config.py triage --image orig/54540859/Swing_DLL.dll \
  --symbols config/54540859/symbols.txt --log work/recomp/swing/recomp.log \
  --switches work/recomp/swing/Swing_switch_tables.toml
```

Generated configs: `Swing.toml` sha256 `ae8d6728…4d6b` and `Swing_switch_tables.toml` sha256
`4c1c49da…5c42`. They hold addresses only.

### 2.2 What the config generator found (`tools/recomp_config.py config`) [here]

- **Function list.** 46,730 non-overlapping code functions, in `.text`, `BINK` and `RADCODE`. The
  register save/restore helpers are left out, because XenonRecomp generates them itself.
- **Save/restore helpers.** All eight were found by the byte patterns in the XenonRecomp README.
  They match the names in `symbols.txt`: `__savegprlr_14` at 0x8856AC40, `__restgprlr_14` at
  0x8856AC90, `__savefpr_14` at 0x8856B2F0, `__restfpr_14` at 0x8856B33C, `__savevmx_14` at
  0x8856AD90, `__restvmx_14` at 0x8856B028, `__savevmx_64` at 0x8856AE24 and `__restvmx_64` at
  0x8856B0BC.
- **setjmp and longjmp.** These matter because Lua 5.0 error handling uses them.
  - `setjmp` = 0x8856B7F0 (from `symbols.txt`).
  - `longjmp` = 0x88569D30. Lua `luaD_throw` (0x8881D390) calls it. The body restores f14 and the
    following registers from the jmp_buf.
- **`bctr` census, 1,565 sites:**

  | Kind | Count |
  |---|---:|
  | Switch, absolute (word table in `.text` after the `bctr`) | 534 |
  | Switch, byte offset table in `.rdata` | 7 |
  | Switch, halfword offset table in `.rdata` | 11 |
  | Indirect jump through a loaded pointer (vcall or tail call) | 703 |
  | Import thunks | 248 |
  | Other register jumps (function-pointer tail calls) | 54 |
  | Pointer-table tail calls (`lwzx` without bound) | 6 |
  | Switch whose cases are other functions (0x888B3C0C) | 1 |
  | Unclassified | 2 |

  The byte and halfword tables are all in the XDK and FMOD ranges. The switch at 0x888B3C0C works
  as an indirect tail call, because every target is a known function. No switch-shaped `bctr` is
  left unresolved.
- **Case counts.** 449 come from the dominating `cmplwi`, following `mr` copies. 103 come from a
  table scan.
- **Cross-check with Jeff.** 529 of the 534 absolute tables have the same length as Jeff's
  `jumptable_` symbol. Four have no size in `symbols.txt`. One disagrees: 0x8849E1E4 has
  `cmplwi 15`, so 16 entries, and all 16 words are in-function addresses, but `symbols.txt` gives
  `jumptable_8849E1E8` size 0x34 (13). That is a Jeff size bug worth fixing in the split (not done
  here: `config/` is out of scope).
- **Indirect calls.** 17,354 `bctrl` sites. XenonRecomp resolves every indirect call at run time
  through a table indexed by guest address. It is filled from the 47,077 function entries, so any
  target that is a known function start works.

### 2.3 What XenonRecomp did with it [here]

| Measure | Swing_DLL | Loader_DLL | default.xex |
|---|---:|---:|---:|
| Function boundaries supplied | 46,730 (`symbols.txt`) | 9,686 (`loader/symbols.seed.txt` only) | 0 (XenonRecomp's own analysis) |
| Functions emitted | **47,077** | 17,615 | 481 |
| Switch tables used | 552 | 17 (only in seeded functions) | 0 |
| Instructions translated (generated comment lines) | 2,553,850 | — | — |
| Unrecognised instruction sites | **3,866** in 1,056 functions | 10,271 | 12 |
| Out-of-function branch targets dropped (`// ERROR`) | 71 sites, 59 targets | — | — |
| Run time | 5.1 s | 4.6 s | <1 s |
| Output | 184 `.cpp`, 171 MB | 73 files, 83 MB | 2 MB |

**Unrecognised instructions in Swing, all reachable.** `triage` walks intra-function control flow
from each entry, including switch edges.

| Instruction | Sites | Note |
|---|---:|---|
| `bdzf` | 876 | MSVC "switch by CTR decrement" chain (`mtctr r11; bdzf cr6.eq,…` ×N) |
| `stfsu` / `lfsu` / `stfsux` / `lfsux` / `stfdu` / `lfdu` | 776 / 461 / 67 / 72 / 4 / 3 | update forms |
| `sthu` / `lhzu` / `lhau` / `sthux` / `lhzux` / `stbux` / `lbzux` / `lwzux` / `stdux` / `ldux` | 385 / 298 / 22 / 63 / 29 / 19 / 13 / 10 / 9 / 4 | update forms |
| `vsel128` | 366 | VMX128 |
| `eqv`, `subfze(.)`, `addc`, `addme`, `mulhdu` | 129, 68, 39, 28, 12 | integer |
| `vpkswss128`, `vcfpuxws128` | 60, 1 | VMX128 |
| `vsubuwm`, `vsububm`, `vminub`, `vmaxub`, `vaddsws`, `vsubshs`, `lvehx`, `lhbrx`, `frsqrte`, `dcbst`, `bdnzt` | 9, 8, 8, 8, 2, 1, 4, 8, 1, 1, 2 | VMX and misc |
| warnings: `vpkd3d128` float16_4 pack variant, `vcmpbfp128.` without compare | 20, 3 | |

By bucket (`tools/decomp_survey.py` ranges): FMOD core 589, XAudio2/XMA 557, FMOD codecs 478, game
core loaders 428, Pam core 228, front end 223, D3DX 175, Havok mixed 163, Lua 141, libpng/jpeg 131,
then smaller counts. Swing gameplay has 77 and the renderer 95.

**Cross-function branches.** 71 conditional or unconditional branches jump into the middle of
another function. XenonRecomp emits `// ERROR` and drops them, which is silently wrong code. 59
distinct targets, mostly in the XDK CRT and XAudio2 (0x88562D78-0x885DABF8) plus the Bink asm
(`RADCODE` 0x88B14AA8). Fix: give these targets function entries (allow overlap in `functions`), or
merge the pairs.

**Instruction coverage overall.** 361 distinct mnemonics occur. VMX and VMX128 account for 93,925
instructions (113 kinds), of which VMX128 is 75,971 (59 kinds). XenonRecomp handled all but the
four VMX128 forms above, plus the 20 `vpkd3d128` warnings.

**Loader_DLL** has many more gaps: 16-bit integer SIMD (`vslh` 2,606, `vsrah` 1,136, `vsubshs`
1,114, `vspltish` 671, `vmaxsh` 339) in code we have not attributed; probably video or image
decode [inf]. It also needs a full symbol set. The Jeff split gives 17,215 functions, but only the
9,686-entry seed is committed, so its switch tables are only partly covered.

**default.xex** is small (481 functions). It only has GPR save/restore helpers. Loader_DLL contains
the strings `game:\Loader_DLL.xex` and `game:\Swing_DLL.xex`, so the chain is default.xex →
Loader_DLL (image base 0x83000000) → Swing_DLL (0x88000000) [here, strings and XEX headers]. The
three image ranges do not overlap. A runtime must implement `XexLoadImage`,
`XexGetProcedureAddress` and `XexGetModuleHandle` over the precompiled modules (ReXGlue's
`is_dll`). The alternative is to boot Swing directly once the Loader → Swing handoff is understood
(unverified).

### 2.4 Does the generated C++ compile? [here]

Command (per file, 4 in parallel):
`clang++ -std=c++20 -O2 -march=x86-64-v3 -fno-strict-aliasing -I ppc -I ../XenonRecomp/thirdparty/simde -c ppc/ppc_recomp.N.cpp`.

**First config (`work/recomp/swing`):**

- 183 of 185 files compiled with no errors and no warnings promoted to errors.
- `ppc_recomp.62.cpp` and `.63.cpp` failed on three `goto loc_X` whose label lies in the previous
  symbol: `sub_88562DFC` → 0x88562DE4, `sub_8856AB20` → 0x8856AB08, `sub_8856ABC0` → 0x8856ABB0.
  - All three are hand-written CRT loops (around `memset` 0x8856ABA0) whose `bdnzf` loop bottom was
    split into its own symbol.
  - XenonRecomp checks function bounds for `b`/`bc` but not for the CTR-decrementing forms.
- One file takes 5.6 s on an idle core, and the largest (4.2 MB) about 30 s. The whole set took
  about 30 minutes on this 4-core container, which was shared with other jobs (load average 8-17).
- Object code: text 36,976,884 bytes, data 796,384 bytes (`size -t obj/*.o`), 53 MB of `.o` files.

**Second config (`work/recomp/swing5`, merge enabled):**

- `recomp_config.py config` now merges a function with a neighbour (up to two symbols away, at most
  0x400 bytes of growth) when one branches into the other's body. An inner entry survives as a
  separate, overlapping function only if a direct call, tail call or data word references it.
  - 46 merges; 38 inner entries dropped; 46,692 functions supplied, 47,039 emitted.
- An undeclared-label scan over every generated function finds **0**, against 3 before.
  `// ERROR` (dropped out-of-function branches) fell from 71 sites to **28 sites, 17 targets**:
  - XDK CRT and XAudio2/XHV 0x88562D78-0x885DABF8;
  - the Bink asm target 0x88B14AA8.

  They need explicit entries or a XenonRecomp change.
- **All 185 files compile with 0 errors** (`work/recomp/swing5/obj`). Text 37,585,503 bytes, data
  797,312 bytes.

**Link.** The objects reference the 248 import functions (`__imp__<Name>`), which a runtime must
define. With the stubs of section 2.5, `clang++ -fuse-ld=lld` links them into a 44 MB x86-64
executable in under a second.

### 2.5 Smoke run [here]

`work/recomp/swing/harness/` holds a throwaway harness of about 150 lines (work/ only), built
against the `swing5` objects:

- It reserves 4.5 GiB of host address space, copies the PE sections to guest 0x88000000, and fills
  the indirect-call table: 47,287 entries.
- It points the 14 variable imports at zeroed guest blocks.
- It implements about 25 imports trivially: critical sections, TLS, a bump allocator for
  `NtAllocateVirtualMemory` and `MmAllocatePhysicalMemoryEx`, and `KeGetCurrentProcessType`.
- Every other import is a logging stub that returns 0.
- It calls the entry point `_DllMainCRTStartup` (0x88562DB0) with `DLL_PROCESS_ATTACH`.

```sh
cd work/recomp/swing/harness && ./harness ../../../../orig/54540859/Swing_DLL.dll
```

**Result:**

- **The translated CRT start-up and all static initialisers run to completion, and `DllMain`
  returns TRUE**, after 255 import calls and with no fault.
- Calls seen, in order: `RtlImageXexHeaderField`, 2 `NtAllocateVirtualMemory` (CRT heap),
  19 critical-section inits, 4 `KeTlsAlloc`, then `XexLoadImage("xam.xex")` and
  `XexGetProcedureAddress` for xam ordinals 0xAFF and 0xB00. With our stubs those fail, and the CRT
  falls back cleanly. Last comes `KeQueryPerformanceFrequency`.
- The game's main loop is not started by `DllMain`. Loader_DLL presumably calls into Swing after
  loading it; that handoff is unverified.

**Lesson recorded in the tool.** The first harness run returned FALSE immediately. Our function list
had claimed the 248 XEX import thunks as ordinary `sub_` functions, so XenonRecomp translated the
thunk words as code instead of naming them after the import. The harness works around it with
strong overrides (`thunks.cpp`, `sub_<thunk>` → `__imp__<Name>`). `recomp_config.py config` now
leaves thunks out of the function list, so future configs get XenonRecomp's import naming directly.

## 3. What the game needs from a runtime

Import counts come from `python3 tools/recomp_config.py imports ...` (call sites into each thunk)
and `symbols.txt` (`__imp_*`). Swing imports only from `xam.xex` and `xboxkrnl.exe` [here, XEX
import header]. It has 248 function thunks (242 called) and 14 variable imports (`VdGlobalDevice`,
`KeTimeStampBundle`, `XboxHardwareInfo`, `ExThreadObjectType`, and others). Almost every import is
reached through the statically linked xapi layer (CRT + xapi 0x88562AB8-0x88590000). For example,
`NtCreateFile` is called once, from `fn_8857C5A0`, and `ExCreateThread` from two functions. So the
runtime implements the kernel and XAM level, not Win32.

| Piece | What Swing uses (measured) | Size estimate [inf] | Exists in open runtimes [doc] |
|---|---|---|---|
| **Memory layout** | Image base 0x88000000, image size 0xDD0000, code 0x88150000-0x88B152F8. Loader at 0x83000000 (0x5E0000), default at 0x82000000 (0x180000). Allocations via `NtAllocateVirtualMemory` (12 sites; the 0x40000000 64 KB heap) and `MmAllocatePhysicalMemoryEx` (5 sites: D3D, PIX, xapi; the 0xA0000000/0xC0000000/0xE0000000 physical aliases of 512 MB). Big-endian memory throughout. | 0.5-1 k lines | ReXGlue `src/system/xmemory.cpp` uses exactly this map with host aliasing (verified in source). Unleashed has a simpler heap. |
| **Threading and sync** | `KeTlsGetValue` (2,734 call sites, mostly Havok `hkThreadMemory` and game core), critical sections (705 sites), `ExCreateThread`, events, semaphores, mutants, timers, `KeWaitFor*`, `NtWaitForMultipleObjectsEx`, `KeSetAffinityThread`, spin locks, DPC and APC (XAudio2). OpenMP runtime present (17 call sites). | 2-3 k lines | ReXGlue (Xenia kernel), Unleashed (`kernel/imports.cpp`, most of these) |
| **File I/O and archive loading** | `NtCreateFile`, `NtOpenFile`, `NtReadFile`, `NtReadFileScatter` (0 sites), `NtQueryDirectoryFile` (0), `NtQueryInformationFile`, `NtQueryFullAttributesFile`, `NtSetInformationFile`, `NtWriteFile`/`Gather`. The game opens `game:\…` paths and reads PAM-LZX `.arc` archives itself in game code: `tools/ts4_arc.py` and `tools/ts4_lzx.py` document the format. Also `IoCreateDevice`, `ObCreateSymbolicLink` and `StfsCreateDevice`: an in-title device for content packages. | 1-2 k lines (path mapping to the user's ISO or folder, XDVDFS reader) | ReXGlue `src/filesystem` (disc image and STFS), Unleashed `kernel/io/file_system.cpp` (folder-backed). Our `tools/xdvdfs.py`, `tools/stfs.py` and `tools/xiso.py` define the formats. |
| **Graphics** | Statically linked D3D (`D3D9LTCG 2.0.20209.16387` in the XEX library list). The Vd* kernel calls show a ring-buffer GPU driver: `VdInitializeRingBuffer`, `VdSwap`, `VdGetSystemCommandBuffer`, `VdSetGraphicsInterruptCallback`, EDRAM retraining, and others (≈30 Vd imports). 76 D3D runtime and 21 D3DX entry points are called directly from game code (section 4). D3DX texture loaders (230 KB unmatched) and the xgraphics shader microcode compiler (44 KB) are also linked. 1,028 unique shaders in XDK container format. | Emulation route: reuse 254 k lines (ReXGlue). Translation route: 8-15 k lines (Unleashed's `video.cpp` is 7.9 k) plus shader cache tooling. | ReXGlue: Xenia PM4 command processor and Xenos translator → D3D12/Vulkan. Unleashed: D3D-API translation layer → plume (D3D12/Vulkan). XenosRecomp: offline HLSL. |
| **Audio** | FMOD Ex 4.32.02 → XAudio2 (statically linked) → kernel `XAudioRegisterRenderDriverClient`, `XAudioSubmitRenderDriverFrame` and `XAudioGetSpeakerConfig`. XMA via `XMACreateContext`/`XMAReleaseContext` and **`MmMapIoSpace`** (hardware registers, from XAudio2 `fn_8859AB88`). Banks: FSB4 with XMA (most), MP3 and Xbox IMA (`docs/port/presentation-and-audio.md`). Voice: `MicDeviceRequest`/`RmcDeviceRequest`. | Render driver 0.3-0.5 k lines. XMA decode: reuse FFmpeg's `xma2` decoder (LGPL) or ReXGlue's XMA context emulation. | ReXGlue `src/audio` (XMA context, register file, decoder). Unleashed has an SDL2 driver only (its audio did not use XMA hardware this way). XenonRecomp has no MMIO. |
| **Input** | `XamInputGetState`/`SetState`/`GetCapabilities` (1 site each, xapi wrappers) | 0.2 k lines | both |
| **Save data** | `XamContentCreateEx`/`Close`/`Delete`/`Flush`/`CreateEnumerator`/`GetDeviceState`/`GetDeviceData`/`GetCreator`, `XamShowDeviceSelectorUI`, profile settings (`XamUserRead/WriteProfileSettings`) | 0.5-1 k lines (map content to a host folder or browser IndexedDB/OPFS) | ReXGlue (Xenia content manager), Unleashed (partial) |
| **Online and system UI (stub)** | 34 `NetDll_*` (sockets and XNet), `XamSession*`, `XamUserCreateStatsEnumerator`, `XamShow*UI` (12: signin, friends, keyboard, gamercard, achievements, marketplace, message box, …), `XNotify*`, `XMsg*`, `XamVoice*`, `XamLoaderLaunchTitle` | 0.5 k lines of stubs that report "offline / no user change" | ReXGlue (all names present), Unleashed (most stubbed) |
| **Exceptions** | `__C_specific_handler` (0 call sites), `RtlUnwind` (2), `RtlRaiseException` (3), 55 `except_data` blocks in `.text` | Low if the game does not rely on SEH at run time | ReXGlue has `generate_exception_handlers`. XenonRecomp has none. |

Coverage check: all 262 Swing import names appear in ReXGlue's `src/kernel` sources (some may be
stubs), and 183 appear in Unleashed's kernel sources (`grep -w` over both trees).

## 4. The replacement plan (middleware boundary)

**Method. [here]** Run `python3 tools/recomp_config.py boundary --image ... --symbols ... --json
work/recomp/boundary_game.json`. It collects every direct `bl` and every out-of-function `b` whose
caller lies in a `game` bucket of `tools/decomp_survey.py` and whose target lies in another bucket.

**Limits:**

- Virtual and function-pointer calls (17,354 `bctrl` sites in total) are **not** in these numbers.
  Havok and the FMOD Event API are partly C++ interfaces, so these are lower bounds. A run-time
  trace in the recompiled build (log every indirect call that crosses a bucket) will close the gap.
- The "bink" range starts with the import thunks (0x88B00160…). Those three callees are imports,
  not Bink.

| Middleware | Distinct callees from game code | Call sites | Calling game functions | Notes |
|---|---:|---:|---:|---|
| D3D9 runtime (0x88287D28-0x882A0000) | **76** | 771 | 190 | Top: 0x88288530 (interlocked release, 99 sites), 0x882882A0 (82), 0x8828B128, 0x8828A3B8, 0x88292698 … |
| D3DX9 loaders | 21 | 53 | 28 | texture-from-memory family |
| PIX / debug | 2 | 6 | 2 | stub |
| Havok Animation (hka) | 24 | 83 | 37 | 0x88403FD0 (20 sites) … |
| Havok Physics (hkp) | 43 | 101 | 37 | world, bodies, queries |
| Havok Base/Serialize, Compat, mixed | 37 + 8 + 62 | 304 | 155 | memory, packfile loading, utilities |
| Havok reflection/static init | 10 | 406 | 212 | class registration |
| FMOD event system | 20 | 31 | 15 | `ts4_if_get_fn_883CB130_*` = C++ API thin wrappers (`EventI::validate` then forward) |
| FMOD core | 11 | 13 | 9 | |
| Bink | ≈12 | 33 | 12 | intro and attract videos |
| CRT + xapi | 296 | 20,661 | 7,019 | memcpy/memset/malloc/strings: replace with libc |
| Lua 5.0.2 | 166 | 1,529 | 446 | open source, keep |

**Havok Animation: what matters is sampling and blending.**

- `docs/havok.md` and `tools/havok/` already decode the three compressed codecs the game ships
  (spline, delta, wavelet). The decoders were checked against the game's own decompression
  routines, and export skeletons and clips to glTF.
- **Replacement** keeps the 24 entry points' guest ABI and implements them in C over guest memory.
  XenonRecomp emits every function as a weak symbol with an `__imp__` alias, so a replacement is
  one `PPC_FUNC(sub_X)` definition. The work is the decoder port to C plus the blend tree.
- **Identical:** bit-exact is realistic [inf]. Decoding is integer unpacking plus a fixed float
  sequence. Keep the original float operation order and VMX128 rounding (SIMDe reproduces the
  instruction semantics), and compare the sampled poses against the translated original frame by
  frame.

**Havok Physics.**

- Ball flight, bounce and net are closed-form game code, not Havok (`docs/gameplay/gp4b.md`,
  validated bit for bit).
- Havok Physics drives ragdolls (`Baked_*` `Physics.hkx`), venue and prop rigid bodies, and the net
  rig, plus some queries from the physics wrapper (WP4 in `docs/gameplay-map.md`).
- **Replacement** behind 43 hkp entry points means a solver that behaves the same.
- **Identical:** bit-exact physics replacement is unrealistic [inf]. The translated Havok is already
  bit-exact; only a replacement is the problem. A replacement can be at best visually identical,
  and only where the gameplay never reads back the physics state.

**FMOD.**

- 31 direct entry points (event start/stop, parameters, 3D attributes), plus whatever goes through
  interface pointers.
- Formats are already decoded: FEV event and FSB4 bank readers in `tools/port/`, and trigger
  functions in `docs/port/presentation-and-audio.md`.
- **Boundary options:**
  - **(a) Keep FMOD and XAudio2 translated**, and implement only the 5 XAudio kernel imports plus
    XMA decode. The output is sample-identical to the original mix only if the XMA decoder is exact
    (FFmpeg's is not bit-exact to hardware [inf]). In practice it is audibly identical.
  - **(b) Replace FMOD** with our own event player over the decoded banks. Mixing, DSP and
    3D-attenuation curves would differ, so the result is only "sounds the same". Pursue it only for
    the browser footprint.

**Graphics.** Two different meanings of "replace":

- **(a) Emulate the GPU** below D3D (ReXGlue).
  - The game's own D3D code runs translated and writes PM4 packets.
  - The runtime interprets them and translates Xenos shaders at run time.
  - The result is visually identical at Xenia accuracy, with zero hooks.
- **(b) Hook D3D** (Unleashed).
  - Replace the API entry points: here 76 runtime plus 21 D3DX functions, plus the device's
    render-state function table, plus whatever LTCG inlined.
  - Ship shaders pre-translated with XenosRecomp. 82% compile today; the 183 that fail need
    Texture1D support and per-shader input locations.
  - This is what makes a WebGPU renderer practical.
- **Risk:** the XEX library list says `D3D9LTCG`, so D3D parts compiled with /GL were inlined into
  game code at link time. That is consistent with the D3D runtime range being only 98 KB [inf]. The
  amount of inlined state-setting code in the renderer (0x886E8000-0x88780000) is **not measured**.
  It decides how many mid-asm hooks route (b) needs. Measure it by tracing writes to the D3D device
  struct and command buffer in the recompiled build.
- **Identical:** visually identical, not bit-exact. Rasterisation, EDRAM resolve formats, gamma ramp
  and MSAA patterns differ between Xenos and desktop GPUs.

**Bink.** 86 KB plus hand-written PPC asm in `RADCODE`, and 3 of the 71 out-of-function branches.
Replace the video player with any decoder of the user's `.bik` files (FFmpeg decodes Bink 1) or skip
the videos. Visually identical.

## 5. Browser (WebAssembly + WebGPU)

**Known from other projects. [web]**

- **PS2 Web Recomp** translates PS2 code to C++ and compiles it to wasm, with the console
  reimplemented in a WebGPU runtime. Gran Turismo 4 holds about 50 fps in Chrome on a laptop iGPU
  at 2× resolution ([Adafruit](https://blog.adafruit.com/2026/10/12/ps2-games-in-browser-static-recompilation-to-webassembly-with-a-native-runtime/),
  [guide](https://ps2webrecomp.app/)).
- **WebCompiled** (Mario Kart Wii) is a PowerPC → C++ → wasm build ([repo](https://github.com/dynamiteswag81/webcompiled), GPL-3.0):
  - Emscripten, WebGPU through Dawn's emdawnwebgpu.
  - Guest threads use **JSPI**, with no SharedArrayBuffer and so no COOP/COEP headers.
  - The disc is streamed with HTTP Range requests; saves go to IndexedDB.
  - About 60 fps on desktop Chrome/Edge 137+; on Android Chrome "a full race works but slowly with
    glitches".
  - No Firefox or Safari yet.
- **nfsu2-web** maps D3D9 to WebGPU and streams assets into OPFS after a ~7 MB first download
  ([article](https://pro-gamer.gg/need-for-speed-underground-2-playable-browser-120-fps-webgpu-multiplayer-free-roam/)).
- I found no Xbox 360 recompilation running in a browser.
- **Platform support:**
  - Memory64 shipped in Chrome 133 and Firefox 134; Safari was still missing it in early 2026
    ([SpiderMonkey](https://spidermonkey.dev/blog/2025/01/15/is-memory64-actually-worth-using.html),
    [WebKit bug](https://bugs.webkit.org/show_bug.cgi?id=300538)).
  - The SpiderMonkey post measures memory64 as noticeably slower because of bounds checks.
  - JSPI shipped in Chrome; Firefox planned to enable it by default from version 153
    ([intent](https://groups.google.com/a/mozilla.org/g/dev-platform/c/8cOxM-dWaNs)).

**Inference for Top Spin 4. [inf]**

- **Memory.**
  - XenonRecomp's model is `base + guest_address` over a 4 GiB reservation, with the physical
    512 MB aliased three times by host mmap. wasm32 has one linear memory of at most 4 GiB, shared
    with the host heap, and no aliasing.
  - So redefine `PPC_LOAD_*`/`PPC_STORE_*` (they are macros in `ppc_context.h`) to map guest
    addresses through an 8-entry table on the top 3 bits:
    - 0x4-0x7 → the virtual heap window;
    - 0x8 → the images (Swing alone is 14.5 MB);
    - 0xA/0xC/0xE → one 512 MB physical block.
  - About 1.2-1.5 GiB of wasm memory in total. That is one load and an AND per access; expect
    10-30% on memory-heavy code.
  - memory64 avoids the remap but costs more and does not exist in Safari.
  - The indirect-call table shrinks to 4-byte entries (about 10 MB for Swing).
- **Threads.** The game creates several threads: FMOD and XAudio2 workers, streaming, render and
  OpenMP regions. Two choices:
  - **pthreads over SharedArrayBuffer.** Needs cross-origin isolation (COOP/COEP headers). Guest
    `lwarx`/`stwcx.` map to wasm atomics.
  - **Cooperative JSPI fibres**, the WebCompiled choice. This works only if the game tolerates
    serialised threads, which is plausible for a 30/60 fps console title. Busy-wait spin loops need
    yields.
- **Assets.**
  - The retail ISO is 7,838,695,424 bytes [here]. The player selects their own ISO or extracted
    folder.
  - A `File` gives random access by `slice()` without copying. The File System Access API (Chrome)
    or OPFS can keep it for later sessions.
  - The XDVDFS reader and the archive formats are already documented (`tools/xdvdfs.py`,
    `tools/ts4_arc.py`), so the runtime reads archives on demand. Nothing is downloaded from us
    except the wasm build.
  - Shader translation and the HLSL → WGSL step (DXC → SPIR-V → Tint or Naga) run at install time
    on the user's machine, or are precomputed only as code that contains no game data.
- **Shader translation.** XenosRecomp HLSL → SPIR-V works for 82% today [here]. SPIR-V → WGSL needs
  Tint or Naga, which is unverified for these shaders. Specialisation constants map to WGSL
  `override`. WGSL supports `texture_1d`.
- **Binary size.** The native object code size is in section 2.4. Wasm will be similar, and gzip or
  Brotli usually cut it by 3-4×.
- **Performance.** A laptop with an integrated GPU should reach full speed if the renderer is route
  (b), by analogy with GT4 at 50 fps and MKWii at 60 fps. Route (a), Xenia-style emulation in wasm,
  is a much heavier lift: EDRAM emulation and run-time shader translation. A phone is likely below
  full speed at first, as WebCompiled reports for a lighter game. iOS needs WebGPU in Safari plus
  JSPI or threads.

## 6. Recommendation and plan

**Recommendation.** Adopt static recompilation as the scaffolding.

- Build the native first boot on the **ReXGlue SDK runtime** (BSD-3: compatible with keeping our
  own code under any licence, and it already has the kernel HLE, the Xenia GPU, XMA and DLL loading).
- Feed it **our** function boundaries and switch tables. They are richer than any automatic
  analysis: 46,730 boundaries and 552 tables versus XenonAnalyse's 0.
- Keep XenonRecomp as the second translator for cross-checks: same input TOML shape, and a smaller
  codebase to patch.
- Then move the renderer and audio to our own layers behind the measured boundaries. Do this before
  the browser port, because the browser needs route (b) for graphics.

| Stage | Work | Rough effort (agent rounds) [inf] | Feeds from existing assets |
|---|---|---|---|
| 0 (done) | Recompiler built, Swing translated, compiled, linked, and `DllMain` run natively with stub imports; config generator; census | — | `symbols.txt`, Jeff jump tables, `decomp_survey.py` ranges |
| 1 | **Close translation gaps:** add the ~40 missing instruction forms (or switch codegen to ReXGlue's: of 15 mnemonics checked by name, its `src/codegen` handles all but `lhbrx` and `lvehx` [doc]); fix the remaining 28 cross-function branches; emit `switch` on `.u32`; full Loader symbol set from the Jeff split; run Xenia's PPC instruction tests through the chosen codegen | 1-2 | Jeff split for Loader |
| 2 | **First boot, the first milestone on screen:** default.xex → Loader_DLL → Swing_DLL on ReXGlue's runtime, natively on Linux/Windows, user-supplied ISO. Target: the Loader's logo and loading screens, then the Swing front end rendered by Xenia's GPU path | 2-4 | XEX headers, `tools/xdvdfs.py` |
| 3 | **Gameplay parity:** play a match; trace the ball state (`ball+0x4C0..0x4DC`) and shot-outcome rolls against `src/xbox360/drafts/gp4b_ball_model.c` and the documented analyser graphs; apply the owner's retune as data patches (`docs/data-patching.md`) | 1-2 | `docs/gameplay/*`, `data/gameplay/` |
| 4 | **Replace game functions with clean C:** override the weak `sub_*` with matched or drafted C, starting with gameplay (ball model, shot error, reach) | continuous | 30k matched functions in `src/` (needs a big-endian guest-memory accessor layer: `be<T>`/guest-pointer types like Unleashed's), drafts, names in `symbols.txt` |
| 5 | **Own audio:** 5 XAudio kernel imports + XMA decoder → SDL / WebAudio | 2-3 | `tools/port/fmod_fsb.py`, FSB/FEV notes |
| 6 | **Own renderer (route b):** hook the 76+21 D3D entry points + render-state table + measured LTCG inlines; XenosRecomp shader cache with Texture1D and per-shader locations; WebGPU via Dawn natively | 6-10 | `tools/ts4_texture.py`, `ts4_mesh.py`, materials notes, 1,028-shader census |
| 7 | **Browser:** Emscripten build, address remap macros, JSPI or pthreads, File/OPFS ISO reader, WebGPU renderer from stage 6, WGSL shader path | 4-8 | `tools/xdvdfs.py` and `ts4_arc.py` logic ported to C |
| 8 | **Middleware replacement** where it pays: Havok Animation sampling (bit-exact target), Bink (FFmpeg), CRT (libc); FMOD and Havok Physics only if needed | 3-6 per library | `tools/havok/`, `docs/havok.md` |

**What could kill it. [inf]**

1. **The renderer cannot be cleanly hooked** because of D3D9LTCG inlining. The native build still
   works under GPU emulation, but the browser build would then need Xenia-class GPU emulation in
   wasm and WebGPU, which is unproven.
2. **Timing and threading assumptions** break when code runs 5-20× faster than on the Xenon, or
   with JSPI-serialised threads in the browser. These bugs are typical of every port listed above
   and are fixed one hook at a time.
3. **Runtime maturity.** ReXGlue is "early development" and changes its API quickly. Pin a commit
   and keep our runtime patches small.
4. **Browser limits.** No memory aliasing, 4 GiB, Safari without memory64 or JSPI, phone GPU
   budgets.
5. **Distribution.** Translated middleware must be generated on the user's machine from their own
   XEX, never shipped. The repository can hold the tools, configs (addresses only) and our runtime.

**First concrete next step.** Build ReXGlue's codegen and runtime in a container with more disk
than this one had: 4 GB free here, and its submodules include FFmpeg, Vulkan and SDL3. Convert
`work/recomp/swing/Swing.toml` and the switch TOML to its `functions`/`switch_tables` keys, and run
it on all three modules.

## 7. Files

| Path | What |
|---|---|
| `tools/recomp_config.py` | Standard-library tool. `config` writes the XenonRecomp TOML, switch TOML and report. `triage` classifies unrecognised instructions by reachability and bucket. `boundary` gives the game → middleware call boundary. `imports` gives thunks and call counts. |
| `tests/test_recomp_config.py` | Synthetic-code tests: absolute and byte switch shapes, bound through `mr`, vcall rejection, clobbered index, helper patterns, TOML shapes, symbol parsing, reachability |
| `work/recomp/` (ignored) | XenonRecomp checkout and build, `swing/` `loader/` `default/` configs, logs and generated C++, `shaders/` (extracted, local only), `hlsl/`, `spv/`, `ref/` (XenosRecomp, UnleashedRecomp, ReXGlue shallow clones), `boundary_game.json` |
