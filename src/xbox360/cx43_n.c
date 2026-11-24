/* CX43 part n: Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Cx43Msg { void **vt; u8 pad[0x414 - 4]; int refs; } Cx43Msg;
typedef struct Cx43Lsn { void **vt; } Cx43Lsn;
typedef struct Cx43Sv { u8 pad[0x261]; u8 b261; u8 pad1[2]; u32 w264; u32 w268; u8 pad2[0x2d0 - 0x26c]; u32 w2d0; } Cx43Sv;
typedef struct Cx43SessCtx { u8 pad[0xc]; void *ctxc; u8 pad1[0x3c - 0x10]; Cx43Sv *p3c; } Cx43SessCtx;
extern Cx43SessCtx *g_ts4_session_context;
typedef void (*Cx43ListenFn)(Cx43Lsn *l, Cx43Msg *m, int a);
typedef void (*Cx43DelFn)(Cx43Msg *m, int flags);

/* 0x889A4970 */
extern Cx43Msg *ts4_flagged_object_create_88154018(void *ctx);
#if 0 /* near miss, not byte-identical */
void ts4_send_mode_message_889A4970(Cx43Lsn *o)
{
    Cx43Msg *m = ts4_flagged_object_create_88154018(g_ts4_session_context->ctxc);
    Cx43ListenFn fn;
    Cx43Sv *t;
    if (g_ts4_session_context->p3c->w2d0 == 0x7235DA0A)
        fn = (Cx43ListenFn)o->vt[5];
    else
        fn = (Cx43ListenFn)o->vt[4];
    fn(o, m, 0);
    if (--m->refs <= 0)
        ((Cx43DelFn)m->vt[0])(m, 1);
    t = g_ts4_session_context->p3c;
    t->w264 = 0xA0BDE62E;
    t->w268 = 1;
    t->b261 = 1;
}
#endif

/* 0x889B2BB0 */
typedef struct Cx43Arg { u32 n; void *p; } Cx43Arg;
typedef struct Cx43Wd4 { u8 pad[0x430]; u32 w430; } Cx43Wd4;
typedef struct Cx43Q { u8 pad[0xa4]; void *pa4; u8 pad1[0xd4 - 0xa8]; Cx43Wd4 *pd4; } Cx43Q;
typedef struct Cx43Pk { u32 w0; u32 w4; u16 h8; u16 ha; u32 wc; } Cx43Pk;
extern u8 fn_889B5A30(void *self, u32 a, u32 *p, u32 b, u32 c);
extern void ts4_memset(void *p, u32 v, u32 n);
extern void fn_889C0298(void *o, void *p);
#if 0 /* near miss, not byte-identical */
u32 ts4_query_list_889B2BB0(Cx43Q *self, u32 *pos, u32 *key)
{
    u32 k = *key;
    if (fn_889B5A30(self, 0xb, &k, (u32)pos, 8) == 0) {
        Cx43Pk pk;
        Cx43Arg arg;
        u32 w;
        ts4_memset(&pk, 0, 0x10);
        w = self->pd4->w430;
        arg.n = 0x12;
        arg.p = &pk;
        pk.ha = (u16)pos[1];
        pk.h8 = (u16)pos[0];
        pk.w4 = *key;
        pk.wc = 1;
        pk.w0 = w;
        fn_889C0298(self->pa4, &arg);
    }
    return 1;
}
#endif

/* 0x889B39A0 */
typedef struct Cx43Sv210 { u8 pad[0x210]; u32 w210; } Cx43Sv210;
typedef struct Cx43Sess210 { u8 pad[0x3c]; Cx43Sv210 *p3c; } Cx43Sess210;
typedef struct Cx43Wd8 { u8 pad[8]; u32 w8; } Cx43Wd8;
typedef struct Cx43Q2 { u8 pad[0xa0]; int wa0; void *pa4; u8 pad1[0xd8 - 0xa8]; Cx43Wd8 *pd8; } Cx43Q2;
void ts4_title_server_request_patch(Cx43Q2 *self, int mode)
{
    int m = mode;
    if (fn_889B5A30(self, 2, (u32 *)&m, 0, 0) == 0) {
        u32 buf;
        Cx43Arg arg;
        ts4_memset(&buf, 0, 4);
        arg.p = &buf;
        arg.n = 0xe;
        fn_889C0298(self->pa4, &arg);
        self->wa0 = mode;
        if (mode == 1) {
            ((Cx43Sess210 *)g_ts4_session_context)->p3c->w210 = 0xBE270439;
        } else if (mode == 2) {
            if ((long)self->pd8 != 0)
                self->pd8->w8 = 0xBE270439;
        }
    }
}

/* 0x889B31B8 */
typedef struct Cx43Pk3 { u32 w0; u32 w4; u16 h8; u16 ha; } Cx43Pk3;
typedef struct Cx43Q3 { u8 pad[0xa4]; void *pa4; u8 pad1[0xb0 - 0xa8]; u32 wb0; u8 pad2[4]; u32 wb8; u8 pad3[0xc4 - 0xbc]; int wc4; u8 pad4[0xd8 - 0xc8]; u8 *pd8; u8 *pdc; u8 pad5[4]; u8 *pe4; } Cx43Q3;
extern u8 *fn_8899DFC8(u32 key);
#if 0 /* near miss, not byte-identical */
void ts4_query_round_info_889B31B8(Cx43Q3 *self, u32 key)
{
    self->wb8 = 0;
    *self->pe4 = 0;
    self->pd8[0x448] = 0;
    self->pdc[8] = 0;
    if (self->wc4 != 0) {
        u32 k = key;
        if (fn_889B5A30(self, 6, &k, 0, 0) == 0) {
            Cx43Pk3 pk;
            Cx43Arg arg;
            ts4_memset(&pk, 0, 0xc);
            if (key == 0x31EFB504) {
                pk.w0 = 0x582B3086;
                pk.h8 = 0;
                pk.ha = 1;
            } else {
                u8 *o = fn_8899DFC8(key);
                if (o != 0) {
                    *(volatile u32 *)&pk.w0 = key;
                    pk.ha = 0;
                    pk.h8 = (u16)*(u32 *)(o + 0x1c);
                }
            }
            arg.n = 0xd;
            arg.p = &pk;
            pk.w4 = self->wb0;
            fn_889C0298(self->pa4, &arg);
        }
    }
}
#endif

/* 0x889B14A8 */
typedef struct Cx43Pl { u8 pad[0x180]; int w180; } Cx43Pl;
typedef struct Cx43Pls { u8 pad[0x20]; Cx43Pl **first; Cx43Pl **last; } Cx43Pls;
typedef struct Cx43Rec { u32 w0; u8 b4; u8 pad[7]; u32 wc; } Cx43Rec;
typedef struct Cx43Lo { u8 pad[0x48]; u32 w48; u8 pad1[0xa0 - 0x4c]; u8 sub[0xc]; u32 wac; } Cx43Lo;
typedef struct Cx43U { u8 pad[0x2c]; Cx43Lo *p2c; u8 pad1[0xb4 - 0x30]; u32 wb4; int wb8; u8 pad2[0x18c - 0xbc]; Cx43Rec *p18c; } Cx43U;
extern Cx43Pls *lbl_88D459E0;
extern void ts4_if_get_fn_8883F238_88848698(void *o, u32 a);
extern void fn_889254C8(void *o, u32 a);
u32 ts4_online_unload_profile(Cx43U *self)
{
    u32 z = 0;
    Cx43Pl *found = 0;
    Cx43Pl **p;
    Cx43Pl **end = lbl_88D459E0->last;
    for (p = lbl_88D459E0->first; p != end; p++) {
        Cx43Pl *x = *p;
        if (x->w180 == 0) {
            found = x;
            break;
        }
    }
    ts4_if_get_fn_8883F238_88848698(found, 0);
    self->p2c->w48 = z;
    if ((long)self->p18c != 0) {
        Cx43Rec *r = self->p18c;
        r->b4 = (u8)z;
        r->w0 = (u32)-1;
        r->wc = (u32)-1;
    }
    if (self->wb8 != 0)
        self->wb8 = z;
    {
        u8 *sub = self->p2c->sub;
        if (*(u32 *)(sub + 0xc) != 0) {
            fn_889254C8(sub, 1);
            self->wb4 = z;
            return 1;
        }
    }
    return 0;
}

/* 0x889A5118 */
typedef struct Cx43E2 { u8 pad[0x80]; int w80; } Cx43E2;
typedef struct Cx43G2 { u8 pad[4]; Cx43E2 **first; Cx43E2 **last; u8 pad1[0x1c - 0xc]; void *w1c; } Cx43G2;
typedef struct Cx43Lb { u8 pad[0x18]; Cx43G2 **first; Cx43G2 **last; u8 pad1[0xb0 - 0x20]; u32 wb0; } Cx43Lb;
typedef struct Cx43SessC { u8 pad[0xc]; void *ctxc; } Cx43SessC;
extern Cx43Msg *ts4_flagged_object_create_88153BE0(void *ctx);
extern void fn_88933C58(void *h, void *m);
void ts4_lobby_ask_for_character(Cx43Lb *self, int idx)
{
    if (idx > 0 && self->wb0 != (u32)idx) {
        Cx43Msg *m = ts4_flagged_object_create_88153BE0(((Cx43SessC *)g_ts4_session_context)->ctxc);
        Cx43G2 *g = 0;
        Cx43G2 **p;
        Cx43G2 **end = self->last;
        for (p = self->first; p != end; p++) {
            g = *p;
            if (g != 0) {
                Cx43E2 **q;
                Cx43E2 **qend = g->last;
                for (q = g->first; q != qend; q++) {
                    if (idx == (*q)->w80)
                        goto done;
                }
            }
        }
done:
        if (g != 0 && m != 0 && g->w1c != 0)
            fn_88933C58(g->w1c, m);
        if (--m->refs <= 0)
            ((Cx43DelFn)m->vt[0])(m, 1);
    }
}
