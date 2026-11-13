# GP7 notes: swing animation engine and planner (WP7)

Module: Swing_DLL.xex, sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`.
Tools: `tools/fn_asm.py`, `tools/fn_check.py` (MSVC 16.00.10224.00, /O2 /Oi), `tools/sym_info.py`, Python 3.13.18.
Hashes are zlib crc32 of the ASCII name. Confidence: **H** disassembly read directly, **M** consistent structure,
**L** guess (marked `(?)`). Units: cm, 60 Hz ticks (floats for anim time, ints for match frames).
Sources: `src/xbox360/drafts/gp7_aod_loader.c`, `gp7_engine_update.c`, `gp7_swing_contract.c`;
matched code `src/xbox360/gp7_swing_anim_module.c`, `gp7_anim_busy.cpp`, `gp7_types.h`.

## 1. Corrections to the WP7 premise

* `PlannerCommand/@Reset`, `PlannerParameters/@ScaleActivated`, `UpdateSetupCommand/@{SetupId,LeftHanded,Reset,BuildIndex}`,
  `PlayParameters/@AnimIdToPlay`, `Scale/CustomScale[@Bone="B_Neck"]` (fn_88795E40, fn_888EFD68, fn_8878E9B8, fn_88791AE8,
  fn_888BF898, fn_888F9750) are **front-end / player-creator** nodes: their code sits in UI screen classes
  (`S4LockerRoom*`, `S4PlayerCreator_*`, `GameDB:/GameDB/PlayerCreator/@Gender|@DNAFile`, `M_UI_PRESET_GLOBAL_1`). They drive the
  mannequin preview and the per-slot body build; they are **not** how a swing is requested in a match (H).
* `fn_886D75B8` is only the **node-type registration** of "SwingAnimationEngine" (crc32 0xB7625AE0) and
  "SwingAnimationEngineController" (0xA42D753B); argument = pointer to a byte, 1 = register, 0 = unregister (Init
  fn_886DACF0 passes lbl_880C8F37 = 01, Exit fn_886DACA8 passes lbl_880C8F91 = 00). The module shell CSwingAnimation
  (28 bytes, vtable 0x880F3804, registered by fn_886D2838) has a no-op Update. The simulation is the *engine object*
  (vtable 0x880F37A8, ctor fn_886D7878, dtor fn_886D77B8, **Update fn_886E5F50**, Init fn_886E57A8, Exit fn_886E11C8) (H).
  The controller (32 bytes, vtable 0x880F37DC) only reads a service name attribute (hash 0xCEB2A4D9) in Init fn_886D8EF8 and
  stores the service at +0x1c.
* `fn_886DC2C8` binds `AnimationData:/SwingAnimation/States/InstanceState[1]` once per player and builds one binding vector entry
  per player (count = `animations_root+0x54`); it is data plumbing for the display module, not logic.
* `fn_886CD3C8` is the function GP2 calls "anim busy ticks"; it is a pure time formula (section 5).

## 2. Who calls what: the swing -> animation path (H unless marked)

1. GP2 picks the candidate sample (`PlayerState+0xbc8`, side `+0xbd1`) in `fn_886A2E48`/`fn_8865DBA8`.
2. The GP3 movement dispatcher (`$LN886B88BC`, inside fn_886B8468) calls **fn_886A26E0** (0x886B91FC, 0x886B92E4) or **fn_886A58F0**
   (0x886B8C94, 0x886B8DFC, and fn_886A80F0). They turn the committed sample into an *animation request* in the shared object
   **AnimIface** (= GP2's `PlayerCtx+0x78`, GP3's `anim`, the animation engine's `PlayerAnim+0x14`):
   * `AnimIface+0x3c0` vec4 **target position (cm)** = ball sample position + court-frame racket offset. The offset comes from two
     float tables of the player tuning (`PlayerCtx->+0x2c`: rel arrays at `+0xa0` and `+0xac`, indexed by stroke level
     `AnimIface+0x460`, -1 -> 2). **Left-handed mirroring** happens here: `left = (PlayerCtx->0x28+0xc == "Left" 0xDA554856)`;
     with a = table0[level], b = table1[level]: `lateral = left ? (side ? -b : -a) : (side ? a : b)` (side = `PlayerState+0xbd1`),
     i.e. tables swapped and negated (H, fn_886A26E0 0x886A2870..0x886A2894).
   * `AnimIface+0x3d0 / +0x3d4` floats = **allowed contact time window** in ticks from now:
     `ticks = sample.tick(+0x24) - match+0x310`; `lo = ticks - tuning[+0xbd2 ? 0x3c4 : 0x3cc]`, `hi = ticks - tuning[+0xbd2 ? 0x3c8 : 0x3d0]`.
   * `AnimIface+0x3d8 / +0x3dc` position tolerances (tuning `+0x3dc` / `+0x3e0`); `+0x3e0` byte is only a debug marker flag.
   * Gate (tuning, not AnimIface): target farther than `tuning+0x3f4` cm (squared xz compare) from the first usable prediction
     sample; angle player->target `|a| < pool+0x770`; sample height `tuning+0x3bc < y < tuning+0x3c0`.
   * if `AnimIface+0x3b5` (swing requested, set each frame by GP0 fn_886C1ED8) -> **fn_886D3AD8** (clip fitter) with the query list at
     `AnimData root+0x94` (fn_886A26E0) or `+0xa0` (fn_886A58F0). fn_886D7508 / fn_886D7540 are the same call as stand-alone thunks.
3. The animation engine's per-frame Update (fn_886E5F50, section 3) then plays/stretches the chosen layer so its racket event lands on
   the target frame (sections 5-6). It publishes back: `AnimIface+0x464` = planned **contact frame**, flag-block bytes for the
   "animation busy" logic (section 4), and the pose for display.

What is **data**, not code: which clips exist, their ids, segment tables, event annotations (`EventRacket` = racket contact,
`Preparation`), time ratios (`Animations.bin` records, section 7); the tuning tables above; the ball sample from GP2. The clip
**selection rule** is the geometric fit in fn_886D3AD8 (section 6); there is no per-shot-type table in code.

## 3. Engine object and per-frame order (fn_886E5F50), H

Fields of the engine E and of `PlayerAnim P` are in `drafts/gp7_engine_update.c` (all offsets measured). Order inside one Update:

1. `fn_886D7638`: if AnimData root dirty bytes `+0x2ac` / `+0x2ad` are set, copy the custom-scale vec4 (`root+0x29c..0x2a8`) from / to the
   setup record of `Animations.bin` whose `+0x84` id equals `root+0x298` (**SetupId**); then rebuild (`fn_886D3310`).
2. Decide whether to run: `sim = frame.+0x1c && frame.+0x1d` (gameplay frame block, type 0x5E16CF76); `run = !sim || frame.+0x354 || any
   player locked by a cutscene animation (AnimIface+0x55 and per-player record active)`; skipped while the XData bool at `E+0x144` ("paused") is set.
3. `fn_886D7C28(AodManager, root+0x1f4)`: consume the **AOD request queue** stored in the AnimationData root at `+0x1f4`
   (rel-array of 0x14-byte load requests -> `fn_886CE5B0`, rel-array of 0x10-byte release requests -> `fn_886D7B88`, both counts cleared
   afterwards), then tick the manager (`fn_886D2E78`, section 8).
4. `fn_886C8158`: publish animation timing to the gameplay frame block (section 4).
5. For each active player: `fn_886E5378` = `fn_886D9070`, **`fn_886E5178` (pipeline below)**, `fn_886DAF38`, `fn_886CDFD8`, then
   `fn_88649678` publishes the pose (`ToDisplay/Position|Rotation`).
6. For each active player: `fn_886E5008` (debug draw / replay recording hooks).

`fn_886E5178` per player: command intake (live: `fn_886C5D20`; replay: `fn_886E4958`) -> `fn_886DF5D0` (planner step: advance the planner
clock, call the rate solver) -> `fn_886D6478`, `fn_886D5958` (root motion / pose) -> racket-hand nodes (`state+0x210`, `fn_886DCAC8`
yields hash Both 0x5BE8962F / Left 0xDA554856 / Right 0x750B5A10 stored in the per-player record `+0x34`, `+0x38` float, `+0x30` flag)
-> blending (`fn_886CB238`, `fn_886D56B0`, `fn_886D81A0`) -> `AnimIface+0x458/+0x45c := P+0x48/P+0x44`.

## 4. Animation-busy / lock signals (what gameplay waits on)

* `fn_886C8158` (H): for every active player take the topmost entry of its playing list (`P+0x8c..0x90`); if its play record type is
  0x959A9407 or 0xC222A5E0 use `remaining = layer.+0x98 - layer.+0x48` (end time minus current time) and keep the minimum
  (start FLT_MAX). When all players qualify: `*(E+0x13c) := (int)remaining - 20` (flag block `+0xE8`) and, if `remaining < 20.0`
  (pool+0x130), `*(E+0x138) := 1` (flag block `+0xE6`). For player index 0 additionally `flag block +0xEC := (int)(layer.+0x28 - layer.+0x48)`.
  => gameplay is told how many frames its current animation still blocks it and whether the end is within 20 frames.
* `fn_886CD3C8(ctrl)` (H, GP2 `anim_busy_ticks`): `ctrl->+0x2c` = layer stack (`+0x5c/+0x60` layer vector, `+0x18` now). Take the topmost
  layer with `slot != 0xffff` (fn_886C4638, **matched**). If its record has exactly 2 segments:
  `busy = max(0, (segment[1]+0x10 - layer.+0x14) * (record.ratio(+0x14) - 1.0) + layer.+0x24 - stack.+0x18)` else 0.
  Siblings fn_886CD1E8 / fn_886CD2E0 return the same expression as an int (segment[1] and last segment), -1 if the shape does not fit.

## 5. Time scaling / start time relative to the ball (M for roles, H for formulas)

* **Time warp** `fn_886D1408(layer, t) = clamp((t - layer.+0x14) * (record.ratio - 1.0) + layer.+0x24, layer.+0x24, layer.+0x28)`:
  the clip's time ratio (`record+0x14`, 1.0 = unscaled) is applied as an extra shift that grows with elapsed time and is clamped.
* **Rate to hit the target frame** `fn_886C72E0(RateSolver = P+0x430, float *rate)`: with `cur = AnimIface+0x3fc` (frame stamp = current
  match frame) inside the window `[this+0x18, window+0x40]` and the window's layer being the top layer:
  `rate = (window+0x44 - P+0x48) / (float)(*P+0x5f8 - cur + 1)` when `cur <= *P+0x5f8`; otherwise `rate *= this+0x1c`.
  `*P+0x5f8` is an XData int (hash 0xF73023FB). Reading: remaining anim time to the event divided by remaining ticks => the event
  lands on the target frame; hits are therefore achieved by **time-scaling the clip, not by moving the player alone** (M; the roles of
  window+0x44 / P+0x48 as "event anim time / clip now" are inferred from the quotient).
* `fn_886DF5D0` (planner step) then does `planner.+0x18 += dt` where dt = result of the rate solver (or `fn_886D62F8`: 1.0 from pool+0, or
  `planner.+0x14` when `AnimData+0x12` is set, or replay values `AnimIface+0x408/+0x40c`), and `planner.+0x14 := root.+0x0 * dt`.
* `AnimIface+0x464 := AnimIface+0x3fc + (int)contact_offset` is written by fn_886D3AD8 when it accepts a candidate.

## 6. Clip selection: fn_886D3AD8 (0xDF0, vector-heavy, structure only)

* Candidates = layers of the planner's layer set whose animation record id (`record+0x84`) is listed in the **query list** (16-byte rows,
  key at `+0xc`; lists at `AnimData root+0x94` and `+0xa0`, i.e. one list per stroke family).
* Contact moment inside the clip: annotation **"EventRacket"** (0x3B9AD22E) when `record+0xc != -1`, else annotation **"Preparation"**
  (0x7F6C2523); annotations are 0x10-byte rows `{name hash, time, ...}` at `record+0x64` (count `+0x68`). Record `+0x74` = number of
  0x28-byte segments (`+0x70` rel offset); a 2-segment record takes the second segment (`+0x28`).
* The clip's root motion is sampled with `fn_88644CE8` at the warped event time, rotated by the player facing (sin/cos `fn_881BD4B8`) and
  compared against `AnimIface.target_pos` with the time window `+0x3d0/+0x3d4` and tolerances `+0x3d8/+0x3dc`; best candidate (cost
  init FLT_MAX) is stored at `planner+0x168` layer, `+0x16c` record, `+0x170` cost, `+0x174` stretch, `+0x178` start offset (M).
* Not decoded: the exact cost function and the per-row table at `AnimIface+0x38c` (0x30-byte rows with float lists), see drafts.

## 7. Data dependencies

* `\Animations\Animations.bin` (loaded by fn_88774300 into a container, mounted for the engine as `AnimationDB:/`) and
  `\Animations\AnimationsInterface.bin` (fn_88773438): animation records (0x8c bytes: id +0x84, time ratio +0x14, slot +0xc, annotations +0x64,
  segments +0x70; setup records with custom scale +0x38..0x44 and SetupId +0x84); also `SbikAnimationDB:/` (type 0x7600225C).
  fn_886E57A8 sums the `+0x14` of all segments with type hash 0x959A9407 (unnamed) to size the play-slot array `E+0x14c`.
* `Media\Animation\AOD\%u.hkx`, one Havok packfile per clip id (section 8). Clip ids == `record+0x84`.
* Config hashes read by Init: services 0xF26CAE63, 0xD0DB47B3 (path of the gameplay frame block), 0x1E5D80A2 etc.; typed structs
  0x5E16CF76 (gameplay frame block), 0x1E51C496 (per-player records, stride 0x140, `+0x120` byte = active), 0x1367BD6D,
  0x3A60FEE2 (AnimationData root), 0xEE710815 (AnimationDB), 0x7600225C (SbikAnimationDB).
* Tuning from XData (PlayerTuning `PlayerCtx+0x2c`): racket offset tables `+0xa0/+0xac`, `+0x3bc..0x3f4` zone/time constants (GP2/GP3 own them).

## 8. AOD loader (H) - see `drafts/gp7_aod_loader.c`

Load requests are reference counted per clip entry (`fn_886CE5B0`: count 0 -> enqueue, else ++; `fn_886D7B88`: count 1 -> `fn_886D7AE0`
(unload / cancel), else --). Manager object: request vector `+4/+8`, free list `+0x10`, current request `+0x28`, staging buffer `+0x38` of `+0x34` bytes (service
`lbl_88D45B1C+0x2a4`, vtbl+0x38(0xD2000)), streaming flag `+0x44`. Request states 0 queued, 1 reading, 2 read done, 3 loaded, 4/5 cancel,
6 remove. fn_886D2E78 (tick) retires finished/cancelled requests then calls fn_886D2B58, which opens the next file
`Media\Animation\AOD\%u.hkx` through the engine file system (`lbl_88D45B1C+0x224`, vtbl+0x28; flags 0x8001 for streamed), checks that
`service->vtbl[0x38](file size) <= buffer size`, and issues one async read (tag 0x2800, completion callback fn_886C3DA8). Synchronous
requests (non-streaming) are parsed immediately by fn_886472C0 (hkMemoryStream + packfile reader -> clip+0xc). `fn_886CE2D8` is the
single-request form of fn_886D2B58 (no caller). fn_886D7970 / 79D8 / 7A60 are blocking waits (max 1000 polls, Sleep(1)).
fn_886D1DC8 preloads AOD clips for the zones in `AnimIface+0x3f0..0x3f4` (Right 0x750B5A10, Left 0xDA554856, Baseline 0x0F6FB110,
Net 0xCAA7531F, 0x4E4997E5).

## 9. Hashes resolved here (crc32, verified)

SwingAnimationEngine b7625ae0, SwingAnimationEngineController a42d753b, EventRacket 3b9ad22e, Preparation 7f6c2523, Both 5be8962f,
Cutscene f388b2fb, Left da554856, Right 750b5a10, Baseline 0f6fb110, Net caa7531f, Swing 20d7985e, Rush 550171d1, Idle 7c161a2b,
Pause 165bbde9, B_LeftHand 07791d49, B_RightHand 3e4c9599, B_Head 6f94d460, LifeTime 64a3fde0, IsActive 7300948e.
Unresolved (data names, left as hashes): 959a9407, c222a5e0, 323e2cf5, b6cdb794, 9b51b831, b0b391f4 (animation record categories),
b7b2d9fd, 82047f82, 2db2d90f, f73023fb, fc6b3509, ca68aaec (movement/state tags seen in fn_886A26E0/fn_886A84C0).

## 10. Matching status

Matched (`work/specs/GP7/`): `gp7_swing_anim_module.c` fn_886D75B8, fn_886D8FE0, fn_886D8FF0, fn_886D3AB0, fn_886D7508, fn_886D7540;
`gp7_anim_busy.cpp` fn_886C4638. 7 functions, 0x17C = 380 bytes.
Compiler findings:
* STL-style vector with `_Myfirst/_Mylast`, `size()`, `operator[]` in a **.cpp** reproduces fn_886C4638's loop exactly; the plain C forms
  (pointer difference, index loop, `found` variable) all differ in operand order.
* A thunk of the form `ret = 0; if (flag) ret = fn(...); return ret;` reproduces `li r3,0 / beqlr / b target / blr` (fn_886D7508).
* Not matched: fn_886CD3C8 / fn_886D1408 / fn_886C72E0 use the *select-table idiom* (`fcmpu; mfcr; rlwinm x2; or; lfsx table(pool+0x68); fsel`) for
  float min/max; plain `?:`, `if`, `/fp:precise|strict|except` all produce direct `fsel` or branches instead. fn_886CD3C8 additionally keeps the
  0.0 argument in f1 across the call to fn_886C4638 (whole-program register allocation), which fn_check cannot reproduce.
* fn_886DACF0 / fn_886DACA8 (module Init/Exit) belong to clusters (`work/clusters/fn_8864A1A8.txt`, fn_88618858); the 64-bit param home
  (`std r5,0x88(r1); lwz r11,0x88(r1); rldicr r5,r11,32,63`) was not reproduced.
Not decoded: fn_886D3AD8 cost function, fn_886D5958, fn_886D4978, fn_886D81A0, fn_886DFDB0, fn_886E28C8, the command-stream formats
(`P+0x5ac`, `P+0xd0`), the Animations.bin schema names (hash-only), left-handed handling inside the engine (only the gameplay-side mirror above was found;
the `UpdateSetupCommand/@LeftHanded` consumer was not located).
