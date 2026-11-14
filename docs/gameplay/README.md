# Gameplay extraction notes

Working notes from the gameplay-first decompilation (see `docs/gameplay-map.md`
for the subsystem map). Each file is one work package. Where a note corrects
the map, the note is newer and wins.

| Note | Package | Main findings |
|---|---|---|
| [gp0.md](gp0.md) | Scheduler, recorders, XData glue | Vtable slots ([2] Update, [4] Init, [5] Exit); module order is data (CoreTech_Xenon.bin); gameplay engine singleton and per-instance step order; XData handle protocol; name hashes are zlib crc32 |
| [gp1.md](gp1.md) | Shot rewards and crowd excitement | Reward rules and thresholds, excitement gauge, point-end modifiers, court half-widths in cm |
| [gp2.md](gp2.md) | Swing candidate selection and reach | Units (cm, 60 Hz ticks); per-sample reach cost; Baseline/Volley/Smash/Unreachable candidate types; data-driven analyser scoring; commit hysteresis; AI uses the same path |
| [gp3.md](gp3.md) | Main frame, ball prediction, movement | Command applier and ball launch; the game's own ball stepper (not Havok) run up to 600 ticks for prediction; 23-state movement planner with Rush/Jog modes |
| [gp4.md](gp4.md) | Ball flight model and Havok wrapper | Closed-form ball flight (drag toward a spin drift vector plus gravity), template-driven bounce and spin, net and let-cord rules, km/h arrival-speed launch solve; Havok never drives the ball |
| [gp4b.md](gp4b.md) | Ball model spec and shot error model | Exact launch solve (commanded speed is initial km/h), kind routines DropTime/BounceSpeed/InitialSpeed/Apogee, template layout, golden-vector validated reference C; shot outcome In/Out/Net/Let decided by dice rolls against PlayerState error floats with court bounds and dispersion |
| [gp7.md](gp7.md) | Swing animation engine | Swing target written by the movement planner (contact position, time window, left-handed mirroring), clip choice by geometric fit at the EventRacket annotation, time scaling to the contact frame, AOD clip loader, per-frame order |
| [gp8.md](gp8.md) | Shot error inputs | Error probabilities are outputs of data-driven analyser graphs (ShotDifficulty, BaselineTimingAbility, VolleyTimingAbility, FatigueIngame, LetProbability...), not code; shot difficulty = required speed in m/s; timing-grade factors; outcome code never reads shot power |
| [input-to-shot.md](input-to-shot.md) | Controller input to shot request | Pad driver and data-driven InputMapper; A/B/X/Y = Flat/TopSpin/Slice/Lob, RT and LT both set Risk, RB sprint; shot-selection tree with Finesse/Medium/Powerful tiers; drop shot = Slice + Risk; smash automatic; advanced serve on the right stick |
| [controls-and-shot-selection.md](controls-and-shot-selection.md) | Pad to chosen shot (supersedes parts of input-to-shot / shot-to-template) | PlayerState schema decoded from Layoutall.bin; power = frames since last launch / D through a 0..1.25 ramp; tiers Finesse < 0.15 <= Medium < 0.70 <= Powerful from three analyser graphs; full 33-node tree; Risky rows only via the debug/shot-editor override; aim from Stick_Move; extractor `tools/ts4data/shot_tree.py`, reference `ref/gameplay/shot_select.c` |
| [shot-to-template.md](shot-to-template.md) | Shot request to template row and launch | A data decision tree in Settings.bin picks the row (serve type x tier, baseline tier x stroke, volleys, smash, wood); Finesse/Medium/Powerful tiers explain the repeated rows; Risky rows 12-15 are unreachable; ball speed comes from the row curve with no stat term in code; command fields located |
| [surfaces.md](surfaces.md) | Court surface | Surface changes sound, visuals and the clay-only swing takes, not ball physics; one global template table; smallest per-surface bounce hook is a trampoline at the bounce tail (0x889C1F58) |
| [df.md](df.md) | Data file formats | XBin `.bin` container, `.arc` archives (crc32 path hashes, XOR-masked FAT), 0x8C animation records with EventRacket annotations and AOD clip mapping, curve and 2-D table nodes, Havok 5.5 packfiles; readers in `tools/ts4data/` |
| [tunables-catalog.md](tunables-catalog.md) | Every gameplay tunable in the data | Layoutall.bin is a full reflection table; generic walker types every member; 274k editable scalars from 12 files dumped to `data/gameplay/tunables/` with path, offset and type; Settings root map (shot tree, templates, AI, aim tables, outcome geometry, movement profile, power curves, serve rules, reach, tier thresholds) with consumer reads; patch tool rebuilds the archive |
| [gp5.md](gp5.md) | Ball, bounce and umpire sound events | Shot class and power buckets, bounce angle/speed buckets, net/let arrive from the physics event queue, umpire score calls |
| [ball-physics.md](ball-physics.md) | Complete ball mechanics (G3) | Consolidated spec: template row fields, launch solve, flight, exact bounce and net/let-cord branches, court bounds and out grades, outcome dice, prediction, timing; portable C in `ref/gameplay/ball.c`, values in `data/gameplay/ball_templates.yaml` / `ball_trajectories.csv` |
| [graphs-decoded.md](graphs-decoded.md) | Every analyser graph (G1) | Curves are ramps: load-time slope fixup `fn_8890DFC8` → `fn_88179740` (templates: `fn_8867BB78`); every port bound to a named member via the 307-entry cell table; who runs each graph; shot error chain (FaultProbability, OutcomeNet, LetProbability); reader `tools/ts4_analyser.py`, values `data/gameplay/graphs.yaml` |
| [graphs-catalogue.md](graphs-catalogue.md) | Generated per-graph catalogue | One entry per graph with ports, runner and formula shape; `tools/ts4_graph_catalogue.py` |
| [player-and-movement.md](player-and-movement.md) | Player tuning, AI levels, movement modes, clip catalogue (G4) | Settings player block, AI difficulty table, speed override, 3,184 clips; `ref/gameplay/player.c`, `data/gameplay/player.yaml`, `animation_clips.yaml` |
| [stats-coaches-career.md](stats-coaches-career.md) | Ratings, coaches, career, AI records (G4b) | Raw ratings → DefaultAttributes graph → Profile 0..1; reaction delay written by AI positioning graphs; AI record layout (5 weighted lists, 6 graphs, speed limit); 110 coaches with budgets; clip-fit cost decoded; `tools/ts4data/career_data.py`, `data/gameplay/coaches_career.yaml` |
| [traits-and-skills.md](traits-and-skills.md) | Every skill/trait with magnitudes (G4b) | 30 working skills, 2 cut; all effects via shot-quality outputs (none touch ball parameters); checked against the community reference; `data/gameplay/traits_skills.yaml` |
| [movement-and-animation.md](movement-and-animation.md) | Movement and animation end to end (G6) | Clip record and qualifier masks decoded (46 types), selection-procedure filter DSL, move-set sectors, transition matrix/rules/events, clip clock (gp7 "ratio" is FrameCount), Dive volley trigger, special-swing classes and rewards; `tools/ts4data/anim_rules.py`, `data/gameplay/animation_rules.yaml`, `ref/gameplay/locomotion.c`, `anim_select.c` |
| [community-reference.md](community-reference.md) | Public documentation (R1) | Manual, patch notes, press and community claims with sources and confidence; 26 hypotheses for code verification; `data/gameplay/skills_community.yaml` |

Readable C for understood but not yet byte-matching functions lives in
`src/xbox360/drafts/`. Drafts are not part of the matching build and do not
count as progress; they exist so ports can use the logic before it matches.
Exact matches live in `src/xbox360/gp*_*.c` with the rest of the matched code.

Most tuning values (reach radii, preparation times, scoring weights, ball
templates) are loaded from game data files, not code. The notes name the
loaders and offsets; the values need the user's own game data.
