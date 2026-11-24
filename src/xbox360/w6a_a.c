#include "w6a_types.h"

int ts4_vec_all_ge_886C35E0(__vector4 a, __vector4 b)
{
    unsigned int cr;
    __vcmpgefpR(a, b, &cr);
    return (cr >> 7) & 1;
}

void ts4_vec_splat_neg_max_886C35F0(__vector4 *out)
{
    *out = vx1_replicate(-340282346638528859811704183484516925440.0f);
}

__vector4 ts4_vec_sign_to_x_886C3C30(__vector4 v)
{
    __vector4 zero = __vspltisw(0);
    __vector4 ones = __vspltisw(-1);
    __vector4 mask = __vslw(ones, ones);
    __vector4 ge = __vcmpgefp(__vspltw(v, 0), zero);
    return __vsel(__vxor(v, mask), v, ge);
}

void ts4_copy_mat4_88670918(__vector4 *dst, const char *src)
{
    const __vector4 *m = (const __vector4 *)(src + *(const unsigned int *)src);
    __vector4 t[4];
    int i;
    for (i = 0; i < 4; i++)
        t[i] = m[i];
    for (i = 0; i < 4; i++)
        dst[i] = t[i];
}
