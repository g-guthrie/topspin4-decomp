/* Loader_DLL.xex 0x83456D18-0x83457DA0, executable version 0.0.0.3.
 * Statically linked libjpeg 6b routines. */

#include "l21_jp1_jpeg_8344E498.h"

struct ts4l_jpeg_my_coef {
    struct ts4l_jpeg_d_coef pub;          /* 0x00 */
    ts4l_jdim MCU_ctr;                    /* 0x14 */
    int MCU_vert_offset;                 /* 0x18 */
    int MCU_rows_per_iMCU_row;           /* 0x1c */
    ts4l_jblockrow MCU_buffer[10];        /* 0x20 */
    struct ts4l_jpeg_virt_barray *whole_image[10]; /* 0x48 */
    int *coef_bits_latch;                /* 0x70 */
};

/* Zero-fills a block of memory (jzero_far). */
void ts4_tailcall_fn_833E3A30_8344EFA0(void *target, unsigned int bytestozero);

/* Resets the per-iMCU-row MCU counters */
void ts4l_jpeg_start_iMCU_row_83456D18(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_my_coef *coef = (struct ts4l_jpeg_my_coef *)cinfo->coef;

    if (cinfo->comps_in_scan > 1) {
        coef->MCU_rows_per_iMCU_row = 1;
    } else {
        if (cinfo->input_iMCU_row < (cinfo->total_iMCU_rows - 1))
            coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->v_samp_factor;
        else
            coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->last_row_height;
    }
    coef->MCU_ctr = 0;
    coef->MCU_vert_offset = 0;
}

/* Single-pass decode: entropy-decodes each MCU and runs the inverse DCT straight into the
 * output rows */
int ts4l_jpeg_decompress_onepass_83456D98(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage output_buf)
{
    struct ts4l_jpeg_my_coef *coef = (struct ts4l_jpeg_my_coef *)cinfo->coef;
    ts4l_jdim MCU_col_num;
    ts4l_jdim last_MCU_col = cinfo->MCUs_per_row - 1;
    ts4l_jdim last_iMCU_row = cinfo->total_iMCU_rows - 1;
    int blkn, ci, xindex, yindex, yoffset, useful_width;
    ts4l_jsamparray output_ptr;
    ts4l_jdim start_col, output_col;
    struct ts4l_jpeg_component_info *compptr;
    void (*inverse_DCT)(struct ts4l_jpeg_decomp *, struct ts4l_jpeg_component_info *, ts4l_jcoef *,
                        ts4l_jsamparray, ts4l_jdim);

    for (yoffset = coef->MCU_vert_offset; yoffset < coef->MCU_rows_per_iMCU_row; yoffset++) {
        for (MCU_col_num = coef->MCU_ctr; MCU_col_num <= last_MCU_col; MCU_col_num++) {
            ts4_tailcall_fn_833E3A30_8344EFA0(coef->MCU_buffer[0],
                                              (unsigned int)cinfo->blocks_in_MCU * sizeof(ts4l_jblock));
            if (!(*cinfo->entropy->decode_mcu)(cinfo, (ts4l_jblock **)coef->MCU_buffer)) {
                coef->MCU_vert_offset = yoffset;
                coef->MCU_ctr = MCU_col_num;
                return 0;
            }
            blkn = 0;
            for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
                compptr = cinfo->cur_comp_info[ci];
                if (!compptr->component_needed) {
                    blkn += compptr->MCU_blocks;
                    continue;
                }
                inverse_DCT = cinfo->idct->inverse_DCT[compptr->component_index];
                useful_width = (MCU_col_num < last_MCU_col) ? compptr->MCU_width
                                                            : compptr->last_col_width;
                output_ptr = output_buf[compptr->component_index] +
                             yoffset * compptr->DCT_scaled_size;
                start_col = MCU_col_num * compptr->MCU_sample_width;
                for (yindex = 0; yindex < compptr->MCU_height; yindex++) {
                    if (cinfo->input_iMCU_row < last_iMCU_row ||
                        yoffset + yindex < compptr->last_row_height) {
                        output_col = start_col;
                        for (xindex = 0; xindex < useful_width; xindex++) {
                            (*inverse_DCT)(cinfo, compptr, (ts4l_jcoef *)coef->MCU_buffer[blkn + xindex],
                                           output_ptr, output_col);
                            output_col += compptr->DCT_scaled_size;
                        }
                    }
                    blkn += compptr->MCU_width;
                    output_ptr += compptr->DCT_scaled_size;
                }
            }
        }
        coef->MCU_ctr = 0;
    }
    cinfo->output_iMCU_row++;
    if (++(cinfo->input_iMCU_row) < cinfo->total_iMCU_rows) {
        ts4l_jpeg_start_iMCU_row_83456D18(cinfo);
        return 3;
    }
    (*cinfo->inputctl->finish_input_pass)(cinfo);
    return 4;
}

/* Multi-pass input: decodes one iMCU row of MCUs into the virtual coefficient arrays
 * */
int ts4l_jpeg_consume_data_83457040(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_my_coef *coef = (struct ts4l_jpeg_my_coef *)cinfo->coef;
    ts4l_jdim MCU_col_num;
    int blkn, ci, xindex, yindex, yoffset;
    ts4l_jdim start_col;
    ts4l_jblockarray buffer[4];
    ts4l_jblockrow buffer_ptr;
    struct ts4l_jpeg_component_info *compptr;

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        buffer[ci] = (*cinfo->mem->access_virt_barray)(
            cinfo, coef->whole_image[compptr->component_index],
            cinfo->input_iMCU_row * compptr->v_samp_factor, (ts4l_jdim)compptr->v_samp_factor, 1);
    }
    for (yoffset = coef->MCU_vert_offset; yoffset < coef->MCU_rows_per_iMCU_row; yoffset++) {
        for (MCU_col_num = coef->MCU_ctr; MCU_col_num < cinfo->MCUs_per_row; MCU_col_num++) {
            blkn = 0;
            for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
                compptr = cinfo->cur_comp_info[ci];
                start_col = MCU_col_num * compptr->MCU_width;
                for (yindex = 0; yindex < compptr->MCU_height; yindex++) {
                    buffer_ptr = buffer[ci][yindex + yoffset] + start_col;
                    for (xindex = 0; xindex < compptr->MCU_width; xindex++) {
                        coef->MCU_buffer[blkn++] = buffer_ptr++;
                    }
                }
            }
            if (!(*cinfo->entropy->decode_mcu)(cinfo, (ts4l_jblock **)coef->MCU_buffer)) {
                coef->MCU_vert_offset = yoffset;
                coef->MCU_ctr = MCU_col_num;
                return 0;
            }
        }
        coef->MCU_ctr = 0;
    }
    cinfo->input_iMCU_row++;
    if (cinfo->input_iMCU_row < cinfo->total_iMCU_rows) {
        ts4l_jpeg_start_iMCU_row_83456D18(cinfo);
        return 3;
    }
    (*cinfo->inputctl->finish_input_pass)(cinfo);
    return 4;
}



/* Rounds a up to a multiple of b (jutils.c jround_up). */
/* start_input_pass for the coefficient controller. */
/* dummy_consume_data: always reports suspension. */
int ts4_runtime_type_code_none(struct ts4l_jpeg_decomp *cinfo);


/* Copies a row of coefficient blocks (jutils.c jcopy_block_row). */
void ts4_tailcall_fn_833E3AD0_8344EF88(ts4l_jblockrow input_row, ts4l_jblockrow output_row, ts4l_jdim num_blocks);

/* Number of AC-prediction coefficients latched per component. */
#define TS4L_SAVED_COEFS 6

/* Multi-pass output with block smoothing: estimates missing low-order AC coefficients
 * from neighbouring DC values before the IDCT */
int ts4l_jpeg_decompress_smooth_data_834575F8(struct ts4l_jpeg_decomp *cinfo,
                                             ts4l_jsampimage output_buf)
{
    struct ts4l_jpeg_my_coef *coef = (struct ts4l_jpeg_my_coef *)cinfo->coef;
    ts4l_jdim last_iMCU_row = cinfo->total_iMCU_rows - 1;
    ts4l_jdim block_num, last_block_column;
    int ci, block_row, block_rows, access_rows;
    ts4l_jblockarray buffer;
    ts4l_jblockrow buffer_ptr, prev_block_row, next_block_row;
    ts4l_jsamparray output_ptr;
    ts4l_jdim output_col;
    struct ts4l_jpeg_component_info *compptr;
    void (*inverse_DCT)(struct ts4l_jpeg_decomp *, struct ts4l_jpeg_component_info *, ts4l_jcoef *,
                        ts4l_jsamparray, ts4l_jdim);
    int first_row, last_row;
    ts4l_jblock workspace;
    int *coef_bits;
    struct ts4l_jpeg_quant_tbl *quanttbl;
    long Q00, Q01, Q02, Q10, Q11, Q20, num;
    int DC1, DC2, DC3, DC4, DC5, DC6, DC7, DC8, DC9;
    int Al, pred;

    while (cinfo->input_scan_number <= cinfo->output_scan_number &&
           !cinfo->inputctl->eoi_reached) {
        if (cinfo->input_scan_number == cinfo->output_scan_number) {
            ts4l_jdim delta = (cinfo->Ss == 0) ? 1 : 0;
            if (cinfo->input_iMCU_row > cinfo->output_iMCU_row + delta)
                break;
        }
        if ((*cinfo->inputctl->consume_input)(cinfo) == 0)
            return 0;
    }
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if (!compptr->component_needed)
            continue;
        if (cinfo->output_iMCU_row < last_iMCU_row) {
            block_rows = compptr->v_samp_factor;
            access_rows = block_rows * 2;
            last_row = 0;
        } else {
            block_rows = (int)(compptr->height_in_blocks % (ts4l_jdim)compptr->v_samp_factor);
            if (block_rows == 0)
                block_rows = compptr->v_samp_factor;
            access_rows = block_rows;
            last_row = 1;
        }
        if (cinfo->output_iMCU_row > 0) {
            access_rows += compptr->v_samp_factor;
            buffer = (*cinfo->mem->access_virt_barray)(
                cinfo, coef->whole_image[ci],
                (cinfo->output_iMCU_row - 1) * compptr->v_samp_factor, (ts4l_jdim)access_rows, 0);
            buffer += compptr->v_samp_factor;
            first_row = 0;
        } else {
            buffer = (*cinfo->mem->access_virt_barray)(cinfo, coef->whole_image[ci], 0,
                                                       (ts4l_jdim)access_rows, 0);
            first_row = 1;
        }
        coef_bits = coef->coef_bits_latch + (ci * TS4L_SAVED_COEFS);
        quanttbl = compptr->quant_table;
        Q00 = quanttbl->quantval[0];
        Q01 = quanttbl->quantval[1];
        Q10 = quanttbl->quantval[8];
        Q20 = quanttbl->quantval[16];
        Q11 = quanttbl->quantval[9];
        Q02 = quanttbl->quantval[2];
        inverse_DCT = cinfo->idct->inverse_DCT[ci];
        output_ptr = output_buf[ci];
        for (block_row = 0; block_row < block_rows; block_row++) {
            buffer_ptr = buffer[block_row];
            if (first_row && block_row == 0)
                prev_block_row = buffer_ptr;
            else
                prev_block_row = buffer[block_row - 1];
            if (last_row && block_row == block_rows - 1)
                next_block_row = buffer_ptr;
            else
                next_block_row = buffer[block_row + 1];
            DC1 = DC2 = DC3 = (int)prev_block_row[0][0];
            DC4 = DC5 = DC6 = (int)buffer_ptr[0][0];
            DC7 = DC8 = DC9 = (int)next_block_row[0][0];
            output_col = 0;
            last_block_column = compptr->width_in_blocks - 1;
            for (block_num = 0; block_num <= last_block_column; block_num++) {
                ts4_tailcall_fn_833E3AD0_8344EF88(buffer_ptr, (ts4l_jblockrow)workspace, 1);
                if (block_num < last_block_column) {
                    DC3 = (int)prev_block_row[1][0];
                    DC6 = (int)buffer_ptr[1][0];
                    DC9 = (int)next_block_row[1][0];
                }
                if ((Al = coef_bits[1]) != 0 && workspace[1] == 0) {
                    num = 36 * Q00 * (DC4 - DC6);
                    if (num >= 0) {
                        pred = (int)(((Q01 << 7) + num) / (Q01 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                    } else {
                        pred = (int)(((Q01 << 7) - num) / (Q01 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                        pred = -pred;
                    }
                    workspace[1] = (ts4l_jcoef)pred;
                }
                if ((Al = coef_bits[2]) != 0 && workspace[8] == 0) {
                    num = 36 * Q00 * (DC2 - DC8);
                    if (num >= 0) {
                        pred = (int)(((Q10 << 7) + num) / (Q10 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                    } else {
                        pred = (int)(((Q10 << 7) - num) / (Q10 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                        pred = -pred;
                    }
                    workspace[8] = (ts4l_jcoef)pred;
                }
                if ((Al = coef_bits[3]) != 0 && workspace[16] == 0) {
                    num = 9 * Q00 * (DC2 + DC8 - 2 * DC5);
                    if (num >= 0) {
                        pred = (int)(((Q20 << 7) + num) / (Q20 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                    } else {
                        pred = (int)(((Q20 << 7) - num) / (Q20 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                        pred = -pred;
                    }
                    workspace[16] = (ts4l_jcoef)pred;
                }
                if ((Al = coef_bits[4]) != 0 && workspace[9] == 0) {
                    num = 5 * Q00 * (DC1 - DC3 - DC7 + DC9);
                    if (num >= 0) {
                        pred = (int)(((Q11 << 7) + num) / (Q11 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                    } else {
                        pred = (int)(((Q11 << 7) - num) / (Q11 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                        pred = -pred;
                    }
                    workspace[9] = (ts4l_jcoef)pred;
                }
                if ((Al = coef_bits[5]) != 0 && workspace[2] == 0) {
                    num = 9 * Q00 * (DC4 + DC6 - 2 * DC5);
                    if (num >= 0) {
                        pred = (int)(((Q02 << 7) + num) / (Q02 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                    } else {
                        pred = (int)(((Q02 << 7) - num) / (Q02 << 8));
                        if (Al > 0 && pred >= (1 << Al))
                            pred = (1 << Al) - 1;
                        pred = -pred;
                    }
                    workspace[2] = (ts4l_jcoef)pred;
                }
                (*inverse_DCT)(cinfo, compptr, (ts4l_jcoef *)workspace, output_ptr, output_col);
                DC1 = DC2;
                DC2 = DC3;
                DC4 = DC5;
                DC5 = DC6;
                DC7 = DC8;
                DC8 = DC9;
                buffer_ptr++, prev_block_row++, next_block_row++;
                output_col += compptr->DCT_scaled_size;
            }
            output_ptr += compptr->DCT_scaled_size;
        }
    }
    if (++(cinfo->output_iMCU_row) < cinfo->total_iMCU_rows)
        return 3;
    return 4;
}


