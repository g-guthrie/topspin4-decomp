/* CX42: net/lobby, scheduler, front end helpers (part 3), Swing_DLL.xex 0x8899xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-macros"
#endif
#define W(o, off) (*(u32 *)((u8 *)(o) + (off)))
#define B(o, off) (*(u8 *)((u8 *)(o) + (off)))
extern u8 *g_ts4_session_context;
#ifdef _MSC_VER
#pragma function(memcpy)
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
void ts4_cx42_copy_block_8899DC40(u8 *o, u32 *src)
{
    u8 *t = (u8 *)W(o, 0x10);
    if (t != 0) {
        u8 *d = t + W(t, 0) + W(o, 8) * 0x9a0;
        memcpy(d + 0x9c, (void *)*src, 0x800);
        B(d, 0x99c) = 1;
        W(o, 8) = W(o, 8) + 1;
    }
}
extern int ts4_overlapped_status_8857A878(void *p);
u32 ts4_cx42_poll_88995638(u8 *o, u32 unused, int *out)
{
    u32 *p = (u32 *)(o + 0x30);
    int i;
    if (p[0] != 0x3e5) {
        int r = ts4_overlapped_status_8857A878(p);
        if (r != 0) *out = r;
        for (i = 0; i < 7; i++) p[i] = 0;
        return 1;
    }
    return 0;
}
extern int fn_884F11D8(u32 a, u32 b, void *c, void *d);
int ts4_cx42_overlapped_88996C00(u8 *o, u8 *m, int *out)
{
    if (W(m, 0x14) != 0 && W(g_ts4_session_context, 0x1c) != 0 && W(o, 0x4c) != 0) {
        int r = fn_884F11D8(W(o, 0x4c), W(m, 0x14), m + 0x18, o + 0x30);
        *out = r;
        return r != 0x3e5 ? -1 : 0;
    }
    return -1;
}
