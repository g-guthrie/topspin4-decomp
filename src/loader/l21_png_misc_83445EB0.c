/* Loader_DLL.xex 0x83445EB0-0x83448678, executable version 0.0.0.3.
 * libpng 1.2.x small routines. */


#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

#include "l21_ts4l_p6_png.h"

#define TS4L_P6_PNG_INFO_gAMA 0x0001u
#define TS4L_P6_PNG_INFO_sRGB 0x0800u
#define TS4L_P6_PNG_INFO_tRNS 0x0010u

extern const double lbl_83005ED8; /* 1.0 */
extern const double lbl_830198D0; /* PNG_GAMMA_THRESHOLD */
double fabs(double);
#define TS4L_P6_PNG_GAMMA 0x2000u
void fn_834452E0(ts4l_p6_png_struct *png_ptr, unsigned char *row);                       /* png_write_row */
void fn_83445648(ts4l_p6_png_struct *png_ptr);                                          /* png_write_destroy */
void fn_8344C628(void *ptr);                                                        /* png_free */
void fn_83446890(ts4l_p6_png_struct *png_ptr, unsigned char *row, int arg);             /* png_write_row, 3-arg form */
int ts4_if_get_u8_off613_83447650(ts4l_p6_png_struct *png_ptr);                         /* png_set_interlace_handling */

/* Write num_rows rows from an array of row pointers (libpng png_write_rows). */
void ts4l_png_write_rows_83445EB0(ts4l_p6_png_struct *png_ptr, unsigned char **row_pointers, unsigned int num_rows)
{
    unsigned int i;
    unsigned char **rp = row_pointers;
    for (i = 0; i < num_rows; i++, rp++)
        fn_834452E0(png_ptr, *rp);
}

/* Free the info struct and the write struct and clear the caller's pointers (libpng png_destroy_write_struct).
 * */
void ts4l_png_destroy_write_struct_83445F58(ts4l_p6_png_struct **png_ptr_ptr, void **info_ptr_ptr)
{
    ts4l_p6_png_struct *png_ptr = 0;
    if (png_ptr_ptr != 0)
        png_ptr = *png_ptr_ptr;
    if (info_ptr_ptr != 0 && *info_ptr_ptr != 0) {
        fn_8344C628(*info_ptr_ptr);
        *info_ptr_ptr = 0;
    }
    if (png_ptr != 0) {
        fn_83445648(png_ptr);
        fn_8344C628(png_ptr);
        *png_ptr_ptr = 0;
    }
}

/* Store the file gamma (float) and flag it valid (libpng png_set_gAMA). */
void ts4l_png_set_gAMA_83446060(ts4l_p6_png_struct *png_ptr, ts4l_p6_png_info *info_ptr, double file_gamma)
{
    if (png_ptr == 0 || info_ptr == 0)
        return;
    info_ptr->gamma = (float)file_gamma;
    info_ptr->valid |= TS4L_P6_PNG_INFO_gAMA;
}

/* Store the transparency array pointer, optional single-colour transparency and count (libpng png_set_tRNS).
 * */
void ts4l_png_set_tRNS_83446228(ts4l_p6_png_struct *png_ptr, ts4l_p6_png_info *info_ptr, unsigned char *trans,
                               int num_trans, const ts4l_p6_png_color_16 *trans_values)
{
    if (png_ptr == 0 || info_ptr == 0)
        return;
    if (trans != 0)
        info_ptr->trans = trans;
    if (trans_values != 0) {
        memcpy(&info_ptr->trans_values, trans_values, sizeof(ts4l_p6_png_color_16));
        if (num_trans == 0)
            num_trans = 1;
    }
    info_ptr->num_trans = (unsigned short)num_trans;
    info_ptr->valid |= TS4L_P6_PNG_INFO_tRNS;
}

/* Write the whole image: one pass over all rows per interlace pass (libpng png_write_image).
 * */
void ts4l_png_write_image_83446DD0(ts4l_p6_png_struct *png_ptr, unsigned char **image)
{
    int pass;
    int num_pass = ts4_if_get_u8_off613_83447650(png_ptr);
    unsigned int height = png_ptr->height;
    png_ptr->num_rows = height;
    for (pass = 0; pass < num_pass; pass++) {
        unsigned char **rp = image;
        unsigned int i;
        for (i = 0; i < height; i++, rp++)
            fn_83446890(png_ptr, *rp, 0);
    }
}

/* Swap the two bytes of every sample in a 16-bit row (libpng png_do_swap). */
void ts4l_png_do_swap_834476E8(ts4l_p6_png_row_info *row_info, unsigned char *row)
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

/* Record file and screen gamma, flagging the gamma transform if they differ from 1/1 (libpng png_set_gamma).
 * */
void ts4l_png_set_gamma_83448070(ts4l_p6_png_struct *png_ptr, double screen_gamma, double file_gamma)
{
    if (fabs(screen_gamma * file_gamma - lbl_83005ED8) > lbl_830198D0)
        png_ptr->transformations |= TS4L_P6_PNG_GAMMA;
    png_ptr->gamma = (float)file_gamma;
    png_ptr->screen_gamma = (float)screen_gamma;
}

/* Reduce a 16-bit row to 8 bits per sample by keeping the high byte (libpng png_do_chop). */
void ts4l_png_do_chop_83448620(ts4l_p6_png_row_info *row_info, unsigned char *row)
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
