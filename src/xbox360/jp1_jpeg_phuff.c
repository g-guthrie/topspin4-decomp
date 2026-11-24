/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG progressive Huffman entropy decoder, IJG jdphuff.c style. (JP1) */
#include "jp1_jpeg.h"

enum { JP1_JERR_BAD_PROGRESSION = 0x10, JP1_JWRN_BOGUS_PROGRESSION = 0x73, JP1_JWRN_HUFF_BAD_CODE = 0x76 };

/* Savable decoder state: pending EOB run and DC predictors. */
struct ts4_jpeg_phuff_saved {
    unsigned int EOBRUN;
    int last_dc_val[4];
};

/* Progressive Huffman entropy decoder private state (jdphuff.c phuff_entropy_decoder). */
struct ts4_jpeg_phuff_entropy {
    void (*start_pass)(struct ts4_jpeg_decomp *cinfo);                        /* 0x00 */
    int (*decode_mcu)(struct ts4_jpeg_decomp *cinfo, ts4_jblock **MCU_data);  /* 0x04 */
    int insufficient_data;                                                    /* 0x08 */
    struct ts4_jpeg_bitread_perm_state bitstate;                              /* 0x0c */
    struct ts4_jpeg_phuff_saved saved;                                        /* 0x14 */
    unsigned int restarts_to_go;                                              /* 0x28 */
    struct ts4_jpeg_d_derived_tbl *derived_tbls[4];                           /* 0x2c */
    struct ts4_jpeg_d_derived_tbl *ac_derived_tbl;                            /* 0x3c */
};

int ts4_jpeg_fill_bit_buffer_882F7288(struct ts4_jpeg_bitread_working_state *state, int get_buffer,
                                      int bits_left, int nbits);
int ts4_jpeg_huff_decode_882F73F0(struct ts4_jpeg_bitread_working_state *state, int get_buffer,
                                  int bits_left, struct ts4_jpeg_d_derived_tbl *htbl, int min_bits);
void ts4_jpeg_make_d_derived_tbl_882F6F20(struct ts4_jpeg_decomp *cinfo, int isDC, int tblno,
                                          struct ts4_jpeg_d_derived_tbl **pdtbl);
/* jpeg_natural_order: zigzag position to natural coefficient index. */
extern const int lbl_88025F10[];

/* extend_test[16] followed by extend_offset[16] (jdphuff.c copy of the HUFF_EXTEND tables). */
extern const int lbl_88026A58[32];
/* jpeg_natural_order: zigzag position to natural coefficient index. */
extern const int lbl_88025F10[];

#define BITREAD_STATE_VARS                                                                \
    int get_buffer;                                                                       \
    int bits_left;                                                                        \
    struct ts4_jpeg_bitread_working_state br_state
#define BITREAD_LOAD_STATE(cinfop, permstate)                                             \
    br_state.cinfo = cinfop;                                                              \
    br_state.next_input_byte = cinfop->src->next_input_byte;                              \
    br_state.bytes_in_buffer = cinfop->src->bytes_in_buffer;                              \
    get_buffer = permstate.get_buffer;                                                    \
    bits_left = permstate.bits_left;
#define BITREAD_SAVE_STATE(cinfop, permstate)                                             \
    cinfop->src->next_input_byte = br_state.next_input_byte;                              \
    cinfop->src->bytes_in_buffer = br_state.bytes_in_buffer;                              \
    permstate.get_buffer = get_buffer;                                                    \
    permstate.bits_left = bits_left
#define CHECK_BIT_BUFFER(state, nbits, action)                                            \
    {                                                                                     \
        if (bits_left < (nbits)) {                                                        \
            if (!ts4_jpeg_fill_bit_buffer_882F7288(&(state), get_buffer, bits_left, nbits)) { \
                action;                                                                   \
            }                                                                             \
            get_buffer = (state).get_buffer;                                              \
            bits_left = (state).bits_left;                                                \
        }                                                                                 \
    }
#define GET_BITS(nbits) (((int)(get_buffer >> (bits_left -= (nbits)))) & ((1 << (nbits)) - 1))
#define PEEK_BITS(nbits) (((int)(get_buffer >> (bits_left - (nbits)))) & ((1 << (nbits)) - 1))
#define DROP_BITS(nbits) (bits_left -= (nbits))
#define HUFF_DECODE(result, state, htbl, failaction, slowlabel)                           \
    {                                                                                     \
        int nb, look;                                                                     \
        if (bits_left < 8) {                                                              \
            if (!ts4_jpeg_fill_bit_buffer_882F7288(&state, get_buffer, bits_left, 0)) {   \
                failaction;                                                               \
            }                                                                             \
            get_buffer = state.get_buffer;                                                \
            bits_left = state.bits_left;                                                  \
            if (bits_left < 8) {                                                          \
                nb = 1;                                                                   \
                goto slowlabel;                                                           \
            }                                                                             \
        }                                                                                 \
        look = PEEK_BITS(8);                                                              \
        if ((nb = htbl->look_nbits[look]) != 0) {                                         \
            DROP_BITS(nb);                                                                \
            result = htbl->look_sym[look];                                                \
        } else {                                                                          \
            nb = 8 + 1;                                                                   \
        slowlabel:                                                                        \
            if ((result = ts4_jpeg_huff_decode_882F73F0(&state, get_buffer, bits_left, htbl, nb)) < 0) { \
                failaction;                                                               \
            }                                                                             \
            get_buffer = state.get_buffer;                                                \
            bits_left = state.bits_left;                                                  \
        }                                                                                 \
    }
#define HUFF_EXTEND(x, s) ((x) < lbl_88026A58[s] ? (x) + lbl_88026A58[16 + (s)] : (x))


#define JP1_ERREXIT4(c, code, p1, p2, p3, p4)                                              \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                            \
     (c)->err->msg_parm[1] = (p2), (c)->err->msg_parm[2] = (p3), (c)->err->msg_parm[3] = (p4), \
     (*(c)->err->error_exit)(c))
#define JP1_WARNMS2(c, code, p1, p2)                                                       \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                            \
     (c)->err->msg_parm[1] = (p2), (*(c)->err->emit_message)((c), -1))

/* Skips a restart marker and resets DC predictions and the EOB run (Swing_DLL.xex 0x882F7C08). */
int ts4_jpeg_phuff_process_restart_882F7C08(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_phuff_entropy *entropy = (struct ts4_jpeg_phuff_entropy *)cinfo->entropy;
    int ci;

    cinfo->marker->discarded_bytes += entropy->bitstate.bits_left / 8;
    entropy->bitstate.bits_left = 0;
    if (!(*cinfo->marker->read_restart_marker)(cinfo))
        return 0;
    for (ci = 0; ci < cinfo->comps_in_scan; ci++)
        entropy->saved.last_dc_val[ci] = 0;
    entropy->saved.EOBRUN = 0;
    entropy->restarts_to_go = cinfo->restart_interval;
    if (cinfo->unread_marker == 0)
        entropy->insufficient_data = 0;
    return 1;
}

/* Decodes the first DC scan of a progressive MCU (Swing_DLL.xex 0x882F7CB0). */
int ts4_jpeg_decode_mcu_DC_first_882F7CB0(struct ts4_jpeg_decomp *cinfo, ts4_jblock **MCU_data)
{
    struct ts4_jpeg_phuff_entropy *entropy = (struct ts4_jpeg_phuff_entropy *)cinfo->entropy;
    int Al = cinfo->Al;
    int s, r;
    int blkn, ci;
    ts4_jblock *block;
    BITREAD_STATE_VARS;
    struct ts4_jpeg_phuff_saved state;
    struct ts4_jpeg_d_derived_tbl *tbl;
    struct ts4_jpeg_component_info *compptr;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0)
            if (!ts4_jpeg_phuff_process_restart_882F7C08(cinfo))
                return 0;
    }
    if (!entropy->insufficient_data) {
        BITREAD_LOAD_STATE(cinfo, entropy->bitstate);
        state = entropy->saved;
        for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
            block = MCU_data[blkn];
            ci = cinfo->MCU_membership[blkn];
            compptr = cinfo->cur_comp_info[ci];
            tbl = entropy->derived_tbls[compptr->dc_tbl_no];
            HUFF_DECODE(s, br_state, tbl, return 0, label1);
            if (s) {
                CHECK_BIT_BUFFER(br_state, s, return 0);
                r = GET_BITS(s);
                s = HUFF_EXTEND(r, s);
            }
            s += state.last_dc_val[ci];
            state.last_dc_val[ci] = s;
            (*block)[0] = (short)(s << Al);
        }
        BITREAD_SAVE_STATE(cinfo, entropy->bitstate);
        entropy->saved = state;
    }
    entropy->restarts_to_go--;
    return 1;
}

/* Decodes the first AC scan of a progressive MCU (Swing_DLL.xex 0x882F7F00). */
int ts4_jpeg_decode_mcu_AC_first_882F7F00(struct ts4_jpeg_decomp *cinfo, ts4_jblock **MCU_data)
{
    struct ts4_jpeg_phuff_entropy *entropy = (struct ts4_jpeg_phuff_entropy *)cinfo->entropy;
    int Se = cinfo->Se;
    int Al = cinfo->Al;
    int s, k, r;
    unsigned int EOBRUN;
    ts4_jblock *block;
    BITREAD_STATE_VARS;
    struct ts4_jpeg_d_derived_tbl *tbl;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0)
            if (!ts4_jpeg_phuff_process_restart_882F7C08(cinfo))
                return 0;
    }
    if (!entropy->insufficient_data) {
        EOBRUN = entropy->saved.EOBRUN;
        if (EOBRUN > 0) {
            EOBRUN--;
        } else {
            BITREAD_LOAD_STATE(cinfo, entropy->bitstate);
            block = MCU_data[0];
            tbl = entropy->ac_derived_tbl;
            for (k = cinfo->Ss; k <= Se; k++) {
                HUFF_DECODE(s, br_state, tbl, return 0, label2);
                r = s >> 4;
                s &= 15;
                if (s) {
                    k += r;
                    CHECK_BIT_BUFFER(br_state, s, return 0);
                    r = GET_BITS(s);
                    s = HUFF_EXTEND(r, s);
                    (*block)[lbl_88025F10[k]] = (short)(s << Al);
                } else {
                    if (r == 15) {
                        k += 15;
                    } else {
                        EOBRUN = 1 << r;
                        if (r) {
                            CHECK_BIT_BUFFER(br_state, r, return 0);
                            r = GET_BITS(r);
                            EOBRUN += r;
                        }
                        EOBRUN--;
                        break;
                    }
                }
            }
            BITREAD_SAVE_STATE(cinfo, entropy->bitstate);
        }
        entropy->saved.EOBRUN = EOBRUN;
    }
    entropy->restarts_to_go--;
    return 1;
}

/* Decodes a DC refinement scan: one more bit per DC coefficient (Swing_DLL.xex 0x882F8160). */
int ts4_jpeg_decode_mcu_DC_refine_882F8160(struct ts4_jpeg_decomp *cinfo, ts4_jblock **MCU_data)
{
    struct ts4_jpeg_phuff_entropy *entropy = (struct ts4_jpeg_phuff_entropy *)cinfo->entropy;
    int p1 = 1 << cinfo->Al;
    int blkn;
    ts4_jblock *block;
    BITREAD_STATE_VARS;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0)
            if (!ts4_jpeg_phuff_process_restart_882F7C08(cinfo))
                return 0;
    }
    BITREAD_LOAD_STATE(cinfo, entropy->bitstate);
    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
        block = MCU_data[blkn];
        CHECK_BIT_BUFFER(br_state, 1, return 0);
        if (GET_BITS(1))
            (*block)[0] |= p1;
    }
    BITREAD_SAVE_STATE(cinfo, entropy->bitstate);
    entropy->restarts_to_go--;
    return 1;
}

/* Decodes an AC refinement scan: correction bits and newly nonzero coefficients
 * (Swing_DLL.xex 0x882F8278). */
int ts4_jpeg_decode_mcu_AC_refine_882F8278(struct ts4_jpeg_decomp *cinfo, ts4_jblock **MCU_data)
{
    struct ts4_jpeg_phuff_entropy *entropy = (struct ts4_jpeg_phuff_entropy *)cinfo->entropy;
    int Se = cinfo->Se;
    int p1 = 1 << cinfo->Al;
    int m1 = (int)(~0u << cinfo->Al);
    int s, k, r;
    unsigned int EOBRUN;
    ts4_jblock *block;
    short *thiscoef;
    BITREAD_STATE_VARS;
    struct ts4_jpeg_d_derived_tbl *tbl;
    int num_newnz;
    int newnz_pos[64];

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0)
            if (!ts4_jpeg_phuff_process_restart_882F7C08(cinfo))
                return 0;
    }
    if (!entropy->insufficient_data) {
        BITREAD_LOAD_STATE(cinfo, entropy->bitstate);
        EOBRUN = entropy->saved.EOBRUN;
        block = MCU_data[0];
        tbl = entropy->ac_derived_tbl;
        num_newnz = 0;
        k = cinfo->Ss;
        if (EOBRUN == 0) {
            for (; k <= Se; k++) {
                HUFF_DECODE(s, br_state, tbl, goto undoit, label3);
                r = s >> 4;
                s &= 15;
                if (s) {
                    if (s != 1)
                        JP1_WARNMS(cinfo, JP1_JWRN_HUFF_BAD_CODE);
                    CHECK_BIT_BUFFER(br_state, 1, goto undoit);
                    if (GET_BITS(1))
                        s = p1;
                    else
                        s = m1;
                } else {
                    if (r != 15) {
                        EOBRUN = 1 << r;
                        if (r) {
                            CHECK_BIT_BUFFER(br_state, r, goto undoit);
                            r = GET_BITS(r);
                            EOBRUN += r;
                        }
                        break;
                    }
                }
                do {
                    thiscoef = *block + lbl_88025F10[k];
                    if (*thiscoef != 0) {
                        CHECK_BIT_BUFFER(br_state, 1, goto undoit);
                        if (GET_BITS(1)) {
                            if ((*thiscoef & p1) == 0) {
                                if (*thiscoef >= 0)
                                    *thiscoef += p1;
                                else
                                    *thiscoef += m1;
                            }
                        }
                    } else {
                        if (--r < 0)
                            break;
                    }
                    k++;
                } while (k <= Se);
                if (s) {
                    int pos = lbl_88025F10[k];
                    (*block)[pos] = (short)s;
                    newnz_pos[num_newnz++] = pos;
                }
            }
        }
        if (EOBRUN > 0) {
            for (; k <= Se; k++) {
                thiscoef = *block + lbl_88025F10[k];
                if (*thiscoef != 0) {
                    CHECK_BIT_BUFFER(br_state, 1, goto undoit);
                    if (GET_BITS(1)) {
                        if ((*thiscoef & p1) == 0) {
                            if (*thiscoef >= 0)
                                *thiscoef += p1;
                            else
                                *thiscoef += m1;
                        }
                    }
                }
            }
            EOBRUN--;
        }
        BITREAD_SAVE_STATE(cinfo, entropy->bitstate);
        entropy->saved.EOBRUN = EOBRUN;
    }
    entropy->restarts_to_go--;
    return 1;
undoit:
    while (num_newnz > 0)
        (*block)[newnz_pos[--num_newnz]] = 0;
    return 0;
}

/* Validates the progressive scan parameters, updates the coefficient progress table and
 * selects the MCU decoder for the scan (Swing_DLL.xex 0x882F86B8). */
void ts4_jpeg_start_pass_phuff_decoder_882F86B8(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_phuff_entropy *entropy = (struct ts4_jpeg_phuff_entropy *)cinfo->entropy;
    int is_DC_band, bad;
    int ci, coefi, tbl;
    int *coef_bit_ptr;
    struct ts4_jpeg_component_info *compptr;

    is_DC_band = (cinfo->Ss == 0);
    bad = 0;
    if (is_DC_band) {
        if (cinfo->Se != 0)
            bad = 1;
    } else {
        if (cinfo->Ss > cinfo->Se || cinfo->Se >= 64)
            bad = 1;
        if (cinfo->comps_in_scan != 1)
            bad = 1;
    }
    if (cinfo->Ah != 0) {
        if (cinfo->Al != cinfo->Ah - 1)
            bad = 1;
    }
    if (cinfo->Al > 13)
        bad = 1;
    if (bad)
        JP1_ERREXIT4(cinfo, JP1_JERR_BAD_PROGRESSION, cinfo->Ss, cinfo->Se, cinfo->Ah, cinfo->Al);
    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        int cindex = cinfo->cur_comp_info[ci]->component_index;
        coef_bit_ptr = &cinfo->coef_bits[cindex][0];
        if (!is_DC_band && coef_bit_ptr[0] < 0)
            JP1_WARNMS2(cinfo, JP1_JWRN_BOGUS_PROGRESSION, cindex, 0);
        for (coefi = cinfo->Ss; coefi <= cinfo->Se; coefi++) {
            int expected = (coef_bit_ptr[coefi] < 0) ? 0 : coef_bit_ptr[coefi];
            if (cinfo->Ah != expected)
                JP1_WARNMS2(cinfo, JP1_JWRN_BOGUS_PROGRESSION, cindex, coefi);
            coef_bit_ptr[coefi] = cinfo->Al;
        }
    }
    if (cinfo->Ah == 0) {
        if (is_DC_band)
            entropy->decode_mcu = ts4_jpeg_decode_mcu_DC_first_882F7CB0;
        else
            entropy->decode_mcu = ts4_jpeg_decode_mcu_AC_first_882F7F00;
    } else {
        if (is_DC_band)
            entropy->decode_mcu = ts4_jpeg_decode_mcu_DC_refine_882F8160;
        else
            entropy->decode_mcu = ts4_jpeg_decode_mcu_AC_refine_882F8278;
    }
    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        if (is_DC_band) {
            if (cinfo->Ah == 0) {
                tbl = compptr->dc_tbl_no;
                ts4_jpeg_make_d_derived_tbl_882F6F20(cinfo, 1, tbl, &entropy->derived_tbls[tbl]);
            }
        } else {
            tbl = compptr->ac_tbl_no;
            ts4_jpeg_make_d_derived_tbl_882F6F20(cinfo, 0, tbl, &entropy->derived_tbls[tbl]);
            entropy->ac_derived_tbl = entropy->derived_tbls[tbl];
        }
        entropy->saved.last_dc_val[ci] = 0;
    }
    entropy->bitstate.bits_left = 0;
    entropy->bitstate.get_buffer = 0;
    entropy->insufficient_data = 0;
    entropy->saved.EOBRUN = 0;
    entropy->restarts_to_go = cinfo->restart_interval;
}

/* Creates the progressive Huffman decoder and the coefficient progress table
 * (Swing_DLL.xex 0x882F89A0). */
void ts4_jpeg_jinit_phuff_decoder_882F89A0(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_phuff_entropy *entropy;
    int i, ci;
    int *coef_bit_ptr;

    entropy = (struct ts4_jpeg_phuff_entropy *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*entropy));
    cinfo->entropy = (struct ts4_jpeg_entropy_decoder *)entropy;
    entropy->start_pass = ts4_jpeg_start_pass_phuff_decoder_882F86B8;
    for (i = 0; i < 4; i++)
        entropy->derived_tbls[i] = 0;
    cinfo->coef_bits = (int (*)[64])(*cinfo->mem->alloc_small)(
        cinfo, 1, cinfo->num_components * 64 * sizeof(int));
    coef_bit_ptr = &cinfo->coef_bits[0][0];
    for (ci = 0; ci < cinfo->num_components; ci++)
        for (i = 0; i < 64; i++)
            *coef_bit_ptr++ = -1;
}
