/* Loader_DLL.xex 0x83441F00-0x83442068, executable version 0.0.0.3. */
/* Library routine: libjpeg get_dri (jdmarker.c). */
#include "l21_jp1_jpeg_8344E498.h"

int ts4l_jpeg_get_dri_83441F00(struct ts4l_jpeg_decomp *cinfo)
{
    int length;
    unsigned int tmp;
    TS4L_INPUT_VARS(cinfo);

    TS4L_INPUT_2BYTES(cinfo, length, return 0);

    if (length != 4)
        TS4L_ERREXIT(cinfo, 11);

    TS4L_INPUT_2BYTES(cinfo, tmp, return 0);

    TS4L_TRACEMS1(cinfo, 1, 82, tmp);

    cinfo->restart_interval = tmp;

    TS4L_INPUT_SYNC(cinfo);
    return 1;
}
