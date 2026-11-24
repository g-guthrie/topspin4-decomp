# VX1: VMX128 vector code (2026-11-15)

Compiler: cl.exe 16.00.10224.00 (sha256 `6c27181a805dee13…`), c1.dll `efdba0fdb4ac2684…`, c2.dll `349694b184976d44…`,
link.exe 10.00.10224.00, wibo as in `docs/ltcg-route.md`. Split `work/matching-b62` (`TS4_MATCHING_DIR`). Python 3.13.18.
Scratch files are in `work/army/VX1/` (git-ignored):
- `census.py [LO HI] [--list]`: every `.text` function of the original that uses a vector register, matched or not,
  with the register classes used (a = v0-v13, b = v14-v31, c = v32-v63, d = v64-v127). Disassembly comes from
  `work/ppcdis` (VMX128-aware) and is cached in `textdis.pkl`;
- `pat.py`: pattern counts over unmatched vector functions;
- `chk.sh SRC name=0xADDR [...]`: `fn_check_ltcg.py ... --context src/xbox360/pp1_pool_primer.c --flags /Oc`;
- `e/*.c`: the probes below (`python3 work/army/OP1/op1dis.py FILE [flags]` disassembles them, VMX128 included);
- `rt/`: the four RT1 sources rebuilt with the aligned `__vector4`;
- `nm_8866C8B8.c`, `nm_88644C58.c`, `nm_88679900.c`: near misses.

## Census

`python3 work/army/VX1/census.py LO HI` (match state from `config/54540859/match.json`):

| range | matched vector fns (bytes) | unmatched vector fns (bytes) |
|---|---:|---:|
| whole image | 113 (8,800) | 2,025 (1,504,772) |
| game core 0x88150000-0x882A0000 | 10 (1,456) | 141 (172,500) |
| libraries 0x882A0000-0x885F4E48 | 11 (296) | 1,182 (752,120) |
| game LTCG 0x885F4E48-0x889D3410 | 92 (7,048) | 699 (579,052) |
| gameplay 0x88640000-0x886E8000 | 48 (3,220) | 422 (295,248) |

The 113 matched ones are tiny: getters/setters and constant copies from the bulk generators (fk3/fk5/fk6, sm1-sm5),
a few ball-model functions (bm_/nm2_, plain route) and `ga4_arm_timed_slot` (`*(__vector4 *)p = pos; f(self, pos)`).
None of them changes a lane, copies a vector struct, or keeps a vector across a call.

Unmatched vector functions with a pattern (`pat.py`; v2-v13 excludes the dummy `v0` operand of vspltisw128):

| range | total | `vor` copy | lvlx | vrlimi128 | stvewx | v0/v3-v13 used |
|---|---:|---:|---:|---:|---:|---:|
| gameplay | 422 | 169 | 174 | 125 | 73 | 130 |
| game LTCG | 699 | 279 | 318 | 164 | 180 | 235 |

## Rules

### 1. Temporaries are v63 downwards; v0-v13 come only from VMX32-only encodings (no flag is involved)

Our compiler and the original use the same allocator. Temporaries take v63, v62, ...; a value live across a call takes
v127, v126, ... and is saved before `stwu` with `li r12,-0x20; stvx128 v127,r1,r12` (0x88679900, reproduced). v1, v2, ...
are by-value `__vector4` arguments and the return value.

v0-v13 appear when a value feeds or comes from an instruction that has no VMX128 form for that operand: the 3-input
`__vmaddfp(a, b, c)` (VMX32 `vmaddfp`; `vmaddfp128` overwrites its addend) and a `__vspltw` whose result feeds it (the
compiler then picks VMX32 `vspltw`). Probe `e/q.c`, plain route, no flags:

```c
__vector4 a = *pa, b = *pb;
__vector4 t = __vsubfp(__vmulfp(__vpermwi(a, 99), __vpermwi(b, 135)), __vmulfp(__vpermwi(a, 135), __vpermwi(b, 99)));
t = __vmaddfp(a, __vspltw(b, 3), t);  t = __vmaddfp(b, __vspltw(a, 3), t);
*d = __vrlimi(t, __vmsum3fp(a, b), 1, 0);
/* lvx128 v0; lvx128 v13; vpermwi128 v63..v59; vspltw v10,v13,3; vspltw v12,v0,3; vsubfp128 v11,..;
   vmaddfp v0,v0,v10,v11; vmaddfp128 v0,v13,v12; vrlimi128 v0,v62,1,0; stvx128 v0 */
```

This is the shape of 0x88645F20 (`lvx128 v13/v0`, `vspltw v11,v13,3`, `vmaddfp v13,v13,v12,v10`, `vmaddfp128`).
So "v0-v13 vector register use" is not a whole-program effect: it follows from which intrinsic the source used.

`cl.exe` strings list `/QVMX128` (`-D__VMX128_SUPPORTED=1`) and `/QVMXReserve` (`__VMX128_RESERVE`); c2 has
"VMX128 extensions disabled". Not needed: the default already emits VMX128. Not tried further.

### 2. `vor128 vD,vS,vS` copies: a vector member changed through a pointer helper (LTCG)

The copy is a late-forwarded load, the vector form of CL1's `clrrwi` copy. Writing the member through an inline helper
that takes a pointer to it gives the copy and keeps later scalar accesses below the vector store:

```c
static __inline void vx1_vec_set_x(Vx1Vec *p, float x) { p->v = vx1_set_x(p->v, x); }
vx1_vec_set_x(&s->vel, scale.v[0] * vx1_vec_x(&s->vel));
vx1_vec_set_z(&s->vel, vx1_vec_z(&s->vel) * scale.v[2]);   /* -> stvx128 v63; vor128 v61,v63,v63; ...; vrlimi128 v61 */
```

`s->vel = vx1_set_x(s->vel, ..)` (direct) and the CL1 forms (`get(s)->vel = ..`, a local pointer, a local copy)
all give no copy and hoist the following `lfs 0x24(r3)` above the store (34 instructions off). C helpers and C++
member functions (`s->vel.SetX(..)`) give the same code. Verified on 0x8867D7C8 (LTCG; the plain route also fails on
the pooled select table).

### 3. Lane setters and splats are the xnamath bodies

- set lane x/y/z/w: `t = __lvlx(&x, 0); __vrlimi(v, t, 8,0 | 4,3 | 2,2 | 1,1)` gives `stfs; lvlx128; vrlimi128`;
- splat a scalar: `__vspltw(__lvlx(&x, 0), 0)`;
- read one lane: `.v[i]` gives `stvx128` to a stack slot then `lfs` (by-value arguments are read from their home slot,
  `stvx128 v1,r1,r12` with r12 = frame+0x20);
- extract a dot product: `__stvewx(v, &f, 0)` gives `stvewx128` (intrinsic name from the c1.dll table).

These are in `src/xbox360/vx1_vector.h` as `vx1_set_x/y/z/w`, `vx1_replicate`, `vx1_vec_set_*`.

### 4. `__vector4` must be 16-byte aligned (ts4_vector.h is not)

`ts4_vector.h` declares `struct __declspec(passinreg) __vector4 { float v[4]; }` with no alignment:
`__alignof(__vector4)` is 4 and `sizeof(struct { int a; __vector4 v; })` is 0x14 (probe `e/al.c`). A struct or union
holding one is then copied with four `lwz/stw` pairs. With `__declspec(passinreg) __declspec(align(16))`
(`e/al2.c`) the alignment is 0x10, the size 0x20, the copy is `ld; ld; std; std` as in the game (0x88670C20), and
by-value passing is unchanged (`return __vaddfp(a, b)` is `vaddfp v1,v1,v2; blr`). `src/xbox360/vx1_vector.h`
defines this type; it sets the `TS4_VECTOR_H` guard so a later `#include "ts4_vector.h"` is a no-op, and stops with
`#error` if ts4_vector.h came first. It also wraps the intrinsic declarations in `extern "C"`: a .cpp including
ts4_vector.h directly fails to link (`unresolved external ?__vrlimi@@YA?AU__vector4@@...`).

### 5. Loop unrolling: write the count-down test with the constant on the left

`for (i = n - 1; i >= 0; i--)` is unrolled (by 2 for a float sum, by 4 in 0x8866C8B8's body); `for (i = n - 1; 0 <= i; i--)`
is not, and gives the target's `subic. rI,rN,1; blt; addi; mtctr; ...; bdnz` (probes `e/u6.c`, `e/u7.c`, plain route):

| loop | result |
|---|---|
| `i = n-1; i >= 0; i--` / `--i` / `while (--i >= 0)` / `i > -1` | unrolled |
| `i = n-1; 0 <= i; i--` | **not unrolled**, `subic.` + `bdnz` |
| `i = 0; i != n; i++`, `unsigned i = n; i-- != 0;`, `while (i-- > 0)`, `i != -1` | not unrolled (other shapes) |
| `i = 0; i < n; i++` | unrolled |

Same on the LTCG route. In 0x8866C8B8 this removes the whole unrolled body (0x218 bytes -> 0xCC; target 0xD0).

### 6. The FP1 select inside a loop, and the min helper

If-conversion to the `mfcr`/`fsel` table runs after unrolling: in an unrolled body only the first copy is converted.
Assigning the select back to the same variable (`best = (best - f >= kZero) ? f : best;`) or returning it from a helper
written `return (a - b >= z) ? b : a;` gives a branch (`bltlr`); a fresh local gives the select:
`static __inline float min(float a, float b) { float r = (a - b >= kZero) ? b : a; return r; }` (probes `e/u4.c`, `e/u5.c`).

### 7. Constants addressed from another constant: lay them out in one static struct

0x88670C20 loads 0.5f with `lvlx128 v62,rZ,r5; li r5,0x4d0`, rZ = the address of the named zero (BINKCONS 0x8814B440;
0.5f is at 0x8814B910). The code generator addressed one constant from the other, so it knew both places. Two
`static const float`s in one file give the same shape with `li r5,4` (they are laid out adjacently); a separate
`static const` gap array is placed after them, and an `extern const` pair defined in a context file is folded to
literals under LTCG (bare `fsel`, 32 instructions off). A file-scope `static const struct { float zero; unsigned gap[0x4cc/4];
float half; }` reproduces `li r5,0x4d0` exactly, and `.zero` still gives the FP1 select. This stands in for the original's
constant layout, like `pp1_pool_primer.c`; it is not the original source.

Two vector constants used separately (0x88644C58: `lbl_880D1B10` and `lbl_880D1B00`, adjacent in the original) must be
extern: two `static const __vector4` in the file are addressed as base + `li 0x10` (lvx128 indexed). Declare them by their
symbols.txt names (`extern const __vector4 lbl_880D1B10;`).

### 8. Results returned through a pointer

0x8867D9A0 writes a `__vector4` local to `*out` with `lvx128/stvx128` and returns `out` in r3 (`mr r3,r31`): declare the
function as returning the pointer (`__vector4 *f(__vector4 *out, ...) { ...; *out = r; return out; }`).

### 9. Frame size of 0x8867DF68 is not a vector effect

The target frame is 0x130 against RT1's 0x120 because the target saves one more GPR (`__savegprlr_26` vs `_27`, an extra
live pointer `r31 = pc + 0x5a0`), which moves the FPR/VMX save slots and the locals by 0x10. Rebuilding the four RT1
sources with the aligned `__vector4` changes nothing (`work/army/VX1/rt/`, same diff counts).

## Matched (LTCG route, exit 0)

Command for each: `python3 tools/fn_check_ltcg.py <src> <name>=<addr> --context src/xbox360/pp1_pool_primer.c --flags /Oc`.

| Address | Size | Source | Spec |
|---|---:|---|---|
| 0x8867D7C8 | 0xB4 | `src/xbox360/vx1_scale_velocity_xz.c` (rule 2, 3) | `work/specs/VX1/vx1_scale_velocity_xz.json` |
| 0x88670C20 | 0xA8 | `src/xbox360/vx1_clamp_speed_half_vel.c` (rule 3, 4, 7) | `work/specs/VX1/vx1_clamp_speed_half_vel.json` |
| 0x8867D9A0 | 0x8C | `src/xbox360/vx1_polar_offset_xz.c` (rule 3, 8) | `work/specs/VX1/vx1_polar_offset_xz.json` |

- 0x8867D9A0 also matches with plain `fn_check.py --flags /Oc`, but that reports `RENAME lbl_8814B440 -> vx1_zero_d9a0`
  (the split still names the zero lbl_8814B440, and the candidate's is a static), so the spec uses the LTCG route, where
  the static zero compares by value.
- 0x8867D7C8 calls `fn_88670C20` (its current name). The plain route fails both 0x8867D7C8 (34) and 0x88670C20 (24) on the
  pooled select table.
- All three sources pass `cc -std=c11 -Wall -Wextra -Werror -fsyntax-only -Isrc/xbox360 -Iinclude`;
  `vx1_vector.h` also passes `c++ -std=c++11` with the same flags.

## Near misses

| Address | Draft | Diff | What is left |
|---|---|---|---|
| 0x8866C8B8 | `work/army/VX1/nm_8866C8B8.c` | 0xCC vs 0xD0, 34 instructions (register shift from one instruction) | Loop (rule 5), select (rule 6), tag access all match. The target forms the element address in full (`add i16,ph; add rel; lvx128 v62,r0,rA`); every source form tried is folded to `add rel,i16; lvx128 v62,rA,rPh`: char-pointer sums in either order, unsigned casts, `&arr[i]` then `+ rel`, element struct `{__vector4 pos;}`, inline accessor returning a pointer, pointer local. An inline `vload(const __vector4 *)` returning `*p` instead copies through the stack (ld/std). Open. |
| 0x88644C58 | `work/army/VX1/nm_88644C58.c` | 8 instructions | sin/cos polynomial (vmulfp, vspltw128 1, vmsum4fp128 against `lbl_880D1B10`/`lbl_880D1B00`, `stvewx128`) and the rotate. Vector part and stack slots match with `float sc[2]` (cos in `sc[1]`); two scalars put cos at -0x20 (10 off). Left: f0/f13 swapped in the scalar tail and the product operand order (`x*s` vs `s*x`). Tried: operand order, load order, declaration order, locals, rotate helpers. |
| 0x88679900 | `work/army/VX1/nm_88679900.c` | 8 instructions | Everything but the stack slot of the two lane-setter temporaries: target 0x58 (one slot for both, separate from the sin/cos outputs at 0x50/0x54); ours reuses 0x50/0x54. Tried: nested or sequential setters, explicit `float t` reused, temporaries in an inner block, declaration order, `float ab[2]`, a struct pair, a rotate helper (that one loses the v127 copy). |

## The four retune functions

Measured with `work/army/VX1/chk.sh` (LTCG, primer, /Oc), RT1 sources unchanged and rebuilt with the aligned
`__vector4` (`work/army/VX1/rt/`): no change.

| Function | Now | Notes |
|---|---|---|
| 0x8867DF68 `rt1_vmx_timing_update.c` | 0x314 vs 0x320, 193 | rule 9: the first difference is the extra saved GPR (an address `pc+0x5a0` kept in r31), not a vector.|
| 0x886807C0 `rt1_vmx_outcome_roll.c` | 0x7A8 vs 0x900, 568 | not re-worked |
| 0x8869B928 `rt1_vmx_net_rush.c` | 0x29C vs 0x2A4, 161 | not re-worked |
| 0x889C1C80 `rt1_vmx_ball_bounce.c` | 0x300 vs 0x2EC, 162 | not re-worked (RT1 measured 164 on b46) |

What applies to them: rules 2 (lane setters on members through pointer helpers give the `vor` copies), 3, 4, 6 and 7.
They were not rewritten in this round.

## Ruled out

- Flags: `/QVMX128` and `/QVMXReserve` exist but are not needed; v0-v13 use and v63-down allocation reproduce with
  `/O2 /Oi` (plus `/Oc`), on both routes.
- `__lvx` does not exist in this compiler (c1.dll lists `__lvx_volatile`, `__lvlx`, `__lvrx`, `__lvewx`, `__lvebx`,
  `__lvehx`, `__lvsl`, `__lvsr`, `__stvewx`, `__stvlx`, `__stvrx`, `__stvx_volatile`, the `__v*` arithmetic and the `R`
  record forms such as `__vcmpeqfpR`). Plain loads and stores are `*(__vector4 *)p`.
- C vs C++ makes no difference for rule 2 (both match 0x8867D7C8).
- Aligned `__vector4` does not change the RT1 diffs.
- A struct copy of a 4-aligned float[4] is lwz/stw; a struct copy of an aligned float struct is ld/std; neither gives lvx.
