# GPC notes: does the court surface change the game? (tuning link 7)

Family GPC. Module `Swing_DLL.xex` sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`
(PE image `orig/54540859/Swing_DLL.dll` sha256 `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9`;
image offset to VA: `VA = file_offset + 0x88004600` inside `.text`, checked on `fn_886BBEA8`). Disc image sha256
`93f3436310632c59334fd5df0f2e7d7a8350e867ce7e354780c871dfbf8f3e5c`. Tools: Python 3.13.18, `tools/fn_asm.py`, `tools/sym_info.py`
(`TS4_MATCHING_DIR=work/matching-b9`), `tools/xiso.py`, `tools/ts4_arc.py`, `tools/ts4data/hkx.py`. Confidence: H read directly, M inferred.

## 1. Conclusion

**(b) The surface does not change ball physics, shot outcome, movement speed, AI or stats in code or in the shot/analyser data.**
It changes (1) sound, (2) which swing animation takes are allowed (Clay-only takes with a slide cue) and so slightly the swing
timing and contact geometry on clay, and (3) visuals/UI. Evidence is in sections 3 to 6. There is **one ground plane, one template
table and one bounce routine for all courts**, and no restitution/friction/speed value in any venue file is keyed by surface.

Practical consequence for tuning: a per-surface bounce factor does not exist and must be added. The smallest hook is a post-process
of the outgoing velocity in `fn_889C1C80` (section 7). Nothing is tunable per surface by data alone.

## 2. Where the surface is stored (H unless noted)

Surface name hashes (zlib crc32): Hard `6127B0EC`, Clay `BC1789F5`, Grass `69CCB0F7`, Carpet `4679AD1C`, Wood `9CAFB633` (Tokyo only),
Indoor `1436B81A`, Outdoor `D3338BA2`. `IndoorHard 0608EDB7`, `IndoorClay 0AEC63E5`, `IndoorCarpet DB38D4AE` also exist (section 6).
`Hard` is also the difficulty-level name (neighbours `Normal 26296DD2`, `VeryHard DDAE07EE`, `E95035A9`): the hits in
`fn_886C0568`, `fn_888C1AB8`, `fn_888C53D8`, `fn_888CB278` and `Settings.bin` are difficulty, not surface.

Chain from data to code:

1. `Global.arc` holds 49 `<Venue>Desc.bin` files (names resolved by `ts4_arc.py --list`). In each, **+0x5C = surface hash, +0x60 = Indoor or
   Outdoor hash** (+0x58 hash, +0x64/+0x68 crowd class, +0x6C crowd size such as `Huge`/`Medium`). Example `AmsterdamDesc.bin`
   (576 B): `+0x5C = 6127B0EC (Hard)`, `+0x60 = D3338BA2`. Result of the scan (49 venues): Hard 27, Clay 10, Grass 6, Carpet 5, Wood 1.
   Clay: Barcelone, BuenosAires, Casablanca, Houston, MonteCarlo, RolandGarros, Riviera, Rome, Madrid, Rio (indoor). Grass: Munich,
   Londres, Irland, Boston, SanFrancisco, Auckland. Carpet: ParisBercy, Santiago, Athens, Kiev, HongKong (all indoor). Wood/Indoor: Tokyo.
   Hard indoor: Shanghai, Stavgaard, LasVegas, Dubai, LondonO2, Moscou, PracticeGround.
2. The venue record is a 0x90-byte entry found by `fn_888D5F50(key = (this+0x40)+0x14, matchinfo = this+0x38)` (3-level container at
   `matchinfo+0x13A4`, key at record `+0x24`). `fn_886AA940 +0x2F4..+0x35C` (match setup) stores **`m+0x31C = record+0x38` (surface hash, 0 if
   no record) and `m+0x32B = (surface == Clay)`**, `m = this+0x30` (the match state; `m+0x320` is a different hash, the tournament level,
   set by `ts4_mode_selector_pick_hash_8866E128`).
3. `fn_886A16D8 +0xC58..+0xC7C` (per-player blackboard build) copies them into the PlayerState (`PC+0x74`): **`S+0x36C = surface hash`,
   `S+0x370 = (isClay != 0)`**. Nothing in `Swing_DLL` reads `S+0x36C/0x370` by offset (every `lwz/lbz` of those displacements in `.text` is
   another structure, checked with a displacement scan); analyser graphs could only reach them by name and none does (section 5).
4. A second copy of the surface lives in the venue/match settings object whose `+0x10` is the surface hash and `+0x1C` the Indoor hash. It is
   reached as `*(*(0x88D45A18) + 0xA8)` by the animation query builder (`fn_887E1928 +0xEC`, `lwz 0x5A18(0x88D4....)`, `lwz 0xA8`, `+0x10`) and
   as `controller+0x2C` by the sound code (`fn_8888ADC0 +0xF4`, `fn_8888DD18 +0x5E8`: `lwz r8,0x10(r9)`, `lwz r3,0x1C(r9)`). M: same object.

## 3. Every reader of the surface in `Swing_DLL` (complete for the five surface hashes, `Surface`, `SurfaceType`, found by scanning all
`lis/ori` pairs and all data words; command in section 8)

| address | function | use |
|---|---|---|
| `886AAC54..AC98` | `fn_886AA940` | writer: `m+0x31C`, `m+0x32B` |
| `886A2330..2350` | `fn_886A16D8` | copies to `S+0x36C/0x370` (no reader found) |
| `8888AEB4..B010`, `8888E300..E45C` | `fn_8888ADC0`, `fn_8888DD18` | sound only: select one of four 10-float volume blocks (Hard+Indoor, Clay, Grass, Carpet), also Slide/Stomp cue volume (gp5 section 6) |
| `887E1A14` | `fn_887E1928` | animation query: qualifier key `Surface 73FCA7F2` with the venue surface as value |
| `886A07AC`, `886DB160` | `fn_886A06B0`, `fn_886DB058` | register the swing-take qualifier accessors `SwingCategory, BHType, ProStyle, Setup, Surface, FollowNet, SwingPreferenceLevel` (hashes `AD4BA1AB, 96793E47, 860F3051, E4DC7934, 73FCA7F2, A906C730, 80EC0B87`) |
| `88269E88`, `88660E38` | `ts4_if_get_u32_off18_*` | the `Surface` accessor itself: `if (m+0x32B == 0) out = (take_key == Clay)`; i.e. only Clay is distinguished (takes tagged Clay are excluded unless the court is clay; M on polarity) |
| `889632A4..78C4` | `fn_88967840` (caller `fn_8896BE28`) | Clay -> text `DST`, Grass -> `GRA` (resource/texture prefix, visual) |
| `887D1F84`, `887D1FDC` | `fn_887D1F80`, `fn_887D1FB8` | Indoor flag only (camera/cutscene mode selector) |
| `887D171C` | `fn_887D1660` | reads `m+0x328..0x332` flag bytes incl. `m+0x32B` in a mode selector (camera/replay), not physics |

There is **no surface constant or `m+0x31C/0x32B` read anywhere in the ball stepper (`0x889C0000..0x889D2000`), the kind solvers
(`fn_888AA...`), the launch/aim code (`fn_889C19F0`, `fn_889C29E8`), the shot planners (`fn_886AD758`, `fn_886AE528`, `fn_886B1BA0`,
`fn_886B2D00`), the error model (`fn_886807C0`, gp4b section 10), the reach code (gp2) or the movement planner (gp3)**.

## 4. Ball physics: nothing surface-dependent (H)

* Bounce `fn_889C1C80` (called once, `fn_889C1F70 +0x2D8` = `889C2248`) reads only the template row curves `+0x40/+0x4C/+0x58/+0x64`
  and constants (`pool+0x1E0 = 5.0`). The ground is the plane `y = 0`. Disassembly: speed loss `fsubs f9, 1.0, c40(spin_a)` at `889C1EA8`,
  multiplied into the vector at `889C1ECC`; outgoing velocity copied to `ball+0x140` at `889C1F48..1F54`, then `fn_889C0DC0` at `889C1F58`.
* Templates: 37 rows in `Core.arc/Settings.bin` (`334E7E0D`, 286,492 B) plus one in `State.bin`; none of the surface hashes occurs in either
  file except `Hard = difficulty` (neighbours `VeryHard`, `Backhand` keys at `0x12014..0x12024`). One table for all courts
  (`shot-templates.md` section 7 already said "Surface: none").
* Default ball block in `State.bin`: radius 4.0 cm, `a4` 0.06, `g` 9.81, max bounces 5 (same file for all venues).
* Havok: venue `Physics.hkx` files contain only `Collision##` scenery bodies. Decoded with `python3 tools/ts4data/hkx.py json`
  (RolandGarros clay `6a6fd868`, 62 bodies; Londres grass `fa6be898`, 90 bodies; Amsterdam hard `69916137`, 113; LondonO2 hard indoor
  `a065ca07`, 31): **every body has `hkpMaterial` friction 0.5, restitution 0.4**, identical on clay, grass and hard, and none is a court
  ground. Shared files: ball `bde8ab04` friction 0.1 / restitution 0.95 / damping 1.0, `CollisionNet` `db0ddc52` 0/0, player body parts
  `762e762e` 0/0, the same bytes in every venue. Havok only generates contact events (gp4); the closed-form stepper never reads them.
* Venue `Physics.bin` (`a11a8a6d` 6,592 B, `311eba9d`, `a2e43332`, `6b109802`) lists the object names of that `.hkx`; no surface field.

## 5. Movement, animation, AI, stats

* **Animation clips are the only gameplay-visible surface effect.** `Core.arc/AnimationsDB.bin` (`70155255`, 3,437,395 B) declares a
  qualifier `Surface` (key at `0x234`) with values `Clay 0x5C0, Hard 0x5C4, Grass 0x5C8, Wood 0x5CC, Carpet 0x5D0`. Of the 3,184 takes
  (`work/disc/gameplay/animation_db.json`), **90 are named `*_Clay_*` (84 swings: FH/BH Slice_Power 38, 1H/2H Flat_Power 24, FH Flat_Power 10,
  Volley FH/BH 12; 6 `GiveUp_EndOfPoint`), and the 88 takes with a `Slide` annotation are exactly the Clay ones.** No take is named
  Hard/Grass/Carpet. A Clay take differs from its twin: e.g. `Swing_Volley_FH_..._Waist_Clay` racket event 0.338 s vs 0.370 s for the plain
  take, `Slide` cue at 0.173 s. So on clay the swing-selection candidate set (gp2/gp7) gets 84 extra clips with different contact timing
  and geometry; reach, swing timing and the clip-fit result can differ slightly on clay. The `Slide` cue is consumed only by sound
  (`fn_8888DD18 +0x864`); the movement itself is baked into the clip root motion. (M: the exact accept/reject rule of the accessor.)
* Movement planner (gp3), reach (gp2), the error model (gp4b/gp8) and the stamina/fatigue analysers: no surface read in code. The analyser graph
  store `Core.arc/AnalyserFrameworkModule.bin` (`6E852B1A`) and `Settings.bin` contain none of `Surface, Clay, IsClay, CourtSurface,
  SurfaceType, IsGrass, IsHard, IsCarpet` as 32-bit hashes (scan of every Core, GlobalMem and Global entry <= 6 MB). So no shipped graph
  conditions on surface, even though `S+0x36C/0x370` are populated.
* Stats: `PlayerList.bin` (`de208ac7`) has 732 records; each carries a 6-slot table `{Hard, Clay, Grass, IndoorHard, IndoorClay,
  IndoorCarpet} -> int` (next to `SignatureStyle`, `TwoHanded`). 676 records are all zero; the rest hold 100..3000 (mostly a single Grass
  value of 200/500/1000, one 3000, one Clay 1500). These look like per-surface experience/rating bonuses, but **no literal read exists in
  `Swing_DLL`** (the hashes `0608EDB7, 0AEC63E5, DB38D4AE` occur nowhere in code); the reader, if any, is UI/career. Not a physics input.
* `Season_*.bin`, `SeasonDB.bin`, `UI.bin`, `BackstageRequests.bin`: tournament calendar and menu surface labels only.
* `InGameModule.bin` (per-venue copy, identical `62C2690A`, 103,484 B, sha256 `88bcbdfa...ee233` for RolandGarros) contains
  `Pam::System::Conditions` choice blocks keyed Hard/Clay/Grass/Carpet/Indoor (offsets `0x21BC`, `0x2258`, `0x2310`, `0x24BC`, `0x233C..0x2D14`,
  `0x48A8..0x4D5C`). They sit among module/loading/scene-path data and parameter blocks keyed by hashes without dictionary names
  (`A0EEDFD9, C5B832D8, B5E84010, 4BBC7579`); target not decoded (candidates: sound/FX/crowd set choice, which matches `Crowd_*_Indoor_*.fsb`).
  The same bytes ship in all 43 venue archives, so they cannot hold venue-specific physics.

## 6. What the surface is NOT (checked)

Not a key of the shot template table, not in the bounce curves, not in the ball block, not in Havok materials, not in the in/out/net/let dice,
not in movement or reach, not in the AI, and the venue archives themselves (`RolandGarros, Londres, LondonO2, Amsterdam, Athens, Melbourne,
ArthurAshe`) contain no surface hash outside the shared `InGameModule.bin` and `CutSceneEngine.bin` (Indoor only).

## 7. Recommended hook for a subtle per-surface retune (target: grass about 5-8% faster/lower, clay about 5-8% slower/higher)

No data-only route exists (one template table, no per-venue override of `Settings.bin`; whether a venue archive entry could shadow a `Core.arc`
path through the composite file system is untested, df.md section on `GameplayEOP.arc`). Smallest code hook, all in the bounce function so the
real ball, the 600-tick prediction copies (`fn_886AD278`) and the AI reach prediction stay consistent, and the in/out roll is untouched because the
first bounce already snaps to the planned landing point (gp4 section 1.4):

* **Patch point**: `fn_889C1C80` tail, the call `bl fn_889C0DC0` at **`889C1F58`** (instruction `4bffee69`). At that moment `ball+0x140..0x14C`
  holds the outgoing velocity in the local frame (m/s; x along the court, y up, z across) and `ball+0x130` the bounce position. Redirect it to
  a trampoline that:
  1. reads `surf = *(*(*(0x88D45A18) + 0xA8) + 0x10)` (the chain used by `fn_887E1928 +0xEC`; null-check each level, treat 0 as Hard);
  2. picks `(sh, sv)`: Hard `(1, 1)`; Grass about `(1.06, 0.94)`; Clay about `(0.94, 1.06)` (Carpet and Wood as Hard, or about
     `(1.03, 0.97)`). `sh` multiplies x and z, `sv` multiplies y, which gives a faster/flatter bounce on grass and a slower/higher one on clay;
  3. stores the scaled vector back to `ball+0x140` and tail-calls `fn_889C0DC0` (the drift vector is rebuilt from the direction).
  Uniform alternative: scale the whole vector, which is the existing factor `1 - c40(spin_a)` computed at **`889C1EA8`**
  (`fsubs f9, f30, f28`): multiply `f9` by one `k_surface` (about 1.06 grass, 0.94 clay); only one constant per surface, but it cannot make the ball both
  faster and lower.
* The factor carries through the arc-2 closed form `p(t) = p0 + (v0 - Weff)(1 - e^{-kt})/k + Weff t` (gp4 section 1.2), so a 6% change of `v0` changes
  the post-bounce reach by about 6% at short times. Let and net rules use other code paths (`fn_889C1F70` net block) and are unchanged.
* Checks to run after patching: golden-vector reference `src/xbox360/drafts/gp4b_ball_model.c` extended with `(sh, sv)`; one rally per surface in Xenia
  with the ball dump (`ball+0x4C0..0x4DC`, `+0x140`) to confirm the surface chain is non-null on a clay and a grass venue.
* If a data-only variant is preferred, the only per-venue levers are the animation takes (Clay clips) and `InGameModule.bin` conditions; neither
  touches the ball.

## 8. Reproduction

```sh
export TS4_MATCHING_DIR=work/matching-b9
# scan Swing_DLL.dll for lis/ori pairs of a hash (the VA is file offset + 0x88004600):
#   for each word w with opcode 15, RA=0, imm == hash>>16, look within 48 bytes for ori/addi with imm == hash&0xFFFF
python3 tools/sym_info.py at 0x8888AEB4          # -> fn_8888ADC0 +0xf4
python3 tools/fn_asm.py fn_886AA940              # writer of m+0x31C / m+0x32B  (886AAC54..AC98)
python3 tools/fn_asm.py fn_886A16D8              # S+0x36C / S+0x370            (886A2330..2350)
python3 tools/fn_asm.py fn_887E1928              # Surface animation qualifier  (887E1A14)
python3 tools/fn_asm.py fn_889C1C80              # bounce response              (889C1EA8, 889C1F48, 889C1F58)
python3 tools/xiso.py extract "orig/54540859/disc_archive/Top Spin 4 (World) (En,Fr,De,Es,It).iso" <outdir> Global.arc RolandGarros.arc Londres.arc ...
python3 tools/ts4_arc.py <outdir>/Global.arc --extract all --out <dir>   # then read <Venue>Desc.bin +0x5C/+0x60 (big endian u32)
python3 tools/ts4data/hkx.py json <venue Physics.hkx>                     # friction / restitution of every hkpRigidBody
```

Archive hashes used: `Core.arc` `7df7bfd575150e9ff3b3a171bada368e8bb4d6676ef82505f46961da0aefbf50`, `Global.arc`
`4c59cfdb3026101564b3062b11a4ece68f5b58db345b416351e01246f7919965`, `RolandGarros.arc`
`c2dc927edf5bae7eadeaa66a4bc4bc4ecba707baef735cef4d356f375e4189d6`, `Londres.arc`
`0ab2bd33e0d0e7bb3382f1d14877dfa7660e2174c02363479710754e8b651f76`, `AnimationsDB.bin`
`3a3a98cf71d1c82479bd5842ac596a599d5e90fa12c22e69e8c65f64aaf7a3dc`, `PlayerList.bin`
`35b3b7267c0e1a642c508340bbdef14aee157124bee0ef6f05e6db719a32398e`. Extracted data stays under the scratch/`work/` directories and is not committed.

## 9. Open items

1. Polarity and default of the `Surface` take accessor (`88269E88`): confirm with one query dump that Clay takes are rejected on a non-clay court.
2. Decode the `InGameModule.bin` surface choice blocks (needs the `Pam::System::Conditions` layout from `Layoutall.bin`).
3. Reader of the `PlayerList.bin` per-surface table (UI/career, probably `Loader_DLL.xex` or schema-generic).
4. Confirm `*(0x88D45A18)+0xA8` and `controller+0x2C` are the same object and non-null during a rally before relying on the patch chain.
