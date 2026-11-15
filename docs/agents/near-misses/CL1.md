# CL1: the `clrrwi rD,rS,0` register copy (2026-11-15)

Compiler: cl.exe 16.00.10224.00 (sha256 `6c27181a…`), wibo `work/matching-tools/work_wibo`, split
`work/matching-b54`. Scratch files are in `work/army/CL1/` (git-ignored):
- `census.py LO HI [ctx]`: lists every `rlwinm rD,rS,0,0,31` in the original, by function, and marks
  the function matched when a source names `Swing_DLL.xex 0xADDR`. `ctx` prints 4 instructions of context.
- `e1.c` … `e8.c`, `e7.cpp`: the probes below. `work/army/OP1/op1dis.py FILE [flags]` disassembles them.

## Rule

`clrrwi rD,rS,0` (`rlwinm rD,rS,0,0,31`) is how MSVC writes a **load that it removed late**. The load is
replaced by a copy of the register that already holds the value, and the copy is a 32-bit zero-extension,
because `lwz` zero-extends. The early, expression-level CSE does not emit this. It reuses the register and
emits nothing, or `mr` when the register is needed elsewhere. The late pass runs when the early CSE did not
see the two accesses as the same location:

1. **The base pointer comes from a different expression.** For example, an inline accessor is called again
   (`get(p)->n--; return get(p)->n < 0;`), or an inline helper re-reads a pointer field from its own
   parameter.
2. **The store happens on two paths and the read follows the merge** (`if (c) p->n++; else p->n = 0;
   use(p->n);`).
3. **Another memory access lies between the store and the reload** (`s->c = x; s->d = a->y; f(s->c + 0x20);`).
4. **A rotated loop condition** re-reads a field the body just stored (`while (it->p != end) { …; it->p++; }`).
   That is why the Expat and zlib sources already matched it without anyone noticing.

Inside an inline body, only the **first** load off the parameter is forwarded (as clrrwi). Loads chained off
it are not CSE'd again: the original reloads them, and so do we. So which level gets the clrrwi tells you
which pointer the inline helper took as its parameter.

Writing the same expression twice in one function body does **not** give clrrwi: the early CSE merges it.
Neither does a local pointer used twice, nor a single inline call.

### Minimal reproduction (plain route, no flags; LTCG gives the same)

```c
struct S { int a, b, n; };
static __inline struct S *get(struct S *p) { return p; }
int r2(struct S *p) { get(p)->n--; return get(p)->n < 0; }
/* lwz r11,8(r3); subi r11,r11,1; clrrwi r10,r11,0; stw r11,8(r3); srwi r3,r10,31; blr */
int g2(struct S *p) { p->n--; return p->n < 0; }
/* lwz r11,8(r3); subi r11,r11,1; stw r11,8(r3); srwi r3,r11,31; blr   (no copy) */
```

`r2` is byte-identical to 0x8865AB58. C++ gives the same result through an inline `operator->` or an accessor
that returns `int&`.

### Probe results (each line: one compile)

| Form | clrrwi? |
|---|---|
| `p->n--; return p->n < 0;` / `--p->n < 0` / local copy / `p->n -= 1` / goto / `do{}while(0)` / `if (k=1)` | no |
| `get(p)->n--; return get(p)->n < 0;` (inline returns p) | **yes** |
| `struct S *q = get(p); q->n--; return q->n < 0;` (one call) | no |
| C++ `H<S> h` by value with inline `operator->`, used twice | **yes** |
| `struct H h` by value, `h.p->n--; h.p->n < 0` (no inline) | no |
| `static inline void dec(struct C *c){ if (c) c->n--; }` on `&p->c` | **yes** (after tail duplication) |
| `if (f) p->c++; else p->c = 0; t->f1 = p->c > 300;` | **yes** |
| `p->c = f ? p->c + 1 : 0; …` (one store) | no |
| `while (p->p != e) { *p->p = 0; p->p++; }` | **yes** |
| load after load: `if (get(o)->a == get(o)->b) return get(o)->b - 0x30;` | no |
| same, but through C++ `empty()` + `back()` (which calls `end()`) with a result local | **yes** |
| float field copies (`cp(&a->x, &b->y)` inlined) | **`fmr`** instead (the float analogue) |

### Ruled out

None of the following matter: 64-bit types (`__int64` fields, `& 0xffffffff` on 32-bit values, u64 casts),
`long`, signed versus unsigned, struct-by-value parameters on their own, `__ptr64`, enums, and the flags
(`/Oc`, `/fp:precise`, LTCG). The old explanation in `codegen-idioms.md` ("64-bit integer to pointer") is a
special case at most. FAM4's `& 0xffffffff` sources match because the translator duplicated the loads,
which is case 1.

## Census (`census.py`, raw words of `orig/54540859/Swing_DLL.dll`, symbols.txt sizes, before this work)

| Range | Matched funcs / sites | Unmatched funcs / sites |
|---|---:|---:|
| whole image 0x88000000-0x89000000 | 131 / 178 | 1,508 / 2,399 |
| gameplay 0x88640000-0x886E8000 | 6 / 9 | 156 / 239 |
| game core 0x88150000-0x88288000 | 2 / 2 | 181 / 237 |
| LTCG game 0x885F4E48-0x889D3410 | 79 / 122 | 781 / 1,216 |
| plain libraries 0x882A0000-0x885F4E48 | 50 / 54 | 531 / 930 |

The matched sites were already reproduced by:
- Expat `ascii_toUtf8` and `hashTableIterNext` (loop condition, case 4);
- zlib deflate and trees;
- `fd_build_name.c`;
- FAM4/FAM6 translator output (duplicated loads, case 1);
- CRT `strdup`/`cftof`.

All of these are ordinary C, so the idiom was never blocked by the compiler. Only the source shape was
missing. Some "matched" entries in the gameplay range are only failed candidates that name the address
(w2a_a.c, w2a_d.c, rt1_eq_*).

## Results

`src/xbox360/cl1_clrrwi_reload.c`, spec `work/specs/CL1/cl1_clrrwi_reload.json`. `fn_check.py` exit 0, and
all 9 also MATCH with `fn_check_ltcg.py --flags /Oc`. The file passes `cc -std=c11 -Wall -Wextra -Werror
-fsyntax-only`.

| Address | Name | Form |
|---|---|---|
| 0x8865AB58 | `ts4_counter_dec_is_negative_8865AB58` | `--*cl1_counter_value(c); return *cl1_counter_value(c) < 0;` (case 1) |
| 0x8865B278 | `ts4_frame_counter_update_8865B278` | `if (f->active) frames++; else frames = 0; f->over = frames > 300;` (case 2) |
| 0x8865A3E8 | `ts4_last_record_8865A3E8` | result local; `empty()` then `back()` → `end() - 1` inline helpers (case 1) |
| 0x8865A410 | `ts4_first_record_8865A410` | same with `begin()` (no clrrwi; reload of begin) |
| 0x886615D0 | `ts4_registry_release_886615D0` | `--*cl1_entry_refs(e); if (*cl1_entry_refs(e) == 0) …` (case 1) |
| 0x8865E7C0 | `ts4_registry_release_8865E7C0` | identical body |
| 0x8865EE40 | `ts4_token_publish_8865EE40` | compare `s->a->b->c->pending` directly, decrement through an inline helper taking `s` |
| 0x8865BF80 | `ts4_max_track_update_8865BF80` | `cur` local; store through an inline helper taking `s`; `s->track->grew` direct |
| 0x8865F0D0 | `ts4_current_item_8865F0D0` | inline `size()` then `at()` on the same vector |

Integration notes:
- `src/xbox360/w2a_a.c` (0x8865A3E8) and `w2a_d.c` (0x886615D0) contain earlier failed candidates for the
  same addresses under other names.
- No caller references these functions by placeholder name in `src/` (grep for `fn_8865AB58` etc. is
  empty).

## Near misses where the clrrwi now reproduces but other differences remain

- **0x8865E638** (`work/army/CL1/e638b.c`, `y5`): the clrrwi of the stored `s->c` comes out right (case 3).
  13 instructions differ, all register numbering and scheduling: the target keeps the `+0x9d0` sum in r3 and
  stores it through r31. Padding 0-9 dead locals, inline `find()`/`resolve()` helpers, a C++ method and an
  id constructor were tried; all gave 13 or 15 differences.
- **0x8866F740** (`src/xbox360/cl1_prehit_freeze.c`, no spec). This is a rewrite of rt1_eq_prehit_freeze.c.
  Both struct copies now give the target's interleaved word copy plus the clrrwi:
  `cl1_move(t)->required = t->move.stick; self->pc->state->move.latched = t->move.required;`, where
  `cl1_move` is an inline accessor and `t` a fresh local. Writing through the accessor while reading through
  the local is what gives the interleaved order. A plain struct copy loads both words first and does not
  forward. The rewrite is 96 instructions off, down from 138. What remains:
  - self/pc are in r31/r30 where the target has r30/r31;
  - our compile CSEs `pc->match` between the inlined return-of-serve test and the release test, where the
    target reloads it;
  - the clrrwi is scheduled one slot earlier.

  The brief's statement that clrrwi was the only remaining difference does not hold for the RT1
  candidate (138 differences).
- **0x886CD3C8** (`work/army/CL1/cd3c8_v.cpp`, LTCG route, context `flags(/Ob1):src/xbox360/gp7_anim_busy.cpp`,
  `/Oc /fp:precise`): `desc = cl1_desc(stack->layers[top])`, with an inline helper returning
  `l->inner->desc`, gives the target's `clrrwi r9,r9,0` on `inner` followed by a reload of `desc`. The
  difference count drops from 37 to 31. What remains is the `fmadds` contraction and the mfcr/fsel select,
  both separate open idioms. Without `/fp:precise` it is also 31.

## Applying it

Look at what the clrrwi copies, and from where:
- It copies a value just stored, and the store is in another branch: use the two-branch form (case 2).
- It copies a value stored in the same statement sequence: reach the field again through an inline
  accessor (case 1), or let another memory access sit between the store and the reload (case 3).
- It copies a pointer loaded earlier and is followed by reloads of fields under it: the original called an
  inline helper whose parameter is the object *holding* that pointer. Give the helper that parameter and do
  the chained accesses inside it.
- It copies the result of a loop increment: use a `while` loop whose condition re-reads the field (case 4).

Not attempted from the census: 0x8865EF18 and 0x8865EF98 (loops over 0xE0-byte records), the GA5/GA6 lists
(0x886C4F20, 0x886C7CD8, 0x886D6C60, 0x886DC7A8, …), and GA2's pointer-clrrwi set (0x886696A8, 0x8866FC18,
0x88669B98).
