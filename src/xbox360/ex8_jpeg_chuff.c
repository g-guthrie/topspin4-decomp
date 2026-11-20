/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b Huffman entropy encoder (jchuff.c). */
#include "ex8_jpeg.h"

extern const int lbl_88025F10[]; /* jpeg_natural_order */
int ts4_if_get_u32_off20_882FBD18(void *state); /* dump_buffer */
void ts4_jpeg_finish_pass_gather_882FC9D0(ex8_jcomp *cinfo);
int fn_882FC1D0(ex8_jcomp *cinfo, ex8_jblockrow *MCU_data); /* encode_mcu_huff */

enum {
    EX8_JERR_BAD_DCT_COEF = 6,
    EX8_JERR_BAD_HUFF_TABLE = 8,
    EX8_JERR_CANT_SUSPEND = 0x18,
    EX8_JERR_HUFF_MISSING_CODE = 0x28,
    EX8_JERR_NO_HUFF_TABLE = 0x32
};

typedef struct ex8_c_derived_tbl {
    unsigned int ehufco[256];  /* 0x000 */
    char ehufsi[256];          /* 0x400 */
} ex8_c_derived_tbl;

typedef struct ex8_savable_state {
    int put_buffer;       /* 0x00 */
    int put_bits;         /* 0x04 */
    int last_dc_val[4];   /* 0x08 */
} ex8_savable_state;

typedef struct ex8_working_state {
    ex8_joctet *next_output_byte; /* 0x00 */
    unsigned int free_in_buffer;  /* 0x04 */
    ex8_savable_state cur;        /* 0x08 */
    ex8_jcomp *cinfo;             /* 0x20 */
} ex8_working_state;

typedef struct ex8_huff_entropy {
    ex8_jcentropy pub;                         /* 0x00 */
    ex8_savable_state saved;                   /* 0x0c */
    unsigned int restarts_to_go;               /* 0x24 */
    int next_restart_num;                      /* 0x28 */
    ex8_c_derived_tbl *dc_derived_tbls[4];     /* 0x2c */
    ex8_c_derived_tbl *ac_derived_tbls[4];     /* 0x3c */
    long *dc_count_ptrs[4];                    /* 0x4c */
    long *ac_count_ptrs[4];                    /* 0x5c */
} ex8_huff_entropy;

/* Builds the encoder-side derived Huffman table (code and size per symbol). */
void ex8_jpeg_make_c_derived_tbl_882FBA80(ex8_jcomp *cinfo, int isDC, int tblno, ex8_c_derived_tbl **pdtbl)
{
    ex8_jhtbl *htbl;
    ex8_c_derived_tbl *dtbl;
    int p, i, l, lastp, si, maxsymbol;
    char huffsize[257];
    unsigned int huffcode[257];
    unsigned int code;

    if (tblno < 0 || tblno >= 4)
        EX8_ERREXIT1(cinfo, EX8_JERR_NO_HUFF_TABLE, tblno);
    htbl = isDC ? cinfo->dc_huff_tbl_ptrs[tblno] : cinfo->ac_huff_tbl_ptrs[tblno];
    if (htbl == 0)
        EX8_ERREXIT1(cinfo, EX8_JERR_NO_HUFF_TABLE, tblno);

    if (*pdtbl == 0)
        *pdtbl = (ex8_c_derived_tbl *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_c_derived_tbl));
    dtbl = *pdtbl;

    p = 0;
    for (l = 1; l <= 16; l++) {
        i = (int)htbl->bits[l];
        if (i < 0 || p + i > 256)
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_HUFF_TABLE);
        while (i--)
            huffsize[p++] = (char)l;
    }
    huffsize[p] = 0;
    lastp = p;

    code = 0;
    si = huffsize[0];
    p = 0;
    while (huffsize[p]) {
        while (((int)huffsize[p]) == si) {
            huffcode[p++] = code;
            code++;
        }
        if (((int)code) >= (((int)1) << si))
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_HUFF_TABLE);
        code <<= 1;
        si++;
    }

    memset(dtbl->ehufsi, 0, sizeof(dtbl->ehufsi));

    maxsymbol = isDC ? 15 : 255;
    for (p = 0; p < lastp; p++) {
        i = htbl->huffval[p];
        if (i < 0 || i > maxsymbol || dtbl->ehufsi[i])
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_HUFF_TABLE);
        dtbl->ehufco[i] = huffcode[p];
        dtbl->ehufsi[i] = huffsize[p];
    }
}

/* Appends bits to the output bit buffer, stuffing zero after 0xFF; 0 means suspend. */
int ex8_emit_bits_882FBD78(ex8_working_state *state, unsigned int code, int size)
{
    int put_buffer = (int)code;
    int put_bits = state->cur.put_bits;

    if (size == 0)
        EX8_ERREXIT(state->cinfo, EX8_JERR_HUFF_MISSING_CODE);

    put_buffer &= (((int)1) << size) - 1;
    put_bits += size;
    put_buffer <<= 24 - put_bits;
    put_buffer |= state->cur.put_buffer;

    while (put_bits >= 8) {
        int c = (int)((put_buffer >> 16) & 0xFF);

        *state->next_output_byte++ = (ex8_joctet)c;
        if (--state->free_in_buffer == 0) {
            ex8_jdest *dest = state->cinfo->dest;
            if (!(*dest->empty_output_buffer)(state->cinfo))
                return 0;
            state->next_output_byte = dest->next_output_byte;
            state->free_in_buffer = dest->free_in_buffer;
        }
        if (c == 0xFF) {
            *state->next_output_byte++ = 0;
            if (--state->free_in_buffer == 0) {
                ex8_jdest *dest = state->cinfo->dest;
                if (!(*dest->empty_output_buffer)(state->cinfo))
                    return 0;
                state->next_output_byte = dest->next_output_byte;
                state->free_in_buffer = dest->free_in_buffer;
            }
        }
        put_buffer <<= 8;
        put_bits -= 8;
    }

    state->cur.put_buffer = put_buffer;
    state->cur.put_bits = put_bits;
    return 1;
}

/* Huffman-encodes one 8x8 block of quantized coefficients. */
int ex8_encode_one_block_882FBED0(ex8_working_state *state, ex8_jcoef *block, int last_dc_val,
                                  ex8_c_derived_tbl *dctbl, ex8_c_derived_tbl *actbl)
{
    int temp, temp2;
    int nbits;
    int k, r, i;

    temp = temp2 = block[0] - last_dc_val;
    if (temp < 0) {
        temp = -temp;
        temp2--;
    }

    nbits = 0;
    while (temp) {
        nbits++;
        temp >>= 1;
    }
    if (nbits > 11)
        EX8_ERREXIT(state->cinfo, EX8_JERR_BAD_DCT_COEF);

    if (!ex8_emit_bits_882FBD78(state, dctbl->ehufco[nbits], dctbl->ehufsi[nbits]))
        return 0;
    if (nbits)
        if (!ex8_emit_bits_882FBD78(state, (unsigned int)temp2, nbits))
            return 0;

    r = 0;
    for (k = 1; k < 64; k++) {
        if ((temp = block[lbl_88025F10[k]]) == 0) {
            r++;
        } else {
            while (r > 15) {
                if (!ex8_emit_bits_882FBD78(state, actbl->ehufco[0xF0], actbl->ehufsi[0xF0]))
                    return 0;
                r -= 16;
            }
            temp2 = temp;
            if (temp < 0) {
                temp = -temp;
                temp2--;
            }
            nbits = 1;
            while ((temp >>= 1))
                nbits++;
            if (nbits > 10)
                EX8_ERREXIT(state->cinfo, EX8_JERR_BAD_DCT_COEF);
            i = (r << 4) + nbits;
            if (!ex8_emit_bits_882FBD78(state, actbl->ehufco[i], actbl->ehufsi[i]))
                return 0;
            if (!ex8_emit_bits_882FBD78(state, (unsigned int)temp2, nbits))
                return 0;
            r = 0;
        }
    }

    if (r > 0)
        if (!ex8_emit_bits_882FBD78(state, actbl->ehufco[0], actbl->ehufsi[0]))
            return 0;
    return 1;
}

/* Pads the bit buffer with ones and empties it. */
static int ex8_flush_bits(ex8_working_state *state)
{
    if (!ex8_emit_bits_882FBD78(state, 0x7F, 7))
        return 0;
    state->cur.put_buffer = 0;
    state->cur.put_bits = 0;
    return 1;
}

/* Flushes the bit buffer and writes an RSTn marker; resets the DC predictions. */
int ex8_emit_restart_882FC0E0(ex8_working_state *state, int restart_num)
{
    int ci;

    if (!ex8_flush_bits(state))
        return 0;

    *state->next_output_byte++ = 0xFF;
    if (--state->free_in_buffer == 0)
        if (!ts4_if_get_u32_off20_882FBD18(state))
            return 0;
    *state->next_output_byte++ = (ex8_joctet)(0xD0 + restart_num);
    if (--state->free_in_buffer == 0)
        if (!ts4_if_get_u32_off20_882FBD18(state))
            return 0;

    for (ci = 0; ci < state->cinfo->comps_in_scan; ci++)
        state->cur.last_dc_val[ci] = 0;
    return 1;
}

/* Flushes the final bits of the scan. */
void ex8_finish_pass_huff_882FC360(ex8_jcomp *cinfo)
{
    ex8_huff_entropy *entropy = (ex8_huff_entropy *)cinfo->entropy;
    ex8_working_state state;

    state.next_output_byte = cinfo->dest->next_output_byte;
    state.free_in_buffer = cinfo->dest->free_in_buffer;
    state.cur = entropy->saved;
    state.cinfo = cinfo;

    if (!ex8_flush_bits(&state))
        EX8_ERREXIT(cinfo, EX8_JERR_CANT_SUSPEND);
    cinfo->dest->next_output_byte = state.next_output_byte;
    cinfo->dest->free_in_buffer = state.free_in_buffer;
    entropy->saved = state.cur;
}

/* Counts the Huffman symbols one block would produce (optimal-table pass). */
static void ex8_htest_one_block(ex8_jcomp *cinfo, ex8_jcoef *block, int last_dc_val, long *dc_counts,
                                long *ac_counts)
{
    int temp;
    int nbits;
    int k, r;

    temp = block[0] - last_dc_val;
    if (temp < 0)
        temp = -temp;

    nbits = 0;
    while (temp) {
        nbits++;
        temp >>= 1;
    }
    if (nbits > 11)
        EX8_ERREXIT(cinfo, EX8_JERR_BAD_DCT_COEF);
    dc_counts[nbits]++;

    r = 0;
    for (k = 1; k < 64; k++) {
        if ((temp = block[lbl_88025F10[k]]) == 0) {
            r++;
        } else {
            while (r > 15) {
                ac_counts[0xF0]++;
                r -= 16;
            }
            if (temp < 0)
                temp = -temp;
            nbits = 1;
            while ((temp >>= 1))
                nbits++;
            if (nbits > 10)
                EX8_ERREXIT(cinfo, EX8_JERR_BAD_DCT_COEF);
            ac_counts[(r << 4) + nbits]++;
            r = 0;
        }
    }
    if (r > 0)
        ac_counts[0]++;
}

/* Gathers symbol statistics for one MCU. */
int ex8_encode_mcu_gather_882FC448(ex8_jcomp *cinfo, ex8_jblockrow *MCU_data)
{
    ex8_huff_entropy *entropy = (ex8_huff_entropy *)cinfo->entropy;
    int blkn, ci;
    ex8_jcinfo *compptr;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0) {
            for (ci = 0; ci < cinfo->comps_in_scan; ci++)
                entropy->saved.last_dc_val[ci] = 0;
            entropy->restarts_to_go = cinfo->restart_interval;
        }
        entropy->restarts_to_go--;
    }

    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
        ci = cinfo->MCU_membership[blkn];
        compptr = cinfo->cur_comp_info[ci];
        ex8_htest_one_block(cinfo, MCU_data[blkn][0], entropy->saved.last_dc_val[ci],
                            entropy->dc_count_ptrs[compptr->dc_tbl_no],
                            entropy->ac_count_ptrs[compptr->ac_tbl_no]);
        entropy->saved.last_dc_val[ci] = MCU_data[blkn][0][0];
    }
    return 1;
}

/* Prepares Huffman encoding or statistics gathering for a scan. */
void ex8_start_pass_huff_882FCE00(ex8_jcomp *cinfo, int gather_statistics)
{
    ex8_huff_entropy *entropy = (ex8_huff_entropy *)cinfo->entropy;
    int ci, dctbl, actbl;
    ex8_jcinfo *compptr;

    if (gather_statistics) {
        entropy->pub.encode_mcu = ex8_encode_mcu_gather_882FC448;
        entropy->pub.finish_pass = ts4_jpeg_finish_pass_gather_882FC9D0;
    } else {
        entropy->pub.encode_mcu = fn_882FC1D0;
        entropy->pub.finish_pass = ex8_finish_pass_huff_882FC360;
    }

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        dctbl = compptr->dc_tbl_no;
        actbl = compptr->ac_tbl_no;
        if (gather_statistics) {
            if (dctbl < 0 || dctbl >= 4)
                EX8_ERREXIT1(cinfo, EX8_JERR_NO_HUFF_TABLE, dctbl);
            if (actbl < 0 || actbl >= 4)
                EX8_ERREXIT1(cinfo, EX8_JERR_NO_HUFF_TABLE, actbl);
            if (entropy->dc_count_ptrs[dctbl] == 0)
                entropy->dc_count_ptrs[dctbl] = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 257 * sizeof(long));
            memset(entropy->dc_count_ptrs[dctbl], 0, 257 * sizeof(long));
            if (entropy->ac_count_ptrs[actbl] == 0)
                entropy->ac_count_ptrs[actbl] = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 257 * sizeof(long));
            memset(entropy->ac_count_ptrs[actbl], 0, 257 * sizeof(long));
        } else {
            ex8_jpeg_make_c_derived_tbl_882FBA80(cinfo, 1, dctbl, &entropy->dc_derived_tbls[dctbl]);
            ex8_jpeg_make_c_derived_tbl_882FBA80(cinfo, 0, actbl, &entropy->ac_derived_tbls[actbl]);
        }
        entropy->saved.last_dc_val[ci] = 0;
    }

    entropy->saved.put_buffer = 0;
    entropy->saved.put_bits = 0;
    entropy->restarts_to_go = cinfo->restart_interval;
    entropy->next_restart_num = 0;
}

/* Allocates the Huffman entropy encoder. */
void ex8_jinit_huff_encoder_882FCFE0(ex8_jcomp *cinfo)
{
    ex8_huff_entropy *entropy;
    int i;

    entropy = (ex8_huff_entropy *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_huff_entropy));
    cinfo->entropy = &entropy->pub;
    entropy->pub.start_pass = ex8_start_pass_huff_882FCE00;

    for (i = 0; i < 4; i++) {
        entropy->dc_derived_tbls[i] = entropy->ac_derived_tbls[i] = 0;
        entropy->dc_count_ptrs[i] = entropy->ac_count_ptrs[i] = 0;
    }
}
