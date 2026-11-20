/* Loader_DLL.xex 0x834612E0-0x83461474, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcsample.c): int_downsample, with the inlined expand_right_edge. */
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

typedef struct ts4l_compress_struct {
    char pad0[0x1c];
    JDIMENSION image_width;
    char pad20[0xf0 - 0x20];
    int max_h_samp_factor;
    int max_v_samp_factor;
} ts4l_compress_ptr_s, *ts4l_compress_ptr;

typedef struct ts4l_component_info {
    char pad0[0x08];
    int h_samp_factor;
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

void ts4l_jpeg_int_downsample_834612E0(ts4l_compress_ptr cinfo, ts4l_component_info *compptr,
                                       JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    int inrow, outrow, h_expand, v_expand, numpix, numpix2, h, v;
    JDIMENSION outcol, outcol_h;
    JDIMENSION output_cols = compptr->width_in_blocks * 8;
    JSAMPROW inptr, outptr;
    long outvalue;

    h_expand = cinfo->max_h_samp_factor / compptr->h_samp_factor;
    v_expand = cinfo->max_v_samp_factor / compptr->v_samp_factor;
    numpix = h_expand * v_expand;
    numpix2 = numpix / 2;

    expand_right_edge(input_data, cinfo->max_v_samp_factor, cinfo->image_width, output_cols * h_expand);

    inrow = 0;
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        for (outcol = 0, outcol_h = 0; outcol < output_cols; outcol++, outcol_h += h_expand) {
            outvalue = 0;
            for (v = 0; v < v_expand; v++) {
                inptr = input_data[inrow + v] + outcol_h;
                for (h = 0; h < h_expand; h++)
                    outvalue += (long)*inptr++;
            }
            *outptr++ = (JSAMPLE)((outvalue + numpix2) / numpix);
        }
        inrow += v_expand;
    }
}
