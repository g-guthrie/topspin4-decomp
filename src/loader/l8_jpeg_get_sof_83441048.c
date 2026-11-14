/* Loader_DLL.xex 0x83441048-0x83441498, executable version 0.0.0.3. */
/* Library routine: libjpeg get_sof (jdmarker.c). */

#include "l8_jpeg.h"

int ts4l_jpeg_get_sof_83441048(ts4l_jcinfo *cinfo, int is_prog, int is_arith)
{
    int length;
    int c;
    int ci;
    ts4l_jcomp *compptr;
    TS4L_INPUT_VARS(cinfo);

    cinfo->progressive_mode = is_prog;
    cinfo->arith_code = is_arith;

    TS4L_INPUT_2BYTES(cinfo, length, return 0);
    TS4L_INPUT_BYTE(cinfo, cinfo->data_precision, return 0);
    TS4L_INPUT_2BYTES(cinfo, cinfo->image_height, return 0);
    TS4L_INPUT_2BYTES(cinfo, cinfo->image_width, return 0);
    TS4L_INPUT_BYTE(cinfo, cinfo->num_components, return 0);

    length -= 8;

    TS4L_TRACEMS4(cinfo, 1, 100, cinfo->unread_marker, (int)cinfo->image_width,
                  (int)cinfo->image_height, cinfo->num_components);

    if (cinfo->marker->saw_SOF)
        TS4L_ERREXIT(cinfo, 58);
    if (cinfo->image_height <= 0 || cinfo->image_width <= 0 || cinfo->num_components <= 0)
        TS4L_ERREXIT(cinfo, 32);
    if (length != (cinfo->num_components * 3))
        TS4L_ERREXIT(cinfo, 11);

    if (cinfo->comp_info == 0)
        cinfo->comp_info = (ts4l_jcomp *)(*cinfo->mem->alloc_small)(
            cinfo, 1, cinfo->num_components * sizeof(ts4l_jcomp));

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        compptr->component_index = ci;
        TS4L_INPUT_BYTE(cinfo, compptr->component_id, return 0);
        TS4L_INPUT_BYTE(cinfo, c, return 0);
        compptr->h_samp_factor = (c >> 4) & 15;
        compptr->v_samp_factor = (c) & 15;
        TS4L_INPUT_BYTE(cinfo, compptr->quant_tbl_no, return 0);
        TS4L_TRACEMS4(cinfo, 1, 101, compptr->component_id, compptr->h_samp_factor,
                      compptr->v_samp_factor, compptr->quant_tbl_no);
    }

    cinfo->marker->saw_SOF = 1;
    TS4L_INPUT_SYNC(cinfo);
    return 1;
}
