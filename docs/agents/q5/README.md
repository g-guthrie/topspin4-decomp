# Q5: solve every port function (runbook)

Goal: every gameplay function (then renderer) reaches MATCH (byte-identical).

Owner decision (2026-11-23): **byte-exact only.** No new equivalent functions. The 116 already registered
(config/54540859/equivalent.json, reports/byte_exact_backlog.md) are work still owed and go back on the list.
Stalled functions become near-miss drafts plus an escalate.json entry, never equivalents. A near-miss is parked only with a concrete reason the odds improve later (unmatched callee, named tool limit, missing type); otherwise it is worked now. Equivalence
sections below are kept only for maintaining the existing 116.
Middleware (Havok, FMOD, Bink, XDK, CRT) is out of scope.

## Files here (committed, durable)

| File | What |
|---|---|
| `worklist.txt` | The work list. `## 1` gameplay group reps, `## 2` remaining gameplay (ascending size), `## 3` renderer reps, `## 4` remaining renderer. One `0xADDR SIZE QUEUE [| sisters]` per line. |
| `worklist_v2.txt` | **Current work list** (2026-11-23): scope = gameplay plus its non-middleware call-graph dependencies, split into 19 subsystems, each line with its bottom-up level (0 = every in-scope callee matched). Regenerate with `python3 tools/callgraph_worklist.py`. `worklist.txt` is the old size-ordered list, kept for reference. |
| `subsystems.md` | Subsystem table: ranges, counts, key classes, entry points, scope totals, method. |
| `scope_callgraph.json` | In-scope call edges of unsolved functions; `q5_status.py` uses it for live readiness. |
| `brief-opus.md` | Brief for solver agents (Opus). Read all of it, including "Owner decisions (2026-11-22)". |
| `brief-haiku.md` | Brief for rote sister-function agents (Haiku). |
| `brief-fable.md` | Brief for the escalation/tooling solver. |
| `escalate.json` | Functions stuck on a tool limit or after real effort, with drafts and notes. |
| `templates.json` | Matched group representatives and their sisters (rote work for Haiku). |
| `notes/` | Per-function hand-over notes for unfinished large functions. |

Status at any time: `python3 tools/q5_status.py` (v2 by default: per subsystem; `--next N --subsystem ID` lists ready functions, `--blocked` shows what blocks the nearest ones) (add `--from-end` for the
largest-first view, `--next N`). It reads this directory, match.json,
equivalent.json and the claim dirs.

Ephemeral (not committed, recreate): `work/q5/claims/` (claim with
`mkdir work/q5/claims/0xaddr`), `work/specs/Q5/*.json` specs and
`*.equiv.json` evidence (evidence that matters is summarised in
config/54540859/equivalent.json; specs can be rebuilt from it), build dirs
`work/matching-bNNN`.

## Roles (what worked)

- **Coordinator** (one session): hands out work,
  integrates matches, runs the ~40 min build, commits. Never solves functions
  itself.
- **Opus solvers**: section 2 split by direction. Opus A ascending (small end),
  Opus B descending (large end); more solvers can take interleaved slices
  (claims prevent collisions). Every size is byte-matched; for large LTCG
  functions, match the callees first.
- **Haiku (high effort)**: sister functions of a matched template, other rote passes.
- **Fable**: escalations and checker/tool fixes only.

Hand-in cadence: small-end agents every 6-10 functions; large-end agents after
every proven function. Start a fresh agent from the brief rather than letting
one run long. Auto-compact at about 250k is the recommended setting for this
workload.

## Coordinator loop

1. Hand-in arrives: for each equivalent spec,
   `TS4_MATCHING_DIR=$PWD/work/matching-<latest> python3 tools/equiv_register.py <spec>`.
2. For each match spec:
   `python3 work/dupcheck.py $S && python3 tools/fix_refs.py $S && python3 tools/integrate_match.py $S && python3 tools/ltcg_precheck.py --split-dir work/matching-<latest>/split`.
   An LTCG spec's `"context"` is the list `fn_check_ltcg.py --auto-context` printed ("explicit command"); to
   re-check a hand-in, run its source with `--auto-context` (see "Tools: LTCG context selection").
3. Build (about 40 min):
   ```
   T=$PWD/work/matching-tools; nohup sh -c "python3 tools/matching.py --fresh-analysis --jeff work/jeff/target/release/jeff --compiler-dir $T/compilers/X360/16.00.10224.00 --wrapper $T/work_wibo --objdiff $T/objdiff-cli --work-dir work/matching-bNNN > work/bNNN.log 2>&1; echo rc=\$? > work/bNNN.rc" >/dev/null 2>&1 &
   ```
4. After rc=0:
   `python3 tools/sync_progress.py --work-dir work/matching-bNNN && python3 tools/validate_decomp_dev_report.py && python3 tools/byte_exact_backlog.py && python3 tools/check_no_game_data.py`,
   then commit config/, README.md, reports/, docs/, sources.
5. Keep one build dir (disk). Point older paths at the newest with a symlink so
   running agents keep working.
6. Periodically: `python3 tools/equiv_register.py --recheck` (must be 0 failing).

## Tools: LTCG context selection

Work bottom-up through the call graph: a function's LTCG code depends on its callees' bodies, so match the callees
first. `tools/fn_check_ltcg.py --auto-context` picks the contexts:

    python3 tools/fn_check_ltcg.py <src> name=0xADDR --flags /Oc --auto-context [--auto-depth 2]

- Use `--auto-context`; match the listed missing callees first ("missing callee bodies" in its output).
- It reads the callees from the original (`bl` targets; `--auto-depth 2` adds the callees of matched callees), maps
  them to their matched sources (config/54540859/match.json, then work/specs), and adds each source once, plus the
  contexts recorded for a callee that is itself an LTCG unit, the sources of functions the source names but the
  original does not call (the link inlined them), and src/xbox360/pp1_pool_primer.c last. Explicit `--context`
  values stay in front and win for their file.
- Called callees are forced with `--include` (they matched as functions of their own). Contexts are compiled plain;
  when the link inlines a callee the original calls, the check repeats with `flags(/Ob1):` on that callee's source.
  `--auto-prefix "flags(/Ob1):"` puts a fixed prefix on every chosen source instead.
- A callee with no matched source gets the stand-in a registered unit already uses for it, if there is one
  (cw1_ctx_format_text.c for ts4_format_text); it stays on the missing list.
- A context that does not compile, or that breaks the link (a function defined twice), is dropped with a message
  and the check repeats without it.
- A linker crash (wibo SIGSEGV) drops the automatic `--include` values first. When the full context does not
  match, it also tries "without the /INCLUDE of the callees" and "without the callee sources" and says which one
  matched (`--auto-no-include` / `--auto-no-fallback` turn these off). The printed explicit command is the one
  that produced the result.
- Call each callee by the name its matched source uses; the output says when the source does not.
- It prints the equivalent explicit command: put that context list (and `include`) in the spec.
- A candidate source whose definition returns `void` where the source under test uses a value (or the reverse)
  is passed over when another candidate agrees, also for a stand-in (0x8816CBB0: cx39_ctx_hash.c, not
  rm2_index_hash_tables.c). A callee the original calls more often than the candidate (inlined at some call site)
  gets `flags(/Ob1):`.
- A helper that only a context-only file defines (os1_ctx_crc32 in os1_ctx_checksum.c) brings that file in when the
  source names it.
- On FAIL it tries up to `--auto-tries` (12) smaller links in a fixed order: without the /INCLUDEs, `/Ob1` on every
  callee source, without one callee source at a time, one callee source alone, no callee source.
- Before those, once and outside the count, it tries the failed link "without the pool primer": a literal the
  original keeps in another pool than g_ts4_script_constants (the 0.5f at lbl_8814B910 of 0x88779248 and
  0x886AFDF8, the zeros of cx18_ltcg_a.c) costs one instruction more when it lands in the primed pool.
- It cannot know `--no-include` with a caller context, a new stand-in for an unmatched callee, or a stand-in for
  a callee whose matched source compiles to another body under /GL (see the list below): pass those by
  hand. Logic and tests: tools/ltcg_autocontext.py, tests/test_ltcg_autocontext.py.

### Units that need manual context (full run, 2026-11-23)

`TS4_MATCHING_DIR=$PWD/work/matching-b225 python3 tools/ltcg_autocontext_all.py` checks every unit of
config/54540859/ltcg_units.json with its flags and `--auto-context` only (none of its recorded context, include
or no_include values), one worker per core; rows go to work/autoctx_full.tsv, outputs to work/autoctx_logs/.
Result on the b225 split: **256 of 257 units (422 of 423 functions) match by auto-context alone**, 14 of them
through a fallback link (3 "without the pool primer"). The earlier "216 units, 209 by auto alone, 7 manual"
figure (commit 2d0d5c8) predates the return-kind filter, the call-site count and the ranked fallback; its list
was not kept and this one replaces it.

| Unit | Function | Manual context | Why auto-context cannot find it |
|---|---|---|---|
| src/xbox360/cx33_ltcg_b.c | ts4_fill_lookup_8890E810 | `--context "flags(/Ob1):src/xbox360/cx33_ctx_e698.c"` | Its callee 0x8890E698 is matched on the plain route (me_ts4_registry_find_value_8890E698.c, `find_key` as `static __inline`). Under /GL the link does not inline `find_key`: the callee comes out as 0x50 bytes with a `bl` (0xC8 in the original), so the caller sees another clobber set and keeps other registers across the call (38 instructions differ; no fallback link matches). The stand-in cx33_ctx_e698.c writes the search out in the function body and gives the original's register use. Auto-context prefers a matched source to a stand-in, and must: a stand-in is only right for the caller it was written for. |

Not a unit, checked as well: the spec work/specs/Q5/q5_path_getters.json (q5_ctx_move_planner_callees.c,
0x8868ED00 and 0x8867A908) matches by auto-context alone.

## Tools: aliases (ICF folds, C++ members called from C)

docs/ltcg-route.md section 12. Two symbols the original linker folded to one address (two `bl` to one function
that the compiler would merge, one vtable address loaded twice) need a second name in the source: add it to
config/54540859/icf_aliases.json (`"kind": "icf"`, with the evidence) and both checkers and the build accept it.
A function that matches only as a C++ member gets its decorated name in the spec's `"functions"` plus a
`"kind": "cxx"` alias in the spec's `"aliases"`; fix_refs.py writes the alias into the C callers and
integrate_match.py registers it. `python3 tools/icf_alias.py --check` validates the file.

## Debugging equivalence failures

`python3 tools/eqdbg.py` takes fn_equiv's arguments; at the first call-sequence
difference it prints both runs side by side (`EQDBG_N=<window>`), and
`EQDBG_K=<k>` dumps the out-slot words stubs wrote. Big functions need
`--time 300 --trials 800` or more for full coverage.

## Known checker limits

- Loops over heap vectors with a virtual call per element rarely terminate on
  seeded inputs (0x88912118, 0x8886AB08): byte match or harness work needed.
- Literal loads with no relocation in the split (0x88885408) can never pass
  fn_check: equivalent route; the split needs fixing.
- Vector registers across calls: see the fn_equiv version notes in
  docs/equivalence-tier.md for current behaviour.

## Parked 2026-11-23 (after b224)

State: 33,914 functions, 3,519,592 / 10,154,020 code bytes (34.66%). Subsystem wave rounds 1-2
(cont, eng, swan, math, move, world) produced 147 byte-exact matches in b222-b224. Open near-misses
are in src/xbox360/drafts/q5s_*_nearmiss.* with blockers; claims under work/q5/claims/ are stale
once a new wave starts (clear them by exact name).

Recommended order on resume:
1. (Done 2026-11-23: aliases, seed fix and auto-context changes; see "Tools: aliases" above and
   docs/ltcg-route.md sections 12-13.) Checker fixes for false negatives: ICF-folded functions (881A2508, 886D0EB0 vtable pair),
   C++ member symbols called from C (8819C360, 881509F8: rename callers or /alternatename),
   0x8814B440 constant naming differs between plain and LTCG routes, auto-context stand-in choice.
2. Class-recovery pass (C++ classes from vtables/ctors/dtors into src/xbox360/include/ts4/):
   many near-misses cite an unknown class shape (+0x154 move target, +0x3c block, matrix/handle).
3. Register-allocation research: about half the open near-misses differ only in register numbering
   and perm_auto rarely helps; study MSVC's allocator and build a smarter permuter or rules.
Then resume subsystem solver waves; planner 0x886B8468 last (26 callees unmatched).
