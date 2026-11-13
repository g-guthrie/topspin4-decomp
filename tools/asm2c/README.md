# asm2c

Translates small Xbox 360 (PowerPC) functions from `tools/fn_asm.py`
disassembly into C, then verifies each candidate byte-for-byte with
`tools/fn_check.py` (the real MSVC 16.00.10224.00 compiler). Standard library
only. Unverified output is never written to `src/`.

Modules
- `translate.py` - pure translation (`gen(lines, env, mode, orient)`), a small
  symbolic executor. Covers getters/setters, address-of-global thunks, tail
  calls, this-adjusting and vtable-call thunks, straight-line call sequences,
  simple if / early-return / diamond shapes. Raises `Skip(reason)` otherwise;
  the reason is the failure category.
- `source.py` - candidate selection (`fn_*` symbols in `.text`, size limit,
  `work/gen_exclude.txt` addresses and header ranges) and cached disassembly.
- `emit.py` - renders results into `.c` files, runs `fn_check`, drops functions
  that fail to compile and retries, host `cc` syntax check.
- `run.py` - the CLI pipeline.

Usage

    python3 tools/asm2c/run.py --prefix fk --family K          # everything <= 0x100
    python3 tools/asm2c/run.py --limit 300 --no-final --work /tmp/w   # quick trial
    python3 -m unittest tests.test_asm2c

`run.py` tries translation variants (`--variants`, mode/orient pairs) in
order, keeps only functions that MATCH, then writes
`src/xbox360/<prefix>_NNN.c` and `work/specs/<family>/<prefix>_NNN.json`
(MATCH functions plus RENAME lines) and prints failure counts per category.
State is cached in `--work` (default system temp) so reruns resume; use
`--fresh` after changing the generator. Requires a completed
`tools/matching.py` run (split objects) and `work/matching-tools`.
Names are `ts4_<kind>_<detail>_<ADDR>`; do not commit game data.
