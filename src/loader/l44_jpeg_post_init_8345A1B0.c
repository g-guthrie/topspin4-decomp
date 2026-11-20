/* Loader_DLL.xex 0x8345A1B0-0x8345A270, 0x8345A288-0x8345A3C0, executable version 0.0.0.3. */
/* Library routines: libjpeg jdpostct.c jinit_d_post_controller, jdsample.c sep_upsample. */
#include "l44_jpeg.h"

extern void ts4l_if_get_u32_off1b4_8345A0F8(struct ts4l_jpeg_decomp *cinfo, int pass_mode);

struct ts4l_post_ctl {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo, int pass_mode);  /* 0x00 */
    void *post_process_data;                                            /* 0x04 */
    void *whole_image;                                                  /* 0x08 */
    ts4l_jsamparray buffer;                                             /* 0x0c */
    unsigned int strip_height;                                          /* 0x10 */
    unsigned int starting_row;                                          /* 0x14 */
    unsigned int next_row;                                              /* 0x18 */
};

typedef void (*ts4l_up_method)(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jpeg_component_info *compptr,
                               ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr);

struct ts4l_sep_upsample {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);   /* 0x00 */
    void *upsample;                                       /* 0x04 */
    int need_context_rows;                                /* 0x08 */
    ts4l_jsamparray color_buf[10];                        /* 0x0c */
    ts4l_up_method methods[10];                           /* 0x34 */
    int next_row_out;                                     /* 0x5c */
    unsigned int rows_to_go;                              /* 0x60 */
    int rowgroup_height[10];                              /* 0x64 */
};

void ts4l_jpeg_jinit_d_post_controller_8345A1B0(struct ts4l_jpeg_decomp *cinfo, int need_full_buffer)
{
    struct ts4l_post_ctl *post;

    post = (struct ts4l_post_ctl *)(*cinfo->mem->alloc_small)(cinfo, 1, 0x1c);
    cinfo->post = (struct ts4l_jpeg_d_post *)post;
    post->start_pass = ts4l_if_get_u32_off1b4_8345A0F8;
    post->whole_image = 0;
    post->buffer = 0;

    if (cinfo->quantize_colors) {
        post->strip_height = (unsigned int)cinfo->max_v_samp_factor;
        if (need_full_buffer) {
            TS4L_ERREXIT(cinfo, 4);
        } else {
            post->buffer = (*cinfo->mem->alloc_sarray)(cinfo, 1,
                                                       cinfo->output_width * cinfo->out_color_components,
                                                       post->strip_height);
        }
    }
}

void ts4l_jpeg_sep_upsample_8345A288(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                     unsigned int *in_row_group_ctr, unsigned int in_row_groups_avail,
                                     ts4l_jsamparray output_buf, unsigned int *out_row_ctr,
                                     unsigned int out_rows_avail)
{
    struct ts4l_sep_upsample *upsample = (struct ts4l_sep_upsample *)cinfo->upsample;
    int ci;
    struct ts4l_jpeg_component_info *compptr;
    unsigned int num_rows;

    (void)in_row_groups_avail;
    if (upsample->next_row_out >= cinfo->max_v_samp_factor) {
        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            (*upsample->methods[ci])(cinfo, compptr,
                                     input_buf[ci] + (*in_row_group_ctr * upsample->rowgroup_height[ci]),
                                     upsample->color_buf + ci);
        }
        upsample->next_row_out = 0;
    }

    num_rows = (unsigned int)(cinfo->max_v_samp_factor - upsample->next_row_out);
    if (num_rows > upsample->rows_to_go)
        num_rows = upsample->rows_to_go;
    out_rows_avail -= *out_row_ctr;
    if (num_rows > out_rows_avail)
        num_rows = out_rows_avail;

    (*cinfo->cconvert->color_convert)(cinfo, (ts4l_jsampimage)upsample->color_buf,
                                      (unsigned int)upsample->next_row_out, output_buf + *out_row_ctr,
                                      (int)num_rows);

    *out_row_ctr += num_rows;
    upsample->rows_to_go -= num_rows;
    upsample->next_row_out += num_rows;

    if (upsample->next_row_out >= cinfo->max_v_samp_factor)
        (*in_row_group_ctr)++;
}
