# GA5 failures (only functions that were actually attempted; everything not listed here or in work/specs/GA5/ga5_a.json was not attempted)
Tool: TS4_MATCHING_DIR=work/matching-b39, fn_check base flags. Pattern notes at the end.

0x886C3DA8 (0x18): `*status==1` callback. Target `li r3,1; cmpwi; beqlr; li r3,0; blr`. Every plain form (if/else, ?:, local result) gives cntlzw/extrwi or 0x14 bytes; none gives the beqlr shape.
0x886C3D50 (0x58): loop over ptr vector testing (**p==0||==1||==2) returns 0 else 1. Target reloads **p three times and computes end (+8) before begin (+4); mine CSEs the loads (size 0x4c vs 0x58).
0x886C4878 (0x50): `first->t0<=t && t<=last[-1]->t1` returns bool. Target re-reads this->4/this->8 (no CSE) and builds the bool through li 1/li 0/clrlwi; mine CSEs (0x3c-0x44).
0x886C4540 (0x48): 1/x table (p[0]=c[0]/p[5] ...). Target interleaves lfs/fdivs/stfs and keeps f0=c[0] loaded once; mine hoists loads (scheduling only).
0x886C3A48 (0x54): bilinear weights. Target load order is [0x30],[0x34],[0x28],[0x2c] and stfs [0x44] before the constant load; every expression order tried schedules differently.
0x886C44C0 (0x7c): normalize weights (stride 0x98, +0x88 -> +0x8c). Matches except one branch target: target's first loop `beq` jumps to the `fmr f0,f13` block (empty range skips the sum==0 test); mine skips to the next test.
0x886C5C80 (0x24): `i=*cnt; *cnt=i+1; keys[i]=b; vals[i]=a` with typed struct and local `int *k=self->k` is 1 instruction off: stwx operand order (rA/rB swapped for the first store only).
0x886C5160 (0x3c): `for i<n: first[i]->link=link` with unsigned n; 1 instruction off, lwzx index/base registers swapped.
0x886C5098 (0x38): row pointer `(char*)&o->hdr + idx*0x30 + o->hdr` with idx=min(i,count-1); 2 instructions off in the final add order / addi folding.
0x886CE120 (0x50): loop over vector at lbl_88D45AF4+0x50/0x54 calling fn_886CB3A8(elem+0x30); 1 instruction off (lwzx r30,r11 operand order).
0x886C4058 (0x5c): table gather loop; 1 instruction off: `add r5,r3,r9` vs mine `add r5,r9,r3` (commutative operand order) for table = base + *base.
0x886C7CA0 (0x38): 8 stores of -1 + 1 byte store; target loads `lwz r11,8(r3)` then `li r10,-1`; mine allocates o to a different register (pure regalloc, 12 insns).
0x886CBBA0 (0x38): ctor storing vtbl lbl_880D75FC, zeros, c[87]; same stores, different scheduling of li/addi/stw (6 insns).
0x886B8078 (0x40): `fn_886B6448(fn_886A0EC8(o)+0x18, self+0x24, o->8, o->0x28)`; target keeps o in r11 and does `mr r3,r11` (0x40 bytes), mine reuses r3 (0x3c).
0x886B7A60 (0x90): two lookups with hashes 0xBDD29CAD / 0x54457AD3 then fn_88911668. Target loads dom=c->0x44 early (r29) and again for the find call; compiler here always CSEs the two loads (hash is an address-taken local).
0x886C7150 (0x74): rel-array find with 16-byte stride and key compare. Same shape as the matched 0x886C6098 but target keeps the Rel pointer in r11 (`addi r11,r11,0x64; lwz r10,0(r11)`), mine folds +0x64 into the loads.
0x886C7F10 (0xbc): rel-array (stride 0x28) membership test, fn_88265938(...) returns the array. Everything matches except the second compare: target loads *k2 first and then p->b, compares (p->b,*k2); `p->b==*k2` loads p->b first, `*k2==p->b` swaps the cmplw operands (3 insns).
0x886CC408 (0xac): flag test (a!=0&&b==0), then first element with handle==0 in rel array at data+0x49c gets handle=0x7445A27F, v(f1), k(r4). 4 insns off: target stores handle (ori) first, then stfs +0x60, then stw +0x5c; mine always schedules the two plain stores before the ori. Tried all 6 statement orders and ptr/unsigned types.
0x886C4C60 / 0x886C4CB8 (0x54): virtual-base adjust thunks calling fn_886DBF40 twice (this+vboff, then +0xc / +8). Target does `add r4,r11,r4` in place and `addi r31,r4,8`, then calls with r4 = adjusted, r31 = adjusted+8; mine keeps the adjusted pointer in r31 and rematerializes +8 later (5 insns). Reassigning the parameter did not help.
0x886C45E8 etc. were matched; see spec. Not matched because of known blockers: 0x886C5C28 and 0x886C6660 and 0x886C84B8 (LTCG: caller-saved r4/r7 survive a call to fn_886C3658/fn_886C4AF0/fn_886C8438), 0x886C4F20 (clrrwi rX,rX,0), 0x886C7CD8 (clrrwi), 0x886C84F0 (divw by 0x8c in a register), all fsel/mfcr users (0x886C48C8, 0x886C6EE8, 0x886CAE50, 0x886CBBD8, 0x886C5770), and every vector function (vcmpgefp/lvx128 ...: 0x886C35E0, 0x886C3610, 0x886C35F0, 0x886C3620, 0x886C3C30, 0x886C3E08, 0x886C5070, 0x886C6F88).

## Codegen notes worth passing on
- Relative-array begin/end (offset field -1 means "none"): write `begin = 0; if (r->off != -1) begin = ...; end = 0; if (r->off != -1) end = ...;` with `end = 0` AFTER the first if. Declaring both = 0 up front makes MSVC merge the two ifs (wrong shape). Matched 0x886C6098, 0x886C5CB0, 0x886C8438, 0x886C50D0, 0x886C6E18 this way. Some call-free functions (0x886C7150, 0x886C7F10) show the reload variant that I could not reproduce.
- Reverse walk `for (p=last; p!=begin;) { r=*(p-1); ... p--; }` as `while (p != begin) { Rec *r = *(p-1); ...; p--; }` gives subi+lwz at loop top and `beqlr`; the do/while with `*--p` gives lwzu (0x886C45E8).
- A result local `T *r = 0; ... { r = *p; break; } return r;` reproduces `mr r10,r3; li r3,0` prologues (0x886C47F8, 0x886C4360, 0x886C3FE0 style).
- Comparison operand order follows source order: `id == (*p)->id` gives `cmplw r4,r7`; `(*p)->id == id` gives `cmplw r7,r4`.
- MSVC: the same `if (r->off != -1)` evaluated twice is merged when the intermediate store/def can be hoisted; keep a statement between them.

## Round 2 (ga5_b)
0x886C8C48 / 0x886C90F0 (0x20): `bl` to fn_886C8878 / fn_886C8C68 inside a 0xa0-byte frame (non-tail call, no locals visible); plain wrapper gives a tail call or no frame; could not find the source construct.
0x886C5130 (0x30): `lbl_88D45AF4` null test then `arg` null test then tail call fn_88607FB0(g+0x12c, arg); target keeps two separate return-0 paths (beqlr and `li r3,0`); every ordering gives 0x2c bytes, 10 insns off.
0x886C71C8 (0x68): calls the matched 0x886C6048 and keeps this/arg in r5/r6 across the call (LTCG register survival), not reproducible.
0x886C5D20 (0x8c): loop calls fn_886C5CB0 and keeps the element pointer in r6 and a constant 1 in r5 across the call (LTCG survival).
0x886B4B80 (0x8c, documented, PlayerController slot 21): table search then call fn_886B4700(self, found->0x10) as a real call with a 0x60 frame; any source gives a tail call (`b`) instead. Loop and `self->0x7c` store matched in structure.
0x886B63B8 (0x90, documented): loop calling fn_8816D1A8/ts4_resolve_path_text_8862F920/ts4_format_text(buf,0x80,fmt,name,(double)v)/ts4_destroy_owned_object; matches apart from frame size: target frame 0x140 with name at 0x80 and buf at 0x90, mine 0xf0 with 0x50/0x60. An unused 0x30-byte local at 0x50 is missing and cannot be kept (dead arrays are dropped).
0x886B7A60 (0x90): see round 1 (c->0x44 is reloaded for the find call in the target, CSE'd in mine); retried with local copies of c, same result.
0x886C85C0 matched; 0x886CBC30 and 0x886CC058 (0x7c, 0xc4): field-init constructors; stores are in the right order but MSVC schedules the constant loads (f13=1.0 first, then f0=0.0) and the first two `stw` differently; tried zero/one declaration order.
0x886CDA68 (0xdc): relative-array search (stride 0x28, hash 0x959A9407) then range test and `v <= 0`; structure right, but `begin` lands in r7 instead of r8 (li order) and the rest of the allocation follows; tried declaration orders and a result variable.
0x886C5230 (0xc0): target duplicates the common tail (two copies of the two-level lookup) in each branch of the tag test; mine shares it (0x88 bytes).
0x886C3B20 (0xc4): compiler-unrolled loop (5x unrolled parent walk, 100 iterations): known blocker.
0x886C6590 (0xcc): inline struct copy of 0x98-byte records with partial field copies; not attempted beyond reading.
0x886C40B8 (0xc4): function-local static table (guard bit in lbl_88D4AAF8) searched linearly; not attempted beyond reading.
0x886C8750 (0x64): `fn_8826C388(self->0xc+8)` index helper; target saves r29..r31 (result kept in r29, `mr r3,r29`) and does (hit-base)-*base >> 4; mine uses a smaller frame; tried result-local forms.
0x886B80B8 (0x124): 64-bit signed compare (subfc/eqv/addze) and a 5-way switch via bdzf chain; not attempted.
Not attempted (read, judged blocker or too long for the time left): 0x886C3938, 0x886C4278, 0x886C3748, 0x886C3CB8, 0x886C5DB0 (STL vector copy/destroy pairs with memmove helper), 0x886C66C0 (fn_886C48C8 fsel inside), 0x886C46C8, 0x886C4760 (float to int binary search), 0x886C58C0 (half-float unpack), 0x886CA530, 0x886C8358, 0x886CD1E8, and every function above 0x100 bytes except those matched.
