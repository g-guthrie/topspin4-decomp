# Title Update #1: what it changes in gameplay

This note compares the retail disc with Title Update #1 (TU1) for title `54540859`. It covers every
gameplay data file and the patched gameplay code. The machine-readable diff is
`data/gameplay/tu_diff.yaml`. Raw game files stay under ignored `orig/` and `work/`.

## Summary

- **TU1 is the April 2011 "Player Balancing Update" plus the May 2011 fixes.** Its data changes are
  exactly the April notes:
  - power serves and advanced serves are tuned (four graphs);
  - Serve Stick Berserker, Focus Service and Drop Shot Artist are tuned (three graph constants and
    one curve);
  - D-pad movement is enabled, by a data change in the pad mapping.
- **None of the six September 2011 changes is in TU1.** No graph or table for fatigue, speed,
  returns, defensive slice or flat, drop-shot depth, or "good situations" changed. The September
  patch must have reached players by the title-server data path (`Media\Patch\...`, see
  `docs/title-server-patch.md`). That payload is not recovered.
- **TU1 code adds two new analyser inputs that no TU1 graph reads.** These are
  `ShotContext.IsForehand` and `ShotContext.IsSecondServe`. A later data patch could read them
  without a new executable.
- **What the patched game runs.** The patched game loads TU1's `Layoutall.bin`, and TU1 mounts
  `TitleUpdate.arc` in the same archive loader as `Core.arc`. So the TU copies of `Settings.bin`,
  `State.bin`, `Module.bin`, `Expressions.bin`, `GameplayInterface.bin` and `PlayerEvolution.bin`
  replace the disc copies (section 2). `tools/ts4data/dump_tunables.py --tu` dumps that patched
  state.

## 1. Inputs and reproduction

| item | bytes | SHA-256 |
|---|---:|---|
| TU package (STFS `LIVE`) | 2,510,848 | `892738e0cdad221c8049ba5480ec3616e4f0cf94aca8ca44935f07c4745abce4` |
| `TitleUpdate.arc` (56 members) | 555,570 | `729235a9576bb403a8a7b8af23cc61327590c693e041d24cc9bac7407b70ce26` |
| TU `Layoutall.bin` | 761,068 | `d734143df252477b5a41d77d1a8d3839570cefbe9cdb783e2600dfe04ef502a0` |
| disc `Layoutall.bin` | 760,816 | `67793f5b7dc771f8fde298ef07e8976d9362c864ac577a4c9db6b2bf874788c5` |
| TU `Swing_DLL.xexp` | 862,208 | `d5837ef967415ecd77547f3434cf8973f025be8cb45e398ff7eecfd68a0726ed` |
| base `Swing_DLL.xex` | 5,083,136 | `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44` |
| Swing image, base / patched | 14,483,456 | `7b92548a…5c4b936` / `b3ea7d4d…2b9f5a3` |

Commands. Python 3.13.18; `cryptography` 50.0.1 is used only for AES. The retail XEX key is read at
run time from the local jeff checkout and is not stored in this repository.

```sh
python3 tools/stfs.py extract orig/54540859/tu1/package.bin orig/54540859/tu1/files   # see additional-content.md
python3 tools/ts4data/arc.py list orig/54540859/tu1/files/TitleUpdate.arc
python3 tools/xex_patch.py orig/54540859/Swing_DLL.xex orig/54540859/tu1/files/Swing_DLL.xexp \
    --out work/tu1/Swing_DLL.tu1.image --base-out work/tu1/Swing_DLL.base.image \
    --functions work/tu1/swing_functions.json        # ~15 s; every patch block is SHA-1 checked
python3 tools/ts4data/tu_diff.py --functions work/tu1/swing_functions.json   # -> data/gameplay/tu_diff.yaml
python3 tools/ts4data/dump_tunables.py --cache work/disc/cache --tu orig/54540859/tu1/files --out work/tu1/tunables
python3 tools/ts4_analyser.py work/disc/tu1_arc/fa94f637.bin --dump-readable work/tu1/graphs_tu.yaml \
    --state work/disc/tu1_arc/623d0979.bin --layout orig/54540859/tu1/files/Layoutall.bin \
    --settings work/disc/tu1_arc/334e7e0d.bin
```

`tu_diff.py` walks each disc file with the disc layout and each TU file with the TU layout. A member
that only moved because a type grew is therefore not reported as a value change.

## 2. What is in TitleUpdate.arc, and what the patched game uses

| member | status vs disc | gameplay? |
|---|---|---|
| `Settings.bin` (Core.arc `334E7E0D`) | 3 values (section 3.3) and layout signature | yes |
| `State.bin` (`623D0979`) | +64 bytes: two new ShotContext floats per player (0.0) | yes |
| `Expressions.bin` (`FA94F637`) | 7 graphs (section 3) | yes |
| `Module.bin` (`44DC9505`) | layout signature word only | no value change |
| `GameplayInterface.bin` (`F26CDC20`) | byte-identical | no |
| `PlayerEvolution.bin` (venue `E38F72F1`) | two new root booleans, both `true` | career |
| `NetDB.bin`, `UnlockTrigger.bin`, `CreditsList.bin`, `PostReleaseDataMining.bin` | changed | no |
| 38 UI `.scene`/`.actions`/`.sceneData` members, 7 new small UI members | changed or new | no |

- **Signature word.** Word 0 of an XBin file is a layout-version hash of its root type. It changes
  whenever any nested type layout changes:
  - root `D2968089`: `0x181AEDEE` on the disc, `0x1FAAB488` in TU1;
  - `PlayerEvolution`: `0xCF49B9CC` on the disc, `0x50F71691` in TU1.
  TU1 ships every file whose signature changed, including `Module.bin`, which has no value change.
  This fits a loader that requires the file's signature to match the active `Layoutall.bin`
  (inference; the check itself was not located in code).
- **Mounting.** The disc `CoreTech_Xenon.bin` archive loader (`CArchiveLoaderType`, module 39) loads
  `Core.arc, LuaFiles.arc, GlobalMem.arc, Global.arc`. TU1's copy loads
  `Core.arc, LuaFiles.arc, TitleUpdate.arc, GlobalMem.arc, Global.arc`. TU1 also puts the updateable
  compressed file system (`0x839C9578`) first in the localization lookup list. The executable
  already names `UPDATE:\Layoutall.bin` and `UPDATE:\CoreTech_Xenon.bin`.
- **Conclusion.** The patched game uses the TU members listed above, the TU `Layoutall.bin`, and the
  disc copies of everything else. Confidence: high for intent, because the duplicate keys only make
  sense as overrides. The precise first-match rule was not traced in code.
- **Dumping the patched state.** `dump_tunables.py --tu DIR` dumps this state:
  - TU members replace disc members, and the header says `archive: TitleUpdate.arc`;
  - the TU layout is used for every file;
  - the retail-only code cross-reference comments are dropped.

  `patch_tunables.py --tu DIR --layout DIR/Layoutall.bin` patches such YAML.

## 3. Gameplay changes

Curve keys are `[x0, x1, y0, y1]` ramps (slope fixup `fn_88179740`, see `graphs-decoded.md`).
`vigor` is `PlayerState.Fatigue.Output.CurrentVigor`, where 1 means fresh. Graphs are named by the
`Settings.bin` shot class that runs them (`40dd9ee9/00236a48/EvaluateList[i]`). The class ids were
cracked by crc32: `ServeFlatPowerful` = `DE266211` and `AdvancedServe` = `8C2438F6`.

### 3.1 Serves ("Tuning of Power serves and Advanced serves"; April note)

**Graph 220 `e65d4260`: ServeFlatPowerful, aiming efficiency.** It runs as `EvaluateList[23]`
slot `#3f9c096b` and writes `AimingState.Efficiency`.

| node | disc | TU1 |
|---|---|---|
| `curve3(vigor)` | `[0.5,0.6,-0.4,-0.2] [0.6,0.7,-0.2,-0.1] [0.7,1.0,-0.1,0]` | `[0.5,0.6,-0.4,-0.2] [0.6,0.8,-0.2,-0.1] [0.8,1.0,-0.1,0]` |

- `curve3(vigor)` is added to the Serve-rating term. Their sum is the `t` of
  `lerp(curve2(Random), 0, t)`, so a lower `t` means more random scatter in serve quality.
- TU1 makes the fatigue penalty bite earlier. At vigor 0.75 the penalty is -0.083 on the disc and
  -0.125 in TU1. At 0.80 it is -0.067 and -0.100.
- Effect: big flat serves lose precision sooner as the server tires. Confidence: high for the value
  change and the mapping to the note; medium for the reading of the output.

**Graph 215 `4044f237`: AdvancedServe (right-stick serve), aiming efficiency.** It runs as
`EvaluateList[25]` slot `#3f9c096b`.

| node | role | disc | TU1 |
|---|---|---|---|
| `curve1(Random)` | random deviation added to aim quality | `... [0.5,0.8,0,0.05] [0.8,1.0,0.05,0.1]` | `... [0.5,0.8,0,-0.05] [0.8,1.0,-0.05,-0.1]` |
| `curve5(vigor)` | fatigue penalty | `[0,0.2,-0.5,-0.2] [0.2,0.7,-0.2,-0.1] [0.7,1,-0.1,0]` | `[0.5,0.6,-0.5,-0.2] [0.6,0.8,-0.2,-0.1] [0.8,1,-0.1,0]` |
| `curve8(r0)` | quality to efficiency, Serve 0 | knee at 0.45 | knee at 0.475 |
| `curve9(r0)` | quality to efficiency, Serve 1 | knee at 0.40 | knee at 0.45 |
| const `r33` | `product(skill[FocusService], MatchAnalyser.#689dc6f2, r33)` | 0.1 | **0.05** |
| const `r34` | `product(skill[ServeStickBerserker], curve2(Timing), r34)` | 0.1 | **0.05** |

- On the disc, half of all advanced serves got a random quality bonus of up to +0.1. In TU1 the
  random term is never positive.
- A tired server is hit much harder: at vigor 0.5 the penalty is -0.14 on the disc and -0.5 in TU1;
  at 0.6 it is -0.12 and -0.20.
- More aim quality is needed for the same efficiency.
- The Serve Stick Berserker and Focus Service bonuses are halved (section 3.2).
- Confidence: high.

**Graph 311 `95190005`: AdvancedServe fault probability.** It runs as `EvaluateList[25]`
`Element[1]` and writes `FaultProbability` and `OutEfficiency`.

| node | disc | TU1 |
|---|---|---|
| `curve7(vigor)` | `[0.5,0.6,-0.4,-0.2] [0.6,0.7,-0.2,-0.1] [0.7,1,-0.1,0]` | `[0.6,0.8,-0.4,-0.2] [0.8,0.9,-0.2,-0.1] [0.9,1,-0.1,0]` |

- The fatigue term feeds the timing-to-fault chain for human servers. At vigor 0.8 it is -0.067 on
  the disc and -0.20 in TU1; at 0.7 it is -0.10 and -0.30.
- Effect: tired advanced serves fault more. Confidence: high for the values; medium for the
  direction of the effect on the fault rate.

**Graph 257 `8691de05`: AdvancedServe power factor.** It runs as `EvaluateList[25]` `Element[2]`
and writes `PowerfulFactor`.

| node | disc | TU1 |
|---|---|---|
| `curve3(skill[FocusService] * MatchAnalyser.#689dc6f2)` | `[0,1,0,0.2]` | `[0,1,0,0.05]` |

- Focus Service's boost to advanced-serve power drops from up to +0.2 to +0.05. This answers both
  the advanced-serve note and the Focus Service note. Confidence: high.

### 3.2 Skills ("Tuning of ... Serve Stick Berserker, Drop Shot Artist, Focus Service"; April note)

| skill | where | disc | TU1 | confidence |
|---|---|---|---|---|
| Serve Stick Berserker | graph 215 const `r34` | 0.1 | 0.05 | high |
| Focus Service | graph 215 const `r33` | 0.1 | 0.05 | high |
| Focus Service | graph 257 `curve3` | 0 → 0.2 | 0 → 0.05 | high |
| Drop Shot Artist | graph 331 const `r50` in `product(skill[DropShotArtist], r50)`, subtracted from the drop-shot error input | 0.3 | **0.1** | high |

**Graph 331 `610c6bca`: DropShot fault probability.** It runs as `EvaluateList[30]` `Element[1]`.
Besides the Drop Shot Artist constant above, it has two changes that the notes do not mention.

| node | role | disc | TU1 |
|---|---|---|---|
| `curve10(link SwingCategory/#0698037d)` | penalty for a stretched (reach-swing) drop shot, without ReachSwingsExpert | `[0,1,0,-0.6]` | `[0,1,0,-0.8]` |
| `curve9(...)` | same penalty, with ReachSwingsExpert | `[0,1,0,-0.2]` | `[0,1,0,-0.6]` |
| `curve16(MatchState.#8beb922e)` | error multiplier late in long rallies, with BetterOnLongRallies | falls 1 → 0.25 → 0 over 15..25 | floors at **0.5** from 15 on |

- Drop shots hit on the stretch get worse, and Reach Swings Expert protects much less.
- With Better On Long Rallies, drop-shot faults could fall to zero on the disc after about 20
  rally shots. In TU1 they stay at half or more.
- Confidence: high for the values; medium for the semantics of the qualifier link and of
  `MatchState.#8beb922e` (rally-length counter, inferred from the 0..25 domain).

**Dead graph copies.** Graph 214 `89a37ee0` (a ServeFlatPowerful twin) and graph 222 `e9044451`
(an AdvancedServe twin) are referenced nowhere (`UNREFERENCED_GRAPHS` in `tools/ts4_analyser.py`;
TU1 data and code also have no reference).

- TU1 edits them in a different way from their live twins:
  - 214 gets the random-sign flip, Focus Service 0.1 → 0.05 and a knee move;
  - 222 is re-emitted with its nodes reordered, the new `curve5(vigor)` and the knee moves, but with
    the old positive random term and both skill constants still at 0.1.
- They have no runtime effect unless a data patch points a shot class at them.

### 3.3 D-pad movement ("Directional buttons player control added"; April and May notes)

`Settings.bin` `PaddleSettings/1614457d[0]/898866c8/Axe[0]` is the movement stick:

| field | disc | TU1 |
|---|---|---|
| X channel (`b957fa50`) | `0x681AB601` `X_2` (axis 2 = left stick X) | `0xD47EB74D` (axis 6) |
| Y channel (`b8959067`) | `0x69D8DC36` `Y_2` (axis 3 = left stick Y) | `0x4971563B` (axis 7) |

- The channel-to-axis table is at `0x88C6B7C0` in both executables. It maps `X_1/Y_1` = 0/1
  (D-pad), `X_2/Y_2` = 2/3, `X_3/Y_3` = 4/5, and `D47EB74D/4971563B` = 6/7.
- The pad reader (`fn_8890D468`, axis read at `0x8890D5F0`, unchanged in TU1) returns the D-pad axis
  for ids 6/7 when the D-pad is non-zero, and the left stick otherwise.
  `input-to-shot.md` section 1 says "else right stick". The code reads `+0x84/+0x88` (D-pad), then
  axis 2/3 (left stick).
- So D-pad movement is a pure data change. Confidence: high.

### 3.4 Other TU1 data changes

- **`Settings.bin` new flag.** `47ca727b/29eac4a0` gains a boolean `e26ae391` = `true`. Before it
  are the int 40 and the float 1.0 read by `fn_886795C8`.
  - The disc `fn_886795C8` zeroes three `MoveState` request fields when a timer exceeds 40 and a
    stick component passes a threshold.
  - Its TU1 replacement (`0x88679CD8`) takes a new latched path when the flag is set (new byte
    `this+0x16E`).
  - This is a movement-input rule for the human player. The exact behavior is not decoded, but it
    plausibly belongs with D-pad control. Confidence: low.
- **`PlayerEvolution.bin`.** It gains two root booleans (`dcebbf79`, `218349a5`, both `true`). This
  is possibly the May "career ranking calculation" fix. Confidence: low.
- **`State.bin`.** It gains `ShotContext.IsForehand` and `ShotContext.IsSecondServe` (0.0) for all
  four players.

## 4. September 2011 notes: not in TU1

| September note | where it would show | TU1 |
|---|---|---|
| 1. shots in good situations improved | shot-difficulty and timing graphs (`gp8.md`) | unchanged |
| 2. bad and average drop shots less efficient, land deeper | DropShot depth/efficiency graphs, drop-shot templates | unchanged (graph 331 changes are DSA, reach and long rallies, all April-era) |
| 3. defensive slice weaker, defensive flat stronger | Slice/Flat defensive graphs | unchanged |
| 4. high stamina lasts longer | `FatigueIngame` and stamina graphs | unchanged |
| 5. tired and slow players slower | movement speed tables and graphs | unchanged |
| 6. badly timed returns shorter | return graphs | unchanged |

- Only the seven graphs in section 3 differ in all of `Expressions.bin`, and `Settings.bin` differs
  only as described in sections 3.3 and 3.4.
- Building the patched executable on 2011-04-07 (PE timestamp `0x4D9DF6FF`; retail `0x4D2EE821` is
  2011-01-13) means TU1 cannot contain September work. The XboxUnity TU1 upload is dated 2011-06-08.
- TU1's new code gives a September data patch more to work with:
  - the `IsForehand` and `IsSecondServe` inputs;
  - a refreshed ShotDifficulty input set at shot-evaluation time (section 5).

  This is inference.

## 5. Code: Swing_DLL delta patch

`tools/xex_patch.py` applies the XEX2 delta.

- **Header and session keys.** The 0x5FF descriptor carries an LZX header delta. Applied to the base
  header, it gives the target header. The target session key is
  `AES-ECB-decrypt(retail, target +0x150)`. The patch data key is
  `AES-ECB-decrypt(target session, patch +0x150)`.
- **Blocks.** The image delta is 14 SHA-1-verified blocks and 451 records:
  - type 0: zero-fill;
  - type 1: copy;
  - other types: LZX with the window pre-loaded from the old bytes.
- **Rebuild.** TU1's Swing module is a full relink: source version 3, target version `0x103`,
  `.text` 7,632 bytes larger. Functions were matched through `.pdata`, with branch displacements,
  `lis`-based address halves and in-image address words masked.

| class | count |
|---|---:|
| identical, same order | 33,076 |
| identical, moved by the linker | 288 |
| offsets only (struct layout shifts, mostly PlayerState +0x10 after ShotContext and one object +4) | 404 |
| changed | 95 |
| added / removed | 42 / 24 |

### Gameplay functions with real code changes

Addresses are base → TU.

| base | TU | change | confidence |
|---|---|---|---|
| `fn_88695640` (shot evaluation; PoisonedSlices site) | `0x88695D90` | writes the new `ShotContext.IsSecondServe` (S+0x570) on the serve path (`Context.IsServing`), from the flag byte `+0x99` of the owner's `+0x48 → +0x44` object; writes `ShotContext.IsForehand` (S+0x56C) from player byte `+0x39`; adds a call to `fn_8868E320` (refresh ShotDifficulty inputs for the current ball, `gp8.md` 4.1) | high (writes), medium (sources) |
| `fn_886795C8` | `0x88679CD8` | new Settings-flag path with a latch (section 3.4) | medium |
| `fn_886742F8` | `0x886748F8` | +272 bytes; new calls `fn_88656A78(…, 43)` and `(…, 60)` near the stats code (`rules-and-scoring.md`); likely the May stats fixes | low |
| `fn_8869DEF0` `PlayerCtx_Init` | `0x8869E690` | +200 bytes | not analysed |
| `fn_8868C660`, `fn_886A6098`, `fn_886C1ED8` | `0x8868CDA8`, `0x886A6908`, `0x886C2778` | field resets moved to new members; `fn_886C1ED8` adds a call to new `0x886600B8` | low |
| new `0x886555E8`–`0x88657758`, `0x88668280`, `0x886E4240` | — | added helpers in the gameplay range | not analysed |

The rest is outside gameplay:

- `CPatchManager_*` (serialize, reset, finalize), `CTitleServer_ProcessPatchTransfer`,
  `RegisterOnlineScriptCommands` and a dozen online and lobby functions (`0x8899xxxx`–`0x889Bxxxx`).
- The `CoreTech_Xenon.bin` loader (`0x889BD370`), which was replaced.

The full lists are in `tu_diff.yaml` under `swing_dll_code`. `Loader_DLL.xexp` touches 8 functions
in place plus one replaced function. `default.xexp` changes constants in 2 functions. Neither is
gameplay.

## 6. Open items

1. Find the XBin loader's signature check and the archive first-match rule. That would turn the
   runtime-precedence conclusion from inference into a code fact.
2. Decode the semantics of `fn_886795C8` and its TU1 form, together with the `29eac4a0` record.
3. Name the axis-6/7 channel hashes `D47EB74D`/`4971563B` and the new booleans (`e26ae391`, the
   `PlayerEvolution` pair, the `5C3DA25E`/`88CD11F5`/`4F146280` members).
4. Recover the September title-server data patch (`PatchData.arc`/`TempPatch.bin`) from a console
   cache, if one exists. Then diff it with `tu_diff.py` against the TU1 state.
5. XEX page-hash verification. The descriptor digests match only all-zero pages under
   `SHA-1(page ‖ next descriptor)`, for both the known-good base image and the patched one. So the
   chain is computed over something else. The patched image is instead verified by the per-block
   SHA-1s and by its well-formed PE section table.
