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

# Round 2 (2026-11-23, work/matching-b215, cl 16.00.10224 PPC, /O2 /Oi /Oc /GL + link /LTCG)

Candidate is now C++: src/xbox360/drafts/q5_move_planner_best.cpp (sha256
46f3eb8fa66c0f4ed64517b0767aa66e4032b704007d97478d09a9067080e074); drafts/q5_move_planner_best.c and
src/xbox360/q5_ctx_path_sample.c are removed (superseded). Not matched.

## Callees (step 1)

| address | name | result | source | spec |
|---|---|---|---|---|
| 0x8867A7C0 | ts4_path_sample_8867A7C0 (was fn_8867A7C0) | MATCH, 0x144 | src/xbox360/q5_path_sample.cpp (C++) | work/specs/Q5/q5_path_sample.json |
| 0x8868ED00 | ts4_path_weighted_ahead_8868ED00 (was fn_8868ED00) | MATCH, 0xb4 | src/xbox360/q5_ctx_move_planner_callees.c | work/specs/Q5/q5_path_getters.json |
| 0x8867A908 | ts4_vec_with_offset_8867A908 | MATCH, 0x68 | same file | same spec |
| 0x886600E0 | ts4_prediction_ticks_until_x_886600E0 (was fn_886600E0) | MATCH, 0x110 | src/xbox360/q5_prediction_ticks_until_x.c | work/specs/Q5/q5_prediction_ticks_until_x.json |
| 0x8865DBA8 | ts4_swing_select_best_sample_8865DBA8 (was fn_8865DBA8) | near miss: size 0x784 == target, 266 aligned off, 63 loose off | src/xbox360/drafts/q5_select_best_sample.c | none |

Commands (each prints MATCH):

    python3 tools/fn_check_ltcg.py src/xbox360/q5_path_sample.cpp ts4_path_sample_8867A7C0=0x8867A7C0 --flags /Oc --context src/xbox360/pp1_pool_primer.c
    python3 tools/fn_check_ltcg.py src/xbox360/q5_ctx_move_planner_callees.c ts4_path_weighted_ahead_8868ED00=0x8868ED00 ts4_vec_with_offset_8867A908=0x8867A908 --flags /Oc --context "flags(/Ob1):src/xbox360/q5_path_sample.cpp" --context src/xbox360/pp1_pool_primer.c
    python3 tools/fn_check_ltcg.py src/xbox360/q5_prediction_ticks_until_x.c ts4_prediction_ticks_until_x_886600E0=0x886600E0 --flags /Oc --context src/xbox360/cl1_clrrwi_reload.c --context src/xbox360/pp1_pool_primer.c

Source sha256: q5_path_sample.cpp b7ddf4c5d7717197b4c47a6fe55bcfa8fedbc9785c4de89223f388e024a4d930,
q5_ctx_move_planner_callees.c 25d2aa963c348a6be24f8aa962d96bd769100797819d10c7dd6ebedea789d2bb,
q5_prediction_ticks_until_x.c e4c91c4d24a898fa491a86186b52e9bd711ea5d702209e0e15298b471108e606,
drafts/q5_select_best_sample.c d7ca295af8402dcb3401fc0dd33dbceb32d34ad097e07ec9dc31e7f497bb0d4f.

fn_check_ltcg.py compiles a .cpp source or context as it is (cl decides by extension); no tool change was needed.
A C++ function without C linkage is mapped by its decorated name
(`'?f@@YA?AUQ5Vec@@PBUQ5bPlayer@@@Z=0x8865EC70'`).

Other callees of the planner without a matched source (not attempted, 31): fn_8817B608, fn_881896F8, fn_88189888,
fn_8826AC10, fn_8826D3A0, fn_88564BF8, fn_8866BD00, fn_8866BDD8, fn_8866BFE8, fn_8866C150, fn_8866D180, fn_8866D930
(context stand-in ltcg_ctx_rally_active_8866D930.c), fn_8866E318, fn_88678548, fn_88678708, fn_886787D8, fn_886877A8,
fn_88687AC0, fn_886884E8, fn_886987C8, fn_88699300, fn_88699FC0, fn_886A26E0, fn_886A2BE8, fn_886A2E48, fn_886A3440,
fn_886A58F0, fn_886A9678, fn_886A9A48, fn_886A9E48, fn_886B81E0.

## Planner (steps 2 and 3)

The counts below come from this round's scratch script; they are not identical to round 1's (its loose mask was
wider). Round 1's final file measures 681 aligned off / 294 loose off with this script (round 1 reported 679 / 201).
Call targets are compared by address, so renamed callees do not count. The loose count includes the 23 jump-table
words, which cannot compare equal while the sizes differ.

Context sets:
- C2 (exact callees): `flags(/Ob1):src/xbox360/q5_ctx_move_planner_callees.c`,
  `flags(/Ob1):src/xbox360/q5_path_sample.cpp`, `flags(/Ob1):src/xbox360/q5_prediction_ticks_until_x.c`,
  `flags(/Ob1):src/xbox360/cl1_clrrwi_reload.c`, `flags(/Ob1):src/xbox360/fk5_001.c`,
  `flags(/Ob1):src/xbox360/ga1_gameplay_a.c`, `flags(/Ob1):src/xbox360/ltcg_ctx_rally_active_8866D930.c`, pool primer.
- C3 = C2 + `flags(/Ob1):src/xbox360/drafts/q5_select_best_sample.c` (the near-miss arg-max: an inexact body, used
  only for its register use; r3..r7 survive the call in the target and in the near miss).

| step | form | context | size | frame | aligned off | loose off | note |
|---|---|---|---|---|---|---|---|
| r1 final | C | C1 (round 1) | 0x22b8 | 0x1c0 | 681 | 294 | round 1 file, this round's script |
| 20 | C | C2 | 0x22b8 | 0x1c0 | 683 | 291 | exact sampler and ticks-until-x in the link |
| 21 | C | C3 | 0x22b8 | 0x1c0 | 673 | 282 | plus the near-miss arg-max |
| 22 | C | C3 | 0x22b0 | 0x1c0 | 664 | 270 | cases 15 and 7: position getter called before `pred = p->own_ball->prediction` is read (target: `bl getter; lwz 0xb4; lfs f1,0(r3); lwz 0x88`) |
| 23 | C++, same source, all `extern "C"` | C3 | 0x229c | 0x1c0 | 679 | 281 | compiling as C++ alone changes about 15 instructions |
| 24 | C++ | C3 | 0x229c | 0x1c0 | 640 | 275 | path-getter wrappers return `Q5Vec` (class with user-declared destructor) by value: preamble vector registers number as the target (v61, v60, v59, v57, v56, v58, v55, v54, v63, v53) |
| 25 | C++ | C3 | 0x22a0 | 0x1d0 | 605 | 237 | preamble: mirror call through an inline helper `q5b_mirror_point(&contact, p->state)`; frame is the target's 0x1d0. **Final state** |
| 25 | C++ | C2 | 0x22a0 | 0x1d0 | 624 | 252 | final file without the near-miss context |

Final check line (step 25, C3):

    python3 tools/fn_check_ltcg.py src/xbox360/drafts/q5_move_planner_best.cpp ts4_move_planner_transition_886B8468=0x886B8468 --flags /Oc <C3 contexts> --context src/xbox360/pp1_pool_primer.c
    FAIL ts4_move_planner_transition_886B8468 vs fn_886B8468 @ 886B8468: size 0x22a0 != target 0x2300; 2061 differing instruction(s), first at +0x30; relocation layout differs (target 222, candidate 220)

Target 2240 instructions, candidate 2216; 38 epilogues (target 39).

## C++ experiments for blockers 1 and 2

- The three path functions take `out` explicitly (self r3, out r4). A member or free function returning a class by
  value gets the hidden result pointer in r3 and the object in r4, so they are not by-value members. Blocker 1's
  hypothesis in that literal form is refuted.
- The position getter 0x8865EC70 does have the by-value convention (result pointer r3, player r4, r3 preserved). It
  byte-matches as a typed C++ function (scratch; fk5_001.c already owns the address, so no second source was added):

      Q5Vec ts4_player_court_position_8865EC70(const Q5bPlayer *p)
      {
          __vector4 v = p->state->pos;
          if (p->team->state->side_tag == (int)0xA2EDA1E7u) {   /* side_tag read as int: cmpw */
              v = vx1_set_x(v, -v.v[0]);
              v = vx1_set_z(v, -v.v[2]);
          }
          Q5Vec r;
          r.v = v;
          return r;
      }

  MATCH for `struct Q5Vec { __vector4 v; }` and for the class with constructor and destructor.
- Planner calling it by value, `Q5Vec` a plain struct: every call copies the returned struct to a second temporary
  (`ld/ld/std/std`), which the target does not do (it reads through the returned r3). Size 0x22fc is close to the
  target by accident; 679 / 302. Slot order as in C.
- Planner calling it by value, `Q5Vec` with destructor: reads through r3 as the target, but 673 / 299 on top of step
  24 (640 / 275), frame 0x1b0. Not kept; the explicit-out C spelling stays.
- Blocker 2 (slot order). Target: case 1 0x120, case 15 0x130, case 17 0xf0, case 7 first 0x100, case 7 second
  0x110. Step 25: 0x130, 0x110, 0xf0, 0x120, 0x100 (same five slots, other order). Findings: a temporary that lives
  in an inlined helper or an inlined whole-case handler is packed into a low slot shared with other inlined
  temporaries (0x80/0x90/0xa0) and the frame shrinks (0x1a0..0x1b0), so the target's five distinct slots are all
  main-body temporaries; moving any one temporary reorders the others (pod: e0,100,120,110,f0; one site in a
  helper: f0,e0,110,[80],100), so the order is the stack packer's and not the declaration or creation order.
  Not solved.
- Blocker 1 (state reload). The candidate reloads `p->state` after ts4_if_get_8865E730 (body in fk5_001.c writes
  through untyped pointers) and keeps it in r29 across the two path getters; the target reloads it after the first
  path getter (`lwz r11,0x74(r30)` at 0x886B85B4). The destructor class for the wrapper result does not change that.
  Not solved.
- Whole cases 1 and 15 as inline handlers (the slot order suggested it): size becomes exactly 0x2300 but the frame
  drops to 0x1a0 and the counts get worse (846 / 392). Not kept.
- The mirror helper at the second call site (case 14) or a `st` local with `st->sample` helpers there: frame grows
  past 0x1d0, 643..654 / 276..299. Not kept. The gain of step 25 is tied to the frame size becoming 0x1d0;
  `contact` itself sits at 0xa0 in the candidate and at 0x60 in the target.

## Codegen rules found in round 2

1. Hidden result pointer: for a function returning a class by value the result pointer is r3 and `this`/first
   argument is r4.
2. A class with a user-declared destructor returned by value from an inline is a real memory temporary: an in-place
   `o->v = a->v; o->v = __vaddfp(o->v, l)` becomes `vor128` + `vmaddfp128` (late store-to-load forwarding), the
   result is stored to the stack and block-copied (`ld/ld/std/std`) to `*out`. A plain struct, a constructor-only
   class, a union, memcpy or a local are enregistered and give `vmaddfp v0,v12,v13`.
3. VMX128 expression temporaries take v63 downward in creation order and a register is never reused inside the
   function; a load removed by late CSE still consumes a number (a gap in the sequence).
4. A vector load from a named global always takes v63; a vector literal (`__vector4 z = { 0, 0, 0, 0 }`) becomes a
   `__vmx@...` pool entry and takes the next sequential register. lbl_880FC650 is such a literal.
5. Two loads through the same named pointer are merged early; two loads through separately written accessor
   expressions (`a->Back()` twice) are merged late: one materialised address (`subi r11,r10,0x10; lvx rB`) and the
   gap of rule 3.
6. `__lvx` / `__stvx` are not intrinsics in this c1.dll (calls); only the `_volatile` forms are.
7. LTCG inlining of a real out-of-line accessor (ts4_first_record_8865A410, ts4_last_record_8865A3E8) leaves a
   `clrrwi rX,rY,0` copy and reloads the fields per inlined call.
8. `int result = -1; ... result = x; break; ... return result;` in both loops gives the preloaded `li r3,-1`,
   `beqlr` exits and one shared tail.
9. The same C body compiled as C++ can differ: in 0x8868ED00 `*out = __vaddfp(*out, l)` is fused early on volatile
   v0/v12/v13 in C++ and late on v56.. in C (the target). The two path getters therefore stay C.
10. An unrolled-by-4 loop needs the bounds in locals: with `i <= window_at(k)->end` in the condition the loop of
    0x8865DBA8 is not unrolled at all.
11. Argument order: the target evaluates the by-value getter before it loads the first argument of the call that
    consumes the result (`ticks_until_x(pred, pos(p).x)` with `pred` read after the getter).

## Remaining blockers

1. State reload after the first path getter (old blocker 1), unexplained.
2. Order of the five position-getter result slots (old blocker 2); frame size is now right.
3. 38 epilogues instead of 39 and the hold-block merge (old blocker 3), not worked on.
4. 0x8865DBA8 not exact; 31 further callees have no source, so their clobber sets are unknown to the link.
5. Not done: tools/perm_auto.py (the remaining differences are not register/scheduling only), fn_equiv coverage.

## Equivalent after the comment-only byte-gap update (round 2)

`python3 tools/fn_equiv.py src/xbox360/eq_q5b_move_planner.c ts4_move_planner_transition_886B8468=0x886B8468 --flags /Oc --time 300 --trials 800 --json work/specs/Q5/eq_q5b_move_planner.equiv.json`
(source sha256 0c34d7bdd956823733e683ce6e9466c4aa73c25b57860636030d9559bd6b8ea1): no difference, 535 valid of 800,
coverage 53% (195/366), verdict UNCHECKED as before. The C++ draft was not run through fn_equiv.
