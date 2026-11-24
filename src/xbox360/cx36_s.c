/* CX36: net message forwarding, Swing_DLL.xex 0x88937968. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Cx36Msg { void **vt; u8 pad[0x414 - 4]; int refs; u8 pad2[0x42c - 0x418]; u32 value; } Cx36Msg;
typedef struct Cx36SessCtx { u8 pad[0xc]; void *ctxc; } Cx36SessCtx;
extern Cx36SessCtx *g_ts4_session_context;
extern Cx36Msg *ts4_construct_vtable_obj_8816E998(void *ctx);
extern void fn_88933C58(void *p, void *arg);
typedef void (*Cx36DelFn)(Cx36Msg *m, int flags);
typedef struct Cx36Fo { void **vt; } Cx36Fo;
typedef struct Cx36Src { u8 pad[0x42c]; u32 w42c; } Cx36Src;
typedef struct Cx36Han { u8 pad[0x1c]; void *h1c; } Cx36Han;
typedef void (*Cx36Slot14)(Cx36Fo *o, Cx36Han *h, Cx36Src *s);

/* 0x88937968: copy the source value into a message, hand it to the handler, release it, then call slot 14 */
void ts4_forward_value_message_88937968(Cx36Fo *o, Cx36Src *s, Cx36Han *h)
{
    Cx36Msg *m = ts4_construct_vtable_obj_8816E998(g_ts4_session_context->ctxc);
    m->value = s->w42c;
    if (h->h1c)
        fn_88933C58(h->h1c, m);
    if (--m->refs <= 0)
        ((Cx36DelFn)m->vt[0])(m, 1);
    ((Cx36Slot14)o->vt[14])(o, h, s);
}

/* 0x88939910: append another stream's bits: whole bytes first, then the leftover bits one at a time */
typedef struct Cx36BS { void **vt; u32 bits; } Cx36BS;
typedef u8 *(*Cx36DataFn)(Cx36BS *b);
extern u8 fn_88933EF8(Cx36BS *dst, u32 n);
extern void fn_88939040(Cx36BS *dst, const u8 *data, u32 n);
extern void fn_88936AF0(Cx36BS *dst, u8 bit);
#if 0 /* near miss, not byte-identical */
void ts4_bits_append_stream_88939910(Cx36BS *dst, Cx36BS *src)
{
    if (fn_88933EF8(dst, src->bits)) {
        u8 *data = ((Cx36DataFn)src->vt[1])(src);
        u32 n = src->bits >> 3;
        u32 rem;
        if (n)
            fn_88939040(dst, data, n);
        rem = src->bits & 7;
        if (rem) {
            u8 last = data[n];
            n = 0;
            do {
                fn_88936AF0(dst, (last >> n) & 1);
                n++;
            } while (n < rem);
        }
    }
}
#endif
