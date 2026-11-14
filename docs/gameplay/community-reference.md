# Top Spin 4 gameplay: public and community reference (agent R1)

This note gathers what 2K, the press and players documented publicly about how Top Spin 4 (Xbox 360,
2K Czech, 2011) plays. Its purpose is to give engineers decoding `Swing_DLL.xex` a list of the
behaviours to look for, and the names the public uses for them. It is **not** evidence about the code.
Every claim below is something a person wrote. The last section turns the claims into testable
hypotheses.

The skills/coaches catalogue is in `data/gameplay/skills_community.yaml`. Disc-derived ground truth
already in the repo is cited as **[repo]** where it confirms or contradicts a public claim. The main
files are `data/gameplay/traits_skills.yaml` (in-game skill names and texts from `StringTable.bin`),
`data/gameplay/coaches_career.yaml` (coaches, level-up packs, AI difficulty) and
`docs/gameplay/controls-and-shot-selection.md` (input path).

## 0. Method, provenance and confidence tags

- Research ran on 2026-11-14 with the session's WebSearch and WebFetch tools. Most community hosts
  refused direct fetches: GameFAQs, Operation Sports forums, Lowyat, jeuxvideo.com, gamer.com.tw,
  GameSpot, TrueAchievements, MobyGames and StrategyWiki returned HTTP 403, intertopspintour returned
  403/503, and topspinsuperguides.com does not resolve in this sandbox. web.archive.org is blocked.
  For those pages the content comes from **search-engine snippets**, marked *(snippet)*. A snippet is
  a short extract, so wording can be cut, and in one case (the superguide coach table) the order is
  garbled.
- **Full reads:** the Xbox 360 printed manual PDF, the Just Push Start patch article, the PlayStation
  Blog developer post, Worthplaying, Hotwire3D, Gamereactor, VideoGamer, Destructoid, Game Informer's
  career preview, the CBS News preview, a pixnet (Chinese) review, a PTT (Chinese) career post and
  Wikipedia.
- Manual PDF: `https://www.videogamemanual.com/xbox360/Top%20Spin%204.pdf`, 860.7 KB, sha256
  `959994c9ee593fabae54332014a6ec68076097a4bca662d9b4ec5f8a0c7c46e9`. Text was taken with
  `pdftotext` (poppler-utils, the version shipped in this container) in both raw and `-layout` modes.
  It is the short printed manual. It points to a fuller online manual at
  `www.2ksports.com/manual/top-spin-4`, which I could not retrieve.

Confidence tags:

| tag | meaning |
|---|---|
| **OFF** | official: manual, 2K/2K Czech staff, 2K-announced patch notes |
| **PRESS** | review or preview text (journalist describing what they saw) |
| **COMM** | community; several independent posters or a fan guide agree |
| **SINGLE** | one forum poster / one fan page, unconfirmed |
| **REPO** | matches disc data already extracted in this repo (strong cross-check) |
| **TS3 / 2K25** | from another game in the series; clearly not TS4 evidence |

## 1. Controls (Xbox 360)

### 1.1 Button map (OFF, manual)

The manual prints buttons as glyphs from the Xbox "Convection" symbol font. I mapped them to buttons
from where they sit on the controller diagram and from other sources (column "how mapped").

| input | manual label | how mapped |
|---|---|---|
| Left stick | "Move / Aim", "Move player / Aim" | text |
| A | "Flat serve / Flat shot / Normal volley" | text |
| B | "Top Spin serve / Top Spin shot / Power volley" | text |
| X | "Slice serve / Slice shot / Control volley" | text |
| Y | "Lob / Replay" ("Replay after a point") | text |
| Right stick | "Advanced serve": "(swing) + L (aim)" | text |
| **RT** | "Drop shot modifier"; Drop shot = **RT + X** | diagram right-trigger slot; a Chinese review says the drop shot is "RT+X" ([pixnet](https://notebooklover.pixnet.net/blog/post/44784757), PRESS) |
| **LT** | "Inside out modifier"; Inside out = **LT + A, B or X** | diagram left-trigger slot (M confidence) |
| **RB** | "Serve & volley modifier / fast reposition"; RB alone = Fast reposition; RB + A/B/X = Serve & volley | diagram right-bumper slot; Hotwire3D says "The RB button controls speed" ([review](https://hotwire3d.com/top-spin-4-xbox-360-review/), PRESS) |
| LB | "N/A" | diagram left-bumper slot |
| Back | "Various" | diagram |
| Start | "Pause menu / Resume game" | diagram |

- Manual pro tip: to rush the net, "hold X to prepare a slice shot, hold [RB], use [L] to aim, then
  release X". The slice "gives you time to reposition" and RB "moves you toward the net quickly"
  (OFF).
- The PlayStation Move scheme was described by gameplay designer **Rémi Ercolani**. Drop shot = slice
  + Move button. Lob = L2 + swing. "Serve and volley / shot followed to the net" = L1 + swing or serve.
  **Drop volley = control volley + Move button**. Inside out = play a forehand motion on a backhand
  ball (and the reverse), which "forces" that stroke
  ([PlayStation Blog](https://blog.playstation.com/2011/03/14/top-spin-4-serves-up-playstation-move-stereoscopic-3d-tomorrow/),
  OFF). This confirms that "follow to the net", "drop shot", "drop volley" and "inside out" are
  separate shot modifiers in TS4.
- **There are no TS3-style risk shots in TS4.** One review says risk shots "have been dumped
  completely", replaced by hold-to-charge power versus tap-to-control (*(snippet)* via search, PRESS).
  An Indian Video Gamer review says the game is "more predictable" without them (PRESS, snippet). For
  contrast, TS3 used RT as the power/risk modifier and LT as the precision/line modifier
  ([bit-tech TS3](https://bit-tech.net/reviews/gaming/xbox/top-spin-3/1/),
  [GameSpot TS3 hands-on](https://www.gamespot.com/articles/top-spin-3-hands-on/1100-6188393/), TS3).
  **[repo]** The code still has an `@Risk` input set by LT **or** RT, and "Risky" shot-template rows
  12-15 that the retail tree cannot reach (`controls-and-shot-selection.md` §0, §6.1). That fits a
  TS3 holdover that TS4 turned into the drop-shot modifier.
- In the TS4 in-game skill texts, inside out is written "(℮ + a shot button)" and the drop shot
  "(ℯ + ℥)" (**[repo]** `traits_skills.yaml`). These glyphs are LT and RT + X, consistent with the
  manual.
- The 2011 balancing update added D-pad movement ("Directional buttons player control added") (OS
  forum, *(snippet)*, COMM).
- Grokipedia says the right stick plays groundstrokes and the drop shot is "right stick down + slice"
  ([page](https://grokipedia.com/page/Top_Spin_4)). This conflicts with the manual. Treat it as
  **unreliable**.

### 1.2 Shot charge: Normal, Control and Power (OFF)

The manual names three shot strengths for A/B/X:

- **Normal shot**: "the basic shots". They "don't have any particular strength or weakness".
- **Control shot**: "tap a shot button". It gives "precision placement", and "Power is sacrificed for
  precision".
- **Power shot**: "A long press and hold". It is "more susceptible to going out or into the net if you
  have bad timing".
- Flat (A): "powerful, straight swings. The longer you press and hold A, the more powerful the swing."
  Topspin (B): "fast, precise balls", used to "cross the ball very wide, or push your opponent back".
  Slice (X): "slow, precise balls", for defending or rushing the net.
- Pro tip: release the button "at the moment when your player should begin his or her swing".
  "Sooner is always better than later!" (OFF). This implies the late-timing penalty is harsher than
  the early one.
- Press: a filling circle beside the player shows charge (Gamereactor and other previews, PRESS).
  A pixnet review describes a "red ring" for power and a white crosshair marker for control shots
  (PRESS). Holding too long "doesn't cause a complete miss", but the shot "more likely to skew wide"
  ([VideoGamer](https://www.videogamer.com/reviews/top-spin-4-review/), PRESS).
- **[repo]** The code has three tiers: Finesse (power < 0.15), Medium (0.15 to 0.70) and Powerful
  (>= 0.70) (`controls-and-shot-selection.md` §0.4). These match Control, Normal and Power. In the
  skill texts "Finesse" is the in-game word for a control shot ("Flat Finesse", Shot counter).

### 1.3 Timing feedback (OFF + PRESS)

- The optional **Timing display** (Options > IN-GAME HELPERS > TIMING DISPLAY) "grades your swing".
  "Shot quality is based on button release timing. Wait too long to release ... quality suffers" (OFF).
- Grades: **Too Early / Good / Perfect / Too Late**, shown over the player's head
  ([Hotwire3D](https://hotwire3d.com/top-spin-4-xbox-360-review/); GameSpot via snippet, PRESS).
  A "PERFECT" hit also gives rumble and a heavier impact sound (pixnet, PRESS).
- Off-timed swings "might not produce the best shots, but they won't produce poor shots, either"
  ([Worthplaying](https://worthplaying.com/article/2011/3/23/reviews/80484-ps3x360-review-top-spin-4/),
  PRESS). GamesRadar says late hits lose speed and accuracy, and that the training advice ("release
  before the actual return animation starts") felt "nebulous, inconsistent" (snippet, PRESS).
- Community release rules (SINGLE, GameFAQs "Timing question", snippet): release a normal shot just
  after the bounce, a slice after the bounce, and a topspin later, on the rising ball. Timing depends
  on distance to the ball, not on the bounce alone (another poster). Others advise that a perfect
  normal shot beats a mistimed power shot.
- Volleys: "The press and hold duration doesn't matter when performing a volley; only timing does"
  (OFF, manual).
- An achievement, "Metronome", rewards consecutive perfect-timed shots (TrueAchievements, snippet).
- **[repo]** The GoodTiming graph window is |t| < 0.3 at skill 0 and widens to |t| < 0.8 at skill 1
  (`controls-and-shot-selection.md` §0.8). Coach objectives count "balls with a good timing (or
  better)" (`coaches_career.yaml`, objective `GoodTimingShotCount`).

### 1.4 Aim and helpers

- The left stick aims and moves. A "first bounce" marker shows where the incoming ball lands, and a
  yellow cross shows where your own shot will land (Gamereactor, Hotwire3D, GameSpot via snippet,
  PRESS). Stick depth controls how deep or wide the shot goes. The drop shot "can land deep unless the
  left stick is held back" (OS/GameFAQs, snippet, SINGLE).
- The helpers can be turned off. One fan claim says that with auto positioning, a glitch gave perfect
  timing on every shot even with low stats
  ([Steam 2K25 thread](https://steamcommunity.com/app/1785650/discussions/0/4516632348042834638),
  secondhand, SINGLE, unverified).

### 1.5 Serve (OFF)

- Toss with A (flat), B (topspin) or X (slice). "The duration of your button press varies the power of
  the swing. Release the button to deliver the serve."
- **Normal serve**: tap. **Power serve**: "hold A, B, or X until the ball is at the top of the toss,
  then release." While hitting, aim with the left stick "to avoid hitting out or into the net".
- **Advanced serve**: pull the right stick down to toss, "wait to time your shot with the top of the
  toss", then push the stick: one direction gives flat, one slice, one topspin. The printed glyphs are
  ambiguous. A Chinese review gives forward = flat (powerful), up-left = slice (curves left) and
  up-right = topspin (high bounce), and says a perfect right-stick serve is faster than a standard one
  (pixnet, PRESS). The Move version maps the toss direction differently: straight up = flat, up-right =
  slice, up-left = topspin (PS Blog, OFF, Move only).
- "When you perform a Power serve or an Advanced serve, the timing of the release is very important.
  The perfect timing is when the ball is at the peak of its trajectory" (OFF). On Move, "The closer to
  the peak of the ball toss, the more powerful the serve" (Ercolani, OFF).
- Serve aim depends on "holding down a direction for a certain amount of time" (VideoGamer, PRESS).
  Community tips (SINGLE, snippets) say to hold the stick toward the target for about a second during
  the toss, or to press the stick a split second before contact. Aiming at the lines often goes out
  even on a "perfect" serve.
- The advanced serve gives the highest speed and the most aces, at a cost in accuracy (fan guides,
  COMM). The 2K producer said a skilled Roddick serves "130, 140 mph"
  ([CBS preview](https://www.cbsnews.com/news/preview-2k-czechs-top-spin-4/), OFF).
- Serve & volley: hold RB while serving (manual: "RB + A, B, or X") (OFF).

### 1.6 Net play, volleys, smash, lob, specials

- Volleys come in three kinds: A normal, B power, X control. A drop volley is a control volley plus
  the drop modifier (OFF, manual + PS Blog). The game also has low volleys and semi-volleys (half
  volleys), since skills exist for both (**[repo]** skills `LowVolleySpecialist`, `SemiVolleyKing`).
- **Smash** replaces the stroke automatically when the ball is overhead. The manual says the opponent
  may "get behind" a lob and "return it as an overhand smash" (OFF). **[repo]** Smash is a context
  flag, not a button (`controls-and-shot-selection.md` §0.2).
- **Lob**: Y. "There really is no offensive or defensive lob" in TS4, but **holding Y makes the lob
  move faster**, more like a topspin lob (topspinsuperguides, snippet, COMM).
- **Between-the-legs (tweener)**: this happens on its own when you chase down a lob. "Depending on
  your positioning to the ball", the player either swings from the side or hits between the legs. It
  "puts a lot of air under the ball" (superguide, snippet, COMM). GameFAQs posters report hitting
  tweeners with little power that keep the rally alive, and that one can occasionally be a winner
  ([thread](https://gamefaqs.gamespot.com/boards/605746-top-spin-4/58557413), snippet, SINGLE).
- **Reach and stretch shots**: hard-to-reach balls come back as weak "rescue" shots. The skill Reach
  swings expert makes them better (see §4). The press notes that TS4 removed the "accidental"
  slipping and diving of earlier games (Hotwire3D, PRESS).
- **Spectacular volleys**: the skill "Expand your arsenal of Volleys to perform spectacular shots"
  (**[repo]**). This implies some volley animations only play if the player has the skill.
- **Approach / follow-to-net**: RB + shot. A 2K tip sheet says "a slice shot followed to the net
  (RB + X) aimed at the side of the court" is one of the most efficient ways to the net
  ([Time Techland tip sheet](https://techland.time.com/?p=74129), snippet, OFF). Fan tip: use RB when
  the opponent is around the service line coming in, not when they are already at the net (snippet,
  SINGLE).
- **Momentum in movement**: players "skid after a direction change", so movement must be planned
  ahead (Worthplaying, PRESS). The producer said "Some tennis games ... turn on a dime"; TS4 is about
  "the real tennis battle" (CBS, OFF).

### 1.7 Animations

- The developer diary describes motion capture of every movement and shot, more than 8,000 animations,
  and signature animations for each pro (Capsule Computers / cyberludus coverage of dev diary 1,
  snippet, OFF). Reviews say animations "slide into each other" (Gamereactor) with "no abrupt changes"
  (Worthplaying) (PRESS). **[repo]** Clip names include `Swing_FH_Fatality_*` (`animation_clips.yaml`).
  These suggest the Fatality skill or reward plays dedicated put-away swings.

## 2. Stamina, fatigue and momentum

- A **Fatigue gauge** fills from power shots and running (Gamereactor, GameSpot via snippet, PRESS).
  2K tip sheet: fatigue rises "when you need to run fast and when you play powerful shots". Its impact
  is "slower movement and slower reaction time as well as less precise shots". Use control shots to
  wear an opponent down (Time tip sheet, snippet, OFF).
- Normal movement barely drains energy. Long rallies and power shots "take a heavy toll". Energy only
  partly recovers between points, and "it isn't a full refill". Tired CPU players may give up chasing
  balls (Worthplaying, PRESS).
- Gauge colours (Grokipedia: yellow and red zones) are **unverified**.
- **No "In the Zone" or confidence meter in TS4.** The oscillating RT risk meter tied to an "In the
  Zone" meter belongs to Top Spin (2003) (GameSpot TS1 review via snippet, TS1). No TS4 source
  mentions a zone meter. However, the skill **Highly flammable** says you "become on fire" on a
  winning streak of four or more points in a set (**[repo]**), which is a skill-gated hot streak.
- **[repo]** The data has a FatigueIngame analyser graph and an "excitement" accumulator
  (`gp4b.md` §10, `src/xbox360/drafts/gp1_excitement.c`).

## 3. Attributes, styles and progression

### 3.1 Attributes

- There are eight attributes: four technical (**Forehand, Backhand, Serve/Service, Volley**) and four
  physical (**Power, Stamina, Speed, Reflexes**) (dev diary 4 via jeuxvideo, snippet, OFF;
  superguide, COMM). Reflex replaced TS3's "Return of Serve" (superguide, snippet, COMM).
- Described effects (COMM unless noted):
  - Stamina keeps accuracy and speed up in long points.
  - Higher Serve makes serves easier and more accurate.
  - A low Volley (under 50) makes net play a losing proposition (single poster); you must time volleys
    very precisely unless Volley is high (Indian Video Gamer, PRESS).
  - Speed: the September 2011 patch made "low speed players ... slower" to reach wide balls (OFF).
  - Power is "no longer the easy path to dominance" (Destructoid, PRESS).
- **[repo]** `pro_players` columns are Serve, Return, Reflex, Forehand, Backhand, Volley, Power, Speed,
  Stamina, Mental, Overall. Return and Mental are hidden ratings. In every row Return equals Reflex and
  Mental is 30.

### 3.2 Styles and level-ups

- Each level-up raises one of three tracks: **Serve & Volley**, **Offensive baseline** and
  **Defensive baseline**. The overall level is the sum, capped at **20** in total. You cannot assign
  individual attributes (Destructoid, Game Informer, Worthplaying, Gamereactor, PRESS; GameFAQs, COMM).
- Style descriptions:
  - S&V: precise serves and net coverage.
  - Offensive: power from the baseline; "fills Power faster" but is slower on court.
  - Defensive: speed, stamina and spin variety; accurate control shots with wide reach.
  - Sources: reviews (PRESS); PTT career post
    ([pttweb](https://www.pttweb.cc/bbs/PlayStation/M.1301121995.A.30A), SINGLE).
- Style icons: yellow net (S&V), red ball (offensive), blue crosshair (defensive) (pixnet, PRESS).
  Federer is a hybrid of the three.
- Reaching level 20 once lets later created players start with levels and see their coach lists
  (Destructoid, PRESS).
- **[repo]** `coaches_career.yaml` `player_evolution.packs` holds the per-level gains for each style
  (`VolleyFinessePlayer`, `BaselineAttacker`, ...). Example: S&V level 1 gives Serve +4, Volley +4,
  Speed +1, Reflex +3.

### 3.3 Coaches

- Coaches come in **Bronze, Silver and Gold** tiers.
  - Press counts vary: "nearly 50" (Hotwire3D), "about 100" (Destructoid), "more than a 100" (Game
    Informer), "more than 30" (MobyGames, snippet).
  - **[repo]** The data holds 110 coaches: 20 at level 1, 37 at level 2 and 53 at level 3.
- Tier rules (topspinsuperguides, snippet, COMM):
  - bronze +25 attribute points, silver +35, gold +50;
  - no single attribute gets more than +15;
  - the snippet also says "20 Gold coaches" and "13 Silver coaches". It is garbled, so check it against
    the repo data.
- Bronze coaches give mostly XP bonuses: "10% XP", "20% XP", and per-winner XP at the net or the
  baseline. Silver and gold coaches add attribute bonuses and **skills** (Destructoid, PRESS;
  **[repo]** `coach_only_abilities`).
- Which coaches you can hire depends on how your levels are spread ("some require a minimum
  investment in a given area") (Destructoid, PRESS). **[repo]** Each coach has `conditions` (hire
  tests such as `LesserThan 8` / `GreaterThan 1`).
- Coach bonuses unlock step by step through objectives. Examples: "10 aces against your coach"
  (GameSpot first impressions, snippet); "50 slice shots or eight aces" (Grokipedia, unverified).
  **[repo]** There are four objectives per coach (for example "Perform 15 topspin serves", "Hit 15
  winners at the net"), and each ability has an `unlock_step` 0-4.
- Only one coach is active at a time. Switching coaches loses the previous coach's bonuses, though
  some reviews say learned skills stay ("permanently learned skills", Worthplaying). Sources conflict
  on this (Gamereactor and VideoGamer say bonuses are lost on switching; PRESS).
- Skills from coaches also apply online (superguide, snippet, COMM).
- Pro players have up to 3 skills; created players get up to 2 (MobyGames, snippet). One GameFAQs
  thread claims gold coaches have 2 skills and a few have 3 (SINGLE).
- Achievement "Golden boy": unlock all the skills of a Gold Coach (snippet, OFF).
- Easter egg: coach names include **Rémi Ercolani** (the gameplay designer) and Czech names (Tomas
  Madr, Pavel Dlouhy, Roman Neuwirth) (**[repo]**). Some coaches seem to be named after 2K Czech staff.

## 4. Skills (traits)

The full table with sources is in `data/gameplay/skills_community.yaml`. The in-game texts are
**[repo]**-confirmed (`traits_skills.yaml`, 32 entries from `StringTable.bin`). Community descriptions
agree with them closely; most posts look copied from the in-game text.

| skill (in-game name) | internal code [repo] | trigger / effect as described | community notes |
|---|---|---|---|
| Shot counter | PowerfulShotCounter | well-timed **Flat Finesse** (tap A) uses the power of the opponent's shot | strong vs power hitters |
| Return serve counter | ReturnServeCounter | same, against a serve | rarely discussed |
| Reach swings expert | ReachSwingsExpert | better shots "on the run and stretching" | best defensive skill (FR forum); "makes all your control shots on the run better" (ITST) |
| Passing shot sniper | PassingShotSniper | more precise when the opponent is at the net | |
| Crushing passing shot | CrushingPassingShot | more powerful when the opponent is at the net | |
| Spectacular volleys | SpectacularVolleys | unlocks spectacular volley animations | S&V |
| Longer, better! | BetterOnLongRallies | more precise and reliable as the rally lengthens | "good" (FR) |
| Highly flammable | HighlyFlammable | "on fire" after a streak of 4 or more points in a set | split: weakest vs very effective; hard to trigger |
| Poisoned slices | PoisonedSlices | low slices force less efficient replies | "completely nullified Monster Defense" (SINGLE) |
| Diesel returner | DieselReturner | returns improve during return games | |
| Instant rocket | InstantRocket | reach max power sooner on power shots | "minimal difference" (FR) vs strong online (ITST) |
| Diesel hard hitter | DieselHardHitter | power shots grow more precise during a rally | |
| Inside out master | InsideOutMaster | more powerful inside-out (LT) shots | |
| Focus service | FocusService | better serves when trailing in the game | tuned in Apr 2011 update |
| Wrong foot expert | WrongFootExpert | more precise when you wrong-foot the opponent | the Destructoid "wrong-foot bonus" |
| Amazing first volley | Amazing1stVolley | first volley of the rally more efficient | |
| Slice invasion | SliceInvasion | slice gets more efficient with use in a rally | |
| Topspin invasion | TopSpinInvasion | topspin gets more efficient with use in a rally | meta: "TI/MD is still king" (ITST) |
| Fatality | Fatality | more precise when aiming at the open court | Chinese guide: big angles |
| Approach shots expert | ApproachShotsExpert | approach shots harder to counter | |
| Monster Defense | TenaciousCockroach | more precise, fewer errors when trailing in the game | meta skill, paired with TI |
| Semi-volley king | SemiVolleyKing | shots just after the bounce are no problem | |
| Diesel server | DieselServer | serves improve during your serve games | |
| Spin serve master | SpinServeMaster | "devastating" topspin and slice serves | |
| Volley shots artist | VolleyShotsArtist | standard, control and drop volleys more efficient | |
| Low volley specialist | LowVolleySpecialist | low volleys no longer a problem | |
| Smell of blood | SmellOfBlood | more efficient shots on your game point | "opposite of monster defense" |
| Serve stick berserker | ServeStickBerserker | more precision on powerful **advanced** (right-stick) serves | tuned in Apr 2011 update |
| Drop shot artist | DropShotArtist | "innate talent" for drop shots (RT + X) | tuned in Apr 2011 update |
| Brutal volley | BrutalVolley | power volleys (B) more efficient | |
| Return sixth sense | Return6thSense | rumble before the serve shows its direction | **not in any public source; no coach or pro owns it [repo]**, probably cut |
| Emergency reactivity | EmergencyReactivity | faster transitions after a bad own shot or a good opponent shot | **not in any public source; unowned [repo]**, probably cut |

Names that appear publicly but are **not** TS4 skills:

- "No Mercy" (MobyGames): not in the string table. The unresolved hashes in the pro skill lists are
  attribute bonuses (**[repo]**: for example `538a6bbf` = Stamina +5).
- "Diesel Serve" / "Diesel Return of Serve": informal names for Diesel server / Diesel returner.
- "Spin Serve Berserker": a snippet garble.
- "Net Rusher", "Lob Artist": not found anywhere.
- TS2K25 reuses many of these names (Slice Invasion, Wrong Foot Expert, Serve Stick Berserker) with
  different effects. Do not mix them up.

## 5. AI and difficulty

- Difficulty levels are **Very Easy, Easy, Normal, Hard, Very Hard, Expert** (**[repo]**: 6 per AI
  style, 9 styles).
  - An achievement guide calls Very Hard "Expert" in menus (trophieshunter, snippet). That conflicts
    with the repo, which lists both; the guide is probably wrong.
  - Reviews call Expert "rediculous" (sic) (OSFTW review, snippet).
  - The pixnet review mentions a "Legend" difficulty unlocked through achievements. That is
    unconfirmed for TS4 and may be confused with the Legend career rank or with 2K25.
- Very Easy and Easy are "pushovers"; Normal makes "every point tough to win but not impossible"; Hard
  and Very Hard are for veterans (Worthplaying, PRESS). On the higher levels the AI largely avoids
  unforced errors (review snippet, PRESS). One GameFAQs/PTT post says the hardest level still felt easy
  (SINGLE).
- After the September 2011 patch, players reported the CPU making more unforced errors (OS "New Top
  Spin 4 Balancing Update" thread, snippet, COMM).
- Play styles: each pro has a style (S&V, offensive, defensive, hybrid). AI pros play to type. It is
  "pointless" to out-hit Nadal; Becker and Sampras dominate if allowed to control the net (VideoGamer,
  PRESS; producer at CBS, OFF). On Wii, baseliners stay "rooted to the baseline" (Wii review, PRESS,
  other platform).
- One reviewer felt an "invisible handicap" that stopped a strong created player from winning easily
  on any difficulty (Hotwire3D, PRESS, SINGLE). This could be a rubber-band mechanic or just
  perception.
- **[repo]** AI records weight `ShotComponents.*`: Flat, TopSpin, Slice, Lob, DropShot, FollowToNet,
  PressAndHold, RiskyShot and the aim side/length choices. These correspond to the human modifiers
  above.

## 6. Patches

| date | name | changes | source / confidence |
|---|---|---|---|
| ~2011-04-11/12 | **"Player Balancing Update"** (2K called it an update, separate from the patch) | "Tuning of Power serves and Advanced serves"; "Tuning of the following skills: Serve Stick Berserker, Drop Shot Artist, Focus Service"; "Directional buttons player control added" | [OS forum thread](https://forums.operationsports.com/forums/tennis/477387-top-spin-4-player-balancing-update-available.html), snippet; Lowyat repost, snippet; COMM, quoting 2K. Posters: it "diminished my ace serving capability"; serves now "just normal big serve" (SINGLE) |
| 2011-05-09 | Title update (patch) | no balance changes: modded-profile detection (360), D-pad, lobby/NAT/lag-animation fixes, World Tour fixes, 2K Open rating fix, stats visibility fix, PS3 trophy exploit | [Just Push Start](https://www.justpushstart.com/2011/05/top-spin-4-patch-released/) (cited by `research_notes/.../ts4_meta.md`); [Pasta Padre](https://www.pastapadre.com/2011/05/09/top-spin-4-patch-details) (503 here) |
| announced 2011-09-17, rollout "Monday" (~09-19) | Gameplay balance patch (360/PS3) | 1. "Shots in good situations have been improved" (good timing + position = more precise and efficient). 2. "Bad and average drop shots are less efficient" (land farther from the net, bounce higher). 3. "Shots in defensive situations have been slightly reworked" (defensive slices weaker and less precise; defensive flats a bit more powerful). 4. "Players with a higher stamina will last longer before being tired". 5. "Tired and low speed players are slower" (harder to reach far balls). 6. "Returns with a bad timing are less efficient" (land shorter) | [Just Push Start](https://www.justpushstart.com/blog/2011/09/17/new-gameplay-patch-coming-for-top-spin-4/) (full read), OFF via 2K announcement |

- **[repo]** `docs/additional-content.md` records Title Update #1. Whether TU1 contains the September
  balance changes, the April update, or both should be settled by diffing TU1 data against the disc
  data (`Settings.bin`, `Expressions.bin`).

## 7. Meta, exploits and hidden mechanics (community)

- **Serve dominance at launch**: complaints about "unreturnable serve after unreturnable serve" online
  led to the April serve tuning (OS thread, snippet, SINGLE + OFF response).
- **Online meta**: "TI/MD is still king" (Topspin Invasion + Monster Defense)
  ([ITST TS4 Matchups](https://intertopspintour.com/forum/viewtopic.php?f=1032&t=14624), snippet,
  SINGLE). Matchup lore: Instant Rocket beats Topspin/Slice Invasion and can beat Reach Swings Expert
  "but is tough"; Poisoned Slices "nullified monster defense" (SINGLE). A defensive build with high
  speed and stamina, Slice Invasion and Reach Swings Expert was reported as strong (SINGLE).
- **Control-shot rallies** are the sound default; power shots drain stamina and cost precision
  (superguide, COMM; 2K tip sheet, OFF).
- **Drop shots**: tuned twice (the Drop Shot Artist skill in April; weak drop shots in September). The
  TS1 "Death Drop Shot" net-cord exploit was a different game (thexbfl TS FAQ, TS1).
- **Wide-angle serve exploit** dates from TS2 (same FAQ, TS2). No TS4-specific confirmation was found.
- **Returns underpowered** for most players (superguide, snippet, COMM). The September patch also
  weakened badly timed returns.
- Hidden ratings: Return and Mental exist in the data but are not shown (**[repo]**).
- Two cut skills (Return sixth sense, Emergency reactivity) exist in the string table
  (**[repo]**); no public mention found.

## 8. Hypotheses to verify in code

Each item is a concrete, testable claim taken from the public record. Repo pointers are starting
points only.

**Input and shot selection**

1. **LT and RT both set `@Risk`, and Risk only turns Slice into a drop shot or drop volley.** The
   manual gives LT as the *inside-out* modifier and RT + X as the drop shot. Test whether LT + X also
   gives a drop shot in the original (an input quirk). Also test whether inside-out reads
   `Buttons/@LT` directly, forcing forehand on backhand balls (and the reverse) in stroke-side
   selection rather than in the shot tree. Find the code that forces the stroke side.
2. **RB = follow-to-net / fast reposition.** RB + a shot sets `ShotComponents.FollowToNet` and moves
   the player forward after the shot. RB on a serve gives serve & volley. LB is "N/A" in the manual;
   `@ReqSpeedSwing` / `@ReqBaselineRepos` on LB may be dead or debug-only.
3. **Control / Normal / Power = Finesse / Medium / Powerful.** A tap gives lower speed and smaller
   error dispersion. A hold gives higher speed, and the error grows *faster* with timing deviation
   ("more susceptible to going out ... if you have bad timing").
4. **Late timing is penalised more than early timing** ("Sooner is always better than later"). Expect
   an asymmetric timing-to-quality curve (BaselineTimingAbility / GoodTiming graphs) and four output
   bins, TooEarly / Good / Perfect / TooLate, for the HUD.
5. **Volleys ignore charge.** On a volley path the power value is not read; only timing matters.
6. **Holding Y makes a faster lob** (a power-tier lob row is selected), and there is no separate
   defensive lob.
7. **Smash is automatic** from the overhead context flag; there is no button for it.

**Serve**

8. **Power serve quality peaks at the toss apex.** Serve power (and accuracy) is a function of
   |release time - apex time|, with the maximum at the apex.
9. **The advanced serve is faster than the power serve, at higher error.** Serve stick berserker
   raises the precision of advanced serves only. Expect the April 2011 tuning to show as differing
   serve speed or error constants between the disc and TU1.
10. **Serve aim scales with how long the left stick is held** during the toss/swing, not only with
    its direction at contact.

**Physical state**

11. **Fatigue rises with sprinting and power shots, and lowers move speed, reaction time and shot
    precision.** Stamina sets the drain rate. Recovery between points is partial.
12. **The September 2011 patch changes are data deltas**: higher precision for good-situation shots;
    longer and higher-bouncing weak drop shots; weaker defensive slice and stronger defensive flat;
    slower drain for high stamina; a larger speed penalty when tired or with low Speed; shorter
    badly timed returns. Diff the TU1 analyser graphs against the disc.
13. **Momentum when changing direction**: players skid or decelerate before reversing (movement
    planner; `gp3.md`).

**Skills**: all should be graph inputs `Profile.SkillList[crc32(code)].Value` or `HasSkill`
(`fn_8868F0D8`) checks.

14. **Instant rocket** shortens the charge time to full power (a smaller divisor `D`, or a scaled
    power curve).
15. **The "Diesel" and "Invasion" skills scale with a counter**: rally length (Longer better, Diesel
    hard hitter), games or points played in serve/return games (Diesel server, Diesel returner), and
    the number of same-type shots in the current rally (Topspin/Slice invasion). Find those counters.
16. **Score-state skills read the match score**: Monster Defense and Focus service when trailing in
    the game; Smell of blood on the player's own game point; Highly flammable at 4 or more
    consecutive points won in the set (the "on fire" state).
17. **Position-state skills**: Passing shot sniper and Crushing passing shot when the opponent is at
    the net; Fatality when the aim is toward the open court; Wrong foot expert when the aim is behind
    an opponent moving the other way; Reach swings expert on stretch/reach swings; Approach shots
    expert on follow-to-net shots.
18. **The counter skills** (Shot counter, Return serve counter) need stroke = Flat, tier = Finesse,
    good timing and a fast incoming ball. The output is extra speed derived from the incoming ball's
    speed. **[repo]** The consumer graph `491e53f5` outputs `PowerfulFactor` from
    `ManualShotTiming`.
19. **Poisoned slices affects the opponent**: a low slice lowers the receiver's shot quality. The
    graph should read the *opponent's* skill, or an incoming-ball property set when the shot is hit.
20. **Spectacular volleys gates animation selection** (volley clip sets only available with the
    skill). The `Fatality` clips (`Swing_FH_Fatality_*`) may be a put-away animation set linked to
    the Fatality skill or reward.
21. **Return sixth sense and Emergency reactivity** are probably cut. Check whether any code or graph
    reads their CRCs (`7dcc9c04`, `ffd369ce`). If the rumble hint code exists, it is an unused
    feature.

**Career and AI**

22. **Coach bonus budget**: bronze 25, silver 35 and gold 50 points, with at most 15 per attribute,
    unlocked over `unlock_step` 0-4 through four objectives. Check against `CoachList.bin`.
23. **Level cap of 20 in total across the three tracks.** Per-level gains come from
    `PlayerEvolution.bin` packs.
24. **AI difficulty modulates shot-choice weights and error.** Expect 6 levels × 9 styles. Expert
    should have the lowest unforced-error rate. Look for a hidden catch-up or "handicap" term
    (rubber-banding) on the player.
25. **Tired CPU players give up chasing** balls they judge unreachable (an AI reach or effort
    threshold tied to fatigue).
26. **Tweener and side-swing on lob chases** are chosen by the player's position relative to the ball
    when running back. The result is a high, slow recovery ball.

## 9. Sources

Official:

- Xbox 360 printed manual: https://www.videogamemanual.com/xbox360/Top%20Spin%204.pdf (mirror of
  http://epix.xbox.com/shaXam/0201/0a/2a/0a2a6260-233c-43b2-8591-a4a1669eba01.PDF)
- PlayStation Blog, R. Ercolani: https://blog.playstation.com/2011/03/14/top-spin-4-serves-up-playstation-move-stereoscopic-3d-tomorrow/
- CBS News preview (producer M. Kelly): https://www.cbsnews.com/news/preview-2k-czechs-top-spin-4/
- September patch announcement: https://www.justpushstart.com/blog/2011/09/17/new-gameplay-patch-coming-for-top-spin-4/
- Time Techland tip sheet (snippet): https://techland.time.com/?p=74129

Press:

- https://worthplaying.com/article/2011/3/23/reviews/80484-ps3x360-review-top-spin-4/
- https://hotwire3d.com/top-spin-4-xbox-360-review/
- https://www.gamereactor.eu/top-spin-4-preview/
- https://www.videogamer.com/reviews/top-spin-4-review/
- https://www.destructoid.com/preview-top-spin-4-player-creator-career-more/
- https://gameinformer.com/games/top_spin_4/b/xbox360/archive/2011/02/24/more-on-top-spin-4-39-s-career-mode.aspx
- https://notebooklover.pixnet.net/blog/post/44784757
- https://en.wikipedia.org/wiki/Top_Spin_4
- https://www.gamespot.com/reviews/top-spin-4-review/1900-6305154/ (snippet)
- https://www.gamesradar.com/top-spin-4-review-11/ (snippet)

Community (mostly snippets):

- http://www.topspinsuperguides.com/topspin4.htm
- http://www.topspinsuperguides.com/Top_Spin_4.html
- https://forum.lowyat.net/topic/1679805/+420
- https://forums.operationsports.com/forums/tennis/477387-top-spin-4-player-balancing-update-available.html
- https://forums.operationsports.com/forums/forum/other-sports/tennis/425707-new-top-spin-4-balancing-update
- https://intertopspintour.com/forum/viewtopic.php?f=1032&t=14624
- http://www.intertopspintour.net/forum/viewtopic.php?t=15388
- http://www.intertopspintour.net/forum/viewtopic.php?t=14002
- https://www.jeuxvideo.com/forums/1-25025-117376-1-0-1-0-evolution-la-plus-efficace-d-un-joueur.htm
- https://forum.gamer.com.tw/C.php?bsn=4794&snA=106
- https://www.pttweb.cc/bbs/PlayStation/M.1301121995.A.30A (full read)
- https://gamefaqs.gamespot.com/boards/605746-top-spin-4/59004617
- https://gamefaqs.gamespot.com/boards/605746-top-spin-4/58557413
- https://gamefaqs.gamespot.com/boards/605746-top-spin-4/58515521
- https://gamefaqs.gamespot.com/boards/605747-top-spin-4/58947469
- https://www.mobygames.com/game/65583/top-spin-4/

Other games (context only): https://bit-tech.net/reviews/gaming/xbox/top-spin-3/1/,
https://www.gamespot.com/articles/top-spin-3-hands-on/1100-6188393/, http://www.thexbfl.com/TSFAQ2.htm,
https://www.charlieintel.com/games/best-topspin-2k25-skills-how-to-unlock-322101/

Not reachable from this sandbox (worth a local read): topspinsuperguides.com (DNS), GameFAQs, Operation
Sports forums, Lowyat, ITST, jeuxvideo, gamer.com.tw (all 403/503), and the full 2K online manual.
