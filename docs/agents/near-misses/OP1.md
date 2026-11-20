# OP1: operand order of indexed `add` / `lwzx` / `lfsx` (2026-11-15)

Compiler: cl.exe 16.00.10224.00 (sha256 `6c27181a…`), wibo `work/matching-tools/work_wibo`, split
`work/matching-b52`. The scratch scripts are in `work/army/OP1/` (git-ignored):
- `op1dis.py`: compile a file and disassemble every function;
- `padtry.py`: insert N dead `int op1_padK = 0` locals and run fn_check for N = 0..max;
- `scan.py`: census of `lwz rB,0(rA)` followed by an X-form instruction on {rA, rB}.

## Rule

The order of the two operands of a commutative op (`add`, and the base/index of `lwzx`/`lfsx`/`stbx`…)
does **not** follow the source. `a+b` and `b+a`, casts, temporaries, `&p[i]` versus `p+i`, C versus C++
and the flags all give the same order. The order follows the **function-local symbol numbering** of the
user locals the operands are computed from.

- Locals are numbered in the order they are **first assigned**, in statement order. Declaration order does
  not count: declaring `hdr` last but assigning it first changes nothing.
- A local counts only if it is referenced. `int d;` on its own, `static`, `typedef`, `enum` and `extern`
  do not count. `int d = 0;` counts, and so does `int d; (void)d;`.
- Parameters come first and cannot be shifted.
- Locals of an inlined `static __inline` helper do **not** count. Nor do copies of plain loads or
  parameters (`char *b = s->buf;`), because they are copy-propagated away.
- Dead code with no locals (`if (0) {…}`) does not count.
- The effect depends on the absolute number, not on the difference between the two operands. It is not
  monotonic. In the probe below the order flips only when the base local is number 7, 15, 23, 31/32,
  39/40, … (the parameter is number 0). So it is about period 8, with extra flips above about 30.
- Only expressions that involve a local holding a **computed address** are affected (`h = &t->hdr`,
  `e = h + idx*K + h->rel`). Two loads off a parameter (`r->buf + r->pos`), parameter plus load, or
  parameter plus parameter never flipped under any padding (0..48 tried).

Minimal reproduction (`work/army/OP1/gen6.py`, `ord.sh`):

```c
struct R { int rel; };
struct Blk { char pad[0x3c]; struct R r; };
struct Own { char pad[0x50]; struct Blk *blk; };
struct Ctx { int pad; struct Own *own; };
void q1(struct Ctx *c) {
  { struct R *h = &c->own->blk->r; *((char*)h + h->rel + 1) = 1; }   /* repeated 60 times, +1..+60 */
  ...
}
```

All 60 statements are identical apart from the constant, and the register allocation repeats every 7.
Even so, `add rD, h, rel` appears in place of `add rD, rel, h` at statements 6, 14, 22, 30, 31, 38, 39,
46, 47, 54 and 55 (0-based). Adding k referenced dead locals at the top shifts the whole pattern down by
exactly k, and the order of the constants does not matter.

A one-statement probe (`u1.c`), `float f(struct T *t) { struct H *h = &t->h; return *(float*)((char*)h + h->rel); }`,
gives `lfsx f1,r10,r11` (rel, h) with 0-5, 7-13 or 15 dead locals and `lfsx f1,r11,r10` with 6 or 14.

**How to use it.** Write the source so that the base is a real local holding an address. If the order is
wrong, change how many referenced locals are assigned before it:

- split a pointer chain into named locals (`o = self->owner; b = o->blk; h = &b->hdr;`);
- give each repeated access its own block-scoped locals;
- or run `padtry.py SRC FUNC name=0xADDR 9` to find the count that works, then look for a natural form
  with the same number of locals.

Because the effect has period 8, one of eight counts works when the problem is a single instruction.

## Census

From `scan.py` over the original image:

- In the LTCG ranges (0x88150000-0x889D3410), 572 sites have the order (base, loaded offset) and 2,420 have
  (loaded offset, base).
- Among functions already matched (a source names `Swing_DLL.xex 0xADDR`), the counts are **0** and 137.
  The only (base, offset) site in a matched function is the w2a_h near miss.
- In the gameplay window 0x88640000-0x886E8000, 151 unmatched sites have the (base, offset) order.
- The plain-library range has 1 such site and 41 of the other order.

The (base, offset) order is therefore common in the original but had never been reproduced. These counts
are only a guide: the scan is a heuristic over raw words with simple register tracking.

## Results

Each was checked with `fn_check.py` (exit 0), and also MATCHES via `fn_check_ltcg.py`.

| Address | Spec | Source form |
|---|---|---|
| 0x8866A608, 0x8866A8C8, 0x8866ABD0, 0x8866AF38 | `work/specs/OP1/op1_rel_side_flags.json` | four block-scoped locals per store (`o`, `b`, `h`, `s`), `s[side].flag[which] = 1`: natural, no padding |
| 0x8865B658 | `work/specs/OP1/op1_value_at_least.json` | `tab` and `l` split out, plus `idx`, `off`, `pv`, so that `e` is local number 7: natural |
| 0x88668D70 | `work/specs/OP1/op1_clear_records.json` | **padding form**: seven dead referenced locals before `hdr` (`OP1_SYMBOL_PAD`). No natural form found |

The base pointer was the only thing that mattered in 0x88668D70. Padding after `hdr`, or inside the loop
before `r`, changes nothing. Padding before `hdr` matches only at 7. The flipped instruction there is
`add r11, r9, r11` (i*0x40, hdr->rel), which does not use `hdr` directly. So the key comes from the leaf
symbols underneath the operands, not only from the operand registers themselves.

## Not fixed and what was ruled out there

- **0x88655310** (`add r3, r11, r10`, pos and buf, both loads off the parameter `r`): padding 0-12, with and
  without `pos`/`buf` locals, `r0` copied to a local `r` (propagated away), `dst = r->buf + r->pos` hoisted
  above the branch (7 instructions worse), `&r->buf[r->pos]`.
- **0x886C5160** (`lwzx r8, r11, r10`, strength-reduced induction temp and reloaded `s->begin`): padding
  0-48 at the top, padding 0-9 inside the loop, `s->begin[i]`, `char **b = s->begin` inside the loop, an
  explicit byte-offset counter (9 instructions worse).

  In both cases neither operand comes from a user local holding a computed address. Nothing at the source
  level moved them.
- **0x886616D0**: the candidate in `work/army/W2B/nearmiss/w2b_i.c` is 17 instructions off (no unrolled
  ×4 loop, different `lis` placement). It is not a pure operand-order case, so it was not attempted.
- **No effect on the order** (on top of what W2/W2B already listed): environment size (0-20,000 bytes),
  long identifier or struct names, another function before it in the TU, `if (0)` blocks, unreferenced
  locals, `static`/`typedef`/`enum`/`extern` declarations, and declaration order versus assignment order.

## Notes for integration

- `src/xbox360/w2a_h.c` and `w2a_l.c` define the same `ts4_value_at_least_8865B658` and
  `ts4_clear_records_88668D70` names as earlier failed candidates. Make sure those files are not built
  alongside the op1 sources.
- Callers reference `fn_8865B658` (`d2g_ai_conditions.c`) and `fn_88668D70` (`d1_leaf_88660000.c`,
  `forward_thunks.c`) by placeholder name.
