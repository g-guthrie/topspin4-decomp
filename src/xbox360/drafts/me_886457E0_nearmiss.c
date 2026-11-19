/* me_886457E0 near-miss: 87 off (LTCG + primer). Force mixer: for each 0x1c-byte force with a cfg, sample the pair
   table (fn_88644CE8), rotate the pair by the force angle (the 0x88644C58 polynomial sin/cos rotation, inlined),
   accumulate weight*angle into twist and gain*weight*pair into x/z; then scale by twist_scale (mode != 1) and store
   (sx, 0, scale*sz, 0) and scale*twist. Structure is right; open: the zero kept in f27, the target's
   base+offset induction (r29) and the hoisted lvx of both coefficient vectors, which we keep as addresses.
   Depends on 0x88644C58 (draft, 8 off). 2 variants. */
#include "vx1_vector.h"
void __stvewx(__vector4 v, void *p, int off);
extern const __vector4 lbl_880D1B00;
extern const __vector4 lbl_880D1B10;
extern const float g_ts4_event_value;   /* 0.0f */
static __inline void rotate2(float *x, float *y, float a)
{
    Vx1Vec p;
    __vector4 sq;
    struct { float s, c; } sc;
    float a2 = a * a;
    p.v.v[2] = a2;
    p.v.v[1] = a;
    p.v.v[0] = 1.0f;
    p.v.v[3] = a2 * a;
    sq = __vmulfp(p.v, p.v);
    __stvewx(__vmsum4fp(sq, lbl_880D1B10), &sc.c, 0);
    __stvewx(__vmsum4fp(__vmulfp(sq, __vspltw(p.v, 1)), lbl_880D1B00), &sc.s, 0);
    {
        float c = sc.c, s = sc.s;
        float py = *y, px = *x;
        *y = py * c - px * s;
        *x = py * s + px * c;
    }
}
typedef struct Cfg Cfg;
typedef struct Force { char p0[4]; Cfg *cfg; float u; float w; float angle; float weight; char p18[4]; } Force;
typedef struct Mixer { Force *begin; Force *end; char p8[0x14]; float twist_scale; float gain; char p28[0x28]; __vector4 out; float twist; char p64[0x58]; int mode; } Mixer;
void fn_88644CE8(Mixer *o, Cfg *c, float u, float w, float *da, float *db);

void fn_886457E0(Mixer *m)
{
    Force *b = m->begin;
    int n = m->end - b;
    float zero = g_ts4_event_value;
    float x = zero, y = zero;
    float scale = 1.0f;
    float twist = zero, sx = zero, sz = zero;
    m->out = __vspltisw(0);
    if (n) {
        int off = 0;
        do {
            Force *f = (Force *)((char *)b + off);
            if (f->cfg) {
                float ang = f->angle;
                float k;
                fn_88644CE8(m, f->cfg, f->u, f->w, &y, &x);
                rotate2(&x, &y, ang);
                k = m->gain * f->weight;
                twist = f->weight * ang + twist;
                sz = k * y + sz;
                sx = k * x + sx;
            }
            off += sizeof(Force);
        } while (--n);
    }
    if (m->mode != 1) scale = m->twist_scale;
    {
        Vx1Vec v;
        v.v.v[0] = sx;
        v.v.v[1] = zero;
        v.v.v[2] = scale * sz;
        v.v.v[3] = zero;
        m->twist = scale * twist;
        m->out = v.v;
    }
}
