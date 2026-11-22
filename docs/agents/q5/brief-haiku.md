# Q5 brief: clone matched templates onto their sister functions (rote work)

You are a matching-decompilation helper for Top Spin 4, Swing_DLL.xex (Xbox 360, MSVC 16.00.10224, PowerPC).
The repo is /home/user/topspin4-decomp.

**What a sister is.** Each sister has the same instruction shape as a template function that is already matched (or proven equivalent). What changes is usually struct offsets, constants, callee addresses or registers. Your job is to copy the template's C, adjust it, and verify it.

## Setup and tools

Run `export TS4_MATCHING_DIR=$PWD/work/matching-<latest>`.

| Task | Command |
|---|---|
| Show the original asm | `python3 tools/fn_asm.py fn_X` (run it for the template and for the sister, and diff them) |
| Check a match | `python3 tools/fn_check.py <src> name=0xADDR [--flags as in the template]` |
| Check an LTCG template | `python3 tools/fn_check_ltcg.py <src> name=0xADDR --context src/xbox360/pp1_pool_primer.c` |
| Check an equivalent-route template | `python3 tools/fn_equiv.py <src> name=0xADDR --json work/specs/Q5H/<stem>.equiv.json` |
| Near miss of 1-4 instructions | `python3 tools/perm_auto.py <src> name=0xADDR -j 2 --time 180` |

Use the LTCG command when the template entry has `"ltcg": true`. Use the equivalence check when the template has `"route": "equiv"`.

## Your entries

You get entries from docs/agents/q5/templates.json, listed in your prompt. For each sister address:

1. **Check it is still unmatched.** Run `grep -ri <address without 0x> src/`. If any file already defines it, skip it.
2. **Find the differences.** Read the template source. Diff the two asm listings and note every offset, constant, call target and branch that differs.
3. **Write the clone.** Put it in YOUR file `src/xbox360/q5h<N>_<topic>.c`, where N is your agent number from the prompt.
   - Name it `ts4_<same verb as template>_<ADDR>`, or something better if the difference shows what it does.
   - Reuse the template's struct types where the offsets agree. Where they differ, make a new struct.
   - **Never `#include` another agent's .c file.** Copy what you need, with your own type names prefixed `Q5h<N>`.
4. **Check it** with the command that fits the template.
5. **Write the spec** at `work/specs/Q5H/q5h<N>_<topic>.json`, in the same format as the template's spec in work/specs/Q5/ (copy it). It lists only the functions that pass.

## Rules

- **No shortcuts.** No stand-in callee stubs, no knowingly false prototypes, no volatile hacks. If the sister calls a function, declare it with the same prototype the template uses for its counterpart.
- **Host syntax.** .c files must pass `cc -std=c11 -Wall -Wextra -Werror -Wno-deprecated-non-prototype -fsyntax-only -Isrc/xbox360`.
- **Every sister gets solved.** A sister is solved when it MATCHES. If byte matching stalls after the permuter, it is also solved when equivalent C passes `tools/fn_equiv.py`; write its spec with `"route": "equiv"` and evidence. Nothing is skipped. If a sister really is not a clone (different control flow), still write it from its own asm. Then match it or make it equivalent.
- **Files and git.** Don't edit any file other than your own. Don't run tools/matching.py. Don't commit. Never put game data in the repo.
- **Honesty.** A function counts only if the checker says MATCH, or PASS for the equivalent route.

## Final report

- your source and spec files;
- the functions that passed, by address;
- anything still open, with its exact state (there should be none).
