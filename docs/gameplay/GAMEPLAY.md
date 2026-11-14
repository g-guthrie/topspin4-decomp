# Top Spin 4 gameplay engine: the current end-to-end account

This is the single current description of how a point is played in Top Spin 4 (Xbox 360,
`Swing_DLL.dll`, disc data `Settings.bin` sha256 `55cb175d...a0167`). It follows one shot from
the pad to the score. Each section gives the mechanism, the real numbers and the note that holds
the evidence. Where this file and an older note disagree, this file and the notes it links win.
Items still open are in [OPEN.md](OPEN.md). Names, prototypes and layouts are in
[symbols.md](symbols.md). How to change each value is in [TUNING.md](TUNING.md).

Grades, as in the notes: **C**/**V**/**H** = read from code, **D** = read from data, **I** =
inferred. Units: world cm (x along the court, net at x = 0, y up, z across), 60 frames per second
(`EngineConfig.Frequency`).

## 0. The model in ten lines

1. The pad fills `PlayerState.InputState` through a data-driven InputMapper. The AI fills the
   same fields from weighted random draws.
2. The **hold time** of the shot button is the power: `power = min(frames / 60, 1.25) / 1.25`.
3. A 33-node data decision tree picks a **shot template row** (stroke x tier x situation).
4. The **frames between the release and the ball's arrival** give the timing value (0 = 20 frames).
5. Analyser graphs (data, `Expressions.bin`) turn ratings, timing, position, fatigue and skills
   into **FaultProbability**, **OutcomeNet**, **LetProbability** and aim **efficiencies**.
6. The left stick picks a **landing target** on quads that shrink toward the centre as aim
   efficiency falls.
7. **Dice are rolled before the launch**: In, Out (3 cm past a line), Net or Let.
8. The ball flies on a **closed-form** drag-plus-drift arc solved to land exactly on the target.
9. Movement is a 23-state planner choosing Rush or Jog from slack-time tables; swing clips are
   chosen by geometric fit and time-scaled to the contact frame.
10. Vigor falls with movement and swing load during a point and recovers between points up to a
    stamina-dependent ceiling. Rules, crowd and rewards run on the result.

## 1. Frame and ownership

The gameplay engine is one module of the CoreTech scheduler; each player has a
PlayerController (`PC`) holding a PlayerState (`S`, the 0x1000-byte block typed by
`Layoutall.bin`), and the shared PlayerTuning block `PT` = `Settings cfg+0x180`
(file 0x1A4) (gp0, gp3 s1, player-and-movement s1). The main frame `fn_886B5128` applies
commands, steps the ball, runs the prediction (the game's own stepper, up to 600 ticks) and the
per-player update `fn_886BF360` (gp3). Field names come from the reflection table
(`tools/ts4data/ps_layout.py`).

## 2. Input

* **Buttons** (D, `data/gameplay/input_map.yaml`): A/B/X/Y = Flat/TopSpin/Slice/Lob; LT or RT =
  `Risk` (trigger > 128/255); RB = Rush + fast reposition + go to the net; LB = speed swing /
  baseline reposition; left stick = aim and movement (0.4 radial dead zone); right stick =
  advanced serve (controls s0, s3).
* **Risk** changes the shot only under Slice (drop shot / drop volley). LT alone also requests
  an inside-out shot (controls s15).
* **AI**: the difficulty's behaviour lists write component weights; the code draws the stroke,
  the aim direction (one of nine stick directions), Risk, follow-to-net and power from them, then
  the shot goes through the human path ([ai-inputs.md](ai-inputs.md)).

## 3. Shot request, power and the template row

* **Request state machine** `fn_886B3CF8`: press latches the stroke (Flat > TopSpin > Slice >
  Lob); the swing commits on **release**, or automatically **12 frames before contact**
  (`PT+0x740`) if the button is still held (controls s4).
* **Power** (C): `power = min(frames held / 60, 1.25) / 1.25`. Tiers (D): **Finesse < 0.15 <=
  Medium < 0.70 <= Powerful**, i.e. under 11 frames, 11 to 52 frames, 53 frames and more
  (controls s5).
* **Tree** (D): Wood, serves (stroke x tier), smash, baseline (tier x stroke; Slice + Risk = drop
  shot), volley (stroke only). The Risky rows 12-15 are reachable only through the debug override
  (controls s6, shot-to-template). The planner `fn_886B0490` runs at the animation point.
* **Serve**: power = release time / toss length; Powerful above 0.8, Medium from 0.1; the serve
  gauge timing comes from a per-animation curve (controls s9).

## 4. Timing ([timing-and-fatigue.md](timing-and-fatigue.md) s1)

Every frame `fn_8867DF68` finds the frames `f` until the predicted ball reaches the player's
contact depth and maps them through `SwingTimingSelectionList` curves (D): groundstroke
`f <= 10: +1`, `12: +0.5`, `15: +0.25`, **`20: 0`**, `25: -0.25`, `30: -0.5`, `>= 40: -1` (volley
±0.6/0.3 instead of ±0.5/0.25). Positive is late. The value is frozen into `ManualShotTiming`
(S+0x544) at the commit. So the perfect release is **20 frames (1/3 s) before the ball arrives**;
holding to the auto-commit gives +0.5 (late). The TimingAbility blend has no effect in retail
(both curves are equal). The AI's timing is its difficulty's TimingExpression graph instead.

## 5. Shot error ([graphs-decoded.md](graphs-decoded.md) s11)

Each of the 33 shot classes has a fault graph and a net graph (V):

```
c = clamp01(0.8 + running far and fast (to -0.5) + full charge (-0.15) + fast ball (to -0.6; its
            input S+0x770 has no writer, so probably inert in retail, OPEN 1.10)
            + fatigue ramp(vigor 0..0.4: -0.3 -> 0) + contact point, pressure, skill terms)
e = lerp(lerp(hard(t), easy(t), c), lerp(hard2(t), easy2(t), c), HandAttributeQuality) * rally term
FaultProbability = dz(lerp(ErrorResolution.Min, Max, e)),  dz(x) = 0 below 0.15
```

The `ErrorResolution`, `PowerResolution` and `AimingResolution` ranges come from the shot's
`ShotDef` row, always its **Good** grade (the swing keys that select the grade are never set to
anything else; OPEN 1.9). Inside `|t| < 0.3` a groundstroke is safe under normal conditions; late errors cost about twice
early ones; the hand stat halves the penalty. Flat/power classes are the least forgiving, volleys
the most; the drop shot misses 30-40 % at `|t| = 0.3`. OutcomeNet sends low-contact errors
(below 90 cm) into the net. LetProbability is 0.02 fading to 0. Human serves use deterministic
0/1 fault graphs with a gauge window of about -0.4..+0.8. The additive term `S+0x564` is always 0.

## 6. Aim ([aiming.md](aiming.md))

* The target selector (`fn_886935A0`) reads `Stick_Aiming` (S+0x430); no direction gives the
  zone centre. Far-side players have the stick negated.
* Settings holds **25 AimingConfig rows** (D, `data/gameplay/aim_tables.yaml`), keyed by the
  template name (FlatReturn for returns). Each has four zones (VolleyCenter/Side,
  BaselineCenter/Side) of four quads: q0 near the centre, q1, **q2 = the court lines**, **q3 about
  3 m out**. The hitter's position blends the zones (`lat = |z| / 350`, `dep = (x + 1300) / 1000`).
* **QuadEfficiency** (= FinalEfficiency; graph 196 for humans, the difficulty's `7bcf55ee` for the
  AI) picks the quad: 0..0.5 lerps q0 to q1, 0.5..1 lerps q1 to q2. The stick direction is pushed
  to the edge of that quad. So a perfect aimer reaches the lines; a poor one is pulled to the
  middle.
* **In**: the target is pulled back toward the hitter by DeepDeviation (0..310 cm, random) and
  clipped to the court. **Out**: efficiency = OutEfficiency + 1, so the ball lands between the
  lines and q3. Doubles widen the lines quad by the 137 cm alley.

## 7. Outcome and ball flight ([ball-physics.md](ball-physics.md), gp4b)

* `fn_886807C0` rolls Let, then error (`P = FaultProbability`), then Net vs Out
  (`P = OutcomeNet`) **before launch**; Out moves the target 3 cm past the nearest line; In clamps
  it to `x >= 75 cm`.
* The launch solve finds the flight time to the first bounce from the template kind
  (DropTime / BounceSpeed / InitialSpeed / Apogee), quantised to whole frames, and launches so
  that the ball lands exactly on the target. Drag `k = T / 0.06` = 0.67..0.875 /s; spin is a
  constant drift acceleration, not Magnus.
* Typical values (D, ramp reading): serves 141-193 km/h, flat drives about 129-148 km/h,
  topspin/slice 109-128 km/h, volleys 67-109 km/h, smash about 151 km/h.
* Bounce: template-driven reflection with tilt, yaw and speed loss; spin decays. Physics never
  decides in or out. Surfaces do not change ball physics (surfaces.md).

## 8. Movement and swing animation

* **Planner** (gp3 s5, movement-and-ai A, player-and-movement s3): 23 states; regimes Rush,
  JogJogPrepared, JogPrepared chosen from slack-time validity tables `PT+0x270/284/298` (minimum
  distances 400 / 2000 / 175 cm). The speed override `S+0xDE8` comes from `PT+0x34C` (walk when
  early). Candidate hit points are scored by reach cost and data graphs (gp2).
* **RB** (C, OPEN 3.1): sprint sets `RequiredAmplitude = 1.0` while vigor >= 0.1; near the net
  (x > -500 cm) the fast-reposition flag also scales the locomotion by `S+0x39C` = 1.15.
* **Planner windows** (movement-and-ai A.4b): ReadyA when within 8.1 m of the net with more than
  40 frames left; a late Rush re-plan when the stick points back with power > 0.2 under 10
  frames before contact.
* **Planner transitions** (GE2, C; movement-and-ai A.3/A.4c, `mv_next_state`): a replan
  (state 9) or hold (13) follows when the position predicted 20 frames ahead is within 40 cm of
  the stand-point line (`fn_886A9678`). Rush is valid only when the slack (frames left minus the
  preparation table and the lead) is short: under 35 frames at 400 cm. In state 15 a human
  chooses volley or bounce from the nearest ball sample's type, its depth (|x| < 700) and the move
  stick (pushed within the PT+0x1EC angle window = volley); the other candidates become
  unreachable. Steps raises `PT+0x210` to 6 m/s while searching and then writes back **3.0**, not
  the data value.
* **Repositioning** (GE2, [repositioning.md](repositioning.md)): after a shot the player walks to
  a wait point: singles uses graph 116, net (300, hit_z/6) or baseline (1300, -hit_z/12) in the
  opponent's hit frame. A human goes to the net when inside the baseline box or holding RB,
  pushing within 40 deg of the net point, more than 175 cm from it, and with no event under 20
  frames away. The RB sprint only applies during this repositioning action (`0x7653DEC8`), not
  while chasing a ball (`0xA740FF84`).
* **Locomotion clips** (movement-and-animation s2): move-set sectors, transition matrix (314 x
  314) and 128 rules; RushSpeedCoef from Speed and vigor.
* **Swing** (gp7, stats-swing-clipfit): the planner writes the contact target; the clip is chosen
  by geometric fit at the EventRacket annotation and time-scaled to the contact frame (GE2, C: the
  nearest racket point by squared distance among clips whose contact tick lies in the window and
  whose x / z error is inside the box; no weights). Swing
  category rules decide Fatality, spectacular volleys and dives (controls s17, movement-and-animation s3).

## 9. Ratings, skills and fatigue

* **Ratings** 30..100 map to 0..1 stats through DefaultAttributes (graph 23); HandAttributeQuality is
  the Return stat on a return of serve, Volley in volley states, else Forehand or Backhand by side
  (stats-coaches-career s1, OPEN 1.11).
* **Skills**: 30 working skills; 28 act through graph link ports (0/1 multipliers or curve
  switches), three in code (PoisonedSlices, InstantRocket, SpectacularVolleys). None touches the
  ball template directly (traits-and-skills).
* **Vigor** ([timing-and-fatigue.md](timing-and-fatigue.md) s2): during a rally the movement
  load (acceleration above 0.02) and the animation-event costs feed FatigueIngame;
  `CurrentVigor = max(0, 1 - (carried + cost) / (2 x capacity))`. At the end of each point
  `vigor = min(vigor + recovery rate x rest, VigorMax)` with rest 1 / 2 / 3 (I: point / game /
  set). VigorMax = `lerp(lerp(0.5, 0.65, Stamina), 1, ...)`. Vigor feeds the fault graphs,
  movement and swing speed, transitions and the serve window, and **below 0.1 the RB sprint is
  refused** (code `fn_8865E430`; sprint otherwise runs at full amplitude 1.0).

## 10. AI difficulty

The difficulty table `Settings cfg+0xF0` (9 styles x 6 levels, VeryEasy..Expert) gives each
level five behaviour lists (shot, return, serve, repositioning, positioning components), six
graphs (TimingExpression, FinalEfficiency `7bcf55ee`, two hit-point scores, a selection output,
SwingReactionTime) and a run-speed limit of 4..10 m/s (stats-coaches-career s5,
player-and-movement s1). So a harder AI times better, aims closer to the lines, reacts faster and
accepts faster runs; it does not get different physics ([ai-inputs.md](ai-inputs.md) s6). Its reaction delay is the
positioning component `#79b99b60` (frames), its net rushes are random draws on the
repositioning components (net if `U[0, Volley + BaseLine] < Volley`; RushRepositioning gives
its RB), and after its swing it stands still for `#6e33662f` frames (about 16-24). The stop rule
(StopMoving) and the PositioningComponents Volley/BaseLine/InsideOut are inert in retail. In
doubles the wait points are four hard-coded points per team (net 300 cm, baseline 1200 cm, z
±300); the AI takes the half away from its partner, and humans are not moved
([ai-inputs.md](ai-inputs.md) s5b, [repositioning.md](repositioning.md)).

## 11. Rules, crowd and rewards

* **Scoring** (rules-and-scoring): the Standard class implements points, games, deuce, sets and
  tie-breaks (in a tie-break the server changes after points 1, 3, 5, ... and ends change every
  6 points; a quirk makes the next set's first server depend on the tie-break length); other
  formats are mini-game classes. Doubles follows the standard order: the serving team's
  partners alternate on its service games, the receivers alternate point by point and keep their
  courts for the set (rules s4.6). Serve rules: two serves (one with the single-serve option), a
  let is replayed, double fault awards the point.
* **Crowd and rewards** (gp1): each shot earns named rewards that fill an excitement gauge; point-
  end modifiers weight the point (rally length, winner type, importance); the level drives crowd
  audio: `SetExcitement`, `Applause` and `EndOfPoint` events go through a queue to the sound
  dispatcher `fn_8888DD18` (OPEN 6.1). The per-player crowd level 0..1 updates at rally end from
  the average shot quality (`data/gameplay/crowd.yaml`).

## 12. Title Update 1

TU1 (April and May 2011 balancing) retunes four serve graphs, three skills and enables D-pad
movement; its `Settings.bin`/`Expressions.bin` replace the disc copies when installed. It also
loosens a code rule that cancels a sideways push further out from more than 1 m off centre in
the 40 frames after a stamp: TU1 holds it only while the push continues (OPEN 6.5). The
September 2011 changes are not in TU1 (title-update-balance).

## 13. Reference models

Portable C in `ref/gameplay/`, built and tested by `tests/test_gameplay_ref.py`: `rules.c` (with the doubles rotation),
`movement.c` (with the planner window predicates, the full state machine `mv_next_state`, the
replan check, line intersection, mode slack, the Mover average, the state-15 volley choice, the
inside-out test and the `rp_*` repositioning rules) + `ai_driver.c`, `stats.c` + `swing_window.c` + `clip_fit.c`, `player.c`, `ball.c`,
`shot_select.c`, `locomotion.c`, `anim_select.c`, `swing_category.c`, `aim.c`, `timing.c` +
`fatigue.c`.
