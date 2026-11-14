/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b compression master control (jcmaster.c). */
#include "ex8_jpeg.h"

long ts4_jpeg_jdiv_round_up_882EE848(long a, long b); /* jdiv_round_up */

enum {
    EX8_JERR_BAD_PRECISION = 0x0f,
    EX8_JERR_BAD_PROG_SCRIPT = 0x11,
    EX8_JERR_BAD_SAMPLING = 0x12,
    EX8_JERR_BAD_SCAN_SCRIPT = 0x13,
    EX8_JERR_BAD_MCU_SIZE = 0x0d,
    EX8_JERR_MISSING_DATA = 0x2d,
    EX8_JERR_NOT_COMPILED = 0x30,
    EX8_JERR_COMPONENT_COUNT = 0x1a,
    EX8_JERR_EMPTY_IMAGE = 0x20,
    EX8_JERR_IMAGE_TOO_BIG = 0x29
};

/* jpeg_scan_info: one entry of a multi-scan script. */
typedef struct ex8_scan_info {
    int comps_in_scan;       /* 0x00 */
    int component_index[4];  /* 0x04 */
    int Ss;                  /* 0x14 */
    int Se;                  /* 0x18 */
    int Ah;                  /* 0x1c */
    int Al;                  /* 0x20 */
} ex8_scan_info;

void ts4_get_u32_off154_883020A8(ex8_jcomp *cinfo);   /* pass_startup */
void ts4_if_get_u32_off174_88302100(ex8_jcomp *cinfo); /* finish_pass_master */

typedef struct ex8_comp_master {
    ex8_jcmaster pub;        /* 0x00 */
    int pass_type;           /* 0x14 */
    int pass_number;         /* 0x18 */
    int total_passes;        /* 0x1c */
    int scan_number;         /* 0x20 */
} ex8_comp_master;

/* Validates the image parameters and computes the component dimensions. */
void ex8_initial_setup_88301358(ex8_jcomp *cinfo)
{
    int ci;
    ex8_jcinfo *compptr;

    if (cinfo->image_height <= 0 || cinfo->image_width <= 0 || cinfo->num_components <= 0 ||
        cinfo->input_components <= 0)
        EX8_ERREXIT(cinfo, EX8_JERR_EMPTY_IMAGE);

    if ((long)cinfo->image_height > (long)65500 || (long)cinfo->image_width > (long)65500)
        EX8_ERREXIT1(cinfo, EX8_JERR_IMAGE_TOO_BIG, (unsigned int)65500);

    if (cinfo->data_precision != 8)
        EX8_ERREXIT1(cinfo, EX8_JERR_BAD_PRECISION, cinfo->data_precision);

    if (cinfo->num_components > 10) {
        cinfo->err->msg_code = EX8_JERR_COMPONENT_COUNT;
        cinfo->err->msg_parm[0] = cinfo->num_components;
        cinfo->err->msg_parm[1] = 10;
        (*cinfo->err->error_exit)(cinfo);
    }

    cinfo->max_h_samp_factor = 1;
    cinfo->max_v_samp_factor = 1;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if (compptr->h_samp_factor <= 0 || compptr->h_samp_factor > 4 || compptr->v_samp_factor <= 0 ||
            compptr->v_samp_factor > 4)
            EX8_ERREXIT(cinfo, EX8_JERR_BAD_SAMPLING);
        cinfo->max_h_samp_factor =
            cinfo->max_h_samp_factor > compptr->h_samp_factor ? cinfo->max_h_samp_factor : compptr->h_samp_factor;
        cinfo->max_v_samp_factor =
            cinfo->max_v_samp_factor > compptr->v_samp_factor ? cinfo->max_v_samp_factor : compptr->v_samp_factor;
    }

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        compptr->component_index = ci;
        compptr->DCT_scaled_size = 8;
        compptr->width_in_blocks = (unsigned int)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_width * (long)compptr->h_samp_factor,
                                                             (long)(cinfo->max_h_samp_factor * 8));
        compptr->height_in_blocks = (unsigned int)ts4_jpeg_jdiv_round_up_882EE848(
            (long)cinfo->image_height * (long)compptr->v_samp_factor, (long)(cinfo->max_v_samp_factor * 8));
        compptr->downsampled_width = (unsigned int)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_width * (long)compptr->h_samp_factor,
                                                               (long)cinfo->max_h_samp_factor);
        compptr->downsampled_height = (unsigned int)ts4_jpeg_jdiv_round_up_882EE848(
            (long)cinfo->image_height * (long)compptr->v_samp_factor, (long)cinfo->max_v_samp_factor);
        compptr->component_needed = 1;
    }

    cinfo->total_iMCU_rows =
        (unsigned int)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_height, (long)(cinfo->max_v_samp_factor * 8));
}

/* Checks that a scan script is legal for sequential or progressive output. */
void ex8_validate_script_883015E8(ex8_jcomp *cinfo)
{
    const ex8_scan_info *scanptr;
    int scanno, ncomps, ci, coefi, thisi;
    int Ss, Se, Ah, Al;
    int component_sent[10];
    int *last_bitpos_ptr;
    int last_bitpos[10][64];

    if (cinfo->num_scans <= 0)
        EX8_ERREXIT1(cinfo, EX8_JERR_BAD_SCAN_SCRIPT, 0);

    scanptr = (const ex8_scan_info *)cinfo->scan_info;
    if (scanptr->Ss != 0 || scanptr->Se != 64 - 1) {
        cinfo->progressive_mode = 1;
        last_bitpos_ptr = &last_bitpos[0][0];
        for (ci = 0; ci < cinfo->num_components; ci++)
            for (coefi = 0; coefi < 64; coefi++)
                *last_bitpos_ptr++ = -1;
    } else {
        cinfo->progressive_mode = 0;
        for (ci = 0; ci < cinfo->num_components; ci++)
            component_sent[ci] = 0;
    }

    for (scanno = 1; scanno <= cinfo->num_scans; scanptr++, scanno++) {
        ncomps = scanptr->comps_in_scan;
        if (ncomps <= 0 || ncomps > 4) {
            cinfo->err->msg_code = EX8_JERR_COMPONENT_COUNT;
            cinfo->err->msg_parm[0] = ncomps;
            cinfo->err->msg_parm[1] = 4;
            (*cinfo->err->error_exit)(cinfo);
        }
        for (ci = 0; ci < ncomps; ci++) {
            thisi = scanptr->component_index[ci];
            if (thisi < 0 || thisi >= cinfo->num_components)
                EX8_ERREXIT1(cinfo, EX8_JERR_BAD_SCAN_SCRIPT, scanno);
            if (ci > 0 && thisi <= scanptr->component_index[ci - 1])
                EX8_ERREXIT1(cinfo, EX8_JERR_BAD_SCAN_SCRIPT, scanno);
        }
        Ss = scanptr->Ss;
        Se = scanptr->Se;
        Ah = scanptr->Ah;
        Al = scanptr->Al;
        if (cinfo->progressive_mode) {
            if (Ss < 0 || Ss >= 64 || Se < Ss || Se >= 64 || Ah < 0 || Ah > 10 || Al < 0 || Al > 10)
                EX8_ERREXIT1(cinfo, EX8_JERR_BAD_PROG_SCRIPT, scanno);
            if (Ss == 0) {
                if (Se != 0)
                    EX8_ERREXIT1(cinfo, EX8_JERR_BAD_PROG_SCRIPT, scanno);
            } else {
                if (ncomps != 1)
                    EX8_ERREXIT1(cinfo, EX8_JERR_BAD_PROG_SCRIPT, scanno);
            }
            for (ci = 0; ci < ncomps; ci++) {
                last_bitpos_ptr = &last_bitpos[scanptr->component_index[ci]][0];
                if (Ss != 0 && last_bitpos_ptr[0] < 0)
                    EX8_ERREXIT1(cinfo, EX8_JERR_BAD_PROG_SCRIPT, scanno);
                for (coefi = Ss; coefi <= Se; coefi++) {
                    if (last_bitpos_ptr[coefi] < 0) {
                        if (Ah != 0)
                            EX8_ERREXIT1(cinfo, EX8_JERR_BAD_PROG_SCRIPT, scanno);
                    } else {
                        if (Ah != last_bitpos_ptr[coefi] || Al != Ah - 1)
                            EX8_ERREXIT1(cinfo, EX8_JERR_BAD_PROG_SCRIPT, scanno);
                    }
                    last_bitpos_ptr[coefi] = Al;
                }
            }
        } else {
            if (Ss != 0 || Se != 64 - 1 || Ah != 0 || Al != 0)
                EX8_ERREXIT1(cinfo, EX8_JERR_BAD_PROG_SCRIPT, scanno);
            for (ci = 0; ci < ncomps; ci++) {
                thisi = scanptr->component_index[ci];
                if (component_sent[thisi])
                    EX8_ERREXIT1(cinfo, EX8_JERR_BAD_SCAN_SCRIPT, scanno);
                component_sent[thisi] = 1;
            }
        }
    }

    if (cinfo->progressive_mode) {
        for (ci = 0; ci < cinfo->num_components; ci++) {
            if (last_bitpos[ci][0] < 0)
                EX8_ERREXIT(cinfo, EX8_JERR_MISSING_DATA);
        }
    } else {
        for (ci = 0; ci < cinfo->num_components; ci++) {
            if (!component_sent[ci])
                EX8_ERREXIT(cinfo, EX8_JERR_MISSING_DATA);
        }
    }
}

/* Chooses the components and spectral parameters of the current scan. */
void ex8_select_scan_parameters_88301AA8(ex8_jcomp *cinfo)
{
    int ci;

    if (cinfo->scan_info != 0) {
        ex8_comp_master *master = (ex8_comp_master *)cinfo->master;
        const ex8_scan_info *scanptr = (const ex8_scan_info *)cinfo->scan_info + master->scan_number;

        cinfo->comps_in_scan = scanptr->comps_in_scan;
        for (ci = 0; ci < scanptr->comps_in_scan; ci++)
            cinfo->cur_comp_info[ci] = &cinfo->comp_info[scanptr->component_index[ci]];
        cinfo->Ss = scanptr->Ss;
        cinfo->Se = scanptr->Se;
        cinfo->Ah = scanptr->Ah;
        cinfo->Al = scanptr->Al;
    } else {
        if (cinfo->num_components > 4) {
            cinfo->err->msg_code = EX8_JERR_COMPONENT_COUNT;
            cinfo->err->msg_parm[0] = cinfo->num_components;
            cinfo->err->msg_parm[1] = 4;
            (*cinfo->err->error_exit)(cinfo);
        }
        cinfo->comps_in_scan = cinfo->num_components;
        for (ci = 0; ci < cinfo->num_components; ci++)
            cinfo->cur_comp_info[ci] = &cinfo->comp_info[ci];
        cinfo->Ss = 0;
        cinfo->Se = 64 - 1;
        cinfo->Ah = 0;
        cinfo->Al = 0;
    }
}

/* Computes the MCU layout of the current scan. */
void ex8_per_scan_setup_88301BF0(ex8_jcomp *cinfo)
{
    int ci, mcublks, tmp;
    ex8_jcinfo *compptr;

    if (cinfo->comps_in_scan == 1) {
        compptr = cinfo->cur_comp_info[0];

        cinfo->MCUs_per_row = compptr->width_in_blocks;
        cinfo->MCU_rows_in_scan = compptr->height_in_blocks;

        compptr->MCU_width = 1;
        compptr->MCU_height = 1;
        compptr->MCU_blocks = 1;
        compptr->MCU_sample_width = 8;
        compptr->last_col_width = 1;

        tmp = (int)(compptr->height_in_blocks % compptr->v_samp_factor);
        if (tmp == 0)
            tmp = compptr->v_samp_factor;
        compptr->last_row_height = tmp;

        cinfo->blocks_in_MCU = 1;
        cinfo->MCU_membership[0] = 0;
    } else {
        if (cinfo->comps_in_scan <= 0 || cinfo->comps_in_scan > 4) {
            cinfo->err->msg_code = EX8_JERR_COMPONENT_COUNT;
            cinfo->err->msg_parm[0] = cinfo->comps_in_scan;
            cinfo->err->msg_parm[1] = 4;
            (*cinfo->err->error_exit)(cinfo);
        }

        cinfo->MCUs_per_row = (unsigned int)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_width, (long)(cinfo->max_h_samp_factor * 8));
        cinfo->MCU_rows_in_scan =
            (unsigned int)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_height, (long)(cinfo->max_v_samp_factor * 8));

        cinfo->blocks_in_MCU = 0;

        for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
            compptr = cinfo->cur_comp_info[ci];
            compptr->MCU_width = compptr->h_samp_factor;
            compptr->MCU_height = compptr->v_samp_factor;
            compptr->MCU_blocks = compptr->MCU_width * compptr->MCU_height;
            compptr->MCU_sample_width = compptr->MCU_width * 8;
            tmp = (int)(compptr->width_in_blocks % compptr->MCU_width);
            if (tmp == 0)
                tmp = compptr->MCU_width;
            compptr->last_col_width = tmp;
            tmp = (int)(compptr->height_in_blocks % compptr->MCU_height);
            if (tmp == 0)
                tmp = compptr->MCU_height;
            compptr->last_row_height = tmp;
            mcublks = compptr->MCU_blocks;
            if (cinfo->blocks_in_MCU + mcublks > 10)
                EX8_ERREXIT(cinfo, EX8_JERR_BAD_MCU_SIZE);
            while (mcublks-- > 0)
                cinfo->MCU_membership[cinfo->blocks_in_MCU++] = ci;
        }
    }

    if (cinfo->restart_in_rows > 0) {
        long nominal = (long)cinfo->restart_in_rows * (long)cinfo->MCUs_per_row;
        cinfo->restart_interval = (unsigned int)(nominal < 65535L ? nominal : 65535L);
    }
}

/* Sets up the modules for the next pass (main, Huffman optimization, or output). */
void ex8_prepare_for_pass_88301E00(ex8_jcomp *cinfo)
{
    ex8_comp_master *master = (ex8_comp_master *)cinfo->master;

    switch (master->pass_type) {
    case 0:
        ex8_select_scan_parameters_88301AA8(cinfo);
        ex8_per_scan_setup_88301BF0(cinfo);
        if (!cinfo->raw_data_in) {
            (*cinfo->cconvert->start_pass)(cinfo);
            (*cinfo->downsample->start_pass)(cinfo);
            (*cinfo->prep->start_pass)(cinfo, 0);
        }
        (*cinfo->fdct->start_pass)(cinfo);
        (*cinfo->entropy->start_pass)(cinfo, cinfo->optimize_coding);
        (*cinfo->coef->start_pass)(cinfo, (master->total_passes > 1 ? 3 : 0));
        (*cinfo->main_ctl->start_pass)(cinfo, 0);
        if (cinfo->optimize_coding)
            master->pub.call_pass_startup = 0;
        else
            master->pub.call_pass_startup = 1;
        break;
    case 1:
        ex8_select_scan_parameters_88301AA8(cinfo);
        ex8_per_scan_setup_88301BF0(cinfo);
        if (cinfo->Ss != 0 || cinfo->Ah == 0 || cinfo->arith_code) {
            (*cinfo->entropy->start_pass)(cinfo, 1);
            (*cinfo->coef->start_pass)(cinfo, 2);
            master->pub.call_pass_startup = 0;
            break;
        }
        master->pass_type = 2;
        master->pass_number++;
        /* fall through */
    case 2:
        if (!cinfo->optimize_coding) {
            ex8_select_scan_parameters_88301AA8(cinfo);
            ex8_per_scan_setup_88301BF0(cinfo);
        }
        (*cinfo->entropy->start_pass)(cinfo, 0);
        (*cinfo->coef->start_pass)(cinfo, 2);
        if (master->scan_number == 0)
            (*cinfo->marker->write_frame_header)(cinfo);
        (*cinfo->marker->write_scan_header)(cinfo);
        master->pub.call_pass_startup = 0;
        break;
    default:
        EX8_ERREXIT(cinfo, EX8_JERR_NOT_COMPILED);
        break;
    }

    master->pub.is_last_pass = (master->pass_number == master->total_passes - 1);

    if (cinfo->progress != 0) {
        cinfo->progress->completed_passes = master->pass_number;
        cinfo->progress->total_passes = master->total_passes;
    }
}

/* Allocates the compression master and validates the scan parameters. */
void ex8_jinit_c_master_control_883021B0(ex8_jcomp *cinfo, int transcode_only)
{
    ex8_comp_master *master;

    master = (ex8_comp_master *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_comp_master));
    cinfo->master = &master->pub;
    master->pub.prepare_for_pass = ex8_prepare_for_pass_88301E00;
    master->pub.pass_startup = ts4_get_u32_off154_883020A8;
    master->pub.finish_pass = ts4_if_get_u32_off174_88302100;
    master->pub.is_last_pass = 0;

    ex8_initial_setup_88301358(cinfo);

    if (cinfo->scan_info != 0) {
        ex8_validate_script_883015E8(cinfo);
    } else {
        cinfo->progressive_mode = 0;
        cinfo->num_scans = 1;
    }

    if (cinfo->progressive_mode)
        cinfo->optimize_coding = 1;

    if (transcode_only) {
        if (cinfo->optimize_coding)
            master->pass_type = 1;
        else
            master->pass_type = 2;
    } else {
        master->pass_type = 0;
    }
    master->scan_number = 0;
    master->pass_number = 0;
    if (cinfo->optimize_coding)
        master->total_passes = cinfo->num_scans * 2;
    else
        master->total_passes = cinfo->num_scans;
}
