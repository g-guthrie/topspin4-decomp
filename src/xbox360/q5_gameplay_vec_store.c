/* Q5: VMX store helpers whose results are discarded (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route.
 * The only reference to these is .pdata (address-taken / table entry); the bodies store the xyz of two
 * vectors into a stack temporary that is never read, which is what an inlined XMStoreFloat3-style
 * accessor leaves behind once the use of its result has been compiled out. */
#include "vx1_vector.h"
typedef struct Q5Float3 { float x, y, z; } Q5Float3;
typedef struct Q5VecPair { __vector4 a, b; } Q5VecPair;

static __inline void q5_store_float3(Q5Float3 *dst, __vector4 v)
{
    __stvewx(__vspltw(v, 0), dst, 0);
    __stvewx(__vspltw(v, 1), dst, 4);
    __stvewx(__vspltw(v, 2), dst, 8);
}

/* 0x8890DE88: store the xyz of both vectors of the pair into a discarded temporary */
void ts4_vec_pair_store_discard_8890DE88(const Q5VecPair *pair)
{
    Q5Float3 tmp;
    q5_store_float3(&tmp, pair->a);
    q5_store_float3(&tmp, pair->b);
}
