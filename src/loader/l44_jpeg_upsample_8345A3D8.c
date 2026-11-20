/* Loader_DLL.xex 0x8345A3D8-0x8345A4B0, 0x8345A518-0x8345A808, executable version 0.0.0.3. */
/* Library routines: libjpeg jdsample.c (int_upsample, h2v2_upsample, h2v1_fancy_upsample, h2v2_fancy_upsample). */
#include "l44_jpeg.h"

struct ts4l_up_state {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);   /* 0x00 */
    void *upsample;                                       /* 0x04 */
    int need_context_rows;                                /* 0x08 */
    ts4l_jsamparray color_buf[10];                        /* 0x0c */
    void *methods[10];                                    /* 0x34 */
    int next_row_out;                                     /* 0x5c */
    unsigned int rows_to_go;                              /* 0x60 */
    int rowgroup_height[10];                              /* 0x64 */
    unsigned char h_expand[10];                           /* 0x8c */
    unsigned char v_expand[10];                           /* 0x96 */
};

extern void ts4l_jpeg_jcopy_sample_rows_8344EF30(ts4l_jsamparray input_array, int source_row, ts4l_jsamparray output_array,
                        int dest_row, int num_rows, unsigned int num_cols);

void ts4l_jpeg_int_upsample_8345A3D8(struct ts4l_jpeg_decomp *cinfo,
                                     struct ts4l_jpeg_component_info *compptr,
                                     ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr)
{
    struct ts4l_up_state *upsample = (struct ts4l_up_state *)cinfo->upsample;
    ts4l_jsamparray output_data = *output_data_ptr;
    unsigned char *inptr, *outptr;
    unsigned char invalue;
    int h;
    unsigned char *outend;
    int h_expand, v_expand;
    int inrow, outrow;

    h_expand = upsample->h_expand[compptr->component_index];
    v_expand = upsample->v_expand[compptr->component_index];

    inrow = outrow = 0;
    while (outrow < cinfo->max_v_samp_factor) {
        inptr = input_data[inrow];
        outptr = output_data[outrow];
        outend = outptr + cinfo->output_width;
        while (outptr < outend) {
            invalue = *inptr++;
            for (h = h_expand; h > 0; h--) {
                *outptr++ = invalue;
            }
        }
        if (v_expand > 1) {
            ts4l_jpeg_jcopy_sample_rows_8344EF30(output_data, outrow, output_data, outrow + 1, v_expand - 1, cinfo->output_width);
        }
        inrow++;
        outrow += v_expand;
    }
}

void ts4l_jpeg_h2v2_upsample_8345A518(struct ts4l_jpeg_decomp *cinfo,
                                      struct ts4l_jpeg_component_info *compptr,
                                      ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr)
{
    ts4l_jsamparray output_data = *output_data_ptr;
    unsigned char *inptr, *outptr;
    unsigned char invalue;
    unsigned char *outend;
    int inrow, outrow;

    (void)compptr;
    inrow = outrow = 0;
    while (outrow < cinfo->max_v_samp_factor) {
        inptr = input_data[inrow];
        outptr = output_data[outrow];
        outend = outptr + cinfo->output_width;
        while (outptr < outend) {
            invalue = *inptr++;
            *outptr++ = invalue;
            *outptr++ = invalue;
        }
        ts4l_jpeg_jcopy_sample_rows_8344EF30(output_data, outrow, output_data, outrow + 1, 1, cinfo->output_width);
        inrow++;
        outrow += 2;
    }
}

void ts4l_jpeg_h2v1_fancy_upsample_8345A5B8(struct ts4l_jpeg_decomp *cinfo,
                                            struct ts4l_jpeg_component_info *compptr,
                                            ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr)
{
    ts4l_jsamparray output_data = *output_data_ptr;
    unsigned char *inptr, *outptr;
    int invalue;
    unsigned int colctr;
    int inrow;

    for (inrow = 0; inrow < cinfo->max_v_samp_factor; inrow++) {
        inptr = input_data[inrow];
        outptr = output_data[inrow];
        invalue = *inptr++;
        *outptr++ = (unsigned char)invalue;
        *outptr++ = (unsigned char)((invalue * 3 + *inptr + 2) >> 2);

        for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
            invalue = *inptr++ * 3;
            *outptr++ = (unsigned char)((invalue + inptr[-2] + 1) >> 2);
            *outptr++ = (unsigned char)((invalue + *inptr + 2) >> 2);
        }

        invalue = *inptr;
        *outptr++ = (unsigned char)((invalue * 3 + inptr[-1] + 1) >> 2);
        *outptr++ = (unsigned char)invalue;
    }
}

void ts4l_jpeg_h2v2_fancy_upsample_8345A6A0(struct ts4l_jpeg_decomp *cinfo,
                                            struct ts4l_jpeg_component_info *compptr,
                                            ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr)
{
    ts4l_jsamparray output_data = *output_data_ptr;
    unsigned char *inptr0, *inptr1, *outptr;
    int thiscolsum, lastcolsum, nextcolsum;
    unsigned int colctr;
    int inrow, outrow, v;

    inrow = outrow = 0;
    while (outrow < cinfo->max_v_samp_factor) {
        for (v = 0; v < 2; v++) {
            inptr0 = input_data[inrow];
            if (v == 0)
                inptr1 = input_data[inrow - 1];
            else
                inptr1 = input_data[inrow + 1];
            outptr = output_data[outrow++];

            thiscolsum = (*inptr0++) * 3 + (*inptr1++);
            nextcolsum = (*inptr0++) * 3 + (*inptr1++);
            *outptr++ = (unsigned char)((thiscolsum * 4 + 8) >> 4);
            *outptr++ = (unsigned char)((thiscolsum * 3 + nextcolsum + 7) >> 4);
            lastcolsum = thiscolsum;
            thiscolsum = nextcolsum;

            for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
                nextcolsum = (*inptr0++) * 3 + (*inptr1++);
                *outptr++ = (unsigned char)((thiscolsum * 3 + lastcolsum + 8) >> 4);
                *outptr++ = (unsigned char)((thiscolsum * 3 + nextcolsum + 7) >> 4);
                lastcolsum = thiscolsum;
                thiscolsum = nextcolsum;
            }

            *outptr++ = (unsigned char)((thiscolsum * 3 + lastcolsum + 8) >> 4);
            *outptr++ = (unsigned char)((thiscolsum * 4 + 7) >> 4);
        }
        inrow++;
    }
}
