/* Loader_DLL.xex 0x83440C38-0x83441048, executable version 0.0.0.3. */
/* Library routines: libjpeg jdapistd.c (jpeg_start_output, jpeg_finish_output,
   jpeg_start_decompress) and jdmarker.c get_soi. */
#include "l21_jp1_jpeg_8344E498.h"

extern int ts4l_loop_get_u32_off14_83440958(struct ts4l_jpeg_decomp *cinfo);
extern void ts4l_jpeg_jinit_master_decompress_8344EE68(struct ts4l_jpeg_decomp *cinfo);

int ts4l_jpeg_start_output_83440C38(struct ts4l_jpeg_decomp *cinfo, int scan_number)
{
    if (cinfo->global_state != 207 && cinfo->global_state != 204)
        TS4L_ERREXIT1(cinfo, 20, cinfo->global_state);
    if (scan_number <= 0)
        scan_number = 1;
    if (cinfo->inputctl->eoi_reached && scan_number > cinfo->input_scan_number)
        scan_number = cinfo->input_scan_number;
    cinfo->output_scan_number = scan_number;
    return ts4l_loop_get_u32_off14_83440958(cinfo);
}

int ts4l_jpeg_finish_output_83440CE0(struct ts4l_jpeg_decomp *cinfo)
{
    if ((cinfo->global_state == 205 || cinfo->global_state == 206) && cinfo->buffered_image) {
        (*cinfo->master->finish_output_pass)(cinfo);
        cinfo->global_state = 208;
    } else if (cinfo->global_state != 208) {
        TS4L_ERREXIT1(cinfo, 20, cinfo->global_state);
    }
    while (cinfo->input_scan_number <= cinfo->output_scan_number && !cinfo->inputctl->eoi_reached) {
        if ((*cinfo->inputctl->consume_input)(cinfo) == 0)
            return 0;
    }
    cinfo->global_state = 207;
    return 1;
}

int ts4l_jpeg_start_decompress_83440DE8(struct ts4l_jpeg_decomp *cinfo)
{
    int retcode;

    if (cinfo->global_state == 202) {
        ts4l_jpeg_jinit_master_decompress_8344EE68(cinfo);
        if (cinfo->buffered_image) {
            cinfo->global_state = 207;
            return 1;
        }
        cinfo->global_state = 203;
    }
    if (cinfo->global_state == 203) {
        if (cinfo->inputctl->has_multiple_scans) {
            for (;;) {
                if (cinfo->progress != 0)
                    (*cinfo->progress->progress_monitor)(cinfo);
                retcode = (*cinfo->inputctl->consume_input)(cinfo);
                if (retcode == 0)
                    return 0;
                if (retcode == 2)
                    break;
                if (cinfo->progress != 0 && (retcode == 3 || retcode == 1)) {
                    if (++cinfo->progress->pass_counter >= cinfo->progress->pass_limit)
                        cinfo->progress->pass_limit += (int)cinfo->total_iMCU_rows;
                }
            }
        }
        cinfo->output_scan_number = cinfo->input_scan_number;
    } else if (cinfo->global_state != 204) {
        TS4L_ERREXIT1(cinfo, 20, cinfo->global_state);
    }
    return ts4l_loop_get_u32_off14_83440958(cinfo);
}

int ts4l_jpeg_get_soi_83440F60(struct ts4l_jpeg_decomp *cinfo)
{
    int i;

    TS4L_TRACEMS(cinfo, 1, 102);

    if (cinfo->marker->saw_SOI)
        TS4L_ERREXIT(cinfo, 61);

    for (i = 0; i < 16; i++) {
        cinfo->arith_dc_L[i] = 0;
        cinfo->arith_dc_U[i] = 1;
        cinfo->arith_ac_K[i] = 5;
    }
    cinfo->restart_interval = 0;

    cinfo->jpeg_color_space = 0;
    cinfo->CCIR601_sampling = 0;

    cinfo->saw_JFIF_marker = 0;
    cinfo->JFIF_major_version = 1;
    cinfo->JFIF_minor_version = 1;
    cinfo->density_unit = 0;
    cinfo->X_density = 1;
    cinfo->Y_density = 1;
    cinfo->saw_Adobe_marker = 0;
    cinfo->Adobe_transform = 0;

    cinfo->marker->saw_SOI = 1;
    return 1;
}
