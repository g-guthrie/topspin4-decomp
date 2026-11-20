/* Loader_DLL.xex 0x83463D08-0x83465A80, executable version 0.0.0.3. */
/* Library routines: zlib 1.1.x trees.c. */

#include "l8_zlib.h"

#define TS4L_PUT_BYTE(s, c) { s->pending_buf[s->pending++] = (c); }
#define TS4L_PUT_SHORT(s, w)                                                                   \
    {                                                                                          \
        TS4L_PUT_BYTE(s, (ts4l_u8)((w) & 0xff));                                               \
        TS4L_PUT_BYTE(s, (ts4l_u8)((ts4l_u16)(w) >> 8));                                       \
    }

#define TS4L_SEND_BITS(s, value, length)                                                       \
    {                                                                                          \
        int len = length;                                                                      \
        if (s->bi_valid > (int)16 - len) {                                                     \
            int val = value;                                                                   \
            s->bi_buf |= (val << s->bi_valid);                                                 \
            TS4L_PUT_SHORT(s, s->bi_buf);                                                      \
            s->bi_buf = (ts4l_u16)val >> (16 - s->bi_valid);                                   \
            s->bi_valid += len - 16;                                                           \
        } else {                                                                               \
            s->bi_buf |= (value) << s->bi_valid;                                               \
            s->bi_valid += len;                                                                \
        }                                                                                      \
    }

#define TS4L_SEND_CODE(s, c, tree) TS4L_SEND_BITS(s, tree[c].freq, tree[c].code)

extern ts4l_u8 lbl_8307B49C[];
extern int lbl_8307B428[];
extern ts4l_u8 lbl_8307BA70[];
extern ts4l_u8 lbl_8307BC70[];

#define TS4L_SMALLER(tree, n, m, depth)                                                        \
    (tree[n].freq < tree[m].freq || (tree[n].freq == tree[m].freq && depth[n] <= depth[m]))

void ts4l_zlib_pqdownheap_834639D8(ts4l_zstate *s, ts4l_zct *tree, int k)
{
    int v = s->heap[k];
    int j = k << 1;

    while (j <= s->heap_len) {
        if (j < s->heap_len && TS4L_SMALLER(tree, s->heap[j + 1], s->heap[j], s->depth)) {
            j++;
        }
        if (TS4L_SMALLER(tree, v, s->heap[j], s->depth))
            break;
        s->heap[k] = s->heap[j];
        k = j;
        j <<= 1;
    }
    s->heap[k] = v;
}

void ts4l_zlib_gen_bitlen_83463AC8(ts4l_zstate *s, ts4l_ztdesc *desc)
{
    ts4l_zct *tree = desc->dyn_tree;
    int max_code = desc->max_code;
    const ts4l_zct *stree = desc->stat_desc->static_tree;
    const int *extra = desc->stat_desc->extra_bits;
    int base = desc->stat_desc->extra_base;
    int max_length = desc->stat_desc->max_length;
    int h;
    int n, m;
    int bits;
    int xbits;
    ts4l_u16 f;
    int overflow = 0;

    for (bits = 0; bits <= 15; bits++)
        s->bl_count[bits] = 0;

    tree[s->heap[s->heap_max]].code = 0;

    for (h = s->heap_max + 1; h < 573; h++) {
        n = s->heap[h];
        bits = tree[tree[n].code].code + 1;
        if (bits > max_length)
            bits = max_length, overflow++;
        tree[n].code = (ts4l_u16)bits;

        if (n > max_code)
            continue;

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base)
            xbits = extra[n - base];
        f = tree[n].freq;
        s->opt_len += (ts4l_u32)f * (bits + xbits);
        if (stree)
            s->static_len += (ts4l_u32)f * (stree[n].code + xbits);
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
            if (tree[m].code != (unsigned)bits) {
                s->opt_len += ((long)bits - (long)tree[m].code) * (long)tree[m].freq;
                tree[m].code = (ts4l_u16)bits;
            }
            n--;
        }
    }
}

void ts4l_zlib_scan_tree_83463D08(ts4l_zstate *s, ts4l_zct *tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].code;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0)
        max_count = 138, min_count = 3;
    tree[max_code + 1].code = (ts4l_u16)0xffff;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen;
        nextlen = tree[n + 1].code;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            s->bl_tree[curlen].freq += count;
        } else if (curlen != 0) {
            if (curlen != prevlen)
                s->bl_tree[curlen].freq++;
            s->bl_tree[16].freq++;
        } else if (count <= 10) {
            s->bl_tree[17].freq++;
        } else {
            s->bl_tree[18].freq++;
        }
        count = 0;
        prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

void ts4l_zlib_send_tree_83463E30(ts4l_zstate *s, ts4l_zct *tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].code;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0)
        max_count = 138, min_count = 3;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen;
        nextlen = tree[n + 1].code;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            do {
                TS4L_SEND_CODE(s, curlen, s->bl_tree);
            } while (--count != 0);
        } else if (curlen != 0) {
            if (curlen != prevlen) {
                TS4L_SEND_CODE(s, curlen, s->bl_tree);
                count--;
            }
            TS4L_SEND_CODE(s, 16, s->bl_tree);
            TS4L_SEND_BITS(s, count - 3, 2);
        } else if (count <= 10) {
            TS4L_SEND_CODE(s, 17, s->bl_tree);
            TS4L_SEND_BITS(s, count - 3, 3);
        } else {
            TS4L_SEND_CODE(s, 18, s->bl_tree);
            TS4L_SEND_BITS(s, count - 11, 7);
        }
        count = 0;
        prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

void ts4l_zlib_send_all_trees_83464380(ts4l_zstate *s, int lcodes, int dcodes, int blcodes)
{
    int rank;

    TS4L_SEND_BITS(s, lcodes - 257, 5);
    TS4L_SEND_BITS(s, dcodes - 1, 5);
    TS4L_SEND_BITS(s, blcodes - 4, 4);
    for (rank = 0; rank < blcodes; rank++) {
        TS4L_SEND_BITS(s, s->bl_tree[lbl_8307B49C[rank]].code, 3);
    }
    ts4l_zlib_send_tree_83463E30(s, s->dyn_ltree, lcodes - 1);
    ts4l_zlib_send_tree_83463E30(s, s->dyn_dtree, dcodes - 1);
}

#define TS4L_D_CODE(dist)                                                                      \
    ((ts4l_u8)((dist) < 256 ? lbl_8307BA70[dist] : lbl_8307BA70[256 + ((dist) >> 7)]))

extern void ts4l_zlib_build_tree_83464EF0(ts4l_zstate *s, ts4l_ztdesc *desc);

int ts4l_zlib_build_bl_tree_834651C0(ts4l_zstate *s)
{
    int max_blindex;

    ts4l_zlib_scan_tree_83463D08(s, s->dyn_ltree, s->l_desc.max_code);
    ts4l_zlib_scan_tree_83463D08(s, s->dyn_dtree, s->d_desc.max_code);
    ts4l_zlib_build_tree_83464EF0(s, &s->bl_desc);
    for (max_blindex = 19 - 1; max_blindex >= 3; max_blindex--) {
        if (s->bl_tree[lbl_8307B49C[max_blindex]].code != 0)
            break;
    }
    s->opt_len += 3 * (max_blindex + 1) + 5 + 5 + 4;
    return max_blindex;
}

void ts4l_zlib_tr_stored_block_83465250(ts4l_zstate *s, char *buf, ts4l_u32 stored_len, int eof)
{
    unsigned len = (unsigned)stored_len;

    TS4L_SEND_BITS(s, (0 << 1) + eof, 3);

    if (s->bi_valid > 8) {
        TS4L_PUT_SHORT(s, s->bi_buf);
    } else if (s->bi_valid > 0) {
        TS4L_PUT_BYTE(s, (ts4l_u8)s->bi_buf);
    }
    s->bi_buf = 0;
    s->bi_valid = 0;
    s->last_eob_len = 8;

    TS4L_PUT_SHORT(s, (ts4l_u16)len);
    TS4L_PUT_SHORT(s, (ts4l_u16)~len);
    while (len--) {
        TS4L_PUT_BYTE(s, *buf++);
    }
}

