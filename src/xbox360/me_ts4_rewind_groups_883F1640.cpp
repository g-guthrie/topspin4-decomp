/* 0x883F1640: rewinds every node of every group (clears counters and level, resets flags to 0x400, invalidates the index for kind-3 keys), marks every sub-entry, calls fn_883F0480(t, 1), then reapplies each pending item's level and flushes kind-0x30 items */
/* Matched on /O1 plain only (work/army/ME/v.py chk); C++ virtual set_level (slot 4); the zero float is a local held in f31. */
struct Link { Link *next; };
struct Tbl { char pad[0xC]; void *key; };
struct Def { char pad[0xC]; Tbl *tbl; };
struct Node { int p0; Link link; char p8[0x14 - 8]; Def *def; char p18[0x24 - 0x18]; unsigned int flags; char p28[0x40 - 0x28]; short index; char p42[0x4C - 0x42]; float level; char p50[0x84 - 0x50]; int p84; char p88[4]; short p8c; };
struct Sub { int p0; Link link; char p8[0x24 - 8]; unsigned short flags; };
struct Grp { int p0; Link link; char p8[0x34 - 8]; Link nodes; char p38[0x40 - 0x38]; Link subs; };
struct Mode { char pad[0x10]; float gain; char p14[0x28 - 0x14]; unsigned int flags; };
struct Item {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void set_level(float v);
    Link link; char p8[0x14 - 8]; Mode *mode; char p18[0x24 - 0x18]; int p24; unsigned int flags; float level;
};
struct Obj { char pad[0x60]; unsigned int flags; };
struct T { int p0; Obj *obj; char p8[4]; Link groups; char p10[0x18 - 0x10]; Link items; };
extern "C" int ts4_get_bits_0_1c_7_883E0778(void *key);
extern "C" int fn_883F0480(T *t, int a);
extern "C" int fn_883CF9B8(Item *it, int a);
extern "C" int ts4_rewind_groups_883F1640(T *t)
{
    float z = 0.0f;
    Link *n, *m;
    Grp *g;
    Node *node;
    Item *it;
    int r;
    t->obj->flags |= 0x4000000;
    for (n = t->groups.next; n != &t->groups; n = n->next) {
        g = n ? (Grp *)((char *)n - 4) : 0;
        for (m = g->nodes.next; m != &g->nodes; m = m->next) {
            node = m ? (Node *)((char *)m - 4) : 0;
            node->p8c = 0;
            node->p84 = 0;
            node->level = z;
            node->flags = (node->flags & ~0x189) | 0x400;
            if (ts4_get_bits_0_1c_7_883E0778(node->def->tbl->key) == 3)
                node->index = -1;
        }
        for (m = g->subs.next; m != &g->subs; m = m->next)
            (m ? (Sub *)((char *)m - 4) : 0)->flags |= 1;
    }
    r = fn_883F0480(t, 1);
    if (r) return r;
    for (n = t->items.next; n != &t->items; n = n->next) {
        it = n ? (Item *)((char *)n - 4) : 0;
        it->p24 = 0;
        if ((it->mode->flags & 6) && it->mode->gain != z && !(it->flags & 2))
            it->set_level(it->level);
        if (it->mode->flags & 0x30) {
            r = fn_883CF9B8(it, 0);
            if (r) return r;
        }
        it->flags &= ~6;
    }
    return 0;
}
