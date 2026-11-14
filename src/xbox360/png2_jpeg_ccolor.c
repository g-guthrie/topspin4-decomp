/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libjpeg 6b jccolor.c jinit_color_converter (default flags), finished from JP2's draft. Colorspaces 6 and 7
 * are this build's BGR-ordered inputs; they are tested as two separate branches with identical bodies. */
#include "ex8_jpeg.h"

enum {
    PNG2_JERR_BAD_IN_COLORSPACE = 9,
    PNG2_JERR_BAD_J_COLORSPACE = 10,
    PNG2_JERR_CONVERSION_NOTIMPL = 27
};

void ts4_noop_881B3360(ex8_jcomp *cinfo); /* null_method */
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

/* Picks the color conversion method from the input and JPEG colorspaces (jccolor.c jinit_color_converter).
 * Swing_DLL.xex 0x88300F78 */
void png2_jpeg_jinit_color_converter_88300F78(ex8_jcomp *cinfo)
{
    ex8_jcconv *cconvert;

    cconvert = (ex8_jcconv *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_jcconv) + 4);
    cinfo->cconvert = cconvert;
    cconvert->start_pass = ts4_noop_881B3360;

    switch (cinfo->in_color_space) {
    case 1:
        if (cinfo->input_components != 1)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_IN_COLORSPACE);
        break;
    case 2:
    case 3:
        if (cinfo->input_components != 3)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_IN_COLORSPACE);
        break;
    case 4:
    case 5:
        if (cinfo->input_components != 4)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_IN_COLORSPACE);
        break;
    default:
        if (cinfo->input_components < 1)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_IN_COLORSPACE);
        break;
    }

    switch (cinfo->jpeg_color_space) {
    case 1:
        if (cinfo->num_components != 1)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_J_COLORSPACE);
        if (cinfo->in_color_space == 1)
            cconvert->color_convert = ex8_grayscale_convert_88300E80;
        else if (cinfo->in_color_space == 2) {
            cconvert->start_pass = ex8_rgb_ycc_start_883008F8;
            cconvert->color_convert = ex8_rgb_gray_convert_88300C00;
        } else if (cinfo->in_color_space == 6) {
            cconvert->start_pass = ex8_rgb_ycc_start_883008F8;
            cconvert->color_convert = ex8_bgr_gray_convert_88300CA0;
        } else if (cinfo->in_color_space == 7) {
            cconvert->start_pass = ex8_rgb_ycc_start_883008F8;
            cconvert->color_convert = ex8_bgr_gray_convert_88300CA0;
        } else if (cinfo->in_color_space == 3)
            cconvert->color_convert = ex8_grayscale_convert_88300E80;
        else
            EX8_ERREXIT(cinfo, PNG2_JERR_CONVERSION_NOTIMPL);
        break;

    case 2:
        if (cinfo->num_components != 3)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_J_COLORSPACE);
        if (cinfo->in_color_space == 2)
            cconvert->color_convert = ex8_null_convert_88300EF0;
        else
            EX8_ERREXIT(cinfo, PNG2_JERR_CONVERSION_NOTIMPL);
        break;

    case 3:
        if (cinfo->num_components != 3)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_J_COLORSPACE);
        if (cinfo->in_color_space == 2) {
            cconvert->start_pass = ex8_rgb_ycc_start_883008F8;
            cconvert->color_convert = ex8_rgb_ycc_convert_883009C8;
        } else if (cinfo->in_color_space == 6) {
            cconvert->start_pass = ex8_rgb_ycc_start_883008F8;
            cconvert->color_convert = ex8_bgr_ycc_convert_88300AE0;
        } else if (cinfo->in_color_space == 7) {
            cconvert->start_pass = ex8_rgb_ycc_start_883008F8;
            cconvert->color_convert = ex8_bgr_ycc_convert_88300AE0;
        } else if (cinfo->in_color_space == 3)
            cconvert->color_convert = ex8_null_convert_88300EF0;
        else
            EX8_ERREXIT(cinfo, PNG2_JERR_CONVERSION_NOTIMPL);
        break;

    case 4:
        if (cinfo->num_components != 4)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_J_COLORSPACE);
        if (cinfo->in_color_space == 4)
            cconvert->color_convert = ex8_null_convert_88300EF0;
        else
            EX8_ERREXIT(cinfo, PNG2_JERR_CONVERSION_NOTIMPL);
        break;

    case 5:
        if (cinfo->num_components != 4)
            EX8_ERREXIT(cinfo, PNG2_JERR_BAD_J_COLORSPACE);
        if (cinfo->in_color_space == 4) {
            cconvert->start_pass = ex8_rgb_ycc_start_883008F8;
            cconvert->color_convert = ex8_cmyk_ycck_convert_88300D48;
        } else if (cinfo->in_color_space == 5)
            cconvert->color_convert = ex8_null_convert_88300EF0;
        else
            EX8_ERREXIT(cinfo, PNG2_JERR_CONVERSION_NOTIMPL);
        break;

    default:
        if (cinfo->jpeg_color_space != cinfo->in_color_space || cinfo->num_components != cinfo->input_components)
            EX8_ERREXIT(cinfo, PNG2_JERR_CONVERSION_NOTIMPL);
        cconvert->color_convert = ex8_null_convert_88300EF0;
        break;
    }
}
