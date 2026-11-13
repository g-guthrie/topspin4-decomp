#ifndef GP3_TYPES_H
#define GP3_TYPES_H

/*
 * GP3 (core per-frame gameplay): types for fn_886B5128 (main gameplay frame), the ball state /
 * ball prediction, the swing command record, the reward-tag tracker (fn_88697118/fn_88696D40) and
 * the player movement planner (fn_886BF360 -> fn_886BF260 -> fn_886BD690 -> fn_886B8468).
 * Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 *
 * Every offset was read from machine code (see work/gameplay-notes/gp3.md for the evidence
 * of each field). Names are roles; a trailing `/ * ? * /` marks a guess. Positions are in
 * centimetres, times in 60 Hz ticks ("frames"). Hashes are zlib crc32 of the ASCII name.
 * Shared sample / candidate types come from gp2_types.h (GP2 owns them; do not redefine).
 */

#include "gp2_types.h"

typedef unsigned char gp3_u8;
typedef unsigned int gp3_u32;

/* ---- hashes (crc32 of the name; reproduce with python3 -c "import zlib;print(hex(zlib.crc32(b'Rush')))") ---- */
#define GP3_HASH_RUSH            0x550171D1u /* "Rush" movement mode (anim->+0x468 current movement mode) */
#define GP3_HASH_JOG             0xB3FF5297u /* "Jog" */
#define GP3_HASH_IDLE            0x7C161A2Bu /* "Idle" */
#define GP3_HASH_RECEIVER        0xC4CEEEC0u /* "Receiver": player component looked up in player+0x94 */
#define GP3_HASH_LET_IN          0x8F903DFBu /* "LetIn"  ball mode (ball+0x2C) */
#define GP3_HASH_LET_OUT         0x02315629u /* "LetOut" ball mode */
#define GP3_HASH_BALL_NET        0xCAA7531Fu /* "Net"  ball mode (prediction ends here) */
#define GP3_HASH_BALL_OUT        0x81A72B79u /* "Out"  ball mode (prediction ends here) */
#define GP3_HASH_WOOD            0x9CAFB633u /* "Wood" */
#define GP3_HASH_VOLLEY          0x71198650u /* "Volley" (candidate type) */
#define GP3_HASH_FH              0x9FFD33DEu /* "FH" */
#define GP3_HASH_BH              0xFB91F6DAu /* "BH" */
#define GP3_HASH_COURT_SIDE_A    0xA2EDA1E7u /* team side tag whose x/z are mirrored (name unknown) */
#define GP3_HASH_STATE_IDLE_POINT 0x85E3E155u /* match state "play" (gp0 notes) */
#define GP3_HASH_STATE_POINT_END  0x029EAAF4u /* match state: point finished */

/* ---- ball state: 0x540 bytes, world->u20 (fn_889C2818 steps it, fn_886AD278 copies it to predict) ---- */
struct Gp3BallState {
    float  f_00;                 /* +0x00 command C+0x40 */
    gp3_u32 u_04;                /* +0x04 command C+0x44 */
    float  f_08;                 /* +0x08 shot-template[+0x54] (fn_889C19F0) */
    float  f_0c;                 /* +0x0C = +0x430 */
    float  f_10;                 /* +0x10 = +0x364 */
    int    bounce_count;         /* +0x14 bounces since launch (0 on launch; sim stops at >= 2) */
    int    tick;                 /* +0x18 ticks since launch */
    int    tick_prev;            /* +0x1C */
    int    launch_frame;         /* +0x20 match frame of the shot (match+0x310 at apply time) */
    gp3_u32 shot_template;       /* +0x24 (a pointer on console) = table[stepper+0x3C] + index(+0x360) + 0x18 */
    int    hold_ticks;           /* +0x28 while > 0 the ball is carried by +0xA0 per tick (toss/hold) */
    gp3_u32 mode;                /* +0x2C ball mode hash: LetIn/LetOut/Wood/Net/Out/...; command C+0x80 -> player+0x30 */
    gp3_u8 flag_30, flag_31, flag_32, flag_33, flag_34;  /* +0x30..+0x34 bytes used by the step (fn_889C1F70) */
    gp3_u8 pad_35[0x0B];
    float  pos[4];               /* +0x40 position (cm); the stepper rescales it temporarily */
    float  pos_prev[4];          /* +0x50 ? (copy) */
    float  pos_prev2[4];         /* +0x60 previous position */
    float  origin[4];            /* +0x70 local-frame origin subtracted by fn_889C1160 */
    gp3_u8 pad_80[0x10];
    float  spin_like[3];         /* +0x90..+0x98 damped on bounce (fn_889C1F70) */
    float  pad_9c;
    float  hold_delta[4];        /* +0xA0 per-tick displacement while hold_ticks > 0 */
    int    event_frame[8][2];    /* +0xB0..+0xEF 8 scheduled ball-event slots {frame, aux}, 0x7FFFFFFF = none (fn_8867B2D8):
                                  * [0]=+0xB0 [1]=+0xB8 [2]=+0xC0 [3]=+0xC8 launch frame + template time (fn_889C19F0)
                                  * [4]=+0xD0 [5]=+0xD8 next scheduled event that the frame step waits for
                                  * [6]=+0xE0 serve/first-sample frame [7]=+0xE8 last-sample frame */
    gp3_u8 pad_f0[0x10];
    float  v100[4], v110[4], v120[4], v130[4], v140[4]; /* +0x100..+0x14F command vectors, rescaled by fn_889C1160 */
    gp3_u8 pad_150[0x50];
    float  v1a0[4];              /* +0x1A0 */
    gp3_u8 pad_1b0[0x190];
    float  saved_340[4];         /* +0x340 copy of command C+0x00 */
    float  saved_350[4];         /* +0x350 copy of command C+0x10 */
    int    shot_template_index;  /* +0x360 command C+0x48 */
    float  shot_f_364;           /* +0x364 command C+0x50 */
    gp3_u8 shot_flag_368;        /* +0x368 command C+0x58 */
    gp3_u8 pad_369[7];
    float  shot_f_370;           /* +0x370 command C+0x54 */
    gp3_u8 pad_374[0xBC];
    float  shot_f_430;           /* +0x430 command C+0x4C */
    gp3_u32 shot_u_434;          /* +0x434 = player+0x30 (shot id) */
    gp3_u8 pad_438[4];
    gp3_u8 new_shot;             /* +0x43C 1 = launch pending: fn_889C2818 runs fn_889C19F0 once */
    gp3_u8 pad_43d[3];
    gp3_u32 shot_u_440;          /* +0x440 command C+0x88 */
    gp3_u8 pad_444[0x50];
    float  shot_f_494, shot_f_498, shot_f_49c, shot_f_4a0; /* +0x494.. command C+0x30,+0x34,+0x38,+0x3C */
    gp3_u8 pad_4a4[0x3C];
    gp3_u8 flag_4e0, flag_4e1;   /* +0x4E0/+0x4E1 */
    gp3_u8 pad_4e2[0x0E];
    float  velocity_per_tick[4]; /* +0x4F0 (pos - pos_prev) * scale, written at the end of every step */
    float  v500[4], v510[4];     /* +0x500/+0x510 launch-time derived vectors (fn_888AB220/fn_888AB0E0) */
    float  speed;                /* +0x520 |velocity| * scale (written by fn_886C1ED8) */
    gp3_u8 pad_524[0x0C];
    gp3_u8 enabled;              /* +0x530 stepper does nothing while 0; set to 1 when a command is applied */
    gp3_u8 pad_531[0x0F];
};

/* ---- the swing command record (one per player slot, 0xE0 bytes, located by match->u70 relative table) ---- */
struct Gp3SwingCommand {          /* rec+0x20 (0xA8 bytes used); offsets below are relative to the sub-struct */
    float  from[4];              /* +0x00 -> ball+0x340/+0x100 (launch position?) */
    float  to[4];                /* +0x10 -> ball+0x350/+0x110 (target position?) */
    float  extra[4];             /* +0x20 -> ball+0x120 */
    float  f_30, f_34, f_38, f_3c; /* +0x30.. -> ball+0x494/+0x498/+0x49C/+0x4A0 */
    float  f_40;                 /* +0x40 -> ball+0x00 */
    gp3_u32 u_44;                /* +0x44 -> ball+0x04 */
    gp3_u32 template_index;      /* +0x48 -> ball+0x360 (shot template) */
    float  f_4c;                 /* +0x4C -> ball+0x430 */
    float  f_50;                 /* +0x50 -> ball+0x364 */
    float  f_54;                 /* +0x54 -> ball+0x370 */
    gp3_u8 flag_58;              /* +0x58 -> ball+0x368 */
    gp3_u8 pad_59[0x17];
    float  v70[4];               /* +0x70 -> ball+0x70 (origin of the local frame) */
    gp3_u32 mode_80;             /* +0x80 -> player+0x30, ball+0x434 */
    gp3_u32 u_84;
    gp3_u32 u_88;                /* +0x88 -> ball+0x440, player_state+0x3D0 */
    gp3_u32 shot_type_hash;      /* +0x8C Flat/TopSpin/Slice/Lob/DropShot/Smash (crc32): drives ball+0x4C..+0x5C float flags */
    float  f_90;                 /* +0x90 -> player_state+0x764 */
    float  f_94;                 /* +0x94 -> player_state+0x7A8 */
    gp3_u8 b_98, b_99, b_9a, b_9b; /* +0x98 -> state+0x5DA, +0x99 -> +0x5D9, +0x9A -> +0x405, +0x9B -> +0x404 */
    gp3_u8 pad_9c[4];
    int    due_frame;            /* +0xA0 command applies when match frame >= due_frame */
    gp3_u8 valid;                /* +0xA4 command present; cleared after it was applied */
    gp3_u8 pad_a5[3];
};

/* ---- reward-tag tracker (the object behind fn_88697118 / fn_88696D40 / fn_88697890; GP1 "evaluator") ---- */
struct Gp3TagCell {               /* word cell owned by the animation/tag service; byte 0 == 1 while the tag is active */
    gp3_u8 active;
    gp3_u8 pad[3];
};

/* The shot "collector" at tracker+0x38 (GP1 Gp1RewardList is its first part): reward vector at +0x08 and the two
 * lookup-request vectors written by fn_886965E0. */
struct Gp3RewardCollector {
    gp3_u8 pad_00[8];
    gp3_u32 *reward_begin, *reward_end, *reward_cap;                /* +0x08 reward hashes (fn_88673630) */
    gp3_u32 *req_hashes_begin, *req_hashes_end, *req_hashes_cap;    /* +0x14 queued tag hashes (fn_886965E0) */
    gp3_u32 *req_players_begin, *req_players_end, *req_players_cap; /* +0x20 queued player indices */
};

struct Gp3TagTracker {
    gp3_u8 pad_00[0x20];
    void  *shot_record;          /* +0x20 GP1 ShotRecord (+0x99 flag read by fn_88697118, +0x104 relative array) */
    gp3_u8 pad_24[4];
    void  *tuning;               /* +0x28 GP1 ShotTuning: +0xC4/+0xC8 Rush thresholds, +0x15C = 60.0 */
    void  *player_states;        /* +0x2C relative array of 0x1070-byte PlayerStates */
    void  *u_30;                 /* +0x30 */
    void  *match_ctx;            /* +0x34 (+0x44 = flag block, +0x1C/+0x1D pause bytes) */
    struct Gp3RewardCollector *collector; /* +0x38 */
    struct Gp3TagCell *cell[34][4]; /* +0x3C..+0x25B  cell[k][player]; fn_88697118 reads k = 0..6,10..16 */
    gp3_u8 prev[18][4];          /* +0x25C..+0x2A3  previous-frame active byte of cell[k][player] (edge detection) */
    int    slot_a4[4];           /* +0x2A4 per-player int, -1 = "unset" (fn_88696D40 tail) */
    gp3_u8 pad_2b4[0x59];
    gp3_u8 flag_30d;             /* +0x30D set on a rising edge of cell[0] (SpectacularAnimation) */
    gp3_u8 pad_30e[0x66];
    gp3_u8 flag_374_reach;       /* +0x374 reach animation (cell[1] rising edge) */
    gp3_u8 flag_375_powerful;    /* +0x375 PowerfulShotAnimation (cell[3]) */
    gp3_u8 pad_376[8];
    gp3_u8 flag_37e_fatality;    /* +0x37E Fatality (cell[16]) */
    gp3_u8 flag_37f_trickshot;   /* +0x37F TrickShot (cell[6]) */
};

/* ---- movement planner (class of fn_886BD690/fn_886B8468; owned by the PlayerController at +0x24) ---- */
enum Gp3MoveState {
    GP3_MOVE_0_AFTER_HIT_WAIT = 0,   /* waits until cfg+0x1DC frames passed since the last team hit */
    GP3_MOVE_1_READY = 1,
    GP3_MOVE_2 = 2,
    GP3_MOVE_3 = 3,
    GP3_MOVE_4 = 4,
    GP3_MOVE_5 = 5,
    GP3_MOVE_6 = 6,
    GP3_MOVE_7_ADJUST_A = 7,         /* ball sample within 250 cm: step adjust (direction a) */
    GP3_MOVE_8_ADJUST_B = 8,
    GP3_MOVE_9 = 9,
    GP3_MOVE_10 = 10,
    GP3_MOVE_11 = 11,
    GP3_MOVE_12 = 12,
    GP3_MOVE_13 = 13,
    GP3_MOVE_14 = 14,
    GP3_MOVE_15_PICK_CANDIDATE = 15, /* commits a ball sample (fn_8865DBA8) then classifies via fn_88699FC0 */
    GP3_MOVE_16_VOLLEY = 16,         /* returned by fn_88699FC0 when the chosen sample type is Volley */
    GP3_MOVE_17 = 17,
    GP3_MOVE_18 = 18,
    GP3_MOVE_19 = 19,
    GP3_MOVE_20_RUSH = 20,           /* "[Rush]" validated by fn_88688948(cfg+0x270) */
    GP3_MOVE_21_JOG_PREPARED = 21,   /* "[JogPrepared]" fn_88688948(cfg+0x284) */
    GP3_MOVE_22_JOG_JOG_PREPARED = 22 /* "[JogJogPrepared]" fn_88688948(cfg+0x298) */
};

/* Movement-mode validity entry (player cfg +0x270 Rush, +0x284 JogPrepared, +0x298 JogJogPrepared): 0x14 bytes. */
struct Gp3MoveModeCfg {
    gp3_u32 u_00[4];
    float  min_distance;         /* +0x10 minimum |contact - player| in cm; fn_88688948 returns false below it */
};

#endif /* GP3_TYPES_H */
