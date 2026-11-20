# GP5 notes: ball / net / umpire event classification (WP5), WP4 start

Scope: Swing_DLL.xex (module sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`,
symbols.txt sha256 `ec79e191534b9b28aa58772c7e3b9112ce120957930a3d6ea7658a1c167b9d5d`).
Compiler: MSVC 16.00.10224.00 (PPC), flags `/O2 /Oi`, via `python3 tools/fn_check.py` (see commands below).
All offsets/addresses below are measured from `tools/fn_asm.py` output and `tools/sym_info.py` data dumps.

## 1. What this code is

0x8888A000-0x88890000 is the **sound-event controller of the Swing module** (the class whose vtable has
`play` +0x28, `commit` +0x2c, `prepare` +0x34, `set_volume` +0x3c).  It does **not** simulate the ball. It reads the
rally/physics event record ("rally state" R, controller+0x30) that the PhysicEngine wrapper fills and turns it into
FMOD event paths (`Root/Ball/...`, `Root/Umpire/...`, `Root/PlayerSounds/...`).  That makes it the cleanest place in
the binary where the game *names* its own shot / bounce / net-hit categories.

Analysed functions (size): fn_8888D700 (0x22C) shot name, fn_8888CFD0 (0x150) bounce name, fn_8888D328 (0x3D4)
collision-material name, fn_8888EBE8 (0x8D4) per-frame ball event pass, fn_8888ADC0 (0x79C) player cue dispatcher,
fn_8888A658 (0xB4) play helper, fn_8888E828 (0x3C0) umpire dispatcher, fn_8888C7E8 / CB48 / CCE8 / CF40 / C620 / C540
umpire builders.

## 2. Name hashes (important for porting)

Every enum in this layer is a **CRC32 of the ASCII name, seed 0** (`fn_88608590`; table `lbl_880C84C0` is the standard
zlib table, `zlib.crc32(name) == game hash`).  Names were recovered by brute force over strings in the binary
(`tools/sym_info.py str`) plus small guess vocabularies.  Resolved:

| hash | name | where |
|---|---|---|
| F578057A | Flat | stroke type R+0x174 |
| 7EB30F90 | Smash | stroke type |
| D9FA1B37 | TopSpin | stroke type |
| C718DAAA | Lob | stroke type |
| 990377A5 | DropShot | stroke type |
| FC6F57A1 | Slice | stroke type (volume select) |
| 007925F4 / 70D81E2F / 4FA695A1 | WoodUp / WoodSide / WoodDown | racket-frame hit direction, R+0x168 |
| A053865E | Ground | contact kind R+0x168 |
| CAA7531F / C9238771 | Net / Let | contact kind |
| 6127B0EC / BC1789F5 / 69CCB0F7 / 4679AD1C | Hard / Clay / Grass / Carpet | court surface; 1436B81A = Indoor |
| 0B352785 | Shot | player sound event |
| EF823202 / 555999B1 | Effort / ReachAnimation | player sound events (grunt effort) |
| E79E1444 / 7E9745FE / 3DBC0C95 | Bounce01 / Bounce02 / BallHit | player sound events |
| 3689AB7E / 319DC754 / D5973F7E / AA7AEBC4 | Dive / TunnelStep / TunnelJump / TunnelBagSound | |
| EEFAA65F / 77F3F7E5 / 00F4C773 | Racket01 / Racket02 / Racket03 | |
| DBE48D14 / A108392D / ADACB502 / 2E20A34E | Never / Always / PowerfulShot / Service | per-player grunt setting, player+0x34 |
| F5BF4F97 | Male | player+0x0C (gender) |
| 5026F7B4 / C92FA60E | TypeA / TypeB | voice type, player+0x38 |
| 53F9901F | Pro | player name kind (real pro player) |
| CD0B222F | Single | match type, match+0x22C |
| FB595DB2 | KingOfTheCourt | game mode, match+0x238 |
| FE32DF8D | School | match type |
| DE9BF1C4 | Replay | match+0x1C0, suppresses live sound |
| D400E765 / C0BA51F5 / 18C45490 | Ball / Environment / Standalone | contact-record object types |
| 80CB558B / CE712E50 | Umpire / Announcer | audio buses |

Unresolved (no name found): D8898BEC, DC5643EE, 5EC3EE35, DA442B95 (match+0x1D0 modes), 290F9F49, 93458B98,
F177AE1A, 01DFAA59, A38D7FC5, 1AD280AF / 83DBD115 / F4DCE183 (GruntVictory01-03 sound events),
BF9D9C32 / 2694CD88 (GruntFrustration01-02).

## 3. Shot classification (fn_8888D700)

Inputs in the rally state R: `R+0x164` frame_hit (u8), `R+0x168` contact kind hash, `R+0x174` stroke hash,
`R+0x178` power (f32, 0..1), `R+0x95` coarse flag (u8).  Decision order:

1. frame_hit and kind in {WoodUp, WoodSide}: `Root/Ball/Shot/Wood`
2. frame_hit and kind == WoodDown: `Root/Ball/Shot/FlatWeak`
3. stroke == DropShot: `Root/Ball/Shot/Drop`
4. else power word + family:
   * family: Flat or Smash -> `Flat%s`; TopSpin or Lob -> `TopSpin%s`; anything else (Slice, ...) -> `Slice%s`
   * power word, `R+0x95 != 0` (3 buckets; probably "this is a serve", unconfirmed):
     p < 0.4 -> "" ; p < 0.7 -> "Strong" ; else "Powerfull"
   * `R+0x95 == 0` (5 buckets): p < 0.2 "Powerless"; < 0.4 "Weak"; < 0.6 ""; < 0.8 "Strong"; else "Powerfull"
   (thresholds are `g_ts4_script_constants` pool entries +0x10C=0.2, +0x118=0.4, +0x114=0.6, +0x110=0.8 and
   `lbl_880D0938`=0.7).
There is **no lob/volley/serve class here**: Lob is folded into TopSpin, Smash into Flat.  The five stroke hashes
Flat/Smash/TopSpin/Lob/DropShot/Slice are however the game's own stroke enum in R+0x174, so any port should reuse
those six categories.

## 4. Bounce classification (fn_8888CFD0)

Controller fields: `C+0x48..0x50` ball velocity xyz at the bounce, `C+0x54` speed (f32).  Impact angle ratio =
`-vy / speed` (dot product with (0,-1,0) done with `vmsum3fp128`; Y is up, so this is sin of the descent angle).
Event path `Root/Ball/Bounce/%sAngle%sSpeed`:

* angle word: ratio < 0.30 "Small"; < 0.45 "Medium"; else "Large"   (pool +0x564 = 0.3, +0x464 = 0.45)
* speed word: speed < 40 "VerySlow"; < 55 "Slow"; < 75 "Medium"; else "Fast"   (pool +0x404, +0x688, +0x604)
  Speed units are those of the physics wrapper (probably m/s; unconfirmed).  The same buckets are reused for
  fixed player-sound events Bounce01 = MediumAngleSlowSpeed, Bounce02 = LargeAngleMediumSpeed.
That is 3 x 4 = 12 bounce classes.  Plain "Root/Ball/Bounce/MediumAngle%sSpeed" is material 15 of the collision table.

## 5. Net / let and scenery collisions (fn_8888EBE8, fn_8888D328)

* contact kind Net (CAA7531F) or Let (C9238771) -> `Root/Ball/Collision/Net_%s`, `%s` = "Slow" if the first contact
  record's speed < 25.0 (pool +0x61C) else "Fast".  So **net-hit and let detection is a physics flag, not code**: the
  sound layer only sees R+0x168 == Net/Let (set by the physics event queue).  The *rules* "let" is separate:
  R+0xCF && R+0xD0 == Let makes the umpire say `LetFirstServe` / `LetSecondServe` (R+0x99 selects second serve).
* scenery contact records (blob at controller+0x3c, stride 0x24, 8 records): `+0 s32 material_a, +4 s32 material_b,
  +8 f32 speed_a, +0xC f32 speed_b, +0x10/+0x14 u32 object-type hashes, +0x20 u8 active`.  Name =
  `Root/Ball/Collision/<Material>_<Slow|Fast>`; material id 1..29 -> Bag, Bench_Metal, Bench_Wood, Billboard,
  Box_Metal, Box_Plastic, Box_Wood, Camera, Chair_Fabric, Chair_Metal, Chair_Plastic, Chair_Wood, Cover_Fabric,
  Cover_Plastic, Grid, (15 = MediumAngle bounce), Microphone, (17 = Net), Plant, Post, Wall_Concrete, Wall_Glass,
  Wall_Wood, Wall_Grass, Cube_Leather, Bench_Leather, Sphere_Rubber, Frame_Metal, Shard_Glass.
* the "School" match type (TopSpin School) has its own pass over all 8 records with Ball / Environment / Standalone
  object-type combinations.

## 6. Player cue dispatcher (fn_8888ADC0)

See drafts/gp5_ball_events.c.  Per-player grunt rules: setting `Never` / `Always` / `PowerfulShot` / `Service`
(player+0x34), voice = gender (Man/Woman) + voice type A/B/other (`%02i` = 0,1,2).  Gains are floats in the tuning blob
of match context +0x28 (+0x490..+0x4C8); the surface (Hard+Indoor, Clay, Grass, Carpet) selects one of four ten-float
volume curves (blocks at +0x28, +0x50, +0x78, +0xA0 of the blob at +0x480).  Voices are taken round-robin from
pools of hashed FMOD ids: pool A (4, lbl_88C6BE08), pool B (8, lbl_88C6BE38), pool C (4, lbl_88C6BE58).

## 7. Umpire

Score is announced from a **self-relative score table** (`S = R+0x90`, tables at `S+0x24`), per team a 0x18-byte record
{per-set games offset, ?, ?, ?, sets won, current point}.  Point values: -1 = advantage side marker; tie-break
announcements ignore values > 30.  Full wording table and branch conditions in drafts/gp5_umpire_cues.c.
Dispatcher fn_8888E828 plays each cue once per event (flags controller+0x58..0x5d), split at '|' into FMOD segments.

## 8. Ball-event structs (field list is the deliverable; names are role guesses)

Rally state R (controller+0x30), offsets seen: +0x54 s32 serve-order flag, +0x90 score block (§7), +0x95 u8 coarse/serve?,
+0x96 u8, +0x99 u8 second serve, +0xA4 u8, +0xCD/+0xCF u8, +0xD0 u32 event hash (Let), +0xD4/+0xD5/+0xD6/+0xD7 u8,
+0x100 s32 plural flag, +0x110 hit block, +0x164 u8 frame_hit, +0x168 u32 contact kind, +0x174 u32 stroke,
+0x178 f32 power, +0x198 u8, +0x19A u8 racket-hit-this-frame, +0x19D u8, +0x19F u8, +0x1A0 u8, +0x234 u8 scenery contact.
Typed view used by the matched code: `src/xbox360/gp5_types.h`.

## 9. WP4 start (fn_8887C108, PhysicEngine world creation, 0x27C bytes)

`fn_8887C108(this, cfg)`: ensures `this+0x1C` is a 0x200-entry pointer vector (0x800 bytes) and `this+0x28` a 4-entry
vector (0x10 bytes) (grows with fn_88613570, copies, frees the old one); builds a `hkpWorldCinfo` on the stack
(fn_884758C0), copies gravity (cfg+0, +4, +8, w = 0.0 from lbl_8814B440) and cfg+0x1C (f32, first scalar argument of
fn_88475A30), cfg+0x0C (int, fn_88475780), cfg+0x10 (int, byte at stack 0x11d), cfg+0x18 (byte), cfg+0x20 (f32);
copies cfg+0x24/0x28/0x2C/0x14 into this+4/+0xC/+0x14/+8; sets a TLS timer flag (KeTlsGetValue, fn_8841A510 with 0x310);
creates the world `this+0x10 = fn_8846E050(&cinfo, ...)`; calls fn_88439630(world+0x74) and finally
`fn_8887B148(this, 0x26296DD2)` (hash-id registration).  Gravity, collision tolerance and solver values are
**config inputs**, not literals (consistent with docs/gameplay-map.md section 3).  fn_8887B148 / B458 / AB50 / F190 not started.

## 10. Reproduction and matching notes

Commands (run from the repo root):

* `python3 tools/fn_asm.py fn_8888D700` ... disassembly of each function.
* `python3 tools/sym_info.py str 0x880DE544` ... strings; `python3 tools/sym_info.py data 0x88C6BE08 0x60` voice pools.
* `python3 tools/fn_check.py src/xbox360/gp5_umpire_player_name.cpp ts4_umpire_player_name_8888C540=0x8888C540`
  -> MATCH size 0xDC.
* `python3 tools/fn_check.py src/xbox360/gp5_umpire_announce.cpp ts4_umpire_let_call_path_8888CF40=0x8888CF40
  ts4_umpire_player_name_cue_8888C620=0x8888C620` -> two MATCH (sizes 0x8C, 0x1C8) plus
  `RENAME fn_8856ABA0 -> memset` and `RENAME fn_8888C540 -> ts4_umpire_player_name_8888C540`.

Compiler facts learned (useful to other families):

* `fn_8856ABA0` **is the CRT `memset`**.  Every `char buf[N] = ""` in this module compiles to
  `stb 0; memset(buf+1, 0, N-1)` and the matching compiler references symbol `memset`, so fn_check reports
  `RENAME fn_8856ABA0 -> memset`.  An explicit call to `fn_8856ABA0` cannot reproduce the instruction schedule
  (the `li` of the stored zero is hoisted differently), `#pragma intrinsic(memset)` with `buf[0]=0; memset(buf+1,0,N-1)`
  does reproduce it.  532 other references to fn_8856ABA0 exist, so the rename is a global decision: the two functions
  that need it are in `work/specs/GP5/pending/`.
* The MSVC original reserves a gap of ceil16(8 * nargs of the widest call) bytes above the 0x50 linkage area before the
  first local (e.g. 0x20 for a 3-argument `ts4_format_text`, 0x40 for 7).  The matching compile does not, so the gap is
  reproduced by wrapping the local buffer in `struct { char reserved[GAP]; char text[N]; }` (`Gp5Scratch<GAP,N>`).
  (The same trick appears in the existing `ts4_tsu_format_and_assign`.)
* `Gp5Str256` (0x110 bytes: begin, end, char[0x100], +0x108 pointer to storage+8) is an eastl::fixed_string-like type.
  ctor from `const char*` = fn_881A5020 (returns this), assignment = fn_8816D090.  Returning one by value with
  `return Gp5Str256(text)` compiles to exactly the original (RVO into r3).  To place several results in a controlled
  stack order call the callee through its hidden return pointer (`void f(Gp5Str256 *ret, ...)`) into members of one
  struct.
* C++ globals need `extern "C"` blocks or the relocation names are mangled and fn_check rejects them.
* Self-relative tables: `p = &obj->field; q = (char*)p + *p` is the idiom; re-evaluating it at every use (not hoisting)
  matters for register allocation.
