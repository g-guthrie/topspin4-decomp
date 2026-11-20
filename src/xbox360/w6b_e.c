#include "w6b_types.h"

static __inline void w6b_swap(__vector4 *a, __vector4 *b)
{
    __vector4 t = *a;
    *a = *b;
    *b = t;
}

void ts4_matrix_flip_z_swap_rows_88661188(Vx1Vec *m)
{
    int i;
    for (i = 0; i < 4; i++)
        vx1_vec_set_z(&m[i], -vx1_vec_z(&m[i]));
    w6b_swap(&m[3].v, &m[2].v);
    w6b_swap(&m[0].v, &m[1].v);
}

extern const __vector4 lbl_880FC650;

typedef struct W6eCfg { unsigned char pad[0x2c]; int type2c; unsigned char pad30[0x160 - 0x30]; __vector4 v160; __vector4 v170; __vector4 v180; __vector4 v190; } W6eCfg;
typedef struct W6eP1c { unsigned char pad[0x4c]; W6eCfg *cfg4c; } W6eP1c;
typedef struct W6eSel {
    unsigned char pad00[0x1c];
    W6eP1c *p1c;              /* +0x1c */
    __vector4 v20;            /* +0x20 */
    __vector4 v30;            /* +0x30 */
    int mode40;               /* +0x40 */
} W6eSel;

void ts4_select_vector_8866CB28(__vector4 *out, W6eSel *self)
{
    __vector4 r = lbl_880FC650;
    W6eCfg *cfg = self->p1c->cfg4c;
    int mode = self->mode40;
    if (cfg->type2c == 2) {
        switch (mode) {
        case 3: r = cfg->v180; break;
        case 4: r = cfg->v160; break;
        case 5: r = cfg->v190; break;
        case 6: r = cfg->v170; break;
        default: break;
        }
    } else {
        if (mode == 1)
            r = self->v30;
        else if (mode == 2)
            r = self->v20;
    }
    *out = r;
}

typedef struct W6eP78 { unsigned char pad[0x90]; __vector4 vec90; } W6eP78;
typedef struct W6eObj78 { unsigned char pad[0x78]; W6eP78 *p78; } W6eObj78;
void fn_8867A7C0(W6eObj78 *self, __vector4 *out, float t);
extern const float g_ts4_script_constants[];

void ts4_accumulate_samples_8868ED00(W6eObj78 *self, __vector4 *out, int n)
{
    *out = self->p78->vec90;
    if (n > 0) {
        float one = 1.0f;
        float inv = one / (float)n;
        float idx = one;
        float w = one;
        __vector4 prev = __vspltisw(0);
        int i;
        for (i = 1; i < n; i++) {
            __vector4 tmp;
            __vector4 cur;
            w = w - inv;
            fn_8867A7C0(self, &tmp, idx);
            cur = tmp;
            *out = __vmaddfp(vx1_replicate(w), __vsubfp(cur, prev), *out);
            prev = cur;
            idx = idx + one;
        }
    }
}

typedef struct W6eList30 { unsigned char *base; } W6eList30;
typedef struct W6eHost24 { unsigned char pad[0x24]; void *p24; } W6eHost24;
W6eList30 *ts4_call_seq_fn_884025C0_88402FB0(void *p);
static const float w6e_zero_5b98 = 0.0f;

void ts4_extract_xyz_array_88645B98(W6eHost24 *self, __vector4 *out, unsigned int n)
{
    W6eList30 *l = ts4_call_seq_fn_884025C0_88402FB0(self->p24);
    unsigned int i;
    for (i = 0; i != n; i++) {
        __vector4 v = *(__vector4 *)(l->base + i * 0x30);
        float z, x, y;
        __vector4 r;
        __stvewx(__vspltw(v, 2), &z, 0);
        __stvewx(__vspltw(v, 1), &y, 0);
        __stvewx(__vspltw(v, 0), &x, 0);
        r.v[0] = x;
        r.v[1] = y;
        r.v[2] = z;
        r.v[3] = w6e_zero_5b98;
        out[i] = r;
    }
}

static __inline __vector4 w6e_load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}

static __inline __vector4 w6e_transform_coord(__vector4 p, const __vector4 *m)
{
    __vector4 m0 = m[0];
    __vector4 sz = __vspltw(p, 2);
    __vector4 sy = __vspltw(p, 1);
    __vector4 sx = __vspltw(p, 0);
    __vector4 r = __vmaddfp(m[2], sz, m[3]);
    __vector4 one = __vspltw(__vupkd3d(__vspltisw(0), 1), 3);
    __vector4 w, r0, s, r1, s2, mask, r2, rf;
    r = __vmaddfp(sy, m[1], r);
    r = __vmaddfp(sx, m0, r);
    w = __vspltw(r, 3);
    r0 = __vrefp(w);
    s = __vnmsubfp(w, r0, one);
    r1 = __vmaddfp(r0, s, r0);
    s2 = __vnmsubfp(w, r1, one);
    mask = __vcmpeqfp(r1, r1);
    r2 = __vmaddfp(r1, s2, r1);
    rf = __vsel(r0, r2, mask);
    return __vmulfp(r, rf);
}

extern const float g_ts4_script_constants[];

void ts4_transform_vec3_in_place_8864E9F8(float *v, const __vector4 *m)
{
    __vector4 p = w6e_load3(v);
    __vector4 r;
    p.v[3] = g_ts4_script_constants[0];
    r = w6e_transform_coord(p, m);
    __stvewx(__vspltw(r, 0), v, 0);
    __stvewx(__vspltw(r, 1), v, 4);
    __stvewx(__vspltw(r, 2), v, 8);
}

typedef struct W6eInfo { unsigned char pad[8]; float f08; float f0c; unsigned char pad10[0xb0 - 0x10]; int hash; } W6eInfo;
typedef struct W6eRig {
    unsigned char pad00[0x24];
    W6eInfo *info24;               /* +0x24 */
    unsigned char pad28[0x34 - 0x28];
    unsigned char sub34[0x160 - 0x34];
    __vector4 v160;
    __vector4 v170;
    __vector4 v180;
    __vector4 v190;
} W6eRig;
void ts4_loop_call_seq_u32_off2c_8890E988(void *p);
static __inline void w6e_setx(__vector4 *p, float x) { *p = vx1_set_x(*p, x); }

void ts4_set_rig_x_lanes_8868D510(W6eRig *self)
{
    int h = self->info24->hash;
    float a[2];
    ts4_loop_call_seq_u32_off2c_8890E988(self->sub34 + 0);
    if (h == (int)0xa2eda1e7) {
        a[0] = self->info24->f0c;
        a[1] = self->info24->f08;
    } else {
        a[0] = -self->info24->f0c;
        a[1] = -self->info24->f08;
    }
    w6e_setx(&self->v160, a[0]);
    w6e_setx(&self->v170, a[0]);
    w6e_setx(&self->v180, a[1]);
    w6e_setx(&self->v190, a[1]);
}
