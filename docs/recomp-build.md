# Native build by static recompilation (RC2)

RC2, 2026-11-14. This follows [recomp-feasibility.md](recomp-feasibility.md) (RC1). Stage 1 closes the
translation gaps. Stage 2 boots the game natively on Linux.

Rules followed:

- Nothing generated, translated or extracted is in the repo. Generated C++, objects, binaries, logs and
  captured frames live under `work/recomp/` (git-ignored).
- `src/`, `config/` and `tools/matching.py` were not touched.
- Third-party code is fetched at a pinned commit and patched from `tools/recomp/patches/`. It is never
  vendored.

## 1. Where it stands

**Milestone reached: Swing_DLL is in its main loop, drawing its 3D front-end scene, driven by a scripted
pad with no human and no X server.** The menus are not yet visible (section 6, item 1).

| Milestone | Status | Evidence (`work/recomp/rc2/…`) |
|---|---|---|
| Zero unhandled translation sites (XenonRecomp, all 3 modules) | done | §3 |
| All 3 modules compile and link (XenonRecomp output) | done | §3 |
| Loader runs and loads Swing | done | `logs/imports_h3/imports_at___imp__XexLoadImage.tsv` |
| Loader screens: legal, 2K logo, attract movie, Press START, Loading | done | `run/r7/shot_0010..0080.png`, `run/h3/frame_000660.png` |
| Swing start-up → main loop (game threads, profile, device selector, per-frame VdSwap) | done | `logs/imports_h3/imports_at___imp__NetDll_accept.tsv` |
| Swing issues draw calls; first Swing frame (3D scene: net, umpire chair) | done | `run/h3/frame_001200.png` (very dark: normalise to see it) |
| Swing front-end menus visible | **not yet** | §6, item 1 |
| Scripted pad input from a file | done | §5.2 |
| Headless frame capture, frame-rate log, guest-memory watch | done (the watch still needs ball and player offsets) | §5.3 |
| Exhibition match, serve and rally | not yet | §6 |

Frames are 1280×720 captures of the guest output image (`Presenter::CaptureGuestOutput`). They are taken
inside the process, not by screenshotting a window.

## 2. Reproduce from a clean checkout

Owner's files needed: `orig/54540859/disc_archive/Top Spin 4 (World) (En,Fr,De,Es,It).iso` plus the files
already used by the repo: `orig/54540859/disc/{default,Loader_DLL}.xex`, `disc/Loader_DLL.dll`,
`orig/54540859/Swing_DLL.{xex,dll}`. The default.xex basefile image `work/recomp/default/default.dll` comes
from RC1 (sha256 `efa8eff4…e90f`, 1,572,864 bytes, a mapped image). It is used only to generate the
XenonRecomp config for default.xex. The ReXGlue path reads the XEX directly.

Ubuntu 24.04 packages: `clang lld cmake ninja-build libvulkan-dev libx11-dev libx11-xcb-dev libxcb1-dev
libwayland-dev libgtk-3-dev mesa-vulkan-drivers imagemagick`. `gdb` is useful.

```sh
tools/recomp/setup_toolchain.sh work/recomp 2   # XenonRecomp ddd128b + ReXGlue 546a082, patched, built, SDK installed (~40 min)
tools/recomp/rexproj/build.sh 3                  # configs → ReXGlue codegen (2 passes) → build ts4 + 2 module .so (~30 min)
TS4_ISO=".../Top Spin 4 (World) (En,Fr,De,Es,It).iso" \
TS4_INPUT_SCRIPT=tools/recomp/rexproj/start_pulses.txt TS4_SHOT_EVERY=60 TS4_EXIT_AT_SWAP=6000 \
REX_DRAW_EVERY=30 tools/recomp/rexproj/headless.sh work/recomp/rc2/run/h3 600
```

Stage-1 cross-check, which is not needed to run the game:

```sh
tools/recomp/run_ppc_tests.sh work/recomp/XenonRecomp work/recomp/ref/rexglue-sdk work/recomp/rc2/ppctests
cd work/recomp/rc2/swing && ../../XenonRecomp/build/XenonRecomp/XenonRecomp Swing.toml ../../XenonRecomp/XenonUtils/ppc_context.h
tools/recomp/build_xenon.sh work/recomp/rc2/swing work/recomp/XenonRecomp 2   # compile + link check
python3 -m unittest tests.test_recomp_config
```

Tool versions: clang 18.1.3, cmake 3.28.3, ninja 1.11.1, Python 3.13, Mesa lavapipe 25.2.8 (llvmpipe, LLVM
20.1.2, Vulkan 1.4.318), ReXGlue v0.10.1 (`546a082`), XenonRecomp `ddd128b`.

## 3. Stage 1: translation (patched XenonRecomp)

Patch: `tools/recomp/patches/xenonrecomp/0001-rc2-translation-gaps.patch` (sha256 `cf228f28…0ece50c`).

- **New instruction forms.**
  - Integer: `eqv addc addme subfze subfme mulhd mulhdu`.
  - CR logic: all CR-logic ops, plus `mtcrf mtocrf`; `mfocrf` now decodes FXM correctly; `mfctr`.
  - Loads and stores: every update-form load/store; `lhbrx`; `dcbst/dcbi/icbi` as no-ops; `frsqrte`.
  - CTR branches: all conditional forms (`bdz[f|t] bdnz[f|t] bdnzlr`).
  - VMX: `vcmpbfp(128)(.)` (NaN-correct), record forms of `vcmpgtub/uh`, `vsel128`, `lvebx/lvehx`,
    `vaddsws`, halfword and byte shifts and rotates, `vspltish`, the saturating and modulo packs (+128
    forms), `vctuxs`, `vcfpuxws128`.
  - `vpkd3d128` for all types 0-5 and pack/shift combinations, using Xenia's permute table.
    `vupkd3d128` for types 0-5.
- **Cross-function jumps.** A branch into the middle of another function becomes a tail call to an
  "alternate entry". That is a copy of the container that starts with `goto loc_T` (Swing has 17, Loader
  9). Out-of-function switch cases also become tail calls.
- **Fail loudly.** Every untranslatable site emits `__builtin_trap()`, is counted by kind, and makes
  XenonRecomp exit with status 2.
- **Function sets.**
  - `tools/recomp_config.py config --pdata --discover` adds `.pdata` entries and discovered leaf
    functions (call targets, data words, `lis/addi` pairs, gap sweep).
  - It detects mapped images (this fixed RC1's default.dll, where 237 bogus merges came from wrong
    helper addresses).
  - It adds `clrlwi`-masked switch tables.
  - Tests: `tests/test_recomp_config.py` (16 tests, synthetic code).

Semantics checks:

- ReXGlue's PPC corpus (`tests/ppc/asm`) plus our `tools/recomp/tests/rc2_forms.s`, assembled with
  ReXGlue's binutils and run through `run_ppc_tests.sh`: **5,459 checks, 0 failing**.
- Corpus forms still unhandled, none of which occur in the game: `tw*/td*`, `rlwnm`, `vsl`, `vslo`, `vsro`,
  `vandc`.

| Module | Functions emitted | Alternate entries | Errors | Translate | Compile + link (clang -O1, 2 jobs) | x86 text |
|---|---:|---:|---:|---:|---:|---:|
| Swing_DLL | 46,792 | 17 | 0 | 5.5 s | 1,040 s, 248 import stubs | 41,062,295 B |
| Loader_DLL | 17,303 | 9 (2 impossible switch cases trap) | 0 | 2.9 s | 311 s, 328 import stubs | 19,714,025 B |
| default.xex | 457 | 0 | 0 | <1 s | links, 107 import stubs | 421,076 B |

Function sources: Loader has 9,686 from symbols, 5,838 from `.pdata` and 1,835 discovered; default has
334 from `.pdata` and 191 discovered.

The remaining log lines are information only:

- 8 "Unable to decode" words each at Loader 0x83517E0C and Swing 0x88B00784. These are the XEX `.text`
  trailer.
- default has no fpr/vmx helpers.

## 4. Stage 2: runtime (ReXGlue)

ReXGlue (BSD-3, derived from Xenia) supplies the codegen, kernel/XAM HLE, the Xenos GPU (Vulkan) and audio.
XenonRecomp stays as the cross-check translator. A one-module stub harness would have had to solve
cross-module indirect calls, which ReXGlue already does: one module per shared library and a shared
dispatcher.

**Codegen inputs** (`tools/recomp/rexproj/build.sh`, `tools/recomp/to_rexglue.py`):

- ReXGlue's own analysis (pdata, vtables, gap fill) is used, with two hint passes.
  - Pass 1 adds 4 Loader and 4 Swing boundaries that it gets wrong. Without them, validation fails with
    "target not in any function".
  - Pass 2 adds every function start in our config that ReXGlue lacks (Loader 327, Swing 217, default
    12), unsized. These include indirect-call targets such as Loader 0x833F9780: without it the game hit
    `FATAL: call to unregistered function`.
- 23 Loader entries are excluded. Splitting at them would cut loops: they have no data references and are
  reached only from inside their container. `tools/recomp/check_labels.py` reports 0 undeclared gotos.
- Result: 0 unresolved branches and 0 `REX_FATAL` sites.
  - Registered functions: default 564, Loader 17,676, Swing 47,212.
  - 614 switch tables, all found by ReXGlue's analysis.
- **setjmp/longjmp.**
  - Swing: 0x8856B7F0 / 0x88569D30 (from RC1).
  - Loader: **0x8346A940 / 0x8346A510**, found by matching Swing's CRT bodies. libjpeg's error path
    longjmps. Without these, the Press Start screen crashed in `jpeg_read_markers` with `r31 = 0`.

**ReXGlue patches** (`tools/recomp/patches/rexglue/`):

| Patch | Why |
|---|---|
| 0001 std-expected | libstdc++ 13 hides `std::expected` from clang 18 (`__cpp_concepts`). |
| 0002 import-call-counters | Every `REX_HOOK`/`REX_STUB` counts its calls. Adds first-call log lines (`[import-first]`), snapshots when a chosen import is first called (`REX_IMPORT_SNAPSHOT_ON`), and `GetImportCount`. The 11 `REX_HOOK_RAW` imports (DbgPrint, sprintf family) are not counted. |
| 0003 posix winsock | `ioctlsocket(FIONBIO)` was passed straight to Linux `ioctl`, so Swing's listen socket stayed blocking and `accept()` hung the main thread for good. Now FIONBIO/FIONREAD are translated, and a failed accept sets WSAEWOULDBLOCK. |
| 0004 gpu ring re-init + draw-every | (a) The Loader calls `VdShutdownEngines` and Swing calls `VdInitializeRingBuffer` again. The command processor now resets the read and write indices on its own thread; before, it executed the old write index against the new buffer, giving "PM4 overflow" errors and garbage draws. (b) `REX_DRAW_EVERY=N` (§5.4). |

**Host app** (`tools/recomp/rexproj/src/`, copied into the generated project):

- Mounts the ISO with ReXGlue's `DiscImageDevice` and repoints `game:`/`d:` at it after default.xex has
  loaded from `work/recomp/rc2/rex/game` (hard links to the three XEXs).
- Scripted input, frame capture, memory watch, import dumps, frame-rate log, exit-at-frame (§5).

**Runtime environment that matters:**

- `SDL_VIDEODRIVER=offscreen`. Under Xvfb, lavapipe's X11 swapchain deadlocked with the GPU worker
  (`VulkanDevice::AcquireQueue`) as soon as Swing started presenting.
- `SDL_AUDIO_DRIVER=dummy`. With no audio device, XAudio voices never drain, and the Loader waits forever
  in `IXAudio2SourceVoice::GetState` (`sub_83220810`) after the 2K logo.
- `--async_shader_compilation=false`. Otherwise every frame is skipped as "async placeholder draw".
- ReXGlue `dlopen()`s modules by bare target name on Linux. `build.sh` adds `build/ts4_Loader_DLL` and
  `build/ts4_Swing_DLL` symlinks, plus the GPU plugin symlink.

**Import calls per milestone.** Headless run h3, from boot to Swing frame 6000. The full tables are in
`work/recomp/rc2/logs/imports_h3/` (call count, name).

| Snapshot (first call of) | t | Distinct imports called so far |
|---|---:|---:|
| `XexLoadImage` (default.xex loads the Loader) | 1.26 s | 29 |
| `VdSwap` (first Loader frame) | 1.36 s | 61 |
| `XexUnloadImage` (Loader hands over to Swing) | 10.5 s | 116 |
| `NetDll_accept` (Swing main loop polling) | 13.0 s | 133 |
| `XamShowDeviceSelectorUI` (Swing storage prompt, auto-answered) | 19.9 s | 136 |
| end of run (6,000 swaps) | 106.6 s | 139 |

Most-called imports at the end: RtlEnter/LeaveCriticalSection (9.1 M each), KeTlsGetValue (5.1 M),
KeQueryPerformanceFrequency (226 k), KeDelayExecutionThread (92 k), XNotifyGetNext (49 k),
XAudioSubmitRenderDriverFrame (23 k), XamInputGetState (22 k).

Stubs hit, from the log:

- `XNetLogonGetTitleID` (STUB);
- `IoDismountVolumeByFileHandle` (stub);
- `NtQueryVolumeInformationFile(XFileFsDeviceInformation)` (stub);
- the VFS has no `cache:` device, so `cache:\User.txt` fails. This is deliberate in ReXGlue.

## 5. Running headless

### 5.1 Runner

`tools/recomp/rexproj/headless.sh OUTDIR MAX_SECONDS [ts4 args]` needs `TS4_ISO`. It writes into OUTDIR:

- `ts4.log`;
- `imports_latest.tsv` and `imports_at_*.tsv`;
- `frames.csv` (wall ms, swap count, once a second);
- `frame_<swap>.png`;
- `watch.csv`.

### 5.2 Scripted pad (`TS4_INPUT_SCRIPT`)

The script replaces the SDL and keyboard drivers with one pad on user 0 (`src/ts4_script.h`). Each line is
a state held until the next line:

```
<frame> <buttons> [lt=N rt=N lx=N ly=N rx=N ry=N]
```

- `frame` is the guest `VdSwap` count, so a script replays the same way however fast the host runs.
  `+N` means N frames after the previous line.
- `buttons` is `-` or names joined by `+`: `A B X Y START BACK UP DOWN LEFT RIGHT LB RB LS RS`.
- Button edges are also delivered as `XamInputGetKeystroke(Ex)` events (VK_PAD_*). The Loader skips its
  movies on keystrokes but reads Press Start from `XamInputGetState`.

`tools/recomp/rexproj/start_pulses.txt` (START for 8 frames every 100 frames) gets from boot through Press
Start and into Swing in about 1,100 frames.

### 5.3 Capture and state log

- `TS4_SHOT_EVERY=n` writes a frame every n swaps.
- `TS4_EXIT_AT_SWAP=n` ends the run.
- ffmpeg is not installed here. To make a video, run
  `ffmpeg -framerate 2 -pattern_type glob -i 'frame_*.png' run.mp4` wherever it is available.
- `TS4_WATCH=file` logs one CSV row per swap.
  - Each line is `name type expr`, with `type` one of `u8 u16 u32 s32 f32 f32x3`.
  - `expr` is `0xADDR`, `[expr]+0xOFF` or `[expr]-0xOFF`, where `[…]` dereferences a big-endian
    pointer.
  - Pointers outside 0x40000000-0xFFFF0000 give empty fields.
  - `tools/recomp/rexproj/watch_basic.txt` has the engine frame counter, the engine state and scene hash,
    and the match-instance pointer and its frame counters (from gameplay/gp0.md).
  - **Open:** offsets from the match instance to the ball (position, speed) and to the players (position,
    PlayerState timing/power, shot outcome). They are documented relative to `ball`/`state`/`world`, but
    the chain from `[[0x88D45B00]+0x78]` to those objects has not been written down. Once it is, the
    values only need adding to the watch file.

### 5.4 Speed

Host: 4 cores shared with other agents (load average about 9).

| Phase | Full render (lavapipe) | `REX_DRAW_EVERY=30` |
|---|---:|---:|
| Loader (logos, movie, Press Start) | about 16 swaps/s | about 57 swaps/s |
| Swing front end | **about 1 swap/s** | about 57 swaps/s |

In Swing, the CPU sits in the D3D GPU-fence wait (`sub_88292698`, spinning on the read pointer) while
llvmpipe renders. The software renderer is the bottleneck.

With `REX_DRAW_EVERY=N`, every PM4 packet still executes (register writes, fences, interrupts, swaps), but
only every Nth frame's draws, resolves and presentation run. The title therefore runs at simulation speed
and still gives a real frame every N swaps. A null renderer would be the same switch with N = ∞.

**Caveat (open):** with N = 30, Swing's captures go fully black after about 200 Swing frames (frame 1380
onward in h3), while the simulation keeps running. One likely cause is that resolves or render-to-texture
UI layers only update on a skipped frame. A full-render run (`run/h4`) was started to tell this apart from
a front-end rendering fault. Its result is in §7.

## 6. Next blockers, in order

1. **Swing front-end frames.** Find out why captures turn black after the first Swing frames: frame
   skipping versus a real rendering fault (§5.4, §7). Possible fixes:
   - render K consecutive frames before each capture instead of one;
   - never skip resolves (`IssueCopy`).

   The 3D scene in `frame_001200.png` is very dark, which suggests missing textures or lighting.
2. **Menu navigation script.** With frames visible, write the Press Start → main menu → exhibition →
   player/venue select → match script. The START-pulse script already reaches Swing and answers the
   device selector.
3. **Game-state watch.** Ball and player offsets from the match instance (§5.3).
4. **Match:** a serve and a rally, AI against AI if the exhibition menu allows it.
5. **Smaller items:**
   - the Loader's `XamInputGetState` Press Start needs the pad state on user 0, which the script driver
     provides;
   - `cache:` device;
   - ffmpeg for videos.

## 7. Files

New tools (standard library or shell):

- `tools/recomp/setup_toolchain.sh`
- `tools/recomp/patches/{xenonrecomp,rexglue}/*.patch`
- `tools/recomp/run_ppc_tests.sh`
- `tools/recomp/tests/rc2_forms.s`
- `tools/recomp/build_xenon.sh`
- `tools/recomp/to_rexglue.py`
- `tools/recomp/check_labels.py`
- `tools/recomp/rexproj/{build.sh,headless.sh,start_pulses.txt,watch_basic.txt,CMakeLists.txt,ts4_manifest.toml,src/*}`

Changed:

- `tools/recomp_config.py` (pdata, discovery, mapped images, mask switches)
- `tests/test_recomp_config.py`

Work tree (not in git):

- `work/recomp/rc2/{default,loader,swing}`: XenonRecomp configs and output.
- `work/recomp/rc2/rex`: the ReXGlue project; `build/ts4` is the game.
- `work/recomp/rc2/run`: runs and frames.
- `work/recomp/rc2/logs`: import tables.
