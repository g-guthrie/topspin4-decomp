/* CX42: net/lobby, scheduler, front end helpers (part 2), Swing_DLL.xex 0x8899xxxx. */
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
extern u8 *lbl_88D45B1C;

u8 *ts4_cx42_b_8899D750(int key)
{
    u8 *r = 0;
    u8 *t = (u8 *)W(g_ts4_session_context, 0x68) + 0x214;
    int n = W(t, 4);
    int i;
    for (i = 0; i < n; i++) {
        u8 *e = t + W(t, 0) + i * 0x20;
        if ((int)W(e, 0xc) == key) { r = e; break; }
    }
    return r;
}
void ts4_cx42_e_8899CAE0(u32 *out, u8 *o, u32 key)
{
    u8 *t = (u8 *)W(o, 0x2c) + 0x94;
    u32 i;
    for (i = 0; i < W(t, 4); i++) {
        u8 *e = t + W(t, 0) + i * 8;
        if (W(e, 0) == (key & 0xff)) { *out = W(e, 4); return; }
    }
    *out = W(lbl_88D45B1C, 0x27c);
}
extern void fn_88930D20(u32 a);
extern void fn_88930C60(u32 a);
void ts4_cx42_i_889967F0(u8 *unused, u8 *o)
{
    u32 n = *(u16 *)W(o, 0xdb8);
    if (n != 0) {
        u32 k = 0;
        u8 *f = o + 0x118;
        do {
            u8 *tab = (u8 *)*(u32 *)((u8 *)W(o, 0xdb8) + 2);
            if ((int)W(tab, k) != 0) {
                if (B(f, 8) != 0) fn_88930D20(W(f, 0));
                else fn_88930C60(W(f, 0));
            }
            n--; f += 0x110; k += 4;
        } while (n != 0);
    }
}
extern int fn_884F1400(u32 a, void *b);
int ts4_cx42_c_88996B28(u8 *o, u32 a, int *out)
{
    int r;
    if (B(o, 0x2c) == 0) return 1;
    r = fn_884F1400(W(o, 0x4c), o + 0x30);
    *out = r;
    return r != 0x3e5 ? -1 : 0;
}
extern int fn_884F1360(u32 a, u32 b, void *c);
int ts4_cx42_d_88996B90(u8 *o, u32 a, int *out)
{
    int r;
    if (B(o, 0x2c) != 0) return 1;
    r = fn_884F1360(W(o, 0x4c), 0, o + 0x30);
    *out = r;
    return r != 0x3e5 ? -1 : 0;
}
