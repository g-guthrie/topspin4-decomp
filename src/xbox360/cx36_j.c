/* CX36: keyed removal from pointer vectors and a handler constructor, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *fn_88562DC0(void *dst, const void *src, u32 n);

typedef struct Cx36El { void **vt; int key; u8 pad[0x2c - 8]; u32 ukey; } Cx36El;
typedef struct Cx36V { Cx36El **first; Cx36El **last; } Cx36V;
typedef void (*Cx36DelFn)(Cx36El *e, int flags);

/* 0x88933DF0: remove and delete the first element whose key (signed) equals the argument */
void ts4_vec_remove_first_by_key_88933DF0(Cx36V *v, int key)
{
    Cx36El **p = v->first;
    Cx36El **last = v->last;
    if (p == last)
        return;
    for (; p != last; p++) {
        Cx36El *e = *p;
        if (e->key == key) {
            Cx36El **q = p + 1;
            if (q != last)
                fn_88562DC0(p, q, (u32)((char *)last - (char *)q));
            v->last--;
            ((Cx36DelFn)e->vt[0])(e, 1);
            return;
        }
    }
}

#if 0 /* near miss, not byte-identical */
/* 0x88933D58: remove and delete every element whose unsigned key at +0x2c equals the argument */
void ts4_vec_remove_all_by_ukey_88933D58(Cx36V *v, u32 key)
{
    Cx36V *w = v;
    Cx36El **p = v->first;
    Cx36El **q;
    if (p == v->last)
        return;
    q = p + 1;
    do {
        Cx36El *e = *p;
        if (key == e->ukey) {
            if (q != w->last)
                fn_88562DC0(p, q, (u32)((char *)w->last - (char *)q));
            w->last--;
            ((Cx36DelFn)e->vt[0])(e, 1);
        } else {
            q++;
            p++;
        }
    } while (p != v->last);
}
#endif

/* 0x889296C0: handler object constructor (base init, three vtable-like words, two zeroed triplets) */
extern void fn_88617D88(void *o);
extern void *ts4_create_zeroed_triplet(void);
extern char lbl_880D6218[];
extern char lbl_880D62D8[];
extern char lbl_880D6330[];
typedef struct Cx36Han {
    void *vtbl;
    u8 pad[0x1c - 4];
    u32 w1c, w20;
    void *p24;
    void *vt28;
    u32 w2c, w30, w34, w38, w3c;
    void *vt40;
    u32 w44, w48, w4c;
    void *p50;
} Cx36Han;
#if 0 /* near miss, not byte-identical */
Cx36Han *ts4_handler_ctor_889296C0(Cx36Han *o)
{
    fn_88617D88(o);
    o->vtbl = lbl_880D6218;
    o->vt28 = lbl_880D62D8;
    o->w2c = 0;
    o->w30 = 0;
    o->w34 = 0;
    o->w38 = 0;
    o->w3c = 0;
    o->vt40 = lbl_880D6330;
    o->w44 = 0;
    o->w48 = 0;
    o->w4c = 0;
    o->p50 = ts4_create_zeroed_triplet();
    o->p24 = ts4_create_zeroed_triplet();
    o->w20 = 0;
    o->w1c = 0;
    return o;
}
#endif
