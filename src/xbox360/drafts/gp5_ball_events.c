/*
 * GP5 draft: per-frame ball / net / player sound-event pass of the Swing sound controller
 * ("controller" below).  Not compiled into the matching build.  Plain C.
 *
 *   fn_8888EBE8 0x8888EBE8 (2260 B)  per-frame pass: racket hit, ground bounce, net/let, scenery contacts
 *   fn_8888ADC0 0x8888ADC0 (1948 B)  player sound dispatcher: grunts, rackets, dive, tunnel, bounce01/02
 *   fn_8888A658 0x8888A658 (  180 B)  "play" helper used by both
 *   fn_8888F4C0 0x8888F4C0           caller of fn_8888EBE8 (not analysed)
 *
 * Confidence: structure and constants high; field *names* are role guesses from the strings
 * they select (marked `?`).  There is no physics here: this is the layer that turns the
 * physics-event record (PhysicEngine wrapper, WP4) into FMOD cues.
 *
 * Controller layout seen so far (offsets in the controller object):
 *   +0x00 vtable   slot 0x28 play(id*, name, 0,0,0)   slot 0x2c commit(id*)
 *                  slot 0x34 prepare(id*)             slot 0x3c set_volume(id*, f32)
 *   +0x28 match context (hashes for game mode / match type; also the table of volume scalars
 *         at +0x480 (self-relative blob) and +0x490..+0x4C8 floats)
 *   +0x2c court surface object (+0x10 surface hash, +0x14 / +0x1c qualifiers)
 *   +0x30 rally state R
 *   +0x3c contact-record blob (see gp5_ball_classify.c)
 *   +0x44 u8 / +0x45 u8   "racket hit already handled" / "ground contact already handled"
 *   +0x58..+0x5d u8       umpire announcement already played (E828)
 *   +0x70 players[2][2]   +0x80 players_by_index[4]   +0x90 player_number[2][2]
 *   +0xa4 index into voice pool B (8 ids at lbl_88C6BE38)
 *   +0xa8 cursor into voice pool A (4 ids at lbl_88C6BE08)
 *   +0xac cursor into voice pool B (8 ids)         +0xb0 cursor into voice pool C (4 ids at lbl_88C6BE58)
 * Voice pools are round-robin FMOD instance handles (hashed ids), so overlapping cues do not
 * cut each other off.
 */

#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;

typedef struct Gp5Controller Gp5Controller;
typedef struct Gp5Vtbl {
    void *slot_00_to_20[10];
    void (*play)(Gp5Controller *self, const u32 *voice_id, const char *event_name, int a, int b, int c); /* +0x28 */
    void (*commit)(Gp5Controller *self, const u32 *voice_id);                                          /* +0x2c */
    void *slot_30;
    void (*prepare)(Gp5Controller *self, const u32 *voice_id);                                         /* +0x34 */
    void *slot_38;
    void (*set_volume)(Gp5Controller *self, const u32 *voice_id, float volume);                        /* +0x3c */
} Gp5Vtbl;

/* fn_8888A658: prepare, play, commit, set volume - the common tail of every simple cue. */
void gp5_play_cue(Gp5Controller *self, const Gp5Vtbl *vt, u32 voice_id, float volume, const char *event_name)
{
    vt->prepare(self, &voice_id);
    vt->play(self, &voice_id, event_name, 0, 0, 0);
    vt->commit(self, &voice_id);
    vt->set_volume(self, &voice_id, volume);
}

/* ---- fn_8888EBE8: per-frame pass ----------------------------------------------------- *
 *
 * 0. return if match->mode_1c0 == CRC("Replay") 0xDE9BF1C4 (no live sounds during replays).
 * 1. RACKET HIT: if R+0x19a (hit this frame) && !controller+0x44 && !R+0x19f:
 *      name  = fn_8888D700(...)        "Root/Ball/Shot/{Wood,FlatWeak,Drop,Flat%s,TopSpin%s,Slice%s}"
 *      voice = poolC[++cursor_b0 % 4]
 *      volume = base * stroke_scale where stroke_scale = tune[+0x494] for Flat,
 *               tune[+0x498] for Slice, tune[+0x49C] for TopSpin, tune[+0x4A0] otherwise;
 *               base = 1.0 (g_ts4_script_constants[0]); when the surface object's +0x14 hash is
 *               0x93458b98 (?) base = tune[+0x4B4]; unless R+0x1a0 is set the volume is also
 *               multiplied by tune[+0x490].
 *      play + commit + set_volume, then RETURN (one racket cue per frame).
 * 2. GROUND / NET: else if R+0x164 && !controller+0x45 (contact this frame), switch R+0x168:
 *      Ground          name = fn_8888CFD0(...)     "Root/Ball/Bounce/%sAngle%sSpeed"
 *      Net or Let      speed word from the first contact record (< 25.0f Slow else Fast)
 *                      name = "Root/Ball/Collision/Net_%s"
 *      each: voice = poolC[++cursor_b0 % 4]; play + commit (volume left at the default).
 * 3. SCENERY CONTACTS: if R+0x234 && match->mode_22c != CRC("School") 0xFE32DF8D:
 *      take the first active contact record; voice = poolB[(cursor_ac++ % 8)->+0xa4];
 *      if max(speed_a, speed_b) > threshold (lbl_8814B910 pool) build the name with
 *      fn_8888D328(-1, 0) ("Root/Ball/Collision/<Material>_<Slow|Fast>") and play it.
 *    else if match->mode_22c == "School": loop the 8 records; for each active record whose
 *      speed passes the threshold, look at the two type hashes (Ball 0xD400E765, Environment
 *      0xC0BA51F5 ("Environment"), Standalone 0x18C45490 ("Standalone"), ? 0x290F9F49):
 *        Ball+Environment      collision cue via fn_8888D328(-1, i) at volume 1.0
 *        Ball+Standalone       collision cue via fn_8888D328(0 or 1, i); volume scaled
 *        Standalone+?(0x290F9F49) a fixed voice 0x290F9F49 cue
 *      (only the School branch distinguishes the combinations, i.e. training-school props).
 * The routine only *classifies* contacts; it never changes ball state.
 */

/* ---- fn_8888ADC0: player sound dispatcher ------------------------------------------- *
 * fn_8888ADC0(controller, event_hash, gain, player_index):
 *   player = controller->players_by_index[player_index]
 *   gender word  = player+0x0c == CRC("Male") 0xF5BF4F97 ? "Man" : "Woman"
 *   voice type   = player+0x38: "TypeA" 0x5026F7B4 -> 0, "TypeB" 0xC92FA60E -> 1, else 2
 *   cursor_a8 = (cursor_a8 + 1) % 4
 *   court-surface volume curve: the surface object (+0x10, +0x1c) selects 1 of 4 ten-float
 *     blocks of the tuning blob at match+0x480: Hard+Indoor -> +0x28, Clay -> +0x50, Grass -> +0x78,
 *     Carpet -> +0xA0; the block is copied over the live curve (10 floats = 0x28 bytes).
 *   The event hash then picks the cue and the gain scalar:
 *     0x0B352785 "Shot"       grunt on a shot, gated by the player's grunt setting at player+0x34:
 *                             "Never" 0xDBE48D14 = none, "Always" 0xA108392D, "PowerfulShot" 0xADACB502,
 *                             "Service" 0x2E20A34E (and two unresolved: 0xF177AE1A, 0x01DFAA59)
 *                             -> "Root/Grunt/<Man|Woman>/<type 00..02>/Shot"; gain = tune[+0x4B8]
 *     0xEF823202 "Effort", 0x555999B1 (resolves to "ReachAnimation")
 *                             -> "Root/Grunt/%s/%02i/Effort"; gain = tune[+0x4BC]
 *     0x1AD280AF, 0x83DBD115, 0xF4DCE183 (unresolved, GruntVictory 01..03)
 *                             -> "Root/PlayerSounds/%s/%02i/GruntVictory0N"; gain = tune[+0x4C0]
 *     0xBF9D9C32, 0x2694CD88 (unresolved, GruntFrustration 01..02), only if player+0xcc
 *                             -> "Root/PlayerSounds/%s/%02i/GruntFrustration0N"; gain = tune[+0x4C4]
 *     0xEEFAA65F "Racket01" 0x77F3F7E5 "Racket02" 0x00F4C773 "Racket03"
 *                             -> "Root/PlayerSounds/Events/Racket0N"; gain = curve[8]
 *     0xE79E1444 "Bounce01"   -> "Root/Ball/Bounce/MediumAngleSlowSpeed"   (no gain change)
 *     0x7E9745FE "Bounce02"   -> "Root/Ball/Bounce/LargeAngleMediumSpeed"
 *     0x3DBC0C95 "BallHit"    -> "Root/Ball/Shot/Flat"
 *     0x3689AB7E "Dive"       -> "Root/PlayerSounds/Events/Dive"; gain = curve[9]
 *     0x319DC754 "TunnelStep", 0xD5973F7E "TunnelJump", 0xAA7AEBC4 "TunnelBagSound"
 *                             -> "Root/PlayerSounds/Tunnel/{TunnelStep,TunnelJump,TunnelBagSound}"
 *   Common tail: voice = poolA[cursor_a8]; gp5_play_cue(voice, gain * argument_gain, name).
 */
