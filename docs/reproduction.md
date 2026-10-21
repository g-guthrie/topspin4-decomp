# Reproducing the matching result

Guide version **3-next2** (2026-10-21); it goes with [methodology.md](methodology.md).
This branch carries the wave-1 change plus a **separate leaf supplement**: 617 trivial 8- and 4-byte leaf functions, with unknown prototypes and no publication approval yet (`publication_ready` false). The supplement claims no new-match credit. This branch also carries a **next-candidate addition**: 1,161 leaf, slot and constant functions (4,932 B; code identity only; semantic NOT_TESTED; reuse of prior independent verification; `publication_ready` false; zero ledger credit), and an **allocation-wrapper addition**: 180 functions in two units (21,936 B; code identity only; semantic NOT_TESTED; `publication_ready` false; zero ledger credit). The expected outputs below are for this branch. The wave-1 baseline values (the branch without the supplement, `cb59ab3`) are given next to them, labelled as such.
The commands below are the ones actually run for this change, on Windows 11 x64
with Python 3.13.11 (the CI uses 3.12). Each is followed by its expected output.
On Windows, write `python` wherever this guide says `python3`: there `python3`
usually starts the Microsoft Store stub instead of an installed interpreter.
The `sh` blocks in the quick start are POSIX **templates** (backslash line
continuation, `<…>` placeholders) and do not run in PowerShell as written. The
PowerShell 7.6 block after the quick start was run exactly as shown, with only
the paths changed.
Paths are written relative to the repository root, and `<…>` marks a path you
supply.

## What you need (supplied locally, never committed)

| input | check |
|---|---|
| `Swing_DLL.xex` from your own copy of the game | SHA-256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44` |
| Xbox 360 compiler directory `16.00.10224.00` (`cl.exe`, `c1.dll`, `c2.dll`, `1033/clui.dll`, `mspdbXX.dll` and the rest of the folder) | `cl.exe` SHA-256 `6c27181a805dee13d0c9515efc00812d92f9c504cd1158eaf1f338d9f651f198` |
| Jeff 0.3.5 with `patches/jeff-v0.3.5-topspin4.patch` | built from tag `v0.3.5` (`a7b667e29cce75c4c6329624b398c05c6b163d36`) as in [canonical-build.md](canonical-build.md). That build step was **not exercised** for this change. The Windows binary that was used reports `jeff 0.3.5 1ae97da6…` and has SHA-256 `c3bece150b9c88e2a052955646a21a777d2d9dd15689ba05b4ad265c0dec83c4`; a binary with that hash is the tested alternative. |
| objdiff-cli 3.7.1 | `objdiff-cli --version` prints `objdiff-cli 3.7.1` |
| a "wrapper" | On Linux or macOS this is wibo, as upstream documents (not exercised for this change). On Windows, a one-line pass-through batch file that runs its arguments: `@echo off` / `%*` / `exit /b %ERRORLEVEL%` |

The wave-1 units need no SDK headers and no `ATL100.DLL`.

## Quick start

1. **Repository checks** (template; PowerShell form below). These need no game data, but they must run in a git checkout: `tools/check_no_game_data.py` lists files with `git ls-files`, so it fails in an exported tree or archive.

   ```sh
   python3 tools/check_no_game_data.py
   python3 tools/validate_decomp_dev_report.py
   python3 tools/validate_link_status.py
   python3 -m unittest discover -s tests -v
   ```

   Expected output on this branch (wave-1 baseline: 439 exact functions, 34632 bytes, 594 units, 205 source objects):

   ```
   No tracked game-data candidates found.
   Validated decomp.dev report: 2397 exact functions, 66236/10153700 code bytes, 2168 units
   Validated link status: 213 source objects, 2397 exact functions, 66236 matching bytes
   ```

   - **Unit tests on Windows** (observed): `FAILED (failures=1, skipped=1)`, exit code 1. The failure is `test_external_work_directory_uses_relative_compiler_output`, because `/Fo` uses backslashes there; the base commit 553f783 fails the same test in the same way.
   - **Unit tests on Linux: expected, not verified on this revision.** Linux and the remote CI were not run for this revision. The expected result, by the CI configuration, is 15 tests with one skip, with the `/Fo` test passing.

2. **Full matching check** (template; PowerShell form below). It splits the module, compiles all 213 units, generates the objdiff report and rejects any listed function that is not at 100% at its recorded size.

   ```sh
   python3 tools/matching.py \
     --xex <Swing_DLL.xex> \
     --jeff <patched jeff> \
     --compiler-dir <16.00.10224.00 directory> \
     --wrapper <wibo or pass-through.cmd> \
     --objdiff <objdiff-cli> \
     --work-dir <scratch directory outside the repository> \
     --fresh-analysis
   ```

   - The run takes under two minutes on a 48-thread host.
   - The last line is: `Matched 2397 functions: 66236/10153700 code bytes (0.65233360%)`. Without the allocation-wrapper addition, it is `Matched 2217 functions: 44300/10153700 code bytes (0.43629417%)`. With the leaf supplement only, it is `Matched 1056 functions: 39368/10153700 code bytes (0.38772073%)`. On the wave-1 baseline it is `Matched 439 functions: 34632/10153700 code bytes (0.34107763%)`.
   - The exit code is 0.
   - The work directory contains game-derived split objects. Keep it private.

3. **Optional: regenerate the committed report** (template; PowerShell form below). The committed `reports/54540859/report.json` is derived from the generated `objdiff-project/report.json`:
   - Keep the top-level keys and every unit in the generated order, with each unit's keys unchanged.
   - In each unit, set `functions` to the entries whose `fuzzy_match_percent` is exactly `100.0`. A unit with no `functions` list gets `"functions": []` written as its last key.
   - Serialise with Python `json.dumps(report, separators=(",", ":"))`: no key sorting, default float formatting. Add exactly one trailing newline and no BOM.

   ```sh
   python3 -c "import json,sys; r=json.load(open(sys.argv[1])); [u.__setitem__('functions',[f for f in u.get('functions',[]) if f.get('fuzzy_match_percent')==100.0]) for u in r['units']]; open(sys.argv[2],'wb').write((json.dumps(r,separators=(',',':'))+chr(10)).encode())" <work-dir>/objdiff-project/report.json <out.json>
   git hash-object <out.json>
   git rev-parse HEAD:reports/54540859/report.json
   ```

   - The two hashes printed must be equal. Two independent runs on this tree produced the same file, and the same transformation reproduces the base commit's committed report byte for byte.
   - Compare git blob ids as shown, not the working file's SHA-256. A fresh Windows clone with `core.autocrlf=true` checks `report.json` out with CRLF line endings, which changes the working file's bytes.

4. **Optional: forced link probe** (`config/link-status.json`).
   - **Linker.** `link.exe` is the one in the same `16.00.10224.00` compiler directory, SHA-256 `5c970fc53998e620fc70c100ef2729cd59c8714f8b761eeac289cfa2fa3a5acf`.
   - **Git Bash.** Set `MSYS_NO_PATHCONV=1`; otherwise arguments such as `/nologo` are rewritten as paths. cmd.exe and PowerShell are not affected.
   - **Why a response file.** Every rebuilt object is linked, in `MATCHING_UNITS` order. Two hundred five absolute paths exceed the Windows command-line limit, so run the linker from `<work-dir>/rebuilt` with a response file that holds the bare object names, one per line, in `MATCHING_UNITS` order. The block below is a template; the tested PowerShell form follows the quick start.

   ```
   python3 -c "import tools.matching as m; print(chr(10).join(u['object'] for u in m.MATCHING_UNITS))" > <work-dir>/rebuilt/objects.rsp
   cd <work-dir>/rebuilt
   link.exe /nologo /dll /noentry /nodefaultlib /machine:PPCBE /subsystem:XBOX /XEX:NO /OPT:NOREF /FORCE:UNRESOLVED /MAP /out:probe.dll @objects.rsp
   ```

   - Run the first command from the repository root.
   - **Counting rules.** These are the definitions that reproduce the base commit's 218 / 373 / 22,528 / 17,176 / 8 exactly. "Unique unresolved external symbols" = distinct `LNK2001`/`LNK2019` message texts with the object-file prefix removed. "References" = all such lines. `.text` bytes = the section's VirtualSize. Static helpers = static function symbols in the map.
   - **Results on this branch:** 433 / 682 / 86,016 / 74,028 / 51. Without the allocation-wrapper addition: 342 / 587 / 59,904 / 52,000 / 51. With the leaf supplement only: 343 / 588 / 50,688 / 42,712 / 51. On the wave-1 baseline: 343 / 588 / 45,568 / 37,772 / 51.
   - **Output hash.** The output file's SHA-256 changes with every link, because of the link timestamp.

### The same steps in PowerShell (tested on Windows 11, PowerShell 7.6.6)

Replace the paths in the first lines with your own; the repository root must be the current directory.

```powershell
$Xex = 'D:\private\Swing_DLL.xex'; $Jeff = 'D:\tools\jeff.exe'; $Cl = 'D:\tools\16.00.10224.00'
$Wrap = 'D:\tools\passthrough.cmd'; $Objdiff = 'D:\tools\objdiff-cli.exe'; $Work = 'D:\scratch\work'
python tools/check_no_game_data.py
python tools/validate_decomp_dev_report.py
python tools/validate_link_status.py
python -m unittest discover -s tests          # Windows: FAILED (failures=1, skipped=1), see above
python tools/matching.py --xex $Xex --jeff $Jeff --compiler-dir $Cl --wrapper $Wrap --objdiff $Objdiff --work-dir $Work --fresh-analysis
# committed report form, then compare git blob ids (both lines must print the same id)
python -c 'import json,sys; r=json.load(open(sys.argv[1])); [u.__setitem__("functions",[f for f in u.get("functions",[]) if f.get("fuzzy_match_percent")==100.0]) for u in r["units"]]; open(sys.argv[2],"wb").write((json.dumps(r,separators=(",",":"))+chr(10)).encode())' "$Work\objdiff-project\report.json" "$Work\report.committed.json"
git hash-object "$Work\report.committed.json"
git rev-parse HEAD:reports/54540859/report.json
# link probe: an ASCII, LF-terminated response file of bare object names in MATCHING_UNITS order
python -c 'import sys,tools.matching as m; open(sys.argv[1],"wb").write("".join(u["object"]+chr(10) for u in m.MATCHING_UNITS).encode("ascii"))' "$Work\rebuilt\objects.rsp"
$Link = Join-Path $Cl 'link.exe'
Push-Location "$Work\rebuilt"
& $Link /nologo /dll /noentry /nodefaultlib /machine:PPCBE /subsystem:XBOX /XEX:NO /OPT:NOREF /FORCE:UNRESOLVED /MAP '/out:probe.dll' '@objects.rsp' > link.txt
Pop-Location
```

**Observed results**
- The three checks print the lines above.
- This block was run on the **wave-1 baseline tree**. There, `matching.py` ended with `Matched 439 functions: 34632/10153700 code bytes (0.34107763%)` (exit code 0) and both blob ids were `bd072ba189589396ff9b709143082dc445641fd3`. The linker exited 0, with 588 `LNK2001`/`LNK2019` lines in `link.txt` and a 45,568-byte `probe.dll`.
- **On this branch** the same commands give the following. These were checked with the same `matching.py` invocation, the report one-liner and the link probe run from a POSIX shell, not with this PowerShell block.
  - `Matched 2397 functions: 66236/10153700 code bytes (0.65233360%)`
  - both blob ids `e17d3b565f4a3e223d2a5712fd0b4b96916303fa` (the committed report's SHA-256 is `0d54ccdb8ae8c774e5d8d28e035a28068060907faf7eb7e9338086a887049b77`)
  - 682 unresolved lines and an 86,016-byte `probe.dll`

Quote `'@objects.rsp'` as shown: unquoted, PowerShell reads `@objects` as splatting.

## Directory and configuration schema (what a new match touches)

| file | entry per new function or unit |
|---|---|
| `src/xbox360/…/<unit>.c` | the source, compiled from the repository root |
| `tools/matching.py` `MATCHING_UNITS` | `{"source", "object", "symbols": {name: size}, ["extra_flags"]}` |
| `config/54540859/splits.txt` | `<source>:` block listing `.pdata` ranges (when the function has an exception entry), then `.text` ranges |
| `config/54540859/symbols.txt` | `fn_XXXXXXXX` renamed to the function name; the size must equal the extent |
| `config/54540859/symbols.seed.txt` | the new names, appended |
| `config/54540859/objects.json` | `"<source>": {"status": "Matching", "source": "<path below src/>"}` |
| `config/54540859/match.json` | one row per function plus the counters |
| `config/progress.json` | counters equal to `match.json` |
| `reports/54540859/report.json` | the committed report, see step 3 |
| `config/link-status.json`, `tests/test_canonical_build.py` | forced link probe counts |

The CI (`.github/workflows/guard.yml`) runs only the four checks of step 1. The matching check needs your local game copy and compiler, so its result is recorded in the pull request.

## Privacy and identity checks used before committing
- **Diff scan.** No file with a blocked suffix and no binary file. No absolute or private paths, decompiler tokens, raw instruction words, SDK includes or secrets in added lines.
- **Commit identity.** Every commit's author and committer is the contributor's GitHub no-reply address. No other address and no trailers appear anywhere in the log.
