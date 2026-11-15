#include "w6b_types.h"

int ts4_vec_all_ge_886C3610(__vector4 a, __vector4 b)
{
    unsigned int cr;
    __vcmpgefpR(b, a, &cr);
    return (cr >> 7) & 1;
}

void ts4_vec_splat_flt_max_886C3620(__vector4 *out)
{
    *out = vx1_replicate(340282346638528859811704183484516925440.0f);
}

__vector4 ts4_vec_sign_mask_xz_886C5070(int enable)
{
    __vector4 ones, zero, m;
    if (enable == 0)
        return __vspltisw(0);
    ones = __vspltisw(-1);
    zero = __vspltisw(0);
    m = __vslw(ones, ones);
    m = __vrlimi(m, zero, 4, 0);
    m = __vrlimi(m, zero, 1, 0);
    return m;
}
