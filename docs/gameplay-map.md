# Top Spin 4 (Xbox 360) gameplay map

Status: static analysis only, nothing here is a reconstructed function.
Per AGENTS.md, a function is reconstructed only after it is named, typed,
reviewed and validated; this document is the planning map that precedes that.
Every address is a Swing_DLL.xex virtual address (module sha256
`dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`, see
`config/54540859/match.json`).

Confidence labels: **high** = a string or a direct call chain pins it,
**medium** = strong neighbourhood or structural evidence, **low** = a guess
from address layout. Sizes in the tables are function counts / bytes taken from
`config/54540859/symbols.txt` (sha256 `ec79e191...9d5e`, 7,552,839 bytes).

## 0. Big picture

* The title is built on an in-house engine whose namespaces are `Pam::*`
  (`Pam::Swing::CSwing`, `Pam::System::...`, `Pam::Net::...`) plus "CoreTech".
  State is exchanged through an XPath-addressed tree ("XData") with named
  roots: `GamePlayInterface:/SwingGameplayInterface/GameplayInputs|GameplayOutputs`,
  `GamePlayState:/SwingData/State/...`, `FrameSynchroData:/FrameSynchro/Frame[n]/...`,
  `AnimationData:/SwingAnimation/...`, `GameDB:/GameDB/...`,
  `SystemData:/SystemData/Scheduler/...`.
* Gameplay is a set of scheduler **modules** (`CSwingGamePlay`, `CSwingAnimation`,
  `CAnimation`, `CAnimationEvolution`, `CPhysicEngine`, `CGameLogic`,
  `CAnalyserFramework`, `CInputMapper`, `CPositionningSynchro`,
  `CPhysicEventSynchro`, `CGameFrameSynchro`, `CMultiBallManager`,
  `CPlayersCollisions`, ...). Their names are registered by `fn_888DB320`
  (95 registrations, address 0x888DB320, size 0xC90).
* The gameplay code is **sparse in strings and almost free of float constants**
  (section 3). Game rules/tuning are data driven. Expect the decompilation to be
  structural glue plus VMX128 vector math, with the numbers in data files.
* Havok Physics/Animation (hk*), FMOD, an XDK shader compiler, Lua 5.x, zlib/png,
  Bink are middleware. Not mapped further than their address ranges (section 6).

## 1. Subsystem address ranges

### 1.1 Module-level layout of .text (0x88150008 - 0x88AFF800, 42,984 `fn_` + named symbols)

| Range | Contents | Fns | Bytes | Conf |
|---|---|---|---|---|
| 0x88150000-0x88240000 | XData accessors/serialisers, loaders, RUI/UI node classes (`__Server`, `basic_string`) | ~4,550 | ~0.9 MB | medium |
| 0x88260000-0x88290000 | `fa_factory_thunks.obj`: per-class factory/dtor thunks (`ts4_factory_*`) | many tiny | | high (symbol names) |
| 0x882A0000-0x88300000 | PIX/xbmovie, image libs (png/zlib/jpeg strings) | | | medium |
| 0x88300000-0x88400000 | FMOD (`..\src\fmod_*.cpp` path strings) | 3,607 | 1,056,432 | high |
| 0x88400000-0x88440000 | Havok Animation (`hka*`) | 1,481 | 259,028 | high |
| 0x88440000-0x88560000 | Havok Physics (`hkp*`, Mopp) | 4,415 | 1,180,504 | high |
| 0x88560000-0x88600000 | MS CRT + XDK graphics ucode compiler (0x885DC000+) | 3,433 | 650,656 | high |
| 0x88600000-0x88640000 | Pam core: XData server/pool, heap (`HeapChunk/List/Stack.cpp`), `CModuleManager`, threads | 1,883 | 258,688 | high |
| **0x88640000-0x886E8000** | **Swing gameplay module + animation glue (this document's main target)** | **2,549** | **682,956** | medium |
| 0x886E8000-0x88780000 | `Pam Display` renderer (HierarchyProcessor, materials, shadows, post-fx) | 1,974 | 618,464 | high |
| 0x88780000-0x88800000 | PlayerCreator, UI/RUI, season/online Lua bindings (`tsu_*`) | 1,854 | 521,004 | medium |
| 0x88800000-0x88838000 | Lua VM + `CScriptEngine`/`CScriptServerLua` | 1,070 | 229,124 | high |
| 0x88838000-0x88870000 | game-flow DB: season, profiles, tournament | 874 | 227,628 | medium |
| 0x88870000-0x88878000 | zlib inflate + IO | 114 | 33,136 | high |
| **0x88878000-0x88882000** | **PhysicEngine wrapper over Havok (world, ball, event queue)** | 159 | 40,784 | high |
| 0x88882000-0x8888A000 | PamThread, file IO, `CPaddleDriver` | 225 | 32,264 | high |
| **0x8888A000-0x88890000** | **ball/net/umpire/crowd sound events** | 46 | 24,264 | high |
| 0x88890000-0x888B0000 | `CSoundSwing`, misc | 712 | 141,508 | low |
| 0x888B0000-0x888C0000 | `CCameraEngine`/CShot | 202 | 64,972 | medium |
| 0x888C0000-0x888E0000 | module-registration stubs (`ts4_keyed_item_list_add_unique_*`), `CPlayersCollisions`, `CMultiBallManager`, minigames | 699 | 129,868 | medium |
| 0x888E0000-0x88900000 | XData publishers (PlayerStates, GamePlayInterface, `Global.bin` loaders) | 256 | 130,524 | medium |
| 0x88900000-0x889C0000 | net/lobby, PlayerCreator, `CScheduler` (0x88954210), `CoreTech_Xenon.bin` loader (0x889BD370) | | | medium |
| 0x889C0000-0x88B00000 | Havok reflection/class-registration tables (11,948 tiny fns, 1.29 MB) | 11,948 | 1,289,108 | high |

### 1.2 Sub-ranges of the gameplay module (0x88640000-0x886E8000)

These are anchored at the listed evidence points; the boundaries between
anchors are neighbourhood estimates (laid out roughly by source file) and
should be treated as **low** until call-graph work confirms them.
Of the 2,549 functions, 857 are <=64 bytes (XData accessor/vtable stubs) and
only 143 are >=1000 bytes.

| Range | Fns | Bytes | Role | Evidence | Conf |
|---|---|---|---|---|---|
| 0x88640000-0x88650000 | 322 | 64,924 | Animation/bone glue: bone-name table (`B_Racket_Handle`, `B_Spine*`, `B_Head`; fn_88648998 1712 B, fn_88645200), `PlayerAnimData:/AnimationInterface/AnimDataList` (fn_8864A1E0/8348), `Play %d at @%.2f Weight %.2f` (fn_88644990), `CAnimationEvolution` registration fn_88649138; 25 fns call Havok Animation | strings, `hka` callers | high |
| 0x88650000-0x88658000 | 136 | 32,124 | math/curve utilities: `CMath` registration fn_88652918, `CInterpolatorLinear/Constant/Bezier/Composite_{Float,C3DVector,Vector4D}` (fn_886529C8, fn_88652A90), `UserProperties/Property[@Name=` (fn_88654760) | strings | medium |
| 0x88658000-0x8865A000 | 196 | 7,688 | `CDataMining` telemetry (`Events.xml`, `Datamining.bin`; reg fn_88658008) | strings | high |
| 0x8865A000-0x88680000 | 748 | 155,544 | vtable-slot accessor stubs plus: **shot-quality scoring fn_8865B780**, input-state debug fn_886630B8, in/out/net stats fn_88661D58, crowd excitement fn_88666F18/fn_88674E00, **shot efficiencies fn_886674E8** | strings | high (anchors) / low (rest) |
| 0x88680000-0x88694000 | 202 | 79,968 | XData node-type registration (`CSwingGamePlay` Init fn_8869C9E8 registers 30 hashed node types through `ts4_keyed_item_list_add_unique_if_mode_*` at 0x886810C0-0x8868D298 and 0x88690208-0x88693E28), **point-end/rally evaluation fn_88685060 (4272 B)**, movement validity `[Rush]/[JogPrepared]/[JogJogPrepared]` fn_88688948, crowd reaction fn_8868E370 | strings, call chain | high (anchors) |
| 0x88694000-0x886B4000 | 273 | 132,608 | movement requirement + interception + swing candidate scoring: `RequiredSpeed/Distance` fn_88699FC0, **`InputNotation/Selection Score/Ball Difficulty/Reachability` fn_886AC2C8**; fn_886AE528 (5964 B, 97 calls) | strings, call chain | medium |
| 0x886B4000-0x886C8000 | 275 | 79,704 | TopSpin School exercise logic (`End of exercice` fn_886B3490), a very large dispatcher fn_886B8468 (8960 B, 187 calls; contains 39 prologue-helper calls, so it likely aggregates many functions - check symbol size before assuming one function), debug camera/HUD (fn_886C0568 `GamePlayTool/Cam...`), input and heap recorders (`Input.rec` fn_886BC568, `GamePlayHeapP/V/AOD/Patch_%d.rec` fn_886C27F8) | strings | medium |
| 0x886C8000-0x886E8000 | 397 | 130,396 | swing animation: AOD clip loaders `Media\Animation\AOD\%u.hkx` (fn_886CE2D8, fn_886D2B58), `CSwingAnimation` reg fn_886D2838, `SwingAnimationEngine(Controller)` fn_886D75B8, animation stats (`Animation_Statistics.xml`, `Occurency.sql` fn_886DA840/DADB8), `/SwingAnimation/States/InstanceState[1]` fn_886DC2C8, `ToDisplay/Position|Rotation` fn_886E31F0, `SbikAnimationDB:/` fn_886E3A00, `CClothProcessor` at ~0x886E8448 | strings | high (anchors) |

Other gameplay-related islands outside that range:

| Range | Role | Evidence | Conf |
|---|---|---|---|
| 0x88724FF0, 0x887911B8, 0x887928A8, 0x88790DA0, 0x88798E68, 0x888B9D50, 0x888E00D8, 0x888E7498 | `GamePlayInterface:/.../GameplayInputs` readers (EngineConfig/@Frequency, NetConfig, Commands/Pause, RestartMatch, Withdrawal, TopSpinSchool/@StartExercise) and GameplayOutputs writers (RulesInfo, PlayerInfoList) | strings | high |
| 0x888BA888, 0x888E40B0, 0x888E4EF8, 0x888E4438 | `GamePlayState:/SwingData/State/PlayerStates/PlayerState[%d]/...`, `MatchState` publishers | strings | high |
| 0x88795E40, 0x888EFD68, 0x8878E9B8, 0x88791AE8, 0x888BF898, 0x888F9750 | animation planner XData: `PlannerCommand`, `PlannerParameters/@ScaleActivated`, `UpdateSetupCommand`, `PlayParameters/@AnimIdToPlay`, per-instance `Update*` | strings | high |
| 0x888BF238, 0x8887F190, 0x8872C7F0 | FrameSynchro: `Frame[3]/SRPList/SRP[@Name="Ball"]/Position`, `BallNPlus1/2`, `BallDetectCollision`, `BallInPhysic` | strings | high |
| 0x88866000-0x88870000 | `CGameLogic` (registration fn_888678A8; vtable 0x880E06B0, Init/Exit slots fn_888669E8/fn_888681D8). Match flow (`GameDB:/GameDB/Match/@State|@NextState`). Window is a guess | structural | low |
| 0x887EC000-0x88800000 | `CAnalyserFramework` (reg fn_887FB300, slots fn_887FC748/fn_887FC790), `CTrackSideEngine` (fn_887F4808; `TrackSideManager.cpp`, `Behavior\Behavior.bin` fn_887F65B8), `CSysServices` | structural | low |
| 0x8890C000-0x88918000 | `CInputMapper` (reg fn_8890F070) | structural | low |
| 0x888D0000-0x888DA000 | `CMultiBallManager`, `CMinigame*`, `CPlayersCollisions` (reg fn_888D8B68), `CPositionningSynchro/CPhysicEventSynchro/CGameFrameSynchro` regs (0x888D6820/68D0/6980). Their module code was **not** located | structural | low |

### 1.3 Per-topic mapping (what you asked for)

**Ball flight / physics (trajectory, spin, bounce, net collision) - medium.**
There is no analytic trajectory code that I could find (no 9.81, no court
dimensions, section 3). The ball is a Havok rigid body driven through the
`CPhysicEngine` wrapper:
* World creation `fn_8887C108` (0x8887C108, 636 B): builds a `hkpWorldCinfo`
  (`fn_884758C0`), copies gravity/vector fields from a config struct passed in
  r4 (floats at +0x00/+0x04/+0x08, 4th component = 0.0 from lbl_8814B440),
  other params from +0x0C/+0x10/+0x14/+0x18/+0x1C/+0x20/+0x24/+0x28/+0x2C, then
  calls the `hkpWorld` constructor `fn_8846E050`. So gravity and solver
  parameters are **inputs, not constants in code**.
* Loader: `fn_88879098` (PhysicData.cpp), `fn_888791E8`
  (PhysicEngineCommandProcessor.cpp), `fn_88880B88` (`Physics\Physics`),
  `fn_888807E8` (`Physics\Physics.hkx`, `Ragdoll_`), `fn_88958D10`
  (`Physics\Physics.bin`/`.hkx`), `CPhysicResourceLoader`.
* Ball objects: `fn_88881048` (`Ball%02d`, 720 B, 4 Havok calls),
  `CMultiBallManager`; debug `Ball Speed : %f Km/h` fn_88881318 (2052 B); the
  physics-to-gameplay handoff is `fn_8887F190` (4052 B: `GameDB:/GameDB/Physic/EventQueue`,
  `BallNPlus1/2`, `BallDetectCollision`).
* Collision classification feeds the sound layer: `Root/Ball/Bounce/%sAngle%sSpeed`
  fn_8888CFD0, `Root/Ball/Collision/Net_%s` fn_8888EBE8 (2260 B),
  `Root/Ball/Shot/{Wood,FlatWeak,Flat%s,TopSpin%s,Slice%s,Drop}` fn_8888D700
  (556 B) and fn_8888ADC0 (1948 B). These classify events as flat/topspin/slice/
  drop and angle/speed buckets (VerySlow..Medium...), which is the best handle
  on how shot types are defined in code.
* Spin/magnus: no string evidence. Treat as unknown (could be in Havok,
  in the game's animation-driven shot parameters or in data).
* Havok wrapper range: 0x88878000-0x88882000, ~159 fns / 40.8 KB; the core
  (0x88879000-0x8887F000) is 124 fns / 24.3 KB. Closure from the physics roots
  (fn_8887C108, fn_8887F190, fn_88880B88, fn_888807E8, fn_88881048, fn_88881318,
  fn_88879098, fn_888791E8) = 21 fns / 12.6 KB.

**Shot selection & parameters (power/control/timing, flat/topspin/slice/lob/drop) - medium.**
* `fn_8865B780` (1496 B, 34 calls, no floats): shot-quality bonus table with
  21 labelled rewards `<Name> (S+%d)`: CounterEfficientShot, SpectacularAnimation,
  Volley, DropShot, ReturnEfficientShot, VeryPowerfullShot, VeryEfficientShot,
  ConnectGoodShots, ConnectedEfficientShots, ReachAnimation, RushingAnimation,
  RushingToBall, PowerfulShotAnimation, SmashAnimation, LitigiousBounce,
  VeryEfficientSlowShot, VeryPowerfulEfficientShot, VolleyPowerfulShot,
  PowerfulShot, VolleyShortReactionTime, ReflexVolleyAnimation. Called only
  from `fn_88683FA8` (1876 B, `(E%d)`), which is called from `fn_88697890`
  (via `fn_8869EF08`/`fn_886C1ED8`) and `fn_886AB760`. These are an in-game
  "score/special shot" evaluation (points rating `S+`), displayed in a debug HUD.
* `fn_886674E8` `Shot efficiencies %.2f %.2f`; `fn_88661D58`
  `In : %.2f Out : %.2f Net : %.2f` (landing zone statistics).
* `fn_886630B8` input-state names `Waiting/PressAndHold/Swing/Analysed`,
  `StickIntensity %.2f` (input analyser states, 212 B).
* UI side strings (`Cpp_PS_PowerShot_*`, `Cpp_PS_ControlShot_*`,
  `Cpp_Timing_Good/Bad/Average`, `ActionTimingFeedback`, `S4InGameStaminaBars`)
  show that "power shot", "control shot" and timing quality exist as game concepts.
  I did **not** find the code that computes them.
* Lob has no string evidence (only the sound class names above).

**Player movement, reach, interception - medium.**
* `fn_886AC2C8` (1220 B, 14 calls; caller `fn_886B0418`, vtable slot at
  0x880F44B0): prints `InputNotation`, `Selection Score`, `Ball Difficulty`,
  `Reachability: %.2f m.s-1` for the currently considered swing candidate. This is
  the swing-selection scoring HUD; the real work is in its callees
  (`fn_8869B128`, `fn_8869AEF8`, `fn_8868BD80`, `fn_886A9628`, `fn_886794D0`,
  `fn_8866C830`, `fn_8866C578`). Closure = 45 fns / 25.5 KB (0x88659F00-0x886CD3C8).
* `fn_88688948` (1096 B): validity of movement preparation types **Rush**,
  **JogPrepared**, **JogJogPrepared** against a minimum distance and a frame
  validity value. Called by `fn_88699FC0` (`RequiredSpeed: %.2f Distance: %.2f`,
  1296 B, 13 calls), itself called by `fn_886A9E48` <- `fn_886B8468` <- `fn_886BD690`
  <- `fn_886BF260` <- vtable slot fn_886BF360 (0x880F4480). Closure from
  {fn_886B8468, fn_88699FC0, fn_88688948, fn_886A9E48} = 98 fns / 59.4 KB.
  Reaction timing is implied by "frame validity" (animation frame at which the
  hit is reachable) but the timing numbers are not in code.
* Positions of players are published through XData
  (`.../PlayerState[%d]/AnimBones/Head/Position/@Y`, `ToDisplay/Position`).

**Volley logic - medium/low.** Only classification strings: `Volley`, `Volley winner`,
`VolleyPowerfulShot`, `VolleyShortReactionTime`, `ReflexVolleyAnimation`
(all in fn_8865B780/fn_88685060); `WinServeAndVolley` (fn_8868E370); sound hooks.
There is no dedicated volley decision function visible by string. Volley
behaviour is more likely animation/planner driven.

**Swing/animation planner - high for location, low for internals.**
`CSwingAnimation`/`SwingAnimationEngine(Controller)` (fn_886D75B8, registration of two
object types `ts4_keyed_item_list_add_unique_if_mode_886D2910/886D1B90`),
`InstanceState[1..4]` per-player state with `UpdateSetupCommand/@SetupId|@LeftHanded|@Reset|@BuildIndex`,
`PlannerCommand/@Reset`, `PlannerParameters/@ScaleActivated`,
`Scale/CustomScale[@Bone="B_Neck"]/Scale/@X`. Clips are Havok `.hkx` streamed on
demand (AOD), clip metadata in `Animations.bin`/`AnimationsInterface.bin`
(fn_88774300/fn_88773438). Closure from the string roots (fn_886D75B8, fn_886DACA8,
fn_886DC2C8, fn_886CE2D8, fn_886D2B58, fn_886D9CB0, fn_886DADB8) is only 14 fns / 6.6 KB
because the work is dispatched via vtables; the whole range is 397 fns / 130 KB.
Per-player `CAnimation` (reg fn_88801378, Init/Exit fn_88801E10/fn_88801E60).

**AI opponent decisions - low.** No AI strings (no "difficulty", "aggressive"...).
Candidates: the swing selection scorer above (it scores `Ball Difficulty` /
`Reachability`), `CTrackSideEngine`/`Behavior.bin` (that is probably
ball-boy/umpire/crowd behaviour, not the opponent), `CAnalyserFramework`
(input analysers; also sends commands to FaceGen agents). Treat the opponent
AI as **not located**; find it by tracing who writes the opponent's
`GameplayInputs` / analyser outputs at runtime or in the XData dump.

**Match rules / scoring - low/medium.**
* Point classification: `fn_88685060` (4272 B, 50 calls, vtable-free helper called by
  `fn_88686110`, `fn_8868F9C8`): builds `END OF POINT MODIFIERS`:
  Short/Memorable/Boring/Epic rally, PowerfulShot, VeryEfficientShot/Return,
  Baseline winner, Passing shot, Volley winner, Spectacular anim, Trickshot,
  Smash, Dropshot, Reach, Fatality, Double fault, Fault (general), Obviously out,
  Game point, Set point, Match point, Litigious, Important/Crucial point,
  First game, TOTAL. This is a momentum/stat modifier calculator, not the scoring
  state machine.
* Crowd/stat reaction: `fn_8868E370` (`LoseUnforcedError`, `WinWinner`,
  `WinAce`, `WinTwentyShots` ... `%.0f` deltas), `fn_8868EA30` (`Gain %.0f Clamp %0.f Result %0.f`).
* Umpire/announcer events, which mirror the real score state machine:
  `fn_8888C7E8` (Set/GameSetAndMatch, TieBreak), `fn_8888CB48` (GameNormal),
  `fn_8888CCE8` (TieBreakNormal `%iAll`), `fn_8888CF40` (Let first/second serve),
  `fn_8888C540/C620` (`PlayerOne/PlayerTwo`, `BeginWith/EndWith`).
* The score state itself is published in `GameplayOutputs/RulesInfo`
  (`Service/@ServiceRunning`, fn_8872C7F0) and `GameDB:/GameDB/Match/@State`.
  The rules state machine is likely in or near `CGameLogic` (low).

## 2. Entry points and the frame chain

Verified facts:
* Class registry: `fn_888DB320` (95 names). Each name hashes through
  `fn_88608590` and is registered by a per-class `ts4_keyed_item_list_add_unique_<addr>`
  function sitting next to the module's code. Useful anchors (registration fn,
  descriptor vtable):

  | Module | Registration | Init / Exit slots (vtable slot 5 / 4) |
  |---|---|---|
  | CSwingGamePlay | 0x8868D418 | fn_886AA650 / fn_886AA698 (small wrappers around fn_8869C9E8 which registers the 30 node types) |
  | CSwingAnimation | 0x886D2838 | fn_886DACA8 / fn_886DACF0 (wrappers around fn_886D75B8) |
  | CAnimationEvolution | 0x88649138 | fn_8864A160 / fn_8864A1A8 |
  | CAnimation | 0x88801378 | fn_88801E10 / fn_88801E60 |
  | CPhysicEngine | 0x8887E4A8 | fn_8887EA78 / fn_8887EAC0 |
  | CGameLogic | 0x888678A8 | fn_888669E8 / fn_888681D8 (large, ~6 KB apart) |
  | CAnalyserFramework | 0x887FB300 | fn_887FC748 / fn_887FC790 |
  | CCameraEngine | 0x888B8338 | fn_888B1D80 / fn_888B8FD8 |
  | CTrackSideEngine | 0x887F4808 | fn_887F21D8 / fn_887F4F00 |
  | CSeason | 0x8883E7A0 | fn_8883C298 / fn_888476F0 |
  | CDataMining | 0x88658008 | fn_88657AC8 / fn_88658878 |
  | CMultiBallManager, CPositionningSynchro, CPhysicEventSynchro, CGameFrameSynchro, CPlayersCollisions, CInputMapper | 0x888D2098 / 0x888D6820 / 0x888D68D0 / 0x888D6980 / 0x888D8B68 / 0x8890F070 | not resolved |

  The "slot 4/5 = Exit/Init" reading is a **guess** (medium): for the small cases they
  are wrappers that call a registrar with a constant 1/0 byte flag.
* The module list that is actually run in a match comes from XData
  (`SystemData:/SystemData/Scheduler/{ModuleManager,SubModuleManager}/ModuleList/Module[@Name="InGame"]`,
  scene switch code fn_8890B068), so the **per-frame order is data, not code**.
  Code side: `CScheduler` class registration fn_88954210, `CModuleManager`
  (class list fn_88626F70, worker thread `ModuleManager_%i` fn_88633470 created by
  fn_886345E0, 4244 B, 73 calls).
* I did **not** identify the per-frame Update virtual of CSwingGamePlay or of any
  gameplay module (the vtable slots found are register/unregister stubs and
  XData property accessors, not simulation). Finding it is work package 0 below.
* Data flow pattern that is certain: gameplay reads `GameplayInputs`, publishes
  `PlayerStates`/`MatchState`/`RulesInfo`/`PlayerInfoList`; the Display module
  reads `FrameSynchroData` (Ball position and `BallInPhysic`) and
  `AnimationData` (`InstanceState`).

Call-graph sizes (transitive closure of the listed roots, restricted to
0x88640000-0x88900000, excluding functions with >120 callers):

| Roots | Fns | Bytes |
|---|---|---|
| shot eval/stats (fn_88683FA8, fn_88697890, fn_88685060, fn_8868E370, fn_8865B780, fn_886674E8) | 20 | 16,640 |
| movement/reach (fn_886B8468, fn_88699FC0, fn_88688948, fn_886A9E48) | 98 | 59,432 |
| swing selection (fn_886B0418, fn_886AC2C8) | 45 | 25,496 |
| swing animation string roots | 14 | 6,608 |
| physics glue roots | 21 | 12,572 |
| sound events (ball/net/umpire/crowd) | 17 | 16,248 |
| XData GamePlayInterface/State glue | 63 | 22,028 |
| training/exercise (fn_886B3490, fn_886C1ED8) | 367 | 170,000 |
| replay/record/debug (fn_886C27F8, fn_886BC568, fn_886C0568) | 409 | 194,464 |

The last two closures are large because debug/trainer code reads most of the
gameplay API: that is useful as a map of "everything gameplay exposes" but is
not a good first decompile target.

## 3. Floating-point constants (physics tuning search)

Method: all `.rdata`/`.data` words in `work/sym_index.pkl['memory']` read as
big-endian f32 and f64 at natural alignment, compared to {9.8, 9.81, 9.80665,
23.77, 11.885, 10.97, 5.485, 8.23, 4.115, 0.914, 0.9144, 1.07, 1.0668,
0.033, 0.0335, 0.067, 6.40, 3.6, 0.2778, 1/60, 1/30} (tolerance 3e-5 relative
first, then 1e-3). Then code use was resolved by decoding `lis`/`lfs|lfd|addi`
relocation pairs in the split objects (`work/matching/split`).

Result: **none of the court/ball constants occur in the gameplay code or its
constant pools.** Hits and where they are:

| Constant | Address | Used by | Meaning |
|---|---|---|---|
| 9.81f | 0x88086C68 | fn_8846E050 (hkpWorld ctor) | Havok default gravity |
| 0.02f | 0x88086C5C | fn_8846E050, fn_884758C0, fn_885C0208 | Havok defaults |
| 1/30 (0.0333333f) | 0x88086EC0 | fn_884758C0 (hkpWorldCinfo ctor) | Havok default timestep |
| 1/60 (0.0166667f) | 0x88039778 | fn_883E6978, fn_883FB2E0 (FMOD), fn_8846E050 | FMOD/Havok |
| 3.6f | 0x8808A850 | fn_884C22B8 (Havok) | m/s to km/h in Havok vehicle code |
| 0.2778f | 0x8808A844 | fn_884C19A0 (Havok) | km/h to m/s |
| 3.6f, 6.4f, 1.2f, 1/60, 1/30 | 0x880D1214, 0x880D14D0, 0x880D16CC, 0x880D1050, 0x880D17C8 | inside the pooled table below | game constant pool, **cannot be attributed to a function** |
| -9.8f (21 copies), 1/30f (21 copies) | 0x88055268 ... 0x88086EF4 | none | `.rdata` Havok serialisation default tables (0 code refs) |
| 0.9143851f (13 copies) | 0x8802CDAC ... 0x8803854C | none | FMOD tables (not net height) |
| 0.0335f | 0x88B363EC / 0x88B33DD0 | fn_883559B8 (FMOD) | FMOD codec table |

The game's own float pool is the symbol `g_ts4_script_constants`
(0x880D0F70, size 0xA70, 668 words; 3,688 relocation references from ~1,450
functions). In the split objects every reference was collapsed to symbol+0, so
the constant index per function is lost; per-function attribution needs the
original instruction displacements (not in the split). The pool holds generic
values (0, 1, 0.5, 100, 1000, pi/2, 360, 1/60, 1/30, ... screen coordinates
such as 552.5, 1182.5) and **no 23.77/10.97/8.23/0.914/1.07/0.033**. Elsewhere,
the gameplay range references only **32 distinct float addresses** across
1,346 `lfs` instructions (0, 1, 0.5, 2, 4, 10, 150, pi, 2pi, 0.15, 0.7, 0.9 ...).
Conclusion: court dimensions, net height, ball radius, bounce/drag and spin
coefficients are **not literals in code**; they come from `Physics.bin/.hkx`
(Havok rigid-body/shape data) or other data files (section 4). Gravity is a
config input to `fn_8887C108`.

## 4. What comes from data files (needs the game's data to validate)

String-referenced files and the code that opens them:

| Data | Loader | Gameplay relevance |
|---|---|---|
| `Physics\Physics.bin`, `Physics\Physics.hkx`, `Common\Physics\`, `Physics\Physics` | fn_88958D10, fn_888807E8, fn_88880B88 | **court, net, ball, player collision shapes, gravity, restitution/friction** (Havok packfile) |
| `Media\Animation\AOD\%u.hkx` | fn_886CE2D8, fn_886D2B58 | swing/movement clips (Havok animation on demand), annotations such as contact frame |
| `\Animations\Animations.bin`, `\Animations\AnimationsInterface.bin` | fn_88774300, fn_88773438 | clip tables / interface mapping used by the planner |
| `Global.bin` | fn_8879A4F8/A730/A918/AA40, fn_887EFAE8, fn_888568C0, fn_8886B230/B388, fn_888F0D28 ... (many) | global game database; likely holds player/gameplay attributes and tuning (**unverified**) |
| `GameplayEOP.arc` | fn_887E35D0, fn_887E5538 | end-of-point (cutscene/stat) data |
| `%sBehavior\Behavior.bin` | fn_887F65B8 | trackside behaviour (ball boys/crowd/umpire) |
| `CoreTech_Xenon.bin`, `UPDATE:\CoreTech_Xenon.bin`, `UPDATE:\Layoutall.bin` | fn_889BD370 | engine/scheduler XData incl. module list |
| `Media\BinData\GameDB\*.bin`, `Season\*`, `Tournament`, `CoachList.bin`, `WorldTourProfile.bin`, `UnlockedItemList.bin` | game-flow code | match setup, season, progression |
| `Media\PlayerCreator\Xml\DNA\...`, `Media\Display\Scenes\...` | player creator/display | appearance, not gameplay |
| `Media\StringTable\%sStringTable.bin`, `Media\BinData\StringTable.bin` | fn_887E9EC8 | text |
| `Media\Sounds\`, `Core.arc` | FMOD | audio events (`Root/Ball/...`) |
| `Media\ReplayDemo\%s.bin`, `Input.rec`, `Input_%d.rec`, `GamePlayHeap{P,V,AOD,Patch}_%d.rec` | fn_888FA780, fn_886BC568, fn_886C27F8 | replay and input recording; debug record of gameplay heaps |
| `modules/?.lua`, `PackageHierarchy.lua`, Lua `tsu_*` bindings | Lua VM at 0x88800000 | menu/flow scripts, not shot physics |

Hash keys: node types and many lookups use 32-bit hashes (`lis/ori`
immediates such as 0xD18BEF51, 0xE81F2AE1 in fn_8869C9E8); the string table
for those hashes is in data (XData schema), so naming those node types will
require the schema files.

## 5. Work packages (priority order)

Sizes: functions / bytes from the closures or ranges above (bytes are code
only). All "validate" steps require the corresponding data files or a
recorded input replay; the repo cannot store them (AGENTS.md).

| # | Package | Entry functions | Size | Why first |
|---|---|---|---|---|
| WP0 | Locate per-frame update + build the observation harness: find the Update virtuals of CSwingGamePlay/CSwingAnimation/CPhysicEngine/CGameLogic via the scheduler (fn_88954210, fn_88626F70, fn_886345E0) and the module XData list; document `Input.rec`/`GamePlayHeap*.rec` formats (fn_886BC568, fn_886C27F8) | scheduler 0x88620000-0x88640000 (1,883 fns / 258 KB, mostly utility) + 2 recorders | ~15 fns / 15 KB core | unblocks everything; recorders give deterministic validation |
| WP1 | Shot evaluation, point-end modifiers, stats | fn_8865B780, fn_88683FA8, fn_88697890, fn_88685060, fn_8868E370, fn_8868EA30, fn_886674E8, fn_88661D58, fn_88666F18, fn_886630B8 | 20 fns / 16.6 KB (closure) | string-anchored, floats-free, high confidence naming, small |
| WP2 | Swing candidate selection scoring (`Selection Score`, `Ball Difficulty`, `Reachability`, `InputNotation`) | fn_886B0418 -> fn_886AC2C8 and callees (fn_8869B128, fn_8869AEF8, fn_8868BD80, fn_886A9628, fn_886794D0, fn_8866C830, fn_8866C578) | 45 fns / 25.5 KB | core of shot choice and reach |
| WP3 | Player movement preparation and required speed (Rush/Jog/JogJog) | fn_886B8468 (check for merged functions), fn_886A9E48, fn_88699FC0, fn_88688948 | 98 fns / 59.4 KB | movement and interception timing |
| WP4 | PhysicEngine wrapper: world creation, ball bodies, event queue, FrameSynchro ball | fn_8887C108, fn_8887B148, fn_8887B458, fn_8887AB50, fn_8887F190, fn_88880B88, fn_888807E8, fn_88881048, fn_88879098, fn_888791E8, fn_88958D10 | 21 fns / 12.6 KB (core) up to 159 fns / 40.8 KB (range) | ball flight/bounce/net originate here; data = Physics.hkx |
| WP5 | Ball/net/umpire event classification (sound hooks) | fn_8888D700, fn_8888ADC0, fn_8888CFD0, fn_8888EBE8, fn_8888C7E8, fn_8888CB48, fn_8888CCE8, fn_8888CF40, fn_8888C620, fn_8888C540 | 17 fns / 16.2 KB | reveals shot-type buckets and score-state events cheaply |
| WP6 | GamePlayInterface/PlayerState/MatchState XData glue (inputs, rules info, player states) | fn_88724FF0, fn_88790DA0, fn_887911B8, fn_887928A8, fn_88798E68, fn_888B9D50, fn_888BA888, fn_888E40B0, fn_888E4EF8, fn_888E00D8, fn_888E7498, fn_8872C7F0 | 63 fns / 22 KB | gives typed structs for inputs/outputs used by all other packages |
| WP7 | Swing animation engine and planner XData | fn_886D75B8, fn_886DACA8, fn_886DC2C8, fn_886CE2D8, fn_886D2B58, fn_886D9CB0, fn_886DADB8, fn_88795E40, fn_888EFD68, fn_8878E9B8, fn_88791AE8, fn_888BF898, fn_888F9750 | range 0x886C8000-0x886E8000: 397 fns / 130 KB (string roots: 14 fns / 6.6 KB + planner glue) | choosing/timing swing clips |
| WP8 | Gameplay module schema registration + accessor stubs (mechanical) | fn_8869C9E8 (30 registrars at 0x886810C0-0x8868D298, 0x88690208-0x88693E28), small stubs in 0x8865A000-0x88680000 | ~850 fns <=64 B (~56 KB in 0x8865A000-0x88668000 alone) | boilerplate; suits the existing cluster-matching workflow (`work/clusters*`) and yields typed node names |
| WP9 | CGameLogic (match flow/rules) and CAnalyserFramework/CInputMapper | CGameLogic 0x88866000-0x88870000 (~244 fns / 46.7 KB, window guessed), CAnalyserFramework region 0x887EC000-0x88800000 (398 fns / 81 KB), CInputMapper 0x8890C000-0x88918000 (275 fns / 48 KB) | ~900 fns / 175 KB | rules and input interpretation; boundaries unverified, do after WP0 |
| later | AI opponent (not located), TopSpin School/exercises (`fn_886B3490`, 367 fns / 170 KB closure), debug HUD/replay recorder, CMultiBallManager/CPlayersCollisions (module code not located), camera (0x888B0000-0x888C0000, 202 fns / 65 KB) | | | not needed for first gameplay pass |

Recommended order: WP0, WP6 (types), WP1, WP5, WP4, WP2, WP3, WP7, WP9, WP8
(run WP8 in parallel as a mechanical batch).

## 6. Do-not-map middleware

Havok Physics 0x88440000-0x88560000 (4,415 fns / 1.18 MB), Havok Animation
0x88400000-0x88440000 (1,481 / 259 KB), Havok reflection 0x889C0000-0x88B00000
(11,948 / 1.29 MB, class-registration tables), FMOD 0x88300000-0x88400000
(3,607 / 1.06 MB), CRT + XDK ucode 0x88560000-0x88600000 (3,433 / 651 KB),
Lua 0x88800000-0x88838000, zlib 0x88874270-0x88877400, Bink (`BINK*` sections).
Together these are roughly 25,000 of the ~48,000 symbols.

## 7. Reproducibility and caveats

Inputs: `config/54540859/symbols.txt` (7,552,839 B, sha256 `ec79e191534b9b28aa58772c7e3b9112ce120957930a3d6ea7658a1c167b9d5d`),
`work/gameplay_strings.txt` (29,622 B, 714 lines, sha256 `b0f26bff95964d0df9bc4f140f109467d89ab1d644c3d0cd10a107c993feb84f`),
`work/sym_index.pkl` (sha256 `68b6d42d60b8b6119f45c27fba18bd287a95d39f53de59e282d6994863e1e35a`),
repo HEAD `3ab0a63`, Python 3.13.18, `tools/fn_asm.py`/`tools/sym_info.py` as in the repo.

Method summary (standard library only, scripts not committed): (1) read function
bytes and relocations from `work/matching/split` via `tools/xcoff.py` (47,933 of
48,029 `.text` symbols decoded, about 1.7 s); (2) record REL24 callees, and for
`lis`+`REFLO` pairs the data address `(hi<<16)+sext(lo)`; (3) invert to callers;
(4) string -> function via `X[lbl_<addr>]` xrefs of the C strings found in
`.rdata`; (5) closures with a 120-caller cut-off to drop utility functions;
(6) float search as in section 3.

Caveats:
* Symbol sizes come from the splitter; at least `fn_886B8468` contains 39
  prologue-helper pairs and is probably several functions. Count/size totals
  for ranges are sums of symbol sizes.
* Ranges are layout inferences. Address neighbourhood is a good predictor
  (functions are grouped by original source file) but module boundaries were
  confirmed only at the anchors named above.
* VMX128 instructions disassemble as garbage (`.long`, `vcmpequd`) in the
  objdump used by `fn_asm.py`; gameplay math using them cannot be read from the
  current disassembly. Check how the matching compiler emits these before
  decompiling WP2/WP3.
* "Init/Exit" slot naming, the meaning of the 30 registered node types
  (schema/accessor descriptors rather than update tasks), and the role of
  `fn_886B8468` are open items.
