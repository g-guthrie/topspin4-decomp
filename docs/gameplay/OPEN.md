# Gameplay open items (agent GE1)

Every item that a gameplay note marks open, unknown, inferred, M/L/U confidence, or an unnamed
hash, grouped by subsystem. For each one: what would settle it, and the status. Status is one
of **closed** (answer read from code or data, with the note that holds it), **partly** (the
gameplay-relevant part is closed, a detail remains), or **open**. Items are ordered by how much
a player would feel them.

The notes that raised them are cited as `note sN`. "Settle" says what evidence would close the
item. Names that are only missing a crc32 preimage are grouped at the end: they do not change
behaviour.

## 1. Shot request, aim and outcome

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 1.1 | Aim tables and the aim point: how the stick becomes the landing target | controls s8, shot-to-template s4, input-to-shot s5 | read the selector's target method and the tables | **closed** ([aiming.md](aiming.md)): selector vtbl slot 4 `fn_886935A0`, AimingConfig quads chosen by QuadEfficiency, stick direction to the quad edge |
| 1.2 | `S+0xD78` (In depth pull-back) value | ball-physics s14.4, s16 | find its writer | **closed** (aiming.md s4): DeepDeviation, output of each aiming graph, 0..310 cm from DeviationSystem.Random |
| 1.3 | `S+0xD8C/0xD90` Out margin | ball-physics s7, s14.4 | name and writers | **closed**: OutEfficiency (fault graph) and QuadEfficiency (= FinalEfficiency, aiming.md) |
| 1.4 | `fn_88693280/fn_88693040/fn_886935A0/fn_8867D150` described, not ported | ball-physics s14.5 | port | **closed**: `ref/gameplay/aim.c` (`fn_88693280` clip itself is still only described) |
| 1.5 | Consumer of the control-graph list `ShotResolutionSettings.00236a48` | controls s12.6 | find who maps a template row to its EvaluateList entry | **partly**: the entry lives at `SC+0x100` (SC = `PC+0x70`) and is run by `fn_88659AA0` (Element graphs) and `fn_88695C48` (aiming graph `+0x18`, FinalEfficiency); the writer of `SC+0x100` was not located |
| 1.6 | Inside-out geometry: the two side tests of `fn_886AE528 +0x78..+0x3B4`, stick window direction | controls s12.5, s15.4 | transcribe the side tests | open |
| 1.7 | Skill linked to the inside-out bonus (control graphs, SkillList link r67) | controls s12.6, s15.3 | resolve the link port's skill id | open |
| 1.8 | Groundstroke TimingValue `S+0xD08`: computation and early/late asymmetry | controls s12.9 | read the TimingState analyser graphs (BaselineTimingAbility, VolleyTimingAbility, `39cfdeba`) and the code that feeds them | open |
| 1.9 | `ShotSpecific` grade (`S+0x6BC`, copy of `ShotDef[i].9b182896`): copy code and grade selector | graphs-decoded s10 | find the copy | open |
| 1.10 | Writers of `#1407106c` (S+0x770), `#be5d458f` (0x768), `#693eedbe` (0x7D8), `#aee2d90b` (0x7D0), `#3c6beee9` (S+0xD84) | graphs-decoded s10 | store scan by offset off `S` | open |
| 1.11 | `HandAttributeQuality` (S+0x74C) exact rule | graphs-decoded s10 | read the stores in `fn_88699xxx`, `fn_886BA254`, `fn_886BD4F0` | open |
| 1.12 | LetProbability input `#fea37f2e` | brief | find the bound field and its writer | open |
| 1.13 | `b50/b51` meaning, gate `G` bytes `match+0x328/0x329`, `DebugConfig+0x784` | gp4b s10, ball-physics s8 | transcribed by G3b; names of the match bytes | partly (formula C, names U) |
| 1.14 | Risk hold value `S+0xE08` reader (TU1 xexp?) | controls s12.7 | scan the TU1 code delta | open |
| 1.15 | Risky rows reachable only by the debug override | controls s6.1 | closed by G2b | closed |
| 1.16 | AimingConfig flag `5ed23100` (+0x94, true on serve configs) | aiming s5 | whole-module reader search | open |

## 2. Ball flight and bounce

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 2.1 | Curves step or ramp | ball-physics s14.1, analyser-graphs | load-time fixup | **closed** by G1 (ramps; graphs-decoded s2). ball-physics s11 values are STEP readings with RAMP in brackets |
| 2.2 | Serve sub-record `row+0x10` and stroke ranges `row+0x14` readers | ball-physics s14.2, shot-templates s8.1 | reader search | partly: no reader found by G3b (likely unused) |
| 2.3 | Live ball keeps the State.bin image `+0x4C0..0x4E1`; net height | ball-physics s14.3, gp4 s5 | runtime dump (Xenia) | open (needs a runtime) |
| 2.4 | Bounce rotation: the unclamped tilt weight `|5 spin_a|`, `1 - c40` speed factor, yaw kick | ball-physics s14.6, shot-templates s8.5 | runtime bounce dump, or a matched `fn_889C1C80` | open (code read H; physics meaning M) |
| 2.5 | Kind routines `fn_888AC748/ACA68/ACDA8` only characterised | gp4 s5 | transcribe | partly (ported via the golden-vector reference of gp4b) |
| 2.6 | Command `f4C` and spin blend distribution (S+0x778, S+0x774) | shot-templates s8.3 | evaluate the power graphs 198/238-273 | partly: both are graph outputs (ball-physics s16) |
| 2.7 | Net hit-test polarity | gp4 s5 | runtime | open |

## 3. Movement and animation

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 3.1 | How sprint (RB) reaches the locomotion keys | movement-and-animation s5.7 | follow `@Rush` S+0x4DD (`fn_8865E430`), `@ReqFastRepos` S+0x4E2 (`fn_8868C218`, `fn_8869B928`) into the planner and AnimationSelection | open |
| 3.2 | About 12 movement predicates and exit conditions of planner states 10-18 (L/I) | gp3 s9, movement-and-ai A.3/D | transcribe `fn_886A9678`, `fn_886877A8`, `fn_8869A4D0`, `fn_886A58F0`, `fn_886A26E0`, `fn_886A33C0`, `fn_88678548`, `fn_886A2BE8`, `fn_8865DBA8`, `fn_88699FC0`, `fn_88688948`, `fn_886887C0` | open (some V in movement-and-ai A.4) |
| 3.3 | Sector angle rounding, Back look-side rule, blend curve, root-motion mirroring, retarget angle tests | movement-and-animation s5.6 | read the locomotion selector and `fn_886D3AD8` | open (I) |
| 3.4 | Vivacity source of the transition speed | movement-and-animation s5.6 | graph binding of Vivacity (graph 14) to the transition lerp | open |
| 3.5 | Power/Control "VeryGood" swing keys never set by code, yet the 74 Fatality clips ask for VeryGood | movement-and-animation s5.1, s6.1 | does the swing query read `S+0x3B4/0x3B8` at all | open |
| 3.6 | Who reads the clip Tolerancy arrays | movement-and-animation s5.3 | reader of the record's Tolerancy offsets | open |
| 3.7 | TimingState field names `S+0xCF0` (3fe3a099), `S+0xD00` (1490306b) | movement-and-animation s5.5 | crc preimage | partly: meanings known (frames to contact; ball speed km/h), names U; see s9 |
| 3.8 | ReceiverState fields `S+0xC28/0xC2C/0xC38` | brief | names and writers | partly: they are `ReceiverState.c7b7bdac.#8760acf5 / #420a6cfc / #2f6930a4` (hit-point block next to BallDifficulty, ShotDifficulty, Spin; `ps_layout.py`); writers not traced |
| 3.9 | Reach/lunge, wait positions after a shot (second hashed machine, base profile `cfg+0x1F8`) | movement-and-ai A.5 | decode | open |
| 3.10 | `SpectacularVolleys` flag S+0x388 reader | traits-and-skills s5 | closed by G6b: the swing category condition VolleySpectacular | closed |
| 3.11 | PlayerController vtable slot 21 caller (`fn_886B4B80`) | player-and-movement s9.1 | indirect-call trace | open |
| 3.12 | PT+0x31C/0x32C/0x33C/0x37C and PT+0x450..0x5D3 readers | player-and-movement s9.4 | scan with other bases | open |
| 3.13 | Clip-fit cost terms and weights (`fn_886D3AD8`) | stats-swing-clipfit s4 | VMX read | partly (structure V, G4b) |

## 4. AI

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 4.1 | How the AI turns ShotComponents and ServeComponents into inputs | controls s10, movement-and-ai B.2 | read the AI decision functions | **closed** ([ai-inputs.md](ai-inputs.md)): weighted random draws into ShotTriggers, Stick_Aiming, Risk, FollowToNet, power |
| 4.2 | RepositioningComponents / PositioningComponents consumers | analyser-graphs s6.5 | same method as 4.1 | open |
| 4.3 | Names of AI style groups `824ec12e`, `75c6d60c`, `PositioningComponents.#79b99b60`, expression keys `bfc9cc2c`, `2836a60f` | player-and-movement s9.3, stats-coaches-career s6 | crc preimage | open (name only) |

## 5. Fatigue, skills, stats

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 5.1 | Vigor integration `S+0xF64` | brief | read the fatigue update (`fn_886BC1E0`, `fn_886BBC38`) | open |
| 5.2 | Flammable counter `((world+0x50)+0x4C)[team].+0x30` incrementer | player-and-movement s9.5 | find the store | open |
| 5.3 | MatchAnalyser trigger names (`b6b22409`, ...) | traits-and-skills s5 | crc | open (name only; writers known, G4c) |
| 5.4 | Graph 22 for players 1-3; readers of ServePrecision/ServePower | graphs-decoded s10 | code read | open |
| 5.5 | Created player to `PlayerList` row; coach bonuses added when | player-and-movement s9.2 | career Lua | open (outside Swing) |

## 6. Rules, crowd, match flow

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 6.1 | Where crowd excitement and applause level are computed (upstream of `fn_8888DD18`) | brief, gp1 | trace the callers of `fn_8888DD18` | open |
| 6.2 | Doubles: rotation arithmetic, serve order, positioning | rules-and-scoring s7, brief | read `0x88674ED0`, `0x88674D58`, the doubles AI | open (aim widening closed in aiming.md) |
| 6.3 | Rally judge `fn_886A84C0` skimmed | rules-and-scoring s7 | transcribe | open |
| 6.4 | Initial server choice | rules-and-scoring s7 | find a toss step | open |
| 6.5 | TU1 `RepositioningSettings/29eac4a0` flag and `fn_886795C8` | title-update-balance s6.2 | read `fn_886795C8` and its TU1 form | open |

## 7. Data formats and infrastructure

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 7.1 | XBin signature check and archive first-match rule (TU precedence) | title-update-balance s6.1 | read the loader | open |
| 7.2 | 0x8C animation record fields beyond the known ones | df s8.2 | correlate with names | partly (G6 decoded the qualifier masks) |
| 7.3 | InputMapper `+0x18/+0x24` gesture blocks, root floats 0.55/0.8 | controls s12.8 | reader search (PS Move code) | open (no gameplay effect for a pad) |
| 7.4 | Polar stick angle +0.5 offset | controls s12.10 | runtime | open |
| 7.5 | `Expressions.bin` in TU1 does not parse ("unexpected signature") | controls s16 | fix the parser or diff the bytes | open |
| 7.6 | `fn_889B4C10` second Expressions module | graphs-decoded s10 | none on disc | closed (I: dead path) |

## 8. State machines and conditions (behaviour known, names missing)

| hash | where | meaning (C) |
|---|---|---|
| `0xAFAF1093` | `fn_886B3CF8` request state | waiting for a shot press |
| `0x658B2E11` | same | swing running, waiting for the 12-frame trigger or the release |
| `0xF6EB6636` | same | committed on an early release |
| `0xA1903341` | same | planner has run (shot chosen) |
| `0x93E5E96D` | same | auto-swing evaluation (volley/baseline analysers) |
| `693616c3`, `60d5b606`, `de050fd0`, `42864090`, `4041760a` | `fn_88697E98` swing-category conditions | min line speed > 3.5 / > 4.5 m/s, with or without the timing window (controls s17.2) |
| `0x280AE84D` | `fn_88662C08` | out grade beyond OutFar |
| `0x959A9407` | animation slot kind | play slot (EOP) |

## 9. Names only (crc32 preimages not found; behaviour documented)

TimingState `c11ed16a`, `3fe3a099` (frames to contact), `d2797eb6` (depth difference),
`02583288` (press-to-launch frames), `18d5f130`, `1490306b` (ball speed km/h), `0eaa0333`
(auto-swing good); hit-point block `c7b7bdac` members `2c63ee31`, `8760acf5`, `420a6cfc`,
`2f6930a4`, `e00ec629`; `#1407106c`, `#03d2be3d`, `#5cf9de02`, `#07902e50`, `#7bb6a318`,
`#8ea88f9f`, `#6906754b`, `#7afa6edb`; about 290 graph names; the 11 kernel type names; the
unresolved PlayerTuning words `baaa713d`, `32b6d5c1`, `8946f070`. A 1-3 word search over 190
gameplay words (GE1, `crc32`) found none of them; the G5b/G4c searches are wider.

## 10. Progress log

* GE1, 2026-11-14: closed 1.1-1.4 (aiming), 4.1 (AI inputs); partly 1.5, 3.7, 3.8. New tool
  `tools/ts4data/ps_layout.py` prints any reflected type with absolute offsets and names.
