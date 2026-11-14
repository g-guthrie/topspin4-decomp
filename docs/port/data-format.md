# ts4core data blob (format version 1)

This is the contract between the export tools (`tools/port/`, written by the asset/data agent) and the
simulation core (`port/core/`, `ts4_data_load()` in `port/core/include/ts4core.h`). One local file, built
from the user's own disc, holds every number the core needs. **The blob is never committed** (it contains
bytes copied from the game); `port/core/data/provisional.tunables.json` is the only data file in the repo and
holds port-invented values only.

Reference writer/reader and a game-free synthetic blob generator: `port/core/tools/ts4d.py`
(`python3 port/core/tools/ts4d.py --help`). The C loader is `port/core/src/data.c`. They agree by test
(`tests/test_port_core.py`): a blob written by the Python tool is parsed by the C test binary.

## 1. Container

All integers little-endian, all floats IEEE binary32 little-endian, **except** the `TPLS` payload, which is a
verbatim copy of game bytes (big-endian).

```
0x00  char[4]  "TS4D"
0x04  u32      version = 1
0x08  u32      section_count
0x0C  u32      reserved = 0
0x10  directory: section_count x { char[4] tag, u32 offset, u32 size, u32 flags = 0 }
```

`offset` is from the start of the blob, 4-byte aligned, `offset + size <= blob size`. Unknown tags are ignored
(forward compatibility). A tag may appear once. Sections: `TUNE`, `TPLS`, `TREE`, `GRPH`, `ROLE`, `CURV`.
Only `TUNE` and `TPLS` and `TREE` are required for the ball/shot path; the match needs the full required
tunable set (section 8).

## 2. `TUNE`: scalar tunables

```
u32 count
count x { u32 key, f32 value, u32 flags }       sorted by key ascending, keys unique
```

`key = zlib.crc32(name.encode("ascii"))` (the engine's own name hash). `flags` bit 0 = **provisional** (a value
chosen by the port, not read from the game; the UI may show it differently). The names are the registry in
section 8 (`port/core/include/ts4_tunables.def`). Unknown keys are ignored, so the exporter can add
experimental values; a runtime override (`ts4_set_tunable`) wins over the blob.

## 3. `TPLS`: shot template rows (big-endian, verbatim)

```
u32 row_count            (37 in Settings.bin)
u32 row_stride           (0x8C)
u32 rows_offset          offset of row 0 inside the payload
u32 payload_size
u8  payload[payload_size]   (padded with zeros to a multiple of 4)
```

The payload is a byte-exact copy of a contiguous region of `Settings.bin` (the file of `Core.arc` entry
`0x334E7E0D`). Template rows reference their curves by **self-relative signed 32-bit offsets**, in both
directions, so the exporter must keep the relative layout: the simplest valid choice is the whole file
(`rows_offset = 0x137C`, `row_count = 37`, `row_stride = 0x8C`; see `docs/gameplay/shot-to-template.md` s1).
Trimming is allowed only if every byte any row reaches is kept at the same distance from the rows. The row
unique id is the big-endian u32 at `row + 0x88`. Row layout: `docs/gameplay/gp4b.md` s1 and
`src/xbox360/gp4b_types.h`; the core hands `payload + rows_offset + i * row_stride` to the ball model unchanged.

## 4. `TREE`: shot request decision tree

The tree `Settings.bin` stores at file `0x24` (shot-to-template.md s2/s3), flattened:

```
u32 node_count
u32 root                 index of the root node
node_count x { u32 cond_hash, i32 child_true, i32 child_false }
```

`child >= 0` is a node index; `child < 0` is a leaf and `~child` (= `-child - 1`) is the **template row index**
(the exporter resolves the leaf's row id to the row whose `row+0x88` equals it, exactly as the game's init pass
does). `cond_hash` = `crc32` of the request attribute: `IsWoodDown, IsWood, IsClassicServe, IsAdvancedServe,
IsSmash, IsBaseLine, IsTopSpin, IsSlice, IsLob, IsRisk, IsMedium, IsPowerful`. Depth <= 32; no cycles (validated).
A condition the core does not know evaluates false.

## 5. `GRPH`: analyser graphs (normalised from `Expressions.bin`)

```
u32 graph_count
graph_count x { u32 name_hash, u32 offset, u32 size }      offset relative to the section start
```

Graph record (offsets relative to the start of the graph record):

```
+0x00 u32 name_hash        (= GraphDef +0x28)
+0x04 u32 nregs
+0x08 u32 n_in
+0x0C u32 n_out
+0x10 u32 n_nodes
+0x14 u32 ports_off        n_in input ports then n_out output ports, 16 bytes each
+0x18 u32 nodes_off        n_nodes x 32 bytes
+0x1C u32 reserved
port : { u32 domain, i32 cell, u32 reg, u32 path_key }
       domain/cell/path_key are informational for the role table (path_key = crc32 of the concatenated big-endian
       path name hashes); reg is the register the port reads/writes
node : { u32 kind, i32 out, u32 a, u32 b, u32 t, u32 n, u32 off, f32 value }
```

Node kinds and fields (semantics are exactly `tools/ts4_analyser.py` `evaluate_node`, all arithmetic
single precision, fused multiply-add where the original uses it; `docs/gameplay/analyser-graphs.md` s4):

| kind | name | fields |
|---|---|---|
| 0 | CONST | `out`, `value` |
| 1 | SUM | `out`; `n` slots (u32 registers) at `off` |
| 2 | PRODUCT | same |
| 3 | MIN | same |
| 4 | MAX | same |
| 5 | CURVE | `a` = input register, `out` (< 0: node skipped), `n` keys at `off`: 4 x f32 `{x0, x1, y0, slope}` |
| 6 | RUNSUM | `out`; `n` slots (result -1.0 if any slot is negative) |
| 7 | SUB | `a`, `b`, `out` |
| 8 | DIV | `a`, `b`, `out` |
| 9 | LERP | `a`, `b`, `t`, `out` |
| 10 | INVLERP | `a`, `b`, `t` (the x), `out` |
| 0xFFFFFFFF | UNKNOWN | skipped, like the runtime |

`ts4d.py graphs_from_expressions()` converts a parsed `Expressions.bin` (via `tools/ts4_analyser.py`) into
this layout. Registers start at 0.0 and ports are written in order, like the Python evaluator.

## 6. `ROLE`: binding of graphs to core variables

The game binds graph ports to `PlayerState` memory through a cell table that is not decoded yet
(`analyser-graphs.md` s5). The port therefore binds by *role*. One record per role, concatenated:

```
u32 role_count
role_count x { u32 role, u32 graph_hash, u32 n_in, u32 n_out, u32 in_var[n_in], u32 out_var[n_out] }
```

`role` and `*_var` are the numeric ids from `port/core/include/ts4_roles.def` (append-only lists; listed in
section 9). `in_var[i]` is the core variable written into the graph's i-th input port before evaluation,
`out_var[j]` the variable that receives the j-th output port. `n_in` must equal the graph's input count
(`n_out` its output count). Use `zero` for ports whose meaning is unknown. A role without a record is not run.
Which graph/cells realise each role is research output; only this section changes when it is decoded.

## 7. `CURV`: named curves and 2-D tables (little-endian)

```
u32 count
count x { u32 name_hash, u32 type, u32 n, u32 off }       off relative to the section start
type 0  curve16 : n keys of 4 x f32 {x0, x1, y0, y1}      y = y0 + clamp((x-x0)/(x1-x0), 0, 1) * (y1-y0)
type 1  curve20 : n keys of 4 x f32 {x0, x1, y0, slope}   y = y0 + slope * clamp(x-x0, 0, x1-x0)
type 2  table2d : n rows, each { f32 a_key, u32 nkeys, nkeys x 4 x f32 curve16 keys }, rows ascending in a_key
```

Evaluation follows `fn_881899D8`, `fn_8817A688`, `fn_8826D278` (`docs/gameplay/gp4b.md`). Names (crc32) used by
the core: `move.table.rush`, `move.table.jogjog`, `move.table.jog` (table2d, row key = distance cm, column =
slack ticks; the movement validity margin, `movement-and-ai.md`). All optional: without them no run mode is
ever "valid" and the planner stays in Approach.

## 8. Tunable registry

Generated from `port/core/include/ts4_tunables.def` (`python3 port/core/tools/ts4d.py registry`). ORIGIN
`GAME` = the value exists in the game; the exporter should fill it from the decoded location in the last
column. `PORT` = invented by the port; `provisional.tunables.json` supplies it. `R` = required to start a match.

| name | unit | origin | req | source / meaning |
|---|---|---|---|---|
| `ball.radius_cm` | cm | GAME | R | ball+0x4D0; writer not located (gp4b s7) |
| `ball.a4` | s | GAME | R | ball+0x4D4 drag time constant; k = T / a4; loc U |
| `ball.g` | m/s^2 | GAME | R | ball+0x4D8 gravity; loc U |
| `ball.max_bounces` | count | GAME | R | ball+0x4DC; fn_886B1BA0+0x2178 stores 10 |
| `ball.net_height_cm` | cm | GAME | R | ball+0x124 / cfg+0x124 net height at the crossing |
| `ball.net_restitution` | ratio | GAME | R | pool+0x10C = 0.2 (velocity factor after a solid net hit) |
| `ball.cord_angle_a_deg` | deg | GAME | R | ball+0x494 net-cord deflection (gp4 s1.4) |
| `ball.cord_angle_b_deg` | deg | GAME | R | ball+0x498 net-cord deflection |
| `ball.cord_speed_loss` | ratio | GAME | R | ball+0x49C |
| `ball.cord_spin_loss` | ratio | GAME | R | ball+0x4A0 |
| `ball.disp_x_lo_cm` | cm | GAME | R | ball+0x4C0 landing dispersion box (gp4b s10.3) |
| `ball.disp_x_hi_cm` | cm | GAME | R | ball+0x4C4 |
| `ball.disp_z_lo_cm` | cm | GAME | R | ball+0x4C8 |
| `ball.disp_z_hi_cm` | cm | GAME | R | ball+0x4CC |
| `court.half_length_cm` | cm | PORT | R | baseline |x|; gp4b s10.3 lists 1194.5 incl. tolerance (pool const) |
| `court.half_width_singles_cm` | cm | PORT | R | singles sideline |z|; gp4b s10.3 lists 415.5 incl. tolerance |
| `court.half_width_doubles_cm` | cm | PORT | R | doubles sideline |z|; gp4b s10.3 lists 552.5 |
| `court.service_line_cm` | cm | PORT | R | service line |x|; gp4b s10.3 lists 646.0 |
| `shot.net_aim_cm` | cm | GAME | R | cfg+0x134 = S+0x750 Net outcome aim height (80.0 on disc) |
| `shot.let_aim_cm` | cm | GAME | R | cfg+0x138 = S+0x754 Let outcome aim height (90.0 on disc) |
| `shot.min_depth_cm` | cm | GAME | R | pool+0x604/0x610 = 75: minimum depth past the net for an In shot |
| `shot.out_margin_cm` | cm | GAME | R | pool+0x4C = 3: how far outside the line an Out shot lands |
| `shot.tier_medium` | 0..1 | GAME | R | cfg+0xC70 = 0.4 (power above which the Medium tier applies; role M) |
| `shot.tier_powerful` | 0..1 | GAME | R | cfg+0xC74 = 0.7 |
| `shot.charge_full_ticks` | ticks | PORT | R | ticks of holding a shot button for full power (game: curves cfg+0x8FC..0x920 over *(flags+0x44)) |
| `shot.error_prob` | 0..1 | PORT | R | initial S+0x718 (graph ERROR refines it) |
| `shot.error_added` | 0..1 | PORT | R | initial S+0x564 |
| `shot.let_prob` | 0..1 | PORT | R | initial S+0x71C (graph LET refines it) |
| `shot.net_share` | 0..1 | PORT | R | initial S+0x720: share of errors that are Net |
| `shot.spin_blend` | 0..1 | PORT | R | initial S+0x774 (spin lerp between template lo/hi) |
| `shot.f4c` | 0..1 | PORT | R | initial S+0x778 (secondary stage weight w = 1 - f4C) |
| `shot.net_let_enabled` | 0/1 | PORT | R | gate G of gp4b s10.2 (bytes match+0x328/0x329 meaning unknown) |
| `aim.depth_cm` | cm | PORT | R | default landing depth past the net for a groundstroke |
| `aim.depth_stick_cm` | cm | PORT | R | extra depth at full forward stick (negative = shorter) |
| `aim.width_stick_cm` | cm | PORT | R | lateral offset at full sideways stick |
| `aim.serve_x_cm` | cm | GAME | R | serve landing x past the net (aim table 0x12C entries, x ~485..535) |
| `aim.serve_z_cm` | cm | GAME | R | serve landing |z| (z ~145..180) |
| `serve.contact_height_cm` | cm | PORT | R | ball height at serve contact |
| `serve.baseline_x_cm` | cm | PORT | R | server's |x| when serving |
| `serve.start_z_cm` | cm | PORT | R | server's |z| offset from the centre mark |
| `receive.baseline_x_cm` | cm | PORT | R | receiver's |x| when the point starts |
| `reach.volley_x_max_cm` | cm | GAME | R | ReachTuning+0xD8: |sample.x| below this = volley zone |
| `reach.volley_max_bounce` | count | GAME | R | bounce index limit of the volley zone (gp2: <= 2) |
| `reach.split_height_volley_cm` | cm | GAME | R | ReachTuning+0x44 |
| `reach.split_height_other_cm` | cm | GAME | R | ReachTuning+0x40 |
| `reach.smash_lo_volley_cm` | cm | GAME | R | ReachTuning+0x48 |
| `reach.smash_hi_volley_cm` | cm | GAME | R | ReachTuning+0x4C |
| `reach.smash_lo_other_cm` | cm | GAME | R | ReachTuning+0x50 |
| `reach.smash_hi_other_cm` | cm | GAME | R | ReachTuning+0x54 |
| `reach.radius_right_cm` | cm | GAME | R | ReachTuning+0xF4 |
| `reach.radius_left_cm` | cm | GAME | R | ReachTuning+0x100 |
| `reach.prep_ticks_volley` | ticks | GAME | R | ReachTuning+0x108 |
| `reach.prep_ticks` | ticks | GAME | R | ReachTuning+0x104 |
| `reach.unit_scale` | m/s per cm/tick | GAME | R | pool+0x114 = 0.6 |
| `reach.speed_cap` | m/s | GAME | R | finite clamp of a required speed (FLT_MAX in gp2 draft; use a large number) |
| `reach.unreachable` | m/s | GAME | R | pool+0x20 = 100 |
| `reach.far_default` | m/s | GAME | R | stored for samples with no usable geometry |
| `reach.min_time_ticks` | ticks | GAME | R | pool+0x00 = 1: minimum preparation slack |
| `reach.net_margin_cm` | cm | GAME | R | gp2: samples with |x| <= 150 are not candidates |
| `reach.score_max_speed` | m/s | GAME | R | pool+0xF0 = 50: above this the score is -1 |
| `swing.contact_delay_ticks` | ticks | PORT | R | ticks from button release to racket contact (game: clip fit at EventRacket) |
| `swing.recovery_ticks` | ticks | PORT | R | ticks the player is locked after contact |
| `swing.contact_slack_cm` | cm | PORT | R | extra distance tolerated at contact on top of the reach radius |
| `move.speed_rush_cms` | cm/s | PORT | R | locomotion speed in the Rush regime (game: animation root motion) |
| `move.speed_jog_cms` | cm/s | PORT | R | Jog regimes |
| `move.speed_walk_cms` | cm/s | PORT | R | walk / approach |
| `move.accel_cms2` | cm/s^2 | PORT | R | acceleration limit |
| `move.reaction_frames` | ticks | GAME | R | profile record +0x1DC (state 0 wait) |
| `move.rush_guard` |  | GAME | R | cfg+0x630 |
| `move.min_distance_rush` | cm | GAME | R | cfg+0x270 mode record minimum distance |
| `move.min_distance_jogjog` | cm | GAME | R | cfg+0x284 |
| `move.min_distance_jog` | cm | GAME | R | cfg+0x298 |
| `move.validity_threshold` |  | GAME | R | pool 0x8814B910 = 0.5 |
| `move.max_hops` | count | GAME | R | 8 (fn_886BD690 loop bound) |
| `flow.point_end_ticks` | ticks | PORT | R | pause after a point before the next serve |
| `flow.ai_serve_delay_ticks` | ticks | PORT | R | AI waits this long before serving |
| `flow.ai_power` | 0..1 | PORT | R | AI holds the shot button for this fraction of shot.charge_full_ticks |

## 9. Roles and variables

Roles (`ROLE` section, numeric id = position):

| id | name | graph | when the sim runs it |
|---|---|---|---|
| 0 | `default_attributes` | DefaultAttributes (0x8C9B26E0) | match start, per player: stat.* -> profile.* |
| 1 | `fatigue_ingame` | FatigueIngame (0xCBE44A9B) | reserved: stamina is not simulated yet |
| 2 | `timing_baseline` | BaselineTimingAbility (0x85F4C811) | before a groundstroke: profile.* -> timing.state |
| 3 | `timing_volley` | VolleyTimingAbility (0xA6DFABAA) | before a volley: profile.* -> timing.state |
| 4 | `shot_difficulty` | ShotDifficulty (0xDDA048F3) | per candidate sample: ball.dist_m, reach.speed -> ball.difficulty |
| 5 | `shot_error` | error graph (E4F01642 / 46C7BB5F) | before the outcome roll: fatigue, timing, difficulty, stats -> error.prob |
| 6 | `let_probability` | LetProbability (0xBDD29CAD) | immediately before the let roll: let.ctx.0 -> let.prob |
| 7 | `selection_ground` | swing selection scorer (ground) | per candidate: reach.speed, ball.difficulty, input.notation -> selection.score |
| 8 | `selection_volley` | swing selection scorer (volley) | same for volley candidates |
| 9 | `rush_speed_coef` | RushSpeedCoef (0x0340A26E) | each tick while moving: profile.*, fatigue.out -> coef.rush |
| 10 | `swing_speed_coef` | SwingSpeedCoef (0xB5CFF9B7) | at swing start: -> coef.swing (scales swing recovery) |

Variables (numeric id = position):

| id | name | meaning |
|---|---|---|
| 0 | `zero` | constant 0, bind unmapped input ports here (writes to it are discarded) |
| 1 | `stat.serve` | S+0x64C |
| 2 | `stat.return` | S+0x650 |
| 3 | `stat.forehand` | S+0x654 |
| 4 | `stat.backhand` | S+0x658 |
| 5 | `stat.volley` | S+0x65C |
| 6 | `stat.power` | S+0x660 |
| 7 | `stat.speed` | S+0x664 |
| 8 | `stat.stamina` | S+0x668 |
| 9 | `profile.0` | DefaultAttributes output (cell order of the graph's output ports) |
| 10 | `profile.1` |  |
| 11 | `profile.2` |  |
| 12 | `profile.3` |  |
| 13 | `profile.4` |  |
| 14 | `profile.5` |  |
| 15 | `profile.6` |  |
| 16 | `profile.7` |  |
| 17 | `fatigue.in` | Fatigue.Input cells 19/21/22 (stamina state) |
| 18 | `fatigue.out` | Fatigue.Output cell 16/188 |
| 19 | `ball.dist_m` | S+0x7A0: distance player to contact sample, metres (gp8 s4.1) |
| 20 | `reach.speed` | S+0x7A4 / Reachability, m/s |
| 21 | `ball.difficulty` | S+0x7A8 output of ShotDifficulty |
| 22 | `input.notation` | InputNotation (0 for AI) |
| 23 | `selection.score` | Selection Score output |
| 24 | `ticks.since_first` | ticks since the first candidate sample, -1000 when negative |
| 25 | `hit.height_cm` | contact height |
| 26 | `shot.ctx.0` | ShotContext members (ShotContext domain 0x53A7FCCE); meaning U |
| 27 | `shot.ctx.1` |  |
| 28 | `shot.ctx.2` |  |
| 29 | `shot.ctx.3` |  |
| 30 | `timing.state` | TimingState cell 106 (timing ability output) |
| 31 | `error.prob` | S+0x718 |
| 32 | `error.added` | S+0x564 |
| 33 | `let.prob` | S+0x71C |
| 34 | `net.share` | S+0x720 |
| 35 | `spin.blend` | S+0x774 |
| 36 | `shot.f4c` | S+0x778 |
| 37 | `shot.power` | S+0xE00 (0..1) |
| 38 | `skill.current` | S+0x74C: stat of the current stroke (stats-swing-clipfit.md s1.3) |
| 39 | `let.ctx.0` | Commands.LetCommands.Inputs cell 114 (BallState) |
| 40 | `let.ctx.1` | cell 115 |
| 41 | `let.out.0` | Commands.LetCommands.Outputs cells 277..280 (LetSettings) |
| 42 | `let.out.1` |  |
| 43 | `let.out.2` |  |
| 44 | `let.out.3` |  |
| 45 | `coef.rush` | RushSpeedCoef output (AnimationSelection.Movement cell 202) |
| 46 | `coef.swing` | SwingSpeedCoef output (cell 201) |
| 47 | `generic.0` | spare slots for experiments in the role file |
| 48 | `generic.1` |  |
| 49 | `generic.2` |  |
| 50 | `generic.3` |  |

## 10. What the export tools must produce (checklist for `tools/port/`)

1. `TPLS` from `Settings.bin` (whole file), `TREE` from the tree at `0x24` with leaf ids resolved to rows.
2. `GRPH` from `Expressions.bin` (all 341 graphs; `ts4d.py` has the converter).
3. `TUNE` for every `GAME` tunable whose location is known, merged over `provisional.tunables.json`.
4. `ROLE` from a hand-maintained role file (JSON: `{"role": "shot_difficulty", "graph": "ShotDifficulty",
   "in": ["ball.dist_m", "reach.speed", "zero"], "out": ["ball.difficulty"]}`); `ts4d.py` resolves names.
5. `CURV` for the three movement margin tables when located.
6. Record sha256 of every source file in a sidecar `*.manifest.json` (AGENTS.md rule); never commit the blob.

A blob with only `TUNE` + `TPLS` + `TREE` + `GRPH` is enough for `ts4_shot_probe`/`ts4_shot_trace` and for
graph evaluation; the full match additionally needs every `R` tunable (provisional ones are fine).
