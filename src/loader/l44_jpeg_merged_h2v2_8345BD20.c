/* Loader_DLL.xex 0x8345BD20-0x8345BEF8, 0x8345BF00-0x8345BFE0, executable version 0.0.0.3. */
/* Library routines: libjpeg jdmerge.c (h2v2_merged_upsample, jinit_merged_upsampler). */
#include "l44_jpeg.h"

struct ts4l_merged_up {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);   /* 0x00 */
    void *upsample;                                       /* 0x04 */
    int need_context_rows;                                /* 0x08 */
    void *upmethod;                                       /* 0x0c */
    int *Cr_r_tab;                                        /* 0x10 */
    int *Cb_b_tab;                                        /* 0x14 */
    long *Cr_g_tab;                                       /* 0x18 */
    long *Cb_g_tab;                                       /* 0x1c */
    unsigned char *spare_row;                             /* 0x20 */
    int spare_full;                                       /* 0x24 */
    unsigned int out_row_width;                           /* 0x28 */
    unsigned int rows_to_go;                              /* 0x2c */
};

extern void ts4_get_u32_off1c8_8345BA48(struct ts4l_jpeg_decomp *cinfo);
extern void fn_8345BA60(void);
extern void ts4l_jpeg_merged_1v_upsample_8345BB68(void);
extern void fn_8345BBD8(void);
extern void ts4_tailcall_fn_8345BD20_8345BEF8(void);
extern void fn_8345B928(struct ts4l_jpeg_decomp *cinfo);

void ts4l_jpeg_h2v2_merged_upsample_8345BD20(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                             unsigned int in_row_group_ctr, ts4l_jsamparray output_buf)
{
    struct ts4l_merged_up *upsample = (struct ts4l_merged_up *)cinfo->upsample;
    int y, cred, cgreen, cblue;
    int cb, cr;
    unsigned char *outptr0, *outptr1;
    unsigned char *inptr00, *inptr01, *inptr1, *inptr2;
    unsigned int col;
    unsigned char *range_limit = cinfo->sample_range_limit;
    int *Crrtab = upsample->Cr_r_tab;
    int *Cbbtab = upsample->Cb_b_tab;
    long *Crgtab = upsample->Cr_g_tab;
    long *Cbgtab = upsample->Cb_g_tab;

    inptr00 = input_buf[0][in_row_group_ctr * 2];
    inptr01 = input_buf[0][in_row_group_ctr * 2 + 1];
    inptr1 = input_buf[1][in_row_group_ctr];
    inptr2 = input_buf[2][in_row_group_ctr];
    outptr0 = output_buf[0];
    outptr1 = output_buf[1];
    for (col = cinfo->output_width >> 1; col > 0; col--) {
        cb = *inptr1++;
        cr = *inptr2++;
        cred = Crrtab[cr];
        cgreen = (int)((Cbgtab[cb] + Crgtab[cr]) >> 16);
        cblue = Cbbtab[cb];
        y = *inptr00++;
        outptr0[0] = range_limit[y + cred];
        outptr0[1] = range_limit[y + cgreen];
        outptr0[2] = range_limit[y + cblue];
        outptr0 += 3;
        y = *inptr00++;
        outptr0[0] = range_limit[y + cred];
        outptr0[1] = range_limit[y + cgreen];
        outptr0[2] = range_limit[y + cblue];
        outptr0 += 3;
        y = *inptr01++;
        outptr1[0] = range_limit[y + cred];
        outptr1[1] = range_limit[y + cgreen];
        outptr1[2] = range_limit[y + cblue];
        outptr1 += 3;
        y = *inptr01++;
        outptr1[0] = range_limit[y + cred];
        outptr1[1] = range_limit[y + cgreen];
        outptr1[2] = range_limit[y + cblue];
        outptr1 += 3;
    }
    if (cinfo->output_width & 1) {
        cb = *inptr1;
        cr = *inptr2;
        cred = Crrtab[cr];
        cgreen = (int)((Cbgtab[cb] + Crgtab[cr]) >> 16);
        cblue = Cbbtab[cb];
        y = *inptr00;
        outptr0[0] = range_limit[y + cred];
        outptr0[1] = range_limit[y + cgreen];
        outptr0[2] = range_limit[y + cblue];
        y = *inptr01;
        outptr1[0] = range_limit[y + cred];
        outptr1[1] = range_limit[y + cgreen];
        outptr1[2] = range_limit[y + cblue];
    }
}

void ts4l_jpeg_jinit_merged_upsampler_8345BF00(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_merged_up *upsample;

    upsample = (struct ts4l_merged_up *)(*cinfo->mem->alloc_small)(cinfo, 1, 0x30);
    cinfo->upsample = (struct ts4l_jpeg_upsampler *)upsample;
    upsample->start_pass = ts4_get_u32_off1c8_8345BA48;
    upsample->need_context_rows = 0;

    upsample->out_row_width = cinfo->output_width * cinfo->out_color_components;

    if (cinfo->max_v_samp_factor == 2) {
        upsample->upsample = (void *)fn_8345BA60;
        upsample->upmethod = (void *)ts4_tailcall_fn_8345BD20_8345BEF8;
        upsample->spare_row = (unsigned char *)(*cinfo->mem->alloc_large)(cinfo, 1, upsample->out_row_width);
    } else {
        upsample->upsample = (void *)ts4l_jpeg_merged_1v_upsample_8345BB68;
        upsample->upmethod = (void *)fn_8345BBD8;
        upsample->spare_row = 0;
    }

    fn_8345B928(cinfo);
}
