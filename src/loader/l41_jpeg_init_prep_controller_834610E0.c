/* Loader_DLL.xex 0x834610E0-0x834611FC, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcprepct.c): jinit_c_prep_controller. */
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

extern void ts4l_if_get_u32_off15c_83460A30(void);
extern void fn_83460B00(void);
extern void fn_83460D38(void);
extern void fn_83460F90(ts4l_compress_struct *cinfo);

void ts4l_jpeg_init_prep_controller_834610E0(ts4l_compress_struct *cinfo, int need_full_buffer)
{
    ts4l_prep_controller *prep;
    int ci;
    ts4l_component_info *compptr;

    if (need_full_buffer) {
        cinfo->err->msg_code = 4;
        (*cinfo->err->error_exit)(cinfo);
    }
    prep = (ts4l_prep_controller *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ts4l_prep_controller));
    cinfo->prep = prep;
    prep->start_pass = ts4l_if_get_u32_off15c_83460A30;
    if (cinfo->downsample->need_context_rows) {
        prep->pre_process_data = fn_83460D38;
        fn_83460F90(cinfo);
    } else {
        prep->pre_process_data = fn_83460B00;
        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            prep->color_buf[ci] = (*cinfo->mem->alloc_sarray)(cinfo, 1,
                (JDIMENSION)(((long)compptr->width_in_blocks * 8 * cinfo->max_h_samp_factor) / compptr->h_samp_factor),
                (JDIMENSION)cinfo->max_v_samp_factor);
        }
    }
}
