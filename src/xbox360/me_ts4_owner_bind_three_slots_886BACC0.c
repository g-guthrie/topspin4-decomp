/* 0x886BACC0: binds an object to its owner, then initialises three 0x44-byte slots (+0xc, +0x50, +0x94) from the owner's
 * graph set entries found by hash (0xC4B26668, 0x661A3F2C, 0x39968A9E) via fn_88911668. */

typedef unsigned int u32;
typedef struct { char pad[0x8c]; char a[0xd4-0x8c]; char b[4]; } Tbl;
typedef struct { char pad[0x44]; Tbl *tbl; char p48[0x74-0x48]; char *x74; char p78[0x330-0x78]; char x330[4]; } Owner;
typedef struct { char d[0x44]; } Slot;
typedef struct { u32 f0; u32 f4; char *f8; Slot s0; Slot s1; Slot s2; Owner *owner; } O;
extern void *ts4_graph_set_find_8866F028(Tbl *t, u32 *h);
extern void fn_88911668(Slot *s, char *x, void *e, char *a, char *b);
static void slot_init(Slot *s, Owner *ow, u32 *h) {
    Tbl *t = ow->tbl;
    fn_88911668(s, ow->x330, ts4_graph_set_find_8866F028(t, h), t->a, t->b);
}
void ts4_owner_bind_three_slots_886BACC0(O *o, Owner *ow, u32 v) {
    u32 h;
    o->owner = ow;
    o->f8 = ow->x74 + 0xa40;
    o->f4 = v;
    h = 0xC4B26668; slot_init(&o->s0, o->owner, &h);
    h = 0x661A3F2C; slot_init(&o->s1, o->owner, &h);
    h = 0x39968A9E; slot_init(&o->s2, o->owner, &h);
}
