/* Loader_DLL.xex 0x83449578-0x834496A8, executable version 0.0.0.3.
 * libpng 1.2.x pngrtran.c: png_do_dither. */
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

#define PNG_COLOR_TYPE_PALETTE 3
#define PNG_COLOR_TYPE_RGB 2
#define PNG_COLOR_TYPE_RGB_ALPHA 6
#define PNG_DITHER_RED_BITS 5
#define PNG_DITHER_GREEN_BITS 5
#define PNG_DITHER_BLUE_BITS 5

void ts4l_png_do_dither_83449578(png_row_info *row_info, png_bytep row, png_bytep palette_lookup, png_bytep dither_lookup)
{
    png_bytep sp, dp;
    png_uint_32 i;
    png_uint_32 row_width = row_info->width;

    if (row_info->color_type == PNG_COLOR_TYPE_RGB && palette_lookup && row_info->bit_depth == 8) {
        int r, g, b, p;
        sp = row;
        dp = row;
        for (i = 0; i < row_width; i++) {
            r = *sp++;
            g = *sp++;
            b = *sp++;
            p = (((r >> (8 - PNG_DITHER_RED_BITS)) & ((1 << PNG_DITHER_RED_BITS) - 1)) << (PNG_DITHER_GREEN_BITS + PNG_DITHER_BLUE_BITS)) |
                (((g >> (8 - PNG_DITHER_GREEN_BITS)) & ((1 << PNG_DITHER_GREEN_BITS) - 1)) << (PNG_DITHER_BLUE_BITS)) |
                ((b >> (8 - PNG_DITHER_BLUE_BITS)) & ((1 << PNG_DITHER_BLUE_BITS) - 1));
            *dp++ = palette_lookup[p];
        }
        row_info->color_type = PNG_COLOR_TYPE_PALETTE;
        row_info->channels = 1;
        row_info->pixel_depth = row_info->bit_depth;
        row_info->rowbytes = ((row_width * row_info->pixel_depth + 7) >> 3);
    } else if (row_info->color_type == PNG_COLOR_TYPE_RGB_ALPHA && palette_lookup != 0 && row_info->bit_depth == 8) {
        int r, g, b, p;
        sp = row;
        dp = row;
        for (i = 0; i < row_width; i++) {
            r = *sp++;
            g = *sp++;
            b = *sp++;
            sp++;
            p = (((r >> (8 - PNG_DITHER_RED_BITS)) & ((1 << PNG_DITHER_RED_BITS) - 1)) << (PNG_DITHER_GREEN_BITS + PNG_DITHER_BLUE_BITS)) |
                (((g >> (8 - PNG_DITHER_GREEN_BITS)) & ((1 << PNG_DITHER_GREEN_BITS) - 1)) << (PNG_DITHER_BLUE_BITS)) |
                ((b >> (8 - PNG_DITHER_BLUE_BITS)) & ((1 << PNG_DITHER_BLUE_BITS) - 1));
            *dp++ = palette_lookup[p];
        }
        row_info->color_type = PNG_COLOR_TYPE_PALETTE;
        row_info->channels = 1;
        row_info->pixel_depth = row_info->bit_depth;
        row_info->rowbytes = ((row_width * row_info->pixel_depth + 7) >> 3);
    } else if (row_info->color_type == PNG_COLOR_TYPE_PALETTE && dither_lookup && row_info->bit_depth == 8) {
        sp = row;
        for (i = 0; i < row_width; i++, sp++) {
            *sp = dither_lookup[*sp];
        }
    }
}
