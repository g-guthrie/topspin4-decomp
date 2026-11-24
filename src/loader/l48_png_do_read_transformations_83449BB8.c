/* Loader_DLL.xex 0x83449BB8-0x83449D78, executable version 0.0.0.3.
 * libpng: png_do_read_transformations. */
#include "l48_png.h"

extern void fn_8343FD80(void *png, const char *msg);
extern void ts4l_png_do_expand_palette_83448E30(l48_png_row_info *ri, unsigned char *row, unsigned char *palette, unsigned char *trans, int num_trans);
extern void ts4l_png_do_expand_834490D0(l48_png_row_info *ri, unsigned char *row, l48_png_color_16 *trans_values);
extern void ts4l_png_do_gamma_834489D0(l48_png_row_info *ri, unsigned char *row, unsigned char *gamma_table, unsigned short **gamma_16_table, int gamma_shift);
extern void ts4l_png_do_chop_83448620(l48_png_row_info *ri, unsigned char *row);
extern void ts4l_png_do_dither_83449578(l48_png_row_info *ri, unsigned char *row, unsigned char *palette_lookup, unsigned char *dither_index);
extern void fn_834483E8(l48_png_row_info *ri, unsigned char *row, l48_png_color_8 *sig_bits);
extern void ts4l_png_do_unpack_83448278(l48_png_row_info *ri, unsigned char *row);
extern void ts4l_png_do_bgr_83447728(l48_png_row_info *ri, unsigned char *row);
extern void ts4l_png_do_read_filler_83448678(l48_png_row_info *ri, unsigned char *row, unsigned int filler, unsigned int flags);
extern void ts4l_png_do_swap_834476E8(l48_png_row_info *ri, unsigned char *row);
extern char lbl_83075BD4[], lbl_83075BB0[];

void ts4l_png_do_read_transformations_83449BB8(l48_png_struct *png_ptr)
{
    if (png_ptr->row_buf == 0)
        fn_8343FD80(png_ptr, lbl_83075BD4);
    if (png_ptr->transformations & 0x1000) {
        if (png_ptr->row_info.color_type == 3) {
            ts4l_png_do_expand_palette_83448E30(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->palette, png_ptr->trans, png_ptr->num_trans);
        } else {
            if (png_ptr->num_trans)
                ts4l_png_do_expand_834490D0(&png_ptr->row_info, png_ptr->row_buf + 1, &png_ptr->trans_values);
            else
                ts4l_png_do_expand_834490D0(&png_ptr->row_info, png_ptr->row_buf + 1, 0);
        }
    }
    if ((png_ptr->transformations & 0x2000) && png_ptr->color_type != 3)
        ts4l_png_do_gamma_834489D0(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->gamma_table, png_ptr->gamma_16_table, png_ptr->gamma_shift);
    if (png_ptr->transformations & 0x400)
        ts4l_png_do_chop_83448620(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x40) {
        ts4l_png_do_dither_83449578(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->palette_lookup, png_ptr->dither_index);
        if (png_ptr->row_info.rowbytes == 0)
            fn_8343FD80(png_ptr, lbl_83075BB0);
    }
    if (png_ptr->transformations & 0x8)
        fn_834483E8(&png_ptr->row_info, png_ptr->row_buf + 1, &png_ptr->shift);
    if (png_ptr->transformations & 0x4)
        ts4l_png_do_unpack_83448278(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x1)
        ts4l_png_do_bgr_83447728(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x8000)
        ts4l_png_do_read_filler_83448678(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->filler, png_ptr->flags);
    if (png_ptr->transformations & 0x10)
        ts4l_png_do_swap_834476E8(&png_ptr->row_info, png_ptr->row_buf + 1);
}
