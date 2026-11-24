/* CX36: assorted small object helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *fn_88562DC0(void *dst, const void *src, u32 n);

/* 0x889213A0: iterate the converge step (at most 8 times) and publish the result */
typedef struct Cx36Conv { u32 *cell; void *obj; int val; int cnt; } Cx36Conv;
typedef struct Cx36ConvOwner { u8 pad[0x1c]; Cx36Conv st; } Cx36ConvOwner;
extern int fn_88920388(void *obj, int cur);
void ts4_converge_publish_889213A0(Cx36ConvOwner *o)
{
    Cx36Conv *s = &o->st;
    int i = 0;
    int cur = (int)*s->cell;
    do {
        int next = fn_88920388(s->obj, cur);
        if (next == cur)
            break;
        i++;
        s->cnt = 0;
        cur = next;
    } while (i < 8);
    *s->cell = cur;
    s->val = cur;
    s->cnt = s->cnt + 1;
}

/* 0x88932FF8: pick the unmarked element with the smallest +0x14, track the maximum, mark the pick */
typedef struct Cx36Pick { u8 pad[0x14]; u32 w14; u8 pad2[0x2c - 0x18]; u8 b2c; } Cx36Pick;
typedef struct Cx36PickOwner { u8 pad[0x14]; Cx36Pick *first; Cx36Pick **b; Cx36Pick **e; u8 pad2[0x60 - 0x20]; u32 w60; } Cx36PickOwner;
void ts4_pick_min_mark_88932FF8(Cx36PickOwner *o)
{
    Cx36Pick *best = o->first;
    Cx36Pick **end = o->e;
    Cx36Pick **p = o->b;
    o->w60 = best->w14;
    for (; p != end; p++) {
        Cx36Pick *e = *p;
        if (e->b2c == 0 && e->w14 < best->w14)
            best = e;
        if (e->w14 > o->w60)
            o->w60 = e->w14;
    }
    best->b2c = 1;
}

/* 0x88923648: when the child accepts the id (slot 17), forward it through slot 15 */
typedef struct Cx36Ch { void **vt; } Cx36Ch;
typedef struct Cx36ChOwner { u8 pad[0x30]; u32 w30; Cx36Ch *w34; } Cx36ChOwner;
typedef u8 (*Cx36AcceptFn)(Cx36Ch *c, void *a, u32 *id);
typedef u32 (*Cx36FwdFn)(Cx36Ch *c, u32 *id);
#if 0 /* near miss, not byte-identical */
u32 ts4_forward_if_accepted_88923648(Cx36ChOwner *o, void *a)
{
    Cx36Ch *c = o->w34;
    if (c) {
        u32 id = o->w30;
        void **vt;
        vt = c->vt;
        if (((Cx36AcceptFn)vt[17])(c, a, &id))
            return ((Cx36FwdFn)c->vt[15])(c, &id);
    }
    return 0;
}
#endif
