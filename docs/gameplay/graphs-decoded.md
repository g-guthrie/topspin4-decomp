# Analyser graphs decoded (agents G1, G1b)

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

G1b (second pass) also used `Loader_DLL.dll` (sha256 `e49a53cdca2c1686e46a2514ca77f0736ff90433b477f5f171b0084c10cf5cfa`),
the 1,250 decompressed `Core.arc` members (`work/disc/core_all`, 73 MB), the 56 Title Update #1 archive members
(`work/disc/tu1_arc`), the TU1 package (`orig/54540859/tu1`) and the extracted Lua chunks (`work/disc/lua_amst`).
G1b's results are sections 2.4, 4.3, 4.4, 5 (duplicates), 6.1 (graph 22), 6.9, 7.1, 11 and 12.

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
   - Of the 40 graphs G1 left without a runner, **graphs 1-4 are run by code** (the hit-point scorer,
     section 4.3). **The other 36 are dead data**: their hash occurs in no other file and in no code (G1b).
4. **The shot-error inputs of `gp4b.md` 10.2 come from graphs (V).** `S+0x718` (FaultProbability),
   `S+0x720` (OutcomeNet) and `S+0x71C` (LetProbability) are graph outputs. FaultProbability and OutcomeNet
   come from one pair of graphs per shot class.
5. **Names.** 46 of 341 graph names are recovered by G1: 35 high, 5 medium and 6 low confidence. G1b adds
   50 more member, key and graph names (837 entries in `data/gameplay/analyser_names.json`, section 7.1).
6. **The additive error term `S+0x564` is always 0 (G1b, V).** The PlayerCtx reset `fn_8869DEF0` stores 0.0
   there and clears the forcing flags; nothing else writes it (section 6.9). So
   `P(error) = clamp01(FaultProbability)`. Section 11 walks through the whole shot-error chain.

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
- **Other evaluators (answered by G1b, V).** `fn_888AB6C8` and `fn_889C1868` evaluate the same template curves,
  so they see the fixed-up slopes:
  - `fn_8867BB78` walks the array header at `PlayerCtx+0x6C` `+8`. `PlayerCtx+0x6C` is the body of the
    service `0x91831427`, which is the **`Settings.bin` root** (section 4.4). At `Settings.bin` root `+8` the
    header is `{rel 0x1350, count 37}`, which points at file `0x137C`: the 37 shot-template rows of
    `ball-physics.md` section 1. For each row it fixes the 8 value slots whose type word is `0xF9F12A60`:
    `row+0x18` (primary), `row+0x24` (secondary), and the lo/hi pairs behind the array headers at
    `row+0x30/+0x3C/+0x48` (spin `vertical_a`, `along_c`, `lateral_b`). The bounce tables at `row+0x58..`
    are curve16 records with their own evaluator, so they need no fixup.
  - `fn_888AB6C8(value*, ...)` is the generic "value" reader: type `0x7A330099` -> 2-D table `fn_8826D278`,
    `0xF9F12A60` -> `fn_8817A688`, `0x33799CCE` -> constant. All 11 callers (`fn_888AB7B0` .. `fn_888ACDA8`,
    the per-kind flight planners) pass `ball+0x24` (the selected template row's `tpl`) or `tpl+0xC`, so they
    read the primary or secondary value of a Settings row.
  - `fn_889C1868(ball, blend)` reads `X = ball+0x24` and evaluates the pairs behind `X+0x18/+0x24/+0x30`
    (= `row+0x30/+0x3C/+0x48`, the spin lo/hi curves) at `ball+0x344`, then stores
    `lerp(lo, hi, blend)` into `ball+0x90/+0x94/+0x98`. Callers: `0x889C1A58`, `0x889C1B98`, `0x889C2724`.
  - **Exception.** The template row embedded in `State.bin` (file `0xEC4`, kind `BounceSpeed`, primary
    `[100..1000: 80 -> 120]`, spin-a hi `[50..120: -0.4 -> -0.2]`) is not in that array and is never fixed up.
    If the game ever plans a ball from it, its curves act as steps (`y0`). No code was found that points
    `ball+0x24` at it (U).
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
| 0x724 / 0x728 / 0x72C | OutcomeWoodUp / OutcomeWoodDown / OutcomeWoodSide (G1b names) | graphs 280-282 (289-291 are shadowed copies): wood (frame) up / down / side chances |
| 0x730 / 0x734 | OutcomeLetIn / OutcomeLetOut (G1b names) | no graph |
| 0x780..0x794 | WoodUp/WoodDown/WoodSide `AngleDeviation` and `Distance` (G1b names) | the wood graphs' constants (800 / -1, 0.5 / 800, 1000 / 0) |
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
| fn_886B6348 (array from fn_886B69F8 and fn_8869DEF0, G1b) | 1 `3c58fc77`, 2 `4b5fcce1`, 3 `d2569d5b`, 4 `a551adcd` (hit-point scorer, section 4.3) |
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

### 4.3 The 40 graphs without a runner (G1b)

**Method.** `tools/ts4_graph_refs.py` looks for each graph hash outside `Expressions.bin`:

- as a big- or little-endian word in every decompressed `Core.arc` member (1,250 files), every Title
  Update #1 archive member and the TU1 package, and the Lua chunks;
- as a `lis` + `ori`/`addi` constant (at most 12 instructions apart) in the code of `Swing_DLL.dll` and
  `Loader_DLL.dll`.

A layout walk of every XBin member (`ts4_layout.walk` over `Core.arc` and TU1 members, typed by
`Layoutall.bin`) gave the same answer. The only XBins that hold graph hashes are `Settings.bin`,
`State.bin` and `Module.bin` (`44dc9505`). The non-Core archives on the disc hold no XBin with an
Expressions root (`work/disc/inventory/xbin_types.tsv`).

**Graphs 1-4 run (V).** Graphs `3c58fc77`, `4b5fcce1`, `d2569d5b` and `a551adcd` are built as a 4-word array
with `lis/ori` and handed to the **hit-point scorer**:

- The scorer class has vtable `0x880F4428`. Slot 3, `fn_886B6348(this, hashes[4], ctx)`, looks up each hash
  with `fn_8866F028` (`0x886B637C`) and binds it into `this+8 + i*0x44`. Slot 4, `fn_8867C488(h)`, would load
  the same hash into all four slots. Slot 2, `fn_88692040`, evaluates one of them.
- The array is built in two places:
  - the AI brain init `fn_886B69F8` (`0x886B6A04..0x886B6A50`), for the scorer at `brain+0xD4`;
  - the PlayerCtx reset `fn_8869DEF0` (`0x8869E028..0x8869E0B0`), for the two scorers at `PlayerCtx+0xC0`
    and `+0xC4` (one per candidate side, I).
- `fn_88692040` scores one **BallPrediction sample** (the 0x30-byte record of `gp2.md` section 2). It picks
  graph number `sample+0x28` (the sample's bounce state; `gp2.md` keeps samples with a value of 2 or less) and fills the inputs in `S+0x880..` (domain
  `8448B811`) before it calls `fn_8890E988`:
  - `+0x04` Height;
  - `+0x0C` `#1407106c`, a speed times 3.6 (pool `0x880D1214`), so km/h (I);
  - `+0x10`, `+0x18`, `+0x1C`, `+0x20` from the sample index, the tick difference and the prediction.
  It returns `FinalScore` (`S+0x8CC`).
- So graphs 1-4 rate **where along the incoming ball's path to take the ball**, one graph per bounce
  state. Each is a product of curves: height (best 120..180 cm), `#1407106c` (falls from 1 at 40 to 0 at
  100), and the other three inputs.
- Graph 0 `36bde5fe` (`fn_886B62E0`, vtable `0x880F444C`) is the one-graph sibling. It rates by AvgSpeed and
  Distance.

**The other 36 are dead data (V for the scan, I for "never run").** No data word and no code constant
names them. All 68 callers of `fn_8866F028` take the hash either from a `lis/ori` literal or from a
loaded data record: the AI difficulty record (`fn_886A0EC8`), `PlayerTuning+0x63C` (`fn_886B4700`, the
PlayerSettings `Expr` list), or the lists read by `fn_886B6448`, `fn_886B7AF0` and `fn_886B7CF8`. A
data-provided hash would show up in the file scan. The only way left would be a hash computed from a string
at run time, and no caller does that. Most of the 36 are earlier versions of graphs that do run:

| graphs | what they are | live counterpart |
|---|---|---|
| 21 `075a2137` | old stat curves with gaps at 49/50, 69/70, 89/90 | 23 DefaultAttributes |
| 7 `46c7bb5f` | older error formula writing `S+0x7DC` | 8 `E4F01642` |
| 15 `728e34d8` | tiredness formula using LocalPosition | 16 IsTired |
| 34-36 | TeamState doubles positioning scores (Player1/Player2.Score) | 31-33 |
| 57 `de9da221` (constant 0), 73 `ad039c14` | AI behaviour score graphs | the Settings AI lists |
| 143, 147, 148 | AI PositioningComponents mixes | the Settings AI lists |
| 167 `f5d45ddf` | receiver move value `S+0xDF0` | none |
| 192, 195, 200 | AimingState FinalEfficiency variants | AI `714e0b0b`/`39b3b9e2` |
| 212-214, 222, 223, 227, 234 | serve, return and drop aiming graphs | the aiming graphs in the class table |
| 268-270 | power graphs | the class-table power graphs |
| 319-322 | return net and fault graphs | 313-318 |
| 335-338 | smash and lob net and fault graphs (338 = constant 0) | 333/334, 339/340 |
| 61 / 146 `04cda578` Inputs, 109 `e8ad3080` | empty graphs: no nodes, no ports | none |

`04cda578` is also the hash of the member name `Inputs`. It occurs in `State.bin` and `19ce55a5.bin` only as
that name, never as a graph reference. `tools/ts4_analyser.py` keeps this list as `UNREFERENCED_GRAPHS`.
`graphs.yaml` marks the graphs `unreferenced: true`, and the catalogue says "runs: never".

### 4.4 Lookup structures (G1b, V)

`fn_886BC568` (PlayerCtx init) and `fn_886BC678` make three registry services and store each body pointer
(`server->vt+0x4C`, then `body + *body`):

| service hash | object | body at | file |
|---|---|---|---|
| `0x91831427` | PlayerCtx+0x5C | **PlayerCtx+0x6C** | `Settings.bin` root (type `9B4FB082`): `+8` is the 37-row template array that `fn_8867BB78` fixes up |
| `0x6D6C3329` | PlayerCtx+0x64 | PlayerCtx+0x68 | `State.bin` root (I: the cell table is read from this root) |
| `0x3419C748` | PlayerCtx+0x60 | PlayerCtx+0x70 | `Expressions.bin` graph array (`fn_88690920` builds `PlayerCtx+0x9C` from it) |

The stores are at `0x886BC74C`/`0x886BC784` (+0x5C/+0x6C), `0x886BC75C` and `0x886BC4BC` (+0x64/+0x68), and
`0x886BC590`/`0x886BC5B8` (+0x60/+0x70).

**Graph lookup (V).** `fn_8866F028(PlayerCtx, &hash)` scans `PlayerCtx+0x9C` from index 0 up to the count
`*(PlayerCtx+0x70)+4`. It compares `entry->def +0x28` (the graph name) and **returns the first match**.
`fn_88690920` fills `PlayerCtx+0x9C` in file order: entry `i` gets GraphDef `i` (stride 0x2C, `0x886909B4..`).
So for a duplicated hash, **the lower index wins**. The higher copies are never looked up by hash.

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

**The first copy is the live one (G1b, V, section 4.4).** The game runs 241 (knot 0.3), 280 (with the vigor
factor), 242, 281, 282 and 61. Graphs 246, 289, 247, 290, 291 and 146 are shadowed, so editing them has no
effect. The class table names the hash, not an index, so every class that lists `a4273d35` uses 241.

## 6. What the graphs do (plain language)

All inputs named `Profile.X` are the normalised 0..1 stats unless the name says `3B91D48C` (raw rating).
`HandAttributeQuality` (S+0x74C) is the forehand or backhand stat for the hitting side (I).
`ManualShotTiming` is the timing error in -1..1: negative means early, positive late (I from curve shapes).
Formulas with every key are in `graphs-catalogue.md` and `graphs.yaml`.

### 6.1 Player setup (3)

- **DefaultAttributes** (23, PlayerSettings) maps each raw rating 30..100 to a 0..1 stat with 3-4 ramps.
  For example, Volley is `[30..50: 0->0.2 | 50..80: 0.2->0.8 | 80..100: 0.8->1]`. Ratings below 30 give 0.
- **`075a2137`** (21) is an older variant with gaps at 49/50, 69/70 and 89/90. **Dead (G1b, V):** its hash
  occurs in no other file, no TU1 file, and no code of either DLL (section 4.3).
- **`dc1d59b1`** (22, PlayerSettings) computes the two custom serve attributes (G1b, V):
  - `S.Profile.CustomAttribute[ServePrecision].Value = lerp(Serve, Forehand, 0.4)`
  - `S.Profile.CustomAttribute[ServePower].Value = lerp(Serve, Power, 0.4)`

  How this was found:
  - `Profile` (S+0x5F0, type `07e5954b`) starts with the list `CustomAttribute` (`3b5cf1c2`) of
    `{Id, Value}` (8 bytes).
  - In `State.bin` player 0's list payload sits at element offset `0x5AC0`. Its two elements have
    Id `592daed8` = crc("ServePrecision") and `32c0a57a` = crc("ServePower").
  - Cells 204/205 (`0x5AC4`, `0x5ACC`) are exactly the two `Value` words.
  - The two Id hashes also occur inside graph 22's port path records (`Expressions.bin` `0x80424`,
    `0x80618`, leaf type `0x001A0000` after `Id`), so the ports select the list element by key.

  Caveat (I): the cell offsets are player 0's payload position. Players 1-3 have their payloads at
  `0x10AA4`, `0x1BA94` and `0x26A84` from their elements, so in the file image the raw cell would miss for
  them. Whether the runtime resolves the key or relocates the payload per player was not traced.
  No other graph and no code constant reads these two values (no `lis/ori` of either Id). Their reader is
  unknown.

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
S+0x564 is `Context.ShotContext.#6906754b`. No graph writes it, and it is always 0 (section 6.9), so in
practice `P(error) = clamp01(S+0x718)`.

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

### 6.9 The additive error term S+0x564 (G1b, V)

`S+0x564` is `Context.ShotContext.#6906754b` (float, State.bin default 0.0 for all four players). Its only
writer is the PlayerCtx reset **`fn_8869DEF0`** (PlayerCtx vtable entry at `0x880F4360`). With
`r11 = S + 0x500` (ShotContext), the reset does this (`0x8869E290..0x8869E344`):

```
f31 = 0.0 (pool 0x8814B440), f29 = 1.0 (pool 0x880D0F70), r31 = 0
ShotContext +0x30, +0x40..+0x58, +0x60, +0x64 (= S+0x564), +0x68  = 0.0
ShotContext +0x5C (S+0x55C)                                        = 1.0
ShotContext +0x6C..+0x7D (bytes: S+0x56C..0x57D, which includes the forcing flags
                          S+0x56D "force error", S+0x56E "force net", S+0x572 "force let") = 0
ShotContext +0x60 (S+0x560, IsHuman)                               = r24 ? 1.0 : 0.0
```

The search covered every store in both DLLs:

- `gp8.md` 9.1 already found no store to `0x564/0x56D/0x56E/0x572` relative to the PlayerState.
- A register scan of every `.text` store whose base came from `addi rX, rY, 0x500` or `0x4F0` within 40
  instructions found only the stores above (`tools/ts4_graph_refs.py --stores`, section 12).
- No graph port names `6906754b`. The hash occurs only in `Layoutall.bin`.

So **`S+0x564` is 0 in normal play.** It is a debug or tuning hook that ships unused, and the error
probability is `clamp01(FaultProbability)`.

The same reset clears `S+0x56E`. Its `State.bin` default is 1 for all four players, which would force every
error to be a net error. So the State.bin image is not the live value; the per-point reset is.

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

### 7.1 Names added by G1b

All entries are crc-checked and stored in `data/gameplay/analyser_names.json`. Agent G5b's
`tools/ts4data/names.py` merges that file (`--merge`), so no separate names file was written. Method:
2-word joins over the 1,345-word vocabulary from G5b's `names.json` tokens plus gameplay words; 3-word joins
over a 348-word gameplay vocabulary (C brute force); family searches with a fixed prefix or suffix
(`Wood*`, `Outcome*`, `*ValueIndex`); and the CRC-affine check `crc(P+w) = crc(w) ^ Z_L(crc(P)) ^ Z_L(0)`
for `Coef*` siblings.

| hash | name | conf | where | why |
|---|---|---|---|---|
| `592daed8` / `32c0a57a` | ServePrecision / ServePower | high | CustomAttribute Ids, graph 22 | the graph formulas lerp(Serve, Forehand) / lerp(Serve, Power) |
| `acb75b15` | PSMove | high | graph 187 and member S+0x48 | its ports are PSMove.Swing.MaxSpeed, Preparation.Length, Output.PressAndHold |
| `c0150160` / `fc7f3d8a` | EmergencyPositioning / EmergencyRepositioning | high | graphs 19 / 20 | both write `Context.Emergency` |
| `5b808224` `2f6da855` `34a3a858` `2b157b35` `4d0165be` `f5ec1133` | Wood{Up,Down,Side}{AngleDeviation,Distance} | high | S+0x780..0x794 | 6-way pattern |
| `fd4a76f0` `d9a8add8` `e6d62656` `de3a43e1` `ff02052d` | OutcomeWood{Up,Down,Side}, OutcomeLet{In,Out} | high | S+0x724..0x734 | sibling of OutcomeNet |
| `033f32d0` `032809f7` `528a0451` | Power / Aiming / ErrorResolution | high | ShotSpecific Min/Max ranges | 3-way pattern |
| `c3716fda` `9d6d3bff` `16cacc41` `ef197290` `c81829b9` `9ef21274` | First / Second / Sub / Control / Source / DestValueIndex | high | kernel node members (LERP a/b/t, SUB b, CURVE in, all out) | `*ValueIndex` family |
| `c2ddc2e6` | Behavior | high | Settings `3f7bd49d` lists | 1 word |
| `03996229` | DeviationSystem | medium | AimingState block with DeepDeviation/Random | |
| `1313ce9c` | CurrentTrajectory | medium | BallState+0x0 | |
| `d4df4664` | IncomingBall | medium | TeamState block with NormSpeedInfo | |
| `4e56b470` | PreparedMoveDistance | medium | S+0x75C | 3 words |
| `8dd0fb98` | HeightNotation | medium | S+0x7F0 | sibling of InputNotation |
| `3f7bd49d` `5f0108a7` `20276499` `8c5e64b4` `99d2ac4e` | BehaviorSettings, ShotDef, AnimationFeedback, EvaluateList, AISettings | medium | Settings sections | |
| 14 more | BallToRacket, RandSlot, PlanMatch, ... | low | Settings and S fields | 2-3 word joins, unchecked by context |

`#7afa6edb` (S+0x8A4, also Fatigue.Input) is proven to be a **21-character** name: `crc("Coef" + w)` equals
its sibling `#cbce3218` only for `len(w) = 21`. It is not yet recovered. Still unnamed are
`#1407106c` (role: a speed in km/h, section 4.3), `#03d2be3d`/`#5cf9de02` (run distance in cm / required speed
in m/s, `fn_8868E248`), `#07902e50` (the spin blend `S+0x774`), `#6906754b`, `#7bb6a318` (Commands block
whose `From` is the contact point) and `#8ea88f9f`. Kernel **type** names (CONST, SUM, ...) are not found.
They are not `CAnalyserAgent*` (those strings belong to the FaceGen and animation analyser) or any tried
`Pam::*::C*` form.

## 8. Corrections to earlier docs

- `analyser-graphs.md` section 4: curves are ramps, not an open question (section 2 here).
  `analyser-graphs.md` section 6.1: `E4F01642` and `46c7bb5f` write S+0x7DC (`#e4f01642`), not the S+0x718
  error probability. S+0x718 comes from the 31 shot-class fault graphs.
- The raw-rating order in `Profile.3B91D48C` (S+0x620..) and `Profile` (S+0x64C..) is Serve, Return, Forehand,
  Backhand, Volley, Power, Speed, Stamina (Layoutall names, V).
- Graph runners: section 4 replaces the "consumer unknown" entries. G1b closes the last 40: graphs 1-4 run
  (section 4.3) and the other 36 are dead.
- (G1b) `gp4b.md` 10.2/10.5 and `ball-physics.md` list `S+0x564` as a tuning knob. It is reset to 0 at every
  PlayerCtx reset and has no other writer (section 6.9). The forcing flags `S+0x56D/56E/572` are cleared there
  too.

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

Closed by G1b: the 40 unknown runners (section 4.3), the other curve evaluators (2.4), `PlayerCtx+0x6C` and
the duplicate lookup (4.4), graph 22's target (6.1), `075a2137` (dead), and the writer of `S+0x564` (6.9).
Still open:

- **Graph 22 for players 1-3.** Does the runtime resolve `CustomAttribute[Id]` per player, or does it use
  player 0's raw offset? And who reads ServePrecision and ServePower?
- **ShotSpecific grade.** `ShotSpecific` (S+0x6BC..) is a copy of one grade
  (VeryGood/Good/Normal/Bad/VeryBad) of `Settings` `761fdece.ShotDef[i].9b182896`. The copy code and the
  grade that selects the row were not traced (section 11, step 4).
- **Code-written inputs.** The writers of `#1407106c` (S+0x770), `#be5d458f` (0x768), `#693eedbe` (0x7D8),
  `#aee2d90b` (0x7D0) and `#3c6beee9` (S+0xD84, the serve roll) were not located. `HandAttributeQuality`
  (S+0x74C) has literal stores in `fn_88699xxx`, `fn_886BA254` and `fn_886BD4F0`. Its exact rule (forehand
  or backhand, volley) was not read.
- **The State.bin template row** (2.4) is not fixed up. Is it ever used?
- **Names.** `#1407106c`, `#03d2be3d`, `#5cf9de02`, `#07902e50`, `#7bb6a318`, `#8ea88f9f`, `#6906754b`, the
  21-character `#7afa6edb`, the remaining 291 unnamed graph hashes, and the 11 kernel type names.
- **`fn_889B4C10`** loads graphs `54F0F0FB` and `E99E34D2` from a second Expressions module. No such module is on
  the disc or in TU1, so that path finds nothing in the shipped game (I).

## 11. What decides whether a shot goes in (plain-language walkthrough, G1b)

This section ties `gp4b.md` 10 (the roll), G2/G2b's controls note (`controls-and-shot-selection.md`) and the
graphs together. Grades follow the rest of this file. "I" marks a step whose code was not read end to end.

### 11.1 The one-line answer

Before the ball is launched, the game rolls dice against three per-player numbers that the shot-class
graphs have just computed:

```
P(error)       = clamp01(FaultProbability S+0x718)      (+ S+0x564, which is always 0: section 6.9)
P(net | error) = OutcomeNet S+0x720                     (the rest of the errors go long or wide: Out)
P(let)         = LetProbability S+0x71C                 (0.02, fading to 0 as its input goes 40 -> 60)
```

An "In" shot then still gets the uniform landing spread of the ball block (`gp4b.md` 10.3). The flight
template never adds error. Which numbers go into the dice depends on these steps.

### 11.2 Step by step

1. **Ratings become stats (V).** `DefaultAttributes` (graph 23) maps each 30..100 rating to 0..1 with
   3-4 ramps (section 6.1). For example, Forehand is `[30..50: 0->0.2 | 50..80: 0.2->0.8 | 80..100: 0.8->1]`.
   The game then sets `HandAttributeQuality` (S+0x74C) to the stat of the hitting side by code (I). Serves
   use `Profile.Serve`.
2. **Buttons pick the shot class (V for the controls, I for the class lookup).**
   - The stroke button gives Flat/TopSpin/Slice/Lob.
   - The hold time gives the tier: Finesse below 0.1875 s, Medium to 0.875 s, Powerful after
     (`power = min(frames/60, 1.25)/1.25`, G2b).
   - The situation gives serve, return, volley or smash.
   - The decision tree picks a template row. Its `ShotDef` entry (`Settings 761fdece.5f0108a7[i]`: `Id` =
     the shot-class Id, `Aiming.939129fa` = the template row name) names one of the 33 rows of the
     shot-class table (section 5). That row gives the **fault, net, power and aiming graphs**.
   - **Risk** (LT/RT) only turns Slice into DropShot (class 30, graphs 331/332) or VolleyDrop (class 29,
     graphs 329/330). The Risk classes 9-12 (graphs 298-305) are reachable only through the debug shot
     override (G2b). So in retail, Risk changes the error **only** by turning the shot into a drop shot,
     which is the most error-prone class (table below).
3. **Timing gives the main input (V for the field, I for the sign).** `t = ManualShotTiming` (S+0x544, -1..1)
   is copied from TimingState at the swing commit. Negative is early and positive is late. 0 is perfect.
   For the AI, the difficulty's `TimingExpression` graph writes it instead (section 4.2).
4. **The fault graph computes FaultProbability (V for the formula; FlatPower, graph 292, as the example).**
   Every groundstroke and volley class has the same template with different curves:

   ```
   control c = clamp01( 0.8                                      base
                        + lerp(0, ramp(dist 300..600 cm: 0 -> -0.5), ramp(speed 3..6 m/s: 0 -> 1))
                                                                 having to run far and fast
                        + lerp(...)(power 0.99..1: 0 -> -0.15)   full charge
                        + ramp(#1407106c 40..60: 0 -> -0.6)      fast incoming ball (km/h, I)
                        + ramp(vigor 0..0.2..0.4: -0.3 -> -0.1 -> 0)   fatigue
                        + contact-point terms (depth From.x, height From.y), pressure (MatchAnalyser),
                          skill links (SkillList) and #693eedbe / #aee2d90b / #8ea88f9f terms )
   e = lerp( lerp(hard(t),  easy(t),  c),                        weak hand
             lerp(hard2(t), easy2(t), c),  HandAttributeQuality)  strong hand
       * rally(MatchState.#8beb922e)                             1, or 1 -> 0.6 over 5..15 shots with a skill
   FaultProbability = dz( lerp(ErrorResolution.Min, ErrorResolution.Max, e) )
                      dz(x) = 0 for x < 0.15, else x             a dead zone: small errors are forgiven
   ```

   Timing curves of graph 292 (value at |t| = 0 / 0.3 / 0.6 / 1; early side first):

   | curve | early (t < 0) | late (t > 0) |
   |---|---|---|
   | easy (c = 1, weak hand) | 0 / 0 / 0.05 / 0.1 | 0 / 0 / 0.2 / 0.4 |
   | hard (c = 0, weak hand) | 0 / 0.2 / 0.5 / 0.5 | 0 / 0.2 / 1.0 / 1.0 |
   | easy2 (c = 1, strong hand) | 0 / 0 / 0.05 / 0.1 | 0 / 0 / 0.1 / 0.2 |
   | hard2 (c = 0, strong hand) | 0 / 0.1 / 0.3 / 0.3 | 0 / 0.1 / 0.6 / 0.6 |

   `ErrorResolution.Min/Max` come from the shot's `ShotDef` grade row (I for which grade). For most shots
   and the Good/Normal grades it is 0 / 1 (0 / 0.8 to 0.9 for VeryGood/Good on some rows, 0.2 / 1 for
   VeryBad).

   So in words:
   - **Inside |t| < 0.3 a groundstroke is safe** under normal conditions: every curve is 0 there.
   - **Late is punished about twice as hard as early.**
   - **The hand stat halves the timing penalty.**
   - **Bad situations** (running far, a fast ball, full charge, fatigue, an awkward contact point) lower
     `c` and move the curve toward the hard pair.
   - The 0.15 dead zone makes small mistakes free and big ones jump straight to 15 % or more.
5. **The net graph computes OutcomeNet (V).** For FlatPower (293):
   `lerp(ErrMin, ErrMax, Short * ramp(contact height 90..100 cm: 1 -> 0) + Long * ramp(90..100 cm: 0.5 -> 0))`.
   Errors from a low contact (below 90 cm) go into the net, all of them for a short aim and half for a deep
   aim. From 1 m up every error goes long or wide.
6. **Serves are a different, deterministic graph (V for the formula, I for `#3c6beee9`).** For a human
   (`IsHuman` = 1), the serve fault graphs (307-311) output 0 or 1 (FlatPowerful = 309):

   ```
   fault = step( (#3c6beee9 - lerp(0.5, 0.5, Serve))                         an aiming value vs 0.5
                 + window(gauge timing S+0x66C; window widens with Serve and vigor)
                 + (Target < 450 ? 1 : 0) )
   ```

   - The gauge window is about -0.4..+0.8 for a good, fresh server, narrower when tired.
   - `#3c6beee9` (AimingState S+0xD84) acts like a 0..1 roll or aim risk. Its writer was not found.
   - For the AI, the fault value is `ShotContext.#f089f55c` directly (the `(1 - IsHuman)` branch).
7. **The roll (V, `gp4b.md` 10.2).**
   - Let is decided first, with `P = S+0x71C`, when net and let outcomes are enabled.
   - Then `error = roll < P(error)`. A net error happens with `roll2 < S+0x720`; any other error is Out.
   - Out moves the target 3 cm past the nearest line. Net aims the ball into the tape.
   - Fatigue also feeds the *frame-shot* path: the Wood rule graph and the wood graphs 280-282 (frame
     chance `lerp(0, 0.3, ramp(#1407106c 60..100))` times the template's WoodUp/Down/Side flag).

### 11.3 Worked numbers

`python3 tools/ts4_shot_error.py Expressions.bin State.bin Layoutall.bin --class ... --set ...` evaluates the
real graphs. All inputs not named are 0: no skills, no pressure, link ports 0. Common settings:
`err_max=1 hit_y=90 hit_x=-1188 aim_long=1`. Each cell is P(error):

| scenario | class | t = -1 | -0.6 | -0.3 | 0 | +0.3 | +0.45 | +0.6 | +1 |
|---|---|---|---|---|---|---|---|---|---|
| A: hand 0.8, fresh, Medium charge | FlatPower | .17 | 0 | 0 | 0 | 0 | .16 | .29 | .37 |
| | TopSpinMedium | .22 | 0 | 0 | 0 | 0 | 0 | .11 | .24 |
| | SliceFinesse | .07 | 0 | 0 | 0 | 0 | 0 | .07 | .18 |
| | DropShot | .61 | .53 | .30 | 0 | .40 | .70 | .73 | .81 |
| | VolleyStandard | 0 | 0 | 0 | 0 | 0 | 0 | 0 | .12 |
| B: hand 0.3 | FlatPower | .20 | .17 | 0 | 0 | 0 | .22 | .38 | .50 |
| C: vigor 0.1 | FlatPower | .22 | .20 | 0 | 0 | 0 | .23 | .40 | .46 |
| D: stretched (`#1407106c`=70, 500 cm at 5 m/s) | FlatPower | .34 | .34 | 0 | 0 | 0 | .40 | .68 | .68 |
| | TopSpinMedium | .32 | .17 | 0 | 0 | 0 | .13 | .23 | .42 |

What the numbers say:

- **Timing is everything.** Inside |t| < 0.3 nothing else matters for groundstrokes.
- **Flat and power classes are much less forgiving than topspin or slice.** Volleys almost never miss
  from the error roll.
- **The drop shot (the only retail use of Risk) misses 30-40 % even at |t| = 0.3.**
- **A weak hand stat, fatigue or a stretched position each add 5-30 points** once the timing is off.

### 11.4 Where to retune

| lever | where | effect |
|---|---|---|
| timing window | the timing curves of each fault graph (`y1` of the keys) | the safe zone and how fast error grows |
| dead zone | `dz` curve (last two curves of each fault graph) | forgiveness of small errors |
| situational penalties | the constant 0.8 and the penalty curves in the `control` sum | how much running, fast balls and charge cost |
| hand stat weight | the strong- and weak-hand curve pairs | stat value vs timing |
| per-shot ceiling | `Settings 761fdece.ShotDef[i].9b182896.ErrorResolution` Min/Max per grade | per-shot error scale |
| net vs out | the net graphs' height ramps | where errors land |
| Risk | the shot tree (G2b) and the unreachable Risk classes 9-12 | a real risk/reward shot |

Edit graphs with `tools/ts4_analyser_patch.py` (patch `y1`, not `slope`). Shadowed duplicate copies
(246, 289-291, 247, 146) have no effect.

## 12. Reproduction (G1b)

```
# references to every graph: data words (BE/LE) and lis/ori code constants
python3 tools/ts4_graph_refs.py work/disc/core/fa94f637.bin \
  --data work/disc/core_all work/disc/tu1_arc work/disc/lua_amst orig/54540859/tu1 \
  --pe orig/54540859/Swing_DLL.dll orig/54540859/disc/Loader_DLL.dll --only-unreferenced
# writers of S+0x564 and the forcing flags through a ShotContext base
python3 tools/ts4_graph_refs.py work/disc/core/fa94f637.bin --pe orig/54540859/Swing_DLL.dll \
  orig/54540859/disc/Loader_DLL.dll --stores 0x564,0x56d,0x56e,0x572
# worked numbers of section 11.3 (scenario A)
python3 tools/ts4_shot_error.py work/disc/core/fa94f637.bin work/disc/core/623d0979.bin work/disc/Layoutall.bin \
  --class FlatPower --class TopSpinMedium --class SliceFinesse --class DropShot --class VolleyStandard \
  --timing -1 -0.6 -0.3 0 0.3 0.45 0.6 1 --set hand=0.8 vigor=1 power=0.5 err_max=1 hit_y=90 hit_x=-1188 aim_long=1
# regenerate graphs.yaml and the catalogue (names, list-payload binding, runners)
python3 tools/ts4_analyser.py ...   # section 9 commands
python3 -m unittest tests.test_g1b_graphs tests.test_analyser tests.test_arc_write
```

Disassembly addresses were read with capstone 5.0.7 through the `work/disc/ppcd.py` helper and a skipdata
variant of it. `graphs.yaml` (2,256,439 bytes) and the catalogue were regenerated with the section 9 commands.
