# Gameplay tunables catalogue (agent G5)

Where every value that governs gameplay lives in the Top Spin 4 (Xbox 360) data, how it is typed, which code
reads it, and how to change it. The complete value set is in `data/gameplay/tunables/` (one YAML per
top-level block, all under 5 MiB, `index.yaml` lists them). This note catalogues blocks. It does not repeat
the value tables.

Tags: **V** verified (walked on the retail file, or read in code), **I** inferred, **U** unknown.
Hashes are `zlib.crc32` of the ASCII name. Addresses are Swing_DLL VAs. "cfg+X" means the Settings.bin root
object (file offset 0x24, see section 3), so the file offset is `0x24 + X`.

## 0. Summary

1. **`Layoutall.bin` (disc root) is a full reflection database** (V). It holds 3,642 type records that give,
   for every serialised struct, each member's name hash, type hash, byte offset, size and container kind
   (inline, list, pointer or polymorphic reference). The generic walker in `tools/ts4_xbin.py`
   (`Layout`, `Walker`) uses this table to follow **every** typed member of an XBin file without
   per-file code. The table format is in section 2.
2. **Coverage** (V): every non-zero byte of `State.bin` is reached except 48 bytes (the curve headers of
   one block). In `Settings.bin` the bytes not reached are only XBin-path link records and `{rel,type}`
   reference slots (structure, not values). `PlayerSetup.bin` is reached except 13 bytes.
   No types are left unresolved in the gameplay files listed in section 1.
3. **274,020 editable scalars** are dumped from 12 files. Each scalar has its file offset, type and member
   path. `tools/ts4data/patch_tunables.py` writes edited values back in place and verifies the result.
   It can rebuild `Core.arc` (or a venue archive) for Xenia with the existing archive writer.
4. **Names** (I): 2,743 of 12,988 target hashes are named (21%). The sources are the game's own two CRC
   dictionaries, the strings of every Core.arc member and of the executable, tokens of those strings, the
   `Parent_Member` nested-type rule (two independent 32-bit checks), and two-word combinations (medium
   confidence, about 19 expected false hits). Each name records its source and confidence in
   `work/disc/values/names.json` (local, regenerate with `tools/ts4data/names.py`). Unnamed members print
   as 8 hex digits.
5. **Consumer code** (M): `tools/ts4data/xref_fields.py` finds 135 code reads of Settings root fields whose
   access width matches the member type. Each consistent read with a neighbouring read is printed as
   `# code? <addr>` in the YAML. These reads match every documented anchor: cfg+0x134/0x138 (net and let aim
   heights, `fn_8867E3A0` region 0x8867E730/38, gp8), cfg+0xC74 (Powerful tier, 0x886B5D38, shot-to-template)
   and cfg+0x914 (the third power curve, 0x8869D798).

## 1. Files (inventory of the disc)

Inventory: `python3 tools/ts4data/arc_inventory.py --iso <image>` writes `work/disc/inventory/<Archive>.tsv`
and `summary.json`. The disc has 145 archives. 144 are Pam `.arc` files with 61,308 members, of which 11,927 are
XBin images with 101 distinct root types. `CutScenes.arc` is not a PAM archive (no `PAM-LZX` tag; it holds no
gameplay data). There are two loose XBin files: `Layoutall.bin` (760,816 B, sha256
`67793f5b7dc771f8fde298ef07e8976d9362c864ac577a4c9db6b2bf874788c5`) and `CoreTech_Xenon.bin` (65,864 B,
`aaa269c4...2c2a97`). `CoreTech_Xenon.bin` names the mount paths: `Media\Gameplay\BinData\Settings\Settings.bin`,
`...\Settings\Expressions.bin`, `...\State\State.bin`, `...\Module\Module.bin`, `...\Interface\GameplayInterface.bin`,
`Media\Animation\PlayerAnimData.bin`, `PlayerSetup.bin`, `MenSetup.bin` and `WomenSetup.bin`.

| File | Archive / key | Size (B) | sha256 (decompressed) | Root type | Values | Role |
|---|---|---|---|---|---|---|
| Settings.bin | Core.arc `334E7E0D` | 286,492 | `55cb175d...a0167` | ref -> `9B4FB082` (0xD20 B) | 45,316 | gameplay settings: shot tree, templates, AI, aiming, movement, reach, school |
| State.bin | Core.arc `623D0979` | 273,746 | `ff871577...c4aeb` | ref -> `B77BBB90` (0xF70 B) | 10,305 | initial gameplay state: debug flags, MatchState, 2 ball states, 4 PlayerStates, TeamStates |
| Module.bin | Core.arc `44DC9505` | 428 | `23a18f12...` | ref -> `8070B164` | 28 | module descriptor: MaxMatch 4, MaxPlayer 4, MaxBall 2, analyser lists (Aiming, Serve, Repositioning, ReturnServe, Net) |
| Expressions.bin | Core.arc `FA94F637` | 581,988 | `fd3bc49b...dee9` | ref -> `D440C339` | 79,454 | 341 analyser graphs; semantics in `analyser-graphs.md` (G1) |
| GameplayInterface.bin | Core.arc `F26CDC20` | 5,748 | `8d4f3685...` | `5E16CF76` (SwingGameplayInterface) | 645 | defaults of GameplayInputs/GameplayOutputs (EngineConfig, Commands, Fatigue, RulesInfo, BallInfo, PlayerInfoList) |
| PlayerSetup.bin, MenSetup.bin, WomenSetup.bin | Core.arc `798A36DD`, `F9532D93`, `989D8828` | 24,916 each | `4423ecf9...`, `cf5ba4b9...`, `cd1bfa25...` | `9E65549B` (Setup) | 6,190 each | skeleton: BoneList (198 bones) and the reference pose `Fig/Pose` (5,790 floats) |
| PlayerAnimData.bin | Core.arc `9914D191` | 466,436 | `0843b4ac...` | `AF32244D` (AnimationInterface) | 115,965 | `AnimDataList/Frame[]`: per-frame pose floats (G4) |
| InGameModule.bin | every venue `.arc`, key `62C2690A` | 103,484 | `88bcbdfa...` | `90276CEF` | 2,376 | in-game module graph (CAny objects, module flags) |
| MatchSimulation.bin | venues, `FE620B2D` | 1,788 | `7112dabd...` | `8D1C7B83` | 331 | simulated-match integer tables |
| PlayerEvolution.bin | venues, `E38F72F1` | 4,920 | `34e5d5e2...` | `32286F35` | 1,030 | career evolution: `AttributePack[]` (key, int) |

The venue copies are the same file in every venue: the same key, stored size and uncompressed size in all 43 to 49
venue archives, in one distinct row per file name (`grep` over the inventory TSVs, I). `Amsterdam.arc` is
dumped. `Physics.bin` varies per venue (182 distinct `(key, size)` rows over 358 copies). Each is a list of
object physics configs: strings, keys and flags, with no floats on the Amsterdam copies (V for those 5). They are
catalogued here, not dumped, because they hold no numeric tunables. Not gameplay: FxSettings, crowd, camera
`Shots.bin`, lights, materials, meshes, string tables. Animations.bin, AnimationsInterface.bin and
AnimationsDB.bin are G4's scope; the walker handles AnimationsDB.bin (432k leaves).
`MatchSettingsLib.bin` and the other `*Lib.bin` are Lua 5.0 bytecode (UI scripts, `\x1bLua` header), not XBin.
Their match-setting choices end up in `MatchState` and are catalogued there.

## 2. Formats (V, decoded on the retail files)

### 2.1 Layoutall.bin

```
0x14 array<{u32 class key, u32 root type crc}, 8>    403 entries (module / data class -> data type)
0x20 array<TypeRecord, 0x40>                         3,642 entries, sorted by type crc
TypeRecord: +0x00 first attribute {type, flags, name}
            +0x0C first element {type, flags, name}
            +0x18 array<AttrRec, 0x1C>   scalar members
            +0x24 array<ElemRec, 0x24>   struct / list / pointer members
            +0x30 type crc, +0x34 size, +0x38 align, +0x3C attribute count
AttrRec:  next_type, next_flags, next_name, OFFSET, TYPE, NAME, BYTE_SIZE
ElemRec:  next_type, next_flags, next_name, key, KIND, NAME, OFFSET, align, 0
```

Records form a chain: each one carries the *next* member's `(type, flags, name)`, and the first member's
triple is in the type record header. So an element's type is in the previous record (or in the header).
`tools/ts4_layout.py` (G1) and `shot_tree.Layout` (G2) read the same table. They are partial (only struct and
list kinds, used for naming). `ts4_xbin.Layout` decodes all four kinds plus the attribute byte sizes. Element
kinds:

| kind crc | meaning | storage |
|---|---|---|
| `D543463B` | inline struct (also C3DVector 12 B, C3DVectorA 16, CQuat 16, CMatrix 64) | in place |
| `33F5AD9F` | list | `{s32 rel, u32 count, u32 cap}`, elements at `desc + rel`, stride = element size |
| `6D866019` | pointer | `s32 rel` to one object of the member type |
| `AAB84325` | polymorphic reference | `{s32 rel, u32 type crc}` (type `AAB84325` = "Element") |

`Pam::XBinData::CAny` (`80E55C7B`) is 12 bytes: `{s32 rel, u32 type, u32 class key}`. Attribute (scalar) types
are Boolean (1 B), Int8/UInt8/Char, Int16/UInt16, Int32/UInt32, CKey (u32 crc), Single (f32), UInt64,
CString/XBin paths (`s32 rel` to a NUL string) and Pointer. An attribute whose byte size is a multiple of its
element size is a fixed array (for example `Single[4]`). All `rel` values are relative to the field that holds them.

### 2.2 Gameplay XBin files

Header `{u32 sig, u32 root type, u32 version, 0, 0xFFFFFFFF}`. In generic data trees (header root type
`D2968089`: Settings, State, Module, Expressions) a polymorphic reference sits at 0x14. Other files have their
root struct at 0x14. A walker visits each `(offset, type)` once. Shared objects appear under their first path.

## 3. Settings.bin (root `9B4FB082`, 0xD20 bytes at file 0x24 = "cfg")

Top-level members in file order. The YAML is `data/gameplay/tunables/Settings/NN_<member>.yaml`.

| cfg+ | member (type, size) | values | content and consumers |
|---|---|---|---|
| 0x000 | `761FDECE` (`48125DEB`, 0x14): `Element` ref + list `5F0108A7` | 2,971 | **shot selection tree** (33 nodes `48BFC8B8`, leaves `2C3F7780` {row id}) and the **37 shot template rows** (0x8C each, file 0x137C; curves and constants). Readers: tree `fn_8865A938`, rows `fn_88662390`/`fn_889C19F0` (shot-to-template, gp4b). G2/G3 own the semantics |
| 0x014 | `3F7BD49D` (`80ABE512`): list `Behavior[]` | 827 | AI behaviour table (keys and ints) |
| 0x020 | `AI` (`F2B24032`, 0xDC) | 14,560 | AI parameters: `Aiming`, `Conditions` (difficulty factors Easy 1.0 / Normal 0.8 / Hard 0.6 / VeryHard 0.4), `Double`, `Service`, per-difficulty curves and decision tables. Consistent reads at 0x8846A8C8, 0x886B11BC |
| 0x0FC | `11F82B5C` (`5B8D6994`): list `2A2F8871[]` | 315 | 15 records of 20 floats (positions in cm, 800.0 ...): AI/positioning zones (I) |
| 0x108 | `B50DEF25` (`B1AB555F`): list `C6C76679[]` | 6,950 | 25 records of 276 floats ({x,z} landing points such as 485.3/179.9 cm, plus a key and flag each): aim target tables (I; input-to-shot "aim table", 25 entries in shot-to-template) |
| 0x114 | `9850102C` (`03A127A3`): list | 0 | empty on the disc |
| 0x120 | `40DD9EE9` (`DB2CA966`, 0x60) | 637 | **shot outcome geometry**: cfg+0x130/0x134/0x138 = 100 / **80 / 90 cm** (net and let aim heights; reads 0x8867E730/38, 0x886AD908, 0x886AEA6C, 0x886B225C; gp8 S+0x750/0x754), `39801E1E` widths 50/100 cm (reads 0x88662C7C..94), `7106890E` (9 angle or limit floats), list `00236A48` (571 condition flags and keys) |
| 0x180 | `C4EBA473` (`94729773`, 0x760) | 2,306 | **player movement and positioning profile**: court bounds `0C910649`/`F164EF8E` (-1260/-1250 cm ...), `2906F362` (884 values: positioning grids, 1650/750 cm), `Acting` (200/300/100), `Fatigue` (12 floats, 8 keys), `59F72580` (370 keys, 182 flags: state conditions), `0B337596` (458 floats), `F2300AC2` 100/115, `19543B5D` 300/300/400, `027D6931`, `53EB0CF1`/`E238C406` (8 floats each), 5 ints, `79199F1D` = 1.1 (read 0x8866980C), `FBFB0BC9`/`39185E28` (1.07/1.04/1.00 and 1.12/1.07/1.03 multipliers), `73253DC5`/`5A170C63` (80-float curves) |
| 0x8E0 | `PaddleSettings` (`1A2B0DA3`, 0x18) | 3,402 | **InputMapper** config: buttons, channels, dead zones 0.4, stick scales (input-to-shot s2) |
| 0x8F8 | `MatchSettings` (`30E10B04`, 1 B) | 0 | no scalar members |
| 0x8FC | `A957F922` (`39B6FA65`, 0x30) | 16 | **shot power curves**: 4 curve lists at cfg+0x8FC/0x908/0x914/0x920 (keys at file 0x305BC.., x 0..1.25). These are the curves `fn_8869D798` picks between (shot-to-template "cfg+0x8FC..0x920") |
| 0x92C | `3939C1D9` (`A57BFDA9`, 0x84) | 33 | serve and aiming sectors: five `2D28B4A7` records {0.9, angle (pi, 2.1416 ...), weight}, `0E3C35A0` (read 0x886960C8), `F700452A` (read 0x88681C0C) |
| 0x9B0 | `47CA727B` (`D23F4DBB`, 0x100) | 61 | **swing and contact window**: `8A5D9F93` (46 floats, -700..400 cm geometry, reads 0x8868C0D8..0x8868C5AC), 5 uints (reads 0x8866F7D0, 0x8869BB7C, 0x886B2FD4, 0x8868C430/54), 90.0 / 1.0 / 30.0 (reads 0x8868C3DC, 0x8868C4D4, 0x8868C5AC), a flag (read 0x886BB1C0) |
| 0xAB0 | `3FCC8AC9` (`4250E54F`, 0x34) | 360 | **serve rules**: `ServiceConstraint` 40 / 375 cm (read 0x8865E66C), 45 / 40, `C2379436` (256 floats: service-box geometry), `F98D2C03` |
| 0xAF0 | `3B896EC8` (C3DVectorA) | 4 | 1900, 0, 900 (court extent in cm, I) |
| 0xB00 | `DED1BAA5` (`743633C1`): list `899C4C22[]` | 446 | 23 records (key, floats, flag) |
| 0xB10 | `TopSpinSchool` (`68176BEB`, 0xF0) | 12,352 | tutorial and school lessons (Top Spin Academy): lesson trees, targets, scoring |
| 0xC00 | `B042EAB4` (`E0DBD9B4`, 0x34) | 13 | **reach**: `BF03EAA1` (0.6, 300, 300 ...), `ReachBall` 8.0 / 300.0 |
| 0xC34 | `6FF19A2E` (`F2A0BD48`, 0xCC) | 50 | **shot request thresholds**: `4914978D` = 0.3 / **0.4 / 0.7** at cfg+0xC6C/0xC70/0xC74 (Finesse/Medium/Powerful power tiers; read 0x886B5D38), and about 20 {int, float} pairs (8.0, 0.2, 0.8/80, 0.15, 0.35, 0.5, 6.0, 140.0, 0.33 ...) of the timing and charge rules |
| 0xD00 | `C1F0F632` (`136F0BFA`, 8) | 2 | 30.0 (read 0x886718FC), 2.5 (read 0x8867188C) |
| 0xD08 | `948988C8` (`01E45DB7`, 0xC) | 14 | one 2-D table `7A330099` (rows {key, curve16}; values 0 / 400 cm), the df.md 4.4 table form |

The first column is the root member offset as the layout gives it (V). These offsets agree with the code anchors
from earlier notes (cfg+0x134/0x138, cfg+0x8FC..0x920, cfg+0xC70/0xC74).

## 4. State.bin (root `B77BBB90`)

Initial images that the game copies into its runtime state. An edit here changes the starting value, not a
constant that the code re-reads every frame. Treat these as defaults.

| member | values | content |
|---|---|---|
| `57A6F54C` | 110 | debug / HUD toggles (`MatchState`, `PlayerState`, `BallTrail`, `AIInfo`, `PositioningInfo`, `ShotInfo`, `BallCorridor`, `Rules`, `XhCoach` ...), `MoveController` (-600 ...) |
| `MatchState` | 737 | `RecordReplay`, `Clock`, `Surface`, `IsDouble`, `IsSchool`, `IsTraining`, `IsClay`, `TopSpinSchool` (174 floats), rule state `21B9063D` |
| `MainBallState`, `659B335F` | 317 each | two ball images (`1313CE9C`, `6C78E021` flight states, `Commands`, `Settings`, `SpeedInfo`). The **default ball block** (radius, drag `a4`, gravity, bounces; shot-templates s3) is `659B335F` at file 0x964 |
| `PlayerInputConfigState` | 25 | per-pad flags |
| `B56A13CB` | 87 | camera / view defaults (75 floats) |
| `PlayerStates/PlayerState[]` | 7,240 | PlayerState images (type `502FE79D` list, stride 0x1070): stats S+0x64C..0x668, error and let probabilities S+0x718/0x71C, aim heights S+0x750/0x754, `ShotSelection` at +0x400 (G2), fatigue +0xF20 (G1) |
| `E25EDAE7/E9CA839C[]` | 1,368 | per-player analyser state blocks (the `e9ca839c` domain of the graph ports) |
| `340DD477/TeamState[]` | 104 | team defaults (1300 / 300 cm positions) |

## 5. Other files

* **Module.bin**: `MaxMatch` 4, `MaxPlayer` 4, `MaxBall` 2, `4E743CCD` 50, `F72C6A0B` 2, and the analyser
  name lists. Changing the limits needs matching code capacity. Do not raise them.
* **GameplayInterface.bin**: interface defaults (`Fatigue` 1.0 x4, `EngineConfig`, `Commands`). Overwritten
  at run time.
* **Expressions.bin**: every CONST value, curve key (`x0, x1, y0, slope`) and register or cell index of the
  341 graphs. Edit the float keys only. Changing an index rewires the graph. `tools/ts4_analyser_patch.py`
  (graph or node addressing) and this YAML (offset addressing) write the same bytes.
* **Setup / PlayerAnimData**: skeleton and pose data. These are listed for completeness and are not tuning levers.
* **MatchSimulation / PlayerEvolution**: career simulation and progression tables (integers).

## 6. Workflow

```sh
ISO="orig/54540859/disc_archive/Top Spin 4 (World) (En,Fr,De,Es,It).iso"
python3 tools/xiso.py extract "$ISO" work/disc/root Layoutall.bin CoreTech_Xenon.bin
python3 tools/ts4data/names.py --layout work/disc/root/Layoutall.bin \
    --strings work/disc/core_all orig/54540859/Swing_DLL.dll work/disc/root \
    --xbin work/disc/core_all/{334e7e0d,623d0979,fa94f637}.bin --out work/disc/values/names.json  # optional
python3 tools/ts4data/xref_fields.py --dll orig/54540859/Swing_DLL.dll --layout work/disc/root/Layoutall.bin \
    --type 9b4fb082 --out work/disc/values/xref_settings.json                                     # optional
python3 tools/ts4data/dump_tunables.py --iso "$ISO" --out data/gameplay/tunables
# edit values in a copy of the YAML parts you care about, then:
python3 tools/ts4data/patch_tunables.py my/Settings/*.yaml --iso "$ISO" --out work/patched --rebuild
python3 tools/ts4_iso_patch.py "$ISO" work/patched/game --arc Core.arc=work/patched/Core.arc
```

Measured on the retail image: an unedited dump patches back to identity for all 12 files. Changing cfg+0x134
from 80.0 to 95.5 gives patched `Settings.bin` sha256 `4ce8baf7...cbf3a`. The rebuilt `Core.arc` is
37,244,346 B, the same size as the raw-member rebuild in `docs/data-patching.md`. The member reads back.
Tests: `python3 -m unittest tests.test_tunables` (synthetic layout and data). These cover the walker, identity,
edits of every scalar type, the reverse patch, and rejection of out-of-range values, wrong types, wrong
paths and wrong offsets.

## 7. Open items

* Names: 79% of hashes are unnamed. The root type names of Settings and State are unknown, which blocks the
  nested-name rule for their subtrees. Next sources: Title Update #1 data, PlayerCreator `*crc.bin`, and larger
  two-word searches restricted to member names with a type check.
* Consumer code exists only for Settings root fields reached through `ctx+0x6C`, and it is heuristic (M).
  State.bin defaults are consumed as runtime PlayerState fields (documented per field in gp2..gp8). Movement
  `cfg+0x1DC..0x630` in gp3 / movement-and-ai is a different object (planner profile) and is not yet mapped
  to a data member.
* Shared objects are dumped once. Editing one changes every user of the object.
* Physics.bin per venue holds no numeric tunables in the copies checked. The ball's physical constants are in
  the State.bin ball block (section 4) and in code (gp4).
