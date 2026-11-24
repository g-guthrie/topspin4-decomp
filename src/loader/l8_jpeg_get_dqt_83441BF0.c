/* Loader_DLL.xex 0x83441BF0-0x83441EFC, executable version 0.0.0.3. */
/* Library routine: libjpeg get_dqt (jdmarker.c). */

#include "l8_jpeg.h"

extern int lbl_8307A868[];
extern ts4l_jquant *fn_8344E350(ts4l_jcinfo *cinfo);

int ts4l_jpeg_get_dqt_83441BF0(ts4l_jcinfo *cinfo)
{
    int length;
    int n;
    int i;
    int prec;
    unsigned int tmp;
    ts4l_jquant *quant_ptr;
    TS4L_INPUT_VARS(cinfo);

    TS4L_INPUT_2BYTES(cinfo, length, return 0);
    length -= 2;

    while (length > 0) {
        TS4L_INPUT_BYTE(cinfo, n, return 0);
        prec = n >> 4;
        n &= 0x0F;

        TS4L_TRACEMS2(cinfo, 1, 81, n, prec);

        if (n >= 4)
            TS4L_ERREXIT1(cinfo, 31, n);
        if (cinfo->quant_tbl_ptrs[n] == 0)
            cinfo->quant_tbl_ptrs[n] = fn_8344E350(cinfo);
        quant_ptr = cinfo->quant_tbl_ptrs[n];

        for (i = 0; i < 64; i++) {
            if (prec) {
                TS4L_INPUT_2BYTES(cinfo, tmp, return 0);
            } else {
                TS4L_INPUT_BYTE(cinfo, tmp, return 0);
            }
            quant_ptr->quantval[lbl_8307A868[i]] = (unsigned short)tmp;
        }

        if (cinfo->err->trace_level >= 2) {
            for (i = 0; i < 64; i += 8) {
                TS4L_TRACEMS8(cinfo, 2, 93, quant_ptr->quantval[i], quant_ptr->quantval[i + 1],
                              quant_ptr->quantval[i + 2], quant_ptr->quantval[i + 3],
                              quant_ptr->quantval[i + 4], quant_ptr->quantval[i + 5],
                              quant_ptr->quantval[i + 6], quant_ptr->quantval[i + 7]);
            }
        }

        length -= 64 + 1;
        if (prec)
            length -= 64;
    }

    if (length != 0)
        TS4L_ERREXIT(cinfo, 11);

    TS4L_INPUT_SYNC(cinfo);
    return 1;
}
