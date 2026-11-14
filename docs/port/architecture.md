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

| Module (`ts4core`) | Source of truth (note; original functions) | Implementation | Status | Missing / gap |
|---|---|---|---|---|
| Soft libm | gp4b s9 (CRT double `exp`/`log` rounded to float) | `softmath.c` | validated (fma exact vs HW; exp/log agree after float rounding; golden vectors pass) | sin/cos/atan2 only for the draft bounce, not bit-exact |
| Ball arcs, launch solve, kinds DropTime/BounceSpeed/InitialSpeed/AverageSpeed/Apogee, apex, net height | `gp4b.md` s1-s6; `fn_888AAEA8/AAE00/AAB98/AAA70/AACB8/AA968/AB308/AB6C8/AB0E0/AB220/AB558/AD1C8/AB8D0/AC748/ACA68/ACDA8/AD0E8`, probe `889C2678`, spin `889C1868/889C0DC0`, launch `889C19F0` | `gp4b_ball_model.c` included as is | **validated** (golden vectors from the emulated original, 8 solver cases, probe, launch, per-tick before first bounce) | ball `a4`, `g`, radius, net height values are not located in the game data (gp4b s7): provisional |
| Per-tick step, first-bounce event | `fn_889C2818`, `fn_889C1F70` ground part | `gp4b_step_flight` | validated | world/local frame is kept local between ticks (no per-tick round trip) |
| Bounce response (speed loss, elevation, yaw kick, spin decay) | `gp4.md`; `fn_889C1C80` | `ball.c bounce_response` | draft (rotation convention of `fn_8864F7B8` assumed right-handed Rodrigues) | curves come from the template (data) |
| Net hit, net cord (Let) | `gp4.md` 1.4; `fn_889C1F70` net branch | `ball.c` | draft (height-test polarity M; which cord angle is yaw/pitch assumed) | cord params `ball+0x494..4A0` not located: provisional |
| Ball mode flags | `fn_889C0C70` | `gp4b_mode_flags` | validated | |
| Prediction (up to 600 ticks, 2 bounces) | `gp3.md` s2; `fn_886AD278` | `sim.c predict()` (runs the real stepper on a copy) | reference | per-sample difficulty `fn_886AB250` not done (graph role instead) |
| Request tree -> template row | `shot-to-template.md`; `fn_8865A938`, `fn_886715A0` | `shot.c ts4_tree_select` + blob `TREE` | reference | request booleans `IsMedium/IsPowerful/IsWood*/IsClassic/AdvancedServe` come from the swing (tier thresholds are `cfg+0xC70/0xC74`, M) |
| Shot templates | `shot-templates.md`, `gp4b.md` s1; `Settings.bin` rows (0x8C bytes) | blob `TPLS`, big-endian bytes handed to the ball model unchanged | validated layout | payload pointers are not bounds-checked (see gaps) |
| Outcome In/Out/Net/Let | `gp4b.md` s10; `fn_886807C0`, `fn_8866E318`, `fn_88672130`, `fn_88662C08`, RNG `fn_8861E598` | `shot.c` (decision table, rolls, clamp, push-out, dispersion, Net/Let aim bisection) | reference (M-high; not emulated) | `fn_88671B10` flags b50/b51 treated as open; demotion branch (`> 200 cm`) not done; the four error floats come from tunables + graph roles |
| Aim point | `shot-to-template.md` s4 aim tables (`fn_886935A0`, `fn_88693040`) | `shot.c` | **policy** (depth/width from stick, serve box targets) | aim tables not decoded |
| Analyser graph evaluator | `analyser-graphs.md`; `fn_8890E988/8890E8B0`, kernels `fn_88178F60...`, curve `fn_8817A688` | `data.c ts4_graph_run` over blob `GRPH` | **validated**: bit-identical to `tools/ts4_analyser.py` (itself verified on 8,525 evaluations of the real file) on random graphs incl. NaN/inf (3,000+ outputs per run in `test_port_core.py`) | cell -> variable table (U): roles are supplied by the blob |
| Stat curves, timing, fatigue, error, let, difficulty | graphs `DefaultAttributes`, `Baseline/VolleyTimingAbility`, `FatigueIngame`, `ShotDifficulty`, error graphs, `LetProbability` | roles `default_attributes`, `timing_*`, `shot_difficulty`, `shot_error`, `let_probability` | reference (evaluator validated; wiring needs a role file) | role files for the real graphs; fatigue is not simulated (role reserved) |
| Rules and scoring (singles, Standard class) | `rules-and-scoring.md`; `fn_8866A1C8`, `fn_88676DB0`, `fn_88676960`, `fn_88676AF0` ... | `ref/gameplay/rules.c` unchanged | reference (own host tests; wrapper tested here: games, deuce, fault/double fault, let, tiebreak, whole match) | mini-game scoring classes, doubles |
| Judge (in/out/net, bounces, serve box, let) | `rules-and-scoring.md`, umpire `gp5` | `sim.c judge()` | policy (structural rules of tennis; court line positions are tunables incl. the game's `2 * radius` tolerance) | the game's own event queue (`fn_8866E...`) not ported |
| Candidate window, reach speed | `gp2.md`; `fn_8869B178`, `fn_8868B4E8` | `ref/gameplay/swing_window.c` unchanged | reference (classification thresholds inferred in the ref) | turn time, anim-busy time and volley side logic of the original are not in the ref; distances are horizontal |
| Selection (arg-max) | `gp2.md`; `fn_8865DBA8` | `gp_select_best` | reference (behaviour complete per notes) | commit hysteresis `fn_886A2E48` not done (commit once per incoming shot) |
| Selection score | graph via role `selection_ground/volley`; AI feeds InputNotation 0 | `sim.c ai_commit` | reference when the role is present; else **policy** (`1 / (1 + reach speed)`) | real graphs/role mapping |
| Movement regime selector | `movement-and-ai.md`; `fn_88699FC0`, `fn_88688948` | `mv_select_move_state` | reference (order verified) | margin tables optional `CURV` |
| Movement planner state machine | `fn_886B8468`, `fn_886BD690` | `mv_update` in `ref/gameplay/movement.c` | reference; wired with the predicates that are known, the rest 0 (the AI's regime comes from the selector, not from the hop result) | ~12 predicates (`fn_886A9678`, zones, ...) |
| Locomotion | game: animation root motion | `sim.c player_update` (stick -> speed regime, acceleration limit) | **policy** | animation data, `RushSpeedCoef` role used when present |
| Swing timing | `gp7.md`, `stats-swing-clipfit.md` C; `fn_886D3AD8/886D4978` | button release -> contact after `swing.contact_delay_ticks`, contact sample search on the prediction, whiff if out of reach | **policy** (clip fit is a scaffold in `ref/gameplay/clip_fit.c`, not used) | AOD clips with EventRacket markers, time scaling |
| Stats | `stats-swing-clipfit.md` A; `fn_88699300` | `gp_stat_for_stroke` feeds `skill.current` | reference | |
| AI virtual input | `movement-and-ai.md` B (same pipeline, human flag cleared) | `sim.c ai_think`: stick toward the committed contact, sprint on Rush regime, press/release schedule, aim away from the opponent | reference for candidate/selection/move regime; **policy** for shot kind and aim | `ShotComponents` / `Repositioning` graphs (shot-style mix) not wired |
| Hit-quality grade, rewards, excitement, crowd | `gp1.md`, `gp8.md` s10.4 | not implemented | not done | not needed for a playable core |
| Serve toss/hold, doubles, other surfaces' swing takes | `gp4.md`, `surfaces.md` | not implemented | not done | |

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
Everything the renderer needs is in `Ts4Snapshot` plus the event stream.

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

1. **Real data.** Run the exporter against the disc: `TPLS`/`TREE`/`GRPH` first (everything for `ts4_shot_probe`), then
   locate `ball.a4/g/radius`, the pool constants, the reach tuning object, and write the role file for the real
   graphs (needs the cell table or a Xenia dump of `ctx+0x10`). Re-run `test_port_core.py` with a blob from the real
   `Settings.bin`: the template reader is the validated one, the tree/row-resolution code lives in the exporter.
2. **Template payload validation.** The loader validates every section it parses itself but not the self-relative
   pointers inside the game bytes of `TPLS`; a hostile blob could make the ball model read outside the payload. In wasm
   this traps (sandbox) but a bounds-walking validator for the five node types would make it a clean error.
3. **Commit hysteresis, hit-quality grade, fatigue, timing graphs in the loop** (`fn_886A2E48`, gp2 draft): the roles
   exist, the call sites need the stamina/tiredness state.
4. **Swing animation timing** (gp7): replace `swing.contact_delay_ticks` by clip-fit contact times from the AOD
   annotations once the animation export exists; feed `swing_t` to the renderer from the same source.
5. **Aim tables and shot-style mix** (`ShotComponents`, `Repositioning*` graphs) to replace the two policies.
6. **Matched-code backends** (section 5), starting with the graph kernels and the ball model.
7. Doubles (the group alternation of `fn_886B5128`), serve toss/hold, other scoring classes.
