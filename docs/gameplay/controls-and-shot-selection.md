# Controls and shot selection: from the pad to the chosen shot (agent G2)

This note follows the path from the controller to the shot the game picks. It covers the pad driver,
the data-driven InputMapper, the PlayerState input block, the shot-button latch, the power (charge)
value and its Finesse / Medium / Powerful tiers, the timing inputs, the full shot-selection decision
tree in `Settings.bin`, where the Risky rows go, aim, serve, and how the AI feeds the same path.

It builds on and **corrects** `input-to-shot.md` and `shot-to-template.md` (section 13 lists the
corrections). Agent G2b extended it with the power counter and divisor, the trigger chain, the
serve path, the stick channel, wood, and a full trace of RT/LT (section 15). Values are quoted where they explain behaviour. The full dump is
`data/gameplay/shot_tree.yaml`, and the flat tree for the C reference is `data/gameplay/shot_tree.tree`.

Confidence tags: **H** = read in code or data and reproducible. **M** = consistent structural
evidence, partly interpreted. **L** = inference. **U** = unknown. Addresses are xex VAs. `S` is the
PlayerState element (0x1070 bytes, `PC+0x74`). `PC` is the PlayerController. Every name hash is
`zlib.crc32` of the ASCII name.

## 0. The model in plain terms

1. **Pad to PlayerState** (H). The pad driver fills a 0xC4-byte record. The InputMapper (data,
   `Settings.bin` `cfg+0x8E0`) writes it into `S.InputState` (S+0x40C..0x4F0) as named bools and floats:
   `Buttons/@A..@RT`, `ShotTriggers`, `@Risk`, `@Rush`, the sticks and the serve inputs.
   - A/B/X/Y = Flat/TopSpin/Slice/Lob.
   - LT **or** RT = `@Risk`. A trigger counts as held above 128/255. LT is also read on its own
     (`Buttons.LT`, s15).
   - RB = `@Rush`, `@ReqFastRepos`, `@ReqVolleyRepos` (go to the net). LB = `@ReqSpeedSwing`,
     `@ReqBaselineRepos`.
   - Left stick = aim **and** movement. Right stick = advanced serve.
   - Every control, edge, output path, offset and stick parameter is in `data/gameplay/input_map.yaml`.
2. **Stroke**. The first held face button is latched (priority Flat > TopSpin > Slice > Lob). When the
   request starts, `fn_8868F178` writes the 12-byte `S.ShotSelection.Request` (S+0x400):
   `IsFlat, IsSlice, IsTopSpin, IsLob, IsRisk, IsPowerful, IsMedium, IsClassicServe, IsAdvancedServe,
   IsSmash, IsWood, IsWoodDown`. **IsSmash** replaces the stroke when the overhead situation flag
   (`S+0x5DA`, Context.IsSmash) is set. (H)
3. **Power = how long the shot button is held** (H, s5). A frame counter (S+0xDFC) starts at 0 when the
   request starts and counts every frame until the swing is committed. The commit happens when the
   button is **released**, or automatically 12 frames before contact if it is still held. Each frame
   `power = min(frames / 60, 1.25) / 1.25` (`fn_8869D720`). The divisor 60 is
   `GameplayInterface.bin` `EngineConfig/@Frequency`.
4. **Tiers** (H). Three one-curve analyser graphs read `power` and give
   **Finesse = power < 0.15**, **Medium = 0.15 <= power < 0.70** and **Powerful = power >= 0.70**.
   In hold time: **Finesse below 0.1875 s (about 11 frames), Medium to 0.875 s (52.5 frames),
   Powerful from 0.875 s, saturated at 1.25 s (75 frames).**
   - Each bool is "graph output > 0.5" (`fn_886872A0`).
   - `fn_886783B0` copies Powerful/Medium into `IsPowerful`/`IsMedium`. Finesse is the "neither" branch of the tree.
5. **Tree** (H). A 33-node binary tree in `Settings.bin` (walker `fn_8865A938`) tests in this order:
   1. WoodDown, Wood
   2. classic serve (stroke x tier), then advanced serve (stroke)
   3. Smash
   4. baseline: tier x stroke, with Slice+Risk = drop shot
   5. volley: stroke only (no tier), with Slice+Risk = drop volley

   The leaf names a template row by id. The planner (`fn_886B0490`) runs at the **animation point**,
   12 frames before contact (`PlayerTuning+0x740`), not at the release (s4).
6. **RT/LT do not make a "risk shot"** (H, s15). The Risk bit changes the row only under Slice
   (drop shot, drop volley). Otherwise it is only copied to the HUD/telemetry and statistics. No
   analyser graph and no ball routine reads it. The Risky rows 12-15 are reachable only through the
   debug shot override. **LT** additionally requests an **inside-out** shot: it feeds
   `Context.InsideOutRequested` and, with the left stick pushed sideways, forces the movement planner
   to commit a swing side at once (s15).
7. **Aim** (H). It uses `Stick_Move` (S+0x448/0x44C). depth = min(|stick|, 1). angle = atan2 of the
   stick, with +pi on the mirrored side. The stick channel itself has a 0.4 **radial** dead zone
   rescaled to 0..1 (s3.2).
8. **Timing** (H for the code, M for the meaning).
   - `S+0xCF8` = frame the shot button was pressed minus the frame of the last launch.
   - `S+0x544` (`ShotContext.ManualShotTiming`) = `TimingState.TimingValue` (S+0xD08) at commit.
   - The **GoodTiming** graph takes the signed timing value in -1..1. Its window is |t| < 0.3 for a
     skill input of 0 and widens to |t| < 0.8 for 1.
   - A **Wood** (frame) shot is forced when |`S+0x544`| >= 0.1 while the animation controller has armed
     the wood check (racket close to the ball).
9. **Serve** (H, s9). Toss with A/B/X (or flick the right stick for the advanced serve), hit on the
   release. Serve power = release time / toss length (0..1), and **Powerful above 0.8, Medium from 0.1**.
   Serve timing comes from a per-animation curve of the frames between release and contact; late
   releases are penalised faster than early ones.

## 1. Provenance

| item | value |
|---|---|
| `Settings.bin` (`Core.arc` 334e7e0d) | 286,492 B, sha256 `55cb175dbaf64e30d75f6fe72ae71305a39a39cffca7a2fa3b2e5471431a0167` |
| `Expressions.bin` (`Core.arc` fa94f637) | 581,988 B, sha256 `fd3bc49b44ca4b77deebc58acaefe67763a273538f4901266f949e9ec9dedee9` |
| `Layoutall.bin` (disc root) | 760,816 B, sha256 `67793f5b7dc771f8fde298ef07e8976d9362c864ac577a4c9db6b2bf874788c5` |
| `Swing_DLL.dll` (PE image) | 13,848,064 B, sha256 `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9` |
| tools | Python 3.13.18 (stdlib), capstone 5.0.7 (`work/disc/ppcd.py`), `tools/fn_asm.py` with `TS4_MATCHING_DIR=work/matching-b9`, cc 13.3.0 |
| `GameplayInterface.bin` (`Core.arc` f26cdc20) | 5,748 B, sha256 `8d4f3685bd5ca2246525e983bebfd9176a247d5dca1b0f8374786fefe2c5dd83` (disc and TU1) |
| extractor | `python3 tools/ts4data/shot_tree.py --settings work/disc/core/334e7e0d.bin --expressions work/disc/core/fa94f637.bin --layout work/disc/Layoutall.bin --interface work/disc/core_all/f26cdc20.bin --input-map data/gameplay/input_map.yaml --out data/gameplay/shot_tree.yaml` |
| values written | `data/gameplay/shot_tree.yaml`, `shot_tree.tree` (adds `risk_curve`, `frequency`), `input_map.yaml` (every control, stick item and serve table) |
| reference C | `ref/gameplay/shot_select.{h,c}`, test `ref/gameplay/test_shot_select.c` (synthetic; optional real-file walk) |

## 2. PlayerState schema from `Layoutall.bin` (new, H)

`Layoutall.bin` holds the reflected layout of every XData type. That includes PlayerState: the type
whose fields put `ShotSelection` at 0x400, with size 0x1070. This turns every XData path in
`Settings.bin` into a byte offset, and it settles which byte is which. `shot_tree.py` resolves the
offsets with its `Layout` class.

Format, refining `docs/disc-data.md` s3:
- The type records are an array `{rel, count 3642}` at file 0x20, at 0x40 bytes each.
  Word 12 is the type crc and word 13 is the size.
- Words 6/7 point to 7-word scalar-field records `{type, size<<16, next-name, OFFSET, type, NAME, align}`.
- Words 9/10 point to 9-word field records `{TYPE, size<<16, NEXT, ?, kind 0xD543463B, NAME, OFFSET, align, 0}`.
- A field's type crc is stored in the record of the **preceding** field (the `{type, next-name}` pair).
  For the first field it is in words 0..5 of the type record.

Validation:
- Six independent anchors from code agree: Flat 0x400, Slice 0x401, TopSpin 0x402, Lob 0x403,
  Risk 0x404 (`fn_8868F178`) and Smash 0x409.
- InputState.Risk = 0x4D8 matches `fn_88687528`.
- Stick_MovePolar Power/Angle = 0x440/0x444 match the "stick used" test of gp2.

Names marked `?` are unresolved hashes.

| S offset | field (XData path) | role |
|---|---|---|
| 0x040 | `PSMove` {Preparation{MaxSpeed,?,Length} 0x40, Swing{...} 0x4C, Output{PressAndHold} 0x58, ? 0x5C, int 0x60} | motion-controller swing model (PS Move legacy). `S+0x58` caps power (s5) |
| 0x3A8 | `SwingSelection.Request.Power` = {RequirePowerful 0x3A8, RequireMedium 0x3A9, RequireFinesse 0x3AA} | tier flags (s5) |
| 0x3AC | `SwingSelection.Request.Style` | style hash (PlayerTuning +0x14 or +0x18, handedness) |
| 0x3B0 | `SwingSelection.Output` {Timing, Power, Control, ...} | grade hashes |
| 0x3D4 | `SwingSelection.EvaluationOutputs` {RequireFinesse 0x3D4, RequireMedium 0x3D8, RequirePowerful 0x3DC, ? 0x3E0, ? 0x3E4, GoodTiming 0x3E8, Wood 0x3EC, ? 0x3F0} | rule graph outputs |
| 0x400 | `ShotSelection.Request` (12 bools) | the tree conditions (s6) |
| 0x40C | `InputState.Shots` list `{Id, Raise}` | RELEASE events per shot id |
| 0x418 | `InputState.ShotTriggers` list `{Id, Raise}` | LEVEL (held) per shot id. Read by `fn_8868F178` |
| 0x424 | `InputState.?` (5 bools) | `S+0x424/0x425` select the serve/return hash in the latch |
| 0x429 | `InputState.DPad` {Up, Down, Right, Left} | |
| 0x430 | `InputState.Stick_Aiming` {X, Y} | left stick (filter header 1) |
| 0x438 | `InputState.d3ef3bda` {X, Y} | unmapped by the config |
| 0x440 | `InputState.Stick_MovePolar` {Power, Angle} | left stick polar (movement, InputNotation) |
| 0x448 | `InputState.Stick_Move` {X, Y} | left stick. **Used by aim** `fn_8869C010` |
| 0x450 / 0x460 / 0x468 | `Stick_1` (D-pad x25) / `Stick_3` (right stick x25) / `PolarStick_3` | |
| 0x470 | `InputState.Buttons` {A, B, X, Y, PressA..PressY, ReleaseA..ReleaseY, LB, RB, LT, RT} (16 bools) | levels 0x470..0x473, press edges 0x474..0x477, release edges 0x478..0x47B |
| 0x480 | `InputState.Serve.Classic` {Throw, ?, ThrowFlat, ThrowSlice, ThrowTopSpin, Flat, Slice, TopSpin} | classic serve: toss levels and hit-on-release |
| 0x488 | `InputState.Serve.Advanced` {PolarStick 0x488, CartesianStick 0x490, AnimationSpeedFactor 0x498, SpeedFactor, Amplitude, Precision, ?, ?, ?, bool 0x4B4, Throw 0x4B5, ? 0x4B6, ...} | advanced serve. The four floats are the `State.bin` HUD "Serve" labels |
| 0x4C8 | `InputState.Serve.IsAdvanced` | |
| 0x4D8 | `InputState.Risk` | LT/RT level |
| 0x4D9 / 0x4DA | `InputState.ShotTriggerDetected` / `InputState.ShotDetected` | latch "held" / "released" bytes (swing trigger vtbl +0x28/+0x2C) |
| 0x4DB..0x4EA | SpecialShot, SpecialShotDetected, Rush, ReqBaselineRepos, ReqVolleyRepos, ?, ReqSpeedSwing, ReqFastRepos, OnRaiseReqBaselineRepos, OnRaiseReqVolleyRepos, InvertPaddle, RequestChallenge, ShotEditor_Launch, ShotEditor_Reset, AskNext, AskPrevious | |
| 0x500 | `Context.ShotContext` (0x80) | 0x544 = `ManualShotTiming` (s7). 0x560 IsHuman. **0x574 ModeBaseLine** (tree `IsBaseLine`). 0x575 IsSmash |
| 0x5D8 / 0x5D9 / 0x5DA | `Context.IsServing` / `Context.IsVolley` / `Context.IsSmash` | serve situation, volley mode, overhead situation |
| 0x5DC / 0x5DD / 0x5E1 | `Context.InsideOutRequested` / `IsFastBall` / `IsPrepared` | 0x5DC = LT inside-out request (s15.4) |
| 0x7C8 | `#7e28dbc0.InsideOut` (float 0/1) | inside-out decision, input of 27 control graphs (s15.3) |
| 0xA40 | `ReceiverState` (0x440, also `PC+0x20`) containing `TimingState` (0xCE0) | `S+0xCF8` = press-to-launch frames. `S+0xD08` = `TimingValue`, copied to `S+0x544` |
| 0xDFC | `ReceiverState.82526c5c.{FrameCount 0xDFC, Value 0xE00}` | power: hold frames and power value (s5). Input of the tier graphs |
| 0xE04 | `ReceiverState.8cbcac9b.{FrameCount 0xE04, Value 0xE08}` | Risk hold frames and value (curve `cfg+0x908/0x920`); no reader |
| 0xE80 | `ServeState.HumanState` {mode 0xE80, 0xE84, ServeClass 0xE88}; `ServerState` counter 0xEBC | human serve input node (s9.1) |

## 3. Pad and InputMapper (values in `data/gameplay/input_map.yaml`)

### 3.1 Buttons

- **Driver** `fn_888854B0` (H). Digital buttons give 0/255 and triggers 0..255. Axes are int16 with
  an invert byte. The records go into a ring at `lbl_88D45B1C+0x234`.
- **Mapper** `fn_88910F50` / `fn_8890DB90` (H).
  - A LEVEL bool is "value != 0", and for LT/RT "value > 0x80". Then `invert` is applied.
  - PRESS/RELEASE take bits 0x40/0x80 of the slot flag word and last one poll.
  - Root `cfg+0x8E0` -> file 0x2C110. Buttons at +0 (11 entries), stick channels at +0xC (3).
  - +0x18 holds 4 entries of 0x34 bytes keyed Slice/Flat/TopSpin/Lob, and +0x24 holds 3 entries with
    angle sectors in degrees (30-90, 90-150, 150-200, 200-270, 270-340, 340-360). The mapper loader
    does not read them; they look like PS Move gesture tables (U).
  - Floats 0.55 and 0.8 sit at +0x30/+0x34, words 1, 0 at +0x38 (U).
- **Shipped mapping** (H):

| control | outputs (S offset) |
|---|---|
| A / B / X | LEVEL `ShotTriggers/Shot[Id]/@Raise` (list 0x418); RELEASE `Shots/Shot[Id]/@Raise` (list 0x40C); LEVEL `Serve/Classic/@Throw<Stroke>` (0x482/0x484/0x483); RELEASE `Serve/Classic/@<Stroke>` (0x485/0x487/0x486); `Buttons` level/press/release |
| Y | the same shot pair for Lob; LEVEL `@SpecialShotDetected` (0x4DC), RELEASE `@SpecialShot` (0x4DB). No Lob serve |
| LT | `Buttons/@LT` (0x47E), LEVEL `@Risk` (0x4D8), PRESS `@AskNext` |
| RT | `Buttons/@RT` (0x47F), LEVEL `@Risk` (0x4D8), PRESS `@AskPrevious` |
| LB | `Buttons/@LB` 0x47C, `@ReqSpeedSwing` 0x4E1, `@ReqBaselineRepos` 0x4DE, PRESS `@OnRaiseReqBaselineRepos` 0x4E3 |
| RB | `Buttons/@RB` 0x47D, `@ReqFastRepos` 0x4E2, `@Rush` 0x4DD, `@ReqVolleyRepos` 0x4DF, PRESS `@OnRaiseReqVolleyRepos` 0x4E4 |
| Start / Back / R-click | `@ShotEditor_Launch`, `@RequestChallenge` (Hawk-Eye challenge), `@ShotEditor_Reset` |

`@AskNext`/`@AskPrevious` are menu/replay paging events (debug: `fn_886C0568` steps a debug index with
them). Hold durations are **not** a mapper feature: no item has a timer. Every hold-dependent
quantity comes from frame counters in the swing controller (s4, s5).

### 3.2 Stick channels (H for code, values from data)

Loader `fn_88910038` (item types `8312E402` cartesian, `B8ED75CD` polar, `A31497B5` direction),
runtime `fn_88910F50` -> `fn_8890E358`:
1. The raw int16 axis (`fn_8890D5F0`) is converted to float and **negated when the item's invert
   bool is 1**. The two "header words" of each item noted by G2 are the paths of those invert bools.
   In the shipped map every item binds them to `InputState/@InvertPaddle` (S+0x4E5).
2. `angle = atan2(x, y)` (`fn_88564BF8(f1 = x, f2 = y)`) and `mag = sqrt(x^2 + y^2)`.
3. Optional snapping of the angle to N sectors (runtime +0x24; not used by the shipped items).
4. **Radial dead zone**: if `mag <= dz * 32767` (const `0x880023EC`) every output is 0. Otherwise
   `m = clamp(mag / 32767, 0, 1)`, `out = (m - dz) / (1 - dz)`, and `(x, y) = out * (x, y) / mag`.
5. Orientation flags at runtime +0x28/+0x29 (a flip and a pi offset), then
   `angle * 1/(2 pi)` (`g_ts4_script_constants+0x1B8`).
6. **Cartesian** item: `X = x * scale[0]`, `Y = y * scale[1]`. **Polar** item: `Power = lerp(power_range, out)`,
   `Angle = lerp(angle_range, normalised angle)`. A running-average filter exists (item word +0x20:
   10 for `Stick_Move`, 1 for the others; M).

| channel | dead zone | items (S offset) |
|---|---|---|
| left stick | 0.4 | `Stick_Aiming` x1 (0x430), `Stick_Move` x1 (0x448, filter 10), `Stick_MovePolar` Power 0..1 / Angle -pi..pi (0x440/0x444) |
| D-pad | 0.4 | `Stick_1` x25 (0x450), `DPad/@Up..@Right` (threshold 0.5) |
| right stick | 0.4 | `Stick_3` x25 (0x460), `Serve/Advanced/CartesianStick` x10 (0x490), `Serve/Advanced/PolarStick` (0x488), `PolarStick_3` (0x468) |

`ref/gameplay` ports this as `ts4_stick_channel`, `ts4_stick_cartesian` and `ts4_stick_polar`
(snapping and filter left out). TU1 changes the left-stick axes `LeftX/LeftY` to `AnyX/AnyY` (s16),
which matches the 2011 patch note "Directional buttons player control added".

## 4. Shot request: latch, state machine, trigger chain

- **`ShotInputLatch`** `fn_88679C78` (PC+0x50, H). While nothing is latched it latches the first set
  of `Buttons.A/B/X/Y` (S+0x470..0x473) as Flat/TopSpin/Slice/Lob. Each frame it does the following:
  - `S+0x4D9` (`InputState.ShotTriggerDetected`, be84dbd4) = "a shot button is held" and `S+0x4DA`
    (`InputState.ShotDetected`) = "the latched button was released".
  - It appends `(S+0x9D4, S+0x9D0)` to the stick ring `S+0x4CC`.
  - It stamps the last frame each of `PressA..Y, ReleaseA..Y` (S+0x474..0x47B) was true at `latch+0x1C..0x38`.
- **Swing trigger interface** (`PC+0x44`, set in `fn_886B83B0`; human: `&PC+0xF4`, vtbl `0x880F46B8`;
  AI: `&PC+0x48`). Human slots (H):
  - `+0x28` = `S+0x4D9` (button held), `fn_8865AB98`.
  - `+0x2C` = `S+0x4DA` (released); it also loads a countdown `this+8 = PlayerTuning+0x74C` (40 frames), `fn_8865AB70`.
  - `+0x30` decrements that countdown, `fn_8865AB58`.
  - `+0x34` = **swing now**: `S+0x98` (`PlayerEvents.BallShot.AtFrame`, the predicted contact frame) is
    valid and `S+0x98 - clock <= PlayerTuning+0x740` (**12 frames**), `fn_88662458`.
- **Request state machine** `fn_886B3CF8(PC, state)` (called from `fn_886BF260`; H for flow).
  - **`0xAFAF1093`** (waiting). On `ShotTriggerDetected` the first time: `fn_8868F178` (Request) and
    `fn_8866B8C0` (press stamp, s7), and `PC+0x58D = 1` (latched). The re-press path is `fn_88698538`,
    which also resets the charge counter (FrameCount = 0, Value = 0). If the human releases in this
    state the swing is **committed** at once: `S+0x544 = TimingState.TimingValue (S+0xD08)`,
    `PlayerInfo[slot]+0xB4 = Good`, `PC+0x58C = 1`, `fn_8866B738`, next state `0xF6EB6636`. Otherwise
    `fn_8868E320`/`fn_8866B5B8`/`fn_886B0380` and next state `0x658B2E11`.
  - **`0x658B2E11`** (swing running). If vtbl `+0x34` (12 frames before contact): commit if not yet
    committed, `fn_886783B0`, then the planner **`fn_886B0490`**, next state `0xA1903341`. Else, if
    the human releases: commit.
  - In the three states above the charge counters advance while not committed (s5).
  - `fn_886B3AE8` (interrupt path) also commits and runs the planner.
  - In state `0x93E5E96D` it runs one of three analysers (`this+0x328` when `Context.IsVolley`, else
    `+0x3B0`/`+0x36C`) and requests the swing if `S+0x5DD && S+0x7C4 > 0.5`, `S+0x5DF && S+0x7C0 > 0.5`
    or `S+0x5D9 && S+0x5DE && team mode != 2 && S+0x7BC > 0.5`.
  - With no button, the **auto swing** sets `Raise` on every ShotTriggers entry whose Id is Flat (`+0x5E0`).

  So **the power stops growing at the release** (or at the auto trigger, if the button is still held),
  while **the shot row is chosen at the animation point** 12 frames before contact. The state hashes are
  unnamed.
- **`fn_8868F178`** (H).
  1. It takes the first entry of **`InputState.ShotTriggers`** (S+0x418, the LEVEL list) whose
     `Raise` is 1, and stores its Id at `PC+0x3C`. **Smash replaces it when `S+0x5DA`** is set.
  2. It clears S+0x400..0x40B.
  3. It sets IsFlat/IsSlice/IsTopSpin/IsLob/IsSmash from the id and `IsRisk = InputState.Risk`.
  4. It calls `fn_8865ED78` (tree walk).
  5. If the chosen row id is `DropShotNormal` (c47dfdc1) or `DropVolley` (8ff66130), it sets
     `PC+0x3C = crc32("DropShot") = 0x990377A5`.
- **Sticky bits** `fn_88687528` / `fn_8867AEB8` (H). `PC+0x3C` (byte) |= `InputState.Risk` and
  `PC+0x3D` |= `InputState.ReqVolleyRepos` (RB) for the whole request; Risk is written back to S+0x4D8
  and `IsRisk`. With `Context.IsSmash` they set `IsSmash` and the Smash id. Both are cleared on entering
  `0xAFAF1093` (`fn_886A84C0`). So tapping RT/LT or RB at any time during the request counts.
- **`fn_886783B0`** (H). It copies a 0x40-byte block from the scratch ball into `S+0x500`, sets
  `IsPowerful = S+0x3A8`, `IsMedium = S+0x3A9`, the Smash id again when `S+0x5DA`, and
  **`ModeBaseLine (S+0x574) = !Context.IsVolley (S+0x5D9)`** (`+0xA4`).
- **Command copy** (`fn_886B5128 +0x44C`, H). When `*(PC+0x40)` is set (a recorded or remote command),
  it copies the command bytes into the state: C+0x99 -> IsVolley, C+0x98 -> IsSmash,
  C+0x9A -> **IsPowerful**, C+0x9B -> **IsRisk**.

## 5. Power (charge) and the Finesse / Medium / Powerful tiers

### 5.1 The counter (H)

`ReceiverState` hangs off `S+0xA40` (also `PC+0x20`). Two charge records live there:
- `ReceiverState.82526c5c` = `{FrameCount S+0xDFC, Value S+0xE00}` (the **power**).
- `ReceiverState.8cbcac9b` = `{FrameCount S+0xE04, Value S+0xE08}` (a **Risk hold** value).

`fn_886B3CF8`, states `0xAFAF1093` (+0x134), `0xF6EB6636` (+0x6EC) and `0x658B2E11` (+0x9C0):
```
if (!PC+0x58C committed && (AI || PC+0x58D latched)) {
    S+0xDFC += 1;                          // every frame from the press
    if (InputState.Risk) S+0xE04 += 1;     // only while LT/RT is held
}
fn_88698538 (new request): S+0xDFC = 0, S+0xE00 = 0
```

### 5.2 The value (H)

Every frame, before the state machine, `fn_886BF360 +0xF8` calls `fn_8869D720` (human, not PS Move):
```
D = **(World+0x44)                    // GameplayInterface root: EngineConfig/@Frequency = 60
alt = fn_8868F0D8(PC, "InstantRocket")   // Profile.SkillList skill value > 0.5
S+0xE00 = curve16(alt ? cfg+0x914 : cfg+0x8FC)(S+0xDFC / D)
S+0xE08 = curve16(alt ? cfg+0x920 : cfg+0x908)(S+0xE04 / D)
curve16 key {x0,x1,y0,y1}: y = y0 + clamp(x-x0, 0, x1-x0)/(x1-x0) * (y1-y0)
```
- `D` comes from `GameplayInterface.bin` (Core.arc `f26cdc20`, 5,748 B, sha256 `8d4f3685...dd83`,
  identical in TU1), type `5e16cf76`, `GameplayInputs.EngineConfig.Frequency` = **60** at root+0. The
  path string `GamePlayInterface:/SwingGameplayInterface/GameplayInputs/EngineConfig/@Frequency` is at
  `0x880C8F40` (resolved by `fn_886AD030`/`fn_886AC790`). So `S+0xDFC / D` is the hold time in seconds.
- `cfg+0x8FC` and `cfg+0x914` are both `[0..1.25 -> 0..1]`: **power = min(t_hold, 1.25 s) / 1.25**.
  The InstantRocket skill (G4b's scope) picks the alternate curve, which is identical in retail data.
- `cfg+0x908` = `[0..1 -> 0..1]`, `cfg+0x920` (InstantRocket) = `[0..0.9 -> 0..1]`. **No reader of
  S+0xE08 was found** in code or in any analyser graph: the Risk hold value is computed and unused.
- The planner `fn_886B0490` computes power itself only on the PS Move path (`IsPSMove`, then capped by
  `S+0x58 PSMove.Output.PressAndHold`) and for the AI (`min(previous, new)` with
  `F = clock - rally+0x68`). For a pad player it uses the counter value above.

### 5.3 Tiers (H)

1. `fn_886872A0` (each frame of the request) runs the analysers at controller
   `+0x108/+0x14C/+0x190/+0x2E4`, which write `SwingSelection.EvaluationOutputs`.
2. It sets `SwingSelection.Request.Power.RequirePowerful (S+0x3A8, 19e5a8dd) = out(0x3DC) > 0.5`,
   `RequireMedium (0x3A9, 4eb93f3d) = out(0x3D8) > 0.5` and `RequireFinesse (0x3AA, 1293ff81) =
   out(0x3D4) > 0.5`. EvaluationOutputs 0x3D4/0x3D8/0x3DC are `RequireFinesse/RequireMedium/RequirePowerful`.
3. `fn_886783B0` copies the first two into IsPowerful/IsMedium.

| graph (index) | input | curve | output cell | meaning |
|---|---|---|---|---|
| `Finesse` d0cb6659 (163) | `ReceiverState.82526c5c.Value` = S+0xE00, cell 107 | 1 on [0, 0.15), 0 on [0.15, 1] | 259 | Finesse |
| `Medium` c1df4081 (164) | same | 0, 1 on [0.15, 0.7), 0 | 260 | Medium |
| `Powerful` 912faaa2 (165) | same | 0 on [0, 0.7), 1 on [0.7, 1] (flat beyond) | 261 | Powerful |
| `PowerfulBall` 729975e2 (169) | hit-point block, cell 72 | 0 below 15, 1 from 15 | 264 | fast incoming ball |
| `GoodTiming` cfdbd245 (178) | ShotContext.ManualShotTiming, SkillList link | lerp(1 if \|t\|<0.3, 1 if \|t\|<0.8; skill) | 273 | timing window (s7) |
| `Wood` 9cafb633 (180) | TimingState (twice), cell 17, ShotContext 2cd48361, fatigue | product of two curve branches | 275 | frame-shot likelihood |

| tier | power | hold time (D = 60) |
|---|---|---|
| Finesse ("Control", tap) | < 0.15 | < 0.1875 s, frames 0..11 |
| Medium ("Normal") | 0.15 .. < 0.70 | 0.1875 .. 0.875 s, frames 12..52 |
| Powerful ("Power", hold) | >= 0.70 | >= 0.875 s, frames 53+, saturates at 75 |

Power is not only a tier: about 25 analyser graphs read S+0xE00 (cell 107) besides the three tier
graphs, and output `AimingState` (cell 145), `ControlValues` (cells 286..297) and related control
cells. So the hold time also feeds aiming precision and control directly (graph formulas: G1/G4b,
`graphs.yaml`). Nothing in code scales ball speed by power. The tier picks the template row
(gp4b, shot-to-template s7). `fn_886B5128 +0xC10` tests `S+0xE00 > cfg+0xC74` (0.7) for the
"powerful ball" flag of the incoming-ball descriptor.

## 6. The shot-selection decision tree (`Settings.bin`, H)

- **Root.** `cfg+0` = `{rel, 0x48BFC8B8}` -> file 0xD44. There are 33 nodes and 34 leaves.
- **Node record.** `{rel children, 2, 2, condition crc32, rel path, pre-order index}`. `fn_8865A9C8`
  numbers the nodes pre-order, true child first.
- **Walk** (`fn_8865A938`). Read the condition object's byte (bound to the node's XData path). If it is
  1, take child 0, otherwise child 1. A leaf `{id, row index}` gets its row index at init, from an
  exact match on `row+0x88`.
- **Re-walk.** `fn_8865ED78` runs after every Request change. The result is `PC+0xB0`.
- **Offsets.** Condition bytes resolve through the schema (s2) to S+0x400..0x40B. `IsBaseLine` is bound to
  `Context/ShotContext/@ModeBaseLine` (S+0x574).

```
n0  IsWoodDown        T: WoodDown (row 36)
n1   IsWood           T: Wood (row 35)
n2    IsClassicServe  T: n3   F: n11
n3     IsTopSpin   T: IsMedium ? row 20 : (IsPowerful ? row 21 : row 22)            kick serve, 150 km/h rows
n6     IsSlice     T: IsMedium ? row 23 : (IsPowerful ? row 24 : row 25)            slice serve, 140 km/h
                   F: IsMedium ? row 26 : (IsPowerful ? row 27 : row 28)            flat serve, 190 km/h
n11   IsAdvancedServe T: IsTopSpin ? row 29 : (IsSlice ? row 30 : row 31)           advanced serve, no tiers
n14   IsSmash         T: SmashNormal (row 33)
n15   IsBaseLine      T: n16  F: n30
n16    IsPowerful T: [IsTopSpin row 8 | IsSlice: (IsRisk ? DropShotNormal row 32 : row 9) | IsLob row 11 | row 10]
n21    IsMedium   T: [IsTopSpin row 4 | IsSlice: (IsRisk ? row 32 : row 5)                | IsLob row 7  | row 6 ]
                  F: [IsTopSpin row 0 | IsSlice: (IsRisk ? row 32 : row 1)                | IsLob row 3  | row 2 ]
n30    (volley)   IsTopSpin TopSpinVolley row 16 | IsSlice: (IsRisk ? DropVolley row 18 : SliceVolley row 17) | FlatVolley row 19
```

Rows 0..11 are named `{TopSpin, Slice, Flat, Lob} x {Finesse, Medium, Powerful}`: 0..3 Finesse,
4..7 Medium, 8..11 Powerful. The leaf ids are crc32 of exactly those names. The serve leaf names are
in s9.4. The full node table with file offsets is in `data/gameplay/shot_tree.yaml` (`tree_nodes`).

Consequences (H):
- **Test order.** Serve tests come before Smash and IsBaseLine. Wood/WoodDown override everything.
- **Tiers.** In the serve and baseline branches the tree tests **IsMedium before IsPowerful** in serves,
  but **IsPowerful before IsMedium** at the baseline. The two cannot both be set from the power graphs
  (disjoint intervals), so the order only matters for the command-copied flags.
- **Flat.** It is the fall-through of each stroke test: no IsFlat node.
- **Lob.** It has tiers at the baseline. In volley mode Y gives **FlatVolley**, and there is no lob volley.
- **Drop shot.** Slice + Risk at the baseline (all tiers) or at the net. **Risk has no other effect on
  the row.**
- **Not reachable from the tree.** Rows 12..15 (`TopSpinRisky`, `SliceRisky`, `FlatRisky`, `LobRisky`)
  and row 34 (`DefensiveShot`). The C test walks all 2^13 Request/context combinations of the real tree
  and reaches exactly rows 0..11, 16..33, 35 and 36.

### 6.1 The Risky rows (12-15): how they can be reached (H)

1. **`PC+0xB0` has two writers.**
   - `fn_8865ED78` = tree result or the debug override. The override applies when
     `DebugConfig(+0x28 of match)+0xF57 != 0` and `+0x844 == 0`. It then takes the entry whose
     `row+0x88 == DebugConfig+0x840`.
   - `fn_886B1BA0` writes `+0x840/+0x844` and builds a Request directly. It is the shot editor (M for the name), launched by
     `@ShotEditor_Launch` = Start: it memsets the Request and sets stroke/Risk/`IsClassicServe = Context.IsServing`.
2. **The "Risky" id set is statistics only.** It is read in code only for statistics and reward
   classification (`fn_88666288 +0x130`, `fn_886B5128` `info+0x3D`).
3. **Animation-class lookup** (`S+0x70C`). It has no literal writer, and the id sets there are
   classification, not selection (shot-to-template s5).

So Risky rows are reached **only through the debug/shot-editor override** in this build. The retail
Risk bit (LT or RT) picks the drop shot under Slice and is otherwise only recorded (s15).
Retune lever: re-point any leaf id (4 bytes at the leaf record) to `4708429a`, `dba7dd53`, `8c2d5a8e` or
`de481349` to make a Risky row selectable, for example `IsRisk` under TopSpin/Flat/Lob. That needs new
nodes, because the tree only branches on Risk under Slice.

### 6.2 Who sets each Request byte in normal play

| byte | writer | confidence |
|---|---|---|
| IsFlat/IsSlice/IsTopSpin/IsLob/IsSmash | `fn_8868F178` from the first held ShotTriggers entry. Smash if `Context.IsSmash` | H |
| IsRisk | `fn_8868F178` = `InputState.Risk` (LT/RT), kept sticky by `fn_88687528`/`fn_8867AEB8`. Command copy `C+0x9B` | H |
| IsPowerful / IsMedium | `fn_886783B0` from the power graphs. Command copy `C+0x9A` (IsPowerful only). Serve: `fn_886723A8` (s9) | H |
| IsWood | `fn_886B0490` entry: if the anim controller's wood arm `*(PC+0x78)+0x431` is set and `|S+0x544| >= 0.1` (constants `+0x2AC/+0x474`), clear the arm and set IsWood. The arm is set to 1 by `fn_886D6EB0 +0x534` (called from `fn_886E2410`) when the squared 3-D distance between the racket point (`anim+0x250`) and the ball point is below `r28+0x4EC`, and cleared by `fn_886BCE88 +0x2E4` | H for code, M for "racket close to the ball" |
| IsWoodDown | aim builder `fn_886AE528 +0x618..+0x760`: the target x is pushed out to at least 50 from the centre line (`x < 0 ? min(x, -50) : max(x, 50)`); if `x < 0`, IsWood is not set and `|T - v127|^2 < 640000` (`g_ts4_script_constants+0x7EC`, 8 m) then IsWoodDown = 1 and the tree is walked again | H for code, L for meaning |
| IsClassicServe / IsAdvancedServe | **`fn_886723A8`** (serve Request builder): `IsClassicServe = Serve.Classic.Throw (S+0x480)`, `IsAdvancedServe = Serve.Advanced.Throw (S+0x4B5)` (or a motion controller) | H |
| IsBaseLine (ModeBaseLine S+0x574) | `fn_886783B0 +0xA4` = `!Context.IsVolley`; also the movement planner `fn_88699300` (+0x380, +0x55C, +0x728, +0x828, +0x874, +0xC58), `fn_886B8468 +0x8A0` (= `!S+0x5DE`) and `+0x1E34`, `fn_886BCE88 +0x4E8`, `fn_886BDCC0 +0xC8` | H |

## 7. Timing

- **Press stamp** (`fn_8866B8C0`, H). `S+0xCF8` (TimingState) = `latch.stamp[PressA..PressY of the
  held button] - rally+0x68`, as float frames. It is the frame the button was pressed, counted from
  the opponent's launch.
- **Signed timing value** (H for the copy, M for the meaning).
  - `S+0x544` = `Context.ShotContext.ManualShotTiming` (38453afd). It gets `TimingState.TimingValue`
    (S+0xD08) when the swing is committed (s4). For the serve it gets the serve timing curve (s9).
    The `PSMove` graph also writes it, for the Move controller.
  - Its range is -1..1, per the GoodTiming and Wood curves.
  - **GoodTiming** = 1 when |t| < 0.3 (skill 0) up to |t| < 0.8 (skill 1).
  - **Wood** (frame shot) triggers at |t| >= 0.1 when the wood check is armed (s6.2).
- **Hit-quality grade** (gp2 6.4, H). It is rolled once per commit by the analyser at `brain+0x19C`
  from distance, a random number, ball+0x68 and ticks:
  - `S+0x3A0 = out < 0.5 ? Bad : Good`
  - `S+0x3A4` = Bad / Medium / Good at 0.33 / 0.66
- **Five-level factors** (gp8 2.2). VeryGood 1, Good 0.75, Normal 0.5, Bad 0.25, otherwise 0
  (`fn_8865AC08`). `S+0x3B4/0x3B8` are only ever set to Good in this build.
- No code compares the press time with the ball arrival for groundstrokes. That comparison happens
  inside the TimingState analysers (`BaselineTimingAbility`, `VolleyTimingAbility`, `39CFDEBA`;
  analyser-graphs.md s6.2). The control graphs of the `Settings` list `00236a48` (s15.3) read
  `ManualShotTiming` through symmetric curves (for example graph 188: 0.4 at |t| >= 0.7, 0.6 for
  |t| <= 0.3).
- **Serve timing is asymmetric** (H, data `cfg+0x78C`, s9): 5 frames late or early cost the same
  (+-0.2), but 8 frames late give 0.5 against -0.32 early, and 10 frames late give 1.0 against -0.4.

## 8. Aim (H)

`fn_8869C010`. The mode hash is in `aim+0x5C`.
- **Stick mode `0x9E51242B`.**
  - `(x, y) = Stick_Move (S+0x448, S+0x44C)`. Both are forced to 0 for non-human players.
  - `v = (y, 0, -x)`.
  - `depth = min(max(|v|, 0), 1)`. This is the **stick magnitude**, not the forward component.
  - `angle = wrap(atan2(v.x, v.z) + (pi if the hitter's court tag == 0xA2EDA1E7))`.
  - The result is written to `aim+0x30/+0x34` and mirrored to `+0x38/+0x3C`.
  - `S+0x5A0` is set to FLT_MAX first.
- **Neutral `0x8999A0BF`.** (0, 0).
- **Auto `0x487570E4`.** `fn_8869BEF0(aim, out, &dist, target - S.LocalPosition(0x8E0))`.
  1. It stores `dist = |target - player|` (S+0x5A0 and S+0x5A4).
  2. It asks `fn_8868ED00(ctrl, buf, 30)` for the ball state 30 ticks ahead (M).
  3. If `|aim.target - buf| > 30.0` (`g_ts4_script_constants+0x42C`), then `depth = 1` and
     `angle = -atan2(dx, dz)` of target - player. Otherwise both are 0.
- **Use.** The planner feeds `aim+0x30/+0x34` into `ball+0x430` / `ball+0x364` (input-to-shot s5). Depth and
  width come from the aim tables keyed by template name (`cfg` vectors at file 0x120 / 0x12C,
  shot-to-template s4). The landing-point maths there is G3's / gp4b's scope.
- **Ported in** `ts4_aim_from_stick` / `ts4_aim_auto`. The court-side tag decides the +pi.

## 9. Serve (H unless marked)

### 9.1 Human serve input node (`0x0E0DB124`, `fn_88696020`)

Pointers set in `fn_8865AEB8`: `this+0x20 = S+0x480` (Serve.Classic), `+0x28 = S+0xE80`
(`ServeState.HumanState`), `+0x2C = S+0xEBC` (`ServerState` frame counter), `+0x24 = cfg+0x92C`.
Each frame it increments `S+0xEBC` and clears `Classic.ShotDetected` / `Advanced.ShotDetected`. After
`S+0xEBC > cfg+0x9A8` (**30 frames**) it runs the mode `S+0xE80`:
- **0, waiting** (`fn_88681B80`):
  - A/B/X `Throw<Stroke>` -> mode 1 (classic), `Classic.Throw = 1`, `ServeClass S+0xE88` = 1 Flat / 2 Slice / 3 TopSpin.
  - a right-stick gesture (`fn_88672750`, record `cfg+0x95C` = `{MinPower 0.9, angle 0, tolerance 1.0,
    frames 1}`) -> mode 2 (advanced), `Advanced.Throw = 1`.
  - idle longer than `cfg+0x9AC` (**480 frames**, 8 s) -> mode 3 and `ThrowFlat` (automatic flat serve).
- **1, classic** (`fn_8865AE10`): keeps `Throw<Class> = 1`, `Throw = 1`, `Advanced.Throw = 0`; the
  release of the button sets `Classic.ShotDetected = 1`.
- **2, advanced** (`fn_8826B640`, `fn_88659BB0`): right-stick class per gesture.
- **3, auto**: `ShotDetected = 1`.

The other gesture records (file 0x970..0x9BC, all MinPower 0.9) have angles pi (tol 1.0), pi (0.5),
2.14 (0.5) and -2.14 (0.5); they are listed in `input_map.yaml` (`serve.right_stick_gestures`). The
AI serves through `fn_886825A0`, which writes the same InputState fields from its command block.

### 9.2 Serve controller (`fn_886B29C8`)

- Phase 0: wait for `Classic.Throw` or `Advanced.Throw`. Then `S+0xF9D = !S+0x4E0`,
  `S+0xF9E = S+0x4E0` (Baseline/VolleyServeInit), `IsVolley = ServeAndVolley`, `SwingCategory` =
  `0x1EB396F9` when serve-and-volley else Flat, `this+0x41 = Advanced.Throw`; toss `fn_88662F60`;
  `this+0x30` = toss start frame.
- Phase 1: toss. `this+0x28 = toss frames - PlayerTuning+0x744` (12); `S+0x98` = contact frame.
  `Classic.ShotDetected` (the release) records the release frame (`fn_8865AD50`, `this+0x34 = clock`).
- Phase 2: when `S+0x98 - clock <= PlayerTuning+0x744`, the hit `fn_886B2638`.

### 9.3 Serve hit (`fn_886B2638`) and the serve Request (`fn_886723A8`)

```
frames = clock + *(this+0x20) - release            // frames between release and contact
t      = released ? curve(PT+0x60C table, serve animation)(frames) : 1.0
S+0x544 ManualShotTiming = t;  S+0x66C (serve Timing) = t
S+0x670 (serve PressAndHold) = released ? clamp((release - toss_start) / this+0x28, 0, 1) : 1.0
GameplayInterface +0x17C = t;  PlayerInfo[slot]+0xBC = grade(|t| < 0.2, < 0.6 ...)
-> fn_886B0490 (planner)
fn_886723A8:  IsFlat/IsSlice/IsTopSpin = Classic.ThrowFlat/ThrowSlice/ThrowTopSpin
              p = S+0x670;  IsPowerful = p > 0.8;  IsMedium = !(p < 0.1) && !IsPowerful
              IsClassicServe = Classic.Throw;  IsAdvancedServe = Advanced.Throw (or PS Move)
```
So the classic serve tier comes from **when in the toss the button is released**: before 10 % of the
toss = Finesse, 10..80 % = Medium, after 80 % = Powerful; holding to the end gives Powerful with
timing 1.0. The timing table (`cfg+0x78C`, 15 curves keyed by serve animation; values in
`input_map.yaml`) for the default animation `2ce33943` is:
`[10-12: 1 -> 0.5] [12-15: 0.5 -> 0.2] [15-20: 0.2 -> 0] [20-25: 0 -> -0.2] [25-30: -0.2 -> -0.4] [30-40: -0.4 -> -1]`.
The ideal release is 20 frames before contact. Ported as `ts4_serve_request`, `ts4_serve_power`,
`ts4_serve_timing`.

### 9.4 Serve leaves and the Advanced block

Serve leaf names (crc32 verified): `Serve_TopSpinMedium` b31b5ee0, `Serve_TopSpinPowerful` 17c6bfe3,
`Serve_TopSpinFinesse` ea0cf389, `Serve_SliceMedium` 5f8e74c3, `Serve_SlicePowerful` 72d4edc1,
`Serve_SliceFinesse` 488717d1, `Serve_FlatMedium` 6bbc9a88, `Serve_FlatPowerful` 26eb8042,
`Serve_FlatFinesse` a9bdbd27, `Serve_AdvancedTopSpin` fa212c96, `Serve_AdvancedSlice` c1e2aa62,
`Serve_AdvancedFlat` a010111f.

`Serve.Classic` (S+0x480): Throw, ShotDetected 0x481, ThrowFlat, ThrowSlice, ThrowTopSpin, Flat, Slice,
TopSpin. `Serve.Advanced`: PolarStick 0x488, CartesianStick 0x490, AnimationSpeedFactor 0x498,
SpeedFactor 0x49C, Amplitude 0x4A0, Precision 0x4A4, DebugStickSpeed 0x4A8, ActualMovementWK 0x4B4,
Throw 0x4B5, ShotDetected 0x4B6, ShotFailed 0x4B7; `Serve.IsAdvanced` 0x4C8. The four advanced
factors are HUD/analyser values (`S+0x674..0x67C` `664e6855.{Speed, Amplitude, Precision}`).

## 10. AI (M)

The AI goes through the same PlayerState and tree:
- `PC+0x10 == 0` disables the stick terms (aim and InputNotation are zeroed, gp2 s7).
- The power path takes `min(previous, new)` (s5).
- Stroke and serve inputs come from command blocks such as `fn_886825A0`, or from the command copy of
  `fn_886B5128`. Those blocks are filled by the AI analysers: 24 `ShotComponents` graphs output a
  Flat/TopSpin/Slice/DropShot/Lob mix, and there are `ServeComponents`, `RepositioningComponents` and
  `PositioningComponents` graphs (analyser-graphs.md s6.5).
- The AI stroke choice from that mix is G4's / the AI package's scope. The interface into this package is:
  stroke id in ShotTriggers, Risk, IsPowerful (command byte `C+0x9A`), IsVolley/IsSmash.

## 11. Code constants vs data

| quantity | value | where | kind |
|---|---|---|---|
| trigger level | > 0x80 | `fn_8890DB90` | code |
| shot-button priority | Flat > TopSpin > Slice > Lob | `fn_88679C78` | code |
| tier bool test | > 0.5 | `fn_886872A0` (`lbl_8814B910`) | code |
| power divisor D | 60 (`EngineConfig/@Frequency`) | GameplayInterface.bin root+0, `fn_8869D720` | data |
| power curve | 0..1.25 -> 0..1 (ramp) | `cfg+0x8FC/0x914` | data |
| Risk hold curve | 0..1 -> 0..1 (0..0.9 InstantRocket) | `cfg+0x908/0x920` | data, unused |
| tier edges | 0.15 / 0.70 | graphs Finesse / Medium / Powerful | data |
| swing lead (planner runs) | 12 frames before contact | `cfg+0x8C0` = PT+0x740 | data |
| serve lead | 12 frames | `cfg+0x8C4` = PT+0x744 | data |
| release countdown | 40 frames | `cfg+0x8CC` = PT+0x74C | data |
| serve input delay / auto serve | 30 / 480 frames | `cfg+0x9A8` / `cfg+0x9AC` | data |
| serve tier edges | 0.1 / 0.8 | `g_ts4_script_constants+0x2AC/+0x110`, `fn_886723A8` | code |
| powerful-ball edge | 0.7 (`cfg+0xC74`), 0.4 at `cfg+0xC70` (U) | `fn_886B5128 +0xC10` | data |
| wood timing edge | abs(t) >= 0.1 | `g_ts4_script_constants+0x2AC/+0x474` | code |
| wood-down x clamp / radius^2 | +-50 / 640000 | `g_ts4_script_constants+0xF0/+0x570/+0x7EC` | code |
| GoodTiming window | abs(t) < 0.3 .. 0.8 by skill | graph `GoodTiming` | data |
| auto-aim distance | 30 (cm) | `g_ts4_script_constants+0x42C` | code |
| stick dead zone | 0.4, radial, rescaled | InputMapper channels; 32767 at `0x880023EC` | data + code |
| LT forced commit | power > 0.2, angle within 0.8727 of pi/2 (4.712 alt) | `g_ts4_script_constants+0x10C/+0xE8/+0x774/+0x778` | code |
| GoToNet zone | abs(z) < 300 | `cfg+0x870` = PT+0x6F0 | data |
| aim mirror | pi | `lbl_880C88DC` | code |

## 12. Open items

1. **State hashes.** `0xAFAF1093`, `0x658B2E11`, `0xF6EB6636`, `0xA1903341`, `0x93E5E96D` are unnamed.
2. **Unnamed fields.** `S+0x424..0x428` (e4e2402d: 707fdc19..888ddb39), `S+0x438` (d3ef3bda), `S+0x5C`
   (d755a588), `S+0x60` (2ffcec37), `S+0xCF8` (02583288), `S+0x4E0` (3eb5a1c7, serve-and-volley
   request), PlayerTuning words baaa713d (12) / 32b6d5c1 (12) / 8946f070 (40), swing category
   `0x1EB396F9`.
3. **Human serve-and-volley writer.** Who sets `S+0x4E0` for a pad player (AI: `fn_886825A0`).
4. **Wood arm radius.** `r28+0x4EC` in `fn_886D6EB0` (object base not identified).
5. **Inside-out geometry.** The exact meaning of the two side tests in `fn_886AE528 +0x78..+0x3B4`, and
   which way the `pi/2` stick window points on screen (depends on the court frame and the `+0x60` flag).
6. **Skill link of the inside-out bonus** in the control graphs, and the consumer of the
   `Settings` list `00236a48` (which control graph runs for which shot).
7. **Risk hold value `S+0xE08`.** No reader found; check the TU1 code patch (`Swing_DLL.xexp`), which is
   not analysed.
8. **InputMapper `+0x18/+0x24` blocks** (gesture tables, probably PS Move) and the root floats 0.55/0.8.
9. **Groundstroke TimingValue (S+0xD08).** Its computation lives in the TimingState analysers; the
   early/late asymmetry for groundstrokes needs those graphs evaluated (G1/G4b).
10. **Polar stick angle offset.** The port uses `Angle = atan2(x, y)` (normalised angle + 0.5, which
    matches the pi/2 tests of `fn_886A3440` and gp2); confirm the +0.5 under Xenia.

## 13. Corrections to earlier notes

| earlier statement | correct |
|---|---|
| `S+0x401` TopSpin, `S+0x402` Slice (input-to-shot s3, s4) | **0x401 = IsSlice, 0x402 = IsTopSpin** (`fn_8868F178` stores; Layoutall) |
| `S+0x470..0x473` are `ShotTriggers` level flags | They are `Buttons.A/B/X/Y`. `ShotTriggers` is the list at S+0x418 |
| `S+0x474..0x477` = Shots release events; `S+0x478..0x47B` = Buttons A/B/X/Y | `PressA..PressY` and `ReleaseA..ReleaseY` |
| `fn_8868F178` reads the `Shots` (release) list | It reads `ShotTriggers` (S+0x418, the level list) |
| aim from `S+0x448/0x44C` "aim stick"; depth = forward component | `Stick_Move`; depth = stick magnitude |
| IsMedium/IsPowerful source `S+0x3A8/0x3A9` "analyser bytes", thresholds unknown | `SwingSelection.Request.Power.RequirePowerful/RequireMedium` = (graph out > 0.5); tiers 0.15 / 0.70 |
| `S+0x405..0x408` cleared then "power tiers" | 0x405 IsPowerful, 0x406 IsMedium, 0x407 IsClassicServe, 0x408 IsAdvancedServe, 0x40A IsWood, 0x40B IsWoodDown |
| `S+0x5D9`/`0x5DA` = copies of command bytes | they are `Context.IsVolley` / `Context.IsSmash`; `S+0x5D8` = `Context.IsServing` |
| G2: power over "frames since the last launch", D unknown, computed by the planner | for a pad player power = **hold frames** (S+0xDFC, counted from the press until release/auto trigger) / **60**; the planner computes it only for PS Move and the AI |
| G2: the planner runs at the button release | it runs **12 frames before contact** (`PlayerTuning+0x740`); the release only stops the charge |
| G2: "the retail Risk button ... is counted (`team+0x3C4`)" | `S+0x3C4` relative to `ReceiverState` is the **Risk hold counter** `S+0xE04`; Risk counts only in statistics/telemetry (`PlayerInfo+0xAC`, `BallInfo+0x89`, shot record) |
| G2: ModeBaseLine has no literal store | `fn_886783B0 +0xA4` (`!IsVolley`) and the movement planner (s6.2) |
| G2: IsClassicServe / IsAdvancedServe written only through data binding | `fn_886723A8` writes them from `Serve.Classic.Throw` / `Serve.Advanced.Throw` |
| G2: IsWoodDown radius `obj+0x7EC` | `g_ts4_script_constants+0x7EC` = 640000 (a code constant) |
| G2: stick "header words" 0x28 / -1 | they are the invert-bool paths (`@InvertPaddle`); the dead zone is radial |
| `fn_886A3440` tests `bb+0x47E` "reaction allowed" (movement-and-ai.md, gp3.md) | S+0x47E is `Buttons.LT`; PS Move synthesises it in `fn_886BD690` |
| G2 s9: serve power is timing-derived through the shot power graphs | serve tier = toss fraction at release (`fn_886723A8`, 0.1 / 0.8) |
| `00236a48` list = reward/coach evaluators (G2b draft) | per-shot control graphs (outputs ControlValues and AimingState) |

## 14. Reproduction

```sh
python3 tools/ts4data/shot_tree.py --selftest
python3 tools/ts4data/shot_tree.py --settings work/disc/core/334e7e0d.bin \
    --expressions work/disc/core/fa94f637.bin --layout work/disc/Layoutall.bin \
    --interface work/disc/core_all/f26cdc20.bin --input-map data/gameplay/input_map.yaml \
    --out data/gameplay/shot_tree.yaml           # also writes data/gameplay/shot_tree.tree
cc -std=c11 -Wall -Wextra -Werror -o /tmp/tss ref/gameplay/test_shot_select.c ref/gameplay/shot_select.c -lm
/tmp/tss && /tmp/tss data/gameplay/shot_tree.tree      # synthetic tests, then every Request combination
TS4_MATCHING_DIR=work/matching-b9 python3 tools/fn_asm.py fn_8868F178 fn_886783B0 fn_886872A0 \
    fn_8869D720 fn_886B0490 fn_8869C010 fn_8869BEF0 fn_8866B8C0 fn_8865ED78 fn_886825A0 \
    fn_886B3CF8 fn_88687528 fn_886723A8 fn_886B2638 fn_88696020 fn_88681B80 fn_886A3440 fn_886BD690 \
    fn_886AE528 fn_8890E358 fn_88662458
python3 work/disc/ppcd.py 886AD380 0x20        # rally+0x68 = clock at launch (fn_886AD278)
grep -n "offset: 0x7c8" data/gameplay/graphs.yaml   # the 27 InsideOut graph inputs (s15.3)
```

## 15. What RT and LT really do (agent G2b; answers the coordinator and R1 s8)

### 15.1 Short answer

- **RT** = drop-shot modifier. It sets `@Risk`. Risk changes the chosen row only under **Slice**:
  RT + X at the baseline gives `DropShotNormal` (row 32, any tier), RT + X at the net gives
  `DropVolley` (row 18). With A, B or Y it changes **nothing** in the shot: no other tree branch, no
  graph, no ball routine and no timing code reads it. TS4 has no TS3-style risk shot; the
  "harder / riskier" behaviour players describe is the **hold time** (power, s5).
- **LT** = the same `@Risk` bit (so **LT + X is also a drop shot**, an input quirk of the shipped map)
  **plus** the inside-out request: `Buttons.LT` feeds `Context.InsideOutRequested` and, with the left
  stick pushed sideways, forces the movement planner to commit a swing side at once. LT + A/B is not a
  drop shot (Risk is ignored outside Slice), so it acts as inside-out only.
- **RB** = `@Rush` / `@ReqFastRepos` (fast reposition) and `@ReqVolleyRepos`, kept sticky for the
  request (`PC+0x3D`). The sticky bit drives the swing-category condition `GoToNet` (follow the shot to
  the net). On the serve, the serve-and-volley byte `S+0x4E0` selects the volley serve init and
  SwingCategory `0x1EB396F9`.

### 15.2 Every consumer of Risk and of the triggers (H, addresses)

| consumer | what it does with it |
|---|---|
| InputMapper | LT -> `Buttons.LT` 0x47E + `@Risk` 0x4D8 + PRESS `@AskNext`; RT -> `Buttons.RT` 0x47F + `@Risk` + PRESS `@AskPrevious` |
| `fn_88687528`, `fn_8867AEB8` | sticky `PC+0x3C |= Risk`, written back to S+0x4D8 and `IsRisk` (S+0x404) |
| `fn_8868F178` | `IsRisk = Risk`, tree walk |
| shot tree | branches on `IsRisk` only under Slice (nodes 19, 24, 28 baseline; 32 volley) |
| `fn_886B3CF8` | `S+0xE04++` while Risk held -> `S+0xE08` (no reader) |
| `fn_886B0490 +0x5B0`, `+0x9E8` | `IsRisk` -> command byte `C+0x9B` and the shot record (stats); the shot record also takes `InsideOut` (`0x4DAA7349`) |
| `fn_886B5128 +0x48C` | command copy `C+0x9B -> IsRisk` (replay/remote); `+0xA30` command `+0x3C = InsideOut > 0.5` |
| `fn_886865D8` | `PlayerInfo[i]+0xAC = IsRisk` (+0xAD IsPowerful, +0xA4 power) for the HUD/GameplayOutputs |
| `fn_88675840` | `BallInfo+0x89 = IsRisk` (+0x88 IsPowerful) |
| `fn_886900E8` (debug) | DebugConfig copies to GameplayInterface +0x5C/+0x5D |
| `fn_886C0568` (debug) | AskNext/AskPrevious step a debug index |
| `fn_886A3440` | **`Buttons.LT`**: forced swing-profile commit (15.4) |
| `fn_886BD690 +0x494` | **`InsideOutRequested (S+0x5DC) |= Buttons.LT`** every frame (all players; on PS Move it first synthesises `Buttons.LT` itself, `+0x50..+0x114`) |

Reads of byte `0x9B` in `fn_8868E370`/`fn_8868EA30` are DebugConfig print flags, and the 0x98/0x99/0x9B
bytes in `fn_8869F760`/`fn_886A5D38` are `GameplayOutputs.RulesInfo.Service`; none is Risk.

### 15.3 Analyser graph bindings (G3b's question; exact result)

Search of every input port of `data/gameplay/graphs.yaml` by Layoutall offset:
- **No graph input is bound to** `ShotSelection.Request` (S+0x400..0x40B: IsRisk, IsPowerful, ...),
  any `InputState` field (S+0x40C..0x4EF: Risk, Buttons LB/RB/LT/RT, ShotTriggers, Shots, sticks,
  serve inputs) or `ReceiverState.8cbcac9b` (S+0xE04..0xE0B).
- Context inputs start at S+0x4F0 (ShotContext, copied from the ball block) and do not include
  `InsideOutRequested`.
- **`#7e28dbc0.InsideOut` (S+0x7C8, cell 127)** is an input of 27 graphs: indices 188-190, 202-207,
  209-211, 238-240, 243-245, 248-250, 252-254, 271-273. These are the per-shot **control graphs**
  listed by `Settings` `00236a48.8c5e64b4` (cfg+0x150, file 0x28C10; ids FlatFinesse, SliceMedium, ...,
  entry 11 `Risk` -> graph `0x90B9BEFC`), which output `ControlValues` (cells 286..297) and
  `AimingState.Efficiency` / `DeepDeviation`. In graph 188 the term is
  `r68 = InsideOut * curve([0..1 -> 0..0.2])(SkillList link r67)`, added into the sum r114 with the
  other bonuses: an inside-out shot gets a control bonus of up to 0.2 scaled by a skill (by its text,
  `InsideOutMaster` "more powerful inside-out (LT) shots"; the link's skill id is not resolved here).
- The power value S+0xE00 (cell 107) feeds the tier graphs and about 25 aiming/control graphs (s5.3).

So the only trigger effect visible to the graphs is **InsideOut**, set from LT (15.4). Risk reaches
nothing but the tree's Slice branches, statistics and the HUD.

### 15.4 LT and inside-out (H for code, M for the geometric meaning)

1. **Request.** `fn_886BD690` (from `fn_886BF260 +0xF0`, every frame when the match phase matches):
   `S+0x5DC InsideOutRequested |= Buttons.LT`.
2. **Decision.** Aim builder `fn_886AE528 +0x78..+0x3B4`: when `InsideOutRequested` and `InsideOut`
   (S+0x7C8) < 0.5, it projects two positions (`fn_881896F8`, `fn_8865E730`) and tests on which side of a
   reference line each falls. If the two sides differ it sets `InsideOut = 1.0`
   (`g_ts4_script_constants+0`) and keeps the request; otherwise `InsideOut = 0` and the request is
   dropped. I read this as "the ball is on the other side of the body from the natural stroke", i.e.
   a real run-around (M).
3. **Forced side commit.** Movement planner `fn_886A3440` (called by `fn_886A9E48` and `fn_886B8468`):
   for a human pad player with `Buttons.LT` held, `Stick_MovePolar.Power > 0.2` and the stick angle
   (plus pi on the mirrored court side `0xA2EDA1E7`) within **0.8727 rad (50 deg) of pi/2** (of
   `3 pi/2` = 4.712 when the flag `*(planner+0x2C)+0x60` is set) it immediately runs `fn_886A2E48` with
   swing profile `PlayerTuning+0x1F8` (flags `01 00 00 00`, speed limit 3 m/s, no volley limit). That
   function scores both sides (`ts4_selection_scorer_score_both_sides`, with the stick InputNotation
   choosing the window end) and commits `S+0xBC8` (sample) and `S+0xBD1` (side). Without LT the
   planner goes through its normal profile order (`+0x238/+0x248`, then `+0x218`, `+0x208`, `+0x228`).
   For the AI the same function commits `+0x1F8` whenever `Buttons.LT` is set. Ported as
   `ts4_lt_forced_commit`.
4. **Effects.** `InsideOut` is read by the 27 control graphs (15.3), by the shot record and the
   statistics counters 0x1F/0x20 (`fn_886567A8` from `fn_886AE528 +0x16B0`), and by the remote command
   (`fn_886B5128 +0xA30`). No code reads it to change the stroke row or the template. The stroke
   **side** (forehand/backhand) is fixed by the planner commit in step 3, not by the shot tree.

So the manual's "LT = inside out" is **confirmed** in code, with the side forced in the movement
planner (stroke-side selection), not in the shot tree.

### 15.5 R1 s8 hypotheses 1-5

| # | hypothesis | verdict |
|---|---|---|
| 1 | LT and RT both set `@Risk`; Risk only turns Slice into drop shot / drop volley; LT + X also drops; inside-out reads `Buttons.LT` and forces the stroke side outside the tree | **Confirmed** (H). LT + X = drop shot. Inside-out: `fn_886BD690` (request), `fn_886AE528` (decision), `fn_886A3440` -> `fn_886A2E48` (side commit) |
| 2 | RB = follow-to-net / fast reposition; RB on a serve = serve & volley; LB may be dead | **Partly confirmed.** RB -> `@Rush`, `@ReqFastRepos`, `@ReqVolleyRepos`; the sticky `PC+0x3D` drives the condition `GoToNet` (0x7E522D55: sticky RB and `|player z| < PlayerTuning+0x6F0` = 300) and `Fatality` (0xC78C8F06: AI `S+0x4E0`, human sticky RB + the same zone test, and power > 0.15) in the swing-category rule list (`fn_886AFDF8` -> `fn_88697E98`, data at Settings file ~0x2AC00, category `0x1EB396F9`). `ReqVolleyRepos` is also read by the side filter `fn_8869A520 +0x210`. Serve & volley uses `S+0x4E0`; its human writer was not found (AI: `fn_886825A0`). RB's `@ReqFastRepos` 0x4E2 is read by `fn_8868C218` and `fn_8869B928`, `@Rush` 0x4DD by `fn_8865E430`. LB: `@ReqSpeedSwing` 0x4E1 is read by `fn_8868C660` and `fn_886BB0A8`, and the press edges `@OnRaiseReqBaselineRepos`/`@OnRaiseReqVolleyRepos` (0x4E3/0x4E4) by `fn_8866F9F0`; no reader of the level `@ReqBaselineRepos` 0x4DE was found. So LB is not dead in code even though the manual lists it as N/A (M) |
| 3 | Control / Normal / Power = Finesse / Medium / Powerful by hold time | **Confirmed** (H): < 0.1875 s, 0.1875..0.875 s, >= 0.875 s. The rows differ in template speed (gp4b); power also feeds 25 aiming/control graphs. Error growth with timing per tier is in those graphs (G4b) |
| 4 | Late timing penalised more than early | **Confirmed for the serve** (H, s9.3 table). For groundstrokes the control graphs' timing curves are symmetric in `ManualShotTiming` (graph 188); the TimingValue computation itself is in the TimingState analysers (not traced here) |
| 5 | Volleys ignore charge | **Confirmed for the row** (H): the volley branch (node 30) has no tier test, so the volley row is the same at any hold time. The charge counter still runs and S+0xE00 still feeds the analysers |

## 16. TU1 differences (H)

`orig/54540859/tu1/files/TitleUpdate.arc` (extracted copy in `work/disc/tu1_arc/`):
- `Settings.bin` (334e7e0d): 286,492 B, sha256 `a4d73994...4737`; 27 bytes differ from the disc. The
  left-stick channel axes change from `LeftX/LeftY` to `AnyX/AnyY` (D-pad movement), and one bool is
  inserted near file 0xAAC (a PlayerTuning field shift). The tree, the power curves and the tier graphs
  are unchanged.
- `GameplayInterface.bin` (f26cdc20) is identical (D = 60).
- `Expressions.bin` (sha256 `1351c0b9...909d`) does not parse with `ts4_analyser.py` ("unexpected
  signature"), so TU1 graph changes were not compared.
- TU1 also ships `Swing_DLL.xexp` (a code patch, not analysed) and a new `Layoutall.bin`.
