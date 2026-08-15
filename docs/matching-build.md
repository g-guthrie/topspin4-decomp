# Matching build

The first seventeen matching measurement units cover online feature stubs, session state, Pro Challenge, title-server, player-visibility, minigame, and King of the Court callbacks from the locked `Swing_DLL.xex`. Xbox 360 MSVC `16.00.10224.00` with `/O2 /Oi` reproduces all 1,820 code bytes across twenty-six functions exactly.

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

The match is 1,820 of 10,153,700 Swing code bytes (`0.0179245%`) and twenty-six of 47,280 objdiff functions (`0.054991543%`). These are matching-build counters, not the Ghidra discovery denominator in `config/progress.json`.

Each accompanying eight-byte `.pdata` range is also a 100% relocation-aware objdiff match. The progress percentage intentionally counts code bytes only.
