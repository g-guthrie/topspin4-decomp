/* 0x88516E38: divides a 4-float vector in place by d: inv = 1 / d, then each component times inv.
 * Matched (/Oc plain) as compound assignments with the literal 1.0f (lbl_88001A68): named component locals give
 * `fmuls (y, inv)` for y/z, the extern numerator gives 3 off; `v->c *= inv` with the literal gives the target's
 * mixed order (x * inv, then inv * y, inv * z, inv * w). */
typedef struct Ts4Vec4f { float x, y, z, w; } Ts4Vec4f;

void ts4_vec4_div_scalar_88516E38(Ts4Vec4f *v, float d)
{
    float inv = 1.0f / d;
    v->x *= inv;
    v->y *= inv;
    v->z *= inv;
    v->w *= inv;
}
