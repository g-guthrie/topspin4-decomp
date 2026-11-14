/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libjpeg jdmarker.c routines (decoder side). */

#include "ex7_jpeg.h"

int ts4_jpeg_next_marker_882E4B70(ex7_jpeg_decompress_struct *cinfo); /* next_marker */

/* Swallow the expected restart marker or let the source resync (jdmarker.c read_restart_marker). Swing_DLL.xex 0x882E50E0 */
int ex7_jpeg_read_restart_marker_882E50E0(ex7_jpeg_decompress_struct *cinfo)
{
    if (cinfo->unread_marker == 0) {
        if (!ts4_jpeg_next_marker_882E4B70(cinfo))
            return 0;
    }
    if (cinfo->unread_marker == (0xD0 + cinfo->marker->next_restart_num)) {
        cinfo->err->msg_code = 98; /* JTRC_RESTART */
        cinfo->err->msg_parm.i[0] = cinfo->marker->next_restart_num;
        (*cinfo->err->emit_message)(cinfo, 3);
        cinfo->unread_marker = 0;
    } else {
        if (!(*cinfo->src->resync_to_restart)(cinfo, cinfo->marker->next_restart_num))
            return 0;
    }
    cinfo->marker->next_restart_num = (cinfo->marker->next_restart_num + 1) & 7;
    return 1;
}

/* Resynchronise to the next restart marker after a corrupted stream (jpeg_resync_to_restart). Swing_DLL.xex 0x882E51C8 */
int ex7_jpeg_resync_to_restart_882E51C8(ex7_jpeg_decompress_struct *cinfo, int desired)
{
    int marker = cinfo->unread_marker;
    int action = 1;

    cinfo->err->msg_code = 121; /* JWRN_MUST_RESYNC */
    cinfo->err->msg_parm.i[0] = marker;
    cinfo->err->msg_parm.i[1] = desired;
    (*cinfo->err->emit_message)(cinfo, -1);
    for (;;) {
        if (marker < 0xC0)
            action = 2;
        else if (marker < 0xD0 || marker > 0xD7)
            action = 3;
        else {
            if (marker == (0xD0 + ((desired + 1) & 7)) || marker == (0xD0 + ((desired + 2) & 7)))
                action = 3;
            else if (marker == (0xD0 + ((desired - 1) & 7)) || marker == (0xD0 + ((desired - 2) & 7)))
                action = 2;
            else
                action = 1;
        }
        cinfo->err->msg_code = 97; /* JTRC_RECOVERY_ACTION */
        cinfo->err->msg_parm.i[0] = marker;
        cinfo->err->msg_parm.i[1] = action;
        (*cinfo->err->emit_message)(cinfo, 4);
        switch (action) {
        case 1:
            cinfo->unread_marker = 0;
            return 1;
        case 2:
            if (!ts4_jpeg_next_marker_882E4B70(cinfo))
                return 0;
            marker = cinfo->unread_marker;
            break;
        case 3:
            return 1;
        }
    }
}

void ts4_get_u32_off1bc_882E5320(void *cinfo);   /* reset_marker_reader */
int ts4_jpeg_read_markers_882E4DD0(void *cinfo);                    /* read_markers */
int ts4_jpeg_skip_variable_882E4A70(void *cinfo);                    /* skip_variable */
int ts4_jpeg_get_interesting_appn_882E48C8(void *cinfo);                    /* get_interesting_appn */

/* Create the marker reader object and reset its state (jdmarker.c jinit_marker_reader). Swing_DLL.xex 0x882E5348 */
void ex7_jpeg_jinit_marker_reader_882E5348(ex7_jpeg_decompress_struct *cinfo)
{
    ex7_jpeg_marker_reader *marker;
    int i;

    marker = (ex7_jpeg_marker_reader *)(*cinfo->mem->alloc_small)(cinfo, 0, 0xac);
    cinfo->marker = marker;
    marker->reset_marker_reader = ts4_get_u32_off1bc_882E5320;
    marker->read_markers = ts4_jpeg_read_markers_882E4DD0;
    marker->read_restart_marker = (int (*)(void *))ex7_jpeg_read_restart_marker_882E50E0;
    marker->process_COM = ts4_jpeg_skip_variable_882E4A70;
    marker->length_limit_COM = 0;
    for (i = 0; i < 16; i++) {
        marker->process_APPn[i] = ts4_jpeg_skip_variable_882E4A70;
        marker->length_limit_APPn[i] = 0;
    }
    marker->process_APPn[0] = ts4_jpeg_get_interesting_appn_882E48C8;
    marker->process_APPn[14] = ts4_jpeg_get_interesting_appn_882E48C8;
    cinfo->comp_info = 0;
    cinfo->input_scan_number = 0;
    cinfo->unread_marker = 0;
    {
        ex7_jpeg_marker_reader *reset_marker = cinfo->marker;
        reset_marker->saw_SOI = 0;
        reset_marker->saw_SOF = 0;
        reset_marker->discarded_bytes = 0;
        reset_marker->cur_marker = 0;
    }
}
