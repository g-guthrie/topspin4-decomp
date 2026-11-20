# D2G failed / near-miss functions (gameplay window). Best sources in work/army/d2g_scratch/.

- 0x8866A1C8 StdScoring_OnPointEnd (0x418): 10 instructions off, source work/army/d2g_scratch/8866A1C8_best.c.
  Fixed vs D1's version: size now exact (loop body reads cfg->games/tiebreak_sets into locals before the stores;
  winner via `&players(s)[w]`, loser via a second helper `(char*)s + (rel + i*24)` gives the dead `mr`).
  Left: (a) `stb r11,0x95` fault flag: the target stores the raw && phi while testing clrlwi; every C/C++ form
  (int/u8/bool local, char/signed char field, `(ts4_bool)` casts, `& 0xFF`, assignment-in-if) either stores the
  clrlwi value (r9) or allocates clrlwi r8 / flow r7 instead of r9 / r8. (b) players[w]/players[1-w]: target computes
  win = (rel + S) + 24w and lose = (rel - 24w) + S + 24; MSVC canonicalises every source form I tried (25+ helper and
  ordering variants) to (S +- 24w) + rel. (c) one `add r9,r9,r7` operand order in the set loop. LTCG checker: same 10.
- 0x886BC678 GamePlayEngine::Init (0x40C): size exact, ~6 local issues, source 886BC678_best.c. Left: (a) the inlined
  0x38-byte helper ctor: target stores the vtbl first, then the zeros, no interleaving (tried plain stores, result
  variable, C++ member ctors with placement new); (b) a dead `addi r11,r31,0x4c` (address of the limits block
  self+0x4C) before the config copy; struct assignment copies padding words, inline copy helpers leave no addi;
  (c) register order of `lis 0x3659`/`lis lbl_88D45B20`; (d) vcall slot 0x10 with a 12-byte struct arg: target loads
  word 2 into r6 and the vtbl into r5 before `rldicr r5,r6`; (e) court pair copy registers (array-dst form is closest).
  LTCG checker and /O1 /Ox: no improvement.
- 0x886750D0 reward tag tracker init (0x510): 3 instructions off, source 886750D0_best.c. Structure found:
  the 17-way tag chain must be an else-if chain calling a `__forceinline int ts4_tag_is(row, kind, name)`
  (returns `r->kind == kind && r->name == name`; gives the kind re-test and name reload), and the fn_88617788 name
  argument must be an if/else of two calls (lets r3 stay self). Loop 1 element: `char *pl = (char*)P + i*0x1070;
  ps = pl + P->offset`. Left: loop 2 element should be (P + rel) + i*0x1070, every form gives (rel + iN) + P or
  breaks loop 1 again (MSVC seems to canonicalise the reassociation per function). LTCG, /Oc, /fp:* no change.
- 0x886BF598 rule node Init (0x588, node 23428A2C): 7 instructions off, source 886BF598_best.cpp. Structure found:
  the stores to self+0x2C/+0x30/+0x3E must go through an inline helper taking a sub-object pointer
  (`struct Ts4RuleSub *` = &self->sub at +0x28): that makes them alias self->owner, so the owner reloads are not
  hoisted above them (fixed 8 instructions). The f5d0 float store sits at the end of that helper, and obj_48/obj_f4 are
  C++ objects with a virtual bind (slot 2). Analyser binds: a helper that reloads owner/graphs, takes `&name` of a
  by-value hash, and does no null check. Left: (a) the target loads obj_48's vptr before the owner load that feeds
  the f5d0 store, and gives that owner value r4. Every form tried (vt local before the store, comma in the argument,
  float local, C/C++ vtables, all 60 helper orders) loads the owner first. (b) First watcher: target does stw 0x100
  before lwz owner, we do the reverse. The second watcher, with identical source, matches. LTCG and /Oc: same 7.
- 0x886A9050 rule node ctor (0x5D8): size short by 17 instructions, source 886A9050_best.cpp (C++ ctor
  `??0Ts4RuleNode@@QAA@XZ`; members have inline ctors). Each 0x44-byte analyser needs two dead addis (a and
  a+0x14 for the 12-word block); we get only the first. Tried: a member Sub ctor, a nested Inner, a base-class split,
  clear() helpers, out-of-class inline/__forceinline ctors, C inline helpers, and loops over 3x4-word quads (they stay
  ctr loops or unroll with no addi). Placement new adds null checks (no /EH). Same idiom is open in the GA3/GA4
  ctor-family notes (0x88695568, 0x886A0408).
- 0x8865B658 stats row value >= tuning+0x14 (0x48): 1 instruction off, source 8865B658_best.c (GA1's entry).
  `lfsx f13,r11,r6` (row, rel): every form tried gives (rel, row). Tried both address orders, locals, a helper, and
  reversed compares. The same idiom resolved inside 0x886646B8 once the case order changed, so it depends on context.
- 0x88641ED0 (0x5D0, 28 calls, string/service temporaries with destructors) and 0x88665630 (0x988, the third
  45-case condition switch with a vector find in front): not attempted (time).
- 0x886646B8 condition progress (0x8A4, writes rule+8/+0xC for the same 45 hashes as the matched 0x88665010):
  8 instructions off, source 886646B8_best.c (add it to d2g_ai_conditions.c next to 0x88665010; it shares the types).
  What made it close: the three cases that go to the default body must be separate `current = 0; target = 0;` cases,
  or the compare tree changes. 0xAFBE5D69 must stay a separate copy of the slot-row body, which needs a different
  source form (a `match_1c` local). Case ORDER in the source fixes the add association: with D2CD5B31 first and a
  hill climb over the case order, 404 -> 8. Left: slot-row `subf/add` association in the 02CA group, `lis` placement
  of lbl_8814B440 in the forehand/backhand case, and r8/r9 swapped in 0xB1F46C7A. Two more seeds of the
  case-order hill climb do not go below 8.
- 0x8866A608 (GA2 entry): 4^4 combinations of rel-array address forms (with or without a header local, either add
  order) stop at 2 instructions off, same as GA2.
