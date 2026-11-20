# Codegen idioms (Swing_DLL.xex, MSVC 16.00.10224.00 PPC)

Notes from the LEV1 investigation. Every claim was checked with
`TS4_MATCHING_DIR=work/matching-b22 python3 tools/fn_check.py <src> name=0xADDR`
(base flags /O2 /Oi) unless stated otherwise.

## SOLVED: 64-bit home-slot spill (`std r5,0x88(r1); lwz r11; rldicr r5,r11,32,63`)

Construct: a **12-byte struct passed by value**.

```c
struct TS4TripleArg { unsigned first, second, third; };
void *ctor(void *self, struct TS4TripleArg value) { base(self, value); return self; }
```

The PPC ABI packs the 12 bytes into r4 plus the high half of r5, or into later
registers. When MSVC re-passes the struct, it spills the registers with `std` to the
home slots, reloads the third word with `lwz`, and rebuilds r5 with `rldicr`. FAM2's
"handle {obj, id, extra}" is this same struct.

Examples, all MATCH: 0x8864A1A8, 0x88638E80, 0x8863EF00 (a struct at r7..r8 is spilled
with `std r8,0x98`). See `src/xbox360/lev1_triple_arg_ctors.c` (15 functions).

Related tip: when a vtable call takes a call result as an argument, compute the
argument into a local before the call. If you inline the call in the argument list,
MSVC hoists the vtbl load and the registers come out wrong.

## MECHANISM FOUND, not matchable per object: fsel ±1 table

Target sequence:
```
fcmpu cr6,f1,f0 ; mfcr r11 ; rlwinm 27,29,29 ; rlwinm 30,29,29 ; [xori 4] ; or ;
lfsx fX,table,idx ; fsel
```

This is MSVC's own lowering of a float `?:` under **`/fp:precise`**. The default fp
model never emits `mfcr`. All of these reproduce it:

```c
r = (d < 0.0f) ? a : b;        r = (x < 0) ? -x : x;        r = x * (x < 0 ? -1.0f : 1.0f);
```

The compiler creates the table `__real@3f800000bf800000` = {+1.0, -1.0}. Under LTCG it is
merged into the constant pool at `g_ts4_script_constants`+0x68 (0x880D0F70+0x68). This was
verified with a local /GL + /LTCG link harness. Per-object compiles still differ from the
target in two ways:
- The relocation is `__real@...`, not the pool.
- The target uses one fewer `addi`, because the table is addressed as base+offset.

So fn_check cannot report MATCH even when the source is correct. About 455 instances in
about 219 functions (0x881..0x889, e.g. 0x88275018, 0x888AEE68).

Unresolved detail: the target index is `(LT|UN)` with no `xori`, on `fcmpu(d,0)`. Our
forms give `(!LT)|UN` with an `xori`. `(d>=0)?a:b` gives a plain fsel, and `(0.0f<=d)?a:b`
gives `fcmpu(0,d)`, rot 28, no xori. Neither is the target. The orientation should only
need an operand or sense flip. Matching these functions needs either LTCG-aware matching
or a way to accept pool relocations.

Ruled out by the coordinator and LEV1: `__fsel`, `/fp:fast`, `/Ox`, explicit table
indexing, `!(a>=b)`.

## PARTIAL: `clrrwi rX,rX,0`

MSVC emits `clrrwi rX,rX,0` (a no-op) when it **converts a 64-bit integer to a pointer**,
as in `(T *)u64var`. Not reproduced: the target shape `lwz; cmplwi; clrrwi`, with no
64-bit value in sight (0x8876DE48, 0x88720B08). For 0x88720B08 our output differs only by
that missing clrrwi.

Tried with no success: a 32-bit bitfield, `__ptr32`/`__ptr64`, an enum, `__w64`, LTCG.

## NEGATIVE: divw/divwu with no `tw` trap (0x886091E0, 0x88609228, 0x888118D8)

The divide-by-zero trap (`twllei`/`twi`) stays in every form we tried:
- `__assume(d != 0)`
- an explicit zero-check branch
- every `/Q` flag
- LTCG

The one case with no trap: dividing by a constant that is held in a register.

## NEGATIVE: float→int conversion before a global load (0x88786290, 0x88782A00, ...)

The target converts with `fctidz` before it loads the global and checks it for null.
MSVC always moves the conversion below the null check. Tried with no change:
- `/fp:precise`, `/fp:strict`, `/fp:except`
- converting into a separate local first

0x88786290 still differs by 7 instructions starting at +0x6c.

## DONE elsewhere: `li r4,1; cmplwi; beqlr; b T` (0x88469710)

Already matched in `src/xbox360/fam1_hk_finish_loaded_object.c`.

## Local LTCG harness (tooling note; commit no binaries)

To reproduce the pooled-constant layout:
- Compile with `/GL`.
- Link `/LTCG` with `work/wibo-src/build/release64/wibo`.
- Compile `_fltused` and the `__savegprlr_*`/`__restgprlr_*` stubs in a separate object
  without `/GL`, because those definitions fail with C2268 under /GL.
- The linker needs OLEAUT32 ordinals 2, 6 and 200. A small stub DLL built with mingw in a
  private copy of the toolchain directory is enough.
