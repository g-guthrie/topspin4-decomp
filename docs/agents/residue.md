# Hard residue: triage and the LTCG context finder

Tooling pass of 2026-11-24 over the two populations that plain solving has not moved:

- the 98 equivalent-only functions (`config/54540859/equivalent.json`, `reports/byte_exact_backlog.md`);
- the near-miss drafts `src/xbox360/drafts/*nearmiss*` whose address is not in `match.json`
  (336 draft/address pairs when the run ended; some addresses are in both populations, marked `E+N`).

Everything below is measured with the existing checkers, unmodified, with
`TS4_MATCHING_DIR=work/matching-b215` (cl 16.00.10224) and a private `TS4_LTCG_SCRATCH`.
Scratch harnesses and raw outputs are in `work/residue/` (git-ignored): `triage.py` (runs the checkers),
`triage/*.json` (one result per function), `find/*.log` (context finder runs), `recheck.out` (fn_equiv re-runs),
`gen_doc.py` (builds the tables of this file).

## How each function was classified

1. `tools/fn_check.py` on the registered source (equivalents: registry flags; drafts: no flags and `/Oc`).
   The differing instructions are classed REG (same opcode, other register numbers), SWAP (two adjacent
   instructions exchanged), COMMUTE (operands of a commutative op exchanged), OTHER.
2. Static evidence from the target's own instructions (`tools/ltcg_ctx_find.py evidence`): a volatile register
   that is live across a `bl` proves the callee body was visible to the link (LTCG). 35 functions have it.
3. For those 35 and for every function whose note mentions LTCG: `tools/fn_check_ltcg.py --auto-context
   --auto-no-fallback`, then `tools/ltcg_ctx_find.py find` (context repair, see below).
4. Equivalents: `tools/fn_equiv.py --trials 300` with seeds 1 and 7 (only the first 33 rows; the sweep was
   stopped when the coordinator asked for one process at a time).
5. A flag sweep (`/O1`, `/Oc /O1`, `/GS-`, `/Ox`, `/Oc /Ob1`, `/Oc /Oy-`) over 75 functions before it was stopped:
   no function matched under another flag set, so "compiler flag difference" is an empty bucket here.

Buckets:

| Bucket | Meaning | Decided by |
|---|---|---|
| L1 | Missing LTCG context: a callee in the call closure has no matched body, so the link stubs it and the stub kills every volatile register | kept-register evidence + closure member unmatched |
| L2 | LTCG context is available and links with the exact kill set; what is left is the caller's own shape or register numbering | `ltcg_ctx_find find` diagnosis "every needed body is in the link" |
| L3 | LTCG-only codegen artifact without a kept register (dead copies, no-op `clrrwi`, value placed in another register by inlined members): the note says LTCG, the context run changes nothing | note + LTCG run equal to plain run |
| R | Register allocation / scheduling coin flip: equal size and only REG/SWAP/COMMUTE differences (or at most 8 off) | fn_check classes |
| S | Source shape or type: size differs or the instruction mix differs | fn_check classes |
| T | Tool limit: VMX, pool placement, split or checker limits named by the note | note |
| W | Wrong source: the "equivalent" source is not equivalent | fn_equiv re-run |
| M | Matched in this pass | fn_check_ltcg MATCH |
| U | Not checkable (draft does not compile / names no function) or the run did not reach it | - |

"Unmatched callee" and "wrong prototype" from the brief did not need their own bucket: an unmatched callee only
matters when the target keeps a register across it (that is L1), and a wrong prototype shows as S.

## Bucket totals

| Bucket | Equivalent-only (98) | Near-miss drafts | Total |
|---|---|---|---|
| L1 missing LTCG context: unmatched callee body | 9 | 3 | 12 |
| L2 LTCG context present, link or caller shape differs | 4 | 8 | 12 |
| L3 LTCG-only codegen artifact (dead copy, no-op clrrwi, value placement) | 22 | 17 | 39 |
| M matched in this pass | 2 | 0 | 2 |
| R register allocation / scheduling coin flip | 24 | 115 | 139 |
| S source shape / type (structural) | 29 | 179 | 208 |
| T tool limit / VMX / pool placement | 5 | 2 | 7 |
| U not checkable | 0 | 4 | 4 |
| U not checked | 0 | 8 | 8 |
| W wrong source (equivalence false positive) | 3 | 0 | 3 |
| **Total** | 98 | 336 | 434 |

## The tool: `tools/ltcg_ctx_find.py`

Standard library only; imports `fn_equiv`, `fn_check_ltcg` and `ltcg_autocontext` read-only. Test:
`python3 -m unittest tests.test_ltcg_ctx_find` (14 tests, synthetic PPC words, no toolchain needed).

- `evidence 0xADDR... [--json]`: static, no compile. For every call site: the volatile registers the target
  keeps across the call and the callee's true kill set (registers written anywhere in its call closure, read
  from the image). Lists every closure member that needs a body and where one exists (match, spec, stand-in,
  equivalent, draft). Verdict `LTCG PROVEN`, `LTCG LIKELY` (only r3/f1 kept) or no evidence.
- `find SRC name=0xADDR [--flags ...]`: takes the context of `fn_check_ltcg.py --auto-context --auto-depth 2`,
  adds sources for deeper closure members, links, and then compares, per closure member, the kill set of the
  linked candidate with the original, and per call site the kept registers. It then tries repairs one at a
  time: a stand-in body from a draft/equivalent source (renamed through a generated wrapper), a
  `__declspec(noinline)` wrapper instead of `flags(/Ob1):`, the `/Ob1` toggle, the `/INCLUDE` toggle, an
  alternate source, no pool primer. Prints each link's score and diagnosis and the best explicit
  `fn_check_ltcg.py` command. Exit 0 only on MATCH.
- `kills SRC name=0xADDR...`: links one source and prints each function's kill-set difference against the
  original: is this draft usable as a callee body?

### What it found

- The caller picks the highest free volatile register, so a callee body must reproduce the original's kill
  set exactly; "does not kill the kept register" is not enough. Example 0x88660520: with auto-context's
  `flags(/Ob1):me_ts4_cursor_out_of_range_886603C0.c` the callee stops inlining its own static helper and its
  kill set becomes +r12 -r6; the caller then keeps `self` in r6 instead of r5. A wrapper context
  (`#define NAME __declspec(noinline) NAME` + `#include`) restores the kill set and the kept register.
- A draft that is close in instruction count can still be useless as a stand-in: the 0x886C48C8 draft lacks
  r4-r7 and f8-f12 in its kill set, so 0x886C7C28 stays 4 off (f12 where the target has f7).
- When the diagnosis says "every needed body is in the link ... kept registers still differ", the missing
  kept register is a value the source must create before the call. Both matches below came from that line.

### Measured results (all LTCG route; MATCH printed by `tools/fn_check_ltcg.py`)

| Address | Result | Source | Spec |
|---|---|---|---|
| 0x888C5C00 | MATCH (was equivalent-only, 2 off with the found context) | `src/xbox360/q5s_res_pad_stick.c` | `work/specs/Q5S/q5s_res_pad_stick.json` |
| 0x886A80F0 | MATCH (was equivalent-only, 28 off plain, 6 off with the found context) | `src/xbox360/q5s_res_stroke_query.c` | `work/specs/Q5S/q5s_res_stroke_query.json` |

Commands:

    python3 tools/fn_check_ltcg.py src/xbox360/q5s_res_pad_stick.c ts4_pad_send_stick_888C5C00=0x888C5C00 --flags /Oc \
        --include ts4_pad_record_find_88614938 --context src/xbox360/pr2_signin.c --context src/xbox360/pp1_pool_primer.c
    python3 tools/fn_check_ltcg.py src/xbox360/q5s_res_stroke_query.c ts4_stroke_query_886A80F0=0x886A80F0 --flags /Oc \
        --include ts4_state_flag_8865DA28 --context src/xbox360/jt_switch_flags.c --context src/xbox360/pp1_pool_primer.c

The tool supplied the context and the diagnosis; the source edits were made by hand (literal `65535.0f` and
store order for the first; a result variable set before the call and the flag narrowed at its test for the
second). The specs carry an `"include"` list (the callee `/INCLUDE` names), as `work/specs/Q5S/sweep_*.json` do.

Other `find` runs (differing instructions with the best link; before -> after where the tool improved it):
0x886C7C28 27 -> 4 (draft stand-in for fn_886C48C8), 0x886A1628 42 -> 23 (draft stand-in for fn_886643F8),
0x88660520 29 -> 28 on the registered source and 8 on a corrected source (noinline wrapper),
0x887F8920 / 0x887F8A50 75 -> 14 (register numbering only; perm_auto already tried twice),
0x8867BCF8 2, 0x88691C40 2 (both known coin flips worked by solvers), 0x886D5F78 36 -> 34.
No other function reached MATCH. Honest count: 2 matches, both in the L2 bucket; L1 (12) needs callee bodies
that do not exist yet, and R and S (347 together) are not moved by a context tool.

## Equivalence registry findings

Of the first 33 registered equivalents re-run with `fn_equiv.py --trials 300 --seed 1`:

- 0x88660520 `DIFFERENT`: `Q5CursorIn` in `eq_q5a_gameplay_small_i.c` has grid/grid_id at +0x84/+0x88, the
  target reads +0x88/+0x8C. `--trials 1000 --seed 1` and `equiv_register.py --recheck` still say EQUIVALENT:
  the verdict depends on the trial count.
- 0x886C5820 `DIFFERENT` (source hash equal to the registry): final memory differs at arg2+0.
- 0x88693FA8 `DIFFERENT`, and the source no longer has the registered sha256 (stale row).
- 0x8866BAE0, 0x886D5028, 0x88667C98, 0x886D0808 come back `UNCHECKED` for one or both seeds; 0x886D5F78 reaches
  90% coverage only.

The other 65 rows were not re-run.

## Proposed patches to existing tools (not applied)

1. `tools/ltcg_autocontext.py`: when a callee source would get `flags(/Ob1):`, generate a wrapper context
   (`#define NAME __declspec(noinline) NAME` / `#include "source"`) instead. `/Ob1` changes the callee's own
   inlining and therefore its kill set (0x88660520). `ltcg_ctx_find.wrap_noinline` is the reference code.
2. `tools/ltcg_autocontext.py`: follow the call closure to its leaves instead of depth 2, but only below callees
   across which the target keeps a register (`ltcg_ctx_find.closure` / `kept_by_callee`); skip the LTCG link
   completely when no register is kept and the note does not ask for it (saves a 50-110 s link per function).
3. `tools/fn_check_ltcg.py`: after a failed link, print per call site "target keeps X, candidate keeps Y" and
   whether each callee is a stub (`ltcg_ctx_find.diagnose`). This one line tells a solver whether to work on
   the context or on the source.
4. `tools/fn_check_ltcg.py` symbol extents: strip trailing zero padding words before disassembly (padding
   decoded as unknown instructions makes any derived kill set "all volatile").
5. `tools/equiv_register.py --recheck`: re-run at two more trial counts and seeds (for example 300/1 and
   300/7) and refuse rows that turn DIFFERENT or UNCHECKED; verify `source_sha256` first.
6. `tools/fn_check_ltcg.py --spec`: accept the `"include"` list used by the Q5S specs if it does not already.

## What to do next

1. L1 (12 functions) unlocks by matching eight callees: fn_88646658 and fn_88645A68 (2 callers each),
   fn_88668DF8, fn_8866C8B8, fn_886643F8, fn_886AD158, fn_886C48C8, fn_886CB778/fn_886C6758, fn_887F4BA0/fn_887F4708
   (5 constructors). Where a body will not match, a kill-set-exact stand-in is enough: extend `kills` into a
   synthesizer that pads a draft with dead register traffic until its kill set equals the original.
2. L2: add a hint pass to `find` for the pattern "target has `li rN,0` before the call and `mr r3,rN` at the
   exit": declare the result variable before the call and assign the call result to it (0x886A80F0);
   0x888D4EF8 is the same pattern with r31 and did not yield to three variants.
3. Review the three W rows and re-run the fn_equiv sweep over the remaining 65 rows, serially.
4. R (139): these are the population for `regalloc_mutate` / `perm_auto`; 72 of them are at most 3 off.
   S (208): mostly drafts that are far from the target; they need class/type recovery, not tooling.

## Full table

Pop: E = equivalent-only, N = near-miss draft. "plain N" = differing instructions with fn_check; "ltcg N" with
auto-context; "ctx_find N" with the best link of `ltcg_ctx_find find`; "kept:" = registers the target keeps
across the named callee.

| Address | Size | Pop | Bucket | Evidence | What would unlock it |
|---|---|---|---|---|---|
| 0x88151088 | 248 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x881518D0 | 116 | N | L3 | plain 16; ltcg 16; classes REG 16; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x88151A70 | 152 | N | S | plain 25; classes OTHER 25; size 0x9c/0x98 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88152ED8 | 236 | N | S | plain 29; classes OTHER 23,REG 6; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88165170 | 172 | N | R | plain 3; classes COMMUTE 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88178D10 | 592 | N | S | plain 143; classes OTHER 133,REG 10; size 0x25c/0x250 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88181240 | 184 | N | R | plain 4; classes OTHER 2,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88189630 | 196 | N | U | plain - | triage run did not reach it |
| 0x881896F8 | 316 | N | S | plain 62; classes OTHER 48,REG 14; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88190190 | 108 | N | L3 | plain 15; ltcg 15; classes OTHER 6,REG 6,SWAP 2; size 0x68/0x6c | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x881A9968 | 104 | N | L3 | plain 20; ltcg 20; classes OTHER 17,REG 2; size 0x64/0x68 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x881BBC00 | 120 | N | L2 | plain 1; ltcg 29; classes COMMUTE 1; size equal; kept: ts4_noop_881B3360 r3 | run tools/ltcg_ctx_find.py find; all callee bodies are matched |
| 0x881BC130 | 220 | N | R | plain 3; classes REG 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x881EE260 | 100 | N | L3 | plain 6; ltcg 6; classes REG 6; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x881EF138 | 96 | N | L3 | plain 6; ltcg 6; classes REG 6; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x88267630 | 88 | N | L3 | plain 18; classes OTHER 15,REG 3; size 0x5c/0x58 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x8826C388 | 116 | N | L3 | plain 22; ltcg 24; classes OTHER 12,REG 10; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x88272340 | 172 | N | T | plain 36; classes OTHER 36; size 0xd0/0xac | checker or split fix, vector class recovery (see note) |
| 0x882738F8 | 108 | N | L3 | plain 2; ltcg 2; classes REG 2; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x882867E0 | 480 | N | S | plain 67; classes OTHER 64,REG 1,SWAP 2; size 0x1e4/0x1e0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88290D58 | 460 | N | S | plain 106; classes OTHER 96,REG 10; size 0x1f4/0x1cc | different statement or type shape: size or instruction mix differs; class recovery |
| 0x882A2EE8 | 216 | N | S | plain 49; classes OTHER 38,REG 11; size 0xe0/0xd8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x882DD880 | 160 | N | S | plain 20; classes OTHER 9,REG 11; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88335B48 | 44 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88345478 | 72 | N | S | plain 13; classes OTHER 5,REG 8; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88365560 | 260 | N | R | plain 5; classes REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8836E4D0 | 200 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8837AA88 | 120 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x883C8D58 | 576 | N | S | plain 133; classes OTHER 130,REG 3; size 0x25c/0x240 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883CA2A0 | 560 | N | L2 | plain 127; ltcg 124; ctx_find 124; classes OTHER 112,REG 5,SWAP 2; size 0x21c/0x230; kept: ts4_progress_ratio_883C9520 f11 | context found by ltcg_ctx_find (124 off left): caller source shape / register numbering |
| 0x883CB860 | 72 | N | R | plain 3; classes REG 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x883CF8A8 | 272 | N | L2 | plain 65; ltcg 59; ctx_find 59; classes OTHER 59; size 0x134/0x110; kept: fn_883CF7F0 r4,f13 | context found by ltcg_ctx_find (59 off left): caller source shape / register numbering |
| 0x883D0C18 | 112 | N | S | plain 23; classes OTHER 21,SWAP 2; size 0x74/0x70 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883D4998 | 252 | N | S | plain 53; classes OTHER 48,REG 5; size 0x100/0xfc | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883D8970 | 152 | N | S | plain 33; classes OTHER 30,REG 3; size 0xa8/0x98 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883DB8F0 | 164 | N | S | plain 33; classes OTHER 23,REG 10; size 0xa8/0xa4 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883DC438 | 504 | N | S | plain 119; classes OTHER 117,SWAP 2; size 0x200/0x1f8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883DD338 | 540 | N | S | plain 120; classes OTHER 115,REG 5; size 0x238/0x21c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883DE6A8 | 184 | N | S | plain 43; classes OTHER 33,REG 9; size 0xb4/0xb8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883DFA10 | 76 | N | R | plain 4; classes OTHER 2,REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x883E5CE0 | 136 | N | S | plain 23; classes OTHER 19,REG 4; size 0x8c/0x88 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883E5E80 | 140 | N | S | plain 26; classes OTHER 24,REG 2; size 0x90/0x8c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883E6438 | 192 | N | S | plain 42; classes OTHER 40,REG 2; size 0xc4/0xc0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883E6D98 | 492 | N | S | plain 115; classes OTHER 114,REG 1; size 0x1f8/0x1ec | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883E82F8 | 24 | N | R | plain 5; classes OTHER 2,REG 1,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x883EA6C0 | 524 | N | S | plain 105; classes OTHER 90,REG 15; size 0x21c/0x20c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883EAF78 | 516 | N | S | plain 90; classes OTHER 83,REG 7; size 0x208/0x204 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883EC148 | 448 | N | S | plain 96; classes OTHER 91,REG 5; size 0x1cc/0x1c0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883ED860 | 512 | N | S | plain 125; classes COMMUTE 1,OTHER 121,REG 3; size 0x22c/0x200 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883FA998 | 452 | N | S | plain 93; classes OTHER 78,REG 1; size 0x18c/0x1c4 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883FBC58 | 164 | N | S | plain 34; classes OTHER 34; size 0xb4/0xa4 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x883FCCC0 | 216 | N | S | plain 42; classes OTHER 37,REG 5; size 0xe4/0xd8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88423E28 | 224 | N | R | plain 3; classes REG 1,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88439050 | 104 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x884482C0 | 92 | N | R | plain 9; classes OTHER 8,REG 1; size equal | targeted permutation; diff is same-size reordering |
| 0x8847E770 | 184 | N | T | plain 2; classes REG 2; size equal | checker or split fix, vector class recovery (see note) |
| 0x88482E88 | 136 | N | R | plain 5; classes REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8848B978 | 68 | N | R | plain 3; classes REG 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x884957C0 | 60 | N | R | plain 3; classes COMMUTE 1,REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x884C19A0 | 64 | N | S | plain 12; classes OTHER 11,REG 1; size 0x4c/0x40 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8854FDA8 | 92 | N | S | plain 16; classes OTHER 13; size 0x50/0x5c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88564BF8 | 304 | N | S | plain 68; classes OTHER 59,REG 7,SWAP 2; size 0x13c/0x130 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8857CBC0 | 264 | N | S | plain 50; classes OTHER 49,REG 1; size 0x114/0x108 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88589748 | 124 | N | S | plain 22; classes OTHER 20,REG 2; size 0x84/0x7c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x885897C8 | 124 | N | S | plain 25; classes OTHER 25; size 0x88/0x7c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88593848 | 100 | N | R | plain 4; classes OTHER 2,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88594A48 | 92 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8859B308 | 84 | N | R | plain 8; classes OTHER 8; size equal | targeted permutation; diff is same-size reordering |
| 0x885E3968 | 72 | N | L3 | plain 2; ltcg 2; classes REG 2; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x885E5D38 | 84 | N | S | plain 19; ltcg 19; ctx_find 19; classes OTHER 16; size 0x48/0x54; kept: fn_885E5BC8 r3 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x885E6C48 | 88 | N | S | plain 16; ltcg 16; ctx_find 16; classes OTHER 15; size 0x54/0x58; kept: fn_885E5BC8 r3 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88600D88 | 116 | N | R | plain 2; classes REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8860C2E0 | 112 | N | R | plain 2; classes OTHER 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88611440 | 80 | N | R | plain 3; classes REG 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886176F0 | 108 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88617D88 | 112 | N | L3 | plain 6; ltcg 6; classes OTHER 4,SWAP 2; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x8862BA88 | 200 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88640748 | 192 | N | S | plain 16; classes OTHER 11,REG 1,SWAP 4; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88640810 | 136 | N | R | plain 7; classes OTHER 7; size equal | targeted permutation; diff is same-size reordering |
| 0x886408C8 | 156 | E | R | plain 8; ltcg 8; classes OTHER 8; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88644738 | 84 | N | S | plain 10; classes OTHER 9; size 0x50/0x54 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88644C58 | 144 | N | R | plain 5; classes REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88644CE8 | 216 | N | S | plain 27; classes OTHER 6,REG 21; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88645290 | 184 | N | R | plain 5; classes OTHER 1,SWAP 4; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886457E0 | 388 | N | S | plain 87; classes OTHER 75,REG 11; size 0x180/0x184 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88648610 | 304 | N | S | plain 36; classes OTHER 28,REG 3,SWAP 2; size 0x124/0x130 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88649298 | 88 | E | L1 | plain 20; ltcg 20; ctx_find 20; classes OTHER 18,REG 2; size 0x64/0x58; kept: fn_88646658 f1; ts4_multiply_by_keys_886491E8 f1; fn_equiv --trials 300: EQUIVALENT coverage 100% | match fn_88646658, fn_88645A68 |
| 0x88649C10 | 120 | E+N | L1 | plain 26; ltcg 26; ctx_find 26; classes OTHER 25,REG 1; size 0x84/0x78; kept: fn_88646658 f1; ts4_multiply_by_keys_886491E8 f1; fn_equiv --trials 300: EQUIVALENT coverage 100% | match fn_88646658, fn_88645A68 |
| 0x8864A4E8 | 252 | N | S | plain 49; classes OTHER 47; size 0xf4/0xfc | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8864BAE8 | 88 | E+N | R | plain 2; ltcg 2; classes OTHER 2; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8864BBB0 | 88 | E | R | plain 2; ltcg 2; classes OTHER 2; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8864E790 | 100 | N | R | plain 5; classes REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8864EAB8 | 164 | N | R | plain 9; classes REG 9; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8864ED80 | 244 | N | S | plain 57; classes OTHER 46,REG 9; size 0xec/0xf4 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8864F7B8 | 232 | N | S | plain 14; classes OTHER 4,REG 10; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8864FB68 | 264 | N | S | plain 47; classes OTHER 45,REG 2; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88650430 | 432 | N | R | plain 9; classes OTHER 9; size equal | targeted permutation; diff is same-size reordering |
| 0x88650B80 | 236 | N | R | plain 4; classes REG 4; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88651E18 | 312 | N | S | plain 66; classes OTHER 50,REG 7; size 0x114/0x138 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88651F50 | 636 | N | S | plain 15; classes OTHER 15; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88655310 | 132 | N | R | plain 1; classes COMMUTE 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88656378 | 240 | N | R | plain 5; classes OTHER 5; size equal | targeted permutation; diff is same-size reordering |
| 0x88656C88 | 564 | N | S | plain 45; classes OTHER 32,REG 13; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88658120 | 152 | N | R | plain 5; classes OTHER 2,REG 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886581B8 | 176 | N | S | plain 43; classes OTHER 43; size 0xc8/0xb0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865A460 | 364 | N | S | plain 72; classes COMMUTE 1,OTHER 59,REG 11; size 0x168/0x16c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865AC90 | 80 | N | R | plain 7; classes OTHER 3,REG 4; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8865BE68 | 244 | N | S | plain 47; classes OTHER 31,REG 14; size 0xec/0xf4 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865C2D8 | 48 | E | R | plain 9; ltcg 9; classes OTHER 6,REG 3; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | targeted permutation; diff is same-size reordering |
| 0x8865C3D8 | 380 | N | R | plain 11; classes OTHER 8,REG 3; size equal | targeted permutation; diff is same-size reordering |
| 0x8865C648 | 328 | N | S | plain 56; classes OTHER 45,REG 11; size 0x158/0x148 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865C818 | 260 | N | R | plain 8; classes OTHER 2,REG 6; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8865C920 | 672 | N | L3 | plain 6; classes COMMUTE 1,REG 5; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x8865CBD8 | 244 | N | S | plain 13; classes OTHER 4,REG 1,SWAP 8; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865CCD0 | 672 | E | L3 | plain 6; ltcg 6; classes COMMUTE 1,REG 5; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x8865CF88 | 380 | N | S | plain 38; classes OTHER 11,REG 25,SWAP 2; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865D108 | 672 | E | L3 | plain 6; ltcg 6; classes COMMUTE 1,REG 5; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x8865D3C0 | 712 | N | S | plain 32; classes OTHER 28,REG 3; size 0x2c4/0x2c8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865D7D8 | 164 | E | S | plain 40; ltcg 40; classes OTHER 40; size 0xb4/0xa4; flags: /Oc /Ob1 -> 39; fn_equiv --trials 300: EQUIVALENT coverage 100% | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865E430 | 92 | N | S | plain 18; classes OTHER 16; size 0x54/0x5c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865E638 | 108 | E | S | plain 22; ltcg 22; classes OTHER 13,REG 8; size 0x68/0x6c; fn_equiv --trials 300: EQUIVALENT coverage 100% | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865EF18 | 128 | E | S | plain 32; ltcg 32; classes OTHER 28,REG 1; size 0x74/0x80; flags: /O1 -> 31, /Oc /O1 -> 31; fn_equiv --trials 300: EQUIVALENT coverage 100% | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865F8F0 | 296 | N | S | plain 62; classes OTHER 56,REG 1,SWAP 2; size 0x11c/0x128 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8865FD40 | 100 | N | R | plain 2; classes OTHER 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8865FFF8 | 88 | N | R | plain 1; ltcg 1; classes COMMUTE 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88660520 | 156 | E | W | plain 37; ltcg 29; ctx_find 28; classes OTHER 28,REG 1; size equal; kept: ts4_cursor_out_of_range_886603C0 r5; fn_equiv --trials 300: DIFFERENT (seed 1) | registered source reads grid at +0x84/+0x88, target +0x88/+0x8C (fn_equiv --trials 300 --seed 1: DIFFERENT). Corrected source work/residue/try/f.c + noinline wrapper context is 8 off, register numbering only (perm_auto 144, regalloc search 172 candidates: none) |
| 0x886609E0 | 168 | N | S | plain 32; classes OTHER 27,REG 1; size 0x98/0xa8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886612E0 | 184 | N | S | plain 30; classes OTHER 26,REG 3; size 0xb4/0xb8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88662390 | 200 | N | R | plain 10; classes OTHER 3,REG 7; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88662738 | 580 | N | S | plain 102; classes OTHER 83,REG 17; size 0x23c/0x244 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886629C8 | 408 | N | U | plain - | draft does not compile or names no function for this address |
| 0x88662C08 | 428 | N | S | plain 68; classes COMMUTE 2,OTHER 55,REG 11; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88662F60 | 132 | N | S | plain 17; classes OTHER 11,REG 6; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88663050 | 104 | N | R | plain 4; classes OTHER 2,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886634E0 | 312 | N | S | plain 19; classes REG 19; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886643F8 | 132 | N | R | plain 3; classes OTHER 3; size equal | targeted permutation; diff is same-size reordering |
| 0x886678A8 | 640 | N | R | plain 12; classes COMMUTE 6,OTHER 4,REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88667C98 | 172 | E | S | plain 41; ltcg 41; classes OTHER 38,REG 2; size 0xa8/0xac; fn_equiv --trials 300: EQUIVALENT coverage 100% | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88667D48 | 388 | N | S | plain 97; classes OTHER 84,REG 4; size 0x160/0x184 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88668118 | 500 | N | S | plain 17; classes COMMUTE 3,OTHER 6,REG 2,SWAP 6; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88668310 | 380 | N | R | plain 2; classes COMMUTE 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886688F0 | 356 | N | R | plain 11; classes COMMUTE 3,OTHER 6,REG 2; size equal | targeted permutation; diff is same-size reordering |
| 0x88669040 | 92 | E | L1 | plain 21; ltcg 21; ctx_find 21; classes OTHER 21; size 0x74/0x5c; kept: fn_88668DF8 r3,r5; ts4_clear_records_88668D70 r3,r5; fn_equiv --trials 300: EQUIVALENT coverage 100% | match fn_88668DF8 |
| 0x886696A8 | 76 | E | L3 | plain 17; ltcg 17; classes OTHER 7,REG 6; size 0x3c/0x4c; fn_equiv --trials 300: EQUIVALENT coverage 100% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x886696F8 | 384 | N | S | plain 93; classes OTHER 82,REG 10; size 0x17c/0x180 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88669B98 | 148 | E | S | plain 37; ltcg 37; classes OTHER 29,REG 5; size 0x88/0x94; fn_equiv --trials 300: EQUIVALENT coverage 100% | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88669F30 | 232 | N | R | plain 1; classes COMMUTE 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8866A1C8 | 1048 | N | U | plain - | draft does not compile or names no function for this address |
| 0x8866A670 | 332 | N | S | plain 58; classes OTHER 32,REG 26; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866A7C0 | 260 | N | R | plain 2; classes OTHER 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8866A930 | 388 | N | R | plain 7; classes COMMUTE 2,OTHER 4,REG 1; size equal | targeted permutation; diff is same-size reordering |
| 0x8866AC38 | 388 | N | R | plain 7; classes COMMUTE 2,OTHER 4,REG 1; size equal | targeted permutation; diff is same-size reordering |
| 0x8866ADC0 | 376 | N | S | plain 58; classes OTHER 53,REG 5; size 0x180/0x178 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866AFA0 | 548 | N | S | plain 133; classes COMMUTE 1,OTHER 121,REG 11; size 0x248/0x224 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866B1C8 | 664 | N | R | plain 10; classes OTHER 10; size equal | targeted permutation; diff is same-size reordering |
| 0x8866B460 | 312 | N | L3 | plain 5; classes OTHER 4,REG 1; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x8866B5B8 | 296 | N | S | plain 19; classes OTHER 11,REG 7; size 0x124/0x128 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866B738 | 392 | N | S | plain 76; classes OTHER 33,REG 43; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866BAE0 | 152 | E | L3 | plain 37; ltcg 37; classes OTHER 31; size 0x80/0x98; fn_equiv --trials 300: UNCHECKED coverage 50% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x8866BFE8 | 356 | N | S | plain 85; classes OTHER 77,REG 8; size 0x16c/0x164 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866C1A8 | 160 | N | S | plain 33; ltcg 33; classes OTHER 26,REG 5; size 0x98/0xa0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866C988 | 116 | E | L1 | plain 26; ltcg 26; ctx_find 26; classes OTHER 21; size 0x60/0x74; kept: fn_8866C8B8 r4,f10; fn_equiv --trials 300: EQUIVALENT coverage 100% | match fn_8866C8B8 |
| 0x8866CBE0 | 376 | N | S | plain 59; ltcg 59; ctx_find 59; classes OTHER 58,REG 1; size 0x17c/0x178; kept: ts4_if_get_u32_off4c_8865EC70 r3 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866CFA8 | 196 | N | S | plain 14; classes OTHER 14; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866D110 | 88 | N | S | plain 10; classes OTHER 9; size 0x54/0x58 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866D180 | 152 | N | R | plain 5; classes REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8866D368 | 368 | N | S | plain 87; classes OTHER 79,REG 6,SWAP 2; size 0x17c/0x170 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866D728 | 320 | N | S | plain 40; classes OTHER 31,REG 6; size 0x134/0x140 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866E318 | 204 | N | S | plain 36; ltcg 36; classes COMMUTE 1,OTHER 23,REG 12; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866EB80 | 60 | E+N | L3 | plain 15; ltcg 15; classes OTHER 9,REG 1; size 0x28/0x3c; flags: /O1 -> 14, /Oc /O1 -> 14; fn_equiv --trials 300: EQUIVALENT coverage 100% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x8866ECA8 | 412 | N | S | plain 90; classes COMMUTE 1,OTHER 79,REG 9; size 0x198/0x19c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866EE48 | 340 | N | S | plain 48; classes COMMUTE 1,OTHER 38,REG 7; size 0x14c/0x154 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866F4B8 | 292 | N | S | plain 61; classes OTHER 49,REG 6,SWAP 4; size 0x11c/0x124 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866F740 | 688 | N | S | plain 51; classes OTHER 14,REG 37; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8866FDD0 | 272 | N | R | plain 3; classes OTHER 3; size equal | targeted permutation; diff is same-size reordering |
| 0x886707C8 | 144 | N | R | plain 12; classes OTHER 7,REG 5; size equal | targeted permutation; diff is same-size reordering |
| 0x88670CC8 | 72 | N | R | plain 9; classes OTHER 6,REG 3; size equal | targeted permutation; diff is same-size reordering |
| 0x88671B10 | 1568 | N | L1 | plain 361; ltcg 361; ctx_find 355; classes OTHER 296,REG 65; size 0x628/0x620; kept: fn_8866E318 r6,r7,f5; ts4_if_get_8865E730 r6,r7,f5 | match fn_8866E318 (stand-in draft exists for fn_8866E318) |
| 0x88672130 | 632 | N | S | plain 141; classes OTHER 123,REG 7; size 0x24c/0x278 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886723A8 | 416 | N | S | plain 42; classes OTHER 31,REG 11; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88672548 | 424 | N | S | plain 91; classes OTHER 85,REG 4,SWAP 2; size 0x1b0/0x1a8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88673078 | 312 | N | S | plain 47; classes OTHER 43,REG 1; size 0x12c/0x138 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886734E8 | 324 | N | S | plain 65; ltcg 65; classes OTHER 55,REG 10; size 0x14c/0x144 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886736A0 | 448 | N | S | plain 33; classes COMMUTE 1,OTHER 29,REG 2; size 0x1bc/0x1c0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88676228 | 628 | N | S | plain 153; classes OTHER 125,REG 27; size 0x270/0x274 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886764A0 | 456 | N | S | plain 63; classes OTHER 18,REG 41,SWAP 4; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88676AF0 | 700 | N | R | plain 1; classes COMMUTE 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88676DB0 | 508 | N | S | plain 35; classes OTHER 24,REG 11; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88677D90 | 656 | N | S | plain 26; classes COMMUTE 1,OTHER 4,REG 21; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88678020 | 332 | N | S | plain 76; classes OTHER 71,REG 3; size 0x144/0x14c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88678708 | 196 | N | R | plain 10; ltcg 10; classes OTHER 5,REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886795C8 | 380 | N | S | plain 84; classes OTHER 84; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886797B8 | 324 | N | S | plain 55; classes OTHER 52,REG 2; size 0x140/0x144 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88679900 | 180 | N | R | plain 8; classes OTHER 6,SWAP 2; size equal | targeted permutation; diff is same-size reordering |
| 0x88679C78 | 716 | N | S | plain 137; classes OTHER 135,REG 2; size 0x2dc/0x2cc | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8867A970 | 112 | N | R | plain 1; classes COMMUTE 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8867AD58 | 352 | N | S | plain 36; classes OTHER 8,REG 28; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8867AF08 | 388 | N | S | plain 79; classes OTHER 71,REG 5; size 0x178/0x184 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8867B090 | 464 | N | S | plain 58; classes OTHER 55,REG 2; size 0x1cc/0x1d0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8867B800 | 272 | N | R | plain 3; classes COMMUTE 1,REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8867BCF8 | 180 | N | L2 | plain 35; ltcg 2; ctx_find 2; classes SWAP 2; size equal; kept: ts4_zero_field4_8890D7C0 r3,r9,r10 | context found by ltcg_ctx_find (2 off left): caller source shape / register numbering |
| 0x8867DA30 | 252 | N | R | plain 8; classes OTHER 3,REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8867DC80 | 460 | N | S | plain 62; classes COMMUTE 1,OTHER 44,REG 17; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8867DF68 | 800 | N | S | plain 169; classes OTHER 134,REG 34; size 0x31c/0x320 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8867E838 | 224 | N | S | plain 44; classes OTHER 42,REG 1; size 0xdc/0xe0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886807C0 | 2304 | N | S | plain 541; ltcg 562; ctx_find 540; classes FORM 1,OTHER 486,REG 39; size 0x8c4/0x900; kept: fn_88672130 r3; fn_88662C08 r3 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88681958 | 388 | N | S | plain 81; classes OTHER 68,REG 11; size 0x17c/0x184 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88686B08 | 280 | N | S | plain 16; classes REG 16; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886884E8 | 396 | N | L3 | plain 92; ltcg 90; classes OTHER 82,REG 7; size 0x188/0x18c | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x88688678 | 324 | N | S | plain 63; classes OTHER 47,REG 14; size 0x13c/0x144 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8868C218 | 380 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8868CB18 | 216 | N | S | plain 35; classes OTHER 30,REG 3; size 0xd0/0xd8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8868CBF0 | 316 | N | S | plain 76; classes OTHER 75,REG 1; size 0x140/0x13c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8868CD30 | 232 | N | S | plain 45; classes OTHER 39,REG 4; size 0xe0/0xe8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8868E248 | 216 | N | U | plain - | triage run did not reach it |
| 0x8868E950 | 220 | N | S | plain 46; classes OTHER 41,REG 5; size 0xe4/0xdc | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8868FAB8 | 260 | N | R | plain 2; classes COMMUTE 1,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88691C40 | 592 | N | L2 | plain 93; ltcg 2; ctx_find 2; classes COMMUTE 2; size equal; kept: ts4_loop_get_u32_off10_8865FE20 r3; ts4_phase_timer_flags_8866FB60 r3 | context found by ltcg_ctx_find (2 off left): caller source shape / register numbering |
| 0x88693FA8 | 132 | E | W | plain 8; ltcg 8; classes OTHER 2,REG 6; size equal; fn_equiv --trials 300: DIFFERENT (seed 1) | stale registration: eq_q5_gameplay_small_e.c no longer has the registered source_sha256 and fn_equiv --trials 300 --seed 1 says DIFFERENT (call #1 to ts4_rng_range_8861E598: f1 original 0, candidate 1.0); fix or re-register |
| 0x886952B8 | 160 | N | S | plain 34; classes OTHER 30,REG 3; size 0x9c/0xa0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88695C48 | 244 | N | U | plain - | draft does not compile or names no function for this address |
| 0x88696170 | 336 | N | S | plain 62; classes OTHER 62; size 0x154/0x150 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886962C0 | 124 | N | S | plain 19; classes OTHER 14,REG 3,SWAP 2; size 0x80/0x7c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88697E98 | 1696 | N | S | plain 275; classes OTHER 262,REG 12; size 0x69c/0x6a0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8869BEF0 | 284 | N | S | plain 67; classes OTHER 64,REG 3; size 0x134/0x11c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8869CDF0 | 456 | N | S | plain 26; classes OTHER 24,SWAP 2; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8869FAD8 | 532 | N | S | plain 58; classes OTHER 52,REG 6; size 0x218/0x214 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886A0A48 | 220 | N | S | plain 14; classes OTHER 11,REG 3; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886A13B0 | 304 | N | S | plain 55; classes COMMUTE 1,OTHER 45,REG 3; size 0x118/0x130 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886A14E0 | 328 | N | S | plain 17; ltcg 17; ctx_find 17; classes OTHER 10,REG 7; size equal; kept: ts4_mat_pretranslate_by_body_886633E8 r3 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886A1628 | 176 | E | L1 | plain 42; ltcg 42; ctx_find 23; classes OTHER 37; size 0x9c/0xb0; kept: fn_886643F8 r3,r6; fn_equiv --trials 300: EQUIVALENT coverage 100% | match fn_886643F8 (stand-in draft exists for fn_886643F8) |
| 0x886A2BE8 | 516 | N | S | plain 91; classes COMMUTE 1,OTHER 82,REG 8; size 0x218/0x204 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886A37D0 | 152 | E | L3 | plain 30; ltcg 30; classes OTHER 24,REG 2; size 0x88/0x98; fn_equiv --trials 300: EQUIVALENT coverage 100% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x886A3AC8 | 464 | N | L2 | plain 112; ltcg 53; classes OTHER 53; size equal; kept: ts4_obj44_triple_ctor_8869AF98 r6,r7 | run tools/ltcg_ctx_find.py find; all callee bodies are matched |
| 0x886A3DF0 | 696 | N | S | plain 92; classes OTHER 57,REG 35; size 0x2bc/0x2b8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886A5C88 | 172 | N | R | plain 3; classes COMMUTE 1,REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886A5D38 | 864 | N | S | plain 209; ltcg 209; ctx_find 209; classes OTHER 140,REG 1; size 0x250/0x360; kept: fn_8866EE48 r3 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886A7AC8 | 604 | N | S | plain 13; classes OTHER 13; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886A80F0 | 128 | E | M | plain 28; ltcg 6; ctx_find 6; classes OTHER 3,REG 3; size equal; kept: ts4_state_flag_8865DA28 r4,r9,r10; fn_equiv --trials 300: EQUIVALENT coverage 100% | done: src/xbox360/q5s_res_stroke_query.c (result variable set before the call, flag narrowed at the test; context jt_switch_flags.c + pool primer) |
| 0x886A8170 | 844 | N | S | plain 189; classes OTHER 156,REG 23; size 0x324/0x34c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886AA280 | 732 | N | S | plain 49; classes OTHER 47,REG 2; size 0x2f0/0x2dc | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886AB1A8 | 164 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886AB250 | 156 | N | R | plain 4; classes OTHER 1,REG 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886AB500 | 608 | N | S | plain 105; classes FORM 1,OTHER 84,REG 11; size 0x23c/0x260 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886AC130 | 404 | N | S | plain 87; classes OTHER 55,REG 32; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886AC9D8 | 304 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886AD158 | 148 | N | L3 | plain 23; classes OTHER 23; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x886AD1F0 | 132 | E | L3 | plain 9; ltcg 9; classes OTHER 8,REG 1; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x886AFC90 | 356 | N | S | plain 24; classes OTHER 16,REG 6; size 0x15c/0x164 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886B12D0 | 524 | N | S | plain 31; ltcg 31; ctx_find 31; classes OTHER 31; size equal; kept: ts4_addr_lbl_880F44EC_8867E7B0 r3 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886B1578 | 144 | E | L1 | plain 30; ltcg 30; ctx_find 30; classes OTHER 16,REG 12; size 0x88/0x90; kept: fn_886AD158 r3,r4,r5,r6; fn_equiv --trials 300: EQUIVALENT coverage 100% | match fn_886AD158 |
| 0x886B2638 | 912 | N | S | plain 223; classes OTHER 114,REG 12; size 0x20c/0x390 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886B4D00 | 1064 | N | S | plain 262; classes OTHER 18; size 0x58/0x428 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886B7F68 | 272 | N | S | plain 29; classes OTHER 28,REG 1; size 0x114/0x110 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886B8078 | 64 | N | S | plain 13; classes OTHER 10,REG 2; size 0x3c/0x40 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886B81E0 | 460 | N | S | plain 48; ltcg 48; ctx_find 48; classes OTHER 43,REG 1; size 0x1bc/0x1cc; kept: ts4_if_get_u32_off4c_8865EC70 r3 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886BCA88 | 528 | N | S | plain 33; classes OTHER 18,REG 13,SWAP 2; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886BF1C0 | 156 | N | S | plain 19; classes OTHER 17,REG 2; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C46C8 | 148 | N | R | plain 9; classes OTHER 7,REG 2; size equal | targeted permutation; diff is same-size reordering |
| 0x886C48C8 | 164 | N | S | plain 41; classes COMMUTE 1,OTHER 30; size 0x7c/0xa4 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C4970 | 156 | E | L3 | plain 36; ltcg 36; classes OTHER 20,REG 1; size 0x60/0x9c; fn_equiv --trials 300: EQUIVALENT coverage 100% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x886C5230 | 192 | N | S | plain 43; classes OTHER 36,REG 6; size 0xbc/0xc0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C54C8 | 328 | N | S | plain 68; classes OTHER 30,REG 37; size 0x144/0x148 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C5610 | 352 | N | S | plain 72; classes FORM 1,OTHER 40,REG 30; size 0x15c/0x160 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C5770 | 172 | N | S | plain 38; classes OTHER 15,REG 23; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C5820 | 156 | E | W | plain 39; ltcg 39; classes OTHER 28,REG 4; size 0x80/0x9c; fn_equiv --trials 300: DIFFERENT (seed 1) | source hash equals the registry, yet fn_equiv --trials 300 --seed 1 says DIFFERENT (final memory at arg2+0: original ff ff 01 f6, candidate 3f 80 11 7d); registered run was 407 trials of 1000 requested; fix the source |
| 0x886C58C0 | 212 | N | S | plain 21; classes OTHER 14,REG 7; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C5998 | 84 | N | R | plain 6; classes REG 6; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886C5A08 | 540 | N | S | plain 66; classes COMMUTE 1,OTHER 46,REG 12; size 0x200/0x21c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C5F08 | 264 | N | R | plain 5; classes OTHER 4,REG 1; size equal | targeted permutation; diff is same-size reordering |
| 0x886C6758 | 456 | N | L3 | plain 48; ltcg 48; classes OTHER 43,REG 4; size 0x1c4/0x1c8 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x886C6AE0 | 200 | N | R | plain 10; classes OTHER 4,REG 4,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886C6EE8 | 160 | N | S | plain 37; classes OTHER 33,REG 1; size 0x94/0xa0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C7C28 | 120 | E+N | L1 | plain 27; ltcg 27; ctx_find 2; classes OTHER 27; size 0x80/0x78; kept: ts4_anim_layer_index_886C66C0 f7; flags: /O1 -> 24, /Oc /O1 -> 24; fn_equiv --trials 300: EQUIVALENT coverage 100% | match fn_886C48C8 (stand-in draft exists for fn_886C48C8) |
| 0x886C7DD8 | 160 | N | L1 | plain 36; classes OTHER 34,REG 1; size 0x9c/0xa0; kept: ts4_anim_layer_index_886C66C0 f7 | match fn_886C48C8 (stand-in draft exists for fn_886C48C8) |
| 0x886C8010 | 176 | N | R | plain 9; classes REG 9; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886C80C0 | 152 | E | S | plain 18; ltcg 18; classes REG 16,SWAP 2; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886C8678 | 176 | N | R | plain 10; classes OTHER 2,REG 8; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886CB670 | 264 | N | S | plain 65; classes OTHER 50,REG 6; size 0xe4/0x108 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886CC058 | 196 | N | R | plain 41; ltcg 6; classes OTHER 6; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886CD580 | 228 | N | R | plain 5; classes COMMUTE 1,REG 4; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886CF018 | 248 | N | S | plain 14; classes OTHER 7,REG 7; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886CF760 | 244 | N | R | plain 2; classes OTHER 1,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886D0390 | 580 | N | S | plain 144; classes OTHER 130,REG 7; size 0x228/0x244 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886D0808 | 140 | E | L3 | plain 30; ltcg 32; classes OTHER 25,REG 1; size 0x7c/0x8c; fn_equiv --trials 300: EQUIVALENT coverage 100% | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x886D08F8 | 284 | N | S | plain 14; classes OTHER 12,REG 2; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886D0A18 | 712 | N | S | plain 177; classes OTHER 163,REG 9; size 0x2b4/0x2c8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886D0D88 | 148 | N | S | plain 33; classes OTHER 24; size 0x70/0x94 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886D1578 | 380 | N | R | plain 5; classes REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886D19C8 | 88 | E | T | plain 5; ltcg 5; classes OTHER 3,REG 2; size equal; fn_equiv --trials 300: EQUIVALENT coverage 100% | checker or split fix, vector class recovery (see note) |
| 0x886D1A20 | 368 | N | S | plain 80; classes OTHER 72,REG 1; size 0x154/0x170 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886D48F8 | 128 | N | R | plain 4; classes OTHER 2,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886D5028 | 140 | E | L2 | plain 30; ltcg 29; ctx_find 29; classes OTHER 24,REG 3; size 0x84/0x8c; kept: ts4_clear_three_vectors_886C3658 r4; fn_equiv --trials 300: UNCHECKED coverage 100% | context found by ltcg_ctx_find (29 off left): caller source shape / register numbering |
| 0x886D5F78 | 156 | E+N | L1 | plain 36; ltcg 36; ctx_find 34; classes OTHER 34,REG 2; size 0xa8/0x9c; kept: ga6_pair_accepts_886D0CE0 f4; flags: /O1 -> 35, /Oc /O1 -> 35; fn_equiv --trials 300: EQUIVALENT coverage 90% | match fn_886CB778, fn_886C6758 (stand-in draft exists for fn_886C6758) |
| 0x886D6BD8 | 136 | N | R | plain 6; classes OTHER 5,REG 1; size equal | targeted permutation; diff is same-size reordering |
| 0x886D8730 | 504 | N | S | plain 113; classes OTHER 109,REG 4; size 0x22c/0x1f8 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886D9AB8 | 220 | N | R | plain 1; classes REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886DA840 | 516 | N | S | plain 87; classes OTHER 81,REG 5; size 0x200/0x204 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886DC8B0 | 272 | N | S | plain 61; classes OTHER 58,REG 3; size 0x114/0x110 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886DCE78 | 308 | N | S | plain 28; classes OTHER 21,REG 5; size 0x12c/0x134 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886DEC78 | 348 | N | S | plain 82; classes OTHER 78,REG 4; size 0x16c/0x15c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886DFAE8 | 332 | N | S | plain 73; classes OTHER 68,REG 5; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886E0D08 | 340 | N | S | plain 48; classes OTHER 47,REG 1; size 0x15c/0x154 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886E3818 | 284 | N | S | plain 31; classes REG 31; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886E3938 | 112 | E | S | plain 24; ltcg 24; classes OTHER 20,REG 4; size 0x7c/0x70 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886E6470 | 692 | N | S | plain 165; classes OTHER 113,REG 52; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886E6BE8 | 416 | N | S | plain 97; classes OTHER 87,REG 7; size 0x194/0x1a0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886E7738 | 72 | E | R | plain 3; ltcg 6; classes OTHER 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886E7EF0 | 136 | E | R | plain 14; ltcg 12; classes OTHER 8,REG 4; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886E9BC8 | 296 | N | U | plain - | draft does not compile or names no function for this address |
| 0x886EBDA0 | 36 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886F0278 | 144 | N | R | plain 2; classes OTHER 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886F1A70 | 152 | N | R | plain 3; classes REG 1,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886F3350 | 80 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886F3798 | 136 | N | S | plain 14; classes OTHER 3,REG 11; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886F6348 | 120 | N | S | plain 25; classes OTHER 24,REG 1; size 0x7c/0x78 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886F99C8 | 152 | N | S | plain 34; classes OTHER 34; size 0x9c/0x98 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x886F9A60 | 144 | N | R | plain 3; classes REG 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886FC638 | 328 | N | R | plain 4; classes SWAP 4; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x886FCC50 | 132 | N | S | plain 10; classes OTHER 8,REG 1; size 0x80/0x84 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x887011A8 | 212 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88701280 | 296 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8870E8F0 | 280 | N | S | plain 49; classes OTHER 47,REG 1; size 0x114/0x118 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88720108 | 120 | N | R | plain 3; classes OTHER 3; size equal | targeted permutation; diff is same-size reordering |
| 0x88720B70 | 148 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88720E48 | 148 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88747E58 | 84 | N | R | plain 4; classes OTHER 2,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8876E0B0 | 160 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88770288 | 272 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88774260 | 160 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88778CD0 | 20 | N | R | plain 3; classes OTHER 1,REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8877C0F0 | 164 | N | R | plain 3; classes OTHER 3; size equal | targeted permutation; diff is same-size reordering |
| 0x8877F4B8 | 116 | N | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x887965D8 | 100 | N | R | plain 3; classes REG 3; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x887C7BD0 | 132 | N | R | plain 1; classes COMMUTE 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x887D56F0 | 108 | N | R | plain 2; ltcg 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x887EA898 | 112 | N | L2 | plain 26; classes FORM 1,OTHER 23,REG 2; size 0x7c/0x70; kept: fn_887E9D78 r4 | run tools/ltcg_ctx_find.py find; all callee bodies are matched |
| 0x887EC8C0 | 164 | E | R | plain 7; ltcg 7; classes OTHER 3,REG 2,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x887F1F00 | 100 | E | L3 | plain 21; ltcg 21; classes OTHER 19,REG 1; size 0x60/0x64 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x887F4C18 | 56 | E | L1 | plain 12; ltcg 12; ctx_find 12; classes OTHER 9; size 0x2c/0x38; kept: fn_887F4BA0 r3 | match fn_887F4BA0, fn_887F4708 |
| 0x887F4C60 | 56 | E | L3 | plain 12; ltcg 12; ctx_find 12; classes OTHER 9; size 0x2c/0x38; kept: fn_887F4BA0 r3 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x887F4CB0 | 56 | E | L3 | plain 12; ltcg 12; ctx_find 12; classes OTHER 9; size 0x2c/0x38; kept: fn_887F4BA0 r3 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x887F4CF8 | 56 | E | L3 | plain 12; ltcg 12; ctx_find 12; classes OTHER 9; size 0x2c/0x38; kept: fn_887F4BA0 r3 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x887F4EC8 | 56 | E | L3 | plain 12; ltcg 12; ctx_find 12; classes OTHER 9; size 0x2c/0x38; kept: fn_887F4BA0 r3 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x887F73F0 | 44 | E | R | plain 6; ltcg 6; classes COMMUTE 1,OTHER 5; size equal | targeted permutation; diff is same-size reordering |
| 0x887F8710 | 136 | E | L3 | plain 21; ltcg 21; classes OTHER 17,REG 3; size 0x84/0x88 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x887F8920 | 304 | E | L2 | plain 75; ltcg 14; ctx_find 14; classes REG 14; size equal; kept: ts4_set_u32_off0_887F7B18 r3,r7,r9 | context found by ltcg_ctx_find (14 off left): caller source shape / register numbering |
| 0x887F8A50 | 304 | E | L2 | plain 75; ltcg 14; ctx_find 14; classes REG 14; size equal; kept: ts4_set_u32_off0_887F7B18 r3,r7,r9 | context found by ltcg_ctx_find (14 off left): caller source shape / register numbering |
| 0x887FAA48 | 180 | N | L2 | plain 23; ltcg 1; classes COMMUTE 1; size equal; kept: ts4_index_to_name_hash_887F7BC8 r3,r5,r6,r7,r8,r9 | run tools/ltcg_ctx_find.py find; all callee bodies are matched |
| 0x8886AB08 | 160 | N | S | plain 27; classes OTHER 22,REG 5; size 0xa4/0xa0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8886FE50 | 128 | E | S | plain 30; ltcg 30; classes OTHER 22; size 0x60/0x80 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8886FED0 | 132 | E | S | plain 31; ltcg 31; classes OTHER 24; size 0x68/0x84 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888795F8 | 144 | E | R | plain 9; ltcg 17; classes OTHER 6,REG 3; size equal | targeted permutation; diff is same-size reordering |
| 0x88879C48 | 220 | N | S | plain 47; classes OTHER 45,REG 1; size 0xd8/0xdc | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8887C000 | 152 | E | S | plain 12; ltcg 12; classes OTHER 11; size 0x94/0x98 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x8887DA38 | 88 | E | R | plain 6; ltcg 6; classes OTHER 4,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8887EB10 | 136 | E+N | R | plain 2; ltcg 6; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88880750 | 148 | E | T | plain 25; ltcg 25; classes OTHER 18; size 0x78/0x94 | checker or split fix, vector class recovery (see note) |
| 0x88883CD0 | 120 | E | S | plain 23; ltcg 23; classes OTHER 22; size 0x74/0x78 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88885408 | 168 | E | T | plain 2; ltcg 2; classes OTHER 2; size equal | checker or split fix, vector class recovery (see note) |
| 0x88885BB8 | 92 | E+N | L3 | plain 23; ltcg 23; classes OTHER 17,REG 5; size 0x58/0x5c; flags: /O1 -> 22, /Oc /O1 -> 22, /GS- -> 22, /Ox -> 22 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x88886608 | 112 | E | S | plain 15; ltcg 15; classes OTHER 14; size 0x6c/0x70 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88888C80 | 116 | E+N | R | plain 2; ltcg 4; classes OTHER 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88888CF8 | 176 | E | R | plain 6; ltcg 6; classes OTHER 5,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88888DA8 | 152 | E+N | L3 | plain 36; ltcg 36; classes OTHER 34; size 0x90/0x98 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x88888E40 | 168 | E | R | plain 6; ltcg 6; classes OTHER 1,REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88888EE8 | 168 | E | R | plain 9; classes OTHER 4,REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8888C2B0 | 272 | N | U | plain - | triage run did not reach it |
| 0x8888D120 | 256 | N | U | plain - | triage run did not reach it |
| 0x88890860 | 140 | N | U | plain - | triage run did not reach it |
| 0x888AE188 | 92 | N | U | plain - | triage run did not reach it |
| 0x888AF5C0 | 144 | N | U | plain - | triage run did not reach it |
| 0x888B1960 | 148 | E | L3 | plain 31; ltcg 31; classes OTHER 30; size 0x90/0x94 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x888B3BF0 | 112 | E | T | plain 21; classes OTHER 21; size 0xa8/0x70 | checker or split fix, vector class recovery (see note) |
| 0x888B7360 | 116 | E | L3 | plain 20; classes OTHER 18; size 0x6c/0x74 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x888B8D98 | 172 | E | R | plain 8; classes OTHER 6,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888BB670 | 8300 | E | S | plain 2048; classes OTHER 1592,REG 16; size 0x198c/0x206c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888C00A0 | 80 | N | R | plain 1; classes FORM 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888C1368 | 152 | E | S | plain 34; classes OTHER 30; size 0x88/0x98 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888C15A0 | 128 | E | S | plain 28; classes OTHER 24; size 0x70/0x80 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888C1910 | 128 | E+N | S | plain 28; classes OTHER 23,REG 5; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888C3198 | 136 | E | S | plain 31; classes OTHER 25,REG 3; size 0x7c/0x88 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888C3940 | 92 | E | S | plain 10; classes OTHER 7,REG 2; size 0x58/0x5c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888C4160 | 140 | E | R | plain 4; classes REG 4; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888C51D0 | 128 | N | R | plain 12; classes OTHER 12; size equal | targeted permutation; diff is same-size reordering |
| 0x888C5C00 | 144 | E+N | M | plain 33; ltcg 2; ctx_find 2; classes COMMUTE 2; size equal; kept: ts4_pad_record_find_88614938 f1,f2 | done: src/xbox360/q5s_res_pad_stick.c (literal 65535.0f, x stored first; context pr2_signin.c + pool primer) |
| 0x888C5D80 | 144 | E | S | plain 28; classes OTHER 27; size 0x8c/0x90 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888C5E10 | 168 | E | S | plain 22; classes OTHER 9,REG 13; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888C5EB8 | 56 | E | R | plain 6; classes OTHER 4,REG 2; size equal | targeted permutation; diff is same-size reordering |
| 0x888C80A0 | 148 | N | R | plain 2; classes OTHER 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888C93E8 | 176 | N | R | plain 2; ltcg 42; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888C9940 | 160 | E | L3 | plain 33; ltcg 33; classes OTHER 29,REG 2; size 0x98/0xa0 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x888CAA98 | 104 | E | R | plain 7; classes OTHER 2,REG 5; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888CB5F8 | 144 | E | S | plain 20; classes OTHER 20; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888CB9D0 | 80 | E | S | plain 18; classes OTHER 6,REG 12; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888CDBC8 | 124 | E+N | L3 | plain 4; classes OTHER 4; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x888CF290 | 328 | N | S | plain 77; classes OTHER 76; size 0x144/0x148 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888D0150 | 328 | N | S | plain 77; classes OTHER 76; size 0x144/0x148 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888D0F00 | 220 | N | R | plain 2; classes OTHER 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888D3850 | 184 | N | L3 | plain 32; ltcg 26; classes REG 26; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x888D4EF8 | 168 | E | L2 | plain 40; ltcg 37; ctx_find 37; classes OTHER 35,REG 1; size 0xa4/0xa8; kept: ts4_slotset_has_pending_888CA680 r4,r5 | callee body links with exact kill set; target holds a zero result in r31 and it/end in r5/r4 across the call; 3 result-variable variants still const-propagate the 0 (37 off) |
| 0x888D66C8 | 88 | E | R | plain 6; classes REG 4,SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888D82E0 | 136 | N | S | plain 34; classes OTHER 30,REG 1; size 0x7c/0x88 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888D9368 | 76 | E | S | plain 15; classes OTHER 10,REG 4; size 0x48/0x4c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888DA288 | 104 | E | R | plain 11; classes OTHER 9,REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888DA428 | 136 | E | S | plain 31; classes OTHER 28,REG 3; size 0x8c/0x88 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888DDD70 | 172 | E | S | plain 15; classes OTHER 9,REG 5; size 0xa8/0xac | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888DF740 | 112 | E | R | plain 8; classes OTHER 7,REG 1; size equal | targeted permutation; diff is same-size reordering |
| 0x888E1FC0 | 216 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888E4CA0 | 172 | E | R | plain 3; classes OTHER 2,REG 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888E5190 | 164 | E | L3 | plain 34; ltcg 34; classes OTHER 29,REG 2; size 0x98/0xa4 | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x888E6C78 | 124 | E | S | plain 13; classes OTHER 12; size 0x78/0x7c | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888E7278 | 144 | E | S | plain 22; classes OTHER 21,REG 1; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888EC548 | 176 | E | S | plain 39; classes OTHER 35,REG 2,SWAP 2; size 0xbc/0xb0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888EC5F8 | 176 | E | S | plain 39; classes OTHER 35,REG 2,SWAP 2; size 0xbc/0xb0 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888ED7E0 | 220 | N | S | plain 20; classes OTHER 19; size 0xd8/0xdc | different statement or type shape: size or instruction mix differs; class recovery |
| 0x888FA078 | 124 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x888FD948 | 128 | E+N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8890C618 | 80 | N | R | plain 1; classes FORM 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8890DF58 | 104 | N | R | plain 2; classes SWAP 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x8890E1C8 | 108 | E+N | T | plain 25; ltcg 2; classes REG 2; size equal | checker or split fix, vector class recovery (see note) |
| 0x8890EE68 | 240 | N | S | plain 51; classes OTHER 51; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88912018 | 104 | N | L3 | plain 8; classes OTHER 6,REG 2; size equal | LTCG route with the real caller/callee units in one link; not reachable from one function |
| 0x88912118 | 168 | N | R | plain 1; classes COMMUTE 1; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88916F48 | 136 | N | U | plain - | triage run did not reach it |
| 0x88922F78 | 108 | N | R | plain 9; classes COMMUTE 1,REG 8; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88925410 | 24 | N | R | plain 2; classes REG 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x88944378 | 340 | N | S | plain 57; classes OTHER 49,REG 8; size 0x15c/0x154 | different statement or type shape: size or instruction mix differs; class recovery |
| 0x88947468 | 316 | N | R | plain 2; classes OTHER 2; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x889A0BE8 | 116 | N | R | plain 4; classes REG 4; size equal | targeted permutation (regalloc_mutate), member/accessor form, OP1 pads |
| 0x889C0DC0 | 308 | N | S | plain 39; classes OTHER 37,REG 2; size equal | different statement or type shape: size or instruction mix differs; class recovery |
| 0x889C1478 | 64 | N | L1 | plain 8; ltcg 8; classes OTHER 7,REG 1; size 0x44/0x40; kept: fn_889C1160 r4 | match fn_889C1160 |
| 0x889C1C80 | 748 | N | S | plain 96; classes OTHER 75,REG 21; size 0x2f8/0x2ec | different statement or type shape: size or instruction mix differs; class recovery |
| 0x889C29E8 | 204 | N | S | plain 37; classes OTHER 37; size 0xdc/0xcc | different statement or type shape: size or instruction mix differs; class recovery |
