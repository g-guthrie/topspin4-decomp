# Tennis rules and scoring in Swing_DLL.xex

Agent: `rules`. Target: `Swing_DLL.xex`, title 54540859, image base `0x88000000`.
Everything below is original prose and pseudocode. No game data, bytes or
disassembly are reproduced. Addresses are virtual addresses in the decompressed
image; names are proposals (the binary is stripped).

Companion files:

- `docs/gameplay/rules-symbols.csv` - every function identified, with confidence.
- `ref/gameplay/rules.c`, `rules.h`, `test_rules.c` - a clean C re-implementation of the
  decoded state machine with a self-test.
- `src/xbox360/gp_rules_*.c` - three small byte-matched functions (see the end).

Confidence tags used in this document:

- **[V]** verified by reading the instructions of the function named.
- **[I]** inferred (from data flow, strings, or the way consumers use a field).
- **[U]** unknown or not decoded.

## 1. How the rules were found (reproducible)

1. The umpire call strings (`Root/Umpire/Rally%s/%i-%i`, `.../Deuce`,
   `.../Advantage`, `.../TieBreakNormal/...`, `.../GameNormal/TieBreak`,
   `.../GameNormal/SuperTieBreak`, `.../SetNormal/...`, `.../RallyNormal/LetFirstServe`)
   live in `.rdata` at `0x880DE9D8..0x880DEEA4`. Scanning the split objects'
   relocations for code that references them (`tools/disasm.py`'s `parse_coff`,
   REFLO/ADDR32 targets named `lbl_880DEAC8` etc.) gives four announcer functions:
   `0x8888C7E8` (set), `0x8888CB48` (game), `0x8888CCE8` (point), `0x8888CF40` (let).
   Their single caller is `0x8888E828`.
2. Those functions read score fields out of a block reached as `ctx+0x30` /
   `ctx+0x44`. Searching all `.text` for the instruction pattern that writes the
   display values (`li 0x28` / `li 0x1E` / `li 0x0F` in one small function) finds
   `0x8865C648`, the 0/15/30/40 converter. Its unit
   (`auto_03_8865C578_text.obj`) and the vtables that reference it
   (`0x880F4900..0x880F4A60`) are the scoring classes.
3. The code compares 32-bit constants everywhere. They are **zlib CRC-32 of
   case-sensitive names**: `python3 -c "import zlib;print(hex(zlib.crc32(b'Standard')))"`
   prints `0xe981b5d1`, which is the constant the scoring-class factory selects the
   ordinary tennis class with. The same hash resolves `Let` (`0xC9238771`),
   `Fault` (`0x5E11F1A7`), `Withdrawal` (`0x22703895`), `EndOfPoint`
   (`0x87B1920F`), `KingOfTheCourt` (`0xFB595DB2`), `Minigame` (`0x6D2794E5`),
   `LetIn` (`0x8F903DFB`), `LetOut` (`0x02315629`), `Miss` (`0xC222A5E0`),
   `ServiceMissBall` (`0x3C1D5115`), `Normal/Important/Crucial`.
   A dictionary of every string in the DLL plus word-combination brute force was used
   (scratch tools only; not committed).
4. Disassembly: `TS4_JOB=rules work/venv/bin/python tools/disasm.py 0x8866A1C8`.
   `tools/disasm.py` stops at the first VMX instruction, so for a few functions a
   skip-data capstone loop over the same split objects was used instead.

## 2. Architecture

The match is driven by a gameplay "owner" object (call it `Match`, passed as
`this+4` of every scoring object). It has these relevant members [V]:

| Owner offset | Meaning |
| --- | --- |
| +0x28 | game-mode object; byte +0x40 = mode forces the match to end, +0x44 = its winner [I] |
| +0x30 | flow-flags block "B30" (section 3.5) |
| +0x38 | game configuration; +0x1D0 = game format hash, +0x1D4 = first-to-N target for the mini-game classes, +0x1E0 = single-serve flag [V] |
| +0x40 | match rules configuration (section 3.6) |
| +0x44 | rules-state block "B44". It embeds the published `RulesInfo` at +0x90 |
| +0x48 | point-end info; `[0]` is the CRC-32 of the end-of-point reason |
| +0x4C | event/statistics object |
| +0x50 | per-player situation records (stride 0x10) |

A scoring object ("scoring class") is created by `fn_88676028`
(`Scoring_CreateClassForFormat`, 0x200 bytes), which switches on the game-format
hash `Match+0x38 -> +0x1D0` [V]:

| Format hash | Vtable | Object size | Role |
| --- | --- | --- | --- |
| `0xE981B5D1` = `Standard` | `0x880F4900` | 0x24 | **real tennis** (this document) |
| `0xDA442B95` (unnamed) | `0x880F4948` | 0x14 | first-to-N mini-game scoring (class B) |
| `0xD8898BEC` (unnamed) | `0x880F4990` | 0x1C | first-to-N scoring (class C) |
| `0xDC5643EE` = `Percentage` | `0x880F49D8` | 0x10 | reason-driven +1/-1 scoring (class D) |
| `0x5EC3EE35` (unnamed) | `0x880F4A20` | 0x1C | winner-takes-point, loser resets (class E) |

Only the Standard class implements games, sets, deuce and tie-breaks. The umpire
code also treats B..E as "numeric score" modes (it prints raw point counts) [V].

### Standard scoring class (vtable `0x880F4900`) [V unless noted]

Object layout (size 0x24):

| Offset | Field |
| --- | --- |
| +0x00 | vtable |
| +0x04 | owner (`Match*`) |
| +0x08 | pointer to `RulesInfo` (`owner->B44 + 0x90`) |
| +0x0C | games needed to win a set (6; 0 when sets are decided by a single tie-break) |
| +0x10 | number of sets in the match (1, 3 or 5) |
| +0x14 | unused/unknown [U] |
| +0x15 | final set is a 10-point super tie-break |
| +0x18 | tie-break change-of-ends counter |
| +0x1C | tie-break serve-switch counter |
| +0x20 | match over |

Vtable slots (byte offsets from the vtable pointer):

| Slot | Function | Proposed name |
| --- | --- | --- |
| +0x04 | `0x8866A5E0` | `StdScoring_Init` |
| +0x10 | `0x88677058` | `StdScoring_StartMatch` |
| +0x14 | `0x88676FB0` | `StdScoring_InitServeState` [I] |
| +0x18 | `0x8866A1C8` | `StdScoring_OnPointEnd` |
| +0x1C | `0x8865C648` | `Scoring_RefreshDisplayScore` |
| +0x20 | `0x8865C308` | `Scoring_GetPointWinner` |
| +0x24 | `0x88669CF8` | `StdScoring_PointWinsMatch` |
| +0x28 | `0x88676668` | `StdScoring_ClassifyPointImportance` |
| +0x2C | `0x886764A0` | `StdScoring_UpdateLeadStats` [I] |
| +0x30 | `0x88676228` | `StdScoring_UpdateSetMatchPointFlags` |
| +0x38 | `0x88676AF0` | `StdScoring_UpdateServerAndEnds` |
| +0x3C | `0x8866A188` | `StdScoring_ResetCounters` |
| +0x40 | `0x88676DB0` | `StdScoring_AddPoint` |

Non-virtual helpers: `0x88676960` GameWon, `0x8866A060` SetWon, `0x88676898`
StartGame, `0x8865C578` StartSet, `0x88669F30` TotalGamesPlayed, `0x88669C30`
ResetScoreRecords, `0x88669878` PublishPointEndFlags.

## 3. Data layout

### 3.1 RulesInfo block ("R", at `B44+0x90`) [V]

Offsets are relative to R. The umpire reads the same block as `ctx+0x30 + 0x90 + off`.

| Off | Type | Meaning |
| --- | --- | --- |
| +0x09 | u8 | **second serve** flag (0 = first serve). Umpire picks LetFirstServe/LetSecondServe with it |
| +0x24 | rel32 | self-relative pointer to the player table (`Q = R+0x24 + *(R+0x24)`) |
| +0x28 | s32 | player count (2) |
| +0x30 | s32 | **current set index**, 0-based |
| +0x34 | u8 | **tie-break active** (also set for the super tie-break) |
| +0x35 | u8 | **super tie-break** (10 points) |
| +0x36 | u8 | deuce (40-all) |
| +0x37 | u8 | exactly 3-3 in points (first deuce) |
| +0x3D | u8 | point ended (umpire point-call trigger) [V use, I name] |
| +0x3E | u8 | trigger consumed by `Rules_PublishPointEndFlags` [I] |
| +0x3F | u8 | let flag (umpire let-call trigger) [V use, I name] |
| +0x40 | u32 | CRC-32 of the last point-end reason |
| +0x44 | u8 | game over event for the umpire |
| +0x45 | u8 | set over event |
| +0x46 | u8 | match over event |
| +0x47 | u8 | match ended by withdrawal/forced end |
| +0x48 | s32 | winner of the last awarded point (-1 = none); also the forced-end winner |
| +0x4C, +0x4D | u8 | change-of-ends request after a game (not in tie-breaks) [I] |
| +0x64 | u32 | point importance: CRC-32 of `Normal`, `Important` or `Crucial` |
| +0xE0 (B44) | s32 | **points needed to win the current game**: 4, 7 (tie-break), 10 (super tie-break), 1 (short format) |
| +0x54 (B44) | s32 | **current server** (0/1) |
| +0x58 (B44) | s32 | hash of the serve side (even or odd point count) |

### 3.2 Player table

`Q` holds two player records, stride **0x18**:

| Off | Meaning |
| --- | --- |
| +0x00 | self-relative pointer to the per-set array (entries of 12 bytes) |
| +0x04 | number of entries in that array (sets capacity) |
| +0x0C | **raw point count in the current game / tie-break** |
| +0x10 | **sets won** |
| +0x14 | **display score**: 0, 15, 30, 40, or **-1 = holds advantage**; the raw count inside tie-breaks |

Player `p` is at `Q + p*0x18`, the opponent at `Q + (1-p)*0x18` [V].

### 3.3 Per-set entry (12 bytes)

| Off | Meaning |
| --- | --- |
| +0x00 | games won in this set |
| +0x04 | last recorded point count (written on every point; what remains after a tie-break is the tie-break score shown as 7-6(5)) |
| +0x08 | byte: set is decided by a single game (set threshold <= 1: tie-break-only set or super tie-break) |

### 3.4 Serve/ends block ("S", at `B44+0x48`) [V for fields written by `UpdateServerAndEnds`]

| Off | Meaning |
| --- | --- |
| +0x00 | self-relative pointer to two 8-byte team entries |
| entry+0x00 | doubles rotation index (only meaningful when `B30+0x327` is set) |
| entry+0x04 | CRC-ish hash naming the end of the court the team is on (two constants `0x317C51B7` / `0xA2EDA1E7`) |
| +0x0C | server index |
| +0x10 | hash `0x23BAED9E` when the points played in the game are even, `0xD826E563` when odd (serve side) |

The hash names for these four constants were not found.

### 3.5 Flow flags "B30" (`Match+0x30`)

| Off | Meaning |
| --- | --- |
| +0x91 | game over this point |
| +0x92 | set over |
| +0x93 | match over |
| +0x94 | players changed ends this update |
| +0x95 | service fault this point |
| +0x310 | frame counter used by the judges |
| +0x327 | doubles (team size 2) |
| +0x328 | judging disabled/forced mode; when set the fault logic is skipped [I] |
| +0x32A | the point ended in the serve phase |
| +0x32C | match progress fraction (written by `0x8865C3D8`) [I] |

### 3.6 Match rules configuration (`Match+0x40`)

Written by script command `InitMatchRules` (handler `0x88792D48`; registered by
the function at `0x887B41E8`). Arguments in order: games per set (int), number of
sets (int), then four booleans parsed from the strings "true"/"false":

| Off | Value |
| --- | --- |
| +0x04 | games per set (6) |
| +0x08 | number of sets (1, 3, 5) |
| +0x0C | when non-zero, sets are decided by a single tie-break game (gamesToWin becomes 0) [I] |
| +0x0D | final-set super tie-break (10 points) |
| +0x0E | stored 6th argument [U]; also tested as an "already started" flag by `StartMatch` |
| +0x0F | stored 5th argument [U] |
| +0x78 | game-format hash. `0x4035E2DF` selects a short format (1 game per set, 1 set, 1 point per game); not resolvable by name |

## 4. Rules decoded

### 4.1 Point to game (`StdScoring_AddPoint`, `0x88676DB0`) [V]

```
AddPoint(w):                       # w = winner from GetPointWinner
    rec[w].points += 1
    for both players: set[cur].tb_points = rec.points
    target = B44.pointTarget       # 4, 7, 10 or 1
    if rec[w].points >= target:
        if lead >= 2  or  (tiebreak and points == 99)  or  short_format:
            GameWon(w)
    stats update (fn_88674ED0)
    if tiebreak and totalPoints != 0:           # totals are 0 after GameWon resets
        if totalPoints % 6 == 0: this.tbChangeovers += 1
        if totalPoints % 2 == 1: this.tbServeSwitches += 1
```

- Deuce/advantage have no limit: a player must lead by 2 once at 4+ points. There is
  **no no-ad variant** in the standard class.
- Tie-break points are not capped except by the odd rule that 99 points ends it
  immediately (the predicate also special-cases 98-98).

### 4.2 Display score (`Scoring_RefreshDisplayScore`, `0x8865C648`) [V]

```
c0, c1 = raw point counts
if not tiebreak and (c0 > 3 or c1 > 3):
    equal  -> display 40/40, deuce flag
    c0>c1  -> display[0] = -1 (advantage), display[1] = 40
    else   -> display[0] = 40,  display[1] = -1
else:
    display = tiebreak ? raw count : {0:0, 1:15, 2:30, 3:40}[count]
    if c0 == 3 and c1 == 3: deuce flag and first-deuce flag
```

The umpire calls the score as "Deuce" only when the counts are equal and the
player count is >= 4; at the first 3-3 it calls the plain score `40-40` [V].
The server's score is called first [V].

### 4.3 Game won (`0x88676960`) [V]

```
GameWon(w):
    games[w][cur] += 1
    (statistics: love-game counter for w if the opponent has 0 points)
    both players' points = 0
    setWon = tiebreak  or  (games[w] >= gamesToWin and games[w] - games[l] >= 2)
    if setWon: SetWon(w)
    if not matchOver: StartGame()
    flags: game over event (B30+0x91), stats event
```

### 4.4 Start of a game (`0x88676898`) [V]

```
if games[0][cur] == gamesToWin and games[1][cur] == gamesToWin:
    if not tiebreak: tiebreak = true; pointTarget = 7
else:
    tiebreak = false
    pointTarget = short_format ? 1 : 4
```

So at **6-6 in every set, including the deciding set, a 7-point tie-break is played**;
there is no advantage-final-set variant [V]. With `gamesToWin == 0` (tie-break
only sets, or the super tie-break set) 0-0 already satisfies the test.

### 4.5 Set and match (`0x8866A060`, `0x8865C578`) [V]

```
SetWon(w):
    sets[w] += 1
    if numSets-1 == cur  or  2*sets[w] > numSets:  matchOver = true (B30+0x93)
    else: cur += 1; StartSet()
    set over event (B30+0x92)

StartSet():                          # from StartMatch and after a set
    if finalSetSuperTB and numSets-1 == cur:
        tiebreak = superTiebreak = true; gamesToWin = 0; pointTarget = 10
    else: superTiebreak = false
    set[cur].singleGameFlag = (gamesToWin <= 1)
```

So `finalSetSuperTB` replaces the **whole deciding set** by a single 10-point
tie-break (win by 2).

### 4.6 Tie-break serving and ends (`0x88676AF0`) [V formula, I intent]

```
totalGames = sum over sets 0..cur of (games0+games1)             # 0x88669F30
server     = (this.tbServeSwitches + totalGames) mod 2           # player index 0 serves game 1
serveSide  = (points0 + points1) mod 2                           # even: first court
ends       = (sum over sets 0..cur of ceil(games/2)  +  this.tbChangeovers) mod 2
endsChanged = ends != previous ends                              # B30+0x94
```

- Ordinary games: change of ends after games 1, 3, 5, ... of each set, including
  after an odd final game; none after even games [V].
- Tie-break: first point served by the player whose turn it is; then the server
  changes after point 1, 3, 5, ... (serve switch counter counts odd totals); ends
  change after every 6 points (`total % 6 == 0`) [V].
- For doubles the entry index `((games+switches)/2) mod 2` rotates the serving
  partner [I, low].

**Quirk [V formula, U whether intended]:** the last point of a game is never counted
in the switch counter (points are already reset), so the first server of the next
set after a tie-break depends on how many points the tie-break lasted, and does
not always equal "the player who received first in the tie-break". The reference
implementation reproduces the decoded formula.

### 4.7 Serve rules (`0x8866A1C8` + `0x88669878`) [V]

`OnPointEnd` is called once per point with the reason hash in `owner->0x48[0]`.

```
if matchOver: return
if not (B30+0x32A  /* point ended in the serve phase */):
    award = true; fault = false
else:
    winner = GetPointWinner(info)
    fault  = (winner != -1) and (winner != server) and (B30+0x328 == 0)
    B30+0x95 = fault
    if fault:  award = secondServe or cfg.singleServe        # double fault
    else:      award = (reason != Let)
if award:
    w = GetPointWinner(info); AddPoint(w); UpdateServerAndEnds(); Refresh; R+0x48 = w
else:
    R+0x48 = -1
PublishPointEndFlags:
    if fault and not secondServe and not singleServe:  secondServe = 1
    elif secondServe and (state is LetIn/LetOut) and not fault and not singleServe: secondServe = 1
    else: secondServe = 0
    if reason == Withdrawal: secondServe = 0
```

Consequences:

- **First serve fault** (a point that ends in the serve phase and is won by the
  receiver): no point, `secondServe = 1`.
- **Second serve fault = double fault**: the receiver is awarded the point
  (the crowd/stat function shows "Double fault"); `secondServe` resets.
- **Let** (reason `Let`, `0xC9238771`): `GetPointWinner` returns -1, nothing is
  awarded, the serve number is kept. The umpire calls `LetFirstServe` or
  `LetSecondServe` from `R+0x09` [V].
- **Single serve option** (`GameConfig+0x1E0`): the first fault already loses the point.
- The serve judge (`0x886A8170`) classifies the serve trajectory: net-cord and
  landing in (`LetIn` state) emits `Let`; net-cord and landing out (`LetOut`)
  emits `Fault` at the net-contact frame; a first bounce outside the box emits
  `Fault` at the bounce frame; a missed ball emits `Miss` (`0xC222A5E0`); a further
  reason `0x7DDEC718` is emitted at a third timeline frame and `0x79EE9B03` when the
  serve is judged against the server in the first branch [I]. Their names are unknown.
- **Foot fault:** no foot-fault reason, string or hash was found [U]. Do not assume
  one exists.
- `GetPointWinner` (`0x8865C308`): winner is the "last hitter" index stored at
  `B30+0x7C`, except reasons `Miss` and `0x79EE9B03` (winner = the other player),
  `ServiceMissBall` (`0x3C1D5115`, the last-hitter value is inverted first),
  `Withdrawal` (winner = 1 - loser stored at `B44+0x64`) and `Let` (-1) [V].

### 4.8 Forced end / withdrawal (`0x8866A1C8` branch) [V]

Taken when the reason is `Withdrawal`, or the game mode object requests it
(`Match+0x28 -> +0x40`, winner `+0x44`), or the short format is past set 0. All
three event flags (game, set, match) are raised, `R+0x47 = 1`, `R+0x48 = winner`,
the winner receives `numSets/2 + 1` sets (set entries filled with
`gamesPerSet` games and tie-break value 7), the opponent 0, and the current set
index becomes `numSets/2`. A single-set match with the super tie-break flag
records 1 game and tie-break value 10.

### 4.9 Set point / match point and importance [V formula, I use]

- `StdScoring_UpdateSetMatchPointFlags` (`0x88676228`): game-level set point for a
  player when not in a tie-break and `games >= gamesPerSet-1` and he leads in
  games; in a tie-break both players are flagged. Match point when his sets won
  equal `(numSets-1)/2`.
- `StdScoring_PointWinsMatch` (`0x88669CF8`): would the next point win the game,
  then the set (tie-break or `games+1 >= gamesToWin` with a 2-game lead), then the
  match (last possible set, or `2*(sets+1) > numSets`).
- `StdScoring_ClassifyPointImportance` (`0x88676668`) writes `Normal` /
  `Important` / `Crucial` at `R+0x64`. In a tie-break the total of both players'
  points decides (>= 5 important, >= 9 crucial); outside tie-breaks it uses the
  `R+0x38..0x3A` situation flags, the games lead and the server's lead [I]. A
  second threshold pair (7 and 15) is tested only for `R+0x35` without `R+0x34`
  and is therefore not reached by real matches [I].
- `0x88685060` builds the crowd/AI "end of point modifiers" text and uses the same
  fields for "Game point", "Set point", "Match point", "Ace", "Double fault", "Let".

### 4.10 Umpire calls (`0x8888E828` dispatcher) [V]

Per frame, in this priority:

1. Set over event (`R+0x45`, not yet announced) -> `Umpire_AnnounceSet`.
2. Game over event (`R+0x44`) -> `Umpire_AnnounceGame`.
3. Point ended, not match over, not after a first-serve fault (`R+0x09` clear),
   reason not `Let` -> `Umpire_AnnouncePoint`.
4. Let reason with the let flag -> `Umpire_AnnounceLet` (cycling a 4-entry variant table).

String selection:

- Point: `Rally%s/%i-%i` with the server's score first, `Deuce` (equal and count >= 4),
  `Advantage|<player>` (a display value of -1), and tie-breaks `TieBreakNormal/%iAll`,
  `BeginWith/%i|EndWith/%i` (leader first).
- Game: `GameNormal/Game|<winner>` plus a games-all or "Leads/Lead %i game to %i" sentence;
  `TieBreak` for target 7, `SuperTieBreak` otherwise.
- Set: `SetNormal/%i-%i` per set (one-game sets use the tie-break begin/end strings with
  the stored tie-break points), `GameSetAndMatch|<winner>` when the match is over,
  `GameAnd%iSet` with the set count otherwise.

## 5. Constants

| Rule | Value | Where |
| --- | --- | --- |
| Display points | 0, 15, 30, 40; advantage -1 | `0x8865C648` |
| Points to win a game | 4, win by 2 (unlimited deuces) | `0x88676898` |
| Games to win a set | `cfg+4` (6), win by 2 | `0x88676960` |
| Set tie-break | at games 6-6 (`gamesToWin` both), 7 points, win by 2, cap at 99 | `0x88676898`, `0x88676DB0` |
| Super tie-break | replaces the deciding set when `cfg+0xD`; 10 points, win by 2 | `0x8865C578` |
| Sets | 1, 3 or 5; clinch when `2*sets > numSets` | `0x8866A060` |
| Tie-break serve | switch after point 1 then every two points | `0x88676DB0`, `0x88676AF0` |
| Change of ends | after odd games of each set; every 6 tie-break points | `0x88676AF0` |
| Second serve | one fault allowed unless single-serve | `0x88669878` |

## 6. Other scoring classes (summary)

B..E are used by non-tennis formats (the hash `0xDA442B95` is referenced by the
mini-game and King-of-the-Court preparation code). They share the same RulesInfo layout and
`GetPointWinner`, but use `GameConfig+0x1D4` as a first-to-N target:

- C `0x8865C818`: winner points++, game over when lead >= 2 and points >= target.
- E `0x8865CBD8`: winner points++, loser reset to 0, game over at target.
- D `0x8865CF88`: reason-driven: some reasons give the winner +1, others subtract 1 from
  the loser; both clamped at 0; then the C rule.
- B `0x8866B1C8` / `0x8865D3C0`: not decoded [U].

Each also implements a forced-end `OnPointEnd` (`0x8865C920`, `0x8865CCD0`,
`0x8865D108`, `0x8865D3C0`).

## 7. Not decoded / unknown

- The hash names for the serve-side, ends, format (`0x4035E2DF`), and three of the
  serve reason hashes (`0x7DDEC718`, `0x79EE9B03`, `0xA03CA0ED`).
- How the initial server is chosen: the formula above uses player slot 0 as the first
  server; a toss/choice step (if any) must happen outside these functions [U].
- The rally judge `0x886A84C0` (out / net / double bounce reasons) was only skimmed.
- The doubles rotation arithmetic, statistics updates (`0x88674ED0`, `0x88674D58`),
  `0x886764A0`, and the match-progress fraction `0x8865C3D8` are low confidence.
- Whether the quirk in section 4.6 is a genuine game behaviour; no ITF correction was found.
- No no-ad scoring, no final-set advantage, and no foot-fault logic exists in the
  standard class [V for the first two; foot fault: not found].

## 8. Verification

```
TS4_JOB=rules work/venv/bin/python tools/disasm.py 0x8865C648     # display scores
TS4_JOB=rules work/venv/bin/python tools/disasm.py 0x88676DB0     # AddPoint
cc -std=c11 -Wall -Wextra -Werror ref/gameplay/rules.c ref/gameplay/test_rules.c -o /tmp/rules_test && /tmp/rules_test
TS4_JOB=rules work/venv/bin/python tools/try_match.py src/xbox360/gp_rules_8865CBC0.c --at gp_rules_init_8865CBC0=0x8865CBC0 -v
```

Matched functions (listed in `work/agents/rules/manifest.json`):
`0x8865CBC0` (`gp_rules_init_8865CBC0`), `0x8865C558` (`gp_rules_get_winner_8865C558`),
`0x88676950` (`gp_rules_update_stats_88676950`).
