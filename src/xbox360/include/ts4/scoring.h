/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: scoring.h
 *
 * Tennis scoring objects (docs/gameplay/rules-and-scoring.md s2-s4). Layouts taken from rt1_scoring.h
 * (Rt1Scoring, Rt1ScoreState, Rt1ScorePlayer, Rt1SetEntry) and promoted to V as functions match on them.
 * Conventions and evidence tags: docs/agents/types.md.
 *
 * The scoring object's `rules` pointer (+0x08) is the Ts4RulesInfo of match.h; its score block starts at
 * Ts4RulesInfo +0x24 (players_rel). The original code reaches that block through a pointer to the block
 * itself (`addi rX,rRules,0x24`, fields off rX), so it is its own type here: take it with ts4_rules_score().
 */
#ifndef TS4_SCORING_H
#define TS4_SCORING_H

#include "base.h"
#include "containers.h"
#include "match.h"

struct Ts4Scoring;

/* One set's entry in a player's set list (12 bytes). rt1: Rt1SetEntry. */
typedef struct Ts4SetEntry {
    int games;                                   /* +0x00 U rt1_scoring.h (games won in this set) */
    int points;                                  /* +0x04 U rt1_scoring.h (tie-break points) */
    unsigned char single_game;                   /* +0x08 V 8865C578 (set decided by one game: games_to_win <= 1) */
    char pad_0009[0x3];
} Ts4SetEntry;
TS4_ASSERT_OFFSET(Ts4SetEntry, single_game, 0x8);
TS4_ASSERT_SIZE(Ts4SetEntry, 0xC);

/* One player's score record (stride 0x18), self-relative array at Ts4ScoreState.players_rel. rt1: Rt1ScorePlayer. */
typedef struct Ts4ScorePlayer {
    Ts4RelArray sets;                            /* +0x00 V 8865C578 (self-relative Ts4SetEntry[], one per set) */
    unsigned int f_08;                           /* +0x08 U rt1_scoring.h */
    int points;                                  /* +0x0C V 8865C2D8 (points in the current game) */
    int sets_won;                                /* +0x10 U rt1_scoring.h */
    int display;                                 /* +0x14 V 8865C2D8 (points shown; copy of points) */
} Ts4ScorePlayer;
TS4_ASSERT_OFFSET(Ts4ScorePlayer, points, 0xC);
TS4_ASSERT_OFFSET(Ts4ScorePlayer, sets_won, 0x10);
TS4_ASSERT_OFFSET(Ts4ScorePlayer, display, 0x14);
TS4_ASSERT_SIZE(Ts4ScorePlayer, 0x18);

/* Score block at Ts4RulesInfo +0x24. rt1: Rt1ScoreState. */
typedef struct Ts4ScoreState {
    int players_rel;                             /* +0x00 V 8865C2D8 8865C578 (self-relative Ts4ScorePlayer[]) */
    int player_count;                            /* +0x04 U rt1_scoring.h */
    unsigned int f_08;                           /* +0x08 U */
    int cur_set;                                 /* +0x0C V 8865C578 (Ts4RulesInfo.cur_set) */
    unsigned char tiebreak;                      /* +0x10 V 8865C578 (Ts4RulesInfo.tiebreak) */
    unsigned char super_tiebreak;                /* +0x11 V 8865C578 */
    unsigned char deuce;                         /* +0x12 V 8865C2D8 */
    unsigned char first_deuce;                   /* +0x13 V 8865C2D8 */
} Ts4ScoreState;
TS4_ASSERT_OFFSET(Ts4ScoreState, cur_set, 0xC);
TS4_ASSERT_OFFSET(Ts4ScoreState, tiebreak, 0x10);
TS4_ASSERT_OFFSET(Ts4ScoreState, deuce, 0x12);
TS4_ASSERT_OFFSET(Ts4ScoreState, first_deuce, 0x13);
TS4_ASSERT_SIZE(Ts4ScoreState, 0x14);

/* The score block of a rules object (Ts4RulesInfo +0x24). */
static TS4_INLINE Ts4ScoreState *ts4_rules_score(struct Ts4RulesInfo *r)
{
    return (Ts4ScoreState *)&r->players_rel;
}

/* Scoring object (vtables 0x880F48B8, 0x880F4900 and siblings). rt1: Rt1Scoring. */
typedef struct Ts4Scoring {
    void *vtbl;                                  /* +0x00 U rt1_scoring.h */
    struct Ts4Match *match;                      /* +0x04 V 8865C578 (rt1: Rt1ScoringOwner) */
    struct Ts4RulesInfo *rules;                  /* +0x08 V 8865C2D8 8865C578 */
    int games_to_win;                            /* +0x0C V 8865C578 (games to win a set; 0 in a super tie-break) */
    int num_sets;                                /* +0x10 V 8865C578 */
    unsigned char f_14;                          /* +0x14 U */
    unsigned char final_set_super_tb;            /* +0x15 V 8865C578 (last set is a super tie-break) */
    char pad_0016[0x6];
    int f_1c;                                    /* +0x1C V 8865C578 (cleared at set start) */
    unsigned char match_over;                    /* +0x20 U rt1_scoring.h */
} Ts4Scoring;
TS4_ASSERT_OFFSET(Ts4Scoring, rules, 0x8);
TS4_ASSERT_OFFSET(Ts4Scoring, games_to_win, 0xC);
TS4_ASSERT_OFFSET(Ts4Scoring, final_set_super_tb, 0x15);
TS4_ASSERT_OFFSET(Ts4Scoring, f_1c, 0x1C);
TS4_ASSERT_OFFSET(Ts4Scoring, match_over, 0x20);

#endif /* TS4_SCORING_H */
