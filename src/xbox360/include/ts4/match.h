/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: match.h
 *
 * Conventions: docs/agents/types.md. Evidence tags in the field comments:
 *   V <addr..>  the offset and width are used by byte-matched functions at these addresses (config/54540859/match.json).
 *               A trailing `~` means the function was attributed to this class by its access pattern (hub signature),
 *               not by a documented name: treat the class attribution as likely, the offset itself as proven.
 *   U <source>  unverified: read from machine code or data by an earlier analysis, no byte-matched function uses it yet.
 * Pointer targets and field names are interpretation; only offset + width are proven by a V tag.
 * First pass generated from the matched sources by a one-off miner (2026-11-23); maintained by hand since.
 */
#ifndef TS4_MATCH_H
#define TS4_MATCH_H

#include "base.h"
#include "math.h"
#include "containers.h"

/* forward declarations of every shared gameplay class */
struct Ts4Match;
struct Ts4MatchFlow;
struct Ts4DebugConfig;
struct Ts4World;
struct Ts4Settings;
struct Ts4GameplayInterface;
struct Ts4RulesInfo;
struct Ts4TeamState;
struct Ts4Team;
struct Ts4PlayerTuning;
struct Ts4PlayerState;
struct Ts4AIRecord;
struct Ts4AIController;
struct Ts4Body;
struct Ts4Mover;
struct Ts4ReceiverState;
struct Ts4Player;
struct Ts4PlayerComponent;
struct Ts4SwingController;
struct Ts4Repositioning;
struct Ts4MovePlanner;
struct Ts4CandidateSet;
struct Ts4ReachRecord;
struct Ts4BallSample;
struct Ts4BallPrediction;
struct Ts4BallSys;
struct Ts4BallLink;
struct Ts4Ball;
struct Ts4ShotTemplate;
struct Ts4ShotRow;
struct Ts4ShotTree;
struct Ts4ShotContext;

/* Match / world hub (Player+0x48, Team+0x20). d1g: Ts4Match; rt1: Rt1MatchView/O/R; q5: Q5World. */
typedef struct Ts4Match {
    unsigned int hash;                           /* +0x000 V 8866AAF8~ */
    void *players;                               /* +0x004 V 8866DF18~ */
    char pad_0008[0x8];
    void *sides;                                 /* +0x010 V 88663208~ 88682B58~ */
    char pad_0014[0x8];
    void *f_01c;                                 /* +0x01C V 886AB438~ */
    char pad_0020[0x4];
    void *f_024;                                 /* +0x024 V 886BCDA8~ */
    struct Ts4DebugConfig *debug;                /* +0x028 V 8865A890~ 8865ED78 88662B60 886630B8~ +2 */
    char pad_002C[0x4];
    struct Ts4MatchFlow *flow;                   /* +0x030 V 8865AD50~ 8865DB50~ 8865E490~ 8865E980~ +16 also read as unsigned int (8865AD50) */
    char pad_0034[0x10];
    struct Ts4GameplayInterface *hud;            /* +0x044 V 8865F858~ 88660F70~ 8866DA58~ 886706C8~ +3 */
    char pad_0048[0x8];
    void *f_050;                                 /* +0x050 V 88682B58~ */
    char pad_0054[0x4];
    void *flags;                                 /* +0x058 V 886B80B8~ */
    struct Ts4BallSys *balls;                    /* +0x05C V 886624C8~ 8866BD00 8866BEE0~ 886782D0~ +2 */
    char pad_0060[0x18];
    void *mode;                                  /* +0x078 V 8866DF18~ */
    void *f_07c;                                 /* +0x07C V 886AB438~ */
} Ts4Match;
TS4_ASSERT_OFFSET(Ts4Match, hash, 0x0);
TS4_ASSERT_OFFSET(Ts4Match, players, 0x4);
TS4_ASSERT_OFFSET(Ts4Match, sides, 0x10);
TS4_ASSERT_OFFSET(Ts4Match, f_01c, 0x1C);
TS4_ASSERT_OFFSET(Ts4Match, f_024, 0x24);
TS4_ASSERT_OFFSET(Ts4Match, debug, 0x28);
TS4_ASSERT_OFFSET(Ts4Match, flow, 0x30);
TS4_ASSERT_OFFSET(Ts4Match, hud, 0x44);
TS4_ASSERT_OFFSET(Ts4Match, f_050, 0x50);
TS4_ASSERT_OFFSET(Ts4Match, flags, 0x58);
TS4_ASSERT_OFFSET(Ts4Match, balls, 0x5C);
TS4_ASSERT_OFFSET(Ts4Match, mode, 0x78);
TS4_ASSERT_OFFSET(Ts4Match, f_07c, 0x7C);

/* Match flow / clock (Match+0x30). d1g: Ts4MatchClock; rt1: Rt1MatchFlow, Rt1ScoreFlow; q5: Q5Clock. */
typedef struct Ts4MatchFlow {
    char pad_0000[0x7C];
    int key;                                     /* +0x07C V 8869D870~ */
    char pad_0080[0x11];
    unsigned char game_over;                     /* +0x091 V 88669878 88676960 */
    unsigned char set_over;                      /* +0x092 V 88669878 */
    unsigned char match_over;                    /* +0x093 V 88669878 */
    unsigned char ends_changed;                  /* +0x094 V 88669878 */
    unsigned char fault;                         /* +0x095 V 88669878 */
    char pad_0096[0x12];
    int serving_team;                            /* +0x0A8 V 8865EB60 8867DEF0~ */
    unsigned int f_0ac;                          /* +0x0AC V 88682B58~ */
    char pad_00B0[0x260];
    int frame;                                   /* +0x310 V 8865AD50~ 8865DB50~ 8865E490~ 8865E980~ +7 also read as unsigned int (8865AD50) */
    char pad_0314[0x4];
    unsigned int state;                          /* +0x318 V 886AC7E0 */
    char pad_031C[0xC];
    unsigned char f_328;                         /* +0x328 V 886782D0~ */
    unsigned char flag_329;                      /* +0x329 U rt1_types.h Rt1MatchFlowO (Net/Let gate) */
    unsigned char serve_phase;                   /* +0x32A V 8865EB60 88660F70~ 88669878 886706C8~ +2 */
} Ts4MatchFlow;
TS4_ASSERT_OFFSET(Ts4MatchFlow, key, 0x7C);
TS4_ASSERT_OFFSET(Ts4MatchFlow, game_over, 0x91);
TS4_ASSERT_OFFSET(Ts4MatchFlow, set_over, 0x92);
TS4_ASSERT_OFFSET(Ts4MatchFlow, match_over, 0x93);
TS4_ASSERT_OFFSET(Ts4MatchFlow, ends_changed, 0x94);
TS4_ASSERT_OFFSET(Ts4MatchFlow, fault, 0x95);
TS4_ASSERT_OFFSET(Ts4MatchFlow, serving_team, 0xA8);
TS4_ASSERT_OFFSET(Ts4MatchFlow, f_0ac, 0xAC);
TS4_ASSERT_OFFSET(Ts4MatchFlow, frame, 0x310);
TS4_ASSERT_OFFSET(Ts4MatchFlow, state, 0x318);
TS4_ASSERT_OFFSET(Ts4MatchFlow, f_328, 0x328);
TS4_ASSERT_OFFSET(Ts4MatchFlow, flag_329, 0x329);
TS4_ASSERT_OFFSET(Ts4MatchFlow, serve_phase, 0x32A);

/* Debug configuration (Match+0x28). d1g: Ts4DebugConfig. */
typedef struct Ts4DebugConfig {
    char pad_0000[0x48];
    unsigned char f_048;                         /* +0x048 V 886630B8~ */
    char pad_0049[0x21];
    unsigned char f_06a;                         /* +0x06A V 8865A890~ */
    char pad_006B[0x1];
    unsigned char f_06c;                         /* +0x06C V 8869D870~ */
    char pad_006D[0x12];
    unsigned char f_07f;                         /* +0x07F V 886630B8~ */
    char pad_0080[0x3AC];
    unsigned int f_42c;                          /* +0x42C V 8866D930 */
    char pad_0430[0xA8];
    int f_4d8;                                   /* +0x4D8 V 8866D930 */
    char pad_04DC[0x2A8];
    unsigned char net_let_outcomes;              /* +0x784 U rt1_types.h Rt1DebugConfigO */
    char pad_0785[0xBB];
    unsigned int forced_row_id;                  /* +0x840 V 8865ED78 */
    unsigned char forced_row_off;                /* +0x844 V 8865ED78 */
    char pad_0845[0x712];
    unsigned char force_row;                     /* +0xF57 V 8865ED78 88662B60 */
} Ts4DebugConfig;
TS4_ASSERT_OFFSET(Ts4DebugConfig, f_048, 0x48);
TS4_ASSERT_OFFSET(Ts4DebugConfig, f_06a, 0x6A);
TS4_ASSERT_OFFSET(Ts4DebugConfig, f_06c, 0x6C);
TS4_ASSERT_OFFSET(Ts4DebugConfig, f_07f, 0x7F);
TS4_ASSERT_OFFSET(Ts4DebugConfig, f_42c, 0x42C);
TS4_ASSERT_OFFSET(Ts4DebugConfig, f_4d8, 0x4D8);
TS4_ASSERT_OFFSET(Ts4DebugConfig, net_let_outcomes, 0x784);
TS4_ASSERT_OFFSET(Ts4DebugConfig, forced_row_id, 0x840);
TS4_ASSERT_OFFSET(Ts4DebugConfig, forced_row_off, 0x844);
TS4_ASSERT_OFFSET(Ts4DebugConfig, force_row, 0xF57);

/* World services (Player+0x44). rt1: Rt1World, Rt1WorldR. */
typedef struct Ts4World {
    char pad_0000[0x6C];
    struct Ts4Settings *settings;                /* +0x06C V 8865E490~ 886BCDA8~ */
    char pad_0070[0x2A];
    unsigned char f_09a;                         /* +0x09A V 8866AAF8~ */
    char pad_009B[0x19];
    int rng;                                     /* +0x0B4 V 886821A0~ */
} Ts4World;
TS4_ASSERT_OFFSET(Ts4World, settings, 0x6C);
TS4_ASSERT_OFFSET(Ts4World, f_09a, 0x9A);
TS4_ASSERT_OFFSET(Ts4World, rng, 0xB4);

/* Settings root (World+0x6C). rt1: Rt1SettingsRoot. */
typedef struct Ts4Settings {
    char pad_0000[0xA68];
    float f_a68;                                 /* +0xA68 V 8865E490~ */
    char pad_0A6C[0x1C];
    unsigned int hit_lead_frames;                /* +0xA88 U rt1_types.h (20 frames) */
    unsigned int release_frames;                 /* +0xA8C U symbols.md (10 frames) */
} Ts4Settings;
TS4_ASSERT_OFFSET(Ts4Settings, f_a68, 0xA68);
TS4_ASSERT_OFFSET(Ts4Settings, hit_lead_frames, 0xA88);
TS4_ASSERT_OFFSET(Ts4Settings, release_frames, 0xA8C);

/* Gameplay interface / HUD block (Match+0x44). rt1: Rt1GameplayInterface. */
typedef struct Ts4GameplayInterface {
    char pad_0000[0x48];
    int f_048;                                   /* +0x048 V 8866DA58~ */
    char pad_004C[0x8];
    int f_054;                                   /* +0x054 V 88660F70~ 8866DA58~ */
    unsigned int f_058;                          /* +0x058 V 8866DA58~ */
    char pad_005C[0x3D];
    unsigned char busy;                          /* +0x099 V 88682B58~ 886B80B8~ */
    char pad_009A[0x1A];
    int self_off;                                /* +0x0B4 V 886B80B8~ */
    char pad_00B8[0x4C];
    int players_rel;                             /* +0x104 V 8865F858~ 886714C0~ */
    char pad_0108[0x238];
    void *f_340;                                 /* +0x340 V 886B80B8~ */
} Ts4GameplayInterface;
TS4_ASSERT_OFFSET(Ts4GameplayInterface, f_048, 0x48);
TS4_ASSERT_OFFSET(Ts4GameplayInterface, f_054, 0x54);
TS4_ASSERT_OFFSET(Ts4GameplayInterface, f_058, 0x58);
TS4_ASSERT_OFFSET(Ts4GameplayInterface, busy, 0x99);
TS4_ASSERT_OFFSET(Ts4GameplayInterface, self_off, 0xB4);
TS4_ASSERT_OFFSET(Ts4GameplayInterface, players_rel, 0x104);
TS4_ASSERT_OFFSET(Ts4GameplayInterface, f_340, 0x340);

/* Rules / scoring publisher object of ts4_rules_publish_point_end_flags (0x88669878) and 0x88676960. rt1_scoring.h. */
typedef struct Ts4RulesInfo {
    char pad_0000[0x24];
    int players_rel;                             /* +0x024 V 88676960 */
    char pad_0028[0x8];
    int cur_set;                                 /* +0x030 V 88676960 */
    unsigned char tiebreak;                      /* +0x034 V 88676960 */
    char pad_0035[0x5F];
    unsigned char missed_serve;                  /* +0x094 V 88669878 */
    char pad_0095[0x3];
    unsigned char second_serve_let;              /* +0x098 V 88669878 */
    unsigned char second_serve;                  /* +0x099 V 88669878 */
    char pad_009A[0x1];
    unsigned char net_cord;                      /* +0x09B V 88669878 */
    char pad_009C[0x28];
    unsigned char tiebreak_c4;                   /* +0x0C4 V 88669878 */
    char pad_00C5[0x9];
    unsigned char point_end_pending;             /* +0x0CE V 88669878 */
    char pad_00CF[0x1];
    unsigned int reason;                         /* +0x0D0 V 88669878 */
    unsigned char game_over_event;               /* +0x0D4 V 88669878 */
    unsigned char set_over_event;                /* +0x0D5 V 88669878 */
    unsigned char match_over_event;              /* +0x0D6 V 88669878 */
    char pad_00D7[0x5];
    unsigned char ends_change;                   /* +0x0DC V 88669878 */
    unsigned char ends_change_2;                 /* +0x0DD V 88669878 */
} Ts4RulesInfo;
TS4_ASSERT_OFFSET(Ts4RulesInfo, players_rel, 0x24);
TS4_ASSERT_OFFSET(Ts4RulesInfo, cur_set, 0x30);
TS4_ASSERT_OFFSET(Ts4RulesInfo, tiebreak, 0x34);
TS4_ASSERT_OFFSET(Ts4RulesInfo, missed_serve, 0x94);
TS4_ASSERT_OFFSET(Ts4RulesInfo, second_serve_let, 0x98);
TS4_ASSERT_OFFSET(Ts4RulesInfo, second_serve, 0x99);
TS4_ASSERT_OFFSET(Ts4RulesInfo, net_cord, 0x9B);
TS4_ASSERT_OFFSET(Ts4RulesInfo, tiebreak_c4, 0xC4);
TS4_ASSERT_OFFSET(Ts4RulesInfo, point_end_pending, 0xCE);
TS4_ASSERT_OFFSET(Ts4RulesInfo, reason, 0xD0);
TS4_ASSERT_OFFSET(Ts4RulesInfo, game_over_event, 0xD4);
TS4_ASSERT_OFFSET(Ts4RulesInfo, set_over_event, 0xD5);
TS4_ASSERT_OFFSET(Ts4RulesInfo, match_over_event, 0xD6);
TS4_ASSERT_OFFSET(Ts4RulesInfo, ends_change, 0xDC);
TS4_ASSERT_OFFSET(Ts4RulesInfo, ends_change_2, 0xDD);

#endif /* TS4_MATCH_H */
