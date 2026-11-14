# Shot request to template row, and what scales the launch (family GPB, tuning links 2 and 3)

Module `Swing_DLL.xex` (PE image `orig/54540859/Swing_DLL.dll`, sha256 `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9`),
disassembly with `tools/fn_asm.py` / `work/ppcdis/target/release/ppcdis` (`TS4_MATCHING_DIR=work/matching-b9`). Data: `Core.arc` (sha256
`7df7bfd575150e9ff3b3a171bada368e8bb4d6676ef82505f46961da0aefbf50`) entries `Settings.bin` (`334e7e0d`, 286,492 B) and `State.bin` (`623d0979`), extracted with
`python3 tools/ts4_arc.py orig/54540859/disc/Core.arc --extract <hash> --out <dir>`. Names are zlib crc32 of ASCII. Confidence: **H** read in code or data and
cross-checked, **M** read but not validated, **L** guess, **U** unknown. No game data is copied here except hashes, offsets and a few tuning numbers.

## 0. Headline

1. **Row selection is a data decision tree**, not code. `Settings.bin` file `0x24` holds the root `{rel, type 0x48BFC8B8}`; 33 branch nodes (file `0xD44..0x137C`) test
   named booleans (`IsTopSpin`, `IsMedium`, ...) and 34 leaves name a row by its **unique id** (`row+0x88`). Code is only the walker (`fn_8865A938`) (H).
2. **Why rows repeat**: one row per leaf of the tree. The repeats are the **power tiers** (Finesse / Medium / Powerful = rows 0..3 / 4..7 / 8..11) and, for serves,
   **three leaves per serve kind** (`IsMedium` / `IsPowerful` / neither). Lobs repeat 4+2 times (3 tiers + volley-less, plus two "Wood" lobs). No per-player-level or surface key exists (H).
3. **Risky rows (12..15) are not reachable from the tree**, and no code path names their ids (section 5). They are dead or reached only by a debug override (H for "not in tree", M for "dead").
4. **No stat multiplies the template speed in code.** The commanded speed is the row curve (km/h, data). Stats can only act through analyser graph outputs
   bound to PlayerState floats (`S+0x774` spin blend, `S+0x778` secondary weight f4C, power `S+0xE00`, error floats `S+0x718/0x564`...), whose graph content is not decoded (section 7).
5. The command fields are written by the planner `fn_886B0490` from the ball scratch state (section 6): tau/tick are the **probe results saved at ball+0x1A0/0x1A4**, `+0x54` speed is
   `ball+0x370` which is only meaningful for Net/Let outcomes, `+0x360` is the selected row offset, `+0x364` / `+0x4C` come from `S+0x774` / `S+0x778`.

## 1. Where the table and root live (H)

* **cfg** = `*(*(inst+0x1C)+0x6C)` = the `Settings.bin` root typed struct at **file offset 0x24** (not 0x14/0x20). Evidence: `fn_886715A0` reads `cfg+4` (type 0x48BFC8B8) and
  `cfg+0xC` (count 37) = file `0x28` / `0x30`; cfg+0x134/+0x138 (the `S+0x750/0x754` Net/Let aim heights, gp8) = file `0x158/0x15C` = **80.0 / 90.0 cm** (sensible), and cfg+0xC70/0xC74 = **0.4 / 0.7**.
* Template array: `cfg+8 {rel 0x1350, count 37, cap 37}` -> file `0x137C`, row stride 0x8C. **`ball+0x360` = row file offset - 0x24** = `0x1358 + 0x8C*i` (launch: `tpl = cfg + off + 0x18`, `fn_889C19F0`). So the numbers the planner stores are 0x1358, 0x13E4, ... 0x2708.
* Row ids (`row+0x88`, unique; name hash at `+4` repeats): rows 0..3 `8dc6b132 f74ecf4f b0043514 3bbfdfcc`; 4..7 `a413297b 4637fcf0 be02d81e bb50ea44`; 8..11 `4b121fa5 65dc9a5a 992258dc 11a1b9d0`;
  12..15 `4708429a dba7dd53 8c2d5a8e de481349`; 16..19 `14d5efaa f6f13a21 8ff66130 0ec41ecf`; serves 20..31 `b31b5ee0 17c6bfe3 ea0cf389 5f8e74c3 72d4edc1 488717d1 6bbc9a88 26eb8042 a9bdbd27 fa212c96 c1e2aa62 a010111f`;
  32 `c47dfdc1`; 33 `e8b7486e`; 34 `43961ee3`; 35 `9cafb633` (= the ball-mode hash **Wood**); 36 `4fa695a1`. Leaf lookup is exact id match (`fn_8826D8E0` compares `row+0x88`, `fn_88272088` returns `row+0x88`) (H).
  `input-to-shot.md` names the ids `{TopSpin,Slice,Flat,Lob}{Finesse,Medium,Powerful,Risky,RiskyFinesse}`; the row *names* in `templates.py` are the template family, not the tier.

## 2. Runtime objects (H unless noted)

| address | role |
|---|---|
| `fn_886715A0` (selector init) | `this+0x14` = controller, `this+0x18` = cfg; resizes vector `this+8` to `cfg+0xC` = 37 entries of 0x14 bytes; `fn_8865A9C8(this, cfg root elem, &n)` numbers the tree nodes in **pre-order, child 0 (true) first** and stores the number in `node+0x14`; `this+4` = node count; then `fn_88662390(entry_i, row_i, ctrl+0x6C)` for i in file order (entry i is row i) |
| `fn_88662390` (entry init) | `entry+4 = row`; `entry+8 =` object of class `0x9BD3657E`; `entry+0xC = X` = object created from the **row's first word 0x85B71A2B** (class vtable `0x880F4808`, 0x14 bytes, gp0 table); calls `X.vtbl[2](X,row,ctrl)`; `entry+0x10 = row+0x14+rel` (aux float block) when `row+0x14 != -1` |
| controller `+0xA0` | pointer to an array of **condition objects**, one per tree node (index = pre-order number, first byte of the object = 0/1) |
| controller `+0xB0` ("B") | the **currently selected entry**; `B+4` = row pointer, `B+0xC` = X (vcalls: slot `+0x10` = aim/target for the planner, `+0x18`, `+0x20`) |
| `fn_8865ED78` | refresh of B: if `inst->0x28 (+0xF57) != 0 && (+0x844) == 0` (a **debug override**) pick the entry whose `row+0x88 == inst->0x28+0x840`; else `B = fn_8865A938(vec, tree root, &controller+0xA0)`. Called after every request change (many callers) |
| `fn_8865A938` | walk: node `{rel to children, count 2, cap 2, cond-id crc32, rel to path string, node-index}`; condition byte `== 1` -> child 0 else child 1 (child = 8-byte `{rel,type}`, type 0x48BFC8B8 = node, else leaf `{id, row index}` where the row index was filled by the init pass); result = `vec[row_index]` |
| `fn_886B0490` / `fn_886AE528` | planner; `S+0x6E0 = (B+4)->+0x88` (id of the chosen row, `fn_886B0490 +0x4E4`) and `ball+0x360 = (B+4) - cfg` (`fn_886AE528 +0x798`) |

The condition **id is crc32 of the attribute name** (`hashA = crc32("IsTopSpin") = f271f3c8`, etc., all 12 verified), while the string in the node is the XData path
(`ShotSelection/Request/@IsTopSpin`, strings at file `0x42C1C..0x42DA7`; the base-line one is `Context/ShotContext/@ModeBaseLine` but keyed `IsBaseLine 82747a4b`).

## 3. The tree (decoded from `Settings.bin`; T = true child, F = false child) (H)

```
IsWoodDown                 T: row 36 (LobNormal, DropTime curve over 100..600 cm = 0.2 s, id 4fa695a1)
 F IsWood                  T: row 35 (LobNormal, DropTime 2.6 s, id 9cafb633 = ball mode Wood)
  F IsClassicServe         T: SERVE-CLASSIC   F: next
   F IsAdvancedServe       T: SERVE-ADVANCED  F: next
    F IsSmash              T: row 33 SmashNormal
     F IsBaseLine          T: BASELINE        F: VOLLEY

SERVE-CLASSIC : IsTopSpin -> kick ServeNormal 150 km/h : IsMedium row 20 | IsPowerful row 21 | else row 22
                else IsSlice -> ServeSlice 140 km/h   : IsMedium row 23 | IsPowerful row 24 | else row 25
                else flat ServeNormal 190 km/h        : IsMedium row 26 | IsPowerful row 27 | else row 28
SERVE-ADVANCED: IsTopSpin row 29 (150) | IsSlice row 30 (140) | else row 31 (190)        (no tier flags)
BASELINE      : IsPowerful -> [IsTopSpin row 8 | IsSlice -> (IsRisk row 32 DropShot | row 9) | IsLob row 11 | else row 10]
                else IsMedium -> [IsTopSpin row 4 | IsSlice -> (IsRisk row 32 | row 5) | IsLob row 7 | else row 6]
                else (Finesse) -> [IsTopSpin row 0 | IsSlice -> (IsRisk row 32 | row 1) | IsLob row 3 | else row 2]
VOLLEY        : IsTopSpin row 16 PowerVolley | IsSlice -> (IsRisk row 18 DropVolley | row 17 SliceVolley) | else row 19 FlatVolley   (Lob button gives FlatVolley)
```
Not reachable from the tree: rows 12..15 (Risky), row 34 (DefensiveShot). Flat has no flag: it is the fall-through of the stroke test.
Per stroke the tier changes (km/h initial speed at 5..30 m, secondary offset, T): Flat 120 / 130 / 140, TopSpin 80 / 80 / 90, Slice 70 / 80 / 80, Lob (DropTime s) 1.40 / 1.45 / 1.25; the Powerful group also narrows the spin curve
x range to 0.8..1.2 (launch height m) and has smaller Apogee offsets (Flat 1.0 m vs 1.5/1.55). The three serve rows of one kind differ only in `lo` spin and the junk-looking aux block: rows 20/21 are byte-identical in values, row 22 has `spin_a lo = -0.2` (vs -0.05).

Who sets the request booleans: the input agent's note (`input-to-shot.md`) gives `fn_8868F178` (Flat/TopSpin/Slice/Lob/Smash/Risk bytes `S+0x400..0x40B`) and the tier bytes `S+0x405/0x406` copied from analyser bytes `S+0x3A8/0x3A9` (`fn_886783E8`). Tier thresholds: code
tests `S+0xE00 > cfg+0xC74 (0.7)` for the "powerful" flag of the incoming-ball descriptor (`fn_886B5128 +0xC10`, bytes `info+0x3F` is also set from membership of the **Powerful ids** `992258dc 65dc9a5a 4b121fa5 11a1b9d0`, `info+0x3E` = Finesse ids, `info+0x3D` = Risky ids);
`cfg+0xC70 = 0.4` is the adjacent value (M: Medium threshold). Whether the request flags `IsMedium/IsPowerful` use exactly these thresholds is **M/L**.

## 4. Why Normal/Lob/ServeNormal repeat (answer)

* Normal x2 = Medium and Powerful (rows 4..7, 8..11); Finesse = rows 0..3 (the "base" hash `row+0x0C` of SliceFinesse/FlatFinesse points to the Normal row, M role).
* Lob x6: LobFinesse (3), LobMedium (7), LobPowerful (11), LobRisky (15, unreachable) and two Wood lobs (35 = id Wood 2.6 s, 36 = IsWoodDown 0.2 s over 1..6 m). Lob has no tier flag in volley mode.
* ServeNormal x6 = {kick 150 km/h, flat 190 km/h} x {3 tier leaves}; ServeSlice x3 = 140 km/h x 3 tier leaves; ServeAdvanced x3 = one leaf per kick/slice/flat, no tiers.
* Serve vs return vs rally: serves are chosen by `IsClassicServe`/`IsAdvancedServe`; there is **no separate return row** (a return is a baseline stroke; `FlatReturn` is only the row *group* hash on the four Flat rows and a key in the aim table); first vs second serve is not in the tree
  (it is the kick/slice/flat input, section 4 of input-to-shot.md). Volley/smash/baseline use `IsBaseLine`/`IsSmash` (gp2's per-sample candidate type is separate and only feeds reach/selection).
* Aim tables keyed by template **name**: `cfg` vectors at file `0x120` (15 entries, 0x70 bytes: per-stroke pairs of aim distances in cm, e.g. Flat 800/300..350/140..150) and `0x12C` (25 entries, 0xA0 bytes: `300, 1300, 350|550` plus 4 x,z aim-point lists; serve entries hold (x~485..535, z~145..180) cm service-box targets). Used by `X` (class 85B71A2B) for the landing target; meanings of individual numbers M/L.

## 5. Risky rows and IsRisk (priority question)

Facts (H): (a) no tree leaf has ids `4708429a dba7dd53 8c2d5a8e de481349` (TopSpinRisky / SliceRisky / FlatRisky / LobRisky) nor the four ids `ef50cf09 5f04e79c 3b293e51 2a12fbe4` (RiskyFinesse, no rows exist for them, two appear only as keys in the 25-entry aim table); (b) the 8-id "risky" set is compared in code only for statistics
(`fn_88666288 +0x130`: `S+0x70C` in set -> team counter `+0x88`; `fn_886B5128`: `info+0x3D`), never to pick a row; (c) leaf -> row is an exact `row+0x88` match, no fuzzy or base-hash fallback; (d) the only other code that sets B is the debug id override in `fn_8865ED78`; (e) `S+0x70C` has no literal writer except an integer counter in a net-sync copy (`fn_887CF7xx`), so the id-in-`S+0x70C` statistic is itself fed by data/binding.
`IsRisk` (`S+0x404` = `S+0x4D8` = LT/RT, per input-to-shot.md) changes the row **only** for Slice (DropShot / DropVolley). Elsewhere it is copied into the command byte `C+0x9B` -> `S+0x404` (`fn_886B0490 +0x5A0`), counted (`team+0x3C4`), and reaches analyser graphs as a port (U). No code multiplies speed, spin or error by it.
Conclusion: in this build the Risky template rows are **not selectable through the shipped tree**; the ids exist in the stats set, so either a build-time feature was removed from the tree, or a graph/analyser overrides `S+0x6E0`/the entry through bindings (U). To test: edit the tree (swap a leaf id to `4708429a`) and run under Xenia.
Retune hint: editing leaf ids (4 bytes each at file `0xD..` leaf records) re-points any request to any row without code changes; the row index is resolved at init by id.

## 6. Command fields (gp4b table, now located) (H)

All stores are in `fn_886B0490 +0x3F8..+0x4A0` (`0x886B085C..0x886B08CC`), destination = command `C` (`this+0x88`), source ball = `this->0x48->0x5C->0x20` (scratch ball, 0x540 B):

| C field | source | meaning |
|---|---|---|
| `+0x40` tau | `ball+0x1A0` | **saved probe state**: after the probe `fn_889C2678` the planner (`fn_886AE528 +0xF9C..0xFC4`, also `fn_886AD758`) swaps: `memcpy(tmp, ball, 0x1A0); ball <- ball+0x1A0; ball+0x1A0 <- tmp`, so `ball+0x1A0` holds the probed `ball+0x00` = tau (quantised: n/60 by repeated addition) |
| `+0x44` bounce tick | `ball+0x1A4` | = `ball+0x04` of the probe = floor(tau*60) (u32) |
| `+0x48` row offset | `ball+0x360` | `(B+4) - cfg` (written `fn_886AE528 +0x798`) |
| `+0x4C` f4C | planner record `rec+0x30` = `S+0x778` (`fn_886AE528 +0x594`) | -> `ball+0x430` -> `ball+0x0C`; secondary weight `w = clamp01(1 - f4C)` |
| `+0x50` spin blend | `rec+0x34` = `S+0x774` (`+0x5A4`) | -> `ball+0x364` -> `ball+0x10` |
| `+0x54` speed km/h | `ball+0x370` | **only written for Net/Let outcomes**: `fn_886AE528 +0xBA0`: `ball+0x370 = ball+0x3CC` (the previous probe's initial speed), `planned = 0`. For In/Out shots the planner never stores it, the launch (`fn_889C19F0`) never reads it (the speed is the row curve), so for normal shots it is stale and unused (M for the stale value) |
| `+0x58` sidespin sign | `ball+0x368` | `1` when hitter is left-handed and match state is `0x029EAAF4`... exactly `(match->0x318 == 0x029EAAF4) && (match0x28->+0xC == 0xDA554856 "Left")` (`+0x848`), else 0 |
| `+0x30/34/38/3C`, `+0x70` | `ball+0x494..0x4A0`, `ball+0x210` | net-cord params, origin (unchanged) |
| `+0x80` mode, `+0x84` | planner mode record `rec+0x38/0x3C` | In / Out / Net / Let (gp4b s10) |

`ball+0x369 planned = 1` is set for In/Out (the template path), `0` for Net/Let (probe of commanded speed). The Net/Let aim heights are `cfg+0x134/+0x138` = 80 / 90 cm (`S+0x750/0x754`).

## 7. Speed, spin and power scaling: what is code, what is data

**Code (H):**
* Initial speed = `node0` of the row evaluated by `fn_888AB6C8` at horizontal distance d (cm, 500..3000 in every row; constant curves here). `InitialSpeed` rows: tau is solved so that `|v0|` equals the curve value; `DropTime` rows: tau = curve value (s) (+ raise for net clearance); secondary stage `tauA + w*(tauB - tauA)` with `w = clamp01(1 - f4C)` (gp4b s5). **No term contains a player stat, charge, grade or coach bonus.**
* Net clearance raise uses ball radius + net height; the landing point comes from the target (`fn_886935A0`/`fn_88693040`, aim tables above, S+0xD20 block, stick `S+0x764/0x7A8`); error/Out/Net/Let by `fn_886807C0` (gp4b s10, probabilities `S+0x718/0x71C/0x720/0x564` from graphs).
* **Charge / power**: `fn_8869D720`: `S+0xDFC = frame - start` (`fn_886B0490 +0x1A4`), `S+0xE00 = curve16(cfg+0x914 or +0x8FC)(S+0xDFC / *(flagblock+0x44) )` (the 0x914 curve when `fn_8868F0D8(0x82E4BF1A)` is true, else 0x8FC), and `S+0xE08 = curve16(cfg+0x920 or +0x908)(S+0xE04 / same)`. Data: curves at cfg `0x8FC/0x914` = x 0..1.25 -> y 0..1 (i.e. `power = frac/1.25`), `0x908` = identity 0..1, `0x920` = 0..0.9 -> 0..1. Then `S+0xE00` is capped with `S+0x58` through a pool compare/fsel (`fn_886B0490 +0x1E8..`). Power is a 0..1 float that feeds graphs and the tier decision, **never the ball speed directly**.
* Skill stat: `S+0x74C` (current-stroke skill: Forehand/Backhand/Volley/Return/Serve from the stat block `S+0x64C..0x668`, stats-swing-clipfit.md s1.3) is only an analyser input.

**Data / graph outputs (U for content):**
* `S+0x774` (spin blend, 0..1: `spin = lo + (hi - lo)*blend`, `lo` = 0 for strokes so blend 0 = **no spin**) and `S+0x778` (f4C) have **no literal store** except resets (`fn_88672690 +0x18: S+0x778 = 0.0` with power `S+0xE00` and `S+0x66C`); they are bound outputs of analyser graphs (`fa94f637.bin`, 341 graphs; binding mechanism gp8 s3). The decode of port->field-offset (the stride-0x40 type-0x2F68067A table is not located, State.bin `0x42390` lists the offsets 0x718/0x720/0x774/0x784.. as the port order) is the next step. Evidence that they are per-shot analyser results: the planner copies them into the record next to power (`fn_88686628`: shot-history record stores `S+0x3C` type, `S+0xE00` power, `S+0x778`).
* Therefore the real distribution of f4C and of the spin blend (and any stat/timing/coach dependence) is undecoded. If f4C stays 0, every shot gets the full secondary stage (apex target offsets 0.5..1.75 m); shot-templates.md s5 shows that this changes speeds by 20-30%.
* The match-history integers at `0x38(P)+0x760..0x78C` (10-slot shift register, `fn_88697890`) are unrelated (same offsets on a different object).

## 8. Retuning consequences

* Re-point or add tiers: edit leaf ids (and the rows) in `Settings.bin` `0xD44..0x137C`; add rows (the entry vector size is `cfg+0xC`, aim table 25 entries must have the name).
* Speed per tier/stroke: row node0 (curve20 `y0`), secondary node1, T, spin hi/lo, bounce curves (shot-templates.md). Per-stat scaling would need the analyser graphs (spin blend, f4C) or new code.
* Tier thresholds: `cfg+0xC70/0xC74` (0.4/0.7) and power curves `cfg+0x8FC..0x920`; the 0.5 test on `S+0x7BC/7C0/7C4` is code.

## 9. Not found / next steps

1. Producer of the Request booleans `IsMedium/IsPowerful/IsWood*/IsClassicServe/IsAdvancedServe` (analyser outputs; `fn_886783E8` copies bytes `S+0x3A8/0x3A9` into `S+0x405/0x406`).
2. Content of the analyser graphs that write `S+0x774/0x778/0x7BC..`; stat -> graph inputs.
3. Selection of the Risky rows (if any) and effect of `IsRisk` on error graphs; row 34 DefensiveShot (no leaf, no code reference found).
4. Exact meaning of the aux float blocks `row+0x10/+0x14` (read by X.init `fn_88662738` into `X+0x38..0x4C`).
5. `cfg` offset convention (file `0x24`) validated by two data coincidences and the init code, not by a runtime dump.

## 10. Reproduction

* Tree walk: read big-endian; element at file `0x24` `{rel,type}`; node fields `rel@0, count@4, crc@0xC, path rel@0x10, index@0x14`, children at `node+rel` (8 bytes each); leaf id = first word; compare with `row+0x88` of rows at `0x137C + 0x8C*i`. Condition names: `python3 -c "import zlib;print(hex(zlib.crc32(b'IsTopSpin')))"` -> `0xf271f3c8`.
* Code: `TS4_MATCHING_DIR=work/matching-b9 python3 tools/fn_asm.py fn_886AE528 fn_886B0490 fn_886AD758` ; raw ranges `ppcdis 8865A938`, `8865ED78`, `886715A0`, `88662390`, `8869D720`, `8826D8E0`.
