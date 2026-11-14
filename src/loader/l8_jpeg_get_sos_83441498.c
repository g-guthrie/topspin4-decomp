/* Loader_DLL.xex 0x83441498-0x8344184C, executable version 0.0.0.3. */
/* Library routine: libjpeg get_sos (jdmarker.c). */

#include "l8_jpeg.h"

int ts4l_jpeg_get_sos_83441498(ts4l_jcinfo *cinfo)
{
    int length;
    int i;
    int ci;
    int n;
    int c;
    int cc;
    ts4l_jcomp *compptr;
    TS4L_INPUT_VARS(cinfo);

    if (!cinfo->marker->saw_SOF)
        TS4L_ERREXIT(cinfo, 62);

    TS4L_INPUT_2BYTES(cinfo, length, return 0);
    TS4L_INPUT_BYTE(cinfo, n, return 0);

    TS4L_TRACEMS1(cinfo, 1, 103, n);

    if (length != (n * 2 + 6) || n < 1 || n > 4)
        TS4L_ERREXIT(cinfo, 11);

    cinfo->comps_in_scan = n;

    for (i = 0; i < n; i++) {
        TS4L_INPUT_BYTE(cinfo, cc, return 0);
        TS4L_INPUT_BYTE(cinfo, c, return 0);

        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            if (cc == compptr->component_id)
                goto id_found;
        }

        TS4L_ERREXIT1(cinfo, 5, cc);

    id_found:

        cinfo->cur_comp_info[i] = compptr;
        compptr->dc_tbl_no = (c >> 4) & 15;
        compptr->ac_tbl_no = (c) & 15;

        TS4L_TRACEMS3(cinfo, 1, 104, cc, compptr->dc_tbl_no, compptr->ac_tbl_no);
    }

    TS4L_INPUT_BYTE(cinfo, c, return 0);
    cinfo->Ss = c;
    TS4L_INPUT_BYTE(cinfo, c, return 0);
    cinfo->Se = c;
    TS4L_INPUT_BYTE(cinfo, c, return 0);
    cinfo->Ah = (c >> 4) & 15;
    cinfo->Al = (c) & 15;

    TS4L_TRACEMS4(cinfo, 1, 105, cinfo->Ss, cinfo->Se, cinfo->Ah, cinfo->Al);

    cinfo->marker->next_restart_num = 0;
    cinfo->input_scan_number++;

    TS4L_INPUT_SYNC(cinfo);
    return 1;
}
