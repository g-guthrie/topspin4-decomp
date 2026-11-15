/* CX36: net/lobby constructors and table helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif

/* ---- object with an embedded sub-object at +4 and a u16 at +0x4c4 ---- */
typedef struct Cx36Sub { void *vtbl; u32 a, b, c; } Cx36Sub;
typedef struct Cx36ObjS {
    void *vtbl;
    Cx36Sub sub;
    u8 pad[0x4c4 - 0x14];
    u16 h4c4;
} Cx36ObjS;
extern char lbl_880D2A0C[];
extern char lbl_880D5AA0[];
extern char lbl_880D5ABC[];
CX36_INL void cx36_sub_base_init(Cx36Sub *s)
{
    volatile Cx36Sub *v = s;
    v->a = 0;
    v->b = 0;
}
CX36_INL void cx36_sub_init(Cx36Sub *s)
{
    cx36_sub_base_init(s);
    s->a = 0;
    s->b = 0;
    s->c = 0;
    s->vtbl = lbl_880D2A0C;
}
/* 0x88934D00 */
void ts4_objs_ctor_a_88934D00(Cx36ObjS *o)
{
    o->vtbl = lbl_880D5AA0;
    cx36_sub_init(&o->sub);
    o->h4c4 = 0;
}
#if 0 /* near miss, not byte-identical */
/* 0x88938700 */
void ts4_objs_ctor_b_88938700(Cx36ObjS *o)
{
    cx36_sub_init(&o->sub);
    o->h4c4 = 0;
    o->vtbl = lbl_880D5ABC;
}
#endif

/* ---- range pair constructors (two 12-byte structs passed by value) ---- */
typedef struct Cx36V3 { u32 a, b, c; } Cx36V3;
typedef struct Cx36Rng { Cx36V3 lo; Cx36V3 hi; u8 kind; } Cx36Rng;
CX36_INL void cx36_v3_default(Cx36V3 *v)
{
    v->a = 0;
    v->c = 0;
    v->b = 0xFFFFF;
}
/* 0x88922BD8 */
void ts4_rng_ctor_k1_88922BD8(Cx36Rng *o, Cx36V3 lo, Cx36V3 hi)
{
    cx36_v3_default(&o->hi);
    o->kind = 1;
    o->hi = hi;
    o->lo = lo;
}
/* 0x88922C48 */
void ts4_rng_ctor_k2_88922C48(Cx36Rng *o, Cx36V3 lo, Cx36V3 hi)
{
    cx36_v3_default(&o->hi);
    o->kind = 2;
    o->hi = hi;
    o->lo = lo;
}

/* ---- table countdown loops: when the current id matches an entry, decrement its counter and switch to its value at 0 ---- */
typedef struct Cx36Cnt { u32 id; u32 val; int cnt; } Cx36Cnt;
#if 0 /* near miss, not byte-identical */
/* 0x88922EA8 */
void ts4_cnt_table_step_a_88922EA8(u32 *cur, Cx36Cnt *e, u32 n, int mode)
{
    u32 i;
    if (e == 0)
        return;
    if (n == 0)
        return;
    for (i = 0; i < n; i++, e++) {
        if (*cur == e->id) {
            if (mode == 1 && e->cnt > 0)
                e->cnt--;
            if (e->cnt == 0)
                *cur = e->val;
        }
    }
}
#endif
#if 0 /* near miss, not byte-identical */
/* 0x88925320 */
void ts4_cnt_table_step_b_88925320(u32 *cur, Cx36Cnt *e, u32 n, int mode)
{
    u32 i;
    if (e == 0)
        return;
    if (n == 0)
        return;
    for (i = 0; i < n; i++, e++) {
        if (*cur == e->id) {
            if (mode == 1 && e->cnt > 0)
                e->cnt--;
            if (e->cnt == 0)
                *cur = e->val;
        }
    }
}
#endif
#if 0 /* near miss, not byte-identical */
/* 0x88922F10: same with the current id cached in a signed local */
void ts4_cnt_table_step_c_88922F10(int *cur, Cx36Cnt *e, u32 n, int mode)
{
    int c = *cur;
    u32 i;
    if (e == 0)
        return;
    if (n == 0)
        return;
    for (i = 0; i < n; i++, e++) {
        if (c == (int)e->id) {
            if (mode == 1 && e->cnt > 0)
                e->cnt--;
            if (e->cnt == 0)
                *cur = e->val;
        }
    }
}
#endif

/* 0x889235F8: build a cursor record from the stream's owner (slot 15 of the owner's object) */
typedef struct Cx36CurOwner { void **vt; } Cx36CurOwner;
typedef struct Cx36Stream { u8 pad[0x24]; u32 w24; u8 pad2[0x34 - 0x28]; Cx36CurOwner *own; } Cx36Stream;
typedef struct Cx36Cursor { u32 a; u32 b; Cx36Stream *s; } Cx36Cursor;
typedef u32 (*Cx36CurFn)(Cx36CurOwner *o, u32 *arg);
#if 0 /* near miss, not byte-identical */
Cx36Cursor ts4_make_cursor_889235F8(Cx36Stream *s, u32 pos, u32 arg)
{
    u32 t = arg;
    Cx36Cursor c;
    u32 b = pos - s->w24;
    u32 a = ((Cx36CurFn)s->own->vt[15])(s->own, &t);
    c.a = a;
    c.b = b;
    c.s = s;
    return c;
}
#endif

/* 0x88926600: dispatch slot 21 with the entry found for the key */
extern char *ts4_find_entry24_88924430(void *tab, u32 key);
typedef struct Cx36Disp { void **vt; u8 pad[4]; void *tab; } Cx36Disp;
typedef void (*Cx36DispFn)(Cx36Disp *d, u32 a, char *e, u32 z, u32 c);
#if 0 /* near miss, not byte-identical */
void ts4_dispatch_entry_88926600(Cx36Disp *d, u32 a, u32 *key, u32 c)
{
    void **vt = d->vt;
    char *e = ts4_find_entry24_88924430(d->tab, *key);
    ((Cx36DispFn)vt[21])(d, a, e + 0x10, 0, c);
}
#endif

/* 0x8892EFD0 */
extern void fn_8892EB28(void *s, int a);
extern u32 ts4_if_call_seq_u32_off8_8892ED88(void *s, int a);
extern void *fn_8892E8F8(void *o, u32 v, u32 a);
typedef struct Cx36Fwd { u8 pad[0xc]; void *wc; u8 sub[1]; } Cx36Fwd;
#if 0 /* near miss, not byte-identical */
void *ts4_forward_sub_8892EFD0(Cx36Fwd *o, u32 a)
{
    if (o->wc) {
        fn_8892EB28(o->sub, 0);
        return fn_8892E8F8(o->wc, ts4_if_call_seq_u32_off8_8892ED88(o->sub, 0), a);
    }
    return 0;
}
#endif

/* 0x88933AB8: does the message continue the slot's sequence (key+1 / key with larger value) */
typedef struct Cx36SeqHdr { u8 pad[0x418]; u32 idx; u8 pad2[1]; u8 flag; } Cx36SeqHdr;
typedef struct Cx36SeqMsg { Cx36SeqHdr *h; u32 key; u32 val; } Cx36SeqMsg;
typedef struct Cx36SeqSlot { u32 pad[8]; u32 key; u32 val; } Cx36SeqSlot;
typedef struct Cx36SeqOwner { u32 w[4]; } Cx36SeqOwner;
#if 0 /* near miss, not byte-identical */
u8 ts4_seq_continues_88933AB8(Cx36SeqOwner *o, Cx36SeqMsg *m)
{
    Cx36SeqHdr *h = m->h;
    u32 key = m->key;
    Cx36SeqSlot *s = (Cx36SeqSlot *)((Cx36SeqOwner *)o + h->idx);
    u32 r;
    if (h->flag)
        return s->key + 1 == key;
    if (s->key == key)
        r = m->val > s->val;
    else
        r = 0;
    return (u8)r;
}
#endif
