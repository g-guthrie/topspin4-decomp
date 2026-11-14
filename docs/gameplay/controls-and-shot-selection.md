# Controls and shot selection: from the pad to the chosen shot (agent G2)

This note follows the path from the controller to the shot the game picks. It covers the pad driver,
the data-driven InputMapper, the PlayerState input block, the shot-button latch, the power (charge)
value and its Finesse / Medium / Powerful tiers, the timing inputs, the full shot-selection decision
tree in `Settings.bin`, where the Risky rows go, aim, serve, and how the AI feeds the same path.

It builds on and **corrects** `input-to-shot.md` and `shot-to-template.md` (section 10 lists the
corrections). Values are quoted where they explain behaviour. The full dump is
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
   - LT **or** RT = Risk. A trigger counts as held above 128/255.
   - RB = Rush / fast reposition. LB = speed swing / baseline reposition.
   - Left stick = aim **and** movement. Right stick = advanced serve.
2. **Stroke**. The first held face button is latched (priority Flat > TopSpin > Slice > Lob). When the
   request starts, `fn_8868F178` writes the 12-byte `S.ShotSelection.Request` (S+0x400):
   `IsFlat, IsSlice, IsTopSpin, IsLob, IsRisk, IsPowerful, IsMedium, IsClassicServe, IsAdvancedServe,
   IsSmash, IsWood, IsWoodDown`. **IsSmash** replaces the stroke when the overhead situation flag
   (`S+0x5DA`, Context.IsSmash) is set. (H)
3. **Power** (H for the code, M for the meaning). `power = clamp(F / D, 0, 1.25) / 1.25` (curve `cfg+0x8FC`).
   - `F` = frames from the last ball launch to the moment the planner runs (the swing trigger).
   - `D` = an integer read at run time (U).
   - The result is capped by `S+0x58` (`PSMove.Output.PressAndHold`).
4. **Tiers** (H). Three one-curve analyser graphs read `power` and give
   **Finesse = power < 0.15**, **Medium = 0.15 <= power < 0.70** and **Powerful = power >= 0.70**.
   - Each bool is "graph output > 0.5" (`fn_886872A0`).
   - `fn_886783B0` copies Powerful/Medium into `IsPowerful`/`IsMedium`. Finesse is the "neither" branch of the tree.
   - In frames: Finesse below 0.1875 D, Powerful from 0.875 D, saturated at 1.25 D.
5. **Tree** (H). A 33-node binary tree in `Settings.bin` (walker `fn_8865A938`) tests in this order:
   1. WoodDown, Wood
   2. classic serve (stroke x tier), then advanced serve (stroke)
   3. Smash
   4. baseline: tier x stroke, with Slice+Risk = drop shot
   5. volley: stroke, with Slice+Risk = drop volley

   The leaf names a template row by id.
6. **Risky rows 12-15 and row 34 (DefensiveShot)** (H). The tree cannot reach them. The only way the
   code reaches them is the **DebugConfig shot override** (`fn_8865ED78`: `+0xF57` enabled, `+0x844 == 0`,
   row id at `+0x840`), which is the shot editor's path (`fn_886B1BA0`, `@ShotEditor_Launch` = Start).
   **IsRisk** changes the shot only for Slice (drop shot / drop volley). (H)
7. **Aim** (H). It uses `Stick_Move` (S+0x448/0x44C). depth = min(|stick|, 1). angle = atan2 of the
   stick, with +pi on the mirrored side. The auto-aim mode aims fully at the target unless the ball
   predicted 30 ticks ahead is already within 30 cm of it.
8. **Timing** (H for the code, M for the meaning).
   - `S+0xCF8` = frame the shot button was pressed minus the frame of the last launch.
   - The **GoodTiming** graph takes a signed timing value in -1..1 (ShotContext). Its window is |t| < 0.3 for a
     skill input of 0 and widens to |t| < 0.8 for 1.
   - A **Wood** (frame) shot is forced when |`S+0x544`| >= 0.1 while the controller's wood check is armed.

## 1. Provenance

| item | value |
|---|---|
| `Settings.bin` (`Core.arc` 334e7e0d) | 286,492 B, sha256 `55cb175dbaf64e30d75f6fe72ae71305a39a39cffca7a2fa3b2e5471431a0167` |
| `Expressions.bin` (`Core.arc` fa94f637) | 581,988 B, sha256 `fd3bc49b44ca4b77deebc58acaefe67763a273538f4901266f949e9ec9dedee9` |
| `Layoutall.bin` (disc root) | 760,816 B, sha256 `67793f5b7dc771f8fde298ef07e8976d9362c864ac577a4c9db6b2bf874788c5` |
| `Swing_DLL.dll` (PE image) | 13,848,064 B, sha256 `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9` |
| tools | Python 3.13.18 (stdlib), capstone 5.0.7 (`work/disc/ppcd.py`), `tools/fn_asm.py` with `TS4_MATCHING_DIR=work/matching-b9`, cc 13.3.0 |
| extractor | `python3 tools/ts4data/shot_tree.py --settings work/disc/core/334e7e0d.bin --expressions work/disc/core/fa94f637.bin --layout work/disc/Layoutall.bin --out data/gameplay/shot_tree.yaml` |
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
| 0x3A8 | `SwingSelection.Request.Power` = 3 bools {? 0x3A8, ? 0x3A9, ? 0x3AA} | Powerful / Medium / Finesse flags (s5) |
| 0x3AC | `SwingSelection.Request.Style` | style hash (PlayerTuning +0x14 or +0x18, handedness) |
| 0x3B0 | `SwingSelection.Output` {Timing, Power, Control, ...} | grade hashes |
| 0x3D4 | `SwingSelection.EvaluationOutputs` {? 0x3D4, ? 0x3D8, ? 0x3DC, ? 0x3E0, ? 0x3E4, GoodTiming 0x3E8, Wood 0x3EC, ? 0x3F0} | rule graph outputs. 0x3D4/D8/DC are the Finesse/Medium/Powerful graph outputs |
| 0x400 | `ShotSelection.Request` (12 bools) | the tree conditions (s6) |
| 0x40C | `InputState.Shots` list `{Id, Raise}` | RELEASE events per shot id |
| 0x418 | `InputState.ShotTriggers` list `{Id, Raise}` | LEVEL (held) per shot id. Read by `fn_8868F178` |
| 0x424 | `InputState.?` (5 bools) | `S+0x424/0x425` select the serve/return hash in the latch |
| 0x429 | `InputState.DPad` {Up, Down, Right, Left} | |
| 0x430 | `InputState.Stick_Aiming` {X, Y} | left stick (filter header 1) |
| 0x438 | `InputState.?` {X, Y} | unmapped by the config |
| 0x440 | `InputState.Stick_MovePolar` {Power, Angle} | left stick polar (movement, InputNotation) |
| 0x448 | `InputState.Stick_Move` {X, Y} | left stick. **Used by aim** `fn_8869C010` |
| 0x450 / 0x460 / 0x468 | `Stick_1` (D-pad x25) / `Stick_3` (right stick x25) / `PolarStick_3` | |
| 0x470 | `InputState.Buttons` {A, B, X, Y, PressA..PressY, ReleaseA..ReleaseY, LB, RB, LT, RT} (16 bools) | levels 0x470..0x473, press edges 0x474..0x477, release edges 0x478..0x47B |
| 0x480 | `InputState.Serve.Classic` {Throw, ?, ThrowFlat, ThrowSlice, ThrowTopSpin, Flat, Slice, TopSpin} | classic serve: toss levels and hit-on-release |
| 0x488 | `InputState.Serve.Advanced` {PolarStick 0x488, CartesianStick 0x490, AnimationSpeedFactor 0x498, SpeedFactor, Amplitude, Precision, ?, ?, ?, bool 0x4B4, Throw 0x4B5, ? 0x4B6, ...} | advanced serve. The four floats are the `State.bin` HUD "Serve" labels |
| 0x4C8 | `InputState.Serve.IsAdvanced` | |
| 0x4D8 | `InputState.Risk` | LT/RT level |
| 0x4D9 / 0x4DA | `InputState.?` | latch "pressed" / "released" event bytes |
| 0x4DB..0x4EA | SpecialShot, SpecialShotDetected, Rush, ReqBaselineRepos, ReqVolleyRepos, ?, ReqSpeedSwing, ReqFastRepos, OnRaiseReqBaselineRepos, OnRaiseReqVolleyRepos, InvertPaddle, RequestChallenge, ShotEditor_Launch, ShotEditor_Reset, AskNext, AskPrevious | |
| 0x500 | `Context.ShotContext` (0x80) | 0x544 = signed timing value (s7). 0x560 IsHuman. **0x574 ModeBaseLine** (tree `IsBaseLine`). 0x575 IsSmash |
| 0x5D8 / 0x5D9 / 0x5DA | `Context.IsServing` / `Context.IsVolley` / `Context.IsSmash` | serve situation, volley mode, overhead situation |
| 0xA40 | `?` (0x440) containing `TimingState` (0xCE0) | `S+0xCF8` = press-to-launch frames. `S+0xD08` = timing value copied to `S+0x544` |
| 0xDFC | `?.{frames:int 0xDFC, Value 0xE00}` | power: frames since launch and power value. Input path `[89408a2f, 82526c5c]` of the tier graphs |
| 0xE04 | `?.{frames 0xE04, Value 0xE08}` | second power value (curve `cfg+0x908/0x920`) |

## 3. Pad and InputMapper (summary; details in `input-to-shot.md` s1-2, values in the YAML)

- **Driver** `fn_888854B0` (H). Digital buttons give 0/255 and triggers 0..255. Axes are int16 with
  an invert byte. The records go into a ring at `lbl_88D45B1C+0x234`.
- **Mapper** `fn_88910F50` / `fn_8890DB90` (H).
  - A LEVEL bool is "value != 0", and for LT/RT "value > 0x80". Then `invert` is applied.
  - PRESS/RELEASE take bits 0x40/0x80 of the slot flag word and last one poll.
  - Root `cfg+0x8E0` -> file 0x2C110. Buttons at +0 (11 entries), stick channels at +0xC (3).
  - +0x18/+0x24 are 4 and 3 entries keyed by shot id (not read by the mapper loader, U).
  - Floats 0.55 and 0.8 sit at +0x30/+0x34 (U).
- **Shipped mapping** (H; every output path and its S offset is in `input_mapper` of the YAML):

| control | outputs (S offset) |
|---|---|
| A / B / X | LEVEL `ShotTriggers/Shot[Id]/@Raise` (list 0x418); RELEASE `Shots/Shot[Id]/@Raise` (list 0x40C); LEVEL `Serve/Classic/@Throw<Stroke>` (0x482/0x484/0x483); RELEASE `Serve/Classic/@<Stroke>` (0x485/0x487/0x486); `Buttons` level/press/release |
| Y | the same shot pair for Lob; LEVEL `@SpecialShotDetected` (0x4DC), RELEASE `@SpecialShot` (0x4DB). No Lob serve |
| LT / RT | `Buttons/@LT|@RT`, LEVEL `@Risk` (0x4D8), PRESS `@AskNext` / `@AskPrevious` |
| LB | `@ReqSpeedSwing` 0x4E1, `@ReqBaselineRepos` 0x4DE, PRESS `@OnRaiseReqBaselineRepos` |
| RB | `@ReqFastRepos` 0x4E2, **`@Rush` 0x4DD** (sprint), `@ReqVolleyRepos` 0x4DF, PRESS `@OnRaiseReqVolleyRepos` |
| Start / Back / R-click | `@ShotEditor_Launch`, `@RequestChallenge` (Hawk-Eye challenge), `@ShotEditor_Reset` |
| left stick (dz 0.4) | `Stick_Aiming` x1, `Stick_Move` x1, `Stick_MovePolar` (Power, Angle in +-pi) |
| D-pad (dz 0.4) | `Stick_1` x25, `DPad/@Up..@Right` (threshold 0.5) |
| right stick (dz 0.4) | `Stick_3` x25, **`Serve/Advanced/CartesianStick`** x10, **`Serve/Advanced/PolarStick`**, `PolarStick_3` |

- The stick dead-zone shape and the two header words of each stick item (0x28 or -1) are not decoded
  (U). `ref/gameplay` therefore does not model the stick channel.
- Hold durations are **not** a mapper feature. No item has a timer, and every hold-dependent quantity
  comes from frame stamps (s4, s5).

## 4. Shot request: latch, state machine, Request bytes

- **`ShotInputLatch`** `fn_88679C78` (PC+0x50, H). While nothing is latched it latches the first set
  of `Buttons.A/B/X/Y` (S+0x470..0x473) as Flat/TopSpin/Slice/Lob. Each frame it does the following:
  - `S+0x4D9` = "a shot button is held" and `S+0x4DA` = "the latched button was released".
  - It appends `(S+0x9D4, S+0x9D0)` to the stick ring `S+0x4CC`.
  - It stamps the last frame each of `PressA..Y, ReleaseA..Y` (S+0x474..0x47B) was true at `latch+0x1C..0x38`.
- **Request state machine** `fn_886B3CF8` (H for flow, M for the event meaning).
  - In state `0xAFAF1093`, a held face button (human, `PC+0x10`) starts the request with `fn_88698538`.
    That runs `fn_8868F178` (Request) and `fn_8866B8C0` (timing stamp, s7).
  - In state `0x93E5E96D` it runs one of three analysers (`this+0x328` when `Context.IsVolley`, else
    `+0x3B0`/`+0x36C`). It then requests the swing if any of these holds, using code constant 0.5:
    - `S+0x5DD && S+0x7C4 > 0.5`
    - `S+0x5DF && S+0x7C0 > 0.5`
    - `S+0x5D9 && S+0x5DE && team mode != 2 && S+0x7BC > 0.5`

    After that the timer and `can swing` (vtbl +0x28) are checked.
  - In state `0x658B2E11` (swing running), when the controller's vtbl slot +0x34 returns true, it runs
    `fn_886783B0` and then the planner **`fn_886B0490`**. The planner computes power and the tier
    flags, rebuilds the Request and walks the tree.
  - With no button, the **auto swing** sets `Raise` on every ShotTriggers entry whose Id is Flat (`+0x5E0`).
- **`fn_8868F178`** (H; correction below).
  1. It takes the first entry of **`InputState.ShotTriggers`** (S+0x418, the LEVEL list) whose
     `Raise` is 1, and stores its Id at `PC+0x3C`. **Smash replaces it when `S+0x5DA`** is set.
  2. It clears S+0x400..0x40B.
  3. It sets IsFlat/IsSlice/IsTopSpin/IsLob/IsSmash from the id and `IsRisk = InputState.Risk`.
  4. It calls `fn_8865ED78` (tree walk).
  5. If the chosen row id is `DropShotNormal` (c47dfdc1) or `DropVolley` (8ff66130), it sets
     `PC+0x3C = crc32("DropShot") = 0x990377A5`.
- **`fn_886783B0`** (H). It copies a 0x40-byte block from the scratch ball into `S+0x500`. Then it sets
  `IsPowerful = S+0x3A8` and `IsMedium = S+0x3A9`, and sets the Smash id again when `S+0x5DA`.
- **Command copy** (`fn_886B5128 +0x44C`, H). When `*(PC+0x40)` is set (a recorded or remote command),
  it copies the command bytes into the state: C+0x99 -> IsVolley, C+0x98 -> IsSmash,
  C+0x9A -> **IsPowerful**, C+0x9B -> **IsRisk**.

## 5. Power (charge) and the Finesse / Medium / Powerful tiers

Code (H, `fn_886B0490 +0x16C..+0x2A8`, store of `S+0xDFC` at `+0x1A0`, `fn_8869D720`, `fn_881899D8`):
```
F = match_clock(+0x310) - rally(+0x68)        // S+0xDFC; rally+0x68 is written with the clock by
                                              // fn_886AD278 when a ball is launched (last hit)
x = F / D                                     // D = int *(*(PC+0x48)+0x44)            (U: value)
S+0xE00 = curve16(alt ? cfg+0x914 : cfg+0x8FC)(x)   // alt = fn_8868F0D8(0x82E4BF1A)  (U: which state)
S+0xE08 = curve16(alt ? cfg+0x920 : cfg+0x908)(S+0xE04 / D)
human path:  S+0xE00 = min(S+0xE00, S+0x58)   // PSMove.Output.PressAndHold
AI path:     S+0xE00 = min(previous S+0xE00, new value)
curve16 key {x0,x1,y0,y1}: y = y0 + clamp(x-x0, 0, x1-x0)/(x1-x0) * (y1-y0)   (a true ramp)
```

Data:
- `cfg+0x8FC` and `cfg+0x914` are both `[0..1.25 -> 0..1]`, so **power = min(F/D, 1.25)/1.25**.
- `cfg+0x908` = `[0..1 -> 0..1]` and `cfg+0x920` = `[0..0.9 -> 0..1]`.
- `cfg+0xC70/0xC74` = 0.4 / 0.7. The 0.7 is also the Powerful edge below. `fn_886B5128 +0xC10` tests
  `S+0xE00 > cfg+0xC74` for the "powerful ball" flag of the incoming-ball descriptor.

Tier rule (H):
1. `fn_886872A0` runs the analysers at controller `+0x108/+0x14C/+0x190/+0x2E4`. These are the rule
   graphs that write `SwingSelection.EvaluationOutputs`.
2. It then sets `Power[0] (S+0x3A8) = out(0x3DC) > 0.5`, `Power[1] (0x3A9) = out(0x3D8) > 0.5` and
   `Power[2] (0x3AA) = out(0x3D4) > 0.5`. The test is the sign bit of `0.5 - x`, so it is strict.
3. `fn_886783B0` copies the first two into IsPowerful/IsMedium.

The graphs (`Expressions.bin`, all keys with slope 0, so the G1 step/ramp question does not change them):

| graph (index) | input | curve | output cell | meaning |
|---|---|---|---|---|
| `Finesse` d0cb6659 (163) | PlayerState `[89408a2f, 82526c5c]` = S+0xE00 power, cell 107 | 1 on [0, 0.15), 0 on [0.15, 1] | 259 (EvaluationOutputs) | Finesse |
| `Medium` c1df4081 (164) | same | 0, 1 on [0.15, 0.7), 0 | 260 | Medium |
| `Powerful` 912faaa2 (165) | same | 0 on [0, 0.7), 1 on [0.7, 1] (flat beyond) | 261 | Powerful |
| `PowerfulBall` 729975e2 (169) | `[89408a2f, c7b7bdac]` (hit-point block) cell 72 | 0 below 15, 1 from 15 | 264 | fast incoming ball, reward class |
| `GoodTiming` cfdbd245 (178) | ShotContext cell 109 (signed -1..1) and a SkillList link | lerp(1 if \|t\|<0.3, 1 if \|t\|<0.8; skill) | 273 | timing window (s7) |
| `Wood` 9cafb633 (180) | TimingState (twice), cell 17, ShotContext 2cd48361, fatigue | product of two curve branches | 275 | frame-shot likelihood output (EvaluationOutputs.Wood) |

So: **Finesse when power < 0.15, Medium when 0.15 <= power < 0.70, Powerful when power >= 0.70**.
In units of D frames after the opponent's launch, that is Finesse below 0.1875 D, Medium from 0.1875 D
to 0.875 D, and Powerful from 0.875 D. Power saturates at 1.25 D.

What this means for play (M):
- Power grows with the time between the opponent's hit and the moment the planner runs. The planner
  runs when the swing controller reports its trigger (state `0x658B2E11`, vtbl +0x34). So a later
  trigger gives more power.
- If D is the expected flight time to the contact point, holding the button until near contact
  gives Powerful and an early, short press gives Finesse.
- D's value and the exact trigger event (release vs. animation point) need a runtime read (s11).
- Nothing in code scales ball speed by power. The tier only picks the template row (gp4b,
  shot-to-template s7).

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
unresolved hashes. The full node table with file offsets is in `data/gameplay/shot_tree.yaml` (`tree_nodes`).

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
Risk button picks the drop shot and is counted (`team+0x3C4`).
Retune lever: re-point any leaf id (4 bytes at the leaf record) to `4708429a`, `dba7dd53`, `8c2d5a8e` or
`de481349` to make a Risky row selectable, for example `IsRisk` under TopSpin/Flat/Lob. That needs new
nodes, because the tree only branches on Risk under Slice.

### 6.2 Who sets each Request byte in normal play

| byte | writer | confidence |
|---|---|---|
| IsFlat/IsSlice/IsTopSpin/IsLob/IsSmash | `fn_8868F178` from the first held ShotTriggers entry. Smash if `Context.IsSmash` | H |
| IsRisk | `fn_8868F178` = `InputState.Risk` (LT/RT). Command copy `C+0x9B` | H |
| IsPowerful / IsMedium | `fn_886783B0` from the power graphs. Command copy `C+0x9A` (IsPowerful only) | H |
| IsWood | `fn_886B0490` entry: if `*(PC+0x78)+0x431` is armed and `S+0x544 >= 0.1` or `<= -0.1` (constants `+0x2AC/+0x474`), clear the arm and set IsWood. `S+0x544` gets `TimingState+0xD08` at swing start (`fn_886B3CF8 +0x8A8`, `+0x95C`) | H for code, M for "timing error" |
| IsWoodDown | planner `fn_886AE528 +0x6BC..+0x760`: set when the planned target point (`r15`) is on one side (`x < 0`) and within a squared radius `obj+0x7EC` of a reference point, then the tree is walked again | M (geometry L) |
| IsClassicServe / IsAdvancedServe | no literal store except zeroes and the shot editor. They are bound to the condition objects by path, so the serve module must write them through the XData binding | U (s11) |
| IsBaseLine (ModeBaseLine S+0x574) | no literal store found. gp8: `fn_8866DF60` sets the Volley/Baseline zone hash `S+0x394` from PlayerTuning boxes. The ModeBaseLine byte itself is written through data binding (a ShotContext analyser) | M |

## 7. Timing

- **Press stamp** (`fn_8866B8C0`, H). `S+0xCF8` (TimingState) = `latch.stamp[PressA..PressY of the
  held button] - rally+0x68`, as float frames. It is the frame the button was pressed, counted from
  the opponent's launch.
- **Signed timing value** (M).
  - `S+0x544` (ShotContext `38453afd`) is set from `TimingState+0xD08` at swing start. The `PSMove`
    graph also writes it, for the Move controller.
  - Its range is -1..1, per the GoodTiming and Wood curves.
  - **GoodTiming** = 1 when |t| < 0.3 (skill 0) up to |t| < 0.8 (skill 1).
  - **Wood** (frame shot) triggers at |t| >= 0.1 when the wood check is armed. The arm byte `+0x431`
    of `PC+0x78` was not traced.
- **Hit-quality grade** (gp2 6.4, H). It is rolled once per commit by the analyser at `brain+0x19C`
  from distance, a random number, ball+0x68 and ticks:
  - `S+0x3A0 = out < 0.5 ? Bad : Good`
  - `S+0x3A4` = Bad / Medium / Good at 0.33 / 0.66
- **Five-level factors** (gp8 2.2). VeryGood 1, Good 0.75, Normal 0.5, Bad 0.25, otherwise 0
  (`fn_8865AC08`). `S+0x3B4/0x3B8` are only ever set to Good in this build.
- No code compares the press time with the ball arrival. That comparison happens inside the TimingState
  analysers (`BaselineTimingAbility`, `VolleyTimingAbility`, `39CFDEBA`; analyser-graphs.md s6.2).

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

## 9. Serve

- **Classic** (H for the inputs, M for the flow). A/B/X LEVEL drive `Serve.Classic.Throw<Stroke>`
  (toss while held), and RELEASE drives `Serve.Classic.<Stroke>` (hit on release). `Serve.Classic.Throw`
  (S+0x480) is the generic toss flag.
  The tree then picks a classic-serve row by stroke x tier: 3 kick, 3 slice and 3 flat rows. The tier
  uses the same power and tier graphs (s5), so serve power is timing-derived too (M).
- **Advanced.** The right stick gives `Serve.Advanced.PolarStick` (Power, Angle) and `CartesianStick` (x10).
  The block also holds `AnimationSpeedFactor, SpeedFactor, Amplitude, Precision` (S+0x498..0x4A4), which
  are the `State.bin` HUD "Serve" quantities, written by a ServeComponents analyser (U). `Advanced.Throw`
  (S+0x4B5) is the toss. Tree: one row per stroke, no tiers (rows 29..31).
- **Toss choice for the AI** (`fn_886825A0`, H). It copies a 0x40-byte command block (`obj+0xF8 ->
  +0x1FC`), then evaluates it (`fn_886821A0`) and writes:
  - `Advanced.Throw = block[+0x20] > 0.5`, with `Classic.Throw` the opposite. The same goes for the second
    pair `0x4B6/0x481`.
  - It clears `SwingSelection.Request.Power` and copies the style.
  - `ReqVolleyRepos`/`S+0x4E0 = block[+0x10] > 0.5`.
  - `S+0x66C`, `S+0xD88/0xD8C` = block floats.

  So the AI serves through the same InputState fields.

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
| power curve | 0..1.25 -> 0..1 (ramp) | `cfg+0x8FC/0x914` | data |
| tier edges | 0.15 / 0.70 | graphs Finesse / Medium / Powerful | data |
| powerful-ball edge | 0.7 (`cfg+0xC74`), 0.4 at `cfg+0xC70` (U) | `fn_886B5128 +0xC10` | data |
| divisor D | int `*(*(PC+0x48)+0x44)` | `fn_8869D720` | runtime, **U** |
| press-and-hold cap | `S+0x58` | `fn_886B0490 +0x1BC` | data or graph (PSMove), U on 360 |
| wood timing edge | abs(t) >= 0.1 | `g_ts4_script_constants+0x2AC/+0x474` | code |
| GoodTiming window | abs(t) < 0.3 .. 0.8 by skill | graph `GoodTiming` | data |
| auto-aim distance | 30 (cm) | `g_ts4_script_constants+0x42C` | code |
| stick dead zone | 0.4 | InputMapper channels | data |
| aim mirror | pi | `lbl_880C88DC` | code |

## 12. Open items

1. **D and the trigger event.** Read the int at `*(*(PC+0x48)+0x44)` and the frame at which
   `fn_886B0490` runs, relative to the button release, under Xenia. Also find what `fn_8868F0D8(0x82E4BF1A)`
   tests: it selects the alternate power curves, which are identical in retail data.
2. **IsClassicServe / IsAdvancedServe / ModeBaseLine writers.** They are bound through XData. Trace the
   serve module's binding (the per-node condition objects at `PC+0xA0` are pointers into S; a write
   breakpoint on S+0x407/0x408 under Xenia would settle it).
3. **Names.** The hashes of `Power[0..2]` (19e5a8dd / 4eb93f3d / 1293ff81) and of the EvaluationOutputs
   fields at 0x3D4..0x3DC are unresolved. The cell-to-field order fits Finesse/Medium/Powerful (cells
   259..261 -> 0x3D4..0x3DC), which is consistent with the code's Powerful=0x3DC, Medium=0x3D8.
   Also unresolved: `S+0x4D9/0x4DA`, the serve leaf ids, and the ShotContext timing field `38453afd`.
4. **Arms and tests.** The wood arm `*(PC+0x78)+0x431` and the IsWoodDown geometry (`obj+0x7EC`) are not traced.
5. **Stick channel.** The dead-zone shape and stick-item header words; the `+0x18/+0x24` shot-keyed
   blocks of the mapper root.
6. **PSMove graph.** On Xbox, is `S+0x58` ever below 1, and does the `PSMove` graph run at all? If it runs,
   it writes `S+0x544` too.
7. **Analyser-to-field table.** The cell-to-PlayerState table. Now that the schema is decoded, analyser
   port paths (domain + member names) can be resolved directly with `Layout.resolve` instead of cell
   indices. Example: Finesse/Medium/Powerful read `[89408a2f, 82526c5c]` = S+0xDFC.Value = S+0xE00. This
   probably closes the "cell index -> offset" open item of analyser-graphs.md. Handed to G1/G5.

## 13. Corrections to earlier notes

| earlier statement | correct |
|---|---|
| `S+0x401` TopSpin, `S+0x402` Slice (input-to-shot s3, s4) | **0x401 = IsSlice, 0x402 = IsTopSpin** (`fn_8868F178` stores; Layoutall) |
| `S+0x470..0x473` are `ShotTriggers` level flags | They are `Buttons.A/B/X/Y`. `ShotTriggers` is the list at S+0x418 |
| `S+0x474..0x477` = Shots release events; `S+0x478..0x47B` = Buttons A/B/X/Y | `PressA..PressY` and `ReleaseA..ReleaseY` |
| `fn_8868F178` reads the `Shots` (release) list | It reads `ShotTriggers` (S+0x418, the level list) |
| aim from `S+0x448/0x44C` "aim stick"; depth = forward component | `Stick_Move`; depth = stick magnitude |
| IsMedium/IsPowerful source `S+0x3A8/0x3A9` "analyser bytes", thresholds unknown | `SwingSelection.Request.Power` = (graph out > 0.5) from the power value; tiers 0.15 / 0.70 |
| `S+0x405..0x408` cleared then "power tiers" | 0x405 IsPowerful, 0x406 IsMedium, 0x407 IsClassicServe, 0x408 IsAdvancedServe, 0x40A IsWood, 0x40B IsWoodDown |
| `S+0x5D9`/`0x5DA` = copies of command bytes | they are `Context.IsVolley` / `Context.IsSmash`; `S+0x5D8` = `Context.IsServing` |
| power curve "power = frac/1.25" over hold time | over frames since the last **launch**, divided by D (s5) |

## 14. Reproduction

```sh
python3 tools/ts4data/shot_tree.py --selftest
python3 tools/ts4data/shot_tree.py --settings work/disc/core/334e7e0d.bin \
    --expressions work/disc/core/fa94f637.bin --layout work/disc/Layoutall.bin \
    --out data/gameplay/shot_tree.yaml           # also writes data/gameplay/shot_tree.tree
cc -std=c11 -Wall -Wextra -Werror -o /tmp/tss ref/gameplay/test_shot_select.c ref/gameplay/shot_select.c -lm
/tmp/tss && /tmp/tss data/gameplay/shot_tree.tree      # synthetic tests, then every Request combination
TS4_MATCHING_DIR=work/matching-b9 python3 tools/fn_asm.py fn_8868F178 fn_886783B0 fn_886872A0 \
    fn_8869D720 fn_886B0490 fn_8869C010 fn_8869BEF0 fn_8866B8C0 fn_8865ED78 fn_886825A0
python3 work/disc/ppcd.py 886AD380 0x20        # rally+0x68 = clock at launch (fn_886AD278)
```
