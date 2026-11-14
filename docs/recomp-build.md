# Native build by static recompilation (RC2)

RC2, 2026-11-14. This follows [recomp-feasibility.md](recomp-feasibility.md) (RC1).

- Stage 1 closes the translation gaps.
- Stage 2 boots the game natively on Linux, headless, driven by a script.

Related analyses:

- [renderer-map.md](renderer-map.md): how the game renders, and the black-frame checks C1-C9.
- [frontend-map.md](frontend-map.md): the front-end flow, its waits, the menu path to a match, and the
  pointer chains.

Rules followed:

- Nothing generated, translated or extracted is in the repo. Generated C++, objects, binaries, logs and
  captured frames live under `work/recomp/` (git-ignored).
- `src/`, `config/` and `tools/matching.py` were not touched.
- Third-party code is fetched at a pinned commit and patched from `tools/recomp/patches/`. It is never
  vendored.

## 1. Where it stands

**Milestone reached: a headless, scripted run boots default.xex → Loader → Swing, reaches the practice
ground (live gameplay instance, player moving) and opens the main menu.** Frames render correctly with
`--render_target_path_vulkan=fsi` (§4.3). The menus beyond the main menu, a match, and a serve or rally
have not been driven yet (§6).

| Milestone | Status | Evidence (`work/recomp/rc2/run/…`) |
|---|---|---|
| Zero unhandled translation sites (XenonRecomp, all 3 modules); all 3 compile and link | done | §3 |
| Loader runs: legal, 2K logo, attract movie, Press START, Loading | done | `r7/shot_00*.png`, `h4/frame_000480.png` |
| Loader hands over to Swing; Swing main loop (threads, profile, device selector) | done | `h3`, import tables in `../logs/imports_h3/` |
| Swing frames render (practice ground: court, player, net, ball machine, HUD) | **done** | `f2/frame_001500.png` (sha256 `a8d82759…`) |
| Main menu (scene `S4MainMenu`) reached by script | **done** | `f2/frame_002500.png` (sha256 `d9311320…`), `f2/script.csv`, `f2/watch.csv` |
| Scripted pad from a file, gated on game state (`wait`/`idle` lines) | done | §5.2, `tools/recomp/rexproj/nav_pg.txt` |
| Per-swap game-state log (ball, players, timing, power, outcome, scene name) | done; the ball and player chains read live values on the practice ground | §5.3, `f2/watch.csv` |
| Main menu → exhibition → player and venue select → match | not yet | §6 |
| Serve and rally | not yet | §6 |

Frames are 1280×720 captures of the guest output image (`Presenter::CaptureGuestOutput`), taken inside the
process.

## 2. Recipe from a clean checkout

### 2.1 What you need

The owner's files, under `orig/54540859/`, are never committed:

| File | Used for |
|---|---|
| `disc_archive/Top Spin 4 (World) (En,Fr,De,Es,It).iso` | mounted at run time (`TS4_ISO`) |
| `disc/default.xex`, `disc/Loader_DLL.xex`, `Swing_DLL.xex` | codegen input, and the game root at run time |
| `disc/Loader_DLL.dll`, `Swing_DLL.dll` | basefile images, for the XenonRecomp configs |

`work/recomp/default/default.dll` is the default.xex basefile image from RC1 (sha256 `efa8eff4…e90f`,
1,572,864 bytes, a mapped image). It is used only to generate the XenonRecomp config for default.xex;
ReXGlue reads the XEX itself. If it is missing, extract it from default.xex as RC1 did
([recomp-feasibility.md](recomp-feasibility.md)).

**Linux (tested: Ubuntu 24.04, x86-64).**

- Packages: `git cmake ninja-build clang lld python3 libvulkan-dev libx11-dev libx11-xcb-dev libxcb1-dev
  libwayland-dev libgtk-3-dev mesa-vulkan-drivers imagemagick`, plus `gdb` (useful) and `ffmpeg` (for
  videos; not installed here).
- Versions used: clang 18.1.3, cmake 3.28.3, ninja 1.11.1, Python 3.13, Mesa lavapipe 25.2.8 (llvmpipe,
  LLVM 20.1.2, Vulkan 1.4.318).
- Pinned third-party code: XenonRecomp `ddd128b`, ReXGlue SDK v0.10.1 (`546a082`).
- Disk: about 3 GB under `work/recomp` (toolchain builds about 1.5 GB, generated project about 0.6 GB plus
  objects).

**Windows (untested here).**

- ReXGlue supports Windows: it has a D3D12 backend and a Vulkan one. Our scripts are bash, so run them
  under Git Bash or MSYS2 with clang-cl/ninja, or port the few commands by hand.
- Linux-only details to adapt:
  - `build.sh` creates symlinks `build/ts4_Loader_DLL` and `build/ts4_Swing_DLL` because ReXGlue
    `dlopen()`s modules by bare target name on Linux. On Windows the loader finds the `.dll` names
    directly, so drop the symlinks.
  - The socket patch (0003) only touches the POSIX socket file. On Windows Winsock ioctls are native.
  - `headless.sh` uses `timeout` and the SDL offscreen/dummy drivers. On Windows run `ts4.exe` with the
    same arguments and environment variables.

### 2.2 Steps and how long they took here

The host has 4 cores, shared with other agents (load average about 9).

```sh
# 1. Recompiler + runtime: clone at the pinned commits, apply tools/recomp/patches/*, build,
#    install the ReXGlue SDK into work/recomp/rexsdk.                       (~40 min, 2-3 jobs)
tools/recomp/setup_toolchain.sh work/recomp 3

# 2. Game project: XenonRecomp-format configs (tools/recomp_config.py), ReXGlue codegen in two
#    hint passes (tools/recomp/to_rexglue.py), checks (no unresolved branches, no undeclared
#    labels, no REX_FATAL), then cmake/ninja: ts4 + libts4_Loader_DLL.so + libts4_Swing_DLL.so.
#    Generated code goes to work/recomp/rc2/rex/generated.                (~30 min, 3 jobs)
tools/recomp/rexproj/build.sh 3

# 3. Run headless to the main menu.                                       (~3 min with lavapipe)
TS4_ISO="$PWD/orig/54540859/disc_archive/Top Spin 4 (World) (En,Fr,De,Es,It).iso" \
TS4_INPUT_SCRIPT=$PWD/tools/recomp/rexproj/nav_pg.txt \
TS4_SCRIPT_LOG=$PWD/work/recomp/rc2/run/f2/script.csv \
TS4_WATCH=$PWD/tools/recomp/rexproj/watch_match.txt \
TS4_SHOT_EVERY=50 TS4_EXIT_AT_SWAP=3200 REX_DRAW_EVERY=10 \
tools/recomp/rexproj/headless.sh work/recomp/rc2/run/f2 420
```

| Step | Time here |
|---|---|
| ReXGlue full build (`ninja -j3`) | 1,361 s |
| XenonRecomp build | about 3 min |
| Codegen (both passes) | about 2 min |
| Game project compile and link, clang -O1, 3 jobs | about 25 min (Swing is the long pole: 260 MB of generated C++) |
| Rebuild only the host app (`ninja -C work/recomp/rc2/rex/build ts4`) after editing `src/*.h` | about 3 min |
| Rebuild only the GPU plugin (`ninja -C work/recomp/rexbuild rexgpu-xenos`, then `cmake --install work/recomp/rexbuild`) | about 4 min |

`build.sh` copies `tools/recomp/rexproj/src/*.h`, `main.cpp`, `CMakeLists.txt` and `ts4_manifest.toml`
into `work/recomp/rc2/rex/`. When you edit the host app, edit the repo copy and copy it over, or re-run
`build.sh`: it skips codegen pass 1 when `config/*_register_v1.cpp` already exist.

Stage-1 cross-check (not needed to run the game):

```sh
tools/recomp/run_ppc_tests.sh work/recomp/XenonRecomp work/recomp/ref/rexglue-sdk work/recomp/rc2/ppctests
cd work/recomp/rc2/swing && ../../XenonRecomp/build/XenonRecomp/XenonRecomp Swing.toml ../../XenonRecomp/XenonUtils/ppc_context.h
tools/recomp/build_xenon.sh work/recomp/rc2/swing work/recomp/XenonRecomp 2   # compile + link check
python3 -m unittest tests.test_recomp_config tests.test_untile_xenos         # 19 tests
```

## 3. Stage 1: translation (patched XenonRecomp)

Patch: `tools/recomp/patches/xenonrecomp/0001-rc2-translation-gaps.patch` (sha256 `cf228f28…0ece50c`).

- **New instruction forms.**
  - Integer: `eqv addc addme subfze subfme mulhd mulhdu`.
  - CR logic: all CR-logic ops, plus `mtcrf mtocrf`; `mfocrf` now decodes FXM correctly; `mfctr`.
  - Loads and stores: every update-form load/store; `lhbrx`; `dcbst/dcbi/icbi` as no-ops; `frsqrte`.
  - CTR branches: all conditional forms.
  - VMX: `vcmpbfp(128)(.)` (NaN-correct), record forms of `vcmpgtub/uh`, `vsel128`, `lvebx/lvehx`,
    `vaddsws`, halfword and byte shifts and rotates, `vspltish`, saturating and modulo packs (+128 forms),
    `vctuxs`, `vcfpuxws128`.
  - `vpkd3d128` and `vupkd3d128` for types 0-5, using Xenia's permute table.
- **Cross-function jumps.** A branch into the middle of another function becomes a tail call to an
  "alternate entry", a copy of the container that starts with `goto loc_T` (Swing has 17, Loader 9).
  Out-of-function switch cases also become tail calls.
- **Fail loudly.** Every untranslatable site emits `__builtin_trap()`, is counted by kind, and makes
  XenonRecomp exit with status 2.
- **Function sets.** `tools/recomp_config.py config --pdata --discover` adds `.pdata` entries, discovered
  functions, mapped-image detection and `clrlwi`-masked switch tables (`tests/test_recomp_config.py`, 16
  tests).

Semantics: ReXGlue's PPC corpus plus `tools/recomp/tests/rc2_forms.s`, run through `run_ppc_tests.sh`:
**5,459 checks, 0 failing**.

| Module | Functions emitted | Alternate entries | Errors | Compile + link (clang -O1, 2 jobs) | x86 text |
|---|---:|---:|---:|---:|---:|
| Swing_DLL | 46,792 | 17 | 0 | 1,040 s | 41,062,295 B |
| Loader_DLL | 17,303 | 9 | 0 | 311 s | 19,714,025 B |
| default.xex | 457 | 0 | 0 | links | 421,076 B |

## 4. Stage 2: runtime (ReXGlue)

ReXGlue (BSD-3, derived from Xenia) supplies the codegen, kernel/XAM HLE, the Xenos GPU (Vulkan) and audio.
Each module is one shared library; they share a dispatcher.

### 4.1 Codegen inputs (`tools/recomp/rexproj/build.sh`, `tools/recomp/to_rexglue.py`)

- **Pass 1** adds the boundaries ReXGlue gets wrong: Loader 83184210, 83185C20, 83187050, 8317F628; Swing
  883F1E88, 883D8A08, 883F1FA0, 88660D10.
- **Pass 2** adds every function start our config has that ReXGlue lacks (Loader 327, Swing 217, default
  12), unsized, minus 23 Loader split points that would cut loops (`LOADER_EXCL` in `build.sh`).
- **setjmp/longjmp:** Swing 0x8856B7F0 / 0x88569D30; Loader 0x8346A940 / 0x8346A510. Without the Loader
  pair, libjpeg's error path crashes the Press Start screen.
- Result: 0 unresolved branches, 0 undeclared labels (`tools/recomp/check_labels.py`), 0 `REX_FATAL`.
  Registered functions: default 564, Loader 17,676, Swing 47,212.

### 4.2 ReXGlue patches (`tools/recomp/patches/rexglue/`)

All five apply in order to a clean `546a082` (checked with `git apply --check` in a fresh worktree).

| Patch | sha256 | What and why |
|---|---|---|
| 0001 std-expected | `e71d5f1d…` | libstdc++ 13 hides `std::expected` from clang 18. |
| 0002 import-call-counters | `80c2e32f…` | Every `REX_HOOK`/`REX_STUB` counts its calls. Adds `[import-first]` log lines, snapshots on chosen imports (`REX_IMPORT_SNAPSHOT_ON`), and `GetImportCount` (the frame clock = VdSwap count). |
| 0003 posix winsock | `339b8b8a…` | Translates `ioctlsocket(FIONBIO/FIONREAD)`; a failed accept sets WSAEWOULDBLOCK. Without it, Swing's main thread blocks for good in `accept()`. |
| 0004 gpu ring re-init + draw-every + debug | `ec45b85a…` | (a) Resets the command-processor read and write indices on its own thread when Swing re-initialises the ring buffer (before: PM4 overflow, garbage draws). (b) `REX_DRAW_EVERY` / `REX_DRAW_WINDOW` frame skipping, keyed on swap packets (§5.4). (c) Debug: `REX_FRAME_TRACE`, `REX_SKIP_DRAWS` (§5.5). |
| 0005 gpu debug gamma/swap log | `0daff80d…` | Debug: `REX_GAMMA_LOG`, `REX_PWL_SWAP`, `REX_SWAP_LOG` (§5.5). No effect unless set. |

### 4.3 Runtime settings that matter

| Setting | Why |
|---|---|
| `--render_target_path_vulkan=fsi` (headless.sh default; `TS4_RT_PATH` overrides) | **Without it, every Swing frame is black** (§6.1). The FSI path emulates EDRAM in a storage buffer with fragment-shader interlock. Lavapipe supports it (`fragmentShaderSampleInterlock = true`). |
| `--gpu_plugin=xenos` | the Vulkan Xenos backend |
| `--async_shader_compilation=false` | Otherwise every frame is skipped as "async placeholder draw" (lavapipe compiles slowly). |
| `SDL_VIDEODRIVER=offscreen` | Under Xvfb, lavapipe's X11 swapchain deadlocked with the GPU worker as soon as Swing presented. |
| `SDL_AUDIO_DRIVER=dummy` | With no audio device, XAudio voices never drain and the Loader waits forever after the 2K logo. |
| `VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json` | forces lavapipe |
| `TS4_ISO` | The host app mounts the ISO with `DiscImageDevice` at `\Device\Cdrom0` and repoints `game:` and `d:` at it once default.xex has loaded from `work/recomp/rc2/rex/game` (hard links to the three XEXs). |

**On a machine with a real GPU:**

- Drop `VK_ICD_FILENAMES`, and drop `SDL_VIDEODRIVER=offscreen` if you want a window.
- Async shader compilation can stay off; it costs little on a real driver.
- Try the default render-target path again (`TS4_RT_PATH=`). The black frames may be a lavapipe issue in
  Xenia's host-render-target ownership transfers. FSI is slower on most real GPUs and is not supported
  on all of them, but it is the accurate path.
- `REX_DRAW_EVERY` should become unnecessary.
- Keep `SDL_AUDIO_DRIVER=dummy` on a box with no sound device.

### 4.4 Import calls per milestone (run h3, boot to Swing frame 6000)

| Snapshot (first call of) | t | Distinct imports so far |
|---|---:|---:|
| `XexLoadImage` (default.xex loads the Loader) | 1.26 s | 29 |
| `VdSwap` (first Loader frame) | 1.36 s | 61 |
| `XexUnloadImage` (Loader hands over to Swing) | 10.5 s | 116 |
| `NetDll_accept` (Swing main loop) | 13.0 s | 133 |
| `XamShowDeviceSelectorUI` (auto-answered) | 19.9 s | 136 |
| end of run | 106.6 s | 139 |

Full tables: `work/recomp/rc2/logs/imports_h3/`.

Stubs hit:

- `XNetLogonGetTitleID`;
- `IoDismountVolumeByFileHandle`;
- `NtQueryVolumeInformationFile(XFileFsDeviceInformation)`;
- no `cache:` device (`cache:\User.txt` fails, by ReXGlue's design).

Expected file-open failures: `d:\Media\UI\Rui\*.arc`, `game:\Media\XUI\eng\*.xzp`. The game probes loose
files first and then uses the archives.

## 5. Running headless

### 5.1 Runner

```
tools/recomp/rexproj/headless.sh OUTDIR MAX_SECONDS [extra ts4 args]
```

- Needs `TS4_ISO`. `TS4_WORK` defaults to `<repo>/work/recomp`.
- Kills the game after MAX_SECONDS, then converts the PPM captures to PNG.
- Writes into OUTDIR:

| File | Contents |
|---|---|
| `ts4.log` | runtime log |
| `stdout.log` | runtime stdout |
| `frames.csv` | wall-clock ms and swap count, once a second (frame rate) |
| `frame_<swap>.png` | captures |
| `watch.csv` | memory watch, one row per swap |
| `imports_latest.tsv`, `imports_at_<import>.tsv` | import call counts |
| script log | if `TS4_SCRIPT_LOG` is set |

### 5.2 Every environment variable we added

**Host app** (`tools/recomp/rexproj/src/ts4_app.h`, `ts4_script.h`):

| Variable | Meaning |
|---|---|
| `TS4_ISO=path` | disc image to mount |
| `TS4_INPUT_SCRIPT=file` | scripted pad on user 0. Replaces the SDL and keyboard drivers. Format below. |
| `TS4_SCRIPT_LOG=file.csv` | the swap at which each `wait`/`idle` line cleared or timed out |
| `TS4_SHOT_DIR=dir` | capture directory (headless.sh sets OUTDIR) |
| `TS4_SHOT_EVERY=n` | capture every n swaps (default 30) |
| `TS4_SHOT_RETRY_MS=ms` | retry an all-black capture for this long (default 1500; set 0 for speed) |
| `TS4_WATCH=file` | guest-memory values to log each swap. Format below. |
| `TS4_WATCH_OUT=file.csv` | watch output (default `<TS4_SHOT_DIR>/watch.csv`) |
| `TS4_FRAME_LOG=file.csv` | swap count once a second (headless.sh sets `OUTDIR/frames.csv`) |
| `TS4_EXIT_AT_SWAP=n` | hard exit after n VdSwap calls |
| `TS4_DUMP_PHYS=addr:size` | dump a guest physical range next to each capture (`phys_<swap>.bin`). Untile with `tools/recomp/untile_xenos.py`. Only meaningful with `--readback_resolve=full --vulkan_readback_resolve=true`. |
| `REX_IMPORT_TRACE_DIR=dir` | import counts to `dir/imports_latest.tsv` every 2 s (headless.sh sets it) |
| `REX_IMPORT_SNAPSHOT_ON=a,b` | snapshot the import table when each named import is first called |

**GPU plugin** (patches 0004 and 0005):

| Variable | Meaning |
|---|---|
| `REX_DRAW_EVERY=N` | draw and present only the last `REX_DRAW_WINDOW` (default 1) of every N swaps. All other PM4 packets still execute. |
| `REX_DRAW_WINDOW=K` | see the line above |
| `REX_FRAME_TRACE=FIRST:COUNT` | log every draw, copy and swap in that swap range: prim, count, EDRAM mode, surface/colour/depth info, colour mask, blend, depth control, copy registers |
| `REX_SKIP_DRAWS=A:B` | skip draw packets A..B (1-based) of every frame from swap `REX_SKIP_DRAWS_FROM` (default 600). Used for bisection. |
| `REX_GAMMA_LOG=1` | log the gamma ramp kind and entries on each upload |
| `REX_PWL_SWAP=1` | force the PWL base/delta swap |
| `REX_SWAP_LOG=1` | log the swap source (address, size, format) when it changes |

**Input script format.** One line per state, held until the next line. `#` starts a comment.

```
<frame|+N> <buttons> [lt=0..255 rt=.. lx=-32768..32767 ly=.. rx=.. ry=..]
wait <u8|u16|u32|s32|f32|str> <expr> <== != < > <= >=> <value> [max=N]
idle <ImportName> <N> [max=N]
```

- `frame` is the guest VdSwap count. `+N` means N swaps after the previous line or after the swap at
  which the previous `wait`/`idle` cleared.
- Buttons: `-`, or names joined by `+`: `A B X Y START BACK UP DOWN LEFT RIGHT LB RB LS RS`. Edges are also
  delivered as `XamInputGetKeystroke(Ex)` events.
- `wait` blocks until a guest-memory condition holds. `str` compares a C string, for example the scene
  name.
- `idle` blocks until an import counter has not changed for N swaps. `idle NtReadFile 150` means file
  loading has stopped.
- `max=N` gives up after N swaps, logs it, and carries on.

Scripts in the repo:

- `nav_pg.txt`: boot → practice ground → main menu.
- `start_pulses.txt`: old timing-only START pulses.

**Watch format.** One line per value: `name type expr`.

- `type` is one of `u8 u16 u32 s32 f32 f32x3 str`.
- `expr` is `0xADDR | [expr]+0xOFF | [expr]-0xOFF`, where `[…]` dereferences a big-endian pointer.
  Pointers outside 0x40000000-0xFFFF0000 give empty cells.

Watch files in the repo:

- `watch_basic.txt`: engine state and frame, scene name, gameplay instance.
- `watch_match.txt`, with these chains from frontend-map.md:
  - `inst0 = [[[0x88D45B00]+0x78]]`;
  - frame counter at `[inst0+0x30]+0x310`;
  - ball `[[inst0+0x5C]+0x20]`: +0x40 position, +0x4F0 velocity, +0x520 speed, +0x43C new-shot flag;
  - players `S = [[inst0+0x04]+4i]+0x74`: +0x8E0 position, +0xD08 TimingValue, +0x544 committed timing,
    +0xE00 power, +0x714 outcome hash;
  - scene name `[[[[[0x88D45A60]+0x1B0]+0x6C]+0x50]+0x60]`.

On the practice ground, `p0_pos` reads (-1252, 0, z) cm with z changing, and the ball is parked at 100000
while it is inactive.

**Video.** ffmpeg is not installed here. To make one:

```
ffmpeg -framerate 6 -pattern_type glob -i 'frame_*.png' run.mp4
```

### 5.3 Speed (lavapipe, 4 shared cores)

| Phase | Full render | `REX_DRAW_EVERY=10`, FSI |
|---|---:|---:|
| Loader (logos, movie, Press START) | about 16 swaps/s | not measured separately |
| Swing practice ground and main menu | **about 1 swap/s** | about 16-19 swaps/s (f2: 3,190 swaps in 168 s from boot) |

- In Swing the CPU waits in the D3D GPU-fence wait (`sub_88292698`) while llvmpipe renders. The software
  renderer is the bottleneck.
- With the default host render-target path and `REX_DRAW_EVERY=30`, about 57 swaps/s were measured, but
  the frames were black.
- A null renderer is `REX_DRAW_EVERY` with a very large N. The simulation then runs at whatever the CPU
  side allows (about 57 swaps/s here, close to the guest's 60).

**Draw-skipping fix.** The first version keyed skipping on `counter_`. That counter also advances on every
host vblank (`GraphicsSystem::MarkVblank`), so a slow title frame spanned several values and the window
cut frames in half: the final copy ran while the scene draws had been skipped. It now counts swap packets
(`g_rc2_swaps`).

### 5.4 Debugging aids

- `gdb -p $(pgrep -x ts4) -batch -ex "thread apply all bt 30"` gives guest call stacks: the generated
  functions keep their `sub_XXXXXXXX` symbols.
- The main thread in Swing is `sub_889BCB10` (main loop) → … → `sub_8875EB68` (Present) → `sub_88295D00`
  (Swap) → `sub_88292698` (fence wait).

## 6. State for the hand-over

### 6.1 Black Swing frames: solved, and how

**Symptom.** With the default Vulkan render-target path, every Swing frame captured fully black (all
zeros), at full render too. Exceptions were rare frames in draw-skip mode.

**Cause.** The host-render-target path.

- Swing reuses EDRAM base 0 for render targets of different pitch and MSAA in one frame: 1280 1x, 1040 1x,
  640 1x, 640 4x, 1280 2x. The frame trace in `work/recomp/rc2/run/h12/ts4.log` shows 459 draws per
  frame.
- On lavapipe, the BackBuffer → FrontBuffer copy (copy 459, destination 0x0A793000, k_8_8_8_8) produced
  zeros whenever other render targets had used base 0 earlier in the frame.
- The rare good frames in skip mode were frames where those earlier draws had been skipped.

**Fix.** `--render_target_path_vulkan=fsi`.

**Checks run** (renderer-map.md section 6 / RM1 list), and what they showed:

| Check | Result |
|---|---|
| Gamma ramp (RM1 cause 4) | ruled out: `REX_GAMMA_LOG` shows the linear 256-entry table, front-buffer format 6 (8_8_8_8), no PWL |
| Swap texture vs resolve destination (checks 2, 3) | Swap source 0x0A793000 1280×720 format 6 with a valid view (`REX_SWAP_LOG`). Every frame has the front copy to 0x0A793000 (`REX_FRAME_TRACE`). The copy was right; its source EDRAM content was black. |
| Draw skipping dropping resolves (RM1 cause 1) | Partly true: the counter_ bug above. Fixed, but full render was black too. |
| Readback resolve (check 7, luminance) | `--readback_resolve=full --vulkan_readback_resolve=true`: still black |
| Native 2x MSAA | `--native_2x_msaa=false`: still black |
| Bisecting the frame's draws (`REX_SKIP_DRAWS` 1:372, 373:433, 434:458) | still black in each case, which pointed at EDRAM ownership |
| Present-skip byte, device adopt vs create, fence (checks 1, 5, 8) | not run: the frames render, so not needed |

### 6.2 Front-end flow

- Engine state 4 is normal on the practice ground. It marks an "in place" part (frontend-map.md).
- `nav_pg.txt` waits for Swing's engine global, then for the practice-ground instance's frame counter to
  pass 120, presses START, and waits for loading to stop. The scene name then reads `S4MainMenu`.
- The sign-in, device selector and profile load passed without intervention in these runs. Nothing
  blocked between Press START and the main menu.

### 6.3 Next, in order

1. **Menu path to a match** (frontend-map.md section 2). From `S4MainMenu`:
   - A (Game Modes), A (Exhibition), A (Single);
   - AssignPad: A, A, confirm;
   - PlayerSelect: A, A;
   - A on AI difficulty, A on venue, A on config.

   Gate each press with `wait str <scene expr> == <SceneName>` (scene names from frontend-map.md) or
   `idle NtReadFile`, and leave 60-120 swaps between presses. Capture every 25-50 swaps to check each
   screen. Parts are listed in frontend-map.md (InGame 0x1DCA7285); the match loads S4Loading, then the
   InGame part.
2. **Serve and rally.** The human player must press the shot button to serve, so script the serve: hold
   the shot button for the power time, then release. Look for an AI-vs-AI option in the exhibition
   config, or script rallies by holding a shot button whenever `ball_new_shot` toggles. Log
   `watch_match.txt` and check `p0_timing`, `p0_power`, `p0_outcome` and the ball position each swap.
   If the menus are too slow to script, frontend-map.md describes a direct ChangePart(InGame) call
   (inferred, untested).
3. **Video.** ffmpeg over the PNG captures (§5.2).
4. **Real GPU.** Re-test the default render-target path and full render without skipping (§4.3).
5. **Smaller items:**
   - `cache:` device;
   - the `XNetLogonGetTitleID` stub (title-server login: frontend-map.md lists it as a possible wait on
     other paths).

## 7. Files

**In the repo** (everything the build needs):

- `tools/recomp/setup_toolchain.sh`, `tools/recomp/patches/xenonrecomp/0001-*.patch`,
  `tools/recomp/patches/rexglue/0001..0005-*.patch`
- `tools/recomp/run_ppc_tests.sh`, `tools/recomp/tests/rc2_forms.s`, `tools/recomp/build_xenon.sh`
- `tools/recomp/to_rexglue.py`, `tools/recomp/check_labels.py`
- `tools/recomp/untile_xenos.py` (Xenos 2D-tiled 32bpp dump to PPM) and its test,
  `tests/test_untile_xenos.py`
- `tools/recomp/rexproj/`:
  - `build.sh`, `headless.sh`, `CMakeLists.txt`, `ts4_manifest.toml`
  - `src/{main.cpp,ts4_app.h,ts4_script.h}`
  - `nav_pg.txt`, `start_pulses.txt`, `watch_basic.txt`, `watch_match.txt`
- `tools/recomp_config.py`, `tests/test_recomp_config.py`

Nothing generated or from the game is in the repo.

**Scratch under `work/recomp/` worth keeping** (git-ignored):

| Path | What |
|---|---|
| `rexsdk/` | installed patched ReXGlue SDK; the game project builds against it |
| `rexbuild/` | ReXGlue build tree; rebuild the GPU plugin here |
| `ref/rexglue-sdk/` | ReXGlue source at `546a082` with patches applied |
| `XenonRecomp/` | patched XenonRecomp |
| `default/default.dll` | default.xex basefile image (RC1) |
| `rc2/rex/` | generated ReXGlue project: `generated/`, `config/*_register_v1.cpp` (pass-1 lists; keep them to skip pass 1), `build/ts4` and the module `.so` files |
| `rc2/{default,loader,swing}/` | XenonRecomp configs and output (stage-1 cross-check) |
| `rc2/logs/imports_h3/` | import tables per milestone |
| `rc2/run/f2/` | the reference run: practice ground and main menu frames, `watch.csv`, `script.csv`, `ts4.log` |
| `rc2/run/h12/ts4.log` | `REX_FRAME_TRACE` of complete Swing frames (459 draws), the black-frame evidence |
| `rc2/run/h10/ts4.log` | trace showing the old counter_ skip bug (frames split at vblanks) |
| `rc2/run/h3/`, `h4/`, `r7/`, `h7/` | early runs: Loader screens (r7, h4 to swap 480); `h7/frame_001322.png` is the first good practice-ground frame |
| `rc2/run/*_bt.txt` | gdb backtraces from the early hangs (audio, accept, swapchain) |
| `rm1_checks.md`, `fe1_waits.md` | analysis-agent notes (superseded by renderer-map.md and frontend-map.md) |

`rc2/run/headless.sh`, `drive.sh` and `run.sh` are older copies with this machine's paths hard-coded. Use
the repo's `tools/recomp/rexproj/headless.sh`.
