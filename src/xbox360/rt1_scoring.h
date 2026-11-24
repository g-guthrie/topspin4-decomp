#ifndef RT1_SCORING_H
#define RT1_SCORING_H
/*
 * RT1: standard tennis scoring types (docs/gameplay/rules-and-scoring.md s2-s4). Taken from D2G's
 * draft work/army/d2g_scratch/8866A1C8_best.c (Ts4* names renamed Rt1* because they were never in a
 * shared header) and extended with the RulesInfo fields of Rules_PublishPointEndFlags.
 */
#include "d1g_types.h"

#define RT1_REASON_MISS 0xC222A5E0u
#define RT1_BALL_LET_IN 0x8F903DFBu
#define RT1_BALL_LET_OUT 0x02315629u
#define RT1_GAME_MODE_E981B5D1 0xE981B5D1u

struct Rt1BallState { ts4_u8 pad_00[0x2C]; ts4_u32 mode; /* +0x2C ball outcome mode */ };
struct Rt1BallHolder { ts4_u8 pad_00[0x20]; struct Rt1BallState *ball; /* +0x20 */ };

/* Per-set entry (12 bytes). */
struct Rt1SetEntry {
    int games;                /* +0x00 games won in this set */
    int points;               /* +0x04 last recorded point count (tie-break score) */
    ts4_u8 single_game;       /* +0x08 set decided by a single game */
    ts4_u8 pad_09[3];
};

/* Player score record (stride 0x18). */
struct Rt1ScorePlayer {
    struct Ts4RelArray sets;  /* +0x00 Rt1SetEntry[] */
    ts4_u32 unk_08;
    int points;               /* +0x0C raw point count in the current game */
    int sets_won;             /* +0x10 */
    int display;              /* +0x14 */
};

/* Score state (RulesInfo +0x24). */
struct Rt1ScoreState {
    int players_rel;          /* +0x00 (R+0x24) self-relative pointer to two Rt1ScorePlayer */
    int player_count;         /* +0x04 (R+0x28) */
    ts4_u32 unk_08;
    int cur_set;              /* +0x0C (R+0x30) */
    ts4_bool tiebreak;        /* +0x10 (R+0x34) */
    ts4_bool super_tiebreak;  /* +0x11 (R+0x35) */
    ts4_bool deuce;           /* +0x12 (R+0x36) */
    ts4_bool first_deuce;     /* +0x13 (R+0x37) */
};

/* RulesInfo block (B44 + 0x90). */
struct Rt1RulesInfo {
    ts4_u8 pad_00[0x04];
    ts4_bool missed_serve;    /* +0x04 point ended by a Miss in the serve phase (RT1, I name) */
    ts4_u8 pad_05[3];
    ts4_bool second_serve_let;/* +0x08 copy of second_serve for a serve-phase point (RT1, I name) */
    ts4_bool second_serve;    /* +0x09 */
    ts4_u8 pad_0a;
    ts4_bool net_cord;        /* +0x0B ball state LetIn or LetOut at a serve-phase point end (RT1) */
    ts4_u8 pad_0c[0x18];
    struct Rt1ScoreState score; /* +0x24 */
    ts4_u8 pad_38[0x06];
    ts4_bool point_end_pending; /* +0x3E consumed by Rules_PublishPointEndFlags [I] */
    ts4_u8 pad_3f;
    ts4_u32 reason;           /* +0x40 CRC-32 of the last point-end reason */
    ts4_bool game_over_event; /* +0x44 */
    ts4_bool set_over_event;  /* +0x45 */
    ts4_bool match_over_event;/* +0x46 */
    ts4_bool forced_end;      /* +0x47 match ended by withdrawal/forced end */
    int last_winner;          /* +0x48 winner of the last awarded point, -1 = none */
    ts4_bool ends_change;     /* +0x4C change-of-ends request after a game [I] */
    ts4_bool ends_change_2;   /* +0x4D second change-of-ends request [I] */
};

/* Flow flags block (Match +0x30). */
struct Rt1ScoreFlow {
    ts4_u8 pad_00[0x91];
    ts4_bool game_over;       /* +0x91 */
    ts4_bool set_over;        /* +0x92 */
    ts4_bool match_over;      /* +0x93 */
    ts4_bool ends_changed;    /* +0x94 */
    ts4_bool fault;           /* +0x95 service fault this point */
    ts4_u8 pad_96[0x328 - 0x96];
    ts4_bool judging_disabled; /* +0x328 */
    ts4_u8 pad_329;
    ts4_bool serve_phase;     /* +0x32A the point ended in the serve phase */
    ts4_u8 pad_32b;
    float progress;           /* +0x32C match progress fraction */
};

/* Game mode object (Match +0x28). */
struct Rt1ScoreMode {
    ts4_u8 pad_00[0x40];
    ts4_bool force_end;       /* +0x40 */
    ts4_u8 pad_41[3];
    int force_winner;         /* +0x44 */
};

/* Game configuration (Match +0x38). */
struct Rt1ScoreGameConfig {
    ts4_u8 pad_00[0x1D0];
    ts4_u32 mode;             /* +0x1D0 game-mode hash (0xE981B5D1: match-over events are not forced) */
    ts4_u8 pad_1d4[0xC];
    ts4_bool single_serve;    /* +0x1E0 */
};

/* Match rules configuration (Match +0x40), written by InitMatchRules. */
struct Rt1MatchRules {
    ts4_u32 unk_00;
    int games_per_set;        /* +0x04 */
    int num_sets;             /* +0x08 */
    ts4_bool tiebreak_sets;   /* +0x0C sets decided by a single tie-break game */
    ts4_u8 pad_0d[0x6B];
    ts4_u32 format;           /* +0x78 game-format hash */
};
#define RT1_FORMAT_SHORT 0x4035E2DFu

/* B44 block. */
struct Rt1ScoreB44 {
    ts4_u8 pad_00[0x54];   /* RulesInfo lives at +0x90 (see Rt1ScoreB44Rules) */
    int server;               /* +0x54 current server */
    ts4_u8 pad_58[0x0C];
    int withdraw_loser;       /* +0x64 */
    ts4_u8 pad_68[0x64];
    ts4_bool event_cc;        /* +0xCC */
    ts4_u8 pad_cd[7];
    ts4_bool event_d4;        /* +0xD4 */
    ts4_bool event_d5;        /* +0xD5 */
    ts4_bool event_d6;        /* +0xD6 */
    ts4_u8 pad_d7[9];
    int point_target;         /* +0xE0 points needed to win the current game */
};

/* Point-end info: reason hash first. */
struct Rt1PointInfo {
    ts4_u32 reason;
};
#define RT1_REASON_LET 0xC9238771u
#define RT1_REASON_WITHDRAWAL 0x22703895u

/* Scoring owner (match context view). */
struct Rt1ScoringOwner {
    ts4_u8 pad_00[0x28];
    struct Rt1ScoreMode *mode;          /* +0x28 */
    ts4_u32 unk_2c;
    struct Rt1ScoreFlow *flow;          /* +0x30 */
    ts4_u32 unk_34;
    struct Rt1ScoreGameConfig *game_config; /* +0x38 */
    ts4_u32 unk_3c;
    struct Rt1MatchRules *config;       /* +0x40 */
    struct Rt1ScoreB44 *b44;            /* +0x44 */
    struct Rt1PointInfo *info;          /* +0x48 */
    ts4_u8 pad_4c[0x10];
    struct Rt1BallHolder *ball;         /* +0x5C */
};

struct Rt1Scoring;

struct Rt1ScoringVtbl {
    void *slot00[7];
    void (*refresh_display)(struct Rt1Scoring *self);                     /* +0x1C 0x8865C648 */
    int (*point_winner)(struct Rt1Scoring *self, struct Rt1PointInfo *info); /* +0x20 0x8865C308 */
    void *slot24[5];
    void (*update_server_and_ends)(struct Rt1Scoring *self);              /* +0x38 0x88676AF0 */
    void *slot3c;
    void (*add_point)(struct Rt1Scoring *self);                          /* +0x40 0x88676DB0 */
};

/* Standard scoring object. */
struct Rt1Scoring {
    struct Rt1ScoringVtbl *vtbl;   /* +0x00 */
    struct Rt1ScoringOwner *owner; /* +0x04 */
    struct Rt1RulesInfo *rules;    /* +0x08 */
    int games_to_win;              /* +0x0C */
    int num_sets;                  /* +0x10 */
    ts4_u8 unk_14;
    ts4_bool final_set_super_tb;   /* +0x15 */
    ts4_u8 pad_16[0x0A];
    ts4_bool match_over;           /* +0x20 */
};

/* B44 view used to reach the embedded RulesInfo. */
struct Rt1ScoreB44Rules {
    ts4_u8 pad_00[0x90];
    struct Rt1RulesInfo rules;          /* +0x90 */
};

#endif
