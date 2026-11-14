/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression output colorspace conversion, IJG jdcolor.c style. (JP1) */
#include "jp1_jpeg.h"

/* Color deconverter private state (jdcolor.c my_cconvert). */
struct ts4_jpeg_my_cconvert {
    struct ts4_jpeg_cconvert pub; /* 0x00 */
    int *Cr_r_tab;                /* 0x08 */
    int *Cb_b_tab;                /* 0x0c */
    long *Cr_g_tab;               /* 0x10 */
    long *Cb_g_tab;               /* 0x14 */
    unsigned int *ink_tab[10];    /* 0x18: CMYK-to-RGB attenuation tables (this build's extension) */
};

/* Fixed-point YCbCr conversion constants, 16 fractional bits (jdcolor.c FIX()). */
#define JP1_SCALEBITS 16
#define JP1_ONE_HALF ((long)1 << (JP1_SCALEBITS - 1))
#define JP1_FIX_1_40200 91881L
#define JP1_FIX_1_77200 116130L
#define JP1_FIX_0_71414 46802L
#define JP1_FIX_0_34414 22554L

/* Builds the YCbCr to RGB lookup tables (Swing_DLL.xex 0x882F99A8). */
void ts4_jpeg_build_ycc_rgb_table_882F99A8(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_cconvert *cconvert = (struct ts4_jpeg_my_cconvert *)cinfo->cconvert;
    int i;
    long x;

    cconvert->Cr_r_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->Cb_b_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    cconvert->Cr_g_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(long));
    cconvert->Cb_g_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(long));
    for (i = 0, x = -128; i <= 255; i++, x++) {
        cconvert->Cr_r_tab[i] = (int)((JP1_FIX_1_40200 * x + JP1_ONE_HALF) >> JP1_SCALEBITS);
        cconvert->Cb_b_tab[i] = (int)((JP1_FIX_1_77200 * x + JP1_ONE_HALF) >> JP1_SCALEBITS);
        cconvert->Cr_g_tab[i] = (-JP1_FIX_0_71414) * x;
        cconvert->Cb_g_tab[i] = (-JP1_FIX_0_34414) * x + JP1_ONE_HALF;
    }
}

/* Converts YCbCr rows to RGB (Swing_DLL.xex 0x882F9AC8). */
void ts4_jpeg_ycc_rgb_convert_882F9AC8(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                       ts4_jdim input_row, ts4_jsamparray output_buf, int num_rows)
{
    struct ts4_jpeg_my_cconvert *cconvert = (struct ts4_jpeg_my_cconvert *)cinfo->cconvert;
    int y, cb, cr;
    ts4_jsamprow outptr;
    ts4_jsamprow inptr0, inptr1, inptr2;
    ts4_jdim col;
    ts4_jdim num_cols = cinfo->output_width;
    ts4_jsample *range_limit = cinfo->sample_range_limit;
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
            outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> JP1_SCALEBITS))];
            outptr[2] = range_limit[y + Cbbtab[cb]];
            outptr += 3;
        }
    }
}

/* Copies each component plane into interleaved output without conversion
 * (Swing_DLL.xex 0x882F9B98). */
void ts4_jpeg_null_convert_882F9B98(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                    ts4_jdim input_row, ts4_jsamparray output_buf, int num_rows)
{
    ts4_jsamprow inptr, outptr;
    ts4_jdim count;
    int num_components = cinfo->num_components;
    ts4_jdim num_cols = cinfo->output_width;
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

/* Expands one grayscale plane into RGB triples (Swing_DLL.xex 0x882F9C40). */
void ts4_jpeg_gray_rgb_convert_882F9C40(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                        ts4_jdim input_row, ts4_jsamparray output_buf,
                                        int num_rows)
{
    ts4_jsamprow inptr, outptr;
    ts4_jdim col;
    ts4_jdim num_cols = cinfo->output_width;

    while (--num_rows >= 0) {
        inptr = input_buf[0][input_row++];
        outptr = *output_buf++;
        for (col = 0; col < num_cols; col++) {
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3;
        }
    }
}

/* Converts YCCK rows to CMYK (Swing_DLL.xex 0x882F9CA8). */
void ts4_jpeg_ycck_cmyk_convert_882F9CA8(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                         ts4_jdim input_row, ts4_jsamparray output_buf,
                                         int num_rows)
{
    struct ts4_jpeg_my_cconvert *cconvert = (struct ts4_jpeg_my_cconvert *)cinfo->cconvert;
    int y, cb, cr;
    ts4_jsamprow outptr;
    ts4_jsamprow inptr0, inptr1, inptr2, inptr3;
    ts4_jdim col;
    ts4_jdim num_cols = cinfo->output_width;
    ts4_jsample *range_limit = cinfo->sample_range_limit;
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
            outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> JP1_SCALEBITS)))];
            outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
            outptr[3] = inptr3[col];
            outptr += 4;
        }
    }
}

enum { JP1_JERR_BAD_J_COLORSPACE = 0x0a, JP1_JERR_CONVERSION_NOTIMPL = 0x1b };

void ts4_jpeg_build_ink_tables_882F9D98(struct ts4_jpeg_decomp *cinfo);
/* start_pass_dcolor: nothing to do. */
void ts4_noop_881B3360(struct ts4_jpeg_decomp *cinfo);
/* grayscale_convert: copies the first component plane. */
void ts4_get_u32_off70_882F9C20(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                ts4_jdim input_row, ts4_jsamparray output_buf, int num_rows);

/* One CMYK ink attenuation curve: a descending line for the first 192 entries, then a
 * rounded linear ramp. */
#define JP1_INK_CURVE(i, slope_lo, c_hi, s_hi) \
    ((i) < 192 ? 65153 - (slope_lo) * (i) : (c_hi) - (((i) - 192) * (s_hi) + 31) / 63)

/* Builds the ten 256-entry ink attenuation tables for the CMYK-to-RGB converters
 * (Swing_DLL.xex 0x882F9D98). */
void ts4_jpeg_build_ink_tables_882F9D98(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_cconvert *cconvert = (struct ts4_jpeg_my_cconvert *)cinfo->cconvert;
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
        cconvert->ink_tab[0][i] = JP1_INK_CURVE(i, 223, 22464, 22464);
        cconvert->ink_tab[1][i] = JP1_INK_CURVE(i, 206, 25728, 25728);
        cconvert->ink_tab[1][i] = (cconvert->ink_tab[1][i] * 0x10101u) >> 16;
        cconvert->ink_tab[2][i] = JP1_INK_CURVE(i, 94, 47232, 8217);
        cconvert->ink_tab[2][i] = (cconvert->ink_tab[2][i] * 0x10101u) >> 16;
        cconvert->ink_tab[3][i] = JP1_INK_CURVE(i, 0, 65280, 3060);
        cconvert->ink_tab[3][i] = (cconvert->ink_tab[3][i] * 0x10101u) >> 16;
        cconvert->ink_tab[4][i] = JP1_INK_CURVE(i, 24, 60672, 7632);
        cconvert->ink_tab[4][i] = (cconvert->ink_tab[4][i] * 0x10101u) >> 16;
        cconvert->ink_tab[5][i] = JP1_INK_CURVE(i, 186, 29568, 29568);
        cconvert->ink_tab[5][i] = (cconvert->ink_tab[5][i] * 0x10101u) >> 16;
        cconvert->ink_tab[6][i] = JP1_INK_CURVE(i, 132, 39936, 11376);
        cconvert->ink_tab[6][i] = (cconvert->ink_tab[6][i] * 0x10101u) >> 16;
        cconvert->ink_tab[7][i] = i < 192 ? 65153 : 65280;
        cconvert->ink_tab[7][i] = (cconvert->ink_tab[7][i] * 0x10101u) >> 16;
        cconvert->ink_tab[8][i] = JP1_INK_CURVE(i, 7, 63936, 1461);
        cconvert->ink_tab[8][i] = (cconvert->ink_tab[8][i] * 0x10101u) >> 16;
        cconvert->ink_tab[9][i] = JP1_INK_CURVE(i, 171, 32448, 25308);
        cconvert->ink_tab[9][i] = (cconvert->ink_tab[9][i] * 0x10101u) >> 16;
    }
}

/* One output channel of the CMYK ink model: three table lookups multiplied together with
 * 16-bit scaling, then reduced to 8 bits. */
#define JP1_INK3(t1, i1, t2, i2, t3, i3, tk, ik) \
    ((((((t1)[i1] * (tk)[ik]) >> 16) * (t2)[i2]) >> 16) * (t3)[i3] >> 24)

/* Converts inverted CMYK rows to RGB through the ink attenuation tables
 * (Swing_DLL.xex 0x882FA1E8). */
void ts4_jpeg_cmyk_rgb_convert_882FA1E8(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                        ts4_jdim input_row, ts4_jsamparray output_buf,
                                        int num_rows)
{
    struct ts4_jpeg_my_cconvert *cconvert = (struct ts4_jpeg_my_cconvert *)cinfo->cconvert;
    ts4_jsamprow outptr, inptr0, inptr1, inptr2, inptr3;
    ts4_jdim col;
    ts4_jdim num_cols = cinfo->output_width;
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
            outptr[0] = (ts4_jsample)JP1_INK3(t1, a, t4, b, t7, c, t0, d);
            outptr[1] = (ts4_jsample)JP1_INK3(t5, b, t8, c, t2, a, t0, d);
            outptr[2] = (ts4_jsample)JP1_INK3(t9, c, t3, a, t6, b, t0, d);
            outptr += 3;
        }
    }
}

/* Converts YCCK rows to RGB through the YCC tables and the ink attenuation tables
 * (Swing_DLL.xex 0x882FA350). */
void ts4_jpeg_ycck_rgb_convert_882FA350(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                        ts4_jdim input_row, ts4_jsamparray output_buf,
                                        int num_rows)
{
    struct ts4_jpeg_my_cconvert *cconvert = (struct ts4_jpeg_my_cconvert *)cinfo->cconvert;
    int y, cb, cr;
    ts4_jsamprow outptr, inptr0, inptr1, inptr2, inptr3;
    ts4_jdim col;
    ts4_jsample *range_limit = cinfo->sample_range_limit;
    unsigned int *t0 = cconvert->ink_tab[0], *t1 = cconvert->ink_tab[1], *t2 = cconvert->ink_tab[2];
    unsigned int *t3 = cconvert->ink_tab[3], *t4 = cconvert->ink_tab[4], *t5 = cconvert->ink_tab[5];
    unsigned int *t6 = cconvert->ink_tab[6], *t7 = cconvert->ink_tab[7], *t8 = cconvert->ink_tab[8];
    unsigned int *t9 = cconvert->ink_tab[9];
    int *Crrtab = cconvert->Cr_r_tab;
    int *Cbbtab = cconvert->Cb_b_tab;
    long *Crgtab = cconvert->Cr_g_tab;
    long *Cbgtab = cconvert->Cb_g_tab;
    ts4_jdim num_cols = cinfo->output_width;
    unsigned int a, b, c, d;

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
            a = range_limit[y + Crrtab[cr]];
            b = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> JP1_SCALEBITS))];
            c = range_limit[y + Cbbtab[cb]];
            d = 255 - inptr3[col];
            outptr[0] = (ts4_jsample)JP1_INK3(t1, a, t4, b, t7, c, t0, d);
            outptr[1] = (ts4_jsample)JP1_INK3(t5, b, t8, c, t2, a, t0, d);
            outptr[2] = (ts4_jsample)JP1_INK3(t9, c, t3, a, t6, b, t0, d);
            outptr += 3;
        }
    }
}

/* Creates the color deconverter and selects the conversion routine for the output
 * colorspace (Swing_DLL.xex 0x882FA518). */
void ts4_jpeg_jinit_color_deconverter_882FA518(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_cconvert *cconvert;
    int ci;

    cconvert = (struct ts4_jpeg_my_cconvert *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*cconvert));
    cinfo->cconvert = &cconvert->pub;
    cconvert->pub.start_pass = ts4_noop_881B3360;
    switch (cinfo->jpeg_color_space) {
    case 1:
        if (cinfo->num_components != 1)
            JP1_ERREXIT(cinfo, JP1_JERR_BAD_J_COLORSPACE);
        break;
    case 2:
    case 3:
        if (cinfo->num_components != 3)
            JP1_ERREXIT(cinfo, JP1_JERR_BAD_J_COLORSPACE);
        break;
    case 4:
    case 5:
        if (cinfo->num_components != 4)
            JP1_ERREXIT(cinfo, JP1_JERR_BAD_J_COLORSPACE);
        break;
    default:
        if (cinfo->num_components < 1)
            JP1_ERREXIT(cinfo, JP1_JERR_BAD_J_COLORSPACE);
        break;
    }
    switch (cinfo->out_color_space) {
    case 1:
        cinfo->out_color_components = 1;
        if (cinfo->jpeg_color_space == 1 || cinfo->jpeg_color_space == 3) {
            cconvert->pub.color_convert = ts4_get_u32_off70_882F9C20;
            for (ci = 1; ci < cinfo->num_components; ci++)
                cinfo->comp_info[ci].component_needed = 0;
        } else {
            JP1_ERREXIT(cinfo, JP1_JERR_CONVERSION_NOTIMPL);
        }
        break;
    case 2:
        cinfo->out_color_components = 3;
        if (cinfo->jpeg_color_space == 3) {
            cconvert->pub.color_convert = ts4_jpeg_ycc_rgb_convert_882F9AC8;
            ts4_jpeg_build_ycc_rgb_table_882F99A8(cinfo);
        } else if (cinfo->jpeg_color_space == 1) {
            cconvert->pub.color_convert = ts4_jpeg_gray_rgb_convert_882F9C40;
        } else if (cinfo->jpeg_color_space == 2) {
            cconvert->pub.color_convert = ts4_jpeg_null_convert_882F9B98;
        } else if (cinfo->jpeg_color_space == 4) {
            cconvert->pub.color_convert = ts4_jpeg_cmyk_rgb_convert_882FA1E8;
            ts4_jpeg_build_ink_tables_882F9D98(cinfo);
        } else if (cinfo->jpeg_color_space == 5) {
            cconvert->pub.color_convert = ts4_jpeg_ycck_rgb_convert_882FA350;
            ts4_jpeg_build_ycc_rgb_table_882F99A8(cinfo);
            ts4_jpeg_build_ink_tables_882F9D98(cinfo);
        } else {
            JP1_ERREXIT(cinfo, JP1_JERR_CONVERSION_NOTIMPL);
        }
        break;
    case 4:
        cinfo->out_color_components = 4;
        if (cinfo->jpeg_color_space == 5) {
            cconvert->pub.color_convert = ts4_jpeg_ycck_cmyk_convert_882F9CA8;
            ts4_jpeg_build_ycc_rgb_table_882F99A8(cinfo);
        } else if (cinfo->jpeg_color_space == 4) {
            cconvert->pub.color_convert = ts4_jpeg_null_convert_882F9B98;
        } else {
            JP1_ERREXIT(cinfo, JP1_JERR_CONVERSION_NOTIMPL);
        }
        break;
    default:
        if (cinfo->out_color_space == cinfo->jpeg_color_space) {
            cinfo->out_color_components = cinfo->num_components;
            cconvert->pub.color_convert = ts4_jpeg_null_convert_882F9B98;
        } else {
            JP1_ERREXIT(cinfo, JP1_JERR_CONVERSION_NOTIMPL);
        }
        break;
    }
    if (cinfo->quantize_colors)
        cinfo->output_components = 1;
    else
        cinfo->output_components = cinfo->out_color_components;
}
