# Matching build

The first seventy matching measurement units cover online feature stubs, session predicates, TSU statistics, profile summaries, friends leaderboards, Pro Challenge, title-server, player-visibility, minigame, King of the Court, TSU object callbacks, NetDB initialization, and span helpers from the locked `Swing_DLL.xex`. Xbox 360 MSVC `16.00.10224.00` reproduces all 9,676 code bytes across eighty functions exactly: most units use `/O2 /Oi`, the per-round TSU aggregation and lobby-timer units additionally require `/GS-`, the three friends-leaderboard units require `/GS- /GR- /EHs-c-`, and the thread-resume wrapper requires `/O1 /Oi`.

## Local prerequisites

Supply these locally; none may be committed:

- the exact `Swing_DLL.xex` recorded in `config/target.json`
- Xbox 360 MSVC `16.00.10224.00`
- a Windows executable wrapper such as wibo on non-Windows hosts
- objdiff-cli `3.7.1`
- Jeff `0.3.5` built after applying `patches/jeff-v0.3.5-topspin4.patch`

Put the XEX at `orig/54540859/Swing_DLL.xex`, or pass another path explicitly. Both `orig/` game data and `work/` output are ignored.

## Reproduce

```sh
python3 tools/matching.py \
  --jeff /absolute/path/to/patched/jeff \
  --compiler-dir /absolute/path/to/X360/16.00.10224.00 \
  --wrapper /absolute/path/to/wibo \
  --objdiff /absolute/path/to/objdiff-cli \
  --fresh-analysis
```

The command verifies the XEX hash, runs Jeff, compiles all source units, generates an objdiff report over every Swing split unit, and rejects the result unless every named function is a 100% match at its recorded size. The full report stays under ignored `work/`; its durable summary is `config/54540859/match.json`.

## Measurement boundary

The match is 9,676 of 10,153,700 Swing code bytes (`0.095295310%`) and eighty of 47,250 objdiff functions (`0.169312180%`). The decomp-framework report has seventy complete-source units among 159 total units. These are matching-build counters, not the Ghidra discovery denominator in `config/progress.json`.

Where a function has an accompanying eight-byte `.pdata` range, it is also a
100% relocation-aware objdiff match. Leaf functions without an exception record
have a text-only split. The progress percentage intentionally counts code bytes
only.

## Link status

The canonical build compiles reconstructed source into Xbox 360 COFF objects
and compares them with split target objects. Its normal target does not invoke
`link.exe` or package an XEX. In objdiff reports, `complete_code` means that a
source-built object exists for that measurement unit; it must not be
interpreted as a successfully linked game executable.

A separate capability probe has now linked two exact reconstructed objects
with Xbox `link.exe 10.00.10224.00`. The result is a 2,560-byte Xbox PowerPC
PE32 DLL whose 64-byte `.text` contains eight matching functions. It uses
`/XEX:NO`, `/dll`, `/noentry`, `/nodefaultlib`, and `/OPT:NOREF`; it has no
imports or exports. `/OPT:NOREF` is necessary because an entryless DLL would
otherwise discard every unreferenced function. The ignored output hash and
machine-readable boundary are recorded in `config/link-status.json`. Running
this linker under macOS requires the
guest-side fake PDB service from
[decompals/wibo PR 110](https://github.com/decompals/wibo/pull/110).

After the canonical build has produced the two objects, reproduce the probe
with local, uncommitted tool paths:

```sh
/path/to/wibo-pr110 /path/to/X360/16.00.10224.00/link.exe \
  /nologo /dll /noentry /nodefaultlib /machine:PPCBE \
  /subsystem:XBOX /XEX:NO /OPT:NOREF \
  /out:work/two-object-link.dll \
  build/54540859/src/src/xbox360/online_feature_stubs.obj \
  build/54540859/src/src/xbox360/generate_cpu_results.obj
```

The path distinction is part of the proof: `build/54540859/src/` contains
objects compiled from this repository's source, while `build/54540859/obj/`
contains original split target objects used only for comparison.

A second probe passes all seventy source-built objects to the linker. Its map
contains all eighty exact public functions. Because the remaining game code and
data are not reconstructed, this probe requires `/FORCE:UNRESOLVED` and reports
seventy-nine unresolved external symbols. The linker emits a 14,336-byte
inspection PE with 10,280 bytes of `.text`; that section also includes eight
source helper functions and alignment, so it is not a new matching-progress
denominator. This is evidence that the current reconstructed subset can enter a
single Xbox link, not evidence of a usable module.

This proves that reconstructed COFF objects can be combined by the original
Xbox linker. It does **not** produce a replacement game module or runnable XEX,
and the generated binary is deliberately not committed.

The untouched target objects provide the rest of the module only as comparison
evidence. An actual relink track still needs a complete and ordered object set,
resolved imports and linker directives, XEX image packaging/signing, and
runtime verification. Until those gates exist, this repository reports exact
object matches and the minimal PE link proof rather than claiming a runnable
linked build.
