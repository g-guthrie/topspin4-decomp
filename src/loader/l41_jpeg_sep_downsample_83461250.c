/* Loader_DLL.xex 0x83461250-0x834612DC, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcsample.c): sep_downsample. */
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef unsigned int JDIMENSION;

struct ts4l_compress_struct;
typedef struct ts4l_component_info {
    char pad0[0x0c];
    int v_samp_factor;
    char pad10[0x54 - 0x10];
} ts4l_component_info;

typedef void (*ts4l_downsample1_ptr)(struct ts4l_compress_struct *cinfo, ts4l_component_info *compptr,
                                     JSAMPARRAY input_data, JSAMPARRAY output_data);

typedef struct ts4l_downsampler {
    void *start_pass;
    void *downsample;
    int need_context_rows;
    ts4l_downsample1_ptr methods[10];
} ts4l_downsampler;

typedef struct ts4l_compress_struct {
    char pad0[0x3c];
    int num_components;
    char pad40[4];
    ts4l_component_info *comp_info;
    char pad48[0x16c - 0x48];
    ts4l_downsampler *downsample;
} ts4l_compress_struct;

void ts4l_jpeg_sep_downsample_83461250(ts4l_compress_struct *cinfo, JSAMPIMAGE input_buf,
                                       JDIMENSION in_row_index, JSAMPIMAGE output_buf,
                                       JDIMENSION out_row_group_index)
{
    ts4l_downsampler *downsample = cinfo->downsample;
    int ci;
    ts4l_component_info *compptr;
    JSAMPARRAY in_ptr, out_ptr;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        in_ptr = input_buf[ci] + in_row_index;
        out_ptr = output_buf[ci] + (out_row_group_index * compptr->v_samp_factor);
        (*downsample->methods[ci])(cinfo, compptr, in_ptr, out_ptr);
    }
}
