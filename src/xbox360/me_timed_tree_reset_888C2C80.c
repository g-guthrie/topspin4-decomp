/* 0x888C2C80: if the node at +0x1C exists, clears its active byte (+0x54) and timer (+0x74, set to the 0.0f
 * constant g_ts4_event_value), then does the same for every 0x84-byte child in its {begin,end} array at +0x84. */
typedef unsigned char u8;
extern float g_ts4_event_value;
typedef struct Ts4TimedNode { char p[0x54]; u8 active; char q[0x74 - 0x55]; float timer; char r[0x84 - 0x78]; } Ts4TimedNode;
typedef struct Ts4TimedTree { Ts4TimedNode node; Ts4TimedNode *begin; Ts4TimedNode *end; } Ts4TimedTree;
typedef struct Ts4TimedOwner { char p[0x1c]; Ts4TimedTree *tree; } Ts4TimedOwner;
void ts4_timed_tree_reset_888C2C80(Ts4TimedOwner *o)
{
    Ts4TimedTree *t = o->tree;
    Ts4TimedNode *i, *e;
    if (!t) return;
    i = t->begin;
    e = t->end;
    t->node.active = 0;
    t->node.timer = g_ts4_event_value;
    for (; i != e; i++) {
        i->timer = g_ts4_event_value;
        i->active = 0;
    }
}
