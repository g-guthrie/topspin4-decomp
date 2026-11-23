/*
 * Q5: rally-active test of a player (Top Spin 4, Xbox 360, Swing_DLL.xex 0x8866D930, 0xD0 bytes).
 * docs/gameplay/movement-and-ai.md: "rally active = not in LetIn/LetOut, or the let deadline passed".
 *
 * Called first by the move planner 0x886B8468 (its result gates the react branch) and by the swing-category
 * walk 0x886AFDF8. Leaf function: it reads memory only and touches r3 and r5..r11, so an LTCG caller keeps r4
 * and its cached loads across the call.
 *
 * Byte match, plain route and LTCG route:
 *   python3 tools/fn_check.py src/xbox360/q5_rally_active.c ts4_rally_active_8866D930=0x8866D930 --flags /Oc
 *   python3 tools/fn_check_ltcg.py src/xbox360/q5_rally_active.c ts4_rally_active_8866D930=0x8866D930 \
 *       --flags /Oc --context src/xbox360/pp1_pool_primer.c
 *
 * The let timeout is evaluated through a small two-pointer view (Q5rLetTimer). That is what the image shows: the
 * address of the deadline is written to the view's first slot (`stw r8,-0x10(r1)`) although nothing reads it
 * back. A view with one member, a plain local pointer or an inline helper are all kept in registers and lose
 * that store; with the members swapped the store lands at -0xC.
 */
#include "d1g_types.h"

#define Q5R_PAD(name, n) ts4_u8 name[n]

#define Q5R_LET_STATE_IN  0x8F903DFBu    /* match state hash: let, ball coming in */
#define Q5R_LET_STATE_OUT 0x02315629u    /* match state hash: let, ball going out */
#define Q5R_PLAYER_BEHAVIOUR_KEY 0xC4CEEEC0u
#define Q5R_BEHAVIOUR_KIND_11 0x11u
#define Q5R_BEHAVIOUR_KIND_12 0x12u

struct Q5rLetFrame {
    Q5R_PAD(pad_00, 0x2C);
    ts4_u32 state;                    /* +0x2C match/let state hash */
    Q5R_PAD(pad_30, 0xA8);
    int deadline;                     /* +0xD8 frame at which the let times out */
};
struct Q5rLetOwner {
    Q5R_PAD(pad_00, 0x400);
    struct Q5rLetFrame let;           /* +0x400 let / rally state block */
};
struct Q5rClock {
    Q5R_PAD(pad_00, 0x310);
    int frame;                        /* +0x310 current frame */
};
struct Q5rMatch {
    Q5R_PAD(pad_00, 0x28);
    struct Q5rLetOwner *owner;        /* +0x28 */
    Q5R_PAD(pad_2c, 4);
    struct Q5rClock *clock;           /* +0x30 */
};
struct Q5rBehaviourLeaf {
    Q5R_PAD(pad_00, 0x10);
    ts4_u32 kind;                     /* +0x10 */
};
struct Q5rBehaviourNode {
    Q5R_PAD(pad_00, 0x24);
    struct Q5rBehaviourLeaf *leaf;    /* +0x24 */
};
struct Q5rBehaviourEntry {
    ts4_u32 unk_00[2];
    ts4_u32 key;                      /* +0x08 */
    struct Q5rBehaviourNode *node;    /* +0x0C */
};
struct Q5rPlayer {
    Q5R_PAD(pad_00, 0x48);
    struct Q5rMatch *match;           /* +0x48 */
    Q5R_PAD(pad_4c, 0x48);
    struct Q5rBehaviourEntry *begin;  /* +0x94 keyed behaviour table */
    struct Q5rBehaviourEntry *end;    /* +0x98 */
};

/* What a let timeout compares: the deadline frame against the match clock. */
struct Q5rLetTimer {
    const int *deadline;
    const struct Q5rClock *clock;
};

/* True while the rally is live for this player: the match is not in a let (or the let deadline has passed) and
   the player's behaviour node is not of kind 0x11 / 0x12. The table is expected to hold the player-behaviour
   key: without it the original dereferences a null entry, and so does this. */
D1G_EXTERN_C ts4_bool ts4_rally_active_8866D930(struct Q5rPlayer *player)
{
    ts4_bool active = 1;
    struct Q5rMatch *m = player->match;
    struct Q5rLetFrame *f = &m->owner->let;
    struct Q5rBehaviourEntry *e;
    struct Q5rBehaviourEntry *found;
    struct Q5rBehaviourEntry *end;
    ts4_u32 kind;
    ts4_bool other;

    if (f->state == Q5R_LET_STATE_IN || f->state == Q5R_LET_STATE_OUT) {
        struct Q5rLetTimer timer;
        timer.deadline = &f->deadline;
        timer.clock = m->clock;
        active = (ts4_u32)(*timer.deadline - timer.clock->frame) >> 31;
    }
    if (!active)
        return active;

    found = 0;
    end = player->end;
    for (e = player->begin; e != end; e++) {
        if (e->key == Q5R_PLAYER_BEHAVIOUR_KEY) {
            found = e;
            break;
        }
    }
    kind = found->node->leaf->kind;
    other = kind == Q5R_BEHAVIOUR_KIND_11 || kind == Q5R_BEHAVIOUR_KIND_12;
    return !other;
}
