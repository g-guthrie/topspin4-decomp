/* Loader_DLL.xex 0x834452E0-0x8344555C, executable version 0.0.0.3.
 * libpng: png_write_row. */
#include "l48_png.h"

extern void ts4_if_get_u32_off544_8343FDB8(void *png, const char *msg);
extern void fn_83450848(l48_png_struct *png);
extern void fn_83451080(l48_png_struct *png);
extern void ts4l_png_do_write_interlace_834509D0(l48_png_row_info *ri, unsigned char *row, int pass);
extern void ts4_fn_83451EF0(l48_png_struct *png);
extern void fn_83451370(l48_png_struct *png, l48_png_row_info *ri);
extern void ts4_tailcall_fn_833E3AD0_8344C6D8(void *p, void *d, const void *s, unsigned int n);
extern char lbl_83075694[], lbl_83075668[], lbl_8307563C[], lbl_83075614[], lbl_830755E8[];

void ts4l_png_write_row_834452E0(l48_png_struct *png_ptr, unsigned char *row)
{
    if (png_ptr->row_number == 0 && png_ptr->pass == 0) {
        if (png_ptr->transformations & 0x8000)
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_83075694);
        if (png_ptr->transformations & 0x4)
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_83075668);
        if (png_ptr->transformations & 0x8)
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_8307563C);
        if (png_ptr->transformations & 0x1)
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_83075614);
        if (png_ptr->transformations & 0x10)
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_830755E8);
        fn_83450848(png_ptr);
    }
    if (png_ptr->interlaced && (png_ptr->transformations & 0x2)) {
        switch (png_ptr->pass) {
        case 0:
            if (png_ptr->row_number & 0x07) {
                fn_83451080(png_ptr);
                return;
            }
            break;
        case 1:
            if ((png_ptr->row_number & 0x07) || png_ptr->width < 5) {
                fn_83451080(png_ptr);
                return;
            }
            break;
        case 2:
            if ((png_ptr->row_number & 0x07) != 4) {
                fn_83451080(png_ptr);
                return;
            }
            break;
        case 3:
            if ((png_ptr->row_number & 0x03) || png_ptr->width < 3) {
                fn_83451080(png_ptr);
                return;
            }
            break;
        case 4:
            if ((png_ptr->row_number & 0x03) != 2) {
                fn_83451080(png_ptr);
                return;
            }
            break;
        case 5:
            if ((png_ptr->row_number & 0x01) || png_ptr->width < 2) {
                fn_83451080(png_ptr);
                return;
            }
            break;
        case 6:
            if (!(png_ptr->row_number & 0x01)) {
                fn_83451080(png_ptr);
                return;
            }
            break;
        default:
            break;
        }
    }
    png_ptr->row_info.color_type = png_ptr->color_type;
    png_ptr->row_info.width = png_ptr->usr_width;
    png_ptr->row_info.channels = png_ptr->usr_channels;
    png_ptr->row_info.bit_depth = png_ptr->usr_bit_depth;
    png_ptr->row_info.pixel_depth = (unsigned char)(png_ptr->row_info.bit_depth * png_ptr->row_info.channels);
    png_ptr->row_info.rowbytes = ((png_ptr->row_info.width * (unsigned int)png_ptr->row_info.pixel_depth + 7) >> 3);
    ts4_tailcall_fn_833E3AD0_8344C6D8(png_ptr, png_ptr->row_buf + 1, row, png_ptr->row_info.rowbytes);
    if (png_ptr->interlaced && png_ptr->pass < 6 && (png_ptr->transformations & 0x2)) {
        ts4l_png_do_write_interlace_834509D0(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->pass);
        if (!png_ptr->row_info.width) {
            fn_83451080(png_ptr);
            return;
        }
    }
    if (png_ptr->transformations)
        ts4_fn_83451EF0(png_ptr);
    fn_83451370(png_ptr, &png_ptr->row_info);
    if (png_ptr->write_row_fn != 0)
        (*png_ptr->write_row_fn)(png_ptr, png_ptr->row_number, png_ptr->pass);
}
