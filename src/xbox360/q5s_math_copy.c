/*
 * 0x88186110: std::copy over 0x40-byte elements of four VMX rows (begin, end, dest) -> dest end.
 * Callers (vector erase): me_ts4_vec_tidy_free_88721B58.c, eq_q5_gameplay_small_h.c. The element type is not
 * known beyond four 16-byte rows, so it stays private here.
 *
 * Codegen: copying the parameters into locals (cursor locals declared after `n`) is what makes the
 * compiler keep dest in r3 for the whole loop (mr r10,r3; mr r3,r5; blelr) and address the third row
 * store as stvx v,(dest-src),(src+0x20). With the parameters used directly it keeps dest in r5
 * (23 instructions off). Found with tools/perm_auto.py (alias mutation).
 */
#include "include/ts4/ts4.h"

typedef struct Q5sMtxRows { __vector4 r0, r1, r2, r3; } Q5sMtxRows;

static __inline void q5s_mtx_rows_assign(Q5sMtxRows *d, const Q5sMtxRows *s)
{
    d->r0 = s->r0; d->r1 = s->r1; d->r2 = s->r2; d->r3 = s->r3;
}

Q5sMtxRows *ts4_copy_mtx_rows_88186110(Q5sMtxRows *first, Q5sMtxRows *last, Q5sMtxRows *dest)
{
    Q5sMtxRows *src = first;
    int n;
    Q5sMtxRows *dst;
    dst = dest;
    for (n = last - src; n > 0; --n, ++src, ++dst)
        q5s_mtx_rows_assign(dst, src);
    return dst;
}
