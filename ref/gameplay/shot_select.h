/*
 * Reference implementation of the Top Spin 4 controller-to-shot path:
 * pad levels -> shot-button latch -> power / tier flags -> ShotSelection.Request
 * -> data decision tree (Settings.bin) -> shot id + template row.  Also the
 * stick-aim conversion.  Spec: docs/gameplay/controls-and-shot-selection.md.
 *
 * No game data is compiled in.  The tree and the tier/power numbers come from a
 * values file written by tools/ts4data/shot_tree.py (data/gameplay/shot_tree.tree).
 * Code constants that ARE in the executable (0x80 trigger level, 0.5 tests, the
 * 32767 stick scale, the wood-down radius) are written here with their original addresses.
 *
 * Compile (portable C11):
 *   cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_shot_select \
 *      ref/gameplay/test_shot_select.c ref/gameplay/shot_select.c -lm
 */
#ifndef TS4_SHOT_SELECT_H
#define TS4_SHOT_SELECT_H

#include <stdint.h>

/* crc32 (zlib) of the ASCII name; every id and condition in the data is one. */
uint32_t ts4_crc32(const char *name);

enum {
    TS4_ID_FLAT = 0xf578057au,           /* "Flat"     button A           */
    TS4_ID_TOPSPIN = 0xd9fa1b37u,        /* "TopSpin"  button B           */
    TS4_ID_SLICE = 0xfc6f57a1u,          /* "Slice"    button X           */
    TS4_ID_LOB = 0xc718daaau,            /* "Lob"      button Y           */
    TS4_ID_SMASH = 0x7eb30f90u,          /* "Smash"    overhead situation */
    TS4_ID_DROPSHOT = 0x990377a5u,       /* "DropShot" (after the tree)   */
    TS4_ID_DROPSHOTNORMAL = 0xc47dfdc1u, /* row id                        */
    TS4_ID_DROPVOLLEY = 0x8ff66130u      /* row id                        */
};

/* ShotSelection.Request, PlayerState +0x400..+0x40B, in memory order
 * (Layoutall.bin type of PlayerState.ShotSelection.Request; verified against
 * the stores of fn_8868F178). */
typedef struct Ts4Request {
    uint8_t is_flat;           /* +0x400 (not tested by the shipped tree) */
    uint8_t is_slice;          /* +0x401 */
    uint8_t is_topspin;        /* +0x402 */
    uint8_t is_lob;            /* +0x403 */
    uint8_t is_risk;           /* +0x404  = InputState.Risk (LT or RT > 128) */
    uint8_t is_powerful;       /* +0x405  = SwingSelection.Request.Power[0] */
    uint8_t is_medium;         /* +0x406  = SwingSelection.Request.Power[1] */
    uint8_t is_classic_serve;  /* +0x407 */
    uint8_t is_advanced_serve; /* +0x408 */
    uint8_t is_smash;          /* +0x409 */
    uint8_t is_wood;           /* +0x40A */
    uint8_t is_wood_down;      /* +0x40B */
} Ts4Request;

/* Context the tree reads besides the Request: Context.ShotContext.ModeBaseLine
 * (PlayerState +0x574), keyed in the tree as crc32("IsBaseLine"). */
typedef struct Ts4ShotContext {
    uint8_t mode_baseline;
} Ts4ShotContext;

/* --- decision tree (values file) ---------------------------------------- */

#define TS4_TREE_MAX_NODES 128
#define TS4_TIER_MAX 8

typedef struct Ts4Child {
    int is_leaf;
    int node;          /* when !is_leaf */
    uint32_t shot_id;  /* when is_leaf: row id (row+0x88) */
    int row;           /* template row index, -1 if the id names no row */
} Ts4Child;

typedef struct Ts4Node {
    uint32_t condition; /* crc32 of the attribute name */
    Ts4Child if_true;   /* child 0 */
    Ts4Child if_false;  /* child 1 */
} Ts4Node;

typedef struct Ts4Tier {
    char name[16];      /* Finesse / Medium / Powerful */
    float lo, hi;       /* power interval where the tier graph outputs 1 */
} Ts4Tier;

typedef struct Ts4ShotTree {
    int n_nodes;
    Ts4Node nodes[TS4_TREE_MAX_NODES];
    int has_power_curve;
    float power_curve[4]; /* curve16 key {x0, x1, y0, y1} of cfg+0x8FC */
    int n_tiers;
    Ts4Tier tiers[TS4_TIER_MAX];
    int has_risk_curve;
    float risk_curve[4];  /* cfg+0x908: Risk hold value S+0xE08 (no reader found) */
    int frequency;        /* GameplayInterface EngineConfig/@Frequency = the divisor D (0: absent) */
} Ts4ShotTree;

/* Parse the line format of shot_tree.py (see its tree_flat()).  0 on success. */
int ts4_shot_tree_parse(const char *text, Ts4ShotTree *tree);
int ts4_shot_tree_load(const char *path, Ts4ShotTree *tree);

/* Value of one tree condition (fn_8865A938 reads a bound byte == 1). */
int ts4_condition_value(uint32_t condition, const Ts4Request *rq, const Ts4ShotContext *ctx);

typedef struct Ts4ShotChoice {
    uint32_t row_id;    /* leaf id = row+0x88 */
    int row;            /* template row index (ball+0x360 = row file offset - 0x24) */
    uint32_t shot_id;   /* PlayerController+0x3C after fn_8868F178: DropShot for the two drop rows */
    int path[TS4_TREE_MAX_NODES]; /* visited node indices */
    int path_len;
} Ts4ShotChoice;

/* Walk the tree from node 0 (fn_8865A938).  Returns 0 on success. */
int ts4_shot_select(const Ts4ShotTree *tree, const Ts4Request *rq, const Ts4ShotContext *ctx,
                    Ts4ShotChoice *out);

/* --- input mapper, latch, request (code semantics) ---------------------- */

/* Pad button slot ids of the 0xC4 pad record (fn_888854B0). */
enum { TS4_PAD_A, TS4_PAD_B, TS4_PAD_X, TS4_PAD_Y, TS4_PAD_LB, TS4_PAD_RB, TS4_PAD_LT, TS4_PAD_RT,
       TS4_PAD_LTHUMB, TS4_PAD_RTHUMB, TS4_PAD_START, TS4_PAD_BACK, TS4_PAD_SLOTS };

/* LEVEL bool of a button item (fn_8890DB90): triggers (slots 6, 7) are "down" above
 * 0x80 of 0xFF, every other button when non-zero; `invert` flips it. */
int ts4_button_level(int slot, uint8_t value, int invert);

/* Stick channel (fn_88910F50 -> fn_8890E358).  Raw int16 axes, each negated when its
 * invert bool (InputState @InvertPaddle in the shipped map) is set; radial dead zone:
 * |v| <= dz*32767 gives all zero, otherwise m = min(|v|/32767, 1) and the output
 * magnitude is (m - dz)/(1 - dz) along the raw direction.  Cartesian items multiply
 * x/y by their scale; polar items give Power = lerp(power_range, mag) and
 * Angle = lerp(angle_range, a/(2*pi) + 0.5) where a = atan2(x, y).  Angular snapping and the
 * running-average filter of the runtime are not reproduced (doc s3.2). */
typedef struct Ts4Stick { float x, y, mag, angle; } Ts4Stick;
Ts4Stick ts4_stick_channel(int16_t raw_x, int16_t raw_y, float dead_zone, int invert_x, int invert_y);
/* Cartesian output pair of one item. */
void ts4_stick_cartesian(const Ts4Stick *s, const float scale[2], float out[2]);
/* Polar output pair {Power, Angle} of one item. */
void ts4_stick_polar(const Ts4Stick *s, const float angle_range[2], const float power_range[2],
                     float out[2]);

/* fn_886A3440, human pad branch: Buttons.LT held, Stick_MovePolar.Power > 0.2 and the
 * stick angle within 0.8727 rad (50 deg) of pi/2 (of 3*pi/2 when `alt`, a flag at
 * *(planner+0x2C)+0x60; +pi first on the mirrored court side): the movement planner then
 * commits the swing profile PlayerTuning+0x1F8 at once (side picked by the stick through
 * InputNotation).  Returns 1 when that forced commit happens. */
int ts4_lt_forced_commit(int lt, float move_power, float move_angle, int alt, int mirrored_side);

/* ShotInputLatch (fn_88679C78): latch the first held of A/B/X/Y in priority
 * Flat > TopSpin > Slice > Lob while nothing is latched.  Returns the latched id
 * (0 = none) and keeps `*latched` across frames; `*released` is set on the frame
 * the latched button goes up. */
uint32_t ts4_latch_update(uint32_t *latched, const uint8_t buttons_abxy[4], int *released);

/* fn_8868F178 + fn_886783B0: Request flags from the requested stroke, the Risk
 * level, the overhead situation (Context.IsSmash, S+0x5DA) and the power tier
 * bools (SwingSelection.Request.Power, S+0x3A8/0x3A9). Serve and Wood flags are
 * passed in (they are not set by these two functions in normal play). */
typedef struct Ts4RequestInput {
    uint32_t stroke_id;      /* Flat / TopSpin / Slice / Lob (first raised shot trigger) */
    int risk;                /* InputState.Risk */
    int overhead;            /* Context.IsSmash: forces stroke Smash */
    int tier_powerful;       /* SwingSelection.Request.Power[0] */
    int tier_medium;         /* SwingSelection.Request.Power[1] */
    int classic_serve, advanced_serve, wood, wood_down;
} Ts4RequestInput;
Ts4Request ts4_build_request(const Ts4RequestInput *in, uint32_t *shot_id_out);

/* --- power and tiers ------------------------------------------------------ */

/* curve16 evaluator (fn_881899D8) for one key. */
float ts4_curve16(const float key[4], float x);

/* fn_8869D720: power (S+0xE00) = curve16(cfg+0x8FC)(frames / D).  For a human pad
 * player `frames` is ReceiverState FrameCount (S+0xDFC): the number of frames the shot
 * button has been held since the request started (incremented by fn_886B3CF8 until the
 * swing is committed, reset by fn_88698538).  D = **(World+0x44) =
 * GameplayInterface EngineConfig/@Frequency (60 in the shipped data); divisor 0 uses
 * tree->frequency. */
float ts4_power(const Ts4ShotTree *tree, int frames_held, int divisor);

/* Charge counter of fn_886B3CF8 (states AFAF1093 / F6EB6636 / 658B2E11): one frame per
 * update while the swing is not committed (PC+0x58C) and the request is latched
 * (PC+0x58D, human) or the player is AI.  Commit happens on the shot-button release, or
 * at the auto trigger (contact frame - now <= PlayerTuning+0x740, 12 frames shipped) if
 * the button is still held.  Returns the new commit flag. */
typedef struct Ts4Charge { int frames; int latched; int committed; } Ts4Charge;
void ts4_charge_start(Ts4Charge *c);  /* fn_88698538: frames = 0, latched = 1 */
int ts4_charge_update(Ts4Charge *c, int released, int frames_to_contact, int lead_frames);

/* Human trigger vtbl +0x34 (fn_88662458): the planner fn_886B0490 runs when the contact
 * frame (S+0x98 PlayerEvents.BallShot.AtFrame) is valid and contact - now <= lead. */
int ts4_swing_now(int contact_frame_valid, int frames_to_contact, int lead_frames);

/* --- serve ----------------------------------------------------------------- */

/* fn_886723A8: serve Request from the toss inputs.  Stroke = Classic.Throw{Flat,Slice,
 * TopSpin}; with p = S+0x670 (serve PressAndHold, the power ratio below):
 * IsPowerful = p > 0.8, IsMedium = !(p < 0.1) && !IsPowerful
 * (g_ts4_script_constants+0x110 / +0x2AC); IsClassicServe = Classic.Throw (S+0x480),
 * IsAdvancedServe = Advanced.Throw (S+0x4B5) or a motion controller. */
typedef struct Ts4ServeInput {
    int throw_flat, throw_slice, throw_topspin;  /* S+0x482 / 0x483 / 0x484 */
    int classic_throw, advanced_throw;           /* S+0x480 / 0x4B5 */
    int motion_device;                           /* forces advanced (fn_8890DB38) */
    float press_and_hold;                        /* S+0x670 */
} Ts4ServeInput;
Ts4Request ts4_serve_request(const Ts4ServeInput *in);

/* fn_886B2638: serve power S+0x670 = clamp((release - toss_start) / toss_len, 0, 1), where
 * toss_len = toss frames - PlayerTuning+0x744 (12 shipped); 1.0 when not released. */
float ts4_serve_power(int release_frame, int toss_start_frame, int toss_len, int released);

/* fn_886B2638: serve timing value = curve table (PlayerTuning+0x60C, keyed by serve
 * animation) of the frames between the button release and contact; 1.0 when the button
 * was not released.  `keys` are n curve16 keys {x0,x1,y0,y1} evaluated like a graph
 * CURVE (last key with x0 <= x, first key below the range). */
float ts4_serve_timing(const float (*keys)[4], int n, float frames_release_to_contact, int released);

/* --- wood -------------------------------------------------------------------- */

/* fn_886B0490 entry: IsWood when the anim controller armed the check (*(PC+0x78)+0x431,
 * set by fn_886D6EB0 when the racket is within a radius of the ball) and
 * |ManualShotTiming (S+0x544)| >= 0.1 (g_ts4_script_constants+0x2AC/+0x474). */
int ts4_wood_check(int armed, float manual_shot_timing);

/* fn_886AE528 +0x618..+0x760: the target x is pushed out to at least 50 from the centre
 * line (min(x, -50) if x < 0, max(x, 50) otherwise; g_ts4_script_constants+0x570/+0xF0);
 * IsWoodDown when the target is on the x < 0 side, IsWood is not set, and the squared
 * distance to the reference point (vector v127 of the planner) is < 640000
 * (g_ts4_script_constants+0x7EC; 8 m).  `target` is updated in place (x, y, z in cm). */
int ts4_wood_down(float target[3], const float ref[3], int is_wood);

/* Tier graph outputs (Expressions.bin Finesse/Medium/Powerful) and the >0.5 tests
 * of fn_886872A0.  out[0] = Finesse, out[1] = Medium, out[2] = Powerful. */
void ts4_tier_flags(const Ts4ShotTree *tree, float power, int out[3]);

/* --- aim ------------------------------------------------------------------ */

/* fn_8869C010, stick mode (0x9E51242B): v = (Stick_Move.Y, 0, -Stick_Move.X);
 * angle = atan2(v.x, v.z) (+pi on the mirrored court side, wrapped to [-pi, pi]),
 * depth = min(|v|, 1).  AI players feed (0, 0). */
typedef struct Ts4Aim { float angle, depth; } Ts4Aim;
Ts4Aim ts4_aim_from_stick(float move_x, float move_y, int mirrored_side);

/* fn_8869BEF0, auto mode (0x487570E4): aim at `target` (x, z in cm) from the
 * ball position predicted 30 ticks ahead; full depth when that distance is
 * above 30 (cm), otherwise zero aim. */
Ts4Aim ts4_aim_auto(const float player_xz[2], const float target_xz[2], const float ball30_xz[2]);

#endif
