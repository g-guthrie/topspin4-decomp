# GP1 notes: shot rating, crowd excitement, point-end modifiers (WP1)

Module: Swing_DLL.xex, sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`.
Tools: `tools/fn_asm.py`, `tools/fn_check.py` (MSVC 16.00.10224.00, /O2 /Oi), Python 3.13.18. All addresses are
Swing_DLL.xex virtual addresses. Statements marked (?) are guesses.

## 1. What WP1 really is

The "shot evaluation" strings (`<Name> (S+%d)`, `END OF POINT MODIFIERS`, `Crowd excitement %d stress %d IMP.: %d`)
belong to one system: a **crowd excitement / shot reward model**. Each finished shot earns named rewards
("quality" tags with S+points); the points fill an excitement gauge (level + gauge), the level is sent to the
crowd/audio as the `SetExcitement` event (crc32 0xdcbb46e0), and at the end of the point a second pass
weights the point (rally length, winner type, game/set/match point, ...) and updates a crowd level (0..1) per player.
It is not the physics of the shot. The rating inputs are values written by the swing/ball code into the shot record.

## 2. Hashing

All identifiers are `zlib.crc32(name)` of the exact ASCII string (case-sensitive). Verified against the game's
own labels in fn_8865B780 (all 33 label strings reproduce their hash). Resolved names (crc32 -> name):
Ace fd119356, Volley 71198650, Let c9238771, Wood 9cafb633, DropShot 990377a5, Lob c718daaa, Slice fc6f57a1,
TopSpin d9fa1b37, Flat f578057a, Smash 7eb30f90, Service 2e20a34e, Forehand e630e16b, Backhand 45fffb93,
Normal 26296dd2, Fault 5e11f1a7, InNet 7ddec718, LetIn 8f903dfb, Single cd0b222f, KingOfTheCourt fb595db2,
Important 4850af43, Crucial c920ac38, EndOfPoint 87b1920f, SetExcitement dcbb46e0, PlayerSound 40ec437f,
Applause d3f7df83, Shot 0b352785, Idle 7c161a2b, Kick bee7703b (?), WinAce edc246a4, WinWinner 5e8f70a2,
WinSmash ae80ba27, WinPassingShot 5ba198eb, WinWinnerPowerfulShot 6add051e, WinServeAndVolley fa298a9c,
WinTwentyShots a0e0e3b0, LoseWinner a51ff087, LoseUnforcedError 74ea79ab, LoseUnforcedErrorEasyBall 90f481d0,
and the 33 reward labels listed in section 4.
Unresolved: 0x7110d0bb (mode of the per-shot call of fn_88685060), 0x731f583e (reward added when evaluator+0x37f==1),
0x629b9e5b (default of +0x2f4/+0x2fc), 0x31217b4c, 0xbcff8fb4, 0xfdbe3ef7 (events posted by fn_88683FA8/fn_88684AE0),
0xc222a5e0, 0x317c51b7, 0x6023f2af.

## 3. Per-shot call chain (fn_88697890, 0x300 B)

`fn_88697890(this, shot_a, shot_b)` (called through fn_8869EF08/fn_886C1ED8) runs the whole pipeline:
1. fn_88696718 (0x628 B): ingest the shot record: copies `shot+0x16c -> this+0x2f4`, `shot+0x174 -> +0x2fc`,
   `+0x188 -> +0x300`, `+0x178 -> +0x304`, `+0x19d -> +0x30c` (volley), `+0x199 -> +0x310`; reads the volley reaction
   time from the player block (`+0xc24`, stride 0x1070) into `+0x314`/`+0x388`; ~20 per-player counters in
   the stats rows (stride 0x134).
2. fn_88667720: per-hitter counts of DropShot/Lob/Slice/TopSpin/Flat (serves and special shots excluded).
3. fn_886674E8: efficiency streaks (below).
4. fn_88673A78: efficiency classification (below).
5. fn_88667C98: forehand/backhand counters (Smash excluded).
6. fn_88673C50: reward rules (below).
7. fn_88666FC8: excitement tier and stress tier (0..2) per player, stored at stats+0x170 (8-byte rows).
8. fn_88683E10 (0x198): posts a `PlayerSound` event for each reward hash that matches a row of the sound table.
9. fn_88683FA8 (0x754): applies the rewards to the excitement gauge.
10. fn_88684AE0 (0x204): decay. Fever: cfg+0xc8 counts down (event 0xfdbe3ef7 with value c8*step+base); at 0 the
    fever ends and level/gauge reset to 0 (`SetExcitement`). Normal: gauge -= cfg+0x80, borrowing cfg+0x7c from the
    level; event 0x31217b4c carries level*cfg+0x88+cfg+0x84.
11. distance run accumulation (position vector at player+0x8e0), `+0x394` (shots in rally)++, shift of the ring of
    10 shot totals (collector `+0x768..+0x78c`), clear `+0x78c`.

## 4. How a shot is rated

### 4.1 Shot inputs (ShotRecord, evaluator+0x20)
`+0x16c` stroke side/context hash (Forehand, Backhand, Service, Wood), `+0x174` shot type hash (Flat, TopSpin, Slice,
Lob, DropShot, Smash), `+0x178` float (power-like, 0 if unknown), `+0x184` float, `+0x188` float,
`+0x19d` volley flag, `+0x199` flag, `+0x220` hitter index, `+0xe4` shot valid, `+0x170` float.
Which physical quantity `+0x178/+0x184/+0x188` is cannot be proven from this package (no strings); roles by use:
`+0x188` is compared with the serve power limit (VeryPowerfulService) and the PowerfulShot minimum, `+0x178` with
the PowerfulShot minimum, `+0x184` with the volley power limit. Efficiency is a separate float per player,
`player->state(+0x74)->+0x588`.

### 4.2 Reward rules (fn_88673C50), thresholds in `ShotTuning` (evaluator+0x28, data driven)
* DropShot: shot type DropShot and efficiency > tuning+0x10c -> `DropShot`.
* Smash: shot type Smash -> `Smash`.
* Volley: `+0x19d` set -> if `reaction_time(+0x314) < tuning+0xe0`: `VolleyPowerfulShot` when `field_184 > tuning+0xdc`,
  else `VolleyShortReactionTime`; always `Volley`.
* Wood: stroke side == Wood -> `Wood`.
* Serve: stroke side == Service -> sets collector flag +0x74a; `field_188 > tuning+0xd0` -> `VeryPowerfulService`.
* Other strokes: `field_188 > tuning+0xd4` and `field_178 > tuning+0xd8` -> `PowerfulShot` (and sets +0x375).
* Reach: flag +0x374 (set by the swing/animation code) -> `ReachAnimation`; flag +0x37f -> reward 0x731f583e.
Flags +0x374/+0x37f are cleared afterwards. The "Reflex volley", "Rushing", "Smash animation", "Spectacular animation",
"Litigious bounce" labels (fn_8865B780) are produced outside this package (not found in fn_88673C50).
The reaction time is read in fn_88696718 from the hitter block at +0xc24 (index * 0x1070).

### 4.3 Efficiency classification (fn_88673A78)
Efficiency of shot A (new) and shot B (opposing) are `state+0x588` floats. The first row of the rel-array
`tuning+0x90` (rows of 0x30 bytes, `Gp1EfficiencyClass`) whose ranges all contain the inputs wins; its name hash
(`VeryEfficientShot`, `CounterEfficientShot`, `ReturnEfficientShot`, `VeryEfficientSlowShot`, `VeryPowerfulEfficientShot` ...)
is added as a reward and stored in `evaluator+0x2f8` (default `Normal`). Ranges: eff_b, eff_a, field_184, field_188,
field_178 (> lower, <= upper); a row flagged +0x2c is skipped for volleys. Serves are skipped. Independent of the
class, a counter `+0x378` counts consecutive shots with efficiency > tuning+0xe8 and awards
`ConnectedEfficientShots` once it reaches tuning+0xe4.
The numeric ranges are in the XData tuning block, not in code.

### 4.4 Efficiency streak (fn_886674E8)
If eff_a < eff_b, eff_b > tuning+0x00 and the stroke is not a serve: the better player's streak (rows at
tuning+0x0c, 8 bytes {count, flag}) is incremented and the other player's streak reset; otherwise the better
player's streak is reset; flag = streak >= tuning+0x04. Debug: "Sen %d Rec %d", "T0 %s(%d) T1 %s(%d)",
"Shot efficiencies %.2f %.2f".

### 4.5 Reward -> points (fn_88683FA8, fn_8865B780)
Rows `Gp1RewardDef` (stride 0x1c) at `cfg+0xdc`: {name_hash, S points, team hash, cap, min level, scale, enabled-singles,
enabled-doubles}; doubles is `game_mode_block+4 == 2`. Points add to the point total (+0x760/+0x78c) and the gauge;
level-up while gauge >= cfg+0x7c; level clamped to [cfg+0x70 if raised, cfg+0x74]; reaching the top enters a fever
state (+0x748). The debug HUD prints `<Name> (S+points)` (fn_8865B780; unknown hashes print the name through
fn_8860C1C0) and `(E<level>)`.

## 5. End of point (fn_88685060, 4272 B)
Called with `(this, mode hash, &outcome hash)`. The weights are ints in `cfg+0xe8..0x16c` (`Gp1PointWeights`).
Named modifiers: rally length (Short/Memorable/Boring/Epic), PowerfulEfficientShot, PowerfulShot, VeryEfficientShot,
VeryEfficientReturn, Baseline winner, Passing shot, Volley winner, Volley, Spectacular anim, Trickshot, Wood, Risk,
Smash, Lob, Dropshot, Reach, Fatality, Ace, Double fault, Return, Fault (general), Obviously out, Game point, Set point,
Match point, Litigious, Let, Important point, Crucial point, First game. Court geometry constants (centimetres):
doubles half width 549.0, singles half width 412.0, "obviously out" margin 50.0 beyond the sideline, 1300.0 along
the court. The clamped sum (excitement level + total, 0..10) indexes `cfg+0x17c` (8-byte rows, float at +4) to give
`tuning+0x140`; the last 10 shot totals (+0x768..+0x78c) are summed into `tuning+0x144`.

## 6. Crowd reaction (fn_8868E370, fn_8868EA30, fn_8868E950)
fn_8868E370 sums the table rows {event hash, float} at `crowd+0x44 -> +0x6c + 0x83c` for the rows whose condition
holds (WinAce, WinWinner, WinWinnerPowerfulShot [ball speed `> 140.0`], WinPassingShot [`|v| < 500.0`], WinSmash,
WinServeAndVolley, WinTwentyShots [>= 20 shots], LoseWinner, LoseUnforcedError [`v > 0.5`], LoseUnforcedErrorEasyBall
[`v > 0.9`]).
fn_8868EA30 per rally: `ratio = accumulated(+0x344)/shot_counter(+0x1048)`; gain from fn_8868E950 (2-D step table at
`+0x824`: first row with level <= row.limit, then first column with ratio <= key); cap from the 8-byte table at
`+0x830` by shot count; `level = clamp(level + events + clamp(gain,-cap,+cap), 0, 1.0)`. Display scale 100.0.

## 7. Other
* fn_88661D58: prints three floats at `(evaluator+0x10 -> +0x48 -> +0x28) + 0xf28` as "In : Out : Net :" (shot outcome odds). The VMX
  loop in it computes values that are not stored.
* fn_88666F18 / fn_886630B8 / fn_8865C0C8 are debug text only (matched).
* Event posting: fn_88683D78 allocates `fn_88181240(queue, hash, {0,0})`, fills payload {hash, target, a, b, c, value} and
  pushes with fn_8861DDB0.

## 8. Matching status
Matched (see work/specs/GP1): fn_88666F18, fn_886630B8, fn_8865C0C8, fn_88673630 (4 functions, 0x230 bytes).
Near matches (drafts): fn_88683D78 (3 instr), fn_8865B780 (frame size), fn_88667720 (34 instr), fn_88667C98 (41 instr),
fn_8868E950 (51 instr). Drafts: shot rating, excitement, point end. Not attempted for matching: fn_88685060,
fn_88683FA8, fn_88697890, fn_8868E370, fn_8868EA30 (fsel clamp idioms), fn_88661D58 (VMX).
Compiler idiom: the debug functions keep 0x20/0x30 bytes of unused locals below the text buffer; wrap the buffer in a
struct with a leading `unused[]` member to reproduce the frame.
