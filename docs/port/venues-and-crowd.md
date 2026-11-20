# Venues, courts and crowd (agent A1)

Status: the formats are decoded, the export runs for every venue, and the viewer renders the venue, crowd,
officials and lights. The trigger code for the crowd is not found yet. Port work paused here on the owner's
decision (2026-11-14). The open items are listed in section 7.

Confidence marks: **C** = confirmed by bytes or by code; **I** = inferred (consistent but unproven); **P** = port choice.

## 1. Tools and commands

| what | command |
|---|---|
| inventory (45 venue archives + Desc records) | `python3 tools/ts4_venue.py inventory [--json]` |
| crowd summary of one archive | `python3 tools/ts4_venue.py crowd Amsterdam.arc` |
| one venue to glTF/JSON | `python3 tools/ts4_venue.py export Amsterdam.arc --out DIR [--crowd-lod 2]` |
| shared TrackSide skeletons + clips | `python3 tools/ts4_venue.py trackside --out DIR` |
| port asset tree | `python3 tools/port/export_assets.py --only venues [--venues all\|A,B] [--crowd-lod N]` → `work/port/assets/venues/` |
| readable tunables | `python3 -I tools/ts4_venue.py crowd-yaml --out data/gameplay/crowd.yaml` |
| tests (synthetic bytes, plus a node FSM test) | `python3 -m unittest tests.test_venue`, `node --test port/web/test/crowd_fsm.test.mjs` |
| viewer | serve the repo root, open `/port/web/venue.html?venue=Amsterdam[&tier=0..2]` |

Environment: `TS4_ISO` = the disc image, `HAVOK_CLASSES=work/havok/classes.json`. Python 3.13.18, node 22.23.4,
three.js r160 (CDN import map), and only the standard library.

Measurements on this disc:
- `CrowdAmsterdam.bin` is 523,838 B, sha256 `f4191aa35ec583fbf2257fa6ad91a20713887ad7c2ea1b0dc280b4db96c8f9ef`.
- `Settings.bin` (Core.arc 334e7e0d) is 286,492 B, sha256 `55cb175d…a0167`.
- `TrackSideBehaviorList.bin` (Amsterdam) has sha256 `9c113c7f…91af`.
- The full hashes are in `data/gameplay/crowd.yaml`.
- An Amsterdam export takes about 39 s and writes:
  - a static scene of 117 meshes and 171 nodes, with 21 skinned nodes moved to trackside;
  - 5 officials models, 11 crowd models and the net.

## 2. Inventory

- There are 45 venue archives on the disc root. `classify_archive` identifies them by a `Crowd<V>.bin` or a `TrackSide.hkx` member.
  - The list includes the special archives `PlayerBackGround` (no crowd), `PracticeGroundPart` and `TopSpinAcademy`.
  - Six Desc records in `Global.arc` have no archive: AtlantaSchool, PC_Presets, PC_Thumbnails, PracticeGround, Rio and Tokyo. **C**
- Venue Desc (`Global.arc <V>Desc.bin`, XBin root f36d2871) has these fields:
  - CodeName, SurfaceKey, `e4e9cc69` (Indoor/Outdoor), TypeKey (GrandSlam/Masters/Major/Minor/Special/Playground);
  - WeatherKey (Sunny/Cloudy/Clear, plus one unresolved key `64042c35`);
  - CapacityKey, a spectator model list, HasUmpire, EntranceType (Center/Side) and CorridorName.
  - There are no night variants. **C**
- Crowd sizes run from 0 (Dubai, PlayerBackGround) through 12 (Riviera), 32 (Atlanta) and 5,836 (Amsterdam) up to
  29,709 (ArthurAshe). Per-venue counts and groups are in `data/gameplay/crowd.yaml`. **C**

## 3. Scene format (venue archive)

### 3.1 Static scene and court

- The scene directory is picked by `ts4_assets.pick_scene_dir`. It holds PackedMeshes.xbin, Hierarchy.xml, materials, textures and PackedLights.bin.
- `export_venue` writes `venue.gltf` without the skinned meshes; those go to `trackside/`.
- Frame: the game is left-handed, Y up, in cm. glTF is metres with z negated. Quaternions are mirrored as (-x, -y, z, w). **C**
- Core positions in cm map to the venue frame as `[x, y, -z] * 0.01`. This is `coreToVenue` in `src/venue/venue_scene.js`.
- **Court lines.** `GroundLines` is textured quads wider than the painted line. Each quad's outer-edge midpoint
  matches the ITF centre to the centimetre: baseline 11.885, service 6.40, singles 4.115 and doubles 5.485 m. **C**
  - The gameplay in/out bounds (ball-physics.md s7, fn_8866E318) are the line centre + 4 cm on the sides
    (415.5 and 552.5 cm) and + 6 cm on the baseline and service line (1194.5 and 646 cm).
  - The 2 × radius tolerance comes on top. The court art therefore agrees with gameplay.
  - The comparison is stored per venue in `venue.json court_lines`. `court_line_check` computes it with the quad-midpoint method.

### 3.2 Lights (PackedLights.bin, root 5dfe2627)

- Each record is 0x34 bytes:
  - +0 name pointer, +4 type, +8 IsUsed;
  - +0x0C user-props pointer (three floats, meaning unknown);
  - +0x10 colour, +0x1C AmbientToShadowModulator, +0x20 four floats, +0x30 Multiplier. **C** for the layout and names; **I** for the four floats.
- Amsterdam has LightCrowd (mult 0), LightEnv (1.1), PlayerLight (0.85) and Sun01 (1.1).
- Hierarchy Light nodes carry only a position. The direction is taken from that position toward `<name>_Target`, or toward the origin when there is no target. **I**
- In the port, LightEnv is a shadowed directional light and PlayerLight is a weak fill. The hemisphere sky colour by weather is **P**.

### 3.3 Trackside people and the net (skinned)

- Skinned stadium meshes are Ballboy00, Judge01, OffcialMan00, OfficialWoman00 and SecurityMan01. Track_Type7_00 is a placement that uses material SecurityMan01_05.
  - Their Geometry UserProperties name a setup (`TrackSideSetupList:/SetupList/Animation[@Name="TS_LJ04"]`) and behaviours (Idle##, Flourish_XX_YY). **C**
  - They are exported to `venue.json trackside.placements` with their hierarchy matrix.
- The crowd models (Spectator02/03, SpectatorW00–02, Vip00–03, Stander00/02) each have a scene directory with a plain Hierarchy.xml.
  - They are skinned to the 19-bone TrackSide human skeleton and modelled in that skeleton's reference pose. **C**, checked by joint centroids.
  - Bone index bytes are reversed relative to the weights. **C**
  - Mesh groups are LODs: 8 for the crowd (2670 down to 55 triangles) and 7 for the officials. **I**
- The net has its own directory (66730038). Its `Net` mesh is skinned to the net skeleton (B_Hips, Filet_D01–09, Filet_G01–09) and uses setup TS_NET00. **C**
- **TrackSide.hkx** (entry 1539c50b) is the same file in every venue archive.
  - Skeleton 0 is the net and skeleton 1 is the human; both have 19 bones.
  - It holds 384 wavelet clips with 19 tracks each.
  - docs/havok.md calls this file only a net rig. That is incomplete; it also carries the human rig. **C**
- Core.arc `TrackSideAnimationList.bin` (be22e5c4) has 384 keys, and a behaviour's AnimID is the clip binding index. **C**
- Core.arc `TrackSideSetupList.bin` (d87cdc9c) has 58 Animation entries. Each has a Name, a setup index `3c330045`
  (LJ=0, BB=1, NET=2, UC=3, SE00..15=4..19, ST00..03=20..23, STANDARD=24) and 44 (net: 19) identity matrices that serve as a runtime palette. **C**
- **Architecture:** each setup is one animated skeleton shared by every instance that references it. **I**, strong: the setup list holds one matrix palette per setup.
  - So the crowd is 16 sections, each with one pose. The port does the same: one rig per setup.

### 3.4 TrackSideBehaviorList.bin (venue archive, root 5fe433ed)

- The file has 25 member lists in setup-index order, plus a float `ecdc2a09` = 1.0.
- Each Behavior has HKXPath, Name and AnimID. A composite has a start sequence (`081ddbd2`) and a stop sequence (`2452c65f`). **C**
- The full graph is in `data/gameplay/crowd.yaml behaviour_graph`. The main entries:
  - **Spectator sections:**
    - `ApplauseX` = start [XIn, XLoop], stop [XOut, Idle], for X in Low/Average/Strong/Wild.
    - `DeceptionLow` and `DeceptionAverage` = [DeceptionXIn, ApplauseXLoop] → [ApplauseXOut, Idle].
    - SE08..15 reuse the clips of SE00..07. The port starts each section at a random phase (**P**).
  - **Line judges:** Idle, Watch1/2, Good/Good2, FaultLeft/Right(2). Composite `45020cf7` = [a0408a04, Watch1] → [fc289842, Idle].
  - **Net:** Idle, IdleNet, Running, Running2. `28bd8c9d` = [Running, Running2] → [Running2, IdleNet].
  - **Ball boy:** Idle only.
  - **Umpire chair:** Idle plus 10 unnamed behaviours.
  - **Standing:** 48 behaviours.
  - **Standard:** Idle01–12, Flourish_XX_YY, SitBase/SitBase2/StandBase, Walk and Jog.

### 3.5 Crowd file (`Crowd<V>.bin`, signature f12cee6b / root ec2064c3, not in Layoutall)

- Header: the signature, then 0xFFFFFFFF at 0x10. The octree root is at 0x14. **C**
- Octree node (0x20 bytes): centre xyz, half size, children descriptor at +0x10, leaf cell at +0x1C (-1 for an inner node). Amsterdam has 1013 nodes, 760 leaves and depth 5.
- Root fields: spectator descriptor at +0x20, group descriptor at +0x2C, leaf count at +0x38, an unknown count at +0x3C.
- Spectator record (0x54 bytes):

  | offset | field | confidence |
  |---|---|---|
  | +0x00 | position (cm) | **C** |
  | +0x0C | Euler rotation (rad; only yaw is set on the disc) | **C** |
  | +0x18 | scale (x = 1; y and z 0.85–1.1) | **C** |
  | +0x24 | pointer to the model name | **C** |
  | +0x28 | pointer to "Model.xml" | **C** |
  | +0x2C, +0x30 | texture-atlas UV offset (0 or 0.5; a 2×2 atlas) | **I** |
  | +0x34, +0x40 | tint colours A and B (meaning unknown) | **I** |
  | +0x4C | pointer to the setup path (`TS_SExx`) | **C** |
  | +0x50 | octree cell | **C** |

- Groups are 1–4 {start, count} ranges, consecutive and covering every spectator (Amsterdam (0, 2932), (2932, 1068), (4000, 1836); ArthurAshe 4; Athens 2). **C**
  - Reading them as the quality steps of `CrowdLODList` (read in fn_8874BB80; strings "Crowd: LOW/MEDIUM/HIGH") is **I**.
- Crowd sound per venue is `Crowd_<Capacity>_Full[_Indoor].fsb`.

## 4. Crowd reaction (code)

| address | role | conf. |
|---|---|---|
| fn_8868E370 | sums the Settings event rows whose conditions hold (WinAce, WinWinner, WinWinnerPowerfulShot speed > 140, WinPassingShot, WinSmash, WinServeAndVolley, WinTwentyShots >= 20, LoseWinner, LoseUnforcedError, LoseUnforcedErrorEasyBall) | C (gp1 s6) |
| fn_8868EA30 | per rally: `ratio = acc(+0x344) / shots(+0x1048)`; `level = clamp(level + events + clamp(gain, -cap, cap), 0, 1)` | C |
| fn_8868E950 | 2-D gain step table (Settings cfg+0x824) | C |
| fn_8888D930 | sound side only: event→+0x38→+0x130 applause level 0..3 → `Root/Crowd/EndOfPoint/ApplauseLow/Average/Strong/Wild` | C |
| fn_887F0000–887F7000 | TrackSide manager: fn_887F65B8 loads `%sBehavior\Behavior.bin`, fn_887F67F0 reads TrackSideSetupList, fn_887F3D98 touches B_Head/B_Neck (head look-at, I), fn_887F55D8 uses "Left"/"Right" | I |
| fn_887E41E8, fn_888DB320, fn_8874BB80 | crowd hierarchy reference, CLoadCrowd, CrowdLODList | I |

Settings.bin tables (file offset = cfg offset + 0x24), decoded by `settings_crowd_tables` and stored in crowd.yaml:
- **0x848:** {rel, count, cap} → rows {rel, count, cap, f32 level limit 0.4/0.75/1.0} → six (ratio key, gain) pairs.
- **0x854:** cap by shot count, (1, .01) (2, .02) (3, .03).
- **0x860:** 10 rows of (event crc32, delta), each ±0.01 except WinPassingShot +0.02.
- After these tables come parameters whose meaning is unknown (0, 600, 5, 8, 10, 20, 15, 20, 400.0, 30.0, 300.0, 18, …).

No crowd camera-flash system was found in the strings or the code.

## 5. Port: rendering (port/web/venue.html, src/venue/)

- **`venue_scene.js`** loads `venue.json` and `venue.gltf` through `loadGltfRobust`, plus the lights, sky, trackside and crowd. It also builds the director and the bindings from each FSM to its rig.
- **`crowd.js`:**
  - `CrowdView`: one rig and mixer per crowd setup. Each (model, setup) pair is one **instanced SkinnedMesh**: a SkinnedMesh flagged `isInstancedMesh` with an `instanceMatrix`, which works in r160 because skinning runs before the instance matrix.
    - The per-instance atlas offset goes through `instUV` in `onBeforeCompile`; tint A goes through `instanceColor`.
    - The tier control maps to a prefix of rows sorted by group.
    - Amsterdam draws 5,836 spectators in 144 draw calls (9 models × 16 sections).
  - `TracksideView`: officials and the net placed by the hierarchy matrices.
- **`venue_main.js`:**
  - venue picker, quality tier, tint toggle;
  - synthetic event buttons;
  - "watch CPU match", which runs `MatchSession` with two CPU players and draws the ball and players as markers through `coreToVenue`. It needs `work/port/ts4core.wasm`, which is not built in this checkout, so this path is untested.
- **`play_hook.js`:** `attachVenueCrowd(play, …)` chains `session.onTick` into the director. It is not wired into play.js, which other agents own.
  - Note: play.js places core positions without the z flip, so the stands come out mirrored relative to the venue export. Use `mirror: true` or adopt `coreToVenue`.
- Checked in headless Chrome (SwiftShader) on Amsterdam:
  - The stadium, all 5,836 seated spectators and the posed officials render.
  - A "winner" event logs `ApplauseAverage lvl 0.31 [WinWinner]` and the sections switch to ApplauseAverageIn.
  - Screenshots were taken at runtime and not kept.

## 6. Port: state machine (src/venue/crowd_fsm.js, readable reference)

- From the game:
  - the composite and sequence rules;
  - one FSM per setup;
  - the excitement tables and update rule;
  - the 0..3 applause naming.
- Port choices (**P**, each marked in the code):
  - **Applause level:** `floor(level × 4)`, +1 for an ace, a passing shot or 20+ shots.
  - **Ratio:** stands in for +0x344 / +0x1048 as shots / 12.
  - **Favourite:** player 0. The Win and Lose rows are taken from that player's side.
  - **Deception:** used for a lost point after 4+ shots.
  - **Hold times:** 1.5 + 1.2 × tier seconds.
  - **Section jitter:** up to 0.35 s.
  - **Line judges:** play 45020cf7 (Watch) from the serve; FaultLeft or FaultRight by the sign of z.
  - **Net:** shakes on a net event.
  - **Officials:** a flourish every 6–16 s.

## 7. Open items (by priority)

1. **What triggers the trackside behaviours.** The behaviour name hashes are not constants in the code. The next step is to trace the callers of the fn_887F**** manager from the point-end and rally code.
2. **Net animation.** The clips in `trackside_net.gltf` are keyed for a chained Filet hierarchy, but the exported net skeleton is flat under B_Hips. Playing them tears the net, so the viewer keeps the bind pose (`VenueScene.netAnim = false`).
   - The net mesh is modelled along x, so the port yaws it 90°. The game's own net placement transform is not decoded.
   - Fix by reading the hkaSkeleton parent indices for skeleton 0 in `add_skeleton_nodes`.
3. **Decal alpha.** Some static decals render as opaque white quads: court-side logos and the large patches around the net. Their materials need alpha or blend modes from the material XML. The viewer shows this.
4. **Unknown meanings:** tint colour B, and the role of A against B. Unnamed hashes: cf1dbb45 (3 variants), umpire behaviours, Standing composites, weather 64042c35. The three floats of the light user props. Settings parameters after 0x860.
5. **Not done:**
   - per-section head look-at (fn_887F3D98);
   - LOD switching by distance (one LOD is exported, `--crowd-lod 2`);
   - material variants per placement (OffcialMan00_00 against _01);
   - the Standing (ST) setups in the director.
6. **CrowdLODList.** The quality-tier meaning of the groups needs confirming from fn_8874BB80.
