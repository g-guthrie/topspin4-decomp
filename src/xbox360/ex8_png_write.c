/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libpng pngwrite.c / pngwutil.c row writing (compiled with /O1). */

#include "ex8_png.h"

void ts4_if_get_u32_off544_882E2720(ex8_png_struct *png_ptr, const char *message); /* png_warning */
void ts4_noop_881B3360(ex8_png_struct *png_ptr);                                     /* png_do_write_transformations */
void ts4_memcpy_forward_shifted_882EC208(ex8_png_struct *png_ptr, void *dst, const void *src, unsigned int length);
void ex7_png_write_start_row_882F0020(ex8_png_struct *png_ptr);
void ex7_png_do_write_interlace_882F01A8(ex8_png_row_info *row_info, unsigned char *row, int pass);
void png2_png_write_finish_row_882F0858(ex8_png_struct *png_ptr);                                           /* png_write_finish_row */
void png2_png_write_find_filter_882F0B48(ex8_png_struct *png_ptr, ex8_png_row_info *row_info);               /* png_write_find_filter */

extern const char lbl_88009698[]; /* "PNG_WRITE_SWAP_SUPPORTED is not defined." */
extern const char lbl_880096C4[]; /* "PNG_WRITE_BGR_SUPPORTED is not defined." */
extern const char lbl_880096EC[]; /* "PNG_WRITE_SHIFT_SUPPORTED is not defined." */
extern const char lbl_88009718[]; /* "PNG_WRITE_PACK_SUPPORTED is not defined." */
extern const char lbl_88009744[]; /* "PNG_WRITE_FILLER_SUPPORTED is not defined." */

/* Writes one image row: transforms, filters, and compresses it (libpng png_write_row). */
void ex8_png_write_row_882E6918(ex8_png_struct *png_ptr, unsigned char *row)
{
    if (png_ptr->row_number == 0 && png_ptr->pass == 0) {
        if (png_ptr->transformations & 0x8000)
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88009744);
        if (png_ptr->transformations & 0x4)
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88009718);
        if (png_ptr->transformations & 0x8)
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880096EC);
        if (png_ptr->transformations & 0x1)
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880096C4);
        if (png_ptr->transformations & 0x10)
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88009698);
        ex7_png_write_start_row_882F0020(png_ptr);
    }

    if (png_ptr->interlaced && (png_ptr->transformations & 0x2)) {
        switch (png_ptr->pass) {
        case 0:
            if (png_ptr->row_number & 0x07) {
                png2_png_write_finish_row_882F0858(png_ptr);
                return;
            }
            break;
        case 1:
            if ((png_ptr->row_number & 0x07) || png_ptr->width < 5) {
                png2_png_write_finish_row_882F0858(png_ptr);
                return;
            }
            break;
        case 2:
            if ((png_ptr->row_number & 0x07) != 4) {
                png2_png_write_finish_row_882F0858(png_ptr);
                return;
            }
            break;
        case 3:
            if ((png_ptr->row_number & 0x03) || png_ptr->width < 3) {
                png2_png_write_finish_row_882F0858(png_ptr);
                return;
            }
            break;
        case 4:
            if ((png_ptr->row_number & 0x03) != 2) {
                png2_png_write_finish_row_882F0858(png_ptr);
                return;
            }
            break;
        case 5:
            if ((png_ptr->row_number & 0x01) || png_ptr->width < 2) {
                png2_png_write_finish_row_882F0858(png_ptr);
                return;
            }
            break;
        case 6:
            if (!(png_ptr->row_number & 0x01)) {
                png2_png_write_finish_row_882F0858(png_ptr);
                return;
            }
            break;
        }
    }

    png_ptr->row_info.color_type = png_ptr->color_type;
    png_ptr->row_info.width = png_ptr->usr_width;
    png_ptr->row_info.channels = png_ptr->usr_channels;
    png_ptr->row_info.bit_depth = png_ptr->usr_bit_depth;
    png_ptr->row_info.pixel_depth = (unsigned char)(png_ptr->row_info.bit_depth * png_ptr->row_info.channels);
    png_ptr->row_info.rowbytes = ((png_ptr->row_info.pixel_depth * png_ptr->row_info.width + 7) >> 3);

    ts4_memcpy_forward_shifted_882EC208(png_ptr, png_ptr->row_buf + 1, row, png_ptr->row_info.rowbytes);

    if (png_ptr->interlaced && png_ptr->pass < 6 && (png_ptr->transformations & 0x2)) {
        ex7_png_do_write_interlace_882F01A8(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->pass);
        if (!png_ptr->row_info.width) {
            png2_png_write_finish_row_882F0858(png_ptr);
            return;
        }
    }

    if (png_ptr->transformations)
        ts4_noop_881B3360(png_ptr);

    png2_png_write_find_filter_882F0B48(png_ptr, &png_ptr->row_info);

    if (png_ptr->write_row_fn != 0)
        ((void (*)(ex8_png_struct *, unsigned int, int))png_ptr->write_row_fn)(png_ptr, png_ptr->row_number,
                                                                                png_ptr->pass);
}
