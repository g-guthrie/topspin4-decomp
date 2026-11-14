/* Loader_DLL.xex 0x8345AB00-0x8345B928, executable version 0.0.0.3.
 * Statically linked libjpeg 6b routines (jdcolor.c). */

#include "l21_jp1_jpeg_8344E498.h"


/* Color deconverter private state (jdcolor.c my_cconvert). */
struct ts4l_jpeg_my_cconvert {
    struct ts4l_jpeg_cconvert pub; /* 0x00 */
    int *Cr_r_tab;                /* 0x08 */
    int *Cb_b_tab;                /* 0x0c */
    long *Cr_g_tab;               /* 0x10 */
    long *Cb_g_tab;               /* 0x14 */
    unsigned int *ink_tab[10];    /* 0x18: CMYK-to-RGB attenuation tables (this build's extension) */
};

/* Fixed-point YCbCr conversion constants, 16 fractional bits (jdcolor.c FIX()). */
#define TS4L_SCALEBITS 16
#define TS4L_ONE_HALF ((long)1 << (TS4L_SCALEBITS - 1))
#define TS4L_FIX_1_40200 91881L
#define TS4L_FIX_1_77200 116130L
#define TS4L_FIX_0_71414 46802L
#define TS4L_FIX_0_34414 22554L

/* Builds the YCbCr to RGB lookup tables */
void ts4l_jpeg_build_ycc_rgb_table_8345AB00(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_my_cconvert *cconvert = (struct ts4l_jpeg_my_cconvert *)cinfo->cconvert;
    int i;
    long x;

    cconvert->Cr_r_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->Cb_b_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->Cr_g_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(long));
    cconvert->Cb_g_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(long));
    for (i = 0, x = -128; i <= 255; i++, x++) {
        cconvert->Cr_r_tab[i] = (int)((TS4L_FIX_1_40200 * x + TS4L_ONE_HALF) >> TS4L_SCALEBITS);
        cconvert->Cb_b_tab[i] = (int)((TS4L_FIX_1_77200 * x + TS4L_ONE_HALF) >> TS4L_SCALEBITS);
        cconvert->Cr_g_tab[i] = (-TS4L_FIX_0_71414) * x;
        cconvert->Cb_g_tab[i] = (-TS4L_FIX_0_34414) * x + TS4L_ONE_HALF;
    }
}

/* Converts YCbCr rows to RGB */
void ts4l_jpeg_ycc_rgb_convert_8345AC20(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                       ts4l_jdim input_row, ts4l_jsamparray output_buf, int num_rows)
{
    struct ts4l_jpeg_my_cconvert *cconvert = (struct ts4l_jpeg_my_cconvert *)cinfo->cconvert;
    int y, cb, cr;
    ts4l_jsamprow outptr;
    ts4l_jsamprow inptr0, inptr1, inptr2;
    ts4l_jdim col;
    ts4l_jdim num_cols = cinfo->output_width;
    ts4l_jsample *range_limit = cinfo->sample_range_limit;
    int *Crrtab = cconvert->Cr_r_tab;
    int *Cbbtab = cconvert->Cb_b_tab;
    long *Crgtab = cconvert->Cr_g_tab;
    long *Cbgtab = cconvert->Cb_g_tab;

    while (--num_rows >= 0) {
        inptr0 = input_buf[0][input_row];
        inptr1 = input_buf[1][input_row];
        inptr2 = input_buf[2][input_row];
        input_row++;
        outptr = *output_buf++;
        for (col = 0; col < num_cols; col++) {
            y = inptr0[col];
            cb = inptr1[col];
            cr = inptr2[col];
            outptr[0] = range_limit[y + Crrtab[cr]];
            outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> TS4L_SCALEBITS))];
            outptr[2] = range_limit[y + Cbbtab[cb]];
            outptr += 3;
        }
    }
}

/* Copies each component plane into interleaved output without conversion
 * */
void ts4l_jpeg_null_convert_8345ACF0(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                    ts4l_jdim input_row, ts4l_jsamparray output_buf, int num_rows)
{
    ts4l_jsamprow inptr, outptr;
    ts4l_jdim count;
    int num_components = cinfo->num_components;
    ts4l_jdim num_cols = cinfo->output_width;
    int ci;

    while (--num_rows >= 0) {
        for (ci = 0; ci < num_components; ci++) {
            inptr = input_buf[ci][input_row];
            outptr = output_buf[0] + ci;
            for (count = num_cols; count > 0; count--) {
                *outptr = *inptr++;
                outptr += num_components;
            }
        }
        input_row++;
        output_buf++;
    }
}

/* Expands one grayscale plane into RGB triples */
void ts4l_jpeg_gray_rgb_convert_8345AD98(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                        ts4l_jdim input_row, ts4l_jsamparray output_buf,
                                        int num_rows)
{
    ts4l_jsamprow inptr, outptr;
    ts4l_jdim col;
    ts4l_jdim num_cols = cinfo->output_width;

    while (--num_rows >= 0) {
        inptr = input_buf[0][input_row++];
        outptr = *output_buf++;
        for (col = 0; col < num_cols; col++) {
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3;
        }
    }
}

/* Converts YCCK rows to CMYK */
void ts4l_jpeg_ycck_cmyk_convert_8345AE00(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                         ts4l_jdim input_row, ts4l_jsamparray output_buf,
                                         int num_rows)
{
    struct ts4l_jpeg_my_cconvert *cconvert = (struct ts4l_jpeg_my_cconvert *)cinfo->cconvert;
    int y, cb, cr;
    ts4l_jsamprow outptr;
    ts4l_jsamprow inptr0, inptr1, inptr2, inptr3;
    ts4l_jdim col;
    ts4l_jdim num_cols = cinfo->output_width;
    ts4l_jsample *range_limit = cinfo->sample_range_limit;
    int *Crrtab = cconvert->Cr_r_tab;
    int *Cbbtab = cconvert->Cb_b_tab;
    long *Crgtab = cconvert->Cr_g_tab;
    long *Cbgtab = cconvert->Cb_g_tab;

    while (--num_rows >= 0) {
        inptr0 = input_buf[0][input_row];
        inptr1 = input_buf[1][input_row];
        inptr2 = input_buf[2][input_row];
        inptr3 = input_buf[3][input_row];
        input_row++;
        outptr = *output_buf++;
        for (col = 0; col < num_cols; col++) {
            y = inptr0[col];
            cb = inptr1[col];
            cr = inptr2[col];
            outptr[0] = range_limit[255 - (y + Crrtab[cr])];
            outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> TS4L_SCALEBITS)))];
            outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
            outptr[3] = inptr3[col];
            outptr += 4;
        }
    }
}

enum { TS4L_JERR_BAD_J_COLORSPACE = 0x0a, TS4L_JERR_CONVERSION_NOTIMPL = 0x1b };

void ts4l_jpeg_build_ink_tables_8345AEF0(struct ts4l_jpeg_decomp *cinfo);
/* start_pass_dcolor: nothing to do. */
void fn_8345B4A8(struct ts4l_jpeg_decomp *cinfo);
/* grayscale_convert: copies the first component plane. */
void ts4_get_u32_off70_8345AD78(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                ts4l_jdim input_row, ts4l_jsamparray output_buf, int num_rows);

/* One CMYK ink attenuation curve: a descending line for the first 192 entries, then a
 * rounded linear ramp. */
#define TS4L_INK_CURVE(i, slope_lo, c_hi, s_hi) \
    ((i) < 192 ? 65153 - (slope_lo) * (i) : (c_hi) - (((i) - 192) * (s_hi) + 31) / 63)

/* Builds the ten 256-entry ink attenuation tables for the CMYK-to-RGB converters
 * */
void ts4l_jpeg_build_ink_tables_8345AEF0(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_my_cconvert *cconvert = (struct ts4l_jpeg_my_cconvert *)cinfo->cconvert;
    int i;

    cconvert->ink_tab[0] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[1] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[2] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[3] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[4] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[5] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[6] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[7] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[8] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->ink_tab[9] = (unsigned int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    for (i = 0; i < 256; i++) {
        cconvert->ink_tab[0][i] = TS4L_INK_CURVE(i, 223, 22464, 22464);
        cconvert->ink_tab[1][i] = TS4L_INK_CURVE(i, 206, 25728, 25728);
        cconvert->ink_tab[1][i] = (cconvert->ink_tab[1][i] * 0x10101u) >> 16;
        cconvert->ink_tab[2][i] = TS4L_INK_CURVE(i, 94, 47232, 8217);
        cconvert->ink_tab[2][i] = (cconvert->ink_tab[2][i] * 0x10101u) >> 16;
        cconvert->ink_tab[3][i] = TS4L_INK_CURVE(i, 0, 65280, 3060);
        cconvert->ink_tab[3][i] = (cconvert->ink_tab[3][i] * 0x10101u) >> 16;
        cconvert->ink_tab[4][i] = TS4L_INK_CURVE(i, 24, 60672, 7632);
        cconvert->ink_tab[4][i] = (cconvert->ink_tab[4][i] * 0x10101u) >> 16;
        cconvert->ink_tab[5][i] = TS4L_INK_CURVE(i, 186, 29568, 29568);
        cconvert->ink_tab[5][i] = (cconvert->ink_tab[5][i] * 0x10101u) >> 16;
        cconvert->ink_tab[6][i] = TS4L_INK_CURVE(i, 132, 39936, 11376);
        cconvert->ink_tab[6][i] = (cconvert->ink_tab[6][i] * 0x10101u) >> 16;
        cconvert->ink_tab[7][i] = i < 192 ? 65153 : 65280;
        cconvert->ink_tab[7][i] = (cconvert->ink_tab[7][i] * 0x10101u) >> 16;
        cconvert->ink_tab[8][i] = TS4L_INK_CURVE(i, 7, 63936, 1461);
        cconvert->ink_tab[8][i] = (cconvert->ink_tab[8][i] * 0x10101u) >> 16;
        cconvert->ink_tab[9][i] = TS4L_INK_CURVE(i, 171, 32448, 25308);
        cconvert->ink_tab[9][i] = (cconvert->ink_tab[9][i] * 0x10101u) >> 16;
    }
}

/* One output channel of the CMYK ink model: three table lookups multiplied together with
 * 16-bit scaling, then reduced to 8 bits. */
#define TS4L_INK3(t1, i1, t2, i2, t3, i3, tk, ik) \
    ((((((t1)[i1] * (tk)[ik]) >> 16) * (t2)[i2]) >> 16) * (t3)[i3] >> 24)

/* Converts inverted CMYK rows to RGB through the ink attenuation tables
 * */
void ts4l_jpeg_cmyk_rgb_convert_8345B340(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                        ts4l_jdim input_row, ts4l_jsamparray output_buf,
                                        int num_rows)
{
    struct ts4l_jpeg_my_cconvert *cconvert = (struct ts4l_jpeg_my_cconvert *)cinfo->cconvert;
    ts4l_jsamprow outptr, inptr0, inptr1, inptr2, inptr3;
    ts4l_jdim col;
    ts4l_jdim num_cols = cinfo->output_width;
    unsigned int *t0 = cconvert->ink_tab[0], *t1 = cconvert->ink_tab[1], *t2 = cconvert->ink_tab[2];
    unsigned int *t3 = cconvert->ink_tab[3], *t4 = cconvert->ink_tab[4], *t5 = cconvert->ink_tab[5];
    unsigned int *t6 = cconvert->ink_tab[6], *t7 = cconvert->ink_tab[7], *t8 = cconvert->ink_tab[8];
    unsigned int *t9 = cconvert->ink_tab[9];
    unsigned int a, b, c, d;

    while (--num_rows >= 0) {
        inptr0 = input_buf[0][input_row];
        inptr1 = input_buf[1][input_row];
        inptr2 = input_buf[2][input_row];
        inptr3 = input_buf[3][input_row];
        input_row++;
        outptr = *output_buf++;
        for (col = 0; col < num_cols; col++) {
            a = 255 - inptr0[col];
            b = 255 - inptr1[col];
            c = 255 - inptr2[col];
            d = 255 - inptr3[col];
            outptr[0] = (ts4l_jsample)TS4L_INK3(t1, a, t4, b, t7, c, t0, d);
            outptr[1] = (ts4l_jsample)TS4L_INK3(t5, b, t8, c, t2, a, t0, d);
            outptr[2] = (ts4l_jsample)TS4L_INK3(t9, c, t3, a, t6, b, t0, d);
            outptr += 3;
        }
    }
}


/* Creates the color deconverter and selects the conversion routine for the output
 * colorspace */
void ts4l_jpeg_jinit_color_deconverter_8345B678(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_my_cconvert *cconvert;
    int ci;

    cconvert = (struct ts4l_jpeg_my_cconvert *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*cconvert));
    cinfo->cconvert = &cconvert->pub;
    cconvert->pub.start_pass = fn_8345B4A8;
    switch (cinfo->jpeg_color_space) {
    case 1:
        if (cinfo->num_components != 1)
            TS4L_ERREXIT(cinfo, TS4L_JERR_BAD_J_COLORSPACE);
        break;
    case 2:
    case 3:
        if (cinfo->num_components != 3)
            TS4L_ERREXIT(cinfo, TS4L_JERR_BAD_J_COLORSPACE);
        break;
    case 4:
    case 5:
        if (cinfo->num_components != 4)
            TS4L_ERREXIT(cinfo, TS4L_JERR_BAD_J_COLORSPACE);
        break;
    default:
        if (cinfo->num_components < 1)
            TS4L_ERREXIT(cinfo, TS4L_JERR_BAD_J_COLORSPACE);
        break;
    }
    switch (cinfo->out_color_space) {
    case 1:
        cinfo->out_color_components = 1;
        if (cinfo->jpeg_color_space == 1 || cinfo->jpeg_color_space == 3) {
            cconvert->pub.color_convert = ts4_get_u32_off70_8345AD78;
            for (ci = 1; ci < cinfo->num_components; ci++)
                cinfo->comp_info[ci].component_needed = 0;
        } else {
            TS4L_ERREXIT(cinfo, TS4L_JERR_CONVERSION_NOTIMPL);
        }
        break;
    case 2:
        cinfo->out_color_components = 3;
        if (cinfo->jpeg_color_space == 3) {
            cconvert->pub.color_convert = ts4l_jpeg_ycc_rgb_convert_8345AC20;
            ts4l_jpeg_build_ycc_rgb_table_8345AB00(cinfo);
        } else if (cinfo->jpeg_color_space == 1) {
            cconvert->pub.color_convert = ts4l_jpeg_gray_rgb_convert_8345AD98;
        } else if (cinfo->jpeg_color_space == 2) {
            cconvert->pub.color_convert = ts4l_jpeg_null_convert_8345ACF0;
        } else if (cinfo->jpeg_color_space == 4) {
            cconvert->pub.color_convert = ts4l_jpeg_cmyk_rgb_convert_8345B340;
            ts4l_jpeg_build_ink_tables_8345AEF0(cinfo);
        } else if (cinfo->jpeg_color_space == 5) {
            cconvert->pub.color_convert = (void (*)(struct ts4l_jpeg_decomp *, ts4l_jsampimage, ts4l_jdim, ts4l_jsamparray, int))(void *)fn_8345B4A8;
            ts4l_jpeg_build_ycc_rgb_table_8345AB00(cinfo);
            ts4l_jpeg_build_ink_tables_8345AEF0(cinfo);
        } else {
            TS4L_ERREXIT(cinfo, TS4L_JERR_CONVERSION_NOTIMPL);
        }
        break;
    case 4:
        cinfo->out_color_components = 4;
        if (cinfo->jpeg_color_space == 5) {
            cconvert->pub.color_convert = ts4l_jpeg_ycck_cmyk_convert_8345AE00;
            ts4l_jpeg_build_ycc_rgb_table_8345AB00(cinfo);
        } else if (cinfo->jpeg_color_space == 4) {
            cconvert->pub.color_convert = ts4l_jpeg_null_convert_8345ACF0;
        } else {
            TS4L_ERREXIT(cinfo, TS4L_JERR_CONVERSION_NOTIMPL);
        }
        break;
    default:
        if (cinfo->out_color_space == cinfo->jpeg_color_space) {
            cinfo->out_color_components = cinfo->num_components;
            cconvert->pub.color_convert = ts4l_jpeg_null_convert_8345ACF0;
        } else {
            TS4L_ERREXIT(cinfo, TS4L_JERR_CONVERSION_NOTIMPL);
        }
        break;
    }
    if (cinfo->quantize_colors)
        cinfo->output_components = 1;
    else
        cinfo->output_components = cinfo->out_color_components;
}
