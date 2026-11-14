/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b compressor main buffer controller (jcmainct.c) and coefficient controller (jccoefct.c). */
#include "ex8_jpeg.h"

void *ts4_tailcall_fn_8856ABA0_882EE910(void *ptr, unsigned int size); /* jzero_far */
long ts4_jpeg_jround_up_882EE870(long value, long base);                               /* jround_up */

enum { EX8_JERR_BAD_BUFFER_MODE = 4 };

typedef struct ex8_main_priv {
    ex8_jcmain pub;               /* 0x00 */
    unsigned int cur_iMCU_row;    /* 0x08 */
    unsigned int rowgroup_ctr;    /* 0x0c */
    int suspended;                /* 0x10 */
    int pass_mode;                /* 0x14 */
    ex8_jsamparray buffer[10];    /* 0x18 */
} ex8_main_priv;

typedef struct ex8_coef_priv {
    ex8_jccoef pub;                  /* 0x00 */
    unsigned int iMCU_row_num;       /* 0x08 */
    unsigned int mcu_ctr;            /* 0x0c */
    int MCU_vert_offset;             /* 0x10 */
    int MCU_rows_per_iMCU_row;       /* 0x14 */
    ex8_jblockrow MCU_buffer[10];    /* 0x18 */
    void *whole_image[4];            /* 0x40 */
    unsigned char pad50[0x68 - 0x50];
} ex8_coef_priv;

/* Simple (single-pass, no context) main-buffer data pump. */
void ex8_process_data_simple_main_882FAE80(ex8_jcomp *cinfo, ex8_jsamparray input_buf,
                                                  unsigned int *in_row_ctr, unsigned int in_rows_avail)
{
    ex8_main_priv *main = (ex8_main_priv *)cinfo->main_ctl;

    while (main->cur_iMCU_row < cinfo->total_iMCU_rows) {
        if (main->rowgroup_ctr < 8)
            (*cinfo->prep->pre_process_data)(cinfo, input_buf, in_row_ctr, in_rows_avail, main->buffer,
                                             &main->rowgroup_ctr, 8);
        if (main->rowgroup_ctr != 8)
            return;
        if (!(*cinfo->coef->compress_data)(cinfo, main->buffer)) {
            if (!main->suspended) {
                (*in_row_ctr)--;
                main->suspended = 1;
            }
            return;
        }
        if (main->suspended) {
            (*in_row_ctr)++;
            main->suspended = 0;
        }
        main->rowgroup_ctr = 0;
        main->cur_iMCU_row++;
    }
}

/* Prepares the main controller for a pass. */
void ex8_start_pass_main_882FAF88(ex8_jcomp *cinfo, int pass_mode)
{
    ex8_main_priv *main = (ex8_main_priv *)cinfo->main_ctl;

    if (cinfo->raw_data_in)
        return;
    main->cur_iMCU_row = 0;
    main->rowgroup_ctr = 0;
    main->suspended = 0;
    main->pass_mode = pass_mode;
    switch (pass_mode) {
    case 0:
        main->pub.process_data = ex8_process_data_simple_main_882FAE80;
        break;
    default:
        EX8_ERREXIT(cinfo, EX8_JERR_BAD_BUFFER_MODE);
        break;
    }
}

/* Allocates the main buffer controller and its per-component sample buffers. */
void ex8_jinit_c_main_controller_882FAFE0(ex8_jcomp *cinfo, int need_full_buffer)
{
    ex8_main_priv *main;
    int ci;
    ex8_jcinfo *compptr;

    main = (ex8_main_priv *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_main_priv));
    cinfo->main_ctl = &main->pub;
    main->pub.start_pass = ex8_start_pass_main_882FAF88;

    if (cinfo->raw_data_in)
        return;

    if (need_full_buffer) {
        EX8_ERREXIT(cinfo, EX8_JERR_BAD_BUFFER_MODE);
    } else {
        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            main->buffer[ci] = (*cinfo->mem->alloc_sarray)(cinfo, 1, compptr->width_in_blocks * 8,
                                                           compptr->v_samp_factor * 8);
        }
    }
}

/* Starts a new iMCU row of the coefficient controller. */
void ex8_start_iMCU_row_882FB0B8(ex8_jcomp *cinfo)
{
    ex8_coef_priv *coef = (ex8_coef_priv *)cinfo->coef;

    if (cinfo->comps_in_scan > 1) {
        coef->MCU_rows_per_iMCU_row = 1;
    } else {
        if (coef->iMCU_row_num < (cinfo->total_iMCU_rows - 1))
            coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->v_samp_factor;
        else
            coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->last_row_height;
    }

    coef->mcu_ctr = 0;
    coef->MCU_vert_offset = 0;
}

/* Single-pass: forward DCT the input rows and entropy-code each MCU. */
int ex8_compress_data_882FB128(ex8_jcomp *cinfo, ex8_jsamparray *input_buf)
{
    ex8_coef_priv *coef = (ex8_coef_priv *)cinfo->coef;
    unsigned int MCU_col_num;
    unsigned int last_MCU_col = cinfo->MCUs_per_row - 1;
    unsigned int last_iMCU_row = cinfo->total_iMCU_rows - 1;
    int blkn, bi, ci, yindex, yoffset, blockcnt;
    unsigned int ypos, xpos;
    ex8_jcinfo *compptr;

    for (yoffset = coef->MCU_vert_offset; yoffset < coef->MCU_rows_per_iMCU_row; yoffset++) {
        for (MCU_col_num = coef->mcu_ctr; MCU_col_num <= last_MCU_col; MCU_col_num++) {
            blkn = 0;
            for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
                compptr = cinfo->cur_comp_info[ci];
                blockcnt = (MCU_col_num < last_MCU_col) ? compptr->MCU_width : compptr->last_col_width;
                xpos = MCU_col_num * compptr->MCU_sample_width;
                ypos = yoffset * 8;
                for (yindex = 0; yindex < compptr->MCU_height; yindex++) {
                    if (coef->iMCU_row_num < last_iMCU_row || yoffset + yindex < compptr->last_row_height) {
                        (*cinfo->fdct->forward_DCT)(cinfo, compptr, input_buf[compptr->component_index],
                                                    coef->MCU_buffer[blkn], ypos, xpos, (unsigned int)blockcnt);
                        if (blockcnt < compptr->MCU_width) {
                            ts4_tailcall_fn_8856ABA0_882EE910(coef->MCU_buffer[blkn + blockcnt],
                                                              (compptr->MCU_width - blockcnt) * sizeof(ex8_jblock));
                            for (bi = blockcnt; bi < compptr->MCU_width; bi++)
                                coef->MCU_buffer[blkn + bi][0][0] = coef->MCU_buffer[blkn + bi - 1][0][0];
                        }
                    } else {
                        ts4_tailcall_fn_8856ABA0_882EE910(coef->MCU_buffer[blkn],
                                                          compptr->MCU_width * sizeof(ex8_jblock));
                        for (bi = 0; bi < compptr->MCU_width; bi++)
                            coef->MCU_buffer[blkn + bi][0][0] = coef->MCU_buffer[blkn - 1][0][0];
                    }
                    blkn += compptr->MCU_width;
                    ypos += 8;
                }
            }
            if (!(*cinfo->entropy->encode_mcu)(cinfo, coef->MCU_buffer)) {
                coef->MCU_vert_offset = yoffset;
                coef->mcu_ctr = MCU_col_num;
                return 0;
            }
        }
        coef->mcu_ctr = 0;
    }
    coef->iMCU_row_num++;
    ex8_start_iMCU_row_882FB0B8(cinfo);
    return 1;
}

/* Multi-pass: entropy-code MCUs out of the full-image coefficient buffer. */
int ex8_compress_output_882FB3D8(ex8_jcomp *cinfo, ex8_jsamparray *input_buf)
{
    ex8_coef_priv *coef = (ex8_coef_priv *)cinfo->coef;
    unsigned int MCU_col_num;
    int blkn, ci, xindex, yindex, yoffset, start_col;
    ex8_jblockarray buffer[4];
    ex8_jblockrow buffer_ptr;
    ex8_jcinfo *compptr;
    (void)input_buf;

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        buffer[ci] = (*cinfo->mem->access_virt_barray)(cinfo, coef->whole_image[compptr->component_index],
                                                       coef->iMCU_row_num * compptr->v_samp_factor,
                                                       (unsigned int)compptr->v_samp_factor, 0);
    }

    for (yoffset = coef->MCU_vert_offset; yoffset < coef->MCU_rows_per_iMCU_row; yoffset++) {
        for (MCU_col_num = coef->mcu_ctr; MCU_col_num < cinfo->MCUs_per_row; MCU_col_num++) {
            blkn = 0;
            for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
                compptr = cinfo->cur_comp_info[ci];
                start_col = MCU_col_num * compptr->MCU_width;
                for (yindex = 0; yindex < compptr->MCU_height; yindex++) {
                    buffer_ptr = buffer[ci][yindex + yoffset] + start_col;
                    for (xindex = 0; xindex < compptr->MCU_width; xindex++)
                        coef->MCU_buffer[blkn++] = buffer_ptr++;
                }
            }
            if (!(*cinfo->entropy->encode_mcu)(cinfo, coef->MCU_buffer)) {
                coef->MCU_vert_offset = yoffset;
                coef->mcu_ctr = MCU_col_num;
                return 0;
            }
        }
        coef->mcu_ctr = 0;
    }
    coef->iMCU_row_num++;
    ex8_start_iMCU_row_882FB0B8(cinfo);
    return 1;
}

/* First pass of a multi-pass compression: DCT into the virtual coefficient arrays. */
int ex8_compress_first_pass_882FB600(ex8_jcomp *cinfo, ex8_jsamparray *input_buf)
{
    ex8_coef_priv *coef = (ex8_coef_priv *)cinfo->coef;
    unsigned int last_iMCU_row = cinfo->total_iMCU_rows - 1;
    unsigned int blocks_across, MCUs_across, MCUindex;
    int bi, ci, h_samp_factor, block_row, block_rows, ndummy;
    ex8_jcoef lastDC;
    ex8_jcinfo *compptr;
    ex8_jblockarray buffer;
    ex8_jblockrow thisblockrow, lastblockrow;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        buffer = (*cinfo->mem->access_virt_barray)(cinfo, coef->whole_image[ci],
                                                   coef->iMCU_row_num * compptr->v_samp_factor,
                                                   (unsigned int)compptr->v_samp_factor, 1);
        if (coef->iMCU_row_num < last_iMCU_row) {
            block_rows = compptr->v_samp_factor;
        } else {
            block_rows = (int)(compptr->height_in_blocks % compptr->v_samp_factor);
            if (block_rows == 0)
                block_rows = compptr->v_samp_factor;
        }
        blocks_across = compptr->width_in_blocks;
        h_samp_factor = compptr->h_samp_factor;
        ndummy = (int)(blocks_across % h_samp_factor);
        if (ndummy > 0)
            ndummy = h_samp_factor - ndummy;
        for (block_row = 0; block_row < block_rows; block_row++) {
            thisblockrow = buffer[block_row];
            (*cinfo->fdct->forward_DCT)(cinfo, compptr, input_buf[ci], thisblockrow,
                                        (unsigned int)(block_row * 8), 0, (unsigned int)blocks_across);
            if (ndummy > 0) {
                thisblockrow += blocks_across;
                ts4_tailcall_fn_8856ABA0_882EE910(thisblockrow, ndummy * sizeof(ex8_jblock));
                lastDC = thisblockrow[-1][0];
                for (bi = 0; bi < ndummy; bi++)
                    thisblockrow[bi][0] = lastDC;
            }
        }
        if (coef->iMCU_row_num == last_iMCU_row) {
            blocks_across += ndummy;
            MCUs_across = blocks_across / h_samp_factor;
            for (block_row = block_rows; block_row < compptr->v_samp_factor; block_row++) {
                thisblockrow = buffer[block_row];
                lastblockrow = buffer[block_row - 1];
                ts4_tailcall_fn_8856ABA0_882EE910(thisblockrow, blocks_across * sizeof(ex8_jblock));
                for (MCUindex = 0; MCUindex < MCUs_across; MCUindex++) {
                    lastDC = lastblockrow[h_samp_factor - 1][0];
                    for (bi = 0; bi < h_samp_factor; bi++)
                        thisblockrow[bi][0] = lastDC;
                    thisblockrow += h_samp_factor;
                    lastblockrow += h_samp_factor;
                }
            }
        }
    }
    return ex8_compress_output_882FB3D8(cinfo, input_buf);
}

/* Starts a coefficient-controller pass in the requested buffer mode. */
void ex8_start_pass_coef_882FB820(ex8_jcomp *cinfo, int pass_mode)
{
    ex8_coef_priv *coef = (ex8_coef_priv *)cinfo->coef;

    coef->iMCU_row_num = 0;
    ex8_start_iMCU_row_882FB0B8(cinfo);

    switch (pass_mode) {
    case 0:
        if (coef->whole_image[0] != 0)
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_BUFFER_MODE);
        coef->pub.compress_data = ex8_compress_data_882FB128;
        break;
    case 3:
        if (coef->whole_image[0] == 0)
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_BUFFER_MODE);
        coef->pub.compress_data = ex8_compress_first_pass_882FB600;
        break;
    case 2:
        if (coef->whole_image[0] == 0)
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_BUFFER_MODE);
        coef->pub.compress_data = ex8_compress_output_882FB3D8;
        break;
    default:
        EX8_ERREXIT(cinfo, EX8_JERR_BAD_BUFFER_MODE);
        break;
    }
}

/* Allocates the coefficient controller (and virtual arrays when multi-pass). */
void ex8_jinit_c_coef_controller_882FB938(ex8_jcomp *cinfo, int need_full_buffer)
{
    ex8_coef_priv *coef;
    int ci, i;
    ex8_jcinfo *compptr;
    ex8_jblock *buffer;

    coef = (ex8_coef_priv *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_coef_priv));
    cinfo->coef = &coef->pub;
    coef->pub.start_pass = ex8_start_pass_coef_882FB820;

    if (need_full_buffer) {
        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            coef->whole_image[ci] = (*cinfo->mem->request_virt_barray)(
                cinfo, 1, 0, (unsigned int)ts4_jpeg_jround_up_882EE870((long)compptr->width_in_blocks, (long)compptr->h_samp_factor),
                (unsigned int)ts4_jpeg_jround_up_882EE870((long)compptr->height_in_blocks, (long)compptr->v_samp_factor),
                (unsigned int)compptr->v_samp_factor);
        }
    } else {
        buffer = (ex8_jblock *)(*cinfo->mem->alloc_large)(cinfo, 1, 10 * sizeof(ex8_jblock));
        for (i = 0; i < 10; i++)
            coef->MCU_buffer[i] = buffer + i;
        coef->whole_image[0] = 0;
    }
}
