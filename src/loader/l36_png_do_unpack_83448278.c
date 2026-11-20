/* Loader_DLL.xex 0x83448278-0x834483E4, executable version 0.0.0.3.
 * libpng 1.2.x pngrtran.c: png_do_unpack. */
typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef unsigned int png_size_t;
typedef png_byte *png_bytep;
typedef struct {
    png_uint_32 width;
    png_uint_32 rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
} png_row_info;

void ts4l_png_do_unpack_83448278(png_row_info *row_info, png_bytep row)
{
    png_uint_32 i;
    png_uint_32 row_width;

    if (row_info->bit_depth < 8) {
        png_bytep sp;
        png_bytep dp;
        unsigned int shift;

        row_width = row_info->width;
        switch (row_info->bit_depth) {
            case 1: {
                sp = row + (png_size_t)((row_width - 1) >> 3);
                dp = row + (png_size_t)row_width - 1;
                shift = 7 - (unsigned)((row_width + 7) & 0x07);
                for (i = 0; i < row_width; i++) {
                    *dp = (png_byte)((*sp >> shift) & 0x01);
                    if (shift == 7) {
                        shift = 0;
                        sp--;
                    } else {
                        shift++;
                    }
                    dp--;
                }
                break;
            }
            case 2: {
                sp = row + (png_size_t)((row_width - 1) >> 2);
                dp = row + (png_size_t)row_width - 1;
                shift = (unsigned)((3 - ((row_width + 3) & 0x03)) << 1);
                for (i = 0; i < row_width; i++) {
                    *dp = (png_byte)((*sp >> shift) & 0x03);
                    if (shift == 6) {
                        shift = 0;
                        sp--;
                    } else {
                        shift += 2;
                    }
                    dp--;
                }
                break;
            }
            case 4: {
                sp = row + (png_size_t)((row_width - 1) >> 1);
                dp = row + (png_size_t)row_width - 1;
                shift = (unsigned)((1 - ((row_width + 1) & 0x01)) << 2);
                for (i = 0; i < row_width; i++) {
                    *dp = (png_byte)((*sp >> shift) & 0x0f);
                    if (shift == 4) {
                        shift = 0;
                        sp--;
                    } else {
                        shift = 4;
                    }
                    dp--;
                }
                break;
            }
        }
        row_info->bit_depth = (png_byte)8;
        row_info->pixel_depth = (png_byte)(8 * row_info->channels);
        row_info->rowbytes = row_width * row_info->channels;
    }
}
