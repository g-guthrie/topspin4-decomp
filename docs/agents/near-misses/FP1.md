# FP1: fmadds together with the mfcr/fsel select (2026-11-15)

Compiler: cl.exe 16.00.10224.00 (sha256 `6c27181a805dee13…`), c1.dll `efdba0fdb4ac2684…`, c2.dll
`349694b184976d44…`, wibo `work/matching-tools/work_wibo`, split `work/matching-b57`. LTCG checks use
`tools/fn_check_ltcg.py` (link.exe 10.00.10224). Scratch files are in `work/army/FP1/` (git-ignored):
- `census.py LO HI [list|matched|both|fma|sel]`: per-function census of fmadds-family, fsel and mfcr after fcmpu;
  "matched" means the function start is in `config/54540859/match.json`;
- `selscan.py LO HI`: the CR bits each mfcr select extracts (rlwinm shift), xori, fsel;
- `tdis.py 0xADDR`: disassembles an original function;
- `probe.sh`, `t1.c` … `t21.c`, `m1.c`, `m2.c`: the probes below. `work/army/OP1/op1dis.py FILE [flags]` disassembles them.

## Rule

There is no fp-mode conflict. The game's float code was built in the compiler's **default** float model, the one
that contracts `a*b+c` into `fmadds`. The ±1-table select comes from the **source**: the compare is made
against a **named `const float` whose value is 0.0f**, not against a literal.

- With a literal `0.0f`, `c >= 0.0f ? a : b` becomes a bare `fsel`. A compare against a variable becomes
  branches.
- With a translation-unit `const float` (static or global) equal to 0.0f, the compiler still knows the value,
  so it if-converts the select. It does not recognise the value as a literal zero, so the bare-`fsel` peephole
  does not fire. It emits: `lfs fZ, zero_const`, then `fcmpu cr6,x,fZ; mfcr; rlwinm 27,29,29 (LT);
  rlwinm 30,29,29 (UN); or; lfsx` from `{1.0f,-1.0f}`, then `fsel`.
- Once such a constant exists in the TU, **every literal `0.0f` in that TU is replaced by it**. In m2.c,
  `(v - lo >= 0.0f) ? v : lo` also becomes the table form, loading the named constant. That explains why the
  game's zero always comes from one address (BINKCONS 0x8814B440, named `g_ts4_event_value` in symbols.txt)
  and why the pool also holds a separate 0.0.
- In the default model the compiler orients every select as "x >= 0" (index = LT|UN, never GT, never `xori`).
  It may do so because NaN ordering does not matter there. `/fp:precise` keeps the source orientation, so it
  adds `xori` and GT variants, and it never contracts. The original matches the default model:
  - gameplay 0x88640000-0x886E8000: all 328 mfcr+fsel sites are LT|UN without xori;
  - LTCG game range 0x885F4E48-0x889D3410: all 479 are LT|UN without xori.

  The xori LT1 saw on 0x886A48B8 and CL1/RT1 saw on 0x886CD3C8 came from `/fp:precise`.
- `max(0, x)` written as an fsel-style helper `(a - b >= zero) ? a : b` gives the original's
  `fneg; fcmpu; … fsel(t, zero, x)`. The default model folds `0 - x` to `fneg`.

### Minimal reproduction (plain route, no flags; `python3 work/army/OP1/op1dis.py work/army/FP1/m2.c`)

```c
static const float kZero = 0.0f;
float madd_named(float a, float b, float c, float lo) { float v = a * b + c; return (v - lo >= kZero) ? v : lo; }
/* fmadds f13,f1,f2,f3; lis r11,kZero; lis r10,__real@3f800000bf800000; addi r9,r10,0; lfs f0,0(r11);
   fsubs f12,f13,f4; fcmpu cr6,f12,f0; mfcr r8; rlwinm r7,r8,27,29,29; rlwinm r6,r8,30,29,29; or r5,r7,r6;
   lfsx f11,r9,r5; fsel f1,f11,f13,f4; blr */
```

Without the `kZero` line (m1.c), the same function gives `fmadds; fsubs; fsel` with no compare. The fix lives
entirely in the source file and needs no flag or pipeline change.

### LTCG detail: the constant pool

On the LTCG route the table is pooled, and the original reaches it as `addi r11,r10,lo(g_ts4_script_constants);
addi r8,r11,0x68`, with `1.0f` at pool+0. That is a whole-program layout. In a scratch link our pool held only
our own constants: table at +0 and 1.0 at +8, so the code shape differed. `src/xbox360/fp1_pool_primer.c` is a
context-only file that uses, in order, the constants of the first 0x68 bytes of the original pool. With it in
the link, LTCG lays out `1.0f` at +0 and the table at +0x68, and the code matches. Pool constants are accepted
by value (POOL lines), as before.

Policy point for the owner: this is a stand-in for the pool layout, like LT1's per-file `flags(/Ob1):` stands in
for inlining decisions. It covers only offsets below 0x68. A function that also uses a later pool constant
needs a longer primer, for example 0x886C6EE8, which loads 30.0f from pool+0x42c. The original pool has
repeated values (0.0 eleven times in the first 0x430 bytes, 1.0f/-1.0f twice), so it is not a single
deduplicated set. A primer generated mechanically from the raw words would not reproduce it. Not attempted.

## Results

| Address | Source | Spec | Command (exit 0) |
|---|---|---|---|
| 0x886CD3C8 | `src/xbox360/fp1_anim_busy_frames.cpp` | `work/specs/FP1/fp1_anim_busy_frames.json` | `fn_check_ltcg.py src/xbox360/fp1_anim_busy_frames.cpp ts4_anim_busy_frames_886CD3C8=0x886CD3C8 --context "flags(/Ob1):src/xbox360/gp7_anim_busy.cpp" --context src/xbox360/fp1_pool_primer.c --include ts4_anim_stack_top_active_layer_886C4638 --flags /Oc` |
| 0x886D1408 | `src/xbox360/fp1_layer_time_warp.c` | `work/specs/FP1/fp1_layer_time_warp.json` | `fn_check_ltcg.py src/xbox360/fp1_layer_time_warp.c ts4_layer_time_warp_886D1408=0x886D1408 --context src/xbox360/fp1_pool_primer.c --flags /Oc` |

Notes:
- 0x886CD3C8 needs `--include ts4_anim_stack_top_active_layer_886C4638`. Without it, LTCG drops the unused
  float argument and the `lfs f1` before the call disappears.
- With `--flags /Oc /fp:precise`, the ternary version of this source (before the `fp1_max` helper) fails: 16 instructions differ and there is no fmadds.
- `src/xbox360/rt1_eq_anim_busy_frames.cpp` defines the same name `ts4_anim_busy_frames_886CD3C8`; do not build
  both.
- 0x886D1408 matches only with nested inline helpers, `fp1_min(fp1_max(x, base), limit)`. Writing the two
  selects as statements on `x` turns the first one into a branch.
- All three files pass `cc -std=c11` / `c++ -std=c++11 -Wall -Wextra -Werror -fsyntax-only` (with
  `-Isrc/xbox360` for the .cpp).

## Not matched

- **0x886C6EE8**: draft in `work/army/FP1/c6ee8.c`. The select reproduces (fneg + LT|UN table), but the
  function also loads 30.0f from pool+0x42c, which the primer does not cover (pool layout above). The draft
  also has source-shape differences: vector-empty compare order and where the clrrwi copy goes.
- **0x886C4970**: draft in `work/army/FP1/c4970_draft.c`. `d = (before >= zero) ? after : before; inside =
  d >= zero;` is jump-threaded into two compares and branches. A helper-wrapped select did not help (2 tries).
  The original keeps the table select followed by a separate `fcmpu`/`li 1`/`li 0`. Open.
- **0x886D6C60, 0x886D1910**: not attempted. Both contain fmadds and pool constants. 0x886D6C60 has no mfcr
  select. 0x886D1910 loads from pool+0 and an `lfsx` table.

## Ruled out (each line: compiled and disassembled)

- `/fp:precise`, `/fp:strict`, `/fp:fast`, default, `/fp:except[-]`, `/QFPU`, `/Qfast_transcendentals`: no single
  mode gives both patterns with a literal zero.
- `#pragma fp_contract(on)` under `/fp:precise`: no contraction. `fp_contract(off)` does work in the default
  model, so the pragma is parsed. `float_control(precise, off)` = default; `float_control(except, on)`,
  `fenv_access(on)`: no effect on contraction.
- `/d1fpfast` with `/fp:precise` behaves like the default model; `/d2fpfast` with `/fp:precise` behaves like
  precise. Both decisions are made in c1, from `-fpfast`.
- `cl /Bd`: the default passes `-fpfast` to c1 and c2. `/fp:precise` passes nothing. c2 has no other fp
  switch (wide-string option list: only `-QFPU`, `-Qsafe_fp_loads`, `-Qfast_transcendentals`,
  `-Qimprecise_fwaits`).
- No `__fmadds`/`__fmadd` intrinsic exists (C4163). `double` intermediates under precise give
  `fmul; fadd; frsp`. `__fsel` / `__fself` give a bare fsel in every mode.
- Mixed modes do work, but they do not reproduce the original:
  - a `__forceinline` helper defined under `float_control(precise, on)` and inlined into a default-model
    caller gives fmadds plus a table;
  - plain `__inline` is not inlined across fp modes;
  - a precise caller with an inlined default-model helper gives no contraction.

  This route keeps the precise orientation (xori/GT) and never gives LT|UN for `>= 0`. That gives no
  practical way to the original's form.
- Variable compares (a parameter, an `extern` global, or a const defined without /GL): branches in every
  mode and shape (leaf, non-leaf, store, multiply).
- A cross-TU `const float` defined in a /GL context: LTCG treats it as a literal and emits a bare fsel.
- Dead-local padding (OP1 rule, 0-9) does not change the fcmpu operand order.

## Census (work/army/FP1/census.py, raw words of orig/54540859/Swing_DLL.dll, before this work)

"both" = fmadds-family plus (fsel or mfcr within 12 words of fcmpu); "fma" = only the first; "sel" = only the
second.

| Range | both: matched / unmatched funcs (bytes) | fma only | sel only |
|---|---|---|---|
| whole image | 0 / 131 (179,456) | 38 / 642 | 2 / 177 |
| gameplay 0x88640000-0x886E8000 | 0 / 46 (50,184) | 6 / 74 | 0 / 78 (74,384) |
| LTCG game 0x885F4E48-0x889D3410 | 0 / 62 (72,840) | 15 / 149 | 0 / 110 |
| game core 0x88150000-0x882A0000 | 0 / 17 | 3 / 51 | 0 / 30 |
| plain libraries 0x882A0000-0x885F4E48 | 0 / 52 | 20 / 442 | 2 / 37 |

No matched function contained both patterns. The 38 matched fmadds functions all use default flags. The 2
matched "sel" functions (d9t_list_scale, 0x8847AAF8/0x88485AF0) are bare `__fself`, with no mfcr. No matched
function had the mfcr table.

## Applying it

- Put `static const float <name>_zero = 0.0f;` at file scope in any TU whose target has the
  `lfs fZ,-0x4bc0(rX)` (0x8814B440) zero plus mfcr/fsel. Compile without `/fp:precise`. Literal `0.0f` then
  behaves the same, so either spelling works.
- Write selects fsel-style through small inline helpers: `max(a,b) = (a - b >= zero) ? a : b`,
  `min(a,b) = (a - b >= zero) ? b : a`. Read the fsel operands to choose:
  - `fsel f, t, A, B` means "A when the compared value >= 0";
  - an `fneg` before the fcmpu means the helper was called as `max(0, x)`.
- On the LTCG route, add `--context src/xbox360/fp1_pool_primer.c` when the function reaches the table at
  pool+0x68 and uses no pool constant at a higher offset.
- `tools/matching.py` needs no change.
