# RA1: register assignment (saved r31..r14 and volatile r11..r3) (2026-11-15)

Compiler cl.exe 16.00.10224.00 under wibo, split `work/matching-b77`, Python 3.13.18.
Plain route `tools/fn_check.py SRC name=0xADDR --flags /Oc`. LTCG route `tools/fn_check_ltcg.py ... --context
src/xbox360/pp1_pool_primer.c --flags /Oc`. About 125 compiles in all: roughly 50 on probe files (each probe file holds
6-24 probe functions), about 75 on real functions.

Scratch is in `work/army/RA1/` (git-ignored):
- `dis.sh FILE` compiles a probe with `/Oc` and disassembles it (wraps `work/army/OP1/op1dis.py`);
- `summ.py FILE` prints one line per function, with `[pN=rX]` for every `mr rSaved,rArg` and the body on one line
  (`BRIEF=1` prints the mapping only);
- `c.sh SRC name=0xADDR [l]` runs the plain or LTCG check;
- `var.py SRC name=0xADDR STEM 'old=>new' ...` applies text substitutions, checks the result and prints the diff count
  (`L=1` for LTCG);
- probes `p1.c`-`p23.c`, `pz.c` (saved registers) and `q1.c`-`q5.c` (volatile registers); candidates `f20*.c`,
  `k1a.c`, `b29*.c`, `e1*.c`, `e2*.c`, `i1*.c`, `f18*.c`, `b22*.c`, `g3a.c`, `a1*.c`, `t4a.c`.

## Matched (all exit 0)

| Address | Source | Spec | Fix |
|---|---|---|---|
| 0x886BC3A0 | `src/xbox360/ra1_a.c` | `work/specs/RA1/ra1_a.json` | address-taken copy `val = o` made right after the pop. The push helper takes `(v, o, &val)`, with the value for the fast path and `&val` for the slow-path call. Also the corrected `fn_8826B718(v, where, &val, 1, 1)` argument order |
| 0x886900E8 | same | same | no `one`/`zero` locals. Literal 0/1 stores that straddle the vcalls, plus `unsigned char c = q->b470 && q->b472;` |
| 0x88658C80 | same | same | `a = *slot` (read through `slot = &self->w1c`), and `self->w2c = 0` moved inside `if (pend)`. Callee is now `ts4_load_handle_88658B90` |
| 0x88657810 | `src/xbox360/ra1_b.c` | `work/specs/RA1/ra1_b.json` | the third vcall argument is a 4-byte struct by value. `if (lbl_88D45B08) { g = lbl_88D45B08; ... }` |
| 0x886AD030 | `src/xbox360/ra1_ltcg_a.c` | `work/specs/RA1/ra1_ltcg_a.ltcg.json` | `if (n) c = f(n); else c = 0;` and `if (n) {...} else b = 0;`. LTCG only: on the plain route it is 33 off, on scheduling |

- `ra1_a.c` (sha256 `bb1a02ba…`) and `ra1_b.c` (sha256 `a32a003d…`) also MATCH on the LTCG route with the primer.
- `ra1_ltcg_a.c` sha256 is `faa4940e…`.
- All three pass `cc -std=c11 -Wall -Wextra -Werror -fsyntax-only -Isrc/xbox360`.

## Sub-class 1: saved registers. Probe table and rules

Every probe has the shape "values live across `g3(0)`, then used". It records which value gets r31, r30, r29, ...

| Probe | Result |
|---|---|
| params a,b,c, each used after the call only as call args, xori, load/store base, compare, shift, sub, and/or/xor, mullw, divw, extsh, an index, or a store through a pointer; uses counted 1..4 per value; use order and last-use order permuted (p2 s4-s8, p4, p6, p12, p21) | always a=r31, b=r30, c=r29 (parameter order) |
| locals loaded before the call (p7 y1-y4), in any declaration order and any use order | order of FIRST ASSIGNMENT in statement order (`z = s->c` assigned first gets r31). Declaration order does not count |
| 3..14 locals live across one call (p8) | strictly r31, r30, r29, ... in assignment order, with no period-8 effect. Dead-local pads change nothing (p14) |
| params, then locals (p7 y6) | the parameter comes first |
| one value used in `add`, `addi` or `mulli` (`c + b`, `c + 1`, `c * 3`), or stored to a GLOBAL (`s2 = c`), against values used only in xori-style ops (p5, p12, p13, p21 n4/n5) | that value moves to the top. Two such uses beat one (m3: `s2=c; s3=c` puts c at r31; m1, with each value stored once, keeps parameter order) |
| `a + b` with both parameters (p5 w1, p13 e3/e4) | b=r31, a=r30, in either source order. Two locals in `x + y` keep assignment order (p14 a0) |
| a use in a separate block (a conditional arm, p10 b1-b3, p23 u5/u6) | promotes the value above values used only in the entry block (xori) |
| a use inside a loop body (p23 u1-u3, as a store, xori or shift) | promotes the value: i, then n, then the loop-used c, then the others |
| a call-argument use inside a loop (p10 b5/b6) | does NOT promote the value |
| a store of the value through a pointer (`x->a = z`, p16 h4) | does NOT promote it, whereas a store to a global does (h1-h3) |
| zero stored to two members with a call between them (p9 k5, p17 c3/c6/c7/c10) | the constant is CSE'd into ONE saved register (`li r31,0` once), placed at the dominator of its store uses |
| zero stored, all stores on one side of the call (p17 c1, c2, c4, c5) | a fresh volatile `li` |
| the constant as an int call argument, of any type: int, short, char, pointer, long long (p17 c8, p18, p19, p20) | ALWAYS a fresh `li rArg,0`, even while the CSE'd register holds 0. Variables, struct fields, arrays, `z+z`, `z^0`, `-z`, `k&0` and two-way assignments are all propagated into a fresh `li` |
| the constant passed as a 4-byte STRUCT by value (pz A2) | `mr r4,r31`, copied from the CSE'd zero register |
| a float constant argument (p18 d8) | `fmr f1,f31`, reused |
| `slot = &s->e; a = s->e;` against `a = *slot;` (pz C1/C2) | C1: s=r31, slot=r30, `addi` after the load. C2: slot=r31, s=r30, `addi r31,r3,0x10` BEFORE the load |
| `c = 0; if (n) c = f();` against `if (n) c = f(); else c = 0;` (pz D1/D2) | D1: the zero's `li` goes at the top, c gets its own saved register, and the frame uses `savegprlr_29`. D2: the zero's `li` goes after the call, c is copied in the else arm (`mr r3,r30`), and c stays volatile |

### Rules (what moves a saved register)

1. **Tie order.** Among values of equal weight, saved registers go from r31 downward in this order: parameters in
   parameter order, then locals in the order of their first assignment, as emitted. A value whose first assignment is
   later (inside a block, after a test) ranks lower. The order of `{ T x; }` declarations does not count. Dead-local
   pads do not shift it. This is NOT the OP1 period-8 numbering.
2. **Weight.** Some references raise a value above the tie order:
   - an `add`/`addi`/`mulli` operand;
   - a store of the value to a global;
   - a use in another basic block (a conditional arm);
   - a use inside a loop.

   References that do NOT count: call arguments, use as a load/store base, compares, xori/sub/and/or/shift, mullw,
   stores through a pointer. They do not count even repeated four times. The exact formula was not recovered. These
   are measured facts, not a model.
3. **Constants in saved registers.** A constant is held in a saved register only when two or more of its STORE uses
   lie on both sides of a call (stores only). Integer call arguments never reuse it. Three things do reuse it:
   - a struct passed by value with that value (`mr r5,r31`);
   - a phi copy (`c = 0` on one arm, `mr r11,r31`);
   - a bool idiom `a && b`, whose `li 1`/`li 0` become `mr` from the CSE'd 1 and 0 registers.

   So `mr rArg,rZero` before a call means a by-value struct argument (or a phi), never a plain int literal. A
   `one`/`zero` pair held in saved registers means literal stores straddling calls, plus a `&&`/`?:` that reuses
   them. Do not use user locals for them: a user local is constant-propagated and gives the opposite form.
4. **A pointer-to-member local** read through (`a = *slot`) is defined at entry: `addi` before the load, and a high
   saved register. Reading `a = s->m` directly lets the address local start later, so it gets a lower register.
5. **Phi shape.** For a zero-default variable, `if (n) c = f(n); else c = 0;` and `c = 0; if (n) c = f(n);` give
   different weights to the CSE'd zero. The first raised the zero from r29 to r31 in 0x886AD030. An explicit
   `else b = 0;` before a shared tail gives the tail-duplicated `stw; mr r3,rZero; bl` copies.
6. **An address-taken copy** stored at definition (`stw rX,0x50(r1)` right after the value is produced, register kept)
   is `T val = x;` with only `&val` passed, while `x` itself is used for the register paths. Making `x` itself
   address-taken puts it in memory (f20b/f20d: 30+ off).
7. Changes elsewhere in the function move the order (0x886E1738: rewriting the final loop as `o = s->o; n = o->h.cnt;`
   with `h = &o->h` inside the loop fixed the s/zero swap at the top). Try the other sites' known fixes first.

## Sub-class 2: volatile registers r11..r3. Probe table

| Probe | Result |
|---|---|
| straight-line chain of 15 loads and subtractions (q4 r4) | registers taken ROUND-ROBIN downward: r11, r10, r9, r8, r7, r6, r5, r4, r3, then wrap to r11. A register freed earlier is NOT reused before the wrap |
| `s->v18 = 0; p = s->owner->p74; p->f.. = 0.0f x4` (q1, q2, q3: locals, no local, inline helper, a `void *p` reused for both loads, a loop block, an int instead of a float constant, an extern float, a parameter float) | owner=r11, then the next registers, so p=r8 or r9. The chained load never reuses r11. Overwriting the same variable (`p = s->owner; p = p->p74`) changes nothing (c1/c2) |
| `s->owner->p74->f = 0` written four times (q2 b1) | four reloads walk r8..r3 and wrap to r11 at the fourth |
| order among simultaneously defined temporaries (q4 r1/r2/r5, q5) | follows the evaluation order of the (reassociated, canonicalised) expression tree, not the statement order. `x*y` evaluates y first. `(x-y)*z` gives x, y, z. `(x-y)-z` is reassociated to `(x-z)-y` and gives x, z, y. An add-rooted tree `x*y+z` gives y, z, x, and `x-(y-z)` gives z, x, y. Declaration order is irrelevant (o6 = o7 = o8) |

Rule: volatile registers rotate. The register a temporary gets depends on how many volatile values were allocated
before it in the same region, counted from r11 downward with wrap-around after r3. A target that reuses the register
of a value that just died (`lwz r11,0x74(r11)` in 0x8866D218) therefore had exactly 8 more volatile allocations
before that point than our source. Alternatively, its value was allocated before the intervening `lis`/`li`. No
source form tried reproduces it.

## Results on the listed functions (not matched)

| Address | Before | Best | File | What is left |
|---|---|---|---|---|
| 0x886581B8 | 43 | 2 | `work/army/RA1/f18g.c` | the zero argument is a 4-byte struct (`Id18 z; z.v = 0;`, rule 3), which fixes the frame and `mr r5,r29`. The `fp = s->vt->f4c` local fixes the r10/r11 pair. Left: `lwz r9,0x4c(r11)` is placed before `stw r10,0x50(r1)` in ours. A vt local, an inline `rec_a`, `Rec18 r[1]` and LTCG were tried (2-4 off) |
| 0x886E1738 | 26 | 8 | `work/army/RA1/e2c.c` | the vector sub-object `Vec v1c` at +0x1c with an inline `vempty(&s->v1c)` (the `addi r29,r3,0x1c`), literal zeros, and the loop rewrite. The registers are now all right. Left: stores of x/y scheduled after the argument `addi`s, the `lwz r29,0x58` order, and one OP1 add order. Tried: an inline `sum0` that zeroes through its pointers, block-scoped x/y, `y = 0; x = 0;` (worse), LTCG |
| 0x886559C8 | 20 | 6 | `work/army/RA1/b22b.c` | without an `end` local (b22a) the registers are right (v=r29, id=r28) but the loop reloads `end`. With the `end` local, `end` is hoisted but v and id swap. `w8b_vend(&self->vec)` for the erase gives the reload but folds it onto r31. A `find` inline (b22e) and `v` assigned at the top (b22f) are worse |
| 0x88650908 | 7 | 7 | `work/army/RA1/g3a.c` | found/n swap. A probe of the same shape (p22) gives found above n as in the target, so it is a weight effect from the real block structure. `found = 0; n = 0;` order makes no difference |
| 0x886AC928 | 38 | — | `work/army/W8A/v/f16b.c` | not a pure register case: it also needs a `r->rel` reload |
| 0x886612E0 | 28 | — | `work/army/W8D/r1.c` | the target loads `a` into r11 and copies it with `mr r29,r11` for the post-call uses, and the float store pattern differs. Not attempted further |
| 0x886CD580 | 5 | 5 | `work/army/RA1/a1*.c` | r10/r11 on subf/divw/mullw/add. A named `d` local, a split `idx` and an early `xv = x` copy make no difference |
| 0x8866D218 | 5 | 5 | `work/army/RA1/t4a.c` | see the volatile rule. `extern const float g_ts4_event_value` keeps r8 and reloads the constant |

Not attempted (budget): 0x886C84F0, 0x886CC408, 0x886690B0,
0x886C7CA0, 0x88661D28, 0x8866F9F0, 0x88662320, 0x886A5C88, 0x886B0380.
