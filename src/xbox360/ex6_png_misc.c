/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX6: small libpng 1.2.x routines (png_set_*, png_do_swap/chop, png_write_rows, ...). */

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

#include "ex6_png.h"

#define EX6_PNG_INFO_gAMA 0x0001u
#define EX6_PNG_INFO_sRGB 0x0800u
#define EX6_PNG_INFO_tRNS 0x0010u

/* Store the file gamma (float) and flag it valid (libpng png_set_gAMA). Swing_DLL.xex 0x882E7240 */
void ex6_png_set_gAMA_882E7240(ex6_png_struct *png_ptr, ex6_png_info *info_ptr, double file_gamma)
{
    if (png_ptr == 0 || info_ptr == 0)
        return;
    info_ptr->gamma = (float)file_gamma;
    info_ptr->valid |= EX6_PNG_INFO_gAMA;
}

/* Store the transparency array pointer, optional single-colour transparency and count (libpng png_set_tRNS).
 * Swing_DLL.xex 0x882E7408 */
void ex6_png_set_tRNS_882E7408(ex6_png_struct *png_ptr, ex6_png_info *info_ptr, unsigned char *trans,
                               int num_trans, const ex6_png_color_16 *trans_values)
{
    if (png_ptr == 0 || info_ptr == 0)
        return;
    if (trans != 0)
        info_ptr->trans = trans;
    if (trans_values != 0) {
        memcpy(&info_ptr->trans_values, trans_values, sizeof(ex6_png_color_16));
        if (num_trans == 0)
            num_trans = 1;
    }
    info_ptr->num_trans = (unsigned short)num_trans;
    info_ptr->valid |= EX6_PNG_INFO_tRNS;
}

/* Swap the two bytes of every sample in a 16-bit row (libpng png_do_swap). Swing_DLL.xex 0x882E8310 */
void ex6_png_do_swap_882E8310(ex6_png_row_info *row_info, unsigned char *row)
{
    if (row_info->bit_depth == 16) {
        unsigned char *rp = row;
        unsigned int i;
        unsigned int istop = row_info->width * row_info->channels;
        for (i = 0; i < istop; i++, rp += 2) {
            unsigned char t = *rp;
            *rp = *(rp + 1);
            *(rp + 1) = t;
        }
    }
}

/* Reduce a 16-bit row to 8 bits per sample by keeping the high byte (libpng png_do_chop). Swing_DLL.xex 0x882E89D8 */
void ex6_png_do_chop_882E89D8(ex6_png_row_info *row_info, unsigned char *row)
{
    if (row_info->bit_depth == 16) {
        unsigned char *sp = row;
        unsigned char *dp = row;
        unsigned int i;
        unsigned int istop = row_info->width * row_info->channels;
        for (i = 0; i < istop; i++, sp += 2, dp++)
            *dp = *sp;
        row_info->bit_depth = 8;
        row_info->pixel_depth = (unsigned char)(8 * row_info->channels);
        row_info->rowbytes = row_info->width * row_info->channels;
    }
}

extern const double lbl_880038D0; /* 1.0 */
extern const double lbl_88009AA8; /* PNG_GAMMA_THRESHOLD */
double fabs(double);

#define EX6_PNG_GAMMA 0x2000u

/* Record file and screen gamma, flagging the gamma transform if they differ from 1/1 (libpng png_set_gamma).
 * Swing_DLL.xex 0x882E8458 */
void ex6_png_set_gamma_882E8458(ex6_png_struct *png_ptr, double screen_gamma, double file_gamma)
{
    if (fabs(screen_gamma * file_gamma - lbl_880038D0) > lbl_88009AA8)
        png_ptr->transformations |= EX6_PNG_GAMMA;
    png_ptr->gamma = (float)file_gamma;
    png_ptr->screen_gamma = (float)screen_gamma;
}

void fn_882E6918(ex6_png_struct *png_ptr, unsigned char *row);                       /* png_write_row */
void ex7_png_write_destroy_882E6C68(ex6_png_struct *png_ptr);                                          /* png_write_destroy */
void fn_882EC158(void *ptr);                                                        /* png_free */
void fn_882E7940(ex6_png_struct *png_ptr, unsigned char *row, int arg);             /* png_write_row, 3-arg form */
int ts4_if_get_u8_off613_882E8278(ex6_png_struct *png_ptr);                         /* png_set_interlace_handling */

/* Write num_rows rows from an array of row pointers (libpng png_write_rows). Swing_DLL.xex 0x882E70F8 */
void ex6_png_write_rows_882E70F8(ex6_png_struct *png_ptr, unsigned char **row_pointers, unsigned int num_rows)
{
    unsigned int i;
    unsigned char **rp = row_pointers;
    for (i = 0; i < num_rows; i++, rp++)
        fn_882E6918(png_ptr, *rp);
}

/* Free the info struct and the write struct and clear the caller's pointers (libpng png_destroy_write_struct).
 * Swing_DLL.xex 0x882E7138 */
void ex6_png_destroy_write_struct_882E7138(ex6_png_struct **png_ptr_ptr, void **info_ptr_ptr)
{
    ex6_png_struct *png_ptr = 0;
    if (png_ptr_ptr != 0)
        png_ptr = *png_ptr_ptr;
    if (info_ptr_ptr != 0 && *info_ptr_ptr != 0) {
        fn_882EC158(*info_ptr_ptr);
        *info_ptr_ptr = 0;
    }
    if (png_ptr != 0) {
        ex7_png_write_destroy_882E6C68(png_ptr);
        fn_882EC158(png_ptr);
        *png_ptr_ptr = 0;
    }
}

/* Write the whole image: one pass over all rows per interlace pass (libpng png_write_image).
 * Swing_DLL.xex 0x882E7DC8 */
void ex6_png_write_image_882E7DC8(ex6_png_struct *png_ptr, unsigned char **image)
{
    int pass;
    int num_pass = ts4_if_get_u8_off613_882E8278(png_ptr);
    unsigned int height = png_ptr->height;
    png_ptr->num_rows = height;
    for (pass = 0; pass < num_pass; pass++) {
        unsigned char **rp = image;
        unsigned int i;
        for (i = 0; i < height; i++, rp++)
            fn_882E7940(png_ptr, *rp, 0);
    }
}

void fn_882E26E8(ex6_png_struct *png_ptr, const char *message); /* png_error */
void ts4_if_get_u32_off544_882E2720(ex6_png_struct *png_ptr, const char *message); /* png_warning */

extern const char lbl_880098B4[]; /* "image size exceeds user limits in IHDR" */
extern const char lbl_88009874[]; /* "Width too large to process image data; rowbytes will overflow." */

#define EX6_PNG_UINT_31_MAX 0x7fffffffUL
#define EX6_PNG_USER_WIDTH_MAX 1000000UL
#define EX6_PNG_USER_HEIGHT_MAX 1000000UL

/* Store the image header fields in the info struct and derive channels, pixel depth and row bytes
 * (libpng png_set_IHDR). Swing_DLL.xex 0x882E7268 */
void ex6_png_set_IHDR_882E7268(ex6_png_struct *png_ptr, ex6_png_info *info_ptr, unsigned int width,
                               unsigned int height, int bit_depth, int color_type, int interlace_type,
                               int compression_type, int filter_type)
{
    unsigned int rowbytes;
    if (png_ptr == 0 || info_ptr == 0)
        return;

    if (width > EX6_PNG_USER_WIDTH_MAX || height > EX6_PNG_USER_HEIGHT_MAX)
        fn_882E26E8(png_ptr, lbl_880098B4);

    info_ptr->width = width;
    info_ptr->height = height;
    info_ptr->bit_depth = (unsigned char)bit_depth;
    info_ptr->color_type = (unsigned char)color_type;
    info_ptr->compression_type = (unsigned char)compression_type;
    info_ptr->filter_type = (unsigned char)filter_type;
    info_ptr->interlace_type = (unsigned char)interlace_type;
    if (info_ptr->color_type == 3)
        info_ptr->channels = 1;
    else if (info_ptr->color_type & 2)
        info_ptr->channels = 3;
    else
        info_ptr->channels = 1;
    if (info_ptr->color_type & 4)
        info_ptr->channels++;
    info_ptr->pixel_depth = (unsigned char)(info_ptr->channels * info_ptr->bit_depth);

    if (width > EX6_PNG_UINT_31_MAX / ((info_ptr->pixel_depth + 7) >> 3)) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88009874);
        rowbytes = 0;
    } else {
        rowbytes = (info_ptr->pixel_depth * width + 7) >> 3;
    }
    info_ptr->rowbytes = rowbytes;
}
