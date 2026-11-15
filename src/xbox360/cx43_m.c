/* CX43 part h: net/lobby helpers, Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Cx43Msg { void **vt; u8 pad[0x414 - 4]; int refs; u8 pad2[0x42c - 0x418]; u8 b42c; } Cx43Msg;
typedef struct Cx43Lsn { void **vt; } Cx43Lsn;
typedef struct Cx43SessCtx { u8 pad[0xc]; void *ctxc; } Cx43SessCtx;
extern Cx43SessCtx *g_ts4_session_context;
typedef void (*Cx43ListenFn)(Cx43Lsn *l, Cx43Msg *m, int a);
typedef void (*Cx43DelFn)(Cx43Msg *m, int flags);

/* 0x889A44C0 */
typedef struct Cx43Cfg40 { u8 pad[0x40]; int w40; } Cx43Cfg40;
typedef struct Cx43Flag { u8 pad[0x1d]; u8 b1d; u8 pad1[0x74 - 0x1e]; u8 b74; } Cx43Flag;
typedef struct Cx43Own { void **vt; u8 pad[0x10]; Cx43Cfg40 *p14; u8 pad1[0xa0 - 0x18]; Cx43Flag *pa0; } Cx43Own;
extern Cx43Msg *ts4_flagged_object_create_88154180(void *ctx);


#ifdef _MSC_VER
#define CX43_INL static __forceinline
#else
#define CX43_INL static inline
#endif
CX43_INL u8 flag_set(Cx43Own *o)
{
    if (o->p14->w40 != 0) {
        if (o->pa0->b1d == 0)
            return 0;
    }
    return 1;
}
void m1(Cx43Own *o)
{
    u8 f = flag_set(o);
    if (f != 0) {
        Cx43Msg *m = ts4_flagged_object_create_88154180(g_ts4_session_context->ctxc);
        m->b42c = 0;
        ((Cx43ListenFn)o->vt[5])((Cx43Lsn *)o, m, 0);
        if (--m->refs <= 0)
            ((Cx43DelFn)m->vt[0])(m, 1);
    }
    o->pa0->b74 = 1;
}
void ts4_send_flag_message_889A44C0(Cx43Own *o)
{
    u8 f = flag_set(o);
    if (f != 0) {
        Cx43Msg *m = ts4_flagged_object_create_88154180(g_ts4_session_context->ctxc);
        m->b42c = 0;
        ((Cx43ListenFn)o->vt[5])((Cx43Lsn *)o, m, 0);
        if (--m->refs <= 0)
            ((Cx43DelFn)m->vt[0])(m, 1);
    }
    o->pa0->b74 = 1;
}

/* 0x889A4590 */
typedef struct Cx43Svc858 { u8 pad[0x858]; u32 w858; u32 w85c; } Cx43Svc858;
typedef struct Cx43Sess858 { u8 pad[0xc]; void *ctxc; u8 pad1[0x3c - 0x10]; Cx43Svc858 *p3c; } Cx43Sess858;
extern u32 ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);
typedef struct Cx43OwnT { void **vt; u8 pad[0x10]; Cx43Cfg40 *p14; u8 pad1[0x9c - 0x18]; u32 w9c; Cx43Flag *pa0; } Cx43OwnT;
#if 0 /* near miss, not byte-identical */
void ts4_reset_time_889A4590(Cx43OwnT *o)
{
    Cx43Sess858 *c;
    Cx43Svc858 *t;
    u32 z = 0;
    u32 f;
    o->w9c = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    c = (Cx43Sess858 *)g_ts4_session_context;
    t = c->p3c;
    t->w858 = z;
    t->w85c = z;
    f = z;
    if (o->p14->w40 == 0 || o->pa0->b1d != 0)
        f = 1;
    if ((u8)f != 0) {
        Cx43Msg *m = ts4_flagged_object_create_88154180(c->ctxc);
        m->b42c = 1;
        ((Cx43ListenFn)o->vt[5])((Cx43Lsn *)o, m, 0);
        if (--m->refs <= 0)
            ((Cx43DelFn)m->vt[0])(m, 1);
    }
}
#endif
