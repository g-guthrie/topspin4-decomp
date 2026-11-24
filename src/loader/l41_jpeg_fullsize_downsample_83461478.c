/* Loader_DLL.xex 0x83461478-0x83461508, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcsample.c): fullsize_downsample, with the inlined expand_right_edge. */
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

extern void ts4l_jpeg_jcopy_sample_rows_8344EF30(JSAMPARRAY input_array, int source_row, JSAMPARRAY output_array, int dest_row, int num_rows, JDIMENSION num_cols);

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

void ts4l_jpeg_fullsize_downsample_83461478(ts4l_compress_ptr cinfo, ts4l_component_info *compptr,
                                            JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    ts4l_jpeg_jcopy_sample_rows_8344EF30(input_data, 0, output_data, 0, cinfo->max_v_samp_factor, cinfo->image_width);
    expand_right_edge(output_data, cinfo->max_v_samp_factor, cinfo->image_width, compptr->width_in_blocks * 8);
}
