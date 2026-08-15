# Matching build

The first twenty matching measurement units cover online feature stubs, session predicates, Pro Challenge, title-server, player-visibility, minigame, and King of the Court callbacks from the locked `Swing_DLL.xex`. Xbox 360 MSVC `16.00.10224.00` with `/O2 /Oi` reproduces all 1,920 code bytes across twenty-nine functions exactly.

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

The match is 1,920 of 10,153,700 Swing code bytes (`0.018909363%`) and twenty-nine of 47,280 objdiff functions (`0.06133672%`). These are matching-build counters, not the Ghidra discovery denominator in `config/progress.json`.

Where a function has an accompanying eight-byte `.pdata` range, it is also a
100% relocation-aware objdiff match. Leaf functions without an exception record
have a text-only split. The progress percentage intentionally counts code bytes
only.

## Link status

The current build compiles reconstructed source into Xbox 360 COFF objects and
compares them with split target objects. It does **not** yet invoke `link.exe`,
produce a replacement PE image, or package a runnable XEX. In objdiff reports,
`complete_code` means that a source-built object exists for that measurement
unit; it must not be interpreted as a successfully linked game executable.

The untouched target objects provide the rest of the module only as comparison
evidence. An actual relink track still needs a complete and ordered object set,
resolved imports and linker directives, a working Xbox linker invocation, and
XEX image packaging/verification. Until those gates exist, this repository
reports exact object matches rather than claiming a runnable linked build.
