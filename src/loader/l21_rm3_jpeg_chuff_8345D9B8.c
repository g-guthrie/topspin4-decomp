/* Loader_DLL.xex 0x8345D9B8-0x8345E130, executable version 0.0.0.3.
 * Statically linked libjpeg 6b routines. */

#include "l21_rm3_jpeg_8345D9B8.h"

enum {
    TS4L_JERR_HUFF_CLEN_OVERFLOW = 0x27
};

/* Builds an optimal Huffman table (code-length counts and symbol order) from
 * symbol frequencies, limiting codes to 16 bits */
void ts4l_jpeg_gen_optimal_table_8345D9B8(struct ts4l_jpeg_comp *cinfo, struct ts4l_jpeg_comp_huff_tbl *htbl,
                                         long freq[])
{
    unsigned char bits[32 + 1];
    int codesize[257];
    int others[257];
    int c1, c2;
    int p, i, j;
    long v;

    memset(bits, 0, sizeof(bits));
    memset(codesize, 0, sizeof(codesize));
    for (i = 0; i < 257; i++)
        others[i] = -1;

    freq[256] = 1;

    for (;;) {
        c1 = -1;
        v = 1000000000L;
        for (i = 0; i <= 256; i++) {
            if (freq[i] && freq[i] <= v) {
                v = freq[i];
                c1 = i;
            }
        }

        c2 = -1;
        v = 1000000000L;
        for (i = 0; i <= 256; i++) {
            if (freq[i] && freq[i] <= v && i != c1) {
                v = freq[i];
                c2 = i;
            }
        }

        if (c2 < 0)
            break;

        freq[c1] += freq[c2];
        freq[c2] = 0;

        codesize[c1]++;
        while (others[c1] >= 0) {
            c1 = others[c1];
            codesize[c1]++;
        }

        others[c1] = c2;

        codesize[c2]++;
        while (others[c2] >= 0) {
            c2 = others[c2];
            codesize[c2]++;
        }
    }

    for (i = 0; i <= 256; i++) {
        if (codesize[i]) {
            if (codesize[i] > 32)
                JPEG_ERREXIT(cinfo, TS4L_JERR_HUFF_CLEN_OVERFLOW);

            bits[codesize[i]]++;
        }
    }

    for (i = 32; i > 16; i--) {
        while (bits[i] > 0) {
            j = i - 2;
            while (bits[j] == 0)
                j--;

            bits[i] -= 2;
            bits[i - 1]++;
            bits[j + 1] += 2;
            bits[j]--;
        }
    }

    while (bits[i] == 0)
        i--;
    bits[i]--;

    memcpy(htbl->bits, bits, sizeof(htbl->bits));

    p = 0;
    for (i = 1; i <= 32; i++) {
        for (j = 0; j <= 255; j++) {
            if (codesize[j] == i) {
                htbl->huffval[p] = (unsigned char)j;
                p++;
            }
        }
    }

    htbl->sent_table = 0;
}

/* Huffman encoder private state; only the gathered frequency tables are used here. */
struct ts4l_jpeg_huff_entropy_enc {
    unsigned char reserved00[0x4c];
    long *dc_count_ptrs[4]; /* 0x4c */
    long *ac_count_ptrs[4]; /* 0x5c */
};

/* After a statistics-gathering pass, builds optimal DC and AC tables once per
 * table used by the scan */
void ts4l_jpeg_finish_pass_gather_8345DD00(struct ts4l_jpeg_comp *cinfo)
{
    struct ts4l_jpeg_huff_entropy_enc *entropy = (struct ts4l_jpeg_huff_entropy_enc *)cinfo->entropy;
    int ci, dctbl, actbl;
    struct ts4l_jpeg_component_info *compptr;
    struct ts4l_jpeg_comp_huff_tbl **htblptr;
    int did_dc[4];
    int did_ac[4];

    memset(did_dc, 0, sizeof(did_dc));
    memset(did_ac, 0, sizeof(did_ac));

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        dctbl = compptr->dc_tbl_no;
        actbl = compptr->ac_tbl_no;
        if (!did_dc[dctbl]) {
            htblptr = &cinfo->dc_huff_tbl_ptrs[dctbl];
            if (*htblptr == 0)
                *htblptr = ts4_get_u32_off4_8344E390(cinfo);
            ts4l_jpeg_gen_optimal_table_8345D9B8(cinfo, *htblptr, entropy->dc_count_ptrs[dctbl]);
            did_dc[dctbl] = 1;
        }
        if (!did_ac[actbl]) {
            htblptr = &cinfo->ac_huff_tbl_ptrs[actbl];
            if (*htblptr == 0)
                *htblptr = ts4_get_u32_off4_8344E390(cinfo);
            ts4l_jpeg_gen_optimal_table_8345D9B8(cinfo, *htblptr, entropy->ac_count_ptrs[actbl]);
            did_ac[actbl] = 1;
        }
    }
}
