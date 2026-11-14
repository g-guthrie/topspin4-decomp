/* Loader_DLL.xex 0x8345BA60-0x8345BB68, 0x8345BBD8-0x8345BD20, executable version 0.0.0.3. */
/* Library routines: libjpeg jdmerge.c (merged_2v_upsample, h2v1_merged_upsample). */
#include "l44_jpeg.h"

struct ts4l_merged_up {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);   /* 0x00 */
    void *upsample;                                       /* 0x04 */
    int need_context_rows;                                /* 0x08 */
    void (*upmethod)(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                     unsigned int in_row_group_ctr, ts4l_jsamparray output_buf);  /* 0x0c */
    int *Cr_r_tab;                                        /* 0x10 */
    int *Cb_b_tab;                                        /* 0x14 */
    long *Cr_g_tab;                                       /* 0x18 */
    long *Cb_g_tab;                                       /* 0x1c */
    unsigned char *spare_row;                             /* 0x20 */
    int spare_full;                                       /* 0x24 */
    unsigned int out_row_width;                           /* 0x28 */
    unsigned int rows_to_go;                              /* 0x2c */
};

extern void ts4l_jpeg_jcopy_sample_rows_8344EF30(ts4l_jsamparray input_array, int source_row, ts4l_jsamparray output_array,
                        int dest_row, int num_rows, unsigned int num_cols);

void ts4l_jpeg_merged_2v_upsample_8345BA60(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                           unsigned int *in_row_group_ctr,
                                           unsigned int in_row_groups_avail, ts4l_jsamparray output_buf,
                                           unsigned int *out_row_ctr, unsigned int out_rows_avail)
{
    struct ts4l_merged_up *upsample = (struct ts4l_merged_up *)cinfo->upsample;
    unsigned char *work_ptrs[2];
    unsigned int num_rows;

    (void)in_row_groups_avail;
    if (upsample->spare_full) {
        ts4l_jpeg_jcopy_sample_rows_8344EF30(&upsample->spare_row, 0, output_buf + *out_row_ctr, 0, 1, upsample->out_row_width);
        num_rows = 1;
        upsample->spare_full = 0;
    } else {
        num_rows = 2;
        if (num_rows > upsample->rows_to_go)
            num_rows = upsample->rows_to_go;
        out_rows_avail -= *out_row_ctr;
        if (num_rows > out_rows_avail)
            num_rows = out_rows_avail;
        work_ptrs[0] = output_buf[*out_row_ctr];
        if (num_rows > 1) {
            work_ptrs[1] = output_buf[*out_row_ctr + 1];
        } else {
            work_ptrs[1] = upsample->spare_row;
            upsample->spare_full = 1;
        }
        (*upsample->upmethod)(cinfo, input_buf, *in_row_group_ctr, work_ptrs);
    }

    *out_row_ctr += num_rows;
    upsample->rows_to_go -= num_rows;
    if (!upsample->spare_full)
        (*in_row_group_ctr)++;
}

void ts4l_jpeg_h2v1_merged_upsample_8345BBD8(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                             unsigned int in_row_group_ctr, ts4l_jsamparray output_buf)
{
    struct ts4l_merged_up *upsample = (struct ts4l_merged_up *)cinfo->upsample;
    int y, cred, cgreen, cblue;
    int cb, cr;
    unsigned char *outptr;
    unsigned char *inptr0, *inptr1, *inptr2;
    unsigned int col;
    unsigned char *range_limit = cinfo->sample_range_limit;
    int *Crrtab = upsample->Cr_r_tab;
    int *Cbbtab = upsample->Cb_b_tab;
    long *Crgtab = upsample->Cr_g_tab;
    long *Cbgtab = upsample->Cb_g_tab;

    inptr0 = input_buf[0][in_row_group_ctr];
    inptr1 = input_buf[1][in_row_group_ctr];
    inptr2 = input_buf[2][in_row_group_ctr];
    outptr = output_buf[0];
    for (col = cinfo->output_width >> 1; col > 0; col--) {
        cb = *inptr1++;
        cr = *inptr2++;
        cred = Crrtab[cr];
        cgreen = (int)((Cbgtab[cb] + Crgtab[cr]) >> 16);
        cblue = Cbbtab[cb];
        y = *inptr0++;
        outptr[0] = range_limit[y + cred];
        outptr[1] = range_limit[y + cgreen];
        outptr[2] = range_limit[y + cblue];
        outptr += 3;
        y = *inptr0++;
        outptr[0] = range_limit[y + cred];
        outptr[1] = range_limit[y + cgreen];
        outptr[2] = range_limit[y + cblue];
        outptr += 3;
    }
    if (cinfo->output_width & 1) {
        cb = *inptr1;
        cr = *inptr2;
        cred = Crrtab[cr];
        cgreen = (int)((Cbgtab[cb] + Crgtab[cr]) >> 16);
        cblue = Cbbtab[cb];
        y = *inptr0;
        outptr[0] = range_limit[y + cred];
        outptr[1] = range_limit[y + cgreen];
        outptr[2] = range_limit[y + cblue];
    }
}
