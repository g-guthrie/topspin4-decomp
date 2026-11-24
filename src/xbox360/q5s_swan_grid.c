/*
 * Q5S swan: spatial grid of clip boxes (LTCG route, /Oc).
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_swan_grid.c ts4_grid_query_overlaps_886C4190=0x886C4190 \
 *        --flags /Oc --context src/xbox360/pp1_pool_primer.c
 */
#include "vx1_vector.h"
typedef struct Q5sGridBox { __vector4 lo, hi; } Q5sGridBox;
typedef struct Q5sGridRange { short start; short end; } Q5sGridRange;
typedef struct Q5sGrid { unsigned char pad00[8]; Q5sGridRange *ranges; unsigned char pad0c[0x38 - 0xc]; unsigned short base_id; unsigned char pad3a[2]; Q5sGridBox *boxes; } Q5sGrid;
typedef struct Q5sIdList { unsigned short *first; unsigned short *last; } Q5sIdList;
/* Swing_DLL.xex 0x886C4190: collect the indices of the boxes (0x20 bytes: lo, hi vectors) of every listed
 * id that overlap the query box q; at most 256. Both box pointers are formed from the range before the
 * start index is taken into its own local (that order sets the r9/r10 assignment). */
unsigned int ts4_grid_query_overlaps_886C4190(Q5sGrid *g, Q5sIdList *ids, Q5sGridBox *q, unsigned short *out)
{
    unsigned short *e = ids->last;
    unsigned short *p = ids->first;
    unsigned int n = 0;
    int base = g->base_id;
    Q5sGridRange *ranges = g->ranges;
    for (; p != e; p++) {
        Q5sGridRange *r = &ranges[*p - base];
        Q5sGridBox *b = &g->boxes[r->start];
        Q5sGridBox *be = &g->boxes[r->end];
        int idx = r->start;
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
