# Renderer map: the Pam Display renderer and its D3D boundary (Swing_DLL)

Analysis agent RM1, 2026-11-14. Scope: the game's renderer (bucket "game: Pam Display renderer",
0x886E8000-0x88780000) and the statically linked Xbox 360 D3D library it calls (0x88287D28-0x882A8000).
This is an understanding document for the static-recompilation build (`docs/recomp-build.md`) and for a
later own renderer. Nothing here is byte-matched.

**Source and tools.** `orig/54540859/Swing_DLL.dll`: sha256 `a7f28b29…952ba9`, 13,848,064 B, mapped
image base 0x88000000. Symbols: `config/54540859/symbols.txt`. Disassembly: capstone 5.0.7, Python 3.13.18
(`work/disc/ppcd.py` plus throwaway scripts). The measurements in section 3 come from
`python3 tools/renderer_scan.py {boundary,inline,pm4}`, added with this note.

**Tags.**
- **[code]**: read from the disassembly.
- **[data]**: read from the image's data.
- **[inf]**: inferred (from behaviour, neighbourhood, or XDK conventions), not proven.

Function names in this note are proposals. The symbol file still has `fn_XXXXXXXX` for nearly all of them.

---

## 0. Summary

1. **There is no fixed pass list in code.**
   - Passes come from data: render-target descriptions and "pass commands" inside sorted render packets, built
     from the `Hierarchy.xml`/DataSpool display hierarchy (`HierarchyProcessor.cpp`).
   - The code side of a frame is one loop: Display message, then `RenderFrame`, then packet loop, then `Present`.
     Section 1 gives it.
2. **Present path:**
   - resolve the `BackBuffer` render target into the `FrontBuffer` texture (`D3DDevice_Resolve`);
   - then `D3DDevice_Swap(dev, FrontBuffer)`, which calls `VdSwap`.
   - The game turns off D3D's automatic front buffer, so a host that drops resolves shows black.
3. **Device hand-over.** At start-up Swing **adopts an already-existing D3D device** when it finds one through a
   global hand-over pointer. In that case it only re-initialises the ring buffer and video mode; otherwise it
   calls `Direct3D_CreateDevice` (section 2).
4. **Inlining.**
   - Game code contains **no** PM4 packet construction: 0 of the 40 functions holding PM4 type-3 header
     constants are game code.
   - It does write D3D device *shadow state* inline in 24 functions (20,092 B): render states, shader constants,
     sampler fields, dirty flags.
   - It also appends records to a D3D device list in 2 functions.
   - **A hook layer at the 76+21 callable entry points works, provided the draw/resolve hooks read the device
     shadow block** rather than expecting `SetRenderState` calls (section 3.3).

---

## 1. The frame

### 1.1 Objects the frame works on [code]

| Object | Where | Notes |
|---|---|---|
| `g_Display` (Pam Display renderer) | `*(u32*)0x88D45AD4` | Large object, at least 0x15810 B. All renderer functions load it. |
| D3D device | `*(g_Display + 0x15720)` | Same object as `*__imp_VdGlobalDevice` (`0x88000788`), or `0x8800078C` when `KeGetCurrentProcessType()==2`. The inlined XDK accessor uses the second form in 35 game functions. |
| Render-texture table | `*(g_Display + 0x10)` | (CRC32(name), index) pairs between `+4` and `+8`. Entries of 0x44 B at `+0x24`; the texture pointer is at entry `+8`. Names are plain zlib CRC32 [code + computed]: `FrontBuffer` = 0x7E6E6B46, `BackBuffer` = 0x623CC12C, `CamUI` = 0xD2284DB4. |
| RHI / video object | `*(u32*)0x88D45A4C` | `CRenderHardwareInterface_Xenon` [data: RTTI strings at `fn_887C8268`]. Lock at `+0x154`, present parameters at `+0x8C`. |
| Engine singleton | `*(u32*)0x88D45B1C` | `+0x2CC` = hand-over pointer used by device creation (section 2). |

### 1.2 Call order of one frame

The display module receives messages. `fn_88769F10` (0x13D4 B) is its dispatcher [code]:
- `fn_881506A0` extracts the message type;
- an if-chain compares it against type ids at `0x88C6CC54…`;
- each handler runs, followed by another `fn_881506A0`.

One handler is the render message.

| # | Address | Size | Proposed name | What it does | Tag |
|---|---|---|---|---|---|
| 1 | `0x8875F950` | 0xD7C | `CDisplay::OnRenderMessage` | Camera/VMX set-up for the frame, then at `0x88760068-0x88760074`: `0x8873B890`, then `0x8875F308`, then `0x8875EB68`. Also has the screenshot path (`"Shot0000_%i-%i_%i-%i"`, `"ZShot…"`). | code |
| 2 | `0x8873B890` | 0x98 | `BeginFrame` | Calls `SetShaderGPRAllocation` (`0x882910E8`) for the frame. | code |
| 3 | `0x8875F308` | 0x180 | `CDisplay::RenderFrame` | (1) `fn_8822A1E8(g+0x1D64, g+0x1D68)`; (2) if a hierarchy is active (`g+0x1563C` ≠ 0 and ≠ 0xDD3695AD), binds two default render textures (name hashes 0xADA3A6BB and 0x18F10F61) on samplers 5 and 4 with `0x88755E58`; (3) `0x8875E4C8(g+0x1D64, g+0x155F0)`. | code |
| 4 | `0x8875E4C8` | 0x5FC | `RenderPacketLoop` | Walks the sorted render-packet array (see the table after this one). Compares each packet with the previous one so that only changed state is re-sent. | code |
| 5 | `0x88759BA0` | 0x4D0 | `ExecutePassCommands` | Per packet `+0x70`: the pass block (render target, clear, resolve), section 1.3. | code |
| 6 | `0x88750E30` | 0x294 | `DrawPacketGeometry` | Normal path `0x8874EA60`: `DrawVertices` `0x882938A0` or `DrawIndexedVertices` `0x88293488`, primitive-count table at `0x880D1A00`. Second path when `packet+0x328→+0x74` ≠ 0 and `g+0x15628 > 2`: unbinds streams 1 and 2, draws point lists in chunks through `0x8829AE68`, patches three export slots at device `+0x34A4/+0x34BC/+0x34D4`, appends tag 0x8B000000 to the device list at `+0x3500`, then `0x8829A260`. This looks like a GPU memexport pass (skinning/cloth/sweat simulation) [inf]. | code / inf |
| 7 | `0x8875EB68` | 0x260 | `CDisplay::Present` | See the steps after this table. | code |

`RenderPacketLoop` (`0x8875E4C8`) steps per packet:
- `ExecutePassCommands` `0x88759BA0` with the packet's pass block;
- `0x887326B0` (view/job set-up; records `packet+0x328`);
- camera VS constants `0x887071D0`, when `+0xA7` changes;
- lights `0x886F71E0`, when `+0x80`/`+0x84` change;
- material `0x88730CD8`, when the `+0x50` block changes;
- vertex declaration `0x88722798`, when `+0x90` changes;
- shader select and bind `0x8875D910`, when `+0x8E`/`+0xA4` change;
- `0x887074E0`, when `+0x92` changes;
- `SetVertexShaderConstantF` `0x88290568`;
- draw `0x88750E30`. The four parallel draws at the end go through `0x887146C0`/`0x88750DD0`, which looks like a multi-view loop [inf].

`CDisplay::Present` (`0x8875EB68`) steps:
1. If the byte at `this+0x15649` ≠ 0, return without presenting.
2. Lock `*(0x88D45A4C)+0x154`.
3. Frame limiter: compares `this+0x15804` against the elapsed time and sleeps through `fn_8857AFE8`.
4. If `*(u32*)(this+0x1562C)` ≠ 0:
   - `SetShaderGPRAllocation(dev,0,0)`, then the pre-swap sync `0x882957C8`;
   - `ResolveRT` `0x887561A8(…, tex["BackBuffer"])`;
   - `D3DDevice_Swap` `0x88295D00(dev, tex["FrontBuffer"], 0)`.
5. Otherwise: sync, `SetShaderGPRAllocation`, then `Swap(dev, tex["BackBuffer"→entry], 0)`.
6. Unlock.

Other frame drivers that also present:
- **Loading screen.** `LoadingScreenThreadProc` (`fn_88905788`) runs frame `0x88904C40` on its own thread:
  - `CreateRenderTarget`-like `0x8828AFC0` and `SetRenderTarget`;
  - `ClearF` and `Resolve`;
  - the pre-swap sync and `Swap`.

  It renders while the main thread loads [code: strings and call graph].
- **Bink bumper videos.** `BumperVideoThread` (`fn_88905808`) runs frame `0x88904FD8`, which calls `0x88759BA0`,
  `Present` and `0x8873B890`.
- **Offscreen snapshot.** `0x8875F588` (virtual) renders the hierarchy into a texture: `RenderFrame`, then unbind
  all (`0x88296EB8`), then kick-off and cache flush. Used for thumbnails such as `PlayerCreatorThumbnail` [inf].
  This is the main render-to-texture *caching* path.
- **Persist display.** `0x88905600` calls `D3DDevice_PersistDisplay` (`0x88296650`). It runs before the loading
  thread or a module change [inf].

### 1.3 Render targets, clears, resolves [code]

`ExecutePassCommands(ctx, cmd)` (`0x88759BA0`) reads the pass block's first byte as flags:

| Bit | Action | Callee |
|---|---|---|
| `0x04` | resolve, then re-bind | `0x887567D8`: calls `0x887561A8` (resolve) and `0x88756638` (set RT/DS and begin tiling) |
| `0x02` | resolve the depth and secondary targets | `0x887563A8` (per-tile `SetPredication`, `GetLevelDesc`, `Resolve`) |
| `0x08` | clear with flags `byte>>4` | `0x887533F8` `ClearTarget` |

If the render-target index (`cmd+8`) differs from the current one (`ctx+0xC`):
1. Resolve the old target: `0x88756720` and `ResolveRT` `0x887561A8`.
2. Release its surfaces: `0x88750AD8`, twice.
3. Bind the new target: `0x887534F0`, which calls `SetRenderTarget`, `GetLevelDesc`, `CreateRenderTarget`-like `0x8828AFC0`, `SetDepthStencilSurface`, `SetViewport`, `ClearF`.
4. `SetViewport` from the target descriptor (`+0x108…+0x114`), with MinZ 0.0 and MaxZ 1.0.

**Render-to-texture path** (same target, new destination):
1. `GetLevelDesc` (`0x88289D38`).
2. `MapRTFormatToTextureFormat` (`0x886EB3E8`, a switch over D3DFORMAT with A8R8G8B8 as default).
3. If the mapped format differs, the old texture is released (after `BlockOnFence`) and **re-created** with
   `CreateTexture(w, h, 1, usage 1, newFormat, …)` (`0x8828AEA0`).

**`ClearTarget(rt, flags)` (`0x887533F8`).**
- Flags become D3DCLEAR bits: bit0 = 0xF (all colour targets), bit1 = 0x10 (Z), bit2 = 0x20 (stencil).
- Calls `ClearF(dev, flags, NULL, &rt[+0x18..+0x24] colour, Z, stencil)` (`0x8828FA98`), then `SetViewport(rt+0x94)`.
- **Z clears to 0.0 when `rt+0xC4` is set and to 1.0 otherwise.** The same flag selects the depth format
  `D3DFMT_D24FS8`-like 0x1A220197 instead of `D24S8` 0x2D200196 in `ResolveRT`. Some targets therefore use
  reversed, float depth [code; the "reversed" reading is inf].

**`ResolveRT(rt, destTex)` (`0x887561A8`).** `destTex` = 0 means the target's own texture.
- With tiles (`rt+0x80` = tile count > 0, i.e. predicated tiling):
  - per tile i: `SetPredication`-like `0x8829B288(dev, 3<<2i)`;
  - `Resolve(dev, 0, &tileRect[i], destTex, …, clearZ, stencil = rt+0xC8, &params)`;
  - then `0x8829B288(dev,0)` and `EndTiling`-like `0x8829B748`.
- Without tiles:
  - `SetRenderTarget(dev,0,rt+0x84)`, `SetDepthStencilSurface(dev,rt+0x88)`;
  - one `Resolve(dev, 0, NULL, destTex, …)`.
- Resolve flags are 0 (colour target 0, no clear-on-resolve). Clears are separate.

**Render targets created at load.** `0x88750150` (0x984 B; called from `0x88766020` via `0x88751458`) creates
the `BackBuffer`, `FrontBuffer`, `DepthMap`, `ShadowDepthMapPlayer`, `JitterTexture`, `SweatGravityPass` and
`SweatSimulationPass_Player0%d` render textures with `CreateTexture` [data: strings; code: calls].
- Formats passed [code, constants before the call]:
  - FrontBuffer 0x28280106 (X8R8G8B8 variant);
  - depth 0x2D200196 (D24S8);
  - A8R8G8B8 0x18280186 and 0x18280086 (`fn_8874C360`);
  - `0x1A20…` float-depth/float formats.
- `D3DXFillTexture`-like `0x882C5958` with callback `0x886EB3B0` initialises the BackBuffer.
- Whether the game creates its own BackBuffer/FrontBuffer depends on `RHI+0x108`. When it is 0, the FrontBuffer
  is taken from `RHI+0x10C` (the device's). The meaning of `RHI+0x108` is not established.

### 1.4 Post-processing, tone mapping, gamma

- **Post-processing is data-driven.** Material names in `0x8872F6E0` (0xBF8 B) [data]:
  `AddGlow`, `BackBufferBlurV`, `BallImpact`, `DofMat`, `GlowMatUI`, `PlayerTrail`, `PostProdMat(UI|LOW)`,
  `ScreenQuadBackBuffer`, `ThumbnailInGame`, `Corridor_*`.
- Geometry quads named in data:
  - `GlowBlurH/V`, `BackBufferBlurV/H(2)` (`0x8872E320`);
  - `Dof`;
  - `MotionBlurDisplayQuad/BlendQuad/QuadInit` (`0x88727E78`, `0x88743CE8`);
  - `PostProdMat` (`0x88728118`).

  These are screen quads drawn by the ordinary packet loop, fed by resolves.
- **Average luminance.** `ReadAverageLuminance` `0x8874A180` [code]:
  - finds render texture CRC 0x0EBA9702;
  - `GetSurfaceLevel` and `LockRect`, then reads one `float` at the base: a 1×1 32-bit float texture;
  - `Unlock` (cache flush), `BlockOnFence`, `Release`;
  - default −10000.0 (`0x880D17E8`) if the texture is absent.

  The only caller found is `0x8874F420` (virtual), which prints `"LumMoy:%2.3f CurveMerge:%2.3f"` and builds a
  debug curve. So the CPU readback looks like a debug display, and exposure itself is applied on the GPU by the
  post-production shaders sampling that 1×1 texture [inf].
- **Gamma.**
  - Display gamma is set inside D3D during video-mode set-up: `0x882A2430` → `0x8828E7D8`/`0x8828E8A8` →
    `0x8829C3F0` → `0x8829C190` (`VdGetCurrentDisplayGamma`) [code].
  - The game calls no gamma-ramp function directly; `0x882A2430` is reached from both device paths (section 2).
  - **sRGB writes.** `0x8828CDE8` toggles the gamma variant of the render-target-0 colour format (the formats
    tested 2/3/0xA/0xC are the 8_8_8_8 and 2_10_10_10 families) in shadow register `+0x2884`. It is called from
    the render-mode setters `0x88738BE0`/`0x88739110`. Xenos "gamma" formats are piecewise-linear, not true sRGB
    [inf].

---

## 2. Start-up and hand-over

### 2.1 Video and device initialisation: `fn_887CAE50` (0x694 B, virtual) [code]

`CRenderHardwareInterface_Xenon::Init`, step by step:

1. Store the module arguments; take `r30 = *( *(0x88D45B1C) + 0x2CC )`. If `r30` is set: call its `+0x2AE0`
   callback, then `r27 = *(r30+0x2AD8)` (an existing device).
2. Read XData settings by key hash. The values go into a `D3DPRESENT_PARAMETERS` on the stack at sp+0xC0
   (0x7C B; the memcpy size into `RHI+0x8C` is 0x7C):

| PP offset | Field | Value / default |
|---|---|---|
| +0x00/+0x04 | BackBufferWidth/Height | 1280×720 if `XGetVideoMode` reports widescreen, else 1088×816 (0x440×0x330); aspect ratio stored at `RHI+0x6C` |
| +0x08 | BackBufferFormat | XData string `D3DFMT_R8G8B8`/`A8R8G8B8`/`X8R8G8B8`, via the 6-entry table at `0x88C6C404`; default 0x18280186 (A8R8G8B8) |
| +0x0C | BackBufferCount | XData, default 1 |
| +0x10/+0x14 | MultiSampleType/Quality | 0 / XData (default 0) |
| +0x18 | SwapEffect | XData, default 1 |
| +0x24/+0x28 | EnableAutoDepthStencil / format | XData bool (default 1) / XData (default 0x2D200196 D24S8) |
| +0x2C | Flags | XData, default 0 |
| +0x34 | PresentationInterval | XData, default 0x80000000 (immediate) |
| +0x38/+0x3C | DisableAutoBackBuffer / DisableAutoFrontBuffer | (XData == 1), both cleared if `RHI+0x16D` is set |
| +0x40 | FrontBufferFormat | XData, default 0x28280186 |
| +0x48 | RingBufferParameters | copied from `RHI+0x118`: flags 0, **primary 0x40000 B, secondary 0x500000 B, 0x50 segments**. Both buffers come from `fn_8857B048` (physical allocation, flags 0x20000404). |

3. Allocate the two ring buffers.
4. **Branch A, adopt the existing device** (`r27` ≠ 0, `0x887CB3E4`):
   - call `*__imp_KeCertMonitorData`'s `+4` with 1 (when present);
   - under the device lock `+0x3B34`, set the owner thread `dev+0x2A88` and clear a bit in `dev+0x2ABE`;
   - **ring re-initialisation** `0x88292B88(dev, ringParams)`: `VdInitializeRingBuffer`,
     `VdEnableRingBufferRPtrWriteBack`, `VdSetSystemCommandBufferGpuIdentifierAddress`;
   - `BlockUntilIdle` `0x88292A78`;
   - video-mode set `0x882A26D8`/`0x882A2430(dev, pp)` (gamma ramp, scaler);
   - `RHI+0x114 = dev`; reference count `dev+0x3C` is incremented.
5. **Branch B, create**: `Direct3D_CreateDevice` `0x88296D48(pp, &RHI+0x114)`:
   - allocate 0x5F80 and align to 128 (device size 0x5F00);
   - `+0x3C` refcount = 1, `+0x2A80` qword, `+0x2A88` thread, `+0x2A8C` = xam flag, `+0x4230` = 0x12C0-byte block, `+0x5E88` = 0x0C000001;
   - device init `0x882A2940` (`VdInitializeEngines`, `VdSetGraphicsInterruptCallback`, `VdIsHSIOTrainingSucceeded`).
6. Copy pp to `RHI+0x8C`, initialise the critical section `RHI+0x134`, then `fn_887C8C68`.

So **Swing does not necessarily create its own device.** When the hand-over pointer is set, Swing keeps the
device object and its state (allocated by whoever created it, presumably Loader_DLL's statically linked D3D)
and only points it at a new ring buffer.

Which branch runs in the recompiled build is not known: run check C1. What the hand-over pointer holds is
inferred. Reading it as the Loader's device is consistent with `+0x2AD8`/`+0x2AE0` lying inside the 0x5F00-byte
device layout.

### 2.2 Device reset: `fn_887690A8` (0xEC B, virtual via `0x88769AE0`) [code]

1. **Busy-waits** until `*(u32*)0x88D45A94 == 0` and `*(u32*)0x88D45A7C == 0`. These are other threads' busy
   flags [inf].
2. Lock RHI.
3. `BlockUntilIdle`.
4. Unbind all `0x88296EB8`.
5. Release display GPU resources `0x88767230`, which unbinds streams and declaration, frees, and flushes.
6. Copy new present parameters from `g_Display+0x15748` to `RHI+0x8C`.
7. Ring re-initialisation `0x88292B88`, then `BlockUntilIdle`.
8. Video-mode set `0x882A2430`.
9. Unlock.

### 2.3 Device fields established [code unless marked]

| Offset | Meaning |
|---|---|
| +0x00…+0x38 | dirty-flag qwords (`ld/ori/std` in every state setter; `+0x10` render states, `+0x18` fetch/sampler/viewport, `+0x20` bool/int constants) |
| +0x30 / +0x38 | command buffer write pointer (pre-increment `stwu …,4`) / limit; overflow → `0x88292598` |
| +0x3C | reference count |
| +0x480 + 0x18·i | fetch constants (texture: 6 dwords per slot; vertex: 2 dwords; vertex slots from `+0x6F0` down) |
| +0x780 + 16·r | VS float constants (matches Unleashed's older layout) |
| +0x1780 + 16·r | PS float constants |
| +0x2780 / +0x27A0 | bool / int constants |
| +0x2880…+0x2F18 | shadow GPU registers. +0x2884 RT0 colour info; +0x28DC, +0x2934, +0x293C, +0x2948 depth/stencil/colour control; +0x2938, +0x2958…0x2960 blend control RT0-3; +0x2EF8/+0x2EFC blend factors and enables; +0x2F44/+0x2F5E/+0x2F78/+0x2F92 per-sampler bytes [names inf] |
| +0x2A88 | owning thread |
| +0x2A90 | → GPU-written fence |
| +0x2A9C | CPU fence (next) |
| +0x2AA8 | GPR allocation |
| +0x2B04 | flag spun on by `BlockUntilIdle` |
| +0x3144 | declaration or index-buffer object [inf] |
| +0x3148…+0x3154 | render targets 0-3 |
| +0x3158 | depth-stencil surface |
| +0x315C+4s / +0x31A0+s | stream VB pointer / stride |
| +0x31B0+4s | bound textures |
| +0x3218…+0x322C | viewport floats (X, Y, W, H, MinZ, MaxZ) |
| +0x3244 / +0x3248 | bound shaders (one VS, one PS) |
| +0x34A4/+0x34BC/+0x34D4 | three export slots (section 1.2, row 6) [inf] |
| +0x3500 (+0x350C wp, +0x3510 limit) | deferred-record list |
| +0x35A8/+0x35AC | pending-resource list (busy tracking, `0x8829BA90`) |
| +0x3B34 | device critical section |
| +0x4188 | frame counter |
| +0x5E88 | 0x0C000001 at creation |

D3D version 2.0.20209 (LTCG), from the GPU-hang printer `0x882A6C70` (`"D3D version %i.%i %s"`, 0x4EF1, `"LTCG"`) [code + data].

### 2.4 What the first frames after hand-over do

- The first Swing work is the loading screen thread (`0x88904C40`): its own render target, clear, resolve and
  swap.
- The Bink bumper may play (`0x88904FD8`).
- The 3D front-end scene then starts through the Display message path.
- The observed "almost black frame with only the net and umpire chair" is consistent with the 3D front-end scene
  drawing static venue meshes while lit or post-processed output is missing (next section) [inf].

### 2.5 Things in the game's code that give black or almost-black frames if a host mis-handles them

Ranked by how well they explain "Loader frames fine, Swing black, one dark frame with static props only". All [inf]
unless marked.

1. **Resolve into the game-owned FrontBuffer, then `Swap` with an explicit texture.**
   - The game sets DisableAutoFrontBuffer, resolves `BackBuffer` into `FrontBuffer` (`0x887561A8` →
     `Resolve 0x88294450`) and passes that texture to `Swap` (`0x88295D00`).
   - If the host skips or mis-addresses that resolve, or scans out its own back buffer instead of the texture
     given to `VdSwap`, every frame is black.
   - The Loader may use the automatic front buffer, which would explain why it works.
   - `REX_DRAW_EVERY=N` skipping resolves breaks this directly (see `docs/recomp-build.md` §5.4).
   - Checks C2, C3.
2. **Render-target texture formats.**
   - Post effects resolve into textures whose format is chosen by `0x886EB3E8`; render textures are re-created on
     a format change (`0x88759BA0`).
   - Float formats (`0x1A20…`), the 1×1 R32F luminance target (CRC 0x0EBA9702) and the D24FS8 float-depth
     resolve (0x1A220197) are the formats a host is least likely to resolve correctly.
   - The tone-map or post-production pass samples them, so a zero or NaN there blackens the whole image while
     earlier geometry passes still render. Check C3.
3. **Inverted-depth targets.** Targets flagged `+0xC4` clear Z to 0.0 and use float depth. A host that ignores the
   float-depth format or the depth-compare direction rejects every pixel except geometry drawn without depth test.
   Check C4.
4. **Gamma ramp after hand-over.**
   - On branch A the gamma ramp and scaler are re-set by `0x882A2430` on the adopted device.
   - A host whose presenter applies the guest gamma ramp shows black if that ramp ends up zero.
   - Check C1, then dump the ramp the host uses.
5. **Memexport / point-list GPU passes** (`0x88750E30` second path, `0x8829AE68`).
   - If the host does not run memexport, vertex data these passes produce stays empty. That data is probably
     skinned players, cloth and sweat [inf].
   - Static meshes such as the net and umpire chair would still draw, matching the single dark frame.
   - Check C5.
6. **Predicated tiling** (`ResolveRT` with `rt+0x80 > 0`, `SetPredication` `0x8829B288`, `BeginTiling`/
   `EndTiling`-like `0x8829B3F8`/`0x8829B748`). Only used if a target's tile count is non-zero (MSAA or large
   targets). A host that ignores predication resolves the wrong tiles.
7. **Fence and idle waits that never return.**
   - `BlockOnFence` `0x88292698` spins on `*(dev+0x2A90)`. `BlockUntilIdle` `0x88292A78` also spins until
     `dev+0x2B04 == 0`. `ResetDevice` `0x887690A8` busy-waits on `0x88D45A94`/`0x88D45A7C`.
   - The native build already sees the main thread waiting in `0x88292698`, which is expected under a slow
     software GPU.
   - A missing fence write-back or interrupt would hang rather than blacken.
8. **Present skipped.** `Present` returns early when the byte `g_Display+0x15649` ≠ 0. This would freeze the last
   image rather than blacken it. Check C2.
9. **Uninitialised constants.**
   - Camera constants are uploaded only when packet `+0xA7` changes (`0x887071D0`), lights when `+0x80`/`+0x84`
     change, and so on.
   - The first packet is compared with a zeroed packet on the stack (`fn_88713DF8` initialises it), so state that
     equals the "previous" default is never sent.
   - A host that does not keep the device shadow constants between frames, or starts them at garbage, gives
     wrong lighting. Low probability under full emulation.

The luminance readback `0x8874A180` is reached only from a debug-display function, so it is not a likely cause.

---

## 3. The boundary

### 3.1 D3D runtime entry points called by game code (76 callees, 771 call sites, 190 callers)

`python3 tools/renderer_scan.py boundary` (direct `bl` and out-of-function `b` only; virtual calls are not
included). Five of the 76 are already matched (`0x882884B8`, `0x88288530`, `0x8828B128`, `0x88293440`,
`0x88296E30`). Names marked "code" were read from behaviour and constants. "inf" means a role guess,
typically "one of a pair".

| Address | Size | Proposed name | Tag | Sites | Callers (renderer) | First callers |
|---|---|---|---|---:|---|---|
| 88287FA0 | 0x2fc | D3DResource lock wait / BlockUntilNotBusy (inside LockRect) | code: device via VdGlobalDevice, owner thread +0x2A88, BlockOnFence | 28 | 21 (18) | 886E9E60, 886EA110, 887393F0, 88739440, 88739490 |
| 882882A0 | 0x158 | D3DResource_Unlock (flush base+mip ranges with dcbf, lock count −0x100) | code | 82 | 51 (32) | 88239620, 88239A58, 88239E90, 8823A2C8, 8823A700 |
| 882884B8 | 0x74 | D3DResource_AddRef (interlocked inc) | code | 8 | 3 (0) | 887C94C0, 888FB660, 88904C40 |
| 88288530 | 0x80 | D3DResource_Release (interlocked dec, destroy at 0) | code | 99 | 48 (21) | 88221008, 882213A0, 8822EE20, 8822F1E8, 8822F5B0 |
| 88288628 | 0x8c | D3DResource_GetType | code | 6 | 4 (3) | 88236A10, 88733BB0, 88752210, 88754C40 |
| 882886B8 | 0xc8 | create vertex/index buffer (0x20-byte header) | inf | 6 | 6 (5) | 88731158, 88731410, 88739490, 8873AB30, 88757D38 |
| 88288780 | 0xec | query on RT/depth/shader slots | inf | 3 | 1 (0) | 8890CBD0 |
| 88289D38 | 0x100 | D3DTexture_GetLevelDesc(tex, level, D3DSURFACE_DESC*) | code | 29 | 24 (19) | 882213A0, 88221570, 88708560, 8871ABB0, 8872BA68 |
| 8828A3B8 | 0xc0 | D3DTexture_LockRect | code/inf | 49 | 26 (10) | 88239620, 88239A58, 88239E90, 8823A2C8, 8823A700 |
| 8828ABF0 | 0xd0 | D3DTexture_GetSurfaceLevel (0x30-byte surface) | code | 40 | 22 (7) | 8822EE20, 8822F1E8, 8822F5B0, 8822F978, 8822FD40 |
| 8828AEA0 | 0x120 | D3DDevice_CreateTexture | code/inf | 21 | 13 (9) | 882210F0, 882213A0, 882262B0, 88733038, 8874BEA8 |
| 8828AFC0 | 0x164 | CreateRenderTarget / CreateDepthStencilSurface (EDRAM surface) | inf | 4 | 3 (2) | 88750BF0, 887534F0, 88904C40 |
| 8828B128 | 0x98 | D3DSurface_GetDesc | code | 50 | 34 (4) | 8822EE20, 8822F1E8, 8822F5B0, 8822F978, 8822FD40 |
| 8828B298 | 0x18c | D3DDevice_SetTexture(dev, sampler, tex) | code | 15 | 8 (4) | 88737E50, 88755168, 88755480, 88755E58, 887C9F00 |
| 8828BBC0 | 0x80 | SetRenderState_AlphaBlendEnable | code/inf | 16 | 7 (3) | 88738BE0, 88739110, 88755E58, 887C9AD0, 887C9F00 |
| 8828BC50 | 0x7c | SetRenderState blend field (+0x2EF8) | inf | 6 | 1 (1) | 88738BE0 |
| 8828BCE0 | 0x7c | SetRenderState blend field (+0x2EF8) | inf | 11 | 5 (1) | 88738BE0, 887C9AD0, 887C9F00, 888FB660, 8890CFD8 |
| 8828BD70 | 0x7c | SetRenderState blend field (+0x2EF8) | inf | 11 | 5 (1) | 88738BE0, 887C9AD0, 887C9F00, 888FB660, 8890CFD8 |
| 8828BE00 | 0x5c | SetRenderState blend op/alpha field | inf | 3 | 1 (1) | 88738BE0 |
| 8828BE70 | 0x5c | SetRenderState blend op/alpha field | inf | 3 | 1 (1) | 88738BE0 |
| 8828BEE0 | 0x5c | SetRenderState blend op/alpha field | inf | 3 | 1 (1) | 88738BE0 |
| 8828BF50 | 0x84 | SetRenderState_SeparateAlphaBlendEnable | inf | 4 | 2 (2) | 88738BE0, 88739110 |
| 8828CD98 | 0x40 | render-state setter (+0x2944 bit, +0x294C) | code; state unknown | 6 | 4 (1) | 88755E58, 887C9AD0, 887C9F00, 8890CFD8 |
| 8828CDE8 | 0x90 | SetRenderState_SRGBWriteEnable-like (RT0 gamma format) | inf | 5 | 2 (2) | 88738BE0, 88739110 |
| 8828D408 | 0xc8 | SetSamplerState Min/Mag filter | code/inf | 6 | 6 (2) | 886F74B8, 88755E58, 887C9AD0, 887C9F00, 888FB0C8 |
| 8828D5B0 | 0xc8 | SetSamplerState Mag/Min filter | inf | 6 | 6 (2) | 886F74B8, 88755E58, 887C9AD0, 887C9F00, 888FB0C8 |
| 8828D850 | 0x68 | SetSamplerState_MipFilter | code/inf | 1 | 1 (1) | 886F74B8 |
| 8828D970 | 0x60 | SetSamplerState_MipMapLodBias | code/inf | 1 | 1 (1) | 886F74B8 |
| 8828DA98 | 0x6c | SetSamplerState_MaxMipLevel | code/inf | 3 | 2 (2) | 88737E50, 88755E58 |
| 8828DF30 | 0x7c | D3DDevice_SetViewport | code | 13 | 9 (8) | 8874B648, 8874B668, 8874B730, 887533F8, 887534F0 |
| 8828DFB0 | 0x50 | D3DDevice_GetViewport | code | 1 | 1 (1) | 88755E58 |
| 8828E000 | 0x120 | D3DDevice_SetStreamSource | code | 10 | 6 (4) | 88730CD8, 88750E30, 88755E58, 88767230, 888DF8C0 |
| 8828E120 | 0x90 | SetVertexDeclaration or SetIndices (slot +0x3144) | inf | 2 | 2 (2) | 88722798, 88767230 |
| 8828E1B0 | 0x34c | D3DDevice_SetRenderTarget | code/inf | 6 | 5 (4) | 88750AD8, 887534F0, 887561A8, 88756638, 88904C40 |
| 8828E500 | 0x2d8 | D3DDevice_SetDepthStencilSurface | code/inf | 4 | 4 (4) | 88750AD8, 887534F0, 887561A8, 88756638 |
| 8828FA98 | 0x120 | D3DDevice_ClearF | code | 7 | 7 (2) | 887533F8, 887534F0, 887A00B0, 887CA228, 88904C40 |
| 88290568 | 0xd8 | SetVertexShaderConstantF fast path | code | 18 | 13 (11) | 886F6FA8, 886F70B0, 886F70E8, 886F71E0, 886F7998 |
| 88290640 | 0xd8 | SetPixelShaderConstantF fast path | inf | 4 | 4 (3) | 88706E48, 88707360, 88737E50, 8890CA90 |
| 88290718 | 0x5c | SetShaderConstantB | code | 1 | 1 (1) | 886F6FA8 |
| 882907D8 | 0x54 | SetShaderConstantI | code | 2 | 2 (2) | 886F1E18, 88730CD8 |
| 882908C0 | 0xf0 | CreateVertexShader or CreatePixelShader (pair A) | inf | 7 | 6 (2) | 8873AB30, 8874EDE0, 887C94C0, 888F1D00, 888F1D50 |
| 882909B0 | 0x1bc | SetVertexShader or SetPixelShader (pair A, +0x3244) | inf | 14 | 8 (1) | 8822E3E0, 8822E530, 88755E58, 887C9AD0, 887C9F00 |
| 88290C68 | 0xf0 | CreatePixelShader or CreateVertexShader (pair B) | inf | 6 | 6 (2) | 8873AB30, 8874EDE0, 887C94C0, 888F1D00, 888F1D50 |
| 88290D58 | 0x1cc | SetPixelShader or SetVertexShader (pair B, +0x3248) | inf | 8 | 6 (1) | 8822E3E0, 8822E530, 88755E58, 887C9F00, 888FB660 |
| 88290F28 | 0x4c | sets +0x2ED8/+0x3140 | inf | 2 | 1 (0) | 8890CFD8 |
| 88291068 | 0x80 | CreateVertexDeclaration-like | inf | 6 | 6 (4) | 88730CD8, 887311F8, 887312A8, 8873AB30, 887C94C0 |
| 882910E8 | 0xd4 | D3DDevice_SetShaderGPRAllocation | code/inf | 3 | 2 (2) | 8873B890, 8875EB68 |
| 88291290 | 0x124 | grow device deferred-record buffer (+0x3500) | code | 2 | 2 (2) | 887326B0, 88750E30 |
| 882917C0 | 0x1a0 | KickOff (submit ring segment) | inf | 9 | 8 (5) | 88733038, 8874ADC8, 8874B1C0, 8875F588, 88767230 |
| 88292598 | 0x100 | command buffer make-space / segment kick | code | 1 | 1 (1) | 88750E30 |
| 88292698 | 0xf4 | D3DDevice_BlockOnFence | code | 40 | 35 (17) | 88221008, 882213A0, 8822EE20, 8822F1E8, 8822F5B0 |
| 88292A78 | 0x7c | D3DDevice_BlockUntilIdle | code | 6 | 5 (3) | 8873B7E8, 887573E0, 887690A8, 887C9618, 887CAE50 |
| 88292B88 | 0x3f8 | ring buffer (re)initialisation | code | 2 | 2 (1) | 887690A8, 887CAE50 |
| 88292F80 | 0x4bc | DrawVerticesUP-like | inf | 2 | 2 (0) | 887CA2B8, 887CA760 |
| 88293440 | 0x48 | DrawIndexedVerticesUP-like (wraps 88292F80) | inf | 1 | 1 (0) | 8890CFD8 |
| 88293488 | 0x414 | D3DDevice_DrawIndexedVertices | code/inf | 3 | 3 (2) | 8874EA60, 88755E58, 888FB0C8 |
| 882938A0 | 0x474 | D3DDevice_DrawVertices | code/inf | 1 | 1 (1) | 8874EA60 |
| 88294450 | 0x10a8 | D3DDevice_Resolve | code/inf | 7 | 5 (4) | 88755E58, 887561A8, 887563A8, 88756720, 88904C40 |
| 882957C8 | 0x1c8 | pre-Swap sync (WAIT_REG_MEM + InsertCallback 0x88295618) | inf | 3 | 2 (1) | 8875EB68, 88904C40 |
| 88295D00 | 0x828 | D3DDevice_Swap(dev, pFrontBuffer, params) → VdSwap | code | 2 | 2 (1) | 8875EB68, 88904C40 |
| 88296528 | 0x128 | full present helper (resolve, sync, swap) | inf | 2 | 2 (0) | 887AE3D0, 887CAE10 |
| 88296650 | 0x1ec | D3DDevice_PersistDisplay | code | 1 | 1 (0) | 88905600 |
| 88296D48 | 0xe8 | Direct3D_CreateDevice | code | 1 | 1 (0) | 887CAE50 |
| 88296E30 | 0x84 | device Release | code | 1 | 1 (0) | 887CAC58 |
| 88296EB8 | 0x204 | unbind all (RT/DS/streams/textures/declaration) | code | 2 | 2 (2) | 8875F588, 887690A8 |
| 8829A260 | 0x208 | flush deferred records / end of export job | inf | 1 | 1 (1) | 88750E30 |
| 8829A6E8 | 0x138 | resource busy wait | code | 13 | 7 (1) | 8822D4B0, 8822D5C0, 8822D6D8, 8822D7F0, 8822D908 |
| 8829A820 | 0x174 | XGSetTextureHeader-like | inf | 6 | 6 (0) | 8822D4B0, 8822D5C0, 8822D6D8, 8822D7F0, 8822D908 |
| 8829A998 | 0x1b8 | XGSet…Header-like | inf | 1 | 1 (1) | 8871A8C0 |
| 8829AB50 | 0x13c | resource lock helper | inf | 7 | 7 (1) | 8822D4B0, 8822D5C0, 8822D6D8, 8822D7F0, 8822D908 |
| 8829AC90 | 0x1d4 | begin GPU job for a packet | inf | 1 | 1 (1) | 887326B0 |
| 8829AE68 | 0x41c | draw for the export/point path | inf | 2 | 1 (1) | 88750E30 |
| 8829B288 | 0x170 | SetPredication-like | inf | 4 | 2 (2) | 887561A8, 887563A8 |
| 8829B3F8 | 0x34c | BeginTiling-like | inf | 1 | 1 (1) | 88756638 |
| 8829B748 | 0x344 | EndTiling-like | inf | 1 | 1 (1) | 887561A8 |
| 8829C048 | 0xa8 | flush CPU cache range for the GPU (dcbf loop) | code | 9 | 8 (5) | 88733038, 8874ADC8, 8874B1C0, 8875F588, 88767230 |

Also called from game code but placed in the "PIX/debug" bucket:
- `0x882A2430`: video-mode/display set-up including the gamma ramp; callers `0x887690A8`, `0x887CAE50`.
- `0x882A26D8`: KeGetCurrentProcessType loop helper around it.

`0x882A2940` (device init) and `0x882A2C10` (device destroy) sit there too. So the PIX bucket starting at
0x882A0000 also holds D3D device/display code [code], and the bucket boundary in `docs/decomp-remaining.md` is
approximate.

### 3.2 D3DX entry points (21 callees, 53 sites)

| Address | Size | Role | Tag | Callers |
|---|---|---|---|---|
| 882C7288 / 882C72F8 / 882C7368 | 0x6C each | create 2-D / cube / volume texture from memory (`_CU_`, `_3D_`, `DDS` cases of `0x88758448`) | inf | 88758448, 8871ABB0, 888BFD88 |
| 882C5958 | 0x550 | D3DXFillTexture-like (callback `0x886EB3B0`) | inf | 88750150, 882210F0, 882262B0 |
| 882C74C0 | 4 (forward) | shader constant-table query, used when loading `.vso`/`.pso` | inf | 8874EDE0 |
| 882C7750 | 0x90 | vertex-declaration helper; callers parse `C3DVector/Float16_4/Dec3N/D3DColor/UByte4…` | inf | 88748350, 88748B18, 88749920 |
| 882AA058 (forward), 882AAFD8, 882AAFE0, 882AB238, 882AD248, 882C6688, 882C4C40, 882C6680, 882C5EA8 | — | texture processing used by the dynamic-texture builders `0x8874ADC8/0x8874B1C0/0x8874BEA8/0x8874C360` and `0x88752210` (`Textures.rdf` with `D3DFMT_DXT1/3/5/CTX1/A8R8G8B8`): format conversion, compression, filtering | inf | see `tools/renderer_scan.py boundary` |
| 882A93F0, 882A94C8, 882A9780, 882A97F0, 882A9868, 882A98D0 | 0x6C-0xD8 | image/texture helpers at the start of the D3DX range (Bink frame `0x88904FD8`, XPR loader `0x887C8A78`, 88750150) | inf | |

### 3.3 Inlining measurement: how much of the draw path bypasses the callable boundary

**Measurement 1: command-buffer writes.**
- `python3 tools/renderer_scan.py pm4` finds every function that builds a PM4 type-3 header constant (`lis`+`ori`
  giving 0xC0nnXX00 with a plausible opcode): 36 in D3D, 4 in the PIX/display range, **0 in game code**.
- No game function was found that loads the device write pointer (`+0x30`) and limit (`+0x38`) and stores packets
  through it. The five heuristic hits were plain struct copies, checked by hand.
- **Game code never emits GPU packets itself.** [code]

**Measurement 2: inlined device-state writes.**
- `python3 tools/renderer_scan.py inline` finds functions that update a device dirty-flag qword (`ld`/`or`/`std`
  at `+0x00…+0x38` of the same base) and store at device offsets 0x480-0x5F00 through that same base.
- Result: **24 game functions, 0x4E7C = 20,092 bytes**, against 106 D3D functions, which validates the heuristic.
- This is a lower bound: vector stores (`stvx`) of constants through computed addresses are not counted.

| Function | Size | Area | State written |
|---|---|---|---|
| `0x88737F68` | 0xBEC | renderer | render/blend mode: +0x28DC, +0x2901…+0x2903, +0x2934, +0x2948, +0x2F04, +0x2F14, +0x2F18 (109 stores; render-state setters inlined, e.g. `0x8828C2B0`) |
| `0x88738BE0` | 0x530 | renderer | stencil modes (`StencilShadow/Up/Down/Middle`): +0x2904, +0x293C |
| `0x88739110` | 0x2E0 | renderer | depth/colour mode: +0x28DC, +0x2934, +0x29C0, +0x2F04…, +0x35F0 |
| `0x88748040` | 0x110 | renderer | +0x28DC, +0x2948, +0x2F04 |
| `0x88738B58`, `0x88738B88` | 0x30, 0x54 | renderer | +0x2948 |
| `0x88755E58` | 0x350 | renderer | samplers +0x480/+0x48C, +0x2934, +0x293C, +0x2948, +0x29C0, +0x2ED8, +0x2F14 |
| `0x88706E48` | 0x388 | renderer | VS constants c196-… (+0x13C0…) |
| `0x887071D0` | 0x190 | renderer | VS c194 (+0x13A0), PS c0 (+0x1780…) |
| `0x88707360`, `0x887074E0` | 0x180, 0xC4 | renderer | VS (+0x1390, +0x1950…) and PS (+0x1860) constants |
| `0x8871EA50`, `0x886F7198` | 0xF0, 0x44 | renderer | VS +0x1400/+0x13E0, PS +0x1850 |
| `0x88730CD8` | 0x480 | renderer | VS +0x13E0…, +0x2ED8 |
| `0x88767230` | 0x228 | renderer | +0x2ED8, +0x35A4…+0x35AC |
| `0x887C9AD0`, `0x887C9F00` | 0x42C, 0x328 | UI RHI | samplers, blend/stencil/depth, VS constants |
| `0x887CA2B8`, `0x887CA760` | 0x4A4, 0x4F8 | UI RHI | VS +0x790…, PS +0x1780… |
| `0x8890CFD8` | 0x48C | front end | PS +0x1780…, +0x2934, +0x293C, +0x2948, +0x2F14 |
| `0x888FB0C8`, `0x888FB660`, `0x88904C40` | 0x594, 0x164, 0x398 | front end / loading screen | +0x48C, +0x2ED8, +0x2934, +0x2F14 |
| `0x8869D0C8` | 0x658 | gameplay | +0x8E0/+0x8E8 (VS c22) |

**Measurement 3: device-owned lists written inline.** Two renderer functions append records to the device list at
`+0x3500` (write pointer `+0x350C`, limit `+0x3510`; overflow calls D3D `0x88291290`):
- `0x887326B0`: 12-byte record with tag 0x8C000000;
- `0x88750E30`: tag 0x8B000000, plus the export-slot fix-ups at `+0x34A4…`.

They also manipulate device fields directly [code]. These records are consumed later by D3D (`0x8829A260`,
kick-off), not by the GPU [inf].

**Consequences for a hook layer (route b).**
- Every GPU command is still emitted by out-of-line D3D code: draws, resolve, swap, clear, kick-off.
- What bypasses the boundary is **state**: about 20 KB of inlined setters write the device's shadow registers,
  constants and fetch constants directly and set dirty bits. Unleashed-style hooks on `SetRenderState`/a
  render-state table would miss it.
- A hook layer should therefore treat the device's shadow block as the state API. At each hooked draw
  (`0x882938A0`, `0x88293488`, `0x88292F80`, `0x8829AE68`), clear (`0x8828FA98`) and resolve (`0x88294450`),
  read the dirty-flag qwords at `+0x00…+0x38`, translate the changed shadow registers, then clear the bits as
  D3D's own flush (`0x8829D190`/`0x8829CDF8`/`0x8829D038`/`0x8829DFB0`, called at the top of each draw) would.
- The device list at `+0x3500` and the export slots need two small mid-function hooks or a re-implementation of
  `0x8829A260`.
- **Conclusion:** a boundary hook layer can work. The draw path's state cost is one "shadow block → host state"
  translator, not hundreds of mid-asm hooks. The device layout used is the one in section 2.3.

---

## 4. Data structures

### 4.1 Device: see section 2.3. Resources [code]

- **Texture** (header 0x34 B, from `CreateTexture` `0x8828AEA0`):
  - `+0x00` common/type bits (low 4 bits: 3 = texture, 4 = …);
  - `+0x04` refcount; `+0x08` fence; `+0x14`/`+0x18` base/mip flush ranges (packed page counts, used by
    `Unlock`);
  - `+0x1C…+0x33` GPU texture fetch constant (6 dwords). Dword 1 at `+0x20` holds the base address in its top 20
    bits and the format in the low 6 bits; `+0x24` the size; dword 5 at `+0x30` the mip address.
  - `LockRect` computes level addresses from these fields.
- **Surface** (0x30 B, from `GetSurfaceLevel` `0x8828ABF0`): `+0x18` parent texture; `+0x1C` level in the top
  4 bits. EDRAM surfaces: size word at `+0x24` (width = (v>>18)+1, height = ((v>>3)&0x7FFF)+1); format at `+0x28`;
  multisample in `+0x18` low bits (`D3DSurface_GetDesc` `0x8828B128`).
- **D3DSURFACE_DESC** as written by `0x88289D38`: Format, Type, Usage, Pool, MultiSampleType, Quality, Width
  `+0x18`, Height `+0x1C`.
- **Vertex/index buffer**: 0x20-byte header from `0x882886B8`; common word 0x00100001 or 0x00300001 depending on a
  flag; data pointer at `+0x18` (|3).
- D3D object headers come from the game's own allocator `fn_88888668` (XMemAlloc replacement) with attribute
  words 0x6480xxxx/0x8C80xxxx [code].

### 4.2 Render packet (the sorted draw item) [code, layout partial]

The fields `RenderPacketLoop` reads from each packet (`r31`):

| Offset | Use |
|---|---|
| +0x34 | material argument to `0x88730CD8` |
| +0x50 (block) | material parameter block, compared with `fn_8822DF38` |
| +0x70 | pass-command block for `0x88759BA0`: byte 0 = flags (§1.3), +1 = sub-index, +2 = level, +4 = destination texture index, +8 = render-target index |
| +0x7C/+0x84 | light set (`0x886F71E0`) |
| +0x80 | light key |
| +0x8E | shader index (×0x8C into the shader table at `*(ctx+0x20)`) |
| +0x90 | vertex-format index (×0x40 into `*(ctx+0x328)+0x40`) |
| +0x92 | constant-block index (`0x887074E0`) |
| +0x94 | view index (×0xB0 into `*(g_Display+0xA0)+0x20`, `0x887326B0`) |
| +0x96 | shader variant data for `0x8875D910` |
| +0xA0/+0xA1 | skip/countdown byte |
| +0xA2 | slot (`0x8874E9E8`) |
| +0xA4 | shader sub-variant (−1 = none) |
| +0xA5 | layer |
| +0xA6 | flag bits (bit 5 → `g_Display+0x15688`, bits 6/7 → per-frame flags) |
| +0xA7 | camera index |

Packets are built by `HierarchyProcessor` (`0x8872D5F8`, `"[Display] Render packet tab overflow"`) from the
display hierarchy in `Hierarchy.xml`/`.bin` (`0x8874D270`). Render-target descriptors (fields `+0x18` clear colour,
`+0x80` tile count, `+0x84`/`+0x88` colour/depth surfaces, `+0x8C` texture index, `+0x94` viewport, `+0xC4`
inverted-depth flag, `+0xC8` stencil clear, `+0x108…+0x118` viewport floats and enable) also come from data.

### 4.3 Shaders and constants

- **Shader files.** Shader pairs are loaded from `Shaders\` packs (`0x8875C458`) and per-venue archives by
  `0x8874EDE0`.
  - The name format is `"%x-%llx"`: a 32-bit effect hash and a 64-bit permutation key [data].
  - This matches the extracted files in `work/recomp/shaders/` (`…_0x83d970bc-0x2190000442a2efd.pso`).
  - `0x8874EDE0` creates the pixel shader (`0x88290C68`) and the vertex shader (`0x882908C0`).
  - It queries their constant tables through D3DX (`0x882C74C0`) and builds parameter bindings with
    `0x8871A280` [code; the VS/PS assignment of the two create functions is inf].
- **Selection per packet.** `0x8875D910` takes the packet's shader index and sub-variant [code].
  - It picks the material's variant through the material-family builders `0x887302D8`, `0x8871EB40`, `0x8872F6E0`
    (post-production materials) and `0x8871E4F0`.
  - It binds the pair through `0x8822E3E0`/`0x8822E530`, which call the two Set*Shader functions.
  - It applies render modes through `0x88737E50`/`0x886F7110`.
- **Constants** reach the device three ways [code]:
  - `SetVertexShaderConstantF` fast path `0x88290568` (18 sites; `dev+0x780+16·reg`, VMX copy, dirty mask);
  - its PS twin `0x88290640`;
  - direct inlined stores (section 3.3).

  Camera (VS c194-c199), lights (`0x886F71E0`, `0x886F6FA8`, `0x886F70B0`), material parameters (`0x88730CD8`)
  and per-object constants (`0x887074E0`, `0x88706E48`) each have their own uploader, and run only when the
  packet key changes.
- Shader parameter names (`OrenNayarMap`, `ShadowMap`, `BlinnMap`, `WrinkleScale`, `SweatSecondPass` and others)
  are in `docs/assets.md` §10 and `docs/port/players.md`.

### 4.4 Vertex formats

- Vertex element types are parsed from XML names: `C2DVector`, `C3DVector`, `C4DVector`, `Float16_2`,
  `Float16_4`, `Dec3N`, `D3DColor`, `UShort4N`, `UByte4` (`0x88749920`) [data].
- They are converted into a declaration with the D3DX helper `0x882C7750` and `CreateVertexDeclaration`-like
  `0x88291068`.
- Meshes use `_MainVB`/`_OriginalVB`/`SecondVBOf%d` buffers (`0x8873F228…`) with `TriStrip`/`IndexedTriList`
  topologies (`0x887395A8`) [data].
- The declaration used by a packet is chosen by `+0x90` and bound by `0x88722798` (already matched) through
  `0x8828E120`.
- The Xenos D3DDECLTYPE codes are the ones listed in Unleashed's `video.h` (`D3DDECLTYPE_FLOAT3 = 0x2A23B9`, …)
  [inf, same XDK family].

### 4.5 Textures

- **Disc textures** are XPR2 (`fn_887C8A78`) and DDS (`0x88758448`, with `_CU_` cube and `_3D_` volume cases), in
  the formats listed in `docs/assets.md` §3: DXT1, DXT4_5, CTX1, 8_8_8_8, DXN.
- **Runtime-built textures:**
  - `Textures.rdf` with `D3DFMT_DXT1/DXT3/DXT5/CTX1/A8R8G8B8` (`0x88752210`);
  - video textures (`CVideoTextureManager`, `\VideosDDS`, `0x88771378…`);
  - FaceGen textures `0x%x_FaceGen` (`0x88741860`);
  - six internal cube maps `InternalCubeMap0-5` (`0x88741188`, `0x88751AC0`).
- **Render-target formats:** section 1.3.

---

## 5. The 50 renderer functions most worth having as readable C

Ranked for the port: frame control and the boundary first, then state that bypasses the boundary, then
resource set-up. "Matched" is from `config/54540859/match.json`; 3 of the 50 are matched.

| # | Address | Size | Proposed name | Why | Matched |
|---:|---|---|---|---|---|
| 1 | 8875E4C8 | 0x5FC | RenderPacketLoop | the draw loop itself | no |
| 2 | 88759BA0 | 0x4D0 | ExecutePassCommands | render-target switches, clears, resolves | no |
| 3 | 8875EB68 | 0x260 | CDisplay::Present | resolve to FrontBuffer, Swap | no |
| 4 | 887561A8 | 0x200 | ResolveRT | resolve / tiling | no |
| 5 | 8875F308 | 0x180 | CDisplay::RenderFrame | frame entry | no |
| 6 | 887CAE50 | 0x694 | RHI_Xenon::Init | present parameters, ring buffer, device hand-over | no |
| 7 | 887690A8 | 0xEC | CDisplay::ResetDevice | re-initialisation path | no |
| 8 | 88737F68 | 0xBEC | ApplyRenderMode | largest inlined state block | no |
| 9 | 88738BE0 | 0x530 | ApplyStencilMode | inlined stencil state | no |
| 10 | 88739110 | 0x2E0 | ApplyDepthColourMode | inlined state | no |
| 11 | 88750E30 | 0x294 | DrawPacketGeometry | draw / export path | no |
| 12 | 8874EA60 | 0x6C | DrawPacketPrimitives | primitive-count table | no |
| 13 | 8875D910 | 0x3C8 | SelectAndBindShader | shader permutation choice | no |
| 14 | 88730CD8 | 0x480 | ApplyMaterial | material constants, streams | no |
| 15 | 887534F0 | 0x138 | BindRenderTarget | SetRT/SetDS/viewport/clear | no |
| 16 | 887533F8 | 0xF4 | ClearTarget | clear flags, Z direction | no |
| 17 | 887563A8 | 0x28C | ResolveSecondaryTargets | depth/extra resolves | no |
| 18 | 88756638 | 0xE8 | BeginTargetTiling | SetRT and begin tiling | no |
| 19 | 88756720 | 0xAC | ResolveCurrentTarget | | no |
| 20 | 88750150 | 0x984 | CreateRenderTextures | RT formats and sizes | no |
| 21 | 886EB3E8 | 0x698 | MapRTFormatToTextureFormat | format table | no |
| 22 | 88755E58 | 0x350 | BindDefaultTextures | per-frame state reset | no |
| 23 | 887071D0 | 0x190 | UploadCameraConstants | VS/PS constant layout | no |
| 24 | 88706E48 | 0x388 | UploadObjectConstants | VS constants | no |
| 25 | 886F71E0 | 0x2D4 | UploadLights | light constants | no |
| 26 | 887074E0 | 0xC4 | UploadConstantBlock | | no |
| 27 | 88707360 | 0x180 | UploadConstants2 | | no |
| 28 | 887326B0 | 0xD4 | BeginPacketJob | inline device-list write | no |
| 29 | 88722798 | 0xD0 | BindVertexFormat | | **yes** |
| 30 | 8822E3E0 | 0x150 | BindShaderPairA | Set*Shader | no |
| 31 | 8822E530 | 0x148 | BindShaderPairB | Set*Shader | no |
| 32 | 8874EDE0 | 0x640 | LoadShaderPair | `%x-%llx` names, constant tables | no |
| 33 | 8871A280 | 0xAC | BuildShaderParamBindings | | no |
| 34 | 887302D8 | 0x914 | MaterialFamily_Std | shader variant tables | no |
| 35 | 8872F6E0 | 0xBF8 | MaterialFamily_PostProd | post-processing materials | no |
| 36 | 8871EB40 | 0x5E8 | MaterialFamily_B | | no |
| 37 | 8871E4F0 | 0x560 | MaterialFamily_C | | no |
| 38 | 8872D5F8 | 0x568 | HierarchyProcessor::BuildPackets | packet creation | no |
| 39 | 88769F10 | 0x13D4 | CDisplay::HandleMessage | dispatcher | no |
| 40 | 8875F950 | 0xD7C | CDisplay::OnRenderMessage | frame handler | no |
| 41 | 8873B890 | 0x98 | BeginFrame | GPR split | no |
| 42 | 88904C40 | 0x398 | LoadingScreenFrame | second presenter (thread) | no |
| 43 | 88904FD8 | 0x5C8 | BumperVideoFrame | Bink presenter | no |
| 44 | 887C9AD0 | 0x42C | UIRHI_ApplyState | inlined UI state | no |
| 45 | 887C9F00 | 0x328 | UIRHI_ApplyState2 | inlined UI state | no |
| 46 | 887CA2B8 | 0x4A4 | UIRHI_DrawUP | UI user-pointer draws, constants | no |
| 47 | 887CA760 | 0x4F8 | UIRHI_DrawUP2 | | no |
| 48 | 8875F588 | 0x3C4 | RenderToTextureSnapshot | render-to-texture caching | no |
| 49 | 88767230 | 0x228 | ReleaseDisplayGpuResources | reset path | no |
| 50 | 887567D8 | 0x54 | ResolveAndRebind | | **yes** |

Next after these:
- `0x8890CFD8` (front-end inlined state, 0x48C);
- `0x88752210` (`Textures.rdf` builder);
- `0x88754DC0` (`Textures.xpr` loader);
- `0x8874A180` (luminance readback);
- `0x88722000` (render-mode name table, matched).

---

## 6. Runtime checks for the native build

These checks settle the open points above. Addresses are guest addresses in Swing_DLL. The ReXGlue build emits
every function as `sub_XXXXXXXX`, so a mid-asm hook or a wrapper around the function entry works. "Log" means
once per call, limited to the first ~300 Swing frames or to one frame in N.

| Id | Where | Log | Settles |
|---|---|---|---|
| C1 | `0x887CB3E4` (in `sub_887CAE50`, before the branch) | `r27`. Then whether `0x887CB448` (adopt) or `0x887CB4B0` (CreateDevice) runs. After ring init (`0x887CB44C`): `r3`, `*(dev+0x2A90)`, `*(*(dev+0x2A90))`, `dev+0x2A9C`, `dev+0x30`, `dev+0x38` | device hand-over branch; ring state after hand-over |
| C2 | `sub_8875EB68` entry | byte `r3+0x15649` (skip flag), u32 `r3+0x1562C` (resolve-then-swap path), swap count | is Present running, and which path |
| C3a | `sub_88294450` entry (Resolve) | `r4` flags, `r5` rect pointer (+ the 4 words), `r6` destination texture with `*(r6+0x20)` (address and format) and `*(r6+0x24)` (size), `f1` ClearZ; count per frame | which resolves run, into which formats; the FrontBuffer resolve |
| C3b | `sub_88295D00` entry (Swap) | `r4` texture, `*(r4+0x20)`, `*(r4+0x24)`; in the host, the guest address `VdSwap` scans out | the resolve destination and the scanned-out buffer must be the same address |
| C3c | after any Resolve whose destination is the CRC 0x0EBA9702 texture, or at `sub_8874A180` | the float at that texture's base address (base = `*(tex+0x20) & 0xFFFFF000`, physical) | is the 1×1 luminance texture ever written (0, NaN, or sane) |
| C4 | `sub_887533F8` entry (ClearTarget) | `r4` flags, byte `r3+0xC4` (inverted-depth flag), the four clear-colour floats at the descriptor | reversed-Z targets and clear values |
| C5 | `sub_88750E30` entry | `*(*(r3+0x328)+0x74)` ≠ 0 (export path taken), `g_Display+0x15628`; count of `sub_8829AE68` calls | are memexport/point passes executed |
| C6 | `sub_8828E1B0` / `sub_8828E500` entry | `r4`/`r5`: dump 0x30 B of the surface (format `+0x28`, size `+0x24`) | render-target formats the host must support |
| C7 | at `0x88759E14` (in `sub_88759BA0`, after `bl 0x886EB3E8`) | `r3` (new format) and `r7` (old surface), how often a texture is re-created | render-to-texture format churn |
| C8 | `sub_88292698` entry | `r4` fence, `*(*(r3+0x2A90))`, `*(r3+0x2A9C)`, spin time. In `sub_88292A78`, time spent waiting on `dev+0x2B04` | hangs vs. black |
| C9 | host side, after `sub_882A2430` returns | the gamma ramp / PWL table the host presenter applies | black output from a zero ramp |

If C2 shows Present running and C3b shows the swapped texture is the one C3a resolved into, but the image is
black, the problem is inside the scene passes. Then C3a's format list and C5 are the next places to look.

---

## 7. Open points

- **Unidentified D3D entry points.**
  - The exact XDK names of the "inf" rows in section 3.1: the shader create/set pairs, `0x8828E120`, `0x8829AE68`,
    `0x8829AC90` and `0x8829A260`. The "pair A/pair B" vertex-or-pixel assignment needs one check (shader-object
    magic or the device slot each one fills).
  - The state names behind shadow registers `+0x2934/+0x2948/+0x28DC`; the Xenos register map in Xenia's
    `register_table.inc` would settle them.
- **Device hand-over.** What `*(0x88D45B1C)+0x2CC` points to at hand-over, and who writes it (the Loader
  presumably). Check C1 answers the runtime half.
- **Export path.** The role of the export slots `+0x34A4…` and of the `+0x3500` record list (memexport or
  conditional rendering).
- **Data-side passes.** The render-target and pass list per scene is data. Dumping the `Hierarchy.bin` RT
  descriptors would give the exact passes of the front end and of a match.
