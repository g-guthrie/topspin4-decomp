# Start here (agent handoff)

Read `AGENTS.md` first, then this file. It tells a new agent, especially one
with the user's own game disc available locally, how to get set up, what is
done, and what to do next.

## 1. Goals, in the user's priority order

1. **Extract the gameplay "essence"** of Top Spin 4 (Xbox 360, title
   `54540859`): ball physics, shot launch and error, reach and interception,
   volleys, movement, swing timing, rules, plus skeletons, every shot and movement
   animation (with racket-contact markers), shot templates and tuning tables.
   It should come out as documented C and open data formats (JSON and glTF), so
   it can drive new ports (browser, iPhone, others).
2. **Retune the gameplay.** The aim is that every shot has a purpose, no build can
   be min-maxed, and outcomes match real tennis (see `docs/tuning/research.md`).
   The first target is the *original game running unchanged under Xenia with
   modified data files*, because most tuning lives in data, not code.
3. **Full matching decompilation** of `Swing_DLL.xex`, measured by objdiff,
   continues in parallel.

## 2. Current state (commit at the head of `claude/eloquent-planck-ydqo96`, PR #12)

- **Matching.** 14,300 exact Swing functions, 965,440 of 10,153,700 code bytes
  (`9.50825800%`). Every one is verified by `tools/matching.py` and reaches the
  forced link map (`config/link-status.json`). The canonical numbers are in
  `config/progress.json`.
- **Gameplay.** This is documented in `docs/gameplay/README.md`, with one note
  per package plus readable drafts in `src/xbox360/drafts/`. Highlights:
  - **Ball flight.** It is closed-form, *not* Havok. The spec and reference C are
    validated bit for bit against the original (`docs/gameplay/gp4b.md`,
    `src/xbox360/drafts/gp4b_ball_model.c`).
  - **Shot outcome.** In/Out/Net/Let is a pre-launch dice roll against
    per-player error values. Those values are produced by **data-driven
    analyser graphs** (ShotDifficulty, BaselineTimingAbility, FatigueIngame,
    LetProbability, ...), so the retune is mostly a data edit
    (`gp4b.md` section 10, `gp8.md`).
  - **Reach and selection** are covered in `gp2.md`, the movement planner in
    `gp3.md`, and the swing animation and contact timing in `gp7.md`.
  - **Most numbers are in the game data**, not the code: shot templates, reach,
    preparation and turn tables, scoring weights, and drag and gravity.
- **Data formats.** These were specified from the loader code but **barely
  tested on real files** (`docs/gameplay/df.md`). The readers are in
  `tools/ts4data/` (`xbin.py`, `arc.py`, `hkx.py`).
  - `arc.py` and `xbin.py` parsed files from Title Update #1 correctly.
- **Title Update #1.** It is recorded in `docs/additional-content.md`, and
  `tools/stfs.py` reads it.

### Second target: Loader_DLL

`Loader_DLL.xex` (4,650,436 code bytes, 17,215 functions) is now a matching
target alongside Swing, with its own pipeline (`tools/loader_matching.py`),
config (`config/54540859/loader/`) and sources (`src/loader/`). See
`docs/loader-analysis.md`. Together the two modules are about 14.8 MB of code.

## 3. Setup on a local machine

Everything below `orig/`, `work/` and `build/` is git-ignored. Never commit game
files, extracted data, SDK-derived tables or compiler binaries.

1. **Executable.** Put your `Swing_DLL.xex` (SHA-256
   `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`) at
   `orig/54540859/Swing_DLL.xex`.
2. **Tools.** Use `tools/download_tool.py`, or `configure.py`, which uses the
   same tool. On a Mac that already has these tools from the earlier setup, just
   reuse them.
   ```sh
   mkdir -p work/matching-tools && cd work/matching-tools
   python3 ../../tools/download_tool.py compilers compilers --tag 20260305   # X360/16.00.10224.00
   python3 ../../tools/download_tool.py wibo work_wibo --tag 1.0.0
   python3 ../../tools/download_tool.py objdiff-cli objdiff-cli --tag v3.7.1
   python3 ../../tools/download_tool.py binutils binutils --tag 2.42-1
   cd ../..
   git clone --branch v0.3.5 https://github.com/rjkiv/jeff.git work/jeff
   git -C work/jeff apply ../../patches/jeff-v0.3.5-topspin4.patch   # also rebuilds jump-table relocations
   cargo build --release --manifest-path work/jeff/Cargo.toml
   cargo build --release --manifest-path tools/ppcdis/Cargo.toml --target-dir work/ppcdis/target  # VMX128 disassembly
   ```
   On Linux, `fn_asm.py` and `fn_check.py` expect `work/matching-tools/work_wibo`,
   `compilers/` and `binutils/`.
3. **Linker probe (optional).** This needs wibo built from
   `decompals/wibo` commit `a91b26e05df7e3ee67e684d96b266b1aba13f3e3` (PR 110).
   On Linux that build needs libclang, lld and the `i686-w64-mingw32-g++` cross
   compiler. Configure it with
   `cmake --preset release64 -DLIBCLANG_LIBRARY=<path to libclang.so.N> -DCMAKE_EXE_LINKER_FLAGS=-fuse-ld=lld`.
4. **Verify.**
   ```sh
   T=$PWD/work/matching-tools
   python3 tools/matching.py --fresh-analysis --jeff work/jeff/target/release/jeff \
     --compiler-dir $T/compilers/X360/16.00.10224.00 --wrapper $T/work_wibo --objdiff $T/objdiff-cli
   # expect: Matched 14300 functions: 965440/10153700 code bytes (9.50825800%)
   python3 -m unittest discover -s tests
   ```

## 4. With the disc: first steps (the most valuable work right now)

1. **Extract the disc.** Use `python3 tools/xiso.py list <image.iso>` and then
   `extract <image.iso> orig/54540859/disc` (or copy an existing extracted
   folder there). Record the hash, size and command of every file you rely on,
   as `AGENTS.md` requires.
2. **Follow the checklist** in `docs/gameplay/df.md` section 8:
   - grep every `.bin` for the shot-template kind hashes `0x5D90675B`,
     `0x2DB3EB6F`, `0x50B89452` and `0xC1965E5C`, and for the curve type
     `0xF9F12A60`, to find the shot template table;
   - `python3 tools/ts4data/xbin.py info|scan` on `Animations.bin`,
     `AnimationsInterface.bin`, `Physics.bin` and `Global.bin`;
   - `python3 tools/ts4data/arc.py list` on each `.arc` (path hashes are crc32 of
     the lower-cased path, see `df.md` 2.2);
   - `tools/ts4data/hkx.py` on one `Media\Animation\AOD\<id>.hkx`. This needs
     `work/havok55_classes.json`, which is SDK-derived and therefore local only.
     Regenerate it from your `Swing_DLL.xex` with the procedure in `df.md` 5.4.
3. **Fix the readers** against the real files and add tests that use only
   synthetic data.
4. **Export** to `work/` (never committed):
   - shot template rows (feed them into the ball model);
   - the analyser graphs (error, difficulty, fatigue, let);
   - reach, preparation and turn tables (2-D piecewise-linear, `df.md` 4.4);
   - animation records with their EventRacket times;
   - skeletons and clips as glTF (the compressed Havok animation formats
     are still to be decoded).
5. **Fill in the tuning table.** For each lever in the last section of
   `docs/tuning/research.md`, compare the game's current value, the real-tennis
   value and the proposal.
6. **Runtime oracle (if possible).** Run the game in Xenia and dump the ball state
   (`ball+0x4C0..0x4DC`: dispersion, radius, drag, gravity) and some recorded
   rallies to validate the models.

## 5. Matching workflow (one batch)

```sh
python3 tools/fn_asm.py fn_XXXXXXXX                       # original asm with relocations
python3 tools/fn_check.py src/xbox360/foo.c ts4_name=0xADDR [...] [--flags /GS-]
# write work/specs/<FAMILY>/<stem>.json: {"source","flags","functions":{name:addr},"renames":{}}
python3 tools/fix_refs.py work/specs/<FAMILY>/*.json      # update placeholder references
python3 tools/integrate_match.py work/specs/<FAMILY>/*.json
python3 tools/matching.py --fresh-analysis ...           # the authority; must pass
python3 tools/sync_progress.py                           # match.json, progress, README, report.json.gz
python3 tools/link_probe.py --wrapper <wibo-pr110> --linker-dir <X360 dir> --write  # optional
python3 -m unittest discover -s tests && python3 tools/validate_link_status.py \
  && python3 tools/validate_decomp_dev_report.py && python3 tools/check_no_game_data.py
```

- **Bulk generator.** `tools/asm2c` matched more than 10k small functions; see
  `tools/asm2c/README.md`.
- **Agent briefs.** Briefs for subagents are in `docs/agents/`.

### Permutation search

When a function misses an exact match by a few instructions of scheduling or
register allocation, mark the variants in comments and let `tools/permute.py`
search them (it scores with `fn_check`'s own comparison, compiles `-j 4` at a
time, and never edits the input):

```sh
python3 tools/permute.py src/xbox360/foo.c ts4_name=0xADDR [--flags /GS-] [--flags-sweep] [-j 4] [-n 400] [--time 900]
TS4_MATCHING_DIR=work/loader python3 tools/permute.py src/loader/foo.c name=0x83...   # Loader
python3 tools/permute.py src/xbox360/foo.c ts4_name=0xADDR --info                      # show the search space only
```

Markers (all comments, so the file still compiles unchanged):
`/* PERM_BEGIN */ s1; s2; /* PERM_END */` (reorder independent statements;
`PERM_BEGIN(strict|free)` change the dependency check), `/* PERM_DECLS */ ...
/* PERM_DECLS_END */` (declaration order), `/* PERM_ALT(i++|++i) */i++/* PERM_ALT_END */`
(inline alternatives: operand swaps, loop forms, `__forceinline|`, even whole
statements without the `;`), `/* PERM_TYPE(int|unsigned|short) */ int x;`,
`/* PERM_VOLATILE */` (inserts `volatile `), and `--flags-sweep ["/O1" ...]`
for compiler flags. Small spaces are enumerated; larger ones are searched by
randomised hill climbing on the differing-instruction count within the
`-n`/`--time` budget. The winner is written to `work/permute-out/<stem>.perm.c`
(else the best near-miss to `<stem>.best.c`); confirm it with the printed
`fn_check` command. Read `python3 tools/permute.py --help` for the full syntax.

## 6. Pitfalls we hit (read before integrating)

- **Same-file callees get inlined.** After `fix_refs.py`, a call to a function
  defined in the same file can be inlined or given a private register
  convention, and the match breaks. Either mark the callee
  `__declspec(noinline)` under `_MSC_VER`, or move it to its own file
  (`tools/split_selfrefs.py`). The reverse also happens: some callers *only*
  match when the callee is in the same file, because the original compiler
  analysed registers within one translation unit.
- **Fresh analysis after renames.** Run `matching.py --fresh-analysis` after any
  rename; otherwise the cached analysis keeps the old names and functions go
  "missing".
- **Stale split.** `fn_asm.py` and `fn_check.py` read `work/matching/split`.
  Re-run `matching.py` to refresh it after integrating, or old names show up.
- **Jump-table switches.** MSVC embeds the table in `.text` right after the
  `bctr`, with one ADDR32 relocation per word against a local `$LN` label. The
  XEX has no usable base relocations (the `.reloc` section of the decompressed
  PE is 315 KB of high-entropy data), so the patched Jeff rebuilds those
  relocations from the table itself, gives every case block a `$LN<addr>`
  label, writes `jumptable_*` as plain labels (not data symbols that split the
  function for objdiff), zeroes the table words in the split `.text` like a
  real MSVC object, and extends leaf functions (no pdata) over their case
  blocks. Run `TS4_MATCHING_DIR=work/matching-jt python3 tools/fn_check.py ...`
  against a split made with that Jeff; `fn_check.py` then accepts a candidate
  `$LN` reloc when the label sits at the same offset in the function as the
  target address. Existing sizes in `symbols.txt` are stale for the five
  functions listed in `docs/matching-build.md` (case blocks that were split off
  as separate `fn_` symbols): refresh those lines from a fresh analysis before
  `integrate_match.py`. See `src/xbox360/jt_switch_flags.c` for a worked example.
- **Compact switch tables.** Small switches can compile to an 8/16-bit offset
  table in `.rdata` that MSVC names `$T<n>` (the target has a `jumptable_*` data
  symbol). `fn_check.py` accepts the `$T` relocation when the table's bytes equal
  the target's, and resolves `$LN<address>` case labels from the name when
  `symbols.txt` lacks them. zlib 1.1.x `inflate`, `inflate_blocks` and
  `inflate_codes` (both modules, `/O1`) are worked examples.
- **`__vector4`/VMX128** used to block the ball-flight functions. Solved: include
  `src/xbox360/ts4_vector.h`, which is our own declaration of a `passinreg` 16-byte
  struct plus `#pragma intrinsic` prototypes. Dereferencing a `__vector4 *` emits
  `lvx128`/`stvx128`, and `__vaddfp`, `__vmaddfp` and the other intrinsics emit
  their VMX128 instructions. Add intrinsics to the header as needed, verifying
  each with `fn_check.py`.
- **Host syntax test.** `tests/test_symbol_map.py` compiles every
  `src/xbox360/*.c` with host `cc -Werror`. Guard MSVC-only declarations
  (`memset`, `strlen`, `__declspec`) with `#ifdef _MSC_VER`.
- **Public progress report.** It is `reports/54540859/report.json.gz`, written by
  `sync_progress.py`; CI decompresses it for decomp.dev.

## 7. Coordination with the cloud session

A cloud session still pushes to `claude/eloquent-planck-ydqo96`. A
generator-improvement run is in progress there and will add
`src/xbox360/fk2_*.c` plus `tools/asm2c` changes.

- **Branching.** Branch from the latest `claude/eloquent-planck-ydqo96` and pull
  before integrating.
- **Conflicts.** `config/54540859/*`, `tools/matching.py` and `config/progress.json`
  conflict easily, so integrate on top of the latest head and re-run the pipeline.
- **Prefixes.** Use new family prefixes for your sources, for example `d1_`,
  `gpd_`, so they never collide with the existing `fa_`..`fk_`, `fk2_`, `gp*_`
  and `r1_`..`r6_`.

## 8. Document map

| Path | Contents |
|---|---|
| `docs/gameplay-map.md` | Subsystem map of Swing (some details corrected by the gameplay notes) |
| `docs/gameplay/` | Per-package gameplay notes, data format spec (`df.md`) |
| `docs/tuning/research.md` | Tuning research and proposed numbers |
| `docs/matching-build.md`, `docs/canonical-build.md` | Build and measurement details |
| `docs/additional-content.md` | Title update and DLC records |
| `THIRD_PARTY_NOTICES.md` | Expat and zlib notices for derived sources |
