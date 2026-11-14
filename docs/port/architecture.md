# Top Spin 4 browser port: architecture

Goal: a faithful browser port that runs the game's own logic (today: the validated reference C and readable drafts;
eventually the matched decompiled C compiled to WebAssembly) and loads assets the user extracts from their own
disc; then data-driven retuning (`docs/tuning/research.md`). This note is the design; the code is `port/core/`.

Hard rules (AGENTS.md): no game assets, executables, keys or extracted data in the repository, ever. The only data
file committed is `port/core/data/provisional.tunables.json` (port-invented or doc-quoted numbers, flagged as
provisional in the blob). Everything else comes from a blob built locally from the user's disc
(`docs/port/data-format.md`).

## 1. Layers

```
 browser tab
 ┌───────────────────────────────────────────────────────────────────────────────────────────────┐
 │ (c) renderer  WebGL2: glTF court / players / ball, skeletal clips, camera       port/web/    │
 │ (b) platform  Gamepad+keyboard -> Ts4Input, fixed 60 Hz clock + interpolation, audio cues,   │
 │               save/rollback (memcpy of the core region), debug HUD                port/web/    │
 ├───────────────────────────────  ts4core.h  (C ABI, 4-byte-field structs)  ──────────────────┤
 │ (a) ts4core   deterministic fixed-step simulation, portable C99, wasm32 or host  port/core/  │
 │      ball · shot · graphs · rules · reach/selection · movement · swing · AI                  │
 ├───────────────────────────────────────────────────────────────────────────────────────────────┤
 │ (d) data      blob (TS4D) + glTF + textures + audio, exported locally from the user's disc   │
 │               tools/port/ (other agent)  ->  work/port/  (git-ignored)                         │
 └───────────────────────────────────────────────────────────────────────────────────────────────┘
```

### (a) ts4core: the simulation

* **Fixed timestep.** One call to `ts4_step()` is one 1/60 s gameplay tick; the game's own unit system is kept
  (centimetres, ticks, net plane `x = 0`, y up). No wall clock, no allocation, no globals, no libm, no `-ffast-math`:
  the result is a pure function of (blob, tunable overrides, `Ts4MatchConfig`, per-tick `Ts4Input`).
* **Determinism.** IEEE binary32, `-ffp-contract=off` (every fused multiply-add of the console is an explicit
  `fmaf`), and a software `fmaf` / `exp` / `log` / `sin` / `cos` / `atan2` (`src/softmath.c`) so that host, wasm and any
  future target agree bit for bit. Verified: the same AI-vs-AI match gives the same state hash at `-O0`, `-O3`, under
  ASan/UBSan and in wasm under Node (6,000 and 30,000 ticks); `ts4_fmaf` equals the hardware instruction on 2 million
  random/cancelling/subnormal inputs; the reference ball model's golden vectors (taken from an emulation of the
  original machine code) pass with the software libm.
* **State.** Everything lives in one region of `ts4_core_size()` bytes the host provides (about 35 KB). Copying it is a
  save state / rollback snapshot (the blob is referenced, not copied, so restore at the same address).
* **Modules** (section 3) are plain C files with narrow seams; each can be replaced by the matched decompiled
  function(s) it models without touching the others (section 5).
* **Data in, never baked in.** Every tunable is looked up by `crc32(name)` in the blob (`include/ts4_tunables.def` is the
  registry; the C sources contain no default for any of them). A module whose required data is absent reports
  `TS4_STATUS_MISSING_DATA` and `ts4_match_start()` refuses; an absent optional input (a graph role, a movement margin
  table) gives `TS4_STATUS_DEGRADED` and a named fallback. Tunables can be overridden at run time
  (`ts4_set_tunable`), which is the retuning hook; graph curves are retuned by editing the blob's `GRPH` section.
* **Graph roles.** The analyser graphs of `Expressions.bin` bind to `PlayerState` through a cell table that is not
  decoded yet (`analyser-graphs.md` s5). The core binds by *role* (`include/ts4_roles.def`): the blob lists which graph
  runs for each role and which core variable feeds each port. Decoding the cell table later changes only the blob.

### (b) platform layer (in `port/web/`; the contract it relies on)

* **Input.** Gamepad: A/B/X/Y -> `TS4_BTN_FLAT/TOPSPIN/SLICE/LOB`, RT or LT -> `RISK`, RB -> `SPRINT`, left stick ->
  `stick_x/stick_z` (shooter relative: +x toward the opponent's baseline, +z the player's right), the same stick is
  the aim at the tick the shot button is released (hold = charge = tier). Keyboard maps onto the same struct.
  `Ts4Input` is latched once per tick; record/replay is a list of `(tick, player, Ts4Input)`.
* **Time.** `requestAnimationFrame` accumulator: step `n = floor(acc / (1/60))` times (cap at 4), render with the
  fractional remainder; snapshot interpolation uses two consecutive `ts4_snapshot()` copies.
* **Audio.** Stub: subscribe to `ts4_poll_events()` (`HIT`, `BOUNCE`, `NET`, `POINT_END`, ...). The sound buckets
  (shot class, power, bounce angle/speed, umpire calls) are specified in `docs/gameplay/gp5.md`; surface only changes
  sound, visuals and the clay swing takes (`surfaces.md`), never ball physics, so `Ts4MatchConfig.surface` is recorded
  for the renderer/audio and ignored by the core.
* A JavaScript reference binding with layout assertions is in `port/core/js/ts4core.mjs`.

### (c) renderer (in `port/web/`)

WebGL2, glTF 2.0 assets exported by `tools/port/` (skeletons, every shot/movement clip with the EventRacket contact
marker as a glTF extra, court and ball meshes, textures re-encoded locally). The snapshot gives player root position,
heading, `move_state`, `swing_state` and `swing_t` (0..1 to contact) and the template row of the last shot; clip choice
and time-warp to the contact frame are the renderer's job until the clip-fit logic (gp7) is ported (section 3). The
ball is drawn from `Ts4BallView` (position, velocity, spin, bounce count); trajectory previews use `ts4_shot_trace()`.

### (d) data

`tools/port/` (other agent) turns the user's disc into `work/port/`: the TS4D blob, glTF, textures, audio, plus a
manifest with sha256 of every source file. The blob format, the tunable registry, the role/variable tables and the
exporter checklist are in `docs/port/data-format.md`. `port/core/tools/ts4d.py` is the reference writer/reader and
generates a game-free synthetic blob for tests and demos.

## 2. Repository map

| Path | Role |
|---|---|
| `port/core/include/ts4core.h` | the API contract (stable within `TS4_API_VERSION`) |
| `port/core/include/ts4_tunables.def`, `ts4_roles.def` | registries: tunables, graph roles, core variables |
| `port/core/src/data.c` | blob parse/validate, tunables, curves, analyser graph evaluator, roles |
| `port/core/src/ball.c` | ball: `#include`s `src/xbox360/drafts/gp4b_ball_model.c` (validated) + bounce/net/cord |
| `port/core/src/shot.c` | request tree, outcome decision, aiming, launch plan, RNG |
| `port/core/src/sim.c` | match: players, swings, judge, AI, events, snapshot |
| `port/core/src/softmath.c`, `shim/` | deterministic math, `<math.h>`/`<string.h>` shims (host and wasm) |
| `port/core/src/wasm_rt.c` | wasm only: `mem*`, bump allocator exported as `ts4_wasm_alloc/reset` |
| `ref/gameplay/*.c` | reused unchanged: rules, movement planner, AI argmax, stats, swing window |
| `port/core/Makefile`, `build_wasm.sh` | host build + tests; wasm build (`work/port/ts4core.wasm`) |
| `port/core/test/`, `tests/test_port_core.py` | C self-test, wasm smoke test, Python orchestration |

Build and test:

```
make -C port/core test                      # host: cc -std=c99 -Wall -Wextra -Werror, runs the self-tests
python3 -m unittest tests.test_port_core    # same + graph parity vs tools/ts4_analyser.py + blob fuzzing + wasm
port/core/build_wasm.sh                     # -> work/port/ts4core.wasm  (CLANG=... to pick a wasm32-capable clang)
```

The wasm build needs a clang with the wasm32 target (Apple clang lacks it; Homebrew `llvm` has it) and `wasm-ld`
(`lld`). Command it runs: `clang --target=wasm32 -nostdlib -ffreestanding -std=c99 -O2 -ffp-contract=off
-fno-math-errno -mbulk-memory -fvisibility=hidden -Wl,--no-entry -Wl,--export-dynamic -Wl,-z,stack-size=262144 ...`.
The module has no imports (55 KB), exports the `ts4_*` API plus `memory`.

## 3. Module table

Status vocabulary. **validated**: bit-exact against an instruction-level emulation of the original code (or the
original's own kernels) with committed evidence. **reference**: behaviour documented from the machine code and
implemented in host-tested reference C; some constants or branches inferred (noted). **draft**: readable C from the
notes, mathematically right but not bit-checked. **policy**: the game's behaviour is not decoded, the port uses a
labelled stand-in (no game numbers: tunables only). **missing data / not done**: see the last column.

Two data paths. **Synthetic / exporter blob** (`ts4d.py synthetic`, `tools/port/blob_writer.py`): graphs are wired
through the hand-written `ROLE` section and the port policies below apply. **Gameplay blob**
(`port/core/tools/ts4yaml.py pack --data data/gameplay`, local only, never committed): adds `BIND`/`SINI`/`AIDF`/
`SKIL`/`ANIM`/`SCLS`/`SCAT` so every analyser graph runs on byte images of PlayerState / AI / Team / Match / ball
laid out by the decoded cell -> member bindings (4672/4672 ports bound). Rows marked "bound" below describe that path.

| Module (`ts4core`) | Source of truth (note; original functions) | Implementation | Status | Missing / gap |
|---|---|---|---|---|
| Soft libm | gp4b s9 (CRT double `exp`/`log` rounded to float) | `softmath.c` | validated (fma exact vs HW; exp/log agree after float rounding; golden vectors pass) | sin/cos/atan2 only for the draft bounce, not bit-exact |
| Ball arcs, launch solve, kinds DropTime/BounceSpeed/InitialSpeed/AverageSpeed/Apogee, apex, net height | `gp4b.md` s1-s6; `fn_888AAEA8/AAE00/AAB98/AAA70/AACB8/AA968/AB308/AB6C8/AB0E0/AB220/AB558/AD1C8/AB8D0/AC748/ACA68/ACDA8/AD0E8`, probe `889C2678`, spin `889C1868/889C0DC0`, launch `889C19F0` | `gp4b_ball_model.c` included as is | **validated** (golden vectors from the emulated original, 8 solver cases, probe, launch, per-tick before first bounce) | ball `a4`, `g`, radius come from the `State.bin` ball block in the exporter/gameplay blobs; net height assumed 91.4 cm |
| Per-tick step, first-bounce event | `fn_889C2818`, `fn_889C1F70` ground part | `gp4b_step_flight` | validated | world/local frame is kept local between ticks; `skip_launch_step` (`ball.skip_launch`) not applied |
| Bounce response (speed loss, elevation, yaw kick, spin decay) | `gp4.md`; `fn_889C1C80` | `ball.c bounce_response`; later bounces snap y = 0 (G3) | draft (rotation convention of `fn_8864F7B8` assumed right-handed Rodrigues) | curves come from the template (data) |
| Net hit, net cord (Let) | `gp4.md` 1.4, `ref/gameplay/ball.c` (G3); `fn_889C1F70` net branch | `ball.c`: net test on the end-of-tick height; bound: exact reference cord (rotate by |elevation| + Angle, yaw by SideAngle, spin scaled twice, `no_sidespin`) with Angle/SideAngle/speed/spin loss written by the `LetSettings` graph into ball+0x494..0x4A0 | **reference** when bound; draft otherwise (cord params from tunables) | port deviation: `bounce_count` still increments after a cord touch |
| Ball mode flags | `fn_889C0C70` | `gp4b_mode_flags` | validated | |
| Prediction (up to 600 ticks, 2 bounces) | `gp3.md` s2; `fn_886AD278` | `sim.c predict()` (runs the real stepper on a copy) | reference | per-sample difficulty `fn_886AB250` not done |
| Request tree -> template row | `shot-to-template.md`; `fn_8865A938`, `fn_886715A0` | `shot.c ts4_tree_select` + blob `TREE` | reference | tiers: bound = Finesse/Medium/Powerful graph outputs S+0x3D4/0x3D8/0x3DC on S+0xE00 (edges 0.15 / 0.70); otherwise the `shot.tier_*` fallback with the same edges. `cfg+0xC6C..0xC74` are Objective8AllAround fields, not tiers (G6b) |
| Shot templates | `shot-templates.md`, `gp4b.md` s1; `Settings.bin` rows (0x8C bytes) | blob `TPLS`, big-endian bytes handed to the ball model unchanged; gameplay blob rebuilds them from `ball_templates.yaml` with ramp curves | validated layout | payload pointers are not bounds-checked (see gaps) |
| Shot charge / commit / serve input | `controls-and-shot-selection.md`, `ref/gameplay/shot_select.c` (G2b); `input_map.yaml` | `sim.c on_press/charge_update/serve_input`, `shotsel.c` (copied helpers): press latches the counter and picks the contact, commit on release or 12 frames before contact, power = `shot.power` curve of frames / 60 (`shot.power_alt` with InstantRocket), LT forced commit, inside-out side, stick dead zone; serve: input delay 30, auto toss 480, countdown 40, power = release fraction, tiers > 0.8 / >= 0.1 | **reference** (constants are GAME values from the input map) | human ManualShotTiming (S+0x544) = commit lead vs ideal 20 frames: **policy**; serve AI is policy |
| Outcome In/Out/Net/Let | `gp4b.md` s10, `ref/gameplay/ball.c` (G3); `fn_886807C0`, `fn_8866E318`, `fn_88672130`, `fn_88662C08`, `fn_88671B10`, RNG `fn_8861E598` | `shot.c` + `shotsel.c`: G3 decision (forced vs non-forced), reach flags b50/b51 (only when S+0x7E0 > 0), In clamp + shortfall S+0xD78, forced push-out 3 cm, non-forced roll + demotion (> 40000 cm^2), Out / OutFar / very-far grading, Wood target box, Net/Let aim bisection | **reference** (M-high; not emulated) | bound: error / net share / let from graphs (S+0x718+0x564, 0x720, `LetProbability` S+0x71C); unbound: tunables + roles. Reach-flag fan angles are tunables; LetProbability input `#fea37f2e` not written |
| Aim point | `shot-to-template.md` s4 aim tables (`fn_886935A0`, `fn_88693040`) | `shot.c` | **policy** (depth/width from stick, serve box targets) | aim tables not decoded |
| Analyser graph evaluator | `analyser-graphs.md`; `fn_8890E988/8890E8B0`, kernels `fn_88178F60...`, curve `fn_8817A688` | `data.c ts4_graph_run` over blob `GRPH` | **validated**: bit-identical to `tools/ts4_analyser.py` (itself verified on 8,525 evaluations of the real file) on random graphs incl. NaN/inf | |
| Graph wiring (cell -> member) | `data/gameplay/graphs.yaml` bindings (G1b), `State.bin` defaults | `fields.c ts4_bgraph`: blob `BIND` (region + offset per port, RANDOM flag fills U[0,1)), `SINI` defaults; regions SELF/OPP/BALL/MATCH/TEAM/AI/SKILL/QUAL/PARTNER | reference (bindings are data; 154 random ports) | sim writes only part of the inputs: ReceiverState `#c7b7bdac` fields (S+0xC28/0xC2C/0xC38), S+0xD00/0xCF0, MinSpeed lines, IsFastBall stay at their `State.bin` defaults |
| Stat curves, quality, difficulty | graphs `DefaultAttributes` (0x8C9B26E0), `ShotDifficulty`, `HandAttributeQuality`, the 33 shot-class graph sets (`SCLS`), Wood | bound: run at match start / per shot on the image; unbound: roles | reference (bound) | row -> shot-class mapping is a **policy** name match (Return* classes when returning serve); ShotDef ShotSpecific min/max are tunables (**policy**) |
| Fatigue | FatigueConst, FatigueIngame, `#80ce1a10`, ErrorMissFatiguePenalty, Vivacity, IsTired, `#9c8607a7`, InputFiltering, Volley, `#daf2ecbd` | bound: graphs run at match start and after every point | graphs reference; **CurrentVigor integration (S+0xF54) is policy** (`fatigue.*` tunables: drain per metre, per shot, recovery per point) | S+0xF64 ("VigorMax?") is not used as a cap |
| Skills | `traits_skills.yaml`, skill graph inputs | blob `SKIL`; `ts4_set_player_extra` skill mask feeds the SKILL region; InstantRocket, PoisonedSlices, dive skill read by the sim | reference (data) | most skills act only through the graphs that read them |
| Rules and scoring (singles, Standard class) | `rules-and-scoring.md`; `fn_8866A1C8`, `fn_88676DB0`, `fn_88676960`, `fn_88676AF0` ... | `ref/gameplay/rules.c` unchanged | reference | mini-game scoring classes, doubles |
| Judge (in/out/net, bounces, serve box, let) | `rules-and-scoring.md`, umpire `gp5` | `sim.c judge()` | policy (structural rules of tennis; court line positions are tunables incl. the game's `2 * radius` tolerance) | the game's own event queue (`fn_8866E...`) not ported |
| Candidate window, reach speed | `gp2.md`; `fn_8869B178`, `fn_8868B4E8` | `ref/gameplay/swing_window.c` unchanged | reference (classification thresholds inferred in the ref) | turn time, anim-busy time and volley side logic not in the ref |
| Selection (arg-max) | `gp2.md`; `fn_8865DBA8` | `gp_select_best` | reference | commit hysteresis `fn_886A2E48` not done |
| Selection score | AI record g48 / g4c hit-point score graphs (`#3237ffac.Score` S+0xBA8) | `sim.c ai_commit` | reference when bound; else **policy** (`1 / (1 + reach speed)`) | |
| Movement regime selector | `movement-and-ai.md`; `fn_88699FC0`, `fn_88688948` | `mv_select_move_state` | reference (order verified) | margin tables optional `CURV` |
| Movement planner state machine | `fn_886B8468`, `fn_886BD690` | `mv_update` in `ref/gameplay/movement.c` | reference; known predicates wired, the rest 0 | ~12 predicates (`fn_886A9678`, zones, ...) |
| Locomotion | game: animation root motion | `sim.c player_update` | speeds **policy**; bound `RushSpeedCoef` (S+0x398) and the speed override (G4, change only above 0.4) reference | root motion |
| Swing timing | `gp7.md`, `stats-swing-clipfit.md` C | contact from the prediction at press, swing starts `contact - 12` frames; the clip starts at the frame that puts its contact frame on the contact tick at the global rate | lead reference (input map); clip start **policy** | full clip fit (`ref/gameplay/clip_fit.c`) needs root motion |
| Swing category (class / mode, Fatality put-away) | `ref/gameplay/swing_category.c` (G6b) | `swingcat.c` copy over blob `SCAT`, writes S+0x360 | reference | only the Normal mode is walked (autoswing modes not); PlayerTuning thresholds hard-coded as in the ref |
| Animation selection and state | `ref/gameplay/anim_select.c` (exact filter rules), `animation_rules.yaml`, `animation_clips.yaml` | `anim.c`: movesets by planner state, sector8 vs facing, transition matrix (blend frames, HighVivacity speed), swing query by category + preference level 8..3, dive volley; `ts4_anim_view` gives clip id / frame / rate / blend per player every tick | filter rules and movesets reference; clip choice **policy** | best clip = least time scaling (no root-motion cost); first clip of a subgroup; male clip set only |
| AI virtual input | `movement-and-ai.md` B, AI difficulty records (`AIDF`, G4b) | `sim.c ai_think`: g40 TimingExpression -> S+0x544, g44/g50/g54, lists rally/return/repositioning/positioning; reaction delay = PositioningComponents `#79b99b60` (AI+0x1DC) | reference for the graphs and the reaction delay; **policy** for turning ShotComponents into buttons (arg-max of Slice/TopSpin/Flat/Lob/DropShot, PressAndHold -> power, Side/Length arg-max -> aim) | ServeComponents not used (serve AI policy) |
| Hit-quality grade, rewards, excitement, crowd | `gp1.md`, `gp8.md` s10.4 | not implemented | not done | not needed for a playable core |
| Doubles, other surfaces' swing takes | `gp4.md`, `surfaces.md` | not implemented | not done | |

Evidence in the repository: `src/xbox360/drafts/gp4b_ball_model.c` self-test, `ref/gameplay/test_*.c`,
`tests/test_analyser.py`, and `tests/test_port_core.py` (this port). What the port suite asserts: deterministic
ball probe/trace for 9 synthetic template rows (landing on the planned point, net clearance, Net-mode ball stops at the
net), loader rejection of corrupted blobs (150 mutations never crash), AI-vs-AI matches terminate with a correct
score, human serve and human return work, identical hashes across optimisation levels and in wasm.

## 4. Behaviour of the simulation (what runs today)

`ts4_match_start` places server and receiver (rules decide server, side and ends). A human server charges and
releases a shot button to serve; an AI server does so after `flow.ai_serve_delay_ticks`. A shot is: request flags
(buttons + power tier + stroke class of the contact sample) -> tree -> template row -> the three outcome rolls with the
error graph/let graph in between -> landing point (In clamp + dispersion, Out push-out, Net/Let commanded-speed probe
with a 10-step bisection of the aim) -> probe + launch (validated model) -> prediction. After a hit the opponent's AI
builds the candidate window from the prediction, scores it (graph role or fallback), commits to the best sample, runs
there with the regime chosen by the verified selector, and presses/releases a button so that contact happens on the
sample's tick. The judge applies the rules of tennis to ground bounces and net events and calls `rules_end_point`.
A human presses a shot button: the counter latches and the contact is chosen; the shot commits on release or
12 frames before contact (power from the hold frames / 60), and the swing clip starts so that its contact frame lands
on the contact tick. Serves follow the input-map toss/countdown. With a gameplay blob every analyser graph runs on
the bound images (section 3). Everything the renderer needs is in `Ts4Snapshot`, the event stream and
`ts4_anim_view` (clip id, frame, rate, blend per player, every tick).

## 5. Swapping in matched decompiled functions

The seam of every module is a small C interface that already has the original's shape:

| Seam | Today | Matched replacement |
|---|---|---|
| ball model | `gp4b_probe/launch/step_flight/spin_*` over `Gp4bBall` (`gp4b_types.h` is offset-exact to the 0x540-byte original) | the matched `fn_889C2678`, `fn_889C19F0`, `fn_889C2818`, `fn_888A*` take the same `Gp4bBall *` / template row pointer |
| bounce, net, cord | `ball.c` | matched `fn_889C1C80` and the `fn_889C1F70` net branch (then the validated per-tick path is the original) |
| outcome decision | `shot.c decide` | matched `fn_886807C0` (needs PlayerCtx/world objects: provide a thin adapter filling the few fields it reads) |
| graph kernels | `ts4_graph_run` | matched `fn_8890E8B0`, `fn_88178F60`, ... `fn_8817A688` (small, leaf, closest to matching); same blob layout via a loader that builds the original's node tables |
| rules | `ref/gameplay/rules.c` | matched `fn_8866A1C8` family operating on the RulesInfo records |
| reach/selection/movement | `ref/gameplay/*.c` | matched `fn_8868B4E8`, `fn_8869B178`, `fn_8865DBA8` (already matched wrappers `gp2_swing_wrappers.c`), `fn_886B8468` |

Procedure per function: (1) the matched source lands in `src/xbox360/` (MSVC-for-PPC C, original `fn_` names mapped to
`ts4_` names); (2) add a compatibility layer in `port/core/compat/` that makes it compile with clang for wasm32:
a portable software implementation of the `__vector4` and VMX128 intrinsics declared in `src/xbox360/ts4_vector.h`,
`__fsel/__fmadds/__fnmsubs` as `fmaf`/selects, `__declspec` removed, big-endian accessors where the function reads
game blobs; (3) add `port/core/src/backend_<module>_matched.c` implementing the seam by calling the matched code and
select it with `make BACKEND_<MODULE>=matched` / a `-DTS4_BACKEND_*` flag in `build_wasm.sh` (the draft stays as the
default and as the oracle); (4) run both backends in lock step on randomized inputs and on whole matches: for modules
whose draft is validated (ball) they must agree bit for bit, which proves the compat layer; for draft modules the
matched code becomes the new reference and the divergence report is the review artefact; (5) matched code reads
`.rdata` constants through the pool (`g_ts4_script_constants`, `lbl_8814B910`...): add an optional blob section `POOL`
holding those bytes, exported from the user's own `Swing_DLL.xex`, and let the compat layer define the externs over
it, which also turns most `GAME` tunables that are pool constants into automatically exported data.

End state: the data blob is replaced by the game's own XData trees (Settings.bin, Expressions.bin, ... parsed by the
matched loaders, `docs/gameplay/df.md`) and the whole per-frame gameplay tick (`fn_886B5128` and the planners) runs
as matched code over the engine objects; `sim.c` then shrinks to the platform adapter (input injection, snapshot
export). Each step keeps the tests green because the seams and the golden traces do not change.

## 6. Known gaps and next steps (ordered)

Port work is paused (owner decision 2026-11-14: decomp first). What is still invented or stubbed:

1. **Template payload validation.** The loader does not bounds-walk the self-relative pointers inside `TPLS`; a
   hostile blob could make the ball model read outside the payload (traps in wasm).
2. **Policies with no decoded behaviour behind them:** aim point (aim tables `fn_886935A0`/`fn_88693040`); ShotDef
   ShotSpecific min/max; row -> shot-class name matching; CurrentVigor integration (S+0xF54); human ManualShotTiming;
   ShotComponents -> buttons for the AI; serve AI (ServeComponents unused); locomotion speeds; swing clip start;
   judge.
3. **Graph inputs the sim does not write** (left at `State.bin` defaults): ReceiverState `#c7b7bdac` fields
   S+0xC28/0xC2C/0xC38, S+0xD00/0xCF0, MinSpeed lines, IsFastBall, LetProbability input `#fea37f2e`.
4. **Animation:** autoswing modes of the swing-category walk are not walked; clip choice has no root-motion fit
   cost; the first clip of a subgroup is taken; only the male clip set is packed.
5. **Ball deviations:** cord touch still increments `bounce_count`; `skip_launch_step` not applied; reach-flag fan
   angles are tunables; bounce rotation convention is a draft.
6. Commit hysteresis (`fn_886A2E48`), hit-quality grade, doubles, other scoring classes, matched-code backends
   (section 5).

