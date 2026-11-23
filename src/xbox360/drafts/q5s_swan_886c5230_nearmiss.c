/* nearmiss: 43 off; concrete blocker: address-formation shape. Size (0xC0), control flow and every load offset
 * match, but the game keeps explicit base registers &tbl->clips (addi +0x60) and &tbl->helds (addi +0x6C) inside
 * each branch and indexes with lhzx/add off those bases, and it forms rel pointers as base+off after the type
 * compare; here MSVC folds them into displacement loads (lhz 0x60(t), addi r3,r11,0x6c). Rel*-taking helpers
 * (DA1 rule) keep the bases but hoist them above the branch; a merged single held_of() call drops size to 0x88.
 * 0x886C5230: returns the held-state record for rec: rec's relative node (or, when rec->type is not 0xA0B2A282,
 * the c-th child link of that node), mapped through the clip table to the held table. */
typedef struct Rel { int off; int count; } Rel;
typedef struct Held { int state; int count; int w2, w3; } Held;
typedef struct Clip1c { unsigned short held; unsigned char pad[0x1a]; } Clip1c;
typedef struct Node { Rel kids; unsigned char pad[4]; unsigned short clip; } Node;
typedef struct Link { int off; int pad; } Link;
typedef struct Tbl { unsigned char pad[0x60]; Rel clips; unsigned char p68[4]; Rel helds; } Tbl;
typedef struct P48 { unsigned char pad[0xc]; Tbl *tbl; } P48;
typedef struct Self { unsigned char pad[0x48]; P48 *p48; } Self;
typedef struct Rec { unsigned char pad[0x5c]; int node; unsigned type; } Rec;
static __inline Node *rel_node(int *p) { return (Node *)((char *)p + *p); }
static __inline Link *link_at(Rel *a, int i) { return (Link *)((char *)a + (i * 8 + a->off)); }
static __inline Held *held_of(Tbl *t, Node *n)
{
    Clip1c *c = (Clip1c *)((char *)&t->clips + ((short)n->clip * 0x1c + t->clips.off));
    return (Held *)((char *)&t->helds + ((short)c->held * 16 + t->helds.off));
}
Held *ts4_rec_find_held_886C5230(Self *self, Rec *rec, unsigned c)
{
    Held *r = 0;
    if (rec != 0) {
        Tbl *t = self->p48->tbl;
        Node *n = rel_node(&rec->node);
        if (rec->type == 0xA0B2A282u) r = held_of(t, n);
        else r = held_of(t, rel_node(&link_at(&n->kids, c)->off));
    }
    return r;
}
