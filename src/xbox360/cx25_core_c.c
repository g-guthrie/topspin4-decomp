/* CX25 part c: game core 0x881EEBB0-0x8820F390, functions that call matched neighbours through their externs, plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
extern long _InterlockedIncrement(long volatile *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif

typedef struct Cx25cR8 { u32 a, b; } Cx25cR8;
typedef struct Cx25cV8 { u32 p0; Cx25cR8 *data; u32 count; } Cx25cV8;
extern u8 ts4_table_nearest_88207848(u32 key, Cx25cV8 *t, u32 *out);
typedef struct Cx25cSel { u8 pad[0x28]; Cx25cV8 t0; u32 pad2; Cx25cV8 t1; u8 pad3[0xac - 0x44]; u32 limit; } Cx25cSel;

/* 0x882078B8: nearest-key lookup in the primary table (when idx is in range), else in the secondary table */
u32 ts4_table_lookup_882078B8(Cx25cSel *o, u32 key, u32 idx)
{
    u32 out = 0;
    if (idx < o->limit && o->t0.count > 0) {
        if (ts4_table_nearest_88207848(key, &o->t0, &out)) return out;
    }
    if (o->t1.count > 0) {
        u8 ok = ts4_table_nearest_88207848(key, &o->t1, &out);
        if (ok) return out;
    }
    return 0;
}

/* ---- vector of 8-byte (string, value) pairs: assignment ---- */
typedef struct Cx25cPr { u32 s; u32 v; } Cx25cPr;
typedef struct Cx25cPrVec { u32 p0; Cx25cPr *data; u32 count; u32 cap; } Cx25cPrVec;
extern void ts4_grow_reserve_8_881DA390(Cx25cPrVec *v, u32 n);
extern void ts4_str_release_each_8820ADD8(Cx25cPr *p, u32 n);
extern void ts4_slots_init_8820B310(Cx25cPr *p, u32 n);
extern void ts4_if_call_seq_u32_off0_8819B0C8(void *dst, void *src);

/* 0x8820ACE8: make d a copy of s: resize (initialise new slots or destroy extras), then copy each pair */
void ts4_prvec_assign_8820ACE8(Cx25cPrVec *d, Cx25cPrVec *s)
{
    u32 n = s->count;
    u32 i;
    Cx25cPr *dp;
    Cx25cPr *sp;
    if (n == 0) {
        ts4_str_release_each_8820ADD8(d->data, d->count);
        d->count = 0;
    } else {
        if (n <= d->cap) {
            if (d->count < n) {
                ts4_slots_init_8820B310(d->data + d->count, n - d->count);
            } else if (d->count > n) {
                ts4_str_release_each_8820ADD8(d->data + n, d->count - n);
            }
        } else {
            ts4_grow_reserve_8_881DA390(d, n);
            ts4_slots_init_8820B310(d->data + d->count, n - d->count);
        }
        d->count = n;
    }
    n = s->count;
    sp = s->data;
    dp = d->data;
    for (i = n; i != 0;) {
        Cx25cPr *cur = dp;
        i--;
        dp++;
        ts4_if_call_seq_u32_off0_8819B0C8(&cur->s, &sp->s);
        cur->v = sp->v;
        sp++;
    }
}

/* ---- reference-counted chain: release up the parent links ---- */
typedef struct Cx25cSub { u32 p0; u32 sub4; } Cx25cSub;
typedef struct Cx25cCh Cx25cCh;
struct Cx25cCh { u32 p0; void (*cb)(void); u32 p8; Cx25cCh *parent; Cx25cSub *sub; int refs; };
extern void fn_881992A8(u32 z, void *p);
extern void ts4_if_call_seq_u32_off0_881C8B60(void *p);

/* 0x881F8B58: drop one count; at zero free the sub-object, run the callback and move on to the parent (volatile view keeps the store/load order) */
void ts4_chain_release_881F8B58(Cx25cCh *o)
{
    Cx25cSub *zero;
    void (*cb)(void);
    o->refs--;
    if (o->refs != 0) return;
    zero = 0;
    for (;;) {
        Cx25cSub *s = o->sub;
        if (s != 0) {
            ts4_if_call_seq_u32_off0_881C8B60(&s->sub4);
            fn_881992A8(0, s);
        }
        ((volatile Cx25cCh *)o)->sub = zero;
        cb = ((volatile Cx25cCh *)o)->cb;
        if (cb != 0) cb();
        {
            Cx25cCh *p = o->parent;
            if (p == 0) return;
            if (p->parent == 0) return;
            o = p;
            o->refs--;
            if (o->refs != 0) return;
        }
    }
}

/* ---- vector of 0x2c-byte reference holders ---- */
typedef struct Cx25cE2c { u8 pad[0x2c]; } Cx25cE2c;
typedef struct Cx25cV2c { u32 p0; Cx25cE2c *data; u32 count; u32 cap; } Cx25cV2c;
extern void ts4_ref_holder_dtor_881D7008(Cx25cE2c *e);
extern void fn_881992A8(u32 z, void *p);

/* 0x8820AC88: destroy every element, then free the buffer */
void ts4_v2c_destroy_8820AC88(Cx25cV2c *v)
{
    Cx25cE2c *p = v->data;
    if (p != 0) {
        u32 n = v->count;
        while (n != 0) {
            Cx25cE2c *e = p;
            n--;
            p++;
            ts4_ref_holder_dtor_881D7008(e);
        }
        if (v->data != 0) fn_881992A8(0, v->data);
    }
}

extern void ts4_grow_reserve_2c_881DA2C0(Cx25cV2c *v, u32 n);
extern void fn_881DA4D8(Cx25cE2c *p, u32 n);

/* 0x8820B1A0: resize to n elements (destroy extras, initialise new ones, growing first when over capacity) */
void ts4_v2c_resize_8820B1A0(Cx25cV2c *v, u32 n)
{
    if (n == 0) {
        u32 c = v->count;
        Cx25cE2c *p = v->data;
        if (c != 0) {
            do {
                Cx25cE2c *e = p;
                c--;
                p++;
                ts4_ref_holder_dtor_881D7008(e);
            } while (c != 0);
        }
        v->count = 0;
        return;
    }
    if (n <= v->cap) {
        if (v->count < n) {
            fn_881DA4D8(v->data + v->count, n - v->count);
            v->count = n;
        } else {
            if (v->count > n) {
                u32 k = v->count - n;
                Cx25cE2c *p = v->data + n;
                if (k != 0) {
                    do {
                        Cx25cE2c *e = p;
                        k--;
                        p++;
                        ts4_ref_holder_dtor_881D7008(e);
                    } while (k != 0);
                }
            }
            v->count = n;
        }
    } else {
        ts4_grow_reserve_2c_881DA2C0(v, n);
        fn_881DA4D8(v->data + v->count, n - v->count);
        v->count = n;
    }
}

/* ---- string-pointer ranges ---- */
extern u32 fn_881519D0(void);
extern void ts4_string_copy_mgr_8819AFC8(void *dst, void *src, u32 x);

/* 0x881FB7F8: copy-construct [first, last) of string handles into dst, passing each string's size (or the default) along; returns the end of dst */
u32 **ts4_copy_strs_881FB7F8(u32 **first, u32 **last, u32 **dst)
{
    u32 **s;
    if (first != last) {
        s = first;
        do {
            if (dst != 0) {
                int n = ((int *)*s)[-4];
                u32 x = (u32)n;
                if (n == 0) x = fn_881519D0();
                ts4_string_copy_mgr_8819AFC8(dst, s, x);
            }
            s++;
            dst++;
        } while (s != last);
    }
    return dst;
}

/* ---- vector of string handles ---- */
typedef struct Cx25cSv { u32 **begin; u32 **end; } Cx25cSv;
extern void ts4_if_call_seq_u32_off0_8819B0C8(void *dst, void *src);
extern void ts4_call_seq_u32_off0_881A2570(void *p);

static __inline u32 **cx25c_copy(u32 **first, u32 **last, u32 **dst)
{
    int n = last - first;
    for (; n > 0; --n) {
        ts4_if_call_seq_u32_off0_8819B0C8(dst, first);
        ++first;
        ++dst;
    }
    return dst;
}

/* 0x881FB5C8: clear the vector (assign-copy of the empty tail, then destroy what remains) */
void ts4_strvec_clear_881FB5C8(Cx25cSv *v)
{
    u32 **d = cx25c_copy(v->end, v->end, v->begin);
    u32 **p = d;
    u32 **e = v->end;
    if (d != e) {
        do {
            ts4_call_seq_u32_off0_881A2570(p);
            p++;
        } while (p != e);
    }
    v->end = d;
}

/* ---- keyed resolve with a temporary counted holder ---- */
typedef struct Cx25cRcx { const void *vt; long rc; } Cx25cRcx;
typedef struct Cx25cHold { Cx25cRcx *p; } Cx25cHold;
extern void *lbl_88D41FC4;
extern u32 *ts4_if_get_u32_off4_881E9010(Cx25cHold *out, void *g, u32 key);
extern long ts4_if_atomic_interlocked_dec_881876D0(Cx25cRcx *p);
#ifdef _MSC_VER
typedef unsigned int Cx25cUp;
#else
typedef unsigned long Cx25cUp;
#endif
typedef struct Cx25cRes { u8 pad[4]; u8 f4; u8 f5; u8 pad6[2]; u32 f8; u32 fc; } Cx25cRes;

/* 0x88201EB8: look the key up, release the temporary holder, and on success fill in the record (key text, flag, extra word) */
u32 ts4_resolve_88201EB8(Cx25cRes *o, u32 key, u8 flag, u32 extra)
{
    Cx25cHold h;
    o->f8 = *ts4_if_get_u32_off4_881E9010(&h, lbl_88D41FC4, key);
    if (h.p != 0) {
        ts4_if_atomic_interlocked_dec_881876D0(h.p);
        h.p = 0;
    }
    if (o->f8 != 0) {
        o->fc = extra;
        o->f5 = 0;
        ts4_if_call_seq_u32_off0_8819B0C8(o, (void *)(Cx25cUp)key);
        o->f4 = flag;
        return 1;
    }
    return 0;
}

/* ---- name read from a config stream (kind 4 = inline text, otherwise the default text) ---- */
typedef struct Cx25cTmp { u32 w0; u32 w1; int kind; u32 w3; const char *data; u32 w5; u32 w6; u32 w7; } Cx25cTmp;
extern void fn_881F4D38(void *o, void *stream);
extern void fn_88837880(Cx25cTmp *t, void *stream, const char *key);
extern void fn_881B19A0(Cx25cTmp *t);
extern void ts4_loop_call_seq_u8_off0_8819B148(void *dst, const char *s);
extern char lbl_880E9AB0[];
extern char lbl_880E1084[];
extern char lbl_880C1320[];

/* 0x882013C0: read the base record, then the name entry; store its text (or the default) into the name slot */
u32 ts4_read_name_882013C0(void *self, void *stream)
{
    Cx25cTmp t;
    const char *s;
    fn_881F4D38(self, stream);
    fn_88837880(&t, stream, lbl_880E9AB0);
    if (t.kind != 4) {
        fn_881B19A0(&t);
        ts4_loop_call_seq_u8_off0_8819B148((char *)self + 0x24, lbl_880C1320);
    } else {
        s = t.data + 0x18;
        fn_881B19A0(&t);
        ts4_loop_call_seq_u8_off0_8819B148((char *)self + 0x24, s);
    }
    return 1;
}

/* 0x88206BC8: store the config name text (or the default) into the name slot at +0xc, return 1 */
u32 ts4_set_name_from_config_88206BC8(void *self, void *cfg)
{
    Cx25cTmp t;
    const char *s;
    fn_88837880(&t, cfg, lbl_880E1084);
    if (t.kind != 4) {
        fn_881B19A0(&t);
        ts4_loop_call_seq_u8_off0_8819B148((char *)self + 0xc, lbl_880C1320);
    } else {
        s = t.data + 0x18;
        fn_881B19A0(&t);
        ts4_loop_call_seq_u8_off0_8819B148((char *)self + 0xc, s);
    }
    return 1;
}

/* ---- current-object test with a temporary reference ---- */
typedef struct Cx25cSub6c { u8 pad[0x50]; Cx25cRcx *cur; } Cx25cSub6c;
typedef struct Cx25cGlob { u8 pad[0x6c]; Cx25cSub6c *sub; } Cx25cGlob;

/* 0x88200580: take a temporary reference on the current object, compare it with x, release it again */
int ts4_is_current_88200580(Cx25cRcx *x)
{
    Cx25cRcx *p = ((Cx25cGlob *)lbl_88D41FC4)->sub->cur;
    int r;
    if (p != 0) _InterlockedIncrement(&p->rc);
    r = x == p;
    if (p != 0) ts4_if_atomic_interlocked_dec_881876D0(p);
    return r;
}

/* ---- scoped lookup that takes a reference on the found object ---- */
typedef struct Cx25cRcz { const void *vt; long rc; } Cx25cRcz;
typedef struct Cx25cEnt2 { u32 p0; Cx25cRcz *obj; } Cx25cEnt2;
typedef struct Cx25cScope Cx25cScope;
struct Cx25cScope { u8 pad[8]; void *table; u32 pc; Cx25cScope *parent; };
typedef struct Cx25cOut { Cx25cRcz *p; } Cx25cOut;
extern Cx25cEnt2 *ts4_string_table_find_881FBA58(void *table, u32 key, u32 *a, u32 *b, u32 *c);

/* 0x881FB330: look the key up in this scope's table; the hit is returned with an extra reference, a miss optionally retries in the parent scope */
#ifdef _MSC_VER
__declspec(noinline)
#endif
Cx25cOut *ts4_scope_lookup_881FB330(Cx25cOut *out, Cx25cScope *s, u32 key, u8 recurse)
{
    u32 a, b, c;
    Cx25cEnt2 *e = ts4_string_table_find_881FBA58(s->table, key, &c, &b, &a);
    if (e != 0) {
        out->p = e->obj;
        if (out->p != 0) _InterlockedIncrement(&out->p->rc);
        return out;
    }
    if (recurse && (long)s->parent != 0) {
        ts4_scope_lookup_881FB330(out, s->parent, key, 1);
        return out;
    }
    out->p = 0;
    return out;
}
