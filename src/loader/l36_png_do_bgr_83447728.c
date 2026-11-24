/* Loader_DLL.xex 0x83447728-0x8344782C, executable version 0.0.0.3.
 * libpng 1.2.x pngtrans.c: png_do_bgr. */
typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef png_byte *png_bytep;
typedef struct {
    png_uint_32 width;
    png_uint_32 rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
} png_row_info;

#define PNG_COLOR_MASK_COLOR 2
#define PNG_COLOR_TYPE_RGB 2
#define PNG_COLOR_TYPE_RGB_ALPHA 6

void ts4l_png_do_bgr_83447728(png_row_info *row_info, png_bytep row)
{
    if ((row_info->color_type & PNG_COLOR_MASK_COLOR)) {
        png_uint_32 row_width = row_info->width;
        if (row_info->bit_depth == 8) {
            if (row_info->color_type == PNG_COLOR_TYPE_RGB) {
                png_bytep rp;
                png_uint_32 i;
                for (i = 0, rp = row; i < row_width; i++, rp += 3) {
                    png_byte save = *rp;
                    *rp = *(rp + 2);
                    *(rp + 2) = save;
                }
            } else if (row_info->color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
                png_bytep rp;
                png_uint_32 i;
                for (i = 0, rp = row; i < row_width; i++, rp += 4) {
                    png_byte save = *rp;
                    *rp = *(rp + 2);
                    *(rp + 2) = save;
                }
            }
        } else if (row_info->bit_depth == 16) {
            if (row_info->color_type == PNG_COLOR_TYPE_RGB) {
                png_bytep rp;
                png_uint_32 i;
                for (i = 0, rp = row; i < row_width; i++, rp += 6) {
                    png_byte save = *rp;
                    *rp = *(rp + 4);
                    *(rp + 4) = save;
                    save = *(rp + 1);
                    *(rp + 1) = *(rp + 5);
                    *(rp + 5) = save;
                }
            } else if (row_info->color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
                png_bytep rp;
                png_uint_32 i;
                for (i = 0, rp = row; i < row_width; i++, rp += 8) {
                    png_byte save = *rp;
                    *rp = *(rp + 4);
                    *(rp + 4) = save;
                    save = *(rp + 1);
                    *(rp + 1) = *(rp + 5);
                    *(rp + 5) = save;
                }
            }
        }
    }
}
