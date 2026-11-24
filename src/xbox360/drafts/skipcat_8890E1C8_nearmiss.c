/* Near miss, 2 instructions: the *x and r->lo loads come out in swapped order.
 * Check: python3 tools/fn_check_ltcg.py <this> ts4_clamp_to_range_8890E1C8=0x8890E1C8 \
 *          --context src/xbox360/pp1_pool_primer.c --flags /Oc
 * Every spelling of the two selects (>=/<, operand order, helper vs C++ member)
 * compiles to the same code; only the load order differs. */
#define W5C_SEL
#include "w5c_types.h"
typedef struct { float lo; float hi; } TS4Range;
/* *x = min(max(*x, r->lo), r->hi) */
void ts4_clamp_to_range_8890E1C8(TS4Range *r, float *x)
{
    float v = *x, lo = r->lo;
    *x = w5c_min(w5c_max(v, lo), r->hi);
}
