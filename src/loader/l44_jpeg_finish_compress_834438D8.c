/* Loader_DLL.xex 0x834438D8-0x83443A80, executable version 0.0.0.3. */
/* Library routine: libjpeg jcapimin.c jpeg_finish_compress. */
#include "l44_jpeg.h"

extern void ts4l_if_get_u32_off4_8344E298(struct ts4l_jcomp *cinfo);

void ts4l_jpeg_finish_compress_834438D8(struct ts4l_jcomp *cinfo)
{
    unsigned int iMCU_row;

    if (cinfo->global_state == 101 || cinfo->global_state == 102) {
        if (cinfo->next_scanline < cinfo->image_height)
            TS4L_CERREXIT(cinfo, 67);
        (*cinfo->master->finish_pass)(cinfo);
    } else if (cinfo->global_state != 103) {
        TS4L_CERREXIT1(cinfo, 20, cinfo->global_state);
    }
    while (!cinfo->master->is_last_pass) {
        (*cinfo->master->prepare_for_pass)(cinfo);
        for (iMCU_row = 0; iMCU_row < cinfo->total_iMCU_rows; iMCU_row++) {
            if (cinfo->progress != 0) {
                cinfo->progress->pass_counter = (int)iMCU_row;
                cinfo->progress->pass_limit = (int)cinfo->total_iMCU_rows;
                (*cinfo->progress->progress_monitor)(TS4L_J(cinfo));
            }
            if (!(*cinfo->coef->compress_data)(cinfo, 0))
                TS4L_CERREXIT(cinfo, 24);
        }
        (*cinfo->master->finish_pass)(cinfo);
    }
    (*cinfo->marker->write_file_trailer)(cinfo);
    (*cinfo->dest->term_destination)(cinfo);
    ts4l_if_get_u32_off4_8344E298(cinfo);
}
