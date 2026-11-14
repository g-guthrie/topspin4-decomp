# Matching-decomp agent brief (Top Spin 4, Xbox 360, Swing_DLL.xex)

Goal: write C (or C++) source that compiles with the original Xbox 360 MSVC 16.00.10224.00
to byte-identical code for as many functions in your assigned clusters as possible.
Repo: /home/user/topspin4-decomp. Read AGENTS.md and a few existing files in src/xbox360/
(e.g. script_callback_batch_g.c, tsu_update_profile.c, parse_u8_decimal_if_changed.c) for style.

## Your clusters
Each file work/clusters/<rep>.txt lists functions whose machine code is identical except for
relocation targets (callees/globals), in order of appearance in the code. One source pattern
(a macro instantiated per function) can match the whole cluster.

## Tools (all already working; do not reinstall anything)
- `python3 tools/fn_asm.py fn_XXXXXXXX` : original disassembly with relocation targets.
- `python3 tools/fn_check.py <source> name=0xADDR [name2=0xADDR2 ...] [--flags /GS-]`
  Compiles your source with the real compiler (base flags /O2 /Oi) and compares each defined
  function against the original. Prints MATCH/FAIL with a side-by-side diff, and RENAME lines.
  Exit 0 = all listed functions match. Safe to run concurrently. Takes a few seconds; for big
  files pass many mappings in one call.
- `python3 tools/sym_info.py xrefs SYMBOL | str 0xADDR | data 0xADDR 0xLEN | at 0xADDR`
  cross-references, strings, data words (with relocations) to help name things.

## How matching works / tips
- Prologue/epilogue helpers (__savegprlr_NN, __restgprlr_NN) are emitted by the compiler.
- Calls and global accesses are relocations; the target name in your source must equal the
  symbol name in config/54540859/symbols.txt OR be a new name for a placeholder symbol
  (fn_/lbl_/jumptable_), which fn_check reports as `RENAME old -> new`.
- Only rename a placeholder if every reference to it comes from your own clusters
  (check `tools/sym_info.py xrefs`). Otherwise use the placeholder name itself in the source,
  e.g. `extern void *lbl_88D45B38; void *fn_88613268(void *, int, int, int, int);`.
  Never invent a different name for an already-named symbol (ts4_*, g_ts4_*, memcpy...).
- Avoid float/double literals (they create __real@ constants); use the extern data symbol
  the original loads from instead.
- Structs passed/returned by value with user-defined copy ctors behave differently (see
  docs or experiment); C++ needs `extern "C"` on every function so names stay unmangled.
- Try compiler flags only if needed: /GS- (stack cookies), /O1, /GR- /EHs-c-.
- Branch-to-same-place patterns, register allocation and instruction order are sensitive to
  expression order, variable declarations, signedness, and types — iterate.

## Naming (required by AGENTS.md)
Every matched function needs a descriptive name of what it does plus its address for
uniqueness, e.g. `ts4_component_list_add_unique_8861C648`. Prefix all your names with ts4_.
Add a one-line comment above each pattern explaining the behavior, and comment each
instantiation with its original address (`/* Swing_DLL.xex 0x8861C648 */` style or a table).
Name parameters and struct fields by role. Do not claim knowledge you don't have.

## Output (strict)
- Write source files ONLY as src/xbox360/<FAMILYPREFIX>_*.c (or .cpp); new headers allowed
  with the same prefix. Do not edit any other repo file (no config/, tools/, tests/, docs/,
  no existing sources), do not run tools/matching.py, do not git add/commit.
- For each source file write work/specs/<FAMILY>/<stem>.json:
  {"source": "src/xbox360/<file>", "flags": [], "functions": {"ts4_name": "0x8861C648", ...},
   "renames": {"lbl_...": "g_ts4_..."}}
  List ONLY functions that fn_check reported as MATCH in a final run of the exact file, and
  include every RENAME line from that run in "renames".
- Keep source files to at most ~300 functions each.
- Final report: spec files written, functions matched / total, bytes, any functions that
  could not be matched and why, and any insight worth sharing with other agents. Keep it short.

## Lessons from round 1 (read these)
- C++ helps for objects: `extern "C"` on everything; custom `inline void *operator new(unsigned,
  void *heap, int size, int align, int flags, int tag)` wrapping fn_88613268 reproduces the
  shared allocator pattern; constructors with `vtbl = &lbl_X;` bodies.
- Copying a result into a second local, or passing through a `__forceinline` helper, can fix
  register moves/scheduling around calls.
- Scalar-deleting destructors: `base_dtor(this); if (flags & 1) ts4_tsu_cleanup_end(this);
  return this;` (see src/xbox360/fb_dtor_*.c for working forms).
- strlen: declare `#ifdef _MSC_VER extern unsigned int strlen(const char *); #else #include
  <string.h> #endif` and call it. memset may appear as a placeholder fn_ — use that name.
- .c files must also pass host `cc -std=c11 -Wall -Wextra -Werror -fsyntax-only`: declare
  every callee with a prototype, no MSVC-only keywords in .c (use .cpp for those).
  Check with that command before finishing.
- Some members of a cluster differ in a callee; make every relocation a macro parameter.
- Cluster files list names AFTER round 1; some relocation targets may now be ts4_* names
  (already-reviewed; use them exactly as listed in config/54540859/symbols.txt).

## Range matching (round 4)
- You own one address range. Work on functions named fn_XXXXXXXX with size > 0x100 inside it
  (smaller ones belong to the automatic generator; skip them). Start with the smaller sizes
  and with functions whose callees are already named or matched; skip a function after a
  solid attempt (~3 compile iterations without convergence) and move on — throughput matters.
- Adjacent functions usually come from the same original source file: group matches from one
  neighbourhood into one source file named after the subsystem, with shared struct types.
- Use docs/gameplay/*.md and docs/gameplay-map.md for struct layouts and names where they apply.
- Write a spec per source file as usual; include only MATCH functions. Commit nothing.
