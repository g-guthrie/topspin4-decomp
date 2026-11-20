/* Loader_DLL.xex 0x83460F90-0x834610E0, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcprepct.c): create_context_buffer. */
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

struct ts4l_compress_struct;
typedef struct ts4l_error_mgr {
    void (*error_exit)(struct ts4l_compress_struct *cinfo);
    char pad4[0x10];
    int msg_code;
} ts4l_error_mgr;
typedef struct ts4l_memory_mgr {
    void *(*alloc_small)(struct ts4l_compress_struct *cinfo, int pool_id, unsigned long sizeofobject);
    void *alloc_large;
    JSAMPARRAY (*alloc_sarray)(struct ts4l_compress_struct *cinfo, int pool_id, JDIMENSION samplesperrow,
                               JDIMENSION numrows);
} ts4l_memory_mgr;
typedef struct ts4l_component_info {
    char pad0[0x08];
    int h_samp_factor;
    int v_samp_factor;
    char pad10[0x1c - 0x10];
    JDIMENSION width_in_blocks;
    char pad20[0x54 - 0x20];
} ts4l_component_info;
typedef struct ts4l_downsampler {
    void *start_pass;
    void *downsample;
    int need_context_rows;
} ts4l_downsampler;
typedef struct ts4l_prep_controller {
    void (*start_pass)(void);
    void (*pre_process_data)(void);
    JSAMPARRAY color_buf[10];
    char pad[0x40 - 0x30];
} ts4l_prep_controller;
typedef struct ts4l_compress_struct {
    ts4l_error_mgr *err;
    ts4l_memory_mgr *mem;
    char pad8[0x3c - 0x08];
    int num_components;
    char pad40[4];
    ts4l_component_info *comp_info;
    char pad48[0xf0 - 0x48];
    int max_h_samp_factor;
    int max_v_samp_factor;
    char padf8[0x15c - 0xf8];
    ts4l_prep_controller *prep;
    char pad160[0x16c - 0x160];
    ts4l_downsampler *downsample;
} ts4l_compress_struct;

extern void *fn_833E3AD0(void *dst, const void *src, unsigned long n);

void ts4l_jpeg_create_context_buffer_83460F90(ts4l_compress_struct *cinfo)
{
    ts4l_prep_controller *prep = cinfo->prep;
    int rgroup_height = cinfo->max_v_samp_factor;
    int ci, i;
    ts4l_component_info *compptr;
    JSAMPARRAY true_buffer, fake_buffer;

    fake_buffer = (JSAMPARRAY)(*cinfo->mem->alloc_small)(cinfo, 1,
        (cinfo->num_components * 5 * rgroup_height) * sizeof(JSAMPROW));

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        true_buffer = (*cinfo->mem->alloc_sarray)(cinfo, 1,
            (JDIMENSION)(((long)compptr->width_in_blocks * 8 * cinfo->max_h_samp_factor) / compptr->h_samp_factor),
            (JDIMENSION)(3 * rgroup_height));
        fn_833E3AD0(fake_buffer + rgroup_height, true_buffer, 3 * rgroup_height * sizeof(JSAMPROW));
        for (i = 0; i < rgroup_height; i++) {
            fake_buffer[i] = true_buffer[2 * rgroup_height + i];
            fake_buffer[4 * rgroup_height + i] = true_buffer[i];
        }
        prep->color_buf[ci] = fake_buffer + rgroup_height;
        fake_buffer += 5 * rgroup_height;
    }
}
