/* 0x886777B8 (hand match): remember the previous state hash, then choose the new one from the
 * kinds of the two sides' entries: either side of kind 4 wins, else either side of kind 3,
 * else the default state. */
typedef struct Side { char p[0xc]; int kind; char p2[0x18 - 0x10]; } Side;
typedef struct Rel { int offset; } Rel;
typedef struct State { char p[0x24]; Rel sides; char p2[0x60 - 0x28]; unsigned int prev; unsigned int cur; } State;
typedef struct Obj { char p[8]; State *st; } Obj;
static __inline Side *at(Rel *t, int i) { int off = t->offset; return (Side *)((char *)t + off) + i; }
void ts4_pick_state_from_sides_886777B8(Obj *o)
{
    unsigned char k4 = 0, k3 = 0;
    int a, b;
    o->st->prev = o->st->cur;
    a = at(&o->st->sides, 0)->kind;
    b = at(&o->st->sides, 1)->kind;
    if (a == 4 || b == 4)
        k4 = 1;
    else if (a == 3 || b == 3)
        k3 = 1;
    if (k4)
        o->st->cur = 0xC920AC38;
    else if (k3)
        o->st->cur = 0x4850AF43;
    else
        o->st->cur = 0x26296DD2;
}
