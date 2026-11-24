# RT1 near misses and unverified functions (2026-11-15)

Agent RT1, ranges 0x88640000-0x886E8000 and 0x889C0000-0x889C3000. All measurements were made with
`TS4_MATCHING_DIR=work/matching-b46` and the repository's `tools/fn_check.py` / `tools/fn_equiv.py`.
Byte-diff numbers come from `python3 tools/fn_check.py <src> <name>=<addr> [--flags /Oc]`.
Equivalence evidence: `work/specs/RT1/<stem>.equiv.json`, `work/equiv/rt1_<addr>.json`, seed 1.
`+hashes` = `work/army/RT1/fn_equiv_hashes.py` (runs `tools/fn_equiv.py` unchanged, adds the
`lis`/`ori` and `addis`/`addi` 32-bit constants to `code_consts`; checker string `fn_equiv/1+hashes`).

## Matched (for reference)

| function | source | size |
|---|---|---|
| `fn_88669878` | `src/xbox360/rt1_serve_flags.c` | 0x21C, base flags. Key: store `second_serve_let` before `missed_serve`. |
| `fn_886935A0` | `src/xbox360/rt1_aim_get_target.c` | 0x8C, base flags |

## EQUIVALENT, not byte-matched

| function | source | evidence | what blocks the byte match |
|---|---|---|---|
| `fn_886629C8` ShotSpecific_Fill | `rt1_eq_shot_specific_fill.c` | 45 valid of 609, 15/15 blocks, /Oc | 8 instructions of scheduling: +0x30 grade load order, +0x70 `stfs` vs `addi`, +0x15C key load vs `beq`. Same on the plain route (/Oc) and on LTCG with `ga1_gameplay_a.c` as context (fn_8865EB60 inlined). |
| `fn_886AFDF8` SwingCategory_Walk | `rt1_eq_swing_category_walk.c` | 345 of 584, 67/67, /Oc | the original keeps r4 live across the call to `fn_8866D930` (LTCG register convention); our build reloads it, and the allocation shifts from there. Needs the callee in the LTCG context with the right inlining. |
| `fn_886B0250` SwingCategory_Select | `rt1_eq_swing_category_select.c` | 339 of 432, 11/11 | 57 diffs: register allocation and block order of the result-variable form. |
| `fn_88695C48` AimingState_Evaluate | `rt1_eq_aiming_evaluate.c` | 264 of 325, 11/11 | 6 diffs, register numbering only (f-register pair swapped). |
| `fn_8866F740` Mover_PreHitFreeze | `rt1_eq_prehit_freeze.c` | `+hashes` 429 of 613, 28/28 | 0x2AC vs 0x2B0, 138 diffs from +0x10. The original copies the stick/latched move with `clrrwi rX,rY,0` (open idiom, no source form found) and reloads `self->pc->state` between stores. |
| `fn_886CD3C8` AnimNode_BusyFrames | `rt1_eq_anim_busy_frames.cpp` | 956 of 1500, 4/4, /Oc | LTCG with context `flags(/Ob1):src/xbox360/gp7_anim_busy.cpp` is 37 instructions off: `clrrwi` reload, `fmadds` contraction (we get it only without /fp:precise, but then lose the `mfcr` select), `mfcr`/`fsel` orientation (we add an `xori`). |
| `fn_8866A1C8` Scoring_OnPointEnd | `rt1_eq_serve_point_end.c` | `+hashes` 1865 of 3000, 95% (38/40), /Oc | 10 diffs. The plain checker reaches only 82% because the serve-rule branches switch on hash keys. The two uncovered blocks need match states the generator does not build. |

## Compiles, unverified (VMX128)

`tools/fn_equiv.py` emulates with Unicorn, which has no VMX128, so it reports UNCHECKED for all
four. Current byte distance:

| function | source | measurement |
|---|---|---|
| `fn_8867DF68` TimingState_Update | `rt1_vmx_timing_update.c` | 0x314 vs 0x320, 193 diffs from +0x8; frame 0x130 vs 0x120. A C4700 warning (uninitialised `back` before `vrlimi`) is expected: the original reads the same undefined lanes. |
| `fn_886807C0` outcome roll | `rt1_vmx_outcome_roll.c` | 0x7A8 vs 0x900, 568 diffs from +0x10, relocations 21 vs 33 (we address the float constants off one base, the original loads them separately; it also uses `mfcr`/`fsel` selects). |
| `fn_8869B928` Repositioning_HumanMode | `rt1_vmx_net_rush.c` | 0x29C vs 0x2A4, 161 diffs from +0x8. |
| `fn_889C1C80` bounce response | `rt1_vmx_ball_bounce.c` | 0x300 vs 0x2EC, 164 diffs from +0x10. |

### Native trace plan

Same method for all four: build a test XEX (or a hooked Swing_DLL) that contains both the original
function and the RT1 build of it, under a different name. At each call of the original, snapshot
the inputs listed below, call the RT1 copy on a deep copy of those inputs (same RNG state), then
call the original, and compare the outputs bit for bit (floats as raw u32, vectors as 4 x u32;
treat NaN payload differences as a failure). Log the first mismatch with its inputs. Play sessions
to cover: rallies with baseline and volley shots, serves (first and second, human and AI), forced
errors, net and let outcomes (DebugConfig net/let enabled), net rushes with and without RB, and
balls bouncing at low and high speed with and without side spin. Report per function: calls seen,
mismatches, and which branches were reached (instrument the RT1 copy with branch counters).

| function | inputs to snapshot | outputs to compare |
|---|---|---|
| `fn_8867DF68` | self->pc; PlayerState is_volley and TimingAbility; PlayerTuning baseline/volley curve blocks (reach_offset, best, worst lists); body line (point, dir); predicted ball samples (pos, tick) and match flow frame; team side tag; result of `fn_8867A908` (look-ahead position) | TimingState base_frame and value; the HUD player block timing_value |
| `fn_886807C0` | the full ShotPlan, *target, PlayerState fault/error/let probabilities and force flags, stick x/y, out efficiency, AI record serve fields, DebugConfig net/let flag, flow flags 0x328/0x329 and state, `forced`, RNG state before the call, court bounds from `fn_8866E318` | *out, plan target and outcome, *target, AimingState efficiency/out efficiency/quad efficiency, stick x/y, Debug.ChosenOutcome, RNG state after the call |
| `fn_8869B928` | r (mode, net point); team human flag; PlayerState LocalPosition, move power, stick angle, ReqFastRepos; repositioning settings; match mode kind; next-hitter planned frame and flow frame | r->mode, the behaviour flags set by `fn_8868C218`, PlayerState repositioning_active (S+0xA2D) |
| `fn_889C1C80` | *vel, ball template curves, ball spin[3], no_sidespin flag, pos | *vel, spin[3], arc2 position and velocity, drift written by `fn_889C0DC0` |

A cheaper partial check: run the RT1 copies through a PowerPC emulator that has VMX128 (Xenia's
interpreter) with the snapshot inputs above captured once from a trace.
