# NM1: near-miss clean-up, list 1 (2026-11-15)

Compiler cl.exe 16.00.10224 via wibo, split `work/matching-b73`, plain route `tools/fn_check.py --flags /Oc`
(every match below also MATCHES on `tools/fn_check_ltcg.py --context src/xbox360/pp1_pool_primer.c --flags /Oc`).
Scratch scripts in `work/army/NM1/` (git-ignored): `c.sh` (plain check), `cl.sh` (LTCG check), `var.py`
(substitute-and-check), `pad.py` (N dead locals at `/*PAD*/`), `grid2.py` (two pad markers, 2-D grid),
`spec.py`. About 120 compiles in total.

## Matched (4)

| Address | Spec | Source form |
|---|---|---|
| 0x886E5670 | `work/specs/NM1/nm1_create_items.json` | site 1: block-scoped copy `hb = o->b4c`, `(char*)hb + i*0x530 + hb->rel`; site 2: six dead locals in its own block |
| 0x886558B0 | `work/specs/NM1/nm1_buffered_write.json` | `u32 *t = &s->total; *t = *t + n;` with four dead locals before `t` (t = symbol 7) |
| 0x886C5160 | `work/specs/NM1/nm1_set_owner_ptrs.json` | vector as sub-object local `v = &s->v` (begin/end at +0x50) with six dead locals before it (v = symbol 7) |
| 0x8864E420 | `work/specs/NM1/nm1_any_handles.json` | same, `v = &l->v` with five dead locals (params l, arg; v = symbol 7) |

## Rules (class 1, operand order)

- **OP1 rule extended.** OP1 said a (param, load) pair and a strength-reduced induction temp never flip. They do flip
  once the LOADED operand is read through a computed-address local:
  - (param, field load): make the field's address a local (`u32 *t = &s->total; *t = *t + n;`). The order then
    flips when `t` is symbol 7 (0x886558B0: pads 4 and 12 match, nothing else does).
  - (induction temp, vector begin): put begin/end in a sub-struct and read them through `v = &s->vec`.
    Flips at v = 7 (0x886C5160: pads 6 and 7; 0x8864E420: pads 5 and 6). Writing `s->begin[i]`, int vs unsigned,
    and `char **` vs typed elements changed nothing; only the local did.
- **Self-relative site after a strength-reduced index (0x886E5670 site 1).** `(char*)o->b4c + (i*K + o->b4c->rel)`
  gave add(rel, ind) under every pad count 0..16. A block-scoped copy of the loaded base,
  `{ W9Hdr *hb = o->b4c; ... (char*)hb + i*K + hb->rel ...}`, gives add(ind, rel) with no pads, even though `hb` is a
  plain load copy (OP1 said such copies are propagated away and do not count). The block-scoped copy still changes
  the order. With two sites, fix them left to right: site 2 then needed six dead locals in its own block
  (grid top x block: matches at (0,6), (1,5), (8,6)).
- **Refuted for 0x886E3938** (`add r9,r10,r31`: rel off the PARAMETER `list` + IV i*4 shared with `self->slots[i]`):
  pads 0..16 at the top, 0..16 inside the loop, 0..16 in a block around `item`; `int *lh = &list->rel` or
  `struct Hdr *lh = &list->h` (offset 0, so a copy of the parameter) with pads 0..9; index-first, parenthesised,
  `&((int*)(list+rel))[i]` forms; `slot` loaded first; while, do-while, `count > i`, unsigned i; inline helper
  taking the list or `&list->rel`. An explicit user byte counter `off` (used for both item and slots) DOES give the
  item add (rel, off). But then the slots `lwzx` flips to (base, off) and `li off,0` moves above the count test
  (6 off). Using `off` for item only and `[i]` for slots creates a second IV (25 off). So a user-local index is
  always placed second. The compiler IV is placed first against the rel load off a parameter. No source form put
  it second.
- **Refuted for 0x88656538** (`add r10,r9,r10` idx*4 + rel off h = &x->h, then lfsx with h): pads 0..9 at the top,
  0..9 around an element local, a named `off = idx*4` local with pads 0..9, four expression forms. h = symbol 7
  (2 pads) does change the association: it gives `add (ind, h)` then `lfsx (sum, rel)` (4 off). So the three-term sum
  is reassociated by a key that depends on h's number, but no count gives the target's (ind, rel) then h.

## Class 2 (adjacent swaps): not solved, findings

- 0x8866DF18 (`lwz r11,0x48(r4)` must precede `lis/ori` of the hash stored to `*out`): hash as a one-member struct by
  value, the hash in a local, b loaded via `struct B *b; b = a->b;`, inline store helper, int vs unsigned out, result
  local stored once (16 off), if/else stores (17 off), pads 0..9, LTCG route: all unchanged. Loading `m = b->m78`
  before the store moves the lwz b first, but then the m78 load is also hoisted above the store (2 off).
- 0x88657F68 (`li r7,2` before `lwz r3,lbl_88D45B38` before `stw f4`): with no `heap` local, the store moves
  before the arguments (6 off). A comma expression or an inline `alloc5` wrapper changed nothing. An inline
  `new_r10` helper gave 19 off.
- 0x886C5DB0 (`li r10,0` above `stw r11,4(r8)`): writing `r->f4 = 0` BEFORE `v->last = e` in the source gives the
  target's li/register choice but swaps the two stores (2 off). `int zero` local, `int *fp = &r->f4` with pads
  0..9, and an e-local all leave it at 3. Note that the callee is now `ts4_clear_three_vectors_886C3978` in
  symbols.txt (the W7C draft still uses fn_).

## Class 3 (FPR numbering): 0x88672750 not solved

Target `lfs f10; fabs f9,f10; lfs f11,q->f8`; ours f11/f10/f9. Pads 0..9 at the top and 0..9 between `d` and `t`,
fabs on d directly (31 off), a `lim` local loaded before or after the fabs, declaration order of d/t, a separate `u`
for the fabs result: all unchanged. `q->f8 > t` gives the limit f9 and the compare f9,f10 (5 off). Note that the
callee is `fn_8817B608` in symbols.txt (the W8B draft uses an unregistered ts4_ name).

## Not attempted (budget)

0x886875D8, 0x88677C38, 0x886BC480, 0x8864E640, 0x8865FA18, 0x88644CE8, 0x8866F9F0, 0x88662578, 0x886C4C60,
0x886CF760, 0x88690AA0, 0x88645290.
