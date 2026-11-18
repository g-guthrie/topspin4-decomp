/*
 * RT2: rally-active test used by the swing-category walk (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * docs/gameplay/movement-and-ai.md: "rally active = not in LetIn/LetOut, or the let deadline passed".
 *
 * NEAR MISS (not byte-matched; register assignment differs, 20 instrs) and UNCHECKED by fn_equiv (0 valid trials,
 * the original faults on random inputs; work/equiv/rt2_8866D930.json). Kept only as the LTCG context of
 * rt2_swing_walk.c: it leaves r4 untouched, as the original does.
 */
#include "d1g_types.h"

#define RT2_PAD(name, n) ts4_u8 name[n]

#define RT2_LET_STATE_IN  0x8F903DFBu
#define RT2_LET_STATE_OUT 0x02315629u
#define RT2_PLAYER_BEHAVIOUR_KEY 0xC4CEEEC0u

struct Rt2LetFrame {
    RT2_PAD(pad_00, 0x2C);
    ts4_u32 state;                    /* +0x2C match/let state hash */
    RT2_PAD(pad_30, 0xA8);
    int deadline;                     /* +0xD8 let deadline frame */
};
struct Rt2LetOwner {
    RT2_PAD(pad_00, 0x400);
    struct Rt2LetFrame let;           /* +0x400 let / rally state block */
};
struct Rt2LetClockPtr {
    RT2_PAD(pad_00, 0x310);
    int frame;                        /* +0x310 */
};
struct Rt2LetMatch {
    RT2_PAD(pad_00, 0x28);
    struct Rt2LetOwner *owner;        /* +0x28 */
    RT2_PAD(pad_2c, 4);
    struct Rt2LetClockPtr *clock;     /* +0x30 */
};
struct Rt2BehaviourEntry {
    ts4_u32 unk_00[2];
    ts4_u32 key;                      /* +0x08 */
    struct Rt2BehaviourNode *node;    /* +0x0C */
};
struct Rt2BehaviourLeaf {
    RT2_PAD(pad_00, 0x10);
    ts4_u32 kind;                     /* +0x10 */
};
struct Rt2BehaviourNode {
    RT2_PAD(pad_00, 0x24);
    struct Rt2BehaviourLeaf *leaf;    /* +0x24 */
};
struct Rt2RallyCtl {
    RT2_PAD(pad_00, 0x48);
    struct Rt2LetMatch *match;        /* +0x48 */
    RT2_PAD(pad_4c, 0x48);
    struct Rt2BehaviourEntry *begin;  /* +0x94 */
    struct Rt2BehaviourEntry *end;    /* +0x98 */
};

/* True while the rally is live: not in a let, or the let deadline has passed, and the player's
   behaviour node is not kind 0x11/0x12. Swing_DLL.xex 0x8866D930 */
D1G_EXTERN_C ts4_bool fn_8866D930(struct Rt2RallyCtl *ctl)
{
    ts4_bool active = 1;
    struct Rt2LetMatch *m = ctl->match;
    struct Rt2LetFrame *f = &m->owner->let;
    struct Rt2BehaviourEntry *e;
    struct Rt2BehaviourEntry *found;
    struct Rt2BehaviourEntry *end;
    ts4_u32 kind;
    ts4_bool other;
    if (f->state == RT2_LET_STATE_IN || f->state == RT2_LET_STATE_OUT) {
        int *volatile keep;
        keep = &f->deadline;
        (void)&keep;
        active = (ts4_u32)(f->deadline - m->clock->frame) >> 31;
    }
    if (!active)
        return active;
    found = 0;
    end = ctl->end;
    for (e = ctl->begin; e != end; e++) {
        if (e->key == RT2_PLAYER_BEHAVIOUR_KEY) {
            found = e;
            break;
        }
    }
    kind = found->node->leaf->kind;
    other = kind == 0x11 || kind == 0x12;
    return !other;
}
