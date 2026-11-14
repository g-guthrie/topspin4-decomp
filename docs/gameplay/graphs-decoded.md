# Analyser graphs decoded (agent G1)

This file covers the 341 data-driven formula graphs in `Expressions.bin`: how a curve evaluates on the
real game, how each port binds to a game field, who runs each graph, and what the graphs compute.
It builds on `analyser-graphs.md`, which covers the file format, the kernels and the runtime loop. The per-graph
listing is in [`graphs-catalogue.md`](graphs-catalogue.md). Every value is in
[`data/gameplay/graphs.yaml`](../../data/gameplay/graphs.yaml).

Evidence grades: **V** = verified in code or by a measurement in this file, **I** = inferred from data
shape or names, **U** = unknown or guessed.

Inputs used (sha256):

| file | where | sha256 | size |
|---|---|---|---|
| Expressions.bin | Core.arc `0xFA94F637` | `fd3bc49b44ca4b77deebc58acaefe67763a273538f4901266f949e9ec9dedee9` | 581,988 |
| State.bin | Core.arc `0x623D0979` | `ff871577ad82545a26bca27d220e758734093d52b0f3b2f697337408aa1c4aeb` | |
| Settings.bin | Core.arc `0x334E7E0D` | `55cb175dbaf64e30d75f6fe72ae71305a39a39cffca7a2fa3b2e5471431a0167` | |
| Layoutall.bin | disc root | `67793f5b7dc771f8fde298ef07e8976d9362c864ac577a4c9db6b2bf874788c5` | |
| Swing_DLL.dll | `orig/54540859/` | `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9` | |

Disassembly was done with capstone 5.0.7 (PPC32 big-endian, skipdata); the repository helper is `work/disc/ppcd.py`.

## 1. Headline

1. **Curves are piecewise-linear ramps (V).** At load time the game overwrites every CURVE key's slope
   word with `(y1 - y0) / (x1 - x0)` (`fn_88179740`). The `0.0` slopes stored on disc are never used. The
   "steps or ramps" question in `analyser-graphs.md` section 4 is answered: **ramps**.
2. **Every port is bound to a named struct member and byte offset (V).** Port cell indices go through a
   307-entry cell table at `State.bin` root `+0xF58`. The `Layoutall.bin` type tables then name the member.
   All 341 graphs resolve, except graph 22, which has two out-of-range cells.
3. **Runners (V).**
   - 55 graphs are loaded by a literal hash in code.
   - 246 more are referenced only from `Settings.bin`: the AI difficulty tables, the 33-row shot-class
     table and `PlayerSettings`.
   - 40 have no runner found. Some of those are reached through tables that have not been traced.
4. **The shot-error inputs of `gp4b.md` 10.2 come from graphs (V).** `S+0x718` (FaultProbability),
   `S+0x720` (OutcomeNet) and `S+0x71C` (LetProbability) are graph outputs. FaultProbability and OutcomeNet
   come from one pair of graphs per shot class.
5. **Names.** 46 of 341 graph names are recovered: 35 high, 5 medium and 6 low confidence. 787 member and
   graph names are listed with confidence in `data/gameplay/analyser_names.json`.

## 2. Curve semantics (V)

### 2.1 Key layout

Each key is `0x14` bytes: `{f32 x0, f32 x1, f32 y0, f32 slope, f32 y1}`. On disc `slope` is `0.0` in
all 9,124 keys, and `+0x10` holds the segment's end value `y1`.

### 2.2 Load-time fixup

```
fn_886BC568 (PlayerCtx init)
  -> fn_88690920            builds the graph list PlayerCtx+0x9C from PlayerCtx+0x70
     -> fn_8890DFC8(entry, def) for every GraphDef: entry+4 = def; for each node whose type is
                                CURVE 0x993894C6 (lis/ori at 0x8890E014), bl fn_88179740(record) at 0x8890E030
        -> fn_88179740(record): for every key k
               d = x1 - x0;  k.slope = (d == 0) ? 0 : (y1 - y0) / d
```

The fixup loop in `Swing_DLL.dll` points `r11` at `key+0x10` and uses negative displacements, which is why
an earlier scan for a `+0xC` store relative to the key start missed it:

```
88179780  addi  r11, r10, 0x10        ; r11 = &key.y1
8817978C  lfs   f0, -0xc(r11)         ; x1
88179790  lfs   f12, -0x10(r11)       ; x0
88179794  fsubs f0, f0, f12           ; d = x1 - x0
88179798  fcmpu cr6, f0, f13          ; d == 0.0 ?
881797A0  fmr   f0, f13               ;   slope = 0
881797A8  lfs   f12, 0(r11)           ; y1
881797AC  lfs   f11, -8(r11)          ; y0
881797B0  fsubs f10, f12, f11
881797B4  fdivs f0, f10, f0           ; slope = (y1 - y0) / d   (single precision)
881797B8  stfs  f0, -4(r11)           ; key+0xC = slope
881797BC  addi  r11, r11, 0x14        ; next key
```

`PlayerCtx+0x70` is `body + rel` of the server object made by registry hash `0x3419C748` (vtable `+0x4C`).

`fn_889B4C10` also calls `fn_8890DFC8`, for graphs `0x54F0F0FB` and `0xE99E34D2`. Those graphs are not in
`Expressions.bin`; they come from another module whose `entry+0x200` must equal crc("Expressions")
`0xEA4D401C`.

### 2.3 Evaluation

The evaluator `fn_8817A688` picks the last key with `x0 <= x` (the first key if there is none). It clamps
`t = x - x0` to `[0, x1 - x0]` with two `fsel`, then returns `fmadds f1 = t * slope + y0` at `0x8817A754`.
On the real game:

```
value(x) = y0 + (y1 - y0) * clamp((x - x0) / (x1 - x0), 0, 1)      for the selected key
```

So each key is a ramp `y0 -> y1` that holds `y1` past `x1` and `y0` before `x0`. Gaps between keys hold the
previous key's `y1`. Overlapping or decreasing x ranges jump at the next key's `x0`. Flat keys such as
`[0..0.15: 1->1 | 0.15..1: 0->0]` (graph `Finesse`) are how the designers wrote steps.

The data supports this reading. In 4,095 of 5,174 adjacent key pairs, `y1` equals the next key's `y0`, and
677 last keys ramp to `y1 = 0` from a non-zero `y0`. Under the step reading, single-key curves such as
`[0..1: 0->1]` would be constants and many stat inputs would have no effect.

### 2.4 Other curve users

- **Template curves.** `fn_8867BB78` applies the same fixup to the 8 curve slots (type `0xF9F12A60`) of the
  0x8C-byte records reached via `r3+0x6C -> +8`. It is called from `fn_886BC568 @0x886BC60C` and
  `fn_886900E8 @0x88690180`. This covers the shot/ball template speed curves. **`tools/ts4data/templates.py`
  (G3) currently assumes steps** and should switch to ramps. That file is not edited here.
- **Other evaluators.** `fn_888AB6C8` and `fn_889C1868` evaluate other `0xF9F12A60` curves by calling
  `fn_8817A688` directly. Whether those keys are fixed up first is **open** (U).
- **No second fixup.** A scan of every `fdivs`/`stfs` within a `0x14`-stride loop found this one fixup in
  `Swing_DLL` and none in `Loader_DLL`.

### 2.5 Tools

- `tools/ts4_analyser.py` uses the runtime reading by default (`fixup_curves`, `slope_fixup`). Pass
  `--disc-slopes` (or `parse_expressions(buf, fixup=False)`) for the stored words.
- `tools/ts4_analyser_patch.py` accepts a `y1` key field. **To retune a curve, patch `y1`; a patched
  `slope` is recomputed at load and has no effect on the game.** `--disc-slopes` / `fixup=False` keeps
  the old evaluation.

## 3. Binding: from a port to a game field (V)

A port is `{domain key, path hashes, cell index}`. `fn_8817A4F0` resolves a port with `idx >= 0` to:

```
ptr = cellTable[idx] + pool_base(handle.pool + 0x24) + handle.offset
```

`cellTable` is a self-relative u32 array. `ctx+0x10` is the State root `+ 0xF58`. This is set by
`fn_8868F480` at `0x8868F518` (`stw r7, 0x340(r30)` with `ctx = player + 0x330`), and the same assignment is
at `fn_886B6448 +0x98`. The domain handles are appended by `fn_8890ED60` (`{handle, key}`) in `fn_8868F480`
and `fn_886B6448`. The domain picks which object the cell offset applies to. A port with `idx < 0` is a
link resolved by name, through `fn_88610a48` (child lookup by name).

The cell table holds 307 u32 entries. For PlayerState domains, the entry is an offset inside the 0x1070-byte
PlayerState element. Code anchors that agree: cell 276 -> `0x71C` (let chance, `gp4b.md`), cells 51/52 ->
`0x7A0/0x7A4` (ShotDifficulty inputs), and Profile Serve..Stamina at `0x64C..0x668`.

### 3.1 State.bin root (type `0xB77BBB90`, file offset 0x24)

| root offset | member | type (size) | meaning |
|---|---|---|---|
| +0x000 | `57a6f54c` | 34520bab | |
| +0x0C0 | MatchState | 72b1c1a1 (0x340) | |
| +0x400 | BallState `d9e063b8` | MainBallState 6fee4245 (0x540) | |
| +0x940 | `659b335f` | 6fee4245 | second ball state |
| +0xE80 | list of PlayerState | 502fe79d -> element 25fcd125 (0x1070) x4 | |
| +0xE8C | list of `D7C700B9` | 0x274 x4 | per-player AI record |
| +0xE98 | list of TeamState | 9ef5c521 (0xC0) x2 | |
| +0xF58 | cell table | 307 x u32 | |

### 3.2 Domain map (V for the registration, I for some labels)

| domain key | object | notes |
|---|---|---|
| PlayerState | own PlayerState element `S` | |
| `3BA3D582` | opponent's PlayerState | player index = (this - base) / 0x3D0; teams {0,2} and {1,3} |
| `A2AA8438` | opponent's partner | |
| `56B5B281` | partner | |
| Context | `S.Context` (S+0x4F0, type 64efba3a) | |
| ShotContext | `S.Context.ShotContext` (S+0x500) | |
| `8448B811` | `S.44B8753C` (S+0x880) | |
| `3237FFAC` | `S.89408A2F.2906F362.FBDD21BC` (S+0xB80) | reachability scores |
| MatchAnalyser | S+0xF80 | |
| BallState | State + 0x400 | |
| MatchState | State + 0xC0 | |
| TeamState | own team | |
| `E9CA839C` | AI record (D7C700B9) | |
| ShotComponents | AI + 0x23C (ee0f0a46, FinalShotComponents) | |
| ServeComponents | AI + 0x1FC (7a5e9f81) | |
| RepositioningComponents | AI + 0x1E0 (38f589f1) | |
| PositioningComponents | AI + 0x1D0 (aef32f14) | |

### 3.3 Key PlayerState fields written or read by graphs

| S offset | member | written by |
|---|---|---|
| 0x010..0x01C | `9c11fa39.ControlValues` | intermediate values the shot-class graphs export (0x10 power mix, 0x14/0x1C aiming mix, 0x18 fault mix) |
| 0x3D4..0x3F0 | `SwingSelection.EvaluationOutputs` | rule graphs (Finesse, Medium, Powerful, GoodTiming, Wood, ...) |
| 0x620..0x63C | `Profile.3B91D48C` | raw ratings 30..100 (Serve, Return, FH, BH, Volley, Power, Speed, Stamina); input to DefaultAttributes |
| 0x64C..0x668 | `Profile.Serve..Stamina` | DefaultAttributes (0..1 per stat) |
| 0x718 | `7e28dbc0.FaultProbability` | the fault graph of each shot class |
| 0x71C | `LetProbability` | LetProbability |
| 0x720 | `OutcomeNet` | the net graph of each shot class |
| 0x724 / 0x728 / 0x72C | `fd4a76f0` / `d9a8add8` / `e6d62656` | graphs 280-282 / 289-291: wood (frame) up / down / side chances |
| 0x774 | `07902e50` | graphs 241/242/246/247 (curve of PowerfulFactor), serve power graphs |
| 0x778 | `PowerfulFactor` | power graph of each shot class, then graph 198 |
| 0x7DC | `e4f01642` | graphs `E4F01642` (8) and `46c7bb5f` (7) |
| 0xD0C | `TimingState.TimingAbility` | BaselineTimingAbility, VolleyTimingAbility, `39cfdeba` |
| 0xD78 / 0xD88 / 0xD8C | `AimingState` DeepDeviation / Efficiency / OutEfficiency | aiming graph and fault graph of each shot class |
| 0xF20..0xF7C | `Fatigue.Input` / `Fatigue.Output` | fatigue graphs; `CurrentVigor` S+0xF54 is read by 112 graphs |

### 3.4 Layoutall.bin

`tools/ts4_layout.py` is a thin wrapper around G5's `ts4_xbin.Layout`, which handles all four member
kinds: inline, list, pointer and reference. The wrapper adds `resolve(types, type, offset)` (offset ->
member chain) and `walk(...)` (visit every primitive in a data XBin, following lists). An earlier scan-based
reader found 3,022 types. `ts4_xbin` finds 3,642, and it also finds 12 more Settings references to graphs.

## 4. Who runs each graph

### 4.1 Code loaders (V, 55 graphs)

Each loader passes a literal hash to the graph lookup at the address given.

| loader | graphs (index name) |
|---|---|
| fn_886B62E0 @0x886B6320 | 0 `36bde5fe` (writes `8448B811.FinalScore`) |
| fn_886B7048 | 41 BaselineTimingAbility, 40 `39cfdeba`, 42 VolleyTimingAbility |
| fn_886B7A60 | 181 LetProbability, 182 LetSettings |
| fn_886BACC0 | 26 `c4b26668`, 30 `661a3f2c`, 27 `39968a9e` |
| fn_886BB6E0 | 116 RepositioningPointSingle??, 20 `fc7f3d8a`, 17 SwingSpeedCoef, 37 VolleySpeedCoef |
| fn_886BB828 | 6 `d5b5624b` (TeamState.RepositioningState), 33, 32, 31 |
| fn_886BBC38 | 5 `daf1c0d6` (court context), 9 `9c8607a7` (ProfileFactor = Serve * vigor) |
| fn_886BC1E0 | 10 FatigueIngame, 12 `80ce1a10`, 11 ErrorMissFatiguePenalty??, 14 Vivacity, 13 FatigueConst |
| fn_886BCDA8 @0x886BCE64 | 8 `E4F01642` (planner +0x104) |
| fn_886BDB58 | 166 Volley, 16 IsTired, 38 InputFiltering, 39 `daf2ecbd` |
| fn_886BE1C8 | 18 RushSpeedCoef, 24 ShotDifficulty, 25 ShotEfficiency?, 196, 183, 184 DiffAttributesGain??, 185, 186, 187 |
| fn_886BF598 | 163 Finesse, 164 Medium, 165 Powerful, 170 HighTopSpin, 169 PowerfulBall, 179 AutoSwing, 174 AutoVolleySwing, 173 GoodVolleySwing, 175, 176, 177, 180 Wood, 168 PerfectShot, 171 ReturnServeZone, 172 VolleyZone, 19 `c0150160`, 178 GoodTiming |

Call addresses for each graph are in `CODE_LOADERS` in `tools/ts4_analyser.py` and in `loaded_by_code` in
`graphs.yaml`.

Indirect loads take the hash from data rather than code: `fn_886B4700` (via `PlayerTuning+0x63C`), the
`fn_886a0ec8` objects, `fn_886B7AF0`, `fn_886B7178` and `fn_886B6348`.

### 4.2 Settings.bin references (V for the paths, I for the AI usage)

`tools/ts4_analyser.py --settings` walks `Settings.bin` through the layout and reports every u32 field that
equals a graph name. Some hits are coincidences: an `Id` that happens to equal a graph name, such as the
surface "Wood" or a "ReturnServe" tutorial step. The structural tables are:

- **AI.** `AI.AISettings(99d2ac4e).51b273d0.AIStyle(63199a64)[9].Difficulty[]` has one entry per level, with
  `Id` = VeryEasy, and so on. Each Difficulty has five behaviour lists: `f8bde3bf` (rally), `0a7a82d5`
  (return), `2693de78` (serve), `ef9ce04a` (repositioning) and `0b4e23b3` (positioning).
  - Each list is `.af3d703d[]` of `{Expression, ExpressionComponents, #782f2ee9 weight, Default, #ee04af9f}`.
    `Expression` is a **score graph** that writes `E9CA839C.a9a83d2d.91329eea`, the behaviour's score.
    `ExpressionComponents` is a **mix graph** that writes the Shot/Serve/Repositioning/PositioningComponents
    floats of the behaviour.
  - Single graphs per Difficulty:
    - `TimingExpression` (bab5b3f4) writes `ShotContext.ManualShotTiming`, the AI's simulated timing error.
    - `7bcf55ee` writes FinalEfficiency.
    - `714e0b0b` and `39b3b9e2` write the `3237ffac` reachability Score.
    - `6b696700` writes EvaluationOutputs `#4abbb588`.
    - `98fff83e` writes SwingReactionTime.
- **Player setup.** `PlayerSettings(c4eba473).8b92df82.Expr[]` = {DefaultAttributes, `dc1d59b1`}. The
  alternative stat-curve graph `075a2137` is not referenced.
- **Shot classes.** `40dd9ee9.00236a48.8c5e64b4` is at Settings file offset `0x28C04`: 33 entries of 0x18
  bytes `{Element list of links, Id, 3f9c096b aiming graph, 2c3e6b9c power graph}`. Section 5 has the table.

## 5. The shot-class table (V)

Each of the 33 shot classes names an aiming graph and, for the first nine, the power post-graph 198. Its
`Element` list holds, in order:

1. the **net** graph (OutcomeNet S+0x720)
2. the **fault** graph (FaultProbability S+0x718, OutEfficiency S+0xD8C, ControlValues `115e007b`)
3. the three wood graphs 282/291, 280/289, 281/290 (S+0x728/0x724/0x72C)
4. the **power** graph (PowerfulFactor S+0x778, ControlValues `ff506157`)
5. the `07902e50` curve (241/246 for TopSpin classes, 242/247 for the others)
6. for most classes: graph 191 (AimingState `615dc2b6`, an aiming spread in cm, 40..250 by Efficiency)
   and 197 or 199 (AimingState `ffd438ab`)

Serve classes use 306..312 for net and fault and 255..257 for power. The full row-by-row table, with the
duplicate copies written `i/j`, is at the end of `graphs-catalogue.md`.

```
row class               aiming power  net  fault power
 0  SliceFinesse         190   198    279  278   240
 1  TopSpinFinesse       189   198    277  276   239
 2  FlatFinesse          188   198    275  274   238
 3  SliceMedium          204   198    288  287   245
 4  TopSpinMedium        203   198    286  285   244
 5  FlatMedium           202   198    284  283   243
 6  SlicePower           207   198    297  296   250
 7  TopSpinPower         206   198    295  294   249
 8  FlatPower            205   198    293  292   248
 9  TopSpinRisk          210    -     303  302   253
10  SliceRisk            211    -     305  304   254
11  Risk                 208    -     299  298   251
12  FlatRisk             209    -     301  300   252
13  ReturnFlatFinesse    224    -     314  313   258
14  ReturnTopSpinFinesse 225    -     316  315   259
15  ReturnSliceFinesse   226    -     318  317   260
16  ReturnFlatPower      224    -     314  313   261
17  ReturnTopSpinPower   228    -     316  315   262
18  ReturnSlicePower     229    -     318  317   263
19  ServeFlatFinesse     216    -     306  307   255
20  ServeSpinFinesse     217    -     306  307   255
21  ServeFlatMedium      218    -     306  308   255
22  ServeSpinMedium      219    -     306  308   255
23  ServeFlatPowerful    220    -     310  309   256
24  ServeSpinPowerful    221    -     310  309   256
25  AdvancedServe        215    -     312  311   257
26  VolleyPower          231    -     326  325   265
27  VolleyStandard       230    -     324  323   264
28  VolleySlice          232    -     328  327   266
29  VolleyDrop           233    -     330  329   267
30  DropShot             236    -     332  331   271
31  Lob                  237    -     333  334   272
32  Smash                235    -     340  339   273
```

**Duplicate graphs (V).** Six hashes occur twice in `Expressions.bin`:

| hash | indices | same content? |
|---|---|---|
| `04cda578` Inputs | 61 / 146 | identical |
| `fe1d9057` | 242 / 247 | identical |
| `823bd977` | 281 / 290 | identical |
| `bd4552f9` | 282 / 291 | identical |
| `a4273d35` | 241 / 246 | differ: the 0.3 knot is 0.3 in 241 and 0.2 in 246 |
| `7979bb20` | 280 / 289 | differ: 280 adds a vigor factor and its second curve starts at 70 |

Which copy the hash lookup returns (first or last) is **open**.

## 6. What the graphs do (plain language)

All inputs named `Profile.X` are the normalised 0..1 stats unless the name says `3B91D48C` (raw rating).
`HandAttributeQuality` (S+0x74C) is the forehand or backhand stat for the hitting side (I).
`ManualShotTiming` is the timing error in -1..1: negative means early, positive late (I from curve shapes).
Formulas with every key are in `graphs-catalogue.md` and `graphs.yaml`.

### 6.1 Player setup (3)

- **DefaultAttributes** (23, PlayerSettings) maps each raw rating 30..100 to a 0..1 stat with 3-4 ramps.
  For example, Volley is `[30..50: 0->0.2 | 50..80: 0.2->0.8 | 80..100: 0.8->1]`. Ratings below 30 give 0.
- **`075a2137`** (21, unreferenced) is an older variant with gaps at 49/50, 69/70 and 89/90.
- **`dc1d59b1`** (22, PlayerSettings) computes `lerp(Serve, Forehand, 0.4)` and `lerp(Serve, Power, 0.4)` into
  cells 204/205. These resolve to S+0x5AC4/0x5ACC, past the PlayerState size, so the target is another
  object (U).

### 6.2 Fatigue (8, `fn_886BC1E0` and `fn_886BBC38`)

- **FatigueConst** (13) sets per-match constants: recovery-related 1, 10, 5, 180, 30, 5, and
  `lerp(1100, 3300, Stamina) * MatchState.#bc21f307`.
- **FatigueIngame** (10) computes the fatigue cost of a shot or run. It is a stamina-weighted lerp of
  0.2 + multiples of SumAcceleration and SumPowerfulFactor, clamped `[0..100000]`.
- **`80ce1a10`** (12) sets VigorMax `lerp(lerp(0.5, 0.65, Stamina), 1, ramp(#cfd8dd5d 1..5))` and a recovery
  rate `lerp(lerp(40, 80), lerp(100, 200), CurrentRecovery)`.
- **ErrorMissFatiguePenalty??** (11) accumulates a penalty counter from vigor.
- **Vivacity** (14) computes two move-vivacity values from Speed, Return, vigor, Emergency and timing state.
- **IsTired** (16) computes `Fatigue.Output.Tired` from vigor, Return, Emergency and a random gate.
- **`9c8607a7`** (9) computes AimingState ProfileFactor = Serve * CurrentVigor.

### 6.3 Ability and speed (12)

- **BaselineTimingAbility / VolleyTimingAbility / `39cfdeba`** (41/42/40) compute
  `TimingAbility = ramp[0..1: 0->1](HandAttributeQuality)`, with the volley variants on Volley.
- **SwingSpeedCoef** (17) computes an animation swing-speed multiplier `1..1.2`. It is higher near the court
  sides (LocalPosition > 600) and for Speed/Volley, and lower at low vigor.
- **RushSpeedCoef** (18) computes `0.6->1` of Speed plus a vigor penalty, mapped through `[0..1: 0.7->1]`.
  VolleySpeedCoef (37) is the volley variant.
- **InputFiltering** (38) sets two input-filter windows: `lerp(10..30, 20..40)` and `lerp(20..40, 30..50)`
  by Return, blended by vigor.
- **Volley, `daf2ecbd`, `c0150160`, `fc7f3d8a`** compute other movement and swing coefficients. See the
  catalogue.

### 6.4 Shot difficulty, efficiency and let

- **ShotDifficulty** (24) combines curves of BallDifficulty (S+0x764) and `#03d2be3d`/`#5cf9de02`
  (S+0x7A0/0x7A4) by lerp and sum, then inverts the result.
- **ShotEfficiency?** (25) computes `1 - OppShotDifficulty`.
- **LetProbability** (181) computes `S+0x71C = [-10..40: 0.02->0.02 | 40..60: 0.02->0]`. The let chance is 2%,
  fading to 0 as the input goes from 40 to 60.
- **LetSettings** (182) picks the let ball's parameters from a Random: angle 10/25/45, speed lost 0.3/0.5/0.7,
  side angle -2..2, spin lost 0.8.

### 6.5 Per-shot-class graphs (161)

These are the shot-error model. All classes share one template and differ in their curves:

- **Fault graph** (e.g. 278 SliceFinesse). It sums penalties into a 0..1 difficulty `d`, written to
  ControlValues `115e007b`. The penalties come from:
  - ball distance `#7bb6a318.From`;
  - `#03d2be3d` / `#5cf9de02` (the ShotDifficulty inputs);
  - `#1407106c`;
  - vigor;
  - MatchState rally counter `#8beb922e`;
  - SkillList;
  - side/short aim flags `#719dc5ee`;
  - MatchAnalyser pressure terms such as IsGamePoint.

  Next, `d` blends two **timing curves of ManualShotTiming**: an easy pair and a hard pair, mixed by
  HandAttributeQuality. The fault chance therefore grows with timing error, from about 0 at perfect timing
  to 0.1..0.4 at full error, and faster when the shot is hard. That value scales `lerp(ShotSpecific.Min,
  ShotSpecific.Max)`, which comes from the shot template. The results are FaultProbability (S+0x718) and
  OutEfficiency (S+0xD8C).
- **Net graph** (e.g. 279) has the same structure with fewer terms and writes OutcomeNet (S+0x720), the
  share of faults that go into the net.
- **Power graph** (e.g. 240) maps Power, HandAttributeQuality, inside-out, timing curves and the same
  difficulty terms to a 0..1 factor that scales `lerp(ShotSpecific.#033f32d0.Min, .Max)`. It writes
  PowerfulFactor (S+0x778). Graph 198 then adds `curve(AimingState.ffd438ab - 6cf4c076)` for the first
  nine classes.
- **Aiming graph** (e.g. 190) sets:
  - AimingState Efficiency (S+0xD88), which is quantised to 0.2/0.4/0.6/0.8/1 by a flat-step curve;
  - DeepDeviation (S+0xD78) in cm, from 600 down to 0 against a Random, scaled by efficiency and by
    Long/short aim;
  - ControlValues `8f3a95d8`/`665930ed`.
- **Wood graphs** (280-282 / 289-291) set the frame-shot chances to
  `lerp(0, 0.3 (0.2 for down), ramp(#1407106c 60..100))` times the template's `ShotSpecific.WoodUp/Down/Side`
  flag. They also write constants (800 / -1, 0.5 / 800, 1000 / 0).
- **`07902e50`** (241/242/246/247) is a curve of PowerfulFactor `[0..0.3: 0->0.3 | 0.3..0.5: ->0.6 |
  0.5..1: ->1]`. The serve graphs 255..257 compute it from PressAndHold, Serve, Power and SkillList.

Together with `gp4b.md` 10.2 this closes the chain:
`P(error) = clamp01(S+0x718 + S+0x564)`, `P(net | error) = S+0x720`, `P(let) = S+0x71C`.
S+0x564 is `Context.ShotContext.#6906754b`. No graph writes it.

### 6.6 Older error graphs (2)

**`E4F01642`** (8, planner `+0x104`, `fn_886BCDA8`) and **`46c7bb5f`** (7) write **S+0x7DC**
(`7e28dbc0.#e4f01642`), not S+0x718. `E4F01642` is a 14-curve formula over:

- AimingState.Random
- `#1407106c` (S+0x770)
- ManualShotTiming
- CurrentVigor
- `#6fec51bf`
- HandAttributeQuality (S+0x74C)

### 6.7 AI (119)

- **Score graphs** (64, `Expression`) rate a behaviour in about -1..1 from the geometry of the incoming ball:
  - hit position `HitPositionLocal`;
  - ball speed `#8760acf5` 200..600;
  - height `#2f6930a4`;
  - bounce count `#420a6cfc`;
  - own and opponent `LocalPosition`.

  The AI picks the best-scoring entry, weighted by `#782f2ee9` (I).
- **Mix graphs** (55, `ExpressionComponents`) set the chosen behaviour's component weights, again from ball
  geometry and the AI style floats `a9a83d2d.Style.*`:
  - ShotComponents: Slice/TopSpin/Flat/Lob/DropShot, RiskyShot, PressAndHold, FollowToNet, AimingSide L/C/R,
    AimingLength S/C/L;
  - ServeComponents, Repositioning, Positioning.
- TimingExpression, SwingReactionTime, FinalEfficiency and the reachability scores are the per-difficulty
  skill knobs.

### 6.8 Rule graphs (20) and court context (9)

`fn_886BF598` evaluates the rule graphs into `SwingSelection.EvaluationOutputs` (0/1 flags or blends):

- **Finesse / Medium / Powerful** are steps of the power input at 0.15 and 0.70 (G2's tiers).
- **GoodTiming** is `|ManualShotTiming| < 0.3` for low skill and `< 0.8` for high skill.
- **Wood** is a frame shot when the timing state is late and a random draw `ShotContext.#2cd48361` falls
  below `0.2..0.4`, scaled by vigor and hand quality.
- PerfectShot, AutoSwing, AutoVolleySwing, GoodVolleySwing, HighTopSpin, PowerfulBall, ReturnServeZone and
  VolleyZone are similar 0/1 classifiers.

The court-context graphs (5 `daf1c0d6`, 6 `d5b5624b`, 26/27/30-33) write
`ShotContext.BaseLineInterpolator`, `Context.PosVolleyQualifier` and `TeamState.RepositioningState`.

## 7. Names and confidence

Names were recovered by crc32 brute force over:

- strings and tokens from the binaries;
- the repo CRC dictionaries (`work/disc/gameplay/crc_dictionaries.json`);
- a curated gameplay vocabulary (1-, 2- and 3-word camel-case joins);
- names found in the other gameplay docs.

Confidence:

- **high**: the exact string appears in a binary or dictionary, or the name is built into the tool.
- **medium**: a 2-word join, or a pattern confirmed by its neighbours.
- **low**: a 3-word join.

Readable output marks medium names with `?` and low with `??`. `data/gameplay/analyser_names.json` stores
`{hex: [name, confidence]}` and each entry is crc-checked on load.

## 8. Corrections to earlier docs

- `analyser-graphs.md` section 4: curves are ramps, not an open question (section 2 here).
  `analyser-graphs.md` section 6.1: `E4F01642` and `46c7bb5f` write S+0x7DC (`#e4f01642`), not the S+0x718
  error probability. S+0x718 comes from the 31 shot-class fault graphs.
- The raw-rating order in `Profile.3B91D48C` (S+0x620..) and `Profile` (S+0x64C..) is Serve, Return, Forehand,
  Backhand, Volley, Power, Speed, Stamina (Layoutall names, V).
- Graph runners: section 4 replaces the "consumer unknown" entries. 40 graphs remain without a runner.

## 9. Tools, tests and reproduction

- `tools/ts4_analyser.py`:
  - ramps by default and `--disc-slopes` for the stored words;
  - `--state/--layout/--settings` add bindings and runners;
  - `--name-table` defaults to `data/gameplay/analyser_names.json`;
  - `--dump-readable OUT` writes the YAML dump.
- `tools/ts4_layout.py` is the wrapper over `ts4_xbin.Layout` (section 3.4).
- `tools/ts4_graph_catalogue.py` writes `graphs-catalogue.md`.
- `tools/ts4_analyser_patch.py` supports `y1` and the runtime or disc evaluation choice.
- Tests (synthetic data only): `tests/test_analyser.py` (slope fixup, ramps, disc reading, readable dump,
  layout, walk, settings references, name table) and `tests/test_arc_write.py` (patching under both
  readings).

```
python3 tools/ts4_analyser.py work/disc/core/fa94f637.bin --names work/disc/gameplay/crc_dictionaries.json \
  --state work/disc/core/623d0979.bin --layout work/disc/Layoutall.bin --settings work/disc/core/334e7e0d.bin \
  --dump-readable data/gameplay/graphs.yaml
python3 tools/ts4_graph_catalogue.py work/disc/core/fa94f637.bin work/disc/core/623d0979.bin \
  work/disc/Layoutall.bin work/disc/core/334e7e0d.bin docs/gameplay/graphs-catalogue.md \
  --names work/disc/gameplay/crc_dictionaries.json
python3 -m unittest tests.test_analyser tests.test_arc_write
```

## 10. Open items

- **Unknown runners.** 40 graphs have no runner found. Candidates are the indirect loaders (`fn_886B4700`
  via PlayerTuning+0x63C, `fn_886a0ec8`, `fn_886B7AF0/7178/6348`) and data tables not yet walked.
- **Other curve evaluators.** Are the `0xF9F12A60` curves evaluated by `fn_888AB6C8` and `fn_889C1868`
  fixed up? This matters for G3/G4 data. `fn_8867BB78` covers the template records only.
- **Lookup structures.** What `PlayerCtx+0x6C` points to (the `fn_8867BB78` records), and which copy of a
  duplicate graph the lookup returns.
- **Graph 22.** Graph 22 `dc1d59b1` writes cells 204/205, which fall outside PlayerState.
- **Unnamed members.** Many member hashes are still unnamed, for example `#1407106c`, `#03d2be3d`,
  `#5cf9de02`, `#7bb6a318.From`, `#8ea88f9f` and `#07902e50`. Their roles in section 6 are inferred from use.
- **Kernel names.** The kernel type-name preimages are not recovered.
