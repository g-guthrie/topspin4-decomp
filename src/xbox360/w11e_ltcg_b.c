/*
 * W11E (LTCG route): 0x8864E888. Check with
 *   tools/fn_check_ltcg.py src/xbox360/w11e_ltcg_b.c ts4_rotate_vec_in_place_8864E888=0x8864E888
 *     --context src/xbox360/pp1_pool_primer.c --flags /Oc
 * Matrix by value to a forced-inline helper (see af1_vector.h); lanes z, y, x, vmulfp then two vmaddfp.
 */
#include "af1_vector.h"
#ifdef _MSC_VER
#define W11E_FORCEINLINE static __forceinline
#else
#define W11E_FORCEINLINE static inline
#endif

/* Rotation part only (rows 0-2, no translation row). */
W11E_FORCEINLINE __vector4 w11e_rotate_vec(__vector4 v, Af1Mat m)
{
    __vector4 z = __vspltw(v, 2), y = __vspltw(v, 1), x = __vspltw(v, 0), r;
    r = __vmulfp(z, m.r[2]);
    r = __vmaddfp(y, m.r[1], r);
    r = __vmaddfp(x, m.r[0], r);
    return r;
}

/* Swing_DLL.xex 0x8864E888 */
void ts4_rotate_vec_in_place_8864E888(__vector4 *v, const Af1Mat *m)
{
    *v = w11e_rotate_vec(*v, *m);
}
