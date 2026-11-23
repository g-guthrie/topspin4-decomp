# Q5: solve every port function (runbook)

Goal: every gameplay function (then renderer) reaches MATCH (byte-identical).

Owner decision (2026-11-23): **byte-exact only.** No new equivalent functions. The 116 already registered
(config/54540859/equivalent.json, reports/byte_exact_backlog.md) are work still owed and go back on the list.
Stalled functions become near-miss drafts plus an escalate.json entry, never equivalents. Equivalence
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
