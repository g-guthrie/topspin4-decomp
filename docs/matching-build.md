# Matching build

The first four hundred forty-three matching measurement units reproduce all 1,033,064 code bytes across fifteen thousand four hundred forty-two functions exactly.

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

The match is 1,033,064 of 10,154,212 Swing code bytes (`10.17374800%`) and fifteen thousand four hundred forty-two of 46,736 objdiff functions (`33.0409130%`). The decomp-framework report has four hundred forty-three complete-source units among 12321 total units.

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

A second probe passes all four hundred forty-three source-built objects to the linker. Its map
contains all fifteen thousand four hundred forty-two exact public functions. Because the remaining game code and
data are not reconstructed, this probe requires `/FORCE:UNRESOLVED` and reports
13,822 unique unresolved external symbols across 19,775 references. The linker emits a 1,305,088-byte
inspection PE with 1,086,036 bytes of `.text`; that section also includes eighty-six
source helper functions (inline C++ constructors and allocation wrappers) and alignment, so it is not a new matching-progress
denominator. Linker outputs embed timestamps, so their hashes change between runs. Reproduce with `tools/link_probe.py`. This is evidence that the current reconstructed subset can enter a
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

## Jump-table switches

The Jeff patch rebuilds jump-table relocations and function extents for MSVC
switch tables embedded in `.text` (534 sites in Swing). Measurements, with the
patched Jeff 0.3.5 and objdiff-cli 3.7.1:

- A fresh analysis finds 552 `jumptable_*` objects instead of 520. All 534
  `mtctr`/`bctr` sites with an inline absolute table are covered except
  `0x888B3C10`, whose case blocks are matched functions in
  `symbols.seed.txt` (see below).
- Five functions grow to include case blocks that used to be separate `fn_`
  symbols: `fn_8849E168`, `fn_8865DA28`, `fn_8865DAC0`, `fn_886ED218`,
  `fn_8889CD00`.
- Table words get ADDR32 relocations against `$LN<address>` labels, are zeroed
  in the split object, and `jumptable_*` symbols are written as labels.
- `tools/fn_check.py` compares a candidate `$LN` relocation with the target by
  offset inside the function. Set `TS4_MATCHING_DIR` to use the split and
  symbols of an alternate `tools/matching.py --work-dir`.

