/* Loader_DLL.xex 0x8316A080-0x8316A2C0, executable version 0.0.0.3.
 * zlib 1.1.4 trees.c gen_bitlen. */
#include "l45_zlib_ds.h"

void ts4l_zlib_gen_bitlen_8316A080(Ts4lDeflateState *s, Ts4lTreeDesc *desc)
{
    Ts4lCtData *tree = desc->dyn_tree;
    int max_code = desc->max_code;
    const Ts4lCtData *stree = desc->stat_desc->static_tree;
    const int *extra = desc->stat_desc->extra_bits;
    int base = desc->stat_desc->extra_base;
    int max_length = desc->stat_desc->max_length;
    int h;
    int n, m;
    int bits;
    int xbits;
    ush f;
    int overflow = 0;

    for (bits = 0; bits <= 15; bits++)
        s->bl_count[bits] = 0;

    tree[s->heap[s->heap_max]].dl = 0;

    for (h = s->heap_max + 1; h < 573; h++) {
        n = s->heap[h];
        bits = tree[tree[n].dl].dl + 1;
        if (bits > max_length)
            bits = max_length, overflow++;
        tree[n].dl = (ush)bits;

        if (n > max_code)
            continue;

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base)
            xbits = extra[n - base];
        f = tree[n].fc;
        s->opt_len += (ulg)f * (bits + xbits);
        if (stree)
            s->static_len += (ulg)f * (stree[n].dl + xbits);
    }
    if (overflow == 0)
        return;

    do {
        bits = max_length - 1;
        while (s->bl_count[bits] == 0)
            bits--;
        s->bl_count[bits]--;
        s->bl_count[bits + 1] += 2;
        s->bl_count[max_length]--;
        overflow -= 2;
    } while (overflow > 0);

    for (bits = max_length; bits != 0; bits--) {
        n = s->bl_count[bits];
        while (n != 0) {
            m = s->heap[--h];
            if (m > max_code)
                continue;
            if (tree[m].dl != (unsigned)bits) {
                s->opt_len += ((long)bits - (long)tree[m].dl) * (long)tree[m].fc;
                tree[m].dl = (ush)bits;
            }
            n--;
        }
    }
}
