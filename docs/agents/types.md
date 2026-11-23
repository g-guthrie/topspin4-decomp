# Shared gameplay types (`src/xbox360/include/ts4/`)

One layout per gameplay class, shared by every source. Use and extend these types; do not declare a new
private struct for a class that has a shared type.

## Where things live

| header | contents |
| --- | --- |
| `ts4/base.h` | `TS4_EXTERN_C`, `TS4_NOINLINE`, `TS4_INLINE`, `TS4_OFFSETOF`, `TS4_STATIC_ASSERT`, `TS4_ASSERT_OFFSET`, `TS4_ASSERT_SIZE` |
| `ts4/math.h` | `Ts4Vec4` (union: `v` / `f[4]` / `q[2]`), `Ts4Line`, `Ts4RangeList`, C++ `Ts4VecD` / `Ts4LineD` |
| `ts4/containers.h` | `Ts4RelArray`, `Ts4RelArray12`, `TS4_REL_AT`, `TS4_VECTOR`, `Ts4PtrVector` |
| `ts4/match.h` | forward declarations of every class; `Ts4Match`, `Ts4MatchFlow`, `Ts4DebugConfig`, `Ts4World`, `Ts4Settings`, `Ts4GameplayInterface`, `Ts4RulesInfo` |
| `ts4/player.h` | `Ts4Player` (the hub), `Ts4PlayerState`, `Ts4PlayerTuning`, `Ts4Team`, `Ts4TeamState`, `Ts4AIController`, `Ts4AIRecord`, `Ts4Body`, `Ts4Mover`, `Ts4HoldCounter`, `Ts4ReceiverState`, `Ts4PlayerComponent`, `Ts4ControllerMode` (C++), `Ts4SwingController`, `Ts4Repositioning` |
| `ts4/planner.h` | `Ts4MovePlanner`, `Ts4CandidateSet`, `Ts4ReachRecord` |
| `ts4/ball.h` | `Ts4Ball`, `Ts4BallArc`, `Ts4BallSample`, `Ts4BallPrediction`, `Ts4BallSys`, `Ts4BallLink` |
| `ts4/shot.h` | `Ts4ShotTemplate`, `Ts4ShotRow`, `Ts4ShotTree`, `Ts4ShotContext` |
| `ts4/ts4.h` | umbrella, include this one |

Include form in a matched source: `#include "include/ts4/ts4.h"`. `fn_check.py` and `fn_check_ltcg.py`
already pass `/I src/xbox360`, so no tool option is needed. Host checks use `-Isrc/xbox360/include` and
`#include "ts4/ts4.h"`.

Object graph (all V): `Ts4Player` +0x2C tuning, +0x44 world, +0x48 match, +0x4C team, +0x50 ai, +0x5C mover,
+0x68 body, +0x70 shot_ctx, +0x74 state, +0xAC tree, +0xB0 row, +0xB4 ball_link; `Ts4Match` +0x28 debug,
+0x30 flow, +0x44 hud, +0x5C balls; components +0x1C -> player; `Ts4MovePlanner` +0x154 -> player.
`Ts4Player` is the class the docs call PlayerCtx / PC and `d1g_types.h` calls `Ts4PlayerController`.

## Conventions

- Names: `Ts4<Class>` for types, `snake_case` fields, `pad_XXXX[N]` (`char`) for unknown regions where XXXX
  is the hex offset, `f_XXX` for a field whose offset and width are proven but whose meaning is not.
- Every field carries `/* +0xOFF <tag> <evidence> */`:
  - `V <addr> ...` verified: read or written at that offset by the byte-matched function(s) at those
    addresses. A trailing `~` means the class of the base pointer was attributed by access-pattern
    signature rather than by a typed pointer chain; treat the offset as proven and the class as probable.
  - `U <source>` unverified: taken from docs or an older private header (`d1g_types.h`, `rt1_types.h`,
    `gp2_types.h`, `gp3_types.h`, `bm_ball.h`). Never rely on a U field without matching a function on it.
- Every struct with a known size has `TS4_ASSERT_SIZE`; named fields have `TS4_ASSERT_OFFSET`. The asserts
  are real under MSVC 16 PPC and any 32-bit target and vacuous on a 64-bit host. To check offsets on the
  host: `clang -target powerpc-unknown-linux-gnu -fms-extensions -fsyntax-only -Isrc/xbox360/include tu.c`.
- Prototypes of already-matched functions sit in the header of the class of their first argument and use
  the `symbols.txt` name. Labelled pointer parameters are typed (`struct Ts4Player *`), others stay as
  matched.
- C vs C++: all headers are valid C11 and C++. Structs are plain C structs. C++-only pieces are fenced with
  `#ifdef __cplusplus` and exist only where codegen needs them: `Ts4VecD` / `Ts4LineD` (vector with a
  user-declared destructor) and `Ts4ControllerMode` (virtuals). Write a function in C++ when the original
  is a method with class codegen (virtual calls, destructors, by-value class temporaries); C otherwise.
- Vector flavours: `ts4/math.h` uses `vx1_vector.h` (`__vector4` aligned 16) by default. A source that
  needs the align-4 flavour includes `ts4_vector.h` before `ts4.h`.
- `Ts4Vec4` lets one field be used as a VMX vector (`.v`), as scalars (`.f[i]`) or as two 64-bit copies
  (`.q[i]`); pick the member that reproduces the original load/store width.

## Adding or changing a field

1. Match the function first, using the shared type with the field added locally in your working copy of
   the header.
2. Replace the pad: split `pad_XXXX[N]` around the new field, keep offsets in the comments, add
   `TS4_ASSERT_OFFSET`.
3. Tag it `V <address of your matched function>`. Append addresses to an existing V list; promote a U field
   to V by replacing the tag.
4. Run the four header checks (host cc/c++, PPC clang/clang++, commands below) and re-check one matched
   source that includes the header.
5. Do not rename a V field without updating every source that uses it (`grep -rn "->name" src/xbox360`).

```
printf '#include "ts4/ts4.h"\n' > /tmp/tu.c; cp /tmp/tu.c /tmp/tu.cpp
cc -std=c11 -Wall -Wextra -Werror -fsyntax-only -Isrc/xbox360/include /tmp/tu.c
c++ -fsyntax-only -Isrc/xbox360/include /tmp/tu.cpp
clang -target powerpc-unknown-linux-gnu -fms-extensions -std=c11 -Wall -Wextra -Werror -fsyntax-only -Isrc/xbox360/include /tmp/tu.c
clang++ -target powerpc-unknown-linux-gnu -fms-extensions -fsyntax-only -Isrc/xbox360/include /tmp/tu.cpp
```

## Resolving conflicts

- Byte-matched code beats docs and older headers. Two matched functions cannot disagree about an offset,
  only about type, name or class.
- Type disagreement (pointer vs `unsigned int`, `int` vs `unsigned`, scalar vs vector): keep the type the
  majority of matched functions need, note the other in the comment (`also read as ...`), and cast at the
  minority use. If a cast breaks the match, make the field a union of the two views.
- Same offset, different meaning in two functions: first suspect that the base pointers are different
  classes. Split the class only when a matched function proves it (different size, different vtable,
  field overlap); otherwise keep one field with the neutral name `f_XXX`.
- Name disagreement: the name backed by a string, a vtable name or the gameplay docs wins; put the other
  name in the comment.
- Record every conflict in the table below with both addresses.

## Usability proof (2026-11-23)

Copies of matched functions rewritten against the shared headers only (no private structs), checked with
`TS4_MATCHING_DIR=$PWD/work/matching-b215`. Sources: `work/ts4types-scratch/` (ignored by git).
`P` = `python3 tools/`.

| function | original source | lang | result | command |
| --- | --- | --- | --- | --- |
| `ts4_line_init_normalized_8826AC10`, `ts4_line_init_two_points_88189888` (math) | `q5_line_init.c` | C | MATCH x2 | `P/fn_check_ltcg.py v_line_init.c ts4_line_init_normalized_8826AC10=0x8826AC10 ts4_line_init_two_points_88189888=0x88189888 --context src/xbox360/pp1_pool_primer.c --flags /Oc` |
| `ts4_line_closest_point_8826D3A0` (math) | `q5_line_project.cpp` | C++ class | MATCH | `P/fn_check_ltcg.py v_line_project.cpp ts4_line_closest_point_8826D3A0=0x8826D3A0 --auto-context --flags /Oc` |
| `ts4_planner_update_committed_8866BD00` (move) | `q5_planner_commit.c` | C | MATCH | `P/fn_check_ltcg.py v_planner_commit.c ts4_planner_update_committed_8866BD00=0x8866BD00 --auto-context --flags /Oc` |
| `ts4_shot_request_repress_88698538` (shot) | `d1g_shotreq.cpp` | C++ | MATCH | `P/fn_check.py v_shotreq.cpp ts4_shot_request_repress_88698538=0x88698538` |
| `ts4_bm_ball_arc1_position_888AB558`, `ts4_bm_ball_launch_velocity_888AB220` (ball) | `nm2_ball_a.c` | C | MATCH x2 | `P/fn_check.py v_ball_arc1.c ts4_bm_ball_arc1_position_888AB558=0x888AB558 ts4_bm_ball_launch_velocity_888AB220=0x888AB220` |
| `ts4_controller_activate` 0x886B83B0 (ctrl) | `me_ts4_controller_activate_886B83B0.cpp` | C++ class (virtuals) | MATCH | `P/fn_check_ltcg.py v_controller_activate.cpp ts4_controller_activate=0x886B83B0 --auto-context --flags /Oc /Ob1` |
| `ts4_query_slot_matches_target_8865EB60` (ctrl) | `ga1_gameplay_a.c` | C | MATCH | `P/fn_check.py v_slot_match.c ts4_query_slot_matches_target_8865EB60=0x8865EB60` |

The three `--auto-context` runs also MATCH with the explicit contexts of their specs. `v_controller_activate.cpp` still declares small local structs for classes that have no shared type yet (rig at `Ts4Player`+0x60, slot table, variant); every class that has a shared type uses it.

## Known conflicts

| # | where | A | B | status |
| --- | --- | --- | --- | --- |
| 1 | `Ts4Player`+0x10 (byte) | `is_human` (rt1, 0x886AFDF8) | `is_ai` (0x886B83B0) | same byte, opposite names; header keeps `is_human`, polarity unproven |
| 2 | `Ts4Player`+0x50 | AI record pointer (0x886AFDF8) | `variants` object with owner at +0x28 (0x886B83B0, 0x886A0EC8) | one object; header: `Ts4AIController *ai`, `ai->record` at +0x28 |
| 3 | `Ts4PlayerComponent`+0x20 | `unsigned int` (0x8865AD50) | `__vector4` (0x88679518) | probably two component classes sharing the +0x1C player link; split when a size or vtable proves it |
| 4 | `Ts4SwingController`+0x40 | `unsigned` (0x88698538) | `int` (0x886AFDF8) | header `unsigned int walk_misses`; 0x886AFDF8 casts |
| 5 | `Ts4Player`+0x18 and other pointer fields | typed pointer | `unsigned int` in asm2c-style sources (0x8865AD50, 0x8865EC70, 0x886A31B8) | header keeps pointers, comment says `also read as unsigned int` |
| 6 | `ts4_if_get_u32_off4c_8865EC70` | defined `void(unsigned, unsigned)` | callers use `__vector4 *(__vector4 *out, Ts4Player *)` | header has the caller form; the name is wrong (returns a vector through `out`), rename when re-matched |
| 7 | swing controller class name | symbols.md: `PlayerController *` for 0x886AFDF8 | rt1: SwingRequest with +0x1C -> hub; d1g `Ts4PlayerController` is the hub | header: `Ts4SwingController` (component) and `Ts4Player` (hub) |
| 8 | `Ts4Player`+0x2C pointee | tuning | data / court / vecs in other sources | `Ts4PlayerTuning` |
| 9 | `Ts4Match`+0x30 pointee | flow | `Ga1Slot32A`, pawn | `Ts4MatchFlow` |
| 10 | `Ts4BallPrediction`+0x5A0 element | `Cl1Rec30` | `Gp2BallSample`, `Q5fKeyElem` | `Ts4BallSample` (0x30) |
| 11 | `Ts4Player`+0x78 | move path state with rel array at +0x380 (q5_path_sample) | `Ga4DelayCfg` (0x886A5BB0) | unresolved; left as `void *` |
| 12 | `Ts4Player`+0x60 | rig | query | unresolved name |
| 13 | `Ts4DebugConfig`+0xF57 | `force_row` | `freeze_shot_flags` | unresolved name |
| 14 | `Ts4Ball`+0x24 | pointer (0x888AD0E8) | word (0x888AC688) | pointer, see 5 |
| 15 | `Ts4ReceiverState`+0x3BC..0x3CB | four scalars | two `{int frames; float value}` pairs | 0x88698538 only matches with the pair struct (`Ts4HoldCounter`): register allocation differs with scalars |

## Next header pass

- Most matched gameplay functions still use anonymous or private structs, so evidence per class is thin.
  Migrating existing sources to the shared types (re-check each) is the main source of new V fields.
- Not covered yet: container and string classes, rules and scoring (`rt1_scoring.h`), `Ts4Repositioning`
  (all U), AI classes beyond the record link, `Ts4Mover` state machine, move-path state (`Ts4Player`+0x78),
  the remaining `Ts4PlayerState` regions.
- Identify classes by vtable (`vtables.json`) to settle conflicts 3, 7, 11, 12.
