# Front end and in-match HUD (port agent A2)

Status on 2026-11-14: **formats decoded and exported; the browser renderer has not been written** (the port is
paused after this round on the owner's decision). This note records what is decoded, how it was measured,
what is mapped and what is still open.

Tools (standard library only, plus the repository's `ts4_arc`, `xdvdfs`, `ts4_texture`, `ts4_mesh`):

| file | purpose |
|---|---|
| `tools/port/lua50.py` | Lua 5.0 / LuaPlus bytecode loader, disassembler, symbolic evaluator, pseudo-Lua decompiler |
| `tools/port/ui_actions.py` | `.actions` (tokenised command scripts) and `.anims` (key-framed clips) readers |
| `tools/port/ui_formats.py` | `StringTable.bin`, `.abc` fonts, `PositioningInfo`, `ControlData`, scene JSON post-processing |
| `tools/port/ui_export.py` | reads the user's ISO in place and writes `work/port/assets/ui/` (git-ignored); `--summary data/ui` writes the committed, game-free summaries |
| `tests/test_port_ui.py` | 16 tests, synthetic bytes only (`python3 -m unittest tests.test_port_ui`) |

Reproduce: `python3 tools/port/ui_export.py --out work/port/assets/ui --summary data/ui` (Python 3, ISO found
under `orig/` automatically or with `--iso`). Last full run: 337 scenes, 958 textures, 5 string tables of
8,211 keys each, 4 fonts; archive sha256s are in `work/port/assets/ui/manifest.json` and in every
`data/ui/*.json` (`source_sha256`). Core.arc sha256 `7df7bfd5…aefbf50`, PracticeGroundPart.arc
`e9acba16…c0af5`, PlayerBackGround.arc `bb580156…68ec`.

## 1. Technology

The game's UI is Pam's own **RUI** system (not XUI). A screen is a *scene*: a Maya-authored node graph
(`*.sceneData`, compiled Lua), a behaviour table with closures (`*.scene`, compiled Lua), a tokenised
action script (`*.actions`) and animation clips (`*.anims`). Templates (`T4*`) are scenes instanced inside
scenes. Packages (`Boot`, `Common`, `InGame`, `OnlineExhib`, ...) are Lua tables listing scenes, templates
and fonts. Geometry comes from `PackedMeshes.xbin`, textures from per-pack `Textures.xpr`, text from
`StringTable.bin`, glyphs from `.abc` fonts. XUI is used only for `Media/XUI/PressStart.xzp`
(`PressStartScreen.xur`, `DownloadableContent.xur`); legal and attract videos are `.wmv` under `Media/`.

Where things live (confidence high, from archive listings):

- **Core.arc**: boot scenes (`S4Disclaimer`, `S4Loading`, `SMainMenuBackground`, `SMessageBox`, ...), Lua
  libraries (`*Lib.bin`), `StringTable.bin` ×5, fonts, shared texture packs.
- **PracticeGroundPart.arc**: start screen, attract mode, main menu and sub menus, offline exhibition
  setup (`S4ExhibitionConfig`, `...AIDifficulty`, `...PlayerSelect`, `...VenueSelect`, `...AssignPad`),
  options (`S4Options_*`), practice ground (`S4PG_*`), Move tutorials, `S4UnlockOverview`, 3D disclaimer.
- **PlayerBackGround.arc** (and every venue archive): the `InGame` package — HUD, pause, statistics, replay.
- CareerMain, CareerTournament, PlayerAreaMenus, PlayerCreator, LockerRoom, TopSpinAcademy,
  KingOfTheCourt(Menus), OnlineExhibition, OnlineProChallenge, OnlineWorldTour: their mode screens.

## 2. Formats

### 2.1 Lua 5.0 bytecode (LuaPlus) — confidence high

Header `1B 'Lua' 50 00 04 04 04 06 08 09 09 08` + f64 test number, big endian. Constant tags 0 nil,
3 number, 4 string, **9 wide string** (UTF-16BE, LuaPlus). Instruction: op bits 0-5, C 6-14, B 15-23,
A 24-31, **Bx 18 bits** (6-23), sBx bias 131071, RK constant when ≥ 250. 39 opcodes with the LuaPlus
bit ops inserted after DIV (`BAND BOR SHL SHR BXOR`, opcodes 16-20), so `UNM`=21 … `CLOSURE`=38.

Code evidence: the `luaV_execute` jump table, function `fn_8880D5E0`, table at `0x8880D748` (39 cases,
BXOR's fallback is tag-method 9); constant loader `fn_88810948` (LoadConstants, tags above),
`fn_88810D48` (LoadLocals), `lua2_LoadWString_888107F0`, all in `src/xbox360/lua2_lundump.c`, and
`d4b_lua_undump_88810048.c`. Wide strings are created by `lua2_luaS_newlwstr_88812FC8`.

`lua50.evaluate` runs a main chunk symbolically (unknown globals become named tables, calls are recorded,
not run), which is enough for the data-only `.sceneData`/`.scene`/package/library chunks. `lua50.decompile`
emits pseudo-Lua (folded expressions, `goto` for jumps) for the closures — readable, not recompilable.

### 2.2 `.sceneData` / `.scene` — confidence high

`SceneData` = {ControlData (binary), Graph, Model.Meshes (per mesh: Shader {TextureName, ShaderType
`TexturedColor`/`UntexturedColor`/`TexturedColorMatrix`, Diffuse, Transparency}), NodeCount, NodeTypes,
Templates, ZOrder}. Node types: Camera, Node, Anchor, Color, Mesh, UntexturedMesh, Text, ScrollText,
List, ColorMatrix, Template, PamDynamicNode, PamVideoPlayer, PamWorldPosNode.

- `PositioningInfo`: 48 B = 12 BE floats (translate, scale, rotate in radians, pivot) or 96 B = 24 floats
  in Maya order (t, s, r, rotatePivot, scalePivot, shear, rotatePivotTranslate, scalePivotTranslate).
- `TexturePositioningInfo`: 5 floats (imageCenterX/Y, imageScaleU/V, rotation).
- Text: Box Left/Right/Top/Bottom, Justification, TextColor, `TextID` (string key name), WordWrap,
  UseColorMatrix. Anchor: Horizontal 0 centre / 1 left / 2 right / 3 left-safe / 4 right-safe; Vertical
  0 centre / 1 top / 2 bottom / 3 top-safe / 4 bottom-safe; AspectCorrect.
- Template instance: `TemplateName` + `ChangedAttributes` (overrides: imageName, visible, translate*,
  scale*, rotate*, pivots, shear, Flags, LPM, IsAnimated, Rui_GlobalColorAlpha).
- Virtual screen: `UICamera` at z = 622.25, FOV 0.736 rad, aspect 4:3 → 640×480 units centred on the
  origin, y up.

`.scene` = `Scenes.<Name>` = {Controls (name → index), ControlsInfo (per control: Items, ItemMapping,
ActionPrefix, Up/Down/DefaultInput, Value ...), LayerList, TexturePackList, MultipleControllerInput,
`__Action_N` closures}.

### 2.3 Geometry — confidence high (measured)

UI meshes are records of `PackedMeshes.xbin` (XBin signature `6912b1b83f65f116`), named `Crc%X`. Each
top-level scene has a `Hierarchy.xdt` whose Geometry elements are in the order of the Mesh,
UntexturedMesh, Text, ScrollText, PamVideoPlayer and PamWorldPosNode nodes of a depth-first walk with
templates expanded in place (`ui_export.expanded_geometry_nodes`). Full export: 158 hierarchies,
17,983 nodes resolved, 0 missing, 0 count mismatches. Vertices are in the x/z plane (z = screen up),
uv v = 0 at +z. For a scene's own meshes the key is `crc32(lower(scene + "_" + MeshName))`; template
meshes do not follow that rule, so order matching is used.

### 2.4 `.actions` — confidence high (format), medium (command semantics)

`u32 nactions, u32 record_bytes, nactions × u32 offset, u32 nstrings, nstrings × u32 offset`, record
area, string pool (u8-length strings). Record: `u32 0, u16 len + name, u16 nparams, u8 params_len,
params, u8 nblocks`, each block `u16 cond_len, cond (first byte 0x01), statements (u8 len + tokens), 0`.
Token byte ≥ 0x80 is a pool reference `(b & 0x7F) | next << 7`.
Commands seen: `SceneOn/SceneOff`, `Wait(n)`, `ChangeScene('X')`, `PushScene`, `PushLayer('X', false)`,
`SetActiveControl`, `$Scene.Action`, `self.__Action_N(@Param@)`, `>Template.Clip|path` (play clip),
`-Template.Clip` (reverse), `!` (loop), `Action('|Ctrl','Clip',false)`, `PlaySound(crc,'Root/UI/...',true)`,
`ListSelNext`, `ListProcessInput`, `SetControlAction`. Actions named `Cpp_*` / `Update*` are called by
the game code.

### 2.5 `.anims` — confidence high (546 files parse, 0 errors; 2 empty, 35 clips without curves)

Curve: `u32 first (8 = first of group), u32 size, u32 node_off, prop_off, tail_off (from curve − 8),
FFFFFFFF, u32 nkeys, u32 flags (0x10000 stepped), 0, 0`, then keys of 6 floats (t, v, in-tangent dx/dy,
out-tangent dx/dy; Maya Hermite). Name blocks `[len][padlen][FFFFFFFF][chars]`. Groups separated by 2-3
words (last = duration); clip table `{0x24, first-curve offset, f32 speed, f32, 0, 0, name}`. Properties:
visibility, translate*, scale*, rotate*, globalColorR/G/B/A, globalR/G/BScale, globalSaturation,
imageCenter*. Rotation units in clips are unverified (degrees assumed, the graph uses radians).

### 2.6 Strings — confidence high

`StringTable.bin` (XBin `c88433e76668075d`): array A at 0x14 (8 B: rel → font C string, f32 scale),
array B at 0x20 (12 B: rel, class, key; sorted by key; class `0x92A82712` = rel → rel → UTF-16BE,
`0x9EDE2887` = rel → UTF-16BE), array C at 0x30 (case pairs). Key = `zlib.crc32(TextID)`. 8,211 keys
per language; table key → language: `7e885948` en, `b7977968` fr, `e26082c0` de, `803e07b4` es,
`297fbe13` it (identified by word statistics, `ui_formats.guess_language`). 770 key names recovered
from scene TextIDs and Lua/action strings (`data/ui/loc_keys.json`). Controller buttons are private-use
glyphs in the text.

### 2.7 Fonts — confidence high (glyphs), medium (header word 5)

`.abc` little endian: u32 version 6, line height (39/33), texture w, h (512), u32 unknown, nranges,
ranges (u16 first, last), u32 nglyphs, 28-byte glyphs {4 f32 uv, i16 offset, width, advance, u16 pad,
u32 channel mask}. Page texture = the XPR entry of the same name in Core (Main_White 8_8_8_8, Main_Big
and Main_Gray DXT5). Fonts: Main_White, Main_Gray, Main_Big, LCD_30 (string table also names
Florencesans_Gray_28).

### 2.8 Sound hooks — confidence medium

UI sounds are `PlaySound(crc, 'Root/UI/...', true)` statements in `.actions` (FMOD event paths; see
A3's audio export for the event banks).

## 3. Screen map and flow

`data/ui/screens.json` lists every scene (archives, layers, texture packs, node counts and types, actions,
menu item → transition targets); `data/ui/flow.json` lists every `ChangeScene`/`PushScene`/`PushLayer`
edge found in actions. Main path, derived from data (confidence high unless noted):

```
S4Disclaimer -> S4Loading -> S4StartScreen (XUI PressStart; idle -> S4AttractMode)
S4StartScreen -> S4MainMenu  [layers SMainMenuBackground, S4MainMenu]
S4MainMenu items: GameModes -> S4MainMenuSubOffline, XboxLive -> S4MainMenuSubXboxLive,
                  PZone -> S4MainMenuSubPZone, Unlock -> S4UnlockOverview, Options -> S4MainMenuSubOptions,
                  3DConfig -> S4Xbox3DDisclaimer
S4MainMenuSubOffline: Exhibition -> S4MainMenuSubExhibition, Career (CareerMain), KingOfTheCourt, TopSpinSchool
S4MainMenuSubExhibition: SingleMatch / DoubleMatch -> S4ExhibitionAssignPad
  -> S4ExhibitionPlayerSelect -> S4ExhibitionAIDifficulty -> S4ExhibitionVenueSelect -> S4ExhibitionConfig
  -> match (started from C++; not found)
Back (B) returns one level (sub menu -> S4MainMenu).
```

Menu items are written by closures: `currentScene.Controls["|MainMenu"].Items = {{Id = crc32(name),
MappingTitle = TextID}}` with `ItemMapping = {{Control = "ButtonText.textID", SourceAttribute =
"MappingTitle"}}`; transitions come from conditional action blocks that test `.Id`
(`ui_export.menu_targets`). Exhibition config lists: sets 1/3/5, games 3/6/7(?), advantage on/off,
plus two value lists not yet named. Player and venue grids are filled by C++ (`UpdatePadList_*` and
attribute requests) — not reconstructable from data.

### In-match HUD (`InGame` package)

`S4InGameMatch` LayerList: S4InGameFatique, S4InGameStaminaBars, S4InGameMatch, S4MoveRange,
SInGameReplay, S4InGameTransition, S4InGameVideoTransition.

- Score bug: `T4InGameScoreBoardSmall` (top-left anchor): texts PlayerName1/2; five
  `T4InGameScoreBoardPoints` (ScorePlayer1/2; clips Player1Winner/Player2Winner); two
  `T4InGameScoreBoardActuallPoints` (clips PointOn/ChangePoint); own clips Single/Double,
  Player1Ball/Player2Ball (server), BallOn, ScoreBoardOn, PointsOn. Also ScoreBoardBig, Message,
  OnBench, Objectives, SparringProgressBox, Timer, Score, ServingMessage, Statistics, Replay templates.
- Timing feedback: `T4IngameTimingFeedback` (control `|TimingFeedback` in `S4InGameFatique`). Game code
  calls `Cpp_Timing_Good` / `Cpp_Timing_Average` / `Cpp_Timing_Bad`, each playing
  `TimingFeedback_OnOff`, then `TimingFeedback_<grade>` (1.25 s: alpha 0 → 0.7 → 0, scale 2.0 → 1.2;
  colours Good (0.3, 1, 0.3), Average (1, 0.8, 0), Bad (1, 0.1, 0.1)), then the reverse of OnOff.
  Strings: `39445a7e` PERFECT, `625e2078` GOOD, `f7020060` AVERAGE, `b0da3179` TOO LATE (no "too early"
  key was found by text search). Which grade maps to which string is decided in C++ (open).
- Shot icons: `Cpp_PS_*` actions colour `T4InGameShootIcon` (power/control shot) per player; stamina
  `T4InGameStaminaBar`.
- Pause: `S4InGamePauseMenu` (MenuList of `T4InGameMenuButton`, layer `S4InGameBackground`).

## 4. Lua API used by the scripts

Census of calls in all scene closures and libraries: `ExecuteAttributeRequest(crc32(name), 0)` with
`GetValueInt/Bool/CKey/String/WString/UInt`, `GetAttribute`, `SetValueCKey/Bool/Int`,
`SetControlAction`, `SetActiveControl`, `StartTrackingRequest`, `FormatText`, `ConvertNumber`,
`PlayInstantAnimation`, `StartSmoothCameraMove`, `GetMasterPad`, `common_FindRowInTable`, `Pam.PPrint`,
`towstring`, `tostring`, `TCR_*` (incl. `TCR_IsUserSignedIn`), `DLL_IsDLLGame`, `Is3DAccessible`,
`IsAnyMoveConnected`, `IsAGuest`, `exhib_GetPlayerSection`, `season_*`, `playerarea_*`.
635 distinct attribute ids are requested; only 10 names are recovered (from `RequestCache`, e.g.
`GamePlay_ServiceBeginRaised`, `GamePlay_IsTieBreak`, `GamePlay_GetServingTeamIndex`,
`MatchSettings_RulesNbSets`). The names are not in the executable or the data as plain strings.

## 5. Export layout (`work/port/assets/ui/`, never committed)

`manifest.json`, `scenes/<Name>.json` (scene, data with decoded positioning, actions, anims, pseudo-Lua,
action_closures, closure_writes, menu_targets, lists, geometry by expanded node path), `packages/`,
`libs/`, `strings/<lang>.json` + `.fonts.json` + `keys.json`, `fonts/`, `textures/*.png` +
`textures.json`, `flow.json`.

## 6. Not done / open

- **Renderer not written**: `port/web/ui/` (scene instancing, Maya pivot matrices, anchors, Hermite clip
  playback, bitmap text, list binding, front-end state machine, HUD bound to `Ts4Core.snapshot().score`
  and `pollEvents()`) was designed but not started before the pause. The exported data is sufficient
  for it; the mapping planned was: score → `T4InGameScoreBoardSmall` texts and clips; server → Player1Ball
  /Player2Ball; timing → `Cpp_Timing_*` sequences (needs a timing grade, which port/core does not
  produce); exhibition config → `Ts4Core.startMatch` cfg (numSets, gamesPerSet, ...).
- Text layout assumptions unverified: line height (20 local units per font line), Justification codes
  (0 left, 1 centre, 2 right assumed), 5% safe-area margin.
- Anim rotation units; `.abc` header word 5; ControlData fields beyond name/id.
- Attribute request names (625 of 635 unknown) and the C++ side: the RUI scene manager, the function
  that starts the match from `S4ExhibitionConfig`, the code that fills player/venue grids and that
  calls `Cpp_Timing_*` — none located in the executable yet (no addresses).
- Career, online, player creator, stats and trophy screens are exported and listed in
  `data/ui/screens.json`, but their flows were not walked by hand.
