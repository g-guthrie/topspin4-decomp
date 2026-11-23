/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: planner.h
 *
 * Conventions: docs/agents/types.md. Evidence tags in the field comments:
 *   V <addr..>  the offset and width are used by byte-matched functions at these addresses (config/54540859/match.json).
 *               A trailing `~` means the function was attributed to this class by its access pattern (hub signature),
 *               not by a documented name: treat the class attribution as likely, the offset itself as proven.
 *   U <source>  unverified: read from machine code or data by an earlier analysis, no byte-matched function uses it yet.
 * Pointer targets and field names are interpretation; only offset + width are proven by a V tag.
 * First pass generated from the matched sources by a one-off miner (2026-11-23); maintained by hand since.
 */
#ifndef TS4_PLANNER_H
#define TS4_PLANNER_H

#include "base.h"
#include "math.h"
#include "containers.h"
#include "match.h"
#include "player.h"

/* Movement planner (class of MovePlanner_Update 0x886BD690 / NextState 0x886B8468). q5: Q5Planner. */
typedef struct Ts4MovePlanner {
    char pad_0000[0x24];
    unsigned int f_024;                          /* +0x024 V 886A31B8 886A3238 886A33C0 */
    char pad_0028[0xF8];
    unsigned char committed;                     /* +0x120 V 8866BD00 */
    char pad_0121[0x33];
    struct Ts4Player *player;                    /* +0x154 V 8865DAC0 8865DB50~ 8866BD00 8866BEE0~ +4 also read as unsigned int (886A31B8) */
    char pad_0158[0x118];
    Ts4Vec4 f_270;                               /* +0x270 V 8866C150 (position compared with player->state->local_position) */
    char pad_0280[0x4];
    unsigned char side_flags_latched;            /* +0x284 U symbols.md */
    char pad_0285[0x3];
    unsigned int held_command[2];                /* +0x288 U symbols.md */
    char pad_0290[0x4];
    unsigned char f_294;                         /* +0x294 V 8866C150 */
    char pad_0295[0xB];
    int f_2a0;                                   /* +0x2A0 V 8865DB50~ */
} Ts4MovePlanner;
TS4_ASSERT_OFFSET(Ts4MovePlanner, f_024, 0x24);
TS4_ASSERT_OFFSET(Ts4MovePlanner, committed, 0x120);
TS4_ASSERT_OFFSET(Ts4MovePlanner, player, 0x154);
TS4_ASSERT_OFFSET(Ts4MovePlanner, f_270, 0x270);
TS4_ASSERT_OFFSET(Ts4MovePlanner, side_flags_latched, 0x284);
TS4_ASSERT_OFFSET(Ts4MovePlanner, held_command, 0x288);
TS4_ASSERT_OFFSET(Ts4MovePlanner, f_294, 0x294);
TS4_ASSERT_OFFSET(Ts4MovePlanner, f_2a0, 0x2A0);

/* CandidateSet (0x60 bytes, two per brain). gp2: Gp2CandidateSet. */
typedef struct Ts4CandidateSet {
    char pad_0000[0x1C];
    float best_reach_speed;                      /* +0x01C U gp2_types.h */
    unsigned char dirty;                         /* +0x020 V 886A39A8 */
    char pad_0021[0x2F];
    int first_index;                             /* +0x050 U gp2_types.h */
    int last_index;                              /* +0x054 U gp2_types.h */
    char pad_0058[0x8];
} Ts4CandidateSet;
TS4_ASSERT_OFFSET(Ts4CandidateSet, best_reach_speed, 0x1C);
TS4_ASSERT_OFFSET(Ts4CandidateSet, dirty, 0x20);
TS4_ASSERT_OFFSET(Ts4CandidateSet, first_index, 0x50);
TS4_ASSERT_OFFSET(Ts4CandidateSet, last_index, 0x54);
TS4_ASSERT_SIZE(Ts4CandidateSet, 0x60);

/* ReachRecord (0x34 bytes, two per brain). gp2: Gp2ReachRecord. */
typedef struct Ts4ReachRecord {
    char pad_0000[0x24];
    float side_offset;                           /* +0x024 U gp2_types.h */
    char pad_0028[0x8];
    unsigned char valid;                         /* +0x030 V 886A9628 */
    char pad_0031[0x3];
} Ts4ReachRecord;
TS4_ASSERT_OFFSET(Ts4ReachRecord, side_offset, 0x24);
TS4_ASSERT_OFFSET(Ts4ReachRecord, valid, 0x30);
TS4_ASSERT_SIZE(Ts4ReachRecord, 0x34);

/* ---- byte-matched functions (current symbol names, config/54540859/symbols.txt). Private struct pointers of the
 * matched source that have no shared type yet are `void *`. ---- */
TS4_EXTERN_C_BEGIN
void ts4_move_state_leave_8865DAC0(struct Ts4MovePlanner *self, unsigned int state);                           /* 8865DAC0 */
unsigned char ts4_elapsed_within_limit_8865DB50(struct Ts4MovePlanner *s);                                     /* 8865DB50~ */
void ts4_planner_update_committed_8866BD00(struct Ts4MovePlanner *s);                                          /* 8866BD00 */
int ts4_is_near_mirrored_x_8866BEE0(struct Ts4MovePlanner *s);                                                 /* 8866BEE0~ */
void ga4_publish_query_flag_8869A4D0(struct Ts4MovePlanner *host);                                             /* 8869A4D0 */
unsigned int ts4_if_call_seq_u32_off154_886A31B8(struct Ts4MovePlanner *a0);                                   /* 886A31B8 */
unsigned int ts4_if_call_seq_u32_off154_886A3238(struct Ts4MovePlanner *a0);                                   /* 886A3238 */
unsigned int ts4_if_call_seq_u32_off154_886A33C0(struct Ts4MovePlanner *a0);                                   /* 886A33C0 */
TS4_EXTERN_C_END

#endif /* TS4_PLANNER_H */
