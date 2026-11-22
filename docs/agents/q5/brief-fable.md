# Q5 brief: escalation solver for stuck functions

You solve the Top Spin 4 functions that the main decomp agent got stuck on. The game is for Xbox 360: Swing_DLL.xex, built with MSVC 16.00.10224 for PowerPC. The repo is /home/user/topspin4-decomp.
**No one comes after you. Every function you are given must end SOLVED.**

## What counts as solved

A function is solved in one of two ways:

1. **MATCH:** `python3 tools/fn_check.py <src> name=0xADDR [--flags]` passes. For an LTCG unit, use `tools/fn_check_ltcg.py ... --context src/xbox360/pp1_pool_primer.c`.
2. **EQUIVALENT:** readable, named and typed C that passes `python3 tools/fn_equiv.py <src> name=0xADDR --json <evidence>` with its default coverage.

## Read first

- AGENTS.md.
- docs/agents/matching-brief.md.
- docs/agents/codegen-idioms.md.
- docs/agents/matching-tips.md, all of it. That includes the skip-category recipes, the class maps, and the automatic permuter `tools/perm_auto.py`.
- docs/equivalence-tier.md.

## Setup

Run `export TS4_MATCHING_DIR=$PWD/work/matching-<latest>`.

## Each function

Each function comes with:
- its address;
- the previous agent's best attempt;
- the state it reached;
- what was tried.

Start from that attempt. Don't redo what was tried. Try the big levers:
- **Different source structure:** helpers that the compiler inlines, loops written another way, or struct temporaries.
- **Probes of the compiler:** small test programs that isolate the one construct that diverges.
- **Flag variants:** `/O1`, `/Oc`, `/GS-`, or the LTCG route.
- **Fixing the model of a callee** in fn_equiv.
- **Splitting the function** into its natural pieces.

If byte matching is not reachable, finish it as EQUIVALENT.
If a tool is truly at fault (for example an undecoded instruction, or a harness that cannot model something), fix the tool:
- keep the fix small;
- keep it standard library only;
- add a test with synthetic data.
Then finish the function.

## Output

- **Sources:** put them in src/xbox360/q5f_<topic>.c. For the equivalent route, use eq_q5f_<topic>.c.
- **Specs:** put them in work/specs/Q5F/<stem>.json. Matched specs list only matches. An equivalent spec uses `"route": "equiv"` and `"evidence"` pointing at the fn_equiv json.

## Rules

- **No shortcuts.** No stand-in callee stubs, no knowingly false prototypes, no volatile hacks.
- **Host syntax.** .c files must pass `cc -std=c11 -Wall -Wextra -Werror -Wno-deprecated-non-prototype -fsyntax-only -Isrc/xbox360`.
- **Files and git.**
  - Don't run tools/matching.py.
  - Don't commit.
  - Edit only your own files, plus any tool you fix.
  - Never put game data in the repo.

## Final report

For each function, give:
- MATCH or EQUIVALENT;
- the source and spec;
- the trick that unlocked it, in one line for matching-tips.md;
- any tool fix you made.
