# Codegen tips collected from agents (re-read when you pick new work)

- Relative array begin/end (offset -1 = no array): `begin = 0; if (r->off != -1) begin = ...; end = 0; if (r->off != -1) end = ...;`
  with `end = 0` AFTER the first `if`. Initialising both up front merges the branches wrongly. Many functions with
  `cmpwi rX,-1` are this family.
- Backward walk: `while (p != begin) { r = *(p-1); ...; p--; }` gives subi+lwz with beqlr; `do { r = *--p; }` gives lwzu.
- Hoisted zero result (`li rX,0 ... mr r3,rX`, or `mr r10,r3; li r3,0`): result local initialised to 0, set in each
  branch (`r = f(); break;`), returned once.
- Compare operand order follows source order: `id == p->id` gives `cmplw r4,r7`; reversed gives `cmplw r7,r4`.
- Bool from &&: `ok = a != 0 && b == 0;` gives li 1 / li 0 / clrlwi. Untruncated flag stored then tested with clrlwi:
  `int fault = a && b && c; flow->fault = fault; if ((ts4_bool)fault)`.
- Float args consume GPR slots: for fn(float, ptr) the pointer is in r4 and r3 is never set.
- Static helper called with `&self->member` stops the member offset being folded (separate `r30 = this+0x38`).
- Result-by-value struct: `*dst = fn(w)` with a 16-byte struct gives the `addi r3,r1,0x50` sret call plus four-word copy.
- 12-byte handle by value plus unused int before a pointer parameter: call as `f(this, handle, int, ptr)`.
- Vector args: `#include "ts4_vector.h"`, pass `__vector4` by value; `*(__vector4 *)p = pos` before a tail call gives stvx128 v1.
- C++ class whose constructor zeros members, followed by a fill loop through `this`, keeps the dead zero stores.
- Self-relative players array: `p = ts4_score_players(s)` plus a separate local `p1 = &p[1]`.
- zlib: crc32() wrapper is inlined with a null check; deflate needs GZIP defined. Lua: lua_type must be inlined.
- A volatile local buffer keeps out-of-frame stores.
- Callee names: once a function is renamed in symbols.txt, fn_check fails the relocation check if you use the fn_ name.
  Check with `grep -i "0xADDR;" config/54540859/symbols.txt`.
- Leave alone (whole-program patterns, under investigation by agent LT1): callers relying on r4/r6/r7/r9/f10 surviving a
  call, fsel/mfcr float selects, v0-v13 vector register use. (`clrrwi rX,rX,0` is solved, see the CL1 section; divw
  with no trap is `/Oc`.)

## Added from GA3
- Hash/id arguments: pass a 4-byte hash or id as a one-member struct by value (`struct Ga3Id` in src/xbox360/ga3_types.h).
  That gives `lis/ori rX; mr r4,rX` and the late `lis r4` before calls; a plain unsigned folds straight into r4.
- Virtual-call thunks (`??_9Class@@$B...`): call through a pointer-to-member constant, `(h->*(&Cls::slot_00e))()`, in a
  .cpp with a class named exactly `TS4VcallClass88271E68` (see src/xbox360/ga3_c.cpp). MSVC emits a direct bl to the thunk.
- Self-relative arrays, alternative form: two `__forceinline` helpers begin()/end(), each returning 0 when offset is -1;
  end is `(char*)a + (count*N + offset)`; call end() before begin(). Gives the duplicated `cmpwi -1` + `mr`.
- Float sign test: `*(unsigned short*)&d & 0x8000` on `d = 0.5f - x` gives stfs; lhz; clrrwi 15. `(x > 0)` assigned to
  unsigned char gives neg; andc; srwi 31; declaring it int flips cmplwi to cmpwi.
- A callee that returns its `this` in r3 lets the target skip `mr r3,r31` before the next call: declare it as returning
  the pointer and pass the result on.
- Counter wrap without a local: `p->count = (p->count + 1 > 6) ? 0 : p->count + 1`.
- Some address-taken struct parameters are 4-byte structs passed in r4/r5.
- Float model: where the target recomputes `a+b` after a call instead of reusing it, try `--flags /fp:strict` (unresolved,
  under investigation by LT1).

## Link-time code generation (LT1, confirmed)
The original was built with /GL + /LTCG for 362 of its objects. The "callee leaves registers untouched / caller relies
on r4,r6,r7,r9,f10 surviving a call / read r" patterns are cross-object register knowledge, and they reproduce when the
callee's source is in the same link. Checker: `python3 tools/fn_check_ltcg.py --setup` once, then
`python3 tools/fn_check_ltcg.py <src> name=0xADDR --context <file with the callees> ...` (see `--help`).
The matching build does not accept LTCG-verified functions yet (in progress). Until it does: when a function fails only
for that reason, try the LTCG checker; if it matches there, keep the source in a separate file `<id>_ltcg_*.c` with a
spec `work/specs/<ID>/<stem>.ltcg.json` (same format plus "route": "ltcg" and "context": [files]) so it can be
integrated later. Do not list it in a normal spec.

## Added from GA6 and DG1
- Bool result: `static unsigned char helper()` returning `a && b` gives li 1 / beq / li 0 / clrlwi. Reloading a field
  three times needs a `volatile struct *`.
- Signed compare of a pointer or handle: `(long)p != 0` gives cmpwi instead of cmplwi.
- Dead `addi` of a sub-object address: a static inline function taking `struct Sub *`, called on `&self->sub`.
  Vector clear / pop_back: `v->end = copy(v->end, v->end, v->begin)` with a copy helper.
- Self-relative array element: `(char*)hdr + *hdr + idx*stride`. A callee reading 6+ register args needs the full prototype.
- Switch of n in 0..7 returning `base + n*8`: a real switch with `case 0: return base;` gives the bdz chain.
- `#pragma intrinsic(strcmp)` (under `#ifdef _MSC_VER`) makes /O2 inline strcmp as the original's byte loop.
- Statement order of locals matters (`idx = h % count; bk = t->buckets; *hash_out = h; ...`); permute it.
- In C++, `return voidfunc(args);` gives a real tail call (b) and a frameless function.
- Families that differ only in field offsets: one macro per family (see src/xbox360/dg1_string_table_find.c).

## Added from GA2 and GA4 (second pass)
- Use real structs with padding (`PAD(n)`, see src/xbox360/ga2_types.h), not `*(T*)((char*)p+off)` casts: the casts change
  register allocation.
- `addi rX,rY,K` followed by field accesses off rX: keep a local pointer to the sub-struct or self-relative header
  (`struct Hdr *h = &owner->hdr;`), element = `(char*)h + (idx*stride + h->rel)`. Folding K into the offsets diverges.
- Plain `for` over begin/end on real structs matches list searches easily. `x->count++` gives addi/lwz/addi/stw.
- Vcall thunk `??_9TS4VcallClass<addr>@@$B<d>AA`: single-digit suffix d means vtable offset d+1 (7 = offset 8 = slot 2).
- A self-recursive function: recurse through the existing `fn_<addr>` placeholder to avoid a rename entry in the spec.
- memset is not inlined by this compiler; a small constant-trip inner loop does unroll.

## Added from GA1
- One shared return after a loop: result variable set up front (`int r=-1; ... r=i-1; break;`, `u32 ok=0; ... ok=1;`).
- Self-relative array inside a loop: declare the base pointer inside the loop body (`struct Rel *a = &t->recs;`).
- Indexed loads: element address written as `(char*)t + (off + mid*8)` gives `lwzx rIndexSum, rBase`.
- u32 pointer difference with u32 counter gives cmplw/beq; a signed counter gives cmpw/ble.
- Zeroed 0x80-byte stack local: `for (i = 0; i < 16; i++) buf.q[i] = 0;` on `unsigned long long q[16]` gives the
  stdu/bdnz loop; `= {0}` gives a memset call.
- `fn(a, &param)` takes the address of the incoming register-home slot with no copy.
- A constant float through `extern const float` is reloaded after every store; hoist it into a local first.
- `switch` can match where an if/else-if chain puts case bodies in the wrong order.
- Float locals can swap registers when declared in a different order; statement order matters too
  (`x = (float)fn(); k = const; v = k - x; out = v + k`).
- Use a private scratch directory (your own folder under the scratchpad); a shared /tmp path was clobbered by another agent.

## Added from GA5 (second pass)
- Copying a parameter to a local (`const unsigned *hash = hashes;`) swaps which nonvolatile register it lands in.
- Float constant into a local first (`float zero = lbl_...; a = zero; b = zero;`) stops reloads after float stores.
- Bool from a relative-array offset: `ok = (unsigned)(r->off + 1) != 0; if (ok == 1) ...` gives
  addi; subic; subfe; clrlwi; cmplwi 1. Pointer as `r->off + (char *)r`.
- In an accumulate loop the order of the if/else arms matters (`if (x != -1) sum += ...; else sum += 1;`).
- `int result = 0; if (arg >= 0) { ...; result = ...; } return result;` gives `mr r11,r3; li r3,0`; extra statements
  between the init and the guard change register allocation.
- If the original always calls the trailing function, call it unconditionally and make only the increment conditional.

## Divides: solved (LT1)
The game project was compiled with /Oc (no divide-by-zero trap). For any game-code function with divw/divwu and no
twllei, check with `--flags /Oc` (works on the plain route) and put "flags": ["/Oc"] in the spec. "Divides without
twllei" is no longer a blocker. Libraries (FMOD, Havok, trio) mostly keep the trap.

## Build flags of the game code (LT1 final)
Game code = /GL + /LTCG, /Oc, and /fp:precise for float code. Read section 7 of docs/ltcg-route.md ("How to match with
the LTCG route") before using it. docs/ltcg-ranges.json says which address ranges are LTCG (0x88150000-0x882A0000 and
0x885F4E48-0x889D3410) and which are plain-route libraries.
- Float `?:` lowered to a +-1 table + mfcr + fsel needs `/fp:precise` under LTCG (partial: still a few instructions off).
- A larger stack frame than the plain compile gives: LTCG with the callee's definition in the link.
- To stop LTCG inlining a context function: prefix the context file with `flags(/Ob1):`. A noinline declaration on the
  caller's side is ignored. `--include NAME` keeps the standard calling convention for a callee.
- Still open: dead `mr` copies, pure register swaps, unrolled loops, v0-v13 vector copies.

## Added from D2 (large gameplay functions)
- `0 == p` (constant on the left) keeps `lwz; addi rX,rX,0; cntlzw`; `p == 0` drops the addi. May relate to clrrwi cases.
- Switch on a hash returning bool: `int result = 0; switch (...) { case ...: result = expr; break; } return result;`.
- Shared float-compare tails: `{ int above = a * b > c; result = above; }`; a (ts4_bool) cast adds clrlwi instead.
- Switch cases equal to the default still need their own `x = 0` statements; two cases needing separate copies of the
  same machine code need different source forms. Case ORDER changes how MSVC associates adds across the whole function:
  a hill climb over case order took one function from 65 to 8 instructions off.
- Owner-field reloads kept below stores: route the stores through an inline helper taking `&self->sub`.
- `srawi; subfc; srwi; adde` is signed `a >= b` with `a` the operand that gets the srawi.

## Added from W2 (small gameplay functions, second pass)
- Per-element call loop: cache the end (`unsigned *end = s->end; for (p = s->begin; p != end; p++) f(s, *p);`) to get
  `savegprlr_29`; `p != s->end` gives a std r30/r31 prologue.
- Counted clear loop with `mtctr` and `beq` on zero: hoist the count, `unsigned n = hdr->count; for (i = 0; i != n; i++)`.
- Bool-or-minus-one mask: `return 0 != call(a, b) ? -1 : 0;` gives `addi; subfic; subfe`. `call() != 0 ? -1 : 0` does not.
- u32 callee result stored in a u64 field: declare the callee as returning `unsigned` and assign directly (`rldicl rX,r3,0,32`).
- Base pointer and zero swapped (target keeps base in r11, zero in r10): store through a local pointer to the first
  element of a consecutive group, `unsigned *q = &s->sub->w[0]; q[0]=0; q[1]=0; q[2]=0;`.
- Search over a self-relative array returning the element address: header `&src->hdr`, element
  `(char*)h + (i*stride + h->rel)`, `r = 0; for (...) { if (e->key == key) { r = e; break; } } out->found = r;`.
- Under LTCG, small wrappers around two calls need the callees in context, with `flags(/Ob1):` on context files whose
  functions must not be inlined.
- Padding macros: use `__COUNTER__`, not `__LINE__`.
- Open, no source form found on either route: `add`/`lwzx`/`lfsx` (index, base) operand order; a 5-word copy kept as an
  `lwzu`/`stwu` `bdnz` loop; `mtctr`+`bdz` switch chains.
- Sources must also pass the host check (`cc -std=c11 -Wall -Wextra -Werror -fsyntax-only`): guard pointer-to-int casts
  and `__forceinline` behind `_MSC_VER` macros that expand to the same tokens under MSVC.

## Operand order of indexed add / lwzx / lfsx (from OP1; full notes in docs/agents/near-misses/OP1.md)
- The (base, offset) vs (offset, base) order of a commutative op does not follow the source expression. It follows the
  function-local symbol number of the local the operand is built from, when that local holds a computed address
  (`h = &t->hdr`, `e = h + i*K + h->rel`). Numbering is by first assignment in statement order, parameters first; only
  referenced locals count. The order flips when the base local is number 7, 15, 23, ... (about period 8).
- Fix: make the base a named local and change how many referenced locals are assigned before it (split pointer chains
  into named locals, or give each repeated access its own block-scoped locals). `python3 tools/operand_order_pad.py SRC
  FUNC name=0xADDR 9` tries 0-9 dead locals and prints the diff count for each, to find the count to aim for.
- Not covered: both operands loaded straight off a parameter, or a strength-reduced induction temp.
- Operand order, refinements (W3): with several sites in one function, pads before one site shift every later site, so
  fix sites left to right. Block-scoped base locals are numbered separately and flip independently (7 and 15 in
  0x8866D070). One `int x = 0;` per pad; a comma-separated declaration inside a macro argument fails to compile.

## `clrrwi rD,rS,0` copies (from CL1; full notes in docs/agents/near-misses/CL1.md)
- The copy is a load that the compiler removed late: the `lwz` is replaced by a zero-extending copy of the register that
  already holds the value. It appears when the early CSE did not see two accesses as the same location:
  1. the second access goes through an inline accessor called again (`static __inline struct S *get(struct S *p)
     { return p; }  get(p)->n--; return get(p)->n < 0;`), or an inline helper that re-reads a pointer field;
  2. a store on two paths, read after the merge (`if (f) p->c++; else p->c = 0; t->x = p->c > 300;`);
  3. another memory access between the store and the reload;
  4. a rotated loop condition re-reading a field the body just stored.
- Inside an inline body only the first load off the parameter becomes the copy, so the level that gets the copy tells
  you which pointer the helper took. The same expression written twice, or a local pointer used twice, gives no copy.
  Float fields give `fmr`. No flag is involved; 64-bit casts, `& 0xffffffff`, `/Oc`, `/fp:precise`, LTCG make no difference.
- Worked examples: src/xbox360/cl1_clrrwi_reload.c. 1,508 unmatched functions in the image contain this pattern.
- clrrwi refinements (W4): pass the expression to the inline helper at each call site (`lempty(in->list)` then
  `lback(in->list)`), not a named local; a local caching the first accessor result turns the copy back into an `lwz`.
  For a decrement or store of an element, use a tiny inline returning the address for the write only
  (`--*counter(self)`, `(*elem(s->o->arr, i))--`) and read the value directly. `while (begin != end) { ...; end--; }`
  gives the copy with no helper. Open: a reload the target keeps as a real `lwz` before the copy (0x886696A8), a
  redundant re-test kept after the copy (0x8866BAE0), and the stack-temporary id round trip
  `addi r10,r1,0x50; stw id,0x50(r1); lwz r5,0(r10)` (0x886A37D0, 0x88669B98).

## Float code: fmadds together with the mfcr/fsel select (from FP1; full notes in docs/agents/near-misses/FP1.md)
- Game float code is compiled in the DEFAULT float model (the one that emits `fmadds`), not `/fp:precise`. Do not use
  `/fp:precise` to get the mfcr select: it gives the wrong orientation (`xori`/GT). All 479 select sites in the LTCG
  game range are LT|UN with no `xori`.
- The `fcmpu; mfcr; rlwinm 27; rlwinm 30; or; lfsx {1.0,-1.0}; fsel` select comes from comparing against a NAMED
  file-scope `static const float kZero = 0.0f;`. A literal 0 gives a bare `fsel`; a variable gives branches. Once the
  named zero exists in a file, every literal `0.0f` in it is redirected to it.
  `float f(float a,float b,float c,float lo){ float v=a*b+c; return (v-lo >= kZero) ? v : lo; }`
- Max written as a helper `(a - b >= kZero) ? a : b` and called as `max(0, x)` gives the target's `fneg` before `fcmpu`.
  Nest the helpers (`min(max(x, base), limit)`); two separate select statements turn the first into a branch.
- LTCG route: the select table and constants are addressed off the module constant pool (0xA70 bytes). Add
  `src/xbox360/pp1_pool_primer.c` as the LAST `context` entry; it reproduces the whole pool layout, so any constant
  lands at its original offset (notes: docs/agents/near-misses/PP1.md; regenerate with tools/ltcg_pool_primer.py).
  `fp1_pool_primer.c` is the older version covering only the first 0x68 bytes.
- Worked examples: src/xbox360/fp1_anim_busy_frames.cpp, src/xbox360/fp1_layer_time_warp.c. 131 unmatched functions
  (179 KB) contain both patterns; 46 of them (50 KB) are in the gameplay range.
- Float refinements (W5):
  - Reciprocal `fres; fnmsubs; fadds; fmuls`: `extern float __fres(float); #pragma intrinsic(__fres)` then
    `inv = __fres(d); inv = ((1.0f - inv*d) + 1.0f) * inv;`. Keep the divisor in a named local (`float d = ratio - 1.0f;`)
    to get the fnmsubs operand order. Plain `1.0f/d` gives `fdivs`.
  - `(unsigned)f` gives `fctidz` + low-word `lwz`; `(float)u` gives `std; fcfid` with no `extsw`.
  - `fabs`: `extern double fabs(double); #pragma intrinsic(fabs)`, with `float d; d = s->v; d = (float)fabs(d);` (through a
    local) for a bare `fabs` with no `frsp`. `fabsf` is a call.
  - Abs written `(x >= kZero) ? x : -x` with a bare compare stays a branch in some contexts; only the
    `(a - b >= kZero) ? a : b` helper shape reliably gives the table select. Open.
  - A zero the target keeps in a saved FPR across calls in a loop comes from `extern const float g_ts4_event_value;`
    plus a local copy; a `static const float` zero is rematerialised from the pool each time. The two do not combine
    with the table select. Open.
  - 64-byte float struct copied with an inline `ldu/stdu` + bdnz loop: make the struct a union with
    `unsigned long long q[8]` and write `T t = *p;`.
  - Bool kept in a register: `int hit = 1; if (c) hit = 0; if ((unsigned char)hit) {...} return hit;`.
  - A callee with an unused parameter must be defined in context with `flags(/Ob1):`, or the extra argument is emitted.
  - Call callees by their current symbols.txt name. An invented `ts4_` name for an unmatched callee passes fn_check with
    a RENAME note but fails the LTCG build ("unapplied renames").

## Vector (VMX128) code (from VX1; full notes in docs/agents/near-misses/VX1.md)
- Include `src/xbox360/vx1_vector.h` instead of `ts4_vector.h` in new vector sources: its `__vector4` is 16-byte
  aligned and `passinreg`, so vector struct copies come out as `ld/ld/std/std` like the game (the old header's type is
  4-byte aligned and gives four `lwz/stw` pairs). It also declares the intrinsics `extern "C"` (needed for .cpp),
  adds `__vcmpeqfpR` and `__stvewx`, and has lane helpers `vx1_set_x/y/z/w`, `vx1_replicate`, `vx1_vec_set_*`.
- Register choice follows the source, not a flag: temporaries go v63 downward, vectors live across a call v127 downward.
  v0-v13 appear only around instructions with no VMX128 form: 3-input `__vmaddfp` and a `__vspltw` feeding it.
- `vor128 vD,vS,vS` copies are late-forwarded loads (the vector form of the clrrwi rule): change a vector member through
  an inline helper taking a pointer to it (`vx1_vec_set_x(&s->vel, x)`). A direct `s->vel = set_x(s->vel, x)` gives none.
- Lane ops are the xnamath bodies: setter `__vrlimi(v, __lvlx(&x, 0), mask, rot)`, splat `__vspltw(__lvlx(&x, 0), 0)`,
  lane read `.v[i]` (stack store + `lfs`), dot-product extract `__stvewx`.
- Loop unroll: `for (i = n - 1; 0 <= i; i--)` (constant on the left) is NOT unrolled and gives `subic.; mtctr; bdnz`;
  `i >= 0` is unrolled 4x.
- The float table select inside a loop needs a fresh local in the helper (`float r = ...; return r;`); `best = c ? f : best`
  gives a branch.
- A constant addressed from another constant (`li r5,0x4d0; lvlx128 v62,rZero,r5`): one file-scope
  `static const struct { float zero; unsigned gap[N]; float half; }`. Two separately used vector constants must be
  `extern` under their symbols.txt names.
- Use the LTCG route with `src/xbox360/pp1_pool_primer.c` as last context and `/Oc`. Worked examples:
  src/xbox360/vx1_scale_velocity_xz.c, vx1_clamp_speed_half_vel.c, vx1_polar_offset_xz.c.
- 2,025 unmatched vector functions (1.5 MB) in the image; 422 (295 KB) in the gameplay range.
- Vector refinements (W6):
  - Load-all-then-store-all copies of a 4x4 matrix: two loops through `__vector4 t[4]` (`t[i]=m[i]` loop, then
    `dst[i]=t[i]` loop). Direct `dst[i]=m[i]` interleaves.
  - Compare-to-bool: `__vcmpgefpR(a, b, &cr); return (cr >> 7) & 1;` (declarations for `__vslw`, `__vsldoi`,
    `__vcmpgefpR`, `__vcmpgtfpR` in src/xbox360/w6a_types.h). 0.5 is `__vcfsx(__vspltisw(1), 1)`.
  - `__vupkd3d(v, imm)`: the disassembly shows imm<<2. 3-input vmaddfp prints as `vD, a, b, addend`.
  - Members written after a vector store need pointer helpers on both sides; scalars as `*p = *p * k` (k on the right).
  - A literal `1.0f` loads at the use; `g_ts4_script_constants[0]` loads earlier.
  - A second `self->field` read kept as a real `lwz`: write the long expression `self->a->b->c` at each use, no local.
  - Vector-member erase (`v->end = copy(...)`) loops: `*dest = *src; ++src; ++dest;` in braces, sub-struct pointer
    assigned right before each use.
  - 16-byte copy from a stack vector as `ld/ld/std/std`: cast through an 8-aligned `unsigned long long q[2]` struct.
  - A vector kept in v1 or v126/v127 across a call needs the real callee in the LTCG context.
  - Open: `li off; lvx rBase,rOff` vs `addi; lvx r0,rT` address form (both directions), VMX32 register numbering in the
    TransformCoord chain (v7/v13 vs v13/v11), `vor128` copy of a constant stored to two members, `vmaddfp128` with the
    addend as destination, bdz/bdnz switch chains.

## Vector address form and matrix helpers (from AF1; full notes in docs/agents/near-misses/AF1.md)
- Address form is fixed when the address is CSE'd: `base+K` used twice or more gives `addi rT,base,K; lvx128 v,r0,rT`;
  used once it gives `li rK,K; lvx128 v,base,rK`, with the `li` register shared by every base using K once. Indexing
  vs pointer arithmetic vs member access makes no difference.
- `li` form for both the loads and the stores of one matrix: pass the matrix BY VALUE to a `__forceinline` helper and
  assign the result row by row (`Af1Mat t = transpose(*m); af1_mat_set(m, &t);`). A plain `*m = f(*m)` struct assignment
  gives an ldu/stdu loop.
- TransformCoord: matrix by value, `r = __vmaddfp(m.r[2], z, m.r[3]); r = __vmaddfp(y, m.r[1], r);
  r = __vmaddfp(x, m.r[0], r);` then the refined reciprocal. Matrix multiply: one nested
  `vmaddfp(vmaddfp(vmaddfp(vmulfp)))` expression per row. Translation matrix: build rows in the order r[3], r[2], r[1], r[0].
- `vmaddfp128 vD,vA,vB` (addend as destination) is a contracted `__vmulfp` + `__vaddfp` on a value stored then reloaded:
  `l = __vmulfp(__vsubfp(b,*a), s); *o = *a; *o = __vaddfp(*o, l);`. There is no vmaddfp128 intrinsic.
- Helpers in src/xbox360/af1_vector.h (`Af1Mat`, `af1_mat_mul`, `af1_mat_set`, `af1_mat_transpose`, `af1_recip`,
  `af1_transform_coord`, `af1_mat_translation`, ...). Worked examples: src/xbox360/af1_mat.c, af1_mat_transpose.c.
- Open: `add; lvx r0` with a strength-reduced offset (0x88645B98, 0x8866C8B8); the `vor128` copy of a constant stored
  to two members (0x8867D8D0 is 6 instructions off on that alone).

## Added from W7 (gameplay re-sweep with all rules)
- Operand-order pads: the pad locals must be used (`(void)x;` at the end) to pass the host check. The flip period is 8
  (3 and 11 in 0x88671350). Pads also fix some pure scheduling differences. A per-call-site fix: a second copy of the
  inline accessor with its own dead locals shifts only that site; pads in the caller shift every site.
- `(char*)h + i*K + h->rel` (index term written before `rel`) gives `mulli; add h; lwz rel; add`.
- Self-relative record counters: `helper(&s->own->hdr, idx)->field++` with the helper returning `h + (i*K + h->rel)`
  reproduces the dead `addi` of the field address.
- Late-forwarded float reload `fmr`: re-read a field just stored (`s->a = 1.0f - s->b - s->c - x`).
- Result in a local returned once (`unsigned char r = 1; ... r = 0; break;`) fixes loop-exit layouts; a `?:` feeding an
  early return can schedule differently from `if`.
- Bool chain kept as branches: `int x = a>=b; int y = ...;` up front, then
  `if ((unsigned char)x && (unsigned char)y) return 1; return 0;`.
- Storing in both branches (`if (c) p->f = K1; else p->f = K2;`) instead of a local stored at the end removes a
  register shuffle.
- `(float)unsigned` drops `extsw`; `do {} while (--n != 0)` gives `subic.`.
- Float args take GPR slots: `(this, int, float a, const float *p, float b)` puts the pointer in r6.
- LTCG callee register survival: add the real matched callee's source as plain `--context` (no `/Ob1` prefix) with
  `--include <callee>`; a varargs caller of `ts4_format_text` needs `src/xbox360/cw1_ctx_format_text.c` as context.
- Whole-struct assignment of an 8-byte element gives `ld/std`; per-word copies give `lwz/stw` pairs.
- Open: dead `addi` of a sub-object address in constructors; a parameter spill ordered before the first load;
  five register copies of one constant (0x8866EB80); callers needing an unmatched callee in context.
