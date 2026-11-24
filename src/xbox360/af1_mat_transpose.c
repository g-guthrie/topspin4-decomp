/* AF1: in-place matrix transpose (by-value transpose, rule A1 in docs/agents/near-misses/AF1.md). */
#include "af1_vector.h"
/* Swing_DLL.xex 0x8864E6B8 */
void ts4_mat_transpose_8864E6B8(Af1Mat *m)
{
    Af1Mat t = af1_mat_transpose(*m);
    af1_mat_set(m, &t);
}
