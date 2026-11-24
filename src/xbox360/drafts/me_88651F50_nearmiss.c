/* near-miss 0x88651F50 (plain /Oc): 15 instructions off, same size. Only the stack slots of the six handle temporaries differ (target: inner results at 0x80/0x90/0xA0, outer at 0xB0, spin inner at 0xB0/outer 0xC0). Block-scoped temps overlap (24 off); C++ by-value forwards with temporaries copy the handle (worse). */
/* 0x88651F50: resolves the six tuning curves of a shot config node: three under section 0xB7B2364B into the speed
 * table and three under section 0xDCB67730 into the spin table (each through the curve loader vslot 10, kind 4). */
typedef unsigned long u32;
typedef struct Ts4Handle { u32 w[3]; } Ts4Handle;
typedef struct CurveLoader CurveLoader;
struct CurveLoader { u32 (**vtbl)(CurveLoader *self, Ts4Handle *h, u32 extra, u32 kind); };
typedef struct CurveTable { u32 c[3]; } CurveTable;
typedef struct ShotCfg { char p[0x14]; CurveTable *speed; char p2[0x20 - 0x18]; CurveTable *spin; } ShotCfg;
void ts4_get_fn_8864F6E8_88650C70(ShotCfg *self, Ts4Handle node);
Ts4Handle *ts4_handle_forward_88610A48(Ts4Handle *out, Ts4Handle *in, u32 *key);
Ts4Handle *ts4_handle_forward_88150770(Ts4Handle *out, Ts4Handle *in, u32 *key);
static __inline u32 load_curve(Ts4Handle *h)
{
    CurveLoader *l = (CurveLoader *)h->w[0];
    return l->vtbl[10](l, h, h->w[1], 4);
}
void fn_88651F50(ShotCfg *self, Ts4Handle node)
{
    u32 k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
    Ts4Handle ta0, tb0, tc0, t80, t90;
    ts4_get_fn_8864F6E8_88650C70(self, node);
    k0 = 0xCA3885CFu;
    ts4_handle_forward_88610A48(&t80, &node, &k0);
    k1 = 0xB7B2364Bu;
    self->speed->c[0] = load_curve(ts4_handle_forward_88150770(&tb0, &t80, &k1));
    k2 = 0xF758AC7Fu;
    ts4_handle_forward_88610A48(&t90, &node, &k2);
    k3 = 0xB7B2364Bu;
    self->speed->c[1] = load_curve(ts4_handle_forward_88150770(&tb0, &t90, &k3));
    k4 = 0xB0F8D6AFu;
    ts4_handle_forward_88610A48(&ta0, &node, &k4);
    k5 = 0xB7B2364Bu;
    self->speed->c[2] = load_curve(ts4_handle_forward_88150770(&tb0, &ta0, &k5));
    k6 = 0x1D368573u;
    k7 = 0xDCB67730u;
    self->spin->c[0] = load_curve(ts4_handle_forward_88150770(&tc0, ts4_handle_forward_88610A48(&tb0, &node, &k6), &k7));
    k9 = 0xDCB67730u;
    k8 = 0xBB418EC7u;
    self->spin->c[1] = load_curve(ts4_handle_forward_88150770(&tb0, ts4_handle_forward_88610A48(&tc0, &node, &k8), &k9));
    k11 = 0xDCB67730u;
    k10 = 0x8AA9945Au;
    self->spin->c[2] = load_curve(ts4_handle_forward_88150770(&tb0, ts4_handle_forward_88610A48(&tc0, &node, &k10), &k11));
}
