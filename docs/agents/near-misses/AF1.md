# AF1: vector address forms, VMX32 numbering, vmaddfp128 (2026-11-15)

Compiler: cl.exe 16.00.10224.00 (sha256 `6c27181a805dee13…`), link.exe 10.00.10224.00, wibo as in `docs/ltcg-route.md`.
Split `work/matching-b64` (`TS4_MATCHING_DIR`). Python 3.13.18. About 95 compiles.
Scratch files are in `work/army/AF1/` (git-ignored):
- `chk.sh SRC name=0xADDR [...]`: `fn_check_ltcg.py ... --context src/xbox360/pp1_pool_primer.c --flags /Oc`, output in `last.txt`.
  Extra `--context` arguments go before the primer. Several `name=0xADDR` pairs with the same address can be used to test variants in one link.
- `td.py 0xADDR ...`: target disassembly from `work/army/VX1/textdis.pkl`.
- `p1.c`-`p12.c`: plain-route probes (`python3 work/army/OP1/op1dis.py FILE /Oc`). Lettered drafts (`a*.c`, `d*.c`, `g*.c`, `j*.c`, `m1.c`) are listed below.

## A. Address form of lvx128/stvx128 with a constant offset

### Rule A1: one use gives `li` + indexed, two uses of the same base+K give `addi`

The form is decided per address (base, K) when the address is CSE'd:
- `base+K` used **twice or more** in the function (for example a load and a store of the same row through one pointer) is CSE'd as a sum.
  That gives `addi rT,base,K` and `lvx128/stvx128 v,r0,rT`.
- `base+K` used **once** keeps K as an operand. That gives `li rK,K` and `lvx128 v,base,rK`. The `li` register is shared by every base that uses K
  once, so `li r9,0x10; li r10,0x20; li r11,0x30` is materialised once.

Plain-route probes (`p1.c`, `p3.c`):

```c
void f1(__vector4 *m) { __vector4 a=m[1],b=m[2],c=m[3]; m[1]=__vaddfp(a,b); m[2]=..; m[3]=..; }      /* addi r11,r3,0x10 ... (same base twice) */
void f4(__vector4 *d, const __vector4 *s) { __vector4 a=s[1],..; d[1]=..; }                          /* li r9,0x10; lvx128 v,r4,r9; stvx128 v,r3,r9 */
void h5(__vector4 *m, const __vector4 *s) { a=s[1],b=s[2],c=s[3]; m[1]=a; s=m; a=s[1];.. m[1..3]=..; } /* 0x10: li (two bases); 0x20/0x30: addi */
```

The following do not change it: array index vs `(char *)p + 16` vs struct member, a local copy of the pointer, an inline with
`(out, in)` both bound to the same pointer, an inline accessor returning the pointer, or unrolled copy loops. All were tried (`p2.c`, `p3.c`, `p6.c`, `p7.c`).

### Rule A2: a matrix passed BY VALUE to an inline is read late, so it gives the `li` form even when the same rows are stored back

When the target uses `li` + indexed for both the loads and the stores of the **same** pointer (0x8864E4B0, 0x8864E6B8), the source passes the
matrix by value to an inline helper and assigns the result row by row:

```c
typedef struct Af1Mat { __vector4 r[4]; } Af1Mat;            /* not passinreg: a 4-row struct cannot be (C2280) */
static __forceinline Af1Mat transpose(Af1Mat m) { ... return t; }
static __inline void mat_set(Af1Mat *d, const Af1Mat *s) { d->r[0]=s->r[0]; ... d->r[3]=s->r[3]; }   /* operator= */
void f(Af1Mat *m) { Af1Mat t = transpose(*m); mat_set(m, &t); }   /* li r9,0x20; lvx128 v,r3,r9 ... stvx128 v,r3,r11 */
```

The by-value copy is scalar-replaced after address CSE. Its loads are forwarded from `*m` with the member offset as the index, so
each load is a separate one-use address. In C, `*m = f(*m)` (a struct assignment) gives an `ldu/stdu` loop instead. Write the stores row by row
(`mat_set`, or C++ `operator=` with four row assignments; both give the same code, `p8.cpp`, `p9.c`). In LTCG, a large helper needs
`__forceinline`, or it stays a call.

### Rule A3: a pointer passed to an inline gives `addi`; an `&member` written through twice gives `addi`

In 0x8867D2B0 the fifth row is `lerp_to(&out->v, &a->v, b->v, t)`, where the inline reads `*a` twice and writes `*o` twice. The result is
`addi r8,r4,0x40` (a), `addi r7,r3,0x40` (out) and `li r31,0x40` (b, read once). That is rule A1 counted after inlining.

### What stays open in A

- 0x88645B98 (w6b_e.c): target `add r9,base,off; lvx128 v,r0,r9` with a strength-reduced offset. Ours gives `lvx128 v,base,off`.
  A local struct copy (`E30 e = *(E30 *)p`) is not removed (ld/std copy). A by-value inline `first(E30 e)` gives the same code as the direct load.
  Draft: `work/army/AF1/b3.c`, 32 instructions, all register shifts from this one address. It is the same open form as VX1's 0x8866C8B8.
- 0x88670CC8 (w6a_b.c): `addi r10,r11,0x30; stvx128 v62,r0,r10` comes from a sub-struct pointer. The vector and the three floats after it form
  one struct `S30 { __vector4 v; float f10,f14,f18; }` that is reset through an inline taking `S30 *`. Writing `s->b8d = 0;` first fixes
  the `stb` position. That leaves 7 instructions: the target stores the vector before the three `stfs` and puts the zero in v63 and the constant in v62,
  while ours sinks the store to the end and swaps them. Draft: `work/army/AF1/j5.c` (`k_b`). Not tried further.
- 0x88645348, 0x88645AD8, 0x886633E8, 0x8866C8B8: not attempted in this round. Rule A2 is the first thing to try for 0x886633E8 (translate
  applied to a matrix by value).

## B. VMX32 register numbering (vspltw + 3-input vmaddfp) and vmaddfp128

### Rule B1: TransformCoord takes the matrix BY VALUE

0x8864E980, 0x8864E908 and 0x8864E9F8 all match with:

```c
static __forceinline __vector4 transform_coord(__vector4 v, Af1Mat m)   /* m by value */
{
    __vector4 z = __vspltw(v, 2), y = __vspltw(v, 1), x = __vspltw(v, 0), r, w;
    r = __vmaddfp(m.r[2], z, m.r[3]);       /* note m.r[2] first: vmaddfp v13,v12,v10,v13 */
    r = __vmaddfp(y, m.r[1], r);
    r = __vmaddfp(x, m.r[0], r);
    w = af1_recip(__vspltw(r, 3));          /* vrefp + 2 Newton steps + vsel */
    return __vmulfp(r, w);
}
```

With a pointer matrix (`m->r[i]`, or named row locals as in w6b_d.c/w6a_d.c), the first vmaddfp writes over `m.r[2]`, and x lands in v13 instead
of v7 (5 instructions off). With the by-value matrix, m3 is loaded into the accumulator register (v13), and the rest follows. The multiplicand
order of the first madd decides the last instruction (`(z, m2)` leaves 1 off).

### Rule B2: matrix multiply as one nested expression per row

In 0x8864E4B0 (`m = m * fromquat(q)`), each output row is one expression
`__vmaddfp(spl3, b3, __vmaddfp(spl2, b2, __vmaddfp(spl1, b1, __vmulfp(spl0, b0))))`. Then each vmaddfp writes over its splat operand
(`vmaddfp v2,v2,v0,v1`, as in the target). Reassigning an accumulator (`x0 = __vmaddfp(s, b1, x0)`, as in w6b_f.c) writes over the accumulator
and shifts the whole VMX32 numbering (29 instructions off). The matrix is by value (rule A2).

### Rule B3: `vmaddfp128 vD,vA,vB` (addend as destination) is a contracted multiply and add on a value stored then reloaded

```c
static __inline void lerp_to(__vector4 *o, const __vector4 *a, __vector4 b, float t)
{
    __vector4 l = __vmulfp(__vsubfp(b, *a), __vspltw(__lvlx(&t, 0), 0));
    *o = *a;
    *o = __vaddfp(*o, l);       /* lvx128 v58; vor128 v54,v58,v58; vsubfp128; vmaddfp128 v54,v56,v0; stvx128 v54 */
}
```

The reload of `*o` is forwarded late into a `vor128` copy. The `__vmulfp` + `__vaddfp` pair is contracted into vmaddfp128, which overwrites
the copy. There is no `__vmaddcfp`/`__vmaddfp128` intrinsic (c1.dll lists only `__vmaddfp`). Every direct form gives VMX32 `vmaddfp`
(probes `p10.c`-`p12.c`): `__vmaddfp(x, s, *o)`, `__vaddfp(*o, __vmulfp(..))` and `*o = __vaddfp(__vmulfp(..), *o)`. Computing `l`
before the copy matters. With the subtraction after the copy, `*o` is stored, `*a` is reloaded and the store is not dead
(`d5.c`, 32 instructions off).

0x8868ED00 (the vmaddfp128 dest is a real load of `*out` in a loop with a call) does not follow from B3. The add form `*out = __vaddfp(*out,
__vmulfp(..))` still gives VMX32 there (`e2.c`). It also needs fn_8867A7C0's register use in context (ours saves v127/f28-f31). Open.

### Open in B

- 0x88661238 (matrix lerp alone): 7 instructions off, the same in every form. The subtraction results are allocated v6,v9,v8,v7, and the target
  has v7,v6,v8,v9. The same body inside 0x8867D2B0 gives that function's target allocation exactly. Forms that change nothing: by-value matrices
  (10 off), the result through a local, the order of the a/b/d statements, splat first or last, operand order, `__vaddfp(__vmulfp())` and 1-8
  dead int locals (`g1.c`-`g3.c`).

## C. `vor128` copy of a loaded constant stored to two members

Not found. 0x8867D8D0 (`s->a = K; s->b = K; s->f20 = s->f24 = 0`) reaches 6 instructions off with any of the following: `s->b = s->a`,
pointer setter helpers on either store, an accessor returning `&s->a`, `vcopy(&s->b, &s->a)`, a by-value pair built in an inline
(`p.b = p.a` or `mkpair2(K)`), or a by-value pair passed to a setter (`m1.c`, `c_a`-`c_h`). Everything matches except the `vor128 v62,v63,v63`:
the forwarded copy is coalesced away when nothing modifies it. In the B3 and VX1-rule-2 cases, the copy survives because a destructive
instruction (vmaddfp128, vrlimi128) writes over it. That is the lead to try next: the constant stored to `b` may be modified in place
by a lane or madd operation that folds away.

## Matched (LTCG route, `/Oc`, primer last, word MATCH, exit 0)

| Address | Size | Function | Source | Spec | Rules |
|---|---:|---|---|---|---|
| 0x8864E4B0 | 0xF4 | `ts4_matrix_mul_quat_in_place_8864E4B0` | `src/xbox360/af1_mat_mul_quat.c` | `work/specs/AF1/af1_mat_mul_quat.json` | A2, B2 (context `flags(/Ob1):src/xbox360/w6b_ctx_e310.c`) |
| 0x8864E6B8 | 0x50 | `ts4_mat_transpose_8864E6B8` | `src/xbox360/af1_mat_transpose.c` | `work/specs/AF1/af1_mat_transpose.json` | A2 |
| 0x8864E980 | 0x78 | `ts4_transform_coord_8864E980` | `src/xbox360/af1_mat.c` | `work/specs/AF1/af1_mat.json` | B1 |
| 0x8864E908 | 0x78 | `ts4_transform_coord_in_place_8864E908` | `src/xbox360/af1_mat.c` | same | B1 |
| 0x8864E9F8 | 0xC0 | `ts4_transform_vec3_in_place_8864E9F8` | `src/xbox360/af1_mat.c` | same | B1 |
| 0x8867D2B0 | 0x9C | `ts4_xform_lerp_8867D2B0` | `src/xbox360/af1_mat.c` | same | A3, B3 |
| 0x8864E7F8 | 0x54 | `ts4_mat_translation_8864E7F8` | `src/xbox360/af1_mat.c` | same | A2 (rows built r[3]..r[0]) |
| 0x8864EFF0 | 0x60 | `ts4_mat_translation_from_ptr_8864EFF0` | `src/xbox360/af1_mat.c` | same | A2 |
| 0x8864F050 | 0x60 | `ts4_mat_translation_from_ptr_8864F050` | `src/xbox360/af1_mat.c` | same | A2 |

- Command, for example: `python3 tools/fn_check_ltcg.py src/xbox360/af1_mat.c ts4_transform_coord_8864E980=0x8864E980 ... --context src/xbox360/pp1_pool_primer.c --flags /Oc`.
  For 0x8864E4B0, add `--context "flags(/Ob1):src/xbox360/w6b_ctx_e310.c"` before the primer. Without it, the target's `mr r8,r3` (m kept
  in a volatile register across the call) becomes `std r31` (23 instructions off).
- Translation matrices: the stores come out in the target order (`r[3]` first, then the `li 0x30/0x20/0x10` rows) only when the inline builds
  the rows in the order `r[3], r[2], r[1], r[0]`. With `r[0]` first, 4 instructions are off. 0x8864EFF0 and 0x8864F050 are byte-identical in the target.
- The helpers are in `src/xbox360/af1_vector.h`: `Af1Mat`, `af1_mat_mul`, `af1_mat_set`, `af1_mat_transpose`, `af1_recip`,
  `af1_transform_coord`, `af1_vec_lerp_to`, `af1_mat_lerp_rows`, `af1_mat_translation`. They were written from the instruction sequences.
- All three sources pass `cc -std=c11 -Wall -Wextra -Werror -fsyntax-only -Isrc/xbox360`.

## Near misses left

| Address | Draft | Diff | Note |
|---|---|---|---|
| 0x88661238 | `work/army/AF1/g3.c` | 7 | B open (sub register order) |
| 0x88670CC8 | `work/army/AF1/j5.c` `k_b` | 7 | A partly: addi from sub-struct pointer; vector store order |
| 0x8867D8D0 | `work/army/AF1/m1.c` `c_a` | 6 | C open (vor128 copy) |
| 0x88645B98 | `work/army/AF1/b3.c` | 32 | A open (`add; lvx r0`) |
| 0x8868ED00 | `work/army/AF1/e1.c` | 43 | needs callee register info; vmaddfp128 from a real load |
