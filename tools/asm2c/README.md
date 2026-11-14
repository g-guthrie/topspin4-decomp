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
- mode 0/1/2/3: how many argument registers a call is given (callee prefix scan
  only / plus contiguously written registers / every register up to the highest
  written one / only the contiguously written ones, for variadic callees whose
  prefix saves r6..r10);
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

Round K3 additions (all behind unit tests in `tests/test_asm2c.py`)
- counted loops: `mtctr`/`bdnz`/`bdz` become a counter variable `cN` and a
  `do { ... } while (--cN != 0)` latch; update-form accesses (`lwzu`, `stbu`, ...) bump
  the base register; `break` out of loops (`if (c) break;`), loops that end in a
  conditional back edge although the header also tests (`while (c) { ...; if (!d) break; }`),
  a fall-back from the while to the do-while form for loops with early returns, and loop
  exits that jump to a return block shared with the normal exit;
- registers loaded by an absorbed (short-circuit) condition block and still needed
  afterwards: `gen()` retries with those blocks kept as nested ifs (`strict`);
- typed stack locals: byte/half/float/double accesses and spills that are not covered by an
  `addi rX,r1,..` array get their own word array accessed through casts; frameless leaf
  functions use the red zone (`locm10` for -0x10(r1)); conversions through a stack slot
  (`extsw/std/lfd/fcfid/frsp`, `fctiwz/stfd/lwz`) are folded into casts without a local;
- `ld` getters return `ts4_u64`; VMX (lvx128/stvx128 and the ALU ops of `ts4_vector.h`) for
  call-free, loop-free functions; interlocked `mfmsr/mtmsrd/lwarx/stwcx.` sequences become
  `_InterlockedExchange/Increment/Decrement/ExchangeAdd`; float phi variables (`pfN`); floats in
  loops when no float register is carried around the back edge; `clrlslwi`;
- budget: `gen()` gives up (`too big`) after 2500 symbolically executed instructions, because
  arms that never rejoin duplicate the code behind them; `--max-size 0x300` is practical;
- `emit.cc_ok` also runs clang and passes `-Wno-deprecated-non-prototype`.

Findings worth knowing
- A function whose original builds an image address from a bare `lis 0x88xx`
  (no REFHI relocation) cannot match: `fn_check` compares relocation layouts
  (`translate.unrelocated()` reports `unrelocated original`). Until the COFF
  reader honoured relocation-count overflow (tools/xcoff.py, commit 97edd51) this
  hit ~7,100 functions of the 0x88A442B8+ unit; rerun with a purged disassembly
  cache if you still have one from before that fix.
- `lwz r12,0(r3); lwz r11,N(r12); mtctr r11; bctr` is the compiler-generated
  thunk of a pointer to a virtual member (`??_9Class@@$B...AA`). It is matched
  from a `.cpp` by taking `&Class::slotN` of a class with N/4 earlier virtual
  functions (`emit.vthunk_name` computes the symbol that `fn_check` must map).
  An ordinary C++ virtual call does not use r12, so only these thunks need it.
- Volatile stores reproduce the original store order of constructor-style
  initialisers; a signed compare (cmpwi) needs an `int` operand type.
