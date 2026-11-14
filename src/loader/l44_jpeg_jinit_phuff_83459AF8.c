/* Loader_DLL.xex 0x83459AF8-0x83459BCC, 0x8345A060-0x8345A0F8, executable version 0.0.0.3. */
/* Library routines: libjpeg jdphuff.c jinit_phuff_decoder,
   jdpostct.c post_process_1pass. */
#include "l44_jpeg.h"

extern void ts4l_jpeg_start_pass_phuff_decoder_83459810(struct ts4l_jpeg_decomp *cinfo);

struct ts4l_phuff_ent {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);
    void *decode_mcu;
    int insufficient_data;
    int bitstate[2];
    unsigned int saved[5];
    unsigned int restarts_to_go;
    void *derived_tbls[4];
    void *ac_derived_tbl;
};

struct ts4l_my_post {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo, int pass_mode);
    void *post_process_data;
    void *whole_image;
    ts4l_jsamparray buffer;
    unsigned int strip_height;
};

void ts4l_jpeg_jinit_phuff_decoder_83459AF8(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_phuff_ent *entropy;
    int *coef_bit_ptr;
    int ci, i;

    entropy = (struct ts4l_phuff_ent *)(*cinfo->mem->alloc_small)(cinfo, 1, 0x40);
    cinfo->entropy = (void *)entropy;
    entropy->start_pass = ts4l_jpeg_start_pass_phuff_decoder_83459810;

    for (i = 0; i < 4; i++)
        entropy->derived_tbls[i] = 0;

    cinfo->coef_bits = (int (*)[64])(*cinfo->mem->alloc_small)(cinfo, 1, cinfo->num_components * 64 * 4);
    coef_bit_ptr = &cinfo->coef_bits[0][0];
    for (ci = 0; ci < cinfo->num_components; ci++)
        for (i = 0; i < 64; i++)
            *coef_bit_ptr++ = -1;
}

void ts4l_jpeg_post_process_1pass_8345A060(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                           unsigned int *in_row_group_ctr,
                                           unsigned int in_row_groups_avail, ts4l_jsamparray output_buf,
                                           unsigned int *out_row_ctr, unsigned int out_rows_avail)
{
    struct ts4l_my_post *post = (struct ts4l_my_post *)cinfo->post;
    unsigned int num_rows, max_rows;

    max_rows = out_rows_avail - *out_row_ctr;
    if (max_rows > post->strip_height)
        max_rows = post->strip_height;
    num_rows = 0;
    (*cinfo->upsample->upsample)(cinfo, input_buf, in_row_group_ctr, in_row_groups_avail, post->buffer,
                                 &num_rows, max_rows);

    (*cinfo->cquantize->color_quantize)(cinfo, post->buffer, output_buf + *out_row_ctr, (int)num_rows);
    *out_row_ctr += num_rows;
}
