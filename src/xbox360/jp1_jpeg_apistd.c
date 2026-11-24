/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression API, jdapistd.c style. (JP1) */
#include "jp1_jpeg.h"

enum { JP1_JERR_BAD_STATE = 0x14 };
int ts4_loop_get_u32_off14_882E3070(struct ts4_jpeg_decomp *cinfo); /* output_pass_setup */
void ts4_jpeg_jinit_master_decompress_882EE7D8(struct ts4_jpeg_decomp *cinfo);                    /* jinit_master_decompress */

/* Starts decompression: runs the master setup and, for single-scan images, preloads input (Swing_DLL.xex 0x882E3228). */
int ts4_jpeg_start_decompress_882E3228(struct ts4_jpeg_decomp *cinfo)
{
    if (cinfo->global_state == JP1_DSTATE_READY) {
        ts4_jpeg_jinit_master_decompress_882EE7D8(cinfo);
        if (cinfo->buffered_image) {
            cinfo->global_state = JP1_DSTATE_BUFIMAGE;
            return 1;
        }
        cinfo->global_state = JP1_DSTATE_PRELOAD;
    }
    if (cinfo->global_state == JP1_DSTATE_PRELOAD) {
        if (cinfo->inputctl->has_multiple_scans) {
            for (;;) {
                int retcode;
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
    } else if (cinfo->global_state != JP1_DSTATE_PRESCAN)
        JP1_ERREXIT1(cinfo, JP1_JERR_BAD_STATE, cinfo->global_state);
    return ts4_loop_get_u32_off14_882E3070(cinfo);
}
