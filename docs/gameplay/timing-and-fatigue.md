# Groundstroke timing and vigor (agent GE1)

Closes two items of [OPEN.md](OPEN.md): how the shot timing value `TimingState.TimingValue`
(S+0xD08) is computed (1.8), and how vigor is integrated (5.1, `S+0xF54/0xF64`).
Grades: **C** = read from code (`Swing_DLL.dll`, `tools/fn_asm.py`), **D** = read from
`Settings.bin` (sha256 `55cb175d...a0167`), **I** = inferred.

## 1. TimingValue: frames to the ball (C, D)

`fn_8867DF68` runs every frame from the per-player update (`fn_886BF360 +0xC0`, call at
`0x886BF420`). No analyser graph writes `S+0xD08`.

1. `TimingBaseFrame (S+0xD04) = 600`. If the ball prediction buffer (`(ctx+0xB4)->+0x88 +0x5A0`)
   is empty, `TimingValue = -1` and stop.
2. Reference point: the player's look-ahead position (`fn_8867A908`), moved 50 cm toward the
   ball (`SwingTimingSelectionList/<Baseline|Volley>/6d669a99` = 50).
3. Walk the predicted ball samples (0x30 bytes each) from the first; take the first whose `|x|`
   is beyond the reference `|x|` (I: the ball reaching the player's contact depth). Then
   `f = sample.tick - clock` (frames from now), stored in `TimingBaseFrame`. With no such
   sample the last one is used.
4. `TimingValue = lerp(curve_worst(f), curve_best(f), TimingAbility S+0xD0C)`, with the curve pair
   `SwingTimingSelectionList/Baseline/5ae85f27/{848c2a13, BestAbility}` (`PT+0x5D4`, file 0x778 /
   0x784) when `Context.IsVolley` is 0, else `.../Volley/...` (`PT+0x5F0`). `TimingAbility` is
   the output of the timing graphs (BaselineTimingAbility, VolleyTimingAbility).
   The curve evaluator is `fn_881899D8` (C): the last range with `InStart <= f` (else the first),
   ramped and clamped, the same semantics as the analyser curves (`graphs-decoded.md` s2).
5. The value is also copied to the GameplayInterface per-player block `+0x130` (HUD).

The request state machine freezes it: each of the three commit sites of `fn_886B3CF8`
(`0x886B3F28`, `0x886B45A0`, `0x886B4654`) stores `ManualShotTiming (S+0x544) = TimingValue`.

**Shipped curves** (D; worst and best are identical, so the TimingAbility graphs have no effect
in the retail game):

| frames to the ball at commit | <= 10 | 12 | 15 | 20 | 25 | 30 | >= 40 |
|---|---|---|---|---|---|---|---|
| baseline TimingValue | +1 | +0.5 | +0.25 | **0** | -0.25 | -0.5 | -1 |
| volley TimingValue | +1 | +0.6 | +0.3 | **0** | -0.3 | -0.6 | -1 |

Positive is **late**, negative **early**. Perfect timing is a commit **20 frames (1/3 s) before
the ball arrives**. Under normal conditions the fault graphs forgive `|t| < 0.3` (`graphs-decoded.md` s11), which is
about 14.4 to 26 frames for a groundstroke: a 12-frame (0.2 s) window. A volley's window is
15 to 25 frames.

What a player feels (C for the mechanism):
* The swing commits on the **release** of the shot button, or automatically **12 frames
  before contact** if the button is still held (`controls-and-shot-selection.md` s4). A held
  button therefore commits at about 12 frames, which reads as **late (t = +0.5)**.
* The power tier needs a long hold (Powerful from 53 frames). Combined with this, a powerful
  shot needs the button **pressed at least about 73 frames (1.2 s) before the ball arrives**,
  and released 20 frames before.
* The early/late asymmetry of groundstrokes is not in this curve, which is symmetric in frames.
  It is in the fault graphs (late errors cost about twice as much) and in the serve table
  (`controls-and-shot-selection.md` s9.3).

Tuning: edit the `Range[k]/InStart/InStop/OutStart/OutStop` rows of
`/SwingTimingSelectionList/<Baseline|Volley>/5ae85f27/<848c2a13|BestAbility>` in
`data/gameplay/tunables/Settings/02_PlayerSettings.yaml` (file 0x2B420..), then
`tools/ts4data/patch_tunables.py`. Making `BestAbility` differ from `848c2a13` turns the timing
ability graphs on.

## 2. Vigor (C; graph numbers from `graphs-decoded.md` s6.2)

PlayerState `Fatigue` block (`S+0xF20`, names from `Layoutall.bin`): `Input.SumAcceleration`
0xF20, `Input.SumPowerfulFactor` 0xF24, `Input.#080853e1` 0xF28 (animation costs),
`Input.#908acc60` 0xF2C (fatigue carried from earlier points), `Input.Random` 0xF30;
`Output.#3122036a` 0xF44 (this point's cost, FatigueIngame), `Output.#2c8fcdcc` 0xF48 (match
total), `Output.#09ff7c93` 0xF50 (recovery per rest unit), **`CurrentVigor` 0xF54**,
`CurrentRecovery` 0xF58, `#a50ecfff` 0xF5C, `#b2f052bb` 0xF60 (capacity), **`VigorMax` 0xF64**,
`Tired` 0xF68.

**Match start** (`fn_886902E8`): sums and outputs 0, `CurrentVigor = CurrentRecovery =
VigorMax = 1`; then the constant graphs run (FatigueConst, `80ce1a10`).

**During a point**, every frame of an active rally (`fn_88690540`, only when the controller mode
is 2 and the rally clock runs):
1. Movement load: `a = |second difference of the look-ahead positions at 10 and 20 frames| x
   0.1 x 0.001` (`g_ts4_script_constants+0x2AC`, `+0x80`; I for the geometric meaning). If
   `a > 0.02` (`+0x408`), `SumAcceleration += a`.
2. Animation load (`fn_8866ECA8`): for each animation tag event of the frame that matches an
   entry of the `PT+0x618` fatigue table (`/Fatigue` list, entries `{tag, key, cost +8, inside-out
   extra +0xC, once-flag +0x10}`), `#080853e1 += cost` (+ the extra when `IsInsideOut`).
3. FatigueIngame (graph 10) turns the sums into this point's cost `#3122036a`.
4. **`CurrentVigor = max(0, 1 - (carried + cost) / (2 x capacity))`**.

**At the end of a point** (`fn_8866EE48`, from `fn_8869F760` and `fn_886A5D38`):
1. `total += cost`, then `total = max(total - bonus, 0)` where the bonus is the controller's
   `+0x34` or `+0x30` when the match-info flags `+0xD5` / `+0xD4` are set (I: end of set / game).
2. `CurrentRecovery = max(1 - total / (2 x #a50ecfff), 0)` (when `#a50ecfff` is not 0).
3. **`vigor = min(CurrentVigor + recovery x rest, VigorMax)`**, with `rest` =
   `/Fatigue/a15d9c95` = 3 when the match-info flag `+0xD5` is set, `/Fatigue/3cd7e708` = 2 when
   `+0xDC` is set, else `/Fatigue/2aa60eef` = 1 (`PT+0x624/0x628/0x62C`, file 0x7C8..0x7D0;
   0 means 1). I: 1 after a point, 2 after a game, 3 after a set.
4. `carried = (1 - vigor) x 2 x capacity`; `SumAcceleration = SumPowerfulFactor = 0`.

So **VigorMax is the ceiling of between-point recovery**, not of in-point vigor. Graph `80ce1a10`
sets it to `lerp(lerp(0.5, 0.65, Stamina), 1, ramp(#cfd8dd5d 1..5))`: a low-stamina player can
recover only to about 0.5-0.65 until the ramp input grows. CurrentVigor feeds the fault graphs
(`ramp(vigor 0..0.2..0.4: -0.3 -> -0.1 -> 0)` in the control sum), RushSpeedCoef and
SwingSpeedCoef (movement and swing animation speed), Vivacity (transition speed), IsTired, the
wood graph 280 and the serve window.

Tuning: capacity and per-point recovery are the FatigueConst / `80ce1a10` graph keys
(`ts4_analyser_patch.py`); the rest multipliers and the animation cost table are in
`02_PlayerSettings.yaml` (`/Fatigue/...`).

## 3. Reference model

`ref/gameplay/timing.c` (`ts4_range_curve`, `ts4_timing_value`, shipped curves) and
`ref/gameplay/fatigue.c` (`ts4_fatigue_init`, `_add_acceleration`, `_update_vigor`,
`_point_end`), tested by `ref/gameplay/test_timing_fatigue.c` (run by
`tests/test_gameplay_ref.py`). The graph outputs (FatigueIngame cost, FatigueConst capacity and
rates, TimingAbility) are inputs of the model.

## 4. Reproduction

```sh
python3 tools/fn_asm.py fn_8867DF68 fn_88661B60 fn_886B3CF8 fn_88690540 fn_886902E8 fn_8866ECA8 fn_8866EE48
python3 tools/ts4data/ps_layout.py --range 0xCE0 0xD20      # TimingState
python3 tools/ts4data/ps_layout.py --range 0xF20 0xF80      # Fatigue
grep -n 'SwingTimingSelectionList\|/Fatigue/' data/gameplay/tunables/Settings/02_PlayerSettings.yaml
```
