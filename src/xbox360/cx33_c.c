/* CX33: net/lobby message dispatch helpers (Swing_DLL.xex 0x8891xxxx). Each builds a ref-counted message object,
   hands it to a listener through vtable slot 5 and releases it. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Cx33Msg Cx33Msg;
typedef struct Cx33Lsn Cx33Lsn;
struct Cx33Msg {
    void **vt;
    u8 pad[0x414 - 4];
    int refs;           /* 0x414 */
    u8 pad2[0x42c - 0x418];
    int value;          /* 0x42c */
};
struct Cx33Lsn { void **vt; };
typedef struct Cx33Flag { u8 pad[0x38]; u8 b38; } Cx33Flag;

extern Cx33Msg *ts4_construct_vtable_obj_88172550(void *ctx);
extern Cx33Msg *ts4_construct_vtable_obj_88172CA0(void *ctx);

typedef void (*Cx33ListenFn)(Cx33Lsn *l, Cx33Msg *m, int a);
typedef void (*Cx33DelFn)(Cx33Msg *m, int flags);

typedef struct Cx33SessCtx { u8 pad[0x1c]; Cx33Lsn *listener; } Cx33SessCtx;
extern Cx33SessCtx *g_ts4_session_context;

typedef struct Cx33Owner { u8 pad0[4]; void *ctx4; } Cx33Owner;

/* 0x8891A4E8: send a value message to the session listener */
void ts4_send_value_message_8891A4E8(Cx33Owner *o, int value)
{
    Cx33Lsn *l = g_ts4_session_context->listener;
    if (l) {
        Cx33Msg *m = ts4_construct_vtable_obj_88172550(o->ctx4);
        m->value = value;
        ((Cx33ListenFn)l->vt[5])(l, m, 0);
        if (--m->refs <= 0)
            ((Cx33DelFn)m->vt[0])(m, 1);
    }
}

typedef struct Cx33Pump2 {
    u8 pad0[8];
    u32 w8;
    u32 wc;
    u8 pad10[4];
    void *p14;
    u32 w18;
    u8 b1c;
    u8 pad1d[3];
    Cx33Flag *p20;
    Cx33Lsn *p24;
} Cx33Pump2;

/* 0x88919028: send a message to the listener, flag the owner, and reset the pump counters */
void ts4_pump_flush_88919028(Cx33Pump2 *p)
{
    Cx33Msg *m = ts4_construct_vtable_obj_88172CA0(p->p14);
    ((Cx33ListenFn)p->p24->vt[5])(p->p24, m, 0);
    p->p20->b38 = 1;
    if (--m->refs <= 0)
        ((Cx33DelFn)m->vt[0])(m, 1);
    p->wc = 0;
    p->w8 = 0;
    p->w18 = 0;
    p->b1c = 0;
}
