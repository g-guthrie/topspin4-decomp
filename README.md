# Top Spin 4 decompilation

Clean-room reverse engineering and source reconstruction of *Top Spin 4*.

## Status

Bootstrap only. No game code has been decompiled yet, and the target platform is intentionally not locked.

The first local candidate inspected is a 7,838,695,424-byte Xbox 360-style UDF image, not the PS3 layout used by RPCS3. See [docs/targets.md](docs/targets.md).

## Boundaries

This repository contains only original source, analysis notes, symbols, hashes, and tooling. It must never contain game images, extracted executables, keys, firmware, proprietary SDK files, or copyrighted game assets. Contributors must supply their own lawfully obtained game copy locally.

## Start here

```sh
python3 tools/inventory.py /absolute/path/to/your/dump --output work/inventory.json
python3 tools/check_no_game_data.py
python3 -m unittest discover -s tests -v
```

`work/` is ignored. Review the generated inventory, choose one exact platform/region/version, and then update `config/target.json` before extraction or decompilation begins.

## Definition of progress

Progress is counted by independently validated reconstructed functions—not lines emitted by a decompiler. The canonical counters live in [config/progress.json](config/progress.json).

## License

Original repository code and documentation are MIT-licensed. That license does not apply to *Top Spin 4* or any material owned by 2K, Take-Two, PAM Development, Sony, or Microsoft.
