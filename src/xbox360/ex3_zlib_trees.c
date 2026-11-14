/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: zlib 1.2.3 trees.c. All of these functions share one translation unit because the original
 * compiler gave the file-local helpers private register conventions (r3 survives calls). */
#include "ex3_zlib.h"

#ifdef _MSC_VER
#define EX3_NOINLINE __declspec(noinline)
#else
#define EX3_NOINLINE __attribute__((noinline, unused))
#endif

static const unsigned char lbl_880C9D44[19] = {1}; /* bl_order (first static of the file) */

/* File-local constant tables of trees.c. They are statics of the original translation unit, which is why the
 * compiler reaches several of them from one base register with constant offsets. The values below are
 * placeholders: only their sizes and order matter for the code generation (the real tables live in the
 * game image at the given addresses). */
static const int ex3_extra_lbits_880C9D58[29] = {1};     /* extra_lbits */
static const int ex3_pad_880C9DCC[3] = {1};              /* neighbour in .rdata (keeps the original spacing) */
static const int ex3_extra_dbits_880C9DD8[30] = {1};     /* extra_dbits */
static const int ex3_extra_blbits_880C9E50[19 + 1] = {1}; /* extra_blbits */
static const ex3_ct_data ex3_static_ltree_880C9EA0[288 + 0] = {{1, 1}};   /* static_ltree */
static const ex3_ct_data ex3_static_dtree_880CA320[30] = {{1, 1}};        /* static_dtree */
static const unsigned char ex3_pad_880CA398[0x300] = {1}; /* _dist_code + _length_code live here in the image */
static const int ex3_base_length_880CA698[29 + 1] = {1}; /* base_length */
static const int lbl_880CA710[30] = {1};                 /* base_dist */
extern const unsigned char lbl_880CA398[512]; /* _dist_code */
extern const unsigned char lbl_880CA598[256]; /* _length_code */

struct ex3_z_stream {
    char pad[0x2c];
    int data_type; /* +0x2C */
};

#define EX3_REP_3_6 16
#define EX3_REPZ_3_10 17
#define EX3_REPZ_11_138 18
#define EX3_HEAP_SIZE_ (2 * EX3_L_CODES + 1)
#define EX3_SMALLEST 1

#define EX3_SEND_CODE(s, c, tree) EX3_SEND_BITS(s, (tree)[c].fc, (tree)[c].dl)

#define EX3_SMALLER(tree, n, m, depth) \
    ((tree)[n].fc < (tree)[m].fc || ((tree)[n].fc == (tree)[m].fc && (depth)[n] <= (depth)[m]))

/* Flush the bit buffer to a byte boundary (zlib bi_windup). Swing_DLL.xex 0x88871CF8 */
static EX3_NOINLINE void ex3_bi_windup_88871CF8(ex3_deflate_state *s)
{
    if (s->bi_valid > 8) {
        EX3_PUT_SHORT(s, s->bi_buf);
    } else if (s->bi_valid > 0) {
        EX3_PUT_BYTE(s, (unsigned char)s->bi_buf);
    }
    s->bi_buf = 0;
    s->bi_valid = 0;
}

/* Flush whole bytes out of the bit buffer (zlib bi_flush). Swing_DLL.xex 0x88871D80 */
void ex3_bi_flush_88871D80(ex3_deflate_state *s)
{
    if (s->bi_valid == 16) {
        EX3_PUT_SHORT(s, s->bi_buf);
        s->bi_buf = 0;
        s->bi_valid = 0;
    } else if (s->bi_valid >= 8) {
        EX3_PUT_BYTE(s, (unsigned char)s->bi_buf);
        s->bi_buf >>= 8;
        s->bi_valid -= 8;
    }
}

/* Reverse the first len bits of a code (zlib bi_reverse). Swing_DLL.xex 0x88871E10 */
unsigned ex3_bi_reverse_88871E10(unsigned code, int len)
{
    unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

/* Restore the heap property below node k (zlib pqdownheap). Swing_DLL.xex 0x88872F68 */
static EX3_NOINLINE void ex3_pqdownheap_88872F68(ex3_deflate_state *s, ex3_ct_data *tree, int k)
{
    int v = s->heap[k];
    int j = k << 1;
    while (j <= s->heap_len) {
        if (j < s->heap_len && EX3_SMALLER(tree, s->heap[j + 1], s->heap[j], s->depth))
            j++;
        if (EX3_SMALLER(tree, v, s->heap[j], s->depth))
            break;
        s->heap[k] = s->heap[j];
        k = j;
        j <<= 1;
    }
    s->heap[k] = v;
}

/* Compute optimal bit lengths for a tree, limiting them to max_length (zlib gen_bitlen).
 * Swing_DLL.xex 0x88872D20 */
static EX3_NOINLINE void ex3_gen_bitlen_88872D20(ex3_deflate_state *s, ex3_tree_desc *desc)
{
    ex3_ct_data *tree = desc->dyn_tree;
    int max_code = desc->max_code;
    const ex3_ct_data *stree = desc->stat_desc->static_tree;
    const int *extra = desc->stat_desc->extra_bits;
    int base = desc->stat_desc->extra_base;
    int max_length = desc->stat_desc->max_length;
    int h;
    int n, m;
    int bits;
    int xbits;
    unsigned short f;
    int overflow = 0;

    for (bits = 0; bits <= EX3_MAX_BITS; bits++)
        s->bl_count[bits] = 0;

    tree[s->heap[s->heap_max]].dl = 0;

    for (h = s->heap_max + 1; h < EX3_HEAP_SIZE_; h++) {
        n = s->heap[h];
        bits = tree[tree[n].dl].dl + 1;
        if (bits > max_length)
            bits = max_length, overflow++;
        tree[n].dl = (unsigned short)bits;

        if (n > max_code)
            continue;

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base)
            xbits = extra[n - base];
        f = tree[n].fc;
        s->opt_len += (unsigned long)f * (bits + xbits);
        if (stree)
            s->static_len += (unsigned long)f * (stree[n].dl + xbits);
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
            if ((unsigned)tree[m].dl != (unsigned)bits) {
                s->opt_len += ((long)bits - (long)tree[m].dl) * (long)tree[m].fc;
                tree[m].dl = (unsigned short)bits;
            }
            n--;
        }
    }
}

/* Assign canonical Huffman codes to the symbols of a tree from its length counts (zlib gen_codes).
 * Swing_DLL.xex 0x88872C88 */
static EX3_NOINLINE void ex3_gen_codes_88872C88(ex3_ct_data *tree, int max_code, unsigned short *bl_count)
{
    unsigned short next_code[EX3_MAX_BITS + 1];
    unsigned short code = 0;
    int bits;
    int n;

    for (bits = 1; bits <= EX3_MAX_BITS; bits++) {
        next_code[bits] = code = (unsigned short)((code + bl_count[bits - 1]) << 1);
    }
    for (n = 0; n <= max_code; n++) {
        int len = tree[n].dl;
        if (len == 0)
            continue;
        tree[n].fc = (unsigned short)ex3_bi_reverse_88871E10(next_code[len]++, len);
    }
}

/* Count the run-length codes needed to transmit a tree (zlib scan_tree). Swing_DLL.xex 0x88872B58 */
static EX3_NOINLINE void ex3_scan_tree_88872B58(ex3_deflate_state *s, ex3_ct_data *tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].dl;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0)
        max_count = 138, min_count = 3;
    tree[max_code + 1].dl = (unsigned short)0xffff;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen;
        nextlen = tree[n + 1].dl;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            s->bl_tree[curlen].fc += count;
        } else if (curlen != 0) {
            if (curlen != prevlen)
                s->bl_tree[curlen].fc++;
            s->bl_tree[EX3_REP_3_6].fc++;
        } else if (count <= 10) {
            s->bl_tree[EX3_REPZ_3_10].fc++;
        } else {
            s->bl_tree[EX3_REPZ_11_138].fc++;
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

/* Send a tree in run-length coded form (zlib send_tree). Swing_DLL.xex 0x888725C0 */
static EX3_NOINLINE void ex3_send_tree_888725C0(ex3_deflate_state *s, ex3_ct_data *tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].dl;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0)
        max_count = 138, min_count = 3;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen;
        nextlen = tree[n + 1].dl;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            do {
                EX3_SEND_CODE(s, curlen, s->bl_tree);
            } while (--count != 0);
        } else if (curlen != 0) {
            if (curlen != prevlen) {
                EX3_SEND_CODE(s, curlen, s->bl_tree);
                count--;
            }
            EX3_SEND_CODE(s, EX3_REP_3_6, s->bl_tree);
            EX3_SEND_BITS(s, count - 3, 2);
        } else if (count <= 10) {
            EX3_SEND_CODE(s, EX3_REPZ_3_10, s->bl_tree);
            EX3_SEND_BITS(s, count - 3, 3);
        } else {
            EX3_SEND_CODE(s, EX3_REPZ_11_138, s->bl_tree);
            EX3_SEND_BITS(s, count - 11, 7);
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

/* Clear the frequency counts for a new block (zlib init_block). Swing_DLL.xex 0x88873058 */
static EX3_NOINLINE void ex3_init_block_88873058(ex3_deflate_state *s)
{
    int n;

    for (n = 0; n < EX3_L_CODES; n++)
        s->dyn_ltree[n].fc = 0;
    for (n = 0; n < EX3_D_CODES; n++)
        s->dyn_dtree[n].fc = 0;
    for (n = 0; n < EX3_BL_CODES; n++)
        s->bl_tree[n].fc = 0;

    s->dyn_ltree[256].fc = 1;
    s->opt_len = s->static_len = 0L;
    s->last_lit = s->matches = 0;
}

/* Write a stored block's length header and copy its bytes into the pending buffer (zlib copy_block with
 * header always 1). Swing_DLL.xex 0x888730C0 */
static EX3_NOINLINE void ex3_copy_block_888730C0(ex3_deflate_state *s, unsigned char *buf, unsigned len)
{
    ex3_bi_windup_88871CF8(s);
    s->last_eob_len = 8;
    EX3_PUT_SHORT(s, (unsigned short)len);
    EX3_PUT_SHORT(s, (unsigned short)~len);
    while (len--) {
        EX3_PUT_BYTE(s, *buf++);
    }
}

/* Emit a stored (uncompressed) block header and its data (zlib _tr_stored_block).
 * Swing_DLL.xex 0x88873180 */
void ex3_tr_stored_block_88873180(ex3_deflate_state *s, unsigned char *buf, unsigned long stored_len, int eof)
{
    EX3_SEND_BITS(s, (0 << 1) + eof, 3);
    ex3_copy_block_888730C0(s, buf, (unsigned)stored_len);
}

/* Send the header of a dynamic block: code counts, bit-length code lengths and the two trees
 * (zlib send_all_trees). Swing_DLL.xex 0x88873208 */
static EX3_NOINLINE void ex3_send_all_trees_88873208(ex3_deflate_state *s, int lcodes, int dcodes, int blcodes)
{
    int rank;

    EX3_SEND_BITS(s, lcodes - 257, 5);
    EX3_SEND_BITS(s, dcodes - 1, 5);
    EX3_SEND_BITS(s, blcodes - 4, 4);
    for (rank = 0; rank < blcodes; rank++) {
        EX3_SEND_BITS(s, s->bl_tree[lbl_880C9D44[rank]].dl, 3);
    }
    ex3_send_tree_888725C0(s, s->dyn_ltree, lcodes - 1);
    ex3_send_tree_888725C0(s, s->dyn_dtree, dcodes - 1);
}

/* Construct one Huffman tree and assign code bit strings and lengths (zlib build_tree).
 * Swing_DLL.xex 0x888734C8 */
static EX3_NOINLINE void ex3_build_tree_888734C8(ex3_deflate_state *s, ex3_tree_desc *desc)
{
    ex3_ct_data *tree = desc->dyn_tree;
    const ex3_ct_data *stree = desc->stat_desc->static_tree;
    int elems = desc->stat_desc->elems;
    int n, m;
    int max_code = -1;
    int node;

    s->heap_len = 0, s->heap_max = EX3_HEAP_SIZE_;

    for (n = 0; n < elems; n++) {
        if (tree[n].fc != 0) {
            s->heap[++(s->heap_len)] = max_code = n;
            s->depth[n] = 0;
        } else {
            tree[n].dl = 0;
        }
    }

    while (s->heap_len < 2) {
        node = s->heap[++(s->heap_len)] = (max_code < 2 ? ++max_code : 0);
        tree[node].fc = 1;
        s->depth[node] = 0;
        s->opt_len--;
        if (stree)
            s->static_len -= stree[node].dl;
    }
    desc->max_code = max_code;

    for (n = s->heap_len / 2; n >= 1; n--)
        ex3_pqdownheap_88872F68(s, tree, n);

    node = elems;
    do {
        n = s->heap[EX3_SMALLEST];
        s->heap[EX3_SMALLEST] = s->heap[s->heap_len--];
        ex3_pqdownheap_88872F68(s, tree, EX3_SMALLEST);
        m = s->heap[EX3_SMALLEST];

        s->heap[--(s->heap_max)] = n;
        s->heap[--(s->heap_max)] = m;

        tree[node].fc = tree[n].fc + tree[m].fc;
        s->depth[node] = (unsigned char)((s->depth[n] >= s->depth[m] ? s->depth[n] : s->depth[m]) + 1);
        tree[n].dl = tree[m].dl = (unsigned short)node;
        s->heap[EX3_SMALLEST] = node++;
        ex3_pqdownheap_88872F68(s, tree, EX3_SMALLEST);
    } while (s->heap_len >= 2);

    s->heap[--(s->heap_max)] = s->heap[EX3_SMALLEST];

    ex3_gen_bitlen_88872D20(s, (ex3_tree_desc *)desc);
    ex3_gen_codes_88872C88((ex3_ct_data *)tree, max_code, s->bl_count);
}

/* Build the bit-length Huffman tree and find the last non-zero code length (zlib build_bl_tree);
 * returns the index of the last bit-length code to send. Swing_DLL.xex 0x88873770 */
static EX3_NOINLINE int ex3_build_bl_tree_88873770(ex3_deflate_state *s)
{
    int max_blindex;

    ex3_scan_tree_88872B58(s, s->dyn_ltree, s->l_desc.max_code);
    ex3_scan_tree_88872B58(s, s->dyn_dtree, s->d_desc.max_code);
    ex3_build_tree_888734C8(s, &(s->bl_desc));
    for (max_blindex = EX3_BL_CODES - 1; max_blindex >= 3; max_blindex--) {
        if (s->bl_tree[lbl_880C9D44[max_blindex]].dl != 0)
            break;
    }
    s->opt_len += 3 * (max_blindex + 1) + 5 + 5 + 4;
    return max_blindex;
}

/* Send the compressed block data using the given literal/length and distance trees (zlib compress_block).
 * Swing_DLL.xex 0x88871F08 */
static EX3_NOINLINE void ex3_compress_block_88871F08(ex3_deflate_state *s, const ex3_ct_data *ltree,
                                                     const ex3_ct_data *dtree)
{
    unsigned dist;
    int lc;
    unsigned lx = 0;
    unsigned code;
    int extra;

    if (s->last_lit != 0)
        do {
            dist = s->d_buf[lx];
            lc = s->l_buf[lx++];
            if (dist == 0) {
                EX3_SEND_CODE(s, lc, ltree);
            } else {
                code = lbl_880CA598[lc];
                EX3_SEND_CODE(s, code + 256 + 1, ltree);
                extra = ex3_extra_lbits_880C9D58[code];
                if (extra != 0) {
                    lc -= ex3_base_length_880CA698[code];
                    EX3_SEND_BITS(s, lc, extra);
                }
                dist--;
                code = (dist) < 256 ? lbl_880CA398[dist] : lbl_880CA398[256 + ((dist) >> 7)];
                EX3_SEND_CODE(s, code, dtree);
                extra = ex3_extra_dbits_880C9DD8[code];
                if (extra != 0) {
                    dist -= lbl_880CA710[code];
                    EX3_SEND_BITS(s, dist, extra);
                }
            }
        } while (lx < s->last_lit);

    EX3_SEND_CODE(s, 256, ltree);
    s->last_eob_len = ltree[256].dl;
}

/* zlib set_data_type (detect_data_type). The original compiler saw this function in the same translation unit
 * (it leaves r3 untouched), so a file-local copy with the identical name stands in for the one in
 * d1_big5_check_slots_empty_88871E38.c; the result is the same code. Swing_DLL.xex 0x88871E38 */
static EX3_NOINLINE void ts4_check_slots_empty_88871E38(ex3_deflate_state *s)
{
    int i;

    for (i = 0; i < 9; i++) {
        if (s->dyn_ltree[i].fc != 0) {
            break;
        }
    }
    if (i == 9) {
        for (i = 14; i < 32; i++) {
            if (s->dyn_ltree[i].fc != 0) {
                break;
            }
        }
    }
    s->strm->data_type = (i == 32);
}

/* Determine the best encoding for the current block (stored, static or dynamic trees) and write it out
 * (zlib _tr_flush_block). Swing_DLL.xex 0x88873870 */
void ex3_tr_flush_block_88873870(ex3_deflate_state *s, unsigned char *buf, unsigned long stored_len, int eof)
{
    unsigned long opt_lenb, static_lenb;
    int max_blindex;

    if (s->level > 0) {
        if (stored_len > 0 && s->strm->data_type == 2)
            ts4_check_slots_empty_88871E38(s);

        ex3_build_tree_888734C8(s, &(s->l_desc));
        ex3_build_tree_888734C8(s, &(s->d_desc));
        max_blindex = ex3_build_bl_tree_88873770(s);

        opt_lenb = (s->opt_len + 3 + 7) >> 3;
        static_lenb = (s->static_len + 3 + 7) >> 3;
        if (static_lenb <= opt_lenb)
            opt_lenb = static_lenb;
    } else {
        max_blindex = 0;
        opt_lenb = static_lenb = stored_len + 5;
    }

    if (stored_len + 4 <= opt_lenb && buf != (unsigned char *)0) {
        ex3_tr_stored_block_88873180(s, buf, stored_len, eof);
    } else if (s->strategy == 4 || static_lenb == opt_lenb) {
        EX3_SEND_BITS(s, (1 << 1) + eof, 3);
        ex3_compress_block_88871F08(s, ex3_static_ltree_880C9EA0, ex3_static_dtree_880CA320);
    } else {
        EX3_SEND_BITS(s, (2 << 1) + eof, 3);
        ex3_send_all_trees_88873208(s, s->l_desc.max_code + 1, s->d_desc.max_code + 1, max_blindex + 1);
        ex3_compress_block_88871F08(s, s->dyn_ltree, s->dyn_dtree);
    }
    ex3_init_block_88873058(s);
    if (eof) {
        ex3_bi_windup_88871CF8(s);
    }
}

/* Not part of the original: references the neighbouring constant tables so the compiler keeps them in the
 * object with the original spacing. Never matched against anything. */
int ex3_zlib_trees_layout_pin(void)
{
    return ex3_pad_880C9DCC[0] + ex3_extra_blbits_880C9E50[0] + ex3_pad_880CA398[0];
}
