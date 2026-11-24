/* Loader_DLL.xex 0x83457DA0-0x83457FD0, executable version 0.0.0.3. */
/* Library routines: libjpeg jdcoefct.c (start_output_pass, jinit_d_coef_controller). */
#include "l44_jpeg.h"

typedef struct ts4l_my_coef {
    struct ts4l_jpeg_d_coef pub;           /* 0x00 */
    unsigned int MCU_ctr;                  /* 0x14 */
    int MCU_vert_offset;                   /* 0x18 */
    int MCU_rows_per_iMCU_row;             /* 0x1c */
    ts4l_jblock *MCU_buffer[10];           /* 0x20 */
    void *whole_image[10];                 /* 0x48 */
    int *coef_bits_latch;                  /* 0x70 */
} ts4l_my_coef;

extern int fn_83457458(struct ts4l_jpeg_decomp *cinfo);
extern int ts4l_jpeg_decompress_smooth_data_834575F8(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage output_buf);
extern int fn_834572A0(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage output_buf);
extern void ts4_set_u32_off98_83456D88(struct ts4l_jpeg_decomp *cinfo);
extern int ts4_fn_83457038(struct ts4l_jpeg_decomp *cinfo);
extern int ts4l_jpeg_decompress_onepass_83456D98(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage output_buf);
extern int ts4l_jpeg_consume_data_83457040(struct ts4l_jpeg_decomp *cinfo);
extern long ts4l_jpeg_jround_up_8344EF00(long a, long b);

void ts4l_jpeg_start_output_pass_83457DA0(struct ts4l_jpeg_decomp *cinfo)
{
    ts4l_my_coef *coef = (ts4l_my_coef *)cinfo->coef;

    if (coef->pub.coef_arrays != 0) {
        if (cinfo->do_block_smoothing && fn_83457458(cinfo))
            coef->pub.decompress_data = ts4l_jpeg_decompress_smooth_data_834575F8;
        else
            coef->pub.decompress_data = fn_834572A0;
    }
    cinfo->output_iMCU_row = 0;
}

void ts4l_jpeg_jinit_d_coef_controller_83457E30(struct ts4l_jpeg_decomp *cinfo, int need_full_buffer)
{
    ts4l_my_coef *coef;

    coef = (ts4l_my_coef *)(*cinfo->mem->alloc_small)(cinfo, 1, 0x74);
    cinfo->coef = &coef->pub;
    coef->pub.start_input_pass = ts4_set_u32_off98_83456D88;
    coef->pub.start_output_pass = ts4l_jpeg_start_output_pass_83457DA0;
    coef->coef_bits_latch = 0;

    if (need_full_buffer) {
        int ci, access_rows;
        struct ts4l_jpeg_component_info *compptr;

        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            access_rows = compptr->v_samp_factor;
            if (cinfo->progressive_mode)
                access_rows *= 3;
            coef->whole_image[ci] = (*cinfo->mem->request_virt_barray)(
                cinfo, 1, 1,
                (unsigned int)ts4l_jpeg_jround_up_8344EF00((long)compptr->width_in_blocks, (long)compptr->h_samp_factor),
                (unsigned int)ts4l_jpeg_jround_up_8344EF00((long)compptr->height_in_blocks, (long)compptr->v_samp_factor),
                (unsigned int)access_rows);
        }
        coef->pub.consume_data = ts4l_jpeg_consume_data_83457040;
        coef->pub.decompress_data = fn_834572A0;
        coef->pub.coef_arrays = (struct ts4l_jpeg_virt_barray **)coef->whole_image;
    } else {
        ts4l_jblock *buffer;
        int i;

        buffer = (ts4l_jblock *)(*cinfo->mem->alloc_large)(cinfo, 1, 10 * 128);
        for (i = 0; i < 10; i++)
            coef->MCU_buffer[i] = buffer + i;
        coef->pub.consume_data = ts4_fn_83457038;
        coef->pub.decompress_data = ts4l_jpeg_decompress_onepass_83456D98;
        coef->pub.coef_arrays = 0;
    }
}
