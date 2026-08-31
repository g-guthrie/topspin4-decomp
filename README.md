# Top Spin 4 decompilation

[![Repository guard](https://github.com/g-guthrie/topspin4-decomp/actions/workflows/guard.yml/badge.svg)](https://github.com/g-guthrie/topspin4-decomp/actions/workflows/guard.yml)
[![Code progress](https://decomp.dev/g-guthrie/topspin4-decomp.svg?mode=shield&measure=code&label=Code)](https://decomp.dev/g-guthrie/topspin4-decomp)

Clean-room reverse engineering and source reconstruction of *Top Spin 4*.

## Status

Xbox 360 retail baseline locked and imported into Ghidra. The current analysis denominator is 41,795 discovered functions across three XEX modules. Two hundred seventeen functions have reviewed names. One hundred eighty-eight reconstructed functions now compile to 100% code matches: 14,216 of 10,153,700 measured Swing code bytes (`0.14000808%`).

The selected build is title ID `54540859` (`TT-2137`), media ID `60819732`, executable version `0.0.0.3`. See [docs/targets.md](docs/targets.md), [docs/analysis-status.md](docs/analysis-status.md), the [canonical decomp.dev-style build](docs/canonical-build.md), and [matching build instructions](docs/matching-build.md). The first active investigation maps the dormant server-delivered patch path in [docs/title-server-patch.md](docs/title-server-patch.md); the separate Loader split is documented in [docs/loader-analysis.md](docs/loader-analysis.md). Official updates and optional content are tracked separately in [docs/additional-content.md](docs/additional-content.md); they are not part of the baseline.

The public progress artifact in `reports/54540859/report.json` contains measurements, unit sizes, and exact-match metadata only. GitHub Actions validates and uploads it for decomp.dev; it contains no original executable bytes.

## Boundaries

This repository contains only original source, analysis notes, symbols, hashes, and tooling. It must never contain game images, extracted executables, keys, firmware, proprietary SDK files, or copyrighted game assets. Contributors must supply their own lawfully obtained game copy locally.

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
