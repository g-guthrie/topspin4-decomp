# Reproduce the exact-code publication set

Version 25 October 2026. Branch measurements: **13,793 functions, 1,155,808 / 10,153,700 code bytes (objdiff-reported 11.3831215%), 11,598 source objects and 21,576 report units**. Compared with public branch `94748f2946b876c0629ca3f628f74fd296adcf75`, this adds **11,396 functions / 1,089,572 bytes**. Upstream `553f783` had 245 / 16,360 bytes. These comparisons count code identity; original ABI, types and most behavior remain unproven.

## Private prerequisites

Supply your own files locally. Never commit their contents or generated objects.

| Input | Tested SHA-256 or version |
|---|---|
| `Swing_DLL.xex` | `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44` |
| Xbox compiler directory 16.00.10224.00, including its companion DLLs | `cl.exe`: `6c27181a805dee13d0c9515efc00812d92f9c504cd1158eaf1f338d9f651f198` |
| ATL100 runtime companion, needed by the single `/TP` unit | `81bc7479b974658741f7d1b9a321a9d1303b2c95416b5170eee74fef09280875` |
| Jeff 0.3.5 plus `patches/jeff-v0.3.5-topspin4.patch` | Tested Windows binary: `c3bece150b9c88e2a052955646a21a777d2d9dd15689ba05b4ad265c0dec83c4` |
| objdiff-cli 3.7.1 | Tested Windows binary: `97f906acf83442040e3624688341f821238db367c9dba7585213d301216310d2` |
| Python | Local checks used Python 3.13.11; CI config uses 3.12 |

Jeff's upstream tag is `v0.3.5` (`a7b667e29cce75c4c6329624b398c05c6b163d36`); [canonical-build.md](canonical-build.md) gives its patch/build commands. Rebuilding Jeff itself was not tested in this update. Its pinned prebuilt binary was used. No proprietary SDK header is shipped or required by the new units; their minimal guest declarations are original project code. Keep the ATL runtime locally on `PATH`. Compiler flags are `/nologo /c /O2 /Oi`, with the recorded per-unit `/O1`, `/TP` and pre-existing flag exceptions.

## Build and compare (PowerShell templates)

Run from a complete Git checkout. Set these variables to your private input/tool paths: `$xex`, `$jeff`, `$compilerDir`, `$objdiff`, `$atlRuntimeDir`. No model or compiler cache is needed. Use a new ignored work directory so failed/partial receipts stay preserved.

```powershell
New-Item -ItemType Directory -Force work | Out-Null
@('@echo off', '%*', 'exit /b %ERRORLEVEL%') | Set-Content -Encoding ascii work/passthrough.cmd
$env:PATH = "$compilerDir;$atlRuntimeDir;$env:PATH"
python tools/matching.py --xex $xex --jeff $jeff --compiler-dir $compilerDir --wrapper work/passthrough.cmd --objdiff $objdiff --work-dir work/reproduce-20261025 --fresh-analysis --write-receipt
```

The compiler is deliberately sequential. Sharing its temporary directory between concurrent invocations is unsafe. Each expected function must have the exact recorded size and a 100% objdiff result. This is followed by independent raw checks below. `--write-receipt` records current sources/headers/config, DLLs alongside the compiler, private tool hashes, per-source flags and object hashes, and project/report hashes. It rejects changed inputs and refuses to overwrite an earlier receipt. The separately supplied ATL100 runtime resolved through `PATH` is not captured automatically: verify it manually against the SHA256 above before compiling the single `/TP` unit. An interrupted pair of receipt files is incomplete evidence; preserve it and choose a new work directory. A receipt is not acceptance.

## Independently check raw code, relocations and pdata

Jeff extracts a file-layout PE; the verifier needs an RVA-addressed image. Keep both private:

```powershell
New-Item -ItemType Directory -Force work/raw-input | Out-Null
Copy-Item -LiteralPath $xex -Destination work/raw-input/Swing_DLL.xex
& $jeff xex extract work/raw-input/Swing_DLL.xex
python tools/flatten_pe.py --input work/raw-input/Swing_DLL.dll --output work/raw-input/Swing_DLL.flat.pe
python tools/verify_exact_objects.py --repo . --pe work/raw-input/Swing_DLL.flat.pe --objdiff work/reproduce-20261025/objdiff-project/objdiff.json --out work/reproduce-20261025/INDEPENDENT-RAW.json
```

The tested extracted DLL hash is `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9`; the mapped image hash is `d78f393eb434b283040f002cd5346b0a70732df8b1fc0798c7a0be8546f27997`. The historical private flat image has a different full-image hash; its entire `.text`, `.pdata` and section headers were independently checked equal to this reproducible view. The checker accepts only those two pinned images.

Expected new packet: **11,368 core + 28 legacy = 11,396 exact functions / 1,089,572 bytes, zero holds and zero duplicate external function definitions**. The existing 2,397 public functions are regression-checked by the whole-module objdiff report; the new packet receives per-address full-extent/raw/effective-relocation/strict-pdata verification. Unknown relocation kinds, wrong addends, fragments, changed source/header pins and missing pdata expectations fail closed. Two exact address aliases are validated against the symbol registry and matching relocation slots; they are not arbitrary suffix-based name resolution or original ABI proof.

For a small worked example, choose a `local756` row in `local_20261025_units.json`: its source, source SHA, symbol, extent and pdata range are explicit, and the compiler command above emits the corresponding `fn_XXXXXXXX.obj`. The independent receipt records both COFF hashes and raw code digests for that same address. For a substantive family, the five published shot-request functions share `remaining_20261025/group-12-8865AE10/drafts/sr_common.h`; all five pass individually. Its sixth proposed member, `0x8826B640`, is excluded because the publication source context emitted 324 bytes against retail116. Another excluded address, `0x88884C08`, retains its specific float/double signature hold. Neither adds publication credit.

## Repository checks and observed validation

```powershell
python tools/check_no_game_data.py
python tools/validate_decomp_dev_report.py
python tools/validate_link_status.py
python -m unittest discover -s tests -v
```

This preparation compiled every proposed source, corrected 15 legacy header copies to their actual retained cohort versions, then rebuilt the legacy units and regenerated the whole-project comparison. A whitespace cleanup affected 726 source files; all 726 were recompiled. Final publication review also corrected stale status comments in 17 legacy units and their headers, followed by another rebuild of those 17 units and full raw verification. Unchanged, already freshly compiled objects were pinned and reused; every included function was independently raw-checked again. Failed attempts and the excluded member remain in the private review appendix. The documented extraction/flattening and the portable raw checker were run on the real complete final packet. The optional public receipt-writer mode was tested with isolated mutation fixtures; a fresh whole-corpus invocation of that newly added flag was not performed. The full real verification used the separately recorded clean private Windows Job receipt. Linux compilation, remote CI and gameplay were not run here.

The separate linker capability probe passed 11,598 source objects and reported all 13,793 matching symbols. Its inspection PE required `/FORCE:UNRESOLVED` (2,408 unresolved names / 24,025 references) and is **not runnable**. It is not committed. Source grouping remains provisional; exactness is not a type/layout solution or an original TU-boundary claim. See [methodology](exact-matches-20261025.md) for remaining work and the worker/evidence protocol.
