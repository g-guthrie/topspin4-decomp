/* CX36: net message senders and nested counters, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif

typedef struct Cx36Msg Cx36Msg;
struct Cx36Msg {
    void **vt;
    u8 pad[0x414 - 4];
    int refs;           /* 0x414 */
    u8 pad2[0x42c - 0x418];
    u32 value;          /* 0x42c */
};
typedef struct Cx36Lsn { void **vt; } Cx36Lsn;
typedef void (*Cx36SendFn)(Cx36Lsn *l, Cx36Msg *m, int a);
typedef void (*Cx36DelFn)(Cx36Msg *m, int flags);
typedef struct Cx36SessCtx { u8 pad[0xc]; void *ctxc; } Cx36SessCtx;
extern Cx36SessCtx *g_ts4_session_context;
extern Cx36Msg *ts4_construct_vtable_obj_8816E8E8(void *ctx);
extern Cx36Msg *ts4_construct_vtable_obj_8816EA48(void *ctx);

/* 0x88937A00: send an empty message through slot 4 and release it */
void ts4_send_empty_message_88937A00(Cx36Lsn *l)
{
    Cx36Msg *m = ts4_construct_vtable_obj_8816E8E8(g_ts4_session_context->ctxc);
    ((Cx36SendFn)l->vt[4])(l, m, 0);
    if (--m->refs <= 0)
        ((Cx36DelFn)m->vt[0])(m, 1);
}

/* 0x889378D8: publish the element count of the pending vector and send it */
typedef struct Cx36Cnt28 { u8 pad[0x28]; u32 w28; } Cx36Cnt28;
typedef struct Cx36Pending { void **vt; u8 pad[0x10]; Cx36Cnt28 *p14; u32 *first; u32 *last; } Cx36Pending;
void ts4_send_pending_count_889378D8(Cx36Pending *o)
{
    int n = o->last - o->first;
    Cx36SessCtx *sc = g_ts4_session_context;
    Cx36Msg *m;
    o->p14->w28 = n;
    m = ts4_construct_vtable_obj_8816EA48(sc->ctxc);
    m->value = n;
    ((Cx36SendFn)o->vt[4])((Cx36Lsn *)o, m, 0);
    if (--m->refs <= 0)
        ((Cx36DelFn)m->vt[0])(m, 1);
}

/* 0x88931EF0: count the true slot-6 predicates over a vector of containers */
typedef struct Cx36Pred { void **vt; } Cx36Pred;
typedef struct Cx36Cont { u8 pad[4]; Cx36Pred **first; Cx36Pred **last; } Cx36Cont;
typedef struct Cx36ContVec { u8 pad[0x18]; Cx36Cont **first; Cx36Cont **last; } Cx36ContVec;
typedef u8 (*Cx36PredFn)(Cx36Pred *p);
u32 ts4_count_true_nested_88931EF0(Cx36ContVec *v)
{
    u32 total = 0;
    Cx36Cont **c;
    Cx36Cont **cend = v->last;
    for (c = v->first; c != cend; c++) {
        u32 n = 0;
        Cx36Pred **end = (*c)->last;
        Cx36Pred **p;
        for (p = (*c)->first; p != end; p++) {
            if (((Cx36PredFn)(*p)->vt[6])(*p))
                n++;
        }
        total = n + total;
    }
    return total;
}

/* 0x88933EF8: grow the stream to hold n more bits; true when it already fits or growing succeeds */
typedef struct Cx36Grow { void **vt; u32 bits; } Cx36Grow;
typedef u32 (*Cx36SizeFn)(Cx36Grow *g);
typedef u8 (*Cx36ResizeFn)(Cx36Grow *g, u32 bytes);
#if 0 /* near miss, not byte-identical */
u8 ts4_stream_reserve_bits_88933EF8(Cx36Grow *g, u32 n)
{
    u32 end = g->bits + n;
    u32 r;
    if (end <= ((Cx36SizeFn)g->vt[2])(g) * 8)
        goto yes;
    {
        u8 ok = ((Cx36ResizeFn)g->vt[4])(g, (end + 7) >> 3);
        r = 0;
        if (ok == 0)
            goto done;
    }
yes:
    r = 1;
done:
    return (u8)r;
}
#endif
