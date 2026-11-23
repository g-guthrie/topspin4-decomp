/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: shot.h
 *
 * Conventions: docs/agents/types.md. Evidence tags in the field comments:
 *   V <addr..>  the offset and width are used by byte-matched functions at these addresses (config/54540859/match.json).
 *               A trailing `~` means the function was attributed to this class by its access pattern (hub signature),
 *               not by a documented name: treat the class attribution as likely, the offset itself as proven.
 *   U <source>  unverified: read from machine code or data by an earlier analysis, no byte-matched function uses it yet.
 * Pointer targets and field names are interpretation; only offset + width are proven by a V tag.
 * First pass generated from the matched sources by a one-off miner (2026-11-23); maintained by hand since.
 */
#ifndef TS4_SHOT_H
#define TS4_SHOT_H

#include "base.h"
#include "math.h"
#include "containers.h"
#include "match.h"
#include "player.h"
#include "planner.h"
#include "ball.h"

/* Shot template (ShotRow+0x4). d1g: Ts4ShotTemplate. */
typedef struct Ts4ShotTemplate {
    char pad_0000[0x10];
    int serve_rel;                               /* +0x010 U rt1_types.h */
    char pad_0014[0x74];
    unsigned int id;                             /* +0x088 V 8868F178 */
} Ts4ShotTemplate;
TS4_ASSERT_OFFSET(Ts4ShotTemplate, serve_rel, 0x10);
TS4_ASSERT_OFFSET(Ts4ShotTemplate, id, 0x88);

/* Shot template row (0x14 bytes; Player+0xB0). d1g: Ts4ShotRow. */
typedef struct Ts4ShotRow {
    char pad_0000[0x4];
    struct Ts4ShotTemplate *tmpl;                /* +0x004 V 8868F178 */
    char pad_0008[0x4];
    void *aim;                                   /* +0x00C U rt1_types.h Rt1ShotRowO (aim selector) */
    void *resolution;                            /* +0x010 U rt1_types.h Rt1ShotDef */
} Ts4ShotRow;
TS4_ASSERT_OFFSET(Ts4ShotRow, tmpl, 0x4);
TS4_ASSERT_OFFSET(Ts4ShotRow, aim, 0xC);
TS4_ASSERT_OFFSET(Ts4ShotRow, resolution, 0x10);
TS4_ASSERT_SIZE(Ts4ShotRow, 0x14);

/* Shot decision tree (Player+0xAC). d1g: Ts4ShotTree. */
typedef struct Ts4ShotTree {
    char pad_0000[0x8];
    struct Ts4ShotRow *rows;                     /* +0x008 V 8865A938 8865ED78 */
    struct Ts4ShotRow *rows_end;                 /* +0x00C V 8865ED78 */
    char pad_0010[0x8];
    void *root;                                  /* +0x018 V 8865A9B8 8865ED78 also read as unsigned int (8865A9B8) */
} Ts4ShotTree;
TS4_ASSERT_OFFSET(Ts4ShotTree, rows, 0x8);
TS4_ASSERT_OFFSET(Ts4ShotTree, rows_end, 0xC);
TS4_ASSERT_OFFSET(Ts4ShotTree, root, 0x18);

/* Shot context "SC" (Player+0x70). rt1: Rt1ShotContext. */
typedef struct Ts4ShotContext {
    struct Ts4Player *player;                    /* +0x000 V 88662B60 */
    struct Ts4PlayerState *state;                /* +0x004 V 88662B60 */
    char pad_0008[0x8];
    void *evals;                                 /* +0x010 U rt1_types.h */
    void *evals_end;                             /* +0x014 U rt1_types.h */
    char pad_0018[0xE8];
    void *eval;                                  /* +0x100 U rt1_types.h */
} Ts4ShotContext;
TS4_ASSERT_OFFSET(Ts4ShotContext, player, 0x0);
TS4_ASSERT_OFFSET(Ts4ShotContext, state, 0x4);
TS4_ASSERT_OFFSET(Ts4ShotContext, evals, 0x10);
TS4_ASSERT_OFFSET(Ts4ShotContext, evals_end, 0x14);
TS4_ASSERT_OFFSET(Ts4ShotContext, eval, 0x100);

/* ---- byte-matched functions (current symbol names, config/54540859/symbols.txt). Private struct pointers of the
 * matched source that have no shared type yet are `void *`. ---- */
TS4_EXTERN_C_BEGIN
void *ts4_shot_tree_walk_8865A938(struct Ts4ShotTree *tree, void *node, void *conditions);                     /* 8865A938 */
unsigned int ts4_get_u32_off18_8865A9B8(struct Ts4ShotTree *a0, unsigned int a1);                              /* 8865A9B8 */
void ts4_shot_eval_refresh_flags_88662B60(struct Ts4ShotContext *eval);                                        /* 88662B60 */
TS4_EXTERN_C_END

#endif /* TS4_SHOT_H */
