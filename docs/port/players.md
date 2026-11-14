# Player characters: models, appearance, animation playback (agent A4)

Scope: how the game builds a player on screen (pros and the PlayerCreator), how the port exports it to glTF, and how
the browser drives it with the game's own clips. Confidence tags: **V** read from data or code and reproducible,
**I** inferred from consistent evidence, **U** unknown or guessed, **PORT** a port-side choice.

Measured on the retail image `Top Spin 4 (World) (En,Fr,De,Es,It).iso` (SHA-256 `93f34363...8f3e5c`, docs/assets.md),
Core.arc members extracted to `work/disc/core_all/` (docs/gameplay/player-and-movement.md). Tools: Python 3.13.18
(standard library only), node v22.23.4, Google Chrome for Testing 153.0.8010.12 (headless, SwiftShader) for the render
check. Addresses refer to `Swing_DLL.dll` (base 0x88000000). No game data is committed. The readable dumps live under
`data/gameplay/` (AGENTS.md exception). Exports go under `work/port/assets/` (git-ignored).

## 0. Files and reproduction

| Path | What |
|---|---|
| `tools/ts4_players.py` | `roster`, `creator`, `export`, `animrules`, `aodclips` (below). Reuses `ts4_assets.py` (glTF writer, XPR textures, skeleton), `ts4_mesh.py`, `ts4_xbin.py`, `ts4data/anim_rules.py`, `tools/havok/` |
| `tests/test_players.py` | 16 tests on synthetic bytes and trees (names, Hierarchy, LOD sets, skin pairing, DMorph record, creator tree, YAML writer, roster reader, clip chains) |
| `data/gameplay/pro_roster.yaml` | 81 Baked archives: parts, visible body groups, LOD distances, texture variants, cloth, PlayerList row (height, handedness, gender); all 732 PlayerList rows |
| `data/gameplay/creator_options.yaml` | PlayerCreatorDB option lists: 583 geometries, 810 materials, 2,570 morphs, outfits and brands per sex, morph groups, FaceGen controls and hot spots, texture layer command sets, presets |
| `port/web/src/players/anim_logic.js` | pure engine rules (sector8, move-set pick, play rate, cycle loop, blend, RotY, rate-to-target, time warp, mirroring rule, height scale, swing qualifier match) |
| `port/web/src/players/pose_mirror.js` | pure left-handed pose mirroring |
| `port/web/src/players/core_anim.js` | reader for P1's `Ts4AnimView` (`ts4_anim_view`) |
| `port/web/src/players/game_animator.js` | `ClipStore` (Core, AOD and lead-in+AOD clips, root speed, pose-mirrored copies) and `GameAnimator` |
| `port/web/src/players/appearance.js`, `appearance_pure.js` | `PlayerModel`: LOD switching, sweat / clay / grass variants |
| `port/web/src/players/play_hook.js` | `PlayMode` glue, enabled by `?anim=game` (two lines in `play.js`, one in `config.js`) |
| `port/web/players.html`, `src/players/demo.js` | standalone viewer: two exported players with a scripted state (no ts4core needed) |
| `port/web/test/players.test.mjs` | node tests of the pure modules |

```sh
export TS4_ISO="orig/54540859/disc_archive/Top Spin 4 (World) (En,Fr,De,Es,It).iso" HAVOK_CLASSES=work/havok/classes.json
python3 tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll                 # once (local only)
python3 tools/ts4_players.py roster                                            # 2 s  -> data/gameplay/pro_roster.yaml (510,335 B)
python3 tools/ts4_players.py creator                                           # 29 s -> data/gameplay/creator_options.yaml (626,405 B)
python3 tools/ts4_players.py animrules                                         # -> work/port/assets/players/anim_rules.json (1,849,418 B)
python3 tools/ts4_players.py export Baked_Federer0.arc Baked_Nadal0.arc        # ~1 min each; --all for the 81; --variants adds sweat/dirt PNGs (slow)
python3 tools/port/clip_map.py --iso "$TS4_ISO"                                # record -> Core / AOD clips (about 7 min with cutscenes)
node /path/to/wanted.mjs > records.txt     # or any list of AnimationsDB record indexes
python3 tools/ts4_players.py aodclips --records records.txt                    # AOD clips + players/clip_chains.json
python3 tools/port/export_assets.py --iso "$TS4_ISO" --only havok animdb --core-clips <list printed by aodclips>
python3 -m unittest tests.test_players && node port/web/test/players.test.mjs
python3 tools/port/serve.py   # http://127.0.0.1:8000/port/web/players.html  or  /port/web/?anim=game&meshes=../../work/port/assets/players/&p0=Baked_Federer0&p1=Baked_Nadal0
```

## 1. Where a player comes from

* **Pros (V).** There are 27 licensed or academy players with up to three outfits each, in 81 archives `Baked_<Name><n>.arc` (the digit is
  the outfit). PlayerList.bin (Core `de208ac7`, 278,423 B, sha256 `35b3b726...398e`) has 732 rows. Every Baked archive
  matches a row by `AssetName` (Federer is row 674: Type `Pro` (`53f9901f`), Height 186, Plays `RightHanded`; Nadal:
  `LeftHanded`, 185). Other rows' Types are `d5b6d18f` (158 generated players), `84b1caf4` (19), `CreatedPlayer` (21),
  `4bd2442c` (academy, Boyce / Ikeda / Gutierrez / Ralley / WaltWilliams / PlayerAcademy1). The 700 non-Baked players
  have **no** baked meshes. They must be built by the PlayerCreator at run time from creator data (U: their DNA records
  were not located; `PlayerBackGround.arc` and the GameThumbnailDB files are candidates).
* **Created players (V for the data, U for the runtime).** PlayerCreatorDB.bin (Core `365f5d5a`, 6,674,250 B, sha256
  `28b1d2fa...91bc`) is the creator database. The meshes and textures are in `PlayerCreator_Male/Female/Common.arc` and
  the 0.7 GB `PlayerCreator_*_Texture.arc`. PlayerCreator2.ctl (Core `2b9afed1`, 141,524 B) and the `FREG`/`FRTR`-tagged
  members of the creator archives are FaceGen data (strings `CFaceGenInterfaceXBIN`,
  `c:\dev\playercreator\private\facegen\FaceGen_Coding_Apply.cpp`). Not decoded (s7).

## 2. A Baked archive (V)

`Baked_Federer0.arc` (105 members, listed by `tools/ts4_assets.py list`):

| Member pattern | Role |
|---|---|
| `Hierarchy.xdt` (PAM-XDT) | scene of the player `Player00`: one `Geometry` per part slot, cameras, `PlayerLight` (s3) |
| `M_<PART>_<STYLE>_<PLAYER>_<nn>_000/_100/_200.xbin` | part mesh LOD files (record signature `a4b9371d 330fac24`, docs/assets.md s4) |
| `..._0NN.xbin` (signature `7d72a97d a12b5eb9`) | **DMorph target** of a part (s3.3) |
| `M_..._nn.xdt` / `_01.xml` / `_2dPass.xdt` / `_99.xdt` | material trees (PAM-XDT, docs/assets.md s5); `_2dPass` = second pass (hair cards); `_99` = alternative part material |
| `<PART>_..._00.xpr` | the clean (`_R`) textures: `_DI` diffuse, `_SP` specular, `_BU` bump (CTX1), plus `WrinkleMap` / `WrinkleMaskMap` in the head pack |
| `M_..._<BRAND>_00_SWE / _DST / _GRA.xpr` | sweat, clay dust and grass-stain variants of the clothes (s5) |
| `M_HUM_<PART>_..._SP_R_<n>_0.xpr`, `M_HUM_HEADX_..._DI_R_<n>_0.xpr`, `M_HCX_..._DI_F_<n>_0.xpr` | skin and hair sweat levels 1..3 |
| `CLTH_TOP/BTM.bin`, `CLMT_TOP/BTM.bin` | cloth simulation and cloth morph targets (`ClmtBottom00:/ClothMorphTarget`, DLL string). Not decoded |
| `Physics.hkx` (28 of 81) | ragdoll, 20 `Ragdoll_*` bones (docs/havok.md) |
| `Physics.bin` | xbin `2d547a13`, 440 B. Not decoded |
| `Full.bin` | 2,448 B, scene directory member. Not decoded |

Asset name grammar (V, from all member names): `<M|C>_<PART:3>_<STYLE:5>_<PLAYER:5>[_<BRAND:3>]_<nn>[_<lod|morph:3>][_<tail>]`.
`C_` parts are shared (racket `C_RAC_RACKT`, strings `C_RAC_TAMIT`), and `XXXXX` means generic. `parse_part_name()`
implements it. Part tokens: HUM (body `BODYX`, head `HEADX`, eyes `EYESE`/`EYESI`, mouth `MOUTH`, lashes `ELASH`),
TOP, BTM, SOC, SHO, LAC, HCX (hair or headwear), WBL/WBR (wristbands), RAC. A player-specific style keeps the player
token (`TOP_PFEDB_FEDER`, `HCX_BDANA_FEDER`), listed per archive as `signature_items`.

## 3. Hierarchy.xdt: parts, visibility, LODs, morphs

Element and attribute names are crc32 keys. These were resolved: `LODList` 88040e79, `LOD` 80917bf5, `Level` 5b2be317,
`Distance` e5e4f8d7, `LightList` 72516e44, `DMorphList` 4ee4e19e, `DMorph` dd0ebed6, `Weight` 00615077,
`LifeTime` 64a3fde0, `Priority`, `RenderTarget`, `Up`.

### 3.1 Which parts are drawn (V data, I semantics)
The Hierarchy lists every slot of the template (for example both `M_WBR_SRIGH` and `M_WBR_LRIGH`). A part is drawn when its
mesh exists in the archive **and** `LifeTime` = -1. Absent slots and the `_100` / `_200` LOD files carry 0.
`hierarchy_geometries()` returns them; the roster keeps only the present ones.

### 3.2 Body groups hidden under the clothes (V data, I semantics)
The body mesh `M_HUM_BODYX` has 11 groups per LOD (`GRP_ARMSX_00/01`, `GRP_CHEST_00/01/02`, `GRP_PELVI_00`,
`GRP_HANDS_00`, `GRP_LEGSX_00/01`, plus `GRP_BACKX_*` / `GRP_BREST_*` on women). Its Geometry node holds a list
`0xebd4a36e` of `0xabca359e {Name}` rows. The list **varies with the outfit** and is read as the groups that stay
**visible**:

* Federer0 (sleeved shirt): no `ARMSX_00` (upper arm), no `CHEST_01` (torso).
* Nadal0 (sleeveless top): also drops `CHEST_02`.
* Becker0: keeps `CHEST_01`.
* Women add `BACKX` / `BREST` according to the top.

Group centroids (Federer body, mesh frame, cm) agree:

| Group | Region |
|---|---|
| `LEGSX_01` | y 21..62, shins |
| `LEGSX_00` | y 59..89, thighs |
| `HANDS_00` | x up to ±76, hands and forearms |
| `CHEST_01` | y 106..154, torso |

The export drops the unlisted groups (Federer 15, Nadal 18 groups over three LODs). The headless render (s8) shows no
skin through the clothes. Confidence: data **V**, "listed = visible" **I** (consistent over all 81 archives).

### 3.3 LODs (V)
* **Per part.** `UserProperties` carries `Distance1 = 1000`, `Distance2 = 1500` (cm), `ShaderLOD = AUTO`, and a
  `LODList` of `LOD {Level 1, Distance 1000}`, `{Level 2, Distance 1500}`, the same on every shipped part.
* **Two storage forms.**
  * **In-file sets.** A mesh stores N equal sets of groups. The ordering is by index count, and not fixed: the body is
    mid, low, high (`lod_sets()`).
  * **Separate files.** `_000` / `_100` / `_200`, used for TOP and BTM. The `_100` / `_200` files have `LifeTime 0` and
    are swapped in by distance (I).
* **Export.** The export writes every level as its own node (`extras.lod`, `extras.lod_distance_cm`; levels > 0 are
  `hidden_by_default`).
* **Browser.** `PlayerModel.setLodDistance()` shows level 0 below 10 m, 1 below 15 m, 2 beyond (`lodLevel` / `useLevel`).
  The DLL has `CLodSelector`, `LODBias` and a `ForceLod` spool path. A global bias is possible (U).

### 3.4 DMorph targets (V layout, I meaning)
* **Data.** `DMorphList` names targets per part (`M_HUM_BODYX_XXXXX_00_001/002/003/010`, all with `Weight 0.0` in the
  pros). In Baked archives only `M_HCX_BDANA_FEDER_00_010.xbin` exists: 42,404 B, built from `M_HCX_XXXXX_FEDER_Phy.max`,
  so probably a hair physics or hat-compression shape (I).
* **Record layout.** The file is a mesh record without groups and bones. Its vertex array has the base mesh's vertex
  count (2,626 here): `position Float16_4` (mostly `(0,0,0,1)`: a delta, I), `normal Dec3N`, `tangent Dec3N`.
  `parse_morph()` reads it, and the export emits glTF morph targets with the Hierarchy weights (`targetNames` in mesh
  extras).
* **Creator.** The creator's 741 `7d72a97d` members of `PlayerCreator_Male.arc` are the same kind (the Morph list of
  PlayerCreatorDB has 2,570 entries with Min/Max/Weight). DLL strings: `DMorph_VS.hlsl`, `CMorphXBIN`, `Morphs\GeometryPack.xbin`.

## 4. Skeleton, skinning, racket (V, docs/assets.md s4/s7 and docs/havok.md)

* **Skeleton.** 71 bones (Core `6932352f` skeleton 0). There are **no facial bones**: the head and mouth meshes are
  skinned to `B_Head` / `B_Neck` / `B_Spine2` / shoulders, and the eyes to `B_Head` only.
* **Hair physics.** Hair and headwear meshes carry extra palette bones `Bone01..Bone19`, which are not in the 71. They
  are skinned to `B_Head` (their physics is not decoded).
* **Skin weights.** Weight i pairs with index byte 3 - i (`skin_pairs()`).
* **Racket.** `C_RAC_RACKT` and `C_RAC_TAMIT` are modelled in `B_Racket_Handle` space and attached as child nodes. The
  handle bone is a child of `B_RightHand`.
* **Left-handers.** The mesh is not mirrored, and the racket follows the mirrored pose (s6.4).
* **Height.** PlayerList `Height` selects a PlayerHeight band. The step factors in `animation_rules.yaml height_steps`
  (Men 150..170: 0.93, ..., 178..187: 1.00, 187..193: 1.04) scale root motion (I). They are not applied to the mesh:
  pros are modelled at their own size (U).

## 5. Materials, sweat and dirt (V names, I selection)

* **Texture names.** `<base>_2D_<DI|SP|BU>_<R|F>[_PASTTIME][_SWEATn][_DIRTYn]`, parsed by `parse_texture_name()`. `_R` is
  the clean map wired by the material trees (`..._Player00` suffix stripped). `_F_PASTTIME_SWEAT1/2` and `_DIRTY1` are
  the per-player variants:
  * `SWE` packs: sweat 1..2.
  * `DST` packs: clay dust.
  * `GRA` packs: grass stains.
  * skin and hair: `_n_0` packs, sweat 1..3.
* **What a montage of the shirt maps shows.** `_R` is clean. SWEAT1 and SWEAT2 add growing dark patches at the chest,
  armpits and back. DIRTY1 adds brown dust at the hem.
* **Export.** `export --variants` adds `material.extras.variants.{diffuse,specular}.{sweat1, sweat2, sweat1_clay, ...}`
  (PNG paths). `PlayerModel.setCondition({sweat, surface})` swaps the diffuse map (`pickVariant`: exact, then without
  dirt, then lower sweat).
* **Selection in the game (I).** The DLL names `PasttimeSweat`, `SweatSimulationPass_Player0`, `SweatGravityPass`,
  `F_SweatPass_`, `M_SweatPass_`, `_SWEAT_`, `DIRTY`, `SWEAT`. Sweat is partly a **runtime simulated texture pass**, and
  the baked levels are its inputs or fallbacks. The driver (fatigue or match time) was not traced (U). In the creator DB,
  `StepParam {SweatID, DirtyID}` and `DirtyCategory` lists tie texture steps to sweat and dirt ids.
* **Wrinkles (V names, U use).** Head packs carry `WrinkleMap` + `WrinkleMaskMap`, and Core has per-pro
  `WrinkleMap_<Pro>.dds` (13 pros + Default). The shader parameters are `WrinkleScale` and `WrinkleMaskWeights1/2`.
  Facial wrinkles are presumably driven by the facial animation (s7). Not exported.
* **Shaders.** These are `PamOrenNayarBlinn` HLSL in Core (docs/assets.md s10). The glTF has diffuse, normal (BU,
  CTX1 reconstructed; channel order I) and the specular path in extras. The port lights with three.js PBR
  (metallic 0, roughness 1): **PORT**.

## 6. Animation playback in the browser

### 6.1 Data
* `anim_rules.json` (`animrules`) holds the 3,184 AnimationsDB records (frames, group/sub, SpeedCoef, IgnoreSpeedCoef,
  NoMirror, AnimEvents, TransitionEvents, RotY, qualifiers), 126 groups, 34 move sets, the transition rules and the
  sparse matrix. Source: AnimationsDB.bin `3a3a98cf...`, swinganimation.bin `901b8cef...`.
* `clip_map.json` (`tools/port/clip_map.py`, docs/port/clip-map.md) maps records to clips: 2,143 exporter links
  (run with cutscenes, 2,093 AOD headers scanned). Some records are linked only through `records[].variants`, not the
  `"#i"` map. Jog_Right (#1632 to core 1068) and Sidesteps_Right (#1916 to core 38) are examples. `ClipStore` therefore
  seeds its record-to-clip table from `clip_chains.json` as well.
* `aodclips` resolves a record list through the clip map and writes `players/clip_chains.json`
  (`{record: {core, aod, kind}}`). It exports AOD clips when a record needs one, and `ClipStore.concatClips` joins a
  lead-in and an AOD clip offset by one 60 Hz frame (record frames = Core + AOD frames, V). M: for the 162 records the
  viewer needs (Men and Women: Jog, Rush and sidestep sectors, idle, and the swing picks), every chain is `kind: core`.
  None needs an AOD clip; the 162 Core clips are listed in `core_needed`.
* The Core clips must be exported together with the clip index in a single run:
  `export_assets.py --iso ... --only havok animdb --core-clips <list> --clip-map auto`. An animdb run alone indexes only
  the clips its own havok pass wrote, so `animations.json` loses the `file` of the others.
* **Facing (M).** Every exported Core clip has `B_Hips` at about -90 deg yaw in Havok space (Jog_Front -80, Jog_Right
  -87, Rush_Front -76, Idle -104). The bind pose is +90 deg. An animated player therefore faces 180 deg from the
  bind-pose forward that `PlayerRig` aligns to +x (foot to toe). `GameAnimator.calibrateFacing()` (after preload) adds
  `facingOffset(rest, clip)` (0 or PI) to the rig's facing node, so heading 0 faces +x for the clips. The legacy
  `animator.js` path does not do this.

### 6.2 Per-tick state: P1's core first
P1 is adding `Ts4AnimView` / `ts4_anim_view()` to `port/core/include/ts4core.h` (64 bytes: layer, clip, clip_hash,
frame, rate, prev clip/hash/frame, blend, group, subgroup, mirrored, contact_frame). `core_anim.js` reads it from the
wasm memory and refuses on a size mismatch. It maps `clip_hash = crc32(name)` to a browser record (so the table order
need not match), and `GameAnimator.applyCoreState()` samples the clip and the blended-out clip verbatim. The core then
owns selection, rate, time warp, blend and mirroring. When the core has no ANIM section, the animator derives the same
quantities from `Ts4PlayerView` (s6.3).

### 6.3 Derived playback (G6 rules)
| Step | Rule | Confidence |
|---|---|---|
| move set | idle below 30 cm/s, `Rush` above the jog/rush midpoint, the sidestep family (`20485ec3`: Jog front, Sidesteps sides, Backsteps back) below the walk/jog midpoint, else `Jog` | PORT (the planner regime is not in `Ts4PlayerView`) |
| sector | `lo_sector8` of the velocity relative to facing. Port frame (x forward, z right) to locomotion frame: `lo_x = -z, lo_z = x, yaw = -heading` | V (rule), I (frame mapping) |
| clip in sector | `chooseInSector`: prefer `Normal`/`Medium`/`Good`, avoid `Bad`/`Wrong` | PORT (selection procedures need keys the core lacks) |
| loop | phase wraps between `Cycle_In` / `Cycle_Out` | I |
| rate | `lo_play_rate` (SpeedCoef unless IgnoreSpeedCoef, group gameplay coef), times sim speed / clip root speed clamped to 0.5..2 so the feet stay planted | V/I, PORT for the speed match |
| transitions | 15-frame linear cross-fade (TransitionRule BlendIn/Out 15/15). The matrix and bridging `Tr_*` clips are in the JSON but not yet used by the derived path | V data, I curve |
| swing | record by qualifiers (`swingMatches`: Category Swing, SwingType, SwingEffect, PositionOnCourt) or the core's record. Time `(contact × swing_t) × duration` until contact, then contact..1 over the recovery | V (gp7 time warp) |
| mirroring | `mirrorFor`: left-handed and not NoMirror (no gameplay clip is NoMirror) | V |
| root motion | removed (hips x/z pinned), measured first for the rate | PORT |

### 6.4 Left-handed mirroring (`pose_mirror.js`)
`W'_b = R W_c R C_b` with `R = I - 2nn^T` (n measured from the rest up-legs), c the Left/Right counterpart, and
`C_b = (R Rest_c R)^-1 Rest_b`. It is exact for a symmetric rest pose and keeps proper rotations. The mesh is unchanged,
so logos and partings stay right. `mirrorAnimationClip` bakes a mirrored copy per clip. The old path (`scale.z = -1` on
the rig) is kept for `?anim=legacy` and mirrors the whole mesh. The tests check that the rest pose maps onto itself, that
a raised right arm becomes a raised left arm, and that the root yaw and lateral offset flip. That the game mirrors
exactly this way is **I** (it plays right-handed clips mirrored, V; its handling of the racket bone was not traced).

## 7. Not decoded / open

1. **FaceGen face generation** (PlayerCreator2.ctl, creator `FREG`/`FRTR` members, FaceGenDataList values,
   `FaceGen_HotSpotList`) and the **DNA analyser agents** (AgentsSettings, 329,666 leaves) that turn creator sliders into
   morph weights and texture layers. Created and generic players therefore cannot be rebuilt yet. The option lists are in
   `creator_options.yaml`.
2. **Creator XPath references** print as raw self-relative offsets (for example `-135188`). They point at the target
   object inside the file but are not yet resolved to names.
3. **Facial animation.** `facialdata.bin` (Core `8e39f815`, 451,128 B) and `FacialAnimGroup.bin` (`5bbd0775`) have
   root types missing from Layoutall (`68765c59`, `a44ae067`). The DLL has `Media\FacialAnimation\FacialMorph\`. Faces
   are animated with morphs, not bones. Not decoded: faces stay neutral.
4. **Cloth and hair physics** (`CLTH_*`, `CLMT_*`, `Bone01..19`, `Physics.hkx` ragdolls). Hair and clothes are rigid on
   the skin.
5. **IK and head look.** DLL strings `TRACK_FOOT_IK_CONTROLS`, `TRACK_HAND_IK_CONTROLS`,
   `TRACK_LEFT/RIGHT_HAND_IK_POSITION/NORMAL_CONTROLS` (Havok annotation track names). The foot and hand IK and any
   head-look are not implemented.
6. **Sweat and dirt driver** (which state picks the level and when), the runtime sweat simulation pass, and wrinkle maps.
7. **Set layers and blends.** Records with additive layers (sets) play their base clip only. The derived path does not
   use the transition matrix or the bridging clips, the RotY code yaw, or the clip-fit cost `fn_886D3AD8`. P1's
   core view supersedes these when present.
8. **Selection procedures** for locomotion variants (TransitionQuality, SplitSteps, Surface) and `MaximumOccurency`.
9. The `0x58e4a0f3` flag on `_99` geometries (alternative racket strings and bandana materials) and the `_2dPass` child
   (second pass for hair cards) are recorded but not used.

## 8. Checks

* `python3 tools/ts4_assets.py check` on both exports: indices in range, joints < 71, weights sum to 1.
* Federer0: 44 meshes (16 LOD0, 15 LOD1, 13 LOD2 nodes), 34 PNG, 19 normal-mapped materials, 8.7 MB.
* Nadal0: 46 meshes, 35 PNG, 7.7 MB.
* Headless render of `players.html` (Chrome 153, SwiftShader, three.js 0.160.0 copied into git-ignored `work/a4_preview/`
  because the sandboxed browser cannot reach the CDN): Nadal0 in the T pose before clips were linked. The orange
  sleeveless top, white shorts, headband and wristbands are correct, and no skin shows through the clothes.
* After the clip export, headless renders of `players.html?t=...` (Federer0 right-handed, Nadal0 left-handed):
  * t=1.0: Federer plays Sidesteps_Right and Nadal plays Jog_Right (sector 6, faster scripted speed).
  * t=5.0: the same players play Sidesteps_Left and Jog_Left (sector 2).
  * t=2.6, swing: Federer plays Swing_FH_Flat_Power_InsideOut (racket in his right hand, forehand on his right).
    Nadal's swing is mirrored: Swing_BH_BadReach_Jog_FrontLeft (racket in his left hand, reaching to his right).
  * t=3.2: both play Idle_Wait_Loop facing the camera (heading +z) after `calibrateFacing`. Before the fix they faced
    away.
* `python3 -m unittest tests.test_players` (16 OK), `node port/web/test/players.test.mjs` (9 tests: pure logic, mirror,
  appearance, facing offset, Ts4AnimView decode OK).
