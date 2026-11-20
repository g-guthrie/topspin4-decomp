# Presentation, cameras and audio (port agent A3)

Measured on the retail disc image (SHA-256 `93f34363...8f3e5c`) and `Swing_DLL.dll` (SHA-256
`a7f28b29...952ba9`, base `0x88000000`), with Python 3.13 (standard library only), ffmpeg 7.x (used only to decode XMA
locally) and node 22. Nothing from the game is committed. Exports go to `work/port/assets/` (git-ignored).
Confidence: **C** = read from code or data, **I** = inferred, **P** = a port stand-in for something not decoded.

Port work is paused after this round, as the owner decided. Section 5 lists what is still open.

## 1. Files

| Kind | Path |
|---|---|
| FEV1 parser | `tools/port/fmod_fev.py` |
| FSB4 reader, XMA RIFF wrapper, Xbox IMA decoder | `tools/port/fmod_fsb.py` |
| Audio exporter | `tools/port/audio_export.py`. It writes `audio/<venue>/events.json`, `audio/banks/<bank>-<sha8>/*.wav|mp3` and `manifest.json`. `--summary` writes `data/gameplay/audio/fev_inventory.yaml`. |
| Camera exporter | `tools/port/camera_export.py`. It writes `cameras/shots.json`. `--summary` writes `data/gameplay/camera/tv_cameras.yaml`. |
| Readable data | `data/gameplay/audio/events.yaml` (triggers → code), `data/gameplay/audio/fev_inventory.yaml` (539 events, with sha256 for each .fev), `data/gameplay/camera/tv_cameras.yaml` (38 in-game shots plus the names of the other 58) |
| Web | `port/web/src/camera_tv.js`, `audio.js`, `presentation_hook.js`, plus 6 one-line calls in `play.js` |
| Tests | `tests/test_port_audio.py` (synthetic bytes only) and `port/web/test/presentation.test.mjs` (node; run from the Python test) |

Commands:

```
python3 tools/port/audio_export.py            # Amsterdam + Core: 24 banks, 539 events, ~1045 files, 414 MB, ~2 min
python3 tools/port/camera_export.py           # 96 shots
```

URL options in the viewer:

| Option | Effect |
|---|---|
| `?cam=port` | Use the old follow camera instead of the TV camera |
| `?tvcam=TVZoom` (or the other options) | Pick a TV camera option |
| `?tvaspect=normal` | Use the 4:3 camera records |
| `?audio=off` | Turn sound off |

## 2. Cameras

### Data (C)

**Where the shots are**
- `<venue>.arc`, Shots.bin in directory `0x53e083e4`: 96 shots.
  - 38 `CShotSourceInGame` (the TV cameras).
  - 8 `CShotPad` (free cameras with a key mapping).
  - The rest are `CShotCutSceneDynamic`: the replay and cutscene cameras `CameraReplayBall*`, `CameraReplayPlayer*` and `CameraCutscene{Left,Right}{Baseline,Corner,Side}{CloseUp,MidShot,LongShot}0N`.
- Directory `0x703e7afd` Shots.bin: 15 `CShotAnimated`. These are CamCrowd, CamHotSpot, CamFixed, CamScoreBoard, CamSpeedOMeter, CamFlyover00-04 and CamCrowdEndOfMatch.
- Directory `0x86c4ecdc` Shots.bin: 769 `CShotAnimated` (`Cam0N_CS_*`) and 202 `CShotCutSceneDynamic`.
- Core.arc PackedCameras.bin: CamDisplay, CamFlyover, ScoreboardCamera, SpeedOMeterCamera, CamReplayPC and cube-map cameras.

**`CShotSourceInGameType` record layout** (crc `0xcfad87d0`, 224 bytes, big-endian; full field list in `camera_export.py`)
- From, At, Up in cm, at `+0x04`, `+0x10` and `+0x1C`.
- Two FOV pairs (`+0x28/+0x2C` and `+0xD8/+0xDC`). Each pair is the full 4:3-width angle and the vertical angle, with tan ratio exactly 4:3.
- Smooth times at `+0x6C..+0x78`.
- AtLimit at `+0x98..+0xB0`.
- PositionPercent `+0xC4`, FarLimit and FarLimitMax `+0xC8/+0xCC`, SideLimit and SideLimitMax `+0xD0/+0xD4`.

**`CShotCutSceneDynamicType`** (276 bytes) adds:
- target type and qualifiers (Ball, Baseline)
- FovDistanceMin/Max
- DOF near and far
- BoneName (e.g. `B_Head`), PlayerIndex

### Code (C)

**Factories**

| Shot class | Address |
|---|---|
| CShotPad | `0x888B5080` |
| CShotSource | `0x888B4FC8` |
| CShotSourceInGame | `0x888B4810` (vtable `0x880DCA44`) |
| CShotCutSceneDynamic | `0x888B7250` |
| CShotAnimated | `0x888B73D8` |
| CCamera | `0x888B42F8` |

Type registration is at `fn_888B83E8`.

**`fn_888B4900`** is the TV compute. Its algorithm is written out at the top of `camera_tv.js`. In short:
1. Pick the near player and the far player. In doubles, average each pair.
2. `At = near + (far − near) · PositionPercent`.
3. Clamp `At` per axis with `fn_888AE0F8`: max first, then min. On Left records Min.x > Max.x, so x is pinned to Max.x.
4. The FOV widens linearly once the near player is past FarLimit in |x|, or past SideLimit in |z|. There is no clamp.

**`fn_888F03B0`** builds the shot name: `"CameraInGame" + Widescreen|Normal + "Left" + Singles|Doubles + option`. It stores the crc32 at `matchctx+0x6EC`. The option hash is at `matchctx+0x6F8`; the hashes are in tv_cameras.yaml.

**Other camera functions**
- `fn_888BD828` writes `GameDB:/GameDB/CameraSystem/CurrentCamera/{From,At,Up,@Fov}`.
- The PackedCameras loader is `fn_8875CF78` / `fn_88767F98`.
- The replay file path is built at `fn_888FA780` (`Media\ReplayDemo\%s.bin`).

### Port status

**Rendered:** `camera_tv.js` implements the TV compute exactly as decoded, from `shots.json`. If no export is present it falls back to the embedded WidescreenLeftSinglesTV record.

**Port stand-ins (P)**
- The camera films from the human's end. The game always builds the "Left" name, and how it uses the Right records at run time was not traced.
- SmoothTime is applied as an exponential time constant. The engine's smoother was not decoded.

**Not rendered:** replay, cutscene, animated and pad cameras.

## 3. Presentation flow

### Data and code (C)

**CutSceneEngine.bin** (directory `0x86c4ecdc`, root `0x3eb25c31`) holds 122 sequences. Each has a Name, Mode, Double and Interaction flag, a list of Shot names and a list of Dummy/Animation entries. There are also 98 condition rules and the category lists.

Sequence names include:
- PlayerEntranceFromSameSide/OppositeSide, Corridors, PlayerTakingPlace, WarmingUp
- GettingReadyToServe/Return, ReadyToServe/Return, Repositioning
- Sitting, IsSittingDown, IsGettingUp (changeover)
- ShakingHands
- Winner, WinnerChampion, SalutingCrowd, SalutingCrowdLoser

Animation names follow the pattern `Cutscene_<Sequence>_...`.

**Flow strings** (DLL): `[Cutscene] FLOW NormalEndOfGame_Single_Flow_%d`, `ChangeTeamSide_Single_Flow_%d` and `EndOfSet_Single_Flow_%d`.

**Classes:** CCutSceneManager, CReplay, CRecordReplay, CReplayDemo, CReplaySequencerBegin/End and CXDataReplayable_*. The replay records typed values per frame.

**Lua entry points:** ChooseInGameCamera, InitMainCamera, SetMainCameraConstraints, StartSmoothCameraMove, FreezeMainCamera, ActivateInGameCam and InitPlayerReplay.

**UI scenes:** S4InGameIntro, SInGameReplay, T4InGameReplay. Venue transitions play `Transition<Venue>_HD/SD.bik`.

**Sounds per stage** come from `fn_8888B560`:

| Stage | Sounds |
|---|---|
| Intro | Announcer by match type; MatchIntro Flyover / Corridor / Applause*; Stadium/Corridor/*; Welcome_Players_* |
| Changeover | Crowd/Interpoint/Music, Umpire CourtChange/Time |
| End of match | EndOfMatchPart1-4, ApplauseWild |

### Open (I)

- **The sequence chooser.** The 98 condition rules that map match state to a sequence are not decoded.
- **CutScenes.arc** is not a PAM archive ("tag missing"); its format is unknown.
- **Unresolved name hashes:** `c1ffe2a8` (58 repositioning sequences), `8ff1ec8b` and `b8370498`.
- **Port:** none of the flow is rendered. The port has no intro, changeover or ceremony; the audio director only plays the matching sounds on GAME / CHANGE_ENDS / MATCH.

## 4. Audio

### Formats (C)

**FEV1, version `0x003E0000`, little-endian.** Full layout in the docstring of `fmod_fev.py`. The parser reads all 19 Amsterdam projects and Core Menu.fev to the end of the sound-definition table.

Unknown parts:
- the rest of the 0x84-byte base block
- the 48-byte instance tail
- the meaning of the 0–2 extra u32 at the tail of a complex event (handled by a validated heuristic)
- the envelope DSP type 12 (taken to be volume, **I**)
- the sound-definition template play-mode numbering (**I**)

**FSB4**

Layout:
- 48-byte header.
- 80-byte sample headers, plus extra bytes.
- Sample data is consecutive. When mode bit `0x10000000` is set, each sample's data is padded to 32 bytes.

Codecs by sample mode bit:

| Bit | Codec | Where used | Handling |
|---|---|---|---|
| `0x01000000` | XMA | most banks | Wrapped as an XMA2WAVEFORMATEX RIFF and decoded by ffmpeg. The decoded length matches the header sample count. |
| `0x200` | MP3 | Ball_Shot, Crowd_*_Full, Stadium, streamed music | Copied as-is |
| `0x00400000` + `0x20000000` | Xbox IMA | Media/Sounds Crowd_*_Empty/Half; probably unused | Decoded in Python; untested on disc data |

The sample loop bit `0x2` is never set. Looping lives in the event data, which is not decoded, so the port loops events by name.

**Bank lookup** for a .fev bank name, in order:
1. `<bank>.fsb` in the same archive
2. `Media/Sounds/<bank>.fsb` (streamed crowd banks, `Music.fsb`)
3. Core.arc

Banks per venue: Ball_Shot, Ball_Collision, Ball_Bounce_<surface>, Foot_<surface>, Grunt_*, Judge_*, Umpire_*, PlayerName_*, PlayerSounds, Stadium, Venue_<City> and Crowd_<size>_Full[_Streamed].

### Triggers (C, see `data/gameplay/audio/events.yaml`)

The controller lives in `0x8888A000-0x88890000`. The per-frame update is `fn_8888F4C0`, and the command-queue dispatcher is `fn_8888DD18`.

| What | Function |
|---|---|
| Shots | `fn_8888D700` |
| Bounces | `fn_8888CFD0` |
| Net | `fn_8888EBE8` |
| Scenery collisions | `fn_8888D328` |
| Line judge | `fn_8888AB30` |
| Umpire | `0x8888C620..0x8888CF40`, dispatcher `fn_8888E828` |
| Player cues (grunts, victory) | `fn_8888ADC0` |
| Crowd kicks / reactions | `fn_8888DA20` |
| Applause | `fn_8888D930` |
| Ambience | `fn_8888AC68` |
| Presentation | `fn_8888B560` |
| Menu music | `fn_8890BCA0` |

Footsteps come from animation commands (`6023f2af`). They use per-surface volume curves.

### Port status

**Rendered** (`audio.js` + `presentation_hook.js`):
- WebAudio playback of `events.json`, with weighted random waves, max playbacks, loops, and a parameter-driven layer and envelope gain.
- Core events are mapped with the game's thresholds: shot family and power words, bounce angle and speed buckets, net slow/fast, the line judge, and umpire score calls (point, game, tie-break, match, let, court change).
- End-of-point applause, the Excitement loop, Hubbub, the ambience bed, grunts, victory grunts and footsteps.

**Port stand-ins (P)**
- **Stroke power:** the core does not provide it, so it is taken from launch speed, mapped from 40–160 km/h onto 0–1.
- **Speed unit** for the bounce and net thresholds: assumed to be km/h. The game's unit is unknown.
- **Crowd levels:** the applause level and excitement come from rally length. The game's source, `+0x130`, was not traced.
- **Footsteps:** a cadence from running speed instead of the animation events.
- **Voices:** Man/00 and Man/01, called PlayerOne/PlayerTwo.
- **Score order:** server first.

**Audible check: not done.** It has not been checked in a browser by ear. Only the node logic tests and the export (all files present, durations correct) were checked.

## 5. Still open

- **Crowd excitement:** who queues the excitement and crowd commands upstream of `fn_8888DD18`, and the level at `+0x130`.
- **Undecoded format pieces:** the rest of the FEV base block and instance tail (loop and 3D modes), and the speed unit.
- **Replay:** the replay record format and the replay camera selection.
- **Cutscenes:** the CutSceneEngine condition rules, the CutScenes.arc format, and unresolved CRC names.
- **Camera end and smoothing:** how the camera end (Left/Right) is chosen at run time, and the smoother's semantics.
- **Not exported:** other venues and languages. `--venue all` exists but has not been run.
