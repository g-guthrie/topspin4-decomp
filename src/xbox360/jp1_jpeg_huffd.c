/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG baseline Huffman entropy decoder, IJG jdhuff.c style. (JP1) */
#include "jp1_jpeg.h"

enum { JP1_JWRN_HIT_MARKER = 0x75, JP1_JWRN_HUFF_BAD_CODE = 0x76 };

#define JP1_MIN_GET_BITS 25

/* Refills the bit buffer from the source, stopping at markers; returns 0 if the source suspends
 * (Swing_DLL.xex 0x882F7288). */
int ts4_jpeg_fill_bit_buffer_882F7288(struct ts4_jpeg_bitread_working_state *state, int get_buffer,
                                      int bits_left, int nbits)
{
    const ts4_joctet *next_input_byte = state->next_input_byte;
    unsigned int bytes_in_buffer = state->bytes_in_buffer;
    struct ts4_jpeg_decomp *cinfo = state->cinfo;

    if (cinfo->unread_marker == 0) {
        while (bits_left < JP1_MIN_GET_BITS) {
            int c;

            if (bytes_in_buffer == 0) {
                if (!(*cinfo->src->fill_input_buffer)(cinfo))
                    return 0;
                next_input_byte = cinfo->src->next_input_byte;
                bytes_in_buffer = cinfo->src->bytes_in_buffer;
            }
            bytes_in_buffer--;
            c = *next_input_byte++;
            if (c == 0xFF) {
                do {
                    if (bytes_in_buffer == 0) {
                        if (!(*cinfo->src->fill_input_buffer)(cinfo))
                            return 0;
                        next_input_byte = cinfo->src->next_input_byte;
                        bytes_in_buffer = cinfo->src->bytes_in_buffer;
                    }
                    bytes_in_buffer--;
                    c = *next_input_byte++;
                } while (c == 0xFF);
                if (c == 0) {
                    c = 0xFF;
                } else {
                    cinfo->unread_marker = c;
                    goto no_more_bytes;
                }
            }
            get_buffer = (get_buffer << 8) | c;
            bits_left += 8;
        }
    } else {
    no_more_bytes:
        if (nbits > bits_left) {
            if (!((struct ts4_jpeg_huff_entropy *)cinfo->entropy)->insufficient_data) {
                JP1_WARNMS(cinfo, JP1_JWRN_HIT_MARKER);
                ((struct ts4_jpeg_huff_entropy *)cinfo->entropy)->insufficient_data = 1;
            }
            get_buffer <<= JP1_MIN_GET_BITS - bits_left;
            bits_left = JP1_MIN_GET_BITS;
        }
    }
    state->next_input_byte = next_input_byte;
    state->bytes_in_buffer = bytes_in_buffer;
    state->get_buffer = get_buffer;
    state->bits_left = bits_left;
    return 1;
}

/* Decodes the remainder of a Huffman code bit by bit once the lookahead table failed
 * (Swing_DLL.xex 0x882F73F0). */
int ts4_jpeg_huff_decode_882F73F0(struct ts4_jpeg_bitread_working_state *state, int get_buffer,
                                  int bits_left, struct ts4_jpeg_d_derived_tbl *htbl, int min_bits)
{
    int l = min_bits;
    int code;

    if (bits_left < l) {
        if (!ts4_jpeg_fill_bit_buffer_882F7288(state, get_buffer, bits_left, l))
            return -1;
        get_buffer = state->get_buffer;
        bits_left = state->bits_left;
    }
    code = (get_buffer >> (bits_left -= l)) & ((1 << l) - 1);
    while (code > htbl->maxcode[l]) {
        code <<= 1;
        if (bits_left < 1) {
            if (!ts4_jpeg_fill_bit_buffer_882F7288(state, get_buffer, bits_left, 1))
                return -1;
            get_buffer = state->get_buffer;
            bits_left = state->bits_left;
        }
        code |= (get_buffer >> (bits_left -= 1)) & 1;
        l++;
    }
    state->get_buffer = get_buffer;
    state->bits_left = bits_left;
    if (l > 16) {
        JP1_WARNMS(state->cinfo, JP1_JWRN_HUFF_BAD_CODE);
        return 0;
    }
    return htbl->pub->huffval[(int)(code + htbl->valoffset[l])];
}

/* extend_test[16] followed by extend_offset[16] (jdhuff.c HUFF_EXTEND tables). */
extern const int lbl_880269D8[32];
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
#define HUFF_EXTEND(x, s) ((x) < lbl_880269D8[s] ? (x) + lbl_880269D8[16 + (s)] : (x))

/* Skips a restart marker and resets the DC predictions (inlined into decode_mcu). */
static int process_restart(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_huff_entropy *entropy = (struct ts4_jpeg_huff_entropy *)cinfo->entropy;
    int ci;

    cinfo->marker->discarded_bytes += entropy->bitstate.bits_left / 8;
    entropy->bitstate.bits_left = 0;
    if (!(*cinfo->marker->read_restart_marker)(cinfo))
        return 0;
    for (ci = 0; ci < cinfo->comps_in_scan; ci++)
        entropy->last_dc_val[ci] = 0;
    entropy->restarts_to_go = cinfo->restart_interval;
    if (cinfo->unread_marker == 0)
        entropy->insufficient_data = 0;
    return 1;
}

/* Decodes one MCU of baseline Huffman data into the coefficient blocks, handling restart
 * markers first (Swing_DLL.xex 0x882F7518). */
int ts4_jpeg_decode_mcu_882F7518(struct ts4_jpeg_decomp *cinfo, ts4_jblock **MCU_data)
{
    struct ts4_jpeg_huff_entropy *entropy = (struct ts4_jpeg_huff_entropy *)cinfo->entropy;
    int blkn;
    BITREAD_STATE_VARS;
    int last_dc_val[4];

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0)
            if (!process_restart(cinfo))
                return 0;
    }
    if (!entropy->insufficient_data) {
        BITREAD_LOAD_STATE(cinfo, entropy->bitstate);
        memcpy(last_dc_val, entropy->last_dc_val, sizeof(last_dc_val));
        for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
            ts4_jblock *block = MCU_data[blkn];
            struct ts4_jpeg_d_derived_tbl *dctbl = entropy->dc_cur_tbls[blkn];
            struct ts4_jpeg_d_derived_tbl *actbl = entropy->ac_cur_tbls[blkn];
            int s, k, r;

            HUFF_DECODE(s, br_state, dctbl, return 0, label1);
            if (s) {
                CHECK_BIT_BUFFER(br_state, s, return 0);
                r = GET_BITS(s);
                s = HUFF_EXTEND(r, s);
            }
            if (entropy->dc_needed[blkn]) {
                int ci = cinfo->MCU_membership[blkn];
                s += last_dc_val[ci];
                last_dc_val[ci] = s;
                (*block)[0] = (short)s;
            }
            if (entropy->ac_needed[blkn]) {
                for (k = 1; k < 64; k++) {
                    HUFF_DECODE(s, br_state, actbl, return 0, label2);
                    r = s >> 4;
                    s &= 15;
                    if (s) {
                        k += r;
                        CHECK_BIT_BUFFER(br_state, s, return 0);
                        r = GET_BITS(s);
                        s = HUFF_EXTEND(r, s);
                        (*block)[lbl_88025F10[k]] = (short)s;
                    } else {
                        if (r != 15)
                            break;
                        k += 15;
                    }
                }
            } else {
                for (k = 1; k < 64; k++) {
                    HUFF_DECODE(s, br_state, actbl, return 0, label3);
                    r = s >> 4;
                    s &= 15;
                    if (s) {
                        k += r;
                        CHECK_BIT_BUFFER(br_state, s, return 0);
                        DROP_BITS(s);
                    } else {
                        if (r != 15)
                            break;
                        k += 15;
                    }
                }
            }
        }
        BITREAD_SAVE_STATE(cinfo, entropy->bitstate);
        memcpy(entropy->last_dc_val, last_dc_val, sizeof(last_dc_val));
    }
    entropy->restarts_to_go--;
    return 1;
}

void ts4_jpeg_make_d_derived_tbl_882F6F20(struct ts4_jpeg_decomp *cinfo, int isDC, int tblno,
                                          struct ts4_jpeg_d_derived_tbl **pdtbl);

/* Prepares the baseline Huffman decoder for a scan: derives the tables and per-block
 * lookup pointers (Swing_DLL.xex 0x882F79F0). */
void ts4_jpeg_start_pass_huff_decoder_882F79F0(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_huff_entropy *entropy = (struct ts4_jpeg_huff_entropy *)cinfo->entropy;
    int ci, blkn, dctbl, actbl;
    struct ts4_jpeg_component_info *compptr;

    if (cinfo->Ss != 0 || cinfo->Se != 63 || cinfo->Ah != 0 || cinfo->Al != 0)
        JP1_WARNMS(cinfo, 0x7a);
    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        dctbl = compptr->dc_tbl_no;
        actbl = compptr->ac_tbl_no;
        ts4_jpeg_make_d_derived_tbl_882F6F20(cinfo, 1, dctbl, &entropy->dc_derived_tbls[dctbl]);
        ts4_jpeg_make_d_derived_tbl_882F6F20(cinfo, 0, actbl, &entropy->ac_derived_tbls[actbl]);
        entropy->last_dc_val[ci] = 0;
    }
    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
        ci = cinfo->MCU_membership[blkn];
        compptr = cinfo->cur_comp_info[ci];
        entropy->dc_cur_tbls[blkn] = entropy->dc_derived_tbls[compptr->dc_tbl_no];
        entropy->ac_cur_tbls[blkn] = entropy->ac_derived_tbls[compptr->ac_tbl_no];
        if (compptr->component_needed) {
            entropy->dc_needed[blkn] = 1;
            entropy->ac_needed[blkn] = (compptr->DCT_scaled_size > 1);
        } else {
            entropy->ac_needed[blkn] = 0;
            entropy->dc_needed[blkn] = 0;
        }
    }
    entropy->bitstate.bits_left = 0;
    entropy->bitstate.get_buffer = 0;
    entropy->insufficient_data = 0;
    entropy->restarts_to_go = cinfo->restart_interval;
}

/* Creates the baseline Huffman decoder object (Swing_DLL.xex 0x882F7B90). */
void ts4_jpeg_jinit_huff_decoder_882F7B90(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_huff_entropy *entropy;
    int i;

    entropy = (struct ts4_jpeg_huff_entropy *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*entropy));
    cinfo->entropy = (struct ts4_jpeg_entropy_decoder *)entropy;
    entropy->start_pass = ts4_jpeg_start_pass_huff_decoder_882F79F0;
    entropy->decode_mcu = ts4_jpeg_decode_mcu_882F7518;
    for (i = 0; i < 4; i++) {
        entropy->dc_derived_tbls[i] = entropy->ac_derived_tbls[i] = 0;
    }
}
