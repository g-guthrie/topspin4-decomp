# asm2c

Translates small Xbox 360 (PowerPC) functions from `tools/fn_asm.py`
disassembly into C, then verifies each candidate byte-for-byte with
`tools/fn_check.py` (the real MSVC 16.00.10224.00 compiler). Standard library
only. Unverified output is never written to `src/`.

Modules
- `cfg.py` - pure control-flow logic: instruction decoding, basic blocks,
  dominators / post-dominators, natural loops, boolean condition trees
  (`neg`, `cstr`) and `fold()` which merges chains of single-use condition
  blocks into `&&` / `||` conditions.
- `translate.py` - `gen(lines, env, mode, orient, infer_signed, vol)`: a
  symbolic executor (registers hold C expressions, loads become lazily
  materialised locals) driven by a structurizer. Handles getters/setters,
  thunks, call sequences, if / else / early return, short-circuit `&&`/`||`,
  shared tails (branches to one block), diamonds (phi variables), `while` and
  `do ... while` loops (loop-carried registers become `lvN` variables),
  integer/float basics, record forms (`srawi.`, `mr.`, `subic.` ...), indexed
  loads/stores, `rlwinm`/`rlwimi`/`clrrwi`/`mulli`/`divw`, vcall thunks.
  Raises `Skip(reason)` otherwise; the reason is the failure category.
- `source.py` - candidate selection (`fn_*` symbols in `.text`, size limit,
  `work/gen_exclude.txt` addresses and header ranges) and cached disassembly.
- `emit.py` - renders results into `.c` / `.cpp` files, runs `fn_check` (with
  compiler flags), drops functions that fail to compile and retries, host
  `cc` / `c++` syntax check.
- `run.py` - the CLI pipeline.

Usage

    python3 tools/asm2c/run.py --prefix fk2 --family K2 --work /tmp/w     # everything <= 0x100
    python3 tools/asm2c/run.py --limit 300 --no-final --work /tmp/w       # quick trial
    python3 -m unittest tests.test_asm2c

Search space. `run.py` walks every compiler flag set (`--flagsets ,O1`: base
`/O2 /Oi` and `/O1`; many original modules were built with `/O1`, which picks
different registers) and every variant (`--variants`), translating the still
unmatched functions and checking only translations whose C text has not been
tried before for that flag set. A variant is `<mode><orient>[letters]`:
- mode 0/1/2: how many argument registers a call is given (callee prefix scan
  only / plus contiguously written registers / every register up to the highest
  written one);
- orient 0/1: which arm of an if/else becomes the `if` body;
- `u`: do not infer `int` types from signed compares (cmpwi);
- `v` / `V` / `L`: make stores / loads+stores / loads `volatile`, which freezes
  the original access order (the scheduler otherwise reorders independent
  accesses; this alone matched ~500 constructor-style functions).
Matches are written to `src/xbox360/<prefix>[_cpp][_o1]_NNN.c[pp]` with specs in
`work/specs/<family>/` (MATCH functions plus RENAME lines, "flags" lists the
compiler flags). Functions that call each other are never placed in the same
file (the compiler would inline the callee in the integrated build).
State is cached in `--work` (translations' text digests, matches, disassembly)
so reruns resume; use `--fresh` to discard it. Requires a completed
`tools/matching.py` run (split objects) and `work/matching-tools`.
Names are `ts4_<kind>_<detail>_<ADDR>`; do not commit game data.

Findings worth knowing
- Originals that build image addresses from a bare `lis 0x88xx` (no REFHI
  relocation, e.g. the 0x88A00000 unit) have no relocations in the split
  object; `fn_check` compares relocation layouts, so they can never match.
  `translate.unrelocated()` reports them as `unrelocated original`.
- `lwz r12,0(r3); lwz r11,N(r12); mtctr r11; bctr` is the compiler-generated
  thunk of a pointer to a virtual member (`??_9Class@@$B...AA`). It is matched
  from a `.cpp` by taking `&Class::slotN` of a class with N/4 earlier virtual
  functions (`emit.vthunk_name` computes the symbol that `fn_check` must map).
  An ordinary C++ virtual call does not use r12, so only these thunks need it.
- Volatile stores reproduce the original store order of constructor-style
  initialisers; a signed compare (cmpwi) needs an `int` operand type.
