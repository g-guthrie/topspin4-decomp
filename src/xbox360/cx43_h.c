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
typedef struct Cx43Flag { u8 pad[0x1d]; u8 b1d; } Cx43Flag;
typedef struct Cx43Own { void **vt; u8 pad[0x10]; Cx43Cfg40 *p14; u8 pad1[0xa0 - 0x18]; Cx43Flag *pa0; } Cx43Own;
extern Cx43Msg *ts4_flagged_object_create_88154180(void *ctx);


#ifdef _MSC_VER
#define CX43_INL static __forceinline
#else
#define CX43_INL static inline
#endif
#if 0 /* near miss, not byte-identical */
CX43_INL u8 flag_set(Cx43Own *o)
{
    if (o->p14->w40 == 0)
        return 1;
    if (o->pa0->b1d != 0)
        return 1;
    return 0;
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
}
#endif

/* 0x889B59A0 */
typedef struct Cx43W24 { u8 pad[0x24]; u32 w24; } Cx43W24;
typedef struct Cx43W48 { u8 pad[0x48]; u32 w48; } Cx43W48;
typedef struct Cx43Lob { u8 pad[0x2c]; Cx43W48 *p2c; u8 pad1[0xb8 - 0x30]; Cx43W24 *pb8; } Cx43Lob;
typedef struct Cx43Lob2 { u8 pad[0x2c]; u8 *p2c; } Cx43Lob2;
extern void fn_889A3540(void *self, void *a, u32 f);
extern void fn_889ABC78(void *self, void *a, u32 f);
extern void fn_889B4B48(void *self, u32 a, u32 b, u32 c);
void ts4_online_forfeit_in_lobby(Cx43Lob *self, void *a)
{
    if ((long)self->pb8 != 0 && self->pb8->w24 == self->p2c->w48) {
        fn_889A3540(self, a, 1);
        fn_889ABC78(self, a, 1);
        fn_889B4B48(self, 0, 1, 0);
    }
    ((Cx43Lob2 *)self)->p2c[0x44a] = 0;
}

/* 0x889B1A58 */
typedef struct Cx43TS { u8 pad[0xa4]; void *pa4; u8 pad1[0xb0 - 0xa8]; u32 wb0; u8 pad2[8]; u32 wbc; u8 pad3[0x110 - 0xc0]; u32 w110; } Cx43TS;
extern u8 fn_889B5A30(void *self, u32 a, u32 *p, u32 b, u32 c);
extern u32 ts4_if_call_seq_fn_889BD910_889BFAB8(void *o, u32 *p);
u32 ts4_title_server_logout(Cx43TS *self, u32 v)
{
    u32 a = 0;
    self->wbc = v;
    self->w110 = 0;
    if (fn_889B5A30(self, 1, &a, 0, 0) == 0) {
        u32 b = self->wb0;
        return ts4_if_call_seq_fn_889BD910_889BFAB8(self->pa4, &b);
    }
    return 0;
}
