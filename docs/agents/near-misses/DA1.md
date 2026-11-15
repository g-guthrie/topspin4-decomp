# DA1: the dead sub-object `addi` (2026-11-15)

Compiler: cl.exe 16.00.10224.00 under wibo, split `work/matching-b69`, Python 3.13.18. Plain route
`tools/fn_check.py SRC name=0xADDR --flags /Oc`; LTCG route `tools/fn_check_ltcg.py ... --context
src/xbox360/pp1_pool_primer.c --flags /Oc`. Scratch files are in `work/army/DA1/` (git-ignored): `run.sh FILE
NAME ADDR [n]` (plain), `runl.sh` (LTCG), probes `a1.cpp`-`a10.c`, candidates `d*.c`, `subs*.c`, `b*.c`, `c84f0_*.c`.
`work/army/OP1/op1dis.py FILE /Oc` disassembles the probes. About 95 compiles in total, about 75 of them on A.

## A. Rule: the dead `addi` is the address of a sub-object handed to a nested inline helper

The target's `addi rX,rObj,K` that is never used (or is kept as a separate base, `addi r10,r3,0x44; addi r10,r10,0x14`)
is the address of a member sub-object that the source passed to an inline helper (a C++ member constructor or
destructor, written in C as `static __inline void sub_init(struct Sub *s)` called as `sub_init(&o->sub)`). The
compiler computes the address into a register. Later the memory accesses through it are re-based onto the parent
pointer with the offsets added together (`stw 0x5c(r3)`), and the `addi` is left behind, dead. A value use (a
derived address passed on as an argument) keeps using the register (`addi r3,r11,4`).

The address goes into a register only when the helper's pointer is used for **two or more** things and at least
one of them is not a plain load or store:
1. it derives another address: `&s->m` passed to a deeper inline helper, or `s->m4` (an array member) passed as an
   argument. One level of nesting below the dead `addi` is enough. In `o -> sub -> m -> vec` (0x88695FB8) the target
   has `addi sub` and `addi m` (both dead) and folds every `vec` field;
2. the same field is loaded and then stored (`v->e = v->e + 1`), or loaded, passed to a call, and stored after it
   (`f(v->e); v->e = 0`);
3. the same field is loaded twice with a possibly aliasing store in between (`o[0] = t - v->b; o[1] = v->b;`).

When the parent pointer is dead and the sub-object pointer is used across calls, the sub-object address becomes the
saved base (`addi r31,r3,0x14`, 0x886D8020). The first access before the calls is still folded onto `r3`.

Each of these probes was one compile (`work/army/DA1/a2.c`-`a10.c`):

| Form (H has the sub-object at +K) | `addi`? |
|---|---|
| `f1(&h->a)`, `f1(s){ fin(s->m4); }` (one use) | no, `addi r3,r3,K+4` |
| `f4(&h->a)`, `f4(s){ fin(s->m4); s->w8 = 0; }` | **yes**, `addi r11,r3,K; addi r3,r11,4`, store re-based |
| `f(&h->a)`, `f(s){ s->w4 = 0; s->w8 = 0; }` (stores only), the same with loads only | no |
| local `struct V *v = &h->v; v->e = v->e + 1;` | **yes** (dead) |
| `h->v.e = h->v.e + 1;` / `int *p = &h->v.e; *p = *p + 1;` | no |
| `v = &h->v; g1(v->e); v->e = 0;` (load, call, store of one field) | **yes** (dead) |
| `v = &h->v; v->b = 0; g0(); v->e = 0;` (store, call, store) | no |
| `h1(&h->v)`, `h1(v){ o[0] = t - v->b; o[1] = v->b; }` | **yes** (dead) |
| `h2(&h->v)`, `h2(v){ *o = (t - v->b) / (1 - v->b); }` (the two loads are merged) | no |
| C++ member constructors in the initialiser list, placement new, `this`-adjusting inline member functions | folded, no `addi` |

### Two more effects of the same mechanism

- **Redundant stores survive** when the same `&o->m` expression is passed to two separate inline calls
  (`init(&o->range); reset(&o->range);`, 0x8864F5B0). The target stores 0x1c, 0x20 and 0x24 twice, with an
  `mr r8,r11` copy of the constant. A nested call (`init` calling `reset`) or a local pointer passed to both removes
  the second set of stores.
- **Store order and register choice of the plain members around the sub-object** also follow the real member
  structure. In 0x886D32A0 the vtable store is scheduled first only when `w04..w24` are written as three
  three-word sub-objects (`vec_init(&s->v04)` and so on), not as nine scalar stores.

### Recipe

Write constructors, destructors and resets as one `static __inline` helper per member type and call them on
`&parent->member`. Find the types from the target:
- each dead `addi rX,base,K` is one sub-object at K;
- a chained `addi rY,rX,K2` is a sub-object at K2 inside it;
- a run of three zeroed words is usually a `{begin,end,cap}` vector with its own init helper;
- destructors free members in reverse order, one helper per member.

The game's `lbl_880D7600` object (0x44 bytes) is `{vt; w04..w10; {vec,vec,vec} at +0x14; vec at +0x38}`. It is
shared by 0x8890ED08 (constructor), 0x8890F1E8 (destructor, called out of line by many callers) and every
constructor that embeds it.

## Results (all exit 0)

| Address | Source | Spec |
|---|---|---|
| 0x886D0E20, 0x886D32A0, 0x886D8020, 0x88695FB8, 0x88695400, 0x8864F5B0, 0x886A0408, 0x886D50F8, 0x8890ED08, 0x8890F1E8, 0x88695D78, 0x886A04C8 | `src/xbox360/da1_a.c` (sha256 `ce8be1b8…`) | `work/specs/DA1/da1_a.json` (plain, `/Oc`) |
| 0x8865ADD0 | `src/xbox360/da1_b.c` (sha256 `ab8659fd…`) | `work/specs/DA1/da1_b.json` (LTCG, primer last, `/Oc`) |

- All 12 functions in `da1_a.c` also MATCH on the LTCG route with the primer.
- 0x8865ADD0 matches instruction for instruction on the plain route too. That route fails only on the relocation
  name: the split names 0x8814B440 `lbl_8814B440`, and the candidate uses `g_ts4_event_value`. The LTCG route
  resolves it.
- Its other fix: `unsigned char armed = o->bcc0;` read before the copy, for the early `lbz`.
- 0x886A04C8 (array of four 0x44 objects) needs a pointer loop, `q = a->s; for (i = 4; i != 0; i--) { init(q);
  q++; }`. An indexed loop gives one induction pointer instead of the target's two.
- Both files pass `cc -std=c11 -Wall -Wextra -Werror -fsyntax-only -Isrc/xbox360`.

## Near misses for A

- **0x88690AA0** (from `work/army/W8B/b12.c`, `work/army/DA1/d0aa0.c`): 24 differing instructions became 5. The fix
  is to make the owned pointer of the +0x8c sub-object a one-field struct freed through its own helper
  (`own_free(&s->own)`).
  - Left: the target loads `pa8` after the vtable store but before `lbl_88D45B00 = 0`.
  - Plain route: the load stays after the global store.
  - LTCG route: the load moves above both stores.
  - Tried, no fix: a local read first, if/else stores, a base-class cast for the vtable store, own-structs for
    a8/o78.
- **0x886B14E0** (`work/army/DA1/d14e0c.c`): 25 differing instructions became 8.
  - Fix: own-structs for the base at +0x20 and for the element sub-object. The loop's `addi r31,…,0x38`
    induction pointer and the dead `addi r11,r27,0x20` now match.
  - Left: `addi r30,r27,0x294c` is computed before the first call instead of after it.
- **0x88695568** (`work/army/DA1/subs3.c`): 4 differing instructions.
  - The same object pair plus two vectors. Only the registers of the two vtable addresses are swapped (r9/r8).
  - Tried, no fix: a head struct with its own init, the vtable store moved, extern declaration order, an array of
    two.
- **0x88644738**: no form gave the dead `addi r3,r3,4` with the real reload of `s->b` in the then-branch. Tried 11
  forms: helper on `&p->s` with one/two loads, `getb()` accessors, `&s->b` passed to an inner helper, the whole body
  in a helper (gives a live base), and separate helper calls. The whole-body helper is the only one that materialises
  the address, but it uses it as the base.
- **0x8866D110** (vector store through `b+0x9a0`, dead `b+0x40c`): no change from helpers on `&b->s9a0`/`&b->s40c`,
  `&q->vec20` passed to a store helper, or `&a->f40` passed to a reader (5 forms). Open.
- **0x8865C2D8**: not a dead-`addi` case. The rel load is re-based and the element copy is not reordered. Four forms
  tried, none closer than the draft's 9.
- Not attempted: 0x88644A48, 0x88667C98, 0x88687528 (34-41 instructions off).

## B. Table select plus a zero from `g_ts4_event_value`: ruled out

- `__declspec(selectany) extern const float g_ts4_event_value = 0.0f;` and a plain `const float g_ts4_event_value
  = 0.0f;` definition in the TU: the compiler treats both as a literal zero, giving a bare `fsel` (`b1.c`, `b2.c`).
- `static const float g_ts4_event_value = 0.0f;` gives the table select, and the relocation carries the name
  `g_ts4_event_value` (`b3.c`). It is a separate local object, the same thing FP1's named zero already does.
- 0x886C4970 (`b4970*.c`): the bool form `int ge = v >= zero; if ((unsigned char)ge) return i;` reproduces the
  target's `li 1; bge; li 0; clrlwi; cmplwi; bnelr`. The select before it stays a branch in every form tried: static
  zero for both, extern zero for the compare, `(a - b >= zero) ? other : d`.
  - The branch form computes `r->hi - x` only on its own arm, so the operand that appears in one arm only is sunk
    into the branch. FP1's helpers use both operands in the compare.
  - Open: a form that keeps that operand unconditional.
- 0x886C6EE8 (PP1 v17) re-checked on b69: still 2 instructions (1.0f in f0 instead of f13). The static zero's
  relocation is accepted there (printed as `?`).

## C. r10/r11 swaps: no movement

0x886C84F0 (`c84f0_1.c`-`c84f0_5.c`): base through `g1_begin(&a->c->h50)`, declaration/assignment order of `h0` and
`base`, a split `c = a->c` local, and moving `*out = …` after `g1_end(h)` (26 instructions, worse) or reading `h->off`
into a local first (47, worse). The draft's 15 differences did not move. 0x88695568 above is also a pure register
swap that none of the forms moved.
