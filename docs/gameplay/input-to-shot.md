# Input to shot: how controller input becomes a shot request (family GPA, tuning link 1)

Module `Swing_DLL.xex`; PE image `orig/54540859/Swing_DLL.dll` (13,848,064 B, sha256 `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9`),
split `work/matching-b9`, `TS4_MATCHING_DIR=work/matching-b9 python3 tools/fn_asm.py fn_X`, `tools/sym_info.py` (index rebuilt from the b9 split), Python 3.13.18.
Disc data (local only, never committed): `Core.arc` (36,997,962 B, sha256 `7df7bfd575150e9ff3b3a171bada368e8bb4d6676ef82505f46961da0aefbf50`),
extracted with `python3 tools/ts4_arc.py orig/54540859/disc/Core.arc --extract <hash> --out <dir>`:
`Settings.bin` = entry `334e7e0d` (286,492 B, sha256 `55cb175dbaf64e30d75f6fe72ae71305a39a39cffca7a2fa3b2e5471431a0167`),
`State.bin` = `623d0979`, `Expressions.bin` = `fa94f637` (581,988 B, sha256 `fd3bc49b44ca4b77deebc58acaefe67763a273538f4901266f949e9ec9dedee9`).
Name hashes are `zlib.crc32` of the ASCII name. All addresses are xex VAs. Offsets in `Settings.bin` are file offsets; every `rel` is a signed 32-bit
offset relative to the address of the field that holds it (`-1` = null). Confidence tags: **H** read directly in code or data and reproducible,
**M** consistent structural evidence, **L** inference.

## 0. The model in plain terms

1. Every poll the 360 pad driver fills a **0xC4-byte input record** (12 button slots, 6 axes). Digital buttons are 0 or 255; the two triggers are 0..255. (H)
2. The **InputMapper** (`CInputMapper`, vtable `0x880D7608`, Update `fn_88910F50`) is a fully **data-driven** mapper. Its table is in `Settings.bin`
   (root node at file offset `0x2C110`). It turns the raw record into **XData attributes inside each player's PlayerState node**, via path strings
   such as `ShotTriggers/Shot[@Id="Flat"]/@Raise` or `Buttons/@RT`. No button-to-action table is in code; the code only fixes the **threshold semantics**. (H)
3. The four face buttons select the **stroke type** and nothing else: **A = Flat, B = TopSpin, X = Slice, Y = Lob** (H, data `Settings.bin` 0x2C150..).
   **LT and RT are the same "Risk" modifier** (`@Risk`, level, down when the trigger value is above 128 of 255) (H). **RB = Rush/sprint + fast and volley
   reposition request, LB = speed-swing + baseline reposition request** (H for the names, M for the effects).
4. A shot is requested in this order (H for the code path, M for the semantics of the XData names):
   button held (level) -> `ShotInputLatch` latches the first held shot button (priority Flat > TopSpin > Slice > Lob) -> release of that button is the **"Raise"** event
   -> `fn_8868F178` converts the raised shot id into the **ShotSelection/Request flags** (`IsTopSpin`, `IsSlice`, `IsLob`, `IsSmash`, `IsRisk`, ...) at PlayerState `+0x400..+0x40B`
   -> a **data decision tree** (`Settings.bin` 0xD44..0x137C) maps these flags to a **shot id** (e.g. `TopSpinPowerful`, `SliceFinesse`, `DropShotNormal`, `FlatVolley`)
   -> the shot id picks the shot record and its **template row** (`record+4` minus the table base = the byte offset that becomes `ball+0x360`) -> the planner builds the swing command (`Gp3SwingCommand`, gp3).
5. **Power is not a code threshold.** The tree has three power tiers per stroke (no flag = **Finesse**, `IsMedium` = **Medium**, `IsPowerful` = **Powerful**), and the flags
   `IsMedium`/`IsPowerful` are produced by **analyser graphs** (data) each frame in the swing-ready state; the code only reads their 0.5 threshold. How long a button
   must be held for Medium or Powerful is therefore **in data** and is **not yet decoded** (section 9). **Risk** is the trigger level.
6. **Aim** comes from the left stick (`Stick_Aiming/@X,@Y`, range -1..1); `fn_8869C010` converts it to (lateral angle, forward depth 0..1), mirrored per court side. (H for the code, M for which XData name feeds `+0x448/+0x44C`)
7. **Timing**: code measures the frames between the **opponent's last hit** and **the moment the shot request starts** and stores it as float `PlayerState+0xCF8` (`fn_8866B8C0`, H).
   The Good/Medium/Bad grade is a separate data-driven random roll (gp2 6.4, gp8). Nothing in code compares the button time with the ball arrival; that comparison is also in analyser data (M).

## 1. Layer 1: the raw pad record (0xC4 bytes) (H)

Polled by the Xenon paddle driver (`fn_888854B0`, 0x370 B; it calls `XamInputGetState` through `ts4_tailcall_XamInputGetState_8857B170`, and `fn_88884C08` is the rumble side).
Records live in a ring owned by the engine object `lbl_88D45B1C+0x234` (count `+0x34`, base `+0x3C`, slot table `+0x30`; the mapper picks `base + slot*0xC4`, see `fn_8890DCC8`).

| record offset | content |
|---|---|
| `+0x00..+0x2C` | twelve 32-bit "button index" words (the index handed to the edge helper; constant 0..11 in practice, M) |
| `+0x30 + 4*i` | button slot i: `u8 value` (+0) and a halfword flag word whose bit `0x40` = **press edge**, bit `0x80` = **release edge** (one poll only) |
| `+0x60 + i` | press threshold per button, reset to **1** by `fn_886096C0`; `+0x6C + i` release threshold, reset to **0**; `+0x78 + i` "armed" flags |
| `+0x84 + 4*a` | axis a, `int16` in the first halfword (a = 0..5) plus flag halfword (`fn_886094C8`); press thresholds `+0x9C..+0xA6` reset to 1 |
| `+0xB4/+0xB8` | float pair (rumble/motor state, driver side) |
| `+0xBC` | connection state (**2** = usable; the mapper skips a record unless this is 2, `fn_88910F50 +0x94`) |

Button slot ids (`fn_888854B0`, XINPUT_GAMEPAD masks): 0 = A (0x1000), 1 = B (0x2000), 2 = X (0x4000), 3 = Y (0x8000), 4 = LB (0x0100), 5 = RB (0x0200),
6 = LT (`bLeftTrigger`, analog), 7 = RT (`bRightTrigger`, analog), 8 = left thumb click (0x40), 9 = right thumb click (0x80), 10 = Start (0x10), 11 = Back (0x20).
Digital buttons store 0 or 255 (`fn_886095B8` is called with `(mask ? 0xFF : 0)`). Axis ids: 0 = D-pad X (right - left, +-32767), 1 = D-pad Y, 2 = LX, 3 = LY, 4 = RX, 5 = RY (each with an
invert byte `this+0x1C/+0x1D` of the driver). Two synthetic axes exist in the reader `fn_8890D5F0`: id 6 = "left stick X if the left stick is non-zero else right stick X", id 7 = same for Y
(not used by the shipped config).

## 2. Layer 2: the InputMapper (`CInputMapper`, vtable `0x880D7608`)

Vtable (H): `[2]` Update `fn_88910F50` (0x714 B), `[4]` Init `fn_889117B8` (0x240), `[5]` Exit `fn_8890FEB0`. Registered at engine level as service `0x8B430A2D` (`crc32("InputMapper")`),
engine object `+0xD0` (gp0). Note `fn_88911668` (0x14C) is the "reload" entry and `fn_88910CF0` (0x260) builds the per-player records.

### 2.1 Load (once, `fn_889117B8 -> fn_88910CF0 -> fn_88910038`) (H)
* `fn_88910CF0`: for each player entry (stride 0x10 in the typed struct `0x2F68067A`/`0x1A2B0DA3`; element = player index, pad index, flags) it resolves the player's PlayerState node
  (`PlayerStates`, type `0x502FE79D`, **stride 0x1070**) and a config node (stride 0x40, type `0xFD0DA8E3`), and creates one **0x34-byte player record**
  (`+0x18` = pointer to the 0xC4 pad record, `+0x20` = pad slot, `+0x28` config, `+0x2C` enabled byte, vectors at `+0x00` (buttons, 0x28-byte items), `+0x0C` (stick channels, 0x24-byte items), `+0x18`).
* `fn_88910038` walks the config node and, for every path string, asks the XData tree for the **attribute address** (`fn_8862BCB8` + tree vtable `+0x28`, size 1 for a bool, 4 for a float). The path is
  relative to the player's PlayerState node, so every output below is an **attribute inside that player's PlayerState**, written by pointer each frame. (H for the mechanism; the base-path string
  in the per-player entry (`+0x0C`) was not read, L.)

### 2.2 Config node layout (`Settings.bin`, root at 0x2C110, 0x40 bytes) (H)
```
+0x00 {rel,count,cap}  buttons      11 items, stride 0x10: {rel->items, count, cap, key hash}
+0x0C {rel,count,cap}  stick channels 3 items, stride 0x18: {rel->items, count, cap, axisX id hash, axisY id hash, float deadzone}
+0x18 {rel,count,cap}  4 items, stride 0x34, keyed by shot id (Slice fc6f57a1, Flat f578057a, TopSpin d9fa1b37, Lob c718daaa)   (not read by fn_88910038, section 9)
+0x24 {rel,count,cap}  3 items, same keys                                                                                   (not read by fn_88910038, section 9)
+0x30 f32 0.55, +0x34 f32 0.8, +0x38 1, +0x3C 0                                                                              (unknown)
```
Button key -> slot id table (`lbl_88C6B760`, 12 x {hash, id}, H): `31dfdd4f`=0 (A; crc32 `Button_A`), `a8d68cf5`=1 (B), `dfd1bc63`=2 (X), `41b529c0`=3 (Y), `ea3cec17`=4 (LB), `fc84626d`=5 (RB),
`7335bdad`=6 (LT), `658d33d7`=7 (RT), `17e7a91f`=8 (`ButtonStick_2`), `60e09989`=9 (`ButtonStick_3`), `5eb87a8b`=10 (Start), `cdfc6e09`=11 (Back).
Axis key -> axis id table (`lbl_88C6B7C0`, 8 entries): `f113e7bb`=0, `f0d18d8c`=1, `681ab601`=2, `69d8dc36`=3, `1f1d8697`=4, `1edfeca0`=5, `d47eb74d`=6, `4971563b`=7.
Button item types (`{rel,type}` -> record): `0x992C138B` = **LEVEL** bool output (record: `u8 invert`, `rel path`), `0x32B69F1A` = **PRESS edge** bool (record: `rel path`), `0xEA646810` = **RELEASE edge** bool.
Stick item types: `0x8312E402` = Cartesian pair (X path at +8, Y path at +0xC, floats `+0x10/+0x14` = range scale), `0xB8ED75CD` = Cartesian pair that is converted to **polar** (Power, Angle, angle range +-pi),
`0xA31497B5` = direction bool (hash of `Up/Down/Left/Right` + threshold float 0.5, D-pad).

### 2.3 Update semantics (`fn_88910F50` + `fn_8890DB90`) (H)
Per enabled player record whose pad record has state 2:
* **Buttons** (`fn_8890DB90`, per item): float outputs get `(float)value`; **LEVEL bools: for slots 6 and 7 (LT, RT) `value > 0x80` (i.e. 129..255 of 255), for every other slot `value != 0`**; the item's
  `invert` byte then flips it. **Edge bools** take bit 0x40 (PRESS) or 0x80 (RELEASE) of the slot's flag word. Edges last one poll. The raw record thresholds (press >= 1, release <= 0, `fn_886096C0`)
  make the edge fire on **any** non-zero trigger value, but the level bool of LT/RT needs > 128.
* **Sticks** (per channel): read the two raw axes (+-32767 as float), apply the channel dead zone (data, 0.4 on all three channels), optional smoothing (items carry two ints, `1/30` for Aiming, `10/30` for Move, `1/30` for
  the rest; meaning not decoded, L: filter length and limit) and write X/Y scaled by the item's range scale; for polar items `fn_8890E358` computes Power (0..1) and Angle (radians).

### 2.4 What the shipped config does (decoded from `Settings.bin`, H)

Buttons (each line = XData output, type):

| pad control | outputs |
|---|---|
| **A** | LEVEL `ShotTriggers/Shot[@Id="Flat"]/@Raise`; RELEASE `Shots/Shot[@Id="Flat"]/@Raise`; LEVEL `Serve/Classic/@ThrowFlat`; RELEASE `Serve/Classic/@Flat`; LEVEL `Buttons/@A`; PRESS `Buttons/@PressA`; RELEASE `Buttons/@ReleaseA` |
| **B** | same with `TopSpin`, `Buttons/@B/@PressB/@ReleaseB` |
| **X** | same with `Slice`, `Buttons/@X/...` |
| **Y** | LEVEL `ShotTriggers/Shot[@Id="Lob"]/@Raise`; RELEASE `Shots/Shot[@Id="Lob"]/@Raise`; LEVEL `@SpecialShotDetected`; RELEASE `@SpecialShot`; `Buttons/@Y`, `@PressY`, `@ReleaseY` |
| **LT** | LEVEL `Buttons/@LT`; LEVEL **`@Risk`**; PRESS `@AskNext` |
| **RT** | LEVEL `Buttons/@RT`; LEVEL **`@Risk`**; PRESS `@AskPrevious` |
| **LB** | LEVEL `Buttons/@LB`; LEVEL `@ReqSpeedSwing`; LEVEL `@ReqBaselineRepos`; PRESS `@OnRaiseReqBaselineRepos` |
| **RB** | LEVEL `Buttons/@RB`; LEVEL `@ReqFastRepos`; LEVEL **`@Rush`**; LEVEL `@ReqVolleyRepos`; PRESS `@OnRaiseReqVolleyRepos` |
| Right-thumb click | PRESS `@ShotEditor_Reset`; Start: PRESS `@ShotEditor_Launch`; Back: PRESS `@RequestChallenge` (all three are debug/shot-editor/challenge hooks) |

Sticks (channel = axis pair, dead zone 0.4 each):

| channel | outputs |
|---|---|
| left stick (axes 2,3) | `Stick_Aiming/@X,@Y` (scale 1.0, ints 1/30); `Stick_Move/@X,@Y` (scale 1.0, ints 10/30); `Stick_MovePolar/@Power,@Angle` (polar) |
| D-pad (axes 0,1) | `Stick_1/@X,@Y` (scale **25.0**); `DPad/@Up,@Down,@Left,@Right` (direction bools at 0.5) |
| right stick (axes 4,5) | `Stick_3/@X,@Y` (scale **25.0**); **`Serve/Advanced/CartesianStick/@X,@Y` (scale 10.0)**; **`Serve/Advanced/PolarStick/@Power,@Angle`**; `PolarStick_3/@Power,@Angle` |

So: **the advanced serve is driven by the right stick only**, the classic serve by A/B/X (see 6.3); the left stick feeds both aiming and movement (and the polar movement vector used by the swing selection).

### 2.5 Which behaviours this answers
* "RT = risk/hard-hit modifier" (the user's belief): **confirmed, and LT does the same.** Both triggers write `@Risk` (level, active above 128/255) and also `Buttons/@LT|@RT`; the press edges `@AskNext/@AskPrevious`
  belong to menus/school. It is a **hold** modifier, read as a flag, not an analog amount. (H)
* Dash: `RB` = `@Rush` (level) plus `@ReqFastRepos` and `@ReqVolleyRepos` (+ press edge `@OnRaiseReqVolleyRepos`). `LB` = `@ReqSpeedSwing` + `@ReqBaselineRepos`. No stick-click sprint exists in the config. (H names, M effects: the consumers read
  the bool at a PlayerState offset that is only reachable through the XData schema.)

## 3. Layer 3: the PlayerState input block (offsets from the PlayerState base, `S`)

Evidence: bytes read by the movement/swing state machine and the latch (H unless noted). Names are the XData attributes of 2.4 that these bytes are consistent with (M).

| offset | meaning |
|---|---|
| `S+0x430..0x46C` | 14-float block cleared every frame by `fn_8865F518` (gp0); contains the stick outputs. `S+0x440` stick intensity, `S+0x444` stick angle (the **polar Move** pair, `> 0.2` = "stick used", gp2), `S+0x448/0x44C` aim stick (lateral, forward) (`fn_8869C010`, zeroed for AI) |
| `S+0x400..0x40B` | **Request flags** (section 4): 0x400 Flat, 0x401 TopSpin, 0x402 Slice, 0x403 Lob, 0x404 Risk (copy of `S+0x4D8`), 0x405/0x406/0x407/0x408 cleared by `fn_8868F178` then set by analysers/command copy (power tiers, M), 0x409 Smash, 0x40A/0x40B others |
| `S+0x40C` | start of the **Inputs** sub-block: `+0x0C` relative array of 8-byte `{shot id hash, byte Raise}` = `Shots` list (`S+0x418`, 4 entries); `+0x64..+0x67` (`S+0x470..0x473`) = **`ShotTriggers` level flags Flat, TopSpin, Slice, Lob** (read by `fn_88679C78`, `fn_886B3CF8`, `fn_886A84C0`, `fn_8866B8C0`, `fn_886900E8`) |
| `S+0x474..0x477` | four per-shot event flags (the latch stamps the frame at which each is set; `fn_8866B8C0` maps Flat/TopSpin/Slice/Lob to stamps `+0x1C/+0x20/+0x24/+0x28`) (M: the `Shots/.../@Raise` release events) |
| `S+0x478..0x47B` | `Buttons/@A, @B, @X, @Y` level (proved by the hashes `crc32("A")=d3d99e8b`, `"B"=4ad0cf31`, `"X"=b7b2364b`, `"Y"=c0b506dd` that `fn_886A84C0 +0x730..+0x7C0` loads for each) |
| `S+0x4D8` (= block `+0xCC`) | **Risk level**, latched into `PC+0x3C` flag by `fn_88687528` (H for the code; M that it is `@Risk`) |
| `S+0x4D9/0x4DA` | per-frame **event** flags cleared at the start of `fn_88679C78`; `S+0x4D9` set => `fn_886B3CF8` runs `fn_8868F178` + `fn_8866B8C0` (a shot request this frame) |
| `S+0x4CC` | ring buffer `{rel; capacity at +0x4D0; index}` of 8-byte `(move intensity S+0x9D4, move angle S+0x9D0)` per frame, filled by `fn_88679C78`; reset by `fn_886799D0`. This is the **stick history** (flick/sweep detection input for analysers, M) |
| `S+0x5D9/0x5DA` | copies of command bytes `C+0x99/C+0x98`; `0x5DA` = overhead/smash situation (forces shot id Smash in `fn_8868F178`) (H) |
| `S+0xCF8` | float **frames from the opponent's last hit to the shot-request moment** (`fn_8866B8C0`, H) |
| `S+0x3A0/0x3A4` | hit-quality grades (Good/Medium/Bad), gp2 6.4 |

### 3.1 `ShotInputLatch` (component of the PlayerController, `PC+0x50`, vtable `0x880F43E8`, slot 1 = `fn_88679C78`, 0x2CC B) (H)
Per frame, in order:
1. clear `S+0x4D9`, `S+0x4DA`;
2. if the latched shot type (`this+0x18`) is 0, latch the **first set** of `S+0x470` Flat, `+0x471` TopSpin, `+0x472` Slice, `+0x473` Lob (**priority Flat > TopSpin > Slice > Lob**, hashes `f578057a`, `d9fa1b37`, `fc6f57a1`, `c718daaa`);
3. if a type is latched: block byte `+0xCD` = 1 ("a shot button was pressed"); if that type's flag is now 0 again: `+0xCE` = 1 (**released**, the "Raise");
4. `+0xD4 = +0xD3`; `S+0x5C0` = `0x2CE33943` if `S+0x424` else `0x1110721A` if `S+0x425` (serve/return mode hash, names unresolved);
5. append `(S+0x9D4, S+0x9D0)` to the stick ring at `S+0x4CC[match_frame % capacity]`;
6. for the eight flags `S+0x474..0x47B` keep a **"last frame this flag was true"** stamp at `this+0x1C..+0x38` (stamp = `match+0x310` if the flag is set, else unchanged).
Reset (`fn_886799D0`): latched type 0, `S+0x5C0` = `0x2CE33943`, ring zeroed.

### 3.2 The swing-request state machine (`fn_886B3CF8`, 0xA08 B, human-only parts) (H for control flow)
States are CRC hashes: `0xAFAF1093` (waiting for the request), `0x93E5E96D`, `0xF6EB6636`, `0x658B2E11` (request accepted / swing starts, the value returned by the path through `fn_886B0380`, `fn_8865EE40`), `0x35649982` (aborted), `0x029EAAF4` (point end).
In state `0xAFAF1093` for a human (`PC+0x10 != 0`): if any of `S+0x470..0x473` is held, `PC+0x58C`, `PC+0x59D` are set and `PC+0x59E` is clear => `fn_88698538` (**begin shot request**: sets `PC+0x59E`, runs `fn_8868F178`
and `fn_8866B8C0`, clears `PC+0x58C`); `S+0x4D9` set does the same through `fn_8868F178 + fn_8866B8C0` with `PC+0x58D = 1`. Counters: `team+0x3BC++` while no request/`+0x3C4++` while `S+0x4D8` (risk) is set (statistics, H).
Auto swing: when the ball is hittable and no button came, the state machine sets `Raise` of the **Flat** entry in the `Shots` list for every entry whose Id is Flat (`fn_886B3CF8 +0x5E0`, `fn_88662648`), which is the auto-swing (rule names `AutoSwing`/`AutoVolleySwing`, gp8). (H for the store, M for the role)

## 4. Layer 4: Request flags and the shot-selection decision tree (data)

`fn_8868F178` (0x1A0 B) (H): takes the **first entry of the `Shots` list (`S+0x418`) whose Raise byte is 1** (`fn_88270780`), stores its Id as the current shot id at `PC+0x3C` (replaced by **Smash `7eb30f90` when `S+0x5DA`**),
clears `S+0x400..0x40B`, then sets `S+0x400` = (id == Flat), `+0x401` TopSpin, `+0x402` Slice, `+0x403` Lob, `+0x409` Smash, `+0x404` = `S+0x4D8` (**Risk**), and zeroes `+0x407/+0x408`.
These are the attributes `ShotSelection/Request/@Is...` named in `Settings.bin` (strings at 0x42C1C..: `IsWoodDown, IsWood, IsClassicServe, IsTopSpin, IsMedium, IsPowerful, IsSlice, IsAdvancedServe, IsSmash, IsRisk, IsLob`, plus `Context/ShotContext/@ModeBaseLine`).

### 4.1 The decision tree (`Settings.bin` 0xD44..0x137C, decoded, H for structure)
Node = `{rel 0x18, 2, 2, flag-name crc32, rel path, 0}` followed by two child slots `{rel, type}`: type `0x2C3F7780` = **leaf** `{shot id hash, 0}`, type `0x48BFC8B8` = **sub-node**; child 0 = flag true, child 1 = flag false.
Decoded tree (leaf names recovered by crc32 search over `{Flat,TopSpin,Slice,Lob}x{Finesse,Medium,Powerful,Risky,RiskyFinesse}`; every one is a 32-bit match):
```
IsWoodDown -> WoodDown
IsWood     -> Wood
IsClassicServe -> TopSpin: Medium b31b5ee0 | Powerful 17c6bfe3 | else ea0cf389
                  Slice  : Medium 5f8e74c3 | Powerful 72d4edc1 | else 488717d1
                  other  : Medium 6bbc9a88 | Powerful 26eb8042 | else a9bdbd27      (serve ids, names unresolved; order TopSpin/Slice/Flat = kick/slice/flat serve)
IsAdvancedServe -> TopSpin fa212c96 | Slice c1e2aa62 | else a010111f              (advanced serve ids, unresolved)
IsSmash -> SmashNormal
ModeBaseLine:
   IsPowerful: TopSpinPowerful 4b121fa5 | Slice: (IsRisk -> DropShotNormal else SlicePowerful 65dc9a5a) | Lob: LobPowerful 11a1b9d0 | else FlatPowerful 992258dc
   IsMedium:   TopSpinMedium a413297b   | Slice: (IsRisk -> DropShotNormal else SliceMedium 4637fcf0)   | Lob: LobMedium bb50ea44   | else FlatMedium be02d81e
   neither:    TopSpinFinesse 8dc6b132  | Slice: (IsRisk -> DropShotNormal else SliceFinesse f74ecf4f)   | Lob: LobFinesse 3bbfdfcc  | else FlatFinesse b0043514
not baseline (volley): TopSpinVolley 14d5efaa | Slice: (IsRisk -> DropVolley 8ff66130 else SliceVolley f6f13a21) | else FlatVolley 0ec41ecf     (Lob in volley mode falls to FlatVolley)
```
Consequences (H for the tree, M for how the flags are produced):
* **Drop shot = Slice button while Risk (LT or RT held)**; baseline gives `DropShotNormal`, volley mode gives `DropVolley`. There is no drop-shot button.
* **Lob = Y**; there is no Risk variant of the lob in the tree, and in volley mode Y yields `FlatVolley`.
* **Smash is automatic** (any shot button while the overhead situation flag `S+0x5DA` is set).
* The tree has **no Risky leaves** (`TopSpinRisky`, `FlatRisky`, `SliceRisky`, `LobRisky`, `*RiskyFinesse` exist as ids and as template rows 12..15, `Settings.bin` 0x1A0C..) outside the drop shot, so Risky strokes are chosen **elsewhere**
  (probably by the analyser layer that sets `S+0x405..0x408`, or by the `Risk` flag inside the shot record/animation selection). **This is the biggest open point for the Risk link** (section 9).
* Power tier: `IsPowerful` is tested first, then `IsMedium`, otherwise Finesse. `IsMedium` and `IsPowerful` are set by analysers (below).

### 4.2 Tier flags (`fn_886B3CF8`, state `0x93E5E96D` path, `0x886B40E4..0x886B4300`) (H for flow, L for naming)
Before the swing starts, an analyser from three alternatives (`this+0x328` when `S+0x5D9`, else `this+0x3B0` if `this+0x3E` else `this+0x36C`) is evaluated (`fn_8890E988`), then three booleans are formed from byte flag + float threshold 0.5
(`pool lbl_8814B910` = 0.5): `S+0x5DD && S+0x7C4 > 0.5`, `S+0x5DF && S+0x7C0 > 0.5`, `S+0x5D9 && S+0x5DE && PC->team mode != 2 && S+0x7BC > 0.5`. If any is true (and the timer `this+0x38 > 0` and the player can swing, `fn_886872A0`/slot `+0x28`),
the machine requests the swing. This is where the **power tiers** are decided; the floats `S+0x7BC/0x7C0/0x7C4` are analyser outputs (data), the 0.5 is a code constant. (M)

## 5. Layer 5: aim target, InputNotation, command

* **Aim** `fn_8869C010` (0x228 B, H): the aim object (`this+0x14`) mode hash selects the source: `0x9E51242B` = **stick aim** (vector `(S+0x44C, 0, -S+0x448)`, forced to 0 for non-human players), `0x8999A0BF` = neutral (0,0),
  `0x487570E4` = **auto target** (`fn_8869BEF0`, ball-relative). Result written to `aim+0x30` (**lateral angle**, `atan2` of the stick vector plus `pi` when the court-side tag `a2eda1e7` is set, wrapped by `fn_8817B608`) and `aim+0x34`
  (**depth = clamp(stick forward, 0..1)**), then mirrored to `+0x38/+0x3C`. Callers: `fn_886A3DDC`, `fn_886A4098`, `fn_886A4244`, `fn_886A487C` (the mode siblings of `fn_886A3DF0`), `fn_886AA364`, `fn_886BB094`, `fn_886C0850`, `fn_886C15E4`.
  The planner `fn_886AE528` takes `aim+0x30/+0x34` into `ball+0x430` and `ball+0x364` (spin blend) (`fn_886AE528 +0x2CC..+0x2F8`, M: the argument `r19` is the aim object).
* **InputNotation** (gp2 section 3 step 5): not an input read but a swing-candidate score term: for an input-driven player (`PC+0x10`) `fn_8868AF88` fills `ReachRecord.input_notation[i]` per ball sample from the stick angle (`S+0x444`, +pi on one court side) and
  stick intensity (`S+0x440 > 0.2` selects the directional path); samples on the side the stick points toward score higher. It chooses **which ball sample/side** is hit, not the stroke type.
* **Command**: the planner builds `Gp3SwingCommand` (gp3/gp4b: template row offset `C+0x48` -> `ball+0x360`, spin blend `C+0x50`, w `C+0x4C`, shot id `C+0x8C`, due frame `C+0xA0`); when `due_frame <= match frame` `fn_886B5128` applies it (gp3 section 1).
  For an input-present player the bytes `C+0x99/0x98/0x9A/0x9B` are copied to `S+0x5D9/0x5DA/0x405/0x404` first, i.e. the **Request tier/risk bytes `0x404/0x405` can be overwritten by the command** (H). The row byte offset is `shot_record+4 - table_base` (`fn_886AE528 +0x798`, H);
  how the shot id picks the record is not decoded.
* Template rows (gp4b/shot-templates.md): rows 0..3 Finesse (TopSpin, Slice, Flat, Lob), 4..7 and 8..11 the two "Normal" groups (initial speeds Flat 130 and 140 km/h, most likely **Medium and Powerful**, M: same names, speed step 130 -> 140), 12..15 Risky, 16..19 volleys,
  20..31 serves, 32 DropShotNormal, 33 SmashNormal, 34 DefensiveShot, 35/36 Lob. The leaf ids `TopSpinPowerful`/`TopSpinMedium` etc. are *not* row names; the mapping leaf -> row is data (not decoded).

## 6. Direct answers

### 6.1 Shot buttons, tap vs hold, charge
* Flat A, TopSpin B, Slice X, Lob Y. A tap and a hold produce the same latched stroke; the **hold length** is only visible through the stamps/flags that analysers read (**Finesse = no tier flag** (control, softest), **Medium**, **Powerful**; `S+0x7BC..0x7C4` threshold 0.5). The numeric hold times are not in code and not yet decoded from data.
* No code constant gives a "circle fills" meter. The debug HUD labels in `State.bin` (0x42B7C..) list the quantities an analyser exposes: Inputs `Timing`; Outputs `PwrFactor`, `TechFactor`, `AimEff`, `QuadEff`, `OutcomeNet`; Context `BallDiff`, `IncIniEffect`, `IncCurrEffect`, `AnimPower`, `AnimControl`; State `Recovery`, `CurrentVigor`, `Vivacity Amplitude/Transition`; Serve `AnimationSpeedFactor`, `MinSpeed Hit`, `MaxSpeed Hit`, `SpeedFactor`, `Amplitude`, `Precision`;
  `AnalogShots`: `PrepaPrecision`, `ReleasePrecision`, `SuccessFactor`, `InputState` (crc32 of these labels is not used as an immediate anywhere in `.text`, so they are display names, M). This indicates **power vs control** (`PwrFactor`, `TechFactor`) and an **analog/hold-and-release precision** model exist in data. A fill meter, if any, is rendered from such outputs (UI side, not traced).
* Right-stick "analog shots" are not present in the input config (right stick = Stick_3 and the advanced serve only); the label group suggests an analog mode that needs the `InputState` flags.

### 6.2 Shot family (Normal/Risky/Finesse)
Finesse/Medium/Powerful is the **tier flags** result (4.1, 4.2); Risk is the LT/RT hold (`@Risk` -> `S+0x4D8` -> `S+0x404` IsRisk) and, in the decision tree, only selects the drop shot (`DropShotNormal`/`DropVolley`). The Risky template rows
(`TopSpinRisky 4708429a`, `SliceRisky dba7dd53`, `FlatRisky 8c2d5a8e`) and ids (`LobRisky de481349`, `*RiskyFinesse`) are selected by data not yet decoded (9).

### 6.3 Serve
* **Classic serve**: A/B/X each drive two outputs: `Serve/Classic/@Throw<Flat|TopSpin|Slice>` while the button is held (toss) and `Serve/Classic/@<Flat|TopSpin|Slice>` on **release**; the serve id selects `ServeNormal/ServeSlice` rows (190 flat, 150 kick, 140 slice km/h; shot-templates.md). Tier flags `IsMedium`/`IsPowerful` modify the leaf (three serve leaves per type, 4.1).
* **Advanced serve**: right stick only: `Serve/Advanced/CartesianStick/@X,@Y` (range +-10) and `Serve/Advanced/PolarStick/@Power,@Angle`; leaves `fa212c96` (TopSpin), `c1e2aa62` (Slice), `a010111f` (Flat) and the `ServeAdvanced` rows (3 rows: 150/140/190).
* Serve timing/amplitude/precision thresholds: data (`State.bin` labels `Serve`: `MinSpeed Hit`, `MaxSpeed Hit`, `Amplitude`, `Precision`).

### 6.4 Timing window
There is **no button-timing window constant in code**. What code does: `S+0xCF8 = (frame of the swing request) - (opponent's last hit frame)` (`fn_8866B8C0`); the swing candidate commit (gp2) uses reach/timing slack in ticks from data; the grade Good/Medium/Bad is rolled from an analyser (gp2 6.4); the five-level grade factor is 0/.25/.5/.75/1 (`fn_8865AC08`, gp8). Any "perfect timing" window is in analyser data keyed to the debug names `Timing`, `PrepaPrecision`, `ReleasePrecision`, `SuccessFactor`.

## 7. Thresholds: code constants vs data

| quantity | value | where | kind |
|---|---|---|---|
| trigger "down" level (LT/RT -> Risk, `Buttons/@LT|@RT`) | `value > 0x80` (129..255 of 255) | `fn_8890DB90 +0x34..+0x44` (`subfic r11,r9,0x80`) | **code constant** |
| other buttons "down" | `value != 0` | `fn_8890DB90` | code constant |
| trigger edge (press/release events) | press at `>= 1`, release at `<= 0` | `fn_886096C0` (records `+0x60..+0x6B`) | code constant (per-record, resettable) |
| stick dead zone | 0.4 (all three channels) | `Settings.bin` 0x2C498, 0x2C4B0, 0x2C4C8 (float at channel entry +0x14) | **data** |
| stick scales | Aiming/Move 1.0; D-pad (`Stick_1`) 25.0; right stick `Stick_3` 25.0; advanced serve 10.0; polar angle +-pi | `Settings.bin` items | **data** |
| D-pad direction bools | 0.5 | `Settings.bin` (`a31497b5` items) | data |
| stick smoothing ints | 1/30, 10/30 | `Settings.bin` items | data (meaning L) |
| shot-button priority | Flat > TopSpin > Slice > Lob | `fn_88679C78` | code |
| tier test | 0.5 on `S+0x7BC/0x7C0/0x7C4` | `fn_886B3CF8` (`lbl_8814B910`) | code constant on data-produced floats |
| stick "used" | intensity `S+0x440 > 0.2` | `pool +0x10C`, gp2 | code constant |
| Medium/Powerful hold times, Risky selection, Perfect-timing window | unknown | analyser/shot-record data | **data, undecoded** |

## 8. Key addresses

| address | role |
|---|---|
| `0x880D7608` | CInputMapper vtable (Update `[2]` `0x88910F50`, Init `[4]` `0x889117B8`, Exit `[5]` `0x8890FEB0`) |
| `fn_88910F50` | mapper Update (0x714): sticks, calls `fn_8890DB90` for buttons |
| `fn_8890DB90` | button item update (level threshold 0x80 for slots 6/7, edge bits 0x40/0x80) |
| `fn_8890D5F0` | axis reader (ids 0..7, synthetic 6/7) |
| `fn_8890DCC8` | pick the 0xC4 pad record of each player slot (`lbl_88D45B1C+0x234`) |
| `fn_88910038` (0xCB4), `fn_88910CF0` (0x260), `fn_88911668` | config loader (typed `0xFD0DA8E3`), per-player records, reload |
| `fn_888854B0` (0x370) | Xenon pad driver: XInput -> 0xC4 record |
| `fn_886095B8`, `fn_886094C8`, `fn_886096C0` | button edge update, axis update, record reset (thresholds) |
| `fn_88679C78` | ShotInputLatch (vtable `0x880F43E8` slot 1), `fn_886799D0` reset |
| `fn_88687528` | per-frame input latch update (`PC+0x3C/0x3D`, `S+0x4D8` risk, smash id) |
| `fn_8868F178` | Raised shot -> Request flags `S+0x400..0x40B`, shot id `PC+0x3C` |
| `fn_8866B8C0` | writes `S+0xCF8` (frames since the opponent's hit) |
| `fn_88698538` | begin shot request (human) |
| `fn_886B3CF8` | hashed swing-request state machine (human input flags, tier tests, auto swing) |
| `fn_886A84C0 +0x730` | swing-state enter: builds the button-hash event (A/B/X/Y) for the animation controller (`fn_8826CF98`) |
| `fn_8869C010` | aim vector/angle/depth from the stick |
| `fn_886AE528`, `fn_886B0490`, `fn_886AFC78`, `fn_886B1608` | swing planner and its callers |
| `Settings.bin` 0x2C110 | InputMapper config root (buttons 0x2C150, channels 0x2C484) |
| `Settings.bin` 0xD44 | shot-selection decision tree root (to 0x137C; template rows follow) |
| `Settings.bin` 0x42C1C..0x4327D | path string pool |

## 9. Still unknown (ordered by value for the tuning link)

1. **Risky shot selection.** The decision tree never returns `*Risky` ids; Risk only gives the drop shot. Candidates: the analyser that produces `S+0x405..0x408`, the shot record chosen from the id (`PC+0xB0`), or the animation-class lookup (`S+0x70C`, gp3 hash sets `4708429a ...`). Needs the writer of `PC+0xB0` / the shot-record table.
2. **Medium/Powerful thresholds**: hold times and the exact meaning of `S+0x5DD/0x5DF/0x5D9/0x5DE` and floats `S+0x7BC/0x7C0/0x7C4`. They are analyser outputs; the graphs are in `Expressions.bin` (`fa94f637`) and `Settings.bin` (the stack of per-shot entries at `0x2C71C` and `0x2C990`, keyed Slice/Flat/TopSpin/Lob with float pairs 30/90/150/200/270/340/360, probably angle sectors or frame windows, **unverified**). The format of the graph file entries is only partly known (stats-swing-clipfit.md section 2).
3. **PlayerState schema**: the attribute name -> byte offset mapping (only the offsets proven above, by their consumers, are used). The schema is the node stream in `Settings.bin` from 0x44100 (names appear as crc32 hashes: `Buttons 8ce1bc2a`, `ShotTriggers c51ec0b8`, `Shots 86d78d83`, `Shot 0b352785`, `Raise 79a7b49d`, `Id 2abd43f2`, `Classic 7c521831`); not decoded.
4. Whether `Shots/Shot[@Id]/@Raise` (release edge) or `ShotTriggers/.../@Raise` (level) is what the planner calls the shot request: the latch uses the level flags and detects the release itself (`+0xCE`); the `Shots` list is read by `fn_8868F178` as the "which shot was raised" record.
5. Serve flow (toss/hit timing) and which analyser grades serve timing (`Serve` labels in `State.bin`).
6. Meaning of `S+0x4D9/0x4DA` (shot-request event flags) and of `S+0x474..0x477`; whether `@AskNext/@AskPrevious` (LT/RT press edges) matter in matches.
7. `ModeBaseLine` source (`Context/ShotContext`), set by the context code (`fn_8866DF60` sets `S+0x394` Volley/Baseline, gp8 table, M).
8. The two int fields of stick items (1/30, 10/30) and the `0.55/0.8` floats in the config root.

## 10. Reproduction

* Disc extraction: `python3 tools/ts4_arc.py orig/54540859/disc/Core.arc --extract 334e7e0d --out <scratch>` (same for `623d0979`, `fa94f637`).
* Config decode: read `Settings.bin` big-endian; root `0x2C110`; for button entry `e = 0x2C150 + 0x10*i`: items at `e + rel(e)`, count `u32(e+4)`, key `u32(e+12)`; item `{rel,type}` -> record at `item + rel`; paths are `rel` fields (`field + rel` -> NUL string). Channels at `0x2C11C + rel`, stride 0x18.
* Tree decode: scan `Settings.bin` 0xD00..0x1380 for `00000018 00000002 00000002 <crc32(IsX)>`; children at `node+0x18`, 8 bytes each; leaf type `2c3f7780`, node type `48bfc8b8`. Leaf names: crc32 of `{Flat,TopSpin,Slice,Lob}{Finesse,Medium,Powerful,Risky,RiskyFinesse}` and `TopSpinVolley`.
* Code: `TS4_MATCHING_DIR=work/matching-b9 python3 tools/fn_asm.py fn_88910F50 fn_8890DB90 fn_88679C78 fn_8868F178 fn_886B3CF8 fn_8869C010 fn_8866B8C0`.
* Hash helper: `python3 -c "import zlib;print(hex(zlib.crc32(b'IsRisk')))"` gives `0xdf97c57b`.
