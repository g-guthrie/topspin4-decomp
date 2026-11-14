/* Loader_DLL.xex 0x834616C8-0x83461974, 0x83461978-0x83461B0C, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcsample.c): h2v2_smooth_downsample and fullsize_smooth_downsample,
   with the inlined expand_right_edge. */
#include "l44_jpeg.h"

#ifdef _MSC_VER
static __forceinline
#else
static
#endif
void expand_right_edge(unsigned char **image_data, int num_rows, unsigned int input_cols,
                       unsigned int output_cols)
{
    unsigned char *ptr;
    unsigned char pixval;
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

void ts4l_jpeg_h2v2_smooth_downsample_834616C8(struct ts4l_jcomp *cinfo,
                                              struct ts4l_jpeg_component_info *compptr,
                                              unsigned char **input_data, unsigned char **output_data)
{
    int inrow, outrow;
    unsigned int colctr;
    unsigned int output_cols = compptr->width_in_blocks * 8;
    unsigned char *inptr0, *inptr1, *above_ptr, *below_ptr, *outptr;
    int membersum, neighsum, memberscale, neighscale;

    expand_right_edge(input_data - 1, cinfo->max_v_samp_factor + 2, cinfo->image_width, output_cols * 2);

    memberscale = 16384 - cinfo->smoothing_factor * 80;
    neighscale = cinfo->smoothing_factor * 16;

    inrow = 0;
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr0 = input_data[inrow];
        inptr1 = input_data[inrow + 1];
        above_ptr = input_data[inrow - 1];
        below_ptr = input_data[inrow + 2];

        membersum = inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1];
        neighsum = above_ptr[0] + above_ptr[1] + below_ptr[0] + below_ptr[1] + inptr0[0] + inptr0[2] +
                   inptr1[0] + inptr1[2];
        neighsum += neighsum;
        neighsum += above_ptr[0] + above_ptr[2] + below_ptr[0] + below_ptr[2];
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr++ = (unsigned char)((membersum + 32768) >> 16);
        inptr0 += 2;
        inptr1 += 2;
        above_ptr += 2;
        below_ptr += 2;

        for (colctr = output_cols - 2; colctr > 0; colctr--) {
            membersum = inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1];
            neighsum = above_ptr[0] + above_ptr[1] + below_ptr[0] + below_ptr[1] + inptr0[-1] + inptr0[2] +
                       inptr1[-1] + inptr1[2];
            neighsum += neighsum;
            neighsum += above_ptr[-1] + above_ptr[2] + below_ptr[-1] + below_ptr[2];
            membersum = membersum * memberscale + neighsum * neighscale;
            *outptr++ = (unsigned char)((membersum + 32768) >> 16);
            inptr0 += 2;
            inptr1 += 2;
            above_ptr += 2;
            below_ptr += 2;
        }

        membersum = inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1];
        neighsum = above_ptr[0] + above_ptr[1] + below_ptr[0] + below_ptr[1] + inptr0[-1] + inptr0[1] +
                   inptr1[-1] + inptr1[1];
        neighsum += neighsum;
        neighsum += above_ptr[-1] + above_ptr[1] + below_ptr[-1] + below_ptr[1];
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr = (unsigned char)((membersum + 32768) >> 16);
        inrow += 2;
    }
}

void ts4l_jpeg_fullsize_smooth_downsample_83461978(struct ts4l_jcomp *cinfo,
                                                  struct ts4l_jpeg_component_info *compptr,
                                                  unsigned char **input_data, unsigned char **output_data)
{
    int outrow;
    unsigned int colctr;
    unsigned int output_cols = compptr->width_in_blocks * 8;
    unsigned char *inptr, *above_ptr, *below_ptr, *outptr;
    int membersum, neighsum, memberscale, neighscale;
    int colsum, lastcolsum, nextcolsum;

    expand_right_edge(input_data - 1, cinfo->max_v_samp_factor + 2, cinfo->image_width, output_cols);

    memberscale = 65536 - cinfo->smoothing_factor * 512;
    neighscale = cinfo->smoothing_factor * 64;

    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr = input_data[outrow];
        above_ptr = input_data[outrow - 1];
        below_ptr = input_data[outrow + 1];

        colsum = *above_ptr++ + *below_ptr++ + *inptr;
        membersum = *inptr++;
        nextcolsum = *above_ptr + *below_ptr + *inptr;
        neighsum = colsum + (colsum - membersum) + nextcolsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr++ = (unsigned char)((membersum + 32768) >> 16);
        lastcolsum = colsum;
        colsum = nextcolsum;

        for (colctr = output_cols - 2; colctr > 0; colctr--) {
            membersum = *inptr++;
            above_ptr++;
            below_ptr++;
            nextcolsum = *above_ptr + *below_ptr + *inptr;
            neighsum = lastcolsum + (colsum - membersum) + nextcolsum;
            membersum = membersum * memberscale + neighsum * neighscale;
            *outptr++ = (unsigned char)((membersum + 32768) >> 16);
            lastcolsum = colsum;
            colsum = nextcolsum;
        }

        membersum = *inptr;
        neighsum = lastcolsum + (colsum - membersum) + colsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr = (unsigned char)((membersum + 32768) >> 16);
    }
}
