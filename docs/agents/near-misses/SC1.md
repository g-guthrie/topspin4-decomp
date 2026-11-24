# SC1: store scheduling, adjacent swaps and block layout (2026-11-15)

Compiler cl.exe 16.00.10224.00 (sha256 `6c27181a…`) under wibo, split `work/matching-b76`, Python 3.13.18.
Plain route `tools/fn_check.py SRC name=0xADDR --flags /Oc`. LTCG route `tools/fn_check_ltcg.py ... --context
src/xbox360/pp1_pool_primer.c --flags /Oc`. Scratch is in `work/army/SC1/` (git-ignored):
- `chk.sh` / `chkl.sh`: plain and LTCG check. `chkl.sh` takes extra contexts in `$CTX`.
- `cmp.py SRC name=0xADDR [N] [skip] [--ltcg]`: diff count plus a compact two-column listing.
- `sdis.py FILE [flags]` + `flat.py`: compile a probe and print each function on one line.
- probes `p1.c`-`p16.c`; candidates `f1*.c`, `c170*.c`, `r48*.c`, `d78*.c`, `a3*.c`, `a920*.c`, `d828*.c`, ...
- generators `gen_f1c.py` (sub-object partitions of 0x88695E78), `gen170.py`, `gen48.py`.
About 110 experiments. Roughly 80 were on A.

## Matched (all exit 0)

| Address | Source | Spec | Fix |
|---|---|---|---|
| 0x88695E78 | `src/xbox360/sc1_a.c` | `work/specs/SC1/sc1_a.json` | header words +0x04..+0x14 as sub-objects {2,2,1} |
| 0x88668C80 | same | same | record words 3..7 as one sub-object + six dead locals (OP1 add order) |
| 0x886B4C10 | same | same | `free(&s->member)` (pointer to the member) instead of `free(s->member)` |
| 0x88646FD0 | same | same | the three tail words +0x08..+0x10 as one sub-object |
| 0x8864A920 | `src/xbox360/sc1_ltcg_a.c` | `work/specs/SC1/sc1_ltcg_a.ltcg.json` | vectors at +0x00/+0x0c and +0x28..+0x48, words +0x94..+0xa4 as one sub-object, literal `1.0f` |

- `sc1_a.c` (sha256 `697c396e…`): all four also MATCH on the LTCG route with the primer.
- `sc1_ltcg_a.c` (sha256 `ccc0b5ea…`) is LTCG only. On the plain route the literal `1.0f` is a local constant.
- Both files pass `cc -std=c11 -Wall -Wextra -Werror -fsyntax-only -Isrc/xbox360`.

## A. Store scheduling: rule

**A1. Alias base.** The scheduler only reorders two memory accesses that go through the same pointer value. That
means the same parameter or local, with different constant offsets. Any two accesses through different pointer values
keep their source order, in both directions. This covers a store through an inline helper's pointer parameter
(`init(&o->m)`), through a local `p = &o->m`, or through a second parameter. Types make no difference: int, char,
float and pointer stores all behave the same. `__restrict` on the helper parameter, `/Oa` and `/Ow` change nothing.
(These are probes p7, p8, p11, p13, p13r and p14.cpp.)

| probe (S *o; A at +0x18) | emitted order |
|---|---|
| `o->a.x=1; o->a.y=2; o->a.z=3; o->w[0]=x;` (all through `o`) | `stw x` FIRST (ready earliest) |
| `ainit(&o->a); o->w[0]=x;` (helper, 3 uses of its pointer) | `stw x` LAST |
| `A *p=&o->a; p->x=1; ...; o->w[0]=x;` | `stw x` LAST |
| `o->vt=VT; ainit(&o->a)` with ready `li` values in `ainit` | the `a` stores wait for the `addi VT` store |
| `avb(&o->b) {s->vb=VB;}` (pointer used once) then `o->w[0]=1` | `w[0]` passes it: one use is folded onto `o` |
| `o->c0=1; o->c1=2; o->w[1]=3; o->w[0]=x` (char and int through `o`) | `stw x` first: no type barrier |
| float stores through `o` before or after a helper's int stores | kept in source order |
| C++ inline member constructors | same as the C helpers |

A helper pointer used only once is folded into `o+K`, so it counts as `o` (DA1's rule for the dead `addi`). Used
twice or more, it is a separate base.

**A2. Priority among stores that are free to move.** The scheduler is a list scheduler. A store whose value is a
`lis/addi` address, or a loaded value, goes out as soon as its value is ready. Two examples: the vtable store
written last still comes second (p1, p3a/b, p4), and `stfs` follows its `lfs` closely. Stores of values that are
ready at the same time keep source order (p2a/p2b). The constants themselves (`li`/`lis`) are ordered by dependence
height. When the stores are chained by A1, the first store of the chain has the largest height. Its constant is then
materialised first, and a constant needed only at the start of a later group (a second vtable address) is
materialised late, right before its group. When the stores are free, every `lis` is hoisted to the top.

**Consequence (the rule to apply).** Look at a target constructor's store order and at when its constants appear:
- a constant materialised late (`lis` after other stores), the vtable store first, or a run of stores that stays in
  exact source order even where a value was ready earlier: the stores are split into member sub-objects, each
  initialised by its own `static __inline` helper on `&o->member`;
- stores that pass each other freely: the stores go through the same pointer.

Find the partition by trial when the shape is not obvious. A small sweep of word groupings is cheap
(`gen_f1c.py`):
- 0x88695E78: the target wants exactly {2,2,1} or {2,1,2}. The 13 other groupings of the five words give 7-17 diffs, and one 5-word sub-object gives 17.
- 0x8864C170: any grouping of the 12 words gives 2. Scalar stores give 12.

**A3. Destructors: a load through a member pointer stays behind the vtable store.** `free(&s->p)` with
`if (*pp) destroy(*pp)` keeps `stw vt; lwz p` in order, because the load goes through a different pointer. The
value form `free(s->p)` hoists the `lwz` above the vtable store (0x886B4C10: 45 diffs to MATCH). The same form
gives the dead `addi r11,r31,0x330` of the member sub-object.

**A4. Loads of constants under LTCG.** A load through `extern const float g_ts4_script_constants[]` or
`g_ts4_event_value` is held behind the stores through `s` (alias, A1). A literal `1.0f` under LTCG becomes pool
entry 0 (the same address, 0x880D0F70), and its load is scheduled freely (0x8864A920: 4 to MATCH). On the LTCG route a
global read written early in the source is sunk to its use. In 0x886D7878 that leaves the load after all the
stores. Only `*(void * volatile *)&g` keeps it early, and it then gives a different compare schedule (6 diffs).

### Results on the A list

| Address | Before | After | Best file | What is left |
|---|---|---|---|---|
| 0x88695E78 | 9 | MATCH | sc1_a.c | |
| 0x88668C80 | 16 | MATCH | sc1_a.c | |
| 0x886B4C10 | 45 | MATCH | sc1_a.c | |
| 0x88646FD0 | 8 | MATCH | sc1_a.c | |
| 0x8864A920 | (template) | MATCH (LTCG) | sc1_ltcg_a.c | |
| 0x8864C170 | 12 | 2 | `work/army/SC1/c170a.c` | `addi r3,r11,4` (call argument) one store early; 64 groupings, pads 0-8, LTCG with the callee context, a nested `mid` sub-object and a `vt_init` helper all stay at 2 |
| 0x886D48F8 | 9 | 4 | `r48a.c` | `addi r3,r3,0x30` (argument) one slot late; `mr r3,r31` (return) one slot late. 132 groupings of the tail, an inline call wrapper, a 5-word range struct: all 4 |
| 0x886D7878 | 59 | 6 (LTCG) | `d78c.c` with `CTX="flags(/Ob1):src/xbox360/sm4_ctor_a.c"` | the global load: see A4. Non-volatile forms stay at 18 |
| 0x886A3AC8 | 97 | 75 (LTCG) | `a3b.c` | float stores +0x130/+0x134/+0x288/+0x28c are interleaved in the target, which under A1 means they share a base with the Obj44 stores. Every form tried here keeps them ordered (floats placed before or after `o[0]`, C++). Open |
| 0x886738D0 | 15 (LTCG) | 15 | `work/army/PL1/e12.c` | the target shares the Rng stack slot with the `fcfid` temp at 0x50. A scoped `int r`, `rand_range`: no change |

## B. Adjacent swaps

- **The same mechanism covers part of B.** In 0x8864A920 the swaps `stw 0 / addi r10` and `stw 4 / li r8` went away
  once +0x00..+0x14 were two `{b,e,c}` sub-objects (4 diffs to MATCH).
- **No rule found** for an argument or return-value copy placed one slot off (0x8864C170, 0x886D48F8 above).
- **0x88656C88** (`li i,0` vs `addi h`). With `h` declared in a block OUTSIDE the loop, the `addi` comes before the
  `li` (the target order), but the add association flips to `(rel+i)+h`, still 2 off. Dead-local pads 0-9 at the top
  and 0-9 before `h` gave no fix, nor did a `base = h + h->rel` local in the loop.
- **0x886C5DB0**. The vector-clear helper, and the direct `r->v.last = copy(...)` form (19 off), both keep
  `stw last` before `li 0`. Open.

## C. Block layout

- **Rule: a failure block shared by two exits and placed after the first test, reached from the second test by a
  BACKWARD branch, is an inline helper returned from at both sites.**
  - `static __inline int fail(S *s) { ...stores...; return 0; }` with `if (a != 2) return fail(s); if (b != n) return fail(s);`.
  - The two inlined copies are tail-merged at the first site.
  - A `goto fail` into a block, an if-block with a label, `for(;;)`/break, and the reversed second test all put the
    block at the end (35 diffs).
  - 0x8864D828: 35 to 14 (`work/army/SC1/d828d.c`).
  - What is left there: `if (bc == 0) w4 = 3; else w4 = 4;` is a real two-arm branch with the store after the join in
    the target. Every form tried gives `li; beq; li`, arithmetic (`cntlzw`) or a 21-diff tail-merge.
- The same helper form did NOT work for 0x886D16F8 (`work/army/SC1/16f8a.c`). There the merged call block went to
  the end (128 diffs, from 118). So the merge position is not always the first site.
