# Browser front end and asset pipeline (`port/web/`, `tools/port/`)

Agent `portweb`. This is milestone 1 of the browser port: a static viewer that loads the user's own exported
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

* No player or venue meshes yet: the court is procedural and the player is a bone drawing. A static mannequin is
  shown only when no skeleton was exported.
* Which swing record belongs to which Havok clip is unknown (docs/havok.md), and which of the two Core skeletons is
  which player is unknown. 2,092 `CutScenes.arc` wavelet clips and the net rig are not exported.
* The WASM adapter was exercised against a scratch wasm32 build, not against a released `work/port/ts4core.wasm`
  from the core agent's CI. `port/core/js/ts4core.mjs` (their binding) writes `struct_size` 64 for `Ts4ShotIn`
  while the header's `sizeof` is 60; harmless today because the core does not check it.
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
