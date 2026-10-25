# Top Spin 4 decompilation

[![Repository guard](https://github.com/g-guthrie/topspin4-decomp/actions/workflows/guard.yml/badge.svg)](https://github.com/g-guthrie/topspin4-decomp/actions/workflows/guard.yml)
[![Code progress](https://decomp.dev/g-guthrie/topspin4-decomp.svg?mode=shield&measure=code&label=Code)](https://decomp.dev/g-guthrie/topspin4-decomp)

Clean-room reverse engineering and source reconstruction of *Top Spin 4*. That description applies to the project's established work; the units under `src/xbox360/matched/` were produced differently, as described in "Provenance of the matched-function units" below.

## Status

Xbox 360 retail baseline locked and imported into Ghidra. The analysis inventory is 41,795 discovered functions across three modules; the separate whole-Swing Jeff report measures 47,250 functions. There are 418 reviewed names and **13,793 exact code matches / 1,155,808 Swing code bytes (11.38%)**. This update adds 11,396 functions / 1,089,572 bytes to the previous public branch. The existing `reconstructed_functions` and `validated_functions` counters follow the repository's code-match convention: these additions establish code identity, effective relocations and `.pdata`, not original types, ABI or gameplay behavior. `typed_functions` remains zero. See [the current publication measurements](reports/54540859/publication-20261025.json), [methodology and limits](docs/exact-matches-20261025.md), and [reproduction](docs/reproduction.md).

The selected build is title ID `54540859` (`TT-2137`), media ID `60819732`, executable version `0.0.0.3`. See [docs/targets.md](docs/targets.md), [docs/analysis-status.md](docs/analysis-status.md), the [canonical decomp.dev-style build](docs/canonical-build.md), and [matching build instructions](docs/matching-build.md). The first active investigation maps the dormant server-delivered patch path in [docs/title-server-patch.md](docs/title-server-patch.md); the separate Loader split is documented in [docs/loader-analysis.md](docs/loader-analysis.md). Official updates and optional content are tracked separately in [docs/additional-content.md](docs/additional-content.md); they are not part of the baseline.

The public progress artifact in `reports/54540859/report.json` contains measurements, unit sizes, and exact-match metadata only. GitHub Actions validates and uploads it for decomp.dev; it contains no original executable bytes.

## Boundaries

This repository contains only original source, analysis notes, symbols, hashes, and tooling. It must never contain game images, extracted executables, keys, firmware, proprietary SDK files, or copyrighted game assets. Contributors must supply their own lawfully obtained game copy locally.

## Provenance of the matched-function units

The sources and headers under `src/xbox360/matched/` were written for this repository from disassembly listings of the retail module, with AI assistance. They are not the product of a separately established clean-room process, and they contain no game bytes, decompiler output or SDK files.

What is established and what is not:
- **Verified:** each function is checked by byte-exact matching. It compiles with the target compiler to a 100% objdiff match at its recorded size, and its effective relocations and original `.pdata` entry were checked equal.
- **Scope of the proof:** a match proves the code bytes, relocations and `.pdata` only.
- **Reconstructed or unknown:** names, prototypes, signatures, types, field roles and source groupings.
- **Method:** [docs/methodology.md](docs/methodology.md) describes how the units were produced, and [docs/reproduction.md](docs/reproduction.md) how to reproduce the matches.

The five `leaf_family_*.c` units are a separate supplement.
- **What they are:** 617 trivial 8- and 4-byte leaf functions (constant returns, single-word getters, no-op returns), each under its existing `fn_XXXXXXXX` name.
- **What is not known:** their original prototypes and roles. Their C bodies reproduce the instruction shape only.
- **Leaf, slot and constant addition (1,161 functions, 4,932 B).** Leaf functions were appended to these units and to `runtime_constant_slot_families.c` (27 no-op slots and the 4-byte `fn_881B3360` leaf), and twelve 32-bit constant returns were added in `constant_u32_family.c`. Each extent is byte-identical to the retail module. Scope: code identity only; semantic NOT_TESTED; reviewed for publication as exact code matches, without duplicate verification credit; original ABI and types not established.
- **Allocation-wrapper addition (180 functions, 21,936 B).** Two new units, `allocation_wrappers_88617d88.c` (156 functions) and `allocation_wrappers_fill.c` (24 functions), hold wrappers that call the `fn_88613268` allocator, each under its existing `fn_` name. Each extent equals the retail module once its relocations are resolved, and its `.pdata` entry is equal. Their declarations of `fn_88613268`, `fn_88617D88` and three address-only labels follow existing units; see [docs/methodology.md](docs/methodology.md) for the inconsistent allocator result type. Scope: code identity only; semantic NOT_TESTED; reviewed for publication as exact code matches, without duplicate verification credit; original ABI and types not established.
- **What they do not claim:** they carry no reviewed names and no understanding of behaviour beyond the exact code match.

## Start here

```sh
python3 tools/inventory.py /absolute/path/to/your/dump --output work/inventory.json
python3 tools/xex_info.py /absolute/path/to/default.xex
python3 tools/check_no_game_data.py
python3 -m unittest discover -s tests -v
```

With Ghidra 12.1.2 and the matching XEXLoaderWV extension installed, the complete local analysis pipeline is:

```sh
tools/analyze_xbox360.sh /absolute/path/to/extracted-game
```

`work/` is ignored. The local extraction and Ghidra project belong there. Never use an update, DLC package, or modified image as the reference executable without adding it as a separately hashed target.

## Definition of progress

Progress distinguishes reviewed names, semantic drafts, validated reconstructions, and exact compiler matches. Ghidra output and host-C syntax checks do not count as matching progress. “Complete source” in the generated report does not mean a runnable XEX has been linked; the current [object-build and link status](docs/matching-build.md#link-status) is explicit. The canonical counters live in [config/progress.json](config/progress.json).

## License

Original repository code and documentation are MIT-licensed. That license does not apply to *Top Spin 4* or any material owned by 2K, Take-Two, PAM Development, Sony, or Microsoft.
