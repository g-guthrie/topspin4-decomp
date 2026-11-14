/* HS2 hand-decompiled functions, group F: float4 helpers (Swing_DLL.xex 0x8851xxxx). */

#ifdef _MSC_VER
extern float __fsqrts(float);
#pragma intrinsic(__fsqrts)
#else
static float __fsqrts(float x) { return x; }
#endif

typedef struct Hs2Vec4 {
    float x, y, z, w;
} Hs2Vec4;

/* out = *in scaled component-wise by s (copy goes through a stack temporary). */
void ts4_vec4_scale_88516F98(Hs2Vec4 *out, const Hs2Vec4 *in, float s)
{
    Hs2Vec4 t = *in;
    t.x *= s;
    t.y *= s;
    t.z *= s;
    t.w *= s;
    *out = t;
}

/* Same as ts4_vec4_scale_88516F98 with an extra ignored second argument. */
void ts4_vec4_scale_885170A0(Hs2Vec4 *out, int unused, const Hs2Vec4 *in, float s)
{
    Hs2Vec4 t = *in;
    (void)unused;
    t.x *= s;
    t.y *= s;
    t.z *= s;
    t.w *= s;
    *out = t;
}

/* Euclidean distance between two float4 values. */
float ts4_vec4_distance_88518E78(const Hs2Vec4 *a, const Hs2Vec4 *b)
{
    Hs2Vec4 t = *a;
    float dw = t.w - b->w;
    float dz = t.z - b->z;
    float dy = t.y - b->y;
    float dx = t.x - b->x;
    return __fsqrts(dx * dx + dy * dy + dz * dz + dw * dw);
}

extern float lbl_88001A68; /* 1.0f */

/* out = b + a (component-wise, a copied through a stack temporary). */
void ts4_vec4_add_88516E78(Hs2Vec4 *out, const Hs2Vec4 *a, const Hs2Vec4 *b)
{
    Hs2Vec4 t = *a;
    t.x = b->x + t.x;
    t.y = b->y + t.y;
    t.z = b->z + t.z;
    t.w = b->w + t.w;
    *out = t;
}

/* out = a - b (component-wise). */
void ts4_vec4_sub_88516F08(Hs2Vec4 *out, const Hs2Vec4 *a, const Hs2Vec4 *b)
{
    Hs2Vec4 t = *a;
    t.x = t.x - b->x;
    t.y = t.y - b->y;
    t.z = t.z - b->z;
    t.w = t.w - b->w;
    *out = t;
}

/* out = *in * (1.0f / s). */
void ts4_vec4_div_scalar_88517018(Hs2Vec4 *out, const Hs2Vec4 *in, float s)
{
    Hs2Vec4 t = *in;
    t.x = t.x * (lbl_88001A68 / s);
    t.y = t.y * (lbl_88001A68 / s);
    t.z = t.z * (lbl_88001A68 / s);
    t.w = t.w * (lbl_88001A68 / s);
    *out = t;
}

/* Same as ts4_vec4_div_scalar_88517018 with an extra ignored second argument. */
void ts4_vec4_div_scalar_88517120(Hs2Vec4 *out, int unused, const Hs2Vec4 *in, float s)
{
    Hs2Vec4 t = *in;
    (void)unused;
    t.x = t.x * (lbl_88001A68 / s);
    t.y = t.y * (lbl_88001A68 / s);
    t.z = t.z * (lbl_88001A68 / s);
    t.w = t.w * (lbl_88001A68 / s);
    *out = t;
}

/* Euclidean distance between two float4 values (b copied through a stack temporary). */
float ts4_vec4_distance_rev_88519160(const Hs2Vec4 *a, const Hs2Vec4 *b)
{
    Hs2Vec4 t = *b;
    float dw = t.w - a->w;
    float dz = t.z - a->z;
    float dy = t.y - a->y;
    float dx = t.x - a->x;
    return __fsqrts(dx * dx + dy * dy + dz * dz + dw * dw);
}

typedef struct Hs2Mat34 {
    float m[12];
} Hs2Mat34;

/* Scales the three 4-float rows of a 3x4 matrix by sx, sy and sz. */
void ts4_mat34_scale_rows_8864E5A8(Hs2Mat34 *m, float sx, float sy, float sz)
{
    m->m[0] *= sx;
    m->m[1] *= sx;
    m->m[2] *= sx;
    m->m[3] *= sx;
    m->m[4] *= sy;
    m->m[5] *= sy;
    m->m[6] *= sy;
    m->m[7] *= sy;
    m->m[8] *= sz;
    m->m[9] *= sz;
    m->m[10] *= sz;
    m->m[11] *= sz;
}
