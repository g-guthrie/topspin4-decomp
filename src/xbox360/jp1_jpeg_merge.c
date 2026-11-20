/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression merged upsampling and color conversion, IJG jdmerge.c style. (JP1) */
#include "jp1_jpeg.h"

struct ts4_jpeg_my_merged_upsampler;
typedef void (*ts4_jpeg_merged_upmethod)(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                         ts4_jdim in_row_group_ctr, ts4_jsamparray output_buf);

/* Merged upsampler private state (jdmerge.c my_upsampler). */
struct ts4_jpeg_my_merged_upsampler {
    struct ts4_jpeg_upsampler pub;       /* 0x00 */
    ts4_jpeg_merged_upmethod upmethod;   /* 0x0c */
    int *Cr_r_tab;                       /* 0x10 */
    int *Cb_b_tab;                       /* 0x14 */
    long *Cr_g_tab;                      /* 0x18 */
    long *Cb_g_tab;                      /* 0x1c */
    ts4_jsamprow spare_row;              /* 0x20 */
    int spare_full;                      /* 0x24 */
    ts4_jdim out_row_width;              /* 0x28 */
    ts4_jdim rows_to_go;                 /* 0x2c */
};

#define JP1_SCALEBITS 16
#define JP1_ONE_HALF ((long)1 << (JP1_SCALEBITS - 1))
#define JP1_FIX_1_40200 91881L
#define JP1_FIX_1_77200 116130L
#define JP1_FIX_0_71414 46802L
#define JP1_FIX_0_34414 22554L

/* Copies rows of samples (jutils.c jcopy_sample_rows). */
void ts4_jpeg_jcopy_sample_rows_882EE8A0(ts4_jsamparray input_array, int source_row, ts4_jsamparray output_array,
                 int dest_row, int num_rows, ts4_jdim num_cols);
/* start_pass_merged_upsample. */
void ts4_get_u32_off1c8_882FA8E8(struct ts4_jpeg_decomp *cinfo);
/* Linker thunk that forwards to h2v2_merged_upsample. */
void ts4_forward_882FAD98(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                          ts4_jdim in_row_group_ctr, ts4_jsamparray output_buf);

void ts4_jpeg_h2v1_merged_upsample_882FAA78(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                            ts4_jdim in_row_group_ctr, ts4_jsamparray output_buf);

/* Builds the YCbCr to RGB lookup tables of the merged upsampler (Swing_DLL.xex 0x882FA7C8). */
void ts4_jpeg_build_ycc_rgb_table_882FA7C8(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_merged_upsampler *upsample = (struct ts4_jpeg_my_merged_upsampler *)cinfo->upsample;
    int i;
    long x;

    upsample->Cr_r_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    upsample->Cb_b_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    upsample->Cr_g_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(long));
    upsample->Cb_g_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(long));
    for (i = 0, x = -128; i <= 255; i++, x++) {
        upsample->Cr_r_tab[i] = (int)((JP1_FIX_1_40200 * x + JP1_ONE_HALF) >> JP1_SCALEBITS);
        upsample->Cb_b_tab[i] = (int)((JP1_FIX_1_77200 * x + JP1_ONE_HALF) >> JP1_SCALEBITS);
        upsample->Cr_g_tab[i] = (-JP1_FIX_0_71414) * x;
        upsample->Cb_g_tab[i] = (-JP1_FIX_0_34414) * x + JP1_ONE_HALF;
    }
}

/* Upsample and convert two rows at a time (Swing_DLL.xex 0x882FA900). */
void ts4_jpeg_merged_2v_upsample_882FA900(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                          ts4_jdim *in_row_group_ctr, ts4_jdim in_row_groups_avail,
                                          ts4_jsamparray output_buf, ts4_jdim *out_row_ctr,
                                          ts4_jdim out_rows_avail)
{
    struct ts4_jpeg_my_merged_upsampler *upsample = (struct ts4_jpeg_my_merged_upsampler *)cinfo->upsample;
    ts4_jsamprow work_ptrs[2];
    ts4_jdim num_rows;

    (void)in_row_groups_avail;
    if (upsample->spare_full) {
        ts4_jpeg_jcopy_sample_rows_882EE8A0(&upsample->spare_row, 0, output_buf + *out_row_ctr, 0, 1, upsample->out_row_width);
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

/* Upsample and convert one row at a time (Swing_DLL.xex 0x882FAA08). */
void ts4_jpeg_merged_1v_upsample_882FAA08(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                          ts4_jdim *in_row_group_ctr, ts4_jdim in_row_groups_avail,
                                          ts4_jsamparray output_buf, ts4_jdim *out_row_ctr,
                                          ts4_jdim out_rows_avail)
{
    struct ts4_jpeg_my_merged_upsampler *upsample = (struct ts4_jpeg_my_merged_upsampler *)cinfo->upsample;

    (void)in_row_groups_avail;
    (void)out_rows_avail;
    (*upsample->upmethod)(cinfo, input_buf, *in_row_group_ctr, output_buf + *out_row_ctr);
    (*out_row_ctr)++;
    (*in_row_group_ctr)++;
}

/* Merged 2h1v upsampling and YCbCr to RGB conversion of one row (Swing_DLL.xex 0x882FAA78). */
void ts4_jpeg_h2v1_merged_upsample_882FAA78(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                            ts4_jdim in_row_group_ctr, ts4_jsamparray output_buf)
{
    struct ts4_jpeg_my_merged_upsampler *upsample = (struct ts4_jpeg_my_merged_upsampler *)cinfo->upsample;
    int y, cred, cgreen, cblue;
    int cb, cr;
    ts4_jsamprow outptr;
    ts4_jsamprow inptr0, inptr1, inptr2;
    ts4_jdim col;
    ts4_jsample *range_limit = cinfo->sample_range_limit;
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
        cgreen = (int)((Cbgtab[cb] + Crgtab[cr]) >> JP1_SCALEBITS);
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
        cgreen = (int)((Cbgtab[cb] + Crgtab[cr]) >> JP1_SCALEBITS);
        cblue = Cbbtab[cb];
        y = *inptr0;
        outptr[0] = range_limit[y + cred];
        outptr[1] = range_limit[y + cgreen];
        outptr[2] = range_limit[y + cblue];
    }
}

/* Merged 2h2v upsampling and YCbCr to RGB conversion of two rows (Swing_DLL.xex 0x882FABC0). */
void ts4_jpeg_h2v2_merged_upsample_882FABC0(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                            ts4_jdim in_row_group_ctr, ts4_jsamparray output_buf)
{
    struct ts4_jpeg_my_merged_upsampler *upsample = (struct ts4_jpeg_my_merged_upsampler *)cinfo->upsample;
    int y, cred, cgreen, cblue;
    int cb, cr;
    ts4_jsamprow outptr0, outptr1;
    ts4_jsamprow inptr00, inptr01, inptr1, inptr2;
    ts4_jdim col;
    ts4_jsample *range_limit = cinfo->sample_range_limit;
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
        cgreen = (int)((Cbgtab[cb] + Crgtab[cr]) >> JP1_SCALEBITS);
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
        cgreen = (int)((Cbgtab[cb] + Crgtab[cr]) >> JP1_SCALEBITS);
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

/* Creates the merged upsampler for 2h1v or 2h2v YCbCr images (Swing_DLL.xex 0x882FADA0). */
void ts4_jpeg_jinit_merged_upsampler_882FADA0(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_merged_upsampler *upsample;

    upsample = (struct ts4_jpeg_my_merged_upsampler *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*upsample));
    cinfo->upsample = &upsample->pub;
    upsample->pub.start_pass = ts4_get_u32_off1c8_882FA8E8;
    upsample->pub.need_context_rows = 0;
    upsample->out_row_width = cinfo->output_width * cinfo->out_color_components;
    if (cinfo->max_v_samp_factor == 2) {
        upsample->pub.upsample = ts4_jpeg_merged_2v_upsample_882FA900;
        upsample->upmethod = ts4_forward_882FAD98;
        upsample->spare_row = (ts4_jsamprow)(*cinfo->mem->alloc_large)(
            cinfo, 1, (unsigned int)(upsample->out_row_width * sizeof(ts4_jsample)));
    } else {
        upsample->pub.upsample = ts4_jpeg_merged_1v_upsample_882FAA08;
        upsample->upmethod = ts4_jpeg_h2v1_merged_upsample_882FAA78;
        upsample->spare_row = 0;
    }
    ts4_jpeg_build_ycc_rgb_table_882FA7C8(cinfo);
}
