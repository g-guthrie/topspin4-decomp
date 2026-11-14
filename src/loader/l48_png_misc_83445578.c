/* Loader_DLL.xex 0x83445578-0x83447650, executable version 0.0.0.3.
 * libpng: png_write_flush, png_set_compression_window_bits, png_write_image,
 * png_set_shift. */
#include "l48_png.h"

extern void ts4_if_get_u32_off544_8343FDB8(void *png, const char *msg);
extern void fn_8343FD80(void *png, const char *msg);
extern int ts4l_zlib_deflate_83452130(void *strm, int flush);
extern void ts4l_png_write_idat_83450FE0(void *png, unsigned char *data, unsigned int len);
extern void ts4_if_get_u32_off620_83445FE0(void *png);
extern void fn_834452E0(void *png, unsigned char *row);
extern int ts4_if_get_u8_off613_83447650(void *png);
extern char lbl_830756C0[], lbl_830757D4[], lbl_830757A0[];

void ts4l_png_write_flush_83445578(l48_png_struct *png_ptr)
{
    int wrote_IDAT;

    if (png_ptr->row_number >= png_ptr->num_rows)
        return;
    do {
        int ret;
        ret = ts4l_zlib_deflate_83452130(&png_ptr->zstream, 2);
        wrote_IDAT = 0;
        if (ret != 0) {
            if (png_ptr->zstream.msg != 0)
                fn_8343FD80(png_ptr, png_ptr->zstream.msg);
            else
                fn_8343FD80(png_ptr, lbl_830756C0);
        }
        if (!png_ptr->zstream.avail_out) {
            ts4l_png_write_idat_83450FE0(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size);
            png_ptr->zstream.next_out = png_ptr->zbuf;
            png_ptr->zstream.avail_out = png_ptr->zbuf_size;
            wrote_IDAT = 1;
        }
    } while (wrote_IDAT);
    if (png_ptr->zbuf_size != png_ptr->zstream.avail_out) {
        ts4l_png_write_idat_83450FE0(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size - png_ptr->zstream.avail_out);
        png_ptr->zstream.next_out = png_ptr->zbuf;
        png_ptr->zstream.avail_out = png_ptr->zbuf_size;
    }
    png_ptr->flush_rows = 0;
    ts4_if_get_u32_off620_83445FE0(png_ptr);
}

void ts4l_png_set_compression_window_bits_83445C48(l48_png_struct *png_ptr, int window_bits)
{
    if (window_bits > 15)
        ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_830757D4);
    else if (window_bits < 8)
        ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_830757A0);
    png_ptr->flags |= 0x8;
    png_ptr->zlib_window_bits = window_bits;
}

void ts4l_png_write_image_83445EF0(l48_png_struct *png_ptr, unsigned char **image)
{
    unsigned int i;
    int pass, num_pass;
    unsigned char **rp;

    num_pass = ts4_if_get_u8_off613_83447650(png_ptr);
    for (pass = 0; pass < num_pass; pass++) {
        rp = image;
        for (i = 0; i < png_ptr->height; i++) {
            fn_834452E0(png_ptr, *rp);
            rp++;
        }
    }
}

void ts4l_png_set_shift_83447620(l48_png_struct *png_ptr, const l48_png_color_8 *true_bits)
{
    png_ptr->transformations |= 0x8;
    png_ptr->shift = *true_bits;
}
