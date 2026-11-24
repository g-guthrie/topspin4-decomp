/* Loader_DLL.xex 0x83458D60-0x83459058, 0x834592B8-0x834593D0, executable version 0.0.0.3. */
/* Library routines: libjpeg jdphuff.c (process_restart, decode_mcu_DC_first, decode_mcu_DC_refine). */
#include "l44_jpeg.h"

struct ts4l_jpeg_phuff_saved {
    unsigned int EOBRUN;
    int last_dc_val[4];
};

/* Progressive Huffman entropy decoder private state (jdphuff.c phuff_entropy_decoder). */
struct ts4l_jpeg_phuff_entropy {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);                        /* 0x00 */
    int (*decode_mcu)(struct ts4l_jpeg_decomp *cinfo, ts4l_jblock **MCU_data);  /* 0x04 */
    int insufficient_data;                                                    /* 0x08 */
    struct ts4l_jpeg_bitread_perm_state bitstate;                              /* 0x0c */
    struct ts4l_jpeg_phuff_saved saved;                                        /* 0x14 */
    unsigned int restarts_to_go;                                              /* 0x28 */
    struct ts4l_jpeg_d_derived_tbl *derived_tbls[4];                           /* 0x2c */
    struct ts4l_jpeg_d_derived_tbl *ac_derived_tbl;                            /* 0x3c */
};

int ts4l_jpeg_fill_bit_buffer_83458338(struct ts4l_jpeg_bitread_working_state *state, int get_buffer,
                                      int bits_left, int nbits);
int ts4l_jpeg_huff_decode_834584A0(struct ts4l_jpeg_bitread_working_state *state, int get_buffer,
                                  int bits_left, struct ts4l_jpeg_d_derived_tbl *htbl, int min_bits);
void ts4l_jpeg_make_d_derived_tbl_83457FD0(struct ts4l_jpeg_decomp *cinfo, int isDC, int tblno,
                                          struct ts4l_jpeg_d_derived_tbl **pdtbl);
/* jpeg_natural_order: zigzag position to natural coefficient index. */
extern const int lbl_8307A868[];

/* extend_test[16] followed by extend_offset[16] (jdphuff.c copy of the HUFF_EXTEND tables). */
extern const int lbl_8307B1F0[32];
/* jpeg_natural_order: zigzag position to natural coefficient index. */
extern const int lbl_8307A868[];

#define BITREAD_STATE_VARS                                                                \
    int get_buffer;                                                                       \
    int bits_left;                                                                        \
    struct ts4l_jpeg_bitread_working_state br_state
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
            if (!ts4l_jpeg_fill_bit_buffer_83458338(&(state), get_buffer, bits_left, nbits)) { \
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
            if (!ts4l_jpeg_fill_bit_buffer_83458338(&state, get_buffer, bits_left, 0)) {   \
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
            if ((result = ts4l_jpeg_huff_decode_834584A0(&state, get_buffer, bits_left, htbl, nb)) < 0) { \
                failaction;                                                               \
            }                                                                             \
            get_buffer = state.get_buffer;                                                \
            bits_left = state.bits_left;                                                  \
        }                                                                                 \
    }
#define HUFF_EXTEND(x, s) ((x) < lbl_8307B1F0[s] ? (x) + lbl_8307B1F0[16 + (s)] : (x))


#define TS4L_ERREXIT4(c, code, p1, p2, p3, p4)                                              \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                            \
     (c)->err->msg_parm[1] = (p2), (c)->err->msg_parm[2] = (p3), (c)->err->msg_parm[3] = (p4), \
     (*(c)->err->error_exit)(c))
#define TS4L_WARNMS2(c, code, p1, p2)                                                       \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                            \
     (c)->err->msg_parm[1] = (p2), (*(c)->err->emit_message)((c), -1))




int ts4l_jpeg_phuff_process_restart_83458D60(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_phuff_entropy *entropy = (struct ts4l_jpeg_phuff_entropy *)cinfo->entropy;
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

int ts4l_jpeg_decode_mcu_DC_first_83458E08(struct ts4l_jpeg_decomp *cinfo, ts4l_jblock **MCU_data)
{
    struct ts4l_jpeg_phuff_entropy *entropy = (struct ts4l_jpeg_phuff_entropy *)cinfo->entropy;
    int Al = cinfo->Al;
    int s, r;
    int blkn, ci;
    ts4l_jblock *block;
    BITREAD_STATE_VARS;
    struct ts4l_jpeg_phuff_saved state;
    struct ts4l_jpeg_d_derived_tbl *tbl;
    struct ts4l_jpeg_component_info *compptr;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0)
            if (!ts4l_jpeg_phuff_process_restart_83458D60(cinfo))
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

int ts4l_jpeg_decode_mcu_DC_refine_834592B8(struct ts4l_jpeg_decomp *cinfo, ts4l_jblock **MCU_data)
{
    struct ts4l_jpeg_phuff_entropy *entropy = (struct ts4l_jpeg_phuff_entropy *)cinfo->entropy;
    int p1 = 1 << cinfo->Al;
    int blkn;
    ts4l_jblock *block;
    BITREAD_STATE_VARS;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0)
            if (!ts4l_jpeg_phuff_process_restart_83458D60(cinfo))
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
