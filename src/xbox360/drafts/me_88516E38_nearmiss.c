/* 0x88516E38: Divides a 4-float vector in place by d: inv = lbl_88001A68 / d, then each component times inv. */
/* Near miss (agAH): 2 off: fmuls operand order for y and z (target inv first); source order of each product, *=, and C++ operators do not change it. */
typedef struct Vec4f { float x, y, z, w; } Vec4f;
extern const float lbl_88001A68;
void fn_88516E38(Vec4f *v, float d)
{
    float x = v->x, y = v->y, z = v->z, w = v->w;
    float inv = lbl_88001A68 / d;
    v->x = x * inv;
    v->y = inv * y;
    v->z = inv * z;
    v->w = inv * w;
}
