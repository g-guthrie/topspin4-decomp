/* Loader_DLL.xex 0x834623B8-0x83462424, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jccolor.c): grayscale_convert. */
#include "l44_jpeg.h"

void ts4l_jpeg_grayscale_convert_834623B8(struct ts4l_jcomp *cinfo, unsigned char **input_buf,
                                         unsigned char ***output_buf, unsigned int output_row, int num_rows)
{
    unsigned char *inptr, *outptr;
    unsigned int col;
    unsigned int num_cols = cinfo->image_width;
    int instride = cinfo->input_components;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr = output_buf[0][output_row++];
        for (col = 0; col < num_cols; col++) {
            outptr[col] = inptr[0];
            inptr += instride;
        }
    }
}
