/* nearmiss: 17 off; GPR numbering only (r9/r10 swap of the box-array base vs the start index and the
 * mfocrf temp; and the start/end extsh order). Concrete blocker: register allocation; perm_auto (150
 * candidates, -j 3, 600 s) and 10 manual layouts (iterator, index loop, helper, decl order) did not move it.
 * Swing_DLL.xex 0x886C4190: collect the indices of boxes (0x20 bytes: lo, hi vectors) of every listed id
 * that overlap the query box; at most 256. LTCG + pp1_pool_primer, /Oc. */
#include "vx1_vector.h"
typedef struct Box { __vector4 lo, hi; } Box;
typedef struct Range { short start; short end; } Range;
typedef struct Grid { unsigned char pad00[8]; Range *ranges; unsigned char pad0c[0x38 - 0xc]; unsigned short base_id; unsigned char pad3a[2]; Box *boxes; } Grid;
typedef struct IdList { unsigned short *first; unsigned short *last; } IdList;
unsigned int ts4_grid_query_overlaps_886C4190(Grid *g, IdList *ids, Box *q, unsigned short *out)
{
    unsigned short *e = ids->last;
    unsigned short *p = ids->first;
    unsigned int n = 0;
    int base = g->base_id;
    Range *ranges = g->ranges;
    for (; p != e; p++) {
        Range *r = &ranges[*p - base];
        int idx = r->start;
        Box *b = &g->boxes[idx];
        Box *be = &g->boxes[r->end];
        for (; b != be; b++, idx++) {
            unsigned int cr;
            unsigned int ok;
            __vector4 m = __vand(__vcmpgefp(q->hi, b->lo), __vcmpgefp(b->hi, q->lo));
            __vcmpeqfpR(m, __vspltisw(0), &cr);
            ok = (cr >> 5) & 1;
            if ((unsigned char)ok != 0) {
                out[n] = idx;
                n++;
                if (n == 256)
                    break;
            }
        }
        if (n == 256)
            break;
    }
    return n;
}
