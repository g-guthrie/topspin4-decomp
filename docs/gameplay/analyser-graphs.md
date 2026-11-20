# Analyser graphs (agent `graphs`)

The data-driven expression graphs ("analysers") that turn player stats, fatigue, timing and ball context into
gameplay quantities. They are decoded from the retail disc and from `Swing_DLL.xex` (image base 0x88000000).
Tools: `tools/ts4_analyser.py` (reader and evaluator), `tests/test_analyser.py` (synthetic tests only).
This note records structure and counts. The game's numeric tables are not reproduced here; they stay in
`work/disc/gameplay/analyser_graphs.json` (local, git-ignored).

Confidence tags: **V** verified (read in code or measured on the disc and reproducible), **I** inferred,
**U** unknown. Addresses are VAs; hashes are `zlib.crc32` of the ASCII name.

## 0. Headline

1. **The graphs are in `Expressions.bin`, not in `AnalyserFrameworkModule.bin`** (V). `Core.arc` key `0xFA94F637`,
   581,988 bytes, sha256 `fd3bc49b44ca4b77deebc58acaefe67763a273538f4901266f949e9ec9dedee9`. It holds **341 graphs**
   (335 distinct name hashes) with 7,345 nodes, 9,124 curve keys, 3,559 input ports and 1,113 output ports.
   `docs/disc-data.md` listed `AnalyserFrameworkModule.bin` as the candidate; it is the **PlayerCreator** module
   (module name `PlayerCreatorAnalyserFrameworkModule`, 2,017 `CAnalyserAgentExpr` instances for gender, hue, morph
   and outfit commands) and contains no gameplay graph (section 8).
2. The 11 node kernels all behave as `stats-swing-clipfit.md` s2 says; the shipped data uses 8 of them (section 4).
   Evaluating all 341 graphs with `ts4_analyser.evaluate` agrees bit for bit with an independent raw-memory
   interpreter that follows the assembly (8,525 evaluations, 0 mismatches, section 7).
3. Every named gameplay analyser from `gp8.md` s2.4 was located by name hash: ShotDifficulty, BaselineTimingAbility,
   VolleyTimingAbility, FatigueIngame, FatigueConst, LetProbability, LetSettings, RushSpeedCoef, SwingSpeedCoef,
   VolleySpeedCoef, InputFiltering, the reward rules and zone graphs. Their wiring is in section 6.
4. **The stat to gameplay curves are graph `DefaultAttributes` (`0x8C9B26E0`) and its sibling `0x075A2137`**: eight raw
   stat ratings in, eight "Profile" values out, one independent piecewise-linear curve per stat (section 6.3). Nearly every other
   graph reads those Profile values, so this graph is where a stat is turned into fatigue, speed, timing and error
   behaviour.
5. **Open**: what each variable cell (`idx`) is in `PlayerState` terms. The graphs name their variables by
   (domain class, path of member names, cell index); the table that maps a cell index to a struct offset is not in
   any disc file examined and not decoded from code (section 5). The tuning levers are therefore located (graph,
   node, curve key) but the final link "output cell 276 is `S+0x71C`" rests on `gp8.md`, not on a decoded table.

## 1. Where the data lives (V)

| File | `Core.arc` key | Size | Type (root) | Role |
|---|---|---|---|---|
| `Expressions.bin` | `0xFA94F637` | 581,988 | sig `181AEDEE D2968089`, root type `0xD440C339` | the 341 graphs |
| `AnalyserFrameworkModule.bin` | `0x6E852B1A` | 348,264 | sig `A5D091F1 1FB5171F`, root type `0xB708811F` | PlayerCreator analyser module (no graphs) |
| `Module.bin` | `0x44DC9505` | 428 | same signature as `Settings.bin` | small module descriptor (not decoded) |

`Expressions.bin`, `Settings.bin` and `State.bin` share the signature `181AEDEE D2968089` (generic data tree).
Extract: `python3 tools/ts4_arc.py Core.arc --iso <iso> --extract fa94f637 --out work/disc/core_big`.
The names used in the file are hashes only; no dictionary on the disc contains them (the two CRC dictionaries
resolve a handful of path words such as `Distance`).

## 2. File format of `Expressions.bin` (V, measured on the disc)

All integers big-endian. Arrays are 12-byte descriptors `{s32 rel, u32 count, u32 cap}`; elements start at
(address of the descriptor + rel); `rel == -1` is a null array.

```
0x00  u32 0x181AEDEE, u32 0xD2968089   signature
0x08  u32 0x10, u32 0, u32 0xFFFFFFFF  version, zero, marker
0x14  u32 8, u32 0xD440C339            root header (root type hash)
0x1C  array<GraphDef, 0x2C>            341 elements, first at 0x28
```

**GraphDef** (0x2C bytes; this is the object `fn_88911668` reads as `def`, V):

| off | field |
|---|---|
| +0x00 | u32 register count (`fn_88158B28` sizes the register file to it) |
| +0x04 | array<Port, 0x18> inputs (`fn_8817A4F0(this+0x2C, ctx, def+4)`) |
| +0x10 | array<Port, 0x18> outputs (`fn_8817A4F0(this+0x20, ctx, def+0x10)`) |
| +0x1C | array<NodeEntry, 8> nodes (`def+0x20` is the count that sizes the kernel table) |
| +0x28 | u32 graph name hash (`fn_8866F028` matches it against the requested hash) |

**Port** (0x18 bytes):

| off | field |
|---|---|
| +0x00 | u32 domain key: looked up by `fn_8890EE68` in the context table (0x10-byte entries, key at +0xC) |
| +0x04 | s32 rel to the name-path record (also the 12-byte link field that `fn_8892EE88` resolves) |
| +0x08, +0x0C | zero |
| +0x10 | u32 register number (the `slot` of the `{float*, slot}` binding) |
| +0x14 | s32 cell index; `-1` means the port is bound through the link (a data constant) instead |

Binding rule in `fn_8817A4F0` (V): `index == -1` takes the pointer from the resolved link (`fn_8817F5E0`); otherwise
`ptr = (ctx+0x10 table)[index] + obj(+0x24) + field_offset` where `obj` and `field_offset` come from the domain lookup.
So `index` selects a variable cell and the domain selects the member inside it.

**Name-path record** (V for the shape, I for what the nodes mean). A link tree of `{rel, type}` pairs:
`{0xC,1,1}` then `{8, 0xFCF73E23}` to a node `{8, kind}` whose array (`+8`) lists elements; elements that
point to leaves `{0x10, 0x00270000, name hash, 0x00010000, 0, 0, 0}` give the reflected member names in order;
other elements are terminators. `kind` is `0x30001` for state blocks (PlayerState, BallState, TeamState,
`e9ca839c`, `3ba3d582`, `a2aa8438`, `56b5b281`) and `0x40001` for component or context blocks (ShotComponents,
ShotContext, RepositioningComponents, ServeComponents, PositioningComponents, MatchAnalyser, MatchState, `8448b811`,
`3237ffac`, `2de0bce2`; 9 TeamState ports). The reader returns the name hashes only.

**NodeEntry** (8 bytes): `{s32 rel to the record (relative to the entry), u32 node type crc32}`. Records (words
are u32 unless noted; the variadic ones start with an array descriptor whose slots are u32 registers):

| kernel | record |
|---|---|
| CONST | `+0 out, +4 f32 value` |
| SUM, PRODUCT, MIN, MAX, RUNSUM | `{rel,count,cap}` then `+0xC out`; slots at `rec + rel` |
| CURVE | `{rel=0x14,count,cap}`, `+0xC in`, `+0x10 s32 out` (negative: skipped), keys at `rec+0x14`, 0x14 bytes each `{f32 x0, x1, y0, slope, u32 unused}` |
| SUB, DIV | `+0 a, +4 b, +8 out` |
| LERP | `+0 a, +4 b, +8 t, +0xC out` |
| INVLERP | `+0 a, +4 b, +8 x, +0xC out` |

Measured node mix: CURVE 3,950, LERP 981, PRODUCT 896, CONST 870, SUM 487, SUB 126, MIN 31, MAX 4. DIV, RUNSUM and
INVLERP are implemented by the runtime but unused by the shipped data. Nodes are listed in dependency order (the
runtime executes them in file order; in all 341 graphs no node reads a register that is not an input or already
written, V); the largest graph has 90 nodes and 137 registers; 5 graphs have no nodes.
Six names occur twice (`04CDA578` and `FE1D9057` are empty or trivial and identical; `A4273D35`, `7979BB20` differ
by a node or a register, `823BD977`, `BD4552F9` are identical): the file carries a second copy of part of the set
(graph indices 61/146, 241/246, 242/247, 280/289, 281/290, 282/291), probably per-gender or per-mode variants;
which copy the game picks is not determined (U).

## 3. Runtime (V, code)

* `fn_8866F028(PlayerCtx, &hash)` finds the loaded graph with `def+0x28 == hash` in the list at `PlayerCtx+0x9C`.
* `fn_88911668(analyser, ctx, graph, ...)` resizes the register file, binds the inputs (`this+0x2C`) and outputs
  (`this+0x20`) with `fn_8817A4F0`, then `fn_8890E810` stores one kernel pointer per node (resolved by node type
  with `fn_8890E698` from the table built by `fn_8890EA30`) in `this+0x38`.
* `fn_8890E988(analyser)` = copy every bound input float into `regs[slot]`, `fn_8890E8B0` (run the nodes in order;
  CURVE nodes are evaluated inline, an unknown type has no kernel and is skipped), copy `regs[slot]` to every bound
  output float. Registers start from whatever was left in the register file: graphs are written so every register
  is written before it is read; the evaluator starts them at zero.

## 4. Node kernels (V)

Constants: `g_ts4_script_constants` (0x880D0F70) holds `+0x00 = 1.0`, `+0x38 = -1.0`, and a two-word select
table at `+0x68 = {+1.0, -1.0}` indexed by "value is negative or unordered" (this is how every clamp is written:
`fcmpu` then `fsel`). `lbl_8814B440` is `0.0`. The listing columns are the original function and what it does.

| type crc32 | name used here | function | semantics (all arithmetic single precision) |
|---|---|---|---|
| `6BBD0182` | CONST | `fn_8890DD88` | `regs[out] = value` |
| `DEE0059F` | SUM | `fn_88178F60` | left fold `acc = regs[s_i] + acc` starting from `regs[s_0]` |
| `9DA3605F` | PRODUCT | `fn_88179050` | same with multiply |
| `DCCE2909` | MIN | `fn_88179140` | `acc = x if (acc - x) >= 0 else acc` (a NaN compare keeps `acc`) |
| `FB754E38` | MAX | `fn_881792E0` | `acc = acc if (acc - x) >= 0 else x` (a NaN compare takes `x`) |
| `993894C6` | CURVE | `fn_88179480` / inline in `fn_8890E8B0` | `regs[out] = fn_8817A688(regs[in], keys)`; skipped when `out < 0` |
| `7A741F05` | RUNSUM | `fn_881794E0` | sum of the slots; if any slot is negative the result is `-1.0` |
| `8196EAE3` | SUB | `fn_88179580` | `a - b` |
| `B6EA415E` | DIV | `fn_881795B8` | `a / b` (IEEE: x/0 gives a signed infinity, 0/0 NaN) |
| `7E683220` | LERP | `fn_881795F0` | `a + clamp01(t) * (b - a)`, fused multiply-add; NaN `t` becomes 0 |
| `A68E1DC3` | INVLERP | `fn_88179698` | `clamp01((x - a) / (b - a))`; NaN becomes 0 |

Curve evaluator `fn_8817A688(x, curve)` (V): scan the keys in order, remember the last one with `x0 <= x` (the first
key if none; an unordered compare does not stop the scan), `d = min(max(x - x0, 0), x1 - x0)`, result
`y0 + slope * d` as a fused multiply-add. Beyond the last key the segment stays clamped at its own `x1`, so a curve
is flat after its last `x1`; below the first key it holds the first segment's `y0`. The type-crc preimages of the 11
nodes are not known (U); the names above are by function.

**Answered (G1, 2026-11-14): ramps.** `fn_88179740` (called from `fn_8890DFC8` for every CURVE node at load) writes `slope = (y1-y0)/(x1-x0)`; see `graphs-decoded.md` section 2. The original question follows for the record.

**Open question: are the curves steps or ramps? (measured 2026-11-14)** In the retail data every curve key has
`slope` (+0xC) = 0.0. That covers all 9,124 CURVE keys in `Expressions.bin` (sha256 `fd3bc49b…dee9`) and all 121
curve20 keys in `Settings.bin`/`State.bin`. Word +0x10 holds a float that is the segment's end value `y1`: in 4,095 of
5,174 adjacent key pairs it equals the next key's `y0`. A template example is `[500..3000: 80 → 135]`.
`fn_8817A688` reads +0xC and never +0x10 (`fmadds f1, d, [+0xC], [+0x8]` at `0x8817A754`). The graph runner
`fn_8890E8B0` passes the node record straight from the loaded file. No code that writes +0xC from `(y1-y0)/(x1-x0)`
turned up in `Swing_DLL` or `Loader_DLL`. The search scanned every `fdivs`/`fres` near a `0x14`-stride loop with
an +0x10 load and an +0xC store (capstone 5.0.7, `work/disc/scan2.py`–`scan4.py`, local). Two readings remain:
(a) a load-time fixup that was not found fills `slope`, so the curves are piecewise-linear ramps `y0 → y1`;
(b) the shipped game evaluates them as steps that hold `y0`. Under (b), single-key curves such as
`[0..1: 0 → 1]` are constants, and template speed curves never use their upper value. Reading (b) would make
many stat inputs inert. Settle it with a runtime memory read of a loaded curve key (Xenia) before trusting any
number derived from these curves. `tools/ts4_analyser.py` and `tools/ts4data/templates.py` currently implement
reading (b).

## 5. The variable model (V for fields, I for meaning)

A port names a variable by three things:

1. **domain key** (u32). Resolved by brute force over names found in the executable and the layout file
   (each verified by crc32): `1BF15200` PlayerState (2,786 ports), `9D7C7C58` BallState (283), `6C67FB3C` TeamState
   (228), `53A7FCCE` ShotContext (205), `8883D2E1` ShotComponents (324, all outputs), `FCD367BC` RepositioningComponents,
   `328A2512` ServeComponents, `B8C9A9FA` PositioningComponents, `92672F1B` MatchAnalyser, `11453F46` MatchState.
   Unresolved: `E9CA839C` (232), `3BA3D582` (129), `A2AA8438`, `8448B811`, `3237FFAC`, `56B5B281`, `2DE0BCE2`.
   `1BF15200` also occurs as a member name in `Layoutall.bin` next to the PlayerState array type `0x502FE79D` (I).
2. **path** of member names, for example `Fatigue.Output`, `Profile`, `Commands.LetCommands.Inputs`,
   `SwingSelection.EvaluationOutputs`, `AnimationSelection.Movement`. Words that resolve: Profile, Fatigue, Input(s),
   Output(s), Commands, LetCommands, SkillList, Context, EndOfPoint, LocalPosition, LocalOpponentPosition, HitPoint(Local),
   HitPosition(Local), TimingState, Movement, SwingSelection, AnimationSelection, EvaluationOutputs, Qualifier, and the
   shot kinds Flat, TopSpin, Slice, DropShot, Lob, Volley, BaseLine. 53 of 133 distinct path hashes resolve.
3. **cell index** `idx` (0..306, 308 distinct values including -1). The cells are numbered globally: for example the
   outputs of the named graphs occupy consecutive ranges (186 to 209), several ports may share a cell (the three inputs
   of LetSettings all read cell 115, i.e. one variable feeding three curves) and a cell written by one graph is read
   by others.

Cells written by no graph are state the game code writes before running the graphs (for example the fatigue level in
cell 16, which `RushSpeedCoef`, `SwingSpeedCoef`, `Vivacity` and others read through `Fatigue.Output`).
The table `ctx+0x10` that turns a cell into an address is built from XData typed arrays (types `0x1A2B0DA3`,
`0x2F68067A`, `0x502FE79D`, loaded by `fn_889117B8` from data trees `0xAF5C6F1F`, `0x2B4BE357`, `0x4588040C`); none of
those type hashes occurs in any extracted `.bin`. **Cell index to PlayerState offset is therefore U**; the cells fixed by
`gp8.md` (S+0x71C let chance is `LetProbability`'s output, written by cell 276) are the only anchors.

Ports with `idx == -1` (389 ports in 89 graphs) are bound through links to data (the player's skill list:
`Profile.SkillList` then a `Qualifier` chain). 303 of them use the path `Profile.SkillList` with a qualifier; which
skill each selects is U.

## 6. Named graphs, wiring and consumers

Each line: inputs (cell, source) -> nodes -> output. "Consumer" is the code that loads the graph by hash
(`tools/fn_asm.py`, lis/ori hash scan of `.text`). Wiring is V (read from the file); roles marked I are inferred.

### 6.1 Shot error, let, difficulty

* **LetProbability** (`0xBDD29CAD`, index 181). Input: cell 114 of `Commands.LetCommands.Inputs` (BallState). One CURVE
  node (2 keys). Output: PlayerState cell 276. Consumer: planner `+0x1C` loaded in `fn_886B7A60`; it is the `rec` argument
  of `fn_886807C0`, which reads `S+0x71C` right after running it (`gp8.md` s0.3). So the let chance is one curve of one
  ball-context variable. **Retune: the 2 key records of this curve.**
* **LetSettings** (`0x54457AD3`, 182). Input: cell 115 of `Commands.LetCommands.Inputs`, bound three times (registers
  4, 5, 6). Nodes: one CONST and three CURVE nodes (3, 3, 1 keys), one per register. Outputs: BallState
  `Commands.LetCommands.Outputs` cells 277 to 280 (four values: the CONST and the three curves). Consumer: planner
  `+0x60` (`fn_886B7A60`). Role I: let aim height and related let parameters.
* **ShotDifficulty** (`0xDDA048F3`, index 24). Inputs: PlayerState cells 50, 51, 52 (path `7E28DBC0`). Nodes: 6 CURVE
  (1 key each), 1 LERP, 1 SUM: `c0 = curve(in0)`, `a = curve(in2)`, `b = curve'(in2)` (a second curve of the same
  input), `w = curve(in1)`, `c1 = curve(lerp(a, b, w))`, `out = curve(c0 + c1)`. Output: PlayerState cell 153. Consumer: PlayerCtx `+0x154`
  (`fn_886BE1C8`), run by `fn_8868E248` after it stores the distance (m) and required speed (m/s) in `S+0x7A0/0x7A4`
  (`gp8.md` 4.1). Role: the "Ball Difficulty" used by swing selection scoring. Which of cells 50 to 52 is which stored
  field is U.
* **Error probability candidates**: `E4F01642` (index 8, 13 inputs, 21 nodes) and `46c7bb5f` (index 7, 8 inputs,
  13 nodes) both write PlayerState cell 186. `E4F01642` is the analyser at planner `+0x104` that `fn_886AE528 +0x5D8` runs
  immediately before the shot outcome decision (`gp8.md` 2.4; loaded in `fn_886BCDA8`). Its
  inputs are fatigue (cell 16, twice), the shot context (cell 14, twice), PlayerState cells 12, 13, 15, 17 and two
  skill-list links; per input a CURVE, combined by PRODUCT, SUM and a LERP, then multiplied once more and passed through
  the final CURVE. Role I:
  the shot error probability that feeds `S+0x718` (`gp4b.md` 10.2). `46c7bb5f` writes the same cell with 8 inputs
  (variant for another shot class, I). **Retune the curves of these two graphs first.**

### 6.2 Timing and fatigue

* **BaselineTimingAbility** (`0x85F4C811`, 41): input PlayerState cell 17, one CURVE (1 key), output cell 106
  (`89408A2F.TimingState`). Consumer: timing object `+0x00` (`fn_886B7048`).
* **VolleyTimingAbility** (`0xA6DFABAA`, 42): input cell 37 of `Profile`, one CURVE, output cell 106. Timing object
  `+0x88`. A third graph `39CFDEBA` (cell 26 in, cell 106 out, one CURVE) at timing object `+0x44` follows the same pattern.
  All three write the same TimingState cell, so only one shot class is active at a time.
* **FatigueIngame** (`0xCBE44A9B`, 10): inputs `Fatigue.Input` cells 19, 21, 22 and `Profile` cell 20 (bound twice);
  nodes: 4 CONST, 4 PRODUCT, 2 LERP, 1 SUM, 1 CURVE (2 keys); output `Fatigue.Output` cell 188. Consumer: fatigue object
  `+0x04` (`fn_886BC1E0`). The `Profile` cell 20 input is the stamina-derived Profile value (section 6.3, I).
* **FatigueConst** (`0x6BD1FBAB`, 13): inputs `Profile` cell 20 and MatchState cell 25 (`BC21F307`, component kind);
  8 CONST, 2 PRODUCT, 1 LERP; seven `Fatigue.Output` cells 191 to 197 (constants and one interpolated value). Fatigue
  object `+0xD0`. The siblings `80CE1A10` (cells 189, 190) and `8ADD300F` (cell 23) and `Vivacity` (`0x9D734117`, cells
  198, 199) are loaded in the same function (`fn_886BC1E0`); the first two are unnamed.
* **RushSpeedCoef** (`0x0340A26E`, 18): inputs `Profile` cell 29 and `Fatigue.Output` cell 16; two CURVE nodes (1 and 2
  keys), SUM, CURVE; output `AnimationSelection.Movement` cell 202. Consumer: PlayerCtx `+0x110` (`fn_886BE1C8`).
* **SwingSpeedCoef** (`0xB5CFF9B7`, 17): 9 inputs (LocalPosition cells 9 and 33, a skill link, `Profile` cells 37 and
  29, `Fatigue.Output` cell 16); 10 CURVE (1 to 5 keys), 3 LERP, 3 SUM, 1 PRODUCT, 1 CONST; output
  `AnimationSelection.SwingSelection` cell 201. Consumer `fn_886BB6E0`.
* **VolleySpeedCoef** (`0x4FCC3EB8`, 37): no inputs, one CONST, output `AnimationSelection.Movement` cell 209.
  Consumer `fn_886BB6E0`. A fixed multiplier: edit the CONST value.
* **InputFiltering** (`0xDF1F8733`, 38): consumer `fn_886BDB58`; reads `Profile` cell 26.

### 6.3 Stat curves (`DefaultAttributes`, `0x8C9B26E0`, index 23, and `0x075A2137`, index 21)

The two graphs have identical wiring (`0x075A2137` uses 4 keys per curve, `DefaultAttributes` 3 or 4); the second is
probably the variant for another player class (U). Eight inputs `Profile.3B91D48C` cells 40..47, eight outputs `Profile` cells 29, 20, 48, 26, 18, 49, 37, 203, and exactly
eight CURVE nodes (3 or 4 keys each, no other nodes): one independent curve per stat. Pairing (input cell -> output
cell): 40->203, 41->20, 42->48, 43->29, 44->49, 45->37, 46->26, 47->18. The eight input cells are the eight float
ratings at `S+0x64C..0x668` (`stats-swing-clipfit.md` 1.2; count V, order U). From the consumers: output cell 20 is read
by FatigueIngame and FatigueConst (so input 41 is the stamina rating, I), cell 29 by RushSpeedCoef and SwingSpeedCoef
(input 43 is speed, I), cell 37 by VolleyTimingAbility, `Volley` and `VolleyZone` (input 45 is the volley rating, I).
Cells 18, 26, 49 are read by 31, 50 and 27 graphs respectively (the most widely used Profile values; `IsTired`,
`InputFiltering` and `ReturnServeZone` read cell 26). **Retune the 8 curves here to change how a rating affects play.**
No code loads either graph by a literal hash, so what selects and triggers them (match start, player change) is U.

### 6.4 Reward and rule graphs

The 18-entry rule table of `fn_886BF598` (`gp8.md` 2.4) loads `PerfectShot`, `GoodTiming`, `GoodVolleySwing`,
`HighTopSpin`, `Powerful`, `PowerfulBall`, `AutoSwing`, `AutoVolleySwing`, `ReturnServeZone`, `VolleyZone`, `Finesse`,
`Medium`, `Volley`, `Wood`, `WrongFoot` and others; each is a small graph whose output cell is in the 259 to 275 range
(`SwingSelection.EvaluationOutputs`, `7E28DBC0` or `ReturnServeState` paths), i.e. per-swing rule scores for swing
selection and rewards, not error chances. 63 of the 341 graph names are loaded directly by hash in code.

### 6.5 Shot-style mix and positioning outputs

* 24 graphs write `ShotComponents` (13 outputs each: Flat, TopSpin, Slice, DropShot, Lob and 8 unresolved shot
  components), driven by the hit position and a style cell; they are made mostly of CONST and CURVE nodes.
* 21 graphs write `RepositioningComponents`, 10 `PositioningComponents`, 8 `ServeComponents`, 44 write domain
  `E9CA839C`, 7 `TeamState`: the AI shot choice and court positioning mixes (I).

## 7. Verification (V, local)

`work/agents/graphs/check_trace.py` (not committed; it reads the disc file):

1. an independent interpreter reads the raw `Expressions.bin` with the same pointer arithmetic as `fn_8890E988`,
   `fn_8890E8B0`, the node kernels and `fn_8817A688` (constants from `g_ts4_script_constants`, `fsel` tables); it agrees
   bit for bit with `ts4_analyser.evaluate` on **8,525 evaluations over all 341 graphs** (25 random input vectors each,
   0 mismatches);
2. hand traces of two graphs against the formulas read from the assembly: `LetProbability` (single CURVE: segment
   lookup, clamp, fma) at five inputs, and `FatigueConst` (PRODUCT, PRODUCT, LERP with the t clamp, no curves) at two
   inputs; both agree.

`tests/test_analyser.py` (30 tests, synthetic byte strings built by an in-test image writer) covers the curve
rules, every kernel including NaN, infinity and clamp cases, the parser (header checks, truncation, unknown node
type), topology and evaluation.

## 8. AnalyserFrameworkModule.bin (V)

Root `{8, 0xB708811F}` with a two-element array and tables of 37 and 1,997 entries (I) of `CAnalyserAgentExpr`
records (`0x87AD70EC`, 2,017 words) keyed by names such as `Gender`, `Hue`, `Saturation`, `Brightness`, `Outfit`, `MeshName`,
`Channel`, `Enabled` (resolved by crc32), with `CPCAnalyserAgent_Current`, `CPCAnalyserAgent_Preset` and
`CAnalyserAgentCmdSender_*` classes. All of that is character-creator tuning; `framework_module_summary()` returns the
counts. Its entry layout (0x1C bytes per agent, cross references by index) is not decoded because no gameplay value
lives there.

## 9. Retuning notes

* The unit of tuning is a CURVE key `{x0, x1, y0, slope}` (0x14 bytes at `rec+0x14`) or a CONST `value`: both are plain
  floats in `Expressions.bin`, in place. Patching needs a `.arc` writer (`tools/ts4_arc.py` only reads; members are LZX
  compressed and re-packing was not attempted).
* Because the evaluator is bit exact, a modified graph can be evaluated offline to check the new response before
  repacking: `python3 tools/ts4_analyser.py Expressions.bin --eval LetProbability <x>`.
* Where to start: `E4F01642` and `46c7bb5f` (error), `LetProbability`, `DefaultAttributes` (all 8 stat curves),
  `FatigueIngame`/`FatigueConst`, the three timing abilities, `ShotDifficulty`.

## 10. Not found / next steps

1. The cell table (cell index to PlayerState offset). Best lead: the XData typed arrays loaded by `fn_889117B8` and the
   `0x10`-byte binding descriptors read by `fn_88910CF0`; the extractor found none of their type hashes in any disc file,
   so they are probably built at run time from the layout. A runtime memory dump (Xenia) of `ctx+0x10` would settle it.
2. Which graph is `S+0x564` (the additive error modifier) and which writes `S+0x720` (net share) beyond the LetSettings
   guess.
3. The stat order of `Profile.3B91D48C` cells 40 to 47 and the skill-list qualifier of the 389 link ports.
4. Names for about 280 of the 341 graphs and 80 of the path hashes; the brute force over words from the executable
   (1 to 3 words) found real words only for the ones listed above.
5. The node type preimages and what selects between the duplicate graph copies.

## 11. Reproduction

```
ISO="orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso"
python3 tools/ts4_arc.py Core.arc --iso "$ISO" --extract fa94f637 --out work/disc/core_big   # Expressions.bin
python3 tools/ts4_analyser.py work/disc/core_big/fa94f637.bin --list
python3 tools/ts4_analyser.py work/disc/core_big/fa94f637.bin --json work/disc/gameplay/analyser_graphs.json
python3 -m unittest tests.test_analyser
python3 tools/fn_asm.py fn_8890E8B0 fn_8817A688 fn_8890EA30      # runtime, curve, registration
```

Tool versions: Python 3 standard library only; code disassembly with `tools/fn_asm.py` over the Jeff split of
`Swing_DLL.xex` (sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`).
