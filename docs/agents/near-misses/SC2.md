# SC2: applying the store-scheduling rule to near misses (2026-11-15)

Compiler cl.exe 16.00.10224.00 under wibo, split `work/matching-b77`, Python 3.13.18.
- Plain route: `tools/fn_check.py SRC name=0xADDR --flags /Oc`.
- LTCG route: `tools/fn_check_ltcg.py ... --context src/xbox360/pp1_pool_primer.c --flags /Oc`.
- Scratch is in `work/army/SC2/` (git-ignored): `chk.sh`/`chkl.sh` (the two routes, `$CTX` holds extra LTCG contexts) and
  `cmp.py SRC name=0xADDR [N] [skip] [--ltcg]` (diff count plus a two-column listing).
- Generators: `g158.py` (groupings of +0x158..+0x160 in 0x886D7878), `m_gen.py` (groupings of 0x88658E40).
- About 115 compiles in all.

## Matched (all exit 0)

| Address | Source | Spec | Fix |
|---|---|---|---|
| 0x88677C38 | `src/xbox360/sc2_a.c` | `work/specs/SC2/sc2_a.json` | `{ u32 *p = &h->f10; *p = K; }` keeps the store ahead of the `h->rel` load |
| 0x88658E40 | same | same | +0x44/+0x48 as a 2-word sub-object, +0x24 stored through a local member pointer |
| 0x88690AA0 | `src/xbox360/sc2_ltcg_a.c` | `work/specs/SC2/sc2_ltcg_a.ltcg.json` | DA1's draft with `own_free(&self->pa8)`, on the LTCG route |

- `sc2_a.c` (sha256 `4d0639a7…`): 0x88677C38 also matches on LTCG. 0x88658E40 is plain only (LTCG gives 5 diffs, see R2 below).
- `sc2_ltcg_a.c` (sha256 `28944281…`) is LTCG only.
- Both files pass `cc -std=c11 -Wall -Wextra -Werror -fsyntax-only -Isrc/xbox360`.

## Extensions of the rule

**R1. A block-local pointer to one member pins that one store.**
- `{ T *p = &o->m; *p = v; }` keeps the store in source order relative to accesses through `o`. The store is still
  re-based onto `o` in the output (`stw v,K(rO)`), and no `addi` is emitted.
- A single store needs no helper and no second use. This differs from SC1's "a helper pointer used once is folded and
  counts as `o`".
- Where it helped:
  - 0x88677C38 (3 diffs to MATCH): the store stays ahead of a load through the same base.
  - 0x88658E40 (+0x24 store, 3 diffs to MATCH): the store stays behind the flag-byte stores.
  - 0x886AD1F0 (`{ int *c = &o->f18; *c = 0; }`, 9 diffs to 2): the store stays ahead of the float loads.
- Where it did NOT help: a vtable store in 0x88690AA0 (`{ const char **vp = &self->vtbl; *vp = VT; }`). The `pa8` load
  still went above it.
- So the pin holds for a data store in the middle of a run. It does not hold for every case. Use it as one more option
  in the sweep, next to the sub-object helper.

**R2. LTCG: a global whose address is never taken does not alias any pointer access.**
- Plain route: a global store or load keeps its source order relative to accesses through pointers (SC1 A1).
- LTCG route: if the TU never takes the global's address, the store or load is scheduled freely:
  - 0x88690AA0: `lbl_88D45B00 = 0` now sinks below the `pa8` load, which matches. DA1 had 5 diffs on the plain route.
  - 0x88658E40: the `lbl_88D45B08 = self` store moves, so this function matches on the plain route only.
  - 0x886D7878, non-volatile read: the load sinks to its use. This is SC1's "an early global read is sunk".
- Taking the address once, anywhere in the TU, makes the global alias pointer accesses again. Either of these does it:
  - in the function: `void **head = &lbl_88D45AF4; cur = *head; ... *head = s;`
  - in an unused static function returning `&lbl`.
- In 0x886D7878 that keeps the load early, in its source position. The volatile form left 6 diffs. This form leaves 5,
  and the load register now matches (r9).
- SC1's volatile read was one way to take the address. The address-taking local is the cleaner form.
- Rule of thumb for an LTCG target: if a global access keeps its place among the stores, the original TU took that
  global's address. If it floats, the TU did not.

**R3. Store groupings found by sweep.** 0x88658E40 (`m_gen.py`). Flags as a helper were tried with groupings of
w44..w50; with flags written directly, four groupings were tried:

| flags | w44..w50 | diffs |
|---|---|---|
| helper | {3,1} | 8 |
| direct | {3,1} | 11 |
| direct | {1,2,1} | 11 |
| direct | {4} | 12 |
| direct | {2,1,1} | 3 |
| direct | {2,1,1}, with +0x24 through a local pointer (R1) | MATCH |

- Flags must be written through `o`: the vtable store has to pass the first flag byte.
- The global store sits between w4c and w50 in the source.

**R4. A conditional constructor called from the allocation site** (0x886BC480): `s->p88 = n ? obj_ctor(n) : 0;`.
- `obj_ctor` stores the vtable, then words +0x08..+0x14 as two 2-word sub-objects, then +0x18 directly.
- That fixes `mr r10,r3` before `stw vt`, with the zero stores after it (7 diffs to 4).

## Results on the list

| Address | Before | After | Best file | What is left |
|---|---|---|---|---|
| 0x886BC480 | 7 | 4 | `work/army/SC2/b1.c` | `lwz r3,0x5b38` (heap global) in the target comes right after `li r7`, ahead of `li r6/r5/r4`. In ours it comes last. Only 6 of about 1300 calls in the image use the early form. Tried: heap in a local, two inline allocator wrappers, volatile read, LTCG. None moved it |
| 0x88677C38 | 3 | MATCH | sc2_a.c | |
| 0x886C5DB0 | 3 | 2 | `l5.c` | Needs `li r10,0` before `stw last` AND `stw last` before `stw f4`. With the f4 store before the `last` store in the source (`l = copy(); r->f4 = 0; v->last = l;`), the `li` comes first but the two stores swap. Tried: zero local, member pointer for f4, local vector pointer, temp for the copy result |
| 0x88695568 | 4 | 4 | `work/army/DA1/subs3.c` | r8/r9 swap of the outer vtable `addi` and the sub-object `lis`. The vtable store must be first (any later position gives 16-51). Tried: {q0,q1} as a struct (42), 6-word struct (13), scalar q stores (7), {vt,w4} head struct, vtable stored twice, extern order, function alone in the file, single-use local for `&p->a`. None changed it |
| 0x88690AA0 | 5 | MATCH (LTCG) | sc2_ltcg_a.c | |
| 0x886D7878 | 6 | 5 (LTCG) | `d4.c` with `CTX="flags(/Ob1):src/xbox360/sm4_ctor_a.c"` | `lis` of the global is not first, and `cmplwi` comes straight after the load (the target has 2 stores in between). Tried: groupings of +0x158 (7), `p130` pair helper, read position. All 5 |
| 0x886B14E0 | 8 | 8 | `work/army/DA1/d14e0c.c` | `addi r30,r27,0x294c` (end of array = `&o294c`) is hoisted above the call. It stays hoisted with: direct `o294c` free (10), `&arr[10]`, inline array-dtor helper, wrapped array sub-object, do/while, LTCG. Indexed loop: 27 |
| 0x886CDED0 | 9 | 9 | `work/army/W9C/h1.c` | Stack loads of `r2` pass the store `s->f5fc` in ours. In the target they stay behind it. Tried: out-pointer helper, local member pointer, `r[2]` array, struct of two (18), `off` local, LTCG |
| 0x886AD1F0 | 9 | 2 | `work/army/SC2/t1b.c` | R1 on f18, f14 store after the global read. Left: `stw 0x14` before `fcmpu` in the target, after it in ours. Same on LTCG, also with `!(v >= z)` |
| 0x88640810 | 7 | 7 | `work/army/W8C/nm_88640810.c` | `lis` of the global ahead of `li 0` (register numbers r11/r10 swapped). Tried: declaration order, a `{p}` struct id with init helper before or after the read, a static const null, an alias local for self, LTCG |
| 0x88658E40 | 12 | MATCH | sc2_a.c | |
| 0x8866FB60 | 12 | 12 | `work/army/W8B/b17.c` | Prologue load order. Declaration order 12, late `q0` 16 |
| 0x886E7EF0 | 17 | not attempted | | vector constructor |
| others (0x886E34F8, 0x886AD158, 0x8869D000, 0x8865CBD8, 0x8864A4E8, 0x886AD030, 0x886952B8, 0x8864C170, 0x886D48F8) | | not attempted | | out of budget |

## Refuted or not reproduced

- "One use of a member pointer folds and counts as `o`" does not cover a block-local pointer variable (R1).
- An `extern` global is not always ordered against pointer accesses: that is true on the plain route only (R2).
- Changing the type of an address-taken stack local (struct, array, struct of two refs) does not change how it is
  ordered against stores through a parameter (0x886CDED0, 0x88640810).
