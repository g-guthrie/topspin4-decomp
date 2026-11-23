# Register numbering, operand order and scheduling: rules and decision procedure (RG1, 2026-11-23)

Compiler: Xbox 360 cl 16.00.10224.00 (PowerPC) through the repo wrapper, `TS4_MATCHING_DIR=work/matching-b215`,
flags `/Oc`. Probes are small C files compiled with `python3 work/regalloc/ra_dis.py FILE /Oc` (a copy of
`work/army/OP1/op1dis.py`: `fn_check.compile_candidate` + `fn_asm.disassemble`; about 0.1 s per file). Probe files
`work/regalloc/p1.c`-`p12.c` (git-ignored); each rule below names the probe functions it rests on. Earlier,
compatible results: docs/agents/near-misses/RA1.md (saved registers, volatile rotation), OP1.md (period-8 local
numbering), SC1.md/SC2.md (store scheduling), NM1/NM2.md.

Tooling: `python3 tools/regalloc_mutate.py classify SRC name=0xADDR` sorts each differing instruction into
REG / COMMUTE / SWAP / FORM / OTHER and prints the rule to apply; `... search ...` runs a deterministic beam
search over the moves that fit those classes; `python3 tools/perm_auto.py ... --targeted` weights its random
mutators the same way (and drops arithmetic `commute`, which is inert, rule C1).

## 1. Operand order

**C1. Commutative arithmetic is canonicalised; the source order never matters (high confidence).**
`add`, `fadds`, `fmuls`, `xor`, `mullw` ... take the same operand order for `a + b` and `b + a`, with or without
single-use locals, in any statement or declaration order.
Evidence: p3 a1-a5, b1-b6, c1/c2; p6 w1-w9, f1-f6; p9 e1-e8 and p11 e1-e8 (`*b + (g - *b) * K` in 16 spellings,
including inline helpers returning the product: always `fadds fD, product, load`).
The canonical order, as measured:
- a COMPUTED operand (product, difference, ...) comes before a plain LOAD (p9, p10 e8: `*b + g*k` gives
  `fadds f12, f0(product), f13(*b)`);
- a LOAD comes before a VARIABLE (a parameter, a multi-use or cross-block local, a CSE temp, a phi):
  p10 e6/e7, p4 e7 (`x = r->p` used twice: `r->d + x` gives `add (d, x)`), p12 k2 (phi `x + s->c` gives
  `add (c, x)` in both tail copies);
- two loads off the same base: HIGHER OFFSET first (p3 b1-b4, p6 w1-w3: `p[0] + p[1]` gives `add (p[1], p[0])`);
  same offset, different bases: base parameter order (p6 w4-w7); different offset and base: higher offset
  first (p6 w8, w9, wa);
- two variables: parameter order (p3 c1/c2, p10 f6); two locals: OP1's symbol numbering (period 8; RA1 found
  assignment order for saved-register ties).
So to flip an `add`/`fadds`, change what KIND of operand each side is, not where it is written: make the side
that must come second a variable (a local used twice, or read in an earlier block), or make the side that must
come first a fresh expression (re-read the field at the use instead of reusing a cross-block value).
Example: 0x88655310 `add r3,pos,data`: in our draft `r->pos` is a cross-block CSE temp (a variable, so second);
a `d = r->data` local makes data the variable and flips the add (confirmed), but moves the data load (7 off).

**C2. Compares keep SOURCE operand order, and the first operand is loaded first (high confidence).**
`a == b` gives `cmplw a,b`, `b == a` gives `cmplw b,a`; `a < b` and `b > a` differ (p7 c1-cc, d1/d2; p8 h1-h9).
The load order follows the compare order: the left operand is loaded first and gets the first volatile
register. Every single-block spelling tried couples them (p8: locals, `!(a != b)`, inline `eq(a,b)` helpers,
`eqp(&a,&b)`, `(a ^ b) == 0`). They decouple only when one operand is DEFINED EARLIER: a loop-invariant hoisted
load (0x88165170's head loop: `lwz r11,*val` before the loop, `cmplw first,val` inside), or the struct copy of
matching-tips "Solved (Q5, 0x8887B380)". Open: 0x88165170's switch tail needs the decoupled form per case.

**C3. Shift form (high confidence).** A 32-bit shift gives `srwi`. A 64-bit shift whose count is an UNSIGNED
32-bit expression zero-extends the count and folds the extension into the count computation:
`x64 >> (i >> 2)` gives `rldicl rC,ri,62,34`; with an `int` count, `x64 >> (int)(i >> 2)` gives `srwi rC,ri,2`
(p7 s1-s5, 0x888C00A0). The cast moves the IR enough to change the store schedule there (10 off, open).

## 2. Register numbering

**R1. Volatile GPRs rotate r11, r10, ..., r3 and FPRs f0, f13, f12, ..., in allocation order (high confidence).**
A freed register is not reused until the rotation comes round (p1 chain2: six chained loads take r11..r6 although
each value dies at once; p12 k3: the rotation continues across a call; p10 e6, p12 k4 for FPRs). The result value
is coalesced into r3/f1. Dead locals and dead pads do not move the rotation (p2 pad0-pad9).

**R2. Single-use locals are forward-substituted: their declaration order, assignment order and statement order are
inert (high confidence).** p2, p5 u0-u11/v0-v11, p6 w1-w3, and six re-orderings of 0x886C5998 (t first, key first,
named range pointer, named key) all give identical code. What the allocator sees is the expression TREE after
substitution and canonicalisation (C1), evaluated in tree order (RA1: `x*y` evaluates y first; p12 k4).
Levers that DO change the tree: a local used twice, a value read in an earlier block (a real symbol, cross-block),
an inline helper whose pointer parameter is used twice (SC1), a by-value struct copy, a different type
(u16 vs int index, signed vs unsigned), or a statement that cannot be substituted (call, store, volatile-free
aliasing barrier).

**R3. The rotation is NOT simple program order (open).** The allocator follows IR order before scheduling, and
some targets reuse a just-freed register (0x886C5998: `lwzx r11` right after `slwi r10,r11`, where ours gives
`lwzx r7`). p2 pre1-pre9 show the same: after `lwz r9,0x20(r10); lwz r8,0x20(r9)` the next load takes r10, not r7.
So the choice also depends on interference (values live across the point), not only on a counter. No source
form found changes 0x886C5998's numbering (12 variants + 119/357-candidate targeted search).

**R4. Saved registers (RA1, unchanged).** r31 downward: parameters in order, then locals by first assignment;
raised by add/addi/mulli use, global stores, conditional-arm and loop uses. See RA1.md.

## 3. Scheduling of two independent instructions

**S1.** Memory accesses through the SAME pointer value may be reordered; through different pointer values they keep
source order (SC1). Two stores whose values are ready together can come out reversed (PL2): swap the statements.
**S2.** A change in a different part of the tree (C3's cast, an extra local) changes the critical path and moves
unrelated float stores (0x888C00A0: 1 off -> 10 off). Fix FORM/COMMUTE first, then re-permute statements.

## 4. Decision procedure ("if the diff is X, try Y")

Run `python3 tools/regalloc_mutate.py classify SRC name=0xADDR [--ltcg]` first.

| Diff class | Try, in order |
|---|---|
| COMMUTE on `cmpw/cmplw/fcmpu` (operands swapped, loads in matching order) | flip the compare (`a<b` -> `b>a`, `a==b` -> `b==a`) |
| COMMUTE on `cmp*` with loads in the OTHER order | define one operand earlier: hoist it out of a loop, read it in an earlier block, struct copy (C2) |
| COMMUTE on `add/fadds/fmuls/xor/mullw` | do NOT swap source operands (C1). Change operand kinds: make the second operand a variable (local used twice / read earlier), or the first a fresh expression; then OP1 pads 0-9 when both are locals |
| FORM `srwi` vs `rldicl ...,34` | `(int)` cast on a 64-bit shift's count, or an unsigned count to get rldicl (C3) |
| FORM `clrrwi rX,rX,0` | CL1 (matching-tips) |
| REG, whole run shifted by k registers | count volatile allocations before the run (R1): one more or one fewer temp upstream (a CSE'd vs re-read field, an extra address local) |
| REG, two values exchanged | change which is a variable vs an expression (C1/R2), or which is defined first in a NON-substitutable statement; single-use local reordering is inert (R2) |
| REG on saved registers | RA1 weights (add/addi use, global store, guarded first assignment) |
| SWAP of two stores/loads through one pointer | swap the source statements; split through a block-local member pointer (SC2) |
| SWAP across different pointers | change which pointer value the access goes through (SC1) |

## 5. Corpus results (RG1)

No corpus function closed (0/13 attempted; 885FF748 notes only). Score = differing instructions (plain / LTCG).

| Function | Base | Now | What was tried / blocker |
|---|---|---|---|
| 0x886C5998 | 6/6 | 6 | 12 manual variants + 319-candidate targeted search; R3 (register reuse) |
| 0x886C8010 | 9/9 | 9 | targeted search, all REG; no candidate below baseline |
| 0x881518D0 | 16/16 | 16 | search only |
| 0x888D3850 | 32/26 | 26 | search only |
| 0x88655310 | 1/1 | 1 | C1 flip works (`d = r->data` local) but moves the data load: 7 off |
| 0x8865FFF8 | 1/1 | 1 | target `fadds (load, product)` is against C1; 16+5 spellings (p9, p11, p13) all canonicalise |
| 0x886CF018 | 14/14 | 14 | search only |
| 0x888C00A0 | 1/1 | 1 | C3 `(int)` cast fixes srwi but S2 moves stores: best 10 over 120 store/dirty permutations |
| 0x886C46C8 | 9/9 | 9 | search (REG 2, OTHER 7) |
| 0x888C93E8 | 2/2 | 2 | search only |
| 0x886CBC30 | 17/2 | 2 | LTCG; script address vs event value allocation order unresolved |
| 0x886CC058 | 41/6 | 6 | LTCG search only |
| 0x88165170 | 3/3 | 3 | C2: every compare spelling couples load and compare order (9 or 12 off) |

Logs: work/regalloc/logs/*.log, work/regalloc/c0a0_perm.log (git-ignored scratch).
