# 0x886B8468 ts4_move_planner_transition_886B8468 — byte-match log

Target: Swing_DLL.xex 0x886B8468, size 0x2300 (2240 instructions), /GL + /LTCG, /Oc.
Candidate: src/xbox360/q5_move_planner.c (copy of the proven equivalent src/xbox360/eq_q5b_move_planner.c).

Measurements (TS4_MATCHING_DIR=work/matching-b215 -> b218, cl 16.00.10224 PPC):

- "fn_check" = `python3 tools/fn_check_ltcg.py src/xbox360/q5_move_planner.c ts4_move_planner_transition_886B8468=0x886B8468 --flags /Oc <contexts> --context src/xbox360/pp1_pool_primer.c`
  (positional differing-instruction count; meaningless while the sizes differ).
- "aligned off" = max(target, candidate instruction count) - instructions equal after a difflib alignment of the two
  listings with branch displacements and pool offsets normalised (scratch script, not in the repo).

Context sets:
- C0: pool primer only.
- C1: `flags(/Ob1):src/xbox360/q5_ctx_move_planner_callees.c`, `flags(/Ob1):src/xbox360/q5_ctx_path_sample.c`,
  `flags(/Ob1):src/xbox360/fk5_001.c`, `flags(/Ob1):src/xbox360/ga1_gameplay_a.c`,
  `flags(/Ob1):src/xbox360/ltcg_ctx_rally_active_8866D930.c`, then the pool primer.

| step | context | size | fn_check differing | aligned off | epilogues (target 39) | note |
|---|---|---|---|---|---|---|
| 0 | C0 | 0x1e20 | 2224 | 1312 | 1 | unmodified equivalent; saves v126/v127, __savegprlr_18, frame 0x200 |
| 0 | plain route | 0x1e20 | 2224 | - | 1 | same as C0 |
| 1 | C1 | 0x2020 | 2221 | 1275 | 1 | vector callees in the link: no vector saves, frame 0x1b0 |
| 2 | C1 | 0x1fc4 | 2226 | 1256 | 36 | every `return X` in the switch -> `next = X; break;`, one `return next` after the switch |
| 3 | C1 | - | - | 1231 | 36 | preamble rewritten from the listing: reads through `p->state` in target order, flags computed before use |
| 4 | C1 | - | - | 1224 | 36 | condition flags as `int` tested through `(unsigned char)flag` (target: `mr rX,r20` then `clrlwi; cmplwi` at the test) |
| 5 | C1 | - | - | 1218 | 36 | path getters as by-value inline wrappers (callee out-buffer shares the dot-temp slot) |
| 6 | C1 | 0x2100 | 2181 | 1064 | - | cases 0..6 rewritten from the listing (reads through `s->player`, inline helpers re-read fields) |
| 7 | C1 | - | - | 1077 | - | tuning constants as float literals (pool primer places them); gives the entry hoist of f28=1.0, f29=pi/2, pool base |
| 8 | C1 | - | - | 1074 | - | named `static const float q5b_zero` for 0.0f: f30 load and `&zero` share one `lis` |
| 9 | C1 | - | - | 1062 | - | receiver block: `ai` read before the component scan |
| 10 | C1 | - | - | 1053 | - | first/last sample helpers with list accessors (the game's 0x8865A410 / 0x8865A3E8 inlined): `clrrwi` copies |
| 11 | C1 | - | - | 1023 | - | cases 20..22, 15, 16 rewritten from the listing; candidate 2159 instructions |
| 12 | C1 | 0x21e0 | 2142 | 1009 | 37 | case 20..22: the save-aim tail written in both branches as the target has it twice; candidate 2168 instructions |

| 13 | C1 | - | - | 976 | - | cases 18, 17, 14 rewritten from the listing (flag + branch-free lead select, list pointer, half-word sign test, frames-to-contact helper) |
| 14 | C1 | 0x2240 | 2178 | 694 | 37 | candidate-set position through a relative-array helper `(char *)a + a->offset` with `a = &set->positions`: removes a hoisted `li rX,4`, prologue becomes `__savegprlr_20` and r20..r27 line up; side select as `set = s->sets; if (!side) set++` |

From step 13 on a second number is tracked: "loose off" = the aligned count with register numbers and r1 offsets
masked, i.e. the instructions that differ in more than allocation. Step 12: 274, step 14: 255.

| step | context | size | fn_check differing | aligned off | loose off | epilogues (target 39) | note |
|---|---|---|---|---|---|---|---|
| 15 | C1 | - | - | 692 | 254 | - | set-y as a one-expression inline `__vrlimi(v, __lvlx(&y, 0), 4, 3)` called with the literal 0.0f; named static zero removed (the literal's address is hoisted into r27 and shares the `lis` with the f30 load) |
| 16 | C1 | 0x22b8 | - | 680 | 201 | - | case 7 rewritten from the listing (line-through helper, wrapped-angle helper, `>= 0` table select as inline helper, half-word sign tests); candidate 2222 instructions, frame 0x190 |
| 17 | C1 | 0x22b4 | - | 686 | 199 | - | variant: second half of case 7 in an inline helper `q5b_time_to_run_line`; 2221 instructions. Not kept (strict count worse) |
| 18 | C1 | 0x22b8 | 2063 | 679 | 201 | 38 | step 16 plus one function-scope temporary per call of the by-value position getter; frame 0x1c0 (target 0x1d0); unused helpers removed. **Final state** |

Final check line (step 18), command as in the header with context set C1:

    FAIL ts4_move_planner_transition_886B8468 vs fn_886B8468 @ 886B8468: size 0x22b8 != target 0x2300; 2063 differing instruction(s), first at +0x10; relocation layout differs (target 222, candidate 220)

The positional fn_check count is not meaningful while the sizes differ (everything after the first size difference
is shifted). Aligned: target 2240 instructions, candidate 2222, 1561 equal, 679 off; with register numbers and r1
offsets masked 2039 equal, 201 off. Loose off per region (off/target instructions): preamble 59/300, case 0 0/27,
case 1 17/369, case 2 6/99, case 3 0/15, case 4 0/27, cases 5-6 0/80, cases 20-22 1/166, case 15 35/266, case 16
0/38, case 18 4/95, case 17 11/154, cases 10-11 0/26, case 12 1/44, case 14 24/142, case 13 4/16, case 19 17/75,
case 8 0/10, case 7 14/229, case 9 8/57, tail 0/5.

## Experiments that did not help

- Named `static const float` zero used by value (for the `fcmpu/mfcr/.../lfsx/fsel` table select): every 0.0f literal
  is redirected to it, the f30 hoist disappears (`lfs f0,0(r27)` at each use), only f29..f31 are saved inline and the
  epilogue is no longer duplicated (2085 instructions, aligned off 850). A global zero (const or not) defined in a
  context object is not hoisted either. The select comes out with the literal when written as an inline helper.
- Function-scope getter temporaries at step 14 state: frame 0x1e0 and slot order c17 0x100, c7b 0x110, c15 0x120,
  c7a 0x130, c1 0x140. At step 18: frame 0x1c0, c1 0xe0, c7b 0xf0, c15 0x100, c7a 0x110, c17 0x120. Target: frame
  0x1d0, c17 0xf0, c7a 0x100, c7b 0x110, c1 0x120, c15 0x130. Declaration order and names do not change the order.
- Declaring ts4_if_get_u32_off4c_8865EC70 as returning a struct by value: the LTCG link fails (the context
  definition in fk5_001.c is `void f(ts4_word, ts4_word)`).
- Side select as `side ? &sets[0] : &sets[1]` or if/else: `beq; lwz; b; lwz; addi` instead of the target's
  `cmplwi; lwz; bne; addi 0x60` (kept: `set = s->sets; if (!side) set++;`).
- `pos = s->player->state->pos` to force the reload of the state pointer after the path getters: reloads, but adds
  a `lwz 0x154(r31)` the target does not have.
- Variants of the sample-list accessors (`&l->begin[i]`, begin/end getters, direct member reads) for the target's
  real reload `addi rL,pred,0x5a0; lwz rX,0(rL)`: the candidate gives either a `clrrwi` copy or full CSE.
- Without the real bodies of fn_8868ED00 / ts4_vec_with_offset_8867A908 / fn_8867A7C0 in the link (context fk5_001
  only) the state pointer is reloaded after those calls as in the target, but then v126/v127 are saved and the
  volatile-register use across the calls is lost.

## Blockers (why this stops here)

1. Memory mod/ref of the vector getters. The target keeps volatile registers across fn_8868ED00 /
   ts4_vec_with_offset_8867A908 (so it had their clobber sets) but reloads `p->state` after them; with the matched C
   bodies in the link the candidate keeps `p->state` in a saved register. Likely the originals are C++ members
   returning a vector class by value, whose hidden return pointer is not disambiguated from player state. No C
   spelling of the callees found that matches them and is treated as writing unknown memory.
2. Struct-return temporaries: the target has one stack slot per call of ts4_if_get_u32_off4c_8865EC70, ordered
   main-body sites first, then case 1, then case 15 (as if cases 1 and 15 were inlined handlers). The C candidate
   cannot reproduce that order, so the frame (0x1c0 vs 0x1d0) and about 480 r1-offset/register-only differences
   remain.
3. Identical-block merging: the target keeps four `li r21,0x11` epilogues and merges all "hold" blocks into the copy
   at the end of case 2; the candidate keeps the first copies (38 epilogues instead of 39).
4. Three callees are not exact in the link: fn_8867A7C0 (0x140 vs 0x144, 40 off), fn_886600E0 and fn_8865DBA8 (no
   source) - the target keeps `pred` in r4 across fn_886600E0, which needs that callee's clobber set.

## Behaviour of the candidate and of the equivalent (2026-11-23, work/matching-b215, fn_equiv/6, seed 1, /Oc)

- `python3 tools/fn_equiv.py src/xbox360/q5_move_planner.c ts4_move_planner_transition_886B8468=0x886B8468 --flags /Oc --time 300 --trials 6000`:
  no difference, 4109 valid of 6000, coverage 78% (285/366), verdict UNCHECKED (coverage below 90%).
  Source sha256 00335e27438150088c1f34d9770f7acf8f70fd18fd38f38973306e3b20e7780b (same file as
  src/xbox360/drafts/q5_move_planner_best.c).
- `python3 tools/fn_equiv.py src/xbox360/eq_q5b_move_planner.c ... --flags /Oc --time 300 --trials 800 --json work/specs/Q5/eq_q5b_move_planner.equiv.json`
  (after the comment-only byte-gap update, source sha256 d4567b527632070ede7d892ace96bacd5d5fd85aaa852b024bb5cc2c12f1cb2c):
  no difference, 535 valid of 800, coverage 53% (195/366). With `--trials 6000` (not written to the json): 4109
  valid, coverage 78% (285/366).
