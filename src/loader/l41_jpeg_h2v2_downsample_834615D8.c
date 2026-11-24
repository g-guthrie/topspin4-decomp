/* Loader_DLL.xex 0x834615D8-0x834616C8, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcsample.c): h2v2_downsample, with the inlined expand_right_edge. */
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

typedef struct ts4l_compress_struct {
    char pad0[0x1c];
    JDIMENSION image_width;
    char pad20[0xf4 - 0x20];
    int max_v_samp_factor;
} ts4l_compress_ptr_s, *ts4l_compress_ptr;

typedef struct ts4l_component_info {
    char pad0[0x0c];
    int v_samp_factor;
    char pad10[0x1c - 0x10];
    JDIMENSION width_in_blocks;
} ts4l_component_info;

#ifdef _MSC_VER
static __forceinline
#else
static
#endif
void expand_right_edge(JSAMPARRAY image_data, int num_rows, JDIMENSION input_cols, JDIMENSION output_cols)
{
    JSAMPROW ptr;
    JSAMPLE pixval;
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

void ts4l_jpeg_h2v2_downsample_834615D8(ts4l_compress_ptr cinfo, ts4l_component_info *compptr,
                                       JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    int inrow, outrow;
    JDIMENSION outcol;
    JDIMENSION output_cols = compptr->width_in_blocks * 8;
    JSAMPROW inptr0, inptr1, outptr;
    int bias;

    expand_right_edge(input_data, cinfo->max_v_samp_factor, cinfo->image_width, output_cols * 2);
    inrow = 0;
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr0 = input_data[inrow];
        inptr1 = input_data[inrow + 1];
        bias = 1;
        for (outcol = 0; outcol < output_cols; outcol++) {
            *outptr++ = (JSAMPLE)((inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1] + bias) >> 2);
            bias ^= 3;
            inptr0 += 2;
            inptr1 += 2;
        }
        inrow += 2;
    }
}
