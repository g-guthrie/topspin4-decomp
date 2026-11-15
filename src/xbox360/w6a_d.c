#include "w6a_types.h"

typedef struct W6aInfo19a {
    unsigned char pad00[0x188];
    float f188;
    unsigned char pad18c[0x19a - 0x18c];
    unsigned char b19a;
} W6aInfo19a;

typedef struct W6aBody500 {
    unsigned char pad00[0x20];
    char *base20;
} W6aBody500;

typedef struct W6aInner44 {
    unsigned char pad00[0x44];
    W6aInfo19a *info;
    unsigned char pad48[0x5c - 0x48];
    struct {
        unsigned char pad00[0x20];
        char *data;
    } *body;
} W6aInner44;

typedef struct W6aOwner4 {
    unsigned char pad00[4];
    W6aInner44 *inner;
} W6aOwner4;

void ts4_update_speed_from_vector_8865C170(W6aOwner4 *self)
{
    W6aInner44 *in = self->inner;
    __vector4 v, len_sq, r, half, step, len;
    if (!in->info->b19a)
        return;
    v = *(__vector4 *)(in->body->data + 0x500);
    len_sq = __vmsum3fp(v, v);
    r = __vrsqrtefp(len_sq);
    half = __vcfsx(__vspltisw(1), 1);
    step = __vnmsubfp(__vmulfp(len_sq, half), __vmulfp(r, r), half);
    r = __vmaddfp(r, step, r);
    len = __vsel(__vmulfp(len_sq, r), len_sq, __vcmpeqfp(len_sq, __vspltisw(0)));
    in->info->f188 = len.v[0] * 3.5999999046325684f;
}

/* position = v * M with the homogeneous divide */
void ts4_transform_coord_8864E908(__vector4 *v, const __vector4 *m)
{
    __vector4 in = *v;
    __vector4 m0 = m[0], m1 = m[1], m2 = m[2], m3 = m[3];
    __vector4 res, w, one, rcp, r1, step, mask;
    res = __vmaddfp(__vspltw(in, 2), m2, m3);
    one = __vupkd3d(__vspltisw(0), 1);
    res = __vmaddfp(__vspltw(in, 1), m1, res);
    res = __vmaddfp(__vspltw(in, 0), m0, res);
    w = __vspltw(res, 3);
    one = __vspltw(one, 3);
    rcp = __vrefp(w);
    step = __vnmsubfp(w, rcp, one);
    r1 = __vmaddfp(rcp, step, rcp);
    step = __vnmsubfp(w, r1, one);
    mask = __vcmpeqfp(r1, r1);
    r1 = __vmaddfp(r1, step, r1);
    *v = __vmulfp(res, __vsel(rcp, r1, mask));
}
