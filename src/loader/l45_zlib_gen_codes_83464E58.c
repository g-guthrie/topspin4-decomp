/* Loader_DLL.xex 0x83464E58-0x83464EEC, executable version 0.0.0.3.
 * zlib 1.1.4 trees.c gen_codes (second copy). */
#include "l45_zlib_ds.h"

static unsigned bi_reverse(unsigned code, int len)
{
    unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

void ts4l_zlib_gen_codes_83464E58(Ts4lCtData *tree, int max_code, ush *bl_count)
{
    ush next_code[16];
    ush code = 0;
    int bits;
    int n;

    for (bits = 1; bits <= 15; bits++) {
        next_code[bits] = code = (ush)((code + bl_count[bits - 1]) << 1);
    }
    for (n = 0; n <= max_code; n++) {
        int len = tree[n].dl;
        if (len == 0)
            continue;
        tree[n].fc = (ush)bi_reverse(next_code[len]++, len);
    }
}

