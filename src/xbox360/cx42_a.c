/* CX42: net/lobby, scheduler, front end helpers, Swing_DLL.xex 0x8898xxxx-0x8899xxxx. */
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
#define H(o, off) (*(u16 *)((u8 *)(o) + (off)))
extern u8 *g_ts4_session_context;

/* 0x8899D3B0: is the word reached through two self-relative hops in the session block non-zero */
u32 ts4_cx42_ptr_nz_8899D3B0(void)
{
    u8 *a = (u8 *)W(g_ts4_session_context, 0x68) + 0x220;
    u8 *b = a + W(a, 0);
    u8 *c = b + W(b, 0);
    return W(c, 0) != 0;
}

/* 0x8899F8F0 */
u32 ts4_cx42_eq_8899F8F0(void)
{
    int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0;
    u8 *g = (u8 *)g_ts4_session_context;
    u8 *a = (u8 *)W(g, 0x68) + 0x220;
    u8 *b = (u8 *)W(g, 0x6c);
    u8 *d = a + W(a, 0);
    u8 *e = d + W(d, 0);
    (void)op1_pad0; (void)op1_pad1; (void)op1_pad2; (void)op1_pad3;
    return W(b, 0xd8) == (W(e, 0) != 0);
}

/* 0x8899C870: entry's word at +0x1c differs from the matching slot of the owner */
u32 ts4_cx42_same_8899C870(u8 *o, int *idx)
{
    u8 *q = (u8 *)W(o, 0x2c) + 0xe0;
    u8 *e = q + W(q, 0) + *idx * 0x6c;
    return (W(o, 0x88 + *idx * 4) - W(e, 0x1c)) != 0;
}

/* 0x8899F930 / 0x8899C5F8: per-entry (stride 0xd8) store loops */
void ts4_cx42_setall_8899F930(u8 *o, u32 v)
{
    u8 *t = (u8 *)W(o, 0xac);
    u32 i;
    for (i = 0; i < W(t, 4); i++) W(t + W(t, 0) + i * 0xd8, 0xcc) = v;
}
void ts4_cx42_clrall_8899C5F8(u8 *o)
{
    u8 *t = (u8 *)W(o, 0xac);
    u32 i;
    for (i = 0; i < W(t, 4); i++) B(t + W(t, 0) + i * 0xd8, 0xd2) = 0;
}

extern void ts4_store_fields_8857A960(void *p);
void ts4_cx42_init_889955F0(u8 *o)
{
    u32 *p = (u32 *)(o + 0x30);
    int i;
    ts4_store_fields_8857A960(p);
    for (i = 0; i < 7; i++) p[i] = 0;
}

extern void fn_88152340(void *p);
extern void fn_881522C8(void *p);
extern int ts4_if_get_u32_lbl_88C32048_8857A1E0(int h);
extern void ts4_registry_dispatch_888860A0(u32 h);
void ts4_runtime_process_record_family_98000(u8 *o)
{
    fn_88152340(o + 0x1c);
    if ((int)W(o, 0x620) != -1) { ts4_if_get_u32_lbl_88C32048_8857A1E0(W(o, 0x620)); W(o, 0x620) = -1; }
}
void ts4_runtime_process_record_family_98048(u8 *o)
{
    fn_88152340(o + 0x20);
    if ((int)W(o, 0x624) != -1) { ts4_if_get_u32_lbl_88C32048_8857A1E0(W(o, 0x624)); W(o, 0x624) = -1; }
}
void ts4_runtime_process_record_family_98090(u8 *o)
{
    fn_881522C8(o + 0x1c);
    if ((int)W(o, 0x328) != 0) { ts4_registry_dispatch_888860A0(W(o, 0x328)); W(o, 0x328) = 0; }
}

u8 *ts4_cx42_findw_8899C8B0(u8 *o, u32 key)
{
    u8 *t = (u8 *)W(o, 0xb8);
    u32 i;
    for (i = 0; i < W(t, 4); i++) {
        u8 *e = t + W(t, 0) + i * 0x14;
        if (W(e, 0xc) == key) return e;
    }
    return 0;
}

extern int fn_8857A228(int a, void *b, void *c);
int ts4_cx42_a_88995490(u8 *o, u8 *m)
{
    int r;
    W(m, 0x1c) = W(m, 0x18);
    W(m, 0x20) = W(m, 0x14);
    r = fn_8857A228(1, m + 0x1c, o + 0x30);
    return r != 0x3e5 ? -1 : 0;
}
void ts4_cx42_d_8899C668(u8 *o)
{
    u8 *t = (u8 *)W(o, 0x1c) + 0x40;
    u32 i;
    W(t, 0x10) = 0;
    for (i = 0; i < W(t, 4); i++) W(t + W(t, 0) + i * 0x50, 4) = 0;
}
u32 ts4_cx42_i_8899CB48(u8 *o, u32 *key)
{
    u8 *t = (u8 *)W(o, 0x2c) + 0x94;
    int i;
    for (i = 0; i < (int)W(t, 4); i++) {
        u8 *e = t + W(t, 0) + i * 8;
        if (W(e, 4) == *key) return (u8)W(e, 0);
    }
    return 0;
}
extern u32 fn_884F0530(u32 a, void *b);
extern void fn_8899AFD0(void *self, u32 a, void *b);
void ts4_cx42_g_8899B6B8(u8 *o, u8 *m)
{
    struct { u32 a[5]; u32 b[16]; } l;
    if (fn_884F0530(W(m, 0), l.a) == 0) fn_8899AFD0(o, W(m, 0), l.b);
}
u8 *ts4_cx42_j_8899C498(u8 *o, u32 *key)
{
    u8 *t = (u8 *)W(o, 0xc8);
    if (t != 0) {
        u32 n = W(t, 4);
        u32 i = 0;
        if (n != 0) {
            for (; i < n; i++) {
                u8 *e = t + W(t, 0) + i * 0x2c;
                if (W(e, 0x28) == *key) return e;
            }
        }
    }
    return 0;
}
