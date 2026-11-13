# GP0 notes: scheduler / per-frame update (WP0) and XData glue (WP6)

Module: Swing_DLL.xex, symbols.txt sha256 prefix ec79e191534b9b28 (7,552,839 B), repo HEAD f4efd94,
Python 3.13.18, matching compiler MSVC 16.00.10224.00 (tools/fn_check.py). All addresses are xex VAs.
Confidence: **H** disassembly read directly, **M** consistent structural evidence, **L** guess.

## 1. Facts that unblock everything else

1. **Name hash = zlib crc32 (seed 0, standard table at lbl_880C84C0) of the ASCII string.**
   `fn_88608590(0, str)`. Verified: crc32("GamePlayInterface")=0x7A84A93D, "SystemData"=0xC24FECAC,
   "CModuleProcessor"=0x552A6649, "InputMapper"=0x8B430A2D, "Season"=0xF7485E9F, "InGame"=0x1DCA7285,
   "First"=0x53B0C153, "Xenon"=0xC89FA93B, "GamePlayState"=0x80790025, "CSwingGamePlayEngine"=0xCA2A2DBB,
   "Serve"=0xA6A1B2AE, "Minigame"=0x6D2794E5, "B_Head"=0x6F94D460. (H, reproducible: `zlib.crc32(s.encode())`.)
   Most gameplay class/service/node-type names are NOT in the binary as strings (hash only), e.g. the 30
   node types of CSwingGamePlay, the services 0x91831427 0x6D6C3329 0x3CC3B6C0 0x21AC4822 0x3419C748 and the
   typed-struct hash 0x63F5A11F (GameplayInputs), 0x502FE79D (PlayerStates). A 7.4k-word CamelCase
   brute force (prefixes C/Pam::...) found nothing: names live in the schema data files.
2. **Object model (every scheduler module, service and XData node class).** C++ objects with this vtable
   (verified on ~60 classes, listing reproducible with the scripts in the report):
   `[0]` dtor, `[1]` noop `886063A0`, **`[2]` per-frame Update/Run**, `[3]` `fn_88628098` (clone/assign),
   **`[4]` Init**, **`[5]` Exit**, `[6]` `fn_8860C0B8`, `[7]` noop, `[8]` `fn_88608320`, `[9]` noop, `[10..]` class specific.
   The gameplay-map's "slot 4/5 = Exit/Init" is **reversed**: slot 4 is Init (calls base init `fn_88627EC0`, then
   `fn_8869C9E8(&1)` = register node types), slot 5 is Exit (`fn_8869C9E8(&0)` = unregister, clears byte +8,
   destroys the +0x10 member). Proof: lbl_880C8F25 = 0x01, lbl_880C8F26 = 0x00 are the pointer argument; `fn_88636AE8`
   (slot 4 of the CModuleManager vtable) creates the worker thread, `fn_8862E0A8` (slot 5) joins/destroys it.
3. **28-byte "module shells" have a NOOP Update.** CSwingGamePlay, CGameLogic, CPhysicEngine, CAnimation,
   CSwingAnimation, CAnimationEvolution, CCameraEngine, CAnalyserFramework, CSeason, CDataMining, CTrackSideEngine,
   CSysServices ... all have slot 2 = a noop (886063D8). They only register/unregister node types in Init/Exit.
   Their simulation lives in **node-type classes** registered by Init (section 4) and in other registered classes.
4. **Who calls Update:** `CModuleProcessor::Run` = `fn_88611760` (vtable 0x880F8C44 slot 2, H). It is the only
   place that issues `module->vtbl[2](module)` for scheduled modules (0x88611914 and 0x88611AA0). See
   `src/xbox360/drafts/gp0_module_processor.c`. The modules, their order, repeat counts (+0x30), frame divisors
   (+0x34) and threading flags (+0x0C) come from the XData config at processor+0x24 (SystemData:/SystemData/Scheduler/
   {ModuleManager,SubModuleManager}/ModuleList, CoreTech_Xenon.bin). **The per-frame order is data and cannot be
   recovered from code**; what code gives is the set of Update functions (section 3-4) and the order *inside* the
   engine object's update (section 3).

## 2. Scheduler / engine globals

* `lbl_88D45B1C` (global engine object): `+0x228..0x230` RNG state (xorshift + LCG 0x10DCD, inlined in fn_88724FF0),
  `+0x220/+0x224` file system objects (vtbl+0x44 exists, +0x28 open-read, +0x34 open-write),
  `+0x234` ring buffer of 0xC4-byte input records (count +0x34, index +0x1C/+0x30, base +0x3C),
  `+0x24C` bool "modules on worker threads", `+0x270` global frame counter (used modulo the entry divisors),
  `+0x278` engine state (2/3/4 = load/transition; 6 set while a scene starts), `+0x27C` current scene hash.
* `lbl_88D45B20` = class/node registry (hash -> descriptor; `fn_8816D220(reg, hash)`; descriptor vtable
  `[dtor, factory_tag2, factory_tag0]`), `lbl_88D45B38` = allocator heap (`fn_88613268(heap,size,align,flags,tag)`),
  `lbl_88D45B00` = singleton GamePlay engine object (set in ctor fn_88690B48, cleared in dtor fn_88690AA0).
* `ts4_find_service(hash)` (fn_8860BB30) searches engine->+4->+0x88 (vector of objects with +4 = hash).
* `fn_886345E0` (0x1094) is the **scene-start state machine of the module manager** (this+0x2C state 0..5,
  +0x68 substate, +0x4C scheduler config, +0x44 module list entry (0xA4 stride, hash at +0x90), +0x20 CModuleProcessor
  created by `fn_88611C00` = registry hash 0x552A6649 + vtbl[11] Configure). `fn_88633470` creates the thread
  "ModuleManager_%i" (thread proc fn_8862F6D8). Entry points: vtbl slot 4 `fn_88636AE8` (Init), slot 2 `fn_88636C30`
  (per-frame kick: runs fn_886345E0 / fn_88635678 when idle). Registered class list: `fn_88626F70` (pure
  registration: output logs, CQueue*, CModuleProcessor, CCompositeModule, CFileSystem*, CArchiveLoader...), not a
  scheduler. `fn_88954210` (CScheduler class registration) likewise only registers node types (CTextureBlendXBIN,
  CFaceGenInterfaceXBIN, CMorphXBIN ...), no update code.

## 3. THE gameplay per-frame update (H for steps marked, see drafts/gp0_engine_update.c)

Engine object (singleton, 0xD8 bytes, node-type hash 0xD18BEF51, registered first by CSwingGamePlay Init; class
vtable 0x880F4318, ctor fn_88690B48, Init fn_886BC678, **Update fn_886C27F8**). Fields: `+0x78/+0x7C` vector of
match **instances**, `+0xC8` input/heap record writer service (0x3CC3B6C0), `+0xCC` (0x21AC4822), `+0xD0` InputMapper
service, `+0x5C` service 0x91831427, `+0x64` 0x6D6C3329, `+0x84` object of registry class 0x36594CC8.
Init reads services GamePlayInterface (0x7A84A93D), SystemData, Season, InputMapper, and copies the engine config
(hash 0x2FEF2019 struct, fn_886BC568) into +0x1C..+0x58.

`fn_886C27F8` (Update), in order: record/replay bookkeeping (section 5) -> frame number++ -> optional record
service updates -> **either** `InputMapper->Update` (when inst0.flags+0x354 and the GamePlayInterface bool at +0x80
is false) **or** `fn_8865F518(inst)` for all instances (clears 14 per-player floats at player.state+0x430..0x46C)
-> `fn_886C1ED8(inst)` for all instances -> `fn_8869EE60(inst)` for all instances.

`fn_886C1ED8` (instance step, 0x91C): see the ordered list in drafts/gp0_engine_update.c. Condensed order:
1. clear one-shot flag bytes; 2. restart/training reset (match flags +0x328/+0x329);
3. TopSpin School step `fn_886B3490` **or** end-of-point handling (`fn_8868F9C8` -> `fn_88685060`, state hash
   0x029EAAF4/0x02083CFD -> 0x85E3E155); 4. `fn_8867B608` decides whether this frame simulates;
5. **`fn_886B5128` (0xF08) = main gameplay frame** (shots/swings/movement/AI; first call is fn_8866EBC0, uses
   fn_886AD278/fn_8867B2D8/fn_8869F068/fn_886A4AE0/fn_88675840; this is the function WP2/WP3 owners should take);
6. `fn_8869EFC8`, `fn_8868FCC0` (0x428), `fn_8865F150` (0x2C0), speed |v|*scale at world+0x520 (VMX `vmsum3fp128`),
   `fn_886660A0` at the serve frame, `fn_886C1E80` (<= 8 queued command steps via `fn_886C1628`, 0x858),
   `fn_8865C170`/`fn_8869EF08`, `instance.sub68->Update`, `fn_8866E448`, per-player `fn_88697118` + `fn_88696D40`
   (ball/player interception + reach tables, 0x634/0x2EC), `fn_889C2818`, then **frame counters ++**
   (`match+0x310`, `+0x314`) and `fn_886ABAE8(.., 1, 0x51FC19ED)` (shot-quality/stat evaluation, WP1);
7. `fn_8866E4B8` (0x6C8), `fn_886900E8`, `fn_8867BDB8` per player.

Other Update slots reached through the processor (data-driven order), keyed by node-type hash (registered by
CSwingGamePlay Init `fn_8869C9E8`; table in section 4):
* **PlayerController** (0x5A0 B, hash 0x23428A2C, vtable 0x880F4478): Update `fn_886BF360` = `fn_8867DEF0`,
  `fn_8867DF68`, `fn_8869D720`, **`fn_886BF260`** (-> fn_886A8170, fn_8866BAE0, fn_886B3CF8, fn_88678468,
  fn_886A84C0, fn_886B3AE8, **fn_886BD690 -> fn_886B8468 (0x2300 B movement/reach)**), `fn_886782D0`, then sets
  the 'Serve'-phase bits (crc32("Serve")). Init `fn_886BF598`, Exit `fn_886A2378`, swing-selection slot `fn_886B0418`.
* instance-like node (0x180 B, hash 0x368ED310, vtable 0x880F4708): Update `fn_886BB0A8`, Init `fn_886BB6E0`.
* nodes with Update: 0x44 B 0x961271DF `fn_886B7D50`; 0x30 B 0x2DF2A93A `fn_886B80B8`; 0x4C B 0x0E0DB124
  `fn_88696020`; 0x40 B 0xE73B8150 `fn_8865F618`; 0x20 B: 0xE81F2AE1 `fn_8826A1A0`, 0x5989B500 `fn_8865ADD0`,
  0x04E0BD27 `fn_8866D110`, 0xEDF815A4 `fn_886631B0`, 0x4D7FB59D `fn_88663328`, 0x6034F29C (0x24 B) `fn_88670950`,
  0xB9F15B60 (0x30 B) `fn_88663208`, small: AF20A359 `fn_886614F8`, 85B71A2B `fn_886707C8`, 83B15071 `fn_88660F08`,
  AF2346B9 `fn_88662F10`, 9D187419 `fn_88662DF0`, DD92070A `fn_886B25B8`.
* Support modules with real Update (not shells): CPlayersCollisions `fn_888D8C18`, CMultiBallManager `fn_888E2BE8`,
  CMultiBallManagerPreUpdate `fn_888C3D00`, CPhysicEventSynchro `fn_888CB8F0`, CGameFrameSynchro `fn_888D6A30`,
  CPositionningSynchro `ts4_forward_888C5BF8`, CInputMapper `fn_88910F50`, CInGameUINotifier `fn_88909888`
  (Init fn_888E40B0), CFacialAnimSync `fn_8817BA50`, CReplay `fn_888FDFF0`, CTopSpinSchool `fn_888FB960`,
  CDisplay* `fn_8876D048/fn_8876D040/fn_887606D0`.
  Their addresses in the 0x888C-0x8890 band make CMultiBallManager/CPlayersCollisions code **located** (WP map
  said "not located").

## 4. The node types registered by CSwingGamePlay Init (fn_8869C9E8)

Walked as registry descriptor -> factory -> ctor -> first vtable (noop slots are `ts4_noop_*`; shown as the address of whatever
is in the slot). Names are hash-only. Rows whose Update is a `ts4_noop_*` are data-only nodes. The three big rows were checked by hand.

| hash | bytes | vtable | [2] Update | [4] Init | [5] Exit |
|---|---|---|---|---|---|
| D18BEF51 | 0xd8 | 0x880F4318 | fn_886C27F8 | fn_886BC678 | fn_886A7020 |
| E81F2AE1 | 0x20 | 880F4868 | fn_8826A1A0 | fn_8826A1B8 | fn_8826A260 |
| E73B8150 | 0x40 | 880F4890 | fn_8865F618 | fn_886ACC40 | fn_8865F588 |
| 9BD3657E | 0x8 | 880F4640 | ts4_noop_88659520 | fn_8826A9B0 | ts4_dtor_wrapper_88271310 |
| AF20A359 | 0xc | 880F4654 | fn_886614F8 | ts4_forward_886A0EC0 | fn_8867DA30 |
| 85B71A2B | 0x14 | 880F4808 | fn_886707C8 | fn_886935A0 | fn_886A0850 |
| 83B15071 | 0xc | 880F482C | fn_88660F08 | fn_88692B48 | ts4_noop_8867D140 |
| 6034F29C | 0x24 | 880F47C8 | fn_88670950 | fn_886A7928 | fn_8867D728 |
| 4AC3C6C8 | 0x24 | 880F4788 | ts4_noop_886599B8 | fn_886A7958 | fn_8867D900 |
| B0EF04B3 | 0x20 | 880F4678 | ts4_noop_8865A718 | fn_886AB2F0 | fn_88693F08 |
| 961271DF | 0x44 | 880F4DC8 | fn_886B7D50 | fn_886A7D58 | fn_886813B8 |
| 0E0DB124 | 0x4c | 880F4D10 | fn_88696020 | fn_886A7E00 | fn_88681D00 |
| 2DF2A93A | 0x30 | 880F4C50 | fn_886B80B8 | fn_886A7EA8 | fn_88682988 |
| 5989B500 | 0x20 | 880F4D8C | fn_8865ADD0 | fn_886A7DA0 | fn_88681548 |
| 34B31A80 | 0x20 | 880F4CD0 | ts4_noop_88659CC8 | fn_886A7E48 | fn_88681EA0 |
| B9F15B60 | 0x30 | 880F4C10 | fn_88663208 | fn_886A7ED8 | fn_88682DC0 |
| 368ED310 | 0x180 | 0x880F4708 | fn_886BB0A8 | fn_886BB6E0 | fn_8868C930 |
| 4B649818 | 0x20 | 880F4B50 | ts4_noop_8865A120 | fn_886AA590 | fn_8868CEF8 |
| 14C197B0 | 0x20 | 880F4AD0 | ts4_noop_8865A140 | fn_886AA5F0 | fn_8868D1F8 |
| 46617B17 | 0x20 | 880F4B90 | ts4_noop_8865A088 | fn_886AA560 | fn_8868CA78 |
| 04E0BD27 | 0x20 | 880F4B10 | fn_8866D110 | fn_886AA5C0 | fn_8868D078 |
| FE44A736 | 0x20 | 880F4A90 | ts4_noop_8865A148 | fn_886AA620 | fn_8868D378 |
| 002DAC2B | 0x20 | 880F4D50 | ts4_noop_88659B68 | fn_886A7DD0 | fn_886816C8 |
| EDF815A4 | 0x20 | 880F4C90 | fn_886631B0 | fn_886A7E78 | fn_88682020 |
| 4D7FB59D | 0x20 | 880F4BD0 | fn_88663328 | fn_886A7F08 | fn_88682F40 |
| 23428A2C | 0x5a0 | 0x880F4478 | fn_886BF360 | fn_886BF598 | fn_886A2378 |
| AF2346B9 | 0xc | 880F4E04 | fn_88662F10 | fn_88659B00 | ts4_dtor_vtable_base_8826B6B8 |
| 9D187419 | 0x10 | 880F4E40 | fn_88662DF0 | fn_886811A0 | ts4_dtor_vtable_base_8826B6B8 |
| DD92070A | 0xc | 880F4E54 | fn_886B25B8 | fn_88659A70 | ts4_dtor_vtable_only_88286DD0 |

## 5. Recorder formats (WP0)

* `Input.rec` / `Input_%d.rec` and `GamePlayHeap{P,V,AOD,Patch}_%d.rec` are written/read by the **engine Update**
  (`fn_886C27F8`), not by a dedicated recorder module. `%d` = `match+0x4` (instance 0 match record).
  File access goes through the engine file-system objects (g_engine+0x220/+0x224); `fn_88913BD8(this, name, mode)`
  stores `mode` at +0x48 and opens the file: mode 1 = write (fs.vtbl+0x34(name, access 2, 0), after fs.vtbl+0x3C(name)
  delete when fs.vtbl+0x44 reports it exists), else read (fs.vtbl+0x28(name, 1)); the handle is kept at +0x1C. (H)
* The record **content** is produced by the writer service's Update (engine+0xC8 vtbl[2], class not identified) and by the
  four heap-service serializers (service hashes 0x85E88173, 0xB20FF443, 0x14E2D892 and engine heap +0x0C: vtbl+0x88 /
  +0x8C). Per-frame input record = the 0xC4-byte struct at ring+idx*0xC4 (memcpy 0xC4, H). No field layout of the
  .rec files was recovered: **format is only known at the container level** (raw FS stream; frame-indexed 0xC4-byte
  input records). `fn_886BC568` additionally stores a service pointer (hash 0x3419C748, +0x60), clears byte +0x530 of
  every object in the vector at +0x84, then re-applies config and, when recording is allowed (`match+0x9`), calls
  fn_88913BD8(+0xCC, "Input.rec", 1).
* Heap dumps: P/V/AOD/Patch = presumably physics/vertex/animation-on-demand/patch heaps (names from suffixes only, L).

## 6. XData protocol (WP6) - established by matched code

* **Handle** `struct { void *tree; u32 node_id; void *pool; }` (12 B). `fn_8862BE08(out, "XPath")` resolves an
  attribute path (`...@Name`), `fn_8862C0E8(out, "XPath")` a node path. node_id 0x000FFFFF = invalid/unresolved.
  Idiom everywhere: cached handles in objects; `if (!h.tree || h.node_id == 0xFFFFF) h = resolve(path)`.
* **Tree vtable**: `+0x24 get_value_ptr(tree, handle, id, size)`, `+0x30 has_type(tree, id, code)`,
  `+0x38 create_with_default(tree, handle, id, out, size, default_object)`. Type codes: **1 bool, 2 int32, 9 u32
  (hash)**. Matched: `ts4_gp0_xdata_get_bool_88163C60`, `..._int32_88163D18`, `..._u32_or_default_88165E20`;
  fn_88169350 (u32 read) is the same pattern (not matched byte-for-byte).
* **Typed struct view**: `fn_88923530(pool, handle, type_hash)` returns `pool->+0x24 + node_offset` after checking the
  tree tag (0x80E55C7B) and that the node's type hash (node->+0x30) == `type_hash`. This is how the typed C
  structs below are reached.
* Packed XData arrays use `{ int rel_offset (-1 = null); int count; }` headers with the element address =
  header_addr + rel_offset + i*stride (fn_8827F9A8/fn_881BB8A0 return end/begin).

### Typed structs seen (offsets exact, names role-only)

* `GamePlayInterface:/SwingGameplayInterface/GameplayInputs` (type 0x63F5A11F): `+0x60` u8 EngineConfig-valid,
  `+0x64` int EngineConfig/@Frequency (fn_88790DA0, Lua binding, draft). `NetConfig/@IsOnlineMatch` bool
  (read by fn_88724FF0 and matched fn_887911B8). Commands/Withdrawal/@LooserTeamIndex (int) + @IsTriggered (bool)
  written by script binding fn_887928A8 (draft notes in drafts/gp0_xdata_misc.c).
* `SystemData:/SystemData/Scheduler/SubModuleManager/@NextModule` (u32 scene hash): InGame = 0x1DCA7285.
  `ts4_gp0_next_module_is_local_match_887911B8` = "next module is InGame (or 0xF202BB09) and local (not online)
  and lbl_88C4589D set".
* `GamePlayState:/SwingData/State/PlayerStates` (type 0x502FE79D): array header {rel_off, count at +4}, **element stride
  0x1070**, base + 0x70 is the per-player block read by the camera code (fn_888BA888 reads PlayerState+0xC4 target hash,
  +0xD4/+0xD8/+0xE0/+0xE8 floats (extents), +0xEC byte, +0xF8 float, +0x110 index, +0xFC bone hash (B_Prop2/B_Head)).
  The in-memory **Gp0PlayerState** (player->u_0074 in the engine, size >= 0x1070 because the instance step writes
  +0x1068) is the same layout: +0x430..0x46C float block cleared per frame, +0x4E5 flag, +0x530 float (speed), +0x57D/+0x5DB
  flags, +0x9F4 float, +0xBC8 int, +0xFBC/+0xFBA flags, +0x1068 hash.
* `GamePlayState:/SwingData/State/MatchState/TopSpinSchool/@StepIndex` (fn_888E4EF8: also registers sound busses
  'ambience','crowd','fx','umpire','ui','music' through fn_886387E0); `.../PlayerStates/PlayerState[%d]/ToDisplay/Position`
  (fn_888E40B0 = CInGameUINotifier Init, 0x388 B, vtable 0x880DB698 slot 4).
* `GameplayOutputs/RulesInfo/Service/@ServiceRunning` and `FrameSynchroData:/FrameSynchro/Frame[2]/BallInPhysic` are
  consumed by **CDisplay** code (fn_8872C7F0, 0x54C, the shadow/LifeTime logic of group "BallShadowMultiLight00"),
  not by gameplay: it follows the pattern "lazy-resolve handle, read bool/int, write LifeTime".
* `GameplayOutputs/PlayerInfoList/PlayerInfo[%d]/@IsActive` and `GameDB:/GameDB/PlayerGamerTagDataList`,
  `GameDB:/GameDB/PlayerCreator/@Gender` are in fn_88798E68 (0x55C, PlayerCreator glue: builds
  Media\PlayerCreator\Xml\DNA\{Male,Female}\PlayerCreated%d.bin, PlayerCreator_{Male,Female}.arc) - a menu/avatar
  function, not gameplay.

### In-memory gameplay object layout (engine side, offsets from the instance step; role names are guesses)

GamePlayInstance (`fn_886C1ED8` this; probably the 0x180-byte node, hash 0x368ED310, M):
`+0x04/+0x08` player vector, `+0x10/+0x14` team vector (stride: team->+0x10 players, team->+0x24 info with
`+0xB8` = current player index), `+0x28` rules/mode record (`+0xC` mode hash, `+0xF57` special-mode bool),
`+0x30` match frame state (`+0x310` frame, `+0x314` frame2, `+0x318` state hash, `+0x328/+0x329` training flags,
`+0x2D4` frame limit), `+0x44` flag block (`+0x1C/+0x1D` pause-ish bytes, `+0x60` end-of-point request,
`+0x68` active-flag sync request, `+0x78` restart request, `+0x84` bool, `+0x90..+0x1A0` per-event state block
incl. `+0x164/+0x168` deferred state {valid, hash}, `+0x19A` active, `+0x218`, `+0x354` simulate-this-frame,
`+0x104 + player*0x140` per-player 0x140-byte records), `+0x4C` ball/interception tables,
`+0x58`, `+0x5C` world {`+0x20` -> vec4 at +0x4F0, speed +0x520, `+0xE0` serve frame}, `+0x68` helper with +4 = instance
back-pointer, `+0x6C`, `+0x70` training object, `+0x74` object with vtbl[1], `+0x7C`.

## 7. Matches (fn_check MATCH, exit 0; specs in work/specs/GP0/)

| source | function | VA | bytes |
|---|---|---|---|
| gp0_instance_small.c | ts4_gp0_clear_player_float_block_8865F518 | 0x8865F518 | 0x70 |
| gp0_instance_small.c | ts4_gp0_run_command_steps_886C1E80 | 0x886C1E80 | 0x54 |
| gp0_instance_small.c | ts4_gp0_instance_tail_steps_8869EE60 | 0x8869EE60 | 0xA8 |
| gp0_instance_small.c | ts4_gp0_force_state_hash_88697B90 | 0x88697B90 | 0x68 |
| gp0_xdata_get.c | ts4_gp0_xdata_get_bool_88163C60 | 0x88163C60 | 0xB4 |
| gp0_xdata_get.c | ts4_gp0_xdata_get_int32_88163D18 | 0x88163D18 | 0xB4 |
| gp0_xdata_get.c | ts4_gp0_xdata_get_u32_or_default_88165E20 | 0x88165E20 | 0x60 |
| gp0_xdata_state_checks.c | ts4_gp0_next_module_is_local_match_887911B8 | 0x887911B8 | 0xB8 |

Total 8 functions / 0x4B8 = 1208 bytes. Near-misses (drafts): fn_88790DA0 (stack slot of handle),
fn_8866E448 (lwzx operand order), fn_88169350, and fn_88669040 (needs custom callee register convention).

## 8. Open items for the next pass

* Names for the 30 node types and the services (need the XData schema / CoreTech_Xenon.bin; not in repo).
* Who calls `fn_886BF360` per player and `fn_886BB0A8`: data-driven module list; confirm with a runtime trace.
* Middle of fn_886C27F8 (0x886C2A00-0x886C3060) was summarised, not read line by line.
* fn_886B5128 (0xF08), fn_886B8468 (0x2300), fn_886ABAE8 (0x5D4) are the next big gameplay targets.
