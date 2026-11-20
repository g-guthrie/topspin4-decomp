/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression postprocessing controller, IJG jdpostct.c style. (JP1) */
#include "jp1_jpeg.h"

enum { JP1_JERR_BAD_BUFFER_MODE = 0x04 };

struct ts4_jpeg_my_post {
    struct ts4_jpeg_d_post pub;           /* 0x00 */
    struct ts4_jpeg_virt_sarray *whole_image; /* 0x08 */
    ts4_jsamparray buffer;                /* 0x0c */
    ts4_jdim strip_height;                /* 0x10 */
    ts4_jdim starting_row;                /* 0x14 */
    ts4_jdim next_row;                    /* 0x18 */
};

void ts4_if_get_u32_off1b4_882F8FA0(struct ts4_jpeg_decomp *cinfo, int pass_mode); /* start_pass_dpost */

/* Upsamples a strip into the post buffer and color-quantizes it into the output rows
 * (Swing_DLL.xex 0x882F8F08). */
void ts4_jpeg_post_process_1pass_882F8F08(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                          ts4_jdim *in_row_group_ctr, ts4_jdim in_row_groups_avail,
                                          ts4_jsamparray output_buf, ts4_jdim *out_row_ctr,
                                          ts4_jdim out_rows_avail)
{
    struct ts4_jpeg_my_post *post = (struct ts4_jpeg_my_post *)cinfo->post;
    ts4_jdim num_rows, max_rows;

    max_rows = out_rows_avail - *out_row_ctr;
    if (max_rows > post->strip_height)
        max_rows = post->strip_height;
    num_rows = 0;
    (*cinfo->upsample->upsample)(cinfo, input_buf, in_row_group_ctr, in_row_groups_avail,
                                 post->buffer, &num_rows, max_rows);
    (*cinfo->cquantize->color_quantize)(cinfo, post->buffer, output_buf + *out_row_ctr,
                                        (int)num_rows);
    *out_row_ctr += num_rows;
}

/* Creates the postprocessing controller and, when quantizing, its strip buffer
 * (Swing_DLL.xex 0x882F9058). */
void ts4_jpeg_jinit_d_post_controller_882F9058(struct ts4_jpeg_decomp *cinfo, int need_full_buffer)
{
    struct ts4_jpeg_my_post *post;

    post = (struct ts4_jpeg_my_post *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*post));
    cinfo->post = &post->pub;
    post->pub.start_pass = ts4_if_get_u32_off1b4_882F8FA0;
    post->whole_image = 0;
    post->buffer = 0;
    if (cinfo->quantize_colors) {
        post->strip_height = (ts4_jdim)cinfo->max_v_samp_factor;
        if (need_full_buffer) {
            JP1_ERREXIT(cinfo, JP1_JERR_BAD_BUFFER_MODE);
        } else {
            post->buffer = (*cinfo->mem->alloc_sarray)(
                cinfo, 1, cinfo->output_width * cinfo->out_color_components, post->strip_height);
        }
    }
}
