/* Loader_DLL.xex 0x8344C840-0x8344CABC, executable version 0.0.0.3. */
/* Library routine: libjpeg initial_setup (jdinput.c). */

#include "l8_jpeg.h"

extern ts4l_u32 fn_8344EED8(unsigned int a, unsigned int b);

void ts4l_jpeg_initial_setup_8344C840(ts4l_jcinfo *cinfo)
{
    int ci;
    ts4l_jcomp *compptr;

    if ((int)cinfo->image_height > 65500 || (int)cinfo->image_width > 65500)
        TS4L_ERREXIT1(cinfo, 41, 65500);

    if (cinfo->data_precision != 8)
        TS4L_ERREXIT1(cinfo, 15, cinfo->data_precision);

    if (cinfo->num_components > 10)
        TS4L_ERREXIT2(cinfo, 26, cinfo->num_components, 10);

    cinfo->max_h_samp_factor = 1;
    cinfo->max_v_samp_factor = 1;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if (compptr->h_samp_factor <= 0 || compptr->h_samp_factor > 4 ||
            compptr->v_samp_factor <= 0 || compptr->v_samp_factor > 4)
            TS4L_ERREXIT(cinfo, 18);
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
        compptr->width_in_blocks = (ts4l_u32)fn_8344EED8(
            cinfo->image_width * compptr->h_samp_factor, cinfo->max_h_samp_factor * 8);
        compptr->height_in_blocks = (ts4l_u32)fn_8344EED8(
            cinfo->image_height * compptr->v_samp_factor, cinfo->max_v_samp_factor * 8);
        compptr->downsampled_width = (ts4l_u32)fn_8344EED8(
            cinfo->image_width * compptr->h_samp_factor, cinfo->max_h_samp_factor);
        compptr->downsampled_height = (ts4l_u32)fn_8344EED8(
            cinfo->image_height * compptr->v_samp_factor, cinfo->max_v_samp_factor);
        compptr->component_needed = 1;
        compptr->quant_table = 0;
    }

    cinfo->total_iMCU_rows =
        (ts4l_u32)fn_8344EED8(cinfo->image_height, cinfo->max_v_samp_factor * 8);

    if (cinfo->comps_in_scan < cinfo->num_components || cinfo->progressive_mode)
        cinfo->inputctl->has_multiple_scans = 1;
    else
        cinfo->inputctl->has_multiple_scans = 0;
}
