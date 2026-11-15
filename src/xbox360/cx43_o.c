/* CX43 part o: Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX43_INL static __forceinline
#else
#define CX43_INL static inline
#endif

/* 0x889A3C20 */
typedef struct Cx43Own { void *vt; void *p4; u32 w8; } Cx43Own;
typedef struct Cx43Ref { void *vt; void *obj; } Cx43Ref;
extern void ts4_destroy_owned_object(void *p);
extern void ts4_clear_intrusive_list(void *l);
extern void ts4_obj44_dtor_8890F1E8(void *p);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *o);
extern char lbl_880D2484[];
extern char lbl_880D75FC[];
extern char lbl_880D6B70[];
typedef struct Cx43Big {
    void *vt;
    u8 pad[0x1c - 4];
    void *w1c;
    void *w20;
    u8 pad1[0x3c - 0x24];
    u8 b3c;
    u8 pad2[0xcc - 0x3d];
    void *wcc;
    u8 pad3[0x118 - 0xd0];
    void *w118;
    u8 pad4[0x164 - 0x11c];
    Cx43Ref r164;
    u8 pad5[0x178 - 0x16c];
    Cx43Ref r178;
} Cx43Big;
#if 0 /* near miss, not byte-identical */
void ts4_dtor_889A3C20(Cx43Big *o)
{
    o->vt = lbl_880D2484;
    o->b3c = 0;
    ref_dtor(&o->r178);
    ref_dtor(&o->r164);
    ts4_obj44_dtor_8890F1E8((u8 *)o + 0x120);
    o->w118 = lbl_880D6B70;
    ts4_obj44_dtor_8890F1E8((u8 *)o + 0xd4);
    o->wcc = lbl_880D6B70;
    if (o->w20 != 0)
        ts4_destroy_owned_object(o->w20);
    ts4_clear_intrusive_list((u8 *)o + 0x1c);
    ts4_destroy_owned_object(o->w1c);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(o);
}
#endif

/* 0x889B1320 */
typedef struct Cx43Wr { void **vt; u8 pad[0x42c - 4]; u8 e[0x38]; u8 pad1[0x50c - 0x464]; u32 w50c; } Cx43Wr;
extern u32 lbl_88C6B4AC;
extern void fn_889393C0(void *a, void *b, u32 c);
extern void ts4_if_call_seq_fn_88933EF8_889396A8(void *a, u32 n);
extern void ts4_if_call_seq_u32_off0_889AFEE8(void *e, void *a);
void ts4_write_entries_889B1320(Cx43Wr *self, void *a)
{
    u32 g = lbl_88C6B4AC;
    u32 i;
    u8 *p;
    fn_889393C0(a, ((void *(*)(void *))self->vt[3])(self), g);
    ts4_if_call_seq_fn_88933EF8_889396A8(a, self->w50c);
    i = 0;
    if (self->w50c > 0) {
        p = (u8 *)self + 0x42c;
        do {
            ts4_if_call_seq_u32_off0_889AFEE8(p, a);
            i++;
            p += 0x38;
        } while (i < self->w50c);
    }
}

/* 0x889A4FD0 */
typedef struct Cx43Msg { void **vt; u8 pad[0x414 - 4]; int refs; u8 pad2[0x42c - 0x418]; u32 w42c, w430, w434, w438; } Cx43Msg;
typedef struct Cx43SessC { u8 pad[0xc]; void *ctxc; } Cx43SessC;
extern Cx43SessC *g_ts4_session_context;
typedef struct Cx43Cfg { u8 pad[0x50]; u32 w50, w54, w58, w5c; } Cx43Cfg;
typedef struct Cx43Src { u8 pad[0x14]; Cx43Cfg *p14; } Cx43Src;
typedef struct Cx43Dst { u8 pad[0x1c]; void *w1c; } Cx43Dst;
extern void *ts4_node_dispatch_8860DCF8(void *ctx, u32 a, u32 b, u32 c);
extern Cx43Msg *fn_889A14B0(void *p);
extern void fn_88933C58(void *h, void *m);
typedef void (*Cx43DelFn)(Cx43Msg *m, int flags);
void ts4_send_cfg_message_889A4FD0(Cx43Src *self, Cx43Dst *dst)
{
    void *t = ts4_node_dispatch_8860DCF8(g_ts4_session_context->ctxc, 0x43c, 4, 2);
    Cx43Msg *m;
    Cx43Cfg *c;
    if (t != 0)
        m = fn_889A14B0(t);
    else
        m = 0;
    c = self->p14;
    m->w430 = c->w54;
    m->w434 = c->w58;
    m->w42c = c->w50;
    m->w438 = c->w5c;
    if (dst->w1c != 0)
        fn_88933C58(dst->w1c, m);
    if (--m->refs <= 0)
        ((Cx43DelFn)m->vt[0])(m, 1);
}

/* 0x889B0BB0 */
typedef struct Cx43Cfg2c { u8 pad[0x2c]; u8 b2c; } Cx43Cfg2c;
typedef struct Cx43Lsn2 { void **vt; u8 pad[0x10]; Cx43Cfg2c *p14; } Cx43Lsn2;
typedef struct Cx43Sess1c { u8 pad[0xc]; void *ctxc; u8 pad1[0x1c - 0x10]; Cx43Lsn2 *p1c; } Cx43Sess1c;
typedef struct Cx43Sc { u8 pad[0xec]; u8 e[1]; } Cx43Sc;
typedef struct Cx43Ow { u8 pad[0xc]; void *wc; u8 pad1[0x2c - 0x10]; Cx43Sc *p2c; u8 pad2[0xb8 - 0x30]; int wb8; } Cx43Ow;
extern void *ts4_node_dispatch_8860DCF8(void *ctx, u32 a, u32 b, u32 c);
extern Cx43Msg *fn_889A7570(void *p, u32 a);
extern void fn_881512B8(void *dst, void *src);
typedef void (*Cx43LnFn)(Cx43Lsn2 *l, Cx43Msg *m, int a);
void ts4_send_open_message_889B0BB0(Cx43Ow *self)
{
    Cx43Lsn2 *l = ((Cx43Sess1c *)g_ts4_session_context)->p1c;
    if (l != 0 && self->wb8 != 0) {
        u8 f = l->p14->b2c;
        void *n = ts4_node_dispatch_8860DCF8(self->wc, 0x5b4, 4, 2);
        Cx43Msg *m;
        if (n != 0)
            m = fn_889A7570(n, f == 1);
        else
            m = 0;
        fn_881512B8((u8 *)m + 0x42c, self->p2c->e);
        ((Cx43LnFn)l->vt[5])(l, m, 0);
        if (--m->refs <= 0)
            ((Cx43DelFn)m->vt[0])(m, 1);
    }
}

/* 0x889B0DB8 */
typedef struct Cx43Sv2d0 { u8 pad[0x280]; u32 w280; u8 pad1[0x2c4 - 0x284]; u32 w2c4, w2c8; u32 w2d0; u8 pad2[0x858 - 0x2d4]; u32 w858, w85c; } Cx43Sv2d0;
typedef struct Cx43Sc3c { u8 pad[0x3c]; Cx43Sv2d0 *p3c; } Cx43Sc3c;
typedef struct Cx43Cfg3 { u8 pad[0x2c]; u8 b2c; u8 pad1[0x40 - 0x2d]; int w40; } Cx43Cfg3;
typedef struct Cx43St { u8 pad[8]; u8 *p8; } Cx43St;
typedef struct Cx43Q3 { u8 pad[0x12]; u8 b12; u8 pad0[0x14 - 0x13]; Cx43Cfg3 *p14; u8 pad1[0x28 - 0x18]; int w28; int w2c; u8 pad2[0x5d - 0x30]; u8 b5d; u8 pad3[0x9c - 0x5e]; u32 w9c; } Cx43Q3;
extern void fn_889AC258(u32 a, u32 b);
extern void fn_8899A2F0(void *o);
extern void *fn_88157CD0(void *st, u32 k);
extern void ts4_guarded_update_88151560(void *st, void *o);
extern void *g_ts4_session_state;
#if 0 /* near miss, not byte-identical */
void ts4_set_ready_889B0DB8(Cx43Q3 *self)
{
    Cx43Sv2d0 *c;
    u32 z = 0;
    self->b12 = (u8)z;
    self->b5d = (u8)z;
    c = ((Cx43Sc3c *)g_ts4_session_context)->p3c;
    if ((((u32)self->w2c - (u32)self->w28) & ~3u) == 0) {
        fn_889AC258(c->w2d0, 0x7A2DB365);
        return;
    }
    c->w2d0 = 0x4BAF89F9;
    c->w2c8 = 1;
    c->w2c4 = 1;
    if (self->p14->w40 == 0)
        self->p14->b2c = 1;
    fn_8899A2F0(self->p14);
    {
        Cx43St *s = (Cx43St *)fn_88157CD0(g_ts4_session_state, 0x6F35FE88);
        s->p8[0x1c] = 1;
        s->p8[0x1d] = 1;
        ts4_guarded_update_88151560(g_ts4_session_state, s);
    }
    self->w9c = z;
    ((Cx43Sc3c *)g_ts4_session_context)->p3c->w858 = z;
    ((Cx43Sc3c *)g_ts4_session_context)->p3c->w85c = z;
    c->w280 = 0x5FF4B00E;
}
#endif

/* 0x889B32A8 */
typedef struct Cx43Arg2 { u32 n; void *p; } Cx43Arg2;
typedef struct Cx43Pk4 { u32 w0, w4; u8 pad[0x2c - 8]; u16 h2c; u16 h2e; u8 pad1[0x34 - 0x30]; } Cx43Pk4;
typedef struct Cx43Wd0 { u8 pad[0xd8]; u32 wd8; } Cx43Wd0;
typedef struct Cx43On { u8 pad[0x2c]; u8 *p2c; } Cx43On;
typedef struct Cx43Q4 { u8 pad[0xa4]; void *pa4; u8 pad1[0xb4 - 0xa8]; u32 wb4; u32 wb8; u8 pad2[0xd0 - 0xbc]; Cx43Wd0 *pd0; } Cx43Q4;
extern u8 fn_889B5A30(void *self, u32 a, u32 *p, u32 b, u32 c);
extern void ts4_memset(void *p, u32 v, u32 n);
extern void fn_889BFDA8(void *o, void *p);
extern Cx43On *g_ts4_online_context;
#if 0 /* near miss, not byte-identical */
void ts4_send_status_889B32A8(Cx43Q4 *self)
{
    u32 z = 0;
    u32 a = z;
    if (fn_889B5A30(self, 0xa, &a, 0, 0) == 0) {
        Cx43Pk4 pk;
        Cx43Arg2 arg;
        Cx43Wd0 *d;
        u32 v8;
        u32 v4;
        ts4_memset(&pk, 0, 0x34);
        v8 = self->wb8;
        d = self->pd0;
        v4 = self->wb4;
        arg.p = &pk;
        arg.n = 8;
        pk.w0 = v8;
        pk.w4 = v4;
        pk.h2c = (u16)d->wd8;
        pk.h2e = g_ts4_online_context->p2c[0x244];
        fn_889BFDA8(self->pa4, &arg);
        self->wb8 = z;
    }
}
#endif
