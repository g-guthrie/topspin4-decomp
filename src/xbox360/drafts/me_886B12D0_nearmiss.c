/* 0x886B12D0 near miss (31 off, /Oc plain C; C++ ctor with vt base gives the same). Manager constructor: zeroes
 * fields, registers itself in lbl_88D45AFC, then pool-allocates (ts4_node_dispatch_with_target_88613268 on lbl_88D45B38)
 * two 12-byte vtable objects, a 0x90 object, and objects built by ts4_addr_lbl_880F44EC_8867E7B0, ts4_obj_ctor_886AC130,
 * ts4_call_seq_u32_off28_886A7FC0. Residue: prologue order (target stores vt before f4 and hoists the call args with
 * the zero stores) and the heap global loaded before the li args. Tried: result temp o (105->35), inline pool_alloc,
 * C++ base vt + init lists. */
typedef unsigned int u32; typedef unsigned char u8;
extern const void *lbl_880F4308[];
extern const void *lbl_880F4508[];
extern const void *lbl_880F4518[];
extern const void *lbl_880D6B70[];
extern void *lbl_88D45B38;
extern void *lbl_88D45AFC;
void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
void *ts4_addr_lbl_880F44EC_8867E7B0(void *p);
void *ts4_obj_ctor_886AC130(void *p);
void *ts4_call_seq_u32_off28_886A7FC0(void *p);
typedef struct Small { const void **vt; u32 f4; char _8[4]; } Small;
typedef struct Big { const void **vt; char _4[0x74]; u32 f78; } Big;
typedef struct Mgr {
    const void **vt; u32 f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28; char _2c[4]; u32 f30; char _34[4];
    u32 f38, f3c, f40, f44, f48; void *ctor_obj; char _50[8]; void *list; u32 f5c, f60; char _64[4];
    Small *a, *b; Big *big; void *addr_obj; u32 f78, f7c, f80, f84; char _88[8]; u32 f90;
    u8 b94, b95, b96, b97, b98; char _99[7]; u8 ba0, ba1; char _a2[2]; int fa4; char _a8; u8 ba9;
} Mgr;
Mgr *ts4_mgr_ctor_886B12D0(Mgr *m)
{
    void *p, *o;
    m->vt = lbl_880F4308;
    m->f4 = 0; m->f8 = 0; m->fc = 0; m->f10 = 0; m->f14 = 0; m->f18 = 0;
    m->f30 = 0; m->f28 = 0; m->f24 = 0; m->f20 = 0; m->f1c = 0;
    m->f5c = 0; m->f60 = 0;
    m->f3c = 0; m->f40 = 0; m->f44 = 0; m->f48 = 0;
    m->f84 = 0; m->f38 = 0; m->f78 = 0; m->f7c = 0;
    lbl_88D45AFC = m;
    p = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0xC, 4, 0, 2);
    if (p) { ((Small *)p)->f4 = 0; ((Small *)p)->vt = lbl_880F4508; o = p; } else o = 0;
    m->a = (Small *)o;
    p = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0xC, 4, 0, 2);
    if (p) { ((Small *)p)->f4 = 0; ((Small *)p)->vt = lbl_880F4518; o = p; } else o = 0;
    m->b = (Small *)o;
    p = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x90, 0x10, 0, 2);
    if (p) { ((Big *)p)->f78 = 0; ((Big *)p)->vt = lbl_880D6B70; o = p; } else o = 0;
    m->big = (Big *)o;
    p = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x70, 0x10, 0, 2);
    m->addr_obj = p ? ts4_addr_lbl_880F44EC_8867E7B0(p) : 0;
    p = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x3B0, 0x10, 0, 2);
    m->ctor_obj = p ? ts4_obj_ctor_886AC130(p) : 0;
    p = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x120, 0x10, 0, 2);
    m->list = p ? ts4_call_seq_u32_off28_886A7FC0(p) : 0;
    m->f90 = 0; m->f80 = 0;
    m->b97 = 0; m->b94 = 0; m->b95 = 0; m->b96 = 0; m->b98 = 0; m->ba1 = 0;
    m->fa4 = -1; m->ba0 = 0; m->ba9 = 0;
    return m;
}
