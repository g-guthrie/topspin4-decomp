/* CX43 part e: ref-counted message dispatch helpers (Swing_DLL.xex 0x889Axxxx). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Cx43Msg { void **vt; u8 pad[0x414 - 4]; int refs; u8 pad2[0x424 - 0x418]; void *w424; void *w428; u32 w42c; u8 b430; } Cx43Msg;
typedef struct Cx43Lsn { void **vt; } Cx43Lsn;
typedef struct Cx43SessCtx { u8 pad[0xc]; void *ctxc; u8 pad1[0x1c - 0x10]; Cx43Lsn *listener; } Cx43SessCtx;
extern Cx43SessCtx *g_ts4_session_context;
typedef void (*Cx43ListenFn)(Cx43Lsn *l, Cx43Msg *m, int a);
typedef void (*Cx43DelFn)(Cx43Msg *m, int flags);

/* 0x889A4028 */
typedef struct Cx43Own { u8 pad[0xc]; void *ctxc; u8 pad1[0xb8 - 0x10]; u32 wb8; } Cx43Own;
extern Cx43Msg *ts4_flagged_object_create_881544D8(void *ctx);
extern void ts4_session_event_post_8899F588(void);
void ts4_post_event_message_889A4028(Cx43Own *o)
{
    Cx43Lsn *l = g_ts4_session_context->listener;
    if (l) {
        Cx43Msg *m = ts4_flagged_object_create_881544D8(o->ctxc);
        m->w424 = (void *)ts4_session_event_post_8899F588;
        m->w428 = o;
        m->w42c = o->wb8;
        ((Cx43ListenFn)l->vt[4])(l, m, 0);
        if (--m->refs <= 0)
            ((Cx43DelFn)m->vt[0])(m, 1);
    }
}

/* 0x889A55E8 */
typedef struct Cx43Own2 { u8 pad[0x1c]; void *h1c; } Cx43Own2;
extern Cx43Msg *ts4_flagged_object_create_88153B30(void *ctx);
extern void fn_88933C58(void *h, void *m);
void ts4_forward_message_889A55E8(Cx43Own2 *o)
{
    Cx43Msg *m = ts4_flagged_object_create_88153B30(g_ts4_session_context->ctxc);
    if (m != 0 && o->h1c != 0)
        fn_88933C58(o->h1c, m);
    if (--m->refs <= 0)
        ((Cx43DelFn)m->vt[0])(m, 1);
}

/* 0x889A5080 */
typedef struct Cx43Ob { void **vt; } Cx43Ob;
typedef struct Cx43Cfg14 { u8 pad[0x2c]; u8 b2c; } Cx43Cfg14;
typedef struct Cx43Own3 { void **vt; u8 pad[0x10]; Cx43Cfg14 *p14; } Cx43Own3;
extern Cx43Msg *ts4_flagged_object_create_88153D48(void *ctx);
void ts4_send_message_889A5080(Cx43Own3 *o)
{
    if (o->p14->b2c != 0) {
        Cx43Msg *m = ts4_flagged_object_create_88153D48(g_ts4_session_context->ctxc);
        ((Cx43ListenFn)o->vt[4])((Cx43Lsn *)o, m, 0);
        if (--m->refs <= 0)
            ((Cx43DelFn)m->vt[0])(m, 1);
    }
}

/* 0x889A53A8 */
extern Cx43Msg *ts4_create_obj434_88153A70(void *ctx);
void ts4_send_message_889A53A8(Cx43Own3 *o)
{
    Cx43Msg *m = ts4_create_obj434_88153A70(g_ts4_session_context->ctxc);
    m->w42c = (u32)-1;
    m->b430 = 0;
    ((Cx43ListenFn)o->vt[4])((Cx43Lsn *)o, m, 0);
    if (--m->refs <= 0)
        ((Cx43DelFn)m->vt[0])(m, 1);
}
