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

  - abs as an mfcr/lfsx table select (0x889C1C80, open): on the LTCG route only the `(a - b >= kZero) ? a : b` shape
    if-converts; `(w >= kZero) ? w : -w`, `k_sign[w < z] * w`, a select helper and a `neg` local all stay branches,
    and a TU-defined zero gives a bare `fsel`. The target compares w directly against the extern zero.
  - A {begin,end} list inside a larger object whose address the target keeps (`addi r31,pred,0x5A0`): view it as
    `struct List *l = (struct List *)&pred->begin;` and test through an inline `empty(l)` (0x8867DF68, 193 -> 169).

  - Size gaps from constants (0x886807C0, 0x7A8 -> 0x900 = target size): on LTCG with the pool primer, write
    g_ts4_script_constants entries as LITERALS with the pool's exact values; each use then gets its own
    `lis/addi` base like the target (an extern array is CSE'd to one base). Clamp as nested
    `(a - b >= kZero)` max/min helpers gives the mfcr/lfsx/fsel table selects.

  - `fmadds` operand order of a lerp `u * d + lo` (0x8861E598, 0x881899D8): put the difference in a named local
    declared BEFORE the other float locals (`float d = hi - lo;` / `float dy = y1 - y0; float u;`); the same
    expression inline or with `d` declared later swaps the multiplicands. A file-scope `static const kZero = 0.0f`
    compiles to the same BINKCONS zero the target loads (reloc accepted), so clamps written as nested
    `(a - b >= kZero)` max/min helpers match directly.

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
- (886CD3C8, update) Writing the select as an explicit `__fself(g_ts4_script_constants[26 + (-busy < zero)], zero, busy)`
  (intrinsic declared as in d9t_list_scale_8847AAF8.c) gets the target's `fneg; fcmpu -busy,f1` against the call's
  zero and the exact size (29 -> 22 off). The index then comes out as `li 1; blt; li 0; slwi`, not mfcr/rlwinm/or;
  eight index spellings (`!(x >= z)`, `z > x`, pointer-offset form...) all compile the same. Primer in or out: same.
- Out-parameter store scheduled after an `addi` the target puts before it (0x8865EF98, 2 -> 0 off): store through a
  block-local restrict pointer, `{ int *__restrict fp = frame_out; *fp = -1; }`. `__restrict` on the parameter, a plain
  block-local pointer or an inline store helper do not move it.
- Pool constant values (ME, 88672130): every `lfs off(r11)` from the 0x880D0F70 base can be read off the
  `/* +0xNNN */` comments in `src/xbox360/pp1_pool_primer.c` (e.g. +0x4C 3.0f, +0x2EC 100000.0f, +0x494 -100000.0f,
  +0x368 double 57.29577951). Writing those literals took 88672130 from 132 off to 11 off; an extern array gave a different reloc.
- A 16-byte struct of four floats passed by value arrives in two GPRs that are spilled with `std r5,0x20(r1); std r6,0x28(r1)`
  and read back with `lfs` (88672130).
- Zero shared by a lane insert and a compare (ME, 88662738): when the target takes both `lvlx` (y = 0) and the fsel
  compare from the same zero symbol, use one `static const float kZero` for both (`__lvlx(&kZero, 0)`). An extern zero for
  the insert plus `kZero` for the compare gives 9 relocations instead of 7.
- A float local declared with its initializer (`float z = p->v[2];`) is loaded earlier than the same read written as a
  later assignment. On 88672130 this changed the diff from 11 to 6 off.
- Hash constant chosen by a condition and stored once (0x88676AF0, 48 -> 6 off): write `if (c) b->f = K1; else
  b->f = K2;`. The `?:` form (and a local assigned in if/else) loads both halves into one register (`lis r11; ori r11`);
  the target's `lis r11; ori r9,r11` needs the two-store form.
- Hash equality emitted as `subis rX,rY,hi; addi rX,rX,lo; cntlzw; extrwi` (ME, 88671B10): write `(x - 0x029EAAF4) == 0`.
  `x == K`, `x == Ku`, an `(int)` cast and a static const all give `lis; ori; subf`.
- A vector whose address goes to a callee (`if_get(&v)`) stays in memory for the rest of the function. Copy it into a
  second local after the call (`q = set_y0(qm)`) to keep it in a register; this cut 0x34 bytes on 88671B10.
- Period-8 pads measured (ME): fixed two of three add-order sites in 0x88676AF0 (4 function pads + named players base,
  1 pad in the loop block; 6 -> 1 off). NOT fixed by any pad count (16x10 joint sweep, block pads, late-assigned pads,
  named/pointer accumulators): the merge add of the two accumulators MSVC creates when it unrolls a sum loop
  (0x88676AF0 +0x22C, 0x88669F30). Pads have no effect on 0x88695C48 (r9/r10 numbering after calls) and only move
  0x8866A1C8 from 10 to 9 (its win/lose residue is association, not operand order).
- A 16-byte struct copy emitted as `ld; ld; std; std` (ME, 881896F8): give the struct two 8-byte members
  (`struct { __int64 lo, hi; }` or two doubles) and read it as a vector through a cast. A `float v[4]` member copies with
  four `lwz`/`stw`. This took 881896F8 from 77 off to 63.
- Field increment whose following owner/vtable loads the target keeps AFTER the store (0x8865C818, 20 -> 14 off):
  increment through a plain block-local pointer, `{ int *pc = &self->count; (*pc)++; }` (or an inline `inc(int *)`).
  `self->count++`, `__restrict` and an inline taking `self` let the loads move above the store.

## Found at b120: real C++ virtuals instead of hand-made vtables
- A virtual call written in C as a function pointer in a struct (`o->vt->fn(o, ...)`) lets MSVC hoist later loads
  above the call's result store, and it schedules argument setup differently. Writing the callee as a real C++ virtual
  member (correct slot via placeholder virtuals) and calling it through an inline member fixed both 0x886CDED0 (9 off:
  result stores kept ahead of the next ref load) and 0x886B83B0 (2 off: `li r6,1` placement). Try this first on any
  near miss whose residue sits around a `->vt->` call.

## Call argument setup order: name the arguments in a block (agentA2, 2026-11-18)
- When a call's argument registers are set up in the wrong order (e.g. `addi r4,r1,X` before `li r5,0x10` for
  memcpy), put the call in a block and name the late argument(s) in locals first:
  `{ unsigned long n = sizeof(T); const void *s = v; memcpy(dst, s, n); }` fixed 0x886CB3A8 (2 off to match).
  It did not help the `li r6,0` case in 0x886AC9D8.
- Vector load order inside `a = a - b` (b loaded first): read `a` into a local and read `b` through a volatile cast,
  `{ __vector4 x = o->v; o->v = __vsubfp(x, *(volatile __vector4 *)&d->v); }`, fixed 0x8865A6B8 (3 off to match).
- Vector register numbering of a constant loaded for an inline (agentA2, 2026-11-18): when the target gives a loaded
  vector its own fresh register (v61) while ours reuses one (v63), read it through a volatile cast,
  `{ __vector4 ax = *(volatile __vector4 *)&lbl_880FC6B0; probe.dir = normalize3(ax); }`. Fixed 0x886925A8 (7 off to
  match, plain and LTCG). It did not move the row-load numbering of 0x8864EAB8 or the matrix of 0x886634E0.
- A volatile read of one float of a stack pair (`s = *(volatile float *)&sc.s`) fixed the reload/fmuls order of
  0x88644C58 (8 -> 7 off); a named `int r = *rel` inside a relative-array helper took 0x8866A930/0x8866AC38 from 9 to 8.

## Agent B resume (ME, 2026-11-19)
- A vector returned from several branches (0x8866DA58): assign every branch to ONE `__vector4 v` local and end with
  `r.v = v; return r;`. Per-branch `r.v = ...; return r;` gives each branch its own vector register (v61, v60, ...); the
  single local gives the target's shared v63 and the same tail duplication.
- Negating a lane before `__lvlx(&z)` (0x8866DA58): `z = o.v.v[2]; if (c) z = -z;` stores z both before and after
  the branch, because z's address is taken. Compute it in a block temp, `{ float t = o.v.v[2]; if (c) t = -t; z = t; }`,
  to get the target's `lfs; beq; fneg; stfs`.
- Conditional pointer offset (0x8866DA58, 10 -> 1 off): `if (c) p = base + 0x40; else p = base;` rather than
  `p = base; if (c) p += 0x40;`. This moved the base load after the compared field load and fixed the register numbering
  for the whole prologue. The last instruction was `subf` operand order on a hash compare, fixed by `(K == x)`.
- Scalar field read after a vector lane update of a struct member (0x886498F0): use the VX1 in-place helpers,
  `vx1_vec_set_z((Vx1Vec *)&self->acc, vx1_vec_z((Vx1Vec *)&self->acc) * k);`. A hand-written lvlx/vrlimi lets the next
  `self->f60` load move above the vector store.
- LTCG with the real callees as context plus `/Oc /Ob1` (0x886498F0) keeps the callees out of line, while LTCG still
  knows their register use (vectors kept in v62/v63 across the calls, no v127 save). Without /Ob1 they inline.
- Stack slot layout (0x88650430, 34 -> 9 off): putting each xdata lookup's temporaries (hash words, forward handle, ref)
  in its own `{ }` block lets MSVC reuse the slots as the target does. The remaining 9 are slot choices that
  declaration order, k[3] arrays and inline helpers did not change.
- Dead `addi` of two sub-object addresses (0x886902E8): pass both to inline helpers used at two sites
  (`sync_pose(cur, aux)` early and `save_pose(c, cur, aux)` at the end). One plain local pointer each is not enough.
- Note for parallel agents: the shared scratchpad holds other agents' files with short names (a.c, c.py). Use your own
  subdirectory, and do not run `chk()` with an address another agent is working on: `chk()` overwrites `work/army/ME/t_<ADDR>.c`.

## Volatile vector reads, second sweep (agentA2, 2026-11-19)
- Two vor128 copies of one loaded vector (one stored, one used as the vmaddfp addend), 0x886E6F30 (17 off to match):
  read the field again instead of reusing the saved local, `x = p->pos; d = p->pos - p->prev; p->prev = x;
  p->pos = madd(damp, d, p->pos);`. The element address `(off + base)` came from reading the array base into a
  local first (`T *pts = s->points; p = &pts[i];`); `&s->points[i]`, `&i[s->points]` and byte-offset casts give `base + off`.
- A constant vector stored to two members where the target copies it with vor128 (0x8867DA30): read the second
  store through a volatile cast, `out.vel.v = *(volatile __vector4 *)&lbl_880FC650;`. Size fixed, 30 -> 15 off.
- A global constant passed into an inlined cross product (0x889C0DC0): `ts4_cross3(n, *(volatile __vector4 *)&lbl_88001AF0)`
  fixed the zero/up/splat numbering, 24 -> 11 off. On 0x889C1C80 volatile reads of both up and axis: 94 -> 91.
- No effect: 0x88671B10 (q + dir*r madds), 0x8864E790 (vupkd3d vs r1 copy), 0x8868CB18, 0x88662738, 0x8867DF68
  (residue there is GPR/scalar, not vector).

## Agent C notes (ME gameplay range, 2026-11-19; no matches, observations only)
- Dead vector stores the target keeps (0x886805E0: a normalized vector stored to 0x70(r1) and never read): put the
  locals in one stack struct (`struct { __vector4 pos, n1, a; } L;`) and pass two members' addresses to the call.
  Separate locals let MSVC drop the store, and the normalize with it. The target also keeps `a.x = a.x` self-copies.
  An in-place helper `flat(o, i)` that reads `i->v[0]` through `*(volatile float *)` reproduces those, with o == i.
- Union/struct copies of a `__vector4` wrapper come out as `ld/std` pairs. Use plain `__vector4` locals.
- `vx1_replicate(field)` loads straight from the field. The target's `lfs; stfs 0x54(r1); lvlx` comes from a block
  local: `{ float k = cfg->fd78; ... __vspltw(__lvlx(&k, 0), 0) ... }`.
- Pointer loads the target repeats with no store in between (0x886787D8 reloads `s->f154->f74` before every use
  but keeps `s->f154`): declaring the member `Out *volatile f74;` reproduces the reload pattern exactly. Plain locals,
  inline accessors and block scoping do not. This is unconfirmed as the original source, so treat it as a diagnostic
  for now.
- Bool locals the target zero-extends only at the test (`li 1/li 0`, then `clrlwi; cmplwi` at the use): `unsigned char`
  locals or C++ `bool` both gave an early `clrlwi` copy, and `int` locals gave `cmpwi`. `unsigned` locals came closest
  (0x886787D8, 56 off). Still open.
- Loop-invariant float constants hoisted into f28-f31 (f31 = highest index): declare block locals in reverse order
  inside `if (lo < i) { float k5 = .., k4 = .., k3 = .., k2 = ..; for (...) }`, so the loads land after the guard.

## Dead-addi constructors and small scheduling fixes (agD, 2026-11-19)
- C++ constructors with 0x44-byte vtable slots (vt, four words, 12-word body): write the slot ctor body like the
  0x88695568 C model, `vt = lbl_880D7600; arr_init(body);` with `arr_init` casting to `Quad *` and calling
  `quad_init` on three quads. This reproduces every dead `addi rX,slot,0x14`: 0x886A7AC8 121 -> 13, 0x886B4D00 263 -> 92
  (81 LTCG), 0x8869FAD8 129 -> 58 (rewritten in C with five explicit `sub_init` calls).
- A member array of such slots (`Slot slots[9]`) turns into a loop once the Quad-cast helper is used. Declare named
  members (`Slot s0, s1, ..., s8;`, same layout) to keep it unrolled.
- A dead `addi` of a whole sub-object (this+0x330 in 0x886B4D00): initialise its first int[4] through
  `quad_init((Quad *)a)` in that sub-object's ctor.
- A float load that the target schedules in the middle of a constructor (0x8869FAD8): read it at that point in the
  source (`z = g_ts4_event_value;` between `sub_init(&g[3])` and `sub_init(&g[4])`). MSVC will not hoist it above the
  int stores. A constant stored once (avg[17] = 1.0, which is `g_ts4_script_constants[0]`) goes last.
- Early stfs order on a stack vector built lane by lane (0x88644C58, 7 -> 5): make the first lane store volatile,
  `*(volatile float *)&p.v.v[2] = a2;`. Plain reordering of the four lane stores has no effect.
- Self-relative array helper (0x8866A930/AC38, 8 -> 7): `{ int r = *rel; return (Flag *)((char *)rel + r) + i; }`.
- Check that callee names in old drafts match the target relocations. 0x88650430 called 0x886107F8
  (`ts4_handle_forward0_886107F8`), not fn_88610798. The byte diff did not show it.
- Stack slots of block temporaries (0x88650430): brute force over all 2880 declaration orders of the two blocks did not
  move it (9 off). Declaration order inside a block does not decide slot assignment there.

## Round 2 (agD, 2026-11-19): constructor siblings of 0x88695568
- Try the LTCG route when a plain build will not hoist a global float load above struct stores (0x88271158): plain
  /Oc keeps `lfs g_ts4_event_value` after every store, because the global might alias `*s`. LTCG knows it does not, and
  matched at once (plain was 18 off). Declaring the extern `const` did not help on the plain route.
- Duplicate zero stores the target keeps (0x887DA1E8 clears eight words twice): do the second clear through
  `quad_init((Quad *)&o->w[0]); quad_init((Quad *)&o->w[4]);`. Plain stores are merged by dead-store elimination, a
  loop stays a loop, and `Quad *q = (Quad *)o->w;` adds a dead `addi` for `&o->w`.
- Records with a head word stored last (`v[0..2]` then `h`) give the target's 1,2,3,0 store order inside each 16-byte group.
- Typed record helpers beat raw index stores: 0x8846D5E0 matched from `rec_init(Rec *)` = (0, 0, 0x80000000) on named
  record arrays. The raw `((int *)s)[i]` version was 10 off.
- 0x886B4D00 (81 -> 10 on LTCG): a zero-initialised member as a tiny type whose ctor stores through a block-local
  pointer (`struct ZInt { int v; ZInt() { int *p = &v; *p = 0; } }`) lets the base vtable store go first. A float or
  vector member stored through a block-local pointer (`{ __vector4 *p = &v; *p = __vspltisw(0); }`) keeps its store at
  its source position instead of being hoisted.
- Owner reloaded after float stores into self (0x88682B58, matched): the target keeps `addi r30,self,0x1c` and reloads
  `lwz r3,0(r30)` after `stfs` to self+0x20..0x28. Take `Own **po = &s->o;` at the top and use `(*po)->...` for
  every owner access. With plain `s->o` MSVC CSEs `&o->pl` across the stores. An inline `store3(V3 *d, v)` helper
  gives the reload, but leaves a dead `addi` for `d`.
- Vector to float3 through the stack (`vspltw` x3, `stvewx` x3 into a V3 temp, then `lfs`/`stfs`): writing
  `t` fields as `d.x = t.x; d.y = t.y; d.z = t.z;` gives the target's x, z, y store order. A struct copy `*d = t`
  gives lwz/stw.
- A bool the target computes as `li 1` on the fail paths and `li 0` at the end of a chain of `&&` tests (0x8865D3C0,
  0x8868C660): write the negated `||` form, `if (a == -1 || a == b || !flag) x = 1; else x = 0;`. The `&&` form with
  `x = 1; if (...) x = 0;` if-converts the last test into `subfe`/`and`.
- A local `__vector4 tmp` passed to a getter, with an int-to-float conversion later in the same block, takes its own
  stack slot (frame 0xc0 instead of 0xb0). Put the call in its own `{ __vector4 tmp; i = f(&tmp...); }` block so the
  conversion reuses the slot.
- Hoisted float constants from g_ts4_script_constants on the LTCG route: write them as literals with the pool
  values (`-0.01f`, `0.01f`) so they share the pool base register (0x88691C40, 4 instructions fewer).
- Open (0x88691C40): the target holds the select zero (g_ts4_event_value) in a nonvolatile FPR across calls and copies
  it into a second local. A static kZero is rematerialised (f2, reloaded after calls). Comparing against the extern or
  a local turns the selects into branches.
- Open (0x8865D3C0): two element addresses from one self-relative header, (i*24 + rel) + h and (h - i*24) + rel, with
  an `mr` copy of rel. Every source form tried gives the normal form (rel - i*24) + h.

## agE notes (2026-11-19)
- 0x8866B1C8 (12 off, draft): an inline bool helper that reads `c->pend` once, followed by a caller that reads
  `c->pend->x` again with no store in between, while `c` itself stays cached. Only `Pend *volatile pend;` gave the
  reload (94 -> 12 off). Passing `Pend *` or `Ctx *` to a non-volatile helper, /Ob1 and non-forceinline did not.
  This is the same diagnostic as Agent C's 0x886787D8.

## Self-relative add order: what does and does not control it (agG, 2026-11-19)
- The written form of a self-relative element address does not reach codegen: `(char*)((T*)rel + i) + *rel`,
  `((char*)rel + i*16) + *rel`, `&((char*)rel + i*16)[*rel]` and `(T*)((char*)rel + r) + i` compile identically
  (tested on 8866A930). MSVC canonicalises the sum, so cast order, `&a[i]` vs `a + i` and add order are dead knobs.
- What changes the order is the OP1 symbol numbering. It is function-wide: dead locals in an inner block count the same
  as dead locals at the top (on 8866B1C8, 3 pads at the top == 11 pads in the `if` block: period 8). A named temporary
  inside an inline helper (`{ char *b = ...; }`) also shifts the count. So first run `tools/operand_order_pad.py`
  (8 settings cover every case); if no setting fixes every add, the residue is scheduling, not source form.
- 8866B1C8: 3 dead locals at the top plus `itemA(&o->data->items, 0)` for item0 -> 12 to 10 off. What is left is the
  item0 add and the placement of the vtable load before the bctrl.
- 8866A930/AC38: no pad setting and no helper form fixes the "add (rel + i*16), then lwz *rel, then stwx" stores.
  Ruled out: the four forms above, a second helper used only at the active-store sites, and 1-7 pads on top of it.

## Literal zero and statement-order search (agF, 2026-11-19)
- LTCG select zero held in a nonvolatile FPR (0x88691C40, 12 -> 2): write the zero as the literal `0.0f` in the
  select helpers and the `rest = 0.0f` init, not a `static const float kZero`. The literal lands in the pool slot at
  0x8814B440 (g_ts4_event_value), is loaded once into f29 and copied to f28, as in the target. This does not carry
  over to every function: in 0x8867DA30 the literal went to a different `__pool` slot (worse), so keep the extern there.
- Scheduling residue around a call argument (0x8867DA30, 13 -> 8): read the float argument into a local
  (`t = ctx->clock->t;`) and permutation-search its statement position among the struct stores. A short script
  that writes every order and runs the checker finds this in a few minutes.
- Unresolved: a `cmplw` whose loads follow one operand order and whose compare follows the other (target loads e
  then c, compares c,e). Operand swaps, `!=`, casts, compare helpers and `const` give either both in the same order or worse.

## Solved at b129: function-local static names (W8 open item)
0x886C40B8 had 0 instruction diffs but failed on MSVC's local-static names (`?$S1@...`, `?table@...`). Fix:
declare the guard and table as file-scope externs with the target's names (`extern "C" unsigned lbl_88D4AAF8;`,
`extern "C" T lbl_88D4AAD8[4];`) and write the init guard by hand: `g = guard; if (!(g & 1)) { guard = g | 1; init...; }`.
Same bytes, and the relocations now carry the target names. No tool change needed.

## agJ notes (2026-11-19): bottom-up callees of the blocked gameplay functions
- Caller keeps an argument register live across a `bl` with no reload (0x88604E50: `stwx ..., r3` after
  `bl fn_88604C90` with ctx never copied to a nonvolatile): the callee is in the same compilation unit and
  MSVC knows it does not clobber r3. Put the callee's definition in the same file (both functions in one spec);
  it matched on both routes at once. A prototype-only build moves ctx into r30 (frame and saves differ).
- Blowfish encrypt (0x88604C90): the target's 4x4 unrolled round loop needs an `int` counter (Kocher's `short i`
  is not unrolled) and a `__forceinline` F. Compute both final halves into locals before the two stores.
- Shared-tail switch (0x88600CD0, `cmpwi; b common_blt` per case): write each case as
  `case k: if (minor >= N) return 0; break;` with the final check after the switch. A table of limits per case
  (`n = N; break;` then one compare) or an inline predicate gives a single compare or branchless code instead.
- Branch to a shared `li r3,0; blr` after a failed vcall (0x88600D88): `if (o && !o->vt->f(...)) { release(o); o = 0; }
  return o;` The nested-if-with-early-return form duplicates the epilogue.
- Hash argument to a vcall (0x88179AF0): passing a constructed `Hash(0x...)` by const reference
  plus computing the other operand into a local first gave the target's `lis/ori` placement.
- Open (0x8899F760, heap-scope helper): the target materialises the hash 0x45450AE7 into r30 before the first call
  and the scope frame is 0x90 (r28-r31). Every C and C++ form tried (inline helper, ctor with by-value or
  const-ref hash, local variable) rematerialises it just before `fn_88618998`.
- 0x886176F0 is a clock seed for the Rng {seed, x, lcg} used by 0x8860BAB8: the callee 0x88885388 widens a
  SYSTEMTIME into 8 ints (year, month, dow, day, hour, minute, second, ms). 2 off: the target computes `&t` before
  the first zero store; nothing tried moved it.

## agJ round 2 (2026-11-19): STL vector<16-byte> chain
- Vector reallocating insert (0x8817A2A0) matched first try with the Dinkumware pieces as tiny inlines:
  `ucopy(first, last, dest)` (`for (; first != last; ++dest, ++first) if (dest) *dest = *first; return dest;`),
  `ufill(dest, n, val)` (`for (; n; --n, ++dest) ...`), a single-copy fast path for n == 1, and a pointer-returning
  `umax(&size, &n)` for std::max. Open-coded loops put dest in a nonvolatile and miss the `dest + delta` source form.
- Unrolled std::find (0x8890F260): trip count = n >> 2 with four compares per pass, then
  `switch (last - first) { case 3: ... case 2: ... case 1: ...; case 0: default: return last; }` with fallthrough.
  Matches on the plain route; LTCG lays it out differently.
- `resize(size() + 1, T())` then write back() (0x8890ED60): the erase branch has to stay even though it is dead.
  Write it as `if (n < size) erase-copy else _Insert_n(end, n - size, &tmp)`; the target has no separate equality test.
- Diff counts from fn_check balloon after a single inserted instruction. To see the real residue, align the
  register-normalised mnemonics (difflib over `re.sub(r'r\d+','r',...)`); see agJ/al.py in the scratchpad. 0x88178D10
  reports 143 differing but only 7 target instructions are really off.
- Open (0x88178D10 _Insert_n): copy_backward has to come out as `lwzu/stwu -0x10` pre-decrement. Every C form tried gives
  `subi; lwz 0`. The fill loops in the target load the copied value straight from the stack slot.

## agK notes (2026-11-19): STL callees and the pad sweep, no new matches
- Fill loop from a by-address local (0x88178D10): writing the fill member-wise (`p->w[k] = tmp.w[k]`) gives the target's
  direct stack-slot loads hoisted above the loop. The struct-copy form `*p = tmp` gives `addi rX,r1,0x50` plus loads
  inside the loop. But member-wise stores get strength-reduced to `p+8` with offsets -8..4, and the target has 0..0xc.
- A copy loop written as `do { *--d = *--s; } while (--k);` behind a `k > 0` guard gives the target's `subic.` counter
  where the for form gives `mtctr/bdnz`. It still emits `subi; lwz 0`, not `lwzu/stwu -0x10`. Copying the item as four
  pre-decremented `int` words gives `lwzu/stwu -4` per word, which is worse.
- Pad-insensitive drafts (top pads 0-7 do not change the count): 886AB1A8, 886E2578, 8868E320, 88661D28, 886C4D10,
  8890ED60. Their residue is not OP1 numbering, so skip pad sweeps on them. 88668310 is pad-sensitive, but the joint
  sweep (top 0-7 x 0-3 pads in each inline helper) only gets back to 2. 88677D90 LTCG (top x block, 64 runs) stays at 19.
- Pad-sweep script with joint markers that works on both routes: scratchpad agK/js.py
  (`js.py SRC NAME ADDR LTCG N1 MARK1 N2 MARK2 ...`). Drafts with `#include "../x.h"` need absolute include paths
  when they are copied out of drafts/.

## agL notes (2026-11-19): STL/template family mining with siblings.py
- Batch every matched STL-ish source through `work/army/ME/siblings.py` in one loop (one address per call: some
  matched addresses are missing from textdis.pkl and crash a multi-arg run). Filter out drafts/ and reserved lists.
- Member-embedded instances: many lookalikes are the matched template inlined on `&owner->vec` (vec at +0xdc, +0x14 ...).
  Keep the matched body as a `__forceinline` helper and call it on the member: 88940FE0, 8899F268 (+ tail call),
  88880240 matched first try on both routes. Pooled deleting dtors take the same shape, either with the base dtor on
  `self+0x28` or with no flags argument (88472858, 881B8360).
- vector operator= family (881A7A20 POD/memcpy): the non-POD siblings (881A84E8 24-byte, 88162CC8 48-byte) add
  `destroy(first,last)` before the free and `destroy(copy(...), last)` in the shrink branch. Adapting the asm2c source
  gets 8 off, all one register swap (a0+8 and rhs->last). Pads 0-7 and declaration order are dead knobs. The
  memmove POD sibling 881A7FF8 (6-byte) is 19 off: MSVC CSEs the `sl - sf` byte count across the alloc call where
  the target recomputes it.
- Unresolved: `lwzx rD, rIV, rBASE` (index first) in name-lookup loops whose name is at entry offset 0
  (885EEB50, 8841EA48, 884DAF90, 884A7430: each 1 off). Ruled out: index forms, a forceinline at(), a wrapper struct, C++,
  pads, and /Os /O1 flags.

## Added from agM (lookalike mining)
- To get the stack round-trip `stw rX,0x50(r1); ... lwz r31,0(r11)` for a value picked by a condition, bind a C++ reference
  to a conditional temporary: `const Id &pr = cond ? Id(A) : Id(B); u32 val = pr.v;` (Id = one-member struct with a
  constructor). Plain `val = cond ? A : B`, a pointer read or a volatile read do not keep the store (888C8CA0).
- With commutative float adds MSVC always loads the second operand first. To get the target's `lfs o; lfs d; fadds d+o`,
  read `*a` through a volatile pointer: `float x = *(volatile float *)a; *a = *b + x;`. This relies on volatile (88661410).
- Hash-service setter family (ts4_handle_forward_88610778 + ts4_init_range_and_run_service_opt_8816xxxx + vtable slot
  10): the template is src/xbox360/me_ts4_set_handle_value_887D37F0.c. Put each temporary Out in its own block
  (`{ Out o2; ... }`) so the slots are shared like the target's. For fn_8861CE00, pass the hash as a one-member struct by
  value. In .cpp, wrap the externs in extern "C".
- Fill/ctor functions where plain gives a different store order often match on LTCG (88800758, 885C8A18).
- work/matching-b133 was removed while this pass was running. If fn_check crashes in load_symbols, the matching dir is gone.

## agL round 2 (2026-11-19)
- A target that reloads a field the compiler would CSE (`lwz` again after a loop): read the field through a
  different base expression at each site. For example, the loop bound is `o->vec.last` while the erase uses `v->last`
  with `v = &o->vec` (886393F0). Another case is `lbl_X->sentinel` beside `l->sentinel` with `l = lbl_X` (88309D38).
  MSVC only CSEs loads with the same base symbol.
- A null check that survives a dereference (888C2FD8): the find helper must `return *i` from inside the loop and
  `return 0` after it. The `r = o; break;` form lets MSVC prove non-null and drop the caller's `if (o)`.
- Capacity word with a top "no free" bit and `clrlwi r,r,2` as size (884DB7D8): declare it as an MSB-first bitfield
  `int nofree : 1; unsigned bf : 1; unsigned cap : 30;`. The signed 1-bit field gives `clrrwi; cmpwi`. 8 off left (r29/r30 swap).
- An extra `mr r11,r3` before `lwz r3,0(r3)` for `alloc(o->pool, ..., o)` (8825B800): read the pool into a local first.
- vector operator= swap (881A84E8, 88162CC8): a named `e8 = a0 + 8` local fixes the registers (8 -> 6). The 6 left
  are the order of the two capacity/size divides, and no statement permutation or pad changes it.
- A constructor that keeps `this` in r31 unused and stores through the base-ctor result (885E5E40): a C++ ctor gives
  the right prologue but stores through r31 (16 off). Plain C stores through r3 but drops the r31 save (27 off).
- File-static singleton instances (8861DCF8): the plain route matches. LTCG folds the static into a pp1_pool symbol.
- Vector realloc-insert variants (agM round 2):
  - When the old range is destroyed by an inline per-item loop (`lwz r29,4(v); lwz r30,0(v); cmplw; bl dtor; addi`),
    use a static inline `destroy_range` that calls the one-item destructor in a loop. A range-destroy prototype swaps
    r25 and r26.
  - A 5th `unsigned char at_end` parameter (`mr rX,r7` ... `clrlwi`) skips the tail copy (`if (!at_end) d = ucopy(...)`).
  - Allocator member at +8 (`addi r6,v,8` before the newcap test, then `lwz r3,0(r6)`): use an `Alloc *a = &v->alloc;`
    local and an inline `allocate(a, n)`.
  - Items of plain floats or vectors copied field by field: use a `copy2` helper. A struct assignment gives lwz/stw, or
    a single lvx.
- Several {name,value} table searches (885EEB50, 8841EA48, 884DAF90) are 1 instruction off: the `lwzx rD,rOff,rBase`
  operand order, with no source form found yet. Drafts are in src/xbox360/drafts/.
- Before a long run, check that the build dir v.py uses still exists (`ls -dt work/matching-b1* | head`). The dirs
  rotate, and fn_check then fails with FileNotFoundError in load_symbols.

## agL round 3 (2026-11-19)
- vector operator= inline-copy variants (881A6BF0 12-byte, 881AA1A8 40-byte) matched first try on both routes with
  the 881A7A20 asm2c source. Replace `memcpy(d, s, N)` with `*(Item *)d = *(Item *)s` and give Item `int w[N/4]`;
  a `char b[N]` Item compiles back to memcpy. Generator: scratchpad agL/gen2.py (`inline` mode).
- Hidden-pointer return of an 8-byte value (`std` through r3, args shifted to r4/r5; 884AD868): a C struct is returned
  in r3. Make it a C++ struct with a constructor (`Val8() : v(0) {}`) and `return Val8();` on the miss path.
- Name/key-lookup loops: the index-first `lwzx` came out naturally in 88427878 (a leaf with the key at offset 0) and
  884EB4B0 (C++, count hoisted, vcall on the element). It did not in 885EEB50/8841EA48/884DAF90/8847AF38/88265E30, which
  call a function on the element. A hoisted count plus a by-value key are not enough on their own.
- Self-relative find with `*key` loaded before the call each iteration (88265E30/88265938/881BBC00): `u32 k = *key;`
  inside the loop, then `if (*get(r) == k)`. 1 off is left (add operand order).
- Counted inlined copy (881B7FB0, 8816E038, 882867E0, 88218E08, 8817AC40): the target recomputes `(last-first)/S`
  inside the copy. MSVC CSEs it with the earlier size in every form tried: typed pointer diff, unsigned diff, a C++
  iterator wrapper with operator-, and LTCG. Still open.
- 8890EE68 (keyed Val3 get): a C++ `struct Val3` with a 3-arg ctor and
  `const Val3 &r = (it == end) ? Val3(0, 0xfffff, 0) : it->v; return r;` gets within 3 real ops. The `li r7,0` hoisted to
  entry is still missing. Source: scratchpad agL/c8890EE68_best.cpp.

## agN notes (2026-11-19): vector _Insert_n / grow-append family mining (below 0x88400000)
- Single-insert grow paths (`li r10,1; stw r10,0x50(r1)` ... `cmplwi size,1`, three args, no tail copy) are
  `_Insert_n` with `n = 1` and `at_end = 1` as locals. Keep the full body in the source (`if (n == 1) {...} else
  {fill loop}` and `if (!at_end) d = ucopy(where, v->end, d);`): the folded short form matches the instructions but
  not the register allocation. Model: src/xbox360/me_ts4_vector_grow_append_882116A0.c.
- If the one-item construct loads every word of `*val` before the first store (`lwz;lwz;lwz;lwz;stw;stw...`)
  while the copy loop interleaves, declare the outer parameter `const Item *__restrict val` (only the outer one).
  This is not a volatile and it held on both routes (88162220, 88189E18, 88214608, 88229798, 88266EF8).
- Scalar `_Ucopy` (memmove fn_88562DC0, `subf r25,first,last; mr r5,r25; bl; add r3,r3,r25`) must return early:
  `if (last == first) return dest; off = (char *)last - (char *)first; return (Item *)((char *)memmove(dest, first, off) + off);`
  An `if (last != first) {...} return dest;` body leaves an extra `mr` or swaps v/n registers (8826B718, 8826E438, 882349A0).
  For scalar fill, use `for (; 0 < n; --n, ++dest) *dest = *val;` with no null check (mtctr loop). For float items, use
  `dest->v = val->v` (a struct copy gives lwz/stw). If the newcap add comes out `add. rX, r10, r11`, use
  `const unsigned *mp = size < n ? &n : &size; unsigned newcap = *mp + size;`.
- A fixed inline-buffer vector (`addi r8,r3,8` used as the new storage, cap at +0x48, no free; 88235140): make
  `allocate()` return `a->buf`.
- Unrolled `ld/std` item copies: `__int64 w[N]`. Unrolled `lhz/sth`: `unsigned short`. The 4th fn_88613570 argument
  (align) can be 16 (8826E190, 88229580). Check `li r5`.
- Generators (scratchpad agN): `ga.py ADDR SIZE ITEMDEF [ALIGN]` with env RESTRICT/ALLOCM/DIRECT/COPY/PRE/DESTROY/DRANGE,
  and `auto.py ADDR`, which brute-forces copy/destroy kinds, fills in callee names from objdiff's reloc/RENAME
  feedback and saves on a match. It produced most of the grow-append matches.

## agO notes (2026-11-19): lookalike mining at 0x88400000 and up (32 matches)
- Try `/Os` early on small vcall find loops: 884FA750/884F7E18 (inline pointer array, vslot 6 compare, return the item)
  were 10 off on every /Oc form (register swap plus the found-path tail placed after the epilogue) and matched on both
  routes with `/Os` alone.
- Hash-service setter family: the shape is regular enough to generate. scratchpad agO/gen.py parses the target (global key
  label from `lis/subi r9`, k1 from the `ori` before the 88610778 call, each fn_8861CE00 hash and its `mr r6`/`lwz r6,0(rN)`
  source) and agO/mk.py emits the 8894D298 template; 8894D0E8/D1C0/EC98/F188 matched with no edits.
- In that family, when the target keeps the forwarded key slot apart from the temporaries (key at 0x60, tmp at 0x70), give
  every service call its own `{ Out tmp; ... }` block (889508E8, 889502B8). A single function-level tmp shares the key slot.
- `ts4_clone_byte_with_object_context(p, src)` (0x88153620) is the out-of-line `*(u8 *)slot10(p, 1) = *src`. Targets that
  call it instead of a bctrl pass `&lbl_880xxxxx` (a const byte) or the address of a u8 parameter. The `f0 == 0 || f4 ==
  0xFFFFF` null-handle test (`li 0 / li 1 / clrlwi 24`) is a `static __inline u8` helper returning that expression (8894EE70).
- Load and store scheduling of the null-init plus global-key copy (88937148, 888B1780) matched only on LTCG. Plain stays 6-12 off.
- An array walk whose target has `add rP, rP, rStride` (pointer first) after strength reduction: index it as
  `data + i * stride` rather than `data += stride` (884D4308). This did not fix the base-reloaded `add r11,r11,r30` in 88432B08.
- Four zero stores through a just-loaded pointer that reuse its register (`lwz r11,4(r11); li r10,0; stw r10,...(r11)`):
  take an `int *w = l->rec->w;` local and write `w[0] = 0; ... w[3] = 0;` as separate statements (889158E8). A struct pointer
  local moves it to a new register; a chained `w[0] = w[1] = ... = 0` reverses the store order.
- Keyed Val3 get (8890EE68): assigning the members in the ctor body as `a = a_; c = c_; b = b_;` (not an init list) took it from
  9 to 5 off. Draft in drafts/me_8890EE68_nearmiss.cpp.
- Open: a constant passed by address to ts4_get_u32_off0_8822AFE8 (`v = 10; get(p, &v)`) is stored one slot early against
  `li r6,0` (888E1FC0 2 off, 887011A8 3 off). The n+1 recompute in the range-pair setters (88944378/88702E00) is CSE'd in every
  u32 form. A u64 slot argument gets the second addi but adds rldicl/extsw.
- Grow step without an insert (copy [begin, where) into the new block, end = new prefix end; 882289F8, 88227878,
  882285E8, 88228900, 8827A7B8): this is the grow-append body with the insert and the at_end tail removed and `where` as the
  only argument. Here newcap has to be `const unsigned *mp = size < n ? &n : &size; unsigned newcap = size + *mp;`
  (the inline form swaps the add operands). With an allocator member, old storage is sometimes released by one
  call `fn(v)` instead of the inline deallocate (ga.py TIDY=...).
- Open: 883FB5A0 tests a call result with `cmpwi cr0` where every C form gives cr6 (2 off,
  drafts/me_883FB5A0_nearmiss.c). 882669B0 (16-byte {vtbl,a,b,u8}) has a dead `addi rX,d,0xc` and a subic fill loop.
  C++ placement new on the u8 member makes a real null check (35 off).

## agO round 2 (2026-11-19, b143): 9 matches
- Ctor store order (the vtable store hoisted above member clears, 8862A190 3 off -> match): put the clears in a
  `static __forceinline void state_init(State *s)` on a sub-struct covering those fields, called before the vtable store.
  It also fixed 88636DC8 on LTCG and took 88889240 from 12 to 5 off.
- Range-for with a begin()/end() member pair on a {data, count} struct (8844EAD8): `for (e = v.begin(), end = v.end(); ...)`
  matched. Open-coded `o->entries + o->count` loads the count first or strength-reduces the pointer to +8.
- `cmpwi` vs `cmplwi` against 0 on a field means that field is signed: declare it `int` (8841C428 buffer word, 88636DC8
  lbl_88D45B1C->+0x21c, the null-handle f0 in 88770288). An `int` mode parameter instead of `u8` dropped a clrlwi in 88446550.
- Find-index leaf that sets `li r3,-1` before the loop (888C39A0): `int r = -1; ... { r = i; break; } return r;`.
  `return i` inside the loop gives a beqlr-less layout.
- Two consecutive rodata byte flags addressed from one base (`subi r31,r11,X; subi r4,r31,1`, 88770288/888CF290): one extern
  `const u8 lbl_Y[]` with `&lbl_Y[-1]` and `&lbl_Y[0]`.
- Still open: the constant passed by address to ts4_get_u32_off0_8822AFE8 is scheduled one slot off (888E1FC0, 887011A8, 88770288,
  886FC638). A C++ const-ref wrapper and moving the assignment do not help. 888CF290/888D0150 are missing only a dead
  `li r11,0` before the value test.
- **`cmpwi rX,0` / `cmplwi rX,0` on cr0 (no `cr6`) before a branch means the unit was built /O1 (or /Os), not /Oc.**
  883FB5A0 (2 off on /Oc) and 883E8AE0 matched once the flags were switched to `/O1`, on both routes. Try `flags=['/O1']`
  in v.chk whenever cr0 compares show up. 65+ specs already use /O1. /O1 did not help the add-order or operator=
  1-off groups.

## agO round 3 (2026-11-19, b145): pointer-local stores fix scheduling (6 matches)
- When MSVC hoists a load above a store to the same object (or reorders two stores to different fields), do the store or
  load through a block-local pointer: `{ Item **pe = &v->end; *pe = f(*pe, *pe, v->begin); }` (88721B58),
  `{ void **pb = &self->buf364; destroy(*pb); }` (887CC0B0, 888885F8), `{ void **pv = &s->vt; *pv = lbl; }` (88889240),
  `{ unsigned *ph = &self->hash; *ph = 0xA0BDE62E; }` (88995400). MSVC stops disambiguating by base+offset for
  that access. This needs no volatile and holds on both routes. Try it before any volatile read.
- It did not fix the constant passed by address to ts4_get_u32_off0_8822AFE8 (888E1FC0/887011A8/88770288/886FC638). The li of the
  constant is still scheduled on the wrong side of the previous stb or `li r6,0`. Tried: function-top, block, before/after the
  key, const, int, a {key, value} struct or array, a comma expression inside the call args, a pointer-local store, and
  /Ob1 or no /Oc. The IR order does not matter, so it looks like register choice (target r4, ours r5).
- Zero result kept in r31 across a call (889A0BE8): `int result = 0; ... if (h) result = h->value; return result;`.
- 888CF290/888D0150 dead `li r11,0`: `ok` flags, an early-return helper and a value-folded ready() all make it worse (6-24 off).
- The /O1 region: unmatched functions between about 0x882C0000 and 0x883F0000 with `cmpwi r3,0x0` (cr0) after a call are
  mostly /O1 units that return error codes (883E86A0, 883E86F8, 883E8398, 883E8410, 883E8B28, 883E9170, 883E9758, 883E8EB8,
  883FB528, 883FB620, 883FDB00, 882DDC08, 883E9BC8). The usual shape is `int r = f(...); if (r) return r;`. A scan of
  textdis.pkl for small unmatched functions containing `cmp[l]wi rN,` (no cr6) below 0x88400000 found about 85. Free calls
  that pass a file/line pair use `lbl_88B3302C->heap` and `lbl_88039A20` with the line as an immediate. Not solved:
  /O1 rotates `for` loops (a jump to the bottom test) where 883E6308 tests at the top, and /O2 gives the right loop with cr6.
- Helper for this pass: scratchpad agN/r3.py `go(addr, name, src, h1, h2, fls=...)`. It loops over flag sets, fills in
  callee names from reloc/RENAME feedback, checks LTCG and saves (spec + done list) on a match.
- An inline member constructor that zeroes a field and then copies every field (`stw 0,4(d)` followed by a full
  copy; 881BA060) needs the copy written field by field after `d->b = 0;`. A struct assignment drops the dead store.
- A find helper with a default (`if (!o) return s->def; return o;`, 8816D220) keeps the target's duplicated return
  tails. `if (o) return o; return s->def;` and `o ? o : def` merge them.

## agP (2026-11-19, b146): pointer-local stores, second pass over scheduling drafts (4 matches)
- The pointer-local store does not have to be the store right before the misplaced load. Put it on the store that
  the target emits just before the load: 886BBC38 (body weight stores in both if/else arms), 886E2578 (the last
  list field, `{ void **pc = &pl->capacity; *pc = 0; }`), 88677AC0 (court stores in both arms; 8 off -> match),
  88683BF0 (the n4c store in a zeroing block, so the float zero loads after 0x40-0x4C; LTCG only, plain 23).
  Try each store in the block around the residue, one at a time. It costs about a minute per candidate.
- Doing the store through the pointer on the store right before the misplaced load often does nothing, or it
  grows the size (88677AC0 b->server: +8 bytes).
- No effect, so do not retry the trick on: a constant li/lis on the wrong side of a store (88151088, the 8822AFE8
  family), a parameter spill (8864BAE8), a zero register choice (88640810, r10 vs r11), or a missing early `mr r31,r3`
  in constructors (8866CFA8, 886D48F8).
- matching-b146 still names 0x8814B440 `lbl_8814B440` on the plain route, but symbols.txt calls it `g_ts4_event_value`.
  With the symbols.txt name, the plain check fails only by that relocation name, and LTCG matches.

## agQ (2026-11-19, b148): /O1 cr0 scan below 0x88400000 (55 matches)
- Scan: unmatched functions below 0x88400000 with 8-150 instructions that contain `cmp[l]wi rN,` without a cr field
  number 361 (textdis.pkl, b148 report). 234 of them read a volatile register (r4-r12) after a `bl` before writing it.
  Those keep values in volatile registers across in-unit calls (883DD7A0 keeps `this` in r7 across fn_883DC3C0), so they
  need the callee's source as LTCG context. Do the other 127 first. The scan script is in scratchpad agQ/scan.py.
- 54 of the 55 matches are /O1 and one sibling (88377078, cr6 compares) is /Oc. All 55 match on both routes.
- Intrusive-list walk (`n = head.next; n != &head; n = n->next`, item = `n ? n - 4 : 0`): /O1 rotates it into a jump to the
  bottom test. A plain `for` over the list matches (883F02A0, 883F2830, 883F2C28, 883F0208, 883FDA60, 883FE220, 883EF2A0).
  When the end is re-read through the owner each pass (`&t->s->head`), write it that way in the loop test (883F6338).
  When the end is null-checked (`cmplwi; addi rX,rY,4; bne; li rX,0`), write it as `n != (t->kids ? &t->kids->link : 0)`
  (883DF0F0, 883DFD60).
- `clrrwi r3,r11,0` before a vtable call means the member was used directly: `if (t->opt) t->opt->vt->f(t->opt, x)`. With a
  local (`L *l = t->opt;`) the clrrwi goes away (883EE728 wants the local, 883FF9B0/883F7948 want the member).
- Singleton creators with two inlined base ctors (883E8F58 + 6 siblings: `stw A,8; stw 0,0x10; stw B,0; stw C,8`): in C,
  do the first (dead) vtable store through a pointer local, `{ void ***pv = &d->vt8; *pv = lbl_8803978C; }`, so DSE keeps it.
  A real C++ base+derived ctor pair adds an `addi rX,r3,8`.
- COM QueryInterface with inline 16-byte IID compares (882DD460, 882DDAA0, 884F9EC8): use `#pragma intrinsic(memcmp)` and
  `if (!memcmp(a)) *out = u; else if (!memcmp(b)) *out = u; else return E_NOINTERFACE;`. The `||` form puts the failure
  path first. When the result stays in r31, duplicate the AddRef in both arms and keep one `hr` local.
- A local pointer copy changed `cmplwi cr6` into `cmplwi cr0` (883F6338). `if (t->s) { s = t->s; ...` restored cr6.
- `rlwinm.` vs `extrwi.` on a halfword flag test (883C7278, 1 off, draft): every bitfield, shift and mask form gives
  rlwinm. Near miss 883DF888 (2 off, draft): both fmuls have swapped operands, and no operand order fixes it.
- Signed ring index `x < 0 ? x + (1 - x / 4) * 4 : x - x / 4 * 4` (srawi/addze, `add.`, subfic) as a static inline matched
  883FFC48. Note that this is not a true modulo: a negative multiple of 4 maps to 4.
- Constant hoisted out of two consecutive loops (882EB390, 6 off): a `float k` local and an inline helper both leave
  the lfs scheduled one slot off.
- Float temporaries that are all computed before any compare (883C7158): use a Vec3 local for the difference.
  `if (all zero) *p = 0; else *p = 1;` puts the stb before `li r3,0`, where `*p = !(...)` puts it after.
- Delay math with `__u64tod` (883FB6B8): `d = (float)delay * K; due = now + (__int64)(d * (float)rate + K2);`. The
  64-bit stamp comes back as an {int,int} pair and is read with `ld`, so it is typed as a union.

## agR (2026-11-19, b148): vector out-of-line copy, emplace_back and push_back variants (35 matches)
- Generator: scratchpad agR/ga.py and agR/auto.py (copies of agN's with these additions). `UCOPY=fn` makes ucopy an
  out-of-line call `Item *fn(first, last, dest)`. `NOCHK=1` drops the null check on the inserted-item construct, and
  `UNCHK=1` drops it in the ucopy loop. `A16=1` (auto) gives a `__declspec(align(16))` Item. `EMPLACE=ctor|-` with an
  optional `EBODY='...'` wraps the PREFIX grow body as `grow()` and emits emplace_back: `if (end == cap) grow(v, end);
  if (end) ctor(end); ++end; return end - 1;`. `PUSH=1` (with `PUSHCHK=1` for a null-checked fast path) wraps the full
  grow-append as `insert1()` and emits push_back: `if (end != cap) { construct(end, val); ++end; } else insert1(v, end, val);`.
  `FORCE=1` makes grow `__forceinline`, which vector members need. `OUT=path` writes the source and does not compile it.
- Bugs fixed in ga.py: `DRANGE` with `ALLOCM` silently dropped the range-destroy call, because ALLOCM had already rewritten
  the line it replaced. Every allocm+range attempt by agN's auto.py was therefore really a no-destroy attempt.
  `TIDY` with `ALLOCM` emitted no prototype for the tidy callee, so the source compiled with an implicit `int fn()`
  declaration. That affected 8 saved files (88228C40, 88228E18, 88228FD8, 882290B8, 882298C8, 882299A0, 88225790,
  882597D8). They now declare `void fn(Vec *v);` and each was re-verified as matching. auto.py's rename loop now runs
  8 rounds instead of 4: with fn_AL, fn_U, fn_C and fn_DR as placeholders, 4 rounds ran out before the last rename.
- Do not run two auto.py/ga.py jobs on the same address. Both write ga_ADDR.c, and save.py will save whichever body
  is on disk at the time (one header was overwritten that way).
- A 0x60-byte POD copied with an inline `li 12; mtctr; ldu/stdu -8` loop (88178590): give the Item `__declspec(align(16))`.
  Without it, a struct assignment of 88 bytes or more is a memcpy call. With align 16, MSVC emits the ldu/stdu block loop.
- Item of two `__vector4` (88263380): `#include "vx1_vector.h"` and copy member by member (`d->a = s->a; d->b = s->b;`) to get
  `lvx128/stvx128`. A struct assignment gives ld/std. A C++ empty struct item (size 1, 882596F8) makes the whole copy and
  construct compile away, so ucopy reduces to `d = nb + (where - begin)`.
- Inline default ctors in emplace_back that zero several fields (88263548, 88263730, 8827A540): store through an
  `int *w = v->end->w;` local. Direct `v->end->w[i] = 0` stores schedule the `end` reload before the second store.
- Byte-item ucopy (88263460): `++first, ++dest` order fixes a swapped addi pair.
- Item with a vtable word (882598B0, 88228EF8): `d->vt = (const void *)lbl_880F228C;` and then the fields one by one.
- Counted-copy reuse blocker (Task 2, 88218E08 operator=, 56-byte item). I wrote a typed C model:
  self/rhs, an inline ucopy, a destroy loop, and a `copy()` with `for (n = l - f; 0 < n; --n)`. It is 102-111 off. In the
  shrink branch MSVC reuses n (`mr r30,r24`), while the target runs `divw.` again. Results, as candidate `divw.` count
  against the target's 2:
  a plain static (non-inline) helper: still reused. A pointer loop `for (; f != l; ++d, ++f)`: MSVC keeps it as a pointer
  loop, with no counted loop and no divw. `/O1`, `/Os`, `/Ot`, `/Ox`, `/Ob1`: still reused (`/O1` is 94 off). A pointer-local
  store on `self->last`, or `n` computed through a pointer: no change. The copy as a separate function in an LTCG context
  TU, inlined at link time: still reused, and `mid - f` is still folded. A C++ by-value iterator struct
  (`copy(It f, It l, Item *d)`): best at 74 off, still one divw. The target also leaves `(f + size*56) - f` unfolded
  (`mulli; subf; add; divw.`), so the count expression was out of reach of reassociation/CSE in the original build. Still open.
  Sources: scratchpad agR/t2 (b.c, idx.c, try_.py).
- 88152ED8 (`reserve(3)` on a 0x208-byte item): 29 off, in drafts/me_88152ED8_nearmiss.c. The target loads `v->alloc.h` once
  above the `begin == 0` test and calls fn_88613570 separately in both arms. Neither a single allocate nor an explicit `h`
  local reproduces this.

## agT (2026-11-19, b150): volatile registers kept across in-unit calls (LTCG + callee context)
- agQ's scan2 "IPA" flag is mostly false positives: it is a straight-line scan, and it counts the `bl __savegprlr_NN`
  as a call. A path-aware rescan (scratchpad agT/real.py: CFG fixed point, `bl` into 0x8856A000-0x8856B000 ignored)
  leaves 17 of the 234 that really read r4-r12 after a call: 883DD7A0, 883EDB98, 882C3628, 883ED7A8, 883ED800, 883CF7F0,
  883D2620, 882DDD58, 883CF8A8, 883D34C8, 883CBBC8, 883E52E0, 883CAB80, 883F63F8, 882E1CC8, 883EC308, 883CEC88.
  The rest are normal /O1 functions: 883F77C0, 883E8598 and 883CE938 matched on the plain route (883F77C0 and 883CE938
  fail on LTCG, where values move into volatile registers or the float literal goes to `__pool`).
- Recipe that worked (6 LTCG matches): match the small leaf callee on plain /O1 first, keep its `fn_` name (symbols.txt
  name), save it, then `chk(..., ltcg=True, ctx=[callee.c], flags=['/O1'])`. No `/Ob1` prefix was needed: /O1 LTCG did
  not inline these callees. `/Oc /Ob1` was always worse (the frame grows).
- LTCG constant-propagates into the callee when the caller is its only caller in the link: 883DD7A0 passes -1 to
  fn_883DC3C0 and the `li r6,-1` disappeared. Adding a real matched sibling caller that passes a variable delta
  (883DD558) as a second context file brings it back. Check for other callers before blaming the source.
- 883EDB98: with only the callee in context, `out` was kept in r8 (target r9). Flags `/O1 /Ob1` give r9.
- Float literals on the plain route: `0.0f` gives lbl_88001A20 and `1.0f` gives lbl_88001A68 (accepted by fn_check). Under
  LTCG they go to `__pool@`; use `extern const float lbl_...` there.
- Bitfields: MSVC fills from the most significant bit here, so a 2-bit state in the low bits of a u16 (`clrlwi 30`) is
  the last field: `unsigned short rest:14; unsigned short state:2;`. float to unsigned is `fctidz` (`(unsigned)f`); with
  `(int)` in between it becomes `fctiwz`.
- Near misses (drafts/me_<ADDR>_nearmiss.c):
  - 882DDD58: the code is identical on LTCG + fk2_o1_000.c, but the target has a relocation on `lis/ori 0x8876086C`
    (an HRESULT that falls inside .text, read as `fn_887607E0+0x8c`). The checker wants the relocation, so this is a
    split/config problem. Writing it as a function address would be a false source.
  - 883CF8A8 (caller of 883CF7F0, keeps `out` in r4 and 0.0f in f13): the branch layout is wrong (target has 4 calls with
    the not-found second seek shared by both directions). Tried nested if/else, gotos and a `lo` local: 47-50 off.
  - 883D0C18 (callee of 883D2620): the target counts with `mtctr idx` and checks `n == head` before `idx > 0`. A plain
    `while (n != head && i--)` loop is 11 off. /O1, /Oc, /O2, /Os and LTCG did not give the ctr loop.

## agS (2026-11-19, b150): /O1 cr0 scan, non-volatile group from 51 instructions (29 matches)
- Re-filtered agQ/scan2.txt against b150 (scratchpad agS/filt.py): 70 non-volatile candidates were left. I worked them in
  order from 51 to 86 instructions, plus siblings 883CF350 and 8828E8A8. All 29 matches are /O1 on the plain route, and
  5 of them miss on LTCG (883F2960, 883CC968, 883FBDC0, 883CF1A0, 883C8F98). The three C++ ones
  (883E39A8, 883E84A8, 883F8460) need real `virtual` methods because the target loads the method before the arguments.
- **fmuls operand swap fixed by a float literal** (883F2960): `tmp * lbl_88039DD4` gave `fmuls f1,f0,f13` in either source
  order. `tmp * 5.020597f` gives the target's `fmuls f1,f13,f0`, and the checker accepts it because the label holds the same
  bytes. Read the label's value with `fn_check.target_data('lbl_X')` (TS4_MATCHING_DIR set) and print the shortest float
  that round-trips. This may also fix agQ's 883DF888 (both fmuls swapped). It is still on the blocker list, so I did not try it.
  Counter case (883FB2E0): two literals in a row (`* 0.016666668f * 0.25f`) are folded into one constant under the default
  fp model, so keep externs there.
- **A pointer-chain select that reloads the field** (883F1A68): `(o->own ? o->own->sys : 0) ? (...)->src : o->src` is CSE'd.
  The target reloads +0xAC for the second use, and an inline accessor called twice does that:
  `static Sys *obj_sys(Obj *o) { return o->own ? o->own->sys : 0; }`.
- Edge-triggered flag tests (883CA810): `if ((f & B) && !on) ...; else if (!(f & B) && on) ...` reproduces the target reusing
  the masked flag in a second `cmplwi`. Nested if/else forms give a different layout.
- `extrwi.` vs `rlwinm.` on a word flag (883CC388): `if ((unsigned char)((t->flags >> 17) & 1))` gives `extrwi.`. A plain
  shift-and-mask, a bitfield or `== 1` gives `rlwinm.`. (agQ's halfword case 883C7278 may be worth one try with this.)
- `cmpwi cr6` on a call result instead of cr0 (883FBDC0): the call sits in an inline helper that does its own
  `if (r) return r; return 0;`, and the caller tests the helper's result again.
- Two early `return 0x21` tests written separately (`if (!a) return X; if (!a->b) return X;`) keep the target's shared
  `li r3,X` block above the chain walk (883FE980). With `||` the returns merge at the end.
- Header-size read before an inline zeroing (882908C0): `unsigned h = b->hdr; void *d = init(res); copy(d, b, h);`.
  The target loads `hdr` before the five `std` zero stores. Passing `b->hdr` as an argument loads it after them.
- Inner list loop with a prefetched next (883D1240, 2 off): `for (l = first; (cur = l) != end; ) { l = l->next; ... }` gives
  the target's rotation with `mr r11,r31` in the bottom test.
- Signatures found from register use: fn_883DE760 takes 5 arguments (r5 holds the buffer that was null-tested), and
  ts4_call_cb_883C7220 is `void (o, int, int, int)` (see d9ob_call_cb_883C7220.c). I fixed the 883E2C90 prototype to match and
  re-checked it on both routes. Before you declare a callee, grep src/ for an existing prototype.
- Near misses (drafts): 883E3F20 (2 off, swapped lwz destinations r10/r11 in an add loop), 883CC388 (2 off, `stb` of the
  out-flag scheduled before `mr r3,r31`), 883D1240 (2 off, see above), 883EA1F8 (1 off, `add r10,r30,r10` for t->blocks[i];
  every indexing form gives the reverse order).
- Open, more than 3 off: 883F9B68 and 883DA348 (count-then-index list helpers; MSVC CSEs `head->next` across the count loop and the
  target does not. A `size()` inline helper does not help), 883F6FA0 (12 off, an int64 stamp read through a union; the stack slots of
  `now` and the temporary are swapped), 88290C68 (sibling of 882908C0; r30/r31 swapped between `b` and `res`), 883F2158 (12 off,
  register assignment only, nested list walks), 883CE7E0 (singleton creator; one register too many), 8828FA98, 883FB2E0, and 88296908 (the
  `mr r1,r1` / `mr r31,r31` / `mr r2,r2` spin hints have no intrinsic in this compiler setup).
- agT round 2 (b151, plain-route /O1 group from the rescan): 22 matches. Patterns that helped:
  - Shared `~x` tails in handle APIs (882E2570): put both results in the out variable (`out = g(); ... return ~out;`). A
    separate `r` local or early returns lays the blocks out differently.
  - An 8-byte zeroed pair kept as `std` (883E1980): use a union with an unsigned 64-bit member and write `p.q = 0`.
  - `if (r) return r;` kept before `return 0` (883D4900): write the check inside each branch of the if/else.
  - Byte swap with `lbz` of byte 0 (883E7828): `(w << 24) | ((w << 8) & 0xff0000) | ((w >> 8) & 0xff00) | ((u8 *)&field)[0]`.
  - `and.` operand order inside a bool helper (883FF850): pass the struct (`helper(info)`, reading `i->mask & lbl`), not the
    loaded mask value.
  - Nested child loops with `clrrwi` before the call (883F9DD0): `int n = k->n; Obj **items = k->items;` locals, then
    `if (items[j]) items[j]->vt->f(items[j], x)`.
  - A parent climb kept as temp-then-assign (883E1C08/883E2ED0): `p = t->parent; q = p->parent; while (q) { p = q; q = q->parent; } root = p;`.
  - An unused first parameter needs `(void)self;` for the host check.
- Near misses in round 2 (drafts/me_<ADDR>_nearmiss.c): 883C75D0 and 883CBB30 (1-2 off, `lwzx` operand order on a
  strength-reduced i*4 index into a re-read `kids->items`; operand_order_pad 0-12 did not change it); 883E5E80 (6 off,
  u64 register choice); 883E5CE0 (20 off, null-object branch placed at the end); 883D8970 (5 off, two parameter
  registers swapped); 883DB8F0 (16 off, register renumbering); 883DE6A8 (17 off, target re-copies r3-r6 from saved
  registers before the else-branch call).

### agS round 2 (b152): blockers retried, 87-110 instructions (5 matches)
- 883DF888 matches once all four multiplier labels are float literals (0.25f, 0.020833334f, 0.041666668f, 4.0f). With only
  the `* 4.0f` literal, the other fmuls stays swapped. So when an fmuls swap appears, replace every labelled multiplier in
  the function, not just the one in the diff. The old draft drafts/me_883DF888_nearmiss.c is superseded and can be removed.
- 883C7278 (halfword flag, `extrwi.`) is still 1 off. On a `lhz` value, the `(unsigned char)` cast gives `srwi; clrlwi.` instead of
  `extrwi.`. A u16 bitfield, `!!`, `!= 0`, a helper and an `(unsigned int)` widening all give `rlwinm.`. So the 883CC388 trick works only on
  word fields.
- 88290C68 is still open (r30/r31 swap between `b` and `res`). Statement order, declaration order, const, `== 0`, folding memcpy into
  the call and C++ all give the same assignment.
- New matches: 883DF888, 883FCE80 (seven-way compare with `fabs(x - a) < 1e-05` as a macro and a `switch`; matched first
  try), 883CC1F0, 883F1640, 883D03C8.
- Store order inside a zeroing block (883F1640): MSVC emitted the stores in a different order from the source. Moving the
  `sth` to the top of the block in source fixed it. Try each store first.
- A local list head (`Link *h = &t->own->lst->items;`) gives the extra non-volatile register that the target keeps for the
  loop end (883D03C8). Re-reading `&t->own->lst->items` in the loop test uses one register less.
- A call made after both arms of an if/else (883D03C8: the fade arm also calls ts4_flag_all) should be written once after the
  if/else. The target's `b` jumps into the shared `mr r3,r29; bl`.
- Open: 8829B288 and 8828FA98 share an inlined "render targets equal" check plus a `use_viewport` uchar helper. In 8829B288
  the bitfield store (`rlwimi`) and the store order match, but the inner chain's `li 1` is threaded past the double
  `clrlwi`; `__forceinline` helpers and `?:` forms did not fix it. Also open: 882D1FB8 (4 off, lbzx base/offset order on a byte
  palette; every indexing form gives the reverse order), 882A4F50 (the compiler reorders the state switch), 883ED130 (2-bit mode
  bitfield written from `mode == 3`: the target re-extracts with cntlzw/extrwi and inserts 2 bits), 883DF678 (the target reloads
  `*pv` for the virtual call after testing it), 883E5610 (stack slots), 883CC4A8 (not tried).

## agS round 3 (b154): no new matches
- 883CC4A8: the if/else arms that use bus are tail-merged, and the target puts the else block late. I could not reproduce that layout from source order.
- 883DC840: lbl_88B3B4B4 is addressed through a reloc plus an addi base. The candidate's address materialization differs, and the stream is off by one.
- 882D1FB8: the base/offset order of lbzx did not change with `4*i`, a shift, a 2-D array cast or const.
- 883C72E0: the candidate puts the `+= 0xffff` constant in a callee-saved register (`ori r30, r10, 0xffff`), which costs an extra save of r29. The rewrites I tried for the u16 decrement all stayed 133 off.
- 883CAEC8: the int handle field gets a `clrrwi` and a materialized `!= 0` in the target. It is still 69 off.
- agT round 3 (b154): 18 more plain /O1 matches. Notes:
  - Parameters passed straight through to a callee (no `mr` before the `bl`) mean the callee takes them in the same
    position: 882DB018 calls fn_882D1BC0(t, fmt, 0, 1), and 883D4900/883DE6A8 pass r4-r6 on unchanged.
  - Import data: `lis r28,0x8800; lwz r3,0x868(r28)` is `__imp_VdHSIOCalibrationLock`. Declare
    `extern void *__imp_VdHSIOCalibrationLock;` and pass it directly. Kernel calls (KeEnterCriticalRegion,
    RtlEnterCriticalSection, VdRetrainEDRAM, ...) are declared by their own names (882A6528).
  - Pointer null test with `cmpwi` (signed): `if (PTR_INT(o) != 0)` with a local `o`, behind an `_MSC_VER` macro so the host
    check passes (883FB9D0).
  - Argument setup order: name the arguments as block locals in the order the target computes them
    (`int px = x0 + x; int py = y0 + y;`, 882BFD50/882DB888).
  - Tail-insert into an intrusive list: an inline `link_before(n, head)` helper that reads `head->prev` before the first
    store (883D2700).
  - Two calls to a manager getter: keep one `Mgr *m = get();` local (883FB780).
- Open across rounds 2 and 3: `lwzx rD, rIdx, rBase` (target) vs `rBase, rIdx` (ours) when the base is re-read through
  a two-level chain (`node->kids->items[i]`) inside a strength-reduced loop: 883C75D0, 883CBB30, 883D87A0, 883D9CA0.
  Accessors, `i[a]`, unsigned indices, referenced pad locals (0-10, top and loop body) and OP1 pads made no difference.
  In 883D9CA0 the target also allocates the induction to r31 and the node to r30, where ours swaps them.
- 882DD5F0 has the same `0x8876086C` false relocation as 882DDD58 (needs a split/config fix).
- Other round-3 near misses (drafts): 883E6438 (a `cmpwi cr6; bne +4` left after the last call, plus a register swap);
  882A2EE8 (one extra saved register); 883FCCC0 (Pair zero stores scheduled after `addi r5`); 883FBC58 (prototype of
  fn_883E6978 with a float argument and a stack argument: frame 0x60 not reproduced).

## agU (2026-11-19, b154): whole-binary sweep of the smallest unmatched functions (69 matches)
- Candidate list (scratchpad agU/cands.py, filt.py): 3050 unmatched functions of 6-40 instructions after removing drafts,
  ME specs and agT's todo. 769 are left after dropping v0-v13 vector code, asm/CRT shapes (mffs, r13, `mr r8,r8`/`mr r1,r1`,
  lwarx, mftb, `(r0)` addressing) and mis-split functions whose listing does not end in a return or tail branch
  (883FBB88, 884F5080, 883F1994: the symbol is cut in the middle of a function). Do not filter on `mflr r12`: that is the
  normal prologue here. My first filter did, and it hid every non-leaf candidate.
- Flags: 68 of the 69 matches are /Oc, and one (883EEAB8) is /O1. 55 match on both routes. The other 13 match plain only,
  because a 0.0f/1.0f literal goes to `__pool` under LTCG.
- **The 0x88330000-0x883A0000 band is mostly first-try /Oc C.** Recurring shapes, each with a model source:
  - Outer-object adapters: `O *o = b ? (O *)((char *)b - 0x1c) : 0; ...; return 0;` (setters, flag toggles, zeroing loops,
    format into a buffer through a varargs call with `(double)` promotion). Models: me_ts4_set_flag_134_8833DE28.c,
    me_ts4_set_param_13c_148_88349D60.c (switch on k), me_ts4_busy_code_2d_8836F980.c.
  - Heap frees with file/line: `fn_88315F10(lbl_88B3302C->heap, p, lbl_FILE, LINE)` (models me_ts4_free_buf_16c_883746B0.c,
    me_ts4_free_bufs8_2d4_88396180.c). Allocations: fn_88315C60 takes 6 arguments (heap, size, file, line, 0, 0), and
    fn_88316070 is the 6-argument realloc (heap, p, size, file, line, 0).
  - Child loops: `int r = 0; for (i = 0; i < s->n; i++) r = s->kids[i]->vt->fn(s->kids[i], args...); return r;` (count at
    +0x7c, kids at +0x80), and the variant `int r = base(s, args); if (r) return r; for (...) ...; return 0;` (count +0xac).
    14 matches. Argument lists of any mix of int and float matched without edits (me_ts4_kids_call_slot18_8f_883795B0.c).
- Small fixes that worked:
  - Indexed address helpers that compile to `slwi/add/slwi` (24- or 20-byte items): the C function swaps r10/r11, and the
    same body as a C++ member function (`It *O::at(int i) { return &items[i]; }`) matches (8841ED80, 8841F0D8, 886EBA80).
    Give each file's structs unique names: identical mangled names in two units would collide at link time.
  - When a string routine keeps `mr r11,r3` and returns with r3 untouched, return the argument: `char *f(char *s) { ...; return s; }`
    (88329768, 883297A8, 88376700).
  - Unsigned `cmplwi` against a parameter that has no clrlwi: declare the parameter `unsigned`, not `int` (8833DE28).
  - The pointer-local store trick (agO) also fixes float load-after-store order: `{ float *p = &s->a; *p = s->base + x; }`
    (8843F8F8).
  - Early returns written separately keep the shared `li r3,X` block in the middle (8836F980), as agS found for 883FE980.
- LTCG constant-propagation signatures (skip these on the plain route): `li rK,C; subf; subic; subfe` for `x != C`
  (885E9648, 88428E80), and `addi rX,rX,0` before `subic/subfe` (88925410). These are compares with a propagated constant.
- Not solved: the 8828Cxxx bitfield setters (7 functions) store a u64 dirty word twice with no scheduling and keep
  everything in r11. Every flag set, volatile and pointer-local form tried was 9 off. Vector-copy getters that use v0-v13
  (88476128 family) stay open, as the existing note says.
- Near misses (drafts/me_<ADDR>_nearmiss.c): 883E82F8 (dead addi order), 8864E640 (two fadds operand swaps), 888C72E8
  (cmplw operand order), 8836CBE8 (add operand order; pads 0-8 no help), 88329478 (lwzx order), 883EEFA0 (`mr r3` vs store
  order). These are more than 2 off and have no draft: 886EBDA0 (fdivs/fsubs order), 88330278 (li hoist),
  88399650 (two constants addressed from one base, `lbl_8802E940[-1]`).

## agV (2026-11-19, b155): /O1 cr0 queue (agT todo3), 57-79 instructions (29 matches)
- Queue re-filtered against b155 (scratchpad agV/filt.py; it also skips addresses that have a draft in src/xbox360/drafts). I worked
  from 57 to 79 instructions, plus siblings 883D28E8, 882CF300 and 883F2C98. All 29 are /O1 on the plain route. 8 of them miss on
  LTCG: 882B2688, 882CF300, 883D32B8, 883CF430, 883FF1A0, 883CB130, 883F1400 and 883DBDC0. None uses volatile.
- **Float literals, all or nothing** (883FF1A0): with `(float)rate * K + 0.5f` for two windows and a `1.0f` store, only
  the version with all four constants as literals matches. Any mix with `extern const float lbl_...` reschedules the block.
  Search every combination (16 tries) before giving up on a float-heavy init. The checker accepts `__real@` for labels
  with the same bytes. The opposite case was 883EE2E8 (open): there, literals 0.0f/1.0f give `__real@` relocations
  that the checker rejected, because their scheduling differed.
- `unsigned int` sample rate: `(float)u` gives `std; lfd; fcfid` with no `extsw`. If `extsw` shows up, the source is unsigned.
- **Declaring two clamped indices together** (882B2688/882CF300, resample taps): `int prev, next; ... if ((unsigned)next >= total)`
  matches. An `unsigned int next` local swaps r9/r10 through the whole loop body.
- Signed pointer tests (`cmpwi` on a pointer) came up twice more: 883FBEB0 (`a->tgt`) and 883CB130 (`list->items`). Use
  the PTR_INT macro from 883FB9D0.
- 883CB130: a top-bit handle test `if (h >> 31)` gives `clrrwi.`, and `if ((unsigned char)(h >> 31))` gives the target's `srwi.`.
  Reading the global `lbl_88CAC988->nodes[idx]` directly, with no local copy, brought back the `clrrwi r11,r9,0` before the member use.
- Writing a call result into an out-param (883EAC40): when two calls in an if/else each test the result, put
  `if (r) return r;` inside each arm. A shared test after the if/else tail-merges the blocks differently.
- Tail-link with no helper (883E3700): an inlined `link_before(n, head)` helper put the loop increment in the wrong place.
  Open-coding the four stores in a block with locals `Link *n = &o->link, *h = &t->head;` matched. 883D32B8 wants the
  helper with `Link *p = head->prev; n->next = head; n->prev = p;` (next stored first).
- Path walkers (883D80E0, iterative): `while (path && t->kids) { scan; for (n = first; ; n = n->next) { if (n == end) return 0;
  if (match) break; } if (!*p) return ITEM(n); t = ITEM(n); path = p + 1; }`, with ITEM as a null-checked macro that is evaluated each time.
- Prototypes taken from register use. Each disagreement is noted in the file header:
  - 883CF548 and 883E2B30 are `(Ref *, Alloc *)`; their asm2c bodies declare 8 words.
  - 883E54A8 is called with 2 arguments in 883E8978; another file declares 3.
  - fn_883E13B8 returns int in 883E3700; another file declares it void.
  - ts4_if_get_u32_off4_883E51B8 returns an int index (`>= 0` test in 883E8978). 883EAC40 now uses int as well.
- Not attempted:
  - `0x100(r13)` + `mftb` GPU waits: 882914D8, 88291B08, 88292698. `__getReg(13)` is an ordinary call in this compiler, not an
    intrinsic. 8829A6E8 belongs to the same group.
  - 0x8876086C false relocation (as in 882DDD58): 882C73D8, 882C5EA8, 882C5FC8.
  - 88296D48: the target `lis/ld 0x88C6E1A0` has no relocation (there is no symbol there), so it has the same split/config problem in reverse.
  - ctr search loops (see 883D0C18): 883F2058, 883F8FC8, 883D4A98.
- Near misses (drafts): 882DD880 (1 off: `li r10,1` scheduled above the lhz/cmplwi of an `m = wide ? 4 : 1` select), 882BF4D8 (2 off: the
  buffer null test is cr0 where the target has cr6), 883D4998 (3 off: lbzx/stbx/add base/index order on `rest[n]`), 883D86A0 (1 off: lwzx
  order, the same open class as 883C75D0).
- Open, more than 3 off: 883EAB38 (inline 0x14-byte ctor; the target materializes zero twice, `li r9,0` and `li r10,0`; a C++ base+derived
  ctor and pointer types did not change it), 882DD6C8 (register assignment of all 8 saved registers), 883F5598 (7 off, register naming in
  `bank->used = n*0x90 + base`), 883EE2E8 (store/lfs scheduling of an inline ctor with self-linked node).

### agV round 2 (b157): 79-91 instructions (21 matches)
- 21 /O1 plain-route matches. 18 also match on LTCG; 883E9C28, 883F14E8 and 883F90E0 are plain only. None uses volatile.
- **A shared retire tail** (883DCC58): the error path `return 0x25` jumps into the unlink/relink code with r3 kept, and the normal path
  returns the argument. Write the tail as a static helper `retire(e, ret)` and call it from both returns.
- **A zero-initialised local array after an early return** (883D1B80): the target zeroes `int s[33]` only after the first read
  succeeds. Put `{ int s[33] = { 0 }; ... }` in a block after the first `if (r) return r;`. At function scope the memset moves to the top.
  The summed fields are emitted in reverse source order (target `s27+s25+...` = source `s[19] + ... + s[27]`).
- **Owner-select with one owner load** (883F8550): `Node *o = t->node; Bank *bk = owner_node(o) ? owner_node(o)->bank : o->bank;`
  The `o` local lets MSVC reuse the `+0xAC` load. Without it, the select re-reads `t->node`. 883F5598 (open) already had the local and is still off by registers.
- **Duplicated vcall in both arms tail-merged** (883E5FB0, open): the target calls `m->vt->set(m)` in both arms and shares the
  following `find` call, with the key loaded after the first call. if/else with a set local and inline-helper forms gave an extra saved
  register or the opposite block order.
- `x = j < lo || (state & 0x8000);` as an unsigned char gives the target's `li 0; beq; li 1` (883F6608). The `?:` chain gave `extrwi`.
- A parameter used in only one arm keeps its incoming register there (883C7CC0): declare `Node *t = n;` at the top of the
  function, so the `mr r30,r3` sits in the prologue, and use `n` itself in the arm that does not redirect.
- Inline error tails (883E4C60): repeat `{ if (owned) free(owned); destroy(s); return r; }` at each failure and let MSVC
  tail-merge them. gotos to shared labels lay the blocks out differently.
- Path-lookup family: 883DF370, 883DA1C8 and 883F99F8 (with 883F8EC0/883D80E0 from round 1) need the vcall item in a local
  (`Item *it = ITEM(n); return it->vt->f(it, ...)`) and the null-checked ITEM macro everywhere else.
- Not matched: 883CA160 (1 off, draft) and siblings 883C7A00/883C7B60 have the halfword `extrwi.` flag test (the 883C7278 class).
  8829DD30/8829DBD0 are GPU ring writers (sync/r13). 882E21B8 has the 0x8876086C relocation. 883D1DC0 (a local object with a vtable and two
  function-pointer arguments) was not tried.

### agU round 2 (b157): 15 matches; the 5 C++ accessors moved to drafts
- The member-function accessors (8841ED80, 8841F0D8, 886EBA80, 88443518, 88605DA0) match only as real C++ members. As C
  or as `extern "C"` C++, each one is 2-4 off: the base goes into r10 where the target uses r11. I tried a direct body, an
  `extern "C"` wrapper around an inline member, a reference parameter, an index helper, `__restrict`, pads 0-4, LTCG, /O1
  and /Ob1. The mangled name breaks C callers in the build, so they are now
  drafts/me_<ADDR>_nearmiss.cpp, which hold the matching member body.
- **/Os in the 0x885 range and on small helpers.** 8859F380 (a range-checked table read), 884FD970 (zeroing 8 floats per
  pass) and 883EEFA0 (bump allocator; it was a 2-off /Oc draft) all matched on /Os alone. When a small function is 1-5 off
  on /Oc with a branch-layout or move-order residue, try /Os before rewriting it.
- **Floats initialised from `g_ts4_event_value` match on the LTCG route only** (882744F0, 88277978, 88275858, 88636EA8).
  Use `extern float g_ts4_event_value; float z = g_ts4_event_value;` and store z. On the plain route the global is
  reloaded for each store, or an extra `fmr` appears.
- List items whose links point to +4 of each item: write `ITEM(l) ((l) ? (It *)((char *)(l) - 4) : 0)` and compare against
  `&s->head` as an item (8830BC78/8830BCD0).
- A table pointer computed once before a find loop (`Sub *sub = &o->sub;`) reproduces the target's early `addi r3,r4,X`
  (88523EE8). Indexing through `o->sub` each time does not.
- New near-miss draft: 88614900 (1 off, lwzx order). Open, 3 off: 884213B0/88421400 (per-character case helper; the `mr`
  lands before the test), 88516E38 (fmuls operand order), and 885E3968/885E39B0/885E60F0 (an assert-style range check
  with the failure branch placed first).

### agX (2026-11-19, b159): /O1 cr0 queue (agT todo3), 90-106 instructions (12 matches)
- 12 /O1 plain-route matches: 883DFE20, 883D4EB0, 883E7C98, 883DDEB0, 883F0308, 883DBEF8, 883DFF90, 882B1548, 882CE298
  (sibling of 882B1548 at 1.00), 883FFCF0, 883F75E8 and 883FA0A0. 883DFE20 is plain only; check the others' headers for LTCG. None uses volatile.
- **Inline ctor stores out of order: route one store through a pointer local** (agO trick). 883D4EB0: `{ int *pf = &e->fc; *pf = 0; }`
  inside a static ctor fixed the `li r9,0` vs vtable `addi` order. 883DFE20: `{ T **o = &it->owner; *o = t; }` fixed an owner store
  that was scheduled after the following list load. In the same function, the embedded list's self-link
  `{ Link *l = &s->list; l->next = l; l->prev = l; }` written last put the stores at the end, and `1.0f`/`0.0f` literals were needed (agV rule).
- **A signed ring-buffer wrap with a sign branch** (`add.; srawi; addze; bge; subfic; slwi; add` / `slwi; subf`, 883FFCF0): write a helper
  `x < 0 ? x + (1 - x / 4) * 4 : x - x / 4 * 4`. `% 4` gives the branch-free form, and the `>= 0` order swaps the blocks.
- **A duplicated probe block whose locals share stack slots** (883F75E8): write it as a macro with direct `return r;`. A static helper,
  even `__forceinline`, adds a merged result test after each use.
- A 64-bit position passed as two words via `std; lwz; lwz` (883E5900): use a union `{ u64 v; float f; int w[2]; }` and pass `w[0], w[1]`.
  Two such locals give the two stack slots the target uses (0x58 and 0x60).
- Optional object call with `clrrwi r3,r11,0` (883FA0A0): `if (t->ext) { r = t->ext->vt->write(t->ext, w); }`. A `W *e = t->ext` local
  gives a plain `lwz r3`, and an accessor helper is still 1 off.
- `memcmp(p, q, 0x400)` declared as `int memcmp(const void *, const void *, unsigned long)` is inlined to the byte loop with `cmpw` (882B1548).
  `unsigned long` keeps the host syntax check quiet. Declaring `Img *b = p->b, *a = p->a;` (b first) fixed an `xor` operand order.
- A copy loop that the target still guards with `cmplwi count,0` after an early `if (!count) return` (882AF4A8): move the loop into a
  static helper. MSVC then does not carry the known count into it.
- A word flag tested with `extrwi.` (883DBEF8) matched with the 883CC388 form `(unsigned char)((x >> n) & 1)`. The halfword +0x64 flag (bit 0x20)
  in 883CC668, 883C7E10, 883C9090, 883C9208, 883C8340/84C0/8640/87C0/8950, 883CC7D0, 883C9380, 883C76F0, 883C8180, 883C7F88, 883CA2A0 and 883C8D58
  is the open 883C7278 class, and I skipped those functions.
- Skipped, not plain-route: 883E7028 calls fn_883E6D98 with no argument setup and relies on fn_883E5F30 keeping r3/r4 (LTCG register
  knowledge). 882917C0/88291960 are D3D ring code (KeGetCurrentProcessType). 882D0F38 returns 0x8876086C (the false-relocation group).
- Near misses (drafts): 882AF4A8 (1 off: `add r31,r26,r31` operand order on the loop pointer), 883D3738 (2 off: lwzx order, the 883C75D0 class),
  883E5900 (2 off: 64-bit `x += d` operand order, on both routes).
- Open, more than 3 off: 883D38C8 (handle builder; registers r9/r10 swapped for the owner select, and the index local kept in r31 across a
  conditional call), 883DF1A0 (voice steal; a u64 stamp is copied twice through the stack, `std; lwz; std; lwz`, and copy-propagation folds
  every struct-copy form I tried; the final `if (r) return r; return 0;` also folds).

### agY (b160): the halfword `extrwi.` flag test is solved (17 matches)
- Rule: declare the +0x64 halfword as `short` (not `unsigned short`) and test the bit as
  `(unsigned char)(((unsigned)f >> 5) & 1)`, directly or in `static unsigned char is_grp(Node *n)`. This gives `lhz; extrwi. rX,rX,1,26`
  on /O1 and /Os. Measured on 883C7278 (/O1 and /Os):
  - `unsigned short` field: every form gives `rlwinm.` or `srwi; clrlwi.`. This includes `(unsigned char)((f>>5)&1)`, `(unsigned char)((f&0x20)>>5)`,
    `(unsigned char)(((unsigned)f>>5)&1)`, `(char)`/`(signed char)` casts, `(unsigned short)`/`(short)` casts and `== 1`.
  - `short` field: only the `(unsigned)` widening plus the `(unsigned char)` cast gives `extrwi.`. `(int)` widening, no widening, and
    char/short casts give `clrlwi.` or `rlwinm.`.
- Family 883C76F0..883CC7D0 (setters that redirect to the owner node when `deep`, then recurse into owned playing group items or
  list children). These details were needed:
  - Copy the parameter (`Node *n = self;`) so that n is in r28.
  - Test the list child as `PTR_INT(n->list->items) != 0 && n->list->items[i]` and pass `n->list->items[i]`. That form gives the
    `clrrwi r3,r10,0` and the cr6 compare. With an `it` local the compare is cr0 and the copy is missing.
  - Use if/else with the deep arm first.
  - 883C76F0 multiplies by the three unit labels. Write them as literals (0.25f, 0.020833334f, 0.041666668f) to fix the fmuls
    operand order, as at 883DF888.
- New drafts:
  - 883C9380 (1 off): lwzx order, the 883C75D0 class.
  - 883CA2A0 (15 off): needs LTCG with 883C9520 in context, because f11 survives the call. The level and the jitter
    swap f30/f31.
  - 883C8D58 (69 off): the shape of the busy pre-scan loop.

## agW (2026-11-19, b159/b160): whole-binary sweep, 6-21 instructions (40 matches)
- Candidate list: agU's cands.py/filt.py rebuilt against the b159 report, with agT todo3 and the agU open list excluded
  (scratchpad agW/c3.txt, 683 left). I worked smallest first through about 21 instructions. work/matching-b159 was deleted
  during the run, so the last third was checked against b160, and all 40 were re-verified on b160 (agW/ver.py).
- Flags: 27 /Oc and 13 /Os. Routes: 36 match on plain and LTCG, and 4 match on LTCG only (881CC958, 8840B570, 88481F60, 8847DB48).
  None uses volatile.
- **The checker does not compare names for unnamed callees.** A wrong `fn_XXXXXXXX` still reports MATCH. Work out every
  `b`/`bl` target from the address (agW/d.py prints them with symbols.txt names). I fixed two wrong names this way: 8857A8A0
  calls fn_88583188, and 8827D750 calls fn_88568A40.
- **/Os also works outside 0x885.** 882DE5F8 (vcall then memcpy) and 882C3950 (table scan) matched only on /Os, as did
  8856E7E0/8856E7B8 (frexp/ldexp-style exponent read/write through `*(unsigned short *)&x`), 88574C30 (`_unlock_fh`),
  885846A0, 8857A720/8857A8A0, 885E5600, 88569800 and 8856D820. If /Oc is 1-6 off in register naming or branch layout, run /Os next.
- **Tail call followed by a dead `blr`** (`b fn; blr`, with the return value preloaded before the test): write
  `int r = K; if (cond) r = fn(...); return r;` (8857A720, 8827D750). `if (!cond) return K; return fn(...);` lays out differently.
- **Hoist the index init above the count test** (88941C68, 881EE208): `if (r) { unsigned i = 0; if (r->n) for (; i < r->n; i++) ... }`
  gives the target's `li r7,0` before `cmplwi n`. Declaring `i` inside the for moves it below the test.
- **lwzx operand order through a vector struct pointer** (886CE120): `Vec *v = &g->items; v->first[i]` gives
  `lwzx r11,r30,r11`. `g->first[i]`, `i[g->first]` and an `at()` inline all gave the swapped operands. The same change did
  not fix 88464D78 (draft).
- A float clamp whose two arms share one `fmr` (88335BA8): `if (x < lo) x = lo; else if (x > hi) x = hi;`. The low branch
  jumps to the `fmr` with f0 still holding lo.
- `float` passed in a GPR slot (8840B9B0 family): a vcall wrapper that clobbers r4 with the function pointer has a float
  second parameter. Floats use f1 but still take a GPR position.
- A `long long` callee parameter shows up as `extsw` on the forwarded int (8836CE00). For `(signed char)c` to be
  extended after the extsw, the wrapper parameter must be `int`.
- Grouping changes fmuls order (884C0CF8): `(a * d * c * b * x) * K` matches; without the parentheses, K is multiplied first.
- 2x2 inverse 8898E050 (4 off, no draft): the four `x * inv` products come out as `inv * x` whatever the operand order,
  local declaration order or route.
- Near misses (drafts): 88464D78 (1 off, lwzx order), 886EDDF8 (1 off, cmplw operand order in a two-key find),
  884C9AC8 (2 off, r10/r11 naming; the clrrwi copy comes from calling a `&o->slots[i]` accessor twice), 884390B8 and
  884A5F20 (2 off, `mr r3` and `subi r4` swapped after a vcall), 889A4930 (2 off, register naming in the global chain).
- Open: the self-relative (-1 = null) offset family 888AF298/888AF448/88838808 (3-9 off), 884218C8/88421918 (case
  conversion with `extsb` before the store; the same class as 884213B0), 884C1A48 (stores through r3 and returns it, which looks like a C++
  struct return), and 888C00A0/8890C618 (vec4 store plus a dirty-bit `srd`).

### agZ (b161): index/base order of `lwzx` in loops that call (9 matches)
- Rule: in a loop that makes a call (the offset `i*4` is strength-reduced into a callee-saved register and the base is
  re-read every iteration), the operand order follows how the LAST source access to the element writes its base:
  - base written as a chain expression (`t->kids->items[i]`) gives `lwzx rD, rBASE, rOFF`;
  - base read into a named local inside the loop (`Node **it = t->kids->items; ... it[i]`) gives `lwzx rD, rOFF, rBASE`.
  When a test and a use are CSE'd into one load, the use (the later access) decides: chain test + `it[i]` use is
  index-first; `it[i]` test + chain use, or chain test + `Node *c = chain[i]`, is base-first. A use after a call is a
  separate load, so give each call its own block-scoped `it` (883D87A0, 883D9CA0). The local must be re-read inside
  the loop; hoisting it out of the loop drops the reload.
- Typical fixes: `if (n->list->items[i]) { Node **it = n->list->items; r = f(it[i]); ... }`; table finds
  `for (...) { Pair *p = t->items; if (cmp(p[i].name, key) == 0) return t->items[i].value; }` (/Oc).
- Measured in a harness (scratchpad agZ/h.py, /O1 and /Oc): index type, `i[a]`, `*(a+i)`, byte offsets, pads (dead,
  CSE, volatile, 0-8) and C++ `operator[]` make no difference; only the local vs the chain does.
- Not covered: leaf loops without calls (88614900 ctr loop, 88329478 no loop): the base local has no effect there. 883EA1F8
  (`add` for a 12-byte stride, then `lwz 8`): the loop-body base local, pads 0-9 and element locals all leave it 1 off.
- Matched: 883C75D0, 883CBB30, 883C9380, 883D3738, 883D86A0, 883D87A0, 883D9CA0 (/O1 and /Os), 885EEB50, 8841EA48,
  884DAF90 (/Oc).

## agAA (b163): callee audit

- The gap is real. `tools/fn_check.py` (and the objdiff report) mask relocated fields and treat a relocation
  symbol whose name differs from the target's as a rename. Changing the only callee in
  `me_advance_sequence_886A76F8.c` from `fn_8890FD00` to `fn_88400000` still gives
  `MATCH ... size 0xf0`, with only a `RENAME fn_8890FD00 -> fn_88400000` line. Treat any RENAME of an
  address-named symbol as a wrong callee.
- `tools/audit_callees.py --build work/matching-b163` reads each rebuilt plain-unit object (`MATCHING_UNITS`).
  For every REL24/REL14 relocation in a matched function, it compares the relocation symbol with the original
  branch target at the same offset. The symbol is resolved by full name in symbols.txt, else by its 8-hex
  suffix, else by its base name. The original target comes from `work/army/VX1/textdis.pkl`. It exits 1 on a
  mismatch. b163 result: 2613 objects, 32569 functions, 48174 branch relocations, **0 mismatches**. The 7534
  unresolved relocations are all save/restore-register helpers. It catches the injected wrong callee (rc=1).
- `tools/audit_datarefs.py --build work/matching-b163` does the same for REFHI/REFLO data references. For
  REFLO it expects `(S + signext(field)) & 0xFFFF` to equal the original low 16 bits (the `subi` form is
  negated). For REFHI it expects `ha(S + lo)` to equal the original `lis` immediate. Pooled `__real@`/`$LN`
  literals are not resolved. b163 result: 2613 objects, 109196 hi/lo relocations, **0 mismatches**, 478
  unresolved. Renaming `lbl_88D45B38` to `lbl_88D46000` in `me_append_new_state_8864AF28.c` still gives
  fn_check MATCH plus a RENAME line, but the audit reports the REFLO (rc=1). ADDR32 words in data sections
  are not checked yet.
- LTCG units (172 in `ltcg_units.json`) are skipped by both scripts. `tools/ltcg_route.py` writes their
  rebuilt object as the split target object with the verified code patched in, so its relocations carry the
  original names. `build_units` already fails a unit with any rename, so wrong names cannot pass that route.
- Run both after each full build; each takes about 2 s.

### agAB (b163): lwzx refinements, /O1 queue, small sweep (5 matches)
- agZ's loop-body local only gives index-first `lwzx` when nothing else in the function pins the order. In destructors
  that store the vtable first (884A7430, 8847AF38), a plain `it[i]` or `self->items[i]` both gave base-first. 884A7430
  matched with a TEST through the local followed by an element local: `Shared **it = self->items; if (it[i]->live) {
  Shared *s = it[i]; ... }`. 8847AF38 (element passed straight to a call, count re-read) stays 1 off: removing the
  vtable store flips it to index-first, so the store, not the loop, decides there. Draft: drafts/me_8847AF38_nearmiss.c.
- Two float constants compared after a call with the loads in the target's order (`lis` of 0.0 before 1.0, `lfs 0.0`
  before the field): declare them as block locals AFTER the call, 1.0 first, `float one = K1; float z = K0;` (883F45F0).
  Locals before the call, or 0.0 first, leave the lis or the lfs pair swapped.
- `if (r == 0) all = 0; else if (r == 2) {...}` gives `bne; li; b`; the target's `beq` to the clear comes from
  `if (r) { if (r == 2) {...} } else all = 0;` (883F45F0).
- A pointer-walk scan `lwz base; lwz 0(p); addi p,4` with the count test before the base load: write `i = 0; if (cnt > 0)
  { int *p = t->used; for (; i < cnt; i++, p++) if (*p) break; }` (883DD5E8). `for (...) if (t->used[i])` gives lwzx.
- Vcall argument order (vtable load before an `*ids` reload): the C function-pointer form loads the argument first, a C++
  virtual member call loads the vtable first (883DD5E8, now 1 off on a tail-merged return branch; draft .cpp).
- `r = 0` + `if (p->o) r = p->o->vt->f(p->o, 0); return r;` with `P *p = s->p;` gives `li r3,0; beqlr; clrrwi r3` and a
  dead `blr` after `bctr` (888386C0). A vector bounds-checked get through two inline helpers on `&s->v` (size and slot
  address) gives the clrrwi copy of begin and an index-first lwzx (88879168).
- (second run) A path walk that reassigns its node parameter got the target's callee-saved order only after copying the
  parameter into a local (`Node *t = node;`) and declaring the cursor before the start pointer (883D7F20, /O1).
- agZ's loop-body base local also works in a LEAF loop when the body stores through another pointer (the store forces
  the base reload like a call does): `unsigned *it = t->items; o->map[it[i] >> 8] = (unsigned char)it[i];` (88446198).
- Self-relative family: the `cmpwi` (not `cmplwi`) null test of the holder comes from an `int` field cast to a pointer
  (888AF448 7 off with that). The remaining diff is the target's add-then-select merge before one shared load; every
  C/C++ form tail-duplicates the load. 884C19A0: a chain of .rdata factors needs `/fp:precise` to keep the source order
  (1 fmuls operand swap left, draft).

## agAC (b163): the 0x8876086C false relocation is fixed in config (5 matches)
- Cause: 0x8876086C is the D3D HRESULT `D3DERR_INVALIDCALL` (`MAKE_D3DHRESULT(2156)` = 0x88760000 | 0x86C). The facility code
  0x876 makes it look like an address inside .text: it falls at fn_887607E0+0x8C (fn_887607E0 is 0x887607E0-0x88760BA0). Jeff's
  analysis takes every `lis/ori` pair that lands in a section as a pointer, so the split target carried REFHI/REFLO to
  fn_887607E0 where the compiler emits a plain constant. In the b163 split, every REFHI/REFLO to fn_887607E0 (14 objects in
  0x882B27AC-0x882E1F88, the D3DX-style texture helpers) is this constant. The real references (a REL24 call from 0x88761C3C
  and the .pdata entry) are branch or ADDR32 relocations and are kept. Other D3DERR values in these functions are odd
  (0x88760B59) or otherwise unaligned for code, and Jeff already drops those.
- Fix: `config/54540859/block_relocations.json` lists relocation targets that are constants. `tools/matching.py`
  (`write_jeff_config`) writes it into the Jeff config as `block_relocations: - target: ".text:0x8876086C"`, which Jeff
  already supports (`obj.blocked_relocation_targets`, checked in `analysis/tracker.rs`). If another HRESULT-shaped constant
  shows up as a relocation, add its address there rather than writing the constant as a function address in source.
- Build before and after with no new units: 32825 and 32825, with the same set of matched functions (compared per function in
  report.json). With the 5 new units integrated: 32830, and audit_callees and audit_datarefs both report 0 mismatches.
- Matches: 882DD5F0, 882C5EA8, 882C5FC8, 882D0F38 (/O1 plain) and 882DDD58 (/O1 LTCG + fk2_o1_000.c, agT's draft unchanged).
  - 882C5EA8/882C5FC8: a stack loader object with ctor/dtor calls. Write the dtor call before every `return` (C++ scope-exit
    style), and `fl = 1; if (src == dst) fl = 0x10001;`. The frame layout depends on local sizes: the 882AA058 descriptor must be
    0x48 bytes. At 0x40 it is placed before the 0x60 Info block in 882C5FC8.
  - 882D0F38: the S_OK block must come before the E_FAIL block. Flat gotos, `if (!(a||b||..)) goto fail`, do/while+break and a
    ternary all give E_FAIL first. What works is nesting:
    `if (c->in && (c->out = make(out)) != 0) { r = seq(); if (r < 0) goto done; if (a>=0 || ... ) { r = 0; goto done; } } r = E_FAIL; done:`.
- Left open (drafts): 882C73D8 (2 off: `li r3,0` and `stw res,0(out)` are in the opposite order, on plain and LTCG; I tried
  r/hr locals, volatile, a comma expression, gotos and a Detach-style clear), and 882E21B8 (66 off: the target puts the else path
  (fn_882DD1B8) and the 0x88760B59 return after the epilogue; source order, gotos and inverted tests did not move it).
- (third run) Self-relative (-1 = null) resolves: write the inline helper as `p = 0; if (off != -1) p = base + off;
  return p;` (li 0 before the test), not a ternary or early return. This matched 8883B2B8 and 88838808; the element
  address goes inside the helper as `(char *)t + (i * stride + t->off)` with the caller's `r = 0; if (i < n) r = at(t, i);`.
  888AF298/888AF448 stay open (5 off) because the target computes the add before the -1 test.
- A 2-bit field tested with `extrwi rX,rX,2,10; addi 0; cntlzw` is a bitfield after 10 bits, read in each branch, and
  `0 == m` (8859AD10, /O1).
- An `extern` float stored in a loop is not hoisted; a `0.0f` literal is (88397970, /Oc).
- A ternary pick of a struct pointer passed straight to a call: put the pick in an inline helper with an early
  return (8875E080/8875E0C8).

## agAD (b164): counted-copy size reuse solved (5 matches)
- **Rule: MSVC CSEs expressions by source operand, not by loaded value.** In vector operator= the size must be
  `unsigned n = l - rhs->first;` (locals `f = rhs->first`, `l = rhs->last` loaded first), and the shrink-branch copy must be
  `copy(f, rhs->last, self->first)` and the overlap copy `copy(f, rhs->first + (self->last - self->first), self->first)`.
  Then the target's second `subf; divw.` and the unfolded `mulli; subf; add; divw.` count both appear. Writing the same
  pointer as a local in one place and as `rhs->x` in another is what stops the CSE. The loads still merge into one register.
- Counted copy loop: `for (n = l - f; 0 < n; --n, ++f, ++d) assign(d, f);` (`++f` before `++d`, which fixes the swapped addi pair).
- Grow-branch uninitialised copy, where the target iterates over the source and tests `add. r3, delta, f`: write it open, with its own
  loop variable, so that `d` is derived:
  `{ const Item *s; for (s = f; s != l; ++s) { Item *d = (Item *)(((char *)nb - (char *)f) + (char *)s); if (d) cons(d, s); } }`.
  The inline `ucopy(f, l, nb)` makes d the induction variable, which costs an extra saved register and moves the whole frame. Keep the inline ucopy
  for the third branch (`ucopy(rhs->first + size, rhs->last, self->last)`).
- Matched: 88218E08 (56-byte item), 881B7FB0 (12-byte, range-destroy call `fn(first,last)`), 8816E038 (12-byte, the construct takes
  `s->w[0]`), 881AE140 (44-byte POD: `*d = *s` memcpy and an out-of-line assign `fn_881AF6E8(f, l, d)`, no destroy). All /Oc plain.
  Generator: scratchpad agAD/gen.py `build(addr)` (it picks the callees from textdis and symbols.txt, and detects a range destroy and a
  word-arg construct). scan.py runs it over the family.
- Left: drafts/me_882867E0_nearmiss.c (20-byte item, out-of-line ucopy, 67 off). The shrink-branch copy loop gets a +0x10 IV
  offset (addi/subi r4) where the target indexes f directly. Its third-branch copy does use the offset, so the two copies are scheduled differently.
- 8822AFE8 constant group (888E1FC0, 887011A8, 88770288, 886FC638): 8822AFE8 is `void f(Handle *h, const u32 *value)`.
  It loads h->f0 and h->f4 and calls vtable slot 10 with (obj, h, f4, 4), then stores `*value` to the returned pointer. The prototype is
  right, so the r4/r5 difference is not an argument-order problem. These had no effect: by-value inline helpers (`put_u32(p, 4)`, which moves
  the store after the call), C++ `const u32 &` temporaries for both the key and the value, the count argument as u8/short/int/
  pointer/u64 or a variable, comma expressions in any argument position, the value in an escaped array with the keys, an
  early `u32 *pv = &v`, and the flags /Ou /Ot /Ox /O2 /Oi- /Oy- /GS- /Gy /fp:strict. Declaration and statement order do change the result
  (887011A8 goes from 3 to 7 off) but never reach 0.
- (fourth run, b165) A count-guarded pointer walk with the base loaded after the guard, `i = 0; if (n > 0) { p = base;
  for (; i < n; i++, p++) ... }`, matched 883C6E90. A countdown ctr loop with a decrementing offset is `while (i) { i--; ...
  a[i] ... }` (88411FE8). Pointer-vector finds want the end hoisted into a local and compared `end != it`, with an `r = 0`
  result and `break` (88803198). A handle re-test after the find (clrrwi copy) is an inline release helper on `&o->sub`
  (8883DD48). `!=` vs `==` operand order on cmplw/subf follows the written order: `owner->root == top` (883E2E78).

### agAB round 5 (b166)

- `/O1` signature check: `cmpwi rX,0` on cr0 plus test-at-top loop entry; retry with `/O1` before reshaping source (883FDBB8, 884F8A90, 8858A668).
- Keyed find over fixed-stride entries that returns a field: a plain `for (i = 0; i < t->n; i++) if (key == t->arr[i].k) return t->arr[i].v; return 0;` matches; hoisting `n`/`arr` into locals does not (887788F0).
- Owner-path branch that skips a null test (883C66E8, sibling 883C6740 at +0x18) stays 1 off with plain if/else; unresolved.

### agAD round 2 (b166): 3 matches
- 882907D8/88290830, which pack the low bytes of the x/y/z words into `0x00ZZYYXX` device registers: the `rlwimi` came from byte-typed struct fields.
  Read u32 words (`(c->z & 0xff) << 16 | (c->y & 0xff) << 8 | (c->x & 0xff)`); that gives `rotlwi; or; slwi; or`. They then
  match only on **/O1**, because /Oc chains the ORs through fresh registers (8 off).
- 882E21B8 (block layout, agAC): the target shares one `return 0x88760B59` block between the `off == 0` test and the `r == 1` test.
  Write the raw (`== 0x102A1100`) branch first, with `goto bad;` in both arms and `bad: return (int)0x88760B59;` after
  `return 0;`. That moves the fn_882DD1B8 arm after the epilogue. The size-before-data order then needed a pointer local:
  `const char *p = (const char *)src + off; data = (char *)p + 4; raw = 1; res->size = *(const unsigned *)p;`.
- 882C73D8 is still 2 off (`li r3,0` against `stw res,0(out)`). These had no effect: a pointer-local store on `*out`, `return 0` against `r = 0`,
  `long`, /Os /O2 /Ob0 /Ob1, a D3DX-style `goto fail` with or without an `if (res)` cleanup (that one is larger), and a `goto ok` that skips the tag test.
- 883FA998 (/O1 queue, a stream reader): the body matches except for two byte-swap cases (mode 0/1) that the target keeps apart with different
  OR orders and a shared tail store. MSVC merges identical unsigned swaps in all 24x24 macro operand orders. An `int` view
  splits the cases but gives `srawi`. Draft: drafts/me_883FA998_nearmiss.c (36 off).

### agAD round 3 (b167): /O1 queue, 3 matches
- Matched (/O1 plain, keeping the fn_ names): 883EB800 and 883EB9F8 (section readers: an 'hmht'/'hnlt' header via fn_883E7828, a u16 count, a 0x18-byte
  lookup with an inline ctor, entry arrays with inline vtable ctors, then a per-entry header loop), 883F2390 (three nested
  intrusive lists, `l ? (T *)((char *)l - 4) : 0`, the probe body written out twice with its own block locals so the stack slots differ).
  In 883EA6C0 (draft) the reference holder at 0x50 is `Ref {vt, pad, p}`, and the error path releases `p` without the vtable store.
- File label 0x8803A020 is not in symbols.txt, but `extern const char lbl_8803A020[]` is accepted by the checker.
- New drafts: 883EAF78 (only stack slots differ: n/items below the header, and 0x10 bytes of frame missing), 883EA6C0 (6 off: `ref.p`
  is loaded into r3 and then copied to r30), 883D90A8 (1 off: `lwzx` order in a call-free inner loop, which agZ's local/chain rule does not cover),
  883DC438 (the target keeps the repeated `-1, -1` arguments in a callee-saved register; `int any = -1` gets propagated).

### agAB round 6 (b167)

- Bool written through `r3` with args shifted one slot (`stb rX,0(r3)`): write `void f(unsigned char *out, ...)` and
  store 0/1 on each path; a guarded `do { } while (p[i])` gives the top `lbz; beq` plus bottom test (0x88421968).
- In-place char loops whose store is unconditional with an `extsb` of the original byte: an inline
  `static __inline char conv(char c) { if (lo <= c && c <= hi) return c +/- 0x20; return c; }` called as
  `buf[i] = conv(buf[i])` matches; a local `char c` with a conditional or unconditional store does not (0x884218C8, 0x88421918).
- Hand-scheduled float code with single loads despite in-place output: `__restrict` on both pointers, source order of
  stores as in target (2x2 inverse 0x8898E050). Per-element locals give the wrong register order.
- Float-to-int with `fctidz` + `lwz -0xc(r1)` is an unsigned conversion; `fctiwz` is signed. f0 reused everywhere
  points to /O1 (0x8859BB40).
- Dispatch on a selector compared with `cmplwi` and the clrrwi copy: pointer-typed selector, identity inline accessor
  per call, /O1 (0x885CEFC8, 0x885CF028).
- Self-relative holder compared with `cmpwi` (signed): the holder field is an int offset/address; resolve with a ternary
  `*(int *)o != -1 ? (R *)(*(int *)o + o) : 0` (0x888AF448).

### agAD round 4 (b169): 1 match, 4 drafts
- **Check every data label against the target's lis/addi.** 0x88040000 - 0x65E0 is 0x88039A20, not 0x8803A020. objdiff does not flag a wrong
  data label, but the data-ref audit does.
- 882B4340 (pixel-converter init, /O1) matched with nested success ifs: `c->src = f(src); if (c->src) { c->dst = f(dst); if (c->dst) {...
  goto done;} } msg = lbl_88001B38; fail: trace(msg); ...`. A `mr. r4, r3` on a store means the value is also the next call's r4:
  fn_882B6DB8 takes `(src, dst)`, not just `(src)`. The ten back-end tries are one `||` chain.
- Drafts: 883E6D98 (8 off, prev and the stream-vtable local get swapped callee-saved registers; `u64 sz = size(); end = start + sz;` fixed
  the add order), 88290D58 (state-block bind: logic matches, register allocation does not; the packet is a bitfield `{b0:1, b1:1, addr:30}`
  with `addr = ptr >> 2`), 883ED860 (queue insert with inline list helpers; register order and a tail merge), 883DD338 (request post:
  44 off; the shared unlock/return block is placed after the 0x25 path in the target).

## agAD round 5

- 88384A00 (/Oc) matched: a flag-bit check written as `static __inline unsigned char f(const T *r){return (unsigned char)((r->flags>>1)&1);}` gives the `extrwi` form. Writing every early exit as its own `{ *out = 1; return 0; }` block gives the duplicated exit blocks.
- 883EEEA8 (pool free) is not solved; the best attempt is 16 instructions off under /O1. The target computes the `inside` byte with `clrlwi.` (a record form) and sets `li r6,0` before the branch. Our build tests it with `cmplwi cr6` instead. The `free(a ? vt : heap)` inline helper got the shape closest.

### agAB round 7 (b169)

- Bit-array writer loops (`stwx` of `(w & ~(1<<b)) | ((v&1)<<b)` with `li rX,1` re-materialised each pass): an inline
  per-bit setter in a `do { } while (--n)` loop on /O1; /Oc hoists the constant and saves r31 (0x88290718, 0x88290778).
- Callback with a shared fallback returning 0 (`li r3,0` first, `beqlr` exits): `int r = 0; if (a) r = f(); else if (b)
  r = g(); return r;`; early `return`s give a different layout (0x883202A0).
- Unit-conversion getters `switch (unit) { case n: k = lbl; }` then one shared `fmuls`: /O1 stops the tail duplication,
  but the f0/f13 roles stay swapped (0x883DF940, 0x883CA750; open).
- Data labels: run a check after every match that names a `lbl_`: the address is in symbols.txt and the target has
  `lis ha(addr)` plus the matching low half. objdiff MATCH does not compare relocation targets.

## agAE (b169): medium sweep from agAD's r5 list (14 matches, 1 draft)
- **/O1 first for list walkers and small leaf finds.** 882DDA00, 883E4F58, 883D3C60, 883D2348, 883D3D10, 883FD5C0, 883F1340,
  883DBBA0 and 882CDCD8 all matched on /O1 after /Oc was 20-35 off. /Oc matches: 88378F68, 88323BA0, 8830B840, 88384918, 88322EB0.
- **The `l ? (T *)((char *)l - 4) : 0` result of an inline "nth" helper:** when every failure path shares one `li r11,0`
  block, write the helper's tail as `if (l) return (T *)((char *)l - 4); return 0;`. The ternary goes branchless
  (`subfic; subfe; and`) (883D2348). Write the countdown to the index as `for (; index > 0; index--)` (mtctr + bdnz).
- **Rotated find loop, where the body tests the bound and the bottom tests the sentinel:** `for (k = head->next; k != head; k = k->next, i++) if (i >= idx) break;`
  followed by `if (k == head) return err;` (883FD5C0).
- **Two induction registers swapped (count and walk pointer):** move the walk pointer into a fresh block-local
  (`{ Node **q = p; for (i = n; i > 0; i--, q++) ... }`). That flips the allocation order (883DBBA0, 7 off to 0).
- **A byte-compare loop on `cmpw` (signed) pointers with `subf.` is the memcmp intrinsic**: `#pragma intrinsic(memcmp)` +
  `memcmp(a, b, 16)`. Hand-written loops give cmplw or get unrolled (8836E4D0).
- **Pixel box filters (882CDCD8):** use separate row pointers `p`/`n` (`n = src + pitch`) and recompute rowEnd in the row loop
  (`rowEnd = src + width*4` inside the loop). The increment order in the for header decides the order of the bottom adds: `dst += dstPitch, src += 2*pitch`.
  Lane sums need `unsigned` (`(unsigned)(x) & mask`), or `>>` becomes srawi.
- **Flag set/clear inline:** `if (!v) f |= 2; else f &= ~2u;` gives the target's `ori` preload and then conditional `rlwinm` (88384918).
  The ternary and the explicit-local forms are worse.
- **A hoisted `li r3,0` ahead of `if (outCount)` stores**: write `if (!outCount) return 0; *outCount = n; return 0;` (88322EB0).
- Unsolved: 8836F5C8 (bswap: OR-chain order 11 off. The macro operand order has no effect, and an inline swap drops the intermediate store),
  88329C00 (strstr: the target iterates the haystack pointer), 88359B78 (fader: `rotlwi`/`clrrwi` copies not reproduced),
  882CDE48/882CDF48 (16-bit box filters: body matches, prologue load order h/pitch and src/dst does not), 883A3000 (pool alloc:
  the target folds the +0x10 `used` offset into the loop pointer), 88385498 (sibling of 88384A00: 8 off in the scheduling of the second copy), 88329A88
  (atoi from the right: the target keeps two saved registers, std/ld rather than savegprlr).

## agAF (b170): small sweep, 15-40 instructions (23 matches)

- **Retry every near-miss draft on /O1 before reshaping it.** 885AA050/885AA168 (agAB's 2-off draft, vtable slot in r10 vs r11)
  and 883E5F30 (2 off, `add` operand order) both matched unchanged or nearly so on /O1. For 883E5F30 the length local goes
  first and the end is `a->start + len` after the start store.
- **Read the label's bytes before writing a float constant.** The unit getters 883CA750/883DF940 multiply by 4, 48 and 24
  (not 1/4, 1/48, 1/24 as in the 883C76F0 setters). Literals with the right values match on /O1, with the f0/f13 roles right;
  `extern` labels leave the roles swapped. Read with `scratchpad/gp8/img.py` (`img.f32(addr)`).
- In-place string case loops that return `s` (884213B0, 88421400): declare the walk pointer inside `if (*s) { char *p = s; do ... }`
  so the test comes before the `mr`.
- A struct returned through a hidden pointer that the caller discards (88837FB0, a Lua `{script, top}` ref): declare the callee
  as `Ref *f(Ref *out, Obj *o)` and pass `&local`. The by-value C form returns in registers and drops the frame slot.
- A vtable call whose argument is another vtable call (884D7A38) loads the outer `s->vt` first (into a saved register) only when
  the inner call is written inside the argument list. A `vt` or result local moves it.
- `r = 0; for (...) if (match) { r = items[i]; break; } return r;` gives `li r3,0` before the count test and the `blelr` exit
  (88923BE0); `return items[i]` inside the loop does not.
- A 64-bit probe index (`mulld`, `extsw` of an int mask, `clrrwi rN,i,0` per probe) is an `unsigned __int64` variable narrowed at
  each use: `slots[(unsigned int)i]`, `return (unsigned int)i` (88423A78).
- An inline byte compare with `subf.` and a `cntlzw`-free 1/0 select is `#pragma intrinsic(memcmp)` (88162C60).
- A count-guarded inner pointer walk that starts at `row + 1`: `j = 1; if (j < m) { p = rows[i] + 1; for (; j < m; j++, p++) ... }`
  (8837E640, agAD's fourth-run rule applied to an inner loop).
- A store that the target emits before two loads of the same object (88771CB0, `stb` of the dirty byte before begin/end):
  agO's block-local pointer store fixed it.
- Lazy import trampolines (884F4630, 884F7D18): `if (!g) resolve(ord, &g); if (g) return g(a, b); return 0x80004005;` on /O1.
- Open: 888C00A0/8890C618 (`srwi` shift count; 15 forms of the count all give `rldicl`), 88421338 (strlen with the trailing
  `clrrwi r3` copy; 12 forms), 886EDDF8 and 887F7678 (cmplw operand order), 889A4930 (r11 reuse down a global chain;
  inline accessors don't help), 888C2C80, 888C4EE0, 883F9D78, 8851EC30 (unchanged by /O1, /Os, /O2 or /Oy-).
  885928D8 (6 off on /Oc: an inline `(unsigned char)w->mode` accessor gives the extrwi, but each tail gets fresh registers
  where the target reuses r11), 883C9BD8/883C9F98 (4 off on /O1: the owner-ternary null tests are cr0 where the target has cr6),
  887CF490 (8 off, register swap), 88772BA8 (the target keeps the hash constant in r29), 884281A0, 881A9968, 88933AB8
  (the target does not fold the +0x20 array base into the index), 88425670 (3x3 transpose: `__restrict` hoists all loads, no
  restrict reloads).
- Draft: drafts/me_88439050_nearmiss.c (3 off, final-call argument order, likely a C++ base cast; sibling 884A5EB8).

### agAE round 2 (b171): 21 matches, 1 draft
- Matched (/Oc unless noted): 88331AF8, 8835A848, 8832BFF0, 883E1DD0 (/O1), 883E2598, 883E2428, 883E24D8, 88322BF8, 88331E10,
  88330968, 883290D0, 88334648, 88334700, 88329D20, 8831D7E0, 8839CA60, 88346598, 883FA8C8 (/O1), 883E0960 (/O1), 88359310, 88322CA8.
- **Switch block order follows the case order in the source.** If the target puts the table/default case last, write it last
  (`case 1: ... case 2: ... case 0: case 3:`) (8835A848).
- **`x ? a - x : 0` against `x == 0 ? 0 : a - x`** decides which arm falls through (88346598). The same holds for a ternary max that reloads
  both fields in its arms: write it inline on the struct fields, `p->s->b < p->s->a ? p->s->a : p->s->b`. A local pointer CSEs the reload (8831D7E0).
- **"Walk to the root" inline:** `Timer *p = t->parent; if (!p) return t; while (p->parent) p = p->parent; return p;` (883E1DD0).
- **A do-while list walk that visits the owner and then its children**, with the LINK of the sentinel as the end, gives the
  `cmplwi r29; addi r11, r30, 0x74` pattern (883E2598, 883E2428 and 883E24D8 share one template, differing only in the float argument count).
- **Optional-allocator free:** `static __inline void heap_free(Allocator *a, void *p, file, line) { if (a) a->vt->free(...); else fn_88315F10(heap, ...); }`
  needs /O1 (883FA8C8).
- **Stores into a static descriptor follow the source statement order**, so match the target's store sequence exactly (88359310).
- `% n` on a signed int with /O1 brings in MSVC's `twi 5` / `twllei` trap checks automatically (883E0960, a shuffle).
- `(d < 2) ? 0x24 : 0xb` compiles to `subfc; subfe; clrlwi 27; rlwinm 0,31,28; addi 0xb`. Read the error codes off the rlwinm mask (88322CA8).
- Draft: drafts/me_88365560_nearmiss.c (vibrato step, 1 instruction: a join `clrlwi`). The family uses one template: 88361168, 88365328
  (`>>7<<2`), 88368958, 88361248, 88359EA0 and 88359FB0 (tremolo/pan variants, out +0x1DC/+0x264, clamped 0..0x40).
- Unsolved: 8836E420 (vtable submit loop, 6 off from argument-load scheduling), 883F1888 (index-or-first-flagged lookup, the shared LINK
  tail), 88353138 (PCM sign/endian fix, register order), 883E50B0 (a C++ move with a stack temporary), 8838B5F8 (tree insert, not attempted).

### agAE round 3 (b173): 10 matches
- **Try plain /O2, the base flags with no /Oc, as well.** 883C00E0 (kiss_fft `kf_factor`) matches only there: /Oc drops the `twi`
  divide-overflow traps and /O1 rotates the `while (n % p)` loop. The spec uses `"flags": ["/O2"]`. The kiss_fft code near 883C0xxx probably
  needs it too. `floor((float)sqrt((double)n))` with `#pragma intrinsic(sqrt)` gives `fcfid; fsqrts; bl floor`.
- **Plugin-descriptor initialisers (memset of a static block, then stores of label and thunk addresses)** can be generated:
  scratchpad agAE/pd.py builds the C from the target's lis/addi/li/stw sequence (the descriptor is a `unsigned int w[N]` array, the thunks
  are cast to `unsigned int`), and pdt.py greedily swaps adjacent stores until it matches. The source order is the target's store order
  with two adjacent pairs swapped. Matched: 88360D38, 883687E8, 8836B2E8, 883651A0, 88373888, 88382FB0 (0xAC bytes).
- Vibrato family (88365560, 88365328, ...): **declaring the wave inline as `int` rather than `unsigned char`** produces the missing join
  `clrlwi`. They are still 5 lines off, all registers (r9/r7 against r7/r6 in the position advance). The draft has been updated.
- 883E2390 (timer-tree member with an int key argument) is 4 off: the key and the sentinel get swapped callee-saved registers. 883DA348 (item at index
  through an indirect list `g->list->items`) matched on /O1. The direct-list sibling 883F9B68 is 13 off because head->next gets CSE'd.
- 88330A18 (sibling of 88330968: reserve sizes per cache slot, two ternary maxes) /Oc.

### agAF round 2 (b173): 11 matches
- `return 0 == flag;` (not `!flag` or `flag == 0`) gives the `addi rX,rX,0` before `cntlzw` in a bool return (88606108; agAB's
  8859AD10 rule holds outside bitfields too).
- A `switch` on a byte field compares with `cmplwi`; copy it into an `int` local first to get `cmpwi` (8854D7F8). A `(int)` cast
  in the switch does not help.
- Locked call returning `ok ? 0 : E_OUTOFMEMORY` (subic/subfe/and after the unlock): compute the HRESULT into a local before the
  unlock call, on /O1 (88595218, 885A63C8).
- Bounds-checked vector element update with end-first size loads and a `clrrwi` copy of begin: inline `vsize(&t->v)` and
  `vat(&t->v, i)` helpers on an embedded `{begin, end}` (88838500).
- Lexicographic float compare through an out byte: each early true is its own `{ *out = 1; return; }` (8855A9C0).
- Binary halving on 4-byte entries `while (last - first > 16) { mid = first + ((last - first) >> 1); ... }` gives the
  `clrrwi 2`/`srawi 3` pair with no `addze` (885450F0).
- Float returns with .rdata 1.0/0.0/-1.0 labels match as literals (884C0E78).
- Open, three times in this sweep: the target keeps a 32-bit hash constant in a callee-saved register across a call or loop
  (88772BA8 r29, 88718210 r30). A plain or const local, an inline wrapper, /O1, /Os and LTCG all re-materialise it with lis/ori.
- Open, argument-register order before a call (target sets the earlier argument first): 88439050/884A5EB8 (C and C++, base cast),
  887CCB00 (vcall `destroy(o, 1)`; draft .cpp), 887A1A80 (`memcpy(d, s, 12)` with `#pragma function(memcpy)`, inline wrapper,
  C++). 8816B1C8/88890E30 need a `clrrwi r3` copy of the lbl_88D45B38 registry; identity inlines and casts don't produce it.
  88662510/88662458: only the order of `lwz t->ctx` vs the INT_MAX `lis` differs. 883C9BD8/883C9F98 and 885928D8/88592878:
  no new progress.

## agAG (b174): medium sweep, 40-70 instructions (14 matches, 1 draft)
- **The b174 report.json has no per-function fuzzy_match_percent for unmatched code** (only sections and matched functions carry it),
  so the 85-100 band cannot be built from it. This sweep took unmatched `fn_` entries of 40-70 instructions, skipped drafts and
  addresses already in this file, and ranked leaf integer functions first (no bl/bctrl/float ops). The previous agent's c1.py printed only the
  last 3000 characters of the diff, so its `grep -c '^\*'` undercounts when the diff is early in the function. It now prints 20000. Check with `head -2` for `MATCH`.
- Matched (/Oc unless noted): 88165650 (strcpy+3x strcat intrinsics), 881ABC10 (u32 find, 4x unrolled), 881AFD98/881AFE60
  (list merge, inline _Splice), 882348F0/8816BA20 (string compare), 88258910/88269028 (insertion sort), 882694D0 (clears two vectors),
  88280428 (vector resize), 88289770 (/O1, texture fetch dims), 883159F0 (bitmap free run), 8837D2D8 (plane rows), 88421120 (stricmp).
- **std::string compare against a C string**: `n2 = strlen(p); n1 = last - first; r = memcmp(first, p, *min_ref(&n2, &n1));` with
  `min_ref` returning `const int *` (`*a < *b ? a : b`). That gives the two stack slots and the `subi r9,r1,0x10` pick. Then
  `if (r) return r; if (n1 < n2) return -1; return n2 < n1;`. The `== 0` wrapper (8816BA20) takes `const char *const *`.
- **Dinkumware _Insertion_sort on 8-byte pairs** (88258910 desc, 88269028 asc): the else branch takes its **own** `Pair v = *next;`
  (the target has a second `ld` and stack spill) and declares `next1 = next` there. The if branch is `copy_backward(first, next, next + 1)`
  with a counted `*--dest = *--last` loop.
- **std::list merge without a size field** (881AFD98/881AFE60): write `_Splice(where, first, last)` inline with the `where != last` guard.
  The first branch is `if (first2->key < first1->key) { mid = first2->next; splice; first2 = mid; } else first1 = first1->next;`.
  The two-key sibling 881AFCA0 is open: the target keeps two separate `subfc/eqv` tails for the major and minor compares, and the six pred forms tried all merge them.
- **vector erase(begin, end) or resize-shrink of POD** keeps the counted copy loop even though the count is always zero:
  `v->last = copy(v->last, v->last, v->first + n)` (the `subf r8,r11,r11`). Grep `subf r8, r11, r11` to find more. 88158BB8 and 88158C70
  are already in cx21_core_b.c.
- A loop whose first test is `count > 0` folded in (`cmpwi r6,0` before the bounds tests, with no separate branch) is `while (run < count && ...)`,
  where run starts at 0. Declaration order decides the order of the `li` and `srawi` at the top (883159F0: `run` first).
- Unsigned (`cmpwi` on `and`) vs int: a bit-mask local tested with `cmpwi` is `int` (883159F0).
- Args narrowed with `extsh` at entry, followed by dead `mr` copies, are `int` parameters stored through `(short)` casts. `*cursor = *cursor + p->pitch`
  gives the `add r10, pitch, cursor` operand order (8837D2D8).
- Open:
  - 88150940/881509F8/882736E8 (64-bit key hash `<=`/`==`): all the code matches, but the two operands' register sets are mirrored. Statement order, locals and `!`/swapped forms have no effect.
  - 88168F08 (char) and 881AC348 (u16) std::search: the target keeps first1 in r3. 38 off.
  - 88214C20 (char find) and 88165170 (u32 find): count-switch tail compare order. Draft drafts/me_88165170_nearmiss.c is 3 off. 881ABC10 has the same source and matches.
  - 88286638/88286700 (64-bit bitfield struct copy): the target reloads src and keeps `mr` copies of each stored dword.
  - 88322D80 (unlink three lists, relink into owner+0x2e8): 33 off. `head = q ? &o->queue.head : 0` (test on q, add from o) fixed the tail.
    What is left is the register order of the shared 0/-1 constants and a `clrrwi` copy of `head->next`.
  - 884021E0 (three flag-array scans into an out byte): the target keeps a shared zero in r6 (`mr` copies for every counter). /O1 /Os /Ox have no effect.
  - 88421208 (strnicmp): only the prologue `mr r7,r4` and the increment order differ.
  - 8843B300 (ptr-array remove plus release): the target hoists the count in the find loop but reloads it for the remove.

## agAH (b174): small sweep, 15-40 instructions (20 matches, 1 draft)
- Matched (/Oc unless noted): 887F7248, 887F7368, 887FB120, 88941E20, 882890A8 (/Os), 883D4890 (/O1), 88472AF0, 884D4BD8,
  884BDD10, 884CDCC8, 88517488, 8854D9B0, 88592188 (/O1), 8863A780, 886ED8E0, 886ED7F0, 88942370, 88954A38, 8899CD48, 8831F560.
- **Try /Os when a constant multiply or divide stays as `mulli`/`divw` with the constant in a register.** 882890A8 (EDRAM tile count,
  `(w + 79) / 80 * 80`) matches only on /Os; /Oc strength-reduces the `* 80` into shifts and adds.
- **Vector-of-children loops with index-first `lwzx`:** an inline `vsize(&o->v)` on an embedded `{begin, end}` in the count, then
  `Item *it = o->v.begin[i]` in the body (887F7248, 887F7368, 887FB120). An explicit `Vec *v` local gives the same 1-off as a plain chain.
- **`stbu` with offsets 7/8 and stride 8 is a struct-array field access, not a byte walk.** Read the stride off the update form: 884BDD10
  byte-swaps the u16 at +2 of 8-byte entries, then a run of u16 words. Use `Entry { unsigned char b[8]; }` and `t->e[i].b[2]`; byte-pointer
  loops never give the `subi base,1` start.
- **Self-relative `{first, count}` tables** (8863A780, 88942370): inline `begin`/`end` as `Ent *e = 0; if (t->first != -1) e = ...; return e;`
  (`li 0` preload, not a ternary), and write the loop test `end != e` when the target compares `cmplw end, e`. A found-result
  local (`r = e; break;`) gives the `li r3,0` at the top. With a global table, call each inline on `&g->tab` directly; a `Tab *` local changes the layout.
- **A redundant arm in a hash-to-enum chain** (886ED8E0): `r = 1; ... else if (h == B) r = 1;` is what makes the target's separate
  `li r3,1; blr` block for B. A switch or a merged `||` drops it.
- **Tail recursion folded into a loop with a jump into the middle** (88517488, bisection): the inline search must compute `mid` before the loop
  and again at the bottom of each pass. Each branch then gets its own `add` and jumps to the `srawi`.
- **Vtable-then-temporary order** (884CDCC8): `n->vt->set(n, make_temp(&v, src))` written inline loads the vtable before the temporary call in C.
  Hoisting `vt` into a local adds frame.
- `unsigned char ok = 0 != t->owner; if (!ok) return ok;` gives `addi; subic; subfe; clrlwi; cmplwi` for a bool guard (88941E20).
- An inline owner accessor (`owner_of(t->items[i])`) loads the item straight into r4 for `f(item->owner, item)` tail calls (883D4890,
  index sibling of 883D4900).
- Hoisting both counts into locals turns nested copy loops into `subic.`/`mtctr` countdowns (8899CD48).
- Draft: drafts/me_8848E4F8_nearmiss.c (1 off: the second of two reverse loops wants index-first lwzx; locals, embedded arrays, inline
  accessors, block counters and C++ all give base-first).
- Unsolved: 88924250 and 881518D0 (binary searches, 6 and 16 off, register naming only: the target's `addze` writes a fresh register);
  88922F78 (5-hash type check plus self-relative u16, r10/r11 swapped); 8827DBF0 (vcall dispatch until handled, 9 off: params
  get callee-saved registers one lower than the target); 881FB550 (the target keeps an unsimplified `subfe` bool on the first list test);
  88748150 (C++ member loop, begin/end land in r4/r5); 888ADC60 (self-relative float update, the target reloads every field);
  884D9110 (format string at 0x88084480 has no symbol); 88944980 (fn_889426C8 gets an unset r4, probably an unused float slot).
- Family: 8826C388, 8826C400, 8826C478, 8826C4F0, 8826CC60, 8826CCD8, 8826D010, 8826D7F0, 8826D868, 8826D8E0 and 8826D958 share one
  template (self-relative table find through a key getter, with 0 kept in r24 and t in r29, frame 0xa0). C forms are 22+ off on /Oc, /O1 and LTCG.

### agAG round 2 (b175): no matches, 1 draft
- 8826C388 family: the key getter is `ts4_fn_88273620` (fk_004.c, `return a0 + 12`). The target hoists t->offset, t->count and *key into
  callee-saved registers across that call, and keeps the `i*16` offset (r31) apart from the base offset (r28). With the loads written as
  locals before the loop, MSVC strength-reduces to a single pointer (27 off). With them inside the loop they are reloaded every pass (20 off).
  LTCG with fk_004.c as context inlines the getter (29 off), and `__declspec(noinline)` on the prototype does not stop that. The next thing to try:
  LTCG with a context file that holds a non-inlinable getter.
- **Find, then remove: the find reads `r->arr.count`/`r->arr.data` directly and the remove goes through a separate `Arr *a = &r->arr`**.
  That is agAD's CSE-by-operand rule again: the target hoists the count in the find loop and reloads it for the remove. This took 88475BF8
  (remove by key, 16-byte slots, the 8-byte value returned through a hidden `Value *out`) from 35 to 1 off. Draft:
  drafts/me_88475BF8_nearmiss.c (the shift-loop `add` operand order). 8843B300 and 884A9E38 (pointer-array remove plus refcount
  release) look like the same shape, but `a` folds back into h+0x30 (34 off).
- Open: 884926F8 (extent accumulate, 24 off: the target loads all of v[1..3] before the short adds), 884BDB38 (header byte swap:
  the dead `addi rX,+3` copies come from a lo/hi pointer swap inline, 27 off on /O1).

### agAG round 3 (b175): 7 matches
- Matched: 884ED120 (/Oc, message size switch), 88516C28 (/Oc, factorial with a stack table), 885678D0 strspn, 88567988 strcspn
  (/O1, CRT C shape with a 32-byte map), 8858DAA8 (/O1, bit writer), 88596630 (/O1, WAVEFORMAT check).
- **`ok &= mask` chains (`subi; subic; subfe rX,rX,rX; and`) are `if (cond) ok = 0;` statements on /O1**, where `ok` starts at 1.
  Neither `ok = ok && x` nor `ok &= (x)` reproduces it (88596630).
- **A switch with `bdz` (not `bdzf`) and shared case blocks**: group the case labels by result and write the groups in the target's block order
  (884ED120: `case 6:` first, then `case 1: case 5:`, `case 8: case 9:` ...). This extends agAE's switch-order rule.
- Bit writer (8858DAA8): `int r = w->room - n; w->room = (signed char)r; w->acc |= value << r;` gives the unextended shift count and the
  extsb'd store and compare.
- 88563540 (strpbrk, same map) cannot match: its symbol ends 3 instructions early (the `bne; li r3,0; blr` tail is split off as 885635C0). This needs a split fix in config.
- The 8826C388 family under LTCG with a `__declspec(noinline)` getter in the context file: the call stays, but the caller then keeps its values in volatile
  registers (24-28 off). So the target was not compiled with knowledge of the callee, and the 8 saved registers come from the source shape.
- Open: 884DAC70 (whitespace-collapsing copy: the delimiter loop is fixed with `while (*p) if (c == *p++)`, but the source loop's
  `lbzu`-at-top rotation is not), 884F5610 (sorted u64-key queue insert, 43 off on /O1), 88539B68 (2-bit saturating counters:
  the target keeps three separate `nor`s of the same value), 88596700 (MS-ADPCM format check, 40 off: /O1 inserts `twllei` on the
  divide, the target has none), 88596910/8859F4E8 (speaker-mask getters: the loop matches with a union `streams[]`/`ext`, but the tag and
  return blocks get tail-merged differently, 39 off).
- Skipped: 884A2D40/884B4FF8 (C++ vtable constructors), 88582F98 (XDK title-launch wrapper), the WMA decoder group 885C2E90..885C31A8.

### agAH round 2 (b175): 29 matches, 7 drafts
- Matched (/Oc unless noted): 88356BD8, 88399768, 883E5E00 (/O1), 88443170, 884EB5C0, 884FAFC0 (/O1), 884FB038 (/O1), 8857E608 (/O1),
  885A5EB0 (/Os), 886F36A0, 887E9D78, 8899DFC8, 881F4090, 881F0388, 88411C40, 8842CE08/8842CE80/8842CEF8 (/O1), 884CCF20, 885E5A08 (/O1),
  8860E740, 88584B50, 889422F8, 889166D8, 882B0290 (/O1), 883298D8, 88531FF8, 88479F38.
- **/Os gives an unrotated `while` loop** (`b` to the bottom test, the null test at the bottom): 885A5EB0, a locked list find through an inline find().
- **A vtable loaded before an unrelated call** (883E5E00): read the vtable into a local before the call, `TgtVt *vt = t->tgt->vt; t->src->vt->flush(t->src);
  *out = vt->position(t->tgt);` on /O1. An `r3` that is not set before the second vcall means the first call's result is not an argument.
- **A discarded hidden-pointer result:** size the temporary from the frame. 884EB5C0 needs a 4-byte struct; 0x10 gives a frame that is 0x10 too big.
- **The bisection template from 88517488 also covers byte tables** (88411C40: `x >= p[i+1]` returns i, `x <= p[0]` returns hi).
- **The 88942370/8863A780 self-relative find covers more tables:** 889422F8 (stride 0x60), 886F36A0 (end recomputed in the loop test, key passed by value).
  When the key is read from memory (`*key`, a global field), the target compares (key, e->key) with e->key loaded first, and every C/C++ form
  is 1 off: 886EFCC0, 886EFC48, 886EFD38, 88945960 (drafts for 886EFCC0 and 88945960).
- **The OP1 symbol-number rule in a nested self-relative lookup** (8899DFC8): a `Rel *rel = &s->rows;` local flipped `add` to (index+first)+base.
- **In a ring-init loop, the store order picks the induction variable** (88584B50): `e[i].prev = i - 1; e[i].next = i + 1;` matches;
  next-first gives an `i - 1` induction.
- **A case-fold helper that modifies its parameter** (`if (...) c += 0x20; return c;`) matches strnicmp 883298D8. The early-return helper is larger.
- **A done flag kept in r3 across a listener loop** (8860E740): `unsigned char done = 0; L **end = t->end, **it; for (it = t->begin; end != it && !done; it++)`.
  The same form on 8827DBF0 is still 9 off (parameter registers).
- **Byte-entry fields:** read the entry layout off the first `addi` (88531FF8: entries at +4, u16 id at +2 of each, so `addi r30,r3,6`).
- **Cached-id lookup family** 8842CE08/8842CE80/8842CEF8 (/O1, only the lbl_88B3D1D4/D8/DC cache differs); there may be more past 8842CF70.
- **Assertion helper fn_885DC838:** called as (0, lbl_880B4540 format, expression string, file string, line). Read the strings to type the code (885E5A08: `arg < (5 + 1)`, irinst.cpp).
- Drafts: 883FD1D8 (2 off, the order of the two byte loads), 885871A0 (1 off, branch target of the found path), 886EFCC0 and 88945960 (1 off, cmplw order),
  88209E80 (2 off, lfsx operand order at one of two sites), 8837AA88 (2 off, li/addi order of the loop setup; sibling 8831F788 is the same),
  884EC070 (1 off, lwzx wants base-first and every form gives index-first).
- Unsolved: 888008B0/88800A28/88800B10 (they reuse r6 across a call, which points to LTCG with callee context), 88941B30 (std::map find, 9 off),
  884A0768 (the command walk biases its pointer by +4), 884DC9B0 (TLS free of two buffers), 884F7470 (the bool result keeps `li 1; beq; li 0`),
  88343470 (the clamp's subtraction is recomputed), 887E61A0, 88518EE8 (quaternion cosine, fmr copies), 88924250/881518D0 (from round 1).

## agAI (b176): split fix for strpbrk, medium sweep from agAG/cand.txt (5 matches, 1 draft)
- **Fixing a wrongly split function.** `tools/matching.py --fresh-analysis` copies `config/54540859/symbols.seed.txt` into
  `<work-dir>/analysis/symbols.txt` and Jeff analyses from that seed, so the fix is one seed line with the full size.
  `config/54540859/symbols.txt` is a committed snapshot read by the audit tools (audit_callees, audit_datarefs, decomp_survey);
  update it to match by hand, as 90c1b60 did for the jump-table merges (8865DA28 grew to 0x94 and its tail pieces were deleted).
  For 88563540: seed `fn_88563540 = .text:0x88563540; // type:function size:0x8C`, and in symbols.txt size 0x80 -> 0x8C with the
  `fn_885635C0` (0xC) line deleted. The tail had no callers: no branch in the disassembly targets 0x885635C0 and nothing in src/
  names it. Full build: 33041 functions, 3380172/10154028 bytes, the same as b176 (the 0xC tail was never matched, and both pieces
  were already in the denominator). agAG's p3.c matches on /O1 against the fixed split. It fails against b176 until the next
  integration build, which picks up the seed line.
- Matched: 88563540 strpbrk (/O1, after the split fix), 885DA2D0 (/O1, 16-bit 2:3 upsampler), 888C7E58 (/Oc), 888C30F0 (/Oc), 888C3BE8 (/Oc).
- **A dead `mr r5,r3` at entry, before a tail vcall,** means the function's own argument is passed through as the vcall's third
  argument (888C7E58). The agAH self-relative begin/end inlines then matched as written.
- **Pointer select with the second choice as the default** (`addi +0x4c; beq; addi +0x34`): write `flag == 0 ? &b : &a` (888C30F0).
  Struct copies from a global that is re-read through the selected pointer, while the other target gets the register copy:
  `Vec3 pos = *pp; ... a->pos = *pp; b->pos = pos;`.
- **`if (k == A) h = X; else if (k == B) h = Y; set = 1;`**: MSVC duplicates the shared tail into the first arm and lets the second
  fall into it (`bne` to the shared store). Writing `set = 1` in each arm gives `bnelr` (888C3BE8).
- **Null guards compared with `cmpwi` (signed) on pointer fields:** pointers compare with `cmplwi`, so the target tested them as ints.
  `(int)a == 0` reproduces it (888C3BE8). Look for a better type before reusing this.
- **Final store after an inline that writes through `*o++`:** to keep the last store after the computation, write `*o++ = x; *o = last;`.
  Writing `o[0]`/`o[1]` schedules the second store first (885DA2D0). Signed `/ 8192` gives the `srawi 13; addze` pair.
- Draft: drafts/me_886EC0E0_nearmiss.c (font glyph lookup, 1 off: lhzx operand order on the final `ranges[i].first`; the `'_'` fallback
  is a tail-recursive call that MSVC turns into the backward `b`).
- Open, more than 3 off:
  - 8859F4E8/88596910 (speaker mask): with `mask = 0; if (1 <= ch && ch <= 8) mask = tab[ch-1]; return mask;` the channel tail matches
    (`li r3,0; bltlr; bgtlr`). The 0x166/0xFFFE `return ext.channel_mask` block always moves to the end. The target keeps it inline
    after `bne` to the channel code. Tried a switch, else-if chains, an inverted test, a tag local and an inline default_mask helper.
    The r10/r11 tag/pointer swap at entry is still there.
  - 885C9D58 (Q30 smoother, 64-bit): 6 off. The target stores the `sradi 30` result raw, then `clrrwi r9,r9,0; extsw` for the
    scale test. An `__int64 v` local gives everything else. `(int)`/`(unsigned)` casts, a `k = (int)v` local and inline mul helpers do not give the clrrwi.
  - 885F99E0 family (885F9E08, 885FAE20, 885FB5E8, 88601270, 88601710, 88602E80, 88603208; probably 885FA8C0/885FAA38): field unpackers,
    `if (left < sizeof f) return 0; f = *p; left -= ..; p += ..;` then `*size -= p - buf`. The code is all there, but the target has left in r11
    and p in r10 (swapped in every form): inline read_u16 helpers, a Reader struct in either field order, macro and memcpy forms (memcpy gives byte copies).
  - 8860A088 (20-bit index tree find): 31 off. A result local and the vsize/vat inlines give the shape, but begin is reloaded per pass where the target has a clrrwi copy.
  - 88667C98: 41 off, only because `&s->shot` (`addi r9,r11,0x80`) is folded. The target materialises it before the active-byte test.
  - 8876D210/8876D2C0 (find by id in two pointer vectors): the target preloads r3=0 and keeps a clrrwi copy of begin.
    Seven forms (vsize/vat inlines, value vat, a find helper, n/begin locals) all reload begin. 43 off.
  - 887CDDE8 family (887CDE98, 887CF6A0, ...; commentary triggers that return a hash through a hidden pointer): 35 off. Missing are
    the `clrrwi` copy of the match pointer and the add order of the self-relative stats element (`(i*0x134 + off) + base`).
  - 888D5298: the 0x2D-byte record copy becomes a memcpy call. The target copies 11 words and a byte inline.
- Skipped: 885CF138 (lwarx), 885CF4F8, 885D4890, 885D9C48 (audio/codec state), 886094C8 (bitfield clamp), 888C5760.

## agAH round 3 (b176)
- **Cached field-id store family (8842B5xx-8842C8xx).** These are generated by `fam.py` in the agAH scratch folder:
  ```
  if (cache == 0xFFFF) {
      Ref r; unsigned id;
      88428890(&r, src, lbl_880E1DE4);
      884278D0(88426140(88428AC0(&r)), lbl_field, &id);
      cache = id;
  }
  88428890(&r2, src, name);
  *884289F8(&r2, 0) = cache;
  ```
  Then, per extra field, `88428890(&rN, src, lbl_x); *getter(&rN, 0) = param;`.
  - Getters: `88428A28` for u8, `884289B8` for float, `884289F8` for u16, `88428988` for u32, and `88428A38` for 16-byte Vec4 struct assignment (8842B738).
  - Parameters take their GPR/FPR slot from position. When a float sits between ints, the int after it skips a GPR (r9 instead of r8), so order the parameters to match.
  - 8842BE98 and 8842C808 are 6 off. Their first extra field uses the getter `884289A8` (`add r3,r11,r4`). The target stores straight after that call and numbers every later register one higher. `char*` with an `int` param gives the right schedule but not the register numbers.
- **Struct returned by value through a hidden pointer.** If a callee writes `stb 0(r3)` and the caller passes `addi r3,r1,0x50`, declare the callee as `T *f(T *out, ...)` and call `f(&tmp, ...)->field` (88468370).
  - Vec4 min/max (88517378/88517400) only match as `Vec4 f(const Vec4*, const Vec4*)` returning a local by value, with the four zero stores as separate statements. Chained `r.x = r.y = ... = 0` misses.
- **Shared failure block.** Put all the early-out tests in one `||` (or one `&&` with the work inside) so they share one `li r3,-1` block. Separate `if (...) return -1;` lines get their own blocks (88468370, 8898FE30/EB0: error path inside the `!=` block, success `return 1` last).
- **Reading a double's bits through `&param`** uses the parameter home slot `0x10(r1)`. A local union copy uses `-0x10(r1)` (8856E7F8).
- **`unsigned __int64` parameter truncated to u32** gives the `clrrwi rX,r3,0` copy at entry (8857B308). Also, `x * 64 + 0x40` aligned up with a `static` align helper keeps `slwi; addi 0x103f`, where the compiler would otherwise fold it to `addi 0x40; extlwi`.
- **Branch sense on float compares:** write the branch the target falls through to first, e.g. `if (x <= d[mid]) hi = mid; else lo = mid;` (885188F8).
- **bdnz countdown loops at /O1** come from `n = count*4; for (i = 0; i != n; i++)` (882DE4F0); `i < count*4` gives a `cmplw` loop.
- **Register number shifted by one at an indexed call:** assigning the entry pointer inside the condition fixed it: `if (t < reg->count && (e = &reg->entries[t])->create != 0)` (8893B7E8).
- **A ternary on a separate local** (`n = m->instances; counts[slot] += n < 1 ? 1 : n;`) matched where an `if` with a default value did not (8848EC10).
- **A pointer local for the field operand** fixes vcall scheduling: `float *e = &t->elapsed; *e += ...; vt->advance(s, e);` (886EEDF0).
- **Nested MAX macros** that re-evaluate the inner MAX (`MAX(w-t, MAX(h-t, MAX(d-t, 1)))`) matched 882891B0 at /O1 together with the intrinsic `_CountLeadingZeros`.
- **The open-coded list iterator** `if (n) { it = n->next; li = n->item; } else li = 0; if (!li) break;` matched at /O1 (88594678).
- **Accumulator initialised after a NULL guard:** `unsigned v; if (s == 0) return 0; v = 0;` keeps the `li` after the `blr` (88329B70). `v = 0` at the declaration hoists it above the guard.
- **lwzx (base, index) order:** a live alias of the parameter (`Table *self = t;`, then use `self->` everywhere) flipped it at /O1 (883D08A8). This is the OP1 symbol-number rule, satisfied without dead pads.
- **Element pointer local in a loop body:** `Edge *e = &g->edges[i]; if (e->dst == node) f(g, e->src, e->dst, ...)` keeps the compared value in the argument register and avoids a reload (88451948).
- **Struct-cleanup sibling pair 882207A8/8825B3A8:** 12 off. The heap global is loaded once into r31 and reloaded only after the heap-free call. An explicit local that is reloaded inside the if-path gets everything except an r30/r31 swap of self and heap.
- Drafts this round (drafts/me_<ADDR>_nearmiss.c):
  - 88589748 and 885897C8 (3 off): `rotlwi` of `index*64` is scheduled late.
  - 8870FF70 (3 off): rate/value load order.
  - 8818A210 (3 off): memcmp result written with cntlzw instead of a branch.
  - 884D14F8 (1 off): `add` operand order in the first fixup loop.
  - 8877BF58 (2 off): register number.
  - 888AF478 (3 off): when the threshold label is loaded.
  - 887C7BD0 (1 off): slot address add order; named locals do not flip it.
- Open, more than 3 off:
  - 8842CD08: C++ temporary stack-slot order; 6 off.
  - 883B1800/883B1888 (float copy and scale, unrolled by 4): 31 off. The target runs a `(n-4)/4+1` bdnz loop, then a `cmplw` remainder loop.
  - 882BD358/882D8598 (pixel write): 4 off at /O1 on the order of the dst/src `subi`.
  - 885BDB40: a switch of seven function pointers. The target has a `bdz` chain with no range check; ours adds `cmplwi 6` and `bdzf`.
  - 88771598 (hash switch): 9 off on block order.
  - 884E1F10 (float to RGBA): float register allocation of the scale.

### In-place prefix sum (88515620, agAH round 3)
Walk a separate `p = a + 1` pointer alongside the counter; MSVC then emits the target's 4x-unrolled loop plus the bdnz remainder loop.

### Integration note (b178)
`tools/audit_callees.py` caught `me_ts4_stream_reset_88624F68.c` calling fn_8827FAB0 where the target calls fn_882800B0; objdiff had reported MATCH. Run both audits after every full build.

## agAI round 2 (b177): vector resize/clear/teardown templates (/Oc)

- **Dinkumware resize**: `if (n < size) v->last = copy(v->last, v->last, v->first + n); else _Insert_n(v, v->last, n - size, &val);`
  (88280428 family). A default value whose type has a no-op constructor is passed uninitialised. A value-initialised default
  is `memset` with `#pragma intrinsic(memset)` (std/stw through the pointer). Member-wise element assignment gives the
  unrolled field copy; struct assignment `*dest = *first` gives a word loop (5 words: `li 5; mtctr; lwzu/stwu`) or ldu/std
  for 8-byte elements. A 16-byte uninitialised allocator/param block (`struct { int unused[4]; }`) sets a 0xA0 frame (88227978).
- **Use one inline size() helper** for both size computations (8890ED60). For counted loops, hoist it: `unsigned i, n = size(v);
  for (i = 0; i != n; i++)` gives `srawi.; beq; mtctr`.
- **cw4 clear `cmplw r4,r4`**: forceinline `copy_bytes` = no store on the equal path, or the `lwz r11; mr r3,r11` form with
  a store on both paths. Plain `static __inline` = `bne; stw first; b` (equal path stores first). Pick per target.
- **Load order and register swap of vector bounds (fixed 9 functions)**: read `end` through the owner and `begin`
  through the vector local: `ObjVec *v = &o->objs; Obj **it, **end = o->objs.last; for (it = v->first; it != end; it++)`.
  This gives the target's last-before-first loads and the v/global register assignment (888FF550, 889310A0, 8861EDB8,
  886DAFA0, 88800550...). If the loop end is re-read every iteration: `for (it = v->first; it != o->objs.last; it++)`.
  The cmplw operand order: `end != it` vs `it != end`. Does not work when the vector is at offset 0 (8862BA88 draft).
- **Indexed slot loops**: `o->objs.first[i]` (through the owner) vs `v->first[i]` swaps the stwx/lwzx operands
  (8876D180, 887F72B8 want the owner form; 88803090 wants v). Re-read the slot after a call: `p = v->first[i];` again.
- **Reverse loops**: `Obj *p = *(it - 1); ...; it--;` gives `lwz -4(r11); subi r31,r11,4; ... mr r11,r31` (8860B888, 886A6E98);
  `*--it` gives lwzu. A hoisted `slot = last - 1` with the old slot compared: `for (;;) { body(slot); { T *cur = slot; slot--;
  if (cur == first) break; } }` (8861EDB8).
- **Dead `addi rX,r3,off` after zero stores** = a fully unrolled inline zero loop over a sub-struct:
  `static __inline void sub_clear(Sub *s) { int i; for (i = 0; i < 5; i++) s->w[i] = 0; }` (887CDC40, 887CF290).
- `0 == (s->a + 0)` keeps the target's `addi r11,r11,0; cntlzw` (88624EE0; matches the `0 == p` note above).
- Signed `cmpwi` tests of pointer-like fields: declare the field `int` (88728350, 8825DE40), or `(int)p != 0` when the same
  field is also tested unsigned later (887F2C48).
- A field tested in the caller and then reloaded through `r4 = &o->field`: test `o->hub.hub` in the caller, do the work in an
  inline taking `&o->hub` (88912E70).
- Hand-written `delete[]` with a count prefix: `int *hdr = (int *)arr - 1; int i = *hdr; Elem *e = arr + i;
  while (--i >= 0) { e--; elem_destroy(e); } free(hdr);` (8825DE40).
- Counted copy loops: `for (n = last - first; 0 < n; --n, ++first, ++dest)`; the increment order sets the order of the two addi.
- Open: 885F99E0 field-unpacker family (10 functions) stays 5 off, one sth scheduled differently (tried LTCG, /O1, /O2, /Os,
  /Oy-, all 64 step orders, type changes, out-first args, void* buffers). 88702BF0/88703788 (signed cmpw of vector bounds;
  int casts reproduce cmpw, not the operand order, draft 3 off). 8866FDD0 (3 off, agentA2 draft kept). 886262D8 (member
  pointer induction `r9 = g+0x18` across the group loop). 887D96E0 (explicit clear plus inline delete clear: the
  second clear's `clrrwi` reload). 88941780 (global flag stores scheduled around the clear, 7 off). 88233678
  (`clrrwi r3,r11,0` on the global allocator argument). 8816C030 (two-element ctor loop: our zero stores fold the clear).
  886BEBC8/8826AE38 family (this/n callee-saved swap, 18 off).
- lwzx/stwx operand order in counted slot loops also follows the index type: signed `int i, n` gives base-first
  (`lwzx r31,r11,r29`), unsigned gives index-first (8825B918). Try the signedness before rewriting the access path.
- A branchy bool in r11 (`li r11,1; beq +8; li r11,0; clrlwi; cmplwi`) is an inline written `if (cond) return 1; return 0;`
  returning unsigned char; `return p ? *p == 1 : 0;` gives subi/cntlzw instead (88911668). A vtable pointer loaded after
  a call, with the object loaded before it: keep the call result in its own local (`desc = ...; m->vt->f(m, desc + 0xc, 1);`, 888C2E58).

## agAH round 4 (b178)
- **Pool-buffer family (TLS allocator, kind 0x17).** Many destructors, deleting destructors and copy helpers share one
  buffer shape `{T *data; int count; int capFlags;}`: bit 31 of capFlags = storage not owned, bit 30 = kept flag,
  bits 0-29 = capacity. The free that matches every member is an inline helper:
  `if ((b->capFlags & (int)0x80000000) == 0) { unsigned cap = b->capFlags & 0x3FFFFFFF; void *alloc =
  KeTlsGetValue(lbl_88CACF08); fn_8841A590(alloc, b->data, cap * sizeof(T), 0x17); }`.
  - The capacity word must be a signed int and the mask cast to int; unsigned gives cmplwi instead of cmpwi.
  - The masked capacity goes in a local before the KeTlsGetValue call; the element size is in `cap * sizeof(T)`.
  - Matched with element sizes 1, 2, 4, 8, 12, 16, 20, 36, 40, 48, 56, 80 and 112:
    884DC9B0, 884E1FE8, 88555608, 88486090, 887F4698, 8841C2B8, 88520CE8, 88437790, 88437BB0, 884BF008,
    884BF468, 884384B8, 88489B98, 884A8D60, 88541FB0 and 88492D88.
  - The u16 variant `{data; u16 count; u16 capFlags}` has bit 15 = not owned, mask 0x3FFF, and gives clrrwi 15 +
    cmplwi (885E94D8, 885E9568).
- **Deleting destructors in this family:** the inlined body, then the d1_band2 tail
  `if (flags & 1) { alloc = KeTlsGetValue(...); fn_8841A590(alloc, o, o->size /*u16 at +4*/, kind); } return o;`
  (884BF398, 884DA3F0, 884DCAE0, 884BF220, 884CCAB0, 8844E450, 884863C0).
- **Pooled variants** return the header to a per-thread free list. Use the `list_full`/`list_push` helpers from
  me_ts4_release_buf_and_pool_obj_8841C428.c. The list sits at pool +0x38 + 8*kind, and the overflow path is
  `fn_8841A3F8(pool, kind, obj)`. Add `&& o != 0` to the flags test when the target has `cmplwi r31,0`.
  Examples: 884A2100, 884C4FA8, 8841DA58, 8841ABD8, 8849B2F8, 884AD988, 88520DD8, 885F2390, 8841AAC8.
- **Regrow (8841C5E8, 8841C678, 885E94D8, 885E9568) and assign (8847B028, 884A74E8, 88473EB0, 88560A90).**
  - Fetch each KeTlsGetValue into its own local before the alloc or free call; an inline argument swaps
    `li r4` and `li r5`.
  - The assign copy loop must use the locals `n = src->count; d = dst->data; dst->count = n; s = src->data;`
    and then `d[i] = s[i]`. `*d++ = *s++` gives lwzu/stwu instead.
  - A lone static assign helper is not inlined (88560A90), so mark it __forceinline.
- **A secondary base whose fields are reset in the destructor** (vtable at +8, link at +0xc, 885EBBC8): make it an
  embedded struct with its own inline dtor helper. Plain field stores in the outer function get reordered.
- **Comparing against zero:** `0 < x` (constant on the left) gives `subfc; eqv; srwi; addze; clrlwi 31`, while
  `x > 0` gives `neg; andc; srwi` (8826ACB8). `result = 0 != find(...)` keeps the `addi rX,rY,0` copy (88995358).
- **Memmove loops:** a `while (n--)` loop with separate d/s pointers gives the mtctr/bdnz loops. An index loop or
  `for (; n; n--)` gives subic./bne (88329998).
- **Store order around a helper:** copying through a small field-copy helper keeps the 64-bit flag `ld/ori/std`
  after the float stores (886F7198). Open-coded stores let the compiler hoist the ld.
- **Byte swap:** two calls of a byte-swap helper per word match 88432BE0. Open-coded temporaries give a different
  store order.
- **Open: the `stwx r10, r11, r9` fill order** (88423C28 is 1 off; 88423E28 and 88423C28 are drafts). It is not fixed
  by any index form or by 0-8 operand_order_pad locals. The constant-count fill in 88423CE0 does match.
- **Open: register or operand order only:** 88472A88 (fmuls operands), 88611440, 883CB860, 8848C0A0 (r30/r31 swap),
  8847E770 (v0 vs v63 element copy, the v0-v13 issue), 882759C8, 885EAB70, 886C4CB8, 88413538 (constant loads
  hoisted and shared), 88605438/88608590 (CRC32 crc/char register swap).
- (agAH r4) An embedded list read through a local pointer (`KeyList *keys = &c->registry->keys;`) fixes the reload order in loops over owner->sub->list (884EDB18).
- (agAH r4) When a null test at the call site is followed by passing the same expression to a helper, the compiler emits a clrrwi copy; keep both uses of the expression (884812E0).
- (agAH r4) Writing the element expression twice instead of caching it in a local flips the lwzx operand order; pick whichever form the target shows (88408D58).
- (agAH r4) Null-checked base casts inside a loop (`cmplwi; addi r4; bne; li r4,0` per call): write each as a small __forceinline helper with `if (o) return &p->field; return 0;`. A ternary at the call site, or `l = 0; if (o) l = ...`, is if-converted and hoisted out of the loop (884AA078).

## agAJ (b179): reserve/insert/uninit-copy/pool templates, medium sweep (55 matches, 5 drafts)
- Matched (/Oc): 886CE860, 88870AC0, 88737A60, 8895B200, 8825FB30, 88255F90, 8825CC20, 88224330, 88224410, 8815CAD0,
  8815D230, 882642E0, 88282A90, 881533E0, 881A7B98, 881AE298, 881AE450, 88278AC8, 88278BC0, 882828A0, 88163AD8,
  881B29E8, 8827C2E8, 88215BF8, 881FB710, 88216198, 8827ABC0, 88163238, 88162E48, 881797D0, 881798E0, 881799F0,
  88215F60, 88162F40, 881A6D80, 88265380, 8822A3D8, 886CF940, 881705B0, 8815DCE0, 8815DDC0, 8815DEA0, 8815DB40,
  8815DC10, 88159870, 8815D160, 88264F28, 881A8AB0, 8817F8E8, 886CBA80, 8890EBB8, 886DFC80, 88166650, 881665D0, 8827C428.
- **textdis.pkl branch targets:** the `-> 0x...` field in work/army/VX1/textdis.pkl is not a usable address. Compute the
  target from the relative offset instead: `addr = func + 4*i + rel`. agAJ/dis.py and agAJ/scan.py do this (`bl 88562DC0`
  regexes then work). With the raw field, callers of memmove looked like one function.
- **objdiff does compare relocation names when the instructions match:** a callee declared `fn_88216528` where the symbol is
  `ts4_e5c_ucopy_88216528` fails with `reloc +0x..: candidate fn_.. vs target ts4_..`. Take every callee and label name
  from config/54540859/symbols.txt by address (the reserve generators do this). The float constant at 0x8814B440 must be
  spelled `lbl_8814B440` (the b179 analysis names it that way, not g_ts4_event_value).
- **vector reserve(n) family (24 matches).** Template is d1_big1_vector_reserve_family.c with a runtime count:
  `first = v->first; if ((unsigned)(v->end - first) < n) { last = v->last; size = last - first; if (first != 0) {
  buffer = n != 0 ? alloc(&v->end, n) : 0; src/dest copy loop; first = buffer; free(v->first); } else first = alloc..;
  v->first = first; v->last = first + size; v->end = first + n; }`. Variants, each confirmed:
  - element copy: `*dest = *src` for POD (word loop, `ldu/stdu` for `unsigned __int64` members, two `lhz/sth` for a
    u16 pair); member-wise `dest->a = src->a; dest->b = src->b;` for __vector4 pairs (struct assignment gives ld/std);
    a copy-ctor call `if (dest) copy(dest, src)`; `ts4_assign_formatted_text(dest, src->p)` for 12-byte text strings.
  - an uninitialized-copy range call `ucopy(first, last, buffer)` plus a destroy step that re-reads `v->first, v->last`:
    either a destroy range call or an inline loop calling the element dtor (`&first->body` when the call takes +K).
    `first = buffer;` goes before or after the destroy step; try both (agAJ/gen3.py tries all four).
  - memmove POD form: `size = v->last - v->first` (re-read, not `last - first`) keeps the memmove length as its own subf.
  - allocator through the heap (`fn_88613570(lbl_88D45B38 ? fn_8860D250(lbl_88D45B38) : 0, n*sz, align, &v->end)`):
    allocate and reserve must both be `__forceinline` (two expansions), see 886CBA80/8890EBB8/886DFC80.
  Generators: agAJ/gen_res.py (POD/call copy), agAJ/gen3.py (ucopy + destroy), agAJ/mmres.py (memmove).
- **Dinkumware vector::insert(where, val)** (88224330/88224410): construct at end or `construct(last, last-1); ++last;
  copy_backward(where, last-2, last-1); assign(where, &tmp)`, else `_Insert_n(v, where, val, 1)` (val before count).
- **Inline-buffer vector operator= (8825FB30, 88255F90, 8825CC20):** grow into the buffer, shrink copy, or split copy then
  append; write the size test as `size(s) >= n` for the cmplw operand order.
- **SGI node pool (lbl_88D49310 free lists, lock lbl_88D49350, lock acquire fn_8815E358):** declare the lock
  `extern volatile int` (keeps the unlock store last and the 0 in a saved register). String dtor: null test inside a
  `deallocate(p, n)` inline so `end - first` is computed before the test. allocate (8815D160): one result variable for
  both the pop and the `_S_refill` path. Range destroyers 8815DB40..8815DEA0 differ only in layout.
- **uninitialized_copy / fill_n of records with strings (8815CAD0, 8815D230, 88166650, 881665D0, 8827C428):** the read
  order inside the string copy picks the induction base (`last = src->last; first = src->first;` gave first+0x14).
  fill_n wants a separate iterator local (`Entry *p = dest; for (; count != 0; --count, ++p) ...; return p;`), which fixes
  the parameter `mr` order.
- A by-value handle tested by an inline (8895B200): two function-scope `Handle` locals (frame 0x90); a scoped local
  shares the slot and gives 0x80.
- `resize(v, n, val)` written as an inline that takes the default by value fixed the zero-store placement (886CE860);
  an inline that owns an uninitialised default `T val;` gives the `addi r6,r1,0x50` with no store (88870AC0).
- Drafts: me_8815CFA8 (3 off) and me_8815D388 (2 off): second string's zero stores scheduled end-first;
  me_8827FFB8 (2 off): +0x804/+0x808 zero-store order (a `char *` clear helper and a vector-init inline already give
  the reload of `first`); me_8815C0B0 and me_8815C708 (1 off): `add.` operand order of `size + max(size, n)`; C++ refs,
  a size() inline and statement splits all give max first. Siblings 88279448/88283C60 have the same shape.
- Open, more than 3 off:
  - 8822AD70/8822BE48/8822D1D8 (constant reserve) and 8822C1C8/8825CB20 (runtime reserve) with the 886131F0/885651F8 free:
    8822C1C8 is 6 off (register numbers of the final `p + size`/`p + n` adds); the constant ones keep the `v->alloc`
    load hoisted above the null test (21 off).
  - 88286F38, 881FB710-style ctors that zero the vector then reserve: ours folds the reserve because it knows first == 0;
    the target reloads first (8827FFB8 shows a `char *` store in between blocks the forwarding).
  - 8826B078/8826B188 (pool of n 0xAC-byte elements + slot vector): 18 off, only the pool/n callee-saved swap.
  - 887DA038 (16 off): srawi. size test vs our clrrwi; 886106D0/88610620 (handle derive vcall): svc kept in r11 by the target.
  - 88166C58/88161F58/88166938 (vector copy ctor): 4 off, `mr r29,r3` scheduled before the first load.
  - 88233DA0 (uninit copy, six words then two strings): the target picks the +0x18 base; 10 off.
  - 88178378 (two vector clears + frees): the 96-byte struct copy becomes a memcpy call; member loops give ldx.

## agAH round 5 (b180)
- To get `li r3,0` at the top of a search loop and a single `mr r3,rX; blr` exit, keep a `found = 0` variable and `break` out of the loop; plain `return s` inside the loop does not do it (8861A370).
- If the loop end is loaded before the begin pointer (`lwz +0x18` before `+0x14`), read end into a local first and compare `end != it` (8825DFE0).
- A u8 predicate whose return tails are each `li r11,K; clrlwi r3,r11,24`: compute an `int r` in an inline helper and `return (unsigned char)r`. Returning the condition directly merges the tails (88936EB8).
- In `base[i].field[j]`, write `Bank *b = &m->banks[i];` to get the `add r9,r9,r11` operand order (885C3A58).
- When a field is reloaded in the else branch, write `r->table->x` at every use. A local `t = r->table` lets the compiler reuse the earlier load (8843CEB8).
- When a float constant stays in a register (f31 across a call, or one register for two compares), read it into a local first: `float step = lbl;` (8832B1D8) or `float unset = lbl;` (88483540).
- Float arguments take GPR slots in the Xbox 360 ABI. For example, (seed, lo, hi, out) puts out in r6. Pointer arguments after a float appear in the registers that follow (88557450, 8843F3F8).
- `fctidz` + `stfiwx` comes from a float-to-unsigned-int conversion; `fctiwz` comes from float-to-int (8828DFB0 is still open because of LTCG scheduling).
- Some r4new2 entries have truncated listings in textdis.pkl, ending without blr or b (883D2400, 8858E758, 8859D010, 887E9A38). Check the size in symbols.txt before trying one.
- **Round 2 (b181), copy-constructor family and teardowns (50 more matches):** 88166C58 88161F58 88166938 881B6A80 881B6E00 88213EB8
  88216620 88166BC0 88166428 88181878 88286F38 88166728 88179D88 8817A108 8827FFB8 88624FE8 8879CBE8 881A8D88 8815BD90
  8815BCA8 88181910 88171088 881BC210 88158A98 88282FC8 881A7188 88163300 88159C88 88286558
  8815CFA8 8815D388 8816C648 8816C258 8816C2F0 88178268 8827B778 8827B810 887DA2B8 88235D80 88162768 88255C08
  88261188 88261360 88261450 8825EB00 88260C58 882400F8 88261530 882294A0 88258BF8.
  - **End-slot zero store:** the vector copy constructor / ctor-then-reserve needs the end zero store written through a
    pointer: `T **end_slot = &v->end; v->first = 0; v->last = 0; *end_slot = 0;`. This one change fixed the old
    "4 off, mr r29 scheduled late" copy ctors (88166C58 family), the "reserve folded because first is known 0" ctors
    (88286F38, 88624FE8) and the 8827FFB8 draft (+0x804/+0x808 order). Plain member stores are right for some members
    (88166BC0 needs end-slot, 88163300 does not), so try both.
  - Shape: `n = src->last - src->first; zero (end-slot); p = n != 0 ? alloc(&v->end, n) : 0; v->first = p; v->last = p;
    v->end = p + n; v->last = ucopy(src->first, src->last, v->first);`. Put it in an inline that takes `(Vec *v,
    const Vec *src)`, so an aggregate's source base gets its own `src+K` register (88181878, 88171088).
    Generators: agAJ/gencc.py (plain vector), agAJ/genagg.py (aggregate: member copies + vector part).
  - Variants: `p = 0; if (n != 0) p = alloc(..)` when the target sets r3 = 0 before the test (88166728, 88181910);
    `v->last = p; v->first = p;` when the target stores +0 before +4 but ours comes out reversed (88282FC8, 881A7188);
    a `__forceinline` copy inline when the same vector type is copied twice (88179D88); `if (last == first) return dest;`
    in the memmove ucopy for the cmplw order (88216620).
  - **Store vectors** `{first; last; {alloc; end}}` (88235D80 and 10 siblings; alloc handle constructed by 88255AA0,
    allocated with fn_88613570(alloc, n*size, align, &alloc)): the alloc handle and end are ONE struct, initialised by
    an inline through its pointer: `store_init(S *s) { s->alloc = 0; init(&s->alloc); s->end = 0; }`. Copy ctor:
    `def = 0; init(&def); n = size(src); v->first = 0; v->last = 0; store_init(&v->store); p = 0; if (n != 0) p =
    alloc; first = last = p; store.end = p + n; last = ucopy(...)`. Separate `alloc`/`end` members are 2 off (the end
    store moves after the n test). Generator: agAJ/genst.py (addr,size,pod|call:ADDR). Aggregates inline one member and
    call the others (882400F8, 88261530). Open: 8872E248 (store vector + reserve(32), 27 off), 88220690/88222D28
    (two store vectors + reserve).
  - String concat (88163300, 88159C88): compute the combined length before the zero stores; the append inline reads
    `s->last` before `s->p`. 8822C0F8 (string + char) is 5 off on the same `size + max(size, 1)` add order as 8815C0B0.
  - Open: ts4_assign_formatted_text 88152D58 / 881599B8 (char* ctor). The fam3 `char_copy_range` helper with an early
    return gives the duplicated tail, but only when the zero stores sit in the same inline, which then puts them after
    the strlen loop (31-37 off). 88179F80 (96-byte u64 element copied with ldu/stdu, ours gives memcpy or ldx, 59 off).
    88181BF0 (text + six words + two 5-word blocks + four words, 41 off). 8827A130 (copy via reserve + resize + copy, 61 off).
  - **Reverse member-array destroy** (teardowns 8816C648, 8816C258, 8816C2F0): the `addi rB,this,END; addi rP,rB,K;
    lwzu r3,-SIZE(rP)` loop is an inline `destroy_n(T *first, int count) { T *p = first + count; while (--count >= 0)
    { --p; dtor(p); } }` called as `destroy_n(o->arr, N)`. An index loop or a hand pointer in the function body
    folds END+K into one addi (10-16 off). Registry release (`find_range_owner` 8860D360, else `->fallback`) must take
    the registry as an inline parameter, `release(lbl_88D45B38, p)`, for the `clrrwi r3,rX,0` copy.
  - **Vector destructor = clear + tidy** (88178268, 8827B778, 8827B810, 887DA2B8): the `subf rX,rY,rY` count loops
    are `erase(first, last)` = `v->last = copy(last, v->last, first)` with a counted copy `for (n = last - first;
    0 < n; --n, ++first, ++dest) *dest = *first;` (or the memmove copy with `if (last == first) return dest;`).
    Write `clear(Vec *v)` and `tidy(Vec *v) { if (v->first) free(v->first); }` as inlines taking the vector pointer;
    a class destructor clears every member first, then tidies them in reverse. Read `v->last` before `v->first` in
    clear when the second clear's loads come out swapped (8827B810). 887DA038 now differs only in the `srawi.` size test
    (ours `clrrwi`+`cmpwi`) and the registers that follow (16 off). 887D96E0 (44 off) keeps a null test after a deref.
  - Drafts: me_881BC130_nearmiss.c (3 off, r9/r10 swap between the first byte copy and &t->sub);
    88258BF8 is now matched (rec160_store_vec_uninit_copy). When `mr r30,r3` and the `addi r31,r5,8` induction come out
    in the wrong order, copy the loop pointer into a block-local first: `{ Rec160AVec *d = dest; if (d) copy(d, first); }`.
    The drafts me_8827FFB8, me_8815CFA8 and me_8815D388 are now matched with the end-slot string/vector init, so
    those three draft files can be removed at integration.
  - Struct copy that loads all three words before any store, with the first store as `stwx` (887FD7A8): copy the source into
    a local first (`Elem12 e = *tmp.first; b->out.first[i] = e;`). A plain `o[i] = *s` interleaves the loads and stores,
    and a pointer `d = &o[i]` drops the `stwx`. Draft me_887FD7A8_nearmiss.c is 2 off: only the lwzx operand order differs.
  - Open: 88259608 is emplace_back on a vector of store vectors. It grows with `size + max(size, 1)` and copies through
    88258BF8; the new element is built as def-init, `first = last = 0`, store_init. It is 13 off with a `__forceinline`
    grow, called as `if (v->last == v->store.end) grow(v, v->last);`. Re-reading `v->last` instead of caching it fixes
    the `end`-before-`last` load order. What remains is a pure swap: `last` and the zero constant take r28/r27 the other way
    round. Neither a separate copy-result variable nor `count` as a grow parameter changes it.
    887DA038 is still 16 off; the target keeps `srawi.` for the `size() != 0` test.
- **Round 3 (b183): the strlen `clrrwi` rule.**
  - The inline strlen loop (`lbz/addi/cmplwi/bne; subf; subi`) followed by `clrrwi rX,rY,0` is the strlen intrinsic
    converted to int. Declare `unsigned int strlen(const char *s);` and write `(int)strlen(s)` wherever the length is used,
    for example `s + (int)strlen(s)`, `124 - (int)strlen(buf)` or `unsigned int len = (int)strlen(name);`.
  - A hand-written loop gets folded (`e - s - 1 + s` becomes `e - 1`), and an unconverted `strlen(s)` drops the `clrrwi`.
  - This settled the open char* string constructor (88152D58/881599B8) and the 12-form open item 88421338 (`return (int)strlen(s);`).
    About 50 unmatched functions have the pattern; scan them with an lbz/cmplwi/bne loop followed within 5 instructions
    by `clrrwi r,r,0`.
  - Related shapes:
    - A `result = 0; ... result = 1; break;` local keeps the target's r27/r31 zero register. A direct `return 1` loses it
      (886ED490, 886EBEF0).
    - A capacity check reads both fields into locals before an unrelated store (88421BF8).
    - A grow size passed as a `?:` argument (88421830).
    - An allocation inline whose size argument is `len + 1` (88421D50).
  - CRT/strsafe-style functions near the CRT (882C7840, 88582530) are /O1, like their neighbour 882C74C8. /Oc
    duplicates the epilogue there.
  - Other round 3 rules:
    - A hand-written length loop (`while (*e++); e - s - 1`) compiles with no `clrrwi` (8819B3F8).
    - `s ? (unsigned short)strlen(s) : -1` stored in a short gives the `clrlwi 16` form (88603D78).
    - A find_first_of inline must end with `return last;` (88160848).
    - The 256-byte inline-buffer string constructor copies an uninitialised local store, so the target memcpys
      0x100 bytes from the stack (88236708).
    - Two function-scope 256-byte buffers make the 0x290 frame; block-scoped buffers share one slot (8861B800).
  - Round 3 open items:
    - 881B1DB0 (vsprintf append, 17 off): the capacity check and the grow loop must not CSE `size`. A grow inline over
      the embedded `GrowBuf` gets close; what remains is a register swap.
    - 8821FAF8 (rfind via find_end, 5 off): MSVC orders `p + n + min` as `min + p` then `+ n`; the target does `p + n` first.
      An `unsigned int rest = size - n;` local fixed the stack slots.
    - 889414F0 group (offset-array name lookup, 13 off): the inner loop pointer needs r31.
    - 884F0018 (XAM enumerator create): /O1 gives 35 off.
    - 888371F8/888372C0 (Lua string set): 24 off.
    - 8815C0B0/88279448: `add.` operand order. About 25 more max_ref and add-order forms were tried with no change.
    - 8861B8E0 (`@name="value"` script line parser): LTCG with cl2_c.c as context gives 5 off. The target keeps the
      index_of result in r6 across the rfind call, where we get r8. Adding cx30_core_a.c to the context lets LTCG
      constant-propagate the `'"'` argument into index_of, so the image must have other callers.
      Source: scratchpad w/pl4.c.
  - Session-state stores through a substruct pointer (8899FA00, 8899F838). When the target reloads
    `g_ts4_session_context->state` into r11 and stores through it, while ours puts the reloaded state in a fresh
    register (r7, r4), take a pointer to the substruct (`EventSlot *ev = &ctx->state->event;` or
    `ClockDisplay *c = &...->clock;`) instead of a `SessionState *st` local. The event slot layout is in
    src/xbox360/fam2_session_event.c.
  - Counter pairs updated in both arms of an if (`used++/free--` against `used--/free++`), where the target loads both
    before the branch and stores after it: read them into locals, adjust, then store (8899FA00).
  - A dead `cmpwi rN,0` before the final store comes from a sign split that folds to one expression:
    `if (s > 0) x -= s * 1000; else x += -s * 1000;` (8899F7F8).
  - A pointer field tested with `cmpwi` (signed) is an int handle; declare the field `int` and cast at the dereference
    (8899F520).
  - The same rule matched 8899FAE8: take a `SessionContext *ctx` local, then `SessionConfig *cfg = &ctx->state->cfg;` for
    the copies and `EventSlot *ev = &ctx->state->event;` for the post. A `SessionState *st` local gives 18 off.
  - A dead `addi rX,rBase,0x14` just before a run of field stores means the source took the address of an array
    member: write the stores through `float *v = in->values; v[2] = ...` (8899FE68).
  - A recursive matcher matched first try as a plain for loop with a swap before and after the self-call (8899FB48).
  - Self-relative tables (`(char *)t + t->off`): read the table through the owner (`o->table`, `o->log->table`)
    with no `t` local when the target adds `index * size` to the table base before adding `off` (889A00A8).
  - More open items in this area:
    - 889A00A8 draft (2 off): the state load is in r7 where the target has r10.
    - 889A0540 draft (1 off): the stwx fill order, the same family as 88423C28.
    - 8899F098 (season/career stats update, 15 off): the target loads `pointsAgainst` after the `pointsFor` store,
      where ours hoists it. The streak fix: `if (streak <= 0) streak = 1; else streak++;` (and the mirror form for
      losses) inside a `streak` local.
    - 889A0698 (OR a 128-bit flag block into a 256-bit mask, 6 off): the target loads all four flag words before
      any store. Locals give 8 off, or 4 off with a permuted load order.
      Sibling 8899E040 matched: zero words 0-2, read the four flag words into locals, zero word 7, then store the locals.
      With the global state load, 889A0698 stays at 6 off in the same form (its w[7] zero is scheduled before the
      state load).
    - 8899F6B0: the `clrrwi r3,r11,0` argument to 884EFF18 has not been reproduced (22 off).
    - 8899CDB8 (copy nested self-relative word arrays, 31 off): with `n`/`m` count locals the structure matches, but the
      target computes the source as `(s + j*4) + s->off` and keeps the word in r31 (frame save). No index form changes it.
    - 8899D148 (symmetric 8-wide gap matrix update, 39 off): the target keeps a `clrrwi r31,n,0` loop bound with no ctr loop.
    - 8899DAF0 (format a name with ts4_format_text, then push a 16-byte item via the 88152530 span16 append inline,
      13 off): the target frame is 0xb0 with the item at +0x80, and its copy loads all four words before storing.
      We get a 0x80 frame and an interleaved copy. Source: scratchpad w/daf0.c.
  - First-try matches in this area: 8899DBB0 (nested self-relative tables) and 8899C8F8 (current entry). For 8899C8F8, keep
    a `RelTable *t` local but read the index through the block (`b->table.current`).
- (agAH r6) If the config symbol for an address is not fn_XXXXXXXX, name the function with that existing symbol (for example ts4_profile_internal_is_available at 88936EB8).

### C++ float fabs (agAH, round 6)
- C `(float)fabs(x)` on a float keeps an `frsp` after each `fabs`. If the target has `fabs` feeding `fsubs`/`fsel` with no `frsp`, compile as C++ with `inline float fabs(float x) { return (float)fabs((double)x); }`: the overload drops the rounding. A `bool` return then gives the `li r11,1` / `clrlwi r3,r11,24` tail (8854FDA8 draft).
- `clrrwi rX,rX,0` (rlwinm 0,0,31) as a 64-bit argument comes from a `long long` value cast to `(unsigned int)`. An `unsigned int` parameter passed straight to a `long long` gives `rldicl rX,rX,0,32` instead (8836B5D0).
- A 16-byte state restored with one struct assignment (`a->state = *h;`) gives the target `mr r9,r3` (dead copy) plus interleaved ld/std; two separate u64 stores do not (8841A710).
- If a small function is 1-2 off only in the order of the final store and the `mr r3` (store first on /Oc, mr first in the target), try `/Os`. 883EEA70 matched with `/Oc /Os` and no source change.
- A call through a vtable slot whose argument is loaded after the slot (`lwz r10,0(r3); lwz r10,0xc(r10); lwz r4,...`) is a C++ virtual call: the C function-pointer form loads the argument first. 883E5D68 matched as a .cpp free function calling `sink->Attach(...)` (with /Os).
- A small result returned through a hidden pointer (`addi r3,r1,0x50; bl; lbz rX,0(r3)`) means the callee returns a C++ class with a non-trivial copy constructor: C structs of 4 or 8 bytes come back in registers. Declare the callee `extern "C"` (disable C4190) to keep the unmangled config name (884A9798).
- A loop exit test materialised as `li r11,0/1; extsb r11,r11; cmpwi` in the same register: write `while (!(char)(a || b))`. A `char stop` local puts the extsb in a new register (885191D0).
- A target that keeps the `twllei` divide trap but still differs under /O2 only in register choice may match under `/Os` alone
  (no /Oc): /Os keeps the trap and changes allocation (885A9BD8, `total / per + c * n`; the sibling 885A9BA0 still fails).
- A `clrrwi rX, r3, 0` (a no-op mask) after a call that returns 64 bits, before a 32-bit use, comes from truncating an
  `unsigned long long` return to int. Declaring the callee with a 32-bit return gives `mr` instead (8841E5D0 family).
  This is a call result, not a reload, so it is separate from the CL1 load-copy rule above.
  In the same family, a sign-flag byte read back from the stack only got the target's register numbers when the flag
  was a plain `char`, not `unsigned char` or `int`.
- `rlwimi rA, rB, 12, 0, 19` merging a 4-bit and a 12-bit field (88322E58): write both masks explicitly,
  `((kind << 12) & 0xF000) | (idx & 0xFFF)`. Without the masks you get `slwi` and `or`, even when idx was extracted
  with `& 0xFFF` earlier.

## agAK (b185): strlen family, roster/lobby, page pool and Huffman builder (32 matches, 1 draft)
- **strlen `clrrwi` scan.** The bl-based scan finds nothing: the strlen is inline. Scan for `bne` after `cmplwi`, then
  `subf` and `subi`, with a `clrrwi` within the next 5 instructions. That gives about 150 unmatched functions; most are large.
  - A CRT `mbstowcs` (8856A3F8) matched at /O1 with the MS CRT shape: `if (dst && n == 0) return 0; if (dst && n > 0) *dst = 0;`,
    then `while (count < n)`. Return `count`, not 0, from the early exits.
  - `ANSI_STRING` init (8857E4E0, /O1): `s.length = (u16)strlen(t); s.maximumLength = s.length;`. A chained `a = b = x`
    stores the two halves in the wrong order.
  - A bounded copy before strncat (`lbzx` from `src - buf + d`, test the byte, store, `cmplw d, buf+N-1`) is
    `do { if (*s == 0) break; *d++ = *s++; } while (d != buf + N - 1); *d = 0;` (888412B0, 8883E850). Set `s` and `d` after
    any calls; initialising them in their declarations keeps `d` in r31 across the calls.
- **Self-relative slot search** (889414F0, 889415D0, 889416A8, the old 13-off group): use a `result = 0` local, and in the
  slot loop write `if (len == 0) { result = s; break; }` then `break` out of the entry loop. `unsigned int len = (int)strlen(..)`
  gives the `cmplwi`. For 889414F0 (slots end found by calling `end192`), put the entry search in an inline that returns the
  entry (`find_entry(h, a, b)`). The slot pointer then gets r31, as in the target.
- **Search returning from a second nested loop** with `li r3,0` before the outer loop and one `mr r3,rX; blr` (8899F970):
  `found = 0; ... found = *it; goto done;`. Plain returns and inline helpers do not keep the zero in r3.
- **Session context read once inside a guarded loop** (8899FF98): when the target loads `g_ts4_session_context` after the
  empty test but before the loop body, and loads `->state` on each iteration, write the member loop as
  `it = first; if (it != end) { SessionContext *ctx = g_ts4_session_context; do { ... ctx->state->mode ... } while (++it != end); }`.
- **Config names**: 8899FC10 is `ts4_lobby_remove_fake_player`. agAK/sv.py now looks up symbols.txt, uses the config name,
  and asserts that the source defines it.
- **Address of a local computed before a ternary argument** (`addi r3,r1,X` ahead of the compare, 8886A998): write the call
  in both arms of an if/else. A `?:` argument puts the `addi` after the select.
- **Hidden-pointer bool results** (884A6C48, 88540460): a C function `u8 *f(u8 *ret, ...)` that stores `*ret` and returns
  `ret` matches. For sort predicates that reload the key for each comparison, read the key through an inline that takes the
  owner object (`order_of(x)`), not a cached pointer.
- **Declaration order sets register numbers** for independent self-relative resolves (884879D0): permute the `Link *a/b/c/d`
  declarations. The match was `a, c, b, d`, which is the order in which the ranks are used.
- **Address-taken parameters cached in registers** (8857CBC0 draft, 3 off at /O1): when the target keeps `name`/`len` in
  r29/r28, stores them back to the parameter home after each change, and reloads only after the call that takes their
  address, copy them into locals (`s = name; n = nameLen;`) and write them back by hand.
- **Middleware at 0x8858xxxx-0x8859xxxx is /O1** (page pool 88584868/885847C8/88584AE0/88584B50 and an ar002-style Huffman
  builder at 88590420/88590608/885904C8/885906F0, plus the run decoders 88591230/88591A40).
  - `divwu` by a constant held in a register (no magic multiply) is /O1 (88584CE0). Work on a local copy of the parameter
    so the first stage flows into the second.
  - A ctr loop over a `u8` count needs the count widened to `u32` first (88584B50).
  - When the target keeps a volatile register (r3, r5, r9) live across a `bl` to a sibling, it is LTCG. Compile with the
    sibling's saved source as `--context` (885904C8 with count_len; 885906F0 with sift-down, make_len and count_len).
  - ar002 `make_tree` (88590818, 17 off): the target recomputes `extsh r4,n` inside the retry loop; every loop or tail-call
    form hoists it.
- Open: 889C7AB0 (6 off; data pointer r30/r31 swap around the NetDll_send + registry release), 88956170 (8 off; the
  `clrrwi` copy of the stored hash into the map entry), 889A0CA8 (4 off; vtable/zero scheduling; probably a C++ ctor),
  88400358 (38 off; the deque wrap index uses cr0 `subic.`), 88590B80 (14 off; r9/r10 swap), 887759B8 (frame 0x30 larger
  than ours; the temporaries are probably C++ ones). 8899DAF0/889A7180 (span16 users) still copy with interleaved loads; by-value,
  temp-copy and placement-new forms give the same 13 off.

## agAL (b185): LTCG-list small sweep, then renderer (32 matches, 3 drafts)
- Many entries in agAH's LTCG candidate list (r5l.txt) match on the plain route with ordinary source; try plain /Oc first.
- **Two equal constants kept in two registers** (`li r11,-1; li r10,-1`): the fields have different types. An `unsigned int`
  field set to `0xFFFFFFFF` next to `int` fields set to `-1` gets its own `li` (886EC460, 886EC980).
- **Self-relative begin/end inlines: pass `&o->db->ents` to each inline call**, not a `RelTab *t` local. With the local, the
  second inline reuses the first `off` load; the target reloads it (8883CA60).
- **Registry release family** (find_range_owner 8860D360 + node_visit 8860DBC8): two inline forms exist.
  (a) Registry as an inline parameter, `release(lbl_88D45B38, p)`, gives the `clrrwi r3,rX,0` copy (88995CB8, 887858B0, 8816B1C8).
  (b) A registry read inside the inline after the key test, with int (cmpwi) handle fields, gives `mr r3,r30` and no copy
  (881522C8, 88152340, 88711998). ts4_destroy_owned_object (88174B18) is the free form: registry, else CRT free fn_885651F8.
- **Open in that family:** 8887EB10, 88AFEEB0, 8817F670, 881ADFD8 and 8815BB30 load the registry once before the loop and reload it only after node_visit,
  never after fn_885651F8. Declaring `__declspec(noalias) void fn_885651F8(void *)` (CRT free) and reading the registry
  before the `p` test hoists the load, but the reloads after visit are still missing (21 off).
- Element read through an inline slot accessor at each use (`*vslot(v, i)`) gives the clrrwi copies of both `first` and the element (8876DEE0).
- **A string walk that reads b at a's offset** (`lbzx` with b - a): keep one cursor p over a and read `b[p - a]` (88639D48). The same holds for a copy loop that stores
  `out[s - p]` (88605FA0). A separate `n = value` local gives the leading `mr r10,r3`.
- `return A || B || C;` as a u8 gives the `li r11,1 / li r11,0 / clrlwi` tail where if/return forms give `bltlr` (886603C0).
- Float literal 0.5f in an LTCG range: matches on LTCG **without** pp1_pool_primer.c (__pool@_0 = lbl_8814B910); spec `"context": []` (88779248).
- Vector `back()`/`pop_back()` inlines taking `&s->v` reproduce a dead `addi` of the member address and an early `last - 1` (886ED110).
- ts4_hash_find_null_888689F8 takes **no arguments** (r3 is not set before calls to it); cx18_core_c.c declares an idx parameter.
- Drafts: me_88942A90 (2 off, store order of a Vec3 copy), me_887965D8 (3 off, add association), me_886EBDA0 (3 off, fdivs/fsubs order).
- agAK gameplay addendum (b185). The totals are now 35 matches and 4 drafts.
  - 888C0528 (random integer in [0, n) from the generator in the game globals) matches only with the guard written as `if (n != 0) { ...; return x % n; } return 0;`. An early `return 0` puts the zero path first, with `bne` instead of `beq`.
  - 88659BB0 cannot be matched in its current form. Its case 3 falls into the next symbol, ts4_set_u8_off2_88659C24, so the size in the config is short.
  - Open items:
    - 88662458 and 88662510 are 6 off. The base pointer gets r11 where the target has r10, both plain and LTCG.
    - 888CAA98 is 4 off. The three-float colour store loads 0xF0 before g_ts4_event_value.
    - 887F1F00 belongs to the self-relative (-1 = null) family. It is missing the target's no-op `clrrwi r10,r10,0`.
    - 888D93B8 and 888D9498 forward 4-byte structs by value. The target spills them to the stack and repacks them with `rldicr 32`.

## agAN (b185/b186): renderer small sweep (12 matches, 1 draft)
- **LTCG caller of an unmatched callee:** a correct but not byte-exact callee definition in `--context` is enough when
  the caller only depends on which argument registers the callee leaves intact. 886FCB48 reuses r3/r4 after
  `bl fn_886F3798` and matches with drafts/me_886F3798_nearmiss.c as context. The callee stays a 14-off draft.
- **`int res = 0; if (A) res = f(x); else if (B) res = g(x); return res;`** gives the early `li r10,0` / final
  `mr r3,r10`, with both calls as tail `b`. Early `return f(x)` forms lose the `li` (88737DF8). Write the guard as an
  inline returning `u8` `A || B` to get the `li 1 / li 0 / clrlwi / cmplwi` shape.
- A u16 vector read through `size()` and `at()` inlines that take `&l->frames` loads `last` before `first` and
  reloads `first` for the element (886F3C28). Direct `l->frames_end - l->frames` CSEs the load.
- Vector clear with a memcpy per 32-byte element: `v->last = copy(v->last, v->last, v->first)`. The element is
  `unsigned char b[32]` (u32 or float arrays inline the copy). The loop is `for (n = last - first; n > 0; --n, ++first, ++dest)`,
  and the increment order decides the order of the `addi` (88707630).
- `__vsldoi` is not in vx1_vector.h. Declare it, with `#pragma intrinsic(__vsldoi)`, as w6a_types.h does.
  D3DCOLOR unpack loop: `out[i] = __vmaddfp(scale, __vupkd3d(__vsldoi(v, v, 4), 0), bias)` with `v = __lvlx(&packed[i], 0)`
  matches only on LTCG (ctx=[]) in the indexed `for (i = 0; i < 16; i++)` form (886EB188).
- The float at 0x8814B440 is the config symbol `g_ts4_event_value`. Under LTCG, a reference to `lbl_8814B440` fails only on the
  relocation name (886F5DA0).
- Open: 88703DC8 (12 off) loads end/begin into r8/r7 and copies them to r3/r4 with `mr`; tried locals, a vector by value,
  and an inline sort wrapper. 886ED6D8 (14 off) is a 7-bit bitfield countdown; the target reuses the loaded byte register as the
  rlwimi base where ours adds `mr`.

## agAM (b185): gameplay sweep, the r11/r10 base-register family
- **Base pointer in r11 vs r10 / reloaded pointer gets a fresh register (the 88662xxx family) is solved by a sub-struct
  address.** When the target reuses the dying base register (e.g. `lwz r11,0x74(r10); lwz r11,0x98(r11)`, or a reload
  `lwz r11,0x28(r8)` followed by stores through r11) and ours picks r7/r4/r9, put the accessed fields in a sub-struct and
  pass its ADDRESS: `FrameRef *t = &p->ctx->state->contact; if (!frame_unset(t) && t->frame - ...)` (88662458, 88662510),
  `set_pair(&h->x->pair, v)` (88661D28, 886624C8), `clear_flags(&s->g->f->block)` (8865C1F0, 886690B0),
  `clear_quad(&s->g->p->quad)` (8866D218, LTCG). Inline helpers taking the plain object pointer, locals, declaration
  order and every /O level do not change it.
- 8865C1F0 symptom of the same family: the zero constant takes r11 and the base r9/r10 (target: base r11, zero r10).
- 88662458 is the "swing now" test from docs/gameplay (contact frame state+0x98 valid and <= clock + PlayerTuning+0x740).
- Open: 8864E640 (Vec3 += three float args) keeps load/add/store per component and `fadds f13,f1,f0` (arg first). Plain
  field `+=` reorders (7 off); a `float *p` per component keeps the order but the add operands come out `f0,f1` (3 off).
  888C72E8 (1 off): `return s->b || s->d == s->a;` gets the loads right but `cmplw r11,r10`.
- 88644738 draft: a dead `addi r3,r3,4` (address of the sub-struct used by the ramp branch) is not reproduced by an inline
  on `&s->r`, a C++ member function, or a base-class `this` adjust. Everything else matches.
- Before writing a draft, check `src/xbox360/drafts/` and git for an existing one: integration commits drafts as they appear,
  and several gameplay addresses (8864E640, 88644738) already had annotated drafts from earlier agents.
- Cursor-step family 886FC938/886FC990/886FCA90/886FCAE8 (b186): read `s->st->pos` directly at each use, with no local.
  That gives the `clrrwi r9,r9,0` copy before the inc/dec and the reload after the store. The forward variant needs the
  early-return guard `if (limit <= 0 || limit <= pos) return 0;`. The backward variant needs `if (pos > 0) { ...; return 1; }
  return 0;`, because an early return there puts the `li r3,0; blr` first.
- The order of the declarations in `T *p = v->first, *e = v->last;` sets the load order. Declare `e` first when the target loads +4 before +0 (886EC548).
- Open: 886F9020 (12 off) loads its 1.0f-like constant as `addi r8,(g_ts4_script_constants+0xF70); lfs f13,0x38(r8)`.
  Neither `g_ts4_script_constants[1002]`, a sub-array cast, nor a literal (it goes to the pool) reproduces the 0xF70 base. 886EEBC0
  (23 off) resets display render-target bindings. The target keeps a dead `addi r9,r11,0x40` and an `mr r4,r9` copy of 0xFFFFF for the last store.
- Retried with fresh forms in b186, no match: 886F3798 is best at 11 off, with `u32 ia = s->id_a;` before the module
  local and `id == (*it)->id` (scratch form in the draft note). 88703DC8 stays at 12 off; iterator structs, a vector by value, and
  inline wrappers all failed.

### agAM round 3 (b187)
- The sub-struct rule worked on its first try at 88917340. Pattern: `lwz r11,X(r11)` followed by three stores through r11, where ours moved the pointer to r6. Fix: group the stored fields into a sub-struct and pass `&g->req->ev` to a static setter.
- 8865FFF8 went from 12 off to 1 off with a `float *bl=&holder->target->blend` pointer plus an ease inline under fp_contract(off). The remaining fadds operand order resisted `+=`, temporaries and an add inline.
- When the target swaps float registers (8865AC90) or vector registers (88650B80), the sub-struct rule does not help: it only fixes reuse of a GPR base register.
- Sweep tip: filter gameplay.txt to 60-240 bytes and grep the disassembly for two or more `lwz r11, X(r11)`. Note that column 2 of gameplay.txt is the size in bytes, not instructions.

### agAM round 4 (b188)
- Hash-post glue (88868A88, 88868B48): build the key {engine->f27c, arg, 1} and the null Ts4Handle12 {0,0xFFFFF,0} in the order k.b, k.c, n.*, k.a, then call ts4_hash_find_arg_88180F08 with key as a pointer and the handle by value. This matches on the LTCG route only (ctx=[]); the plain route gets the wrong store order.
- 888EE7E8: the "a && (m==4||m==2) && (u8)call()" chain matches as a single return expression. An if/return-0 ladder adds about 8 instructions.

- agAN: 887245B0 (two id-slot inits {0,0xFFFFF,0}) matched only once the slot init was a `static __inline` helper called twice; writing the stores inline put them in the wrong order.
- agAN: 886F1798/1810/1888 (getters that return a struct by value through a vcall) matched only as C++. In C, the by-value form was 23 off and the pointer-to-result form (`T *f(T *out, L *l)`, vcall `get_id(out, s)`) was 11 off. Dropped because C is required.
- agAN: Inline vector push_back (`if (last != end) { if (last) *last = v; ++last; } else grow(vec, last, &v);`) matched with the not-full branch first and the value copied to a local `u32 k = key` before the test. The vector at +0x54 is {first, last, reserved, end}, with end at +0xc (886F62B8, 886FA908).
- agAN: When a caller keeps values in volatile registers (r8, r9) across a `bl`, it is LTCG. Pass the callee's source file as context: `ltcg=True, ctx=['src/xbox360/cx44_a.c']` matched 886F62B8 and 886FA908.
- agAN: For a find-then-check (`for (p = t->first; p != t->last; p++) ...; if (p == t->last) return -1;`), re-read `t->last` inside a static __inline helper. Caching first/last in locals swapped the load order (88701118).
- agAN: The stack temp in a ternary (`subi r11,r1,0x10; stw; lwz`) comes from a C++ class ternary, `c ? Key(a) : Key(b)` with a user ctor. Use an extern "C" free function in a .cpp file. A `cmpwi` on a pointer test needs `(int)p != 0` (8877A170).
- agAN: If a callee reads f1 that the caller never sets, it takes a float parameter the caller passes through. Check the callee before writing the prototype (886F39F0 -> fn_886F38F0(slot, float)).

### agAM round 5 (b188/b189)
- When a constructor sets the null handle {0,0xFFFFF,0} on a member, take a Ts4Handle12 *h=&o->handle and store in the order a, c, b. This is the sub-struct rule again; it matched 8887CAD0.
- A constructor chain with the intermediate vtable inlined (base ctor, mid vtable, field, final vtable) matches on the LTCG route only. Write both vtable stores literally (88887FA0).
- A vector count used in a bounds check: `count(&o->vec)`, an inline that takes the {begin,end} sub-struct, gives the target's `mr r8,r11` copy of begin (8890DAA8).
- A ctor wrapper that stores the vtable through the base ctor's return value r3 while saving r31 (887F4C18 family) looks like C++ `this` return semantics. I did not reproduce it in plain C.
- agAN: Several boolean OR chains matched in plain C with `a || b || c` returned as unsigned char. A sub-chain from another object went in a static __inline helper (886F3B08).

## agAM round 6
- "This-return" constructors (target stores via the base ctor's returned r3 while still saving r31; 887F4C18, 888B48C0, 886C6660) did not reproduce from plain C or an extern "C" .cpp form (best 5-12 off). Skip them.
- A __vector4 out-param call (8865EC70) cannot be rewritten as a struct return-by-value. That form grows the function by 0x18-0x28; keep the explicit out pointer.

## agAO (b190): gameplay queue, smallest first (2 matches, 2 drafts)
- **A flag test that returns 1 or `count == 0`** with `li r3,1; beqlr; subic; subfe; and` (888C1C80): write
  `int r = 1; if (flag) { if (count) r = 0; } return r;` with an `unsigned int` count. `return !f || !a` and
  `?:` forms give `cntlzw`/`extrwi`.
- **One flag store, then a branchy 1/2 store** (888C63B8): `o->flag = !on; if (on) *p = 1; else *p = 2;`. A `?:`
  or `2 - (on != 0)` folds the value into `addi`.
- The same `!o->b42` value stored through four pointers (888C5EB8) stays 6 off. `v = 0; if (!x) v = 1;` gets the
  branch, but the first pointer load is scheduled after the select where the target loads it before.
- Open items:
  - 8887B380 draft (1 off): the operand order of the key `cmplw`. Its sibling 8887B328 is at 0.95.
  - 888E9840 draft (2 off): `mr r31,r3` comes before the `stw r4` home store in the target.
  - 886E7738 (4 off): two `lvx` vector constant stores are scheduled after the first int store. Loading into
    locals first and the .cpp build do not change this.
  - 8888AC30 (4 off): three self-relative args to fn_88636FA0 (`rel(&t->a)`, ...). r5 and r6 are swapped.
  - 888C1B88/888C1B58 (4 and 7 off): the target loads `s->total` after the `c->cfg` load and the field stores.
  - 886696A8 (6 off): the target reloads `o->inst` for the second test, and the call uses a `clrrwi` copy.
  - 888CB9D0 (18 off): a nested self-relative lookup. The index adds come before the base add.
- 88884488, 88884C88 and 88884618 call XAM wrappers (8857Bxxx). 887F4C18-887F4EC8, 887F4FA0 and 886C6660 are
  this-return constructors. Skip all of these.

## agAP (b190): renderer small sweep (4 matches, 1 draft)
- `lwz; addi rX,rX,0; subic; subfe` (a pointer-not-null bool) is `return 0 != o->ptr;` (886EFA08), the
  `!=` counterpart of the `0 == p` rule at line 116.
- A 64-bit `rldicl/rldimi/clrrwi/or` shuffle that reverses four u16 lanes matches the plain mask form
  `((x>>48)&0xffff)|((x>>16)&0xffff0000)|((x<<16)&0xffff00000000)|(x<<48)` on a `unsigned __int64` (886EB1D8).
  The swap-halves-then-swap-pairs forms do not.
- Cubic Hermite evaluation `(float t, const Hermite *h)` (886EB298): fmsubs/fnmsubs come from writing
  `p0*c - p1*c + m1 + m0` and `p1*k - p0*k - m0*c - m1` literally, with `a*t3 + b*t2 + m0*t + p0`. It matched first try.
- Field-init block with a dead `addi rX,rB,0x40` and an `mr r4,r9` copy of 0xFFFFF (886EEBC0): clear the int array with a
  `for (i = 0; i < 4; i++)` loop (pointer locals and inlines drop the addi). The last range is stored lo, extra, hi.
- Open: 88778CD0 (3 off, register numbers of a `flag == 0` byte test, draft); 886F3588/886F35B8 (6 off, the
  self-relative pair: the target loads `d->state` before `s->data`); 886F26B0 (LTCG vector+field init, 7 off with
  random store orders); 88703D18 (6 off: the target sets the 0xF5DD52E9 hash in r4 before the registry null test;
  inline, local and C++ forms all put it after); 886EFAC0 (ring cursor; the target reloads idx/ring after the `cur` store);
  886F5838 (14 off, r10/r11 swap in a keyed 30-entry lookup returning a Range).

### agAO round 2 additions
- Xbox 360 ABI: a float argument also consumes a GPR slot. In `(R*, const float *x, float t)`, x arrives in r4 and t in f1 (8890F008).
- With LTCG, a callee given in ctx gets inlined. Prefix it as `flags(/Ob1):src/...c` to keep the `bl` (88660470).
- A small result struct that the target zeroes word by word (`li r11,0; stw` x N) wants explicit field-by-field zero stores, not `= {0}` or memset (888CCEE0).
- Float range check `t >= lo && t <= hi` written as a static inline helper gives the target's `li 1/0; clrlwi` bool tail.

### agAP (b190) round 2 addendum
- `if (e != find(begin, e, &key))` (end on the left) gives `cmplw r31,r3`. Flip the operands if the target shows the opposite order.
- In constructors with an inline AVec init (handle tmp, then a `ts4_if_call_seq_u32_lbl_88D45B38_88255AA0` call on `&tmp` and on `&v->ctx`), copy the avec_init pattern from src/xbox360/cw16_core_b.c. It matches under plain /Oc (88721CB0, 887261D0).
- A mangled member callee (`?name@ts4_obj_ADDR@@QAAXXZ`) needs a `.cpp` file that declares `struct ts4_obj_ADDR { void name(); };` and an `extern "C"` wrapper for the function.
- In countdown loops, the order of the for-init (`p = base, i = N` versus `i = N, p = base`) sets the order of the `addi`/`li` instructions. Try both.
- Paired -1 field stores: give one field `unsigned` 0xFFFFFFFF and the other `int` -1 to get the target's register reuse. This confirms agAL's rule (8873B6E8, 887482D8).
- Dropped (more than 4 off): 88747E58 (overlapping u64/u32 stores), 886F31F8, 886EE6E0, 88771258, 88718210, 8877DDC0 (the target reloads `*self` once after the call).

## agAQ (b190/b191): gameplay queue lines 77-100 (8 matches, 1 draft)
- **Dead store kept** (888B0FF8: `stw r11,0xa8; stw r8,0xa8`): `{ u32 *h = &o->hash; *h = 0; o->hash = K; }` keeps both
  stores. Two plain `o->hash =` stores, or an inline clear helper, drop the first one.
- **`new T[n]` overflow guard** (888866E8: `cmplw n,0x1FFFFFFF; slwi; ble; li -1`): pass
  `n <= 0x1FFFFFFF ? n * 8 : 0xFFFFFFFF` straight into a static __inline allocator. Write the allocator as
  `if (!heap) return crt_malloc(size); return heap_alloc(heap, size);`, because the `if (heap)` order flips the branch. A
  `size` local with an if-assign is 4 off.
- A six-word clear that the target writes after the vtable/`addi r7` setup (888663D0, LTCG with a
  `flags(/Ob1):src/xbox360/cx18_core_b.c` callee context) matched with a local `u32 *p = o->f20; p[0]=0;...`. A loop is 22 off.
- **A `bdz` ladder over `mtctr kind`** (88879280) is a small `switch` with sparse cases plus an explicit list of the default
  cases up to the bound (`case 0: case 1: ...: case 8:`), with values above the bound falling through. It matched first try in plain C.
- **String clear** (888F4E70: `if (b != e) { *b = 0; e = b; }`) as a static inline on a `{char *begin, *end}` sub-struct
  matched first try. A vector erase-all is `ts4_copy_down_8817EEB8(v, v->first, v->end)`.
- A `x ? -1 : 0` int store after a vcall (888DF8E8) compiles to `subfic/subfe` and matched in plain C. The vcall result is
  the slot pointer.
- A destructor with a vtable store, a global clear and member teardown calls (887EE430) was 9 off plain and matched on
  LTCG with `ctx=[]`. Try LTCG early for dtors. Its sibling 88658DC8 is still 4 off on every store order, plain and LTCG.
- When an LTCG caller keeps a value in a volatile register across a `bl`, look for an existing context model of the callee
  (`src/xbox360/cx34_ctx_af5c0.c` for fn_888AF5C0, `pr2_signin.c` for ts4_pad_record_find_88614938) before skipping.
- Open: 88888C80 (2 off, draft): `lis` r9/r10 swap between the vtable and the global. 888DF9C0 (9 off): flag/vtable/handle
  ctor scheduling. 888CAD50 (10-11 off): ctor with an embedded circular list; an `emb_list_init(&o->list)` inline
  gives the `addi r10,+0x2c; addi r10,4` but the scheduling stays off. Skipped: 8866C988 (fn_8866C8B8 has no source to give LTCG
  the r4 preservation), 888B7360 (tail call with a live cr6), 888C0818/888D9420/888B8F58 (vector or 64-bit float packing),
  88883CD0/888842F0 (XAM/CRT callees).

### agAP (b190) round 3 addendum
- Inline AVec init at a high offset (0x80): if the inline `avec_init(&s->items, 0)` keeps `v` in r29, write it out as follows. Store begin and end through `s->items`, then use a block-local `AVec *v = &s->items; v->ctx = 0; call(&v->ctx);`. This gives the target's `addi r11,r31,0x80; addi r3,r11,8` (88723C70).
- A singleton ctor that ends with `lbl_X = s;` after `s->hash = K;`: plain /Oc swaps the last two stores. Write `lbl_X = s; s->hash = K;` and build with LTCG `ctx=[]` (88723B58). The same trick did not fix 88724CC0.
- atan2 argument order: `lfs f2,0(r31); lfs f1,8(r31)` comes from `fn_88564BF8(v->z, v->x)`. The loads are emitted right to left.
- For a range splitter whose zero constant lives in its own register, declare `max` first, compute `chunk`, then `off`, and store `end = off + sz` before `off += sz` (886EC7C8).
- For a C++ struct-returning virtual call followed by an IsNull test (886EF330, 886EF3B8), the target frame is 0x70 and has a dead `li r10,0`. No form I tried reproduced it.

## agAR (b192): gameplay queue lines 101-119 (3 matches, 4 drafts)
- **A default return value that the target puts in r30 before the first call** (888C70F8: `lis/addi r30` before `bl`; at the
  end `mr r3,r30`): write `const char *r = DEFAULT; ...; if (k < 6) r = table[k]; return r;`. An early `return table[k]`
  drops the saved register.
- An entry loop with a nested guarded table lookup and a default fallback matched first try in plain C (8890DCC8):
  `if (e->idx >= t->n || (k = t->map[e->idx]) == -1) k = t->def; e->slot = &t->slots[k];`, with `end`, `begin` and the
  global loaded into locals before the loop.
- A transform fetch into a 64-byte stack struct, three `scale * t[i]` stores, then `memcpy(out, &m, 0x40)` matched first try (8887A5B8).
- Two float constants that the target keeps in f31/f30 across three calls (88693FA8): `float hi = K0; float lo = K1;` locals
  give the right loads, but MSVC loads them straight into f1/f2 and copies back (4 off). Inline helpers and loops do not fix it.
- **The `li` of a non-zero constant scheduled one store later** (888FA078 `li r11,-1`, 888FD948 `li r8,1`, both after the first
  zero store) stays 2 off in plain, LTCG and .cpp builds, whatever the store order or field types. These two are the same
  sub-struct (`{0,0,0,0,0xFFFFF,0}` range init). Drafts are saved.
- A remove-all over a u32 vector (88879AA8/88879B28, sibling 887ED8C8 at 0.96, 887ECA58 at 0.91) is 2 off: the else-branch
  increments of `p` and `p+1` come out in the wrong order. Drafts are saved.
- Self-relative row lookups (888C51D0): write `int *b = &t->rel; row = (Row *)((char *)b + (pl->row * 16 + *b));` to get the
  target's add order. A hoisted `lfs` then needs a `lo` local, but r9/r10 stay swapped (11 off). Dropped.
- Dropped: 888C1910 (the target does `neg base` before the float math; every form gives `add` then `neg`, 28 off), 886AD1F0 (the zero
  stores are interleaved with the float compare, 9 off), 8886FE50/8886FED0 (index-0 self element plus a clrrwi array
  lookup, 20+ off), 888C15A0 (64-bit bit-iterator copies), 886A80F0/886DC610/888E6C78 (not attempted).

### agAR round 2 (lines 120-133: 7 matches, plus 2 earlier drafts promoted)
- **Vector remove-if loops where the target bumps `p+1` before `p`** (88879AA8, 88879B28, 887ECA58, 887ED8C8): keep `n = p + 1`
  as its own induction variable inside a guarded do-while, and pass both pointers to an inline erase on `&o->v`:
  `p = o->v.begin; if (p != o->v.end) { n = p + 1; do { if (hit) erase_at(&o->v, p, n); else { n++; p++; } } while (p != o->v.end); }`
  with `erase_at(v,p,n) { if (n != v->end) fn_88562DC0(p, n, (char*)v->end - (char*)n); v->end--; }`. A separate `Vec *v`
  local swaps r28/r29. 88933D58 (the vec at +0 and an erase followed by a deleting-dtor vcall) is still 30 off: the target reloads `end`.
- **A field reload after an unrelated store** (8887CA38: `lwz r3,0x10(r3)` again after `stw 0x58(r3)`): write that store
  through a pointer local, `{ u32 *h = &o->hash; *h = K; }`. This is the same trick as agAQ's dead-store rule.
- **Bounds-checked element access with `clrrwi` copies** (888C99E0) matched first try with `size()`/`at()` inlines per vector:
  `if (i < svec_size(&o->v)) (*svec_at(&o->v, i))->x = 0;`.
- **Vtable slot loaded before the argument `li`s** (888CE028): a C-struct vtable call schedules the `lwz` after the
  args (4 off in C and .cpp builds). A real C++ class with `virtual` methods in a .cpp file matches. The C version had also hidden a wrong
  callee: base-estimated callee addresses can be off by one function, so check the reloc name the checker prints.
- Open: 888C4160 (pop-front loop matches; LTCG gets 4 off on r8/r11 in the trailing three-float store, plain /Oc adds an
  `fmr`), 888D82E0 (rel-table binary search; the target keeps t/rel in r30/r31, 34 off in every form). Skipped:
  888D6608 (callee keeps r4 live, LTCG without source), 888D6A30, 888DA428, 888DC298, 88916F48 (vector), 887F8710, 88879098/
  888791E8 (string format), 8887EB10, 888C3198.

## agAS (b192): renderer queue lines 61-88 (9 matches, 4 drafts)
- **Vector field copy with loads in reverse order** (`lfs 0x38; lfs 0x34; lfs 0x30; stfs x,y,z`, 8877D578): write it as an
  inline `vec3_set(out, it->pos.x, it->pos.y, it->pos.z)`. A struct assignment gives `lwz/stw` word copies instead.
- **Tidy with the inlined element copy** (8873EFC0, 16-byte elements copied as `stw a` then a 12-byte sub-struct): give the
  element `{u32 a; Rest12 r;}` and copy `d->a = s->a; d->r = s->r;`. When the target loads `begin` for the free test *before*
  the `end` store, compute the copy result into a local, read `b = v->begin`, then store `v->end = e`.
- The 8872F300/88737B40 dtor family (vt; `ts4_object_finalize(&o->vec)`; free buffer via lbl_88D45B38 or fn_885651F8; base vt;
  member dtor) matches in plain /Oc with a `bytevec_tidy` static inline. Look for more siblings with vt 0x880F21xx / base 0x880F34xx.
- Two AVecs back to back (8872CD50) match with the plain `avec_init` inline called twice. One AVec at 0x80 followed by a null
  handle (88723BE0) matched with the agAP round 3 block form plus `h.a = 0; h.c = 0; h.b = 0xFFFFF;`.
- A vcall wrapper whose target has a single exit and `li r3,0` set before the first test (886F5FB0) matched on LTCG
  `ctx=[]` with `void *r = 0; if (...) { ...; r = call(); if (r) o->f = r; } return r;`. Plain /Oc is 2 off (r5 home store order).
- A 12-byte `memcpy` into a `__vector4` local must stay a call: add `#pragma function(memcpy)` (886F0278) and `#include "vx1_vector.h"`.
- ori constants are zero-extended: `lis 0x6f80; ori 0xa671` is 0x6F80A671. Do not apply the addi sign fix to ori.
- Self-relative add order in a remap loop (8876E380) was fixed by block-scoped `u32 *s = src->first; u32 *d = o->out.first;`
  inside the loop body (the OP1 local count), which `tools/operand_order_pad.py` had confirmed with 2 pads.
- Drafts: 886F0278 (2 off: the target loads lbl_88D45AD4 before the slwi of the index); 88720B70/88720E48 (3 off:
  singleton-clearing dtor, the lis pair and vt/global store order, the same family as agAQ 88888C80).
- Dropped: 8876DCB8 (the target reloads the self-relative offset for the second key test; inline accessors CSE it), 886F0440
  (the local-static hash table; the `li r9,1` result is hoisted before the loop, 13 off), 88778A40 (the two vcall tails are merged),
  8876D0F0 (stores a double 0.0 from g_ts4_script_constants+0x58 and the LTCG scratch pool does not land there), 88771D80 (23 off).
  Skipped: 886F7110 (bit tricks), 886EC9B0/886F5D10 (vector packing), 886F39F0 (the LTCG callee fn_886F38F0 has no source).

## agAT (b193/b194): gameplay queue lines 134-162 (5 matches, 1 draft)
- **Constructors that keep dead base vtable stores** (8887A3E8: `stw` base vtables at +8/+0xc, then derived vtables
  overwrite them): build a real C++ constructor in a .cpp file whose inline base constructors store
  `extern "C" char lbl_X[]` into a plain `const void *vt` member. Do not use `virtual`: real vtables relocate as `??_7...`,
  which fn_check rejects against `lbl_` targets. The spec key is the mangled ctor name (`??0Name@@QAA@PAX@Z`).
  symbols.txt already holds mangled names. Placement-new wrappers add a null check, so don't use them.
- **A self-relative table write with a hashed bool** (889170B8): if a header-field store must stay before the `d->rel`
  load, store it through a pointer local (`unsigned int *p = &d->bk; if (b == 0) *p = H0; else *p = H1;`).
  Hoist the two value hashes into locals `t`/`f` and use if/else stores. A ternary gives the wrong `lis` register.
- Vector-of-12-byte loops (88880AF8): use `size()`/`at(i)`/`clear()` static inlines on `&o->vec`. They give the target's
  vector base in r29 and the byte offset in r30. A raw `n`/`off` loop swaps the registers.
- A rel-table row search (888C2AA0) and a 28-byte entry flag set (888F0798) matched first try with `(char *)b + *b` row math.
- Draft 888C5C00 (2 off): LTCG with `flags(/Ob1):src/xbox360/pr2_signin.c` (ts4_pad_record_find_88614938 keeps f1/f2 live).
  Only the `fmuls` operand order differs (target f2,f0). No operand order, helper, or /Ox build fixed it.
- Open or dropped:
  - 888795F8 (17 off): LTCG with the fn_881643D0 ctx gives the right lwzx shape, but the callee's free r5 is used where the target saves r31.
  - 886B7A60: the 0x8c offset is recomputed after the call, 15 off.
  - 888C5D80: -1 is kept in r25 across the loop, 30 off.
  - 886B14E0 (dtor of 886B1578's object, 25 off): vtable stores must stay ahead of the buffer loads; pointer-local stores and LTCG don't help, so try real C++ dtors next.
  - 888B1960: the float copy keeps load/store order and an early global load; 31 off in plain and LTCG builds.
- Skipped:
  - 886D0808: LTCG passes cr6 to a callee that has no source.
  - 886D5028 and 886B1578: the callee keeps r4 or r3-r6 live, and it has no source.
  - 8864E310 (VMX), 8865DAC0 (jump table), 888DFA40/888E7278 (64-bit packing), 887F8EE8.

## agAU (b194): renderer queue lines 89-124 (8 matches, 3 drafts)
- **A ternary picks `cntlzw/extrwi/xori`; arithmetic on the compare picks `subic/subfe`** (8876D8D8, 8876D970): write
  `st = (d->id == K) ? 5 : 6;`. `(d->id != K) + 5` and `!(d->id == K) + 5` both give the carry form.
- **The target loads a global before the store it follows in the source** (8873B890: `lwz lbl_88D45A4C` before the `stfsx`):
  read the global into a local first, `s = lbl; o->x = (float)((double)a / (double)b);`.
- **Clearing a vector in a dtor with the inline erase(first, last)** (8873DF48, 0x30-byte elements) matched with `v = &o->v;`
  after the vt store, then `elemvec_erase(v, v->first, v->last)`: an assign loop over `(end - src)/0x30`, a range destroy, `v->last = p`.
- **The device global is read before the fence test** (88731158: `lwz r3,0(r11)` sits before `cmplwi`): pass the device as
  an argument to an inline, `gpu_block_on_fence(gpu_device(), old->fence)`, with `if (fence)` inside. `gpu_device()` returns
  `KeGetCurrentProcessType() == 2 ? *__imp_VdGlobalXamDevice : *__imp_VdGlobalDevice`.
- **A self-relative table search with `li r3,0` before the loop and `cmplw count,i; bgt`** (88779330, sibling 88779288 at 0.99):
  `Entry *r = 0; for (i = 0; t->count > i; i++) { e = (Entry *)((char *)t + (i * sizeof(Entry) + t->rel)); if (*key == e->key) { r = e; break; } } return r;`.
  When the array is a sub-struct, read `t->second.count` in the condition and take `RelArray *a = &t->second` inside the body.
- **Find-then-erase in a u32 vector with `last` loaded before `first`** (88779428): use a block-scoped `u32 *e = o->list.last;`
  and test `e != p`. `o->list.last != p` alone still loads `first` first (2 off).
- **`cmpwi` (signed) null tests on pointers** (88778AD0): `(int)p != 0`, in a .cpp file with a smart-pointer struct. The branch
  tails are still merged, and `this`/`&h` land in swapped r30/r31 (26 off). Dropped.
- **Do not attempt the 8872xxxx dtor family that frees via lbl_88D45B38** (88720518, 88720470, 887239C0, 88721E38): the target
  caches the allocator global in r31 across both member tidies and reloads it only after the 886131F0 call, not after
  fn_885651F8. That needs LTCG knowledge of fn_885651F8, which has no source. Skipped.
- Drafts: 886F99C8 (LTCG `ctx=[]`, 3 off: the target holds the Res* in r11, the inlined lookup puts it in r3); 886F1A70 (3 off:
  `lhzx` operands swapped, and the map head is loaded after the iterator, in .cpp/LTCG builds too); 8876E0B0 (2 off: `o->a` is loaded
  after the stack local; needs `changed = 0` after the call to free r30).
- Skipped for 64-bit/struct-by-value packing (`rldicr`): 887696F8, 88717178, 88720F10, 8875EAC8. Not attempted: 886F76A0,
  886F8518, 88774260, 88778DC8, 886F0090, 88720DA0, 88721F10, 88728A48, 8872A910, 8872B8A0, 8877C0F0.

## agAW (b194): renderer queue lines 125-133 (1 match, 1 draft)
- **`divw.` record-form element count** (886ECC38: `size = (last-first)/0x68` tested after a bool vcall): write the
  subtraction inline in each test, `if ((o->last - o->first) == 0)`. A named `int n` local gives `divw` plus `cmpwi`.
- Self-relative table search returning a field of the hit (8877C0F0): the inline `at(t,i)` used for both test and result
  gets the `slwi`/re-add tail, but the target loads `t->rel` before `li i`/`addi t` (3 off in plain and LTCG). Draft saved.
- Dropped: 88773390 (ctor with 4 null handles; the target interleaves stores via r3 before `mr r31`, 19 off in all forms),
  886EEC48 (float do-while; the target keeps the new `t` in f13 for the compare and reloads it for the loop test, 25 off).
  Skipped for rldicr packing: 88701E80, 8871AF40.
- Coordinator rule: never save specs keyed by a mangled C++ name (`??0...`); put C++-only ctor/dtor matches in drafts/.

## agAV (b194): gameplay queue lines 162-174 (1 saved match, 2 ctor matches in drafts, 1 draft)
- **Stack round trip `addi rX,r1,0x50; stw v,0x50(r1); lwz rY,0(rX)` for a selected hash/colour** (888CB4D0, matched):
  build the value as a by-value C++ temporary, `struct Hash { unsigned v; Hash(unsigned x) : v(x) {} };`
  `Hash h = flag ? Hash(H0) : Hash(H1); rec->id = h.v;` in a .cpp with an `extern "C"` function. This should
  also help the open 886A37D0 and 88669B98, though 886A37D0 still fails on its `clrrwi` copy (30 off).
- Self-relative base used twice with `mr r9,r10` copy: route the first use through an inline member
  `char *base() { return (char *)this + rel; }` and write the second one out as `(char *)s->blk + s->blk->rel + K`.
- **Constructors on the shared base fn_88617D88 where the vtable store sits among the member stores** (888DDF98,
  888DE430: full matches): use an inline intermediate base `struct Vt : Base { Vt() { vt = lbl_X; } };` where
  Base's ctor calls fn_88617D88(this). Then add members with inline ctors in field order: range record
  `{lo=0; cur=0; hi=0xFFFFF}`, `M() { fn_8816D1A8(this); }`. The rest of the body goes in the derived ctor.
  Per the coordinator, mangled `??0` keys must not be saved as specs, so these are in src/xbox360/drafts/.
- Open:
  - 888C80A0 (2 off): same ctor shape, with `w1c = 0` before vt in the intermediate base. The `lis` of the global
    `lbl_88D4595C = this` is scheduled one slot early.
  - 888C6320 (6 off): three zeroed out-locals passed to fn_8886FED0(o, id, &a, &b, &c). The addi/stw
    interleave is wrong in every C, C++, struct, LTCG and /Ox form tried.
  - 8887C000 (12 off): vector `clear()` inlines give the dead `addi r11,vec`. The last `e =` store
    should come after `addi r3,r31,0x5c` (mr r11,r3).
  - 888E9898: rel-table walk with ts4_hash_service_str_888C8370; reached 24 off, then I stopped.
- Skipped: 8866BAE0/886A37D0 (open clrrwi cases), 886C80C0 (VMX), 888C1368 (64-bit ld/std).
