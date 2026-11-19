/* 0x886BCDA8: binds an object to its owner, copies owner fields, resolves the source entry 0x03B4B446 through the
 * source's finder vcall, hands it with its relative offset to fn_886BCC98, initialises the +0x1c sub-object and the
 * +0x104 graph slot (hash 0xE4F01642). Sibling of 886BACC0. */

typedef unsigned int u32;
typedef struct Ts4GraphSet { char pad[0x8c]; char a[0xd4-0x8c]; char b[4]; } Tbl;
typedef struct Q Q;
typedef struct { void *s[15]; void *(*find)(Q *q, u32 *h); } QVt;
struct Q { QVt *vt; };
typedef struct { char pad[0x24]; char *base; char p28[0x34-0x28]; Q *q; } Src;
typedef struct { char pad[0x24]; Src *src; } X48;
typedef struct { char pad[0x6c]; char *x6c; } X44;
typedef struct { char pad[0x28]; u32 x28; char p2c[0x44-0x2c]; Tbl *tbl; X48 *x48; char p4c[0x74-0x4c]; char *x74; char p78[0x330-0x78]; char x330[4]; } Owner;
typedef struct { char d[0x44]; } Slot;
typedef struct { void *e; char *off; Src *src; } Bind;
typedef struct { Owner *owner; char *f4; u32 f8; char *fc; char p10[0x1c-0x10]; char sub[0x104-0x1c]; Slot s; } O;
extern struct Ts4GraphSlot *ts4_graph_set_find_8866F028(Tbl *t, const u32 *h);
extern void fn_88911668(Slot *s, char *x, struct Ts4GraphSlot *e, char *a, char *b);
extern void fn_886BCC98(O *o, Bind *b, Owner *ow);
extern void fn_886B7A60(char *sub, Owner *ow);
static void slot_init(Slot *s, Owner *ow, u32 *h) {
    Tbl *t = ow->tbl;
    fn_88911668(s, ow->x330, ts4_graph_set_find_8866F028(t, h), t->a, t->b);
}
void ts4_owner_bind_source_slot_886BCDA8(O *o, Owner *ow) {
    u32 h0, h1;
    Bind bd;
    Src *s;
    o->owner = ow;
    o->f8 = ow->x28;
    o->f4 = ow->x74;
    o->fc = ((X44 *)ow->tbl)->x6c + 0x120;
    s = ow->x48->src;
    { Q *q = s->q; char *off = ow->x74 - s->base + 0x66c;
    h0 = 0x03B4B446;
    bd.e = q->vt->find(q, &h0);
    bd.off = off; }
    bd.src = s;
    fn_886BCC98(o, &bd, ow);
    fn_886B7A60(o->sub, ow);
    h1 = 0xE4F01642; slot_init(&o->s, o->owner, &h1);
}
