#ifndef GP2_TYPES_H
#define GP2_TYPES_H

/*
 * GP2 (WP2): types for the swing-candidate / reach / selection package of Swing_DLL.xex
 * (sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44).
 *
 * Every offset is read from machine code of the functions named in the comment next to it
 * (see work/gameplay-notes/gp2.md). Names are by role; a trailing `/ * ? * /` marks a guess.
 * Hash constants are zlib crc32 of the ASCII name. Positions are in centimetres and times
 * in 60 Hz ticks (the factor 0.6 = 60 / 100 turns cm/tick into m/s).
 */

typedef unsigned int gp2_u32;

/* ---- hashes (crc32 of ASCII name, verified with python3 -c "import zlib;print(hex(zlib.crc32(b'Name')))") ---- */
#define GP2_HASH_VOLLEY        0x71198650u /* "Volley": sample/candidate type (fn_8868B4E8, fn_8865DBA8) */
#define GP2_HASH_SMASH         0x7eb30f90u /* "Smash" */
#define GP2_HASH_BASELINE      0x0f6fb110u /* "Baseline": groundstroke candidate type (fn_8869B178) */
#define GP2_HASH_UNREACHABLE   0xdda489b8u /* "Unreachable": candidate type of a sample that cannot be hit */
#define GP2_HASH_LEFT          0xda554856u /* "Left" (handedness / side tag in fn_8869B178) */
#define GP2_HASH_WOOD          0x9cafb633u /* "Wood" (frame hit, fn_88689508) */
#define GP2_HASH_STEPS         0xf5e32576u /* "Steps" (debug style selector, fn_886AC2C8) */
#define GP2_HASH_INSIDE_OUT    0xbd8ea388u /* "InsideOut" (debug style selector, fn_886AC2C8) */
#define GP2_HASH_GOOD          0xccb6e1acu /* "Good"   hit-quality grade written at commit (fn_886A2E48) */
#define GP2_HASH_MEDIUM        0xc1df4081u /* "Medium" */
#define GP2_HASH_BAD           0xba667f1bu /* "Bad" */
#define GP2_HASH_COURT_SIDE_A  0xa2eda1e7u /* court-side tag whose coordinates are mirrored (name unknown) */

/* ---- ball prediction sample: 0x30 bytes, array at BallPrediction+0x5a0 (begin) / +0x5a4 (end) ---- */
struct Gp2BallSample {
    float pos[4];             /* +0x00 world position (x, y=height, z, w) in cm (lvx128 in fn_8869B178) */
    unsigned char unk10[0x24 - 0x10];
    int tick;                 /* +0x24 frame number at which the ball is here (fn_8868B4E8: tick - clock+0x310) */
    int bounce_count;         /* +0x28 number of bounces so far; fn_8869B178 only accepts <= 2 */
    unsigned char unk2c[4];
};

/* BallPrediction: reached as PlayerCtx->world(+0x48)->ball(+0x5c)->prediction(+0x24). */
struct Gp2BallPrediction {
    unsigned char pad0[0x5a0];
    struct Gp2BallSample *samples_begin; /* +0x5a0 */
    struct Gp2BallSample *samples_end;   /* +0x5a4 */
    unsigned char pad1[0x5bc - 0x5a8];
    unsigned int first_sample;           /* +0x5bc index of the first usable sample (3*16 bytes stride) */
};

/* Relative array header used all over this package: 12 bytes {offset-from-header (-1 = none), count, aux}. */
struct Gp2RelArray {
    int offset;               /* data = (char *)&header + offset, or null when -1 */
    int count;
    int aux;                  /* third word, purpose unknown (capacity?) */
};

/*
 * CandidateSet (0x60 bytes, two per brain: side 0 at +0, side 1 at +0x60). Structure-of-arrays,
 * indexed by ball-sample index. Read by fn_8868B4E8, fn_8868BD80, fn_8869B178, fn_886AC2C8.
 */
struct Gp2CandidateSet {
    unsigned char valid_a;      /* +0x00 fn_8868BD80: ball line passes the player on this side */
    unsigned char side_is_not_left; /* +0x01 fn_8869B178: handedness test against "Left" */
    unsigned char pad02[2];
    struct Gp2RelArray positions; /* +0x04/+0x08 vec4 per sample (copy of sample pos, mirrored by court side) */
    struct Gp2RelArray reach_speed; /* +0x10/+0x14 "Reachability": required run speed per sample, m/s */
    float best_reach_speed;     /* +0x1c running minimum of reach_speed (init FLT_MAX) */
    unsigned char dirty;        /* +0x20 recompute request (set by the debug HUD, cleared in fn_886A39A8) */
    unsigned char pad21[3];
    struct Gp2RelArray types;   /* +0x24/+0x28 candidate type hash per sample: Baseline/Volley/Smash/Unreachable */
    float first_pos[4];         /* +0x30 position of first accepted sample */
    float last_pos[4];          /* +0x40 position of last accepted sample */
    int first_index;            /* +0x50 first accepted sample index, -1 if none */
    int last_index;             /* +0x54 last accepted sample index */
    unsigned char pad58[0x60 - 0x58];
};

/* One contiguous window of ball samples [start, end] that can be hit on one side (0x30 bytes). */
struct Gp2ReachWindow {
    unsigned char pad0[0x24];
    int start;                  /* +0x24 first ball-sample index */
    int end;                    /* +0x28 last ball-sample index (inclusive) */
    unsigned char pad2c[0x30 - 0x2c];
};

/*
 * ReachRecord (0x34 bytes, two per brain: forehand-side at +0, other side at +0x34).
 * fn_886AC2C8 (HUD), fn_8865DBA8 (arg-max), fn_88689508 (score writer), fn_88678A88 (notation writer).
 */
struct Gp2ReachRecord {
    struct Gp2RelArray input_notation; /* +0x00/+0x04 float per sample: HUD "InputNotation" */
    struct Gp2RelArray selection_score;/* +0x0c/+0x10 float per sample: HUD "Selection Score" (-1 = invalid) */
    struct Gp2RelArray windows;        /* +0x18/+0x1c Gp2ReachWindow list */
    float side_offset;                 /* +0x24 lateral miss measure of this side (init FLT_MAX); fn_8869AB70 picks the smaller side */
    unsigned char pad28[0x30 - 0x28];
    unsigned char valid;               /* +0x30 this side has at least one window */
    unsigned char pad31[3];
};

/* ---- swing brain scratch / query handed to the analyser (PlayerState+0xb80) ---- */
struct Gp2SwingQuery {
    float position[4];        /* +0x00 ball sample position */
    float ball_height;        /* +0x10 sample[i].pos.y */
    float input_notation;     /* +0x14 only when the player is human-driven (PlayerCtx+0x10) */
    float ball_difficulty;    /* +0x18 BallPrediction+0x7c[i*8] */
    float reach_speed;        /* +0x1c CandidateSet.reach_speed[i] */
    float ref_height;         /* +0x20 150.0 default, or height of sample #ball+0x5c8 */
    float side_offset;        /* +0x24 min(ReachRecord[0].side_offset, ReachRecord[1].side_offset) */
    float selection_score;    /* +0x28 analyser OUTPUT */
    float ticks_since_first;  /* +0x2c sample.tick - first.tick, -1000 when earlier */
};

#ifndef _MSC_VER
/* Layout checks (host compilers only; the matching compiler lacks __builtin_offsetof). */
#define GP2_SIZE_CHECK(tag, size) \
    typedef char gp2_size_check_##tag[(sizeof(struct tag) == (size)) ? 1 : -1]
#define GP2_OFFSET_CHECK(tag, field, offset) \
    typedef char gp2_offset_check_##tag##_##field[(__builtin_offsetof(struct tag, field) == (offset)) ? 1 : -1]

GP2_SIZE_CHECK(Gp2BallSample, 0x30);
GP2_SIZE_CHECK(Gp2CandidateSet, 0x60);
GP2_SIZE_CHECK(Gp2ReachWindow, 0x30);
GP2_SIZE_CHECK(Gp2ReachRecord, 0x34);
GP2_OFFSET_CHECK(Gp2CandidateSet, first_pos, 0x30);
GP2_OFFSET_CHECK(Gp2CandidateSet, last_index, 0x54);
GP2_OFFSET_CHECK(Gp2ReachRecord, side_offset, 0x24);
GP2_OFFSET_CHECK(Gp2ReachRecord, valid, 0x30);
#endif

#endif /* GP2_TYPES_H */
