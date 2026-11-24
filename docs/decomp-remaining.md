# What is left to match in Swing_DLL, and how to attack it

Survey date 2026-11-14. Planning document only. Nothing in `src/`, `config/` or `tools/matching.py` was
changed to produce it, and `tools/matching.py` was not run. Other agents were integrating at the same
time, so every number here is a snapshot of the inputs listed in section 0. Rerun the commands to
refresh them.

## Summary

1. **7.26 MB of 10.15 MB is unmatched.** About **4.02 MB is the game's own code** (Pam/CoreTech engine
   and Swing). **2.95 MB is proprietary middleware and XDK code with no public source:** Havok 5.5.0
   1.31 MB, FMOD Ex 4.32.02 0.74 MB, XDK libraries 0.82 MB and Bink 0.09 MB. **0.28 MB is open-source
   code** whose source is public: the FMOD codecs (CELT, FLAC, Ogg, Vorbis), Lua 5.0.2, zlib, libpng,
   libjpeg, expat and trio.
2. **Reusing already matched code will not close the gap.** Only 14 unmatched functions of 128 bytes
   or more (2.7 KB) have exactly the same normalised instruction sequence as a matched function. At a
   fuzzy 90% opcode similarity the figure is 184 functions (41 KB), and at 80% it is 347 functions
   (83 KB). Earlier rounds have already used up the template and duplicate route. The remaining
   lever of this kind is duplicates *among the unmatched functions themselves*. There are 530 groups
   of identical-opcode functions (1,300 functions, 414 KB). Matching one function per group would
   bring in another 248 KB. The top 100 groups hold 193 KB.
3. **asm2c's problem above 256 bytes is code shape, not coverage.** In the last full run (K6M, up to
   0x800 bytes), it produced C for 12,270 of 14,687 candidates and matched 10. In a stratified sample
   of 35 functions between 256 and 2048 bytes, it produced C for 23 and matched none. Only 2 of those
   23 compiled to the right size and relocation layout. The first divergence was usually one of these:
   - **stack-frame layout**: 11 of 23 (local slot order, frame size, struct temporaries, the varargs
     home area);
   - **register allocation and statement shape**: 6 of 23;
   - **control-flow structure**: 2 of 23 (early-return error paths, duplicated tails);
   - **float or vector code**: 2 of 23;
   - **missed integer idioms**: 2 of 23 (branchless select, 64-bit constants and bitfields).

   A real model of the stack frame is the single translator fix that would help most.
4. **Recommended definition of 100%.** Count the game code plus the open-source libraries:
   5.62 MB, 23.4% matched today. Report Havok, FMOD, XDK and Bink separately, or leave them out:
   4.53 MB, 34.9% matched, almost all of it the generated Havok reflection tables. Section 5 explains
   why.

## 0. Inputs, tools and commands

| Item | Value |
|---|---|
| Repository HEAD when measured | `1c7b6c0e` at the start, `8683c81` at the end (moving tree) |
| `config/54540859/symbols.txt` | sha256 `0ba1dd993b71b1fe83053e7d8135e4d340924e4ecafbf5441be06d1b785dabdf` (46,765 function symbols, 46,736 distinct starts) |
| `config/54540859/match.json` | sha256 `5b3beb18e171b328260eb94f9724be2d7b74d8a01e60543f91b397c2514e18ab` (30,190 matches, 2,897,304 bytes) |
| `orig/54540859/Swing_DLL.dll` (decompressed PE of the XEX) | sha256 `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9` |
| `orig/54540859/Swing_DLL.xex` | sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44` |
| `work/k6m/state.pkl` (K6M asm2c run state, read only) | sha256 `39784c6a45fbba1cb0ac2c946427787d0510ec49ebb3a8f57e2caf6c0346436c` |
| Python / capstone | 3.13.18 / 5.0.7. capstone was used only by `work/disc/ppcd.py` for spot checks. The survey tool decodes raw words itself. |
| Matching split used by asm2c | `work/matching-b39` (`TS4_MATCHING_DIR`) |

New files:

- `tools/decomp_survey.py` (standard library only) holds the bucket ranges and has four
  subcommands: `buckets`, `dups`, `profile` and `sample`.
- `tests/test_decomp_survey.py` holds its tests. They use synthetic data only. Run them with
  `python3 -m unittest tests.test_decomp_survey`.

```sh
python3 tools/decomp_survey.py buckets                      # section 1 table
python3 tools/decomp_survey.py dups --min-size 128 --fuzzy 0.9 --top 20   # section 2.1
python3 tools/decomp_survey.py dups --min-size 128 --fuzzy 0.8 --top 0
python3 tools/decomp_survey.py dups --min-size 8 --top 0
python3 tools/decomp_survey.py profile --min-size 256       # section 2.2
python3 tools/decomp_survey.py sample --lo 256 --hi 768 -n 16 --seed 1     # section 3 sample (with the next line)
python3 tools/decomp_survey.py sample --lo 768 --hi 2048 -n 18 --seed 1
```

"Matched" means that the function start appears in `match.json`. Function sizes come from
`symbols.txt`. The tool's total, 10,153,672 bytes, differs from `match.json`'s 10,154,036 by 364
bytes, because duplicate symbol starts are counted once. START_HERE.md section 2 is stale: it still
says 14,300 functions and 965,440 bytes.

## 1. What the unmatched 7.26 MB is

### 1.1 How the ranges were attributed

The bucket boundaries are hand-set address ranges in `tools/decomp_survey.py` (`RANGES`). The linker
placed each library's objects contiguously. The boundaries were therefore set at the first and last
function carrying strong evidence for a library, then refined from neighbouring matched source files.
The evidence comes from these sources:

- **String references.** A raw-word scan of `lis`/`addi`/load pairs in every function found 13,574
  functions that reference a C string. Examples:
  - `..\src\fmod_*.cpp` and `c:\anthill_builds\fmod4\...`;
  - `k:\H2K\Build\code\Complete\Source\Physics/...` and `hkpMopp*VirtualMachine.cpp`;
  - `e:\xenon\xdk-main-sep10\core\private\xtl\graphics\xgraphics\ucode\...`;
  - `c:\dev\coretech\private\...`;
  - `C:\devel\projects\bink\src\sdk\decode\binkread.c`;
  - the D3D GPU-hang messages and the PIX strings;
  - `Invalid image filter`, `#?RADIANCE` and `1.0.5` (D3DX and libpng);
  - `LUA_SOPATH=`, `OpenMP Warning>>`.
- **RTTI.** 496 vtables carry an MSVC complete-object locator, which points to 424 `.?AV` type names.
  All of them are Havok types (hk 113, hkp 280, hka 15) or anonymous Havok namespaces. The game code
  is built without RTTI.
- **Import calls.** These pin several boundaries:
  - Havok code calls `KeTlsGetValue` (hkThreadMemory) up to 0x88562800;
  - the CRT entry `_DllMainCRTStartup` is at 0x88562DB0;
  - `XMACreateContext` and `XAudioGetVoiceCategoryVolume` mark XAudio2 from 0x88590000;
  - `MicDeviceRequest` and `RmcDeviceRequest` mark the voice library at 0x885D8328;
  - `KeGetCurrentProcessType` marks D3D from 0x88287D28.
- **Version constants.**
  - `Havok-5.5.0-r1` is the newest entry in the hkVersionRegistry list. It is also the packfile
    version of every `.hkx` on the disc (`docs/havok.md`).
  - `lis rX,4; ori rX,rX,0x3202`, i.e. `FMOD_VERSION` 0x00043202, appears exactly once in the FMOD
    range. This identifies FMOD Ex 4.32.02.
  - `inflate 1.2.3` / `deflate 1.2.3` identify zlib 1.2.3.
  - `Lua 5.0.2` and `Copyright (C) 1998, Thomas G. Lane` (libjpeg 6b).
  - `@(#)$Id: trio.c,v 1.75` (trio 1.10).
- **Which Havok products have code.** Code references Havok strings only with the `hk`, `hkp` and
  `hka` prefixes. `hkb*` (Behavior) and `hkx*` (scene) names occur only inside the reflection tables
  (1,605 and 1,032 references there, none from code). So the shipped code is Havok Physics, Havok
  Animation and Base/Serialize/Compat, while Behavior and scene classes are registered but not
  linked as code.

Boundary confidence:

- **High:** library extents that end at a matched function from a named library source
  (`lib2_flac_*`, `aud1_vorbis_*`, `ex3_zlib_*`, `r3_xmlparse`, `lua2_*`, `lib4_trio*`).
- **Medium:** the Havok sub-ranges and the XDK splits. Each is accurate to within about 16 KB. They
  were set from 16 KB bins of string, RTTI and import evidence.
- **Inferred, not measured:**
  - "D3D9 runtime" for 0x88287D28-0x882A0000;
  - "D3DX9" for 0x882A8000-0x882E25D8;
  - that the libpng/libjpeg/zlib 1.1.4 copy belongs to D3DX9. It sits right after the D3DX image
    loaders and before FMOD, and the libpng version string `1.0.5` is referenced from the D3DX range.

The game sub-ranges reuse the subsystem layout of `docs/gameplay-map.md` section 1.1, with the byte
counts re-measured here.

### 1.2 Bucket table

From `python3 tools/decomp_survey.py buckets`. "unm" columns are unmatched bytes by function size.

| Bucket | Range | Fns | Bytes | Matched fns | Matched bytes | Unmatched bytes | %done | unm <128 | 128-256 | 256-1K | >1K |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| game: core (XData, containers, UI node classes) | 88150000-8819C000 | 1971 | 308404 | 1209 | 108980 | 199424 | 35.3 | 11732 | 71732 | 102552 | 13408 |
| lib: trio 1.x (printf) | 8819C000-881A2000 | 53 | 24572 | 30 | 11796 | 12776 | 48.0 | 908 | 1328 | 1788 | 8752 |
| game: core (loaders, resources, render support) | 881A2000-88287D28 | 3750 | 934524 | 2001 | 189508 | 745016 | 20.3 | 22264 | 132820 | 335972 | 253960 |
| xdk: D3D9 runtime (inferred) | 88287D28-882A0000 | 425 | 98120 | 200 | 5264 | 92856 | 5.4 | 3568 | 13684 | 41692 | 33912 |
| xdk: PIX / D3D debug | 882A0000-882A8000 | 75 | 33088 | 20 | 1476 | 31612 | 4.5 | 364 | 3488 | 10488 | 17272 |
| xdk: D3DX9 texture/image loaders | 882A8000-882E25D8 | 511 | 237404 | 109 | 7336 | 230068 | 3.1 | 4688 | 18316 | 95824 | 111240 |
| lib: libpng 1.0.5 + libjpeg 6b + zlib 1.1.x | 882E25D8-883089E0 | 408 | 155868 | 391 | 141648 | 14220 | 90.9 | 248 | 416 | 4760 | 8796 |
| fmod: FMOD Ex 4.32.02 core, DSP, output | 883089E0-88399650 | 1540 | 589560 | 746 | 58932 | 530628 | 10.0 | 10688 | 46140 | 158612 | 315188 |
| lib: FMOD codecs (CELT, FLAC, Ogg, Vorbis) | 88399650-883C6218 | 415 | 182392 | 213 | 52496 | 129896 | 28.8 | 1732 | 7904 | 52536 | 67724 |
| fmod: FMOD Ex 4.32.02 event/music system | 883C6218-884014E0 | 1109 | 240372 | 536 | 35020 | 205352 | 14.6 | 10888 | 34048 | 100100 | 60316 |
| havok: 5.5.0 Animation (hka) | 884014E0-88418000 | 291 | 93404 | 123 | 5924 | 87480 | 6.3 | 3708 | 7244 | 33724 | 42804 |
| havok: 5.5.0 Base/Serialize (hk) | 88418000-88436000 | 777 | 120248 | 443 | 30100 | 90148 | 25.0 | 8248 | 23840 | 42440 | 15620 |
| havok: 5.5.0 Physics dynamics/collide (hkp) | 88436000-884C4000 | 3083 | 576056 | 1791 | 102024 | 474032 | 17.7 | 22192 | 81044 | 234720 | 136076 |
| havok: 5.5.0 Serialize/Compat (hk) | 884C4000-884E8000 | 545 | 156000 | 269 | 18388 | 137612 | 11.8 | 3788 | 19656 | 45904 | 68264 |
| havok: 5.5.0 mixed (anim compression, keycode, utils) | 884E8000-88520000 | 608 | 217508 | 223 | 12296 | 205212 | 5.7 | 5088 | 25216 | 72924 | 101984 |
| havok: 5.5.0 Physics agents/MOPP (hkp) | 88520000-88562AB8 | 491 | 271692 | 138 | 7052 | 264640 | 2.6 | 3524 | 14092 | 84496 | 162528 |
| xdk: C runtime + xapi | 88562AB8-88590000 | 823 | 184096 | 315 | 27948 | 156148 | 15.2 | 13592 | 28604 | 64680 | 49272 |
| xdk: XAudio2 / XMA | 88590000-885D8328 | 1017 | 293252 | 416 | 30536 | 262716 | 10.4 | 7988 | 38724 | 110756 | 105248 |
| xdk: voice (XHV, Mic/Rmc) | 885D8328-885DC838 | 64 | 17532 | 20 | 1124 | 16408 | 6.4 | 592 | 2992 | 8160 | 4664 |
| xdk: xgraphics shader ucode compiler | 885DC838-885E78C8 | 261 | 44596 | 171 | 20796 | 23800 | 46.6 | 3112 | 4868 | 11976 | 3844 |
| havok: 5.5.0 Base/Serialize/Utilities tail | 885E78C8-885F4E48 | 258 | 54112 | 126 | 8296 | 45816 | 15.3 | 2148 | 7248 | 26344 | 10076 |
| game: Pam core (XData server, heaps, modules) | 885F4E48-88640000 | 2551 | 303140 | 1822 | 102328 | 200812 | 33.8 | 20648 | 45676 | 97004 | 37484 |
| game: Swing gameplay + animation glue | 88640000-886E8000 | 2538 | 682572 | 1149 | 65528 | 617044 | 9.6 | 24332 | 78304 | 263420 | 250988 |
| game: Pam Display renderer | 886E8000-88780000 | 1973 | 618464 | 917 | 61764 | 556700 | 10.0 | 14320 | 52972 | 242044 | 247364 |
| game: PlayerCreator, UI, script bindings | 88780000-88800000 | 1844 | 520660 | 923 | 90416 | 430244 | 17.4 | 11344 | 59452 | 188564 | 170884 |
| lib: Lua 5.0.2 (+ script engine glue) | 88800000-8883C000 | 1159 | 243452 | 930 | 152400 | 91052 | 62.6 | 3400 | 19528 | 35696 | 32428 |
| game: game flow DB (season, profiles) | 8883C000-88871F08 | 820 | 219080 | 390 | 31704 | 187376 | 14.5 | 6776 | 26828 | 83620 | 70152 |
| lib: zlib 1.2.3 | 88871F08-88878FA0 | 53 | 28684 | 47 | 18476 | 10208 | 64.4 | 48 | 212 | 576 | 9372 |
| game: physics wrapper, IO, sound events | 88878FA0-88891678 | 480 | 99012 | 286 | 18376 | 80636 | 18.6 | 3824 | 10124 | 38080 | 28608 |
| lib: expat | 88891678-888AA8D0 | 254 | 102500 | 241 | 84488 | 18012 | 82.4 | 360 | 148 | 1704 | 15800 |
| game: ball, camera, minigames, publishers | 888AA8D0-88900000 | 1303 | 347604 | 681 | 56568 | 291036 | 16.3 | 9416 | 32816 | 135604 | 113200 |
| game: net/lobby, scheduler, front end | 88900000-889CE000 | 3277 | 836864 | 1736 | 124224 | 712640 | 14.8 | 24984 | 96928 | 281012 | 309716 |
| lib: Lua 5.0.2 libs (tab/math/loadlib) | 889CE000-889D02D8 | 49 | 8772 | 25 | 1712 | 7060 | 19.5 | 640 | 1004 | 5416 | 0 |
| xdk: OpenMP runtime | 889D02D8-889D1900 | 11 | 5680 | 4 | 332 | 5348 | 5.8 | 88 | 500 | 832 | 3928 |
| game: static initialisers | 889D1900-889D3410 | 124 | 6616 | 111 | 4952 | 1664 | 74.8 | 548 | 368 | 748 | 0 |
| havok: reflection/class tables + static init | 889D3410-88B00000 | 11576 | 1211420 | 11438 | 1207096 | 4324 | 99.6 | 2472 | 132 | 1720 | 0 |
| bink: Bink (BINK/RADCODE sections) | 88B00000-88B20000 | 249 | 86352 | 0 | 0 | 86352 | 0.0 | 3484 | 5496 | 32336 | 45036 |
| **total** | | 46736 | 10153672 | 30190 | 2897304 | 7256368 | 28.5 | | | | |

Rolled up:

| Group | Bytes | Matched | Unmatched | Of which |
|---|---:|---:|---:|---|
| Game code (Pam/CoreTech + Swing) | 4,876,940 | 854,348 | **4,022,592** | 737 functions over 1 KB hold 1.50 MB |
| Open-source libraries | 746,240 | 463,016 | **283,224** | codecs 130 KB, Lua 98 KB, expat 18 KB, png/jpeg 14 KB, trio 13 KB, zlib 10 KB |
| Havok 5.5.0 (Physics, Animation, Base) | 2,700,440 | 1,391,176 | **1,309,264** | 1,207,096 of the matched bytes are the generated reflection tables |
| FMOD Ex 4.32.02 (without codecs) | 829,932 | 93,952 | **735,980** | |
| XDK libraries (CRT, xapi, D3D, D3DX, PIX, XAudio2, XHV, xgraphics, OpenMP) | 913,768 | 94,812 | **818,956** | |
| Bink | 86,352 | 0 | **86,352** | |

Unmatched bytes by function size. Each cell is functions/bytes:

| Group | <256 | 256-512 | 512-1K | 1K-2K | 2K-4K | >=4K |
|---|---|---|---|---|---|---|
| game | 4904 / 758,208 | 2539 / 903,420 | 1226 / 865,200 | 523 / 729,316 | 158 / 430,552 | 56 / 335,896 |
| lib | 240 / 37,876 | 127 / 44,552 | 83 / 57,924 | 41 / 56,860 | 18 / 54,496 | 5 / 31,516 |
| sdk | 3568 / 485,552 | 1578 / 565,568 | 863 / 612,160 | 422 / 581,272 | 148 / 406,860 | 47 / 299,140 |

The largest unmatched functions are:

- 0x882506A0, 21,500 B (game core);
- 0x88310E30, 13,432 B (FMOD);
- 0x889CAD28, 11,836 B (front end);
- 0x884E7DB8, 11,416 B (Havok Compat);
- 0x8838DE30, 0x8835E190 and 0x883928D0, 10-11 KB each (FMOD DSP and mixers).

Notes on specific ranges:

- **0x88240000-0x88258000 (game core).** This range is 38 functions and 98 KB, all unmatched, with no
  strings. The functions are large and VMX-heavy, and the game renderer calls them. They are probably
  hand-vectorised skinning or geometry code (inferred).
- **Second zlib copy.** The zlib 1.2.3 copy at 0x88871F08 is separate from the zlib 1.1.4 that is
  embedded with libpng. Its unmatched `inflate()` (0x88874270, 6,308 B) and `deflate()`
  (0x88876730, 3,064 B) have exact public source.
- **Lua.** The Lua 5.0.2 libraries are split across two places, 0x88800000-0x8883C000 and
  0x889CE000-0x889D02D8 (ltablib, lmathlib and loadlib strings).

## 2. Cheapest route per bucket

### 2.1 Template, inline and duplicate reuse (measured)

`decomp_survey.py dups` normalises every function's instruction words at three tiers:

- **Tier 1:** call targets and `lis`-paired immediates are masked, and registers are kept.
- **Tier 2:** only the primary and extended opcode of each instruction is kept.
- **Tier 3 (`--fuzzy`):** the difflib ratio of the opcode sequences against matched functions within
  15% of the size, with candidates found by MinHash LSH on opcode 4-grams.

| Unmatched functions >= 128 B (13,160 fns, 6,905,756 B) that repeat a matched function | Fns | Bytes |
|---|---:|---:|
| Tier 1, identical modulo relocations | 5 | 960 |
| Tier 2 only, identical opcode sequence | 9 | 1,708 |
| Tier 3, opcode similarity >= 0.9 (not tier 1/2) | 184 | 41,184 |
| Tier 3, opcode similarity >= 0.8 (not tier 1/2) | 347 | 82,676 |

All sizes (>= 8 B): tier 1 has 13 functions (1,432 B) and tier 2 has 69 functions (4,296 B). Tier 3
at 0.9 is concentrated in these buckets:

- game core: 70 functions, 14 KB;
- PlayerCreator/UI: 22 functions, 5.7 KB;
- Lua glue: 20 functions, 4 KB;
- Havok: 16 functions, 2.9 KB.

The top tier-3 pairs are listed by the command, e.g. 0x885DFB70 ~ 0x885DEF98 (ratio 0.993) and
0x88832648 ~ 0x8882A258 (0.993).

**Clusters among the unmatched functions** are the larger lever. Matching one representative covers
the rest of its group:

| Groups (>= 128 B) | Groups | Functions | Total bytes | Bytes covered beyond the representatives |
|---|---:|---:|---:|---:|
| Tier 1 | 244 | 589 | | 123,388 |
| Tier 2, all | 530 | 1,300 | 413,656 | 247,564 |
| Tier 2, top 100 by bytes | 100 | 337 | 193,052 | 127,096 |
| Tier 2, top 50 | 50 | 193 | 135,396 | 92,168 |

By group, the tier-2 cluster bytes are game 242 KB, SDK 160 KB and lib 12 KB. The biggest clusters:

- 9 x 964 B at 0x8822EE20 and 8 x 1,080 B at 0x88239620: game loaders, the `floor`-calling family
  at 0x88239620-0x8823D0F8;
- D3DX pixel-format converters, 4 x 1,164 B at 0x882B9558 and so on;
- 7 x 624 B and 7 x 452 B at 0x88256870 and 0x88256AE0;
- 6 x 620 B at 0x889C9CF8;
- 15 x 216 B and 15 x 188 B in Havok Physics, at 0x8844CAF0 and 0x8844E080.

### 2.2 Code features of what is left (measured)

From `decomp_survey.py profile --min-size 256`. Bytes of unmatched functions of 256 bytes or more that
contain at least one instruction of each kind:

| Total | bctr (switch / computed jump) | VMX/VMX128 | floating point | integer only |
|---:|---:|---:|---:|---:|
| 5,897,360 | 456,108 (7.7%) | 1,405,036 (23.8%) | 3,015,040 (51.1%) | 2,728,748 (46.3%) |

The buckets that are mostly integer-only, and so easiest for both translator and hand work:

| Bucket | Integer-only bytes / total bytes (functions >= 256 B) |
|---|---|
| game flow DB | 138,504 / 153,772 (90%) |
| Pam core | 111,972 / 134,488 |
| game core XData | 101,208 / 115,960 |
| CRT + xapi | 99,408 / 113,952 |
| Havok Serialize/Compat | 79,048 / 114,168 |

The heaviest in VMX:

| Bucket | VMX bytes / total bytes |
|---|---|
| Swing gameplay | 275,696 / 514,408 |
| Havok Physics | 214,328 / 370,796 |
| Havok agents/MOPP | 183,440 / 247,024 |
| game core loaders | 148,208 / 589,932 |
| renderer | 126,412 / 489,408 |

FMOD core has the most switch bytes: 146,232 of 473,800. (The tool also prints a 64-bit integer
column. It is noisy because `rldicl` zero-extension and `std` register saves are everywhere, so it
is not used here.)

### 2.3 Route per bucket

| Bucket(s) | Unmatched | Public source? | Cheapest realistic route |
|---|---:|---|---|
| zlib 1.2.3 | 10 KB (3 fns) | Yes, exact: zlib 1.2.3 from zlib.net (`inflate.c`, `deflate.c`) | Compile the upstream function with flag sweeps (`/O1`, `/O2`). `inflate()` has a large switch, so use the jump-table support in `fn_check` (`TS4_MATCHING_DIR=work/matching-jt`). Low difficulty. |
| libpng / libjpeg 6b / zlib 1.1.4 | 14 KB (9 fns of 556-2,572 B) | Yes: libpng 1.0.5/1.0.6, IJG jpeg-6b, zlib 1.1.4 | Upstream source. These are the last large functions; earlier rounds matched 91% of the bucket. Low to medium difficulty. |
| expat | 18 KB (7 fns, 548-6,448 B) | Yes: Expat 2.0.x (earlier rounds used 1.95/2.0-era source, THIRD_PARTY_NOTICES.md) | Upstream source. 14 KB of it is in functions with switches (the xmltok/xmlparse state machines). Medium difficulty. |
| trio 1.10 | 13 KB (4 large fns) | Yes: trio 1.10 (SourceForge ctrio) | Upstream `trio.c`, `TrioFormatProcess` and the like. These are float-formatting paths. Medium difficulty. |
| Lua 5.0.2 (both ranges) | 98 KB | Yes: Lua 5.0.2 (lua.org) plus LuaPlus-style changes. Part of the bucket is the game's `CScriptEngine` glue, which has no source. | Upstream for the Lua part. Treat the glue as game code. Medium difficulty. |
| FMOD codecs | 130 KB (202 fns, 10 above 1.8 KB) | Yes, near version: CELT 0.6.1, libFLAC 1.2.1, libogg, libvorbis (2009, about 1.2.3) | Upstream source. First pin the vorbis version from matched `aud1_vorbis_*` neighbours. Float-heavy (92 KB contain FP). Medium difficulty. |
| Game code, all buckets | 4.02 MB | No | Hand decompilation driven by asm2c drafts, `fn_check` and `permute.py`, with types recovered per subsystem. Start where code is integer-only (game flow DB, Pam core, XData) and with the duplicate clusters. Drafts in `src/xbox360/drafts/` and `docs/gameplay/` already cover much of gameplay semantically. |
| Havok 5.5.0 code | 1.31 MB | No. Havok source was licensee-only. The free 2008-2010 PC SDK shipped headers and binary libraries, not source, under a proprietary licence: do not download it or derive from it. | Hand decompilation. Two strong aids are already in the binary: the 424 RTTI class names, and the hkClass reflection tables, which give member names, types and offsets for 352 classes (`work/havok55_classes.json`, generated locally per `docs/gameplay/df.md` 5.4, never commit). Most of the code is hkVector4/hkArray inline math (VMX). Hard. |
| FMOD Ex 4.32.02 core and events | 0.74 MB | No. FMOD Ex source was licensee-only. The public programmer's API download contains headers only, under a proprietary licence. | Hand decompilation. The C API wrappers (`fmod.cpp`, 0x883089E0+) are mostly matched already. The internals are switch- and float-heavy. Hard. |
| XDK libraries | 0.82 MB | No. Microsoft XDK 2.0.20209 static libraries; source never published. The Visual C++ 2010 CRT source that ships with Visual Studio is a near version of the CRT part (about 156 KB) but is proprietary. Do not commit it or anything copied from it. Whether an agent may read a locally licensed copy is an owner decision. | Hand decompilation, or leave unmatched (section 5). Earlier rounds matched some CRT pieces (`d9crt_*`, `port1_crt_*`) from Loader_DLL counterparts. Shared XDK code in `Loader_DLL.xex` is the one cheap cross-module source: same toolchain and libraries (inferred, not measured here). |
| Bink | 86 KB | No (RAD Game Tools SDK; version string not found) | Leave for last. It is in its own BINK/RADCODE sections, and whether it was built with the same compiler and flags is unverified. |

Two smaller points:

- **Compiler-generated code** (vcall thunks, `??_9` pointer-to-member thunks, dtor wrappers,
  `$LN` switch blocks, static initialisers) is effectively finished. The static initialisers are
  74.8% matched and the Havok reflection and static-init region 99.6%. None of the remaining large
  buckets is dominated by generated code.
- **Cross-module duplicates in Loader_DLL** are a measurable route that this survey did not
  measure. The same `dups` normalisation could be run against `config/54540859/loader/match.json`.
  It is listed as batch 9 below.

## 3. Why large functions fail in asm2c today

### 3.1 Population data from the K6M run

`work/k6m/run.log` and `state.pkl` come from `work/k6m/driver.sh`: up to 0x800 bytes, variants
10w, 10wV, 20w, 10wJ and 10, both flag sets. The base flag set's 10w pass gave 14,687 candidates,
12,270 translated, **10 matched**, and 12,260 "GENERATED-NOMATCH".

A near miss is recorded only when the candidate has the target's size and relocation layout, which
is the precondition for `permute.py`. Of the translated functions, 1,052 reached that stage. With 10
or fewer differing instructions there are 512 functions totalling 64.6 KB, most of them under 256
bytes.

Translation and near-miss rate by size, as fn_ functions per class. (The candidates column counts
unmatched `fn_` functions at survey time plus K6M's own matches.)

| Size | Candidates | Translated | Same size and relocation layout |
|---|---:|---:|---:|
| <128 | 2984 | 2501 (84%) | 454 |
| 128-256 | 5379 | 4572 (85%) | 385 |
| 256-512 | 4202 | 3065 (73%) | 133 |
| 512-1K | 2128 | 1251 (59%) | 15 |
| 1K-2K | 975 | 388 (40%) | 1 |

Top translate-time refusals in K6M:

| Refusal | Count | Meaning |
|---|---:|---|
| read r | 655 | A register is read before the symbolic executor has a value for it. |
| stvewx | 190 | |
| irregular exit | 156 | |
| loop shape | 133 | |
| stack addr | 97 | |
| double break | 91 | |
| vec loop | 69 | |
| br out | 66 | |
| struct arg | 63 | |
| too big | 63 | |
| unrelocated original | 53 | |
| std | 47 | |
| fsel | 39 | |
| vsldoi | 31 | |

So unsupported instructions are a minor cause, about 400 functions. Nearly all of the loss comes from
C that compiles to different code.

### 3.2 Sample of 35 functions, 256-2048 bytes

**Sample.** Stratified by bucket and size, drawn with the two `sample` commands in section 0 (seed 1):

> 88196708 88226cf8 88239a58 88283490 882d4c48 882d9180 88325370 88330af8 88344798 883abed8
> 8840d480 884141c0 884a3918 8850c910 885286a8 88551f98 88588890 88590eb8 885c3348 8860adf0
> 886b29c8 886bbea8 886d22a0 88706e48 8870fe00 8872d070 88795930 887d73c0 8884e000 888506e0
> 888d7920 888ea3e8 88923d98 8892e580 889a80c0

Together they are 26,056 bytes.

**Run.** A scratch work dir with its own state, cache, `--out-dir` and `--spec-dir`, and
`--no-final`, so nothing was written to `src/` or `work/specs/`. The loop below was run once per
variant 10w, 10wV, 20w, 10wJ and 10, and per flag set "" and O1:

```sh
TS4_MATCHING_DIR=$PWD/work/matching-b39 python3 tools/asm2c/run.py --prefix zz_survey --family ZZSURVEY \
  --work $W --out-dir $W/out --spec-dir $W/specs --no-final --max-size 0x800 \
  --variants $v --flagsets "$fs" --only-addrs $W/only.txt --jobs 4
```

The full run took 1 m 50 s. Each scratch file was then rechecked with
`python3 tools/fn_check.py <file> name=0xADDR ...` (adding `--flags /O1` for O1) to get the listings.
For each function, the variant closest in size and in differing instructions was kept.

**Result.** 0x886D22A0 is in a `work/gen_exclude.txt` range, which another agent has reserved, so it
was not tried. Of the remaining 34:

- **11 were refused at translation:** `read r` 4 (0x882D9180, 0x886B29C8, 0x88795930, 0x8884E000),
  `loop shape` 0x883ABED8, `struct arg` 0x884141C0, `stvewx128` 0x884A3918, `vreg` 0x8850C910,
  `vec loop` 0x88590EB8, `irregular exit` 0x888D7920, `vsldoi128` 0x888EA3E8.
- **23 were translated and none matched.** Only 2 had the target's size and relocation layout and a
  small diff, and so are permuter candidates: 0x88196708 (14 differing instructions) and
  0x88551F98 (21). For the other 21 the candidate size differed from the target by -10% to +100%.

Cause of the *first* divergence for the 23, read from the `fn_check` listings:

| Cause | Count | Functions | What the listing shows |
|---|---:|---|---|
| Stack-frame layout | 11 | 88196708, 88239A58, 8840D480, 88551F98, 886BBEA8, 8872D070, 887D73C0, 888506E0, 8892E580, 889A80C0, 88706E48 | Different `stwu` frame size (0x1E0 vs 0x230, 0x2F0 vs 0x340, 0x70 vs 0xE0, ...) or the same size with locals at different offsets. Causes: out-parameter locals at 0x54 vs 0x58, struct temporaries, the varargs home area at 0x100 vs 0xF0. asm2c models stack data as word arrays accessed through casts, not as separately declared typed locals, so MSVC lays them out differently. |
| Register allocation / statement shape | 6 | 88226CF8, 88283490, 88588890, 885C3348, 8870FE00, 88923D98 | Same instructions with permuted registers. One more or one fewer callee-saved register. A loop written with an index (`mulli`) where the target strength-reduces to a pointer. A field reload where the original kept a CSE'd pointer in r30. Global struct initialiser stores in a different order. |
| Control-flow structure | 2 | 88325370, 88330AF8 (both FMOD) | The target returns error codes early (`li r3,0x25; addi r1..; b __restgprlr`). The candidate nests the body under the inverted test and duplicates shared tails, which makes it twice the size. |
| Float / vector code | 2 | 882D4C48 (D3DX), 885286A8 (Havok) | The candidate spills far more FP registers (`__savefpr_17` vs `__savefpr_28`), does not reuse float temporaries or loaded constants, and is 1.3-1.8x the size. |
| Integer idioms | 2 | 88344798, 8860ADF0 | The branchless select `subfic/subfe/and` (a `cond ? -1 : 0` mask) is rewritten as branches. 64-bit bitfield extraction with `ld`/`rldicl` is mistranslated. 0x88706E48 also drops a 64-bit constant argument (`rldicr r7,r7,55` = `1ull << 55`) to 0. |

### 3.3 Which fixes would unlock the most bytes

These are judgements from the measurements above. The byte effects are inferred, not measured.

1. **Stack-frame model.** Emit one declared local per stack slot, with the type its accesses imply
   (int, float, double, 64-bit, struct of the observed span). Declare them in the order MSVC needs to
   reproduce the offsets, and check the frame size before compiling: compare `stwu` with the target
   and reorder or re-type until it agrees. This was the first divergence in 11 of 23 sample
   functions. It is also a prerequisite for `permute.py`, which only works once size and relocation
   layout agree, and that happened for 1 of the 388 translated functions of 1-2 KB. *Expected effect*:
   moves a large share of the 256-1K translations into the near-miss pool.
2. **Shape variants for register allocation.**
   - Generate fewer and more reused variables (MSVC's allocation follows the source variables' live
     ranges).
   - Rewrite loops with pointer induction when the target increments a pointer register.
   - Keep a CSE'd field pointer as a named local when the target keeps it in a callee-saved
     register.
   - Feed these to `permute.py` as `PERM_ALT` markers instead of emitting a single guess.
3. **Structurizer: early returns and shared tails.** Prefer `if (!x) return ERR;` when the target
   duplicates the epilogue, and stop duplicating tails. This also covers the K6M refusals
   `irregular exit` 156, `loop shape` 133, `double break` 91, `br out` 66 and `too big` 63. These
   cases are concentrated in FMOD, the bucket with the most switch and error-return code.
4. **Fix `read r`**, the largest refusal class (655 in K6M, 4 of 35 in the sample). It means the
   argument count was inferred wrongly, or a value is carried in a callee-saved register across a
   call from another path.
5. **Float and 64-bit idioms**: float temporary reuse, `__real@` constant handling, `fsel`, the
   compare-to-mask select, 64-bit constants, and `ld`/`std` struct copies. Unsupported VMX opcodes
   (`stvewx`, `vsldoi`, vector loops) come last. Together they are under 3% of K6M refusals.

Even with all of these, asm2c will not turn a 1-2 KB function into a match by itself. The realistic
role for asm2c above 512 bytes is to produce a compiling, behaviourally faithful draft that already
has the right frame and control flow. An agent then closes the gap with `fn_check` and `permute.py`.

## 4. Ranked plan

Effort is in agent rounds, one agent working one batch of the size of the earlier K and D rounds.
Expected bytes are estimates (inferred). The "unmatched" figures are measured. Ordered by expected
bytes per round.

| # | Batch | Unmatched in scope | Expected gain | Rounds | Difficulty | Why this order |
|---:|---|---:|---:|---:|---|---|
| 1 | **Open-source big functions**: zlib 1.2.3 `inflate`/`deflate` + 1 (0x88873870, 0x88874270, 0x88876730), libpng/jpeg/zlib 1.1.4 (9 fns at 0x882E6298-0x882FEB48), expat (7 fns, 0x88899F70-0x888A8898), trio (4 fns, 0x8819E4F0-0x881A0E68), Lua libs at 0x889CE000 (5 fns) | 52 KB | 35-50 KB | 1 | low-medium | Exact public source; only flags, switch tables and local edits stand in the way. |
| 2 | **Duplicate clusters, top 100** (`dups --min-size 128` tier-2 list): match one representative per cluster by hand from an asm2c draft, then clone with renamed offsets | 193 KB in 337 fns | 120-190 KB | 1-2 | medium | One representative pays for 3.4 functions on average. Across all 530 clusters, 58% of the bytes are game code. |
| 3 | **FMOD codecs**: CELT 0.6.1, libFLAC 1.2.1, libogg, libvorbis | 130 KB | 80-120 KB | 1-2 | medium | Public source of a near version. Float-heavy. Pin the vorbis version first. |
| 4 | **Lua 5.0.2 remainder + script-engine glue** at 0x88800000-0x8883C000 | 91 KB | 50-80 KB | 1 | medium | Lua part from upstream. The glue is game code with many repeated binding shapes (tier-3 hits). |
| 5 | **asm2c: stack-frame model + early-return structurizer + `read r`** (section 3.3, items 1, 3 and 4), then rerun at most 0x800 bytes and permute the new near misses | 5.56 MB (15,774 fn_ candidates up to 2 KB) | 100-300 KB (very uncertain) | 2 | high | Tooling. Pays back across every later batch. Do it before the large hand batches. |
| 6 | **Game flow DB** (season, profiles, tournament; 0x8883C000-0x88871F08) | 187 KB | 120-170 KB | 2-3 | medium | 90% integer-only. Data-structure code with clear XData paths in strings. |
| 7 | **Pam core + core XData/containers** (0x885F4E48-0x88640000, 0x88150000-0x8819C000) | 400 KB | 250-350 KB | 3-4 | medium | Mostly integer. Already a third matched, so types exist. Everything else calls into it, so later batches get easier. |
| 8 | **PlayerCreator/UI/script bindings + front end, net and lobby** (0x88780000-0x88800000, 0x88900000-0x889CE000) | 1.14 MB | 0.6-0.9 MB | 6-8 | medium-high | Large and less float-heavy; 1,265 functions of at least 128 B in the front end alone. |
| 9 | **Loader_DLL cross-module duplicates**: run the `dups` normalisation against Loader matches (shared CRT, XDK, zlib and engine code) | not measured | not measured | 0.5 | low | Cheap measurement. Could pull in CRT and XDK functions without source. |
| 10 | **Game core loaders/resources** (0x881A2000-0x88287D28, including the 98 KB VMX block at 0x88240000) | 745 KB | 0.4-0.6 MB | 5-6 | high | |
| 11 | **Gameplay + ball/camera + physics wrapper** (0x88640000-0x886E8000, 0x888AA8D0-0x88900000, 0x88878FA0-0x88891678) | 989 KB | 0.5-0.8 MB | 8-10 | high | VMX/float-heavy. Highest value for goal 1, and drafts in `docs/gameplay/` give semantics. Should be pulled earlier if the owner wants gameplay-first. |
| 12 | **Renderer** (0x886E8000-0x88780000) | 557 KB | 0.3-0.45 MB | 5-6 | high | |
| 13 | **Havok 5.5.0** by product: Base/Serialize/Compat first (273 KB, the most integer code), then Animation (87 KB; the codecs are already understood, `docs/havok.md`), then Physics (1.0 MB) | 1.31 MB | 0.6-1.0 MB | 12-16 | very high | No source. Types from reflection. |
| 14 | **FMOD Ex core + events** | 736 KB | 0.3-0.6 MB | 8-12 | very high | No source. Switch- and float-heavy. |
| 15 | **XDK libraries + Bink** | 905 KB | ? | ? | very high | No source. Possibly built differently (Bink). See section 5. |

The top five recommendations are batches 1, 2, 3, 5 and 6. Batch 4 is interchangeable with 5 if no
agent is free for tooling.

## 5. What cannot be matched without source, and what "100%" should mean

Strictly, any function compiled by this MSVC can be matched by hand: earlier rounds matched CRT, XDK
and Havok pieces with no source. In practice, the **2.95 MB of Havok, FMOD, XDK and Bink code** has
these problems:

- **No source.** We have no source, and we must not obtain proprietary SDK source.
- **Publication.** It would end up as a published re-creation of three vendors' proprietary
  libraries, which the repository rules (no proprietary SDK material) argue against.
- **Effort.** It costs at least as much per byte as game code (very VMX- and switch-heavy).
- **No benefit to the goals.** It does nothing for the project's goals, which are the gameplay
  essence and retuning.
- **Bink may be out of reach.** It may not be reproducible with this compiler at all (unverified).

I recommend:

- **"100%" = all game code plus the open-source libraries:** 5,623,180 bytes, of which 1,317,364
  (23.4%) are matched today. Every byte of it is either the game itself or has public upstream source.
- **Report the SDK middleware separately:** 4,530,492 bytes, 1,579,940 (34.9%) matched, of which
  1,207,096 is the generated Havok reflection and static-init region. Treat it as linked binary
  libraries, like a debug-symbol-less static library in other decompilation projects. Match it only
  opportunistically: functions that appear in the duplicate clusters, CRT and XDK code that turns out
  to be shared with Loader_DLL (batch 9), and Havok classes the gameplay port needs.

Recording the split needs a scope list in `config/` (for example the `RANGES` groups from
`tools/decomp_survey.py`), and `sync_progress.py` would need to report both numbers. Neither change
was made here: config and the matching pipeline were out of scope for this survey.

## 6. Caveats

- **Range boundaries are hand-set.** The Havok sub-ranges and the XDK split points are accurate to
  within about 16 KB. The "D3D9 runtime" and "D3DX9" labels, and the claim that the libpng/libjpeg
  copy belongs to D3DX, are inferred from neighbourhood and strings.
- **Duplicate tiers can miss things.** They are computed from raw words. Tier 1 can miss duplicates
  whose embedded jump tables differ, and tier 2 ignores registers entirely, so a tier-2 cluster
  member may still need different source (different struct offsets, constants or types).
- **The sample is small.** 35 functions, and each one's first divergence was classified by reading
  one listing. The per-cause counts are indicative, not population estimates.
- **The tree was moving.** Other agents were integrating `fk6_`, `fk6m_` and `d1g_` work during the
  survey. Rerun `decomp_survey.py buckets` against the current `match.json` before choosing ranges,
  and check `work/gen_exclude.txt` for reserved ranges.
