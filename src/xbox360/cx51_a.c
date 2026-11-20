/* CX51: net/lobby, scheduler and front-end helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX51_INL static __forceinline
#else
#define CX51_INL static inline
#endif

/* ---- constructor with a nested zeroed sub-object (dead addi of &o->s) ---- */
typedef struct Cx51V4 { u32 a, b, c, d; } Cx51V4;
typedef struct Cx51V3 { u32 a, b, c; } Cx51V3;
typedef struct Cx51Sub8 { Cx51V4 lo, hi; } Cx51Sub8;
typedef struct Cx51O8 { void *vt; u8 pad[0x50]; Cx51V3 m; Cx51Sub8 s; } Cx51O8;
extern char lbl_880D6A28[];
extern void fn_889296C0(void *);
static __inline void cx51_v4_init(Cx51V4 *v) { v->a = 0; v->b = 0; v->c = 0; v->d = 0; }
static __inline void cx51_v3_init(Cx51V3 *v) { v->a = 0; v->b = 0; v->c = 0; }
static __inline void cx51_sub8_init(Cx51Sub8 *s)
{
    cx51_v4_init(&s->lo);
    cx51_v4_init(&s->hi);
}
/* 0x8892A0E0: construct a 0x80-byte object on top of the 0x54-byte base */
Cx51O8 *ts4_obj80_ctor_8892A0E0(Cx51O8 *o)
{
    fn_889296C0(o);
    cx51_v3_init(&o->m);
    o->vt = lbl_880D6A28;
    cx51_sub8_init(&o->s);
    return o;
}

/* ---- notify the global front-end object ---- */
typedef struct Cx51Ob { void **vt; } Cx51Ob;
typedef struct Cx51G { u8 pad[0x224]; Cx51Ob *o224; } Cx51G;
extern Cx51G *lbl_88D45B1C;
extern void fn_8892EB28(void *, u32);
extern u32 ts4_if_call_seq_u32_off8_8892ED88(void *, u32);
typedef u32 (*Cx51GFn)(Cx51Ob *, u32);
/* 0x8892F1C0: reset the sub-object at +0x10, then pass its status to the global object's slot 0x44 */
u32 ts4_reset_and_notify_8892F1C0(u8 *self)
{
    u8 *p = self + 0x10;
    u32 res = 0;
    u32 r;
    long g;
    fn_8892EB28(p, 0);
    r = ts4_if_call_seq_u32_off8_8892ED88(p, 0);
    g = (long)lbl_88D45B1C->o224;
    if (g) {
        Cx51Ob *q = (Cx51Ob *)g;
        res = ((Cx51GFn)q->vt[17])(q, r);
    }
    return res;
}

/* ---- UDP endpoint record ---- */
typedef struct Cx51Ep { void *vt; u16 kind; u16 port; u32 addr; } Cx51Ep;
extern char lbl_880D5E90[];
extern u32 ts4_tailcall_NetDll_inet_addr_884F0388(const char *s);
/* 0x88932418: IPv4 endpoint from a dotted string (0 when null or invalid) and a port */
Cx51Ep *ts4_endpoint_init_88932418(Cx51Ep *o, u16 port, const char *ip)
{
    u32 a, t;
    o->kind = 2;
    o->vt = lbl_880D5E90;
    if (ip == 0)
        a = 0;
    else {
        t = ts4_tailcall_NetDll_inet_addr_884F0388(ip);
        a = (t != 0xFFFFFFFF) ? t : 0;
    }
    o->addr = a;
    o->port = port;
    return o;
}

/* ---- object with an owned pointer vector at +0x444 ---- */
typedef struct Cx51PV { void *first; void *last; u32 alloc; } Cx51PV;
extern char lbl_880D5CBC[];
extern void *lbl_88D45B38;
extern void ts4_object_finalize(void *);
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *node, u32 a);
extern void fn_885651F8(void *node);
extern u32 ts4_if_get_u32_off42c_88931688(void *o);
/* 0x8893BDE0: destroy the object: finalize the member at +0x444, free its storage, then run the base teardown */
u32 ts4_flagged_object_dtor_8893BDE0(u8 *o)
{
    Cx51PV *v = (Cx51PV *)(o + 0x444);
    *(char **)o = lbl_880D5CBC;
    ts4_object_finalize(v);
    if (v->first != 0) {
        if (lbl_88D45B38 != 0)
            ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, v->first, v->alloc);
        else
            fn_885651F8(v->first);
    }
    return ts4_if_get_u32_off42c_88931688(o);
}

/* ---- wide-string helpers ---- */
extern u32 ts4_loop_get_u16_off0_885647A8(const u16 *s);
extern void *ts4_memset(void *d, int v, u32 n);
#ifdef _MSC_VER
#pragma function(memcpy)
extern void *memcpy(void *d, const void *s, u32 n);
#else
#include <string.h>
#endif
/* 0x88930D20: overwrite a wide string with asterisks of the same length (up to 8) */
void ts4_wstr_mask_88930D20(u16 *dst)
{
    u16 mask[9] = { 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0 };
    u32 n, m;
    n = ts4_loop_get_u16_off0_885647A8(mask) * 2;
    m = ts4_loop_get_u16_off0_885647A8(dst) * 2;
    ts4_memset(dst, 0, m);
    memcpy(dst, mask, n);
}

/* ---- bit-stream writers ---- */
typedef struct Cx51BS { void **vt; u32 pos; u32 lim; int err; } Cx51BS;
extern u8 fn_88933EF8(Cx51BS *b, u32 n);
Cx51BS *ts4_bits_write_bits_889393C0(Cx51BS *b, u32 v, u32 n);
extern void fn_88936AF0(Cx51BS *b, u32 neg);
/* 0x88939548: write a signed value as magnitude then sign flag using n bits, or flag an error when n is zero */
Cx51BS *ts4_bits_write_signed_88939548(Cx51BS *b, int v, u32 p)
{
    if (p) {
        if (fn_88933EF8(b, p)) {
            u32 neg;
            int a;
            if (v < 0) {
                neg = 1;
                a = -v;
            } else {
                neg = 0;
                a = v;
            }
            ts4_bits_write_bits_889393C0(b, a, p);
            fn_88936AF0(b, neg);
        }
    } else if (b->err == 0)
        b->err = 3;
    return b;
}

extern void fn_88938DF8(Cx51BS *b, u8 *out);
/* 0x88939840: read one byte from the bit stream when 8 bits remain, else flag an overflow */
Cx51BS *ts4_bits_read_u8_88939840(Cx51BS *b, u8 *out)
{
    u32 c = b->pos >= b->lim + 8;
    if ((u8)c == 0) {
        if (b->err == 0)
            b->err = 2;
    }
    if ((u8)c != 0)
        fn_88938DF8(b, out);
    return b;
}
/* 0x88939738: read a big-endian u16 from the bit stream when 16 bits remain, else flag an overflow */
Cx51BS *ts4_bits_read_u16_88939738(Cx51BS *b, u16 *out)
{
    u8 hi, lo;
    u32 c = b->pos >= b->lim + 16;
    if ((u8)c == 0) {
        if (b->err == 0)
            b->err = 2;
    }
    if ((u8)c != 0) {
        fn_88938DF8(b, &hi);
        fn_88938DF8(b, &lo);
        *out = (u16)((hi << 8) | lo);
    }
    return b;
}

extern void fn_88938E98(Cx51BS *b, u8 v);
/* 0x889393C0: write the low n bits of a value (whole bytes first, then single bits), or flag an error when n is zero */
#ifdef _MSC_VER
__declspec(noinline)
#endif
Cx51BS *ts4_bits_write_bits_889393C0(Cx51BS *b, u32 v, u32 n)
{
    if (n) {
        if (fn_88933EF8(b, n)) {
            u32 i = 0;
            if (n >= 8) {
                do {
                    fn_88938E98(b, (u8)(v >> i));
                    i += 8;
                } while (n - i >= 8);
            }
            if (i < n) {
                do {
                    fn_88936AF0(b, (v >> i) & 1);
                    i++;
                } while (i < n);
            }
        }
    } else if (b->err == 0)
        b->err = 3;
    return b;
}

/* ---- messages from the session pool ---- */
typedef struct Cx51Msg {
    void **vt;
    u8 pad[0x414 - 4];
    int ref;
    u32 w418;
    u8 b41c, b41d;
    u8 pad2[0x42c - 0x41e];
    u32 w42c;
    u16 h430;
} Cx51Msg;
typedef struct Cx51SessPool { void **vt; u8 pad[8]; void *w0c; } Cx51SessPool;
extern Cx51SessPool *g_ts4_session_context;
extern Cx51Msg *fn_8816E6C0(void *pool);
extern void fn_88933C58(void *self, Cx51Msg *m);
typedef void (*Cx51DelFn)(Cx51Msg *, int);
/* 0x889387F0: allocate a message from the session pool, fill it, dispatch it and drop the reference */
void ts4_post_message_889387F0(void *self, u32 a, u32 b, u16 *c)
{
    Cx51Msg *m = fn_8816E6C0(g_ts4_session_context->w0c);
    m->b41d = 0;
    m->b41c = 1;
    m->w418 = b;
    m->w42c = a;
    m->h430 = *c;
    fn_88933C58(self, m);
    m->ref = m->ref - 1;
    if (m->ref <= 0)
        ((Cx51DelFn)m->vt[0])(m, 1);
}

/* ---- push a session-created child into a pointer vector ---- */
typedef struct Cx51Sess { void **vt; } Cx51Sess;
typedef struct Cx51PtrVec { u32 w0; u32 **last; u32 w8; u32 **cap; } Cx51PtrVec;
typedef u32 *(*Cx51MkFn)(Cx51Sess *);
extern void ts4_vector_grow_append_scalar4_8816DD48(Cx51PtrVec *v, u32 **where, u32 **val);
/* 0x889332B8: use the given child (or create one through slot 0x64 of the session), link it to its parent and append it to the vector at +4 */
u32 *ts4_adopt_child_889332B8(u8 *self, u32 *x)
{
    Cx51PtrVec *v;
    u32 **last;
    u32 *r = x;
    if (r == 0) {
        r = ((Cx51MkFn)((Cx51Sess *)g_ts4_session_context)->vt[25])((Cx51Sess *)g_ts4_session_context);
        x = r;
    }
    *(u8 **)((u8 *)r + 0x68) = self;
    v = (Cx51PtrVec *)(self + 4);
    last = v->last;
    if (last != v->cap) {
        if (last) *last = r;
        v->last = v->last + 1;
    } else
        ts4_vector_grow_append_scalar4_8816DD48(v, last, &x);
    return r;
}
/* 0x88934AC8: use the given child (or create one through slot 0x5c of the session) and append it to the vector at +0x18 */
u32 *ts4_add_child_88934AC8(u8 *self, u32 *x)
{
    Cx51PtrVec *v;
    u32 **last;
    u32 *r = x;
    if (r == 0) {
        r = ((Cx51MkFn)((Cx51Sess *)g_ts4_session_context)->vt[23])((Cx51Sess *)g_ts4_session_context);
        x = r;
    }
    v = (Cx51PtrVec *)(self + 0x18);
    last = v->last;
    if (last != v->cap) {
        if (last) *last = r;
        v->last = v->last + 1;
    } else
        ts4_vector_grow_append_scalar4_8816DD48(v, last, &x);
    return r;
}
