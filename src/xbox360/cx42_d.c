/* CX42: net/lobby, scheduler, front end helpers (part 4), Swing_DLL.xex 0x8898xxxx-0x8899xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wpointer-to-int-cast"
#endif
#define W(o, off) (*(u32 *)((u8 *)(o) + (off)))
#define B(o, off) (*(u8 *)((u8 *)(o) + (off)))
extern u8 *g_ts4_session_context;

/* interlocked stores of 2 / 1 into the word pointed to by the owner at +0x120 */
extern long _InterlockedExchange(volatile long *value, long v);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedExchange)
#endif
void ts4_cx42_signal_flag2_8899C348(u8 *s, u8 *o)
{
    int flag = W(o, 0x120);
    volatile long v;
    if (flag != 0) { v = 2; _InterlockedExchange((volatile long *)(long)flag, v); }
}
void ts4_cx42_signal_if_set_88994E10(u8 *s, u8 *o)
{
    int *p = (int *)W(o, 0x120);
    volatile long v;
    if (*p != 0) { v = 1; _InterlockedExchange((volatile long *)p, v); }
}
void ts4_cx42_signal_if_set_8899C380(u8 *s, u8 *o)
{
    int flag = W(o, 0x120);
    volatile long v;
    if (*(int *)flag != 0) { v = 1; _InterlockedExchange((volatile long *)(long)flag, v); }
}

typedef struct Svc { void **vt; } Svc;
typedef struct Res { u8 pad[0x34]; float f34; } Res;
typedef Res *(*SvcFn)(Svc *, u32);
extern void *ts4_find_service(u32 id);
int ts4_cx42_scaled_sq_8899C758(int n)
{
    Svc *s = (Svc *)ts4_find_service(0xB303E02C);
    Res *r = ((SvcFn)s->vt[0x4c / 4])(s, 0);
    if (n < 0) return 0;
    return (int)(r->f34 * (float)n * (float)n);
}
extern float __fsqrts(float);
#ifdef _MSC_VER
#pragma intrinsic(__fsqrts)
#endif
int ts4_cx42_scaled_sqrt_8899C7F0(int n)
{
    Svc *s = (Svc *)ts4_find_service(0xB303E02C);
    Res *r = ((SvcFn)s->vt[0x4c / 4])(s, 0);
    int v = (int)__fsqrts((float)n / r->f34);
    return v & (int)(((u32)v >> 31) - 1);
}

extern int fn_884F1128(u32 a, u32 b, void *c, void *d, void *e);
int ts4_cx42_overlapped_88996C90(u8 *o, u8 *m, int *out)
{
    if (W(g_ts4_session_context, 0x1c) != 0 && W(o, 0x4c) != 0 && W(m, 0x14) != 0) {
        int r = fn_884F1128(W(o, 0x4c), W(m, 0x14), m + 0x18, m + 0x38, o + 0x30);
        *out = r;
        return r != 0x3e5 ? -1 : 0;
    }
    return -1;
}

extern u8 *ts4_node_dispatch_8860DCF8(u32 a, u32 sz, u32 c, u32 d);
extern char lbl_880D2A04[];
extern int fn_884F0BC8(u32 a, void *b, u32 c, void *d, u32 e, void *f, void *g);
int ts4_cx42_alloc_overlapped_88996860(u8 *o, u8 *m, int *out)
{
    u32 sz;
    u8 *buf;
    int r;
    if (W(m, 0xab4) != 0) {
        sz = W(m, 0xab4) * 4 + 6;
        buf = ts4_node_dispatch_8860DCF8(W(o, 0xc), sz, 1, 2);
        W(m, 0xdb8) = (u32)buf;
        if (sz != 0) {
            u32 i = sz;
            u8 *p = buf;
            do { *p++ = 0; } while (--i != 0);
        }
        r = fn_884F0BC8(0, lbl_880D2A04, W(m, 0xab4), m + 0xab8, sz, (void *)W(m, 0xdb8), o + 0x30);
        *out = r;
        return r != 0x3e5 ? -1 : 0;
    }
    return -1;
}
