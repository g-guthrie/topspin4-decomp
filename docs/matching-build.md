# Matching build

The first matching translation unit is `src/xbox360/title_patch.c` from the locked `Swing_DLL.xex`. Xbox 360 MSVC `16.00.10224.00` with `/O1 /Oi` reproduces all 56 code bytes of `ts4_script_title_server_get_patch` exactly.

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

The command verifies the XEX hash, runs Jeff, compiles the source unit, generates an objdiff report over every Swing split unit, and rejects the result unless the named function is a 56-byte 100% match. The full report stays under ignored `work/`; its durable summary is `config/54540859/match.json`.

## Measurement boundary

The match is 56 of 10,153,700 Swing code bytes (`0.0005515231%`) and one of 47,250 objdiff functions (`0.0021164021%`). These are matching-build counters, not the Ghidra discovery denominator in `config/progress.json`.

The accompanying eight-byte `.pdata` range contains a relocated function address and an exact unwind word. It is not claimed as an exact data match.
