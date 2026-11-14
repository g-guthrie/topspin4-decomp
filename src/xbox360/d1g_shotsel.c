/*
 * D1G: shot selection (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Shot request -> ShotSelection.Request flags (PlayerState +0x400..+0x40B) -> decision-tree walk.
 * Behaviour and offsets: docs/gameplay/controls-and-shot-selection.md sections 2, 4 and 6
 * (PlayerState field names come from the Layoutall.bin schema).
 */
#include "d1g_types.h"

/* Walk the shot decision tree from `node`: a node takes child 0 when its bound condition byte is 1,
   else child 1; the leaf gives the row index into tree->rows. Swing_DLL.xex 0x8865A938 */
D1G_NOINLINE struct Ts4ShotRow *ts4_shot_tree_walk_8865A938(struct Ts4ShotTree *tree, struct Ts4ShotTreeNode *node,
                                               struct Ts4ConditionVector *conditions)
{
    while (node->kind == TS4_SHOT_TREE_KIND_NODE) {
        struct Ts4ShotTreeBody *body = (struct Ts4ShotTreeBody *)((char *)node + node->rel);
        if (*conditions->begin[body->condition] == 1)
            node = &((struct Ts4ShotTreeNode *)((char *)body + body->rel))[0];
        else
            node = &((struct Ts4ShotTreeNode *)((char *)body + body->rel))[1];
    }
    return &tree->rows[((struct Ts4ShotTreeLeaf *)((char *)node + node->rel))->row];
}

/* Re-select the template row (PC+0xB0): the shot-editor override row when the debug config forces one,
   else the decision-tree result. Swing_DLL.xex 0x8865ED78 */
D1G_NOINLINE void ts4_shot_select_row_8865ED78(struct Ts4PlayerController *pc)
{
    struct Ts4ShotRow *row = 0;
    struct Ts4DebugConfig *debug = pc->match->debug;
    if (debug->force_row && !debug->forced_row_off) {
        struct Ts4ShotRow *it = pc->tree->rows;
        struct Ts4ShotRow *end = pc->tree->rows_end;
        for (; it != end; it++) {
            if (it->tmpl->id == debug->forced_row_id) {
                row = it;
                break;
            }
        }
    } else {
        row = ts4_shot_tree_walk_8865A938(pc->tree, pc->tree->root, &pc->conditions);
    }
    pc->row = row;
}

/* InputState.ShotTriggers element accessor used as the find_if predicate: &entry->raise. */
extern ts4_u8 *ts4_fn_882720A0(struct Ts4ShotInput *entry);
/* std::find_if over Ts4ShotInput[] with an accessor returning a bool pointer. */
struct Ts4ShotInput *fn_88270780(struct Ts4ShotInput *first, struct Ts4ShotInput *last,
                                 ts4_u8 *(*pred)(struct Ts4ShotInput *));

static struct Ts4ShotInput *ts4_rel_begin(struct Ts4RelArray *a)
{
    struct Ts4ShotInput *p = 0;
    if (a->offset != -1)
        p = (struct Ts4ShotInput *)((char *)a + a->offset);
    return p;
}

static struct Ts4ShotInput *ts4_rel_end(struct Ts4RelArray *a)
{
    struct Ts4ShotInput *p = 0;
    if (a->offset != -1)
        p = (struct Ts4ShotInput *)((char *)a + (a->count * 8 + a->offset));
    return p;
}

static struct Ts4ShotInput *ts4_rel_find_if(struct Ts4RelArray *a, ts4_u8 *(*pred)(struct Ts4ShotInput *))
{
    return fn_88270780(ts4_rel_begin(a), ts4_rel_end(a), pred);
}

/* Shot request: take the first held ShotTriggers id (Smash in an overhead situation), rebuild the
   ShotSelection.Request flags from it and InputState.Risk, walk the tree, and rename the two drop-shot
   rows' shot to DropShot. Swing_DLL.xex 0x8868F178 */
void ts4_shot_request_8868F178(struct Ts4PlayerController *pc)
{
    ts4_u8 *(*pred)(struct Ts4ShotInput *) = ts4_fn_882720A0;
    struct Ts4InputState *in = &pc->state->input;
    ts4_u32 *shot_id = &pc->shot_id;
    struct Ts4ShotRequest *rq;
    ts4_u8 drop = 0;
    *shot_id = ts4_rel_find_if(&in->shot_triggers, pred)->id;
    if (pc->state->is_smash)
        *shot_id = TS4_SHOT_SMASH;
    rq = &pc->state->request;
    rq->is_flat = 0;
    rq->is_slice = 0;
    rq->is_topspin = 0;
    rq->is_lob = 0;
    rq->is_risk = 0;
    rq->is_classic_serve = 0;
    rq->is_advanced_serve = 0;
    rq->is_smash = 0;
    rq->is_powerful = 0;
    rq->is_medium = 0;
    rq->is_wood = 0;
    rq->is_wood_down = 0;
    rq->is_flat = pc->shot_id == TS4_SHOT_FLAT;
    rq->is_slice = pc->shot_id == TS4_SHOT_SLICE;
    rq->is_topspin = pc->shot_id == TS4_SHOT_TOPSPIN;
    rq->is_lob = pc->shot_id == TS4_SHOT_LOB;
    rq->is_smash = pc->shot_id == TS4_SHOT_SMASH;
    rq->is_risk = in->risk;
    rq->is_classic_serve = 0;
    rq->is_advanced_serve = 0;
    ts4_shot_select_row_8865ED78(pc);
    if (pc->row->tmpl->id == TS4_ROW_DROPSHOTNORMAL || pc->row->tmpl->id == TS4_ROW_DROPVOLLEY)
        drop = 1;
    if (drop)
        pc->shot_id = TS4_SHOT_DROPSHOT;
}
