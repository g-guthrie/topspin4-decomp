# Browser front end and asset pipeline (`port/web/`, `tools/port/`)

Agents `portweb` (milestone 1) and `portplay` (milestone 2, section 6). Milestone 1 of the browser port is a static viewer that loads the user's own exported
assets, plays the Havok animation clips on the player skeleton, and flies a ball trajectory computed by `ts4core`
(WebAssembly) or by a labelled JavaScript fallback. Nothing from the game is committed or hosted: the export writes
under `work/port/` (git-ignored) and the viewer reads it from a local web server.

Related: `docs/port/data-format.md` (the blob `ts4core` loads), `port/core/include/ts4core.h` (the API),
`docs/havok.md` (skeleton and clip decoders), `docs/gameplay/input-to-shot.md`, `shot-to-template.md`, `gp4b.md`.

## 1. Quick start

```sh
# 1. one-time: the Havok class table (generated from your own Swing_DLL, never committed)
python3 tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll         # export_assets.py does this itself if --dll is given

# 2. export (reads the ISO in place; first run decompresses a 34 MB Core.arc entry and caches it, about 30 s)
python3 tools/port/export_assets.py --iso "orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso" \
        --dll orig/54540859/Swing_DLL.dll --core-clips 0-31
# 3. optional: the WebAssembly core (needs clang with the wasm32 target, see port/core/build_wasm.sh)
make -C port/core wasm                                                  # -> work/port/ts4core.wasm
# 4. serve the repository root and open the viewer
python3 tools/port/serve.py                                             # or: python3 -m http.server from the repo root
#    http://127.0.0.1:8000/port/web/
```

Viewer URL parameters: `?assets=URL` (default `../../work/port/assets/`), `?wasm=URL` (default
`../../work/port/ts4core.wasm`), `?blob=URL` (default `<assets>/gameplay/ts4core.dat`), `?surface=hard|clay|grass`.
Serve only on loopback: the exported assets are the user's own game data. three.js 0.160.0 is loaded from
`cdn.jsdelivr.net` through an import map in `index.html` (no build step, nothing vendored).

## 2. What the export produces (`tools/port/export_assets.py`)

Every part is optional and skipped with a message when its dependency is missing (`--only` / `--skip` select
parts, `--strict` stops on the first failure). `manifest.json` records the status of each part.

| Part | Output under `work/port/assets/` | Source | Notes |
|---|---|---|---|
| `havok` | `skeletons/player_<n>.gltf` (+ `.bin`): the two 71-bone Core skeletons, bones only (the mesh is the assets agent's). `clips/core_<i>.gltf`: one animation per file for the clips chosen with `--core-clips` | `Core.arc` entry `6932352f` via `tools/havok/` | node names equal the bone names, so a clip file drives either skeleton. Units metres (`--unit-scale 0.01` of the Havok centimetres). Additive delta clips are composed onto the reference pose. Measured: about 0.5 s and 130 KB per clip, so all 5,850 clips are roughly 50 minutes and 0.7 GB; `--max-gb` (default 10) stops writing when reached |
| `animdb` | `animations.json`: `clips` (every Core clip: codec, duration, frames, tracks, additive, exported file) and `records` (3,184 `AnimationsDB.bin` swing records: name, slot, tags, annotations, EventRacket contact, preparation) | `AnimationsDB.bin` + the CRC dictionaries | the record to clip link is **not established** (`docs/havok.md` section 8), so `records[].clip` is null unless `--clip-map FILE` supplies `{record name \| 8-hex id \| "#index": "core:<n>"}` |
| `gameplay` | `gameplay/shots.json`: the 37 `Settings.bin` template rows plus the `State.bin` row, compacted (curves, spin pairs, bounce curves, `T`) and the ball defaults (`radius_cm`, `a4`, `g`, `max_bounces` read from the `State.bin` ball block, net height 91.4 cm assumed). `gameplay/analyser.json`: the 341 analyser graphs. `gameplay/ts4core.dat` (+ `.manifest.json` with sha256 of every source member): the data blob | `Settings.bin`, `State.bin`, `Expressions.bin` via `tools/ts4data/templates.py`, `tools/ts4_analyser.py`, `tools/port/blob_writer.py` | blob sections written: `TPLS`, `TREE`, `GRPH`, `TUNE`. `ROLE` and `CURV` are not (research output of the core agent); `TUNE` merges the game values we can decode (ball block, `shot.net_aim_cm`/`let_aim_cm` at `Settings.bin` 0x158/0x15C, tier thresholds at 0xC94) over `port/core/data/provisional.tunables.json`. Checked: `TPLS` and `GRPH` are byte-identical to `port/core/tools/ts4d.py pack`; the C core loads the blob (37 templates, 341 graphs, 0 missing tunables) |
| `meshes` | `meshes/` | `tools/ts4_assets.py` (assets agent) | pending: `tools/ts4_mesh.py` and `tools/ts4_texture.py` exist, the exporter does not. When it appears, the part runs it with `--iso <iso> --out <out>/meshes` (extra arguments after `--assets-args`) |

`animations.json` time units: the swing records' `EventRacket` and `Preparation` values are unverified. All 1,638
EventRacket values lie in 0.06 to 0.68, which reads as a normalised phase of the clip (docs/gameplay/df.md says
60 Hz ticks), so the viewer treats a value <= 1 as a phase and larger values as ticks. The clip browser can pair a
swing record with a Core clip by eye (marker shown on the scrub bar) and download the pairing as `clip-map.json`
for `--clip-map`.

Pure helpers (`parse_clip_spec`, `contact_markers`, `build_animation_records`, `link_records`,
`read_ball_defaults`, `compact_shot_rows`, the blob section builders and readers) are covered by
`tests/test_port_export.py` with synthetic data only. The test also runs the JS ball model under `node` (skipped
when node is absent).

## 3. Viewer structure (`port/web/`)

```
index.html            panel + canvas, import map (three@0.160.0), no build step
css/style.css
src/main.js           bootstrap: scene, tabs, clip browser, shot panel, input tab, status tab, render loop
src/config.js         URL parameters, fetch helper
src/court.js          procedural ITF court (23.77 x 10.97 m, singles 8.23 m, service line 6.40 m, net 0.914/1.07 m)
src/player.js         PlayerRig: skeleton glTF + clip glTF -> AnimationMixer, bone-line drawing, racket-handle marker
src/ballview.js       trajectory line, bounce rings, ball playback at 60 Hz
src/core.js           backend loader and adapter: ts4core WASM (ts4core.h API) or the JS fallback
src/core_js.js        JS fallback ball model (documented formulas, labelled in the UI)
src/curves.js         curve20 / curve16 / table2d evaluators
src/input.js          keyboard + gamepad -> shot request (stub), request -> template row (decision tree)
```

World frame everywhere: x along the court with the net at x = 0, y up, z across (the game's frame, metres in the
viewer, centimetres at the ts4core boundary). The hitter is at x < 0 and faces +x.

**Clip browser.** "Core clips" lists all 5,850 container clips (grey = not exported; the info line prints the
command to export that clip), "Swing records" lists the 3,184 named records with their annotations. Transport:
play/pause, scrub, speed, loop, yaw offset (the rig's forward axis is detected from foot to toe in the reference
pose and pointed at +x; clips may disagree, hence the slider). The red dot is the `B_Racket_Handle` bone.

**Shot panel.** Pick a template row, contact point and landing target (or click the court; shift+click moves the
contact point), spin blend, `f4C` (0 = full secondary stage, the game's reset value), handedness and outcome mode
(In, or Net which makes the ball hit the net), then Launch. The ball flies the trace at 60 Hz (speed slider).
Readout: flight time and bounce tick, launch and arrival speed, ball-centre height at the net plane (from the
trace), apex, first bounce, events. Presets: baseline forehand, serve, volley, lob.

**Backends.** `loadCore()` tries `work/port/ts4core.wasm` plus the blob; if either is missing it falls back to the
JS model and the badge says `JS fallback: documented formulas, NOT ts4core` (orange). The WASM adapter:
instantiates with stub imports, allocates through the core's `ts4_wasm_alloc` (falls back to `__heap_base`),
`ts4_core_init`, `ts4_data_load`, then `ts4_shot_probe` / `ts4_shot_trace` (struct layouts of `Ts4ShotIn`
(60 bytes) and `Ts4ShotOut` (52 bytes) verified against the header with a C compiler). Verified in a browser
against a wasm32 build of the current core (api 1): the badge reads `ts4core WASM`, the preset shots match the
host build.

**JS fallback accuracy.** Double precision transcription of gp4.md 1.2 to 1.4 and gp4b.md section 5: arc 1
boundary-value form, the three kind solvers (DropTime, InitialSpeed, BounceSpeed) with the net-clearance raise and
the secondary stage (DropTime, InitialSpeed, BounceSpeed, Apogee), tick quantisation, spin drift vector, ground
bounce response (speed loss, elevation, yaw kick, spin decay), solid-net response, second bounce. Not modelled:
let/net-cord deflection, serve toss hold, Wood mode. Measured against the host build of the C core
(`ts4_shot_probe`/`ts4_shot_trace`, 9 shots x In/Net): bounce tick equal in 16 of 18 cases (the drop shot differs by
one tick in both modes), whole-trajectory distance (including the post-bounce arc and the net bounce) at most 12 cm, 20 cm for the
drop shot. Against `tools/ts4data/template_sim.py`'s C model over all 37 rows x f4C 0/1: flight time equal to
within one tick on every row. `ts4_shot_probe().net_height_m` is the original quirky value (it reads cached
exponentials of the previous call, gp4b section 5), so the viewer reports the height at the net plane from the trace
instead.

**Input stub (`input.js`).** Produces the shot request of `input-to-shot.md`: A/B/X/Y = Flat/TopSpin/Slice/Lob
(keys J, K, U, I; Space = Flat), LT/RT = Risk (L or Ctrl, a held flag read above 128/255), RB = sprint (Shift),
LB = speed swing, left stick (WASD or arrows, dead zone 0.4) = aim and movement. The first held shot button is
latched (Flat > TopSpin > Slice > Lob) and the request is emitted on its release. The request carries `shot`,
`risk`, `rush`, `tier`, the `ShotSelection/Request/@Is*` flags, `aim = {lateral, depth}` and the template row.
`rowForRequest()` implements the decision tree of `shot-to-template.md` section 3 (checked against the tree in the
exported blob for all 120 combinations of situation, stroke, tier, risk and serve kind: no mismatch). Port-side stubs,
marked as such in the source: the Medium/Powerful tier comes from hold time (0.20 s, 0.45 s; the game's analyser
graphs are not decoded), the stick to landing point mapping (the aim tables are not decoded), and the situation
(baseline, volley, smash, serve) is chosen in the UI. `toTs4Input()` returns the `Ts4Input` of `ts4core.h`.

## 4. Known limits

* The procedural court and the bone drawing remain as the fallback when no mesh export exists (`?venue=none`,
  `?p0=none`). Which of the two Core skeletons is which player is unknown. AOD clips (`CutScenes.arc`) and the net rig are not exported.
* The Shot tab's adapter (`core.js`) is a separate WASM instance from the one the Play and Tune tabs use
  (`port/core/js/ts4core.mjs`), so tunable edits made in Tune do not affect the Shot tab. Struct sizes: `Ts4ShotIn`
  is 60 bytes in the header, in `core.js` and in `ts4core.mjs` (`SIZES.shotIn`); an earlier note that the binding wrote 64
  was stale. `tests/test_port_web.py` now recomputes every boundary struct size from `ts4core.h` and compares it with
  both JavaScript sides (the core accepts `struct_size >= sizeof`).
* Clips use the default skeleton 0 (`--skeleton`); the additive composition convention is the assumption recorded in
  docs/havok.md section 8 (`--raw-additive` exports raw deltas).

## 5. Roadmap to a playable match

1. **Wire the match API.** Replace the shot panel's direct `ts4_shot_trace` with `ts4_match_start`, `ts4_set_input`,
   `ts4_step` at a fixed 60 Hz accumulator and render from `ts4_snapshot()` (ball, two players, score) with
   interpolation between ticks; `ts4_poll_events()` drives bounce/hit/net/point-end effects. `input.js`
   `toTs4Input()` is already the input struct. Needs the blob's `ROLE`/`CURV` sections for the full module set.
2. **Two players.** Instantiate two `PlayerRig`s, drive them from `Ts4PlayerView` (position, heading, move state,
   swing state and progress). Mirror for left-handed players. Needs the record to clip mapping.
3. **Animation selection.** Map move/swing state to clips: locomotion clips by planner state, swing clips by the
   core's chosen record. Time-scale a swing clip so its racket contact (EventRacket) lands on the contact tick
   (gp7). First task: establish the `AnimationsDB` record to Core clip link (export every clip, compare the contact
   marker with the `B_Racket_Handle` speed peak, or find the id to clip index table).
4. **Meshes and venues.** Load the assets agent's player meshes (skinned onto the same skeletons) and venue
   geometry and textures from `meshes/`; keep the procedural court as the fallback and for dimension checks.
5. **Camera.** Broadcast camera that tracks the ball and the players, serve and replay cameras, preset cuts on
   events (the game's cameras are data driven, not decoded).
6. **Rally loop and UI.** Serve flow (toss, fault, let, second serve), point/game/set messages, scoreboard from
   `Ts4ScoreView`, pause menu, retuning panel on top of `ts4_set_tunable()` (the tunable registry is in
   `ts4_tunables.def`).
7. **Input polish.** Gamepad rumble, remappable keys, analyser-driven Medium/Powerful tiers once the graphs bound by
   the `ROLE` section are decoded, touch controls.
8. **Audio (later).** Ball, bounce, net and crowd sounds keyed off the same events (gp5 documents the shot and
   bounce buckets); music and umpire calls.
9. **Packaging.** A loader page that lets the user point at their ISO (or pick files) and runs the export pipeline
   in a worker, so no local Python is needed; asset caching in IndexedDB.

## 6. Playable match (milestone 2, agent `portplay`)

Open `http://127.0.0.1:8000/port/web/` (the **Play** tab is the default). The page needs `work/port/ts4core.wasm`
(`sh port/core/build_wasm.sh`) and the exported blob; everything else degrades (no meshes: procedural court and
bone drawing; no animation export: static rigs).

### 6.1 What runs

```
frame clock --FixedStepper(60 Hz, <= 6 ticks/frame)--> MatchSession.tick():
    ts4_set_input(0, keyboard/pad)  ->  ts4_step  ->  ts4_snapshot  ->  ts4_poll_events
render: interpolateSnapshot(prev, cur, alpha)  ->  rigs, ball, camera, HUD     (positions and headings blend; a jump above 150 cm
        per tick or a new serve phase snaps instead of sliding)
```

| File | Role |
|---|---|
| `src/match.js` | `MatchSession`: wraps `Ts4Core` (`port/core/js/ts4core.mjs`), the accumulator, snapshot pair, event queue, `onTick` hook |
| `src/helpers.js` | every pure function (stepper, interpolation, locomotion class, swing class guess and clip choice, swing clip time, camera goal, scoreboard rows, event text, `.def` parsers, probe summaries). Unit-tested without a browser |
| `src/animator.js` | `ClipLibrary` (clip glTF loading, root motion removal, z mirror for the skinned export) and `RigAnimator` (mixer weights) |
| `src/play.js` | `PlayMode`: scene objects, per-tick animation triggers, camera, HUD, probe overlay |
| `src/tuning.js` | the retuning panel |
| `src/gltfload.js` | glTF loading with throttled, retried texture fetches (python's `http.server` resets connections under 90 parallel requests) |
| `clipmap.config.json` | animation mapping configuration (see 6.3) |
| `test/helpers.test.mjs`, `test/session_smoke.mjs` | node tests; `tests/test_port_web.py` runs them and skips when node, the wasm or the blob is missing |

URL parameters added: `?meshes=` (default `../../work/assets/`), `?venue=` (default `venue_Amsterdam`, `none` = procedural court),
`?p0=` / `?p1=` (default `player_Federer0` / `player_Safina1`, `none` = bone drawing). The exports come from
`tools/ts4_assets.py` (docs/assets.md). The venue glTF replaces the procedural court (the procedural net is kept: the export
has posts only); players load as skinned meshes (the 71 Havok bones plus meshes). The exported skinned players are z-mirrored
into a right-handed frame (docs/assets.md section 7), so every Havok clip is mirrored on load (`mirrorTrackValues`: position z
negated, quaternion `(x,y,z,w) -> (-x,-y,z,w)`) before it drives them. The bone-line fallback uses the clips unmirrored.
A `window.__ts4` hook (state, input, play) exists for console debugging.

### 6.2 Controls and flow

Move WASD / arrows or left stick (stick x = toward the opponent, shooter relative, as in `ts4core.h`). Hold J or Space (flat, pad A),
K (topspin, B), U (slice, X) or I (lob, Y) and release to swing; the hold time is the power (the core's `shot.charge_full_ticks`).
L or Ctrl = risk (slice + risk = drop shot), Shift = sprint, stick at release = aim. Serving: the server holds a shot button
(charging; the ball rises in the hand) and releases to serve; the core launches the ball on the release tick. The scoreboard
(sets won by games per set, current game points, server dot, second serve, tiebreak), point/fault/game messages and a one-line hint
come from the snapshot and events. Match panel: format (short, 1 set, best of 3), first server, ratings, seed, pause, single
step, 0.5x and 0.25x, camera, debug overlay (tick, state hash, per-player speed class / planner state / swing state, chosen
clip and its contact time scale, recent events). Typing in a form field neutralises the input.

Camera: a broadcast-style camera behind the human's baseline (8.5 m behind, 5.2 m high) that slides with the human's z and
leans toward the ball, smoothed with frame-rate independent exponential damping (`damp`); it snaps when the ends change. The
framing numbers (`CAM` in `helpers.js`) are port choices. The Follow button returns from the orbit presets.

### 6.3 Animation: what is measured and what is a port choice

* **Swing clip choice** uses `work/port/assets/clip_map.json` (`tools/port/clip_map.py`, docs/port/clip-map.md): record to Core clip
  exact for 3,183 of 3,184 records. `pickSwingClip()` takes the swing class (below), keeps the records of `animations.json` whose tags match
  `recordTags` in `clipmap.config.json`, requires their clip to be exported, and prefers the most `prefer` tags. The tag filters and the
  preferences are port choices (which of the many variants to show). The contact time is the record's `EventRacket` as a fraction of the
  clip (verified against racket-handle speed in clip-map.md). Only records that map to one Core clip (single clips and the base of sets)
  and the primary of two-clip blends are used; records with an appended AOD clip are skipped because their contact fraction refers to the
  summed length. Sets are played as their base clip (the eight additive layers are not applied). AOD clips are not exported or used.
* **Swing class** of a row follows `shot-to-template.md` (`swingClassForRow`). At swing start the core has not reported the row yet
  (`Ts4PlayerView.template_row` is valid after the hit), so the rig **guesses** the class (`guessSwingClass`: the buttons released, the
  ball position classified with the `reach.*` zone tunables, forehand when the ball is on the right for a right-hander). The hit event's row is
  shown next to the guess in the debug overlay. The AI's guess is topspin from the baseline.
* **Contact lands on the contact tick.** While `swing_state` is 1 the clip time is `contact * swing_t`, where `swing_t` is the core's
  progress to the contact tick (0 until the contact tick is `swing.contact_delay_ticks` away, then linear). `swing_t = 1` is reached at the
  contact tick, so the racket-contact marker lands exactly there; the effective time scale is `contact / (delay / 60)` (printed in the debug
  overlay). At contact the follow-through plays out over `swing.recovery_ticks`. Serves are launched on the release tick, so the serve clip
  jumps to its contact time at the serve event (a wind-up pose scrubbed by the charge while the button is held hides most of it).
* **Locomotion** (`idle`, `jog`, `run`, `rush`): classes from the planar speed with thresholds at the midpoints of `move.speed_walk_cms`,
  `move.speed_jog_cms`, `move.speed_rush_cms`. Clips are named records (`Idle_Baseline`, `Jog_Front_IK`, `Rush_Front`) that are real game clips;
  the choice of those variants, `run` reusing the jog clip, and the nominal root speeds that set the playback rate are **placeholders**
  (`nominalSpeedCms`). Root motion is removed from every clip (the hips' x/z are pinned to the first key): the sim owns position.
* The `core:N` entries of `clipmap.config.json` are fallbacks used only when the record's clip is not exported, and are labelled
  `PLACEHOLDER` in the debug overlay. Export what the page asks for (it lists missing clips in the Play tab):
  `python3 tools/port/export_assets.py --only havok animdb --clip-map auto --core-clips 0-31,281,290,421,607,617,1003,1054,1885,1994,2057,2302,2318,2334`
  (this is the set that the default mapping selects; `work/agents/portplay/needed.mjs` recomputes it).

### 6.4 Retuning panel (Tune tab)

* **Tunables.** Every entry of the core's registry (`ts4_tunable_count/name/get`), grouped by prefix, with unit, origin badge (G = decoded from the
  game, P = invented by the port) and the doc string of `include/ts4_tunables.def` (parsed by `parseTunablesDef`; the C ABI exposes none of these).
  Editing a value calls `ts4_set_tunable` immediately and re-reads it (float32). Changed rows are highlighted; filter by text or
  "modified only"; per-row reset; Reset all; Export overrides as JSON; Import. Overrides persist in `localStorage` and are re-applied (and the
  match restarted) on load. Values the core copies at match start (`APPLY_ON_RESTART`: the `move.*` planner settings) are marked R and need a
  restart; "restart match on edit" does it automatically. Everything else is read each tick.
* **Shot probe.** Pick a template (names from `shots.json`), contact point, landing target, spin blend, f4C, handedness and mode (In, Out, Net,
  LetIn). Probe runs `ts4_shot_probe` and `ts4_shot_trace` and reports flight time, bounce tick, launch and arrival speed, net height,
  apex, landing point; side and top views are drawn on canvases and, optionally, as a line over the court. **Pin baseline** keeps a result: later
  probes show the difference per field and draw the baseline in grey, so the effect of a tunable edit is visible at once. "Re-probe on edit"
  runs the probe after every tunable change.
* **Graphs and roles.** The roles of `ts4_roles.def` (what the sim runs when), the module status table, and an evaluator for any of the analyser
  graphs (`ts4_graph_eval`, inputs labelled from `analyser.json` when the name is known). The blob's ROLE section is not exported yet, so roles are
  unbound (modules read `degraded`).

### 6.5 Next steps

1. Export the ROLE/CURV blob sections so the shot/reach/move/swing modules leave `degraded` and the tuning panel can show per-role bindings.
2. Real swing selection data: have the core report the candidate swing record (or template row) at swing start so the rig does not guess.
3. Records with an appended AOD clip, AOD-only records and set layers (additive clips); then locomotion by direction (the `Jog_*`/`Rush_*` families
   exist for eight directions) and turn clips, with the real root-motion speeds from the clips instead of `nominalSpeedCms`.
4. A toss model in the core (the ball is drawn in the hand and lifted by the charge on the render side only).
5. Left-handed players use a mirrored rig; the game's own left-hand clips are not selected.
6. Use the Tune core for the Shot tab (one wasm instance), venue picker, audio cues from the events, replay camera, gamepad rumble.
