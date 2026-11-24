# GA1 failed / skipped functions (first divergence and what was tried)

Near misses (1-5 instructions off):
- 0x8864E420: walk vector of vobj*, call slot 0x10(obj,key)==1. Only diff: `lwzx r3,r31,r11` (index,base) vs ours (base,index). Tried begin[i], pointer+byte offset, helper static, int/u32 counters, separate off counter.
- 0x88655310: ring-buffer write (memcpy x1/x2). Only diff: `add r3,r11,r10` (pos,buf) vs ours (buf,pos). Tried pos+buf, buf+pos, casts, locals, permute 150s.
- 0x8865B658: lfsx f13,r11,r6 (elem,rel) vs ours (rel,elem); everything else matches (rel-array item 0x134 stride, threshold compare).
- 0x886567A8: saturating u32 increment in script data (inc, 0xFFFFFFFF-v<1). Only register naming differs (value r9/address r10 vs ours swapped). Tried ~12 forms and permute 240s.
- 0x88658120: state-change event {12,key,vcall 0x4c}; only register numbering differs (r9/r10, r7/r8). Permute 240s no match.
- 0x88656538: float getter from data block (+0x3c array); only `lwz r10,off; slwi r9; add r10,r9,r10` register order differs (we allocate off in r9).
- 0x88655F98 / 0x88656118 / 0x886561E0 (also 0x88655EC8, 0x88656048, 0x886562A0): per-channel (0x1c stride, <4) accessors. Logic and control flow match; the channel pointer is computed as `(chans+0x48) + (chan*0x1c + off)` in the original, we get `(chans + chan*0x1c) + off` (mulli/add order). Tried parenthesised sums, locals, static helper.
- 0x8865C018: many zero stores into a state block with a self-relative sub-struct at +0xc; original keeps base=&s->off in r9 and `add r8,r9,r8` (base,off) while we emit (off,base).
- 0x8865ADD0: copy 2 floats +0x9d0 -> +0x9d8, then clear flag; the original keeps a dead `addi r10,r11,0x9d0` and loads the flag byte first.
- 0x8865AEB8: four derived pointers stored; original reloads this->0x1c->8 between the stores and stores 0x20 after 0x2c/0x28; we CSE the reload and reorder.
- 0x886468B8: init of floats from lbl_8814B440 / lbl_880C8FB0; original interleaves `stw 0x20; lfs; stfs...` and loads the 10.0f late; tried locals in several orders and permute 60s.
- 0x8864E640, 0x8864EF60: Vec3 += (fadds operand order f1,f0 and interleaved load/add/store); tried struct and pointer helper forms.
- 0x8865AC90: float helper with abs/sub branches; original loads b[0] before the zero constant (f13/f12) and writes the first subtraction into the loaded register; tried locals, permute 70s.
- 0x88644738: curve eval x/(knee) with a dead `addi r3,r3,4` and relocation layout (g_ts4_script_constants+0 reloc is exact in ours; only the dead addi and blt target differ).
- 0x886579B8: lock; find entry by id in vector<Data*>; fn_88655BC8(d->data); unlock. Layout of the two unlock paths differs (call path is placed last in the original). Tried 4 control-flow shapes.
- 0x8864BAE8 / 0x8864BBB0: critical-section push wrappers; only the order of `lwz r30` / `mr r31` / `stw r4,0x8c(r1)` differs (arg spill must come after the mr). Tried &param, copies, struct arg.
- 0x8864B030: wait with 200 ms; `return r==0x102 ? 1 : (r != 0 ? -1 : 0)`; original has `addi r11,r3,0; subfic r11,r11,0; subfe r3,r10,r10`, ours `subic r10,r3,-1`-style; 3 instructions.

clrrwi (`rlwinm rX,rY,0,0,31` no-op) cases, known blocker: 0x8865AB58, 0x8865A3E8, 0x8865B278, 0x8865BF80, 0x8865F0D0, 0x8865EE40, 0x8865E7C0, 0x8865EF18, 0x8865EF98. Tried (u64) casts, char* from int, long, u64->ptr.
0x8865B2D8: `lwz; addi r11,r11,0; cntlzw` (ptr+0); not reproduced by ==0 forms.

Divide without trap: 0x8865E940, 0x8865E980 (ring buffer idx % cap, `divw` with no twllei/twi).

LTCG register passing: 0x8865E388 (f1 stays live across calls to 0x8865E330).

Not attempted / skipped on purpose: vector (VMX128) functions (0x8864E850, 0x8864F0B0, 0x8864F618, 0x8865A6B8, 0x8864E6B8, 0x8864E7F8, 0x8864EF98, 0x8864E790, 0x8864E708, 0x8865EE90, ...), other agents' or D1's: 0x8865A938, 0x8865ED78 (d1g_shotsel.c), 0x88649678 (ga6_l.c), 0x8865FD40 (ga4_a.c), 0x8865A348 (ga3_a.c).
- 0x8864EBB0: vector<vobj*> destroy loop (slot 0xc then delete slot 0) + clear via fn_88562DC0; structure matches, but register allocation (loop counter in r29, byte offset r31, vec ptr r30) and lwzx (offset,base) order differ.
- 0x8864AF28, 0x88645290, 0x88645B98, 0x886455A0, 0x88644990, 0x8865E490, 0x8865B3B0 and the rest of the list beyond 0xB0 bytes: not attempted (time).
