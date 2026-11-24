/* 0x88517378: Returns the per-component maximum of a and b as a Vec4, after zero-initialising the result (lbl_88001A20). */
/* Matched on /Oc (agAH). Return the Vec4 by value and zero each field in its own statement. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
extern const float lbl_88001A20;
Vec4 fn_88517378(const Vec4 *a, const Vec4 *b)
{
    Vec4 r;
    r.x = lbl_88001A20;
    r.y = lbl_88001A20;
    r.z = lbl_88001A20;
    r.w = lbl_88001A20;
    r.x = a->x > b->x ? a->x : b->x;
    r.y = a->y > b->y ? a->y : b->y;
    r.z = a->z > b->z ? a->z : b->z;
    r.w = a->w > b->w ? a->w : b->w;
    return r;
}
