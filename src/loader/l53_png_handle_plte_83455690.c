/* Loader_DLL.xex 0x83455690-0x83455848, executable version 0.0.0.3.
 * libpng: png_handle_PLTE. */
#include "l48_png.h"

extern void ts4_if_get_u32_off544_8343FDB8(void *png, const char *msg);
extern void fn_8343FD80(void *png, const char *msg);
extern unsigned char *ts4l_alloc_zero_8343FF78(void *png, unsigned int items, unsigned int size);
extern void ts4_if_get_u32_off550_83449D78(void *png, void *buf, unsigned int n);
extern void fn_83440030(void *png, const void *buf, unsigned int n);
extern int ts4l_png_crc_finish_834552D0(void *png, unsigned int skip);
extern void ts4_if_get_u32_off8_834461A8(void *png, l48_png_info *info, unsigned char *palette, int num);
extern char lbl_8307AEB0[], lbl_8307AE98[], lbl_8307AE80[], lbl_8307AE68[], lbl_8307AE40[];

void ts4l_png_handle_PLTE_83455690(l48_png_struct *png_ptr, l48_png_info *info_ptr, unsigned int length)
{
    unsigned char *palette;
    l48_png_color *pal_ptr;
    int num, i;
    unsigned char buf[3];

    if (!(png_ptr->mode & 0x01)) {
        fn_8343FD80(png_ptr, lbl_8307AEB0);
    } else if (png_ptr->mode & 0x04) {
        ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_8307AE98);
        ts4l_png_crc_finish_834552D0(png_ptr, length);
        return;
    } else if (png_ptr->mode & 0x02) {
        fn_8343FD80(png_ptr, lbl_8307AE80);
    }
    png_ptr->mode |= 0x02;
    if (length % 3) {
        if (png_ptr->color_type != 3) {
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_8307AE68);
            ts4l_png_crc_finish_834552D0(png_ptr, length);
            return;
        }
        fn_8343FD80(png_ptr, lbl_8307AE68);
    }
    num = (int)length / 3;
    palette = ts4l_alloc_zero_8343FF78(png_ptr, num, 3);
    if (palette == 0)
        fn_8343FD80(png_ptr, lbl_8307AE68);
    png_ptr->flags |= 0x1000;
    for (i = 0, pal_ptr = (l48_png_color *)palette; i < num; i++, pal_ptr++) {
        ts4_if_get_u32_off550_83449D78(png_ptr, buf, 3);
        fn_83440030(png_ptr, buf, 3);
        pal_ptr->red = buf[0];
        pal_ptr->green = buf[1];
        pal_ptr->blue = buf[2];
    }
    ts4l_png_crc_finish_834552D0(png_ptr, 0);
    png_ptr->palette = palette;
    png_ptr->num_palette = (unsigned short)num;
    ts4_if_get_u32_off8_834461A8(png_ptr, info_ptr, palette, num);
    if (png_ptr->color_type == 3 && info_ptr && (info_ptr->valid & 0x10)) {
        if (png_ptr->num_trans > png_ptr->num_palette) {
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_8307AE40);
            png_ptr->num_trans = png_ptr->num_palette;
        }
    }
}
