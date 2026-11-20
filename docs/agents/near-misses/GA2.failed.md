GA2 failed functions (first divergence and what was tried). Everything not listed here and not in work/specs/GA2/ was not attempted.
0x88676898 StartGame: 8 insns off (D1's hint reproduced). With p=players, p1=&p[1], set entry as (char*)p+(offset+cur*12) the loads match; else branch has flags/target in swapped regs (r10/r11). permute.py over decl order, cfg/flags load order and target ?: forms found nothing.
0x88661D28, 0x886624C8 (select current entry): structure and loads match, but the last reload of b->selector (for pending_42c/entry_410) lands in r4/r3 instead of r11 (the dead ctx register). Tried locals vs chained, struct-typed vs cast access, reuse of variables.
0x8866D218: stw 0x18(r3) must precede the lwz 0x74 and lfs; scheduler puts lfs/lwz first, permute (free) best diff 8.
0x88670918 (4x lvx128/stvx128 copy): target loads all four vectors then stores; candidate interleaves. Not retried with __lvx intrinsics.
0x88670BD8 (Vec10 scale): lvlx128/vspltw128 splat of the stack float matches in form, scheduling of lfs/fmuls differs (14 insns).
0x88666EE0 (counter wrap 7->0): same instruction sequence (xoris/subf/addc/subfe/and) but the li constants land in r9/r8 instead of r11/r9.
0x886690B0 (11 byte stores + self->owner=0): zero constant gets r11 and the pointer r10 (target: pointer r11, zero r10, flags reuse r11). All store orders and local layouts tried.
0x8866EB80: target copies 0x7FFFFFFF into five registers (mr r5..r9) before the stores; five separate locals and CSE-defeating forms not tried beyond the obvious.
0x8866DF18: only the order of lwz 0x48(r4) vs the lis/ori/stw of the constant differs (scheduler hoists the constant); permute free order did not help.
0x8866A608, 0x8866A8C8, 0x8866ABD0, 0x8866AF38 (four identical 'arm both sides' setters): matched except 2 insns: the add of (hdr, rel) for the 2nd and 4th store has operands swapped (add r7,r10,r9 vs add r7,r9,r10). Reloads/sub-struct side[2] form already reproduces everything else.
0x88669040: callees fn_88668DF8/fn_88668D70 keep r5 (zero) alive across the calls and return this in r3: custom register convention (LTCG), not matchable per object.
0x886603C0 (index out of range test on the 8-byte-element vector at owner+0x7C): target tests (end-begin)&~7 (clrrwi 3) then srawi 3; all if/return/bool forms give srawi. only.
0x886615D0 (release registered object): needs 'clrrwi r9,r10,0' after refs-1 (known unreproduced idiom), rest matches (see 0x88661638 acquire, matched).
0x88660F08, 0x886614F8 (id lookup in 0x70-byte records, self-relative): loop matches; target keeps n in the param register r5 and found=0 in r4, candidate uses r31/r5 (8 insns).
0x886626D8 (clear flag byte of 8-byte slots): begin/end each get their own rel==-1 test in the target (not merged) and the sub-struct pointer at +0x40C is kept as a separate register; candidate merges the tests and folds 0x40C.
0x88667ED0, 0x88667FA8, 0x88668780, 0x886685E0, 0x88668568, 0x88667C98 (stats counters in the 0x134-byte player records at owner+0x5C): the first two accesses via a local pointer to the rel header reproduce; the third (via self->owner->hdr.rel directly) and the 'sub-struct at state+0x90/+0x110' address materialisation do not (candidate folds the constant offsets).
0x886777B8, 0x88677380, 0x886779C0 (point-state hash from points/total): all branches/constants match; target computes the players base twice (mr r9,r10 / add) and keeps high/mid flags in r8/r7; candidate CSEs and uses r9/r8.
0x88677480, 0x88676FB0, 0x88677870, 0x88677C38, 0x88678170 (enter-state helpers writing the 4-word state block then calling vtable slot 15): body matches except that the target stores state_10 before loading rel; 88676FB0 also returns the same register as the stored flag (li r3,1; stb r3).
0x88670D10, 0x88672828 (reset default record): constant materialisation order (lis 0x9682 before lis g_ts4_script_constants) differs.
0x886731B0 family is matched; 0x88673210 too.
Not attempted: everything of 0x100+ bytes except as listed, all vector/float-select/mfcr/divw functions, and the ptr-clrrwi ones (0x886696A8, 0x8866FC18, 0x88669B98).
Note: 0x886688A8 and 0x8866F028 were already matched elsewhere (d1g_analyser.c / fk6_000.c); they are not in my specs.
