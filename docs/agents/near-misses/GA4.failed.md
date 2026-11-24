0x88698538 reset (stores 0/float 0 to p20 fields): all instructions match except the register for the second `lwz 0x20(r31)` pair (target r10, ours r7/r6); tried local zero float, helper inlines, repeated self->p20 accesses.
0x886A0408 / 0x886A04C8 element ctors (vtbl 0x880D7600 + 16 zero words, stride 0x44): target has dead `addi r10,r3,8; addi r10,r10,0x14` pair and a bdnz loop with two induction pointers (stwu); ours unrolls or differs in lis/li order. Tried sub-struct inline init, loops.
0x886AD1F0 (probe step loop): only instruction scheduling differs (target stores steps=0 before the lfs loads; ours hoists lfs above the stw). Tried reorder/permute.
0x886AD158 (slot ctor, 20 records stride 0x30, bdnz loop): everything right except the single `lfs` of lbl_8814B440 is placed mid-sequence in the target; local float hoists it to the top, global access reloads 3 times.
0x886B14E0 (container dtor, 10 slots): target keeps two induction pointers (stwu -0x41c and +0x38 shadow), 6 saved regs; ours folds to one pointer.
0x886B0380: all matches except cfg pointer lives in r10 in the target, r11 in ours (join variable register).
0x886AB1A8: 3 instructions differ, only the register numbers of the g_ts4_script_constants pointer (target r10/r9, ours r11/r10); u8 settled + u32 i version is otherwise exact.
0x886AB250: target hoists f31=0.0f, f29=limit, f30=k with allocation order zero,k,limit; ours gets k,zero (f31/f30 swapped).
0x886AB0E8: exact except target emits lwz/addi/stw of p->steps before the lbz of p->enabled; ours hoists the lbz above the stw.
0x8869EF08: target hoists `mr r4,sel` and `lwz r3,0x4c` before the tag compare; ours does it inside each branch.
0x886A5C88: exact except 3 register names (r8/r9 swap on idx*8 and rel-array offset); permute.py did not find it.
0x886A1628, 0x886A5C00, 0x886A80F0, 0x886986C8, 0x886A37D0: LTCG register conventions (callee preserves r6/f10/r4/r9, or clrrwi-pointer idiom); not reproducible.
0x886A02B0: record init loop with overlapping fields (+0x20,+0x24,+0x30,+0x3c,+0x3d per 0x30 stride) not understood.
0x886AFC78..others not listed: not attempted (time).
0x886A48B8: float ?: lowered to fsel table (mfcr), known blocker.
0x886AC928: relative-array begin/end min-search; ours folds the `addi r11,r11,0x5b0` base and allocates this/best registers swapped.
--- second pass (functions up to 0x300 bytes) ---
0x886A76F8: shape right (cursor index via divw by constant 0x60 in a register, stored changed byte); blocker: call passes flag in r6 with r5 never set (fn_8890FD00 skips an argument register); also float load schedule.
0x886AD030: allocator/new idiom; target keeps `lis` of lbl_88D45B38 in callee-saved r29 and zero in r31; ours folds the address into a full pointer and swaps r30/r31.
0x886A0EC8: two linear searches over self-relative arrays (stride 0x10 key at +0xC compared with A->0x7C->8, then stride 0x5C key at +0x3C compared with ->4, each with first-element fallback); target uses extra r31 for the element key and separate found/cursor registers; ours differs in register use (inline helpers make it worse).
0x8869AF98, 0x886A3AC8, 0x886A0408, 0x886A04C8, 0x8869D000: element ctors (0x44-byte element: vtbl 0x880D7600 + 12-word block at +0x14 + 4 words). A loop over 3 x 4-word sub-structs reproduces the first element's dead `addi` pair and store order exactly, but the scheduler interleaves the three elements; target emits each element sequentially.
0x886A0188: 20-record ring (stride 0x30, flags at +0x2C/+0x2D of each record, head +0x10, count +0x14 signed). Logic reproduced; target loads `this` into r10 and sets r3=0 before the count test (beqlr), ours branches to a shared exit.
0x886A13B0: blend/lerp with fn_881899D8 and fn_886962C0 (float bits passed as u32 args, result via sret float*); structure right, ordering of the px load and a float/register naming differ.
0x886A3868: shape and offsets right (0x154->0x74 cfg, window test with signed int->float); only register choice of the constants pointer (target r29/r30/r28 = g/p1/p2) and the `li 1` placement differ.
0x886ACB08: scalar-deleting-style dtor (5 virtual deletes, 2 owned destroys); 3 instructions differ: target stores lbl_88D45AFC=0 between `cmplwi` and the branch of the own10 test.
0x886AFC90: reset of state bytes through repeated self->4->0x30/0x44 reloads; matches except `p->0x58 = p->0x310` where the target keeps a dead `mr r10,r4` copy of the pointer.
0x886AC130: big ctor (about 100 stores plus heap alloc of 0x790 bytes); constants (lbl_8814B440, g[14]) are loaded once mid-sequence in the target; not matched.
0x886AC9D8, 0x886A06B0: many stack temporaries / function-pointer constant tables (fn_88269E10..); not attempted in depth.
0x8869BDF8, 0x8869BEF0, 0x8869C638, 0x886A14E0, 0x886A3C98, 0x886AA748, 0x886A40A8, 0x8869CDF0, 0x886A0850, 0x886A32B8, 0x886A4978, 0x8869C868, 0x8869BC48, 0x886A2BE8, 0x8869DC38: vector (vspltw/vrlimi/vsel/vupkd3d/lvlx), fsel-table or LTCG-clobber patterns on first read.
0x886AC7E0: same min-search over self-relative array as 0x886AC928, not retried.
