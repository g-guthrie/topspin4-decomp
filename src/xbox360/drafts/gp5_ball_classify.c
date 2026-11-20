/*
 * GP5 draft: how Top Spin 4 (Xbox 360, Swing_DLL.xex) classifies ball events for the sound layer.
 * Not compiled into the matching build.  Plain C, host-syntax-checkable.
 *
 * Sources (all addresses are Swing_DLL.xex virtual addresses):
 *   fn_8888D700 0x8888D700  shot class + power bucket   (near-miss in drafts/gp5_ball_shot_nearmiss.cpp)
 *   fn_8888CFD0 0x8888CFD0  bounce angle/speed buckets  (VMX128 dot product; not matched)
 *   fn_8888D328 0x8888D328  collision material + speed word (not matched)
 *   fn_8888EBE8 0x8888EBE8  net / let speed word (part of the per-frame event pass)
 *
 * The strings become FMOD event paths ("Root/Ball/..."); the classification is therefore the
 * game's own definition of "what kind of shot / bounce / net hit just happened".  All the
 * gameplay *numbers* below are literal data pulled from g_ts4_script_constants (0x880D0F70)
 * or lbl_ constants; the pool offsets are noted so they can be re-checked.
 *
 * Name hashes are CRC32 of the ASCII name with seed 0 (fn_88608590, table lbl_880C84C0 which
 * is the standard zlib table): gp5_crc32("Flat") == 0xF578057A.  Resolved by brute force over
 * the strings in the binary; entries marked `?` have no recovered name.
 */

#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;

/* ---- hashes ------------------------------------------------------------------------- */
enum Gp5Hash {
    /* stroke types, rally+0x174 */
    GP5_H_FLAT = 0xF578057A,      /* "Flat" */
    GP5_H_SMASH = 0x7EB30F90,     /* "Smash" */
    GP5_H_TOPSPIN = 0xD9FA1B37,   /* "TopSpin" */
    GP5_H_LOB = 0xC718DAAA,       /* "Lob" */
    GP5_H_DROPSHOT = 0x990377A5,  /* "DropShot" */
    GP5_H_SLICE = 0xFC6F57A1,     /* "Slice" (used for volume selection, fn_8888EBE8) */
    GP5_H_SHOT = 0x0B352785,      /* "Shot" (player sound event id) */
    /* contact kinds, rally+0x168 */
    GP5_H_WOOD_UP = 0x007925F4,   /* "WoodUp"   racket-frame hit */
    GP5_H_WOOD_SIDE = 0x70D81E2F, /* "WoodSide" */
    GP5_H_WOOD_DOWN = 0x4FA695A1, /* "WoodDown" */
    GP5_H_GROUND = 0xA053865E,    /* "Ground"   ball bounced on the court */
    GP5_H_NET = 0xCAA7531F,       /* "Net" */
    GP5_H_LET = 0xC9238771,       /* "Let" */
    /* surfaces (this+0x2c object, +0x10) */
    GP5_H_HARD = 0x6127B0EC,      /* "Hard" */
    GP5_H_CLAY = 0xBC1789F5,      /* "Clay" */
    GP5_H_GRASS = 0x69CCB0F7,     /* "Grass" */
    GP5_H_CARPET = 0x4679AD1C,    /* "Carpet" */
    GP5_H_INDOOR = 0x1436B81A     /* "Indoor" (+0x1c) */
};

/* ---- shot classification: fn_8888D700 ------------------------------------------------ */

/*
 * Inputs read from the rally state R (this->rally, controller+0x30):
 *   R+0x164 u8   frame_hit        ball touched the racket frame
 *   R+0x168 u32  contact_kind     hash (WoodUp/WoodSide/WoodDown/Ground/Net/Let)
 *   R+0x174 u32  stroke           hash (Flat/Smash/TopSpin/Lob/DropShot/Slice/...)
 *   R+0x178 f32  power            0..1 normalised shot power
 *   R+0x95  u8   coarse_buckets   1 -> 3 power buckets, 0 -> 5 power buckets
 *                                 (also tested by the player-grunt dispatcher, see gp5_ball_events.c;
 *                                  most likely "this hit is a serve" -- unconfirmed)
 *
 * Output: FMOD event path, written into a 0x40-byte buffer.
 */
typedef struct Gp5ShotInput {
    u8 frame_hit;
    u32 contact_kind;
    u32 stroke;
    float power;
    u8 coarse_buckets;
} Gp5ShotInput;

/* g_ts4_script_constants pool values read by fn_8888D700 (pool offset in comments). */
#define GP5_POWER_T_020 0.2f /* +0x10C */
#define GP5_POWER_T_040 0.4f /* +0x118 */
#define GP5_POWER_T_060 0.6f /* +0x114 */
#define GP5_POWER_T_070 0.7f /* lbl_880D0938 */
#define GP5_POWER_T_080 0.8f /* +0x110 */

static const char *gp5_power_word(const Gp5ShotInput *in)
{
    float p = in->power;
    if (in->coarse_buckets) {
        /* three buckets: "" < 0.4 <= Strong < 0.7 <= Powerfull */
        if (p < GP5_POWER_T_040) return "";
        if (p < GP5_POWER_T_070) return "Strong";
        return "Powerfull";
    }
    /* five buckets */
    if (p < GP5_POWER_T_020) return "Powerless";
    if (p < GP5_POWER_T_040) return "Weak";
    if (p < GP5_POWER_T_060) return "";
    if (p < GP5_POWER_T_080) return "Strong";
    return "Powerfull";
}

/* Returns a format-selected event name; `power_word` is the %s argument ("" for none). */
const char *gp5_shot_event_format(const Gp5ShotInput *in, const char **power_word)
{
    *power_word = "";
    if (in->frame_hit && (in->contact_kind == GP5_H_WOOD_UP || in->contact_kind == GP5_H_WOOD_SIDE))
        return "Root/Ball/Shot/Wood";
    if (in->frame_hit && in->contact_kind == GP5_H_WOOD_DOWN)
        return "Root/Ball/Shot/FlatWeak";
    if (in->stroke == GP5_H_DROPSHOT)
        return "Root/Ball/Shot/Drop";
    *power_word = gp5_power_word(in);
    if (in->stroke == GP5_H_FLAT || in->stroke == GP5_H_SMASH)
        return "Root/Ball/Shot/Flat%s";    /* Flat family: Flat, Smash */
    if (in->stroke == GP5_H_TOPSPIN || in->stroke == GP5_H_LOB)
        return "Root/Ball/Shot/TopSpin%s"; /* TopSpin family: TopSpin, Lob */
    return "Root/Ball/Shot/Slice%s";       /* everything else, incl. Slice */
}

/* ---- bounce classification: fn_8888CFD0 ---------------------------------------------- */

/*
 * Controller fields: C+0x48..0x50 f32[3] ball velocity (x,y,z) at the bounce, C+0x54 f32 speed.
 * angle = dot(velocity, (0,-1,0)) / speed  (vmsum3fp128 with the constant vector built from
 * g_ts4_script_constants[+0x38] = -1.0f and lbl_8814B440 = 0.0f), i.e. sin of the impact
 * angle measured from the court plane.  Speed units are those of the physics wrapper
 * (probably m/s, unconfirmed); thresholds are g_ts4_script_constants entries.
 */
#define GP5_BOUNCE_SPEED_VERYSLOW 40.0f /* +0x404 */
#define GP5_BOUNCE_SPEED_SLOW 55.0f     /* +0x688 */
#define GP5_BOUNCE_SPEED_MEDIUM 75.0f   /* +0x604 */
#define GP5_BOUNCE_ANGLE_SMALL 0.30f    /* +0x564 */
#define GP5_BOUNCE_ANGLE_MEDIUM 0.45f   /* +0x464 */

const char *gp5_bounce_speed_word(float speed)
{
    if (speed < GP5_BOUNCE_SPEED_VERYSLOW) return "VerySlow";
    if (speed < GP5_BOUNCE_SPEED_SLOW) return "Slow";
    if (speed < GP5_BOUNCE_SPEED_MEDIUM) return "Medium";
    return "Fast";
}

const char *gp5_bounce_angle_word(float sin_angle)
{
    if (sin_angle < GP5_BOUNCE_ANGLE_SMALL) return "Small";
    if (sin_angle < GP5_BOUNCE_ANGLE_MEDIUM) return "Medium";
    return "Large";
}

/* event path: "Root/Ball/Bounce/%sAngle%sSpeed" with (angle word, speed word) => 3 x 4 classes */
float gp5_bounce_sin_angle(const float velocity[3], float speed)
{
    return (velocity[0] * 0.0f + velocity[1] * -1.0f + velocity[2] * 0.0f) / speed;
}

/* ---- net / let and scenery collision: fn_8888EBE8 / fn_8888D328 ----------------------- */

/*
 * Contact records live in a blob at controller+0x3c, reached through a self-relative offset
 * (blob + *(int*)blob).  Record layout (stride 0x24, 8 records = 0x120 bytes):
 *   +0x00 s32 material_a   +0x04 s32 material_b      material ids 1..29 (see table below)
 *   +0x08 f32 speed_a      +0x0C f32 speed_b
 *   +0x10 u32 type_a_hash  +0x14 u32 type_b_hash     Ball / Environment / Standalone / ...
 *   +0x20 u8  active
 * Speed words: speed < 25.0f (g_ts4_script_constants +0x61C, for side -1/net) or
 * lbl_880C8FB0 (sides 0/1) -> "Slow", otherwise "Fast".
 * Net / Let events (contact_kind Net or Let) play "Root/Ball/Collision/Net_%s" with that word.
 */
#define GP5_COLLISION_SLOW_BELOW_NET 25.0f /* g_ts4_script_constants +0x61C */

/* material ids 1..29 -> "Root/Ball/Collision/<name>_%s"  (jump table at 0x8888D508) */
static const char *const gp5_collision_material[29] = {
    "Bag", "Bench_Metal", "Bench_Wood", "Billboard", "Box_Metal", "Box_Plastic",
    "Box_Wood", "Camera", "Chair_Fabric", "Chair_Metal", "Chair_Plastic", "Chair_Wood",
    "Cover_Fabric", "Cover_Plastic", "Grid", "(Bounce)", /* id 15 -> "Root/Ball/Bounce/MediumAngle%sSpeed" */
    "Microphone", "Net", /* id 17 -> "Root/Ball/Collision/Net_%s" (lbl_880DD8D0) */
    "Plant", "Post", "Wall_Concrete", "Wall_Glass", "Wall_Wood", "Wall_Grass",
    "Cube_Leather", "Bench_Leather", "Sphere_Rubber", "Frame_Metal", "Shard_Glass"};
