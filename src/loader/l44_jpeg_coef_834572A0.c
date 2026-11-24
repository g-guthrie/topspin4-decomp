/* Loader_DLL.xex 0x834572A0-0x834575F8, executable version 0.0.0.3. */
/* Library routines: libjpeg jdcoefct.c (decompress_data, smoothing_ok). */
#include "l44_jpeg.h"

typedef struct ts4l_my_coef {
    struct ts4l_jpeg_d_coef pub;           /* 0x00 */
    unsigned int MCU_ctr;                  /* 0x14 */
    int MCU_vert_offset;                   /* 0x18 */
    int MCU_rows_per_iMCU_row;             /* 0x1c */
    ts4l_jblock *MCU_buffer[10];           /* 0x20 */
    void *whole_image[10];                 /* 0x48 */
    int *coef_bits_latch;                  /* 0x70 */
} ts4l_my_coef;

int ts4l_jpeg_decompress_data_834572A0(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage output_buf)
{
    ts4l_my_coef *coef = (ts4l_my_coef *)cinfo->coef;
    unsigned int last_iMCU_row = cinfo->total_iMCU_rows - 1;
    unsigned int block_num;
    int ci, block_row, block_rows;
    ts4l_jblockarray buffer;
    ts4l_jblockrow buffer_ptr;
    ts4l_jsamparray output_ptr;
    unsigned int output_col;
    struct ts4l_jpeg_component_info *compptr;
    void (*inverse_DCT)(struct ts4l_jpeg_decomp *, struct ts4l_jpeg_component_info *, ts4l_jcoef *,
                        ts4l_jsamparray, ts4l_jdim);

    while (cinfo->input_scan_number < cinfo->output_scan_number ||
           (cinfo->input_scan_number == cinfo->output_scan_number &&
            cinfo->input_iMCU_row <= cinfo->output_iMCU_row)) {
        if ((*cinfo->inputctl->consume_input)(cinfo) == 0)
            return 0;
    }

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if (!compptr->component_needed)
            continue;
        buffer = (ts4l_jblockarray)(*cinfo->mem->access_virt_barray)(
            cinfo, (struct ts4l_jpeg_virt_barray *)coef->whole_image[ci],
            cinfo->output_iMCU_row * compptr->v_samp_factor, (unsigned int)compptr->v_samp_factor, 0);
        if (cinfo->output_iMCU_row < last_iMCU_row) {
            block_rows = compptr->v_samp_factor;
        } else {
            block_rows = (int)(compptr->height_in_blocks % (unsigned int)compptr->v_samp_factor);
            if (block_rows == 0)
                block_rows = compptr->v_samp_factor;
        }
        inverse_DCT = cinfo->idct->inverse_DCT[ci];
        output_ptr = output_buf[ci];
        for (block_row = 0; block_row < block_rows; block_row++) {
            buffer_ptr = buffer[block_row];
            output_col = 0;
            for (block_num = 0; block_num < compptr->width_in_blocks; block_num++) {
                (*inverse_DCT)(cinfo, compptr, (ts4l_jcoef *)buffer_ptr, output_ptr, output_col);
                buffer_ptr++;
                output_col += compptr->DCT_scaled_size;
            }
            output_ptr += compptr->DCT_scaled_size;
        }
    }

    if (++(cinfo->output_iMCU_row) < cinfo->total_iMCU_rows)
        return 3;
    return 4;
}

int ts4l_jpeg_smoothing_ok_83457458(struct ts4l_jpeg_decomp *cinfo)
{
    ts4l_my_coef *coef = (ts4l_my_coef *)cinfo->coef;
    int smoothing_useful = 0;
    int ci, coefi;
    struct ts4l_jpeg_component_info *compptr;
    struct ts4l_jpeg_quant_tbl *qtable;
    int *coef_bits;
    int *coef_bits_latch;

    if (!cinfo->progressive_mode || cinfo->coef_bits == 0)
        return 0;

    if (coef->coef_bits_latch == 0)
        coef->coef_bits_latch = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, cinfo->num_components * (6 * 4));
    coef_bits_latch = coef->coef_bits_latch;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if ((qtable = compptr->quant_table) == 0)
            return 0;
        if (qtable->quantval[0] == 0 || qtable->quantval[1] == 0 || qtable->quantval[8] == 0 ||
            qtable->quantval[16] == 0 || qtable->quantval[9] == 0 || qtable->quantval[2] == 0)
            return 0;
        coef_bits = cinfo->coef_bits[ci];
        if (coef_bits[0] < 0)
            return 0;
        for (coefi = 1; coefi <= 5; coefi++) {
            coef_bits_latch[coefi] = coef_bits[coefi];
            if (coef_bits[coefi] != 0)
                smoothing_useful = 1;
        }
        coef_bits_latch += 6;
    }

    return smoothing_useful;
}
