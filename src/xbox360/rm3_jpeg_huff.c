/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG Huffman entropy decoder tables (IJG libjpeg jdhuff.c style), Swing_DLL.xex
 * auto_03_882F5CEC. (RM3) */
#include "rm3_jpeg.h"

/* Derived decoding table for one Huffman table (IJG d_derived_tbl). */
struct ts4_jpeg_d_derived_tbl {
    int maxcode[18];                 /* 0x000 */
    int valoffset[17];               /* 0x048 */
    struct ts4_jpeg_huff_tbl *pub;   /* 0x08c */
    int look_nbits[256];             /* 0x090 */
    unsigned char look_sym[256];     /* 0x490 */
};

enum {
    TS4_JERR_BAD_HUFF_TABLE_D = 0x08,
    TS4_JERR_NO_HUFF_TABLE_D = 0x32
};

/* Expands a DHT table into maxcode/valoffset arrays and the 8-bit lookahead
 * tables used by the Huffman decoder (Swing_DLL.xex 0x882F6F20). */
void ts4_jpeg_make_d_derived_tbl_882F6F20(struct ts4_jpeg_decomp *cinfo, int isDC, int tblno,
                                          struct ts4_jpeg_d_derived_tbl **pdtbl)
{
    struct ts4_jpeg_huff_tbl *htbl;
    struct ts4_jpeg_d_derived_tbl *dtbl;
    int p, i, l, si, numsymbols;
    int lookbits, ctr;
    char huffsize[257];
    unsigned int huffcode[257];
    unsigned int code;

    if (tblno < 0 || tblno >= 4)
        JPEG_ERREXIT1(cinfo, TS4_JERR_NO_HUFF_TABLE_D, tblno);
    htbl = isDC ? cinfo->dc_huff_tbl_ptrs[tblno] : cinfo->ac_huff_tbl_ptrs[tblno];
    if (htbl == 0)
        JPEG_ERREXIT1(cinfo, TS4_JERR_NO_HUFF_TABLE_D, tblno);

    if (*pdtbl == 0)
        *pdtbl = (struct ts4_jpeg_d_derived_tbl *)(*cinfo->mem->alloc_small)(
            cinfo, 1, sizeof(struct ts4_jpeg_d_derived_tbl));
    dtbl = *pdtbl;
    dtbl->pub = htbl;

    p = 0;
    for (l = 1; l <= 16; l++) {
        i = (int)htbl->bits[l];
        if (i < 0 || p + i > 256)
            JPEG_ERREXIT(cinfo, TS4_JERR_BAD_HUFF_TABLE_D);
        while (i--)
            huffsize[p++] = (char)l;
    }
    huffsize[p] = 0;
    numsymbols = p;

    code = 0;
    si = huffsize[0];
    p = 0;
    while (huffsize[p]) {
        while (((int)huffsize[p]) == si) {
            huffcode[p++] = code;
            code++;
        }
        if (((int)code) >= (((int)1) << si))
            JPEG_ERREXIT(cinfo, TS4_JERR_BAD_HUFF_TABLE_D);
        code <<= 1;
        si++;
    }

    p = 0;
    for (l = 1; l <= 16; l++) {
        if (htbl->bits[l]) {
            dtbl->valoffset[l] = (int)p - (int)huffcode[p];
            p += htbl->bits[l];
            dtbl->maxcode[l] = huffcode[p - 1];
        } else {
            dtbl->maxcode[l] = -1;
        }
    }
    dtbl->maxcode[17] = 0xFFFFFL;

    memset(dtbl->look_nbits, 0, sizeof(dtbl->look_nbits));

    p = 0;
    for (l = 1; l <= 8; l++) {
        for (i = 1; i <= (int)htbl->bits[l]; i++, p++) {
            lookbits = huffcode[p] << (8 - l);
            for (ctr = 1 << (8 - l); ctr > 0; ctr--) {
                dtbl->look_nbits[lookbits] = l;
                dtbl->look_sym[lookbits] = htbl->huffval[p];
                lookbits++;
            }
        }
    }

    if (isDC) {
        for (i = 0; i < numsymbols; i++) {
            int sym = htbl->huffval[i];
            if (sym < 0 || sym > 15)
                JPEG_ERREXIT(cinfo, TS4_JERR_BAD_HUFF_TABLE_D);
        }
    }
}
