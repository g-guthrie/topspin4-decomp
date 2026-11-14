# Retune systems design: grades, timing windows, Tee-off, overcharge and the put-away

Status: design authority for the retune (coordinator, 2026-11-14). The numbers are starting values
to be tuned by `docs/design/retune-spec.md` (simulation) and then by play. Where this note and the
spec disagree on structure, this note wins; where they disagree on a number, the spec's tuned value
wins once it is justified there.

Constraints from the owner: no animation is edited; the aim system stays (direction-only stick,
nested boxes, efficiency); movement stays as retail except the agreed net rules; no new ratings;
the forehand ceiling is 110 mph; everything must run through inputs and outputs the engine already
has, or be a clearly labelled code change.

## 1. Two questions, kept separate

Every shot answers two questions, and they must not be mixed:

| Question | Answered by | Decided when |
|---|---|---|
| How good was the situation? | the **grade** (six rows) | at the swing's commit, from the ball and the player's state |
| How well was it executed? | the **timing value** inside a window | at the release |

The grade picks a row of the shot's power and aim/error ranges (the retail ShotResolution rows,
which exist for VeryGood..VeryBad and are only ever read at Good). Timing picks the position inside
that row's range. So a Perfect on a Bad ball is the best Bad ball, and a late swing on a Tee-off
ball is the worst Tee-off ball. Neither can replace the other.

## 2. The grade

A penalty score, summed from four inputs the engine already computes, then mapped to a row.

| Input | Engine value | Points |
|---|---|---|
| Arrival margin: frames the player has been at the hit point before contact | planner arrival, frames to contact `S+0xCF0` | 30 or more: 0; 15-29: 1; 0-14: 2; still moving at contact: 3; reach or lunge swing: 4 |
| Contact height | hit-point height (`C38`, ball `+0x344`) | waist to shoulder: 0; knee to waist, or shoulder to head: 1; below the knee or above the head: 2 |
| Incoming pace at contact | the fast-ball input `S+0x770`, to be written (code) | slow: -1; normal: 0; heavy: 1; near reflex limits: 2 |
| Self-inflicted | charge state, vigor | rushed power swing (section 5): +1; vigor under 0.3: +1 |

| Score | Grade | Pace cap vs Good | Aim cap vs Good | Error added | Window factor `W_grade` |
|---|---|---|---|---|---|
| -1, and the Tee-off test passes | Tee-off | 1.18 | 1.18 | 0 | 1.30 |
| -1 or 0 | VeryGood | 1.08 | 1.12 | 0 | 1.10 |
| 1-2 | Good | 1.00 | 1.00 | 0 | 1.00 |
| 3 | Normal | 0.93 | 0.82 | +0.03 | 0.95 |
| 4-5 | Bad | 0.82 | 0.59 | +0.08 | 0.90 |
| 6 or more | VeryBad | 0.70 | 0.35 | +0.15 | 0.85 |

Both caps are ratios to the Good row, and the Good row is the retail row unchanged.

Checks on the table:
* A normal rally ball (arrived 15-29 frames early, strike zone, normal pace) scores 1: Good. That is
  retail's only grade, so the middle of the game does not move.
* Volleys use the same table with a volley time scale for the arrival margin (frames since the
  opponent's contact instead of frames set), because nobody is "set" for a second at the net.
* The Tee-off test is all of: incoming pace slow; contact waist to shoulder; 60 or more frames
  since the opponent's contact (the engine's own AutoSwing test, graph 179); arrived 20 or more
  frames early within about 1 m; no reach swing; not moving away from the net.
  Also: the contact point is no more than about 1 m behind the baseline. A slow ball taken from
  deep behind the baseline is VeryGood, not Tee-off (owner question, 2026-11-14: the deep moonball).
* Contact height is measured at the hit point the planner chose, not at the top of the bounce. A
  high-bouncing ball that the player has time and room to let drop is struck in the strike zone and
  scores 0 for height. Height only costs points when the player is forced, or chooses, to take the
  ball high or low: pinned by a heavy kick, taking it early on the rise, or a skidding low ball.

Pace check: a top pace build's full-charge flat forehand is 145 km/h (90 mph) in retail at Good.
Times 1.18 for Tee-off is 106 mph; the overcharge (section 5) adds about 4%: 110 mph, the ceiling.
An ordinary pro (130 km/h, 81 mph at full charge) tops out near 95-99 mph.

Code: one function decides the row today (`fn_886629C8`, always Good, by `S+0x3B4` Power and
`S+0x3B8` Control). The change computes the score there. ShotResolution has five rows at fixed
offsets, so Tee-off is not a sixth data row: it reuses the VeryGood row with a code multiplier
(Q1 engine check, item 3).

## 2a. The grade is not one scale: each shot family is judged on its own terms

Review after the first tuning run (owner, 2026-11-14). Section 2's table was written for a rally
groundstroke and then applied to everything. That was an error: it put every return of a fast serve
in a Bad or VeryBad row, because serve pace is "near reflex limits" on a rally scale, and that was
the main cause of the big server's dominance in the simulation. The same mistake was latent in
other families. The rule from now on: a grade measures how good the situation is *for that kind of
shot*, against what is normal for that kind of shot.

| Family | What "normal" is | Grade inputs | Notes |
|---|---|---|---|
| Rally groundstroke | Set a quarter to half a second early, strike zone, rally pace | Section 2's table as written | |
| Return of serve | Standing ready, little time, high pace: all normal | **No pace or arrival-time points.** Good by default. Bad only when stretched wide or jammed at the body (reach swing). VeryGood on a slow serve in the strike zone, which is how a weak second serve gets attacked. No Tee-off. | Serve pace reaches the returner through the timing window only (`W_react`, and `W_opp` from the server's own timing), and through the Return rating |
| Serve | There is no incoming ball | **No grade.** The serve keeps its own inputs: motion timing, pace chosen, how near the lines, Serve rating, fatigue, and the new fault chance | The overcharge and Tee-off do not exist on serve |
| Volley | Little time is normal; the ball is judged against the net, not the body | Time since the opponent's contact (volley scale); ball height **relative to the net**; incoming pace on a volley scale; stretch | Output is the four outcome bands (weak ball before error), not extra error |
| Smash | The ball is overhead by definition | Time under the ball and whether the player is backpedalling. **No height points.** | Set under a short lob is VeryGood or Tee-off |
| Half-volley and pick-up | Low contact is the whole problem | Height relative to the ground and the Volley rating | Pace capped because the ball must be lifted |

### Shot type changes how much a bad situation costs

The grade table's caps are for a flat drive. Other shot types lose less on a bad grade, which is why
players use them when they are in trouble:

| Shot type | Share of the grade penalty applied | Why |
|---|---|---|
| Flat | 100% | needs timing, balance and a clean strike zone |
| Topspin | 80% | more margin; still needs the legs under it |
| Slice | 50% | the defensive stroke: short swing, works stretched and low |
| Lob | 50% | a touch shot, hit from anywhere |
| Drop shot | 120% on pace-related points | touch off a fast ball is the hardest thing in the game |

The same shares apply to the bonus side in reverse: a flat drive gains the most from VeryGood and
Tee-off, a slice the least. So the reason to hit flat is the top of the grade table, and the reason
to hit slice is the bottom of it.

### What this does to the big server

In real tennis the big serve is very strong and still does not dominate, because holding serve is
not winning: the server also has to break. The targets:

* A serve specialist holds about 90% of service games and breaks about 10-15%; an all-rounder holds
  80-85% and breaks about 20%. Their matches are decided in tie-breaks and come out close to even.
* Levers, in order: (1) returns are no longer pushed into Bad rows by pace (the table above);
  (2) the fault chance rises with pace, so the biggest serves miss more; (3) a second serve is
  slower and can be VeryGood for the returner; (4) maximum effort costs stamina; (5) the Return and
  Reflexes ratings widen the returner's window; (6) standing further back buys reaction time at the
  cost of angle, which the reaction rule already makes real.
* What is deliberately left: free points on a well-timed first serve. That is the style's reward.

## 3. The timing window

Retail: the timing value `t` is 0 at 20 frames before the ball arrives and moves 0.05 per frame.
Perfect is `|t| < 0.1` (2 frames either side). Good is `|t| < 0.3` (6 frames either side). The
automatic commit at 12 frames gives `t` of about +0.4, which is late. One curve for every ball.

The window is changed in one place: the timing value is divided by a window scale `W` where it is
computed (`fn_8867DF68`, which evaluates `t` every frame and freezes it at the commit). Everything
that reads `t` then scales with it: the Perfect and Good bands, the fault graphs' forgiveness and
the aim efficiency curve. No graph has to be re-keyed for the window itself. (An earlier draft drove
the engine's worst/best timing-curve blend instead; that blend takes one scalar from a
single-input graph and lerps t-values, so it cannot carry four factors. Q1 engine check, item 1.)
`W_grade` must be known before the commit; the order of the grade and the commit in code is to be
confirmed.

```
W = clamp( W_rating * W_opp * W_grade * W_react , 0.60 , 1.75 )
Perfect half-width = 2 frames * W        Good half-width = 6 frames * W
```

| Factor | What it is | Values |
|---|---|---|
| `W_rating` | the rating of the stroke being hit (Forehand, Backhand, Volley, Return) | 0.90 at 40, 1.00 at 70, 1.10 at 100 |
| `W_opp` | the timing grade of the opponent's last shot, carried with the ball; its own input, independent of how the ball turned out | Perfect 0.85; Good 0.93; average 1.00; poor 1.15; badly mistimed 1.30 |
| `W_grade` | from the grade table: this is how the ball's own character enters | 0.85 to 1.30 |
| `W_react` | time between the opponent's contact and the player's | 1.00 at 600 ms or more, falling linearly to 0.70 at 250 ms and below |

Worked cases (average rating):

| Case | W | Perfect, frames either side | Good, frames either side |
|---|---|---|---|
| Retail | 1.00 | 2.0 | 6.0 |
| Rally ball, opponent hit Good | 0.93 | 1.9 | 5.6 |
| Opponent hit Perfect, heavy ball (grade Normal) | 0.81 | 1.6 | 4.8 |
| Volley against a clean pass: Perfect, 300 ms, grade Bad | 0.60 (floor) | 1.2 | 3.6 |
| Opponent badly mistimed but the ball came back deep (grade Good) | 1.30 | 2.6 | 7.8 |
| Opponent badly mistimed, sitter (Tee-off) | 1.69 | 3.4 | 10.1 |
| Opponent poor, easy ball (VeryGood) | 1.27 | 2.5 | 7.6 |

The fifth row is the "lucky roll" case: the opponent made a mistake, the dice kept the ball in, and
the receiver still gets an easier Perfect. The direct term exists for exactly that.

The zero-error band keeps its retail size at `W = 1` (19 frames, `t` from -0.6 to +0.45) and scales
with `W` like everything else. It is not tied to the Good band: that would cut the error-free zone
by about 37% on a neutral ball, which is not intended (Q1 engine check, item 4). Aim efficiency
keeps its retail shape against `t`.

Code: compute `W` and divide `t` by it; carry the hitter's timing grade on the ball record.
Incoming pace (`S+0x770`): writing it wakes two dormant retail terms, the fault graphs' fast-ball
penalty (ramp 40-60 km/h, up to -0.6 on control) and the frame-shot chance (graphs 280-282, up to
0.3 from 60 to 100 km/h). Nearly every rally ball is over 60 km/h at contact, so those curves must
be re-keyed in the same change (data) to start near reflex limits, or every shot is penalised.

## 4. What timing buys

Timing picks the position inside the grade's ranges, and it already does so in retail: the power,
aiming and fault graphs read each row's Min and Max with the timing value. That stays, with its
retail shape, which is gentle (a late +0.5 flat power shot still gets about 75% of its peak aim).
So this part is data and needs no new rule. The one change is the depth pull:

| Timing | Depth pull |
|---|---|
| Perfect | 0-40 cm |
| Good | up to 150 cm |
| Outside Good | the retail 2-3 m |

A poor or bad timing also marks the ball: the next receiver's `W_opp` widens, and a slow, short
result usually earns them a better grade as well. That is the knock-on the owner asked for.

## 5. The charge, the rushed swing and the overcharge

Retail: charge counts from the press to the commit; Medium from 12 frames, Powerful from 53, full at
75; holding longer does nothing; a full charge is worth about 4% over Medium.

* **The payoff moves into the grade.** Tier pace steps stay small on Normal and below and grow on
  Good and above, so a power swing is only worth its cost when the situation supports it.
* **Rushed swing.** A swing is rushed when the player is still holding the button at the automatic
  commit and the charge is short of Powerful: they asked for more than the ball allowed. Releasing
  early at a lower tier is never rushed; it is just a smaller swing. Cost of a rushed swing: +1
  grade point, on top of the retail late timing.
* **Overcharge.** Holding at least 10 frames past a full meter (85 frames in all) without moving
  enters the overcharge state. (The first draft used 25 frames; the simulation showed that a
  typical Tee-off ball gives about 98 frames from the opponent's contact, so 25 made the overcharge
  a once-in-70-matches event. At 10 it is about once in 11 matches.) The time requirement is still
  the gate: only a slow ball allows it, and it cannot happen on a return of serve or in a normal
  rally.

| | Full charge | Overcharge |
|---|---|---|
| Pace | the row's cap | cap + 4% |
| Timing window | `W` | `W * 0.80` |
| Outside the Good band | retail error | error doubled, miss goes long |
| Stamina | 25 x power factor | 1.5 times that |

The meter needs a visible state for the overcharge (the HUD meter thresholds are in UI screens not
yet decoded; this is a UI change).

## 6. Tee-off, overcharge and the put-away: how they relate

| Thing | What it is | Who decides |
|---|---|---|
| Tee-off | a grade: the ball is a sitter | the situation (the opponent's weak ball) |
| Overcharge | a commitment: maximum swing | the player |
| Put-away | an animation and, in retail, a fixed reward | retail: a clip that happens to fit |

Retail's put-away fires when a flat power swing finds one of 37 shoulder-height forehand clips. It
pins the power factor (0.85 Medium, 0.80 Powerful) and removes the late-timing aim penalty, so it
is a consistency bonus that ignores the player's ratings, and it is unavailable on low balls,
backhands, topspin and lobs.

In the design the put-away stops being a separate rule. It becomes how the top grades look:

* The reward (pace cap, aim cap, wide window) belongs to the grade. A Tee-off ball gets it whichever
  swing clip fits.
* On Tee-off and VeryGood power swings, the put-away clip set is tried first on every stroke. The
  37 special clips play when they fit. Where they do not (low ball, backhand), existing power-swing
  clips for that height and side are marked eligible and play instead. No clip is edited.
* The retail "no late-timing aim penalty" property is kept for Tee-off only, as part of its
  forgiveness.
* The sprint block in the centre corridor is removed.

The three stack only at the top: Tee-off (situation) + overcharge (commitment) + Perfect (execution)
+ a pace build (ratings) is the 110 mph forehand. Any one missing and it is an ordinary big shot.

## 7. Guard rails

* `W` is clamped to 0.60-1.75, so no chain of Perfects makes a rally unplayable and no sitter makes
  Perfect automatic (3.5 frames either side is still a window).
* The grade is recomputed on every shot; nothing carries over except `W_opp`.
* Tee-off needs a weak ball, so it cannot be farmed by standing still.
* The overcharge needs about two seconds of ball time, so it cannot be spammed.
* A defensive, poorly timed ball is punished twice on purpose (wide window and good grade for the
  receiver); a well-timed defensive ball is punished once at most (the receiver's grade only).

## 8. What needs code, and what is data

| Change | Kind |
|---|---|
| Grade score and row selection | code (`fn_886629C8`) |
| Tee-off as the VeryGood row with a multiplier | code |
| Incoming pace written to `S+0x770` | code |
| Hitter's timing grade carried on the ball | code |
| Window scale `W` computed and applied to the timing value | code (`fn_8867DF68`) |
| Fast-ball and frame-shot curves re-keyed for the live pace input | data |
| Timing picks the position in the row | data (already graph-driven) |
| Depth pull scaled by timing | data (aiming graphs) |
| Rushed swing, overcharge state | code |
| Overcharge meter state | UI |
| Put-away clip eligibility and rule order | data |
| Sprint corridor block removed | code |
