# Repositioning: where players go between shots (agent GE2)

This note covers what a player does after the ball leaves the opponent's racket and before the
movement planner (movement-and-ai A) takes over to chase it. Here "repositioning" means the
recovery run: to the net or the baseline in singles, and into one of four court points in doubles.
It closes OPEN 3.1 (sprint), 4.2 (Volley/BaseLine/InsideOut components and `#6e33662f`) and 6.2
(doubles positioning), and answers most of 3.9 (wait positions).

Grades: **C** = read from code (`Swing_DLL.dll`, `tools/fn_asm.py` and capstone), **D** = read
from data, **I** = inferred. `S` = PlayerState, `R` = the repositioning controller (the object
`fn_886BB0A8` is called with; `R+0x1C` = PlayerCtx), `team` = `ctx+0x4C` (the player's own team,
C: `fn_8866D368(team)` returns a player of the *other* team). Values are dumped by
`python3 -I tools/ts4data/repositioning.py` to `data/gameplay/repositioning.yaml` (with the sha256
of the DLL and of Settings.bin). The reference model is in `ref/gameplay/movement.c` (`rp_*`).
Court tags: `0x317C51B7` = near side (negative world x), `0xA2EDA1E7` = far side (C:
`fn_8865EC70` mirrors x and z for the far tag).

## 1. Who runs what (fn_886BB0A8, every frame, C)

1. Bookkeeping: the TU1 push rule `fn_886795C8` (OPEN 6.5) and the vigor clamp of `anim+0x410`.
2. If Settings `/6b31c8f4` (cfg+0xAA8, false on disc) is set, the player is left alone (`fn_8865E490`).
3. If the play mode `(world+0x78)+0 == 1`: `fn_8868C090` (fixed points) + `fn_8869B928` +
   `fn_88679518`. This is the human path, used here for every player (I: mode 1 is a practice or
   menu mode).
4. Otherwise, if the own team is not the team in possession (`team+0x28 != clock+0x7C`) and the
   opponent who will hit (`fn_8866D368`) has frames to its hit point (`S'+0xC24`) > 0, then the
   player is recovering after his shot:
   * **doubles** (`team+0x2C == 2`): human: `fn_8866CBE0` + `fn_8865E490`; AI: `fn_886A4260` +
     `fn_886A3DF0`;
   * **singles**: `fn_8868C090` (targets), then human: `fn_8869B928` + `fn_88679518`, AI:
     `fn_886BADA0` + `fn_886A3DF0`. Then `S+0xA18` (`RePositioningState.#9d2b062e`) counts the
     frames in which the player's z lies within `[min(c, 0) - 50, max(c, 0) + 50]` (`c = R+0x38`).
5. If the own team is in possession and it is doubles: the four team points are written once
   (section 4), then human: `fn_8866CBE0` + `fn_8865E490`, AI: `fn_886A40A8` + `fn_886A3C98`.
6. Tail: sprint update `fn_8865E430` (section 5), a forced stop when `AnimationSelection.Movement.SplitSteps`
   (S+0x390) becomes `0x4DAA7349`, and the AI post-swing hold (section 3.3).

`R+0x40` is the **repositioning mode**: 0 none, 1 baseline, 2 net (singles), 3..6 doubles points.
**`S+0xA2D` (`RePositioningState.#f7b180d0`) = "a repositioning mode is active"** (written as
`R+0x40 != 0` by `fn_8869B928`, `fn_8866CBE0`, and set to 1 by the AI deciders, C). This answers
the `S+0xA2D` question of OPEN 3.1. `S+0xA2E` (`#69e79f9d`) = "arrived" (section 3.2).

## 2. Singles targets (fn_8868C090, C + D)

Once per opponent shot (`team+0x1A3` latch) the graph `R+0x5C` = **graph 116
`RepositioningPointSingle`** runs. It reads the opponent's `ReceiverState.#c7b7bdac.HitPositionLocal.z`
and writes (D, `data/gameplay/graphs.yaml`):

| output | value | used as |
|---|---|---|
| `RePositioningState.#00fb8872` (S+0xA24), `#eef5e95e` (S+0xA28) | x = **300**, z = `hit_z / 6` (clamped to ±100 at ±600) | net point `R+0x20` |
| `#ed59542a` (S+0xA1C), `#03573506` (S+0xA20) | x = **1300**, z = `-hit_z / 12` (±50) | baseline point `R+0x30` |

Both points are mirrored by the opponent's court tag (`fn_8865E730`), so they land on the player's
own half: 3 m and 13 m from the net. The net point follows the side the opponent hits from; the
baseline point leans slightly the other way (I: covering the cross-court angle). In play mode 1 the
points are fixed by Settings: baseline x = `RepositioningPointSettings/2c987b2e` = 1300 and net
x = `/00fb8872` = 300, z = 0 (cfg+0xA40/0xA44, file 0xA64/0xA68).

## 3. Singles decisions

### 3.1 Human: fn_8869B928 (C)

With `LocalPosition` (x toward the net is positive, own side negative) and the move stick:

* **at the net already**: x > -`RepositioningPointSettings/8154a27b` (500 cm) -> mode 0;
* **stick released**: `#b21d6f76.Power` (S+0x9DC) < 0.1 -> mode 0;
* otherwise **mode 2 (go to the net)** when the move stick angle `Stick_MovePolar.Angle` (S+0x444)
  is within **40 deg** (`/324f5246`) of the direction to the net point and the net point is more
  than **175 cm** (`/0081913b`) away, **and** either the player stands in the baseline box
  `bad7533a` (-1100 < x < -700, -400 < z < 400) outside play mode 1, or **RB** (`@ReqFastRepos`,
  S+0x4E2) is held;
* a new mode 2 is refused while a pending match event (`fn_8865EF98`, I: the opponent's planned
  hit) is fewer than **20 frames** (`/98294782`) away.

So **from behind the baseline, pushing the stick toward the net starts the net rush on its own;
from mid-court it needs RB** (C). `fn_88679518` then overrides the move direction `#b21d6f76.LocalDirection`
(S+0x9D8) with the heading to the net point (`-angle` on the near court, `pi - angle` on the far
court) while mode 2 lasts.

`fn_8868C218(R, mode)` (called by both singles deciders): the locomotion scale `anim+0x41C` = 1.0,
or, at the net (x > -500) with RB, graph `R+0x128` runs and `anim+0x41C = S+0x39C`
(`AnimationSelection.Movement.#98bb2ce3`, VolleySpeedCoef 1.15; OPEN 3.1, GE1). Behind -500 the
behaviour is 2 for mode 2 and 0 otherwise; at the net it is 0. When the behaviour changes, at most
once every **5 frames** (`/7440a9da`), it raises one `BehaviorTransitionState` flag: 0 ->
`#65e3cf11` (S+0xFA0), 1 -> `#7582f708` (S+0xFA1), 2 -> **`Rush`** (S+0xFBD). That flag drives the
animation behaviour graph (BehaviorSettings).

### 3.2 AI: fn_886BADA0 + fn_886A3DF0 (C + D)

Once per opponent shot (`S+0xA2D` latch):

1. `frames` = ticks until the opponent's planned hit sample (min 1); the AI record gets
   `#a9a83d2d.#98396fb5` (+0x1A4) = |net point - position| / frames x 0.6 and `#e0dd212e` (+0x1A8)
   = the same for the baseline point, i.e. **the run speeds in m/s needed to reach each point
   before the opponent hits**.
2. The repositioning graphs (117..137 by style and level) evaluate; their outputs are copied to
   `FinalRepositioningComponents` (+0x1E0..+0x1F8).
3. **Draw**: `r = U[0, Volley + BaseLine]`; `0 < r < Volley` -> mode 2 (net); `Volley < r <
   Volley + BaseLine` -> mode 1 (baseline). (Corrects ai-inputs s5b, which compared U[0,1] with
   Volley alone: BaseLine is the second weight.) `S+0x9DC` = 1.0.
4. `@ReqFastRepos = U[0,1] < RushRepositioning` (the AI's RB).

Graph 117 (D) is typical: Volley rises when the net point is at least about 4 m/s easier to reach
than the baseline point (`curve9(#98396fb5 - #e0dd212e)`), when the AI decided to follow its shot
to the net (`#9be5b94e`, +0x1AC), and, randomly, when it stands near the centre.

`fn_886A3DF0` executes the mode every frame: target = `R+0x30` (mode 1), `R+0x20` (2), or a doubles
point (3 `team+0x180`, 4 `+0x160`, 5 `+0x190`, 6 `+0x170`), mirrored to the local frame. It sets
`MoveState.MoveMode` (S+0x9FC) to `0x487570E4` (walk to `MoveGoal` = target) until the target is
within **175 cm** (`/0081913b`). Then it sets `0x8999A0BF` and `S+0xA2E = 1` (arrived, re-armed when the mode changes).

**Stop rule** (singles): `MoveMode = 0x9E51242B` (stand, zero vector), mode 0, when
(`Final.#2b4b4baa < 0.5` or `Final.StopMoving > 0.5`) and the opponent's frames to hit <
`Final.#2ac5965a`. Every repositioning graph outputs `#2b4b4baa = 1`, `StopMoving = 0` and
`#2ac5965a = 0` (D), so **the stop rule never fires in retail** (C + D; ai-inputs s5b had the
first test the wrong way round).

### 3.3 AI post-swing hold: #6e33662f (C + D)

In the tail of `fn_886BB0A8`, for an AI player (in doubles only the team's slot `team+0x30`),
`n = int(Final.#6e33662f)`. While the swing animation runs and no stamp is set (`R+0x170 == -1`), the
move power `S+0x9DC` is zeroed. When the swing ends the stamp is set to the current frame, and the
power stays zero for **n more frames**. So **`#6e33662f` is the AI's recovery delay after its
swing**. Graph 117 gives `0.8 x lerp(30 -> 20, 25 -> 20 by vigor, by Return)` = about 16-24 frames
(x 1.0 beyond |x| 1000 cm) (D).

### 3.4 Positioning components Volley, BaseLine, InsideOut (C scan + D)

`PositioningComponents.Volley/BaseLine/InsideOut` (AI record +0xCC..+0xD4, Final +0x1D0..+0x1D8)
are written by the positioning graphs 141-155 (D). No instruction in the gameplay window
(0x88600000-0x88720000) loads +0x1D0/+0x1D4/+0x1D8 from anything but the constant pools, no
`addi` forms those addresses, and no graph takes them as input (C scan). I: they are dead in retail.
Only `#79b99b60` (+0x1DC) is used, as the reaction delay (movement-and-ai A.7).

## 4. Doubles (C, code constants)

The four team points are **hard-coded** in `.rdata` and written to `team+0x160..+0x190` by
`fn_886BB0A8` when `team+0x1A3` is clear (values in `data/gameplay/repositioning.yaml`):

| slot | near team (x < 0) | far team | mode |
|---|---|---|---|
| `team+0x160` | (-300, 300) | (300, -300) | 4 net |
| `team+0x170` | (-300, -300) | (300, 300) | 6 net |
| `team+0x180` | (-1200, 300) | (1200, -300) | 3 baseline |
| `team+0x190` | (-1200, -300) | (1200, 300) | 5 baseline |

So a doubles player recovers to 3 m or 12 m from the net, 3 m either side of the centre line
(modes 3/4 one half, 5/6 the other, the same half from each team's own view).

* **AI, opponent about to hit (`fn_886A4260`)**: the half is the one **away from the partner**.
  With a human partner it compares the partner's local z with 0 (`z > 0` -> points `+0x170/+0x190`);
  with an AI partner it compares the two players' local z, once per point (`S+0xA2D` latch). The
  required speeds to the net and baseline point of that half go to the AI record (+0x1A4/+0x1A8)
  and the same Volley/BaseLine draw picks the depth: mode 6/4 (net) or 5/3 (baseline). With a
  human partner it also draws `@ReqFastRepos` from RushRepositioning; with an AI partner it does not.
* **AI, own team in possession (`fn_886A40A8`)**: keep the depth, switch to the half away from
  the partner (3 <-> 5, 4 <-> 6); with no mode yet, choose baseline when the AI's local x is below
  **-900** cm, else net. `fn_886A3C98` then walks to the point.
* **Humans** are not moved: `fn_8866CBE0` sets mode = the strictly nearest of the four points
  (4/6/3/5) and `S+0xA2D`, then `fn_8865E490` clears the mode again (and raises behaviour 0 after
  5 frames).

`DoubleSettings` (file 0xC24..0xC54: `HumanHuman`, `c11474f9`, `33f3601a` triples, `ReachBall`)
and `/AISettings/52945bdd/Double` have **no code reader** found: no load at cfg+0xC00..+0xC30
through the cfg pointer in the window, and no hit in the whole-.text `xref_fields.py` scan
(`work/disc/values/xref_settings.json`; its hit 0x886B11BC for `/Double/9671f02c` is a destructor,
a false positive) (C scan, I: unused in retail).

## 5. Sprint and the move-speed query (C + D)

`fn_8866FB60` (move speed query) switches on the **action type** of the current amplitude
config (`AmplitudeConfigList`, Settings file 0x30C68.., field `19259749`; D). GE1 wrote the hashes
with a sign-extension slip; the instructions are `lis 0xA740; ori 0xFF84` and `lis 0x7653; ori 0xDEC8`:

| hash | name (crc32) | speed returned |
|---|---|---|
| `0xA740FF84` | `ActionReceiver` | planner speed override `S+0xDE8` / valid `S+0xDEC` |
| `0x7653DEC8` | `ActionRepositioning` | `RequiredAmplitude` S+0xA10 (= 1.0) and the sprint flag `S+0xA2C` |
| `0x77579282` | (unnamed; the `ReturnServe` config) | `Mover+0x34` |

So **the RB sprint (`S+0xA2C = Rush && vigor >= 0.1`, GE1) only acts during repositioning runs**,
not while the planner chases a ball (`ActionReceiver` takes the planner's own speed). In the
locomotion request `fn_886BEEE8` also picks `Mover+0x2C` instead of `+0x28` for an
`ActionRepositioning` move without an active mode (`S+0xA2D` clear). That value is stored with
the speed in the locomotion request ring (I: a blend time).

`ctx+0x5C` is the **Mover** (ctor 0x8866CFA8, update `fn_8866CDC8`): `+0x10` PlayerCtx, `+0x14` ->
`S+0x9A0` (MoveState), `+0x20` last position, `+0x50` = smoothed velocity and `+0x68` = smoothed
speed, both in m/s (cm/frame x 0.6). The smoothing is a running mean with time constant 0.6 x 5 = 3 frames
(`sum = sum - mean + x; mean = sum / 3`). `fn_8869C010` turns `MoveMode` (S+0x9FC) into the move
vector.

## 6. Open

* Names of `MoveMode` hashes `0x487570E4` / `0x8999A0BF` / `0x9E51242B` and of action `0x77579282`,
  `0xA396BE25` (a 1-3 word search over 4000 gameplay words found none).
* Play mode `(world+0x78)+0` values 1/2 (I: practice / match).
* Runtime check R12 (OPEN s11) now only confirms the action hash in a match.
