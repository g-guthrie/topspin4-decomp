# Front end map: from boot to a running match (FE1)

Analysis agent FE1, 2026-11-14. Written for the native-build agent (docs/recomp-build.md). It shows where
the game's C++ front end lives, what it waits on, how a match is described and started, and how a per-frame
logger reaches the ball and the players from fixed globals.

All addresses are Swing_DLL virtual addresses. Each claim carries a tag:

- **R**: read from code (disassembly);
- **D**: read from data (the compiled Lua and action scripts under `work/port/assets/ui`, or a disc file);
- **I**: inferred.

Inputs (git-ignored, the owner's copies):

| file | size | sha256 |
|---|---:|---|
| `orig/54540859/Swing_DLL.dll` | 13,848,064 | `a7f28b29…952ba9` |
| `config/54540859/symbols.txt` | | `f9238feb…78fd42` |
| `work/port/assets/ui` | | export of `tools/port/ui_export.py` (docs/port/ui.md) |
| Core.arc `BackstageRequests.bin` (hash 19ce55a5) | 1,053,532 | `247a31f8…62efb` |

Tools: Python 3.13.18 and capstone 5.0.7. Capstone fails on some VMX128 words; those were read around.
The method is reproducible with small throw-away scripts that were not committed, because they read the
executable:

1. Load the PE (`work/disc/ppcd.py` mapping).
2. Index every `lis`/`addi` pair and every `bl` in `.text`. This gives the code references to each string
   and the callers of each function.
3. Find the callers of the three Lua registration helpers (0x881E9B28, 0x882198D0 and 0x88836968).
4. Simulate each registrar linearly to pair the name string with the handler pointer it stores.
5. Resolve the class list registered by `ts4_name_keys_register_888DB320`: registry descriptor → factory →
   constructor → vtable, using the slot layout of docs/gameplay/gp0.md (slot 2 Update, slot 4 Init, slot 5 Exit).
6. Name crc32 hashes from every identifier in the UI export, plus a one-token brute force over the known
   prefixes (`MatchSettings_`, `Online_` and so on). 365 of the 918 attribute ids are named.

No `src/`, `config/` or matching file was changed.

## 0. The model in five lines

- **Top level = Pam module manager "Parts" (R).** Each Part is a set of scheduler modules listed in XData
  (`SystemData:/SystemData/Scheduler/ModuleManager/ModuleList`, data in SystemData.bin). Switching Part means
  writing `ModuleManager/@NextModule` = crc32(name), then setting `engine+0x274 = 1`. The switch is run by
  `fn_886345E0` (module-manager state machine). Parts seen: Boot, PracticeGround `0xCFC05A31`, InGame `0x1DCA7285`,
  Online `0x999EBBDC`, PlayerCreator `0xA6F6E957`, LockerRoom `0x1BC17295`, Minigame `0x6D2794E5`, and others.
  Sub-parts use `SubModuleManager/@NextModule`.
- **Screens = RUI scenes (R+D).** The RUI scene manager singleton is `[0x88D45A60]` (`CRUIWrapperEngine`
  side, vtable 0x880EF9A8, Update `fn_887C6080`, Init `fn_887C69C0`). `ChangeScene(name)` from Lua calls
  `fn_887BFDA8(mgr, name, 0, 0, 0)`. Scenes drive themselves through Lua closures and action scripts.
- **All front-end state is XData attributes (R+D).** Lua reads and writes it through
  `ExecuteAttributeRequest(crc32(name), nargs, args…)`. The request table is data: the RUI manager `+0x318`
  points at a relative array of 0x18-byte records with the hash at +0x10 (`fn_8879CD88`). It comes from
  `Media\BinData\BackstageRequests.bin`, which `fn_8877A028` loads. That is why the attribute names are
  not in the executable.
- **The match is described by XData `GameDB:/GameDB/MatchSettings/...` (R+D)** and started with
  `ChangePart("InGame")` (section 3).
- **Live gameplay = the GamePlay engine singleton `[0x88D45B00]` (R)** and its instance vector (section 4).
  The PracticeGround behind the start screen already runs one instance.

## 1. Boot to first menu, in order

### 1.1 Start-up, before any screen

| # | what | where | tag |
|---|---|---|---|
| 1 | CRT start-up and static initialisers (`_DllMainCRTStartup` 0x88562DB0). They return TRUE; no game loop yet | recomp-feasibility.md | R |
| 2 | Game main: `ts4_if_call_seq_fn_889BCA90_885F5228` (0x885F5228). Calls in order: `fn_889BCA90` (early globals) → `fn_889BD310` → `fn_889BD370` → **main loop `fn_889BCB10`** → shutdown (`fn_889BD208`, `fn_889BD2B8`) | 0x885F523C..0x885F5290 | R |
| 3 | `fn_889BD310` → `fn_8862F0B8`: builds the engine object and stores it in `[0x88D45B1C]`. Critical sections, `+0x270` frame = 0, `+0x274/+0x275/+0x276` flags = 0. Registers the core classes (`ts4_name_keys_register_88626F70`) and the game classes (`ts4_name_keys_register_888DB320`, 98 names: CLoadingManager, CTCRActions, CRUIWrapperEngine, CPracticeGround, CGameModeSelector, ...). Writes engine state `+0x278`. Opens **Core.arc** through the file system at `+0x220` (vtbl+0x44) | 0x8862F244..0x8862F280 | R |
| 4 | `fn_889BD370`: `XexGetModuleSection("CORETECH")`, or else `CoreTech_Xenon.bin` (or `UPDATE:\CoreTech_Xenon.bin`), then `CoreTech_Xenon.xml`. These give the XData schema, SystemData, GameDB and the scheduler config (module list). It creates the module manager (`fn_8862C390`, ...) | 0x889BD3A4..0x889BD55C | R |
| 5 | Main loop `fn_889BCB10`: `while (!engine+0x275) { if (engine+0x278 != 4) engine+0x278 = 2; engine+0x270++; engine+0xC->vtbl[2](); }`. Everything else runs from module Update slots and worker threads ("ModuleManager_%i", `fn_88633470`) | 0x889BCB10 | R |
| 6 | Module manager `fn_886345E0` (state at `this+0x2C`, 0..5): when `ModuleManager/@NextModule` differs from the current module, it looks the hash up in the module list (stride 0xA4, hash at +0x90), unloads, configures a `CModuleProcessor` (`fn_88611C00`) and starts its threads. It writes **engine+0x278 = 6** during the steps, **7** briefly, and **2** when the module is running | R |
| 7 | First Part = Boot (I: the XData default; `"Boot"` is referenced by `fn_887C05E0` in the RUI wrapper). Boot package scenes: S4Loading, SMainMenuBackground, S4Disclaimer, S4InGameTransition (D, packages/Boot.json) | I/D |

**engine+0x278 values (R).** 2 = running (main loop); 6 and 7 = module switch in progress (`fn_886345E0`);
**4 = written by `CLoadingManager` slot 12 (`fn_8890BCA0`, 0x8890C17C)** when the Part being started is one
of the in-place parts: PracticeGround, LockerRoom, PlayerCreator, Minigame, Thumbnail, `0x04F0A963`,
`0x3D616581` or `0xF6865E97` (hashes compared at 0x8890C0A4..0x8890C0F0). In that case no S4Loading screen
is shown and `ChangeScene("")` is called. The main loop never overwrites 4, so state 4 lasts until the next
module switch. **State 4 with a rising frame counter is therefore the normal PracticeGround state after
Press Start, not a hang.** The native runs h5 and h8 show exactly that. For every other Part
(InGame included), `CLoadingManager` slots 13 and 14 (`fn_888CD978`, `fn_8890BAF8`) push `S4Loading`.

**Better position probes** for the watch file:

- Current RUI scene (R, from `GetCurrentSceneKey` 0x887A76F0): `scene = [[[[0x88D45A60]+0x1B0]+0x6C]+0x50]`.
  `[scene+0x60]` is a `char*` to the scene name, crc32'd by the game.
  Watch line: `scene_name4 u32 [[[[[0x88D45A60]+0x1B0]+0x6C]+0x50]+0x60]`. It reads the first 4 ASCII bytes
  (`S4Ma`, `S4Ex`, `S4PG`, ...).
- Master pad (R, `GetMasterPad` 0x887A76A0): `[0x88D45A60]+0x314`.
- Pending Part switch: `engine+0x274` (u8) = 1 until the module manager has picked it up.

### 1.2 Screen flow up to the main menu (D)

1. **S4Disclaimer** On: `SceneOn; Wait(5); SceneOff; WaitForTexturePacks(); ChangeScene('S4Loading')`. It waits 5 s and needs no input.
2. **S4Loading** is the loading screen of every Part change. It has no ChangeScene of its own and waits on the
   tracked attributes `Common_LoadingScreen_ResourcesLoaded` and `…PicturesLoaded`. The C++
   `CLoadingManager` (vtable 0x880DB408) puts up the first scene of the next Part when loading ends (R:
   `fn_8890BCA0` calls `fn_887BFDA8`; each Part's first scene comes from
   `SystemData:/SystemData/UIPackDescList/UIPackDesc[@Part=…]/@Scene`, string at 0x880D9178).
3. **S4StartScreen** (PracticeGround package). Its controls and their bindings are written by closure main.68:
   - `|Interaction`.Start → `Start28881`. If `attr(-67464981)[pad] > 3` a message box is shown. Otherwise it sets
     `SetControlAction(|AttractMode)`, `TCR_SetActivePad(pad,true)` and `SetMasterPad(pad)`. Then, if no PS Move,
     it activates `|PrepareLaunchMainMenu`.
   - `|PrepareLaunchMainMenu`.Focus: if `attr 1892929434` (unnamed; I: "profile already set up") is true →
     `ChangeGameStage(MainMenu, PracticeGround)`, `SceneOff`, `ChangeScene('S4MainMenu')`. Otherwise → `|PreLaunchPG`.
   - `|PreLaunchPG`.Focus: `GameSaveAccess_RemoveAllActions()`. On Xenon (`executionPlatform == crc32("Xenon")`)
     `TCR_AskSignIn(master,1,0)` then **wait `TCR_WaitForSignIn()`**. Then `ChangeGameStage(MainMenu, PracticeGround)`.
     If `PadList_IsPadSignedIn[master]`: `TCR_ShowDeviceSelector(master,true,true,0,false)` then **wait
     `TCR_WaitForDeviceSelector()`**, then the save checks (`attr 1519310934[pad]`, `IsAGuestOffline`, message box
     `TriggerMessageBox` + **wait `WaitMessageBox()`**). Then → `|LoginToTitleServer`.
   - `|LoginToTitleServer`.Focus: if signed in and not a guest → `TCR_TriggerLoadSaveCompositeAction(master, …, "SPopupSave", …)`
     and `TitleServer_LoginUserOnly(master)`, then it waits for `Online_Event_LoggedInToTitleServerEvent_Done`
     (tracked). Otherwise it goes straight to `|DiscoveryDLC`.
   - `|DiscoveryDLC` → (`DLC_IsUserDiscovered`) → `|LoadPlayer`: `LoadProfileOptions(master,true)`,
     `ApplyProfileOptions()`, `InitializeUnlockList(master)`, `PushLayer('S4PlayerLoadingIndicator')`.
   - `|DLC_DLL_PreEnter`: `ChangeGameStage(MainMenu, PracticeGround)` and `SetActiveControl('|LoginToTitleServer')`.
   - `|LaunchPG`.Focus: sets `InGame_NextState`, `MatchSettings_PadIndex[0] = pad` and
     `MatchSettings_PlayerType[0] = Human`, calls `EnterPracticeGround()`, waits 0.2 s, then `ChangeScene('S4PG_InGame')`.
     This is the playable practice ground.
   - Idle 120 s on `|Interaction` → `ChangeScene('S4AttractMode')`, a Bink movie (`AttractMode.bik`). The movie
     returns to the start screen when it ends (tracked `VariableCKey == 426031496`), or on A or START.
4. **S4PG_InGame**: in-match practice HUD over the PracticeGround gameplay instance. START opens the menu, as the
   native agent's nav script already notes; `Case22393` → `ChangeScene('S4MainMenu')`.
5. **S4MainMenu**: items in order GameModes, XboxLive, PZone, Unlock, Options (and 3DConfig when 3D is
   available). `curSel = 0` (D). GameModes → `S4MainMenuSubOffline`.

### 1.3 Every external wait, what satisfies it, and the imports involved

| wait | code | satisfied by | imports | tag |
|---|---|---|---|---|
| **Sign-in** (start screen `|PreLaunchPG`, AssignPad, others) | `TCR_AskSignIn` 0x8878A5D8 → `fn_888DA4B0`: if the pad is already in the signed-in list (`[g_ts4_online_state 0x88D458E4]+0x1C`), byte **0x88C46F42** = 1 at once. Otherwise 0x88C46F42 = 0 and a deferred action runs `fn_888C5618` → `XamShowSigninUI` → **`fn_888C0260`**, which blocks: `XamNotifyCreateListener(1)`, then loops `XNotifyGetNext(l, 9 = XN_SYS_UI)` until a notification with param ≠ 0, then until param == 0. Only then 0x88C46F42 = 1. Lua `TCR_WaitForSignIn` (0x88778CD0) keeps waiting while the byte is 0 | report user 0 signed in (`XamUserGetSigninState` ≠ 0) so that no UI is shown, **or** post XN_SYS_UI (id 9) with param 1 then param 0 after `XamShowSigninUI` | XamShowSigninUI, XamNotifyCreateListener, XNotifyGetNext, XamUserGetSigninState | R |
| **Device selector** | `TCR_ShowDeviceSelector` 0x88785B10 / `TCR_WaitForDeviceSelector` 0x88782898 poll `[0x88D45A58]` and the state machine `fn_8888A1B8`: wait for XN_SYS_UI == 0, call `XamShowDeviceSelectorUI`, wait for the overlapped status ≠ 0x3E5 (ERROR_IO_PENDING), call `XamContentGetDeviceData` (type 2 takes another branch, `fn_888DA288`). Byte 0x88C46F6A also takes part | the overlapped completes with a device id and XN_SYS_UI goes back to 0. **Already passes in the native build** | XamShowDeviceSelectorUI, XNotifyGetNext, XamContentGetDeviceData, XamContentGetDeviceState | R |
| Other XN_SYS_UI loops | `fn_8877AF50` (`OnLaunchSignInGameMode`), `fn_88885820` (4 loops), `ts4_if_call_seq_u32_off84_888C2398`; XN id 14 in `fn_888C5338` | same XN_SYS_UI 1→0 pulse | XNotifyGetNext | R |
| Message box | `TriggerMessageBox` 0x88791270 / `WaitMessageBox` 0x887915B0 read XData `UI:/UI/VariableList/VarBool[@Id="MessageBox_Closed"]` | the RUI `SMessageBox` layer is closed with A. The start screen shows one when `attr(-67464981)[pad] > 3`, and the save checks can show one | none (RUI) | R+D |
| Texture packs before every ChangeScene | `WaitForTexturePacks` 0x8877C730 → script engine `[[0x88D41FC4]+0x70]` busy flag (`ts4_loop_get_u32_off10_882109B8`) | the RUI texture-pack loads (archive reads) finish. A file-I/O stall stops **every** scene change | NtReadFile and friends | R |
| ChangePart / ChangeSubPart | 0x88794188 → `fn_887915F0` (and 0x88790FF0) return 1 (retry) while the same script-engine flag is busy | as above | – | R |
| Save and profile | `TCR_TriggerLoadSaveCompositeAction` 0x8879F810; Lua waits for `Common_LoadSaveStatus_Closed`/`_Finished`. `GameSaveAccess_WaitForPendingActions` 0x8877C318 counts the queue at `[0x88D45A0C]`. `TCR_LoadProfileSettingsIfNotLoaded` 0x8879A918 | content create/open and profile read succeed. The native build already answers a profile read/write | XamContentCreate*, XamUserReadProfileSettings, XamUserWriteProfileSettings, XamContentClose | R+D |
| Title server / Live | `TitleServer_LoginUserOnly` 0x88792638; the start screen waits for `Online_Event_LoggedInToTitleServerEvent_Done` only when the user is signed in and not a guest | make the login fail fast, or report the user as a guest/offline so that branch is skipped | NetDll_*, XNetLogonGetTitleID (stub) | D/I |
| Patch check | `Online_Event_UpdatePatchEvent_Done` tracked by the start screen | as above | NetDll_* | D |
| Loading lists | Part loads wait on `SystemData:/SystemData/LoadingList/Loading[@Name=…]/@IsFinished` flags (`LoadingPictures` `fn_889018B8`, `InGameVenueLogo` `fn_888E0148`/`fn_888FFB18`, `Player0N`, `MinigameScene`, ...) | the archive and data loads complete | NtReadFile, XAudio (voice drain, see recomp-build.md) | R |
| Movies | `S4AttractMode` (`AttractMode.bik`) returns when the tracked variable reports the end. In-game transitions use `MemTransitionVenue.bik` (`CInGameVideo` `fn_88903878`) | Bink decode reaches the end, or A/START is pressed (attract only) | – | D/R |
| Pads | `XamInputGetState` through `fn_8827D668`, `fn_88884C88`, `fn_888854B0`, `fn_888BFC20`. Lua `GetButtonState` 0x8877AD18 | scripted pad on user 0 | XamInputGetState | R |

## 2. The Lua-to-C++ interface

**Mechanisms (R).** There are two registration helpers.

- **Global functions** are registered with
  `fn_881E9B28(registry=[0x88D41FC4], std::string name, {fn, 0}, {0, dispatcher 0x881D3FD0})`. The name is
  built by `ts4_assign_text_from_c_string` (0x88152E70) and the handler pointer is stored at `sp+0x60`. A
  thin wrapper `fn_882198D0(reg, name, fn)` also exists. Every handler has the shape
  `int f(LuaCallCtx *c)`; arguments are read from `c->+0x10` (args at `+0x380`, count at `+0x384`, default
  `g_ts4_default_script_value` 0x88D41F84).
- **LuaPlus `LuaObject::Register`** (0x88836968) is used for the core table (`ts4_callback_table_build_887BAF90`)
  and for the Lua standard-library glue.

The RUI per-scene and per-control API (`SetActiveControl`, `SetControlAction`, `PushScene`, `GetValueInt`,
`GetAttribute`, ...) is reached as object methods. Its strings are referenced by `fn_881D3100` and
`fn_881E5230` (R), but the method table was not paired.

600 registrations were extracted (572 game functions in 17 tables, the rest Lua library glue).

### 2.1 The functions the front-end path needs

All tagged R for name and address. Roles come from the name and the Lua call sites; the four marked * were also
read in code.

| function | handler | role |
|---|---|---|
| `ChangeScene` * | 0x887C26D0 | `fn_887BFDA8([0x88D45A60], name, 0,0,0)`: switch the RUI scene |
| `PushLayer` | 0x887BE4D0 | push an overlay scene (message box, loading indicator) |
| `PopMe` | 0x887BF780 | pop the calling layer |
| `ChangePart` * | 0x88794188 | `fn_887915F0`: XData `ModuleManager/@NextModule = hash`, `engine+0x274 = 1` (returns 1 while the script engine is busy) |
| `ChangeSubPart` * | 0x88790FF0 | same with `SubModuleManager/@NextModule` |
| `ChangeGameStage` * | 0x88780F58 | `*([0x88D4593C]+0x60) = (int)arg`. `[0x88D4593C]` is the **CTCRActions** singleton (vtable 0x880DBC04, Update `fn_8890A0B0`, Init `fn_888EE390`). The stage word feeds rich presence and TCR checks (I) |
| `ChangePackage` / `ChangePackageEx` | 0x887C09D8 / 0x887BF510 | load a RUI package |
| `LoadArchive` / `UnloadArchive` | 0x88785E38 / 0x8878DC68 | mount or unmount a .arc |
| `WaitForTexturePacks`, `WaitForTexturePacksUnload`, `IsPackageNotReadyToUse`, `WaitForSceneDeactivation` | 0x8877C730, 0x8877C720, 0x8877C740, 0x8879FE68 | waits (section 1.3) |
| `ExecuteAttributeRequest` | 0x887BAEB0 | `fn_8879CD88(mgr=[0x88D45A60], hash, args)`: look up the data-defined request; returns an attribute object |
| `ExecuteSectionListRequest` / `ExecuteSectionRequest` | 0x887BAC80 / 0x887BADD0 | same for lists. **This is how the player and venue grids are filled**: `PlayerList_ProPlayers`, `PlayerList_LegendPlayers`, `Venue_FullList`, `AIDifficultyListAvailable`, `Common_PadList` |
| `StartTrackingRequest` / `StopTrackingRequest` | 0x887BF7B8 / 0x8879C2A0 | subscribe a scene to attribute changes (`OnUpdate…` events) |
| `GetMasterPad` / `SetMasterPad` / `GetActivePadsCount` | 0x887A76A0 / 0x8879AB70 / 0x887A7668 | pad ownership |
| `ConvertLogicIdToHwPadPort` / `ConvertHwPortToLogicPadId` | 0x887A75F0 / 0x887A7578 | pad id mapping |
| `GetButtonState` / `GetStickState` / `GetAxisState` | 0x8877AD18 / 0x8877AA58 / 0x8877A878 | input queries |
| `GetCurrentSceneKey` | 0x887A76F0 | crc32 of the current scene name (probe in section 1.1) |
| `TCR_AskSignIn` / `TCR_WaitForSignIn` / `TCR_IsUserSignedIn` / `TCR_RequireSignIn` | 0x8878A5D8 / 0x88778CD0 / 0x88782930 / 0x887AED08 | sign-in (section 1.3) |
| `TCR_ShowDeviceSelector` (= `TCR_SelectDevice`) / `TCR_WaitForDeviceSelector` (= `TCR_WaitForSelectDevice`) | 0x88785B10 / 0x88782898 | storage device |
| `TCR_SetActivePad`, `TCR_ResetActivePads`, `TCR_ResetActivePadsExceptMaster`, `DLL_InitMasterPad` | 0x887AE240, 0x8878A730, 0x8877E330, 0x887AE210 | active pads |
| `TCR_TriggerLoadSaveCompositeAction`, `TCR_LoadProfileSettingsIfNotLoaded`, `GameSaveAccess_*` | 0x8879F810, 0x8879A918, … | saves and profile |
| `TCR_GoToStartScreen` | 0x887B6C00 | back to Press Start (on sign-out and similar) |
| `TriggerMessageBox` / `WaitMessageBox` / `DisplayMessageBox` | 0x88791270 / 0x887915B0 / 0x887BE010 | message boxes |
| `EnterPracticeGround` / `InitPracticeGround` / `StartPracticeGround` | 0x8879AD18 / 0x88796770 / 0x887948A8 | practice ground |
| `ResetTeamList` / `ResetPlayerList` / `CleanAllPadList` | 0x88790F68 / 0x88790EE0 / 0x88782AA8 | reset the match settings lists |
| `InitMatchRules` * | 0x88792D48 | rules object = `ts4_hash_find([0x88D458F0], 0x7E35EE14)`: `+4` games per set, `+8` sets, `+0xC..+0xF` four booleans (rules-and-scoring.md 3.6) |
| `Exhibition_SetBall` | 0x88792F38 | same object (ball type) |
| `SetVenue` | 0x887935C8 | XData `GameDB:/GameDB/MatchSettings/CurrentVenue/@Key = key`, then `fn_887934A8` (display venue) |
| `SetMatchIntensity` | 0x887966E0 | called by VenueSelect before Config |
| `PlayerSelectLoadSavedPlayerInfo` / `PlayerSelectUnloadAllCreatedPlayers` | 0x8879BE08 / 0x88793000 | created players in the grid |
| `MatchStart_ResetRewards`, `MatchStart_InitCoachObjectives` | 0x88796640, 0x887964C8 | match start bookkeeping |
| `LoadAllPlayers_InGame` / `UnloadAllPlayers_InGame` | 0x8879B418 / 0x887A4EF0 | player model loading |
| `IsInGameUI` / `IsInLoadingUI` | 0x88778678 / 0x88778688 | state queries |
| `RestartMatchUI` | 0x8877B2A0 | restart from the pause menu |
| `DEBUG_StartRealMatch` / `DEBUG_SimulateMatch` | 0x88787590 / 0x887875C8 | online-session debug (`fn_889A4970` on `g_ts4_session_context`), not the local exhibition path |

### 2.2 Full registration list

The tables below were generated from the executable. The name is the role unless section 2.1 says more.
**FE** marks a function the boot → exhibition → match path calls.

**RUI control object methods (pad stick angles; the RUI per-control API is registered here as object methods)** (registered by `fn_881D3100`)

| name | C++ handler | FE |
|---|---|---|
| `GetLeftStickControllerAngle` | `0x881D2B48` |  |
| `GetRightStickControllerAngle` | `0x881D2BE8` |  |
| `GetDPadControllerAngle` | `0x881D2C88` |  |

**Top Spin School** (registered by `fn_887AF010`)

| name | C++ handler | FE |
|---|---|---|
| `TopSpinSchool_SetFlyoverMode` | `0x887A0770` |  |
| `TopSpinSchool_InitZones` | `0x8879E590` |  |
| `TopSpinSchool_MoveZone` | `0x887A81D8` |  |
| `TopSpinSchool_ToggleZone` | `0x887A8048` |  |
| `TopSpinSchool_ChooseCamera` | `0x887A06A0` |  |
| `TopSpinSchool_SaveProgress` | `0x8879A4C8` |  |

**Practice ground** (registered by `fn_887AF6A0`)

| name | C++ handler | FE |
|---|---|---|
| `EnterPracticeGround` | `0x8879AD18` | **FE** |
| `LoadPreferredPlayer` | `0x887A4CC8` |  |
| `InitPracticeGround` | `0x88796770` | **FE** |
| `ActivateInGameCam` | `0x8877E8E8` |  |
| `StartPracticeGround` | `0x887948A8` | **FE** |

**Player creator, player loading, cameras, facial** (registered by `fn_887AF990`)

| name | C++ handler | FE |
|---|---|---|
| `InitPlayerCreator` | `0x8879F230` |  |
| `PlayerCreatedId_Destroy` | `0x88794908` |  |
| `SaveAll` | `0x887786E8` |  |
| `InitAnimSetup` | `0x88791950` |  |
| `InitAnalyserFramework` | `0x88782EC0` |  |
| `ScaleClothes` | `0x8877B870` |  |
| `ConfigurePCForPlayerArea` | `0x887A31E0` |  |
| `ConfigurePCForLockerRoom` | `0x887A3218` |  |
| `UnloadAllPlayers_InGame` | `0x887A4EF0` | **FE** |
| `LoadAllPlayers_InGame` | `0x8879B418` | **FE** |
| `UnloadAllPlayers_PlayerCreator` | `0x887A0A68` |  |
| `PlayerCreator_PhysicFreeze` | `0x887919A0` |  |
| `PlayerCreatorShadowMode` | `0x88786290` |  |
| `UpdateNeckScaleValue` | `0x8877B9B0` |  |
| `IsBissextile` | `0x8877BA30` |  |
| `IsDeltaActivateEllapsed` | `0x88779900` |  |
| `SetHideWhenLoading` | `0x8877BAF0` |  |
| `SetBodyCutOutMode` | `0x88791D90` |  |
| `ForceUpdateFaceGen` | `0x8878DF80` |  |
| `SetFreezeClothes` | `0x88786330` |  |
| `ActivateAnalyserFrameWork` | `0x8877F4B8` |  |
| `SetWantCommandTimeOut` | `0x8877BBC0` |  |
| `HideHierarchy` | `0x88791C00` |  |
| `ShowHierarchy` | `0x88791CC8` |  |
| `ResetViewport` | `0x88794B28` |  |
| `ApplyPreset` | `0x8877F1B8` |  |
| `DebugSaveDNA` | `0x8877EFC0` |  |
| `SaveDNA` | `0x8877ED90` |  |
| `SaveHairCutDNA` | `0x8877EA50` |  |
| `SaveCommonDNA` | `0x8877E908` |  |
| `SaveOutfitDNA` | `0x8877EB98` |  |
| `LoadDNAOutfit` | `0x8877F2E0` |  |
| `CheckPlayerCreatorQueues` | `0x8877F448` |  |
| `SetPlayerVisibility` | `0x88794C70` |  |
| `SetPlayerBodyVisibility` | `0x88794C18` |  |
| `SetFurnitureVisibility` | `0x88794BC0` |  |
| `SetFreeFormReplayVisibility` | `0x88794B60` |  |
| `SetPlayerRotation` | `0x8877B7F0` |  |
| `InitPlayerReplay` | `0x8877B558` |  |
| `RotatePlayer` | `0x8877B4D0` |  |
| `RotatePlayerReplay` | `0x8877B418` |  |
| `InitFreeFormCamera` | `0x8878A758` |  |
| `InitMainCamera` | `0x887948D8` |  |
| `SetMainCameraConstraints` | `0x8878DD98` |  |
| `StartSmoothCameraMove` | `0x887967A0` |  |
| `FreezeMainCamera` | `0x88782D18` |  |
| `ClearAllCustomPreset` | `0x887832C0` |  |
| `ClearCustomPreset` | `0x88783228` |  |
| `StoreCustomPreset` | `0x88783128` |  |
| `BackupCategoryCustomPreset` | `0x8877BC60` |  |
| `RestoreCategoryCustomPreset` | `0x8877BC28` |  |
| `ClearCategoryCustomPreset` | `0x88779928` |  |
| `HighlightVertex` | `0x887949F8` |  |
| `ResetVertex` | `0x88794A90` |  |
| `MoveVertex` | `0x887860F0` |  |
| `EnterInEditionMode` | `0x88782D78` |  |
| `EnterInSelectMode` | `0x88782E50` |  |
| `BackupHotSpot` | `0x88783090` |  |
| `RestoreHotSpot` | `0x88782FF8` |  |
| `UndoHotSpot` | `0x88782F30` |  |
| `UndoAllHotSpots` | `0x88782F00` |  |
| `SaveHotSpotInHistory` | `0x88782F60` |  |
| `ClearHotSpotHistory` | `0x88783320` |  |
| `HideHotSpots` | `0x88796CA8` |  |
| `ShowHotSpots` | `0x88796C78` |  |
| `Debug_HotSpotsInfosOnOff` | `0x8877BB60` |  |
| `SetDefaultHotSpotPosition` | `0x887832F0` |  |
| `IncreaseFreeFormSlider` | `0x88796BE0` |  |
| `DecreaseFreeFormSlider` | `0x88796B48` |  |
| `BackupFreeFormSlider` | `0x88796AB0` |  |
| `RestoreFreeFormSlider` | `0x887969E8` |  |
| `RestoreAllFreeFormSliders` | `0x88786420` |  |
| `RestoreAllFreeFormSlidersStep2` | `0x887969B8` |  |
| `ResetAllFreeFormSliders` | `0x88796990` |  |
| `FacialSetNumPlayers` | `0x8878AAC0` |  |
| `FacialSetUpdate` | `0x8877B878` |  |
| `FacialStartAnim` | `0x8878A9C8` |  |
| `FacialStopAnim` | `0x8879AD48` |  |
| `FacialResumeAnim` | `0x8877F2C8` |  |
| `TakeThumbnail` | `0x8879AD70` |  |
| `TestThumbnailAnim` | `0x88791AE8` |  |
| `SetAnimationActivation` | `0x8877B948` |  |
| `SetBlendLoopActivation` | `0x8877B8E0` |  |

**Online: sessions, lobby, Live HUDs, leaderboards (TSU), title server, debug match** (registered by `fn_887B1468`)

| name | C++ handler | FE |
|---|---|---|
| `CreateSession` | `0x887953D0` |  |
| `DestroySession` | `0x887893E0` |  |
| `EndSession` | `0x88789368` |  |
| `SearchSession` | `0x887891D8` |  |
| `JoinSession` | `0x88788EF0` |  |
| `QuickSearchSession` | `0x88789008` |  |
| `ModifySessionSettings` | `0x88789698` |  |
| `KickUser` | `0x8878E3D8` |  |
| `IsSessionStarted` | `0x8877BFD8` |  |
| `ConfigureOnlineMatchSettings` | `0x88783CA8` |  |
| `ResetOnlineConfig` | `0x88779968` |  |
| `IsHost` | `0x88780200` |  |
| `IsRemote` | `0x8877BFF8` |  |
| `SetReadyInLobby` | `0x88788E40` |  |
| `UnsetReadyInLobby` | `0x88788D90` |  |
| `SetEveryoneReadyInLobby` | `0x88778D10` |  |
| `IsLobbyFull` | `0x887801E0` |  |
| `OpenHudSignIn` | `0x88788CA0` |  |
| `OpenHudGamercard` | `0x88788B78` |  |
| `OpenHudGamercardInSessionList` | `0x88788A48` |  |
| `OpenHudGamercardInLeaderboards` | `0x887888F8` |  |
| `OpenHudGamercardInLobby` | `0x88788620` |  |
| `OpenHudFriendRequest` | `0x887884F8` |  |
| `OpenHudFriendRequestInLeaderboards` | `0x887883A8` |  |
| `OpenHudFriendRequestInLobby` | `0x88788268` |  |
| `OpenHudPlayerReview` | `0x88788140` |  |
| `OpenHudPlayerReviewInLeaderboards` | `0x88787FF0` |  |
| `OpenHudPlayerReviewInLobby` | `0x88787EB0` |  |
| `IsUserAtLeaderboardRow` | `0x8877FE28` |  |
| `RestartMatch` | `0x887952D0` |  |
| `SendInvitation` | `0x88787BD0` |  |
| `AcceptInvitation` | `0x88787AD8` |  |
| `HasPartyMembers` | `0x8877BCE8` |  |
| `ModifySession` | `0x8877BC98` |  |
| `SetNoDisco` | `0x8877C0A0` |  |
| `SendQuitLobby` | `0x88792A80` |  |
| `Forfeit` | `0x887928A8` |  |
| `IsInASession` | `0x88778CF0` |  |
| `IsAGuest` | `0x88783A18` |  |
| `IsLocalUserAGuest` | `0x8877FCD0` | **FE** |
| `IsAPublicSession` | `0x8877BE98` |  |
| `LockSession` | `0x8877BE30` |  |
| `MutePeer` | `0x88788760` |  |
| `IsLocalUserAllowedToChat` | `0x88778D08` |  |
| `IsLocalUserAllowedToGetUserContent` | `0x88780000` |  |
| `CancelCommands` | `0x8877BEB8` |  |
| `OnlineSparring_SetPlayStyle` | `0x88795138` |  |
| `OnlineSparring_SetDifficulty` | `0x88783960` |  |
| `OnExhib_DisableReadyness` | `0x887876E0` |  |
| `SetPeerLocation` | `0x8878B0E0` |  |
| `HasOpponentForfeited` | `0x88783BD8` |  |
| `TSU_LoadProfileSummaries` | `0x8879BCC8` |  |
| `TSU_GetProfileSummaries` | `0x88783870` |  |
| `TSU_WriteProfileSummaries` | `0x8879BC28` |  |
| `TSU_CheckCharacterChange` | `0x8877FC10` |  |
| `TSU_SaveProfile` | `0x8879BB58` |  |
| `TSU_LoadProfile` | `0x8879BAA8` |  |
| `TSU_UnloadProfile` | `0x88792888` |  |
| `TSU_UpdateProfile` | `0x8879B9F8` |  |
| `TSU_UpdatePlayerRank` | `0x8878BD20` |  |
| `TSU_UpdateCreatedPlayerStats` | `0x8878BCE8` |  |
| `TSU_SetLocalPlayerInLeaderboard` | `0x88783728` |  |
| `TSU_ReadStatsByRank` | `0x8878BAA0` |  |
| `TSU_ReadStatsAroundUser` | `0x8878B820` |  |
| `TSU_InitFriendsLeaderboard` | `0x8878B600` |  |
| `TSU_ResetFriendsLeaderboard` | `0x8877FBC0` |  |
| `TSU_FillFriendsLeaderboard` | `0x88783620` |  |
| `TSU_ReadStatsByIdInLeaderboards` | `0x8878B450` |  |
| `TSU_ReadStatsByIdInLobby` | `0x8878B250` |  |
| `TSU_ResetSeasonRankHistory` | `0x887835E8` |  |
| `TSU_CopyLocalPlayerInLeaderboards` | `0x8877FAD0` |  |
| `TSU_VerifyLeaderboardStrings` | `0x88787900` |  |
| `TSU_VerifyPlayerStats` | `0x88787750` |  |
| `TSU_RefreshTournamentSessions` | `0x8877FA98` |  |
| `TSU_ServerRequest_CheckVersion` | `0x887786C8` |  |
| `TSU_IsThereEnoughTimeLeftBeforeEndOfSeason` | `0x887835C8` |  |
| `TSU_IsThereEnoughTimeLeftToEnterLobbyBeforeEndOfSeason` | `0x887835A8` |  |
| `TSU_DeclareMatchAsOfficial` | `0x88787718` |  |
| `TSU_CopyLocalStatToNetDB` | `0x8877F970` |  |
| `TSU_ReplaceSearchResultsWithPerRoundStats` | `0x8877F818` |  |
| `TSU_ReplaceSearchResultsWithSessionStats` | `0x8877F758` |  |
| `TSU_HasWonLastMatch` | `0x88783568` |  |
| `TSU_ForfeitInLobby` | `0x88798C60` |  |
| `TSU_FillPlayerSheet` | `0x887A4F28` |  |
| `TSU_HasPairingStarted` | `0x8877BF58` |  |
| `TSU_Debug_AddFakePlayerToLobby` | `0x88783BA0` |  |
| `TSU_Debug_RemoveFakePlayerFromLobby` | `0x88783AF8` |  |
| `TSU_Debug_EndSeason` | `0x8877FD88` |  |
| `TSU_Debug_SendEndSeasonToAll` | `0x88787E10` |  |
| `TSU_Debug_IndDecLobbyTimer` | `0x88787CE8` |  |
| `CG_AddAIPlayerToLobby` | `0x887786C0` |  |
| `CG_RemoveAIPlayerFromLobby` | `0x887786B8` |  |
| `CG_Reset` | `0x88779960` |  |
| `CG_GenerateCPUResults` | `0x88778CE8` |  |
| `CG_AskForCharacter` | `0x88787638` |  |
| `CG_MakeSlotPublic` | `0x88789528` |  |
| `OnlinePS3_IsWorldTourEnabled` | `0x887786B0` |  |
| `OnlinePS3_IsPlayerCreatedEnabled` | `0x887786A8` |  |
| `OnlinePS3_IsInvitationEnabled` | `0x887786A0` |  |
| `TitleServer_Login` | `0x88795020` |  |
| `TitleServer_Logout` | `0x88792820` |  |
| `TitleServer_QueryRoundInfo` | `0x88794ED8` |  |
| `TitleServer_DownloadPlayerInfo` | `0x887926D8` |  |
| `TitleServer_QueryNews` | `0x88778698` |  |
| `TitleServer_LoginUserOnly` | `0x88792638` | **FE** |
| `TitleServer_IsLoggedIn` | `0x8877F6B8` | **FE** |
| `TitleServer_GetPatch` | `0x88794FE8` |  |
| `ProChallenge_LoadProfile` | `0x8879B948` |  |
| `ProChallenge_SaveProfile` | `0x8879B898` |  |
| `ProChallenge_TitleServer_Login` | `0x88794E38` |  |
| `ProChallenge_TitleServer_QueryProPlayerList` | `0x88794CC8` |  |
| `ProChallenge_ReadStatsByRank` | `0x8878AF60` |  |
| `ProChallenge_ReadStatsByRankInMiniLeaderboard` | `0x8878ADE0` |  |
| `ProChallenge_GetMyStats` | `0x887874E0` |  |
| `ProChallenge_IsUserAtLeaderboardRow` | `0x8877F530` |  |
| `ProChallenge_OpenHudGamercardInLeaderboards` | `0x88787390` |  |
| `ProChallenge_OpenHudPlayerReviewInLeaderboards` | `0x88787240` |  |
| `ProChallenge_OpenHudFriendRequestInLeaderboards` | `0x887870F0` |  |
| `ProChallenge_ReadStatsAroundUser` | `0x8878AC40` |  |
| `ProChallenge_ReadStatsFriends` | `0x8878AB50` |  |
| `ProChallenge_IsThereEnoughTimeLeftBeforeEndOfSeason` | `0x88783520` |  |
| `GlobalUserRanking_ReadStatsByRank` | `0x88786DA8` |  |
| `GlobalUserRanking_ReadStatsAroundId` | `0x887869F0` |  |
| `GlobalUserRanking_ReadStatsFriends` | `0x887865B0` |  |
| `DEBUG_SimulateMatch` | `0x887875C8` | **FE** |
| `DEBUG_StartRealMatch` | `0x88787590` | **FE** |

**Minigames** (registered by `fn_887B37A8`)

| name | C++ handler | FE |
|---|---|---|
| `Minigame_SetState` | `0x887A86F0` |  |
| `Minigame_HideUnusedTracksides` | `0x88795570` |  |
| `Minigame_IngameDialogueClose` | `0x8878BDD0` |  |
| `Minigame_PrepareInGame` | `0x88795548` |  |
| `Minigame_ChangeDisplayGameMode` | `0x88792CB8` |  |
| `Minigame_Cleanup` | `0x887897F8` |  |
| `Minigame_UpdateCamera` | `0x88798C98` |  |

**King of the Court** (registered by `fn_887B3BB0`)

| name | C++ handler | FE |
|---|---|---|
| `KingOfTheCourt_PrepareIngame` | `0x887955A0` |  |
| `KingOfTheCourt_Init` | `0x88789860` |  |
| `KingOfTheCourt_Restart` | `0x88789828` |  |
| `KingOfTheCourt_PrepareNextMatch` | `0x88797198` |  |
| `KingOfTheCourt_StartMatch` | `0x88798CC8` |  |
| `KingOfTheCourt_NotifyEndOfMatch` | `0x8878BE18` |  |
| `KingOfTheCourt_UnloadAllPlayers` | `0x88779A20` |  |
| `KingOfTheCourt_WaitForUnloadPlayers` | `0x887799F0` |  |
| `KingOfTheCourt_StartLoadingPlayers` | `0x887799C0` |  |
| `KingOfTheCourt_WaitForPlayersLoading` | `0x88797168` |  |
| `KingOfTheCourt_CheckAndIncrementPlayerKingOfTheCourtSeasons` | `0x8879BD68` |  |

**Match rules, sparring objectives** (registered by `fn_887B41E8`)

| name | C++ handler | FE |
|---|---|---|
| `InitMatchRules` | `0x88792D48` | **FE** |
| `SPT_TriggerObjective` | `0x887A0B60` |  |
| `SPT_FinishObjective` | `0x887955C8` |  |

**Exhibition player select** (registered by `fn_887B43C0`)

| name | C++ handler | FE |
|---|---|---|
| `PlayerSelectLoadSavedPlayerInfo` | `0x8879BE08` | **FE** |
| `PlayerSelectUnloadAllCreatedPlayers` | `0x88793000` | **FE** |
| `Exhibition_SetBall` | `0x88792F38` | **FE** |

**Cameras, venue, viewport, video player** (registered by `fn_887B4598`)

| name | C++ handler | FE |
|---|---|---|
| `ChooseInGameCamera` | `0x8879FA30` |  |
| `ChooseFreeCamera` | `0x8878BE48` |  |
| `ChooseFlyoverCamera` | `0x88789D88` |  |
| `SetVenue` | `0x887935C8` | **FE** |
| `ViewportSelectCamera` | `0x887A9CC8` |  |
| `ViewportSelectShot` | `0x887A9B38` |  |
| `ViewportCameraIncRotateY` | `0x887A9670` |  |
| `ViewportCameraIncZoom` | `0x887A9518` |  |
| `ViewportCameraSetFov` | `0x887A93C0` |  |
| `ViewportTargetIncRotateY` | `0x887A99E0` |  |
| `ViewportCameraSetDecal` | `0x887A97C8` |  |
| `VideoPlayerLoad` | `0x887A91F8` |  |
| `VideoPlayerDestroy` | `0x887A9108` |  |
| `VideoPlayerPlay` | `0x887A8FB0` |  |
| `VideoPlayerStop` | `0x887A8CC8` |  |
| `VideoPlayerPause` | `0x887A8EC0` |  |
| `VideoPlayerResume` | `0x887A8DD0` |  |
| `VideoPlayerIsPause` | `0x887A8BD8` |  |
| `VideoPlayerSetLoop` | `0x887A8AB0` |  |
| `VideoPlayerIsLoop` | `0x887A89C8` |  |
| `VideoPlayerSetTrackingVariable` | `0x887A8898` |  |
| `ChangeHierarchyLifeTime` | `0x8879FA60` |  |

**Academy** (registered by `fn_887B51D8`)

| name | C++ handler | FE |
|---|---|---|
| `Academy_InitProfile` | `0x8879C0C0` |  |
| `Academy_SaveProfile` | `0x8879BFF8` |  |
| `Academy_UpdateResults` | `0x88789DB8` |  |

**TCR (sign-in, storage, saves), pads, DLC, GameSaveAccess** (registered by `fn_887B6CB8`)

| name | C++ handler | FE |
|---|---|---|
| `TCR_ResetActivePads` | `0x8878A730` | **FE** |
| `TCR_ResetActivePadsExceptMaster` | `0x8877E330` | **FE** |
| `TCR_SetActivePad` | `0x887AE240` | **FE** |
| `TCR_SelectDevice` | `0x88785B10` | **FE** |
| `TCR_AskSignIn` | `0x8878A5D8` | **FE** |
| `TCR_RequireSignIn` | `0x887AED08` | **FE** |
| `TCR_WaitForSignIn` | `0x88778CD0` | **FE** |
| `TCR_WaitForSelectDevice` | `0x88782898` | **FE** |
| `TCR_IsUserPrivilegeSet` | `0x8877E1B8` | **FE** |
| `TCR_IsUserSignedIn` | `0x88782930` | **FE** |
| `TCR_CheckStorageCapacity` | `0x88778658` |  |
| `TCR_IsStorageCapacityOK` | `0x88778650` |  |
| `TCR_ShowDeviceSelector` | `0x88785B10` | **FE** |
| `TCR_WaitForDeviceSelector` | `0x88782898` | **FE** |
| `TCR_TriggerSaveEndPC` | `0x8879E960` |  |
| `TCR_WaitSaveEndPC` | `0x887A8480` |  |
| `TCR_LoadPlayerCreated` | `0x8879E758` |  |
| `TCR_SavePlayerCreated` | `0x8878D840` |  |
| `TCR_SaveLoadProfileSettings` | `0x8877A5F8` |  |
| `TCR_DeleteSave` | `0x88790AE8` |  |
| `TCR_SaveProfileSettings` | `0x8877E0B0` |  |
| `TCR_SaveProfileOptions` | `0x887785E0` |  |
| `TCR_IsPCExist` | `0x8879EE28` |  |
| `TCR_UpdateDNASave` | `0x88794220` |  |
| `TCR_UpdateThumbnail` | `0x88791688` |  |
| `TCR_LoadProfileSettingsIfNotLoaded` | `0x8879A918` | **FE** |
| `TCR_TryLoadProfileSettings` | `0x8879AA40` | **FE** |
| `TCR_IsSavePresent` | `0x8877B2C8` |  |
| `TCR_IsPlayerLoaded` | `0x887909B8` |  |
| `TCR_TriggerLoadSaveCompositeAction` | `0x8879F810` | **FE** |
| `TCR_TriggerLoadSaveCompositeActionWithParam` | `0x8879F5D0` | **FE** |
| `TCR_GoToStartScreen` | `0x887B6C00` | **FE** |
| `TRC_CanBeSaved` | `0x88778640` |  |
| `TRC_PartySessions` | `0x88785D48` |  |
| `TCR_ListMarketPlaceContents` | `0x88778638` |  |
| `TCR_LoadMarketPlaceContentPro` | `0x88778628` |  |
| `TCR_LoadMarketPlaceContentProFat` | `0x88778630` |  |
| `TCR_LoadMarketPlaceContentTextureFat` | `0x88778620` |  |
| `TCR_LoadMarketPlaceContentTexture` | `0x88778618` |  |
| `TCR_UnloadMarketPlaceContentTexture` | `0x88778608` |  |
| `TCR_LoadMarketPlaceThumbnailPack` | `0x88778600` |  |
| `TCR_UnloadMarketPlaceThumbnailPack` | `0x887785F8` |  |
| `TCR_ReleaseMarketPlaceContentTexture` | `0x88778610` |  |
| `TCR_OutfitContainsDLC` | `0x8877A600` |  |
| `TCR_IsProDownloadContentEnabled` | `0x887785F0` |  |
| `TCR_IsClothDownloadContentEnabled` | `0x887785E8` |  |
| `SetMasterPad` | `0x8879AB70` | **FE** |
| `TCR_SetMasterPadForInvitation` | `0x887AE318` |  |
| `GameSaveAccess_LoadTemporaryPlayers` | `0x88789A48` |  |
| `GameSaveAccess_LoadTemporaryPlayersFromId` | `0x88789898` |  |
| `GameSaveAccess_LoadPlayer` | `0x8879F440` |  |
| `GameSaveAccess_RemoveAllActions` | `0x88783E88` | **FE** |
| `GameSaveAccess_WaitForPendingActions` | `0x8877C318` | **FE** |
| `GameSaveAccess_LoadPreferredPlayer` | `0x887A57B0` |  |
| `GameSaveAccess_ChangePreferredPlayer` | `0x88780370` |  |
| `GameSaveAccess_SetSaving` | `0x8877C2A0` | **FE** |
| `SavingNewCreatedPlayer` | `0x8877C198` |  |
| `TCR_CreateNewTournament` | `0x8877A768` |  |
| `TCR_SaveTournament` | `0x8877A710` |  |
| `TCR_LoadTournament` | `0x8877A708` |  |
| `TCR_ListTournaments` | `0x8877A700` |  |
| `TCR_TournamentHasPC` | `0x8877A6F8` |  |
| `TCR_IsTournamentExist` | `0x88778648` |  |
| `DLC_DumpCacheContent` | `0x8877C370` |  |
| `DLC_DiscoveryUser` | `0x88789C50` | **FE** |
| `DLC_IsUserDiscovered` | `0x88780C90` | **FE** |
| `DLC_EnumeratePlayers` | `0x887AD360` |  |
| `DLC_EnumerateOutfits` | `0x887AD028` |  |
| `DLC_EnumerateOutfitBrands` | `0x887AD1B8` |  |
| `DLC_IsLoadedOutfitTexture` | `0x88780BD0` |  |
| `DLC_LoadPlayerInfo` | `0x88780990` |  |
| `DLC_LoadPlayer` | `0x88793230` |  |
| `DLC_UnmountLoadedPlayers` | `0x88780850` |  |
| `DLC_UnmountUnusedOffers` | `0x88783F88` |  |
| `DLC_UnmountAllOffers` | `0x88789BF8` |  |
| `DLC_ShowMarketplaceUI` | `0x88780758` |  |
| `DLC_CheckNewContent` | `0x88793030` |  |
| `DLC_CloseAllDlcOutfits` | `0x8879BF20` |  |
| `DLC_OpenOutfitArchive` | `0x887806A0` |  |
| `DLC_UseOutfit` | `0x88783E98` |  |
| `DLC_NewGameDLLNeeded` | `0x8877C360` |  |
| `DLC_RestartGameNewDLL` | `0x8877C350` |  |
| `DLL_IsDLLGame` | `0x88778CA0` |  |
| `DLL_InitMasterPad` | `0x887AE210` | **FE** |
| `GlobalInfo_IsProfileEventTriggered` | `0x8879A730` |  |
| `GlobalInfo_SetProfileEventTriggered` | `0x8879A4F8` |  |
| `TCR_CheckDeviceSpace` | `0x8877A608` |  |

**UI core: attribute requests, text, pads, unit conversion (LuaObject::Register)** (registered by `ts4_callback_table_build_887BAF90`)

| name | C++ handler | FE |
|---|---|---|
| `SetModuleUpdateable` | `0x88789F10` |  |
| `GetWString` | `0x887ABA30` |  |
| `GetTextWidth` | `0x887A5E48` |  |
| `CreateCKey` | `0x887A7790` |  |
| `GetCrcDictString` | `0x887AB978` |  |
| `ExecuteAttributeRequest` | `0x887BAEB0` | **FE** |
| `ExecuteSectionListRequest` | `0x887BAC80` | **FE** |
| `ExecuteSectionRequest` | `0x887BADD0` | **FE** |
| `SetStringTableValue` | `0x88789E40` |  |
| `GetCurrentSceneKey` | `0x887A76F0` | **FE** |
| `GetMasterPad` | `0x887A76A0` | **FE** |
| `GetActivePadsCount` | `0x887A7668` | **FE** |
| `ConvertLogicIdToHwPadPort` | `0x887A75F0` | **FE** |
| `ConvertHwPortToLogicPadId` | `0x887A7578` | **FE** |
| `GetGamerTag` | `0x8877CF20` |  |
| `FormatText` | `0x887AB820` |  |
| `RoundInteger` | `0x887A7508` |  |
| `Ceil` | `0x887A74A8` |  |
| `ConvertInteger` | `0x887AB768` |  |
| `ConvertLength` | `0x887AB688` |  |
| `ConvertSpeed` | `0x887A73E0` |  |
| `ConvertWeight` | `0x887A7318` |  |
| `ConvertTemperature` | `0x887A7248` |  |
| `ConvertNumber` | `0x887AB5A0` |  |
| `ConvertOrdinalNumber` | `0x887AB4B0` |  |
| `ConvertDecimal` | `0x887AB3C8` |  |
| `ConvertDate` | `0x887AB200` |  |
| `ConvertDateTime` | `0x887AB068` |  |
| `GetDateFormatString` | `0x887AB358` |  |
| `GetCurrentLengthUnit` | `0x887AB030` |  |
| `GetCurrentSpeedUnit` | `0x887AAFF8` |  |
| `GetCurrentWeightUnit` | `0x887AAFC0` |  |
| `GetCurrentTemperatureUnit` | `0x887AAF88` |  |
| `GetCurrentLanguage` | `0x887A7128` |  |
| `IsWStringGamerTagTCR` | `0x887A6F68` |  |
| `BuildShortPlayerName` | `0x887AACE0` |  |
| `GetCurrentTimeMs` | `0x887A5E08` |  |
| `GetCustomHelpText` | `0x887AACA8` |  |
| `SetCustomHelpText` | `0x88789DE8` |  |
| `HairCuts_GetPresetCurrent` | `0x887A6ED8` |  |
| `HairCuts_SetPresetCurrent` | `0x8877CE80` |  |
| `HairCuts_GetPresetIDFromIndex` | `0x887A6E08` |  |
| `HairCuts_GetUICodeFromCurrent` | `0x887A6D50` |  |
| `HairCuts_GetInfoFromUICode` | `0x887A6AC8` |  |
| `FacialHair_GetPresetCurrent` | `0x887A6A78` |  |
| `FacialHair_SetPresetCurrent` | `0x8877CE20` |  |
| `FacialHair_GetPresetIDFromIndex` | `0x887A69C8` |  |
| `FacialHair_GetUICodeFromCurrent` | `0x887A6930` |  |
| `FacialHair_GetInfoFromUICode` | `0x887A67A8` |  |
| `WristbandLeft_GetPresetCurrent` | `0x887A6718` |  |
| `WristbandLeft_SetPresetCurrent` | `0x8877CD80` |  |
| `WristbandLeft_GetPresetIDFromIndex` | `0x887A6648` |  |
| `WristbandLeft_GetUICodeFromCurrent` | `0x887A6590` |  |
| `WristbandLeft_GetInfoFromUICode` | `0x887A6368` |  |
| `WristbandRight_GetPresetCurrent` | `0x887A62D8` |  |
| `WristbandRight_SetPresetCurrent` | `0x8877CCE0` |  |
| `WristbandRight_GetPresetIDFromIndex` | `0x887A6208` |  |
| `WristbandRight_GetUICodeFromCurrent` | `0x887A6150` |  |
| `WristbandRight_GetInfoFromUICode` | `0x887A5F28` |  |
| `LockerRoom_FillOutfitTable` | `0x887AE4F0` |  |
| `WorldTour_GradeFromScore` | `0x887A5D80` |  |
| `WorldTour_MinScoreFromGrade` | `0x887A5CF8` |  |
| `Career_GetTournamentStatus` | `0x887A5C88` |  |
| `PlayerEvolution_GetXPCostFromLevel` | `0x887A5C00` |  |

**Player area / locker room** (registered by `fn_887BBD10`)

| name | C++ handler | FE |
|---|---|---|
| `InitPlayerArea` | `0x8879B690` |  |
| `ReleasePlayerArea` | `0x887A0AA0` |  |
| `SaveDNAInLockerRoom` | `0x8879B5E8` |  |
| `PlayerAreaLoadCreatedPlayer` | `0x8879B788` |  |
| `InitLockerRoom` | `0x887A3310` |  |
| `InitCategories` | `0x887970D8` |  |
| `InitOutfitType` | `0x88798BD0` |  |
| `AddLoadRequest` | `0x88783488` | **FE** |
| `StartLoading` | `0x887BBCD8` | **FE** |
| `StopLoading` | `0x88783450` |  |
| `UnloadAllOutfits` | `0x887A3250` |  |
| `ExitLockerRoom` | `0x88797088` |  |
| `FillItemInfosUI` | `0x887A3280` |  |
| `ResetDNA` | `0x8878E0F8` |  |
| `Haircut_UpdateBrandList` | `0x88798978` |  |
| `SportsGear_SavePresetInDnaOutfit` | `0x88796E80` |  |
| `TopOutfit_SaveClothType` | `0x88796CD8` |  |
| `TopOutfit_BackupClothType` | `0x88786500` |  |
| `TopOutfit_RestoreClothType` | `0x88786450` |  |
| `BottomOutfit_SaveClothType` | `0x88783350` |  |
| `Racket_SaveBrandBag` | `0x8879F328` |  |
| `Racket_BackupBrandBag` | `0x8879B520` |  |
| `Racket_RestoreBrandBag` | `0x8879B470` |  |
| `UpdateOutfitAgent` | `0x88792278` |  |

**UI tracking requests** (registered by `fn_887BFBA0`)

| name | C++ handler | FE |
|---|---|---|
| `StartTrackingRequest` | `0x887BF7B8` | **FE** |
| `StopTrackingRequest` | `0x8879C2A0` | **FE** |

**Game flow: parts, packages, archives, options, input state, unlocks, career, rewards** (registered by `fn_887C0AF0`)

| name | C++ handler | FE |
|---|---|---|
| `ChangePart` | `0x88794188` | **FE** |
| `ChangeSubPart` | `0x88790FF0` | **FE** |
| `AskForCoreRestart` | `0x8877B118` |  |
| `LaunchExe` | `0x8879ED98` |  |
| `OnLaunchSignInGameMode` | `0x8877AF50` |  |
| `SetCurrentLanguageId` | `0x88790E78` |  |
| `CleanAllPadList` | `0x88782AA8` | **FE** |
| `BackupGameDBOptions` | `0x8877E818` |  |
| `RestoreGameDBOptions` | `0x8877E748` |  |
| `ApplyProfileOptions` | `0x88794158` | **FE** |
| `SwitchDimension` | `0x8877E630` |  |
| `Is3DAccessible` | `0x887798F0` |  |
| `Is3DOn` | `0x887798E0` |  |
| `LoadProfileOptions` | `0x8879AC38` | **FE** |
| `LoadDefaultProfileOptions` | `0x88782B90` |  |
| `UnloadProfileOptions` | `0x88782BC0` |  |
| `ShowUIAchievements` | `0x8877B138` |  |
| `ChangePackage` | `0x887C09D8` | **FE** |
| `LoadArchive` | `0x88785E38` | **FE** |
| `UnloadArchive` | `0x8878DC68` | **FE** |
| `ResetTeamList` | `0x88790F68` | **FE** |
| `ResetPlayerList` | `0x88790EE0` | **FE** |
| `SetMatchIntensity` | `0x887966E0` | **FE** |
| `IsThereActiveSignedUser` | `0x887910F0` |  |
| `IsInGameUI` | `0x88778678` | **FE** |
| `IsInLoadingUI` | `0x88778688` | **FE** |
| `IsInGameRewardSupported` | `0x887911B8` | **FE** |
| `UnloadAllPlayerPortraits` | `0x887A0A40` |  |
| `UnloadAllTemporaryPlayerPortraits` | `0x887A0A18` |  |
| `RestartMatchUI` | `0x8877B2A0` | **FE** |
| `ChangePackageEx` | `0x887BF510` | **FE** |
| `CheckDLCOk` | `0x887940C8` |  |
| `BackupCurrentSettings` | `0x88782CB0` |  |
| `SettingsHaveChanged` | `0x8877B1F0` |  |
| `TriggerMessageBox` | `0x88791270` | **FE** |
| `WaitMessageBox` | `0x887915B0` | **FE** |
| `GetButtonState` | `0x8877AD18` | **FE** |
| `GetStickState` | `0x8877AA58` | **FE** |
| `GetAxisState` | `0x8877A878` | **FE** |
| `IsMoveController` | `0x8877A870` | **FE** |
| `IsNavController` | `0x8877A868` |  |
| `IsMoveCalibrated` | `0x8877A860` |  |
| `BindingExists` | `0x8877A858` |  |
| `IsBoundToMoveController` | `0x8877A850` |  |
| `IsMoveControllerReady` | `0x8877A848` | **FE** |
| `IsAnyMoveConnected` | `0x88778670` |  |
| `IsActiveMoveConnected` | `0x88778668` |  |
| `ForceMoveRecalibrate` | `0x8877A840` |  |
| `CancelMoveRecalibrate` | `0x8877A838` |  |
| `EnableMoveBinding` | `0x8877A7E0` |  |
| `EnableMoveCalibration` | `0x8877A788` |  |
| `ResetAllMoveBindings` | `0x88778660` |  |
| `InitializeUnlockList` | `0x887A0900` | **FE** |
| `TriggerContentUnlock` | `0x887AF4E0` |  |
| `AddRewardUnlock` | `0x887AF390` |  |
| `AddRewardQuantity` | `0x88798708` |  |
| `IsUnlocked` | `0x887A3090` |  |
| `MatchStart_ResetRewards` | `0x88796640` | **FE** |
| `EndOfMatch_CheckForRewards` | `0x887B8AD0` |  |
| `AreThereRewardsForPlayers` | `0x887965D8` |  |
| `AreThereRewardsForEventRecap` | `0x887965D0` |  |
| `Debug_ResetAllUnlocks` | `0x887A3060` |  |
| `Debug_UnlockAll` | `0x887B6030` |  |
| `Debug_SetEasyAchievements` | `0x8879ED08` |  |
| `IncAndCheckSparringPartnerTrainingsCount` | `0x8879EC78` |  |
| `AddAchievement` | `0x887A0808` |  |
| `Career_Forfeit` | `0x88790DA0` |  |
| `Career_SkipMonths` | `0x8879EA80` |  |
| `Career_FillCalendar` | `0x8877E4C8` |  |
| `Career_InitNextMatch` | `0x8877A770` |  |
| `Coaches_InitCoachList` | `0x8877E360` |  |
| `MatchStart_InitCoachObjectives` | `0x887964C8` |  |
| `EndOfPoint_CheckCoachObjectives` | `0x88794098` |  |
| `EndOfMatch_CheckCoachObjectives` | `0x8879AC08` |  |
| `EndOfMatch_ApplyCoachProgress` | `0x887B8AA0` |  |
| `NotifyRichPresence` | `0x88782A00` |  |
| `NotifyRichPresenceByPart` | `0x88796668` |  |
| `Credits_BuildTable` | `0x887ACE28` |  |

**RUI scene control, sound, texture packs, memory/debug** (registered by `fn_887C2798`)

| name | C++ handler | FE |
|---|---|---|
| `DumpSceneHierarchy` | `0x887A0F78` |  |
| `Pause` | `0x887786F0` | **FE** |
| `DisableController` | `0x8877C828` |  |
| `SetTextValue` | `0x887A9E48` |  |
| `PlaySound` | `0x8879FD18` |  |
| `StopSound` | `0x8877C668` |  |
| `SetSoundVolume` | `0x8877C560` |  |
| `TraceDumpStart` | `0x887786E0` |  |
| `TraceDumpStop` | `0x887786D8` |  |
| `LoadTexturePack` | `0x887BA738` | **FE** |
| `LoadTextureFile` | `0x887BA490` |  |
| `UnloadTexturePack` | `0x887A0ED0` |  |
| `IsTexturePackExist` | `0x8879FBD8` |  |
| `IsImperialUnits` | `0x8877C818` |  |
| `IsWideScreen` | `0x8877C808` |  |
| `IsPackageNotReadyToUse` | `0x8877C740` | **FE** |
| `WaitForTexturePacks` | `0x8877C730` | **FE** |
| `WaitForTexturePacksUnload` | `0x8877C720` | **FE** |
| `WaitForSceneDeactivation` | `0x8879FE68` | **FE** |
| `IsInDebugMode` | `0x88779A88` |  |
| `IsAGuestOffline` | `0x88783FD8` | **FE** |
| `PopMe` | `0x887BF780` | **FE** |
| `IsPopupPushed` | `0x8877C4A8` |  |
| `SelectPluginDataPart` | `0x887937F8` |  |
| `IsWorkingFlagActivated` | `0x887936A8` |  |
| `IsGameFeatureActivated` | `0x8877C3E8` |  |
| `DisplayMessageBox` | `0x887BE010` | **FE** |
| `DisplayInfoBox` | `0x887BDC00` |  |
| `PushLayer` | `0x887BE4D0` | **FE** |
| `ChangeScene` | `0x887C26D0` | **FE** |
| `ChangeGameStage` | `0x88780F58` | **FE** |
| `ChangeStringTable` | `0x887AA340` |  |
| `Core_Memory_DumpStatus` | `0x8878E600` |  |
| `Core_Memory_EnableTracking` | `0x8877C398` |  |
| `Core_Memory_TrackHeap` | `0x8878E518` |  |
| `Core_Memory_DisplayMemoryStatus` | `0x88793610` |  |
| `Core_Memory_CheckMemory` | `0x8878E480` |  |
| `DataMining_PrintCounter8` | `0x8877C390` |  |
| `DataMining_PrintCounter16` | `0x8877C388` |  |
| `DataMining_PrintCounter32` | `0x8877C380` |  |
| `DataMining_PrintCounterSingle` | `0x8877C378` |  |
| `DataMining_PrintAllCounters` | `0x88779A50` |  |
| `DataMining_PrintPlayerCounter8` | `0x88780E90` |  |
| `DataMining_PrintPlayerCounter16` | `0x88780DC8` |  |
| `DataMining_PrintAllPlayerCounters` | `0x88780D28` |  |
## 3. Starting a match

### 3.1 What ExhibitionConfig's confirm does (D, with the C++ side R)

In `S4ExhibitionConfig`, pressing **A on any rules line** jumps to the `|LaunchGame` control: the actions
`A10199`, `A10245`, `A10262`, `A10309` and `A10363` each do `SetActiveControl('|Values|..|..|LaunchGame')`.
`|LaunchGame`.Focus = `GotFocus10366` runs `__Action_28`, then `__Action_29`, then the "Validation" sound:

```lua
-- __Action_28 (main.28): reset 15 cached attributes, then name the first InGame scene
RequestCache[0xF173DE4C]:SetValueInt(0)   RequestCache[0xE3C671A2]:SetValueInt(-1)
RequestCache[0x5B7A16C7]:SetValueInt(-1)  RequestCache[0xC6AD2E7E]:SetValueInt(-1)
RequestCache[0xF41A4B0A]:SetValueInt(0)   RequestCache[0xCD9777CF]:SetValueInt(0)
RequestCache[0xDAEC638C]:SetValueInt(0)   RequestCache[0xBE8D0E45]:SetValueInt(0)
RequestCache[0xB62ABDA7]:SetValueInt(-1)  RequestCache[0x7FF1F340]:SetValueInt(0)
RequestCache[0x0278E80D]:SetValueInt(-1)  RequestCache[0x8B09463A]:SetValueInt(0)
RequestCache[0xFC0E76AC]:SetValueInt(0)   RequestCache[0x65072716]:SetValueInt(0)
RequestCache[0x12001780]:SetValueInt(0)
ExecuteAttributeRequest(0xC67203FA, 1, crc32"InGame"):SetValueCKey(crc32"S4InGameIntro")  -- I: "first scene of Part InGame"
-- __Action_29 (main.29)
return ChangePart(crc32"InGame")           -- 0x1DCA7285
```

That is the whole launch. **There is no dedicated "start match" C++ entry: the match starts because Part
InGame starts.** The C++ side (R):

1. `ChangePart` 0x88794188 → `fn_887915F0`: XData `SystemData/Scheduler/ModuleManager/@NextModule = 0x1DCA7285`,
   then `engine([0x88D45B1C])+0x274 = 1`.
2. The module manager `fn_886345E0` sees the new hash, tears down PracticeGround and builds the InGame module
   set. Engine state goes to 6, then 7, then 2.
3. `CLoadingManager` (vtable 0x880DB408) shows `S4Loading` (slots 13 and 14). Slot 17 `fn_8890B068` reads
   `GameDB:/GameDB/MatchSettings/PlayerList`, `…/CurrentVenue/@Key`, `…/CurrentVenue/@Licensed`,
   `SystemData/Scheduler/SubModuleManager/@DefaultModule` and `Module[@Name="InGame"]`, and the camera sequence.
4. InGame module Inits run: `CInitPlayerSetups` (Init `fn_888EE258`), `CPlayerLoadingManager` (Init `fn_888E0148`,
   waits for `InGameVenueLogo`), `CPluginDataVenue` (Init `fn_888E67A8`, `GameDB:/GameDB/VenuePackSlotList`),
   `CSwingGamePlay` (registers the gameplay node types; the engine singleton `[0x88D45B00]` is built by
   `fn_88690B48`), `CInGameUINotifier` (HUD, section 5), and the rest of the module list (data).
5. The scoring `StdScoring_StartMatch` (0x88677058) reads the rules object (rules-and-scoring.md 3.6).

### 3.2 The structure that describes a match

It is **XData, not a C struct** (R for the paths, D for the attribute names):

| what | XData path / attribute | written by |
|---|---|---|
| game mode | `GameDB:/GameDB/MatchSettings/@GameMode`; attr `MatchSettings_MatchGameMode` (-88494981) = crc32 `Single` (0xCD0B222F) or `Double` | SubExhibition (item Id) |
| match type | `GameDB:/GameDB/MatchSettings/@MatchType` (`fn_888E6FF8`) | |
| players | `GameDB:/GameDB/MatchSettings/PlayerList`, a section list `Match_PlayerList` (-842023810). Each entry has `PlayerIndex` (940697594), `PadIndex` (154180010), `Type` (753727511; `Human` 0x64A3FAF1, otherwise CPU), `PlayerId` (2073149053), `OutfitIndex` (-1936601083). Per index: `MatchSettings_PlayerAILevel` (-845869611), `MatchSettings_PadIndex` (489294865), `MatchSettings_PlayerType` (-726685764), `MatchSettings_OutfitIndex` (-1261549883), `MatchSettings_PlayerPos` (-1721408879), `Match_PlayerIndex` (606839848) | AssignPad, PlayerSelect, AIDifficulty (MatchSettingsLib `match_GetPlayerList`) |
| venue | `GameDB:/GameDB/MatchSettings/CurrentVenue/@Key` (attr `MatchSettings_VenueKey` 2035802414; Lua `SetVenue`); also `SystemData:/…/Module[@Name="InGame"]/PluginDataList/PluginData[@Key="VenuePlugin"]/@RequiredDataKey` | VenueSelect |
| rules | attrs `MatchSettings_RulesNbSets` (1609392398), `MatchSettings_RulesNbGames` (-377191344), `MatchSettings_RulesSetAsTiebreak` (954745869), `MatchSettings_RulesSuperTieBreak` (337986206), `MatchSettings_RulesPointSystem` (2064589668, `Standard`). In C++ the rules object is `ts4_hash_find([0x88D458F0], 0x7E35EE14)`: `+0x04` games per set, `+0x08` sets, `+0x0C` set-is-tiebreak, `+0x0D` super tie-break, `+0x0E/+0x0F` | Config, `InitMatchRules` |
| difficulty | `MatchSettings_PlayerAILevel[i]` (keys from `AIDifficultyListAvailable`), `Common_ProfileOptions_Difficulty` default | AIDifficulty |
| court side / team | `MatchSettings_PlayerPos`, `TeamIndex`, `TeamPosition` in the list | AssignPad (pad Pos 1 = left team, 2 = right) |
| match state | `GameDB:/GameDB/Match/@State`, `@NextState`, `@IsIngamePauseMenu` | InGame |

Defaults written when AssignPad opens (D, S4ExhibitionAssignPad main.N, lines with `Match_PlayerIndex`):
`Match_PlayerIndex[0..3] = 7, 5, 8, 1339`, `RulesSetAsTiebreak = true`, `RulesNbSets = 1`, `RulesNbGames = 7`
(I: an index or a games count), `RulesPointSystem = Standard`.

**Player ids (I).** `PlayerId` is the `Index` field of the PlayerList entries listed by `PlayerList_ProPlayers`.
The demo build gates on the values 7, 8, 1316 and 1319, so the index space is the GameDB player list, not
obviously the PlayerList.bin row numbers of `data/gameplay/pro_roster.yaml` (Federer 674, Nadal 675, Djokovic 677,
Murray 678, Roddick 681). Which space is used was **not** settled. The pad route below avoids the question.

**Venue keys.** A venue key is crc32 of the venue CodeName, the Key field of `Venue_FullList` (I from the Lua:
`MappingVenueLogo` is built from the CodeName). VenueSelect's own default key is `-503660377` (0xE1FAB1A7,
unnamed).

### 3.3 Shortest way to a running exhibition

**A. Pad script (recommended; D for the screen logic, I for timings).** Every screen does `WaitForTexturePacks()`
before `ChangeScene`, so leave about 60–120 frames after each press and check `scene_name4` (section 1.1)
rather than counting frames. Starting from the practice ground (engine state 4, scene `S4PG`):

| screen | press | what the screen waits for |
|---|---|---|
| S4PG_InGame | START | opens the main menu (`Case22393` → `S4MainMenu`) |
| S4MainMenu | A | cursor starts on GameModes (`curSel = 0`) → `S4MainMenuSubOffline` |
| S4MainMenuSubOffline | A | first item Exhibition → `S4MainMenuSubExhibition` |
| S4MainMenuSubExhibition | A | first item `Single` (0xCD0B222F). Sets `MatchSettings_MatchGameMode`, `SetMasterPad`, `ResetTeamList/ResetPlayerList`, `TCR_ResetActivePadsExceptMaster` → `S4ExhibitionAssignPad` |
| S4ExhibitionAssignPad | (wait for `PadSetupCompleted`), then A or START, then A | first press: the master pad moves from Pos 0 to Pos 1 (left team, human). Second press: locks it. The free side is CPU. If the pad is not signed in it may call `TCR_AskSignIn` and the device selector (section 1.3). Confirm → `S4ExhibitionPlayerSelect` |
| S4ExhibitionPlayerSelect | A, A, then A or START | pick P1 on the grid (`PlayerList_ProPlayers` + Legends, sorted by SortIndex), then the CPU opponent. Each pick loads the portrait packs (`LoadQueue:AddLoadRequest`), so wait |
| S4ExhibitionAIDifficulty | A | keeps `DefaultDifficulty` |
| S4ExhibitionVenueSelect | A | `SetMatchIntensity()`; `MatchSettings_VenueKey` is copied to attr 1289193821 |
| S4ExhibitionConfig | A | any line → `|LaunchGame` → section 3.1 → `ChangePart(InGame)` → S4Loading → S4InGameIntro |

Two pads are not needed: the second side is CPU. **AI on both sides:** MatchSettingsLib counts
`ActiveLocalHumanPlayersCount`, and AssignPad needs the master pad locked on a side, so a CPU-vs-CPU exhibition
from the menus looks impossible (I). The practical substitute is a human slot with nobody touching the pad.
The human must still serve: the serve waits for input (I from the serve phase in
controls-and-shot-selection.md), so a script has to press the shot button for the human's serves.

**B. Direct call (I, untested; for the native harness).** From the host, between two `VdSwap`s on the
title's main thread:

1. Optionally write the match settings (section 3.2) through the same XData helpers the bindings use:
   `ts4_if_set_u32_off0_8862BE08(&handle, "GameDB:/GameDB/MatchSettings/CurrentVenue/@Key")` and then
   `ts4_get_u32_off0_8822AFE8(&handle, &key)` (the pair `SetVenue` and `ChangePart` use; R). The PlayerList
   entries need their child attribute hashes, which are data (BackstageRequests.bin). If the settings are left
   alone, GameDB keeps its defaults from GameDB.bin, which may already form a valid singles match (not checked).
2. Call `fn_887915F0(&hash)` with `hash = 0x1DCA7285`. It returns 0 once queued, 1 if the script engine is busy
   (then retry next frame).
3. Watch the engine state go 6 → 7 → 2 and `GameDB:/GameDB/Match/@State` change.

The missing first-scene attribute (`0xC67203FA[InGame] = S4InGameIntro`) is also data-driven. Without it the
UIPackDesc default for Part InGame applies (I).

## 4. Match-side objects from stable globals (R unless marked)

The watch syntax is that of `tools/recomp/rexproj/headless.sh`: `[x]` dereferences a big-endian pointer.

**Fix for `watch_basic.txt`.** `[gp]+0x78` is the **begin** pointer of a `std::vector<Instance*>`, and the
frame counters live in `[inst+0x30]`, not in `inst`. The current lines `match0_frame_a/b` read
`inst0+0x310`, which is wrong.

```
gp        = [0x88D45B00]                      GamePlay engine singleton (0 until a gameplay Part loads)
vec_begin = [gp+0x78]   vec_end = [gp+0x7C]   fn_886C27F8 iterates *it
inst0     = [[gp+0x78]]                       GamePlayInstance
mstate    = [inst0+0x30]                      match frame state
  +0x310 frame (u32), +0x314 frame2, +0x318 state hash, +0x7C active group/team to hit, +0x328/+0x329 flags
world     = [inst0+0x5C]
ball      = [world+0x20]                      0x540-byte ball state (gp3.md, gp4b.md s2)
  +0x18 tick (u32, ++ in fn_886C1ED8), +0x2C mode hash, +0x40 pos (f32x3, world cm between frames, I from gp4b_to_world),
  +0x60 prev pos, +0x100 P0 hit point, +0x110 P1 target, +0x4F0 vel (f32x3), +0x520 speed (f32), +0x434 shot id / outcome,
  +0x530 enabled (u8)
players   = [inst0+0x04] .. [inst0+0x08]       vector<PlayerCtx*>; pc_i = [[inst0+0x04]+4*i]
  pc+0x10 human (u8), +0x14 slot, +0x4C team, +0x5C Mover (+0x50 velocity, +0x68 speed m/s), +0x78 anim
  S = [pc+0x74]  PlayerState (0x1070 B)
    S+0x8E0 LocalPosition (f32x3, court-local, mirrored by court side; fn_8865EC70 = to world)
    S+0xD08 TimingValue (f32), S+0x544 ManualShotTiming (committed timing), S+0x66C serve timing
    S+0xDFC power hold frames (u32), S+0xE00 power (f32)
    S+0x714 outcome mode hash: In 0xCA68AAEC, Out 0x81A72B79, Net 0xCAA7531F, Let 0xC9238771
teams     = [inst0+0x10] .. [inst0+0x14]
```

Watch lines (each `[` … `]` is one dereference):

```
gp            u32    0x88D45B00
inst0         u32    [[0x88D45B00]+0x78]
m_frame       u32    [[[[0x88D45B00]+0x78]]+0x30]+0x310
m_state       u32    [[[[0x88D45B00]+0x78]]+0x30]+0x318
m_tohit       u32    [[[[0x88D45B00]+0x78]]+0x30]+0x7C
ball_tick     u32    [[[[[0x88D45B00]+0x78]]+0x5C]+0x20]+0x18
ball_mode     u32    [[[[[0x88D45B00]+0x78]]+0x5C]+0x20]+0x2C
ball_pos      f32x3  [[[[[0x88D45B00]+0x78]]+0x5C]+0x20]+0x40
ball_vel      f32x3  [[[[[0x88D45B00]+0x78]]+0x5C]+0x20]+0x4F0
ball_speed    f32    [[[[[0x88D45B00]+0x78]]+0x5C]+0x20]+0x520
p0_pos        f32x3  [[[[[0x88D45B00]+0x78]]+0x04]]+0x74]+0x8E0
p0_timing     f32    [[[[[0x88D45B00]+0x78]]+0x04]]+0x74]+0xD08
p0_shot_t     f32    [[[[[0x88D45B00]+0x78]]+0x04]]+0x74]+0x544
p0_power      f32    [[[[[0x88D45B00]+0x78]]+0x04]]+0x74]+0xE00
p0_outcome    u32    [[[[[0x88D45B00]+0x78]]+0x04]]+0x74]+0x714
p1_pos        f32x3  [[[[[[0x88D45B00]+0x78]]+0x04]+0x4]+0x74]+0x8E0
scene_name4   u32    [[[[[0x88D45A60]+0x1B0]+0x6C]+0x50]+0x60]
engine_state  u32    [0x88D45B1C]+0x278
part_request  u8     [0x88D45B1C]+0x274
```

In the PracticeGround (after Press Start) one instance already exists: gp became non-zero in runs h5 and h8. These
values should therefore move before any match, as soon as the player hits a practice ball.

## 5. The HUD (R)

- **`CInGameUINotifier`** (vtable 0x880DB698, Init `fn_888E40B0`, **Update `fn_88909888`**) is the C++ side of
  the in-match HUD. Its Update calls `fn_88903D18`, which binds the `S4InGameMatch`/`S4InGameFatique` scenes and
  the controls `|ActionTimingFeedback`, `|TimingFeedback|Text`, `|Position_TimingFeedback`,
  `|ScoreBoardSmall|BottomRightPoint` and `|ScoreBoardSmall|Color_Fading`. It then runs the per-feature
  helpers below. Init registers `GamePlayState:/…/PlayerStates/PlayerState[%d]/ToDisplay/Position` (gp0.md).
- **Timing feedback**: `fn_889082C0` (from `fn_88909888+0xE8`).
  1. Gate: `+0x2FE` set and `+0x2FC == 1`.
  2. Read the timing float `[this+0x2F0]+0x10` and the flag `+0x2F`.
  3. Classify with `ts4_classify_range_hash_888C4708`. The thresholds are at `g_ts4_script_constants`
     (0x880D0F70) `+0x38, +0x38C, +0x474, +0x2AC, +0x10C`. Results are string keys `0x39445A7E` PERFECT,
     `0x625E2078` GOOD, `0xB0DA3179` TOO LATE, `0xF489E4D9` and `0x8CDA49A8` (the last two not in ui.md's list).
  4. Compare against the constants at 0x880D0934 and 0x880D0938, then send the action string `$Cpp_Timing_Good()`,
     `$Cpp_Timing_Average()` or `$Cpp_Timing_Bad()` to the control (`fn_881CECD0`/`fn_881C31D0`).
  This answers ui.md's open item "which grade maps to which string".
- **Shot icons and charge**: `Cpp_PS_PowerShot_FadeIn/Out`, `Cpp_PS_ControlShot_FadeIn/Out`, `Cpp_PS_Charging`
  (`fn_88909578`, `fn_88908530`, `fn_88909360`, `ts4_if_call_seq_u8_off20_88909488`). `Cpp_PS_SupaDupaInit/Init2/Hide`
  (`fn_889085E8`, `…88908710`).
- **Fatigue and player id**: `Cpp_Fatigue_Show/Hide/Update` (`fn_889073D8`, `fn_88908A18`, `…88908908`),
  `Cpp_PlayerID_Show/ShowCentered/Hide` (`…88908870`, `…889087F0`).
- **Score display**: driven through the scoreboard controls above and the attribute requests the score
  templates track (`GamePlay_GetTeamWonGameCount`, `GamePlay_GetTeamLastGamePoints`,
  `GamePlay_GetTeamDisplayLastGame`, `GamePlay_GetServingTeamIndex`, `GamePlay_IsTieBreak`; D). The values come
  from the scoring object (rules-and-scoring.md); the per-call path was not traced.

## 6. Open items and leads

1. **BackstageRequests.bin decode** (Core.arc 19ce55a5, 1,053,532 B; entries of 0x18 bytes with the attribute
   hash at +0x10, e.g. `Online_IsOnline` 0x74DDA130 at file offset 0x3674). It maps every attribute id to
   its XData path. That would complete section 3.2 (player entry fields) and allow route B without guessing.
2. The RUI object-method table (`SetActiveControl`, `GetValueInt`, …) behind `fn_881D3100`/`fn_881E5230` was not
   paired.
3. AssignPad and PlayerSelect press sequences are read from Lua, but the exact number of presses was not
   checked against a running game.
4. `ChangeGameStage` semantics (the CTCRActions `+0x60` target) and attribute 1892929434 (it decides between
   the main menu and the sign-in/profile chain) are unnamed.
5. The PlayerId index space (section 3.2).
6. The class → module (Part) membership is data (SystemData.bin, `ModuleList`). It was not decoded.
