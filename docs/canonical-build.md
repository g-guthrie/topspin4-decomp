# Canonical build and objdiff workflow

This repository now uses the same Jeff template structure as the Xbox 360
projects indexed by decomp.dev:

- `configure.py` describes tools, versions, compiler flags, and object status.
- `config/54540859/config.yml` describes the user-owned Swing XEX and Jeff
  symbol/split databases.
- `config/54540859/objects.json` maps split objects to reconstructed sources.
- `build.ninja` and `objdiff.json` are generated views, not handwritten state.
- `build/54540859/report.json` is the objdiff report consumed by decomp.dev.

## Local setup

Place the verified Swing module at `orig/54540859/Swing_DLL.xex`. Its expected
SHA-256 is
`dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`.
Do not commit it.

Jeff 0.3.5 needs the repository patch for this executable:

```sh
git clone --branch v0.3.5 https://github.com/rjkiv/jeff.git work/jeff
git -C work/jeff apply ../../patches/jeff-v0.3.5-topspin4.patch
cargo build --release --manifest-path work/jeff/Cargo.toml
```

Generate the canonical build files using explicit local tool paths:

```sh
python3 configure.py \
  --dtk work/jeff/target/release/jeff \
  --compilers work/matching-tools/compilers \
  --wrapper work/matching-tools/wibo \
  --objdiff work/matching-tools/objdiff-cli
ninja
```

The generated Ninja file serializes Xbox 360 compiler invocations in an
`msvc_pool` of depth one. The compiler and wibo use shared `_CL_*` temporary
files and can hang when several source objects compile concurrently.

The tracked `config/54540859/symbols.txt` is the full Jeff-generated symbol
database, so normal builds use `quick_analysis: true`. The reviewed bootstrap
names remain separately preserved in `symbols.seed.txt`; use `tools/matching.py
--fresh-analysis` to reconstruct the full database from that seed. `ninja`
splits the XEX, regenerates `build.ninja` and `objdiff.json`, compiles the
tracked source, generates `build/54540859/report.json`, and prints progress.

## decomp.dev visualization

decomp.dev does not infer its color map from source files. A successful GitHub
Actions run uploads the generated objdiff `report.json` as a workflow artifact.
The site reads that report's units, sections, functions, sizes, and match
percentages. The treemap then colors matching code and unmatched code according
to the report. Accordingly, `objects.json`, the split output, and an honest
whole-module report determine what appears on the website.

At project level, rectangle area is proportional to each unit's
`measures.total_code`, and color is derived from
`measures.fuzzy_match_percent`. Selecting a unit drills into function
rectangles, where area comes from `function.size` and color again comes from
the function match percentage. `metadata.source_path` supplies the link back to
the exact source revision on GitHub. No project-specific map code is needed.

For eventual ingestion, a completed default-branch push workflow must upload
the report in an artifact named `54540859_report` (the hyphen form is also
accepted). The repository must be public before decomp.dev project management
can add it. This repository intentionally has no report-upload workflow yet:
CI still needs a private, lawful source for the user-owned XEX, Xbox compiler,
and patched Jeff binary. The repository remains private and no decomp.dev
submission has been made.

decomp.dev's public project listing currently filters projects below 0.5%
matched code. This does not prevent report ingestion or the treemap from
working, but it means the project should reach roughly 50,769 exact Swing code
bytes before expecting it in the public list.
