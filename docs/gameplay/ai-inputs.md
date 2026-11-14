# AI: from component mixes to pad-equivalent inputs (agent GE1)

This note closes "how the AI turns ShotComponents and ServeComponents into inputs". It corrects
`movement-and-ai.md` B.2 ("AI gets neutral/auto aim because the stick is zero") and fills
`controls-and-shot-selection.md` s10.

Grades: **C** = read from code (`Swing_DLL.dll`, `tools/fn_asm.py`), **D** = data,
**I** = inferred. AI record = `State.bin` type `D7C700B9`, 0x274 bytes per player (`State root
+0xE8C`); `S` = PlayerState. Field names come from `Layoutall.bin`
(`python3 tools/ts4data/ps_layout.py --type d7c700b9`).

## 1. Summary

The AI's behaviour lists (`AI.AIStyle[].Difficulty[]`, `stats-coaches-career.md` s5) score
candidate behaviours and their mix graphs write **component weights** into the AI record. At the
decision point the code copies them into a `Final*` copy and turns them into the **same
PlayerState inputs a pad would write**: the stroke trigger, the left stick, Risk, the
follow-to-net bit and the power value. Every choice among strokes and aim directions is a
**weighted random draw** (`fn_8861E598`, the game RNG) over the non-negative weights. From
there the AI's shot goes through the human path: the decision tree, the aiming quads
(`aiming.md`), the shot-class graphs and the outcome roll. (C)

## 2. Component records (AI record offsets)

| block | offset | members in order (all floats) |
|---|---|---|
| `ServeComponents` | +0xF8 (copy `FinalServeComponents` +0x1FC) | Slice, TopSpin, Flat, Timing, FollowToNet, AimingEfficiency, OutEfficiency, FaultProbability, ServeStick, PressAndHold, AimingSideLeft, AimingSideCenter, AimingSideRight, AimingLengthShort, AimingLengthCenter, AimingLengthLong |
| `ShotComponents` | +0x138 (copy `FinalShotComponents` +0x23C) | Slice, TopSpin, Flat, Lob, DropShot, FollowToNet, PressAndHold, RiskyShot, AimingSideLeft, AimingSideCenter, AimingSideRight, AimingLengthShort, AimingLengthCenter, AimingLengthLong |
| `RepositioningComponents` | +0xDC.. (copy +0x1E0) | Volley, BaseLine, RushRepositioning, `2b4b4baa`, StopMoving, `2ac5965a`, `6e33662f` |
| `PositioningComponents` | (copy +0x1D0) | Volley, BaseLine, InsideOut, `79b99b60` |
| `Difficulty` | +0x170 | VeryEasy, Easy, Normal, Hard, VeryHard, Expert |
| misc | +0x1B8 FirstServe, +0x1C0 SwingReactionTime, +0x1C4/+0x1C8/+0x1CC Random1..3 | |

## 3. Weighted draws (C)

* `fn_886821A0(slice, topspin, flat)` (serve stroke): `r = U[0, s + t + f]`; `r < s` -> Slice,
  `r < s + t` -> TopSpin, else Flat. It writes `Serve.Classic.Throw<Stroke>` and the hit flag
  (`S+0x482..0x487`). Weights are clamped at 0 first (`fsel`).
* `fn_88682290(a, b, c)` / `fn_8867EB98` (aim axis): `r = U[0, a + b + c]`; returns -1
  (`g_ts4_script_constants+0x38`) for the first weight, 0 for the second, +1 for the third.
* `fn_8867EA10` (rally stroke): the same draw over Slice, TopSpin, Flat, Lob, DropShot.

## 4. Serve (C; AI serve state machine `fn_886B8180`: state 1 `fn_886825A0`, 2 `fn_88682350`, 3 `fn_88682800`)

`fn_886825A0` (decide):
1. Copy `ServeComponents` to `FinalServeComponents`.
2. Stroke = `fn_886821A0(Slice, TopSpin, Flat)`.
3. `Serve.Advanced.Throw (S+0x4B5) = ServeStick > 0.5`; `Serve.Classic.Throw (S+0x480) = !that`.
   The SwingSelection power flags are cleared and `Request.Style = S+0x610`.
4. `S+0x4E0` and `ReqVolleyRepos S+0x4DF` = `FollowToNet > 0.5` (serve and volley); AI `+0x1AC` = 1 or 0.
5. Serve gauge timing `S+0x66C = Timing`; `AimingState.Efficiency (S+0xD88) = AimingEfficiency`;
   `OutEfficiency (S+0xD8C) = OutEfficiency`.

`fn_88682350` (aim):
1. `x = draw(AimingSideLeft, Center, Right)`, `y = draw(AimingLengthShort, Center, Long)`, each
   -1 / 0 / +1; both negated on the far court side.
2. `Stick_Aiming (S+0x430/0x434) = (x, y)`; `#4fc9dd9e.PolarResult (S+0xD60/0xD64)` = (angle,
   1.0); `DirectionSelected (S+0xDAD) = 1`.
3. `S+0x688`, serve PressAndHold `S+0x670` and power `S+0xE00` = `PressAndHold`.

So an AI serve aims at one of nine stick directions (centre included) of the serve quads.

## 5. Rally shot (C; `fn_886B7208`)

1. Copy `ShotComponents` to `FinalShotComponents`.
2. If the current swing category `S+0x360` is `Fatality` (0xC78C8F06), Slice, Lob and DropShot
   weights become 0, and Flat is replaced by register f29 (I: 1.0) when TopSpin + Flat < 0.01.
3. Stroke = `fn_8867EA10(...)`. DropShot is played as **Slice + Risk**. Every
   `InputState.ShotTriggers` entry gets `Raise = (Id == stroke)`.
4. Aim as for the serve: `Stick_Aiming = (draw(Side L/C/R), draw(Length S/C/L))`, negated on the
   far side.
5. `InputState.Risk (S+0x4D8) = DropShot chosen || U[0, 1] < RiskyShot`. Risk changes nothing
   outside Slice (`controls-and-shot-selection.md` s15), so RiskyShot only matters for slices.
6. `S+0x4DF`, `S+0x4E0` = `FollowToNet > 0.5`; AI `+0x1AC` = 1 or 0.
7. Power `S+0xE00 = min(PressAndHold, min(frames since the opponent's launch, 75) / 75)`. The 75
   is `EngineConfig.Frequency (60) x 1.25` (`g_ts4_script_constants+0x55C`). So the AI's charge
   is capped by the time it has had, on the same 1.25 s ramp as a human's hold.
8. `(PC+0x50)->+0x28 -> +0xA8 = 0x2CE33943` (I: the default serve/return animation key).

The AI's timing does not come from here: the difficulty's `TimingExpression` graph writes
`ShotContext.ManualShotTiming` (`graphs-decoded.md` 4.2), and the FinalEfficiency graph is the
difficulty's `7bcf55ee` (`aiming.md` s4).

## 5b. Repositioning and positioning components (C; GE1, OPEN 4.2)

* **Copies.** `fn_886BADA0` copies `RepositioningComponents` (+0xDC..+0xF4) to
  `FinalRepositioningComponents` (+0x1E0..+0x1F8); `fn_886B81E0` copies `PositioningComponents`
  (+0xCC..+0xD8) to `FinalPositioningComponents` (+0x1D0..+0x1DC). `fn_886A4260` re-evaluates the
  repositioning list (`fn_88694030`, `fn_88693FA8`) and copies it the same way.
* **fn_886A4260 (AI repositioning after a shot):** `volley = U[0,1] < Final.Volley`;
  `@ReqFastRepos (S+0x4E2) = U[0,1] < Final.RushRepositioning`; then it picks the next mode
  `P+0x40` (3/4 or 5/6 by the volley draw and a doubles-partner position test).
* **fn_886A3DF0 (AI stop):** when `Final.#2b4b4baa >= 0.5` or `Final.StopMoving > 0.5`, and the
  hit-point value `ReceiverState.#c7b7bdac.#2c63ee31` (S+0xC24) is below `Final.#2ac5965a`, it
  zeroes the move command (aim mode `0x9E51242B` with a zero vector): the AI stands still.
* **Reaction delay:** planner state 0 waits `((ctx+0x50)+0x28)+0x1DC` frames after the
  opponent's hit (`fn_886B8468 +0x4D0`). With the AI record layout that word is
  **`FinalPositioningComponents.#79b99b60`**, so the reaction delay is a positioning component
  written by the difficulty's positioning mix graphs (this answers the "writer not located" of
  player-and-movement s1 item 4).
* `Final.#6e33662f` (+0x1F8) is read by `fn_886BB0A8` (human/AI input update; use not traced).

## 6. Consequences for tuning

* The AI's shot choice, aim, risk and approach rates are the **component mix graphs** of each
  difficulty's behaviour lists (`Expressions.bin`, see `graphs-catalogue.md`). There is no
  separate code-side AI decision for strokes or targets.
* Aim precision is the same quad mechanism as the human's. A harder AI comes from a higher
  FinalEfficiency (its graph), a better TimingExpression and better aim-direction weights.
* `StickOverride` (S+0xD70) and its flag `S+0xDAE` are written only by the debug shot editor
  (`fn_886B1BA0 +0x34`), not by the AI.

## 7. Reproduction

```sh
python3 tools/fn_asm.py fn_886825A0 fn_886821A0 fn_88682350 fn_886B7208 fn_8867EA10 fn_8867EB98
python3 tools/ts4data/ps_layout.py --type d7c700b9 --range 0xD0 0x280
```
