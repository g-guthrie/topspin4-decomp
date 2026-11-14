/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "ex8_jpeg.h"

/* Replicates the last real column of each row into the padding columns (jcsample.c expand_right_edge). */
static void expand_right_edge(ex8_jsamparray image_data, int num_rows, unsigned int input_cols,
                              unsigned int output_cols)
{
    ex8_jsamprow ptr;
    ex8_joctet pixval;
    int count;
    int row;
    int numcols = (int)(output_cols - input_cols);

    if (numcols > 0) {
        for (row = 0; row < num_rows; row++) {
            ptr = image_data[row] + input_cols;
            pixval = ptr[-1];
            for (count = numcols; count > 0; count--)
                *ptr++ = pixval;
        }
    }
}

/* 2:1 horizontal and vertical downsampling with alternating rounding bias (jcsample.c h2v2_downsample). */
void ts4_jpeg_h2v2_downsample_883000A0(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray input_data,
                                       ex8_jsamparray output_data)
{
    int inrow, outrow;
    unsigned int outcol;
    unsigned int output_cols = compptr->width_in_blocks * 8;
    ex8_jsamprow inptr0, inptr1, outptr;
    int bias;

    expand_right_edge(input_data, cinfo->max_v_samp_factor, cinfo->image_width, output_cols * 2);

    inrow = 0;
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr0 = input_data[inrow];
        inptr1 = input_data[inrow + 1];
        bias = 1;
        for (outcol = 0; outcol < output_cols; outcol++) {
            *outptr++ = (ex8_joctet)((inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1] + bias) >> 2);
            bias ^= 3;
            inptr0 += 2;
            inptr1 += 2;
        }
        inrow += 2;
    }
}
