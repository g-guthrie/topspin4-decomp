/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b progressive Huffman entropy encoder (jcphuff.c). */
#include "ex8_jpeg.h"

extern const int lbl_88025F10[]; /* jpeg_natural_order */
void ts4_if_get_u32_off20_882FD058(void *entropy);        /* dump_buffer */
void ts4_call_seq_u32_off18_882FDE30(ex8_jcomp *cinfo);   /* finish_pass_phuff */
int ts4_jpeg_encode_mcu_AC_refine_882FDB30(ex8_jcomp *cinfo, ex8_jblockrow *MCU_data);
void ts4_jpeg_gen_optimal_table_882FC688(ex8_jcomp *cinfo, ex8_jhtbl *htbl, long *freq);
ex8_jhtbl *ts4_get_u32_off4_882EDE88(ex8_jcomp *cinfo); /* jpeg_alloc_huff_table */

enum {
    EX8_JERR_BAD_DCT_COEF = 6,
    EX8_JERR_HUFF_MISSING_CODE = 0x28,
    EX8_JERR_NO_HUFF_TABLE = 0x32
};

typedef struct ex8_c_derived_tbl {
    unsigned int ehufco[256];  /* 0x000 */
    char ehufsi[256];          /* 0x400 */
} ex8_c_derived_tbl;

typedef struct ex8_phuff_entropy {
    ex8_jcentropy pub;                      /* 0x00 */
    int gather_statistics;                  /* 0x0c */
    ex8_joctet *next_output_byte;           /* 0x10 */
    unsigned int free_in_buffer;            /* 0x14 */
    int put_buffer;                         /* 0x18 */
    int put_bits;                           /* 0x1c */
    ex8_jcomp *cinfo;                       /* 0x20 */
    int last_dc_val[4];                     /* 0x24 */
    int ac_tbl_no;                          /* 0x34 */
    unsigned int EOBRUN;                    /* 0x38 */
    unsigned int BE;                        /* 0x3c */
    char *bit_buffer;                       /* 0x40 */
    unsigned int restarts_to_go;            /* 0x44 */
    int next_restart_num;                   /* 0x48 */
    ex8_c_derived_tbl *derived_tbls[4];     /* 0x4c */
    long *count_ptrs[4];                    /* 0x5c */
} ex8_phuff_entropy;

/* dump_buffer expanded in place (the original inlines it at some call sites only). */
#define EX8_DUMP_INLINE(entropy)                                                    \
    do {                                                                            \
        ex8_jdest *dest_ = (entropy)->cinfo->dest;                                  \
        if (!(*dest_->empty_output_buffer)((entropy)->cinfo))                       \
            EX8_ERREXIT((entropy)->cinfo, 0x18);                                    \
        (entropy)->next_output_byte = dest_->next_output_byte;                      \
        (entropy)->free_in_buffer = dest_->free_in_buffer;                          \
    } while (0)

void ex8_jpeg_make_c_derived_tbl_882FBA80(ex8_jcomp *cinfo, int isDC, int tblno, ex8_c_derived_tbl **pdtbl);

/* Appends bits to the output bit buffer (no-op while gathering statistics). */
void ex8_emit_bits_882FD0D8(ex8_phuff_entropy *entropy, unsigned int code, int size)
{
    int put_buffer = (int)code;
    int put_bits = entropy->put_bits;

    if (size == 0)
        EX8_ERREXIT(entropy->cinfo, EX8_JERR_HUFF_MISSING_CODE);

    if (entropy->gather_statistics)
        return;

    put_buffer &= (((int)1) << size) - 1;
    put_bits += size;
    put_buffer <<= 24 - put_bits;
    put_buffer |= entropy->put_buffer;

    while (put_bits >= 8) {
        int c = (int)((put_buffer >> 16) & 0xFF);

        *entropy->next_output_byte++ = (ex8_joctet)c;
        if (--entropy->free_in_buffer == 0)
            EX8_DUMP_INLINE(entropy);
        if (c == 0xFF) {
            *entropy->next_output_byte++ = 0;
            if (--entropy->free_in_buffer == 0)
                ts4_if_get_u32_off20_882FD058(entropy);
        }
        put_buffer <<= 8;
        put_bits -= 8;
    }

    entropy->put_buffer = put_buffer;
    entropy->put_bits = put_bits;
}

/* Counts or emits one Huffman symbol. */
static void ex8_emit_symbol(ex8_phuff_entropy *entropy, int tbl_no, int symbol)
{
    if (entropy->gather_statistics) {
        entropy->count_ptrs[tbl_no][symbol]++;
    } else {
        ex8_c_derived_tbl *tbl = entropy->derived_tbls[tbl_no];
        ex8_emit_bits_882FD0D8(entropy, tbl->ehufco[symbol], tbl->ehufsi[symbol]);
    }
}

/* Emits buffered correction bits, one bit per byte. */
void ex8_emit_buffered_bits_882FD238(ex8_phuff_entropy *entropy, char *bufstart, unsigned int nbits)
{
    if (entropy->gather_statistics)
        return;

    while (nbits > 0) {
        int put_buffer;
        int put_bits;

        if (entropy->gather_statistics)
            goto next;
        put_buffer = ((int)(unsigned int)(*bufstart)) & 1;
        put_bits = entropy->put_bits;
        put_bits += 1;
        put_buffer <<= 24 - put_bits;
        put_buffer |= entropy->put_buffer;
        while (put_bits >= 8) {
            int c = (int)((put_buffer >> 16) & 0xFF);

            *entropy->next_output_byte++ = (ex8_joctet)c;
            if (--entropy->free_in_buffer == 0)
                EX8_DUMP_INLINE(entropy);
            if (c == 0xFF) {
                *entropy->next_output_byte++ = 0;
                if (--entropy->free_in_buffer == 0)
                    EX8_DUMP_INLINE(entropy);
            }
            put_buffer <<= 8;
            put_bits -= 8;
        }
        entropy->put_buffer = put_buffer;
        entropy->put_bits = put_bits;
    next:
        bufstart++;
        nbits--;
    }
}

/* Emits any pending end-of-band run and its buffered correction bits. */
void ex8_emit_eobrun_882FD3C8(ex8_phuff_entropy *entropy)
{
    int temp, nbits;

    if (entropy->EOBRUN > 0) {
        temp = entropy->EOBRUN;
        nbits = 0;
        while ((temp >>= 1))
            nbits++;
        if (nbits > 14)
            EX8_ERREXIT(entropy->cinfo, EX8_JERR_HUFF_MISSING_CODE);

        ex8_emit_symbol(entropy, entropy->ac_tbl_no, nbits << 4);
        if (nbits)
            ex8_emit_bits_882FD0D8(entropy, entropy->EOBRUN, nbits);

        entropy->EOBRUN = 0;
        ex8_emit_buffered_bits_882FD238(entropy, entropy->bit_buffer, entropy->BE);
        entropy->BE = 0;
    }
}

/* Emits an RSTn marker and resets the per-restart state. */
void ex8_emit_restart_882FD4C0(ex8_phuff_entropy *entropy, int restart_num)
{
    int ci;

    ex8_emit_eobrun_882FD3C8(entropy);

    if (!entropy->gather_statistics) {
        ex8_emit_bits_882FD0D8(entropy, 0x7F, 7);
        entropy->put_buffer = 0;
        entropy->put_bits = 0;
        *entropy->next_output_byte++ = 0xFF;
        if (--entropy->free_in_buffer == 0)
            ts4_if_get_u32_off20_882FD058(entropy);
        *entropy->next_output_byte++ = (ex8_joctet)(0xD0 + restart_num);
        if (--entropy->free_in_buffer == 0)
            ts4_if_get_u32_off20_882FD058(entropy);
    }

    if (entropy->cinfo->Ss == 0) {
        for (ci = 0; ci < entropy->cinfo->comps_in_scan; ci++)
            entropy->last_dc_val[ci] = 0;
    } else {
        entropy->EOBRUN = 0;
        entropy->BE = 0;
    }
}

/* Encodes one MCU's DC coefficients for the first DC scan of a progressive file. */
int ex8_encode_mcu_DC_first_882FD5B8(ex8_jcomp *cinfo, ex8_jblockrow *MCU_data)
{
    ex8_phuff_entropy *entropy = (ex8_phuff_entropy *)cinfo->entropy;
    int temp, temp2;
    int nbits;
    int blkn, ci;
    int Al = cinfo->Al;
    ex8_jblockrow block;
    ex8_jcinfo *compptr;

    entropy->next_output_byte = cinfo->dest->next_output_byte;
    entropy->free_in_buffer = cinfo->dest->free_in_buffer;

    if (cinfo->restart_interval)
        if (entropy->restarts_to_go == 0)
            ex8_emit_restart_882FD4C0(entropy, entropy->next_restart_num);

    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
        block = MCU_data[blkn];
        ci = cinfo->MCU_membership[blkn];
        compptr = cinfo->cur_comp_info[ci];

        temp2 = (int)((*block)[0]) >> Al;
        temp = temp2 - entropy->last_dc_val[ci];
        entropy->last_dc_val[ci] = temp2;

        temp2 = temp;
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
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_DCT_COEF);

        ex8_emit_symbol(entropy, compptr->dc_tbl_no, nbits);
        if (nbits)
            ex8_emit_bits_882FD0D8(entropy, (unsigned int)temp2, nbits);
    }

    cinfo->dest->next_output_byte = entropy->next_output_byte;
    cinfo->dest->free_in_buffer = entropy->free_in_buffer;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0) {
            entropy->restarts_to_go = cinfo->restart_interval;
            entropy->next_restart_num++;
            entropy->next_restart_num &= 7;
        }
        entropy->restarts_to_go--;
    }
    return 1;
}

/* Encodes one block's AC coefficients for the first AC scan of a band. */
int ex8_encode_mcu_AC_first_882FD798(ex8_jcomp *cinfo, ex8_jblockrow *MCU_data)
{
    ex8_phuff_entropy *entropy = (ex8_phuff_entropy *)cinfo->entropy;
    int temp, temp2;
    int nbits;
    int r, k;
    int Se = cinfo->Se;
    int Al = cinfo->Al;
    ex8_jblockrow block;

    entropy->next_output_byte = cinfo->dest->next_output_byte;
    entropy->free_in_buffer = cinfo->dest->free_in_buffer;

    if (cinfo->restart_interval)
        if (entropy->restarts_to_go == 0)
            ex8_emit_restart_882FD4C0(entropy, entropy->next_restart_num);

    block = MCU_data[0];

    r = 0;
    for (k = cinfo->Ss; k <= Se; k++) {
        if ((temp = (*block)[lbl_88025F10[k]]) == 0) {
            r++;
            continue;
        }
        if (temp < 0) {
            temp = -temp;
            temp >>= Al;
            temp2 = ~temp;
        } else {
            temp >>= Al;
            temp2 = temp;
        }
        if (temp == 0) {
            r++;
            continue;
        }

        if (entropy->EOBRUN > 0)
            ex8_emit_eobrun_882FD3C8(entropy);

        while (r > 15) {
            ex8_emit_symbol(entropy, entropy->ac_tbl_no, 0xF0);
            r -= 16;
        }

        nbits = 1;
        while ((temp >>= 1))
            nbits++;
        if (nbits > 10)
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_DCT_COEF);

        ex8_emit_symbol(entropy, entropy->ac_tbl_no, (r << 4) + nbits);
        ex8_emit_bits_882FD0D8(entropy, (unsigned int)temp2, nbits);

        r = 0;
    }

    if (r > 0) {
        entropy->EOBRUN++;
        if (entropy->EOBRUN == 0x7FFF)
            ex8_emit_eobrun_882FD3C8(entropy);
    }

    cinfo->dest->next_output_byte = entropy->next_output_byte;
    cinfo->dest->free_in_buffer = entropy->free_in_buffer;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0) {
            entropy->restarts_to_go = cinfo->restart_interval;
            entropy->next_restart_num++;
            entropy->next_restart_num &= 7;
        }
        entropy->restarts_to_go--;
    }
    return 1;
}

/* Emits the Al'th bit of each DC coefficient (DC refinement scan). */
int ex8_encode_mcu_DC_refine_882FDA30(ex8_jcomp *cinfo, ex8_jblockrow *MCU_data)
{
    ex8_phuff_entropy *entropy = (ex8_phuff_entropy *)cinfo->entropy;
    int temp;
    int blkn;
    int Al = cinfo->Al;
    ex8_jblockrow block;

    entropy->next_output_byte = cinfo->dest->next_output_byte;
    entropy->free_in_buffer = cinfo->dest->free_in_buffer;

    if (cinfo->restart_interval)
        if (entropy->restarts_to_go == 0)
            ex8_emit_restart_882FD4C0(entropy, entropy->next_restart_num);

    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
        block = MCU_data[blkn];
        temp = (*block)[0];
        ex8_emit_bits_882FD0D8(entropy, (unsigned int)(temp >> Al), 1);
    }

    cinfo->dest->next_output_byte = entropy->next_output_byte;
    cinfo->dest->free_in_buffer = entropy->free_in_buffer;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0) {
            entropy->restarts_to_go = cinfo->restart_interval;
            entropy->next_restart_num++;
            entropy->next_restart_num &= 7;
        }
        entropy->restarts_to_go--;
    }
    return 1;
}

/* Builds optimal Huffman tables from the statistics of a progressive scan. */
void ex8_finish_pass_gather_phuff_882FDEB8(ex8_jcomp *cinfo)
{
    ex8_phuff_entropy *entropy = (ex8_phuff_entropy *)cinfo->entropy;
    int is_DC_band;
    int ci, tbl;
    ex8_jcinfo *compptr;
    ex8_jhtbl **htblptr;
    int did[4];

    ex8_emit_eobrun_882FD3C8(entropy);

    is_DC_band = (cinfo->Ss == 0);

    memset(did, 0, sizeof(did));

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        if (is_DC_band) {
            if (cinfo->Ah != 0)
                continue;
            tbl = compptr->dc_tbl_no;
        } else {
            tbl = compptr->ac_tbl_no;
        }
        if (!did[tbl]) {
            if (is_DC_band)
                htblptr = &cinfo->dc_huff_tbl_ptrs[tbl];
            else
                htblptr = &cinfo->ac_huff_tbl_ptrs[tbl];
            if (*htblptr == 0)
                *htblptr = ts4_get_u32_off4_882EDE88(cinfo);
            ts4_jpeg_gen_optimal_table_882FC688(cinfo, *htblptr, entropy->count_ptrs[tbl]);
            did[tbl] = 1;
        }
    }
}

/* Prepares progressive Huffman encoding or statistics gathering for a scan. */
void ex8_start_pass_phuff_882FDFA8(ex8_jcomp *cinfo, int gather_statistics)
{
    ex8_phuff_entropy *entropy = (ex8_phuff_entropy *)cinfo->entropy;
    int is_DC_band;
    int ci, tbl;
    ex8_jcinfo *compptr;

    entropy->cinfo = cinfo;
    entropy->gather_statistics = gather_statistics;

    is_DC_band = (cinfo->Ss == 0);

    if (cinfo->Ah == 0) {
        if (is_DC_band)
            entropy->pub.encode_mcu = ex8_encode_mcu_DC_first_882FD5B8;
        else
            entropy->pub.encode_mcu = ex8_encode_mcu_AC_first_882FD798;
    } else {
        if (is_DC_band) {
            entropy->pub.encode_mcu = ex8_encode_mcu_DC_refine_882FDA30;
        } else {
            entropy->pub.encode_mcu = ts4_jpeg_encode_mcu_AC_refine_882FDB30;
            if (entropy->bit_buffer == 0)
                entropy->bit_buffer = (char *)(*cinfo->mem->alloc_small)(cinfo, 1, 1000 * sizeof(char));
        }
    }

    if (gather_statistics)
        entropy->pub.finish_pass = ex8_finish_pass_gather_phuff_882FDEB8;
    else
        entropy->pub.finish_pass = ts4_call_seq_u32_off18_882FDE30;

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        entropy->last_dc_val[ci] = 0;
        if (is_DC_band) {
            if (cinfo->Ah != 0)
                continue;
            tbl = compptr->dc_tbl_no;
        } else {
            entropy->ac_tbl_no = tbl = compptr->ac_tbl_no;
        }
        if (gather_statistics) {
            if (tbl < 0 || tbl >= 4)
                EX8_ERREXIT1(cinfo, EX8_JERR_NO_HUFF_TABLE, tbl);
            if (entropy->count_ptrs[tbl] == 0)
                entropy->count_ptrs[tbl] = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 257 * sizeof(long));
            memset(entropy->count_ptrs[tbl], 0, 257 * sizeof(long));
        } else {
            ex8_jpeg_make_c_derived_tbl_882FBA80(cinfo, is_DC_band, tbl, &entropy->derived_tbls[tbl]);
        }
    }

    entropy->EOBRUN = 0;
    entropy->BE = 0;
    entropy->put_buffer = 0;
    entropy->put_bits = 0;
    entropy->restarts_to_go = cinfo->restart_interval;
    entropy->next_restart_num = 0;
}

/* Allocates the progressive Huffman entropy encoder. */
void ex8_jinit_phuff_encoder_882FE1A0(ex8_jcomp *cinfo)
{
    ex8_phuff_entropy *entropy;
    int i;

    entropy = (ex8_phuff_entropy *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_phuff_entropy));
    cinfo->entropy = &entropy->pub;
    entropy->pub.start_pass = ex8_start_pass_phuff_882FDFA8;

    for (i = 0; i < 4; i++) {
        entropy->derived_tbls[i] = 0;
        entropy->count_ptrs[i] = 0;
    }
    entropy->bit_buffer = 0;
}
