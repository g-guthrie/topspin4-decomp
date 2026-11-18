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
- Struct copy chains `a = b; c = a;` emitted as `lwz; stw; lwz; clrrwi; stw; <reload base>; stw copy; lwz a.2nd; stw`
  (0x8866F740): use an inline word-copy helper `copy(dst, src) { *(u32*)&dst->x = *(u32*)&src->x; *(u32*)&dst->y = ...; }`
  called twice, `copy(&m->a, &m->b); copy(&self->pc->state->c, &m->a);`. dst/src may alias, which keeps the source
  order and the reload of the second word; float fields must be copied as words or you get lfs/stfs.
- A field load the target repeats after an inlined helper already read it (e.g. `pc->match` in a later block, 0x8866F740):
  write the later read through the owner, `self->pc->match`, not via the cached `pc`; it is CSE'd back to the same base
  register, but the field load itself is no longer merged with the inline's load.
- Row walks over a self-relative array (0x886AFDF8, 3 off): iterate the row pointer, not a pointer to a
  member; MSVC makes the `row+4` induction variable itself. A top test plus a bottom `beq` back on the
  stop flag is `do { if (row == end) break; ...; row++; } while (!found);`. A member pointer that the target
  keeps (`addi rX,st,0x358`) alongside absolute-offset stores off `st`: take `sel = &self->pc->state->sel` and
  derive `st` from `sel` by subtraction, then write the first field through `sel`.
- A hoisted float constant addressed directly (`lis; lfs f31,-0x46f0`), outside g_ts4_script_constants: write
  it as a literal (`x > 0.5f`) and run LTCG WITHOUT pp1_pool_primer.c, or it lands deep in the primed pool and
  needs an `addi`. An extern const local gives the wrong schedule; an extern read in the loop is not hoisted
  (0x886AFDF8 matched this way, spec work/specs/ME/me_ts4_swing_category_walk_886AFDF8.json).
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

  - XMVector3NotEqual materialised as `mfocrf; extrwi 1,24; cmplwi 1; beq` (0x889C1C80): an inline `Equal` returning
    ts4_bool `(cr & 0x80) == 0x80`, tested `eq(...) != 1`. Returning int (or NotEqual directly) gives a CR branch or `nor`.
  - A sub-struct pointer kept as `addi r31,base,0x9B0` (0x8869B928): accessor helpers, `__restrict`, pointer casts and an
    LTCG-inlined extern getter all fold it into the field offsets; only a `volatile` copy of the pointer keeps it
    (161 -> 100 off, but adds a stack store). Open.

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
- More from W7: container teardown `v->last = copy(v->last, v->last, v->first)` with a copy helper calling
  `fn_88562DC0` that returns `dest` when first==last, else `dest + n` (worked examples src/xbox360/w7b_b.c, w7b_c.c);
  element loops read `end` once into a local. `return 0 != r;` gives the `addi rX,r3,0` copy before `subic/subfe`.
  Under LTCG, declaration order of two constant-holding locals decides which constant gets which `lis/lfs` slot.
  A callee that returns its `this` is used as `o = callee(o, o)` to get `mr r4,r3` and the later r3 reuse.

## Added from W8 (132-224 byte gameplay functions)
- A store that must precede a later load: `{ u32 *sp = &p->steps; *sp = *sp + 1; }`, not `p->steps++`.
- Nested counted loops keep the target's shape: `for i<4 { for k<5 {...} }` gives `mtctr 4` with a 5-way unrolled body;
  a flat 20-iteration loop does not.
- Lane extraction without a `vor128` copy: `float t[4]; __stvewx(__vspltw(*rp, k), &t[k], 0)` with every splat taken
  from `*rp` (no named vector local).
- Float bool chain: `int a = x < lim; ... if ((u8)b==1 && (u8)c==1 && (u8)a==1) call();`. Result bool in r3 via r11:
  `int x = cmp; u8 r = (u8)x;`.
- 64-bit elapsed time: `u64 start = (unsigned)get();` gives `rldicl`; write the wrap as
  `if (now < start) d = now - start + 0xffffffffu; else d = now - start;`.
- A float first parameter takes r3's slot (integer parameters start at r4); find a parameter's position from its home
  slot offset (1st = 0x14(r1), 5th = 0x34(r1)).
- Zero stored on one branch only: `float z = g_ts4_event_value;` as the first statement of that branch.
- Address-taken stack id round trip (`addi r10,r1,0x50; stw; lwz r5,0(r10)`): `struct Id *pid = &id; f(..., *pid)`.
- LTCG callee register survival: `--context "flags(/Ob1):<callee file>"`, sometimes also `--include <callee>`; when the
  real callee has an unused float parameter, pass a dummy `0.0f`.
- Open: the table select together with a zero from extern `g_ts4_event_value` (0x886C4970, 0x886C5770, 0x886C6EE8);
  a 23-entry jump table the compiler folds to compares (0x8865DAC0); r10/r11 register swaps; dead sub-object `addi`.
- More from W8: the fmadds multiplicand order follows the declaration order of the float locals. `unsigned char sign =
  h >> 15` keeps `srwi 15; nor; clrlwi 31` where `~(h >> 15) & 1` folds to `nor; extrwi`. Read `end` into a local before
  a `begin` loop for the end-first load order. Callee float-register survival (f10) also works with
  `--context "flags(/Ob1):<callee file>" --include <callee>`. A function-local static table with an inline constructor
  matches in C++ but fn_check rejects the compiler-generated `?$S1` symbols (0x886C40B8): open.

## Dead sub-object `addi` in constructors, destructors and setters (from DA1; notes in docs/agents/near-misses/DA1.md)
- The dead `addi rX,rObj,K` is the address of a member sub-object passed to an inline helper: write the member's
  ctor/dtor as `static __inline void sub_init(struct Sub *s)` and call it as `sub_init(&o->sub)`. The address is kept
  in a register only when the helper uses its pointer for two or more things and at least one is not a plain load or
  store: (1) it derives another address (`&s->m` to a deeper helper, an array member passed as an argument),
  (2) the same field is loaded then stored (`v->e = v->e + 1`, or `f(v->e); v->e = 0`), or (3) the same field is
  loaded twice with a possibly aliasing store between. Loads and stores are re-based onto the parent afterwards, which
  leaves the `addi` dead. One use, or stores only, gives no `addi`.
- A chained `addi rY,rX,K2` is a sub-object nested in another. If the parent pointer is dead, the sub-object address
  becomes the saved base (`addi r31,r3,0x14`). Two separate inline calls `init(&o->m); reset(&o->m);` keep the redundant
  stores and the `mr` copy of the constant.
- Member structure fixes store order too: nine zero words written as three `{begin,end,cap}` vector inits put the
  vtable store first (0x886D32A0).
- C++ member-initialiser constructors, placement new and `this`-adjusting member functions all fold (no `addi`); use
  the C inline-helper form.
- The common 0x44-byte object with vtable `lbl_880D7600` is `{vt; w04..w10; {vec,vec,vec} at +0x14; vec at +0x38}`;
  its ctor/dtor and embedding constructors are in src/xbox360/da1_a.c (worked examples).
- Still open: the table select with the zero from extern `g_ts4_event_value` (a one-arm operand is sunk into the branch);
  r10/r11 swaps between a base pointer and a loaded value.

## Added from W9 (228-328 byte gameplay functions)
- Two matched functions in one file where one calls the other: mark the callee `__declspec(noinline)` (under
  `#ifdef _MSC_VER`) from the start. fn_check passes while the call still uses the fn_ placeholder; after integration the
  call resolves to the same-file definition and gets inlined, and the build then reports "not a perfect match".
- Per-site operand-order pads: block-scoped base local in each branch plus N dead top-level locals flips only the later
  site (0x886CC560 needed exactly 2).
- Element helper with explicit stride, `(E*)((char*)h + (i*0x18 + h->rel))`, called with constants 0 then 1, gives the
  two separate `add` copies and the dead `mr`.
- Two stack temporaries swapped between helper calls: ONE `struct {u32 a,b,c,d;} tmp[2]`, using `&tmp[0]`/`&tmp[1]`.
- 12-byte handle read from a struct and passed on: `Id id = p->id; f(id.c, id, key);`.
- Index search with a slow path: `r = 4; if (...) { i = 4; if (vc) {scan} if (i >= 4) r = call(); else r = i; } return r;`.
- Conditional negate through a float local: `t = out[0]; if (c) t = -t; out[0] = t;`.
- Buffered writer with a shared direct-write tail:
  `if ((long)buf != 0) { if (fill + n > cap) { flush; fill = 0; if (n > cap) direct; else copy; } else copy; } else direct;`.
- `(t < 20)` stored as a byte gives `subfc; eqv; srwi 31; addze; clrlwi 31`.
- Open at this size: vtable store scheduled first in constructors with many zero stores; a failure block placed before
  the success block; `one`/`zero` kept as saved-register locals; loads the scheduler hoists above a store.
- More from W9: unfused float code (separate `fmuls` then `fadds`) is `#pragma fp_contract(off)` in the default float
  model. A copy loop written `for (; 0 < n; --n) { *d = *s; ++d; ++s; }` gives the dead `subf.; ble; mtctr` inline loop.
  `__stvewx(vec, base, 4)` with a constant offset gives `li r9,4; stvewx v,r10,r9`. In `af1_mat_mul`, the multiplier by
  value and the other matrix through a pointer gives `addi/lvx r0`; both by value gives `li/lvx base,rK`. A constructor
  embedding three of the 0x44-byte objects: src/xbox360/w9a_a.c.

## Operand order, second pass (from NM1/NM2; notes in docs/agents/near-misses/NM1.md and NM2.md)
- Base pointer loaded from a struct, index a loaded local: a NAMED local for the base (`list = self->sides;
  list->side[idx]`) gives (index, base); writing the base load at the use (`self->sides->side[idx]`) gives (base, index).
  This is separate from the period-8 numbering effect.
- If aliasing forces the base load ahead of a store, `__restrict` on the aliasing pointer keeps that schedule with the
  base written at the use (`int *__restrict count; i = *count; *count = i + 1; s->keys[i] = key;`).
- The period-8 numbering rule also reaches a parameter + field load and a strength-reduced index, once the loaded
  operand goes through a computed-address local: `u32 *t = &s->total; *t = *t + n;` (flips when `t` is local 7);
  vector begin/end in a sub-struct read through `v = &s->vec`.
- A block-scoped copy of a loaded base counts for numbering (`{ Hdr *hb = o->b4c; ... (char*)hb + i*K + hb->rel }`).
  With two sites, fix left to right; the second site takes its dead locals in its own block.
- Refuted, do not retry: a site where load and store through the same base need OPPOSITE orders (0x886D9AB8; they
  always flip together); 0x886CE120, 0x886E3938, 0x88656538 (no pad count or loop/index form flips them).
- Adjacent-instruction swaps (a `lis`/`li` vs a load, a parameter spill vs a load, `mr r4,r3` vs `mr r31,r3`) and the
  f9/f10/f11 float numbering: no rule found; the forms tried are listed in NM1.md and NM2.md.

## Added from the mid-size pilot (PL1, 330-700 byte functions)
- A dead `mr r7,r5` before a call: the callee takes that incoming argument as an extra pass-through parameter.
- `(double)` of an unsigned 64-bit value is a call to `__u64tod` (0x8856B2C0); `(long long)f` gives a bare `fctidz`.
- Record-vector clear: an inline `destroy(first, last)` called with the parent's fields, then an inline `clear(&vec)`
  doing `erase(v, v->first, v->last)`; an all-in-one helper swaps two saved registers.
- Self-relative array loop with `(rel+h)+off` add order: byte-offset counter `for (i = 0; i < 0x70; i += 0x1c)` with `h`
  block-scoped inside the loop.
- min as `(n >= *p) ? *p : n` gives `mr rX,p; bge; mr rX,n`.
- A vector difference whose lanes are read after a call: pass it by pointer to the lane-reading helper.
- Measured: 3 of 12 random functions of this size matched at 6-16 hand compiles each; 3 more ended 2-7 instructions off
  on classes with no rule (adjacent swaps, two-register swaps, load/store order); the rest on block layout, global
  scheduling, multi-site operand order and vector code.

## Store scheduling, constructors and block layout (from SC1; notes and probe tables in docs/agents/near-misses/SC1.md)
- The scheduler only reorders memory accesses that go through the SAME pointer value (same parameter or local, different
  constant offsets). Accesses through different pointer values keep source order in both directions: an inline helper's
  pointer parameter used two or more times, a local `p = &o->m`, a second parameter. A helper pointer used once folds
  onto `o` and counts as `o`. Store types, `__restrict`, `/Oa`, `/Ow` and C++ inline member ctors change nothing.
  `ainit(&o->a); o->w[0] = x;` emits `stw x` last; the same stores written directly through `o` emit it first.
- Among stores free to move: a store of a `lis/addi` address (the vtable) or of a loaded value is emitted as soon as its
  value is ready, so it comes out near the top even when written last; stores whose values are ready together keep
  source order; when stores are free every `lis` is hoisted to the top, when chained a later group's `lis` is
  materialised just before that group.
- To apply: if the target materialises a constant late, puts the vtable store first, or keeps a run of stores in strict
  source order, split the members into sub-objects, each with its own `static __inline` init called on `&o->member`,
  and sweep the grouping (0x88695E78 matched only with header words grouped {2,2,1} or {2,1,2}).
- Destructors: `free(&s->p)` (with `*pp` inside the helper) keeps `stw vt; lwz p`; `free(s->p)` hoists the load above the
  vtable store.
- LTCG: loads through `extern const` objects are held behind the stores; a literal `1.0f` is pool entry 0 and its load
  floats freely. An early global read is sunk to its use unless it is a volatile read.
- Block layout: a failure block placed right after the first test and reached from the second test by a backward branch
  is an inline helper returned from at both sites (`static __inline int fail(S*){...; return 0;}`,
  `if (..) return fail(s);` twice); the copies are tail-merged at the first site. Not universal (0x886D16F8).
- Worked examples: src/xbox360/sc1_a.c, sc1_ltcg_a.c. Open: a call-argument `addi`/`mr` one slot early or late
  (0x8864C170, 0x886D48F8); float stores interleaved with a sub-object's stores (0x886A3AC8).
- Scheduling, extensions (SC2; notes in docs/agents/near-misses/SC2.md):
  - A block-local pointer to ONE member, used once (`{ u32 *p = &h->f10; *p = K; }`), keeps that store in source order
    relative to accesses through `h`, with no `addi` emitted. (Corrects SC1: only an inline helper's single-use pointer
    folds onto the parent.) It does not work for a vtable store.
  - Under LTCG a global whose address is never taken in the file does not alias pointer accesses, so its loads and
    stores move freely; on the plain route they stay ordered. If a global access keeps its place among the stores in an
    LTCG target, take its address somewhere in the file (`void **head = &g; cur = *head; ... *head = s;`). A function
    whose global store must stay ordered may match on the plain route only.
  - Constructor called as `n ? obj_ctor(n) : 0` after an alloc fixes the `mr`/vtable order.
  - Refuted: changing the type of an address-taken stack local does not change its ordering against stores through a
    parameter (0x886CDED0, 0x88640810).

## Register assignment (from RA1; probe tables in docs/agents/near-misses/RA1.md). Partial rules, not a full formula.
- Saved registers go r31 downward: parameters in parameter order, then locals in order of FIRST ASSIGNMENT. Declaration
  order and dead-local pads change nothing. A local first assigned inside a guarded block ranks lowest
  (`if (G) { g = G; ... }` gives r28; `g = G; if (g)` gives r31).
- A value is raised above that order by being an `add`/`addi`/`mulli` operand, by being stored to a global, or by use in
  a conditional arm or a loop. Call arguments, load/store bases, compares, logical ops, shifts, mullw/divw and stores
  through a pointer do not count, however often repeated. For parameters `a + b` gives b=r31, a=r30.
- A constant is kept in a saved register only when two or more stores of it fall on both sides of a call. An int
  argument always gets a fresh `li`. So `mr rArg,rZero` means a 4-byte struct passed by value, a phi copy, or the
  `li 1`/`li 0` of an `a && b` bool, never an int literal. A user local holding 0/1 is constant-propagated: write the
  literal stores.
- `if (n) c = f(n); else c = 0;` and `c = 0; if (n) ...` weight the held zero differently; an explicit `else b = 0;`
  gives duplicated `stw; mr r3,rZero; bl` tails.
- Reading through a pointer-to-member local (`a = *slot`) puts its `addi` before the load and gives it the higher
  register; `a = s->m` the reverse.
- An early `stw rX,0x50(r1)` with the value still in a register is an address-taken COPY (`val = o; f(&val)`); taking
  `&o` itself sends `o` to memory.
- Volatile temporaries are handed out round-robin r11, r10, ..., r3, then wrap; a freed register is not reused before
  the wrap. Order among temporaries defined together follows the reassociated expression tree (`x*y` evaluates y first;
  `(x-y)-z` becomes `(x-z)-y`), not statement or declaration order.
- Distant code matters: rewriting a later loop can move a top-of-function assignment.
- Open: a chained load reusing its own register (`lwz r11,0x74(r11)`, 0x8866D218); found/count weight swap (0x88650908).

## Added from the second mid-size pilot (PL2)
- Two stores through the same pointer whose values are ready together can come out in REVERSE source order
  (`e->w8 = 0; e->wc = 0;` emitted wc first): if a pair is swapped, swap the source statements.
- Branch-free signed max keeping literal zeros in registers (`li 0; subfc; srwi; srwi; subfe; and`): inline
  `max(a,b){ return a<b ? b : a; }` called as `max(0, x)`. `max(x, 0)` and `x<0?0:x` fold the zero.
- Element at index `1-i` with the stride folded into field offsets: `arr(h) - i` then `[1].field`.
- A separate reload of `d` (not merged with an earlier read) comes from writing stores as direct expressions
  (`s->w->d->f = ...`); a local or helper parameter gets merged.
- `#pragma fp_contract(off)` also stops vector `vmulfp` + `vaddfp` fusing into `vmaddfp`.
- Bool defaulted before the branch (`u8 c = side == 0; if (side == 1) {...; c = ...;}`) hoists the `cntlzw`.
- Measured: 1 of 12 random 330-700 byte functions matched (PL1: 3 of 12); five more ended 2-10 instructions off. Top
  residues: register numbering (GPR rank, VMX temps, FPR) 5, adjacent swaps 2, unmatched callee needed in context 2,
  strength-reduction base choice 1. No vector function matched.

## Added from W10 (132-224 byte gameplay functions, full rule set)
- Integer-only functions in the LTCG range can need the LTCG route: try it when a plain draft is 3-4 instructions off
  on scheduling (0x886412C0, 0x88677870 match on LTCG only).
- Before writing a callee as "context", check it is not already matched (`grep -l "0xADDR" src/xbox360/*.c*`); use the
  existing matched source as `flags(/Ob1):` context with `--include <callee>`.
- A function that recomputes `a+b` after a call where the default model would reuse it: `--flags /Oc /fp:strict` on the
  LTCG route (0x8867EB98). This is the one case seen where a non-default float mode was needed.
- Saturating counters: each branch stores its own value (`if (0xffffffffu - v >= 1) *e = v+1; else *e = 0xffffffffu;`);
  the `?:` form differs. The 16-bit case needs `int v` and no `unsigned short` cast.
- Float 3-vector select with odd load/store orders: float locals, loads in one declared order, stores in another;
  brute-force the 36 combinations (0x8866DC98: loads x,y,z, stores y,x,z).
- Vector select through a `switch`: one local `__vector4 r = default; ... r = ...; *out = r;`, the selector read
  directly in both switches; the case order sets the bdz/bdnz chain.
- Placement-new style pool bump: `b = p.cursor; p.cursor = b + n; p.remaining -= n;` in this order; temp register
  numbers follow source definition order.
- Byte offset shared by several arrays (`int o = i*32; (char*)base + o`) gives (base,index) adds.
- Saved-register zero result: `res = 0`, assign in the success branch, `return res` once.
- Rotated loop keeping top test and bottom `beq`: `while (i < 600) { ...; if (!settled) continue; break; }`.
- `for (; end != begin; ...)` compare operand order decides `cmplw end,cur`.

## Added from W11 (re-sweep of small gameplay functions with the full rule set)
- `vor128` copy of a vector stored to two members: write the copy explicitly, `__vector4 w = __vor(v, v);
  p->a.v = v; p->b.v = w;` (closes the open item; 0x8867D8D0).
- Three lane stores `stvewx v,r0,rT / v,rT,4 / v,rT,8`: `__stvewx(__vspltw(v,k), t, 0/4/8)` on the array base, not `&t[k]`.
- Counted store loop kept as `mtctr`/`stwu`: `for (i = 7; 0 < i; --i) { q->b = 0; ++q; }`; `i < 7` counting up is unrolled.
- `idx = (a < b) ? b : a;` gives `mr rX,b; cmpw; blt; mr rX,a`; the `if` form coalesces into r3.
- Result copy `mr r11,r3` after a call: `int ok; if (v != 0) { ok = 1; *out = v; } else ok = 0; return ok;`.
- Fresh `r = 0` in an else branch (not up front) keeps a callee result register alive across a branch.
- 16-byte vector through a stack temp as `ld/ld/std/std`: one `__vector4` local per element, cast both sides through
  `struct { unsigned long long q[2]; }`; an inline helper around the pair does not match.
- `__vcmpgefpR` bool as `mfocrf; extrwi; cmplwi; beqlr`: `unsigned ok = (cr>>7)&1; if ((unsigned char)ok == 0) return;`.
- Bytewise colour copy with an uninitialised 4th byte: struct `{Rgb rgb; u8 a;}` copied member by member.
- A named local `Vec *vec = &self->vec;` assigned first puts `this` in r28 and `&vec` in r29 in a loop that later
  passes it to a call. Loading vector lanes into locals in x, z, y order sets the load order.
- LTCG register survival needs the WHOLE callee chain in context; a matched callee that itself calls an unmatched
  function does not provide it. Under LTCG the frame already includes varargs home space (do not add padding locals).
- Still open after this pass: `li r3,1; cmpwi; beqlr; li r3,0` (0x886C3DA8); the 23-entry jump table (0x8865DAC0);
  five `mr` copies of one constant (0x8866EB80); float `fadds` operand order in three functions; a 0xa0 frame around a
  pass-through call (0x886C8C48, 0x886C90F0).

## 64-bit return type keeps a 0/1 result as a branch
- `li r3,1; cmpwi; beqlr; li r3,0; blr` (and similar branchy 0/1 results that every 32-bit form folds to
  `cntlzw`/`subfe` arithmetic) comes from a function whose RETURN TYPE is 64-bit: `__int64 f(...) { if (c) return 1;
  return 0; }`. Closes 0x886C3DA8 (src/xbox360/me_status_is_one_886C3DA8.c).
- Hoisted `li r3,0` before the first test with a separate `li r3,0` block for the second:
  `res = 0; if (g) res = n ? call(&g->x, n) : 0; return res;` (0x886C5130).
- A bool helper returning `unsigned char` (`return v == MAX || v < 0;`) used as `if (bad(v)) return 0;`, followed by
  `int r; if (...) r = 0; else r = 1; return (unsigned char)r;` gives the direct `li r3,0; blr` exit plus the shared
  `li r11,x; clrlwi r3` exits (0x8866EFA0).
- Haiku agents: reliable on copies of an already matched function (twin lists), 0 for ~60 on the hard small residue
  even with per-function packets (work/army/HP/). Use them for copy jobs only.

## Float literals on the plain route (checker fixed at b88)

`tools/fn_check.py` used to reject any candidate whose float literal (`__real@XXXXXXXX`) faced a labelled constant in
the target, which pushed every float function to the LTCG route. It now accepts the literal when the target label holds
the same bytes. Rule of thumb: when the target loads its constants through **separate `lis` bases** (constants in
different sections, e.g. the shared zero at 0x8814B440 in BINKCONS and a literal in .rdata), the function is a plain-route
function: write `0.0f` as a literal, not as `g_ts4_event_value` (an extern reloads or changes registers), and use the
`lbl_` extern only for constants whose label has no size in symbols.txt. Worked example: `me_reset_floats_886468B8.c`
(also shows that a `set(&v, 0.0f, 10.0f, 0.0f)` inline vector setter makes the second constant load one store early).

## C++ forms that C cannot reproduce (found at b89)

- **Small class returned by value** (`me_lookup_hash_8866DF18.cpp`): the target loads a field of an argument, then
  stores a default constant through the hidden return pointer in r3, then tests. Write the return type as a class with a
  constructor that sets the default (`struct Hash { unsigned v; Hash() : v(0xca68aaecu) {} };`), declare the local
  after the first load, assign `h.v` on the taken path and `return h`. A C function with an `out` pointer hoists the
  constant above the load (2 off) whatever the statement order.
- **Virtual calls** (`me_find_and_notify_88658968.cpp`): when the target loads the method pointer BEFORE setting up the
  arguments (`lwz r7,0(r31); lwz r6,0x3c(r7); addi r4,..; mr r3,r31; mtctr r6`), declare real classes with `virtual`
  members (pad the vtable with dummy virtuals) and call `m->method(&t)`. A C struct of function pointers sets the
  arguments first. A method returning a struct takes the hidden pointer in r3 and `this` in r4.
- Stack locals: the frame size tells the size of locals the code never touches; pad the local structs until the frame
  and the slot offsets agree (text object 12 bytes, handle 8 bytes in that example).
- Float arguments consume GPR slots: `f(obj, float, float, out)` passes `out` in r6.
- Functions no agent has tried go fast by hand (5 of 9 tried at b89 matched in one to three runs); the long-open
  near misses are almost all instruction-scheduling cases and do not.

## Open near misses from the hand pass (b90), drafts in work/army/ME/near/ (not committed)

- 0x889C2940 (2 off): two byte stores after the call come out in the other order whatever the statement order or types.
- 0x886C4D10 (3 off): target keeps `child + 8` in a saved register before the first call; ours recomputes it after.
- 0x889C29E8 (11 off, order only): bisection loop; the stack vector load sits one slot late in the target.
- 0x886707C8 (12 off, registers only): three keys copied to a stack array and two of them also kept in saved registers.
- 0x889C0C70 (25 off, registers only): switch on the ball mode hash; structure exact with a `bool` helper for the test.
- 0x886AD1F0, 0x886C5DB0, 0x8866CFA8: store placed before a compare/call in the target, after it in ours.
- Float multiply operand order (`fmuls`/`fmadds` with the two factors swapped): dead-local pads and declaration order do
  nothing here. Write the factors as inline sub-expressions (macros such as `#define DX (b.v[0] - a.v[0])`) instead of
  named float locals; `me_segment_intersect_xz_88670178.c` went from 4 off to a match that way.

### Near misses parked at b92 (drafts in work/army/ME/near on the cloud session)

- 0x886C8678 (10 off): two 16-byte struct copies; target computes `out + 0x10` into an unused register and stores the second copy high half first.
- 0x886C6AE0 (37 off): keyframe sampler; target keeps `frac` in the conversion stack slot and adds the base index before shifting.
- 0x886E2348 (plain): everything matches except the target keeps `layer + 0x30` in a saved register before adding 0x58.
- 0x886A0A48 (14 off), 0x88640810 (7 off), 0x8867B260 (22 off): store or load scheduling only; structure is right.
- LTCG tip confirmed: when a caller keeps values in r6/r7 across a call, add the callee's source file as `--context` (0x886C7B60 matched this way).
- 0x88692720 (17 off): point-to-line distance; everything matches except `vor128` + `vmaddfp128` (addend as destination).
  With locals the `__vmulfp` + `__vaddfp` pair fuses into plain `vmaddfp` on v0/v13/v12. The form
  `static __inline void addscaled(Vx1Vec *o, const Vx1Vec *a, __vector4 dv, const float *k)` (store `a` then add) makes
  cl.exe crash under wibo (segfault, no message), so "compile failed" with no error text means a compiler crash.
  The same missing piece blocks 0x886C6AE0.

### vmaddfp128 on a local, and clamp register order (found at b93)

- `vor128` + `vmaddfp128` with a local result (0x88692720): the result is built in place in a stack copy that is real
  memory, here the 16-byte struct copy of the direction (`d = g->d`, copied with ld/std), through a pointer:
  `{ Vx1Vec *o = &d; l = __vmulfp(o->v, splat); o->v = g->a.v; o->v = __vaddfp(o->v, l); o->v = __vsubfp(o->v, q.v); ... }`.
  A separate local for the result always fuses to plain `vmaddfp` on v0/v13/v12, whatever the expression shape.
- With a real out pointer the same shape is `af1_vec_lerp_to` (`*o = *a; *o = __vaddfp(*o, l)`).
- A float converted to a splat keeps its own stack slot (`lfs; stfs; lvlx`) when the float comes from an inline that
  returns `t.v.v[0]` and the splat takes its address: `k = dot3(...); __vspltw(__lvlx(&k, 0), 0)`.
- Clamp register order: `i0 = imin(i0, last); i1 = imin(i0 + 1, last);` with `static __inline int imin(int a, int b)
  { return a < b ? a : b; }` keeps `last` in the register the count was loaded into; `if (i0 >= last) i0 = last;` moves it.
- Statement order rarely matters: 504 valid orderings of the sampler body gave only three distinct outputs.
- Near-miss drafts are now committed under src/xbox360/drafts/me_*_nearmiss.*.
- Separate loop iterator (`mr rP, rB; cmplw rB, rE; beqlr` then a do-while on rP, constants loaded after the guard):
  a fill helper that takes the value by value and copies it after its own guard (0x8867B260):
  `static __inline void fill(Rec *b, Rec *e, __vector4 v, float f){ if (b != e) { __vector4 z = v; do { b->f10 = f;
  b->v = z; b++; } while (b != e); } }`. A plain `for` in the caller merges the iterator with `b`.
- A sub-object pointer stays in its own saved register (`addi r28, r31, 0x30` ... `addi r3, r28, 0x58`) when it has
  several uses in the source, even though its member loads are emitted against the outer base (`lfs 0x44(r31)`).
  Read the other fields through the sub-object pointer too: `q = &l->sub; call(&q->f58, q->f18, ..., q->f14)` (0x886E2348).

## Found at b95

- **Float zero hoisted out of a loop**: a `0.0f` *literal* passed to an inline `make(x, y, z, 0.0f)` is loaded and
  stored once in the loop pre-header (after the `n == 0` guard); the `g_ts4_event_value` extern reloads every iteration,
  and a local copy of it is stored before the guard (`me_copy_record_positions_88645AD8.c`).
- **Lane getters**: `static __inline float plx(const __vector4 *v) { float f; __stvewx(__vspltw(*v, 0), &f, 0); return f; }`
  taking a pointer gives `add; addi; lvx 0,rX` plus one load; pass the calls directly as arguments of the inline
  constructor to get the target's stack slot order.
- **Pointer chain reloaded for a call argument** (`lwz r4,0x1c(r31)` again after it was read before the branch): do not
  keep the pointer in a local; spell `s->f1c->...` each time (`me_store_heading_to_target_88679518.c`).
- **Dead `addi rX, rBase, off` pairs in a constructor**: two levels of inline helper, the inner one taking the array
  through a cast pointer (`arr_init(int *b) { Quad *q = (Quad *)b; quad_init(&q[0]); ... }`); one level leaves one
  dead `addi`, a plain run of stores leaves none (`me_ctor_two_tables_8869D000.c`).
- **Bool then restores after a call**: `if (cond) c = 1; else c = 0; o->a = saved; o->flag = c; ...` puts the compare
  ahead of the restoring stores; the `?:` form puts it after (0x889C2940, 4 off to 2).
- Inline vector args written in the call (`fn(o, &r, make(...), make(...))`) matched where named locals did not
  (`me_edge_point_at_x_8867C4E8.c`); if/else on a float local matched where `?:` on an array slot did not
  (`me_refresh_timing_pair_886D8928.c`).
- 0x886A0A48 (14 off) and 0x886925A8 (7 off) are invariant to statement order, helper shape, types, flags and route
  (about 150 and 30 variants): scheduling of independent stores and VMX128 register numbering respectively.

## Found at b97

- **Relative-offset arrays whose offset is re-read at every use.** Some `{int offset; u32 count}` tables
  (the ones embedded in the big data blocks, e.g. `+0x50` with 0x8c-byte entries, `+0x5b0`, `+0x824`,
  `+0x170`) reload `offset` for `begin`, again for `end`, and again inside loops. Declare that field
  `volatile int offset` and read it once per helper into a local (`int off = t->offset; if (off != -1)
  r = (T *)((char *)t + (t->count * SIZE + off));`). Tables reached through a plain parameter usually
  share one load: leave those non-volatile. Matched 0x886CA530, 0x886AC928, 0x88668EE8, 0x886C84F0.
- `begin`/`end` helpers are `T *r = 0; if (off != -1) r = ...; return r;` (if-form, not `?:`), and need
  `__forceinline` once a function uses them three or more times, or the third use becomes a call.
- A result written through the first argument before the loop, with later loads hoisted above that
  store, needs `T *__restrict out` (0x886C84F0).
- A 12-byte struct passed by value arrives as r4 (first 8 bytes) plus the high half of r5; the callee
  spills r5 with `std` and reloads the word (`rldicr r5,rN,32,31` when passing it on). Declare the
  parameter as `struct { int a, b, c; }` by value (0x886DCDC0).
- Callee-saved register order follows weighted use counts: `if (best == -1) best = r; else if (r < best)
  best = r;` weights `best` above the object pointer where `best == -1 || r < best` does not (0x886AC928).
- Two branches that zero the same three fields in different source order can be emitted in one shared
  order; when one branch's order looks rotated, write both branches identically (0x88668EE8).
- Callees that do not touch r3 can be chained (`c(b(a(o)))`) when the target never reloads the object
  between the calls.

## Found at b98
- A search loop compiled as `srawi. rN,rN,4; mtctr; lwzu x4; bdnz` followed by `cmpwi 1/2/3` remainder tests is
  source-level unrolled `find` (random-access form): `for (trip = (last - first) >> 2; trip > 0; --trip) { 4x
  if (*first == v) return first; ++first; }` then `switch (last - first) { case 3: ... case 2: ... case 1: ... ++first;
  default: return last; }` (falls through). A plain loop is never unrolled into this shape. Example draft
  src/xbox360/drafts/me_8864AE08_nearmiss.c; 12 unmatched functions use it (e.g. 0x8864A3B0, 0x8864A5E8, 0x886E1850).
- Load order `last` before `first` around an inline find: pass `o->vec.first, o->vec.last` through the owner, not
  through a `Vec *v = &o->vec` local (0x8864AE08 matched this way).
- Vector `erase(v, p)` whose copy re-reads `v->last` after an inline find (no CSE): read the field through a
  volatile-qualified view only inside erase, e.g. `copy(p + 1, ((VVec *)v)->last, p); --v->last;`.
- A virtual call `o->vt->fn(o, x)` normally loads the vtable before the argument; the target order (argument first)
  was not reproduced (0x88677190).
- Strength-reduced loop pointer follows the most-referenced field: reading `e->hash` in every `if` of an else-if
  chain (instead of caching it) counts as several references and picks the target's base (0x886964C0).
- Loop-invariant `extern float` stored in a loop but loaded once: declare the loop pointer `T *__restrict p`; a
  `float z = g;` before the loop hoists the load above the empty check instead (0x886799D0).
- Dead `mr` copy of a self-relative offset: a non-volatile offset read by two separate inline `at(t, i)` calls with
  no store between (CSE leaves the copy); write `at(&c->score->sides, i)` at each use, not a cached local
  (0x886688F0, 0x8866A7C0, 0x8866B460, 0x8866ADC0 - placement still off in some).
- Index stride `i * sizeof(T)` (unsigned) instead of `i * 0x40` flipped one site's add operand order (0x88668310).
- `#pragma fp_contract(off)` splits `fmadds` into `fmuls`/`fadds`.
- `new` + `push_back` returning the new record (0x8864AF28): keep the record in a register and declare a stack copy
  `t` assigned right after construction (`t = s;` before the field stores); fast path stores `s` and `return s;`,
  slow path `fn_88174A38(v, v->last, &t); return t;` (separate returns give the duplicated epilogue).

## Found at b101 (agent B)
- Early `li r3,0` + `beqlr`/`bgelr`: one result local `T r = 0; if (count) { ...; r = call(); } return r;` — early returns/tail calls don't give it (0x886A0188).
- Result in saved reg across a call (`li r29,0` … `mr r3,r29`): `found = 0; e = call(); if (e) { ...; found = 1; } return found;` (0x886C8750, 0x886C87B8, 0x886D7430).
- `clrrwi` copy + load hoisted above first store: `__restrict` out-pointer, re-read pointer via inline accessor (0x886C7CD8).
- Vector `begin` reloaded via `addi rX,base,K` instead of shared with size(): index through `vec_at(&v, i)` (0x886CD1E8).
- `(char*)e - (char*)tbl - tbl->offset` order: direct expression gives `(e-t)-off`; reading `off` into a local first gives `(e-off)-t`.
- Field load kept after an earlier store: block-local member pointer for the store `{ float *sp = &l->span; *sp = ...; }`.

## Found at b103 (agent A2)
- Restrict per-element pointer (`T *__restrict s`) turns on the 4x-unrolled loop over a self-relative float table (0x8865BD98).
- Owner pointer fields reloaded at every use: declare both fields `T *volatile` (0x8866DF60).
- Sum of two inline values in the wrong add order: wrap in an inline `total(o)` calling a per-side helper (0x88665FB8).
- Moving a loop into an inline helper taking `&o->pl->flags` can give the target's register choice (0x8866F9F0).
- Vtable-vs-argument load order around a vcall is not consistent across targets (0x8865CBD8 loads vtable first).

### Found at 886C44C0: empty-loop early branch into the "zero" arm of a later if/else
When the game's `beq` for an empty range (begin == end) jumps straight past the sum loop to the
`x = 0` arm (skipping the `sum == 0` compare), write it explicitly: `c = b; if (c == e) goto z;`
then the loop `for (; c != e; c++)`, then `if (sum == zero) { z: inv = zero; } else ...`. Plain
`if (b == e) goto z; for (c = b; ...)` mis-schedules the `mr` for `c`; the `c = b` must precede the test.

### Found at 886D1490: pointer-indexed neighbouring fields fix load order; inline helper fixes fmuls operands
- `float *w = &l->w_start; w[2] = (w[1] - w[0]) * k;` loaded w_end before w_start and kept the
  later parent-pointer load after the store (with `l->span =` the parent load was hoisted above it).
  The same rewrite also fixed a later `fmadds` operand swap.
- A commutative `fmuls` whose operand order ignored source order and local temporaries took the
  game's order once one factor came from an inline helper: `static __inline float ratio_m1(Layer *l, float one)
  { return l->inner->desc->time_ratio - one; }`.

### Found at 886CD3C8 (ME, partial: 37 -> 29 off, draft src/xbox360/drafts/me_886CD3C8_nearmiss.cpp)
- The FP1 select recipe (named `static const float kZero`, `max(zero, busy)` helper, default float model) and an
  inline `ldesc(layer) { return layer->inner->desc; }` used INSIDE the float expression (no `desc` local) together give
  the `clrrwi` copy of `layer->inner`, the `fmadds` and the xori-free mfcr/fsel select on the LTCG route. A `desc` local
  (even initialised from the helper) loses the `clrrwi`.
- Still open: target compares `fneg(busy)` against the zero already in f1 (the call argument from `g_ts4_event_value`);
  we emit `fsubs zero-busy` + a separate kZero load. `zero = kZero` or a static `g_ts4_event_value` makes it worse.
- Register-numbering residues that did not move with any rule (≈25-45 variants each): 0x88695C48 (r9/r10 after two
  graph calls), 0x8866A1C8 (win/lose address reassociation: `(rel+base)+24w` and `(rel-24w)+base+24`).
