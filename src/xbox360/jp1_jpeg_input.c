/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression input controller, IJG jdinput.c style. (JP1) */
#include "jp1_jpeg.h"

enum {
    JP1_JERR_BAD_PRECISION = 0x0f, JP1_JERR_BAD_SAMPLING = 0x12, JP1_JERR_BAD_MCU_SIZE = 0x0d,
    JP1_JERR_COMPONENT_COUNT = 0x1a, JP1_JERR_EOI_EXPECTED = 0x23, JP1_JERR_IMAGE_TOO_BIG = 0x29,
    JP1_JERR_NO_QUANT_TABLE = 0x34, JP1_JERR_SOF_NO_SOS = 0x3b
};

/* Rounds a / b up (jutils.c jdiv_round_up). */
long ts4_jpeg_jdiv_round_up_882EE848(long a, long b);
/* Begins a scan's input pass (start_input_pass). */
void ts4_get_fn_882EC5E0_882EC8A8(struct ts4_jpeg_decomp *cinfo);

/* Verifies the frame header and derives the per-component block and sample dimensions
 * (Swing_DLL.xex 0x882EC360). */
void ts4_jpeg_initial_setup_882EC360(struct ts4_jpeg_decomp *cinfo)
{
    int ci;
    struct ts4_jpeg_component_info *compptr;

    if ((long)cinfo->image_height > 65500L || (long)cinfo->image_width > 65500L)
        JP1_ERREXIT1(cinfo, JP1_JERR_IMAGE_TOO_BIG, (unsigned int)65500);
    if (cinfo->data_precision != 8)
        JP1_ERREXIT1(cinfo, JP1_JERR_BAD_PRECISION, cinfo->data_precision);
    if (cinfo->num_components > 10)
        JP1_ERREXIT2(cinfo, JP1_JERR_COMPONENT_COUNT, cinfo->num_components, 10);
    cinfo->max_h_samp_factor = 1;
    cinfo->max_v_samp_factor = 1;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if (compptr->h_samp_factor <= 0 || compptr->h_samp_factor > 4 ||
            compptr->v_samp_factor <= 0 || compptr->v_samp_factor > 4)
            JP1_ERREXIT(cinfo, JP1_JERR_BAD_SAMPLING);
        cinfo->max_h_samp_factor =
            cinfo->max_h_samp_factor > compptr->h_samp_factor ? cinfo->max_h_samp_factor
                                                              : compptr->h_samp_factor;
        cinfo->max_v_samp_factor =
            cinfo->max_v_samp_factor > compptr->v_samp_factor ? cinfo->max_v_samp_factor
                                                              : compptr->v_samp_factor;
    }
    cinfo->min_DCT_scaled_size = 8;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        compptr->DCT_scaled_size = 8;
        compptr->width_in_blocks = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848(
            (long)cinfo->image_width * (long)compptr->h_samp_factor,
            (long)(cinfo->max_h_samp_factor * 8));
        compptr->height_in_blocks = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848(
            (long)cinfo->image_height * (long)compptr->v_samp_factor,
            (long)(cinfo->max_v_samp_factor * 8));
        compptr->downsampled_width = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848(
            (long)cinfo->image_width * (long)compptr->h_samp_factor,
            (long)cinfo->max_h_samp_factor);
        compptr->downsampled_height = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848(
            (long)cinfo->image_height * (long)compptr->v_samp_factor,
            (long)cinfo->max_v_samp_factor);
        compptr->component_needed = 1;
        compptr->quant_table = 0;
    }
    cinfo->total_iMCU_rows =
        (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_height, (long)(cinfo->max_v_samp_factor * 8));
    if (cinfo->comps_in_scan < cinfo->num_components || cinfo->progressive_mode)
        cinfo->inputctl->has_multiple_scans = 1;
    else
        cinfo->inputctl->has_multiple_scans = 0;
}

/* Computes MCU geometry for the current scan (Swing_DLL.xex 0x882EC5E0). */
void ts4_jpeg_per_scan_setup_882EC5E0(struct ts4_jpeg_decomp *cinfo)
{
    int ci, mcublks, tmp;
    struct ts4_jpeg_component_info *compptr;

    if (cinfo->comps_in_scan == 1) {
        compptr = cinfo->cur_comp_info[0];
        cinfo->MCUs_per_row = compptr->width_in_blocks;
        cinfo->MCU_rows_in_scan = compptr->height_in_blocks;
        compptr->MCU_width = 1;
        compptr->MCU_height = 1;
        compptr->MCU_blocks = 1;
        compptr->MCU_sample_width = compptr->DCT_scaled_size;
        compptr->last_col_width = 1;
        tmp = (int)(compptr->height_in_blocks % (unsigned int)compptr->v_samp_factor);
        if (tmp == 0)
            tmp = compptr->v_samp_factor;
        compptr->last_row_height = tmp;
        cinfo->blocks_in_MCU = 1;
        cinfo->MCU_membership[0] = 0;
    } else {
        if (cinfo->comps_in_scan <= 0 || cinfo->comps_in_scan > 4)
            JP1_ERREXIT2(cinfo, JP1_JERR_COMPONENT_COUNT, cinfo->comps_in_scan, 4);
        cinfo->MCUs_per_row =
            (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_width, (long)(cinfo->max_h_samp_factor * 8));
        cinfo->MCU_rows_in_scan =
            (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_height, (long)(cinfo->max_v_samp_factor * 8));
        cinfo->blocks_in_MCU = 0;
        for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
            compptr = cinfo->cur_comp_info[ci];
            compptr->MCU_width = compptr->h_samp_factor;
            compptr->MCU_height = compptr->v_samp_factor;
            compptr->MCU_blocks = compptr->MCU_width * compptr->MCU_height;
            compptr->MCU_sample_width = compptr->MCU_width * compptr->DCT_scaled_size;
            tmp = (int)(compptr->width_in_blocks % (unsigned int)compptr->MCU_width);
            if (tmp == 0)
                tmp = compptr->MCU_width;
            compptr->last_col_width = tmp;
            tmp = (int)(compptr->height_in_blocks % (unsigned int)compptr->MCU_height);
            if (tmp == 0)
                tmp = compptr->MCU_height;
            compptr->last_row_height = tmp;
            mcublks = compptr->MCU_blocks;
            if (cinfo->blocks_in_MCU + mcublks > 10)
                JP1_ERREXIT(cinfo, JP1_JERR_BAD_MCU_SIZE);
            while (mcublks-- > 0)
                cinfo->MCU_membership[cinfo->blocks_in_MCU++] = ci;
        }
    }
}

/* Copies each scan component's quantization table so later DQT markers cannot change it
 * (Swing_DLL.xex 0x882EC7D0). */
void ts4_jpeg_latch_quant_tables_882EC7D0(struct ts4_jpeg_decomp *cinfo)
{
    int ci, qtblno;
    struct ts4_jpeg_component_info *compptr;
    struct ts4_jpeg_quant_tbl *qtbl;

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        if (compptr->quant_table != 0)
            continue;
        qtblno = compptr->quant_tbl_no;
        if (qtblno < 0 || qtblno >= 4 || cinfo->quant_tbl_ptrs[qtblno] == 0)
            JP1_ERREXIT1(cinfo, JP1_JERR_NO_QUANT_TABLE, qtblno);
        qtbl = (struct ts4_jpeg_quant_tbl *)(*cinfo->mem->alloc_small)(
            cinfo, 1, sizeof(struct ts4_jpeg_quant_tbl));
        memcpy(qtbl, cinfo->quant_tbl_ptrs[qtblno], sizeof(struct ts4_jpeg_quant_tbl));
        compptr->quant_table = qtbl;
    }
}

/* Reads markers up to the next SOS or EOI and sets up the scan (Swing_DLL.xex 0x882EC918). */
int ts4_jpeg_consume_markers_882EC918(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_inputctl *inputctl = (struct ts4_jpeg_my_inputctl *)cinfo->inputctl;
    int val;

    if (inputctl->pub.eoi_reached)
        return 2;
    val = (*cinfo->marker->read_markers)(cinfo);
    switch (val) {
    case 1:
        if (inputctl->inheaders) {
            ts4_jpeg_initial_setup_882EC360(cinfo);
            inputctl->inheaders = 0;
        } else {
            if (!inputctl->pub.has_multiple_scans)
                JP1_ERREXIT(cinfo, JP1_JERR_EOI_EXPECTED);
            ts4_get_fn_882EC5E0_882EC8A8(cinfo);
        }
        break;
    case 2:
        inputctl->pub.eoi_reached = 1;
        if (inputctl->inheaders) {
            if (cinfo->marker->saw_SOF)
                JP1_ERREXIT(cinfo, JP1_JERR_SOF_NO_SOS);
        } else {
            if (cinfo->output_scan_number > cinfo->input_scan_number)
                cinfo->output_scan_number = cinfo->input_scan_number;
        }
        break;
    case 0:
        break;
    }
    return val;
}
