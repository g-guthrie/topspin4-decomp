/* agD 2026-11-19: callee at 0x886107F8 is ts4_handle_forward0_886107F8 (was fn_88610798, the reloc name differed). Brute force of all 2880 declaration orders of the two block scopes: 9 off at best. Residue unchanged (slots 0x70/0x60 swapped, k3 at 0x50 vs 0x58, d copy at 0x50 vs 0x70). */
/* NEAR MISS (9 instructions, plain /Oc): stack slots only. Target puts the first forward handle temp at 0x70 and the ref at 0x60 (we swap them), keeps 0xB894A04C at 0x58 (we reuse 0x50) and copies the difference for the length at 0x70 (we use 0x50). Code order and registers match. */
/* 0x88650430: true when the point lies within the xdata radius (path 0x3CD06B6C/0xDCB67730, default g_ts4_event_value when unresolved) of the xdata centre (0xB894A04C, vec3 view): |p - c|^2 <= r^2. */
#include "../vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#pragma intrinsic(__vsldoi)
typedef unsigned int u32;
typedef struct F3 { float x, y, z; } F3;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4XdataTarget { struct Ts4XdataVt *vt; } Ts4XdataTarget;
typedef struct Ts4XdataRef { Ts4XdataTarget *tgt; u32 offset; u32 extra; } Ts4XdataRef;
typedef struct Ts4XdataVt { void *s[10]; void *(*get)(Ts4XdataTarget *, Ts4XdataRef *, u32, int); } Ts4XdataVt;
extern Ts4XdataRef *ts4_handle_forward_88150770(Ts4XdataRef *out, Ts4Handle12 *h, u32 *hash);
extern Ts4Handle12 *ts4_handle_forward_88610A48(Ts4Handle12 *out, Ts4Handle12 *h, u32 *hash);
extern Ts4XdataRef *ts4_handle_forward0_886107F8(Ts4XdataRef *out, Ts4Handle12 *h);
extern float ts4_if_get_u32_off0_8816CCE0(Ts4XdataRef *r);
extern const float g_ts4_event_value;
static __inline void *xget(Ts4XdataRef *r, int n) { Ts4XdataTarget *t = r->tgt; return t->vt->get(t, r, r->offset, n); }
static __inline __vector4 load3(const F3 *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}
static __inline F3 sub3(const F3 *a, const F3 *b)
{
    F3 r;
    __vector4 d = __vsubfp(load3(a), load3(b));
    __stvewx(__vspltw(d, 0), &r, 0);
    __stvewx(__vspltw(d, 1), &r, 4);
    __stvewx(__vspltw(d, 2), &r, 8);
    return r;
}
static __inline float lensq3(F3 p)
{
    Vx1Vec o;
    __vector4 v = load3(&p);
    o.v = __vmsum3fp(v, v);
    return o.v.v[0];
}
unsigned char ts4_point_within_xdata_radius_88650430(const F3 *pos, Ts4Handle12 *h)
{
    float rad;
    {
        u32 k[2]; Ts4XdataRef tr; Ts4Handle12 th; Ts4XdataRef *r;
        k[1] = 0xDCB67730u; k[0] = 0x3CD06B6Cu;
        r = ts4_handle_forward_88150770(&tr, ts4_handle_forward_88610A48(&th, h, &k[0]), &k[1]);
        if (r->offset == 0xfffff) rad = g_ts4_event_value; else rad = ts4_if_get_u32_off0_8816CCE0(r);
    }
    {
        u32 k3; Ts4Handle12 th; Ts4XdataRef tr2; F3 c, d;
        k3 = 0xB894A04Cu;
        c = *(F3 *)xget(ts4_handle_forward0_886107F8(&tr2, ts4_handle_forward_88610A48(&th, h, &k3)), 4);
        d = sub3(pos, &c);
        return lensq3(d) <= rad * rad;
    }
}
