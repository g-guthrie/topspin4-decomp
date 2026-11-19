/* 0x88517400: Returns the per-component minimum of a and b as a Vec4, after zero-initialising the result. */
/* Matched on /Oc (agAH). Sibling of 88517378. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
extern const float lbl_88001A20;
Vec4 fn_88517400(const Vec4 *a, const Vec4 *b)
{
    Vec4 r;
    r.x = lbl_88001A20;
    r.y = lbl_88001A20;
    r.z = lbl_88001A20;
    r.w = lbl_88001A20;
    r.x = a->x < b->x ? a->x : b->x;
    r.y = a->y < b->y ? a->y : b->y;
    r.z = a->z < b->z ? a->z : b->z;
    r.w = a->w < b->w ? a->w : b->w;
    return r;
}
