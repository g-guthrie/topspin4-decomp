/* Loader_DLL.xex 0x83463130-0x83463340, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcmaster.c): per_scan_setup. */
#include "l44_jpeg.h"

extern long ts4l_jpeg_jdiv_round_up_8344EED8(long a, long b);

void ts4l_jpeg_per_scan_setup_83463130(struct ts4l_jcomp *cinfo)
{
    int ci, mcublks, tmp;
    struct ts4l_jpeg_component_info *compptr;

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
        if (cinfo->comps_in_scan <= 0 || cinfo->comps_in_scan > 4)
            TS4L_CERREXIT2(cinfo, 0x1a, cinfo->comps_in_scan, 4);

        cinfo->MCUs_per_row = (unsigned int)ts4l_jpeg_jdiv_round_up_8344EED8((long)cinfo->image_width, (long)(cinfo->max_h_samp_factor * 8));
        cinfo->MCU_rows_in_scan = (unsigned int)ts4l_jpeg_jdiv_round_up_8344EED8((long)cinfo->image_height, (long)(cinfo->max_v_samp_factor * 8));

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
                TS4L_CERREXIT(cinfo, 0xd);
            while (mcublks-- > 0) {
                cinfo->MCU_membership[cinfo->blocks_in_MCU++] = ci;
            }
        }
    }

    if (cinfo->restart_in_rows > 0) {
        long nominal = (long)cinfo->restart_in_rows * (long)cinfo->MCUs_per_row;
        cinfo->restart_interval = (unsigned int)(nominal < 65535L ? nominal : 65535L);
    }
}
