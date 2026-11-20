# Repository rules

- Never commit game images, executables, keys, firmware, raw extracted asset files (archives, .bin/XBin data, models, textures, audio, video), or proprietary SDK material.
- Exception (owner decision, 2026-11-14): readable gameplay value dumps generated from the disc (YAML/JSON/CSV of stats, curves, thresholds, templates, decision trees) may be committed under `data/gameplay/`, each with the generating command and source file sha256.
- Record claims as reproducible measurements: hash, size, command, and tool version.
- Keep Xbox 360 and PS3 work in separate target directories after the target is locked.
- Prefer small scripts with standard-library dependencies.
- A decompiled function is not reconstructed until behavior is named, typed, reviewed, and validated.
- New agents: read docs/START_HERE.md for setup, current state, priorities, and pitfalls.
