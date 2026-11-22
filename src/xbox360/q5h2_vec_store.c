/* Q5h2: VMX store helper whose results are discarded (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route.
 * Clone of ts4_vec_pair_store_discard_8890DE88: the sister 0x8890DEF0 is the same body under another address
 * (identical .obj in the original build), so it stores the xyz of both vectors of the pair into a discarded temporary. */
#include "vx1_vector.h"

typedef struct Q5h2Float3 { float x, y, z; } Q5h2Float3;
typedef struct Q5h2VecPair { __vector4 a, b; } Q5h2VecPair;

static __inline void q5h2_store_float3(Q5h2Float3 *dst, __vector4 v)
{
    __stvewx(__vspltw(v, 0), dst, 0);
    __stvewx(__vspltw(v, 1), dst, 4);
    __stvewx(__vspltw(v, 2), dst, 8);
}

/* 0x8890DEF0: store the xyz of both vectors of the pair into a discarded temporary */
void ts4_vec_pair_store_discard_8890DEF0(const Q5h2VecPair *pair)
{
    Q5h2Float3 tmp;
    q5h2_store_float3(&tmp, pair->a);
    q5h2_store_float3(&tmp, pair->b);
}
