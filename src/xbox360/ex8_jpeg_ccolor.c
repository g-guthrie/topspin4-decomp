/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b input color space conversion (jccolor.c). This build also converts
 * BGR/BGRA input (in_color_space 6 and 7) using input_components as the pixel stride. */
#include "ex8_jpeg.h"

typedef struct ex8_cconvert_priv {
    ex8_jcconv pub;        /* 0x00 */
    int *rgb_ycc_tab;      /* 0x08 */
} ex8_cconvert_priv;

void ex8_rgb_ycc_start_883008F8(ex8_jcomp *cinfo);
void ex8_rgb_ycc_convert_883009C8(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                  unsigned int output_row, int num_rows);
void ex8_bgr_ycc_convert_88300AE0(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                  unsigned int output_row, int num_rows);
void ex8_rgb_gray_convert_88300C00(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                   unsigned int output_row, int num_rows);
void ex8_bgr_gray_convert_88300CA0(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                   unsigned int output_row, int num_rows);
void ex8_cmyk_ycck_convert_88300D48(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                    unsigned int output_row, int num_rows);
void ex8_grayscale_convert_88300E80(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                    unsigned int output_row, int num_rows);
void ex8_null_convert_88300EF0(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                               unsigned int output_row, int num_rows);

/* Builds the fixed-point RGB to YCbCr lookup tables. */
void ex8_rgb_ycc_start_883008F8(ex8_jcomp *cinfo)
{
    ex8_cconvert_priv *cconvert = (ex8_cconvert_priv *)cinfo->cconvert;
    int *rgb_ycc_tab;
    int i;

    rgb_ycc_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, (8 * 256) * sizeof(int));
    cconvert->rgb_ycc_tab = rgb_ycc_tab;

    for (i = 0; i <= 255; i++) {
        rgb_ycc_tab[i + 0] = 19595 * i;
        rgb_ycc_tab[i + 256] = 38470 * i;
        rgb_ycc_tab[i + 512] = 7471 * i + 32768;
        rgb_ycc_tab[i + 768] = (-11059) * i;
        rgb_ycc_tab[i + 1024] = (-21709) * i;
        rgb_ycc_tab[i + 1280] = 32768 * i + (128 << 16) + 32768 - 1;
        rgb_ycc_tab[i + 1536] = (-27439) * i;
        rgb_ycc_tab[i + 1792] = (-5329) * i;
    }
}

/* Converts RGB rows to YCbCr. */
void ex8_rgb_ycc_convert_883009C8(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                  unsigned int output_row, int num_rows)
{
    ex8_cconvert_priv *cconvert = (ex8_cconvert_priv *)cinfo->cconvert;
    int r, g, b;
    int *ctab = cconvert->rgb_ycc_tab;
    ex8_jsamprow inptr;
    ex8_jsamprow outptr0, outptr1, outptr2;
    unsigned int col;
    unsigned int num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr0 = output_buf[0][output_row];
        outptr1 = output_buf[1][output_row];
        outptr2 = output_buf[2][output_row];
        output_row++;
        for (col = 0; col < num_cols; col++) {
            r = inptr[0];
            g = inptr[1];
            b = inptr[2];
            inptr += 3;
            outptr0[col] = (ex8_joctet)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
            outptr1[col] = (ex8_joctet)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
            outptr2[col] = (ex8_joctet)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);
        }
    }
}

/* Converts BGR(A) rows to YCbCr. */
void ex8_bgr_ycc_convert_88300AE0(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                  unsigned int output_row, int num_rows)
{
    ex8_cconvert_priv *cconvert = (ex8_cconvert_priv *)cinfo->cconvert;
    int r, g, b;
    int *ctab = cconvert->rgb_ycc_tab;
    ex8_jsamprow inptr;
    ex8_jsamprow outptr0, outptr1, outptr2;
    unsigned int col;
    int stride = cinfo->input_components;
    unsigned int num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr0 = output_buf[0][output_row];
        outptr1 = output_buf[1][output_row];
        outptr2 = output_buf[2][output_row];
        output_row++;
        for (col = 0; col < num_cols; col++) {
            r = inptr[2];
            g = inptr[1];
            b = inptr[0];
            inptr += stride;
            outptr0[col] = (ex8_joctet)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
            outptr1[col] = (ex8_joctet)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
            outptr2[col] = (ex8_joctet)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);
        }
    }
}

/* Converts RGB rows to grayscale. */
void ex8_rgb_gray_convert_88300C00(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                   unsigned int output_row, int num_rows)
{
    ex8_cconvert_priv *cconvert = (ex8_cconvert_priv *)cinfo->cconvert;
    int r, g, b;
    int *ctab = cconvert->rgb_ycc_tab;
    ex8_jsamprow inptr;
    ex8_jsamprow outptr;
    unsigned int col;
    unsigned int num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr = output_buf[0][output_row++];
        for (col = 0; col < num_cols; col++) {
            r = inptr[0];
            g = inptr[1];
            b = inptr[2];
            inptr += 3;
            outptr[col] = (ex8_joctet)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
        }
    }
}

/* Converts BGR(A) rows to grayscale. */
void ex8_bgr_gray_convert_88300CA0(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                   unsigned int output_row, int num_rows)
{
    ex8_cconvert_priv *cconvert = (ex8_cconvert_priv *)cinfo->cconvert;
    int r, g, b;
    int *ctab = cconvert->rgb_ycc_tab;
    ex8_jsamprow inptr;
    ex8_jsamprow outptr;
    unsigned int col;
    int stride = cinfo->input_components;
    unsigned int num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr = output_buf[0][output_row++];
        for (col = 0; col < num_cols; col++) {
            r = inptr[2];
            g = inptr[1];
            b = inptr[0];
            inptr += stride;
            outptr[col] = (ex8_joctet)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
        }
    }
}

/* Converts CMYK rows to YCCK (K passes through). */
void ex8_cmyk_ycck_convert_88300D48(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                    unsigned int output_row, int num_rows)
{
    ex8_cconvert_priv *cconvert = (ex8_cconvert_priv *)cinfo->cconvert;
    int r, g, b;
    int *ctab = cconvert->rgb_ycc_tab;
    ex8_jsamprow inptr;
    ex8_jsamprow outptr0, outptr1, outptr2, outptr3;
    unsigned int col;
    unsigned int num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr0 = output_buf[0][output_row];
        outptr1 = output_buf[1][output_row];
        outptr2 = output_buf[2][output_row];
        outptr3 = output_buf[3][output_row];
        output_row++;
        for (col = 0; col < num_cols; col++) {
            r = 255 - inptr[0];
            g = 255 - inptr[1];
            b = 255 - inptr[2];
            outptr3[col] = inptr[3];
            inptr += 4;
            outptr0[col] = (ex8_joctet)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
            outptr1[col] = (ex8_joctet)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
            outptr2[col] = (ex8_joctet)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);
        }
    }
}

/* Copies the first channel of each input pixel. */
void ex8_grayscale_convert_88300E80(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                                    unsigned int output_row, int num_rows)
{
    ex8_jsamprow inptr;
    ex8_jsamprow outptr;
    unsigned int col;
    unsigned int num_cols = cinfo->image_width;
    int instride = cinfo->input_components;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr = output_buf[0][output_row++];
        for (col = 0; col < num_cols; col++) {
            outptr[col] = inptr[0];
            inptr += instride;
        }
    }
}

/* De-interleaves pixels into component planes without color changes. */
void ex8_null_convert_88300EF0(ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                               unsigned int output_row, int num_rows)
{
    ex8_jsamprow inptr;
    ex8_jsamprow outptr;
    unsigned int col;
    int ci;
    int nc = cinfo->num_components;
    unsigned int num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        for (ci = 0; ci < nc; ci++) {
            inptr = *input_buf;
            outptr = output_buf[ci][output_row];
            for (col = 0; col < num_cols; col++) {
                outptr[col] = inptr[ci];
                inptr += nc;
            }
        }
        input_buf++;
        output_row++;
    }
}

