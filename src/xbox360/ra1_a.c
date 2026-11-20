/*
 * RA1 (register assignment) matches. Each function's saved-register assignment depended on a source detail:
 *
 * Swing_DLL.xex 0x886BC3A0 ts4_spawn_pooled_886BC3A0: the pushed object is copied into an address-taken
 *   local (`val = o`) right after it is popped; the push helper takes the value for its fast path and the
 *   address of the copy for the slow-path call. Gives the early `stw r31,0x50(r1)` and s=r30 / o=r31.
 * Swing_DLL.xex 0x886900E8 ts4_update_flags_886900E8: literal 0/1 stores straddling the vcalls are
 *   CSE'd into saved registers (one=r29, zero=r30); the `q->b470 && q->b472` bool reuses them
 *   (`mr r11,r29` / `mr r11,r30`). No one/zero locals.
 * Swing_DLL.xex 0x88658C80 ts4_release_pending_88658C80: `a = *slot` read through the address local
 *   (slot=r30 above zero=r29); `self->w2c = 0` inside the `if (pend)` block puts the zero's `li` before the test.
 */

/* ---- 0x886BC3A0 ---- */
struct S20;
typedef struct Obj20 { char pad[0x1c]; struct S20 *owner; char p2[0x64 - 0x20]; void *f64; char p3[0x7c - 0x68]; unsigned f7c; } Obj20;
typedef struct Q20 { char pad[4]; Obj20 **endp; char p2[0xc]; Obj20 **cur; } Q20;
typedef struct P20 { char pad[4]; Q20 qa; Q20 qb; } P20;
typedef struct Vec20 { char pad[4]; Obj20 **end; Obj20 **cap; } Vec20;
typedef struct S20 { char pad[0x74]; P20 *p74; Vec20 vec; unsigned f84; } S20;
void fn_886BBEA8(Obj20 *o);
void ts4_vector_realloc_insert_8826B718(Vec20 *v, Obj20 **where, Obj20 **val, int n, int m);
static __inline Obj20 *w20_pop(Q20 *q)
{
    Obj20 *x = 0;
    if (q->cur != q->endp) {
        x = *q->cur;
        q->cur++;
    }
    return x;
}
static __inline void w20_push(Vec20 *v, Obj20 *x, Obj20 **val)
{
    if (v->end != v->cap) {
        if (v->end)
            *v->end = x;
        v->end++;
    } else {
        ts4_vector_realloc_insert_8826B718(v, v->end, val, 1, 1);
    }
}
void ts4_spawn_pooled_886BC3A0(S20 *s)
{
    Obj20 *o = w20_pop(&s->p74->qb);
    Obj20 *val = o;
    o->f64 = w20_pop(&s->p74->qa);
    o->owner = s;
    o->f7c = s->f84;
    fn_886BBEA8(o);
    w20_push(&s->vec, o, &val);
}

/* ---- 0x886900E8 ---- */
struct W9cV;
typedef struct W9cVt { void *s0; void (*f4)(struct W9cV *); char p[0x10]; void (*f18)(struct W9cV *); } W9cVt;
typedef struct W9cV { W9cVt *vt; } W9cV;
typedef struct W9cQ { char p[0x470]; unsigned char b470; char p1; unsigned char b472; char p2[0x47e - 0x473]; unsigned char b47e, b47f; } W9cQ;
typedef struct W9cO { struct { char p[0x74]; W9cQ *f74; } *vt; } W9cO;
typedef struct W9cX28 { char p[0x48]; unsigned char b48; char p2[0x5e - 0x49]; unsigned char b5e; char p3[0x88 - 0x5f]; unsigned char b88; char p4[0x94 - 0x89]; unsigned char b94; } W9cX28;
typedef struct W9cX44 { char p[0x5c]; unsigned char b5c, b5d; char p2[0xcc - 0x5e]; unsigned char bcc, bcd; } W9cX44;
typedef struct W9cX40 { char p[0xe]; unsigned char be; } W9cX40;
typedef struct W9cP6c { char p[8]; W9cV *p8; } W9cP6c;
typedef struct W9cS { char p0[4]; W9cO *p4; char p[0x1c - 8]; void *p1c; char p2[0x28 - 0x20]; W9cX28 *p28; char p3[0x40 - 0x2c]; W9cX40 *p40; W9cX44 *p44; char p4_[0x68 - 0x48]; W9cV *p68; W9cP6c *p6c; } W9cS;
extern void fn_8867BB78(void *p);
void ts4_update_flags_886900E8(W9cS *s)
{
    if (s->p28->b48 && s->p28->b5e) {
        W9cQ *q = s->p4->vt->f74;
        unsigned char c = q->b470 && q->b472;
        if (c) {
            s->p44->b5d = q->b47f;
            s->p44->b5c = q->b47e;
        }
    }
    if (s->p28->b94) {
        fn_8867BB78(s->p1c);
        s->p28->b94 = 0;
    }
    if (s->p28->b88) {
        s->p6c->p8->vt->f18(s->p6c->p8);
        s->p44->bcd = 1;
        s->p44->bcc = 1;
        s->p68->vt->f4(s->p68);
        s->p44->bcd = 0;
        s->p44->bcc = 0;
        s->p40->be = 0;
        s->p44->b5d = 1;
        s->p28->b88 = 0;
    }
}

/* ---- 0x88658C80 ---- */
typedef unsigned int u32;
typedef unsigned char u8;
struct W8bVtA { unsigned char pad00[0x10]; void (*slot10)(void *self, u32 a, u32 b); };
struct W8bObjA { struct W8bVtA *vt; };
struct W8bVtB { unsigned char pad00[0x58]; void (*slot58)(void *self, void *arg); };
struct W8bObjB { struct W8bVtB *vt; };
struct W8bHolder { unsigned char pad00[4]; struct W8bObjB *b; };
struct W8bVtG { unsigned char pad00[0x38]; void (*slot38)(void *self, void *arg); };
struct W8bObjG { struct W8bVtG *vt; };
struct W8bSelfC {
    unsigned char pad00[0x10]; u32 w10; u32 w14; u32 w18; struct W8bObjA *w1c; unsigned char pad20[4];
    u32 w24; unsigned char pad28[4]; u32 w2c; u8 b30;
};
extern struct W8bObjG *lbl_88D45B2C;
extern int ts4_load_handle_88658B90(struct W8bSelfC *self, int flag);

int ts4_release_pending_88658C80(struct W8bSelfC *self, u32 n)
{
    struct W8bObjA **slot = &self->w1c;
    struct W8bObjA *a = *slot;
    if ((long)a == 0)
        return (int)(unsigned long)a;
    if (self->w18 >= self->w14 + n)
        return 1;
    {
        u32 pend = self->w2c;
        if (pend != 0) {
            a->vt->slot10(a, self->w24, pend);
            self->w2c = 0;
        }
        if (self->b30 != 0) {
            struct W8bHolder *h = (struct W8bHolder *)*slot;
            h->b->vt->slot58(h->b, slot);
        } else if (lbl_88D45B2C != 0) {
            lbl_88D45B2C->vt->slot38(lbl_88D45B2C, slot);
        }
        *slot = 0;
        self->w10 = self->w10 + 1;
        return ts4_load_handle_88658B90(self, 1);
    }
}
