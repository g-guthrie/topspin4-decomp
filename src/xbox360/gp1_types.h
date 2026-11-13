#ifndef GP1_TYPES_H
#define GP1_TYPES_H

/*
 * GP1 (WP1): types for the shot-rating / crowd-excitement package of Swing_DLL.xex.
 *
 * Evidence level: every offset below is read from machine code in the functions listed per struct
 * (Swing_DLL.xex addresses, see work/gameplay-notes/gp1.md). Names are by role; names ending in
 * `/ * ? * /` are guesses. Hash constants are zlib crc32 of the ASCII name (verified against the
 * game's own string labels).
 */

typedef unsigned int gp1_u32;

#define GP1_OFFSET_CHECK(type, field, offset) \
    typedef char gp1_offset_check_##type##_##field[(__builtin_offsetof(type, field) == (offset)) ? 1 : -1]

/* crc32 names used as shot / reward identifiers */
#define GP1_HASH_DROPSHOT   0x990377a5u /* "DropShot" */
#define GP1_HASH_LOB        0xc718daaau /* "Lob" */
#define GP1_HASH_SLICE      0xfc6f57a1u /* "Slice" */
#define GP1_HASH_TOPSPIN    0xd9fa1b37u /* "TopSpin" */
#define GP1_HASH_FLAT       0xf578057au /* "Flat" */
#define GP1_HASH_SMASH      0x7eb30f90u /* "Smash" */
#define GP1_HASH_SERVICE    0x2e20a34eu /* "Service" (stroke side / context of a serve) */
#define GP1_HASH_FOREHAND   0xe630e16bu /* "Forehand" */
#define GP1_HASH_BACKHAND   0x45fffb93u /* "Backhand" */
#define GP1_HASH_WOOD       0x9cafb633u /* "Wood" (frame hit) */
#define GP1_HASH_NORMAL     0x26296dd2u /* "Normal" (default efficiency class) */
#define GP1_HASH_FAULT      0x5e11f1a7u /* "Fault" */
#define GP1_HASH_IN_NET     0x7ddec718u /* "InNet" */
#define GP1_HASH_LET_IN     0x8f903dfbu /* "LetIn" */
#define GP1_HASH_SINGLE     0xcd0b222fu /* "Single" */
#define GP1_HASH_KING_OF_THE_COURT 0xfb595db2u /* "KingOfTheCourt" */
#define GP1_HASH_IMPORTANT  0x4850af43u /* "Important" */
#define GP1_HASH_CRUCIAL    0xc920ac38u /* "Crucial" */
#define GP1_HASH_EVENT_SET_EXCITEMENT 0xdcbb46e0u /* "SetExcitement" event */
#define GP1_HASH_EVENT_PLAYER_SOUND   0x40ec437fu /* "PlayerSound" event */
#define GP1_HASH_EVENT_APPLAUSE       0xd3f7df83u /* "Applause" */
#define GP1_HASH_MODE_END_OF_POINT    0x87b1920fu /* "EndOfPoint" mode passed to the point-end evaluator */
#define GP1_HASH_MODE_SHOT            0x7110d0bbu /* mode of the per-shot call (name unknown) */

/* Reward / quality hashes that fn_8865B780 labels (all crc32 of the label, S+points). */
#define GP1_REWARD_UNFORCED_ERROR              0xd2db781du
#define GP1_REWARD_COUNTER_EFFICIENT_SHOT      0x466c7e14u
#define GP1_REWARD_SPECTACULAR_ANIMATION       0x2e23f28au
#define GP1_REWARD_ACE                         0xfd119356u
#define GP1_REWARD_VOLLEY                      0x71198650u
#define GP1_REWARD_DROP_SHOT                   0x990377a5u
#define GP1_REWARD_HIGH_POINT_QUALITY          0x78076350u
#define GP1_REWARD_RETURN_EFFICIENT_SHOT       0x3d9faab2u
#define GP1_REWARD_VERY_POWERFUL_SHOT          0xe6d36354u /* spelled "VeryPowerfullShot" in the game */
#define GP1_REWARD_VERY_POWERFUL_SERVICE       0x7f1731e8u
#define GP1_REWARD_VERY_EFFICIENT_SHOT         0x1870e00bu
#define GP1_REWARD_CONNECT_GOOD_SHOTS          0xd5db9aa0u
#define GP1_REWARD_CONNECTED_EFFICIENT_SHOTS   0x035d301fu
#define GP1_REWARD_WRONG_FOOT                  0x32a41e36u
#define GP1_REWARD_VERY_WRONG_FOOT             0x6e55faceu
#define GP1_REWARD_LET                         0xc9238771u
#define GP1_REWARD_REACH_ANIMATION             0x555999b1u
#define GP1_REWARD_RUSHING_ANIMATION           0x39afbba7u
#define GP1_REWARD_RUSHING_TO_BALL             0x7d322733u
#define GP1_REWARD_POWERFUL_SHOT_ANIMATION     0x9aca4d10u
#define GP1_REWARD_SMASH_ANIMATION             0x3ca36f61u
#define GP1_REWARD_LITIGIOUS_BOUNCE            0x6f450666u
#define GP1_REWARD_VERY_EFFICIENT_SLOW_SHOT    0xfa6acf47u
#define GP1_REWARD_VERY_POWERFUL_EFFICIENT_SHOT 0xfe326900u
#define GP1_REWARD_VOLLEY_POWERFUL_SHOT        0x6d63f44au
#define GP1_REWARD_FORCED_ERROR                0xe5723bd0u
#define GP1_REWARD_WINNER_OPPORTUNITY          0x1a64fed3u
#define GP1_REWARD_DOUBLE_FAULT                0x891c1be2u
#define GP1_REWARD_POWERFUL_SHOT               0xadacb502u
#define GP1_REWARD_VOLLEY_SHORT_REACTION_TIME  0x50bf2728u
#define GP1_REWARD_REFLEX_VOLLEY_ANIMATION     0x3559c382u

/* Self-relative array header (offset -1 = empty; elements start `offset` bytes after the header). */
struct Gp1RelArray {
    int offset;
    int count;
};

struct Gp1U32Vector {
    gp1_u32 *begin; /* +0x00 */
    gp1_u32 *end;   /* +0x04 */
    gp1_u32 *cap;   /* +0x08 */
};

/* Float state hanging off a player/ball object at +0x74 (fn_886674E8, fn_88673A78, fn_8868E370, fn_8868EA30, fn_88696718). */
struct Gp1PlayerState {
    unsigned char pad0[0x544];
    float stat_544;               /* +0x544 read in fn_88696718, compared with two limits */
    unsigned char pad1[0x575 - 0x548];
    unsigned char flag_575;       /* +0x575 used by WinSmash condition (fn_8868E370) */
    unsigned char pad2[0x588 - 0x576];
    float shot_efficiency;        /* +0x588 efficiency rating of the player's last shot */
    unsigned char pad3[0x5d9 - 0x58c];
    unsigned char flag_5d9;       /* +0x5d9 used by WinTwentyShots-like condition (WinServeAndVolley, fn_8868E370) */
    unsigned char flag_5da;       /* +0x5da */
    unsigned char pad4[0x7a8 - 0x5db];
    float value_7a8;              /* +0x7a8 compared with limits for WinPassingShot / LoseUnforcedError(EasyBall) */
    unsigned char pad5[0xd80 - 0x7ac];
    float stick_intensity;        /* +0xd80 analyser "StickIntensity" */
    unsigned char pad6[0xe00 - 0xd84];
    float value_e00;              /* +0xe00 */
    unsigned char pad7[0xe20 - 0xe04];
    float value_e20;              /* +0xe20 |.| < limit => WinWinner/WinPassing conditions */
    unsigned char pad8[0xf84 - 0xe24];
    float distance_run;           /* +0xf84 accumulated in fn_88697890 */
    unsigned char pad9[0x1040 - 0xf88];
    float crowd_level;            /* +0x1040 current crowd reaction level, clamped in fn_8868EA30 */
    float crowd_ratio;            /* +0x1044 */
    gp1_u32 shot_counter;         /* +0x1048 */
};

/* Triple printed by fn_88661D58 as "In : %.2f Out : %.2f Net : %.2f", stored at +0xf28 of the block
   evaluator+0x10 -> +0x48 -> +0x28 (landing outcome odds of the shot; producer not located). */
struct Gp1ShotOutcomeOdds {
    float in_court;               /* +0xf28 */
    float out;                    /* +0xf2c */
    float net;                    /* +0xf30 */
};

/* Index node of a player (+0x4c of the player/ball object). */
struct Gp1PlayerNode {
    unsigned char pad0[0x20];
    void *team_side_list;         /* +0x20 */
    void *unknown_24;             /* +0x24 */
    int player_index;             /* +0x28 */
};

struct Gp1Player {
    unsigned char pad0[0x14];
    int id;                       /* +0x14 */
    unsigned char pad1[0x4c - 0x18];
    struct Gp1PlayerNode *node;   /* +0x4c */
    unsigned char pad2[0x74 - 0x50];
    struct Gp1PlayerState *state; /* +0x74 */
};

/*
 * ShotRecord: the shot-parameter block reached through evaluator->shot (+0x20).
 * Only fields touched by WP1 functions are named. All values are inputs written by the swing/ball code
 * before fn_88697890 runs.
 */
struct Gp1ShotRecord {
    unsigned char pad0[0x90];
    unsigned char pad_90[0x34];
    unsigned char flag_c4;        /* +0xc4 (contact +0x34) */
    unsigned char pad1[0xe4 - 0xc5];
    unsigned char valid;          /* +0xe4 shot was hit (contact +0x54) */
    unsigned char pad2[0x16c - 0xe5];
    gp1_u32 stroke_side_hash;     /* +0x16c Forehand / Backhand / Service / Wood ... */
    float field_170;              /* +0x170 compared with 0.0 in fn_88666FC8 */
    gp1_u32 shot_type_hash;       /* +0x174 DropShot / Lob / Smash / Slice / TopSpin / Flat */
    float field_178;              /* +0x178 copied to evaluator+0x304; rating input (power-like) */
    unsigned char pad3[0x184 - 0x17c];
    float field_184;              /* +0x184 rating input (compared with tuning +0xdc, +0xc0 ... ) */
    float field_188;              /* +0x188 rating input (compared with tuning +0xd0/+0xd4) */
    unsigned char pad4[0x199 - 0x18c];
    unsigned char flag_199;       /* +0x199 copied to evaluator+0x310 (Smash flag) */
    unsigned char pad5[0x19d - 0x19a];
    unsigned char is_volley;      /* +0x19d copied to evaluator+0x30c (volley) */
    unsigned char pad6[0x220 - 0x19e];
    int hitter_index;             /* +0x220 */
};

/* Reward definition row (stride 0x1c) in the tuning table at tuning+0xdc (fn_88683FA8). */
struct Gp1RewardDef {
    gp1_u32 name_hash;            /* +0x00 */
    int points;                   /* +0x04 S+points */
    gp1_u32 team_hash;            /* +0x08 compared with the global side id (0x27c of lbl_88D45B1C) */
    int cap;                      /* +0x0c */
    int min_level;                /* +0x10 minimum excitement level for the bonus to fire */
    float scale;                  /* +0x14 */
    unsigned char enabled_singles; /* +0x18 */
    unsigned char enabled_doubles; /* +0x19 */
    unsigned char pad[2];
};

/* Point-end modifier weights (ints) at tuning+0xe8.. (fn_88685060). */
struct Gp1PointWeights {
    int wood;                     /* +0xe8 */
    int double_fault;             /* +0xec */
    int fault_general;            /* +0xf0 */
    int obviously_out;            /* +0xf4 */
    int ace;                      /* +0xf8 */
    int return_winner;            /* +0xfc ("Return") */
    int volley_winner;            /* +0x100 */
    int volley;                   /* +0x104 */
    int baseline_winner;          /* +0x108 */
    int lob;                      /* +0x10c */
    int smash;                    /* +0x110 */
    int dropshot;                 /* +0x114 */
    int spectacular_anim;         /* +0x118 */
    int powerful_shot;            /* +0x11c */
    int powerful_efficient_shot;  /* +0x120 */
    int very_efficient_shot;      /* +0x124 */
    int very_efficient_return;    /* +0x128 */
    int trickshot;                /* +0x12c */
    int risk;                     /* +0x130 */
    int litigious;                /* +0x134 */
    int reach;                    /* +0x138 */
    int passing_shot;             /* +0x13c */
    int let;                      /* +0x140 */
    int fatality;                 /* +0x144 */
    int short_rally;              /* +0x148 */
    int memorable_rally;          /* +0x14c */
    int boring_rally;             /* +0x150 */
    int epic_rally;               /* +0x154 */
    int game_point;               /* +0x158 */
    int set_point;                /* +0x15c */
    int match_point;              /* +0x160 */
    int first_game;               /* +0x164 */
    int important_point;          /* +0x168 */
    int crucial_point;            /* +0x16c */
};

/*
 * Match statistics + rating thresholds block, evaluator+0x28 (fn_88673A78, fn_88673C50, fn_886674E8,
 * fn_88666FC8, fn_88685060, fn_88696718, fn_88667720). Only evidenced fields are listed.
 */
struct Gp1PlayerStats {
    unsigned char pad0[0x7c];
    int backhand_count;           /* +0x7c */
    int forehand_count;           /* +0x80 */
    unsigned char pad1[0xa8 - 0x84];
    int topspin_count;            /* +0xa8 */
    int slice_count;              /* +0xac */
    int flat_count;               /* +0xb0 */
    int lob_count;                /* +0xb4 */
    int drop_count;               /* +0xb8 */
    unsigned char pad2[0xdc - 0xbc];
    int counter_dc;               /* +0xdc incremented in fn_88696718 (stat_544 in range) */
    unsigned char pad3[0x100 - 0xe0];
    int counter_100;              /* +0x100 (player flag 0x3d) */
    unsigned char pad4[0x108 - 0x104];
    int counter_108;              /* +0x108 (player flag 0x3e) */
    unsigned char pad5[0x110 - 0x10c];
    int counter_110;              /* +0x110 (player flag 0x3f) */
    unsigned char pad6[0x11c - 0x114];
    int counter_11c;              /* +0x11c */
    unsigned char pad7[0x12c - 0x120];
    int counter_12c;              /* +0x12c (state flag 0x5da) */
    unsigned char pad8[0x134 - 0x130];
};

struct Gp1ShotTuning {
    float efficiency_streak_min;  /* +0x00 fn_886674E8: the better shot must exceed this efficiency */
    int streak_needed;            /* +0x04 */
    unsigned char pad0[0x0c - 0x08];
    struct Gp1RelArray streak;    /* +0x0c rel array of {int count; unsigned char flag;} (8 bytes) per player */
    unsigned char pad1[0x3c - 0x14];
    struct Gp1RelArray crowd16;   /* +0x3c 16-byte entries per player (+0 int, +0xc flag), fn_88666FC8 */
    unsigned char pad2[0x4c - 0x44];
    struct Gp1RelArray teams64;   /* +0x4c 64-byte entries per player (+0x38 team id) */
    unsigned char pad3[0x5c - 0x54];
    struct Gp1RelArray players;   /* +0x5c Gp1PlayerStats, stride 0x134 */
    unsigned char pad4[0x90 - 0x64];
    struct Gp1RelArray eff_class; /* +0x90 efficiency classes, 0x30-byte Gp1EfficiencyClass rows */
    unsigned char pad5[0xb8 - 0x98];
    float limit_b8;               /* +0xb8 fn_88696718 */
    float limit_bc;               /* +0xbc */
    float limit_c0;               /* +0xc0 */
    unsigned char pad6[0xd0 - 0xc4];
    float serve_power_limit;      /* +0xd0 VeryPowerfulService: ShotRecord.field_188 above */
    float powerful_min_188;       /* +0xd4 PowerfulShot: field_188 above ... */
    float powerful_min_178;       /* +0xd8 ... and field_178 above */
    float volley_power_limit;     /* +0xdc VolleyPowerfulShot: field_184 above */
    float volley_reaction_limit;  /* +0xe0 volley reaction below */
    int connected_needed;         /* +0xe4 ConnectedEfficientShots: streak length */
    float connected_eff_min;      /* +0xe8 efficiency above which the streak counter grows */
    unsigned char pad7[0x10c - 0xec];
    float drop_efficiency_min;    /* +0x10c DropShot reward needs efficiency above */
    unsigned char pad8[0x114 - 0x110];
    int rally_short_limit;        /* +0x114 */
    int rally_memorable_limit;    /* +0x118 */
    int reward_total_boring_limit; /* +0x11c */
    int reward_total_epic_limit;  /* +0x120 */
    unsigned char pad9[0x128 - 0x124];
    int point_importance;         /* +0x128 2 = Important, 3 = Crucial */
    unsigned char pad10[0x130 - 0x12c];
    int last_hitter_130;          /* +0x130 */
    int last_hitter_134;          /* +0x134 */
    gp1_u32 mode_hash_138;        /* +0x138 */
    unsigned char pad11[0x140 - 0x13c];
    float point_modifier_total;   /* +0x140 clamped table lookup at the end of the point */
    /* +0x170: per player 8-byte rows {excitement tier 0..2, stress tier 0..2} written by fn_88666FC8 (struct Gp1RelArray tiers) */
    float reward_window_sum;      /* +0x144 sum of the last 10 shot totals (collector +0x768..+0x78c) */
    float best_window_sum;        /* +0x148 */
    unsigned char rising;         /* +0x14c */
    unsigned char pad12[3];
};

/* Efficiency class row (stride 0x30) at ShotTuning.eff_class (fn_88673A78). A row matches when every value lies in range. */
struct Gp1EfficiencyClass {
    gp1_u32 name_hash;            /* +0x00 e.g. VeryEfficientShot, ReturnEfficientShot, CounterEfficientShot, ... */
    float other_eff_min, other_eff_max; /* +0x04/+0x08 efficiency of the opposing shot (shot B) */
    float eff_min, eff_max;       /* +0x0c/+0x10 efficiency of this shot (shot A) */
    float f184_min, f184_max;     /* +0x14/+0x18 ShotRecord.field_184 */
    float f188_min, f188_max;     /* +0x1c/+0x20 ShotRecord.field_188 */
    float f178_above, f178_max;   /* +0x24 (exclusive lower) / +0x28 */
    unsigned char not_for_volley; /* +0x2c row is skipped for volleys when set */
    unsigned char pad[3];
};

/* Excitement configuration, evaluator+0x2c == collector+0x2c (fn_88683FA8, fn_88685060, fn_88666F18). */
struct Gp1ExcitementCfg {
    unsigned char pad0[0x70];
    int level_floor;              /* +0x70 level is raised to this after a level-up when it is below */
    int level_max;                /* +0x74 */
    int level_unknown_78;         /* +0x78 */
    int gauge_per_level;          /* +0x7c */
    int gauge_decay_80;           /* +0x80 */
    float level_value_base;       /* +0x84 */
    float level_value_step;       /* +0x88 */
    float gauge_value_base;       /* +0x8c */
    float gauge_value_step;       /* +0x90 */
    float zero_value_94;          /* +0x94 */
    unsigned char pad1[0xc0 - 0x98];
    int excitement_level;         /* +0xc0 ("Crowd excitement %d") */
    int excitement_gauge;         /* +0xc4 progress inside the level; "stress" = gauge_per_level * level + gauge */
    int fever_c8;                 /* +0xc8 */
    unsigned char pad2[0xdc - 0xcc];
    struct Gp1RelArray rewards;   /* +0xdc Gp1RewardDef rows, stride 0x1c */
    unsigned char pad3[0xe8 - 0xe4];
    struct Gp1PointWeights weights; /* +0xe8 */
    struct Gp1RelArray rally_steps; /* +0x170 8-byte rows {int, int}: first row whose +4 >= importance-1 selects the rally class (fn_88685060 0x88686008) */
    unsigned char pad5[0x17c - 0x178];
    struct Gp1RelArray point_gain;  /* +0x17c 8-byte rows {?, float}, indexed by clamp(level + reward total, 0, 10); +4 is the gain (fn_88685060) */
};

struct Gp1ShotEvaluatorCollector; /* defined in gp1_notes: see work/gameplay-notes/gp1.md */

#endif
