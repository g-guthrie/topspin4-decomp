/*
 * Math, curves & geometry: 4x4 matrix product (q5s, subsystem math).
 * Checked: python3 tools/fn_check_ltcg.py src/xbox360/q5s_math_mtx.c ts4_mtx_mul_881A4308=0x881A4308 --flags /Oc
 *          --context src/xbox360/pp1_pool_primer.c  -> MATCH size 0xc0 (ltcg)
 * Shape: the product goes through a by-value temporary assigned with af1_mat_set; assigning the
 * af1_mat_mul result directly (or row by row) gives 0xf0 / 0x100.
 */
#include "af1_vector.h"

/* *out = *a * *b (row i = a[i].x*b[0] + a[i].y*b[1] + a[i].z*b[2] + a[i].w*b[3])           881A4308 */
void ts4_mtx_mul_881A4308(Af1Mat *out, const Af1Mat *a, const Af1Mat *b)
{
    Af1Mat t = af1_mat_mul(*a, b);
    af1_mat_set(out, &t);
}
