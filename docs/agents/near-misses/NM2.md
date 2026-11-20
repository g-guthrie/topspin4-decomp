# NM2: near-miss clean-up, list work/army/NM_list2.txt (2026-11-15)

Compiler cl.exe 16.00.10224 via wibo, split `work/matching-b73`, `--flags /Oc`. Scratch in `work/army/NM2/`
(`chk.sh`/`chkl.sh` = plain/LTCG check printing diff count, `pad.py` = dead-local pad sweep at `@PAD1@`/`@USE1@`
markers, `grid/` = loop-form grid for 0x886D9AB8). About 115 compiles in all.

Note: `nm2_ball_a.c`, `nm2_ball_c.c` and `nm2_gp3_groups.c` and their specs come from an earlier agent that was also
called NM2. This run added only `nm2_check_sides.c` and `nm2_push_pair.c`.

## Matched

| Address | Spec | Source form |
|---|---|---|
| 0x8868FBC0 | `work/specs/NM2/nm2_check_sides.json` | `int idx = self->ctx->first; side_a = self->sides->side[idx]; side_b = self->sides->side[1 - idx];` |
| 0x886C5C80 | `work/specs/NM2/nm2_push_pair.json` | `int *__restrict count`; `i = *count; *count = i + 1; s->keys[i] = key; s->vals[i] = val;` |

Both give MATCH with exit 0 on `fn_check.py` and on `fn_check_ltcg.py` (primer as context). Host check passes.

## Rule (class 1): a named local for the base gives (index, base); the base read at the use gives (base, index)

When the base of `lwzx`/`stwx` is a pointer loaded from a struct and the index is a loaded value held in a local:
- `list = self->sides; ... list->side[idx]` gives `lwzx rD, idx*4, list` (as 0x8868FBC0's old draft did).
- `self->sides->side[idx]`, with the load written at the use, gives `lwzx rD, list, idx*4` (the target).
Whether `idx` itself is a local makes no difference (fb6 and fb2 both match). `ctx` as a local makes no difference.
Assigning `idx` before `list` does not help (fb3, fb5, fb7 all fail). This is NOT the OP1 period-8 effect: copies of
plain loads still change the order, although OP1 lists them as propagated away.

When aliasing forces the base load ahead of a store (0x886C5C80: `s->k` must be read before `*cnt = i + 1`), the
named local was the only way to keep that schedule and it gives the wrong order. `__restrict` on the aliasing pointer
lets the base be written at the use and still be scheduled first, which gives the target. Seven forms without
`__restrict` (local first/second, `(*cnt)++`, inline accessor, `int *pc` copy, unsigned i) all stay one instruction off.

Not covered by the rule (still open):
- **0x886D9AB8** (store-back loop `tmp = vals[i]; f(&tmp); vals[i] = tmp;`). The target uses (off, vals) for the
  `lwzx` and (vals, off) for the `stwx`. Every form tried gives the SAME order at both sites: an index loop
  (`for (; i != hi; i++)`) gives (off, vals) at both, so 1 diff on the `stwx`. The old explicit `off` local gives
  (vals, off) at both, so 1 diff on the `lwzx`. The two sites always flip together:
  - `hi` as u16 flips both;
  - a `u32 *v = self->vals` local at the load flips both;
  - a local, block local or inline `set_val` at the store flips neither.
  A 64-form grid (hi type u32/u16/int/short × i type × load direct/local × store direct/local × declaration order)
  never has both sites right. Dead-local pads 0-9 at the top, in the loop and in a block around the store change
  nothing, nor do `__restrict` on `r`, a struct-typed element, or inline get/set/address helpers. Best:
  `work/army/NM2/d3.c` (1 diff: `stwx r8,r9,r30` vs ours `stwx r8,r30,r9`).
- **0x886CE120** (loop over a pointer vector read through a global). The target has (off, base); every form gives
  (base, off). Tried:
  - for/while/do loops, i declared or assigned before or after `n`, signed or unsigned `n`/`i`;
  - a named element local, a named base local inside the loop;
  - inline `at()` helpers, the whole loop in an inline helper taking the manager as a parameter;
  - pads 0-9.
  Best `work/army/NM2/x9.c` (1 diff: `lwzx r11,r30,r11` vs ours `lwzx r11,r11,r30`).

## Class 2 (adjacent instruction order): no rule found, all refuted

- **0x8865FD40** (`stw r4,0x7c(r1)` param spill must come before `lwz r11,0x1c(r3)`). No change from:
  - an id struct by value, `unsigned *pk = &key` first, the header local computed first;
  - an inline find helper (frame grows), an inline `hdr()`/`blk()` accessor;
  - volatile, const or long parameter types;
  - pads 0-9, the LTCG route.
  GA1 noted the opposite residual (spill must come after the `mr`) in 0x8864BAE8.
- **0x886B83B0** (`li r6,1` must come before `lwz r5,0x100(r31)` in the first bind call). No change from:
  - the link parameter typed `void *` to match the callee prototype;
  - inline helpers taking the id, the flag, or (tab, id, link);
  - an inline `slot_tab()`;
  - C++ with `bool`/`true`;
  - block locals for tab, link or id.
  Always exactly these 2 instructions.
- **0x8868E320**: the old draft passed the callee's return value; the target passes `&v` (`addi r4,r1,0x50`), so
  `get(&v, o); fn(o, &v, o->p48->p30->w310);` brings it to 2 diffs (`work/army/NM2/m1.c`). Left: `mr r4,r3` must
  come before `mr r31,r3`. No change from:
  - the callee parameter as `void *` or `unsigned`, the whole function on `unsigned o`;
  - `__vector4 v[1]` or `float v[4]`;
  - inline wrappers (by pointer, or by value with a copy: 14 diffs);
  - a `self = o` copy, a `w` local, the LTCG route.
  In the whole image the sequence `mr r4,r3; mr r31,r3; addi r3,r1,..` occurs only in this function. The one matched
  function with `mr r4,r3; mr r31,r3` in its prologue (0x88867058, fk_024.c) loads r3 from a global after the copies.

## Class 4

- **0x8866D218**: a plain literal `0.0f` (plain route) gets the single `lfs` from the right address (it resolves to
  the g_ts4_event_value slot 0x8814B440). That brings the draft from 10 to 5 diffs (`work/army/NM2/t4.c`). Left: the
  `p74` load goes to r8 instead of reusing r11 (`lwz r11,0x74(r11)`; all four stores then use r8). No change from:
  - `float z` locals (they add `fmr` or move the `lis`), a `m = s->owner` local;
  - chained assignment, an inline zero4 helper;
  - `p` assigned before the v18 store (7 diffs);
  - pads 0-9.
  LTCG with the extern gives the same r8. This is the open r10/r11 class.

## Not attempted (budget)

0x88644738, 0x886BBC38, 0x886468B8, 0x886C6EE8, 0x88693FA8, 0x8865B570, 0x8865A6B8, 0x88661D28, 0x88695568,
0x886C4CB8, 0x8866C150, 0x886C7CD8, 0x8866A7C0.
